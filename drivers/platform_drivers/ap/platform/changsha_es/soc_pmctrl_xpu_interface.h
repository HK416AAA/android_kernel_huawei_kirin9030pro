#ifndef __SOC_PMCTRL_XPU_INTERFACE_H__
#define __SOC_PMCTRL_XPU_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_ADDR(base) ((base) + (0x500UL))
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_0_ADDR(base) ((base) + (0x504UL))
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_1_ADDR(base) ((base) + (0x508UL))
#define SOC_PMCTRL_XPU_VOTE_START_EN_ADDR(base) ((base) + (0x50CUL))
#define SOC_PMCTRL_XPU_INT_VOTE_EN_ADDR(base) ((base) + (0x510UL))
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_ADDR(base) ((base) + (0x514UL))
#define SOC_PMCTRL_XPU_VOTE_POWER_EN_ADDR(base) ((base) + (0x600UL))
#define SOC_PMCTRL_XPU_VOTE_POWER_DIS_ADDR(base) ((base) + (0x604UL))
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_ADDR(base) ((base) + (0x608UL))
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_STAT_ADDR(base) ((base) + (0x60CUL))
#define SOC_PMCTRL_XPU_PWRSTAT_SW2ON_REQ_ADDR(base) ((base) + (0x610UL))
#define SOC_PMCTRL_XPU_PWRSTAT_SW2OFF_REQ_ADDR(base) ((base) + (0x614UL))
#define SOC_PMCTRL_XPU_VOTE_POWER_ONOFF_EN_ADDR(base) ((base) + (0x618UL))
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_ADDR(base) ((base) + (0x61CUL))
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_ADDR(base) ((base) + (0x620UL))
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_RAW_ADDR(base) ((base) + (0x624UL))
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_RAW_ADDR(base) ((base) + (0x628UL))
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_CLR_ADDR(base) ((base) + (0x62CUL))
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_CLR_ADDR(base) ((base) + (0x630UL))
#define SOC_PMCTRL_XPU_CURR_VOTE_POWER_STAT_ADDR(base) ((base) + (0x634UL))
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ONOFF_MASK_ADDR(base) ((base) + (0x638UL))
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ONOFF_ADDR(base) ((base) + (0x63CUL))
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_ADDR(base) ((base) + (0x664UL))
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_ADDR(base) ((base) + (0x668UL))
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_ADDR(base) ((base) + (0x66CUL))
#define SOC_PMCTRL_XPU_SPMI_HOLD_TIME_ADDR(base) ((base) + (0x700UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_A0_ADDR(base) ((base) + (0x000UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_A1_ADDR(base) ((base) + (0x004UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_B0_ADDR(base) ((base) + (0x008UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_B1_ADDR(base) ((base) + (0x00CUL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_C0_ADDR(base) ((base) + (0x010UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_C1_ADDR(base) ((base) + (0x014UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_D0_ADDR(base) ((base) + (0x018UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_D1_ADDR(base) ((base) + (0x01CUL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_E0_ADDR(base) ((base) + (0x020UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_E1_ADDR(base) ((base) + (0x024UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_E2_ADDR(base) ((base) + (0x028UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_E3_ADDR(base) ((base) + (0x02CUL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_F0_ADDR(base) ((base) + (0x030UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_F1_ADDR(base) ((base) + (0x034UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_F2_ADDR(base) ((base) + (0x038UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_F3_ADDR(base) ((base) + (0x03CUL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_G0_ADDR(base) ((base) + (0x040UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_G1_ADDR(base) ((base) + (0x044UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_G2_ADDR(base) ((base) + (0x048UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_G3_ADDR(base) ((base) + (0x04CUL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_H0_ADDR(base) ((base) + (0x050UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_H1_ADDR(base) ((base) + (0x054UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_H2_ADDR(base) ((base) + (0x058UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_H3_ADDR(base) ((base) + (0x05CUL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_I0_ADDR(base) ((base) + (0x060UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_I1_ADDR(base) ((base) + (0x064UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_J0_ADDR(base) ((base) + (0x068UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_J1_ADDR(base) ((base) + (0x06CUL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_K0_ADDR(base) ((base) + (0x070UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_K1_ADDR(base) ((base) + (0x074UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_L0_ADDR(base) ((base) + (0x078UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_L1_ADDR(base) ((base) + (0x07CUL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_M0_ADDR(base) ((base) + (0x080UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_M1_ADDR(base) ((base) + (0x084UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_M2_ADDR(base) ((base) + (0x088UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_M3_ADDR(base) ((base) + (0x08CUL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_N0_ADDR(base) ((base) + (0x090UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_N1_ADDR(base) ((base) + (0x094UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_N2_ADDR(base) ((base) + (0x098UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_N3_ADDR(base) ((base) + (0x09CUL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_O0_ADDR(base) ((base) + (0x0A0UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_O1_ADDR(base) ((base) + (0x0A4UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_O2_ADDR(base) ((base) + (0x0A8UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_O3_ADDR(base) ((base) + (0x0ACUL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_P0_ADDR(base) ((base) + (0x0B0UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_P1_ADDR(base) ((base) + (0x0B4UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_P2_ADDR(base) ((base) + (0x0B8UL))
#define SOC_PMCTRL_XPU_FREQ_VOTE_P3_ADDR(base) ((base) + (0x0BCUL))
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_ADDR(base) ((base) + (0x0D0UL))
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_ADDR(base) ((base) + (0x0D4UL))
#define SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_MASK_0_ADDR(base) ((base) + (0x200UL))
#define SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_MASK_1_ADDR(base) ((base) + (0x204UL))
#define SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_MASK_2_ADDR(base) ((base) + (0x208UL))
#define SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_ADDR(base) ((base) + (0x0D8UL))
#define SOC_PMCTRL_XPU_VOTE_RESULT_A_ADDR(base) ((base) + (0x0DCUL))
#define SOC_PMCTRL_XPU_VOTE_RESULT_B_ADDR(base) ((base) + (0x0E0UL))
#define SOC_PMCTRL_XPU_VOTE_RESULT_C_ADDR(base) ((base) + (0x0E4UL))
#define SOC_PMCTRL_XPU_VOTE_RESULT_D_ADDR(base) ((base) + (0x0E8UL))
#define SOC_PMCTRL_XPU_VOTE_RESULT_E_ADDR(base) ((base) + (0x0ECUL))
#define SOC_PMCTRL_XPU_VOTE_RESULT_F_ADDR(base) ((base) + (0x0F0UL))
#define SOC_PMCTRL_XPU_VOTE_RESULT_G_ADDR(base) ((base) + (0x0F4UL))
#define SOC_PMCTRL_XPU_VOTE_RESULT_H_ADDR(base) ((base) + (0x0F8UL))
#define SOC_PMCTRL_XPU_VOTE_RESULT_I_ADDR(base) ((base) + (0x0FCUL))
#define SOC_PMCTRL_XPU_VOTE_RESULT_J_ADDR(base) ((base) + (0x100UL))
#define SOC_PMCTRL_XPU_VOTE_RESULT_K_ADDR(base) ((base) + (0x104UL))
#define SOC_PMCTRL_XPU_VOTE_RESULT_L_ADDR(base) ((base) + (0x108UL))
#define SOC_PMCTRL_XPU_VOTE_RESULT_M_ADDR(base) ((base) + (0x10CUL))
#define SOC_PMCTRL_XPU_VOTE_RESULT_N_ADDR(base) ((base) + (0x110UL))
#define SOC_PMCTRL_XPU_VOTE_RESULT_O_ADDR(base) ((base) + (0x114UL))
#define SOC_PMCTRL_XPU_VOTE_RESULT_P_ADDR(base) ((base) + (0x118UL))
#define SOC_PMCTRL_XPU_DVFSDATA0_ADDR(base) ((base) + (0x120UL))
#define SOC_PMCTRL_XPU_DVFSDATA1_ADDR(base) ((base) + (0x124UL))
#define SOC_PMCTRL_XPU_DVFSDATA2_ADDR(base) ((base) + (0x128UL))
#define SOC_PMCTRL_XPU_DVFSDATA3_ADDR(base) ((base) + (0x12CUL))
#define SOC_PMCTRL_XPU_DVFSDATA4_ADDR(base) ((base) + (0x130UL))
#define SOC_PMCTRL_XPU_DVFSDATA5_ADDR(base) ((base) + (0x134UL))
#define SOC_PMCTRL_XPU_DVFSDATA6_ADDR(base) ((base) + (0x138UL))
#define SOC_PMCTRL_XPU_DVFSDATA7_ADDR(base) ((base) + (0x13CUL))
#define SOC_PMCTRL_XPU_DVFSDATA8_ADDR(base) ((base) + (0x140UL))
#define SOC_PMCTRL_XPU_DVFSDATA9_ADDR(base) ((base) + (0x144UL))
#define SOC_PMCTRL_XPU_DVFSDATA10_ADDR(base) ((base) + (0x148UL))
#define SOC_PMCTRL_XPU_DVFSDATA11_ADDR(base) ((base) + (0x14CUL))
#define SOC_PMCTRL_XPU_DVFSDATA12_ADDR(base) ((base) + (0x150UL))
#define SOC_PMCTRL_XPU_DVFSDATA13_ADDR(base) ((base) + (0x154UL))
#define SOC_PMCTRL_XPU_DVFSDATA14_ADDR(base) ((base) + (0x158UL))
#define SOC_PMCTRL_XPU_DVFSDATA15_ADDR(base) ((base) + (0x15CUL))
#define SOC_PMCTRL_XPU_DVFSDATA16_ADDR(base) ((base) + (0x160UL))
#define SOC_PMCTRL_XPU_DVFSDATA17_ADDR(base) ((base) + (0x164UL))
#define SOC_PMCTRL_XPU_DVFSDATA18_ADDR(base) ((base) + (0x168UL))
#define SOC_PMCTRL_XPU_DVFSDATA19_ADDR(base) ((base) + (0x16CUL))
#define SOC_PMCTRL_XPU_DVFSDATA20_ADDR(base) ((base) + (0x170UL))
#define SOC_PMCTRL_XPU_DVFSDATA21_ADDR(base) ((base) + (0x174UL))
#define SOC_PMCTRL_XPU_DVFSDATA22_ADDR(base) ((base) + (0x178UL))
#define SOC_PMCTRL_XPU_DVFSDATA23_ADDR(base) ((base) + (0x17CUL))
#define SOC_PMCTRL_XPU_DVFSDATA24_ADDR(base) ((base) + (0x180UL))
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED0_ADDR(base) ((base) + (0x184UL))
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED1_ADDR(base) ((base) + (0x188UL))
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED2_ADDR(base) ((base) + (0x18CUL))
#define SOC_PMCTRL_XPU_TEMPERATURE_VALID_STATUS0_ADDR(base) ((base) + (0x190UL))
#define SOC_PMCTRL_XPU_TEMPERATURE_VALID_STATUS1_ADDR(base) ((base) + (0x194UL))
#define SOC_PMCTRL_XPU_TEMPERATURE_VALID_STATUS2_ADDR(base) ((base) + (0x198UL))
#else
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_ADDR(base) ((base) + (0x500))
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_0_ADDR(base) ((base) + (0x504))
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_1_ADDR(base) ((base) + (0x508))
#define SOC_PMCTRL_XPU_VOTE_START_EN_ADDR(base) ((base) + (0x50C))
#define SOC_PMCTRL_XPU_INT_VOTE_EN_ADDR(base) ((base) + (0x510))
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_ADDR(base) ((base) + (0x514))
#define SOC_PMCTRL_XPU_VOTE_POWER_EN_ADDR(base) ((base) + (0x600))
#define SOC_PMCTRL_XPU_VOTE_POWER_DIS_ADDR(base) ((base) + (0x604))
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_ADDR(base) ((base) + (0x608))
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_STAT_ADDR(base) ((base) + (0x60C))
#define SOC_PMCTRL_XPU_PWRSTAT_SW2ON_REQ_ADDR(base) ((base) + (0x610))
#define SOC_PMCTRL_XPU_PWRSTAT_SW2OFF_REQ_ADDR(base) ((base) + (0x614))
#define SOC_PMCTRL_XPU_VOTE_POWER_ONOFF_EN_ADDR(base) ((base) + (0x618))
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_ADDR(base) ((base) + (0x61C))
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_ADDR(base) ((base) + (0x620))
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_RAW_ADDR(base) ((base) + (0x624))
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_RAW_ADDR(base) ((base) + (0x628))
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_CLR_ADDR(base) ((base) + (0x62C))
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_CLR_ADDR(base) ((base) + (0x630))
#define SOC_PMCTRL_XPU_CURR_VOTE_POWER_STAT_ADDR(base) ((base) + (0x634))
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ONOFF_MASK_ADDR(base) ((base) + (0x638))
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ONOFF_ADDR(base) ((base) + (0x63C))
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_ADDR(base) ((base) + (0x664))
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_ADDR(base) ((base) + (0x668))
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_ADDR(base) ((base) + (0x66C))
#define SOC_PMCTRL_XPU_SPMI_HOLD_TIME_ADDR(base) ((base) + (0x700))
#define SOC_PMCTRL_XPU_FREQ_VOTE_A0_ADDR(base) ((base) + (0x000))
#define SOC_PMCTRL_XPU_FREQ_VOTE_A1_ADDR(base) ((base) + (0x004))
#define SOC_PMCTRL_XPU_FREQ_VOTE_B0_ADDR(base) ((base) + (0x008))
#define SOC_PMCTRL_XPU_FREQ_VOTE_B1_ADDR(base) ((base) + (0x00C))
#define SOC_PMCTRL_XPU_FREQ_VOTE_C0_ADDR(base) ((base) + (0x010))
#define SOC_PMCTRL_XPU_FREQ_VOTE_C1_ADDR(base) ((base) + (0x014))
#define SOC_PMCTRL_XPU_FREQ_VOTE_D0_ADDR(base) ((base) + (0x018))
#define SOC_PMCTRL_XPU_FREQ_VOTE_D1_ADDR(base) ((base) + (0x01C))
#define SOC_PMCTRL_XPU_FREQ_VOTE_E0_ADDR(base) ((base) + (0x020))
#define SOC_PMCTRL_XPU_FREQ_VOTE_E1_ADDR(base) ((base) + (0x024))
#define SOC_PMCTRL_XPU_FREQ_VOTE_E2_ADDR(base) ((base) + (0x028))
#define SOC_PMCTRL_XPU_FREQ_VOTE_E3_ADDR(base) ((base) + (0x02C))
#define SOC_PMCTRL_XPU_FREQ_VOTE_F0_ADDR(base) ((base) + (0x030))
#define SOC_PMCTRL_XPU_FREQ_VOTE_F1_ADDR(base) ((base) + (0x034))
#define SOC_PMCTRL_XPU_FREQ_VOTE_F2_ADDR(base) ((base) + (0x038))
#define SOC_PMCTRL_XPU_FREQ_VOTE_F3_ADDR(base) ((base) + (0x03C))
#define SOC_PMCTRL_XPU_FREQ_VOTE_G0_ADDR(base) ((base) + (0x040))
#define SOC_PMCTRL_XPU_FREQ_VOTE_G1_ADDR(base) ((base) + (0x044))
#define SOC_PMCTRL_XPU_FREQ_VOTE_G2_ADDR(base) ((base) + (0x048))
#define SOC_PMCTRL_XPU_FREQ_VOTE_G3_ADDR(base) ((base) + (0x04C))
#define SOC_PMCTRL_XPU_FREQ_VOTE_H0_ADDR(base) ((base) + (0x050))
#define SOC_PMCTRL_XPU_FREQ_VOTE_H1_ADDR(base) ((base) + (0x054))
#define SOC_PMCTRL_XPU_FREQ_VOTE_H2_ADDR(base) ((base) + (0x058))
#define SOC_PMCTRL_XPU_FREQ_VOTE_H3_ADDR(base) ((base) + (0x05C))
#define SOC_PMCTRL_XPU_FREQ_VOTE_I0_ADDR(base) ((base) + (0x060))
#define SOC_PMCTRL_XPU_FREQ_VOTE_I1_ADDR(base) ((base) + (0x064))
#define SOC_PMCTRL_XPU_FREQ_VOTE_J0_ADDR(base) ((base) + (0x068))
#define SOC_PMCTRL_XPU_FREQ_VOTE_J1_ADDR(base) ((base) + (0x06C))
#define SOC_PMCTRL_XPU_FREQ_VOTE_K0_ADDR(base) ((base) + (0x070))
#define SOC_PMCTRL_XPU_FREQ_VOTE_K1_ADDR(base) ((base) + (0x074))
#define SOC_PMCTRL_XPU_FREQ_VOTE_L0_ADDR(base) ((base) + (0x078))
#define SOC_PMCTRL_XPU_FREQ_VOTE_L1_ADDR(base) ((base) + (0x07C))
#define SOC_PMCTRL_XPU_FREQ_VOTE_M0_ADDR(base) ((base) + (0x080))
#define SOC_PMCTRL_XPU_FREQ_VOTE_M1_ADDR(base) ((base) + (0x084))
#define SOC_PMCTRL_XPU_FREQ_VOTE_M2_ADDR(base) ((base) + (0x088))
#define SOC_PMCTRL_XPU_FREQ_VOTE_M3_ADDR(base) ((base) + (0x08C))
#define SOC_PMCTRL_XPU_FREQ_VOTE_N0_ADDR(base) ((base) + (0x090))
#define SOC_PMCTRL_XPU_FREQ_VOTE_N1_ADDR(base) ((base) + (0x094))
#define SOC_PMCTRL_XPU_FREQ_VOTE_N2_ADDR(base) ((base) + (0x098))
#define SOC_PMCTRL_XPU_FREQ_VOTE_N3_ADDR(base) ((base) + (0x09C))
#define SOC_PMCTRL_XPU_FREQ_VOTE_O0_ADDR(base) ((base) + (0x0A0))
#define SOC_PMCTRL_XPU_FREQ_VOTE_O1_ADDR(base) ((base) + (0x0A4))
#define SOC_PMCTRL_XPU_FREQ_VOTE_O2_ADDR(base) ((base) + (0x0A8))
#define SOC_PMCTRL_XPU_FREQ_VOTE_O3_ADDR(base) ((base) + (0x0AC))
#define SOC_PMCTRL_XPU_FREQ_VOTE_P0_ADDR(base) ((base) + (0x0B0))
#define SOC_PMCTRL_XPU_FREQ_VOTE_P1_ADDR(base) ((base) + (0x0B4))
#define SOC_PMCTRL_XPU_FREQ_VOTE_P2_ADDR(base) ((base) + (0x0B8))
#define SOC_PMCTRL_XPU_FREQ_VOTE_P3_ADDR(base) ((base) + (0x0BC))
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_ADDR(base) ((base) + (0x0D0))
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_ADDR(base) ((base) + (0x0D4))
#define SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_MASK_0_ADDR(base) ((base) + (0x200))
#define SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_MASK_1_ADDR(base) ((base) + (0x204))
#define SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_MASK_2_ADDR(base) ((base) + (0x208))
#define SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_ADDR(base) ((base) + (0x0D8))
#define SOC_PMCTRL_XPU_VOTE_RESULT_A_ADDR(base) ((base) + (0x0DC))
#define SOC_PMCTRL_XPU_VOTE_RESULT_B_ADDR(base) ((base) + (0x0E0))
#define SOC_PMCTRL_XPU_VOTE_RESULT_C_ADDR(base) ((base) + (0x0E4))
#define SOC_PMCTRL_XPU_VOTE_RESULT_D_ADDR(base) ((base) + (0x0E8))
#define SOC_PMCTRL_XPU_VOTE_RESULT_E_ADDR(base) ((base) + (0x0EC))
#define SOC_PMCTRL_XPU_VOTE_RESULT_F_ADDR(base) ((base) + (0x0F0))
#define SOC_PMCTRL_XPU_VOTE_RESULT_G_ADDR(base) ((base) + (0x0F4))
#define SOC_PMCTRL_XPU_VOTE_RESULT_H_ADDR(base) ((base) + (0x0F8))
#define SOC_PMCTRL_XPU_VOTE_RESULT_I_ADDR(base) ((base) + (0x0FC))
#define SOC_PMCTRL_XPU_VOTE_RESULT_J_ADDR(base) ((base) + (0x100))
#define SOC_PMCTRL_XPU_VOTE_RESULT_K_ADDR(base) ((base) + (0x104))
#define SOC_PMCTRL_XPU_VOTE_RESULT_L_ADDR(base) ((base) + (0x108))
#define SOC_PMCTRL_XPU_VOTE_RESULT_M_ADDR(base) ((base) + (0x10C))
#define SOC_PMCTRL_XPU_VOTE_RESULT_N_ADDR(base) ((base) + (0x110))
#define SOC_PMCTRL_XPU_VOTE_RESULT_O_ADDR(base) ((base) + (0x114))
#define SOC_PMCTRL_XPU_VOTE_RESULT_P_ADDR(base) ((base) + (0x118))
#define SOC_PMCTRL_XPU_DVFSDATA0_ADDR(base) ((base) + (0x120))
#define SOC_PMCTRL_XPU_DVFSDATA1_ADDR(base) ((base) + (0x124))
#define SOC_PMCTRL_XPU_DVFSDATA2_ADDR(base) ((base) + (0x128))
#define SOC_PMCTRL_XPU_DVFSDATA3_ADDR(base) ((base) + (0x12C))
#define SOC_PMCTRL_XPU_DVFSDATA4_ADDR(base) ((base) + (0x130))
#define SOC_PMCTRL_XPU_DVFSDATA5_ADDR(base) ((base) + (0x134))
#define SOC_PMCTRL_XPU_DVFSDATA6_ADDR(base) ((base) + (0x138))
#define SOC_PMCTRL_XPU_DVFSDATA7_ADDR(base) ((base) + (0x13C))
#define SOC_PMCTRL_XPU_DVFSDATA8_ADDR(base) ((base) + (0x140))
#define SOC_PMCTRL_XPU_DVFSDATA9_ADDR(base) ((base) + (0x144))
#define SOC_PMCTRL_XPU_DVFSDATA10_ADDR(base) ((base) + (0x148))
#define SOC_PMCTRL_XPU_DVFSDATA11_ADDR(base) ((base) + (0x14C))
#define SOC_PMCTRL_XPU_DVFSDATA12_ADDR(base) ((base) + (0x150))
#define SOC_PMCTRL_XPU_DVFSDATA13_ADDR(base) ((base) + (0x154))
#define SOC_PMCTRL_XPU_DVFSDATA14_ADDR(base) ((base) + (0x158))
#define SOC_PMCTRL_XPU_DVFSDATA15_ADDR(base) ((base) + (0x15C))
#define SOC_PMCTRL_XPU_DVFSDATA16_ADDR(base) ((base) + (0x160))
#define SOC_PMCTRL_XPU_DVFSDATA17_ADDR(base) ((base) + (0x164))
#define SOC_PMCTRL_XPU_DVFSDATA18_ADDR(base) ((base) + (0x168))
#define SOC_PMCTRL_XPU_DVFSDATA19_ADDR(base) ((base) + (0x16C))
#define SOC_PMCTRL_XPU_DVFSDATA20_ADDR(base) ((base) + (0x170))
#define SOC_PMCTRL_XPU_DVFSDATA21_ADDR(base) ((base) + (0x174))
#define SOC_PMCTRL_XPU_DVFSDATA22_ADDR(base) ((base) + (0x178))
#define SOC_PMCTRL_XPU_DVFSDATA23_ADDR(base) ((base) + (0x17C))
#define SOC_PMCTRL_XPU_DVFSDATA24_ADDR(base) ((base) + (0x180))
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED0_ADDR(base) ((base) + (0x184))
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED1_ADDR(base) ((base) + (0x188))
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED2_ADDR(base) ((base) + (0x18C))
#define SOC_PMCTRL_XPU_TEMPERATURE_VALID_STATUS0_ADDR(base) ((base) + (0x190))
#define SOC_PMCTRL_XPU_TEMPERATURE_VALID_STATUS1_ADDR(base) ((base) + (0x194))
#define SOC_PMCTRL_XPU_TEMPERATURE_VALID_STATUS2_ADDR(base) ((base) + (0x198))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_channel_num_a : 2;
        unsigned int freq_vote_channel_num_b : 2;
        unsigned int freq_vote_channel_num_c : 2;
        unsigned int freq_vote_channel_num_d : 2;
        unsigned int freq_vote_channel_num_e : 2;
        unsigned int freq_vote_channel_num_f : 2;
        unsigned int freq_vote_channel_num_g : 2;
        unsigned int freq_vote_channel_num_h : 2;
        unsigned int freq_vote_channel_num_i : 2;
        unsigned int freq_vote_channel_num_j : 2;
        unsigned int freq_vote_channel_num_k : 2;
        unsigned int freq_vote_channel_num_l : 2;
        unsigned int freq_vote_channel_num_m : 2;
        unsigned int freq_vote_channel_num_n : 2;
        unsigned int freq_vote_channel_num_o : 2;
        unsigned int freq_vote_channel_num_p : 2;
    } reg;
} SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_UNION;
#endif
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_a_START (0)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_a_END (1)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_b_START (2)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_b_END (3)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_c_START (4)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_c_END (5)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_d_START (6)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_d_END (7)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_e_START (8)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_e_END (9)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_f_START (10)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_f_END (11)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_g_START (12)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_g_END (13)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_h_START (14)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_h_END (15)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_i_START (16)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_i_END (17)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_j_START (18)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_j_END (19)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_k_START (20)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_k_END (21)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_l_START (22)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_l_END (23)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_m_START (24)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_m_END (25)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_n_START (26)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_n_END (27)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_o_START (28)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_o_END (29)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_p_START (30)
#define SOC_PMCTRL_XPU_VOTE_CHANNEL_CFG_freq_vote_channel_num_p_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_a_type : 2;
        unsigned int freq_vote_b_type : 2;
        unsigned int freq_vote_c_type : 2;
        unsigned int freq_vote_d_type : 2;
        unsigned int freq_vote_e_type : 2;
        unsigned int freq_vote_f_type : 2;
        unsigned int freq_vote_g_type : 2;
        unsigned int freq_vote_h_type : 2;
        unsigned int vote_mode_cfg_0_msk : 16;
    } reg;
} SOC_PMCTRL_XPU_VOTE_MODE_CFG_0_UNION;
#endif
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_0_freq_vote_a_type_START (0)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_0_freq_vote_a_type_END (1)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_0_freq_vote_b_type_START (2)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_0_freq_vote_b_type_END (3)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_0_freq_vote_c_type_START (4)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_0_freq_vote_c_type_END (5)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_0_freq_vote_d_type_START (6)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_0_freq_vote_d_type_END (7)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_0_freq_vote_e_type_START (8)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_0_freq_vote_e_type_END (9)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_0_freq_vote_f_type_START (10)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_0_freq_vote_f_type_END (11)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_0_freq_vote_g_type_START (12)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_0_freq_vote_g_type_END (13)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_0_freq_vote_h_type_START (14)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_0_freq_vote_h_type_END (15)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_0_vote_mode_cfg_0_msk_START (16)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_0_vote_mode_cfg_0_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_i_type : 2;
        unsigned int freq_vote_j_type : 2;
        unsigned int freq_vote_k_type : 2;
        unsigned int freq_vote_l_type : 2;
        unsigned int freq_vote_m_type : 2;
        unsigned int freq_vote_n_type : 2;
        unsigned int freq_vote_o_type : 2;
        unsigned int freq_vote_p_type : 2;
        unsigned int vote_mode_cfg_1_msk : 16;
    } reg;
} SOC_PMCTRL_XPU_VOTE_MODE_CFG_1_UNION;
#endif
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_1_freq_vote_i_type_START (0)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_1_freq_vote_i_type_END (1)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_1_freq_vote_j_type_START (2)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_1_freq_vote_j_type_END (3)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_1_freq_vote_k_type_START (4)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_1_freq_vote_k_type_END (5)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_1_freq_vote_l_type_START (6)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_1_freq_vote_l_type_END (7)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_1_freq_vote_m_type_START (8)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_1_freq_vote_m_type_END (9)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_1_freq_vote_n_type_START (10)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_1_freq_vote_n_type_END (11)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_1_freq_vote_o_type_START (12)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_1_freq_vote_o_type_END (13)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_1_freq_vote_p_type_START (14)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_1_freq_vote_p_type_END (15)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_1_vote_mode_cfg_1_msk_START (16)
#define SOC_PMCTRL_XPU_VOTE_MODE_CFG_1_vote_mode_cfg_1_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_a_start_en : 1;
        unsigned int freq_vote_b_start_en : 1;
        unsigned int freq_vote_c_start_en : 1;
        unsigned int freq_vote_d_start_en : 1;
        unsigned int freq_vote_e_start_en : 1;
        unsigned int freq_vote_f_start_en : 1;
        unsigned int freq_vote_g_start_en : 1;
        unsigned int freq_vote_h_start_en : 1;
        unsigned int freq_vote_i_start_en : 1;
        unsigned int freq_vote_j_start_en : 1;
        unsigned int freq_vote_k_start_en : 1;
        unsigned int freq_vote_l_start_en : 1;
        unsigned int freq_vote_m_start_en : 1;
        unsigned int freq_vote_n_start_en : 1;
        unsigned int freq_vote_o_start_en : 1;
        unsigned int freq_vote_p_start_en : 1;
        unsigned int vote_start_en_msk : 16;
    } reg;
} SOC_PMCTRL_XPU_VOTE_START_EN_UNION;
#endif
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_a_start_en_START (0)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_a_start_en_END (0)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_b_start_en_START (1)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_b_start_en_END (1)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_c_start_en_START (2)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_c_start_en_END (2)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_d_start_en_START (3)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_d_start_en_END (3)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_e_start_en_START (4)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_e_start_en_END (4)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_f_start_en_START (5)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_f_start_en_END (5)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_g_start_en_START (6)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_g_start_en_END (6)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_h_start_en_START (7)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_h_start_en_END (7)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_i_start_en_START (8)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_i_start_en_END (8)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_j_start_en_START (9)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_j_start_en_END (9)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_k_start_en_START (10)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_k_start_en_END (10)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_l_start_en_START (11)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_l_start_en_END (11)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_m_start_en_START (12)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_m_start_en_END (12)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_n_start_en_START (13)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_n_start_en_END (13)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_o_start_en_START (14)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_o_start_en_END (14)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_p_start_en_START (15)
#define SOC_PMCTRL_XPU_VOTE_START_EN_freq_vote_p_start_en_END (15)
#define SOC_PMCTRL_XPU_VOTE_START_EN_vote_start_en_msk_START (16)
#define SOC_PMCTRL_XPU_VOTE_START_EN_vote_start_en_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int int_freq_vote_en_a : 1;
        unsigned int int_freq_vote_en_b : 1;
        unsigned int int_freq_vote_en_c : 1;
        unsigned int int_freq_vote_en_d : 1;
        unsigned int int_freq_vote_en_e : 1;
        unsigned int int_freq_vote_en_f : 1;
        unsigned int int_freq_vote_en_g : 1;
        unsigned int int_freq_vote_en_h : 1;
        unsigned int int_freq_vote_en_i : 1;
        unsigned int int_freq_vote_en_j : 1;
        unsigned int int_freq_vote_en_k : 1;
        unsigned int int_freq_vote_en_l : 1;
        unsigned int int_freq_vote_en_m : 1;
        unsigned int int_freq_vote_en_n : 1;
        unsigned int int_freq_vote_en_o : 1;
        unsigned int int_freq_vote_en_p : 1;
        unsigned int int_vote_en_msk : 16;
    } reg;
} SOC_PMCTRL_XPU_INT_VOTE_EN_UNION;
#endif
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_a_START (0)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_a_END (0)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_b_START (1)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_b_END (1)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_c_START (2)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_c_END (2)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_d_START (3)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_d_END (3)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_e_START (4)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_e_END (4)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_f_START (5)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_f_END (5)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_g_START (6)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_g_END (6)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_h_START (7)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_h_END (7)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_i_START (8)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_i_END (8)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_j_START (9)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_j_END (9)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_k_START (10)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_k_END (10)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_l_START (11)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_l_END (11)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_m_START (12)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_m_END (12)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_n_START (13)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_n_END (13)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_o_START (14)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_o_END (14)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_p_START (15)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_freq_vote_en_p_END (15)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_vote_en_msk_START (16)
#define SOC_PMCTRL_XPU_INT_VOTE_EN_int_vote_en_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int int_freq_vote_a_clr : 1;
        unsigned int int_freq_vote_b_clr : 1;
        unsigned int int_freq_vote_c_clr : 1;
        unsigned int int_freq_vote_d_clr : 1;
        unsigned int int_freq_vote_e_clr : 1;
        unsigned int int_freq_vote_f_clr : 1;
        unsigned int int_freq_vote_g_clr : 1;
        unsigned int int_freq_vote_h_clr : 1;
        unsigned int int_freq_vote_i_clr : 1;
        unsigned int int_freq_vote_j_clr : 1;
        unsigned int int_freq_vote_k_clr : 1;
        unsigned int int_freq_vote_l_clr : 1;
        unsigned int int_freq_vote_m_clr : 1;
        unsigned int int_freq_vote_n_clr : 1;
        unsigned int int_freq_vote_o_clr : 1;
        unsigned int int_freq_vote_p_clr : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_PMCTRL_XPU_INT_VOTE_CLR_UNION;
