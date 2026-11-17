#ifndef __SOC_PMCTRL_FREQ_VOTE_INTERFACE_H__
#define __SOC_PMCTRL_FREQ_VOTE_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_PMCTRL_FREQ_VOTE_PERIBAKDATA0_ADDR(base) ((base) + (0x630UL))
#define SOC_PMCTRL_FREQ_VOTE_PERIBAKDATA1_ADDR(base) ((base) + (0x634UL))
#define SOC_PMCTRL_FREQ_VOTE_PERIBAKDATA2_ADDR(base) ((base) + (0x638UL))
#define SOC_PMCTRL_FREQ_VOTE_PERIBAKDATA3_ADDR(base) ((base) + (0x63CUL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_A0_ADDR(base) ((base) + (0x200UL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_A1_ADDR(base) ((base) + (0x204UL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_B0_ADDR(base) ((base) + (0x208UL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_B1_ADDR(base) ((base) + (0x20CUL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_C0_ADDR(base) ((base) + (0x210UL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_C1_ADDR(base) ((base) + (0x214UL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_D0_ADDR(base) ((base) + (0x218UL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_D1_ADDR(base) ((base) + (0x21CUL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E0_ADDR(base) ((base) + (0x220UL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E1_ADDR(base) ((base) + (0x224UL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E2_ADDR(base) ((base) + (0x228UL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E3_ADDR(base) ((base) + (0x22CUL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F0_ADDR(base) ((base) + (0x230UL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F1_ADDR(base) ((base) + (0x234UL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F2_ADDR(base) ((base) + (0x238UL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F3_ADDR(base) ((base) + (0x23CUL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G0_ADDR(base) ((base) + (0x240UL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G1_ADDR(base) ((base) + (0x244UL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G2_ADDR(base) ((base) + (0x248UL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G3_ADDR(base) ((base) + (0x24CUL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H0_ADDR(base) ((base) + (0x250UL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H1_ADDR(base) ((base) + (0x254UL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H2_ADDR(base) ((base) + (0x258UL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H3_ADDR(base) ((base) + (0x25CUL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H4_ADDR(base) ((base) + (0x260UL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H5_ADDR(base) ((base) + (0x264UL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H6_ADDR(base) ((base) + (0x268UL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H7_ADDR(base) ((base) + (0x26CUL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I0_ADDR(base) ((base) + (0x270UL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I1_ADDR(base) ((base) + (0x274UL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I2_ADDR(base) ((base) + (0x278UL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I3_ADDR(base) ((base) + (0x27CUL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I4_ADDR(base) ((base) + (0x280UL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I5_ADDR(base) ((base) + (0x284UL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I6_ADDR(base) ((base) + (0x288UL))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I7_ADDR(base) ((base) + (0x28CUL))
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_LPMCU_ADDR(base) ((base) + (0x290UL))
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_CPU_LP_CTRL_ADDR(base) ((base) + (0x294UL))
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_GPU_LP_CTRL_ADDR(base) ((base) + (0x298UL))
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_DDR_LP_CTRL_ADDR(base) ((base) + (0x29CUL))
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_MEDIA_LP_CTRL_ADDR(base) ((base) + (0x2A0UL))
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_GIC_ADDR(base) ((base) + (0x2A4UL))
#define SOC_PMCTRL_FREQ_VOTE_VOTE_CHANNEL_CFG_ADDR(base) ((base) + (0x2B0UL))
#define SOC_PMCTRL_FREQ_VOTE_VOTE_MODE_CFG_0_ADDR(base) ((base) + (0x2BCUL))
#define SOC_PMCTRL_FREQ_VOTE_VOTE_MODE_CFG_1_ADDR(base) ((base) + (0x2C0UL))
#define SOC_PMCTRL_FREQ_VOTE_VOTE_START_EN_ADDR(base) ((base) + (0x2C4UL))
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_EN_ADDR(base) ((base) + (0x2C8UL))
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_CLR_ADDR(base) ((base) + (0x2CCUL))
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_RAW_STAT_ADDR(base) ((base) + (0x2D0UL))
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_STAT_ADDR(base) ((base) + (0x2D4UL))
#define SOC_PMCTRL_FREQ_VOTE_INT_FREQUENCY_VOTE_ADDR(base) ((base) + (0x2D8UL))
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_A_ADDR(base) ((base) + (0x2DCUL))
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_B_ADDR(base) ((base) + (0x2E0UL))
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_C_ADDR(base) ((base) + (0x2E4UL))
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_D_ADDR(base) ((base) + (0x2E8UL))
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_E_ADDR(base) ((base) + (0x2ECUL))
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_F_ADDR(base) ((base) + (0x2F0UL))
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_G_ADDR(base) ((base) + (0x2F4UL))
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_H_ADDR(base) ((base) + (0x2F8UL))
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_I_ADDR(base) ((base) + (0x2FCUL))
#define SOC_PMCTRL_FREQ_VOTE_HARD_REQACK_EN_ADDR(base) ((base) + (0x300UL))
#define SOC_PMCTRL_FREQ_VOTE_HARD_INT_FREQ_VOTE_I_CLR_EN_ADDR(base) ((base) + (0x304UL))
#define SOC_PMCTRL_FREQ_VOTE_HARD_REQACK_INFO_ADDR(base) ((base) + (0x308UL))
#else
#define SOC_PMCTRL_FREQ_VOTE_PERIBAKDATA0_ADDR(base) ((base) + (0x630))
#define SOC_PMCTRL_FREQ_VOTE_PERIBAKDATA1_ADDR(base) ((base) + (0x634))
#define SOC_PMCTRL_FREQ_VOTE_PERIBAKDATA2_ADDR(base) ((base) + (0x638))
#define SOC_PMCTRL_FREQ_VOTE_PERIBAKDATA3_ADDR(base) ((base) + (0x63C))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_A0_ADDR(base) ((base) + (0x200))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_A1_ADDR(base) ((base) + (0x204))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_B0_ADDR(base) ((base) + (0x208))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_B1_ADDR(base) ((base) + (0x20C))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_C0_ADDR(base) ((base) + (0x210))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_C1_ADDR(base) ((base) + (0x214))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_D0_ADDR(base) ((base) + (0x218))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_D1_ADDR(base) ((base) + (0x21C))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E0_ADDR(base) ((base) + (0x220))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E1_ADDR(base) ((base) + (0x224))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E2_ADDR(base) ((base) + (0x228))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E3_ADDR(base) ((base) + (0x22C))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F0_ADDR(base) ((base) + (0x230))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F1_ADDR(base) ((base) + (0x234))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F2_ADDR(base) ((base) + (0x238))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F3_ADDR(base) ((base) + (0x23C))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G0_ADDR(base) ((base) + (0x240))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G1_ADDR(base) ((base) + (0x244))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G2_ADDR(base) ((base) + (0x248))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G3_ADDR(base) ((base) + (0x24C))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H0_ADDR(base) ((base) + (0x250))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H1_ADDR(base) ((base) + (0x254))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H2_ADDR(base) ((base) + (0x258))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H3_ADDR(base) ((base) + (0x25C))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H4_ADDR(base) ((base) + (0x260))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H5_ADDR(base) ((base) + (0x264))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H6_ADDR(base) ((base) + (0x268))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H7_ADDR(base) ((base) + (0x26C))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I0_ADDR(base) ((base) + (0x270))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I1_ADDR(base) ((base) + (0x274))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I2_ADDR(base) ((base) + (0x278))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I3_ADDR(base) ((base) + (0x27C))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I4_ADDR(base) ((base) + (0x280))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I5_ADDR(base) ((base) + (0x284))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I6_ADDR(base) ((base) + (0x288))
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I7_ADDR(base) ((base) + (0x28C))
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_LPMCU_ADDR(base) ((base) + (0x290))
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_CPU_LP_CTRL_ADDR(base) ((base) + (0x294))
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_GPU_LP_CTRL_ADDR(base) ((base) + (0x298))
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_DDR_LP_CTRL_ADDR(base) ((base) + (0x29C))
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_MEDIA_LP_CTRL_ADDR(base) ((base) + (0x2A0))
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_GIC_ADDR(base) ((base) + (0x2A4))
#define SOC_PMCTRL_FREQ_VOTE_VOTE_CHANNEL_CFG_ADDR(base) ((base) + (0x2B0))
#define SOC_PMCTRL_FREQ_VOTE_VOTE_MODE_CFG_0_ADDR(base) ((base) + (0x2BC))
#define SOC_PMCTRL_FREQ_VOTE_VOTE_MODE_CFG_1_ADDR(base) ((base) + (0x2C0))
#define SOC_PMCTRL_FREQ_VOTE_VOTE_START_EN_ADDR(base) ((base) + (0x2C4))
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_EN_ADDR(base) ((base) + (0x2C8))
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_CLR_ADDR(base) ((base) + (0x2CC))
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_RAW_STAT_ADDR(base) ((base) + (0x2D0))
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_STAT_ADDR(base) ((base) + (0x2D4))
#define SOC_PMCTRL_FREQ_VOTE_INT_FREQUENCY_VOTE_ADDR(base) ((base) + (0x2D8))
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_A_ADDR(base) ((base) + (0x2DC))
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_B_ADDR(base) ((base) + (0x2E0))
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_C_ADDR(base) ((base) + (0x2E4))
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_D_ADDR(base) ((base) + (0x2E8))
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_E_ADDR(base) ((base) + (0x2EC))
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_F_ADDR(base) ((base) + (0x2F0))
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_G_ADDR(base) ((base) + (0x2F4))
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_H_ADDR(base) ((base) + (0x2F8))
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_I_ADDR(base) ((base) + (0x2FC))
#define SOC_PMCTRL_FREQ_VOTE_HARD_REQACK_EN_ADDR(base) ((base) + (0x300))
#define SOC_PMCTRL_FREQ_VOTE_HARD_INT_FREQ_VOTE_I_CLR_EN_ADDR(base) ((base) + (0x304))
#define SOC_PMCTRL_FREQ_VOTE_HARD_REQACK_INFO_ADDR(base) ((base) + (0x308))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_PERIBAKDATA0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_PERIBAKDATA1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_PERIBAKDATA2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_PERIBAKDATA3_UNION;
#endif
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
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_A0_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_A0_freq_vote_a_channel0_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_A0_freq_vote_a_channel0_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_A0_freq_vote_a0_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_A0_freq_vote_a0_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_A0_freq_vote_a_channel1_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_A0_freq_vote_a_channel1_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_A0_freq_vote_a0_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_A0_freq_vote_a0_msk1_END (31)
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
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_A1_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_A1_freq_vote_a_channel2_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_A1_freq_vote_a_channel2_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_A1_freq_vote_a1_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_A1_freq_vote_a1_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_A1_freq_vote_a_channel3_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_A1_freq_vote_a_channel3_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_A1_freq_vote_a1_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_A1_freq_vote_a1_msk1_END (31)
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
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_B0_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_B0_freq_vote_b_channel0_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_B0_freq_vote_b_channel0_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_B0_freq_vote_b0_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_B0_freq_vote_b0_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_B0_freq_vote_b_channel1_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_B0_freq_vote_b_channel1_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_B0_freq_vote_b0_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_B0_freq_vote_b0_msk1_END (31)
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
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_B1_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_B1_freq_vote_b_channel2_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_B1_freq_vote_b_channel2_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_B1_freq_vote_b1_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_B1_freq_vote_b1_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_B1_freq_vote_b_channel3_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_B1_freq_vote_b_channel3_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_B1_freq_vote_b1_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_B1_freq_vote_b1_msk1_END (31)
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
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_C0_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_C0_freq_vote_c_channel0_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_C0_freq_vote_c_channel0_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_C0_freq_vote_c0_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_C0_freq_vote_c0_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_C0_freq_vote_c_channel1_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_C0_freq_vote_c_channel1_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_C0_freq_vote_c0_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_C0_freq_vote_c0_msk1_END (31)
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
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_C1_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_C1_freq_vote_c_channel2_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_C1_freq_vote_c_channel2_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_C1_freq_vote_c1_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_C1_freq_vote_c1_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_C1_freq_vote_c_channel3_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_C1_freq_vote_c_channel3_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_C1_freq_vote_c1_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_C1_freq_vote_c1_msk1_END (31)
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
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_D0_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_D0_freq_vote_d_channel0_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_D0_freq_vote_d_channel0_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_D0_freq_vote_d0_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_D0_freq_vote_d0_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_D0_freq_vote_d_channel1_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_D0_freq_vote_d_channel1_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_D0_freq_vote_d0_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_D0_freq_vote_d0_msk1_END (31)
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
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_D1_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_D1_freq_vote_d_channel2_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_D1_freq_vote_d_channel2_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_D1_freq_vote_d1_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_D1_freq_vote_d1_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_D1_freq_vote_d_channel3_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_D1_freq_vote_d_channel3_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_D1_freq_vote_d1_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_D1_freq_vote_d1_msk1_END (31)
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
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E0_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E0_freq_vote_e_channel0_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E0_freq_vote_e_channel0_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E0_freq_vote_e0_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E0_freq_vote_e0_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E0_freq_vote_e_channel1_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E0_freq_vote_e_channel1_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E0_freq_vote_e0_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E0_freq_vote_e0_msk1_END (31)
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
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E1_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E1_freq_vote_e_channel2_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E1_freq_vote_e_channel2_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E1_freq_vote_e1_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E1_freq_vote_e1_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E1_freq_vote_e_channel3_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E1_freq_vote_e_channel3_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E1_freq_vote_e1_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E1_freq_vote_e1_msk1_END (31)
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
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E2_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E2_freq_vote_e_channel4_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E2_freq_vote_e_channel4_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E2_freq_vote_e2_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E2_freq_vote_e2_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E2_freq_vote_e_channel5_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E2_freq_vote_e_channel5_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E2_freq_vote_e2_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E2_freq_vote_e2_msk1_END (31)
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
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E3_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E3_freq_vote_e_channel6_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E3_freq_vote_e_channel6_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E3_freq_vote_e3_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E3_freq_vote_e3_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E3_freq_vote_e_channel7_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E3_freq_vote_e_channel7_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E3_freq_vote_e3_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_E3_freq_vote_e3_msk1_END (31)
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
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F0_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F0_freq_vote_f_channel0_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F0_freq_vote_f_channel0_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F0_freq_vote_f0_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F0_freq_vote_f0_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F0_freq_vote_f_channel1_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F0_freq_vote_f_channel1_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F0_freq_vote_f0_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F0_freq_vote_f0_msk1_END (31)
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
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F1_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F1_freq_vote_f_channel2_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F1_freq_vote_f_channel2_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F1_freq_vote_f1_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F1_freq_vote_f1_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F1_freq_vote_f_channel3_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F1_freq_vote_f_channel3_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F1_freq_vote_f1_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F1_freq_vote_f1_msk1_END (31)
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
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F2_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F2_freq_vote_f_channel4_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F2_freq_vote_f_channel4_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F2_freq_vote_f2_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F2_freq_vote_f2_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F2_freq_vote_f_channel5_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F2_freq_vote_f_channel5_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F2_freq_vote_f2_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F2_freq_vote_f2_msk1_END (31)
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
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F3_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F3_freq_vote_f_channel6_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F3_freq_vote_f_channel6_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F3_freq_vote_f3_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F3_freq_vote_f3_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F3_freq_vote_f_channel7_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F3_freq_vote_f_channel7_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F3_freq_vote_f3_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_F3_freq_vote_f3_msk1_END (31)
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
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G0_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G0_freq_vote_g_channel0_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G0_freq_vote_g_channel0_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G0_freq_vote_g0_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G0_freq_vote_g0_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G0_freq_vote_g_channel1_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G0_freq_vote_g_channel1_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G0_freq_vote_g0_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G0_freq_vote_g0_msk1_END (31)
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
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G1_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G1_freq_vote_g_channel2_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G1_freq_vote_g_channel2_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G1_freq_vote_g1_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G1_freq_vote_g1_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G1_freq_vote_g_channel3_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G1_freq_vote_g_channel3_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G1_freq_vote_g1_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G1_freq_vote_g1_msk1_END (31)
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
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G2_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G2_freq_vote_g_channel4_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G2_freq_vote_g_channel4_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G2_freq_vote_g2_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G2_freq_vote_g2_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G2_freq_vote_g_channel5_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G2_freq_vote_g_channel5_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G2_freq_vote_g2_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G2_freq_vote_g2_msk1_END (31)
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
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G3_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G3_freq_vote_g_channel6_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G3_freq_vote_g_channel6_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G3_freq_vote_g3_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G3_freq_vote_g3_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G3_freq_vote_g_channel7_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G3_freq_vote_g_channel7_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G3_freq_vote_g3_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_G3_freq_vote_g3_msk1_END (31)
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
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H0_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H0_freq_vote_h_channel0_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H0_freq_vote_h_channel0_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H0_freq_vote_h0_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H0_freq_vote_h0_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H0_freq_vote_h_channel1_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H0_freq_vote_h_channel1_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H0_freq_vote_h0_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H0_freq_vote_h0_msk1_END (31)
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
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H1_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H1_freq_vote_h_channel2_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H1_freq_vote_h_channel2_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H1_freq_vote_h1_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H1_freq_vote_h1_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H1_freq_vote_h_channel3_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H1_freq_vote_h_channel3_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H1_freq_vote_h1_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H1_freq_vote_h1_msk1_END (31)
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
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H2_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H2_freq_vote_h_channel4_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H2_freq_vote_h_channel4_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H2_freq_vote_h2_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H2_freq_vote_h2_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H2_freq_vote_h_channel5_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H2_freq_vote_h_channel5_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H2_freq_vote_h2_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H2_freq_vote_h2_msk1_END (31)
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
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H3_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H3_freq_vote_h_channel6_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H3_freq_vote_h_channel6_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H3_freq_vote_h3_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H3_freq_vote_h3_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H3_freq_vote_h_channel7_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H3_freq_vote_h_channel7_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H3_freq_vote_h3_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H3_freq_vote_h3_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_h_channel8 : 15;
        unsigned int freq_vote_h4_msk0 : 1;
        unsigned int freq_vote_h_channel9 : 15;
        unsigned int freq_vote_h4_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H4_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H4_freq_vote_h_channel8_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H4_freq_vote_h_channel8_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H4_freq_vote_h4_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H4_freq_vote_h4_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H4_freq_vote_h_channel9_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H4_freq_vote_h_channel9_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H4_freq_vote_h4_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H4_freq_vote_h4_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_h_channel10 : 15;
        unsigned int freq_vote_h5_msk0 : 1;
        unsigned int freq_vote_h_channel11 : 15;
        unsigned int freq_vote_h5_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H5_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H5_freq_vote_h_channel10_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H5_freq_vote_h_channel10_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H5_freq_vote_h5_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H5_freq_vote_h5_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H5_freq_vote_h_channel11_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H5_freq_vote_h_channel11_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H5_freq_vote_h5_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H5_freq_vote_h5_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_h_channel12 : 15;
        unsigned int freq_vote_h6_msk0 : 1;
        unsigned int freq_vote_h_channel13 : 15;
        unsigned int freq_vote_h6_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H6_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H6_freq_vote_h_channel12_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H6_freq_vote_h_channel12_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H6_freq_vote_h6_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H6_freq_vote_h6_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H6_freq_vote_h_channel13_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H6_freq_vote_h_channel13_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H6_freq_vote_h6_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H6_freq_vote_h6_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_h_channel14 : 15;
        unsigned int freq_vote_h7_msk0 : 1;
        unsigned int freq_vote_h_channel15 : 15;
        unsigned int freq_vote_h7_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H7_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H7_freq_vote_h_channel14_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H7_freq_vote_h_channel14_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H7_freq_vote_h7_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H7_freq_vote_h7_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H7_freq_vote_h_channel15_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H7_freq_vote_h_channel15_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H7_freq_vote_h7_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_H7_freq_vote_h7_msk1_END (31)
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
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I0_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I0_freq_vote_i_channel0_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I0_freq_vote_i_channel0_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I0_freq_vote_i0_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I0_freq_vote_i0_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I0_freq_vote_i_channel1_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I0_freq_vote_i_channel1_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I0_freq_vote_i0_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I0_freq_vote_i0_msk1_END (31)
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
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I1_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I1_freq_vote_i_channel2_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I1_freq_vote_i_channel2_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I1_freq_vote_i1_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I1_freq_vote_i1_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I1_freq_vote_i_channel3_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I1_freq_vote_i_channel3_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I1_freq_vote_i1_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I1_freq_vote_i1_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_i_channel4 : 15;
        unsigned int freq_vote_i2_msk0 : 1;
        unsigned int freq_vote_i_channel5 : 15;
        unsigned int freq_vote_i2_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I2_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I2_freq_vote_i_channel4_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I2_freq_vote_i_channel4_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I2_freq_vote_i2_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I2_freq_vote_i2_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I2_freq_vote_i_channel5_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I2_freq_vote_i_channel5_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I2_freq_vote_i2_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I2_freq_vote_i2_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_i_channel6 : 15;
        unsigned int freq_vote_i3_msk0 : 1;
        unsigned int freq_vote_i_channel7 : 15;
        unsigned int freq_vote_i3_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I3_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I3_freq_vote_i_channel6_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I3_freq_vote_i_channel6_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I3_freq_vote_i3_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I3_freq_vote_i3_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I3_freq_vote_i_channel7_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I3_freq_vote_i_channel7_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I3_freq_vote_i3_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I3_freq_vote_i3_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_i_channel8 : 15;
        unsigned int freq_vote_i4_msk0 : 1;
        unsigned int freq_vote_i_channel9 : 15;
        unsigned int freq_vote_i4_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I4_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I4_freq_vote_i_channel8_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I4_freq_vote_i_channel8_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I4_freq_vote_i4_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I4_freq_vote_i4_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I4_freq_vote_i_channel9_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I4_freq_vote_i_channel9_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I4_freq_vote_i4_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I4_freq_vote_i4_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_i_channel10 : 15;
        unsigned int freq_vote_i5_msk0 : 1;
        unsigned int freq_vote_i_channel11 : 15;
        unsigned int freq_vote_i5_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I5_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I5_freq_vote_i_channel10_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I5_freq_vote_i_channel10_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I5_freq_vote_i5_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I5_freq_vote_i5_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I5_freq_vote_i_channel11_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I5_freq_vote_i_channel11_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I5_freq_vote_i5_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I5_freq_vote_i5_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_i_channel12 : 15;
        unsigned int freq_vote_i6_msk0 : 1;
        unsigned int freq_vote_i_channel13 : 15;
        unsigned int freq_vote_i6_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I6_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I6_freq_vote_i_channel12_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I6_freq_vote_i_channel12_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I6_freq_vote_i6_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I6_freq_vote_i6_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I6_freq_vote_i_channel13_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I6_freq_vote_i_channel13_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I6_freq_vote_i6_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I6_freq_vote_i6_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_i_channel14 : 15;
        unsigned int freq_vote_i7_msk0 : 1;
        unsigned int freq_vote_i_channel15 : 15;
        unsigned int freq_vote_i7_msk1 : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I7_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I7_freq_vote_i_channel14_START (0)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I7_freq_vote_i_channel14_END (14)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I7_freq_vote_i7_msk0_START (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I7_freq_vote_i7_msk0_END (15)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I7_freq_vote_i_channel15_START (16)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I7_freq_vote_i_channel15_END (30)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I7_freq_vote_i7_msk1_START (31)
#define SOC_PMCTRL_FREQ_VOTE_FREQ_VOTE_I7_freq_vote_i7_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_mask_to_lpmcu : 9;
        unsigned int reserved : 7;
        unsigned int intr_mask_to_lpmcu_msk : 16;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_LPMCU_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_LPMCU_intr_mask_to_lpmcu_START (0)
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_LPMCU_intr_mask_to_lpmcu_END (8)
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_LPMCU_intr_mask_to_lpmcu_msk_START (16)
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_LPMCU_intr_mask_to_lpmcu_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_mask_to_cpu_lp_ctrl : 9;
        unsigned int reserved : 7;
        unsigned int intr_mask_to_cpu_lp_ctrl_msk : 16;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_CPU_LP_CTRL_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_CPU_LP_CTRL_intr_mask_to_cpu_lp_ctrl_START (0)
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_CPU_LP_CTRL_intr_mask_to_cpu_lp_ctrl_END (8)
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_CPU_LP_CTRL_intr_mask_to_cpu_lp_ctrl_msk_START (16)
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_CPU_LP_CTRL_intr_mask_to_cpu_lp_ctrl_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_mask_to_gpu_lp_ctrl : 9;
        unsigned int reserved : 7;
        unsigned int intr_mask_to_gpu_lp_ctrl_msk : 16;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_GPU_LP_CTRL_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_GPU_LP_CTRL_intr_mask_to_gpu_lp_ctrl_START (0)
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_GPU_LP_CTRL_intr_mask_to_gpu_lp_ctrl_END (8)
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_GPU_LP_CTRL_intr_mask_to_gpu_lp_ctrl_msk_START (16)
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_GPU_LP_CTRL_intr_mask_to_gpu_lp_ctrl_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_mask_to_ddr_lp_ctrl : 9;
        unsigned int reserved : 7;
        unsigned int intr_mask_to_ddr_lp_ctrl_msk : 16;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_DDR_LP_CTRL_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_DDR_LP_CTRL_intr_mask_to_ddr_lp_ctrl_START (0)
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_DDR_LP_CTRL_intr_mask_to_ddr_lp_ctrl_END (8)
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_DDR_LP_CTRL_intr_mask_to_ddr_lp_ctrl_msk_START (16)
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_DDR_LP_CTRL_intr_mask_to_ddr_lp_ctrl_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_mask_to_media_lp_ctrl : 9;
        unsigned int reserved : 7;
        unsigned int intr_mask_to_media_lp_ctrl_msk : 16;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_MEDIA_LP_CTRL_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_MEDIA_LP_CTRL_intr_mask_to_media_lp_ctrl_START (0)
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_MEDIA_LP_CTRL_intr_mask_to_media_lp_ctrl_END (8)
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_MEDIA_LP_CTRL_intr_mask_to_media_lp_ctrl_msk_START (16)
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_MEDIA_LP_CTRL_intr_mask_to_media_lp_ctrl_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_mask_to_gic : 1;
        unsigned int reserved : 30;
        unsigned int intr_mask_to_gic_msk : 1;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_GIC_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_GIC_intr_mask_to_gic_START (0)
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_GIC_intr_mask_to_gic_END (0)
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_GIC_intr_mask_to_gic_msk_START (31)
#define SOC_PMCTRL_FREQ_VOTE_INTR_MASK_TO_GIC_intr_mask_to_gic_msk_END (31)
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
        unsigned int reserved : 14;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_VOTE_CHANNEL_CFG_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_VOTE_CHANNEL_CFG_freq_vote_channel_num_a_START (0)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_CHANNEL_CFG_freq_vote_channel_num_a_END (1)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_CHANNEL_CFG_freq_vote_channel_num_b_START (2)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_CHANNEL_CFG_freq_vote_channel_num_b_END (3)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_CHANNEL_CFG_freq_vote_channel_num_c_START (4)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_CHANNEL_CFG_freq_vote_channel_num_c_END (5)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_CHANNEL_CFG_freq_vote_channel_num_d_START (6)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_CHANNEL_CFG_freq_vote_channel_num_d_END (7)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_CHANNEL_CFG_freq_vote_channel_num_e_START (8)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_CHANNEL_CFG_freq_vote_channel_num_e_END (9)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_CHANNEL_CFG_freq_vote_channel_num_f_START (10)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_CHANNEL_CFG_freq_vote_channel_num_f_END (11)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_CHANNEL_CFG_freq_vote_channel_num_g_START (12)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_CHANNEL_CFG_freq_vote_channel_num_g_END (13)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_CHANNEL_CFG_freq_vote_channel_num_h_START (14)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_CHANNEL_CFG_freq_vote_channel_num_h_END (15)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_CHANNEL_CFG_freq_vote_channel_num_i_START (16)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_CHANNEL_CFG_freq_vote_channel_num_i_END (17)
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
} SOC_PMCTRL_FREQ_VOTE_VOTE_MODE_CFG_0_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_VOTE_MODE_CFG_0_freq_vote_a_type_START (0)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_MODE_CFG_0_freq_vote_a_type_END (1)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_MODE_CFG_0_freq_vote_b_type_START (2)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_MODE_CFG_0_freq_vote_b_type_END (3)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_MODE_CFG_0_freq_vote_c_type_START (4)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_MODE_CFG_0_freq_vote_c_type_END (5)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_MODE_CFG_0_freq_vote_d_type_START (6)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_MODE_CFG_0_freq_vote_d_type_END (7)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_MODE_CFG_0_freq_vote_e_type_START (8)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_MODE_CFG_0_freq_vote_e_type_END (9)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_MODE_CFG_0_freq_vote_f_type_START (10)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_MODE_CFG_0_freq_vote_f_type_END (11)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_MODE_CFG_0_freq_vote_g_type_START (12)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_MODE_CFG_0_freq_vote_g_type_END (13)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_MODE_CFG_0_freq_vote_h_type_START (14)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_MODE_CFG_0_freq_vote_h_type_END (15)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_MODE_CFG_0_vote_mode_cfg_0_msk_START (16)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_MODE_CFG_0_vote_mode_cfg_0_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_i_type : 2;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 2;
        unsigned int reserved_3 : 2;
        unsigned int reserved_4 : 2;
        unsigned int reserved_5 : 2;
        unsigned int reserved_6 : 2;
        unsigned int vote_mode_cfg_1_msk : 16;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_VOTE_MODE_CFG_1_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_VOTE_MODE_CFG_1_freq_vote_i_type_START (0)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_MODE_CFG_1_freq_vote_i_type_END (1)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_MODE_CFG_1_vote_mode_cfg_1_msk_START (16)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_MODE_CFG_1_vote_mode_cfg_1_msk_END (31)
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
        unsigned int reserved : 7;
        unsigned int vote_start_en_msk : 16;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_VOTE_START_EN_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_VOTE_START_EN_freq_vote_a_start_en_START (0)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_START_EN_freq_vote_a_start_en_END (0)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_START_EN_freq_vote_b_start_en_START (1)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_START_EN_freq_vote_b_start_en_END (1)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_START_EN_freq_vote_c_start_en_START (2)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_START_EN_freq_vote_c_start_en_END (2)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_START_EN_freq_vote_d_start_en_START (3)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_START_EN_freq_vote_d_start_en_END (3)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_START_EN_freq_vote_e_start_en_START (4)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_START_EN_freq_vote_e_start_en_END (4)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_START_EN_freq_vote_f_start_en_START (5)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_START_EN_freq_vote_f_start_en_END (5)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_START_EN_freq_vote_g_start_en_START (6)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_START_EN_freq_vote_g_start_en_END (6)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_START_EN_freq_vote_h_start_en_START (7)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_START_EN_freq_vote_h_start_en_END (7)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_START_EN_freq_vote_i_start_en_START (8)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_START_EN_freq_vote_i_start_en_END (8)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_START_EN_vote_start_en_msk_START (16)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_START_EN_vote_start_en_msk_END (31)
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
        unsigned int reserved : 7;
        unsigned int int_vote_en_msk : 16;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_INT_VOTE_EN_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_EN_int_freq_vote_en_a_START (0)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_EN_int_freq_vote_en_a_END (0)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_EN_int_freq_vote_en_b_START (1)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_EN_int_freq_vote_en_b_END (1)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_EN_int_freq_vote_en_c_START (2)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_EN_int_freq_vote_en_c_END (2)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_EN_int_freq_vote_en_d_START (3)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_EN_int_freq_vote_en_d_END (3)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_EN_int_freq_vote_en_e_START (4)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_EN_int_freq_vote_en_e_END (4)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_EN_int_freq_vote_en_f_START (5)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_EN_int_freq_vote_en_f_END (5)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_EN_int_freq_vote_en_g_START (6)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_EN_int_freq_vote_en_g_END (6)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_EN_int_freq_vote_en_h_START (7)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_EN_int_freq_vote_en_h_END (7)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_EN_int_freq_vote_en_i_START (8)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_EN_int_freq_vote_en_i_END (8)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_EN_int_vote_en_msk_START (16)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_EN_int_vote_en_msk_END (31)
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
        unsigned int reserved_0 : 7;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_INT_VOTE_CLR_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_CLR_int_freq_vote_a_clr_START (0)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_CLR_int_freq_vote_a_clr_END (0)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_CLR_int_freq_vote_b_clr_START (1)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_CLR_int_freq_vote_b_clr_END (1)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_CLR_int_freq_vote_c_clr_START (2)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_CLR_int_freq_vote_c_clr_END (2)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_CLR_int_freq_vote_d_clr_START (3)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_CLR_int_freq_vote_d_clr_END (3)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_CLR_int_freq_vote_e_clr_START (4)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_CLR_int_freq_vote_e_clr_END (4)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_CLR_int_freq_vote_f_clr_START (5)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_CLR_int_freq_vote_f_clr_END (5)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_CLR_int_freq_vote_g_clr_START (6)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_CLR_int_freq_vote_g_clr_END (6)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_CLR_int_freq_vote_h_clr_START (7)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_CLR_int_freq_vote_h_clr_END (7)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_CLR_int_freq_vote_i_clr_START (8)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_CLR_int_freq_vote_i_clr_END (8)
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
        unsigned int reserved_0 : 7;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_INT_VOTE_RAW_STAT_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_a_START (0)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_a_END (0)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_b_START (1)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_b_END (1)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_c_START (2)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_c_END (2)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_d_START (3)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_d_END (3)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_e_START (4)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_e_END (4)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_f_START (5)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_f_END (5)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_g_START (6)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_g_END (6)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_h_START (7)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_h_END (7)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_i_START (8)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_RAW_STAT_int_freq_vote_raw_stat_i_END (8)
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
        unsigned int reserved_0 : 7;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_INT_VOTE_STAT_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_STAT_int_freq_vote_stat_a_START (0)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_STAT_int_freq_vote_stat_a_END (0)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_STAT_int_freq_vote_stat_b_START (1)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_STAT_int_freq_vote_stat_b_END (1)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_STAT_int_freq_vote_stat_c_START (2)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_STAT_int_freq_vote_stat_c_END (2)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_STAT_int_freq_vote_stat_d_START (3)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_STAT_int_freq_vote_stat_d_END (3)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_STAT_int_freq_vote_stat_e_START (4)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_STAT_int_freq_vote_stat_e_END (4)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_STAT_int_freq_vote_stat_f_START (5)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_STAT_int_freq_vote_stat_f_END (5)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_STAT_int_freq_vote_stat_g_START (6)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_STAT_int_freq_vote_stat_g_END (6)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_STAT_int_freq_vote_stat_h_START (7)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_STAT_int_freq_vote_stat_h_END (7)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_STAT_int_freq_vote_stat_i_START (8)
