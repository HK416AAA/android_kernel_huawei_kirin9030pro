#ifndef __SOC_ISPCPU_CHIRT_INTERFACE_H__
#define __SOC_ISPCPU_CHIRT_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_ADDR(base) ((base) + 0x0010UL)
#define SOC_ISPCPU_CHIRT_GLB_COH_CTRL_ADDR(base) ((base) + 0x0020UL)
#define SOC_ISPCPU_CHIRT_GLB_QTPEM_CTRL_ADDR(base) ((base) + 0x0030UL)
#define SOC_ISPCPU_CHIRT_GLB_TB_COMMON_ADDR(base) ((base) + 0x120UL)
#define SOC_ISPCPU_CHIRT_GLB_TB_PRI_MAP_ADDR(base) ((base) + 0x0124UL)
#define SOC_ISPCPU_CHIRT_GLB_TB_TRACE_START_ADDR(base) ((base) + 0x0128UL)
#define SOC_ISPCPU_CHIRT_GLB_TB_TRACE_STOP_ADDR(base) ((base) + 0x012CUL)
#define SOC_ISPCPU_CHIRT_GLB_SC_WCMD_SEND_AFTER_WDATA_LW_EN_ADDR(base) ((base) + 0x0200UL)
#define SOC_ISPCPU_CHIRT_GLB_WCMD_PARTIAL_TO_FULL_EN_ADDR(base) ((base) + 0x0204UL)
#define SOC_ISPCPU_CHIRT_GLB_PARITY_EN_ADDR(base) ((base) + 0x0210UL)
#define SOC_ISPCPU_CHIRT_GLB_IECC_EN_ADDR(base) ((base) + 0x0214UL)
#else
#define SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_ADDR(base) ((base) + 0x0010)
#define SOC_ISPCPU_CHIRT_GLB_COH_CTRL_ADDR(base) ((base) + 0x0020)
#define SOC_ISPCPU_CHIRT_GLB_QTPEM_CTRL_ADDR(base) ((base) + 0x0030)
#define SOC_ISPCPU_CHIRT_GLB_TB_COMMON_ADDR(base) ((base) + 0x120)
#define SOC_ISPCPU_CHIRT_GLB_TB_PRI_MAP_ADDR(base) ((base) + 0x0124)
#define SOC_ISPCPU_CHIRT_GLB_TB_TRACE_START_ADDR(base) ((base) + 0x0128)
#define SOC_ISPCPU_CHIRT_GLB_TB_TRACE_STOP_ADDR(base) ((base) + 0x012C)
#define SOC_ISPCPU_CHIRT_GLB_SC_WCMD_SEND_AFTER_WDATA_LW_EN_ADDR(base) ((base) + 0x0200)
#define SOC_ISPCPU_CHIRT_GLB_WCMD_PARTIAL_TO_FULL_EN_ADDR(base) ((base) + 0x0204)
#define SOC_ISPCPU_CHIRT_GLB_PARITY_EN_ADDR(base) ((base) + 0x0210)
#define SOC_ISPCPU_CHIRT_GLB_IECC_EN_ADDR(base) ((base) + 0x0214)
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_ADDR(base) ((base) + 0x0010UL)
#define SOC_ISPCPU_CHIRT_RT_INFO_ADDR(base) ((base) + 0x0400UL)
#define SOC_ISPCPU_CHIRT_RT_RESERVED_RW_ADDR(base) ((base) + 0x0404UL)
#define SOC_ISPCPU_CHIRT_RT_RESERVED_RO_ADDR(base) ((base) + 0x0408UL)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_ADDR(base) ((base) + 0x040CUL)
#define SOC_ISPCPU_CHIRT_RT_CKG_BYPS_ADDR(base) ((base) + 0x0410UL)
#define SOC_ISPCPU_CHIRT_RT_MAX_LAT_CFG_ADDR(base) ((base) + 0x0414UL)
#define SOC_ISPCPU_CHIRT_RT_CKG_EXT_EN_ADDR(base) ((base) + 0x0418UL)
#define SOC_ISPCPU_CHIRT_RT_OUTPORT_CFC_CTRL_ADDR(base,outp_idx) ((base) + 0x041CUL + (outp_idx) * 0x0040UL)
#define SOC_ISPCPU_CHIRT_RT_DIS_LOW_LATENCY_CTRL_ADDR(base,inp_idx) ((base) + 0x0420UL + (inp_idx) * 0x0040UL)
#define SOC_ISPCPU_CHIRT_RT_INPORT_CFC_CTRL_ADDR(base,inp_idx) ((base) + 0x0424UL + (inp_idx) * 0x0040UL)
#define SOC_ISPCPU_CHIRT_RT_GLB_ST_ADDR(base) ((base) + 0x0e00UL)
#define SOC_ISPCPU_CHIRT_RT_GLB_INT_ST_ADDR(base) ((base) + 0x0e04UL)
#define SOC_ISPCPU_CHIRT_RT_MAX_LAT_ST_ADDR(base) ((base) + 0x0e08UL)
#define SOC_ISPCPU_CHIRT_RT_INPORT_LPC_ST_ADDR(base) ((base) + 0x0e0cUL)
#define SOC_ISPCPU_CHIRT_RT_OUTPORT_LPC_ST_ADDR(base) ((base) + 0x0e10UL)
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST0_ADDR(base,inp_idx) ((base) + 0x0e14UL + (inp_idx) * 0x0028UL)
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST2_ADDR(base,inp_idx) ((base) + 0x0e18UL + (inp_idx) * 0x0028UL)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_ST_ADDR(base,inp_idx) ((base) + 0x0e1cUL + (inp_idx) * 0x0028UL)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_INI_ADDR(base,inp_idx) ((base) + 0x0e20UL + (inp_idx) * 0x0028UL)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_CLEAR_ADDR(base,inp_idx) ((base) + 0x0e24UL + (inp_idx) * 0x0028UL)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_EN_ADDR(base,inp_idx) ((base) + 0x0e28UL + (inp_idx) * 0x0028UL)
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST4_ADDR(base,inp_idx) ((base) + 0x0e2cUL + (inp_idx) * 0x0028UL)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_SNP_ADDR(base,inp_idx) ((base) + 0x0e30UL + (inp_idx) * 0x0028UL)
#define SOC_ISPCPU_CHIRT_RT_OUTPORT_DFX_ST0_ADDR(base,outp_idx) ((base) + 0x0e34UL + (outp_idx) * 0x0028UL)
#define SOC_ISPCPU_CHIRT_RT_OUTPORT_DFX_ST1_ADDR(base,outp_idx) ((base) + 0x0e38UL + (outp_idx) * 0x0028UL)
#else
#define SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_ADDR(base) ((base) + 0x0010)
#define SOC_ISPCPU_CHIRT_RT_INFO_ADDR(base) ((base) + 0x0400)
#define SOC_ISPCPU_CHIRT_RT_RESERVED_RW_ADDR(base) ((base) + 0x0404)
#define SOC_ISPCPU_CHIRT_RT_RESERVED_RO_ADDR(base) ((base) + 0x0408)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_ADDR(base) ((base) + 0x040C)
#define SOC_ISPCPU_CHIRT_RT_CKG_BYPS_ADDR(base) ((base) + 0x0410)
#define SOC_ISPCPU_CHIRT_RT_MAX_LAT_CFG_ADDR(base) ((base) + 0x0414)
#define SOC_ISPCPU_CHIRT_RT_CKG_EXT_EN_ADDR(base) ((base) + 0x0418)
#define SOC_ISPCPU_CHIRT_RT_OUTPORT_CFC_CTRL_ADDR(base,outp_idx) ((base) + 0x041C + (outp_idx) * 0x0040)
#define SOC_ISPCPU_CHIRT_RT_DIS_LOW_LATENCY_CTRL_ADDR(base,inp_idx) ((base) + 0x0420 + (inp_idx) * 0x0040)
#define SOC_ISPCPU_CHIRT_RT_INPORT_CFC_CTRL_ADDR(base,inp_idx) ((base) + 0x0424 + (inp_idx) * 0x0040)
#define SOC_ISPCPU_CHIRT_RT_GLB_ST_ADDR(base) ((base) + 0x0e00)
#define SOC_ISPCPU_CHIRT_RT_GLB_INT_ST_ADDR(base) ((base) + 0x0e04)
#define SOC_ISPCPU_CHIRT_RT_MAX_LAT_ST_ADDR(base) ((base) + 0x0e08)
#define SOC_ISPCPU_CHIRT_RT_INPORT_LPC_ST_ADDR(base) ((base) + 0x0e0c)
#define SOC_ISPCPU_CHIRT_RT_OUTPORT_LPC_ST_ADDR(base) ((base) + 0x0e10)
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST0_ADDR(base,inp_idx) ((base) + 0x0e14 + (inp_idx) * 0x0028)
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST2_ADDR(base,inp_idx) ((base) + 0x0e18 + (inp_idx) * 0x0028)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_ST_ADDR(base,inp_idx) ((base) + 0x0e1c + (inp_idx) * 0x0028)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_INI_ADDR(base,inp_idx) ((base) + 0x0e20 + (inp_idx) * 0x0028)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_CLEAR_ADDR(base,inp_idx) ((base) + 0x0e24 + (inp_idx) * 0x0028)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_EN_ADDR(base,inp_idx) ((base) + 0x0e28 + (inp_idx) * 0x0028)
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST4_ADDR(base,inp_idx) ((base) + 0x0e2c + (inp_idx) * 0x0028)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_SNP_ADDR(base,inp_idx) ((base) + 0x0e30 + (inp_idx) * 0x0028)
#define SOC_ISPCPU_CHIRT_RT_OUTPORT_DFX_ST0_ADDR(base,outp_idx) ((base) + 0x0e34 + (outp_idx) * 0x0028)
#define SOC_ISPCPU_CHIRT_RT_OUTPORT_DFX_ST1_ADDR(base,outp_idx) ((base) + 0x0e38 + (outp_idx) * 0x0028)
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_ADDR(base) ((base) + 0x0010UL)
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_INFO_ADDR(base) ((base) + 0x0400UL)
#define SOC_ISPCPU_CHIRT_LINK_RESERVED_RW_ADDR(base) ((base) + 0x0404UL)
#define SOC_ISPCPU_CHIRT_LINK_RESERVED_RO_ADDR(base) ((base) + 0x0408UL)
#define SOC_ISPCPU_CHIRT_LINK_CKG_BYPS_ADDR(base) ((base) + 0x0410UL)
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_CKG_EXT_EN_ADDR(base) ((base) + 0x0414UL)
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_SYSCOACK_ADDR(base) ((base) + 0x0418UL)
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_TXSACTIVE_ADDR(base) ((base) + 0x041CUL)
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_TX_LINK_ACK_ADDR(base) ((base) + 0x0420UL)
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_RX_LINK_REQ_ADDR(base) ((base) + 0x0424UL)
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_MST_SRCID_ADDR(base) ((base) + 0x0428UL)
#define SOC_ISPCPU_CHIRT_CHI_RT_DFX_LINK_STAT_ADDR(base) ((base) + 0xE00UL)
#define SOC_ISPCPU_CHIRT_CHI_RT_DFX_SYSCO_STAT_ADDR(base) ((base) + 0xE04UL)
#define SOC_ISPCPU_CHIRT_CHI_RT_DFX_CKG_STAT_ADDR(base) ((base) + 0xE08UL)
#else
#define SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_ADDR(base) ((base) + 0x0010)
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_INFO_ADDR(base) ((base) + 0x0400)
#define SOC_ISPCPU_CHIRT_LINK_RESERVED_RW_ADDR(base) ((base) + 0x0404)
#define SOC_ISPCPU_CHIRT_LINK_RESERVED_RO_ADDR(base) ((base) + 0x0408)
#define SOC_ISPCPU_CHIRT_LINK_CKG_BYPS_ADDR(base) ((base) + 0x0410)
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_CKG_EXT_EN_ADDR(base) ((base) + 0x0414)
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_SYSCOACK_ADDR(base) ((base) + 0x0418)
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_TXSACTIVE_ADDR(base) ((base) + 0x041C)
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_TX_LINK_ACK_ADDR(base) ((base) + 0x0420)
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_RX_LINK_REQ_ADDR(base) ((base) + 0x0424)
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_MST_SRCID_ADDR(base) ((base) + 0x0428)
#define SOC_ISPCPU_CHIRT_CHI_RT_DFX_LINK_STAT_ADDR(base) ((base) + 0xE00)
#define SOC_ISPCPU_CHIRT_CHI_RT_DFX_SYSCO_STAT_ADDR(base) ((base) + 0xE04)
#define SOC_ISPCPU_CHIRT_CHI_RT_DFX_CKG_STAT_ADDR(base) ((base) + 0xE08)
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_ISPCPU_CHIRT_APCR_CTRL_ADDR(base) (base)
#define SOC_ISPCPU_CHIRT_PROT_CTRL_ADDR(base) ((base) + 0x0004UL)
#define SOC_ISPCPU_CHIRT_PMST_CTRL_ADDR(base) ((base) + 0x0008UL)
#define SOC_ISPCPU_CHIRT_CHAIN_WACK_ADDR(base) ((base) + 0x000CUL)
#define SOC_ISPCPU_CHIRT_LOCK_SEL_ADDR(base) ((base) + 0x0010UL)
#define SOC_ISPCPU_CHIRT_PSLVERR_TYPE_ADDR(base) ((base) + 0x0014UL)
#define SOC_ISPCPU_CHIRT_TIMEOUT_CNT_MIN_VALUE_ADDR(base) ((base) + 0x0018UL)
#define SOC_ISPCPU_CHIRT_PNODE_EN_ADDR(base,pn_idx) (base) + 0x020 + 0x4 * (pn_idx)
#else
#define SOC_ISPCPU_CHIRT_APCR_CTRL_ADDR(base) (base)
#define SOC_ISPCPU_CHIRT_PROT_CTRL_ADDR(base) ((base) + 0x0004)
#define SOC_ISPCPU_CHIRT_PMST_CTRL_ADDR(base) ((base) + 0x0008)
#define SOC_ISPCPU_CHIRT_CHAIN_WACK_ADDR(base) ((base) + 0x000C)
#define SOC_ISPCPU_CHIRT_LOCK_SEL_ADDR(base) ((base) + 0x0010)
#define SOC_ISPCPU_CHIRT_PSLVERR_TYPE_ADDR(base) ((base) + 0x0014)
#define SOC_ISPCPU_CHIRT_TIMEOUT_CNT_MIN_VALUE_ADDR(base) ((base) + 0x0018)
#define SOC_ISPCPU_CHIRT_PNODE_EN_ADDR(base,pn_idx) (base) + 0x020 + 0x4 * (pn_idx)
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
        unsigned int intlv_area_addr_0 : 6;
        unsigned int intlv_area_addr_1 : 6;
        unsigned int intlv_area_rop_mode_sel : 1;
        unsigned int reserved_2 : 7;
    } reg;
} SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_UNION;
#endif
#define SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_intlv_gran_START (0)
#define SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_intlv_gran_END (1)
#define SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_ddr_channel_mode_START (2)
#define SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_ddr_channel_mode_END (2)
#define SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_scramble_en_START (3)
#define SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_scramble_en_END (3)
#define SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_routing_split_START (4)
#define SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_routing_split_END (5)
#define SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_addr_shift_mode_START (8)
#define SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_addr_shift_mode_END (9)
#define SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_intlv_area_addr_0_START (12)
#define SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_intlv_area_addr_0_END (17)
#define SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_intlv_area_addr_1_START (18)
#define SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_intlv_area_addr_1_END (23)
#define SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_intlv_area_rop_mode_sel_START (24)
#define SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_intlv_area_rop_mode_sel_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 3;
        unsigned int gid_sel : 1;
        unsigned int sc_bypass_mode : 1;
        unsigned int sc_bcmo_en : 1;
        unsigned int dmt_dis : 1;
        unsigned int cmo_mode : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_ISPCPU_CHIRT_GLB_COH_CTRL_UNION;