#endif
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_a_clr_START (0)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_a_clr_END (0)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_b_clr_START (1)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_b_clr_END (1)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_c_clr_START (2)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_c_clr_END (2)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_d_clr_START (3)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_d_clr_END (3)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_e_clr_START (4)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_e_clr_END (4)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_f_clr_START (5)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_f_clr_END (5)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_g_clr_START (6)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_g_clr_END (6)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_h_clr_START (7)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_h_clr_END (7)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_i_clr_START (8)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_i_clr_END (8)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_j_clr_START (9)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_j_clr_END (9)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_k_clr_START (10)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_k_clr_END (10)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_l_clr_START (11)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_l_clr_END (11)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_m_clr_START (12)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_m_clr_END (12)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_n_clr_START (13)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_n_clr_END (13)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_o_clr_START (14)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_o_clr_END (14)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_p_clr_START (15)
#define SOC_PMCTRL_XPU_INT_VOTE_CLR_int_freq_vote_p_clr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int xpu_pmc_vote_power_00 : 4;
        unsigned int xpu_pmc_vote_power_01 : 4;
        unsigned int xpu_pmc_vote_power_02 : 4;
        unsigned int xpu_pmc_vote_power_03 : 4;
        unsigned int xpu_pmc_vote_power_04 : 4;
        unsigned int xpu_pmc_vote_power_05 : 4;
        unsigned int xpu_pmc_vote_power_06 : 4;
        unsigned int xpu_pmc_vote_power_07 : 4;
    } reg;
} SOC_PMCTRL_XPU_VOTE_POWER_EN_UNION;
#endif
#define SOC_PMCTRL_XPU_VOTE_POWER_EN_xpu_pmc_vote_power_00_START (0)
#define SOC_PMCTRL_XPU_VOTE_POWER_EN_xpu_pmc_vote_power_00_END (3)
#define SOC_PMCTRL_XPU_VOTE_POWER_EN_xpu_pmc_vote_power_01_START (4)
#define SOC_PMCTRL_XPU_VOTE_POWER_EN_xpu_pmc_vote_power_01_END (7)
#define SOC_PMCTRL_XPU_VOTE_POWER_EN_xpu_pmc_vote_power_02_START (8)
#define SOC_PMCTRL_XPU_VOTE_POWER_EN_xpu_pmc_vote_power_02_END (11)
#define SOC_PMCTRL_XPU_VOTE_POWER_EN_xpu_pmc_vote_power_03_START (12)
#define SOC_PMCTRL_XPU_VOTE_POWER_EN_xpu_pmc_vote_power_03_END (15)
#define SOC_PMCTRL_XPU_VOTE_POWER_EN_xpu_pmc_vote_power_04_START (16)
#define SOC_PMCTRL_XPU_VOTE_POWER_EN_xpu_pmc_vote_power_04_END (19)
#define SOC_PMCTRL_XPU_VOTE_POWER_EN_xpu_pmc_vote_power_05_START (20)
#define SOC_PMCTRL_XPU_VOTE_POWER_EN_xpu_pmc_vote_power_05_END (23)
#define SOC_PMCTRL_XPU_VOTE_POWER_EN_xpu_pmc_vote_power_06_START (24)
#define SOC_PMCTRL_XPU_VOTE_POWER_EN_xpu_pmc_vote_power_06_END (27)
#define SOC_PMCTRL_XPU_VOTE_POWER_EN_xpu_pmc_vote_power_07_START (28)
#define SOC_PMCTRL_XPU_VOTE_POWER_EN_xpu_pmc_vote_power_07_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int xpu_pmc_vote_power_00 : 4;
        unsigned int xpu_pmc_vote_power_01 : 4;
        unsigned int xpu_pmc_vote_power_02 : 4;
        unsigned int xpu_pmc_vote_power_03 : 4;
        unsigned int xpu_pmc_vote_power_04 : 4;
        unsigned int xpu_pmc_vote_power_05 : 4;
        unsigned int xpu_pmc_vote_power_06 : 4;
        unsigned int xpu_pmc_vote_power_07 : 4;
    } reg;
} SOC_PMCTRL_XPU_VOTE_POWER_DIS_UNION;
#endif
#define SOC_PMCTRL_XPU_VOTE_POWER_DIS_xpu_pmc_vote_power_00_START (0)
#define SOC_PMCTRL_XPU_VOTE_POWER_DIS_xpu_pmc_vote_power_00_END (3)
#define SOC_PMCTRL_XPU_VOTE_POWER_DIS_xpu_pmc_vote_power_01_START (4)
#define SOC_PMCTRL_XPU_VOTE_POWER_DIS_xpu_pmc_vote_power_01_END (7)
#define SOC_PMCTRL_XPU_VOTE_POWER_DIS_xpu_pmc_vote_power_02_START (8)
#define SOC_PMCTRL_XPU_VOTE_POWER_DIS_xpu_pmc_vote_power_02_END (11)
#define SOC_PMCTRL_XPU_VOTE_POWER_DIS_xpu_pmc_vote_power_03_START (12)
#define SOC_PMCTRL_XPU_VOTE_POWER_DIS_xpu_pmc_vote_power_03_END (15)
#define SOC_PMCTRL_XPU_VOTE_POWER_DIS_xpu_pmc_vote_power_04_START (16)
#define SOC_PMCTRL_XPU_VOTE_POWER_DIS_xpu_pmc_vote_power_04_END (19)
#define SOC_PMCTRL_XPU_VOTE_POWER_DIS_xpu_pmc_vote_power_05_START (20)
#define SOC_PMCTRL_XPU_VOTE_POWER_DIS_xpu_pmc_vote_power_05_END (23)
#define SOC_PMCTRL_XPU_VOTE_POWER_DIS_xpu_pmc_vote_power_06_START (24)
#define SOC_PMCTRL_XPU_VOTE_POWER_DIS_xpu_pmc_vote_power_06_END (27)
#define SOC_PMCTRL_XPU_VOTE_POWER_DIS_xpu_pmc_vote_power_07_START (28)
#define SOC_PMCTRL_XPU_VOTE_POWER_DIS_xpu_pmc_vote_power_07_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int xpu_pmc_vote_power_00 : 4;
        unsigned int xpu_pmc_vote_power_01 : 4;
        unsigned int xpu_pmc_vote_power_02 : 4;
        unsigned int xpu_pmc_vote_power_03 : 4;
        unsigned int xpu_pmc_vote_power_04 : 4;
        unsigned int xpu_pmc_vote_power_05 : 4;
        unsigned int xpu_pmc_vote_power_06 : 4;
        unsigned int xpu_pmc_vote_power_07 : 4;
    } reg;
} SOC_PMCTRL_XPU_VOTE_POWER_REQ_UNION;
#endif
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_xpu_pmc_vote_power_00_START (0)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_xpu_pmc_vote_power_00_END (3)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_xpu_pmc_vote_power_01_START (4)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_xpu_pmc_vote_power_01_END (7)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_xpu_pmc_vote_power_02_START (8)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_xpu_pmc_vote_power_02_END (11)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_xpu_pmc_vote_power_03_START (12)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_xpu_pmc_vote_power_03_END (15)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_xpu_pmc_vote_power_04_START (16)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_xpu_pmc_vote_power_04_END (19)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_xpu_pmc_vote_power_05_START (20)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_xpu_pmc_vote_power_05_END (23)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_xpu_pmc_vote_power_06_START (24)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_xpu_pmc_vote_power_06_END (27)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_xpu_pmc_vote_power_07_START (28)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_xpu_pmc_vote_power_07_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vote_power_req_stat_00 : 1;
        unsigned int vote_power_req_stat_01 : 1;
        unsigned int vote_power_req_stat_02 : 1;
        unsigned int vote_power_req_stat_03 : 1;
        unsigned int vote_power_req_stat_04 : 1;
        unsigned int vote_power_req_stat_05 : 1;
        unsigned int vote_power_req_stat_06 : 1;
        unsigned int vote_power_req_stat_07 : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_PMCTRL_XPU_VOTE_POWER_REQ_STAT_UNION;
