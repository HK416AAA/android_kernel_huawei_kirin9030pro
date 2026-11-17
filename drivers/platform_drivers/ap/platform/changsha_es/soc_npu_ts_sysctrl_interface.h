#ifndef __SOC_NPU_TS_SYSCTRL_INTERFACE_H__
#define __SOC_NPU_TS_SYSCTRL_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_TS_SYSCTRL_SC_SYSSTAT0_ADDR(base) ((base) + (0x0008UL))
#define SOC_NPU_TS_SYSCTRL_SC_SYSSTAT1_ADDR(base) ((base) + (0x000CUL))
#define SOC_NPU_TS_SYSCTRL_SC_SYSSTAT2_ADDR(base) ((base) + (0x0010UL))
#define SOC_NPU_TS_SYSCTRL_SC_SYSSTAT3_ADDR(base) ((base) + (0x0014UL))
#define SOC_NPU_TS_SYSCTRL_SC_SYSSTAT4_ADDR(base) ((base) + (0x0018UL))
#define SOC_NPU_TS_SYSCTRL_SC_SYSSTAT5_ADDR(base) ((base) + (0x001CUL))
#define SOC_NPU_TS_SYSCTRL_SC_SYSSTAT6_ADDR(base) ((base) + (0x0020UL))
#define SOC_NPU_TS_SYSCTRL_SC_SYSSTAT7_ADDR(base) ((base) + (0x0024UL))
#define SOC_NPU_TS_SYSCTRL_SC_SYSSTAT8_ADDR(base) ((base) + (0x0028UL))
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL1_ADDR(base) ((base) + (0x00A0UL))
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL5_ADDR(base) ((base) + (0x00A4UL))
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL6_ADDR(base) ((base) + (0x00A8UL))
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL7_ADDR(base) ((base) + (0x00ACUL))
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL8_ADDR(base) ((base) + (0x00B0UL))
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL9_ADDR(base) ((base) + (0x0B4UL))
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL10_ADDR(base) ((base) + (0x0B8UL))
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL11_ADDR(base) ((base) + (0x0BCUL))
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL12_ADDR(base) ((base) + (0x0C0UL))
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL13_ADDR(base) ((base) + (0x00C4UL))
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG0_ADDR(base) ((base) + (0x0BE0UL))
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG1_ADDR(base) ((base) + (0x0BE4UL))
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG2_ADDR(base) ((base) + (0x0BE8UL))
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG3_ADDR(base) ((base) + (0x0BECUL))
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG4_ADDR(base) ((base) + (0x0BF0UL))
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG5_ADDR(base) ((base) + (0x0BF4UL))
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG6_ADDR(base) ((base) + (0x0BF8UL))
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG7_ADDR(base) ((base) + (0x0BFCUL))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG0_ADDR(base) ((base) + (0x0C20UL))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG1_ADDR(base) ((base) + (0x0C24UL))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG2_ADDR(base) ((base) + (0x0C28UL))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG3_ADDR(base) ((base) + (0x0C2CUL))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG4_ADDR(base) ((base) + (0x0C30UL))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG5_ADDR(base) ((base) + (0x0C34UL))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG6_ADDR(base) ((base) + (0x0C38UL))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG7_ADDR(base) ((base) + (0x0C3CUL))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG8_ADDR(base) ((base) + (0x0C40UL))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG9_ADDR(base) ((base) + (0x0C44UL))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG10_ADDR(base) ((base) + (0x0C48UL))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG11_ADDR(base) ((base) + (0x0C4CUL))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG12_ADDR(base) ((base) + (0x0C50UL))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG13_ADDR(base) ((base) + (0x0C54UL))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG14_ADDR(base) ((base) + (0x0C58UL))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG15_ADDR(base) ((base) + (0x0C5CUL))
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG8_ADDR(base) ((base) + (0x0C00UL))
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG9_ADDR(base) ((base) + (0x0C04UL))
#else
#define SOC_NPU_TS_SYSCTRL_SC_SYSSTAT0_ADDR(base) ((base) + (0x0008))
#define SOC_NPU_TS_SYSCTRL_SC_SYSSTAT1_ADDR(base) ((base) + (0x000C))
#define SOC_NPU_TS_SYSCTRL_SC_SYSSTAT2_ADDR(base) ((base) + (0x0010))
#define SOC_NPU_TS_SYSCTRL_SC_SYSSTAT3_ADDR(base) ((base) + (0x0014))
#define SOC_NPU_TS_SYSCTRL_SC_SYSSTAT4_ADDR(base) ((base) + (0x0018))
#define SOC_NPU_TS_SYSCTRL_SC_SYSSTAT5_ADDR(base) ((base) + (0x001C))
#define SOC_NPU_TS_SYSCTRL_SC_SYSSTAT6_ADDR(base) ((base) + (0x0020))
#define SOC_NPU_TS_SYSCTRL_SC_SYSSTAT7_ADDR(base) ((base) + (0x0024))
#define SOC_NPU_TS_SYSCTRL_SC_SYSSTAT8_ADDR(base) ((base) + (0x0028))
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL1_ADDR(base) ((base) + (0x00A0))
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL5_ADDR(base) ((base) + (0x00A4))
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL6_ADDR(base) ((base) + (0x00A8))
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL7_ADDR(base) ((base) + (0x00AC))
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL8_ADDR(base) ((base) + (0x00B0))
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL9_ADDR(base) ((base) + (0x0B4))
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL10_ADDR(base) ((base) + (0x0B8))
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL11_ADDR(base) ((base) + (0x0BC))
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL12_ADDR(base) ((base) + (0x0C0))
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL13_ADDR(base) ((base) + (0x00C4))
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG0_ADDR(base) ((base) + (0x0BE0))
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG1_ADDR(base) ((base) + (0x0BE4))
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG2_ADDR(base) ((base) + (0x0BE8))
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG3_ADDR(base) ((base) + (0x0BEC))
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG4_ADDR(base) ((base) + (0x0BF0))
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG5_ADDR(base) ((base) + (0x0BF4))
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG6_ADDR(base) ((base) + (0x0BF8))
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG7_ADDR(base) ((base) + (0x0BFC))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG0_ADDR(base) ((base) + (0x0C20))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG1_ADDR(base) ((base) + (0x0C24))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG2_ADDR(base) ((base) + (0x0C28))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG3_ADDR(base) ((base) + (0x0C2C))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG4_ADDR(base) ((base) + (0x0C30))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG5_ADDR(base) ((base) + (0x0C34))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG6_ADDR(base) ((base) + (0x0C38))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG7_ADDR(base) ((base) + (0x0C3C))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG8_ADDR(base) ((base) + (0x0C40))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG9_ADDR(base) ((base) + (0x0C44))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG10_ADDR(base) ((base) + (0x0C48))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG11_ADDR(base) ((base) + (0x0C4C))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG12_ADDR(base) ((base) + (0x0C50))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG13_ADDR(base) ((base) + (0x0C54))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG14_ADDR(base) ((base) + (0x0C58))
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG15_ADDR(base) ((base) + (0x0C5C))
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG8_ADDR(base) ((base) + (0x0C00))
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG9_ADDR(base) ((base) + (0x0C04))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rv_core_hard_fault_mode : 1;
        unsigned int rv_core_debug_mode : 1;
        unsigned int rv_core_sleep_mode : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_SYSSTAT0_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_SYSSTAT0_rv_core_hard_fault_mode_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_SYSSTAT0_rv_core_hard_fault_mode_END (0)
