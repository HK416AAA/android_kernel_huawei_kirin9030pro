#ifndef __SOC_PMCTRL_UNIT_XPU_INTERFACE_H__
#define __SOC_PMCTRL_UNIT_XPU_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_PMCTRL_UNIT_XPU_PDVFS_INSTR_LIST_ADDR(base,ma) ((base) + (0x000+(ma)*4UL))
#define SOC_PMCTRL_UNIT_XPU_PWR_UP_INSTR_LIST_ADDR(base,mb) ((base) + (0x080+(mb)*4UL))
#define SOC_PMCTRL_UNIT_XPU_PWR_DN_INSTR_LIST_ADDR(base,mb) ((base) + (0x0C0+(mb)*4UL))
#define SOC_PMCTRL_UNIT_XPU_SC_ENTER_DOZE_INSTR_LIST_ADDR(base,mc) ((base) + (0x100+(mc)*4UL))
#define SOC_PMCTRL_UNIT_XPU_SC_EXIT_DOZE_INSTR_LIST_ADDR(base,mc) ((base) + (0x140+(mc)*4UL))
#define SOC_PMCTRL_UNIT_XPU_MASTER_SOURCE_ID_ADDR(base) ((base) + (0x180UL))
#define SOC_PMCTRL_UNIT_XPU_MASTER_STAT_ADDR(base) ((base) + (0x184UL))
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_CTRL_ADDR(base) ((base) + (0x18CUL))
#define SOC_PMCTRL_UNIT_XPU_XPU_PMC_AUTO_CLKGT_BYPASS_ADDR(base) ((base) + (0x200UL))
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_ADDR(base) ((base) + (0x204UL))
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_0_ADDR(base) ((base) + (0x208UL))
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_1_ADDR(base) ((base) + (0x20CUL))
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_2_ADDR(base) ((base) + (0x210UL))
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_3_ADDR(base) ((base) + (0x214UL))
#define SOC_PMCTRL_UNIT_XPU_XPU_PMC_POLL_WAIT_EN_ADDR(base) ((base) + (0x218UL))
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_ADDR(base) ((base) + (0x220UL))
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL1_ADDR(base) ((base) + (0x224UL))
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_STAT_ADDR(base) ((base) + (0x228UL))
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL1_STAT_ADDR(base) ((base) + (0x22CUL))
#define SOC_PMCTRL_UNIT_XPU_APLL_0_SW_DVFS_INITIAL0_ADDR(base) ((base) + (0x230UL))
#define SOC_PMCTRL_UNIT_XPU_APLL_0_SW_DVFS_INITIAL1_ADDR(base) ((base) + (0x234UL))
#define SOC_PMCTRL_UNIT_XPU_APLL_0_SW_PWRUPDN_INITIAL0_ADDR(base) ((base) + (0x238UL))
#define SOC_PMCTRL_UNIT_XPU_APLL_0_SW_PWRUPDN_INITIAL1_ADDR(base) ((base) + (0x23CUL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_0_ADDR(base) ((base) + (0x260UL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_1_ADDR(base) ((base) + (0x264UL))
#define SOC_PMCTRL_UNIT_XPU_SVFD_FREQ_DOWM_CTRL_ADDR(base) ((base) + (0x268UL))
#define SOC_PMCTRL_UNIT_XPU_SVFD_FREQ_CTRL0_ADDR(base) ((base) + (0x26CUL))
#define SOC_PMCTRL_UNIT_XPU_FINE_STEP_FREQ_CTRL_BYPASS_ADDR(base) ((base) + (0x270UL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_CTRL_SRC_ADDR(base) ((base) + (0x300UL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_SRC_ADDR(base) ((base) + (0x304UL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_FREQ_CTRL_SRC_ADDR(base) ((base) + (0x308UL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_0_ADDR(base) ((base) + (0x310UL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_1_ADDR(base) ((base) + (0x314UL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_2_ADDR(base) ((base) + (0x318UL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_0_ADDR(base) ((base) + (0x31CUL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_1_ADDR(base) ((base) + (0x320UL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_ADDR(base) ((base) + (0x324UL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_TRIM_STAT_ADDR(base) ((base) + (0x3ACUL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_0_ADDR(base) ((base) + (0x330UL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_1_ADDR(base) ((base) + (0x334UL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_2_ADDR(base) ((base) + (0x338UL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_0_ADDR(base) ((base) + (0x33CUL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_1_ADDR(base) ((base) + (0x340UL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_ADDR(base) ((base) + (0x344UL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_ADDR(base) ((base) + (0x370UL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_VDM_STAT_ADDR(base) ((base) + (0x374UL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_ADDR(base) ((base) + (0x240UL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_STAT_0_ADDR(base) ((base) + (0x244UL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_LOGIC_TIME_0_ADDR(base) ((base) + (0x380UL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_LOGIC_TIME_1_ADDR(base) ((base) + (0x384UL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_LOGIC_TIME_2_ADDR(base) ((base) + (0x388UL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_LOGIC_TIME_3_ADDR(base) ((base) + (0x38CUL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_MEM_TIME_0_ADDR(base) ((base) + (0x390UL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_MEM_TIME_1_ADDR(base) ((base) + (0x394UL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_MEM_TIME_2_ADDR(base) ((base) + (0x398UL))
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_MEM_TIME_3_ADDR(base) ((base) + (0x39CUL))
#define SOC_PMCTRL_UNIT_XPU_TIME_PARAMETER_CFG_0_ADDR(base) ((base) + (0x3A4UL))
#define SOC_PMCTRL_UNIT_XPU_TIME_PARAMETER_CFG_1_ADDR(base) ((base) + (0x3A8UL))
#else
#define SOC_PMCTRL_UNIT_XPU_PDVFS_INSTR_LIST_ADDR(base,ma) ((base) + (0x000+(ma)*4))
#define SOC_PMCTRL_UNIT_XPU_PWR_UP_INSTR_LIST_ADDR(base,mb) ((base) + (0x080+(mb)*4))
#define SOC_PMCTRL_UNIT_XPU_PWR_DN_INSTR_LIST_ADDR(base,mb) ((base) + (0x0C0+(mb)*4))
#define SOC_PMCTRL_UNIT_XPU_SC_ENTER_DOZE_INSTR_LIST_ADDR(base,mc) ((base) + (0x100+(mc)*4))
#define SOC_PMCTRL_UNIT_XPU_SC_EXIT_DOZE_INSTR_LIST_ADDR(base,mc) ((base) + (0x140+(mc)*4))
#define SOC_PMCTRL_UNIT_XPU_MASTER_SOURCE_ID_ADDR(base) ((base) + (0x180))
#define SOC_PMCTRL_UNIT_XPU_MASTER_STAT_ADDR(base) ((base) + (0x184))
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_CTRL_ADDR(base) ((base) + (0x18C))
#define SOC_PMCTRL_UNIT_XPU_XPU_PMC_AUTO_CLKGT_BYPASS_ADDR(base) ((base) + (0x200))
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_ADDR(base) ((base) + (0x204))
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_0_ADDR(base) ((base) + (0x208))
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_1_ADDR(base) ((base) + (0x20C))
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_2_ADDR(base) ((base) + (0x210))
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_3_ADDR(base) ((base) + (0x214))
#define SOC_PMCTRL_UNIT_XPU_XPU_PMC_POLL_WAIT_EN_ADDR(base) ((base) + (0x218))
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_ADDR(base) ((base) + (0x220))
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL1_ADDR(base) ((base) + (0x224))
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_STAT_ADDR(base) ((base) + (0x228))
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL1_STAT_ADDR(base) ((base) + (0x22C))
#define SOC_PMCTRL_UNIT_XPU_APLL_0_SW_DVFS_INITIAL0_ADDR(base) ((base) + (0x230))
#define SOC_PMCTRL_UNIT_XPU_APLL_0_SW_DVFS_INITIAL1_ADDR(base) ((base) + (0x234))
#define SOC_PMCTRL_UNIT_XPU_APLL_0_SW_PWRUPDN_INITIAL0_ADDR(base) ((base) + (0x238))
#define SOC_PMCTRL_UNIT_XPU_APLL_0_SW_PWRUPDN_INITIAL1_ADDR(base) ((base) + (0x23C))
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_0_ADDR(base) ((base) + (0x260))
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_1_ADDR(base) ((base) + (0x264))
#define SOC_PMCTRL_UNIT_XPU_SVFD_FREQ_DOWM_CTRL_ADDR(base) ((base) + (0x268))
#define SOC_PMCTRL_UNIT_XPU_SVFD_FREQ_CTRL0_ADDR(base) ((base) + (0x26C))
#define SOC_PMCTRL_UNIT_XPU_FINE_STEP_FREQ_CTRL_BYPASS_ADDR(base) ((base) + (0x270))
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_CTRL_SRC_ADDR(base) ((base) + (0x300))
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_SRC_ADDR(base) ((base) + (0x304))
#define SOC_PMCTRL_UNIT_XPU_COFSM_FREQ_CTRL_SRC_ADDR(base) ((base) + (0x308))
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_0_ADDR(base) ((base) + (0x310))
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_1_ADDR(base) ((base) + (0x314))
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_2_ADDR(base) ((base) + (0x318))
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_0_ADDR(base) ((base) + (0x31C))
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_1_ADDR(base) ((base) + (0x320))
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_ADDR(base) ((base) + (0x324))
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_TRIM_STAT_ADDR(base) ((base) + (0x3AC))
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_0_ADDR(base) ((base) + (0x330))
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_1_ADDR(base) ((base) + (0x334))
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_2_ADDR(base) ((base) + (0x338))
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_0_ADDR(base) ((base) + (0x33C))
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_1_ADDR(base) ((base) + (0x340))
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_ADDR(base) ((base) + (0x344))
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_ADDR(base) ((base) + (0x370))
#define SOC_PMCTRL_UNIT_XPU_COFSM_VDM_STAT_ADDR(base) ((base) + (0x374))
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_ADDR(base) ((base) + (0x240))
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_STAT_0_ADDR(base) ((base) + (0x244))
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_LOGIC_TIME_0_ADDR(base) ((base) + (0x380))
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_LOGIC_TIME_1_ADDR(base) ((base) + (0x384))
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_LOGIC_TIME_2_ADDR(base) ((base) + (0x388))
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_LOGIC_TIME_3_ADDR(base) ((base) + (0x38C))
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_MEM_TIME_0_ADDR(base) ((base) + (0x390))
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_MEM_TIME_1_ADDR(base) ((base) + (0x394))
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_MEM_TIME_2_ADDR(base) ((base) + (0x398))
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_MEM_TIME_3_ADDR(base) ((base) + (0x39C))
#define SOC_PMCTRL_UNIT_XPU_TIME_PARAMETER_CFG_0_ADDR(base) ((base) + (0x3A4))
#define SOC_PMCTRL_UNIT_XPU_TIME_PARAMETER_CFG_1_ADDR(base) ((base) + (0x3A8))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_UNIT_XPU_PDVFS_INSTR_LIST_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_UNIT_XPU_PWR_UP_INSTR_LIST_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_UNIT_XPU_PWR_DN_INSTR_LIST_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_UNIT_XPU_SC_ENTER_DOZE_INSTR_LIST_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_UNIT_XPU_SC_EXIT_DOZE_INSTR_LIST_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pwr_updn_id : 4;
        unsigned int sc_doze_dvfs_id : 4;
        unsigned int dvfs_sft_id : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_PMCTRL_UNIT_XPU_MASTER_SOURCE_ID_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_MASTER_SOURCE_ID_pwr_updn_id_START (0)