#endif
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_STAT_vote_power_req_stat_00_START (0)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_STAT_vote_power_req_stat_00_END (0)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_STAT_vote_power_req_stat_01_START (1)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_STAT_vote_power_req_stat_01_END (1)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_STAT_vote_power_req_stat_02_START (2)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_STAT_vote_power_req_stat_02_END (2)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_STAT_vote_power_req_stat_03_START (3)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_STAT_vote_power_req_stat_03_END (3)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_STAT_vote_power_req_stat_04_START (4)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_STAT_vote_power_req_stat_04_END (4)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_STAT_vote_power_req_stat_05_START (5)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_STAT_vote_power_req_stat_05_END (5)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_STAT_vote_power_req_stat_06_START (6)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_STAT_vote_power_req_stat_06_END (6)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_STAT_vote_power_req_stat_07_START (7)
#define SOC_PMCTRL_XPU_VOTE_POWER_REQ_STAT_vote_power_req_stat_07_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pwrstat_sw2on_req_pls_00 : 1;
        unsigned int pwrstat_sw2on_req_pls_01 : 1;
        unsigned int pwrstat_sw2on_req_pls_02 : 1;
        unsigned int pwrstat_sw2on_req_pls_03 : 1;
        unsigned int pwrstat_sw2on_req_pls_04 : 1;
        unsigned int pwrstat_sw2on_req_pls_05 : 1;
        unsigned int pwrstat_sw2on_req_pls_06 : 1;
        unsigned int pwrstat_sw2on_req_pls_07 : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_PMCTRL_XPU_PWRSTAT_SW2ON_REQ_UNION;
