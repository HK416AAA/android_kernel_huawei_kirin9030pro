#ifndef __SOC_CPU_FVT_INTERFACE_H__
#define __SOC_CPU_FVT_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_CPU_FVT_FVT_ASYNC_CG_OFF_ADDR(base) ((base) + (0x000UL))
#define SOC_CPU_FVT_FVT_TIMER_PWP_ADDR(base) ((base) + (0x010UL))
#define SOC_CPU_FVT_FVT_SW_SETTING_ADDR(base) ((base) + (0x014UL))
#define SOC_CPU_FVT_FVT_CURR_STATE_ADDR(base) ((base) + (0x110UL))
#define SOC_CPU_FVT_FVT_NEXT_STATE_ADDR(base) ((base) + (0x114UL))
#define SOC_CPU_FVT_FVT_UNIT_PERIOD_COUNT_ADDR(base) ((base) + (0x118UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_A_CORE0_ADDR(base) ((base) + (0x200UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_B_CORE0_ADDR(base) ((base) + (0x204UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_C_CORE0_ADDR(base) ((base) + (0x208UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_D_CORE0_ADDR(base) ((base) + (0x20CUL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_E_CORE0_ADDR(base) ((base) + (0x210UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_F_CORE0_ADDR(base) ((base) + (0x214UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_G_CORE0_ADDR(base) ((base) + (0x218UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_H_CORE0_ADDR(base) ((base) + (0x21CUL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_I_CORE0_ADDR(base) ((base) + (0x220UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_J_CORE0_ADDR(base) ((base) + (0x224UL))
#define SOC_CPU_FVT_PMU_UNIT_DELTA_COUNT_NUM_CORE0_DONE_ADDR(base) ((base) + (0x228UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_A_CORE1_ADDR(base) ((base) + (0x300UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_B_CORE1_ADDR(base) ((base) + (0x304UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_C_CORE1_ADDR(base) ((base) + (0x308UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_D_CORE1_ADDR(base) ((base) + (0x30CUL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_E_CORE1_ADDR(base) ((base) + (0x310UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_F_CORE1_ADDR(base) ((base) + (0x314UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_G_CORE1_ADDR(base) ((base) + (0x318UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_H_CORE1_ADDR(base) ((base) + (0x31CUL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_I_CORE1_ADDR(base) ((base) + (0x320UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_J_CORE1_ADDR(base) ((base) + (0x324UL))
#define SOC_CPU_FVT_PMU_UNIT_DELTA_COUNT_NUM_CORE1_DONE_ADDR(base) ((base) + (0x328UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_A_CORE2_ADDR(base) ((base) + (0x400UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_B_CORE2_ADDR(base) ((base) + (0x404UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_C_CORE2_ADDR(base) ((base) + (0x408UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_D_CORE2_ADDR(base) ((base) + (0x40CUL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_E_CORE2_ADDR(base) ((base) + (0x410UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_F_CORE2_ADDR(base) ((base) + (0x414UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_G_CORE2_ADDR(base) ((base) + (0x418UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_H_CORE2_ADDR(base) ((base) + (0x41CUL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_I_CORE2_ADDR(base) ((base) + (0x420UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_J_CORE2_ADDR(base) ((base) + (0x424UL))
#define SOC_CPU_FVT_PMU_UNIT_DELTA_COUNT_NUM_CORE2_DONE_ADDR(base) ((base) + (0x428UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_A_CORE3_ADDR(base) ((base) + (0x500UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_B_CORE3_ADDR(base) ((base) + (0x504UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_C_CORE3_ADDR(base) ((base) + (0x508UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_D_CORE3_ADDR(base) ((base) + (0x50CUL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_E_CORE3_ADDR(base) ((base) + (0x510UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_F_CORE3_ADDR(base) ((base) + (0x514UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_G_CORE3_ADDR(base) ((base) + (0x518UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_H_CORE3_ADDR(base) ((base) + (0x51CUL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_I_CORE3_ADDR(base) ((base) + (0x520UL))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_J_CORE3_ADDR(base) ((base) + (0x524UL))
#define SOC_CPU_FVT_PMU_UNIT_DELTA_COUNT_NUM_CORE3_DONE_ADDR(base) ((base) + (0x528UL))
#else
#define SOC_CPU_FVT_FVT_ASYNC_CG_OFF_ADDR(base) ((base) + (0x000))
#define SOC_CPU_FVT_FVT_TIMER_PWP_ADDR(base) ((base) + (0x010))
#define SOC_CPU_FVT_FVT_SW_SETTING_ADDR(base) ((base) + (0x014))
#define SOC_CPU_FVT_FVT_CURR_STATE_ADDR(base) ((base) + (0x110))
#define SOC_CPU_FVT_FVT_NEXT_STATE_ADDR(base) ((base) + (0x114))
#define SOC_CPU_FVT_FVT_UNIT_PERIOD_COUNT_ADDR(base) ((base) + (0x118))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_A_CORE0_ADDR(base) ((base) + (0x200))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_B_CORE0_ADDR(base) ((base) + (0x204))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_C_CORE0_ADDR(base) ((base) + (0x208))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_D_CORE0_ADDR(base) ((base) + (0x20C))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_E_CORE0_ADDR(base) ((base) + (0x210))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_F_CORE0_ADDR(base) ((base) + (0x214))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_G_CORE0_ADDR(base) ((base) + (0x218))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_H_CORE0_ADDR(base) ((base) + (0x21C))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_I_CORE0_ADDR(base) ((base) + (0x220))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_J_CORE0_ADDR(base) ((base) + (0x224))
#define SOC_CPU_FVT_PMU_UNIT_DELTA_COUNT_NUM_CORE0_DONE_ADDR(base) ((base) + (0x228))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_A_CORE1_ADDR(base) ((base) + (0x300))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_B_CORE1_ADDR(base) ((base) + (0x304))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_C_CORE1_ADDR(base) ((base) + (0x308))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_D_CORE1_ADDR(base) ((base) + (0x30C))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_E_CORE1_ADDR(base) ((base) + (0x310))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_F_CORE1_ADDR(base) ((base) + (0x314))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_G_CORE1_ADDR(base) ((base) + (0x318))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_H_CORE1_ADDR(base) ((base) + (0x31C))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_I_CORE1_ADDR(base) ((base) + (0x320))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_J_CORE1_ADDR(base) ((base) + (0x324))
#define SOC_CPU_FVT_PMU_UNIT_DELTA_COUNT_NUM_CORE1_DONE_ADDR(base) ((base) + (0x328))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_A_CORE2_ADDR(base) ((base) + (0x400))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_B_CORE2_ADDR(base) ((base) + (0x404))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_C_CORE2_ADDR(base) ((base) + (0x408))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_D_CORE2_ADDR(base) ((base) + (0x40C))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_E_CORE2_ADDR(base) ((base) + (0x410))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_F_CORE2_ADDR(base) ((base) + (0x414))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_G_CORE2_ADDR(base) ((base) + (0x418))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_H_CORE2_ADDR(base) ((base) + (0x41C))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_I_CORE2_ADDR(base) ((base) + (0x420))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_J_CORE2_ADDR(base) ((base) + (0x424))
#define SOC_CPU_FVT_PMU_UNIT_DELTA_COUNT_NUM_CORE2_DONE_ADDR(base) ((base) + (0x428))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_A_CORE3_ADDR(base) ((base) + (0x500))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_B_CORE3_ADDR(base) ((base) + (0x504))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_C_CORE3_ADDR(base) ((base) + (0x508))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_D_CORE3_ADDR(base) ((base) + (0x50C))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_E_CORE3_ADDR(base) ((base) + (0x510))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_F_CORE3_ADDR(base) ((base) + (0x514))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_G_CORE3_ADDR(base) ((base) + (0x518))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_H_CORE3_ADDR(base) ((base) + (0x51C))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_I_CORE3_ADDR(base) ((base) + (0x520))
#define SOC_CPU_FVT_PMU_DELTA_COUNT_J_CORE3_ADDR(base) ((base) + (0x524))
#define SOC_CPU_FVT_PMU_UNIT_DELTA_COUNT_NUM_CORE3_DONE_ADDR(base) ((base) + (0x528))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fvt_async_cg_off : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CPU_FVT_FVT_ASYNC_CG_OFF_UNION;
#endif
#define SOC_CPU_FVT_FVT_ASYNC_CG_OFF_fvt_async_cg_off_START (0)
#define SOC_CPU_FVT_FVT_ASYNC_CG_OFF_fvt_async_cg_off_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fvt_timer_pwp : 32;
    } reg;
} SOC_CPU_FVT_FVT_TIMER_PWP_UNION;
#endif
#define SOC_CPU_FVT_FVT_TIMER_PWP_fvt_timer_pwp_START (0)
#define SOC_CPU_FVT_FVT_TIMER_PWP_fvt_timer_pwp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fvt_timer_enable : 1;
        unsigned int fvt_kick_enable : 1;
        unsigned int reserved_0 : 6;
        unsigned int fvt_pulse_extend_cycle : 5;
        unsigned int reserved_1 : 3;
        unsigned int fvt_req_wait_cycle : 10;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_CPU_FVT_FVT_SW_SETTING_UNION;
