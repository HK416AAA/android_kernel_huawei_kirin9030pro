#ifndef __SOC_FCM_GICMIS_INTERFACE_H__
#define __SOC_FCM_GICMIS_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FCM_GICMIS_FCM_GIC_LPM3_ACCESS_CFG_REG_ADDR(base) ((base) + (0x000UL))
#define SOC_FCM_GICMIS_FCM_GIC_Q_CHANNEL_CFG_REG_ADDR(base) ((base) + (0x004UL))
#define SOC_FCM_GICMIS_FCM_GIC_MEMORY_CTRL_CFG_REG_ADDR(base) ((base) + (0x008UL))
#define SOC_FCM_GICMIS_FCM_GIC_BYPASS_CFG_REG_ADDR(base) ((base) + (0x00CUL))
#define SOC_FCM_GICMIS_FCM_GIC_SAMPLE_REQ_CFG_REG_ADDR(base) ((base) + (0x010UL))
#define SOC_FCM_GICMIS_FCM_GIC_COL_Q_CHANNEL_CFG_REG_ADDR(base) ((base) + (0x014UL))
#define SOC_FCM_GICMIS_FCM_GIC_P_CHANNEL_CFG_REG_ADDR(base) ((base) + (0x018UL))
#define SOC_FCM_GICMIS_FCM_GIC_CLK_RST_CFG_REG_ADDR(base) ((base) + (0x01CUL))
#define SOC_FCM_GICMIS_FCM_GIC_CPU_ACTIVE_SOFT_CFG_REG_ADDR(base) ((base) + (0x020UL))
#define SOC_FCM_GICMIS_FCM_GIC_SAMPLE_ACK__STAT_ADDR(base) ((base) + (0x200UL))
#define SOC_FCM_GICMIS_FCM_GIC_COL_Q_CHANNEL_STAT_ADDR(base) ((base) + (0x204UL))
#define SOC_FCM_GICMIS_FCM_GIC_P_CHANNEL_STAT_ADDR(base) ((base) + (0x208UL))
#define SOC_FCM_GICMIS_FCM_GIC_INTERRUPT_STAT_ADDR(base) ((base) + (0x20CUL))
#else
#define SOC_FCM_GICMIS_FCM_GIC_LPM3_ACCESS_CFG_REG_ADDR(base) ((base) + (0x000))
#define SOC_FCM_GICMIS_FCM_GIC_Q_CHANNEL_CFG_REG_ADDR(base) ((base) + (0x004))
#define SOC_FCM_GICMIS_FCM_GIC_MEMORY_CTRL_CFG_REG_ADDR(base) ((base) + (0x008))
#define SOC_FCM_GICMIS_FCM_GIC_BYPASS_CFG_REG_ADDR(base) ((base) + (0x00C))
#define SOC_FCM_GICMIS_FCM_GIC_SAMPLE_REQ_CFG_REG_ADDR(base) ((base) + (0x010))
#define SOC_FCM_GICMIS_FCM_GIC_COL_Q_CHANNEL_CFG_REG_ADDR(base) ((base) + (0x014))
#define SOC_FCM_GICMIS_FCM_GIC_P_CHANNEL_CFG_REG_ADDR(base) ((base) + (0x018))
#define SOC_FCM_GICMIS_FCM_GIC_CLK_RST_CFG_REG_ADDR(base) ((base) + (0x01C))
#define SOC_FCM_GICMIS_FCM_GIC_CPU_ACTIVE_SOFT_CFG_REG_ADDR(base) ((base) + (0x020))
#define SOC_FCM_GICMIS_FCM_GIC_SAMPLE_ACK__STAT_ADDR(base) ((base) + (0x200))
#define SOC_FCM_GICMIS_FCM_GIC_COL_Q_CHANNEL_STAT_ADDR(base) ((base) + (0x204))
#define SOC_FCM_GICMIS_FCM_GIC_P_CHANNEL_STAT_ADDR(base) ((base) + (0x208))
#define SOC_FCM_GICMIS_FCM_GIC_INTERRUPT_STAT_ADDR(base) ((base) + (0x20C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 5;
        unsigned int broadcastcacheoutter : 1;
        unsigned int broadcastcachemaint : 1;
        unsigned int broadcastpersist : 1;
        unsigned int broadcastcachemaintpou : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_FCM_GICMIS_FCM_GIC_LPM3_ACCESS_CFG_REG_UNION;