#endif
#define SOC_PMCTRL_XPU_PWRSTAT_SW2ON_REQ_pwrstat_sw2on_req_pls_00_START (0)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2ON_REQ_pwrstat_sw2on_req_pls_00_END (0)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2ON_REQ_pwrstat_sw2on_req_pls_01_START (1)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2ON_REQ_pwrstat_sw2on_req_pls_01_END (1)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2ON_REQ_pwrstat_sw2on_req_pls_02_START (2)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2ON_REQ_pwrstat_sw2on_req_pls_02_END (2)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2ON_REQ_pwrstat_sw2on_req_pls_03_START (3)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2ON_REQ_pwrstat_sw2on_req_pls_03_END (3)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2ON_REQ_pwrstat_sw2on_req_pls_04_START (4)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2ON_REQ_pwrstat_sw2on_req_pls_04_END (4)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2ON_REQ_pwrstat_sw2on_req_pls_05_START (5)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2ON_REQ_pwrstat_sw2on_req_pls_05_END (5)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2ON_REQ_pwrstat_sw2on_req_pls_06_START (6)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2ON_REQ_pwrstat_sw2on_req_pls_06_END (6)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2ON_REQ_pwrstat_sw2on_req_pls_07_START (7)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2ON_REQ_pwrstat_sw2on_req_pls_07_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pwrstat_sw2off_req_pls_00 : 1;
        unsigned int pwrstat_sw2off_req_pls_01 : 1;
        unsigned int pwrstat_sw2off_req_pls_02 : 1;
        unsigned int pwrstat_sw2off_req_pls_03 : 1;
        unsigned int pwrstat_sw2off_req_pls_04 : 1;
        unsigned int pwrstat_sw2off_req_pls_05 : 1;
        unsigned int pwrstat_sw2off_req_pls_06 : 1;
        unsigned int pwrstat_sw2off_req_pls_07 : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_PMCTRL_XPU_PWRSTAT_SW2OFF_REQ_UNION;
#endif
#define SOC_PMCTRL_XPU_PWRSTAT_SW2OFF_REQ_pwrstat_sw2off_req_pls_00_START (0)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2OFF_REQ_pwrstat_sw2off_req_pls_00_END (0)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2OFF_REQ_pwrstat_sw2off_req_pls_01_START (1)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2OFF_REQ_pwrstat_sw2off_req_pls_01_END (1)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2OFF_REQ_pwrstat_sw2off_req_pls_02_START (2)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2OFF_REQ_pwrstat_sw2off_req_pls_02_END (2)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2OFF_REQ_pwrstat_sw2off_req_pls_03_START (3)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2OFF_REQ_pwrstat_sw2off_req_pls_03_END (3)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2OFF_REQ_pwrstat_sw2off_req_pls_04_START (4)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2OFF_REQ_pwrstat_sw2off_req_pls_04_END (4)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2OFF_REQ_pwrstat_sw2off_req_pls_05_START (5)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2OFF_REQ_pwrstat_sw2off_req_pls_05_END (5)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2OFF_REQ_pwrstat_sw2off_req_pls_06_START (6)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2OFF_REQ_pwrstat_sw2off_req_pls_06_END (6)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2OFF_REQ_pwrstat_sw2off_req_pls_07_START (7)
#define SOC_PMCTRL_XPU_PWRSTAT_SW2OFF_REQ_pwrstat_sw2off_req_pls_07_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vote_power_onoff_enable_00 : 1;
        unsigned int vote_power_onoff_enable_01 : 1;
        unsigned int vote_power_onoff_enable_02 : 1;
        unsigned int vote_power_onoff_enable_03 : 1;
        unsigned int vote_power_onoff_enable_04 : 1;
        unsigned int vote_power_onoff_enable_05 : 1;
        unsigned int vote_power_onoff_enable_06 : 1;
        unsigned int vote_power_onoff_enable_07 : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_PMCTRL_XPU_VOTE_POWER_ONOFF_EN_UNION;
#endif
#define SOC_PMCTRL_XPU_VOTE_POWER_ONOFF_EN_vote_power_onoff_enable_00_START (0)
#define SOC_PMCTRL_XPU_VOTE_POWER_ONOFF_EN_vote_power_onoff_enable_00_END (0)
#define SOC_PMCTRL_XPU_VOTE_POWER_ONOFF_EN_vote_power_onoff_enable_01_START (1)
#define SOC_PMCTRL_XPU_VOTE_POWER_ONOFF_EN_vote_power_onoff_enable_01_END (1)
#define SOC_PMCTRL_XPU_VOTE_POWER_ONOFF_EN_vote_power_onoff_enable_02_START (2)
#define SOC_PMCTRL_XPU_VOTE_POWER_ONOFF_EN_vote_power_onoff_enable_02_END (2)
#define SOC_PMCTRL_XPU_VOTE_POWER_ONOFF_EN_vote_power_onoff_enable_03_START (3)
#define SOC_PMCTRL_XPU_VOTE_POWER_ONOFF_EN_vote_power_onoff_enable_03_END (3)
#define SOC_PMCTRL_XPU_VOTE_POWER_ONOFF_EN_vote_power_onoff_enable_04_START (4)
#define SOC_PMCTRL_XPU_VOTE_POWER_ONOFF_EN_vote_power_onoff_enable_04_END (4)
#define SOC_PMCTRL_XPU_VOTE_POWER_ONOFF_EN_vote_power_onoff_enable_05_START (5)
#define SOC_PMCTRL_XPU_VOTE_POWER_ONOFF_EN_vote_power_onoff_enable_05_END (5)
#define SOC_PMCTRL_XPU_VOTE_POWER_ONOFF_EN_vote_power_onoff_enable_06_START (6)
#define SOC_PMCTRL_XPU_VOTE_POWER_ONOFF_EN_vote_power_onoff_enable_06_END (6)
#define SOC_PMCTRL_XPU_VOTE_POWER_ONOFF_EN_vote_power_onoff_enable_07_START (7)
#define SOC_PMCTRL_XPU_VOTE_POWER_ONOFF_EN_vote_power_onoff_enable_07_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_vote_power_on_00 : 1;
        unsigned int intr_vote_power_on_01 : 1;
        unsigned int intr_vote_power_on_02 : 1;
        unsigned int intr_vote_power_on_03 : 1;
        unsigned int intr_vote_power_on_04 : 1;
        unsigned int intr_vote_power_on_05 : 1;
        unsigned int intr_vote_power_on_06 : 1;
        unsigned int intr_vote_power_on_07 : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_UNION;
#endif
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_intr_vote_power_on_00_START (0)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_intr_vote_power_on_00_END (0)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_intr_vote_power_on_01_START (1)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_intr_vote_power_on_01_END (1)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_intr_vote_power_on_02_START (2)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_intr_vote_power_on_02_END (2)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_intr_vote_power_on_03_START (3)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_intr_vote_power_on_03_END (3)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_intr_vote_power_on_04_START (4)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_intr_vote_power_on_04_END (4)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_intr_vote_power_on_05_START (5)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_intr_vote_power_on_05_END (5)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_intr_vote_power_on_06_START (6)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_intr_vote_power_on_06_END (6)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_intr_vote_power_on_07_START (7)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_intr_vote_power_on_07_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_vote_power_off_00 : 1;
        unsigned int intr_vote_power_off_01 : 1;
        unsigned int intr_vote_power_off_02 : 1;
        unsigned int intr_vote_power_off_03 : 1;
        unsigned int intr_vote_power_off_04 : 1;
        unsigned int intr_vote_power_off_05 : 1;
        unsigned int intr_vote_power_off_06 : 1;
        unsigned int intr_vote_power_off_07 : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_UNION;
#endif
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_intr_vote_power_off_00_START (0)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_intr_vote_power_off_00_END (0)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_intr_vote_power_off_01_START (1)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_intr_vote_power_off_01_END (1)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_intr_vote_power_off_02_START (2)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_intr_vote_power_off_02_END (2)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_intr_vote_power_off_03_START (3)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_intr_vote_power_off_03_END (3)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_intr_vote_power_off_04_START (4)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_intr_vote_power_off_04_END (4)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_intr_vote_power_off_05_START (5)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_intr_vote_power_off_05_END (5)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_intr_vote_power_off_06_START (6)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_intr_vote_power_off_06_END (6)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_intr_vote_power_off_07_START (7)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_intr_vote_power_off_07_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_vote_power_on_raw_00 : 1;
        unsigned int intr_vote_power_on_raw_01 : 1;
        unsigned int intr_vote_power_on_raw_02 : 1;
        unsigned int intr_vote_power_on_raw_03 : 1;
        unsigned int intr_vote_power_on_raw_04 : 1;
        unsigned int intr_vote_power_on_raw_05 : 1;
        unsigned int intr_vote_power_on_raw_06 : 1;
        unsigned int intr_vote_power_on_raw_07 : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_RAW_UNION;
#endif
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_RAW_intr_vote_power_on_raw_00_START (0)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_RAW_intr_vote_power_on_raw_00_END (0)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_RAW_intr_vote_power_on_raw_01_START (1)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_RAW_intr_vote_power_on_raw_01_END (1)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_RAW_intr_vote_power_on_raw_02_START (2)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_RAW_intr_vote_power_on_raw_02_END (2)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_RAW_intr_vote_power_on_raw_03_START (3)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_RAW_intr_vote_power_on_raw_03_END (3)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_RAW_intr_vote_power_on_raw_04_START (4)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_RAW_intr_vote_power_on_raw_04_END (4)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_RAW_intr_vote_power_on_raw_05_START (5)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_RAW_intr_vote_power_on_raw_05_END (5)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_RAW_intr_vote_power_on_raw_06_START (6)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_RAW_intr_vote_power_on_raw_06_END (6)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_RAW_intr_vote_power_on_raw_07_START (7)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_RAW_intr_vote_power_on_raw_07_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_vote_power_off_raw_00 : 1;
        unsigned int intr_vote_power_off_raw_01 : 1;
        unsigned int intr_vote_power_off_raw_02 : 1;
        unsigned int intr_vote_power_off_raw_03 : 1;
        unsigned int intr_vote_power_off_raw_04 : 1;
        unsigned int intr_vote_power_off_raw_05 : 1;
        unsigned int intr_vote_power_off_raw_06 : 1;
        unsigned int intr_vote_power_off_raw_07 : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_RAW_UNION;
#endif
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_RAW_intr_vote_power_off_raw_00_START (0)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_RAW_intr_vote_power_off_raw_00_END (0)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_RAW_intr_vote_power_off_raw_01_START (1)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_RAW_intr_vote_power_off_raw_01_END (1)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_RAW_intr_vote_power_off_raw_02_START (2)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_RAW_intr_vote_power_off_raw_02_END (2)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_RAW_intr_vote_power_off_raw_03_START (3)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_RAW_intr_vote_power_off_raw_03_END (3)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_RAW_intr_vote_power_off_raw_04_START (4)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_RAW_intr_vote_power_off_raw_04_END (4)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_RAW_intr_vote_power_off_raw_05_START (5)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_RAW_intr_vote_power_off_raw_05_END (5)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_RAW_intr_vote_power_off_raw_06_START (6)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_RAW_intr_vote_power_off_raw_06_END (6)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_RAW_intr_vote_power_off_raw_07_START (7)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_RAW_intr_vote_power_off_raw_07_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_power_on_clr_00 : 1;
        unsigned int intr_power_on_clr_01 : 1;
        unsigned int intr_power_on_clr_02 : 1;
        unsigned int intr_power_on_clr_03 : 1;
        unsigned int intr_power_on_clr_04 : 1;
        unsigned int intr_power_on_clr_05 : 1;
        unsigned int intr_power_on_clr_06 : 1;
        unsigned int intr_power_on_clr_07 : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_CLR_UNION;
#endif
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_CLR_intr_power_on_clr_00_START (0)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_CLR_intr_power_on_clr_00_END (0)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_CLR_intr_power_on_clr_01_START (1)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_CLR_intr_power_on_clr_01_END (1)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_CLR_intr_power_on_clr_02_START (2)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_CLR_intr_power_on_clr_02_END (2)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_CLR_intr_power_on_clr_03_START (3)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_CLR_intr_power_on_clr_03_END (3)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_CLR_intr_power_on_clr_04_START (4)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_CLR_intr_power_on_clr_04_END (4)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_CLR_intr_power_on_clr_05_START (5)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_CLR_intr_power_on_clr_05_END (5)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_CLR_intr_power_on_clr_06_START (6)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_CLR_intr_power_on_clr_06_END (6)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_CLR_intr_power_on_clr_07_START (7)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ON_CLR_intr_power_on_clr_07_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_power_off_clr_00 : 1;
        unsigned int intr_power_off_clr_01 : 1;
        unsigned int intr_power_off_clr_02 : 1;
        unsigned int intr_power_off_clr_03 : 1;
        unsigned int intr_power_off_clr_04 : 1;
        unsigned int intr_power_off_clr_05 : 1;
        unsigned int intr_power_off_clr_06 : 1;
        unsigned int intr_power_off_clr_07 : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_CLR_UNION;