#endif
#define SOC_ISPCPU_CHIRT_GLB_COH_CTRL_gid_sel_START (3)
#define SOC_ISPCPU_CHIRT_GLB_COH_CTRL_gid_sel_END (3)
#define SOC_ISPCPU_CHIRT_GLB_COH_CTRL_sc_bypass_mode_START (4)
#define SOC_ISPCPU_CHIRT_GLB_COH_CTRL_sc_bypass_mode_END (4)
#define SOC_ISPCPU_CHIRT_GLB_COH_CTRL_sc_bcmo_en_START (5)
#define SOC_ISPCPU_CHIRT_GLB_COH_CTRL_sc_bcmo_en_END (5)
#define SOC_ISPCPU_CHIRT_GLB_COH_CTRL_dmt_dis_START (6)
#define SOC_ISPCPU_CHIRT_GLB_COH_CTRL_dmt_dis_END (6)
#define SOC_ISPCPU_CHIRT_GLB_COH_CTRL_cmo_mode_START (7)
#define SOC_ISPCPU_CHIRT_GLB_COH_CTRL_cmo_mode_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qtpem_disable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISPCPU_CHIRT_GLB_QTPEM_CTRL_UNION;
#endif
#define SOC_ISPCPU_CHIRT_GLB_QTPEM_CTRL_qtpem_disable_START (0)
#define SOC_ISPCPU_CHIRT_GLB_QTPEM_CTRL_qtpem_disable_END (0)
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
        unsigned int reserved_0 : 1;
        unsigned int mde_auth_rd_sel : 4;
        unsigned int dcache_mode : 2;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISPCPU_CHIRT_GLB_TB_COMMON_UNION;
