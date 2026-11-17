#ifndef __SOC_HI9030_V200_AO_CRG_INTERFACE_H__
#define __SOC_HI9030_V200_AO_CRG_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_Hi9030_V200_AO_CRG_AO_SYSCTRL_ADDR(base) (base)
#define SOC_Hi9030_V200_AO_CRG_AO_SYSSTAT_ADDR(base) ((base) + 0x004UL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_ADDR(base) ((base) + 0x008UL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_ADDR(base) ((base) + 0x00CUL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_ADDR(base) ((base) + 0x010UL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN1_ADDR(base) ((base) + 0x014UL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS1_ADDR(base) ((base) + 0x018UL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA1_ADDR(base) ((base) + 0x01CUL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN0_ADDR(base) ((base) + 0x020UL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS0_ADDR(base) ((base) + 0x024UL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT0_ADDR(base) ((base) + 0x028UL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIV0_ADDR(base) ((base) + 0x050UL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIV1_ADDR(base) ((base) + 0x054UL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIV2_ADDR(base) ((base) + 0x058UL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIV3_ADDR(base) ((base) + 0x05CUL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIV4_ADDR(base) ((base) + 0x060UL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSEL0_ADDR(base) ((base) + 0x064UL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKCTRL0_ADDR(base) ((base) + 0x068UL)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL0_0_ADDR(base) ((base) + 0x06CUL)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL1_0_ADDR(base) ((base) + 0x070UL)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG0_0_ADDR(base) ((base) + 0x074UL)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG1_0_ADDR(base) ((base) + 0x078UL)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG2_0_ADDR(base) ((base) + 0x07CUL)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG3_0_ADDR(base) ((base) + 0x080UL)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG4_0_ADDR(base) ((base) + 0x084UL)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG5_0_ADDR(base) ((base) + 0x088UL)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG6_0_ADDR(base) ((base) + 0x08CUL)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG7_0_ADDR(base) ((base) + 0x090UL)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG8_0_ADDR(base) ((base) + 0x094UL)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE0_0_ADDR(base) ((base) + 0x098UL)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_0_ADDR(base) ((base) + 0x09CUL)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL0_1_ADDR(base) ((base) + 0x0A0UL)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL1_1_ADDR(base) ((base) + 0x0A4UL)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG0_1_ADDR(base) ((base) + 0x0A8UL)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG1_1_ADDR(base) ((base) + 0x0ACUL)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG2_1_ADDR(base) ((base) + 0x0B0UL)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG3_1_ADDR(base) ((base) + 0x0B4UL)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG4_1_ADDR(base) ((base) + 0x0B8UL)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG5_1_ADDR(base) ((base) + 0x0BCUL)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG6_1_ADDR(base) ((base) + 0x0C0UL)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG7_1_ADDR(base) ((base) + 0x0C4UL)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG8_1_ADDR(base) ((base) + 0x0C8UL)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE0_1_ADDR(base) ((base) + 0x0CCUL)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_1_ADDR(base) ((base) + 0x0D0UL)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_VOTE0_ADDR(base) ((base) + 0x0D4UL)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL0_ADDR(base) ((base) + 0x0D8UL)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL1_ADDR(base) ((base) + 0x0DCUL)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL2_ADDR(base) ((base) + 0x0E0UL)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_STAT0_ADDR(base) ((base) + 0x0E4UL)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_STAT1_ADDR(base) ((base) + 0x0E8UL)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL0_ADDR(base) ((base) + 0x0ECUL)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL1_ADDR(base) ((base) + 0x0F0UL)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL2_ADDR(base) ((base) + 0x0F4UL)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL3_ADDR(base) ((base) + 0x0F8UL)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL4_ADDR(base) ((base) + 0x0FCUL)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL5_ADDR(base) ((base) + 0x100UL)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL6_ADDR(base) ((base) + 0x104UL)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL7_ADDR(base) ((base) + 0x108UL)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL8_ADDR(base) ((base) + 0x10CUL)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL9_ADDR(base) ((base) + 0x110UL)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL10_ADDR(base) ((base) + 0x114UL)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL11_ADDR(base) ((base) + 0x118UL)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL12_ADDR(base) ((base) + 0x11CUL)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL13_ADDR(base) ((base) + 0x120UL)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL14_ADDR(base) ((base) + 0x124UL)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL0_ADDR(base) ((base) + 0x128UL)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL1_ADDR(base) ((base) + 0x12CUL)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL2_ADDR(base) ((base) + 0x130UL)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL3_ADDR(base) ((base) + 0x134UL)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL4_ADDR(base) ((base) + 0x138UL)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT0_ADDR(base) ((base) + 0x13CUL)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT1_ADDR(base) ((base) + 0x140UL)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT2_ADDR(base) ((base) + 0x144UL)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT3_ADDR(base) ((base) + 0x148UL)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_ADDR(base) ((base) + 0x14CUL)
#define SOC_Hi9030_V200_AO_CRG_AO_HIO_SELF_RESET_ADDR(base) ((base) + 0x150UL)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_ADDR(base) ((base) + 0x154UL)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_CTRL0_ADDR(base) ((base) + 0x158UL)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_CTRL1_ADDR(base) ((base) + 0x15CUL)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_CTRL2_ADDR(base) ((base) + 0x160UL)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_CTRL3_ADDR(base) ((base) + 0x164UL)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_SOURCE_SEL_ADDR(base) ((base) + 0x168UL)
#define SOC_Hi9030_V200_AO_CRG_AO_HIO_RST_CTRL_ADDR(base) ((base) + 0x16CUL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_ADDR(base) ((base) + 0x170UL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_LOW_POWER_GT_BY0_ADDR(base) ((base) + 0x174UL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_AUTO_DE_FREQ_ADDR(base) ((base) + 0x178UL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN2_ADDR(base) ((base) + 0x800UL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS2_ADDR(base) ((base) + 0x804UL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA2_ADDR(base) ((base) + 0x808UL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN2_ADDR(base) ((base) + 0x80CUL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS2_ADDR(base) ((base) + 0x810UL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT2_ADDR(base) ((base) + 0x814UL)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL0_ADDR(base) ((base) + 0x818UL)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL1_ADDR(base) ((base) + 0x81CUL)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL2_ADDR(base) ((base) + 0x820UL)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL3_ADDR(base) ((base) + 0x824UL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_BUSINESS_SAFE_CLKDIV0_ADDR(base) ((base) + 0x828UL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_BUSINESS_SAFE_CLKDIV1_ADDR(base) ((base) + 0x82CUL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_BUSINESS_SAFE_CLKSEL0_ADDR(base) ((base) + 0x830UL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN3_ADDR(base) ((base) + 0xC00UL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS3_ADDR(base) ((base) + 0xC04UL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA3_ADDR(base) ((base) + 0xC08UL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN3_ADDR(base) ((base) + 0xC0CUL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS3_ADDR(base) ((base) + 0xC10UL)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT3_ADDR(base) ((base) + 0xC14UL)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL4_ADDR(base) ((base) + 0xC18UL)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL5_ADDR(base) ((base) + 0xC1CUL)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL6_ADDR(base) ((base) + 0xC20UL)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL7_ADDR(base) ((base) + 0xC24UL)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL0_ADDR(base) ((base) + 0xC28UL)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL1_ADDR(base) ((base) + 0xC2CUL)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL2_ADDR(base) ((base) + 0xC30UL)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL3_ADDR(base) ((base) + 0xC34UL)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL4_ADDR(base) ((base) + 0xC38UL)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL5_ADDR(base) ((base) + 0xC3CUL)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL6_ADDR(base) ((base) + 0xC40UL)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL7_ADDR(base) ((base) + 0xC44UL)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL8_ADDR(base) ((base) + 0xC48UL)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL9_ADDR(base) ((base) + 0xC4CUL)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL10_ADDR(base) ((base) + 0xC50UL)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTR11_ADDR(base) ((base) + 0xC54UL)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL12_ADDR(base) ((base) + 0xC58UL)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL13_ADDR(base) ((base) + 0xC5CUL)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL14_ADDR(base) ((base) + 0xC60UL)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL15_ADDR(base) ((base) + 0xC64UL)
#define SOC_Hi9030_V200_AO_CRG_AO_RAM_SD_CTRL0_ADDR(base) ((base) + 0xC68UL)
#define SOC_Hi9030_V200_AO_CRG_AO_RAM_SD_CTRL1_ADDR(base) ((base) + 0xC6CUL)
#define SOC_Hi9030_V200_AO_CRG_AO_RAM_SD_CTRL2_ADDR(base) ((base) + 0xC70UL)
#else
#define SOC_Hi9030_V200_AO_CRG_AO_SYSCTRL_ADDR(base) (base)
#define SOC_Hi9030_V200_AO_CRG_AO_SYSSTAT_ADDR(base) ((base) + 0x004)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_ADDR(base) ((base) + 0x008)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_ADDR(base) ((base) + 0x00C)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_ADDR(base) ((base) + 0x010)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN1_ADDR(base) ((base) + 0x014)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS1_ADDR(base) ((base) + 0x018)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA1_ADDR(base) ((base) + 0x01C)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN0_ADDR(base) ((base) + 0x020)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS0_ADDR(base) ((base) + 0x024)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT0_ADDR(base) ((base) + 0x028)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIV0_ADDR(base) ((base) + 0x050)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIV1_ADDR(base) ((base) + 0x054)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIV2_ADDR(base) ((base) + 0x058)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIV3_ADDR(base) ((base) + 0x05C)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIV4_ADDR(base) ((base) + 0x060)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSEL0_ADDR(base) ((base) + 0x064)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKCTRL0_ADDR(base) ((base) + 0x068)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL0_0_ADDR(base) ((base) + 0x06C)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL1_0_ADDR(base) ((base) + 0x070)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG0_0_ADDR(base) ((base) + 0x074)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG1_0_ADDR(base) ((base) + 0x078)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG2_0_ADDR(base) ((base) + 0x07C)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG3_0_ADDR(base) ((base) + 0x080)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG4_0_ADDR(base) ((base) + 0x084)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG5_0_ADDR(base) ((base) + 0x088)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG6_0_ADDR(base) ((base) + 0x08C)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG7_0_ADDR(base) ((base) + 0x090)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG8_0_ADDR(base) ((base) + 0x094)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE0_0_ADDR(base) ((base) + 0x098)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_0_ADDR(base) ((base) + 0x09C)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL0_1_ADDR(base) ((base) + 0x0A0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL1_1_ADDR(base) ((base) + 0x0A4)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG0_1_ADDR(base) ((base) + 0x0A8)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG1_1_ADDR(base) ((base) + 0x0AC)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG2_1_ADDR(base) ((base) + 0x0B0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG3_1_ADDR(base) ((base) + 0x0B4)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG4_1_ADDR(base) ((base) + 0x0B8)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG5_1_ADDR(base) ((base) + 0x0BC)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG6_1_ADDR(base) ((base) + 0x0C0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG7_1_ADDR(base) ((base) + 0x0C4)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG8_1_ADDR(base) ((base) + 0x0C8)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE0_1_ADDR(base) ((base) + 0x0CC)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_1_ADDR(base) ((base) + 0x0D0)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_VOTE0_ADDR(base) ((base) + 0x0D4)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL0_ADDR(base) ((base) + 0x0D8)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL1_ADDR(base) ((base) + 0x0DC)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL2_ADDR(base) ((base) + 0x0E0)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_STAT0_ADDR(base) ((base) + 0x0E4)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_STAT1_ADDR(base) ((base) + 0x0E8)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL0_ADDR(base) ((base) + 0x0EC)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL1_ADDR(base) ((base) + 0x0F0)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL2_ADDR(base) ((base) + 0x0F4)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL3_ADDR(base) ((base) + 0x0F8)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL4_ADDR(base) ((base) + 0x0FC)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL5_ADDR(base) ((base) + 0x100)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL6_ADDR(base) ((base) + 0x104)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL7_ADDR(base) ((base) + 0x108)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL8_ADDR(base) ((base) + 0x10C)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL9_ADDR(base) ((base) + 0x110)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL10_ADDR(base) ((base) + 0x114)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL11_ADDR(base) ((base) + 0x118)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL12_ADDR(base) ((base) + 0x11C)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL13_ADDR(base) ((base) + 0x120)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL14_ADDR(base) ((base) + 0x124)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL0_ADDR(base) ((base) + 0x128)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL1_ADDR(base) ((base) + 0x12C)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL2_ADDR(base) ((base) + 0x130)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL3_ADDR(base) ((base) + 0x134)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL4_ADDR(base) ((base) + 0x138)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT0_ADDR(base) ((base) + 0x13C)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT1_ADDR(base) ((base) + 0x140)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT2_ADDR(base) ((base) + 0x144)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT3_ADDR(base) ((base) + 0x148)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_ADDR(base) ((base) + 0x14C)
#define SOC_Hi9030_V200_AO_CRG_AO_HIO_SELF_RESET_ADDR(base) ((base) + 0x150)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_ADDR(base) ((base) + 0x154)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_CTRL0_ADDR(base) ((base) + 0x158)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_CTRL1_ADDR(base) ((base) + 0x15C)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_CTRL2_ADDR(base) ((base) + 0x160)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_CTRL3_ADDR(base) ((base) + 0x164)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_SOURCE_SEL_ADDR(base) ((base) + 0x168)
#define SOC_Hi9030_V200_AO_CRG_AO_HIO_RST_CTRL_ADDR(base) ((base) + 0x16C)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_ADDR(base) ((base) + 0x170)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_LOW_POWER_GT_BY0_ADDR(base) ((base) + 0x174)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_AUTO_DE_FREQ_ADDR(base) ((base) + 0x178)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN2_ADDR(base) ((base) + 0x800)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS2_ADDR(base) ((base) + 0x804)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA2_ADDR(base) ((base) + 0x808)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN2_ADDR(base) ((base) + 0x80C)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS2_ADDR(base) ((base) + 0x810)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT2_ADDR(base) ((base) + 0x814)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL0_ADDR(base) ((base) + 0x818)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL1_ADDR(base) ((base) + 0x81C)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL2_ADDR(base) ((base) + 0x820)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL3_ADDR(base) ((base) + 0x824)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_BUSINESS_SAFE_CLKDIV0_ADDR(base) ((base) + 0x828)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_BUSINESS_SAFE_CLKDIV1_ADDR(base) ((base) + 0x82C)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_BUSINESS_SAFE_CLKSEL0_ADDR(base) ((base) + 0x830)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN3_ADDR(base) ((base) + 0xC00)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS3_ADDR(base) ((base) + 0xC04)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA3_ADDR(base) ((base) + 0xC08)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN3_ADDR(base) ((base) + 0xC0C)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS3_ADDR(base) ((base) + 0xC10)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT3_ADDR(base) ((base) + 0xC14)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL4_ADDR(base) ((base) + 0xC18)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL5_ADDR(base) ((base) + 0xC1C)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL6_ADDR(base) ((base) + 0xC20)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL7_ADDR(base) ((base) + 0xC24)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL0_ADDR(base) ((base) + 0xC28)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL1_ADDR(base) ((base) + 0xC2C)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL2_ADDR(base) ((base) + 0xC30)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL3_ADDR(base) ((base) + 0xC34)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL4_ADDR(base) ((base) + 0xC38)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL5_ADDR(base) ((base) + 0xC3C)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL6_ADDR(base) ((base) + 0xC40)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL7_ADDR(base) ((base) + 0xC44)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL8_ADDR(base) ((base) + 0xC48)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL9_ADDR(base) ((base) + 0xC4C)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL10_ADDR(base) ((base) + 0xC50)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTR11_ADDR(base) ((base) + 0xC54)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL12_ADDR(base) ((base) + 0xC58)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL13_ADDR(base) ((base) + 0xC5C)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL14_ADDR(base) ((base) + 0xC60)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL15_ADDR(base) ((base) + 0xC64)
#define SOC_Hi9030_V200_AO_CRG_AO_RAM_SD_CTRL0_ADDR(base) ((base) + 0xC68)
#define SOC_Hi9030_V200_AO_CRG_AO_RAM_SD_CTRL1_ADDR(base) ((base) + 0xC6C)
#define SOC_Hi9030_V200_AO_CRG_AO_RAM_SD_CTRL2_ADDR(base) ((base) + 0xC70)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 14;
        unsigned int reserved_3: 16;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_SYSCTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ao_soft_rst_req : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_SYSSTAT_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_SYSSTAT_ao_soft_rst_req_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_SYSSTAT_ao_soft_rst_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_fnpll_ate_en : 1;
        unsigned int gt_clk_ulppll_fsm0_en : 1;
        unsigned int gt_clk_ulppll_fsm1_en : 1;
        unsigned int gt_pclk_aobus_en : 1;
        unsigned int gt_pclk_aobus_qcp_en : 1;
        unsigned int gt_ao_cam_ref_clk0_en : 1;
        unsigned int gt_ao_cam_ref_clk1_en : 1;
        unsigned int gt_ao_clk_32k_en : 1;
        unsigned int gt_clk_fnpll_in_en : 1;
        unsigned int gt_pclk_efuse_en : 1;
        unsigned int reserved_1 : 2;
        unsigned int gt_clk_hio_ulp_en : 1;
        unsigned int reserved_2 : 7;
        unsigned int gt_clk_out1_sw0_en : 1;
        unsigned int gt_pclk_ao_ioc_en : 1;
        unsigned int gt_clk_out1_en : 1;
        unsigned int gt_clk_pdc_en : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_clk_out0_en : 1;
        unsigned int hio_gt_pclk_hio_i_en : 1;
        unsigned int gt_clk_cfg_en : 1;
        unsigned int gt_clk_out1_sw1_en : 1;
        unsigned int gt_clk_out1_sw2_en : 1;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_clk_fnpll_ate_en_START (1)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_clk_fnpll_ate_en_END (1)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_clk_ulppll_fsm0_en_START (2)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_clk_ulppll_fsm0_en_END (2)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_clk_ulppll_fsm1_en_START (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_clk_ulppll_fsm1_en_END (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_pclk_aobus_en_START (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_pclk_aobus_en_END (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_pclk_aobus_qcp_en_START (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_pclk_aobus_qcp_en_END (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_ao_cam_ref_clk0_en_START (6)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_ao_cam_ref_clk0_en_END (6)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_ao_cam_ref_clk1_en_START (7)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_ao_cam_ref_clk1_en_END (7)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_ao_clk_32k_en_START (8)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_ao_clk_32k_en_END (8)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_clk_fnpll_in_en_START (9)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_clk_fnpll_in_en_END (9)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_pclk_efuse_en_START (10)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_pclk_efuse_en_END (10)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_clk_hio_ulp_en_START (13)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_clk_hio_ulp_en_END (13)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_clk_out1_sw0_en_START (21)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_clk_out1_sw0_en_END (21)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_pclk_ao_ioc_en_START (22)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_pclk_ao_ioc_en_END (22)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_clk_out1_en_START (23)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_clk_out1_en_END (23)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_clk_pdc_en_START (24)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_clk_pdc_en_END (24)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_clk_out0_en_START (27)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_clk_out0_en_END (27)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_hio_gt_pclk_hio_i_en_START (28)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_hio_gt_pclk_hio_i_en_END (28)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_clk_cfg_en_START (29)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_clk_cfg_en_END (29)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_clk_out1_sw1_en_START (30)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_clk_out1_sw1_en_END (30)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_clk_out1_sw2_en_START (31)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN0_gt_clk_out1_sw2_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_fnpll_ate_dis : 1;
        unsigned int gt_clk_ulppll_fsm0_dis : 1;
        unsigned int gt_clk_ulppll_fsm1_dis : 1;
        unsigned int gt_pclk_aobus_dis : 1;
        unsigned int gt_pclk_aobus_qcp_dis : 1;
        unsigned int gt_ao_cam_ref_clk0_dis : 1;
        unsigned int gt_ao_cam_ref_clk1_dis : 1;
        unsigned int gt_ao_clk_32k_dis : 1;
        unsigned int gt_clk_fnpll_in_dis : 1;
        unsigned int gt_pclk_efuse_dis : 1;
        unsigned int reserved_1 : 2;
        unsigned int gt_clk_hio_ulp_dis : 1;
        unsigned int reserved_2 : 7;
        unsigned int gt_clk_out1_sw0_dis : 1;
        unsigned int gt_pclk_ao_ioc_dis : 1;
        unsigned int gt_clk_out1_dis : 1;
        unsigned int gt_clk_pdc_dis : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_clk_out0_dis : 1;
        unsigned int hio_gt_pclk_hio_i_dis : 1;
        unsigned int gt_clk_cfg_dis : 1;
        unsigned int gt_clk_out1_sw1_dis : 1;
        unsigned int gt_clk_out1_sw2_dis : 1;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_clk_fnpll_ate_dis_START (1)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_clk_fnpll_ate_dis_END (1)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_clk_ulppll_fsm0_dis_START (2)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_clk_ulppll_fsm0_dis_END (2)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_clk_ulppll_fsm1_dis_START (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_clk_ulppll_fsm1_dis_END (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_pclk_aobus_dis_START (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_pclk_aobus_dis_END (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_pclk_aobus_qcp_dis_START (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_pclk_aobus_qcp_dis_END (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_ao_cam_ref_clk0_dis_START (6)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_ao_cam_ref_clk0_dis_END (6)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_ao_cam_ref_clk1_dis_START (7)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_ao_cam_ref_clk1_dis_END (7)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_ao_clk_32k_dis_START (8)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_ao_clk_32k_dis_END (8)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_clk_fnpll_in_dis_START (9)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_clk_fnpll_in_dis_END (9)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_pclk_efuse_dis_START (10)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_pclk_efuse_dis_END (10)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_clk_hio_ulp_dis_START (13)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_clk_hio_ulp_dis_END (13)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_clk_out1_sw0_dis_START (21)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_clk_out1_sw0_dis_END (21)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_pclk_ao_ioc_dis_START (22)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_pclk_ao_ioc_dis_END (22)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_clk_out1_dis_START (23)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_clk_out1_dis_END (23)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_clk_pdc_dis_START (24)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_clk_pdc_dis_END (24)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_clk_out0_dis_START (27)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_clk_out0_dis_END (27)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_hio_gt_pclk_hio_i_dis_START (28)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_hio_gt_pclk_hio_i_dis_END (28)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_clk_cfg_dis_START (29)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_clk_cfg_dis_END (29)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_clk_out1_sw1_dis_START (30)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_clk_out1_sw1_dis_END (30)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_clk_out1_sw2_dis_START (31)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS0_gt_clk_out1_sw2_dis_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_fnpll_ate_sta : 1;
        unsigned int gt_clk_ulppll_fsm0_sta : 1;
        unsigned int gt_clk_ulppll_fsm1_sta : 1;
        unsigned int gt_pclk_aobus_sta : 1;
        unsigned int gt_pclk_aobus_qcp_sta : 1;
        unsigned int gt_ao_cam_ref_clk0_sta : 1;
        unsigned int gt_ao_cam_ref_clk1_sta : 1;
        unsigned int gt_ao_clk_32k_sta : 1;
        unsigned int gt_clk_fnpll_in_sta : 1;
        unsigned int gt_pclk_efuse_sta : 1;
        unsigned int reserved_1 : 2;
        unsigned int gt_clk_hio_ulp_sta : 1;
        unsigned int reserved_2 : 7;
        unsigned int gt_clk_out1_sw0_sta : 1;
        unsigned int gt_pclk_ao_ioc_sta : 1;
        unsigned int gt_clk_out1_sta : 1;
        unsigned int gt_clk_pdc_sta : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_clk_out0_sta : 1;
        unsigned int hio_gt_pclk_hio_i_sta : 1;
        unsigned int gt_clk_cfg_sta : 1;
        unsigned int gt_clk_out1_sw1_sta : 1;
        unsigned int gt_clk_out1_sw2_sta : 1;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_clk_fnpll_ate_sta_START (1)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_clk_fnpll_ate_sta_END (1)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_clk_ulppll_fsm0_sta_START (2)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_clk_ulppll_fsm0_sta_END (2)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_clk_ulppll_fsm1_sta_START (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_clk_ulppll_fsm1_sta_END (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_pclk_aobus_sta_START (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_pclk_aobus_sta_END (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_pclk_aobus_qcp_sta_START (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_pclk_aobus_qcp_sta_END (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_ao_cam_ref_clk0_sta_START (6)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_ao_cam_ref_clk0_sta_END (6)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_ao_cam_ref_clk1_sta_START (7)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_ao_cam_ref_clk1_sta_END (7)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_ao_clk_32k_sta_START (8)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_ao_clk_32k_sta_END (8)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_clk_fnpll_in_sta_START (9)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_clk_fnpll_in_sta_END (9)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_pclk_efuse_sta_START (10)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_pclk_efuse_sta_END (10)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_clk_hio_ulp_sta_START (13)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_clk_hio_ulp_sta_END (13)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_clk_out1_sw0_sta_START (21)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_clk_out1_sw0_sta_END (21)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_pclk_ao_ioc_sta_START (22)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_pclk_ao_ioc_sta_END (22)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_clk_out1_sta_START (23)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_clk_out1_sta_END (23)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_clk_pdc_sta_START (24)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_clk_pdc_sta_END (24)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_clk_out0_sta_START (27)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_clk_out0_sta_END (27)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_hio_gt_pclk_hio_i_sta_START (28)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_hio_gt_pclk_hio_i_sta_END (28)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_clk_cfg_sta_START (29)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_clk_cfg_sta_END (29)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_clk_out1_sw1_sta_START (30)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_clk_out1_sw1_sta_END (30)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_clk_out1_sw2_sta_START (31)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA0_gt_clk_out1_sw2_sta_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_32m_ao2peri_en : 1;
        unsigned int gt_clk_fnpll_ao2peri_en : 1;
        unsigned int gt_clk_140m_ao2peri_en : 1;
        unsigned int gt_clk_uart_ao2peri_en : 1;
        unsigned int gt_pclk_peri_crg_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 26;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN1_gt_clk_32m_ao2peri_en_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN1_gt_clk_32m_ao2peri_en_END (0)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN1_gt_clk_fnpll_ao2peri_en_START (1)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN1_gt_clk_fnpll_ao2peri_en_END (1)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN1_gt_clk_140m_ao2peri_en_START (2)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN1_gt_clk_140m_ao2peri_en_END (2)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN1_gt_clk_uart_ao2peri_en_START (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN1_gt_clk_uart_ao2peri_en_END (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN1_gt_pclk_peri_crg_en_START (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN1_gt_pclk_peri_crg_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_32m_ao2peri_dis : 1;
        unsigned int gt_clk_fnpll_ao2peri_dis : 1;
        unsigned int gt_clk_140m_ao2peri_dis : 1;
        unsigned int gt_clk_uart_ao2peri_dis : 1;
        unsigned int gt_pclk_peri_crg_dis : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 26;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS1_gt_clk_32m_ao2peri_dis_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS1_gt_clk_32m_ao2peri_dis_END (0)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS1_gt_clk_fnpll_ao2peri_dis_START (1)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS1_gt_clk_fnpll_ao2peri_dis_END (1)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS1_gt_clk_140m_ao2peri_dis_START (2)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS1_gt_clk_140m_ao2peri_dis_END (2)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS1_gt_clk_uart_ao2peri_dis_START (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS1_gt_clk_uart_ao2peri_dis_END (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS1_gt_pclk_peri_crg_dis_START (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS1_gt_pclk_peri_crg_dis_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_32m_ao2peri_sta : 1;
        unsigned int gt_clk_fnpll_ao2peri_sta : 1;
        unsigned int gt_clk_140m_ao2peri_sta : 1;
        unsigned int gt_clk_uart_ao2peri_sta : 1;
        unsigned int gt_pclk_peri_crg_sta : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 26;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA1_gt_clk_32m_ao2peri_sta_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA1_gt_clk_32m_ao2peri_sta_END (0)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA1_gt_clk_fnpll_ao2peri_sta_START (1)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA1_gt_clk_fnpll_ao2peri_sta_END (1)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA1_gt_clk_140m_ao2peri_sta_START (2)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA1_gt_clk_140m_ao2peri_sta_END (2)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA1_gt_clk_uart_ao2peri_sta_START (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA1_gt_clk_uart_ao2peri_sta_END (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA1_gt_pclk_peri_crg_sta_START (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA1_gt_pclk_peri_crg_sta_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_hio_ip_rst_axi_asyncbrg_i_n_en : 1;
        unsigned int cpu_reset_ulppll_fsm_0_n_en : 1;
        unsigned int cpu_reset_ulppll_fsm_1_n_en : 1;
        unsigned int cpu_reset_pdc_n_en : 1;
        unsigned int cpu_reset_aobus_n_en : 1;
        unsigned int cpu_reset_aobus_qcp_n_en : 1;
        unsigned int reserved_0 : 4;
        unsigned int cpu_rst_hio_n_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int cpu_hio_ip_prst_hio_i_n_en : 1;
        unsigned int reserved_2 : 6;
        unsigned int cpu_reset_cfg_n_en : 1;
        unsigned int cpu_preset_ao_ioc_n_en : 1;
        unsigned int cpu_reset_peri_n_en : 1;
        unsigned int cpu_reset_pericrg_n_en : 1;
        unsigned int cpu_rst_hio_crg_n_en : 1;
        unsigned int reserved_3 : 8;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN0_cpu_hio_ip_rst_axi_asyncbrg_i_n_en_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN0_cpu_hio_ip_rst_axi_asyncbrg_i_n_en_END (0)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN0_cpu_reset_ulppll_fsm_0_n_en_START (1)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN0_cpu_reset_ulppll_fsm_0_n_en_END (1)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN0_cpu_reset_ulppll_fsm_1_n_en_START (2)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN0_cpu_reset_ulppll_fsm_1_n_en_END (2)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN0_cpu_reset_pdc_n_en_START (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN0_cpu_reset_pdc_n_en_END (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN0_cpu_reset_aobus_n_en_START (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN0_cpu_reset_aobus_n_en_END (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN0_cpu_reset_aobus_qcp_n_en_START (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN0_cpu_reset_aobus_qcp_n_en_END (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN0_cpu_rst_hio_n_en_START (10)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN0_cpu_rst_hio_n_en_END (10)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN0_cpu_hio_ip_prst_hio_i_n_en_START (12)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN0_cpu_hio_ip_prst_hio_i_n_en_END (12)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN0_cpu_reset_cfg_n_en_START (19)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN0_cpu_reset_cfg_n_en_END (19)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN0_cpu_preset_ao_ioc_n_en_START (20)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN0_cpu_preset_ao_ioc_n_en_END (20)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN0_cpu_reset_peri_n_en_START (21)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN0_cpu_reset_peri_n_en_END (21)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN0_cpu_reset_pericrg_n_en_START (22)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN0_cpu_reset_pericrg_n_en_END (22)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN0_cpu_rst_hio_crg_n_en_START (23)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN0_cpu_rst_hio_crg_n_en_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_hio_ip_rst_axi_asyncbrg_i_n_dis : 1;
        unsigned int cpu_reset_ulppll_fsm_0_n_dis : 1;
        unsigned int cpu_reset_ulppll_fsm_1_n_dis : 1;
        unsigned int cpu_reset_pdc_n_dis : 1;
        unsigned int cpu_reset_aobus_n_dis : 1;
        unsigned int cpu_reset_aobus_qcp_n_dis : 1;
        unsigned int reserved_0 : 4;
        unsigned int cpu_rst_hio_n_dis : 1;
        unsigned int reserved_1 : 1;
        unsigned int cpu_hio_ip_prst_hio_i_n_dis : 1;
        unsigned int reserved_2 : 6;
        unsigned int cpu_reset_cfg_n_dis : 1;
        unsigned int cpu_preset_ao_ioc_n_dis : 1;
        unsigned int cpu_reset_peri_n_dis : 1;
        unsigned int cpu_reset_pericrg_n_dis : 1;
        unsigned int cpu_rst_hio_crg_n_dis : 1;
        unsigned int reserved_3 : 8;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS0_cpu_hio_ip_rst_axi_asyncbrg_i_n_dis_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS0_cpu_hio_ip_rst_axi_asyncbrg_i_n_dis_END (0)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS0_cpu_reset_ulppll_fsm_0_n_dis_START (1)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS0_cpu_reset_ulppll_fsm_0_n_dis_END (1)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS0_cpu_reset_ulppll_fsm_1_n_dis_START (2)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS0_cpu_reset_ulppll_fsm_1_n_dis_END (2)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS0_cpu_reset_pdc_n_dis_START (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS0_cpu_reset_pdc_n_dis_END (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS0_cpu_reset_aobus_n_dis_START (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS0_cpu_reset_aobus_n_dis_END (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS0_cpu_reset_aobus_qcp_n_dis_START (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS0_cpu_reset_aobus_qcp_n_dis_END (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS0_cpu_rst_hio_n_dis_START (10)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS0_cpu_rst_hio_n_dis_END (10)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS0_cpu_hio_ip_prst_hio_i_n_dis_START (12)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS0_cpu_hio_ip_prst_hio_i_n_dis_END (12)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS0_cpu_reset_cfg_n_dis_START (19)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS0_cpu_reset_cfg_n_dis_END (19)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS0_cpu_preset_ao_ioc_n_dis_START (20)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS0_cpu_preset_ao_ioc_n_dis_END (20)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS0_cpu_reset_peri_n_dis_START (21)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS0_cpu_reset_peri_n_dis_END (21)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS0_cpu_reset_pericrg_n_dis_START (22)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS0_cpu_reset_pericrg_n_dis_END (22)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS0_cpu_rst_hio_crg_n_dis_START (23)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS0_cpu_rst_hio_crg_n_dis_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_hio_ip_rst_axi_asyncbrg_i_n_sta : 1;
        unsigned int cpu_reset_ulppll_fsm_0_n_sta : 1;
        unsigned int cpu_reset_ulppll_fsm_1_n_sta : 1;
        unsigned int cpu_reset_pdc_n_sta : 1;
        unsigned int cpu_reset_aobus_n_sta : 1;
        unsigned int cpu_reset_aobus_qcp_n_sta : 1;
        unsigned int reserved_0 : 4;
        unsigned int cpu_rst_hio_n_sta : 1;
        unsigned int reserved_1 : 1;
        unsigned int cpu_hio_ip_prst_hio_i_n_sta : 1;
        unsigned int reserved_2 : 6;
        unsigned int cpu_reset_cfg_n_sta : 1;
        unsigned int cpu_preset_ao_ioc_n_sta : 1;
        unsigned int cpu_reset_peri_n_sta : 1;
        unsigned int cpu_reset_pericrg_n_sta : 1;
        unsigned int cpu_rst_hio_crg_n_sta : 1;
        unsigned int reserved_3 : 8;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT0_cpu_hio_ip_rst_axi_asyncbrg_i_n_sta_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT0_cpu_hio_ip_rst_axi_asyncbrg_i_n_sta_END (0)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT0_cpu_reset_ulppll_fsm_0_n_sta_START (1)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT0_cpu_reset_ulppll_fsm_0_n_sta_END (1)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT0_cpu_reset_ulppll_fsm_1_n_sta_START (2)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT0_cpu_reset_ulppll_fsm_1_n_sta_END (2)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT0_cpu_reset_pdc_n_sta_START (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT0_cpu_reset_pdc_n_sta_END (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT0_cpu_reset_aobus_n_sta_START (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT0_cpu_reset_aobus_n_sta_END (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT0_cpu_reset_aobus_qcp_n_sta_START (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT0_cpu_reset_aobus_qcp_n_sta_END (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT0_cpu_rst_hio_n_sta_START (10)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT0_cpu_rst_hio_n_sta_END (10)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT0_cpu_hio_ip_prst_hio_i_n_sta_START (12)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT0_cpu_hio_ip_prst_hio_i_n_sta_END (12)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT0_cpu_reset_cfg_n_sta_START (19)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT0_cpu_reset_cfg_n_sta_END (19)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT0_cpu_preset_ao_ioc_n_sta_START (20)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT0_cpu_preset_ao_ioc_n_sta_END (20)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT0_cpu_reset_peri_n_sta_START (21)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT0_cpu_reset_peri_n_sta_END (21)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT0_cpu_reset_pericrg_n_sta_START (22)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT0_cpu_reset_pericrg_n_sta_END (22)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT0_cpu_rst_hio_crg_n_sta_START (23)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT0_cpu_rst_hio_crg_n_sta_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIV0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_div_fnpll_to_ulppll0 : 6;
        unsigned int cpu_div_fnpll_to_ulppll1 : 6;
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIV1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIV1_cpu_div_fnpll_to_ulppll0_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIV1_cpu_div_fnpll_to_ulppll0_END (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIV1_cpu_div_fnpll_to_ulppll1_START (6)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIV1_cpu_div_fnpll_to_ulppll1_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_div_fnpll_to_clk_out1 : 6;
        unsigned int cpu_div_clk_out0 : 6;
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIV2_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIV2_cpu_div_fnpll_to_clk_out1_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIV2_cpu_div_fnpll_to_clk_out1_END (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIV2_cpu_div_clk_out0_START (6)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIV2_cpu_div_clk_out0_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_div_clk_cam : 6;
        unsigned int cpu_div_hisimc_clk : 6;
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIV3_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIV3_cpu_div_clk_cam_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIV3_cpu_div_clk_cam_END (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIV3_cpu_div_hisimc_clk_START (6)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIV3_cpu_div_hisimc_clk_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_div_fnpll_to_pclk_uart : 6;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 4;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIV4_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIV4_cpu_div_fnpll_to_pclk_uart_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIV4_cpu_div_fnpll_to_pclk_uart_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_sel_hisimc_clk : 1;
        unsigned int reserved_0 : 1;
        unsigned int cpu_sel_clk_hio_ulp : 1;
        unsigned int cpu_sel_ulppll0 : 1;
        unsigned int cpu_sel_ulppll1 : 1;
        unsigned int cpu_sel_clk_i3c_slv : 1;
        unsigned int cpu_sel_clk_ulppll_fsm : 1;
        unsigned int cpu_sel_clk_out1 : 2;
        unsigned int cpu_sel_clk_fnpll_in : 1;
        unsigned int cpu_sel_ao_cam_ref_clk0 : 2;
        unsigned int cpu_sel_ao_cam_ref_clk1 : 2;
        unsigned int cpu_sel_pclk_aobus : 1;
        unsigned int cpu_sel_clk_out0 : 1;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSEL0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSEL0_cpu_sel_hisimc_clk_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSEL0_cpu_sel_hisimc_clk_END (0)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSEL0_cpu_sel_clk_hio_ulp_START (2)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSEL0_cpu_sel_clk_hio_ulp_END (2)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSEL0_cpu_sel_ulppll0_START (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSEL0_cpu_sel_ulppll0_END (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSEL0_cpu_sel_ulppll1_START (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSEL0_cpu_sel_ulppll1_END (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSEL0_cpu_sel_clk_i3c_slv_START (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSEL0_cpu_sel_clk_i3c_slv_END (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSEL0_cpu_sel_clk_ulppll_fsm_START (6)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSEL0_cpu_sel_clk_ulppll_fsm_END (6)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSEL0_cpu_sel_clk_out1_START (7)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSEL0_cpu_sel_clk_out1_END (8)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSEL0_cpu_sel_clk_fnpll_in_START (9)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSEL0_cpu_sel_clk_fnpll_in_END (9)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSEL0_cpu_sel_ao_cam_ref_clk0_START (10)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSEL0_cpu_sel_ao_cam_ref_clk0_END (11)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSEL0_cpu_sel_ao_cam_ref_clk1_START (12)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSEL0_cpu_sel_ao_cam_ref_clk1_END (13)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSEL0_cpu_sel_pclk_aobus_START (14)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSEL0_cpu_sel_pclk_aobus_END (14)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSEL0_cpu_sel_clk_out0_START (15)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSEL0_cpu_sel_clk_out0_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 4;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int sel_pll_tp : 2;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int psel_autogt_bypass : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 16;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKCTRL0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKCTRL0_sel_pll_tp_START (10)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKCTRL0_sel_pll_tp_END (11)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKCTRL0_psel_autogt_bypass_START (14)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKCTRL0_psel_autogt_bypass_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_en_0 : 1;
        unsigned int ulppll_bp_0 : 1;
        unsigned int ulppll_fbdiv_0 : 15;
        unsigned int reserved : 15;
    } reg;
} SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL0_0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL0_0_ulppll_en_0_START (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL0_0_ulppll_en_0_END (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL0_0_ulppll_bp_0_START (1)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL0_0_ulppll_bp_0_END (1)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL0_0_ulppll_fbdiv_0_START (2)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL0_0_ulppll_fbdiv_0_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_ulppll_0 : 1;
        unsigned int ulppll_sleep_en_0 : 1;
        unsigned int ulppll_dt_work_en_0 : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL1_0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL1_0_gt_clk_ulppll_0_START (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL1_0_gt_clk_ulppll_0_END (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL1_0_ulppll_sleep_en_0_START (1)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL1_0_ulppll_sleep_en_0_END (1)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL1_0_ulppll_dt_work_en_0_START (2)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL1_0_ulppll_dt_work_en_0_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_cfg0_0 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG0_0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG0_0_ulppll_cfg0_0_START (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG0_0_ulppll_cfg0_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_cfg1_0 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG1_0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG1_0_ulppll_cfg1_0_START (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG1_0_ulppll_cfg1_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_cfg2_0 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG2_0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG2_0_ulppll_cfg2_0_START (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG2_0_ulppll_cfg2_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_cfg3_0 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG3_0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG3_0_ulppll_cfg3_0_START (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG3_0_ulppll_cfg3_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_cfg4_0 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG4_0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG4_0_ulppll_cfg4_0_START (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG4_0_ulppll_cfg4_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_cfg5_0 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG5_0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG5_0_ulppll_cfg5_0_START (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG5_0_ulppll_cfg5_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_cfg6_0 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG6_0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG6_0_ulppll_cfg6_0_START (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG6_0_ulppll_cfg6_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_cfg7_0 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG7_0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG7_0_ulppll_cfg7_0_START (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG7_0_ulppll_cfg7_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_cfg8_0 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG8_0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG8_0_ulppll_cfg8_0_START (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG8_0_ulppll_cfg8_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_state0_0 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE0_0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE0_0_ulppll_state0_0_START (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE0_0_ulppll_state0_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_lock_0 : 1;
        unsigned int ulppll_op_freq_flag_0 : 1;
        unsigned int st_clk_ulppll_ini_0 : 1;
        unsigned int ulppll_gt_stat_0 : 1;
        unsigned int ulppll_bypass_0 : 1;
        unsigned int ulppll_en_stat_0 : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_0_ulppll_lock_0_START (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_0_ulppll_lock_0_END (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_0_ulppll_op_freq_flag_0_START (1)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_0_ulppll_op_freq_flag_0_END (1)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_0_st_clk_ulppll_ini_0_START (2)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_0_st_clk_ulppll_ini_0_END (2)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_0_ulppll_gt_stat_0_START (3)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_0_ulppll_gt_stat_0_END (3)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_0_ulppll_bypass_0_START (4)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_0_ulppll_bypass_0_END (4)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_0_ulppll_en_stat_0_START (5)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_0_ulppll_en_stat_0_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_en_1 : 1;
        unsigned int ulppll_bp_1 : 1;
        unsigned int ulppll_fbdiv_1 : 15;
        unsigned int reserved : 15;
    } reg;
} SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL0_1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL0_1_ulppll_en_1_START (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL0_1_ulppll_en_1_END (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL0_1_ulppll_bp_1_START (1)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL0_1_ulppll_bp_1_END (1)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL0_1_ulppll_fbdiv_1_START (2)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL0_1_ulppll_fbdiv_1_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_ulppll_1 : 1;
        unsigned int ulppll_sleep_en_1 : 1;
        unsigned int ulppll_dt_work_en_1 : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL1_1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL1_1_gt_clk_ulppll_1_START (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL1_1_gt_clk_ulppll_1_END (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL1_1_ulppll_sleep_en_1_START (1)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL1_1_ulppll_sleep_en_1_END (1)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL1_1_ulppll_dt_work_en_1_START (2)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CTRL1_1_ulppll_dt_work_en_1_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_cfg0_1 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG0_1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG0_1_ulppll_cfg0_1_START (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG0_1_ulppll_cfg0_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_cfg1_1 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG1_1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG1_1_ulppll_cfg1_1_START (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG1_1_ulppll_cfg1_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_cfg2_1 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG2_1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG2_1_ulppll_cfg2_1_START (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG2_1_ulppll_cfg2_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_cfg3_1 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG3_1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG3_1_ulppll_cfg3_1_START (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG3_1_ulppll_cfg3_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_cfg4_1 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG4_1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG4_1_ulppll_cfg4_1_START (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG4_1_ulppll_cfg4_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_cfg5_1 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG5_1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG5_1_ulppll_cfg5_1_START (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG5_1_ulppll_cfg5_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_cfg6_1 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG6_1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG6_1_ulppll_cfg6_1_START (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG6_1_ulppll_cfg6_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_cfg7_1 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG7_1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG7_1_ulppll_cfg7_1_START (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG7_1_ulppll_cfg7_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_cfg8_1 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG8_1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG8_1_ulppll_cfg8_1_START (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_CFG8_1_ulppll_cfg8_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_state0_1 : 32;
    } reg;
} SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE0_1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE0_1_ulppll_state0_1_START (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE0_1_ulppll_state0_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_lock_1 : 1;
        unsigned int ulppll_op_freq_flag_1 : 1;
        unsigned int st_clk_ulppll_ini_1 : 1;
        unsigned int ulppll_gt_stat_1 : 1;
        unsigned int ulppll_bypass_1 : 1;
        unsigned int ulppll_en_stat_1 : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_1_ulppll_lock_1_START (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_1_ulppll_lock_1_END (0)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_1_ulppll_op_freq_flag_1_START (1)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_1_ulppll_op_freq_flag_1_END (1)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_1_st_clk_ulppll_ini_1_START (2)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_1_st_clk_ulppll_ini_1_END (2)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_1_ulppll_gt_stat_1_START (3)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_1_ulppll_gt_stat_1_END (3)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_1_ulppll_bypass_1_START (4)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_1_ulppll_bypass_1_END (4)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_1_ulppll_en_stat_1_START (5)
#define SOC_Hi9030_V200_AO_CRG_ULPPLL_STATE1_1_ulppll_en_stat_1_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_en_fsm_vote_0 : 1;
        unsigned int ulppll_en_fsm_vote_1 : 1;
        unsigned int reserved_0 : 13;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_Hi9030_V200_AO_CRG_PLL_FSM_VOTE0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_VOTE0_ulppll_en_fsm_vote_0_START (0)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_VOTE0_ulppll_en_fsm_vote_0_END (0)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_VOTE0_ulppll_en_fsm_vote_1_START (1)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_VOTE0_ulppll_en_fsm_vote_1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_fsm_en_0 : 1;
        unsigned int ulppll_fsm_en_1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int ulppll_vote_mode_sel_0 : 1;
        unsigned int ulppll_vote_mode_sel_1 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int ulppll_intr_clr_0 : 1;
        unsigned int ulppll_intr_clr_1 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 16;
    } reg;
} SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL0_ulppll_fsm_en_0_START (0)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL0_ulppll_fsm_en_0_END (0)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL0_ulppll_fsm_en_1_START (1)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL0_ulppll_fsm_en_1_END (1)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL0_ulppll_vote_mode_sel_0_START (5)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL0_ulppll_vote_mode_sel_0_END (5)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL0_ulppll_vote_mode_sel_1_START (6)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL0_ulppll_vote_mode_sel_1_END (6)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL0_ulppll_intr_clr_0_START (10)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL0_ulppll_intr_clr_0_END (10)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL0_ulppll_intr_clr_1_START (11)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL0_ulppll_intr_clr_1_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pll_lock_dbc_en : 1;
        unsigned int pll_fsm_intr_en : 1;
        unsigned int pll_wait_en : 1;
        unsigned int pll_timeout_en : 1;
        unsigned int pll_intr_lmt : 3;
        unsigned int reserved : 25;
    } reg;
} SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL1_pll_lock_dbc_en_START (0)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL1_pll_lock_dbc_en_END (0)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL1_pll_fsm_intr_en_START (1)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL1_pll_fsm_intr_en_END (1)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL1_pll_wait_en_START (2)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL1_pll_wait_en_END (2)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL1_pll_timeout_en_START (3)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL1_pll_timeout_en_END (3)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL1_pll_intr_lmt_START (4)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL1_pll_intr_lmt_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pll_wait_lmt : 14;
        unsigned int pll_timeout_lmt : 14;
        unsigned int reserved : 4;
    } reg;
} SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL2_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL2_pll_wait_lmt_START (0)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL2_pll_wait_lmt_END (13)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL2_pll_timeout_lmt_START (14)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_CTRL2_pll_timeout_lmt_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_intr_cnt_0 : 3;
        unsigned int ulppll_intr_cnt_1 : 3;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 3;
        unsigned int reserved_2 : 3;
        unsigned int reserved_3 : 9;
        unsigned int ulppll_fsm_intr_0 : 1;
        unsigned int ulppll_fsm_intr_1 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
    } reg;
} SOC_Hi9030_V200_AO_CRG_PLL_FSM_STAT0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_STAT0_ulppll_intr_cnt_0_START (0)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_STAT0_ulppll_intr_cnt_0_END (2)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_STAT0_ulppll_intr_cnt_1_START (3)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_STAT0_ulppll_intr_cnt_1_END (5)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_STAT0_ulppll_fsm_intr_0_START (24)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_STAT0_ulppll_fsm_intr_0_END (24)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_STAT0_ulppll_fsm_intr_1_START (25)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_STAT0_ulppll_fsm_intr_1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_curr_stat_0 : 4;
        unsigned int ulppll_curr_stat_1 : 4;
        unsigned int ulppll_fsm_wsat_0 : 1;
        unsigned int ulppll_fsm_wsat_1 : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_Hi9030_V200_AO_CRG_PLL_FSM_STAT1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_STAT1_ulppll_curr_stat_0_START (0)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_STAT1_ulppll_curr_stat_0_END (3)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_STAT1_ulppll_curr_stat_1_START (4)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_STAT1_ulppll_curr_stat_1_END (7)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_STAT1_ulppll_fsm_wsat_0_START (8)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_STAT1_ulppll_fsm_wsat_0_END (8)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_STAT1_ulppll_fsm_wsat_1_START (9)
#define SOC_Hi9030_V200_AO_CRG_PLL_FSM_STAT1_ulppll_fsm_wsat_1_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_pdc_state_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL0_cpu_pdc_state_en_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL0_cpu_pdc_state_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_pon_step_dly_value0 : 10;
        unsigned int cpu_pon_step_dly_value1 : 10;
        unsigned int cpu_pon_step_dly_value2 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL1_cpu_pon_step_dly_value0_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL1_cpu_pon_step_dly_value0_END (9)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL1_cpu_pon_step_dly_value1_START (10)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL1_cpu_pon_step_dly_value1_END (19)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL1_cpu_pon_step_dly_value2_START (20)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL1_cpu_pon_step_dly_value2_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_pon_step_dly_value3 : 10;
        unsigned int cpu_pon_step_dly_value4 : 10;
        unsigned int cpu_pon_step_dly_value5 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL2_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL2_cpu_pon_step_dly_value3_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL2_cpu_pon_step_dly_value3_END (9)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL2_cpu_pon_step_dly_value4_START (10)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL2_cpu_pon_step_dly_value4_END (19)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL2_cpu_pon_step_dly_value5_START (20)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL2_cpu_pon_step_dly_value5_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_pon_step_dly_value6 : 10;
        unsigned int cpu_pon_step_dly_value7 : 10;
        unsigned int cpu_pon_step_dly_value8 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL3_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL3_cpu_pon_step_dly_value6_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL3_cpu_pon_step_dly_value6_END (9)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL3_cpu_pon_step_dly_value7_START (10)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL3_cpu_pon_step_dly_value7_END (19)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL3_cpu_pon_step_dly_value8_START (20)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL3_cpu_pon_step_dly_value8_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_poff_step_dly_value0 : 10;
        unsigned int cpu_poff_step_dly_value1 : 10;
        unsigned int cpu_poff_step_dly_value2 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL4_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL4_cpu_poff_step_dly_value0_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL4_cpu_poff_step_dly_value0_END (9)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL4_cpu_poff_step_dly_value1_START (10)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL4_cpu_poff_step_dly_value1_END (19)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL4_cpu_poff_step_dly_value2_START (20)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL4_cpu_poff_step_dly_value2_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_poff_step_dly_value3 : 10;
        unsigned int cpu_poff_step_dly_value4 : 10;
        unsigned int cpu_poff_step_dly_value5 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL5_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL5_cpu_poff_step_dly_value3_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL5_cpu_poff_step_dly_value3_END (9)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL5_cpu_poff_step_dly_value4_START (10)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL5_cpu_poff_step_dly_value4_END (19)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL5_cpu_poff_step_dly_value5_START (20)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL5_cpu_poff_step_dly_value5_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_poff_step_dly_value6 : 10;
        unsigned int cpu_poff_step_dly_value7 : 10;
        unsigned int cpu_poff_step_dly_value8 : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL6_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL6_cpu_poff_step_dly_value6_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL6_cpu_poff_step_dly_value6_END (9)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL6_cpu_poff_step_dly_value7_START (10)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL6_cpu_poff_step_dly_value7_END (19)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL6_cpu_poff_step_dly_value8_START (20)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL6_cpu_poff_step_dly_value8_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_pon_mtcmos_en_no : 3;
        unsigned int cpu_pon_mtcmos_rdy_no : 3;
        unsigned int cpu_pon_ram_sd_no : 3;
        unsigned int cpu_pon_iso_en_no : 3;
        unsigned int cpu_pon_rst_en_no : 3;
        unsigned int cpu_pon_clk_en_no : 3;
        unsigned int cpu_pon_qic_en_no : 3;
        unsigned int cpu_pon_qic_ack_no : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL7_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL7_cpu_pon_mtcmos_en_no_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL7_cpu_pon_mtcmos_en_no_END (2)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL7_cpu_pon_mtcmos_rdy_no_START (3)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL7_cpu_pon_mtcmos_rdy_no_END (5)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL7_cpu_pon_ram_sd_no_START (6)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL7_cpu_pon_ram_sd_no_END (8)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL7_cpu_pon_iso_en_no_START (9)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL7_cpu_pon_iso_en_no_END (11)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL7_cpu_pon_rst_en_no_START (12)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL7_cpu_pon_rst_en_no_END (14)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL7_cpu_pon_clk_en_no_START (15)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL7_cpu_pon_clk_en_no_END (17)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL7_cpu_pon_qic_en_no_START (18)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL7_cpu_pon_qic_en_no_END (20)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL7_cpu_pon_qic_ack_no_START (21)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL7_cpu_pon_qic_ack_no_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_poff_mtcmos_en_no : 3;
        unsigned int cpu_poff_mtcmos_rdy_no : 3;
        unsigned int cpu_poff_ram_sd_no : 3;
        unsigned int cpu_poff_iso_en_no : 3;
        unsigned int cpu_poff_rst_en_no : 3;
        unsigned int cpu_poff_clk_en_no : 3;
        unsigned int cpu_poff_qic_en_no : 3;
        unsigned int cpu_poff_qic_ack_no : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL8_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL8_cpu_poff_mtcmos_en_no_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL8_cpu_poff_mtcmos_en_no_END (2)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL8_cpu_poff_mtcmos_rdy_no_START (3)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL8_cpu_poff_mtcmos_rdy_no_END (5)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL8_cpu_poff_ram_sd_no_START (6)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL8_cpu_poff_ram_sd_no_END (8)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL8_cpu_poff_iso_en_no_START (9)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL8_cpu_poff_iso_en_no_END (11)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL8_cpu_poff_rst_en_no_START (12)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL8_cpu_poff_rst_en_no_END (14)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL8_cpu_poff_clk_en_no_START (15)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL8_cpu_poff_clk_en_no_END (17)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL8_cpu_poff_qic_en_no_START (18)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL8_cpu_poff_qic_en_no_END (20)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL8_cpu_poff_qic_ack_no_START (21)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL8_cpu_poff_qic_ack_no_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_qic_ao_bus_idle_bp : 1;
        unsigned int cpu_qic_peri_bus_idle_bp : 1;
        unsigned int cpu_qspi_idle_bp : 1;
        unsigned int cpu_qic_bus_idle_bp : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL9_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL9_cpu_qic_ao_bus_idle_bp_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL9_cpu_qic_ao_bus_idle_bp_END (0)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL9_cpu_qic_peri_bus_idle_bp_START (1)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL9_cpu_qic_peri_bus_idle_bp_END (1)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL9_cpu_qspi_idle_bp_START (2)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL9_cpu_qspi_idle_bp_END (2)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL9_cpu_qic_bus_idle_bp_START (3)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL9_cpu_qic_bus_idle_bp_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_qic_bus_div_nl : 6;
        unsigned int cpu_qic_bus_div_nh : 6;
        unsigned int cpu_qic_bus_div_spd : 6;
        unsigned int cpu_qic_bus_div_idle : 6;
        unsigned int reserved : 8;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL10_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL10_cpu_qic_bus_div_nl_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL10_cpu_qic_bus_div_nl_END (5)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL10_cpu_qic_bus_div_nh_START (6)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL10_cpu_qic_bus_div_nh_END (11)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL10_cpu_qic_bus_div_spd_START (12)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL10_cpu_qic_bus_div_spd_END (17)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL10_cpu_qic_bus_div_idle_START (18)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL10_cpu_qic_bus_div_idle_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_pon_step_value : 8;
        unsigned int cpu_poff_step_value : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL11_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL11_cpu_pon_step_value_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL11_cpu_pon_step_value_END (7)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL11_cpu_poff_step_value_START (8)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL11_cpu_poff_step_value_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_ao2peri_clken_sel : 1;
        unsigned int cpu_ao2peri_rsten_sel : 1;
        unsigned int cpu_ulppll_lock_0_mask : 1;
        unsigned int cpu_ulppll_lock_1_mask : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL12_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL12_cpu_ao2peri_clken_sel_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL12_cpu_ao2peri_clken_sel_END (0)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL12_cpu_ao2peri_rsten_sel_START (1)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL12_cpu_ao2peri_rsten_sel_END (1)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL12_cpu_ulppll_lock_0_mask_START (2)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL12_cpu_ulppll_lock_0_mask_END (2)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL12_cpu_ulppll_lock_1_mask_START (3)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL12_cpu_ulppll_lock_1_mask_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_bus_idle_wait_num_in : 7;
        unsigned int cpu_bus_idle_wait_num_out : 7;
        unsigned int reserved : 18;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL13_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL13_cpu_bus_idle_wait_num_in_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL13_cpu_bus_idle_wait_num_in_END (6)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL13_cpu_bus_idle_wait_num_out_START (7)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL13_cpu_bus_idle_wait_num_out_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_clk_en_pre_time_start : 10;
        unsigned int cpu_clk_en_pre_time_end : 10;
        unsigned int reserved : 12;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL14_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL14_cpu_clk_en_pre_time_start_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL14_cpu_clk_en_pre_time_start_END (9)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL14_cpu_clk_en_pre_time_end_START (10)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_CTRL14_cpu_clk_en_pre_time_end_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_intr_pls2lvl_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL0_cpu_intr_pls2lvl_en_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL0_cpu_intr_pls2lvl_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_ckg_bypass_pls2lvl : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL1_cpu_ckg_bypass_pls2lvl_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL1_cpu_ckg_bypass_pls2lvl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_pdc_state_intr_pls_mask : 1;
        unsigned int cpu_pon_mtcmos_rdy_overtime_intr_pls_mask : 1;
        unsigned int cpu_pon_qic_ack_overtime_intr_pls_mask : 1;
        unsigned int cpu_poff_mtcmos_rdy_overtime_intr_pls_mask : 1;
        unsigned int cpu_poff_qic_ack_overtime_intr_pls_mask : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL2_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL2_cpu_pdc_state_intr_pls_mask_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL2_cpu_pdc_state_intr_pls_mask_END (0)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL2_cpu_pon_mtcmos_rdy_overtime_intr_pls_mask_START (1)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL2_cpu_pon_mtcmos_rdy_overtime_intr_pls_mask_END (1)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL2_cpu_pon_qic_ack_overtime_intr_pls_mask_START (2)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL2_cpu_pon_qic_ack_overtime_intr_pls_mask_END (2)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL2_cpu_poff_mtcmos_rdy_overtime_intr_pls_mask_START (3)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL2_cpu_poff_mtcmos_rdy_overtime_intr_pls_mask_END (3)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL2_cpu_poff_qic_ack_overtime_intr_pls_mask_START (4)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL2_cpu_poff_qic_ack_overtime_intr_pls_mask_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_pdc_state_intr_pls_clr : 1;
        unsigned int cpu_pon_mtcmos_rdy_overtime_intr_pls_clr : 1;
        unsigned int cpu_pon_qic_ack_overtime_intr_pls_clr : 1;
        unsigned int cpu_poff_mtcmos_rdy_overtime_intr_pls_clr : 1;
        unsigned int cpu_poff_qic_ack_overtime_intr_pls_clr : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL3_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL3_cpu_pdc_state_intr_pls_clr_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL3_cpu_pdc_state_intr_pls_clr_END (0)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL3_cpu_pon_mtcmos_rdy_overtime_intr_pls_clr_START (1)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL3_cpu_pon_mtcmos_rdy_overtime_intr_pls_clr_END (1)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL3_cpu_pon_qic_ack_overtime_intr_pls_clr_START (2)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL3_cpu_pon_qic_ack_overtime_intr_pls_clr_END (2)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL3_cpu_poff_mtcmos_rdy_overtime_intr_pls_clr_START (3)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL3_cpu_poff_mtcmos_rdy_overtime_intr_pls_clr_END (3)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL3_cpu_poff_qic_ack_overtime_intr_pls_clr_START (4)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL3_cpu_poff_qic_ack_overtime_intr_pls_clr_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_pdc_state_intr_pls_err_clr : 1;
        unsigned int cpu_pon_mtcmos_rdy_overtime_intr_pls_err_clr : 1;
        unsigned int cpu_pon_qic_ack_overtime_intr_pls_err_clr : 1;
        unsigned int cpu_poff_mtcmos_rdy_overtime_intr_pls_err_clr : 1;
        unsigned int cpu_poff_qic_ack_overtime_intr_pls_err_clr : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL4_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL4_cpu_pdc_state_intr_pls_err_clr_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL4_cpu_pdc_state_intr_pls_err_clr_END (0)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL4_cpu_pon_mtcmos_rdy_overtime_intr_pls_err_clr_START (1)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL4_cpu_pon_mtcmos_rdy_overtime_intr_pls_err_clr_END (1)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL4_cpu_pon_qic_ack_overtime_intr_pls_err_clr_START (2)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL4_cpu_pon_qic_ack_overtime_intr_pls_err_clr_END (2)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL4_cpu_poff_mtcmos_rdy_overtime_intr_pls_err_clr_START (3)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL4_cpu_poff_mtcmos_rdy_overtime_intr_pls_err_clr_END (3)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL4_cpu_poff_qic_ack_overtime_intr_pls_err_clr_START (4)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_CTRL4_cpu_poff_qic_ack_overtime_intr_pls_err_clr_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hio_burst_cnt_lowbit : 32;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT0_hio_burst_cnt_lowbit_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT0_hio_burst_cnt_lowbit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hio_burst_cnt_highbit : 31;
        unsigned int cpu_hio_burst_cnt_clr : 1;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT1_hio_burst_cnt_highbit_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT1_hio_burst_cnt_highbit_END (30)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT1_cpu_hio_burst_cnt_clr_START (31)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT1_cpu_hio_burst_cnt_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pdc_fsm_state : 3;
        unsigned int hio_peri_on_ack : 1;
        unsigned int pdc_peri_syspdc_pwrd_req : 1;
        unsigned int intr_iodie_sctrl : 1;
        unsigned int qic_bus_div : 6;
        unsigned int peri_mtcmos_en_sta : 1;
        unsigned int peri_ram_sd_sta : 1;
        unsigned int peri_iso_en_sta : 1;
        unsigned int peri_clk_en_sta : 1;
        unsigned int peri_rst_en_sta : 1;
        unsigned int intr_pdc_ack_overtime : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT2_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT2_pdc_fsm_state_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT2_pdc_fsm_state_END (2)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT2_hio_peri_on_ack_START (3)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT2_hio_peri_on_ack_END (3)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT2_pdc_peri_syspdc_pwrd_req_START (4)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT2_pdc_peri_syspdc_pwrd_req_END (4)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT2_intr_iodie_sctrl_START (5)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT2_intr_iodie_sctrl_END (5)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT2_qic_bus_div_START (6)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT2_qic_bus_div_END (11)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT2_peri_mtcmos_en_sta_START (12)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT2_peri_mtcmos_en_sta_END (12)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT2_peri_ram_sd_sta_START (13)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT2_peri_ram_sd_sta_END (13)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT2_peri_iso_en_sta_START (14)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT2_peri_iso_en_sta_END (14)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT2_peri_clk_en_sta_START (15)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT2_peri_clk_en_sta_END (15)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT2_peri_rst_en_sta_START (16)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT2_peri_rst_en_sta_END (16)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT2_intr_pdc_ack_overtime_START (17)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT2_intr_pdc_ack_overtime_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qspi_idle_sync : 1;
        unsigned int qic_peri_bus_nopending_combo_sync : 1;
        unsigned int qic_ao_bus_nopending_combo_sync : 1;
        unsigned int pdc_peri_syspdc_pwrd_ack_sync : 1;
        unsigned int peri_mtcoms_rdy_sync : 1;
        unsigned int phy_rx_status_sync : 1;
        unsigned int phy_tx_status_sync : 1;
        unsigned int hio_rate_status_sync : 1;
        unsigned int hio_peri_on_req_sync : 1;
        unsigned int hio_gt_clk_axi_asyncbrg_i_sta_sync : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT3_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT3_qspi_idle_sync_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT3_qspi_idle_sync_END (0)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT3_qic_peri_bus_nopending_combo_sync_START (1)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT3_qic_peri_bus_nopending_combo_sync_END (1)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT3_qic_ao_bus_nopending_combo_sync_START (2)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT3_qic_ao_bus_nopending_combo_sync_END (2)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT3_pdc_peri_syspdc_pwrd_ack_sync_START (3)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT3_pdc_peri_syspdc_pwrd_ack_sync_END (3)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT3_peri_mtcoms_rdy_sync_START (4)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT3_peri_mtcoms_rdy_sync_END (4)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT3_phy_rx_status_sync_START (5)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT3_phy_rx_status_sync_END (5)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT3_phy_tx_status_sync_START (6)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT3_phy_tx_status_sync_END (6)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT3_hio_rate_status_sync_START (7)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT3_hio_rate_status_sync_END (7)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT3_hio_peri_on_req_sync_START (8)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT3_hio_peri_on_req_sync_END (8)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT3_hio_gt_clk_axi_asyncbrg_i_sta_sync_START (9)
#define SOC_Hi9030_V200_AO_CRG_AO_POWER_FSM_RPT3_hio_gt_clk_axi_asyncbrg_i_sta_sync_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pdc_state_intr_pls_sta : 1;
        unsigned int pon_mtcmos_rdy_overtime_intr_pls_sta : 1;
        unsigned int pon_qic_ack_overtime_intr_pls_sta : 1;
        unsigned int poff_mtcmos_rdy_overtime_intr_pls_sta : 1;
        unsigned int poff_qic_ack_overtime_intr_pls_sta : 1;
        unsigned int pdc_state_intr_pls_raw : 1;
        unsigned int pon_mtcmos_rdy_overtime_intr_pls_raw : 1;
        unsigned int pon_qic_ack_overtime_intr_pls_raw : 1;
        unsigned int poff_mtcmos_rdy_overtime_intr_pls_raw : 1;
        unsigned int poff_qic_ack_overtime_intr_pls_raw : 1;
        unsigned int pdc_state_intr_pls_err_rpt : 1;
        unsigned int pon_mtcmos_rdy_overtime_intr_pls_err_rpt : 1;
        unsigned int pon_qic_ack_overtime_intr_pls_err_rpt : 1;
        unsigned int poff_mtcmos_rdy_overtime_intr_pls_err_rpt : 1;
        unsigned int poff_qic_ack_overtime_intr_pls_err_rpt : 1;
        unsigned int reserved : 17;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_pdc_state_intr_pls_sta_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_pdc_state_intr_pls_sta_END (0)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_pon_mtcmos_rdy_overtime_intr_pls_sta_START (1)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_pon_mtcmos_rdy_overtime_intr_pls_sta_END (1)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_pon_qic_ack_overtime_intr_pls_sta_START (2)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_pon_qic_ack_overtime_intr_pls_sta_END (2)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_poff_mtcmos_rdy_overtime_intr_pls_sta_START (3)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_poff_mtcmos_rdy_overtime_intr_pls_sta_END (3)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_poff_qic_ack_overtime_intr_pls_sta_START (4)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_poff_qic_ack_overtime_intr_pls_sta_END (4)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_pdc_state_intr_pls_raw_START (5)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_pdc_state_intr_pls_raw_END (5)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_pon_mtcmos_rdy_overtime_intr_pls_raw_START (6)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_pon_mtcmos_rdy_overtime_intr_pls_raw_END (6)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_pon_qic_ack_overtime_intr_pls_raw_START (7)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_pon_qic_ack_overtime_intr_pls_raw_END (7)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_poff_mtcmos_rdy_overtime_intr_pls_raw_START (8)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_poff_mtcmos_rdy_overtime_intr_pls_raw_END (8)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_poff_qic_ack_overtime_intr_pls_raw_START (9)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_poff_qic_ack_overtime_intr_pls_raw_END (9)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_pdc_state_intr_pls_err_rpt_START (10)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_pdc_state_intr_pls_err_rpt_END (10)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_pon_mtcmos_rdy_overtime_intr_pls_err_rpt_START (11)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_pon_mtcmos_rdy_overtime_intr_pls_err_rpt_END (11)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_pon_qic_ack_overtime_intr_pls_err_rpt_START (12)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_pon_qic_ack_overtime_intr_pls_err_rpt_END (12)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_poff_mtcmos_rdy_overtime_intr_pls_err_rpt_START (13)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_poff_mtcmos_rdy_overtime_intr_pls_err_rpt_END (13)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_poff_qic_ack_overtime_intr_pls_err_rpt_START (14)
#define SOC_Hi9030_V200_AO_CRG_AO_PLS2LVL_RPT_poff_qic_ack_overtime_intr_pls_err_rpt_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_ip_rst_sel_bypass : 1;
        unsigned int cpu_hiphy_rst_grant_bypass : 1;
        unsigned int cpu_hiphy_axi_brg_gt_bypass : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_HIO_SELF_RESET_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_HIO_SELF_RESET_cpu_ip_rst_sel_bypass_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_HIO_SELF_RESET_cpu_ip_rst_sel_bypass_END (0)
#define SOC_Hi9030_V200_AO_CRG_AO_HIO_SELF_RESET_cpu_hiphy_rst_grant_bypass_START (1)
#define SOC_Hi9030_V200_AO_CRG_AO_HIO_SELF_RESET_cpu_hiphy_rst_grant_bypass_END (1)
#define SOC_Hi9030_V200_AO_CRG_AO_HIO_SELF_RESET_cpu_hiphy_axi_brg_gt_bypass_START (2)
#define SOC_Hi9030_V200_AO_CRG_AO_HIO_SELF_RESET_cpu_hiphy_axi_brg_gt_bypass_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ioc_clkrst_bypass : 1;
        unsigned int adc_clkrst_bypass : 1;
        unsigned int efuse_clkrst_bypass : 1;
        unsigned int hisimc0_clkrst_bypass : 1;
        unsigned int hisimc1_clkrst_bypass : 1;
        unsigned int i2c0_clkrst_bypass : 1;
        unsigned int i2c1_clkrst_bypass : 1;
        unsigned int i2c3_clkrst_bypass : 1;
        unsigned int i2c5_clkrst_bypass : 1;
        unsigned int i3c1_clkrst_bypass : 1;
        unsigned int gpio0_clkrst_bypass : 1;
        unsigned int gpio1_clkrst_bypass : 1;
        unsigned int gpio2_clkrst_bypass : 1;
        unsigned int gpio3_clkrst_bypass : 1;
        unsigned int gpio4_clkrst_bypass : 1;
        unsigned int hio_clkrst_bypass : 1;
        unsigned int cfg_clkrst_bypass : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_ioc_clkrst_bypass_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_ioc_clkrst_bypass_END (0)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_adc_clkrst_bypass_START (1)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_adc_clkrst_bypass_END (1)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_efuse_clkrst_bypass_START (2)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_efuse_clkrst_bypass_END (2)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_hisimc0_clkrst_bypass_START (3)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_hisimc0_clkrst_bypass_END (3)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_hisimc1_clkrst_bypass_START (4)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_hisimc1_clkrst_bypass_END (4)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_i2c0_clkrst_bypass_START (5)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_i2c0_clkrst_bypass_END (5)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_i2c1_clkrst_bypass_START (6)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_i2c1_clkrst_bypass_END (6)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_i2c3_clkrst_bypass_START (7)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_i2c3_clkrst_bypass_END (7)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_i2c5_clkrst_bypass_START (8)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_i2c5_clkrst_bypass_END (8)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_i3c1_clkrst_bypass_START (9)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_i3c1_clkrst_bypass_END (9)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_gpio0_clkrst_bypass_START (10)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_gpio0_clkrst_bypass_END (10)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_gpio1_clkrst_bypass_START (11)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_gpio1_clkrst_bypass_END (11)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_gpio2_clkrst_bypass_START (12)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_gpio2_clkrst_bypass_END (12)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_gpio3_clkrst_bypass_START (13)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_gpio3_clkrst_bypass_END (13)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_gpio4_clkrst_bypass_START (14)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_gpio4_clkrst_bypass_END (14)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_hio_clkrst_bypass_START (15)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_hio_clkrst_bypass_END (15)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_cfg_clkrst_bypass_START (16)
#define SOC_Hi9030_V200_AO_CRG_AO_IPCLKRST_BYPASS0_cfg_clkrst_bypass_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_ulppll_sleep_en_uart_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_CTRL0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_CTRL0_cpu_ulppll_sleep_en_uart_sel_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_CTRL0_cpu_ulppll_sleep_en_uart_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_sleep_en_time_cnt_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_CTRL1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_CTRL1_cpu_sleep_en_time_cnt_en_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_CTRL1_cpu_sleep_en_time_cnt_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_sleep_en_time_cnt_max : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_CTRL2_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_CTRL2_cpu_sleep_en_time_cnt_max_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_CTRL2_cpu_sleep_en_time_cnt_max_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_wakeup_time_cnt_max : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_CTRL3_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_CTRL3_cpu_wakeup_time_cnt_max_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_CTRL3_cpu_wakeup_time_cnt_max_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_peri_on_source_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_PERI_ON_SOURCE_SEL_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_SOURCE_SEL_cpu_peri_on_source_sel_START (0)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_SOURCE_SEL_cpu_peri_on_source_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_hio_rst_release : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_HIO_RST_CTRL_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_HIO_RST_CTRL_cpu_hio_rst_release_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_HIO_RST_CTRL_cpu_hio_rst_release_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ona_clk_fnpll_in_sw : 1;
        unsigned int onb_clk_fnpll_in_sw : 1;
        unsigned int ona_clk_out1_sw : 1;
        unsigned int onb_clk_out1_sw : 1;
        unsigned int onc_clk_out1_sw : 1;
        unsigned int ona_clk_ulppll_fsm_sw : 1;
        unsigned int onb_clk_ulppll_fsm_sw : 1;
        unsigned int ona_clk_i3c_slv_sw : 1;
        unsigned int onb_clk_i3c_slv_sw : 1;
        unsigned int ona_ao_cam_ref_clk0_sw : 1;
        unsigned int onb_ao_cam_ref_clk0_sw : 1;
        unsigned int onc_ao_cam_ref_clk0_sw : 1;
        unsigned int ona_ao_cam_ref_clk1_sw : 1;
        unsigned int onb_ao_cam_ref_clk1_sw : 1;
        unsigned int onc_ao_cam_ref_clk1_sw : 1;
        unsigned int ona_clk_out0_sw : 1;
        unsigned int onb_clk_out0_sw : 1;
        unsigned int ona_ulppll0_sw : 1;
        unsigned int onb_ulppll0_sw : 1;
        unsigned int ona_ulppll1_sw : 1;
        unsigned int onb_ulppll1_sw : 1;
        unsigned int ona_clk_hio_ulp_sw : 1;
        unsigned int onb_clk_hio_ulp_sw : 1;
        unsigned int ona_hisimc_clk_sw : 1;
        unsigned int onb_hisimc_clk_sw : 1;
        unsigned int ona_pclk_aobus_sw : 1;
        unsigned int onb_pclk_aobus_sw : 1;
        unsigned int ona_clk_i2s_sw : 1;
        unsigned int onb_clk_i2s_sw : 1;
        unsigned int reserved : 3;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_ona_clk_fnpll_in_sw_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_ona_clk_fnpll_in_sw_END (0)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onb_clk_fnpll_in_sw_START (1)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onb_clk_fnpll_in_sw_END (1)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_ona_clk_out1_sw_START (2)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_ona_clk_out1_sw_END (2)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onb_clk_out1_sw_START (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onb_clk_out1_sw_END (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onc_clk_out1_sw_START (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onc_clk_out1_sw_END (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_ona_clk_ulppll_fsm_sw_START (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_ona_clk_ulppll_fsm_sw_END (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onb_clk_ulppll_fsm_sw_START (6)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onb_clk_ulppll_fsm_sw_END (6)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_ona_clk_i3c_slv_sw_START (7)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_ona_clk_i3c_slv_sw_END (7)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onb_clk_i3c_slv_sw_START (8)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onb_clk_i3c_slv_sw_END (8)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_ona_ao_cam_ref_clk0_sw_START (9)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_ona_ao_cam_ref_clk0_sw_END (9)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onb_ao_cam_ref_clk0_sw_START (10)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onb_ao_cam_ref_clk0_sw_END (10)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onc_ao_cam_ref_clk0_sw_START (11)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onc_ao_cam_ref_clk0_sw_END (11)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_ona_ao_cam_ref_clk1_sw_START (12)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_ona_ao_cam_ref_clk1_sw_END (12)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onb_ao_cam_ref_clk1_sw_START (13)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onb_ao_cam_ref_clk1_sw_END (13)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onc_ao_cam_ref_clk1_sw_START (14)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onc_ao_cam_ref_clk1_sw_END (14)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_ona_clk_out0_sw_START (15)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_ona_clk_out0_sw_END (15)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onb_clk_out0_sw_START (16)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onb_clk_out0_sw_END (16)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_ona_ulppll0_sw_START (17)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_ona_ulppll0_sw_END (17)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onb_ulppll0_sw_START (18)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onb_ulppll0_sw_END (18)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_ona_ulppll1_sw_START (19)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_ona_ulppll1_sw_END (19)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onb_ulppll1_sw_START (20)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onb_ulppll1_sw_END (20)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_ona_clk_hio_ulp_sw_START (21)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_ona_clk_hio_ulp_sw_END (21)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onb_clk_hio_ulp_sw_START (22)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onb_clk_hio_ulp_sw_END (22)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_ona_hisimc_clk_sw_START (23)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_ona_hisimc_clk_sw_END (23)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onb_hisimc_clk_sw_START (24)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onb_hisimc_clk_sw_END (24)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_ona_pclk_aobus_sw_START (25)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_ona_pclk_aobus_sw_END (25)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onb_pclk_aobus_sw_START (26)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onb_pclk_aobus_sw_END (26)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_ona_clk_i2s_sw_START (27)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_ona_clk_i2s_sw_END (27)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onb_clk_i2s_sw_START (28)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTATE0_onb_clk_i2s_sw_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_ulppll_fsm_pre_div_sw0_bypass : 1;
        unsigned int gt_clk_ulppll_fsm_pre_div_sw1_bypass : 1;
        unsigned int gt_clk_pad_pre_div0_bypass : 1;
        unsigned int gt_clk_pad_pre_div1_bypass : 1;
        unsigned int gt_clk_hisimc_pre_div_sw0_bypass : 1;
        unsigned int gt_clk_hisimc_pre_div_sw1_bypass : 1;
        unsigned int gt_clk_vsensor_pre_div_bypass : 1;
        unsigned int gt_clk_i2s_pre_sw0_bypass : 1;
        unsigned int gt_clk_i2s_pre_sw1_bypass : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_LOW_POWER_GT_BY0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_LOW_POWER_GT_BY0_gt_clk_ulppll_fsm_pre_div_sw0_bypass_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_LOW_POWER_GT_BY0_gt_clk_ulppll_fsm_pre_div_sw0_bypass_END (0)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_LOW_POWER_GT_BY0_gt_clk_ulppll_fsm_pre_div_sw1_bypass_START (1)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_LOW_POWER_GT_BY0_gt_clk_ulppll_fsm_pre_div_sw1_bypass_END (1)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_LOW_POWER_GT_BY0_gt_clk_pad_pre_div0_bypass_START (2)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_LOW_POWER_GT_BY0_gt_clk_pad_pre_div0_bypass_END (2)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_LOW_POWER_GT_BY0_gt_clk_pad_pre_div1_bypass_START (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_LOW_POWER_GT_BY0_gt_clk_pad_pre_div1_bypass_END (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_LOW_POWER_GT_BY0_gt_clk_hisimc_pre_div_sw0_bypass_START (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_LOW_POWER_GT_BY0_gt_clk_hisimc_pre_div_sw0_bypass_END (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_LOW_POWER_GT_BY0_gt_clk_hisimc_pre_div_sw1_bypass_START (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_LOW_POWER_GT_BY0_gt_clk_hisimc_pre_div_sw1_bypass_END (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_LOW_POWER_GT_BY0_gt_clk_vsensor_pre_div_bypass_START (6)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_LOW_POWER_GT_BY0_gt_clk_vsensor_pre_div_bypass_END (6)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_LOW_POWER_GT_BY0_gt_clk_i2s_pre_sw0_bypass_START (7)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_LOW_POWER_GT_BY0_gt_clk_i2s_pre_sw0_bypass_END (7)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_LOW_POWER_GT_BY0_gt_clk_i2s_pre_sw1_bypass_START (8)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_LOW_POWER_GT_BY0_gt_clk_i2s_pre_sw1_bypass_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_qic_bus_div_lock_cnt_max : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_AUTO_DE_FREQ_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_AUTO_DE_FREQ_cpu_qic_bus_div_lock_cnt_max_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_AUTO_DE_FREQ_cpu_qic_bus_div_lock_cnt_max_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int gt_hisimc0_clk_en : 1;
        unsigned int gt_hisimc1_clk_en : 1;
        unsigned int reserved_1 : 2;
        unsigned int gt_ao_ic_clk_i2c_0_en : 1;
        unsigned int gt_ao_ic_clk_i2c_1_en : 1;
        unsigned int gt_ao_ic_clk_i2c_3_en : 1;
        unsigned int gt_ao_ic_clk_i2c_5_en : 1;
        unsigned int gt_ao_ic_clk_i3c_en : 1;
        unsigned int reserved_2 : 5;
        unsigned int gt_pclk_gpio_4_en : 1;
        unsigned int gt_pclk_hisimc0_en : 1;
        unsigned int gt_pclk_hisimc1_en : 1;
        unsigned int reserved_3 : 4;
        unsigned int gt_clk_i2s0_en : 1;
        unsigned int gt_clk_i2s1_en : 1;
        unsigned int reserved_4 : 5;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN2_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN2_gt_hisimc0_clk_en_START (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN2_gt_hisimc0_clk_en_END (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN2_gt_hisimc1_clk_en_START (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN2_gt_hisimc1_clk_en_END (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN2_gt_ao_ic_clk_i2c_0_en_START (8)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN2_gt_ao_ic_clk_i2c_0_en_END (8)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN2_gt_ao_ic_clk_i2c_1_en_START (9)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN2_gt_ao_ic_clk_i2c_1_en_END (9)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN2_gt_ao_ic_clk_i2c_3_en_START (10)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN2_gt_ao_ic_clk_i2c_3_en_END (10)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN2_gt_ao_ic_clk_i2c_5_en_START (11)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN2_gt_ao_ic_clk_i2c_5_en_END (11)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN2_gt_ao_ic_clk_i3c_en_START (12)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN2_gt_ao_ic_clk_i3c_en_END (12)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN2_gt_pclk_gpio_4_en_START (18)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN2_gt_pclk_gpio_4_en_END (18)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN2_gt_pclk_hisimc0_en_START (19)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN2_gt_pclk_hisimc0_en_END (19)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN2_gt_pclk_hisimc1_en_START (20)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN2_gt_pclk_hisimc1_en_END (20)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN2_gt_clk_i2s0_en_START (25)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN2_gt_clk_i2s0_en_END (25)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN2_gt_clk_i2s1_en_START (26)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN2_gt_clk_i2s1_en_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int gt_hisimc0_clk_dis : 1;
        unsigned int gt_hisimc1_clk_dis : 1;
        unsigned int reserved_1 : 2;
        unsigned int gt_ao_ic_clk_i2c_0_dis : 1;
        unsigned int gt_ao_ic_clk_i2c_1_dis : 1;
        unsigned int gt_ao_ic_clk_i2c_3_dis : 1;
        unsigned int gt_ao_ic_clk_i2c_5_dis : 1;
        unsigned int gt_ao_ic_clk_i3c_dis : 1;
        unsigned int reserved_2 : 5;
        unsigned int gt_pclk_gpio_4_dis : 1;
        unsigned int gt_pclk_hisimc0_dis : 1;
        unsigned int gt_pclk_hisimc1_dis : 1;
        unsigned int reserved_3 : 4;
        unsigned int gt_clk_i2s0_dis : 1;
        unsigned int gt_clk_i2s1_dis : 1;
        unsigned int reserved_4 : 5;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS2_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS2_gt_hisimc0_clk_dis_START (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS2_gt_hisimc0_clk_dis_END (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS2_gt_hisimc1_clk_dis_START (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS2_gt_hisimc1_clk_dis_END (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS2_gt_ao_ic_clk_i2c_0_dis_START (8)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS2_gt_ao_ic_clk_i2c_0_dis_END (8)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS2_gt_ao_ic_clk_i2c_1_dis_START (9)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS2_gt_ao_ic_clk_i2c_1_dis_END (9)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS2_gt_ao_ic_clk_i2c_3_dis_START (10)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS2_gt_ao_ic_clk_i2c_3_dis_END (10)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS2_gt_ao_ic_clk_i2c_5_dis_START (11)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS2_gt_ao_ic_clk_i2c_5_dis_END (11)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS2_gt_ao_ic_clk_i3c_dis_START (12)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS2_gt_ao_ic_clk_i3c_dis_END (12)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS2_gt_pclk_gpio_4_dis_START (18)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS2_gt_pclk_gpio_4_dis_END (18)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS2_gt_pclk_hisimc0_dis_START (19)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS2_gt_pclk_hisimc0_dis_END (19)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS2_gt_pclk_hisimc1_dis_START (20)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS2_gt_pclk_hisimc1_dis_END (20)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS2_gt_clk_i2s0_dis_START (25)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS2_gt_clk_i2s0_dis_END (25)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS2_gt_clk_i2s1_dis_START (26)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS2_gt_clk_i2s1_dis_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int gt_hisimc0_clk_sta : 1;
        unsigned int gt_hisimc1_clk_sta : 1;
        unsigned int reserved_1 : 2;
        unsigned int gt_ao_ic_clk_i2c_0_sta : 1;
        unsigned int gt_ao_ic_clk_i2c_1_sta : 1;
        unsigned int gt_ao_ic_clk_i2c_3_sta : 1;
        unsigned int gt_ao_ic_clk_i2c_5_sta : 1;
        unsigned int gt_ao_ic_clk_i3c_sta : 1;
        unsigned int reserved_2 : 5;
        unsigned int gt_pclk_gpio_4_sta : 1;
        unsigned int gt_pclk_hisimc0_sta : 1;
        unsigned int gt_pclk_hisimc1_sta : 1;
        unsigned int reserved_3 : 4;
        unsigned int gt_clk_i2s0_sta : 1;
        unsigned int gt_clk_i2s1_sta : 1;
        unsigned int reserved_4 : 5;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA2_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA2_gt_hisimc0_clk_sta_START (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA2_gt_hisimc0_clk_sta_END (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA2_gt_hisimc1_clk_sta_START (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA2_gt_hisimc1_clk_sta_END (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA2_gt_ao_ic_clk_i2c_0_sta_START (8)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA2_gt_ao_ic_clk_i2c_0_sta_END (8)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA2_gt_ao_ic_clk_i2c_1_sta_START (9)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA2_gt_ao_ic_clk_i2c_1_sta_END (9)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA2_gt_ao_ic_clk_i2c_3_sta_START (10)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA2_gt_ao_ic_clk_i2c_3_sta_END (10)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA2_gt_ao_ic_clk_i2c_5_sta_START (11)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA2_gt_ao_ic_clk_i2c_5_sta_END (11)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA2_gt_ao_ic_clk_i3c_sta_START (12)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA2_gt_ao_ic_clk_i3c_sta_END (12)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA2_gt_pclk_gpio_4_sta_START (18)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA2_gt_pclk_gpio_4_sta_END (18)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA2_gt_pclk_hisimc0_sta_START (19)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA2_gt_pclk_hisimc0_sta_END (19)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA2_gt_pclk_hisimc1_sta_START (20)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA2_gt_pclk_hisimc1_sta_END (20)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA2_gt_clk_i2s0_sta_START (25)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA2_gt_clk_i2s0_sta_END (25)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA2_gt_clk_i2s1_sta_START (26)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA2_gt_clk_i2s1_sta_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 3;
        unsigned int cpu_hisimc0_rst_n_en : 1;
        unsigned int cpu_hisimc1_rst_n_en : 1;
        unsigned int cpu_rst_ao_i2c_0_n_en : 1;
        unsigned int cpu_rst_ao_i2c_1_n_en : 1;
        unsigned int cpu_rst_ao_i2c_3_n_en : 1;
        unsigned int cpu_rst_ao_i2c_5_n_en : 1;
        unsigned int cpu_rst_ao_i3c_n_en : 1;
        unsigned int reserved_1 : 3;
        unsigned int cpu_hisimc0_prst_n_en : 1;
        unsigned int cpu_hisimc1_prst_n_en : 1;
        unsigned int reserved_2 : 4;
        unsigned int cpu_preset_gpio_4_n_en : 1;
        unsigned int reserved_3 : 12;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN2_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN2_cpu_hisimc0_rst_n_en_START (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN2_cpu_hisimc0_rst_n_en_END (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN2_cpu_hisimc1_rst_n_en_START (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN2_cpu_hisimc1_rst_n_en_END (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN2_cpu_rst_ao_i2c_0_n_en_START (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN2_cpu_rst_ao_i2c_0_n_en_END (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN2_cpu_rst_ao_i2c_1_n_en_START (6)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN2_cpu_rst_ao_i2c_1_n_en_END (6)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN2_cpu_rst_ao_i2c_3_n_en_START (7)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN2_cpu_rst_ao_i2c_3_n_en_END (7)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN2_cpu_rst_ao_i2c_5_n_en_START (8)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN2_cpu_rst_ao_i2c_5_n_en_END (8)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN2_cpu_rst_ao_i3c_n_en_START (9)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN2_cpu_rst_ao_i3c_n_en_END (9)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN2_cpu_hisimc0_prst_n_en_START (13)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN2_cpu_hisimc0_prst_n_en_END (13)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN2_cpu_hisimc1_prst_n_en_START (14)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN2_cpu_hisimc1_prst_n_en_END (14)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN2_cpu_preset_gpio_4_n_en_START (19)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN2_cpu_preset_gpio_4_n_en_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 3;
        unsigned int cpu_hisimc0_rst_n_dis : 1;
        unsigned int cpu_hisimc1_rst_n_dis : 1;
        unsigned int cpu_rst_ao_i2c_0_n_dis : 1;
        unsigned int cpu_rst_ao_i2c_1_n_dis : 1;
        unsigned int cpu_rst_ao_i2c_3_n_dis : 1;
        unsigned int cpu_rst_ao_i2c_5_n_dis : 1;
        unsigned int cpu_rst_ao_i3c_n_dis : 1;
        unsigned int reserved_1 : 3;
        unsigned int cpu_hisimc0_prst_n_dis : 1;
        unsigned int cpu_hisimc1_prst_n_dis : 1;
        unsigned int reserved_2 : 4;
        unsigned int cpu_preset_gpio_4_n_dis : 1;
        unsigned int reserved_3 : 12;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS2_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS2_cpu_hisimc0_rst_n_dis_START (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS2_cpu_hisimc0_rst_n_dis_END (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS2_cpu_hisimc1_rst_n_dis_START (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS2_cpu_hisimc1_rst_n_dis_END (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS2_cpu_rst_ao_i2c_0_n_dis_START (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS2_cpu_rst_ao_i2c_0_n_dis_END (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS2_cpu_rst_ao_i2c_1_n_dis_START (6)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS2_cpu_rst_ao_i2c_1_n_dis_END (6)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS2_cpu_rst_ao_i2c_3_n_dis_START (7)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS2_cpu_rst_ao_i2c_3_n_dis_END (7)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS2_cpu_rst_ao_i2c_5_n_dis_START (8)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS2_cpu_rst_ao_i2c_5_n_dis_END (8)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS2_cpu_rst_ao_i3c_n_dis_START (9)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS2_cpu_rst_ao_i3c_n_dis_END (9)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS2_cpu_hisimc0_prst_n_dis_START (13)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS2_cpu_hisimc0_prst_n_dis_END (13)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS2_cpu_hisimc1_prst_n_dis_START (14)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS2_cpu_hisimc1_prst_n_dis_END (14)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS2_cpu_preset_gpio_4_n_dis_START (19)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS2_cpu_preset_gpio_4_n_dis_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 3;
        unsigned int cpu_hisimc0_rst_n_sta : 1;
        unsigned int cpu_hisimc1_rst_n_sta : 1;
        unsigned int cpu_rst_ao_i2c_0_n_sta : 1;
        unsigned int cpu_rst_ao_i2c_1_n_sta : 1;
        unsigned int cpu_rst_ao_i2c_3_n_sta : 1;
        unsigned int cpu_rst_ao_i2c_5_n_sta : 1;
        unsigned int cpu_rst_ao_i3c_n_sta : 1;
        unsigned int reserved_1 : 3;
        unsigned int cpu_hisimc0_prst_n_sta : 1;
        unsigned int cpu_hisimc1_prst_n_sta : 1;
        unsigned int reserved_2 : 4;
        unsigned int cpu_preset_gpio_4_n_sta : 1;
        unsigned int reserved_3 : 12;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT2_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT2_cpu_hisimc0_rst_n_sta_START (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT2_cpu_hisimc0_rst_n_sta_END (3)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT2_cpu_hisimc1_rst_n_sta_START (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT2_cpu_hisimc1_rst_n_sta_END (4)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT2_cpu_rst_ao_i2c_0_n_sta_START (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT2_cpu_rst_ao_i2c_0_n_sta_END (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT2_cpu_rst_ao_i2c_1_n_sta_START (6)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT2_cpu_rst_ao_i2c_1_n_sta_END (6)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT2_cpu_rst_ao_i2c_3_n_sta_START (7)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT2_cpu_rst_ao_i2c_3_n_sta_END (7)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT2_cpu_rst_ao_i2c_5_n_sta_START (8)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT2_cpu_rst_ao_i2c_5_n_sta_END (8)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT2_cpu_rst_ao_i3c_n_sta_START (9)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT2_cpu_rst_ao_i3c_n_sta_END (9)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT2_cpu_hisimc0_prst_n_sta_START (13)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT2_cpu_hisimc0_prst_n_sta_END (13)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT2_cpu_hisimc1_prst_n_sta_START (14)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT2_cpu_hisimc1_prst_n_sta_END (14)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT2_cpu_preset_gpio_4_n_sta_START (19)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT2_cpu_preset_gpio_4_n_sta_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_uart_sleep_vote0 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL0_ulppll_uart_sleep_vote0_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL0_ulppll_uart_sleep_vote0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_uart_sleep_vote1 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL1_ulppll_uart_sleep_vote1_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL1_ulppll_uart_sleep_vote1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_uart_sleep_vote2 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL2_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL2_ulppll_uart_sleep_vote2_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL2_ulppll_uart_sleep_vote2_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_uart_sleep_vote3 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL3_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL3_ulppll_uart_sleep_vote3_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL3_ulppll_uart_sleep_vote3_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_div_clk_i2s0 : 6;
        unsigned int cpu_div_clk_i2s1 : 6;
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_BUSINESS_SAFE_CLKDIV0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_BUSINESS_SAFE_CLKDIV0_cpu_div_clk_i2s0_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_BUSINESS_SAFE_CLKDIV0_cpu_div_clk_i2s0_END (5)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_BUSINESS_SAFE_CLKDIV0_cpu_div_clk_i2s1_START (6)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_BUSINESS_SAFE_CLKDIV0_cpu_div_clk_i2s1_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 6;
        unsigned int cpu_div_clk_i2s_aft_sw : 6;
        unsigned int reserved_1 : 4;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_BUSINESS_SAFE_CLKDIV1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_BUSINESS_SAFE_CLKDIV1_cpu_div_clk_i2s_aft_sw_START (6)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_BUSINESS_SAFE_CLKDIV1_cpu_div_clk_i2s_aft_sw_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int cpu_sel_clk_i2s : 1;
        unsigned int reserved_1 : 30;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_BUSINESS_SAFE_CLKSEL0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_BUSINESS_SAFE_CLKSEL0_cpu_sel_clk_i2s_START (1)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_BUSINESS_SAFE_CLKSEL0_cpu_sel_clk_i2s_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 14;
        unsigned int gt_pclk_gpio_0_en : 1;
        unsigned int gt_pclk_gpio_1_en : 1;
        unsigned int gt_pclk_gpio_2_en : 1;
        unsigned int gt_pclk_gpio_3_en : 1;
        unsigned int reserved_1 : 6;
        unsigned int gt_clk_vsensor_en : 1;
        unsigned int gt_ao_clk_voice_debc_en : 1;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN3_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN3_gt_pclk_gpio_0_en_START (14)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN3_gt_pclk_gpio_0_en_END (14)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN3_gt_pclk_gpio_1_en_START (15)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN3_gt_pclk_gpio_1_en_END (15)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN3_gt_pclk_gpio_2_en_START (16)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN3_gt_pclk_gpio_2_en_END (16)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN3_gt_pclk_gpio_3_en_START (17)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN3_gt_pclk_gpio_3_en_END (17)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN3_gt_clk_vsensor_en_START (24)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN3_gt_clk_vsensor_en_END (24)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN3_gt_ao_clk_voice_debc_en_START (25)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKEN3_gt_ao_clk_voice_debc_en_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 14;
        unsigned int gt_pclk_gpio_0_dis : 1;
        unsigned int gt_pclk_gpio_1_dis : 1;
        unsigned int gt_pclk_gpio_2_dis : 1;
        unsigned int gt_pclk_gpio_3_dis : 1;
        unsigned int reserved_1 : 6;
        unsigned int gt_clk_vsensor_dis : 1;
        unsigned int gt_ao_clk_voice_debc_dis : 1;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS3_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS3_gt_pclk_gpio_0_dis_START (14)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS3_gt_pclk_gpio_0_dis_END (14)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS3_gt_pclk_gpio_1_dis_START (15)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS3_gt_pclk_gpio_1_dis_END (15)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS3_gt_pclk_gpio_2_dis_START (16)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS3_gt_pclk_gpio_2_dis_END (16)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS3_gt_pclk_gpio_3_dis_START (17)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS3_gt_pclk_gpio_3_dis_END (17)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS3_gt_clk_vsensor_dis_START (24)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS3_gt_clk_vsensor_dis_END (24)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS3_gt_ao_clk_voice_debc_dis_START (25)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKDIS3_gt_ao_clk_voice_debc_dis_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 14;
        unsigned int gt_pclk_gpio_0_sta : 1;
        unsigned int gt_pclk_gpio_1_sta : 1;
        unsigned int gt_pclk_gpio_2_sta : 1;
        unsigned int gt_pclk_gpio_3_sta : 1;
        unsigned int reserved_1 : 6;
        unsigned int gt_clk_vsensor_sta : 1;
        unsigned int gt_ao_clk_voice_debc_sta : 1;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA3_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA3_gt_pclk_gpio_0_sta_START (14)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA3_gt_pclk_gpio_0_sta_END (14)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA3_gt_pclk_gpio_1_sta_START (15)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA3_gt_pclk_gpio_1_sta_END (15)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA3_gt_pclk_gpio_2_sta_START (16)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA3_gt_pclk_gpio_2_sta_END (16)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA3_gt_pclk_gpio_3_sta_START (17)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA3_gt_pclk_gpio_3_sta_END (17)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA3_gt_clk_vsensor_sta_START (24)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA3_gt_clk_vsensor_sta_END (24)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA3_gt_ao_clk_voice_debc_sta_START (25)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_CLKSTA3_gt_ao_clk_voice_debc_sta_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 11;
        unsigned int cpu_reset_vsensor_n_en : 1;
        unsigned int reserved_1 : 3;
        unsigned int cpu_preset_gpio_0_n_en : 1;
        unsigned int cpu_preset_gpio_1_n_en : 1;
        unsigned int cpu_preset_gpio_2_n_en : 1;
        unsigned int cpu_preset_gpio_3_n_en : 1;
        unsigned int cpu_reset_voice_debc_n_en : 1;
        unsigned int reserved_2 : 12;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN3_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN3_cpu_reset_vsensor_n_en_START (11)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN3_cpu_reset_vsensor_n_en_END (11)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN3_cpu_preset_gpio_0_n_en_START (15)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN3_cpu_preset_gpio_0_n_en_END (15)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN3_cpu_preset_gpio_1_n_en_START (16)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN3_cpu_preset_gpio_1_n_en_END (16)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN3_cpu_preset_gpio_2_n_en_START (17)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN3_cpu_preset_gpio_2_n_en_END (17)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN3_cpu_preset_gpio_3_n_en_START (18)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN3_cpu_preset_gpio_3_n_en_END (18)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN3_cpu_reset_voice_debc_n_en_START (19)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTEN3_cpu_reset_voice_debc_n_en_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 11;
        unsigned int cpu_reset_vsensor_n_dis : 1;
        unsigned int reserved_1 : 3;
        unsigned int cpu_preset_gpio_0_n_dis : 1;
        unsigned int cpu_preset_gpio_1_n_dis : 1;
        unsigned int cpu_preset_gpio_2_n_dis : 1;
        unsigned int cpu_preset_gpio_3_n_dis : 1;
        unsigned int cpu_reset_voice_debc_n_dis : 1;
        unsigned int reserved_2 : 12;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS3_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS3_cpu_reset_vsensor_n_dis_START (11)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS3_cpu_reset_vsensor_n_dis_END (11)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS3_cpu_preset_gpio_0_n_dis_START (15)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS3_cpu_preset_gpio_0_n_dis_END (15)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS3_cpu_preset_gpio_1_n_dis_START (16)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS3_cpu_preset_gpio_1_n_dis_END (16)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS3_cpu_preset_gpio_2_n_dis_START (17)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS3_cpu_preset_gpio_2_n_dis_END (17)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS3_cpu_preset_gpio_3_n_dis_START (18)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS3_cpu_preset_gpio_3_n_dis_END (18)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS3_cpu_reset_voice_debc_n_dis_START (19)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTDIS3_cpu_reset_voice_debc_n_dis_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 11;
        unsigned int cpu_reset_vsensor_n_sta : 1;
        unsigned int reserved_1 : 3;
        unsigned int cpu_preset_gpio_0_n_sta : 1;
        unsigned int cpu_preset_gpio_1_n_sta : 1;
        unsigned int cpu_preset_gpio_2_n_sta : 1;
        unsigned int cpu_preset_gpio_3_n_sta : 1;
        unsigned int cpu_reset_voice_debc_n_sta : 1;
        unsigned int reserved_2 : 12;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT3_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT3_cpu_reset_vsensor_n_sta_START (11)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT3_cpu_reset_vsensor_n_sta_END (11)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT3_cpu_preset_gpio_0_n_sta_START (15)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT3_cpu_preset_gpio_0_n_sta_END (15)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT3_cpu_preset_gpio_1_n_sta_START (16)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT3_cpu_preset_gpio_1_n_sta_END (16)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT3_cpu_preset_gpio_2_n_sta_START (17)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT3_cpu_preset_gpio_2_n_sta_END (17)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT3_cpu_preset_gpio_3_n_sta_START (18)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT3_cpu_preset_gpio_3_n_sta_END (18)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT3_cpu_reset_voice_debc_n_sta_START (19)
#define SOC_Hi9030_V200_AO_CRG_AO_CRG_RSTSTAT3_cpu_reset_voice_debc_n_sta_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_uart_sleep_vote4 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL4_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL4_ulppll_uart_sleep_vote4_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL4_ulppll_uart_sleep_vote4_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_uart_sleep_vote5 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL5_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL5_ulppll_uart_sleep_vote5_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL5_ulppll_uart_sleep_vote5_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_uart_sleep_vote6 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL6_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL6_ulppll_uart_sleep_vote6_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL6_ulppll_uart_sleep_vote6_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ulppll_uart_sleep_vote7 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL7_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL7_ulppll_uart_sleep_vote7_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_ULPPLL_UART_SLEEP_VOTE_CTRL7_ulppll_uart_sleep_vote7_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_peri_on_vote0 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL0_cpu_peri_on_vote0_START (0)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL0_cpu_peri_on_vote0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_peri_on_vote1 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL1_cpu_peri_on_vote1_START (0)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL1_cpu_peri_on_vote1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_peri_on_vote2 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL2_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL2_cpu_peri_on_vote2_START (0)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL2_cpu_peri_on_vote2_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_peri_on_vote3 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL3_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL3_cpu_peri_on_vote3_START (0)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL3_cpu_peri_on_vote3_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_peri_on_vote4 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL4_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL4_cpu_peri_on_vote4_START (0)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL4_cpu_peri_on_vote4_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_peri_on_vote5 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL5_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL5_cpu_peri_on_vote5_START (0)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL5_cpu_peri_on_vote5_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_peri_on_vote6 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL6_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL6_cpu_peri_on_vote6_START (0)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL6_cpu_peri_on_vote6_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_peri_on_vote7 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL7_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL7_cpu_peri_on_vote7_START (0)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL7_cpu_peri_on_vote7_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_peri_on_vote8 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL8_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL8_cpu_peri_on_vote8_START (0)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL8_cpu_peri_on_vote8_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_peri_on_vote9 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL9_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL9_cpu_peri_on_vote9_START (0)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL9_cpu_peri_on_vote9_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_peri_on_vote10 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL10_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL10_cpu_peri_on_vote10_START (0)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL10_cpu_peri_on_vote10_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_peri_on_vote11 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTR11_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTR11_cpu_peri_on_vote11_START (0)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTR11_cpu_peri_on_vote11_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_peri_on_vote12 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL12_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL12_cpu_peri_on_vote12_START (0)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL12_cpu_peri_on_vote12_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_peri_on_vote13 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL13_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL13_cpu_peri_on_vote13_START (0)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL13_cpu_peri_on_vote13_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_peri_on_vote14 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL14_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL14_cpu_peri_on_vote14_START (0)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL14_cpu_peri_on_vote14_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_peri_on_vote15 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL15_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL15_cpu_peri_on_vote15_START (0)
#define SOC_Hi9030_V200_AO_CRG_PERI_ON_VOTE_CTRL15_cpu_peri_on_vote15_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_ram_sd_ctrl_sel : 6;
        unsigned int cpu_ram_sd_pls : 6;
        unsigned int reserved : 20;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_RAM_SD_CTRL0_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_RAM_SD_CTRL0_cpu_ram_sd_ctrl_sel_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_RAM_SD_CTRL0_cpu_ram_sd_ctrl_sel_END (5)
#define SOC_Hi9030_V200_AO_CRG_AO_RAM_SD_CTRL0_cpu_ram_sd_pls_START (6)
#define SOC_Hi9030_V200_AO_CRG_AO_RAM_SD_CTRL0_cpu_ram_sd_pls_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tp_mem_ctrl_sd_dma0 : 1;
        unsigned int tp_mem_ctrl_sd_qspi : 1;
        unsigned int sp_mem_ctrl_sd_afdft : 4;
        unsigned int reserved : 26;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_RAM_SD_CTRL1_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_RAM_SD_CTRL1_tp_mem_ctrl_sd_dma0_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_RAM_SD_CTRL1_tp_mem_ctrl_sd_dma0_END (0)
#define SOC_Hi9030_V200_AO_CRG_AO_RAM_SD_CTRL1_tp_mem_ctrl_sd_qspi_START (1)
#define SOC_Hi9030_V200_AO_CRG_AO_RAM_SD_CTRL1_tp_mem_ctrl_sd_qspi_END (1)
#define SOC_Hi9030_V200_AO_CRG_AO_RAM_SD_CTRL1_sp_mem_ctrl_sd_afdft_START (2)
#define SOC_Hi9030_V200_AO_CRG_AO_RAM_SD_CTRL1_sp_mem_ctrl_sd_afdft_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_ram_sd_en_peri_sel : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_Hi9030_V200_AO_CRG_AO_RAM_SD_CTRL2_UNION;
#endif
#define SOC_Hi9030_V200_AO_CRG_AO_RAM_SD_CTRL2_cpu_ram_sd_en_peri_sel_START (0)
#define SOC_Hi9030_V200_AO_CRG_AO_RAM_SD_CTRL2_cpu_ram_sd_en_peri_sel_END (5)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
