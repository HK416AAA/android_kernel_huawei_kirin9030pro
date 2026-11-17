#ifndef __SOC_QICE_GLB_INTERFACE_H__
#define __SOC_QICE_GLB_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QICE_GLB_GLB_ADDR_CTRL_ADDR(base) ((base) + 0x0010UL)
#define SOC_QICE_GLB_GLB_COH_CTRL_ADDR(base) ((base) + 0x0020UL)
#define SOC_QICE_GLB_GLB_QTPEM_CTRL_ADDR(base) ((base) + 0x0030UL)
#define SOC_QICE_GLB_GLB_TB_COMMON_ADDR(base) ((base) + 0x120UL)
#define SOC_QICE_GLB_GLB_TB_PRI_MAP_ADDR(base) ((base) + 0x0124UL)
#define SOC_QICE_GLB_GLB_TB_TRACE_START_ADDR(base) ((base) + 0x0128UL)
#define SOC_QICE_GLB_GLB_TB_TRACE_STOP_ADDR(base) ((base) + 0x012CUL)
#define SOC_QICE_GLB_GLB_TB2DMC_RANK_CTRL_ADDR(base) ((base) + 0x130UL)
#define SOC_QICE_GLB_GLB_SC_WCMD_SEND_AFTER_WDATA_LW_EN_ADDR(base) ((base) + 0x0200UL)
#define SOC_QICE_GLB_GLB_WCMD_PARTIAL_TO_FULL_EN_ADDR(base) ((base) + 0x0204UL)
#define SOC_QICE_GLB_GLB_PARITY_EN_ADDR(base) ((base) + 0x0210UL)
#define SOC_QICE_GLB_GLB_IECC_EN_ADDR(base) ((base) + 0x0214UL)
#else
#define SOC_QICE_GLB_GLB_ADDR_CTRL_ADDR(base) ((base) + 0x0010)
#define SOC_QICE_GLB_GLB_COH_CTRL_ADDR(base) ((base) + 0x0020)
#define SOC_QICE_GLB_GLB_QTPEM_CTRL_ADDR(base) ((base) + 0x0030)
#define SOC_QICE_GLB_GLB_TB_COMMON_ADDR(base) ((base) + 0x120)
#define SOC_QICE_GLB_GLB_TB_PRI_MAP_ADDR(base) ((base) + 0x0124)
#define SOC_QICE_GLB_GLB_TB_TRACE_START_ADDR(base) ((base) + 0x0128)
#define SOC_QICE_GLB_GLB_TB_TRACE_STOP_ADDR(base) ((base) + 0x012C)
#define SOC_QICE_GLB_GLB_TB2DMC_RANK_CTRL_ADDR(base) ((base) + 0x130)
#define SOC_QICE_GLB_GLB_SC_WCMD_SEND_AFTER_WDATA_LW_EN_ADDR(base) ((base) + 0x0200)
#define SOC_QICE_GLB_GLB_WCMD_PARTIAL_TO_FULL_EN_ADDR(base) ((base) + 0x0204)
#define SOC_QICE_GLB_GLB_PARITY_EN_ADDR(base) ((base) + 0x0210)
#define SOC_QICE_GLB_GLB_IECC_EN_ADDR(base) ((base) + 0x0214)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intlv_gran : 2;
        unsigned int ddr_channel_mode : 1;
        unsigned int scramble_en : 1;
        unsigned int routing_split : 2;
        unsigned int reserved_0 : 2;
        unsigned int addr_shift_mode : 2;
        unsigned int reserved_1 : 2;
        unsigned int intlv_area_addr_0 : 7;
        unsigned int intlv_area_addr_1 : 7;
        unsigned int intlv_area_rop_mode_sel : 1;
        unsigned int tbed2dmi_rop_sel : 1;
        unsigned int reserved_2 : 4;
    } reg;
} SOC_QICE_GLB_GLB_ADDR_CTRL_UNION;
#endif
#define SOC_QICE_GLB_GLB_ADDR_CTRL_intlv_gran_START (0)
#define SOC_QICE_GLB_GLB_ADDR_CTRL_intlv_gran_END (1)
#define SOC_QICE_GLB_GLB_ADDR_CTRL_ddr_channel_mode_START (2)
#define SOC_QICE_GLB_GLB_ADDR_CTRL_ddr_channel_mode_END (2)
#define SOC_QICE_GLB_GLB_ADDR_CTRL_scramble_en_START (3)
#define SOC_QICE_GLB_GLB_ADDR_CTRL_scramble_en_END (3)
#define SOC_QICE_GLB_GLB_ADDR_CTRL_routing_split_START (4)
#define SOC_QICE_GLB_GLB_ADDR_CTRL_routing_split_END (5)
#define SOC_QICE_GLB_GLB_ADDR_CTRL_addr_shift_mode_START (8)
#define SOC_QICE_GLB_GLB_ADDR_CTRL_addr_shift_mode_END (9)
#define SOC_QICE_GLB_GLB_ADDR_CTRL_intlv_area_addr_0_START (12)
#define SOC_QICE_GLB_GLB_ADDR_CTRL_intlv_area_addr_0_END (18)
#define SOC_QICE_GLB_GLB_ADDR_CTRL_intlv_area_addr_1_START (19)
#define SOC_QICE_GLB_GLB_ADDR_CTRL_intlv_area_addr_1_END (25)
#define SOC_QICE_GLB_GLB_ADDR_CTRL_intlv_area_rop_mode_sel_START (26)
#define SOC_QICE_GLB_GLB_ADDR_CTRL_intlv_area_rop_mode_sel_END (26)
#define SOC_QICE_GLB_GLB_ADDR_CTRL_tbed2dmi_rop_sel_START (27)
#define SOC_QICE_GLB_GLB_ADDR_CTRL_tbed2dmi_rop_sel_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 3;
        unsigned int axdomain_sel : 1;
        unsigned int sc_bypass_mode : 1;
        unsigned int sc_bcmo_en : 1;
        unsigned int dmt_dis : 1;
        unsigned int cmo_mode : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_QICE_GLB_GLB_COH_CTRL_UNION;