#define SOC_PMCTRL_UNIT_XPU_MASTER_SOURCE_ID_pwr_updn_id_END (3)
#define SOC_PMCTRL_UNIT_XPU_MASTER_SOURCE_ID_sc_doze_dvfs_id_START (4)
#define SOC_PMCTRL_UNIT_XPU_MASTER_SOURCE_ID_sc_doze_dvfs_id_END (7)
#define SOC_PMCTRL_UNIT_XPU_MASTER_SOURCE_ID_dvfs_sft_id_START (8)
#define SOC_PMCTRL_UNIT_XPU_MASTER_SOURCE_ID_dvfs_sft_id_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pwr_updn_flag_sync : 1;
        unsigned int pwr_updn_ack : 1;
        unsigned int sc_doze_flag_sync : 1;
        unsigned int sc_doze_dvfs_ack : 1;
        unsigned int resource_lock_id : 4;
        unsigned int dvfs_skip_flag : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_PMCTRL_UNIT_XPU_MASTER_STAT_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_MASTER_STAT_pwr_updn_flag_sync_START (0)
#define SOC_PMCTRL_UNIT_XPU_MASTER_STAT_pwr_updn_flag_sync_END (0)
#define SOC_PMCTRL_UNIT_XPU_MASTER_STAT_pwr_updn_ack_START (1)
#define SOC_PMCTRL_UNIT_XPU_MASTER_STAT_pwr_updn_ack_END (1)
#define SOC_PMCTRL_UNIT_XPU_MASTER_STAT_sc_doze_flag_sync_START (2)
#define SOC_PMCTRL_UNIT_XPU_MASTER_STAT_sc_doze_flag_sync_END (2)
#define SOC_PMCTRL_UNIT_XPU_MASTER_STAT_sc_doze_dvfs_ack_START (3)
#define SOC_PMCTRL_UNIT_XPU_MASTER_STAT_sc_doze_dvfs_ack_END (3)
#define SOC_PMCTRL_UNIT_XPU_MASTER_STAT_resource_lock_id_START (4)
#define SOC_PMCTRL_UNIT_XPU_MASTER_STAT_resource_lock_id_END (7)
#define SOC_PMCTRL_UNIT_XPU_MASTER_STAT_dvfs_skip_flag_START (8)
#define SOC_PMCTRL_UNIT_XPU_MASTER_STAT_dvfs_skip_flag_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int taskctrl_intr_dvfs_en : 1;
        unsigned int taskctrl_intr_dvfs_clr : 1;
        unsigned int taskctrl_intr_dvfs_raw_stat : 1;
        unsigned int taskctrl_intr_dvfs_stat : 1;
        unsigned int pwr_up_sft_ini_pulse : 1;
        unsigned int pwr_dn_sft_ini_pulse : 1;
        unsigned int reserved_1 : 25;
    } reg;
} SOC_PMCTRL_UNIT_XPU_TASKCTRL_CTRL_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_CTRL_taskctrl_intr_dvfs_en_START (1)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_CTRL_taskctrl_intr_dvfs_en_END (1)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_CTRL_taskctrl_intr_dvfs_clr_START (2)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_CTRL_taskctrl_intr_dvfs_clr_END (2)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_CTRL_taskctrl_intr_dvfs_raw_stat_START (3)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_CTRL_taskctrl_intr_dvfs_raw_stat_END (3)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_CTRL_taskctrl_intr_dvfs_stat_START (4)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_CTRL_taskctrl_intr_dvfs_stat_END (4)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_CTRL_pwr_up_sft_ini_pulse_START (5)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_CTRL_pwr_up_sft_ini_pulse_END (5)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_CTRL_pwr_dn_sft_ini_pulse_START (6)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_CTRL_pwr_dn_sft_ini_pulse_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int auto_clkgt_taslctrl_bypass : 1;
        unsigned int cofsm_auto_clkgt_vol_hs_bypass : 1;
        unsigned int cofsm_auto_clkgt_logic_dvs_bypass : 1;
        unsigned int cofsm_auto_clkgt_mem_dvs_bypass : 1;
        unsigned int cofsm_auto_clkgt_apll_ctrl_bypass : 1;
        unsigned int auto_clkgt_apll_cfg_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 24;
    } reg;
} SOC_PMCTRL_UNIT_XPU_XPU_PMC_AUTO_CLKGT_BYPASS_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_XPU_PMC_AUTO_CLKGT_BYPASS_auto_clkgt_taslctrl_bypass_START (0)
#define SOC_PMCTRL_UNIT_XPU_XPU_PMC_AUTO_CLKGT_BYPASS_auto_clkgt_taslctrl_bypass_END (0)
#define SOC_PMCTRL_UNIT_XPU_XPU_PMC_AUTO_CLKGT_BYPASS_cofsm_auto_clkgt_vol_hs_bypass_START (1)
#define SOC_PMCTRL_UNIT_XPU_XPU_PMC_AUTO_CLKGT_BYPASS_cofsm_auto_clkgt_vol_hs_bypass_END (1)
#define SOC_PMCTRL_UNIT_XPU_XPU_PMC_AUTO_CLKGT_BYPASS_cofsm_auto_clkgt_logic_dvs_bypass_START (2)
#define SOC_PMCTRL_UNIT_XPU_XPU_PMC_AUTO_CLKGT_BYPASS_cofsm_auto_clkgt_logic_dvs_bypass_END (2)
#define SOC_PMCTRL_UNIT_XPU_XPU_PMC_AUTO_CLKGT_BYPASS_cofsm_auto_clkgt_mem_dvs_bypass_START (3)
#define SOC_PMCTRL_UNIT_XPU_XPU_PMC_AUTO_CLKGT_BYPASS_cofsm_auto_clkgt_mem_dvs_bypass_END (3)
#define SOC_PMCTRL_UNIT_XPU_XPU_PMC_AUTO_CLKGT_BYPASS_cofsm_auto_clkgt_apll_ctrl_bypass_START (4)
#define SOC_PMCTRL_UNIT_XPU_XPU_PMC_AUTO_CLKGT_BYPASS_cofsm_auto_clkgt_apll_ctrl_bypass_END (4)
#define SOC_PMCTRL_UNIT_XPU_XPU_PMC_AUTO_CLKGT_BYPASS_auto_clkgt_apll_cfg_bypass_START (5)
#define SOC_PMCTRL_UNIT_XPU_XPU_PMC_AUTO_CLKGT_BYPASS_auto_clkgt_apll_cfg_bypass_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int taskctrl_enable : 1;
        unsigned int taskctrl_instr_clr : 1;
        unsigned int taskctrl_instr_lock : 1;
        unsigned int reserved_0 : 1;
        unsigned int pwr_dn_instr_clr : 1;
        unsigned int pwr_dn_instr_lock : 1;
        unsigned int pwr_up_instr_clr : 1;
        unsigned int pwr_up_instr_lock : 1;
        unsigned int instr_update_enable : 1;
        unsigned int instr_update_req : 1;
        unsigned int instr_update_revoke : 1;
        unsigned int sc_exit_doze_dvfs_instr_clr : 1;
        unsigned int sc_exit_doze_dvfs_instr_lock : 1;
        unsigned int sc_enter_doze_dvfs_instr_clr : 1;
        unsigned int sc_enter_doze_dvfs_instr_lock : 1;
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
        unsigned int reserved_13 : 5;
    } reg;
} SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_taskctrl_enable_START (0)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_taskctrl_enable_END (0)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_taskctrl_instr_clr_START (1)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_taskctrl_instr_clr_END (1)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_taskctrl_instr_lock_START (2)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_taskctrl_instr_lock_END (2)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_pwr_dn_instr_clr_START (4)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_pwr_dn_instr_clr_END (4)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_pwr_dn_instr_lock_START (5)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_pwr_dn_instr_lock_END (5)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_pwr_up_instr_clr_START (6)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_pwr_up_instr_clr_END (6)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_pwr_up_instr_lock_START (7)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_pwr_up_instr_lock_END (7)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_instr_update_enable_START (8)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_instr_update_enable_END (8)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_instr_update_req_START (9)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_instr_update_req_END (9)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_instr_update_revoke_START (10)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_instr_update_revoke_END (10)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_sc_exit_doze_dvfs_instr_clr_START (11)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_sc_exit_doze_dvfs_instr_clr_END (11)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_sc_exit_doze_dvfs_instr_lock_START (12)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_sc_exit_doze_dvfs_instr_lock_END (12)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_sc_enter_doze_dvfs_instr_clr_START (13)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_sc_enter_doze_dvfs_instr_clr_END (13)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_sc_enter_doze_dvfs_instr_lock_START (14)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_INSTR_CTRL_sc_enter_doze_dvfs_instr_lock_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int taskctrl_dvfs_sft_en : 1;
        unsigned int taskctrl_next_step_cfg : 1;
        unsigned int taskctrl_escape_cfg : 1;
        unsigned int taskctrl_invalid_instr_flag_clr : 1;
        unsigned int taskctrl_invalid_instr_flag : 1;
        unsigned int taskctrl_halt_flag : 1;
        unsigned int reserved_0 : 2;
        unsigned int taskctrl_cur_decoding_instr_addr : 12;
        unsigned int taskctrl_cur_fetch_num : 8;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_PMCTRL_UNIT_XPU_TASKCTRL_0_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_0_taskctrl_dvfs_sft_en_START (0)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_0_taskctrl_dvfs_sft_en_END (0)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_0_taskctrl_next_step_cfg_START (1)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_0_taskctrl_next_step_cfg_END (1)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_0_taskctrl_escape_cfg_START (2)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_0_taskctrl_escape_cfg_END (2)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_0_taskctrl_invalid_instr_flag_clr_START (3)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_0_taskctrl_invalid_instr_flag_clr_END (3)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_0_taskctrl_invalid_instr_flag_START (4)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_0_taskctrl_invalid_instr_flag_END (4)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_0_taskctrl_halt_flag_START (5)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_0_taskctrl_halt_flag_END (5)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_0_taskctrl_cur_decoding_instr_addr_START (8)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_0_taskctrl_cur_decoding_instr_addr_END (19)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_0_taskctrl_cur_fetch_num_START (20)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_0_taskctrl_cur_fetch_num_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int taskctrl_cur_task_stat : 8;
        unsigned int taskctrl_num_of_end_instr : 8;
        unsigned int reserved_0 : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_PMCTRL_UNIT_XPU_TASKCTRL_1_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_1_taskctrl_cur_task_stat_START (0)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_1_taskctrl_cur_task_stat_END (7)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_1_taskctrl_num_of_end_instr_START (8)