#endif
#define SOC_ISPCPU_CHIRT_GLB_TB_COMMON_cmdque_ram_use_START (0)
#define SOC_ISPCPU_CHIRT_GLB_TB_COMMON_cmdque_ram_use_END (0)
#define SOC_ISPCPU_CHIRT_GLB_TB_COMMON_addr_hzd_ena_START (1)
#define SOC_ISPCPU_CHIRT_GLB_TB_COMMON_addr_hzd_ena_END (1)
#define SOC_ISPCPU_CHIRT_GLB_TB_COMMON_tkn_cmdfifo_ena_START (2)
#define SOC_ISPCPU_CHIRT_GLB_TB_COMMON_tkn_cmdfifo_ena_END (2)
#define SOC_ISPCPU_CHIRT_GLB_TB_COMMON_prftgt_drop_ena_START (3)
#define SOC_ISPCPU_CHIRT_GLB_TB_COMMON_prftgt_drop_ena_END (3)
#define SOC_ISPCPU_CHIRT_GLB_TB_COMMON_trace_clk_on_START (4)
#define SOC_ISPCPU_CHIRT_GLB_TB_COMMON_trace_clk_on_END (4)
#define SOC_ISPCPU_CHIRT_GLB_TB_COMMON_dmi_cmdflag_sync_ena_START (5)
#define SOC_ISPCPU_CHIRT_GLB_TB_COMMON_dmi_cmdflag_sync_ena_END (5)
#define SOC_ISPCPU_CHIRT_GLB_TB_COMMON_dmc_bp_cmd_timeout_byps_START (6)
#define SOC_ISPCPU_CHIRT_GLB_TB_COMMON_dmc_bp_cmd_timeout_byps_END (6)
#define SOC_ISPCPU_CHIRT_GLB_TB_COMMON_mde_auth_rd_sel_START (8)
#define SOC_ISPCPU_CHIRT_GLB_TB_COMMON_mde_auth_rd_sel_END (11)
#define SOC_ISPCPU_CHIRT_GLB_TB_COMMON_dcache_mode_START (12)
#define SOC_ISPCPU_CHIRT_GLB_TB_COMMON_dcache_mode_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pri_map_cfg : 16;
        unsigned int pri_unmap_cfg : 12;
        unsigned int reserved : 4;
    } reg;
} SOC_ISPCPU_CHIRT_GLB_TB_PRI_MAP_UNION;
#endif
#define SOC_ISPCPU_CHIRT_GLB_TB_PRI_MAP_pri_map_cfg_START (0)
#define SOC_ISPCPU_CHIRT_GLB_TB_PRI_MAP_pri_map_cfg_END (15)
#define SOC_ISPCPU_CHIRT_GLB_TB_PRI_MAP_pri_unmap_cfg_START (16)
#define SOC_ISPCPU_CHIRT_GLB_TB_PRI_MAP_pri_unmap_cfg_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trace_start : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISPCPU_CHIRT_GLB_TB_TRACE_START_UNION;
#endif
#define SOC_ISPCPU_CHIRT_GLB_TB_TRACE_START_trace_start_START (0)
#define SOC_ISPCPU_CHIRT_GLB_TB_TRACE_START_trace_start_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trace_stop : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISPCPU_CHIRT_GLB_TB_TRACE_STOP_UNION;
#endif
#define SOC_ISPCPU_CHIRT_GLB_TB_TRACE_STOP_trace_stop_START (0)
#define SOC_ISPCPU_CHIRT_GLB_TB_TRACE_STOP_trace_stop_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_wcmd_send_after_wdata_lw_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISPCPU_CHIRT_GLB_SC_WCMD_SEND_AFTER_WDATA_LW_EN_UNION;
#endif
#define SOC_ISPCPU_CHIRT_GLB_SC_WCMD_SEND_AFTER_WDATA_LW_EN_sc_wcmd_send_after_wdata_lw_en_START (0)
#define SOC_ISPCPU_CHIRT_GLB_SC_WCMD_SEND_AFTER_WDATA_LW_EN_sc_wcmd_send_after_wdata_lw_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wcmd_partial_to_full_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISPCPU_CHIRT_GLB_WCMD_PARTIAL_TO_FULL_EN_UNION;
#endif
#define SOC_ISPCPU_CHIRT_GLB_WCMD_PARTIAL_TO_FULL_EN_wcmd_partial_to_full_en_START (0)
#define SOC_ISPCPU_CHIRT_GLB_WCMD_PARTIAL_TO_FULL_EN_wcmd_partial_to_full_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int parity_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISPCPU_CHIRT_GLB_PARITY_EN_UNION;
#endif
#define SOC_ISPCPU_CHIRT_GLB_PARITY_EN_parity_en_START (0)
#define SOC_ISPCPU_CHIRT_GLB_PARITY_EN_parity_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_iecc_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISPCPU_CHIRT_GLB_IECC_EN_UNION;
#endif
#define SOC_ISPCPU_CHIRT_GLB_IECC_EN_icfg_iecc_en_START (0)
#define SOC_ISPCPU_CHIRT_GLB_IECC_EN_icfg_iecc_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intlv_gran : 2;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 2;
        unsigned int reserved_3 : 2;
        unsigned int reserved_4 : 22;
    } reg;
} SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_UNION;
#endif
#define SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_intlv_gran_START (0)
#define SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_intlv_gran_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rt_info : 32;
    } reg;
} SOC_ISPCPU_CHIRT_RT_INFO_UNION;
#endif
#define SOC_ISPCPU_CHIRT_RT_INFO_rt_info_START (0)
#define SOC_ISPCPU_CHIRT_RT_INFO_rt_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rt_reserved_rw : 32;
    } reg;
} SOC_ISPCPU_CHIRT_RT_RESERVED_RW_UNION;
#endif
#define SOC_ISPCPU_CHIRT_RT_RESERVED_RW_rt_reserved_rw_START (0)
#define SOC_ISPCPU_CHIRT_RT_RESERVED_RW_rt_reserved_rw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rt_reserved_ro : 32;
    } reg;
} SOC_ISPCPU_CHIRT_RT_RESERVED_RO_UNION;
#endif
#define SOC_ISPCPU_CHIRT_RT_RESERVED_RO_rt_reserved_ro_START (0)
#define SOC_ISPCPU_CHIRT_RT_RESERVED_RO_rt_reserved_ro_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pri_map_tbl_0 : 2;
        unsigned int pri_map_tbl_1 : 2;
        unsigned int pri_map_tbl_2 : 2;
        unsigned int pri_map_tbl_3 : 2;
        unsigned int pri_map_tbl_4 : 2;
        unsigned int pri_map_tbl_5 : 2;
        unsigned int pri_map_tbl_6 : 2;
        unsigned int pri_map_tbl_7 : 2;
        unsigned int pri_map_tbl_8 : 2;
        unsigned int pri_map_tbl_9 : 2;
        unsigned int pri_map_tbl_10 : 2;
        unsigned int pri_map_tbl_11 : 2;
        unsigned int pri_map_tbl_12 : 2;
        unsigned int pri_map_tbl_13 : 2;
        unsigned int pri_map_tbl_14 : 2;
        unsigned int pri_map_tbl_15 : 2;
    } reg;
} SOC_ISPCPU_CHIRT_RT_PRI_REMAP_UNION;
#endif
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_0_START (0)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_0_END (1)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_1_START (2)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_1_END (3)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_2_START (4)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_2_END (5)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_3_START (6)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_3_END (7)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_4_START (8)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_4_END (9)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_5_START (10)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_5_END (11)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_6_START (12)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_6_END (13)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_7_START (14)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_7_END (15)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_8_START (16)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_8_END (17)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_9_START (18)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_9_END (19)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_10_START (20)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_10_END (21)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_11_START (22)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_11_END (23)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_12_START (24)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_12_END (25)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_13_START (26)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_13_END (27)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_14_START (28)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_14_END (29)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_15_START (30)
#define SOC_ISPCPU_CHIRT_RT_PRI_REMAP_pri_map_tbl_15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ckg_byps_inp : 10;
        unsigned int reserved_0 : 5;
        unsigned int ckg_byps_outp : 10;
        unsigned int reserved_1 : 4;
        unsigned int ckg_byps_inp_cfc : 1;
        unsigned int ckg_byps_nmg : 1;
        unsigned int ckg_byps_outp_cfc : 1;
    } reg;
} SOC_ISPCPU_CHIRT_RT_CKG_BYPS_UNION;
#endif
#define SOC_ISPCPU_CHIRT_RT_CKG_BYPS_ckg_byps_inp_START (0)
#define SOC_ISPCPU_CHIRT_RT_CKG_BYPS_ckg_byps_inp_END (9)
#define SOC_ISPCPU_CHIRT_RT_CKG_BYPS_ckg_byps_outp_START (15)
#define SOC_ISPCPU_CHIRT_RT_CKG_BYPS_ckg_byps_outp_END (24)
#define SOC_ISPCPU_CHIRT_RT_CKG_BYPS_ckg_byps_inp_cfc_START (29)
#define SOC_ISPCPU_CHIRT_RT_CKG_BYPS_ckg_byps_inp_cfc_END (29)
#define SOC_ISPCPU_CHIRT_RT_CKG_BYPS_ckg_byps_nmg_START (30)
#define SOC_ISPCPU_CHIRT_RT_CKG_BYPS_ckg_byps_nmg_END (30)
#define SOC_ISPCPU_CHIRT_RT_CKG_BYPS_ckg_byps_outp_cfc_START (31)
#define SOC_ISPCPU_CHIRT_RT_CKG_BYPS_ckg_byps_outp_cfc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int prescaler : 3;
        unsigned int reserved_0 : 5;
        unsigned int sat_en : 1;
        unsigned int sat_clr : 1;
        unsigned int reserved_1 : 6;
        unsigned int max_lat_inp : 4;
        unsigned int max_lat_outp : 4;
        unsigned int reserved_2 : 8;
    } reg;
} SOC_ISPCPU_CHIRT_RT_MAX_LAT_CFG_UNION;
#endif
#define SOC_ISPCPU_CHIRT_RT_MAX_LAT_CFG_prescaler_START (0)
#define SOC_ISPCPU_CHIRT_RT_MAX_LAT_CFG_prescaler_END (2)
#define SOC_ISPCPU_CHIRT_RT_MAX_LAT_CFG_sat_en_START (8)
#define SOC_ISPCPU_CHIRT_RT_MAX_LAT_CFG_sat_en_END (8)
#define SOC_ISPCPU_CHIRT_RT_MAX_LAT_CFG_sat_clr_START (9)
#define SOC_ISPCPU_CHIRT_RT_MAX_LAT_CFG_sat_clr_END (9)
#define SOC_ISPCPU_CHIRT_RT_MAX_LAT_CFG_max_lat_inp_START (16)
#define SOC_ISPCPU_CHIRT_RT_MAX_LAT_CFG_max_lat_inp_END (19)
#define SOC_ISPCPU_CHIRT_RT_MAX_LAT_CFG_max_lat_outp_START (20)
#define SOC_ISPCPU_CHIRT_RT_MAX_LAT_CFG_max_lat_outp_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 31;
        unsigned int icfg_ckg_ext_ena : 1;
    } reg;
} SOC_ISPCPU_CHIRT_RT_CKG_EXT_EN_UNION;
#endif
#define SOC_ISPCPU_CHIRT_RT_CKG_EXT_EN_icfg_ckg_ext_ena_START (31)
#define SOC_ISPCPU_CHIRT_RT_CKG_EXT_EN_icfg_ckg_ext_ena_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 8;
        unsigned int outp_cfc0_saturation : 5;
        unsigned int reserved_1 : 11;
        unsigned int outp_cfc0_lp : 2;
        unsigned int reserved_2 : 5;
        unsigned int outp_cfc0_en : 1;
    } reg;
} SOC_ISPCPU_CHIRT_RT_OUTPORT_CFC_CTRL_UNION;
#endif
#define SOC_ISPCPU_CHIRT_RT_OUTPORT_CFC_CTRL_outp_cfc0_saturation_START (8)
#define SOC_ISPCPU_CHIRT_RT_OUTPORT_CFC_CTRL_outp_cfc0_saturation_END (12)
#define SOC_ISPCPU_CHIRT_RT_OUTPORT_CFC_CTRL_outp_cfc0_lp_START (24)
#define SOC_ISPCPU_CHIRT_RT_OUTPORT_CFC_CTRL_outp_cfc0_lp_END (25)
#define SOC_ISPCPU_CHIRT_RT_OUTPORT_CFC_CTRL_outp_cfc0_en_START (31)
#define SOC_ISPCPU_CHIRT_RT_OUTPORT_CFC_CTRL_outp_cfc0_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int disable_low_latency : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISPCPU_CHIRT_RT_DIS_LOW_LATENCY_CTRL_UNION;
#endif
#define SOC_ISPCPU_CHIRT_RT_DIS_LOW_LATENCY_CTRL_disable_low_latency_START (0)
#define SOC_ISPCPU_CHIRT_RT_DIS_LOW_LATENCY_CTRL_disable_low_latency_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int inp_cfc0_bw : 8;
        unsigned int inp_cfc0_saturation : 8;
        unsigned int reserved_0 : 8;
        unsigned int inp_cfc0_lp : 2;
        unsigned int reserved_1 : 5;
        unsigned int inp_cfc0_en : 1;
    } reg;
} SOC_ISPCPU_CHIRT_RT_INPORT_CFC_CTRL_UNION;
#endif
#define SOC_ISPCPU_CHIRT_RT_INPORT_CFC_CTRL_inp_cfc0_bw_START (0)
#define SOC_ISPCPU_CHIRT_RT_INPORT_CFC_CTRL_inp_cfc0_bw_END (7)
#define SOC_ISPCPU_CHIRT_RT_INPORT_CFC_CTRL_inp_cfc0_saturation_START (8)
#define SOC_ISPCPU_CHIRT_RT_INPORT_CFC_CTRL_inp_cfc0_saturation_END (15)
#define SOC_ISPCPU_CHIRT_RT_INPORT_CFC_CTRL_inp_cfc0_lp_START (24)
#define SOC_ISPCPU_CHIRT_RT_INPORT_CFC_CTRL_inp_cfc0_lp_END (25)
#define SOC_ISPCPU_CHIRT_RT_INPORT_CFC_CTRL_inp_cfc0_en_START (31)
#define SOC_ISPCPU_CHIRT_RT_INPORT_CFC_CTRL_inp_cfc0_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_inblk_busy : 10;
        unsigned int reserved_0 : 5;
        unsigned int dfx_outblk_busy : 10;
        unsigned int reserved_1 : 5;
        unsigned int dfx_rt_busy : 1;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_ISPCPU_CHIRT_RT_GLB_ST_UNION;