#endif
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_CLR_intr_power_off_clr_00_START (0)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_CLR_intr_power_off_clr_00_END (0)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_CLR_intr_power_off_clr_01_START (1)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_CLR_intr_power_off_clr_01_END (1)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_CLR_intr_power_off_clr_02_START (2)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_CLR_intr_power_off_clr_02_END (2)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_CLR_intr_power_off_clr_03_START (3)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_CLR_intr_power_off_clr_03_END (3)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_CLR_intr_power_off_clr_04_START (4)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_CLR_intr_power_off_clr_04_END (4)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_CLR_intr_power_off_clr_05_START (5)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_CLR_intr_power_off_clr_05_END (5)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_CLR_intr_power_off_clr_06_START (6)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_CLR_intr_power_off_clr_06_END (6)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_CLR_intr_power_off_clr_07_START (7)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_OFF_CLR_intr_power_off_clr_07_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int curr_vote_power_stat_00 : 2;
        unsigned int curr_vote_power_stat_01 : 2;
        unsigned int curr_vote_power_stat_02 : 2;
        unsigned int curr_vote_power_stat_03 : 2;
        unsigned int curr_vote_power_stat_04 : 2;
        unsigned int curr_vote_power_stat_05 : 2;
        unsigned int curr_vote_power_stat_06 : 2;
        unsigned int curr_vote_power_stat_07 : 2;
        unsigned int reserved : 16;
    } reg;
} SOC_PMCTRL_XPU_CURR_VOTE_POWER_STAT_UNION;
#endif
#define SOC_PMCTRL_XPU_CURR_VOTE_POWER_STAT_curr_vote_power_stat_00_START (0)
#define SOC_PMCTRL_XPU_CURR_VOTE_POWER_STAT_curr_vote_power_stat_00_END (1)
#define SOC_PMCTRL_XPU_CURR_VOTE_POWER_STAT_curr_vote_power_stat_01_START (2)
#define SOC_PMCTRL_XPU_CURR_VOTE_POWER_STAT_curr_vote_power_stat_01_END (3)
#define SOC_PMCTRL_XPU_CURR_VOTE_POWER_STAT_curr_vote_power_stat_02_START (4)
#define SOC_PMCTRL_XPU_CURR_VOTE_POWER_STAT_curr_vote_power_stat_02_END (5)
#define SOC_PMCTRL_XPU_CURR_VOTE_POWER_STAT_curr_vote_power_stat_03_START (6)
#define SOC_PMCTRL_XPU_CURR_VOTE_POWER_STAT_curr_vote_power_stat_03_END (7)
#define SOC_PMCTRL_XPU_CURR_VOTE_POWER_STAT_curr_vote_power_stat_04_START (8)
#define SOC_PMCTRL_XPU_CURR_VOTE_POWER_STAT_curr_vote_power_stat_04_END (9)
#define SOC_PMCTRL_XPU_CURR_VOTE_POWER_STAT_curr_vote_power_stat_05_START (10)
#define SOC_PMCTRL_XPU_CURR_VOTE_POWER_STAT_curr_vote_power_stat_05_END (11)
#define SOC_PMCTRL_XPU_CURR_VOTE_POWER_STAT_curr_vote_power_stat_06_START (12)
#define SOC_PMCTRL_XPU_CURR_VOTE_POWER_STAT_curr_vote_power_stat_06_END (13)
#define SOC_PMCTRL_XPU_CURR_VOTE_POWER_STAT_curr_vote_power_stat_07_START (14)
#define SOC_PMCTRL_XPU_CURR_VOTE_POWER_STAT_curr_vote_power_stat_07_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_vote_power_on_mask : 8;
        unsigned int intr_vote_power_off_mask : 8;
        unsigned int intr_vote_power_on_aft_msked : 8;
        unsigned int intr_vote_power_off_aft_msked : 8;
    } reg;
} SOC_PMCTRL_XPU_INTR_VOTE_POWER_ONOFF_MASK_UNION;
#endif
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ONOFF_MASK_intr_vote_power_on_mask_START (0)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ONOFF_MASK_intr_vote_power_on_mask_END (7)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ONOFF_MASK_intr_vote_power_off_mask_START (8)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ONOFF_MASK_intr_vote_power_off_mask_END (15)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ONOFF_MASK_intr_vote_power_on_aft_msked_START (16)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ONOFF_MASK_intr_vote_power_on_aft_msked_END (23)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ONOFF_MASK_intr_vote_power_off_aft_msked_START (24)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ONOFF_MASK_intr_vote_power_off_aft_msked_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_vote_power_on : 1;
        unsigned int intr_vote_power_off : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_PMCTRL_XPU_INTR_VOTE_POWER_ONOFF_UNION;