#define SOC_NPU_TS_SYSCTRL_SC_SYSSTAT0_rv_core_debug_mode_START (1)
#define SOC_NPU_TS_SYSCTRL_SC_SYSSTAT0_rv_core_debug_mode_END (1)
#define SOC_NPU_TS_SYSCTRL_SC_SYSSTAT0_rv_core_sleep_mode_START (2)
#define SOC_NPU_TS_SYSCTRL_SC_SYSSTAT0_rv_core_sleep_mode_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_SYSSTAT1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_SYSSTAT2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_SYSSTAT3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_SYSSTAT4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_SYSSTAT5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_SYSSTAT6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_SYSSTAT7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_SYSSTAT8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arc_event_o : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_PERCTRL1_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL1_arc_event_o_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL1_arc_event_o_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_smmu_awsid : 8;
        unsigned int hwts_smmu_arsid : 8;
        unsigned int ts_cpu_smmu_awsid : 8;
        unsigned int ts_cpu_smmu_arsid : 8;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_PERCTRL5_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL5_hwts_smmu_awsid_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL5_hwts_smmu_awsid_END (7)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL5_hwts_smmu_arsid_START (8)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL5_hwts_smmu_arsid_END (15)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL5_ts_cpu_smmu_awsid_START (16)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL5_ts_cpu_smmu_awsid_END (23)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL5_ts_cpu_smmu_arsid_START (24)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL5_ts_cpu_smmu_arsid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ts_cpu_smmu_awssid : 12;
        unsigned int reserved_0 : 4;
        unsigned int ts_cpu_smmu_arssid : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_PERCTRL6_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL6_ts_cpu_smmu_awssid_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL6_ts_cpu_smmu_awssid_END (11)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL6_ts_cpu_smmu_arssid_START (16)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL6_ts_cpu_smmu_arssid_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_smmu_awssid : 12;
        unsigned int reserved_0 : 4;
        unsigned int hwts_smmu_arssid : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_PERCTRL7_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL7_hwts_smmu_awssid_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL7_hwts_smmu_awssid_END (11)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL7_hwts_smmu_arssid_START (16)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL7_hwts_smmu_arssid_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_smmu_awssidv : 1;
        unsigned int hwts_smmu_arssidv : 1;
        unsigned int ts_cpu_smmu_awssidv : 1;
        unsigned int ts_cpu_smmu_arssidv : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_PERCTRL8_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL8_hwts_smmu_awssidv_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL8_hwts_smmu_awssidv_END (0)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL8_hwts_smmu_arssidv_START (1)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL8_hwts_smmu_arssidv_END (1)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL8_ts_cpu_smmu_awssidv_START (2)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL8_ts_cpu_smmu_awssidv_END (2)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL8_ts_cpu_smmu_arssidv_START (3)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL8_ts_cpu_smmu_arssidv_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_ts_mem_ctrl_low : 2;
        unsigned int reserved_0 : 1;
        unsigned int sc_ts_mem_ctrl_hign : 23;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_PERCTRL9_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL9_sc_ts_mem_ctrl_low_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL9_sc_ts_mem_ctrl_low_END (1)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL9_sc_ts_mem_ctrl_hign_START (3)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL9_sc_ts_mem_ctrl_hign_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_pmu_mem_ctrl_tp_dlw2r_reg_l : 2;
        unsigned int reserved_0 : 1;
        unsigned int hwts_pmu_mem_ctrl_tp_dlw2r_reg_h : 13;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_PERCTRL10_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL10_hwts_pmu_mem_ctrl_tp_dlw2r_reg_l_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL10_hwts_pmu_mem_ctrl_tp_dlw2r_reg_l_END (1)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL10_hwts_pmu_mem_ctrl_tp_dlw2r_reg_h_START (3)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL10_hwts_pmu_mem_ctrl_tp_dlw2r_reg_h_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_pmu_mem_ctrl_s_reg_l : 2;
        unsigned int reserved_0 : 1;
        unsigned int hwts_pmu_mem_ctrl_s_reg_h : 23;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_PERCTRL11_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL11_hwts_pmu_mem_ctrl_s_reg_l_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL11_hwts_pmu_mem_ctrl_s_reg_l_END (1)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL11_hwts_pmu_mem_ctrl_s_reg_h_START (3)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL11_hwts_pmu_mem_ctrl_s_reg_h_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tscpu_dmmu_ar_gid_in : 6;
        unsigned int reserved_0 : 2;
        unsigned int tscpu_dmmu_aw_gid_in : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_PERCTRL12_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL12_tscpu_dmmu_ar_gid_in_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL12_tscpu_dmmu_ar_gid_in_END (5)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL12_tscpu_dmmu_aw_gid_in_START (8)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL12_tscpu_dmmu_aw_gid_in_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_smmu_svm_awsid : 8;
        unsigned int hwts_user_awssidv : 1;
        unsigned int reserved_0 : 7;
        unsigned int hwts_smmu_svm_arsid : 8;
        unsigned int hwts_user_arssidv : 1;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_PERCTRL13_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL13_hwts_smmu_svm_awsid_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL13_hwts_smmu_svm_awsid_END (7)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL13_hwts_user_awssidv_START (8)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL13_hwts_user_awssidv_END (8)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL13_hwts_smmu_svm_arsid_START (16)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL13_hwts_smmu_svm_arsid_END (23)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL13_hwts_user_arssidv_START (24)