#endif
#define SOC_ISPCPU_CHIRT_RT_GLB_ST_dfx_inblk_busy_START (0)
#define SOC_ISPCPU_CHIRT_RT_GLB_ST_dfx_inblk_busy_END (9)
#define SOC_ISPCPU_CHIRT_RT_GLB_ST_dfx_outblk_busy_START (15)
#define SOC_ISPCPU_CHIRT_RT_GLB_ST_dfx_outblk_busy_END (24)
#define SOC_ISPCPU_CHIRT_RT_GLB_ST_dfx_rt_busy_START (30)
#define SOC_ISPCPU_CHIRT_RT_GLB_ST_dfx_rt_busy_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_inp_err_st : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISPCPU_CHIRT_RT_GLB_INT_ST_UNION;
#endif
#define SOC_ISPCPU_CHIRT_RT_GLB_INT_ST_dfx_inp_err_st_START (0)
#define SOC_ISPCPU_CHIRT_RT_GLB_INT_ST_dfx_inp_err_st_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_bp_cnt : 16;
        unsigned int dfx_sat_cnt : 16;
    } reg;
} SOC_ISPCPU_CHIRT_RT_MAX_LAT_ST_UNION;
#endif
#define SOC_ISPCPU_CHIRT_RT_MAX_LAT_ST_dfx_bp_cnt_START (0)
#define SOC_ISPCPU_CHIRT_RT_MAX_LAT_ST_dfx_bp_cnt_END (15)
#define SOC_ISPCPU_CHIRT_RT_MAX_LAT_ST_dfx_sat_cnt_START (16)
#define SOC_ISPCPU_CHIRT_RT_MAX_LAT_ST_dfx_sat_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_inp_lpc_req : 10;
        unsigned int dfx_inp_lpc_ack : 10;
        unsigned int reserved : 12;
    } reg;
} SOC_ISPCPU_CHIRT_RT_INPORT_LPC_ST_UNION;
#endif
#define SOC_ISPCPU_CHIRT_RT_INPORT_LPC_ST_dfx_inp_lpc_req_START (0)
#define SOC_ISPCPU_CHIRT_RT_INPORT_LPC_ST_dfx_inp_lpc_req_END (9)
#define SOC_ISPCPU_CHIRT_RT_INPORT_LPC_ST_dfx_inp_lpc_ack_START (10)
#define SOC_ISPCPU_CHIRT_RT_INPORT_LPC_ST_dfx_inp_lpc_ack_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_outp_lpc_req : 10;
        unsigned int dfx_outp_lpc_ack : 10;
        unsigned int reserved : 12;
    } reg;
} SOC_ISPCPU_CHIRT_RT_OUTPORT_LPC_ST_UNION;
#endif
#define SOC_ISPCPU_CHIRT_RT_OUTPORT_LPC_ST_dfx_outp_lpc_req_START (0)
#define SOC_ISPCPU_CHIRT_RT_OUTPORT_LPC_ST_dfx_outp_lpc_req_END (9)
#define SOC_ISPCPU_CHIRT_RT_OUTPORT_LPC_ST_dfx_outp_lpc_ack_START (10)
#define SOC_ISPCPU_CHIRT_RT_OUTPORT_LPC_ST_dfx_outp_lpc_ack_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_vcfifo_st : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST0_UNION;
#endif
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST0_dfx_vcfifo_st_START (0)
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST0_dfx_vcfifo_st_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_outp0_arbfifo_st : 2;
        unsigned int dfx_outp1_arbfifo_st : 2;
        unsigned int dfx_outp2_arbfifo_st : 2;
        unsigned int dfx_outp3_arbfifo_st : 2;
        unsigned int dfx_outp4_arbfifo_st : 2;
        unsigned int dfx_outp5_arbfifo_st : 2;
        unsigned int dfx_outp6_arbfifo_st : 2;
        unsigned int dfx_outp7_arbfifo_st : 2;
        unsigned int dfx_outp8_arbfifo_st : 2;
        unsigned int dfx_outp9_arbfifo_st : 2;
        unsigned int reserved : 12;
    } reg;
} SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST2_UNION;
#endif
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST2_dfx_outp0_arbfifo_st_START (0)
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST2_dfx_outp0_arbfifo_st_END (1)
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST2_dfx_outp1_arbfifo_st_START (2)
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST2_dfx_outp1_arbfifo_st_END (3)
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST2_dfx_outp2_arbfifo_st_START (4)
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST2_dfx_outp2_arbfifo_st_END (5)
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST2_dfx_outp3_arbfifo_st_START (6)
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST2_dfx_outp3_arbfifo_st_END (7)
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST2_dfx_outp4_arbfifo_st_START (8)
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST2_dfx_outp4_arbfifo_st_END (9)
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST2_dfx_outp5_arbfifo_st_START (10)
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST2_dfx_outp5_arbfifo_st_END (11)
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST2_dfx_outp6_arbfifo_st_START (12)
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST2_dfx_outp6_arbfifo_st_END (13)
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST2_dfx_outp7_arbfifo_st_START (14)
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST2_dfx_outp7_arbfifo_st_END (15)
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST2_dfx_outp8_arbfifo_st_START (16)
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST2_dfx_outp8_arbfifo_st_END (17)
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST2_dfx_outp9_arbfifo_st_START (18)
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST2_dfx_outp9_arbfifo_st_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_i2o_access_err_st : 1;
        unsigned int dfx_did_ovfl_st : 1;
        unsigned int dfx_rop_ovfl_st : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_ISPCPU_CHIRT_RT_INPORT_INT_ST_UNION;