#endif
#define SOC_QICE_GLB_GLB_COH_CTRL_axdomain_sel_START (3)
#define SOC_QICE_GLB_GLB_COH_CTRL_axdomain_sel_END (3)
#define SOC_QICE_GLB_GLB_COH_CTRL_sc_bypass_mode_START (4)
#define SOC_QICE_GLB_GLB_COH_CTRL_sc_bypass_mode_END (4)
#define SOC_QICE_GLB_GLB_COH_CTRL_sc_bcmo_en_START (5)
#define SOC_QICE_GLB_GLB_COH_CTRL_sc_bcmo_en_END (5)
#define SOC_QICE_GLB_GLB_COH_CTRL_dmt_dis_START (6)
#define SOC_QICE_GLB_GLB_COH_CTRL_dmt_dis_END (6)
#define SOC_QICE_GLB_GLB_COH_CTRL_cmo_mode_START (7)
#define SOC_QICE_GLB_GLB_COH_CTRL_cmo_mode_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qtpem_disable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_GLB_GLB_QTPEM_CTRL_UNION;
#endif
#define SOC_QICE_GLB_GLB_QTPEM_CTRL_qtpem_disable_START (0)
#define SOC_QICE_GLB_GLB_QTPEM_CTRL_qtpem_disable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmdque_ram_use : 1;
        unsigned int addr_hzd_ena : 1;
        unsigned int tkn_cmdfifo_ena : 1;
        unsigned int prftgt_drop_ena : 1;
        unsigned int trace_clk_on : 1;
        unsigned int dmi_cmdflag_sync_ena : 1;
        unsigned int dmc_bp_cmd_timeout_byps : 1;
        unsigned int nderr_wdat_en : 1;
        unsigned int mde_auth_rd_sel : 4;
        unsigned int dcache_mode : 2;
        unsigned int rdrcpt_wait_sched : 1;
        unsigned int derr_wdat_en : 1;
        unsigned int reserved_0 : 9;
        unsigned int wrap2incr_ena : 1;
        unsigned int reserved_1 : 5;
        unsigned int token_mode : 1;
    } reg;
} SOC_QICE_GLB_GLB_TB_COMMON_UNION;
#endif
#define SOC_QICE_GLB_GLB_TB_COMMON_cmdque_ram_use_START (0)
#define SOC_QICE_GLB_GLB_TB_COMMON_cmdque_ram_use_END (0)
#define SOC_QICE_GLB_GLB_TB_COMMON_addr_hzd_ena_START (1)
#define SOC_QICE_GLB_GLB_TB_COMMON_addr_hzd_ena_END (1)
#define SOC_QICE_GLB_GLB_TB_COMMON_tkn_cmdfifo_ena_START (2)
#define SOC_QICE_GLB_GLB_TB_COMMON_tkn_cmdfifo_ena_END (2)
#define SOC_QICE_GLB_GLB_TB_COMMON_prftgt_drop_ena_START (3)
#define SOC_QICE_GLB_GLB_TB_COMMON_prftgt_drop_ena_END (3)
#define SOC_QICE_GLB_GLB_TB_COMMON_trace_clk_on_START (4)
#define SOC_QICE_GLB_GLB_TB_COMMON_trace_clk_on_END (4)
#define SOC_QICE_GLB_GLB_TB_COMMON_dmi_cmdflag_sync_ena_START (5)
#define SOC_QICE_GLB_GLB_TB_COMMON_dmi_cmdflag_sync_ena_END (5)
#define SOC_QICE_GLB_GLB_TB_COMMON_dmc_bp_cmd_timeout_byps_START (6)
#define SOC_QICE_GLB_GLB_TB_COMMON_dmc_bp_cmd_timeout_byps_END (6)
#define SOC_QICE_GLB_GLB_TB_COMMON_nderr_wdat_en_START (7)
#define SOC_QICE_GLB_GLB_TB_COMMON_nderr_wdat_en_END (7)
#define SOC_QICE_GLB_GLB_TB_COMMON_mde_auth_rd_sel_START (8)
#define SOC_QICE_GLB_GLB_TB_COMMON_mde_auth_rd_sel_END (11)
#define SOC_QICE_GLB_GLB_TB_COMMON_dcache_mode_START (12)
#define SOC_QICE_GLB_GLB_TB_COMMON_dcache_mode_END (13)
#define SOC_QICE_GLB_GLB_TB_COMMON_rdrcpt_wait_sched_START (14)
#define SOC_QICE_GLB_GLB_TB_COMMON_rdrcpt_wait_sched_END (14)
#define SOC_QICE_GLB_GLB_TB_COMMON_derr_wdat_en_START (15)
#define SOC_QICE_GLB_GLB_TB_COMMON_derr_wdat_en_END (15)
#define SOC_QICE_GLB_GLB_TB_COMMON_wrap2incr_ena_START (25)
#define SOC_QICE_GLB_GLB_TB_COMMON_wrap2incr_ena_END (25)
#define SOC_QICE_GLB_GLB_TB_COMMON_token_mode_START (31)
#define SOC_QICE_GLB_GLB_TB_COMMON_token_mode_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pri_map_cfg : 16;
        unsigned int pri_unmap_cfg : 12;
        unsigned int reserved : 4;
    } reg;
} SOC_QICE_GLB_GLB_TB_PRI_MAP_UNION;
#endif
#define SOC_QICE_GLB_GLB_TB_PRI_MAP_pri_map_cfg_START (0)
#define SOC_QICE_GLB_GLB_TB_PRI_MAP_pri_map_cfg_END (15)
#define SOC_QICE_GLB_GLB_TB_PRI_MAP_pri_unmap_cfg_START (16)
#define SOC_QICE_GLB_GLB_TB_PRI_MAP_pri_unmap_cfg_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trace_start : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_GLB_GLB_TB_TRACE_START_UNION;
#endif
#define SOC_QICE_GLB_GLB_TB_TRACE_START_trace_start_START (0)
#define SOC_QICE_GLB_GLB_TB_TRACE_START_trace_start_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trace_stop : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_GLB_GLB_TB_TRACE_STOP_UNION;
#endif
#define SOC_QICE_GLB_GLB_TB_TRACE_STOP_trace_stop_START (0)
#define SOC_QICE_GLB_GLB_TB_TRACE_STOP_trace_stop_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr0_rank_hole : 5;
        unsigned int reserved_0 : 3;
        unsigned int size0_rank_hole : 4;
        unsigned int reserved_1 : 4;
        unsigned int addr1_rank_hole : 5;
        unsigned int reserved_2 : 3;
        unsigned int size1_rank_hole : 4;
        unsigned int reserved_3 : 4;
    } reg;
} SOC_QICE_GLB_GLB_TB2DMC_RANK_CTRL_UNION;
#endif
#define SOC_QICE_GLB_GLB_TB2DMC_RANK_CTRL_addr0_rank_hole_START (0)
#define SOC_QICE_GLB_GLB_TB2DMC_RANK_CTRL_addr0_rank_hole_END (4)
#define SOC_QICE_GLB_GLB_TB2DMC_RANK_CTRL_size0_rank_hole_START (8)
#define SOC_QICE_GLB_GLB_TB2DMC_RANK_CTRL_size0_rank_hole_END (11)
#define SOC_QICE_GLB_GLB_TB2DMC_RANK_CTRL_addr1_rank_hole_START (16)
#define SOC_QICE_GLB_GLB_TB2DMC_RANK_CTRL_addr1_rank_hole_END (20)
#define SOC_QICE_GLB_GLB_TB2DMC_RANK_CTRL_size1_rank_hole_START (24)
#define SOC_QICE_GLB_GLB_TB2DMC_RANK_CTRL_size1_rank_hole_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_wcmd_send_after_wdata_lw_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_GLB_GLB_SC_WCMD_SEND_AFTER_WDATA_LW_EN_UNION;
#endif
#define SOC_QICE_GLB_GLB_SC_WCMD_SEND_AFTER_WDATA_LW_EN_sc_wcmd_send_after_wdata_lw_en_START (0)
#define SOC_QICE_GLB_GLB_SC_WCMD_SEND_AFTER_WDATA_LW_EN_sc_wcmd_send_after_wdata_lw_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wcmd_partial_to_full_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_GLB_GLB_WCMD_PARTIAL_TO_FULL_EN_UNION;
#endif
#define SOC_QICE_GLB_GLB_WCMD_PARTIAL_TO_FULL_EN_wcmd_partial_to_full_en_START (0)
#define SOC_QICE_GLB_GLB_WCMD_PARTIAL_TO_FULL_EN_wcmd_partial_to_full_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int parity_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_GLB_GLB_PARITY_EN_UNION;
#endif
#define SOC_QICE_GLB_GLB_PARITY_EN_parity_en_START (0)
#define SOC_QICE_GLB_GLB_PARITY_EN_parity_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_iecc_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_GLB_GLB_IECC_EN_UNION;
#endif
#define SOC_QICE_GLB_GLB_IECC_EN_icfg_iecc_en_START (0)
#define SOC_QICE_GLB_GLB_IECC_EN_icfg_iecc_en_END (0)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