#endif
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ONOFF_intr_vote_power_on_START (0)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ONOFF_intr_vote_power_on_END (0)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ONOFF_intr_vote_power_off_START (1)
#define SOC_PMCTRL_XPU_INTR_VOTE_POWER_ONOFF_intr_vote_power_off_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int resource0lock_cmd0 : 1;
        unsigned int resource0lock_id0 : 3;
        unsigned int resource0lock_cmd1 : 1;
        unsigned int resource0lock_id1 : 3;
        unsigned int resource0lock_cmd2 : 1;
        unsigned int resource0lock_id2 : 3;
        unsigned int resource0lock_cmd3 : 1;
        unsigned int resource0lock_id3 : 3;
        unsigned int resource0lock_cmd4 : 1;
        unsigned int resource0lock_id4 : 3;
        unsigned int resource0lock_cmd5 : 1;
        unsigned int resource0lock_id5 : 3;
        unsigned int resource0lock_cmd6 : 1;
        unsigned int resource0lock_id6 : 3;
        unsigned int resource0lock_cmd7 : 1;
        unsigned int resource0lock_id7 : 3;
    } reg;
} SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_UNION;
#endif
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_cmd0_START (0)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_cmd0_END (0)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_id0_START (1)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_id0_END (3)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_cmd1_START (4)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_cmd1_END (4)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_id1_START (5)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_id1_END (7)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_cmd2_START (8)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_cmd2_END (8)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_id2_START (9)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_id2_END (11)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_cmd3_START (12)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_cmd3_END (12)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_id3_START (13)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_id3_END (15)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_cmd4_START (16)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_cmd4_END (16)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_id4_START (17)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_id4_END (19)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_cmd5_START (20)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_cmd5_END (20)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_id5_START (21)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_id5_END (23)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_cmd6_START (24)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_cmd6_END (24)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_id6_START (25)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_id6_END (27)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_cmd7_START (28)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_cmd7_END (28)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_id7_START (29)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_CFG_0_resource0lock_id7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int resource0unlock_cmd0 : 1;
        unsigned int resource0unlock_id0 : 3;
        unsigned int resource0unlock_cmd1 : 1;
        unsigned int resource0unlock_id1 : 3;
        unsigned int resource0unlock_cmd2 : 1;
        unsigned int resource0unlock_id2 : 3;
        unsigned int resource0unlock_cmd3 : 1;
        unsigned int resource0unlock_id3 : 3;
        unsigned int resource0unlock_cmd4 : 1;
        unsigned int resource0unlock_id4 : 3;
        unsigned int resource0unlock_cmd5 : 1;
        unsigned int resource0unlock_id5 : 3;
        unsigned int resource0unlock_cmd6 : 1;
        unsigned int resource0unlock_id6 : 3;
        unsigned int resource0unlock_cmd7 : 1;
        unsigned int resource0unlock_id7 : 3;
    } reg;
} SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_UNION;
#endif
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_cmd0_START (0)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_cmd0_END (0)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_id0_START (1)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_id0_END (3)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_cmd1_START (4)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_cmd1_END (4)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_id1_START (5)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_id1_END (7)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_cmd2_START (8)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_cmd2_END (8)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_id2_START (9)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_id2_END (11)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_cmd3_START (12)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_cmd3_END (12)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_id3_START (13)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_id3_END (15)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_cmd4_START (16)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_cmd4_END (16)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_id4_START (17)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_id4_END (19)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_cmd5_START (20)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_cmd5_END (20)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_id5_START (21)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_id5_END (23)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_cmd6_START (24)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_cmd6_END (24)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_id6_START (25)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_id6_END (27)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_cmd7_START (28)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_cmd7_END (28)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_id7_START (29)
#define SOC_PMCTRL_XPU_XPU_PMC_UNLOCK_CFG_0_resource0unlock_id7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int resource0lock_st0 : 1;
        unsigned int resource0lock_st_id0 : 3;
        unsigned int resource0lock_st1 : 1;
        unsigned int resource0lock_st_id1 : 3;
        unsigned int resource0lock_st2 : 1;
        unsigned int resource0lock_st_id2 : 3;
        unsigned int resource0lock_st3 : 1;
        unsigned int resource0lock_st_id3 : 3;
        unsigned int resource0lock_st4 : 1;
        unsigned int resource0lock_st_id4 : 3;
        unsigned int resource0lock_st5 : 1;
        unsigned int resource0lock_st_id5 : 3;
        unsigned int resource0lock_st6 : 1;
        unsigned int resource0lock_st_id6 : 3;
        unsigned int resource0lock_st7 : 1;
        unsigned int resource0lock_st_id7 : 3;
    } reg;
} SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_UNION;
#endif
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st0_START (0)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st0_END (0)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st_id0_START (1)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st_id0_END (3)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st1_START (4)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st1_END (4)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st_id1_START (5)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st_id1_END (7)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st2_START (8)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st2_END (8)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st_id2_START (9)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st_id2_END (11)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st3_START (12)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st3_END (12)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st_id3_START (13)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st_id3_END (15)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st4_START (16)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st4_END (16)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st_id4_START (17)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st_id4_END (19)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st5_START (20)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st5_END (20)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st_id5_START (21)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st_id5_END (23)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st6_START (24)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st6_END (24)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st_id6_START (25)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st_id6_END (27)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st7_START (28)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st7_END (28)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st_id7_START (29)
#define SOC_PMCTRL_XPU_XPU_PMC_LOCK_STAT_0_resource0lock_st_id7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spmi_hold_time : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_XPU_SPMI_HOLD_TIME_UNION;
#endif
#define SOC_PMCTRL_XPU_SPMI_HOLD_TIME_spmi_hold_time_START (0)
#define SOC_PMCTRL_XPU_SPMI_HOLD_TIME_spmi_hold_time_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_a_channel0 : 15;
        unsigned int freq_vote_a0_msk0 : 1;
        unsigned int freq_vote_a_channel1 : 15;
        unsigned int freq_vote_a0_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_A0_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_A0_freq_vote_a_channel0_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_A0_freq_vote_a_channel0_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_A0_freq_vote_a0_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_A0_freq_vote_a0_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_A0_freq_vote_a_channel1_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_A0_freq_vote_a_channel1_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_A0_freq_vote_a0_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_A0_freq_vote_a0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_a_channel2 : 15;
        unsigned int freq_vote_a1_msk0 : 1;
        unsigned int freq_vote_a_channel3 : 15;
        unsigned int freq_vote_a1_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_A1_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_A1_freq_vote_a_channel2_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_A1_freq_vote_a_channel2_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_A1_freq_vote_a1_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_A1_freq_vote_a1_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_A1_freq_vote_a_channel3_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_A1_freq_vote_a_channel3_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_A1_freq_vote_a1_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_A1_freq_vote_a1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_b_channel0 : 15;
        unsigned int freq_vote_b0_msk0 : 1;
        unsigned int freq_vote_b_channel1 : 15;
        unsigned int freq_vote_b0_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_B0_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_B0_freq_vote_b_channel0_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_B0_freq_vote_b_channel0_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_B0_freq_vote_b0_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_B0_freq_vote_b0_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_B0_freq_vote_b_channel1_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_B0_freq_vote_b_channel1_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_B0_freq_vote_b0_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_B0_freq_vote_b0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_b_channel2 : 15;
        unsigned int freq_vote_b1_msk0 : 1;
        unsigned int freq_vote_b_channel3 : 15;
        unsigned int freq_vote_b1_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_B1_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_B1_freq_vote_b_channel2_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_B1_freq_vote_b_channel2_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_B1_freq_vote_b1_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_B1_freq_vote_b1_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_B1_freq_vote_b_channel3_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_B1_freq_vote_b_channel3_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_B1_freq_vote_b1_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_B1_freq_vote_b1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_c_channel0 : 15;
        unsigned int freq_vote_c0_msk0 : 1;
        unsigned int freq_vote_c_channel1 : 15;
        unsigned int freq_vote_c0_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_C0_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_C0_freq_vote_c_channel0_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_C0_freq_vote_c_channel0_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_C0_freq_vote_c0_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_C0_freq_vote_c0_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_C0_freq_vote_c_channel1_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_C0_freq_vote_c_channel1_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_C0_freq_vote_c0_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_C0_freq_vote_c0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_c_channel2 : 15;
        unsigned int freq_vote_c1_msk0 : 1;
        unsigned int freq_vote_c_channel3 : 15;
        unsigned int freq_vote_c1_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_C1_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_C1_freq_vote_c_channel2_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_C1_freq_vote_c_channel2_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_C1_freq_vote_c1_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_C1_freq_vote_c1_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_C1_freq_vote_c_channel3_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_C1_freq_vote_c_channel3_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_C1_freq_vote_c1_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_C1_freq_vote_c1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_d_channel0 : 15;
        unsigned int freq_vote_d0_msk0 : 1;
        unsigned int freq_vote_d_channel1 : 15;
        unsigned int freq_vote_d0_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_D0_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_D0_freq_vote_d_channel0_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_D0_freq_vote_d_channel0_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_D0_freq_vote_d0_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_D0_freq_vote_d0_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_D0_freq_vote_d_channel1_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_D0_freq_vote_d_channel1_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_D0_freq_vote_d0_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_D0_freq_vote_d0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_d_channel2 : 15;
        unsigned int freq_vote_d1_msk0 : 1;
        unsigned int freq_vote_d_channel3 : 15;
        unsigned int freq_vote_d1_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_D1_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_D1_freq_vote_d_channel2_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_D1_freq_vote_d_channel2_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_D1_freq_vote_d1_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_D1_freq_vote_d1_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_D1_freq_vote_d_channel3_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_D1_freq_vote_d_channel3_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_D1_freq_vote_d1_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_D1_freq_vote_d1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_e_channel0 : 15;
        unsigned int freq_vote_e0_msk0 : 1;
        unsigned int freq_vote_e_channel1 : 15;
        unsigned int freq_vote_e0_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_E0_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_E0_freq_vote_e_channel0_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_E0_freq_vote_e_channel0_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_E0_freq_vote_e0_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_E0_freq_vote_e0_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_E0_freq_vote_e_channel1_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_E0_freq_vote_e_channel1_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_E0_freq_vote_e0_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_E0_freq_vote_e0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_e_channel2 : 15;
        unsigned int freq_vote_e1_msk0 : 1;
        unsigned int freq_vote_e_channel3 : 15;
        unsigned int freq_vote_e1_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_E1_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_E1_freq_vote_e_channel2_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_E1_freq_vote_e_channel2_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_E1_freq_vote_e1_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_E1_freq_vote_e1_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_E1_freq_vote_e_channel3_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_E1_freq_vote_e_channel3_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_E1_freq_vote_e1_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_E1_freq_vote_e1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_e_channel4 : 15;
        unsigned int freq_vote_e2_msk0 : 1;
        unsigned int freq_vote_e_channel5 : 15;
        unsigned int freq_vote_e2_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_E2_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_E2_freq_vote_e_channel4_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_E2_freq_vote_e_channel4_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_E2_freq_vote_e2_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_E2_freq_vote_e2_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_E2_freq_vote_e_channel5_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_E2_freq_vote_e_channel5_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_E2_freq_vote_e2_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_E2_freq_vote_e2_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_e_channel6 : 15;
        unsigned int freq_vote_e3_msk0 : 1;
        unsigned int freq_vote_e_channel7 : 15;
        unsigned int freq_vote_e3_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_E3_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_E3_freq_vote_e_channel6_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_E3_freq_vote_e_channel6_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_E3_freq_vote_e3_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_E3_freq_vote_e3_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_E3_freq_vote_e_channel7_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_E3_freq_vote_e_channel7_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_E3_freq_vote_e3_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_E3_freq_vote_e3_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_f_channel0 : 15;
        unsigned int freq_vote_f0_msk0 : 1;
        unsigned int freq_vote_f_channel1 : 15;
        unsigned int freq_vote_f0_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_F0_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_F0_freq_vote_f_channel0_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_F0_freq_vote_f_channel0_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_F0_freq_vote_f0_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_F0_freq_vote_f0_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_F0_freq_vote_f_channel1_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_F0_freq_vote_f_channel1_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_F0_freq_vote_f0_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_F0_freq_vote_f0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_f_channel2 : 15;
        unsigned int freq_vote_f1_msk0 : 1;
        unsigned int freq_vote_f_channel3 : 15;
        unsigned int freq_vote_f1_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_F1_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_F1_freq_vote_f_channel2_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_F1_freq_vote_f_channel2_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_F1_freq_vote_f1_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_F1_freq_vote_f1_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_F1_freq_vote_f_channel3_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_F1_freq_vote_f_channel3_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_F1_freq_vote_f1_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_F1_freq_vote_f1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_f_channel4 : 15;
        unsigned int freq_vote_f2_msk0 : 1;
        unsigned int freq_vote_f_channel5 : 15;
        unsigned int freq_vote_f2_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_F2_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_F2_freq_vote_f_channel4_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_F2_freq_vote_f_channel4_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_F2_freq_vote_f2_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_F2_freq_vote_f2_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_F2_freq_vote_f_channel5_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_F2_freq_vote_f_channel5_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_F2_freq_vote_f2_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_F2_freq_vote_f2_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_f_channel6 : 15;
        unsigned int freq_vote_f3_msk0 : 1;
        unsigned int freq_vote_f_channel7 : 15;
        unsigned int freq_vote_f3_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_F3_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_F3_freq_vote_f_channel6_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_F3_freq_vote_f_channel6_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_F3_freq_vote_f3_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_F3_freq_vote_f3_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_F3_freq_vote_f_channel7_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_F3_freq_vote_f_channel7_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_F3_freq_vote_f3_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_F3_freq_vote_f3_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_g_channel0 : 15;
        unsigned int freq_vote_g0_msk0 : 1;
        unsigned int freq_vote_g_channel1 : 15;
        unsigned int freq_vote_g0_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_G0_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_G0_freq_vote_g_channel0_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_G0_freq_vote_g_channel0_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_G0_freq_vote_g0_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_G0_freq_vote_g0_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_G0_freq_vote_g_channel1_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_G0_freq_vote_g_channel1_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_G0_freq_vote_g0_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_G0_freq_vote_g0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_g_channel2 : 15;
        unsigned int freq_vote_g1_msk0 : 1;
        unsigned int freq_vote_g_channel3 : 15;
        unsigned int freq_vote_g1_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_G1_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_G1_freq_vote_g_channel2_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_G1_freq_vote_g_channel2_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_G1_freq_vote_g1_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_G1_freq_vote_g1_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_G1_freq_vote_g_channel3_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_G1_freq_vote_g_channel3_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_G1_freq_vote_g1_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_G1_freq_vote_g1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_g_channel4 : 15;
        unsigned int freq_vote_g2_msk0 : 1;
        unsigned int freq_vote_g_channel5 : 15;
        unsigned int freq_vote_g2_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_G2_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_G2_freq_vote_g_channel4_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_G2_freq_vote_g_channel4_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_G2_freq_vote_g2_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_G2_freq_vote_g2_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_G2_freq_vote_g_channel5_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_G2_freq_vote_g_channel5_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_G2_freq_vote_g2_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_G2_freq_vote_g2_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_g_channel6 : 15;
        unsigned int freq_vote_g3_msk0 : 1;
        unsigned int freq_vote_g_channel7 : 15;
        unsigned int freq_vote_g3_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_G3_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_G3_freq_vote_g_channel6_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_G3_freq_vote_g_channel6_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_G3_freq_vote_g3_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_G3_freq_vote_g3_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_G3_freq_vote_g_channel7_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_G3_freq_vote_g_channel7_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_G3_freq_vote_g3_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_G3_freq_vote_g3_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_h_channel0 : 15;
        unsigned int freq_vote_h0_msk0 : 1;
        unsigned int freq_vote_h_channel1 : 15;
        unsigned int freq_vote_h0_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_H0_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_H0_freq_vote_h_channel0_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_H0_freq_vote_h_channel0_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_H0_freq_vote_h0_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_H0_freq_vote_h0_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_H0_freq_vote_h_channel1_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_H0_freq_vote_h_channel1_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_H0_freq_vote_h0_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_H0_freq_vote_h0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_h_channel2 : 15;
        unsigned int freq_vote_h1_msk0 : 1;
        unsigned int freq_vote_h_channel3 : 15;
        unsigned int freq_vote_h1_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_H1_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_H1_freq_vote_h_channel2_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_H1_freq_vote_h_channel2_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_H1_freq_vote_h1_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_H1_freq_vote_h1_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_H1_freq_vote_h_channel3_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_H1_freq_vote_h_channel3_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_H1_freq_vote_h1_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_H1_freq_vote_h1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_h_channel4 : 15;
        unsigned int freq_vote_h2_msk0 : 1;
        unsigned int freq_vote_h_channel5 : 15;
        unsigned int freq_vote_h2_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_H2_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_H2_freq_vote_h_channel4_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_H2_freq_vote_h_channel4_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_H2_freq_vote_h2_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_H2_freq_vote_h2_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_H2_freq_vote_h_channel5_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_H2_freq_vote_h_channel5_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_H2_freq_vote_h2_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_H2_freq_vote_h2_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_h_channel6 : 15;
        unsigned int freq_vote_h3_msk0 : 1;
        unsigned int freq_vote_h_channel7 : 15;
        unsigned int freq_vote_h3_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_H3_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_H3_freq_vote_h_channel6_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_H3_freq_vote_h_channel6_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_H3_freq_vote_h3_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_H3_freq_vote_h3_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_H3_freq_vote_h_channel7_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_H3_freq_vote_h_channel7_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_H3_freq_vote_h3_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_H3_freq_vote_h3_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_i_channel0 : 15;
        unsigned int freq_vote_i0_msk0 : 1;
        unsigned int freq_vote_i_channel1 : 15;
        unsigned int freq_vote_i0_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_I0_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_I0_freq_vote_i_channel0_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_I0_freq_vote_i_channel0_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_I0_freq_vote_i0_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_I0_freq_vote_i0_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_I0_freq_vote_i_channel1_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_I0_freq_vote_i_channel1_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_I0_freq_vote_i0_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_I0_freq_vote_i0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_i_channel2 : 15;
        unsigned int freq_vote_i1_msk0 : 1;
        unsigned int freq_vote_i_channel3 : 15;
        unsigned int freq_vote_i1_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_I1_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_I1_freq_vote_i_channel2_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_I1_freq_vote_i_channel2_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_I1_freq_vote_i1_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_I1_freq_vote_i1_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_I1_freq_vote_i_channel3_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_I1_freq_vote_i_channel3_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_I1_freq_vote_i1_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_I1_freq_vote_i1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_j_channel0 : 15;
        unsigned int freq_vote_j0_msk0 : 1;
        unsigned int freq_vote_j_channel1 : 15;
        unsigned int freq_vote_j0_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_J0_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_J0_freq_vote_j_channel0_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_J0_freq_vote_j_channel0_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_J0_freq_vote_j0_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_J0_freq_vote_j0_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_J0_freq_vote_j_channel1_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_J0_freq_vote_j_channel1_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_J0_freq_vote_j0_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_J0_freq_vote_j0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_j_channel2 : 15;
        unsigned int freq_vote_j1_msk0 : 1;
        unsigned int freq_vote_j_channel3 : 15;
        unsigned int freq_vote_j1_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_J1_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_J1_freq_vote_j_channel2_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_J1_freq_vote_j_channel2_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_J1_freq_vote_j1_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_J1_freq_vote_j1_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_J1_freq_vote_j_channel3_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_J1_freq_vote_j_channel3_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_J1_freq_vote_j1_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_J1_freq_vote_j1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_k_channel0 : 15;
        unsigned int freq_vote_k0_msk0 : 1;
        unsigned int freq_vote_k_channel1 : 15;
        unsigned int freq_vote_k0_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_K0_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_K0_freq_vote_k_channel0_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_K0_freq_vote_k_channel0_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_K0_freq_vote_k0_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_K0_freq_vote_k0_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_K0_freq_vote_k_channel1_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_K0_freq_vote_k_channel1_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_K0_freq_vote_k0_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_K0_freq_vote_k0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_k_channel2 : 15;
        unsigned int freq_vote_k1_msk0 : 1;
        unsigned int freq_vote_k_channel3 : 15;
        unsigned int freq_vote_k1_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_K1_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_K1_freq_vote_k_channel2_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_K1_freq_vote_k_channel2_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_K1_freq_vote_k1_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_K1_freq_vote_k1_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_K1_freq_vote_k_channel3_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_K1_freq_vote_k_channel3_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_K1_freq_vote_k1_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_K1_freq_vote_k1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_l_channel0 : 15;
        unsigned int freq_vote_l0_msk0 : 1;
        unsigned int freq_vote_l_channel1 : 15;
        unsigned int freq_vote_l0_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_L0_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_L0_freq_vote_l_channel0_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_L0_freq_vote_l_channel0_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_L0_freq_vote_l0_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_L0_freq_vote_l0_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_L0_freq_vote_l_channel1_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_L0_freq_vote_l_channel1_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_L0_freq_vote_l0_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_L0_freq_vote_l0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_l_channel2 : 15;
        unsigned int freq_vote_l1_msk0 : 1;
        unsigned int freq_vote_l_channel3 : 15;
        unsigned int freq_vote_l1_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_L1_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_L1_freq_vote_l_channel2_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_L1_freq_vote_l_channel2_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_L1_freq_vote_l1_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_L1_freq_vote_l1_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_L1_freq_vote_l_channel3_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_L1_freq_vote_l_channel3_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_L1_freq_vote_l1_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_L1_freq_vote_l1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_m_channel0 : 15;
        unsigned int freq_vote_m0_msk0 : 1;
        unsigned int freq_vote_m_channel1 : 15;
        unsigned int freq_vote_m0_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_M0_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_M0_freq_vote_m_channel0_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_M0_freq_vote_m_channel0_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_M0_freq_vote_m0_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_M0_freq_vote_m0_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_M0_freq_vote_m_channel1_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_M0_freq_vote_m_channel1_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_M0_freq_vote_m0_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_M0_freq_vote_m0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_m_channel2 : 15;
        unsigned int freq_vote_m1_msk0 : 1;
        unsigned int freq_vote_m_channel3 : 15;
        unsigned int freq_vote_m1_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_M1_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_M1_freq_vote_m_channel2_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_M1_freq_vote_m_channel2_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_M1_freq_vote_m1_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_M1_freq_vote_m1_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_M1_freq_vote_m_channel3_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_M1_freq_vote_m_channel3_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_M1_freq_vote_m1_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_M1_freq_vote_m1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_m_channel4 : 15;
        unsigned int freq_vote_m2_msk0 : 1;
        unsigned int freq_vote_m_channel5 : 15;
        unsigned int freq_vote_m2_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_M2_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_M2_freq_vote_m_channel4_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_M2_freq_vote_m_channel4_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_M2_freq_vote_m2_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_M2_freq_vote_m2_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_M2_freq_vote_m_channel5_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_M2_freq_vote_m_channel5_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_M2_freq_vote_m2_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_M2_freq_vote_m2_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_m_channel6 : 15;
        unsigned int freq_vote_m3_msk0 : 1;
        unsigned int freq_vote_m_channel7 : 15;
        unsigned int freq_vote_m3_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_M3_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_M3_freq_vote_m_channel6_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_M3_freq_vote_m_channel6_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_M3_freq_vote_m3_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_M3_freq_vote_m3_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_M3_freq_vote_m_channel7_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_M3_freq_vote_m_channel7_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_M3_freq_vote_m3_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_M3_freq_vote_m3_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_n_channel0 : 15;
        unsigned int freq_vote_n0_msk0 : 1;
        unsigned int freq_vote_n_channel1 : 15;
        unsigned int freq_vote_n0_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_N0_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_N0_freq_vote_n_channel0_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_N0_freq_vote_n_channel0_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_N0_freq_vote_n0_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_N0_freq_vote_n0_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_N0_freq_vote_n_channel1_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_N0_freq_vote_n_channel1_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_N0_freq_vote_n0_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_N0_freq_vote_n0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_n_channel2 : 15;
        unsigned int freq_vote_n1_msk0 : 1;
        unsigned int freq_vote_n_channel3 : 15;
        unsigned int freq_vote_n1_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_N1_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_N1_freq_vote_n_channel2_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_N1_freq_vote_n_channel2_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_N1_freq_vote_n1_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_N1_freq_vote_n1_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_N1_freq_vote_n_channel3_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_N1_freq_vote_n_channel3_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_N1_freq_vote_n1_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_N1_freq_vote_n1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_n_channel4 : 15;
        unsigned int freq_vote_n2_msk0 : 1;
        unsigned int freq_vote_n_channel5 : 15;
        unsigned int freq_vote_n2_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_N2_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_N2_freq_vote_n_channel4_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_N2_freq_vote_n_channel4_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_N2_freq_vote_n2_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_N2_freq_vote_n2_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_N2_freq_vote_n_channel5_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_N2_freq_vote_n_channel5_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_N2_freq_vote_n2_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_N2_freq_vote_n2_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_n_channel6 : 15;
        unsigned int freq_vote_n3_msk0 : 1;
        unsigned int freq_vote_n_channel7 : 15;
        unsigned int freq_vote_n3_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_N3_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_N3_freq_vote_n_channel6_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_N3_freq_vote_n_channel6_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_N3_freq_vote_n3_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_N3_freq_vote_n3_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_N3_freq_vote_n_channel7_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_N3_freq_vote_n_channel7_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_N3_freq_vote_n3_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_N3_freq_vote_n3_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_o_channel0 : 15;
        unsigned int freq_vote_o0_msk0 : 1;
        unsigned int freq_vote_o_channel1 : 15;
        unsigned int freq_vote_o0_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_O0_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_O0_freq_vote_o_channel0_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_O0_freq_vote_o_channel0_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_O0_freq_vote_o0_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_O0_freq_vote_o0_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_O0_freq_vote_o_channel1_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_O0_freq_vote_o_channel1_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_O0_freq_vote_o0_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_O0_freq_vote_o0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_o_channel2 : 15;
        unsigned int freq_vote_o1_msk0 : 1;
        unsigned int freq_vote_o_channel3 : 15;
        unsigned int freq_vote_o1_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_O1_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_O1_freq_vote_o_channel2_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_O1_freq_vote_o_channel2_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_O1_freq_vote_o1_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_O1_freq_vote_o1_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_O1_freq_vote_o_channel3_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_O1_freq_vote_o_channel3_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_O1_freq_vote_o1_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_O1_freq_vote_o1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_o_channel4 : 15;
        unsigned int freq_vote_o2_msk0 : 1;
        unsigned int freq_vote_o_channel5 : 15;
        unsigned int freq_vote_o2_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_O2_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_O2_freq_vote_o_channel4_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_O2_freq_vote_o_channel4_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_O2_freq_vote_o2_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_O2_freq_vote_o2_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_O2_freq_vote_o_channel5_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_O2_freq_vote_o_channel5_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_O2_freq_vote_o2_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_O2_freq_vote_o2_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_o_channel6 : 15;
        unsigned int freq_vote_o3_msk0 : 1;
        unsigned int freq_vote_o_channel7 : 15;
        unsigned int freq_vote_o3_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_O3_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_O3_freq_vote_o_channel6_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_O3_freq_vote_o_channel6_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_O3_freq_vote_o3_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_O3_freq_vote_o3_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_O3_freq_vote_o_channel7_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_O3_freq_vote_o_channel7_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_O3_freq_vote_o3_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_O3_freq_vote_o3_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_p_channel0 : 15;
        unsigned int freq_vote_p0_msk0 : 1;
        unsigned int freq_vote_p_channel1 : 15;
        unsigned int freq_vote_p0_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_P0_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_P0_freq_vote_p_channel0_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_P0_freq_vote_p_channel0_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_P0_freq_vote_p0_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_P0_freq_vote_p0_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_P0_freq_vote_p_channel1_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_P0_freq_vote_p_channel1_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_P0_freq_vote_p0_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_P0_freq_vote_p0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_p_channel2 : 15;
        unsigned int freq_vote_p1_msk0 : 1;
        unsigned int freq_vote_p_channel3 : 15;
        unsigned int freq_vote_p1_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_P1_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_P1_freq_vote_p_channel2_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_P1_freq_vote_p_channel2_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_P1_freq_vote_p1_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_P1_freq_vote_p1_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_P1_freq_vote_p_channel3_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_P1_freq_vote_p_channel3_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_P1_freq_vote_p1_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_P1_freq_vote_p1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_p_channel4 : 15;
        unsigned int freq_vote_p2_msk0 : 1;
        unsigned int freq_vote_p_channel5 : 15;
        unsigned int freq_vote_p2_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_P2_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_P2_freq_vote_p_channel4_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_P2_freq_vote_p_channel4_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_P2_freq_vote_p2_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_P2_freq_vote_p2_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_P2_freq_vote_p_channel5_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_P2_freq_vote_p_channel5_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_P2_freq_vote_p2_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_P2_freq_vote_p2_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_p_channel6 : 15;
        unsigned int freq_vote_p3_msk0 : 1;
        unsigned int freq_vote_p_channel7 : 15;
        unsigned int freq_vote_p3_msk1 : 1;
    } reg;
} SOC_PMCTRL_XPU_FREQ_VOTE_P3_UNION;
#endif
#define SOC_PMCTRL_XPU_FREQ_VOTE_P3_freq_vote_p_channel6_START (0)
#define SOC_PMCTRL_XPU_FREQ_VOTE_P3_freq_vote_p_channel6_END (14)
#define SOC_PMCTRL_XPU_FREQ_VOTE_P3_freq_vote_p3_msk0_START (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_P3_freq_vote_p3_msk0_END (15)
#define SOC_PMCTRL_XPU_FREQ_VOTE_P3_freq_vote_p_channel7_START (16)
#define SOC_PMCTRL_XPU_FREQ_VOTE_P3_freq_vote_p_channel7_END (30)
#define SOC_PMCTRL_XPU_FREQ_VOTE_P3_freq_vote_p3_msk1_START (31)
#define SOC_PMCTRL_XPU_FREQ_VOTE_P3_freq_vote_p3_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int int_freq_vote_raw_stat_a : 1;
        unsigned int int_freq_vote_raw_stat_b : 1;
        unsigned int int_freq_vote_raw_stat_c : 1;
        unsigned int int_freq_vote_raw_stat_d : 1;
        unsigned int int_freq_vote_raw_stat_e : 1;
        unsigned int int_freq_vote_raw_stat_f : 1;
        unsigned int int_freq_vote_raw_stat_g : 1;
        unsigned int int_freq_vote_raw_stat_h : 1;
        unsigned int int_freq_vote_raw_stat_i : 1;
        unsigned int int_freq_vote_raw_stat_j : 1;
        unsigned int int_freq_vote_raw_stat_k : 1;
        unsigned int int_freq_vote_raw_stat_l : 1;
        unsigned int int_freq_vote_raw_stat_m : 1;
        unsigned int int_freq_vote_raw_stat_n : 1;
        unsigned int int_freq_vote_raw_stat_o : 1;
        unsigned int int_freq_vote_raw_stat_p : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_UNION;