#endif
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_ST_dfx_i2o_access_err_st_START (0)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_ST_dfx_i2o_access_err_st_END (0)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_ST_dfx_did_ovfl_st_START (1)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_ST_dfx_did_ovfl_st_END (1)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_ST_dfx_rop_ovfl_st_START (2)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_ST_dfx_rop_ovfl_st_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_i2o_access_err_ini : 1;
        unsigned int dfx_did_ovfl_ini : 1;
        unsigned int dfx_rop_ovfl_ini : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_ISPCPU_CHIRT_RT_INPORT_INT_INI_UNION;
#endif
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_INI_dfx_i2o_access_err_ini_START (0)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_INI_dfx_i2o_access_err_ini_END (0)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_INI_dfx_did_ovfl_ini_START (1)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_INI_dfx_did_ovfl_ini_END (1)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_INI_dfx_rop_ovfl_ini_START (2)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_INI_dfx_rop_ovfl_ini_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_err_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISPCPU_CHIRT_RT_INPORT_INT_CLEAR_UNION;
#endif
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_CLEAR_dfx_err_clr_START (0)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_CLEAR_dfx_err_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_i2o_access_err_en : 1;
        unsigned int dfx_did_ovfl_en : 1;
        unsigned int dfx_rop_ovfl_en : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_ISPCPU_CHIRT_RT_INPORT_INT_EN_UNION;