#endif
#define SOC_FCM_GICMIS_FCM_GIC_LPM3_ACCESS_CFG_REG_broadcastcacheoutter_START (5)
#define SOC_FCM_GICMIS_FCM_GIC_LPM3_ACCESS_CFG_REG_broadcastcacheoutter_END (5)
#define SOC_FCM_GICMIS_FCM_GIC_LPM3_ACCESS_CFG_REG_broadcastcachemaint_START (6)
#define SOC_FCM_GICMIS_FCM_GIC_LPM3_ACCESS_CFG_REG_broadcastcachemaint_END (6)
#define SOC_FCM_GICMIS_FCM_GIC_LPM3_ACCESS_CFG_REG_broadcastpersist_START (7)
#define SOC_FCM_GICMIS_FCM_GIC_LPM3_ACCESS_CFG_REG_broadcastpersist_END (7)
#define SOC_FCM_GICMIS_FCM_GIC_LPM3_ACCESS_CFG_REG_broadcastcachemaintpou_START (8)
#define SOC_FCM_GICMIS_FCM_GIC_LPM3_ACCESS_CFG_REG_broadcastcachemaintpou_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gicclk_q_enable : 1;
        unsigned int reserved_0 : 3;
        unsigned int gicclk_qactive_cfgcnt : 7;
        unsigned int reserved_1 : 21;
    } reg;
} SOC_FCM_GICMIS_FCM_GIC_Q_CHANNEL_CFG_REG_UNION;
#endif
#define SOC_FCM_GICMIS_FCM_GIC_Q_CHANNEL_CFG_REG_gicclk_q_enable_START (0)
#define SOC_FCM_GICMIS_FCM_GIC_Q_CHANNEL_CFG_REG_gicclk_q_enable_END (0)
#define SOC_FCM_GICMIS_FCM_GIC_Q_CHANNEL_CFG_REG_gicclk_qactive_cfgcnt_START (4)
#define SOC_FCM_GICMIS_FCM_GIC_Q_CHANNEL_CFG_REG_gicclk_qactive_cfgcnt_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gic_mem_ls : 1;
        unsigned int gic_mem_ds : 1;
        unsigned int gic_mem_sd : 1;
        unsigned int gic_mem_tselr : 3;
        unsigned int gic_mem_tselw : 2;
        unsigned int gic_mem_test : 3;
        unsigned int reserved_0 : 5;
        unsigned int gic_mem_tra : 2;
        unsigned int reserved_1 : 14;
    } reg;
} SOC_FCM_GICMIS_FCM_GIC_MEMORY_CTRL_CFG_REG_UNION;
#endif
#define SOC_FCM_GICMIS_FCM_GIC_MEMORY_CTRL_CFG_REG_gic_mem_ls_START (0)
#define SOC_FCM_GICMIS_FCM_GIC_MEMORY_CTRL_CFG_REG_gic_mem_ls_END (0)
#define SOC_FCM_GICMIS_FCM_GIC_MEMORY_CTRL_CFG_REG_gic_mem_ds_START (1)
#define SOC_FCM_GICMIS_FCM_GIC_MEMORY_CTRL_CFG_REG_gic_mem_ds_END (1)
#define SOC_FCM_GICMIS_FCM_GIC_MEMORY_CTRL_CFG_REG_gic_mem_sd_START (2)
#define SOC_FCM_GICMIS_FCM_GIC_MEMORY_CTRL_CFG_REG_gic_mem_sd_END (2)
#define SOC_FCM_GICMIS_FCM_GIC_MEMORY_CTRL_CFG_REG_gic_mem_tselr_START (3)
#define SOC_FCM_GICMIS_FCM_GIC_MEMORY_CTRL_CFG_REG_gic_mem_tselr_END (5)
#define SOC_FCM_GICMIS_FCM_GIC_MEMORY_CTRL_CFG_REG_gic_mem_tselw_START (6)
#define SOC_FCM_GICMIS_FCM_GIC_MEMORY_CTRL_CFG_REG_gic_mem_tselw_END (7)
#define SOC_FCM_GICMIS_FCM_GIC_MEMORY_CTRL_CFG_REG_gic_mem_test_START (8)
#define SOC_FCM_GICMIS_FCM_GIC_MEMORY_CTRL_CFG_REG_gic_mem_test_END (10)
#define SOC_FCM_GICMIS_FCM_GIC_MEMORY_CTRL_CFG_REG_gic_mem_tra_START (16)
#define SOC_FCM_GICMIS_FCM_GIC_MEMORY_CTRL_CFG_REG_gic_mem_tra_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gicp_allow_ns : 1;
        unsigned int gict_allow_ns : 1;
        unsigned int gic_bus_wakeup_bypass : 1;
        unsigned int cpu_core_active_bypass : 1;
        unsigned int cpu_core_active_hard_sel : 1;
        unsigned int cpu_core_active_soft_ctl : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_FCM_GICMIS_FCM_GIC_BYPASS_CFG_REG_UNION;