#endif
#define SOC_CPU_FVT_FVT_SW_SETTING_fvt_timer_enable_START (0)
#define SOC_CPU_FVT_FVT_SW_SETTING_fvt_timer_enable_END (0)
#define SOC_CPU_FVT_FVT_SW_SETTING_fvt_kick_enable_START (1)
#define SOC_CPU_FVT_FVT_SW_SETTING_fvt_kick_enable_END (1)
#define SOC_CPU_FVT_FVT_SW_SETTING_fvt_pulse_extend_cycle_START (8)
#define SOC_CPU_FVT_FVT_SW_SETTING_fvt_pulse_extend_cycle_END (12)
#define SOC_CPU_FVT_FVT_SW_SETTING_fvt_req_wait_cycle_START (16)
#define SOC_CPU_FVT_FVT_SW_SETTING_fvt_req_wait_cycle_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fvt_curr_state : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CPU_FVT_FVT_CURR_STATE_UNION;
#endif
#define SOC_CPU_FVT_FVT_CURR_STATE_fvt_curr_state_START (0)
#define SOC_CPU_FVT_FVT_CURR_STATE_fvt_curr_state_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fvt_next_state : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CPU_FVT_FVT_NEXT_STATE_UNION;
#endif
#define SOC_CPU_FVT_FVT_NEXT_STATE_fvt_next_state_START (0)
#define SOC_CPU_FVT_FVT_NEXT_STATE_fvt_next_state_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fvt_unit_period_count : 8;
        unsigned int fvt_unit_period_finish_clr : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_CPU_FVT_FVT_UNIT_PERIOD_COUNT_UNION;