#endif
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_EN_dfx_i2o_access_err_en_START (0)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_EN_dfx_i2o_access_err_en_END (0)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_EN_dfx_did_ovfl_en_START (1)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_EN_dfx_did_ovfl_en_END (1)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_EN_dfx_rop_ovfl_en_START (2)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_EN_dfx_rop_ovfl_en_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_vc_req : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST4_UNION;
#endif
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST4_dfx_vc_req_START (0)
#define SOC_ISPCPU_CHIRT_RT_INPORT_DFX_ST4_dfx_vc_req_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_i2o_access_err_snap : 1;
        unsigned int dfx_did_ovfl_snap : 1;
        unsigned int dfx_rop_ovfl_snap : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_ISPCPU_CHIRT_RT_INPORT_INT_SNP_UNION;
#endif
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_SNP_dfx_i2o_access_err_snap_START (0)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_SNP_dfx_i2o_access_err_snap_END (0)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_SNP_dfx_did_ovfl_snap_START (1)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_SNP_dfx_did_ovfl_snap_END (1)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_SNP_dfx_rop_ovfl_snap_START (2)
#define SOC_ISPCPU_CHIRT_RT_INPORT_INT_SNP_dfx_rop_ovfl_snap_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_vc_crdt_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISPCPU_CHIRT_RT_OUTPORT_DFX_ST0_UNION;
#endif
#define SOC_ISPCPU_CHIRT_RT_OUTPORT_DFX_ST0_dfx_vc_crdt_cnt_START (0)
#define SOC_ISPCPU_CHIRT_RT_OUTPORT_DFX_ST0_dfx_vc_crdt_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_vccrdt_vld : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISPCPU_CHIRT_RT_OUTPORT_DFX_ST1_UNION;
#endif
#define SOC_ISPCPU_CHIRT_RT_OUTPORT_DFX_ST1_dfx_vccrdt_vld_START (0)
#define SOC_ISPCPU_CHIRT_RT_OUTPORT_DFX_ST1_dfx_vccrdt_vld_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intlv_gran : 2;
        unsigned int reserved_0 : 1;
        unsigned int scramble_en : 1;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 2;
        unsigned int reserved_3 : 2;
        unsigned int reserved_4 : 22;
    } reg;
} SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_UNION;
#endif
#define SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_intlv_gran_START (0)
#define SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_intlv_gran_END (1)
#define SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_scramble_en_START (3)
#define SOC_ISPCPU_CHIRT_GLB_ADDR_CTRL_scramble_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int chirt_link_info : 32;
    } reg;
} SOC_ISPCPU_CHIRT_CHIRT_LINK_INFO_UNION;
#endif
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_INFO_chirt_link_info_START (0)
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_INFO_chirt_link_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int link_reserved_rw : 32;
    } reg;
} SOC_ISPCPU_CHIRT_LINK_RESERVED_RW_UNION;
#endif
#define SOC_ISPCPU_CHIRT_LINK_RESERVED_RW_link_reserved_rw_START (0)
#define SOC_ISPCPU_CHIRT_LINK_RESERVED_RW_link_reserved_rw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int link_reserved_ro : 32;
    } reg;
} SOC_ISPCPU_CHIRT_LINK_RESERVED_RO_UNION;
#endif
#define SOC_ISPCPU_CHIRT_LINK_RESERVED_RO_link_reserved_ro_START (0)
#define SOC_ISPCPU_CHIRT_LINK_RESERVED_RO_link_reserved_ro_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ckg_byp_ckg_cfg : 1;
        unsigned int ckg_byp_ckg_lk_rs : 1;
        unsigned int ckg_byp_ckg_lk : 1;
        unsigned int ckg_byp_ckg_rs_req : 1;
        unsigned int ckg_byp_ckg_rs_wdata : 1;
        unsigned int ckg_byp_ckg_rs_rdata : 1;
        unsigned int ckg_byp_ckg_rs_srsp : 1;
        unsigned int ckg_byp_ckg_rs_crsp : 1;
        unsigned int ckg_byp_ckg_rs_snp : 1;
        unsigned int ckg_byp_ckg_sysco : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_ISPCPU_CHIRT_LINK_CKG_BYPS_UNION;