#define SOC_PMCTRL_UNIT_XPU_TASKCTRL_1_taskctrl_num_of_end_instr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 8;
        unsigned int reserved_2: 12;
        unsigned int reserved_3: 4;
    } reg;
} SOC_PMCTRL_UNIT_XPU_TASKCTRL_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 8;
        unsigned int reserved_2: 12;
        unsigned int reserved_3: 4;
    } reg;
} SOC_PMCTRL_UNIT_XPU_TASKCTRL_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int taskctrl_poll_wait_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 28;
    } reg;
} SOC_PMCTRL_UNIT_XPU_XPU_PMC_POLL_WAIT_EN_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_XPU_PMC_POLL_WAIT_EN_taskctrl_poll_wait_en_START (0)
#define SOC_PMCTRL_UNIT_XPU_XPU_PMC_POLL_WAIT_EN_taskctrl_poll_wait_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apll_0_en_cfg : 1;
        unsigned int apll_0_bp_cfg : 1;
        unsigned int apll_0_refdiv_cfg : 6;
        unsigned int apll_0_fbdiv_cfg : 12;
        unsigned int apll_0_postdiv1_cfg : 3;
        unsigned int apll_0_postdiv2_cfg : 3;
        unsigned int apll_0_lock : 1;
        unsigned int fcg_lock : 1;
        unsigned int fdcs_fast_mode : 1;
        unsigned int apll_fdcs_ctrl_sel : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_apll_0_en_cfg_START (0)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_apll_0_en_cfg_END (0)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_apll_0_bp_cfg_START (1)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_apll_0_bp_cfg_END (1)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_apll_0_refdiv_cfg_START (2)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_apll_0_refdiv_cfg_END (7)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_apll_0_fbdiv_cfg_START (8)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_apll_0_fbdiv_cfg_END (19)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_apll_0_postdiv1_cfg_START (20)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_apll_0_postdiv1_cfg_END (22)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_apll_0_postdiv2_cfg_START (23)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_apll_0_postdiv2_cfg_END (25)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_apll_0_lock_START (26)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_apll_0_lock_END (26)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_fcg_lock_START (27)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_fcg_lock_END (27)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_fdcs_fast_mode_START (28)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_fdcs_fast_mode_END (28)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_apll_fdcs_ctrl_sel_START (29)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_apll_fdcs_ctrl_sel_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apll_0_fracdiv_cfg : 24;
        unsigned int apll_0_int_mod_cfg : 1;
        unsigned int apll_0_cfg_vld_cfg : 1;
        unsigned int gt_clk_apll_0_cfg : 1;
        unsigned int reserved_0 : 1;
        unsigned int apll_0_bp_dis_req_bypass : 1;
        unsigned int apll_0_bp_en_req_bypass : 1;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL1_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL1_apll_0_fracdiv_cfg_START (0)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL1_apll_0_fracdiv_cfg_END (23)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL1_apll_0_int_mod_cfg_START (24)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL1_apll_0_int_mod_cfg_END (24)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL1_apll_0_cfg_vld_cfg_START (25)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL1_apll_0_cfg_vld_cfg_END (25)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL1_gt_clk_apll_0_cfg_START (26)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL1_gt_clk_apll_0_cfg_END (26)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL1_apll_0_bp_dis_req_bypass_START (28)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL1_apll_0_bp_dis_req_bypass_END (28)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL1_apll_0_bp_en_req_bypass_START (29)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL1_apll_0_bp_en_req_bypass_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apll_0_en_stat : 1;
        unsigned int apll_0_bp_stat : 1;
        unsigned int apll_0_refdiv_stat : 6;
        unsigned int apll_0_fbdiv_stat : 12;
        unsigned int apll_0_postdiv1_stat : 3;
        unsigned int apll_0_postdiv2_stat : 3;
        unsigned int fdcs_fast_mode_stable : 1;
        unsigned int reserved : 1;
        unsigned int cofsm_cur_apll_0_freq_stat : 4;
    } reg;
} SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_STAT_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_STAT_apll_0_en_stat_START (0)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_STAT_apll_0_en_stat_END (0)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_STAT_apll_0_bp_stat_START (1)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_STAT_apll_0_bp_stat_END (1)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_STAT_apll_0_refdiv_stat_START (2)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_STAT_apll_0_refdiv_stat_END (7)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_STAT_apll_0_fbdiv_stat_START (8)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_STAT_apll_0_fbdiv_stat_END (19)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_STAT_apll_0_postdiv1_stat_START (20)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_STAT_apll_0_postdiv1_stat_END (22)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_STAT_apll_0_postdiv2_stat_START (23)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_STAT_apll_0_postdiv2_stat_END (25)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_STAT_fdcs_fast_mode_stable_START (26)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_STAT_fdcs_fast_mode_stable_END (26)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_STAT_cofsm_cur_apll_0_freq_stat_START (28)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL0_STAT_cofsm_cur_apll_0_freq_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apll_0_fracdiv_stat : 24;
        unsigned int apll_0_int_mod_stat : 1;
        unsigned int apll_0_cfg_vld_stat : 1;
        unsigned int gt_clk_apll_0_stat : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL1_STAT_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL1_STAT_apll_0_fracdiv_stat_START (0)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL1_STAT_apll_0_fracdiv_stat_END (23)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL1_STAT_apll_0_int_mod_stat_START (24)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL1_STAT_apll_0_int_mod_stat_END (24)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL1_STAT_apll_0_cfg_vld_stat_START (25)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL1_STAT_apll_0_cfg_vld_stat_END (25)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL1_STAT_gt_clk_apll_0_stat_START (26)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_CTRL1_STAT_gt_clk_apll_0_stat_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 6;
        unsigned int apll_0_fbdiv_sw_initial0 : 12;
        unsigned int apll_0_postdiv1_sw_initial0 : 3;
        unsigned int apll_0_postdiv2_sw_initial0 : 3;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 5;
    } reg;
} SOC_PMCTRL_UNIT_XPU_APLL_0_SW_DVFS_INITIAL0_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_APLL_0_SW_DVFS_INITIAL0_apll_0_fbdiv_sw_initial0_START (8)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_SW_DVFS_INITIAL0_apll_0_fbdiv_sw_initial0_END (19)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_SW_DVFS_INITIAL0_apll_0_postdiv1_sw_initial0_START (20)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_SW_DVFS_INITIAL0_apll_0_postdiv1_sw_initial0_END (22)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_SW_DVFS_INITIAL0_apll_0_postdiv2_sw_initial0_START (23)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_SW_DVFS_INITIAL0_apll_0_postdiv2_sw_initial0_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apll_0_fracdiv_sw_initial0 : 24;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 5;
    } reg;
} SOC_PMCTRL_UNIT_XPU_APLL_0_SW_DVFS_INITIAL1_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_APLL_0_SW_DVFS_INITIAL1_apll_0_fracdiv_sw_initial0_START (0)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_SW_DVFS_INITIAL1_apll_0_fracdiv_sw_initial0_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 6;
        unsigned int apll_0_fbdiv_sw_initial1 : 12;
        unsigned int apll_0_postdiv1_sw_initial1 : 3;
        unsigned int apll_0_postdiv2_sw_initial1 : 3;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 5;
    } reg;
} SOC_PMCTRL_UNIT_XPU_APLL_0_SW_PWRUPDN_INITIAL0_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_APLL_0_SW_PWRUPDN_INITIAL0_apll_0_fbdiv_sw_initial1_START (8)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_SW_PWRUPDN_INITIAL0_apll_0_fbdiv_sw_initial1_END (19)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_SW_PWRUPDN_INITIAL0_apll_0_postdiv1_sw_initial1_START (20)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_SW_PWRUPDN_INITIAL0_apll_0_postdiv1_sw_initial1_END (22)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_SW_PWRUPDN_INITIAL0_apll_0_postdiv2_sw_initial1_START (23)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_SW_PWRUPDN_INITIAL0_apll_0_postdiv2_sw_initial1_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apll_0_fracdiv_sw_initial1 : 24;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 5;
    } reg;
} SOC_PMCTRL_UNIT_XPU_APLL_0_SW_PWRUPDN_INITIAL1_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_APLL_0_SW_PWRUPDN_INITIAL1_apll_0_fracdiv_sw_initial1_START (0)
#define SOC_PMCTRL_UNIT_XPU_APLL_0_SW_PWRUPDN_INITIAL1_apll_0_fracdiv_sw_initial1_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_cpu_div_sft_idx : 16;
        unsigned int cofsm_cpu_div_sft_cfg : 1;
        unsigned int cofsm_sw2ppll0_req : 1;
        unsigned int cofsm_sw2apll_req : 1;
        unsigned int cofsm_pll_sw_stat : 1;
        unsigned int cofsm_ppll0_div_stat : 4;
        unsigned int cofsm_ppll0_div_sft_idx : 4;
        unsigned int cofsm_ppll0_div_sft_cfg : 1;
        unsigned int cofsm_gt_clk_ppll0_gt_sft_set : 1;
        unsigned int cofsm_gt_clk_ppll0_gt_sft_clr : 1;
        unsigned int cofsm_gt_clk_ppll0_gt_stat : 1;
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_0_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_0_cofsm_cpu_div_sft_idx_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_0_cofsm_cpu_div_sft_idx_END (15)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_0_cofsm_cpu_div_sft_cfg_START (16)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_0_cofsm_cpu_div_sft_cfg_END (16)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_0_cofsm_sw2ppll0_req_START (17)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_0_cofsm_sw2ppll0_req_END (17)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_0_cofsm_sw2apll_req_START (18)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_0_cofsm_sw2apll_req_END (18)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_0_cofsm_pll_sw_stat_START (19)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_0_cofsm_pll_sw_stat_END (19)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_0_cofsm_ppll0_div_stat_START (20)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_0_cofsm_ppll0_div_stat_END (23)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_0_cofsm_ppll0_div_sft_idx_START (24)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_0_cofsm_ppll0_div_sft_idx_END (27)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_0_cofsm_ppll0_div_sft_cfg_START (28)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_0_cofsm_ppll0_div_sft_cfg_END (28)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_0_cofsm_gt_clk_ppll0_gt_sft_set_START (29)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_0_cofsm_gt_clk_ppll0_gt_sft_set_END (29)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_0_cofsm_gt_clk_ppll0_gt_sft_clr_START (30)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_0_cofsm_gt_clk_ppll0_gt_sft_clr_END (30)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_0_cofsm_gt_clk_ppll0_gt_stat_START (31)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_0_cofsm_gt_clk_ppll0_gt_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_cpu_div_stat : 16;
        unsigned int cofsm_vdm_div_stat : 4;
        unsigned int cofsm_vdm_div_sft_idx : 4;
        unsigned int cofsm_vdm_div_sft_cfg : 1;
        unsigned int cofsm_cur_clk_src_stat : 3;
        unsigned int cofsm_pipeline_mgt_sft_cfg : 1;
        unsigned int cofsm_pipeline_mgt_en : 1;
        unsigned int reserved : 1;
        unsigned int cofsm_pll_sw_ack_sync : 1;
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_1_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_1_cofsm_cpu_div_stat_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_1_cofsm_cpu_div_stat_END (15)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_1_cofsm_vdm_div_stat_START (16)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_1_cofsm_vdm_div_stat_END (19)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_1_cofsm_vdm_div_sft_idx_START (20)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_1_cofsm_vdm_div_sft_idx_END (23)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_1_cofsm_vdm_div_sft_cfg_START (24)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_1_cofsm_vdm_div_sft_cfg_END (24)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_1_cofsm_cur_clk_src_stat_START (25)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_1_cofsm_cur_clk_src_stat_END (27)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_1_cofsm_pipeline_mgt_sft_cfg_START (28)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_1_cofsm_pipeline_mgt_sft_cfg_END (28)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_1_cofsm_pipeline_mgt_en_START (29)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_1_cofsm_pipeline_mgt_en_END (29)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_1_cofsm_pll_sw_ack_sync_START (31)
#define SOC_PMCTRL_UNIT_XPU_COFSM_CLK_DIV_CTRL_1_cofsm_pll_sw_ack_sync_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_freq_down_en_svfd : 1;
        unsigned int cofsm_svfd_freq_down_ctrl_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 28;
    } reg;
} SOC_PMCTRL_UNIT_XPU_SVFD_FREQ_DOWM_CTRL_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_SVFD_FREQ_DOWM_CTRL_cofsm_freq_down_en_svfd_START (0)
#define SOC_PMCTRL_UNIT_XPU_SVFD_FREQ_DOWM_CTRL_cofsm_freq_down_en_svfd_END (0)
#define SOC_PMCTRL_UNIT_XPU_SVFD_FREQ_DOWM_CTRL_cofsm_svfd_freq_down_ctrl_bypass_START (1)
#define SOC_PMCTRL_UNIT_XPU_SVFD_FREQ_DOWM_CTRL_cofsm_svfd_freq_down_ctrl_bypass_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_svfd_freq_down_step_ctrl : 12;
        unsigned int cofsm_svfd_freq_dn_wait_time : 12;
        unsigned int reserved : 8;
    } reg;
} SOC_PMCTRL_UNIT_XPU_SVFD_FREQ_CTRL0_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_SVFD_FREQ_CTRL0_cofsm_svfd_freq_down_step_ctrl_START (0)
#define SOC_PMCTRL_UNIT_XPU_SVFD_FREQ_CTRL0_cofsm_svfd_freq_down_step_ctrl_END (11)
#define SOC_PMCTRL_UNIT_XPU_SVFD_FREQ_CTRL0_cofsm_svfd_freq_dn_wait_time_START (12)
#define SOC_PMCTRL_UNIT_XPU_SVFD_FREQ_CTRL0_cofsm_svfd_freq_dn_wait_time_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_fine_step_ctrl_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_PMCTRL_UNIT_XPU_FINE_STEP_FREQ_CTRL_BYPASS_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_FINE_STEP_FREQ_CTRL_BYPASS_cofsm_fine_step_ctrl_bypass_START (0)
#define SOC_PMCTRL_UNIT_XPU_FINE_STEP_FREQ_CTRL_BYPASS_cofsm_fine_step_ctrl_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_logic_vol_ctrl_src_0 : 4;
        unsigned int cofsm_logic_vol_ctrl_src_1 : 4;
        unsigned int cofsm_logic_vol_ctrl_src_2 : 4;
        unsigned int cofsm_logic_vol_ctrl_src_3 : 4;
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 4;
        unsigned int reserved_2 : 4;
        unsigned int reserved_3 : 4;
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_VOL_CTRL_SRC_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_CTRL_SRC_cofsm_logic_vol_ctrl_src_0_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_CTRL_SRC_cofsm_logic_vol_ctrl_src_0_END (3)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_CTRL_SRC_cofsm_logic_vol_ctrl_src_1_START (4)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_CTRL_SRC_cofsm_logic_vol_ctrl_src_1_END (7)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_CTRL_SRC_cofsm_logic_vol_ctrl_src_2_START (8)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_CTRL_SRC_cofsm_logic_vol_ctrl_src_2_END (11)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_CTRL_SRC_cofsm_logic_vol_ctrl_src_3_START (12)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_CTRL_SRC_cofsm_logic_vol_ctrl_src_3_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_vol_hs_ctrl_src : 4;
        unsigned int cofsm_mem_vol_ctrl_src_0 : 4;
        unsigned int cofsm_mem_vol_ctrl_src_1 : 4;
        unsigned int cofsm_mem_vol_ctrl_src_2 : 4;
        unsigned int cofsm_mem_vol_ctrl_src_3 : 4;
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 4;
        unsigned int reserved_2 : 4;
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_SRC_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_SRC_cofsm_vol_hs_ctrl_src_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_SRC_cofsm_vol_hs_ctrl_src_END (3)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_SRC_cofsm_mem_vol_ctrl_src_0_START (4)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_SRC_cofsm_mem_vol_ctrl_src_0_END (7)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_SRC_cofsm_mem_vol_ctrl_src_1_START (8)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_SRC_cofsm_mem_vol_ctrl_src_1_END (11)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_SRC_cofsm_mem_vol_ctrl_src_2_START (12)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_SRC_cofsm_mem_vol_ctrl_src_2_END (15)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_SRC_cofsm_mem_vol_ctrl_src_3_START (16)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_SRC_cofsm_mem_vol_ctrl_src_3_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_freq_ctrl_src : 4;
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 4;
        unsigned int reserved_2 : 4;
        unsigned int reserved_3 : 4;
        unsigned int reserved_4 : 4;
        unsigned int reserved_5 : 4;
        unsigned int reserved_6 : 4;
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_FREQ_CTRL_SRC_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_FREQ_CTRL_SRC_cofsm_freq_ctrl_src_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FREQ_CTRL_SRC_cofsm_freq_ctrl_src_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_logic_vau_init_vol_idx : 8;
        unsigned int cofsm_logic_vau_init_vol_req : 1;
        unsigned int reserved_0 : 3;
        unsigned int cofsm_sft_logic_buck_vol_idx : 8;
        unsigned int cofsm_sft_logic_buck_on_req : 1;
        unsigned int cofsm_sft_logic_buck_off_req : 1;
        unsigned int cofsm_sft_logic_buck_onoff_req_en : 1;
        unsigned int cofsm_logic_separate_vset_ven_ctrl_bypass : 1;
        unsigned int cofsm_logic_fer_buck_pg_bypass : 1;
        unsigned int cofsm_logic_fer_buck_vok_bypass : 1;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_0_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_0_cofsm_logic_vau_init_vol_idx_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_0_cofsm_logic_vau_init_vol_idx_END (7)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_0_cofsm_logic_vau_init_vol_req_START (8)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_0_cofsm_logic_vau_init_vol_req_END (8)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_0_cofsm_sft_logic_buck_vol_idx_START (12)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_0_cofsm_sft_logic_buck_vol_idx_END (19)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_0_cofsm_sft_logic_buck_on_req_START (20)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_0_cofsm_sft_logic_buck_on_req_END (20)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_0_cofsm_sft_logic_buck_off_req_START (21)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_0_cofsm_sft_logic_buck_off_req_END (21)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_0_cofsm_sft_logic_buck_onoff_req_en_START (22)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_0_cofsm_sft_logic_buck_onoff_req_en_END (22)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_0_cofsm_logic_separate_vset_ven_ctrl_bypass_START (23)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_0_cofsm_logic_separate_vset_ven_ctrl_bypass_END (23)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_0_cofsm_logic_fer_buck_pg_bypass_START (24)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_0_cofsm_logic_fer_buck_pg_bypass_END (24)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_0_cofsm_logic_fer_buck_vok_bypass_START (25)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_0_cofsm_logic_fer_buck_vok_bypass_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_soft_logic_vol_chg_idx_0 : 8;
        unsigned int cofsm_soft_logic_vol_vote_en_0 : 1;
        unsigned int cofsm_soft_logic_vol_chg_pls_0 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int cofsm_soft_logic_vol_chg_idx_1 : 8;
        unsigned int cofsm_soft_logic_vol_vote_en_1 : 1;
        unsigned int cofsm_soft_logic_vol_chg_pls_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 8;
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_1_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_1_cofsm_soft_logic_vol_chg_idx_0_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_1_cofsm_soft_logic_vol_chg_idx_0_END (7)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_1_cofsm_soft_logic_vol_vote_en_0_START (8)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_1_cofsm_soft_logic_vol_vote_en_0_END (8)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_1_cofsm_soft_logic_vol_chg_pls_0_START (9)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_1_cofsm_soft_logic_vol_chg_pls_0_END (9)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_1_cofsm_soft_logic_vol_chg_idx_1_START (12)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_1_cofsm_soft_logic_vol_chg_idx_1_END (19)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_1_cofsm_soft_logic_vol_vote_en_1_START (20)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_1_cofsm_soft_logic_vol_vote_en_1_END (20)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_1_cofsm_soft_logic_vol_chg_pls_1_START (21)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_1_cofsm_soft_logic_vol_chg_pls_1_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_soft_logic_vol_chg_idx_2 : 8;
        unsigned int cofsm_soft_logic_vol_vote_en_2 : 1;
        unsigned int cofsm_soft_logic_vol_chg_pls_2 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int cofsm_soft_logic_vol_chg_idx_3 : 8;
        unsigned int cofsm_soft_logic_vol_vote_en_3 : 1;
        unsigned int cofsm_soft_logic_vol_chg_pls_3 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 8;
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_2_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_2_cofsm_soft_logic_vol_chg_idx_2_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_2_cofsm_soft_logic_vol_chg_idx_2_END (7)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_2_cofsm_soft_logic_vol_vote_en_2_START (8)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_2_cofsm_soft_logic_vol_vote_en_2_END (8)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_2_cofsm_soft_logic_vol_chg_pls_2_START (9)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_2_cofsm_soft_logic_vol_chg_pls_2_END (9)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_2_cofsm_soft_logic_vol_chg_idx_3_START (12)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_2_cofsm_soft_logic_vol_chg_idx_3_END (19)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_2_cofsm_soft_logic_vol_vote_en_3_START (20)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_2_cofsm_soft_logic_vol_vote_en_3_END (20)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_2_cofsm_soft_logic_vol_chg_pls_3_START (21)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_CTRL_2_cofsm_soft_logic_vol_chg_pls_3_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_logic_vau_nxt_max_vol : 8;
        unsigned int cofsm_logic_vau_cur_max_vol : 8;
        unsigned int cofsm_logic_buck_nxt_vol_idx : 8;
        unsigned int cofsm_logic_buck_cur_vol_idx : 8;
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_0_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_0_cofsm_logic_vau_nxt_max_vol_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_0_cofsm_logic_vau_nxt_max_vol_END (7)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_0_cofsm_logic_vau_cur_max_vol_START (8)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_0_cofsm_logic_vau_cur_max_vol_END (15)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_0_cofsm_logic_buck_nxt_vol_idx_START (16)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_0_cofsm_logic_buck_nxt_vol_idx_END (23)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_0_cofsm_logic_buck_cur_vol_idx_START (24)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_0_cofsm_logic_buck_cur_vol_idx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_logic_valid_vol_vote_idx_0 : 8;
        unsigned int cofsm_logic_valid_vol_vote_idx_1 : 8;
        unsigned int cofsm_logic_valid_vol_vote_idx_2 : 8;
        unsigned int cofsm_logic_valid_vol_vote_idx_3 : 8;
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_1_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_1_cofsm_logic_valid_vol_vote_idx_0_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_1_cofsm_logic_valid_vol_vote_idx_0_END (7)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_1_cofsm_logic_valid_vol_vote_idx_1_START (8)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_1_cofsm_logic_valid_vol_vote_idx_1_END (15)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_1_cofsm_logic_valid_vol_vote_idx_2_START (16)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_1_cofsm_logic_valid_vol_vote_idx_2_END (23)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_1_cofsm_logic_valid_vol_vote_idx_3_START (24)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_1_cofsm_logic_valid_vol_vote_idx_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_pmu_logic_vol_idx_spmi : 8;
        unsigned int cofsm_pmu_logic_vol_chg_spmi : 1;
        unsigned int cofsm_pmu_logic_vol_ack_spmi : 1;
        unsigned int cofsm_vau_logic_vol_equal_flag : 1;
        unsigned int cofsm_vau_logic_vol_equal_flag_clr : 1;
        unsigned int cofsm_logic_vau_cur_stat : 3;
        unsigned int reserved_0 : 1;
        unsigned int cofsm_logic_buck_ctrl_cur_stat : 3;
        unsigned int reserved_1 : 1;
        unsigned int cofsm_logic_vol_trim_stable : 1;
        unsigned int cofsm_logic_buck_onoff_stable : 1;
        unsigned int cofsm_fer_logic_buck_pgvok_req : 1;
        unsigned int cofsm_fer_logic_buck_pgvok_ack : 1;
        unsigned int cofsm_logic_vol_vote_stable_0 : 1;
        unsigned int cofsm_logic_vol_vote_stable_1 : 1;
        unsigned int cofsm_logic_vol_vote_stable_2 : 1;
        unsigned int cofsm_logic_vol_vote_stable_3 : 1;
        unsigned int cofsm_logic_vol_spmi_hold_timeout_flag : 1;
        unsigned int cofsm_logic_vol_buck_onoff_timeout_flag : 1;
        unsigned int cofsm_logic_vol_fer_err_flag : 1;
        unsigned int cofsm_logic_vol_timeout_flag_clr : 1;
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_pmu_logic_vol_idx_spmi_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_pmu_logic_vol_idx_spmi_END (7)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_pmu_logic_vol_chg_spmi_START (8)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_pmu_logic_vol_chg_spmi_END (8)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_pmu_logic_vol_ack_spmi_START (9)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_pmu_logic_vol_ack_spmi_END (9)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_vau_logic_vol_equal_flag_START (10)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_vau_logic_vol_equal_flag_END (10)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_vau_logic_vol_equal_flag_clr_START (11)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_vau_logic_vol_equal_flag_clr_END (11)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_logic_vau_cur_stat_START (12)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_logic_vau_cur_stat_END (14)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_logic_buck_ctrl_cur_stat_START (16)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_logic_buck_ctrl_cur_stat_END (18)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_logic_vol_trim_stable_START (20)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_logic_vol_trim_stable_END (20)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_logic_buck_onoff_stable_START (21)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_logic_buck_onoff_stable_END (21)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_fer_logic_buck_pgvok_req_START (22)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_fer_logic_buck_pgvok_req_END (22)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_fer_logic_buck_pgvok_ack_START (23)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_fer_logic_buck_pgvok_ack_END (23)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_logic_vol_vote_stable_0_START (24)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_logic_vol_vote_stable_0_END (24)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_logic_vol_vote_stable_1_START (25)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_logic_vol_vote_stable_1_END (25)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_logic_vol_vote_stable_2_START (26)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_logic_vol_vote_stable_2_END (26)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_logic_vol_vote_stable_3_START (27)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_logic_vol_vote_stable_3_END (27)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_logic_vol_spmi_hold_timeout_flag_START (28)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_logic_vol_spmi_hold_timeout_flag_END (28)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_logic_vol_buck_onoff_timeout_flag_START (29)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_logic_vol_buck_onoff_timeout_flag_END (29)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_logic_vol_fer_err_flag_START (30)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_logic_vol_fer_err_flag_END (30)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_logic_vol_timeout_flag_clr_START (31)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_STAT_2_cofsm_logic_vol_timeout_flag_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_trim_logic_vol_vote_add_sub_idx : 8;
        unsigned int cofsm_trim_logic_vol_vote_add_sub_flag : 1;
        unsigned int cofsm_trim_logic_vol_vote_req : 1;
        unsigned int cofsm_trim_logic_vol_vote_ack : 1;
        unsigned int cofsm_trim_logic_vol_vote_stable : 1;
        unsigned int cofsm_valid_trim_logic_vol_vote_add_sub_idx : 8;
        unsigned int cofsm_valid_trim_logic_vol_vote_add_sub_flag : 1;
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
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_TRIM_STAT_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_TRIM_STAT_cofsm_trim_logic_vol_vote_add_sub_idx_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_TRIM_STAT_cofsm_trim_logic_vol_vote_add_sub_idx_END (7)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_TRIM_STAT_cofsm_trim_logic_vol_vote_add_sub_flag_START (8)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_TRIM_STAT_cofsm_trim_logic_vol_vote_add_sub_flag_END (8)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_TRIM_STAT_cofsm_trim_logic_vol_vote_req_START (9)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_TRIM_STAT_cofsm_trim_logic_vol_vote_req_END (9)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_TRIM_STAT_cofsm_trim_logic_vol_vote_ack_START (10)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_TRIM_STAT_cofsm_trim_logic_vol_vote_ack_END (10)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_TRIM_STAT_cofsm_trim_logic_vol_vote_stable_START (11)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_TRIM_STAT_cofsm_trim_logic_vol_vote_stable_END (11)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_TRIM_STAT_cofsm_valid_trim_logic_vol_vote_add_sub_idx_START (12)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_TRIM_STAT_cofsm_valid_trim_logic_vol_vote_add_sub_idx_END (19)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_TRIM_STAT_cofsm_valid_trim_logic_vol_vote_add_sub_flag_START (20)
#define SOC_PMCTRL_UNIT_XPU_COFSM_LOGIC_VOL_TRIM_STAT_cofsm_valid_trim_logic_vol_vote_add_sub_flag_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_mem_vau_init_vol_idx : 8;
        unsigned int cofsm_mem_vau_init_vol_req : 1;
        unsigned int reserved_0 : 3;
        unsigned int cofsm_sft_mem_buck_vol_idx : 8;
        unsigned int cofsm_sft_mem_buck_on_req : 1;
        unsigned int cofsm_sft_mem_buck_off_req : 1;
        unsigned int cofsm_sft_mem_buck_onoff_req_en : 1;
        unsigned int cofsm_mem_separate_vset_ven_ctrl_bypass : 1;
        unsigned int cofsm_mem_fer_buck_pg_bypass : 1;
        unsigned int cofsm_mem_fer_buck_vok_bypass : 1;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_0_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_0_cofsm_mem_vau_init_vol_idx_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_0_cofsm_mem_vau_init_vol_idx_END (7)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_0_cofsm_mem_vau_init_vol_req_START (8)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_0_cofsm_mem_vau_init_vol_req_END (8)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_0_cofsm_sft_mem_buck_vol_idx_START (12)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_0_cofsm_sft_mem_buck_vol_idx_END (19)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_0_cofsm_sft_mem_buck_on_req_START (20)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_0_cofsm_sft_mem_buck_on_req_END (20)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_0_cofsm_sft_mem_buck_off_req_START (21)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_0_cofsm_sft_mem_buck_off_req_END (21)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_0_cofsm_sft_mem_buck_onoff_req_en_START (22)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_0_cofsm_sft_mem_buck_onoff_req_en_END (22)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_0_cofsm_mem_separate_vset_ven_ctrl_bypass_START (23)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_0_cofsm_mem_separate_vset_ven_ctrl_bypass_END (23)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_0_cofsm_mem_fer_buck_pg_bypass_START (24)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_0_cofsm_mem_fer_buck_pg_bypass_END (24)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_0_cofsm_mem_fer_buck_vok_bypass_START (25)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_0_cofsm_mem_fer_buck_vok_bypass_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_soft_mem_vol_chg_idx_0 : 8;
        unsigned int cofsm_soft_mem_vol_vote_en_0 : 1;
        unsigned int cofsm_soft_mem_vol_chg_pls_0 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int cofsm_soft_mem_vol_chg_idx_1 : 8;
        unsigned int cofsm_soft_mem_vol_vote_en_1 : 1;
        unsigned int cofsm_soft_mem_vol_chg_pls_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 8;
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_1_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_1_cofsm_soft_mem_vol_chg_idx_0_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_1_cofsm_soft_mem_vol_chg_idx_0_END (7)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_1_cofsm_soft_mem_vol_vote_en_0_START (8)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_1_cofsm_soft_mem_vol_vote_en_0_END (8)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_1_cofsm_soft_mem_vol_chg_pls_0_START (9)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_1_cofsm_soft_mem_vol_chg_pls_0_END (9)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_1_cofsm_soft_mem_vol_chg_idx_1_START (12)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_1_cofsm_soft_mem_vol_chg_idx_1_END (19)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_1_cofsm_soft_mem_vol_vote_en_1_START (20)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_1_cofsm_soft_mem_vol_vote_en_1_END (20)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_1_cofsm_soft_mem_vol_chg_pls_1_START (21)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_1_cofsm_soft_mem_vol_chg_pls_1_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_soft_mem_vol_chg_idx_2 : 8;
        unsigned int cofsm_soft_mem_vol_vote_en_2 : 1;
        unsigned int cofsm_soft_mem_vol_chg_pls_2 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int cofsm_soft_mem_vol_chg_idx_3 : 8;
        unsigned int cofsm_soft_mem_vol_vote_en_3 : 1;
        unsigned int cofsm_soft_mem_vol_chg_pls_3 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 8;
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_2_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_2_cofsm_soft_mem_vol_chg_idx_2_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_2_cofsm_soft_mem_vol_chg_idx_2_END (7)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_2_cofsm_soft_mem_vol_vote_en_2_START (8)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_2_cofsm_soft_mem_vol_vote_en_2_END (8)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_2_cofsm_soft_mem_vol_chg_pls_2_START (9)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_2_cofsm_soft_mem_vol_chg_pls_2_END (9)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_2_cofsm_soft_mem_vol_chg_idx_3_START (12)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_2_cofsm_soft_mem_vol_chg_idx_3_END (19)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_2_cofsm_soft_mem_vol_vote_en_3_START (20)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_2_cofsm_soft_mem_vol_vote_en_3_END (20)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_2_cofsm_soft_mem_vol_chg_pls_3_START (21)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_CTRL_2_cofsm_soft_mem_vol_chg_pls_3_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_mem_vau_nxt_max_vol : 8;
        unsigned int cofsm_mem_vau_cur_max_vol : 8;
        unsigned int cofsm_mem_buck_nxt_vol_idx : 8;
        unsigned int cofsm_mem_buck_cur_vol_idx : 8;
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_0_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_0_cofsm_mem_vau_nxt_max_vol_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_0_cofsm_mem_vau_nxt_max_vol_END (7)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_0_cofsm_mem_vau_cur_max_vol_START (8)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_0_cofsm_mem_vau_cur_max_vol_END (15)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_0_cofsm_mem_buck_nxt_vol_idx_START (16)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_0_cofsm_mem_buck_nxt_vol_idx_END (23)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_0_cofsm_mem_buck_cur_vol_idx_START (24)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_0_cofsm_mem_buck_cur_vol_idx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_mem_valid_vol_vote_idx_0 : 8;
        unsigned int cofsm_mem_valid_vol_vote_idx_1 : 8;
        unsigned int cofsm_mem_valid_vol_vote_idx_2 : 8;
        unsigned int cofsm_mem_valid_vol_vote_idx_3 : 8;
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_1_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_1_cofsm_mem_valid_vol_vote_idx_0_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_1_cofsm_mem_valid_vol_vote_idx_0_END (7)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_1_cofsm_mem_valid_vol_vote_idx_1_START (8)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_1_cofsm_mem_valid_vol_vote_idx_1_END (15)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_1_cofsm_mem_valid_vol_vote_idx_2_START (16)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_1_cofsm_mem_valid_vol_vote_idx_2_END (23)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_1_cofsm_mem_valid_vol_vote_idx_3_START (24)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_1_cofsm_mem_valid_vol_vote_idx_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_pmu_mem_vol_idx_spmi : 8;
        unsigned int cofsm_pmu_mem_vol_chg_spmi : 1;
        unsigned int cofsm_pmu_mem_vol_ack_spmi : 1;
        unsigned int cofsm_vau_mem_vol_equal_flag : 1;
        unsigned int cofsm_vau_mem_vol_equal_flag_clr : 1;
        unsigned int cofsm_mem_vau_cur_stat : 3;
        unsigned int reserved_0 : 1;
        unsigned int cofsm_mem_buck_ctrl_cur_stat : 3;
        unsigned int reserved_1 : 1;
        unsigned int cofsm_mem_vol_trim_stable : 1;
        unsigned int cofsm_mem_buck_onoff_stable : 1;
        unsigned int cofsm_fer_mem_buck_pgvok_req : 1;
        unsigned int cofsm_fer_mem_buck_pgvok_ack : 1;
        unsigned int cofsm_mem_vol_vote_stable_0 : 1;
        unsigned int cofsm_mem_vol_vote_stable_1 : 1;
        unsigned int cofsm_mem_vol_vote_stable_2 : 1;
        unsigned int cofsm_mem_vol_vote_stable_3 : 1;
        unsigned int cofsm_mem_vol_spmi_hold_timeout_flag : 1;
        unsigned int cofsm_mem_vol_buck_onoff_timeout_flag : 1;
        unsigned int cofsm_mem_vol_fer_err_flag : 1;
        unsigned int cofsm_mem_vol_timeout_flag_clr : 1;
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_pmu_mem_vol_idx_spmi_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_pmu_mem_vol_idx_spmi_END (7)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_pmu_mem_vol_chg_spmi_START (8)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_pmu_mem_vol_chg_spmi_END (8)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_pmu_mem_vol_ack_spmi_START (9)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_pmu_mem_vol_ack_spmi_END (9)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_vau_mem_vol_equal_flag_START (10)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_vau_mem_vol_equal_flag_END (10)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_vau_mem_vol_equal_flag_clr_START (11)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_vau_mem_vol_equal_flag_clr_END (11)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_mem_vau_cur_stat_START (12)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_mem_vau_cur_stat_END (14)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_mem_buck_ctrl_cur_stat_START (16)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_mem_buck_ctrl_cur_stat_END (18)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_mem_vol_trim_stable_START (20)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_mem_vol_trim_stable_END (20)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_mem_buck_onoff_stable_START (21)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_mem_buck_onoff_stable_END (21)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_fer_mem_buck_pgvok_req_START (22)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_fer_mem_buck_pgvok_req_END (22)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_fer_mem_buck_pgvok_ack_START (23)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_fer_mem_buck_pgvok_ack_END (23)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_mem_vol_vote_stable_0_START (24)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_mem_vol_vote_stable_0_END (24)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_mem_vol_vote_stable_1_START (25)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_mem_vol_vote_stable_1_END (25)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_mem_vol_vote_stable_2_START (26)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_mem_vol_vote_stable_2_END (26)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_mem_vol_vote_stable_3_START (27)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_mem_vol_vote_stable_3_END (27)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_mem_vol_spmi_hold_timeout_flag_START (28)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_mem_vol_spmi_hold_timeout_flag_END (28)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_mem_vol_buck_onoff_timeout_flag_START (29)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_mem_vol_buck_onoff_timeout_flag_END (29)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_mem_vol_fer_err_flag_START (30)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_mem_vol_fer_err_flag_END (30)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_mem_vol_timeout_flag_clr_START (31)
#define SOC_PMCTRL_UNIT_XPU_COFSM_MEM_VOL_STAT_2_cofsm_mem_vol_timeout_flag_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_soft_vol_hs_cfg_idx : 8;
        unsigned int cofsm_soft_vol_hs_cfg_pls : 1;
        unsigned int reserved_0 : 3;
        unsigned int cofsm_soft_vol_hs_ack : 1;
        unsigned int cofsm_vol_hs_soft_cfg_mode : 1;
        unsigned int cofsm_dvfs_vol_hs_ack : 1;
        unsigned int reserved_1 : 1;
        unsigned int cofsm_vol_hs_idx : 8;
        unsigned int cofsm_vol_hs_req : 1;
        unsigned int reserved_2 : 3;
        unsigned int cofsm_cur_hs_stat : 2;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_cofsm_soft_vol_hs_cfg_idx_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_cofsm_soft_vol_hs_cfg_idx_END (7)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_cofsm_soft_vol_hs_cfg_pls_START (8)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_cofsm_soft_vol_hs_cfg_pls_END (8)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_cofsm_soft_vol_hs_ack_START (12)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_cofsm_soft_vol_hs_ack_END (12)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_cofsm_vol_hs_soft_cfg_mode_START (13)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_cofsm_vol_hs_soft_cfg_mode_END (13)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_cofsm_dvfs_vol_hs_ack_START (14)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_cofsm_dvfs_vol_hs_ack_END (14)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_cofsm_vol_hs_idx_START (16)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_cofsm_vol_hs_idx_END (23)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_cofsm_vol_hs_req_START (24)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_cofsm_vol_hs_req_END (24)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_cofsm_cur_hs_stat_START (28)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VOL_HS_CTRL_cofsm_cur_hs_stat_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_vdm_data : 15;
        unsigned int reserved_0 : 1;
        unsigned int cofsm_vdm_data_ack : 1;
        unsigned int cofsm_vdm_data_req : 1;
        unsigned int cofsm_vdm_en_ack : 1;
        unsigned int cofsm_vdm_en_req : 1;
        unsigned int cofsm_vdm_dis_ack : 1;
        unsigned int cofsm_vdm_dis_req : 1;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 8;
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_VDM_STAT_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_VDM_STAT_cofsm_vdm_data_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VDM_STAT_cofsm_vdm_data_END (14)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VDM_STAT_cofsm_vdm_data_ack_START (16)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VDM_STAT_cofsm_vdm_data_ack_END (16)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VDM_STAT_cofsm_vdm_data_req_START (17)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VDM_STAT_cofsm_vdm_data_req_END (17)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VDM_STAT_cofsm_vdm_en_ack_START (18)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VDM_STAT_cofsm_vdm_en_ack_END (18)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VDM_STAT_cofsm_vdm_en_req_START (19)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VDM_STAT_cofsm_vdm_en_req_END (19)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VDM_STAT_cofsm_vdm_dis_ack_START (20)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VDM_STAT_cofsm_vdm_dis_ack_END (20)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VDM_STAT_cofsm_vdm_dis_req_START (21)
#define SOC_PMCTRL_UNIT_XPU_COFSM_VDM_STAT_cofsm_vdm_dis_req_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_pim_drop_sft_cfg : 1;
        unsigned int cofsm_pim_drop_sft_en : 1;
        unsigned int cofsm_peaklow_sft_cfg : 1;
        unsigned int cofsm_peaklow_sft_en : 1;
        unsigned int cofsm_hw_onsys_avs_sft_cfg : 1;
        unsigned int cofsm_hw_onsys_avs_sft_en : 1;
        unsigned int cofsm_pim_drop_thr_sft_cfg : 1;
        unsigned int cofsm_pim_drop_thr_sft : 8;
        unsigned int cofsm_ack_sel_sft_cfg : 1;
        unsigned int cofsm_ack_sel_sft : 3;
        unsigned int cofsm_fdcs_dcc_thr_vld_sft_cfg : 1;
        unsigned int cofsm_fdcs_monitor_sft_cfg : 1;
        unsigned int cofsm_fdcs_monitor_sft_en : 1;
        unsigned int apll_clkgt_onoff_wait_time : 8;
        unsigned int reserved : 2;
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_cofsm_pim_drop_sft_cfg_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_cofsm_pim_drop_sft_cfg_END (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_cofsm_pim_drop_sft_en_START (1)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_cofsm_pim_drop_sft_en_END (1)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_cofsm_peaklow_sft_cfg_START (2)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_cofsm_peaklow_sft_cfg_END (2)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_cofsm_peaklow_sft_en_START (3)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_cofsm_peaklow_sft_en_END (3)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_cofsm_hw_onsys_avs_sft_cfg_START (4)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_cofsm_hw_onsys_avs_sft_cfg_END (4)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_cofsm_hw_onsys_avs_sft_en_START (5)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_cofsm_hw_onsys_avs_sft_en_END (5)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_cofsm_pim_drop_thr_sft_cfg_START (6)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_cofsm_pim_drop_thr_sft_cfg_END (6)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_cofsm_pim_drop_thr_sft_START (7)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_cofsm_pim_drop_thr_sft_END (14)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_cofsm_ack_sel_sft_cfg_START (15)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_cofsm_ack_sel_sft_cfg_END (15)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_cofsm_ack_sel_sft_START (16)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_cofsm_ack_sel_sft_END (18)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_cofsm_fdcs_dcc_thr_vld_sft_cfg_START (19)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_cofsm_fdcs_dcc_thr_vld_sft_cfg_END (19)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_cofsm_fdcs_monitor_sft_cfg_START (20)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_cofsm_fdcs_monitor_sft_cfg_END (20)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_cofsm_fdcs_monitor_sft_en_START (21)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_cofsm_fdcs_monitor_sft_en_END (21)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_apll_clkgt_onoff_wait_time_START (22)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_CTRL_0_apll_clkgt_onoff_wait_time_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_pim_drop_en : 1;
        unsigned int cofsm_peaklow_en : 1;
        unsigned int cofsm_hw_onsys_avs_en : 1;
        unsigned int cofsm_fdcs_monitor_en : 1;
        unsigned int cofsm_pim_drop_thr : 8;
        unsigned int cofsm_ack_sel : 3;
        unsigned int cofsm_fdcs_dcc_thr_cfg_vld_flag : 1;
        unsigned int cofsm_fdcs_cfg_finish : 1;
        unsigned int cofsm_fdcs_xpu_cfg_finish : 1;
        unsigned int cofsm_pipeline_mgt_finish : 1;
        unsigned int cofsm_fdcs_xpu_req : 1;
        unsigned int reserved_0 : 11;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_STAT_0_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_STAT_0_cofsm_pim_drop_en_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_STAT_0_cofsm_pim_drop_en_END (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_STAT_0_cofsm_peaklow_en_START (1)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_STAT_0_cofsm_peaklow_en_END (1)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_STAT_0_cofsm_hw_onsys_avs_en_START (2)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_STAT_0_cofsm_hw_onsys_avs_en_END (2)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_STAT_0_cofsm_fdcs_monitor_en_START (3)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_STAT_0_cofsm_fdcs_monitor_en_END (3)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_STAT_0_cofsm_pim_drop_thr_START (4)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_STAT_0_cofsm_pim_drop_thr_END (11)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_STAT_0_cofsm_ack_sel_START (12)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_STAT_0_cofsm_ack_sel_END (14)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_STAT_0_cofsm_fdcs_dcc_thr_cfg_vld_flag_START (15)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_STAT_0_cofsm_fdcs_dcc_thr_cfg_vld_flag_END (15)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_STAT_0_cofsm_fdcs_cfg_finish_START (16)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_STAT_0_cofsm_fdcs_cfg_finish_END (16)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_STAT_0_cofsm_fdcs_xpu_cfg_finish_START (17)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_STAT_0_cofsm_fdcs_xpu_cfg_finish_END (17)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_STAT_0_cofsm_pipeline_mgt_finish_START (18)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_STAT_0_cofsm_pipeline_mgt_finish_END (18)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_STAT_0_cofsm_fdcs_xpu_req_START (19)
#define SOC_PMCTRL_UNIT_XPU_COFSM_FDCS_STAT_0_cofsm_fdcs_xpu_req_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_pmu_logic_vol_up_hold_time : 20;
        unsigned int cofsm_pmu_logic_vol_up_step_time : 12;
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_PMU_LOGIC_TIME_0_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_LOGIC_TIME_0_cofsm_pmu_logic_vol_up_hold_time_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_LOGIC_TIME_0_cofsm_pmu_logic_vol_up_hold_time_END (19)
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_LOGIC_TIME_0_cofsm_pmu_logic_vol_up_step_time_START (20)
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_LOGIC_TIME_0_cofsm_pmu_logic_vol_up_step_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_pmu_logic_vol_dn_hold_time : 20;
        unsigned int cofsm_pmu_logic_vol_dn_step_time : 12;
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_PMU_LOGIC_TIME_1_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_LOGIC_TIME_1_cofsm_pmu_logic_vol_dn_hold_time_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_LOGIC_TIME_1_cofsm_pmu_logic_vol_dn_hold_time_END (19)
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_LOGIC_TIME_1_cofsm_pmu_logic_vol_dn_step_time_START (20)
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_LOGIC_TIME_1_cofsm_pmu_logic_vol_dn_step_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_pmu_logic_buck_on_time : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_PMU_LOGIC_TIME_2_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_LOGIC_TIME_2_cofsm_pmu_logic_buck_on_time_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_LOGIC_TIME_2_cofsm_pmu_logic_buck_on_time_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_pmu_logic_buck_off_time : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_PMU_LOGIC_TIME_3_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_LOGIC_TIME_3_cofsm_pmu_logic_buck_off_time_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_LOGIC_TIME_3_cofsm_pmu_logic_buck_off_time_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_pmu_mem_vol_up_hold_time : 20;
        unsigned int cofsm_pmu_mem_vol_up_step_time : 12;
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_PMU_MEM_TIME_0_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_MEM_TIME_0_cofsm_pmu_mem_vol_up_hold_time_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_MEM_TIME_0_cofsm_pmu_mem_vol_up_hold_time_END (19)
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_MEM_TIME_0_cofsm_pmu_mem_vol_up_step_time_START (20)
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_MEM_TIME_0_cofsm_pmu_mem_vol_up_step_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_pmu_mem_vol_dn_hold_time : 20;
        unsigned int cofsm_pmu_mem_vol_dn_step_time : 12;
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_PMU_MEM_TIME_1_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_MEM_TIME_1_cofsm_pmu_mem_vol_dn_hold_time_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_MEM_TIME_1_cofsm_pmu_mem_vol_dn_hold_time_END (19)
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_MEM_TIME_1_cofsm_pmu_mem_vol_dn_step_time_START (20)
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_MEM_TIME_1_cofsm_pmu_mem_vol_dn_step_time_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_pmu_mem_buck_on_time : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_PMU_MEM_TIME_2_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_MEM_TIME_2_cofsm_pmu_mem_buck_on_time_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_MEM_TIME_2_cofsm_pmu_mem_buck_on_time_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cofsm_pmu_mem_buck_off_time : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_PMCTRL_UNIT_XPU_COFSM_PMU_MEM_TIME_3_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_MEM_TIME_3_cofsm_pmu_mem_buck_off_time_START (0)
#define SOC_PMCTRL_UNIT_XPU_COFSM_PMU_MEM_TIME_3_cofsm_pmu_mem_buck_off_time_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apll_cfg_time : 8;
        unsigned int clk_cfg_wait_cycle : 8;
        unsigned int pclk_cycle_per_us : 10;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_PMCTRL_UNIT_XPU_TIME_PARAMETER_CFG_0_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_TIME_PARAMETER_CFG_0_apll_cfg_time_START (0)
#define SOC_PMCTRL_UNIT_XPU_TIME_PARAMETER_CFG_0_apll_cfg_time_END (7)
#define SOC_PMCTRL_UNIT_XPU_TIME_PARAMETER_CFG_0_clk_cfg_wait_cycle_START (8)
#define SOC_PMCTRL_UNIT_XPU_TIME_PARAMETER_CFG_0_clk_cfg_wait_cycle_END (15)
#define SOC_PMCTRL_UNIT_XPU_TIME_PARAMETER_CFG_0_pclk_cycle_per_us_START (16)
#define SOC_PMCTRL_UNIT_XPU_TIME_PARAMETER_CFG_0_pclk_cycle_per_us_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apll_lock_time : 12;
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 10;
        unsigned int reserved_2 : 2;
        unsigned int reserved_3 : 4;
    } reg;
} SOC_PMCTRL_UNIT_XPU_TIME_PARAMETER_CFG_1_UNION;
#endif
#define SOC_PMCTRL_UNIT_XPU_TIME_PARAMETER_CFG_1_apll_lock_time_START (0)
#define SOC_PMCTRL_UNIT_XPU_TIME_PARAMETER_CFG_1_apll_lock_time_END (11)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