#endif
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_a_START (0)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_a_END (0)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_b_START (1)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_b_END (1)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_c_START (2)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_c_END (2)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_d_START (3)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_d_END (3)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_e_START (4)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_e_END (4)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_f_START (5)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_f_END (5)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_g_START (6)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_g_END (6)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_h_START (7)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_h_END (7)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_i_START (8)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_i_END (8)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_j_START (9)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_j_END (9)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_k_START (10)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_k_END (10)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_l_START (11)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_l_END (11)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_m_START (12)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_m_END (12)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_n_START (13)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_n_END (13)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_o_START (14)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_o_END (14)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_p_START (15)
#define SOC_PMCTRL_XPU_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_p_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int int_freq_vote_stat_a : 1;
        unsigned int int_freq_vote_stat_b : 1;
        unsigned int int_freq_vote_stat_c : 1;
        unsigned int int_freq_vote_stat_d : 1;
        unsigned int int_freq_vote_stat_e : 1;
        unsigned int int_freq_vote_stat_f : 1;
        unsigned int int_freq_vote_stat_g : 1;
        unsigned int int_freq_vote_stat_h : 1;
        unsigned int int_freq_vote_stat_i : 1;
        unsigned int int_freq_vote_stat_j : 1;
        unsigned int int_freq_vote_stat_k : 1;
        unsigned int int_freq_vote_stat_l : 1;
        unsigned int int_freq_vote_stat_m : 1;
        unsigned int int_freq_vote_stat_n : 1;
        unsigned int int_freq_vote_stat_o : 1;
        unsigned int int_freq_vote_stat_p : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_PMCTRL_XPU_INT_VOTE_STAT_UNION;
#endif
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_a_START (0)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_a_END (0)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_b_START (1)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_b_END (1)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_c_START (2)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_c_END (2)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_d_START (3)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_d_END (3)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_e_START (4)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_e_END (4)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_f_START (5)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_f_END (5)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_g_START (6)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_g_END (6)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_h_START (7)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_h_END (7)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_i_START (8)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_i_END (8)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_j_START (9)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_j_END (9)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_k_START (10)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_k_END (10)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_l_START (11)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_l_END (11)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_m_START (12)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_m_END (12)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_n_START (13)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_n_END (13)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_o_START (14)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_o_END (14)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_p_START (15)
#define SOC_PMCTRL_XPU_INT_VOTE_STAT_int_freq_vote_stat_p_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int int_frequency_vote_mask_to_lpmcu_a_i : 16;
        unsigned int int_frequency_vote_mask_to_lpmcu_j_p : 16;
    } reg;
} SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_MASK_0_UNION;
#endif
#define SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_MASK_0_int_frequency_vote_mask_to_lpmcu_a_i_START (0)
#define SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_MASK_0_int_frequency_vote_mask_to_lpmcu_a_i_END (15)
#define SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_MASK_0_int_frequency_vote_mask_to_lpmcu_j_p_START (16)
#define SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_MASK_0_int_frequency_vote_mask_to_lpmcu_j_p_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int int_frequency_vote_mask_to_xpu_lp_ctrl_a_i : 16;
        unsigned int int_frequency_vote_mask_to_xpu_lp_ctrl_j_p : 16;
    } reg;
} SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_MASK_1_UNION;
#endif
#define SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_MASK_1_int_frequency_vote_mask_to_xpu_lp_ctrl_a_i_START (0)
#define SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_MASK_1_int_frequency_vote_mask_to_xpu_lp_ctrl_a_i_END (15)
#define SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_MASK_1_int_frequency_vote_mask_to_xpu_lp_ctrl_j_p_START (16)
#define SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_MASK_1_int_frequency_vote_mask_to_xpu_lp_ctrl_j_p_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int int_frequency_vote_mask_to_acpu_a_i : 16;
        unsigned int int_frequency_vote_mask_to_acpu_j_p : 16;
    } reg;
} SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_MASK_2_UNION;
#endif
#define SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_MASK_2_int_frequency_vote_mask_to_acpu_a_i_START (0)
#define SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_MASK_2_int_frequency_vote_mask_to_acpu_a_i_END (15)
#define SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_MASK_2_int_frequency_vote_mask_to_acpu_j_p_START (16)
#define SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_MASK_2_int_frequency_vote_mask_to_acpu_j_p_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int int_frequency_vote : 1;
        unsigned int int_frequency_vote_to_acpu : 1;
        unsigned int int_frequency_vote_to_xpu_lp_ctrl : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_UNION;