#endif
#define SOC_FCM_GICMIS_FCM_GIC_BYPASS_CFG_REG_gicp_allow_ns_START (0)
#define SOC_FCM_GICMIS_FCM_GIC_BYPASS_CFG_REG_gicp_allow_ns_END (0)
#define SOC_FCM_GICMIS_FCM_GIC_BYPASS_CFG_REG_gict_allow_ns_START (1)
#define SOC_FCM_GICMIS_FCM_GIC_BYPASS_CFG_REG_gict_allow_ns_END (1)
#define SOC_FCM_GICMIS_FCM_GIC_BYPASS_CFG_REG_gic_bus_wakeup_bypass_START (2)
#define SOC_FCM_GICMIS_FCM_GIC_BYPASS_CFG_REG_gic_bus_wakeup_bypass_END (2)
#define SOC_FCM_GICMIS_FCM_GIC_BYPASS_CFG_REG_cpu_core_active_bypass_START (3)
#define SOC_FCM_GICMIS_FCM_GIC_BYPASS_CFG_REG_cpu_core_active_bypass_END (3)
#define SOC_FCM_GICMIS_FCM_GIC_BYPASS_CFG_REG_cpu_core_active_hard_sel_START (4)
#define SOC_FCM_GICMIS_FCM_GIC_BYPASS_CFG_REG_cpu_core_active_hard_sel_END (4)
#define SOC_FCM_GICMIS_FCM_GIC_BYPASS_CFG_REG_cpu_core_active_soft_ctl_START (5)
#define SOC_FCM_GICMIS_FCM_GIC_BYPASS_CFG_REG_cpu_core_active_soft_ctl_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gic_sample_req : 1;
        unsigned int reserved_0 : 3;
        unsigned int astartmp : 12;
        unsigned int aendmp : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_FCM_GICMIS_FCM_GIC_SAMPLE_REQ_CFG_REG_UNION;
