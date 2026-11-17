#ifndef __SOC_PMCTRL_INTERFACE_H__
#define __SOC_PMCTRL_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_PMCTRL_PERIBAKDATA0_ADDR(base) ((base) + (0x930UL))
#define SOC_PMCTRL_PERIBAKDATA1_ADDR(base) ((base) + (0x934UL))
#define SOC_PMCTRL_PERIBAKDATA2_ADDR(base) ((base) + (0x938UL))
#define SOC_PMCTRL_PERIBAKDATA3_ADDR(base) ((base) + (0x93CUL))
#define SOC_PMCTRL_PERI_INTR_STAT_ADDR(base) ((base) + (0xC2CUL))
#define SOC_PMCTRL_FREQ_VOTE_A0_ADDR(base) ((base) + (0x200UL))
#define SOC_PMCTRL_FREQ_VOTE_A1_ADDR(base) ((base) + (0x204UL))
#define SOC_PMCTRL_FREQ_VOTE_B0_ADDR(base) ((base) + (0x208UL))
#define SOC_PMCTRL_FREQ_VOTE_B1_ADDR(base) ((base) + (0x20CUL))
#define SOC_PMCTRL_FREQ_VOTE_C0_ADDR(base) ((base) + (0x210UL))
#define SOC_PMCTRL_FREQ_VOTE_C1_ADDR(base) ((base) + (0x214UL))
#define SOC_PMCTRL_FREQ_VOTE_D0_ADDR(base) ((base) + (0x218UL))
#define SOC_PMCTRL_FREQ_VOTE_D1_ADDR(base) ((base) + (0x21CUL))
#define SOC_PMCTRL_FREQ_VOTE_E0_ADDR(base) ((base) + (0x220UL))
#define SOC_PMCTRL_FREQ_VOTE_E1_ADDR(base) ((base) + (0x224UL))
#define SOC_PMCTRL_FREQ_VOTE_E2_ADDR(base) ((base) + (0x228UL))
#define SOC_PMCTRL_FREQ_VOTE_E3_ADDR(base) ((base) + (0x22CUL))
#define SOC_PMCTRL_FREQ_VOTE_F0_ADDR(base) ((base) + (0x230UL))
#define SOC_PMCTRL_FREQ_VOTE_F1_ADDR(base) ((base) + (0x234UL))
#define SOC_PMCTRL_FREQ_VOTE_F2_ADDR(base) ((base) + (0x238UL))
#define SOC_PMCTRL_FREQ_VOTE_F3_ADDR(base) ((base) + (0x23CUL))
#define SOC_PMCTRL_FREQ_VOTE_G0_ADDR(base) ((base) + (0x240UL))
#define SOC_PMCTRL_FREQ_VOTE_G1_ADDR(base) ((base) + (0x244UL))
#define SOC_PMCTRL_FREQ_VOTE_G2_ADDR(base) ((base) + (0x248UL))
#define SOC_PMCTRL_FREQ_VOTE_G3_ADDR(base) ((base) + (0x24CUL))
#define SOC_PMCTRL_FREQ_VOTE_H0_ADDR(base) ((base) + (0x250UL))
#define SOC_PMCTRL_FREQ_VOTE_H1_ADDR(base) ((base) + (0x254UL))
#define SOC_PMCTRL_FREQ_VOTE_H2_ADDR(base) ((base) + (0x258UL))
#define SOC_PMCTRL_FREQ_VOTE_H3_ADDR(base) ((base) + (0x25CUL))
#define SOC_PMCTRL_FREQ_VOTE_H4_ADDR(base) ((base) + (0x260UL))
#define SOC_PMCTRL_FREQ_VOTE_H5_ADDR(base) ((base) + (0x264UL))
#define SOC_PMCTRL_FREQ_VOTE_H6_ADDR(base) ((base) + (0x268UL))
#define SOC_PMCTRL_FREQ_VOTE_H7_ADDR(base) ((base) + (0x26CUL))
#define SOC_PMCTRL_FREQ_VOTE_I0_ADDR(base) ((base) + (0x270UL))
#define SOC_PMCTRL_FREQ_VOTE_I1_ADDR(base) ((base) + (0x274UL))
#define SOC_PMCTRL_FREQ_VOTE_I2_ADDR(base) ((base) + (0x278UL))
#define SOC_PMCTRL_FREQ_VOTE_I3_ADDR(base) ((base) + (0x27CUL))
#define SOC_PMCTRL_FREQ_VOTE_I4_ADDR(base) ((base) + (0x280UL))
#define SOC_PMCTRL_FREQ_VOTE_I5_ADDR(base) ((base) + (0x284UL))
#define SOC_PMCTRL_FREQ_VOTE_I6_ADDR(base) ((base) + (0x288UL))
#define SOC_PMCTRL_FREQ_VOTE_I7_ADDR(base) ((base) + (0x28CUL))
#define SOC_PMCTRL_INTR_MASK_TO_LPMCU_A_I_ADDR(base) ((base) + (0x290UL))
#define SOC_PMCTRL_INTR_MASK_TO_CPU_LP_CTRL_A_I_ADDR(base) ((base) + (0x294UL))
#define SOC_PMCTRL_INTR_MASK_TO_GPU_LP_CTRL_A_I_ADDR(base) ((base) + (0x298UL))
#define SOC_PMCTRL_INTR_MASK_TO_DDR_LP_CTRL_A_I_ADDR(base) ((base) + (0x29CUL))
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_A_I_ADDR(base) ((base) + (0x2B0UL))
#define SOC_PMCTRL_VOTE_MODE_CFG_0_A_I_ADDR(base) ((base) + (0x2BCUL))
#define SOC_PMCTRL_VOTE_MODE_CFG_1_A_I_ADDR(base) ((base) + (0x2C0UL))
#define SOC_PMCTRL_VOTE_START_EN_A_I_ADDR(base) ((base) + (0x2C4UL))
#define SOC_PMCTRL_INT_VOTE_EN_A_I_ADDR(base) ((base) + (0x2C8UL))
#define SOC_PMCTRL_INT_VOTE_CLR_A_I_ADDR(base) ((base) + (0x2CCUL))
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_A_I_ADDR(base) ((base) + (0x2D0UL))
#define SOC_PMCTRL_INT_VOTE_STAT_A_I_ADDR(base) ((base) + (0x2D4UL))
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_A_I_ADDR(base) ((base) + (0x2D8UL))
#define SOC_PMCTRL_VOTE_RESULT_A_ADDR(base) ((base) + (0x2DCUL))
#define SOC_PMCTRL_VOTE_RESULT_B_ADDR(base) ((base) + (0x2E0UL))
#define SOC_PMCTRL_VOTE_RESULT_C_ADDR(base) ((base) + (0x2E4UL))
#define SOC_PMCTRL_VOTE_RESULT_D_ADDR(base) ((base) + (0x2E8UL))
#define SOC_PMCTRL_VOTE_RESULT_E_ADDR(base) ((base) + (0x2ECUL))
#define SOC_PMCTRL_VOTE_RESULT_F_ADDR(base) ((base) + (0x2F0UL))
#define SOC_PMCTRL_VOTE_RESULT_G_ADDR(base) ((base) + (0x2F4UL))
#define SOC_PMCTRL_VOTE_RESULT_H_ADDR(base) ((base) + (0x2F8UL))
#define SOC_PMCTRL_VOTE_RESULT_I_ADDR(base) ((base) + (0x2FCUL))
#define SOC_PMCTRL_FREQ_VOTE_J0_ADDR(base) ((base) + (0x600UL))
#define SOC_PMCTRL_FREQ_VOTE_J1_ADDR(base) ((base) + (0x604UL))
#define SOC_PMCTRL_FREQ_VOTE_K0_ADDR(base) ((base) + (0x608UL))
#define SOC_PMCTRL_FREQ_VOTE_K1_ADDR(base) ((base) + (0x60CUL))
#define SOC_PMCTRL_FREQ_VOTE_L0_ADDR(base) ((base) + (0x610UL))
#define SOC_PMCTRL_FREQ_VOTE_L1_ADDR(base) ((base) + (0x614UL))
#define SOC_PMCTRL_FREQ_VOTE_M0_ADDR(base) ((base) + (0x618UL))
#define SOC_PMCTRL_FREQ_VOTE_M1_ADDR(base) ((base) + (0x61CUL))
#define SOC_PMCTRL_FREQ_VOTE_N0_ADDR(base) ((base) + (0x620UL))
#define SOC_PMCTRL_FREQ_VOTE_N1_ADDR(base) ((base) + (0x624UL))
#define SOC_PMCTRL_FREQ_VOTE_N2_ADDR(base) ((base) + (0x628UL))
#define SOC_PMCTRL_FREQ_VOTE_N3_ADDR(base) ((base) + (0x62CUL))
#define SOC_PMCTRL_FREQ_VOTE_O0_ADDR(base) ((base) + (0x630UL))
#define SOC_PMCTRL_FREQ_VOTE_O1_ADDR(base) ((base) + (0x634UL))
#define SOC_PMCTRL_FREQ_VOTE_O2_ADDR(base) ((base) + (0x638UL))
#define SOC_PMCTRL_FREQ_VOTE_O3_ADDR(base) ((base) + (0x63CUL))
#define SOC_PMCTRL_FREQ_VOTE_P0_ADDR(base) ((base) + (0x640UL))
#define SOC_PMCTRL_FREQ_VOTE_P1_ADDR(base) ((base) + (0x644UL))
#define SOC_PMCTRL_FREQ_VOTE_P2_ADDR(base) ((base) + (0x648UL))
#define SOC_PMCTRL_FREQ_VOTE_P3_ADDR(base) ((base) + (0x64CUL))
#define SOC_PMCTRL_FREQ_VOTE_Q0_ADDR(base) ((base) + (0x650UL))
#define SOC_PMCTRL_FREQ_VOTE_Q1_ADDR(base) ((base) + (0x654UL))
#define SOC_PMCTRL_FREQ_VOTE_Q2_ADDR(base) ((base) + (0x658UL))
#define SOC_PMCTRL_FREQ_VOTE_Q3_ADDR(base) ((base) + (0x65CUL))
#define SOC_PMCTRL_FREQ_VOTE_Q4_ADDR(base) ((base) + (0x660UL))
#define SOC_PMCTRL_FREQ_VOTE_Q5_ADDR(base) ((base) + (0x664UL))
#define SOC_PMCTRL_FREQ_VOTE_Q6_ADDR(base) ((base) + (0x668UL))
#define SOC_PMCTRL_FREQ_VOTE_Q7_ADDR(base) ((base) + (0x66CUL))
#define SOC_PMCTRL_FREQ_VOTE_R0_ADDR(base) ((base) + (0x670UL))
#define SOC_PMCTRL_FREQ_VOTE_R1_ADDR(base) ((base) + (0x674UL))
#define SOC_PMCTRL_FREQ_VOTE_R2_ADDR(base) ((base) + (0x678UL))
#define SOC_PMCTRL_FREQ_VOTE_R3_ADDR(base) ((base) + (0x67CUL))
#define SOC_PMCTRL_FREQ_VOTE_R4_ADDR(base) ((base) + (0x680UL))
#define SOC_PMCTRL_FREQ_VOTE_R5_ADDR(base) ((base) + (0x684UL))
#define SOC_PMCTRL_FREQ_VOTE_R6_ADDR(base) ((base) + (0x688UL))
#define SOC_PMCTRL_FREQ_VOTE_R7_ADDR(base) ((base) + (0x68CUL))
#define SOC_PMCTRL_INTR_MASK_TO_LPMCU_J_R_ADDR(base) ((base) + (0x690UL))
#define SOC_PMCTRL_INTR_MASK_TO_CPU_LP_CTRL_J_R_ADDR(base) ((base) + (0x694UL))
#define SOC_PMCTRL_INTR_MASK_TO_GPU_LP_CTRL_J_R_ADDR(base) ((base) + (0x698UL))
#define SOC_PMCTRL_INTR_MASK_TO_DDR_LP_CTRL_J_R_ADDR(base) ((base) + (0x69CUL))
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_J_R_ADDR(base) ((base) + (0x6B0UL))
#define SOC_PMCTRL_VOTE_MODE_CFG_0_J_R_ADDR(base) ((base) + (0x6BCUL))
#define SOC_PMCTRL_VOTE_MODE_CFG_1_J_R_ADDR(base) ((base) + (0x6C0UL))
#define SOC_PMCTRL_VOTE_START_EN_J_R_ADDR(base) ((base) + (0x6C4UL))
#define SOC_PMCTRL_INT_VOTE_EN_J_R_ADDR(base) ((base) + (0x6C8UL))
#define SOC_PMCTRL_INT_VOTE_CLR_J_R_ADDR(base) ((base) + (0x6CCUL))
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_J_R_ADDR(base) ((base) + (0x6D0UL))
#define SOC_PMCTRL_INT_VOTE_STAT_J_R_ADDR(base) ((base) + (0x6D4UL))
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_J_R_ADDR(base) ((base) + (0x6D8UL))
#define SOC_PMCTRL_VOTE_RESULT_J_ADDR(base) ((base) + (0x6DCUL))
#define SOC_PMCTRL_VOTE_RESULT_K_ADDR(base) ((base) + (0x6E0UL))
#define SOC_PMCTRL_VOTE_RESULT_L_ADDR(base) ((base) + (0x6E4UL))
#define SOC_PMCTRL_VOTE_RESULT_M_ADDR(base) ((base) + (0x6E8UL))
#define SOC_PMCTRL_VOTE_RESULT_N_ADDR(base) ((base) + (0x6ECUL))
#define SOC_PMCTRL_VOTE_RESULT_O_ADDR(base) ((base) + (0x6F0UL))
#define SOC_PMCTRL_VOTE_RESULT_P_ADDR(base) ((base) + (0x6F4UL))
#define SOC_PMCTRL_VOTE_RESULT_Q_ADDR(base) ((base) + (0x6F8UL))
#define SOC_PMCTRL_VOTE_RESULT_R_ADDR(base) ((base) + (0x6FCUL))
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_ADDR(base) ((base) + (0x700UL))
#define SOC_PMCTRL_DSS_FREQ_VOTE_BYPASS_ADDR(base) ((base) + (0x704UL))
#define SOC_PMCTRL_PERI_CTRL0_ADDR(base) ((base) + (0x340UL))
#define SOC_PMCTRL_PERI_CTRL4_ADDR(base) ((base) + (0x350UL))
#define SOC_PMCTRL_PERI_CTRL5_ADDR(base) ((base) + (0x354UL))
#define SOC_PMCTRL_PERI_CTRL7_ADDR(base) ((base) + (0x35CUL))
#define SOC_PMCTRL_PERI_STAT1_ADDR(base) ((base) + (0x364UL))
#define SOC_PMCTRL_QIC_POWER_IDLEREQ_0_ADDR(base) ((base) + (0x380UL))
#define SOC_PMCTRL_QIC_POWER_IDLEACK_DBG_0_ADDR(base) ((base) + (0x384UL))
#define SOC_PMCTRL_QIC_POWER_IDLEACK_0_ADDR(base) ((base) + (0x388UL))
#define SOC_PMCTRL_BOOTROMFLAG_ADDR(base) ((base) + (0x460UL))
#define SOC_PMCTRL_PERIHPMEN_ADDR(base) ((base) + (0x464UL))
#define SOC_PMCTRL_PERIHPMCLKDIV_ADDR(base) ((base) + (0x468UL))
#define SOC_PMCTRL_PERIHPMOPC_ADDR(base) ((base) + (0x46CUL))
#define SOC_PMCTRL_DJTAG_CTRL_ADDR(base) ((base) + (0x4D8UL))
#define SOC_PMCTRL_PERI_STAT12_ADDR(base) ((base) + (0x4E0UL))
#define SOC_PMCTRL_PERI_STAT13_ADDR(base) ((base) + (0x4E4UL))
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_0_ADDR(base) ((base) + (0x000UL))
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_1_ADDR(base) ((base) + (0x004UL))
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_2_ADDR(base) ((base) + (0x02CUL))
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_3_ADDR(base) ((base) + (0x03CUL))
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_ADDR(base) ((base) + (0x008UL))
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_ADDR(base) ((base) + (0x00CUL))
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_ADDR(base) ((base) + (0x010UL))
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_ADDR(base) ((base) + (0x014UL))
#define SOC_PMCTRL_PERI_VOL_STABLE_ADDR(base) ((base) + (0x018UL))
#define SOC_PMCTRL_PERI_INTR_M3ORCPU_MSK_ADDR(base) ((base) + (0x01CUL))
#define SOC_PMCTRL_PERI_DVS_OUTPUT_READ_ADDR(base) ((base) + (0x020UL))
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_ADDR(base) ((base) + (0x024UL))
#define SOC_PMCTRL_PERI_INTR_BYPASS_HRD_ADDR(base) ((base) + (0x028UL))
#define SOC_PMCTRL_PERI_DVS_STAT0_ADDR(base) ((base) + (0x300UL))
#define SOC_PMCTRL_PERI_DVS_STAT1_ADDR(base) ((base) + (0x304UL))
#define SOC_PMCTRL_PERI_DVS_STAT2_ADDR(base) ((base) + (0x308UL))
#define SOC_PMCTRL_PERI_DVS_STAT3_ADDR(base) ((base) + (0x30CUL))
#define SOC_PMCTRL_PERI_DVS_STAT4_ADDR(base) ((base) + (0x310UL))
#define SOC_PMCTRL_PERI_DVS_STAT5_ADDR(base) ((base) + (0x314UL))
#define SOC_PMCTRL_PERI_DVS_STAT6_ADDR(base) ((base) + (0x318UL))
#define SOC_PMCTRL_PERI_DVS_STAT7_ADDR(base) ((base) + (0x31CUL))
#define SOC_PMCTRL_PERI_DVS_STAT8_ADDR(base) ((base) + (0x320UL))
#define SOC_PMCTRL_PERI_VOL_DOZE_VOTE_CTRL_ADDR(base) ((base) + (0xA00UL))
#define SOC_PMCTRL_PERI_PMU_BUCK_ON_TIME_ADDR(base) ((base) + (0xA10UL))
#define SOC_PMCTRL_PERI_PMU_BUCK_OFF_TIME_ADDR(base) ((base) + (0xA14UL))
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG1_ADDR(base) ((base) + (0xA18UL))
#define SOC_PMCTRL_PERI_PMU_TRIM_UP_TIME_ADDR(base) ((base) + (0xA54UL))
#define SOC_PMCTRL_PERI_PMU_TRIM_DN_TTME_ADDR(base) ((base) + (0xA58UL))
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG0_ADDR(base) ((base) + (0xA64UL))
#define SOC_PMCTRL_PERI_FIX_VOL_CONFIG_ADDR(base) ((base) + (0xA68UL))
#define SOC_PMCTRL_PERI_VOL_READ_ADDR(base) ((base) + (0xA70UL))
#define SOC_PMCTRL_PERI_VOTE_SFT_HRD_VOL_IDX_ADDR(base) ((base) + (0xA80UL))
#define SOC_PMCTRL_PERI_STAT_TIME_HOLD_ADDR(base) ((base) + (0xA84UL))
#define SOC_PMCTRL_PERI_VOL_CHG_FLAG_ADDR(base) ((base) + (0xA90UL))
#define SOC_PMCTRL_PERI_SPMI_HOLD_TIME_ADDR(base) ((base) + (0xA98UL))
#define SOC_PMCTRL_PERI_FER_REQ_ACK_ADDR(base) ((base) + (0xA9CUL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH0_IDX_0_ADDR(base) ((base) + (0xB00UL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH0_IDX_1_ADDR(base) ((base) + (0xB04UL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH1_IDX_0_ADDR(base) ((base) + (0xB08UL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH1_IDX_1_ADDR(base) ((base) + (0xB0CUL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH2_IDX_0_ADDR(base) ((base) + (0xB10UL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH2_IDX_1_ADDR(base) ((base) + (0xB14UL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH3_IDX_0_ADDR(base) ((base) + (0xB18UL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH3_IDX_1_ADDR(base) ((base) + (0xB1CUL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH4_IDX_0_ADDR(base) ((base) + (0xB20UL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH4_IDX_1_ADDR(base) ((base) + (0xB24UL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH5_IDX_0_ADDR(base) ((base) + (0xB28UL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH5_IDX_1_ADDR(base) ((base) + (0xB2CUL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH6_IDX_0_ADDR(base) ((base) + (0xB30UL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH6_IDX_1_ADDR(base) ((base) + (0xB34UL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH7_IDX_0_ADDR(base) ((base) + (0xB38UL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH7_IDX_1_ADDR(base) ((base) + (0xB3CUL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH8_IDX_0_ADDR(base) ((base) + (0xB40UL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH8_IDX_1_ADDR(base) ((base) + (0xB44UL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH9_IDX_0_ADDR(base) ((base) + (0xB48UL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH9_IDX_1_ADDR(base) ((base) + (0xB4CUL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH10_IDX_0_ADDR(base) ((base) + (0xB50UL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH10_IDX_1_ADDR(base) ((base) + (0xB54UL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH11_IDX_0_ADDR(base) ((base) + (0xB58UL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH11_IDX_1_ADDR(base) ((base) + (0xB5CUL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH12_IDX_0_ADDR(base) ((base) + (0xB60UL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH12_IDX_1_ADDR(base) ((base) + (0xB64UL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH13_IDX_0_ADDR(base) ((base) + (0xB68UL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH13_IDX_1_ADDR(base) ((base) + (0xB6CUL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH14_IDX_0_ADDR(base) ((base) + (0xB70UL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH14_IDX_1_ADDR(base) ((base) + (0xB74UL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH15_IDX_0_ADDR(base) ((base) + (0xB78UL))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH15_IDX_1_ADDR(base) ((base) + (0xB7CUL))
#define SOC_PMCTRL_BUCK5_VOTE_VOL_RANK_SFT_0_ADDR(base) ((base) + (0x390UL))
#define SOC_PMCTRL_BUCK5_VOTE_VOL_VALID_ADDR(base) ((base) + (0x394UL))
#define SOC_PMCTRL_BUCK5_VOTE_SFT_CHG_ADDR(base) ((base) + (0x398UL))
#define SOC_PMCTRL_BUCK5_VOTE_SFT_CHG_BYPASS_ADDR(base) ((base) + (0x39CUL))
#define SOC_PMCTRL_BUCK5_VOL_SFT_CLR_ADDR(base) ((base) + (0x3A0UL))
#define SOC_PMCTRL_BUCK5_VOL_STABLE_ADDR(base) ((base) + (0x3A4UL))
#define SOC_PMCTRL_BUCK5_INTR_M3ORCPU_MSK_ADDR(base) ((base) + (0x3A8UL))
#define SOC_PMCTRL_BUCK5_DVS_OUTPUT_READ_ADDR(base) ((base) + (0x3ACUL))
#define SOC_PMCTRL_BUCK5_INTR_BYPASS_SFT_ADDR(base) ((base) + (0x3B0UL))
#define SOC_PMCTRL_BUCK5_DVS_STAT0_ADDR(base) ((base) + (0x3B4UL))
#define SOC_PMCTRL_BUCK5_DVS_STAT1_ADDR(base) ((base) + (0x3B8UL))
#define SOC_PMCTRL_BUCK5_DVS_STAT2_ADDR(base) ((base) + (0x3BCUL))
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH0_IDX_0_ADDR(base) ((base) + (0xE58UL))
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH0_IDX_1_ADDR(base) ((base) + (0xE5CUL))
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH1_IDX_0_ADDR(base) ((base) + (0xE60UL))
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH1_IDX_1_ADDR(base) ((base) + (0xE64UL))
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH2_IDX_0_ADDR(base) ((base) + (0xE68UL))
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH2_IDX_1_ADDR(base) ((base) + (0xE70UL))
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH3_IDX_0_ADDR(base) ((base) + (0xE74UL))
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH3_IDX_1_ADDR(base) ((base) + (0xE78UL))
#define SOC_PMCTRL_BUCK5_PMU_TRIM_UP_TIME_ADDR(base) ((base) + (0xE7CUL))
#define SOC_PMCTRL_BUCK5_PMU_TRIM_DN_TIME_ADDR(base) ((base) + (0xE80UL))
#define SOC_PMCTRL_BUCK5_PMU_BUCK_ON_TIME_ADDR(base) ((base) + (0xE84UL))
#define SOC_PMCTRL_BUCK5_PMU_BUCK_OFF_TIME_ADDR(base) ((base) + (0xE88UL))
#define SOC_PMCTRL_BUCK5_INIT_VOL_CONFIG0_ADDR(base) ((base) + (0xE8CUL))
#define SOC_PMCTRL_BUCK5_INIT_VOL_CONFIG1_ADDR(base) ((base) + (0xE90UL))
#define SOC_PMCTRL_BUCK5_FIX_VOL_CONFIG_ADDR(base) ((base) + (0xE94UL))
#define SOC_PMCTRL_BUCK5_VOL_READ_ADDR(base) ((base) + (0xE98UL))
#define SOC_PMCTRL_BUCK5_STAT_TIME_HOLD_ADDR(base) ((base) + (0xE9CUL))
#define SOC_PMCTRL_BUCK5_VOL_CHG_FLAG_ADDR(base) ((base) + (0xEA0UL))
#define SOC_PMCTRL_BUCK5_SPM2_HOLD_TIME_ADDR(base) ((base) + (0xEA4UL))
#define SOC_PMCTRL_BUCK5_FER_REQ_ACK_ADDR(base) ((base) + (0xEA8UL))
#define SOC_PMCTRL_BUCK5_VOL_DOZE_VOTE_CTRL_ADDR(base) ((base) + (0xEACUL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_0_ADDR(base) ((base) + (0x3C0UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_1_ADDR(base) ((base) + (0x3C4UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_2_ADDR(base) ((base) + (0x3C8UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_3_ADDR(base) ((base) + (0x3CCUL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_ADDR(base) ((base) + (0x3D0UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_ADDR(base) ((base) + (0x3D4UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_ADDR(base) ((base) + (0x3D8UL))
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_ADDR(base) ((base) + (0x3DCUL))
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_ADDR(base) ((base) + (0x3E0UL))
#define SOC_PMCTRL_VDDC_MEM_INTR_LPMCU_MSK_ADDR(base) ((base) + (0x3E4UL))
#define SOC_PMCTRL_VDDC_MEM_DVS_OUTPUT_READ_ADDR(base) ((base) + (0x3E8UL))
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_ADDR(base) ((base) + (0x3ECUL))
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_HRD_ADDR(base) ((base) + (0x3F0UL))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_ADDR(base) ((base) + (0x3F4UL))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT1_ADDR(base) ((base) + (0x3F8UL))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT2_ADDR(base) ((base) + (0x3FCUL))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT3_ADDR(base) ((base) + (0x400UL))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT4_ADDR(base) ((base) + (0x404UL))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT5_ADDR(base) ((base) + (0x408UL))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT6_ADDR(base) ((base) + (0x40CUL))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT7_ADDR(base) ((base) + (0x410UL))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT8_ADDR(base) ((base) + (0x414UL))
#define SOC_PMCTRL_VDDC_MEM_INTR_XPU_LP_CTRL_MSK_ADDR(base) ((base) + (0x418UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_4_ADDR(base) ((base) + (0x41CUL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_1_ADDR(base) ((base) + (0x420UL))
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_1_ADDR(base) ((base) + (0x424UL))
#define SOC_PMCTRL_VDDC_MEM_INTR_ACPU_MSK_ADDR(base) ((base) + (0x428UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_1_ADDR(base) ((base) + (0x42CUL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_1_ADDR(base) ((base) + (0x430UL))
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_1_ADDR(base) ((base) + (0x434UL))
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_1_ADDR(base) ((base) + (0x438UL))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT9_ADDR(base) ((base) + (0x43CUL))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT10_ADDR(base) ((base) + (0x440UL))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT11_ADDR(base) ((base) + (0x444UL))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT12_ADDR(base) ((base) + (0x448UL))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT13_ADDR(base) ((base) + (0x44CUL))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT14_ADDR(base) ((base) + (0x450UL))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT15_ADDR(base) ((base) + (0x454UL))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT16_ADDR(base) ((base) + (0x458UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH0_IDX_0_ADDR(base) ((base) + (0xDC4UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH0_IDX_1_ADDR(base) ((base) + (0xDC8UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH1_IDX_0_ADDR(base) ((base) + (0xDCCUL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH1_IDX_1_ADDR(base) ((base) + (0xDD0UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH2_IDX_0_ADDR(base) ((base) + (0xDD4UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH2_IDX_1_ADDR(base) ((base) + (0xDD8UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH3_IDX_0_ADDR(base) ((base) + (0xDDCUL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH3_IDX_1_ADDR(base) ((base) + (0xDE0UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH4_IDX_0_ADDR(base) ((base) + (0xDE4UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH4_IDX_1_ADDR(base) ((base) + (0xDE8UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH5_IDX_0_ADDR(base) ((base) + (0xDECUL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH5_IDX_1_ADDR(base) ((base) + (0xDF0UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH6_IDX_0_ADDR(base) ((base) + (0xDF4UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH6_IDX_1_ADDR(base) ((base) + (0xDF8UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH7_IDX_0_ADDR(base) ((base) + (0xDFCUL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH7_IDX_1_ADDR(base) ((base) + (0xE00UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH8_IDX_0_ADDR(base) ((base) + (0xE04UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH8_IDX_1_ADDR(base) ((base) + (0xE08UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH9_IDX_0_ADDR(base) ((base) + (0xE0CUL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH9_IDX_1_ADDR(base) ((base) + (0xE10UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH10_IDX_0_ADDR(base) ((base) + (0xE14UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH10_IDX_1_ADDR(base) ((base) + (0xE18UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH11_IDX_0_ADDR(base) ((base) + (0xE1CUL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH11_IDX_1_ADDR(base) ((base) + (0xE20UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH12_IDX_0_ADDR(base) ((base) + (0xE24UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH12_IDX_1_ADDR(base) ((base) + (0xE28UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH13_IDX_0_ADDR(base) ((base) + (0xE2CUL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH13_IDX_1_ADDR(base) ((base) + (0xE30UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH14_IDX_0_ADDR(base) ((base) + (0xE34UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH14_IDX_1_ADDR(base) ((base) + (0xE38UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH15_IDX_0_ADDR(base) ((base) + (0xE3CUL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH15_IDX_1_ADDR(base) ((base) + (0xE40UL))
#define SOC_PMCTRL_VDDC_MEM_PMU_TRIM_UP_TIME_ADDR(base) ((base) + (0xE44UL))
#define SOC_PMCTRL_VDDC_MEM_PMU_TRIM_DN_TTME_ADDR(base) ((base) + (0xE48UL))
#define SOC_PMCTRL_VDDC_MEM_PMU_BUCK_ON_TIME_ADDR(base) ((base) + (0xE4CUL))
#define SOC_PMCTRL_VDDC_MEM_PMU_BUCK_OFF_TIME_ADDR(base) ((base) + (0xE50UL))
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG0_ADDR(base) ((base) + (0xE54UL))
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG1_ADDR(base) ((base) + (0xEB0UL))
#define SOC_PMCTRL_VDDC_MEM_FIX_VOL_CONFIG_ADDR(base) ((base) + (0xEB4UL))
#define SOC_PMCTRL_VDDC_MEM_VOL_READ_ADDR(base) ((base) + (0xEB8UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_ADDR(base) ((base) + (0xEBCUL))
#define SOC_PMCTRL_VDDC_MEM_STAT_TIME_HOLD_ADDR(base) ((base) + (0xEC0UL))
#define SOC_PMCTRL_VDDC_MEM_VOL_CHG_FLAG_ADDR(base) ((base) + (0xEC4UL))
#define SOC_PMCTRL_VDDC_MEM_SPMI_HOLD_TIME_ADDR(base) ((base) + (0xEC8UL))
#define SOC_PMCTRL_VDDC_MEM_FER_REQ_ACK_ADDR(base) ((base) + (0xECCUL))
#define SOC_PMCTRL_VDDC_MEM_VOL_DOZE_VOTE_CTRL_ADDR(base) ((base) + (0xED0UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH16_IDX_0_ADDR(base) ((base) + (0xED4UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH16_IDX_1_ADDR(base) ((base) + (0xED8UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH17_IDX_0_ADDR(base) ((base) + (0xEDCUL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH17_IDX_1_ADDR(base) ((base) + (0xEE0UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH18_IDX_0_ADDR(base) ((base) + (0xEE4UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH18_IDX_1_ADDR(base) ((base) + (0xEE8UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH19_IDX_0_ADDR(base) ((base) + (0xEECUL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH19_IDX_1_ADDR(base) ((base) + (0xEF0UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH20_IDX_0_ADDR(base) ((base) + (0xEF4UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH20_IDX_1_ADDR(base) ((base) + (0xEF8UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH21_IDX_0_ADDR(base) ((base) + (0xEFCUL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH21_IDX_1_ADDR(base) ((base) + (0xF00UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH22_IDX_0_ADDR(base) ((base) + (0xF04UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH22_IDX_1_ADDR(base) ((base) + (0xF08UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH23_IDX_0_ADDR(base) ((base) + (0xF0CUL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH23_IDX_1_ADDR(base) ((base) + (0xF10UL))
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG2_ADDR(base) ((base) + (0xF14UL))
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG3_ADDR(base) ((base) + (0xF18UL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_1_ADDR(base) ((base) + (0xF1CUL))
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_2_ADDR(base) ((base) + (0xF20UL))
#else
#define SOC_PMCTRL_PERIBAKDATA0_ADDR(base) ((base) + (0x930))
#define SOC_PMCTRL_PERIBAKDATA1_ADDR(base) ((base) + (0x934))
#define SOC_PMCTRL_PERIBAKDATA2_ADDR(base) ((base) + (0x938))
#define SOC_PMCTRL_PERIBAKDATA3_ADDR(base) ((base) + (0x93C))
#define SOC_PMCTRL_PERI_INTR_STAT_ADDR(base) ((base) + (0xC2C))
#define SOC_PMCTRL_FREQ_VOTE_A0_ADDR(base) ((base) + (0x200))
#define SOC_PMCTRL_FREQ_VOTE_A1_ADDR(base) ((base) + (0x204))
#define SOC_PMCTRL_FREQ_VOTE_B0_ADDR(base) ((base) + (0x208))
#define SOC_PMCTRL_FREQ_VOTE_B1_ADDR(base) ((base) + (0x20C))
#define SOC_PMCTRL_FREQ_VOTE_C0_ADDR(base) ((base) + (0x210))
#define SOC_PMCTRL_FREQ_VOTE_C1_ADDR(base) ((base) + (0x214))
#define SOC_PMCTRL_FREQ_VOTE_D0_ADDR(base) ((base) + (0x218))
#define SOC_PMCTRL_FREQ_VOTE_D1_ADDR(base) ((base) + (0x21C))
#define SOC_PMCTRL_FREQ_VOTE_E0_ADDR(base) ((base) + (0x220))
#define SOC_PMCTRL_FREQ_VOTE_E1_ADDR(base) ((base) + (0x224))
#define SOC_PMCTRL_FREQ_VOTE_E2_ADDR(base) ((base) + (0x228))
#define SOC_PMCTRL_FREQ_VOTE_E3_ADDR(base) ((base) + (0x22C))
#define SOC_PMCTRL_FREQ_VOTE_F0_ADDR(base) ((base) + (0x230))
#define SOC_PMCTRL_FREQ_VOTE_F1_ADDR(base) ((base) + (0x234))
#define SOC_PMCTRL_FREQ_VOTE_F2_ADDR(base) ((base) + (0x238))
#define SOC_PMCTRL_FREQ_VOTE_F3_ADDR(base) ((base) + (0x23C))
#define SOC_PMCTRL_FREQ_VOTE_G0_ADDR(base) ((base) + (0x240))
#define SOC_PMCTRL_FREQ_VOTE_G1_ADDR(base) ((base) + (0x244))
#define SOC_PMCTRL_FREQ_VOTE_G2_ADDR(base) ((base) + (0x248))
#define SOC_PMCTRL_FREQ_VOTE_G3_ADDR(base) ((base) + (0x24C))
#define SOC_PMCTRL_FREQ_VOTE_H0_ADDR(base) ((base) + (0x250))
#define SOC_PMCTRL_FREQ_VOTE_H1_ADDR(base) ((base) + (0x254))
#define SOC_PMCTRL_FREQ_VOTE_H2_ADDR(base) ((base) + (0x258))
#define SOC_PMCTRL_FREQ_VOTE_H3_ADDR(base) ((base) + (0x25C))
#define SOC_PMCTRL_FREQ_VOTE_H4_ADDR(base) ((base) + (0x260))
#define SOC_PMCTRL_FREQ_VOTE_H5_ADDR(base) ((base) + (0x264))
#define SOC_PMCTRL_FREQ_VOTE_H6_ADDR(base) ((base) + (0x268))
#define SOC_PMCTRL_FREQ_VOTE_H7_ADDR(base) ((base) + (0x26C))
#define SOC_PMCTRL_FREQ_VOTE_I0_ADDR(base) ((base) + (0x270))
#define SOC_PMCTRL_FREQ_VOTE_I1_ADDR(base) ((base) + (0x274))
#define SOC_PMCTRL_FREQ_VOTE_I2_ADDR(base) ((base) + (0x278))
#define SOC_PMCTRL_FREQ_VOTE_I3_ADDR(base) ((base) + (0x27C))
#define SOC_PMCTRL_FREQ_VOTE_I4_ADDR(base) ((base) + (0x280))
#define SOC_PMCTRL_FREQ_VOTE_I5_ADDR(base) ((base) + (0x284))
#define SOC_PMCTRL_FREQ_VOTE_I6_ADDR(base) ((base) + (0x288))
#define SOC_PMCTRL_FREQ_VOTE_I7_ADDR(base) ((base) + (0x28C))
#define SOC_PMCTRL_INTR_MASK_TO_LPMCU_A_I_ADDR(base) ((base) + (0x290))
#define SOC_PMCTRL_INTR_MASK_TO_CPU_LP_CTRL_A_I_ADDR(base) ((base) + (0x294))
#define SOC_PMCTRL_INTR_MASK_TO_GPU_LP_CTRL_A_I_ADDR(base) ((base) + (0x298))
#define SOC_PMCTRL_INTR_MASK_TO_DDR_LP_CTRL_A_I_ADDR(base) ((base) + (0x29C))
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_A_I_ADDR(base) ((base) + (0x2B0))
#define SOC_PMCTRL_VOTE_MODE_CFG_0_A_I_ADDR(base) ((base) + (0x2BC))
#define SOC_PMCTRL_VOTE_MODE_CFG_1_A_I_ADDR(base) ((base) + (0x2C0))
#define SOC_PMCTRL_VOTE_START_EN_A_I_ADDR(base) ((base) + (0x2C4))
#define SOC_PMCTRL_INT_VOTE_EN_A_I_ADDR(base) ((base) + (0x2C8))
#define SOC_PMCTRL_INT_VOTE_CLR_A_I_ADDR(base) ((base) + (0x2CC))
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_A_I_ADDR(base) ((base) + (0x2D0))
#define SOC_PMCTRL_INT_VOTE_STAT_A_I_ADDR(base) ((base) + (0x2D4))
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_A_I_ADDR(base) ((base) + (0x2D8))
#define SOC_PMCTRL_VOTE_RESULT_A_ADDR(base) ((base) + (0x2DC))
#define SOC_PMCTRL_VOTE_RESULT_B_ADDR(base) ((base) + (0x2E0))
#define SOC_PMCTRL_VOTE_RESULT_C_ADDR(base) ((base) + (0x2E4))
#define SOC_PMCTRL_VOTE_RESULT_D_ADDR(base) ((base) + (0x2E8))
#define SOC_PMCTRL_VOTE_RESULT_E_ADDR(base) ((base) + (0x2EC))
#define SOC_PMCTRL_VOTE_RESULT_F_ADDR(base) ((base) + (0x2F0))
#define SOC_PMCTRL_VOTE_RESULT_G_ADDR(base) ((base) + (0x2F4))
#define SOC_PMCTRL_VOTE_RESULT_H_ADDR(base) ((base) + (0x2F8))
#define SOC_PMCTRL_VOTE_RESULT_I_ADDR(base) ((base) + (0x2FC))
#define SOC_PMCTRL_FREQ_VOTE_J0_ADDR(base) ((base) + (0x600))
#define SOC_PMCTRL_FREQ_VOTE_J1_ADDR(base) ((base) + (0x604))
#define SOC_PMCTRL_FREQ_VOTE_K0_ADDR(base) ((base) + (0x608))
#define SOC_PMCTRL_FREQ_VOTE_K1_ADDR(base) ((base) + (0x60C))
#define SOC_PMCTRL_FREQ_VOTE_L0_ADDR(base) ((base) + (0x610))
#define SOC_PMCTRL_FREQ_VOTE_L1_ADDR(base) ((base) + (0x614))
#define SOC_PMCTRL_FREQ_VOTE_M0_ADDR(base) ((base) + (0x618))
#define SOC_PMCTRL_FREQ_VOTE_M1_ADDR(base) ((base) + (0x61C))
#define SOC_PMCTRL_FREQ_VOTE_N0_ADDR(base) ((base) + (0x620))
#define SOC_PMCTRL_FREQ_VOTE_N1_ADDR(base) ((base) + (0x624))
#define SOC_PMCTRL_FREQ_VOTE_N2_ADDR(base) ((base) + (0x628))
#define SOC_PMCTRL_FREQ_VOTE_N3_ADDR(base) ((base) + (0x62C))
#define SOC_PMCTRL_FREQ_VOTE_O0_ADDR(base) ((base) + (0x630))
#define SOC_PMCTRL_FREQ_VOTE_O1_ADDR(base) ((base) + (0x634))
#define SOC_PMCTRL_FREQ_VOTE_O2_ADDR(base) ((base) + (0x638))
#define SOC_PMCTRL_FREQ_VOTE_O3_ADDR(base) ((base) + (0x63C))
#define SOC_PMCTRL_FREQ_VOTE_P0_ADDR(base) ((base) + (0x640))
#define SOC_PMCTRL_FREQ_VOTE_P1_ADDR(base) ((base) + (0x644))
#define SOC_PMCTRL_FREQ_VOTE_P2_ADDR(base) ((base) + (0x648))
#define SOC_PMCTRL_FREQ_VOTE_P3_ADDR(base) ((base) + (0x64C))
#define SOC_PMCTRL_FREQ_VOTE_Q0_ADDR(base) ((base) + (0x650))
#define SOC_PMCTRL_FREQ_VOTE_Q1_ADDR(base) ((base) + (0x654))
#define SOC_PMCTRL_FREQ_VOTE_Q2_ADDR(base) ((base) + (0x658))
#define SOC_PMCTRL_FREQ_VOTE_Q3_ADDR(base) ((base) + (0x65C))
#define SOC_PMCTRL_FREQ_VOTE_Q4_ADDR(base) ((base) + (0x660))
#define SOC_PMCTRL_FREQ_VOTE_Q5_ADDR(base) ((base) + (0x664))
#define SOC_PMCTRL_FREQ_VOTE_Q6_ADDR(base) ((base) + (0x668))
#define SOC_PMCTRL_FREQ_VOTE_Q7_ADDR(base) ((base) + (0x66C))
#define SOC_PMCTRL_FREQ_VOTE_R0_ADDR(base) ((base) + (0x670))
#define SOC_PMCTRL_FREQ_VOTE_R1_ADDR(base) ((base) + (0x674))
#define SOC_PMCTRL_FREQ_VOTE_R2_ADDR(base) ((base) + (0x678))
#define SOC_PMCTRL_FREQ_VOTE_R3_ADDR(base) ((base) + (0x67C))
#define SOC_PMCTRL_FREQ_VOTE_R4_ADDR(base) ((base) + (0x680))
#define SOC_PMCTRL_FREQ_VOTE_R5_ADDR(base) ((base) + (0x684))
#define SOC_PMCTRL_FREQ_VOTE_R6_ADDR(base) ((base) + (0x688))
#define SOC_PMCTRL_FREQ_VOTE_R7_ADDR(base) ((base) + (0x68C))
#define SOC_PMCTRL_INTR_MASK_TO_LPMCU_J_R_ADDR(base) ((base) + (0x690))
#define SOC_PMCTRL_INTR_MASK_TO_CPU_LP_CTRL_J_R_ADDR(base) ((base) + (0x694))
#define SOC_PMCTRL_INTR_MASK_TO_GPU_LP_CTRL_J_R_ADDR(base) ((base) + (0x698))
#define SOC_PMCTRL_INTR_MASK_TO_DDR_LP_CTRL_J_R_ADDR(base) ((base) + (0x69C))
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_J_R_ADDR(base) ((base) + (0x6B0))
#define SOC_PMCTRL_VOTE_MODE_CFG_0_J_R_ADDR(base) ((base) + (0x6BC))
#define SOC_PMCTRL_VOTE_MODE_CFG_1_J_R_ADDR(base) ((base) + (0x6C0))
#define SOC_PMCTRL_VOTE_START_EN_J_R_ADDR(base) ((base) + (0x6C4))
#define SOC_PMCTRL_INT_VOTE_EN_J_R_ADDR(base) ((base) + (0x6C8))
#define SOC_PMCTRL_INT_VOTE_CLR_J_R_ADDR(base) ((base) + (0x6CC))
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_J_R_ADDR(base) ((base) + (0x6D0))
#define SOC_PMCTRL_INT_VOTE_STAT_J_R_ADDR(base) ((base) + (0x6D4))
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_J_R_ADDR(base) ((base) + (0x6D8))
#define SOC_PMCTRL_VOTE_RESULT_J_ADDR(base) ((base) + (0x6DC))
#define SOC_PMCTRL_VOTE_RESULT_K_ADDR(base) ((base) + (0x6E0))
#define SOC_PMCTRL_VOTE_RESULT_L_ADDR(base) ((base) + (0x6E4))
#define SOC_PMCTRL_VOTE_RESULT_M_ADDR(base) ((base) + (0x6E8))
#define SOC_PMCTRL_VOTE_RESULT_N_ADDR(base) ((base) + (0x6EC))
#define SOC_PMCTRL_VOTE_RESULT_O_ADDR(base) ((base) + (0x6F0))
#define SOC_PMCTRL_VOTE_RESULT_P_ADDR(base) ((base) + (0x6F4))
#define SOC_PMCTRL_VOTE_RESULT_Q_ADDR(base) ((base) + (0x6F8))
#define SOC_PMCTRL_VOTE_RESULT_R_ADDR(base) ((base) + (0x6FC))
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_ADDR(base) ((base) + (0x700))
#define SOC_PMCTRL_DSS_FREQ_VOTE_BYPASS_ADDR(base) ((base) + (0x704))
#define SOC_PMCTRL_PERI_CTRL0_ADDR(base) ((base) + (0x340))
#define SOC_PMCTRL_PERI_CTRL4_ADDR(base) ((base) + (0x350))
#define SOC_PMCTRL_PERI_CTRL5_ADDR(base) ((base) + (0x354))
#define SOC_PMCTRL_PERI_CTRL7_ADDR(base) ((base) + (0x35C))
#define SOC_PMCTRL_PERI_STAT1_ADDR(base) ((base) + (0x364))
#define SOC_PMCTRL_QIC_POWER_IDLEREQ_0_ADDR(base) ((base) + (0x380))
#define SOC_PMCTRL_QIC_POWER_IDLEACK_DBG_0_ADDR(base) ((base) + (0x384))
#define SOC_PMCTRL_QIC_POWER_IDLEACK_0_ADDR(base) ((base) + (0x388))
#define SOC_PMCTRL_BOOTROMFLAG_ADDR(base) ((base) + (0x460))
#define SOC_PMCTRL_PERIHPMEN_ADDR(base) ((base) + (0x464))
#define SOC_PMCTRL_PERIHPMCLKDIV_ADDR(base) ((base) + (0x468))
#define SOC_PMCTRL_PERIHPMOPC_ADDR(base) ((base) + (0x46C))
#define SOC_PMCTRL_DJTAG_CTRL_ADDR(base) ((base) + (0x4D8))
#define SOC_PMCTRL_PERI_STAT12_ADDR(base) ((base) + (0x4E0))
#define SOC_PMCTRL_PERI_STAT13_ADDR(base) ((base) + (0x4E4))
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_0_ADDR(base) ((base) + (0x000))
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_1_ADDR(base) ((base) + (0x004))
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_2_ADDR(base) ((base) + (0x02C))
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_3_ADDR(base) ((base) + (0x03C))
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_ADDR(base) ((base) + (0x008))
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_ADDR(base) ((base) + (0x00C))
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_ADDR(base) ((base) + (0x010))
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_ADDR(base) ((base) + (0x014))
#define SOC_PMCTRL_PERI_VOL_STABLE_ADDR(base) ((base) + (0x018))
#define SOC_PMCTRL_PERI_INTR_M3ORCPU_MSK_ADDR(base) ((base) + (0x01C))
#define SOC_PMCTRL_PERI_DVS_OUTPUT_READ_ADDR(base) ((base) + (0x020))
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_ADDR(base) ((base) + (0x024))
#define SOC_PMCTRL_PERI_INTR_BYPASS_HRD_ADDR(base) ((base) + (0x028))
#define SOC_PMCTRL_PERI_DVS_STAT0_ADDR(base) ((base) + (0x300))
#define SOC_PMCTRL_PERI_DVS_STAT1_ADDR(base) ((base) + (0x304))
#define SOC_PMCTRL_PERI_DVS_STAT2_ADDR(base) ((base) + (0x308))
#define SOC_PMCTRL_PERI_DVS_STAT3_ADDR(base) ((base) + (0x30C))
#define SOC_PMCTRL_PERI_DVS_STAT4_ADDR(base) ((base) + (0x310))
#define SOC_PMCTRL_PERI_DVS_STAT5_ADDR(base) ((base) + (0x314))
#define SOC_PMCTRL_PERI_DVS_STAT6_ADDR(base) ((base) + (0x318))
#define SOC_PMCTRL_PERI_DVS_STAT7_ADDR(base) ((base) + (0x31C))
#define SOC_PMCTRL_PERI_DVS_STAT8_ADDR(base) ((base) + (0x320))
#define SOC_PMCTRL_PERI_VOL_DOZE_VOTE_CTRL_ADDR(base) ((base) + (0xA00))
#define SOC_PMCTRL_PERI_PMU_BUCK_ON_TIME_ADDR(base) ((base) + (0xA10))
#define SOC_PMCTRL_PERI_PMU_BUCK_OFF_TIME_ADDR(base) ((base) + (0xA14))
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG1_ADDR(base) ((base) + (0xA18))
#define SOC_PMCTRL_PERI_PMU_TRIM_UP_TIME_ADDR(base) ((base) + (0xA54))
#define SOC_PMCTRL_PERI_PMU_TRIM_DN_TTME_ADDR(base) ((base) + (0xA58))
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG0_ADDR(base) ((base) + (0xA64))
#define SOC_PMCTRL_PERI_FIX_VOL_CONFIG_ADDR(base) ((base) + (0xA68))
#define SOC_PMCTRL_PERI_VOL_READ_ADDR(base) ((base) + (0xA70))
#define SOC_PMCTRL_PERI_VOTE_SFT_HRD_VOL_IDX_ADDR(base) ((base) + (0xA80))
#define SOC_PMCTRL_PERI_STAT_TIME_HOLD_ADDR(base) ((base) + (0xA84))
#define SOC_PMCTRL_PERI_VOL_CHG_FLAG_ADDR(base) ((base) + (0xA90))
#define SOC_PMCTRL_PERI_SPMI_HOLD_TIME_ADDR(base) ((base) + (0xA98))
#define SOC_PMCTRL_PERI_FER_REQ_ACK_ADDR(base) ((base) + (0xA9C))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH0_IDX_0_ADDR(base) ((base) + (0xB00))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH0_IDX_1_ADDR(base) ((base) + (0xB04))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH1_IDX_0_ADDR(base) ((base) + (0xB08))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH1_IDX_1_ADDR(base) ((base) + (0xB0C))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH2_IDX_0_ADDR(base) ((base) + (0xB10))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH2_IDX_1_ADDR(base) ((base) + (0xB14))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH3_IDX_0_ADDR(base) ((base) + (0xB18))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH3_IDX_1_ADDR(base) ((base) + (0xB1C))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH4_IDX_0_ADDR(base) ((base) + (0xB20))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH4_IDX_1_ADDR(base) ((base) + (0xB24))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH5_IDX_0_ADDR(base) ((base) + (0xB28))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH5_IDX_1_ADDR(base) ((base) + (0xB2C))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH6_IDX_0_ADDR(base) ((base) + (0xB30))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH6_IDX_1_ADDR(base) ((base) + (0xB34))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH7_IDX_0_ADDR(base) ((base) + (0xB38))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH7_IDX_1_ADDR(base) ((base) + (0xB3C))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH8_IDX_0_ADDR(base) ((base) + (0xB40))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH8_IDX_1_ADDR(base) ((base) + (0xB44))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH9_IDX_0_ADDR(base) ((base) + (0xB48))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH9_IDX_1_ADDR(base) ((base) + (0xB4C))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH10_IDX_0_ADDR(base) ((base) + (0xB50))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH10_IDX_1_ADDR(base) ((base) + (0xB54))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH11_IDX_0_ADDR(base) ((base) + (0xB58))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH11_IDX_1_ADDR(base) ((base) + (0xB5C))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH12_IDX_0_ADDR(base) ((base) + (0xB60))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH12_IDX_1_ADDR(base) ((base) + (0xB64))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH13_IDX_0_ADDR(base) ((base) + (0xB68))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH13_IDX_1_ADDR(base) ((base) + (0xB6C))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH14_IDX_0_ADDR(base) ((base) + (0xB70))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH14_IDX_1_ADDR(base) ((base) + (0xB74))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH15_IDX_0_ADDR(base) ((base) + (0xB78))
#define SOC_PMCTRL_PERI_VOTE_VOL_CH15_IDX_1_ADDR(base) ((base) + (0xB7C))
#define SOC_PMCTRL_BUCK5_VOTE_VOL_RANK_SFT_0_ADDR(base) ((base) + (0x390))
#define SOC_PMCTRL_BUCK5_VOTE_VOL_VALID_ADDR(base) ((base) + (0x394))
#define SOC_PMCTRL_BUCK5_VOTE_SFT_CHG_ADDR(base) ((base) + (0x398))
#define SOC_PMCTRL_BUCK5_VOTE_SFT_CHG_BYPASS_ADDR(base) ((base) + (0x39C))
#define SOC_PMCTRL_BUCK5_VOL_SFT_CLR_ADDR(base) ((base) + (0x3A0))
#define SOC_PMCTRL_BUCK5_VOL_STABLE_ADDR(base) ((base) + (0x3A4))
#define SOC_PMCTRL_BUCK5_INTR_M3ORCPU_MSK_ADDR(base) ((base) + (0x3A8))
#define SOC_PMCTRL_BUCK5_DVS_OUTPUT_READ_ADDR(base) ((base) + (0x3AC))
#define SOC_PMCTRL_BUCK5_INTR_BYPASS_SFT_ADDR(base) ((base) + (0x3B0))
#define SOC_PMCTRL_BUCK5_DVS_STAT0_ADDR(base) ((base) + (0x3B4))
#define SOC_PMCTRL_BUCK5_DVS_STAT1_ADDR(base) ((base) + (0x3B8))
#define SOC_PMCTRL_BUCK5_DVS_STAT2_ADDR(base) ((base) + (0x3BC))
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH0_IDX_0_ADDR(base) ((base) + (0xE58))
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH0_IDX_1_ADDR(base) ((base) + (0xE5C))
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH1_IDX_0_ADDR(base) ((base) + (0xE60))
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH1_IDX_1_ADDR(base) ((base) + (0xE64))
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH2_IDX_0_ADDR(base) ((base) + (0xE68))
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH2_IDX_1_ADDR(base) ((base) + (0xE70))
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH3_IDX_0_ADDR(base) ((base) + (0xE74))
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH3_IDX_1_ADDR(base) ((base) + (0xE78))
#define SOC_PMCTRL_BUCK5_PMU_TRIM_UP_TIME_ADDR(base) ((base) + (0xE7C))
#define SOC_PMCTRL_BUCK5_PMU_TRIM_DN_TIME_ADDR(base) ((base) + (0xE80))
#define SOC_PMCTRL_BUCK5_PMU_BUCK_ON_TIME_ADDR(base) ((base) + (0xE84))
#define SOC_PMCTRL_BUCK5_PMU_BUCK_OFF_TIME_ADDR(base) ((base) + (0xE88))
#define SOC_PMCTRL_BUCK5_INIT_VOL_CONFIG0_ADDR(base) ((base) + (0xE8C))
#define SOC_PMCTRL_BUCK5_INIT_VOL_CONFIG1_ADDR(base) ((base) + (0xE90))
#define SOC_PMCTRL_BUCK5_FIX_VOL_CONFIG_ADDR(base) ((base) + (0xE94))
#define SOC_PMCTRL_BUCK5_VOL_READ_ADDR(base) ((base) + (0xE98))
#define SOC_PMCTRL_BUCK5_STAT_TIME_HOLD_ADDR(base) ((base) + (0xE9C))
#define SOC_PMCTRL_BUCK5_VOL_CHG_FLAG_ADDR(base) ((base) + (0xEA0))
#define SOC_PMCTRL_BUCK5_SPM2_HOLD_TIME_ADDR(base) ((base) + (0xEA4))
#define SOC_PMCTRL_BUCK5_FER_REQ_ACK_ADDR(base) ((base) + (0xEA8))
#define SOC_PMCTRL_BUCK5_VOL_DOZE_VOTE_CTRL_ADDR(base) ((base) + (0xEAC))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_0_ADDR(base) ((base) + (0x3C0))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_1_ADDR(base) ((base) + (0x3C4))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_2_ADDR(base) ((base) + (0x3C8))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_3_ADDR(base) ((base) + (0x3CC))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_ADDR(base) ((base) + (0x3D0))
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_ADDR(base) ((base) + (0x3D4))
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_ADDR(base) ((base) + (0x3D8))
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_ADDR(base) ((base) + (0x3DC))
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_ADDR(base) ((base) + (0x3E0))
#define SOC_PMCTRL_VDDC_MEM_INTR_LPMCU_MSK_ADDR(base) ((base) + (0x3E4))
#define SOC_PMCTRL_VDDC_MEM_DVS_OUTPUT_READ_ADDR(base) ((base) + (0x3E8))
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_ADDR(base) ((base) + (0x3EC))
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_HRD_ADDR(base) ((base) + (0x3F0))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_ADDR(base) ((base) + (0x3F4))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT1_ADDR(base) ((base) + (0x3F8))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT2_ADDR(base) ((base) + (0x3FC))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT3_ADDR(base) ((base) + (0x400))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT4_ADDR(base) ((base) + (0x404))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT5_ADDR(base) ((base) + (0x408))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT6_ADDR(base) ((base) + (0x40C))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT7_ADDR(base) ((base) + (0x410))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT8_ADDR(base) ((base) + (0x414))
#define SOC_PMCTRL_VDDC_MEM_INTR_XPU_LP_CTRL_MSK_ADDR(base) ((base) + (0x418))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_4_ADDR(base) ((base) + (0x41C))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_1_ADDR(base) ((base) + (0x420))
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_1_ADDR(base) ((base) + (0x424))
#define SOC_PMCTRL_VDDC_MEM_INTR_ACPU_MSK_ADDR(base) ((base) + (0x428))
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_1_ADDR(base) ((base) + (0x42C))
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_1_ADDR(base) ((base) + (0x430))
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_1_ADDR(base) ((base) + (0x434))
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_1_ADDR(base) ((base) + (0x438))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT9_ADDR(base) ((base) + (0x43C))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT10_ADDR(base) ((base) + (0x440))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT11_ADDR(base) ((base) + (0x444))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT12_ADDR(base) ((base) + (0x448))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT13_ADDR(base) ((base) + (0x44C))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT14_ADDR(base) ((base) + (0x450))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT15_ADDR(base) ((base) + (0x454))
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT16_ADDR(base) ((base) + (0x458))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH0_IDX_0_ADDR(base) ((base) + (0xDC4))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH0_IDX_1_ADDR(base) ((base) + (0xDC8))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH1_IDX_0_ADDR(base) ((base) + (0xDCC))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH1_IDX_1_ADDR(base) ((base) + (0xDD0))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH2_IDX_0_ADDR(base) ((base) + (0xDD4))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH2_IDX_1_ADDR(base) ((base) + (0xDD8))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH3_IDX_0_ADDR(base) ((base) + (0xDDC))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH3_IDX_1_ADDR(base) ((base) + (0xDE0))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH4_IDX_0_ADDR(base) ((base) + (0xDE4))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH4_IDX_1_ADDR(base) ((base) + (0xDE8))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH5_IDX_0_ADDR(base) ((base) + (0xDEC))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH5_IDX_1_ADDR(base) ((base) + (0xDF0))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH6_IDX_0_ADDR(base) ((base) + (0xDF4))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH6_IDX_1_ADDR(base) ((base) + (0xDF8))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH7_IDX_0_ADDR(base) ((base) + (0xDFC))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH7_IDX_1_ADDR(base) ((base) + (0xE00))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH8_IDX_0_ADDR(base) ((base) + (0xE04))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH8_IDX_1_ADDR(base) ((base) + (0xE08))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH9_IDX_0_ADDR(base) ((base) + (0xE0C))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH9_IDX_1_ADDR(base) ((base) + (0xE10))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH10_IDX_0_ADDR(base) ((base) + (0xE14))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH10_IDX_1_ADDR(base) ((base) + (0xE18))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH11_IDX_0_ADDR(base) ((base) + (0xE1C))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH11_IDX_1_ADDR(base) ((base) + (0xE20))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH12_IDX_0_ADDR(base) ((base) + (0xE24))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH12_IDX_1_ADDR(base) ((base) + (0xE28))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH13_IDX_0_ADDR(base) ((base) + (0xE2C))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH13_IDX_1_ADDR(base) ((base) + (0xE30))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH14_IDX_0_ADDR(base) ((base) + (0xE34))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH14_IDX_1_ADDR(base) ((base) + (0xE38))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH15_IDX_0_ADDR(base) ((base) + (0xE3C))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH15_IDX_1_ADDR(base) ((base) + (0xE40))
#define SOC_PMCTRL_VDDC_MEM_PMU_TRIM_UP_TIME_ADDR(base) ((base) + (0xE44))
#define SOC_PMCTRL_VDDC_MEM_PMU_TRIM_DN_TTME_ADDR(base) ((base) + (0xE48))
#define SOC_PMCTRL_VDDC_MEM_PMU_BUCK_ON_TIME_ADDR(base) ((base) + (0xE4C))
#define SOC_PMCTRL_VDDC_MEM_PMU_BUCK_OFF_TIME_ADDR(base) ((base) + (0xE50))
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG0_ADDR(base) ((base) + (0xE54))
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG1_ADDR(base) ((base) + (0xEB0))
#define SOC_PMCTRL_VDDC_MEM_FIX_VOL_CONFIG_ADDR(base) ((base) + (0xEB4))
#define SOC_PMCTRL_VDDC_MEM_VOL_READ_ADDR(base) ((base) + (0xEB8))
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_ADDR(base) ((base) + (0xEBC))
#define SOC_PMCTRL_VDDC_MEM_STAT_TIME_HOLD_ADDR(base) ((base) + (0xEC0))
#define SOC_PMCTRL_VDDC_MEM_VOL_CHG_FLAG_ADDR(base) ((base) + (0xEC4))
#define SOC_PMCTRL_VDDC_MEM_SPMI_HOLD_TIME_ADDR(base) ((base) + (0xEC8))
#define SOC_PMCTRL_VDDC_MEM_FER_REQ_ACK_ADDR(base) ((base) + (0xECC))
#define SOC_PMCTRL_VDDC_MEM_VOL_DOZE_VOTE_CTRL_ADDR(base) ((base) + (0xED0))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH16_IDX_0_ADDR(base) ((base) + (0xED4))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH16_IDX_1_ADDR(base) ((base) + (0xED8))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH17_IDX_0_ADDR(base) ((base) + (0xEDC))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH17_IDX_1_ADDR(base) ((base) + (0xEE0))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH18_IDX_0_ADDR(base) ((base) + (0xEE4))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH18_IDX_1_ADDR(base) ((base) + (0xEE8))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH19_IDX_0_ADDR(base) ((base) + (0xEEC))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH19_IDX_1_ADDR(base) ((base) + (0xEF0))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH20_IDX_0_ADDR(base) ((base) + (0xEF4))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH20_IDX_1_ADDR(base) ((base) + (0xEF8))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH21_IDX_0_ADDR(base) ((base) + (0xEFC))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH21_IDX_1_ADDR(base) ((base) + (0xF00))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH22_IDX_0_ADDR(base) ((base) + (0xF04))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH22_IDX_1_ADDR(base) ((base) + (0xF08))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH23_IDX_0_ADDR(base) ((base) + (0xF0C))
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH23_IDX_1_ADDR(base) ((base) + (0xF10))
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG2_ADDR(base) ((base) + (0xF14))
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG3_ADDR(base) ((base) + (0xF18))
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_1_ADDR(base) ((base) + (0xF1C))
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_2_ADDR(base) ((base) + (0xF20))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_PERIBAKDATA0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_PERIBAKDATA1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_PERIBAKDATA2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_PERIBAKDATA3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_peri_dvs_stat_pmc2acpu_gather : 1;
        unsigned int intr_peri_dvs_stat_pmc2lpm3_gather : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_PMCTRL_PERI_INTR_STAT_UNION;
#endif
#define SOC_PMCTRL_PERI_INTR_STAT_intr_peri_dvs_stat_pmc2acpu_gather_START (0)
#define SOC_PMCTRL_PERI_INTR_STAT_intr_peri_dvs_stat_pmc2acpu_gather_END (0)
#define SOC_PMCTRL_PERI_INTR_STAT_intr_peri_dvs_stat_pmc2lpm3_gather_START (1)
#define SOC_PMCTRL_PERI_INTR_STAT_intr_peri_dvs_stat_pmc2lpm3_gather_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_a_channel0 : 15;
        unsigned int freq_vote_a0_msk0 : 1;
        unsigned int freq_vote_a_channel1 : 15;
        unsigned int freq_vote_a0_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_A0_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_A0_freq_vote_a_channel0_START (0)
#define SOC_PMCTRL_FREQ_VOTE_A0_freq_vote_a_channel0_END (14)
#define SOC_PMCTRL_FREQ_VOTE_A0_freq_vote_a0_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_A0_freq_vote_a0_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_A0_freq_vote_a_channel1_START (16)
#define SOC_PMCTRL_FREQ_VOTE_A0_freq_vote_a_channel1_END (30)
#define SOC_PMCTRL_FREQ_VOTE_A0_freq_vote_a0_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_A0_freq_vote_a0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_a_channel2 : 15;
        unsigned int freq_vote_a1_msk0 : 1;
        unsigned int freq_vote_a_channel3 : 15;
        unsigned int freq_vote_a1_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_A1_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_A1_freq_vote_a_channel2_START (0)
#define SOC_PMCTRL_FREQ_VOTE_A1_freq_vote_a_channel2_END (14)
#define SOC_PMCTRL_FREQ_VOTE_A1_freq_vote_a1_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_A1_freq_vote_a1_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_A1_freq_vote_a_channel3_START (16)
#define SOC_PMCTRL_FREQ_VOTE_A1_freq_vote_a_channel3_END (30)
#define SOC_PMCTRL_FREQ_VOTE_A1_freq_vote_a1_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_A1_freq_vote_a1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_b_channel0 : 15;
        unsigned int freq_vote_b0_msk0 : 1;
        unsigned int freq_vote_b_channel1 : 15;
        unsigned int freq_vote_b0_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_B0_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_B0_freq_vote_b_channel0_START (0)
#define SOC_PMCTRL_FREQ_VOTE_B0_freq_vote_b_channel0_END (14)
#define SOC_PMCTRL_FREQ_VOTE_B0_freq_vote_b0_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_B0_freq_vote_b0_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_B0_freq_vote_b_channel1_START (16)
#define SOC_PMCTRL_FREQ_VOTE_B0_freq_vote_b_channel1_END (30)
#define SOC_PMCTRL_FREQ_VOTE_B0_freq_vote_b0_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_B0_freq_vote_b0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_b_channel2 : 15;
        unsigned int freq_vote_b1_msk0 : 1;
        unsigned int freq_vote_b_channel3 : 15;
        unsigned int freq_vote_b1_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_B1_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_B1_freq_vote_b_channel2_START (0)
#define SOC_PMCTRL_FREQ_VOTE_B1_freq_vote_b_channel2_END (14)
#define SOC_PMCTRL_FREQ_VOTE_B1_freq_vote_b1_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_B1_freq_vote_b1_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_B1_freq_vote_b_channel3_START (16)
#define SOC_PMCTRL_FREQ_VOTE_B1_freq_vote_b_channel3_END (30)
#define SOC_PMCTRL_FREQ_VOTE_B1_freq_vote_b1_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_B1_freq_vote_b1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_c_channel0 : 15;
        unsigned int freq_vote_c0_msk0 : 1;
        unsigned int freq_vote_c_channel1 : 15;
        unsigned int freq_vote_c0_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_C0_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_C0_freq_vote_c_channel0_START (0)
#define SOC_PMCTRL_FREQ_VOTE_C0_freq_vote_c_channel0_END (14)
#define SOC_PMCTRL_FREQ_VOTE_C0_freq_vote_c0_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_C0_freq_vote_c0_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_C0_freq_vote_c_channel1_START (16)
#define SOC_PMCTRL_FREQ_VOTE_C0_freq_vote_c_channel1_END (30)
#define SOC_PMCTRL_FREQ_VOTE_C0_freq_vote_c0_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_C0_freq_vote_c0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_c_channel2 : 15;
        unsigned int freq_vote_c1_msk0 : 1;
        unsigned int freq_vote_c_channel3 : 15;
        unsigned int freq_vote_c1_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_C1_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_C1_freq_vote_c_channel2_START (0)
#define SOC_PMCTRL_FREQ_VOTE_C1_freq_vote_c_channel2_END (14)
#define SOC_PMCTRL_FREQ_VOTE_C1_freq_vote_c1_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_C1_freq_vote_c1_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_C1_freq_vote_c_channel3_START (16)
#define SOC_PMCTRL_FREQ_VOTE_C1_freq_vote_c_channel3_END (30)
#define SOC_PMCTRL_FREQ_VOTE_C1_freq_vote_c1_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_C1_freq_vote_c1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_d_channel0 : 15;
        unsigned int freq_vote_d0_msk0 : 1;
        unsigned int freq_vote_d_channel1 : 15;
        unsigned int freq_vote_d0_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_D0_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_D0_freq_vote_d_channel0_START (0)
#define SOC_PMCTRL_FREQ_VOTE_D0_freq_vote_d_channel0_END (14)
#define SOC_PMCTRL_FREQ_VOTE_D0_freq_vote_d0_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_D0_freq_vote_d0_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_D0_freq_vote_d_channel1_START (16)
#define SOC_PMCTRL_FREQ_VOTE_D0_freq_vote_d_channel1_END (30)
#define SOC_PMCTRL_FREQ_VOTE_D0_freq_vote_d0_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_D0_freq_vote_d0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_d_channel2 : 15;
        unsigned int freq_vote_d1_msk0 : 1;
        unsigned int freq_vote_d_channel3 : 15;
        unsigned int freq_vote_d1_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_D1_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_D1_freq_vote_d_channel2_START (0)
#define SOC_PMCTRL_FREQ_VOTE_D1_freq_vote_d_channel2_END (14)
#define SOC_PMCTRL_FREQ_VOTE_D1_freq_vote_d1_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_D1_freq_vote_d1_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_D1_freq_vote_d_channel3_START (16)
#define SOC_PMCTRL_FREQ_VOTE_D1_freq_vote_d_channel3_END (30)
#define SOC_PMCTRL_FREQ_VOTE_D1_freq_vote_d1_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_D1_freq_vote_d1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_e_channel0 : 15;
        unsigned int freq_vote_e0_msk0 : 1;
        unsigned int freq_vote_e_channel1 : 15;
        unsigned int freq_vote_e0_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_E0_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_E0_freq_vote_e_channel0_START (0)
#define SOC_PMCTRL_FREQ_VOTE_E0_freq_vote_e_channel0_END (14)
#define SOC_PMCTRL_FREQ_VOTE_E0_freq_vote_e0_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_E0_freq_vote_e0_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_E0_freq_vote_e_channel1_START (16)
#define SOC_PMCTRL_FREQ_VOTE_E0_freq_vote_e_channel1_END (30)
#define SOC_PMCTRL_FREQ_VOTE_E0_freq_vote_e0_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_E0_freq_vote_e0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_e_channel2 : 15;
        unsigned int freq_vote_e1_msk0 : 1;
        unsigned int freq_vote_e_channel3 : 15;
        unsigned int freq_vote_e1_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_E1_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_E1_freq_vote_e_channel2_START (0)
#define SOC_PMCTRL_FREQ_VOTE_E1_freq_vote_e_channel2_END (14)
#define SOC_PMCTRL_FREQ_VOTE_E1_freq_vote_e1_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_E1_freq_vote_e1_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_E1_freq_vote_e_channel3_START (16)
#define SOC_PMCTRL_FREQ_VOTE_E1_freq_vote_e_channel3_END (30)
#define SOC_PMCTRL_FREQ_VOTE_E1_freq_vote_e1_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_E1_freq_vote_e1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_e_channel4 : 15;
        unsigned int freq_vote_e2_msk0 : 1;
        unsigned int freq_vote_e_channel5 : 15;
        unsigned int freq_vote_e2_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_E2_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_E2_freq_vote_e_channel4_START (0)
#define SOC_PMCTRL_FREQ_VOTE_E2_freq_vote_e_channel4_END (14)
#define SOC_PMCTRL_FREQ_VOTE_E2_freq_vote_e2_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_E2_freq_vote_e2_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_E2_freq_vote_e_channel5_START (16)
#define SOC_PMCTRL_FREQ_VOTE_E2_freq_vote_e_channel5_END (30)
#define SOC_PMCTRL_FREQ_VOTE_E2_freq_vote_e2_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_E2_freq_vote_e2_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_e_channel6 : 15;
        unsigned int freq_vote_e3_msk0 : 1;
        unsigned int freq_vote_e_channel7 : 15;
        unsigned int freq_vote_e3_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_E3_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_E3_freq_vote_e_channel6_START (0)
#define SOC_PMCTRL_FREQ_VOTE_E3_freq_vote_e_channel6_END (14)
#define SOC_PMCTRL_FREQ_VOTE_E3_freq_vote_e3_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_E3_freq_vote_e3_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_E3_freq_vote_e_channel7_START (16)
#define SOC_PMCTRL_FREQ_VOTE_E3_freq_vote_e_channel7_END (30)
#define SOC_PMCTRL_FREQ_VOTE_E3_freq_vote_e3_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_E3_freq_vote_e3_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_f_channel0 : 15;
        unsigned int freq_vote_f0_msk0 : 1;
        unsigned int freq_vote_f_channel1 : 15;
        unsigned int freq_vote_f0_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_F0_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_F0_freq_vote_f_channel0_START (0)
#define SOC_PMCTRL_FREQ_VOTE_F0_freq_vote_f_channel0_END (14)
#define SOC_PMCTRL_FREQ_VOTE_F0_freq_vote_f0_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_F0_freq_vote_f0_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_F0_freq_vote_f_channel1_START (16)
#define SOC_PMCTRL_FREQ_VOTE_F0_freq_vote_f_channel1_END (30)
#define SOC_PMCTRL_FREQ_VOTE_F0_freq_vote_f0_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_F0_freq_vote_f0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_f_channel2 : 15;
        unsigned int freq_vote_f1_msk0 : 1;
        unsigned int freq_vote_f_channel3 : 15;
        unsigned int freq_vote_f1_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_F1_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_F1_freq_vote_f_channel2_START (0)
#define SOC_PMCTRL_FREQ_VOTE_F1_freq_vote_f_channel2_END (14)
#define SOC_PMCTRL_FREQ_VOTE_F1_freq_vote_f1_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_F1_freq_vote_f1_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_F1_freq_vote_f_channel3_START (16)
#define SOC_PMCTRL_FREQ_VOTE_F1_freq_vote_f_channel3_END (30)
#define SOC_PMCTRL_FREQ_VOTE_F1_freq_vote_f1_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_F1_freq_vote_f1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_f_channel4 : 15;
        unsigned int freq_vote_f2_msk0 : 1;
        unsigned int freq_vote_f_channel5 : 15;
        unsigned int freq_vote_f2_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_F2_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_F2_freq_vote_f_channel4_START (0)
#define SOC_PMCTRL_FREQ_VOTE_F2_freq_vote_f_channel4_END (14)
#define SOC_PMCTRL_FREQ_VOTE_F2_freq_vote_f2_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_F2_freq_vote_f2_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_F2_freq_vote_f_channel5_START (16)
#define SOC_PMCTRL_FREQ_VOTE_F2_freq_vote_f_channel5_END (30)
#define SOC_PMCTRL_FREQ_VOTE_F2_freq_vote_f2_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_F2_freq_vote_f2_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_f_channel6 : 15;
        unsigned int freq_vote_f3_msk0 : 1;
        unsigned int freq_vote_f_channel7 : 15;
        unsigned int freq_vote_f3_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_F3_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_F3_freq_vote_f_channel6_START (0)
#define SOC_PMCTRL_FREQ_VOTE_F3_freq_vote_f_channel6_END (14)
#define SOC_PMCTRL_FREQ_VOTE_F3_freq_vote_f3_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_F3_freq_vote_f3_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_F3_freq_vote_f_channel7_START (16)
#define SOC_PMCTRL_FREQ_VOTE_F3_freq_vote_f_channel7_END (30)
#define SOC_PMCTRL_FREQ_VOTE_F3_freq_vote_f3_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_F3_freq_vote_f3_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_g_channel0 : 15;
        unsigned int freq_vote_g0_msk0 : 1;
        unsigned int freq_vote_g_channel1 : 15;
        unsigned int freq_vote_g0_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_G0_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_G0_freq_vote_g_channel0_START (0)
#define SOC_PMCTRL_FREQ_VOTE_G0_freq_vote_g_channel0_END (14)
#define SOC_PMCTRL_FREQ_VOTE_G0_freq_vote_g0_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_G0_freq_vote_g0_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_G0_freq_vote_g_channel1_START (16)
#define SOC_PMCTRL_FREQ_VOTE_G0_freq_vote_g_channel1_END (30)
#define SOC_PMCTRL_FREQ_VOTE_G0_freq_vote_g0_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_G0_freq_vote_g0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_g_channel2 : 15;
        unsigned int freq_vote_g1_msk0 : 1;
        unsigned int freq_vote_g_channel3 : 15;
        unsigned int freq_vote_g1_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_G1_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_G1_freq_vote_g_channel2_START (0)
#define SOC_PMCTRL_FREQ_VOTE_G1_freq_vote_g_channel2_END (14)
#define SOC_PMCTRL_FREQ_VOTE_G1_freq_vote_g1_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_G1_freq_vote_g1_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_G1_freq_vote_g_channel3_START (16)
#define SOC_PMCTRL_FREQ_VOTE_G1_freq_vote_g_channel3_END (30)
#define SOC_PMCTRL_FREQ_VOTE_G1_freq_vote_g1_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_G1_freq_vote_g1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_g_channel4 : 15;
        unsigned int freq_vote_g2_msk0 : 1;
        unsigned int freq_vote_g_channel5 : 15;
        unsigned int freq_vote_g2_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_G2_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_G2_freq_vote_g_channel4_START (0)
#define SOC_PMCTRL_FREQ_VOTE_G2_freq_vote_g_channel4_END (14)
#define SOC_PMCTRL_FREQ_VOTE_G2_freq_vote_g2_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_G2_freq_vote_g2_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_G2_freq_vote_g_channel5_START (16)
#define SOC_PMCTRL_FREQ_VOTE_G2_freq_vote_g_channel5_END (30)
#define SOC_PMCTRL_FREQ_VOTE_G2_freq_vote_g2_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_G2_freq_vote_g2_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_g_channel6 : 15;
        unsigned int freq_vote_g3_msk0 : 1;
        unsigned int freq_vote_g_channel7 : 15;
        unsigned int freq_vote_g3_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_G3_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_G3_freq_vote_g_channel6_START (0)
#define SOC_PMCTRL_FREQ_VOTE_G3_freq_vote_g_channel6_END (14)
#define SOC_PMCTRL_FREQ_VOTE_G3_freq_vote_g3_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_G3_freq_vote_g3_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_G3_freq_vote_g_channel7_START (16)
#define SOC_PMCTRL_FREQ_VOTE_G3_freq_vote_g_channel7_END (30)
#define SOC_PMCTRL_FREQ_VOTE_G3_freq_vote_g3_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_G3_freq_vote_g3_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_h_channel0 : 15;
        unsigned int freq_vote_h0_msk0 : 1;
        unsigned int freq_vote_h_channel1 : 15;
        unsigned int freq_vote_h0_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_H0_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_H0_freq_vote_h_channel0_START (0)
#define SOC_PMCTRL_FREQ_VOTE_H0_freq_vote_h_channel0_END (14)
#define SOC_PMCTRL_FREQ_VOTE_H0_freq_vote_h0_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_H0_freq_vote_h0_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_H0_freq_vote_h_channel1_START (16)
#define SOC_PMCTRL_FREQ_VOTE_H0_freq_vote_h_channel1_END (30)
#define SOC_PMCTRL_FREQ_VOTE_H0_freq_vote_h0_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_H0_freq_vote_h0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_h_channel2 : 15;
        unsigned int freq_vote_h1_msk0 : 1;
        unsigned int freq_vote_h_channel3 : 15;
        unsigned int freq_vote_h1_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_H1_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_H1_freq_vote_h_channel2_START (0)
#define SOC_PMCTRL_FREQ_VOTE_H1_freq_vote_h_channel2_END (14)
#define SOC_PMCTRL_FREQ_VOTE_H1_freq_vote_h1_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_H1_freq_vote_h1_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_H1_freq_vote_h_channel3_START (16)
#define SOC_PMCTRL_FREQ_VOTE_H1_freq_vote_h_channel3_END (30)
#define SOC_PMCTRL_FREQ_VOTE_H1_freq_vote_h1_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_H1_freq_vote_h1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_h_channel4 : 15;
        unsigned int freq_vote_h2_msk0 : 1;
        unsigned int freq_vote_h_channel5 : 15;
        unsigned int freq_vote_h2_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_H2_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_H2_freq_vote_h_channel4_START (0)
#define SOC_PMCTRL_FREQ_VOTE_H2_freq_vote_h_channel4_END (14)
#define SOC_PMCTRL_FREQ_VOTE_H2_freq_vote_h2_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_H2_freq_vote_h2_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_H2_freq_vote_h_channel5_START (16)
#define SOC_PMCTRL_FREQ_VOTE_H2_freq_vote_h_channel5_END (30)
#define SOC_PMCTRL_FREQ_VOTE_H2_freq_vote_h2_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_H2_freq_vote_h2_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_h_channel6 : 15;
        unsigned int freq_vote_h3_msk0 : 1;
        unsigned int freq_vote_h_channel7 : 15;
        unsigned int freq_vote_h3_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_H3_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_H3_freq_vote_h_channel6_START (0)
#define SOC_PMCTRL_FREQ_VOTE_H3_freq_vote_h_channel6_END (14)
#define SOC_PMCTRL_FREQ_VOTE_H3_freq_vote_h3_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_H3_freq_vote_h3_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_H3_freq_vote_h_channel7_START (16)
#define SOC_PMCTRL_FREQ_VOTE_H3_freq_vote_h_channel7_END (30)
#define SOC_PMCTRL_FREQ_VOTE_H3_freq_vote_h3_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_H3_freq_vote_h3_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_h_channel8 : 15;
        unsigned int freq_vote_h4_msk0 : 1;
        unsigned int freq_vote_h_channel9 : 15;
        unsigned int freq_vote_h4_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_H4_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_H4_freq_vote_h_channel8_START (0)
#define SOC_PMCTRL_FREQ_VOTE_H4_freq_vote_h_channel8_END (14)
#define SOC_PMCTRL_FREQ_VOTE_H4_freq_vote_h4_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_H4_freq_vote_h4_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_H4_freq_vote_h_channel9_START (16)
#define SOC_PMCTRL_FREQ_VOTE_H4_freq_vote_h_channel9_END (30)
#define SOC_PMCTRL_FREQ_VOTE_H4_freq_vote_h4_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_H4_freq_vote_h4_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_h_channel10 : 15;
        unsigned int freq_vote_h5_msk0 : 1;
        unsigned int freq_vote_h_channel11 : 15;
        unsigned int freq_vote_h5_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_H5_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_H5_freq_vote_h_channel10_START (0)
#define SOC_PMCTRL_FREQ_VOTE_H5_freq_vote_h_channel10_END (14)
#define SOC_PMCTRL_FREQ_VOTE_H5_freq_vote_h5_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_H5_freq_vote_h5_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_H5_freq_vote_h_channel11_START (16)
#define SOC_PMCTRL_FREQ_VOTE_H5_freq_vote_h_channel11_END (30)
#define SOC_PMCTRL_FREQ_VOTE_H5_freq_vote_h5_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_H5_freq_vote_h5_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_h_channel12 : 15;
        unsigned int freq_vote_h6_msk0 : 1;
        unsigned int freq_vote_h_channel13 : 15;
        unsigned int freq_vote_h6_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_H6_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_H6_freq_vote_h_channel12_START (0)
#define SOC_PMCTRL_FREQ_VOTE_H6_freq_vote_h_channel12_END (14)
#define SOC_PMCTRL_FREQ_VOTE_H6_freq_vote_h6_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_H6_freq_vote_h6_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_H6_freq_vote_h_channel13_START (16)
#define SOC_PMCTRL_FREQ_VOTE_H6_freq_vote_h_channel13_END (30)
#define SOC_PMCTRL_FREQ_VOTE_H6_freq_vote_h6_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_H6_freq_vote_h6_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_h_channel14 : 15;
        unsigned int freq_vote_h7_msk0 : 1;
        unsigned int freq_vote_h_channel15 : 15;
        unsigned int freq_vote_h7_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_H7_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_H7_freq_vote_h_channel14_START (0)
#define SOC_PMCTRL_FREQ_VOTE_H7_freq_vote_h_channel14_END (14)
#define SOC_PMCTRL_FREQ_VOTE_H7_freq_vote_h7_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_H7_freq_vote_h7_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_H7_freq_vote_h_channel15_START (16)
#define SOC_PMCTRL_FREQ_VOTE_H7_freq_vote_h_channel15_END (30)
#define SOC_PMCTRL_FREQ_VOTE_H7_freq_vote_h7_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_H7_freq_vote_h7_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_i_channel0 : 15;
        unsigned int freq_vote_i0_msk0 : 1;
        unsigned int freq_vote_i_channel1 : 15;
        unsigned int freq_vote_i0_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_I0_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_I0_freq_vote_i_channel0_START (0)
#define SOC_PMCTRL_FREQ_VOTE_I0_freq_vote_i_channel0_END (14)
#define SOC_PMCTRL_FREQ_VOTE_I0_freq_vote_i0_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_I0_freq_vote_i0_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_I0_freq_vote_i_channel1_START (16)
#define SOC_PMCTRL_FREQ_VOTE_I0_freq_vote_i_channel1_END (30)
#define SOC_PMCTRL_FREQ_VOTE_I0_freq_vote_i0_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_I0_freq_vote_i0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_i_channel2 : 15;
        unsigned int freq_vote_i1_msk0 : 1;
        unsigned int freq_vote_i_channel3 : 15;
        unsigned int freq_vote_i1_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_I1_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_I1_freq_vote_i_channel2_START (0)
#define SOC_PMCTRL_FREQ_VOTE_I1_freq_vote_i_channel2_END (14)
#define SOC_PMCTRL_FREQ_VOTE_I1_freq_vote_i1_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_I1_freq_vote_i1_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_I1_freq_vote_i_channel3_START (16)
#define SOC_PMCTRL_FREQ_VOTE_I1_freq_vote_i_channel3_END (30)
#define SOC_PMCTRL_FREQ_VOTE_I1_freq_vote_i1_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_I1_freq_vote_i1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_i_channel4 : 15;
        unsigned int freq_vote_i2_msk0 : 1;
        unsigned int freq_vote_i_channel5 : 15;
        unsigned int freq_vote_i2_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_I2_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_I2_freq_vote_i_channel4_START (0)
#define SOC_PMCTRL_FREQ_VOTE_I2_freq_vote_i_channel4_END (14)
#define SOC_PMCTRL_FREQ_VOTE_I2_freq_vote_i2_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_I2_freq_vote_i2_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_I2_freq_vote_i_channel5_START (16)
#define SOC_PMCTRL_FREQ_VOTE_I2_freq_vote_i_channel5_END (30)
#define SOC_PMCTRL_FREQ_VOTE_I2_freq_vote_i2_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_I2_freq_vote_i2_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_i_channel6 : 15;
        unsigned int freq_vote_i3_msk0 : 1;
        unsigned int freq_vote_i_channel7 : 15;
        unsigned int freq_vote_i3_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_I3_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_I3_freq_vote_i_channel6_START (0)
#define SOC_PMCTRL_FREQ_VOTE_I3_freq_vote_i_channel6_END (14)
#define SOC_PMCTRL_FREQ_VOTE_I3_freq_vote_i3_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_I3_freq_vote_i3_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_I3_freq_vote_i_channel7_START (16)
#define SOC_PMCTRL_FREQ_VOTE_I3_freq_vote_i_channel7_END (30)
#define SOC_PMCTRL_FREQ_VOTE_I3_freq_vote_i3_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_I3_freq_vote_i3_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_i_channel8 : 15;
        unsigned int freq_vote_i4_msk0 : 1;
        unsigned int freq_vote_i_channel9 : 15;
        unsigned int freq_vote_i4_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_I4_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_I4_freq_vote_i_channel8_START (0)
#define SOC_PMCTRL_FREQ_VOTE_I4_freq_vote_i_channel8_END (14)
#define SOC_PMCTRL_FREQ_VOTE_I4_freq_vote_i4_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_I4_freq_vote_i4_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_I4_freq_vote_i_channel9_START (16)
#define SOC_PMCTRL_FREQ_VOTE_I4_freq_vote_i_channel9_END (30)
#define SOC_PMCTRL_FREQ_VOTE_I4_freq_vote_i4_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_I4_freq_vote_i4_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_i_channel10 : 15;
        unsigned int freq_vote_i5_msk0 : 1;
        unsigned int freq_vote_i_channel11 : 15;
        unsigned int freq_vote_i5_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_I5_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_I5_freq_vote_i_channel10_START (0)
#define SOC_PMCTRL_FREQ_VOTE_I5_freq_vote_i_channel10_END (14)
#define SOC_PMCTRL_FREQ_VOTE_I5_freq_vote_i5_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_I5_freq_vote_i5_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_I5_freq_vote_i_channel11_START (16)
#define SOC_PMCTRL_FREQ_VOTE_I5_freq_vote_i_channel11_END (30)
#define SOC_PMCTRL_FREQ_VOTE_I5_freq_vote_i5_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_I5_freq_vote_i5_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_i_channel12 : 15;
        unsigned int freq_vote_i6_msk0 : 1;
        unsigned int freq_vote_i_channel13 : 15;
        unsigned int freq_vote_i6_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_I6_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_I6_freq_vote_i_channel12_START (0)
#define SOC_PMCTRL_FREQ_VOTE_I6_freq_vote_i_channel12_END (14)
#define SOC_PMCTRL_FREQ_VOTE_I6_freq_vote_i6_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_I6_freq_vote_i6_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_I6_freq_vote_i_channel13_START (16)
#define SOC_PMCTRL_FREQ_VOTE_I6_freq_vote_i_channel13_END (30)
#define SOC_PMCTRL_FREQ_VOTE_I6_freq_vote_i6_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_I6_freq_vote_i6_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_i_channel14 : 15;
        unsigned int freq_vote_i7_msk0 : 1;
        unsigned int freq_vote_i_channel15 : 15;
        unsigned int freq_vote_i7_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_I7_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_I7_freq_vote_i_channel14_START (0)
#define SOC_PMCTRL_FREQ_VOTE_I7_freq_vote_i_channel14_END (14)
#define SOC_PMCTRL_FREQ_VOTE_I7_freq_vote_i7_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_I7_freq_vote_i7_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_I7_freq_vote_i_channel15_START (16)
#define SOC_PMCTRL_FREQ_VOTE_I7_freq_vote_i_channel15_END (30)
#define SOC_PMCTRL_FREQ_VOTE_I7_freq_vote_i7_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_I7_freq_vote_i7_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_mask_to_lpmcu_a_i : 9;
        unsigned int reserved : 7;
        unsigned int intr_mask_to_lpmcu_a_i_msk : 16;
    } reg;
} SOC_PMCTRL_INTR_MASK_TO_LPMCU_A_I_UNION;
#endif
#define SOC_PMCTRL_INTR_MASK_TO_LPMCU_A_I_intr_mask_to_lpmcu_a_i_START (0)
#define SOC_PMCTRL_INTR_MASK_TO_LPMCU_A_I_intr_mask_to_lpmcu_a_i_END (8)
#define SOC_PMCTRL_INTR_MASK_TO_LPMCU_A_I_intr_mask_to_lpmcu_a_i_msk_START (16)
#define SOC_PMCTRL_INTR_MASK_TO_LPMCU_A_I_intr_mask_to_lpmcu_a_i_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_mask_to_cpu_lp_ctrl_a_i : 9;
        unsigned int reserved : 7;
        unsigned int intr_mask_to_cpu_lp_ctrl_a_i_msk : 16;
    } reg;
} SOC_PMCTRL_INTR_MASK_TO_CPU_LP_CTRL_A_I_UNION;
#endif
#define SOC_PMCTRL_INTR_MASK_TO_CPU_LP_CTRL_A_I_intr_mask_to_cpu_lp_ctrl_a_i_START (0)
#define SOC_PMCTRL_INTR_MASK_TO_CPU_LP_CTRL_A_I_intr_mask_to_cpu_lp_ctrl_a_i_END (8)
#define SOC_PMCTRL_INTR_MASK_TO_CPU_LP_CTRL_A_I_intr_mask_to_cpu_lp_ctrl_a_i_msk_START (16)
#define SOC_PMCTRL_INTR_MASK_TO_CPU_LP_CTRL_A_I_intr_mask_to_cpu_lp_ctrl_a_i_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_mask_to_gpu_lp_ctrl_a_i : 9;
        unsigned int reserved : 7;
        unsigned int intr_mask_to_gpu_lp_ctrl_a_i_msk : 16;
    } reg;
} SOC_PMCTRL_INTR_MASK_TO_GPU_LP_CTRL_A_I_UNION;
#endif
#define SOC_PMCTRL_INTR_MASK_TO_GPU_LP_CTRL_A_I_intr_mask_to_gpu_lp_ctrl_a_i_START (0)
#define SOC_PMCTRL_INTR_MASK_TO_GPU_LP_CTRL_A_I_intr_mask_to_gpu_lp_ctrl_a_i_END (8)
#define SOC_PMCTRL_INTR_MASK_TO_GPU_LP_CTRL_A_I_intr_mask_to_gpu_lp_ctrl_a_i_msk_START (16)
#define SOC_PMCTRL_INTR_MASK_TO_GPU_LP_CTRL_A_I_intr_mask_to_gpu_lp_ctrl_a_i_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_mask_to_ddr_lp_ctrl_a_i : 9;
        unsigned int reserved : 7;
        unsigned int intr_mask_to_ddr_lp_ctrl_a_i_msk : 16;
    } reg;
} SOC_PMCTRL_INTR_MASK_TO_DDR_LP_CTRL_A_I_UNION;
#endif
#define SOC_PMCTRL_INTR_MASK_TO_DDR_LP_CTRL_A_I_intr_mask_to_ddr_lp_ctrl_a_i_START (0)
#define SOC_PMCTRL_INTR_MASK_TO_DDR_LP_CTRL_A_I_intr_mask_to_ddr_lp_ctrl_a_i_END (8)
#define SOC_PMCTRL_INTR_MASK_TO_DDR_LP_CTRL_A_I_intr_mask_to_ddr_lp_ctrl_a_i_msk_START (16)
#define SOC_PMCTRL_INTR_MASK_TO_DDR_LP_CTRL_A_I_intr_mask_to_ddr_lp_ctrl_a_i_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_channel_num_a : 2;
        unsigned int freq_vote_channel_num_b : 2;
        unsigned int freq_vote_channel_num_c : 2;
        unsigned int freq_vote_channel_num_d : 2;
        unsigned int freq_vote_channel_num_e : 2;
        unsigned int freq_vote_channel_num_f : 2;
        unsigned int freq_vote_channel_num_g : 2;
        unsigned int freq_vote_channel_num_h : 2;
        unsigned int freq_vote_channel_num_i : 2;
        unsigned int reserved : 14;
    } reg;
} SOC_PMCTRL_VOTE_CHANNEL_CFG_A_I_UNION;
#endif
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_A_I_freq_vote_channel_num_a_START (0)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_A_I_freq_vote_channel_num_a_END (1)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_A_I_freq_vote_channel_num_b_START (2)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_A_I_freq_vote_channel_num_b_END (3)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_A_I_freq_vote_channel_num_c_START (4)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_A_I_freq_vote_channel_num_c_END (5)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_A_I_freq_vote_channel_num_d_START (6)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_A_I_freq_vote_channel_num_d_END (7)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_A_I_freq_vote_channel_num_e_START (8)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_A_I_freq_vote_channel_num_e_END (9)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_A_I_freq_vote_channel_num_f_START (10)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_A_I_freq_vote_channel_num_f_END (11)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_A_I_freq_vote_channel_num_g_START (12)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_A_I_freq_vote_channel_num_g_END (13)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_A_I_freq_vote_channel_num_h_START (14)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_A_I_freq_vote_channel_num_h_END (15)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_A_I_freq_vote_channel_num_i_START (16)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_A_I_freq_vote_channel_num_i_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_a_type : 2;
        unsigned int freq_vote_b_type : 2;
        unsigned int freq_vote_c_type : 2;
        unsigned int freq_vote_d_type : 2;
        unsigned int freq_vote_e_type : 2;
        unsigned int freq_vote_f_type : 2;
        unsigned int freq_vote_g_type : 2;
        unsigned int freq_vote_h_type : 2;
        unsigned int vote_mode_cfg_0_a_i_msk : 16;
    } reg;
} SOC_PMCTRL_VOTE_MODE_CFG_0_A_I_UNION;
#endif
#define SOC_PMCTRL_VOTE_MODE_CFG_0_A_I_freq_vote_a_type_START (0)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_A_I_freq_vote_a_type_END (1)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_A_I_freq_vote_b_type_START (2)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_A_I_freq_vote_b_type_END (3)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_A_I_freq_vote_c_type_START (4)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_A_I_freq_vote_c_type_END (5)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_A_I_freq_vote_d_type_START (6)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_A_I_freq_vote_d_type_END (7)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_A_I_freq_vote_e_type_START (8)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_A_I_freq_vote_e_type_END (9)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_A_I_freq_vote_f_type_START (10)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_A_I_freq_vote_f_type_END (11)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_A_I_freq_vote_g_type_START (12)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_A_I_freq_vote_g_type_END (13)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_A_I_freq_vote_h_type_START (14)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_A_I_freq_vote_h_type_END (15)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_A_I_vote_mode_cfg_0_a_i_msk_START (16)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_A_I_vote_mode_cfg_0_a_i_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_i_type : 2;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 2;
        unsigned int reserved_3 : 2;
        unsigned int reserved_4 : 2;
        unsigned int reserved_5 : 2;
        unsigned int reserved_6 : 2;
        unsigned int vote_mode_cfg_1_a_i_msk : 16;
    } reg;
} SOC_PMCTRL_VOTE_MODE_CFG_1_A_I_UNION;
#endif
#define SOC_PMCTRL_VOTE_MODE_CFG_1_A_I_freq_vote_i_type_START (0)
#define SOC_PMCTRL_VOTE_MODE_CFG_1_A_I_freq_vote_i_type_END (1)
#define SOC_PMCTRL_VOTE_MODE_CFG_1_A_I_vote_mode_cfg_1_a_i_msk_START (16)
#define SOC_PMCTRL_VOTE_MODE_CFG_1_A_I_vote_mode_cfg_1_a_i_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_a_start_en : 1;
        unsigned int freq_vote_b_start_en : 1;
        unsigned int freq_vote_c_start_en : 1;
        unsigned int freq_vote_d_start_en : 1;
        unsigned int freq_vote_e_start_en : 1;
        unsigned int freq_vote_f_start_en : 1;
        unsigned int freq_vote_g_start_en : 1;
        unsigned int freq_vote_h_start_en : 1;
        unsigned int freq_vote_i_start_en : 1;
        unsigned int reserved : 7;
        unsigned int vote_start_en_a_i_msk : 16;
    } reg;
} SOC_PMCTRL_VOTE_START_EN_A_I_UNION;
#endif
#define SOC_PMCTRL_VOTE_START_EN_A_I_freq_vote_a_start_en_START (0)
#define SOC_PMCTRL_VOTE_START_EN_A_I_freq_vote_a_start_en_END (0)
#define SOC_PMCTRL_VOTE_START_EN_A_I_freq_vote_b_start_en_START (1)
#define SOC_PMCTRL_VOTE_START_EN_A_I_freq_vote_b_start_en_END (1)
#define SOC_PMCTRL_VOTE_START_EN_A_I_freq_vote_c_start_en_START (2)
#define SOC_PMCTRL_VOTE_START_EN_A_I_freq_vote_c_start_en_END (2)
#define SOC_PMCTRL_VOTE_START_EN_A_I_freq_vote_d_start_en_START (3)
#define SOC_PMCTRL_VOTE_START_EN_A_I_freq_vote_d_start_en_END (3)
#define SOC_PMCTRL_VOTE_START_EN_A_I_freq_vote_e_start_en_START (4)
#define SOC_PMCTRL_VOTE_START_EN_A_I_freq_vote_e_start_en_END (4)
#define SOC_PMCTRL_VOTE_START_EN_A_I_freq_vote_f_start_en_START (5)
#define SOC_PMCTRL_VOTE_START_EN_A_I_freq_vote_f_start_en_END (5)
#define SOC_PMCTRL_VOTE_START_EN_A_I_freq_vote_g_start_en_START (6)
#define SOC_PMCTRL_VOTE_START_EN_A_I_freq_vote_g_start_en_END (6)
#define SOC_PMCTRL_VOTE_START_EN_A_I_freq_vote_h_start_en_START (7)
#define SOC_PMCTRL_VOTE_START_EN_A_I_freq_vote_h_start_en_END (7)
#define SOC_PMCTRL_VOTE_START_EN_A_I_freq_vote_i_start_en_START (8)
#define SOC_PMCTRL_VOTE_START_EN_A_I_freq_vote_i_start_en_END (8)
#define SOC_PMCTRL_VOTE_START_EN_A_I_vote_start_en_a_i_msk_START (16)
#define SOC_PMCTRL_VOTE_START_EN_A_I_vote_start_en_a_i_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_freq_vote_en_a : 1;
        unsigned int int_freq_vote_en_b : 1;
        unsigned int int_freq_vote_en_c : 1;
        unsigned int int_freq_vote_en_d : 1;
        unsigned int int_freq_vote_en_e : 1;
        unsigned int int_freq_vote_en_f : 1;
        unsigned int int_freq_vote_en_g : 1;
        unsigned int int_freq_vote_en_h : 1;
        unsigned int int_freq_vote_en_i : 1;
        unsigned int reserved : 7;
        unsigned int int_vote_en_a_i_msk : 16;
    } reg;
} SOC_PMCTRL_INT_VOTE_EN_A_I_UNION;
#endif
#define SOC_PMCTRL_INT_VOTE_EN_A_I_int_freq_vote_en_a_START (0)
#define SOC_PMCTRL_INT_VOTE_EN_A_I_int_freq_vote_en_a_END (0)
#define SOC_PMCTRL_INT_VOTE_EN_A_I_int_freq_vote_en_b_START (1)
#define SOC_PMCTRL_INT_VOTE_EN_A_I_int_freq_vote_en_b_END (1)
#define SOC_PMCTRL_INT_VOTE_EN_A_I_int_freq_vote_en_c_START (2)
#define SOC_PMCTRL_INT_VOTE_EN_A_I_int_freq_vote_en_c_END (2)
#define SOC_PMCTRL_INT_VOTE_EN_A_I_int_freq_vote_en_d_START (3)
#define SOC_PMCTRL_INT_VOTE_EN_A_I_int_freq_vote_en_d_END (3)
#define SOC_PMCTRL_INT_VOTE_EN_A_I_int_freq_vote_en_e_START (4)
#define SOC_PMCTRL_INT_VOTE_EN_A_I_int_freq_vote_en_e_END (4)
#define SOC_PMCTRL_INT_VOTE_EN_A_I_int_freq_vote_en_f_START (5)
#define SOC_PMCTRL_INT_VOTE_EN_A_I_int_freq_vote_en_f_END (5)
#define SOC_PMCTRL_INT_VOTE_EN_A_I_int_freq_vote_en_g_START (6)
#define SOC_PMCTRL_INT_VOTE_EN_A_I_int_freq_vote_en_g_END (6)
#define SOC_PMCTRL_INT_VOTE_EN_A_I_int_freq_vote_en_h_START (7)
#define SOC_PMCTRL_INT_VOTE_EN_A_I_int_freq_vote_en_h_END (7)
#define SOC_PMCTRL_INT_VOTE_EN_A_I_int_freq_vote_en_i_START (8)
#define SOC_PMCTRL_INT_VOTE_EN_A_I_int_freq_vote_en_i_END (8)
#define SOC_PMCTRL_INT_VOTE_EN_A_I_int_vote_en_a_i_msk_START (16)
#define SOC_PMCTRL_INT_VOTE_EN_A_I_int_vote_en_a_i_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_freq_vote_a_clr : 1;
        unsigned int int_freq_vote_b_clr : 1;
        unsigned int int_freq_vote_c_clr : 1;
        unsigned int int_freq_vote_d_clr : 1;
        unsigned int int_freq_vote_e_clr : 1;
        unsigned int int_freq_vote_f_clr : 1;
        unsigned int int_freq_vote_g_clr : 1;
        unsigned int int_freq_vote_h_clr : 1;
        unsigned int int_freq_vote_i_clr : 1;
        unsigned int reserved_0 : 7;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_PMCTRL_INT_VOTE_CLR_A_I_UNION;
#endif
#define SOC_PMCTRL_INT_VOTE_CLR_A_I_int_freq_vote_a_clr_START (0)
#define SOC_PMCTRL_INT_VOTE_CLR_A_I_int_freq_vote_a_clr_END (0)
#define SOC_PMCTRL_INT_VOTE_CLR_A_I_int_freq_vote_b_clr_START (1)
#define SOC_PMCTRL_INT_VOTE_CLR_A_I_int_freq_vote_b_clr_END (1)
#define SOC_PMCTRL_INT_VOTE_CLR_A_I_int_freq_vote_c_clr_START (2)
#define SOC_PMCTRL_INT_VOTE_CLR_A_I_int_freq_vote_c_clr_END (2)
#define SOC_PMCTRL_INT_VOTE_CLR_A_I_int_freq_vote_d_clr_START (3)
#define SOC_PMCTRL_INT_VOTE_CLR_A_I_int_freq_vote_d_clr_END (3)
#define SOC_PMCTRL_INT_VOTE_CLR_A_I_int_freq_vote_e_clr_START (4)
#define SOC_PMCTRL_INT_VOTE_CLR_A_I_int_freq_vote_e_clr_END (4)
#define SOC_PMCTRL_INT_VOTE_CLR_A_I_int_freq_vote_f_clr_START (5)
#define SOC_PMCTRL_INT_VOTE_CLR_A_I_int_freq_vote_f_clr_END (5)
#define SOC_PMCTRL_INT_VOTE_CLR_A_I_int_freq_vote_g_clr_START (6)
#define SOC_PMCTRL_INT_VOTE_CLR_A_I_int_freq_vote_g_clr_END (6)
#define SOC_PMCTRL_INT_VOTE_CLR_A_I_int_freq_vote_h_clr_START (7)
#define SOC_PMCTRL_INT_VOTE_CLR_A_I_int_freq_vote_h_clr_END (7)
#define SOC_PMCTRL_INT_VOTE_CLR_A_I_int_freq_vote_i_clr_START (8)
#define SOC_PMCTRL_INT_VOTE_CLR_A_I_int_freq_vote_i_clr_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_freq_vote_raw_stat_a : 1;
        unsigned int int_freq_vote_raw_stat_b : 1;
        unsigned int int_freq_vote_raw_stat_c : 1;
        unsigned int int_freq_vote_raw_stat_d : 1;
        unsigned int int_freq_vote_raw_stat_e : 1;
        unsigned int int_freq_vote_raw_stat_f : 1;
        unsigned int int_freq_vote_raw_stat_g : 1;
        unsigned int int_freq_vote_raw_stat_h : 1;
        unsigned int int_freq_vote_raw_stat_i : 1;
        unsigned int reserved_0 : 7;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_PMCTRL_INT_VOTE_RAW_STAT_A_I_UNION;
#endif
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_A_I_int_freq_vote_raw_stat_a_START (0)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_A_I_int_freq_vote_raw_stat_a_END (0)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_A_I_int_freq_vote_raw_stat_b_START (1)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_A_I_int_freq_vote_raw_stat_b_END (1)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_A_I_int_freq_vote_raw_stat_c_START (2)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_A_I_int_freq_vote_raw_stat_c_END (2)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_A_I_int_freq_vote_raw_stat_d_START (3)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_A_I_int_freq_vote_raw_stat_d_END (3)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_A_I_int_freq_vote_raw_stat_e_START (4)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_A_I_int_freq_vote_raw_stat_e_END (4)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_A_I_int_freq_vote_raw_stat_f_START (5)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_A_I_int_freq_vote_raw_stat_f_END (5)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_A_I_int_freq_vote_raw_stat_g_START (6)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_A_I_int_freq_vote_raw_stat_g_END (6)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_A_I_int_freq_vote_raw_stat_h_START (7)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_A_I_int_freq_vote_raw_stat_h_END (7)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_A_I_int_freq_vote_raw_stat_i_START (8)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_A_I_int_freq_vote_raw_stat_i_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_freq_vote_stat_a : 1;
        unsigned int int_freq_vote_stat_b : 1;
        unsigned int int_freq_vote_stat_c : 1;
        unsigned int int_freq_vote_stat_d : 1;
        unsigned int int_freq_vote_stat_e : 1;
        unsigned int int_freq_vote_stat_f : 1;
        unsigned int int_freq_vote_stat_g : 1;
        unsigned int int_freq_vote_stat_h : 1;
        unsigned int int_freq_vote_stat_i : 1;
        unsigned int reserved_0 : 7;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_PMCTRL_INT_VOTE_STAT_A_I_UNION;
#endif
#define SOC_PMCTRL_INT_VOTE_STAT_A_I_int_freq_vote_stat_a_START (0)
#define SOC_PMCTRL_INT_VOTE_STAT_A_I_int_freq_vote_stat_a_END (0)
#define SOC_PMCTRL_INT_VOTE_STAT_A_I_int_freq_vote_stat_b_START (1)
#define SOC_PMCTRL_INT_VOTE_STAT_A_I_int_freq_vote_stat_b_END (1)
#define SOC_PMCTRL_INT_VOTE_STAT_A_I_int_freq_vote_stat_c_START (2)
#define SOC_PMCTRL_INT_VOTE_STAT_A_I_int_freq_vote_stat_c_END (2)
#define SOC_PMCTRL_INT_VOTE_STAT_A_I_int_freq_vote_stat_d_START (3)
#define SOC_PMCTRL_INT_VOTE_STAT_A_I_int_freq_vote_stat_d_END (3)
#define SOC_PMCTRL_INT_VOTE_STAT_A_I_int_freq_vote_stat_e_START (4)
#define SOC_PMCTRL_INT_VOTE_STAT_A_I_int_freq_vote_stat_e_END (4)
#define SOC_PMCTRL_INT_VOTE_STAT_A_I_int_freq_vote_stat_f_START (5)
#define SOC_PMCTRL_INT_VOTE_STAT_A_I_int_freq_vote_stat_f_END (5)
#define SOC_PMCTRL_INT_VOTE_STAT_A_I_int_freq_vote_stat_g_START (6)
#define SOC_PMCTRL_INT_VOTE_STAT_A_I_int_freq_vote_stat_g_END (6)
#define SOC_PMCTRL_INT_VOTE_STAT_A_I_int_freq_vote_stat_h_START (7)
#define SOC_PMCTRL_INT_VOTE_STAT_A_I_int_freq_vote_stat_h_END (7)
#define SOC_PMCTRL_INT_VOTE_STAT_A_I_int_freq_vote_stat_i_START (8)
#define SOC_PMCTRL_INT_VOTE_STAT_A_I_int_freq_vote_stat_i_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_frequency_vote_a_i : 1;
        unsigned int intr_freq_vote_to_cpu_lp_ctrl_a_i : 1;
        unsigned int intr_freq_vote_to_gpu_lp_ctrl_a_i : 1;
        unsigned int intr_freq_vote_to_ddr_lp_ctrl_a_i : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_PMCTRL_INT_FREQUENCY_VOTE_A_I_UNION;
#endif
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_A_I_int_frequency_vote_a_i_START (0)
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_A_I_int_frequency_vote_a_i_END (0)
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_A_I_intr_freq_vote_to_cpu_lp_ctrl_a_i_START (1)
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_A_I_intr_freq_vote_to_cpu_lp_ctrl_a_i_END (1)
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_A_I_intr_freq_vote_to_gpu_lp_ctrl_a_i_START (2)
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_A_I_intr_freq_vote_to_gpu_lp_ctrl_a_i_END (2)
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_A_I_intr_freq_vote_to_ddr_lp_ctrl_a_i_START (3)
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_A_I_intr_freq_vote_to_ddr_lp_ctrl_a_i_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_result_a : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_VOTE_RESULT_A_UNION;
#endif
#define SOC_PMCTRL_VOTE_RESULT_A_freq_vote_result_a_START (0)
#define SOC_PMCTRL_VOTE_RESULT_A_freq_vote_result_a_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_result_b : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_VOTE_RESULT_B_UNION;
#endif
#define SOC_PMCTRL_VOTE_RESULT_B_freq_vote_result_b_START (0)
#define SOC_PMCTRL_VOTE_RESULT_B_freq_vote_result_b_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_result_c : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_VOTE_RESULT_C_UNION;
#endif
#define SOC_PMCTRL_VOTE_RESULT_C_freq_vote_result_c_START (0)
#define SOC_PMCTRL_VOTE_RESULT_C_freq_vote_result_c_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_result_d : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_VOTE_RESULT_D_UNION;
#endif
#define SOC_PMCTRL_VOTE_RESULT_D_freq_vote_result_d_START (0)
#define SOC_PMCTRL_VOTE_RESULT_D_freq_vote_result_d_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_result_e : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_VOTE_RESULT_E_UNION;
#endif
#define SOC_PMCTRL_VOTE_RESULT_E_freq_vote_result_e_START (0)
#define SOC_PMCTRL_VOTE_RESULT_E_freq_vote_result_e_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_result_f : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_VOTE_RESULT_F_UNION;
#endif
#define SOC_PMCTRL_VOTE_RESULT_F_freq_vote_result_f_START (0)
#define SOC_PMCTRL_VOTE_RESULT_F_freq_vote_result_f_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_result_g : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_VOTE_RESULT_G_UNION;
#endif
#define SOC_PMCTRL_VOTE_RESULT_G_freq_vote_result_g_START (0)
#define SOC_PMCTRL_VOTE_RESULT_G_freq_vote_result_g_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_result_h : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_VOTE_RESULT_H_UNION;
#endif
#define SOC_PMCTRL_VOTE_RESULT_H_freq_vote_result_h_START (0)
#define SOC_PMCTRL_VOTE_RESULT_H_freq_vote_result_h_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_result_i : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_VOTE_RESULT_I_UNION;
#endif
#define SOC_PMCTRL_VOTE_RESULT_I_freq_vote_result_i_START (0)
#define SOC_PMCTRL_VOTE_RESULT_I_freq_vote_result_i_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_j_channel0 : 15;
        unsigned int freq_vote_j0_msk0 : 1;
        unsigned int freq_vote_j_channel1 : 15;
        unsigned int freq_vote_j0_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_J0_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_J0_freq_vote_j_channel0_START (0)
#define SOC_PMCTRL_FREQ_VOTE_J0_freq_vote_j_channel0_END (14)
#define SOC_PMCTRL_FREQ_VOTE_J0_freq_vote_j0_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_J0_freq_vote_j0_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_J0_freq_vote_j_channel1_START (16)
#define SOC_PMCTRL_FREQ_VOTE_J0_freq_vote_j_channel1_END (30)
#define SOC_PMCTRL_FREQ_VOTE_J0_freq_vote_j0_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_J0_freq_vote_j0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_j_channel2 : 15;
        unsigned int freq_vote_j1_msk0 : 1;
        unsigned int freq_vote_j_channel3 : 15;
        unsigned int freq_vote_j1_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_J1_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_J1_freq_vote_j_channel2_START (0)
#define SOC_PMCTRL_FREQ_VOTE_J1_freq_vote_j_channel2_END (14)
#define SOC_PMCTRL_FREQ_VOTE_J1_freq_vote_j1_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_J1_freq_vote_j1_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_J1_freq_vote_j_channel3_START (16)
#define SOC_PMCTRL_FREQ_VOTE_J1_freq_vote_j_channel3_END (30)
#define SOC_PMCTRL_FREQ_VOTE_J1_freq_vote_j1_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_J1_freq_vote_j1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_k_channel0 : 15;
        unsigned int freq_vote_k0_msk0 : 1;
        unsigned int freq_vote_k_channel1 : 15;
        unsigned int freq_vote_k0_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_K0_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_K0_freq_vote_k_channel0_START (0)
#define SOC_PMCTRL_FREQ_VOTE_K0_freq_vote_k_channel0_END (14)
#define SOC_PMCTRL_FREQ_VOTE_K0_freq_vote_k0_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_K0_freq_vote_k0_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_K0_freq_vote_k_channel1_START (16)
#define SOC_PMCTRL_FREQ_VOTE_K0_freq_vote_k_channel1_END (30)
#define SOC_PMCTRL_FREQ_VOTE_K0_freq_vote_k0_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_K0_freq_vote_k0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_k_channel2 : 15;
        unsigned int freq_vote_k1_msk0 : 1;
        unsigned int freq_vote_k_channel3 : 15;
        unsigned int freq_vote_k1_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_K1_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_K1_freq_vote_k_channel2_START (0)
#define SOC_PMCTRL_FREQ_VOTE_K1_freq_vote_k_channel2_END (14)
#define SOC_PMCTRL_FREQ_VOTE_K1_freq_vote_k1_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_K1_freq_vote_k1_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_K1_freq_vote_k_channel3_START (16)
#define SOC_PMCTRL_FREQ_VOTE_K1_freq_vote_k_channel3_END (30)
#define SOC_PMCTRL_FREQ_VOTE_K1_freq_vote_k1_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_K1_freq_vote_k1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_l_channel0 : 15;
        unsigned int freq_vote_l0_msk0 : 1;
        unsigned int freq_vote_l_channel1 : 15;
        unsigned int freq_vote_l0_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_L0_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_L0_freq_vote_l_channel0_START (0)
#define SOC_PMCTRL_FREQ_VOTE_L0_freq_vote_l_channel0_END (14)
#define SOC_PMCTRL_FREQ_VOTE_L0_freq_vote_l0_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_L0_freq_vote_l0_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_L0_freq_vote_l_channel1_START (16)
#define SOC_PMCTRL_FREQ_VOTE_L0_freq_vote_l_channel1_END (30)
#define SOC_PMCTRL_FREQ_VOTE_L0_freq_vote_l0_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_L0_freq_vote_l0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_l_channel2 : 15;
        unsigned int freq_vote_l1_msk0 : 1;
        unsigned int freq_vote_l_channel3 : 15;
        unsigned int freq_vote_l1_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_L1_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_L1_freq_vote_l_channel2_START (0)
#define SOC_PMCTRL_FREQ_VOTE_L1_freq_vote_l_channel2_END (14)
#define SOC_PMCTRL_FREQ_VOTE_L1_freq_vote_l1_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_L1_freq_vote_l1_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_L1_freq_vote_l_channel3_START (16)
#define SOC_PMCTRL_FREQ_VOTE_L1_freq_vote_l_channel3_END (30)
#define SOC_PMCTRL_FREQ_VOTE_L1_freq_vote_l1_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_L1_freq_vote_l1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_m_channel0 : 15;
        unsigned int freq_vote_m0_msk0 : 1;
        unsigned int freq_vote_m_channel1 : 15;
        unsigned int freq_vote_m0_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_M0_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_M0_freq_vote_m_channel0_START (0)
#define SOC_PMCTRL_FREQ_VOTE_M0_freq_vote_m_channel0_END (14)
#define SOC_PMCTRL_FREQ_VOTE_M0_freq_vote_m0_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_M0_freq_vote_m0_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_M0_freq_vote_m_channel1_START (16)
#define SOC_PMCTRL_FREQ_VOTE_M0_freq_vote_m_channel1_END (30)
#define SOC_PMCTRL_FREQ_VOTE_M0_freq_vote_m0_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_M0_freq_vote_m0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_m_channel2 : 15;
        unsigned int freq_vote_m1_msk0 : 1;
        unsigned int freq_vote_m_channel3 : 15;
        unsigned int freq_vote_m1_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_M1_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_M1_freq_vote_m_channel2_START (0)
#define SOC_PMCTRL_FREQ_VOTE_M1_freq_vote_m_channel2_END (14)
#define SOC_PMCTRL_FREQ_VOTE_M1_freq_vote_m1_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_M1_freq_vote_m1_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_M1_freq_vote_m_channel3_START (16)
#define SOC_PMCTRL_FREQ_VOTE_M1_freq_vote_m_channel3_END (30)
#define SOC_PMCTRL_FREQ_VOTE_M1_freq_vote_m1_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_M1_freq_vote_m1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_n_channel0 : 15;
        unsigned int freq_vote_n0_msk0 : 1;
        unsigned int freq_vote_n_channel1 : 15;
        unsigned int freq_vote_n0_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_N0_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_N0_freq_vote_n_channel0_START (0)
#define SOC_PMCTRL_FREQ_VOTE_N0_freq_vote_n_channel0_END (14)
#define SOC_PMCTRL_FREQ_VOTE_N0_freq_vote_n0_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_N0_freq_vote_n0_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_N0_freq_vote_n_channel1_START (16)
#define SOC_PMCTRL_FREQ_VOTE_N0_freq_vote_n_channel1_END (30)
#define SOC_PMCTRL_FREQ_VOTE_N0_freq_vote_n0_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_N0_freq_vote_n0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_n_channel2 : 15;
        unsigned int freq_vote_n1_msk0 : 1;
        unsigned int freq_vote_n_channel3 : 15;
        unsigned int freq_vote_n1_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_N1_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_N1_freq_vote_n_channel2_START (0)
#define SOC_PMCTRL_FREQ_VOTE_N1_freq_vote_n_channel2_END (14)
#define SOC_PMCTRL_FREQ_VOTE_N1_freq_vote_n1_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_N1_freq_vote_n1_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_N1_freq_vote_n_channel3_START (16)
#define SOC_PMCTRL_FREQ_VOTE_N1_freq_vote_n_channel3_END (30)
#define SOC_PMCTRL_FREQ_VOTE_N1_freq_vote_n1_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_N1_freq_vote_n1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_n_channel4 : 15;
        unsigned int freq_vote_n2_msk0 : 1;
        unsigned int freq_vote_n_channel5 : 15;
        unsigned int freq_vote_n2_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_N2_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_N2_freq_vote_n_channel4_START (0)
#define SOC_PMCTRL_FREQ_VOTE_N2_freq_vote_n_channel4_END (14)
#define SOC_PMCTRL_FREQ_VOTE_N2_freq_vote_n2_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_N2_freq_vote_n2_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_N2_freq_vote_n_channel5_START (16)
#define SOC_PMCTRL_FREQ_VOTE_N2_freq_vote_n_channel5_END (30)
#define SOC_PMCTRL_FREQ_VOTE_N2_freq_vote_n2_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_N2_freq_vote_n2_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_n_channel6 : 15;
        unsigned int freq_vote_n3_msk0 : 1;
        unsigned int freq_vote_n_channel7 : 15;
        unsigned int freq_vote_n3_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_N3_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_N3_freq_vote_n_channel6_START (0)
#define SOC_PMCTRL_FREQ_VOTE_N3_freq_vote_n_channel6_END (14)
#define SOC_PMCTRL_FREQ_VOTE_N3_freq_vote_n3_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_N3_freq_vote_n3_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_N3_freq_vote_n_channel7_START (16)
#define SOC_PMCTRL_FREQ_VOTE_N3_freq_vote_n_channel7_END (30)
#define SOC_PMCTRL_FREQ_VOTE_N3_freq_vote_n3_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_N3_freq_vote_n3_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_o_channel0 : 15;
        unsigned int freq_vote_o0_msk0 : 1;
        unsigned int freq_vote_o_channel1 : 15;
        unsigned int freq_vote_o0_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_O0_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_O0_freq_vote_o_channel0_START (0)
#define SOC_PMCTRL_FREQ_VOTE_O0_freq_vote_o_channel0_END (14)
#define SOC_PMCTRL_FREQ_VOTE_O0_freq_vote_o0_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_O0_freq_vote_o0_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_O0_freq_vote_o_channel1_START (16)
#define SOC_PMCTRL_FREQ_VOTE_O0_freq_vote_o_channel1_END (30)
#define SOC_PMCTRL_FREQ_VOTE_O0_freq_vote_o0_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_O0_freq_vote_o0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_o_channel2 : 15;
        unsigned int freq_vote_o1_msk0 : 1;
        unsigned int freq_vote_o_channel3 : 15;
        unsigned int freq_vote_o1_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_O1_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_O1_freq_vote_o_channel2_START (0)
#define SOC_PMCTRL_FREQ_VOTE_O1_freq_vote_o_channel2_END (14)
#define SOC_PMCTRL_FREQ_VOTE_O1_freq_vote_o1_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_O1_freq_vote_o1_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_O1_freq_vote_o_channel3_START (16)
#define SOC_PMCTRL_FREQ_VOTE_O1_freq_vote_o_channel3_END (30)
#define SOC_PMCTRL_FREQ_VOTE_O1_freq_vote_o1_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_O1_freq_vote_o1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_o_channel4 : 15;
        unsigned int freq_vote_o2_msk0 : 1;
        unsigned int freq_vote_o_channel5 : 15;
        unsigned int freq_vote_o2_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_O2_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_O2_freq_vote_o_channel4_START (0)
#define SOC_PMCTRL_FREQ_VOTE_O2_freq_vote_o_channel4_END (14)
#define SOC_PMCTRL_FREQ_VOTE_O2_freq_vote_o2_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_O2_freq_vote_o2_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_O2_freq_vote_o_channel5_START (16)
#define SOC_PMCTRL_FREQ_VOTE_O2_freq_vote_o_channel5_END (30)
#define SOC_PMCTRL_FREQ_VOTE_O2_freq_vote_o2_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_O2_freq_vote_o2_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_o_channel6 : 15;
        unsigned int freq_vote_o3_msk0 : 1;
        unsigned int freq_vote_o_channel7 : 15;
        unsigned int freq_vote_o3_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_O3_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_O3_freq_vote_o_channel6_START (0)
#define SOC_PMCTRL_FREQ_VOTE_O3_freq_vote_o_channel6_END (14)
#define SOC_PMCTRL_FREQ_VOTE_O3_freq_vote_o3_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_O3_freq_vote_o3_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_O3_freq_vote_o_channel7_START (16)
#define SOC_PMCTRL_FREQ_VOTE_O3_freq_vote_o_channel7_END (30)
#define SOC_PMCTRL_FREQ_VOTE_O3_freq_vote_o3_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_O3_freq_vote_o3_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_p_channel0 : 15;
        unsigned int freq_vote_p0_msk0 : 1;
        unsigned int freq_vote_p_channel1 : 15;
        unsigned int freq_vote_p0_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_P0_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_P0_freq_vote_p_channel0_START (0)
#define SOC_PMCTRL_FREQ_VOTE_P0_freq_vote_p_channel0_END (14)
#define SOC_PMCTRL_FREQ_VOTE_P0_freq_vote_p0_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_P0_freq_vote_p0_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_P0_freq_vote_p_channel1_START (16)
#define SOC_PMCTRL_FREQ_VOTE_P0_freq_vote_p_channel1_END (30)
#define SOC_PMCTRL_FREQ_VOTE_P0_freq_vote_p0_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_P0_freq_vote_p0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_p_channel2 : 15;
        unsigned int freq_vote_p1_msk0 : 1;
        unsigned int freq_vote_p_channel3 : 15;
        unsigned int freq_vote_p1_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_P1_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_P1_freq_vote_p_channel2_START (0)
#define SOC_PMCTRL_FREQ_VOTE_P1_freq_vote_p_channel2_END (14)
#define SOC_PMCTRL_FREQ_VOTE_P1_freq_vote_p1_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_P1_freq_vote_p1_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_P1_freq_vote_p_channel3_START (16)
#define SOC_PMCTRL_FREQ_VOTE_P1_freq_vote_p_channel3_END (30)
#define SOC_PMCTRL_FREQ_VOTE_P1_freq_vote_p1_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_P1_freq_vote_p1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_p_channel4 : 15;
        unsigned int freq_vote_p2_msk0 : 1;
        unsigned int freq_vote_p_channel5 : 15;
        unsigned int freq_vote_p2_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_P2_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_P2_freq_vote_p_channel4_START (0)
#define SOC_PMCTRL_FREQ_VOTE_P2_freq_vote_p_channel4_END (14)
#define SOC_PMCTRL_FREQ_VOTE_P2_freq_vote_p2_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_P2_freq_vote_p2_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_P2_freq_vote_p_channel5_START (16)
#define SOC_PMCTRL_FREQ_VOTE_P2_freq_vote_p_channel5_END (30)
#define SOC_PMCTRL_FREQ_VOTE_P2_freq_vote_p2_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_P2_freq_vote_p2_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_p_channel6 : 15;
        unsigned int freq_vote_p3_msk0 : 1;
        unsigned int freq_vote_p_channel7 : 15;
        unsigned int freq_vote_p3_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_P3_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_P3_freq_vote_p_channel6_START (0)
#define SOC_PMCTRL_FREQ_VOTE_P3_freq_vote_p_channel6_END (14)
#define SOC_PMCTRL_FREQ_VOTE_P3_freq_vote_p3_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_P3_freq_vote_p3_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_P3_freq_vote_p_channel7_START (16)
#define SOC_PMCTRL_FREQ_VOTE_P3_freq_vote_p_channel7_END (30)
#define SOC_PMCTRL_FREQ_VOTE_P3_freq_vote_p3_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_P3_freq_vote_p3_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_q_channel0 : 15;
        unsigned int freq_vote_q0_msk0 : 1;
        unsigned int freq_vote_q_channel1 : 15;
        unsigned int freq_vote_q0_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_Q0_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_Q0_freq_vote_q_channel0_START (0)
#define SOC_PMCTRL_FREQ_VOTE_Q0_freq_vote_q_channel0_END (14)
#define SOC_PMCTRL_FREQ_VOTE_Q0_freq_vote_q0_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_Q0_freq_vote_q0_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_Q0_freq_vote_q_channel1_START (16)
#define SOC_PMCTRL_FREQ_VOTE_Q0_freq_vote_q_channel1_END (30)
#define SOC_PMCTRL_FREQ_VOTE_Q0_freq_vote_q0_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_Q0_freq_vote_q0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_q_channel2 : 15;
        unsigned int freq_vote_q1_msk0 : 1;
        unsigned int freq_vote_q_channel3 : 15;
        unsigned int freq_vote_q1_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_Q1_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_Q1_freq_vote_q_channel2_START (0)
#define SOC_PMCTRL_FREQ_VOTE_Q1_freq_vote_q_channel2_END (14)
#define SOC_PMCTRL_FREQ_VOTE_Q1_freq_vote_q1_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_Q1_freq_vote_q1_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_Q1_freq_vote_q_channel3_START (16)
#define SOC_PMCTRL_FREQ_VOTE_Q1_freq_vote_q_channel3_END (30)
#define SOC_PMCTRL_FREQ_VOTE_Q1_freq_vote_q1_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_Q1_freq_vote_q1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_q_channel4 : 15;
        unsigned int freq_vote_q2_msk0 : 1;
        unsigned int freq_vote_q_channel5 : 15;
        unsigned int freq_vote_q2_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_Q2_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_Q2_freq_vote_q_channel4_START (0)
#define SOC_PMCTRL_FREQ_VOTE_Q2_freq_vote_q_channel4_END (14)
#define SOC_PMCTRL_FREQ_VOTE_Q2_freq_vote_q2_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_Q2_freq_vote_q2_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_Q2_freq_vote_q_channel5_START (16)
#define SOC_PMCTRL_FREQ_VOTE_Q2_freq_vote_q_channel5_END (30)
#define SOC_PMCTRL_FREQ_VOTE_Q2_freq_vote_q2_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_Q2_freq_vote_q2_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_q_channel6 : 15;
        unsigned int freq_vote_q3_msk0 : 1;
        unsigned int freq_vote_q_channel7 : 15;
        unsigned int freq_vote_q3_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_Q3_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_Q3_freq_vote_q_channel6_START (0)
#define SOC_PMCTRL_FREQ_VOTE_Q3_freq_vote_q_channel6_END (14)
#define SOC_PMCTRL_FREQ_VOTE_Q3_freq_vote_q3_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_Q3_freq_vote_q3_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_Q3_freq_vote_q_channel7_START (16)
#define SOC_PMCTRL_FREQ_VOTE_Q3_freq_vote_q_channel7_END (30)
#define SOC_PMCTRL_FREQ_VOTE_Q3_freq_vote_q3_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_Q3_freq_vote_q3_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_q_channel8 : 15;
        unsigned int freq_vote_q4_msk0 : 1;
        unsigned int freq_vote_q_channel9 : 15;
        unsigned int freq_vote_q4_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_Q4_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_Q4_freq_vote_q_channel8_START (0)
#define SOC_PMCTRL_FREQ_VOTE_Q4_freq_vote_q_channel8_END (14)
#define SOC_PMCTRL_FREQ_VOTE_Q4_freq_vote_q4_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_Q4_freq_vote_q4_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_Q4_freq_vote_q_channel9_START (16)
#define SOC_PMCTRL_FREQ_VOTE_Q4_freq_vote_q_channel9_END (30)
#define SOC_PMCTRL_FREQ_VOTE_Q4_freq_vote_q4_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_Q4_freq_vote_q4_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_q_channel10 : 15;
        unsigned int freq_vote_q5_msk0 : 1;
        unsigned int freq_vote_q_channel11 : 15;
        unsigned int freq_vote_q5_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_Q5_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_Q5_freq_vote_q_channel10_START (0)
#define SOC_PMCTRL_FREQ_VOTE_Q5_freq_vote_q_channel10_END (14)
#define SOC_PMCTRL_FREQ_VOTE_Q5_freq_vote_q5_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_Q5_freq_vote_q5_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_Q5_freq_vote_q_channel11_START (16)
#define SOC_PMCTRL_FREQ_VOTE_Q5_freq_vote_q_channel11_END (30)
#define SOC_PMCTRL_FREQ_VOTE_Q5_freq_vote_q5_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_Q5_freq_vote_q5_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_q_channel12 : 15;
        unsigned int freq_vote_q6_msk0 : 1;
        unsigned int freq_vote_q_channel13 : 15;
        unsigned int freq_vote_q6_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_Q6_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_Q6_freq_vote_q_channel12_START (0)
#define SOC_PMCTRL_FREQ_VOTE_Q6_freq_vote_q_channel12_END (14)
#define SOC_PMCTRL_FREQ_VOTE_Q6_freq_vote_q6_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_Q6_freq_vote_q6_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_Q6_freq_vote_q_channel13_START (16)
#define SOC_PMCTRL_FREQ_VOTE_Q6_freq_vote_q_channel13_END (30)
#define SOC_PMCTRL_FREQ_VOTE_Q6_freq_vote_q6_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_Q6_freq_vote_q6_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_q_channel14 : 15;
        unsigned int freq_vote_q7_msk0 : 1;
        unsigned int freq_vote_q_channel15 : 15;
        unsigned int freq_vote_q7_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_Q7_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_Q7_freq_vote_q_channel14_START (0)
#define SOC_PMCTRL_FREQ_VOTE_Q7_freq_vote_q_channel14_END (14)
#define SOC_PMCTRL_FREQ_VOTE_Q7_freq_vote_q7_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_Q7_freq_vote_q7_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_Q7_freq_vote_q_channel15_START (16)
#define SOC_PMCTRL_FREQ_VOTE_Q7_freq_vote_q_channel15_END (30)
#define SOC_PMCTRL_FREQ_VOTE_Q7_freq_vote_q7_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_Q7_freq_vote_q7_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_r_channel0 : 15;
        unsigned int freq_vote_r0_msk0 : 1;
        unsigned int freq_vote_r_channel1 : 15;
        unsigned int freq_vote_r0_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_R0_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_R0_freq_vote_r_channel0_START (0)
#define SOC_PMCTRL_FREQ_VOTE_R0_freq_vote_r_channel0_END (14)
#define SOC_PMCTRL_FREQ_VOTE_R0_freq_vote_r0_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_R0_freq_vote_r0_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_R0_freq_vote_r_channel1_START (16)
#define SOC_PMCTRL_FREQ_VOTE_R0_freq_vote_r_channel1_END (30)
#define SOC_PMCTRL_FREQ_VOTE_R0_freq_vote_r0_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_R0_freq_vote_r0_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_r_channel2 : 15;
        unsigned int freq_vote_r1_msk0 : 1;
        unsigned int freq_vote_r_channel3 : 15;
        unsigned int freq_vote_r1_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_R1_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_R1_freq_vote_r_channel2_START (0)
#define SOC_PMCTRL_FREQ_VOTE_R1_freq_vote_r_channel2_END (14)
#define SOC_PMCTRL_FREQ_VOTE_R1_freq_vote_r1_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_R1_freq_vote_r1_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_R1_freq_vote_r_channel3_START (16)
#define SOC_PMCTRL_FREQ_VOTE_R1_freq_vote_r_channel3_END (30)
#define SOC_PMCTRL_FREQ_VOTE_R1_freq_vote_r1_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_R1_freq_vote_r1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_r_channel4 : 15;
        unsigned int freq_vote_r2_msk0 : 1;
        unsigned int freq_vote_r_channel5 : 15;
        unsigned int freq_vote_r2_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_R2_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_R2_freq_vote_r_channel4_START (0)
#define SOC_PMCTRL_FREQ_VOTE_R2_freq_vote_r_channel4_END (14)
#define SOC_PMCTRL_FREQ_VOTE_R2_freq_vote_r2_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_R2_freq_vote_r2_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_R2_freq_vote_r_channel5_START (16)
#define SOC_PMCTRL_FREQ_VOTE_R2_freq_vote_r_channel5_END (30)
#define SOC_PMCTRL_FREQ_VOTE_R2_freq_vote_r2_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_R2_freq_vote_r2_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_r_channel6 : 15;
        unsigned int freq_vote_r3_msk0 : 1;
        unsigned int freq_vote_r_channel7 : 15;
        unsigned int freq_vote_r3_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_R3_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_R3_freq_vote_r_channel6_START (0)
#define SOC_PMCTRL_FREQ_VOTE_R3_freq_vote_r_channel6_END (14)
#define SOC_PMCTRL_FREQ_VOTE_R3_freq_vote_r3_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_R3_freq_vote_r3_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_R3_freq_vote_r_channel7_START (16)
#define SOC_PMCTRL_FREQ_VOTE_R3_freq_vote_r_channel7_END (30)
#define SOC_PMCTRL_FREQ_VOTE_R3_freq_vote_r3_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_R3_freq_vote_r3_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_r_channel8 : 15;
        unsigned int freq_vote_r4_msk0 : 1;
        unsigned int freq_vote_r_channel9 : 15;
        unsigned int freq_vote_r4_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_R4_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_R4_freq_vote_r_channel8_START (0)
#define SOC_PMCTRL_FREQ_VOTE_R4_freq_vote_r_channel8_END (14)
#define SOC_PMCTRL_FREQ_VOTE_R4_freq_vote_r4_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_R4_freq_vote_r4_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_R4_freq_vote_r_channel9_START (16)
#define SOC_PMCTRL_FREQ_VOTE_R4_freq_vote_r_channel9_END (30)
#define SOC_PMCTRL_FREQ_VOTE_R4_freq_vote_r4_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_R4_freq_vote_r4_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_r_channel10 : 15;
        unsigned int freq_vote_r5_msk0 : 1;
        unsigned int freq_vote_r_channel11 : 15;
        unsigned int freq_vote_r5_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_R5_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_R5_freq_vote_r_channel10_START (0)
#define SOC_PMCTRL_FREQ_VOTE_R5_freq_vote_r_channel10_END (14)
#define SOC_PMCTRL_FREQ_VOTE_R5_freq_vote_r5_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_R5_freq_vote_r5_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_R5_freq_vote_r_channel11_START (16)
#define SOC_PMCTRL_FREQ_VOTE_R5_freq_vote_r_channel11_END (30)
#define SOC_PMCTRL_FREQ_VOTE_R5_freq_vote_r5_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_R5_freq_vote_r5_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_r_channel12 : 15;
        unsigned int freq_vote_r6_msk0 : 1;
        unsigned int freq_vote_r_channel13 : 15;
        unsigned int freq_vote_r6_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_R6_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_R6_freq_vote_r_channel12_START (0)
#define SOC_PMCTRL_FREQ_VOTE_R6_freq_vote_r_channel12_END (14)
#define SOC_PMCTRL_FREQ_VOTE_R6_freq_vote_r6_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_R6_freq_vote_r6_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_R6_freq_vote_r_channel13_START (16)
#define SOC_PMCTRL_FREQ_VOTE_R6_freq_vote_r_channel13_END (30)
#define SOC_PMCTRL_FREQ_VOTE_R6_freq_vote_r6_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_R6_freq_vote_r6_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_r_channel14 : 15;
        unsigned int freq_vote_r7_msk0 : 1;
        unsigned int freq_vote_r_channel15 : 15;
        unsigned int freq_vote_r7_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_R7_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_R7_freq_vote_r_channel14_START (0)
#define SOC_PMCTRL_FREQ_VOTE_R7_freq_vote_r_channel14_END (14)
#define SOC_PMCTRL_FREQ_VOTE_R7_freq_vote_r7_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_R7_freq_vote_r7_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_R7_freq_vote_r_channel15_START (16)
#define SOC_PMCTRL_FREQ_VOTE_R7_freq_vote_r_channel15_END (30)
#define SOC_PMCTRL_FREQ_VOTE_R7_freq_vote_r7_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_R7_freq_vote_r7_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_mask_to_lpmcu_j_r : 9;
        unsigned int reserved : 7;
        unsigned int intr_mask_to_lpmcu_j_r_msk : 16;
    } reg;
} SOC_PMCTRL_INTR_MASK_TO_LPMCU_J_R_UNION;
#endif
#define SOC_PMCTRL_INTR_MASK_TO_LPMCU_J_R_intr_mask_to_lpmcu_j_r_START (0)
#define SOC_PMCTRL_INTR_MASK_TO_LPMCU_J_R_intr_mask_to_lpmcu_j_r_END (8)
#define SOC_PMCTRL_INTR_MASK_TO_LPMCU_J_R_intr_mask_to_lpmcu_j_r_msk_START (16)
#define SOC_PMCTRL_INTR_MASK_TO_LPMCU_J_R_intr_mask_to_lpmcu_j_r_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_mask_to_cpu_lp_ctrl_j_r : 9;
        unsigned int reserved : 7;
        unsigned int intr_mask_to_cpu_lp_ctrl_j_r_msk : 16;
    } reg;
} SOC_PMCTRL_INTR_MASK_TO_CPU_LP_CTRL_J_R_UNION;
#endif
#define SOC_PMCTRL_INTR_MASK_TO_CPU_LP_CTRL_J_R_intr_mask_to_cpu_lp_ctrl_j_r_START (0)
#define SOC_PMCTRL_INTR_MASK_TO_CPU_LP_CTRL_J_R_intr_mask_to_cpu_lp_ctrl_j_r_END (8)
#define SOC_PMCTRL_INTR_MASK_TO_CPU_LP_CTRL_J_R_intr_mask_to_cpu_lp_ctrl_j_r_msk_START (16)
#define SOC_PMCTRL_INTR_MASK_TO_CPU_LP_CTRL_J_R_intr_mask_to_cpu_lp_ctrl_j_r_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_mask_to_gpu_lp_ctrl_j_r : 9;
        unsigned int reserved : 7;
        unsigned int intr_mask_to_gpu_lp_ctrl_j_r_msk : 16;
    } reg;
} SOC_PMCTRL_INTR_MASK_TO_GPU_LP_CTRL_J_R_UNION;
#endif
#define SOC_PMCTRL_INTR_MASK_TO_GPU_LP_CTRL_J_R_intr_mask_to_gpu_lp_ctrl_j_r_START (0)
#define SOC_PMCTRL_INTR_MASK_TO_GPU_LP_CTRL_J_R_intr_mask_to_gpu_lp_ctrl_j_r_END (8)
#define SOC_PMCTRL_INTR_MASK_TO_GPU_LP_CTRL_J_R_intr_mask_to_gpu_lp_ctrl_j_r_msk_START (16)
#define SOC_PMCTRL_INTR_MASK_TO_GPU_LP_CTRL_J_R_intr_mask_to_gpu_lp_ctrl_j_r_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_mask_to_ddr_lp_ctrl_j_r : 9;
        unsigned int reserved : 7;
        unsigned int intr_mask_to_ddr_lp_ctrl_j_r_msk : 16;
    } reg;
} SOC_PMCTRL_INTR_MASK_TO_DDR_LP_CTRL_J_R_UNION;
#endif
#define SOC_PMCTRL_INTR_MASK_TO_DDR_LP_CTRL_J_R_intr_mask_to_ddr_lp_ctrl_j_r_START (0)
#define SOC_PMCTRL_INTR_MASK_TO_DDR_LP_CTRL_J_R_intr_mask_to_ddr_lp_ctrl_j_r_END (8)
#define SOC_PMCTRL_INTR_MASK_TO_DDR_LP_CTRL_J_R_intr_mask_to_ddr_lp_ctrl_j_r_msk_START (16)
#define SOC_PMCTRL_INTR_MASK_TO_DDR_LP_CTRL_J_R_intr_mask_to_ddr_lp_ctrl_j_r_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_channel_num_j : 2;
        unsigned int freq_vote_channel_num_k : 2;
        unsigned int freq_vote_channel_num_l : 2;
        unsigned int freq_vote_channel_num_m : 2;
        unsigned int freq_vote_channel_num_n : 2;
        unsigned int freq_vote_channel_num_o : 2;
        unsigned int freq_vote_channel_num_p : 2;
        unsigned int freq_vote_channel_num_q : 2;
        unsigned int freq_vote_channel_num_r : 2;
        unsigned int reserved : 14;
    } reg;
} SOC_PMCTRL_VOTE_CHANNEL_CFG_J_R_UNION;
#endif
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_J_R_freq_vote_channel_num_j_START (0)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_J_R_freq_vote_channel_num_j_END (1)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_J_R_freq_vote_channel_num_k_START (2)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_J_R_freq_vote_channel_num_k_END (3)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_J_R_freq_vote_channel_num_l_START (4)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_J_R_freq_vote_channel_num_l_END (5)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_J_R_freq_vote_channel_num_m_START (6)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_J_R_freq_vote_channel_num_m_END (7)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_J_R_freq_vote_channel_num_n_START (8)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_J_R_freq_vote_channel_num_n_END (9)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_J_R_freq_vote_channel_num_o_START (10)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_J_R_freq_vote_channel_num_o_END (11)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_J_R_freq_vote_channel_num_p_START (12)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_J_R_freq_vote_channel_num_p_END (13)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_J_R_freq_vote_channel_num_q_START (14)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_J_R_freq_vote_channel_num_q_END (15)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_J_R_freq_vote_channel_num_r_START (16)
#define SOC_PMCTRL_VOTE_CHANNEL_CFG_J_R_freq_vote_channel_num_r_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_j_type : 2;
        unsigned int freq_vote_k_type : 2;
        unsigned int freq_vote_l_type : 2;
        unsigned int freq_vote_m_type : 2;
        unsigned int freq_vote_n_type : 2;
        unsigned int freq_vote_o_type : 2;
        unsigned int freq_vote_p_type : 2;
        unsigned int freq_vote_q_type : 2;
        unsigned int vote_mode_cfg_0_j_r_msk : 16;
    } reg;
} SOC_PMCTRL_VOTE_MODE_CFG_0_J_R_UNION;
#endif
#define SOC_PMCTRL_VOTE_MODE_CFG_0_J_R_freq_vote_j_type_START (0)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_J_R_freq_vote_j_type_END (1)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_J_R_freq_vote_k_type_START (2)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_J_R_freq_vote_k_type_END (3)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_J_R_freq_vote_l_type_START (4)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_J_R_freq_vote_l_type_END (5)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_J_R_freq_vote_m_type_START (6)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_J_R_freq_vote_m_type_END (7)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_J_R_freq_vote_n_type_START (8)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_J_R_freq_vote_n_type_END (9)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_J_R_freq_vote_o_type_START (10)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_J_R_freq_vote_o_type_END (11)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_J_R_freq_vote_p_type_START (12)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_J_R_freq_vote_p_type_END (13)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_J_R_freq_vote_q_type_START (14)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_J_R_freq_vote_q_type_END (15)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_J_R_vote_mode_cfg_0_j_r_msk_START (16)
#define SOC_PMCTRL_VOTE_MODE_CFG_0_J_R_vote_mode_cfg_0_j_r_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_r_type : 2;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 2;
        unsigned int reserved_3 : 2;
        unsigned int reserved_4 : 2;
        unsigned int reserved_5 : 2;
        unsigned int reserved_6 : 2;
        unsigned int vote_mode_cfg_1_j_r_msk : 16;
    } reg;
} SOC_PMCTRL_VOTE_MODE_CFG_1_J_R_UNION;
#endif
#define SOC_PMCTRL_VOTE_MODE_CFG_1_J_R_freq_vote_r_type_START (0)
#define SOC_PMCTRL_VOTE_MODE_CFG_1_J_R_freq_vote_r_type_END (1)
#define SOC_PMCTRL_VOTE_MODE_CFG_1_J_R_vote_mode_cfg_1_j_r_msk_START (16)
#define SOC_PMCTRL_VOTE_MODE_CFG_1_J_R_vote_mode_cfg_1_j_r_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_j_start_en : 1;
        unsigned int freq_vote_k_start_en : 1;
        unsigned int freq_vote_l_start_en : 1;
        unsigned int freq_vote_m_start_en : 1;
        unsigned int freq_vote_n_start_en : 1;
        unsigned int freq_vote_o_start_en : 1;
        unsigned int freq_vote_p_start_en : 1;
        unsigned int freq_vote_q_start_en : 1;
        unsigned int freq_vote_r_start_en : 1;
        unsigned int reserved : 7;
        unsigned int vote_start_en_j_r_msk : 16;
    } reg;
} SOC_PMCTRL_VOTE_START_EN_J_R_UNION;
#endif
#define SOC_PMCTRL_VOTE_START_EN_J_R_freq_vote_j_start_en_START (0)
#define SOC_PMCTRL_VOTE_START_EN_J_R_freq_vote_j_start_en_END (0)
#define SOC_PMCTRL_VOTE_START_EN_J_R_freq_vote_k_start_en_START (1)
#define SOC_PMCTRL_VOTE_START_EN_J_R_freq_vote_k_start_en_END (1)
#define SOC_PMCTRL_VOTE_START_EN_J_R_freq_vote_l_start_en_START (2)
#define SOC_PMCTRL_VOTE_START_EN_J_R_freq_vote_l_start_en_END (2)
#define SOC_PMCTRL_VOTE_START_EN_J_R_freq_vote_m_start_en_START (3)
#define SOC_PMCTRL_VOTE_START_EN_J_R_freq_vote_m_start_en_END (3)
#define SOC_PMCTRL_VOTE_START_EN_J_R_freq_vote_n_start_en_START (4)
#define SOC_PMCTRL_VOTE_START_EN_J_R_freq_vote_n_start_en_END (4)
#define SOC_PMCTRL_VOTE_START_EN_J_R_freq_vote_o_start_en_START (5)
#define SOC_PMCTRL_VOTE_START_EN_J_R_freq_vote_o_start_en_END (5)
#define SOC_PMCTRL_VOTE_START_EN_J_R_freq_vote_p_start_en_START (6)
#define SOC_PMCTRL_VOTE_START_EN_J_R_freq_vote_p_start_en_END (6)
#define SOC_PMCTRL_VOTE_START_EN_J_R_freq_vote_q_start_en_START (7)
#define SOC_PMCTRL_VOTE_START_EN_J_R_freq_vote_q_start_en_END (7)
#define SOC_PMCTRL_VOTE_START_EN_J_R_freq_vote_r_start_en_START (8)
#define SOC_PMCTRL_VOTE_START_EN_J_R_freq_vote_r_start_en_END (8)
#define SOC_PMCTRL_VOTE_START_EN_J_R_vote_start_en_j_r_msk_START (16)
#define SOC_PMCTRL_VOTE_START_EN_J_R_vote_start_en_j_r_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_freq_vote_en_j : 1;
        unsigned int int_freq_vote_en_k : 1;
        unsigned int int_freq_vote_en_l : 1;
        unsigned int int_freq_vote_en_m : 1;
        unsigned int int_freq_vote_en_n : 1;
        unsigned int int_freq_vote_en_o : 1;
        unsigned int int_freq_vote_en_p : 1;
        unsigned int int_freq_vote_en_q : 1;
        unsigned int int_freq_vote_en_r : 1;
        unsigned int reserved : 7;
        unsigned int int_vote_en_j_r_msk : 16;
    } reg;
} SOC_PMCTRL_INT_VOTE_EN_J_R_UNION;
#endif
#define SOC_PMCTRL_INT_VOTE_EN_J_R_int_freq_vote_en_j_START (0)
#define SOC_PMCTRL_INT_VOTE_EN_J_R_int_freq_vote_en_j_END (0)
#define SOC_PMCTRL_INT_VOTE_EN_J_R_int_freq_vote_en_k_START (1)
#define SOC_PMCTRL_INT_VOTE_EN_J_R_int_freq_vote_en_k_END (1)
#define SOC_PMCTRL_INT_VOTE_EN_J_R_int_freq_vote_en_l_START (2)
#define SOC_PMCTRL_INT_VOTE_EN_J_R_int_freq_vote_en_l_END (2)
#define SOC_PMCTRL_INT_VOTE_EN_J_R_int_freq_vote_en_m_START (3)
#define SOC_PMCTRL_INT_VOTE_EN_J_R_int_freq_vote_en_m_END (3)
#define SOC_PMCTRL_INT_VOTE_EN_J_R_int_freq_vote_en_n_START (4)
#define SOC_PMCTRL_INT_VOTE_EN_J_R_int_freq_vote_en_n_END (4)
#define SOC_PMCTRL_INT_VOTE_EN_J_R_int_freq_vote_en_o_START (5)
#define SOC_PMCTRL_INT_VOTE_EN_J_R_int_freq_vote_en_o_END (5)
#define SOC_PMCTRL_INT_VOTE_EN_J_R_int_freq_vote_en_p_START (6)
#define SOC_PMCTRL_INT_VOTE_EN_J_R_int_freq_vote_en_p_END (6)
#define SOC_PMCTRL_INT_VOTE_EN_J_R_int_freq_vote_en_q_START (7)
#define SOC_PMCTRL_INT_VOTE_EN_J_R_int_freq_vote_en_q_END (7)
#define SOC_PMCTRL_INT_VOTE_EN_J_R_int_freq_vote_en_r_START (8)
#define SOC_PMCTRL_INT_VOTE_EN_J_R_int_freq_vote_en_r_END (8)
#define SOC_PMCTRL_INT_VOTE_EN_J_R_int_vote_en_j_r_msk_START (16)
#define SOC_PMCTRL_INT_VOTE_EN_J_R_int_vote_en_j_r_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_freq_vote_j_clr : 1;
        unsigned int int_freq_vote_k_clr : 1;
        unsigned int int_freq_vote_l_clr : 1;
        unsigned int int_freq_vote_m_clr : 1;
        unsigned int int_freq_vote_n_clr : 1;
        unsigned int int_freq_vote_o_clr : 1;
        unsigned int int_freq_vote_p_clr : 1;
        unsigned int int_freq_vote_q_clr : 1;
        unsigned int int_freq_vote_r_clr : 1;
        unsigned int reserved_0 : 7;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_PMCTRL_INT_VOTE_CLR_J_R_UNION;
#endif
#define SOC_PMCTRL_INT_VOTE_CLR_J_R_int_freq_vote_j_clr_START (0)
#define SOC_PMCTRL_INT_VOTE_CLR_J_R_int_freq_vote_j_clr_END (0)
#define SOC_PMCTRL_INT_VOTE_CLR_J_R_int_freq_vote_k_clr_START (1)
#define SOC_PMCTRL_INT_VOTE_CLR_J_R_int_freq_vote_k_clr_END (1)
#define SOC_PMCTRL_INT_VOTE_CLR_J_R_int_freq_vote_l_clr_START (2)
#define SOC_PMCTRL_INT_VOTE_CLR_J_R_int_freq_vote_l_clr_END (2)
#define SOC_PMCTRL_INT_VOTE_CLR_J_R_int_freq_vote_m_clr_START (3)
#define SOC_PMCTRL_INT_VOTE_CLR_J_R_int_freq_vote_m_clr_END (3)
#define SOC_PMCTRL_INT_VOTE_CLR_J_R_int_freq_vote_n_clr_START (4)
#define SOC_PMCTRL_INT_VOTE_CLR_J_R_int_freq_vote_n_clr_END (4)
#define SOC_PMCTRL_INT_VOTE_CLR_J_R_int_freq_vote_o_clr_START (5)
#define SOC_PMCTRL_INT_VOTE_CLR_J_R_int_freq_vote_o_clr_END (5)
#define SOC_PMCTRL_INT_VOTE_CLR_J_R_int_freq_vote_p_clr_START (6)
#define SOC_PMCTRL_INT_VOTE_CLR_J_R_int_freq_vote_p_clr_END (6)
#define SOC_PMCTRL_INT_VOTE_CLR_J_R_int_freq_vote_q_clr_START (7)
#define SOC_PMCTRL_INT_VOTE_CLR_J_R_int_freq_vote_q_clr_END (7)
#define SOC_PMCTRL_INT_VOTE_CLR_J_R_int_freq_vote_r_clr_START (8)
#define SOC_PMCTRL_INT_VOTE_CLR_J_R_int_freq_vote_r_clr_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_freq_vote_raw_stat_j : 1;
        unsigned int int_freq_vote_raw_stat_k : 1;
        unsigned int int_freq_vote_raw_stat_l : 1;
        unsigned int int_freq_vote_raw_stat_m : 1;
        unsigned int int_freq_vote_raw_stat_n : 1;
        unsigned int int_freq_vote_raw_stat_o : 1;
        unsigned int int_freq_vote_raw_stat_p : 1;
        unsigned int int_freq_vote_raw_stat_q : 1;
        unsigned int int_freq_vote_raw_stat_r : 1;
        unsigned int reserved_0 : 7;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_PMCTRL_INT_VOTE_RAW_STAT_J_R_UNION;
#endif
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_J_R_int_freq_vote_raw_stat_j_START (0)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_J_R_int_freq_vote_raw_stat_j_END (0)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_J_R_int_freq_vote_raw_stat_k_START (1)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_J_R_int_freq_vote_raw_stat_k_END (1)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_J_R_int_freq_vote_raw_stat_l_START (2)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_J_R_int_freq_vote_raw_stat_l_END (2)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_J_R_int_freq_vote_raw_stat_m_START (3)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_J_R_int_freq_vote_raw_stat_m_END (3)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_J_R_int_freq_vote_raw_stat_n_START (4)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_J_R_int_freq_vote_raw_stat_n_END (4)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_J_R_int_freq_vote_raw_stat_o_START (5)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_J_R_int_freq_vote_raw_stat_o_END (5)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_J_R_int_freq_vote_raw_stat_p_START (6)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_J_R_int_freq_vote_raw_stat_p_END (6)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_J_R_int_freq_vote_raw_stat_q_START (7)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_J_R_int_freq_vote_raw_stat_q_END (7)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_J_R_int_freq_vote_raw_stat_r_START (8)
#define SOC_PMCTRL_INT_VOTE_RAW_STAT_J_R_int_freq_vote_raw_stat_r_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_freq_vote_stat_j : 1;
        unsigned int int_freq_vote_stat_k : 1;
        unsigned int int_freq_vote_stat_l : 1;
        unsigned int int_freq_vote_stat_m : 1;
        unsigned int int_freq_vote_stat_n : 1;
        unsigned int int_freq_vote_stat_o : 1;
        unsigned int int_freq_vote_stat_p : 1;
        unsigned int int_freq_vote_stat_q : 1;
        unsigned int int_freq_vote_stat_r : 1;
        unsigned int reserved_0 : 7;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_PMCTRL_INT_VOTE_STAT_J_R_UNION;
#endif
#define SOC_PMCTRL_INT_VOTE_STAT_J_R_int_freq_vote_stat_j_START (0)
#define SOC_PMCTRL_INT_VOTE_STAT_J_R_int_freq_vote_stat_j_END (0)
#define SOC_PMCTRL_INT_VOTE_STAT_J_R_int_freq_vote_stat_k_START (1)
#define SOC_PMCTRL_INT_VOTE_STAT_J_R_int_freq_vote_stat_k_END (1)
#define SOC_PMCTRL_INT_VOTE_STAT_J_R_int_freq_vote_stat_l_START (2)
#define SOC_PMCTRL_INT_VOTE_STAT_J_R_int_freq_vote_stat_l_END (2)
#define SOC_PMCTRL_INT_VOTE_STAT_J_R_int_freq_vote_stat_m_START (3)
#define SOC_PMCTRL_INT_VOTE_STAT_J_R_int_freq_vote_stat_m_END (3)
#define SOC_PMCTRL_INT_VOTE_STAT_J_R_int_freq_vote_stat_n_START (4)
#define SOC_PMCTRL_INT_VOTE_STAT_J_R_int_freq_vote_stat_n_END (4)
#define SOC_PMCTRL_INT_VOTE_STAT_J_R_int_freq_vote_stat_o_START (5)
#define SOC_PMCTRL_INT_VOTE_STAT_J_R_int_freq_vote_stat_o_END (5)
#define SOC_PMCTRL_INT_VOTE_STAT_J_R_int_freq_vote_stat_p_START (6)
#define SOC_PMCTRL_INT_VOTE_STAT_J_R_int_freq_vote_stat_p_END (6)
#define SOC_PMCTRL_INT_VOTE_STAT_J_R_int_freq_vote_stat_q_START (7)
#define SOC_PMCTRL_INT_VOTE_STAT_J_R_int_freq_vote_stat_q_END (7)
#define SOC_PMCTRL_INT_VOTE_STAT_J_R_int_freq_vote_stat_r_START (8)
#define SOC_PMCTRL_INT_VOTE_STAT_J_R_int_freq_vote_stat_r_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_frequency_vote_j_r : 1;
        unsigned int intr_freq_vote_to_cpu_lp_ctrl_j_r : 1;
        unsigned int intr_freq_vote_to_gpu_lp_ctrl_j_r : 1;
        unsigned int intr_freq_vote_to_ddr_lp_ctrl_j_r : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_PMCTRL_INT_FREQUENCY_VOTE_J_R_UNION;
#endif
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_J_R_int_frequency_vote_j_r_START (0)
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_J_R_int_frequency_vote_j_r_END (0)
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_J_R_intr_freq_vote_to_cpu_lp_ctrl_j_r_START (1)
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_J_R_intr_freq_vote_to_cpu_lp_ctrl_j_r_END (1)
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_J_R_intr_freq_vote_to_gpu_lp_ctrl_j_r_START (2)
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_J_R_intr_freq_vote_to_gpu_lp_ctrl_j_r_END (2)
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_J_R_intr_freq_vote_to_ddr_lp_ctrl_j_r_START (3)
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_J_R_intr_freq_vote_to_ddr_lp_ctrl_j_r_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_result_j : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_VOTE_RESULT_J_UNION;
#endif
#define SOC_PMCTRL_VOTE_RESULT_J_freq_vote_result_j_START (0)
#define SOC_PMCTRL_VOTE_RESULT_J_freq_vote_result_j_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_result_k : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_VOTE_RESULT_K_UNION;
#endif
#define SOC_PMCTRL_VOTE_RESULT_K_freq_vote_result_k_START (0)
#define SOC_PMCTRL_VOTE_RESULT_K_freq_vote_result_k_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_result_l : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_VOTE_RESULT_L_UNION;
#endif
#define SOC_PMCTRL_VOTE_RESULT_L_freq_vote_result_l_START (0)
#define SOC_PMCTRL_VOTE_RESULT_L_freq_vote_result_l_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_result_m : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_VOTE_RESULT_M_UNION;
#endif
#define SOC_PMCTRL_VOTE_RESULT_M_freq_vote_result_m_START (0)
#define SOC_PMCTRL_VOTE_RESULT_M_freq_vote_result_m_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_result_n : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_VOTE_RESULT_N_UNION;
#endif
#define SOC_PMCTRL_VOTE_RESULT_N_freq_vote_result_n_START (0)
#define SOC_PMCTRL_VOTE_RESULT_N_freq_vote_result_n_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_result_o : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_VOTE_RESULT_O_UNION;
#endif
#define SOC_PMCTRL_VOTE_RESULT_O_freq_vote_result_o_START (0)
#define SOC_PMCTRL_VOTE_RESULT_O_freq_vote_result_o_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_result_p : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_VOTE_RESULT_P_UNION;
#endif
#define SOC_PMCTRL_VOTE_RESULT_P_freq_vote_result_p_START (0)
#define SOC_PMCTRL_VOTE_RESULT_P_freq_vote_result_p_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_result_q : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_VOTE_RESULT_Q_UNION;
#endif
#define SOC_PMCTRL_VOTE_RESULT_Q_freq_vote_result_q_START (0)
#define SOC_PMCTRL_VOTE_RESULT_Q_freq_vote_result_q_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int freq_vote_result_r : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_VOTE_RESULT_R_UNION;
#endif
#define SOC_PMCTRL_VOTE_RESULT_R_freq_vote_result_r_START (0)
#define SOC_PMCTRL_VOTE_RESULT_R_freq_vote_result_r_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_frequency_vote : 1;
        unsigned int intr_freq_vote_to_cpu_lp_ctrl : 1;
        unsigned int intr_freq_vote_to_gpu_lp_ctrl : 1;
        unsigned int intr_freq_vote_to_ddr_lp_ctrl : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_PMCTRL_INT_FREQUENCY_VOTE_UNION;
#endif
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_int_frequency_vote_START (0)
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_int_frequency_vote_END (0)
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_intr_freq_vote_to_cpu_lp_ctrl_START (1)
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_intr_freq_vote_to_cpu_lp_ctrl_END (1)
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_intr_freq_vote_to_gpu_lp_ctrl_START (2)
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_intr_freq_vote_to_gpu_lp_ctrl_END (2)
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_intr_freq_vote_to_ddr_lp_ctrl_START (3)
#define SOC_PMCTRL_INT_FREQUENCY_VOTE_intr_freq_vote_to_ddr_lp_ctrl_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dss2qice_freq_vote_bypass : 1;
        unsigned int dss2ddr_freq_vote_bypass : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_PMCTRL_DSS_FREQ_VOTE_BYPASS_UNION;
#endif
#define SOC_PMCTRL_DSS_FREQ_VOTE_BYPASS_dss2qice_freq_vote_bypass_START (0)
#define SOC_PMCTRL_DSS_FREQ_VOTE_BYPASS_dss2qice_freq_vote_bypass_END (0)
#define SOC_PMCTRL_DSS_FREQ_VOTE_BYPASS_dss2ddr_freq_vote_bypass_START (1)
#define SOC_PMCTRL_DSS_FREQ_VOTE_BYPASS_dss2ddr_freq_vote_bypass_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_ctrl_core_crg : 1;
        unsigned int dbg_ctrl_cssys : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int dbg_ctrl_pmc : 1;
        unsigned int dbg_ctrl_crg : 1;
        unsigned int reserved_4 : 24;
    } reg;
} SOC_PMCTRL_PERI_CTRL0_UNION;
#endif
#define SOC_PMCTRL_PERI_CTRL0_dbg_ctrl_core_crg_START (0)
#define SOC_PMCTRL_PERI_CTRL0_dbg_ctrl_core_crg_END (0)
#define SOC_PMCTRL_PERI_CTRL0_dbg_ctrl_cssys_START (1)
#define SOC_PMCTRL_PERI_CTRL0_dbg_ctrl_cssys_END (1)
#define SOC_PMCTRL_PERI_CTRL0_dbg_ctrl_pmc_START (6)
#define SOC_PMCTRL_PERI_CTRL0_dbg_ctrl_pmc_END (6)
#define SOC_PMCTRL_PERI_CTRL0_dbg_ctrl_crg_START (7)
#define SOC_PMCTRL_PERI_CTRL0_dbg_ctrl_crg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 16;
        unsigned int reserved_1: 16;
    } reg;
} SOC_PMCTRL_PERI_CTRL4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_PERI_CTRL5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ispdss2ddr_dfs_ongoing : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PMCTRL_PERI_CTRL7_UNION;
#endif
#define SOC_PMCTRL_PERI_CTRL7_ispdss2ddr_dfs_ongoing_START (0)
#define SOC_PMCTRL_PERI_CTRL7_ispdss2ddr_dfs_ongoing_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_info_cssys : 32;
    } reg;
} SOC_PMCTRL_PERI_STAT1_UNION;
#endif
#define SOC_PMCTRL_PERI_STAT1_dbg_info_cssys_START (0)
#define SOC_PMCTRL_PERI_STAT1_dbg_info_cssys_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pdc_cfg_syspdc_pwrd_req : 1;
        unsigned int pdc_ddrxpu_syspdc_pwrd_req : 1;
        unsigned int reserved_0 : 1;
        unsigned int pdc_cfgdma_syspdc_pwrd_req : 1;
        unsigned int pdc_mdmperi_syspdc_pwrd_req : 1;
        unsigned int pdc_fcm_syspdc_pwrd_req : 1;
        unsigned int pdc_hsdt0_syspdc_pwrd_req : 1;
        unsigned int pdc_hsdt1_syspdc_pwrd_req : 1;
        unsigned int pdc_gpu_syspdc_pwrd_req : 1;
        unsigned int pdc_media1_syspdc_pwrd_req : 1;
        unsigned int pdc_media2_syspdc_pwrd_req : 1;
        unsigned int pdc_npu_syspdc_pwrd_req : 1;
        unsigned int pdc_sdcu_syspdc_pwrd_req : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int biten : 16;
    } reg;
} SOC_PMCTRL_QIC_POWER_IDLEREQ_0_UNION;
#endif
#define SOC_PMCTRL_QIC_POWER_IDLEREQ_0_pdc_cfg_syspdc_pwrd_req_START (0)
#define SOC_PMCTRL_QIC_POWER_IDLEREQ_0_pdc_cfg_syspdc_pwrd_req_END (0)
#define SOC_PMCTRL_QIC_POWER_IDLEREQ_0_pdc_ddrxpu_syspdc_pwrd_req_START (1)
#define SOC_PMCTRL_QIC_POWER_IDLEREQ_0_pdc_ddrxpu_syspdc_pwrd_req_END (1)
#define SOC_PMCTRL_QIC_POWER_IDLEREQ_0_pdc_cfgdma_syspdc_pwrd_req_START (3)
#define SOC_PMCTRL_QIC_POWER_IDLEREQ_0_pdc_cfgdma_syspdc_pwrd_req_END (3)
#define SOC_PMCTRL_QIC_POWER_IDLEREQ_0_pdc_mdmperi_syspdc_pwrd_req_START (4)
#define SOC_PMCTRL_QIC_POWER_IDLEREQ_0_pdc_mdmperi_syspdc_pwrd_req_END (4)
#define SOC_PMCTRL_QIC_POWER_IDLEREQ_0_pdc_fcm_syspdc_pwrd_req_START (5)
#define SOC_PMCTRL_QIC_POWER_IDLEREQ_0_pdc_fcm_syspdc_pwrd_req_END (5)
#define SOC_PMCTRL_QIC_POWER_IDLEREQ_0_pdc_hsdt0_syspdc_pwrd_req_START (6)
#define SOC_PMCTRL_QIC_POWER_IDLEREQ_0_pdc_hsdt0_syspdc_pwrd_req_END (6)
#define SOC_PMCTRL_QIC_POWER_IDLEREQ_0_pdc_hsdt1_syspdc_pwrd_req_START (7)
#define SOC_PMCTRL_QIC_POWER_IDLEREQ_0_pdc_hsdt1_syspdc_pwrd_req_END (7)
#define SOC_PMCTRL_QIC_POWER_IDLEREQ_0_pdc_gpu_syspdc_pwrd_req_START (8)
#define SOC_PMCTRL_QIC_POWER_IDLEREQ_0_pdc_gpu_syspdc_pwrd_req_END (8)
#define SOC_PMCTRL_QIC_POWER_IDLEREQ_0_pdc_media1_syspdc_pwrd_req_START (9)
#define SOC_PMCTRL_QIC_POWER_IDLEREQ_0_pdc_media1_syspdc_pwrd_req_END (9)
#define SOC_PMCTRL_QIC_POWER_IDLEREQ_0_pdc_media2_syspdc_pwrd_req_START (10)
#define SOC_PMCTRL_QIC_POWER_IDLEREQ_0_pdc_media2_syspdc_pwrd_req_END (10)
#define SOC_PMCTRL_QIC_POWER_IDLEREQ_0_pdc_npu_syspdc_pwrd_req_START (11)
#define SOC_PMCTRL_QIC_POWER_IDLEREQ_0_pdc_npu_syspdc_pwrd_req_END (11)
#define SOC_PMCTRL_QIC_POWER_IDLEREQ_0_pdc_sdcu_syspdc_pwrd_req_START (12)
#define SOC_PMCTRL_QIC_POWER_IDLEREQ_0_pdc_sdcu_syspdc_pwrd_req_END (12)
#define SOC_PMCTRL_QIC_POWER_IDLEREQ_0_biten_START (16)
#define SOC_PMCTRL_QIC_POWER_IDLEREQ_0_biten_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pdc_cfg_syspdc_pwrd_ack_dbg : 1;
        unsigned int pdc_ddrxpu_syspdc_pwrd_ack_dbg : 1;
        unsigned int pdc_crossbar_syspdc_pwrd_ack_dbg : 1;
        unsigned int pdc_cfgdma_syspdc_pwrd_ack_dbg : 1;
        unsigned int pdc_mdmperi_syspdc_pwrd_ack_dbg : 1;
        unsigned int pdc_fcm_syspdc_pwrd_ack_dbg : 1;
        unsigned int pdc_hsdt0_syspdc_pwrd_ack_dbg : 1;
        unsigned int pdc_hsdt1_syspdc_pwrd_ack_dbg : 1;
        unsigned int pdc_gpu_syspdc_pwrd_ack_dbg : 1;
        unsigned int pdc_media1_syspdc_pwrd_ack_dbg : 1;
        unsigned int pdc_media2_syspdc_pwrd_ack_dbg : 1;
        unsigned int pdc_npu_syspdc_pwrd_ack_dbg : 1;
        unsigned int pdc_sdcu_syspdc_pwrd_ack_dbg : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 16;
    } reg;
} SOC_PMCTRL_QIC_POWER_IDLEACK_DBG_0_UNION;
#endif
#define SOC_PMCTRL_QIC_POWER_IDLEACK_DBG_0_pdc_cfg_syspdc_pwrd_ack_dbg_START (0)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_DBG_0_pdc_cfg_syspdc_pwrd_ack_dbg_END (0)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_DBG_0_pdc_ddrxpu_syspdc_pwrd_ack_dbg_START (1)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_DBG_0_pdc_ddrxpu_syspdc_pwrd_ack_dbg_END (1)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_DBG_0_pdc_crossbar_syspdc_pwrd_ack_dbg_START (2)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_DBG_0_pdc_crossbar_syspdc_pwrd_ack_dbg_END (2)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_DBG_0_pdc_cfgdma_syspdc_pwrd_ack_dbg_START (3)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_DBG_0_pdc_cfgdma_syspdc_pwrd_ack_dbg_END (3)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_DBG_0_pdc_mdmperi_syspdc_pwrd_ack_dbg_START (4)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_DBG_0_pdc_mdmperi_syspdc_pwrd_ack_dbg_END (4)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_DBG_0_pdc_fcm_syspdc_pwrd_ack_dbg_START (5)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_DBG_0_pdc_fcm_syspdc_pwrd_ack_dbg_END (5)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_DBG_0_pdc_hsdt0_syspdc_pwrd_ack_dbg_START (6)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_DBG_0_pdc_hsdt0_syspdc_pwrd_ack_dbg_END (6)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_DBG_0_pdc_hsdt1_syspdc_pwrd_ack_dbg_START (7)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_DBG_0_pdc_hsdt1_syspdc_pwrd_ack_dbg_END (7)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_DBG_0_pdc_gpu_syspdc_pwrd_ack_dbg_START (8)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_DBG_0_pdc_gpu_syspdc_pwrd_ack_dbg_END (8)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_DBG_0_pdc_media1_syspdc_pwrd_ack_dbg_START (9)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_DBG_0_pdc_media1_syspdc_pwrd_ack_dbg_END (9)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_DBG_0_pdc_media2_syspdc_pwrd_ack_dbg_START (10)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_DBG_0_pdc_media2_syspdc_pwrd_ack_dbg_END (10)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_DBG_0_pdc_npu_syspdc_pwrd_ack_dbg_START (11)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_DBG_0_pdc_npu_syspdc_pwrd_ack_dbg_END (11)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_DBG_0_pdc_sdcu_syspdc_pwrd_ack_dbg_START (12)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_DBG_0_pdc_sdcu_syspdc_pwrd_ack_dbg_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pdc_cfg_syspdc_pwrd_ack : 1;
        unsigned int pdc_ddrxpu_syspdc_pwrd_ack : 1;
        unsigned int pdc_crossbar_syspdc_pwrd_ack : 1;
        unsigned int pdc_cfgdma_syspdc_pwrd_ack : 1;
        unsigned int pdc_mdmperi_syspdc_pwrd_ack : 1;
        unsigned int pdc_fcm_syspdc_pwrd_ack : 1;
        unsigned int pdc_hsdt0_syspdc_pwrd_ack : 1;
        unsigned int pdc_hsdt1_syspdc_pwrd_ack : 1;
        unsigned int pdc_gpu_syspdc_pwrd_ack : 1;
        unsigned int pdc_media1_syspdc_pwrd_ack : 1;
        unsigned int pdc_media2_syspdc_pwrd_ack : 1;
        unsigned int pdc_npu_syspdc_pwrd_ack : 1;
        unsigned int pdc_sdcu_syspdc_pwrd_ack : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 16;
    } reg;
} SOC_PMCTRL_QIC_POWER_IDLEACK_0_UNION;
#endif
#define SOC_PMCTRL_QIC_POWER_IDLEACK_0_pdc_cfg_syspdc_pwrd_ack_START (0)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_0_pdc_cfg_syspdc_pwrd_ack_END (0)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_0_pdc_ddrxpu_syspdc_pwrd_ack_START (1)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_0_pdc_ddrxpu_syspdc_pwrd_ack_END (1)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_0_pdc_crossbar_syspdc_pwrd_ack_START (2)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_0_pdc_crossbar_syspdc_pwrd_ack_END (2)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_0_pdc_cfgdma_syspdc_pwrd_ack_START (3)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_0_pdc_cfgdma_syspdc_pwrd_ack_END (3)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_0_pdc_mdmperi_syspdc_pwrd_ack_START (4)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_0_pdc_mdmperi_syspdc_pwrd_ack_END (4)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_0_pdc_fcm_syspdc_pwrd_ack_START (5)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_0_pdc_fcm_syspdc_pwrd_ack_END (5)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_0_pdc_hsdt0_syspdc_pwrd_ack_START (6)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_0_pdc_hsdt0_syspdc_pwrd_ack_END (6)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_0_pdc_hsdt1_syspdc_pwrd_ack_START (7)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_0_pdc_hsdt1_syspdc_pwrd_ack_END (7)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_0_pdc_gpu_syspdc_pwrd_ack_START (8)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_0_pdc_gpu_syspdc_pwrd_ack_END (8)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_0_pdc_media1_syspdc_pwrd_ack_START (9)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_0_pdc_media1_syspdc_pwrd_ack_END (9)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_0_pdc_media2_syspdc_pwrd_ack_START (10)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_0_pdc_media2_syspdc_pwrd_ack_END (10)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_0_pdc_npu_syspdc_pwrd_ack_START (11)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_0_pdc_npu_syspdc_pwrd_ack_END (11)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_0_pdc_sdcu_syspdc_pwrd_ack_START (12)
#define SOC_PMCTRL_QIC_POWER_IDLEACK_0_pdc_sdcu_syspdc_pwrd_ack_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bootrom_flag : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PMCTRL_BOOTROMFLAG_UNION;
#endif
#define SOC_PMCTRL_BOOTROMFLAG_bootrom_flag_START (0)
#define SOC_PMCTRL_BOOTROMFLAG_bootrom_flag_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_hpm_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int peri_hpmx_en : 1;
        unsigned int reserved_1 : 3;
        unsigned int peri_hpm_opc_min_en : 1;
        unsigned int reserved_2 : 3;
        unsigned int peri_hpmx_opc_min_en : 1;
        unsigned int reserved_3 : 19;
    } reg;
} SOC_PMCTRL_PERIHPMEN_UNION;
#endif
#define SOC_PMCTRL_PERIHPMEN_peri_hpm_en_START (0)
#define SOC_PMCTRL_PERIHPMEN_peri_hpm_en_END (0)
#define SOC_PMCTRL_PERIHPMEN_peri_hpmx_en_START (4)
#define SOC_PMCTRL_PERIHPMEN_peri_hpmx_en_END (4)
#define SOC_PMCTRL_PERIHPMEN_peri_hpm_opc_min_en_START (8)
#define SOC_PMCTRL_PERIHPMEN_peri_hpm_opc_min_en_END (8)
#define SOC_PMCTRL_PERIHPMEN_peri_hpmx_opc_min_en_START (12)
#define SOC_PMCTRL_PERIHPMEN_peri_hpmx_opc_min_en_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_hpm_clk_div : 7;
        unsigned int reserved_0 : 1;
        unsigned int peri_hpm_opc_min : 10;
        unsigned int reserved_1 : 2;
        unsigned int peri_hpmx_opc_min : 10;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_PMCTRL_PERIHPMCLKDIV_UNION;
#endif
#define SOC_PMCTRL_PERIHPMCLKDIV_peri_hpm_clk_div_START (0)
#define SOC_PMCTRL_PERIHPMCLKDIV_peri_hpm_clk_div_END (6)
#define SOC_PMCTRL_PERIHPMCLKDIV_peri_hpm_opc_min_START (8)
#define SOC_PMCTRL_PERIHPMCLKDIV_peri_hpm_opc_min_END (17)
#define SOC_PMCTRL_PERIHPMCLKDIV_peri_hpmx_opc_min_START (20)
#define SOC_PMCTRL_PERIHPMCLKDIV_peri_hpmx_opc_min_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_hpm_opc : 10;
        unsigned int reserved_0 : 2;
        unsigned int peri_hpm_opc_vld : 1;
        unsigned int reserved_1 : 3;
        unsigned int peri_hpmx_opc : 10;
        unsigned int reserved_2 : 2;
        unsigned int peri_hpmx_opc_vld : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_PMCTRL_PERIHPMOPC_UNION;
#endif
#define SOC_PMCTRL_PERIHPMOPC_peri_hpm_opc_START (0)
#define SOC_PMCTRL_PERIHPMOPC_peri_hpm_opc_END (9)
#define SOC_PMCTRL_PERIHPMOPC_peri_hpm_opc_vld_START (12)
#define SOC_PMCTRL_PERIHPMOPC_peri_hpm_opc_vld_END (12)
#define SOC_PMCTRL_PERIHPMOPC_peri_hpmx_opc_START (16)
#define SOC_PMCTRL_PERIHPMOPC_peri_hpmx_opc_END (25)
#define SOC_PMCTRL_PERIHPMOPC_peri_hpmx_opc_vld_START (28)
#define SOC_PMCTRL_PERIHPMOPC_peri_hpmx_opc_vld_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int djtag_ctrl : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_PMCTRL_DJTAG_CTRL_UNION;
#endif
#define SOC_PMCTRL_DJTAG_CTRL_djtag_ctrl_START (0)
#define SOC_PMCTRL_DJTAG_CTRL_djtag_ctrl_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_info_pmc : 32;
    } reg;
} SOC_PMCTRL_PERI_STAT12_UNION;
#endif
#define SOC_PMCTRL_PERI_STAT12_dbg_info_pmc_START (0)
#define SOC_PMCTRL_PERI_STAT12_dbg_info_pmc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_info_crg : 32;
    } reg;
} SOC_PMCTRL_PERI_STAT13_UNION;
#endif
#define SOC_PMCTRL_PERI_STAT13_dbg_info_crg_START (0)
#define SOC_PMCTRL_PERI_STAT13_dbg_info_crg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_rank_0 : 3;
        unsigned int peri_vote_vol_rank_1 : 3;
        unsigned int peri_vote_vol_rank_2 : 3;
        unsigned int peri_vote_vol_rank_3 : 3;
        unsigned int peri_vote_vol_rank_4 : 3;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_0_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_0_peri_vote_vol_rank_0_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_0_peri_vote_vol_rank_0_END (2)
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_0_peri_vote_vol_rank_1_START (3)
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_0_peri_vote_vol_rank_1_END (5)
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_0_peri_vote_vol_rank_2_START (6)
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_0_peri_vote_vol_rank_2_END (8)
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_0_peri_vote_vol_rank_3_START (9)
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_0_peri_vote_vol_rank_3_END (11)
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_0_peri_vote_vol_rank_4_START (12)
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_0_peri_vote_vol_rank_4_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_rank_5 : 3;
        unsigned int peri_vote_vol_rank_6 : 3;
        unsigned int peri_vote_vol_rank_7 : 3;
        unsigned int peri_vote_vol_rank_8 : 3;
        unsigned int peri_vote_vol_rank_9 : 3;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_1_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_1_peri_vote_vol_rank_5_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_1_peri_vote_vol_rank_5_END (2)
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_1_peri_vote_vol_rank_6_START (3)
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_1_peri_vote_vol_rank_6_END (5)
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_1_peri_vote_vol_rank_7_START (6)
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_1_peri_vote_vol_rank_7_END (8)
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_1_peri_vote_vol_rank_8_START (9)
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_1_peri_vote_vol_rank_8_END (11)
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_1_peri_vote_vol_rank_9_START (12)
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_1_peri_vote_vol_rank_9_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_rank_10 : 3;
        unsigned int peri_vote_vol_rank_11 : 3;
        unsigned int peri_vote_vol_rank_12 : 3;
        unsigned int peri_vote_vol_rank_13 : 3;
        unsigned int peri_vote_vol_rank_14 : 3;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_2_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_2_peri_vote_vol_rank_10_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_2_peri_vote_vol_rank_10_END (2)
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_2_peri_vote_vol_rank_11_START (3)
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_2_peri_vote_vol_rank_11_END (5)
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_2_peri_vote_vol_rank_12_START (6)
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_2_peri_vote_vol_rank_12_END (8)
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_2_peri_vote_vol_rank_13_START (9)
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_2_peri_vote_vol_rank_13_END (11)
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_2_peri_vote_vol_rank_14_START (12)
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_2_peri_vote_vol_rank_14_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_rank_15 : 3;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 3;
        unsigned int reserved_2 : 3;
        unsigned int reserved_3 : 3;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 16;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_3_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_3_peri_vote_vol_rank_15_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_RANK_SFT_3_peri_vote_vol_rank_15_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_valid_0 : 1;
        unsigned int peri_vote_vol_valid_1 : 1;
        unsigned int peri_vote_vol_valid_2 : 1;
        unsigned int peri_vote_vol_valid_3 : 1;
        unsigned int peri_vote_vol_valid_4 : 1;
        unsigned int peri_vote_vol_valid_5 : 1;
        unsigned int peri_vote_vol_valid_6 : 1;
        unsigned int peri_vote_vol_valid_7 : 1;
        unsigned int peri_vote_vol_valid_8 : 1;
        unsigned int peri_vote_vol_valid_9 : 1;
        unsigned int peri_vote_vol_valid_10 : 1;
        unsigned int peri_vote_vol_valid_11 : 1;
        unsigned int peri_vote_vol_valid_12 : 1;
        unsigned int peri_vote_vol_valid_13 : 1;
        unsigned int peri_vote_vol_valid_14 : 1;
        unsigned int peri_vote_vol_valid_15 : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_VALID_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_0_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_0_END (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_1_START (1)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_1_END (1)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_2_START (2)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_2_END (2)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_3_START (3)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_3_END (3)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_4_START (4)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_4_END (4)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_5_START (5)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_5_END (5)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_6_START (6)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_6_END (6)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_7_START (7)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_7_END (7)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_8_START (8)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_8_END (8)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_9_START (9)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_9_END (9)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_10_START (10)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_10_END (10)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_11_START (11)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_11_END (11)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_12_START (12)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_12_END (12)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_13_START (13)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_13_END (13)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_14_START (14)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_14_END (14)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_15_START (15)
#define SOC_PMCTRL_PERI_VOTE_VOL_VALID_peri_vote_vol_valid_15_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_sft_chg_0 : 1;
        unsigned int peri_vote_sft_chg_1 : 1;
        unsigned int peri_vote_sft_chg_2 : 1;
        unsigned int peri_vote_sft_chg_3 : 1;
        unsigned int peri_vote_sft_chg_4 : 1;
        unsigned int peri_vote_sft_chg_5 : 1;
        unsigned int peri_vote_sft_chg_6 : 1;
        unsigned int peri_vote_sft_chg_7 : 1;
        unsigned int peri_vote_sft_chg_8 : 1;
        unsigned int peri_vote_sft_chg_9 : 1;
        unsigned int peri_vote_sft_chg_10 : 1;
        unsigned int peri_vote_sft_chg_11 : 1;
        unsigned int peri_vote_sft_chg_12 : 1;
        unsigned int peri_vote_sft_chg_13 : 1;
        unsigned int peri_vote_sft_chg_14 : 1;
        unsigned int peri_vote_sft_chg_15 : 1;
        unsigned int peri_vote_sft_chg_0_vau_4to1 : 1;
        unsigned int peri_vote_sft_chg_1_vau_4to1 : 1;
        unsigned int peri_vote_sft_chg_2_vau_4to1 : 1;
        unsigned int peri_vote_sft_chg_3_vau_4to1 : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_PERI_VOTE_SFT_CHG_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_0_START (0)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_0_END (0)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_1_START (1)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_1_END (1)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_2_START (2)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_2_END (2)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_3_START (3)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_3_END (3)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_4_START (4)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_4_END (4)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_5_START (5)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_5_END (5)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_6_START (6)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_6_END (6)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_7_START (7)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_7_END (7)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_8_START (8)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_8_END (8)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_9_START (9)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_9_END (9)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_10_START (10)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_10_END (10)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_11_START (11)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_11_END (11)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_12_START (12)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_12_END (12)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_13_START (13)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_13_END (13)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_14_START (14)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_14_END (14)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_15_START (15)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_15_END (15)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_0_vau_4to1_START (16)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_0_vau_4to1_END (16)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_1_vau_4to1_START (17)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_1_vau_4to1_END (17)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_2_vau_4to1_START (18)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_2_vau_4to1_END (18)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_3_vau_4to1_START (19)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_peri_vote_sft_chg_3_vau_4to1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_soft_vol_vote_en_0 : 1;
        unsigned int peri_soft_vol_vote_en_1 : 1;
        unsigned int peri_soft_vol_vote_en_2 : 1;
        unsigned int peri_soft_vol_vote_en_3 : 1;
        unsigned int peri_soft_vol_vote_en_4 : 1;
        unsigned int peri_soft_vol_vote_en_5 : 1;
        unsigned int peri_soft_vol_vote_en_6 : 1;
        unsigned int peri_soft_vol_vote_en_7 : 1;
        unsigned int peri_soft_vol_vote_en_8 : 1;
        unsigned int peri_soft_vol_vote_en_9 : 1;
        unsigned int peri_soft_vol_vote_en_10 : 1;
        unsigned int peri_soft_vol_vote_en_11 : 1;
        unsigned int peri_soft_vol_vote_en_12 : 1;
        unsigned int peri_soft_vol_vote_en_13 : 1;
        unsigned int peri_soft_vol_vote_en_14 : 1;
        unsigned int peri_soft_vol_vote_en_15 : 1;
        unsigned int peri_soft_vol_vote_en_0_vau_4to1 : 1;
        unsigned int peri_soft_vol_vote_en_1_vau_4to1 : 1;
        unsigned int peri_soft_vol_vote_en_2_vau_4to1 : 1;
        unsigned int peri_soft_vol_vote_en_3_vau_4to1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 8;
    } reg;
} SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_0_START (0)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_0_END (0)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_1_START (1)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_1_END (1)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_2_START (2)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_2_END (2)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_3_START (3)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_3_END (3)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_4_START (4)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_4_END (4)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_5_START (5)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_5_END (5)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_6_START (6)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_6_END (6)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_7_START (7)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_7_END (7)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_8_START (8)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_8_END (8)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_9_START (9)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_9_END (9)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_10_START (10)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_10_END (10)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_11_START (11)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_11_END (11)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_12_START (12)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_12_END (12)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_13_START (13)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_13_END (13)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_14_START (14)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_14_END (14)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_15_START (15)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_15_END (15)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_0_vau_4to1_START (16)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_0_vau_4to1_END (16)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_1_vau_4to1_START (17)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_1_vau_4to1_END (17)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_2_vau_4to1_START (18)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_2_vau_4to1_END (18)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_3_vau_4to1_START (19)
#define SOC_PMCTRL_PERI_VOTE_SFT_CHG_BYPASS_peri_soft_vol_vote_en_3_vau_4to1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vol_sft_clr_0 : 1;
        unsigned int peri_vol_sft_clr_1 : 1;
        unsigned int peri_vol_sft_clr_2 : 1;
        unsigned int peri_vol_sft_clr_3 : 1;
        unsigned int peri_vol_sft_clr_4 : 1;
        unsigned int peri_vol_sft_clr_5 : 1;
        unsigned int peri_vol_sft_clr_6 : 1;
        unsigned int peri_vol_sft_clr_7 : 1;
        unsigned int peri_vol_sft_clr_8 : 1;
        unsigned int peri_vol_sft_clr_9 : 1;
        unsigned int peri_vol_sft_clr_10 : 1;
        unsigned int peri_vol_sft_clr_11 : 1;
        unsigned int peri_vol_sft_clr_12 : 1;
        unsigned int peri_vol_sft_clr_13 : 1;
        unsigned int peri_vol_sft_clr_14 : 1;
        unsigned int peri_vol_sft_clr_15 : 1;
        unsigned int peri_vol_sft_clr_0_vau_4to1 : 1;
        unsigned int peri_vol_sft_clr_1_vau_4to1 : 1;
        unsigned int peri_vol_sft_clr_2_vau_4to1 : 1;
        unsigned int peri_vol_sft_clr_3_vau_4to1 : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_PERI_VOL_SFT_CLR_UNION;
#endif
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_0_START (0)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_0_END (0)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_1_START (1)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_1_END (1)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_2_START (2)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_2_END (2)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_3_START (3)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_3_END (3)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_4_START (4)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_4_END (4)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_5_START (5)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_5_END (5)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_6_START (6)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_6_END (6)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_7_START (7)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_7_END (7)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_8_START (8)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_8_END (8)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_9_START (9)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_9_END (9)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_10_START (10)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_10_END (10)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_11_START (11)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_11_END (11)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_12_START (12)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_12_END (12)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_13_START (13)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_13_END (13)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_14_START (14)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_14_END (14)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_15_START (15)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_15_END (15)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_0_vau_4to1_START (16)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_0_vau_4to1_END (16)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_1_vau_4to1_START (17)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_1_vau_4to1_END (17)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_2_vau_4to1_START (18)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_2_vau_4to1_END (18)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_3_vau_4to1_START (19)
#define SOC_PMCTRL_PERI_VOL_SFT_CLR_peri_vol_sft_clr_3_vau_4to1_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vol_stable_0 : 1;
        unsigned int peri_vol_stable_1 : 1;
        unsigned int peri_vol_stable_2 : 1;
        unsigned int peri_vol_stable_3 : 1;
        unsigned int peri_vol_stable_4 : 1;
        unsigned int peri_vol_stable_5 : 1;
        unsigned int peri_vol_stable_6 : 1;
        unsigned int peri_vol_stable_7 : 1;
        unsigned int peri_vol_stable_8 : 1;
        unsigned int peri_vol_stable_9 : 1;
        unsigned int peri_vol_stable_10 : 1;
        unsigned int peri_vol_stable_11 : 1;
        unsigned int peri_vol_stable_12 : 1;
        unsigned int peri_vol_stable_13 : 1;
        unsigned int peri_vol_stable_14 : 1;
        unsigned int peri_vol_stable_15 : 1;
        unsigned int peri_vol_stable_vau_0 : 1;
        unsigned int peri_vol_stable_vau_1 : 1;
        unsigned int peri_vol_stable_vau_2 : 1;
        unsigned int peri_vol_stable_vau_3 : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_PERI_VOL_STABLE_UNION;
#endif
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_0_START (0)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_0_END (0)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_1_START (1)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_1_END (1)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_2_START (2)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_2_END (2)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_3_START (3)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_3_END (3)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_4_START (4)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_4_END (4)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_5_START (5)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_5_END (5)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_6_START (6)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_6_END (6)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_7_START (7)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_7_END (7)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_8_START (8)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_8_END (8)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_9_START (9)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_9_END (9)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_10_START (10)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_10_END (10)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_11_START (11)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_11_END (11)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_12_START (12)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_12_END (12)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_13_START (13)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_13_END (13)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_14_START (14)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_14_END (14)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_15_START (15)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_15_END (15)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_vau_0_START (16)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_vau_0_END (16)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_vau_1_START (17)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_vau_1_END (17)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_vau_2_START (18)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_vau_2_END (18)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_vau_3_START (19)
#define SOC_PMCTRL_PERI_VOL_STABLE_peri_vol_stable_vau_3_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_intr_lpm3_msk : 16;
        unsigned int peri_intr_cpu_msk : 16;
    } reg;
} SOC_PMCTRL_PERI_INTR_M3ORCPU_MSK_UNION;
#endif
#define SOC_PMCTRL_PERI_INTR_M3ORCPU_MSK_peri_intr_lpm3_msk_START (0)
#define SOC_PMCTRL_PERI_INTR_M3ORCPU_MSK_peri_intr_lpm3_msk_END (15)
#define SOC_PMCTRL_PERI_INTR_M3ORCPU_MSK_peri_intr_cpu_msk_START (16)
#define SOC_PMCTRL_PERI_INTR_M3ORCPU_MSK_peri_intr_cpu_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_pmu_vol_idx_spmi : 8;
        unsigned int peri_pmu_vol_chg_spmi : 1;
        unsigned int intr_peri_dvs_stat_pmc2lpm3 : 1;
        unsigned int intr_peri_dvs_stat_pmc2acpu : 1;
        unsigned int peri_pmu_vol_ack_spmi : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int peri_buck_on_off_stable : 1;
        unsigned int reserved_2 : 3;
        unsigned int peri_buck_ctrl_cur_stat : 3;
        unsigned int reserved_3 : 11;
    } reg;
} SOC_PMCTRL_PERI_DVS_OUTPUT_READ_UNION;
#endif
#define SOC_PMCTRL_PERI_DVS_OUTPUT_READ_peri_pmu_vol_idx_spmi_START (0)
#define SOC_PMCTRL_PERI_DVS_OUTPUT_READ_peri_pmu_vol_idx_spmi_END (7)
#define SOC_PMCTRL_PERI_DVS_OUTPUT_READ_peri_pmu_vol_chg_spmi_START (8)
#define SOC_PMCTRL_PERI_DVS_OUTPUT_READ_peri_pmu_vol_chg_spmi_END (8)
#define SOC_PMCTRL_PERI_DVS_OUTPUT_READ_intr_peri_dvs_stat_pmc2lpm3_START (9)
#define SOC_PMCTRL_PERI_DVS_OUTPUT_READ_intr_peri_dvs_stat_pmc2lpm3_END (9)
#define SOC_PMCTRL_PERI_DVS_OUTPUT_READ_intr_peri_dvs_stat_pmc2acpu_START (10)
#define SOC_PMCTRL_PERI_DVS_OUTPUT_READ_intr_peri_dvs_stat_pmc2acpu_END (10)
#define SOC_PMCTRL_PERI_DVS_OUTPUT_READ_peri_pmu_vol_ack_spmi_START (11)
#define SOC_PMCTRL_PERI_DVS_OUTPUT_READ_peri_pmu_vol_ack_spmi_END (11)
#define SOC_PMCTRL_PERI_DVS_OUTPUT_READ_peri_buck_on_off_stable_START (14)
#define SOC_PMCTRL_PERI_DVS_OUTPUT_READ_peri_buck_on_off_stable_END (14)
#define SOC_PMCTRL_PERI_DVS_OUTPUT_READ_peri_buck_ctrl_cur_stat_START (18)
#define SOC_PMCTRL_PERI_DVS_OUTPUT_READ_peri_buck_ctrl_cur_stat_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_intr_bypass_0 : 1;
        unsigned int peri_intr_bypass_1 : 1;
        unsigned int peri_intr_bypass_2 : 1;
        unsigned int peri_intr_bypass_3 : 1;
        unsigned int peri_intr_bypass_4 : 1;
        unsigned int peri_intr_bypass_5 : 1;
        unsigned int peri_intr_bypass_6 : 1;
        unsigned int peri_intr_bypass_7 : 1;
        unsigned int peri_intr_bypass_8 : 1;
        unsigned int peri_intr_bypass_9 : 1;
        unsigned int peri_intr_bypass_10 : 1;
        unsigned int peri_intr_bypass_11 : 1;
        unsigned int peri_intr_bypass_12 : 1;
        unsigned int peri_intr_bypass_13 : 1;
        unsigned int peri_intr_bypass_14 : 1;
        unsigned int peri_intr_bypass_15 : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_PMCTRL_PERI_INTR_BYPASS_SFT_UNION;
#endif
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_0_START (0)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_0_END (0)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_1_START (1)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_1_END (1)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_2_START (2)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_2_END (2)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_3_START (3)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_3_END (3)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_4_START (4)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_4_END (4)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_5_START (5)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_5_END (5)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_6_START (6)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_6_END (6)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_7_START (7)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_7_END (7)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_8_START (8)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_8_END (8)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_9_START (9)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_9_END (9)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_10_START (10)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_10_END (10)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_11_START (11)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_11_END (11)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_12_START (12)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_12_END (12)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_13_START (13)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_13_END (13)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_14_START (14)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_14_END (14)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_15_START (15)
#define SOC_PMCTRL_PERI_INTR_BYPASS_SFT_peri_intr_bypass_15_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_intr_bypass_16 : 1;
        unsigned int peri_intr_bypass_17 : 1;
        unsigned int peri_intr_bypass_18 : 1;
        unsigned int peri_intr_bypass_19 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 3;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 16;
    } reg;
} SOC_PMCTRL_PERI_INTR_BYPASS_HRD_UNION;
#endif
#define SOC_PMCTRL_PERI_INTR_BYPASS_HRD_peri_intr_bypass_16_START (0)
#define SOC_PMCTRL_PERI_INTR_BYPASS_HRD_peri_intr_bypass_16_END (0)
#define SOC_PMCTRL_PERI_INTR_BYPASS_HRD_peri_intr_bypass_17_START (1)
#define SOC_PMCTRL_PERI_INTR_BYPASS_HRD_peri_intr_bypass_17_END (1)
#define SOC_PMCTRL_PERI_INTR_BYPASS_HRD_peri_intr_bypass_18_START (2)
#define SOC_PMCTRL_PERI_INTR_BYPASS_HRD_peri_intr_bypass_18_END (2)
#define SOC_PMCTRL_PERI_INTR_BYPASS_HRD_peri_intr_bypass_19_START (3)
#define SOC_PMCTRL_PERI_INTR_BYPASS_HRD_peri_intr_bypass_19_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_dvs_spmi_hold_timeout_flag : 1;
        unsigned int peri_dvs_buck_onoff_timeout_flag : 1;
        unsigned int peri_dvs_fer_err_flag : 1;
        unsigned int peri_dvs_timeout_flag_clr : 1;
        unsigned int peri_vau_vol_equal_flag_vau_0 : 1;
        unsigned int peri_vau_vol_equal_flag_clr_vau_0 : 1;
        unsigned int peri_vau_vol_equal_flag_vau_1 : 1;
        unsigned int peri_vau_vol_equal_flag_clr_vau_1 : 1;
        unsigned int peri_vau_vol_equal_flag_vau_2 : 1;
        unsigned int peri_vau_vol_equal_flag_clr_vau_2 : 1;
        unsigned int peri_vau_vol_equal_flag_vau_3 : 1;
        unsigned int peri_vau_vol_equal_flag_clr_vau_3 : 1;
        unsigned int peri_vau_vol_equal_flag_vau_4to1 : 1;
        unsigned int peri_vau_vol_equal_flag_clr_vau_4to1 : 1;
        unsigned int peri_vau_cur_stat_vau_0 : 3;
        unsigned int peri_vau_cur_stat_vau_1 : 3;
        unsigned int peri_vau_cur_stat_vau_2 : 3;
        unsigned int peri_vau_cur_stat_vau_3 : 3;
        unsigned int peri_vau_cur_stat_vau_4to1 : 3;
        unsigned int reserved : 3;
    } reg;
} SOC_PMCTRL_PERI_DVS_STAT0_UNION;
#endif
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_dvs_spmi_hold_timeout_flag_START (0)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_dvs_spmi_hold_timeout_flag_END (0)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_dvs_buck_onoff_timeout_flag_START (1)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_dvs_buck_onoff_timeout_flag_END (1)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_dvs_fer_err_flag_START (2)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_dvs_fer_err_flag_END (2)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_dvs_timeout_flag_clr_START (3)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_dvs_timeout_flag_clr_END (3)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_vol_equal_flag_vau_0_START (4)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_vol_equal_flag_vau_0_END (4)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_vol_equal_flag_clr_vau_0_START (5)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_vol_equal_flag_clr_vau_0_END (5)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_vol_equal_flag_vau_1_START (6)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_vol_equal_flag_vau_1_END (6)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_vol_equal_flag_clr_vau_1_START (7)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_vol_equal_flag_clr_vau_1_END (7)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_vol_equal_flag_vau_2_START (8)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_vol_equal_flag_vau_2_END (8)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_vol_equal_flag_clr_vau_2_START (9)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_vol_equal_flag_clr_vau_2_END (9)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_vol_equal_flag_vau_3_START (10)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_vol_equal_flag_vau_3_END (10)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_vol_equal_flag_clr_vau_3_START (11)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_vol_equal_flag_clr_vau_3_END (11)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_vol_equal_flag_vau_4to1_START (12)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_vol_equal_flag_vau_4to1_END (12)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_vol_equal_flag_clr_vau_4to1_START (13)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_vol_equal_flag_clr_vau_4to1_END (13)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_cur_stat_vau_0_START (14)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_cur_stat_vau_0_END (16)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_cur_stat_vau_1_START (17)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_cur_stat_vau_1_END (19)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_cur_stat_vau_2_START (20)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_cur_stat_vau_2_END (22)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_cur_stat_vau_3_START (23)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_cur_stat_vau_3_END (25)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_cur_stat_vau_4to1_START (26)
#define SOC_PMCTRL_PERI_DVS_STAT0_peri_vau_cur_stat_vau_4to1_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_cur_max_vol_vau_0 : 8;
        unsigned int peri_nxt_max_vol_vau_0 : 8;
        unsigned int peri_cur_max_vol_vau_1 : 8;
        unsigned int peri_nxt_max_vol_vau_1 : 8;
    } reg;
} SOC_PMCTRL_PERI_DVS_STAT1_UNION;
#endif
#define SOC_PMCTRL_PERI_DVS_STAT1_peri_cur_max_vol_vau_0_START (0)
#define SOC_PMCTRL_PERI_DVS_STAT1_peri_cur_max_vol_vau_0_END (7)
#define SOC_PMCTRL_PERI_DVS_STAT1_peri_nxt_max_vol_vau_0_START (8)
#define SOC_PMCTRL_PERI_DVS_STAT1_peri_nxt_max_vol_vau_0_END (15)
#define SOC_PMCTRL_PERI_DVS_STAT1_peri_cur_max_vol_vau_1_START (16)
#define SOC_PMCTRL_PERI_DVS_STAT1_peri_cur_max_vol_vau_1_END (23)
#define SOC_PMCTRL_PERI_DVS_STAT1_peri_nxt_max_vol_vau_1_START (24)
#define SOC_PMCTRL_PERI_DVS_STAT1_peri_nxt_max_vol_vau_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_cur_max_vol_vau_2 : 8;
        unsigned int peri_nxt_max_vol_vau_2 : 8;
        unsigned int peri_cur_max_vol_vau_3 : 8;
        unsigned int peri_nxt_max_vol_vau_3 : 8;
    } reg;
} SOC_PMCTRL_PERI_DVS_STAT2_UNION;
#endif
#define SOC_PMCTRL_PERI_DVS_STAT2_peri_cur_max_vol_vau_2_START (0)
#define SOC_PMCTRL_PERI_DVS_STAT2_peri_cur_max_vol_vau_2_END (7)
#define SOC_PMCTRL_PERI_DVS_STAT2_peri_nxt_max_vol_vau_2_START (8)
#define SOC_PMCTRL_PERI_DVS_STAT2_peri_nxt_max_vol_vau_2_END (15)
#define SOC_PMCTRL_PERI_DVS_STAT2_peri_cur_max_vol_vau_3_START (16)
#define SOC_PMCTRL_PERI_DVS_STAT2_peri_cur_max_vol_vau_3_END (23)
#define SOC_PMCTRL_PERI_DVS_STAT2_peri_nxt_max_vol_vau_3_START (24)
#define SOC_PMCTRL_PERI_DVS_STAT2_peri_nxt_max_vol_vau_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_buck_ctrl_cur_vol_idx : 8;
        unsigned int peri_buck_ctrl_nxt_vol_idx : 8;
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_PMCTRL_PERI_DVS_STAT3_UNION;
#endif
#define SOC_PMCTRL_PERI_DVS_STAT3_peri_buck_ctrl_cur_vol_idx_START (0)
#define SOC_PMCTRL_PERI_DVS_STAT3_peri_buck_ctrl_cur_vol_idx_END (7)
#define SOC_PMCTRL_PERI_DVS_STAT3_peri_buck_ctrl_nxt_vol_idx_START (8)
#define SOC_PMCTRL_PERI_DVS_STAT3_peri_buck_ctrl_nxt_vol_idx_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_valid_vol_vote_idx_0_vau_0 : 8;
        unsigned int peri_valid_vol_vote_idx_1_vau_0 : 8;
        unsigned int peri_valid_vol_vote_idx_2_vau_0 : 8;
        unsigned int peri_valid_vol_vote_idx_3_vau_0 : 8;
    } reg;
} SOC_PMCTRL_PERI_DVS_STAT4_UNION;
#endif
#define SOC_PMCTRL_PERI_DVS_STAT4_peri_valid_vol_vote_idx_0_vau_0_START (0)
#define SOC_PMCTRL_PERI_DVS_STAT4_peri_valid_vol_vote_idx_0_vau_0_END (7)
#define SOC_PMCTRL_PERI_DVS_STAT4_peri_valid_vol_vote_idx_1_vau_0_START (8)
#define SOC_PMCTRL_PERI_DVS_STAT4_peri_valid_vol_vote_idx_1_vau_0_END (15)
#define SOC_PMCTRL_PERI_DVS_STAT4_peri_valid_vol_vote_idx_2_vau_0_START (16)
#define SOC_PMCTRL_PERI_DVS_STAT4_peri_valid_vol_vote_idx_2_vau_0_END (23)
#define SOC_PMCTRL_PERI_DVS_STAT4_peri_valid_vol_vote_idx_3_vau_0_START (24)
#define SOC_PMCTRL_PERI_DVS_STAT4_peri_valid_vol_vote_idx_3_vau_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_valid_vol_vote_idx_4_vau_1 : 8;
        unsigned int peri_valid_vol_vote_idx_5_vau_1 : 8;
        unsigned int peri_valid_vol_vote_idx_6_vau_1 : 8;
        unsigned int peri_valid_vol_vote_idx_7_vau_1 : 8;
    } reg;
} SOC_PMCTRL_PERI_DVS_STAT5_UNION;
#endif
#define SOC_PMCTRL_PERI_DVS_STAT5_peri_valid_vol_vote_idx_4_vau_1_START (0)
#define SOC_PMCTRL_PERI_DVS_STAT5_peri_valid_vol_vote_idx_4_vau_1_END (7)
#define SOC_PMCTRL_PERI_DVS_STAT5_peri_valid_vol_vote_idx_5_vau_1_START (8)
#define SOC_PMCTRL_PERI_DVS_STAT5_peri_valid_vol_vote_idx_5_vau_1_END (15)
#define SOC_PMCTRL_PERI_DVS_STAT5_peri_valid_vol_vote_idx_6_vau_1_START (16)
#define SOC_PMCTRL_PERI_DVS_STAT5_peri_valid_vol_vote_idx_6_vau_1_END (23)
#define SOC_PMCTRL_PERI_DVS_STAT5_peri_valid_vol_vote_idx_7_vau_1_START (24)
#define SOC_PMCTRL_PERI_DVS_STAT5_peri_valid_vol_vote_idx_7_vau_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_valid_vol_vote_idx_8_vau_2 : 8;
        unsigned int peri_valid_vol_vote_idx_9_vau_2 : 8;
        unsigned int peri_valid_vol_vote_idx_10_vau_2 : 8;
        unsigned int peri_valid_vol_vote_idx_11_vau_2 : 8;
    } reg;
} SOC_PMCTRL_PERI_DVS_STAT6_UNION;
#endif
#define SOC_PMCTRL_PERI_DVS_STAT6_peri_valid_vol_vote_idx_8_vau_2_START (0)
#define SOC_PMCTRL_PERI_DVS_STAT6_peri_valid_vol_vote_idx_8_vau_2_END (7)
#define SOC_PMCTRL_PERI_DVS_STAT6_peri_valid_vol_vote_idx_9_vau_2_START (8)
#define SOC_PMCTRL_PERI_DVS_STAT6_peri_valid_vol_vote_idx_9_vau_2_END (15)
#define SOC_PMCTRL_PERI_DVS_STAT6_peri_valid_vol_vote_idx_10_vau_2_START (16)
#define SOC_PMCTRL_PERI_DVS_STAT6_peri_valid_vol_vote_idx_10_vau_2_END (23)
#define SOC_PMCTRL_PERI_DVS_STAT6_peri_valid_vol_vote_idx_11_vau_2_START (24)
#define SOC_PMCTRL_PERI_DVS_STAT6_peri_valid_vol_vote_idx_11_vau_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_valid_vol_vote_idx_12_vau_3 : 8;
        unsigned int peri_valid_vol_vote_idx_13_vau_3 : 8;
        unsigned int peri_valid_vol_vote_idx_14_vau_3 : 8;
        unsigned int peri_valid_vol_vote_idx_15_vau_3 : 8;
    } reg;
} SOC_PMCTRL_PERI_DVS_STAT7_UNION;
#endif
#define SOC_PMCTRL_PERI_DVS_STAT7_peri_valid_vol_vote_idx_12_vau_3_START (0)
#define SOC_PMCTRL_PERI_DVS_STAT7_peri_valid_vol_vote_idx_12_vau_3_END (7)
#define SOC_PMCTRL_PERI_DVS_STAT7_peri_valid_vol_vote_idx_13_vau_3_START (8)
#define SOC_PMCTRL_PERI_DVS_STAT7_peri_valid_vol_vote_idx_13_vau_3_END (15)
#define SOC_PMCTRL_PERI_DVS_STAT7_peri_valid_vol_vote_idx_14_vau_3_START (16)
#define SOC_PMCTRL_PERI_DVS_STAT7_peri_valid_vol_vote_idx_14_vau_3_END (23)
#define SOC_PMCTRL_PERI_DVS_STAT7_peri_valid_vol_vote_idx_15_vau_3_START (24)
#define SOC_PMCTRL_PERI_DVS_STAT7_peri_valid_vol_vote_idx_15_vau_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_valid_vol_vote_idx_0_vau_4to1 : 8;
        unsigned int peri_valid_vol_vote_idx_1_vau_4to1 : 8;
        unsigned int peri_valid_vol_vote_idx_2_vau_4to1 : 8;
        unsigned int peri_valid_vol_vote_idx_3_vau_4to1 : 8;
    } reg;
} SOC_PMCTRL_PERI_DVS_STAT8_UNION;
#endif
#define SOC_PMCTRL_PERI_DVS_STAT8_peri_valid_vol_vote_idx_0_vau_4to1_START (0)
#define SOC_PMCTRL_PERI_DVS_STAT8_peri_valid_vol_vote_idx_0_vau_4to1_END (7)
#define SOC_PMCTRL_PERI_DVS_STAT8_peri_valid_vol_vote_idx_1_vau_4to1_START (8)
#define SOC_PMCTRL_PERI_DVS_STAT8_peri_valid_vol_vote_idx_1_vau_4to1_END (15)
#define SOC_PMCTRL_PERI_DVS_STAT8_peri_valid_vol_vote_idx_2_vau_4to1_START (16)
#define SOC_PMCTRL_PERI_DVS_STAT8_peri_valid_vol_vote_idx_2_vau_4to1_END (23)
#define SOC_PMCTRL_PERI_DVS_STAT8_peri_valid_vol_vote_idx_3_vau_4to1_START (24)
#define SOC_PMCTRL_PERI_DVS_STAT8_peri_valid_vol_vote_idx_3_vau_4to1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vol_profile_rank_idx : 8;
        unsigned int reserved_0 : 8;
        unsigned int peri_dvs_profile_status : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 14;
    } reg;
} SOC_PMCTRL_PERI_VOL_DOZE_VOTE_CTRL_UNION;
#endif
#define SOC_PMCTRL_PERI_VOL_DOZE_VOTE_CTRL_peri_vol_profile_rank_idx_START (0)
#define SOC_PMCTRL_PERI_VOL_DOZE_VOTE_CTRL_peri_vol_profile_rank_idx_END (7)
#define SOC_PMCTRL_PERI_VOL_DOZE_VOTE_CTRL_peri_dvs_profile_status_START (16)
#define SOC_PMCTRL_PERI_VOL_DOZE_VOTE_CTRL_peri_dvs_profile_status_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_pmu_buck_on_time : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_PERI_PMU_BUCK_ON_TIME_UNION;
#endif
#define SOC_PMCTRL_PERI_PMU_BUCK_ON_TIME_peri_pmu_buck_on_time_START (0)
#define SOC_PMCTRL_PERI_PMU_BUCK_ON_TIME_peri_pmu_buck_on_time_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_pmu_buck_off_time : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_PERI_PMU_BUCK_OFF_TIME_UNION;
#endif
#define SOC_PMCTRL_PERI_PMU_BUCK_OFF_TIME_peri_pmu_buck_off_time_START (0)
#define SOC_PMCTRL_PERI_PMU_BUCK_OFF_TIME_peri_pmu_buck_off_time_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_init_vol_idx_vau_3 : 8;
        unsigned int peri_init_vol_req_vau_3 : 1;
        unsigned int peri_init_vol_idx_vau_4to1 : 8;
        unsigned int peri_init_vol_req_vau_4to1 : 1;
        unsigned int peri_sft_buck_vol_idx : 8;
        unsigned int peri_sft_buck_on_req : 1;
        unsigned int peri_sft_buck_off_req : 1;
        unsigned int peri_sft_buck_onoff_req_en : 1;
        unsigned int reserved : 3;
    } reg;
} SOC_PMCTRL_PERI_INIT_VOL_CONFIG1_UNION;
#endif
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG1_peri_init_vol_idx_vau_3_START (0)
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG1_peri_init_vol_idx_vau_3_END (7)
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG1_peri_init_vol_req_vau_3_START (8)
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG1_peri_init_vol_req_vau_3_END (8)
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG1_peri_init_vol_idx_vau_4to1_START (9)
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG1_peri_init_vol_idx_vau_4to1_END (16)
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG1_peri_init_vol_req_vau_4to1_START (17)
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG1_peri_init_vol_req_vau_4to1_END (17)
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG1_peri_sft_buck_vol_idx_START (18)
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG1_peri_sft_buck_vol_idx_END (25)
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG1_peri_sft_buck_on_req_START (26)
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG1_peri_sft_buck_on_req_END (26)
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG1_peri_sft_buck_off_req_START (27)
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG1_peri_sft_buck_off_req_END (27)
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG1_peri_sft_buck_onoff_req_en_START (28)
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG1_peri_sft_buck_onoff_req_en_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_pmu_up_hold_time : 20;
        unsigned int peri_pmu_up_step_time : 12;
    } reg;
} SOC_PMCTRL_PERI_PMU_TRIM_UP_TIME_UNION;
#endif
#define SOC_PMCTRL_PERI_PMU_TRIM_UP_TIME_peri_pmu_up_hold_time_START (0)
#define SOC_PMCTRL_PERI_PMU_TRIM_UP_TIME_peri_pmu_up_hold_time_END (19)
#define SOC_PMCTRL_PERI_PMU_TRIM_UP_TIME_peri_pmu_up_step_time_START (20)
#define SOC_PMCTRL_PERI_PMU_TRIM_UP_TIME_peri_pmu_up_step_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_pmu_dn_hold_time : 20;
        unsigned int peri_pmu_dn_step_time : 12;
    } reg;
} SOC_PMCTRL_PERI_PMU_TRIM_DN_TTME_UNION;
#endif
#define SOC_PMCTRL_PERI_PMU_TRIM_DN_TTME_peri_pmu_dn_hold_time_START (0)
#define SOC_PMCTRL_PERI_PMU_TRIM_DN_TTME_peri_pmu_dn_hold_time_END (19)
#define SOC_PMCTRL_PERI_PMU_TRIM_DN_TTME_peri_pmu_dn_step_time_START (20)
#define SOC_PMCTRL_PERI_PMU_TRIM_DN_TTME_peri_pmu_dn_step_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_init_vol_idx_vau_0 : 8;
        unsigned int peri_init_vol_req_vau_0 : 1;
        unsigned int peri_init_vol_idx_vau_1 : 8;
        unsigned int peri_init_vol_req_vau_1 : 1;
        unsigned int peri_init_vol_idx_vau_2 : 8;
        unsigned int peri_init_vol_req_vau_2 : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_PMCTRL_PERI_INIT_VOL_CONFIG0_UNION;
#endif
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG0_peri_init_vol_idx_vau_0_START (0)
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG0_peri_init_vol_idx_vau_0_END (7)
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG0_peri_init_vol_req_vau_0_START (8)
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG0_peri_init_vol_req_vau_0_END (8)
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG0_peri_init_vol_idx_vau_1_START (9)
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG0_peri_init_vol_idx_vau_1_END (16)
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG0_peri_init_vol_req_vau_1_START (17)
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG0_peri_init_vol_req_vau_1_END (17)
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG0_peri_init_vol_idx_vau_2_START (18)
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG0_peri_init_vol_idx_vau_2_END (25)
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG0_peri_init_vol_req_vau_2_START (26)
#define SOC_PMCTRL_PERI_INIT_VOL_CONFIG0_peri_init_vol_req_vau_2_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_sft_fix_vol_idx : 8;
        unsigned int peri_sft_fix_vol : 1;
        unsigned int peri_sft_fix_vol_req : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_PMCTRL_PERI_FIX_VOL_CONFIG_UNION;
#endif
#define SOC_PMCTRL_PERI_FIX_VOL_CONFIG_peri_sft_fix_vol_idx_START (0)
#define SOC_PMCTRL_PERI_FIX_VOL_CONFIG_peri_sft_fix_vol_idx_END (7)
#define SOC_PMCTRL_PERI_FIX_VOL_CONFIG_peri_sft_fix_vol_START (8)
#define SOC_PMCTRL_PERI_FIX_VOL_CONFIG_peri_sft_fix_vol_END (8)
#define SOC_PMCTRL_PERI_FIX_VOL_CONFIG_peri_sft_fix_vol_req_START (9)
#define SOC_PMCTRL_PERI_FIX_VOL_CONFIG_peri_sft_fix_vol_req_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_cur_max_vol : 8;
        unsigned int peri_nxt_max_vol : 8;
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_PMCTRL_PERI_VOL_READ_UNION;
#endif
#define SOC_PMCTRL_PERI_VOL_READ_peri_cur_max_vol_START (0)
#define SOC_PMCTRL_PERI_VOL_READ_peri_cur_max_vol_END (7)
#define SOC_PMCTRL_PERI_VOL_READ_peri_nxt_max_vol_START (8)
#define SOC_PMCTRL_PERI_VOL_READ_peri_nxt_max_vol_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_sft_vol_idx_0_vau_4to1 : 8;
        unsigned int peri_vote_sft_vol_idx_1_vau_4to1 : 8;
        unsigned int peri_vote_sft_vol_idx_2_vau_4to1 : 8;
        unsigned int peri_vote_sft_vol_idx_3_vau_4to1 : 8;
    } reg;
} SOC_PMCTRL_PERI_VOTE_SFT_HRD_VOL_IDX_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_SFT_HRD_VOL_IDX_peri_vote_sft_vol_idx_0_vau_4to1_START (0)
#define SOC_PMCTRL_PERI_VOTE_SFT_HRD_VOL_IDX_peri_vote_sft_vol_idx_0_vau_4to1_END (7)
#define SOC_PMCTRL_PERI_VOTE_SFT_HRD_VOL_IDX_peri_vote_sft_vol_idx_1_vau_4to1_START (8)
#define SOC_PMCTRL_PERI_VOTE_SFT_HRD_VOL_IDX_peri_vote_sft_vol_idx_1_vau_4to1_END (15)
#define SOC_PMCTRL_PERI_VOTE_SFT_HRD_VOL_IDX_peri_vote_sft_vol_idx_2_vau_4to1_START (16)
#define SOC_PMCTRL_PERI_VOTE_SFT_HRD_VOL_IDX_peri_vote_sft_vol_idx_2_vau_4to1_END (23)
#define SOC_PMCTRL_PERI_VOTE_SFT_HRD_VOL_IDX_peri_vote_sft_vol_idx_3_vau_4to1_START (24)
#define SOC_PMCTRL_PERI_VOTE_SFT_HRD_VOL_IDX_peri_vote_sft_vol_idx_3_vau_4to1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_stat_time_hold : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_PERI_STAT_TIME_HOLD_UNION;
#endif
#define SOC_PMCTRL_PERI_STAT_TIME_HOLD_peri_stat_time_hold_START (0)
#define SOC_PMCTRL_PERI_STAT_TIME_HOLD_peri_stat_time_hold_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vol_chg_flag : 21;
        unsigned int peri_separate_vset_ven_ctrl_bypass : 1;
        unsigned int peri_fer_buck_pg_bypass : 1;
        unsigned int peri_fer_buck_vok_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_PMCTRL_PERI_VOL_CHG_FLAG_UNION;
#endif
#define SOC_PMCTRL_PERI_VOL_CHG_FLAG_peri_vol_chg_flag_START (0)
#define SOC_PMCTRL_PERI_VOL_CHG_FLAG_peri_vol_chg_flag_END (20)
#define SOC_PMCTRL_PERI_VOL_CHG_FLAG_peri_separate_vset_ven_ctrl_bypass_START (21)
#define SOC_PMCTRL_PERI_VOL_CHG_FLAG_peri_separate_vset_ven_ctrl_bypass_END (21)
#define SOC_PMCTRL_PERI_VOL_CHG_FLAG_peri_fer_buck_pg_bypass_START (22)
#define SOC_PMCTRL_PERI_VOL_CHG_FLAG_peri_fer_buck_pg_bypass_END (22)
#define SOC_PMCTRL_PERI_VOL_CHG_FLAG_peri_fer_buck_vok_bypass_START (23)
#define SOC_PMCTRL_PERI_VOL_CHG_FLAG_peri_fer_buck_vok_bypass_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_spmi_hold_time : 20;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_PMCTRL_PERI_SPMI_HOLD_TIME_UNION;
#endif
#define SOC_PMCTRL_PERI_SPMI_HOLD_TIME_peri_spmi_hold_time_START (0)
#define SOC_PMCTRL_PERI_SPMI_HOLD_TIME_peri_spmi_hold_time_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fer_buck_pgvok_req_peri : 1;
        unsigned int fer_buck_pgvok_ack_peri : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_PMCTRL_PERI_FER_REQ_ACK_UNION;
#endif
#define SOC_PMCTRL_PERI_FER_REQ_ACK_fer_buck_pgvok_req_peri_START (0)
#define SOC_PMCTRL_PERI_FER_REQ_ACK_fer_buck_pgvok_req_peri_END (0)
#define SOC_PMCTRL_PERI_FER_REQ_ACK_fer_buck_pgvok_ack_peri_START (1)
#define SOC_PMCTRL_PERI_FER_REQ_ACK_fer_buck_pgvok_ack_peri_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch0_idx_0 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH0_IDX_0_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH0_IDX_0_peri_vote_vol_ch0_idx_0_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH0_IDX_0_peri_vote_vol_ch0_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch0_idx_1 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH0_IDX_1_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH0_IDX_1_peri_vote_vol_ch0_idx_1_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH0_IDX_1_peri_vote_vol_ch0_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch1_idx_0 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH1_IDX_0_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH1_IDX_0_peri_vote_vol_ch1_idx_0_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH1_IDX_0_peri_vote_vol_ch1_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch1_idx_1 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH1_IDX_1_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH1_IDX_1_peri_vote_vol_ch1_idx_1_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH1_IDX_1_peri_vote_vol_ch1_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch2_idx_0 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH2_IDX_0_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH2_IDX_0_peri_vote_vol_ch2_idx_0_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH2_IDX_0_peri_vote_vol_ch2_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch2_idx_1 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH2_IDX_1_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH2_IDX_1_peri_vote_vol_ch2_idx_1_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH2_IDX_1_peri_vote_vol_ch2_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch3_idx_0 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH3_IDX_0_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH3_IDX_0_peri_vote_vol_ch3_idx_0_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH3_IDX_0_peri_vote_vol_ch3_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch3_idx_1 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH3_IDX_1_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH3_IDX_1_peri_vote_vol_ch3_idx_1_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH3_IDX_1_peri_vote_vol_ch3_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch4_idx_0 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH4_IDX_0_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH4_IDX_0_peri_vote_vol_ch4_idx_0_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH4_IDX_0_peri_vote_vol_ch4_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch4_idx_1 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH4_IDX_1_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH4_IDX_1_peri_vote_vol_ch4_idx_1_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH4_IDX_1_peri_vote_vol_ch4_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch5_idx_0 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH5_IDX_0_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH5_IDX_0_peri_vote_vol_ch5_idx_0_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH5_IDX_0_peri_vote_vol_ch5_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch5_idx_1 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH5_IDX_1_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH5_IDX_1_peri_vote_vol_ch5_idx_1_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH5_IDX_1_peri_vote_vol_ch5_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch6_idx_0 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH6_IDX_0_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH6_IDX_0_peri_vote_vol_ch6_idx_0_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH6_IDX_0_peri_vote_vol_ch6_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch6_idx_1 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH6_IDX_1_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH6_IDX_1_peri_vote_vol_ch6_idx_1_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH6_IDX_1_peri_vote_vol_ch6_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch7_idx_0 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH7_IDX_0_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH7_IDX_0_peri_vote_vol_ch7_idx_0_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH7_IDX_0_peri_vote_vol_ch7_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch7_idx_1 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH7_IDX_1_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH7_IDX_1_peri_vote_vol_ch7_idx_1_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH7_IDX_1_peri_vote_vol_ch7_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch8_idx_0 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH8_IDX_0_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH8_IDX_0_peri_vote_vol_ch8_idx_0_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH8_IDX_0_peri_vote_vol_ch8_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch8_idx_1 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH8_IDX_1_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH8_IDX_1_peri_vote_vol_ch8_idx_1_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH8_IDX_1_peri_vote_vol_ch8_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch9_idx_0 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH9_IDX_0_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH9_IDX_0_peri_vote_vol_ch9_idx_0_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH9_IDX_0_peri_vote_vol_ch9_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch9_idx_1 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH9_IDX_1_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH9_IDX_1_peri_vote_vol_ch9_idx_1_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH9_IDX_1_peri_vote_vol_ch9_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch10_idx_0 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH10_IDX_0_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH10_IDX_0_peri_vote_vol_ch10_idx_0_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH10_IDX_0_peri_vote_vol_ch10_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch10_idx_1 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH10_IDX_1_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH10_IDX_1_peri_vote_vol_ch10_idx_1_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH10_IDX_1_peri_vote_vol_ch10_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch11_idx_0 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH11_IDX_0_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH11_IDX_0_peri_vote_vol_ch11_idx_0_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH11_IDX_0_peri_vote_vol_ch11_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch11_idx_1 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH11_IDX_1_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH11_IDX_1_peri_vote_vol_ch11_idx_1_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH11_IDX_1_peri_vote_vol_ch11_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch12_idx_0 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH12_IDX_0_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH12_IDX_0_peri_vote_vol_ch12_idx_0_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH12_IDX_0_peri_vote_vol_ch12_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch12_idx_1 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH12_IDX_1_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH12_IDX_1_peri_vote_vol_ch12_idx_1_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH12_IDX_1_peri_vote_vol_ch12_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch13_idx_0 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH13_IDX_0_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH13_IDX_0_peri_vote_vol_ch13_idx_0_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH13_IDX_0_peri_vote_vol_ch13_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch13_idx_1 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH13_IDX_1_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH13_IDX_1_peri_vote_vol_ch13_idx_1_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH13_IDX_1_peri_vote_vol_ch13_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch14_idx_0 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH14_IDX_0_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH14_IDX_0_peri_vote_vol_ch14_idx_0_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH14_IDX_0_peri_vote_vol_ch14_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch14_idx_1 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH14_IDX_1_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH14_IDX_1_peri_vote_vol_ch14_idx_1_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH14_IDX_1_peri_vote_vol_ch14_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch15_idx_0 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH15_IDX_0_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH15_IDX_0_peri_vote_vol_ch15_idx_0_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH15_IDX_0_peri_vote_vol_ch15_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_vote_vol_ch15_idx_1 : 32;
    } reg;
} SOC_PMCTRL_PERI_VOTE_VOL_CH15_IDX_1_UNION;
#endif
#define SOC_PMCTRL_PERI_VOTE_VOL_CH15_IDX_1_peri_vote_vol_ch15_idx_1_START (0)
#define SOC_PMCTRL_PERI_VOTE_VOL_CH15_IDX_1_peri_vote_vol_ch15_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_vote_vol_rank_0 : 3;
        unsigned int buck5_vote_vol_rank_1 : 3;
        unsigned int buck5_vote_vol_rank_2 : 3;
        unsigned int buck5_vote_vol_rank_3 : 3;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_PMCTRL_BUCK5_VOTE_VOL_RANK_SFT_0_UNION;
#endif
#define SOC_PMCTRL_BUCK5_VOTE_VOL_RANK_SFT_0_buck5_vote_vol_rank_0_START (0)
#define SOC_PMCTRL_BUCK5_VOTE_VOL_RANK_SFT_0_buck5_vote_vol_rank_0_END (2)
#define SOC_PMCTRL_BUCK5_VOTE_VOL_RANK_SFT_0_buck5_vote_vol_rank_1_START (3)
#define SOC_PMCTRL_BUCK5_VOTE_VOL_RANK_SFT_0_buck5_vote_vol_rank_1_END (5)
#define SOC_PMCTRL_BUCK5_VOTE_VOL_RANK_SFT_0_buck5_vote_vol_rank_2_START (6)
#define SOC_PMCTRL_BUCK5_VOTE_VOL_RANK_SFT_0_buck5_vote_vol_rank_2_END (8)
#define SOC_PMCTRL_BUCK5_VOTE_VOL_RANK_SFT_0_buck5_vote_vol_rank_3_START (9)
#define SOC_PMCTRL_BUCK5_VOTE_VOL_RANK_SFT_0_buck5_vote_vol_rank_3_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_vote_vol_valid_0 : 1;
        unsigned int buck5_vote_vol_valid_1 : 1;
        unsigned int buck5_vote_vol_valid_2 : 1;
        unsigned int buck5_vote_vol_valid_3 : 1;
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
        unsigned int reserved_12 : 16;
    } reg;
} SOC_PMCTRL_BUCK5_VOTE_VOL_VALID_UNION;
#endif
#define SOC_PMCTRL_BUCK5_VOTE_VOL_VALID_buck5_vote_vol_valid_0_START (0)
#define SOC_PMCTRL_BUCK5_VOTE_VOL_VALID_buck5_vote_vol_valid_0_END (0)
#define SOC_PMCTRL_BUCK5_VOTE_VOL_VALID_buck5_vote_vol_valid_1_START (1)
#define SOC_PMCTRL_BUCK5_VOTE_VOL_VALID_buck5_vote_vol_valid_1_END (1)
#define SOC_PMCTRL_BUCK5_VOTE_VOL_VALID_buck5_vote_vol_valid_2_START (2)
#define SOC_PMCTRL_BUCK5_VOTE_VOL_VALID_buck5_vote_vol_valid_2_END (2)
#define SOC_PMCTRL_BUCK5_VOTE_VOL_VALID_buck5_vote_vol_valid_3_START (3)
#define SOC_PMCTRL_BUCK5_VOTE_VOL_VALID_buck5_vote_vol_valid_3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_vote_sft_chg_0 : 1;
        unsigned int buck5_vote_sft_chg_1 : 1;
        unsigned int buck5_vote_sft_chg_2 : 1;
        unsigned int buck5_vote_sft_chg_3 : 1;
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
        unsigned int reserved_16 : 12;
    } reg;
} SOC_PMCTRL_BUCK5_VOTE_SFT_CHG_UNION;
#endif
#define SOC_PMCTRL_BUCK5_VOTE_SFT_CHG_buck5_vote_sft_chg_0_START (0)
#define SOC_PMCTRL_BUCK5_VOTE_SFT_CHG_buck5_vote_sft_chg_0_END (0)
#define SOC_PMCTRL_BUCK5_VOTE_SFT_CHG_buck5_vote_sft_chg_1_START (1)
#define SOC_PMCTRL_BUCK5_VOTE_SFT_CHG_buck5_vote_sft_chg_1_END (1)
#define SOC_PMCTRL_BUCK5_VOTE_SFT_CHG_buck5_vote_sft_chg_2_START (2)
#define SOC_PMCTRL_BUCK5_VOTE_SFT_CHG_buck5_vote_sft_chg_2_END (2)
#define SOC_PMCTRL_BUCK5_VOTE_SFT_CHG_buck5_vote_sft_chg_3_START (3)
#define SOC_PMCTRL_BUCK5_VOTE_SFT_CHG_buck5_vote_sft_chg_3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_soft_vol_vote_en_0 : 1;
        unsigned int buck5_soft_vol_vote_en_1 : 1;
        unsigned int buck5_soft_vol_vote_en_2 : 1;
        unsigned int buck5_soft_vol_vote_en_3 : 1;
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
        unsigned int reserved_20 : 8;
    } reg;
} SOC_PMCTRL_BUCK5_VOTE_SFT_CHG_BYPASS_UNION;
#endif
#define SOC_PMCTRL_BUCK5_VOTE_SFT_CHG_BYPASS_buck5_soft_vol_vote_en_0_START (0)
#define SOC_PMCTRL_BUCK5_VOTE_SFT_CHG_BYPASS_buck5_soft_vol_vote_en_0_END (0)
#define SOC_PMCTRL_BUCK5_VOTE_SFT_CHG_BYPASS_buck5_soft_vol_vote_en_1_START (1)
#define SOC_PMCTRL_BUCK5_VOTE_SFT_CHG_BYPASS_buck5_soft_vol_vote_en_1_END (1)
#define SOC_PMCTRL_BUCK5_VOTE_SFT_CHG_BYPASS_buck5_soft_vol_vote_en_2_START (2)
#define SOC_PMCTRL_BUCK5_VOTE_SFT_CHG_BYPASS_buck5_soft_vol_vote_en_2_END (2)
#define SOC_PMCTRL_BUCK5_VOTE_SFT_CHG_BYPASS_buck5_soft_vol_vote_en_3_START (3)
#define SOC_PMCTRL_BUCK5_VOTE_SFT_CHG_BYPASS_buck5_soft_vol_vote_en_3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_vol_sft_clr_0 : 1;
        unsigned int buck5_vol_sft_clr_1 : 1;
        unsigned int buck5_vol_sft_clr_2 : 1;
        unsigned int buck5_vol_sft_clr_3 : 1;
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
        unsigned int reserved_16 : 12;
    } reg;
} SOC_PMCTRL_BUCK5_VOL_SFT_CLR_UNION;
#endif
#define SOC_PMCTRL_BUCK5_VOL_SFT_CLR_buck5_vol_sft_clr_0_START (0)
#define SOC_PMCTRL_BUCK5_VOL_SFT_CLR_buck5_vol_sft_clr_0_END (0)
#define SOC_PMCTRL_BUCK5_VOL_SFT_CLR_buck5_vol_sft_clr_1_START (1)
#define SOC_PMCTRL_BUCK5_VOL_SFT_CLR_buck5_vol_sft_clr_1_END (1)
#define SOC_PMCTRL_BUCK5_VOL_SFT_CLR_buck5_vol_sft_clr_2_START (2)
#define SOC_PMCTRL_BUCK5_VOL_SFT_CLR_buck5_vol_sft_clr_2_END (2)
#define SOC_PMCTRL_BUCK5_VOL_SFT_CLR_buck5_vol_sft_clr_3_START (3)
#define SOC_PMCTRL_BUCK5_VOL_SFT_CLR_buck5_vol_sft_clr_3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_vol_stable_0 : 1;
        unsigned int buck5_vol_stable_1 : 1;
        unsigned int buck5_vol_stable_2 : 1;
        unsigned int buck5_vol_stable_3 : 1;
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
        unsigned int reserved_16 : 12;
    } reg;
} SOC_PMCTRL_BUCK5_VOL_STABLE_UNION;
#endif
#define SOC_PMCTRL_BUCK5_VOL_STABLE_buck5_vol_stable_0_START (0)
#define SOC_PMCTRL_BUCK5_VOL_STABLE_buck5_vol_stable_0_END (0)
#define SOC_PMCTRL_BUCK5_VOL_STABLE_buck5_vol_stable_1_START (1)
#define SOC_PMCTRL_BUCK5_VOL_STABLE_buck5_vol_stable_1_END (1)
#define SOC_PMCTRL_BUCK5_VOL_STABLE_buck5_vol_stable_2_START (2)
#define SOC_PMCTRL_BUCK5_VOL_STABLE_buck5_vol_stable_2_END (2)
#define SOC_PMCTRL_BUCK5_VOL_STABLE_buck5_vol_stable_3_START (3)
#define SOC_PMCTRL_BUCK5_VOL_STABLE_buck5_vol_stable_3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_intr_lpm3_msk : 4;
        unsigned int buck5_intr_acpu_msk : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_PMCTRL_BUCK5_INTR_M3ORCPU_MSK_UNION;
#endif
#define SOC_PMCTRL_BUCK5_INTR_M3ORCPU_MSK_buck5_intr_lpm3_msk_START (0)
#define SOC_PMCTRL_BUCK5_INTR_M3ORCPU_MSK_buck5_intr_lpm3_msk_END (3)
#define SOC_PMCTRL_BUCK5_INTR_M3ORCPU_MSK_buck5_intr_acpu_msk_START (4)
#define SOC_PMCTRL_BUCK5_INTR_M3ORCPU_MSK_buck5_intr_acpu_msk_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_pmu_vol_idx_spmi : 8;
        unsigned int buck5_pmu_vol_chg_spmi : 1;
        unsigned int intr_buck5_dvs_stat_pmc2lpm3 : 1;
        unsigned int intr_buck5_dvs_stat_pmc2acpu : 1;
        unsigned int buck5_pmu_vol_ack_spmi : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int buck5_buck_on_off_stable : 1;
        unsigned int reserved_2 : 3;
        unsigned int buck5_buck_ctrl_cur_stat : 3;
        unsigned int reserved_3 : 11;
    } reg;
} SOC_PMCTRL_BUCK5_DVS_OUTPUT_READ_UNION;
#endif
#define SOC_PMCTRL_BUCK5_DVS_OUTPUT_READ_buck5_pmu_vol_idx_spmi_START (0)
#define SOC_PMCTRL_BUCK5_DVS_OUTPUT_READ_buck5_pmu_vol_idx_spmi_END (7)
#define SOC_PMCTRL_BUCK5_DVS_OUTPUT_READ_buck5_pmu_vol_chg_spmi_START (8)
#define SOC_PMCTRL_BUCK5_DVS_OUTPUT_READ_buck5_pmu_vol_chg_spmi_END (8)
#define SOC_PMCTRL_BUCK5_DVS_OUTPUT_READ_intr_buck5_dvs_stat_pmc2lpm3_START (9)
#define SOC_PMCTRL_BUCK5_DVS_OUTPUT_READ_intr_buck5_dvs_stat_pmc2lpm3_END (9)
#define SOC_PMCTRL_BUCK5_DVS_OUTPUT_READ_intr_buck5_dvs_stat_pmc2acpu_START (10)
#define SOC_PMCTRL_BUCK5_DVS_OUTPUT_READ_intr_buck5_dvs_stat_pmc2acpu_END (10)
#define SOC_PMCTRL_BUCK5_DVS_OUTPUT_READ_buck5_pmu_vol_ack_spmi_START (11)
#define SOC_PMCTRL_BUCK5_DVS_OUTPUT_READ_buck5_pmu_vol_ack_spmi_END (11)
#define SOC_PMCTRL_BUCK5_DVS_OUTPUT_READ_buck5_buck_on_off_stable_START (14)
#define SOC_PMCTRL_BUCK5_DVS_OUTPUT_READ_buck5_buck_on_off_stable_END (14)
#define SOC_PMCTRL_BUCK5_DVS_OUTPUT_READ_buck5_buck_ctrl_cur_stat_START (18)
#define SOC_PMCTRL_BUCK5_DVS_OUTPUT_READ_buck5_buck_ctrl_cur_stat_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_intr_bypass_0 : 1;
        unsigned int buck5_intr_bypass_1 : 1;
        unsigned int buck5_intr_bypass_2 : 1;
        unsigned int buck5_intr_bypass_3 : 1;
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
        unsigned int reserved_12 : 16;
    } reg;
} SOC_PMCTRL_BUCK5_INTR_BYPASS_SFT_UNION;
#endif
#define SOC_PMCTRL_BUCK5_INTR_BYPASS_SFT_buck5_intr_bypass_0_START (0)
#define SOC_PMCTRL_BUCK5_INTR_BYPASS_SFT_buck5_intr_bypass_0_END (0)
#define SOC_PMCTRL_BUCK5_INTR_BYPASS_SFT_buck5_intr_bypass_1_START (1)
#define SOC_PMCTRL_BUCK5_INTR_BYPASS_SFT_buck5_intr_bypass_1_END (1)
#define SOC_PMCTRL_BUCK5_INTR_BYPASS_SFT_buck5_intr_bypass_2_START (2)
#define SOC_PMCTRL_BUCK5_INTR_BYPASS_SFT_buck5_intr_bypass_2_END (2)
#define SOC_PMCTRL_BUCK5_INTR_BYPASS_SFT_buck5_intr_bypass_3_START (3)
#define SOC_PMCTRL_BUCK5_INTR_BYPASS_SFT_buck5_intr_bypass_3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_dvs_spmi_hold_timeout_flag : 1;
        unsigned int buck5_dvs_buck_onoff_timeout_flag : 1;
        unsigned int buck5_dvs_fer_err_flag : 1;
        unsigned int buck5_dvs_timeout_flag_clr : 1;
        unsigned int buck5_vau_vol_equal_flag_vau : 1;
        unsigned int buck5_vau_vol_equal_flag_clr_vau : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int buck5_vau_cur_stat_vau : 3;
        unsigned int reserved_8 : 3;
        unsigned int reserved_9 : 3;
        unsigned int reserved_10 : 3;
        unsigned int reserved_11 : 3;
        unsigned int reserved_12 : 3;
    } reg;
} SOC_PMCTRL_BUCK5_DVS_STAT0_UNION;
#endif
#define SOC_PMCTRL_BUCK5_DVS_STAT0_buck5_dvs_spmi_hold_timeout_flag_START (0)
#define SOC_PMCTRL_BUCK5_DVS_STAT0_buck5_dvs_spmi_hold_timeout_flag_END (0)
#define SOC_PMCTRL_BUCK5_DVS_STAT0_buck5_dvs_buck_onoff_timeout_flag_START (1)
#define SOC_PMCTRL_BUCK5_DVS_STAT0_buck5_dvs_buck_onoff_timeout_flag_END (1)
#define SOC_PMCTRL_BUCK5_DVS_STAT0_buck5_dvs_fer_err_flag_START (2)
#define SOC_PMCTRL_BUCK5_DVS_STAT0_buck5_dvs_fer_err_flag_END (2)
#define SOC_PMCTRL_BUCK5_DVS_STAT0_buck5_dvs_timeout_flag_clr_START (3)
#define SOC_PMCTRL_BUCK5_DVS_STAT0_buck5_dvs_timeout_flag_clr_END (3)
#define SOC_PMCTRL_BUCK5_DVS_STAT0_buck5_vau_vol_equal_flag_vau_START (4)
#define SOC_PMCTRL_BUCK5_DVS_STAT0_buck5_vau_vol_equal_flag_vau_END (4)
#define SOC_PMCTRL_BUCK5_DVS_STAT0_buck5_vau_vol_equal_flag_clr_vau_START (5)
#define SOC_PMCTRL_BUCK5_DVS_STAT0_buck5_vau_vol_equal_flag_clr_vau_END (5)
#define SOC_PMCTRL_BUCK5_DVS_STAT0_buck5_vau_cur_stat_vau_START (14)
#define SOC_PMCTRL_BUCK5_DVS_STAT0_buck5_vau_cur_stat_vau_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_cur_max_vol_vau : 8;
        unsigned int buck5_nxt_max_vol_vau : 8;
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_PMCTRL_BUCK5_DVS_STAT1_UNION;
#endif
#define SOC_PMCTRL_BUCK5_DVS_STAT1_buck5_cur_max_vol_vau_START (0)
#define SOC_PMCTRL_BUCK5_DVS_STAT1_buck5_cur_max_vol_vau_END (7)
#define SOC_PMCTRL_BUCK5_DVS_STAT1_buck5_nxt_max_vol_vau_START (8)
#define SOC_PMCTRL_BUCK5_DVS_STAT1_buck5_nxt_max_vol_vau_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_valid_vol_vote_idx_0_vau : 8;
        unsigned int buck5_valid_vol_vote_idx_1_vau : 8;
        unsigned int buck5_valid_vol_vote_idx_2_vau : 8;
        unsigned int buck5_valid_vol_vote_idx_3_vau : 8;
    } reg;
} SOC_PMCTRL_BUCK5_DVS_STAT2_UNION;
#endif
#define SOC_PMCTRL_BUCK5_DVS_STAT2_buck5_valid_vol_vote_idx_0_vau_START (0)
#define SOC_PMCTRL_BUCK5_DVS_STAT2_buck5_valid_vol_vote_idx_0_vau_END (7)
#define SOC_PMCTRL_BUCK5_DVS_STAT2_buck5_valid_vol_vote_idx_1_vau_START (8)
#define SOC_PMCTRL_BUCK5_DVS_STAT2_buck5_valid_vol_vote_idx_1_vau_END (15)
#define SOC_PMCTRL_BUCK5_DVS_STAT2_buck5_valid_vol_vote_idx_2_vau_START (16)
#define SOC_PMCTRL_BUCK5_DVS_STAT2_buck5_valid_vol_vote_idx_2_vau_END (23)
#define SOC_PMCTRL_BUCK5_DVS_STAT2_buck5_valid_vol_vote_idx_3_vau_START (24)
#define SOC_PMCTRL_BUCK5_DVS_STAT2_buck5_valid_vol_vote_idx_3_vau_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_vote_vol_ch0_idx_0 : 32;
    } reg;
} SOC_PMCTRL_BUCK5_VOTE_VOL_CH0_IDX_0_UNION;
#endif
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH0_IDX_0_buck5_vote_vol_ch0_idx_0_START (0)
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH0_IDX_0_buck5_vote_vol_ch0_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_vote_vol_ch0_idx_1 : 32;
    } reg;
} SOC_PMCTRL_BUCK5_VOTE_VOL_CH0_IDX_1_UNION;
#endif
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH0_IDX_1_buck5_vote_vol_ch0_idx_1_START (0)
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH0_IDX_1_buck5_vote_vol_ch0_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_vote_vol_ch1_idx_0 : 32;
    } reg;
} SOC_PMCTRL_BUCK5_VOTE_VOL_CH1_IDX_0_UNION;
#endif
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH1_IDX_0_buck5_vote_vol_ch1_idx_0_START (0)
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH1_IDX_0_buck5_vote_vol_ch1_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_vote_vol_ch1_idx_1 : 32;
    } reg;
} SOC_PMCTRL_BUCK5_VOTE_VOL_CH1_IDX_1_UNION;
#endif
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH1_IDX_1_buck5_vote_vol_ch1_idx_1_START (0)
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH1_IDX_1_buck5_vote_vol_ch1_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_vote_vol_ch2_idx_0 : 32;
    } reg;
} SOC_PMCTRL_BUCK5_VOTE_VOL_CH2_IDX_0_UNION;
#endif
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH2_IDX_0_buck5_vote_vol_ch2_idx_0_START (0)
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH2_IDX_0_buck5_vote_vol_ch2_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_vote_vol_ch2_idx_1 : 32;
    } reg;
} SOC_PMCTRL_BUCK5_VOTE_VOL_CH2_IDX_1_UNION;
#endif
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH2_IDX_1_buck5_vote_vol_ch2_idx_1_START (0)
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH2_IDX_1_buck5_vote_vol_ch2_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_vote_vol_ch3_idx_0 : 32;
    } reg;
} SOC_PMCTRL_BUCK5_VOTE_VOL_CH3_IDX_0_UNION;
#endif
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH3_IDX_0_buck5_vote_vol_ch3_idx_0_START (0)
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH3_IDX_0_buck5_vote_vol_ch3_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_vote_vol_ch3_idx_1 : 32;
    } reg;
} SOC_PMCTRL_BUCK5_VOTE_VOL_CH3_IDX_1_UNION;
#endif
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH3_IDX_1_buck5_vote_vol_ch3_idx_1_START (0)
#define SOC_PMCTRL_BUCK5_VOTE_VOL_CH3_IDX_1_buck5_vote_vol_ch3_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_pmu_up_hold_time : 20;
        unsigned int buck5_pmu_up_step_time : 12;
    } reg;
} SOC_PMCTRL_BUCK5_PMU_TRIM_UP_TIME_UNION;
#endif
#define SOC_PMCTRL_BUCK5_PMU_TRIM_UP_TIME_buck5_pmu_up_hold_time_START (0)
#define SOC_PMCTRL_BUCK5_PMU_TRIM_UP_TIME_buck5_pmu_up_hold_time_END (19)
#define SOC_PMCTRL_BUCK5_PMU_TRIM_UP_TIME_buck5_pmu_up_step_time_START (20)
#define SOC_PMCTRL_BUCK5_PMU_TRIM_UP_TIME_buck5_pmu_up_step_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_pmu_dn_hold_time : 20;
        unsigned int buck5_pmu_dn_step_time : 12;
    } reg;
} SOC_PMCTRL_BUCK5_PMU_TRIM_DN_TIME_UNION;
#endif
#define SOC_PMCTRL_BUCK5_PMU_TRIM_DN_TIME_buck5_pmu_dn_hold_time_START (0)
#define SOC_PMCTRL_BUCK5_PMU_TRIM_DN_TIME_buck5_pmu_dn_hold_time_END (19)
#define SOC_PMCTRL_BUCK5_PMU_TRIM_DN_TIME_buck5_pmu_dn_step_time_START (20)
#define SOC_PMCTRL_BUCK5_PMU_TRIM_DN_TIME_buck5_pmu_dn_step_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_pmu_buck_on_time : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_BUCK5_PMU_BUCK_ON_TIME_UNION;
#endif
#define SOC_PMCTRL_BUCK5_PMU_BUCK_ON_TIME_buck5_pmu_buck_on_time_START (0)
#define SOC_PMCTRL_BUCK5_PMU_BUCK_ON_TIME_buck5_pmu_buck_on_time_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_pmu_buck_off_time : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_BUCK5_PMU_BUCK_OFF_TIME_UNION;
#endif
#define SOC_PMCTRL_BUCK5_PMU_BUCK_OFF_TIME_buck5_pmu_buck_off_time_START (0)
#define SOC_PMCTRL_BUCK5_PMU_BUCK_OFF_TIME_buck5_pmu_buck_off_time_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_init_vol_idx_vau : 8;
        unsigned int buck5_init_vol_req_vau : 1;
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 8;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 5;
    } reg;
} SOC_PMCTRL_BUCK5_INIT_VOL_CONFIG0_UNION;
#endif
#define SOC_PMCTRL_BUCK5_INIT_VOL_CONFIG0_buck5_init_vol_idx_vau_START (0)
#define SOC_PMCTRL_BUCK5_INIT_VOL_CONFIG0_buck5_init_vol_idx_vau_END (7)
#define SOC_PMCTRL_BUCK5_INIT_VOL_CONFIG0_buck5_init_vol_req_vau_START (8)
#define SOC_PMCTRL_BUCK5_INIT_VOL_CONFIG0_buck5_init_vol_req_vau_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 8;
        unsigned int reserved_3 : 1;
        unsigned int buck5_sft_buck_vol_idx : 8;
        unsigned int buck5_sft_buck_on_req : 1;
        unsigned int buck5_sft_buck_off_req : 1;
        unsigned int buck5_sft_buck_onoff_req_en : 1;
        unsigned int reserved_4 : 3;
    } reg;
} SOC_PMCTRL_BUCK5_INIT_VOL_CONFIG1_UNION;
#endif
#define SOC_PMCTRL_BUCK5_INIT_VOL_CONFIG1_buck5_sft_buck_vol_idx_START (18)
#define SOC_PMCTRL_BUCK5_INIT_VOL_CONFIG1_buck5_sft_buck_vol_idx_END (25)
#define SOC_PMCTRL_BUCK5_INIT_VOL_CONFIG1_buck5_sft_buck_on_req_START (26)
#define SOC_PMCTRL_BUCK5_INIT_VOL_CONFIG1_buck5_sft_buck_on_req_END (26)
#define SOC_PMCTRL_BUCK5_INIT_VOL_CONFIG1_buck5_sft_buck_off_req_START (27)
#define SOC_PMCTRL_BUCK5_INIT_VOL_CONFIG1_buck5_sft_buck_off_req_END (27)
#define SOC_PMCTRL_BUCK5_INIT_VOL_CONFIG1_buck5_sft_buck_onoff_req_en_START (28)
#define SOC_PMCTRL_BUCK5_INIT_VOL_CONFIG1_buck5_sft_buck_onoff_req_en_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_sft_fix_vol_idx : 8;
        unsigned int buck5_sft_fix_vol : 1;
        unsigned int buck5_sft_fix_vol_req : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_PMCTRL_BUCK5_FIX_VOL_CONFIG_UNION;
#endif
#define SOC_PMCTRL_BUCK5_FIX_VOL_CONFIG_buck5_sft_fix_vol_idx_START (0)
#define SOC_PMCTRL_BUCK5_FIX_VOL_CONFIG_buck5_sft_fix_vol_idx_END (7)
#define SOC_PMCTRL_BUCK5_FIX_VOL_CONFIG_buck5_sft_fix_vol_START (8)
#define SOC_PMCTRL_BUCK5_FIX_VOL_CONFIG_buck5_sft_fix_vol_END (8)
#define SOC_PMCTRL_BUCK5_FIX_VOL_CONFIG_buck5_sft_fix_vol_req_START (9)
#define SOC_PMCTRL_BUCK5_FIX_VOL_CONFIG_buck5_sft_fix_vol_req_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_cur_max_vol : 8;
        unsigned int buck5_nxt_max_vol : 8;
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_PMCTRL_BUCK5_VOL_READ_UNION;
#endif
#define SOC_PMCTRL_BUCK5_VOL_READ_buck5_cur_max_vol_START (0)
#define SOC_PMCTRL_BUCK5_VOL_READ_buck5_cur_max_vol_END (7)
#define SOC_PMCTRL_BUCK5_VOL_READ_buck5_nxt_max_vol_START (8)
#define SOC_PMCTRL_BUCK5_VOL_READ_buck5_nxt_max_vol_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_stat_time_hold : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_BUCK5_STAT_TIME_HOLD_UNION;
#endif
#define SOC_PMCTRL_BUCK5_STAT_TIME_HOLD_buck5_stat_time_hold_START (0)
#define SOC_PMCTRL_BUCK5_STAT_TIME_HOLD_buck5_stat_time_hold_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_vol_chg_flag : 21;
        unsigned int buck5_separate_vset_ven_ctrl_bypass : 1;
        unsigned int buck5_fer_buck_pg_bypass : 1;
        unsigned int buck5_fer_buck_vok_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_PMCTRL_BUCK5_VOL_CHG_FLAG_UNION;
#endif
#define SOC_PMCTRL_BUCK5_VOL_CHG_FLAG_buck5_vol_chg_flag_START (0)
#define SOC_PMCTRL_BUCK5_VOL_CHG_FLAG_buck5_vol_chg_flag_END (20)
#define SOC_PMCTRL_BUCK5_VOL_CHG_FLAG_buck5_separate_vset_ven_ctrl_bypass_START (21)
#define SOC_PMCTRL_BUCK5_VOL_CHG_FLAG_buck5_separate_vset_ven_ctrl_bypass_END (21)
#define SOC_PMCTRL_BUCK5_VOL_CHG_FLAG_buck5_fer_buck_pg_bypass_START (22)
#define SOC_PMCTRL_BUCK5_VOL_CHG_FLAG_buck5_fer_buck_pg_bypass_END (22)
#define SOC_PMCTRL_BUCK5_VOL_CHG_FLAG_buck5_fer_buck_vok_bypass_START (23)
#define SOC_PMCTRL_BUCK5_VOL_CHG_FLAG_buck5_fer_buck_vok_bypass_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_spmi_hold_time : 20;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_PMCTRL_BUCK5_SPM2_HOLD_TIME_UNION;
#endif
#define SOC_PMCTRL_BUCK5_SPM2_HOLD_TIME_buck5_spmi_hold_time_START (0)
#define SOC_PMCTRL_BUCK5_SPM2_HOLD_TIME_buck5_spmi_hold_time_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fer_buck_pgvok_req_buck5 : 1;
        unsigned int fer_buck_pgvok_ack_buck5 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_PMCTRL_BUCK5_FER_REQ_ACK_UNION;
#endif
#define SOC_PMCTRL_BUCK5_FER_REQ_ACK_fer_buck_pgvok_req_buck5_START (0)
#define SOC_PMCTRL_BUCK5_FER_REQ_ACK_fer_buck_pgvok_req_buck5_END (0)
#define SOC_PMCTRL_BUCK5_FER_REQ_ACK_fer_buck_pgvok_ack_buck5_START (1)
#define SOC_PMCTRL_BUCK5_FER_REQ_ACK_fer_buck_pgvok_ack_buck5_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buck5_vol_profile_rank_idx : 8;
        unsigned int reserved_0 : 8;
        unsigned int buck5_dvs_profile_status : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 14;
    } reg;
} SOC_PMCTRL_BUCK5_VOL_DOZE_VOTE_CTRL_UNION;
#endif
#define SOC_PMCTRL_BUCK5_VOL_DOZE_VOTE_CTRL_buck5_vol_profile_rank_idx_START (0)
#define SOC_PMCTRL_BUCK5_VOL_DOZE_VOTE_CTRL_buck5_vol_profile_rank_idx_END (7)
#define SOC_PMCTRL_BUCK5_VOL_DOZE_VOTE_CTRL_buck5_dvs_profile_status_START (16)
#define SOC_PMCTRL_BUCK5_VOL_DOZE_VOTE_CTRL_buck5_dvs_profile_status_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_rank_0 : 3;
        unsigned int vddc_mem_vote_vol_rank_1 : 3;
        unsigned int vddc_mem_vote_vol_rank_2 : 3;
        unsigned int vddc_mem_vote_vol_rank_3 : 3;
        unsigned int vddc_mem_vote_vol_rank_4 : 3;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_0_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_0_vddc_mem_vote_vol_rank_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_0_vddc_mem_vote_vol_rank_0_END (2)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_0_vddc_mem_vote_vol_rank_1_START (3)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_0_vddc_mem_vote_vol_rank_1_END (5)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_0_vddc_mem_vote_vol_rank_2_START (6)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_0_vddc_mem_vote_vol_rank_2_END (8)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_0_vddc_mem_vote_vol_rank_3_START (9)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_0_vddc_mem_vote_vol_rank_3_END (11)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_0_vddc_mem_vote_vol_rank_4_START (12)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_0_vddc_mem_vote_vol_rank_4_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_rank_5 : 3;
        unsigned int vddc_mem_vote_vol_rank_6 : 3;
        unsigned int vddc_mem_vote_vol_rank_7 : 3;
        unsigned int vddc_mem_vote_vol_rank_8 : 3;
        unsigned int vddc_mem_vote_vol_rank_9 : 3;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_1_vddc_mem_vote_vol_rank_5_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_1_vddc_mem_vote_vol_rank_5_END (2)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_1_vddc_mem_vote_vol_rank_6_START (3)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_1_vddc_mem_vote_vol_rank_6_END (5)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_1_vddc_mem_vote_vol_rank_7_START (6)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_1_vddc_mem_vote_vol_rank_7_END (8)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_1_vddc_mem_vote_vol_rank_8_START (9)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_1_vddc_mem_vote_vol_rank_8_END (11)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_1_vddc_mem_vote_vol_rank_9_START (12)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_1_vddc_mem_vote_vol_rank_9_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_rank_10 : 3;
        unsigned int vddc_mem_vote_vol_rank_11 : 3;
        unsigned int vddc_mem_vote_vol_rank_12 : 3;
        unsigned int vddc_mem_vote_vol_rank_13 : 3;
        unsigned int vddc_mem_vote_vol_rank_14 : 3;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_2_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_2_vddc_mem_vote_vol_rank_10_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_2_vddc_mem_vote_vol_rank_10_END (2)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_2_vddc_mem_vote_vol_rank_11_START (3)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_2_vddc_mem_vote_vol_rank_11_END (5)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_2_vddc_mem_vote_vol_rank_12_START (6)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_2_vddc_mem_vote_vol_rank_12_END (8)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_2_vddc_mem_vote_vol_rank_13_START (9)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_2_vddc_mem_vote_vol_rank_13_END (11)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_2_vddc_mem_vote_vol_rank_14_START (12)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_2_vddc_mem_vote_vol_rank_14_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_rank_15 : 3;
        unsigned int vddc_mem_vote_vol_rank_16 : 3;
        unsigned int vddc_mem_vote_vol_rank_17 : 3;
        unsigned int vddc_mem_vote_vol_rank_18 : 3;
        unsigned int vddc_mem_vote_vol_rank_19 : 3;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_3_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_3_vddc_mem_vote_vol_rank_15_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_3_vddc_mem_vote_vol_rank_15_END (2)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_3_vddc_mem_vote_vol_rank_16_START (3)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_3_vddc_mem_vote_vol_rank_16_END (5)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_3_vddc_mem_vote_vol_rank_17_START (6)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_3_vddc_mem_vote_vol_rank_17_END (8)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_3_vddc_mem_vote_vol_rank_18_START (9)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_3_vddc_mem_vote_vol_rank_18_END (11)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_3_vddc_mem_vote_vol_rank_19_START (12)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_3_vddc_mem_vote_vol_rank_19_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_valid_0 : 1;
        unsigned int vddc_mem_vote_vol_valid_1 : 1;
        unsigned int vddc_mem_vote_vol_valid_2 : 1;
        unsigned int vddc_mem_vote_vol_valid_3 : 1;
        unsigned int vddc_mem_vote_vol_valid_4 : 1;
        unsigned int vddc_mem_vote_vol_valid_5 : 1;
        unsigned int vddc_mem_vote_vol_valid_6 : 1;
        unsigned int vddc_mem_vote_vol_valid_7 : 1;
        unsigned int vddc_mem_vote_vol_valid_8 : 1;
        unsigned int vddc_mem_vote_vol_valid_9 : 1;
        unsigned int vddc_mem_vote_vol_valid_10 : 1;
        unsigned int vddc_mem_vote_vol_valid_11 : 1;
        unsigned int vddc_mem_vote_vol_valid_12 : 1;
        unsigned int vddc_mem_vote_vol_valid_13 : 1;
        unsigned int vddc_mem_vote_vol_valid_14 : 1;
        unsigned int vddc_mem_vote_vol_valid_15 : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_0_END (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_1_START (1)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_1_END (1)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_2_START (2)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_2_END (2)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_3_START (3)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_3_END (3)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_4_START (4)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_4_END (4)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_5_START (5)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_5_END (5)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_6_START (6)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_6_END (6)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_7_START (7)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_7_END (7)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_8_START (8)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_8_END (8)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_9_START (9)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_9_END (9)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_10_START (10)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_10_END (10)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_11_START (11)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_11_END (11)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_12_START (12)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_12_END (12)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_13_START (13)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_13_END (13)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_14_START (14)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_14_END (14)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_15_START (15)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_vddc_mem_vote_vol_valid_15_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_sft_chg_0 : 1;
        unsigned int vddc_mem_vote_sft_chg_1 : 1;
        unsigned int vddc_mem_vote_sft_chg_2 : 1;
        unsigned int vddc_mem_vote_sft_chg_3 : 1;
        unsigned int vddc_mem_vote_sft_chg_4 : 1;
        unsigned int vddc_mem_vote_sft_chg_5 : 1;
        unsigned int vddc_mem_vote_sft_chg_6 : 1;
        unsigned int vddc_mem_vote_sft_chg_7 : 1;
        unsigned int vddc_mem_vote_sft_chg_8 : 1;
        unsigned int vddc_mem_vote_sft_chg_9 : 1;
        unsigned int vddc_mem_vote_sft_chg_10 : 1;
        unsigned int vddc_mem_vote_sft_chg_11 : 1;
        unsigned int vddc_mem_vote_sft_chg_12 : 1;
        unsigned int vddc_mem_vote_sft_chg_13 : 1;
        unsigned int vddc_mem_vote_sft_chg_14 : 1;
        unsigned int vddc_mem_vote_sft_chg_15 : 1;
        unsigned int vddc_mem_vote_sft_chg_16 : 1;
        unsigned int vddc_mem_vote_sft_chg_17 : 1;
        unsigned int vddc_mem_vote_sft_chg_18 : 1;
        unsigned int vddc_mem_vote_sft_chg_19 : 1;
        unsigned int vddc_mem_vote_sft_chg_20 : 1;
        unsigned int vddc_mem_vote_sft_chg_21 : 1;
        unsigned int vddc_mem_vote_sft_chg_22 : 1;
        unsigned int vddc_mem_vote_sft_chg_23 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 4;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_0_END (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_1_START (1)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_1_END (1)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_2_START (2)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_2_END (2)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_3_START (3)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_3_END (3)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_4_START (4)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_4_END (4)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_5_START (5)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_5_END (5)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_6_START (6)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_6_END (6)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_7_START (7)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_7_END (7)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_8_START (8)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_8_END (8)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_9_START (9)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_9_END (9)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_10_START (10)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_10_END (10)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_11_START (11)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_11_END (11)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_12_START (12)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_12_END (12)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_13_START (13)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_13_END (13)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_14_START (14)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_14_END (14)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_15_START (15)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_15_END (15)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_16_START (16)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_16_END (16)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_17_START (17)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_17_END (17)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_18_START (18)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_18_END (18)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_19_START (19)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_19_END (19)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_20_START (20)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_20_END (20)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_21_START (21)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_21_END (21)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_22_START (22)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_22_END (22)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_23_START (23)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_vddc_mem_vote_sft_chg_23_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_soft_vol_vote_en_0 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_1 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_2 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_3 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_4 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_5 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_6 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_7 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_8 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_9 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_10 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_11 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_12 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_13 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_14 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_15 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_16 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_17 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_18 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_19 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_20 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_21 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_22 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_23 : 1;
        unsigned int reserved : 8;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_0_END (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_1_START (1)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_1_END (1)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_2_START (2)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_2_END (2)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_3_START (3)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_3_END (3)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_4_START (4)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_4_END (4)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_5_START (5)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_5_END (5)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_6_START (6)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_6_END (6)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_7_START (7)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_7_END (7)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_8_START (8)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_8_END (8)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_9_START (9)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_9_END (9)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_10_START (10)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_10_END (10)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_11_START (11)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_11_END (11)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_12_START (12)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_12_END (12)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_13_START (13)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_13_END (13)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_14_START (14)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_14_END (14)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_15_START (15)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_15_END (15)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_16_START (16)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_16_END (16)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_17_START (17)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_17_END (17)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_18_START (18)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_18_END (18)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_19_START (19)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_19_END (19)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_20_START (20)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_20_END (20)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_21_START (21)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_21_END (21)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_22_START (22)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_22_END (22)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_23_START (23)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_vddc_mem_soft_vol_vote_en_23_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vol_sft_clr_0 : 1;
        unsigned int vddc_mem_vol_sft_clr_1 : 1;
        unsigned int vddc_mem_vol_sft_clr_2 : 1;
        unsigned int vddc_mem_vol_sft_clr_3 : 1;
        unsigned int vddc_mem_vol_sft_clr_4 : 1;
        unsigned int vddc_mem_vol_sft_clr_5 : 1;
        unsigned int vddc_mem_vol_sft_clr_6 : 1;
        unsigned int vddc_mem_vol_sft_clr_7 : 1;
        unsigned int vddc_mem_vol_sft_clr_8 : 1;
        unsigned int vddc_mem_vol_sft_clr_9 : 1;
        unsigned int vddc_mem_vol_sft_clr_10 : 1;
        unsigned int vddc_mem_vol_sft_clr_11 : 1;
        unsigned int vddc_mem_vol_sft_clr_12 : 1;
        unsigned int vddc_mem_vol_sft_clr_13 : 1;
        unsigned int vddc_mem_vol_sft_clr_14 : 1;
        unsigned int vddc_mem_vol_sft_clr_15 : 1;
        unsigned int vddc_mem_vol_sft_clr_16 : 1;
        unsigned int vddc_mem_vol_sft_clr_17 : 1;
        unsigned int vddc_mem_vol_sft_clr_18 : 1;
        unsigned int vddc_mem_vol_sft_clr_19 : 1;
        unsigned int vddc_mem_vol_sft_clr_20 : 1;
        unsigned int vddc_mem_vol_sft_clr_21 : 1;
        unsigned int vddc_mem_vol_sft_clr_22 : 1;
        unsigned int vddc_mem_vol_sft_clr_23 : 1;
        unsigned int reserved : 8;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_0_END (0)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_1_START (1)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_1_END (1)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_2_START (2)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_2_END (2)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_3_START (3)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_3_END (3)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_4_START (4)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_4_END (4)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_5_START (5)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_5_END (5)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_6_START (6)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_6_END (6)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_7_START (7)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_7_END (7)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_8_START (8)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_8_END (8)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_9_START (9)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_9_END (9)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_10_START (10)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_10_END (10)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_11_START (11)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_11_END (11)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_12_START (12)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_12_END (12)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_13_START (13)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_13_END (13)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_14_START (14)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_14_END (14)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_15_START (15)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_15_END (15)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_16_START (16)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_16_END (16)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_17_START (17)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_17_END (17)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_18_START (18)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_18_END (18)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_19_START (19)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_19_END (19)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_20_START (20)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_20_END (20)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_21_START (21)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_21_END (21)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_22_START (22)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_22_END (22)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_23_START (23)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_vddc_mem_vol_sft_clr_23_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vol_stable_0 : 1;
        unsigned int vddc_mem_vol_stable_1 : 1;
        unsigned int vddc_mem_vol_stable_2 : 1;
        unsigned int vddc_mem_vol_stable_3 : 1;
        unsigned int vddc_mem_vol_stable_4 : 1;
        unsigned int vddc_mem_vol_stable_5 : 1;
        unsigned int vddc_mem_vol_stable_6 : 1;
        unsigned int vddc_mem_vol_stable_7 : 1;
        unsigned int vddc_mem_vol_stable_8 : 1;
        unsigned int vddc_mem_vol_stable_9 : 1;
        unsigned int vddc_mem_vol_stable_10 : 1;
        unsigned int vddc_mem_vol_stable_11 : 1;
        unsigned int vddc_mem_vol_stable_12 : 1;
        unsigned int vddc_mem_vol_stable_13 : 1;
        unsigned int vddc_mem_vol_stable_14 : 1;
        unsigned int vddc_mem_vol_stable_15 : 1;
        unsigned int vddc_mem_vol_stable_16 : 1;
        unsigned int vddc_mem_vol_stable_17 : 1;
        unsigned int vddc_mem_vol_stable_18 : 1;
        unsigned int vddc_mem_vol_stable_19 : 1;
        unsigned int vddc_mem_vol_stable_20 : 1;
        unsigned int vddc_mem_vol_stable_21 : 1;
        unsigned int vddc_mem_vol_stable_22 : 1;
        unsigned int vddc_mem_vol_stable_23 : 1;
        unsigned int reserved : 8;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOL_STABLE_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_0_END (0)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_1_START (1)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_1_END (1)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_2_START (2)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_2_END (2)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_3_START (3)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_3_END (3)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_4_START (4)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_4_END (4)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_5_START (5)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_5_END (5)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_6_START (6)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_6_END (6)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_7_START (7)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_7_END (7)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_8_START (8)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_8_END (8)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_9_START (9)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_9_END (9)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_10_START (10)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_10_END (10)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_11_START (11)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_11_END (11)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_12_START (12)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_12_END (12)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_13_START (13)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_13_END (13)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_14_START (14)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_14_END (14)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_15_START (15)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_15_END (15)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_16_START (16)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_16_END (16)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_17_START (17)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_17_END (17)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_18_START (18)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_18_END (18)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_19_START (19)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_19_END (19)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_20_START (20)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_20_END (20)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_21_START (21)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_21_END (21)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_22_START (22)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_22_END (22)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_23_START (23)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_vddc_mem_vol_stable_23_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_intr_lpm3_msk : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_PMCTRL_VDDC_MEM_INTR_LPMCU_MSK_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_INTR_LPMCU_MSK_vddc_mem_intr_lpm3_msk_START (0)
#define SOC_PMCTRL_VDDC_MEM_INTR_LPMCU_MSK_vddc_mem_intr_lpm3_msk_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_pmu_vol_idx_spmi : 8;
        unsigned int vddc_mem_pmu_vol_chg_spmi : 1;
        unsigned int intr_vddc_mem_dvs_stat_pmc2lpm3 : 1;
        unsigned int intr_vddc_mem_dvs_stat_pmc2acpu : 1;
        unsigned int vddc_mem_pmu_vol_ack_spmi : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int vddc_mem_buck_on_off_stable : 1;
        unsigned int reserved_2 : 3;
        unsigned int vddc_mem_buck_ctrl_cur_stat : 3;
        unsigned int reserved_3 : 11;
    } reg;
} SOC_PMCTRL_VDDC_MEM_DVS_OUTPUT_READ_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_DVS_OUTPUT_READ_vddc_mem_pmu_vol_idx_spmi_START (0)
#define SOC_PMCTRL_VDDC_MEM_DVS_OUTPUT_READ_vddc_mem_pmu_vol_idx_spmi_END (7)
#define SOC_PMCTRL_VDDC_MEM_DVS_OUTPUT_READ_vddc_mem_pmu_vol_chg_spmi_START (8)
#define SOC_PMCTRL_VDDC_MEM_DVS_OUTPUT_READ_vddc_mem_pmu_vol_chg_spmi_END (8)
#define SOC_PMCTRL_VDDC_MEM_DVS_OUTPUT_READ_intr_vddc_mem_dvs_stat_pmc2lpm3_START (9)
#define SOC_PMCTRL_VDDC_MEM_DVS_OUTPUT_READ_intr_vddc_mem_dvs_stat_pmc2lpm3_END (9)
#define SOC_PMCTRL_VDDC_MEM_DVS_OUTPUT_READ_intr_vddc_mem_dvs_stat_pmc2acpu_START (10)
#define SOC_PMCTRL_VDDC_MEM_DVS_OUTPUT_READ_intr_vddc_mem_dvs_stat_pmc2acpu_END (10)
#define SOC_PMCTRL_VDDC_MEM_DVS_OUTPUT_READ_vddc_mem_pmu_vol_ack_spmi_START (11)
#define SOC_PMCTRL_VDDC_MEM_DVS_OUTPUT_READ_vddc_mem_pmu_vol_ack_spmi_END (11)
#define SOC_PMCTRL_VDDC_MEM_DVS_OUTPUT_READ_vddc_mem_buck_on_off_stable_START (14)
#define SOC_PMCTRL_VDDC_MEM_DVS_OUTPUT_READ_vddc_mem_buck_on_off_stable_END (14)
#define SOC_PMCTRL_VDDC_MEM_DVS_OUTPUT_READ_vddc_mem_buck_ctrl_cur_stat_START (18)
#define SOC_PMCTRL_VDDC_MEM_DVS_OUTPUT_READ_vddc_mem_buck_ctrl_cur_stat_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_intr_bypass_0 : 1;
        unsigned int vddc_mem_intr_bypass_1 : 1;
        unsigned int vddc_mem_intr_bypass_2 : 1;
        unsigned int vddc_mem_intr_bypass_3 : 1;
        unsigned int vddc_mem_intr_bypass_4 : 1;
        unsigned int vddc_mem_intr_bypass_5 : 1;
        unsigned int vddc_mem_intr_bypass_6 : 1;
        unsigned int vddc_mem_intr_bypass_7 : 1;
        unsigned int vddc_mem_intr_bypass_8 : 1;
        unsigned int vddc_mem_intr_bypass_9 : 1;
        unsigned int vddc_mem_intr_bypass_10 : 1;
        unsigned int vddc_mem_intr_bypass_11 : 1;
        unsigned int vddc_mem_intr_bypass_12 : 1;
        unsigned int vddc_mem_intr_bypass_13 : 1;
        unsigned int vddc_mem_intr_bypass_14 : 1;
        unsigned int vddc_mem_intr_bypass_15 : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_0_END (0)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_1_START (1)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_1_END (1)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_2_START (2)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_2_END (2)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_3_START (3)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_3_END (3)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_4_START (4)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_4_END (4)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_5_START (5)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_5_END (5)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_6_START (6)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_6_END (6)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_7_START (7)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_7_END (7)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_8_START (8)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_8_END (8)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_9_START (9)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_9_END (9)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_10_START (10)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_10_END (10)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_11_START (11)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_11_END (11)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_12_START (12)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_12_END (12)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_13_START (13)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_13_END (13)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_14_START (14)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_14_END (14)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_15_START (15)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_vddc_mem_intr_bypass_15_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_intr_bypass_16 : 1;
        unsigned int vddc_mem_intr_bypass_17 : 1;
        unsigned int vddc_mem_intr_bypass_18 : 1;
        unsigned int vddc_mem_intr_bypass_19 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 3;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 16;
    } reg;
} SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_HRD_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_HRD_vddc_mem_intr_bypass_16_START (0)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_HRD_vddc_mem_intr_bypass_16_END (0)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_HRD_vddc_mem_intr_bypass_17_START (1)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_HRD_vddc_mem_intr_bypass_17_END (1)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_HRD_vddc_mem_intr_bypass_18_START (2)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_HRD_vddc_mem_intr_bypass_18_END (2)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_HRD_vddc_mem_intr_bypass_19_START (3)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_HRD_vddc_mem_intr_bypass_19_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_dvs_spmi_hold_timeout_flag : 1;
        unsigned int vddc_mem_dvs_buck_onoff_timeout_flag : 1;
        unsigned int vddc_mem_dvs_fer_err_flag : 1;
        unsigned int vddc_mem_dvs_timeout_flag_clr : 1;
        unsigned int vddc_mem_vau_vol_equal_flag_vau_0 : 1;
        unsigned int vddc_mem_vau_vol_equal_flag_clr_vau_0 : 1;
        unsigned int vddc_mem_vau_vol_equal_flag_vau_1 : 1;
        unsigned int vddc_mem_vau_vol_equal_flag_clr_vau_1 : 1;
        unsigned int vddc_mem_vau_vol_equal_flag_vau_2 : 1;
        unsigned int vddc_mem_vau_vol_equal_flag_clr_vau_2 : 1;
        unsigned int vddc_mem_vau_vol_equal_flag_vau_3 : 1;
        unsigned int vddc_mem_vau_vol_equal_flag_clr_vau_3 : 1;
        unsigned int vddc_mem_vau_vol_equal_flag_vau0to3 : 1;
        unsigned int vddc_mem_vau_vol_equal_flag_clr_vau0to3 : 1;
        unsigned int vddc_mem_vau_cur_stat_vau_0 : 3;
        unsigned int vddc_mem_vau_cur_stat_vau_1 : 3;
        unsigned int vddc_mem_vau_cur_stat_vau_2 : 3;
        unsigned int vddc_mem_vau_cur_stat_vau_3 : 3;
        unsigned int vddc_mem_vau_cur_stat_vau0to3 : 3;
        unsigned int reserved : 3;
    } reg;
} SOC_PMCTRL_VDDC_MEM_DVS_STAT0_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_dvs_spmi_hold_timeout_flag_START (0)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_dvs_spmi_hold_timeout_flag_END (0)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_dvs_buck_onoff_timeout_flag_START (1)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_dvs_buck_onoff_timeout_flag_END (1)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_dvs_fer_err_flag_START (2)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_dvs_fer_err_flag_END (2)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_dvs_timeout_flag_clr_START (3)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_dvs_timeout_flag_clr_END (3)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_vol_equal_flag_vau_0_START (4)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_vol_equal_flag_vau_0_END (4)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_vol_equal_flag_clr_vau_0_START (5)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_vol_equal_flag_clr_vau_0_END (5)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_vol_equal_flag_vau_1_START (6)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_vol_equal_flag_vau_1_END (6)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_vol_equal_flag_clr_vau_1_START (7)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_vol_equal_flag_clr_vau_1_END (7)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_vol_equal_flag_vau_2_START (8)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_vol_equal_flag_vau_2_END (8)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_vol_equal_flag_clr_vau_2_START (9)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_vol_equal_flag_clr_vau_2_END (9)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_vol_equal_flag_vau_3_START (10)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_vol_equal_flag_vau_3_END (10)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_vol_equal_flag_clr_vau_3_START (11)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_vol_equal_flag_clr_vau_3_END (11)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_vol_equal_flag_vau0to3_START (12)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_vol_equal_flag_vau0to3_END (12)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_vol_equal_flag_clr_vau0to3_START (13)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_vol_equal_flag_clr_vau0to3_END (13)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_cur_stat_vau_0_START (14)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_cur_stat_vau_0_END (16)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_cur_stat_vau_1_START (17)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_cur_stat_vau_1_END (19)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_cur_stat_vau_2_START (20)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_cur_stat_vau_2_END (22)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_cur_stat_vau_3_START (23)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_cur_stat_vau_3_END (25)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_cur_stat_vau0to3_START (26)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT0_vddc_mem_vau_cur_stat_vau0to3_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_cur_max_vol_vau_0 : 8;
        unsigned int vddc_mem_nxt_max_vol_vau_0 : 8;
        unsigned int vddc_mem_cur_max_vol_vau_1 : 8;
        unsigned int vddc_mem_nxt_max_vol_vau_1 : 8;
    } reg;
} SOC_PMCTRL_VDDC_MEM_DVS_STAT1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT1_vddc_mem_cur_max_vol_vau_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT1_vddc_mem_cur_max_vol_vau_0_END (7)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT1_vddc_mem_nxt_max_vol_vau_0_START (8)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT1_vddc_mem_nxt_max_vol_vau_0_END (15)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT1_vddc_mem_cur_max_vol_vau_1_START (16)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT1_vddc_mem_cur_max_vol_vau_1_END (23)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT1_vddc_mem_nxt_max_vol_vau_1_START (24)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT1_vddc_mem_nxt_max_vol_vau_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_cur_max_vol_vau_2 : 8;
        unsigned int vddc_mem_nxt_max_vol_vau_2 : 8;
        unsigned int vddc_mem_cur_max_vol_vau_3 : 8;
        unsigned int vddc_mem_nxt_max_vol_vau_3 : 8;
    } reg;
} SOC_PMCTRL_VDDC_MEM_DVS_STAT2_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT2_vddc_mem_cur_max_vol_vau_2_START (0)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT2_vddc_mem_cur_max_vol_vau_2_END (7)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT2_vddc_mem_nxt_max_vol_vau_2_START (8)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT2_vddc_mem_nxt_max_vol_vau_2_END (15)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT2_vddc_mem_cur_max_vol_vau_3_START (16)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT2_vddc_mem_cur_max_vol_vau_3_END (23)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT2_vddc_mem_nxt_max_vol_vau_3_START (24)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT2_vddc_mem_nxt_max_vol_vau_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_buck_ctrl_cur_vol_idx : 8;
        unsigned int vddc_mem_buck_ctrl_nxt_vol_idx : 8;
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_PMCTRL_VDDC_MEM_DVS_STAT3_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT3_vddc_mem_buck_ctrl_cur_vol_idx_START (0)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT3_vddc_mem_buck_ctrl_cur_vol_idx_END (7)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT3_vddc_mem_buck_ctrl_nxt_vol_idx_START (8)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT3_vddc_mem_buck_ctrl_nxt_vol_idx_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_valid_vol_vote_idx_0_vau_0 : 8;
        unsigned int vddc_mem_valid_vol_vote_idx_1_vau_0 : 8;
        unsigned int vddc_mem_valid_vol_vote_idx_2_vau_0 : 8;
        unsigned int vddc_mem_valid_vol_vote_idx_3_vau_0 : 8;
    } reg;
} SOC_PMCTRL_VDDC_MEM_DVS_STAT4_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT4_vddc_mem_valid_vol_vote_idx_0_vau_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT4_vddc_mem_valid_vol_vote_idx_0_vau_0_END (7)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT4_vddc_mem_valid_vol_vote_idx_1_vau_0_START (8)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT4_vddc_mem_valid_vol_vote_idx_1_vau_0_END (15)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT4_vddc_mem_valid_vol_vote_idx_2_vau_0_START (16)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT4_vddc_mem_valid_vol_vote_idx_2_vau_0_END (23)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT4_vddc_mem_valid_vol_vote_idx_3_vau_0_START (24)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT4_vddc_mem_valid_vol_vote_idx_3_vau_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_valid_vol_vote_idx_4_vau_1 : 8;
        unsigned int vddc_mem_valid_vol_vote_idx_5_vau_1 : 8;
        unsigned int vddc_mem_valid_vol_vote_idx_6_vau_1 : 8;
        unsigned int vddc_mem_valid_vol_vote_idx_7_vau_1 : 8;
    } reg;
} SOC_PMCTRL_VDDC_MEM_DVS_STAT5_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT5_vddc_mem_valid_vol_vote_idx_4_vau_1_START (0)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT5_vddc_mem_valid_vol_vote_idx_4_vau_1_END (7)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT5_vddc_mem_valid_vol_vote_idx_5_vau_1_START (8)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT5_vddc_mem_valid_vol_vote_idx_5_vau_1_END (15)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT5_vddc_mem_valid_vol_vote_idx_6_vau_1_START (16)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT5_vddc_mem_valid_vol_vote_idx_6_vau_1_END (23)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT5_vddc_mem_valid_vol_vote_idx_7_vau_1_START (24)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT5_vddc_mem_valid_vol_vote_idx_7_vau_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_valid_vol_vote_idx_8_vau_2 : 8;
        unsigned int vddc_mem_valid_vol_vote_idx_9_vau_2 : 8;
        unsigned int vddc_mem_valid_vol_vote_idx_10_vau_2 : 8;
        unsigned int vddc_mem_valid_vol_vote_idx_11_vau_2 : 8;
    } reg;
} SOC_PMCTRL_VDDC_MEM_DVS_STAT6_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT6_vddc_mem_valid_vol_vote_idx_8_vau_2_START (0)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT6_vddc_mem_valid_vol_vote_idx_8_vau_2_END (7)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT6_vddc_mem_valid_vol_vote_idx_9_vau_2_START (8)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT6_vddc_mem_valid_vol_vote_idx_9_vau_2_END (15)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT6_vddc_mem_valid_vol_vote_idx_10_vau_2_START (16)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT6_vddc_mem_valid_vol_vote_idx_10_vau_2_END (23)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT6_vddc_mem_valid_vol_vote_idx_11_vau_2_START (24)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT6_vddc_mem_valid_vol_vote_idx_11_vau_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_valid_vol_vote_idx_12_vau_3 : 8;
        unsigned int vddc_mem_valid_vol_vote_idx_13_vau_3 : 8;
        unsigned int vddc_mem_valid_vol_vote_idx_14_vau_3 : 8;
        unsigned int vddc_mem_valid_vol_vote_idx_15_vau_3 : 8;
    } reg;
} SOC_PMCTRL_VDDC_MEM_DVS_STAT7_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT7_vddc_mem_valid_vol_vote_idx_12_vau_3_START (0)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT7_vddc_mem_valid_vol_vote_idx_12_vau_3_END (7)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT7_vddc_mem_valid_vol_vote_idx_13_vau_3_START (8)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT7_vddc_mem_valid_vol_vote_idx_13_vau_3_END (15)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT7_vddc_mem_valid_vol_vote_idx_14_vau_3_START (16)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT7_vddc_mem_valid_vol_vote_idx_14_vau_3_END (23)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT7_vddc_mem_valid_vol_vote_idx_15_vau_3_START (24)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT7_vddc_mem_valid_vol_vote_idx_15_vau_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_valid_vol_vote_idx_0_vau0to3 : 8;
        unsigned int vddc_mem_valid_vol_vote_idx_1_vau0to3 : 8;
        unsigned int vddc_mem_valid_vol_vote_idx_2_vau0to3 : 8;
        unsigned int vddc_mem_valid_vol_vote_idx_3_vau0to3 : 8;
    } reg;
} SOC_PMCTRL_VDDC_MEM_DVS_STAT8_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT8_vddc_mem_valid_vol_vote_idx_0_vau0to3_START (0)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT8_vddc_mem_valid_vol_vote_idx_0_vau0to3_END (7)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT8_vddc_mem_valid_vol_vote_idx_1_vau0to3_START (8)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT8_vddc_mem_valid_vol_vote_idx_1_vau0to3_END (15)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT8_vddc_mem_valid_vol_vote_idx_2_vau0to3_START (16)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT8_vddc_mem_valid_vol_vote_idx_2_vau0to3_END (23)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT8_vddc_mem_valid_vol_vote_idx_3_vau0to3_START (24)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT8_vddc_mem_valid_vol_vote_idx_3_vau0to3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_intr_xpu_lp_ctrl_msk : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_PMCTRL_VDDC_MEM_INTR_XPU_LP_CTRL_MSK_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_INTR_XPU_LP_CTRL_MSK_vddc_mem_intr_xpu_lp_ctrl_msk_START (0)
#define SOC_PMCTRL_VDDC_MEM_INTR_XPU_LP_CTRL_MSK_vddc_mem_intr_xpu_lp_ctrl_msk_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_rank_20 : 3;
        unsigned int vddc_mem_vote_vol_rank_21 : 3;
        unsigned int vddc_mem_vote_vol_rank_22 : 3;
        unsigned int vddc_mem_vote_vol_rank_23 : 3;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_4_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_4_vddc_mem_vote_vol_rank_20_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_4_vddc_mem_vote_vol_rank_20_END (2)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_4_vddc_mem_vote_vol_rank_21_START (3)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_4_vddc_mem_vote_vol_rank_21_END (5)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_4_vddc_mem_vote_vol_rank_22_START (6)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_4_vddc_mem_vote_vol_rank_22_END (8)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_4_vddc_mem_vote_vol_rank_23_START (9)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_RANK_SFT_4_vddc_mem_vote_vol_rank_23_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_valid_16 : 1;
        unsigned int vddc_mem_vote_vol_valid_17 : 1;
        unsigned int vddc_mem_vote_vol_valid_18 : 1;
        unsigned int vddc_mem_vote_vol_valid_19 : 1;
        unsigned int vddc_mem_vote_vol_valid_20 : 1;
        unsigned int vddc_mem_vote_vol_valid_21 : 1;
        unsigned int vddc_mem_vote_vol_valid_22 : 1;
        unsigned int vddc_mem_vote_vol_valid_23 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 16;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_1_vddc_mem_vote_vol_valid_16_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_1_vddc_mem_vote_vol_valid_16_END (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_1_vddc_mem_vote_vol_valid_17_START (1)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_1_vddc_mem_vote_vol_valid_17_END (1)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_1_vddc_mem_vote_vol_valid_18_START (2)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_1_vddc_mem_vote_vol_valid_18_END (2)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_1_vddc_mem_vote_vol_valid_19_START (3)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_1_vddc_mem_vote_vol_valid_19_END (3)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_1_vddc_mem_vote_vol_valid_20_START (4)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_1_vddc_mem_vote_vol_valid_20_END (4)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_1_vddc_mem_vote_vol_valid_21_START (5)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_1_vddc_mem_vote_vol_valid_21_END (5)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_1_vddc_mem_vote_vol_valid_22_START (6)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_1_vddc_mem_vote_vol_valid_22_END (6)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_1_vddc_mem_vote_vol_valid_23_START (7)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_VALID_1_vddc_mem_vote_vol_valid_23_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_intr_bypass_16 : 1;
        unsigned int vddc_mem_intr_bypass_17 : 1;
        unsigned int vddc_mem_intr_bypass_18 : 1;
        unsigned int vddc_mem_intr_bypass_19 : 1;
        unsigned int vddc_mem_intr_bypass_20 : 1;
        unsigned int vddc_mem_intr_bypass_21 : 1;
        unsigned int vddc_mem_intr_bypass_22 : 1;
        unsigned int vddc_mem_intr_bypass_23 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 16;
    } reg;
} SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_1_vddc_mem_intr_bypass_16_START (0)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_1_vddc_mem_intr_bypass_16_END (0)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_1_vddc_mem_intr_bypass_17_START (1)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_1_vddc_mem_intr_bypass_17_END (1)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_1_vddc_mem_intr_bypass_18_START (2)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_1_vddc_mem_intr_bypass_18_END (2)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_1_vddc_mem_intr_bypass_19_START (3)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_1_vddc_mem_intr_bypass_19_END (3)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_1_vddc_mem_intr_bypass_20_START (4)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_1_vddc_mem_intr_bypass_20_END (4)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_1_vddc_mem_intr_bypass_21_START (5)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_1_vddc_mem_intr_bypass_21_END (5)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_1_vddc_mem_intr_bypass_22_START (6)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_1_vddc_mem_intr_bypass_22_END (6)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_1_vddc_mem_intr_bypass_23_START (7)
#define SOC_PMCTRL_VDDC_MEM_INTR_BYPASS_SFT_1_vddc_mem_intr_bypass_23_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_intr_acpu_msk : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_PMCTRL_VDDC_MEM_INTR_ACPU_MSK_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_INTR_ACPU_MSK_vddc_mem_intr_acpu_msk_START (0)
#define SOC_PMCTRL_VDDC_MEM_INTR_ACPU_MSK_vddc_mem_intr_acpu_msk_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_sft_chg_0_vau0to3 : 1;
        unsigned int vddc_mem_vote_sft_chg_1_vau0to3 : 1;
        unsigned int vddc_mem_vote_sft_chg_2_vau0to3 : 1;
        unsigned int vddc_mem_vote_sft_chg_3_vau0to3 : 1;
        unsigned int vddc_mem_vote_sft_chg_0_vau4to7 : 1;
        unsigned int vddc_mem_vote_sft_chg_1_vau4to7 : 1;
        unsigned int vddc_mem_vote_sft_chg_2_vau4to7 : 1;
        unsigned int vddc_mem_vote_sft_chg_3_vau4to7 : 1;
        unsigned int vddc_mem_vote_sft_chg_0_vau0to7 : 1;
        unsigned int vddc_mem_vote_sft_chg_1_vau0to7 : 1;
        unsigned int vddc_mem_vote_sft_chg_2_vau0to7 : 1;
        unsigned int vddc_mem_vote_sft_chg_3_vau0to7 : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_1_vddc_mem_vote_sft_chg_0_vau0to3_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_1_vddc_mem_vote_sft_chg_0_vau0to3_END (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_1_vddc_mem_vote_sft_chg_1_vau0to3_START (1)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_1_vddc_mem_vote_sft_chg_1_vau0to3_END (1)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_1_vddc_mem_vote_sft_chg_2_vau0to3_START (2)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_1_vddc_mem_vote_sft_chg_2_vau0to3_END (2)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_1_vddc_mem_vote_sft_chg_3_vau0to3_START (3)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_1_vddc_mem_vote_sft_chg_3_vau0to3_END (3)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_1_vddc_mem_vote_sft_chg_0_vau4to7_START (4)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_1_vddc_mem_vote_sft_chg_0_vau4to7_END (4)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_1_vddc_mem_vote_sft_chg_1_vau4to7_START (5)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_1_vddc_mem_vote_sft_chg_1_vau4to7_END (5)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_1_vddc_mem_vote_sft_chg_2_vau4to7_START (6)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_1_vddc_mem_vote_sft_chg_2_vau4to7_END (6)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_1_vddc_mem_vote_sft_chg_3_vau4to7_START (7)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_1_vddc_mem_vote_sft_chg_3_vau4to7_END (7)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_1_vddc_mem_vote_sft_chg_0_vau0to7_START (8)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_1_vddc_mem_vote_sft_chg_0_vau0to7_END (8)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_1_vddc_mem_vote_sft_chg_1_vau0to7_START (9)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_1_vddc_mem_vote_sft_chg_1_vau0to7_END (9)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_1_vddc_mem_vote_sft_chg_2_vau0to7_START (10)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_1_vddc_mem_vote_sft_chg_2_vau0to7_END (10)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_1_vddc_mem_vote_sft_chg_3_vau0to7_START (11)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_1_vddc_mem_vote_sft_chg_3_vau0to7_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_soft_vol_vote_en_0_vau0to3 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_1_vau0to3 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_2_vau0to3 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_3_vau0to3 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_0_vau4to7 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_1_vau4to7 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_2_vau4to7 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_3_vau4to7 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_0_vau0to7 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_1_vau0to7 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_2_vau0to7 : 1;
        unsigned int vddc_mem_soft_vol_vote_en_3_vau0to7 : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_1_vddc_mem_soft_vol_vote_en_0_vau0to3_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_1_vddc_mem_soft_vol_vote_en_0_vau0to3_END (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_1_vddc_mem_soft_vol_vote_en_1_vau0to3_START (1)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_1_vddc_mem_soft_vol_vote_en_1_vau0to3_END (1)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_1_vddc_mem_soft_vol_vote_en_2_vau0to3_START (2)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_1_vddc_mem_soft_vol_vote_en_2_vau0to3_END (2)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_1_vddc_mem_soft_vol_vote_en_3_vau0to3_START (3)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_1_vddc_mem_soft_vol_vote_en_3_vau0to3_END (3)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_1_vddc_mem_soft_vol_vote_en_0_vau4to7_START (4)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_1_vddc_mem_soft_vol_vote_en_0_vau4to7_END (4)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_1_vddc_mem_soft_vol_vote_en_1_vau4to7_START (5)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_1_vddc_mem_soft_vol_vote_en_1_vau4to7_END (5)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_1_vddc_mem_soft_vol_vote_en_2_vau4to7_START (6)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_1_vddc_mem_soft_vol_vote_en_2_vau4to7_END (6)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_1_vddc_mem_soft_vol_vote_en_3_vau4to7_START (7)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_1_vddc_mem_soft_vol_vote_en_3_vau4to7_END (7)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_1_vddc_mem_soft_vol_vote_en_0_vau0to7_START (8)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_1_vddc_mem_soft_vol_vote_en_0_vau0to7_END (8)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_1_vddc_mem_soft_vol_vote_en_1_vau0to7_START (9)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_1_vddc_mem_soft_vol_vote_en_1_vau0to7_END (9)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_1_vddc_mem_soft_vol_vote_en_2_vau0to7_START (10)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_1_vddc_mem_soft_vol_vote_en_2_vau0to7_END (10)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_1_vddc_mem_soft_vol_vote_en_3_vau0to7_START (11)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_CHG_BYPASS_1_vddc_mem_soft_vol_vote_en_3_vau0to7_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vol_sft_clr_0_vau0to3 : 1;
        unsigned int vddc_mem_vol_sft_clr_1_vau0to3 : 1;
        unsigned int vddc_mem_vol_sft_clr_2_vau0to3 : 1;
        unsigned int vddc_mem_vol_sft_clr_3_vau0to3 : 1;
        unsigned int vddc_mem_vol_sft_clr_0_vau4to7 : 1;
        unsigned int vddc_mem_vol_sft_clr_1_vau4to7 : 1;
        unsigned int vddc_mem_vol_sft_clr_2_vau4to7 : 1;
        unsigned int vddc_mem_vol_sft_clr_3_vau4to7 : 1;
        unsigned int vddc_mem_vol_sft_clr_0_vau0to7 : 1;
        unsigned int vddc_mem_vol_sft_clr_1_vau0to7 : 1;
        unsigned int vddc_mem_vol_sft_clr_2_vau0to7 : 1;
        unsigned int vddc_mem_vol_sft_clr_3_vau0to7 : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_1_vddc_mem_vol_sft_clr_0_vau0to3_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_1_vddc_mem_vol_sft_clr_0_vau0to3_END (0)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_1_vddc_mem_vol_sft_clr_1_vau0to3_START (1)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_1_vddc_mem_vol_sft_clr_1_vau0to3_END (1)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_1_vddc_mem_vol_sft_clr_2_vau0to3_START (2)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_1_vddc_mem_vol_sft_clr_2_vau0to3_END (2)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_1_vddc_mem_vol_sft_clr_3_vau0to3_START (3)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_1_vddc_mem_vol_sft_clr_3_vau0to3_END (3)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_1_vddc_mem_vol_sft_clr_0_vau4to7_START (4)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_1_vddc_mem_vol_sft_clr_0_vau4to7_END (4)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_1_vddc_mem_vol_sft_clr_1_vau4to7_START (5)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_1_vddc_mem_vol_sft_clr_1_vau4to7_END (5)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_1_vddc_mem_vol_sft_clr_2_vau4to7_START (6)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_1_vddc_mem_vol_sft_clr_2_vau4to7_END (6)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_1_vddc_mem_vol_sft_clr_3_vau4to7_START (7)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_1_vddc_mem_vol_sft_clr_3_vau4to7_END (7)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_1_vddc_mem_vol_sft_clr_0_vau0to7_START (8)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_1_vddc_mem_vol_sft_clr_0_vau0to7_END (8)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_1_vddc_mem_vol_sft_clr_1_vau0to7_START (9)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_1_vddc_mem_vol_sft_clr_1_vau0to7_END (9)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_1_vddc_mem_vol_sft_clr_2_vau0to7_START (10)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_1_vddc_mem_vol_sft_clr_2_vau0to7_END (10)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_1_vddc_mem_vol_sft_clr_3_vau0to7_START (11)
#define SOC_PMCTRL_VDDC_MEM_VOL_SFT_CLR_1_vddc_mem_vol_sft_clr_3_vau0to7_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vol_stable_vau0 : 1;
        unsigned int vddc_mem_vol_stable_vau1 : 1;
        unsigned int vddc_mem_vol_stable_vau2 : 1;
        unsigned int vddc_mem_vol_stable_vau3 : 1;
        unsigned int vddc_mem_vol_stable_vau4 : 1;
        unsigned int vddc_mem_vol_stable_vau5 : 1;
        unsigned int vddc_mem_vol_stable_vau0to3 : 1;
        unsigned int vddc_mem_vol_stable_vau4to7 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOL_STABLE_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_1_vddc_mem_vol_stable_vau0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_1_vddc_mem_vol_stable_vau0_END (0)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_1_vddc_mem_vol_stable_vau1_START (1)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_1_vddc_mem_vol_stable_vau1_END (1)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_1_vddc_mem_vol_stable_vau2_START (2)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_1_vddc_mem_vol_stable_vau2_END (2)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_1_vddc_mem_vol_stable_vau3_START (3)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_1_vddc_mem_vol_stable_vau3_END (3)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_1_vddc_mem_vol_stable_vau4_START (4)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_1_vddc_mem_vol_stable_vau4_END (4)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_1_vddc_mem_vol_stable_vau5_START (5)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_1_vddc_mem_vol_stable_vau5_END (5)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_1_vddc_mem_vol_stable_vau0to3_START (6)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_1_vddc_mem_vol_stable_vau0to3_END (6)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_1_vddc_mem_vol_stable_vau4to7_START (7)
#define SOC_PMCTRL_VDDC_MEM_VOL_STABLE_1_vddc_mem_vol_stable_vau4to7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_cur_max_vol_vau_4 : 8;
        unsigned int vddc_mem_nxt_max_vol_vau_4 : 8;
        unsigned int vddc_mem_cur_max_vol_vau_5 : 8;
        unsigned int vddc_mem_nxt_max_vol_vau_5 : 8;
    } reg;
} SOC_PMCTRL_VDDC_MEM_DVS_STAT9_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT9_vddc_mem_cur_max_vol_vau_4_START (0)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT9_vddc_mem_cur_max_vol_vau_4_END (7)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT9_vddc_mem_nxt_max_vol_vau_4_START (8)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT9_vddc_mem_nxt_max_vol_vau_4_END (15)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT9_vddc_mem_cur_max_vol_vau_5_START (16)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT9_vddc_mem_cur_max_vol_vau_5_END (23)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT9_vddc_mem_nxt_max_vol_vau_5_START (24)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT9_vddc_mem_nxt_max_vol_vau_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_cur_max_vol_vau0to3 : 8;
        unsigned int vddc_mem_nxt_max_vol_vau0to3 : 8;
        unsigned int vddc_mem_cur_max_vol_vau4to7 : 8;
        unsigned int vddc_mem_nxt_max_vol_vau4to7 : 8;
    } reg;
} SOC_PMCTRL_VDDC_MEM_DVS_STAT10_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT10_vddc_mem_cur_max_vol_vau0to3_START (0)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT10_vddc_mem_cur_max_vol_vau0to3_END (7)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT10_vddc_mem_nxt_max_vol_vau0to3_START (8)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT10_vddc_mem_nxt_max_vol_vau0to3_END (15)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT10_vddc_mem_cur_max_vol_vau4to7_START (16)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT10_vddc_mem_cur_max_vol_vau4to7_END (23)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT10_vddc_mem_nxt_max_vol_vau4to7_START (24)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT10_vddc_mem_nxt_max_vol_vau4to7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_cur_max_vol_vau0to7 : 8;
        unsigned int vddc_mem_nxt_max_vol_vau0to7 : 8;
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_PMCTRL_VDDC_MEM_DVS_STAT11_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT11_vddc_mem_cur_max_vol_vau0to7_START (0)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT11_vddc_mem_cur_max_vol_vau0to7_END (7)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT11_vddc_mem_nxt_max_vol_vau0to7_START (8)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT11_vddc_mem_nxt_max_vol_vau0to7_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_valid_vol_vote_idx_0_vau4to7 : 8;
        unsigned int vddc_mem_valid_vol_vote_idx_1_vau4to7 : 8;
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_PMCTRL_VDDC_MEM_DVS_STAT12_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT12_vddc_mem_valid_vol_vote_idx_0_vau4to7_START (0)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT12_vddc_mem_valid_vol_vote_idx_0_vau4to7_END (7)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT12_vddc_mem_valid_vol_vote_idx_1_vau4to7_START (8)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT12_vddc_mem_valid_vol_vote_idx_1_vau4to7_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_valid_vol_vote_idx_0_vau0to7 : 8;
        unsigned int vddc_mem_valid_vol_vote_idx_1_vau0to7 : 8;
        unsigned int vddc_mem_valid_vol_vote_idx_2_vau0to7 : 8;
        unsigned int vddc_mem_valid_vol_vote_idx_3_vau0to7 : 8;
    } reg;
} SOC_PMCTRL_VDDC_MEM_DVS_STAT13_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT13_vddc_mem_valid_vol_vote_idx_0_vau0to7_START (0)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT13_vddc_mem_valid_vol_vote_idx_0_vau0to7_END (7)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT13_vddc_mem_valid_vol_vote_idx_1_vau0to7_START (8)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT13_vddc_mem_valid_vol_vote_idx_1_vau0to7_END (15)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT13_vddc_mem_valid_vol_vote_idx_2_vau0to7_START (16)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT13_vddc_mem_valid_vol_vote_idx_2_vau0to7_END (23)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT13_vddc_mem_valid_vol_vote_idx_3_vau0to7_START (24)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT13_vddc_mem_valid_vol_vote_idx_3_vau0to7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vau_vol_equal_flag_vau_4 : 1;
        unsigned int vddc_mem_vau_vol_equal_flag_clr_vau_4 : 1;
        unsigned int vddc_mem_vau_vol_equal_flag_vau_5 : 1;
        unsigned int vddc_mem_vau_vol_equal_flag_clr_vau_5 : 1;
        unsigned int vddc_mem_vau_vol_equal_flag_vau4to7 : 1;
        unsigned int vddc_mem_vau_vol_equal_flag_clr_vau4to7 : 1;
        unsigned int vddc_mem_vau_vol_equal_flag_vau0to7 : 1;
        unsigned int vddc_mem_vau_vol_equal_flag_clr_vau0to7 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int vddc_mem_vau_cur_stat_vau_4 : 3;
        unsigned int vddc_mem_vau_cur_stat_vau_5 : 3;
        unsigned int vddc_mem_vau_cur_stat_vau4to7 : 3;
        unsigned int vddc_mem_vau_cur_stat_vau0to7 : 3;
        unsigned int reserved_6 : 3;
        unsigned int reserved_7 : 3;
    } reg;
} SOC_PMCTRL_VDDC_MEM_DVS_STAT14_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT14_vddc_mem_vau_vol_equal_flag_vau_4_START (0)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT14_vddc_mem_vau_vol_equal_flag_vau_4_END (0)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT14_vddc_mem_vau_vol_equal_flag_clr_vau_4_START (1)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT14_vddc_mem_vau_vol_equal_flag_clr_vau_4_END (1)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT14_vddc_mem_vau_vol_equal_flag_vau_5_START (2)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT14_vddc_mem_vau_vol_equal_flag_vau_5_END (2)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT14_vddc_mem_vau_vol_equal_flag_clr_vau_5_START (3)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT14_vddc_mem_vau_vol_equal_flag_clr_vau_5_END (3)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT14_vddc_mem_vau_vol_equal_flag_vau4to7_START (4)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT14_vddc_mem_vau_vol_equal_flag_vau4to7_END (4)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT14_vddc_mem_vau_vol_equal_flag_clr_vau4to7_START (5)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT14_vddc_mem_vau_vol_equal_flag_clr_vau4to7_END (5)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT14_vddc_mem_vau_vol_equal_flag_vau0to7_START (6)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT14_vddc_mem_vau_vol_equal_flag_vau0to7_END (6)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT14_vddc_mem_vau_vol_equal_flag_clr_vau0to7_START (7)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT14_vddc_mem_vau_vol_equal_flag_clr_vau0to7_END (7)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT14_vddc_mem_vau_cur_stat_vau_4_START (14)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT14_vddc_mem_vau_cur_stat_vau_4_END (16)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT14_vddc_mem_vau_cur_stat_vau_5_START (17)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT14_vddc_mem_vau_cur_stat_vau_5_END (19)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT14_vddc_mem_vau_cur_stat_vau4to7_START (20)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT14_vddc_mem_vau_cur_stat_vau4to7_END (22)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT14_vddc_mem_vau_cur_stat_vau0to7_START (23)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT14_vddc_mem_vau_cur_stat_vau0to7_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_valid_vol_vote_idx_16_vau_4 : 8;
        unsigned int vddc_mem_valid_vol_vote_idx_17_vau_4 : 8;
        unsigned int vddc_mem_valid_vol_vote_idx_18_vau_4 : 8;
        unsigned int vddc_mem_valid_vol_vote_idx_19_vau_4 : 8;
    } reg;
} SOC_PMCTRL_VDDC_MEM_DVS_STAT15_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT15_vddc_mem_valid_vol_vote_idx_16_vau_4_START (0)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT15_vddc_mem_valid_vol_vote_idx_16_vau_4_END (7)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT15_vddc_mem_valid_vol_vote_idx_17_vau_4_START (8)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT15_vddc_mem_valid_vol_vote_idx_17_vau_4_END (15)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT15_vddc_mem_valid_vol_vote_idx_18_vau_4_START (16)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT15_vddc_mem_valid_vol_vote_idx_18_vau_4_END (23)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT15_vddc_mem_valid_vol_vote_idx_19_vau_4_START (24)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT15_vddc_mem_valid_vol_vote_idx_19_vau_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_valid_vol_vote_idx_20_vau_5 : 8;
        unsigned int vddc_mem_valid_vol_vote_idx_21_vau_5 : 8;
        unsigned int vddc_mem_valid_vol_vote_idx_22_vau_5 : 8;
        unsigned int vddc_mem_valid_vol_vote_idx_23_vau_5 : 8;
    } reg;
} SOC_PMCTRL_VDDC_MEM_DVS_STAT16_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT16_vddc_mem_valid_vol_vote_idx_20_vau_5_START (0)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT16_vddc_mem_valid_vol_vote_idx_20_vau_5_END (7)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT16_vddc_mem_valid_vol_vote_idx_21_vau_5_START (8)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT16_vddc_mem_valid_vol_vote_idx_21_vau_5_END (15)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT16_vddc_mem_valid_vol_vote_idx_22_vau_5_START (16)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT16_vddc_mem_valid_vol_vote_idx_22_vau_5_END (23)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT16_vddc_mem_valid_vol_vote_idx_23_vau_5_START (24)
#define SOC_PMCTRL_VDDC_MEM_DVS_STAT16_vddc_mem_valid_vol_vote_idx_23_vau_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch0_idx_0 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH0_IDX_0_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH0_IDX_0_vddc_mem_vote_vol_ch0_idx_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH0_IDX_0_vddc_mem_vote_vol_ch0_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch0_idx_1 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH0_IDX_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH0_IDX_1_vddc_mem_vote_vol_ch0_idx_1_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH0_IDX_1_vddc_mem_vote_vol_ch0_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch1_idx_0 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH1_IDX_0_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH1_IDX_0_vddc_mem_vote_vol_ch1_idx_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH1_IDX_0_vddc_mem_vote_vol_ch1_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch1_idx_1 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH1_IDX_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH1_IDX_1_vddc_mem_vote_vol_ch1_idx_1_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH1_IDX_1_vddc_mem_vote_vol_ch1_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch2_idx_0 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH2_IDX_0_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH2_IDX_0_vddc_mem_vote_vol_ch2_idx_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH2_IDX_0_vddc_mem_vote_vol_ch2_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch2_idx_1 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH2_IDX_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH2_IDX_1_vddc_mem_vote_vol_ch2_idx_1_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH2_IDX_1_vddc_mem_vote_vol_ch2_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch3_idx_0 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH3_IDX_0_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH3_IDX_0_vddc_mem_vote_vol_ch3_idx_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH3_IDX_0_vddc_mem_vote_vol_ch3_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch3_idx_1 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH3_IDX_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH3_IDX_1_vddc_mem_vote_vol_ch3_idx_1_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH3_IDX_1_vddc_mem_vote_vol_ch3_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch4_idx_0 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH4_IDX_0_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH4_IDX_0_vddc_mem_vote_vol_ch4_idx_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH4_IDX_0_vddc_mem_vote_vol_ch4_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch4_idx_1 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH4_IDX_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH4_IDX_1_vddc_mem_vote_vol_ch4_idx_1_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH4_IDX_1_vddc_mem_vote_vol_ch4_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch5_idx_0 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH5_IDX_0_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH5_IDX_0_vddc_mem_vote_vol_ch5_idx_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH5_IDX_0_vddc_mem_vote_vol_ch5_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch5_idx_1 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH5_IDX_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH5_IDX_1_vddc_mem_vote_vol_ch5_idx_1_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH5_IDX_1_vddc_mem_vote_vol_ch5_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch6_idx_0 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH6_IDX_0_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH6_IDX_0_vddc_mem_vote_vol_ch6_idx_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH6_IDX_0_vddc_mem_vote_vol_ch6_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch6_idx_1 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH6_IDX_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH6_IDX_1_vddc_mem_vote_vol_ch6_idx_1_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH6_IDX_1_vddc_mem_vote_vol_ch6_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch7_idx_0 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH7_IDX_0_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH7_IDX_0_vddc_mem_vote_vol_ch7_idx_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH7_IDX_0_vddc_mem_vote_vol_ch7_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch7_idx_1 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH7_IDX_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH7_IDX_1_vddc_mem_vote_vol_ch7_idx_1_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH7_IDX_1_vddc_mem_vote_vol_ch7_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch8_idx_0 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH8_IDX_0_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH8_IDX_0_vddc_mem_vote_vol_ch8_idx_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH8_IDX_0_vddc_mem_vote_vol_ch8_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch8_idx_1 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH8_IDX_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH8_IDX_1_vddc_mem_vote_vol_ch8_idx_1_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH8_IDX_1_vddc_mem_vote_vol_ch8_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch9_idx_0 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH9_IDX_0_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH9_IDX_0_vddc_mem_vote_vol_ch9_idx_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH9_IDX_0_vddc_mem_vote_vol_ch9_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch9_idx_1 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH9_IDX_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH9_IDX_1_vddc_mem_vote_vol_ch9_idx_1_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH9_IDX_1_vddc_mem_vote_vol_ch9_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch10_idx_0 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH10_IDX_0_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH10_IDX_0_vddc_mem_vote_vol_ch10_idx_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH10_IDX_0_vddc_mem_vote_vol_ch10_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch10_idx_1 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH10_IDX_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH10_IDX_1_vddc_mem_vote_vol_ch10_idx_1_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH10_IDX_1_vddc_mem_vote_vol_ch10_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch11_idx_0 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH11_IDX_0_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH11_IDX_0_vddc_mem_vote_vol_ch11_idx_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH11_IDX_0_vddc_mem_vote_vol_ch11_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch11_idx_1 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH11_IDX_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH11_IDX_1_vddc_mem_vote_vol_ch11_idx_1_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH11_IDX_1_vddc_mem_vote_vol_ch11_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch12_idx_0 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH12_IDX_0_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH12_IDX_0_vddc_mem_vote_vol_ch12_idx_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH12_IDX_0_vddc_mem_vote_vol_ch12_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch12_idx_1 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH12_IDX_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH12_IDX_1_vddc_mem_vote_vol_ch12_idx_1_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH12_IDX_1_vddc_mem_vote_vol_ch12_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch13_idx_0 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH13_IDX_0_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH13_IDX_0_vddc_mem_vote_vol_ch13_idx_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH13_IDX_0_vddc_mem_vote_vol_ch13_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch13_idx_1 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH13_IDX_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH13_IDX_1_vddc_mem_vote_vol_ch13_idx_1_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH13_IDX_1_vddc_mem_vote_vol_ch13_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch14_idx_0 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH14_IDX_0_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH14_IDX_0_vddc_mem_vote_vol_ch14_idx_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH14_IDX_0_vddc_mem_vote_vol_ch14_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch14_idx_1 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH14_IDX_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH14_IDX_1_vddc_mem_vote_vol_ch14_idx_1_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH14_IDX_1_vddc_mem_vote_vol_ch14_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch15_idx_0 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH15_IDX_0_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH15_IDX_0_vddc_mem_vote_vol_ch15_idx_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH15_IDX_0_vddc_mem_vote_vol_ch15_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch15_idx_1 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH15_IDX_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH15_IDX_1_vddc_mem_vote_vol_ch15_idx_1_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH15_IDX_1_vddc_mem_vote_vol_ch15_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_pmu_up_hold_time : 20;
        unsigned int vddc_mem_pmu_up_step_time : 12;
    } reg;
} SOC_PMCTRL_VDDC_MEM_PMU_TRIM_UP_TIME_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_PMU_TRIM_UP_TIME_vddc_mem_pmu_up_hold_time_START (0)
#define SOC_PMCTRL_VDDC_MEM_PMU_TRIM_UP_TIME_vddc_mem_pmu_up_hold_time_END (19)
#define SOC_PMCTRL_VDDC_MEM_PMU_TRIM_UP_TIME_vddc_mem_pmu_up_step_time_START (20)
#define SOC_PMCTRL_VDDC_MEM_PMU_TRIM_UP_TIME_vddc_mem_pmu_up_step_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_pmu_dn_hold_time : 20;
        unsigned int vddc_mem_pmu_dn_step_time : 12;
    } reg;
} SOC_PMCTRL_VDDC_MEM_PMU_TRIM_DN_TTME_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_PMU_TRIM_DN_TTME_vddc_mem_pmu_dn_hold_time_START (0)
#define SOC_PMCTRL_VDDC_MEM_PMU_TRIM_DN_TTME_vddc_mem_pmu_dn_hold_time_END (19)
#define SOC_PMCTRL_VDDC_MEM_PMU_TRIM_DN_TTME_vddc_mem_pmu_dn_step_time_START (20)
#define SOC_PMCTRL_VDDC_MEM_PMU_TRIM_DN_TTME_vddc_mem_pmu_dn_step_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_pmu_buck_on_time : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_VDDC_MEM_PMU_BUCK_ON_TIME_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_PMU_BUCK_ON_TIME_vddc_mem_pmu_buck_on_time_START (0)
#define SOC_PMCTRL_VDDC_MEM_PMU_BUCK_ON_TIME_vddc_mem_pmu_buck_on_time_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_pmu_buck_off_time : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_VDDC_MEM_PMU_BUCK_OFF_TIME_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_PMU_BUCK_OFF_TIME_vddc_mem_pmu_buck_off_time_START (0)
#define SOC_PMCTRL_VDDC_MEM_PMU_BUCK_OFF_TIME_vddc_mem_pmu_buck_off_time_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_init_vol_idx_vau_0 : 8;
        unsigned int vddc_mem_init_vol_req_vau_0 : 1;
        unsigned int vddc_mem_init_vol_idx_vau_1 : 8;
        unsigned int vddc_mem_init_vol_req_vau_1 : 1;
        unsigned int vddc_mem_init_vol_idx_vau_2 : 8;
        unsigned int vddc_mem_init_vol_req_vau_2 : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG0_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG0_vddc_mem_init_vol_idx_vau_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG0_vddc_mem_init_vol_idx_vau_0_END (7)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG0_vddc_mem_init_vol_req_vau_0_START (8)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG0_vddc_mem_init_vol_req_vau_0_END (8)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG0_vddc_mem_init_vol_idx_vau_1_START (9)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG0_vddc_mem_init_vol_idx_vau_1_END (16)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG0_vddc_mem_init_vol_req_vau_1_START (17)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG0_vddc_mem_init_vol_req_vau_1_END (17)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG0_vddc_mem_init_vol_idx_vau_2_START (18)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG0_vddc_mem_init_vol_idx_vau_2_END (25)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG0_vddc_mem_init_vol_req_vau_2_START (26)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG0_vddc_mem_init_vol_req_vau_2_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_init_vol_idx_vau_3 : 8;
        unsigned int vddc_mem_init_vol_req_vau_3 : 1;
        unsigned int vddc_mem_init_vol_idx_vau_4to1 : 8;
        unsigned int vddc_mem_init_vol_req_vau_4to1 : 1;
        unsigned int vddc_mem_sft_buck_vol_idx : 8;
        unsigned int vddc_mem_sft_buck_on_req : 1;
        unsigned int vddc_mem_sft_buck_off_req : 1;
        unsigned int vddc_mem_sft_buck_onoff_req_en : 1;
        unsigned int reserved : 3;
    } reg;
} SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG1_vddc_mem_init_vol_idx_vau_3_START (0)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG1_vddc_mem_init_vol_idx_vau_3_END (7)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG1_vddc_mem_init_vol_req_vau_3_START (8)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG1_vddc_mem_init_vol_req_vau_3_END (8)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG1_vddc_mem_init_vol_idx_vau_4to1_START (9)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG1_vddc_mem_init_vol_idx_vau_4to1_END (16)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG1_vddc_mem_init_vol_req_vau_4to1_START (17)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG1_vddc_mem_init_vol_req_vau_4to1_END (17)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG1_vddc_mem_sft_buck_vol_idx_START (18)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG1_vddc_mem_sft_buck_vol_idx_END (25)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG1_vddc_mem_sft_buck_on_req_START (26)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG1_vddc_mem_sft_buck_on_req_END (26)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG1_vddc_mem_sft_buck_off_req_START (27)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG1_vddc_mem_sft_buck_off_req_END (27)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG1_vddc_mem_sft_buck_onoff_req_en_START (28)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG1_vddc_mem_sft_buck_onoff_req_en_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_sft_fix_vol_idx : 8;
        unsigned int vddc_mem_sft_fix_vol : 1;
        unsigned int vddc_mem_sft_fix_vol_req : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_PMCTRL_VDDC_MEM_FIX_VOL_CONFIG_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_FIX_VOL_CONFIG_vddc_mem_sft_fix_vol_idx_START (0)
#define SOC_PMCTRL_VDDC_MEM_FIX_VOL_CONFIG_vddc_mem_sft_fix_vol_idx_END (7)
#define SOC_PMCTRL_VDDC_MEM_FIX_VOL_CONFIG_vddc_mem_sft_fix_vol_START (8)
#define SOC_PMCTRL_VDDC_MEM_FIX_VOL_CONFIG_vddc_mem_sft_fix_vol_END (8)
#define SOC_PMCTRL_VDDC_MEM_FIX_VOL_CONFIG_vddc_mem_sft_fix_vol_req_START (9)
#define SOC_PMCTRL_VDDC_MEM_FIX_VOL_CONFIG_vddc_mem_sft_fix_vol_req_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_cur_max_vol : 8;
        unsigned int vddc_mem_nxt_max_vol : 8;
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOL_READ_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOL_READ_vddc_mem_cur_max_vol_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOL_READ_vddc_mem_cur_max_vol_END (7)
#define SOC_PMCTRL_VDDC_MEM_VOL_READ_vddc_mem_nxt_max_vol_START (8)
#define SOC_PMCTRL_VDDC_MEM_VOL_READ_vddc_mem_nxt_max_vol_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_sft_vol_idx_0_vau0to3 : 8;
        unsigned int vddc_mem_vote_sft_vol_idx_1_vau0to3 : 8;
        unsigned int vddc_mem_vote_sft_vol_idx_2_vau0to3 : 8;
        unsigned int vddc_mem_vote_sft_vol_idx_3_vau0to3 : 8;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_vddc_mem_vote_sft_vol_idx_0_vau0to3_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_vddc_mem_vote_sft_vol_idx_0_vau0to3_END (7)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_vddc_mem_vote_sft_vol_idx_1_vau0to3_START (8)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_vddc_mem_vote_sft_vol_idx_1_vau0to3_END (15)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_vddc_mem_vote_sft_vol_idx_2_vau0to3_START (16)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_vddc_mem_vote_sft_vol_idx_2_vau0to3_END (23)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_vddc_mem_vote_sft_vol_idx_3_vau0to3_START (24)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_vddc_mem_vote_sft_vol_idx_3_vau0to3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_stat_time_hold : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_VDDC_MEM_STAT_TIME_HOLD_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_STAT_TIME_HOLD_vddc_mem_stat_time_hold_START (0)
#define SOC_PMCTRL_VDDC_MEM_STAT_TIME_HOLD_vddc_mem_stat_time_hold_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vol_chg_flag : 21;
        unsigned int vddc_mem_separate_vset_ven_ctrl_bypass : 1;
        unsigned int vddc_mem_fer_buck_pg_bypass : 1;
        unsigned int vddc_mem_fer_buck_vok_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOL_CHG_FLAG_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOL_CHG_FLAG_vddc_mem_vol_chg_flag_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOL_CHG_FLAG_vddc_mem_vol_chg_flag_END (20)
#define SOC_PMCTRL_VDDC_MEM_VOL_CHG_FLAG_vddc_mem_separate_vset_ven_ctrl_bypass_START (21)
#define SOC_PMCTRL_VDDC_MEM_VOL_CHG_FLAG_vddc_mem_separate_vset_ven_ctrl_bypass_END (21)
#define SOC_PMCTRL_VDDC_MEM_VOL_CHG_FLAG_vddc_mem_fer_buck_pg_bypass_START (22)
#define SOC_PMCTRL_VDDC_MEM_VOL_CHG_FLAG_vddc_mem_fer_buck_pg_bypass_END (22)
#define SOC_PMCTRL_VDDC_MEM_VOL_CHG_FLAG_vddc_mem_fer_buck_vok_bypass_START (23)
#define SOC_PMCTRL_VDDC_MEM_VOL_CHG_FLAG_vddc_mem_fer_buck_vok_bypass_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_spmi_hold_time : 20;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_PMCTRL_VDDC_MEM_SPMI_HOLD_TIME_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_SPMI_HOLD_TIME_vddc_mem_spmi_hold_time_START (0)
#define SOC_PMCTRL_VDDC_MEM_SPMI_HOLD_TIME_vddc_mem_spmi_hold_time_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fer_buck_pgvok_req_vddc_mem : 1;
        unsigned int fer_buck_pgvok_ack_vddc_mem : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_PMCTRL_VDDC_MEM_FER_REQ_ACK_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_FER_REQ_ACK_fer_buck_pgvok_req_vddc_mem_START (0)
#define SOC_PMCTRL_VDDC_MEM_FER_REQ_ACK_fer_buck_pgvok_req_vddc_mem_END (0)
#define SOC_PMCTRL_VDDC_MEM_FER_REQ_ACK_fer_buck_pgvok_ack_vddc_mem_START (1)
#define SOC_PMCTRL_VDDC_MEM_FER_REQ_ACK_fer_buck_pgvok_ack_vddc_mem_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vol_profile_rank_idx : 8;
        unsigned int reserved_0 : 8;
        unsigned int vddc_mem_dvs_profile_status : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 14;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOL_DOZE_VOTE_CTRL_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOL_DOZE_VOTE_CTRL_vddc_mem_vol_profile_rank_idx_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOL_DOZE_VOTE_CTRL_vddc_mem_vol_profile_rank_idx_END (7)
#define SOC_PMCTRL_VDDC_MEM_VOL_DOZE_VOTE_CTRL_vddc_mem_dvs_profile_status_START (16)
#define SOC_PMCTRL_VDDC_MEM_VOL_DOZE_VOTE_CTRL_vddc_mem_dvs_profile_status_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch16_idx_0 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH16_IDX_0_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH16_IDX_0_vddc_mem_vote_vol_ch16_idx_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH16_IDX_0_vddc_mem_vote_vol_ch16_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch16_idx_1 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH16_IDX_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH16_IDX_1_vddc_mem_vote_vol_ch16_idx_1_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH16_IDX_1_vddc_mem_vote_vol_ch16_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch17_idx_0 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH17_IDX_0_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH17_IDX_0_vddc_mem_vote_vol_ch17_idx_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH17_IDX_0_vddc_mem_vote_vol_ch17_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch17_idx_1 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH17_IDX_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH17_IDX_1_vddc_mem_vote_vol_ch17_idx_1_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH17_IDX_1_vddc_mem_vote_vol_ch17_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch18_idx_0 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH18_IDX_0_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH18_IDX_0_vddc_mem_vote_vol_ch18_idx_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH18_IDX_0_vddc_mem_vote_vol_ch18_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch18_idx_1 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH18_IDX_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH18_IDX_1_vddc_mem_vote_vol_ch18_idx_1_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH18_IDX_1_vddc_mem_vote_vol_ch18_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch19_idx_0 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH19_IDX_0_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH19_IDX_0_vddc_mem_vote_vol_ch19_idx_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH19_IDX_0_vddc_mem_vote_vol_ch19_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch19_idx_1 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH19_IDX_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH19_IDX_1_vddc_mem_vote_vol_ch19_idx_1_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH19_IDX_1_vddc_mem_vote_vol_ch19_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch20_idx_0 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH20_IDX_0_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH20_IDX_0_vddc_mem_vote_vol_ch20_idx_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH20_IDX_0_vddc_mem_vote_vol_ch20_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch20_idx_1 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH20_IDX_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH20_IDX_1_vddc_mem_vote_vol_ch20_idx_1_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH20_IDX_1_vddc_mem_vote_vol_ch20_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch21_idx_0 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH21_IDX_0_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH21_IDX_0_vddc_mem_vote_vol_ch21_idx_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH21_IDX_0_vddc_mem_vote_vol_ch21_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch21_idx_1 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH21_IDX_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH21_IDX_1_vddc_mem_vote_vol_ch21_idx_1_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH21_IDX_1_vddc_mem_vote_vol_ch21_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch22_idx_0 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH22_IDX_0_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH22_IDX_0_vddc_mem_vote_vol_ch22_idx_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH22_IDX_0_vddc_mem_vote_vol_ch22_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch22_idx_1 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH22_IDX_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH22_IDX_1_vddc_mem_vote_vol_ch22_idx_1_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH22_IDX_1_vddc_mem_vote_vol_ch22_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch23_idx_0 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH23_IDX_0_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH23_IDX_0_vddc_mem_vote_vol_ch23_idx_0_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH23_IDX_0_vddc_mem_vote_vol_ch23_idx_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_vol_ch23_idx_1 : 32;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH23_IDX_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH23_IDX_1_vddc_mem_vote_vol_ch23_idx_1_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_VOL_CH23_IDX_1_vddc_mem_vote_vol_ch23_idx_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_init_vol_idx_vau_4 : 8;
        unsigned int vddc_mem_init_vol_req_vau_4 : 1;
        unsigned int vddc_mem_init_vol_idx_vau_5 : 8;
        unsigned int vddc_mem_init_vol_req_vau_5 : 1;
        unsigned int vddc_mem_init_vol_idx_vau_4to7 : 8;
        unsigned int vddc_mem_init_vol_req_vau_4to7 : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG2_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG2_vddc_mem_init_vol_idx_vau_4_START (0)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG2_vddc_mem_init_vol_idx_vau_4_END (7)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG2_vddc_mem_init_vol_req_vau_4_START (8)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG2_vddc_mem_init_vol_req_vau_4_END (8)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG2_vddc_mem_init_vol_idx_vau_5_START (9)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG2_vddc_mem_init_vol_idx_vau_5_END (16)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG2_vddc_mem_init_vol_req_vau_5_START (17)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG2_vddc_mem_init_vol_req_vau_5_END (17)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG2_vddc_mem_init_vol_idx_vau_4to7_START (18)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG2_vddc_mem_init_vol_idx_vau_4to7_END (25)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG2_vddc_mem_init_vol_req_vau_4to7_START (26)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG2_vddc_mem_init_vol_req_vau_4to7_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_init_vol_idx_vau_0to7 : 8;
        unsigned int vddc_mem_init_vol_req_vau_0to7 : 1;
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 8;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 5;
    } reg;
} SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG3_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG3_vddc_mem_init_vol_idx_vau_0to7_START (0)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG3_vddc_mem_init_vol_idx_vau_0to7_END (7)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG3_vddc_mem_init_vol_req_vau_0to7_START (8)
#define SOC_PMCTRL_VDDC_MEM_INIT_VOL_CONFIG3_vddc_mem_init_vol_req_vau_0to7_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_sft_vol_idx_0_vau4to7 : 8;
        unsigned int vddc_mem_vote_sft_vol_idx_1_vau4to7 : 8;
        unsigned int vddc_mem_vote_sft_vol_idx_2_vau4to7 : 8;
        unsigned int vddc_mem_vote_sft_vol_idx_3_vau4to7 : 8;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_1_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_1_vddc_mem_vote_sft_vol_idx_0_vau4to7_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_1_vddc_mem_vote_sft_vol_idx_0_vau4to7_END (7)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_1_vddc_mem_vote_sft_vol_idx_1_vau4to7_START (8)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_1_vddc_mem_vote_sft_vol_idx_1_vau4to7_END (15)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_1_vddc_mem_vote_sft_vol_idx_2_vau4to7_START (16)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_1_vddc_mem_vote_sft_vol_idx_2_vau4to7_END (23)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_1_vddc_mem_vote_sft_vol_idx_3_vau4to7_START (24)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_1_vddc_mem_vote_sft_vol_idx_3_vau4to7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vddc_mem_vote_sft_vol_idx_0_vau0to7 : 8;
        unsigned int vddc_mem_vote_sft_vol_idx_1_vau0to7 : 8;
        unsigned int vddc_mem_vote_sft_vol_idx_2_vau0to7 : 8;
        unsigned int vddc_mem_vote_sft_vol_idx_3_vau0to7 : 8;
    } reg;
} SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_2_UNION;
#endif
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_2_vddc_mem_vote_sft_vol_idx_0_vau0to7_START (0)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_2_vddc_mem_vote_sft_vol_idx_0_vau0to7_END (7)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_2_vddc_mem_vote_sft_vol_idx_1_vau0to7_START (8)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_2_vddc_mem_vote_sft_vol_idx_1_vau0to7_END (15)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_2_vddc_mem_vote_sft_vol_idx_2_vau0to7_START (16)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_2_vddc_mem_vote_sft_vol_idx_2_vau0to7_END (23)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_2_vddc_mem_vote_sft_vol_idx_3_vau0to7_START (24)
#define SOC_PMCTRL_VDDC_MEM_VOTE_SFT_HRD_VOL_IDX_2_vddc_mem_vote_sft_vol_idx_3_vau0to7_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