#endif
#define SOC_ISPCPU_CHIRT_LINK_CKG_BYPS_ckg_byp_ckg_cfg_START (0)
#define SOC_ISPCPU_CHIRT_LINK_CKG_BYPS_ckg_byp_ckg_cfg_END (0)
#define SOC_ISPCPU_CHIRT_LINK_CKG_BYPS_ckg_byp_ckg_lk_rs_START (1)
#define SOC_ISPCPU_CHIRT_LINK_CKG_BYPS_ckg_byp_ckg_lk_rs_END (1)
#define SOC_ISPCPU_CHIRT_LINK_CKG_BYPS_ckg_byp_ckg_lk_START (2)
#define SOC_ISPCPU_CHIRT_LINK_CKG_BYPS_ckg_byp_ckg_lk_END (2)
#define SOC_ISPCPU_CHIRT_LINK_CKG_BYPS_ckg_byp_ckg_rs_req_START (3)
#define SOC_ISPCPU_CHIRT_LINK_CKG_BYPS_ckg_byp_ckg_rs_req_END (3)
#define SOC_ISPCPU_CHIRT_LINK_CKG_BYPS_ckg_byp_ckg_rs_wdata_START (4)
#define SOC_ISPCPU_CHIRT_LINK_CKG_BYPS_ckg_byp_ckg_rs_wdata_END (4)
#define SOC_ISPCPU_CHIRT_LINK_CKG_BYPS_ckg_byp_ckg_rs_rdata_START (5)
#define SOC_ISPCPU_CHIRT_LINK_CKG_BYPS_ckg_byp_ckg_rs_rdata_END (5)
#define SOC_ISPCPU_CHIRT_LINK_CKG_BYPS_ckg_byp_ckg_rs_srsp_START (6)
#define SOC_ISPCPU_CHIRT_LINK_CKG_BYPS_ckg_byp_ckg_rs_srsp_END (6)
#define SOC_ISPCPU_CHIRT_LINK_CKG_BYPS_ckg_byp_ckg_rs_crsp_START (7)
#define SOC_ISPCPU_CHIRT_LINK_CKG_BYPS_ckg_byp_ckg_rs_crsp_END (7)
#define SOC_ISPCPU_CHIRT_LINK_CKG_BYPS_ckg_byp_ckg_rs_snp_START (8)
#define SOC_ISPCPU_CHIRT_LINK_CKG_BYPS_ckg_byp_ckg_rs_snp_END (8)
#define SOC_ISPCPU_CHIRT_LINK_CKG_BYPS_ckg_byp_ckg_sysco_START (9)
#define SOC_ISPCPU_CHIRT_LINK_CKG_BYPS_ckg_byp_ckg_sysco_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 31;
        unsigned int icfg_ckg_ext_ena : 1;
    } reg;
} SOC_ISPCPU_CHIRT_CHIRT_LINK_CKG_EXT_EN_UNION;
#endif
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_CKG_EXT_EN_icfg_ckg_ext_ena_START (31)
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_CKG_EXT_EN_icfg_ckg_ext_ena_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_syscoack_enable_high : 1;
        unsigned int icfg_syscoack_enable_low : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ISPCPU_CHIRT_CHIRT_LINK_SYSCOACK_UNION;
#endif
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_SYSCOACK_icfg_syscoack_enable_high_START (0)
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_SYSCOACK_icfg_syscoack_enable_high_END (0)
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_SYSCOACK_icfg_syscoack_enable_low_START (1)
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_SYSCOACK_icfg_syscoack_enable_low_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_txsactive_high : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISPCPU_CHIRT_CHIRT_LINK_TXSACTIVE_UNION;
#endif
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_TXSACTIVE_icfg_txsactive_high_START (0)
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_TXSACTIVE_icfg_txsactive_high_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_tx_link_active_ack : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISPCPU_CHIRT_CHIRT_LINK_TX_LINK_ACK_UNION;
#endif
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_TX_LINK_ACK_icfg_tx_link_active_ack_START (0)
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_TX_LINK_ACK_icfg_tx_link_active_ack_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_rx_link_active_req : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISPCPU_CHIRT_CHIRT_LINK_RX_LINK_REQ_UNION;
#endif
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_RX_LINK_REQ_icfg_rx_link_active_req_START (0)
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_RX_LINK_REQ_icfg_rx_link_active_req_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_chi_mst_srcid : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_ISPCPU_CHIRT_CHIRT_LINK_MST_SRCID_UNION;
#endif
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_MST_SRCID_icfg_chi_mst_srcid_START (0)
#define SOC_ISPCPU_CHIRT_CHIRT_LINK_MST_SRCID_icfg_chi_mst_srcid_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_rx_link_stat : 2;
        unsigned int dfx_tx_link_stat : 2;
        unsigned int dfx_get_all_crd : 1;
        unsigned int dfx_link_busy : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_ISPCPU_CHIRT_CHI_RT_DFX_LINK_STAT_UNION;