#endif
#define SOC_FCM_GICMIS_FCM_GIC_SAMPLE_REQ_CFG_REG_gic_sample_req_START (0)
#define SOC_FCM_GICMIS_FCM_GIC_SAMPLE_REQ_CFG_REG_gic_sample_req_END (0)
#define SOC_FCM_GICMIS_FCM_GIC_SAMPLE_REQ_CFG_REG_astartmp_START (4)
#define SOC_FCM_GICMIS_FCM_GIC_SAMPLE_REQ_CFG_REG_astartmp_END (15)
#define SOC_FCM_GICMIS_FCM_GIC_SAMPLE_REQ_CFG_REG_aendmp_START (16)
#define SOC_FCM_GICMIS_FCM_GIC_SAMPLE_REQ_CFG_REG_aendmp_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qreqn_col : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_GICMIS_FCM_GIC_COL_Q_CHANNEL_CFG_REG_UNION;
#endif
#define SOC_FCM_GICMIS_FCM_GIC_COL_Q_CHANNEL_CFG_REG_qreqn_col_START (0)
#define SOC_FCM_GICMIS_FCM_GIC_COL_Q_CHANNEL_CFG_REG_qreqn_col_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gic_preq : 1;
        unsigned int reserved_0 : 3;
        unsigned int gic_pstate : 5;
        unsigned int reserved_1 : 3;
        unsigned int pctl_gate_en : 1;
        unsigned int topperi_gate_en : 1;
        unsigned int reserved_2 : 18;
    } reg;
} SOC_FCM_GICMIS_FCM_GIC_P_CHANNEL_CFG_REG_UNION;
#endif
#define SOC_FCM_GICMIS_FCM_GIC_P_CHANNEL_CFG_REG_gic_preq_START (0)
#define SOC_FCM_GICMIS_FCM_GIC_P_CHANNEL_CFG_REG_gic_preq_END (0)
#define SOC_FCM_GICMIS_FCM_GIC_P_CHANNEL_CFG_REG_gic_pstate_START (4)
#define SOC_FCM_GICMIS_FCM_GIC_P_CHANNEL_CFG_REG_gic_pstate_END (8)
#define SOC_FCM_GICMIS_FCM_GIC_P_CHANNEL_CFG_REG_pctl_gate_en_START (12)
#define SOC_FCM_GICMIS_FCM_GIC_P_CHANNEL_CFG_REG_pctl_gate_en_END (12)
#define SOC_FCM_GICMIS_FCM_GIC_P_CHANNEL_CFG_REG_topperi_gate_en_START (13)
#define SOC_FCM_GICMIS_FCM_GIC_P_CHANNEL_CFG_REG_topperi_gate_en_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gic_adb_mst_clk_en : 1;
        unsigned int gic_adb_mst_rst_req : 1;
        unsigned int gic_dbg_rst_req : 1;
        unsigned int gic_func_rst_req : 1;
        unsigned int reserved : 12;
        unsigned int clk_rst_en_masken : 16;
    } reg;
} SOC_FCM_GICMIS_FCM_GIC_CLK_RST_CFG_REG_UNION;
#endif
#define SOC_FCM_GICMIS_FCM_GIC_CLK_RST_CFG_REG_gic_adb_mst_clk_en_START (0)
#define SOC_FCM_GICMIS_FCM_GIC_CLK_RST_CFG_REG_gic_adb_mst_clk_en_END (0)
#define SOC_FCM_GICMIS_FCM_GIC_CLK_RST_CFG_REG_gic_adb_mst_rst_req_START (1)
#define SOC_FCM_GICMIS_FCM_GIC_CLK_RST_CFG_REG_gic_adb_mst_rst_req_END (1)
#define SOC_FCM_GICMIS_FCM_GIC_CLK_RST_CFG_REG_gic_dbg_rst_req_START (2)
#define SOC_FCM_GICMIS_FCM_GIC_CLK_RST_CFG_REG_gic_dbg_rst_req_END (2)
#define SOC_FCM_GICMIS_FCM_GIC_CLK_RST_CFG_REG_gic_func_rst_req_START (3)
#define SOC_FCM_GICMIS_FCM_GIC_CLK_RST_CFG_REG_gic_func_rst_req_END (3)
#define SOC_FCM_GICMIS_FCM_GIC_CLK_RST_CFG_REG_clk_rst_en_masken_START (16)
#define SOC_FCM_GICMIS_FCM_GIC_CLK_RST_CFG_REG_clk_rst_en_masken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gic_cpu_active_soft_cfg : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_FCM_GICMIS_FCM_GIC_CPU_ACTIVE_SOFT_CFG_REG_UNION;
#endif
#define SOC_FCM_GICMIS_FCM_GIC_CPU_ACTIVE_SOFT_CFG_REG_gic_cpu_active_soft_cfg_START (0)
#define SOC_FCM_GICMIS_FCM_GIC_CPU_ACTIVE_SOFT_CFG_REG_gic_cpu_active_soft_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gic_sample_ack : 1;
        unsigned int gic_clkqdeny : 1;
        unsigned int gic_clkqactivenew : 1;
        unsigned int gic_clkqreqn : 1;
        unsigned int gic_clkqacceptn : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_FCM_GICMIS_FCM_GIC_SAMPLE_ACK__STAT_UNION;