#endif
#define SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_int_frequency_vote_to_lpmcu_START (0)
#define SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_int_frequency_vote_to_lpmcu_END (0)
#define SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_int_frequency_vote_to_acpu_START (1)
#define SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_int_frequency_vote_to_acpu_END (1)
#define SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_int_frequency_vote_to_xpu_lp_ctrl_START (2)
#define SOC_PMCTRL_XPU_INT_FREQUENCY_VOTE_int_frequency_vote_to_xpu_lp_ctrl_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_result_a : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_XPU_VOTE_RESULT_A_UNION;
#endif
#define SOC_PMCTRL_XPU_VOTE_RESULT_A_freq_vote_result_a_START (0)
#define SOC_PMCTRL_XPU_VOTE_RESULT_A_freq_vote_result_a_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_result_b : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_XPU_VOTE_RESULT_B_UNION;
#endif
#define SOC_PMCTRL_XPU_VOTE_RESULT_B_freq_vote_result_b_START (0)
#define SOC_PMCTRL_XPU_VOTE_RESULT_B_freq_vote_result_b_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_result_c : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_XPU_VOTE_RESULT_C_UNION;
#endif
#define SOC_PMCTRL_XPU_VOTE_RESULT_C_freq_vote_result_c_START (0)
#define SOC_PMCTRL_XPU_VOTE_RESULT_C_freq_vote_result_c_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_result_d : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_XPU_VOTE_RESULT_D_UNION;
#endif
#define SOC_PMCTRL_XPU_VOTE_RESULT_D_freq_vote_result_d_START (0)
#define SOC_PMCTRL_XPU_VOTE_RESULT_D_freq_vote_result_d_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_result_e : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_XPU_VOTE_RESULT_E_UNION;
#endif
#define SOC_PMCTRL_XPU_VOTE_RESULT_E_freq_vote_result_e_START (0)
#define SOC_PMCTRL_XPU_VOTE_RESULT_E_freq_vote_result_e_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_result_f : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_XPU_VOTE_RESULT_F_UNION;
#endif
#define SOC_PMCTRL_XPU_VOTE_RESULT_F_freq_vote_result_f_START (0)
#define SOC_PMCTRL_XPU_VOTE_RESULT_F_freq_vote_result_f_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_result_g : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_XPU_VOTE_RESULT_G_UNION;
#endif
#define SOC_PMCTRL_XPU_VOTE_RESULT_G_freq_vote_result_g_START (0)
#define SOC_PMCTRL_XPU_VOTE_RESULT_G_freq_vote_result_g_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_result_h : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_XPU_VOTE_RESULT_H_UNION;
#endif
#define SOC_PMCTRL_XPU_VOTE_RESULT_H_freq_vote_result_h_START (0)
#define SOC_PMCTRL_XPU_VOTE_RESULT_H_freq_vote_result_h_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_result_i : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_XPU_VOTE_RESULT_I_UNION;
#endif
#define SOC_PMCTRL_XPU_VOTE_RESULT_I_freq_vote_result_i_START (0)
#define SOC_PMCTRL_XPU_VOTE_RESULT_I_freq_vote_result_i_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_result_j : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_XPU_VOTE_RESULT_J_UNION;
#endif
#define SOC_PMCTRL_XPU_VOTE_RESULT_J_freq_vote_result_j_START (0)
#define SOC_PMCTRL_XPU_VOTE_RESULT_J_freq_vote_result_j_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_result_k : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_XPU_VOTE_RESULT_K_UNION;
#endif
#define SOC_PMCTRL_XPU_VOTE_RESULT_K_freq_vote_result_k_START (0)
#define SOC_PMCTRL_XPU_VOTE_RESULT_K_freq_vote_result_k_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_result_l : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_XPU_VOTE_RESULT_L_UNION;
#endif
#define SOC_PMCTRL_XPU_VOTE_RESULT_L_freq_vote_result_l_START (0)
#define SOC_PMCTRL_XPU_VOTE_RESULT_L_freq_vote_result_l_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_result_m : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_XPU_VOTE_RESULT_M_UNION;
#endif
#define SOC_PMCTRL_XPU_VOTE_RESULT_M_freq_vote_result_m_START (0)
#define SOC_PMCTRL_XPU_VOTE_RESULT_M_freq_vote_result_m_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_result_n : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_XPU_VOTE_RESULT_N_UNION;
#endif
#define SOC_PMCTRL_XPU_VOTE_RESULT_N_freq_vote_result_n_START (0)
#define SOC_PMCTRL_XPU_VOTE_RESULT_N_freq_vote_result_n_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_result_o : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_XPU_VOTE_RESULT_O_UNION;
#endif
#define SOC_PMCTRL_XPU_VOTE_RESULT_O_freq_vote_result_o_START (0)
#define SOC_PMCTRL_XPU_VOTE_RESULT_O_freq_vote_result_o_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_result_p : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_XPU_VOTE_RESULT_P_UNION;
#endif
#define SOC_PMCTRL_XPU_VOTE_RESULT_P_freq_vote_result_p_START (0)
#define SOC_PMCTRL_XPU_VOTE_RESULT_P_freq_vote_result_p_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_XPU_DVFSDATA0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_XPU_DVFSDATA1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_XPU_DVFSDATA2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_XPU_DVFSDATA3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_XPU_DVFSDATA4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_XPU_DVFSDATA5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_XPU_DVFSDATA6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_XPU_DVFSDATA7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_XPU_DVFSDATA8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_XPU_DVFSDATA9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_XPU_DVFSDATA10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_XPU_DVFSDATA11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_XPU_DVFSDATA12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_XPU_DVFSDATA13_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_XPU_DVFSDATA14_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_XPU_DVFSDATA15_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_XPU_DVFSDATA16_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_XPU_DVFSDATA17_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_XPU_DVFSDATA18_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_XPU_DVFSDATA19_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_XPU_DVFSDATA20_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_XPU_DVFSDATA21_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_XPU_DVFSDATA22_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lit_core0_pmtu_ret_vol_ctrl_bypass_cfg_ns : 1;
        unsigned int lit_core1_pmtu_ret_vol_ctrl_bypass_cfg_ns : 1;
        unsigned int lit_core2_pmtu_ret_vol_ctrl_bypass_cfg_ns : 1;
        unsigned int lit_core3_pmtu_ret_vol_ctrl_bypass_cfg_ns : 1;
        unsigned int eisc_dis_ctrl_en_apb : 1;
        unsigned int eisc_dis_ctrl_en_big_fsm : 1;
        unsigned int eisc_dis_ctrl_en_big_intr : 1;
        unsigned int eisc_dis_ctrl_en_lit_fsm : 1;
        unsigned int eisc_dis_ctrl_en_lit_intr : 1;
        unsigned int eisc_dis_ctrl_en_mid_fsm : 1;
        unsigned int eisc_dis_ctrl_en_mid_intr : 1;
        unsigned int little_core_bhs_ret_eiscmode_en : 1;
        unsigned int eisc_hw_clkgt_bypass_ns : 1;
        unsigned int eisc_hw_intr_mask_ctrl_bypass : 1;
        unsigned int eisc_hw_ret_ctrl_bypass_ns : 1;
        unsigned int reserved : 1;
        unsigned int eisc_common_ctrl_wmsk : 16;
    } reg;
} SOC_PMCTRL_XPU_DVFSDATA23_UNION;
#endif
#define SOC_PMCTRL_XPU_DVFSDATA23_lit_core0_pmtu_ret_vol_ctrl_bypass_cfg_ns_START (0)
#define SOC_PMCTRL_XPU_DVFSDATA23_lit_core0_pmtu_ret_vol_ctrl_bypass_cfg_ns_END (0)
#define SOC_PMCTRL_XPU_DVFSDATA23_lit_core1_pmtu_ret_vol_ctrl_bypass_cfg_ns_START (1)
#define SOC_PMCTRL_XPU_DVFSDATA23_lit_core1_pmtu_ret_vol_ctrl_bypass_cfg_ns_END (1)
#define SOC_PMCTRL_XPU_DVFSDATA23_lit_core2_pmtu_ret_vol_ctrl_bypass_cfg_ns_START (2)
#define SOC_PMCTRL_XPU_DVFSDATA23_lit_core2_pmtu_ret_vol_ctrl_bypass_cfg_ns_END (2)
#define SOC_PMCTRL_XPU_DVFSDATA23_lit_core3_pmtu_ret_vol_ctrl_bypass_cfg_ns_START (3)
#define SOC_PMCTRL_XPU_DVFSDATA23_lit_core3_pmtu_ret_vol_ctrl_bypass_cfg_ns_END (3)
#define SOC_PMCTRL_XPU_DVFSDATA23_eisc_dis_ctrl_en_apb_START (4)
#define SOC_PMCTRL_XPU_DVFSDATA23_eisc_dis_ctrl_en_apb_END (4)
#define SOC_PMCTRL_XPU_DVFSDATA23_eisc_dis_ctrl_en_big_fsm_START (5)
#define SOC_PMCTRL_XPU_DVFSDATA23_eisc_dis_ctrl_en_big_fsm_END (5)
#define SOC_PMCTRL_XPU_DVFSDATA23_eisc_dis_ctrl_en_big_intr_START (6)
#define SOC_PMCTRL_XPU_DVFSDATA23_eisc_dis_ctrl_en_big_intr_END (6)
#define SOC_PMCTRL_XPU_DVFSDATA23_eisc_dis_ctrl_en_lit_fsm_START (7)
#define SOC_PMCTRL_XPU_DVFSDATA23_eisc_dis_ctrl_en_lit_fsm_END (7)
#define SOC_PMCTRL_XPU_DVFSDATA23_eisc_dis_ctrl_en_lit_intr_START (8)
#define SOC_PMCTRL_XPU_DVFSDATA23_eisc_dis_ctrl_en_lit_intr_END (8)
#define SOC_PMCTRL_XPU_DVFSDATA23_eisc_dis_ctrl_en_mid_fsm_START (9)
#define SOC_PMCTRL_XPU_DVFSDATA23_eisc_dis_ctrl_en_mid_fsm_END (9)
#define SOC_PMCTRL_XPU_DVFSDATA23_eisc_dis_ctrl_en_mid_intr_START (10)
#define SOC_PMCTRL_XPU_DVFSDATA23_eisc_dis_ctrl_en_mid_intr_END (10)
#define SOC_PMCTRL_XPU_DVFSDATA23_little_core_bhs_ret_eiscmode_en_START (11)
#define SOC_PMCTRL_XPU_DVFSDATA23_little_core_bhs_ret_eiscmode_en_END (11)
#define SOC_PMCTRL_XPU_DVFSDATA23_eisc_hw_clkgt_bypass_ns_START (12)
#define SOC_PMCTRL_XPU_DVFSDATA23_eisc_hw_clkgt_bypass_ns_END (12)
#define SOC_PMCTRL_XPU_DVFSDATA23_eisc_hw_intr_mask_ctrl_bypass_START (13)
#define SOC_PMCTRL_XPU_DVFSDATA23_eisc_hw_intr_mask_ctrl_bypass_END (13)
#define SOC_PMCTRL_XPU_DVFSDATA23_eisc_hw_ret_ctrl_bypass_ns_START (14)
#define SOC_PMCTRL_XPU_DVFSDATA23_eisc_hw_ret_ctrl_bypass_ns_END (14)
#define SOC_PMCTRL_XPU_DVFSDATA23_eisc_common_ctrl_wmsk_START (16)
#define SOC_PMCTRL_XPU_DVFSDATA23_eisc_common_ctrl_wmsk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int eisc_common_ctrl_w1p_nc : 32;
    } reg;
} SOC_PMCTRL_XPU_DVFSDATA24_UNION;
#endif
#define SOC_PMCTRL_XPU_DVFSDATA24_eisc_common_ctrl_w1p_nc_START (0)
#define SOC_PMCTRL_XPU_DVFSDATA24_eisc_common_ctrl_w1p_nc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_code_cpul : 9;
        unsigned int temp_update_flag_cpul : 1;
        unsigned int temp_code_cpum0 : 9;
        unsigned int temp_update_flag_cpum0 : 1;
        unsigned int temp_code_cpum1 : 9;
        unsigned int temp_update_flag_cpum1 : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED0_UNION;
#endif
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED0_temp_code_cpul_START (0)
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED0_temp_code_cpul_END (8)
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED0_temp_update_flag_cpul_START (9)
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED0_temp_update_flag_cpul_END (9)
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED0_temp_code_cpum0_START (10)
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED0_temp_code_cpum0_END (18)
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED0_temp_update_flag_cpum0_START (19)
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED0_temp_update_flag_cpum0_END (19)
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED0_temp_code_cpum1_START (20)
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED0_temp_code_cpum1_END (28)
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED0_temp_update_flag_cpum1_START (29)
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED0_temp_update_flag_cpum1_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_code_cpum2 : 9;
        unsigned int temp_update_flag_cpum2 : 1;
        unsigned int temp_code_hc : 9;
        unsigned int temp_update_flag_hc : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED1_UNION;
#endif
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED1_temp_code_cpum2_START (0)
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED1_temp_code_cpum2_END (8)
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED1_temp_update_flag_cpum2_START (9)
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED1_temp_update_flag_cpum2_END (9)
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED1_temp_code_hc_START (10)
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED1_temp_code_hc_END (18)
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED1_temp_update_flag_hc_START (19)
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED1_temp_update_flag_hc_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int temp_code_cpub0 : 9;
        unsigned int temp_update_flag_cpub0 : 1;
        unsigned int temp_code_cpub1 : 9;
        unsigned int temp_update_flag_cpub1 : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED2_UNION;
#endif
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED2_temp_code_cpub0_START (0)
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED2_temp_code_cpub0_END (8)
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED2_temp_update_flag_cpub0_START (9)
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED2_temp_update_flag_cpub0_END (9)
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED2_temp_code_cpub1_START (10)
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED2_temp_code_cpub1_END (18)
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED2_temp_update_flag_cpub1_START (19)
#define SOC_PMCTRL_XPU_TEMPERATURE_TMP_RAED2_temp_update_flag_cpub1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int valid_temp_code_cpul : 9;
        unsigned int reserved_0 : 1;
        unsigned int valid_temp_code_cpum0 : 9;
        unsigned int reserved_1 : 1;
        unsigned int valid_temp_code_cpum1 : 9;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_PMCTRL_XPU_TEMPERATURE_VALID_STATUS0_UNION;
#endif
#define SOC_PMCTRL_XPU_TEMPERATURE_VALID_STATUS0_valid_temp_code_cpul_START (0)
#define SOC_PMCTRL_XPU_TEMPERATURE_VALID_STATUS0_valid_temp_code_cpul_END (8)
#define SOC_PMCTRL_XPU_TEMPERATURE_VALID_STATUS0_valid_temp_code_cpum0_START (10)
#define SOC_PMCTRL_XPU_TEMPERATURE_VALID_STATUS0_valid_temp_code_cpum0_END (18)
#define SOC_PMCTRL_XPU_TEMPERATURE_VALID_STATUS0_valid_temp_code_cpum1_START (20)
#define SOC_PMCTRL_XPU_TEMPERATURE_VALID_STATUS0_valid_temp_code_cpum1_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int valid_temp_code_cpum2 : 9;
        unsigned int reserved_0 : 1;
        unsigned int valid_temp_code_hc : 9;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 12;
    } reg;
} SOC_PMCTRL_XPU_TEMPERATURE_VALID_STATUS1_UNION;
#endif
#define SOC_PMCTRL_XPU_TEMPERATURE_VALID_STATUS1_valid_temp_code_cpum2_START (0)
#define SOC_PMCTRL_XPU_TEMPERATURE_VALID_STATUS1_valid_temp_code_cpum2_END (8)
#define SOC_PMCTRL_XPU_TEMPERATURE_VALID_STATUS1_valid_temp_code_hc_START (10)
#define SOC_PMCTRL_XPU_TEMPERATURE_VALID_STATUS1_valid_temp_code_hc_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int valid_temp_code_cpub0 : 9;
        unsigned int reserved_0 : 1;
        unsigned int valid_temp_code_cpub1 : 9;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 12;
    } reg;
} SOC_PMCTRL_XPU_TEMPERATURE_VALID_STATUS2_UNION;
#endif
#define SOC_PMCTRL_XPU_TEMPERATURE_VALID_STATUS2_valid_temp_code_cpub0_START (0)
#define SOC_PMCTRL_XPU_TEMPERATURE_VALID_STATUS2_valid_temp_code_cpub0_END (8)
#define SOC_PMCTRL_XPU_TEMPERATURE_VALID_STATUS2_valid_temp_code_cpub1_START (10)
#define SOC_PMCTRL_XPU_TEMPERATURE_VALID_STATUS2_valid_temp_code_cpub1_END (18)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