#endif
#define SOC_ISPCPU_CHIRT_CHI_RT_DFX_LINK_STAT_dfx_rx_link_stat_START (0)
#define SOC_ISPCPU_CHIRT_CHI_RT_DFX_LINK_STAT_dfx_rx_link_stat_END (1)
#define SOC_ISPCPU_CHIRT_CHI_RT_DFX_LINK_STAT_dfx_tx_link_stat_START (2)
#define SOC_ISPCPU_CHIRT_CHI_RT_DFX_LINK_STAT_dfx_tx_link_stat_END (3)
#define SOC_ISPCPU_CHIRT_CHI_RT_DFX_LINK_STAT_dfx_get_all_crd_START (4)
#define SOC_ISPCPU_CHIRT_CHI_RT_DFX_LINK_STAT_dfx_get_all_crd_END (4)
#define SOC_ISPCPU_CHIRT_CHI_RT_DFX_LINK_STAT_dfx_link_busy_START (5)
#define SOC_ISPCPU_CHIRT_CHI_RT_DFX_LINK_STAT_dfx_link_busy_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_chi_cpu_syscoreq : 1;
        unsigned int dfx_chi_cpu_syscoack : 1;
        unsigned int dfx_chi_sc_syscoreq : 8;
        unsigned int reserved_0 : 2;
        unsigned int dfx_chi_sc_syscoack : 8;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 10;
    } reg;
} SOC_ISPCPU_CHIRT_CHI_RT_DFX_SYSCO_STAT_UNION;
#endif
#define SOC_ISPCPU_CHIRT_CHI_RT_DFX_SYSCO_STAT_dfx_chi_cpu_syscoreq_START (0)
#define SOC_ISPCPU_CHIRT_CHI_RT_DFX_SYSCO_STAT_dfx_chi_cpu_syscoreq_END (0)
#define SOC_ISPCPU_CHIRT_CHI_RT_DFX_SYSCO_STAT_dfx_chi_cpu_syscoack_START (1)
#define SOC_ISPCPU_CHIRT_CHI_RT_DFX_SYSCO_STAT_dfx_chi_cpu_syscoack_END (1)
#define SOC_ISPCPU_CHIRT_CHI_RT_DFX_SYSCO_STAT_dfx_chi_sc_syscoreq_START (2)
#define SOC_ISPCPU_CHIRT_CHI_RT_DFX_SYSCO_STAT_dfx_chi_sc_syscoreq_END (9)
#define SOC_ISPCPU_CHIRT_CHI_RT_DFX_SYSCO_STAT_dfx_chi_sc_syscoack_START (12)
#define SOC_ISPCPU_CHIRT_CHI_RT_DFX_SYSCO_STAT_dfx_chi_sc_syscoack_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_ckg_busy_sysco : 1;
        unsigned int dfx_ckg_busy_lk : 1;
        unsigned int dfx_ckg_busy_cfg : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_ISPCPU_CHIRT_CHI_RT_DFX_CKG_STAT_UNION;
#endif
#define SOC_ISPCPU_CHIRT_CHI_RT_DFX_CKG_STAT_dfx_ckg_busy_sysco_START (0)
#define SOC_ISPCPU_CHIRT_CHI_RT_DFX_CKG_STAT_dfx_ckg_busy_sysco_END (0)
#define SOC_ISPCPU_CHIRT_CHI_RT_DFX_CKG_STAT_dfx_ckg_busy_lk_START (1)
#define SOC_ISPCPU_CHIRT_CHI_RT_DFX_CKG_STAT_dfx_ckg_busy_lk_END (1)
#define SOC_ISPCPU_CHIRT_CHI_RT_DFX_CKG_STAT_dfx_ckg_busy_cfg_START (2)
#define SOC_ISPCPU_CHIRT_CHI_RT_DFX_CKG_STAT_dfx_ckg_busy_cfg_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int prdata_prot : 8;
        unsigned int prdata_tout : 8;
        unsigned int pslverr_prot : 1;
        unsigned int pslverr_tout : 1;
        unsigned int reserved_0 : 2;
        unsigned int tout_prd : 4;
        unsigned int nersp_prd : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISPCPU_CHIRT_APCR_CTRL_UNION;
#endif
#define SOC_ISPCPU_CHIRT_APCR_CTRL_prdata_prot_START (0)
#define SOC_ISPCPU_CHIRT_APCR_CTRL_prdata_prot_END (7)
#define SOC_ISPCPU_CHIRT_APCR_CTRL_prdata_tout_START (8)
#define SOC_ISPCPU_CHIRT_APCR_CTRL_prdata_tout_END (15)
#define SOC_ISPCPU_CHIRT_APCR_CTRL_pslverr_prot_START (16)
#define SOC_ISPCPU_CHIRT_APCR_CTRL_pslverr_prot_END (16)
#define SOC_ISPCPU_CHIRT_APCR_CTRL_pslverr_tout_START (17)
#define SOC_ISPCPU_CHIRT_APCR_CTRL_pslverr_tout_END (17)
#define SOC_ISPCPU_CHIRT_APCR_CTRL_tout_prd_START (20)
#define SOC_ISPCPU_CHIRT_APCR_CTRL_tout_prd_END (23)
#define SOC_ISPCPU_CHIRT_APCR_CTRL_nersp_prd_START (24)
#define SOC_ISPCPU_CHIRT_APCR_CTRL_nersp_prd_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int protzone_cfg_s2ns : 1;
        unsigned int reserved_0 : 3;
        unsigned int protzone_cfg_ns2s : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_ISPCPU_CHIRT_PROT_CTRL_UNION;
#endif
#define SOC_ISPCPU_CHIRT_PROT_CTRL_protzone_cfg_s2ns_START (0)
#define SOC_ISPCPU_CHIRT_PROT_CTRL_protzone_cfg_s2ns_END (0)
#define SOC_ISPCPU_CHIRT_PROT_CTRL_protzone_cfg_ns2s_START (4)
#define SOC_ISPCPU_CHIRT_PROT_CTRL_protzone_cfg_ns2s_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmst_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISPCPU_CHIRT_PMST_CTRL_UNION;
#endif
#define SOC_ISPCPU_CHIRT_PMST_CTRL_pmst_en_START (0)
#define SOC_ISPCPU_CHIRT_PMST_CTRL_pmst_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int chain_wack_en : 32;
    } reg;
} SOC_ISPCPU_CHIRT_CHAIN_WACK_UNION;
#endif
#define SOC_ISPCPU_CHIRT_CHAIN_WACK_chain_wack_en_START (0)
#define SOC_ISPCPU_CHIRT_CHAIN_WACK_chain_wack_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmst_ctrl_lock_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISPCPU_CHIRT_LOCK_SEL_UNION;
#endif
#define SOC_ISPCPU_CHIRT_LOCK_SEL_pmst_ctrl_lock_sel_START (0)
#define SOC_ISPCPU_CHIRT_LOCK_SEL_pmst_ctrl_lock_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pslverr_prot : 1;
        unsigned int pslverr_tout : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ISPCPU_CHIRT_PSLVERR_TYPE_UNION;
#endif
#define SOC_ISPCPU_CHIRT_PSLVERR_TYPE_pslverr_prot_START (0)
#define SOC_ISPCPU_CHIRT_PSLVERR_TYPE_pslverr_prot_END (0)
#define SOC_ISPCPU_CHIRT_PSLVERR_TYPE_pslverr_tout_START (0)
#define SOC_ISPCPU_CHIRT_PSLVERR_TYPE_pslverr_tout_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timeout_cnt_min_value : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ISPCPU_CHIRT_TIMEOUT_CNT_MIN_VALUE_UNION;
#endif
#define SOC_ISPCPU_CHIRT_TIMEOUT_CNT_MIN_VALUE_timeout_cnt_min_value_START (0)
#define SOC_ISPCPU_CHIRT_TIMEOUT_CNT_MIN_VALUE_timeout_cnt_min_value_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pnode_en : 32;
    } reg;
} SOC_ISPCPU_CHIRT_PNODE_EN_UNION;
#endif
#define SOC_ISPCPU_CHIRT_PNODE_EN_pnode_en_START (0)
#define SOC_ISPCPU_CHIRT_PNODE_EN_pnode_en_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