#endif
#define SOC_FCM_GICMIS_FCM_GIC_SAMPLE_ACK__STAT_gic_sample_ack_START (0)
#define SOC_FCM_GICMIS_FCM_GIC_SAMPLE_ACK__STAT_gic_sample_ack_END (0)
#define SOC_FCM_GICMIS_FCM_GIC_SAMPLE_ACK__STAT_gic_clkqdeny_START (1)
#define SOC_FCM_GICMIS_FCM_GIC_SAMPLE_ACK__STAT_gic_clkqdeny_END (1)
#define SOC_FCM_GICMIS_FCM_GIC_SAMPLE_ACK__STAT_gic_clkqactivenew_START (2)
#define SOC_FCM_GICMIS_FCM_GIC_SAMPLE_ACK__STAT_gic_clkqactivenew_END (2)
#define SOC_FCM_GICMIS_FCM_GIC_SAMPLE_ACK__STAT_gic_clkqreqn_START (3)
#define SOC_FCM_GICMIS_FCM_GIC_SAMPLE_ACK__STAT_gic_clkqreqn_END (3)
#define SOC_FCM_GICMIS_FCM_GIC_SAMPLE_ACK__STAT_gic_clkqacceptn_START (4)
#define SOC_FCM_GICMIS_FCM_GIC_SAMPLE_ACK__STAT_gic_clkqacceptn_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qacceptn_col : 1;
        unsigned int qactive_col : 1;
        unsigned int qdeny_col : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_FCM_GICMIS_FCM_GIC_COL_Q_CHANNEL_STAT_UNION;
#endif
#define SOC_FCM_GICMIS_FCM_GIC_COL_Q_CHANNEL_STAT_qacceptn_col_START (0)
#define SOC_FCM_GICMIS_FCM_GIC_COL_Q_CHANNEL_STAT_qacceptn_col_END (0)
#define SOC_FCM_GICMIS_FCM_GIC_COL_Q_CHANNEL_STAT_qactive_col_START (1)
#define SOC_FCM_GICMIS_FCM_GIC_COL_Q_CHANNEL_STAT_qactive_col_END (1)
#define SOC_FCM_GICMIS_FCM_GIC_COL_Q_CHANNEL_STAT_qdeny_col_START (2)
#define SOC_FCM_GICMIS_FCM_GIC_COL_Q_CHANNEL_STAT_qdeny_col_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gic_paccept : 1;
        unsigned int gic_pactive : 1;
        unsigned int gic_pdeny : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_FCM_GICMIS_FCM_GIC_P_CHANNEL_STAT_UNION;
#endif
#define SOC_FCM_GICMIS_FCM_GIC_P_CHANNEL_STAT_gic_paccept_START (0)
#define SOC_FCM_GICMIS_FCM_GIC_P_CHANNEL_STAT_gic_paccept_END (0)
#define SOC_FCM_GICMIS_FCM_GIC_P_CHANNEL_STAT_gic_pactive_START (1)
#define SOC_FCM_GICMIS_FCM_GIC_P_CHANNEL_STAT_gic_pactive_END (1)
#define SOC_FCM_GICMIS_FCM_GIC_P_CHANNEL_STAT_gic_pdeny_START (2)
#define SOC_FCM_GICMIS_FCM_GIC_P_CHANNEL_STAT_gic_pdeny_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gic_err_int : 1;
        unsigned int gic_fault_int : 1;
        unsigned int gic_pmu_int : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_FCM_GICMIS_FCM_GIC_INTERRUPT_STAT_UNION;
#endif
#define SOC_FCM_GICMIS_FCM_GIC_INTERRUPT_STAT_gic_err_int_START (0)
#define SOC_FCM_GICMIS_FCM_GIC_INTERRUPT_STAT_gic_err_int_END (0)
#define SOC_FCM_GICMIS_FCM_GIC_INTERRUPT_STAT_gic_fault_int_START (1)
#define SOC_FCM_GICMIS_FCM_GIC_INTERRUPT_STAT_gic_fault_int_END (1)
#define SOC_FCM_GICMIS_FCM_GIC_INTERRUPT_STAT_gic_pmu_int_START (2)
#define SOC_FCM_GICMIS_FCM_GIC_INTERRUPT_STAT_gic_pmu_int_END (2)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