#define SOC_NPU_TS_SYSCTRL_SC_PERCTRL13_hwts_user_arssidv_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int test_reg0 : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_TESTREG0_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG0_test_reg0_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG0_test_reg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int test_reg1 : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_TESTREG1_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG1_test_reg1_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG1_test_reg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int test_reg2 : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_TESTREG2_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG2_test_reg2_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG2_test_reg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int test_reg3 : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_TESTREG3_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG3_test_reg3_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG3_test_reg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int test_reg4 : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_TESTREG4_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG4_test_reg4_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG4_test_reg4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int test_reg5 : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_TESTREG5_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG5_test_reg5_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG5_test_reg5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int test_reg6 : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_TESTREG6_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG6_test_reg6_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG6_test_reg6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int test_reg7 : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_TESTREG7_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG7_test_reg7_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG7_test_reg7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sema_reg0 : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_SEMAREG0_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG0_sema_reg0_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG0_sema_reg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sema_reg1 : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_SEMAREG1_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG1_sema_reg1_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG1_sema_reg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sema_reg2 : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_SEMAREG2_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG2_sema_reg2_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG2_sema_reg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sema_reg3 : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_SEMAREG3_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG3_sema_reg3_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG3_sema_reg3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sema_reg4 : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_SEMAREG4_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG4_sema_reg4_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG4_sema_reg4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sema_reg5 : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_SEMAREG5_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG5_sema_reg5_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG5_sema_reg5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sema_reg6 : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_SEMAREG6_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG6_sema_reg6_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG6_sema_reg6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sema_reg7 : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_SEMAREG7_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG7_sema_reg7_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG7_sema_reg7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sema_reg8 : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_SEMAREG8_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG8_sema_reg8_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG8_sema_reg8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sema_reg9 : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_SEMAREG9_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG9_sema_reg9_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG9_sema_reg9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sema_reg10 : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_SEMAREG10_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG10_sema_reg10_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG10_sema_reg10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sema_reg11 : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_SEMAREG11_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG11_sema_reg11_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG11_sema_reg11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sema_reg12 : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_SEMAREG12_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG12_sema_reg12_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG12_sema_reg12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sema_reg13 : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_SEMAREG13_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG13_sema_reg13_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG13_sema_reg13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sema_reg14 : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_SEMAREG14_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG14_sema_reg14_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG14_sema_reg14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sema_reg15 : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_SEMAREG15_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG15_sema_reg15_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_SEMAREG15_sema_reg15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int test_reg8 : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_TESTREG8_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG8_test_reg8_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG8_test_reg8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int test_reg9 : 32;
    } reg;
} SOC_NPU_TS_SYSCTRL_SC_TESTREG9_UNION;
#endif
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG9_test_reg9_START (0)
#define SOC_NPU_TS_SYSCTRL_SC_TESTREG9_test_reg9_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
