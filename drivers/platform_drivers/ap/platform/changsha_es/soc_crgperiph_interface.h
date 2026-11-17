#ifndef __SOC_CRGPERIPH_INTERFACE_H__
#define __SOC_CRGPERIPH_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_CRGPERIPH_PEREN0_ADDR(base) ((base) + (0x000UL))
#define SOC_CRGPERIPH_PERDIS0_ADDR(base) ((base) + (0x004UL))
#define SOC_CRGPERIPH_PERCLKEN0_ADDR(base) ((base) + (0x008UL))
#define SOC_CRGPERIPH_PERSTAT0_ADDR(base) ((base) + (0x00CUL))
#define SOC_CRGPERIPH_PEREN1_ADDR(base) ((base) + (0x010UL))
#define SOC_CRGPERIPH_PERDIS1_ADDR(base) ((base) + (0x014UL))
#define SOC_CRGPERIPH_PERCLKEN1_ADDR(base) ((base) + (0x018UL))
#define SOC_CRGPERIPH_PERSTAT1_ADDR(base) ((base) + (0x01CUL))
#define SOC_CRGPERIPH_PEREN2_ADDR(base) ((base) + (0x020UL))
#define SOC_CRGPERIPH_PERDIS2_ADDR(base) ((base) + (0x024UL))
#define SOC_CRGPERIPH_PERCLKEN2_ADDR(base) ((base) + (0x028UL))
#define SOC_CRGPERIPH_PERSTAT2_ADDR(base) ((base) + (0x02CUL))
#define SOC_CRGPERIPH_PEREN3_ADDR(base) ((base) + (0x030UL))
#define SOC_CRGPERIPH_PERDIS3_ADDR(base) ((base) + (0x034UL))
#define SOC_CRGPERIPH_PERCLKEN3_ADDR(base) ((base) + (0x038UL))
#define SOC_CRGPERIPH_PERSTAT3_ADDR(base) ((base) + (0x03CUL))
#define SOC_CRGPERIPH_PEREN4_ADDR(base) ((base) + (0x040UL))
#define SOC_CRGPERIPH_PERDIS4_ADDR(base) ((base) + (0x044UL))
#define SOC_CRGPERIPH_PERCLKEN4_ADDR(base) ((base) + (0x048UL))
#define SOC_CRGPERIPH_PERSTAT4_ADDR(base) ((base) + (0x04CUL))
#define SOC_CRGPERIPH_PEREN5_ADDR(base) ((base) + (0x050UL))
#define SOC_CRGPERIPH_PERDIS5_ADDR(base) ((base) + (0x054UL))
#define SOC_CRGPERIPH_PERCLKEN5_ADDR(base) ((base) + (0x058UL))
#define SOC_CRGPERIPH_PERSTAT5_ADDR(base) ((base) + (0x05CUL))
#define SOC_CRGPERIPH_PERRSTEN0_ADDR(base) ((base) + (0x060UL))
#define SOC_CRGPERIPH_PERRSTDIS0_ADDR(base) ((base) + (0x064UL))
#define SOC_CRGPERIPH_PERRSTSTAT0_ADDR(base) ((base) + (0x068UL))
#define SOC_CRGPERIPH_PERRSTEN1_ADDR(base) ((base) + (0x06CUL))
#define SOC_CRGPERIPH_PERRSTDIS1_ADDR(base) ((base) + (0x070UL))
#define SOC_CRGPERIPH_PERRSTSTAT1_ADDR(base) ((base) + (0x074UL))
#define SOC_CRGPERIPH_PERRSTEN2_ADDR(base) ((base) + (0x078UL))
#define SOC_CRGPERIPH_PERRSTDIS2_ADDR(base) ((base) + (0x07CUL))
#define SOC_CRGPERIPH_PERRSTSTAT2_ADDR(base) ((base) + (0x080UL))
#define SOC_CRGPERIPH_PERRSTEN3_ADDR(base) ((base) + (0x084UL))
#define SOC_CRGPERIPH_PERRSTDIS3_ADDR(base) ((base) + (0x088UL))
#define SOC_CRGPERIPH_PERRSTSTAT3_ADDR(base) ((base) + (0x08CUL))
#define SOC_CRGPERIPH_PERRSTEN4_ADDR(base) ((base) + (0x090UL))
#define SOC_CRGPERIPH_PERRSTDIS4_ADDR(base) ((base) + (0x094UL))
#define SOC_CRGPERIPH_PERRSTSTAT4_ADDR(base) ((base) + (0x098UL))
#define SOC_CRGPERIPH_PERRSTEN5_ADDR(base) ((base) + (0x09CUL))
#define SOC_CRGPERIPH_PERRSTDIS5_ADDR(base) ((base) + (0x0A0UL))
#define SOC_CRGPERIPH_PERRSTSTAT5_ADDR(base) ((base) + (0x0A4UL))
#define SOC_CRGPERIPH_CLKDIV0_ADDR(base) ((base) + (0x0A8UL))
#define SOC_CRGPERIPH_CLKDIV1_ADDR(base) ((base) + (0x0ACUL))
#define SOC_CRGPERIPH_CLKDIV2_ADDR(base) ((base) + (0x0B0UL))
#define SOC_CRGPERIPH_CLKDIV3_ADDR(base) ((base) + (0x0B4UL))
#define SOC_CRGPERIPH_CLKDIV4_ADDR(base) ((base) + (0x0B8UL))
#define SOC_CRGPERIPH_CLKDIV5_ADDR(base) ((base) + (0x0BCUL))
#define SOC_CRGPERIPH_CLKDIV6_ADDR(base) ((base) + (0x0C0UL))
#define SOC_CRGPERIPH_CLKDIV7_ADDR(base) ((base) + (0x0C4UL))
#define SOC_CRGPERIPH_CLKDIV8_ADDR(base) ((base) + (0x0C8UL))
#define SOC_CRGPERIPH_CLKDIV9_ADDR(base) ((base) + (0x0CCUL))
#define SOC_CRGPERIPH_CLKDIV10_ADDR(base) ((base) + (0x0D0UL))
#define SOC_CRGPERIPH_CLKDIV11_ADDR(base) ((base) + (0x0D4UL))
#define SOC_CRGPERIPH_CLKDIV12_ADDR(base) ((base) + (0x0D8UL))
#define SOC_CRGPERIPH_CLKDIV13_ADDR(base) ((base) + (0x0DCUL))
#define SOC_CRGPERIPH_CLKDIV14_ADDR(base) ((base) + (0x0E0UL))
#define SOC_CRGPERIPH_CLKDIV15_ADDR(base) ((base) + (0x0E4UL))
#define SOC_CRGPERIPH_CLKDIV16_ADDR(base) ((base) + (0x0E8UL))
#define SOC_CRGPERIPH_CLKDIV17_ADDR(base) ((base) + (0x0ECUL))
#define SOC_CRGPERIPH_CLKDIV18_ADDR(base) ((base) + (0x0F0UL))
#define SOC_CRGPERIPH_CLKDIV19_ADDR(base) ((base) + (0x0F4UL))
#define SOC_CRGPERIPH_CLKDIV20_ADDR(base) ((base) + (0x0F8UL))
#define SOC_CRGPERIPH_CLKDIV21_ADDR(base) ((base) + (0x0FCUL))
#define SOC_CRGPERIPH_CLKDIV22_ADDR(base) ((base) + (0x100UL))
#define SOC_CRGPERIPH_CLKDIV23_ADDR(base) ((base) + (0x104UL))
#define SOC_CRGPERIPH_CLKDIV24_ADDR(base) ((base) + (0x108UL))
#define SOC_CRGPERIPH_CLKDIV25_ADDR(base) ((base) + (0x10CUL))
#define SOC_CRGPERIPH_PERI_STAT1_ADDR(base) ((base) + (0x114UL))
#define SOC_CRGPERIPH_PERI_STAT2_ADDR(base) ((base) + (0x118UL))
#define SOC_CRGPERIPH_PERI_STAT3_ADDR(base) ((base) + (0x11CUL))
#define SOC_CRGPERIPH_PERI_CTRL0_ADDR(base) ((base) + (0x120UL))
#define SOC_CRGPERIPH_PERI_CTRL3_ADDR(base) ((base) + (0x12CUL))
#define SOC_CRGPERIPH_PERI_STAT10_ADDR(base) ((base) + (0x130UL))
#define SOC_CRGPERIPH_PERI_STAT11_ADDR(base) ((base) + (0x134UL))
#define SOC_CRGPERIPH_CORESIGHTLPSTAT_ADDR(base) ((base) + (0x204UL))
#define SOC_CRGPERIPH_CORESIGHT_CTRL_ADDR(base) ((base) + (0x208UL))
#define SOC_CRGPERIPH_CORESIGHTETFINT_ADDR(base) ((base) + (0x20CUL))
#define SOC_CRGPERIPH_CORESIGHTETRINT_ADDR(base) ((base) + (0x210UL))
#define SOC_CRGPERIPH_ADB_GT_STATUS_ADDR(base) ((base) + (0x21CUL))
#define SOC_CRGPERIPH_ADB_WAKEUP_STATUS_ADDR(base) ((base) + (0x220UL))
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_ADDR(base) ((base) + (0x400UL))
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_ADDR(base) ((base) + (0x404UL))
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_ADDR(base) ((base) + (0x408UL))
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT3_ADDR(base) ((base) + (0x40CUL))
#define SOC_CRGPERIPH_PEREN6_ADDR(base) ((base) + (0x410UL))
#define SOC_CRGPERIPH_PERDIS6_ADDR(base) ((base) + (0x414UL))
#define SOC_CRGPERIPH_PERCLKEN6_ADDR(base) ((base) + (0x418UL))
#define SOC_CRGPERIPH_PERSTAT6_ADDR(base) ((base) + (0x41CUL))
#define SOC_CRGPERIPH_PEREN7_ADDR(base) ((base) + (0x420UL))
#define SOC_CRGPERIPH_PERDIS7_ADDR(base) ((base) + (0x424UL))
#define SOC_CRGPERIPH_PERCLKEN7_ADDR(base) ((base) + (0x428UL))
#define SOC_CRGPERIPH_PERSTAT7_ADDR(base) ((base) + (0x42CUL))
#define SOC_CRGPERIPH_PEREN8_ADDR(base) ((base) + (0x430UL))
#define SOC_CRGPERIPH_PERDIS8_ADDR(base) ((base) + (0x434UL))
#define SOC_CRGPERIPH_PERCLKEN8_ADDR(base) ((base) + (0x438UL))
#define SOC_CRGPERIPH_PERSTAT8_ADDR(base) ((base) + (0x43CUL))
#define SOC_CRGPERIPH_PEREN9_ADDR(base) ((base) + (0x440UL))
#define SOC_CRGPERIPH_PERDIS9_ADDR(base) ((base) + (0x444UL))
#define SOC_CRGPERIPH_PERCLKEN9_ADDR(base) ((base) + (0x448UL))
#define SOC_CRGPERIPH_PERSTAT9_ADDR(base) ((base) + (0x44CUL))
#define SOC_CRGPERIPH_PEREN10_ADDR(base) ((base) + (0x450UL))
#define SOC_CRGPERIPH_PERDIS10_ADDR(base) ((base) + (0x454UL))
#define SOC_CRGPERIPH_PERCLKEN10_ADDR(base) ((base) + (0x458UL))
#define SOC_CRGPERIPH_PERSTAT10_ADDR(base) ((base) + (0x45CUL))
#define SOC_CRGPERIPH_PEREN11_ADDR(base) ((base) + (0x460UL))
#define SOC_CRGPERIPH_PERDIS11_ADDR(base) ((base) + (0x464UL))
#define SOC_CRGPERIPH_PERCLKEN11_ADDR(base) ((base) + (0x468UL))
#define SOC_CRGPERIPH_PERSTAT11_ADDR(base) ((base) + (0x46CUL))
#define SOC_CRGPERIPH_PEREN12_ADDR(base) ((base) + (0x470UL))
#define SOC_CRGPERIPH_PERDIS12_ADDR(base) ((base) + (0x474UL))
#define SOC_CRGPERIPH_PERCLKEN12_ADDR(base) ((base) + (0x478UL))
#define SOC_CRGPERIPH_PERSTAT12_ADDR(base) ((base) + (0x47CUL))
#define SOC_CRGPERIPH_PEREN13_ADDR(base) ((base) + (0x480UL))
#define SOC_CRGPERIPH_PERDIS13_ADDR(base) ((base) + (0x484UL))
#define SOC_CRGPERIPH_PERCLKEN13_ADDR(base) ((base) + (0x488UL))
#define SOC_CRGPERIPH_PERSTAT13_ADDR(base) ((base) + (0x48CUL))
#define SOC_CRGPERIPH_PERI_STAT4_ADDR(base) ((base) + (0x500UL))
#define SOC_CRGPERIPH_PERI_STAT5_ADDR(base) ((base) + (0x504UL))
#define SOC_CRGPERIPH_PERI_STAT6_ADDR(base) ((base) + (0x508UL))
#define SOC_CRGPERIPH_PERI_STAT7_ADDR(base) ((base) + (0x50CUL))
#define SOC_CRGPERIPH_INTR_MASK_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x520UL))
#define SOC_CRGPERIPH_INTR_CLR_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x524UL))
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x528UL))
#define SOC_CRGPERIPH_DFT_FUNC_GLOBAL_CLK_EN_ADDR(base) ((base) + (0x5FCUL))
#define SOC_CRGPERIPH_PERI_STAT8_ADDR(base) ((base) + (0x600UL))
#define SOC_CRGPERIPH_PERI_STAT9_ADDR(base) ((base) + (0x604UL))
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_ADDR(base) ((base) + (0x668UL))
#define SOC_CRGPERIPH_PERI_AUTODIV1_ADDR(base) ((base) + (0x6A0UL))
#define SOC_CRGPERIPH_PERI_AUTODIV2_ADDR(base) ((base) + (0x6A4UL))
#define SOC_CRGPERIPH_CLKDIV26_ADDR(base) ((base) + (0x700UL))
#define SOC_CRGPERIPH_CLKDIV27_ADDR(base) ((base) + (0x704UL))
#define SOC_CRGPERIPH_CLKDIV28_ADDR(base) ((base) + (0x708UL))
#define SOC_CRGPERIPH_CLKDIV29_ADDR(base) ((base) + (0x70CUL))
#define SOC_CRGPERIPH_CLKDIV30_ADDR(base) ((base) + (0x710UL))
#define SOC_CRGPERIPH_CLKDIV31_ADDR(base) ((base) + (0x714UL))
#define SOC_CRGPERIPH_CLKDIV32_ADDR(base) ((base) + (0x718UL))
#define SOC_CRGPERIPH_PERI_COMMON_CTRL0_ADDR(base) ((base) + (0x720UL))
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ADDR(base) ((base) + (0x724UL))
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ADDR(base) ((base) + (0x728UL))
#define SOC_CRGPERIPH_PERI_COMMON_CTRL3_ADDR(base) ((base) + (0x72CUL))
#define SOC_CRGPERIPH_PERI_COMMON_CTRL4_ADDR(base) ((base) + (0x730UL))
#define SOC_CRGPERIPH_PPLL6CTRL0_ADDR(base) ((base) + (0x830UL))
#define SOC_CRGPERIPH_PPLL6CTRL1_ADDR(base) ((base) + (0x834UL))
#define SOC_CRGPERIPH_PPLL7CTRL0_ADDR(base) ((base) + (0x838UL))
#define SOC_CRGPERIPH_PPLL7CTRL1_ADDR(base) ((base) + (0x83CUL))
#define SOC_CRGPERIPH_PPLL6SSCCTRL_ADDR(base) ((base) + (0x858UL))
#define SOC_CRGPERIPH_PPLL7SSCCTRL_ADDR(base) ((base) + (0x85CUL))
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_CLEAR_ADDR(base) ((base) + (0x918UL))
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_ADDR(base) ((base) + (0x91CUL))
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_CTRL_ADDR(base) ((base) + (0x920UL))
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_ADDR(base) ((base) + (0x924UL))
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_ADDR(base) ((base) + (0x928UL))
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT0_ADDR(base) ((base) + (0x92CUL))
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT1_ADDR(base) ((base) + (0x930UL))
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT2_ADDR(base) ((base) + (0x934UL))
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT3_ADDR(base) ((base) + (0x938UL))
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE0_ADDR(base) ((base) + (0x950UL))
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE1_ADDR(base) ((base) + (0x954UL))
#define SOC_CRGPERIPH_PLL_FSM_NS_STAT_ADDR(base) ((base) + (0x958UL))
#define SOC_CRGPERIPH_FNPLL_CFG0_ADDR(base) ((base) + (0xA00UL))
#define SOC_CRGPERIPH_FNPLL_CFG1_ADDR(base) ((base) + (0xA04UL))
#define SOC_CRGPERIPH_FNPLL_CFG2_ADDR(base) ((base) + (0xA08UL))
#define SOC_CRGPERIPH_FNPLL_CFG3_ADDR(base) ((base) + (0xA0cUL))
#define SOC_CRGPERIPH_FNPLL_STATE0_ADDR(base) ((base) + (0xA10UL))
#define SOC_CRGPERIPH_PPLL1CTRL0_ADDR(base) ((base) + (0xA6CUL))
#define SOC_CRGPERIPH_PPLL1CTRL1_ADDR(base) ((base) + (0xA70UL))
#define SOC_CRGPERIPH_PPLL2CTRL0_ADDR(base) ((base) + (0xA74UL))
#define SOC_CRGPERIPH_PPLL2CTRL1_ADDR(base) ((base) + (0xA78UL))
#define SOC_CRGPERIPH_PPLL3CTRL0_ADDR(base) ((base) + (0xA7CUL))
#define SOC_CRGPERIPH_PPLL3CTRL1_ADDR(base) ((base) + (0xA80UL))
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ADDR(base) ((base) + (0xA84UL))
#define SOC_CRGPERIPH_PPLL2_BCTRL1_ADDR(base) ((base) + (0xA88UL))
#define SOC_CRGPERIPH_PPLL1SSCCTRL_ADDR(base) ((base) + (0xA9CUL))
#define SOC_CRGPERIPH_PPLL2SSCCTRL_ADDR(base) ((base) + (0xAA0UL))
#define SOC_CRGPERIPH_PPLL3SSCCTRL_ADDR(base) ((base) + (0xAA4UL))
#define SOC_CRGPERIPH_PPLL2_BSSCCTRL_ADDR(base) ((base) + (0xAA8UL))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_ADDR(base) ((base) + (0xB00UL))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_ADDR(base) ((base) + (0xB04UL))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV2_ADDR(base) ((base) + (0xB08UL))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV3_ADDR(base) ((base) + (0xB0CUL))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV4_ADDR(base) ((base) + (0xB10UL))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV5_ADDR(base) ((base) + (0xB14UL))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV6_ADDR(base) ((base) + (0xB18UL))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV7_ADDR(base) ((base) + (0xB1CUL))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV8_ADDR(base) ((base) + (0xB20UL))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV9_ADDR(base) ((base) + (0xB24UL))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV10_ADDR(base) ((base) + (0xB28UL))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV11_ADDR(base) ((base) + (0xB2CUL))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV12_ADDR(base) ((base) + (0xB30UL))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV13_ADDR(base) ((base) + (0xB34UL))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_ADDR(base) ((base) + (0xB38UL))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV15_ADDR(base) ((base) + (0xB3CUL))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV16_ADDR(base) ((base) + (0xB40UL))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV17_ADDR(base) ((base) + (0xB44UL))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV18_ADDR(base) ((base) + (0xB48UL))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV19_ADDR(base) ((base) + (0xB4CUL))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV20_ADDR(base) ((base) + (0xB50UL))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV21_ADDR(base) ((base) + (0xB54UL))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV22_ADDR(base) ((base) + (0xB58UL))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV23_ADDR(base) ((base) + (0xB5cUL))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV24_ADDR(base) ((base) + (0xB60UL))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV25_ADDR(base) ((base) + (0xB64UL))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV26_ADDR(base) ((base) + (0xB68UL))
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_ADDR(base) ((base) + (0xC38UL))
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_1_ADDR(base) ((base) + (0xC3CUL))
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_ADDR(base) ((base) + (0xC40UL))
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_ADDR(base) ((base) + (0xC44UL))
#define SOC_CRGPERIPH_PLL_FSM_STAT0_ADDR(base) ((base) + (0xC48UL))
#define SOC_CRGPERIPH_PLL_FSM_STAT1_ADDR(base) ((base) + (0xC4CUL))
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ADDR(base) ((base) + (0xC50UL))
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL0_ADDR(base) ((base) + (0xC54UL))
#define SOC_CRGPERIPH_PLL_GT_VOTE_CTRL0_ADDR(base) ((base) + (0xC58UL))
#define SOC_CRGPERIPH_PLL_BYPASS_VOTE_CTRL0_ADDR(base) ((base) + (0xC5CUL))
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL1_ADDR(base) ((base) + (0xC60UL))
#define SOC_CRGPERIPH_PLL_GT_VOTE_CTRL1_ADDR(base) ((base) + (0xC64UL))
#define SOC_CRGPERIPH_PLL_BYPASS_VOTE_CTRL1_ADDR(base) ((base) + (0xC68UL))
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL2_ADDR(base) ((base) + (0xC6CUL))
#define SOC_CRGPERIPH_PLL_GT_VOTE_CTRL2_ADDR(base) ((base) + (0xC70UL))
#define SOC_CRGPERIPH_PLL_BYPASS_VOTE_CTRL2_ADDR(base) ((base) + (0xC74UL))
#define SOC_CRGPERIPH_PERI_FNPLL_STAT_SEL_ADDR(base) ((base) + (0xC78UL))
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ADDR(base) ((base) + (0xD00UL))
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ADDR(base) ((base) + (0xD04UL))
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ADDR(base) ((base) + (0xD08UL))
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ADDR(base) ((base) + (0xD0CUL))
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ADDR(base) ((base) + (0xD10UL))
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ADDR(base) ((base) + (0xD14UL))
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ADDR(base) ((base) + (0xD18UL))
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ADDR(base) ((base) + (0xD1CUL))
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ADDR(base) ((base) + (0xD20UL))
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_ADDR(base) ((base) + (0xE00UL))
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_ADDR(base) ((base) + (0xE04UL))
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_ADDR(base) ((base) + (0xE08UL))
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_ADDR(base) ((base) + (0xE0CUL))
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_ADDR(base) ((base) + (0xE10UL))
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_ADDR(base) ((base) + (0xE14UL))
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_ADDR(base) ((base) + (0xE18UL))
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_ADDR(base) ((base) + (0xE1CUL))
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_ADDR(base) ((base) + (0xE20UL))
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_ADDR(base) ((base) + (0xE24UL))
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_ADDR(base) ((base) + (0xE28UL))
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_ADDR(base) ((base) + (0xE2CUL))
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_ADDR(base) ((base) + (0xE30UL))
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_ADDR(base) ((base) + (0xE34UL))
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_ADDR(base) ((base) + (0xE38UL))
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_ADDR(base) ((base) + (0xE3CUL))
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_ADDR(base) ((base) + (0xE40UL))
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_ADDR(base) ((base) + (0xE44UL))
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_ADDR(base) ((base) + (0xE48UL))
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_ADDR(base) ((base) + (0xE4CUL))
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_ADDR(base) ((base) + (0xE50UL))
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_ADDR(base) ((base) + (0xE54UL))
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_ADDR(base) ((base) + (0xE58UL))
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_ADDR(base) ((base) + (0xE5CUL))
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_ADDR(base) ((base) + (0xE60UL))
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_ADDR(base) ((base) + (0xE64UL))
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_ADDR(base) ((base) + (0xE68UL))
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_ADDR(base) ((base) + (0xE6CUL))
#define SOC_CRGPERIPH_GENERAL_SEC_CTRL0_ADDR(base) ((base) + (0xF00UL))
#define SOC_CRGPERIPH_DDRSYS_AUTOFS_CTRL0_ADDR(base) ((base) + (0xF20UL))
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL2_ADDR(base) ((base) + (0xF28UL))
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL2_ADDR(base) ((base) + (0xF2CUL))
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL1_ADDR(base) ((base) + (0xF30UL))
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL1_ADDR(base) ((base) + (0xF34UL))
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL_ADDR(base) ((base) + (0xF38UL))
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL_ADDR(base) ((base) + (0xF3CUL))
#define SOC_CRGPERIPH_PERI_AUTODIV0_ADDR(base) ((base) + (0xF40UL))
#define SOC_CRGPERIPH_PERI_AUTODIV3_ADDR(base) ((base) + (0xF4CUL))
#define SOC_CRGPERIPH_PERI_AUTODIV4_ADDR(base) ((base) + (0xF50UL))
#define SOC_CRGPERIPH_PERI_AUTODIV5_ADDR(base) ((base) + (0xF54UL))
#define SOC_CRGPERIPH_PERI_AUTODIV6_ADDR(base) ((base) + (0xF58UL))
#define SOC_CRGPERIPH_PERI_AUTODIV9_ADDR(base) ((base) + (0xF64UL))
#define SOC_CRGPERIPH_PERI_AUTODIV11_ADDR(base) ((base) + (0xF6CUL))
#define SOC_CRGPERIPH_PERI_AUTODIV12_ADDR(base) ((base) + (0xF70UL))
#define SOC_CRGPERIPH_PERI_AUTODIV13_ADDR(base) ((base) + (0xF74UL))
#define SOC_CRGPERIPH_PERI_AUTODIV14_ADDR(base) ((base) + (0xF78UL))
#define SOC_CRGPERIPH_PERI_AUTODIV15_ADDR(base) ((base) + (0xF7CUL))
#define SOC_CRGPERIPH_PERI_AUTODIV16_ADDR(base) ((base) + (0xF80UL))
#define SOC_CRGPERIPH_PERI_AUTODIV17_ADDR(base) ((base) + (0xF84UL))
#define SOC_CRGPERIPH_PERI_AUTODIV_ACPU_ADDR(base) ((base) + (0xF90UL))
#define SOC_CRGPERIPH_PERI_AUTODIV_MCPU_ADDR(base) ((base) + (0xF94UL))
#define SOC_CRGPERIPH_PERI_AUTODIV18_ADDR(base) ((base) + (0xF98UL))
#define SOC_CRGPERIPH_PERI_AUTODIV19_ADDR(base) ((base) + (0xF9cUL))
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_ADDR(base) ((base) + (0xFD0UL))
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_ADDR(base) ((base) + (0xFD4UL))
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_ADDR(base) ((base) + (0xFD8UL))
#define SOC_CRGPERIPH_IPCLKRST_BYPASS3_ADDR(base) ((base) + (0xFDCUL))
#define SOC_CRGPERIPH_IPCLKRST_BYPASS4_ADDR(base) ((base) + (0xFE0UL))
#define SOC_CRGPERIPH_PERI_CTRL2_L_ADDR(base) ((base) + (0xFF0UL))
#define SOC_CRGPERIPH_PERI_CTRL2_H_ADDR(base) ((base) + (0xFF4UL))
#else
#define SOC_CRGPERIPH_PEREN0_ADDR(base) ((base) + (0x000))
#define SOC_CRGPERIPH_PERDIS0_ADDR(base) ((base) + (0x004))
#define SOC_CRGPERIPH_PERCLKEN0_ADDR(base) ((base) + (0x008))
#define SOC_CRGPERIPH_PERSTAT0_ADDR(base) ((base) + (0x00C))
#define SOC_CRGPERIPH_PEREN1_ADDR(base) ((base) + (0x010))
#define SOC_CRGPERIPH_PERDIS1_ADDR(base) ((base) + (0x014))
#define SOC_CRGPERIPH_PERCLKEN1_ADDR(base) ((base) + (0x018))
#define SOC_CRGPERIPH_PERSTAT1_ADDR(base) ((base) + (0x01C))
#define SOC_CRGPERIPH_PEREN2_ADDR(base) ((base) + (0x020))
#define SOC_CRGPERIPH_PERDIS2_ADDR(base) ((base) + (0x024))
#define SOC_CRGPERIPH_PERCLKEN2_ADDR(base) ((base) + (0x028))
#define SOC_CRGPERIPH_PERSTAT2_ADDR(base) ((base) + (0x02C))
#define SOC_CRGPERIPH_PEREN3_ADDR(base) ((base) + (0x030))
#define SOC_CRGPERIPH_PERDIS3_ADDR(base) ((base) + (0x034))
#define SOC_CRGPERIPH_PERCLKEN3_ADDR(base) ((base) + (0x038))
#define SOC_CRGPERIPH_PERSTAT3_ADDR(base) ((base) + (0x03C))
#define SOC_CRGPERIPH_PEREN4_ADDR(base) ((base) + (0x040))
#define SOC_CRGPERIPH_PERDIS4_ADDR(base) ((base) + (0x044))
#define SOC_CRGPERIPH_PERCLKEN4_ADDR(base) ((base) + (0x048))
#define SOC_CRGPERIPH_PERSTAT4_ADDR(base) ((base) + (0x04C))
#define SOC_CRGPERIPH_PEREN5_ADDR(base) ((base) + (0x050))
#define SOC_CRGPERIPH_PERDIS5_ADDR(base) ((base) + (0x054))
#define SOC_CRGPERIPH_PERCLKEN5_ADDR(base) ((base) + (0x058))
#define SOC_CRGPERIPH_PERSTAT5_ADDR(base) ((base) + (0x05C))
#define SOC_CRGPERIPH_PERRSTEN0_ADDR(base) ((base) + (0x060))
#define SOC_CRGPERIPH_PERRSTDIS0_ADDR(base) ((base) + (0x064))
#define SOC_CRGPERIPH_PERRSTSTAT0_ADDR(base) ((base) + (0x068))
#define SOC_CRGPERIPH_PERRSTEN1_ADDR(base) ((base) + (0x06C))
#define SOC_CRGPERIPH_PERRSTDIS1_ADDR(base) ((base) + (0x070))
#define SOC_CRGPERIPH_PERRSTSTAT1_ADDR(base) ((base) + (0x074))
#define SOC_CRGPERIPH_PERRSTEN2_ADDR(base) ((base) + (0x078))
#define SOC_CRGPERIPH_PERRSTDIS2_ADDR(base) ((base) + (0x07C))
#define SOC_CRGPERIPH_PERRSTSTAT2_ADDR(base) ((base) + (0x080))
#define SOC_CRGPERIPH_PERRSTEN3_ADDR(base) ((base) + (0x084))
#define SOC_CRGPERIPH_PERRSTDIS3_ADDR(base) ((base) + (0x088))
#define SOC_CRGPERIPH_PERRSTSTAT3_ADDR(base) ((base) + (0x08C))
#define SOC_CRGPERIPH_PERRSTEN4_ADDR(base) ((base) + (0x090))
#define SOC_CRGPERIPH_PERRSTDIS4_ADDR(base) ((base) + (0x094))
#define SOC_CRGPERIPH_PERRSTSTAT4_ADDR(base) ((base) + (0x098))
#define SOC_CRGPERIPH_PERRSTEN5_ADDR(base) ((base) + (0x09C))
#define SOC_CRGPERIPH_PERRSTDIS5_ADDR(base) ((base) + (0x0A0))
#define SOC_CRGPERIPH_PERRSTSTAT5_ADDR(base) ((base) + (0x0A4))
#define SOC_CRGPERIPH_CLKDIV0_ADDR(base) ((base) + (0x0A8))
#define SOC_CRGPERIPH_CLKDIV1_ADDR(base) ((base) + (0x0AC))
#define SOC_CRGPERIPH_CLKDIV2_ADDR(base) ((base) + (0x0B0))
#define SOC_CRGPERIPH_CLKDIV3_ADDR(base) ((base) + (0x0B4))
#define SOC_CRGPERIPH_CLKDIV4_ADDR(base) ((base) + (0x0B8))
#define SOC_CRGPERIPH_CLKDIV5_ADDR(base) ((base) + (0x0BC))
#define SOC_CRGPERIPH_CLKDIV6_ADDR(base) ((base) + (0x0C0))
#define SOC_CRGPERIPH_CLKDIV7_ADDR(base) ((base) + (0x0C4))
#define SOC_CRGPERIPH_CLKDIV8_ADDR(base) ((base) + (0x0C8))
#define SOC_CRGPERIPH_CLKDIV9_ADDR(base) ((base) + (0x0CC))
#define SOC_CRGPERIPH_CLKDIV10_ADDR(base) ((base) + (0x0D0))
#define SOC_CRGPERIPH_CLKDIV11_ADDR(base) ((base) + (0x0D4))
#define SOC_CRGPERIPH_CLKDIV12_ADDR(base) ((base) + (0x0D8))
#define SOC_CRGPERIPH_CLKDIV13_ADDR(base) ((base) + (0x0DC))
#define SOC_CRGPERIPH_CLKDIV14_ADDR(base) ((base) + (0x0E0))
#define SOC_CRGPERIPH_CLKDIV15_ADDR(base) ((base) + (0x0E4))
#define SOC_CRGPERIPH_CLKDIV16_ADDR(base) ((base) + (0x0E8))
#define SOC_CRGPERIPH_CLKDIV17_ADDR(base) ((base) + (0x0EC))
#define SOC_CRGPERIPH_CLKDIV18_ADDR(base) ((base) + (0x0F0))
#define SOC_CRGPERIPH_CLKDIV19_ADDR(base) ((base) + (0x0F4))
#define SOC_CRGPERIPH_CLKDIV20_ADDR(base) ((base) + (0x0F8))
#define SOC_CRGPERIPH_CLKDIV21_ADDR(base) ((base) + (0x0FC))
#define SOC_CRGPERIPH_CLKDIV22_ADDR(base) ((base) + (0x100))
#define SOC_CRGPERIPH_CLKDIV23_ADDR(base) ((base) + (0x104))
#define SOC_CRGPERIPH_CLKDIV24_ADDR(base) ((base) + (0x108))
#define SOC_CRGPERIPH_CLKDIV25_ADDR(base) ((base) + (0x10C))
#define SOC_CRGPERIPH_PERI_STAT1_ADDR(base) ((base) + (0x114))
#define SOC_CRGPERIPH_PERI_STAT2_ADDR(base) ((base) + (0x118))
#define SOC_CRGPERIPH_PERI_STAT3_ADDR(base) ((base) + (0x11C))
#define SOC_CRGPERIPH_PERI_CTRL0_ADDR(base) ((base) + (0x120))
#define SOC_CRGPERIPH_PERI_CTRL3_ADDR(base) ((base) + (0x12C))
#define SOC_CRGPERIPH_PERI_STAT10_ADDR(base) ((base) + (0x130))
#define SOC_CRGPERIPH_PERI_STAT11_ADDR(base) ((base) + (0x134))
#define SOC_CRGPERIPH_CORESIGHTLPSTAT_ADDR(base) ((base) + (0x204))
#define SOC_CRGPERIPH_CORESIGHT_CTRL_ADDR(base) ((base) + (0x208))
#define SOC_CRGPERIPH_CORESIGHTETFINT_ADDR(base) ((base) + (0x20C))
#define SOC_CRGPERIPH_CORESIGHTETRINT_ADDR(base) ((base) + (0x210))
#define SOC_CRGPERIPH_ADB_GT_STATUS_ADDR(base) ((base) + (0x21C))
#define SOC_CRGPERIPH_ADB_WAKEUP_STATUS_ADDR(base) ((base) + (0x220))
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_ADDR(base) ((base) + (0x400))
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_ADDR(base) ((base) + (0x404))
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_ADDR(base) ((base) + (0x408))
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT3_ADDR(base) ((base) + (0x40C))
#define SOC_CRGPERIPH_PEREN6_ADDR(base) ((base) + (0x410))
#define SOC_CRGPERIPH_PERDIS6_ADDR(base) ((base) + (0x414))
#define SOC_CRGPERIPH_PERCLKEN6_ADDR(base) ((base) + (0x418))
#define SOC_CRGPERIPH_PERSTAT6_ADDR(base) ((base) + (0x41C))
#define SOC_CRGPERIPH_PEREN7_ADDR(base) ((base) + (0x420))
#define SOC_CRGPERIPH_PERDIS7_ADDR(base) ((base) + (0x424))
#define SOC_CRGPERIPH_PERCLKEN7_ADDR(base) ((base) + (0x428))
#define SOC_CRGPERIPH_PERSTAT7_ADDR(base) ((base) + (0x42C))
#define SOC_CRGPERIPH_PEREN8_ADDR(base) ((base) + (0x430))
#define SOC_CRGPERIPH_PERDIS8_ADDR(base) ((base) + (0x434))
#define SOC_CRGPERIPH_PERCLKEN8_ADDR(base) ((base) + (0x438))
#define SOC_CRGPERIPH_PERSTAT8_ADDR(base) ((base) + (0x43C))
#define SOC_CRGPERIPH_PEREN9_ADDR(base) ((base) + (0x440))
#define SOC_CRGPERIPH_PERDIS9_ADDR(base) ((base) + (0x444))
#define SOC_CRGPERIPH_PERCLKEN9_ADDR(base) ((base) + (0x448))
#define SOC_CRGPERIPH_PERSTAT9_ADDR(base) ((base) + (0x44C))
#define SOC_CRGPERIPH_PEREN10_ADDR(base) ((base) + (0x450))
#define SOC_CRGPERIPH_PERDIS10_ADDR(base) ((base) + (0x454))
#define SOC_CRGPERIPH_PERCLKEN10_ADDR(base) ((base) + (0x458))
#define SOC_CRGPERIPH_PERSTAT10_ADDR(base) ((base) + (0x45C))
#define SOC_CRGPERIPH_PEREN11_ADDR(base) ((base) + (0x460))
#define SOC_CRGPERIPH_PERDIS11_ADDR(base) ((base) + (0x464))
#define SOC_CRGPERIPH_PERCLKEN11_ADDR(base) ((base) + (0x468))
#define SOC_CRGPERIPH_PERSTAT11_ADDR(base) ((base) + (0x46C))
#define SOC_CRGPERIPH_PEREN12_ADDR(base) ((base) + (0x470))
#define SOC_CRGPERIPH_PERDIS12_ADDR(base) ((base) + (0x474))
#define SOC_CRGPERIPH_PERCLKEN12_ADDR(base) ((base) + (0x478))
#define SOC_CRGPERIPH_PERSTAT12_ADDR(base) ((base) + (0x47C))
#define SOC_CRGPERIPH_PEREN13_ADDR(base) ((base) + (0x480))
#define SOC_CRGPERIPH_PERDIS13_ADDR(base) ((base) + (0x484))
#define SOC_CRGPERIPH_PERCLKEN13_ADDR(base) ((base) + (0x488))
#define SOC_CRGPERIPH_PERSTAT13_ADDR(base) ((base) + (0x48C))
#define SOC_CRGPERIPH_PERI_STAT4_ADDR(base) ((base) + (0x500))
#define SOC_CRGPERIPH_PERI_STAT5_ADDR(base) ((base) + (0x504))
#define SOC_CRGPERIPH_PERI_STAT6_ADDR(base) ((base) + (0x508))
#define SOC_CRGPERIPH_PERI_STAT7_ADDR(base) ((base) + (0x50C))
#define SOC_CRGPERIPH_INTR_MASK_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x520))
#define SOC_CRGPERIPH_INTR_CLR_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x524))
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_ADDR(base) ((base) + (0x528))
#define SOC_CRGPERIPH_DFT_FUNC_GLOBAL_CLK_EN_ADDR(base) ((base) + (0x5FC))
#define SOC_CRGPERIPH_PERI_STAT8_ADDR(base) ((base) + (0x600))
#define SOC_CRGPERIPH_PERI_STAT9_ADDR(base) ((base) + (0x604))
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_ADDR(base) ((base) + (0x668))
#define SOC_CRGPERIPH_PERI_AUTODIV1_ADDR(base) ((base) + (0x6A0))
#define SOC_CRGPERIPH_PERI_AUTODIV2_ADDR(base) ((base) + (0x6A4))
#define SOC_CRGPERIPH_CLKDIV26_ADDR(base) ((base) + (0x700))
#define SOC_CRGPERIPH_CLKDIV27_ADDR(base) ((base) + (0x704))
#define SOC_CRGPERIPH_CLKDIV28_ADDR(base) ((base) + (0x708))
#define SOC_CRGPERIPH_CLKDIV29_ADDR(base) ((base) + (0x70C))
#define SOC_CRGPERIPH_CLKDIV30_ADDR(base) ((base) + (0x710))
#define SOC_CRGPERIPH_CLKDIV31_ADDR(base) ((base) + (0x714))
#define SOC_CRGPERIPH_CLKDIV32_ADDR(base) ((base) + (0x718))
#define SOC_CRGPERIPH_PERI_COMMON_CTRL0_ADDR(base) ((base) + (0x720))
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ADDR(base) ((base) + (0x724))
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ADDR(base) ((base) + (0x728))
#define SOC_CRGPERIPH_PERI_COMMON_CTRL3_ADDR(base) ((base) + (0x72C))
#define SOC_CRGPERIPH_PERI_COMMON_CTRL4_ADDR(base) ((base) + (0x730))
#define SOC_CRGPERIPH_PPLL6CTRL0_ADDR(base) ((base) + (0x830))
#define SOC_CRGPERIPH_PPLL6CTRL1_ADDR(base) ((base) + (0x834))
#define SOC_CRGPERIPH_PPLL7CTRL0_ADDR(base) ((base) + (0x838))
#define SOC_CRGPERIPH_PPLL7CTRL1_ADDR(base) ((base) + (0x83C))
#define SOC_CRGPERIPH_PPLL6SSCCTRL_ADDR(base) ((base) + (0x858))
#define SOC_CRGPERIPH_PPLL7SSCCTRL_ADDR(base) ((base) + (0x85C))
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_CLEAR_ADDR(base) ((base) + (0x918))
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_ADDR(base) ((base) + (0x91C))
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_CTRL_ADDR(base) ((base) + (0x920))
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_ADDR(base) ((base) + (0x924))
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_ADDR(base) ((base) + (0x928))
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT0_ADDR(base) ((base) + (0x92C))
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT1_ADDR(base) ((base) + (0x930))
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT2_ADDR(base) ((base) + (0x934))
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT3_ADDR(base) ((base) + (0x938))
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE0_ADDR(base) ((base) + (0x950))
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE1_ADDR(base) ((base) + (0x954))
#define SOC_CRGPERIPH_PLL_FSM_NS_STAT_ADDR(base) ((base) + (0x958))
#define SOC_CRGPERIPH_FNPLL_CFG0_ADDR(base) ((base) + (0xA00))
#define SOC_CRGPERIPH_FNPLL_CFG1_ADDR(base) ((base) + (0xA04))
#define SOC_CRGPERIPH_FNPLL_CFG2_ADDR(base) ((base) + (0xA08))
#define SOC_CRGPERIPH_FNPLL_CFG3_ADDR(base) ((base) + (0xA0c))
#define SOC_CRGPERIPH_FNPLL_STATE0_ADDR(base) ((base) + (0xA10))
#define SOC_CRGPERIPH_PPLL1CTRL0_ADDR(base) ((base) + (0xA6C))
#define SOC_CRGPERIPH_PPLL1CTRL1_ADDR(base) ((base) + (0xA70))
#define SOC_CRGPERIPH_PPLL2CTRL0_ADDR(base) ((base) + (0xA74))
#define SOC_CRGPERIPH_PPLL2CTRL1_ADDR(base) ((base) + (0xA78))
#define SOC_CRGPERIPH_PPLL3CTRL0_ADDR(base) ((base) + (0xA7C))
#define SOC_CRGPERIPH_PPLL3CTRL1_ADDR(base) ((base) + (0xA80))
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ADDR(base) ((base) + (0xA84))
#define SOC_CRGPERIPH_PPLL2_BCTRL1_ADDR(base) ((base) + (0xA88))
#define SOC_CRGPERIPH_PPLL1SSCCTRL_ADDR(base) ((base) + (0xA9C))
#define SOC_CRGPERIPH_PPLL2SSCCTRL_ADDR(base) ((base) + (0xAA0))
#define SOC_CRGPERIPH_PPLL3SSCCTRL_ADDR(base) ((base) + (0xAA4))
#define SOC_CRGPERIPH_PPLL2_BSSCCTRL_ADDR(base) ((base) + (0xAA8))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_ADDR(base) ((base) + (0xB00))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_ADDR(base) ((base) + (0xB04))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV2_ADDR(base) ((base) + (0xB08))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV3_ADDR(base) ((base) + (0xB0C))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV4_ADDR(base) ((base) + (0xB10))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV5_ADDR(base) ((base) + (0xB14))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV6_ADDR(base) ((base) + (0xB18))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV7_ADDR(base) ((base) + (0xB1C))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV8_ADDR(base) ((base) + (0xB20))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV9_ADDR(base) ((base) + (0xB24))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV10_ADDR(base) ((base) + (0xB28))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV11_ADDR(base) ((base) + (0xB2C))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV12_ADDR(base) ((base) + (0xB30))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV13_ADDR(base) ((base) + (0xB34))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_ADDR(base) ((base) + (0xB38))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV15_ADDR(base) ((base) + (0xB3C))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV16_ADDR(base) ((base) + (0xB40))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV17_ADDR(base) ((base) + (0xB44))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV18_ADDR(base) ((base) + (0xB48))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV19_ADDR(base) ((base) + (0xB4C))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV20_ADDR(base) ((base) + (0xB50))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV21_ADDR(base) ((base) + (0xB54))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV22_ADDR(base) ((base) + (0xB58))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV23_ADDR(base) ((base) + (0xB5c))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV24_ADDR(base) ((base) + (0xB60))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV25_ADDR(base) ((base) + (0xB64))
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV26_ADDR(base) ((base) + (0xB68))
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_ADDR(base) ((base) + (0xC38))
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_1_ADDR(base) ((base) + (0xC3C))
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_ADDR(base) ((base) + (0xC40))
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_ADDR(base) ((base) + (0xC44))
#define SOC_CRGPERIPH_PLL_FSM_STAT0_ADDR(base) ((base) + (0xC48))
#define SOC_CRGPERIPH_PLL_FSM_STAT1_ADDR(base) ((base) + (0xC4C))
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ADDR(base) ((base) + (0xC50))
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL0_ADDR(base) ((base) + (0xC54))
#define SOC_CRGPERIPH_PLL_GT_VOTE_CTRL0_ADDR(base) ((base) + (0xC58))
#define SOC_CRGPERIPH_PLL_BYPASS_VOTE_CTRL0_ADDR(base) ((base) + (0xC5C))
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL1_ADDR(base) ((base) + (0xC60))
#define SOC_CRGPERIPH_PLL_GT_VOTE_CTRL1_ADDR(base) ((base) + (0xC64))
#define SOC_CRGPERIPH_PLL_BYPASS_VOTE_CTRL1_ADDR(base) ((base) + (0xC68))
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL2_ADDR(base) ((base) + (0xC6C))
#define SOC_CRGPERIPH_PLL_GT_VOTE_CTRL2_ADDR(base) ((base) + (0xC70))
#define SOC_CRGPERIPH_PLL_BYPASS_VOTE_CTRL2_ADDR(base) ((base) + (0xC74))
#define SOC_CRGPERIPH_PERI_FNPLL_STAT_SEL_ADDR(base) ((base) + (0xC78))
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ADDR(base) ((base) + (0xD00))
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ADDR(base) ((base) + (0xD04))
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ADDR(base) ((base) + (0xD08))
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ADDR(base) ((base) + (0xD0C))
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ADDR(base) ((base) + (0xD10))
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ADDR(base) ((base) + (0xD14))
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ADDR(base) ((base) + (0xD18))
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ADDR(base) ((base) + (0xD1C))
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ADDR(base) ((base) + (0xD20))
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_ADDR(base) ((base) + (0xE00))
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_ADDR(base) ((base) + (0xE04))
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_ADDR(base) ((base) + (0xE08))
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_ADDR(base) ((base) + (0xE0C))
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_ADDR(base) ((base) + (0xE10))
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_ADDR(base) ((base) + (0xE14))
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_ADDR(base) ((base) + (0xE18))
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_ADDR(base) ((base) + (0xE1C))
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_ADDR(base) ((base) + (0xE20))
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_ADDR(base) ((base) + (0xE24))
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_ADDR(base) ((base) + (0xE28))
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_ADDR(base) ((base) + (0xE2C))
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_ADDR(base) ((base) + (0xE30))
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_ADDR(base) ((base) + (0xE34))
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_ADDR(base) ((base) + (0xE38))
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_ADDR(base) ((base) + (0xE3C))
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_ADDR(base) ((base) + (0xE40))
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_ADDR(base) ((base) + (0xE44))
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_ADDR(base) ((base) + (0xE48))
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_ADDR(base) ((base) + (0xE4C))
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_ADDR(base) ((base) + (0xE50))
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_ADDR(base) ((base) + (0xE54))
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_ADDR(base) ((base) + (0xE58))
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_ADDR(base) ((base) + (0xE5C))
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_ADDR(base) ((base) + (0xE60))
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_ADDR(base) ((base) + (0xE64))
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_ADDR(base) ((base) + (0xE68))
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_ADDR(base) ((base) + (0xE6C))
#define SOC_CRGPERIPH_GENERAL_SEC_CTRL0_ADDR(base) ((base) + (0xF00))
#define SOC_CRGPERIPH_DDRSYS_AUTOFS_CTRL0_ADDR(base) ((base) + (0xF20))
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL2_ADDR(base) ((base) + (0xF28))
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL2_ADDR(base) ((base) + (0xF2C))
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL1_ADDR(base) ((base) + (0xF30))
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL1_ADDR(base) ((base) + (0xF34))
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL_ADDR(base) ((base) + (0xF38))
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL_ADDR(base) ((base) + (0xF3C))
#define SOC_CRGPERIPH_PERI_AUTODIV0_ADDR(base) ((base) + (0xF40))
#define SOC_CRGPERIPH_PERI_AUTODIV3_ADDR(base) ((base) + (0xF4C))
#define SOC_CRGPERIPH_PERI_AUTODIV4_ADDR(base) ((base) + (0xF50))
#define SOC_CRGPERIPH_PERI_AUTODIV5_ADDR(base) ((base) + (0xF54))
#define SOC_CRGPERIPH_PERI_AUTODIV6_ADDR(base) ((base) + (0xF58))
#define SOC_CRGPERIPH_PERI_AUTODIV9_ADDR(base) ((base) + (0xF64))
#define SOC_CRGPERIPH_PERI_AUTODIV11_ADDR(base) ((base) + (0xF6C))
#define SOC_CRGPERIPH_PERI_AUTODIV12_ADDR(base) ((base) + (0xF70))
#define SOC_CRGPERIPH_PERI_AUTODIV13_ADDR(base) ((base) + (0xF74))
#define SOC_CRGPERIPH_PERI_AUTODIV14_ADDR(base) ((base) + (0xF78))
#define SOC_CRGPERIPH_PERI_AUTODIV15_ADDR(base) ((base) + (0xF7C))
#define SOC_CRGPERIPH_PERI_AUTODIV16_ADDR(base) ((base) + (0xF80))
#define SOC_CRGPERIPH_PERI_AUTODIV17_ADDR(base) ((base) + (0xF84))
#define SOC_CRGPERIPH_PERI_AUTODIV_ACPU_ADDR(base) ((base) + (0xF90))
#define SOC_CRGPERIPH_PERI_AUTODIV_MCPU_ADDR(base) ((base) + (0xF94))
#define SOC_CRGPERIPH_PERI_AUTODIV18_ADDR(base) ((base) + (0xF98))
#define SOC_CRGPERIPH_PERI_AUTODIV19_ADDR(base) ((base) + (0xF9c))
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_ADDR(base) ((base) + (0xFD0))
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_ADDR(base) ((base) + (0xFD4))
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_ADDR(base) ((base) + (0xFD8))
#define SOC_CRGPERIPH_IPCLKRST_BYPASS3_ADDR(base) ((base) + (0xFDC))
#define SOC_CRGPERIPH_IPCLKRST_BYPASS4_ADDR(base) ((base) + (0xFE0))
#define SOC_CRGPERIPH_PERI_CTRL2_L_ADDR(base) ((base) + (0xFF0))
#define SOC_CRGPERIPH_PERI_CTRL2_H_ADDR(base) ((base) + (0xFF4))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_onewire : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_clk_resource_lock : 1;
        unsigned int reserved_5 : 1;
        unsigned int gt_clk_pasensor_peri : 1;
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
        unsigned int gt_clk_time_stamp : 1;
        unsigned int gt_clk_ufs_dfa_sys : 1;
        unsigned int gt_clk_ufs_dfa_cpu : 1;
        unsigned int gt_pclk_autodiv_hsdtbus : 1;
        unsigned int gt_pclk_autodiv_ufs_dfa_sys : 1;
        unsigned int gt_clk_ao_asp : 1;
        unsigned int reserved_18 : 1;
        unsigned int gt_clk_power_stat : 1;
        unsigned int reserved_19 : 1;
        unsigned int gt_pclk_power_stat : 1;
        unsigned int gt_clk_bist_sync : 1;
    } reg;
} SOC_CRGPERIPH_PEREN0_UNION;
#endif
#define SOC_CRGPERIPH_PEREN0_gt_clk_onewire_START (0)
#define SOC_CRGPERIPH_PEREN0_gt_clk_onewire_END (0)
#define SOC_CRGPERIPH_PEREN0_gt_clk_resource_lock_START (6)
#define SOC_CRGPERIPH_PEREN0_gt_clk_resource_lock_END (6)
#define SOC_CRGPERIPH_PEREN0_gt_clk_pasensor_peri_START (8)
#define SOC_CRGPERIPH_PEREN0_gt_clk_pasensor_peri_END (8)
#define SOC_CRGPERIPH_PEREN0_gt_clk_time_stamp_START (21)
#define SOC_CRGPERIPH_PEREN0_gt_clk_time_stamp_END (21)
#define SOC_CRGPERIPH_PEREN0_gt_clk_ufs_dfa_sys_START (22)
#define SOC_CRGPERIPH_PEREN0_gt_clk_ufs_dfa_sys_END (22)
#define SOC_CRGPERIPH_PEREN0_gt_clk_ufs_dfa_cpu_START (23)
#define SOC_CRGPERIPH_PEREN0_gt_clk_ufs_dfa_cpu_END (23)
#define SOC_CRGPERIPH_PEREN0_gt_pclk_autodiv_hsdtbus_START (24)
#define SOC_CRGPERIPH_PEREN0_gt_pclk_autodiv_hsdtbus_END (24)
#define SOC_CRGPERIPH_PEREN0_gt_pclk_autodiv_ufs_dfa_sys_START (25)
#define SOC_CRGPERIPH_PEREN0_gt_pclk_autodiv_ufs_dfa_sys_END (25)
#define SOC_CRGPERIPH_PEREN0_gt_clk_ao_asp_START (26)
#define SOC_CRGPERIPH_PEREN0_gt_clk_ao_asp_END (26)
#define SOC_CRGPERIPH_PEREN0_gt_clk_power_stat_START (28)
#define SOC_CRGPERIPH_PEREN0_gt_clk_power_stat_END (28)
#define SOC_CRGPERIPH_PEREN0_gt_pclk_power_stat_START (30)
#define SOC_CRGPERIPH_PEREN0_gt_pclk_power_stat_END (30)
#define SOC_CRGPERIPH_PEREN0_gt_clk_bist_sync_START (31)
#define SOC_CRGPERIPH_PEREN0_gt_clk_bist_sync_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_onewire : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_clk_resource_lock : 1;
        unsigned int reserved_5 : 1;
        unsigned int gt_clk_pasensor_peri : 1;
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
        unsigned int gt_clk_time_stamp : 1;
        unsigned int gt_clk_ufs_dfa_sys : 1;
        unsigned int gt_clk_ufs_dfa_cpu : 1;
        unsigned int gt_pclk_autodiv_hsdtbus : 1;
        unsigned int gt_pclk_autodiv_ufs_dfa_sys : 1;
        unsigned int gt_clk_ao_asp : 1;
        unsigned int reserved_18 : 1;
        unsigned int gt_clk_power_stat : 1;
        unsigned int reserved_19 : 1;
        unsigned int gt_pclk_power_stat : 1;
        unsigned int gt_clk_bist_sync : 1;
    } reg;
} SOC_CRGPERIPH_PERDIS0_UNION;
#endif
#define SOC_CRGPERIPH_PERDIS0_gt_clk_onewire_START (0)
#define SOC_CRGPERIPH_PERDIS0_gt_clk_onewire_END (0)
#define SOC_CRGPERIPH_PERDIS0_gt_clk_resource_lock_START (6)
#define SOC_CRGPERIPH_PERDIS0_gt_clk_resource_lock_END (6)
#define SOC_CRGPERIPH_PERDIS0_gt_clk_pasensor_peri_START (8)
#define SOC_CRGPERIPH_PERDIS0_gt_clk_pasensor_peri_END (8)
#define SOC_CRGPERIPH_PERDIS0_gt_clk_time_stamp_START (21)
#define SOC_CRGPERIPH_PERDIS0_gt_clk_time_stamp_END (21)
#define SOC_CRGPERIPH_PERDIS0_gt_clk_ufs_dfa_sys_START (22)
#define SOC_CRGPERIPH_PERDIS0_gt_clk_ufs_dfa_sys_END (22)
#define SOC_CRGPERIPH_PERDIS0_gt_clk_ufs_dfa_cpu_START (23)
#define SOC_CRGPERIPH_PERDIS0_gt_clk_ufs_dfa_cpu_END (23)
#define SOC_CRGPERIPH_PERDIS0_gt_pclk_autodiv_hsdtbus_START (24)
#define SOC_CRGPERIPH_PERDIS0_gt_pclk_autodiv_hsdtbus_END (24)
#define SOC_CRGPERIPH_PERDIS0_gt_pclk_autodiv_ufs_dfa_sys_START (25)
#define SOC_CRGPERIPH_PERDIS0_gt_pclk_autodiv_ufs_dfa_sys_END (25)
#define SOC_CRGPERIPH_PERDIS0_gt_clk_ao_asp_START (26)
#define SOC_CRGPERIPH_PERDIS0_gt_clk_ao_asp_END (26)
#define SOC_CRGPERIPH_PERDIS0_gt_clk_power_stat_START (28)
#define SOC_CRGPERIPH_PERDIS0_gt_clk_power_stat_END (28)
#define SOC_CRGPERIPH_PERDIS0_gt_pclk_power_stat_START (30)
#define SOC_CRGPERIPH_PERDIS0_gt_pclk_power_stat_END (30)
#define SOC_CRGPERIPH_PERDIS0_gt_clk_bist_sync_START (31)
#define SOC_CRGPERIPH_PERDIS0_gt_clk_bist_sync_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_onewire : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_clk_resource_lock : 1;
        unsigned int reserved_5 : 1;
        unsigned int gt_clk_pasensor_peri : 1;
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
        unsigned int gt_clk_time_stamp : 1;
        unsigned int gt_clk_ufs_dfa_sys : 1;
        unsigned int gt_clk_ufs_dfa_cpu : 1;
        unsigned int gt_pclk_autodiv_hsdtbus : 1;
        unsigned int gt_pclk_autodiv_ufs_dfa_sys : 1;
        unsigned int gt_clk_ao_asp : 1;
        unsigned int reserved_18 : 1;
        unsigned int gt_clk_power_stat : 1;
        unsigned int reserved_19 : 1;
        unsigned int gt_pclk_power_stat : 1;
        unsigned int gt_clk_bist_sync : 1;
    } reg;
} SOC_CRGPERIPH_PERCLKEN0_UNION;
#endif
#define SOC_CRGPERIPH_PERCLKEN0_gt_clk_onewire_START (0)
#define SOC_CRGPERIPH_PERCLKEN0_gt_clk_onewire_END (0)
#define SOC_CRGPERIPH_PERCLKEN0_gt_clk_resource_lock_START (6)
#define SOC_CRGPERIPH_PERCLKEN0_gt_clk_resource_lock_END (6)
#define SOC_CRGPERIPH_PERCLKEN0_gt_clk_pasensor_peri_START (8)
#define SOC_CRGPERIPH_PERCLKEN0_gt_clk_pasensor_peri_END (8)
#define SOC_CRGPERIPH_PERCLKEN0_gt_clk_time_stamp_START (21)
#define SOC_CRGPERIPH_PERCLKEN0_gt_clk_time_stamp_END (21)
#define SOC_CRGPERIPH_PERCLKEN0_gt_clk_ufs_dfa_sys_START (22)
#define SOC_CRGPERIPH_PERCLKEN0_gt_clk_ufs_dfa_sys_END (22)
#define SOC_CRGPERIPH_PERCLKEN0_gt_clk_ufs_dfa_cpu_START (23)
#define SOC_CRGPERIPH_PERCLKEN0_gt_clk_ufs_dfa_cpu_END (23)
#define SOC_CRGPERIPH_PERCLKEN0_gt_pclk_autodiv_hsdtbus_START (24)
#define SOC_CRGPERIPH_PERCLKEN0_gt_pclk_autodiv_hsdtbus_END (24)
#define SOC_CRGPERIPH_PERCLKEN0_gt_pclk_autodiv_ufs_dfa_sys_START (25)
#define SOC_CRGPERIPH_PERCLKEN0_gt_pclk_autodiv_ufs_dfa_sys_END (25)
#define SOC_CRGPERIPH_PERCLKEN0_gt_clk_ao_asp_START (26)
#define SOC_CRGPERIPH_PERCLKEN0_gt_clk_ao_asp_END (26)
#define SOC_CRGPERIPH_PERCLKEN0_gt_clk_power_stat_START (28)
#define SOC_CRGPERIPH_PERCLKEN0_gt_clk_power_stat_END (28)
#define SOC_CRGPERIPH_PERCLKEN0_gt_pclk_power_stat_START (30)
#define SOC_CRGPERIPH_PERCLKEN0_gt_pclk_power_stat_END (30)
#define SOC_CRGPERIPH_PERCLKEN0_gt_clk_bist_sync_START (31)
#define SOC_CRGPERIPH_PERCLKEN0_gt_clk_bist_sync_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_onewire : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int st_clk_resource_lock : 1;
        unsigned int reserved_5 : 1;
        unsigned int st_clk_pasensor_peri : 1;
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
        unsigned int st_clk_time_stamp : 1;
        unsigned int st_clk_ufs_dfa_sys : 1;
        unsigned int st_clk_ufs_dfa_cpu : 1;
        unsigned int st_pclk_autodiv_hsdtbus : 1;
        unsigned int st_pclk_autodiv_ufs_dfa_sys : 1;
        unsigned int st_clk_ao_asp : 1;
        unsigned int st_clk_npu_tcxo : 1;
        unsigned int st_clk_power_stat : 1;
        unsigned int reserved_18 : 1;
        unsigned int st_pclk_power_stat : 1;
        unsigned int st_clk_bist_sync : 1;
    } reg;
} SOC_CRGPERIPH_PERSTAT0_UNION;
#endif
#define SOC_CRGPERIPH_PERSTAT0_st_clk_onewire_START (0)
#define SOC_CRGPERIPH_PERSTAT0_st_clk_onewire_END (0)
#define SOC_CRGPERIPH_PERSTAT0_st_clk_resource_lock_START (6)
#define SOC_CRGPERIPH_PERSTAT0_st_clk_resource_lock_END (6)
#define SOC_CRGPERIPH_PERSTAT0_st_clk_pasensor_peri_START (8)
#define SOC_CRGPERIPH_PERSTAT0_st_clk_pasensor_peri_END (8)
#define SOC_CRGPERIPH_PERSTAT0_st_clk_time_stamp_START (21)
#define SOC_CRGPERIPH_PERSTAT0_st_clk_time_stamp_END (21)
#define SOC_CRGPERIPH_PERSTAT0_st_clk_ufs_dfa_sys_START (22)
#define SOC_CRGPERIPH_PERSTAT0_st_clk_ufs_dfa_sys_END (22)
#define SOC_CRGPERIPH_PERSTAT0_st_clk_ufs_dfa_cpu_START (23)
#define SOC_CRGPERIPH_PERSTAT0_st_clk_ufs_dfa_cpu_END (23)
#define SOC_CRGPERIPH_PERSTAT0_st_pclk_autodiv_hsdtbus_START (24)
#define SOC_CRGPERIPH_PERSTAT0_st_pclk_autodiv_hsdtbus_END (24)
#define SOC_CRGPERIPH_PERSTAT0_st_pclk_autodiv_ufs_dfa_sys_START (25)
#define SOC_CRGPERIPH_PERSTAT0_st_pclk_autodiv_ufs_dfa_sys_END (25)
#define SOC_CRGPERIPH_PERSTAT0_st_clk_ao_asp_START (26)
#define SOC_CRGPERIPH_PERSTAT0_st_clk_ao_asp_END (26)
#define SOC_CRGPERIPH_PERSTAT0_st_clk_npu_tcxo_START (27)
#define SOC_CRGPERIPH_PERSTAT0_st_clk_npu_tcxo_END (27)
#define SOC_CRGPERIPH_PERSTAT0_st_clk_power_stat_START (28)
#define SOC_CRGPERIPH_PERSTAT0_st_clk_power_stat_END (28)
#define SOC_CRGPERIPH_PERSTAT0_st_pclk_power_stat_START (30)
#define SOC_CRGPERIPH_PERSTAT0_st_pclk_power_stat_END (30)
#define SOC_CRGPERIPH_PERSTAT0_st_clk_bist_sync_START (31)
#define SOC_CRGPERIPH_PERSTAT0_st_clk_bist_sync_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
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
        unsigned int gt_pclk_timer9 : 1;
        unsigned int gt_pclk_timer10 : 1;
        unsigned int gt_pclk_timer11 : 1;
        unsigned int gt_pclk_timer12 : 1;
        unsigned int reserved_19 : 1;
        unsigned int gt_clk_djtag : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
        unsigned int gt_clk_i2c6 : 1;
        unsigned int gt_clk_i2c7 : 1;
    } reg;
} SOC_CRGPERIPH_PEREN1_UNION;
#endif
#define SOC_CRGPERIPH_PEREN1_gt_pclk_timer9_START (22)
#define SOC_CRGPERIPH_PEREN1_gt_pclk_timer9_END (22)
#define SOC_CRGPERIPH_PEREN1_gt_pclk_timer10_START (23)
#define SOC_CRGPERIPH_PEREN1_gt_pclk_timer10_END (23)
#define SOC_CRGPERIPH_PEREN1_gt_pclk_timer11_START (24)
#define SOC_CRGPERIPH_PEREN1_gt_pclk_timer11_END (24)
#define SOC_CRGPERIPH_PEREN1_gt_pclk_timer12_START (25)
#define SOC_CRGPERIPH_PEREN1_gt_pclk_timer12_END (25)
#define SOC_CRGPERIPH_PEREN1_gt_clk_djtag_START (27)
#define SOC_CRGPERIPH_PEREN1_gt_clk_djtag_END (27)
#define SOC_CRGPERIPH_PEREN1_gt_clk_i2c6_START (30)
#define SOC_CRGPERIPH_PEREN1_gt_clk_i2c6_END (30)
#define SOC_CRGPERIPH_PEREN1_gt_clk_i2c7_START (31)
#define SOC_CRGPERIPH_PEREN1_gt_clk_i2c7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
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
        unsigned int gt_pclk_timer9 : 1;
        unsigned int gt_pclk_timer10 : 1;
        unsigned int gt_pclk_timer11 : 1;
        unsigned int gt_pclk_timer12 : 1;
        unsigned int reserved_19 : 1;
        unsigned int gt_clk_djtag : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
        unsigned int gt_clk_i2c6 : 1;
        unsigned int gt_clk_i2c7 : 1;
    } reg;
} SOC_CRGPERIPH_PERDIS1_UNION;
#endif
#define SOC_CRGPERIPH_PERDIS1_gt_pclk_timer9_START (22)
#define SOC_CRGPERIPH_PERDIS1_gt_pclk_timer9_END (22)
#define SOC_CRGPERIPH_PERDIS1_gt_pclk_timer10_START (23)
#define SOC_CRGPERIPH_PERDIS1_gt_pclk_timer10_END (23)
#define SOC_CRGPERIPH_PERDIS1_gt_pclk_timer11_START (24)
#define SOC_CRGPERIPH_PERDIS1_gt_pclk_timer11_END (24)
#define SOC_CRGPERIPH_PERDIS1_gt_pclk_timer12_START (25)
#define SOC_CRGPERIPH_PERDIS1_gt_pclk_timer12_END (25)
#define SOC_CRGPERIPH_PERDIS1_gt_clk_djtag_START (27)
#define SOC_CRGPERIPH_PERDIS1_gt_clk_djtag_END (27)
#define SOC_CRGPERIPH_PERDIS1_gt_clk_i2c6_START (30)
#define SOC_CRGPERIPH_PERDIS1_gt_clk_i2c6_END (30)
#define SOC_CRGPERIPH_PERDIS1_gt_clk_i2c7_START (31)
#define SOC_CRGPERIPH_PERDIS1_gt_clk_i2c7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
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
        unsigned int gt_pclk_timer9 : 1;
        unsigned int gt_pclk_timer10 : 1;
        unsigned int gt_pclk_timer11 : 1;
        unsigned int gt_pclk_timer12 : 1;
        unsigned int reserved_19 : 1;
        unsigned int gt_clk_djtag : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
        unsigned int gt_clk_i2c6 : 1;
        unsigned int gt_clk_i2c7 : 1;
    } reg;
} SOC_CRGPERIPH_PERCLKEN1_UNION;
#endif
#define SOC_CRGPERIPH_PERCLKEN1_gt_pclk_timer9_START (22)
#define SOC_CRGPERIPH_PERCLKEN1_gt_pclk_timer9_END (22)
#define SOC_CRGPERIPH_PERCLKEN1_gt_pclk_timer10_START (23)
#define SOC_CRGPERIPH_PERCLKEN1_gt_pclk_timer10_END (23)
#define SOC_CRGPERIPH_PERCLKEN1_gt_pclk_timer11_START (24)
#define SOC_CRGPERIPH_PERCLKEN1_gt_pclk_timer11_END (24)
#define SOC_CRGPERIPH_PERCLKEN1_gt_pclk_timer12_START (25)
#define SOC_CRGPERIPH_PERCLKEN1_gt_pclk_timer12_END (25)
#define SOC_CRGPERIPH_PERCLKEN1_gt_clk_djtag_START (27)
#define SOC_CRGPERIPH_PERCLKEN1_gt_clk_djtag_END (27)
#define SOC_CRGPERIPH_PERCLKEN1_gt_clk_i2c6_START (30)
#define SOC_CRGPERIPH_PERCLKEN1_gt_clk_i2c6_END (30)
#define SOC_CRGPERIPH_PERCLKEN1_gt_clk_i2c7_START (31)
#define SOC_CRGPERIPH_PERCLKEN1_gt_clk_i2c7_END (31)
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
        unsigned int st_pclk_timer9 : 1;
        unsigned int st_pclk_timer10 : 1;
        unsigned int st_pclk_timer11 : 1;
        unsigned int st_pclk_timer12 : 1;
        unsigned int reserved_22 : 1;
        unsigned int st_clk_djtag : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int st_clk_i2c6 : 1;
        unsigned int st_clk_i2c7 : 1;
    } reg;
} SOC_CRGPERIPH_PERSTAT1_UNION;
#endif
#define SOC_CRGPERIPH_PERSTAT1_st_pclk_timer9_START (22)
#define SOC_CRGPERIPH_PERSTAT1_st_pclk_timer9_END (22)
#define SOC_CRGPERIPH_PERSTAT1_st_pclk_timer10_START (23)
#define SOC_CRGPERIPH_PERSTAT1_st_pclk_timer10_END (23)
#define SOC_CRGPERIPH_PERSTAT1_st_pclk_timer11_START (24)
#define SOC_CRGPERIPH_PERSTAT1_st_pclk_timer11_END (24)
#define SOC_CRGPERIPH_PERSTAT1_st_pclk_timer12_START (25)
#define SOC_CRGPERIPH_PERSTAT1_st_pclk_timer12_END (25)
#define SOC_CRGPERIPH_PERSTAT1_st_clk_djtag_START (27)
#define SOC_CRGPERIPH_PERSTAT1_st_clk_djtag_END (27)
#define SOC_CRGPERIPH_PERSTAT1_st_clk_i2c6_START (30)
#define SOC_CRGPERIPH_PERSTAT1_st_clk_i2c6_END (30)
#define SOC_CRGPERIPH_PERSTAT1_st_clk_i2c7_START (31)
#define SOC_CRGPERIPH_PERSTAT1_st_clk_i2c7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_blpwm1 : 1;
        unsigned int gt_clk_i2c2 : 1;
        unsigned int gt_pclk_ipc0 : 1;
        unsigned int gt_pclk_ipc1 : 1;
        unsigned int gt_pclk_ipc_rtos : 1;
        unsigned int gt_clk_loadmonitor : 1;
        unsigned int gt_pclk_loadmonitor : 1;
        unsigned int gt_clk_i2c3 : 1;
        unsigned int gt_pclk_loadmonitor_lpmcu : 1;
        unsigned int gt_clk_spi1 : 1;
        unsigned int gt_pclk_uart0 : 1;
        unsigned int gt_pclk_uart8 : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_adb_mst_mdm : 1;
        unsigned int gt_pclk_uart4 : 1;
        unsigned int gt_pclk_uart5 : 1;
        unsigned int gt_pclk_wd0 : 1;
        unsigned int gt_pclk_wd1 : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_out1_pre : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_clk_sd_peri : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_pclk_blpwm4 : 1;
        unsigned int gt_pclk_blpwm3 : 1;
        unsigned int gt_pclk_ioc : 1;
        unsigned int gt_clk_codecssi : 1;
        unsigned int gt_clk_i2c4 : 1;
        unsigned int gt_clk_loadmonitor_1 : 1;
        unsigned int gt_pclk_loadmonitor_1 : 1;
        unsigned int gt_pclk_loadmonitor_1_lpmcu : 1;
        unsigned int gt_pclk_pctrl : 1;
    } reg;
} SOC_CRGPERIPH_PEREN2_UNION;
#endif
#define SOC_CRGPERIPH_PEREN2_gt_pclk_blpwm1_START (0)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_blpwm1_END (0)
#define SOC_CRGPERIPH_PEREN2_gt_clk_i2c2_START (1)
#define SOC_CRGPERIPH_PEREN2_gt_clk_i2c2_END (1)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_ipc0_START (2)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_ipc0_END (2)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_ipc1_START (3)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_ipc1_END (3)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_ipc_rtos_START (4)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_ipc_rtos_END (4)
#define SOC_CRGPERIPH_PEREN2_gt_clk_loadmonitor_START (5)
#define SOC_CRGPERIPH_PEREN2_gt_clk_loadmonitor_END (5)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_loadmonitor_START (6)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_loadmonitor_END (6)
#define SOC_CRGPERIPH_PEREN2_gt_clk_i2c3_START (7)
#define SOC_CRGPERIPH_PEREN2_gt_clk_i2c3_END (7)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_loadmonitor_lpmcu_START (8)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_loadmonitor_lpmcu_END (8)
#define SOC_CRGPERIPH_PEREN2_gt_clk_spi1_START (9)
#define SOC_CRGPERIPH_PEREN2_gt_clk_spi1_END (9)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_uart0_START (10)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_uart0_END (10)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_uart8_START (11)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_uart8_END (11)
#define SOC_CRGPERIPH_PEREN2_gt_clk_adb_mst_mdm_START (13)
#define SOC_CRGPERIPH_PEREN2_gt_clk_adb_mst_mdm_END (13)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_uart4_START (14)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_uart4_END (14)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_uart5_START (15)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_uart5_END (15)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_wd0_START (16)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_wd0_END (16)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_wd1_START (17)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_wd1_END (17)
#define SOC_CRGPERIPH_PEREN2_gt_clk_out1_pre_START (19)
#define SOC_CRGPERIPH_PEREN2_gt_clk_out1_pre_END (19)
#define SOC_CRGPERIPH_PEREN2_gt_clk_sd_peri_START (21)
#define SOC_CRGPERIPH_PEREN2_gt_clk_sd_peri_END (21)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_blpwm4_START (23)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_blpwm4_END (23)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_blpwm3_START (24)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_blpwm3_END (24)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_ioc_START (25)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_ioc_END (25)
#define SOC_CRGPERIPH_PEREN2_gt_clk_codecssi_START (26)
#define SOC_CRGPERIPH_PEREN2_gt_clk_codecssi_END (26)
#define SOC_CRGPERIPH_PEREN2_gt_clk_i2c4_START (27)
#define SOC_CRGPERIPH_PEREN2_gt_clk_i2c4_END (27)
#define SOC_CRGPERIPH_PEREN2_gt_clk_loadmonitor_1_START (28)
#define SOC_CRGPERIPH_PEREN2_gt_clk_loadmonitor_1_END (28)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_loadmonitor_1_START (29)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_loadmonitor_1_END (29)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_loadmonitor_1_lpmcu_START (30)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_loadmonitor_1_lpmcu_END (30)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_pctrl_START (31)
#define SOC_CRGPERIPH_PEREN2_gt_pclk_pctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_blpwm1 : 1;
        unsigned int gt_clk_i2c2 : 1;
        unsigned int gt_pclk_ipc0 : 1;
        unsigned int gt_pclk_ipc1 : 1;
        unsigned int gt_pclk_ipc_rtos : 1;
        unsigned int gt_clk_loadmonitor : 1;
        unsigned int gt_pclk_loadmonitor : 1;
        unsigned int gt_clk_i2c3 : 1;
        unsigned int gt_pclk_loadmonitor_lpmcu : 1;
        unsigned int gt_clk_spi1 : 1;
        unsigned int gt_pclk_uart0 : 1;
        unsigned int gt_pclk_uart8 : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_adb_mst_mdm : 1;
        unsigned int gt_pclk_uart4 : 1;
        unsigned int gt_pclk_uart5 : 1;
        unsigned int gt_pclk_wd0 : 1;
        unsigned int gt_pclk_wd1 : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_out1_pre : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_clk_sd_peri : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_pclk_blpwm4 : 1;
        unsigned int gt_pclk_blpwm3 : 1;
        unsigned int gt_pclk_ioc : 1;
        unsigned int gt_clk_codecssi : 1;
        unsigned int gt_clk_i2c4 : 1;
        unsigned int gt_clk_loadmonitor_1 : 1;
        unsigned int gt_pclk_loadmonitor_1 : 1;
        unsigned int gt_pclk_loadmonitor_1_lpmcu : 1;
        unsigned int gt_pclk_pctrl : 1;
    } reg;
} SOC_CRGPERIPH_PERDIS2_UNION;
#endif
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_blpwm1_START (0)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_blpwm1_END (0)
#define SOC_CRGPERIPH_PERDIS2_gt_clk_i2c2_START (1)
#define SOC_CRGPERIPH_PERDIS2_gt_clk_i2c2_END (1)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_ipc0_START (2)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_ipc0_END (2)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_ipc1_START (3)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_ipc1_END (3)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_ipc_rtos_START (4)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_ipc_rtos_END (4)
#define SOC_CRGPERIPH_PERDIS2_gt_clk_loadmonitor_START (5)
#define SOC_CRGPERIPH_PERDIS2_gt_clk_loadmonitor_END (5)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_loadmonitor_START (6)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_loadmonitor_END (6)
#define SOC_CRGPERIPH_PERDIS2_gt_clk_i2c3_START (7)
#define SOC_CRGPERIPH_PERDIS2_gt_clk_i2c3_END (7)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_loadmonitor_lpmcu_START (8)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_loadmonitor_lpmcu_END (8)
#define SOC_CRGPERIPH_PERDIS2_gt_clk_spi1_START (9)
#define SOC_CRGPERIPH_PERDIS2_gt_clk_spi1_END (9)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_uart0_START (10)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_uart0_END (10)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_uart8_START (11)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_uart8_END (11)
#define SOC_CRGPERIPH_PERDIS2_gt_clk_adb_mst_mdm_START (13)
#define SOC_CRGPERIPH_PERDIS2_gt_clk_adb_mst_mdm_END (13)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_uart4_START (14)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_uart4_END (14)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_uart5_START (15)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_uart5_END (15)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_wd0_START (16)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_wd0_END (16)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_wd1_START (17)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_wd1_END (17)
#define SOC_CRGPERIPH_PERDIS2_gt_clk_out1_pre_START (19)
#define SOC_CRGPERIPH_PERDIS2_gt_clk_out1_pre_END (19)
#define SOC_CRGPERIPH_PERDIS2_gt_clk_sd_peri_START (21)
#define SOC_CRGPERIPH_PERDIS2_gt_clk_sd_peri_END (21)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_blpwm4_START (23)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_blpwm4_END (23)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_blpwm3_START (24)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_blpwm3_END (24)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_ioc_START (25)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_ioc_END (25)
#define SOC_CRGPERIPH_PERDIS2_gt_clk_codecssi_START (26)
#define SOC_CRGPERIPH_PERDIS2_gt_clk_codecssi_END (26)
#define SOC_CRGPERIPH_PERDIS2_gt_clk_i2c4_START (27)
#define SOC_CRGPERIPH_PERDIS2_gt_clk_i2c4_END (27)
#define SOC_CRGPERIPH_PERDIS2_gt_clk_loadmonitor_1_START (28)
#define SOC_CRGPERIPH_PERDIS2_gt_clk_loadmonitor_1_END (28)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_loadmonitor_1_START (29)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_loadmonitor_1_END (29)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_loadmonitor_1_lpmcu_START (30)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_loadmonitor_1_lpmcu_END (30)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_pctrl_START (31)
#define SOC_CRGPERIPH_PERDIS2_gt_pclk_pctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_blpwm1 : 1;
        unsigned int gt_clk_i2c2 : 1;
        unsigned int gt_pclk_ipc0 : 1;
        unsigned int gt_pclk_ipc1 : 1;
        unsigned int gt_pclk_ipc_rtos : 1;
        unsigned int gt_clk_loadmonitor : 1;
        unsigned int gt_pclk_loadmonitor : 1;
        unsigned int gt_clk_i2c3 : 1;
        unsigned int gt_pclk_loadmonitor_lpmcu : 1;
        unsigned int gt_clk_spi1 : 1;
        unsigned int gt_pclk_uart0 : 1;
        unsigned int gt_pclk_uart8 : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_adb_mst_mdm : 1;
        unsigned int gt_pclk_uart4 : 1;
        unsigned int gt_pclk_uart5 : 1;
        unsigned int gt_pclk_wd0 : 1;
        unsigned int gt_pclk_wd1 : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_out1_pre : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_clk_sd_peri : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_pclk_blpwm4 : 1;
        unsigned int gt_pclk_blpwm3 : 1;
        unsigned int gt_pclk_ioc : 1;
        unsigned int gt_clk_codecssi : 1;
        unsigned int gt_clk_i2c4 : 1;
        unsigned int gt_clk_loadmonitor_1 : 1;
        unsigned int gt_pclk_loadmonitor_1 : 1;
        unsigned int gt_pclk_loadmonitor_1_lpmcu : 1;
        unsigned int gt_pclk_pctrl : 1;
    } reg;
} SOC_CRGPERIPH_PERCLKEN2_UNION;
#endif
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_blpwm1_START (0)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_blpwm1_END (0)
#define SOC_CRGPERIPH_PERCLKEN2_gt_clk_i2c2_START (1)
#define SOC_CRGPERIPH_PERCLKEN2_gt_clk_i2c2_END (1)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_ipc0_START (2)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_ipc0_END (2)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_ipc1_START (3)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_ipc1_END (3)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_ipc_rtos_START (4)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_ipc_rtos_END (4)
#define SOC_CRGPERIPH_PERCLKEN2_gt_clk_loadmonitor_START (5)
#define SOC_CRGPERIPH_PERCLKEN2_gt_clk_loadmonitor_END (5)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_loadmonitor_START (6)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_loadmonitor_END (6)
#define SOC_CRGPERIPH_PERCLKEN2_gt_clk_i2c3_START (7)
#define SOC_CRGPERIPH_PERCLKEN2_gt_clk_i2c3_END (7)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_loadmonitor_lpmcu_START (8)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_loadmonitor_lpmcu_END (8)
#define SOC_CRGPERIPH_PERCLKEN2_gt_clk_spi1_START (9)
#define SOC_CRGPERIPH_PERCLKEN2_gt_clk_spi1_END (9)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_uart0_START (10)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_uart0_END (10)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_uart8_START (11)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_uart8_END (11)
#define SOC_CRGPERIPH_PERCLKEN2_gt_clk_adb_mst_mdm_START (13)
#define SOC_CRGPERIPH_PERCLKEN2_gt_clk_adb_mst_mdm_END (13)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_uart4_START (14)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_uart4_END (14)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_uart5_START (15)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_uart5_END (15)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_wd0_START (16)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_wd0_END (16)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_wd1_START (17)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_wd1_END (17)
#define SOC_CRGPERIPH_PERCLKEN2_gt_clk_out1_pre_START (19)
#define SOC_CRGPERIPH_PERCLKEN2_gt_clk_out1_pre_END (19)
#define SOC_CRGPERIPH_PERCLKEN2_gt_clk_sd_peri_START (21)
#define SOC_CRGPERIPH_PERCLKEN2_gt_clk_sd_peri_END (21)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_blpwm4_START (23)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_blpwm4_END (23)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_blpwm3_START (24)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_blpwm3_END (24)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_ioc_START (25)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_ioc_END (25)
#define SOC_CRGPERIPH_PERCLKEN2_gt_clk_codecssi_START (26)
#define SOC_CRGPERIPH_PERCLKEN2_gt_clk_codecssi_END (26)
#define SOC_CRGPERIPH_PERCLKEN2_gt_clk_i2c4_START (27)
#define SOC_CRGPERIPH_PERCLKEN2_gt_clk_i2c4_END (27)
#define SOC_CRGPERIPH_PERCLKEN2_gt_clk_loadmonitor_1_START (28)
#define SOC_CRGPERIPH_PERCLKEN2_gt_clk_loadmonitor_1_END (28)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_loadmonitor_1_START (29)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_loadmonitor_1_END (29)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_loadmonitor_1_lpmcu_START (30)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_loadmonitor_1_lpmcu_END (30)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_pctrl_START (31)
#define SOC_CRGPERIPH_PERCLKEN2_gt_pclk_pctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_pclk_blpwm1 : 1;
        unsigned int st_clk_i2c2 : 1;
        unsigned int st_pclk_ipc0 : 1;
        unsigned int st_pclk_ipc1 : 1;
        unsigned int st_pclk_ipc_rtos : 1;
        unsigned int st_clk_loadmonitor : 1;
        unsigned int st_pclk_loadmonitor : 1;
        unsigned int st_clk_i2c3 : 1;
        unsigned int reserved_0 : 1;
        unsigned int st_clk_spi1 : 1;
        unsigned int st_pclk_uart0 : 1;
        unsigned int st_pclk_uart8 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int st_pclk_uart4 : 1;
        unsigned int st_pclk_uart5 : 1;
        unsigned int st_pclk_wd0 : 1;
        unsigned int st_pclk_wd1 : 1;
        unsigned int reserved_3 : 1;
        unsigned int st_clk_out1_pre : 1;
        unsigned int reserved_4 : 1;
        unsigned int st_clk_sd_peri : 1;
        unsigned int reserved_5 : 1;
        unsigned int st_pclk_blpwm4 : 1;
        unsigned int st_pclk_blpwm3 : 1;
        unsigned int st_pclk_ioc : 1;
        unsigned int st_clk_codecssi : 1;
        unsigned int st_clk_i2c4 : 1;
        unsigned int st_clk_loadmonitor_1 : 1;
        unsigned int st_pclk_loadmonitor_1 : 1;
        unsigned int reserved_6 : 1;
        unsigned int st_pclk_pctrl : 1;
    } reg;
} SOC_CRGPERIPH_PERSTAT2_UNION;
#endif
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_blpwm1_START (0)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_blpwm1_END (0)
#define SOC_CRGPERIPH_PERSTAT2_st_clk_i2c2_START (1)
#define SOC_CRGPERIPH_PERSTAT2_st_clk_i2c2_END (1)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_ipc0_START (2)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_ipc0_END (2)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_ipc1_START (3)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_ipc1_END (3)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_ipc_rtos_START (4)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_ipc_rtos_END (4)
#define SOC_CRGPERIPH_PERSTAT2_st_clk_loadmonitor_START (5)
#define SOC_CRGPERIPH_PERSTAT2_st_clk_loadmonitor_END (5)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_loadmonitor_START (6)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_loadmonitor_END (6)
#define SOC_CRGPERIPH_PERSTAT2_st_clk_i2c3_START (7)
#define SOC_CRGPERIPH_PERSTAT2_st_clk_i2c3_END (7)
#define SOC_CRGPERIPH_PERSTAT2_st_clk_spi1_START (9)
#define SOC_CRGPERIPH_PERSTAT2_st_clk_spi1_END (9)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_uart0_START (10)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_uart0_END (10)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_uart8_START (11)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_uart8_END (11)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_uart4_START (14)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_uart4_END (14)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_uart5_START (15)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_uart5_END (15)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_wd0_START (16)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_wd0_END (16)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_wd1_START (17)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_wd1_END (17)
#define SOC_CRGPERIPH_PERSTAT2_st_clk_out1_pre_START (19)
#define SOC_CRGPERIPH_PERSTAT2_st_clk_out1_pre_END (19)
#define SOC_CRGPERIPH_PERSTAT2_st_clk_sd_peri_START (21)
#define SOC_CRGPERIPH_PERSTAT2_st_clk_sd_peri_END (21)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_blpwm4_START (23)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_blpwm4_END (23)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_blpwm3_START (24)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_blpwm3_END (24)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_ioc_START (25)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_ioc_END (25)
#define SOC_CRGPERIPH_PERSTAT2_st_clk_codecssi_START (26)
#define SOC_CRGPERIPH_PERSTAT2_st_clk_codecssi_END (26)
#define SOC_CRGPERIPH_PERSTAT2_st_clk_i2c4_START (27)
#define SOC_CRGPERIPH_PERSTAT2_st_clk_i2c4_END (27)
#define SOC_CRGPERIPH_PERSTAT2_st_clk_loadmonitor_1_START (28)
#define SOC_CRGPERIPH_PERSTAT2_st_clk_loadmonitor_1_END (28)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_loadmonitor_1_START (29)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_loadmonitor_1_END (29)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_pctrl_START (31)
#define SOC_CRGPERIPH_PERSTAT2_st_pclk_pctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_aclk_dmac_lpm3 : 1;
        unsigned int gt_aclk_dmac_acpu : 1;
        unsigned int gt_aclk_dmac_mcpu : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int gt_clk_noc_mdm_cfg : 1;
        unsigned int reserved_8 : 1;
        unsigned int gt_clk_pll_unlock_detect : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int gt_clk_pll_unlock_detect_acpu : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 4;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int gt_clk_txdphy0_cfg : 1;
        unsigned int gt_clk_txdphy0_ref : 1;
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
    } reg;
} SOC_CRGPERIPH_PEREN3_UNION;
#endif
#define SOC_CRGPERIPH_PEREN3_gt_aclk_dmac_lpm3_START (0)
#define SOC_CRGPERIPH_PEREN3_gt_aclk_dmac_lpm3_END (0)
#define SOC_CRGPERIPH_PEREN3_gt_aclk_dmac_acpu_START (1)
#define SOC_CRGPERIPH_PEREN3_gt_aclk_dmac_acpu_END (1)
#define SOC_CRGPERIPH_PEREN3_gt_aclk_dmac_mcpu_START (2)
#define SOC_CRGPERIPH_PEREN3_gt_aclk_dmac_mcpu_END (2)
#define SOC_CRGPERIPH_PEREN3_gt_clk_noc_mdm_cfg_START (11)
#define SOC_CRGPERIPH_PEREN3_gt_clk_noc_mdm_cfg_END (11)
#define SOC_CRGPERIPH_PEREN3_gt_clk_pll_unlock_detect_START (13)
#define SOC_CRGPERIPH_PEREN3_gt_clk_pll_unlock_detect_END (13)
#define SOC_CRGPERIPH_PEREN3_gt_clk_pll_unlock_detect_acpu_START (16)
#define SOC_CRGPERIPH_PEREN3_gt_clk_pll_unlock_detect_acpu_END (16)
#define SOC_CRGPERIPH_PEREN3_gt_clk_txdphy0_cfg_START (28)
#define SOC_CRGPERIPH_PEREN3_gt_clk_txdphy0_cfg_END (28)
#define SOC_CRGPERIPH_PEREN3_gt_clk_txdphy0_ref_START (29)
#define SOC_CRGPERIPH_PEREN3_gt_clk_txdphy0_ref_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_aclk_dmac_lpm3 : 1;
        unsigned int gt_aclk_dmac_acpu : 1;
        unsigned int gt_aclk_dmac_mcpu : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int gt_clk_noc_mdm_cfg : 1;
        unsigned int reserved_8 : 1;
        unsigned int gt_clk_pll_unlock_detect : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int gt_clk_pll_unlock_detect_acpu : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 4;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int gt_clk_txdphy0_cfg : 1;
        unsigned int gt_clk_txdphy0_ref : 1;
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
    } reg;
} SOC_CRGPERIPH_PERDIS3_UNION;
#endif
#define SOC_CRGPERIPH_PERDIS3_gt_aclk_dmac_lpm3_START (0)
#define SOC_CRGPERIPH_PERDIS3_gt_aclk_dmac_lpm3_END (0)
#define SOC_CRGPERIPH_PERDIS3_gt_aclk_dmac_acpu_START (1)
#define SOC_CRGPERIPH_PERDIS3_gt_aclk_dmac_acpu_END (1)
#define SOC_CRGPERIPH_PERDIS3_gt_aclk_dmac_mcpu_START (2)
#define SOC_CRGPERIPH_PERDIS3_gt_aclk_dmac_mcpu_END (2)
#define SOC_CRGPERIPH_PERDIS3_gt_clk_noc_mdm_cfg_START (11)
#define SOC_CRGPERIPH_PERDIS3_gt_clk_noc_mdm_cfg_END (11)
#define SOC_CRGPERIPH_PERDIS3_gt_clk_pll_unlock_detect_START (13)
#define SOC_CRGPERIPH_PERDIS3_gt_clk_pll_unlock_detect_END (13)
#define SOC_CRGPERIPH_PERDIS3_gt_clk_pll_unlock_detect_acpu_START (16)
#define SOC_CRGPERIPH_PERDIS3_gt_clk_pll_unlock_detect_acpu_END (16)
#define SOC_CRGPERIPH_PERDIS3_gt_clk_txdphy0_cfg_START (28)
#define SOC_CRGPERIPH_PERDIS3_gt_clk_txdphy0_cfg_END (28)
#define SOC_CRGPERIPH_PERDIS3_gt_clk_txdphy0_ref_START (29)
#define SOC_CRGPERIPH_PERDIS3_gt_clk_txdphy0_ref_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_aclk_dmac_lpm3 : 1;
        unsigned int gt_aclk_dmac_acpu : 1;
        unsigned int gt_aclk_dmac_mcpu : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int gt_clk_noc_mdm_cfg : 1;
        unsigned int reserved_8 : 1;
        unsigned int gt_clk_pll_unlock_detect : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int gt_clk_pll_unlock_detect_acpu : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 4;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int gt_clk_txdphy0_cfg : 1;
        unsigned int gt_clk_txdphy0_ref : 1;
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
    } reg;
} SOC_CRGPERIPH_PERCLKEN3_UNION;
#endif
#define SOC_CRGPERIPH_PERCLKEN3_gt_aclk_dmac_lpm3_START (0)
#define SOC_CRGPERIPH_PERCLKEN3_gt_aclk_dmac_lpm3_END (0)
#define SOC_CRGPERIPH_PERCLKEN3_gt_aclk_dmac_acpu_START (1)
#define SOC_CRGPERIPH_PERCLKEN3_gt_aclk_dmac_acpu_END (1)
#define SOC_CRGPERIPH_PERCLKEN3_gt_aclk_dmac_mcpu_START (2)
#define SOC_CRGPERIPH_PERCLKEN3_gt_aclk_dmac_mcpu_END (2)
#define SOC_CRGPERIPH_PERCLKEN3_gt_clk_noc_mdm_cfg_START (11)
#define SOC_CRGPERIPH_PERCLKEN3_gt_clk_noc_mdm_cfg_END (11)
#define SOC_CRGPERIPH_PERCLKEN3_gt_clk_pll_unlock_detect_START (13)
#define SOC_CRGPERIPH_PERCLKEN3_gt_clk_pll_unlock_detect_END (13)
#define SOC_CRGPERIPH_PERCLKEN3_gt_clk_pll_unlock_detect_acpu_START (16)
#define SOC_CRGPERIPH_PERCLKEN3_gt_clk_pll_unlock_detect_acpu_END (16)
#define SOC_CRGPERIPH_PERCLKEN3_gt_clk_txdphy0_cfg_START (28)
#define SOC_CRGPERIPH_PERCLKEN3_gt_clk_txdphy0_cfg_END (28)
#define SOC_CRGPERIPH_PERCLKEN3_gt_clk_txdphy0_ref_START (29)
#define SOC_CRGPERIPH_PERCLKEN3_gt_clk_txdphy0_ref_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_dmac0 : 1;
        unsigned int st_clk_dmac1 : 1;
        unsigned int st_aclk_dmac : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int st_clk_noc_mdm_cfg : 1;
        unsigned int reserved_8 : 1;
        unsigned int st_clk_pll_unlock_detect : 1;
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
        unsigned int st_clk_txdphy0_cfg : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
    } reg;
} SOC_CRGPERIPH_PERSTAT3_UNION;
#endif
#define SOC_CRGPERIPH_PERSTAT3_st_clk_dmac0_START (0)
#define SOC_CRGPERIPH_PERSTAT3_st_clk_dmac0_END (0)
#define SOC_CRGPERIPH_PERSTAT3_st_clk_dmac1_START (1)
#define SOC_CRGPERIPH_PERSTAT3_st_clk_dmac1_END (1)
#define SOC_CRGPERIPH_PERSTAT3_st_aclk_dmac_START (2)
#define SOC_CRGPERIPH_PERSTAT3_st_aclk_dmac_END (2)
#define SOC_CRGPERIPH_PERSTAT3_st_clk_noc_mdm_cfg_START (11)
#define SOC_CRGPERIPH_PERSTAT3_st_clk_noc_mdm_cfg_END (11)
#define SOC_CRGPERIPH_PERSTAT3_st_clk_pll_unlock_detect_START (13)
#define SOC_CRGPERIPH_PERSTAT3_st_clk_pll_unlock_detect_END (13)
#define SOC_CRGPERIPH_PERSTAT3_st_clk_txdphy0_cfg_START (28)
#define SOC_CRGPERIPH_PERSTAT3_st_clk_txdphy0_cfg_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_npu_monitor_sensor : 1;
        unsigned int gt_clk_hsdt1_usbdp : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_clk_media_tcxo : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_clk_perf_stat : 1;
        unsigned int gt_pclk_perf_stat : 1;
        unsigned int gt_aclk_perf_stat : 1;
        unsigned int gt_clk_perf_ctrl : 1;
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
    } reg;
} SOC_CRGPERIPH_PEREN4_UNION;
#endif
#define SOC_CRGPERIPH_PEREN4_gt_clk_npu_monitor_sensor_START (0)
#define SOC_CRGPERIPH_PEREN4_gt_clk_npu_monitor_sensor_END (0)
#define SOC_CRGPERIPH_PEREN4_gt_clk_hsdt1_usbdp_START (1)
#define SOC_CRGPERIPH_PEREN4_gt_clk_hsdt1_usbdp_END (1)
#define SOC_CRGPERIPH_PEREN4_gt_clk_media_tcxo_START (6)
#define SOC_CRGPERIPH_PEREN4_gt_clk_media_tcxo_END (6)
#define SOC_CRGPERIPH_PEREN4_gt_clk_perf_stat_START (8)
#define SOC_CRGPERIPH_PEREN4_gt_clk_perf_stat_END (8)
#define SOC_CRGPERIPH_PEREN4_gt_pclk_perf_stat_START (9)
#define SOC_CRGPERIPH_PEREN4_gt_pclk_perf_stat_END (9)
#define SOC_CRGPERIPH_PEREN4_gt_aclk_perf_stat_START (10)
#define SOC_CRGPERIPH_PEREN4_gt_aclk_perf_stat_END (10)
#define SOC_CRGPERIPH_PEREN4_gt_clk_perf_ctrl_START (11)
#define SOC_CRGPERIPH_PEREN4_gt_clk_perf_ctrl_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_npu_monitor_sensor : 1;
        unsigned int gt_clk_hsdt1_usbdp : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_clk_media_tcxo : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_clk_perf_stat : 1;
        unsigned int gt_pclk_perf_stat : 1;
        unsigned int gt_aclk_perf_stat : 1;
        unsigned int gt_clk_perf_ctrl : 1;
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
    } reg;
} SOC_CRGPERIPH_PERDIS4_UNION;
#endif
#define SOC_CRGPERIPH_PERDIS4_gt_clk_npu_monitor_sensor_START (0)
#define SOC_CRGPERIPH_PERDIS4_gt_clk_npu_monitor_sensor_END (0)
#define SOC_CRGPERIPH_PERDIS4_gt_clk_hsdt1_usbdp_START (1)
#define SOC_CRGPERIPH_PERDIS4_gt_clk_hsdt1_usbdp_END (1)
#define SOC_CRGPERIPH_PERDIS4_gt_clk_media_tcxo_START (6)
#define SOC_CRGPERIPH_PERDIS4_gt_clk_media_tcxo_END (6)
#define SOC_CRGPERIPH_PERDIS4_gt_clk_perf_stat_START (8)
#define SOC_CRGPERIPH_PERDIS4_gt_clk_perf_stat_END (8)
#define SOC_CRGPERIPH_PERDIS4_gt_pclk_perf_stat_START (9)
#define SOC_CRGPERIPH_PERDIS4_gt_pclk_perf_stat_END (9)
#define SOC_CRGPERIPH_PERDIS4_gt_aclk_perf_stat_START (10)
#define SOC_CRGPERIPH_PERDIS4_gt_aclk_perf_stat_END (10)
#define SOC_CRGPERIPH_PERDIS4_gt_clk_perf_ctrl_START (11)
#define SOC_CRGPERIPH_PERDIS4_gt_clk_perf_ctrl_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_npu_monitor_sensor : 1;
        unsigned int gt_clk_hsdt1_usbdp : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_clk_media_tcxo : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_clk_perf_stat : 1;
        unsigned int gt_pclk_perf_stat : 1;
        unsigned int gt_aclk_perf_stat : 1;
        unsigned int gt_clk_perf_ctrl : 1;
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
    } reg;
} SOC_CRGPERIPH_PERCLKEN4_UNION;
#endif
#define SOC_CRGPERIPH_PERCLKEN4_gt_clk_npu_monitor_sensor_START (0)
#define SOC_CRGPERIPH_PERCLKEN4_gt_clk_npu_monitor_sensor_END (0)
#define SOC_CRGPERIPH_PERCLKEN4_gt_clk_hsdt1_usbdp_START (1)
#define SOC_CRGPERIPH_PERCLKEN4_gt_clk_hsdt1_usbdp_END (1)
#define SOC_CRGPERIPH_PERCLKEN4_gt_clk_media_tcxo_START (6)
#define SOC_CRGPERIPH_PERCLKEN4_gt_clk_media_tcxo_END (6)
#define SOC_CRGPERIPH_PERCLKEN4_gt_clk_perf_stat_START (8)
#define SOC_CRGPERIPH_PERCLKEN4_gt_clk_perf_stat_END (8)
#define SOC_CRGPERIPH_PERCLKEN4_gt_pclk_perf_stat_START (9)
#define SOC_CRGPERIPH_PERCLKEN4_gt_pclk_perf_stat_END (9)
#define SOC_CRGPERIPH_PERCLKEN4_gt_aclk_perf_stat_START (10)
#define SOC_CRGPERIPH_PERCLKEN4_gt_aclk_perf_stat_END (10)
#define SOC_CRGPERIPH_PERCLKEN4_gt_clk_perf_ctrl_START (11)
#define SOC_CRGPERIPH_PERCLKEN4_gt_clk_perf_ctrl_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_npu_monitor_sensor : 1;
        unsigned int st_clk_hsdt1_usbdp : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int st_clk_media_tcxo : 1;
        unsigned int reserved_4 : 1;
        unsigned int st_clk_perf_stat : 1;
        unsigned int st_pclk_perf_stat : 1;
        unsigned int st_aclk_perf_stat : 1;
        unsigned int st_clk_perf_ctrl : 1;
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
    } reg;
} SOC_CRGPERIPH_PERSTAT4_UNION;
#endif
#define SOC_CRGPERIPH_PERSTAT4_st_clk_npu_monitor_sensor_START (0)
#define SOC_CRGPERIPH_PERSTAT4_st_clk_npu_monitor_sensor_END (0)
#define SOC_CRGPERIPH_PERSTAT4_st_clk_hsdt1_usbdp_START (1)
#define SOC_CRGPERIPH_PERSTAT4_st_clk_hsdt1_usbdp_END (1)
#define SOC_CRGPERIPH_PERSTAT4_st_clk_media_tcxo_START (6)
#define SOC_CRGPERIPH_PERSTAT4_st_clk_media_tcxo_END (6)
#define SOC_CRGPERIPH_PERSTAT4_st_clk_perf_stat_START (8)
#define SOC_CRGPERIPH_PERSTAT4_st_clk_perf_stat_END (8)
#define SOC_CRGPERIPH_PERSTAT4_st_pclk_perf_stat_START (9)
#define SOC_CRGPERIPH_PERSTAT4_st_pclk_perf_stat_END (9)
#define SOC_CRGPERIPH_PERSTAT4_st_aclk_perf_stat_START (10)
#define SOC_CRGPERIPH_PERSTAT4_st_aclk_perf_stat_END (10)
#define SOC_CRGPERIPH_PERSTAT4_st_clk_perf_ctrl_START (11)
#define SOC_CRGPERIPH_PERSTAT4_st_clk_perf_ctrl_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_rxdphy_cfg : 1;
        unsigned int gt_clk_rxdphy0_cfg : 1;
        unsigned int gt_clk_rxdphy1_cfg : 1;
        unsigned int gt_clk_rxdphy2_cfg : 1;
        unsigned int gt_clk_rxdphy3_cfg : 1;
        unsigned int gt_clk_rxdphy4_cfg : 1;
        unsigned int gt_clk_rxdphy5_cfg : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_clk_aohpm : 1;
        unsigned int gt_clk_perihpm : 1;
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
        unsigned int gt_pclk_atg_npu : 1;
        unsigned int gt_pclk_atgc : 1;
        unsigned int gt_pclk_atg_media : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int gt_clk_vcodec_tcxo : 1;
        unsigned int reserved_18 : 1;
    } reg;
} SOC_CRGPERIPH_PEREN5_UNION;
#endif
#define SOC_CRGPERIPH_PEREN5_gt_clk_rxdphy_cfg_START (0)
#define SOC_CRGPERIPH_PEREN5_gt_clk_rxdphy_cfg_END (0)
#define SOC_CRGPERIPH_PEREN5_gt_clk_rxdphy0_cfg_START (1)
#define SOC_CRGPERIPH_PEREN5_gt_clk_rxdphy0_cfg_END (1)
#define SOC_CRGPERIPH_PEREN5_gt_clk_rxdphy1_cfg_START (2)
#define SOC_CRGPERIPH_PEREN5_gt_clk_rxdphy1_cfg_END (2)
#define SOC_CRGPERIPH_PEREN5_gt_clk_rxdphy2_cfg_START (3)
#define SOC_CRGPERIPH_PEREN5_gt_clk_rxdphy2_cfg_END (3)
#define SOC_CRGPERIPH_PEREN5_gt_clk_rxdphy3_cfg_START (4)
#define SOC_CRGPERIPH_PEREN5_gt_clk_rxdphy3_cfg_END (4)
#define SOC_CRGPERIPH_PEREN5_gt_clk_rxdphy4_cfg_START (5)
#define SOC_CRGPERIPH_PEREN5_gt_clk_rxdphy4_cfg_END (5)
#define SOC_CRGPERIPH_PEREN5_gt_clk_rxdphy5_cfg_START (6)
#define SOC_CRGPERIPH_PEREN5_gt_clk_rxdphy5_cfg_END (6)
#define SOC_CRGPERIPH_PEREN5_gt_clk_aohpm_START (11)
#define SOC_CRGPERIPH_PEREN5_gt_clk_aohpm_END (11)
#define SOC_CRGPERIPH_PEREN5_gt_clk_perihpm_START (12)
#define SOC_CRGPERIPH_PEREN5_gt_clk_perihpm_END (12)
#define SOC_CRGPERIPH_PEREN5_gt_pclk_atg_npu_START (24)
#define SOC_CRGPERIPH_PEREN5_gt_pclk_atg_npu_END (24)
#define SOC_CRGPERIPH_PEREN5_gt_pclk_atgc_START (25)
#define SOC_CRGPERIPH_PEREN5_gt_pclk_atgc_END (25)
#define SOC_CRGPERIPH_PEREN5_gt_pclk_atg_media_START (26)
#define SOC_CRGPERIPH_PEREN5_gt_pclk_atg_media_END (26)
#define SOC_CRGPERIPH_PEREN5_gt_clk_vcodec_tcxo_START (30)
#define SOC_CRGPERIPH_PEREN5_gt_clk_vcodec_tcxo_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_rxdphy_cfg : 1;
        unsigned int gt_clk_rxdphy0_cfg : 1;
        unsigned int gt_clk_rxdphy1_cfg : 1;
        unsigned int gt_clk_rxdphy2_cfg : 1;
        unsigned int gt_clk_rxdphy3_cfg : 1;
        unsigned int gt_clk_rxdphy4_cfg : 1;
        unsigned int gt_clk_rxdphy5_cfg : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_clk_aohpm : 1;
        unsigned int gt_clk_perihpm : 1;
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
        unsigned int gt_pclk_atg_npu : 1;
        unsigned int gt_pclk_atgc : 1;
        unsigned int gt_pclk_atg_media : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int gt_clk_vcodec_tcxo : 1;
        unsigned int reserved_18 : 1;
    } reg;
} SOC_CRGPERIPH_PERDIS5_UNION;
#endif
#define SOC_CRGPERIPH_PERDIS5_gt_clk_rxdphy_cfg_START (0)
#define SOC_CRGPERIPH_PERDIS5_gt_clk_rxdphy_cfg_END (0)
#define SOC_CRGPERIPH_PERDIS5_gt_clk_rxdphy0_cfg_START (1)
#define SOC_CRGPERIPH_PERDIS5_gt_clk_rxdphy0_cfg_END (1)
#define SOC_CRGPERIPH_PERDIS5_gt_clk_rxdphy1_cfg_START (2)
#define SOC_CRGPERIPH_PERDIS5_gt_clk_rxdphy1_cfg_END (2)
#define SOC_CRGPERIPH_PERDIS5_gt_clk_rxdphy2_cfg_START (3)
#define SOC_CRGPERIPH_PERDIS5_gt_clk_rxdphy2_cfg_END (3)
#define SOC_CRGPERIPH_PERDIS5_gt_clk_rxdphy3_cfg_START (4)
#define SOC_CRGPERIPH_PERDIS5_gt_clk_rxdphy3_cfg_END (4)
#define SOC_CRGPERIPH_PERDIS5_gt_clk_rxdphy4_cfg_START (5)
#define SOC_CRGPERIPH_PERDIS5_gt_clk_rxdphy4_cfg_END (5)
#define SOC_CRGPERIPH_PERDIS5_gt_clk_rxdphy5_cfg_START (6)
#define SOC_CRGPERIPH_PERDIS5_gt_clk_rxdphy5_cfg_END (6)
#define SOC_CRGPERIPH_PERDIS5_gt_clk_aohpm_START (11)
#define SOC_CRGPERIPH_PERDIS5_gt_clk_aohpm_END (11)
#define SOC_CRGPERIPH_PERDIS5_gt_clk_perihpm_START (12)
#define SOC_CRGPERIPH_PERDIS5_gt_clk_perihpm_END (12)
#define SOC_CRGPERIPH_PERDIS5_gt_pclk_atg_npu_START (24)
#define SOC_CRGPERIPH_PERDIS5_gt_pclk_atg_npu_END (24)
#define SOC_CRGPERIPH_PERDIS5_gt_pclk_atgc_START (25)
#define SOC_CRGPERIPH_PERDIS5_gt_pclk_atgc_END (25)
#define SOC_CRGPERIPH_PERDIS5_gt_pclk_atg_media_START (26)
#define SOC_CRGPERIPH_PERDIS5_gt_pclk_atg_media_END (26)
#define SOC_CRGPERIPH_PERDIS5_gt_clk_vcodec_tcxo_START (30)
#define SOC_CRGPERIPH_PERDIS5_gt_clk_vcodec_tcxo_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_rxdphy_cfg : 1;
        unsigned int gt_clk_rxdphy0_cfg : 1;
        unsigned int gt_clk_rxdphy1_cfg : 1;
        unsigned int gt_clk_rxdphy2_cfg : 1;
        unsigned int gt_clk_rxdphy3_cfg : 1;
        unsigned int gt_clk_rxdphy4_cfg : 1;
        unsigned int gt_clk_rxdphy5_cfg : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_clk_aohpm : 1;
        unsigned int gt_clk_perihpm : 1;
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
        unsigned int gt_pclk_atg_npu : 1;
        unsigned int gt_pclk_atgc : 1;
        unsigned int gt_pclk_atg_media : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int gt_clk_vcodec_tcxo : 1;
        unsigned int reserved_18 : 1;
    } reg;
} SOC_CRGPERIPH_PERCLKEN5_UNION;
#endif
#define SOC_CRGPERIPH_PERCLKEN5_gt_clk_rxdphy_cfg_START (0)
#define SOC_CRGPERIPH_PERCLKEN5_gt_clk_rxdphy_cfg_END (0)
#define SOC_CRGPERIPH_PERCLKEN5_gt_clk_rxdphy0_cfg_START (1)
#define SOC_CRGPERIPH_PERCLKEN5_gt_clk_rxdphy0_cfg_END (1)
#define SOC_CRGPERIPH_PERCLKEN5_gt_clk_rxdphy1_cfg_START (2)
#define SOC_CRGPERIPH_PERCLKEN5_gt_clk_rxdphy1_cfg_END (2)
#define SOC_CRGPERIPH_PERCLKEN5_gt_clk_rxdphy2_cfg_START (3)
#define SOC_CRGPERIPH_PERCLKEN5_gt_clk_rxdphy2_cfg_END (3)
#define SOC_CRGPERIPH_PERCLKEN5_gt_clk_rxdphy3_cfg_START (4)
#define SOC_CRGPERIPH_PERCLKEN5_gt_clk_rxdphy3_cfg_END (4)
#define SOC_CRGPERIPH_PERCLKEN5_gt_clk_rxdphy4_cfg_START (5)
#define SOC_CRGPERIPH_PERCLKEN5_gt_clk_rxdphy4_cfg_END (5)
#define SOC_CRGPERIPH_PERCLKEN5_gt_clk_rxdphy5_cfg_START (6)
#define SOC_CRGPERIPH_PERCLKEN5_gt_clk_rxdphy5_cfg_END (6)
#define SOC_CRGPERIPH_PERCLKEN5_gt_clk_aohpm_START (11)
#define SOC_CRGPERIPH_PERCLKEN5_gt_clk_aohpm_END (11)
#define SOC_CRGPERIPH_PERCLKEN5_gt_clk_perihpm_START (12)
#define SOC_CRGPERIPH_PERCLKEN5_gt_clk_perihpm_END (12)
#define SOC_CRGPERIPH_PERCLKEN5_gt_pclk_atg_npu_START (24)
#define SOC_CRGPERIPH_PERCLKEN5_gt_pclk_atg_npu_END (24)
#define SOC_CRGPERIPH_PERCLKEN5_gt_pclk_atgc_START (25)
#define SOC_CRGPERIPH_PERCLKEN5_gt_pclk_atgc_END (25)
#define SOC_CRGPERIPH_PERCLKEN5_gt_pclk_atg_media_START (26)
#define SOC_CRGPERIPH_PERCLKEN5_gt_pclk_atg_media_END (26)
#define SOC_CRGPERIPH_PERCLKEN5_gt_clk_vcodec_tcxo_START (30)
#define SOC_CRGPERIPH_PERCLKEN5_gt_clk_vcodec_tcxo_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_rxdphy_cfg : 1;
        unsigned int st_clk_rxdphy0_cfg : 1;
        unsigned int st_clk_rxdphy1_cfg : 1;
        unsigned int st_clk_rxdphy2_cfg : 1;
        unsigned int st_clk_rxdphy3_cfg : 1;
        unsigned int st_clk_rxdphy4_cfg : 1;
        unsigned int st_clk_rxdphy5_cfg : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int st_clk_aohpm : 1;
        unsigned int st_clk_perihpm : 1;
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
        unsigned int st_pclk_atg_npu : 1;
        unsigned int st_pclk_atgc : 1;
        unsigned int st_pclk_atg_media : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int st_clk_vcodec_tcxo : 1;
        unsigned int reserved_18 : 1;
    } reg;
} SOC_CRGPERIPH_PERSTAT5_UNION;
#endif
#define SOC_CRGPERIPH_PERSTAT5_st_clk_rxdphy_cfg_START (0)
#define SOC_CRGPERIPH_PERSTAT5_st_clk_rxdphy_cfg_END (0)
#define SOC_CRGPERIPH_PERSTAT5_st_clk_rxdphy0_cfg_START (1)
#define SOC_CRGPERIPH_PERSTAT5_st_clk_rxdphy0_cfg_END (1)
#define SOC_CRGPERIPH_PERSTAT5_st_clk_rxdphy1_cfg_START (2)
#define SOC_CRGPERIPH_PERSTAT5_st_clk_rxdphy1_cfg_END (2)
#define SOC_CRGPERIPH_PERSTAT5_st_clk_rxdphy2_cfg_START (3)
#define SOC_CRGPERIPH_PERSTAT5_st_clk_rxdphy2_cfg_END (3)
#define SOC_CRGPERIPH_PERSTAT5_st_clk_rxdphy3_cfg_START (4)
#define SOC_CRGPERIPH_PERSTAT5_st_clk_rxdphy3_cfg_END (4)
#define SOC_CRGPERIPH_PERSTAT5_st_clk_rxdphy4_cfg_START (5)
#define SOC_CRGPERIPH_PERSTAT5_st_clk_rxdphy4_cfg_END (5)
#define SOC_CRGPERIPH_PERSTAT5_st_clk_rxdphy5_cfg_START (6)
#define SOC_CRGPERIPH_PERSTAT5_st_clk_rxdphy5_cfg_END (6)
#define SOC_CRGPERIPH_PERSTAT5_st_clk_aohpm_START (11)
#define SOC_CRGPERIPH_PERSTAT5_st_clk_aohpm_END (11)
#define SOC_CRGPERIPH_PERSTAT5_st_clk_perihpm_START (12)
#define SOC_CRGPERIPH_PERSTAT5_st_clk_perihpm_END (12)
#define SOC_CRGPERIPH_PERSTAT5_st_pclk_atg_npu_START (24)
#define SOC_CRGPERIPH_PERSTAT5_st_pclk_atg_npu_END (24)
#define SOC_CRGPERIPH_PERSTAT5_st_pclk_atgc_START (25)
#define SOC_CRGPERIPH_PERSTAT5_st_pclk_atgc_END (25)
#define SOC_CRGPERIPH_PERSTAT5_st_pclk_atg_media_START (26)
#define SOC_CRGPERIPH_PERSTAT5_st_pclk_atg_media_END (26)
#define SOC_CRGPERIPH_PERSTAT5_st_clk_vcodec_tcxo_START (30)
#define SOC_CRGPERIPH_PERSTAT5_st_clk_vcodec_tcxo_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_dpctrl_pixel : 1;
        unsigned int ip_rst_time_stamp : 1;
        unsigned int ip_rst_onewire : 1;
        unsigned int ip_rst_pasensor_peri : 1;
        unsigned int ip_rst_resource_lock : 1;
        unsigned int ip_rst_sdcu : 1;
        unsigned int ip_rst_onewire_ref : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_mdmperi_bus : 1;
        unsigned int ip_rst_lat_mon_qice : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_lat_mon_npu : 1;
        unsigned int reserved_3 : 1;
        unsigned int ip_rst_i2c7 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int ip_rst_perf_stat : 1;
        unsigned int ip_rst_i2c6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int ip_rst_noc_mdm_cfg : 1;
        unsigned int ip_rst_power_stat : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int ip_rst_ufs_dfa_cpu : 1;
        unsigned int ip_rst_ufs_dfa_sys : 1;
        unsigned int reserved_13 : 1;
        unsigned int ip_rst_bist_sync : 1;
    } reg;
} SOC_CRGPERIPH_PERRSTEN0_UNION;
#endif
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_dpctrl_pixel_START (0)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_dpctrl_pixel_END (0)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_time_stamp_START (1)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_time_stamp_END (1)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_onewire_START (2)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_onewire_END (2)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_pasensor_peri_START (3)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_pasensor_peri_END (3)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_resource_lock_START (4)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_resource_lock_END (4)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_sdcu_START (5)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_sdcu_END (5)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_onewire_ref_START (6)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_onewire_ref_END (6)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_mdmperi_bus_START (8)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_mdmperi_bus_END (8)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_lat_mon_qice_START (9)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_lat_mon_qice_END (9)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_lat_mon_npu_START (12)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_lat_mon_npu_END (12)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_i2c7_START (14)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_i2c7_END (14)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_perf_stat_START (18)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_perf_stat_END (18)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_i2c6_START (19)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_i2c6_END (19)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_noc_mdm_cfg_START (23)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_noc_mdm_cfg_END (23)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_power_stat_START (24)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_power_stat_END (24)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_ufs_dfa_cpu_START (28)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_ufs_dfa_cpu_END (28)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_ufs_dfa_sys_START (29)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_ufs_dfa_sys_END (29)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_bist_sync_START (31)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_bist_sync_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_dpctrl_pixel : 1;
        unsigned int ip_rst_time_stamp : 1;
        unsigned int ip_rst_onewire : 1;
        unsigned int ip_rst_pasensor_peri : 1;
        unsigned int ip_rst_resource_lock : 1;
        unsigned int ip_rst_sdcu : 1;
        unsigned int ip_rst_onewire_ref : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_mdmperi_bus : 1;
        unsigned int ip_rst_lat_mon_qice : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_lat_mon_npu : 1;
        unsigned int reserved_3 : 1;
        unsigned int ip_rst_i2c7 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int ip_rst_perf_stat : 1;
        unsigned int ip_rst_i2c6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int ip_rst_noc_mdm_cfg : 1;
        unsigned int ip_rst_power_stat : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int ip_rst_ufs_dfa_cpu : 1;
        unsigned int ip_rst_ufs_dfa_sys : 1;
        unsigned int reserved_13 : 1;
        unsigned int ip_rst_bist_sync : 1;
    } reg;
} SOC_CRGPERIPH_PERRSTDIS0_UNION;
#endif
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_dpctrl_pixel_START (0)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_dpctrl_pixel_END (0)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_time_stamp_START (1)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_time_stamp_END (1)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_onewire_START (2)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_onewire_END (2)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_pasensor_peri_START (3)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_pasensor_peri_END (3)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_resource_lock_START (4)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_resource_lock_END (4)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_sdcu_START (5)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_sdcu_END (5)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_onewire_ref_START (6)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_onewire_ref_END (6)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_mdmperi_bus_START (8)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_mdmperi_bus_END (8)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_lat_mon_qice_START (9)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_lat_mon_qice_END (9)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_lat_mon_npu_START (12)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_lat_mon_npu_END (12)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_i2c7_START (14)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_i2c7_END (14)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_perf_stat_START (18)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_perf_stat_END (18)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_i2c6_START (19)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_i2c6_END (19)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_noc_mdm_cfg_START (23)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_noc_mdm_cfg_END (23)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_power_stat_START (24)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_power_stat_END (24)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_ufs_dfa_cpu_START (28)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_ufs_dfa_cpu_END (28)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_ufs_dfa_sys_START (29)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_ufs_dfa_sys_END (29)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_bist_sync_START (31)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_bist_sync_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_dpctrl_pixel : 1;
        unsigned int ip_rst_time_stamp : 1;
        unsigned int ip_rst_onewire : 1;
        unsigned int ip_rst_pasensor_peri : 1;
        unsigned int ip_rst_resource_lock : 1;
        unsigned int ip_rst_sdcu : 1;
        unsigned int ip_rst_onewire_ref : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_mdmperi_bus : 1;
        unsigned int ip_rst_lat_mon_qice : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_lat_mon_npu : 1;
        unsigned int reserved_3 : 1;
        unsigned int ip_rst_i2c7 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int ip_rst_perf_stat : 1;
        unsigned int ip_rst_i2c6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int ip_rst_noc_mdm_cfg : 1;
        unsigned int ip_rst_power_stat : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int ip_rst_ufs_dfa_cpu : 1;
        unsigned int ip_rst_ufs_dfa_sys : 1;
        unsigned int reserved_13 : 1;
        unsigned int ip_rst_bist_sync : 1;
    } reg;
} SOC_CRGPERIPH_PERRSTSTAT0_UNION;
#endif
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_dpctrl_pixel_START (0)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_dpctrl_pixel_END (0)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_time_stamp_START (1)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_time_stamp_END (1)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_onewire_START (2)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_onewire_END (2)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_pasensor_peri_START (3)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_pasensor_peri_END (3)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_resource_lock_START (4)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_resource_lock_END (4)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_sdcu_START (5)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_sdcu_END (5)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_onewire_ref_START (6)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_onewire_ref_END (6)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_mdmperi_bus_START (8)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_mdmperi_bus_END (8)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_lat_mon_qice_START (9)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_lat_mon_qice_END (9)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_lat_mon_npu_START (12)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_lat_mon_npu_END (12)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_i2c7_START (14)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_i2c7_END (14)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_perf_stat_START (18)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_perf_stat_END (18)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_i2c6_START (19)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_i2c6_END (19)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_noc_mdm_cfg_START (23)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_noc_mdm_cfg_END (23)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_power_stat_START (24)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_power_stat_END (24)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_ufs_dfa_cpu_START (28)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_ufs_dfa_cpu_END (28)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_ufs_dfa_sys_START (29)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_ufs_dfa_sys_END (29)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_bist_sync_START (31)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_bist_sync_END (31)
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
        unsigned int ip_prst_timer9 : 1;
        unsigned int ip_prst_timer10 : 1;
        unsigned int ip_prst_timer11 : 1;
        unsigned int ip_prst_timer12 : 1;
        unsigned int reserved_22 : 1;
        unsigned int ip_rst_djtag : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
    } reg;
} SOC_CRGPERIPH_PERRSTEN1_UNION;
#endif
#define SOC_CRGPERIPH_PERRSTEN1_ip_prst_timer9_START (22)
#define SOC_CRGPERIPH_PERRSTEN1_ip_prst_timer9_END (22)
#define SOC_CRGPERIPH_PERRSTEN1_ip_prst_timer10_START (23)
#define SOC_CRGPERIPH_PERRSTEN1_ip_prst_timer10_END (23)
#define SOC_CRGPERIPH_PERRSTEN1_ip_prst_timer11_START (24)
#define SOC_CRGPERIPH_PERRSTEN1_ip_prst_timer11_END (24)
#define SOC_CRGPERIPH_PERRSTEN1_ip_prst_timer12_START (25)
#define SOC_CRGPERIPH_PERRSTEN1_ip_prst_timer12_END (25)
#define SOC_CRGPERIPH_PERRSTEN1_ip_rst_djtag_START (27)
#define SOC_CRGPERIPH_PERRSTEN1_ip_rst_djtag_END (27)
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
        unsigned int ip_prst_timer9 : 1;
        unsigned int ip_prst_timer10 : 1;
        unsigned int ip_prst_timer11 : 1;
        unsigned int ip_prst_timer12 : 1;
        unsigned int reserved_22 : 1;
        unsigned int ip_rst_djtag : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
    } reg;
} SOC_CRGPERIPH_PERRSTDIS1_UNION;
#endif
#define SOC_CRGPERIPH_PERRSTDIS1_ip_prst_timer9_START (22)
#define SOC_CRGPERIPH_PERRSTDIS1_ip_prst_timer9_END (22)
#define SOC_CRGPERIPH_PERRSTDIS1_ip_prst_timer10_START (23)
#define SOC_CRGPERIPH_PERRSTDIS1_ip_prst_timer10_END (23)
#define SOC_CRGPERIPH_PERRSTDIS1_ip_prst_timer11_START (24)
#define SOC_CRGPERIPH_PERRSTDIS1_ip_prst_timer11_END (24)
#define SOC_CRGPERIPH_PERRSTDIS1_ip_prst_timer12_START (25)
#define SOC_CRGPERIPH_PERRSTDIS1_ip_prst_timer12_END (25)
#define SOC_CRGPERIPH_PERRSTDIS1_ip_rst_djtag_START (27)
#define SOC_CRGPERIPH_PERRSTDIS1_ip_rst_djtag_END (27)
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
        unsigned int ip_prst_timer9 : 1;
        unsigned int ip_prst_timer10 : 1;
        unsigned int ip_prst_timer11 : 1;
        unsigned int ip_prst_timer12 : 1;
        unsigned int reserved_22 : 1;
        unsigned int ip_rst_djtag : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
    } reg;
} SOC_CRGPERIPH_PERRSTSTAT1_UNION;
#endif
#define SOC_CRGPERIPH_PERRSTSTAT1_ip_prst_timer9_START (22)
#define SOC_CRGPERIPH_PERRSTSTAT1_ip_prst_timer9_END (22)
#define SOC_CRGPERIPH_PERRSTSTAT1_ip_prst_timer10_START (23)
#define SOC_CRGPERIPH_PERRSTSTAT1_ip_prst_timer10_END (23)
#define SOC_CRGPERIPH_PERRSTSTAT1_ip_prst_timer11_START (24)
#define SOC_CRGPERIPH_PERRSTSTAT1_ip_prst_timer11_END (24)
#define SOC_CRGPERIPH_PERRSTSTAT1_ip_prst_timer12_START (25)
#define SOC_CRGPERIPH_PERRSTSTAT1_ip_prst_timer12_END (25)
#define SOC_CRGPERIPH_PERRSTSTAT1_ip_rst_djtag_START (27)
#define SOC_CRGPERIPH_PERRSTSTAT1_ip_rst_djtag_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_prst_blpwm1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_prst_ipc0 : 1;
        unsigned int ip_prst_ipc1 : 1;
        unsigned int ip_prst_ipc_rtos : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_rst_i2c2 : 1;
        unsigned int ip_rst_i2c3 : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_spi1 : 1;
        unsigned int ip_prst_uart0 : 1;
        unsigned int ip_prst_blpwm4 : 1;
        unsigned int ip_prst_blpwm3 : 1;
        unsigned int reserved_3 : 1;
        unsigned int ip_prst_uart4 : 1;
        unsigned int ip_prst_uart5 : 1;
        unsigned int ip_prst_uart8 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int ip_rst_mdm_drx2dbg : 1;
        unsigned int reserved_8 : 1;
        unsigned int ip_rst_gic : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int ip_rst_codecssi : 1;
        unsigned int ip_rst_i2c4 : 1;
        unsigned int ip_rst_qdb_sys2mdm : 1;
        unsigned int ip_rst_qdb_mdm2sys : 1;
        unsigned int ip_rst_qdb_pdea2ddr : 1;
        unsigned int ip_rst_qdb_mdm2ddr : 1;
    } reg;
} SOC_CRGPERIPH_PERRSTEN2_UNION;
#endif
#define SOC_CRGPERIPH_PERRSTEN2_ip_prst_blpwm1_START (0)
#define SOC_CRGPERIPH_PERRSTEN2_ip_prst_blpwm1_END (0)
#define SOC_CRGPERIPH_PERRSTEN2_ip_prst_ipc0_START (2)
#define SOC_CRGPERIPH_PERRSTEN2_ip_prst_ipc0_END (2)
#define SOC_CRGPERIPH_PERRSTEN2_ip_prst_ipc1_START (3)
#define SOC_CRGPERIPH_PERRSTEN2_ip_prst_ipc1_END (3)
#define SOC_CRGPERIPH_PERRSTEN2_ip_prst_ipc_rtos_START (4)
#define SOC_CRGPERIPH_PERRSTEN2_ip_prst_ipc_rtos_END (4)
#define SOC_CRGPERIPH_PERRSTEN2_ip_rst_i2c2_START (6)
#define SOC_CRGPERIPH_PERRSTEN2_ip_rst_i2c2_END (6)
#define SOC_CRGPERIPH_PERRSTEN2_ip_rst_i2c3_START (7)
#define SOC_CRGPERIPH_PERRSTEN2_ip_rst_i2c3_END (7)
#define SOC_CRGPERIPH_PERRSTEN2_ip_rst_spi1_START (9)
#define SOC_CRGPERIPH_PERRSTEN2_ip_rst_spi1_END (9)
#define SOC_CRGPERIPH_PERRSTEN2_ip_prst_uart0_START (10)
#define SOC_CRGPERIPH_PERRSTEN2_ip_prst_uart0_END (10)
#define SOC_CRGPERIPH_PERRSTEN2_ip_prst_blpwm4_START (11)
#define SOC_CRGPERIPH_PERRSTEN2_ip_prst_blpwm4_END (11)
#define SOC_CRGPERIPH_PERRSTEN2_ip_prst_blpwm3_START (12)
#define SOC_CRGPERIPH_PERRSTEN2_ip_prst_blpwm3_END (12)
#define SOC_CRGPERIPH_PERRSTEN2_ip_prst_uart4_START (14)
#define SOC_CRGPERIPH_PERRSTEN2_ip_prst_uart4_END (14)
#define SOC_CRGPERIPH_PERRSTEN2_ip_prst_uart5_START (15)
#define SOC_CRGPERIPH_PERRSTEN2_ip_prst_uart5_END (15)
#define SOC_CRGPERIPH_PERRSTEN2_ip_prst_uart8_START (16)
#define SOC_CRGPERIPH_PERRSTEN2_ip_prst_uart8_END (16)
#define SOC_CRGPERIPH_PERRSTEN2_ip_rst_mdm_drx2dbg_START (21)
#define SOC_CRGPERIPH_PERRSTEN2_ip_rst_mdm_drx2dbg_END (21)
#define SOC_CRGPERIPH_PERRSTEN2_ip_rst_gic_START (23)
#define SOC_CRGPERIPH_PERRSTEN2_ip_rst_gic_END (23)
#define SOC_CRGPERIPH_PERRSTEN2_ip_rst_codecssi_START (26)
#define SOC_CRGPERIPH_PERRSTEN2_ip_rst_codecssi_END (26)
#define SOC_CRGPERIPH_PERRSTEN2_ip_rst_i2c4_START (27)
#define SOC_CRGPERIPH_PERRSTEN2_ip_rst_i2c4_END (27)
#define SOC_CRGPERIPH_PERRSTEN2_ip_rst_qdb_sys2mdm_START (28)
#define SOC_CRGPERIPH_PERRSTEN2_ip_rst_qdb_sys2mdm_END (28)
#define SOC_CRGPERIPH_PERRSTEN2_ip_rst_qdb_mdm2sys_START (29)
#define SOC_CRGPERIPH_PERRSTEN2_ip_rst_qdb_mdm2sys_END (29)
#define SOC_CRGPERIPH_PERRSTEN2_ip_rst_qdb_pdea2ddr_START (30)
#define SOC_CRGPERIPH_PERRSTEN2_ip_rst_qdb_pdea2ddr_END (30)
#define SOC_CRGPERIPH_PERRSTEN2_ip_rst_qdb_mdm2ddr_START (31)
#define SOC_CRGPERIPH_PERRSTEN2_ip_rst_qdb_mdm2ddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_prst_blpwm1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_prst_ipc0 : 1;
        unsigned int ip_prst_ipc1 : 1;
        unsigned int ip_prst_ipc_rtos : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_rst_i2c2 : 1;
        unsigned int ip_rst_i2c3 : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_spi1 : 1;
        unsigned int ip_prst_uart0 : 1;
        unsigned int ip_prst_blpwm4 : 1;
        unsigned int ip_prst_blpwm3 : 1;
        unsigned int reserved_3 : 1;
        unsigned int ip_prst_uart4 : 1;
        unsigned int ip_prst_uart5 : 1;
        unsigned int ip_prst_uart8 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int ip_rst_mdm_drx2dbg : 1;
        unsigned int reserved_8 : 1;
        unsigned int ip_rst_gic : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int ip_rst_codecssi : 1;
        unsigned int ip_rst_i2c4 : 1;
        unsigned int ip_rst_qdb_sys2mdm : 1;
        unsigned int ip_rst_qdb_mdm2sys : 1;
        unsigned int ip_rst_qdb_pdea2ddr : 1;
        unsigned int ip_rst_qdb_mdm2ddr : 1;
    } reg;
} SOC_CRGPERIPH_PERRSTDIS2_UNION;
#endif
#define SOC_CRGPERIPH_PERRSTDIS2_ip_prst_blpwm1_START (0)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_prst_blpwm1_END (0)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_prst_ipc0_START (2)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_prst_ipc0_END (2)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_prst_ipc1_START (3)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_prst_ipc1_END (3)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_prst_ipc_rtos_START (4)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_prst_ipc_rtos_END (4)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_rst_i2c2_START (6)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_rst_i2c2_END (6)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_rst_i2c3_START (7)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_rst_i2c3_END (7)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_rst_spi1_START (9)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_rst_spi1_END (9)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_prst_uart0_START (10)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_prst_uart0_END (10)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_prst_blpwm4_START (11)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_prst_blpwm4_END (11)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_prst_blpwm3_START (12)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_prst_blpwm3_END (12)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_prst_uart4_START (14)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_prst_uart4_END (14)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_prst_uart5_START (15)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_prst_uart5_END (15)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_prst_uart8_START (16)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_prst_uart8_END (16)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_rst_mdm_drx2dbg_START (21)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_rst_mdm_drx2dbg_END (21)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_rst_gic_START (23)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_rst_gic_END (23)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_rst_codecssi_START (26)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_rst_codecssi_END (26)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_rst_i2c4_START (27)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_rst_i2c4_END (27)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_rst_qdb_sys2mdm_START (28)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_rst_qdb_sys2mdm_END (28)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_rst_qdb_mdm2sys_START (29)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_rst_qdb_mdm2sys_END (29)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_rst_qdb_pdea2ddr_START (30)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_rst_qdb_pdea2ddr_END (30)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_rst_qdb_mdm2ddr_START (31)
#define SOC_CRGPERIPH_PERRSTDIS2_ip_rst_qdb_mdm2ddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_prst_blpwm1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_prst_ipc0 : 1;
        unsigned int ip_prst_ipc1 : 1;
        unsigned int ip_prst_ipc_rtos : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_rst_i2c2 : 1;
        unsigned int ip_rst_i2c3 : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_spi1 : 1;
        unsigned int ip_prst_uart0 : 1;
        unsigned int ip_prst_blpwm4 : 1;
        unsigned int ip_prst_blpwm3 : 1;
        unsigned int reserved_3 : 1;
        unsigned int ip_prst_uart4 : 1;
        unsigned int ip_prst_uart5 : 1;
        unsigned int ip_prst_uart8 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int ip_rst_mdm_drx2dbg : 1;
        unsigned int reserved_8 : 1;
        unsigned int ip_rst_gic : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int ip_rst_codecssi : 1;
        unsigned int ip_rst_i2c4 : 1;
        unsigned int ip_rst_qdb_sys2mdm : 1;
        unsigned int ip_rst_qdb_mdm2sys : 1;
        unsigned int ip_rst_qdb_pdea2ddr : 1;
        unsigned int ip_rst_qdb_mdm2ddr : 1;
    } reg;
} SOC_CRGPERIPH_PERRSTSTAT2_UNION;
#endif
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_prst_blpwm1_START (0)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_prst_blpwm1_END (0)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_prst_ipc0_START (2)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_prst_ipc0_END (2)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_prst_ipc1_START (3)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_prst_ipc1_END (3)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_prst_ipc_rtos_START (4)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_prst_ipc_rtos_END (4)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_rst_i2c2_START (6)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_rst_i2c2_END (6)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_rst_i2c3_START (7)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_rst_i2c3_END (7)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_rst_spi1_START (9)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_rst_spi1_END (9)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_prst_uart0_START (10)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_prst_uart0_END (10)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_prst_blpwm4_START (11)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_prst_blpwm4_END (11)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_prst_blpwm3_START (12)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_prst_blpwm3_END (12)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_prst_uart4_START (14)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_prst_uart4_END (14)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_prst_uart5_START (15)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_prst_uart5_END (15)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_prst_uart8_START (16)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_prst_uart8_END (16)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_rst_mdm_drx2dbg_START (21)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_rst_mdm_drx2dbg_END (21)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_rst_gic_START (23)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_rst_gic_END (23)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_rst_codecssi_START (26)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_rst_codecssi_END (26)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_rst_i2c4_START (27)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_rst_i2c4_END (27)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_rst_qdb_sys2mdm_START (28)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_rst_qdb_sys2mdm_END (28)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_rst_qdb_mdm2sys_START (29)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_rst_qdb_mdm2sys_END (29)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_rst_qdb_pdea2ddr_START (30)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_rst_qdb_pdea2ddr_END (30)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_rst_qdb_mdm2ddr_START (31)
#define SOC_CRGPERIPH_PERRSTSTAT2_ip_rst_qdb_mdm2ddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_arst_dmac : 1;
        unsigned int ip_prst_loadmonitor : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int ip_prst_loadmonitor_1 : 1;
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
        unsigned int ip_rst_perihpm : 1;
        unsigned int ip_rst_aohpm : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
    } reg;
} SOC_CRGPERIPH_PERRSTEN3_UNION;
#endif
#define SOC_CRGPERIPH_PERRSTEN3_ip_arst_dmac_START (0)
#define SOC_CRGPERIPH_PERRSTEN3_ip_arst_dmac_END (0)
#define SOC_CRGPERIPH_PERRSTEN3_ip_prst_loadmonitor_START (1)
#define SOC_CRGPERIPH_PERRSTEN3_ip_prst_loadmonitor_END (1)
#define SOC_CRGPERIPH_PERRSTEN3_ip_prst_loadmonitor_1_START (6)
#define SOC_CRGPERIPH_PERRSTEN3_ip_prst_loadmonitor_1_END (6)
#define SOC_CRGPERIPH_PERRSTEN3_ip_rst_perihpm_START (23)
#define SOC_CRGPERIPH_PERRSTEN3_ip_rst_perihpm_END (23)
#define SOC_CRGPERIPH_PERRSTEN3_ip_rst_aohpm_START (24)
#define SOC_CRGPERIPH_PERRSTEN3_ip_rst_aohpm_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_arst_dmac : 1;
        unsigned int ip_prst_loadmonitor : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int ip_prst_loadmonitor_1 : 1;
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
        unsigned int ip_rst_perihpm : 1;
        unsigned int ip_rst_aohpm : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
    } reg;
} SOC_CRGPERIPH_PERRSTDIS3_UNION;
#endif
#define SOC_CRGPERIPH_PERRSTDIS3_ip_arst_dmac_START (0)
#define SOC_CRGPERIPH_PERRSTDIS3_ip_arst_dmac_END (0)
#define SOC_CRGPERIPH_PERRSTDIS3_ip_prst_loadmonitor_START (1)
#define SOC_CRGPERIPH_PERRSTDIS3_ip_prst_loadmonitor_END (1)
#define SOC_CRGPERIPH_PERRSTDIS3_ip_prst_loadmonitor_1_START (6)
#define SOC_CRGPERIPH_PERRSTDIS3_ip_prst_loadmonitor_1_END (6)
#define SOC_CRGPERIPH_PERRSTDIS3_ip_rst_perihpm_START (23)
#define SOC_CRGPERIPH_PERRSTDIS3_ip_rst_perihpm_END (23)
#define SOC_CRGPERIPH_PERRSTDIS3_ip_rst_aohpm_START (24)
#define SOC_CRGPERIPH_PERRSTDIS3_ip_rst_aohpm_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_arst_dmac : 1;
        unsigned int ip_prst_loadmonitor : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int ip_prst_loadmonitor_1 : 1;
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
        unsigned int ip_rst_perihpm : 1;
        unsigned int ip_rst_aohpm : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
    } reg;
} SOC_CRGPERIPH_PERRSTSTAT3_UNION;
#endif
#define SOC_CRGPERIPH_PERRSTSTAT3_ip_arst_dmac_START (0)
#define SOC_CRGPERIPH_PERRSTSTAT3_ip_arst_dmac_END (0)
#define SOC_CRGPERIPH_PERRSTSTAT3_ip_prst_loadmonitor_START (1)
#define SOC_CRGPERIPH_PERRSTSTAT3_ip_prst_loadmonitor_END (1)
#define SOC_CRGPERIPH_PERRSTSTAT3_ip_prst_loadmonitor_1_START (6)
#define SOC_CRGPERIPH_PERRSTSTAT3_ip_prst_loadmonitor_1_END (6)
#define SOC_CRGPERIPH_PERRSTSTAT3_ip_rst_perihpm_START (23)
#define SOC_CRGPERIPH_PERRSTSTAT3_ip_rst_perihpm_END (23)
#define SOC_CRGPERIPH_PERRSTSTAT3_ip_rst_aohpm_START (24)
#define SOC_CRGPERIPH_PERRSTSTAT3_ip_rst_aohpm_END (24)
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
        unsigned int ip_prst_atgc : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int ip_prst_atgs_sys : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
        unsigned int ip_rst_i3c4 : 1;
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
        unsigned int reserved_27 : 1;
        unsigned int reserved_28 : 1;
    } reg;
} SOC_CRGPERIPH_PERRSTEN4_UNION;
#endif
#define SOC_CRGPERIPH_PERRSTEN4_ip_prst_atgc_START (11)
#define SOC_CRGPERIPH_PERRSTEN4_ip_prst_atgc_END (11)
#define SOC_CRGPERIPH_PERRSTEN4_ip_prst_atgs_sys_START (19)
#define SOC_CRGPERIPH_PERRSTEN4_ip_prst_atgs_sys_END (19)
#define SOC_CRGPERIPH_PERRSTEN4_ip_rst_i3c4_START (24)
#define SOC_CRGPERIPH_PERRSTEN4_ip_rst_i3c4_END (24)
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
        unsigned int ip_prst_atgc : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int ip_prst_atgs_sys : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
        unsigned int ip_rst_i3c4 : 1;
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
        unsigned int reserved_27 : 1;
        unsigned int reserved_28 : 1;
    } reg;
} SOC_CRGPERIPH_PERRSTDIS4_UNION;
#endif
#define SOC_CRGPERIPH_PERRSTDIS4_ip_prst_atgc_START (11)
#define SOC_CRGPERIPH_PERRSTDIS4_ip_prst_atgc_END (11)
#define SOC_CRGPERIPH_PERRSTDIS4_ip_prst_atgs_sys_START (19)
#define SOC_CRGPERIPH_PERRSTDIS4_ip_prst_atgs_sys_END (19)
#define SOC_CRGPERIPH_PERRSTDIS4_ip_rst_i3c4_START (24)
#define SOC_CRGPERIPH_PERRSTDIS4_ip_rst_i3c4_END (24)
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
        unsigned int ip_prst_atgc : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int ip_prst_atgs_sys : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
        unsigned int ip_rst_i3c4 : 1;
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
        unsigned int reserved_27 : 1;
        unsigned int reserved_28 : 1;
    } reg;
} SOC_CRGPERIPH_PERRSTSTAT4_UNION;
#endif
#define SOC_CRGPERIPH_PERRSTSTAT4_ip_prst_atgc_START (11)
#define SOC_CRGPERIPH_PERRSTSTAT4_ip_prst_atgc_END (11)
#define SOC_CRGPERIPH_PERRSTSTAT4_ip_prst_atgs_sys_START (19)
#define SOC_CRGPERIPH_PERRSTSTAT4_ip_prst_atgs_sys_END (19)
#define SOC_CRGPERIPH_PERRSTSTAT4_ip_rst_i3c4_START (24)
#define SOC_CRGPERIPH_PERRSTSTAT4_ip_rst_i3c4_END (24)
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
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int ip_rst_pll_unlock_detect : 1;
        unsigned int ip_rst_csi_crg : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int ip_rst_process_monitor_gpu : 1;
        unsigned int ip_rst_process_monitor_npu : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
        unsigned int reserved_27 : 1;
    } reg;
} SOC_CRGPERIPH_PERRSTEN5_UNION;
#endif
#define SOC_CRGPERIPH_PERRSTEN5_ip_rst_pll_unlock_detect_START (16)
#define SOC_CRGPERIPH_PERRSTEN5_ip_rst_pll_unlock_detect_END (16)
#define SOC_CRGPERIPH_PERRSTEN5_ip_rst_csi_crg_START (17)
#define SOC_CRGPERIPH_PERRSTEN5_ip_rst_csi_crg_END (17)
#define SOC_CRGPERIPH_PERRSTEN5_ip_rst_process_monitor_gpu_START (22)
#define SOC_CRGPERIPH_PERRSTEN5_ip_rst_process_monitor_gpu_END (22)
#define SOC_CRGPERIPH_PERRSTEN5_ip_rst_process_monitor_npu_START (23)
#define SOC_CRGPERIPH_PERRSTEN5_ip_rst_process_monitor_npu_END (23)
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
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int ip_rst_pll_unlock_detect : 1;
        unsigned int ip_rst_csi_crg : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int ip_rst_process_monitor_gpu : 1;
        unsigned int ip_rst_process_monitor_npu : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
        unsigned int reserved_27 : 1;
    } reg;
} SOC_CRGPERIPH_PERRSTDIS5_UNION;
#endif
#define SOC_CRGPERIPH_PERRSTDIS5_ip_rst_pll_unlock_detect_START (16)
#define SOC_CRGPERIPH_PERRSTDIS5_ip_rst_pll_unlock_detect_END (16)
#define SOC_CRGPERIPH_PERRSTDIS5_ip_rst_csi_crg_START (17)
#define SOC_CRGPERIPH_PERRSTDIS5_ip_rst_csi_crg_END (17)
#define SOC_CRGPERIPH_PERRSTDIS5_ip_rst_process_monitor_gpu_START (22)
#define SOC_CRGPERIPH_PERRSTDIS5_ip_rst_process_monitor_gpu_END (22)
#define SOC_CRGPERIPH_PERRSTDIS5_ip_rst_process_monitor_npu_START (23)
#define SOC_CRGPERIPH_PERRSTDIS5_ip_rst_process_monitor_npu_END (23)
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
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int ip_rst_pll_unlock_detect : 1;
        unsigned int ip_rst_csi_crg : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int ip_rst_process_monitor_gpu : 1;
        unsigned int ip_rst_process_monitor_npu : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
        unsigned int reserved_24 : 1;
        unsigned int reserved_25 : 1;
        unsigned int reserved_26 : 1;
        unsigned int reserved_27 : 1;
    } reg;
} SOC_CRGPERIPH_PERRSTSTAT5_UNION;
#endif
#define SOC_CRGPERIPH_PERRSTSTAT5_ip_rst_pll_unlock_detect_START (16)
#define SOC_CRGPERIPH_PERRSTSTAT5_ip_rst_pll_unlock_detect_END (16)
#define SOC_CRGPERIPH_PERRSTSTAT5_ip_rst_csi_crg_START (17)
#define SOC_CRGPERIPH_PERRSTSTAT5_ip_rst_csi_crg_END (17)
#define SOC_CRGPERIPH_PERRSTSTAT5_ip_rst_process_monitor_gpu_START (22)
#define SOC_CRGPERIPH_PERRSTSTAT5_ip_rst_process_monitor_gpu_END (22)
#define SOC_CRGPERIPH_PERRSTSTAT5_ip_rst_process_monitor_npu_START (23)
#define SOC_CRGPERIPH_PERRSTSTAT5_ip_rst_process_monitor_npu_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_ufs_dfa_cpu : 6;
        unsigned int div_ufs_dfa_sys : 6;
        unsigned int reserved : 2;
        unsigned int sel_clk_out1 : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV0_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV0_div_ufs_dfa_cpu_START (0)
#define SOC_CRGPERIPH_CLKDIV0_div_ufs_dfa_cpu_END (5)
#define SOC_CRGPERIPH_CLKDIV0_div_ufs_dfa_sys_START (6)
#define SOC_CRGPERIPH_CLKDIV0_div_ufs_dfa_sys_END (11)
#define SOC_CRGPERIPH_CLKDIV0_sel_clk_out1_START (14)
#define SOC_CRGPERIPH_CLKDIV0_sel_clk_out1_END (15)
#define SOC_CRGPERIPH_CLKDIV0_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 2;
        unsigned int sel_uart0 : 1;
        unsigned int sel_uartl : 1;
        unsigned int sel_uarth : 1;
        unsigned int sel_uart8 : 1;
        unsigned int reserved_1 : 1;
        unsigned int sel_codeccssi_sys_src : 1;
        unsigned int sel_spi : 1;
        unsigned int div_ufs_subsys_hsdt1 : 4;
        unsigned int sel_i2c : 1;
        unsigned int sel_ufs_subsys_hsdt1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV1_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV1_sel_uart0_START (2)
#define SOC_CRGPERIPH_CLKDIV1_sel_uart0_END (2)
#define SOC_CRGPERIPH_CLKDIV1_sel_uartl_START (3)
#define SOC_CRGPERIPH_CLKDIV1_sel_uartl_END (3)
#define SOC_CRGPERIPH_CLKDIV1_sel_uarth_START (4)
#define SOC_CRGPERIPH_CLKDIV1_sel_uarth_END (4)
#define SOC_CRGPERIPH_CLKDIV1_sel_uart8_START (5)
#define SOC_CRGPERIPH_CLKDIV1_sel_uart8_END (5)
#define SOC_CRGPERIPH_CLKDIV1_sel_codeccssi_sys_src_START (7)
#define SOC_CRGPERIPH_CLKDIV1_sel_codeccssi_sys_src_END (7)
#define SOC_CRGPERIPH_CLKDIV1_sel_spi_START (8)
#define SOC_CRGPERIPH_CLKDIV1_sel_spi_END (8)
#define SOC_CRGPERIPH_CLKDIV1_div_ufs_subsys_hsdt1_START (9)
#define SOC_CRGPERIPH_CLKDIV1_div_ufs_subsys_hsdt1_END (12)
#define SOC_CRGPERIPH_CLKDIV1_sel_i2c_START (13)
#define SOC_CRGPERIPH_CLKDIV1_sel_i2c_END (13)
#define SOC_CRGPERIPH_CLKDIV1_sel_ufs_subsys_hsdt1_START (14)
#define SOC_CRGPERIPH_CLKDIV1_sel_ufs_subsys_hsdt1_END (14)
#define SOC_CRGPERIPH_CLKDIV1_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV1_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_uart8 : 4;
        unsigned int div_uart0 : 4;
        unsigned int div_uartl : 4;
        unsigned int div_uarth : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV2_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV2_div_uart8_START (0)
#define SOC_CRGPERIPH_CLKDIV2_div_uart8_END (3)
#define SOC_CRGPERIPH_CLKDIV2_div_uart0_START (4)
#define SOC_CRGPERIPH_CLKDIV2_div_uart0_END (7)
#define SOC_CRGPERIPH_CLKDIV2_div_uartl_START (8)
#define SOC_CRGPERIPH_CLKDIV2_div_uartl_END (11)
#define SOC_CRGPERIPH_CLKDIV2_div_uarth_START (12)
#define SOC_CRGPERIPH_CLKDIV2_div_uarth_END (15)
#define SOC_CRGPERIPH_CLKDIV2_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV2_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 6;
        unsigned int div_dpctrl_16m : 6;
        unsigned int sel_dpctrl_16m : 1;
        unsigned int reserved_1 : 3;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV3_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV3_div_dpctrl_16m_START (6)
#define SOC_CRGPERIPH_CLKDIV3_div_dpctrl_16m_END (11)
#define SOC_CRGPERIPH_CLKDIV3_sel_dpctrl_16m_START (12)
#define SOC_CRGPERIPH_CLKDIV3_sel_dpctrl_16m_END (12)
#define SOC_CRGPERIPH_CLKDIV3_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV3_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_clkout1_tcxo : 4;
        unsigned int div_time_stamp : 3;
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 3;
        unsigned int div_loadmonitor : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV4_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV4_div_clkout1_tcxo_START (0)
#define SOC_CRGPERIPH_CLKDIV4_div_clkout1_tcxo_END (3)
#define SOC_CRGPERIPH_CLKDIV4_div_time_stamp_START (4)
#define SOC_CRGPERIPH_CLKDIV4_div_time_stamp_END (6)
#define SOC_CRGPERIPH_CLKDIV4_div_loadmonitor_START (14)
#define SOC_CRGPERIPH_CLKDIV4_div_loadmonitor_END (15)
#define SOC_CRGPERIPH_CLKDIV4_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV4_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 4;
        unsigned int sel_ufs_dfa_sys : 2;
        unsigned int sel_ufs_dfa_cpu : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV5_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV5_sel_ufs_dfa_sys_START (10)
#define SOC_CRGPERIPH_CLKDIV5_sel_ufs_dfa_sys_END (11)
#define SOC_CRGPERIPH_CLKDIV5_sel_ufs_dfa_cpu_START (12)
#define SOC_CRGPERIPH_CLKDIV5_sel_ufs_dfa_cpu_END (15)
#define SOC_CRGPERIPH_CLKDIV5_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV5_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 2;
        unsigned int div_dpctrl_pixel : 6;
        unsigned int sel_dpctrl_pixel : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV6_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV6_div_dpctrl_pixel_START (8)
#define SOC_CRGPERIPH_CLKDIV6_div_dpctrl_pixel_END (13)
#define SOC_CRGPERIPH_CLKDIV6_sel_dpctrl_pixel_START (14)
#define SOC_CRGPERIPH_CLKDIV6_sel_dpctrl_pixel_END (15)
#define SOC_CRGPERIPH_CLKDIV6_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV6_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_onewire : 4;
        unsigned int sc_gt_clk_onewire : 1;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 4;
        unsigned int div_spi : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV7_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV7_div_onewire_START (0)
#define SOC_CRGPERIPH_CLKDIV7_div_onewire_END (3)
#define SOC_CRGPERIPH_CLKDIV7_sc_gt_clk_onewire_START (4)
#define SOC_CRGPERIPH_CLKDIV7_sc_gt_clk_onewire_END (4)
#define SOC_CRGPERIPH_CLKDIV7_div_spi_START (12)
#define SOC_CRGPERIPH_CLKDIV7_div_spi_END (15)
#define SOC_CRGPERIPH_CLKDIV7_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV7_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 3;
        unsigned int sel_clk_fcg_tp_out : 1;
        unsigned int div_clk_gpu_tp : 6;
        unsigned int sc_gt_clk_gpu_tp_mux : 1;
        unsigned int reserved_2 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV8_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV8_sel_clk_fcg_tp_out_START (7)
#define SOC_CRGPERIPH_CLKDIV8_sel_clk_fcg_tp_out_END (7)
#define SOC_CRGPERIPH_CLKDIV8_div_clk_gpu_tp_START (8)
#define SOC_CRGPERIPH_CLKDIV8_div_clk_gpu_tp_END (13)
#define SOC_CRGPERIPH_CLKDIV8_sc_gt_clk_gpu_tp_mux_START (14)
#define SOC_CRGPERIPH_CLKDIV8_sc_gt_clk_gpu_tp_mux_END (14)
#define SOC_CRGPERIPH_CLKDIV8_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV8_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 4;
        unsigned int reserved_3 : 1;
        unsigned int sel_clk_out1_core : 2;
        unsigned int reserved_4 : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV9_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV9_sel_clk_out1_core_START (10)
#define SOC_CRGPERIPH_CLKDIV9_sel_clk_out1_core_END (11)
#define SOC_CRGPERIPH_CLKDIV9_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV9_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 5;
        unsigned int reserved_2 : 4;
        unsigned int reserved_3 : 1;
        unsigned int div_perf_stat : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV10_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV10_div_perf_stat_START (12)
#define SOC_CRGPERIPH_CLKDIV10_div_perf_stat_END (15)
#define SOC_CRGPERIPH_CLKDIV10_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV10_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 3;
        unsigned int reserved_3 : 1;
        unsigned int sel_a53hpm_pll : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV11_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV11_sel_a53hpm_pll_START (9)
#define SOC_CRGPERIPH_CLKDIV11_sel_a53hpm_pll_END (9)
#define SOC_CRGPERIPH_CLKDIV11_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV11_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_ptp : 4;
        unsigned int sel_clk_pll_test_src : 4;
        unsigned int div_pll_src_tp : 5;
        unsigned int reserved : 3;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV12_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV12_div_ptp_START (0)
#define SOC_CRGPERIPH_CLKDIV12_div_ptp_END (3)
#define SOC_CRGPERIPH_CLKDIV12_sel_clk_pll_test_src_START (4)
#define SOC_CRGPERIPH_CLKDIV12_sel_clk_pll_test_src_END (7)
#define SOC_CRGPERIPH_CLKDIV12_div_pll_src_tp_START (8)
#define SOC_CRGPERIPH_CLKDIV12_div_pll_src_tp_END (12)
#define SOC_CRGPERIPH_CLKDIV12_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV12_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_rxdphy_fll : 2;
        unsigned int sel_rxdphy_cfg : 2;
        unsigned int reserved_0 : 10;
        unsigned int reserved_1 : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV13_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV13_div_rxdphy_fll_START (0)
#define SOC_CRGPERIPH_CLKDIV13_div_rxdphy_fll_END (1)
#define SOC_CRGPERIPH_CLKDIV13_sel_rxdphy_cfg_START (2)
#define SOC_CRGPERIPH_CLKDIV13_sel_rxdphy_cfg_END (3)
#define SOC_CRGPERIPH_CLKDIV13_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV13_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_process_monitor : 4;
        unsigned int div_clkout1_pll : 6;
        unsigned int div_a53hpm : 6;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV14_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV14_div_process_monitor_START (0)
#define SOC_CRGPERIPH_CLKDIV14_div_process_monitor_END (3)
#define SOC_CRGPERIPH_CLKDIV14_div_clkout1_pll_START (4)
#define SOC_CRGPERIPH_CLKDIV14_div_clkout1_pll_END (9)
#define SOC_CRGPERIPH_CLKDIV14_div_a53hpm_START (10)
#define SOC_CRGPERIPH_CLKDIV14_div_a53hpm_END (15)
#define SOC_CRGPERIPH_CLKDIV14_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV14_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 4;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 4;
        unsigned int reserved_3: 6;
        unsigned int reserved_4: 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV15_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV15_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV15_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 4;
        unsigned int div_i2c : 4;
        unsigned int reserved_1: 4;
        unsigned int reserved_2: 2;
        unsigned int reserved_3: 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV16_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV16_div_i2c_START (4)
#define SOC_CRGPERIPH_CLKDIV16_div_i2c_END (7)
#define SOC_CRGPERIPH_CLKDIV16_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV16_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_power_stat : 6;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 6;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV17_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV17_div_power_stat_START (0)
#define SOC_CRGPERIPH_CLKDIV17_div_power_stat_END (5)
#define SOC_CRGPERIPH_CLKDIV17_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV17_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_gt_clk_dpctrl_pixel : 1;
        unsigned int sc_gt_clk_time_stamp_div : 1;
        unsigned int reserved_0 : 1;
        unsigned int sc_gt_clk_perf_stat_div : 1;
        unsigned int sc_gt_clk_power_stat : 1;
        unsigned int sc_gt_clk_loadmonitor : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int sc_gt_clk_out1 : 1;
        unsigned int reserved_5 : 1;
        unsigned int sc_gt_clk_ufs_subsys_hsdt1 : 1;
        unsigned int reserved_6 : 1;
        unsigned int sc_gt_clk_ufs_dfa_cpu : 1;
        unsigned int sc_gt_clk_ufs_dfa_sys : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV18_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV18_sc_gt_clk_dpctrl_pixel_START (0)
#define SOC_CRGPERIPH_CLKDIV18_sc_gt_clk_dpctrl_pixel_END (0)
#define SOC_CRGPERIPH_CLKDIV18_sc_gt_clk_time_stamp_div_START (1)
#define SOC_CRGPERIPH_CLKDIV18_sc_gt_clk_time_stamp_div_END (1)
#define SOC_CRGPERIPH_CLKDIV18_sc_gt_clk_perf_stat_div_START (3)
#define SOC_CRGPERIPH_CLKDIV18_sc_gt_clk_perf_stat_div_END (3)
#define SOC_CRGPERIPH_CLKDIV18_sc_gt_clk_power_stat_START (4)
#define SOC_CRGPERIPH_CLKDIV18_sc_gt_clk_power_stat_END (4)
#define SOC_CRGPERIPH_CLKDIV18_sc_gt_clk_loadmonitor_START (5)
#define SOC_CRGPERIPH_CLKDIV18_sc_gt_clk_loadmonitor_END (5)
#define SOC_CRGPERIPH_CLKDIV18_sc_gt_clk_out1_START (10)
#define SOC_CRGPERIPH_CLKDIV18_sc_gt_clk_out1_END (10)
#define SOC_CRGPERIPH_CLKDIV18_sc_gt_clk_ufs_subsys_hsdt1_START (12)
#define SOC_CRGPERIPH_CLKDIV18_sc_gt_clk_ufs_subsys_hsdt1_END (12)
#define SOC_CRGPERIPH_CLKDIV18_sc_gt_clk_ufs_dfa_cpu_START (14)
#define SOC_CRGPERIPH_CLKDIV18_sc_gt_clk_ufs_dfa_cpu_END (14)
#define SOC_CRGPERIPH_CLKDIV18_sc_gt_clk_ufs_dfa_sys_START (15)
#define SOC_CRGPERIPH_CLKDIV18_sc_gt_clk_ufs_dfa_sys_END (15)
#define SOC_CRGPERIPH_CLKDIV18_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV18_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int sc_gt_clk_ao_asp_pll : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int sc_gt_clk_a53hpm : 1;
        unsigned int sc_gt_clk_uart8 : 1;
        unsigned int sc_gt_clk_uart0 : 1;
        unsigned int sc_gt_clk_uartl : 1;
        unsigned int sc_gt_clk_uarth : 1;
        unsigned int reserved_6 : 1;
        unsigned int sc_gt_clk_spi : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV19_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV19_sc_gt_clk_ao_asp_pll_START (4)
#define SOC_CRGPERIPH_CLKDIV19_sc_gt_clk_ao_asp_pll_END (4)
#define SOC_CRGPERIPH_CLKDIV19_sc_gt_clk_a53hpm_START (7)
#define SOC_CRGPERIPH_CLKDIV19_sc_gt_clk_a53hpm_END (7)
#define SOC_CRGPERIPH_CLKDIV19_sc_gt_clk_uart8_START (8)
#define SOC_CRGPERIPH_CLKDIV19_sc_gt_clk_uart8_END (8)
#define SOC_CRGPERIPH_CLKDIV19_sc_gt_clk_uart0_START (9)
#define SOC_CRGPERIPH_CLKDIV19_sc_gt_clk_uart0_END (9)
#define SOC_CRGPERIPH_CLKDIV19_sc_gt_clk_uartl_START (10)
#define SOC_CRGPERIPH_CLKDIV19_sc_gt_clk_uartl_END (10)
#define SOC_CRGPERIPH_CLKDIV19_sc_gt_clk_uarth_START (11)
#define SOC_CRGPERIPH_CLKDIV19_sc_gt_clk_uarth_END (11)
#define SOC_CRGPERIPH_CLKDIV19_sc_gt_clk_spi_START (13)
#define SOC_CRGPERIPH_CLKDIV19_sc_gt_clk_spi_END (13)
#define SOC_CRGPERIPH_CLKDIV19_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV19_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_gt_clk_i2c : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int sc_gt_clk_ptp : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int sc_gt_clk_320m_pll : 1;
        unsigned int sc_gt_clk_pll_test_src : 1;
        unsigned int sc_gt_clk_atgc : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV20_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV20_sc_gt_clk_i2c_START (0)
#define SOC_CRGPERIPH_CLKDIV20_sc_gt_clk_i2c_END (0)
#define SOC_CRGPERIPH_CLKDIV20_sc_gt_clk_ptp_START (5)
#define SOC_CRGPERIPH_CLKDIV20_sc_gt_clk_ptp_END (5)
#define SOC_CRGPERIPH_CLKDIV20_sc_gt_clk_320m_pll_START (10)
#define SOC_CRGPERIPH_CLKDIV20_sc_gt_clk_320m_pll_END (10)
#define SOC_CRGPERIPH_CLKDIV20_sc_gt_clk_pll_test_src_START (11)
#define SOC_CRGPERIPH_CLKDIV20_sc_gt_clk_pll_test_src_END (11)
#define SOC_CRGPERIPH_CLKDIV20_sc_gt_clk_atgc_START (12)
#define SOC_CRGPERIPH_CLKDIV20_sc_gt_clk_atgc_END (12)
#define SOC_CRGPERIPH_CLKDIV20_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV20_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_gt_clk_usb1_mcu : 1;
        unsigned int sc_gt_clk_usb1_arb : 1;
        unsigned int usb1_arb_clk_sw_req_cfg : 1;
        unsigned int sc_gt_clk_usb1_arb_fll : 1;
        unsigned int div_usb1_arb_fll : 5;
        unsigned int reserved_0 : 1;
        unsigned int sc_gt_clk_rxdphy_fll : 1;
        unsigned int reserved_1 : 1;
        unsigned int sc_gt_clk_dpctrl_16m : 1;
        unsigned int sc_gt_clk_process_monitor : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV21_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV21_sc_gt_clk_usb1_mcu_START (0)
#define SOC_CRGPERIPH_CLKDIV21_sc_gt_clk_usb1_mcu_END (0)
#define SOC_CRGPERIPH_CLKDIV21_sc_gt_clk_usb1_arb_START (1)
#define SOC_CRGPERIPH_CLKDIV21_sc_gt_clk_usb1_arb_END (1)
#define SOC_CRGPERIPH_CLKDIV21_usb1_arb_clk_sw_req_cfg_START (2)
#define SOC_CRGPERIPH_CLKDIV21_usb1_arb_clk_sw_req_cfg_END (2)
#define SOC_CRGPERIPH_CLKDIV21_sc_gt_clk_usb1_arb_fll_START (3)
#define SOC_CRGPERIPH_CLKDIV21_sc_gt_clk_usb1_arb_fll_END (3)
#define SOC_CRGPERIPH_CLKDIV21_div_usb1_arb_fll_START (4)
#define SOC_CRGPERIPH_CLKDIV21_div_usb1_arb_fll_END (8)
#define SOC_CRGPERIPH_CLKDIV21_sc_gt_clk_rxdphy_fll_START (10)
#define SOC_CRGPERIPH_CLKDIV21_sc_gt_clk_rxdphy_fll_END (10)
#define SOC_CRGPERIPH_CLKDIV21_sc_gt_clk_dpctrl_16m_START (12)
#define SOC_CRGPERIPH_CLKDIV21_sc_gt_clk_dpctrl_16m_END (12)
#define SOC_CRGPERIPH_CLKDIV21_sc_gt_clk_process_monitor_START (13)
#define SOC_CRGPERIPH_CLKDIV21_sc_gt_clk_process_monitor_END (13)
#define SOC_CRGPERIPH_CLKDIV21_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV21_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int div_320m : 3;
        unsigned int sel_ao_asp_pll : 2;
        unsigned int div_usb1_mcu : 4;
        unsigned int sel_usb1_arb : 1;
        unsigned int div_usb1_arb : 5;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV22_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV22_div_320m_START (1)
#define SOC_CRGPERIPH_CLKDIV22_div_320m_END (3)
#define SOC_CRGPERIPH_CLKDIV22_sel_ao_asp_pll_START (4)
#define SOC_CRGPERIPH_CLKDIV22_sel_ao_asp_pll_END (5)
#define SOC_CRGPERIPH_CLKDIV22_div_usb1_mcu_START (6)
#define SOC_CRGPERIPH_CLKDIV22_div_usb1_mcu_END (9)
#define SOC_CRGPERIPH_CLKDIV22_sel_usb1_arb_START (10)
#define SOC_CRGPERIPH_CLKDIV22_sel_usb1_arb_END (10)
#define SOC_CRGPERIPH_CLKDIV22_div_usb1_arb_START (11)
#define SOC_CRGPERIPH_CLKDIV22_div_usb1_arb_END (15)
#define SOC_CRGPERIPH_CLKDIV22_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV22_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_gt_mdmperi_dpa : 1;
        unsigned int sc_gt_mdmperi_sne : 1;
        unsigned int sc_gt_mdmperi_100m : 1;
        unsigned int div_mdmperi_100m : 6;
        unsigned int div_mdmperi_dpa : 4;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV23_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV23_sc_gt_mdmperi_dpa_START (0)
#define SOC_CRGPERIPH_CLKDIV23_sc_gt_mdmperi_dpa_END (0)
#define SOC_CRGPERIPH_CLKDIV23_sc_gt_mdmperi_sne_START (1)
#define SOC_CRGPERIPH_CLKDIV23_sc_gt_mdmperi_sne_END (1)
#define SOC_CRGPERIPH_CLKDIV23_sc_gt_mdmperi_100m_START (2)
#define SOC_CRGPERIPH_CLKDIV23_sc_gt_mdmperi_100m_END (2)
#define SOC_CRGPERIPH_CLKDIV23_div_mdmperi_100m_START (3)
#define SOC_CRGPERIPH_CLKDIV23_div_mdmperi_100m_END (8)
#define SOC_CRGPERIPH_CLKDIV23_div_mdmperi_dpa_START (9)
#define SOC_CRGPERIPH_CLKDIV23_div_mdmperi_dpa_END (12)
#define SOC_CRGPERIPH_CLKDIV23_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV23_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_mdmperi_sne : 4;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int div_ao_asp : 4;
        unsigned int sel_mdmperi_dpa : 4;
        unsigned int reserved_2 : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV24_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV24_div_mdmperi_sne_START (0)
#define SOC_CRGPERIPH_CLKDIV24_div_mdmperi_sne_END (3)
#define SOC_CRGPERIPH_CLKDIV24_div_ao_asp_START (6)
#define SOC_CRGPERIPH_CLKDIV24_div_ao_asp_END (9)
#define SOC_CRGPERIPH_CLKDIV24_sel_mdmperi_dpa_START (10)
#define SOC_CRGPERIPH_CLKDIV24_sel_mdmperi_dpa_END (13)
#define SOC_CRGPERIPH_CLKDIV24_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV24_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 1;
        unsigned int sel_hsdt1_usbdp : 1;
        unsigned int sel_mdmperi_sne : 4;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 2;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV25_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV25_sel_hsdt1_usbdp_START (5)
#define SOC_CRGPERIPH_CLKDIV25_sel_hsdt1_usbdp_END (5)
#define SOC_CRGPERIPH_CLKDIV25_sel_mdmperi_sne_START (6)
#define SOC_CRGPERIPH_CLKDIV25_sel_mdmperi_sne_END (9)
#define SOC_CRGPERIPH_CLKDIV25_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV25_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bootmode : 1;
        unsigned int reserved_0 : 1;
        unsigned int sc_noc_aobus_idle_flag : 1;
        unsigned int isp_to_ddrc_dfs_en : 1;
        unsigned int reserved_1 : 28;
    } reg;
} SOC_CRGPERIPH_PERI_STAT1_UNION;
#endif
#define SOC_CRGPERIPH_PERI_STAT1_bootmode_START (0)
#define SOC_CRGPERIPH_PERI_STAT1_bootmode_END (0)
#define SOC_CRGPERIPH_PERI_STAT1_sc_noc_aobus_idle_flag_START (2)
#define SOC_CRGPERIPH_PERI_STAT1_sc_noc_aobus_idle_flag_END (2)
#define SOC_CRGPERIPH_PERI_STAT1_isp_to_ddrc_dfs_en_START (3)
#define SOC_CRGPERIPH_PERI_STAT1_isp_to_ddrc_dfs_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int swdone_clk_ddrc_pll_div : 1;
        unsigned int swdone_clk_sysbus_pll_div : 1;
        unsigned int swdone_clk_lpmcu_pll_div : 1;
        unsigned int swdone_clk_cpu_gic_div : 1;
        unsigned int reserved_0 : 1;
        unsigned int swdone_clk_center_crossbar_fll_div : 1;
        unsigned int swdone_clk_periph_cpu_div : 1;
        unsigned int swdone_clk_sys_tsensor_div : 1;
        unsigned int swdone_clk_noc_npubus_div : 1;
        unsigned int swdone_clk_center_crossbar_sys_div : 1;
        unsigned int swdone_clk_gpu_lp_ctrl_div : 1;
        unsigned int swdone_clk_cpu_lp_ctrl_div : 1;
        unsigned int swdone_clk_pim_div : 1;
        unsigned int swdone_clk_dpctrl_16m_div : 1;
        unsigned int swdone_clk_usb1_mcu_div : 1;
        unsigned int swdone_clk_center_crossbar_pll_div : 1;
        unsigned int swdone_clk_tscpu_peri_div : 1;
        unsigned int reserved_1 : 1;
        unsigned int swdone_clk_rxdphy_fll_div : 1;
        unsigned int reserved_2 : 1;
        unsigned int swdone_clk_ddrcssys : 1;
        unsigned int swdone_clk_a53hpm_div : 1;
        unsigned int swdone_clk_dmc_peri_div : 1;
        unsigned int swdone_clk_core_crg_apb_fll_div : 1;
        unsigned int reserved_3 : 1;
        unsigned int swdone_clk_ptp_div : 1;
        unsigned int reserved_4 : 1;
        unsigned int swdone_clk_spi_div : 1;
        unsigned int swdone_clk_i2c_div : 1;
        unsigned int swdone_aclk_g3d_vdm_aft_div : 1;
        unsigned int swdone_clk_fcm_div : 1;
        unsigned int swdone_clk_out1_div : 1;
    } reg;
} SOC_CRGPERIPH_PERI_STAT2_UNION;
#endif
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_ddrc_pll_div_START (0)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_ddrc_pll_div_END (0)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_sysbus_pll_div_START (1)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_sysbus_pll_div_END (1)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_lpmcu_pll_div_START (2)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_lpmcu_pll_div_END (2)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_cpu_gic_div_START (3)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_cpu_gic_div_END (3)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_center_crossbar_fll_div_START (5)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_center_crossbar_fll_div_END (5)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_periph_cpu_div_START (6)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_periph_cpu_div_END (6)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_sys_tsensor_div_START (7)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_sys_tsensor_div_END (7)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_noc_npubus_div_START (8)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_noc_npubus_div_END (8)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_center_crossbar_sys_div_START (9)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_center_crossbar_sys_div_END (9)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_gpu_lp_ctrl_div_START (10)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_gpu_lp_ctrl_div_END (10)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_cpu_lp_ctrl_div_START (11)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_cpu_lp_ctrl_div_END (11)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_pim_div_START (12)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_pim_div_END (12)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_dpctrl_16m_div_START (13)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_dpctrl_16m_div_END (13)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_usb1_mcu_div_START (14)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_usb1_mcu_div_END (14)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_center_crossbar_pll_div_START (15)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_center_crossbar_pll_div_END (15)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_tscpu_peri_div_START (16)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_tscpu_peri_div_END (16)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_rxdphy_fll_div_START (18)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_rxdphy_fll_div_END (18)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_ddrcssys_START (20)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_ddrcssys_END (20)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_a53hpm_div_START (21)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_a53hpm_div_END (21)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_dmc_peri_div_START (22)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_dmc_peri_div_END (22)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_core_crg_apb_fll_div_START (23)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_core_crg_apb_fll_div_END (23)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_ptp_div_START (25)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_ptp_div_END (25)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_spi_div_START (27)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_spi_div_END (27)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_i2c_div_START (28)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_i2c_div_END (28)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_aclk_g3d_vdm_aft_div_START (29)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_aclk_g3d_vdm_aft_div_END (29)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_fcm_div_START (30)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_fcm_div_END (30)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_out1_div_START (31)
#define SOC_CRGPERIPH_PERI_STAT2_swdone_clk_out1_div_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sw_ack_clk_center_crossbar_fll_sw : 2;
        unsigned int sw_ack_clk_center_crossbar_sw : 3;
        unsigned int sw_ack_atclk_cpu_lit_from_top_sw : 2;
        unsigned int sw_ack_atclk_cpu_hc_from_top_sw : 2;
        unsigned int sw_ack_clk_lpmcu_ini : 3;
        unsigned int sw_ack_clk_ddrc_pll_sw : 4;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int swdone_clk_gpu_ppll0_div : 1;
        unsigned int swdone_clk_cpum_ppll0_div : 1;
        unsigned int swdone_clk_power_stat_div : 1;
        unsigned int swdone_clk_dpctrl_pixel_div : 1;
        unsigned int swdone_clk_cpul_ppll0_div : 1;
        unsigned int swdone_clk_ocr_acpu_div : 1;
        unsigned int sw_ack_clk_sysbus_sw : 3;
        unsigned int sw_ack_clk_ddrc_sw : 3;
        unsigned int sw_ack_clk_center_crossbar_pll_sw : 2;
    } reg;
} SOC_CRGPERIPH_PERI_STAT3_UNION;
#endif
#define SOC_CRGPERIPH_PERI_STAT3_sw_ack_clk_center_crossbar_fll_sw_START (0)
#define SOC_CRGPERIPH_PERI_STAT3_sw_ack_clk_center_crossbar_fll_sw_END (1)
#define SOC_CRGPERIPH_PERI_STAT3_sw_ack_clk_center_crossbar_sw_START (2)
#define SOC_CRGPERIPH_PERI_STAT3_sw_ack_clk_center_crossbar_sw_END (4)
#define SOC_CRGPERIPH_PERI_STAT3_sw_ack_atclk_cpu_lit_from_top_sw_START (5)
#define SOC_CRGPERIPH_PERI_STAT3_sw_ack_atclk_cpu_lit_from_top_sw_END (6)
#define SOC_CRGPERIPH_PERI_STAT3_sw_ack_atclk_cpu_hc_from_top_sw_START (7)
#define SOC_CRGPERIPH_PERI_STAT3_sw_ack_atclk_cpu_hc_from_top_sw_END (8)
#define SOC_CRGPERIPH_PERI_STAT3_sw_ack_clk_lpmcu_ini_START (9)
#define SOC_CRGPERIPH_PERI_STAT3_sw_ack_clk_lpmcu_ini_END (11)
#define SOC_CRGPERIPH_PERI_STAT3_sw_ack_clk_ddrc_pll_sw_START (12)
#define SOC_CRGPERIPH_PERI_STAT3_sw_ack_clk_ddrc_pll_sw_END (15)
#define SOC_CRGPERIPH_PERI_STAT3_swdone_clk_gpu_ppll0_div_START (18)
#define SOC_CRGPERIPH_PERI_STAT3_swdone_clk_gpu_ppll0_div_END (18)
#define SOC_CRGPERIPH_PERI_STAT3_swdone_clk_cpum_ppll0_div_START (19)
#define SOC_CRGPERIPH_PERI_STAT3_swdone_clk_cpum_ppll0_div_END (19)
#define SOC_CRGPERIPH_PERI_STAT3_swdone_clk_power_stat_div_START (20)
#define SOC_CRGPERIPH_PERI_STAT3_swdone_clk_power_stat_div_END (20)
#define SOC_CRGPERIPH_PERI_STAT3_swdone_clk_dpctrl_pixel_div_START (21)
#define SOC_CRGPERIPH_PERI_STAT3_swdone_clk_dpctrl_pixel_div_END (21)
#define SOC_CRGPERIPH_PERI_STAT3_swdone_clk_cpul_ppll0_div_START (22)
#define SOC_CRGPERIPH_PERI_STAT3_swdone_clk_cpul_ppll0_div_END (22)
#define SOC_CRGPERIPH_PERI_STAT3_swdone_clk_ocr_acpu_div_START (23)
#define SOC_CRGPERIPH_PERI_STAT3_swdone_clk_ocr_acpu_div_END (23)
#define SOC_CRGPERIPH_PERI_STAT3_sw_ack_clk_sysbus_sw_START (24)
#define SOC_CRGPERIPH_PERI_STAT3_sw_ack_clk_sysbus_sw_END (26)
#define SOC_CRGPERIPH_PERI_STAT3_sw_ack_clk_ddrc_sw_START (27)
#define SOC_CRGPERIPH_PERI_STAT3_sw_ack_clk_ddrc_sw_END (29)
#define SOC_CRGPERIPH_PERI_STAT3_sw_ack_clk_center_crossbar_pll_sw_START (30)
#define SOC_CRGPERIPH_PERI_STAT3_sw_ack_clk_center_crossbar_pll_sw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sel_pll_ctrl_tp_peri : 5;
        unsigned int reserved : 11;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PERI_CTRL0_UNION;
#endif
#define SOC_CRGPERIPH_PERI_CTRL0_sel_pll_ctrl_tp_peri_START (0)
#define SOC_CRGPERIPH_PERI_CTRL0_sel_pll_ctrl_tp_peri_END (4)
#define SOC_CRGPERIPH_PERI_CTRL0_bitmasken_START (16)
#define SOC_CRGPERIPH_PERI_CTRL0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_timeout_en : 1;
        unsigned int qic_timeout_en_ib_fcm2sys : 1;
        unsigned int qic_timeout_en_ib_mdm2sys : 1;
        unsigned int qic_timeout_en_ib_media22cfg : 1;
        unsigned int qic_timeout_en_subchip2cfg : 1;
        unsigned int qic_sys2ddrc_timeout_en : 1;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PERI_CTRL3_UNION;
#endif
#define SOC_CRGPERIPH_PERI_CTRL3_qic_timeout_en_START (0)
#define SOC_CRGPERIPH_PERI_CTRL3_qic_timeout_en_END (0)
#define SOC_CRGPERIPH_PERI_CTRL3_qic_timeout_en_ib_fcm2sys_START (1)
#define SOC_CRGPERIPH_PERI_CTRL3_qic_timeout_en_ib_fcm2sys_END (1)
#define SOC_CRGPERIPH_PERI_CTRL3_qic_timeout_en_ib_mdm2sys_START (2)
#define SOC_CRGPERIPH_PERI_CTRL3_qic_timeout_en_ib_mdm2sys_END (2)
#define SOC_CRGPERIPH_PERI_CTRL3_qic_timeout_en_ib_media22cfg_START (3)
#define SOC_CRGPERIPH_PERI_CTRL3_qic_timeout_en_ib_media22cfg_END (3)
#define SOC_CRGPERIPH_PERI_CTRL3_qic_timeout_en_subchip2cfg_START (4)
#define SOC_CRGPERIPH_PERI_CTRL3_qic_timeout_en_subchip2cfg_END (4)
#define SOC_CRGPERIPH_PERI_CTRL3_qic_sys2ddrc_timeout_en_START (5)
#define SOC_CRGPERIPH_PERI_CTRL3_qic_sys2ddrc_timeout_en_END (5)
#define SOC_CRGPERIPH_PERI_CTRL3_bitmasken_START (16)
#define SOC_CRGPERIPH_PERI_CTRL3_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int sw_ack_clk_qic_hsdt1_pll_sw : 2;
        unsigned int swdone_clk_qic_hsdt_fll_div : 1;
        unsigned int st_clk_ffts_ref : 1;
        unsigned int reserved_1 : 3;
        unsigned int reserved_2 : 3;
        unsigned int sw_ack_clk_ufs_subsys_hsdt1_sw : 2;
        unsigned int swdone_clk_mdmperi_100m_div : 1;
        unsigned int swdone_clk_mdmperi_sne_div : 1;
        unsigned int swdone_clk_mdmperi_dpa_div : 1;
        unsigned int swdone_clk_usb1_arb_div : 1;
        unsigned int reserved_3 : 2;
        unsigned int swdone_clk_qic_hsdt_pll_div : 1;
        unsigned int sw_ack_clk_sdcu_sw : 2;
        unsigned int swdone_clk_fcm_ppll0_div : 1;
        unsigned int swdone_clk_sdcu_div : 1;
        unsigned int swdone_clk_lat_mon : 1;
        unsigned int swdone_clk_onewire : 1;
        unsigned int swdone_clk_div_hsdt1_fll_div : 1;
        unsigned int swdone_clk_div_hsdt1_pll_div : 1;
        unsigned int sw_ack_clk_qic_hsdt1_sw : 3;
        unsigned int reserved_4 : 1;
    } reg;
} SOC_CRGPERIPH_PERI_STAT10_UNION;
#endif
#define SOC_CRGPERIPH_PERI_STAT10_sw_ack_clk_qic_hsdt1_pll_sw_START (1)
#define SOC_CRGPERIPH_PERI_STAT10_sw_ack_clk_qic_hsdt1_pll_sw_END (2)
#define SOC_CRGPERIPH_PERI_STAT10_swdone_clk_qic_hsdt_fll_div_START (3)
#define SOC_CRGPERIPH_PERI_STAT10_swdone_clk_qic_hsdt_fll_div_END (3)
#define SOC_CRGPERIPH_PERI_STAT10_st_clk_ffts_ref_START (4)
#define SOC_CRGPERIPH_PERI_STAT10_st_clk_ffts_ref_END (4)
#define SOC_CRGPERIPH_PERI_STAT10_sw_ack_clk_ufs_subsys_hsdt1_sw_START (11)
#define SOC_CRGPERIPH_PERI_STAT10_sw_ack_clk_ufs_subsys_hsdt1_sw_END (12)
#define SOC_CRGPERIPH_PERI_STAT10_swdone_clk_mdmperi_100m_div_START (13)
#define SOC_CRGPERIPH_PERI_STAT10_swdone_clk_mdmperi_100m_div_END (13)
#define SOC_CRGPERIPH_PERI_STAT10_swdone_clk_mdmperi_sne_div_START (14)
#define SOC_CRGPERIPH_PERI_STAT10_swdone_clk_mdmperi_sne_div_END (14)
#define SOC_CRGPERIPH_PERI_STAT10_swdone_clk_mdmperi_dpa_div_START (15)
#define SOC_CRGPERIPH_PERI_STAT10_swdone_clk_mdmperi_dpa_div_END (15)
#define SOC_CRGPERIPH_PERI_STAT10_swdone_clk_usb1_arb_div_START (16)
#define SOC_CRGPERIPH_PERI_STAT10_swdone_clk_usb1_arb_div_END (16)
#define SOC_CRGPERIPH_PERI_STAT10_swdone_clk_qic_hsdt_pll_div_START (19)
#define SOC_CRGPERIPH_PERI_STAT10_swdone_clk_qic_hsdt_pll_div_END (19)
#define SOC_CRGPERIPH_PERI_STAT10_sw_ack_clk_sdcu_sw_START (20)
#define SOC_CRGPERIPH_PERI_STAT10_sw_ack_clk_sdcu_sw_END (21)
#define SOC_CRGPERIPH_PERI_STAT10_swdone_clk_fcm_ppll0_div_START (22)
#define SOC_CRGPERIPH_PERI_STAT10_swdone_clk_fcm_ppll0_div_END (22)
#define SOC_CRGPERIPH_PERI_STAT10_swdone_clk_sdcu_div_START (23)
#define SOC_CRGPERIPH_PERI_STAT10_swdone_clk_sdcu_div_END (23)
#define SOC_CRGPERIPH_PERI_STAT10_swdone_clk_lat_mon_START (24)
#define SOC_CRGPERIPH_PERI_STAT10_swdone_clk_lat_mon_END (24)
#define SOC_CRGPERIPH_PERI_STAT10_swdone_clk_onewire_START (25)
#define SOC_CRGPERIPH_PERI_STAT10_swdone_clk_onewire_END (25)
#define SOC_CRGPERIPH_PERI_STAT10_swdone_clk_div_hsdt1_fll_div_START (26)
#define SOC_CRGPERIPH_PERI_STAT10_swdone_clk_div_hsdt1_fll_div_END (26)
#define SOC_CRGPERIPH_PERI_STAT10_swdone_clk_div_hsdt1_pll_div_START (27)
#define SOC_CRGPERIPH_PERI_STAT10_swdone_clk_div_hsdt1_pll_div_END (27)
#define SOC_CRGPERIPH_PERI_STAT10_sw_ack_clk_qic_hsdt1_sw_START (28)
#define SOC_CRGPERIPH_PERI_STAT10_sw_ack_clk_qic_hsdt1_sw_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sw_ack_clk_qic_hsdt_sw : 3;
        unsigned int sw_ack_clk_mdmperi_dpa : 4;
        unsigned int sw_ack_clk_mdmperi_sne : 4;
        unsigned int reserved_0 : 16;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 2;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_CRGPERIPH_PERI_STAT11_UNION;
#endif
#define SOC_CRGPERIPH_PERI_STAT11_sw_ack_clk_qic_hsdt_sw_START (0)
#define SOC_CRGPERIPH_PERI_STAT11_sw_ack_clk_qic_hsdt_sw_END (2)
#define SOC_CRGPERIPH_PERI_STAT11_sw_ack_clk_mdmperi_dpa_START (3)
#define SOC_CRGPERIPH_PERI_STAT11_sw_ack_clk_mdmperi_dpa_END (6)
#define SOC_CRGPERIPH_PERI_STAT11_sw_ack_clk_mdmperi_sne_START (7)
#define SOC_CRGPERIPH_PERI_STAT11_sw_ack_clk_mdmperi_sne_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int csysreq_etr_lpi : 1;
        unsigned int csysack_etr_lpi : 1;
        unsigned int cactive_etr_lpi : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_CRGPERIPH_CORESIGHTLPSTAT_UNION;
#endif
#define SOC_CRGPERIPH_CORESIGHTLPSTAT_csysreq_etr_lpi_START (0)
#define SOC_CRGPERIPH_CORESIGHTLPSTAT_csysreq_etr_lpi_END (0)
#define SOC_CRGPERIPH_CORESIGHTLPSTAT_csysack_etr_lpi_START (1)
#define SOC_CRGPERIPH_CORESIGHTLPSTAT_csysack_etr_lpi_END (1)
#define SOC_CRGPERIPH_CORESIGHTLPSTAT_cactive_etr_lpi_START (2)
#define SOC_CRGPERIPH_CORESIGHTLPSTAT_cactive_etr_lpi_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_s_cssys : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CRGPERIPH_CORESIGHT_CTRL_UNION;
#endif
#define SOC_CRGPERIPH_CORESIGHT_CTRL_mem_ctrl_s_cssys_START (0)
#define SOC_CRGPERIPH_CORESIGHT_CTRL_mem_ctrl_s_cssys_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int etf_top_full : 1;
        unsigned int reserved_2 : 29;
    } reg;
} SOC_CRGPERIPH_CORESIGHTETFINT_UNION;
#endif
#define SOC_CRGPERIPH_CORESIGHTETFINT_etf_top_full_START (2)
#define SOC_CRGPERIPH_CORESIGHTETFINT_etf_top_full_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int etr_top_full : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 23;
    } reg;
} SOC_CRGPERIPH_CORESIGHTETRINT_UNION;
#endif
#define SOC_CRGPERIPH_CORESIGHTETRINT_etr_top_full_START (0)
#define SOC_CRGPERIPH_CORESIGHTETRINT_etr_top_full_END (0)
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
        unsigned int lit_adb_gt_status_cpu0_slv : 1;
        unsigned int hc_adb_gt_status_cpu1_slv : 1;
        unsigned int hc_adb_gt_status_cpu0_slv : 1;
        unsigned int adb_gt_status_lit_mst_0 : 1;
        unsigned int adb_gt_status_hc_mst_1 : 1;
        unsigned int adb_gt_status_hc_mst_0 : 1;
        unsigned int adb_gt_status_gpu1_slv : 1;
        unsigned int adb_gt_status_gpu1_mst : 1;
        unsigned int adb_gt_status_gpu0_slv : 1;
        unsigned int adb_gt_status_gpu0_mst : 1;
        unsigned int adb_gt_status_isp_cpu_mst : 1;
        unsigned int adb_gt_status_isp_cpu_slv : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 8;
    } reg;
} SOC_CRGPERIPH_ADB_GT_STATUS_UNION;
#endif
#define SOC_CRGPERIPH_ADB_GT_STATUS_lit_adb_gt_status_cpu0_slv_START (8)
#define SOC_CRGPERIPH_ADB_GT_STATUS_lit_adb_gt_status_cpu0_slv_END (8)
#define SOC_CRGPERIPH_ADB_GT_STATUS_hc_adb_gt_status_cpu1_slv_START (9)
#define SOC_CRGPERIPH_ADB_GT_STATUS_hc_adb_gt_status_cpu1_slv_END (9)
#define SOC_CRGPERIPH_ADB_GT_STATUS_hc_adb_gt_status_cpu0_slv_START (10)
#define SOC_CRGPERIPH_ADB_GT_STATUS_hc_adb_gt_status_cpu0_slv_END (10)
#define SOC_CRGPERIPH_ADB_GT_STATUS_adb_gt_status_lit_mst_0_START (11)
#define SOC_CRGPERIPH_ADB_GT_STATUS_adb_gt_status_lit_mst_0_END (11)
#define SOC_CRGPERIPH_ADB_GT_STATUS_adb_gt_status_hc_mst_1_START (12)
#define SOC_CRGPERIPH_ADB_GT_STATUS_adb_gt_status_hc_mst_1_END (12)
#define SOC_CRGPERIPH_ADB_GT_STATUS_adb_gt_status_hc_mst_0_START (13)
#define SOC_CRGPERIPH_ADB_GT_STATUS_adb_gt_status_hc_mst_0_END (13)
#define SOC_CRGPERIPH_ADB_GT_STATUS_adb_gt_status_gpu1_slv_START (14)
#define SOC_CRGPERIPH_ADB_GT_STATUS_adb_gt_status_gpu1_slv_END (14)
#define SOC_CRGPERIPH_ADB_GT_STATUS_adb_gt_status_gpu1_mst_START (15)
#define SOC_CRGPERIPH_ADB_GT_STATUS_adb_gt_status_gpu1_mst_END (15)
#define SOC_CRGPERIPH_ADB_GT_STATUS_adb_gt_status_gpu0_slv_START (16)
#define SOC_CRGPERIPH_ADB_GT_STATUS_adb_gt_status_gpu0_slv_END (16)
#define SOC_CRGPERIPH_ADB_GT_STATUS_adb_gt_status_gpu0_mst_START (17)
#define SOC_CRGPERIPH_ADB_GT_STATUS_adb_gt_status_gpu0_mst_END (17)
#define SOC_CRGPERIPH_ADB_GT_STATUS_adb_gt_status_isp_cpu_mst_START (18)
#define SOC_CRGPERIPH_ADB_GT_STATUS_adb_gt_status_isp_cpu_mst_END (18)
#define SOC_CRGPERIPH_ADB_GT_STATUS_adb_gt_status_isp_cpu_slv_START (19)
#define SOC_CRGPERIPH_ADB_GT_STATUS_adb_gt_status_isp_cpu_slv_END (19)
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
        unsigned int lit_adb_wakeup_cpu0_mst : 1;
        unsigned int hc_adb_wakeup_cpu1_mst : 1;
        unsigned int hc_adb_wakeup_cpu0_mst : 1;
        unsigned int hc_adb_wakeup_cpu1_slv : 1;
        unsigned int hc_adb_wakeup_cpu0_slv : 1;
        unsigned int lit_adb_wakeup_cpu0_slv : 1;
        unsigned int adb_wakeup_gpu1_slv : 1;
        unsigned int adb_wakeup_gpu1_mst : 1;
        unsigned int adb_wakeup_gpu0_slv : 1;
        unsigned int adb_wakeup_gpu0_mst : 1;
        unsigned int adb_wakeup_isp_cpu_mst : 1;
        unsigned int adb_wakeup_isp_cpu_slv : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 8;
    } reg;
} SOC_CRGPERIPH_ADB_WAKEUP_STATUS_UNION;
#endif
#define SOC_CRGPERIPH_ADB_WAKEUP_STATUS_lit_adb_wakeup_cpu0_mst_START (8)
#define SOC_CRGPERIPH_ADB_WAKEUP_STATUS_lit_adb_wakeup_cpu0_mst_END (8)
#define SOC_CRGPERIPH_ADB_WAKEUP_STATUS_hc_adb_wakeup_cpu1_mst_START (9)
#define SOC_CRGPERIPH_ADB_WAKEUP_STATUS_hc_adb_wakeup_cpu1_mst_END (9)
#define SOC_CRGPERIPH_ADB_WAKEUP_STATUS_hc_adb_wakeup_cpu0_mst_START (10)
#define SOC_CRGPERIPH_ADB_WAKEUP_STATUS_hc_adb_wakeup_cpu0_mst_END (10)
#define SOC_CRGPERIPH_ADB_WAKEUP_STATUS_hc_adb_wakeup_cpu1_slv_START (11)
#define SOC_CRGPERIPH_ADB_WAKEUP_STATUS_hc_adb_wakeup_cpu1_slv_END (11)
#define SOC_CRGPERIPH_ADB_WAKEUP_STATUS_hc_adb_wakeup_cpu0_slv_START (12)
#define SOC_CRGPERIPH_ADB_WAKEUP_STATUS_hc_adb_wakeup_cpu0_slv_END (12)
#define SOC_CRGPERIPH_ADB_WAKEUP_STATUS_lit_adb_wakeup_cpu0_slv_START (13)
#define SOC_CRGPERIPH_ADB_WAKEUP_STATUS_lit_adb_wakeup_cpu0_slv_END (13)
#define SOC_CRGPERIPH_ADB_WAKEUP_STATUS_adb_wakeup_gpu1_slv_START (14)
#define SOC_CRGPERIPH_ADB_WAKEUP_STATUS_adb_wakeup_gpu1_slv_END (14)
#define SOC_CRGPERIPH_ADB_WAKEUP_STATUS_adb_wakeup_gpu1_mst_START (15)
#define SOC_CRGPERIPH_ADB_WAKEUP_STATUS_adb_wakeup_gpu1_mst_END (15)
#define SOC_CRGPERIPH_ADB_WAKEUP_STATUS_adb_wakeup_gpu0_slv_START (16)
#define SOC_CRGPERIPH_ADB_WAKEUP_STATUS_adb_wakeup_gpu0_slv_END (16)
#define SOC_CRGPERIPH_ADB_WAKEUP_STATUS_adb_wakeup_gpu0_mst_START (17)
#define SOC_CRGPERIPH_ADB_WAKEUP_STATUS_adb_wakeup_gpu0_mst_END (17)
#define SOC_CRGPERIPH_ADB_WAKEUP_STATUS_adb_wakeup_isp_cpu_mst_START (18)
#define SOC_CRGPERIPH_ADB_WAKEUP_STATUS_adb_wakeup_isp_cpu_mst_END (18)
#define SOC_CRGPERIPH_ADB_WAKEUP_STATUS_adb_wakeup_isp_cpu_slv_START (19)
#define SOC_CRGPERIPH_ADB_WAKEUP_STATUS_adb_wakeup_isp_cpu_slv_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int autodiv_sysbus_stat : 1;
        unsigned int autodiv_lpmcu_stat : 1;
        unsigned int reserved_0 : 1;
        unsigned int autodiv_sysbus_fll_stat : 1;
        unsigned int autodiv_lpmcu_fll_stat : 1;
        unsigned int reserved_1 : 1;
        unsigned int autodiv_hsdtbus_l_fll_stat : 1;
        unsigned int autodiv_hsdtbus_l_stat : 1;
        unsigned int autogt_dmc_peri_stat : 1;
        unsigned int autodiv_hsdtbus_h_fll_stat : 1;
        unsigned int autodiv_ufs_dfa_sys_stat : 1;
        unsigned int autodiv_hsdtbus_h_stat : 1;
        unsigned int autogt_ddrc_stat : 1;
        unsigned int autodiv_center_crossbar_stat : 1;
        unsigned int autodiv_center_crossbar_fll_stat : 1;
        unsigned int autodiv_hsdt1bus_fll_stat : 1;
        unsigned int autodiv_npubus_ts_cpu_stat : 1;
        unsigned int autodiv_hsdt1bus_pll_stat : 1;
        unsigned int autodiv_npubus_aicore1_stat : 1;
        unsigned int autodiv_npubus_aicore0_stat : 1;
        unsigned int autodiv_npubus_stat : 1;
        unsigned int autodiv_npubus_cfg_stat : 1;
        unsigned int autodiv_periph_cpu_lit_stat : 1;
        unsigned int autodiv_periph_cpu_hc_stat : 1;
        unsigned int autodiv_periph_cpu_stat : 1;
        unsigned int autodiv_cpu_gic_stat : 1;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_UNION;
#endif
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_sysbus_stat_START (0)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_sysbus_stat_END (0)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_lpmcu_stat_START (1)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_lpmcu_stat_END (1)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_sysbus_fll_stat_START (3)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_sysbus_fll_stat_END (3)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_lpmcu_fll_stat_START (4)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_lpmcu_fll_stat_END (4)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_hsdtbus_l_fll_stat_START (6)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_hsdtbus_l_fll_stat_END (6)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_hsdtbus_l_stat_START (7)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_hsdtbus_l_stat_END (7)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autogt_dmc_peri_stat_START (8)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autogt_dmc_peri_stat_END (8)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_hsdtbus_h_fll_stat_START (9)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_hsdtbus_h_fll_stat_END (9)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_ufs_dfa_sys_stat_START (10)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_ufs_dfa_sys_stat_END (10)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_hsdtbus_h_stat_START (11)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_hsdtbus_h_stat_END (11)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autogt_ddrc_stat_START (12)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autogt_ddrc_stat_END (12)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_center_crossbar_stat_START (13)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_center_crossbar_stat_END (13)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_center_crossbar_fll_stat_START (14)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_center_crossbar_fll_stat_END (14)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_hsdt1bus_fll_stat_START (15)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_hsdt1bus_fll_stat_END (15)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_npubus_ts_cpu_stat_START (16)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_npubus_ts_cpu_stat_END (16)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_hsdt1bus_pll_stat_START (17)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_hsdt1bus_pll_stat_END (17)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_npubus_aicore1_stat_START (18)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_npubus_aicore1_stat_END (18)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_npubus_aicore0_stat_START (19)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_npubus_aicore0_stat_END (19)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_npubus_stat_START (20)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_npubus_stat_END (20)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_npubus_cfg_stat_START (21)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_npubus_cfg_stat_END (21)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_periph_cpu_lit_stat_START (22)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_periph_cpu_lit_stat_END (22)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_periph_cpu_hc_stat_START (23)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_periph_cpu_hc_stat_END (23)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_periph_cpu_stat_START (24)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_periph_cpu_stat_END (24)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_cpu_gic_stat_START (25)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT_autodiv_cpu_gic_stat_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sysbus_idle_flag : 1;
        unsigned int hsdtbus_h_idle_flag : 1;
        unsigned int hsdtbus_l_idle_flag : 1;
        unsigned int hsdt1bus_idle_flag : 1;
        unsigned int gpubus_idle_flag : 1;
        unsigned int fcmbus_idle_flag : 1;
        unsigned int media1bus_idle_flag : 1;
        unsigned int media2bus_idle_flag : 1;
        unsigned int npubus_idle_flag : 1;
        unsigned int ddrsys_idle_flag : 1;
        unsigned int mdmperi2sys_idle_flag : 1;
        unsigned int hsdt1bus2cc_idle_flag : 1;
        unsigned int hsdtbus2cc_idle_flag : 1;
        unsigned int idle_mediaxctrl_h2x : 1;
        unsigned int idle_merdiaxctrl_core : 1;
        unsigned int mdm2sys_bus_idle : 1;
        unsigned int idle_ddrxctrl_h2x : 1;
        unsigned int idle_ddrxctrl_core : 1;
        unsigned int dfa_sys_idle_flag : 1;
        unsigned int dfa_cpu_clk_en : 1;
        unsigned int dmc_idle_flag : 1;
        unsigned int qice_idle_flag : 1;
        unsigned int xpu_to_qic_idle_flag_ddrxctrl : 1;
        unsigned int ffts2cc_nopending : 1;
        unsigned int hts_idle : 1;
        unsigned int m3_idle_flag : 1;
        unsigned int periph_cpu_idle_flag : 1;
        unsigned int periph_cpu_hc_idle_flag : 1;
        unsigned int periph_cpu_lit_idle_flag : 1;
        unsigned int cpu_gic_idle_flag : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_UNION;
#endif
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_sysbus_idle_flag_START (0)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_sysbus_idle_flag_END (0)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_hsdtbus_h_idle_flag_START (1)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_hsdtbus_h_idle_flag_END (1)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_hsdtbus_l_idle_flag_START (2)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_hsdtbus_l_idle_flag_END (2)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_hsdt1bus_idle_flag_START (3)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_hsdt1bus_idle_flag_END (3)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_gpubus_idle_flag_START (4)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_gpubus_idle_flag_END (4)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_fcmbus_idle_flag_START (5)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_fcmbus_idle_flag_END (5)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_media1bus_idle_flag_START (6)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_media1bus_idle_flag_END (6)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_media2bus_idle_flag_START (7)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_media2bus_idle_flag_END (7)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_npubus_idle_flag_START (8)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_npubus_idle_flag_END (8)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_ddrsys_idle_flag_START (9)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_ddrsys_idle_flag_END (9)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_mdmperi2sys_idle_flag_START (10)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_mdmperi2sys_idle_flag_END (10)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_hsdt1bus2cc_idle_flag_START (11)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_hsdt1bus2cc_idle_flag_END (11)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_hsdtbus2cc_idle_flag_START (12)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_hsdtbus2cc_idle_flag_END (12)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_idle_mediaxctrl_h2x_START (13)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_idle_mediaxctrl_h2x_END (13)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_idle_merdiaxctrl_core_START (14)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_idle_merdiaxctrl_core_END (14)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_mdm2sys_bus_idle_START (15)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_mdm2sys_bus_idle_END (15)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_idle_ddrxctrl_h2x_START (16)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_idle_ddrxctrl_h2x_END (16)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_idle_ddrxctrl_core_START (17)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_idle_ddrxctrl_core_END (17)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_dfa_sys_idle_flag_START (18)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_dfa_sys_idle_flag_END (18)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_dfa_cpu_clk_en_START (19)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_dfa_cpu_clk_en_END (19)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_dmc_idle_flag_START (20)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_dmc_idle_flag_END (20)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_qice_idle_flag_START (21)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_qice_idle_flag_END (21)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_xpu_to_qic_idle_flag_ddrxctrl_START (22)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_xpu_to_qic_idle_flag_ddrxctrl_END (22)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_ffts2cc_nopending_START (23)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_ffts2cc_nopending_END (23)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_hts_idle_START (24)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_hts_idle_END (24)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_m3_idle_flag_START (25)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_m3_idle_flag_END (25)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_periph_cpu_idle_flag_START (26)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_periph_cpu_idle_flag_END (26)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_periph_cpu_hc_idle_flag_START (27)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_periph_cpu_hc_idle_flag_END (27)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_periph_cpu_lit_idle_flag_START (28)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_periph_cpu_lit_idle_flag_END (28)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_cpu_gic_idle_flag_START (29)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT1_cpu_gic_idle_flag_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_a_pll_gate_en : 1;
        unsigned int dmc_b_pll_gate_en : 1;
        unsigned int dmc_c_pll_gate_en : 1;
        unsigned int dmc_d_pll_gate_en : 1;
        unsigned int ddr_fast_wakeup : 1;
        unsigned int ffts_idle : 1;
        unsigned int pdea2ddr_bus_idle : 1;
        unsigned int idle_lpmcu_dcdr_h2p_qicecfg : 1;
        unsigned int mdm2ddr_bus_idle : 1;
        unsigned int qic_r_nopending_tb_sys2syscache : 1;
        unsigned int qic_w_nopending_tb_sys2syscache : 1;
        unsigned int sdcu_qice_idle_flag : 1;
        unsigned int qice_cpu_idle_flag : 1;
        unsigned int qice_hsdt0_idle_flag : 1;
        unsigned int qice_npu_idle_flag : 1;
        unsigned int qice_gpu_idle_flag : 1;
        unsigned int qice_media1_idle_flag : 1;
        unsigned int qice_media2_idle_flag : 1;
        unsigned int cc_flag_2 : 1;
        unsigned int cc_flag_1 : 1;
        unsigned int cfg_bus_flag_1 : 1;
        unsigned int cc_flag_4 : 1;
        unsigned int ddrc_lp_ind : 4;
        unsigned int qice_wrap_main_nopending_comb : 1;
        unsigned int qice_wrap_main_em_perf_idle_comb : 1;
        unsigned int cfg_bus_flag_0 : 1;
        unsigned int qice_qsp_fcm_qic_nopending : 1;
        unsigned int qice_wrap_sc_nopending_comb : 1;
        unsigned int qice_wrap_sc_em_perf_idle_comb : 1;
    } reg;
} SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_UNION;
#endif
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_dmc_a_pll_gate_en_START (0)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_dmc_a_pll_gate_en_END (0)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_dmc_b_pll_gate_en_START (1)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_dmc_b_pll_gate_en_END (1)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_dmc_c_pll_gate_en_START (2)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_dmc_c_pll_gate_en_END (2)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_dmc_d_pll_gate_en_START (3)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_dmc_d_pll_gate_en_END (3)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_ddr_fast_wakeup_START (4)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_ddr_fast_wakeup_END (4)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_ffts_idle_START (5)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_ffts_idle_END (5)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_pdea2ddr_bus_idle_START (6)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_pdea2ddr_bus_idle_END (6)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_idle_lpmcu_dcdr_h2p_qicecfg_START (7)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_idle_lpmcu_dcdr_h2p_qicecfg_END (7)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_mdm2ddr_bus_idle_START (8)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_mdm2ddr_bus_idle_END (8)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_qic_r_nopending_tb_sys2syscache_START (9)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_qic_r_nopending_tb_sys2syscache_END (9)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_qic_w_nopending_tb_sys2syscache_START (10)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_qic_w_nopending_tb_sys2syscache_END (10)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_sdcu_qice_idle_flag_START (11)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_sdcu_qice_idle_flag_END (11)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_qice_cpu_idle_flag_START (12)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_qice_cpu_idle_flag_END (12)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_qice_hsdt0_idle_flag_START (13)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_qice_hsdt0_idle_flag_END (13)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_qice_npu_idle_flag_START (14)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_qice_npu_idle_flag_END (14)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_qice_gpu_idle_flag_START (15)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_qice_gpu_idle_flag_END (15)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_qice_media1_idle_flag_START (16)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_qice_media1_idle_flag_END (16)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_qice_media2_idle_flag_START (17)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_qice_media2_idle_flag_END (17)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_cc_flag_2_START (18)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_cc_flag_2_END (18)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_cc_flag_1_START (19)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_cc_flag_1_END (19)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_cfg_bus_flag_1_START (20)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_cfg_bus_flag_1_END (20)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_cc_flag_4_START (21)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_cc_flag_4_END (21)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_ddrc_lp_ind_START (22)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_ddrc_lp_ind_END (25)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_qice_wrap_main_nopending_comb_START (26)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_qice_wrap_main_nopending_comb_END (26)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_qice_wrap_main_em_perf_idle_comb_START (27)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_qice_wrap_main_em_perf_idle_comb_END (27)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_cfg_bus_flag_0_START (28)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_cfg_bus_flag_0_END (28)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_qice_qsp_fcm_qic_nopending_START (29)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_qice_qsp_fcm_qic_nopending_END (29)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_qice_wrap_sc_nopending_comb_START (30)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_qice_wrap_sc_nopending_comb_END (30)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_qice_wrap_sc_em_perf_idle_comb_START (31)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT2_qice_wrap_sc_em_perf_idle_comb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int atgs_lp_cative : 3;
        unsigned int reserved_0 : 2;
        unsigned int tb2ddr_bus_busy_a : 1;
        unsigned int tb2ddr_bus_busy_b : 1;
        unsigned int tb2ddr_bus_busy_c : 1;
        unsigned int tb2ddr_bus_busy_d : 1;
        unsigned int pll_gate_en_ddrphy_d : 1;
        unsigned int pll_gate_en_ddrphy_c : 1;
        unsigned int pll_gate_en_ddrphy_b : 1;
        unsigned int pll_gate_en_ddrphy_a : 1;
        unsigned int ocfg_dcdr_idle_d : 1;
        unsigned int ocfg_dcdr_idle_c : 1;
        unsigned int ocfg_dcdr_idle_b : 1;
        unsigned int ocfg_dcdr_idle_a : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 4;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 4;
    } reg;
} SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT3_UNION;
#endif
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT3_atgs_lp_cative_START (0)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT3_atgs_lp_cative_END (2)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT3_tb2ddr_bus_busy_a_START (5)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT3_tb2ddr_bus_busy_a_END (5)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT3_tb2ddr_bus_busy_b_START (6)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT3_tb2ddr_bus_busy_b_END (6)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT3_tb2ddr_bus_busy_c_START (7)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT3_tb2ddr_bus_busy_c_END (7)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT3_tb2ddr_bus_busy_d_START (8)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT3_tb2ddr_bus_busy_d_END (8)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT3_pll_gate_en_ddrphy_d_START (9)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT3_pll_gate_en_ddrphy_d_END (9)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT3_pll_gate_en_ddrphy_c_START (10)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT3_pll_gate_en_ddrphy_c_END (10)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT3_pll_gate_en_ddrphy_b_START (11)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT3_pll_gate_en_ddrphy_b_END (11)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT3_pll_gate_en_ddrphy_a_START (12)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT3_pll_gate_en_ddrphy_a_END (12)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT3_ocfg_dcdr_idle_d_START (13)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT3_ocfg_dcdr_idle_d_END (13)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT3_ocfg_dcdr_idle_c_START (14)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT3_ocfg_dcdr_idle_c_END (14)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT3_ocfg_dcdr_idle_b_START (15)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT3_ocfg_dcdr_idle_b_END (15)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT3_ocfg_dcdr_idle_a_START (16)
#define SOC_CRGPERIPH_PERI_AUTODIV_INUSE_STAT3_ocfg_dcdr_idle_a_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_lat_mon_m1 : 1;
        unsigned int gt_clk_lat_mon_m2 : 1;
        unsigned int gt_clk_lat_mon_npu : 1;
        unsigned int gt_clk_lat_mon_qice : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_qice_data_sdcu : 1;
        unsigned int gt_clk_sdcu : 1;
        unsigned int gt_clk_sysbus_sdcu : 1;
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
        unsigned int gt_clk_ppll7_sscg : 1;
        unsigned int gt_clk_ppll6_sscg : 1;
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
} SOC_CRGPERIPH_PEREN6_UNION;
#endif
#define SOC_CRGPERIPH_PEREN6_gt_clk_lat_mon_m1_START (0)
#define SOC_CRGPERIPH_PEREN6_gt_clk_lat_mon_m1_END (0)
#define SOC_CRGPERIPH_PEREN6_gt_clk_lat_mon_m2_START (1)
#define SOC_CRGPERIPH_PEREN6_gt_clk_lat_mon_m2_END (1)
#define SOC_CRGPERIPH_PEREN6_gt_clk_lat_mon_npu_START (2)
#define SOC_CRGPERIPH_PEREN6_gt_clk_lat_mon_npu_END (2)
#define SOC_CRGPERIPH_PEREN6_gt_clk_lat_mon_qice_START (3)
#define SOC_CRGPERIPH_PEREN6_gt_clk_lat_mon_qice_END (3)
#define SOC_CRGPERIPH_PEREN6_gt_clk_qice_data_sdcu_START (5)
#define SOC_CRGPERIPH_PEREN6_gt_clk_qice_data_sdcu_END (5)
#define SOC_CRGPERIPH_PEREN6_gt_clk_sdcu_START (6)
#define SOC_CRGPERIPH_PEREN6_gt_clk_sdcu_END (6)
#define SOC_CRGPERIPH_PEREN6_gt_clk_sysbus_sdcu_START (7)
#define SOC_CRGPERIPH_PEREN6_gt_clk_sysbus_sdcu_END (7)
#define SOC_CRGPERIPH_PEREN6_gt_clk_ppll7_sscg_START (21)
#define SOC_CRGPERIPH_PEREN6_gt_clk_ppll7_sscg_END (21)
#define SOC_CRGPERIPH_PEREN6_gt_clk_ppll6_sscg_START (22)
#define SOC_CRGPERIPH_PEREN6_gt_clk_ppll6_sscg_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_lat_mon_m1 : 1;
        unsigned int gt_clk_lat_mon_m2 : 1;
        unsigned int gt_clk_lat_mon_npu : 1;
        unsigned int gt_clk_lat_mon_qice : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_qice_data_sdcu : 1;
        unsigned int gt_clk_sdcu : 1;
        unsigned int gt_clk_sysbus_sdcu : 1;
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
        unsigned int gt_clk_ppll7_sscg : 1;
        unsigned int gt_clk_ppll6_sscg : 1;
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
} SOC_CRGPERIPH_PERDIS6_UNION;
#endif
#define SOC_CRGPERIPH_PERDIS6_gt_clk_lat_mon_m1_START (0)
#define SOC_CRGPERIPH_PERDIS6_gt_clk_lat_mon_m1_END (0)
#define SOC_CRGPERIPH_PERDIS6_gt_clk_lat_mon_m2_START (1)
#define SOC_CRGPERIPH_PERDIS6_gt_clk_lat_mon_m2_END (1)
#define SOC_CRGPERIPH_PERDIS6_gt_clk_lat_mon_npu_START (2)
#define SOC_CRGPERIPH_PERDIS6_gt_clk_lat_mon_npu_END (2)
#define SOC_CRGPERIPH_PERDIS6_gt_clk_lat_mon_qice_START (3)
#define SOC_CRGPERIPH_PERDIS6_gt_clk_lat_mon_qice_END (3)
#define SOC_CRGPERIPH_PERDIS6_gt_clk_qice_data_sdcu_START (5)
#define SOC_CRGPERIPH_PERDIS6_gt_clk_qice_data_sdcu_END (5)
#define SOC_CRGPERIPH_PERDIS6_gt_clk_sdcu_START (6)
#define SOC_CRGPERIPH_PERDIS6_gt_clk_sdcu_END (6)
#define SOC_CRGPERIPH_PERDIS6_gt_clk_sysbus_sdcu_START (7)
#define SOC_CRGPERIPH_PERDIS6_gt_clk_sysbus_sdcu_END (7)
#define SOC_CRGPERIPH_PERDIS6_gt_clk_ppll7_sscg_START (21)
#define SOC_CRGPERIPH_PERDIS6_gt_clk_ppll7_sscg_END (21)
#define SOC_CRGPERIPH_PERDIS6_gt_clk_ppll6_sscg_START (22)
#define SOC_CRGPERIPH_PERDIS6_gt_clk_ppll6_sscg_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_lat_mon_m1 : 1;
        unsigned int gt_clk_lat_mon_m2 : 1;
        unsigned int gt_clk_lat_mon_npu : 1;
        unsigned int gt_clk_lat_mon_qice : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_qice_data_sdcu : 1;
        unsigned int gt_clk_sdcu : 1;
        unsigned int gt_clk_sysbus_sdcu : 1;
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
        unsigned int gt_clk_ppll7_sscg : 1;
        unsigned int gt_clk_ppll6_sscg : 1;
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
} SOC_CRGPERIPH_PERCLKEN6_UNION;
#endif
#define SOC_CRGPERIPH_PERCLKEN6_gt_clk_lat_mon_m1_START (0)
#define SOC_CRGPERIPH_PERCLKEN6_gt_clk_lat_mon_m1_END (0)
#define SOC_CRGPERIPH_PERCLKEN6_gt_clk_lat_mon_m2_START (1)
#define SOC_CRGPERIPH_PERCLKEN6_gt_clk_lat_mon_m2_END (1)
#define SOC_CRGPERIPH_PERCLKEN6_gt_clk_lat_mon_npu_START (2)
#define SOC_CRGPERIPH_PERCLKEN6_gt_clk_lat_mon_npu_END (2)
#define SOC_CRGPERIPH_PERCLKEN6_gt_clk_lat_mon_qice_START (3)
#define SOC_CRGPERIPH_PERCLKEN6_gt_clk_lat_mon_qice_END (3)
#define SOC_CRGPERIPH_PERCLKEN6_gt_clk_qice_data_sdcu_START (5)
#define SOC_CRGPERIPH_PERCLKEN6_gt_clk_qice_data_sdcu_END (5)
#define SOC_CRGPERIPH_PERCLKEN6_gt_clk_sdcu_START (6)
#define SOC_CRGPERIPH_PERCLKEN6_gt_clk_sdcu_END (6)
#define SOC_CRGPERIPH_PERCLKEN6_gt_clk_sysbus_sdcu_START (7)
#define SOC_CRGPERIPH_PERCLKEN6_gt_clk_sysbus_sdcu_END (7)
#define SOC_CRGPERIPH_PERCLKEN6_gt_clk_ppll7_sscg_START (21)
#define SOC_CRGPERIPH_PERCLKEN6_gt_clk_ppll7_sscg_END (21)
#define SOC_CRGPERIPH_PERCLKEN6_gt_clk_ppll6_sscg_START (22)
#define SOC_CRGPERIPH_PERCLKEN6_gt_clk_ppll6_sscg_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_lat_mon_m1 : 1;
        unsigned int st_clk_lat_mon_m2 : 1;
        unsigned int st_clk_lat_mon_npu : 1;
        unsigned int st_clk_lat_mon_qice : 1;
        unsigned int reserved_0 : 1;
        unsigned int st_clk_qice_data_sdcu : 1;
        unsigned int st_clk_sdcu : 1;
        unsigned int st_clk_sysbus_sdcu : 1;
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
        unsigned int st_clk_ppll7_sscg : 1;
        unsigned int st_clk_ppll6_sscg : 1;
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
} SOC_CRGPERIPH_PERSTAT6_UNION;
#endif
#define SOC_CRGPERIPH_PERSTAT6_st_clk_lat_mon_m1_START (0)
#define SOC_CRGPERIPH_PERSTAT6_st_clk_lat_mon_m1_END (0)
#define SOC_CRGPERIPH_PERSTAT6_st_clk_lat_mon_m2_START (1)
#define SOC_CRGPERIPH_PERSTAT6_st_clk_lat_mon_m2_END (1)
#define SOC_CRGPERIPH_PERSTAT6_st_clk_lat_mon_npu_START (2)
#define SOC_CRGPERIPH_PERSTAT6_st_clk_lat_mon_npu_END (2)
#define SOC_CRGPERIPH_PERSTAT6_st_clk_lat_mon_qice_START (3)
#define SOC_CRGPERIPH_PERSTAT6_st_clk_lat_mon_qice_END (3)
#define SOC_CRGPERIPH_PERSTAT6_st_clk_qice_data_sdcu_START (5)
#define SOC_CRGPERIPH_PERSTAT6_st_clk_qice_data_sdcu_END (5)
#define SOC_CRGPERIPH_PERSTAT6_st_clk_sdcu_START (6)
#define SOC_CRGPERIPH_PERSTAT6_st_clk_sdcu_END (6)
#define SOC_CRGPERIPH_PERSTAT6_st_clk_sysbus_sdcu_START (7)
#define SOC_CRGPERIPH_PERSTAT6_st_clk_sysbus_sdcu_END (7)
#define SOC_CRGPERIPH_PERSTAT6_st_clk_ppll7_sscg_START (21)
#define SOC_CRGPERIPH_PERSTAT6_st_clk_ppll7_sscg_END (21)
#define SOC_CRGPERIPH_PERSTAT6_st_clk_ppll6_sscg_START (22)
#define SOC_CRGPERIPH_PERSTAT6_st_clk_ppll6_sscg_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
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
        unsigned int reserved_27: 5;
    } reg;
} SOC_CRGPERIPH_PEREN7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
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
        unsigned int reserved_27: 5;
    } reg;
} SOC_CRGPERIPH_PERDIS7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
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
        unsigned int reserved_27: 5;
    } reg;
} SOC_CRGPERIPH_PERCLKEN7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
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
        unsigned int reserved_27: 5;
    } reg;
} SOC_CRGPERIPH_PERSTAT7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
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
} SOC_CRGPERIPH_PEREN8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
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
} SOC_CRGPERIPH_PERDIS8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
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
} SOC_CRGPERIPH_PERCLKEN8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
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
} SOC_CRGPERIPH_PERSTAT8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
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
} SOC_CRGPERIPH_PEREN9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
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
} SOC_CRGPERIPH_PERDIS9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
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
} SOC_CRGPERIPH_PERCLKEN9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
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
} SOC_CRGPERIPH_PERSTAT9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
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
} SOC_CRGPERIPH_PEREN10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
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
} SOC_CRGPERIPH_PERDIS10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
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
} SOC_CRGPERIPH_PERCLKEN10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
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
} SOC_CRGPERIPH_PERSTAT10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
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
} SOC_CRGPERIPH_PEREN11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
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
} SOC_CRGPERIPH_PERDIS11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
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
} SOC_CRGPERIPH_PERCLKEN11_UNION;
#endif
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
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int ppll2_b_gt_stat : 1;
        unsigned int ppll1_gt_stat : 1;
        unsigned int ppll2_gt_stat : 1;
        unsigned int ppll3_gt_stat : 1;
        unsigned int ppll1_en_stat : 1;
        unsigned int ppll2_en_stat : 1;
        unsigned int ppll3_en_stat : 1;
        unsigned int ppll2_b_en_stat : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int reserved_19 : 1;
        unsigned int reserved_20 : 1;
        unsigned int reserved_21 : 1;
        unsigned int reserved_22 : 1;
        unsigned int reserved_23 : 1;
    } reg;
} SOC_CRGPERIPH_PERSTAT11_UNION;
#endif
#define SOC_CRGPERIPH_PERSTAT11_ppll2_b_gt_stat_START (15)
#define SOC_CRGPERIPH_PERSTAT11_ppll2_b_gt_stat_END (15)
#define SOC_CRGPERIPH_PERSTAT11_ppll1_gt_stat_START (16)
#define SOC_CRGPERIPH_PERSTAT11_ppll1_gt_stat_END (16)
#define SOC_CRGPERIPH_PERSTAT11_ppll2_gt_stat_START (17)
#define SOC_CRGPERIPH_PERSTAT11_ppll2_gt_stat_END (17)
#define SOC_CRGPERIPH_PERSTAT11_ppll3_gt_stat_START (18)
#define SOC_CRGPERIPH_PERSTAT11_ppll3_gt_stat_END (18)
#define SOC_CRGPERIPH_PERSTAT11_ppll1_en_stat_START (19)
#define SOC_CRGPERIPH_PERSTAT11_ppll1_en_stat_END (19)
#define SOC_CRGPERIPH_PERSTAT11_ppll2_en_stat_START (20)
#define SOC_CRGPERIPH_PERSTAT11_ppll2_en_stat_END (20)
#define SOC_CRGPERIPH_PERSTAT11_ppll3_en_stat_START (21)
#define SOC_CRGPERIPH_PERSTAT11_ppll3_en_stat_END (21)
#define SOC_CRGPERIPH_PERSTAT11_ppll2_b_en_stat_START (22)
#define SOC_CRGPERIPH_PERSTAT11_ppll2_b_en_stat_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_i3c4 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_pclk_atgs_sys : 1;
        unsigned int gt_clk_modem_top : 1;
        unsigned int gt_clk_mdm_drx2dbg : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_clk_intr_hub : 1;
        unsigned int gt_clk_cpu_pctrl : 1;
        unsigned int gt_clk_npu_pctrl : 1;
        unsigned int gt_clk_media2_pctrl : 1;
        unsigned int gt_clk_media1_pctrl : 1;
        unsigned int gt_clk_hsdt0_pcmp_xctrl : 1;
        unsigned int gt_clk_hsdt1_pcmp_xctrl : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int gt_clk_dpctrl_16m : 1;
        unsigned int gt_clk_dpctrl_pixel : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 8;
    } reg;
} SOC_CRGPERIPH_PEREN12_UNION;
#endif
#define SOC_CRGPERIPH_PEREN12_gt_clk_i3c4_START (0)
#define SOC_CRGPERIPH_PEREN12_gt_clk_i3c4_END (0)
#define SOC_CRGPERIPH_PEREN12_gt_pclk_atgs_sys_START (3)
#define SOC_CRGPERIPH_PEREN12_gt_pclk_atgs_sys_END (3)
#define SOC_CRGPERIPH_PEREN12_gt_clk_modem_top_START (4)
#define SOC_CRGPERIPH_PEREN12_gt_clk_modem_top_END (4)
#define SOC_CRGPERIPH_PEREN12_gt_clk_mdm_drx2dbg_START (5)
#define SOC_CRGPERIPH_PEREN12_gt_clk_mdm_drx2dbg_END (5)
#define SOC_CRGPERIPH_PEREN12_gt_clk_intr_hub_START (8)
#define SOC_CRGPERIPH_PEREN12_gt_clk_intr_hub_END (8)
#define SOC_CRGPERIPH_PEREN12_gt_clk_cpu_pctrl_START (9)
#define SOC_CRGPERIPH_PEREN12_gt_clk_cpu_pctrl_END (9)
#define SOC_CRGPERIPH_PEREN12_gt_clk_npu_pctrl_START (10)
#define SOC_CRGPERIPH_PEREN12_gt_clk_npu_pctrl_END (10)
#define SOC_CRGPERIPH_PEREN12_gt_clk_media2_pctrl_START (11)
#define SOC_CRGPERIPH_PEREN12_gt_clk_media2_pctrl_END (11)
#define SOC_CRGPERIPH_PEREN12_gt_clk_media1_pctrl_START (12)
#define SOC_CRGPERIPH_PEREN12_gt_clk_media1_pctrl_END (12)
#define SOC_CRGPERIPH_PEREN12_gt_clk_hsdt0_pcmp_xctrl_START (13)
#define SOC_CRGPERIPH_PEREN12_gt_clk_hsdt0_pcmp_xctrl_END (13)
#define SOC_CRGPERIPH_PEREN12_gt_clk_hsdt1_pcmp_xctrl_START (14)
#define SOC_CRGPERIPH_PEREN12_gt_clk_hsdt1_pcmp_xctrl_END (14)
#define SOC_CRGPERIPH_PEREN12_gt_clk_dpctrl_16m_START (21)
#define SOC_CRGPERIPH_PEREN12_gt_clk_dpctrl_16m_END (21)
#define SOC_CRGPERIPH_PEREN12_gt_clk_dpctrl_pixel_START (22)
#define SOC_CRGPERIPH_PEREN12_gt_clk_dpctrl_pixel_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_i3c4 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_pclk_atgs_sys : 1;
        unsigned int gt_clk_modem_top : 1;
        unsigned int gt_clk_mdm_drx2dbg : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_clk_intr_hub : 1;
        unsigned int gt_clk_cpu_pctrl : 1;
        unsigned int gt_clk_npu_pctrl : 1;
        unsigned int gt_clk_media2_pctrl : 1;
        unsigned int gt_clk_media1_pctrl : 1;
        unsigned int gt_clk_hsdt0_pcmp_xctrl : 1;
        unsigned int gt_clk_hsdt1_pcmp_xctrl : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int gt_clk_dpctrl_16m : 1;
        unsigned int gt_clk_dpctrl_pixel : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 8;
    } reg;
} SOC_CRGPERIPH_PERDIS12_UNION;
#endif
#define SOC_CRGPERIPH_PERDIS12_gt_clk_i3c4_START (0)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_i3c4_END (0)
#define SOC_CRGPERIPH_PERDIS12_gt_pclk_atgs_sys_START (3)
#define SOC_CRGPERIPH_PERDIS12_gt_pclk_atgs_sys_END (3)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_modem_top_START (4)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_modem_top_END (4)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_mdm_drx2dbg_START (5)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_mdm_drx2dbg_END (5)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_intr_hub_START (8)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_intr_hub_END (8)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_cpu_pctrl_START (9)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_cpu_pctrl_END (9)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_npu_pctrl_START (10)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_npu_pctrl_END (10)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_media2_pctrl_START (11)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_media2_pctrl_END (11)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_media1_pctrl_START (12)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_media1_pctrl_END (12)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_hsdt0_pcmp_xctrl_START (13)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_hsdt0_pcmp_xctrl_END (13)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_hsdt1_pcmp_xctrl_START (14)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_hsdt1_pcmp_xctrl_END (14)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_dpctrl_16m_START (21)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_dpctrl_16m_END (21)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_dpctrl_pixel_START (22)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_dpctrl_pixel_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_i3c4 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_pclk_atgs_sys : 1;
        unsigned int gt_clk_modem_top : 1;
        unsigned int gt_clk_mdm_drx2dbg : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_clk_intr_hub : 1;
        unsigned int gt_clk_cpu_pctrl : 1;
        unsigned int gt_clk_npu_pctrl : 1;
        unsigned int gt_clk_media2_pctrl : 1;
        unsigned int gt_clk_media1_pctrl : 1;
        unsigned int gt_clk_hsdt0_pcmp_xctrl : 1;
        unsigned int gt_clk_hsdt1_pcmp_xctrl : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int gt_clk_dpctrl_16m : 1;
        unsigned int gt_clk_dpctrl_pixel : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 8;
    } reg;
} SOC_CRGPERIPH_PERCLKEN12_UNION;
#endif
#define SOC_CRGPERIPH_PERCLKEN12_gt_clk_i3c4_START (0)
#define SOC_CRGPERIPH_PERCLKEN12_gt_clk_i3c4_END (0)
#define SOC_CRGPERIPH_PERCLKEN12_gt_pclk_atgs_sys_START (3)
#define SOC_CRGPERIPH_PERCLKEN12_gt_pclk_atgs_sys_END (3)
#define SOC_CRGPERIPH_PERCLKEN12_gt_clk_modem_top_START (4)
#define SOC_CRGPERIPH_PERCLKEN12_gt_clk_modem_top_END (4)
#define SOC_CRGPERIPH_PERCLKEN12_gt_clk_mdm_drx2dbg_START (5)
#define SOC_CRGPERIPH_PERCLKEN12_gt_clk_mdm_drx2dbg_END (5)
#define SOC_CRGPERIPH_PERCLKEN12_gt_clk_intr_hub_START (8)
#define SOC_CRGPERIPH_PERCLKEN12_gt_clk_intr_hub_END (8)
#define SOC_CRGPERIPH_PERCLKEN12_gt_clk_cpu_pctrl_START (9)
#define SOC_CRGPERIPH_PERCLKEN12_gt_clk_cpu_pctrl_END (9)
#define SOC_CRGPERIPH_PERCLKEN12_gt_clk_npu_pctrl_START (10)
#define SOC_CRGPERIPH_PERCLKEN12_gt_clk_npu_pctrl_END (10)
#define SOC_CRGPERIPH_PERCLKEN12_gt_clk_media2_pctrl_START (11)
#define SOC_CRGPERIPH_PERCLKEN12_gt_clk_media2_pctrl_END (11)
#define SOC_CRGPERIPH_PERCLKEN12_gt_clk_media1_pctrl_START (12)
#define SOC_CRGPERIPH_PERCLKEN12_gt_clk_media1_pctrl_END (12)
#define SOC_CRGPERIPH_PERCLKEN12_gt_clk_hsdt0_pcmp_xctrl_START (13)
#define SOC_CRGPERIPH_PERCLKEN12_gt_clk_hsdt0_pcmp_xctrl_END (13)
#define SOC_CRGPERIPH_PERCLKEN12_gt_clk_hsdt1_pcmp_xctrl_START (14)
#define SOC_CRGPERIPH_PERCLKEN12_gt_clk_hsdt1_pcmp_xctrl_END (14)
#define SOC_CRGPERIPH_PERCLKEN12_gt_clk_dpctrl_16m_START (21)
#define SOC_CRGPERIPH_PERCLKEN12_gt_clk_dpctrl_16m_END (21)
#define SOC_CRGPERIPH_PERCLKEN12_gt_clk_dpctrl_pixel_START (22)
#define SOC_CRGPERIPH_PERCLKEN12_gt_clk_dpctrl_pixel_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_i3c4 : 1;
        unsigned int reserved_0 : 1;
        unsigned int st_clk_modem_ref32k : 1;
        unsigned int st_pclk_atgs_sys : 1;
        unsigned int st_clk_modem_top : 1;
        unsigned int st_clk_mdm_drx2dbg : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int st_clk_intr_hub : 1;
        unsigned int st_clk_cpu_pctrl : 1;
        unsigned int st_clk_npu_pctrl : 1;
        unsigned int st_clk_media2_pctrl : 1;
        unsigned int st_clk_media1_pctrl : 1;
        unsigned int st_clk_hsdt0_pcmp_xctrl : 1;
        unsigned int st_clk_hsdt1_pcmp_xctrl : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int st_clk_dpctrl_16m : 1;
        unsigned int st_clk_dpctrl_pixel : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 8;
    } reg;
} SOC_CRGPERIPH_PERSTAT12_UNION;
#endif
#define SOC_CRGPERIPH_PERSTAT12_st_clk_i3c4_START (0)
#define SOC_CRGPERIPH_PERSTAT12_st_clk_i3c4_END (0)
#define SOC_CRGPERIPH_PERSTAT12_st_clk_modem_ref32k_START (2)
#define SOC_CRGPERIPH_PERSTAT12_st_clk_modem_ref32k_END (2)
#define SOC_CRGPERIPH_PERSTAT12_st_pclk_atgs_sys_START (3)
#define SOC_CRGPERIPH_PERSTAT12_st_pclk_atgs_sys_END (3)
#define SOC_CRGPERIPH_PERSTAT12_st_clk_modem_top_START (4)
#define SOC_CRGPERIPH_PERSTAT12_st_clk_modem_top_END (4)
#define SOC_CRGPERIPH_PERSTAT12_st_clk_mdm_drx2dbg_START (5)
#define SOC_CRGPERIPH_PERSTAT12_st_clk_mdm_drx2dbg_END (5)
#define SOC_CRGPERIPH_PERSTAT12_st_clk_intr_hub_START (8)
#define SOC_CRGPERIPH_PERSTAT12_st_clk_intr_hub_END (8)
#define SOC_CRGPERIPH_PERSTAT12_st_clk_cpu_pctrl_START (9)
#define SOC_CRGPERIPH_PERSTAT12_st_clk_cpu_pctrl_END (9)
#define SOC_CRGPERIPH_PERSTAT12_st_clk_npu_pctrl_START (10)
#define SOC_CRGPERIPH_PERSTAT12_st_clk_npu_pctrl_END (10)
#define SOC_CRGPERIPH_PERSTAT12_st_clk_media2_pctrl_START (11)
#define SOC_CRGPERIPH_PERSTAT12_st_clk_media2_pctrl_END (11)
#define SOC_CRGPERIPH_PERSTAT12_st_clk_media1_pctrl_START (12)
#define SOC_CRGPERIPH_PERSTAT12_st_clk_media1_pctrl_END (12)
#define SOC_CRGPERIPH_PERSTAT12_st_clk_hsdt0_pcmp_xctrl_START (13)
#define SOC_CRGPERIPH_PERSTAT12_st_clk_hsdt0_pcmp_xctrl_END (13)
#define SOC_CRGPERIPH_PERSTAT12_st_clk_hsdt1_pcmp_xctrl_START (14)
#define SOC_CRGPERIPH_PERSTAT12_st_clk_hsdt1_pcmp_xctrl_END (14)
#define SOC_CRGPERIPH_PERSTAT12_st_clk_dpctrl_16m_START (21)
#define SOC_CRGPERIPH_PERSTAT12_st_clk_dpctrl_16m_END (21)
#define SOC_CRGPERIPH_PERSTAT12_st_clk_dpctrl_pixel_START (22)
#define SOC_CRGPERIPH_PERSTAT12_st_clk_dpctrl_pixel_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_process_monitor_gpu : 1;
        unsigned int gt_clk_process_monitor_npu : 1;
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
        unsigned int reserved_14 : 16;
    } reg;
} SOC_CRGPERIPH_PEREN13_UNION;
#endif
#define SOC_CRGPERIPH_PEREN13_gt_clk_process_monitor_gpu_START (0)
#define SOC_CRGPERIPH_PEREN13_gt_clk_process_monitor_gpu_END (0)
#define SOC_CRGPERIPH_PEREN13_gt_clk_process_monitor_npu_START (1)
#define SOC_CRGPERIPH_PEREN13_gt_clk_process_monitor_npu_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_process_monitor_gpu : 1;
        unsigned int gt_clk_process_monitor_npu : 1;
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
        unsigned int reserved_14 : 16;
    } reg;
} SOC_CRGPERIPH_PERDIS13_UNION;
#endif
#define SOC_CRGPERIPH_PERDIS13_gt_clk_process_monitor_gpu_START (0)
#define SOC_CRGPERIPH_PERDIS13_gt_clk_process_monitor_gpu_END (0)
#define SOC_CRGPERIPH_PERDIS13_gt_clk_process_monitor_npu_START (1)
#define SOC_CRGPERIPH_PERDIS13_gt_clk_process_monitor_npu_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_process_monitor_gpu : 1;
        unsigned int gt_clk_process_monitor_npu : 1;
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
        unsigned int reserved_14 : 16;
    } reg;
} SOC_CRGPERIPH_PERCLKEN13_UNION;
#endif
#define SOC_CRGPERIPH_PERCLKEN13_gt_clk_process_monitor_gpu_START (0)
#define SOC_CRGPERIPH_PERCLKEN13_gt_clk_process_monitor_gpu_END (0)
#define SOC_CRGPERIPH_PERCLKEN13_gt_clk_process_monitor_npu_START (1)
#define SOC_CRGPERIPH_PERCLKEN13_gt_clk_process_monitor_npu_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_process_monitor_gpu : 1;
        unsigned int st_clk_process_monitor_npu : 1;
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
        unsigned int reserved_14 : 16;
    } reg;
} SOC_CRGPERIPH_PERSTAT13_UNION;
#endif
#define SOC_CRGPERIPH_PERSTAT13_st_clk_process_monitor_gpu_START (0)
#define SOC_CRGPERIPH_PERSTAT13_st_clk_process_monitor_gpu_END (0)
#define SOC_CRGPERIPH_PERSTAT13_st_clk_process_monitor_npu_START (1)
#define SOC_CRGPERIPH_PERSTAT13_st_clk_process_monitor_npu_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int swdone_clk_periph_cpu_hc_div : 1;
        unsigned int swdone_clk_periph_cpu_lit_div : 1;
        unsigned int reserved : 1;
        unsigned int swdone_clk_ufs_subsys_hsdt1_div : 1;
        unsigned int swdone_clk_uart0_div : 1;
        unsigned int swdone_clk_uartl_div : 1;
        unsigned int swdone_clk_uarth_div : 1;
        unsigned int sw_ack_clk_pll_dmc_sw_d : 2;
        unsigned int sw_ack_clk_pll_dmc_sw_c : 2;
        unsigned int swdone_clk_noc_npubus_cfg_div : 1;
        unsigned int swdone_clk_cpu_gic_fll_div : 1;
        unsigned int swdone_clk_ddrc_sys_div : 1;
        unsigned int swdone_clk_sysbus_sys_div : 1;
        unsigned int swdone_clk_periph_cpu_fll_div : 1;
        unsigned int swdone_clk_ao_asp : 1;
        unsigned int swdone_clk_periph_cpu_lit_fll_div : 1;
        unsigned int swdone_clk_periph_cpu_hc_fll_div : 1;
        unsigned int swdone_clk_hisee_flash_div : 1;
        unsigned int sw_ack_clk_cpu_gic_fll_sw : 2;
        unsigned int sw_ack_clk_pll_dmc_sw_b : 2;
        unsigned int swdone_clk_ufs_dfa_sys_div : 1;
        unsigned int swdone_clk_ufs_dfa_cpu : 1;
        unsigned int swdone_clk_spi6_div : 1;
        unsigned int swdone_clk_dcdrbus_div : 1;
        unsigned int swdone_clk_core_crg_apb_div : 1;
        unsigned int swdone_clk_i3c4_div : 1;
        unsigned int swdone_clk_lpmcu_fll_div : 1;
        unsigned int swdone_clk_sysbus_fll_div : 1;
    } reg;
} SOC_CRGPERIPH_PERI_STAT4_UNION;
#endif
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_periph_cpu_hc_div_START (0)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_periph_cpu_hc_div_END (0)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_periph_cpu_lit_div_START (1)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_periph_cpu_lit_div_END (1)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_ufs_subsys_hsdt1_div_START (3)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_ufs_subsys_hsdt1_div_END (3)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_uart0_div_START (4)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_uart0_div_END (4)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_uartl_div_START (5)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_uartl_div_END (5)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_uarth_div_START (6)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_uarth_div_END (6)
#define SOC_CRGPERIPH_PERI_STAT4_sw_ack_clk_pll_dmc_sw_d_START (7)
#define SOC_CRGPERIPH_PERI_STAT4_sw_ack_clk_pll_dmc_sw_d_END (8)
#define SOC_CRGPERIPH_PERI_STAT4_sw_ack_clk_pll_dmc_sw_c_START (9)
#define SOC_CRGPERIPH_PERI_STAT4_sw_ack_clk_pll_dmc_sw_c_END (10)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_noc_npubus_cfg_div_START (11)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_noc_npubus_cfg_div_END (11)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_cpu_gic_fll_div_START (12)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_cpu_gic_fll_div_END (12)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_ddrc_sys_div_START (13)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_ddrc_sys_div_END (13)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_sysbus_sys_div_START (14)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_sysbus_sys_div_END (14)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_periph_cpu_fll_div_START (15)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_periph_cpu_fll_div_END (15)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_ao_asp_START (16)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_ao_asp_END (16)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_periph_cpu_lit_fll_div_START (17)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_periph_cpu_lit_fll_div_END (17)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_periph_cpu_hc_fll_div_START (18)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_periph_cpu_hc_fll_div_END (18)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_hisee_flash_div_START (19)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_hisee_flash_div_END (19)
#define SOC_CRGPERIPH_PERI_STAT4_sw_ack_clk_cpu_gic_fll_sw_START (20)
#define SOC_CRGPERIPH_PERI_STAT4_sw_ack_clk_cpu_gic_fll_sw_END (21)
#define SOC_CRGPERIPH_PERI_STAT4_sw_ack_clk_pll_dmc_sw_b_START (22)
#define SOC_CRGPERIPH_PERI_STAT4_sw_ack_clk_pll_dmc_sw_b_END (23)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_ufs_dfa_sys_div_START (24)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_ufs_dfa_sys_div_END (24)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_ufs_dfa_cpu_START (25)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_ufs_dfa_cpu_END (25)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_spi6_div_START (26)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_spi6_div_END (26)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_dcdrbus_div_START (27)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_dcdrbus_div_END (27)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_core_crg_apb_div_START (28)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_core_crg_apb_div_END (28)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_i3c4_div_START (29)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_i3c4_div_END (29)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_lpmcu_fll_div_START (30)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_lpmcu_fll_div_END (30)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_sysbus_fll_div_START (31)
#define SOC_CRGPERIPH_PERI_STAT4_swdone_clk_sysbus_fll_div_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_gpu_ppll0_div : 1;
        unsigned int st_clk_cpum_ppll0_div : 1;
        unsigned int swdone_clk_hsdt1_usbdp_div : 1;
        unsigned int sw_ack_clk_tscpu_peri_sw : 4;
        unsigned int sw_ack_clk_cpu_gic_sw : 3;
        unsigned int lpmcu_invar_sw_ack : 2;
        unsigned int sw_ack_clk_pll_dmc_sw_a : 2;
        unsigned int sw_ack_clk_ts_cpu_fll_sw : 2;
        unsigned int st_clk_fcm_ppll0_div : 1;
        unsigned int reserved : 1;
        unsigned int st_clk_sysbus_r : 1;
        unsigned int st_clk_sysbus_l : 1;
        unsigned int sw_ack_clk_core_crg_apb_sw : 3;
        unsigned int st_clk_dcdrbus_r : 1;
        unsigned int st_clk_dcdrbus_l : 1;
        unsigned int swdone_clk_hsdt1_usbdp_ulppll_div : 1;
        unsigned int st_clk_cpul_ppll0_div : 1;
        unsigned int st_clk_dcdrbus : 1;
        unsigned int sw_ack_clk_hsdt1_usbdp_sw : 2;
        unsigned int swdone_clk_dmc_sys_fll_div : 1;
        unsigned int swdone_clk_uart8_div : 1;
    } reg;
} SOC_CRGPERIPH_PERI_STAT5_UNION;
#endif
#define SOC_CRGPERIPH_PERI_STAT5_st_clk_gpu_ppll0_div_START (0)
#define SOC_CRGPERIPH_PERI_STAT5_st_clk_gpu_ppll0_div_END (0)
#define SOC_CRGPERIPH_PERI_STAT5_st_clk_cpum_ppll0_div_START (1)
#define SOC_CRGPERIPH_PERI_STAT5_st_clk_cpum_ppll0_div_END (1)
#define SOC_CRGPERIPH_PERI_STAT5_swdone_clk_hsdt1_usbdp_div_START (2)
#define SOC_CRGPERIPH_PERI_STAT5_swdone_clk_hsdt1_usbdp_div_END (2)
#define SOC_CRGPERIPH_PERI_STAT5_sw_ack_clk_tscpu_peri_sw_START (3)
#define SOC_CRGPERIPH_PERI_STAT5_sw_ack_clk_tscpu_peri_sw_END (6)
#define SOC_CRGPERIPH_PERI_STAT5_sw_ack_clk_cpu_gic_sw_START (7)
#define SOC_CRGPERIPH_PERI_STAT5_sw_ack_clk_cpu_gic_sw_END (9)
#define SOC_CRGPERIPH_PERI_STAT5_lpmcu_invar_sw_ack_START (10)
#define SOC_CRGPERIPH_PERI_STAT5_lpmcu_invar_sw_ack_END (11)
#define SOC_CRGPERIPH_PERI_STAT5_sw_ack_clk_pll_dmc_sw_a_START (12)
#define SOC_CRGPERIPH_PERI_STAT5_sw_ack_clk_pll_dmc_sw_a_END (13)
#define SOC_CRGPERIPH_PERI_STAT5_sw_ack_clk_ts_cpu_fll_sw_START (14)
#define SOC_CRGPERIPH_PERI_STAT5_sw_ack_clk_ts_cpu_fll_sw_END (15)
#define SOC_CRGPERIPH_PERI_STAT5_st_clk_fcm_ppll0_div_START (16)
#define SOC_CRGPERIPH_PERI_STAT5_st_clk_fcm_ppll0_div_END (16)
#define SOC_CRGPERIPH_PERI_STAT5_st_clk_sysbus_r_START (18)
#define SOC_CRGPERIPH_PERI_STAT5_st_clk_sysbus_r_END (18)
#define SOC_CRGPERIPH_PERI_STAT5_st_clk_sysbus_l_START (19)
#define SOC_CRGPERIPH_PERI_STAT5_st_clk_sysbus_l_END (19)
#define SOC_CRGPERIPH_PERI_STAT5_sw_ack_clk_core_crg_apb_sw_START (20)
#define SOC_CRGPERIPH_PERI_STAT5_sw_ack_clk_core_crg_apb_sw_END (22)
#define SOC_CRGPERIPH_PERI_STAT5_st_clk_dcdrbus_r_START (23)
#define SOC_CRGPERIPH_PERI_STAT5_st_clk_dcdrbus_r_END (23)
#define SOC_CRGPERIPH_PERI_STAT5_st_clk_dcdrbus_l_START (24)
#define SOC_CRGPERIPH_PERI_STAT5_st_clk_dcdrbus_l_END (24)
#define SOC_CRGPERIPH_PERI_STAT5_swdone_clk_hsdt1_usbdp_ulppll_div_START (25)
#define SOC_CRGPERIPH_PERI_STAT5_swdone_clk_hsdt1_usbdp_ulppll_div_END (25)
#define SOC_CRGPERIPH_PERI_STAT5_st_clk_cpul_ppll0_div_START (26)
#define SOC_CRGPERIPH_PERI_STAT5_st_clk_cpul_ppll0_div_END (26)
#define SOC_CRGPERIPH_PERI_STAT5_st_clk_dcdrbus_START (27)
#define SOC_CRGPERIPH_PERI_STAT5_st_clk_dcdrbus_END (27)
#define SOC_CRGPERIPH_PERI_STAT5_sw_ack_clk_hsdt1_usbdp_sw_START (28)
#define SOC_CRGPERIPH_PERI_STAT5_sw_ack_clk_hsdt1_usbdp_sw_END (29)
#define SOC_CRGPERIPH_PERI_STAT5_swdone_clk_dmc_sys_fll_div_START (30)
#define SOC_CRGPERIPH_PERI_STAT5_swdone_clk_dmc_sys_fll_div_END (30)
#define SOC_CRGPERIPH_PERI_STAT5_swdone_clk_uart8_div_START (31)
#define SOC_CRGPERIPH_PERI_STAT5_swdone_clk_uart8_div_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int st_clk_media2_pctrl_peri : 1;
        unsigned int st_clk_media1_pctrl_peri : 1;
        unsigned int st_clk_hsdt1_xctrl_peri : 1;
        unsigned int st_clk_hsdt0_xctrl_peri : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int st_pclk_i2c_bridge : 1;
        unsigned int st_clk_gpu_noc_peri : 1;
        unsigned int st_clk_ddrcssys : 1;
        unsigned int st_clk_perf_stat : 1;
        unsigned int st_pclk_codecssi : 1;
        unsigned int st_clk_npu_pctrl_peri : 1;
        unsigned int st_clk_ace0_mst_g3d : 1;
        unsigned int st_clk_perf_stat_peri : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int st_clk_ddr_lpctrl_h2x : 1;
        unsigned int sw_ack_clk_usb1_arb_sw : 2;
        unsigned int swdone_clk_usb1_arb_fll_div : 1;
        unsigned int reserved_8 : 4;
        unsigned int st_atclk_to_iomcu : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int st_atclk_mdm : 1;
    } reg;
} SOC_CRGPERIPH_PERI_STAT6_UNION;
#endif
#define SOC_CRGPERIPH_PERI_STAT6_st_clk_media2_pctrl_peri_START (2)
#define SOC_CRGPERIPH_PERI_STAT6_st_clk_media2_pctrl_peri_END (2)
#define SOC_CRGPERIPH_PERI_STAT6_st_clk_media1_pctrl_peri_START (3)
#define SOC_CRGPERIPH_PERI_STAT6_st_clk_media1_pctrl_peri_END (3)
#define SOC_CRGPERIPH_PERI_STAT6_st_clk_hsdt1_xctrl_peri_START (4)
#define SOC_CRGPERIPH_PERI_STAT6_st_clk_hsdt1_xctrl_peri_END (4)
#define SOC_CRGPERIPH_PERI_STAT6_st_clk_hsdt0_xctrl_peri_START (5)
#define SOC_CRGPERIPH_PERI_STAT6_st_clk_hsdt0_xctrl_peri_END (5)
#define SOC_CRGPERIPH_PERI_STAT6_st_pclk_i2c_bridge_START (9)
#define SOC_CRGPERIPH_PERI_STAT6_st_pclk_i2c_bridge_END (9)
#define SOC_CRGPERIPH_PERI_STAT6_st_clk_gpu_noc_peri_START (10)
#define SOC_CRGPERIPH_PERI_STAT6_st_clk_gpu_noc_peri_END (10)
#define SOC_CRGPERIPH_PERI_STAT6_st_clk_ddrcssys_START (11)
#define SOC_CRGPERIPH_PERI_STAT6_st_clk_ddrcssys_END (11)
#define SOC_CRGPERIPH_PERI_STAT6_st_clk_perf_stat_START (12)
#define SOC_CRGPERIPH_PERI_STAT6_st_clk_perf_stat_END (12)
#define SOC_CRGPERIPH_PERI_STAT6_st_pclk_codecssi_START (13)
#define SOC_CRGPERIPH_PERI_STAT6_st_pclk_codecssi_END (13)
#define SOC_CRGPERIPH_PERI_STAT6_st_clk_npu_pctrl_peri_START (14)
#define SOC_CRGPERIPH_PERI_STAT6_st_clk_npu_pctrl_peri_END (14)
#define SOC_CRGPERIPH_PERI_STAT6_st_clk_ace0_mst_g3d_START (15)
#define SOC_CRGPERIPH_PERI_STAT6_st_clk_ace0_mst_g3d_END (15)
#define SOC_CRGPERIPH_PERI_STAT6_st_clk_perf_stat_peri_START (16)
#define SOC_CRGPERIPH_PERI_STAT6_st_clk_perf_stat_peri_END (16)
#define SOC_CRGPERIPH_PERI_STAT6_st_clk_ddr_lpctrl_h2x_START (20)
#define SOC_CRGPERIPH_PERI_STAT6_st_clk_ddr_lpctrl_h2x_END (20)
#define SOC_CRGPERIPH_PERI_STAT6_sw_ack_clk_usb1_arb_sw_START (21)
#define SOC_CRGPERIPH_PERI_STAT6_sw_ack_clk_usb1_arb_sw_END (22)
#define SOC_CRGPERIPH_PERI_STAT6_swdone_clk_usb1_arb_fll_div_START (23)
#define SOC_CRGPERIPH_PERI_STAT6_swdone_clk_usb1_arb_fll_div_END (23)
#define SOC_CRGPERIPH_PERI_STAT6_st_atclk_to_iomcu_START (28)
#define SOC_CRGPERIPH_PERI_STAT6_st_atclk_to_iomcu_END (28)
#define SOC_CRGPERIPH_PERI_STAT6_st_atclk_mdm_START (31)
#define SOC_CRGPERIPH_PERI_STAT6_st_atclk_mdm_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sw_ack_clk_periph_cpu_sw : 2;
        unsigned int sw_ack_clk_periph_cpu_lit_sw : 2;
        unsigned int sw_ack_clk_periph_cpu_hc_sw : 2;
        unsigned int sw_ack_clk_dmc_sys_sw : 2;
        unsigned int reserved_0 : 4;
        unsigned int sw_ack_clk_ufs_dfa_sys : 3;
        unsigned int sw_ack_clk_ufs_dfa_cpu : 4;
        unsigned int sw_ack_clk_lpmcu_fll_sw : 2;
        unsigned int sw_ack_clk_ufs_dfa_cpu_post_sw : 2;
        unsigned int sw_ack_clk_ufs_dfa_sys_post_sw : 2;
        unsigned int reserved_1 : 1;
        unsigned int ppll6_sscg_idle : 1;
        unsigned int ppll7_sscg_idle : 1;
        unsigned int ppll3_sscg_idle : 1;
        unsigned int ppll2_b_sscg_idle : 1;
        unsigned int ppll2_sscg_idle : 1;
        unsigned int ppll1_sscg_idle : 1;
    } reg;
} SOC_CRGPERIPH_PERI_STAT7_UNION;
#endif
#define SOC_CRGPERIPH_PERI_STAT7_sw_ack_clk_periph_cpu_sw_START (0)
#define SOC_CRGPERIPH_PERI_STAT7_sw_ack_clk_periph_cpu_sw_END (1)
#define SOC_CRGPERIPH_PERI_STAT7_sw_ack_clk_periph_cpu_lit_sw_START (2)
#define SOC_CRGPERIPH_PERI_STAT7_sw_ack_clk_periph_cpu_lit_sw_END (3)
#define SOC_CRGPERIPH_PERI_STAT7_sw_ack_clk_periph_cpu_hc_sw_START (4)
#define SOC_CRGPERIPH_PERI_STAT7_sw_ack_clk_periph_cpu_hc_sw_END (5)
#define SOC_CRGPERIPH_PERI_STAT7_sw_ack_clk_dmc_sys_sw_START (6)
#define SOC_CRGPERIPH_PERI_STAT7_sw_ack_clk_dmc_sys_sw_END (7)
#define SOC_CRGPERIPH_PERI_STAT7_sw_ack_clk_ufs_dfa_sys_START (12)
#define SOC_CRGPERIPH_PERI_STAT7_sw_ack_clk_ufs_dfa_sys_END (14)
#define SOC_CRGPERIPH_PERI_STAT7_sw_ack_clk_ufs_dfa_cpu_START (15)
#define SOC_CRGPERIPH_PERI_STAT7_sw_ack_clk_ufs_dfa_cpu_END (18)
#define SOC_CRGPERIPH_PERI_STAT7_sw_ack_clk_lpmcu_fll_sw_START (19)
#define SOC_CRGPERIPH_PERI_STAT7_sw_ack_clk_lpmcu_fll_sw_END (20)
#define SOC_CRGPERIPH_PERI_STAT7_sw_ack_clk_ufs_dfa_cpu_post_sw_START (21)
#define SOC_CRGPERIPH_PERI_STAT7_sw_ack_clk_ufs_dfa_cpu_post_sw_END (22)
#define SOC_CRGPERIPH_PERI_STAT7_sw_ack_clk_ufs_dfa_sys_post_sw_START (23)
#define SOC_CRGPERIPH_PERI_STAT7_sw_ack_clk_ufs_dfa_sys_post_sw_END (24)
#define SOC_CRGPERIPH_PERI_STAT7_ppll6_sscg_idle_START (26)
#define SOC_CRGPERIPH_PERI_STAT7_ppll6_sscg_idle_END (26)
#define SOC_CRGPERIPH_PERI_STAT7_ppll7_sscg_idle_START (27)
#define SOC_CRGPERIPH_PERI_STAT7_ppll7_sscg_idle_END (27)
#define SOC_CRGPERIPH_PERI_STAT7_ppll3_sscg_idle_START (28)
#define SOC_CRGPERIPH_PERI_STAT7_ppll3_sscg_idle_END (28)
#define SOC_CRGPERIPH_PERI_STAT7_ppll2_b_sscg_idle_START (29)
#define SOC_CRGPERIPH_PERI_STAT7_ppll2_b_sscg_idle_END (29)
#define SOC_CRGPERIPH_PERI_STAT7_ppll2_sscg_idle_START (30)
#define SOC_CRGPERIPH_PERI_STAT7_ppll2_sscg_idle_END (30)
#define SOC_CRGPERIPH_PERI_STAT7_ppll1_sscg_idle_START (31)
#define SOC_CRGPERIPH_PERI_STAT7_ppll1_sscg_idle_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_mask_sysbus_nonidle_pend : 1;
        unsigned int intr_mask_cfgbus_nonidle_pend : 1;
        unsigned int reserved_0 : 1;
        unsigned int intr_mask_hsdt1bus_nonidle_pend : 1;
        unsigned int intr_mask_hsdtbus_nonidle_pend : 1;
        unsigned int intr_mask_gpubus_nonidle_pend : 1;
        unsigned int intr_mask_ddrxpu_nonidle_pend : 1;
        unsigned int intr_mask_npubus_nonidle_pend : 1;
        unsigned int intr_mask_fcmbus_nonidle_pend : 1;
        unsigned int intr_mask_m1bus_nonidle_pend : 1;
        unsigned int intr_mask_m2bus_nonidle_pend : 1;
        unsigned int reserved_1 : 5;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_INTR_MASK_NOCBUS_NONIDLE_PEND_UNION;
#endif
#define SOC_CRGPERIPH_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_sysbus_nonidle_pend_START (0)
#define SOC_CRGPERIPH_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_sysbus_nonidle_pend_END (0)
#define SOC_CRGPERIPH_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_cfgbus_nonidle_pend_START (1)
#define SOC_CRGPERIPH_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_cfgbus_nonidle_pend_END (1)
#define SOC_CRGPERIPH_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_hsdt1bus_nonidle_pend_START (3)
#define SOC_CRGPERIPH_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_hsdt1bus_nonidle_pend_END (3)
#define SOC_CRGPERIPH_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_hsdtbus_nonidle_pend_START (4)
#define SOC_CRGPERIPH_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_hsdtbus_nonidle_pend_END (4)
#define SOC_CRGPERIPH_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_gpubus_nonidle_pend_START (5)
#define SOC_CRGPERIPH_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_gpubus_nonidle_pend_END (5)
#define SOC_CRGPERIPH_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_ddrxpu_nonidle_pend_START (6)
#define SOC_CRGPERIPH_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_ddrxpu_nonidle_pend_END (6)
#define SOC_CRGPERIPH_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_npubus_nonidle_pend_START (7)
#define SOC_CRGPERIPH_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_npubus_nonidle_pend_END (7)
#define SOC_CRGPERIPH_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_fcmbus_nonidle_pend_START (8)
#define SOC_CRGPERIPH_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_fcmbus_nonidle_pend_END (8)
#define SOC_CRGPERIPH_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_m1bus_nonidle_pend_START (9)
#define SOC_CRGPERIPH_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_m1bus_nonidle_pend_END (9)
#define SOC_CRGPERIPH_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_m2bus_nonidle_pend_START (10)
#define SOC_CRGPERIPH_INTR_MASK_NOCBUS_NONIDLE_PEND_intr_mask_m2bus_nonidle_pend_END (10)
#define SOC_CRGPERIPH_INTR_MASK_NOCBUS_NONIDLE_PEND_bitmasken_START (16)
#define SOC_CRGPERIPH_INTR_MASK_NOCBUS_NONIDLE_PEND_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_clr_sysbus_nonidle_pend : 1;
        unsigned int intr_clr_cfgbus_nonidle_pend : 1;
        unsigned int reserved_0 : 1;
        unsigned int intr_clr_hsdt1bus_nonidle_pend : 1;
        unsigned int intr_clr_hsdtbus_nonidle_pend : 1;
        unsigned int intr_clr_gpubus_nonidle_pend : 1;
        unsigned int intr_clr_ddrxpu_nonidle_pend : 1;
        unsigned int intr_clr_npubus_nonidle_pend : 1;
        unsigned int intr_clr_fcmbus_nonidle_pend : 1;
        unsigned int intr_clr_m1bus_nonidle_pend : 1;
        unsigned int intr_clr_m2bus_nonidle_pend : 1;
        unsigned int reserved_1 : 5;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_INTR_CLR_NOCBUS_NONIDLE_PEND_UNION;
#endif
#define SOC_CRGPERIPH_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_sysbus_nonidle_pend_START (0)
#define SOC_CRGPERIPH_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_sysbus_nonidle_pend_END (0)
#define SOC_CRGPERIPH_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_cfgbus_nonidle_pend_START (1)
#define SOC_CRGPERIPH_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_cfgbus_nonidle_pend_END (1)
#define SOC_CRGPERIPH_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_hsdt1bus_nonidle_pend_START (3)
#define SOC_CRGPERIPH_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_hsdt1bus_nonidle_pend_END (3)
#define SOC_CRGPERIPH_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_hsdtbus_nonidle_pend_START (4)
#define SOC_CRGPERIPH_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_hsdtbus_nonidle_pend_END (4)
#define SOC_CRGPERIPH_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_gpubus_nonidle_pend_START (5)
#define SOC_CRGPERIPH_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_gpubus_nonidle_pend_END (5)
#define SOC_CRGPERIPH_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_ddrxpu_nonidle_pend_START (6)
#define SOC_CRGPERIPH_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_ddrxpu_nonidle_pend_END (6)
#define SOC_CRGPERIPH_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_npubus_nonidle_pend_START (7)
#define SOC_CRGPERIPH_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_npubus_nonidle_pend_END (7)
#define SOC_CRGPERIPH_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_fcmbus_nonidle_pend_START (8)
#define SOC_CRGPERIPH_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_fcmbus_nonidle_pend_END (8)
#define SOC_CRGPERIPH_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_m1bus_nonidle_pend_START (9)
#define SOC_CRGPERIPH_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_m1bus_nonidle_pend_END (9)
#define SOC_CRGPERIPH_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_m2bus_nonidle_pend_START (10)
#define SOC_CRGPERIPH_INTR_CLR_NOCBUS_NONIDLE_PEND_intr_clr_m2bus_nonidle_pend_END (10)
#define SOC_CRGPERIPH_INTR_CLR_NOCBUS_NONIDLE_PEND_bitmasken_START (16)
#define SOC_CRGPERIPH_INTR_CLR_NOCBUS_NONIDLE_PEND_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_stat_sysbus_nonidle_pend : 1;
        unsigned int intr_stat_cfgbus_nonidle_pend : 1;
        unsigned int reserved_0 : 1;
        unsigned int intr_stat_hsdt1bus_nonidle_pend : 1;
        unsigned int intr_stat_hsdtbus_nonidle_pend : 1;
        unsigned int intr_stat_mediabus_nonidle_pend : 1;
        unsigned int intr_stat_media2bus_nonidle_pend : 1;
        unsigned int intr_stat_gpubus_nonidle_pend : 1;
        unsigned int intr_stat_ddrxpu_nonidle_pend : 1;
        unsigned int intr_stat_ao_nocbus_nonidle_pend : 1;
        unsigned int intr_stat_npubus_nonidle_pend : 1;
        unsigned int intr_stat_npuip_nonidle_pend : 1;
        unsigned int intr_stat_hsdt1ip_nonidle_pend : 1;
        unsigned int intr_stat_hsdtip_nonidle_pend : 1;
        unsigned int intr_stat_fcmbus_nonidle_pend : 1;
        unsigned int intr_stat_m1bus_nonidle_pend : 1;
        unsigned int intr_stat_m2bus_nonidle_pend : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_UNION;
#endif
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_sysbus_nonidle_pend_START (0)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_sysbus_nonidle_pend_END (0)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_cfgbus_nonidle_pend_START (1)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_cfgbus_nonidle_pend_END (1)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_hsdt1bus_nonidle_pend_START (3)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_hsdt1bus_nonidle_pend_END (3)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_hsdtbus_nonidle_pend_START (4)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_hsdtbus_nonidle_pend_END (4)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_mediabus_nonidle_pend_START (5)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_mediabus_nonidle_pend_END (5)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_media2bus_nonidle_pend_START (6)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_media2bus_nonidle_pend_END (6)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_gpubus_nonidle_pend_START (7)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_gpubus_nonidle_pend_END (7)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_ddrxpu_nonidle_pend_START (8)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_ddrxpu_nonidle_pend_END (8)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_ao_nocbus_nonidle_pend_START (9)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_ao_nocbus_nonidle_pend_END (9)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_npubus_nonidle_pend_START (10)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_npubus_nonidle_pend_END (10)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_npuip_nonidle_pend_START (11)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_npuip_nonidle_pend_END (11)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_hsdt1ip_nonidle_pend_START (12)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_hsdt1ip_nonidle_pend_END (12)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_hsdtip_nonidle_pend_START (13)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_hsdtip_nonidle_pend_END (13)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_fcmbus_nonidle_pend_START (14)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_fcmbus_nonidle_pend_END (14)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_m1bus_nonidle_pend_START (15)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_m1bus_nonidle_pend_END (15)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_m2bus_nonidle_pend_START (16)
#define SOC_CRGPERIPH_INTR_STAT_NOCBUS_NONIDLE_PEND_intr_stat_m2bus_nonidle_pend_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int func_global_clk_en : 32;
    } reg;
} SOC_CRGPERIPH_DFT_FUNC_GLOBAL_CLK_EN_UNION;
#endif
#define SOC_CRGPERIPH_DFT_FUNC_GLOBAL_CLK_EN_func_global_clk_en_START (0)
#define SOC_CRGPERIPH_DFT_FUNC_GLOBAL_CLK_EN_func_global_clk_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 4;
        unsigned int sw_ack_clk_ai_core_sw : 2;
        unsigned int sw_ack_clk_core_crg_apb_fll_sw : 2;
        unsigned int reserved_2 : 4;
        unsigned int reserved_3 : 3;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 4;
        unsigned int reserved_6 : 3;
        unsigned int sw_ack_clk_sysbus_fll_sw : 2;
        unsigned int swdone_clk_ddrc_fll_div : 1;
        unsigned int sw_ack_clk_ddrc_fll_sw : 2;
    } reg;
} SOC_CRGPERIPH_PERI_STAT8_UNION;
#endif
#define SOC_CRGPERIPH_PERI_STAT8_sw_ack_clk_ai_core_sw_START (8)
#define SOC_CRGPERIPH_PERI_STAT8_sw_ack_clk_ai_core_sw_END (9)
#define SOC_CRGPERIPH_PERI_STAT8_sw_ack_clk_core_crg_apb_fll_sw_START (10)
#define SOC_CRGPERIPH_PERI_STAT8_sw_ack_clk_core_crg_apb_fll_sw_END (11)
#define SOC_CRGPERIPH_PERI_STAT8_sw_ack_clk_sysbus_fll_sw_START (27)
#define SOC_CRGPERIPH_PERI_STAT8_sw_ack_clk_sysbus_fll_sw_END (28)
#define SOC_CRGPERIPH_PERI_STAT8_swdone_clk_ddrc_fll_div_START (29)
#define SOC_CRGPERIPH_PERI_STAT8_swdone_clk_ddrc_fll_div_END (29)
#define SOC_CRGPERIPH_PERI_STAT8_sw_ack_clk_ddrc_fll_sw_START (30)
#define SOC_CRGPERIPH_PERI_STAT8_sw_ack_clk_ddrc_fll_sw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 4;
        unsigned int reserved_3 : 4;
        unsigned int reserved_4 : 4;
        unsigned int reserved_5 : 1;
        unsigned int swdone_clk_hpm_h_div : 1;
        unsigned int swdone_clk_qice_cfg_div : 1;
        unsigned int swdone_clk_cssysdbg_div : 1;
        unsigned int swdone_clk_syscache_cfg_a : 1;
        unsigned int swdone_clk_syscache_cfg_b : 1;
        unsigned int swdone_clk_syscache_cfg_c : 1;
        unsigned int swdone_clk_syscache_cfg_d : 1;
        unsigned int swdone_clk_ffts_div : 1;
        unsigned int sw_ack_clk_ddrc_sys_sw : 2;
        unsigned int sw_ack_clk_lpmcu_invar_fll_sw : 2;
        unsigned int swdone_clk_lpmcu_invar_fll_div : 1;
        unsigned int swdone_clk_sd_peri_div : 1;
        unsigned int reserved_6 : 1;
    } reg;
} SOC_CRGPERIPH_PERI_STAT9_UNION;
#endif
#define SOC_CRGPERIPH_PERI_STAT9_swdone_clk_hpm_h_div_START (17)
#define SOC_CRGPERIPH_PERI_STAT9_swdone_clk_hpm_h_div_END (17)
#define SOC_CRGPERIPH_PERI_STAT9_swdone_clk_qice_cfg_div_START (18)
#define SOC_CRGPERIPH_PERI_STAT9_swdone_clk_qice_cfg_div_END (18)
#define SOC_CRGPERIPH_PERI_STAT9_swdone_clk_cssysdbg_div_START (19)
#define SOC_CRGPERIPH_PERI_STAT9_swdone_clk_cssysdbg_div_END (19)
#define SOC_CRGPERIPH_PERI_STAT9_swdone_clk_syscache_cfg_a_START (20)
#define SOC_CRGPERIPH_PERI_STAT9_swdone_clk_syscache_cfg_a_END (20)
#define SOC_CRGPERIPH_PERI_STAT9_swdone_clk_syscache_cfg_b_START (21)
#define SOC_CRGPERIPH_PERI_STAT9_swdone_clk_syscache_cfg_b_END (21)
#define SOC_CRGPERIPH_PERI_STAT9_swdone_clk_syscache_cfg_c_START (22)
#define SOC_CRGPERIPH_PERI_STAT9_swdone_clk_syscache_cfg_c_END (22)
#define SOC_CRGPERIPH_PERI_STAT9_swdone_clk_syscache_cfg_d_START (23)
#define SOC_CRGPERIPH_PERI_STAT9_swdone_clk_syscache_cfg_d_END (23)
#define SOC_CRGPERIPH_PERI_STAT9_swdone_clk_ffts_div_START (24)
#define SOC_CRGPERIPH_PERI_STAT9_swdone_clk_ffts_div_END (24)
#define SOC_CRGPERIPH_PERI_STAT9_sw_ack_clk_ddrc_sys_sw_START (25)
#define SOC_CRGPERIPH_PERI_STAT9_sw_ack_clk_ddrc_sys_sw_END (26)
#define SOC_CRGPERIPH_PERI_STAT9_sw_ack_clk_lpmcu_invar_fll_sw_START (27)
#define SOC_CRGPERIPH_PERI_STAT9_sw_ack_clk_lpmcu_invar_fll_sw_END (28)
#define SOC_CRGPERIPH_PERI_STAT9_swdone_clk_lpmcu_invar_fll_div_START (29)
#define SOC_CRGPERIPH_PERI_STAT9_swdone_clk_lpmcu_invar_fll_div_END (29)
#define SOC_CRGPERIPH_PERI_STAT9_swdone_clk_sd_peri_div_START (30)
#define SOC_CRGPERIPH_PERI_STAT9_swdone_clk_sd_peri_div_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hw_dss_dvfs_pll_gt0 : 1;
        unsigned int hw_dss_dvfs_pll_gt1 : 1;
        unsigned int hw_dss_dvfs_pll_gt2 : 1;
        unsigned int hw_dss_dvfs_pll_gt3 : 1;
        unsigned int hw_dss_dvfs_pll_en0 : 1;
        unsigned int reserved_0 : 1;
        unsigned int hw_dss_dvfs_pll_en2 : 1;
        unsigned int hw_dss_dvfs_pll_en3 : 1;
        unsigned int hw_dss_dvfs_pll_lock0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int hw_dss_dvfs_pll_lock2 : 1;
        unsigned int hw_dss_dvfs_pll_lock3 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 16;
    } reg;
} SOC_CRGPERIPH_HW_DSS_DVFS_STAT_UNION;
#endif
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_gt0_START (0)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_gt0_END (0)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_gt1_START (1)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_gt1_END (1)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_gt2_START (2)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_gt2_END (2)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_gt3_START (3)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_gt3_END (3)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_en0_START (4)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_en0_END (4)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_en2_START (6)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_en2_END (6)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_en3_START (7)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_en3_END (7)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_lock0_START (8)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_lock0_END (8)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_lock2_START (10)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_lock2_END (10)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_lock3_START (11)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_lock3_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ufs_dfa_sys_idle_bypass : 1;
        unsigned int ufs_dfa_sys_idle_waitcfg_in : 10;
        unsigned int ufs_dfa_sys_idle_waitcfg_out : 10;
        unsigned int ufs_dfa_sys_div_auto_cfg : 6;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
    } reg;
} SOC_CRGPERIPH_PERI_AUTODIV1_UNION;
#endif
#define SOC_CRGPERIPH_PERI_AUTODIV1_ufs_dfa_sys_idle_bypass_START (0)
#define SOC_CRGPERIPH_PERI_AUTODIV1_ufs_dfa_sys_idle_bypass_END (0)
#define SOC_CRGPERIPH_PERI_AUTODIV1_ufs_dfa_sys_idle_waitcfg_in_START (1)
#define SOC_CRGPERIPH_PERI_AUTODIV1_ufs_dfa_sys_idle_waitcfg_in_END (10)
#define SOC_CRGPERIPH_PERI_AUTODIV1_ufs_dfa_sys_idle_waitcfg_out_START (11)
#define SOC_CRGPERIPH_PERI_AUTODIV1_ufs_dfa_sys_idle_waitcfg_out_END (20)
#define SOC_CRGPERIPH_PERI_AUTODIV1_ufs_dfa_sys_div_auto_cfg_START (21)
#define SOC_CRGPERIPH_PERI_AUTODIV1_ufs_dfa_sys_div_auto_cfg_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 10;
        unsigned int reserved_2: 10;
        unsigned int reserved_3: 6;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
    } reg;
} SOC_CRGPERIPH_PERI_AUTODIV2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_atgc : 4;
        unsigned int dfa_cpu_autogt_bypass : 1;
        unsigned int div_sd_peri : 4;
        unsigned int reserved_0 : 5;
        unsigned int reserved_1 : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV26_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV26_div_atgc_START (0)
#define SOC_CRGPERIPH_CLKDIV26_div_atgc_END (3)
#define SOC_CRGPERIPH_CLKDIV26_dfa_cpu_autogt_bypass_START (4)
#define SOC_CRGPERIPH_CLKDIV26_dfa_cpu_autogt_bypass_END (4)
#define SOC_CRGPERIPH_CLKDIV26_div_sd_peri_START (5)
#define SOC_CRGPERIPH_CLKDIV26_div_sd_peri_END (8)
#define SOC_CRGPERIPH_CLKDIV26_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV26_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 2;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 12;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV27_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV27_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV27_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 4;
        unsigned int reserved_1: 4;
        unsigned int reserved_2: 4;
        unsigned int reserved_3: 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV28_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV28_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV28_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int sc_gt_clk_hsdt1_usbdp : 1;
        unsigned int sc_gt_clk_hpm_h : 1;
        unsigned int reserved_2 : 1;
        unsigned int sc_gt_clk_i3c4 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int sc_gt_clk_sd_peri : 1;
        unsigned int reserved_7 : 1;
        unsigned int sc_gt_clk_hsdt1_usbdp_ulppll : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV29_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV29_sc_gt_clk_hsdt1_usbdp_START (2)
#define SOC_CRGPERIPH_CLKDIV29_sc_gt_clk_hsdt1_usbdp_END (2)
#define SOC_CRGPERIPH_CLKDIV29_sc_gt_clk_hpm_h_START (3)
#define SOC_CRGPERIPH_CLKDIV29_sc_gt_clk_hpm_h_END (3)
#define SOC_CRGPERIPH_CLKDIV29_sc_gt_clk_i3c4_START (5)
#define SOC_CRGPERIPH_CLKDIV29_sc_gt_clk_i3c4_END (5)
#define SOC_CRGPERIPH_CLKDIV29_sc_gt_clk_sd_peri_START (10)
#define SOC_CRGPERIPH_CLKDIV29_sc_gt_clk_sd_peri_END (10)
#define SOC_CRGPERIPH_CLKDIV29_sc_gt_clk_hsdt1_usbdp_ulppll_START (12)
#define SOC_CRGPERIPH_CLKDIV29_sc_gt_clk_hsdt1_usbdp_ulppll_END (12)
#define SOC_CRGPERIPH_CLKDIV29_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV29_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_usbdp : 4;
        unsigned int reserved_0 : 4;
        unsigned int div_usbdp_ulppll : 2;
        unsigned int div_i3c4 : 2;
        unsigned int reserved_1 : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV30_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV30_div_usbdp_START (0)
#define SOC_CRGPERIPH_CLKDIV30_div_usbdp_END (3)
#define SOC_CRGPERIPH_CLKDIV30_div_usbdp_ulppll_START (8)
#define SOC_CRGPERIPH_CLKDIV30_div_usbdp_ulppll_END (9)
#define SOC_CRGPERIPH_CLKDIV30_div_i3c4_START (10)
#define SOC_CRGPERIPH_CLKDIV30_div_i3c4_END (11)
#define SOC_CRGPERIPH_CLKDIV30_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV30_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 4;
        unsigned int reserved_1: 4;
        unsigned int reserved_2: 4;
        unsigned int div_hpm_h : 2;
        unsigned int reserved_3: 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV31_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV31_div_hpm_h_START (12)
#define SOC_CRGPERIPH_CLKDIV31_div_hpm_h_END (13)
#define SOC_CRGPERIPH_CLKDIV31_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV31_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sel_sdcu : 1;
        unsigned int div_sdcu : 2;
        unsigned int sc_gt_clk_sdcu : 1;
        unsigned int sc_gt_clk_mon : 1;
        unsigned int div_lat_mon : 6;
        unsigned int reserved : 5;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_CLKDIV32_UNION;
#endif
#define SOC_CRGPERIPH_CLKDIV32_sel_sdcu_START (0)
#define SOC_CRGPERIPH_CLKDIV32_sel_sdcu_END (0)
#define SOC_CRGPERIPH_CLKDIV32_div_sdcu_START (1)
#define SOC_CRGPERIPH_CLKDIV32_div_sdcu_END (2)
#define SOC_CRGPERIPH_CLKDIV32_sc_gt_clk_sdcu_START (3)
#define SOC_CRGPERIPH_CLKDIV32_sc_gt_clk_sdcu_END (3)
#define SOC_CRGPERIPH_CLKDIV32_sc_gt_clk_mon_START (4)
#define SOC_CRGPERIPH_CLKDIV32_sc_gt_clk_mon_END (4)
#define SOC_CRGPERIPH_CLKDIV32_div_lat_mon_START (5)
#define SOC_CRGPERIPH_CLKDIV32_div_lat_mon_END (10)
#define SOC_CRGPERIPH_CLKDIV32_bitmasken_START (16)
#define SOC_CRGPERIPH_CLKDIV32_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int dvfs_gate_ctrl_cpul_bypass : 1;
        unsigned int dvfs_gate_ctrl_cpum_bypass : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 5;
        unsigned int dvfs_gate_ctrl_fcm_bypass : 1;
        unsigned int dvfs_gate_ctrl_gpu_bypass : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 3;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PERI_COMMON_CTRL0_UNION;
#endif
#define SOC_CRGPERIPH_PERI_COMMON_CTRL0_dvfs_gate_ctrl_cpul_bypass_START (2)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL0_dvfs_gate_ctrl_cpul_bypass_END (2)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL0_dvfs_gate_ctrl_cpum_bypass_START (3)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL0_dvfs_gate_ctrl_cpum_bypass_END (3)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL0_dvfs_gate_ctrl_fcm_bypass_START (10)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL0_dvfs_gate_ctrl_fcm_bypass_END (10)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL0_dvfs_gate_ctrl_gpu_bypass_START (11)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL0_dvfs_gate_ctrl_gpu_bypass_END (11)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL0_bitmasken_START (16)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddrc_autogt_bypass_lpmcu : 1;
        unsigned int ddrc_autogt_bypass_acpu_l_0 : 1;
        unsigned int ddrc_autogt_bypass_acpu_l_1 : 1;
        unsigned int ddrc_autogt_bypass_acpu_l_2 : 1;
        unsigned int ddrc_autogt_bypass_acpu_l_3 : 1;
        unsigned int ddrc_autogt_bypass_acpu_b_0 : 1;
        unsigned int ddrc_autogt_bypass_acpu_b_1 : 1;
        unsigned int ddrc_autogt_bypass_acpu_b_2 : 1;
        unsigned int ddrc_autogt_bypass_acpu_b_3 : 1;
        unsigned int ddrc_autogt_bypass_ccpu : 1;
        unsigned int ddrc_autogt_bypass_mdm_bbe0 : 1;
        unsigned int ddrc_autogt_bypass_mdm_bbe1 : 1;
        unsigned int ddrc_autogt_bypass_mdm_bbe2 : 1;
        unsigned int ddrc_autogt_bypass_other_cpu0 : 1;
        unsigned int ddrc_autogt_bypass_other_cpu1 : 1;
        unsigned int ddrc_autogt_bypass_other_cpu2 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PERI_COMMON_CTRL1_UNION;
#endif
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_lpmcu_START (0)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_lpmcu_END (0)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_acpu_l_0_START (1)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_acpu_l_0_END (1)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_acpu_l_1_START (2)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_acpu_l_1_END (2)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_acpu_l_2_START (3)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_acpu_l_2_END (3)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_acpu_l_3_START (4)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_acpu_l_3_END (4)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_acpu_b_0_START (5)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_acpu_b_0_END (5)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_acpu_b_1_START (6)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_acpu_b_1_END (6)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_acpu_b_2_START (7)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_acpu_b_2_END (7)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_acpu_b_3_START (8)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_acpu_b_3_END (8)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_ccpu_START (9)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_ccpu_END (9)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_mdm_bbe0_START (10)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_mdm_bbe0_END (10)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_mdm_bbe1_START (11)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_mdm_bbe1_END (11)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_mdm_bbe2_START (12)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_mdm_bbe2_END (12)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_other_cpu0_START (13)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_other_cpu0_END (13)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_other_cpu1_START (14)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_other_cpu1_END (14)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_other_cpu2_START (15)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_ddrc_autogt_bypass_other_cpu2_END (15)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_bitmasken_START (16)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL1_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddrsys_autogt_bypass_lpmcu : 1;
        unsigned int ddrsys_autogt_bypass_acpu_l_0 : 1;
        unsigned int ddrsys_autogt_bypass_acpu_l_1 : 1;
        unsigned int ddrsys_autogt_bypass_acpu_l_2 : 1;
        unsigned int ddrsys_autogt_bypass_acpu_l_3 : 1;
        unsigned int ddrsys_autogt_bypass_acpu_b_0 : 1;
        unsigned int ddrsys_autogt_bypass_acpu_b_1 : 1;
        unsigned int ddrsys_autogt_bypass_acpu_b_2 : 1;
        unsigned int ddrsys_autogt_bypass_acpu_b_3 : 1;
        unsigned int ddrsys_autogt_bypass_ccpu : 1;
        unsigned int ddrsys_autogt_bypass_mdm_bbe0 : 1;
        unsigned int ddrsys_autogt_bypass_mdm_bbe1 : 1;
        unsigned int ddrsys_autogt_bypass_mdm_bbe2 : 1;
        unsigned int ddrsys_autogt_bypass_other_cpu0 : 1;
        unsigned int ddrsys_autogt_bypass_other_cpu1 : 1;
        unsigned int ddrsys_autogt_bypass_other_cpu2 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PERI_COMMON_CTRL2_UNION;
#endif
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_lpmcu_START (0)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_lpmcu_END (0)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_acpu_l_0_START (1)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_acpu_l_0_END (1)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_acpu_l_1_START (2)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_acpu_l_1_END (2)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_acpu_l_2_START (3)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_acpu_l_2_END (3)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_acpu_l_3_START (4)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_acpu_l_3_END (4)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_acpu_b_0_START (5)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_acpu_b_0_END (5)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_acpu_b_1_START (6)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_acpu_b_1_END (6)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_acpu_b_2_START (7)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_acpu_b_2_END (7)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_acpu_b_3_START (8)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_acpu_b_3_END (8)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_ccpu_START (9)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_ccpu_END (9)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_mdm_bbe0_START (10)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_mdm_bbe0_END (10)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_mdm_bbe1_START (11)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_mdm_bbe1_END (11)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_mdm_bbe2_START (12)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_mdm_bbe2_END (12)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_other_cpu0_START (13)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_other_cpu0_END (13)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_other_cpu1_START (14)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_other_cpu1_END (14)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_other_cpu2_START (15)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_ddrsys_autogt_bypass_other_cpu2_END (15)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_bitmasken_START (16)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL2_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddrc_autogt_bypass_other_mst : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PERI_COMMON_CTRL3_UNION;
#endif
#define SOC_CRGPERIPH_PERI_COMMON_CTRL3_ddrc_autogt_bypass_other_mst_START (0)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL3_ddrc_autogt_bypass_other_mst_END (15)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL3_bitmasken_START (16)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL3_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddrc_autogt_bypass_other_mst1 : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PERI_COMMON_CTRL4_UNION;
#endif
#define SOC_CRGPERIPH_PERI_COMMON_CTRL4_ddrc_autogt_bypass_other_mst1_START (0)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL4_ddrc_autogt_bypass_other_mst1_END (15)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL4_bitmasken_START (16)
#define SOC_CRGPERIPH_PERI_COMMON_CTRL4_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ppll6_en : 1;
        unsigned int ppll6_bp : 1;
        unsigned int ppll6_refdiv : 6;
        unsigned int ppll6_fbdiv : 12;
        unsigned int ppll6_postdiv1 : 3;
        unsigned int ppll6_postdiv2 : 3;
        unsigned int ppll6_lock : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_CRGPERIPH_PPLL6CTRL0_UNION;
#endif
#define SOC_CRGPERIPH_PPLL6CTRL0_ppll6_en_START (0)
#define SOC_CRGPERIPH_PPLL6CTRL0_ppll6_en_END (0)
#define SOC_CRGPERIPH_PPLL6CTRL0_ppll6_bp_START (1)
#define SOC_CRGPERIPH_PPLL6CTRL0_ppll6_bp_END (1)
#define SOC_CRGPERIPH_PPLL6CTRL0_ppll6_refdiv_START (2)
#define SOC_CRGPERIPH_PPLL6CTRL0_ppll6_refdiv_END (7)
#define SOC_CRGPERIPH_PPLL6CTRL0_ppll6_fbdiv_START (8)
#define SOC_CRGPERIPH_PPLL6CTRL0_ppll6_fbdiv_END (19)
#define SOC_CRGPERIPH_PPLL6CTRL0_ppll6_postdiv1_START (20)
#define SOC_CRGPERIPH_PPLL6CTRL0_ppll6_postdiv1_END (22)
#define SOC_CRGPERIPH_PPLL6CTRL0_ppll6_postdiv2_START (23)
#define SOC_CRGPERIPH_PPLL6CTRL0_ppll6_postdiv2_END (25)
#define SOC_CRGPERIPH_PPLL6CTRL0_ppll6_lock_START (26)
#define SOC_CRGPERIPH_PPLL6CTRL0_ppll6_lock_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ppll6_fracdiv : 24;
        unsigned int ppll6_int_mod : 1;
        unsigned int ppll6_cfg_vld : 1;
        unsigned int gt_clk_ppll6 : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_CRGPERIPH_PPLL6CTRL1_UNION;
#endif
#define SOC_CRGPERIPH_PPLL6CTRL1_ppll6_fracdiv_START (0)
#define SOC_CRGPERIPH_PPLL6CTRL1_ppll6_fracdiv_END (23)
#define SOC_CRGPERIPH_PPLL6CTRL1_ppll6_int_mod_START (24)
#define SOC_CRGPERIPH_PPLL6CTRL1_ppll6_int_mod_END (24)
#define SOC_CRGPERIPH_PPLL6CTRL1_ppll6_cfg_vld_START (25)
#define SOC_CRGPERIPH_PPLL6CTRL1_ppll6_cfg_vld_END (25)
#define SOC_CRGPERIPH_PPLL6CTRL1_gt_clk_ppll6_START (26)
#define SOC_CRGPERIPH_PPLL6CTRL1_gt_clk_ppll6_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ppll7_en : 1;
        unsigned int ppll7_bp : 1;
        unsigned int ppll7_refdiv : 6;
        unsigned int ppll7_fbdiv : 12;
        unsigned int ppll7_postdiv1 : 3;
        unsigned int ppll7_postdiv2 : 3;
        unsigned int ppll7_lock : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_CRGPERIPH_PPLL7CTRL0_UNION;
#endif
#define SOC_CRGPERIPH_PPLL7CTRL0_ppll7_en_START (0)
#define SOC_CRGPERIPH_PPLL7CTRL0_ppll7_en_END (0)
#define SOC_CRGPERIPH_PPLL7CTRL0_ppll7_bp_START (1)
#define SOC_CRGPERIPH_PPLL7CTRL0_ppll7_bp_END (1)
#define SOC_CRGPERIPH_PPLL7CTRL0_ppll7_refdiv_START (2)
#define SOC_CRGPERIPH_PPLL7CTRL0_ppll7_refdiv_END (7)
#define SOC_CRGPERIPH_PPLL7CTRL0_ppll7_fbdiv_START (8)
#define SOC_CRGPERIPH_PPLL7CTRL0_ppll7_fbdiv_END (19)
#define SOC_CRGPERIPH_PPLL7CTRL0_ppll7_postdiv1_START (20)
#define SOC_CRGPERIPH_PPLL7CTRL0_ppll7_postdiv1_END (22)
#define SOC_CRGPERIPH_PPLL7CTRL0_ppll7_postdiv2_START (23)
#define SOC_CRGPERIPH_PPLL7CTRL0_ppll7_postdiv2_END (25)
#define SOC_CRGPERIPH_PPLL7CTRL0_ppll7_lock_START (26)
#define SOC_CRGPERIPH_PPLL7CTRL0_ppll7_lock_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ppll7_fracdiv : 24;
        unsigned int ppll7_int_mod : 1;
        unsigned int ppll7_cfg_vld : 1;
        unsigned int gt_clk_ppll7 : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_CRGPERIPH_PPLL7CTRL1_UNION;
#endif
#define SOC_CRGPERIPH_PPLL7CTRL1_ppll7_fracdiv_START (0)
#define SOC_CRGPERIPH_PPLL7CTRL1_ppll7_fracdiv_END (23)
#define SOC_CRGPERIPH_PPLL7CTRL1_ppll7_int_mod_START (24)
#define SOC_CRGPERIPH_PPLL7CTRL1_ppll7_int_mod_END (24)
#define SOC_CRGPERIPH_PPLL7CTRL1_ppll7_cfg_vld_START (25)
#define SOC_CRGPERIPH_PPLL7CTRL1_ppll7_cfg_vld_END (25)
#define SOC_CRGPERIPH_PPLL7CTRL1_gt_clk_ppll7_START (26)
#define SOC_CRGPERIPH_PPLL7CTRL1_gt_clk_ppll7_END (26)
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
} SOC_CRGPERIPH_PPLL6SSCCTRL_UNION;
#endif
#define SOC_CRGPERIPH_PPLL6SSCCTRL_sscg_enable_START (0)
#define SOC_CRGPERIPH_PPLL6SSCCTRL_sscg_enable_END (0)
#define SOC_CRGPERIPH_PPLL6SSCCTRL_sscg_mode_START (1)
#define SOC_CRGPERIPH_PPLL6SSCCTRL_sscg_mode_END (1)
#define SOC_CRGPERIPH_PPLL6SSCCTRL_sscg_rate_START (2)
#define SOC_CRGPERIPH_PPLL6SSCCTRL_sscg_rate_END (5)
#define SOC_CRGPERIPH_PPLL6SSCCTRL_sscg_depth_START (6)
#define SOC_CRGPERIPH_PPLL6SSCCTRL_sscg_depth_END (8)
#define SOC_CRGPERIPH_PPLL6SSCCTRL_sscg_fast_dis_START (9)
#define SOC_CRGPERIPH_PPLL6SSCCTRL_sscg_fast_dis_END (9)
#define SOC_CRGPERIPH_PPLL6SSCCTRL_bitmasken_START (16)
#define SOC_CRGPERIPH_PPLL6SSCCTRL_bitmasken_END (31)
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
} SOC_CRGPERIPH_PPLL7SSCCTRL_UNION;
#endif
#define SOC_CRGPERIPH_PPLL7SSCCTRL_sscg_enable_START (0)
#define SOC_CRGPERIPH_PPLL7SSCCTRL_sscg_enable_END (0)
#define SOC_CRGPERIPH_PPLL7SSCCTRL_sscg_mode_START (1)
#define SOC_CRGPERIPH_PPLL7SSCCTRL_sscg_mode_END (1)
#define SOC_CRGPERIPH_PPLL7SSCCTRL_sscg_rate_START (2)
#define SOC_CRGPERIPH_PPLL7SSCCTRL_sscg_rate_END (5)
#define SOC_CRGPERIPH_PPLL7SSCCTRL_sscg_depth_START (6)
#define SOC_CRGPERIPH_PPLL7SSCCTRL_sscg_depth_END (8)
#define SOC_CRGPERIPH_PPLL7SSCCTRL_sscg_fast_dis_START (9)
#define SOC_CRGPERIPH_PPLL7SSCCTRL_sscg_fast_dis_END (9)
#define SOC_CRGPERIPH_PPLL7SSCCTRL_bitmasken_START (16)
#define SOC_CRGPERIPH_PPLL7SSCCTRL_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pll_unlock_intr_clr : 1;
        unsigned int pll_unlock_intr_clr_acpu : 1;
        unsigned int pll_unlock_en : 1;
        unsigned int pll_unlock_en_acpu : 1;
        unsigned int reserved : 12;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_CLEAR_UNION;
#endif
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_CLEAR_pll_unlock_intr_clr_START (0)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_CLEAR_pll_unlock_intr_clr_END (0)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_CLEAR_pll_unlock_intr_clr_acpu_START (1)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_CLEAR_pll_unlock_intr_clr_acpu_END (1)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_CLEAR_pll_unlock_en_START (2)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_CLEAR_pll_unlock_en_END (2)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_CLEAR_pll_unlock_en_acpu_START (3)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_CLEAR_pll_unlock_en_acpu_END (3)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_CLEAR_bitmasken_START (16)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_CLEAR_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_unlock_intr_bypass : 1;
        unsigned int ulpppll_1_unlock_intr_bypass : 1;
        unsigned int fcg_little_unlock_intr_bypass : 1;
        unsigned int ppll6_unlock_intr_bypass : 1;
        unsigned int fcg_gpu_unlock_intr_bypass : 1;
        unsigned int ppll2_b_unlock_intr_bypass : 1;
        unsigned int fcm_unlock_intr_bypass : 1;
        unsigned int sdpll_unlock_intr_bypass : 1;
        unsigned int ppll1_unlock_intr_bypass : 1;
        unsigned int ppll2_unlock_intr_bypass : 1;
        unsigned int ppll3_unlock_intr_bypass : 1;
        unsigned int fcg_middle_unlock_intr_bypass : 1;
        unsigned int ppll7_unlock_intr_bypass : 1;
        unsigned int fcg_big_unlock_intr_bypass : 1;
        unsigned int spll_unlock_intr_bypass : 1;
        unsigned int fcg_aicore_unlock_intr_bypass : 1;
        unsigned int aupll_unlock_intr_bypass : 1;
        unsigned int pciepll_pcie_unlock_intr_bypass : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 7;
    } reg;
} SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_UNION;
#endif
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_ulppll_unlock_intr_bypass_START (0)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_ulppll_unlock_intr_bypass_END (0)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_ulpppll_1_unlock_intr_bypass_START (1)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_ulpppll_1_unlock_intr_bypass_END (1)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_fcg_little_unlock_intr_bypass_START (2)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_fcg_little_unlock_intr_bypass_END (2)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_ppll6_unlock_intr_bypass_START (3)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_ppll6_unlock_intr_bypass_END (3)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_fcg_gpu_unlock_intr_bypass_START (4)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_fcg_gpu_unlock_intr_bypass_END (4)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_ppll2_b_unlock_intr_bypass_START (5)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_ppll2_b_unlock_intr_bypass_END (5)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_fcm_unlock_intr_bypass_START (6)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_fcm_unlock_intr_bypass_END (6)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_sdpll_unlock_intr_bypass_START (7)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_sdpll_unlock_intr_bypass_END (7)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_ppll1_unlock_intr_bypass_START (8)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_ppll1_unlock_intr_bypass_END (8)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_ppll2_unlock_intr_bypass_START (9)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_ppll2_unlock_intr_bypass_END (9)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_ppll3_unlock_intr_bypass_START (10)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_ppll3_unlock_intr_bypass_END (10)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_fcg_middle_unlock_intr_bypass_START (11)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_fcg_middle_unlock_intr_bypass_END (11)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_ppll7_unlock_intr_bypass_START (12)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_ppll7_unlock_intr_bypass_END (12)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_fcg_big_unlock_intr_bypass_START (13)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_fcg_big_unlock_intr_bypass_END (13)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_spll_unlock_intr_bypass_START (14)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_spll_unlock_intr_bypass_END (14)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_fcg_aicore_unlock_intr_bypass_START (15)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_fcg_aicore_unlock_intr_bypass_END (15)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_aupll_unlock_intr_bypass_START (16)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_aupll_unlock_intr_bypass_END (16)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_pciepll_pcie_unlock_intr_bypass_START (17)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_ACPU_pciepll_pcie_unlock_intr_bypass_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pll_lock_debounce_cfg : 10;
        unsigned int pll_unlock_debounce_cfg : 10;
        unsigned int pll_en_posedge_delay_enable : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_CRGPERIPH_PLL_UNLOCK_DETECT_CTRL_UNION;
#endif
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_CTRL_pll_lock_debounce_cfg_START (0)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_CTRL_pll_lock_debounce_cfg_END (9)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_CTRL_pll_unlock_debounce_cfg_START (10)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_CTRL_pll_unlock_debounce_cfg_END (19)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_CTRL_pll_en_posedge_delay_enable_START (20)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_CTRL_pll_en_posedge_delay_enable_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_unlock_intr_bypass : 1;
        unsigned int ulpppll_1_unlock_intr_bypass : 1;
        unsigned int fcg_little_unlock_intr_bypass : 1;
        unsigned int ppll6_unlock_intr_bypass : 1;
        unsigned int fcg_gpu_unlock_intr_bypass : 1;
        unsigned int ppll2_b_unlock_intr_bypass : 1;
        unsigned int fcm_unlock_intr_bypass : 1;
        unsigned int sdpll_unlock_intr_bypass : 1;
        unsigned int ppll1_unlock_intr_bypass : 1;
        unsigned int ppll2_unlock_intr_bypass : 1;
        unsigned int ppll3_unlock_intr_bypass : 1;
        unsigned int fcg_middle_unlock_intr_bypass : 1;
        unsigned int ppll7_unlock_intr_bypass : 1;
        unsigned int fcg_big_unlock_intr_bypass : 1;
        unsigned int spll_unlock_intr_bypass : 1;
        unsigned int fcg_aicore_unlock_intr_bypass : 1;
        unsigned int aupll_unlock_intr_bypass : 1;
        unsigned int pciepll_pcie_unlock_intr_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 7;
    } reg;
} SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_UNION;
#endif
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_ulppll_unlock_intr_bypass_START (0)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_ulppll_unlock_intr_bypass_END (0)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_ulpppll_1_unlock_intr_bypass_START (1)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_ulpppll_1_unlock_intr_bypass_END (1)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_fcg_little_unlock_intr_bypass_START (2)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_fcg_little_unlock_intr_bypass_END (2)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_ppll6_unlock_intr_bypass_START (3)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_ppll6_unlock_intr_bypass_END (3)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_fcg_gpu_unlock_intr_bypass_START (4)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_fcg_gpu_unlock_intr_bypass_END (4)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_ppll2_b_unlock_intr_bypass_START (5)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_ppll2_b_unlock_intr_bypass_END (5)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_fcm_unlock_intr_bypass_START (6)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_fcm_unlock_intr_bypass_END (6)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_sdpll_unlock_intr_bypass_START (7)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_sdpll_unlock_intr_bypass_END (7)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_ppll1_unlock_intr_bypass_START (8)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_ppll1_unlock_intr_bypass_END (8)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_ppll2_unlock_intr_bypass_START (9)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_ppll2_unlock_intr_bypass_END (9)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_ppll3_unlock_intr_bypass_START (10)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_ppll3_unlock_intr_bypass_END (10)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_fcg_middle_unlock_intr_bypass_START (11)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_fcg_middle_unlock_intr_bypass_END (11)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_ppll7_unlock_intr_bypass_START (12)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_ppll7_unlock_intr_bypass_END (12)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_fcg_big_unlock_intr_bypass_START (13)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_fcg_big_unlock_intr_bypass_END (13)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_spll_unlock_intr_bypass_START (14)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_spll_unlock_intr_bypass_END (14)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_fcg_aicore_unlock_intr_bypass_START (15)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_fcg_aicore_unlock_intr_bypass_END (15)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_aupll_unlock_intr_bypass_START (16)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_aupll_unlock_intr_bypass_END (16)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_pciepll_pcie_unlock_intr_bypass_START (17)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_BYPSS_LPM3_pciepll_pcie_unlock_intr_bypass_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_unlock_intr_stat : 1;
        unsigned int ulpppll_1_unlock_intr_stat : 1;
        unsigned int fcg_little_unlock_intr_stat : 1;
        unsigned int ppll6_unlock_intr_stat : 1;
        unsigned int fcg_gpu_unlock_intr_stat : 1;
        unsigned int ppll2_b_unlock_intr_stat : 1;
        unsigned int fcm_unlock_intr_stat : 1;
        unsigned int sdpll_unlock_intr_stat : 1;
        unsigned int ppll1_unlock_intr_stat : 1;
        unsigned int ppll2_unlock_intr_stat : 1;
        unsigned int ppll3_unlock_intr_stat : 1;
        unsigned int fcg_middle_unlock_intr_stat : 1;
        unsigned int ppll7_unlock_intr_stat : 1;
        unsigned int fcg_big_unlock_intr_stat : 1;
        unsigned int spll_unlock_intr_stat : 1;
        unsigned int fcg_aicore_unlock_intr_stat : 1;
        unsigned int aupll_unlock_intr_stat : 1;
        unsigned int pciepll_pcie_unlock_intr_stat : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 7;
    } reg;
} SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_UNION;
#endif
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_ulppll_unlock_intr_stat_START (0)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_ulppll_unlock_intr_stat_END (0)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_ulpppll_1_unlock_intr_stat_START (1)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_ulpppll_1_unlock_intr_stat_END (1)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_fcg_little_unlock_intr_stat_START (2)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_fcg_little_unlock_intr_stat_END (2)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_ppll6_unlock_intr_stat_START (3)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_ppll6_unlock_intr_stat_END (3)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_fcg_gpu_unlock_intr_stat_START (4)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_fcg_gpu_unlock_intr_stat_END (4)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_ppll2_b_unlock_intr_stat_START (5)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_ppll2_b_unlock_intr_stat_END (5)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_fcm_unlock_intr_stat_START (6)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_fcm_unlock_intr_stat_END (6)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_sdpll_unlock_intr_stat_START (7)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_sdpll_unlock_intr_stat_END (7)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_ppll1_unlock_intr_stat_START (8)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_ppll1_unlock_intr_stat_END (8)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_ppll2_unlock_intr_stat_START (9)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_ppll2_unlock_intr_stat_END (9)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_ppll3_unlock_intr_stat_START (10)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_ppll3_unlock_intr_stat_END (10)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_fcg_middle_unlock_intr_stat_START (11)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_fcg_middle_unlock_intr_stat_END (11)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_ppll7_unlock_intr_stat_START (12)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_ppll7_unlock_intr_stat_END (12)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_fcg_big_unlock_intr_stat_START (13)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_fcg_big_unlock_intr_stat_END (13)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_spll_unlock_intr_stat_START (14)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_spll_unlock_intr_stat_END (14)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_fcg_aicore_unlock_intr_stat_START (15)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_fcg_aicore_unlock_intr_stat_END (15)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_aupll_unlock_intr_stat_START (16)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_aupll_unlock_intr_stat_END (16)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_pciepll_pcie_unlock_intr_stat_START (17)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECT_INTR_STAT_pciepll_pcie_unlock_intr_stat_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_unlock_intr_cnt : 4;
        unsigned int ulppll_1_unlock_intr_cnt : 4;
        unsigned int fcg_little_unlock_intr_cnt : 4;
        unsigned int ppll6_unlock_intr_cnt : 4;
        unsigned int fcg_gpu_unlock_intr_cnt : 4;
        unsigned int ppll2_b_unlock_intr_cnt : 4;
        unsigned int fcm_unlock_intr_cnt : 4;
        unsigned int sdpll_unlock_intr_cnt : 4;
    } reg;
} SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT0_UNION;
#endif
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT0_ulppll_unlock_intr_cnt_START (0)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT0_ulppll_unlock_intr_cnt_END (3)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT0_ulppll_1_unlock_intr_cnt_START (4)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT0_ulppll_1_unlock_intr_cnt_END (7)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT0_fcg_little_unlock_intr_cnt_START (8)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT0_fcg_little_unlock_intr_cnt_END (11)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT0_ppll6_unlock_intr_cnt_START (12)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT0_ppll6_unlock_intr_cnt_END (15)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT0_fcg_gpu_unlock_intr_cnt_START (16)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT0_fcg_gpu_unlock_intr_cnt_END (19)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT0_ppll2_b_unlock_intr_cnt_START (20)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT0_ppll2_b_unlock_intr_cnt_END (23)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT0_fcm_unlock_intr_cnt_START (24)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT0_fcm_unlock_intr_cnt_END (27)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT0_sdpll_unlock_intr_cnt_START (28)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT0_sdpll_unlock_intr_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ppll1_unlock_intr_cnt : 4;
        unsigned int ppll2_unlock_intr_cnt : 4;
        unsigned int ppll3_unlock_intr_cnt : 4;
        unsigned int fcg_middle_unlock_intr_cnt : 4;
        unsigned int ppll7_unlock_intr_cnt : 4;
        unsigned int fcg_big_unlock_intr_cnt : 4;
        unsigned int spll_unlock_intr_cnt : 4;
        unsigned int fcg_aicore_unlock_intr_cnt : 4;
    } reg;
} SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT1_UNION;
#endif
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT1_ppll1_unlock_intr_cnt_START (0)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT1_ppll1_unlock_intr_cnt_END (3)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT1_ppll2_unlock_intr_cnt_START (4)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT1_ppll2_unlock_intr_cnt_END (7)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT1_ppll3_unlock_intr_cnt_START (8)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT1_ppll3_unlock_intr_cnt_END (11)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT1_fcg_middle_unlock_intr_cnt_START (12)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT1_fcg_middle_unlock_intr_cnt_END (15)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT1_ppll7_unlock_intr_cnt_START (16)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT1_ppll7_unlock_intr_cnt_END (19)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT1_fcg_big_unlock_intr_cnt_START (20)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT1_fcg_big_unlock_intr_cnt_END (23)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT1_spll_unlock_intr_cnt_START (24)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT1_spll_unlock_intr_cnt_END (27)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT1_fcg_aicore_unlock_intr_cnt_START (28)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT1_fcg_aicore_unlock_intr_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aupll_unlock_intr_cnt : 4;
        unsigned int pciepll_pcie_unlock_intr_cnt : 4;
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 4;
        unsigned int reserved_2 : 4;
        unsigned int reserved_3 : 4;
        unsigned int reserved_4 : 4;
        unsigned int reserved_5 : 4;
    } reg;
} SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT2_UNION;
#endif
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT2_aupll_unlock_intr_cnt_START (0)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT2_aupll_unlock_intr_cnt_END (3)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT2_pciepll_pcie_unlock_intr_cnt_START (4)
#define SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT2_pciepll_pcie_unlock_intr_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 4;
        unsigned int reserved_1: 4;
        unsigned int reserved_2: 4;
        unsigned int reserved_3: 4;
        unsigned int reserved_4: 4;
        unsigned int reserved_5: 4;
        unsigned int reserved_6: 4;
        unsigned int reserved_7: 4;
    } reg;
} SOC_CRGPERIPH_PLL_UNLOCK_DETECTCNT3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ppll1_en_fsm_vote : 5;
        unsigned int ppll2_en_fsm_vote : 5;
        unsigned int ppll3_en_fsm_vote : 5;
        unsigned int reserved : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PLL_FSM_NS_VOTE0_UNION;
#endif
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE0_ppll1_en_fsm_vote_START (0)
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE0_ppll1_en_fsm_vote_END (4)
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE0_ppll2_en_fsm_vote_START (5)
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE0_ppll2_en_fsm_vote_END (9)
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE0_ppll3_en_fsm_vote_START (10)
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE0_ppll3_en_fsm_vote_END (14)
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE0_bitmasken_START (16)
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ppll7_en_fsm_vote : 5;
        unsigned int ppll2_b_en_fsm_vote : 5;
        unsigned int ppll6_en_fsm_vote : 5;
        unsigned int reserved : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PLL_FSM_NS_VOTE1_UNION;
#endif
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE1_ppll7_en_fsm_vote_START (0)
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE1_ppll7_en_fsm_vote_END (4)
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE1_ppll2_b_en_fsm_vote_START (5)
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE1_ppll2_b_en_fsm_vote_END (9)
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE1_ppll6_en_fsm_vote_START (10)
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE1_ppll6_en_fsm_vote_END (14)
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE1_bitmasken_START (16)
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE1_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pll1_fsm_wsat : 1;
        unsigned int pll2_fsm_wsat : 1;
        unsigned int pll2_b_fsm_wsat : 1;
        unsigned int pll3_fsm_wsat : 1;
        unsigned int pll7_fsm_wsat : 1;
        unsigned int pll6_fsm_wsat : 1;
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 5;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 16;
    } reg;
} SOC_CRGPERIPH_PLL_FSM_NS_STAT_UNION;
#endif
#define SOC_CRGPERIPH_PLL_FSM_NS_STAT_pll1_fsm_wsat_START (0)
#define SOC_CRGPERIPH_PLL_FSM_NS_STAT_pll1_fsm_wsat_END (0)
#define SOC_CRGPERIPH_PLL_FSM_NS_STAT_pll2_fsm_wsat_START (1)
#define SOC_CRGPERIPH_PLL_FSM_NS_STAT_pll2_fsm_wsat_END (1)
#define SOC_CRGPERIPH_PLL_FSM_NS_STAT_pll2_b_fsm_wsat_START (2)
#define SOC_CRGPERIPH_PLL_FSM_NS_STAT_pll2_b_fsm_wsat_END (2)
#define SOC_CRGPERIPH_PLL_FSM_NS_STAT_pll3_fsm_wsat_START (3)
#define SOC_CRGPERIPH_PLL_FSM_NS_STAT_pll3_fsm_wsat_END (3)
#define SOC_CRGPERIPH_PLL_FSM_NS_STAT_pll7_fsm_wsat_START (4)
#define SOC_CRGPERIPH_PLL_FSM_NS_STAT_pll7_fsm_wsat_END (4)
#define SOC_CRGPERIPH_PLL_FSM_NS_STAT_pll6_fsm_wsat_START (5)
#define SOC_CRGPERIPH_PLL_FSM_NS_STAT_pll6_fsm_wsat_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int FNPLL_CFG0 : 32;
    } reg;
} SOC_CRGPERIPH_FNPLL_CFG0_UNION;
#endif
#define SOC_CRGPERIPH_FNPLL_CFG0_FNPLL_CFG0_START (0)
#define SOC_CRGPERIPH_FNPLL_CFG0_FNPLL_CFG0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int FNPLL_CFG1 : 32;
    } reg;
} SOC_CRGPERIPH_FNPLL_CFG1_UNION;
#endif
#define SOC_CRGPERIPH_FNPLL_CFG1_FNPLL_CFG1_START (0)
#define SOC_CRGPERIPH_FNPLL_CFG1_FNPLL_CFG1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int FNPLL_CFG2 : 32;
    } reg;
} SOC_CRGPERIPH_FNPLL_CFG2_UNION;
#endif
#define SOC_CRGPERIPH_FNPLL_CFG2_FNPLL_CFG2_START (0)
#define SOC_CRGPERIPH_FNPLL_CFG2_FNPLL_CFG2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int FNPLL_CFG3 : 32;
    } reg;
} SOC_CRGPERIPH_FNPLL_CFG3_UNION;
#endif
#define SOC_CRGPERIPH_FNPLL_CFG3_FNPLL_CFG3_START (0)
#define SOC_CRGPERIPH_FNPLL_CFG3_FNPLL_CFG3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int FNPLL_STATE0 : 32;
    } reg;
} SOC_CRGPERIPH_FNPLL_STATE0_UNION;
#endif
#define SOC_CRGPERIPH_FNPLL_STATE0_FNPLL_STATE0_START (0)
#define SOC_CRGPERIPH_FNPLL_STATE0_FNPLL_STATE0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ppll1_en : 1;
        unsigned int ppll1_bp : 1;
        unsigned int ppll1_refdiv : 6;
        unsigned int ppll1_fbdiv : 12;
        unsigned int ppll1_postdiv1 : 3;
        unsigned int ppll1_postdiv2 : 3;
        unsigned int ppll1_lock : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_CRGPERIPH_PPLL1CTRL0_UNION;
#endif
#define SOC_CRGPERIPH_PPLL1CTRL0_ppll1_en_START (0)
#define SOC_CRGPERIPH_PPLL1CTRL0_ppll1_en_END (0)
#define SOC_CRGPERIPH_PPLL1CTRL0_ppll1_bp_START (1)
#define SOC_CRGPERIPH_PPLL1CTRL0_ppll1_bp_END (1)
#define SOC_CRGPERIPH_PPLL1CTRL0_ppll1_refdiv_START (2)
#define SOC_CRGPERIPH_PPLL1CTRL0_ppll1_refdiv_END (7)
#define SOC_CRGPERIPH_PPLL1CTRL0_ppll1_fbdiv_START (8)
#define SOC_CRGPERIPH_PPLL1CTRL0_ppll1_fbdiv_END (19)
#define SOC_CRGPERIPH_PPLL1CTRL0_ppll1_postdiv1_START (20)
#define SOC_CRGPERIPH_PPLL1CTRL0_ppll1_postdiv1_END (22)
#define SOC_CRGPERIPH_PPLL1CTRL0_ppll1_postdiv2_START (23)
#define SOC_CRGPERIPH_PPLL1CTRL0_ppll1_postdiv2_END (25)
#define SOC_CRGPERIPH_PPLL1CTRL0_ppll1_lock_START (26)
#define SOC_CRGPERIPH_PPLL1CTRL0_ppll1_lock_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ppll1_fracdiv : 24;
        unsigned int ppll1_int_mod : 1;
        unsigned int ppll1_cfg_vld : 1;
        unsigned int gt_clk_ppll1 : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_CRGPERIPH_PPLL1CTRL1_UNION;
#endif
#define SOC_CRGPERIPH_PPLL1CTRL1_ppll1_fracdiv_START (0)
#define SOC_CRGPERIPH_PPLL1CTRL1_ppll1_fracdiv_END (23)
#define SOC_CRGPERIPH_PPLL1CTRL1_ppll1_int_mod_START (24)
#define SOC_CRGPERIPH_PPLL1CTRL1_ppll1_int_mod_END (24)
#define SOC_CRGPERIPH_PPLL1CTRL1_ppll1_cfg_vld_START (25)
#define SOC_CRGPERIPH_PPLL1CTRL1_ppll1_cfg_vld_END (25)
#define SOC_CRGPERIPH_PPLL1CTRL1_gt_clk_ppll1_START (26)
#define SOC_CRGPERIPH_PPLL1CTRL1_gt_clk_ppll1_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ppll2_en : 1;
        unsigned int ppll2_bp : 1;
        unsigned int ppll2_refdiv : 6;
        unsigned int ppll2_fbdiv : 12;
        unsigned int ppll2_postdiv1 : 3;
        unsigned int ppll2_postdiv2 : 3;
        unsigned int ppll2_lock : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_CRGPERIPH_PPLL2CTRL0_UNION;
#endif
#define SOC_CRGPERIPH_PPLL2CTRL0_ppll2_en_START (0)
#define SOC_CRGPERIPH_PPLL2CTRL0_ppll2_en_END (0)
#define SOC_CRGPERIPH_PPLL2CTRL0_ppll2_bp_START (1)
#define SOC_CRGPERIPH_PPLL2CTRL0_ppll2_bp_END (1)
#define SOC_CRGPERIPH_PPLL2CTRL0_ppll2_refdiv_START (2)
#define SOC_CRGPERIPH_PPLL2CTRL0_ppll2_refdiv_END (7)
#define SOC_CRGPERIPH_PPLL2CTRL0_ppll2_fbdiv_START (8)
#define SOC_CRGPERIPH_PPLL2CTRL0_ppll2_fbdiv_END (19)
#define SOC_CRGPERIPH_PPLL2CTRL0_ppll2_postdiv1_START (20)
#define SOC_CRGPERIPH_PPLL2CTRL0_ppll2_postdiv1_END (22)
#define SOC_CRGPERIPH_PPLL2CTRL0_ppll2_postdiv2_START (23)
#define SOC_CRGPERIPH_PPLL2CTRL0_ppll2_postdiv2_END (25)
#define SOC_CRGPERIPH_PPLL2CTRL0_ppll2_lock_START (26)
#define SOC_CRGPERIPH_PPLL2CTRL0_ppll2_lock_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ppll2_fracdiv : 24;
        unsigned int ppll2_int_mod : 1;
        unsigned int ppll2_cfg_vld : 1;
        unsigned int gt_clk_ppll2 : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_CRGPERIPH_PPLL2CTRL1_UNION;
#endif
#define SOC_CRGPERIPH_PPLL2CTRL1_ppll2_fracdiv_START (0)
#define SOC_CRGPERIPH_PPLL2CTRL1_ppll2_fracdiv_END (23)
#define SOC_CRGPERIPH_PPLL2CTRL1_ppll2_int_mod_START (24)
#define SOC_CRGPERIPH_PPLL2CTRL1_ppll2_int_mod_END (24)
#define SOC_CRGPERIPH_PPLL2CTRL1_ppll2_cfg_vld_START (25)
#define SOC_CRGPERIPH_PPLL2CTRL1_ppll2_cfg_vld_END (25)
#define SOC_CRGPERIPH_PPLL2CTRL1_gt_clk_ppll2_START (26)
#define SOC_CRGPERIPH_PPLL2CTRL1_gt_clk_ppll2_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ppll3_en : 1;
        unsigned int ppll3_bp : 1;
        unsigned int ppll3_refdiv : 6;
        unsigned int ppll3_fbdiv : 12;
        unsigned int ppll3_postdiv1 : 3;
        unsigned int ppll3_postdiv2 : 3;
        unsigned int ppll3_lock : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_CRGPERIPH_PPLL3CTRL0_UNION;
#endif
#define SOC_CRGPERIPH_PPLL3CTRL0_ppll3_en_START (0)
#define SOC_CRGPERIPH_PPLL3CTRL0_ppll3_en_END (0)
#define SOC_CRGPERIPH_PPLL3CTRL0_ppll3_bp_START (1)
#define SOC_CRGPERIPH_PPLL3CTRL0_ppll3_bp_END (1)
#define SOC_CRGPERIPH_PPLL3CTRL0_ppll3_refdiv_START (2)
#define SOC_CRGPERIPH_PPLL3CTRL0_ppll3_refdiv_END (7)
#define SOC_CRGPERIPH_PPLL3CTRL0_ppll3_fbdiv_START (8)
#define SOC_CRGPERIPH_PPLL3CTRL0_ppll3_fbdiv_END (19)
#define SOC_CRGPERIPH_PPLL3CTRL0_ppll3_postdiv1_START (20)
#define SOC_CRGPERIPH_PPLL3CTRL0_ppll3_postdiv1_END (22)
#define SOC_CRGPERIPH_PPLL3CTRL0_ppll3_postdiv2_START (23)
#define SOC_CRGPERIPH_PPLL3CTRL0_ppll3_postdiv2_END (25)
#define SOC_CRGPERIPH_PPLL3CTRL0_ppll3_lock_START (26)
#define SOC_CRGPERIPH_PPLL3CTRL0_ppll3_lock_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ppll3_fracdiv : 24;
        unsigned int ppll3_int_mod : 1;
        unsigned int ppll3_cfg_vld : 1;
        unsigned int gt_clk_ppll3 : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_CRGPERIPH_PPLL3CTRL1_UNION;
#endif
#define SOC_CRGPERIPH_PPLL3CTRL1_ppll3_fracdiv_START (0)
#define SOC_CRGPERIPH_PPLL3CTRL1_ppll3_fracdiv_END (23)
#define SOC_CRGPERIPH_PPLL3CTRL1_ppll3_int_mod_START (24)
#define SOC_CRGPERIPH_PPLL3CTRL1_ppll3_int_mod_END (24)
#define SOC_CRGPERIPH_PPLL3CTRL1_ppll3_cfg_vld_START (25)
#define SOC_CRGPERIPH_PPLL3CTRL1_ppll3_cfg_vld_END (25)
#define SOC_CRGPERIPH_PPLL3CTRL1_gt_clk_ppll3_START (26)
#define SOC_CRGPERIPH_PPLL3CTRL1_gt_clk_ppll3_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ppll2_b_en : 1;
        unsigned int ppll2_b_bp : 1;
        unsigned int ppll2_b_refdiv : 6;
        unsigned int ppll2_b_fbdiv : 12;
        unsigned int ppll2_b_postdiv1 : 3;
        unsigned int ppll2_b_postdiv2 : 3;
        unsigned int ppll2_b_lock : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_CRGPERIPH_PPLL2_BCTRL0_UNION;
#endif
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ppll2_b_en_START (0)
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ppll2_b_en_END (0)
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ppll2_b_bp_START (1)
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ppll2_b_bp_END (1)
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ppll2_b_refdiv_START (2)
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ppll2_b_refdiv_END (7)
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ppll2_b_fbdiv_START (8)
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ppll2_b_fbdiv_END (19)
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ppll2_b_postdiv1_START (20)
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ppll2_b_postdiv1_END (22)
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ppll2_b_postdiv2_START (23)
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ppll2_b_postdiv2_END (25)
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ppll2_b_lock_START (26)
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ppll2_b_lock_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ppll2_b_fracdiv : 24;
        unsigned int ppll2_b_int_mod : 1;
        unsigned int ppll2_b_cfg_vld : 1;
        unsigned int gt_clk_ppll2_b : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_CRGPERIPH_PPLL2_BCTRL1_UNION;
#endif
#define SOC_CRGPERIPH_PPLL2_BCTRL1_ppll2_b_fracdiv_START (0)
#define SOC_CRGPERIPH_PPLL2_BCTRL1_ppll2_b_fracdiv_END (23)
#define SOC_CRGPERIPH_PPLL2_BCTRL1_ppll2_b_int_mod_START (24)
#define SOC_CRGPERIPH_PPLL2_BCTRL1_ppll2_b_int_mod_END (24)
#define SOC_CRGPERIPH_PPLL2_BCTRL1_ppll2_b_cfg_vld_START (25)
#define SOC_CRGPERIPH_PPLL2_BCTRL1_ppll2_b_cfg_vld_END (25)
#define SOC_CRGPERIPH_PPLL2_BCTRL1_gt_clk_ppll2_b_START (26)
#define SOC_CRGPERIPH_PPLL2_BCTRL1_gt_clk_ppll2_b_END (26)
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
} SOC_CRGPERIPH_PPLL1SSCCTRL_UNION;
#endif
#define SOC_CRGPERIPH_PPLL1SSCCTRL_sscg_enable_START (0)
#define SOC_CRGPERIPH_PPLL1SSCCTRL_sscg_enable_END (0)
#define SOC_CRGPERIPH_PPLL1SSCCTRL_sscg_mode_START (1)
#define SOC_CRGPERIPH_PPLL1SSCCTRL_sscg_mode_END (1)
#define SOC_CRGPERIPH_PPLL1SSCCTRL_sscg_rate_START (2)
#define SOC_CRGPERIPH_PPLL1SSCCTRL_sscg_rate_END (5)
#define SOC_CRGPERIPH_PPLL1SSCCTRL_sscg_depth_START (6)
#define SOC_CRGPERIPH_PPLL1SSCCTRL_sscg_depth_END (8)
#define SOC_CRGPERIPH_PPLL1SSCCTRL_sscg_fast_dis_START (9)
#define SOC_CRGPERIPH_PPLL1SSCCTRL_sscg_fast_dis_END (9)
#define SOC_CRGPERIPH_PPLL1SSCCTRL_bitmasken_START (16)
#define SOC_CRGPERIPH_PPLL1SSCCTRL_bitmasken_END (31)
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
} SOC_CRGPERIPH_PPLL2SSCCTRL_UNION;
#endif
#define SOC_CRGPERIPH_PPLL2SSCCTRL_sscg_enable_START (0)
#define SOC_CRGPERIPH_PPLL2SSCCTRL_sscg_enable_END (0)
#define SOC_CRGPERIPH_PPLL2SSCCTRL_sscg_mode_START (1)
#define SOC_CRGPERIPH_PPLL2SSCCTRL_sscg_mode_END (1)
#define SOC_CRGPERIPH_PPLL2SSCCTRL_sscg_rate_START (2)
#define SOC_CRGPERIPH_PPLL2SSCCTRL_sscg_rate_END (5)
#define SOC_CRGPERIPH_PPLL2SSCCTRL_sscg_depth_START (6)
#define SOC_CRGPERIPH_PPLL2SSCCTRL_sscg_depth_END (8)
#define SOC_CRGPERIPH_PPLL2SSCCTRL_sscg_fast_dis_START (9)
#define SOC_CRGPERIPH_PPLL2SSCCTRL_sscg_fast_dis_END (9)
#define SOC_CRGPERIPH_PPLL2SSCCTRL_bitmasken_START (16)
#define SOC_CRGPERIPH_PPLL2SSCCTRL_bitmasken_END (31)
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
} SOC_CRGPERIPH_PPLL3SSCCTRL_UNION;
#endif
#define SOC_CRGPERIPH_PPLL3SSCCTRL_sscg_enable_START (0)
#define SOC_CRGPERIPH_PPLL3SSCCTRL_sscg_enable_END (0)
#define SOC_CRGPERIPH_PPLL3SSCCTRL_sscg_mode_START (1)
#define SOC_CRGPERIPH_PPLL3SSCCTRL_sscg_mode_END (1)
#define SOC_CRGPERIPH_PPLL3SSCCTRL_sscg_rate_START (2)
#define SOC_CRGPERIPH_PPLL3SSCCTRL_sscg_rate_END (5)
#define SOC_CRGPERIPH_PPLL3SSCCTRL_sscg_depth_START (6)
#define SOC_CRGPERIPH_PPLL3SSCCTRL_sscg_depth_END (8)
#define SOC_CRGPERIPH_PPLL3SSCCTRL_sscg_fast_dis_START (9)
#define SOC_CRGPERIPH_PPLL3SSCCTRL_sscg_fast_dis_END (9)
#define SOC_CRGPERIPH_PPLL3SSCCTRL_bitmasken_START (16)
#define SOC_CRGPERIPH_PPLL3SSCCTRL_bitmasken_END (31)
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
} SOC_CRGPERIPH_PPLL2_BSSCCTRL_UNION;
#endif
#define SOC_CRGPERIPH_PPLL2_BSSCCTRL_sscg_enable_START (0)
#define SOC_CRGPERIPH_PPLL2_BSSCCTRL_sscg_enable_END (0)
#define SOC_CRGPERIPH_PPLL2_BSSCCTRL_sscg_mode_START (1)
#define SOC_CRGPERIPH_PPLL2_BSSCCTRL_sscg_mode_END (1)
#define SOC_CRGPERIPH_PPLL2_BSSCCTRL_sscg_rate_START (2)
#define SOC_CRGPERIPH_PPLL2_BSSCCTRL_sscg_rate_END (5)
#define SOC_CRGPERIPH_PPLL2_BSSCCTRL_sscg_depth_START (6)
#define SOC_CRGPERIPH_PPLL2_BSSCCTRL_sscg_depth_END (8)
#define SOC_CRGPERIPH_PPLL2_BSSCCTRL_sscg_fast_dis_START (9)
#define SOC_CRGPERIPH_PPLL2_BSSCCTRL_sscg_fast_dis_END (9)
#define SOC_CRGPERIPH_PPLL2_BSSCCTRL_bitmasken_START (16)
#define SOC_CRGPERIPH_PPLL2_BSSCCTRL_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_gt_clk_hisee_flash : 1;
        unsigned int sc_gt_clk_sysbus_pll : 1;
        unsigned int sc_gt_clk_pll_fsm : 1;
        unsigned int sc_gt_clk_sysbus_sys : 1;
        unsigned int sc_gt_clk_gpu_ppll0_div : 1;
        unsigned int sc_gt_clk_cpul_ppll0_div : 1;
        unsigned int sc_gt_clk_periph_cpu_lit : 1;
        unsigned int sc_gt_clk_cpum_ppll0_div : 1;
        unsigned int sc_gt_clk_hsdt1bus : 1;
        unsigned int sc_gt_clk_core_crg_apb : 1;
        unsigned int sc_gt_clk_gpu_lp_ctrl : 1;
        unsigned int sc_gt_clk_cpu_lp_ctrl : 1;
        unsigned int sc_gt_clk_periph_cpu : 1;
        unsigned int sc_gt_clk_cpu_gic : 1;
        unsigned int sc_gt_clk_fcm_ppll0_div : 1;
        unsigned int sc_gt_clk_periph_cpu_hc : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_hisee_flash_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_hisee_flash_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_sysbus_pll_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_sysbus_pll_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_pll_fsm_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_pll_fsm_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_sysbus_sys_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_sysbus_sys_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_gpu_ppll0_div_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_gpu_ppll0_div_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_cpul_ppll0_div_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_cpul_ppll0_div_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_periph_cpu_lit_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_periph_cpu_lit_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_cpum_ppll0_div_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_cpum_ppll0_div_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_hsdt1bus_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_hsdt1bus_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_core_crg_apb_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_core_crg_apb_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_gpu_lp_ctrl_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_gpu_lp_ctrl_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_cpu_lp_ctrl_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_cpu_lp_ctrl_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_periph_cpu_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_periph_cpu_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_cpu_gic_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_cpu_gic_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_fcm_ppll0_div_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_fcm_ppll0_div_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_periph_cpu_hc_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_sc_gt_clk_periph_cpu_hc_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_bitmasken_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_gt_clk_dmc_peri : 1;
        unsigned int sc_gt_clk_sysbus_fll : 1;
        unsigned int sc_gt_clk_dcdrbus_lpmcu : 1;
        unsigned int sc_gt_clk_cssysdbg_div : 1;
        unsigned int sc_gt_clk_tscpu_peri : 1;
        unsigned int sc_gt_clk_dcdrbus_ddrxpu : 1;
        unsigned int sc_gt_clk_center_crossbar_pll : 1;
        unsigned int sc_gt_clk_center_crossbar_sys : 1;
        unsigned int sc_gt_clk_center_crossbar_fll : 1;
        unsigned int sc_gt_atclk_cpu_lit_from_top : 1;
        unsigned int sc_gt_atclk_cpu_hc_from_top : 1;
        unsigned int sc_gt_clk_spi6 : 1;
        unsigned int sc_gt_clk_lpmcu_fll : 1;
        unsigned int sc_gt_clk_lpmcu_invar_fll : 1;
        unsigned int sc_gt_clk_lpmcu_pll : 1;
        unsigned int sc_gt_clk_pim : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_clk_dmc_peri_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_clk_dmc_peri_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_clk_sysbus_fll_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_clk_sysbus_fll_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_clk_dcdrbus_lpmcu_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_clk_dcdrbus_lpmcu_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_clk_cssysdbg_div_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_clk_cssysdbg_div_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_clk_tscpu_peri_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_clk_tscpu_peri_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_clk_dcdrbus_ddrxpu_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_clk_dcdrbus_ddrxpu_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_clk_center_crossbar_pll_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_clk_center_crossbar_pll_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_clk_center_crossbar_sys_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_clk_center_crossbar_sys_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_clk_center_crossbar_fll_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_clk_center_crossbar_fll_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_atclk_cpu_lit_from_top_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_atclk_cpu_lit_from_top_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_atclk_cpu_hc_from_top_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_atclk_cpu_hc_from_top_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_clk_spi6_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_clk_spi6_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_clk_lpmcu_fll_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_clk_lpmcu_fll_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_clk_lpmcu_invar_fll_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_clk_lpmcu_invar_fll_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_clk_lpmcu_pll_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_clk_lpmcu_pll_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_clk_pim_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_sc_gt_clk_pim_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_bitmasken_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV1_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_hisee_flash : 6;
        unsigned int sel_clk_hisee_flash : 1;
        unsigned int div_sysbus_pll : 5;
        unsigned int sysbus_clk_sw_req_cfg : 2;
        unsigned int reserved : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_CLKDIV2_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV2_div_hisee_flash_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV2_div_hisee_flash_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV2_sel_clk_hisee_flash_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV2_sel_clk_hisee_flash_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV2_div_sysbus_pll_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV2_div_sysbus_pll_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV2_sysbus_clk_sw_req_cfg_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV2_sysbus_clk_sw_req_cfg_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV2_bitmasken_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV2_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_clk_qic_npubus : 4;
        unsigned int div_spi6 : 4;
        unsigned int div_clk_pll_fsm : 6;
        unsigned int sel_ai_core_sw : 1;
        unsigned int sel_spi6 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_CLKDIV3_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV3_div_clk_qic_npubus_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV3_div_clk_qic_npubus_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV3_div_spi6_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV3_div_spi6_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV3_div_clk_pll_fsm_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV3_div_clk_pll_fsm_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV3_sel_ai_core_sw_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV3_sel_ai_core_sw_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV3_sel_spi6_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV3_sel_spi6_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV3_bitmasken_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV3_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_periph_cpu : 6;
        unsigned int div_cpu_gic : 6;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int div_clk_sys_sysbus : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_CLKDIV4_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV4_div_periph_cpu_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV4_div_periph_cpu_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV4_div_cpu_gic_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV4_div_cpu_gic_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV4_div_clk_sys_sysbus_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV4_div_clk_sys_sysbus_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV4_bitmasken_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV4_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_gpu_lp_ctrl : 2;
        unsigned int div_cpu_lp_ctrl : 2;
        unsigned int sel_ts_cpu_fll_sw : 1;
        unsigned int lpmcu_clk_sw_req_cfg : 2;
        unsigned int div_core_crg_apb : 4;
        unsigned int div_cssysdbg : 1;
        unsigned int lpmcu_invar_clk_sw_req_cfg : 2;
        unsigned int div_tsensor : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_CLKDIV5_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV5_div_gpu_lp_ctrl_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV5_div_gpu_lp_ctrl_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV5_div_cpu_lp_ctrl_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV5_div_cpu_lp_ctrl_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV5_sel_ts_cpu_fll_sw_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV5_sel_ts_cpu_fll_sw_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV5_lpmcu_clk_sw_req_cfg_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV5_lpmcu_clk_sw_req_cfg_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV5_div_core_crg_apb_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV5_div_core_crg_apb_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV5_div_cssysdbg_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV5_div_cssysdbg_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV5_lpmcu_invar_clk_sw_req_cfg_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV5_lpmcu_invar_clk_sw_req_cfg_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV5_div_tsensor_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV5_div_tsensor_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV5_bitmasken_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV5_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_sysbus_fll : 4;
        unsigned int div_core_crg_apb_fll : 4;
        unsigned int div_tscpu_peri : 4;
        unsigned int sel_tscpu_peri : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_CLKDIV6_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV6_div_sysbus_fll_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV6_div_sysbus_fll_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV6_div_core_crg_apb_fll_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV6_div_core_crg_apb_fll_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV6_div_tscpu_peri_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV6_div_tscpu_peri_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV6_sel_tscpu_peri_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV6_sel_tscpu_peri_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV6_bitmasken_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV6_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_sysbus_l_vote : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_CLKDIV7_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV7_gt_clk_sysbus_l_vote_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV7_gt_clk_sysbus_l_vote_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV7_bitmasken_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV7_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_sysbus_r_vote : 16;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_CLKDIV8_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV8_gt_clk_sysbus_r_vote_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV8_gt_clk_sysbus_r_vote_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV8_bitmasken_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV8_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_dmc_peri : 6;
        unsigned int div_lpmcu : 5;
        unsigned int reserved : 1;
        unsigned int div_lpmcu_invar_fll : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_CLKDIV9_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV9_div_dmc_peri_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV9_div_dmc_peri_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV9_div_lpmcu_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV9_div_lpmcu_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV9_div_lpmcu_invar_fll_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV9_div_lpmcu_invar_fll_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV9_bitmasken_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV9_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_lpmcu_fll : 4;
        unsigned int sel_pll_dmc_sw_a : 1;
        unsigned int sel_pll_dmc_sw_b : 1;
        unsigned int sel_pll_dmc_sw_c : 1;
        unsigned int sel_pll_dmc_sw_d : 1;
        unsigned int div_clk_dcdrbus : 2;
        unsigned int div_clk_qic_npubus_cfg : 6;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_CLKDIV10_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV10_div_lpmcu_fll_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV10_div_lpmcu_fll_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV10_sel_pll_dmc_sw_a_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV10_sel_pll_dmc_sw_a_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV10_sel_pll_dmc_sw_b_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV10_sel_pll_dmc_sw_b_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV10_sel_pll_dmc_sw_c_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV10_sel_pll_dmc_sw_c_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV10_sel_pll_dmc_sw_d_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV10_sel_pll_dmc_sw_d_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV10_div_clk_dcdrbus_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV10_div_clk_dcdrbus_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV10_div_clk_qic_npubus_cfg_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV10_div_clk_qic_npubus_cfg_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV10_bitmasken_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV10_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_center_crossbar_pll : 6;
        unsigned int div_center_crossbar_sys : 2;
        unsigned int center_crossbar_clk_sw_req_cfg : 2;
        unsigned int reserved : 1;
        unsigned int sel_center_crossbar_pll : 1;
        unsigned int div_center_crossbar_fll : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_CLKDIV11_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV11_div_center_crossbar_pll_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV11_div_center_crossbar_pll_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV11_div_center_crossbar_sys_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV11_div_center_crossbar_sys_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV11_center_crossbar_clk_sw_req_cfg_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV11_center_crossbar_clk_sw_req_cfg_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV11_sel_center_crossbar_pll_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV11_sel_center_crossbar_pll_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV11_div_center_crossbar_fll_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV11_div_center_crossbar_fll_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV11_bitmasken_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV11_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_periph_cpu_hc : 6;
        unsigned int div_periph_cpu_lit : 6;
        unsigned int reserved : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_CLKDIV12_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV12_div_periph_cpu_hc_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV12_div_periph_cpu_hc_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV12_div_periph_cpu_lit_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV12_div_periph_cpu_lit_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV12_bitmasken_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV12_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sel_ddrcpll : 4;
        unsigned int ddrc_clk_sw_req_cfg : 2;
        unsigned int div_ddrc_pll : 5;
        unsigned int reserved : 1;
        unsigned int sel_qice_ref : 1;
        unsigned int sel_ddrcsys : 1;
        unsigned int div_clk_sys_ddr : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_CLKDIV13_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV13_sel_ddrcpll_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV13_sel_ddrcpll_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV13_ddrc_clk_sw_req_cfg_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV13_ddrc_clk_sw_req_cfg_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV13_div_ddrc_pll_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV13_div_ddrc_pll_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV13_sel_qice_ref_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV13_sel_qice_ref_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV13_sel_ddrcsys_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV13_sel_ddrcsys_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV13_div_clk_sys_ddr_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV13_div_clk_sys_ddr_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV13_bitmasken_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV13_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddrc_autogt_bypass_ddr_xpu : 1;
        unsigned int peri_auto_bypass_a : 1;
        unsigned int peri_auto_bypass_b : 1;
        unsigned int peri_auto_bypass_c : 1;
        unsigned int peri_auto_bypass_d : 1;
        unsigned int ddrc_autogt_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int sc_gt_clk_ddrc_sys : 1;
        unsigned int sc_gt_clk_ddrc_pll : 1;
        unsigned int sc_gt_clk_ddrc_sw : 1;
        unsigned int sc_gt_clk_ddrc_fll : 1;
        unsigned int dmc_glitch_free_en_d : 1;
        unsigned int dmc_glitch_free_en_c : 1;
        unsigned int dmc_glitch_free_en_b : 1;
        unsigned int dmc_glitch_free_en_a : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_ddrc_autogt_bypass_ddr_xpu_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_ddrc_autogt_bypass_ddr_xpu_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_peri_auto_bypass_a_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_peri_auto_bypass_a_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_peri_auto_bypass_b_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_peri_auto_bypass_b_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_peri_auto_bypass_c_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_peri_auto_bypass_c_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_peri_auto_bypass_d_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_peri_auto_bypass_d_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_ddrc_autogt_bypass_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_ddrc_autogt_bypass_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_sc_gt_clk_ddrc_sys_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_sc_gt_clk_ddrc_sys_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_sc_gt_clk_ddrc_pll_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_sc_gt_clk_ddrc_pll_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_sc_gt_clk_ddrc_sw_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_sc_gt_clk_ddrc_sw_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_sc_gt_clk_ddrc_fll_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_sc_gt_clk_ddrc_fll_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_dmc_glitch_free_en_d_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_dmc_glitch_free_en_d_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_dmc_glitch_free_en_c_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_dmc_glitch_free_en_c_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_dmc_glitch_free_en_b_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_dmc_glitch_free_en_b_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_dmc_glitch_free_en_a_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_dmc_glitch_free_en_a_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_bitmasken_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV14_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_qice_ref : 6;
        unsigned int div_clk_qice_cfg : 2;
        unsigned int div_clk_ffts : 2;
        unsigned int div_clk_syscache_cfg : 2;
        unsigned int div_ddrc_fll : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_CLKDIV15_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV15_div_qice_ref_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV15_div_qice_ref_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV15_div_clk_qice_cfg_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV15_div_clk_qice_cfg_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV15_div_clk_ffts_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV15_div_clk_ffts_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV15_div_clk_syscache_cfg_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV15_div_clk_syscache_cfg_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV15_div_ddrc_fll_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV15_div_ddrc_fll_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV15_bitmasken_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV15_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_atclk_cpu_lit_from_top : 6;
        unsigned int div_atclk_cpu_hc_from_top : 6;
        unsigned int sel_atclk_cpu_lit_from_top : 1;
        unsigned int sel_atclk_cpu_hc_from_top : 1;
        unsigned int reserved : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_CLKDIV16_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV16_div_atclk_cpu_lit_from_top_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV16_div_atclk_cpu_lit_from_top_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV16_div_atclk_cpu_hc_from_top_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV16_div_atclk_cpu_hc_from_top_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV16_sel_atclk_cpu_lit_from_top_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV16_sel_atclk_cpu_lit_from_top_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV16_sel_atclk_cpu_hc_from_top_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV16_sel_atclk_cpu_hc_from_top_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV16_bitmasken_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV16_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_pim : 6;
        unsigned int div_ocr_acpu : 6;
        unsigned int dmc_bypass_mode_a : 1;
        unsigned int dmc_bypass_mode_b : 1;
        unsigned int dmc_bypass_mode_c : 1;
        unsigned int dmc_bypass_mode_d : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_CLKDIV17_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV17_div_pim_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV17_div_pim_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV17_div_ocr_acpu_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV17_div_ocr_acpu_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV17_dmc_bypass_mode_a_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV17_dmc_bypass_mode_a_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV17_dmc_bypass_mode_b_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV17_dmc_bypass_mode_b_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV17_dmc_bypass_mode_c_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV17_dmc_bypass_mode_c_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV17_dmc_bypass_mode_d_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV17_dmc_bypass_mode_d_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV17_bitmasken_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV17_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_gt_clk_ocr_acpu : 1;
        unsigned int sc_gt_clk_cpu_gic_fll : 1;
        unsigned int sc_gt_clk_periph_cpu_fll : 1;
        unsigned int sc_gt_clk_periph_cpu_hc_fll : 1;
        unsigned int sc_gt_clk_periph_cpu_lit_fll : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int sc_gt_clk_core_crg_apb_fll : 1;
        unsigned int sc_gt_clk_dmc_sys_fll : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_CLKDIV18_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV18_sc_gt_clk_ocr_acpu_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV18_sc_gt_clk_ocr_acpu_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV18_sc_gt_clk_cpu_gic_fll_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV18_sc_gt_clk_cpu_gic_fll_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV18_sc_gt_clk_periph_cpu_fll_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV18_sc_gt_clk_periph_cpu_fll_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV18_sc_gt_clk_periph_cpu_hc_fll_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV18_sc_gt_clk_periph_cpu_hc_fll_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV18_sc_gt_clk_periph_cpu_lit_fll_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV18_sc_gt_clk_periph_cpu_lit_fll_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV18_sc_gt_clk_core_crg_apb_fll_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV18_sc_gt_clk_core_crg_apb_fll_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV18_sc_gt_clk_dmc_sys_fll_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV18_sc_gt_clk_dmc_sys_fll_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV18_bitmasken_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV18_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_cpu_gic_fll : 6;
        unsigned int reserved : 5;
        unsigned int sel_dmc_sys : 1;
        unsigned int div_dmc_sys_fll : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_CLKDIV19_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV19_div_cpu_gic_fll_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV19_div_cpu_gic_fll_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV19_sel_dmc_sys_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV19_sel_dmc_sys_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV19_div_dmc_sys_fll_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV19_div_dmc_sys_fll_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV19_bitmasken_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV19_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_periph_cpu_fll : 6;
        unsigned int div_periph_cpu_hc_fll : 6;
        unsigned int reserved : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_CLKDIV20_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV20_div_periph_cpu_fll_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV20_div_periph_cpu_fll_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV20_div_periph_cpu_hc_fll_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV20_div_periph_cpu_hc_fll_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV20_bitmasken_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV20_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_periph_cpu_lit_fll : 6;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_CLKDIV21_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV21_div_periph_cpu_lit_fll_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV21_div_periph_cpu_lit_fll_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV21_bitmasken_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV21_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 1;
        unsigned int sc_gt_clk_ffts_ref : 1;
        unsigned int div_ffts_ref : 3;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 5;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_CLKDIV22_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV22_sc_gt_clk_ffts_ref_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV22_sc_gt_clk_ffts_ref_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV22_div_ffts_ref_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV22_div_ffts_ref_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV22_bitmasken_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV22_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 5;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 8;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_CLKDIV23_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV23_bitmasken_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV23_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_qic_hsdt1_fll : 4;
        unsigned int div_qic_hsdt1 : 6;
        unsigned int div_qic_hsdt : 6;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_CLKDIV24_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV24_div_qic_hsdt1_fll_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV24_div_qic_hsdt1_fll_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV24_div_qic_hsdt1_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV24_div_qic_hsdt1_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV24_div_qic_hsdt_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV24_div_qic_hsdt_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV24_bitmasken_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV24_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_gt_clk_qic_hsdt_pll : 1;
        unsigned int reserved_0 : 1;
        unsigned int sel_qic_hsdt_pll : 1;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 6;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int sc_gt_clk_qic_hsdt_fll : 1;
        unsigned int reserved_6 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_CLKDIV25_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV25_sc_gt_clk_qic_hsdt_pll_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV25_sc_gt_clk_qic_hsdt_pll_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV25_sel_qic_hsdt_pll_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV25_sel_qic_hsdt_pll_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV25_sc_gt_clk_qic_hsdt_fll_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV25_sc_gt_clk_qic_hsdt_fll_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV25_bitmasken_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV25_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int sc_gt_clk_qic_hsdt1_fll : 1;
        unsigned int sc_gt_clk_qic_hsdt1_pll : 1;
        unsigned int reserved_1 : 1;
        unsigned int div_hsdt_fll : 4;
        unsigned int qic_hsdt_clk_sw_req_cfg : 2;
        unsigned int qic_hsdt1_clk_sw_req_cfg : 2;
        unsigned int reserved_2 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_CLKDIV26_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV26_sc_gt_clk_qic_hsdt1_fll_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV26_sc_gt_clk_qic_hsdt1_fll_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV26_sc_gt_clk_qic_hsdt1_pll_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV26_sc_gt_clk_qic_hsdt1_pll_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV26_div_hsdt_fll_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV26_div_hsdt_fll_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV26_qic_hsdt_clk_sw_req_cfg_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV26_qic_hsdt_clk_sw_req_cfg_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV26_qic_hsdt1_clk_sw_req_cfg_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV26_qic_hsdt1_clk_sw_req_cfg_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV26_bitmasken_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_CLKDIV26_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hw_dfa_dvfs_en_ppll1_bypass : 1;
        unsigned int hw_dfa_dvfs_en_ppll2_bypass : 1;
        unsigned int hw_dfa_dvfs_en_ppll2_b_bypass : 1;
        unsigned int hw_dfa_dvfs_en_ppll7_bypass : 1;
        unsigned int hw_dfa_dvfs_en_ppll1 : 1;
        unsigned int hw_dfa_dvfs_lock_ppll1 : 1;
        unsigned int hw_dfa_dvfs_lock_ppll2 : 1;
        unsigned int hw_dfa_dvfs_lock_ppll2_b : 1;
        unsigned int hw_dfa_dvfs_lock_ppll7 : 1;
        unsigned int hw_dfa_dvfs_intr_ppll1 : 1;
        unsigned int hw_dfa_dvfs_intr_ppll2 : 1;
        unsigned int hw_dfa_dvfs_intr_ppll2_b : 1;
        unsigned int hw_dfa_dvfs_intr_ppll7 : 1;
        unsigned int hw_dfa_dvfs_en_ppll2 : 1;
        unsigned int hw_dfa_dvfs_en_ppll2_b : 1;
        unsigned int hw_dfa_dvfs_en_ppll7 : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_CRGPERIPH_PLL_DVFS_CTRL_UNION;
#endif
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_en_ppll1_bypass_START (0)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_en_ppll1_bypass_END (0)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_en_ppll2_bypass_START (1)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_en_ppll2_bypass_END (1)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_en_ppll2_b_bypass_START (2)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_en_ppll2_b_bypass_END (2)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_en_ppll7_bypass_START (3)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_en_ppll7_bypass_END (3)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_en_ppll1_START (4)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_en_ppll1_END (4)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_lock_ppll1_START (5)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_lock_ppll1_END (5)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_lock_ppll2_START (6)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_lock_ppll2_END (6)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_lock_ppll2_b_START (7)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_lock_ppll2_b_END (7)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_lock_ppll7_START (8)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_lock_ppll7_END (8)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_intr_ppll1_START (9)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_intr_ppll1_END (9)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_intr_ppll2_START (10)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_intr_ppll2_END (10)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_intr_ppll2_b_START (11)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_intr_ppll2_b_END (11)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_intr_ppll7_START (12)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_intr_ppll7_END (12)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_en_ppll2_START (13)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_en_ppll2_END (13)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_en_ppll2_b_START (14)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_en_ppll2_b_END (14)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_en_ppll7_START (15)
#define SOC_CRGPERIPH_PLL_DVFS_CTRL_hw_dfa_dvfs_en_ppll7_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pll6_fsm_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int pll6_vote_mode_sel : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int pll6_intr_clr : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PLL_FSM_CTRL0_1_UNION;
#endif
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_1_pll6_fsm_en_START (0)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_1_pll6_fsm_en_END (0)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_1_pll6_vote_mode_sel_START (5)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_1_pll6_vote_mode_sel_END (5)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_1_pll6_intr_clr_START (10)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_1_pll6_intr_clr_END (10)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_1_bitmasken_START (16)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_1_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pll1_fsm_en : 1;
        unsigned int pll2_fsm_en : 1;
        unsigned int pll2_b_fsm_en : 1;
        unsigned int pll3_fsm_en : 1;
        unsigned int pll7_fsm_en : 1;
        unsigned int pll1_vote_mode_sel : 1;
        unsigned int pll2_vote_mode_sel : 1;
        unsigned int pll2_b_vote_mode_sel : 1;
        unsigned int pll3_vote_mode_sel : 1;
        unsigned int pll7_vote_mode_sel : 1;
        unsigned int pll1_intr_clr : 1;
        unsigned int pll2_intr_clr : 1;
        unsigned int pll2_b_intr_clr : 1;
        unsigned int pll3_intr_clr : 1;
        unsigned int pll7_intr_clr : 1;
        unsigned int reserved : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PLL_FSM_CTRL0_UNION;
#endif
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll1_fsm_en_START (0)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll1_fsm_en_END (0)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll2_fsm_en_START (1)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll2_fsm_en_END (1)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll2_b_fsm_en_START (2)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll2_b_fsm_en_END (2)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll3_fsm_en_START (3)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll3_fsm_en_END (3)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll7_fsm_en_START (4)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll7_fsm_en_END (4)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll1_vote_mode_sel_START (5)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll1_vote_mode_sel_END (5)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll2_vote_mode_sel_START (6)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll2_vote_mode_sel_END (6)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll2_b_vote_mode_sel_START (7)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll2_b_vote_mode_sel_END (7)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll3_vote_mode_sel_START (8)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll3_vote_mode_sel_END (8)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll7_vote_mode_sel_START (9)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll7_vote_mode_sel_END (9)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll1_intr_clr_START (10)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll1_intr_clr_END (10)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll2_intr_clr_START (11)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll2_intr_clr_END (11)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll2_b_intr_clr_START (12)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll2_b_intr_clr_END (12)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll3_intr_clr_START (13)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll3_intr_clr_END (13)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll7_intr_clr_START (14)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_pll7_intr_clr_END (14)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_bitmasken_START (16)
#define SOC_CRGPERIPH_PLL_FSM_CTRL0_bitmasken_END (31)
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
} SOC_CRGPERIPH_PLL_FSM_CTRL1_UNION;
#endif
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_pll_lock_dbc_en_START (0)
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_pll_lock_dbc_en_END (0)
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_pll_fsm_intr_en_START (1)
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_pll_fsm_intr_en_END (1)
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_pll_wait_en_START (2)
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_pll_wait_en_END (2)
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_pll_timeout_en_START (3)
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_pll_timeout_en_END (3)
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_pll_intr_lmt_START (4)
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_pll_intr_lmt_END (6)
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_pll_wait_lmt_START (7)
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_pll_wait_lmt_END (14)
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_pll_timeout_lmt_START (15)
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_pll_timeout_lmt_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pll1_intr_cnt : 3;
        unsigned int pll2_intr_cnt : 3;
        unsigned int pll2_b_intr_cnt : 3;
        unsigned int pll3_intr_cnt : 3;
        unsigned int pll7_intr_cnt : 3;
        unsigned int pll6_intr_cnt : 3;
        unsigned int reserved : 5;
        unsigned int pll6_fsm_intr : 1;
        unsigned int pll1_fsm_intr : 1;
        unsigned int pll2_fsm_intr : 1;
        unsigned int ppll2_b_fsm_intr : 1;
        unsigned int pll3_fsm_intr : 1;
        unsigned int pll7_fsm_intr : 1;
        unsigned int aupll_fsm_intr : 1;
        unsigned int pll5_fsm_intr : 1;
        unsigned int intr_pll_fsm : 1;
    } reg;
} SOC_CRGPERIPH_PLL_FSM_STAT0_UNION;
#endif
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll1_intr_cnt_START (0)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll1_intr_cnt_END (2)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll2_intr_cnt_START (3)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll2_intr_cnt_END (5)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll2_b_intr_cnt_START (6)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll2_b_intr_cnt_END (8)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll3_intr_cnt_START (9)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll3_intr_cnt_END (11)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll7_intr_cnt_START (12)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll7_intr_cnt_END (14)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll6_intr_cnt_START (15)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll6_intr_cnt_END (17)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll6_fsm_intr_START (23)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll6_fsm_intr_END (23)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll1_fsm_intr_START (24)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll1_fsm_intr_END (24)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll2_fsm_intr_START (25)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll2_fsm_intr_END (25)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_ppll2_b_fsm_intr_START (26)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_ppll2_b_fsm_intr_END (26)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll3_fsm_intr_START (27)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll3_fsm_intr_END (27)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll7_fsm_intr_START (28)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll7_fsm_intr_END (28)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_aupll_fsm_intr_START (29)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_aupll_fsm_intr_END (29)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll5_fsm_intr_START (30)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll5_fsm_intr_END (30)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_intr_pll_fsm_START (31)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_intr_pll_fsm_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pll1_curr_stat : 4;
        unsigned int pll2_curr_stat : 4;
        unsigned int pll2_b_curr_stat : 4;
        unsigned int pll3_curr_stat : 4;
        unsigned int pll7_curr_stat : 4;
        unsigned int pll6_curr_stat : 4;
        unsigned int reserved : 8;
    } reg;
} SOC_CRGPERIPH_PLL_FSM_STAT1_UNION;
#endif
#define SOC_CRGPERIPH_PLL_FSM_STAT1_pll1_curr_stat_START (0)
#define SOC_CRGPERIPH_PLL_FSM_STAT1_pll1_curr_stat_END (3)
#define SOC_CRGPERIPH_PLL_FSM_STAT1_pll2_curr_stat_START (4)
#define SOC_CRGPERIPH_PLL_FSM_STAT1_pll2_curr_stat_END (7)
#define SOC_CRGPERIPH_PLL_FSM_STAT1_pll2_b_curr_stat_START (8)
#define SOC_CRGPERIPH_PLL_FSM_STAT1_pll2_b_curr_stat_END (11)
#define SOC_CRGPERIPH_PLL_FSM_STAT1_pll3_curr_stat_START (12)
#define SOC_CRGPERIPH_PLL_FSM_STAT1_pll3_curr_stat_END (15)
#define SOC_CRGPERIPH_PLL_FSM_STAT1_pll7_curr_stat_START (16)
#define SOC_CRGPERIPH_PLL_FSM_STAT1_pll7_curr_stat_END (19)
#define SOC_CRGPERIPH_PLL_FSM_STAT1_pll6_curr_stat_START (20)
#define SOC_CRGPERIPH_PLL_FSM_STAT1_pll6_curr_stat_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int ppll1_gt_stat : 1;
        unsigned int ppll2_gt_stat : 1;
        unsigned int ppll2_b_gt_stat : 1;
        unsigned int ppll3_gt_stat : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int ppll6_gt_stat : 1;
        unsigned int ppll7_gt_stat : 1;
        unsigned int reserved_3 : 1;
        unsigned int ppll1_bypass : 1;
        unsigned int ppll2_bypass : 1;
        unsigned int ppll2_b_bypass : 1;
        unsigned int ppll3_bypass : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int ppll6_bypass : 1;
        unsigned int ppll7_bypass : 1;
        unsigned int reserved_6 : 1;
        unsigned int ppll1_en_stat : 1;
        unsigned int ppll2_en_stat : 1;
        unsigned int ppll2_b_en_stat : 1;
        unsigned int ppll3_en_stat : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int ppll6_en_stat : 1;
        unsigned int ppll7_en_stat : 1;
        unsigned int reserved_9 : 5;
    } reg;
} SOC_CRGPERIPH_PLL_VOTE_STAT0_UNION;
#endif
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll1_gt_stat_START (1)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll1_gt_stat_END (1)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll2_gt_stat_START (2)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll2_gt_stat_END (2)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll2_b_gt_stat_START (3)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll2_b_gt_stat_END (3)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll3_gt_stat_START (4)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll3_gt_stat_END (4)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll6_gt_stat_START (7)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll6_gt_stat_END (7)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll7_gt_stat_START (8)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll7_gt_stat_END (8)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll1_bypass_START (10)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll1_bypass_END (10)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll2_bypass_START (11)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll2_bypass_END (11)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll2_b_bypass_START (12)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll2_b_bypass_END (12)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll3_bypass_START (13)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll3_bypass_END (13)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll6_bypass_START (16)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll6_bypass_END (16)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll7_bypass_START (17)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll7_bypass_END (17)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll1_en_stat_START (19)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll1_en_stat_END (19)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll2_en_stat_START (20)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll2_en_stat_END (20)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll2_b_en_stat_START (21)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll2_b_en_stat_END (21)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll3_en_stat_START (22)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll3_en_stat_END (22)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll6_en_stat_START (25)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll6_en_stat_END (25)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll7_en_stat_START (26)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll7_en_stat_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ppll1_en_vote : 5;
        unsigned int ppll2_en_vote : 5;
        unsigned int ppll3_en_vote : 5;
        unsigned int reserved : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PLL_EN_VOTE_CTRL0_UNION;
#endif
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL0_ppll1_en_vote_START (0)
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL0_ppll1_en_vote_END (4)
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL0_ppll2_en_vote_START (5)
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL0_ppll2_en_vote_END (9)
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL0_ppll3_en_vote_START (10)
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL0_ppll3_en_vote_END (14)
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL0_bitmasken_START (16)
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ppll1_gt_vote : 5;
        unsigned int ppll2_gt_vote : 5;
        unsigned int ppll3_gt_vote : 5;
        unsigned int reserved : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PLL_GT_VOTE_CTRL0_UNION;
#endif
#define SOC_CRGPERIPH_PLL_GT_VOTE_CTRL0_ppll1_gt_vote_START (0)
#define SOC_CRGPERIPH_PLL_GT_VOTE_CTRL0_ppll1_gt_vote_END (4)
#define SOC_CRGPERIPH_PLL_GT_VOTE_CTRL0_ppll2_gt_vote_START (5)
#define SOC_CRGPERIPH_PLL_GT_VOTE_CTRL0_ppll2_gt_vote_END (9)
#define SOC_CRGPERIPH_PLL_GT_VOTE_CTRL0_ppll3_gt_vote_START (10)
#define SOC_CRGPERIPH_PLL_GT_VOTE_CTRL0_ppll3_gt_vote_END (14)
#define SOC_CRGPERIPH_PLL_GT_VOTE_CTRL0_bitmasken_START (16)
#define SOC_CRGPERIPH_PLL_GT_VOTE_CTRL0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ppll1_bypass_vote : 5;
        unsigned int ppll2_bypass_vote : 5;
        unsigned int ppll3_bypass_vote : 5;
        unsigned int reserved : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PLL_BYPASS_VOTE_CTRL0_UNION;
#endif
#define SOC_CRGPERIPH_PLL_BYPASS_VOTE_CTRL0_ppll1_bypass_vote_START (0)
#define SOC_CRGPERIPH_PLL_BYPASS_VOTE_CTRL0_ppll1_bypass_vote_END (4)
#define SOC_CRGPERIPH_PLL_BYPASS_VOTE_CTRL0_ppll2_bypass_vote_START (5)
#define SOC_CRGPERIPH_PLL_BYPASS_VOTE_CTRL0_ppll2_bypass_vote_END (9)
#define SOC_CRGPERIPH_PLL_BYPASS_VOTE_CTRL0_ppll3_bypass_vote_START (10)
#define SOC_CRGPERIPH_PLL_BYPASS_VOTE_CTRL0_ppll3_bypass_vote_END (14)
#define SOC_CRGPERIPH_PLL_BYPASS_VOTE_CTRL0_bitmasken_START (16)
#define SOC_CRGPERIPH_PLL_BYPASS_VOTE_CTRL0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 5;
        unsigned int ppll6_en_vote : 5;
        unsigned int ppll7_en_vote : 5;
        unsigned int reserved_1 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PLL_EN_VOTE_CTRL1_UNION;
#endif
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL1_ppll6_en_vote_START (5)
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL1_ppll6_en_vote_END (9)
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL1_ppll7_en_vote_START (10)
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL1_ppll7_en_vote_END (14)
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL1_bitmasken_START (16)
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL1_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 5;
        unsigned int ppll6_gt_vote : 5;
        unsigned int ppll7_gt_vote : 5;
        unsigned int reserved_1 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PLL_GT_VOTE_CTRL1_UNION;
#endif
#define SOC_CRGPERIPH_PLL_GT_VOTE_CTRL1_ppll6_gt_vote_START (5)
#define SOC_CRGPERIPH_PLL_GT_VOTE_CTRL1_ppll6_gt_vote_END (9)
#define SOC_CRGPERIPH_PLL_GT_VOTE_CTRL1_ppll7_gt_vote_START (10)
#define SOC_CRGPERIPH_PLL_GT_VOTE_CTRL1_ppll7_gt_vote_END (14)
#define SOC_CRGPERIPH_PLL_GT_VOTE_CTRL1_bitmasken_START (16)
#define SOC_CRGPERIPH_PLL_GT_VOTE_CTRL1_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 5;
        unsigned int ppll6_bypass_vote : 5;
        unsigned int ppll7_bypass_vote : 5;
        unsigned int reserved_1 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PLL_BYPASS_VOTE_CTRL1_UNION;
#endif
#define SOC_CRGPERIPH_PLL_BYPASS_VOTE_CTRL1_ppll6_bypass_vote_START (5)
#define SOC_CRGPERIPH_PLL_BYPASS_VOTE_CTRL1_ppll6_bypass_vote_END (9)
#define SOC_CRGPERIPH_PLL_BYPASS_VOTE_CTRL1_ppll7_bypass_vote_START (10)
#define SOC_CRGPERIPH_PLL_BYPASS_VOTE_CTRL1_ppll7_bypass_vote_END (14)
#define SOC_CRGPERIPH_PLL_BYPASS_VOTE_CTRL1_bitmasken_START (16)
#define SOC_CRGPERIPH_PLL_BYPASS_VOTE_CTRL1_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 5;
        unsigned int reserved_1 : 5;
        unsigned int ppll2_b_en_vote : 5;
        unsigned int reserved_2 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PLL_EN_VOTE_CTRL2_UNION;
#endif
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL2_ppll2_b_en_vote_START (10)
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL2_ppll2_b_en_vote_END (14)
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL2_bitmasken_START (16)
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL2_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 5;
        unsigned int reserved_1 : 5;
        unsigned int ppll2_b_gt_vote : 5;
        unsigned int reserved_2 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PLL_GT_VOTE_CTRL2_UNION;
#endif
#define SOC_CRGPERIPH_PLL_GT_VOTE_CTRL2_ppll2_b_gt_vote_START (10)
#define SOC_CRGPERIPH_PLL_GT_VOTE_CTRL2_ppll2_b_gt_vote_END (14)
#define SOC_CRGPERIPH_PLL_GT_VOTE_CTRL2_bitmasken_START (16)
#define SOC_CRGPERIPH_PLL_GT_VOTE_CTRL2_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 5;
        unsigned int reserved_1 : 5;
        unsigned int ppll2_b_bypass_vote : 5;
        unsigned int reserved_2 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PLL_BYPASS_VOTE_CTRL2_UNION;
#endif
#define SOC_CRGPERIPH_PLL_BYPASS_VOTE_CTRL2_ppll2_b_bypass_vote_START (10)
#define SOC_CRGPERIPH_PLL_BYPASS_VOTE_CTRL2_ppll2_b_bypass_vote_END (14)
#define SOC_CRGPERIPH_PLL_BYPASS_VOTE_CTRL2_bitmasken_START (16)
#define SOC_CRGPERIPH_PLL_BYPASS_VOTE_CTRL2_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_pll_stat_sel : 4;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 10;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PERI_FNPLL_STAT_SEL_UNION;
#endif
#define SOC_CRGPERIPH_PERI_FNPLL_STAT_SEL_peri_pll_stat_sel_START (0)
#define SOC_CRGPERIPH_PERI_FNPLL_STAT_SEL_peri_pll_stat_sel_END (3)
#define SOC_CRGPERIPH_PERI_FNPLL_STAT_SEL_bitmasken_START (16)
#define SOC_CRGPERIPH_PERI_FNPLL_STAT_SEL_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_dmss2dmc_rs : 1;
        unsigned int ip_rst_mdmperi : 1;
        unsigned int ip_prst_gpio0_se : 1;
        unsigned int ip_arst_ddrc : 1;
        unsigned int ip_rst_ffts : 1;
        unsigned int ip_rst_hsdt : 1;
        unsigned int ip_rst_modem : 1;
        unsigned int ip_rst_lpmcu : 1;
        unsigned int ip_rst_cpu_pctrl : 1;
        unsigned int ip_rst_npu_pctrl : 1;
        unsigned int ip_rst_media2_pctrl : 1;
        unsigned int ip_rst_media1_pctrl : 1;
        unsigned int ip_prst_pctrl : 1;
        unsigned int ip_rst_noc_dmc_a : 1;
        unsigned int ip_rst_noc_dmc_b : 1;
        unsigned int ip_rst_noc_dmc_c : 1;
        unsigned int ip_rst_noc_dmc_d : 1;
        unsigned int ip_rst_dmss2dmc_rs_r : 1;
        unsigned int ip_rst_dmss2dmc_rs_l : 1;
        unsigned int ip_hrst_ddrc_dmux : 1;
        unsigned int ip_rst_uce_qic_d : 1;
        unsigned int ip_rst_uce_qic_c : 1;
        unsigned int ip_rst_uce_qic_b : 1;
        unsigned int ip_rst_uce_qic_a : 1;
        unsigned int ip_rst_peri_dmc_d : 1;
        unsigned int ip_rst_peri_dmc_c : 1;
        unsigned int ip_rst_peri_dmc_b : 1;
        unsigned int ip_rst_peri_dmc_a : 1;
        unsigned int ip_rst_peri_dmc_crg_d : 1;
        unsigned int ip_rst_peri_dmc_crg_c : 1;
        unsigned int ip_rst_peri_dmc_crg_b : 1;
        unsigned int ip_rst_peri_dmc_crg_a : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_RSTEN_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_dmss2dmc_rs_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_dmss2dmc_rs_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_mdmperi_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_mdmperi_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_prst_gpio0_se_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_prst_gpio0_se_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_arst_ddrc_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_arst_ddrc_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_ffts_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_ffts_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_hsdt_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_hsdt_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_modem_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_modem_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_lpmcu_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_lpmcu_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_cpu_pctrl_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_cpu_pctrl_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_npu_pctrl_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_npu_pctrl_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_media2_pctrl_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_media2_pctrl_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_media1_pctrl_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_media1_pctrl_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_prst_pctrl_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_prst_pctrl_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_noc_dmc_a_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_noc_dmc_a_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_noc_dmc_b_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_noc_dmc_b_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_noc_dmc_c_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_noc_dmc_c_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_noc_dmc_d_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_noc_dmc_d_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_dmss2dmc_rs_r_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_dmss2dmc_rs_r_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_dmss2dmc_rs_l_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_dmss2dmc_rs_l_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_hrst_ddrc_dmux_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_hrst_ddrc_dmux_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_uce_qic_d_START (20)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_uce_qic_d_END (20)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_uce_qic_c_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_uce_qic_c_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_uce_qic_b_START (22)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_uce_qic_b_END (22)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_uce_qic_a_START (23)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_uce_qic_a_END (23)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_peri_dmc_d_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_peri_dmc_d_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_peri_dmc_c_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_peri_dmc_c_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_peri_dmc_b_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_peri_dmc_b_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_peri_dmc_a_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_peri_dmc_a_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_peri_dmc_crg_d_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_peri_dmc_crg_d_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_peri_dmc_crg_c_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_peri_dmc_crg_c_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_peri_dmc_crg_b_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_peri_dmc_crg_b_END (30)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_peri_dmc_crg_a_START (31)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN_ip_rst_peri_dmc_crg_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_dmss2dmc_rs : 1;
        unsigned int ip_rst_mdmperi : 1;
        unsigned int ip_prst_gpio0_se : 1;
        unsigned int ip_arst_ddrc : 1;
        unsigned int ip_rst_ffts : 1;
        unsigned int ip_rst_hsdt : 1;
        unsigned int ip_rst_modem : 1;
        unsigned int ip_rst_lpmcu : 1;
        unsigned int ip_rst_cpu_pctrl : 1;
        unsigned int ip_rst_npu_pctrl : 1;
        unsigned int ip_rst_media2_pctrl : 1;
        unsigned int ip_rst_media1_pctrl : 1;
        unsigned int ip_prst_pctrl : 1;
        unsigned int ip_rst_noc_dmc_a : 1;
        unsigned int ip_rst_noc_dmc_b : 1;
        unsigned int ip_rst_noc_dmc_c : 1;
        unsigned int ip_rst_noc_dmc_d : 1;
        unsigned int ip_rst_dmss2dmc_rs_r : 1;
        unsigned int ip_rst_dmss2dmc_rs_l : 1;
        unsigned int ip_hrst_ddrc_dmux : 1;
        unsigned int ip_rst_uce_qic_d : 1;
        unsigned int ip_rst_uce_qic_c : 1;
        unsigned int ip_rst_uce_qic_b : 1;
        unsigned int ip_rst_uce_qic_a : 1;
        unsigned int ip_rst_peri_dmc_d : 1;
        unsigned int ip_rst_peri_dmc_c : 1;
        unsigned int ip_rst_peri_dmc_b : 1;
        unsigned int ip_rst_peri_dmc_a : 1;
        unsigned int ip_rst_peri_dmc_crg_d : 1;
        unsigned int ip_rst_peri_dmc_crg_c : 1;
        unsigned int ip_rst_peri_dmc_crg_b : 1;
        unsigned int ip_rst_peri_dmc_crg_a : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_dmss2dmc_rs_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_dmss2dmc_rs_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_mdmperi_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_mdmperi_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_prst_gpio0_se_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_prst_gpio0_se_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_arst_ddrc_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_arst_ddrc_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_ffts_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_ffts_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_hsdt_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_hsdt_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_modem_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_modem_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_lpmcu_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_lpmcu_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_cpu_pctrl_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_cpu_pctrl_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_npu_pctrl_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_npu_pctrl_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_media2_pctrl_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_media2_pctrl_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_media1_pctrl_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_media1_pctrl_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_prst_pctrl_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_prst_pctrl_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_noc_dmc_a_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_noc_dmc_a_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_noc_dmc_b_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_noc_dmc_b_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_noc_dmc_c_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_noc_dmc_c_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_noc_dmc_d_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_noc_dmc_d_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_dmss2dmc_rs_r_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_dmss2dmc_rs_r_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_dmss2dmc_rs_l_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_dmss2dmc_rs_l_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_hrst_ddrc_dmux_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_hrst_ddrc_dmux_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_uce_qic_d_START (20)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_uce_qic_d_END (20)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_uce_qic_c_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_uce_qic_c_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_uce_qic_b_START (22)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_uce_qic_b_END (22)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_uce_qic_a_START (23)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_uce_qic_a_END (23)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_peri_dmc_d_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_peri_dmc_d_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_peri_dmc_c_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_peri_dmc_c_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_peri_dmc_b_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_peri_dmc_b_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_peri_dmc_a_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_peri_dmc_a_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_peri_dmc_crg_d_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_peri_dmc_crg_d_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_peri_dmc_crg_c_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_peri_dmc_crg_c_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_peri_dmc_crg_b_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_peri_dmc_crg_b_END (30)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_peri_dmc_crg_a_START (31)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS_ip_rst_peri_dmc_crg_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int ip_rst_mdmperi : 1;
        unsigned int ip_prst_gpio0_se : 1;
        unsigned int ip_arst_ddrc : 1;
        unsigned int ip_rst_ffts : 1;
        unsigned int ip_rst_hsdt : 1;
        unsigned int ip_rst_modem : 1;
        unsigned int ip_rst_lpmcu : 1;
        unsigned int ip_rst_cpu_pctrl : 1;
        unsigned int ip_rst_npu_pctrl : 1;
        unsigned int ip_rst_media2_pctrl : 1;
        unsigned int ip_rst_media1_pctrl : 1;
        unsigned int ip_prst_pctrl : 1;
        unsigned int ip_rst_noc_dmc_a : 1;
        unsigned int ip_rst_noc_dmc_b : 1;
        unsigned int ip_rst_noc_dmc_c : 1;
        unsigned int ip_rst_noc_dmc_d : 1;
        unsigned int ip_rst_dmss2dmc_rs_r : 1;
        unsigned int ip_rst_dmss2dmc_rs_l : 1;
        unsigned int ip_hrst_ddrc_dmux : 1;
        unsigned int ip_rst_uce_qic_d : 1;
        unsigned int ip_rst_uce_qic_c : 1;
        unsigned int ip_rst_uce_qic_b : 1;
        unsigned int ip_rst_uce_qic_a : 1;
        unsigned int ip_rst_peri_dmc_d : 1;
        unsigned int ip_rst_peri_dmc_c : 1;
        unsigned int ip_rst_peri_dmc_b : 1;
        unsigned int ip_rst_peri_dmc_a : 1;
        unsigned int ip_rst_peri_dmc_crg_d : 1;
        unsigned int ip_rst_peri_dmc_crg_c : 1;
        unsigned int ip_rst_peri_dmc_crg_b : 1;
        unsigned int ip_rst_peri_dmc_crg_a : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_mdmperi_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_mdmperi_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_prst_gpio0_se_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_prst_gpio0_se_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_arst_ddrc_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_arst_ddrc_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_ffts_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_ffts_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_hsdt_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_hsdt_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_modem_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_modem_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_lpmcu_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_lpmcu_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_cpu_pctrl_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_cpu_pctrl_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_npu_pctrl_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_npu_pctrl_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_media2_pctrl_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_media2_pctrl_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_media1_pctrl_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_media1_pctrl_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_prst_pctrl_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_prst_pctrl_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_noc_dmc_a_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_noc_dmc_a_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_noc_dmc_b_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_noc_dmc_b_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_noc_dmc_c_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_noc_dmc_c_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_noc_dmc_d_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_noc_dmc_d_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_dmss2dmc_rs_r_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_dmss2dmc_rs_r_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_dmss2dmc_rs_l_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_dmss2dmc_rs_l_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_hrst_ddrc_dmux_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_hrst_ddrc_dmux_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_uce_qic_d_START (20)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_uce_qic_d_END (20)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_uce_qic_c_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_uce_qic_c_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_uce_qic_b_START (22)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_uce_qic_b_END (22)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_uce_qic_a_START (23)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_uce_qic_a_END (23)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_peri_dmc_d_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_peri_dmc_d_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_peri_dmc_c_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_peri_dmc_c_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_peri_dmc_b_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_peri_dmc_b_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_peri_dmc_a_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_peri_dmc_a_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_peri_dmc_crg_d_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_peri_dmc_crg_d_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_peri_dmc_crg_c_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_peri_dmc_crg_c_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_peri_dmc_crg_b_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_peri_dmc_crg_b_END (30)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_peri_dmc_crg_a_START (31)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT_ip_rst_peri_dmc_crg_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_data_qic_gpu : 1;
        unsigned int ip_rst_hsdtbus : 1;
        unsigned int ip_rst_sysbus : 1;
        unsigned int ip_rst_cfgbus : 1;
        unsigned int ip_rst_hsdt_crg : 1;
        unsigned int ip_rst_gpu_crg : 1;
        unsigned int ip_rst_qic_mdmperi_bus : 1;
        unsigned int ip_rst_noc_hsdt1bus : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_media_lp_ctrl_crg : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_media_lp_ctrl : 1;
        unsigned int reserved_3 : 1;
        unsigned int ip_rst_digtsen : 1;
        unsigned int ip_rst_adb_mst_lit : 1;
        unsigned int ip_rst_peri_pd : 1;
        unsigned int ip_rst_pericrg_pd : 1;
        unsigned int ip_rst_data_qic_gpu2qice : 1;
        unsigned int ip_rst_adb_mst_hc0 : 1;
        unsigned int ip_rst_adb_mst_hc1 : 1;
        unsigned int ip_rst_hsdt1_subsys_crg : 1;
        unsigned int ip_rst_hsdt1_subsys : 1;
        unsigned int ip_rst_media2 : 1;
        unsigned int ip_rst_media2_crg : 1;
        unsigned int ip_rst_spi6 : 1;
        unsigned int ip_rst_ocr_acpu : 1;
        unsigned int ip_rst_intr_hub : 1;
        unsigned int ip_rst_npu_qic_cfg_peri : 1;
        unsigned int ip_rst_media2_qic_cfg_peri : 1;
        unsigned int ip_rst_media1_qic_cfg_peri : 1;
        unsigned int ip_rst_pll_fsm : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_data_qic_gpu_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_data_qic_gpu_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_hsdtbus_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_hsdtbus_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_sysbus_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_sysbus_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_cfgbus_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_cfgbus_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_hsdt_crg_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_hsdt_crg_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_gpu_crg_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_gpu_crg_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_qic_mdmperi_bus_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_qic_mdmperi_bus_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_noc_hsdt1bus_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_noc_hsdt1bus_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_media_lp_ctrl_crg_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_media_lp_ctrl_crg_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_media_lp_ctrl_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_media_lp_ctrl_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_digtsen_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_digtsen_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_adb_mst_lit_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_adb_mst_lit_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_peri_pd_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_peri_pd_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_pericrg_pd_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_pericrg_pd_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_data_qic_gpu2qice_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_data_qic_gpu2qice_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_adb_mst_hc0_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_adb_mst_hc0_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_adb_mst_hc1_START (20)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_adb_mst_hc1_END (20)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_hsdt1_subsys_crg_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_hsdt1_subsys_crg_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_hsdt1_subsys_START (22)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_hsdt1_subsys_END (22)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_media2_START (23)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_media2_END (23)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_media2_crg_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_media2_crg_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_spi6_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_spi6_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_ocr_acpu_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_ocr_acpu_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_intr_hub_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_intr_hub_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_npu_qic_cfg_peri_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_npu_qic_cfg_peri_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_media2_qic_cfg_peri_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_media2_qic_cfg_peri_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_media1_qic_cfg_peri_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_media1_qic_cfg_peri_END (30)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_pll_fsm_START (31)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN1_ip_rst_pll_fsm_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_data_qic_gpu : 1;
        unsigned int ip_rst_hsdtbus : 1;
        unsigned int ip_rst_sysbus : 1;
        unsigned int ip_rst_cfgbus : 1;
        unsigned int ip_rst_hsdt_crg : 1;
        unsigned int ip_rst_gpu_crg : 1;
        unsigned int ip_rst_qic_mdmperi_bus : 1;
        unsigned int ip_rst_noc_hsdt1bus : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_media_lp_ctrl_crg : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_media_lp_ctrl : 1;
        unsigned int reserved_3 : 1;
        unsigned int ip_rst_digtsen : 1;
        unsigned int ip_rst_adb_mst_lit : 1;
        unsigned int ip_rst_peri_pd : 1;
        unsigned int ip_rst_pericrg_pd : 1;
        unsigned int ip_rst_data_qic_gpu2qice : 1;
        unsigned int ip_rst_adb_mst_hc0 : 1;
        unsigned int ip_rst_adb_mst_hc1 : 1;
        unsigned int ip_rst_hsdt1_subsys_crg : 1;
        unsigned int ip_rst_hsdt1_subsys : 1;
        unsigned int ip_rst_media2 : 1;
        unsigned int ip_rst_media2_crg : 1;
        unsigned int ip_rst_spi6 : 1;
        unsigned int ip_rst_ocr_acpu : 1;
        unsigned int ip_rst_intr_hub : 1;
        unsigned int ip_rst_npu_qic_cfg_peri : 1;
        unsigned int ip_rst_media2_qic_cfg_peri : 1;
        unsigned int ip_rst_media1_qic_cfg_peri : 1;
        unsigned int ip_rst_pll_fsm : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_data_qic_gpu_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_data_qic_gpu_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_hsdtbus_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_hsdtbus_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_sysbus_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_sysbus_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_cfgbus_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_cfgbus_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_hsdt_crg_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_hsdt_crg_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_gpu_crg_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_gpu_crg_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_qic_mdmperi_bus_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_qic_mdmperi_bus_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_noc_hsdt1bus_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_noc_hsdt1bus_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_media_lp_ctrl_crg_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_media_lp_ctrl_crg_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_media_lp_ctrl_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_media_lp_ctrl_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_digtsen_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_digtsen_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_adb_mst_lit_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_adb_mst_lit_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_peri_pd_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_peri_pd_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_pericrg_pd_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_pericrg_pd_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_data_qic_gpu2qice_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_data_qic_gpu2qice_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_adb_mst_hc0_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_adb_mst_hc0_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_adb_mst_hc1_START (20)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_adb_mst_hc1_END (20)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_hsdt1_subsys_crg_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_hsdt1_subsys_crg_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_hsdt1_subsys_START (22)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_hsdt1_subsys_END (22)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_media2_START (23)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_media2_END (23)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_media2_crg_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_media2_crg_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_spi6_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_spi6_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_ocr_acpu_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_ocr_acpu_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_intr_hub_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_intr_hub_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_npu_qic_cfg_peri_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_npu_qic_cfg_peri_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_media2_qic_cfg_peri_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_media2_qic_cfg_peri_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_media1_qic_cfg_peri_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_media1_qic_cfg_peri_END (30)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_pll_fsm_START (31)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS1_ip_rst_pll_fsm_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_data_qic_gpu : 1;
        unsigned int ip_rst_hsdtbus : 1;
        unsigned int ip_rst_sysbus : 1;
        unsigned int ip_rst_cfgbus : 1;
        unsigned int ip_rst_hsdt_crg : 1;
        unsigned int ip_rst_gpu_crg : 1;
        unsigned int ip_rst_qic_mdmperi_bus : 1;
        unsigned int ip_rst_noc_hsdt1bus : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_media_lp_ctrl_crg : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_media_lp_ctrl : 1;
        unsigned int reserved_3 : 1;
        unsigned int ip_rst_digtsen : 1;
        unsigned int ip_rst_adb_mst_lit : 1;
        unsigned int ip_rst_peri_pd : 1;
        unsigned int ip_rst_pericrg_pd : 1;
        unsigned int ip_rst_data_qic_gpu2qice : 1;
        unsigned int ip_rst_adb_mst_hc0 : 1;
        unsigned int ip_rst_adb_mst_hc1 : 1;
        unsigned int ip_rst_hsdt1_subsys_crg : 1;
        unsigned int ip_rst_hsdt1_subsys : 1;
        unsigned int ip_rst_media2 : 1;
        unsigned int ip_rst_media2_crg : 1;
        unsigned int ip_rst_spi6 : 1;
        unsigned int ip_rst_ocr_acpu : 1;
        unsigned int ip_rst_intr_hub : 1;
        unsigned int ip_rst_npu_qic_cfg_peri : 1;
        unsigned int ip_rst_media2_qic_cfg_peri : 1;
        unsigned int ip_rst_media1_qic_cfg_peri : 1;
        unsigned int ip_rst_pll_fsm : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_data_qic_gpu_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_data_qic_gpu_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_hsdtbus_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_hsdtbus_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_sysbus_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_sysbus_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_cfgbus_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_cfgbus_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_hsdt_crg_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_hsdt_crg_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_gpu_crg_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_gpu_crg_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_qic_mdmperi_bus_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_qic_mdmperi_bus_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_noc_hsdt1bus_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_noc_hsdt1bus_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_media_lp_ctrl_crg_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_media_lp_ctrl_crg_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_media_lp_ctrl_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_media_lp_ctrl_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_digtsen_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_digtsen_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_adb_mst_lit_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_adb_mst_lit_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_peri_pd_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_peri_pd_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_pericrg_pd_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_pericrg_pd_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_data_qic_gpu2qice_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_data_qic_gpu2qice_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_adb_mst_hc0_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_adb_mst_hc0_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_adb_mst_hc1_START (20)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_adb_mst_hc1_END (20)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_hsdt1_subsys_crg_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_hsdt1_subsys_crg_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_hsdt1_subsys_START (22)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_hsdt1_subsys_END (22)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_media2_START (23)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_media2_END (23)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_media2_crg_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_media2_crg_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_spi6_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_spi6_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_ocr_acpu_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_ocr_acpu_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_intr_hub_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_intr_hub_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_npu_qic_cfg_peri_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_npu_qic_cfg_peri_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_media2_qic_cfg_peri_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_media2_qic_cfg_peri_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_media1_qic_cfg_peri_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_media1_qic_cfg_peri_END (30)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_pll_fsm_START (31)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT1_ip_rst_pll_fsm_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_periph_cpu : 1;
        unsigned int ip_rst_core_crg_apb : 1;
        unsigned int ip_rst_cpu_gic : 1;
        unsigned int ip_rst_cpu_gic_lit : 1;
        unsigned int ip_rst_cpu_gic_hc : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_rst_media : 1;
        unsigned int ip_rst_media_crg : 1;
        unsigned int ip_rst_process_monitor_cpu : 1;
        unsigned int ip_rst_gpu_lp_ctrl_crg : 1;
        unsigned int ip_rst_gpu_lp_ctrl : 1;
        unsigned int ip_rst_cpu_lp_ctrl_crg : 1;
        unsigned int ip_rst_cpu_lp_ctrl : 1;
        unsigned int ip_rst_npu_subsys_crg : 1;
        unsigned int ip_rst_npu_subsys : 1;
        unsigned int ip_rst_ddr_lpctrl_bus : 1;
        unsigned int ip_rst_gpu_fcm : 1;
        unsigned int ip_rst_hsdt1_pcmp_xctrl : 1;
        unsigned int ip_rst_hsdt0_pcmp_xctrl : 1;
        unsigned int ip_prst_ioc : 1;
        unsigned int ip_rst_ddr_lp_ctrl_crg : 1;
        unsigned int ip_rst_ddr_lp_ctrl : 1;
        unsigned int ip_arst_g3d_cfg : 1;
        unsigned int ip_arst_g3d : 1;
        unsigned int ip_rst_g3dmt : 1;
        unsigned int ip_arst_g3d_top_plus : 1;
        unsigned int ip_rst_cpu_gic_top : 1;
        unsigned int ip_rst_gpu_noc : 1;
        unsigned int ip_rst_exmbist : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_perifix_pad : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_periph_cpu_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_periph_cpu_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_core_crg_apb_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_core_crg_apb_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_cpu_gic_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_cpu_gic_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_cpu_gic_lit_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_cpu_gic_lit_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_cpu_gic_hc_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_cpu_gic_hc_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_media_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_media_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_media_crg_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_media_crg_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_process_monitor_cpu_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_process_monitor_cpu_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_gpu_lp_ctrl_crg_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_gpu_lp_ctrl_crg_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_gpu_lp_ctrl_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_gpu_lp_ctrl_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_cpu_lp_ctrl_crg_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_cpu_lp_ctrl_crg_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_cpu_lp_ctrl_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_cpu_lp_ctrl_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_npu_subsys_crg_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_npu_subsys_crg_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_npu_subsys_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_npu_subsys_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_ddr_lpctrl_bus_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_ddr_lpctrl_bus_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_gpu_fcm_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_gpu_fcm_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_hsdt1_pcmp_xctrl_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_hsdt1_pcmp_xctrl_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_hsdt0_pcmp_xctrl_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_hsdt0_pcmp_xctrl_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_prst_ioc_START (20)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_prst_ioc_END (20)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_ddr_lp_ctrl_crg_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_ddr_lp_ctrl_crg_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_ddr_lp_ctrl_START (22)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_ddr_lp_ctrl_END (22)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_arst_g3d_cfg_START (23)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_arst_g3d_cfg_END (23)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_arst_g3d_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_arst_g3d_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_g3dmt_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_g3dmt_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_arst_g3d_top_plus_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_arst_g3d_top_plus_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_cpu_gic_top_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_cpu_gic_top_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_gpu_noc_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_gpu_noc_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_exmbist_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_exmbist_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_perifix_pad_START (31)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTEN2_ip_rst_perifix_pad_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_periph_cpu : 1;
        unsigned int ip_rst_core_crg_apb : 1;
        unsigned int ip_rst_cpu_gic : 1;
        unsigned int ip_rst_cpu_gic_lit : 1;
        unsigned int ip_rst_cpu_gic_hc : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_rst_media : 1;
        unsigned int ip_rst_media_crg : 1;
        unsigned int ip_rst_process_monitor_cpu : 1;
        unsigned int ip_rst_gpu_lp_ctrl_crg : 1;
        unsigned int ip_rst_gpu_lp_ctrl : 1;
        unsigned int ip_rst_cpu_lp_ctrl_crg : 1;
        unsigned int ip_rst_cpu_lp_ctrl : 1;
        unsigned int ip_rst_npu_subsys_crg : 1;
        unsigned int ip_rst_npu_subsys : 1;
        unsigned int ip_rst_ddr_lpctrl_bus : 1;
        unsigned int ip_rst_gpu_fcm : 1;
        unsigned int ip_rst_hsdt1_pcmp_xctrl : 1;
        unsigned int ip_rst_hsdt0_pcmp_xctrl : 1;
        unsigned int ip_prst_ioc : 1;
        unsigned int ip_rst_ddr_lp_ctrl_crg : 1;
        unsigned int ip_rst_ddr_lp_ctrl : 1;
        unsigned int ip_arst_g3d_cfg : 1;
        unsigned int ip_arst_g3d : 1;
        unsigned int ip_rst_g3dmt : 1;
        unsigned int ip_arst_g3d_top_plus : 1;
        unsigned int ip_rst_cpu_gic_top : 1;
        unsigned int ip_rst_gpu_noc : 1;
        unsigned int ip_rst_exmbist : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_perifix_pad : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_periph_cpu_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_periph_cpu_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_core_crg_apb_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_core_crg_apb_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_cpu_gic_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_cpu_gic_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_cpu_gic_lit_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_cpu_gic_lit_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_cpu_gic_hc_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_cpu_gic_hc_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_media_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_media_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_media_crg_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_media_crg_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_process_monitor_cpu_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_process_monitor_cpu_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_gpu_lp_ctrl_crg_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_gpu_lp_ctrl_crg_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_gpu_lp_ctrl_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_gpu_lp_ctrl_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_cpu_lp_ctrl_crg_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_cpu_lp_ctrl_crg_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_cpu_lp_ctrl_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_cpu_lp_ctrl_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_npu_subsys_crg_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_npu_subsys_crg_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_npu_subsys_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_npu_subsys_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_ddr_lpctrl_bus_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_ddr_lpctrl_bus_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_gpu_fcm_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_gpu_fcm_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_hsdt1_pcmp_xctrl_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_hsdt1_pcmp_xctrl_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_hsdt0_pcmp_xctrl_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_hsdt0_pcmp_xctrl_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_prst_ioc_START (20)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_prst_ioc_END (20)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_ddr_lp_ctrl_crg_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_ddr_lp_ctrl_crg_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_ddr_lp_ctrl_START (22)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_ddr_lp_ctrl_END (22)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_arst_g3d_cfg_START (23)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_arst_g3d_cfg_END (23)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_arst_g3d_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_arst_g3d_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_g3dmt_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_g3dmt_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_arst_g3d_top_plus_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_arst_g3d_top_plus_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_cpu_gic_top_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_cpu_gic_top_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_gpu_noc_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_gpu_noc_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_exmbist_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_exmbist_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_perifix_pad_START (31)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTDIS2_ip_rst_perifix_pad_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_periph_cpu : 1;
        unsigned int ip_rst_core_crg_apb : 1;
        unsigned int ip_rst_cpu_gic : 1;
        unsigned int ip_rst_cpu_gic_lit : 1;
        unsigned int ip_rst_cpu_gic_hc : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_rst_media : 1;
        unsigned int ip_rst_media_crg : 1;
        unsigned int ip_rst_process_monitor_cpu : 1;
        unsigned int ip_rst_gpu_lp_ctrl_crg : 1;
        unsigned int ip_rst_gpu_lp_ctrl : 1;
        unsigned int ip_rst_cpu_lp_ctrl_crg : 1;
        unsigned int ip_rst_cpu_lp_ctrl : 1;
        unsigned int ip_rst_npu_subsys_crg : 1;
        unsigned int ip_rst_npu_subsys : 1;
        unsigned int ip_rst_ddr_lpctrl_bus : 1;
        unsigned int ip_rst_gpu_fcm : 1;
        unsigned int ip_rst_hsdt1_pcmp_xctrl : 1;
        unsigned int ip_rst_hsdt0_pcmp_xctrl : 1;
        unsigned int ip_prst_ioc : 1;
        unsigned int ip_rst_ddr_lp_ctrl_crg : 1;
        unsigned int ip_rst_ddr_lp_ctrl : 1;
        unsigned int ip_arst_g3d_cfg : 1;
        unsigned int ip_arst_g3d : 1;
        unsigned int ip_rst_g3dmt : 1;
        unsigned int ip_arst_g3d_top_plus : 1;
        unsigned int ip_rst_cpu_gic_top : 1;
        unsigned int ip_rst_gpu_noc : 1;
        unsigned int ip_rst_exmbist : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_perifix_pad : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_periph_cpu_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_periph_cpu_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_core_crg_apb_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_core_crg_apb_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_cpu_gic_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_cpu_gic_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_cpu_gic_lit_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_cpu_gic_lit_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_cpu_gic_hc_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_cpu_gic_hc_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_media_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_media_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_media_crg_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_media_crg_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_process_monitor_cpu_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_process_monitor_cpu_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_gpu_lp_ctrl_crg_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_gpu_lp_ctrl_crg_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_gpu_lp_ctrl_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_gpu_lp_ctrl_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_cpu_lp_ctrl_crg_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_cpu_lp_ctrl_crg_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_cpu_lp_ctrl_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_cpu_lp_ctrl_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_npu_subsys_crg_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_npu_subsys_crg_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_npu_subsys_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_npu_subsys_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_ddr_lpctrl_bus_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_ddr_lpctrl_bus_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_gpu_fcm_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_gpu_fcm_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_hsdt1_pcmp_xctrl_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_hsdt1_pcmp_xctrl_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_hsdt0_pcmp_xctrl_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_hsdt0_pcmp_xctrl_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_prst_ioc_START (20)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_prst_ioc_END (20)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_ddr_lp_ctrl_crg_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_ddr_lp_ctrl_crg_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_ddr_lp_ctrl_START (22)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_ddr_lp_ctrl_END (22)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_arst_g3d_cfg_START (23)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_arst_g3d_cfg_END (23)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_arst_g3d_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_arst_g3d_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_g3dmt_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_g3dmt_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_arst_g3d_top_plus_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_arst_g3d_top_plus_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_cpu_gic_top_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_cpu_gic_top_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_gpu_noc_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_gpu_noc_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_exmbist_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_exmbist_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_perifix_pad_START (31)
#define SOC_CRGPERIPH_GENERAL_SEC_RSTSTAT2_ip_rst_perifix_pad_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int gt_pclk_gpio0_se : 1;
        unsigned int gt_clk_tsensor0 : 1;
        unsigned int gt_clk_tsensor1 : 1;
        unsigned int gt_clk_tsensor2 : 1;
        unsigned int gt_clk_tsensor3 : 1;
        unsigned int gt_clk_ddrc_a_sys : 1;
        unsigned int gt_clk_ddrc_b_sys : 1;
        unsigned int gt_clk_ddrc_c_sys : 1;
        unsigned int gt_clk_ddrc_d_sys : 1;
        unsigned int gt_clk_p2p_m_a : 1;
        unsigned int gt_clk_p2p_m_b : 1;
        unsigned int gt_clk_p2p_m_c : 1;
        unsigned int gt_clk_p2p_m_d : 1;
        unsigned int gt_clk_lpmcu : 1;
        unsigned int gt_clk_lpmcu2cfgbus : 1;
        unsigned int gt_clk_digtsen : 1;
        unsigned int gt_clk_ocr_acpu : 1;
        unsigned int gt_aclk_power_stat : 1;
        unsigned int gt_clk_hisee_flash : 1;
        unsigned int gt_clk_out1 : 1;
        unsigned int gt_clk_uce_subsys_a : 1;
        unsigned int gt_clk_uce_subsys_b : 1;
        unsigned int gt_clk_uce_subsys_c : 1;
        unsigned int gt_clk_uce_subsys_d : 1;
        unsigned int gt_clk_ddrphy_pll_a : 1;
        unsigned int gt_clk_ddrphy_pll_b : 1;
        unsigned int gt_clk_ddrphy_pll_c : 1;
        unsigned int gt_clk_ddrphy_pll_d : 1;
        unsigned int gt_clk_npu_intr_hub : 1;
        unsigned int gt_clk_media2_intr_hub : 1;
        unsigned int gt_clk_media1_intr_hub : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_PEREN_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_pclk_gpio0_se_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_pclk_gpio0_se_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_tsensor0_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_tsensor0_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_tsensor1_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_tsensor1_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_tsensor2_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_tsensor2_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_tsensor3_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_tsensor3_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_ddrc_a_sys_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_ddrc_a_sys_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_ddrc_b_sys_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_ddrc_b_sys_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_ddrc_c_sys_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_ddrc_c_sys_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_ddrc_d_sys_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_ddrc_d_sys_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_p2p_m_a_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_p2p_m_a_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_p2p_m_b_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_p2p_m_b_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_p2p_m_c_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_p2p_m_c_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_p2p_m_d_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_p2p_m_d_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_lpmcu_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_lpmcu_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_lpmcu2cfgbus_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_lpmcu2cfgbus_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_digtsen_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_digtsen_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_ocr_acpu_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_ocr_acpu_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_aclk_power_stat_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_aclk_power_stat_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_hisee_flash_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_hisee_flash_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_out1_START (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_out1_END (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_uce_subsys_a_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_uce_subsys_a_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_uce_subsys_b_START (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_uce_subsys_b_END (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_uce_subsys_c_START (23)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_uce_subsys_c_END (23)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_uce_subsys_d_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_uce_subsys_d_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_ddrphy_pll_a_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_ddrphy_pll_a_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_ddrphy_pll_b_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_ddrphy_pll_b_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_ddrphy_pll_c_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_ddrphy_pll_c_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_ddrphy_pll_d_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_ddrphy_pll_d_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_npu_intr_hub_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_npu_intr_hub_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_media2_intr_hub_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_media2_intr_hub_END (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_media1_intr_hub_START (31)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN_gt_clk_media1_intr_hub_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int gt_pclk_gpio0_se : 1;
        unsigned int gt_clk_tsensor0 : 1;
        unsigned int gt_clk_tsensor1 : 1;
        unsigned int gt_clk_tsensor2 : 1;
        unsigned int gt_clk_tsensor3 : 1;
        unsigned int gt_clk_ddrc_a_sys : 1;
        unsigned int gt_clk_ddrc_b_sys : 1;
        unsigned int gt_clk_ddrc_c_sys : 1;
        unsigned int gt_clk_ddrc_d_sys : 1;
        unsigned int gt_clk_p2p_m_a : 1;
        unsigned int gt_clk_p2p_m_b : 1;
        unsigned int gt_clk_p2p_m_c : 1;
        unsigned int gt_clk_p2p_m_d : 1;
        unsigned int gt_clk_lpmcu : 1;
        unsigned int gt_clk_lpmcu2cfgbus : 1;
        unsigned int gt_clk_digtsen : 1;
        unsigned int gt_clk_ocr_acpu : 1;
        unsigned int gt_aclk_power_stat : 1;
        unsigned int gt_clk_hisee_flash : 1;
        unsigned int gt_clk_out1 : 1;
        unsigned int gt_clk_uce_subsys_a : 1;
        unsigned int gt_clk_uce_subsys_b : 1;
        unsigned int gt_clk_uce_subsys_c : 1;
        unsigned int gt_clk_uce_subsys_d : 1;
        unsigned int gt_clk_ddrphy_pll_a : 1;
        unsigned int gt_clk_ddrphy_pll_b : 1;
        unsigned int gt_clk_ddrphy_pll_c : 1;
        unsigned int gt_clk_ddrphy_pll_d : 1;
        unsigned int gt_clk_npu_intr_hub : 1;
        unsigned int gt_clk_media2_intr_hub : 1;
        unsigned int gt_clk_media1_intr_hub : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_PERDIS_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_pclk_gpio0_se_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_pclk_gpio0_se_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_tsensor0_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_tsensor0_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_tsensor1_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_tsensor1_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_tsensor2_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_tsensor2_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_tsensor3_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_tsensor3_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_ddrc_a_sys_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_ddrc_a_sys_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_ddrc_b_sys_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_ddrc_b_sys_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_ddrc_c_sys_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_ddrc_c_sys_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_ddrc_d_sys_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_ddrc_d_sys_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_p2p_m_a_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_p2p_m_a_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_p2p_m_b_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_p2p_m_b_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_p2p_m_c_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_p2p_m_c_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_p2p_m_d_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_p2p_m_d_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_lpmcu_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_lpmcu_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_lpmcu2cfgbus_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_lpmcu2cfgbus_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_digtsen_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_digtsen_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_ocr_acpu_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_ocr_acpu_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_aclk_power_stat_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_aclk_power_stat_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_hisee_flash_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_hisee_flash_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_out1_START (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_out1_END (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_uce_subsys_a_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_uce_subsys_a_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_uce_subsys_b_START (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_uce_subsys_b_END (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_uce_subsys_c_START (23)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_uce_subsys_c_END (23)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_uce_subsys_d_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_uce_subsys_d_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_ddrphy_pll_a_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_ddrphy_pll_a_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_ddrphy_pll_b_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_ddrphy_pll_b_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_ddrphy_pll_c_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_ddrphy_pll_c_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_ddrphy_pll_d_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_ddrphy_pll_d_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_npu_intr_hub_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_npu_intr_hub_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_media2_intr_hub_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_media2_intr_hub_END (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_media1_intr_hub_START (31)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS_gt_clk_media1_intr_hub_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int gt_pclk_gpio0_se : 1;
        unsigned int gt_clk_tsensor0 : 1;
        unsigned int gt_clk_tsensor1 : 1;
        unsigned int gt_clk_tsensor2 : 1;
        unsigned int gt_clk_tsensor3 : 1;
        unsigned int gt_clk_ddrc_a_sys : 1;
        unsigned int gt_clk_ddrc_b_sys : 1;
        unsigned int gt_clk_ddrc_c_sys : 1;
        unsigned int gt_clk_ddrc_d_sys : 1;
        unsigned int gt_clk_p2p_m_a : 1;
        unsigned int gt_clk_p2p_m_b : 1;
        unsigned int gt_clk_p2p_m_c : 1;
        unsigned int gt_clk_p2p_m_d : 1;
        unsigned int gt_clk_lpmcu : 1;
        unsigned int gt_clk_lpmcu2cfgbus : 1;
        unsigned int gt_clk_digtsen : 1;
        unsigned int gt_clk_ocr_acpu : 1;
        unsigned int gt_aclk_power_stat : 1;
        unsigned int gt_clk_hisee_flash : 1;
        unsigned int gt_clk_out1 : 1;
        unsigned int gt_clk_uce_subsys_a : 1;
        unsigned int gt_clk_uce_subsys_b : 1;
        unsigned int gt_clk_uce_subsys_c : 1;
        unsigned int gt_clk_uce_subsys_d : 1;
        unsigned int gt_clk_ddrphy_pll_a : 1;
        unsigned int gt_clk_ddrphy_pll_b : 1;
        unsigned int gt_clk_ddrphy_pll_c : 1;
        unsigned int gt_clk_ddrphy_pll_d : 1;
        unsigned int gt_clk_npu_intr_hub : 1;
        unsigned int gt_clk_media2_intr_hub : 1;
        unsigned int gt_clk_media1_intr_hub : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_pclk_gpio0_se_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_pclk_gpio0_se_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_tsensor0_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_tsensor0_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_tsensor1_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_tsensor1_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_tsensor2_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_tsensor2_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_tsensor3_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_tsensor3_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_ddrc_a_sys_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_ddrc_a_sys_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_ddrc_b_sys_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_ddrc_b_sys_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_ddrc_c_sys_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_ddrc_c_sys_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_ddrc_d_sys_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_ddrc_d_sys_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_p2p_m_a_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_p2p_m_a_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_p2p_m_b_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_p2p_m_b_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_p2p_m_c_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_p2p_m_c_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_p2p_m_d_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_p2p_m_d_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_lpmcu_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_lpmcu_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_lpmcu2cfgbus_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_lpmcu2cfgbus_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_digtsen_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_digtsen_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_ocr_acpu_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_ocr_acpu_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_aclk_power_stat_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_aclk_power_stat_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_hisee_flash_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_hisee_flash_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_out1_START (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_out1_END (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_uce_subsys_a_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_uce_subsys_a_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_uce_subsys_b_START (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_uce_subsys_b_END (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_uce_subsys_c_START (23)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_uce_subsys_c_END (23)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_uce_subsys_d_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_uce_subsys_d_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_ddrphy_pll_a_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_ddrphy_pll_a_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_ddrphy_pll_b_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_ddrphy_pll_b_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_ddrphy_pll_c_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_ddrphy_pll_c_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_ddrphy_pll_d_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_ddrphy_pll_d_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_npu_intr_hub_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_npu_intr_hub_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_media2_intr_hub_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_media2_intr_hub_END (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_media1_intr_hub_START (31)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN_gt_clk_media1_intr_hub_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int st_pclk_gpio0_se : 1;
        unsigned int st_clk_tsensor0 : 1;
        unsigned int st_clk_tsensor1 : 1;
        unsigned int st_clk_tsensor2 : 1;
        unsigned int st_clk_tsensor3 : 1;
        unsigned int st_clk_ddrc_a_sys : 1;
        unsigned int st_clk_ddrc_b_sys : 1;
        unsigned int st_clk_ddrc_c_sys : 1;
        unsigned int st_clk_ddrc_d_sys : 1;
        unsigned int st_clk_p2p_m_a : 1;
        unsigned int st_clk_p2p_m_b : 1;
        unsigned int st_clk_p2p_m_c : 1;
        unsigned int st_clk_p2p_m_d : 1;
        unsigned int st_clk_lpmcu : 1;
        unsigned int st_clk_lpmcu2cfgbus : 1;
        unsigned int st_clk_digtsen : 1;
        unsigned int st_clk_ocr_acpu : 1;
        unsigned int st_aclk_power_stat : 1;
        unsigned int st_clk_hisee_flash : 1;
        unsigned int st_clk_out1 : 1;
        unsigned int st_clk_uce_subsys_a : 1;
        unsigned int st_clk_uce_subsys_b : 1;
        unsigned int st_clk_uce_subsys_c : 1;
        unsigned int st_clk_uce_subsys_d : 1;
        unsigned int st_clk_ddrphy_pll_autogt_a : 1;
        unsigned int st_clk_ddrphy_pll_autogt_b : 1;
        unsigned int st_clk_ddrphy_pll_autogt_c : 1;
        unsigned int st_clk_ddrphy_pll_autogt_d : 1;
        unsigned int st_clk_npu_intr_hub : 1;
        unsigned int st_clk_media2_intr_hub : 1;
        unsigned int st_clk_media1_intr_hub : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_pclk_gpio0_se_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_pclk_gpio0_se_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_tsensor0_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_tsensor0_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_tsensor1_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_tsensor1_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_tsensor2_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_tsensor2_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_tsensor3_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_tsensor3_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_ddrc_a_sys_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_ddrc_a_sys_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_ddrc_b_sys_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_ddrc_b_sys_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_ddrc_c_sys_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_ddrc_c_sys_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_ddrc_d_sys_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_ddrc_d_sys_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_p2p_m_a_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_p2p_m_a_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_p2p_m_b_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_p2p_m_b_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_p2p_m_c_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_p2p_m_c_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_p2p_m_d_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_p2p_m_d_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_lpmcu_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_lpmcu_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_lpmcu2cfgbus_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_lpmcu2cfgbus_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_digtsen_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_digtsen_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_ocr_acpu_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_ocr_acpu_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_aclk_power_stat_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_aclk_power_stat_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_hisee_flash_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_hisee_flash_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_out1_START (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_out1_END (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_uce_subsys_a_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_uce_subsys_a_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_uce_subsys_b_START (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_uce_subsys_b_END (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_uce_subsys_c_START (23)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_uce_subsys_c_END (23)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_uce_subsys_d_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_uce_subsys_d_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_ddrphy_pll_autogt_a_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_ddrphy_pll_autogt_a_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_ddrphy_pll_autogt_b_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_ddrphy_pll_autogt_b_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_ddrphy_pll_autogt_c_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_ddrphy_pll_autogt_c_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_ddrphy_pll_autogt_d_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_ddrphy_pll_autogt_d_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_npu_intr_hub_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_npu_intr_hub_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_media2_intr_hub_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_media2_intr_hub_END (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_media1_intr_hub_START (31)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT_st_clk_media1_intr_hub_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_hsdt_crg : 1;
        unsigned int gt_clk_hsdtbus : 1;
        unsigned int gt_pclk_hsdt1_crg : 1;
        unsigned int gt_clk_sysbus : 1;
        unsigned int gt_clk_cfgbus : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_noc_cfg2fcm : 1;
        unsigned int gt_clk_npu_adb_slv : 1;
        unsigned int gt_clk_hsdt1_subsys : 1;
        unsigned int gt_clk_ddr_lpctrl_ram : 1;
        unsigned int gt_clk_ddr_lpctrl_bus : 1;
        unsigned int gt_clk_qic_hsdt1 : 1;
        unsigned int gt_clk_sysbus2hsdt1 : 1;
        unsigned int gt_clk_hsdt1bus : 1;
        unsigned int gt_clk_media_lp_ctrl_sys : 1;
        unsigned int gt_clk_media_lp_ctrl : 1;
        unsigned int gt_clk_pll_ctrl : 1;
        unsigned int gt_clk_pll_fsm : 1;
        unsigned int gt_pclk_autodiv_periph_cpu_hc : 1;
        unsigned int gt_pclk_autodiv_periph_cpu_lit : 1;
        unsigned int gt_pclk_autodiv_periph_cpu : 1;
        unsigned int gt_pclk_autodiv_cpu_gic : 1;
        unsigned int gt_aclk_gic : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_mspc_lock : 1;
        unsigned int gt_clk_ppll2_b_sscg : 1;
        unsigned int gt_clk_ppll1_sscg : 1;
        unsigned int gt_clk_ppll2_sscg : 1;
        unsigned int gt_clk_ppll3_sscg : 1;
        unsigned int gt_clk_spi6 : 1;
        unsigned int gt_pclk_tzpc : 1;
        unsigned int gt_clk_cpu_djtag : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_PEREN1_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_pclk_hsdt_crg_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_pclk_hsdt_crg_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_hsdtbus_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_hsdtbus_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_pclk_hsdt1_crg_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_pclk_hsdt1_crg_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_sysbus_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_sysbus_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_cfgbus_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_cfgbus_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_noc_cfg2fcm_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_noc_cfg2fcm_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_npu_adb_slv_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_npu_adb_slv_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_hsdt1_subsys_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_hsdt1_subsys_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_ddr_lpctrl_ram_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_ddr_lpctrl_ram_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_ddr_lpctrl_bus_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_ddr_lpctrl_bus_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_qic_hsdt1_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_qic_hsdt1_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_sysbus2hsdt1_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_sysbus2hsdt1_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_hsdt1bus_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_hsdt1bus_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_media_lp_ctrl_sys_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_media_lp_ctrl_sys_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_media_lp_ctrl_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_media_lp_ctrl_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_pll_ctrl_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_pll_ctrl_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_pll_fsm_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_pll_fsm_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_pclk_autodiv_periph_cpu_hc_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_pclk_autodiv_periph_cpu_hc_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_pclk_autodiv_periph_cpu_lit_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_pclk_autodiv_periph_cpu_lit_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_pclk_autodiv_periph_cpu_START (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_pclk_autodiv_periph_cpu_END (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_pclk_autodiv_cpu_gic_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_pclk_autodiv_cpu_gic_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_aclk_gic_START (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_aclk_gic_END (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_mspc_lock_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_mspc_lock_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_ppll2_b_sscg_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_ppll2_b_sscg_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_ppll1_sscg_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_ppll1_sscg_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_ppll2_sscg_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_ppll2_sscg_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_ppll3_sscg_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_ppll3_sscg_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_spi6_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_spi6_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_pclk_tzpc_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_pclk_tzpc_END (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_cpu_djtag_START (31)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN1_gt_clk_cpu_djtag_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_hsdt_crg : 1;
        unsigned int gt_clk_hsdtbus : 1;
        unsigned int gt_pclk_hsdt1_crg : 1;
        unsigned int gt_clk_sysbus : 1;
        unsigned int gt_clk_cfgbus : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_noc_cfg2fcm : 1;
        unsigned int gt_clk_npu_adb_slv : 1;
        unsigned int gt_clk_hsdt1_subsys : 1;
        unsigned int gt_clk_ddr_lpctrl_ram : 1;
        unsigned int gt_clk_ddr_lpctrl_bus : 1;
        unsigned int gt_clk_qic_hsdt1 : 1;
        unsigned int gt_clk_sysbus2hsdt1 : 1;
        unsigned int gt_clk_hsdt1bus : 1;
        unsigned int gt_clk_media_lp_ctrl_sys : 1;
        unsigned int gt_clk_media_lp_ctrl : 1;
        unsigned int gt_clk_pll_ctrl : 1;
        unsigned int gt_clk_pll_fsm : 1;
        unsigned int gt_pclk_autodiv_periph_cpu_hc : 1;
        unsigned int gt_pclk_autodiv_periph_cpu_lit : 1;
        unsigned int gt_pclk_autodiv_periph_cpu : 1;
        unsigned int gt_pclk_autodiv_cpu_gic : 1;
        unsigned int gt_aclk_gic : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_mspc_lock : 1;
        unsigned int gt_clk_ppll2_b_sscg : 1;
        unsigned int gt_clk_ppll1_sscg : 1;
        unsigned int gt_clk_ppll2_sscg : 1;
        unsigned int gt_clk_ppll3_sscg : 1;
        unsigned int gt_clk_spi6 : 1;
        unsigned int gt_pclk_tzpc : 1;
        unsigned int gt_clk_cpu_djtag : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_pclk_hsdt_crg_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_pclk_hsdt_crg_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_hsdtbus_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_hsdtbus_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_pclk_hsdt1_crg_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_pclk_hsdt1_crg_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_sysbus_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_sysbus_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_cfgbus_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_cfgbus_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_noc_cfg2fcm_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_noc_cfg2fcm_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_npu_adb_slv_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_npu_adb_slv_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_hsdt1_subsys_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_hsdt1_subsys_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_ddr_lpctrl_ram_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_ddr_lpctrl_ram_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_ddr_lpctrl_bus_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_ddr_lpctrl_bus_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_qic_hsdt1_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_qic_hsdt1_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_sysbus2hsdt1_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_sysbus2hsdt1_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_hsdt1bus_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_hsdt1bus_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_media_lp_ctrl_sys_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_media_lp_ctrl_sys_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_media_lp_ctrl_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_media_lp_ctrl_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_pll_ctrl_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_pll_ctrl_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_pll_fsm_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_pll_fsm_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_pclk_autodiv_periph_cpu_hc_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_pclk_autodiv_periph_cpu_hc_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_pclk_autodiv_periph_cpu_lit_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_pclk_autodiv_periph_cpu_lit_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_pclk_autodiv_periph_cpu_START (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_pclk_autodiv_periph_cpu_END (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_pclk_autodiv_cpu_gic_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_pclk_autodiv_cpu_gic_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_aclk_gic_START (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_aclk_gic_END (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_mspc_lock_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_mspc_lock_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_ppll2_b_sscg_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_ppll2_b_sscg_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_ppll1_sscg_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_ppll1_sscg_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_ppll2_sscg_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_ppll2_sscg_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_ppll3_sscg_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_ppll3_sscg_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_spi6_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_spi6_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_pclk_tzpc_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_pclk_tzpc_END (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_cpu_djtag_START (31)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS1_gt_clk_cpu_djtag_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_hsdt_crg : 1;
        unsigned int gt_clk_hsdtbus : 1;
        unsigned int gt_pclk_hsdt1_crg : 1;
        unsigned int gt_clk_sysbus : 1;
        unsigned int gt_clk_cfgbus : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_noc_cfg2fcm : 1;
        unsigned int gt_clk_npu_adb_slv : 1;
        unsigned int gt_clk_hsdt1_subsys : 1;
        unsigned int gt_clk_ddr_lpctrl_ram : 1;
        unsigned int gt_clk_ddr_lpctrl_bus : 1;
        unsigned int gt_clk_qic_hsdt1 : 1;
        unsigned int gt_clk_sysbus2hsdt1 : 1;
        unsigned int gt_clk_hsdt1bus : 1;
        unsigned int gt_clk_media_lp_ctrl_sys : 1;
        unsigned int gt_clk_media_lp_ctrl : 1;
        unsigned int gt_clk_pll_ctrl : 1;
        unsigned int gt_clk_pll_fsm : 1;
        unsigned int gt_pclk_autodiv_periph_cpu_hc : 1;
        unsigned int gt_pclk_autodiv_periph_cpu_lit : 1;
        unsigned int gt_pclk_autodiv_periph_cpu : 1;
        unsigned int gt_pclk_autodiv_cpu_gic : 1;
        unsigned int gt_aclk_gic : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_clk_mspc_lock : 1;
        unsigned int gt_clk_ppll2_b_sscg : 1;
        unsigned int gt_clk_ppll1_sscg : 1;
        unsigned int gt_clk_ppll2_sscg : 1;
        unsigned int gt_clk_ppll3_sscg : 1;
        unsigned int gt_clk_spi6 : 1;
        unsigned int gt_pclk_tzpc : 1;
        unsigned int gt_clk_cpu_djtag : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_pclk_hsdt_crg_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_pclk_hsdt_crg_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_hsdtbus_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_hsdtbus_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_pclk_hsdt1_crg_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_pclk_hsdt1_crg_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_sysbus_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_sysbus_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_cfgbus_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_cfgbus_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_noc_cfg2fcm_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_noc_cfg2fcm_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_npu_adb_slv_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_npu_adb_slv_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_hsdt1_subsys_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_hsdt1_subsys_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_ddr_lpctrl_ram_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_ddr_lpctrl_ram_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_ddr_lpctrl_bus_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_ddr_lpctrl_bus_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_qic_hsdt1_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_qic_hsdt1_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_sysbus2hsdt1_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_sysbus2hsdt1_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_hsdt1bus_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_hsdt1bus_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_media_lp_ctrl_sys_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_media_lp_ctrl_sys_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_media_lp_ctrl_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_media_lp_ctrl_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_pll_ctrl_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_pll_ctrl_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_pll_fsm_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_pll_fsm_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_pclk_autodiv_periph_cpu_hc_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_pclk_autodiv_periph_cpu_hc_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_pclk_autodiv_periph_cpu_lit_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_pclk_autodiv_periph_cpu_lit_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_pclk_autodiv_periph_cpu_START (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_pclk_autodiv_periph_cpu_END (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_pclk_autodiv_cpu_gic_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_pclk_autodiv_cpu_gic_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_aclk_gic_START (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_aclk_gic_END (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_mspc_lock_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_mspc_lock_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_ppll2_b_sscg_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_ppll2_b_sscg_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_ppll1_sscg_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_ppll1_sscg_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_ppll2_sscg_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_ppll2_sscg_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_ppll3_sscg_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_ppll3_sscg_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_spi6_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_spi6_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_pclk_tzpc_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_pclk_tzpc_END (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_cpu_djtag_START (31)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN1_gt_clk_cpu_djtag_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_pclk_hsdt_crg : 1;
        unsigned int st_clk_hsdtbus : 1;
        unsigned int st_pclk_hsdt1_crg : 1;
        unsigned int st_clk_sysbus : 1;
        unsigned int st_clk_cfgbus : 1;
        unsigned int reserved_0 : 1;
        unsigned int st_clk_noc_cfg2fcm : 1;
        unsigned int st_clk_npu_adb_slv : 1;
        unsigned int reserved_1 : 1;
        unsigned int st_clk_ddr_lpctrl_ram : 1;
        unsigned int st_clk_ddr_lpctrl_bus : 1;
        unsigned int st_clk_qic_hsdt1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int st_clk_hsdt1bus : 1;
        unsigned int st_clk_media_lp_ctrl_sys : 1;
        unsigned int st_clk_media_lp_ctrl : 1;
        unsigned int st_clk_pll_ctrl : 1;
        unsigned int st_clk_pll_fsm : 1;
        unsigned int st_pclk_autodiv_periph_cpu_hc : 1;
        unsigned int st_pclk_autodiv_periph_cpu_lit : 1;
        unsigned int st_pclk_autodiv_periph_cpu : 1;
        unsigned int st_pclk_autodiv_cpu_gic : 1;
        unsigned int st_aclk_gic : 1;
        unsigned int reserved_3 : 1;
        unsigned int st_clk_mspc_lock : 1;
        unsigned int st_clk_ppll2_b_sscg : 1;
        unsigned int st_clk_ppll1_sscg : 1;
        unsigned int st_clk_ppll2_sscg : 1;
        unsigned int st_clk_ppll3_sscg : 1;
        unsigned int st_clk_spi6 : 1;
        unsigned int st_pclk_tzpc : 1;
        unsigned int st_clk_cpu_djtag : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_pclk_hsdt_crg_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_pclk_hsdt_crg_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_hsdtbus_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_hsdtbus_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_pclk_hsdt1_crg_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_pclk_hsdt1_crg_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_sysbus_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_sysbus_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_cfgbus_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_cfgbus_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_noc_cfg2fcm_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_noc_cfg2fcm_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_npu_adb_slv_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_npu_adb_slv_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_ddr_lpctrl_ram_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_ddr_lpctrl_ram_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_ddr_lpctrl_bus_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_ddr_lpctrl_bus_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_qic_hsdt1_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_qic_hsdt1_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_hsdt1bus_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_hsdt1bus_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_media_lp_ctrl_sys_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_media_lp_ctrl_sys_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_media_lp_ctrl_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_media_lp_ctrl_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_pll_ctrl_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_pll_ctrl_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_pll_fsm_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_pll_fsm_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_pclk_autodiv_periph_cpu_hc_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_pclk_autodiv_periph_cpu_hc_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_pclk_autodiv_periph_cpu_lit_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_pclk_autodiv_periph_cpu_lit_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_pclk_autodiv_periph_cpu_START (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_pclk_autodiv_periph_cpu_END (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_pclk_autodiv_cpu_gic_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_pclk_autodiv_cpu_gic_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_aclk_gic_START (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_aclk_gic_END (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_mspc_lock_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_mspc_lock_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_ppll2_b_sscg_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_ppll2_b_sscg_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_ppll1_sscg_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_ppll1_sscg_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_ppll2_sscg_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_ppll2_sscg_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_ppll3_sscg_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_ppll3_sscg_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_spi6_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_spi6_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_pclk_tzpc_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_pclk_tzpc_END (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_cpu_djtag_START (31)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT1_st_clk_cpu_djtag_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_gpu_lp_ctrl_sys : 1;
        unsigned int gt_clk_gpu_lp_ctrl : 1;
        unsigned int gt_clk_cpu_lp_ctrl_sys : 1;
        unsigned int gt_clk_cpu_lp_ctrl : 1;
        unsigned int gt_clk_core_crg_apb : 1;
        unsigned int gt_clk_ddr_lp_ctrl_sys : 1;
        unsigned int gt_clk_ddr_lp_ctrl : 1;
        unsigned int gt_clk_npu_qic_cfg_peri : 1;
        unsigned int gt_clk_media2_qic_cfg_peri : 1;
        unsigned int gt_clk_media1_qic_cfg_peri : 1;
        unsigned int gt_pclk_autodiv_center_crossbar : 1;
        unsigned int gt_clk_fll_media2 : 1;
        unsigned int gt_pclk_media_crg : 1;
        unsigned int gt_pclk_autodiv_sysbus : 1;
        unsigned int gt_clk_npu_qic_cfg_core : 1;
        unsigned int reserved : 1;
        unsigned int gt_clk_cfgbus_media2 : 1;
        unsigned int gt_pclk_autodiv_hsdt1bus : 1;
        unsigned int gt_pclk_autodiv_lpmcu : 1;
        unsigned int gt_clk_cfgbus_media : 1;
        unsigned int gt_pclk_media2_crg : 1;
        unsigned int gt_clk_ppll1_media : 1;
        unsigned int gt_clk_ppll2_media : 1;
        unsigned int gt_clk_fll_media : 1;
        unsigned int gt_clk_ppll0_media : 1;
        unsigned int gt_clk_ppll2_b_media : 1;
        unsigned int gt_clk_qic_hsdt : 1;
        unsigned int gt_clk_ppll2_media2 : 1;
        unsigned int gt_clk_ppll6_media2 : 1;
        unsigned int gt_clk_ppll1_media2 : 1;
        unsigned int gt_clk_ppll0_media2 : 1;
        unsigned int gt_clk_ppll2_b_media2 : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_PEREN2_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_gpu_lp_ctrl_sys_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_gpu_lp_ctrl_sys_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_gpu_lp_ctrl_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_gpu_lp_ctrl_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_cpu_lp_ctrl_sys_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_cpu_lp_ctrl_sys_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_cpu_lp_ctrl_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_cpu_lp_ctrl_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_core_crg_apb_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_core_crg_apb_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_ddr_lp_ctrl_sys_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_ddr_lp_ctrl_sys_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_ddr_lp_ctrl_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_ddr_lp_ctrl_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_npu_qic_cfg_peri_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_npu_qic_cfg_peri_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_media2_qic_cfg_peri_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_media2_qic_cfg_peri_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_media1_qic_cfg_peri_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_media1_qic_cfg_peri_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_pclk_autodiv_center_crossbar_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_pclk_autodiv_center_crossbar_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_fll_media2_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_fll_media2_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_pclk_media_crg_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_pclk_media_crg_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_pclk_autodiv_sysbus_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_pclk_autodiv_sysbus_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_npu_qic_cfg_core_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_npu_qic_cfg_core_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_cfgbus_media2_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_cfgbus_media2_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_pclk_autodiv_hsdt1bus_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_pclk_autodiv_hsdt1bus_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_pclk_autodiv_lpmcu_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_pclk_autodiv_lpmcu_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_cfgbus_media_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_cfgbus_media_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_pclk_media2_crg_START (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_pclk_media2_crg_END (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_ppll1_media_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_ppll1_media_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_ppll2_media_START (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_ppll2_media_END (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_fll_media_START (23)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_fll_media_END (23)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_ppll0_media_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_ppll0_media_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_ppll2_b_media_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_ppll2_b_media_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_qic_hsdt_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_qic_hsdt_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_ppll2_media2_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_ppll2_media2_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_ppll6_media2_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_ppll6_media2_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_ppll1_media2_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_ppll1_media2_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_ppll0_media2_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_ppll0_media2_END (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_ppll2_b_media2_START (31)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN2_gt_clk_ppll2_b_media2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_gpu_lp_ctrl_sys : 1;
        unsigned int gt_clk_gpu_lp_ctrl : 1;
        unsigned int gt_clk_cpu_lp_ctrl_sys : 1;
        unsigned int gt_clk_cpu_lp_ctrl : 1;
        unsigned int gt_clk_core_crg_apb : 1;
        unsigned int gt_clk_ddr_lp_ctrl_sys : 1;
        unsigned int gt_clk_ddr_lp_ctrl : 1;
        unsigned int gt_clk_npu_qic_cfg_peri : 1;
        unsigned int gt_clk_media2_qic_cfg_peri : 1;
        unsigned int gt_clk_media1_qic_cfg_peri : 1;
        unsigned int gt_pclk_autodiv_center_crossbar : 1;
        unsigned int gt_clk_fll_media2 : 1;
        unsigned int gt_pclk_media_crg : 1;
        unsigned int gt_pclk_autodiv_sysbus : 1;
        unsigned int gt_clk_npu_qic_cfg_core : 1;
        unsigned int reserved : 1;
        unsigned int gt_clk_cfgbus_media2 : 1;
        unsigned int gt_pclk_autodiv_hsdt1bus : 1;
        unsigned int gt_pclk_autodiv_lpmcu : 1;
        unsigned int gt_clk_cfgbus_media : 1;
        unsigned int gt_pclk_media2_crg : 1;
        unsigned int gt_clk_ppll1_media : 1;
        unsigned int gt_clk_ppll2_media : 1;
        unsigned int gt_clk_fll_media : 1;
        unsigned int gt_clk_ppll0_media : 1;
        unsigned int gt_clk_ppll2_b_media : 1;
        unsigned int gt_clk_qic_hsdt : 1;
        unsigned int gt_clk_ppll2_media2 : 1;
        unsigned int gt_clk_ppll6_media2 : 1;
        unsigned int gt_clk_ppll1_media2 : 1;
        unsigned int gt_clk_ppll0_media2 : 1;
        unsigned int gt_clk_ppll2_b_media2 : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_gpu_lp_ctrl_sys_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_gpu_lp_ctrl_sys_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_gpu_lp_ctrl_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_gpu_lp_ctrl_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_cpu_lp_ctrl_sys_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_cpu_lp_ctrl_sys_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_cpu_lp_ctrl_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_cpu_lp_ctrl_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_core_crg_apb_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_core_crg_apb_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_ddr_lp_ctrl_sys_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_ddr_lp_ctrl_sys_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_ddr_lp_ctrl_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_ddr_lp_ctrl_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_npu_qic_cfg_peri_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_npu_qic_cfg_peri_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_media2_qic_cfg_peri_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_media2_qic_cfg_peri_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_media1_qic_cfg_peri_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_media1_qic_cfg_peri_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_pclk_autodiv_center_crossbar_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_pclk_autodiv_center_crossbar_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_fll_media2_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_fll_media2_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_pclk_media_crg_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_pclk_media_crg_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_pclk_autodiv_sysbus_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_pclk_autodiv_sysbus_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_npu_qic_cfg_core_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_npu_qic_cfg_core_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_cfgbus_media2_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_cfgbus_media2_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_pclk_autodiv_hsdt1bus_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_pclk_autodiv_hsdt1bus_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_pclk_autodiv_lpmcu_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_pclk_autodiv_lpmcu_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_cfgbus_media_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_cfgbus_media_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_pclk_media2_crg_START (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_pclk_media2_crg_END (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_ppll1_media_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_ppll1_media_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_ppll2_media_START (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_ppll2_media_END (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_fll_media_START (23)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_fll_media_END (23)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_ppll0_media_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_ppll0_media_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_ppll2_b_media_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_ppll2_b_media_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_qic_hsdt_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_qic_hsdt_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_ppll2_media2_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_ppll2_media2_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_ppll6_media2_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_ppll6_media2_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_ppll1_media2_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_ppll1_media2_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_ppll0_media2_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_ppll0_media2_END (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_ppll2_b_media2_START (31)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS2_gt_clk_ppll2_b_media2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_gpu_lp_ctrl_sys : 1;
        unsigned int gt_clk_gpu_lp_ctrl : 1;
        unsigned int gt_clk_cpu_lp_ctrl_sys : 1;
        unsigned int gt_clk_cpu_lp_ctrl : 1;
        unsigned int gt_clk_core_crg_apb : 1;
        unsigned int gt_clk_ddr_lp_ctrl_sys : 1;
        unsigned int gt_clk_ddr_lp_ctrl : 1;
        unsigned int gt_clk_npu_qic_cfg_peri : 1;
        unsigned int gt_clk_media2_qic_cfg_peri : 1;
        unsigned int gt_clk_media1_qic_cfg_peri : 1;
        unsigned int gt_pclk_autodiv_center_crossbar : 1;
        unsigned int gt_clk_fll_media2 : 1;
        unsigned int gt_pclk_media_crg : 1;
        unsigned int gt_pclk_autodiv_sysbus : 1;
        unsigned int gt_clk_npu_qic_cfg_core : 1;
        unsigned int reserved : 1;
        unsigned int gt_clk_cfgbus_media2 : 1;
        unsigned int gt_pclk_autodiv_hsdt1bus : 1;
        unsigned int gt_pclk_autodiv_lpmcu : 1;
        unsigned int gt_clk_cfgbus_media : 1;
        unsigned int gt_pclk_media2_crg : 1;
        unsigned int gt_clk_ppll1_media : 1;
        unsigned int gt_clk_ppll2_media : 1;
        unsigned int gt_clk_fll_media : 1;
        unsigned int gt_clk_ppll0_media : 1;
        unsigned int gt_clk_ppll2_b_media : 1;
        unsigned int gt_clk_qic_hsdt : 1;
        unsigned int gt_clk_ppll2_media2 : 1;
        unsigned int gt_clk_ppll6_media2 : 1;
        unsigned int gt_clk_ppll1_media2 : 1;
        unsigned int gt_clk_ppll0_media2 : 1;
        unsigned int gt_clk_ppll2_b_media2 : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_gpu_lp_ctrl_sys_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_gpu_lp_ctrl_sys_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_gpu_lp_ctrl_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_gpu_lp_ctrl_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_cpu_lp_ctrl_sys_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_cpu_lp_ctrl_sys_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_cpu_lp_ctrl_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_cpu_lp_ctrl_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_core_crg_apb_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_core_crg_apb_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_ddr_lp_ctrl_sys_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_ddr_lp_ctrl_sys_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_ddr_lp_ctrl_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_ddr_lp_ctrl_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_npu_qic_cfg_peri_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_npu_qic_cfg_peri_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_media2_qic_cfg_peri_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_media2_qic_cfg_peri_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_media1_qic_cfg_peri_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_media1_qic_cfg_peri_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_pclk_autodiv_center_crossbar_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_pclk_autodiv_center_crossbar_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_fll_media2_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_fll_media2_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_pclk_media_crg_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_pclk_media_crg_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_pclk_autodiv_sysbus_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_pclk_autodiv_sysbus_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_npu_qic_cfg_core_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_npu_qic_cfg_core_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_cfgbus_media2_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_cfgbus_media2_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_pclk_autodiv_hsdt1bus_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_pclk_autodiv_hsdt1bus_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_pclk_autodiv_lpmcu_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_pclk_autodiv_lpmcu_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_cfgbus_media_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_cfgbus_media_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_pclk_media2_crg_START (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_pclk_media2_crg_END (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_ppll1_media_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_ppll1_media_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_ppll2_media_START (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_ppll2_media_END (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_fll_media_START (23)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_fll_media_END (23)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_ppll0_media_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_ppll0_media_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_ppll2_b_media_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_ppll2_b_media_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_qic_hsdt_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_qic_hsdt_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_ppll2_media2_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_ppll2_media2_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_ppll6_media2_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_ppll6_media2_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_ppll1_media2_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_ppll1_media2_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_ppll0_media2_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_ppll0_media2_END (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_ppll2_b_media2_START (31)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN2_gt_clk_ppll2_b_media2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_gpu_lp_ctrl_sys : 1;
        unsigned int st_clk_gpu_lp_ctrl : 1;
        unsigned int st_clk_cpu_lp_ctrl_sys : 1;
        unsigned int st_clk_cpu_lp_ctrl : 1;
        unsigned int st_clk_core_crg_apb : 1;
        unsigned int st_clk_ddr_lp_ctrl_sys : 1;
        unsigned int st_clk_ddr_lp_ctrl : 1;
        unsigned int st_clk_npu_qic_cfg_peri : 1;
        unsigned int st_clk_media2_qic_cfg_peri : 1;
        unsigned int st_clk_media1_qic_cfg_peri : 1;
        unsigned int st_pclk_autodiv_center_crossbar : 1;
        unsigned int st_clk_fll_media2 : 1;
        unsigned int st_pclk_media_crg : 1;
        unsigned int st_pclk_autodiv_sysbus : 1;
        unsigned int st_clk_npu_qic_cfg_core : 1;
        unsigned int reserved : 1;
        unsigned int st_clk_cfgbus_media2 : 1;
        unsigned int st_pclk_autodiv_hsdt1bus : 1;
        unsigned int st_pclk_autodiv_lpmcu : 1;
        unsigned int st_clk_cfgbus_media : 1;
        unsigned int st_pclk_media2_crg : 1;
        unsigned int st_clk_ppll1_media : 1;
        unsigned int st_clk_ppll2_media : 1;
        unsigned int st_clk_fll_media : 1;
        unsigned int st_clk_ppll0_media : 1;
        unsigned int st_clk_ppll2_b_media : 1;
        unsigned int st_clk_qic_hsdt : 1;
        unsigned int st_clk_ppll2_media2 : 1;
        unsigned int st_clk_ppll6_media2 : 1;
        unsigned int st_clk_ppll1_media2 : 1;
        unsigned int st_clk_ppll0_media2 : 1;
        unsigned int st_clk_ppll2_b_media2 : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_gpu_lp_ctrl_sys_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_gpu_lp_ctrl_sys_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_gpu_lp_ctrl_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_gpu_lp_ctrl_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_cpu_lp_ctrl_sys_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_cpu_lp_ctrl_sys_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_cpu_lp_ctrl_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_cpu_lp_ctrl_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_core_crg_apb_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_core_crg_apb_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_ddr_lp_ctrl_sys_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_ddr_lp_ctrl_sys_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_ddr_lp_ctrl_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_ddr_lp_ctrl_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_npu_qic_cfg_peri_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_npu_qic_cfg_peri_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_media2_qic_cfg_peri_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_media2_qic_cfg_peri_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_media1_qic_cfg_peri_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_media1_qic_cfg_peri_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_pclk_autodiv_center_crossbar_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_pclk_autodiv_center_crossbar_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_fll_media2_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_fll_media2_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_pclk_media_crg_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_pclk_media_crg_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_pclk_autodiv_sysbus_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_pclk_autodiv_sysbus_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_npu_qic_cfg_core_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_npu_qic_cfg_core_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_cfgbus_media2_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_cfgbus_media2_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_pclk_autodiv_hsdt1bus_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_pclk_autodiv_hsdt1bus_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_pclk_autodiv_lpmcu_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_pclk_autodiv_lpmcu_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_cfgbus_media_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_cfgbus_media_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_pclk_media2_crg_START (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_pclk_media2_crg_END (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_ppll1_media_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_ppll1_media_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_ppll2_media_START (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_ppll2_media_END (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_fll_media_START (23)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_fll_media_END (23)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_ppll0_media_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_ppll0_media_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_ppll2_b_media_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_ppll2_b_media_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_qic_hsdt_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_qic_hsdt_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_ppll2_media2_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_ppll2_media2_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_ppll6_media2_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_ppll6_media2_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_ppll1_media2_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_ppll1_media2_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_ppll0_media2_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_ppll0_media2_END (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_ppll2_b_media2_START (31)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT2_st_clk_ppll2_b_media2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_dmc_320m_l : 1;
        unsigned int gt_clk_noc_npubus_cfg : 1;
        unsigned int gt_clk_data_qcp_gpu : 1;
        unsigned int gt_clk_data_qic_gpu : 1;
        unsigned int gt_clk_noc_npubus : 1;
        unsigned int gt_pclk_npu_crg : 1;
        unsigned int gt_clk_cpu_gic : 1;
        unsigned int gt_clk_periph_cpu : 1;
        unsigned int gt_clk_sysbus2npu : 1;
        unsigned int gt_clk_data_qic_gpu2qice : 1;
        unsigned int gt_clk_qice_cfg2npu : 1;
        unsigned int gt_clk_sys_cpu_rtm : 1;
        unsigned int gt_clk_dmc_peri_pll_r : 1;
        unsigned int gt_clk_dmc_peri_pll_l : 1;
        unsigned int gt_clk_fll_npu : 1;
        unsigned int gt_clk_process_monitor_cpu : 1;
        unsigned int gt_clk_tscpu_peri : 1;
        unsigned int gt_clk_fcm : 1;
        unsigned int gt_pclk_gpu_crg : 1;
        unsigned int gt_clk_npu_tcxo : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_hclk_dmc_ddrxpu : 1;
        unsigned int gt_clk_dcdrbus_l_ddrxpu : 1;
        unsigned int gt_clk_dcdrbus_l_lpmcu : 1;
        unsigned int gt_hclk_dmc_lpmcu : 1;
        unsigned int gt_aclk_g3d_cfg : 1;
        unsigned int gt_clk_g3dmt : 1;
        unsigned int gt_aclk_g3d_core : 1;
        unsigned int gt_clk_dmc_320m_r : 1;
        unsigned int gt_clk_gpu_noc : 1;
        unsigned int gt_aclk_ddrphy_dfi_gpu : 1;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_PEREN3_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_dmc_320m_l_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_dmc_320m_l_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_noc_npubus_cfg_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_noc_npubus_cfg_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_data_qcp_gpu_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_data_qcp_gpu_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_data_qic_gpu_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_data_qic_gpu_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_noc_npubus_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_noc_npubus_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_pclk_npu_crg_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_pclk_npu_crg_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_cpu_gic_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_cpu_gic_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_periph_cpu_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_periph_cpu_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_sysbus2npu_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_sysbus2npu_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_data_qic_gpu2qice_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_data_qic_gpu2qice_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_qice_cfg2npu_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_qice_cfg2npu_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_sys_cpu_rtm_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_sys_cpu_rtm_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_dmc_peri_pll_r_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_dmc_peri_pll_r_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_dmc_peri_pll_l_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_dmc_peri_pll_l_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_fll_npu_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_fll_npu_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_process_monitor_cpu_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_process_monitor_cpu_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_tscpu_peri_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_tscpu_peri_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_fcm_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_fcm_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_pclk_gpu_crg_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_pclk_gpu_crg_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_npu_tcxo_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_npu_tcxo_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_hclk_dmc_ddrxpu_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_hclk_dmc_ddrxpu_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_dcdrbus_l_ddrxpu_START (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_dcdrbus_l_ddrxpu_END (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_dcdrbus_l_lpmcu_START (23)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_dcdrbus_l_lpmcu_END (23)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_hclk_dmc_lpmcu_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_hclk_dmc_lpmcu_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_aclk_g3d_cfg_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_aclk_g3d_cfg_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_g3dmt_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_g3dmt_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_aclk_g3d_core_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_aclk_g3d_core_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_dmc_320m_r_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_dmc_320m_r_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_gpu_noc_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_clk_gpu_noc_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_aclk_ddrphy_dfi_gpu_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN3_gt_aclk_ddrphy_dfi_gpu_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_dmc_320m_l : 1;
        unsigned int gt_clk_noc_npubus_cfg : 1;
        unsigned int gt_clk_data_qcp_gpu : 1;
        unsigned int gt_clk_data_qic_gpu : 1;
        unsigned int gt_clk_noc_npubus : 1;
        unsigned int gt_pclk_npu_crg : 1;
        unsigned int gt_clk_cpu_gic : 1;
        unsigned int gt_clk_periph_cpu : 1;
        unsigned int gt_clk_sysbus2npu : 1;
        unsigned int gt_clk_data_qic_gpu2qice : 1;
        unsigned int gt_clk_qice_cfg2npu : 1;
        unsigned int gt_clk_sys_cpu_rtm : 1;
        unsigned int gt_clk_dmc_peri_pll_r : 1;
        unsigned int gt_clk_dmc_peri_pll_l : 1;
        unsigned int gt_clk_fll_npu : 1;
        unsigned int gt_clk_process_monitor_cpu : 1;
        unsigned int gt_clk_tscpu_peri : 1;
        unsigned int gt_clk_fcm : 1;
        unsigned int gt_pclk_gpu_crg : 1;
        unsigned int gt_clk_npu_tcxo : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_hclk_dmc_ddrxpu : 1;
        unsigned int gt_clk_dcdrbus_l_ddrxpu : 1;
        unsigned int gt_clk_dcdrbus_l_lpmcu : 1;
        unsigned int gt_hclk_dmc_lpmcu : 1;
        unsigned int gt_aclk_g3d_cfg : 1;
        unsigned int gt_clk_g3dmt : 1;
        unsigned int gt_aclk_g3d_core : 1;
        unsigned int gt_clk_dmc_320m_r : 1;
        unsigned int gt_clk_gpu_noc : 1;
        unsigned int gt_aclk_ddrphy_dfi_gpu : 1;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_dmc_320m_l_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_dmc_320m_l_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_noc_npubus_cfg_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_noc_npubus_cfg_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_data_qcp_gpu_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_data_qcp_gpu_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_data_qic_gpu_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_data_qic_gpu_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_noc_npubus_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_noc_npubus_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_pclk_npu_crg_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_pclk_npu_crg_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_cpu_gic_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_cpu_gic_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_periph_cpu_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_periph_cpu_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_sysbus2npu_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_sysbus2npu_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_data_qic_gpu2qice_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_data_qic_gpu2qice_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_qice_cfg2npu_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_qice_cfg2npu_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_sys_cpu_rtm_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_sys_cpu_rtm_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_dmc_peri_pll_r_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_dmc_peri_pll_r_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_dmc_peri_pll_l_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_dmc_peri_pll_l_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_fll_npu_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_fll_npu_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_process_monitor_cpu_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_process_monitor_cpu_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_tscpu_peri_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_tscpu_peri_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_fcm_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_fcm_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_pclk_gpu_crg_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_pclk_gpu_crg_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_npu_tcxo_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_npu_tcxo_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_hclk_dmc_ddrxpu_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_hclk_dmc_ddrxpu_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_dcdrbus_l_ddrxpu_START (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_dcdrbus_l_ddrxpu_END (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_dcdrbus_l_lpmcu_START (23)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_dcdrbus_l_lpmcu_END (23)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_hclk_dmc_lpmcu_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_hclk_dmc_lpmcu_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_aclk_g3d_cfg_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_aclk_g3d_cfg_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_g3dmt_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_g3dmt_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_aclk_g3d_core_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_aclk_g3d_core_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_dmc_320m_r_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_dmc_320m_r_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_gpu_noc_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_clk_gpu_noc_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_aclk_ddrphy_dfi_gpu_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS3_gt_aclk_ddrphy_dfi_gpu_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_dmc_320m_l : 1;
        unsigned int gt_clk_noc_npubus_cfg : 1;
        unsigned int gt_clk_data_qcp_gpu : 1;
        unsigned int gt_clk_data_qic_gpu : 1;
        unsigned int gt_clk_noc_npubus : 1;
        unsigned int gt_pclk_npu_crg : 1;
        unsigned int gt_clk_cpu_gic : 1;
        unsigned int gt_clk_periph_cpu : 1;
        unsigned int gt_clk_sysbus2npu : 1;
        unsigned int gt_clk_data_qic_gpu2qice : 1;
        unsigned int gt_clk_qice_cfg2npu : 1;
        unsigned int gt_clk_sys_cpu_rtm : 1;
        unsigned int gt_clk_dmc_peri_pll_r : 1;
        unsigned int gt_clk_dmc_peri_pll_l : 1;
        unsigned int gt_clk_fll_npu : 1;
        unsigned int gt_clk_process_monitor_cpu : 1;
        unsigned int gt_clk_tscpu_peri : 1;
        unsigned int gt_clk_fcm : 1;
        unsigned int gt_pclk_gpu_crg : 1;
        unsigned int gt_clk_npu_tcxo : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_hclk_dmc_ddrxpu : 1;
        unsigned int gt_clk_dcdrbus_l_ddrxpu : 1;
        unsigned int gt_clk_dcdrbus_l_lpmcu : 1;
        unsigned int gt_hclk_dmc_lpmcu : 1;
        unsigned int gt_aclk_g3d_cfg : 1;
        unsigned int gt_clk_g3dmt : 1;
        unsigned int gt_aclk_g3d_core : 1;
        unsigned int gt_clk_dmc_320m_r : 1;
        unsigned int gt_clk_gpu_noc : 1;
        unsigned int gt_aclk_ddrphy_dfi_gpu : 1;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_dmc_320m_l_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_dmc_320m_l_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_noc_npubus_cfg_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_noc_npubus_cfg_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_data_qcp_gpu_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_data_qcp_gpu_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_data_qic_gpu_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_data_qic_gpu_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_noc_npubus_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_noc_npubus_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_pclk_npu_crg_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_pclk_npu_crg_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_cpu_gic_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_cpu_gic_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_periph_cpu_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_periph_cpu_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_sysbus2npu_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_sysbus2npu_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_data_qic_gpu2qice_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_data_qic_gpu2qice_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_qice_cfg2npu_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_qice_cfg2npu_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_sys_cpu_rtm_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_sys_cpu_rtm_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_dmc_peri_pll_r_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_dmc_peri_pll_r_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_dmc_peri_pll_l_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_dmc_peri_pll_l_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_fll_npu_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_fll_npu_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_process_monitor_cpu_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_process_monitor_cpu_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_tscpu_peri_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_tscpu_peri_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_fcm_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_fcm_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_pclk_gpu_crg_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_pclk_gpu_crg_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_npu_tcxo_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_npu_tcxo_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_hclk_dmc_ddrxpu_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_hclk_dmc_ddrxpu_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_dcdrbus_l_ddrxpu_START (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_dcdrbus_l_ddrxpu_END (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_dcdrbus_l_lpmcu_START (23)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_dcdrbus_l_lpmcu_END (23)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_hclk_dmc_lpmcu_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_hclk_dmc_lpmcu_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_aclk_g3d_cfg_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_aclk_g3d_cfg_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_g3dmt_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_g3dmt_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_aclk_g3d_core_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_aclk_g3d_core_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_dmc_320m_r_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_dmc_320m_r_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_gpu_noc_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_clk_gpu_noc_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_aclk_ddrphy_dfi_gpu_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN3_gt_aclk_ddrphy_dfi_gpu_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_dmc_320m_l : 1;
        unsigned int st_clk_noc_npubus_cfg : 1;
        unsigned int st_clk_data_qcp_gpu : 1;
        unsigned int st_clk_data_qic_gpu : 1;
        unsigned int st_clk_noc_npubus : 1;
        unsigned int st_pclk_npu_crg : 1;
        unsigned int st_clk_cpu_gic : 1;
        unsigned int st_clk_periph_cpu : 1;
        unsigned int st_clk_sysbus2npu : 1;
        unsigned int st_clk_data_qic_gpu2qice : 1;
        unsigned int st_clk_qice_cfg2npu : 1;
        unsigned int st_clk_sys_cpu_rtm : 1;
        unsigned int st_clk_dmc_peri_pll_r : 1;
        unsigned int st_clk_dmc_peri_pll_l : 1;
        unsigned int st_clk_fll_npu : 1;
        unsigned int st_clk_process_monitor_cpu : 1;
        unsigned int st_clk_tscpu_peri : 1;
        unsigned int reserved_0 : 1;
        unsigned int st_pclk_gpu_crg : 1;
        unsigned int st_clk_npu_tcxo : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int st_clk_fcm : 1;
        unsigned int st_hclk_dmc : 1;
        unsigned int st_aclk_g3d_cfg : 1;
        unsigned int st_clk_g3dmt : 1;
        unsigned int st_aclk_g3d_core : 1;
        unsigned int st_clk_dmc_320m_r : 1;
        unsigned int st_clk_gpu_noc : 1;
        unsigned int st_aclk_ddrphy_dfi_gpu : 1;
        unsigned int reserved_4 : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_dmc_320m_l_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_dmc_320m_l_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_noc_npubus_cfg_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_noc_npubus_cfg_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_data_qcp_gpu_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_data_qcp_gpu_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_data_qic_gpu_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_data_qic_gpu_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_noc_npubus_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_noc_npubus_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_pclk_npu_crg_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_pclk_npu_crg_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_cpu_gic_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_cpu_gic_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_periph_cpu_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_periph_cpu_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_sysbus2npu_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_sysbus2npu_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_data_qic_gpu2qice_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_data_qic_gpu2qice_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_qice_cfg2npu_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_qice_cfg2npu_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_sys_cpu_rtm_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_sys_cpu_rtm_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_dmc_peri_pll_r_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_dmc_peri_pll_r_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_dmc_peri_pll_l_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_dmc_peri_pll_l_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_fll_npu_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_fll_npu_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_process_monitor_cpu_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_process_monitor_cpu_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_tscpu_peri_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_tscpu_peri_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_pclk_gpu_crg_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_pclk_gpu_crg_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_npu_tcxo_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_npu_tcxo_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_fcm_START (23)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_fcm_END (23)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_hclk_dmc_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_hclk_dmc_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_aclk_g3d_cfg_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_aclk_g3d_cfg_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_g3dmt_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_g3dmt_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_aclk_g3d_core_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_aclk_g3d_core_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_dmc_320m_r_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_dmc_320m_r_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_gpu_noc_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_clk_gpu_noc_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_aclk_ddrphy_dfi_gpu_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT3_st_aclk_ddrphy_dfi_gpu_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 3;
        unsigned int gt_clk_qice_cfg_rs_npu : 1;
        unsigned int gt_pclk_media_lpctrl : 1;
        unsigned int gt_clk_pim_npu : 1;
        unsigned int gt_clk_pim_gpu : 1;
        unsigned int gt_clk_pim_cpu : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_clk_dcdrbus_r_ddrxpu : 1;
        unsigned int gt_clk_dcdrbus_r_lpmcu : 1;
        unsigned int gt_clk_qice_data_rs_up : 1;
        unsigned int gt_clk_qice_data_rs_l : 1;
        unsigned int gt_clk_qice_data_rs_r : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_clk_qice_cfg_rs_up : 1;
        unsigned int gt_clk_qice_cfg_rs_l : 1;
        unsigned int gt_clk_qice_cfg_rs_r : 1;
        unsigned int gt_clk_dmss2dmc_rs_wr_r : 1;
        unsigned int gt_clk_dmss2dmc_rs_wr_l : 1;
        unsigned int gt_clk_dmss2dmc_rs_rd_r : 1;
        unsigned int gt_clk_dmss2dmc_rs_rd_l : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_clk_center_crossbar : 1;
        unsigned int gt_clk_periph_cpu_lit : 1;
        unsigned int gt_clk_periph_cpu_hc : 1;
        unsigned int gt_clk_dcdr_ratio2dmc_d : 1;
        unsigned int gt_clk_dcdr_ratio2dmc_c : 1;
        unsigned int gt_clk_dcdr_ratio2dmc_b : 1;
        unsigned int gt_clk_dcdr_ratio2dmc_a : 1;
        unsigned int reserved_5 : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_PEREN4_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_qice_cfg_rs_npu_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_qice_cfg_rs_npu_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_pclk_media_lpctrl_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_pclk_media_lpctrl_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_pim_npu_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_pim_npu_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_pim_gpu_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_pim_gpu_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_pim_cpu_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_pim_cpu_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_dcdrbus_r_ddrxpu_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_dcdrbus_r_ddrxpu_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_dcdrbus_r_lpmcu_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_dcdrbus_r_lpmcu_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_qice_data_rs_up_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_qice_data_rs_up_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_qice_data_rs_l_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_qice_data_rs_l_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_qice_data_rs_r_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_qice_data_rs_r_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_qice_cfg_rs_up_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_qice_cfg_rs_up_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_qice_cfg_rs_l_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_qice_cfg_rs_l_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_qice_cfg_rs_r_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_qice_cfg_rs_r_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_dmss2dmc_rs_wr_r_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_dmss2dmc_rs_wr_r_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_dmss2dmc_rs_wr_l_START (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_dmss2dmc_rs_wr_l_END (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_dmss2dmc_rs_rd_r_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_dmss2dmc_rs_rd_r_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_dmss2dmc_rs_rd_l_START (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_dmss2dmc_rs_rd_l_END (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_center_crossbar_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_center_crossbar_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_periph_cpu_lit_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_periph_cpu_lit_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_periph_cpu_hc_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_periph_cpu_hc_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_dcdr_ratio2dmc_d_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_dcdr_ratio2dmc_d_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_dcdr_ratio2dmc_c_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_dcdr_ratio2dmc_c_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_dcdr_ratio2dmc_b_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_dcdr_ratio2dmc_b_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_dcdr_ratio2dmc_a_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN4_gt_clk_dcdr_ratio2dmc_a_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 3;
        unsigned int gt_clk_qice_cfg_rs_npu : 1;
        unsigned int gt_pclk_media_lpctrl : 1;
        unsigned int gt_clk_pim_npu : 1;
        unsigned int gt_clk_pim_gpu : 1;
        unsigned int gt_clk_pim_cpu : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_clk_dcdrbus_r_ddrxpu : 1;
        unsigned int gt_clk_dcdrbus_r_lpmcu : 1;
        unsigned int gt_clk_qice_data_rs_up : 1;
        unsigned int gt_clk_qice_data_rs_l : 1;
        unsigned int gt_clk_qice_data_rs_r : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_clk_qice_cfg_rs_up : 1;
        unsigned int gt_clk_qice_cfg_rs_l : 1;
        unsigned int gt_clk_qice_cfg_rs_r : 1;
        unsigned int gt_clk_dmss2dmc_rs_wr_r : 1;
        unsigned int gt_clk_dmss2dmc_rs_wr_l : 1;
        unsigned int gt_clk_dmss2dmc_rs_rd_r : 1;
        unsigned int gt_clk_dmss2dmc_rs_rd_l : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_clk_center_crossbar : 1;
        unsigned int gt_clk_periph_cpu_lit : 1;
        unsigned int gt_clk_periph_cpu_hc : 1;
        unsigned int gt_clk_dcdr_ratio2dmc_d : 1;
        unsigned int gt_clk_dcdr_ratio2dmc_c : 1;
        unsigned int gt_clk_dcdr_ratio2dmc_b : 1;
        unsigned int gt_clk_dcdr_ratio2dmc_a : 1;
        unsigned int reserved_5 : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_qice_cfg_rs_npu_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_qice_cfg_rs_npu_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_pclk_media_lpctrl_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_pclk_media_lpctrl_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_pim_npu_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_pim_npu_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_pim_gpu_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_pim_gpu_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_pim_cpu_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_pim_cpu_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_dcdrbus_r_ddrxpu_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_dcdrbus_r_ddrxpu_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_dcdrbus_r_lpmcu_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_dcdrbus_r_lpmcu_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_qice_data_rs_up_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_qice_data_rs_up_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_qice_data_rs_l_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_qice_data_rs_l_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_qice_data_rs_r_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_qice_data_rs_r_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_qice_cfg_rs_up_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_qice_cfg_rs_up_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_qice_cfg_rs_l_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_qice_cfg_rs_l_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_qice_cfg_rs_r_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_qice_cfg_rs_r_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_dmss2dmc_rs_wr_r_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_dmss2dmc_rs_wr_r_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_dmss2dmc_rs_wr_l_START (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_dmss2dmc_rs_wr_l_END (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_dmss2dmc_rs_rd_r_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_dmss2dmc_rs_rd_r_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_dmss2dmc_rs_rd_l_START (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_dmss2dmc_rs_rd_l_END (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_center_crossbar_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_center_crossbar_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_periph_cpu_lit_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_periph_cpu_lit_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_periph_cpu_hc_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_periph_cpu_hc_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_dcdr_ratio2dmc_d_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_dcdr_ratio2dmc_d_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_dcdr_ratio2dmc_c_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_dcdr_ratio2dmc_c_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_dcdr_ratio2dmc_b_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_dcdr_ratio2dmc_b_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_dcdr_ratio2dmc_a_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS4_gt_clk_dcdr_ratio2dmc_a_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 3;
        unsigned int gt_clk_qice_cfg_rs_npu : 1;
        unsigned int gt_pclk_media_lpctrl : 1;
        unsigned int gt_clk_pim_npu : 1;
        unsigned int gt_clk_pim_gpu : 1;
        unsigned int gt_clk_pim_cpu : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int gt_clk_dcdrbus_r_ddrxpu : 1;
        unsigned int gt_clk_dcdrbus_r_lpmcu : 1;
        unsigned int gt_clk_qice_data_rs_up : 1;
        unsigned int gt_clk_qice_data_rs_l : 1;
        unsigned int gt_clk_qice_data_rs_r : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_clk_qice_cfg_rs_up : 1;
        unsigned int gt_clk_qice_cfg_rs_l : 1;
        unsigned int gt_clk_qice_cfg_rs_r : 1;
        unsigned int gt_clk_dmss2dmc_rs_wr_r : 1;
        unsigned int gt_clk_dmss2dmc_rs_wr_l : 1;
        unsigned int gt_clk_dmss2dmc_rs_rd_r : 1;
        unsigned int gt_clk_dmss2dmc_rs_rd_l : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_clk_center_crossbar : 1;
        unsigned int gt_clk_periph_cpu_lit : 1;
        unsigned int gt_clk_periph_cpu_hc : 1;
        unsigned int gt_clk_dcdr_ratio2dmc_d : 1;
        unsigned int gt_clk_dcdr_ratio2dmc_c : 1;
        unsigned int gt_clk_dcdr_ratio2dmc_b : 1;
        unsigned int gt_clk_dcdr_ratio2dmc_a : 1;
        unsigned int reserved_5 : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_qice_cfg_rs_npu_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_qice_cfg_rs_npu_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_pclk_media_lpctrl_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_pclk_media_lpctrl_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_pim_npu_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_pim_npu_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_pim_gpu_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_pim_gpu_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_pim_cpu_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_pim_cpu_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_dcdrbus_r_ddrxpu_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_dcdrbus_r_ddrxpu_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_dcdrbus_r_lpmcu_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_dcdrbus_r_lpmcu_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_qice_data_rs_up_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_qice_data_rs_up_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_qice_data_rs_l_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_qice_data_rs_l_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_qice_data_rs_r_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_qice_data_rs_r_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_qice_cfg_rs_up_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_qice_cfg_rs_up_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_qice_cfg_rs_l_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_qice_cfg_rs_l_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_qice_cfg_rs_r_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_qice_cfg_rs_r_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_dmss2dmc_rs_wr_r_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_dmss2dmc_rs_wr_r_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_dmss2dmc_rs_wr_l_START (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_dmss2dmc_rs_wr_l_END (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_dmss2dmc_rs_rd_r_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_dmss2dmc_rs_rd_r_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_dmss2dmc_rs_rd_l_START (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_dmss2dmc_rs_rd_l_END (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_center_crossbar_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_center_crossbar_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_periph_cpu_lit_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_periph_cpu_lit_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_periph_cpu_hc_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_periph_cpu_hc_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_dcdr_ratio2dmc_d_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_dcdr_ratio2dmc_d_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_dcdr_ratio2dmc_c_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_dcdr_ratio2dmc_c_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_dcdr_ratio2dmc_b_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_dcdr_ratio2dmc_b_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_dcdr_ratio2dmc_a_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN4_gt_clk_dcdr_ratio2dmc_a_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 3;
        unsigned int st_clk_qice_cfg_npu : 1;
        unsigned int st_pclk_media_lpctrl : 1;
        unsigned int st_clk_pim_npu : 1;
        unsigned int st_clk_pim_gpu : 1;
        unsigned int st_clk_pim_cpu : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int st_clk_qice_data_rs_up : 1;
        unsigned int st_clk_qice_data_rs_l : 1;
        unsigned int st_clk_qice_data_rs_r : 1;
        unsigned int reserved_5 : 1;
        unsigned int st_clk_qice_cfg_rs_up : 1;
        unsigned int st_clk_qice_cfg_rs_l : 1;
        unsigned int st_clk_qice_cfg_rs_r : 1;
        unsigned int st_clk_dmss2dmc_rs_wr_r : 1;
        unsigned int st_clk_dmss2dmc_rs_wr_l : 1;
        unsigned int st_clk_dmss2dmc_rs_rd_r : 1;
        unsigned int st_clk_dmss2dmc_rs_rd_l : 1;
        unsigned int reserved_6 : 1;
        unsigned int st_clk_center_crossbar : 1;
        unsigned int st_clk_periph_cpu_lit : 1;
        unsigned int st_clk_periph_cpu_hc : 1;
        unsigned int st_clk_dcdr_ratio2dmc_d : 1;
        unsigned int st_clk_dcdr_ratio2dmc_c : 1;
        unsigned int st_clk_dcdr_ratio2dmc_b : 1;
        unsigned int st_clk_dcdr_ratio2dmc_a : 1;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_qice_cfg_npu_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_qice_cfg_npu_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_pclk_media_lpctrl_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_pclk_media_lpctrl_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_pim_npu_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_pim_npu_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_pim_gpu_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_pim_gpu_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_pim_cpu_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_pim_cpu_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_qice_data_rs_up_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_qice_data_rs_up_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_qice_data_rs_l_START (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_qice_data_rs_l_END (13)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_qice_data_rs_r_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_qice_data_rs_r_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_qice_cfg_rs_up_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_qice_cfg_rs_up_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_qice_cfg_rs_l_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_qice_cfg_rs_l_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_qice_cfg_rs_r_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_qice_cfg_rs_r_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_dmss2dmc_rs_wr_r_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_dmss2dmc_rs_wr_r_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_dmss2dmc_rs_wr_l_START (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_dmss2dmc_rs_wr_l_END (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_dmss2dmc_rs_rd_r_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_dmss2dmc_rs_rd_r_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_dmss2dmc_rs_rd_l_START (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_dmss2dmc_rs_rd_l_END (22)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_center_crossbar_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_center_crossbar_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_periph_cpu_lit_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_periph_cpu_lit_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_periph_cpu_hc_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_periph_cpu_hc_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_dcdr_ratio2dmc_d_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_dcdr_ratio2dmc_d_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_dcdr_ratio2dmc_c_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_dcdr_ratio2dmc_c_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_dcdr_ratio2dmc_b_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_dcdr_ratio2dmc_b_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_dcdr_ratio2dmc_a_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT4_st_clk_dcdr_ratio2dmc_a_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_exmbist_cfg : 1;
        unsigned int gt_clk_exmbist : 1;
        unsigned int gt_clk_ffts : 1;
        unsigned int gt_clk_qice_chi2qsp_dn : 1;
        unsigned int gt_clk_ffts_ref : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_autogt_ddrc : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_aclk_ddrc : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_clk_qice_data : 1;
        unsigned int gt_clk_qice_cfg : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_hclk_qice_cfg_ddrxpu : 1;
        unsigned int gt_hclk_qice_cfg_lpmcu : 1;
        unsigned int gt_clk_system_cache_c : 1;
        unsigned int gt_clk_system_cache_d : 1;
        unsigned int gt_clk_system_cache_cfg_d : 1;
        unsigned int gt_clk_system_cache_cfg_c : 1;
        unsigned int gt_clk_system_cache_b : 1;
        unsigned int gt_clk_system_cache_a : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int gt_clk_system_cache_cfg_a : 1;
        unsigned int gt_clk_system_cache_cfg_b : 1;
        unsigned int gt_clk_autogt_dmc_d : 1;
        unsigned int gt_clk_autogt_dmc_c : 1;
        unsigned int gt_clk_autogt_dmc_b : 1;
        unsigned int gt_clk_autogt_dmc_a : 1;
        unsigned int gt_clk_autogt_dmc_peri : 1;
        unsigned int gt_aclk_dmss2dmc_mux : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_PEREN5_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_exmbist_cfg_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_exmbist_cfg_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_exmbist_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_exmbist_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_ffts_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_ffts_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_qice_chi2qsp_dn_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_qice_chi2qsp_dn_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_ffts_ref_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_ffts_ref_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_autogt_ddrc_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_autogt_ddrc_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_aclk_ddrc_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_aclk_ddrc_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_qice_data_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_qice_data_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_qice_cfg_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_qice_cfg_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_hclk_qice_cfg_ddrxpu_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_hclk_qice_cfg_ddrxpu_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_hclk_qice_cfg_lpmcu_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_hclk_qice_cfg_lpmcu_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_system_cache_c_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_system_cache_c_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_system_cache_d_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_system_cache_d_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_system_cache_cfg_d_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_system_cache_cfg_d_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_system_cache_cfg_c_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_system_cache_cfg_c_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_system_cache_b_START (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_system_cache_b_END (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_system_cache_a_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_system_cache_a_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_system_cache_cfg_a_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_system_cache_cfg_a_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_system_cache_cfg_b_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_system_cache_cfg_b_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_autogt_dmc_d_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_autogt_dmc_d_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_autogt_dmc_c_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_autogt_dmc_c_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_autogt_dmc_b_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_autogt_dmc_b_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_autogt_dmc_a_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_autogt_dmc_a_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_autogt_dmc_peri_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_clk_autogt_dmc_peri_END (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_aclk_dmss2dmc_mux_START (31)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN5_gt_aclk_dmss2dmc_mux_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_exmbist_cfg : 1;
        unsigned int gt_clk_exmbist : 1;
        unsigned int gt_clk_ffts : 1;
        unsigned int gt_clk_qice_chi2qsp_dn : 1;
        unsigned int gt_clk_ffts_ref : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_autogt_ddrc : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_aclk_ddrc : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_clk_qice_data : 1;
        unsigned int gt_clk_qice_cfg : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_hclk_qice_cfg_ddrxpu : 1;
        unsigned int gt_hclk_qice_cfg_lpmcu : 1;
        unsigned int gt_clk_system_cache_c : 1;
        unsigned int gt_clk_system_cache_d : 1;
        unsigned int gt_clk_system_cache_cfg_d : 1;
        unsigned int gt_clk_system_cache_cfg_c : 1;
        unsigned int gt_clk_system_cache_b : 1;
        unsigned int gt_clk_system_cache_a : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int gt_clk_system_cache_cfg_a : 1;
        unsigned int gt_clk_system_cache_cfg_b : 1;
        unsigned int gt_clk_autogt_dmc_d : 1;
        unsigned int gt_clk_autogt_dmc_c : 1;
        unsigned int gt_clk_autogt_dmc_b : 1;
        unsigned int gt_clk_autogt_dmc_a : 1;
        unsigned int gt_clk_autogt_dmc_peri : 1;
        unsigned int gt_aclk_dmss2dmc_mux : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_exmbist_cfg_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_exmbist_cfg_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_exmbist_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_exmbist_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_ffts_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_ffts_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_qice_chi2qsp_dn_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_qice_chi2qsp_dn_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_ffts_ref_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_ffts_ref_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_autogt_ddrc_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_autogt_ddrc_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_aclk_ddrc_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_aclk_ddrc_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_qice_data_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_qice_data_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_qice_cfg_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_qice_cfg_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_hclk_qice_cfg_ddrxpu_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_hclk_qice_cfg_ddrxpu_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_hclk_qice_cfg_lpmcu_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_hclk_qice_cfg_lpmcu_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_system_cache_c_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_system_cache_c_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_system_cache_d_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_system_cache_d_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_system_cache_cfg_d_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_system_cache_cfg_d_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_system_cache_cfg_c_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_system_cache_cfg_c_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_system_cache_b_START (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_system_cache_b_END (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_system_cache_a_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_system_cache_a_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_system_cache_cfg_a_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_system_cache_cfg_a_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_system_cache_cfg_b_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_system_cache_cfg_b_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_autogt_dmc_d_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_autogt_dmc_d_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_autogt_dmc_c_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_autogt_dmc_c_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_autogt_dmc_b_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_autogt_dmc_b_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_autogt_dmc_a_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_autogt_dmc_a_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_autogt_dmc_peri_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_clk_autogt_dmc_peri_END (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_aclk_dmss2dmc_mux_START (31)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS5_gt_aclk_dmss2dmc_mux_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_exmbist_cfg : 1;
        unsigned int gt_clk_exmbist : 1;
        unsigned int gt_clk_ffts : 1;
        unsigned int gt_clk_qice_chi2qsp_dn : 1;
        unsigned int gt_clk_ffts_ref : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_autogt_ddrc : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_aclk_ddrc : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_clk_qice_data : 1;
        unsigned int gt_clk_qice_cfg : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_hclk_qice_cfg_ddrxpu : 1;
        unsigned int gt_hclk_qice_cfg_lpmcu : 1;
        unsigned int gt_clk_system_cache_c : 1;
        unsigned int gt_clk_system_cache_d : 1;
        unsigned int gt_clk_system_cache_cfg_d : 1;
        unsigned int gt_clk_system_cache_cfg_c : 1;
        unsigned int gt_clk_system_cache_b : 1;
        unsigned int gt_clk_system_cache_a : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int gt_clk_system_cache_cfg_a : 1;
        unsigned int gt_clk_system_cache_cfg_b : 1;
        unsigned int gt_clk_autogt_dmc_d : 1;
        unsigned int gt_clk_autogt_dmc_c : 1;
        unsigned int gt_clk_autogt_dmc_b : 1;
        unsigned int gt_clk_autogt_dmc_a : 1;
        unsigned int gt_clk_autogt_dmc_peri : 1;
        unsigned int gt_aclk_dmss2dmc_mux : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_exmbist_cfg_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_exmbist_cfg_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_exmbist_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_exmbist_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_ffts_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_ffts_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_qice_chi2qsp_dn_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_qice_chi2qsp_dn_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_ffts_ref_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_ffts_ref_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_autogt_ddrc_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_autogt_ddrc_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_aclk_ddrc_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_aclk_ddrc_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_qice_data_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_qice_data_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_qice_cfg_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_qice_cfg_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_hclk_qice_cfg_ddrxpu_START (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_hclk_qice_cfg_ddrxpu_END (14)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_hclk_qice_cfg_lpmcu_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_hclk_qice_cfg_lpmcu_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_system_cache_c_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_system_cache_c_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_system_cache_d_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_system_cache_d_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_system_cache_cfg_d_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_system_cache_cfg_d_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_system_cache_cfg_c_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_system_cache_cfg_c_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_system_cache_b_START (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_system_cache_b_END (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_system_cache_a_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_system_cache_a_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_system_cache_cfg_a_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_system_cache_cfg_a_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_system_cache_cfg_b_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_system_cache_cfg_b_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_autogt_dmc_d_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_autogt_dmc_d_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_autogt_dmc_c_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_autogt_dmc_c_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_autogt_dmc_b_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_autogt_dmc_b_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_autogt_dmc_a_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_autogt_dmc_a_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_autogt_dmc_peri_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_clk_autogt_dmc_peri_END (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_aclk_dmss2dmc_mux_START (31)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN5_gt_aclk_dmss2dmc_mux_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_exmbist_cfg : 1;
        unsigned int st_clk_exmbist : 1;
        unsigned int st_clk_ffts : 1;
        unsigned int st_clk_qice_chi2qsp_dn : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int st_clk_autogt_ddrc : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int st_clk_qice_data : 1;
        unsigned int st_clk_qice_cfg : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int st_hclk_qice_cfg : 1;
        unsigned int st_clk_system_cache_c : 1;
        unsigned int st_clk_system_cache_d : 1;
        unsigned int st_clk_system_cache_cfg_d : 1;
        unsigned int st_clk_system_cache_cfg_c : 1;
        unsigned int st_clk_system_cache_b : 1;
        unsigned int st_clk_system_cache_a : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int st_clk_system_cache_cfg_a : 1;
        unsigned int st_clk_system_cache_cfg_b : 1;
        unsigned int st_clk_autogt_dmc_d : 1;
        unsigned int st_clk_autogt_dmc_c : 1;
        unsigned int st_clk_autogt_dmc_b : 1;
        unsigned int st_clk_autogt_dmc_a : 1;
        unsigned int st_clk_autogt_dmc_peri : 1;
        unsigned int st_aclk_dmss2dmc_mux : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_exmbist_cfg_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_exmbist_cfg_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_exmbist_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_exmbist_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_ffts_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_ffts_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_qice_chi2qsp_dn_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_qice_chi2qsp_dn_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_autogt_ddrc_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_autogt_ddrc_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_qice_data_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_qice_data_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_qice_cfg_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_qice_cfg_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_hclk_qice_cfg_START (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_hclk_qice_cfg_END (15)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_system_cache_c_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_system_cache_c_END (16)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_system_cache_d_START (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_system_cache_d_END (17)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_system_cache_cfg_d_START (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_system_cache_cfg_d_END (18)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_system_cache_cfg_c_START (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_system_cache_cfg_c_END (19)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_system_cache_b_START (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_system_cache_b_END (20)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_system_cache_a_START (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_system_cache_a_END (21)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_system_cache_cfg_a_START (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_system_cache_cfg_a_END (24)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_system_cache_cfg_b_START (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_system_cache_cfg_b_END (25)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_autogt_dmc_d_START (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_autogt_dmc_d_END (26)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_autogt_dmc_c_START (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_autogt_dmc_c_END (27)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_autogt_dmc_b_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_autogt_dmc_b_END (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_autogt_dmc_a_START (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_autogt_dmc_a_END (29)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_autogt_dmc_peri_START (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_clk_autogt_dmc_peri_END (30)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_aclk_dmss2dmc_mux_START (31)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT5_st_aclk_dmss2dmc_mux_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_sysbus_media2 : 1;
        unsigned int gt_clk_sysbus_hsdt0 : 1;
        unsigned int gt_clk_sysbus_gpu : 1;
        unsigned int gt_clk_sysbus_ao : 1;
        unsigned int gt_clk_qice_data_rs_media2 : 1;
        unsigned int gt_clk_qice_data_rs_gpu : 1;
        unsigned int gt_clk_qice_data_rs_npu : 1;
        unsigned int gt_clk_qice_data_rs_media1 : 1;
        unsigned int gt_clk_qice_cfg_media1 : 1;
        unsigned int gt_clk_qice_cfg_media2 : 1;
        unsigned int gt_clk_qice_data_rs_modem : 1;
        unsigned int gt_clk_mdmperi_bus : 1;
        unsigned int gt_clk_qic_mdmperi_bus : 1;
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
        unsigned int gt_clk_hts_peri : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_PEREN6_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_gt_clk_sysbus_media2_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_gt_clk_sysbus_media2_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_gt_clk_sysbus_hsdt0_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_gt_clk_sysbus_hsdt0_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_gt_clk_sysbus_gpu_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_gt_clk_sysbus_gpu_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_gt_clk_sysbus_ao_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_gt_clk_sysbus_ao_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_gt_clk_qice_data_rs_media2_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_gt_clk_qice_data_rs_media2_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_gt_clk_qice_data_rs_gpu_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_gt_clk_qice_data_rs_gpu_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_gt_clk_qice_data_rs_npu_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_gt_clk_qice_data_rs_npu_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_gt_clk_qice_data_rs_media1_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_gt_clk_qice_data_rs_media1_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_gt_clk_qice_cfg_media1_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_gt_clk_qice_cfg_media1_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_gt_clk_qice_cfg_media2_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_gt_clk_qice_cfg_media2_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_gt_clk_qice_data_rs_modem_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_gt_clk_qice_data_rs_modem_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_gt_clk_mdmperi_bus_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_gt_clk_mdmperi_bus_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_gt_clk_qic_mdmperi_bus_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_gt_clk_qic_mdmperi_bus_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_gt_clk_hts_peri_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PEREN6_gt_clk_hts_peri_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_sysbus_media2 : 1;
        unsigned int gt_clk_sysbus_hsdt0 : 1;
        unsigned int gt_clk_sysbus_gpu : 1;
        unsigned int gt_clk_sysbus_ao : 1;
        unsigned int gt_clk_qice_data_rs_media2 : 1;
        unsigned int gt_clk_qice_data_rs_gpu : 1;
        unsigned int gt_clk_qice_data_rs_npu : 1;
        unsigned int gt_clk_qice_data_rs_media1 : 1;
        unsigned int gt_clk_qice_cfg_media1 : 1;
        unsigned int gt_clk_qice_cfg_media2 : 1;
        unsigned int gt_clk_qice_data_rs_modem : 1;
        unsigned int gt_clk_mdmperi_bus : 1;
        unsigned int gt_clk_qic_mdmperi_bus : 1;
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
        unsigned int gt_clk_hts_peri : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_gt_clk_sysbus_media2_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_gt_clk_sysbus_media2_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_gt_clk_sysbus_hsdt0_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_gt_clk_sysbus_hsdt0_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_gt_clk_sysbus_gpu_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_gt_clk_sysbus_gpu_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_gt_clk_sysbus_ao_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_gt_clk_sysbus_ao_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_gt_clk_qice_data_rs_media2_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_gt_clk_qice_data_rs_media2_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_gt_clk_qice_data_rs_gpu_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_gt_clk_qice_data_rs_gpu_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_gt_clk_qice_data_rs_npu_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_gt_clk_qice_data_rs_npu_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_gt_clk_qice_data_rs_media1_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_gt_clk_qice_data_rs_media1_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_gt_clk_qice_cfg_media1_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_gt_clk_qice_cfg_media1_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_gt_clk_qice_cfg_media2_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_gt_clk_qice_cfg_media2_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_gt_clk_qice_data_rs_modem_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_gt_clk_qice_data_rs_modem_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_gt_clk_mdmperi_bus_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_gt_clk_mdmperi_bus_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_gt_clk_qic_mdmperi_bus_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_gt_clk_qic_mdmperi_bus_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_gt_clk_hts_peri_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERDIS6_gt_clk_hts_peri_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_sysbus_media2 : 1;
        unsigned int gt_clk_sysbus_hsdt0 : 1;
        unsigned int gt_clk_sysbus_gpu : 1;
        unsigned int gt_clk_sysbus_ao : 1;
        unsigned int gt_clk_qice_data_rs_media2 : 1;
        unsigned int gt_clk_qice_data_rs_gpu : 1;
        unsigned int gt_clk_qice_data_rs_npu : 1;
        unsigned int gt_clk_qice_data_rs_media1 : 1;
        unsigned int gt_clk_qice_cfg_media1 : 1;
        unsigned int gt_clk_qice_cfg_media2 : 1;
        unsigned int gt_clk_qice_data_rs_modem : 1;
        unsigned int gt_clk_mdmperi_bus : 1;
        unsigned int gt_clk_qic_mdmperi_bus : 1;
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
        unsigned int gt_clk_hts_peri : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_gt_clk_sysbus_media2_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_gt_clk_sysbus_media2_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_gt_clk_sysbus_hsdt0_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_gt_clk_sysbus_hsdt0_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_gt_clk_sysbus_gpu_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_gt_clk_sysbus_gpu_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_gt_clk_sysbus_ao_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_gt_clk_sysbus_ao_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_gt_clk_qice_data_rs_media2_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_gt_clk_qice_data_rs_media2_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_gt_clk_qice_data_rs_gpu_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_gt_clk_qice_data_rs_gpu_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_gt_clk_qice_data_rs_npu_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_gt_clk_qice_data_rs_npu_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_gt_clk_qice_data_rs_media1_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_gt_clk_qice_data_rs_media1_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_gt_clk_qice_cfg_media1_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_gt_clk_qice_cfg_media1_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_gt_clk_qice_cfg_media2_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_gt_clk_qice_cfg_media2_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_gt_clk_qice_data_rs_modem_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_gt_clk_qice_data_rs_modem_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_gt_clk_mdmperi_bus_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_gt_clk_mdmperi_bus_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_gt_clk_qic_mdmperi_bus_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_gt_clk_qic_mdmperi_bus_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_gt_clk_hts_peri_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERCLKEN6_gt_clk_hts_peri_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_clk_sysbus_media2 : 1;
        unsigned int st_clk_sysbus_hsdt0 : 1;
        unsigned int st_clk_sysbus_gpu : 1;
        unsigned int st_clk_sysbus_ao : 1;
        unsigned int st_clk_qice_data_rs_media2 : 1;
        unsigned int st_clk_qice_data_rs_gpu : 1;
        unsigned int st_clk_qice_data_rs_npu : 1;
        unsigned int st_clk_qice_data_rs_media1 : 1;
        unsigned int st_clk_qice_cfg_media1 : 1;
        unsigned int st_clk_qice_cfg_media2 : 1;
        unsigned int st_clk_qice_data_rs_modem : 1;
        unsigned int st_clk_mdmperi_bus : 1;
        unsigned int st_clk_qic_mdmperi_bus : 1;
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
        unsigned int st_clk_hts_peri : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_st_clk_sysbus_media2_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_st_clk_sysbus_media2_END (0)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_st_clk_sysbus_hsdt0_START (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_st_clk_sysbus_hsdt0_END (1)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_st_clk_sysbus_gpu_START (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_st_clk_sysbus_gpu_END (2)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_st_clk_sysbus_ao_START (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_st_clk_sysbus_ao_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_st_clk_qice_data_rs_media2_START (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_st_clk_qice_data_rs_media2_END (4)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_st_clk_qice_data_rs_gpu_START (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_st_clk_qice_data_rs_gpu_END (5)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_st_clk_qice_data_rs_npu_START (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_st_clk_qice_data_rs_npu_END (6)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_st_clk_qice_data_rs_media1_START (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_st_clk_qice_data_rs_media1_END (7)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_st_clk_qice_cfg_media1_START (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_st_clk_qice_cfg_media1_END (8)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_st_clk_qice_cfg_media2_START (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_st_clk_qice_cfg_media2_END (9)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_st_clk_qice_data_rs_modem_START (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_st_clk_qice_data_rs_modem_END (10)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_st_clk_mdmperi_bus_START (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_st_clk_mdmperi_bus_END (11)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_st_clk_qic_mdmperi_bus_START (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_st_clk_qic_mdmperi_bus_END (12)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_st_clk_hts_peri_START (28)
#define SOC_CRGPERIPH_GENERAL_SEC_PERSTAT6_st_clk_hts_peri_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_powerup_cnt : 4;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 4;
        unsigned int reserved_5 : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_GENERAL_SEC_CTRL0_UNION;
#endif
#define SOC_CRGPERIPH_GENERAL_SEC_CTRL0_peri_powerup_cnt_START (0)
#define SOC_CRGPERIPH_GENERAL_SEC_CTRL0_peri_powerup_cnt_END (3)
#define SOC_CRGPERIPH_GENERAL_SEC_CTRL0_bitmasken_START (16)
#define SOC_CRGPERIPH_GENERAL_SEC_CTRL0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 1;
        unsigned int ddrsys_idle_waitcfg_in : 10;
        unsigned int ddrsys_idle_waitcfg_out : 10;
        unsigned int center_crossbar_div_auto_cfg : 6;
        unsigned int center_crossbar_fll_div_auto_cfg : 5;
    } reg;
} SOC_CRGPERIPH_DDRSYS_AUTOFS_CTRL0_UNION;
#endif
#define SOC_CRGPERIPH_DDRSYS_AUTOFS_CTRL0_ddrsys_idle_waitcfg_in_START (1)
#define SOC_CRGPERIPH_DDRSYS_AUTOFS_CTRL0_ddrsys_idle_waitcfg_in_END (10)
#define SOC_CRGPERIPH_DDRSYS_AUTOFS_CTRL0_ddrsys_idle_waitcfg_out_START (11)
#define SOC_CRGPERIPH_DDRSYS_AUTOFS_CTRL0_ddrsys_idle_waitcfg_out_END (20)
#define SOC_CRGPERIPH_DDRSYS_AUTOFS_CTRL0_center_crossbar_div_auto_cfg_START (21)
#define SOC_CRGPERIPH_DDRSYS_AUTOFS_CTRL0_center_crossbar_div_auto_cfg_END (26)
#define SOC_CRGPERIPH_DDRSYS_AUTOFS_CTRL0_center_crossbar_fll_div_auto_cfg_START (27)
#define SOC_CRGPERIPH_DDRSYS_AUTOFS_CTRL0_center_crossbar_fll_div_auto_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_fast_wakeup_bypass : 1;
        unsigned int qice_pdea2ddr_idle_bypass : 1;
        unsigned int qice_mdm2ddr_idle_bypass : 1;
        unsigned int qice_dcdr_qicecfg_bypass : 1;
        unsigned int qice_cc_bypass : 1;
        unsigned int qice_sdcu_bypass : 1;
        unsigned int qice_ffts_idle_bypass : 1;
        unsigned int qice_qsp_fcm_bypass : 1;
        unsigned int qice_qice_bypass : 1;
        unsigned int qice_qice_perf_bypass : 1;
        unsigned int qice_sc_bypass : 1;
        unsigned int qice_sc_perf_bypass : 1;
        unsigned int reserved_0 : 7;
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
    } reg;
} SOC_CRGPERIPH_DDRC_AUTOGT_CTRL2_UNION;
#endif
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL2_qice_fast_wakeup_bypass_START (0)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL2_qice_fast_wakeup_bypass_END (0)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL2_qice_pdea2ddr_idle_bypass_START (1)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL2_qice_pdea2ddr_idle_bypass_END (1)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL2_qice_mdm2ddr_idle_bypass_START (2)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL2_qice_mdm2ddr_idle_bypass_END (2)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL2_qice_dcdr_qicecfg_bypass_START (3)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL2_qice_dcdr_qicecfg_bypass_END (3)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL2_qice_cc_bypass_START (4)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL2_qice_cc_bypass_END (4)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL2_qice_sdcu_bypass_START (5)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL2_qice_sdcu_bypass_END (5)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL2_qice_ffts_idle_bypass_START (6)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL2_qice_ffts_idle_bypass_END (6)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL2_qice_qsp_fcm_bypass_START (7)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL2_qice_qsp_fcm_bypass_END (7)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL2_qice_qice_bypass_START (8)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL2_qice_qice_bypass_END (8)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL2_qice_qice_perf_bypass_START (9)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL2_qice_qice_perf_bypass_END (9)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL2_qice_sc_bypass_START (10)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL2_qice_sc_bypass_END (10)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL2_qice_sc_perf_bypass_START (11)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL2_qice_sc_perf_bypass_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tb2ddr_d_bypass : 1;
        unsigned int tb2ddr_c_bypass : 1;
        unsigned int tb2ddr_b_bypass : 1;
        unsigned int tb2ddr_a_bypass : 1;
        unsigned int dmc_fast_wakeup_bypass : 1;
        unsigned int dmc_d_gate_bypass : 1;
        unsigned int dmc_c_gate_bypass : 1;
        unsigned int dmc_b_gate_bypass : 1;
        unsigned int dmc_a_gate_bypass : 1;
        unsigned int dmc_h2h_bypass : 1;
        unsigned int dmc_peri_lp_en_bypass : 1;
        unsigned int reserved_0 : 9;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL2_UNION;
#endif
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL2_tb2ddr_d_bypass_START (0)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL2_tb2ddr_d_bypass_END (0)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL2_tb2ddr_c_bypass_START (1)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL2_tb2ddr_c_bypass_END (1)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL2_tb2ddr_b_bypass_START (2)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL2_tb2ddr_b_bypass_END (2)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL2_tb2ddr_a_bypass_START (3)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL2_tb2ddr_a_bypass_END (3)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL2_dmc_fast_wakeup_bypass_START (4)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL2_dmc_fast_wakeup_bypass_END (4)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL2_dmc_d_gate_bypass_START (5)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL2_dmc_d_gate_bypass_END (5)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL2_dmc_c_gate_bypass_START (6)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL2_dmc_c_gate_bypass_END (6)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL2_dmc_b_gate_bypass_START (7)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL2_dmc_b_gate_bypass_END (7)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL2_dmc_a_gate_bypass_START (8)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL2_dmc_a_gate_bypass_END (8)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL2_dmc_h2h_bypass_START (9)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL2_dmc_h2h_bypass_END (9)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL2_dmc_peri_lp_en_bypass_START (10)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL2_dmc_peri_lp_en_bypass_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_peri_lp_waitcfg_in : 10;
        unsigned int dmc_peri_lp_waitcfg_out : 10;
        unsigned int reserved : 12;
    } reg;
} SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL1_UNION;
#endif
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL1_dmc_peri_lp_waitcfg_in_START (0)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL1_dmc_peri_lp_waitcfg_in_END (9)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL1_dmc_peri_lp_waitcfg_out_START (10)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL1_dmc_peri_lp_waitcfg_out_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adb_debounce_num_out : 8;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int dmss2dmc_mux_autogt_bypass : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 6;
        unsigned int reserved_8 : 6;
        unsigned int cpu_chi_mst_bypass : 1;
        unsigned int adb_qhanske_enable_mst_bypass : 1;
        unsigned int adb_qhanske_enable_slv_bypass : 1;
        unsigned int ddrc_core_up_auto_gt_bypass : 1;
    } reg;
} SOC_CRGPERIPH_DDRC_AUTOGT_CTRL1_UNION;
#endif
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL1_adb_debounce_num_out_START (0)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL1_adb_debounce_num_out_END (7)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL1_dmss2dmc_mux_autogt_bypass_START (14)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL1_dmss2dmc_mux_autogt_bypass_END (14)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL1_cpu_chi_mst_bypass_START (28)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL1_cpu_chi_mst_bypass_END (28)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL1_adb_qhanske_enable_mst_bypass_START (29)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL1_adb_qhanske_enable_mst_bypass_END (29)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL1_adb_qhanske_enable_slv_bypass_START (30)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL1_adb_qhanske_enable_slv_bypass_END (30)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL1_ddrc_core_up_auto_gt_bypass_START (31)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL1_ddrc_core_up_auto_gt_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_peri_autogt_mode : 1;
        unsigned int dmc_peri_autogt_cnt_cfg : 6;
        unsigned int dmc_peri_autogt_bypass : 1;
        unsigned int autogt_clk_ddrphy_pll_bypass : 1;
        unsigned int autogt_clk_ddrphy_bypass : 1;
        unsigned int autogt_clk_dmc_peri_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int dmc_peri_autogt_bypass_ddr_xpu : 1;
        unsigned int icfg_dcdr_ckg_en : 1;
        unsigned int icfg_ddrc_h2p_ckg_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL_UNION;
#endif
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL_dmc_peri_autogt_mode_START (0)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL_dmc_peri_autogt_mode_END (0)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL_dmc_peri_autogt_cnt_cfg_START (1)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL_dmc_peri_autogt_cnt_cfg_END (6)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL_dmc_peri_autogt_bypass_START (7)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL_dmc_peri_autogt_bypass_END (7)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL_autogt_clk_ddrphy_pll_bypass_START (8)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL_autogt_clk_ddrphy_pll_bypass_END (8)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL_autogt_clk_ddrphy_bypass_START (9)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL_autogt_clk_ddrphy_bypass_END (9)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL_autogt_clk_dmc_peri_bypass_START (10)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL_autogt_clk_dmc_peri_bypass_END (10)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL_dmc_peri_autogt_bypass_ddr_xpu_START (12)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL_dmc_peri_autogt_bypass_ddr_xpu_END (12)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL_icfg_dcdr_ckg_en_START (13)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL_icfg_dcdr_ckg_en_END (13)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL_icfg_ddrc_h2p_ckg_en_START (14)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL_icfg_ddrc_h2p_ckg_en_END (14)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL_bitmasken_START (16)
#define SOC_CRGPERIPH_DMC_PERI_AUTOGT_CTRL_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddrc_core_r_auto_gt_bypass : 1;
        unsigned int ddrc_lp_waitcfg_in : 10;
        unsigned int ddrc_lp_waitcfg_out : 10;
        unsigned int ddrc_autogt_mode : 1;
        unsigned int ddrc_autogt_cnt_cfg : 6;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int ddrc_sys_clk_auto_gt_bypass : 1;
        unsigned int ddrc_core_l_auto_gt_bypass : 1;
    } reg;
} SOC_CRGPERIPH_DDRC_AUTOGT_CTRL_UNION;
#endif
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL_ddrc_core_r_auto_gt_bypass_START (0)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL_ddrc_core_r_auto_gt_bypass_END (0)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL_ddrc_lp_waitcfg_in_START (1)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL_ddrc_lp_waitcfg_in_END (10)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL_ddrc_lp_waitcfg_out_START (11)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL_ddrc_lp_waitcfg_out_END (20)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL_ddrc_autogt_mode_START (21)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL_ddrc_autogt_mode_END (21)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL_ddrc_autogt_cnt_cfg_START (22)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL_ddrc_autogt_cnt_cfg_END (27)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL_ddrc_sys_clk_auto_gt_bypass_START (30)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL_ddrc_sys_clk_auto_gt_bypass_END (30)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL_ddrc_core_l_auto_gt_bypass_START (31)
#define SOC_CRGPERIPH_DDRC_AUTOGT_CTRL_ddrc_core_l_auto_gt_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sysbus_hts_bypass : 1;
        unsigned int sysbus_cc_idle_bypass : 1;
        unsigned int sysbus_mdm_idle_bypass : 1;
        unsigned int sysbus_ffts2cc_bypass : 1;
        unsigned int sysbus_cfg_idle_bypass : 1;
        unsigned int sysbus_mediaxpu_idle_flag_bypass : 1;
        unsigned int sysbus_ddrxpu_idle_flag_bypass : 1;
        unsigned int sysbus_pwr_stat_bypass : 1;
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
    } reg;
} SOC_CRGPERIPH_PERI_AUTODIV0_UNION;
#endif
#define SOC_CRGPERIPH_PERI_AUTODIV0_sysbus_hts_bypass_START (0)
#define SOC_CRGPERIPH_PERI_AUTODIV0_sysbus_hts_bypass_END (0)
#define SOC_CRGPERIPH_PERI_AUTODIV0_sysbus_cc_idle_bypass_START (1)
#define SOC_CRGPERIPH_PERI_AUTODIV0_sysbus_cc_idle_bypass_END (1)
#define SOC_CRGPERIPH_PERI_AUTODIV0_sysbus_mdm_idle_bypass_START (2)
#define SOC_CRGPERIPH_PERI_AUTODIV0_sysbus_mdm_idle_bypass_END (2)
#define SOC_CRGPERIPH_PERI_AUTODIV0_sysbus_ffts2cc_bypass_START (3)
#define SOC_CRGPERIPH_PERI_AUTODIV0_sysbus_ffts2cc_bypass_END (3)
#define SOC_CRGPERIPH_PERI_AUTODIV0_sysbus_cfg_idle_bypass_START (4)
#define SOC_CRGPERIPH_PERI_AUTODIV0_sysbus_cfg_idle_bypass_END (4)
#define SOC_CRGPERIPH_PERI_AUTODIV0_sysbus_mediaxpu_idle_flag_bypass_START (5)
#define SOC_CRGPERIPH_PERI_AUTODIV0_sysbus_mediaxpu_idle_flag_bypass_END (5)
#define SOC_CRGPERIPH_PERI_AUTODIV0_sysbus_ddrxpu_idle_flag_bypass_START (6)
#define SOC_CRGPERIPH_PERI_AUTODIV0_sysbus_ddrxpu_idle_flag_bypass_END (6)
#define SOC_CRGPERIPH_PERI_AUTODIV0_sysbus_pwr_stat_bypass_START (7)
#define SOC_CRGPERIPH_PERI_AUTODIV0_sysbus_pwr_stat_bypass_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hsdtbus_h_idle_bypass : 1;
        unsigned int hsdtbus_h_qice_idle_bypass : 1;
        unsigned int hsdtbus_h_cc_idle_bypass : 1;
        unsigned int hsdtbus_l_cc_idle_bypass : 1;
        unsigned int hsdtbus_l_idle_bypass : 1;
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
        unsigned int hsdtbus1_cc_idle_bypass : 1;
        unsigned int hsdtbus1_idle_bypass : 1;
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
    } reg;
} SOC_CRGPERIPH_PERI_AUTODIV3_UNION;
#endif
#define SOC_CRGPERIPH_PERI_AUTODIV3_hsdtbus_h_idle_bypass_START (0)
#define SOC_CRGPERIPH_PERI_AUTODIV3_hsdtbus_h_idle_bypass_END (0)
#define SOC_CRGPERIPH_PERI_AUTODIV3_hsdtbus_h_qice_idle_bypass_START (1)
#define SOC_CRGPERIPH_PERI_AUTODIV3_hsdtbus_h_qice_idle_bypass_END (1)
#define SOC_CRGPERIPH_PERI_AUTODIV3_hsdtbus_h_cc_idle_bypass_START (2)
#define SOC_CRGPERIPH_PERI_AUTODIV3_hsdtbus_h_cc_idle_bypass_END (2)
#define SOC_CRGPERIPH_PERI_AUTODIV3_hsdtbus_l_cc_idle_bypass_START (3)
#define SOC_CRGPERIPH_PERI_AUTODIV3_hsdtbus_l_cc_idle_bypass_END (3)
#define SOC_CRGPERIPH_PERI_AUTODIV3_hsdtbus_l_idle_bypass_START (4)
#define SOC_CRGPERIPH_PERI_AUTODIV3_hsdtbus_l_idle_bypass_END (4)
#define SOC_CRGPERIPH_PERI_AUTODIV3_hsdtbus1_cc_idle_bypass_START (16)
#define SOC_CRGPERIPH_PERI_AUTODIV3_hsdtbus1_cc_idle_bypass_END (16)
#define SOC_CRGPERIPH_PERI_AUTODIV3_hsdtbus1_idle_bypass_START (17)
#define SOC_CRGPERIPH_PERI_AUTODIV3_hsdtbus1_idle_bypass_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
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
} SOC_CRGPERIPH_PERI_AUTODIV4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddrsys_mdmperi_idle_bypass : 1;
        unsigned int ddrsys_cc_idle_bypass : 1;
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
} SOC_CRGPERIPH_PERI_AUTODIV5_UNION;
#endif
#define SOC_CRGPERIPH_PERI_AUTODIV5_ddrsys_mdmperi_idle_bypass_START (0)
#define SOC_CRGPERIPH_PERI_AUTODIV5_ddrsys_mdmperi_idle_bypass_END (0)
#define SOC_CRGPERIPH_PERI_AUTODIV5_ddrsys_cc_idle_bypass_START (1)
#define SOC_CRGPERIPH_PERI_AUTODIV5_ddrsys_cc_idle_bypass_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sysbus_div_auto_reduce_bypass_lpm3 : 1;
        unsigned int sysbus_auto_waitcfg_in : 10;
        unsigned int sysbus_auto_waitcfg_out : 10;
        unsigned int sysbus_div_auto_cfg : 6;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
    } reg;
} SOC_CRGPERIPH_PERI_AUTODIV6_UNION;
#endif
#define SOC_CRGPERIPH_PERI_AUTODIV6_sysbus_div_auto_reduce_bypass_lpm3_START (0)
#define SOC_CRGPERIPH_PERI_AUTODIV6_sysbus_div_auto_reduce_bypass_lpm3_END (0)
#define SOC_CRGPERIPH_PERI_AUTODIV6_sysbus_auto_waitcfg_in_START (1)
#define SOC_CRGPERIPH_PERI_AUTODIV6_sysbus_auto_waitcfg_in_END (10)
#define SOC_CRGPERIPH_PERI_AUTODIV6_sysbus_auto_waitcfg_out_START (11)
#define SOC_CRGPERIPH_PERI_AUTODIV6_sysbus_auto_waitcfg_out_END (20)
#define SOC_CRGPERIPH_PERI_AUTODIV6_sysbus_div_auto_cfg_START (21)
#define SOC_CRGPERIPH_PERI_AUTODIV6_sysbus_div_auto_cfg_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 10;
        unsigned int reserved_2: 10;
        unsigned int reserved_3: 6;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
    } reg;
} SOC_CRGPERIPH_PERI_AUTODIV9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_fll_div_auto_cfg : 4;
        unsigned int sysbus_fll_div_auto_cfg : 4;
        unsigned int reserved_0 : 13;
        unsigned int reserved_1 : 6;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
    } reg;
} SOC_CRGPERIPH_PERI_AUTODIV11_UNION;
#endif
#define SOC_CRGPERIPH_PERI_AUTODIV11_lpmcu_fll_div_auto_cfg_START (0)
#define SOC_CRGPERIPH_PERI_AUTODIV11_lpmcu_fll_div_auto_cfg_END (3)
#define SOC_CRGPERIPH_PERI_AUTODIV11_sysbus_fll_div_auto_cfg_START (4)
#define SOC_CRGPERIPH_PERI_AUTODIV11_sysbus_fll_div_auto_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hsdt1bus_div_auto_reduce_bypass_lpm3 : 1;
        unsigned int hsdt1bus_auto_waitcfg_in : 10;
        unsigned int hsdt1bus_auto_waitcfg_out : 10;
        unsigned int hsdt1bus_div_auto_cfg : 6;
        unsigned int hsdt1bus_div_auto_cfg_fll : 4;
        unsigned int reserved : 1;
    } reg;
} SOC_CRGPERIPH_PERI_AUTODIV12_UNION;
#endif
#define SOC_CRGPERIPH_PERI_AUTODIV12_hsdt1bus_div_auto_reduce_bypass_lpm3_START (0)
#define SOC_CRGPERIPH_PERI_AUTODIV12_hsdt1bus_div_auto_reduce_bypass_lpm3_END (0)
#define SOC_CRGPERIPH_PERI_AUTODIV12_hsdt1bus_auto_waitcfg_in_START (1)
#define SOC_CRGPERIPH_PERI_AUTODIV12_hsdt1bus_auto_waitcfg_in_END (10)
#define SOC_CRGPERIPH_PERI_AUTODIV12_hsdt1bus_auto_waitcfg_out_START (11)
#define SOC_CRGPERIPH_PERI_AUTODIV12_hsdt1bus_auto_waitcfg_out_END (20)
#define SOC_CRGPERIPH_PERI_AUTODIV12_hsdt1bus_div_auto_cfg_START (21)
#define SOC_CRGPERIPH_PERI_AUTODIV12_hsdt1bus_div_auto_cfg_END (26)
#define SOC_CRGPERIPH_PERI_AUTODIV12_hsdt1bus_div_auto_cfg_fll_START (27)
#define SOC_CRGPERIPH_PERI_AUTODIV12_hsdt1bus_div_auto_cfg_fll_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_div_auto_reduce_bypass : 1;
        unsigned int lpmcu_auto_waitcfg_in : 10;
        unsigned int lpmcu_auto_waitcfg_out : 10;
        unsigned int lpmcu_div_auto_cfg : 6;
        unsigned int lpmcu_cfgbus_idle_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_CRGPERIPH_PERI_AUTODIV13_UNION;
#endif
#define SOC_CRGPERIPH_PERI_AUTODIV13_lpmcu_div_auto_reduce_bypass_START (0)
#define SOC_CRGPERIPH_PERI_AUTODIV13_lpmcu_div_auto_reduce_bypass_END (0)
#define SOC_CRGPERIPH_PERI_AUTODIV13_lpmcu_auto_waitcfg_in_START (1)
#define SOC_CRGPERIPH_PERI_AUTODIV13_lpmcu_auto_waitcfg_in_END (10)
#define SOC_CRGPERIPH_PERI_AUTODIV13_lpmcu_auto_waitcfg_out_START (11)
#define SOC_CRGPERIPH_PERI_AUTODIV13_lpmcu_auto_waitcfg_out_END (20)
#define SOC_CRGPERIPH_PERI_AUTODIV13_lpmcu_div_auto_cfg_START (21)
#define SOC_CRGPERIPH_PERI_AUTODIV13_lpmcu_div_auto_cfg_END (26)
#define SOC_CRGPERIPH_PERI_AUTODIV13_lpmcu_cfgbus_idle_bypass_START (27)
#define SOC_CRGPERIPH_PERI_AUTODIV13_lpmcu_cfgbus_idle_bypass_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_gic_idle_bypass : 1;
        unsigned int cpu_gic_idle_waitcfg_in : 10;
        unsigned int cpu_gic_idle_waitcfg_out : 10;
        unsigned int cpu_gic_div_auto_cfg : 6;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
    } reg;
} SOC_CRGPERIPH_PERI_AUTODIV14_UNION;
#endif
#define SOC_CRGPERIPH_PERI_AUTODIV14_cpu_gic_idle_bypass_START (0)
#define SOC_CRGPERIPH_PERI_AUTODIV14_cpu_gic_idle_bypass_END (0)
#define SOC_CRGPERIPH_PERI_AUTODIV14_cpu_gic_idle_waitcfg_in_START (1)
#define SOC_CRGPERIPH_PERI_AUTODIV14_cpu_gic_idle_waitcfg_in_END (10)
#define SOC_CRGPERIPH_PERI_AUTODIV14_cpu_gic_idle_waitcfg_out_START (11)
#define SOC_CRGPERIPH_PERI_AUTODIV14_cpu_gic_idle_waitcfg_out_END (20)
#define SOC_CRGPERIPH_PERI_AUTODIV14_cpu_gic_div_auto_cfg_START (21)
#define SOC_CRGPERIPH_PERI_AUTODIV14_cpu_gic_div_auto_cfg_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int periph_cpu_idle_bypass : 1;
        unsigned int periph_cpu_idle_waitcfg_in : 10;
        unsigned int periph_cpu_idle_waitcfg_out : 10;
        unsigned int periph_cpu_div_auto_cfg : 6;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
    } reg;
} SOC_CRGPERIPH_PERI_AUTODIV15_UNION;
#endif
#define SOC_CRGPERIPH_PERI_AUTODIV15_periph_cpu_idle_bypass_START (0)
#define SOC_CRGPERIPH_PERI_AUTODIV15_periph_cpu_idle_bypass_END (0)
#define SOC_CRGPERIPH_PERI_AUTODIV15_periph_cpu_idle_waitcfg_in_START (1)
#define SOC_CRGPERIPH_PERI_AUTODIV15_periph_cpu_idle_waitcfg_in_END (10)
#define SOC_CRGPERIPH_PERI_AUTODIV15_periph_cpu_idle_waitcfg_out_START (11)
#define SOC_CRGPERIPH_PERI_AUTODIV15_periph_cpu_idle_waitcfg_out_END (20)
#define SOC_CRGPERIPH_PERI_AUTODIV15_periph_cpu_div_auto_cfg_START (21)
#define SOC_CRGPERIPH_PERI_AUTODIV15_periph_cpu_div_auto_cfg_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int periph_cpu_lit_idle_bypass : 1;
        unsigned int periph_cpu_lit_idle_waitcfg_in : 10;
        unsigned int periph_cpu_lit_idle_waitcfg_out : 10;
        unsigned int periph_cpu_lit_div_auto_cfg : 6;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
    } reg;
} SOC_CRGPERIPH_PERI_AUTODIV16_UNION;
#endif
#define SOC_CRGPERIPH_PERI_AUTODIV16_periph_cpu_lit_idle_bypass_START (0)
#define SOC_CRGPERIPH_PERI_AUTODIV16_periph_cpu_lit_idle_bypass_END (0)
#define SOC_CRGPERIPH_PERI_AUTODIV16_periph_cpu_lit_idle_waitcfg_in_START (1)
#define SOC_CRGPERIPH_PERI_AUTODIV16_periph_cpu_lit_idle_waitcfg_in_END (10)
#define SOC_CRGPERIPH_PERI_AUTODIV16_periph_cpu_lit_idle_waitcfg_out_START (11)
#define SOC_CRGPERIPH_PERI_AUTODIV16_periph_cpu_lit_idle_waitcfg_out_END (20)
#define SOC_CRGPERIPH_PERI_AUTODIV16_periph_cpu_lit_div_auto_cfg_START (21)
#define SOC_CRGPERIPH_PERI_AUTODIV16_periph_cpu_lit_div_auto_cfg_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int periph_cpu_hc_idle_bypass : 1;
        unsigned int periph_cpu_hc_idle_waitcfg_in : 10;
        unsigned int periph_cpu_hc_idle_waitcfg_out : 10;
        unsigned int periph_cpu_hc_div_auto_cfg : 6;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
    } reg;
} SOC_CRGPERIPH_PERI_AUTODIV17_UNION;
#endif
#define SOC_CRGPERIPH_PERI_AUTODIV17_periph_cpu_hc_idle_bypass_START (0)
#define SOC_CRGPERIPH_PERI_AUTODIV17_periph_cpu_hc_idle_bypass_END (0)
#define SOC_CRGPERIPH_PERI_AUTODIV17_periph_cpu_hc_idle_waitcfg_in_START (1)
#define SOC_CRGPERIPH_PERI_AUTODIV17_periph_cpu_hc_idle_waitcfg_in_END (10)
#define SOC_CRGPERIPH_PERI_AUTODIV17_periph_cpu_hc_idle_waitcfg_out_START (11)
#define SOC_CRGPERIPH_PERI_AUTODIV17_periph_cpu_hc_idle_waitcfg_out_END (20)
#define SOC_CRGPERIPH_PERI_AUTODIV17_periph_cpu_hc_div_auto_cfg_START (21)
#define SOC_CRGPERIPH_PERI_AUTODIV17_periph_cpu_hc_div_auto_cfg_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int hsdt1bus_div_auto_reduce_bypass_acpu : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int cfgbus_div_auto_reduce_bypass_acpu : 1;
        unsigned int sysbus_div_auto_reduce_bypass_acpu : 1;
        unsigned int reserved_3 : 2;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PERI_AUTODIV_ACPU_UNION;
#endif
#define SOC_CRGPERIPH_PERI_AUTODIV_ACPU_hsdt1bus_div_auto_reduce_bypass_acpu_START (1)
#define SOC_CRGPERIPH_PERI_AUTODIV_ACPU_hsdt1bus_div_auto_reduce_bypass_acpu_END (1)
#define SOC_CRGPERIPH_PERI_AUTODIV_ACPU_cfgbus_div_auto_reduce_bypass_acpu_START (4)
#define SOC_CRGPERIPH_PERI_AUTODIV_ACPU_cfgbus_div_auto_reduce_bypass_acpu_END (4)
#define SOC_CRGPERIPH_PERI_AUTODIV_ACPU_sysbus_div_auto_reduce_bypass_acpu_START (5)
#define SOC_CRGPERIPH_PERI_AUTODIV_ACPU_sysbus_div_auto_reduce_bypass_acpu_END (5)
#define SOC_CRGPERIPH_PERI_AUTODIV_ACPU_bitmasken_START (16)
#define SOC_CRGPERIPH_PERI_AUTODIV_ACPU_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int hsdt1bus_div_auto_reduce_bypass_mcpu : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int cfgbus_div_auto_reduce_bypass_mcpu : 1;
        unsigned int sysbus_div_auto_reduce_bypass_mcpu : 1;
        unsigned int reserved_3 : 2;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PERI_AUTODIV_MCPU_UNION;
#endif
#define SOC_CRGPERIPH_PERI_AUTODIV_MCPU_hsdt1bus_div_auto_reduce_bypass_mcpu_START (1)
#define SOC_CRGPERIPH_PERI_AUTODIV_MCPU_hsdt1bus_div_auto_reduce_bypass_mcpu_END (1)
#define SOC_CRGPERIPH_PERI_AUTODIV_MCPU_cfgbus_div_auto_reduce_bypass_mcpu_START (4)
#define SOC_CRGPERIPH_PERI_AUTODIV_MCPU_cfgbus_div_auto_reduce_bypass_mcpu_END (4)
#define SOC_CRGPERIPH_PERI_AUTODIV_MCPU_sysbus_div_auto_reduce_bypass_mcpu_START (5)
#define SOC_CRGPERIPH_PERI_AUTODIV_MCPU_sysbus_div_auto_reduce_bypass_mcpu_END (5)
#define SOC_CRGPERIPH_PERI_AUTODIV_MCPU_bitmasken_START (16)
#define SOC_CRGPERIPH_PERI_AUTODIV_MCPU_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hsdtbus_auto_waitcfg_in : 10;
        unsigned int hsdtbus_auto_waitcfg_out : 10;
        unsigned int hsdtbus_div_auto_reduce_bypass : 1;
        unsigned int reserved_0 : 8;
        unsigned int hsdtbus_l_div_auto_reduce_enable : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_CRGPERIPH_PERI_AUTODIV18_UNION;
#endif
#define SOC_CRGPERIPH_PERI_AUTODIV18_hsdtbus_auto_waitcfg_in_START (0)
#define SOC_CRGPERIPH_PERI_AUTODIV18_hsdtbus_auto_waitcfg_in_END (9)
#define SOC_CRGPERIPH_PERI_AUTODIV18_hsdtbus_auto_waitcfg_out_START (10)
#define SOC_CRGPERIPH_PERI_AUTODIV18_hsdtbus_auto_waitcfg_out_END (19)
#define SOC_CRGPERIPH_PERI_AUTODIV18_hsdtbus_div_auto_reduce_bypass_START (20)
#define SOC_CRGPERIPH_PERI_AUTODIV18_hsdtbus_div_auto_reduce_bypass_END (20)
#define SOC_CRGPERIPH_PERI_AUTODIV18_hsdtbus_l_div_auto_reduce_enable_START (29)
#define SOC_CRGPERIPH_PERI_AUTODIV18_hsdtbus_l_div_auto_reduce_enable_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hsdtbus_h_div_auto_cfg : 6;
        unsigned int hsdtbus_l_div_auto_cfg : 6;
        unsigned int hsdtbus_h_div_auto_cfg_fll : 6;
        unsigned int hsdtbus_l_div_auto_cfg_fll : 6;
        unsigned int reserved_0 : 7;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_CRGPERIPH_PERI_AUTODIV19_UNION;
#endif
#define SOC_CRGPERIPH_PERI_AUTODIV19_hsdtbus_h_div_auto_cfg_START (0)
#define SOC_CRGPERIPH_PERI_AUTODIV19_hsdtbus_h_div_auto_cfg_END (5)
#define SOC_CRGPERIPH_PERI_AUTODIV19_hsdtbus_l_div_auto_cfg_START (6)
#define SOC_CRGPERIPH_PERI_AUTODIV19_hsdtbus_l_div_auto_cfg_END (11)
#define SOC_CRGPERIPH_PERI_AUTODIV19_hsdtbus_h_div_auto_cfg_fll_START (12)
#define SOC_CRGPERIPH_PERI_AUTODIV19_hsdtbus_h_div_auto_cfg_fll_END (17)
#define SOC_CRGPERIPH_PERI_AUTODIV19_hsdtbus_l_div_auto_cfg_fll_START (18)
#define SOC_CRGPERIPH_PERI_AUTODIV19_hsdtbus_l_div_auto_cfg_fll_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sysqic_cfg_peri_clkrst_bypass : 1;
        unsigned int pctrl_clkrst_bypass : 1;
        unsigned int blpwm1_clkrst_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int wd0_clkrst_bypass : 1;
        unsigned int wd1_clkrst_bypass : 1;
        unsigned int npu_subchip_pctrl_clkrst_bypass : 1;
        unsigned int media2_subchip_pctrl_clkrst_bypass : 1;
        unsigned int media1_subchip_pctrl_clkrst_bypass : 1;
        unsigned int intr_hub_clkrst_bypass : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int blpwm4_clkrst_bypass : 1;
        unsigned int blpwm3_clkrst_bypass : 1;
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
        unsigned int timer9_clkrst_bypass : 1;
        unsigned int timer10_clkrst_bypass : 1;
        unsigned int timer11_clkrst_bypass : 1;
        unsigned int timer12_clkrst_bypass : 1;
    } reg;
} SOC_CRGPERIPH_IPCLKRST_BYPASS0_UNION;
#endif
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_sysqic_cfg_peri_clkrst_bypass_START (0)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_sysqic_cfg_peri_clkrst_bypass_END (0)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_pctrl_clkrst_bypass_START (1)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_pctrl_clkrst_bypass_END (1)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_blpwm1_clkrst_bypass_START (2)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_blpwm1_clkrst_bypass_END (2)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_wd0_clkrst_bypass_START (4)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_wd0_clkrst_bypass_END (4)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_wd1_clkrst_bypass_START (5)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_wd1_clkrst_bypass_END (5)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_npu_subchip_pctrl_clkrst_bypass_START (6)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_npu_subchip_pctrl_clkrst_bypass_END (6)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_media2_subchip_pctrl_clkrst_bypass_START (7)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_media2_subchip_pctrl_clkrst_bypass_END (7)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_media1_subchip_pctrl_clkrst_bypass_START (8)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_media1_subchip_pctrl_clkrst_bypass_END (8)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_intr_hub_clkrst_bypass_START (9)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_intr_hub_clkrst_bypass_END (9)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_blpwm4_clkrst_bypass_START (13)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_blpwm4_clkrst_bypass_END (13)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_blpwm3_clkrst_bypass_START (14)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_blpwm3_clkrst_bypass_END (14)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_timer9_clkrst_bypass_START (28)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_timer9_clkrst_bypass_END (28)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_timer10_clkrst_bypass_START (29)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_timer10_clkrst_bypass_END (29)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_timer11_clkrst_bypass_START (30)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_timer11_clkrst_bypass_END (30)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_timer12_clkrst_bypass_START (31)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS0_timer12_clkrst_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tzpc_clkrst_bypass : 1;
        unsigned int ipc0_clkrst_bypass : 1;
        unsigned int ipc1_clkrst_bypass : 1;
        unsigned int ioc_clkrst_bypass : 1;
        unsigned int codecssi_clkrst_bypass : 1;
        unsigned int cpu_lpctrl_clkrst_bypass : 1;
        unsigned int gpu_lpctrl_clkrst_bypass : 1;
        unsigned int media_lpctrl_clkrst_bypass : 1;
        unsigned int uart0_clkrst_bypass : 1;
        unsigned int npu_qiccfg_clkrst_bypass : 1;
        unsigned int media2_qiccfg_clkrst_bypass : 1;
        unsigned int media1_qiccfg_clkrst_bypass : 1;
        unsigned int uart4_clkrst_bypass : 1;
        unsigned int uart5_clkrst_bypass : 1;
        unsigned int onewire_clkrst_bypass : 1;
        unsigned int spi1_clkrst_bypass : 1;
        unsigned int sdcu_clkrst_bypass : 1;
        unsigned int i2c2_clkrst_bypass : 1;
        unsigned int i2c6_clkrst_bypass : 1;
        unsigned int i2c3_clkrst_bypass : 1;
        unsigned int i2c4_clkrst_bypass : 1;
        unsigned int dmac_clkrst_bypass : 1;
        unsigned int spi6_clkrst_bypass : 1;
        unsigned int ipc_rtos_clkrst_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int i3c4_clkrst_bypass : 1;
        unsigned int reserved_1 : 1;
        unsigned int hsdt1_crg_clkrst_bypass : 1;
        unsigned int media_crg_clkrst_bypass : 1;
        unsigned int media2_crg_clkrst_bypass : 1;
        unsigned int uart8_clkrst_bypass : 1;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_CRGPERIPH_IPCLKRST_BYPASS1_UNION;
#endif
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_tzpc_clkrst_bypass_START (0)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_tzpc_clkrst_bypass_END (0)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_ipc0_clkrst_bypass_START (1)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_ipc0_clkrst_bypass_END (1)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_ipc1_clkrst_bypass_START (2)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_ipc1_clkrst_bypass_END (2)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_ioc_clkrst_bypass_START (3)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_ioc_clkrst_bypass_END (3)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_codecssi_clkrst_bypass_START (4)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_codecssi_clkrst_bypass_END (4)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_cpu_lpctrl_clkrst_bypass_START (5)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_cpu_lpctrl_clkrst_bypass_END (5)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_gpu_lpctrl_clkrst_bypass_START (6)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_gpu_lpctrl_clkrst_bypass_END (6)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_media_lpctrl_clkrst_bypass_START (7)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_media_lpctrl_clkrst_bypass_END (7)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_uart0_clkrst_bypass_START (8)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_uart0_clkrst_bypass_END (8)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_npu_qiccfg_clkrst_bypass_START (9)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_npu_qiccfg_clkrst_bypass_END (9)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_media2_qiccfg_clkrst_bypass_START (10)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_media2_qiccfg_clkrst_bypass_END (10)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_media1_qiccfg_clkrst_bypass_START (11)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_media1_qiccfg_clkrst_bypass_END (11)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_uart4_clkrst_bypass_START (12)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_uart4_clkrst_bypass_END (12)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_uart5_clkrst_bypass_START (13)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_uart5_clkrst_bypass_END (13)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_onewire_clkrst_bypass_START (14)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_onewire_clkrst_bypass_END (14)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_spi1_clkrst_bypass_START (15)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_spi1_clkrst_bypass_END (15)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_sdcu_clkrst_bypass_START (16)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_sdcu_clkrst_bypass_END (16)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_i2c2_clkrst_bypass_START (17)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_i2c2_clkrst_bypass_END (17)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_i2c6_clkrst_bypass_START (18)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_i2c6_clkrst_bypass_END (18)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_i2c3_clkrst_bypass_START (19)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_i2c3_clkrst_bypass_END (19)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_i2c4_clkrst_bypass_START (20)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_i2c4_clkrst_bypass_END (20)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_dmac_clkrst_bypass_START (21)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_dmac_clkrst_bypass_END (21)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_spi6_clkrst_bypass_START (22)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_spi6_clkrst_bypass_END (22)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_ipc_rtos_clkrst_bypass_START (23)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_ipc_rtos_clkrst_bypass_END (23)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_i3c4_clkrst_bypass_START (25)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_i3c4_clkrst_bypass_END (25)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_hsdt1_crg_clkrst_bypass_START (27)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_hsdt1_crg_clkrst_bypass_END (27)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_media_crg_clkrst_bypass_START (28)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_media_crg_clkrst_bypass_END (28)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_media2_crg_clkrst_bypass_START (29)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_media2_crg_clkrst_bypass_END (29)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_uart8_clkrst_bypass_START (30)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS1_uart8_clkrst_bypass_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int npu_crg_clkrst_bypass : 1;
        unsigned int hsdt_crg_clkrst_bypass : 1;
        unsigned int core_crg_clkrst_bypass : 1;
        unsigned int lpmcu2gpu_apb_clkrst_bypass : 1;
        unsigned int ddr_lpctrl_ram_clkrst_bypass : 1;
        unsigned int pimon_clkrst_bypass : 1;
        unsigned int digtsen_clkrst_bypass : 1;
        unsigned int exmbist_cfg_clkrst_bypass : 1;
        unsigned int lpmcu2cpu_apb_clkrst_bypass : 1;
        unsigned int perf_clkrst_bypass : 1;
        unsigned int qice_cfg_clkrst_bypass : 1;
        unsigned int cpu_pctrl_clkrst_bypass : 1;
        unsigned int npu_pctrl_clkrst_bypass : 1;
        unsigned int ipf_mdm_clkrst_bypass : 1;
        unsigned int loadmonitor_clkrst_bypass : 1;
        unsigned int fcm_clkrst_bypass : 1;
        unsigned int i2c7_clkrst_bypass : 1;
        unsigned int loadmonitor_1_clkrst_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int media2_pctrl_clkrst_bypass : 1;
        unsigned int media1_pctrl_clkrst_bypass : 1;
        unsigned int atgc_clkrst_bypass : 1;
        unsigned int resource_lock_clkrst_bypass : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int dmc_a_clkrst_bypass : 1;
        unsigned int dmc_b_clkrst_bypass : 1;
        unsigned int dmc_c_clkrst_bypass : 1;
        unsigned int dmc_d_clkrst_bypass : 1;
    } reg;
} SOC_CRGPERIPH_IPCLKRST_BYPASS2_UNION;
#endif
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_npu_crg_clkrst_bypass_START (0)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_npu_crg_clkrst_bypass_END (0)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_hsdt_crg_clkrst_bypass_START (1)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_hsdt_crg_clkrst_bypass_END (1)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_core_crg_clkrst_bypass_START (2)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_core_crg_clkrst_bypass_END (2)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_lpmcu2gpu_apb_clkrst_bypass_START (3)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_lpmcu2gpu_apb_clkrst_bypass_END (3)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_ddr_lpctrl_ram_clkrst_bypass_START (4)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_ddr_lpctrl_ram_clkrst_bypass_END (4)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_pimon_clkrst_bypass_START (5)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_pimon_clkrst_bypass_END (5)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_digtsen_clkrst_bypass_START (6)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_digtsen_clkrst_bypass_END (6)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_exmbist_cfg_clkrst_bypass_START (7)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_exmbist_cfg_clkrst_bypass_END (7)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_lpmcu2cpu_apb_clkrst_bypass_START (8)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_lpmcu2cpu_apb_clkrst_bypass_END (8)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_perf_clkrst_bypass_START (9)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_perf_clkrst_bypass_END (9)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_qice_cfg_clkrst_bypass_START (10)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_qice_cfg_clkrst_bypass_END (10)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_cpu_pctrl_clkrst_bypass_START (11)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_cpu_pctrl_clkrst_bypass_END (11)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_npu_pctrl_clkrst_bypass_START (12)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_npu_pctrl_clkrst_bypass_END (12)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_ipf_mdm_clkrst_bypass_START (13)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_ipf_mdm_clkrst_bypass_END (13)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_loadmonitor_clkrst_bypass_START (14)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_loadmonitor_clkrst_bypass_END (14)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_fcm_clkrst_bypass_START (15)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_fcm_clkrst_bypass_END (15)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_i2c7_clkrst_bypass_START (16)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_i2c7_clkrst_bypass_END (16)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_loadmonitor_1_clkrst_bypass_START (17)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_loadmonitor_1_clkrst_bypass_END (17)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_media2_pctrl_clkrst_bypass_START (19)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_media2_pctrl_clkrst_bypass_END (19)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_media1_pctrl_clkrst_bypass_START (20)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_media1_pctrl_clkrst_bypass_END (20)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_atgc_clkrst_bypass_START (21)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_atgc_clkrst_bypass_END (21)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_resource_lock_clkrst_bypass_START (22)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_resource_lock_clkrst_bypass_END (22)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_dmc_a_clkrst_bypass_START (28)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_dmc_a_clkrst_bypass_END (28)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_dmc_b_clkrst_bypass_START (29)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_dmc_b_clkrst_bypass_END (29)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_dmc_c_clkrst_bypass_START (30)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_dmc_c_clkrst_bypass_END (30)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_dmc_d_clkrst_bypass_START (31)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS2_dmc_d_clkrst_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int gpio0_se_clkrst_bypass : 1;
        unsigned int power_stat_clkrst_bypass : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int hsdt1_xctrl_clkrst_bypass : 1;
        unsigned int hsdt0_xctrl_clkrst_bypass : 1;
        unsigned int reserved_3 : 25;
    } reg;
} SOC_CRGPERIPH_IPCLKRST_BYPASS3_UNION;
#endif
#define SOC_CRGPERIPH_IPCLKRST_BYPASS3_gpio0_se_clkrst_bypass_START (1)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS3_gpio0_se_clkrst_bypass_END (1)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS3_power_stat_clkrst_bypass_START (2)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS3_power_stat_clkrst_bypass_END (2)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS3_hsdt1_xctrl_clkrst_bypass_START (5)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS3_hsdt1_xctrl_clkrst_bypass_END (5)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS3_hsdt0_xctrl_clkrst_bypass_START (6)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS3_hsdt0_xctrl_clkrst_bypass_END (6)
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
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 1;
        unsigned int reserved_17 : 1;
        unsigned int reserved_18 : 1;
        unsigned int data_qcp_gpu_clkrst_bypass : 1;
        unsigned int mspc_lock_clkrst_bypass : 1;
        unsigned int reserved_19 : 11;
    } reg;
} SOC_CRGPERIPH_IPCLKRST_BYPASS4_UNION;
#endif
#define SOC_CRGPERIPH_IPCLKRST_BYPASS4_data_qcp_gpu_clkrst_bypass_START (19)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS4_data_qcp_gpu_clkrst_bypass_END (19)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS4_mspc_lock_clkrst_bypass_START (20)
#define SOC_CRGPERIPH_IPCLKRST_BYPASS4_mspc_lock_clkrst_bypass_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pclkdbg_sel_iomcu : 1;
        unsigned int pclkdbg_clkoff_sys : 1;
        unsigned int pclkdbg_to_a53cfg_clkoff_sys_0 : 1;
        unsigned int pclkdbg_to_gpu_clkoff_sys : 1;
        unsigned int pclkdbg_to_iomcu_clkoff_sys : 1;
        unsigned int pclkdbg_to_lpmcu_clkoff_sys : 1;
        unsigned int gt_atclk_cpu_lit_from_top : 1;
        unsigned int atclkoff_sys : 1;
        unsigned int atclk_to_iomcu_clkoff_sys : 1;
        unsigned int atclk_to_a53crg_clkoff_sys_0 : 1;
        unsigned int gt_atclk_cpu_hc_from_top : 1;
        unsigned int cs_soft_rst_req : 1;
        unsigned int div_clk_ddrcssys : 2;
        unsigned int gt_clk_ddrcssys : 1;
        unsigned int cs_cssys_rst_req : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PERI_CTRL2_L_UNION;
#endif
#define SOC_CRGPERIPH_PERI_CTRL2_L_pclkdbg_sel_iomcu_START (0)
#define SOC_CRGPERIPH_PERI_CTRL2_L_pclkdbg_sel_iomcu_END (0)
#define SOC_CRGPERIPH_PERI_CTRL2_L_pclkdbg_clkoff_sys_START (1)
#define SOC_CRGPERIPH_PERI_CTRL2_L_pclkdbg_clkoff_sys_END (1)
#define SOC_CRGPERIPH_PERI_CTRL2_L_pclkdbg_to_a53cfg_clkoff_sys_0_START (2)
#define SOC_CRGPERIPH_PERI_CTRL2_L_pclkdbg_to_a53cfg_clkoff_sys_0_END (2)
#define SOC_CRGPERIPH_PERI_CTRL2_L_pclkdbg_to_gpu_clkoff_sys_START (3)
#define SOC_CRGPERIPH_PERI_CTRL2_L_pclkdbg_to_gpu_clkoff_sys_END (3)
#define SOC_CRGPERIPH_PERI_CTRL2_L_pclkdbg_to_iomcu_clkoff_sys_START (4)
#define SOC_CRGPERIPH_PERI_CTRL2_L_pclkdbg_to_iomcu_clkoff_sys_END (4)
#define SOC_CRGPERIPH_PERI_CTRL2_L_pclkdbg_to_lpmcu_clkoff_sys_START (5)
#define SOC_CRGPERIPH_PERI_CTRL2_L_pclkdbg_to_lpmcu_clkoff_sys_END (5)
#define SOC_CRGPERIPH_PERI_CTRL2_L_gt_atclk_cpu_lit_from_top_START (6)
#define SOC_CRGPERIPH_PERI_CTRL2_L_gt_atclk_cpu_lit_from_top_END (6)
#define SOC_CRGPERIPH_PERI_CTRL2_L_atclkoff_sys_START (7)
#define SOC_CRGPERIPH_PERI_CTRL2_L_atclkoff_sys_END (7)
#define SOC_CRGPERIPH_PERI_CTRL2_L_atclk_to_iomcu_clkoff_sys_START (8)
#define SOC_CRGPERIPH_PERI_CTRL2_L_atclk_to_iomcu_clkoff_sys_END (8)
#define SOC_CRGPERIPH_PERI_CTRL2_L_atclk_to_a53crg_clkoff_sys_0_START (9)
#define SOC_CRGPERIPH_PERI_CTRL2_L_atclk_to_a53crg_clkoff_sys_0_END (9)
#define SOC_CRGPERIPH_PERI_CTRL2_L_gt_atclk_cpu_hc_from_top_START (10)
#define SOC_CRGPERIPH_PERI_CTRL2_L_gt_atclk_cpu_hc_from_top_END (10)
#define SOC_CRGPERIPH_PERI_CTRL2_L_cs_soft_rst_req_START (11)
#define SOC_CRGPERIPH_PERI_CTRL2_L_cs_soft_rst_req_END (11)
#define SOC_CRGPERIPH_PERI_CTRL2_L_div_clk_ddrcssys_START (12)
#define SOC_CRGPERIPH_PERI_CTRL2_L_div_clk_ddrcssys_END (13)
#define SOC_CRGPERIPH_PERI_CTRL2_L_gt_clk_ddrcssys_START (14)
#define SOC_CRGPERIPH_PERI_CTRL2_L_gt_clk_ddrcssys_END (14)
#define SOC_CRGPERIPH_PERI_CTRL2_L_cs_cssys_rst_req_START (15)
#define SOC_CRGPERIPH_PERI_CTRL2_L_cs_cssys_rst_req_END (15)
#define SOC_CRGPERIPH_PERI_CTRL2_L_bitmasken_START (16)
#define SOC_CRGPERIPH_PERI_CTRL2_L_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int atclk_to_modem_clkoff_sys : 1;
        unsigned int reserved_0 : 1;
        unsigned int modem_cssys_rst_req : 1;
        unsigned int pclkdbg_to_npucrg_clkoff_sys : 1;
        unsigned int atclk_to_vcodec_clkoff_sys : 1;
        unsigned int pclkdbg_to_vcodec_clkoff_sys : 1;
        unsigned int reserved_1 : 3;
        unsigned int pclkdbg_to_mdmperi_clkoff_sys : 1;
        unsigned int pclkdbg_to_media_clkoff_sys : 1;
        unsigned int pclkdbg_to_hsdt_clkoff_sys : 1;
        unsigned int atclk_to_peri_clkoff_sys : 1;
        unsigned int div_pclkdbg_sel : 2;
        unsigned int reserved_2 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PERI_CTRL2_H_UNION;
#endif
#define SOC_CRGPERIPH_PERI_CTRL2_H_atclk_to_modem_clkoff_sys_START (0)
#define SOC_CRGPERIPH_PERI_CTRL2_H_atclk_to_modem_clkoff_sys_END (0)
#define SOC_CRGPERIPH_PERI_CTRL2_H_modem_cssys_rst_req_START (2)
#define SOC_CRGPERIPH_PERI_CTRL2_H_modem_cssys_rst_req_END (2)
#define SOC_CRGPERIPH_PERI_CTRL2_H_pclkdbg_to_npucrg_clkoff_sys_START (3)
#define SOC_CRGPERIPH_PERI_CTRL2_H_pclkdbg_to_npucrg_clkoff_sys_END (3)
#define SOC_CRGPERIPH_PERI_CTRL2_H_atclk_to_vcodec_clkoff_sys_START (4)
#define SOC_CRGPERIPH_PERI_CTRL2_H_atclk_to_vcodec_clkoff_sys_END (4)
#define SOC_CRGPERIPH_PERI_CTRL2_H_pclkdbg_to_vcodec_clkoff_sys_START (5)
#define SOC_CRGPERIPH_PERI_CTRL2_H_pclkdbg_to_vcodec_clkoff_sys_END (5)
#define SOC_CRGPERIPH_PERI_CTRL2_H_pclkdbg_to_mdmperi_clkoff_sys_START (9)
#define SOC_CRGPERIPH_PERI_CTRL2_H_pclkdbg_to_mdmperi_clkoff_sys_END (9)
#define SOC_CRGPERIPH_PERI_CTRL2_H_pclkdbg_to_media_clkoff_sys_START (10)
#define SOC_CRGPERIPH_PERI_CTRL2_H_pclkdbg_to_media_clkoff_sys_END (10)
#define SOC_CRGPERIPH_PERI_CTRL2_H_pclkdbg_to_hsdt_clkoff_sys_START (11)
#define SOC_CRGPERIPH_PERI_CTRL2_H_pclkdbg_to_hsdt_clkoff_sys_END (11)
#define SOC_CRGPERIPH_PERI_CTRL2_H_atclk_to_peri_clkoff_sys_START (12)
#define SOC_CRGPERIPH_PERI_CTRL2_H_atclk_to_peri_clkoff_sys_END (12)
#define SOC_CRGPERIPH_PERI_CTRL2_H_div_pclkdbg_sel_START (13)
#define SOC_CRGPERIPH_PERI_CTRL2_H_div_pclkdbg_sel_END (14)
#define SOC_CRGPERIPH_PERI_CTRL2_H_bitmasken_START (16)
#define SOC_CRGPERIPH_PERI_CTRL2_H_bitmasken_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