#define SOC_PMCTRL_FREQ_VOTE_INT_VOTE_STAT_int_freq_vote_stat_i_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int int_frequency_vote : 1;
        unsigned int intr_freq_vote_to_cpu_lp_ctrl : 1;
        unsigned int intr_freq_vote_to_gpu_lp_ctrl : 1;
        unsigned int intr_freq_vote_to_ddr_lp_ctrl : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_INT_FREQUENCY_VOTE_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_INT_FREQUENCY_VOTE_int_frequency_vote_START (0)
#define SOC_PMCTRL_FREQ_VOTE_INT_FREQUENCY_VOTE_int_frequency_vote_END (0)
#define SOC_PMCTRL_FREQ_VOTE_INT_FREQUENCY_VOTE_intr_freq_vote_to_cpu_lp_ctrl_START (1)
#define SOC_PMCTRL_FREQ_VOTE_INT_FREQUENCY_VOTE_intr_freq_vote_to_cpu_lp_ctrl_END (1)
#define SOC_PMCTRL_FREQ_VOTE_INT_FREQUENCY_VOTE_intr_freq_vote_to_gpu_lp_ctrl_START (2)
#define SOC_PMCTRL_FREQ_VOTE_INT_FREQUENCY_VOTE_intr_freq_vote_to_gpu_lp_ctrl_END (2)
#define SOC_PMCTRL_FREQ_VOTE_INT_FREQUENCY_VOTE_intr_freq_vote_to_ddr_lp_ctrl_START (3)
#define SOC_PMCTRL_FREQ_VOTE_INT_FREQUENCY_VOTE_intr_freq_vote_to_ddr_lp_ctrl_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_result_a : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_A_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_A_freq_vote_result_a_START (0)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_A_freq_vote_result_a_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_result_b : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_B_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_B_freq_vote_result_b_START (0)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_B_freq_vote_result_b_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_result_c : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_C_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_C_freq_vote_result_c_START (0)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_C_freq_vote_result_c_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_result_d : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_D_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_D_freq_vote_result_d_START (0)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_D_freq_vote_result_d_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_result_e : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_E_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_E_freq_vote_result_e_START (0)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_E_freq_vote_result_e_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_result_f : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_F_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_F_freq_vote_result_f_START (0)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_F_freq_vote_result_f_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_result_g : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_G_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_G_freq_vote_result_g_START (0)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_G_freq_vote_result_g_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_result_h : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_H_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_H_freq_vote_result_h_START (0)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_H_freq_vote_result_h_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_result_i : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_I_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_I_freq_vote_result_i_START (0)
#define SOC_PMCTRL_FREQ_VOTE_VOTE_RESULT_I_freq_vote_result_i_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hard_reqack_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_HARD_REQACK_EN_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_HARD_REQACK_EN_hard_reqack_en_START (0)
#define SOC_PMCTRL_FREQ_VOTE_HARD_REQACK_EN_hard_reqack_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hard_int_freq_vote_i_clr_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_HARD_INT_FREQ_VOTE_I_CLR_EN_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_HARD_INT_FREQ_VOTE_I_CLR_EN_hard_int_freq_vote_i_clr_en_START (0)
#define SOC_PMCTRL_FREQ_VOTE_HARD_INT_FREQ_VOTE_I_CLR_EN_hard_int_freq_vote_i_clr_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int freq_vote_req : 1;
        unsigned int freq_vote_ack_sync : 1;
        unsigned int freq_vote_result : 20;
        unsigned int reserved : 10;
    } reg;
} SOC_PMCTRL_FREQ_VOTE_HARD_REQACK_INFO_UNION;
#endif
#define SOC_PMCTRL_FREQ_VOTE_HARD_REQACK_INFO_freq_vote_req_START (0)
#define SOC_PMCTRL_FREQ_VOTE_HARD_REQACK_INFO_freq_vote_req_END (0)
#define SOC_PMCTRL_FREQ_VOTE_HARD_REQACK_INFO_freq_vote_ack_sync_START (1)
#define SOC_PMCTRL_FREQ_VOTE_HARD_REQACK_INFO_freq_vote_ack_sync_END (1)
#define SOC_PMCTRL_FREQ_VOTE_HARD_REQACK_INFO_freq_vote_result_START (2)
#define SOC_PMCTRL_FREQ_VOTE_HARD_REQACK_INFO_freq_vote_result_END (21)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