#endif
#define SOC_CPU_FVT_FVT_UNIT_PERIOD_COUNT_fvt_unit_period_count_START (0)
#define SOC_CPU_FVT_FVT_UNIT_PERIOD_COUNT_fvt_unit_period_count_END (7)
#define SOC_CPU_FVT_FVT_UNIT_PERIOD_COUNT_fvt_unit_period_finish_clr_START (8)
#define SOC_CPU_FVT_FVT_UNIT_PERIOD_COUNT_fvt_unit_period_finish_clr_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_a_core0 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_A_CORE0_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_A_CORE0_pmu_delta_count_a_core0_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_A_CORE0_pmu_delta_count_a_core0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_b_core0 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_B_CORE0_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_B_CORE0_pmu_delta_count_b_core0_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_B_CORE0_pmu_delta_count_b_core0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_c_core0 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_C_CORE0_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_C_CORE0_pmu_delta_count_c_core0_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_C_CORE0_pmu_delta_count_c_core0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_d_core0 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_D_CORE0_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_D_CORE0_pmu_delta_count_d_core0_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_D_CORE0_pmu_delta_count_d_core0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_e_core0 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_E_CORE0_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_E_CORE0_pmu_delta_count_e_core0_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_E_CORE0_pmu_delta_count_e_core0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_f_core0 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_F_CORE0_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_F_CORE0_pmu_delta_count_f_core0_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_F_CORE0_pmu_delta_count_f_core0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_g_core0 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_G_CORE0_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_G_CORE0_pmu_delta_count_g_core0_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_G_CORE0_pmu_delta_count_g_core0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_h_core0 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_H_CORE0_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_H_CORE0_pmu_delta_count_h_core0_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_H_CORE0_pmu_delta_count_h_core0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_i_core0 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_I_CORE0_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_I_CORE0_pmu_delta_count_i_core0_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_I_CORE0_pmu_delta_count_i_core0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_j_core0 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_J_CORE0_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_J_CORE0_pmu_delta_count_j_core0_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_J_CORE0_pmu_delta_count_j_core0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_unit_delta_count_num_core0_done : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_CPU_FVT_PMU_UNIT_DELTA_COUNT_NUM_CORE0_DONE_UNION;
#endif
#define SOC_CPU_FVT_PMU_UNIT_DELTA_COUNT_NUM_CORE0_DONE_pmu_unit_delta_count_num_core0_done_START (0)
#define SOC_CPU_FVT_PMU_UNIT_DELTA_COUNT_NUM_CORE0_DONE_pmu_unit_delta_count_num_core0_done_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_a_core1 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_A_CORE1_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_A_CORE1_pmu_delta_count_a_core1_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_A_CORE1_pmu_delta_count_a_core1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_b_core1 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_B_CORE1_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_B_CORE1_pmu_delta_count_b_core1_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_B_CORE1_pmu_delta_count_b_core1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_c_core1 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_C_CORE1_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_C_CORE1_pmu_delta_count_c_core1_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_C_CORE1_pmu_delta_count_c_core1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_d_core1 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_D_CORE1_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_D_CORE1_pmu_delta_count_d_core1_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_D_CORE1_pmu_delta_count_d_core1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_e_core1 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_E_CORE1_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_E_CORE1_pmu_delta_count_e_core1_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_E_CORE1_pmu_delta_count_e_core1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_f_core1 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_F_CORE1_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_F_CORE1_pmu_delta_count_f_core1_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_F_CORE1_pmu_delta_count_f_core1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_g_core1 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_G_CORE1_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_G_CORE1_pmu_delta_count_g_core1_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_G_CORE1_pmu_delta_count_g_core1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_h_core1 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_H_CORE1_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_H_CORE1_pmu_delta_count_h_core1_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_H_CORE1_pmu_delta_count_h_core1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_i_core1 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_I_CORE1_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_I_CORE1_pmu_delta_count_i_core1_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_I_CORE1_pmu_delta_count_i_core1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_j_core1 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_J_CORE1_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_J_CORE1_pmu_delta_count_j_core1_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_J_CORE1_pmu_delta_count_j_core1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_unit_delta_count_num_core1_done : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_CPU_FVT_PMU_UNIT_DELTA_COUNT_NUM_CORE1_DONE_UNION;
#endif
#define SOC_CPU_FVT_PMU_UNIT_DELTA_COUNT_NUM_CORE1_DONE_pmu_unit_delta_count_num_core1_done_START (0)
#define SOC_CPU_FVT_PMU_UNIT_DELTA_COUNT_NUM_CORE1_DONE_pmu_unit_delta_count_num_core1_done_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_a_core2 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_A_CORE2_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_A_CORE2_pmu_delta_count_a_core2_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_A_CORE2_pmu_delta_count_a_core2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_b_core2 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_B_CORE2_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_B_CORE2_pmu_delta_count_b_core2_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_B_CORE2_pmu_delta_count_b_core2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_c_core2 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_C_CORE2_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_C_CORE2_pmu_delta_count_c_core2_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_C_CORE2_pmu_delta_count_c_core2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_d_core2 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_D_CORE2_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_D_CORE2_pmu_delta_count_d_core2_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_D_CORE2_pmu_delta_count_d_core2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_e_core2 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_E_CORE2_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_E_CORE2_pmu_delta_count_e_core2_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_E_CORE2_pmu_delta_count_e_core2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_f_core2 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_F_CORE2_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_F_CORE2_pmu_delta_count_f_core2_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_F_CORE2_pmu_delta_count_f_core2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_g_core2 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_G_CORE2_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_G_CORE2_pmu_delta_count_g_core2_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_G_CORE2_pmu_delta_count_g_core2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_h_core2 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_H_CORE2_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_H_CORE2_pmu_delta_count_h_core2_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_H_CORE2_pmu_delta_count_h_core2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_i_core2 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_I_CORE2_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_I_CORE2_pmu_delta_count_i_core2_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_I_CORE2_pmu_delta_count_i_core2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_j_core2 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_J_CORE2_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_J_CORE2_pmu_delta_count_j_core2_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_J_CORE2_pmu_delta_count_j_core2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_unit_delta_count_num_core2_done : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_CPU_FVT_PMU_UNIT_DELTA_COUNT_NUM_CORE2_DONE_UNION;
#endif
#define SOC_CPU_FVT_PMU_UNIT_DELTA_COUNT_NUM_CORE2_DONE_pmu_unit_delta_count_num_core2_done_START (0)
#define SOC_CPU_FVT_PMU_UNIT_DELTA_COUNT_NUM_CORE2_DONE_pmu_unit_delta_count_num_core2_done_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_a_core3 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_A_CORE3_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_A_CORE3_pmu_delta_count_a_core3_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_A_CORE3_pmu_delta_count_a_core3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_b_core3 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_B_CORE3_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_B_CORE3_pmu_delta_count_b_core3_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_B_CORE3_pmu_delta_count_b_core3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_c_core3 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_C_CORE3_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_C_CORE3_pmu_delta_count_c_core3_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_C_CORE3_pmu_delta_count_c_core3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_d_core3 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_D_CORE3_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_D_CORE3_pmu_delta_count_d_core3_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_D_CORE3_pmu_delta_count_d_core3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_e_core3 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_E_CORE3_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_E_CORE3_pmu_delta_count_e_core3_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_E_CORE3_pmu_delta_count_e_core3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_f_core3 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_F_CORE3_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_F_CORE3_pmu_delta_count_f_core3_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_F_CORE3_pmu_delta_count_f_core3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_g_core3 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_G_CORE3_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_G_CORE3_pmu_delta_count_g_core3_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_G_CORE3_pmu_delta_count_g_core3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_h_core3 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_H_CORE3_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_H_CORE3_pmu_delta_count_h_core3_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_H_CORE3_pmu_delta_count_h_core3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_i_core3 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_I_CORE3_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_I_CORE3_pmu_delta_count_i_core3_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_I_CORE3_pmu_delta_count_i_core3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_delta_count_j_core3 : 32;
    } reg;
} SOC_CPU_FVT_PMU_DELTA_COUNT_J_CORE3_UNION;
#endif
#define SOC_CPU_FVT_PMU_DELTA_COUNT_J_CORE3_pmu_delta_count_j_core3_START (0)
#define SOC_CPU_FVT_PMU_DELTA_COUNT_J_CORE3_pmu_delta_count_j_core3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_unit_delta_count_num_core3_done : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_CPU_FVT_PMU_UNIT_DELTA_COUNT_NUM_CORE3_DONE_UNION;
#endif
#define SOC_CPU_FVT_PMU_UNIT_DELTA_COUNT_NUM_CORE3_DONE_pmu_unit_delta_count_num_core3_done_START (0)
#define SOC_CPU_FVT_PMU_UNIT_DELTA_COUNT_NUM_CORE3_DONE_pmu_unit_delta_count_num_core3_done_END (9)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
