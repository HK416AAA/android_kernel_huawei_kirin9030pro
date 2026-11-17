#ifndef __SOC_SC_INTERFACE_H__
#define __SOC_SC_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_GLB_CFGCMO_CMD_L_ADDR(base) ((base) + 0x4000UL)
#define SOC_GLB_CFGCMO_CMD_H_ADDR(base) ((base) + 0x4004UL)
#else
#define SOC_GLB_CFGCMO_CMD_L_ADDR(base) ((base) + 0x4000)
#define SOC_GLB_CFGCMO_CMD_H_ADDR(base) ((base) + 0x4004)
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_SC_CFG_CMO_REGULAR_EVT_TIME_ADDR(base) ((base) + 0x5020UL)
#define SOC_CFG_CMO_STATUS_ADDR(base,cmo_st) ((base) + 0x5100UL + (cmo_st) * 0x4UL)
#define SOC_CFG_CMO_CLEAR_ADDR(base,cmo_st) ((base) + 0x5200UL + (cmo_st) * 0x4UL)
#define SOC_SC_CFG_CMO_QUEUE_CNT_ADDR(base) ((base) + 0x5300UL)
#define SOC_SC_CFG_CMO_MERGE_BUSY_CTRL_ADDR(base) ((base) + 0x5400UL)
#define SOC_SC_CFG_CMO_DFX_INT_S_STATUS_ADDR(base) ((base) + 0x5500UL)
#define SOC_SC_CFG_CMO_SYNCBUF_INT_S_STATUS_ADDR(base) ((base) + 0x5504UL)
#define SOC_SC_CFG_CMO_DFX_INT_NS_STATUS_ADDR(base) ((base) + 0x5508UL)
#define SOC_SC_CFG_CMO_NOPENDING_STATUS_ADDR(base) ((base) + 0x5510UL)
#define SOC_SC_CFG_CMO_BUSY_STATUS_ADDR(base) ((base) + 0x5514UL)
#define SOC_SC_CFG_CMO_PERF_IDLE_STATUS_ADDR(base) ((base) + 0x5518UL)
#define SOC_SC_CFG_ABNML_NS_INT_CTRL0_ADDR(base) ((base) + 0x5E00UL)
#define SOC_SC_CFG_ABNML_NS_INT_CTRL1_ADDR(base) ((base) + 0x5E04UL)
#define SOC_SC_CFG_ABNML_NS_INT_CTRL2_ADDR(base) ((base) + 0x5E08UL)
#define SOC_SC_CFG_ABNML_NS_INT_STATUS0_ADDR(base) ((base) + 0x5E10UL)
#define SOC_SC_CFG_ABNML_NS_INT_STATUS1_ADDR(base) ((base) + 0x5E14UL)
#define SOC_SC_CFG_ABNML_NS_INT_STATUS2_ADDR(base) ((base) + 0x5E18UL)
#define SOC_SC_CFG_ABNML_NS_INT_CLR_ADDR(base) ((base) + 0x5E1CUL)
#define SOC_SC_CFG_ABNML_NS_INT_INFO0_ADDR(base) ((base) + 0x5E20UL)
#define SOC_SC_CFG_ABNML_NS_INT_INFO1_ADDR(base) ((base) + 0x5E24UL)
#define SOC_SC_CFG_GLB_SEC_CTRL_ADDR(base) ((base) + 0x7000UL)
#define SOC_SC_CFG_SLICE_SEC_CTRL_ADDR(base) ((base) + 0x7004UL)
#define SOC_SC_CFG_DEFSLV_RESP_CTRL_ADDR(base) ((base) + 0x7100UL)
#define SOC_SC_CHAIN_WACK_ADDR(base) ((base) + 0x7200UL)
#define SOC_SC_APCR_CTRL_ADDR(base) ((base) + 0x7204UL)
#define SOC_SC_CFG_ALLOW_MID_S_ADDR(base) ((base) + 0x7300UL)
#define SOC_SC_CFG_CMO_EN_ADDR_HOLE_S_ADDR(base) ((base) + 0x7400UL)
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_0_S_ADDR(base) ((base) + 0x7410UL)
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_0_S_ADDR(base) ((base) + 0x7414UL)
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_1_S_ADDR(base) ((base) + 0x7418UL)
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_1_S_ADDR(base) ((base) + 0x741CUL)
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_2_S_ADDR(base) ((base) + 0x7420UL)
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_2_S_ADDR(base) ((base) + 0x7424UL)
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_3_S_ADDR(base) ((base) + 0x7428UL)
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_3_S_ADDR(base) ((base) + 0x742CUL)
#define SOC_SC_CFG_CMO_TPMEM_CTRL_S_ADDR(base) ((base) + 0x7430UL)
#define SOC_SC_CFG_CMO_SET_S_ADDR(base) ((base) + 0x7440UL)
#define SOC_SC_CFG_BRC_RDATA_SEL_ADDR(base) ((base) + 0x7500UL)
#define SOC_SC_CFG_CMOCKG_CTRL_ADDR(base) ((base) + 0x7600UL)
#else
#define SOC_SC_CFG_CMO_REGULAR_EVT_TIME_ADDR(base) ((base) + 0x5020)
#define SOC_CFG_CMO_STATUS_ADDR(base,cmo_st) ((base) + 0x5100 + (cmo_st) * 0x4)
#define SOC_CFG_CMO_CLEAR_ADDR(base,cmo_st) ((base) + 0x5200 + (cmo_st) * 0x4)
#define SOC_SC_CFG_CMO_QUEUE_CNT_ADDR(base) ((base) + 0x5300)
#define SOC_SC_CFG_CMO_MERGE_BUSY_CTRL_ADDR(base) ((base) + 0x5400)
#define SOC_SC_CFG_CMO_DFX_INT_S_STATUS_ADDR(base) ((base) + 0x5500)
#define SOC_SC_CFG_CMO_SYNCBUF_INT_S_STATUS_ADDR(base) ((base) + 0x5504)
#define SOC_SC_CFG_CMO_DFX_INT_NS_STATUS_ADDR(base) ((base) + 0x5508)
#define SOC_SC_CFG_CMO_NOPENDING_STATUS_ADDR(base) ((base) + 0x5510)
#define SOC_SC_CFG_CMO_BUSY_STATUS_ADDR(base) ((base) + 0x5514)
#define SOC_SC_CFG_CMO_PERF_IDLE_STATUS_ADDR(base) ((base) + 0x5518)
#define SOC_SC_CFG_ABNML_NS_INT_CTRL0_ADDR(base) ((base) + 0x5E00)
#define SOC_SC_CFG_ABNML_NS_INT_CTRL1_ADDR(base) ((base) + 0x5E04)
#define SOC_SC_CFG_ABNML_NS_INT_CTRL2_ADDR(base) ((base) + 0x5E08)
#define SOC_SC_CFG_ABNML_NS_INT_STATUS0_ADDR(base) ((base) + 0x5E10)
#define SOC_SC_CFG_ABNML_NS_INT_STATUS1_ADDR(base) ((base) + 0x5E14)
#define SOC_SC_CFG_ABNML_NS_INT_STATUS2_ADDR(base) ((base) + 0x5E18)
#define SOC_SC_CFG_ABNML_NS_INT_CLR_ADDR(base) ((base) + 0x5E1C)
#define SOC_SC_CFG_ABNML_NS_INT_INFO0_ADDR(base) ((base) + 0x5E20)
#define SOC_SC_CFG_ABNML_NS_INT_INFO1_ADDR(base) ((base) + 0x5E24)
#define SOC_SC_CFG_GLB_SEC_CTRL_ADDR(base) ((base) + 0x7000)
#define SOC_SC_CFG_SLICE_SEC_CTRL_ADDR(base) ((base) + 0x7004)
#define SOC_SC_CFG_DEFSLV_RESP_CTRL_ADDR(base) ((base) + 0x7100)
#define SOC_SC_CHAIN_WACK_ADDR(base) ((base) + 0x7200)
#define SOC_SC_APCR_CTRL_ADDR(base) ((base) + 0x7204)
#define SOC_SC_CFG_ALLOW_MID_S_ADDR(base) ((base) + 0x7300)
#define SOC_SC_CFG_CMO_EN_ADDR_HOLE_S_ADDR(base) ((base) + 0x7400)
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_0_S_ADDR(base) ((base) + 0x7410)
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_0_S_ADDR(base) ((base) + 0x7414)
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_1_S_ADDR(base) ((base) + 0x7418)
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_1_S_ADDR(base) ((base) + 0x741C)
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_2_S_ADDR(base) ((base) + 0x7420)
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_2_S_ADDR(base) ((base) + 0x7424)
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_3_S_ADDR(base) ((base) + 0x7428)
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_3_S_ADDR(base) ((base) + 0x742C)
#define SOC_SC_CFG_CMO_TPMEM_CTRL_S_ADDR(base) ((base) + 0x7430)
#define SOC_SC_CFG_CMO_SET_S_ADDR(base) ((base) + 0x7440)
#define SOC_SC_CFG_BRC_RDATA_SEL_ADDR(base) ((base) + 0x7500)
#define SOC_SC_CFG_CMOCKG_CTRL_ADDR(base) ((base) + 0x7600)
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_SC_STATIS_SLICE_CTRL0_ADDR(base,sc_statis_num) ((base) + 0x200UL + (sc_statis_num) * 0x8UL)
#define SOC_SC_STATIS_SLICE_CTRL1_ADDR(base,sc_statis_num) ((base) + 0x200UL + 0x004UL + (sc_statis_num) * 0x8UL)
#define SOC_SC_STATIS_GLB_EN_ADDR(base) ((base) + 0x0220UL)
#define SOC_SC_CMOQ_QUOTA_CNT_ADDR(base) ((base) + 0x0240UL)
#define SOC_SC_MPAM_WAY_ALLC_ADDR(base,mpam_idx) ((base) + 0x0250UL + (mpam_idx) * 0x4UL)
#define SOC_SC_REPLACE_MPAM_PTID_CFG_ADDR(base,mpam_idx) ((base) + 0x0290UL + (mpam_idx) * 4)
#define SOC_SC_MPAM_CTRL0_ADDR(base) ((base) + 0x02D0UL)
#define SOC_SC_DUMMY_REG0_ADDR(base) ((base) + 0x0300UL)
#define SOC_SC_ABNML_INT_NS_GLB_MASK_ADDR(base) ((base) + 0x0400UL)
#define SOC_SC_ABNML_INT_NS_CLR_ADDR(base) ((base) + 0x0404UL)
#define SOC_SC_ABNML_INT_NS_MASK_ADDR(base,abnml_int_ns_idx) ((base) + 0x0408UL + (abnml_int_ns_idx) * 0x10UL)
#define SOC_SC_ABNML_INT_NS_DIS_ADDR(base,abnml_int_ns_idx) ((base) + 0x040CUL + (abnml_int_ns_idx) * 0x10UL)
#define SOC_SC_ABNML_INT_NS_ORG_STATUS_ADDR(base,abnml_int_ns_idx) ((base) + 0x0410UL + (abnml_int_ns_idx) * 0x10UL)
#define SOC_SC_ABNML_INT_NS_MASK_STATUS_ADDR(base,abnml_int_ns_idx) ((base) + 0x0414UL + (abnml_int_ns_idx) * 0x10UL)
#define SOC_SC_ABNML_INT_NS_TYPE_ADDR(base) ((base) + 0x0448UL)
#define SOC_SC_ABNML_INT_NS_INFO_ADDR(base,dfx_info_num) ((base) + 0x0450UL + (dfx_info_num) * 0x4UL)
#define SOC_SC_DLOCK_INT_GLB_MASK_ADDR(base) ((base) + 0x0480UL)
#define SOC_SC_DLOCK_INT_CLR_ADDR(base) ((base) + 0x0484UL)
#define SOC_SC_DLOCK_INT_MASK_ADDR(base) ((base) + 0x0488UL)
#define SOC_SC_DLOCK_INT_DIS_ADDR(base) ((base) + 0x048CUL)
#define SOC_SC_DLOCK_INT_ORG_STATUS_ADDR(base) ((base) + 0x0490UL)
#define SOC_SC_DLOCK_INT_MASK_STATUS_ADDR(base) ((base) + 0x0494UL)
#define SOC_SC_DLOCK_INT_TYPE_ADDR(base) ((base) + 0x0498UL)
#define SOC_SC_DLOCK_INT_INFO_ADDR(base,dfx_info_num) ((base) + 0x04A0UL + (dfx_info_num) * 0x4UL)
#define SOC_SC_TAG_SF_ECC_ERR_CNT_CLR_ADDR(base) ((base) + 0x0500UL)
#define SOC_SC_TAG_SF_ECC_ERR_CNT_ADDR(base) ((base) + 0x0504UL)
#define SOC_SC_DMEM_ECC_ERR_CNT_ADDR(base) ((base) + 0x0510UL)
#define SOC_SC_DMEM_ECC_ERR_ADDR_ADDR(base) ((base) + 0x0514UL)
#define SOC_SC_CGID_WAY_ALLC_ADDR(base,cgid_idx) ((base) + 0x0600UL + (cgid_idx) * 0x10UL)
#define SOC_SC_CGID_WAY_SEARCH_ADDR(base,cgid_idx) ((base) + 0x0604UL + (cgid_idx) * 0x10UL)
#define SOC_SC_CGID_CFG_ADDR(base,cgid_idx) ((base) + 0x0608UL + (cgid_idx) * 0x10UL)
#define SOC_SC_CGID_QUOTA_ADDR(base,cgid_idx) ((base) + 0x060CUL + (cgid_idx) * 0x10UL)
#define SOC_SC_GID_SEC_ATTR_S_ADDR(base,pgid_idx) ((base) + 0x0800UL + (pgid_idx) * 0x20UL)
#define SOC_SC_QOS_MAP_ADDR(base) ((base) + 0x1000UL + 0x120UL)
#define SOC_SC_PRI_QOS_CTRL0_ADDR(base) ((base) + 0x1000UL + 0x140UL)
#define SOC_SC_PRI_QOS_CTRL1_ADDR(base) ((base) + 0x1000UL + 0x144UL)
#define SOC_SC_FECQ_WRR_WEIGHT_ADDR(base) ((base) + 0x1000UL + 0x160UL)
#define SOC_SC_MSTIF_WRR_WEIGHT_ADDR(base) ((base) + 0x1000UL + 0x164UL)
#define SOC_SC_RSV_CTRL0_ADDR(base) ((base) + 0x1000UL + 0x170UL)
#define SOC_SC_RSV_CTRL1_ADDR(base) ((base) + 0x1000UL + 0x17CUL)
#define SOC_SC_TKN_PRI_CFG0_ADDR(base) ((base) + 0x1000UL + 0x204UL)
#define SOC_SC_TKN_PRI_CFG1_ADDR(base) ((base) + 0x1000UL + 0x208UL)
#define SOC_SC_TKN_PRI_CFG2_ADDR(base) ((base) + 0x1000UL + 0x20CUL)
#define SOC_SC_TKN_WEIGHT_CFG0_ADDR(base) ((base) + 0x1000UL + 0x210UL)
#define SOC_SC_TKN_WEIGHT_CFG1_ADDR(base) ((base) + 0x1000UL + 0x214UL)
#define SOC_SC_TKN_WEIGHT_CFG2_ADDR(base) ((base) + 0x1000UL + 0x218UL)
#define SOC_SC_TKN_WEIGHT_CFG3_ADDR(base) ((base) + 0x1000UL + 0x21CUL)
#define SOC_SC_TKN_WEIGHT_CFG4_ADDR(base) ((base) + 0x1000UL + 0x220UL)
#define SOC_SC_MST_TOKEN_CFG0_ADDR(base,mst_tkn_rsv_idx) (base) + 0x1000 + 0x224 + 0x4 * (mst_tkn_rsv_idx)
#define SOC_SC_FECQ_TOKEN_CFG0_ADDR(base) ((base) + 0x1000UL + 0x22CUL)
#define SOC_SC_QOS_RGLR_ADDR(base) ((base) + 0x1000UL + 0x300UL)
#define SOC_SC_MST_DYN_CFC_LIMIT_ADDR(base,sc_pri_num) ((base) + 0x1000UL + 0x310UL + (sc_pri_num) * 0x4UL)
#define SOC_SC_MST_STA_CFC_LIMIT_ADDR(base) ((base) + 0x1000UL + 0x324UL)
#define SOC_SC_MST_QOSALLOW_MAP_ADDR(base) ((base) + 0x1000UL + 0x328UL)
#define SOC_SC_TH_CTRL0_ADDR(base) ((base) + 0x1000UL + 0x400UL)
#define SOC_SC_TH_CTRL1_ADDR(base) ((base) + 0x1000UL + 0x404UL)
#define SOC_SC_TH_CTRL2_ADDR(base) ((base) + 0x1000UL + 0x408UL)
#define SOC_SC_TH_CTRL3_ADDR(base) ((base) + 0x1000UL + 0x40CUL)
#define SOC_SC_TH_CTRL4_ADDR(base) ((base) + 0x1000UL + 0x410UL)
#define SOC_SC_TH_CTRL5_ADDR(base) ((base) + 0x1000UL + 0x414UL)
#define SOC_SC_TH_BY_PRI_CTRL0_ADDR(base,sc_pri_num) ((base) + 0x1000UL + 0x480UL + (sc_pri_num) * 0x20UL)
#define SOC_SC_TH_BY_PRI_CTRL1_ADDR(base,sc_pri_num) ((base) + 0x1000UL + 0x484UL + (sc_pri_num) * 0x20UL)
#define SOC_SC_FECQ_QOS_ALLOW_TH_ADDR(base,qos_allow_num) ((base) + 0x1000UL + 0x500UL + (qos_allow_num) * 0x10UL)
#define SOC_SC_BECQ_ALLOC_MASK_ADDR(base,sc_becq_num_div32) ((base) + 0x1000UL + 0x5A0UL + (sc_becq_num_div32) * 0x4UL)
#define SOC_SC_FLUSH_CMOQ_CTRL0_ADDR(base) ((base) + 0x1000UL + 0x5B0UL)
#define SOC_SC_TIMEOUT_CTRL0_ADDR(base) ((base) + 0x1000UL + 0x700UL)
#define SOC_SC_TIMEOUT_CTRL1_ADDR(base) ((base) + 0x1000UL + 0x704UL)
#define SOC_SC_TIMEOUT_CTRL2_ADDR(base) ((base) + 0x1000UL + 0x708UL)
#define SOC_SC_TIMEOUT_CTRL3_ADDR(base) ((base) + 0x1000UL + 0x70CUL)
#define SOC_SC_TIMEOUT_CTRL4_ADDR(base) ((base) + 0x1000UL + 0x710UL)
#define SOC_SC_TIMEOUT_CTRL5_ADDR(base) ((base) + 0x1000UL + 0x714UL)
#define SOC_SC_TIMEOUT_BY_FECQ_CTRL0_ADDR(base,sc_fecq_num) ((base) + 0x1000UL + 0x720UL + (sc_fecq_num) * 0x4UL)
#define SOC_SC_TIMEOUT_BY_PRI_CTRL0_ADDR(base,sc_pri_num) ((base) + 0x1000UL + 0x780UL + (sc_pri_num) * 0x20UL)
#define SOC_SC_TIMEOUT_BY_PRI_CTRL1_ADDR(base,sc_pri_num) ((base) + 0x1000UL + 0x784UL + (sc_pri_num) * 0x20UL)
#define SOC_SC_TIMEOUT_BY_PRI_CTRL2_ADDR(base,sc_pri_num) ((base) + 0x1000UL + 0x788UL + (sc_pri_num) * 0x20UL)
#define SOC_SC_DUMMY_REG1_ADDR(base) ((base) + 0x1000UL + 0x800UL)
#define SOC_SC_GLB_ADDR_CTRL_ADDR(base) ((base) + 0x2000UL + 0x00CUL)
#define SOC_SC_GLB_ADDR_CTRL1_ADDR(base) ((base) + 0x2000UL + 0x010UL)
#define SOC_SC_GLB_PIPE_CTRL_ADDR(base) ((base) + 0x2000UL + 0x014UL)
#define SOC_SC_BASE_CTRL0_ADDR(base) ((base) + 0x2000UL + 0x018UL)
#define SOC_SC_FST_WAKEUP_CTRL0_ADDR(base) ((base) + 0x2000UL + 0x01CUL)
#define SOC_SC_FST_WAKEUP_CTRL1_ADDR(base) ((base) + 0x2000UL + 0x020UL)
#define SOC_SC_FST_WAKEUP_CTRL2_ADDR(base) ((base) + 0x2000UL + 0x024UL)
#define SOC_SC_FST_WAKEUP_CTRL3_ADDR(base) ((base) + 0x2000UL + 0x028UL)
#define SOC_SC_FST_WAKEUP_CTRL4_ADDR(base) ((base) + 0x2000UL + 0x02CUL)
#define SOC_SC_SMQ_CTRL_ADDR(base) ((base) + 0x2000UL + 0x030UL)
#define SOC_SC_GLB_WAY_EN_ADDR(base) ((base) + 0x2000UL + 0x034UL)
#define SOC_SC_SYNCBUF_USED_WAY_ADDR(base) ((base) + 0x2000UL + 0x038UL)
#define SOC_SC_TAG_GLB_WAY_SEARCH_ADDR(base) ((base) + 0x2000UL + 0x03CUL)
#define SOC_SC_SF_GLB_WAY_SEARCH_ADDR(base) ((base) + 0x2000UL + 0x040UL)
#define SOC_SC_TPIPE_CTRL0_ADDR(base) ((base) + 0x2000UL + 0x090UL)
#define SOC_SC_TPIPE_CTRL1_ADDR(base) ((base) + 0x2000UL + 0x094UL)
#define SOC_SC_BECQ_CTRL0_ADDR(base) ((base) + 0x2000UL + 0x100UL)
#define SOC_SC_BECQ_STATUS0_ADDR(base) ((base) + 0x2000UL + 0x10CUL)
#define SOC_SC_SPEC_RD_SWITCH_CTRL0_ADDR(base) ((base) + 0x2000UL + 0x200UL)
#define SOC_SC_FEDB_BEDB_CTRL0_ADDR(base) ((base) + 0x2000UL + 0x210UL)
#define SOC_SC_FEDB_BEDB_CTRL1_ADDR(base) ((base) + 0x2000UL + 0x214UL)
#define SOC_SC_DMEM_MSTINTF_CFG0_ADDR(base) ((base) + 0x2000UL + 0x220UL)
#define SOC_SC_VICPIPE_CTRL0_ADDR(base) ((base) + 0x2000UL + 0x230UL)
#define SOC_SC_CKG_CTRL0_ADDR(base) ((base) + 0x2000UL + 0x520UL)
#define SOC_SC_CKG_CTRL1_ADDR(base) ((base) + 0x2000UL + 0x524UL)
#define SOC_SC_CFG_GID_SEC_CTRL_ADDR(base) ((base) + 0x2000UL + 0x600UL)
#define SOC_SC_CFG_GID_SEC_CTRL1_ADDR(base) ((base) + 0x2000UL + 0x604UL)
#define SOC_SC_CFG_CGID_SEC_CTRL_ADDR(base) ((base) + 0x2000UL + 0x608UL)
#define SOC_SC_SEC_BOOT_LOCK_CTRL0_ADDR(base) ((base) + 0x2000UL + 0x700UL)
#define SOC_SC_SEC_BOOT_LOCK_CTRL1_ADDR(base) ((base) + 0x2000UL + 0x704UL)
#define SOC_SC_SEC_BOOT_LOCK_STATUS0_ADDR(base) ((base) + 0x2000UL + 0x708UL)
#define SOC_SC_SEC_BOOT_LOCK_STATUS1_ADDR(base) ((base) + 0x2000UL + 0x70CUL)
#define SOC_SC_SEC_USER_CTRL0_ADDR(base) ((base) + 0x2000UL + 0x710UL)
#define SOC_SC_CFG_PGID_DROP_EN0_ADDR(base) ((base) + 0x2000UL + 0x714UL)
#define SOC_SC_CFG_PGID_DROP_EN1_ADDR(base) ((base) + 0x2000UL + 0x718UL)
#define SOC_SC_SCC_SEC_CTRL_ADDR(base) ((base) + 0x2000UL + 0x71CUL)
#define SOC_SC_CFG_MID_CTRL_ADDR(base,cfg_mid_idx) (base) + 0x2000 + 0x730 + 0x4 * (cfg_mid_idx)
#define SOC_SC_MID_TRUST_WR_NSTRUST_ADDR(base,mid_group_idx) ((base) + 0x2000UL + 0x800UL + (mid_group_idx) * 0x4UL)
#define SOC_SC_DRC_SEC_CTRL_ADDR(base) ((base) + 0x2000UL + 0x820UL)
#define SOC_SC_DUMMY_REG2_ADDR(base) ((base) + 0x2000UL + 0x900UL)
#define SOC_SC_ABNML_INT_S_GLB_MASK_ADDR(base) ((base) + 0x2000UL + 0xA00UL)
#define SOC_SC_ABNML_INT_S_CLR_ADDR(base) ((base) + 0x2000UL + 0xA04UL)
#define SOC_SC_ABNML_INT_S_MASK_ADDR(base) ((base) + 0x2000UL + 0xA08UL)
#define SOC_SC_ABNML_INT_S_DIS_ADDR(base) ((base) + 0x2000UL + 0xA0CUL)
#define SOC_SC_ABNML_INT_S_ORG_STATUS_ADDR(base) ((base) + 0x2000UL + 0xA10UL)
#define SOC_SC_ABNML_INT_S_MASK_STATUS_ADDR(base) ((base) + 0x2000UL + 0xA14UL)
#define SOC_SC_ABNML_INT_S_TYPE_ADDR(base) ((base) + 0x2000UL + 0xA18UL)
#define SOC_SC_ABNML_INT_S_INFO_ADDR(base,dfx_info_num) ((base) + 0x2000UL + 0xA20UL + (dfx_info_num) * 0x4UL)
#define SOC_SC_PARITY_INT_GLB_MASK_ADDR(base) ((base) + 0x2000UL + 0xA40UL)
#define SOC_SC_PARITY_INT_CLR_ADDR(base) ((base) + 0x2000UL + 0xA44UL)
#define SOC_SC_PARITY_INT_MASK_ADDR(base) ((base) + 0x2000UL + 0xA48UL)
#define SOC_SC_PARITY_INT_DIS_ADDR(base) ((base) + 0x2000UL + 0xA4CUL)
#define SOC_SC_PARITY_INT_ORG_STATUS_ADDR(base) ((base) + 0x2000UL + 0xA50UL)
#define SOC_SC_PARITY_INT_MASK_STATUS_ADDR(base) ((base) + 0x2000UL + 0xA54UL)
#define SOC_SC_PARITY_INT_TYPE_ADDR(base) ((base) + 0x2000UL + 0xA58UL)
#define SOC_SC_PARITY_INT_INFO_ADDR(base,dfx_info_num) ((base) + 0x2000UL + 0xA60UL + (dfx_info_num) * 0x4UL)
#define SOC_SC_DBG_PORT_IN0_ADDR(base) ((base) + 0x2000UL + 0xB00UL)
#define SOC_SC_DBG_PORT_IN1_ADDR(base) ((base) + 0x2000UL + 0xB04UL)
#define SOC_SC_DBG_PORT_IN2_ADDR(base) ((base) + 0x2000UL + 0xB08UL)
#define SOC_SC_DBG_PORT_OUT_ADDR(base,dbg_info_num) ((base) + 0x2000UL + 0xB10UL + (dbg_info_num) * 0x4UL)
#define SOC_SC_IDLE_STATUS0_ADDR(base) ((base) + 0x2000UL + 0xB40UL)
#define SOC_SC_PMU_FECQ_CTRL0_ADDR(base,sc_fecq_num) ((base) + 0x2000UL + 0xC00UL + (sc_fecq_num) * 0x04UL)
#define SOC_SC_PMU_FECQ_CTRL1_ADDR(base) ((base) + 0x2000UL + 0xC10UL)
#define SOC_SC_PMU_FEDB_CTRL0_ADDR(base) ((base) + 0x2000UL + 0xC14UL)
#define SOC_SC_PMU_TPIPE_CTRL0_ADDR(base) ((base) + 0x2000UL + 0xC20UL)
#define SOC_SC_PMU_TPIPE_CTRL1_ADDR(base) ((base) + 0x2000UL + 0xC24UL)
#define SOC_SC_PMU_BECQ_CTRL0_ADDR(base) ((base) + 0x2000UL + 0xC30UL)
#define SOC_SC_PMU_BECQ_CTRL1_ADDR(base) ((base) + 0x2000UL + 0xC34UL)
#define SOC_SC_PMU_BECQ_FSM_EN0_ADDR(base,becq_pmu_fsm) ((base) + 0x2000UL + 0xC40UL + (becq_pmu_fsm) * 0x4UL)
#define SOC_SC_PMU_BECQ_FSM_EN1_ADDR(base,becq_pmu_fsm) ((base) + 0x2000UL + 0xC50UL + (becq_pmu_fsm) * 0x4UL)
#define SOC_SC_PMU_OTHER_CTRL0_ADDR(base) ((base) + 0x2000UL + 0xC60UL)
#define SOC_SC_PMU_OTHER_CTRL1_ADDR(base) ((base) + 0x2000UL + 0xC64UL)
#define SOC_SC_PMU_FLT_CTRL0_ADDR(base) ((base) + 0x2000UL + 0xC70UL)
#define SOC_SC_PMU_FLT_CTRL1_ADDR(base) ((base) + 0x2000UL + 0xC74UL)
#define SOC_SC_PMU_FLT_CTRL2_ADDR(base) ((base) + 0x2000UL + 0xC78UL)
#define SOC_SC_PMU_FLT_CTRL3_ADDR(base) ((base) + 0x2000UL + 0xC7CUL)
#define SOC_SC_PMU_FLT_CTRL4_ADDR(base) ((base) + 0x2000UL + 0xC80UL)
#define SOC_SC_PMU_FLT_SNP_CTRL0_ADDR(base) ((base) + 0x2000UL + 0xC90UL)
#define SOC_SC_PMU_FLT_SNP_CTRL1_ADDR(base) ((base) + 0x2000UL + 0xC94UL)
#define SOC_SC_PMU_SNP_SMP_TH_ADDR(base) ((base) + 0x2000UL + 0xCA0UL)
#define SOC_SC_PMU_EVCNT_ADDR(base,sc_pmu_idx) ((base) + 0x2000UL + 0xD80UL + (sc_pmu_idx) * 0x4UL)
#define SOC_SC_PMU_EVSVR_ADDR(base,sc_pmu_idx) ((base) + 0x2000UL + 0xDA0UL + (sc_pmu_idx) * 0x4UL)
#define SOC_SC_PMU_EVTYPE_ADDR(base,sc_pmu_idx) ((base) + 0x2000UL + 0xDC0UL + (sc_pmu_idx) * 0x4UL)
#define SOC_SC_PMU_CNTEN_ADDR(base) ((base) + 0x2000UL + 0xDE0UL)
#define SOC_SC_PMU_OV_ADDR(base) ((base) + 0x2000UL + 0xDE4UL)
#define SOC_SC_PMU_CFG_ADDR(base) ((base) + 0x2000UL + 0xDE8UL)
#define SOC_SC_PMU_CAPR_ADDR(base) ((base) + 0x2000UL + 0xDECUL)
#define SOC_SC_PMU_INT_GLB_MASK_ADDR(base) ((base) + 0x2000UL + 0xDF0UL)
#define SOC_SC_PMU_INT_CLR_ADDR(base) ((base) + 0x2000UL + 0xDF4UL)
#define SOC_SC_PMU_INT_MASK_ADDR(base) ((base) + 0x2000UL + 0xDF8UL)
#define SOC_SC_PMU_INT_DIS_ADDR(base) ((base) + 0x2000UL + 0xDFCUL)
#define SOC_SC_PMU_INT_ORG_STATUS_ADDR(base) ((base) + 0x2000UL + 0xE00UL)
#define SOC_SC_PMU_INT_MASK_STATUS_ADDR(base) ((base) + 0x2000UL + 0xE04UL)
#define SOC_SC_TMEM_SLP_PARAM_ADDR(base) ((base) + 0x2000UL + 0xF00UL)
#define SOC_SC_DMEM_SLP_PARAM_ADDR(base) ((base) + 0x2000UL + 0xF04UL)
#define SOC_SC_SMEM_SLP_PARAM_ADDR(base) ((base) + 0x2000UL + 0xF08UL)
#define SOC_SC_TMEM_STA_CFG0_ADDR(base) ((base) + 0x2000UL + 0xF20UL)
#define SOC_SC_TMEM_STA_CFG1_ADDR(base) ((base) + 0x2000UL + 0xF24UL)
#define SOC_SC_DMEM_STA_CFG0_ADDR(base) ((base) + 0x2000UL + 0xF28UL)
#define SOC_SC_DMEM_STA_CFG1_ADDR(base) ((base) + 0x2000UL + 0xF2CUL)
#define SOC_SC_SMEM_STA_CFG0_ADDR(base) ((base) + 0x2000UL + 0xF30UL)
#define SOC_SC_SMEM_STA_CFG1_ADDR(base) ((base) + 0x2000UL + 0xF34UL)
#define SOC_SC_MEM_LP_CTRL0_ADDR(base) ((base) + 0x2000UL + 0xF40UL)
#define SOC_SC_MEM_LP_CTRL1_ADDR(base) ((base) + 0x2000UL + 0xF44UL)
#define SOC_SC_TMEM_LP_SLP_CFG_ADDR(base) ((base) + 0x2000UL + 0xF60UL)
#define SOC_SC_DMEM_LP_SLP_CFG_ADDR(base) ((base) + 0x2000UL + 0xF64UL)
#define SOC_SC_SMEM_LP_SLP_CFG_ADDR(base) ((base) + 0x2000UL + 0xF68UL)
#define SOC_SC_TMEM_WAY_PWRUP_ADDR(base) ((base) + 0x2000UL + 0xF80UL)
#define SOC_SC_DMEM_WAY_PWRUP_ADDR(base) ((base) + 0x2000UL + 0xF84UL)
#define SOC_SC_SMEM_WAY_PWRUP_ADDR(base) ((base) + 0x2000UL + 0xF88UL)
#define SOC_SC_TMEM_WAY_INIT_ADDR(base) ((base) + 0x2000UL + 0xFA0UL)
#define SOC_SC_DMEM_WAY_INIT_ADDR(base) ((base) + 0x2000UL + 0xFA4UL)
#define SOC_SC_SMEM_WAY_INIT_ADDR(base) ((base) + 0x2000UL + 0xFA8UL)
#define SOC_SC_DMEM_SPC_ADDR(base) ((base) + 0x2000UL + 0xFC0UL)
#define SOC_SC_BEDB_SPC_ADDR(base) ((base) + 0x2000UL + 0xFC4UL)
#define SOC_SC_VICTIM_SPC_ADDR(base) ((base) + 0x2000UL + 0xFC8UL)
#define SOC_SC_SFRAM_SPC_ADDR(base) ((base) + 0x2000UL + 0xFCCUL)
#define SOC_SC_TAGRAM_SPC_ADDR(base) ((base) + 0x2000UL + 0xFD0UL)
#define SOC_SC_CGID_STATUS0_ADDR(base,cgid_idx) ((base) + 0x4000UL + (cgid_idx) * 0x8UL)
#define SOC_SC_GID_BYP_SWITCH_STATUS_ADDR(base,pgid_byp_idx) ((base) + 0x4000UL + 0x080UL + (pgid_byp_idx) * 0x4UL)
#define SOC_SC_STATIS_CNT_IN_ADDR(base,sc_statis_num) ((base) + 0x4000UL + 0x180UL + (sc_statis_num) * 0x8UL)
#define SOC_SC_STATIS_CNT_OUT_ADDR(base,sc_statis_num) ((base) + 0x4000UL + 0x184UL + (sc_statis_num) * 0x8UL)
#define SOC_SC_SMQ_STATUS3_ADDR(base) ((base) + 0x41C0UL)
#define SOC_SC_SMQ_STATUS4_ADDR(base) ((base) + 0x41C4UL)
#define SOC_SC_TAGRAM_LP_STATUS0_ADDR(base) ((base) + 0x6000UL)
#define SOC_SC_TAGRAM_LP_STATUS1_ADDR(base) ((base) + 0x6004UL)
#define SOC_SC_SFRAM_LP_STATUS_ADDR(base) ((base) + 0x6008UL)
#define SOC_SC_DRAM_LP_STATUS0_ADDR(base) ((base) + 0x600CUL)
#define SOC_SC_DRAM_LP_STATUS1_ADDR(base) ((base) + 0x6010UL)
#define SOC_SC_TAGRAM_LPC_DFX0_ADDR(base) ((base) + 0x6014UL)
#define SOC_SC_TAGRAM_LPC_DFX1_ADDR(base) ((base) + 0x6018UL)
#define SOC_SC_SFRAM_LPC_DFX0_ADDR(base) ((base) + 0x601CUL)
#define SOC_SC_DRAM_LPC_DFX0_ADDR(base) ((base) + 0x6020UL)
#define SOC_SC_DRAM_LPC_DFX1_ADDR(base) ((base) + 0x6024UL)
#define SOC_SC_DRAM_LPC_DFX2_ADDR(base) ((base) + 0x6028UL)
#define SOC_SC_SMQ_STATUS_ADDR(base) ((base) + 0x6030UL)
#define SOC_SC_SMQ_STATUS2_ADDR(base) ((base) + 0x6034UL)
#define SOC_SC_GID_CFG_ADDR(base,pgid_idx) ((base) + 0xC000UL + (pgid_idx) * 4)
#define SOC_SC_REPLACE_RRPV_CFG_ADDR(base) ((base) + 0xC140UL)
#define SOC_SC_GLB_SEC_REG_CTRL_ADDR(base) ((base) + 0x8000UL + 0x2010UL)
#define SOC_SC_SEC_RGN_LOCK_SET_ADDR(base) ((base) + 0x8000UL + 0x2014UL)
#define SOC_SC_SEC_RGN_LOCK_CLR_ADDR(base) ((base) + 0x8000UL + 0x2018UL)
#define SOC_SC_SEC_RGN_LOCK_ST_ADDR(base) ((base) + 0x8000UL + 0x201CUL)
#define SOC_SC_SEC_RGN_CTRL_ADDR(base,S) (base) + 0x8000 + 0x2100 + 16 * (S)
#define SOC_SC_SEC_RGN_ADDR_CTRL_ADDR(base,S) (base) + 0x8000 + 0x2104 + 16 * (S)
#define SOC_SC_SEC_RGN_MID_CTRL_R_ADDR(base,S) (base) + 0x8000 + 0x2108 + 16 * (S)
#define SOC_SC_SEC_RGN_MID_CTRL_W_ADDR(base,S) (base) + 0x8000 + 0x210C + 16 * (S)
#define SOC_SC_SYNCBUF_ABNML_INT_S_GLB_MASK_ADDR(base) ((base) + 0x8000UL + 0x2230UL)
#define SOC_SC_SYNCBUF_ABNML_INT_S_CLR_ADDR(base) ((base) + 0x8000UL + 0x2234UL)
#define SOC_SC_SYNCBUF_ABNML_INT_S_MASK_ADDR(base) ((base) + 0x8000UL + 0x2238UL)
#define SOC_SC_SYNCBUF_ABNML_INT_S_DIS_ADDR(base) ((base) + 0x8000UL + 0x223CUL)
#define SOC_SC_SYNCBUF_ABNML_INT_S_ORG_STATUS_ADDR(base) ((base) + 0x8000UL + 0x2240UL)
#define SOC_SC_SYNCBUF_ABNML_INT_S_MASK_STATUS_ADDR(base) ((base) + 0x8000UL + 0x2244UL)
#define SOC_SC_SYNCBUF_ABNML_INT_S_TYPE_ADDR(base) ((base) + 0x8000UL + 0x2248UL)
#define SOC_SC_SYNCBUF_ABNML_INT_S_INFO_ADDR(base,dfx_info_num) ((base) + 0x8000UL + 0x2250UL + (dfx_info_num) * 0x4UL)
#define SOC_SC_GLB_REMAP_CTRL_ADDR(base) ((base) + 0x8000UL + 0x2400UL)
#define SOC_SC_BC_ADDR_REMAP0_ADDR(base,R) (base) + 0x8000 + 0x2500 + 4 * (R)
#else
#define SOC_SC_STATIS_SLICE_CTRL0_ADDR(base,sc_statis_num) ((base) + 0x200 + (sc_statis_num) * 0x8)
#define SOC_SC_STATIS_SLICE_CTRL1_ADDR(base,sc_statis_num) ((base) + 0x200 + 0x004 + (sc_statis_num) * 0x8)
#define SOC_SC_STATIS_GLB_EN_ADDR(base) ((base) + 0x0220)
#define SOC_SC_CMOQ_QUOTA_CNT_ADDR(base) ((base) + 0x0240)
#define SOC_SC_MPAM_WAY_ALLC_ADDR(base,mpam_idx) ((base) + 0x0250 + (mpam_idx) * 0x4)
#define SOC_SC_REPLACE_MPAM_PTID_CFG_ADDR(base,mpam_idx) ((base) + 0x0290 + (mpam_idx) * 4)
#define SOC_SC_MPAM_CTRL0_ADDR(base) ((base) + 0x02D0)
#define SOC_SC_DUMMY_REG0_ADDR(base) ((base) + 0x0300)
#define SOC_SC_ABNML_INT_NS_GLB_MASK_ADDR(base) ((base) + 0x0400)
#define SOC_SC_ABNML_INT_NS_CLR_ADDR(base) ((base) + 0x0404)
#define SOC_SC_ABNML_INT_NS_MASK_ADDR(base,abnml_int_ns_idx) ((base) + 0x0408 + (abnml_int_ns_idx) * 0x10)
#define SOC_SC_ABNML_INT_NS_DIS_ADDR(base,abnml_int_ns_idx) ((base) + 0x040C + (abnml_int_ns_idx) * 0x10)
#define SOC_SC_ABNML_INT_NS_ORG_STATUS_ADDR(base,abnml_int_ns_idx) ((base) + 0x0410 + (abnml_int_ns_idx) * 0x10)
#define SOC_SC_ABNML_INT_NS_MASK_STATUS_ADDR(base,abnml_int_ns_idx) ((base) + 0x0414 + (abnml_int_ns_idx) * 0x10)
#define SOC_SC_ABNML_INT_NS_TYPE_ADDR(base) ((base) + 0x0448)
#define SOC_SC_ABNML_INT_NS_INFO_ADDR(base,dfx_info_num) ((base) + 0x0450 + (dfx_info_num) * 0x4)
#define SOC_SC_DLOCK_INT_GLB_MASK_ADDR(base) ((base) + 0x0480)
#define SOC_SC_DLOCK_INT_CLR_ADDR(base) ((base) + 0x0484)
#define SOC_SC_DLOCK_INT_MASK_ADDR(base) ((base) + 0x0488)
#define SOC_SC_DLOCK_INT_DIS_ADDR(base) ((base) + 0x048C)
#define SOC_SC_DLOCK_INT_ORG_STATUS_ADDR(base) ((base) + 0x0490)
#define SOC_SC_DLOCK_INT_MASK_STATUS_ADDR(base) ((base) + 0x0494)
#define SOC_SC_DLOCK_INT_TYPE_ADDR(base) ((base) + 0x0498)
#define SOC_SC_DLOCK_INT_INFO_ADDR(base,dfx_info_num) ((base) + 0x04A0 + (dfx_info_num) * 0x4)
#define SOC_SC_TAG_SF_ECC_ERR_CNT_CLR_ADDR(base) ((base) + 0x0500)
#define SOC_SC_TAG_SF_ECC_ERR_CNT_ADDR(base) ((base) + 0x0504)
#define SOC_SC_DMEM_ECC_ERR_CNT_ADDR(base) ((base) + 0x0510)
#define SOC_SC_DMEM_ECC_ERR_ADDR_ADDR(base) ((base) + 0x0514)
#define SOC_SC_CGID_WAY_ALLC_ADDR(base,cgid_idx) ((base) + 0x0600 + (cgid_idx) * 0x10)
#define SOC_SC_CGID_WAY_SEARCH_ADDR(base,cgid_idx) ((base) + 0x0604 + (cgid_idx) * 0x10)
#define SOC_SC_CGID_CFG_ADDR(base,cgid_idx) ((base) + 0x0608 + (cgid_idx) * 0x10)
#define SOC_SC_CGID_QUOTA_ADDR(base,cgid_idx) ((base) + 0x060C + (cgid_idx) * 0x10)
#define SOC_SC_GID_SEC_ATTR_S_ADDR(base,pgid_idx) ((base) + 0x0800 + (pgid_idx) * 0x20)
#define SOC_SC_QOS_MAP_ADDR(base) ((base) + 0x1000 + 0x120)
#define SOC_SC_PRI_QOS_CTRL0_ADDR(base) ((base) + 0x1000 + 0x140)
#define SOC_SC_PRI_QOS_CTRL1_ADDR(base) ((base) + 0x1000 + 0x144)
#define SOC_SC_FECQ_WRR_WEIGHT_ADDR(base) ((base) + 0x1000 + 0x160)
#define SOC_SC_MSTIF_WRR_WEIGHT_ADDR(base) ((base) + 0x1000 + 0x164)
#define SOC_SC_RSV_CTRL0_ADDR(base) ((base) + 0x1000 + 0x170)
#define SOC_SC_RSV_CTRL1_ADDR(base) ((base) + 0x1000 + 0x17C)
#define SOC_SC_TKN_PRI_CFG0_ADDR(base) ((base) + 0x1000 + 0x204)
#define SOC_SC_TKN_PRI_CFG1_ADDR(base) ((base) + 0x1000 + 0x208)
#define SOC_SC_TKN_PRI_CFG2_ADDR(base) ((base) + 0x1000 + 0x20C)
#define SOC_SC_TKN_WEIGHT_CFG0_ADDR(base) ((base) + 0x1000 + 0x210)
#define SOC_SC_TKN_WEIGHT_CFG1_ADDR(base) ((base) + 0x1000 + 0x214)
#define SOC_SC_TKN_WEIGHT_CFG2_ADDR(base) ((base) + 0x1000 + 0x218)
#define SOC_SC_TKN_WEIGHT_CFG3_ADDR(base) ((base) + 0x1000 + 0x21C)
#define SOC_SC_TKN_WEIGHT_CFG4_ADDR(base) ((base) + 0x1000 + 0x220)
#define SOC_SC_MST_TOKEN_CFG0_ADDR(base,mst_tkn_rsv_idx) (base) + 0x1000 + 0x224 + 0x4 * (mst_tkn_rsv_idx)
#define SOC_SC_FECQ_TOKEN_CFG0_ADDR(base) ((base) + 0x1000 + 0x22C)
#define SOC_SC_QOS_RGLR_ADDR(base) ((base) + 0x1000 + 0x300)
#define SOC_SC_MST_DYN_CFC_LIMIT_ADDR(base,sc_pri_num) ((base) + 0x1000 + 0x310 + (sc_pri_num) * 0x4)
#define SOC_SC_MST_STA_CFC_LIMIT_ADDR(base) ((base) + 0x1000 + 0x324)
#define SOC_SC_MST_QOSALLOW_MAP_ADDR(base) ((base) + 0x1000 + 0x328)
#define SOC_SC_TH_CTRL0_ADDR(base) ((base) + 0x1000 + 0x400)
#define SOC_SC_TH_CTRL1_ADDR(base) ((base) + 0x1000 + 0x404)
#define SOC_SC_TH_CTRL2_ADDR(base) ((base) + 0x1000 + 0x408)
#define SOC_SC_TH_CTRL3_ADDR(base) ((base) + 0x1000 + 0x40C)
#define SOC_SC_TH_CTRL4_ADDR(base) ((base) + 0x1000 + 0x410)
#define SOC_SC_TH_CTRL5_ADDR(base) ((base) + 0x1000 + 0x414)
#define SOC_SC_TH_BY_PRI_CTRL0_ADDR(base,sc_pri_num) ((base) + 0x1000 + 0x480 + (sc_pri_num) * 0x20)
#define SOC_SC_TH_BY_PRI_CTRL1_ADDR(base,sc_pri_num) ((base) + 0x1000 + 0x484 + (sc_pri_num) * 0x20)
#define SOC_SC_FECQ_QOS_ALLOW_TH_ADDR(base,qos_allow_num) ((base) + 0x1000 + 0x500 + (qos_allow_num) * 0x10)
#define SOC_SC_BECQ_ALLOC_MASK_ADDR(base,sc_becq_num_div32) ((base) + 0x1000 + 0x5A0 + (sc_becq_num_div32) * 0x4)
#define SOC_SC_FLUSH_CMOQ_CTRL0_ADDR(base) ((base) + 0x1000 + 0x5B0)
#define SOC_SC_TIMEOUT_CTRL0_ADDR(base) ((base) + 0x1000 + 0x700)
#define SOC_SC_TIMEOUT_CTRL1_ADDR(base) ((base) + 0x1000 + 0x704)
#define SOC_SC_TIMEOUT_CTRL2_ADDR(base) ((base) + 0x1000 + 0x708)
#define SOC_SC_TIMEOUT_CTRL3_ADDR(base) ((base) + 0x1000 + 0x70C)
#define SOC_SC_TIMEOUT_CTRL4_ADDR(base) ((base) + 0x1000 + 0x710)
#define SOC_SC_TIMEOUT_CTRL5_ADDR(base) ((base) + 0x1000 + 0x714)
#define SOC_SC_TIMEOUT_BY_FECQ_CTRL0_ADDR(base,sc_fecq_num) ((base) + 0x1000 + 0x720 + (sc_fecq_num) * 0x4)
#define SOC_SC_TIMEOUT_BY_PRI_CTRL0_ADDR(base,sc_pri_num) ((base) + 0x1000 + 0x780 + (sc_pri_num) * 0x20)
#define SOC_SC_TIMEOUT_BY_PRI_CTRL1_ADDR(base,sc_pri_num) ((base) + 0x1000 + 0x784 + (sc_pri_num) * 0x20)
#define SOC_SC_TIMEOUT_BY_PRI_CTRL2_ADDR(base,sc_pri_num) ((base) + 0x1000 + 0x788 + (sc_pri_num) * 0x20)
#define SOC_SC_DUMMY_REG1_ADDR(base) ((base) + 0x1000 + 0x800)
#define SOC_SC_GLB_ADDR_CTRL_ADDR(base) ((base) + 0x2000 + 0x00C)
#define SOC_SC_GLB_ADDR_CTRL1_ADDR(base) ((base) + 0x2000 + 0x010)
#define SOC_SC_GLB_PIPE_CTRL_ADDR(base) ((base) + 0x2000 + 0x014)
#define SOC_SC_BASE_CTRL0_ADDR(base) ((base) + 0x2000 + 0x018)
#define SOC_SC_FST_WAKEUP_CTRL0_ADDR(base) ((base) + 0x2000 + 0x01C)
#define SOC_SC_FST_WAKEUP_CTRL1_ADDR(base) ((base) + 0x2000 + 0x020)
#define SOC_SC_FST_WAKEUP_CTRL2_ADDR(base) ((base) + 0x2000 + 0x024)
#define SOC_SC_FST_WAKEUP_CTRL3_ADDR(base) ((base) + 0x2000 + 0x028)
#define SOC_SC_FST_WAKEUP_CTRL4_ADDR(base) ((base) + 0x2000 + 0x02C)
#define SOC_SC_SMQ_CTRL_ADDR(base) ((base) + 0x2000 + 0x030)
#define SOC_SC_GLB_WAY_EN_ADDR(base) ((base) + 0x2000 + 0x034)
#define SOC_SC_SYNCBUF_USED_WAY_ADDR(base) ((base) + 0x2000 + 0x038)
#define SOC_SC_TAG_GLB_WAY_SEARCH_ADDR(base) ((base) + 0x2000 + 0x03C)
#define SOC_SC_SF_GLB_WAY_SEARCH_ADDR(base) ((base) + 0x2000 + 0x040)
#define SOC_SC_TPIPE_CTRL0_ADDR(base) ((base) + 0x2000 + 0x090)
#define SOC_SC_TPIPE_CTRL1_ADDR(base) ((base) + 0x2000 + 0x094)
#define SOC_SC_BECQ_CTRL0_ADDR(base) ((base) + 0x2000 + 0x100)
#define SOC_SC_BECQ_STATUS0_ADDR(base) ((base) + 0x2000 + 0x10C)
#define SOC_SC_SPEC_RD_SWITCH_CTRL0_ADDR(base) ((base) + 0x2000 + 0x200)
#define SOC_SC_FEDB_BEDB_CTRL0_ADDR(base) ((base) + 0x2000 + 0x210)
#define SOC_SC_FEDB_BEDB_CTRL1_ADDR(base) ((base) + 0x2000 + 0x214)
#define SOC_SC_DMEM_MSTINTF_CFG0_ADDR(base) ((base) + 0x2000 + 0x220)
#define SOC_SC_VICPIPE_CTRL0_ADDR(base) ((base) + 0x2000 + 0x230)
#define SOC_SC_CKG_CTRL0_ADDR(base) ((base) + 0x2000 + 0x520)
#define SOC_SC_CKG_CTRL1_ADDR(base) ((base) + 0x2000 + 0x524)
#define SOC_SC_CFG_GID_SEC_CTRL_ADDR(base) ((base) + 0x2000 + 0x600)
#define SOC_SC_CFG_GID_SEC_CTRL1_ADDR(base) ((base) + 0x2000 + 0x604)
#define SOC_SC_CFG_CGID_SEC_CTRL_ADDR(base) ((base) + 0x2000 + 0x608)
#define SOC_SC_SEC_BOOT_LOCK_CTRL0_ADDR(base) ((base) + 0x2000 + 0x700)
#define SOC_SC_SEC_BOOT_LOCK_CTRL1_ADDR(base) ((base) + 0x2000 + 0x704)
#define SOC_SC_SEC_BOOT_LOCK_STATUS0_ADDR(base) ((base) + 0x2000 + 0x708)
#define SOC_SC_SEC_BOOT_LOCK_STATUS1_ADDR(base) ((base) + 0x2000 + 0x70C)
#define SOC_SC_SEC_USER_CTRL0_ADDR(base) ((base) + 0x2000 + 0x710)
#define SOC_SC_CFG_PGID_DROP_EN0_ADDR(base) ((base) + 0x2000 + 0x714)
#define SOC_SC_CFG_PGID_DROP_EN1_ADDR(base) ((base) + 0x2000 + 0x718)
#define SOC_SC_SCC_SEC_CTRL_ADDR(base) ((base) + 0x2000 + 0x71C)
#define SOC_SC_CFG_MID_CTRL_ADDR(base,cfg_mid_idx) (base) + 0x2000 + 0x730 + 0x4 * (cfg_mid_idx)
#define SOC_SC_MID_TRUST_WR_NSTRUST_ADDR(base,mid_group_idx) ((base) + 0x2000 + 0x800 + (mid_group_idx) * 0x4)
#define SOC_SC_DRC_SEC_CTRL_ADDR(base) ((base) + 0x2000 + 0x820)
#define SOC_SC_DUMMY_REG2_ADDR(base) ((base) + 0x2000 + 0x900)
#define SOC_SC_ABNML_INT_S_GLB_MASK_ADDR(base) ((base) + 0x2000 + 0xA00)
#define SOC_SC_ABNML_INT_S_CLR_ADDR(base) ((base) + 0x2000 + 0xA04)
#define SOC_SC_ABNML_INT_S_MASK_ADDR(base) ((base) + 0x2000 + 0xA08)
#define SOC_SC_ABNML_INT_S_DIS_ADDR(base) ((base) + 0x2000 + 0xA0C)
#define SOC_SC_ABNML_INT_S_ORG_STATUS_ADDR(base) ((base) + 0x2000 + 0xA10)
#define SOC_SC_ABNML_INT_S_MASK_STATUS_ADDR(base) ((base) + 0x2000 + 0xA14)
#define SOC_SC_ABNML_INT_S_TYPE_ADDR(base) ((base) + 0x2000 + 0xA18)
#define SOC_SC_ABNML_INT_S_INFO_ADDR(base,dfx_info_num) ((base) + 0x2000 + 0xA20 + (dfx_info_num) * 0x4)
#define SOC_SC_PARITY_INT_GLB_MASK_ADDR(base) ((base) + 0x2000 + 0xA40)
#define SOC_SC_PARITY_INT_CLR_ADDR(base) ((base) + 0x2000 + 0xA44)
#define SOC_SC_PARITY_INT_MASK_ADDR(base) ((base) + 0x2000 + 0xA48)
#define SOC_SC_PARITY_INT_DIS_ADDR(base) ((base) + 0x2000 + 0xA4C)
#define SOC_SC_PARITY_INT_ORG_STATUS_ADDR(base) ((base) + 0x2000 + 0xA50)
#define SOC_SC_PARITY_INT_MASK_STATUS_ADDR(base) ((base) + 0x2000 + 0xA54)
#define SOC_SC_PARITY_INT_TYPE_ADDR(base) ((base) + 0x2000 + 0xA58)
#define SOC_SC_PARITY_INT_INFO_ADDR(base,dfx_info_num) ((base) + 0x2000 + 0xA60 + (dfx_info_num) * 0x4)
#define SOC_SC_DBG_PORT_IN0_ADDR(base) ((base) + 0x2000 + 0xB00)
#define SOC_SC_DBG_PORT_IN1_ADDR(base) ((base) + 0x2000 + 0xB04)
#define SOC_SC_DBG_PORT_IN2_ADDR(base) ((base) + 0x2000 + 0xB08)
#define SOC_SC_DBG_PORT_OUT_ADDR(base,dbg_info_num) ((base) + 0x2000 + 0xB10 + (dbg_info_num) * 0x4)
#define SOC_SC_IDLE_STATUS0_ADDR(base) ((base) + 0x2000 + 0xB40)
#define SOC_SC_PMU_FECQ_CTRL0_ADDR(base,sc_fecq_num) ((base) + 0x2000 + 0xC00 + (sc_fecq_num) * 0x04)
#define SOC_SC_PMU_FECQ_CTRL1_ADDR(base) ((base) + 0x2000 + 0xC10)
#define SOC_SC_PMU_FEDB_CTRL0_ADDR(base) ((base) + 0x2000 + 0xC14)
#define SOC_SC_PMU_TPIPE_CTRL0_ADDR(base) ((base) + 0x2000 + 0xC20)
#define SOC_SC_PMU_TPIPE_CTRL1_ADDR(base) ((base) + 0x2000 + 0xC24)
#define SOC_SC_PMU_BECQ_CTRL0_ADDR(base) ((base) + 0x2000 + 0xC30)
#define SOC_SC_PMU_BECQ_CTRL1_ADDR(base) ((base) + 0x2000 + 0xC34)
#define SOC_SC_PMU_BECQ_FSM_EN0_ADDR(base,becq_pmu_fsm) ((base) + 0x2000 + 0xC40 + (becq_pmu_fsm) * 0x4)
#define SOC_SC_PMU_BECQ_FSM_EN1_ADDR(base,becq_pmu_fsm) ((base) + 0x2000 + 0xC50 + (becq_pmu_fsm) * 0x4)
#define SOC_SC_PMU_OTHER_CTRL0_ADDR(base) ((base) + 0x2000 + 0xC60)
#define SOC_SC_PMU_OTHER_CTRL1_ADDR(base) ((base) + 0x2000 + 0xC64)
#define SOC_SC_PMU_FLT_CTRL0_ADDR(base) ((base) + 0x2000 + 0xC70)
#define SOC_SC_PMU_FLT_CTRL1_ADDR(base) ((base) + 0x2000 + 0xC74)
#define SOC_SC_PMU_FLT_CTRL2_ADDR(base) ((base) + 0x2000 + 0xC78)
#define SOC_SC_PMU_FLT_CTRL3_ADDR(base) ((base) + 0x2000 + 0xC7C)
#define SOC_SC_PMU_FLT_CTRL4_ADDR(base) ((base) + 0x2000 + 0xC80)
#define SOC_SC_PMU_FLT_SNP_CTRL0_ADDR(base) ((base) + 0x2000 + 0xC90)
#define SOC_SC_PMU_FLT_SNP_CTRL1_ADDR(base) ((base) + 0x2000 + 0xC94)
#define SOC_SC_PMU_SNP_SMP_TH_ADDR(base) ((base) + 0x2000 + 0xCA0)
#define SOC_SC_PMU_EVCNT_ADDR(base,sc_pmu_idx) ((base) + 0x2000 + 0xD80 + (sc_pmu_idx) * 0x4)
#define SOC_SC_PMU_EVSVR_ADDR(base,sc_pmu_idx) ((base) + 0x2000 + 0xDA0 + (sc_pmu_idx) * 0x4)
#define SOC_SC_PMU_EVTYPE_ADDR(base,sc_pmu_idx) ((base) + 0x2000 + 0xDC0 + (sc_pmu_idx) * 0x4)
#define SOC_SC_PMU_CNTEN_ADDR(base) ((base) + 0x2000 + 0xDE0)
#define SOC_SC_PMU_OV_ADDR(base) ((base) + 0x2000 + 0xDE4)
#define SOC_SC_PMU_CFG_ADDR(base) ((base) + 0x2000 + 0xDE8)
#define SOC_SC_PMU_CAPR_ADDR(base) ((base) + 0x2000 + 0xDEC)
#define SOC_SC_PMU_INT_GLB_MASK_ADDR(base) ((base) + 0x2000 + 0xDF0)
#define SOC_SC_PMU_INT_CLR_ADDR(base) ((base) + 0x2000 + 0xDF4)
#define SOC_SC_PMU_INT_MASK_ADDR(base) ((base) + 0x2000 + 0xDF8)
#define SOC_SC_PMU_INT_DIS_ADDR(base) ((base) + 0x2000 + 0xDFC)
#define SOC_SC_PMU_INT_ORG_STATUS_ADDR(base) ((base) + 0x2000 + 0xE00)
#define SOC_SC_PMU_INT_MASK_STATUS_ADDR(base) ((base) + 0x2000 + 0xE04)
#define SOC_SC_TMEM_SLP_PARAM_ADDR(base) ((base) + 0x2000 + 0xF00)
#define SOC_SC_DMEM_SLP_PARAM_ADDR(base) ((base) + 0x2000 + 0xF04)
#define SOC_SC_SMEM_SLP_PARAM_ADDR(base) ((base) + 0x2000 + 0xF08)
#define SOC_SC_TMEM_STA_CFG0_ADDR(base) ((base) + 0x2000 + 0xF20)
#define SOC_SC_TMEM_STA_CFG1_ADDR(base) ((base) + 0x2000 + 0xF24)
#define SOC_SC_DMEM_STA_CFG0_ADDR(base) ((base) + 0x2000 + 0xF28)
#define SOC_SC_DMEM_STA_CFG1_ADDR(base) ((base) + 0x2000 + 0xF2C)
#define SOC_SC_SMEM_STA_CFG0_ADDR(base) ((base) + 0x2000 + 0xF30)
#define SOC_SC_SMEM_STA_CFG1_ADDR(base) ((base) + 0x2000 + 0xF34)
#define SOC_SC_MEM_LP_CTRL0_ADDR(base) ((base) + 0x2000 + 0xF40)
#define SOC_SC_MEM_LP_CTRL1_ADDR(base) ((base) + 0x2000 + 0xF44)
#define SOC_SC_TMEM_LP_SLP_CFG_ADDR(base) ((base) + 0x2000 + 0xF60)
#define SOC_SC_DMEM_LP_SLP_CFG_ADDR(base) ((base) + 0x2000 + 0xF64)
#define SOC_SC_SMEM_LP_SLP_CFG_ADDR(base) ((base) + 0x2000 + 0xF68)
#define SOC_SC_TMEM_WAY_PWRUP_ADDR(base) ((base) + 0x2000 + 0xF80)
#define SOC_SC_DMEM_WAY_PWRUP_ADDR(base) ((base) + 0x2000 + 0xF84)
#define SOC_SC_SMEM_WAY_PWRUP_ADDR(base) ((base) + 0x2000 + 0xF88)
#define SOC_SC_TMEM_WAY_INIT_ADDR(base) ((base) + 0x2000 + 0xFA0)
#define SOC_SC_DMEM_WAY_INIT_ADDR(base) ((base) + 0x2000 + 0xFA4)
#define SOC_SC_SMEM_WAY_INIT_ADDR(base) ((base) + 0x2000 + 0xFA8)
#define SOC_SC_DMEM_SPC_ADDR(base) ((base) + 0x2000 + 0xFC0)
#define SOC_SC_BEDB_SPC_ADDR(base) ((base) + 0x2000 + 0xFC4)
#define SOC_SC_VICTIM_SPC_ADDR(base) ((base) + 0x2000 + 0xFC8)
#define SOC_SC_SFRAM_SPC_ADDR(base) ((base) + 0x2000 + 0xFCC)
#define SOC_SC_TAGRAM_SPC_ADDR(base) ((base) + 0x2000 + 0xFD0)
#define SOC_SC_CGID_STATUS0_ADDR(base,cgid_idx) ((base) + 0x4000 + (cgid_idx) * 0x8)
#define SOC_SC_GID_BYP_SWITCH_STATUS_ADDR(base,pgid_byp_idx) ((base) + 0x4000 + 0x080 + (pgid_byp_idx) * 0x4)
#define SOC_SC_STATIS_CNT_IN_ADDR(base,sc_statis_num) ((base) + 0x4000 + 0x180 + (sc_statis_num) * 0x8)
#define SOC_SC_STATIS_CNT_OUT_ADDR(base,sc_statis_num) ((base) + 0x4000 + 0x184 + (sc_statis_num) * 0x8)
#define SOC_SC_SMQ_STATUS3_ADDR(base) ((base) + 0x41C0)
#define SOC_SC_SMQ_STATUS4_ADDR(base) ((base) + 0x41C4)
#define SOC_SC_TAGRAM_LP_STATUS0_ADDR(base) ((base) + 0x6000)
#define SOC_SC_TAGRAM_LP_STATUS1_ADDR(base) ((base) + 0x6004)
#define SOC_SC_SFRAM_LP_STATUS_ADDR(base) ((base) + 0x6008)
#define SOC_SC_DRAM_LP_STATUS0_ADDR(base) ((base) + 0x600C)
#define SOC_SC_DRAM_LP_STATUS1_ADDR(base) ((base) + 0x6010)
#define SOC_SC_TAGRAM_LPC_DFX0_ADDR(base) ((base) + 0x6014)
#define SOC_SC_TAGRAM_LPC_DFX1_ADDR(base) ((base) + 0x6018)
#define SOC_SC_SFRAM_LPC_DFX0_ADDR(base) ((base) + 0x601C)
#define SOC_SC_DRAM_LPC_DFX0_ADDR(base) ((base) + 0x6020)
#define SOC_SC_DRAM_LPC_DFX1_ADDR(base) ((base) + 0x6024)
#define SOC_SC_DRAM_LPC_DFX2_ADDR(base) ((base) + 0x6028)
#define SOC_SC_SMQ_STATUS_ADDR(base) ((base) + 0x6030)
#define SOC_SC_SMQ_STATUS2_ADDR(base) ((base) + 0x6034)
#define SOC_SC_GID_CFG_ADDR(base,pgid_idx) ((base) + 0xC000 + (pgid_idx) * 4)
#define SOC_SC_REPLACE_RRPV_CFG_ADDR(base) ((base) + 0xC140)
#define SOC_SC_GLB_SEC_REG_CTRL_ADDR(base) ((base) + 0x8000 + 0x2010)
#define SOC_SC_SEC_RGN_LOCK_SET_ADDR(base) ((base) + 0x8000 + 0x2014)
#define SOC_SC_SEC_RGN_LOCK_CLR_ADDR(base) ((base) + 0x8000 + 0x2018)
#define SOC_SC_SEC_RGN_LOCK_ST_ADDR(base) ((base) + 0x8000 + 0x201C)
#define SOC_SC_SEC_RGN_CTRL_ADDR(base,S) (base) + 0x8000 + 0x2100 + 16 * (S)
#define SOC_SC_SEC_RGN_ADDR_CTRL_ADDR(base,S) (base) + 0x8000 + 0x2104 + 16 * (S)
#define SOC_SC_SEC_RGN_MID_CTRL_R_ADDR(base,S) (base) + 0x8000 + 0x2108 + 16 * (S)
#define SOC_SC_SEC_RGN_MID_CTRL_W_ADDR(base,S) (base) + 0x8000 + 0x210C + 16 * (S)
#define SOC_SC_SYNCBUF_ABNML_INT_S_GLB_MASK_ADDR(base) ((base) + 0x8000 + 0x2230)
#define SOC_SC_SYNCBUF_ABNML_INT_S_CLR_ADDR(base) ((base) + 0x8000 + 0x2234)
#define SOC_SC_SYNCBUF_ABNML_INT_S_MASK_ADDR(base) ((base) + 0x8000 + 0x2238)
#define SOC_SC_SYNCBUF_ABNML_INT_S_DIS_ADDR(base) ((base) + 0x8000 + 0x223C)
#define SOC_SC_SYNCBUF_ABNML_INT_S_ORG_STATUS_ADDR(base) ((base) + 0x8000 + 0x2240)
#define SOC_SC_SYNCBUF_ABNML_INT_S_MASK_STATUS_ADDR(base) ((base) + 0x8000 + 0x2244)
#define SOC_SC_SYNCBUF_ABNML_INT_S_TYPE_ADDR(base) ((base) + 0x8000 + 0x2248)
#define SOC_SC_SYNCBUF_ABNML_INT_S_INFO_ADDR(base,dfx_info_num) ((base) + 0x8000 + 0x2250 + (dfx_info_num) * 0x4)
#define SOC_SC_GLB_REMAP_CTRL_ADDR(base) ((base) + 0x8000 + 0x2400)
#define SOC_SC_BC_ADDR_REMAP0_ADDR(base,R) (base) + 0x8000 + 0x2500 + 4 * (R)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int glb_cfgcmo_cmd_l : 32;
    } reg;
} SOC_GLB_CFGCMO_CMD_L_UNION;
#endif
#define SOC_GLB_CFGCMO_CMD_L_glb_cfgcmo_cmd_l_START (0)
#define SOC_GLB_CFGCMO_CMD_L_glb_cfgcmo_cmd_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int glb_cfgcmo_cmd_h : 32;
    } reg;
} SOC_GLB_CFGCMO_CMD_H_UNION;
#endif
#define SOC_GLB_CFGCMO_CMD_H_glb_cfgcmo_cmd_h_START (0)
#define SOC_GLB_CFGCMO_CMD_H_glb_cfgcmo_cmd_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmo_regu_evt_time : 24;
        unsigned int reserved : 7;
        unsigned int cmo_regu_evt_en : 1;
    } reg;
} SOC_SC_CFG_CMO_REGULAR_EVT_TIME_UNION;
#endif
#define SOC_SC_CFG_CMO_REGULAR_EVT_TIME_cmo_regu_evt_time_START (0)
#define SOC_SC_CFG_CMO_REGULAR_EVT_TIME_cmo_regu_evt_time_END (23)
#define SOC_SC_CFG_CMO_REGULAR_EVT_TIME_cmo_regu_evt_en_START (31)
#define SOC_SC_CFG_CMO_REGULAR_EVT_TIME_cmo_regu_evt_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_cmo_status : 32;
    } reg;
} SOC_CFG_CMO_STATUS_UNION;
#endif
#define SOC_CFG_CMO_STATUS_cfg_cmo_status_START (0)
#define SOC_CFG_CMO_STATUS_cfg_cmo_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_int_clr : 1;
        unsigned int event_int_clr_num : 10;
        unsigned int reserved : 21;
    } reg;
} SOC_CFG_CMO_CLEAR_UNION;
#endif
#define SOC_CFG_CMO_CLEAR_event_int_clr_START (0)
#define SOC_CFG_CMO_CLEAR_event_int_clr_END (0)
#define SOC_CFG_CMO_CLEAR_event_int_clr_num_START (1)
#define SOC_CFG_CMO_CLEAR_event_int_clr_num_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmo_queue_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_CFG_CMO_QUEUE_CNT_UNION;
#endif
#define SOC_SC_CFG_CMO_QUEUE_CNT_cmo_queue_cnt_START (0)
#define SOC_SC_CFG_CMO_QUEUE_CNT_cmo_queue_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int merge_slice_busy : 1;
        unsigned int merge_cfgcmo_busy : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_SC_CFG_CMO_MERGE_BUSY_CTRL_UNION;
#endif
#define SOC_SC_CFG_CMO_MERGE_BUSY_CTRL_merge_slice_busy_START (0)
#define SOC_SC_CFG_CMO_MERGE_BUSY_CTRL_merge_slice_busy_END (0)
#define SOC_SC_CFG_CMO_MERGE_BUSY_CTRL_merge_cfgcmo_busy_START (1)
#define SOC_SC_CFG_CMO_MERGE_BUSY_CTRL_merge_cfgcmo_busy_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_slice_dfx_intr_s : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_SC_CFG_CMO_DFX_INT_S_STATUS_UNION;
#endif
#define SOC_SC_CFG_CMO_DFX_INT_S_STATUS_sc_slice_dfx_intr_s_START (0)
#define SOC_SC_CFG_CMO_DFX_INT_S_STATUS_sc_slice_dfx_intr_s_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_slice_syncbuf_intr_s : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_SC_CFG_CMO_SYNCBUF_INT_S_STATUS_UNION;
#endif
#define SOC_SC_CFG_CMO_SYNCBUF_INT_S_STATUS_sc_slice_syncbuf_intr_s_START (0)
#define SOC_SC_CFG_CMO_SYNCBUF_INT_S_STATUS_sc_slice_syncbuf_intr_s_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_slice_dfx_intr_ns : 4;
        unsigned int sc_cfgcmo_int_dfx_ns : 1;
        unsigned int sc_cfgcmo_int_fc_ns : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_SC_CFG_CMO_DFX_INT_NS_STATUS_UNION;
#endif
#define SOC_SC_CFG_CMO_DFX_INT_NS_STATUS_sc_slice_dfx_intr_ns_START (0)
#define SOC_SC_CFG_CMO_DFX_INT_NS_STATUS_sc_slice_dfx_intr_ns_END (3)
#define SOC_SC_CFG_CMO_DFX_INT_NS_STATUS_sc_cfgcmo_int_dfx_ns_START (4)
#define SOC_SC_CFG_CMO_DFX_INT_NS_STATUS_sc_cfgcmo_int_dfx_ns_END (4)
#define SOC_SC_CFG_CMO_DFX_INT_NS_STATUS_sc_cfgcmo_int_fc_ns_START (5)
#define SOC_SC_CFG_CMO_DFX_INT_NS_STATUS_sc_cfgcmo_int_fc_ns_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_slice_nopending : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_SC_CFG_CMO_NOPENDING_STATUS_UNION;
#endif
#define SOC_SC_CFG_CMO_NOPENDING_STATUS_sc_slice_nopending_START (0)
#define SOC_SC_CFG_CMO_NOPENDING_STATUS_sc_slice_nopending_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_slice_busy : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_SC_CFG_CMO_BUSY_STATUS_UNION;
#endif
#define SOC_SC_CFG_CMO_BUSY_STATUS_sc_slice_busy_START (0)
#define SOC_SC_CFG_CMO_BUSY_STATUS_sc_slice_busy_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_slice_perf_idle : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_SC_CFG_CMO_PERF_IDLE_STATUS_UNION;
#endif
#define SOC_SC_CFG_CMO_PERF_IDLE_STATUS_sc_slice_perf_idle_START (0)
#define SOC_SC_CFG_CMO_PERF_IDLE_STATUS_sc_slice_perf_idle_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_ns_int_glb_mask : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SC_CFG_ABNML_NS_INT_CTRL0_UNION;
#endif
#define SOC_SC_CFG_ABNML_NS_INT_CTRL0_dfx_ns_int_glb_mask_START (0)
#define SOC_SC_CFG_ABNML_NS_INT_CTRL0_dfx_ns_int_glb_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_ns_int_mask : 32;
    } reg;
} SOC_SC_CFG_ABNML_NS_INT_CTRL1_UNION;
#endif
#define SOC_SC_CFG_ABNML_NS_INT_CTRL1_dfx_ns_int_mask_START (0)
#define SOC_SC_CFG_ABNML_NS_INT_CTRL1_dfx_ns_int_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_ns_int_dis : 32;
    } reg;
} SOC_SC_CFG_ABNML_NS_INT_CTRL2_UNION;
#endif
#define SOC_SC_CFG_ABNML_NS_INT_CTRL2_dfx_ns_int_dis_START (0)
#define SOC_SC_CFG_ABNML_NS_INT_CTRL2_dfx_ns_int_dis_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_ns_int_mask_status : 32;
    } reg;
} SOC_SC_CFG_ABNML_NS_INT_STATUS0_UNION;
#endif
#define SOC_SC_CFG_ABNML_NS_INT_STATUS0_dfx_ns_int_mask_status_START (0)
#define SOC_SC_CFG_ABNML_NS_INT_STATUS0_dfx_ns_int_mask_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_ns_int_org_status : 32;
    } reg;
} SOC_SC_CFG_ABNML_NS_INT_STATUS1_UNION;
#endif
#define SOC_SC_CFG_ABNML_NS_INT_STATUS1_dfx_ns_int_org_status_START (0)
#define SOC_SC_CFG_ABNML_NS_INT_STATUS1_dfx_ns_int_org_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_ns_int_type : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_SC_CFG_ABNML_NS_INT_STATUS2_UNION;
#endif
#define SOC_SC_CFG_ABNML_NS_INT_STATUS2_dfx_ns_int_type_START (0)
#define SOC_SC_CFG_ABNML_NS_INT_STATUS2_dfx_ns_int_type_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_ns_int_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SC_CFG_ABNML_NS_INT_CLR_UNION;
#endif
#define SOC_SC_CFG_ABNML_NS_INT_CLR_dfx_ns_int_clr_START (0)
#define SOC_SC_CFG_ABNML_NS_INT_CLR_dfx_ns_int_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_ns_int_info0 : 32;
    } reg;
} SOC_SC_CFG_ABNML_NS_INT_INFO0_UNION;
#endif
#define SOC_SC_CFG_ABNML_NS_INT_INFO0_dfx_ns_int_info0_START (0)
#define SOC_SC_CFG_ABNML_NS_INT_INFO0_dfx_ns_int_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_ns_int_info1 : 32;
    } reg;
} SOC_SC_CFG_ABNML_NS_INT_INFO1_UNION;
#endif
#define SOC_SC_CFG_ABNML_NS_INT_INFO1_dfx_ns_int_info1_START (0)
#define SOC_SC_CFG_ABNML_NS_INT_INFO1_dfx_ns_int_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int glb_tz_secure : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_CFG_GLB_SEC_CTRL_UNION;
#endif
#define SOC_SC_CFG_GLB_SEC_CTRL_glb_tz_secure_START (0)
#define SOC_SC_CFG_GLB_SEC_CTRL_glb_tz_secure_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slice_tz_secure : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_CFG_SLICE_SEC_CTRL_UNION;
#endif
#define SOC_SC_CFG_SLICE_SEC_CTRL_slice_tz_secure_START (0)
#define SOC_SC_CFG_SLICE_SEC_CTRL_slice_tz_secure_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int defslv_ok_en : 1;
        unsigned int secerr_ok_en : 1;
        unsigned int secerr_rdata_sel : 1;
        unsigned int reserved_0 : 5;
        unsigned int secerr_rdata : 8;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_SC_CFG_DEFSLV_RESP_CTRL_UNION;
#endif
#define SOC_SC_CFG_DEFSLV_RESP_CTRL_defslv_ok_en_START (0)
#define SOC_SC_CFG_DEFSLV_RESP_CTRL_defslv_ok_en_END (0)
#define SOC_SC_CFG_DEFSLV_RESP_CTRL_secerr_ok_en_START (1)
#define SOC_SC_CFG_DEFSLV_RESP_CTRL_secerr_ok_en_END (1)
#define SOC_SC_CFG_DEFSLV_RESP_CTRL_secerr_rdata_sel_START (2)
#define SOC_SC_CFG_DEFSLV_RESP_CTRL_secerr_rdata_sel_END (2)
#define SOC_SC_CFG_DEFSLV_RESP_CTRL_secerr_rdata_START (8)
#define SOC_SC_CFG_DEFSLV_RESP_CTRL_secerr_rdata_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apc_chain_wack_en : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_SC_CHAIN_WACK_UNION;
#endif
#define SOC_SC_CHAIN_WACK_apc_chain_wack_en_START (0)
#define SOC_SC_CHAIN_WACK_apc_chain_wack_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apc_prdata_prot : 8;
        unsigned int apc_prdata_tout : 8;
        unsigned int apc_pslverr_prot : 1;
        unsigned int apc_pslverr_tout : 1;
        unsigned int reserved_0 : 2;
        unsigned int apc_tout_prd : 4;
        unsigned int wreq_nelyrsp_dly : 4;
        unsigned int wreq_nelyrsp : 1;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_SC_APCR_CTRL_UNION;
#endif
#define SOC_SC_APCR_CTRL_apc_prdata_prot_START (0)
#define SOC_SC_APCR_CTRL_apc_prdata_prot_END (7)
#define SOC_SC_APCR_CTRL_apc_prdata_tout_START (8)
#define SOC_SC_APCR_CTRL_apc_prdata_tout_END (15)
#define SOC_SC_APCR_CTRL_apc_pslverr_prot_START (16)
#define SOC_SC_APCR_CTRL_apc_pslverr_prot_END (16)
#define SOC_SC_APCR_CTRL_apc_pslverr_tout_START (17)
#define SOC_SC_APCR_CTRL_apc_pslverr_tout_END (17)
#define SOC_SC_APCR_CTRL_apc_tout_prd_START (20)
#define SOC_SC_APCR_CTRL_apc_tout_prd_END (23)
#define SOC_SC_APCR_CTRL_wreq_nelyrsp_dly_START (24)
#define SOC_SC_APCR_CTRL_wreq_nelyrsp_dly_END (27)
#define SOC_SC_APCR_CTRL_wreq_nelyrsp_START (28)
#define SOC_SC_APCR_CTRL_wreq_nelyrsp_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int allow_mid1 : 8;
        unsigned int allow_mid2 : 8;
        unsigned int allow_mid1_mask : 8;
        unsigned int allow_mid2_mask : 8;
    } reg;
} SOC_SC_CFG_ALLOW_MID_S_UNION;
#endif
#define SOC_SC_CFG_ALLOW_MID_S_allow_mid1_START (0)
#define SOC_SC_CFG_ALLOW_MID_S_allow_mid1_END (7)
#define SOC_SC_CFG_ALLOW_MID_S_allow_mid2_START (8)
#define SOC_SC_CFG_ALLOW_MID_S_allow_mid2_END (15)
#define SOC_SC_CFG_ALLOW_MID_S_allow_mid1_mask_START (16)
#define SOC_SC_CFG_ALLOW_MID_S_allow_mid1_mask_END (23)
#define SOC_SC_CFG_ALLOW_MID_S_allow_mid2_mask_START (24)
#define SOC_SC_CFG_ALLOW_MID_S_allow_mid2_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmo_en_addr_hole_0 : 1;
        unsigned int cmo_en_addr_hole_1 : 1;
        unsigned int cmo_en_addr_hole_2 : 1;
        unsigned int cmo_en_addr_hole_3 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_SC_CFG_CMO_EN_ADDR_HOLE_S_UNION;
#endif
#define SOC_SC_CFG_CMO_EN_ADDR_HOLE_S_cmo_en_addr_hole_0_START (0)
#define SOC_SC_CFG_CMO_EN_ADDR_HOLE_S_cmo_en_addr_hole_0_END (0)
#define SOC_SC_CFG_CMO_EN_ADDR_HOLE_S_cmo_en_addr_hole_1_START (1)
#define SOC_SC_CFG_CMO_EN_ADDR_HOLE_S_cmo_en_addr_hole_1_END (1)
#define SOC_SC_CFG_CMO_EN_ADDR_HOLE_S_cmo_en_addr_hole_2_START (2)
#define SOC_SC_CFG_CMO_EN_ADDR_HOLE_S_cmo_en_addr_hole_2_END (2)
#define SOC_SC_CFG_CMO_EN_ADDR_HOLE_S_cmo_en_addr_hole_3_START (3)
#define SOC_SC_CFG_CMO_EN_ADDR_HOLE_S_cmo_en_addr_hole_3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmo_str_addr_hole_0 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SC_CFG_CMO_STR_ADDR_HOLE_0_S_UNION;
#endif
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_0_S_cmo_str_addr_hole_0_START (0)
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_0_S_cmo_str_addr_hole_0_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmo_end_addr_hole_0 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SC_CFG_CMO_END_ADDR_HOLE_0_S_UNION;
#endif
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_0_S_cmo_end_addr_hole_0_START (0)
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_0_S_cmo_end_addr_hole_0_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmo_str_addr_hole_1 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SC_CFG_CMO_STR_ADDR_HOLE_1_S_UNION;
#endif
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_1_S_cmo_str_addr_hole_1_START (0)
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_1_S_cmo_str_addr_hole_1_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmo_end_addr_hole_1 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SC_CFG_CMO_END_ADDR_HOLE_1_S_UNION;
#endif
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_1_S_cmo_end_addr_hole_1_START (0)
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_1_S_cmo_end_addr_hole_1_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmo_str_addr_hole_2 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SC_CFG_CMO_STR_ADDR_HOLE_2_S_UNION;
#endif
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_2_S_cmo_str_addr_hole_2_START (0)
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_2_S_cmo_str_addr_hole_2_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmo_end_addr_hole_2 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SC_CFG_CMO_END_ADDR_HOLE_2_S_UNION;
#endif
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_2_S_cmo_end_addr_hole_2_START (0)
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_2_S_cmo_end_addr_hole_2_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmo_str_addr_hole_3 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SC_CFG_CMO_STR_ADDR_HOLE_3_S_UNION;
#endif
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_3_S_cmo_str_addr_hole_3_START (0)
#define SOC_SC_CFG_CMO_STR_ADDR_HOLE_3_S_cmo_str_addr_hole_3_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmo_end_addr_hole_3 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SC_CFG_CMO_END_ADDR_HOLE_3_S_UNION;
#endif
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_3_S_cmo_end_addr_hole_3_START (0)
#define SOC_SC_CFG_CMO_END_ADDR_HOLE_3_S_cmo_end_addr_hole_3_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmo_tpmem_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_CFG_CMO_TPMEM_CTRL_S_UNION;
#endif
#define SOC_SC_CFG_CMO_TPMEM_CTRL_S_cmo_tpmem_ctrl_START (0)
#define SOC_SC_CFG_CMO_TPMEM_CTRL_S_cmo_tpmem_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmo_overflow_mode : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SC_CFG_CMO_SET_S_UNION;
#endif
#define SOC_SC_CFG_CMO_SET_S_cmo_overflow_mode_START (0)
#define SOC_SC_CFG_CMO_SET_S_cmo_overflow_mode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int brc_rdata_sel : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_SC_CFG_BRC_RDATA_SEL_UNION;
#endif
#define SOC_SC_CFG_BRC_RDATA_SEL_brc_rdata_sel_START (0)
#define SOC_SC_CFG_BRC_RDATA_SEL_brc_rdata_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dist_ram_ckg_byp : 1;
        unsigned int cmo_buf0_ckg_byp : 1;
        unsigned int cmo_buf1_ckg_byp : 1;
        unsigned int cmo_matrix_ckg_byp : 1;
        unsigned int cmo_qsp2apc_ckg_byp : 1;
        unsigned int cmo_dist_ckg_byp : 1;
        unsigned int cfg_ckg_byp : 1;
        unsigned int cmo_top_cfg_ckg_byp : 1;
        unsigned int reserved : 23;
        unsigned int cfg_cmo_ext_en : 1;
    } reg;
} SOC_SC_CFG_CMOCKG_CTRL_UNION;
#endif
#define SOC_SC_CFG_CMOCKG_CTRL_cfg_dist_ram_ckg_byp_START (0)
#define SOC_SC_CFG_CMOCKG_CTRL_cfg_dist_ram_ckg_byp_END (0)
#define SOC_SC_CFG_CMOCKG_CTRL_cmo_buf0_ckg_byp_START (1)
#define SOC_SC_CFG_CMOCKG_CTRL_cmo_buf0_ckg_byp_END (1)
#define SOC_SC_CFG_CMOCKG_CTRL_cmo_buf1_ckg_byp_START (2)
#define SOC_SC_CFG_CMOCKG_CTRL_cmo_buf1_ckg_byp_END (2)
#define SOC_SC_CFG_CMOCKG_CTRL_cmo_matrix_ckg_byp_START (3)
#define SOC_SC_CFG_CMOCKG_CTRL_cmo_matrix_ckg_byp_END (3)
#define SOC_SC_CFG_CMOCKG_CTRL_cmo_qsp2apc_ckg_byp_START (4)
#define SOC_SC_CFG_CMOCKG_CTRL_cmo_qsp2apc_ckg_byp_END (4)
#define SOC_SC_CFG_CMOCKG_CTRL_cmo_dist_ckg_byp_START (5)
#define SOC_SC_CFG_CMOCKG_CTRL_cmo_dist_ckg_byp_END (5)
#define SOC_SC_CFG_CMOCKG_CTRL_cfg_ckg_byp_START (6)
#define SOC_SC_CFG_CMOCKG_CTRL_cfg_ckg_byp_END (6)
#define SOC_SC_CFG_CMOCKG_CTRL_cmo_top_cfg_ckg_byp_START (7)
#define SOC_SC_CFG_CMOCKG_CTRL_cmo_top_cfg_ckg_byp_END (7)
#define SOC_SC_CFG_CMOCKG_CTRL_cfg_cmo_ext_en_START (31)
#define SOC_SC_CFG_CMOCKG_CTRL_cfg_cmo_ext_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int statis_mid : 8;
        unsigned int statis_mid_mask_n : 8;
        unsigned int gid_statis_en : 16;
    } reg;
} SOC_SC_STATIS_SLICE_CTRL0_UNION;
#endif
#define SOC_SC_STATIS_SLICE_CTRL0_statis_mid_START (0)
#define SOC_SC_STATIS_SLICE_CTRL0_statis_mid_END (7)
#define SOC_SC_STATIS_SLICE_CTRL0_statis_mid_mask_n_START (8)
#define SOC_SC_STATIS_SLICE_CTRL0_statis_mid_mask_n_END (15)
#define SOC_SC_STATIS_SLICE_CTRL0_gid_statis_en_START (16)
#define SOC_SC_STATIS_SLICE_CTRL0_gid_statis_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int type_statis_en : 11;
        unsigned int statis_mode : 1;
        unsigned int bypass_statis_en : 3;
        unsigned int slice_statis_en : 1;
        unsigned int statis_pgid : 6;
        unsigned int reserved_0 : 2;
        unsigned int statis_pgid_mask_n : 6;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_SC_STATIS_SLICE_CTRL1_UNION;
#endif
#define SOC_SC_STATIS_SLICE_CTRL1_type_statis_en_START (0)
#define SOC_SC_STATIS_SLICE_CTRL1_type_statis_en_END (10)
#define SOC_SC_STATIS_SLICE_CTRL1_statis_mode_START (11)
#define SOC_SC_STATIS_SLICE_CTRL1_statis_mode_END (11)
#define SOC_SC_STATIS_SLICE_CTRL1_bypass_statis_en_START (12)
#define SOC_SC_STATIS_SLICE_CTRL1_bypass_statis_en_END (14)
#define SOC_SC_STATIS_SLICE_CTRL1_slice_statis_en_START (15)
#define SOC_SC_STATIS_SLICE_CTRL1_slice_statis_en_END (15)
#define SOC_SC_STATIS_SLICE_CTRL1_statis_pgid_START (16)
#define SOC_SC_STATIS_SLICE_CTRL1_statis_pgid_END (21)
#define SOC_SC_STATIS_SLICE_CTRL1_statis_pgid_mask_n_START (24)
#define SOC_SC_STATIS_SLICE_CTRL1_statis_pgid_mask_n_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int glb_statis_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SC_STATIS_GLB_EN_UNION;
#endif
#define SOC_SC_STATIS_GLB_EN_glb_statis_en_START (0)
#define SOC_SC_STATIS_GLB_EN_glb_statis_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmoq_quota_cnt : 16;
        unsigned int cmoq_quota_cnt_vld : 1;
        unsigned int cmoq_quota_cnt_clr : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_SC_CMOQ_QUOTA_CNT_UNION;
#endif
#define SOC_SC_CMOQ_QUOTA_CNT_cmoq_quota_cnt_START (0)
#define SOC_SC_CMOQ_QUOTA_CNT_cmoq_quota_cnt_END (15)
#define SOC_SC_CMOQ_QUOTA_CNT_cmoq_quota_cnt_vld_START (16)
#define SOC_SC_CMOQ_QUOTA_CNT_cmoq_quota_cnt_vld_END (16)
#define SOC_SC_CMOQ_QUOTA_CNT_cmoq_quota_cnt_clr_START (17)
#define SOC_SC_CMOQ_QUOTA_CNT_cmoq_quota_cnt_clr_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mpam_way_enable : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_MPAM_WAY_ALLC_UNION;
#endif
#define SOC_SC_MPAM_WAY_ALLC_mpam_way_enable_START (0)
#define SOC_SC_MPAM_WAY_ALLC_mpam_way_enable_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ptid_revisit_age : 3;
        unsigned int reserved_0 : 1;
        unsigned int ptid_initial_age : 3;
        unsigned int reserved_1 : 1;
        unsigned int ptid_age_en : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_SC_REPLACE_MPAM_PTID_CFG_UNION;
#endif
#define SOC_SC_REPLACE_MPAM_PTID_CFG_ptid_revisit_age_START (0)
#define SOC_SC_REPLACE_MPAM_PTID_CFG_ptid_revisit_age_END (2)
#define SOC_SC_REPLACE_MPAM_PTID_CFG_ptid_initial_age_START (4)
#define SOC_SC_REPLACE_MPAM_PTID_CFG_ptid_initial_age_END (6)
#define SOC_SC_REPLACE_MPAM_PTID_CFG_ptid_age_en_START (8)
#define SOC_SC_REPLACE_MPAM_PTID_CFG_ptid_age_en_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mpam_writeevict_en : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_MPAM_CTRL0_UNION;
#endif
#define SOC_SC_MPAM_CTRL0_mpam_writeevict_en_START (0)
#define SOC_SC_MPAM_CTRL0_mpam_writeevict_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dummy_reg_0 : 32;
    } reg;
} SOC_SC_DUMMY_REG0_UNION;
#endif
#define SOC_SC_DUMMY_REG0_dummy_reg_0_START (0)
#define SOC_SC_DUMMY_REG0_dummy_reg_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_glb_mask_abnml_ns : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SC_ABNML_INT_NS_GLB_MASK_UNION;
#endif
#define SOC_SC_ABNML_INT_NS_GLB_MASK_int_glb_mask_abnml_ns_START (0)
#define SOC_SC_ABNML_INT_NS_GLB_MASK_int_glb_mask_abnml_ns_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_clr_abnml_ns : 1;
        unsigned int sw_trig_int_abnml_ns : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_SC_ABNML_INT_NS_CLR_UNION;
#endif
#define SOC_SC_ABNML_INT_NS_CLR_int_clr_abnml_ns_START (0)
#define SOC_SC_ABNML_INT_NS_CLR_int_clr_abnml_ns_END (0)
#define SOC_SC_ABNML_INT_NS_CLR_sw_trig_int_abnml_ns_START (1)
#define SOC_SC_ABNML_INT_NS_CLR_sw_trig_int_abnml_ns_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_mask_abnml_ns : 32;
    } reg;
} SOC_SC_ABNML_INT_NS_MASK_UNION;
#endif
#define SOC_SC_ABNML_INT_NS_MASK_int_mask_abnml_ns_START (0)
#define SOC_SC_ABNML_INT_NS_MASK_int_mask_abnml_ns_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_dis_abnml_ns : 32;
    } reg;
} SOC_SC_ABNML_INT_NS_DIS_UNION;
#endif
#define SOC_SC_ABNML_INT_NS_DIS_int_dis_abnml_ns_START (0)
#define SOC_SC_ABNML_INT_NS_DIS_int_dis_abnml_ns_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_org_status_abnml_ns : 32;
    } reg;
} SOC_SC_ABNML_INT_NS_ORG_STATUS_UNION;
#endif
#define SOC_SC_ABNML_INT_NS_ORG_STATUS_int_org_status_abnml_ns_START (0)
#define SOC_SC_ABNML_INT_NS_ORG_STATUS_int_org_status_abnml_ns_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_mask_status_abnml_ns : 32;
    } reg;
} SOC_SC_ABNML_INT_NS_MASK_STATUS_UNION;
#endif
#define SOC_SC_ABNML_INT_NS_MASK_STATUS_int_mask_status_abnml_ns_START (0)
#define SOC_SC_ABNML_INT_NS_MASK_STATUS_int_mask_status_abnml_ns_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_type_abnml_ns : 7;
        unsigned int reserved_0 : 1;
        unsigned int sw_trig_int_type_abnml_ns : 7;
        unsigned int reserved_1 : 17;
    } reg;
} SOC_SC_ABNML_INT_NS_TYPE_UNION;
#endif
#define SOC_SC_ABNML_INT_NS_TYPE_int_type_abnml_ns_START (0)
#define SOC_SC_ABNML_INT_NS_TYPE_int_type_abnml_ns_END (6)
#define SOC_SC_ABNML_INT_NS_TYPE_sw_trig_int_type_abnml_ns_START (8)
#define SOC_SC_ABNML_INT_NS_TYPE_sw_trig_int_type_abnml_ns_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_info_abnml_ns : 32;
    } reg;
} SOC_SC_ABNML_INT_NS_INFO_UNION;
#endif
#define SOC_SC_ABNML_INT_NS_INFO_int_info_abnml_ns_START (0)
#define SOC_SC_ABNML_INT_NS_INFO_int_info_abnml_ns_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_glb_mask_dlock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SC_DLOCK_INT_GLB_MASK_UNION;
#endif
#define SOC_SC_DLOCK_INT_GLB_MASK_int_glb_mask_dlock_START (0)
#define SOC_SC_DLOCK_INT_GLB_MASK_int_glb_mask_dlock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_clr_dlock : 1;
        unsigned int sw_trig_int_dlock : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_SC_DLOCK_INT_CLR_UNION;
#endif
#define SOC_SC_DLOCK_INT_CLR_int_clr_dlock_START (0)
#define SOC_SC_DLOCK_INT_CLR_int_clr_dlock_END (0)
#define SOC_SC_DLOCK_INT_CLR_sw_trig_int_dlock_START (1)
#define SOC_SC_DLOCK_INT_CLR_sw_trig_int_dlock_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_mask_dlock : 32;
    } reg;
} SOC_SC_DLOCK_INT_MASK_UNION;
#endif
#define SOC_SC_DLOCK_INT_MASK_int_mask_dlock_START (0)
#define SOC_SC_DLOCK_INT_MASK_int_mask_dlock_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_dis_dlock : 32;
    } reg;
} SOC_SC_DLOCK_INT_DIS_UNION;
#endif
#define SOC_SC_DLOCK_INT_DIS_int_dis_dlock_START (0)
#define SOC_SC_DLOCK_INT_DIS_int_dis_dlock_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_org_status_dlock : 32;
    } reg;
} SOC_SC_DLOCK_INT_ORG_STATUS_UNION;
#endif
#define SOC_SC_DLOCK_INT_ORG_STATUS_int_org_status_dlock_START (0)
#define SOC_SC_DLOCK_INT_ORG_STATUS_int_org_status_dlock_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_mask_status_dlock : 32;
    } reg;
} SOC_SC_DLOCK_INT_MASK_STATUS_UNION;
#endif
#define SOC_SC_DLOCK_INT_MASK_STATUS_int_mask_status_dlock_START (0)
#define SOC_SC_DLOCK_INT_MASK_STATUS_int_mask_status_dlock_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_type_dlock : 6;
        unsigned int reserved_0 : 2;
        unsigned int sw_trig_int_type_dlock : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_SC_DLOCK_INT_TYPE_UNION;
#endif
#define SOC_SC_DLOCK_INT_TYPE_int_type_dlock_START (0)
#define SOC_SC_DLOCK_INT_TYPE_int_type_dlock_END (5)
#define SOC_SC_DLOCK_INT_TYPE_sw_trig_int_type_dlock_START (8)
#define SOC_SC_DLOCK_INT_TYPE_sw_trig_int_type_dlock_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_info_dlock : 32;
    } reg;
} SOC_SC_DLOCK_INT_INFO_UNION;
#endif
#define SOC_SC_DLOCK_INT_INFO_int_info_dlock_START (0)
#define SOC_SC_DLOCK_INT_INFO_int_info_dlock_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tag_ecc_err_cnt_clr : 1;
        unsigned int sf_ecc_err_cnt_clr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_SC_TAG_SF_ECC_ERR_CNT_CLR_UNION;
#endif
#define SOC_SC_TAG_SF_ECC_ERR_CNT_CLR_tag_ecc_err_cnt_clr_START (0)
#define SOC_SC_TAG_SF_ECC_ERR_CNT_CLR_tag_ecc_err_cnt_clr_END (0)
#define SOC_SC_TAG_SF_ECC_ERR_CNT_CLR_sf_ecc_err_cnt_clr_START (1)
#define SOC_SC_TAG_SF_ECC_ERR_CNT_CLR_sf_ecc_err_cnt_clr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tag_ecc_err_1bit_cnt : 3;
        unsigned int reserved_0 : 5;
        unsigned int tag_ecc_err_2bit_cnt : 3;
        unsigned int reserved_1 : 5;
        unsigned int sf_ecc_err_1bit_cnt : 3;
        unsigned int reserved_2 : 5;
        unsigned int sf_ecc_err_2bit_cnt : 3;
        unsigned int reserved_3 : 5;
    } reg;
} SOC_SC_TAG_SF_ECC_ERR_CNT_UNION;
#endif
#define SOC_SC_TAG_SF_ECC_ERR_CNT_tag_ecc_err_1bit_cnt_START (0)
#define SOC_SC_TAG_SF_ECC_ERR_CNT_tag_ecc_err_1bit_cnt_END (2)
#define SOC_SC_TAG_SF_ECC_ERR_CNT_tag_ecc_err_2bit_cnt_START (8)
#define SOC_SC_TAG_SF_ECC_ERR_CNT_tag_ecc_err_2bit_cnt_END (10)
#define SOC_SC_TAG_SF_ECC_ERR_CNT_sf_ecc_err_1bit_cnt_START (16)
#define SOC_SC_TAG_SF_ECC_ERR_CNT_sf_ecc_err_1bit_cnt_END (18)
#define SOC_SC_TAG_SF_ECC_ERR_CNT_sf_ecc_err_2bit_cnt_START (24)
#define SOC_SC_TAG_SF_ECC_ERR_CNT_sf_ecc_err_2bit_cnt_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmem_ecc_err_1bit_cnt : 12;
        unsigned int reserved_0 : 4;
        unsigned int dmem_ecc_err_2bit_cnt : 12;
        unsigned int reserved_1 : 3;
        unsigned int dmem_ecc_record_en : 1;
    } reg;
} SOC_SC_DMEM_ECC_ERR_CNT_UNION;
#endif
#define SOC_SC_DMEM_ECC_ERR_CNT_dmem_ecc_err_1bit_cnt_START (0)
#define SOC_SC_DMEM_ECC_ERR_CNT_dmem_ecc_err_1bit_cnt_END (11)
#define SOC_SC_DMEM_ECC_ERR_CNT_dmem_ecc_err_2bit_cnt_START (16)
#define SOC_SC_DMEM_ECC_ERR_CNT_dmem_ecc_err_2bit_cnt_END (27)
#define SOC_SC_DMEM_ECC_ERR_CNT_dmem_ecc_record_en_START (31)
#define SOC_SC_DMEM_ECC_ERR_CNT_dmem_ecc_record_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmem_ecc_err_1bit_addr : 15;
        unsigned int reserved_0 : 1;
        unsigned int dmem_ecc_err_2bit_addr : 15;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_SC_DMEM_ECC_ERR_ADDR_UNION;
#endif
#define SOC_SC_DMEM_ECC_ERR_ADDR_dmem_ecc_err_1bit_addr_START (0)
#define SOC_SC_DMEM_ECC_ERR_ADDR_dmem_ecc_err_1bit_addr_END (14)
#define SOC_SC_DMEM_ECC_ERR_ADDR_dmem_ecc_err_2bit_addr_START (16)
#define SOC_SC_DMEM_ECC_ERR_ADDR_dmem_ecc_err_2bit_addr_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cgid_way_enable : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_CGID_WAY_ALLC_UNION;
#endif
#define SOC_SC_CGID_WAY_ALLC_cgid_way_enable_START (0)
#define SOC_SC_CGID_WAY_ALLC_cgid_way_enable_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cgid_way_search : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_CGID_WAY_SEARCH_UNION;
#endif
#define SOC_SC_CGID_WAY_SEARCH_cgid_way_search_START (0)
#define SOC_SC_CGID_WAY_SEARCH_cgid_way_search_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cgid_self_replaceable : 1;
        unsigned int cgid_bypass_en : 1;
        unsigned int cgid_tag_pgid_chg_en : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_SC_CGID_CFG_UNION;
#endif
#define SOC_SC_CGID_CFG_cgid_self_replaceable_START (0)
#define SOC_SC_CGID_CFG_cgid_self_replaceable_END (0)
#define SOC_SC_CGID_CFG_cgid_bypass_en_START (1)
#define SOC_SC_CGID_CFG_cgid_bypass_en_END (1)
#define SOC_SC_CGID_CFG_cgid_tag_pgid_chg_en_START (2)
#define SOC_SC_CGID_CFG_cgid_tag_pgid_chg_en_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cgid_quota : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_CGID_QUOTA_UNION;
#endif
#define SOC_SC_CGID_QUOTA_cgid_quota_START (0)
#define SOC_SC_CGID_QUOTA_cgid_quota_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int pgid_paf_en : 1;
        unsigned int pgid_prefetch_en : 1;
        unsigned int pgid_autoclean_en : 1;
        unsigned int pgid_schint_en : 1;
        unsigned int pgid_keep_cleansh : 1;
        unsigned int pgid_vacmo_en : 1;
        unsigned int pgid_stash_en : 1;
        unsigned int pgid_triger_en : 1;
        unsigned int pgid_mode : 1;
        unsigned int pgid_sot_ignore : 1;
        unsigned int pgid_passdirty_en : 1;
        unsigned int pgid_cgid_idx : 4;
        unsigned int reserved_1 : 4;
        unsigned int pgid_writeevict_en : 1;
        unsigned int reserved_2 : 10;
        unsigned int hit_age_byp : 1;
    } reg;
} SOC_SC_GID_SEC_ATTR_S_UNION;
#endif
#define SOC_SC_GID_SEC_ATTR_S_pgid_paf_en_START (1)
#define SOC_SC_GID_SEC_ATTR_S_pgid_paf_en_END (1)
#define SOC_SC_GID_SEC_ATTR_S_pgid_prefetch_en_START (2)
#define SOC_SC_GID_SEC_ATTR_S_pgid_prefetch_en_END (2)
#define SOC_SC_GID_SEC_ATTR_S_pgid_autoclean_en_START (3)
#define SOC_SC_GID_SEC_ATTR_S_pgid_autoclean_en_END (3)
#define SOC_SC_GID_SEC_ATTR_S_pgid_schint_en_START (4)
#define SOC_SC_GID_SEC_ATTR_S_pgid_schint_en_END (4)
#define SOC_SC_GID_SEC_ATTR_S_pgid_keep_cleansh_START (5)
#define SOC_SC_GID_SEC_ATTR_S_pgid_keep_cleansh_END (5)
#define SOC_SC_GID_SEC_ATTR_S_pgid_vacmo_en_START (6)
#define SOC_SC_GID_SEC_ATTR_S_pgid_vacmo_en_END (6)
#define SOC_SC_GID_SEC_ATTR_S_pgid_stash_en_START (7)
#define SOC_SC_GID_SEC_ATTR_S_pgid_stash_en_END (7)
#define SOC_SC_GID_SEC_ATTR_S_pgid_triger_en_START (8)
#define SOC_SC_GID_SEC_ATTR_S_pgid_triger_en_END (8)
#define SOC_SC_GID_SEC_ATTR_S_pgid_mode_START (9)
#define SOC_SC_GID_SEC_ATTR_S_pgid_mode_END (9)
#define SOC_SC_GID_SEC_ATTR_S_pgid_sot_ignore_START (10)
#define SOC_SC_GID_SEC_ATTR_S_pgid_sot_ignore_END (10)
#define SOC_SC_GID_SEC_ATTR_S_pgid_passdirty_en_START (11)
#define SOC_SC_GID_SEC_ATTR_S_pgid_passdirty_en_END (11)
#define SOC_SC_GID_SEC_ATTR_S_pgid_cgid_idx_START (12)
#define SOC_SC_GID_SEC_ATTR_S_pgid_cgid_idx_END (15)
#define SOC_SC_GID_SEC_ATTR_S_pgid_writeevict_en_START (20)
#define SOC_SC_GID_SEC_ATTR_S_pgid_writeevict_en_END (20)
#define SOC_SC_GID_SEC_ATTR_S_hit_age_byp_START (31)
#define SOC_SC_GID_SEC_ATTR_S_hit_age_byp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int chi_intf_qos_pri_map : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_QOS_MAP_UNION;
#endif
#define SOC_SC_QOS_MAP_chi_intf_qos_pri_map_START (0)
#define SOC_SC_QOS_MAP_chi_intf_qos_pri_map_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mst2fecq_rdata_qos : 2;
        unsigned int bedb2fecq_rdata_qos : 2;
        unsigned int bypass_fecq_sc_pri : 2;
        unsigned int biq2tpipe_arb_pri : 2;
        unsigned int becq2tpipe_arb_pri : 2;
        unsigned int reserved_0 : 6;
        unsigned int victim_mpam : 4;
        unsigned int victim_qtpe_pri : 2;
        unsigned int lowest_realtime_pri : 2;
        unsigned int victim_qos : 3;
        unsigned int reserved_1 : 1;
        unsigned int bedb_arb_qos_dis : 1;
        unsigned int reserved_2 : 3;
    } reg;
} SOC_SC_PRI_QOS_CTRL0_UNION;
#endif
#define SOC_SC_PRI_QOS_CTRL0_mst2fecq_rdata_qos_START (0)
#define SOC_SC_PRI_QOS_CTRL0_mst2fecq_rdata_qos_END (1)
#define SOC_SC_PRI_QOS_CTRL0_bedb2fecq_rdata_qos_START (2)
#define SOC_SC_PRI_QOS_CTRL0_bedb2fecq_rdata_qos_END (3)
#define SOC_SC_PRI_QOS_CTRL0_bypass_fecq_sc_pri_START (4)
#define SOC_SC_PRI_QOS_CTRL0_bypass_fecq_sc_pri_END (5)
#define SOC_SC_PRI_QOS_CTRL0_biq2tpipe_arb_pri_START (6)
#define SOC_SC_PRI_QOS_CTRL0_biq2tpipe_arb_pri_END (7)
#define SOC_SC_PRI_QOS_CTRL0_becq2tpipe_arb_pri_START (8)
#define SOC_SC_PRI_QOS_CTRL0_becq2tpipe_arb_pri_END (9)
#define SOC_SC_PRI_QOS_CTRL0_victim_mpam_START (16)
#define SOC_SC_PRI_QOS_CTRL0_victim_mpam_END (19)
#define SOC_SC_PRI_QOS_CTRL0_victim_qtpe_pri_START (20)
#define SOC_SC_PRI_QOS_CTRL0_victim_qtpe_pri_END (21)
#define SOC_SC_PRI_QOS_CTRL0_lowest_realtime_pri_START (22)
#define SOC_SC_PRI_QOS_CTRL0_lowest_realtime_pri_END (23)
#define SOC_SC_PRI_QOS_CTRL0_victim_qos_START (24)
#define SOC_SC_PRI_QOS_CTRL0_victim_qos_END (26)
#define SOC_SC_PRI_QOS_CTRL0_bedb_arb_qos_dis_START (28)
#define SOC_SC_PRI_QOS_CTRL0_bedb_arb_qos_dis_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mstif_req_qos : 14;
        unsigned int reserved_0 : 2;
        unsigned int cfgcmo_pri : 2;
        unsigned int smq_sc_pri : 2;
        unsigned int autoclen_pri : 2;
        unsigned int cmo_inval_pri : 2;
        unsigned int syncbuf_sc_pri : 2;
        unsigned int bypbuf_cpu_pri : 2;
        unsigned int bypbuf_cpu_pri_fix_en : 1;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_SC_PRI_QOS_CTRL1_UNION;
#endif
#define SOC_SC_PRI_QOS_CTRL1_mstif_req_qos_START (0)
#define SOC_SC_PRI_QOS_CTRL1_mstif_req_qos_END (13)
#define SOC_SC_PRI_QOS_CTRL1_cfgcmo_pri_START (16)
#define SOC_SC_PRI_QOS_CTRL1_cfgcmo_pri_END (17)
#define SOC_SC_PRI_QOS_CTRL1_smq_sc_pri_START (18)
#define SOC_SC_PRI_QOS_CTRL1_smq_sc_pri_END (19)
#define SOC_SC_PRI_QOS_CTRL1_autoclen_pri_START (20)
#define SOC_SC_PRI_QOS_CTRL1_autoclen_pri_END (21)
#define SOC_SC_PRI_QOS_CTRL1_cmo_inval_pri_START (22)
#define SOC_SC_PRI_QOS_CTRL1_cmo_inval_pri_END (23)
#define SOC_SC_PRI_QOS_CTRL1_syncbuf_sc_pri_START (24)
#define SOC_SC_PRI_QOS_CTRL1_syncbuf_sc_pri_END (25)
#define SOC_SC_PRI_QOS_CTRL1_bypbuf_cpu_pri_START (26)
#define SOC_SC_PRI_QOS_CTRL1_bypbuf_cpu_pri_END (27)
#define SOC_SC_PRI_QOS_CTRL1_bypbuf_cpu_pri_fix_en_START (28)
#define SOC_SC_PRI_QOS_CTRL1_bypbuf_cpu_pri_fix_en_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int low_rdata_weight : 10;
        unsigned int reserved_0 : 2;
        unsigned int high_rdata_weight : 10;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_SC_FECQ_WRR_WEIGHT_UNION;
#endif
#define SOC_SC_FECQ_WRR_WEIGHT_low_rdata_weight_START (0)
#define SOC_SC_FECQ_WRR_WEIGHT_low_rdata_weight_END (9)
#define SOC_SC_FECQ_WRR_WEIGHT_high_rdata_weight_START (12)
#define SOC_SC_FECQ_WRR_WEIGHT_high_rdata_weight_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mstif_wdwrr_weight : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_SC_MSTIF_WRR_WEIGHT_UNION;
#endif
#define SOC_SC_MSTIF_WRR_WEIGHT_mstif_wdwrr_weight_START (0)
#define SOC_SC_MSTIF_WRR_WEIGHT_mstif_wdwrr_weight_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int chi_fecq_rsv_pri : 2;
        unsigned int reserved_0 : 2;
        unsigned int chi_fecq_rsv_num : 5;
        unsigned int reserved_1 : 3;
        unsigned int qice_fecq_rsv_pri : 2;
        unsigned int reserved_2 : 2;
        unsigned int qice_fecq_rsv_num : 5;
        unsigned int reserved_3 : 3;
        unsigned int becq_rt_rsv_num : 7;
        unsigned int reserved_4 : 1;
    } reg;
} SOC_SC_RSV_CTRL0_UNION;
#endif
#define SOC_SC_RSV_CTRL0_chi_fecq_rsv_pri_START (0)
#define SOC_SC_RSV_CTRL0_chi_fecq_rsv_pri_END (1)
#define SOC_SC_RSV_CTRL0_chi_fecq_rsv_num_START (4)
#define SOC_SC_RSV_CTRL0_chi_fecq_rsv_num_END (8)
#define SOC_SC_RSV_CTRL0_qice_fecq_rsv_pri_START (12)
#define SOC_SC_RSV_CTRL0_qice_fecq_rsv_pri_END (13)
#define SOC_SC_RSV_CTRL0_qice_fecq_rsv_num_START (16)
#define SOC_SC_RSV_CTRL0_qice_fecq_rsv_num_END (20)
#define SOC_SC_RSV_CTRL0_becq_rt_rsv_num_START (24)
#define SOC_SC_RSV_CTRL0_becq_rt_rsv_num_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bypbuf_rsv_cnt : 7;
        unsigned int reserved_0 : 1;
        unsigned int bypbuf_rsv_pri : 2;
        unsigned int reserved_1 : 2;
        unsigned int retry_rsv_num : 5;
        unsigned int reserved_2 : 15;
    } reg;
} SOC_SC_RSV_CTRL1_UNION;
#endif
#define SOC_SC_RSV_CTRL1_bypbuf_rsv_cnt_START (0)
#define SOC_SC_RSV_CTRL1_bypbuf_rsv_cnt_END (6)
#define SOC_SC_RSV_CTRL1_bypbuf_rsv_pri_START (8)
#define SOC_SC_RSV_CTRL1_bypbuf_rsv_pri_END (9)
#define SOC_SC_RSV_CTRL1_retry_rsv_num_START (12)
#define SOC_SC_RSV_CTRL1_retry_rsv_num_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_pri_0 : 32;
    } reg;
} SOC_SC_TKN_PRI_CFG0_UNION;
#endif
#define SOC_SC_TKN_PRI_CFG0_tkn_pri_0_START (0)
#define SOC_SC_TKN_PRI_CFG0_tkn_pri_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_pri_1 : 32;
    } reg;
} SOC_SC_TKN_PRI_CFG1_UNION;
#endif
#define SOC_SC_TKN_PRI_CFG1_tkn_pri_1_START (0)
#define SOC_SC_TKN_PRI_CFG1_tkn_pri_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_pri_2 : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SC_TKN_PRI_CFG2_UNION;
#endif
#define SOC_SC_TKN_PRI_CFG2_tkn_pri_2_START (0)
#define SOC_SC_TKN_PRI_CFG2_tkn_pri_2_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_weight_0 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_SC_TKN_WEIGHT_CFG0_UNION;
#endif
#define SOC_SC_TKN_WEIGHT_CFG0_tkn_weight_0_START (0)
#define SOC_SC_TKN_WEIGHT_CFG0_tkn_weight_0_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_weight_1 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_SC_TKN_WEIGHT_CFG1_UNION;
#endif
#define SOC_SC_TKN_WEIGHT_CFG1_tkn_weight_1_START (0)
#define SOC_SC_TKN_WEIGHT_CFG1_tkn_weight_1_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_weight_2 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_SC_TKN_WEIGHT_CFG2_UNION;
#endif
#define SOC_SC_TKN_WEIGHT_CFG2_tkn_weight_2_START (0)
#define SOC_SC_TKN_WEIGHT_CFG2_tkn_weight_2_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_weight_3 : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_SC_TKN_WEIGHT_CFG3_UNION;
#endif
#define SOC_SC_TKN_WEIGHT_CFG3_tkn_weight_3_START (0)
#define SOC_SC_TKN_WEIGHT_CFG3_tkn_weight_3_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tkn_weight_4 : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_SC_TKN_WEIGHT_CFG4_UNION;
#endif
#define SOC_SC_TKN_WEIGHT_CFG4_tkn_weight_4_START (0)
#define SOC_SC_TKN_WEIGHT_CFG4_tkn_weight_4_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mst_token_rsv_num : 9;
        unsigned int reserved_0 : 3;
        unsigned int mst_token_rsv_num_updt : 1;
        unsigned int reserved_1 : 3;
        unsigned int mst_token_rsv_th : 9;
        unsigned int mst_token_rsv_pri_qtpe : 3;
        unsigned int mst_token_rsv_wr_en : 1;
        unsigned int reserved_2 : 3;
    } reg;
} SOC_SC_MST_TOKEN_CFG0_UNION;
#endif
#define SOC_SC_MST_TOKEN_CFG0_mst_token_rsv_num_START (0)
#define SOC_SC_MST_TOKEN_CFG0_mst_token_rsv_num_END (8)
#define SOC_SC_MST_TOKEN_CFG0_mst_token_rsv_num_updt_START (12)
#define SOC_SC_MST_TOKEN_CFG0_mst_token_rsv_num_updt_END (12)
#define SOC_SC_MST_TOKEN_CFG0_mst_token_rsv_th_START (16)
#define SOC_SC_MST_TOKEN_CFG0_mst_token_rsv_th_END (24)
#define SOC_SC_MST_TOKEN_CFG0_mst_token_rsv_pri_qtpe_START (25)
#define SOC_SC_MST_TOKEN_CFG0_mst_token_rsv_pri_qtpe_END (27)
#define SOC_SC_MST_TOKEN_CFG0_mst_token_rsv_wr_en_START (28)
#define SOC_SC_MST_TOKEN_CFG0_mst_token_rsv_wr_en_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_slv_tkn_rsv_num : 5;
        unsigned int reserved_0 : 3;
        unsigned int qice_slv_tkn_upd : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_SC_FECQ_TOKEN_CFG0_UNION;
#endif
#define SOC_SC_FECQ_TOKEN_CFG0_qice_slv_tkn_rsv_num_START (0)
#define SOC_SC_FECQ_TOKEN_CFG0_qice_slv_tkn_rsv_num_END (4)
#define SOC_SC_FECQ_TOKEN_CFG0_qice_slv_tkn_upd_START (8)
#define SOC_SC_FECQ_TOKEN_CFG0_qice_slv_tkn_upd_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int chi_intf_rglr_bw : 8;
        unsigned int chi_intf_rglr_sat : 8;
        unsigned int chi_intf_rglr_pri : 2;
        unsigned int reserved_0 : 2;
        unsigned int chi_intf_rglr_lp : 2;
        unsigned int reserved_1 : 9;
        unsigned int chi_intf_rglr_en : 1;
    } reg;
} SOC_SC_QOS_RGLR_UNION;
#endif
#define SOC_SC_QOS_RGLR_chi_intf_rglr_bw_START (0)
#define SOC_SC_QOS_RGLR_chi_intf_rglr_bw_END (7)
#define SOC_SC_QOS_RGLR_chi_intf_rglr_sat_START (8)
#define SOC_SC_QOS_RGLR_chi_intf_rglr_sat_END (15)
#define SOC_SC_QOS_RGLR_chi_intf_rglr_pri_START (16)
#define SOC_SC_QOS_RGLR_chi_intf_rglr_pri_END (17)
#define SOC_SC_QOS_RGLR_chi_intf_rglr_lp_START (20)
#define SOC_SC_QOS_RGLR_chi_intf_rglr_lp_END (21)
#define SOC_SC_QOS_RGLR_chi_intf_rglr_en_START (31)
#define SOC_SC_QOS_RGLR_chi_intf_rglr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dyn_cfc_bw : 8;
        unsigned int dyn_cfc_sat : 8;
        unsigned int reserved_0 : 8;
        unsigned int dyn_cfc_lp : 2;
        unsigned int reserved_1 : 5;
        unsigned int dyn_cfc_en : 1;
    } reg;
} SOC_SC_MST_DYN_CFC_LIMIT_UNION;
#endif
#define SOC_SC_MST_DYN_CFC_LIMIT_dyn_cfc_bw_START (0)
#define SOC_SC_MST_DYN_CFC_LIMIT_dyn_cfc_bw_END (7)
#define SOC_SC_MST_DYN_CFC_LIMIT_dyn_cfc_sat_START (8)
#define SOC_SC_MST_DYN_CFC_LIMIT_dyn_cfc_sat_END (15)
#define SOC_SC_MST_DYN_CFC_LIMIT_dyn_cfc_lp_START (24)
#define SOC_SC_MST_DYN_CFC_LIMIT_dyn_cfc_lp_END (25)
#define SOC_SC_MST_DYN_CFC_LIMIT_dyn_cfc_en_START (31)
#define SOC_SC_MST_DYN_CFC_LIMIT_dyn_cfc_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_cfc_bw : 8;
        unsigned int sta_cfc_sat : 8;
        unsigned int reserved_0 : 8;
        unsigned int sta_cfc_lp : 2;
        unsigned int reserved_1 : 5;
        unsigned int sta_cfc_en : 1;
    } reg;
} SOC_SC_MST_STA_CFC_LIMIT_UNION;
#endif
#define SOC_SC_MST_STA_CFC_LIMIT_sta_cfc_bw_START (0)
#define SOC_SC_MST_STA_CFC_LIMIT_sta_cfc_bw_END (7)
#define SOC_SC_MST_STA_CFC_LIMIT_sta_cfc_sat_START (8)
#define SOC_SC_MST_STA_CFC_LIMIT_sta_cfc_sat_END (15)
#define SOC_SC_MST_STA_CFC_LIMIT_sta_cfc_lp_START (24)
#define SOC_SC_MST_STA_CFC_LIMIT_sta_cfc_lp_END (25)
#define SOC_SC_MST_STA_CFC_LIMIT_sta_cfc_en_START (31)
#define SOC_SC_MST_STA_CFC_LIMIT_sta_cfc_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qos_allow_map : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_SC_MST_QOSALLOW_MAP_UNION;
#endif
#define SOC_SC_MST_QOSALLOW_MAP_qos_allow_map_START (0)
#define SOC_SC_MST_QOSALLOW_MAP_qos_allow_map_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int becq_spec_threshold : 6;
        unsigned int reserved_0 : 2;
        unsigned int becq_ncoh_threshold : 6;
        unsigned int reserved_1 : 2;
        unsigned int becq_unser_threshold : 6;
        unsigned int reserved_2 : 2;
        unsigned int becq_dev_threshold : 6;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_SC_TH_CTRL0_UNION;
#endif
#define SOC_SC_TH_CTRL0_becq_spec_threshold_START (0)
#define SOC_SC_TH_CTRL0_becq_spec_threshold_END (5)
#define SOC_SC_TH_CTRL0_becq_ncoh_threshold_START (8)
#define SOC_SC_TH_CTRL0_becq_ncoh_threshold_END (13)
#define SOC_SC_TH_CTRL0_becq_unser_threshold_START (16)
#define SOC_SC_TH_CTRL0_becq_unser_threshold_END (21)
#define SOC_SC_TH_CTRL0_becq_dev_threshold_START (24)
#define SOC_SC_TH_CTRL0_becq_dev_threshold_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tpbuf_rt_min : 4;
        unsigned int tpbuf_dev_min : 4;
        unsigned int tpbuf_dev_max : 4;
        unsigned int tpbuf_dvmsnp_os : 6;
        unsigned int tpbuf_snoop_os : 6;
        unsigned int tpbuf_dvmsnp_os1 : 6;
        unsigned int reserved : 2;
    } reg;
} SOC_SC_TH_CTRL1_UNION;
#endif
#define SOC_SC_TH_CTRL1_tpbuf_rt_min_START (0)
#define SOC_SC_TH_CTRL1_tpbuf_rt_min_END (3)
#define SOC_SC_TH_CTRL1_tpbuf_dev_min_START (4)
#define SOC_SC_TH_CTRL1_tpbuf_dev_min_END (7)
#define SOC_SC_TH_CTRL1_tpbuf_dev_max_START (8)
#define SOC_SC_TH_CTRL1_tpbuf_dev_max_END (11)
#define SOC_SC_TH_CTRL1_tpbuf_dvmsnp_os_START (12)
#define SOC_SC_TH_CTRL1_tpbuf_dvmsnp_os_END (17)
#define SOC_SC_TH_CTRL1_tpbuf_snoop_os_START (18)
#define SOC_SC_TH_CTRL1_tpbuf_snoop_os_END (23)
#define SOC_SC_TH_CTRL1_tpbuf_dvmsnp_os1_START (24)
#define SOC_SC_TH_CTRL1_tpbuf_dvmsnp_os1_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tpbuf_snoop_os1 : 6;
        unsigned int reserved_0 : 2;
        unsigned int tpbuf_cpu_min : 4;
        unsigned int becq_dvm_threshold : 6;
        unsigned int reserved_1 : 2;
        unsigned int dmemif2fecq_threshold : 6;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_SC_TH_CTRL2_UNION;
#endif
#define SOC_SC_TH_CTRL2_tpbuf_snoop_os1_START (0)
#define SOC_SC_TH_CTRL2_tpbuf_snoop_os1_END (5)
#define SOC_SC_TH_CTRL2_tpbuf_cpu_min_START (8)
#define SOC_SC_TH_CTRL2_tpbuf_cpu_min_END (11)
#define SOC_SC_TH_CTRL2_becq_dvm_threshold_START (12)
#define SOC_SC_TH_CTRL2_becq_dvm_threshold_END (17)
#define SOC_SC_TH_CTRL2_dmemif2fecq_threshold_START (20)
#define SOC_SC_TH_CTRL2_dmemif2fecq_threshold_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int read_sum_th : 7;
        unsigned int reserved_0 : 1;
        unsigned int read_miss_th : 7;
        unsigned int reserved_1 : 1;
        unsigned int spec_rd_sum_th : 7;
        unsigned int reserved_2 : 1;
        unsigned int spec_rd_suc_th : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_SC_TH_CTRL3_UNION;
#endif
#define SOC_SC_TH_CTRL3_read_sum_th_START (0)
#define SOC_SC_TH_CTRL3_read_sum_th_END (6)
#define SOC_SC_TH_CTRL3_read_miss_th_START (8)
#define SOC_SC_TH_CTRL3_read_miss_th_END (14)
#define SOC_SC_TH_CTRL3_spec_rd_sum_th_START (16)
#define SOC_SC_TH_CTRL3_spec_rd_sum_th_END (22)
#define SOC_SC_TH_CTRL3_spec_rd_suc_th_START (24)
#define SOC_SC_TH_CTRL3_spec_rd_suc_th_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmoq_thrd_l : 7;
        unsigned int pri_allow_limit_en : 1;
        unsigned int reserved : 8;
        unsigned int cmoq_thrd_h : 7;
        unsigned int pri_allow_block_en : 1;
        unsigned int low_byp_buf_th : 4;
        unsigned int high_byp_buf_th : 4;
    } reg;
} SOC_SC_TH_CTRL4_UNION;
#endif
#define SOC_SC_TH_CTRL4_cmoq_thrd_l_START (0)
#define SOC_SC_TH_CTRL4_cmoq_thrd_l_END (6)
#define SOC_SC_TH_CTRL4_pri_allow_limit_en_START (7)
#define SOC_SC_TH_CTRL4_pri_allow_limit_en_END (7)
#define SOC_SC_TH_CTRL4_cmoq_thrd_h_START (16)
#define SOC_SC_TH_CTRL4_cmoq_thrd_h_END (22)
#define SOC_SC_TH_CTRL4_pri_allow_block_en_START (23)
#define SOC_SC_TH_CTRL4_pri_allow_block_en_END (23)
#define SOC_SC_TH_CTRL4_low_byp_buf_th_START (24)
#define SOC_SC_TH_CTRL4_low_byp_buf_th_END (27)
#define SOC_SC_TH_CTRL4_high_byp_buf_th_START (28)
#define SOC_SC_TH_CTRL4_high_byp_buf_th_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qice_ost_threshold : 7;
        unsigned int reserved_0 : 1;
        unsigned int chi_ost_threshold : 7;
        unsigned int reserved_1 : 1;
        unsigned int token_rtn_threshold : 3;
        unsigned int reserved_2 : 1;
        unsigned int stash_th : 7;
        unsigned int reserved_3 : 5;
    } reg;
} SOC_SC_TH_CTRL5_UNION;
#endif
#define SOC_SC_TH_CTRL5_qice_ost_threshold_START (0)
#define SOC_SC_TH_CTRL5_qice_ost_threshold_END (6)
#define SOC_SC_TH_CTRL5_chi_ost_threshold_START (8)
#define SOC_SC_TH_CTRL5_chi_ost_threshold_END (14)
#define SOC_SC_TH_CTRL5_token_rtn_threshold_START (16)
#define SOC_SC_TH_CTRL5_token_rtn_threshold_END (18)
#define SOC_SC_TH_CTRL5_stash_th_START (20)
#define SOC_SC_TH_CTRL5_stash_th_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int becq_threshold : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_SC_TH_BY_PRI_CTRL0_UNION;
#endif
#define SOC_SC_TH_BY_PRI_CTRL0_becq_threshold_START (0)
#define SOC_SC_TH_BY_PRI_CTRL0_becq_threshold_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int chi_fecq_threshold : 5;
        unsigned int reserved_0 : 3;
        unsigned int qice_fecq_threshold : 5;
        unsigned int reserved_1 : 3;
        unsigned int chi_pri_ost_threshold : 7;
        unsigned int reserved_2 : 1;
        unsigned int qice_pri_ost_threshold : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_SC_TH_BY_PRI_CTRL1_UNION;
#endif
#define SOC_SC_TH_BY_PRI_CTRL1_chi_fecq_threshold_START (0)
#define SOC_SC_TH_BY_PRI_CTRL1_chi_fecq_threshold_END (4)
#define SOC_SC_TH_BY_PRI_CTRL1_qice_fecq_threshold_START (8)
#define SOC_SC_TH_BY_PRI_CTRL1_qice_fecq_threshold_END (12)
#define SOC_SC_TH_BY_PRI_CTRL1_chi_pri_ost_threshold_START (16)
#define SOC_SC_TH_BY_PRI_CTRL1_chi_pri_ost_threshold_END (22)
#define SOC_SC_TH_BY_PRI_CTRL1_qice_pri_ost_threshold_START (24)
#define SOC_SC_TH_BY_PRI_CTRL1_qice_pri_ost_threshold_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fecq_qos_allow_threshold : 5;
        unsigned int reserved_0 : 3;
        unsigned int becq_qos_allow_threshold : 6;
        unsigned int reserved_1 : 2;
        unsigned int bypq_qos_allow_threshold : 6;
        unsigned int reserved_2 : 2;
        unsigned int bypqct_qos_allow_threshold : 6;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_SC_FECQ_QOS_ALLOW_TH_UNION;
#endif
#define SOC_SC_FECQ_QOS_ALLOW_TH_fecq_qos_allow_threshold_START (0)
#define SOC_SC_FECQ_QOS_ALLOW_TH_fecq_qos_allow_threshold_END (4)
#define SOC_SC_FECQ_QOS_ALLOW_TH_becq_qos_allow_threshold_START (8)
#define SOC_SC_FECQ_QOS_ALLOW_TH_becq_qos_allow_threshold_END (13)
#define SOC_SC_FECQ_QOS_ALLOW_TH_bypq_qos_allow_threshold_START (16)
#define SOC_SC_FECQ_QOS_ALLOW_TH_bypq_qos_allow_threshold_END (21)
#define SOC_SC_FECQ_QOS_ALLOW_TH_bypqct_qos_allow_threshold_START (24)
#define SOC_SC_FECQ_QOS_ALLOW_TH_bypqct_qos_allow_threshold_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int becq_alloc_mask : 32;
    } reg;
} SOC_SC_BECQ_ALLOC_MASK_UNION;
#endif
#define SOC_SC_BECQ_ALLOC_MASK_becq_alloc_mask_START (0)
#define SOC_SC_BECQ_ALLOC_MASK_becq_alloc_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr_flush_cnt_th : 4;
        unsigned int addr_flush_push_en : 1;
        unsigned int pa_flush_static_en : 1;
        unsigned int set_flush_static_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int cmoq_inteval : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_SC_FLUSH_CMOQ_CTRL0_UNION;
#endif
#define SOC_SC_FLUSH_CMOQ_CTRL0_addr_flush_cnt_th_START (0)
#define SOC_SC_FLUSH_CMOQ_CTRL0_addr_flush_cnt_th_END (3)
#define SOC_SC_FLUSH_CMOQ_CTRL0_addr_flush_push_en_START (4)
#define SOC_SC_FLUSH_CMOQ_CTRL0_addr_flush_push_en_END (4)
#define SOC_SC_FLUSH_CMOQ_CTRL0_pa_flush_static_en_START (5)
#define SOC_SC_FLUSH_CMOQ_CTRL0_pa_flush_static_en_END (5)
#define SOC_SC_FLUSH_CMOQ_CTRL0_set_flush_static_en_START (6)
#define SOC_SC_FLUSH_CMOQ_CTRL0_set_flush_static_en_END (6)
#define SOC_SC_FLUSH_CMOQ_CTRL0_cmoq_inteval_START (8)
#define SOC_SC_FLUSH_CMOQ_CTRL0_cmoq_inteval_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int haz_timeout_limit : 24;
        unsigned int fecq2tpipe_matua_push_en : 1;
        unsigned int fecq2byp_matua_push_en : 1;
        unsigned int reserved : 5;
        unsigned int haz_timeout_en : 1;
    } reg;
} SOC_SC_TIMEOUT_CTRL0_UNION;
#endif
#define SOC_SC_TIMEOUT_CTRL0_haz_timeout_limit_START (0)
#define SOC_SC_TIMEOUT_CTRL0_haz_timeout_limit_END (23)
#define SOC_SC_TIMEOUT_CTRL0_fecq2tpipe_matua_push_en_START (24)
#define SOC_SC_TIMEOUT_CTRL0_fecq2tpipe_matua_push_en_END (24)
#define SOC_SC_TIMEOUT_CTRL0_fecq2byp_matua_push_en_START (25)
#define SOC_SC_TIMEOUT_CTRL0_fecq2byp_matua_push_en_END (25)
#define SOC_SC_TIMEOUT_CTRL0_haz_timeout_en_START (31)
#define SOC_SC_TIMEOUT_CTRL0_haz_timeout_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tpipe2biq_arb_timeout_limit : 10;
        unsigned int reserved_0 : 1;
        unsigned int tpipe2biq_arb_timeout_en : 1;
        unsigned int tpipe2becq_arb_timeout_limit : 10;
        unsigned int reserved_1 : 1;
        unsigned int tpipe2becq_arb_timeout_en : 1;
        unsigned int reserved_2 : 8;
    } reg;
} SOC_SC_TIMEOUT_CTRL1_UNION;
#endif
#define SOC_SC_TIMEOUT_CTRL1_tpipe2biq_arb_timeout_limit_START (0)
#define SOC_SC_TIMEOUT_CTRL1_tpipe2biq_arb_timeout_limit_END (9)
#define SOC_SC_TIMEOUT_CTRL1_tpipe2biq_arb_timeout_en_START (11)
#define SOC_SC_TIMEOUT_CTRL1_tpipe2biq_arb_timeout_en_END (11)
#define SOC_SC_TIMEOUT_CTRL1_tpipe2becq_arb_timeout_limit_START (12)
#define SOC_SC_TIMEOUT_CTRL1_tpipe2becq_arb_timeout_limit_END (21)
#define SOC_SC_TIMEOUT_CTRL1_tpipe2becq_arb_timeout_en_START (23)
#define SOC_SC_TIMEOUT_CTRL1_tpipe2becq_arb_timeout_en_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tpipe2cmoq_arb_timeout_limit : 10;
        unsigned int reserved_0 : 1;
        unsigned int tpipe2cmoq_arb_timeout_en : 1;
        unsigned int biq_tmo_limit : 6;
        unsigned int reserved_1 : 1;
        unsigned int biq_tmo_en : 1;
        unsigned int reserved_2 : 12;
    } reg;
} SOC_SC_TIMEOUT_CTRL2_UNION;
#endif
#define SOC_SC_TIMEOUT_CTRL2_tpipe2cmoq_arb_timeout_limit_START (0)
#define SOC_SC_TIMEOUT_CTRL2_tpipe2cmoq_arb_timeout_limit_END (9)
#define SOC_SC_TIMEOUT_CTRL2_tpipe2cmoq_arb_timeout_en_START (11)
#define SOC_SC_TIMEOUT_CTRL2_tpipe2cmoq_arb_timeout_en_END (11)
#define SOC_SC_TIMEOUT_CTRL2_biq_tmo_limit_START (12)
#define SOC_SC_TIMEOUT_CTRL2_biq_tmo_limit_END (17)
#define SOC_SC_TIMEOUT_CTRL2_biq_tmo_en_START (19)
#define SOC_SC_TIMEOUT_CTRL2_biq_tmo_en_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdata_arb_timeout_limit : 10;
        unsigned int reserved_0 : 1;
        unsigned int rdata_arb_timeout_en : 1;
        unsigned int dlock_timeout_th : 10;
        unsigned int reserved_1 : 1;
        unsigned int dlock_timeout_dis : 1;
        unsigned int reserved_2 : 8;
    } reg;
} SOC_SC_TIMEOUT_CTRL3_UNION;
#endif
#define SOC_SC_TIMEOUT_CTRL3_rdata_arb_timeout_limit_START (0)
#define SOC_SC_TIMEOUT_CTRL3_rdata_arb_timeout_limit_END (9)
#define SOC_SC_TIMEOUT_CTRL3_rdata_arb_timeout_en_START (11)
#define SOC_SC_TIMEOUT_CTRL3_rdata_arb_timeout_en_END (11)
#define SOC_SC_TIMEOUT_CTRL3_dlock_timeout_th_START (12)
#define SOC_SC_TIMEOUT_CTRL3_dlock_timeout_th_END (21)
#define SOC_SC_TIMEOUT_CTRL3_dlock_timeout_dis_START (23)
#define SOC_SC_TIMEOUT_CTRL3_dlock_timeout_dis_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bedb_pri0_th : 10;
        unsigned int reserved_0 : 2;
        unsigned int bedb_pri1_th : 10;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_SC_TIMEOUT_CTRL4_UNION;
#endif
#define SOC_SC_TIMEOUT_CTRL4_bedb_pri0_th_START (0)
#define SOC_SC_TIMEOUT_CTRL4_bedb_pri0_th_END (9)
#define SOC_SC_TIMEOUT_CTRL4_bedb_pri1_th_START (12)
#define SOC_SC_TIMEOUT_CTRL4_bedb_pri1_th_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bedb_pri2_th : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_SC_TIMEOUT_CTRL5_UNION;
#endif
#define SOC_SC_TIMEOUT_CTRL5_bedb_pri2_th_START (0)
#define SOC_SC_TIMEOUT_CTRL5_bedb_pri2_th_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tpipe2fecq_arb_timeout_limit : 10;
        unsigned int reserved_0 : 1;
        unsigned int tpipe2fecq_arb_timeout_en : 1;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_SC_TIMEOUT_BY_FECQ_CTRL0_UNION;
#endif
#define SOC_SC_TIMEOUT_BY_FECQ_CTRL0_tpipe2fecq_arb_timeout_limit_START (0)
#define SOC_SC_TIMEOUT_BY_FECQ_CTRL0_tpipe2fecq_arb_timeout_limit_END (9)
#define SOC_SC_TIMEOUT_BY_FECQ_CTRL0_tpipe2fecq_arb_timeout_en_START (11)
#define SOC_SC_TIMEOUT_BY_FECQ_CTRL0_tpipe2fecq_arb_timeout_en_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fecq_arb_timeout_limit : 10;
        unsigned int reserved_0 : 1;
        unsigned int fecq_arb_timeout_en : 1;
        unsigned int retry_arb_timeout_limit : 10;
        unsigned int reserved_1 : 1;
        unsigned int retry_timeout_en : 1;
        unsigned int reserved_2 : 8;
    } reg;
} SOC_SC_TIMEOUT_BY_PRI_CTRL0_UNION;
#endif
#define SOC_SC_TIMEOUT_BY_PRI_CTRL0_fecq_arb_timeout_limit_START (0)
#define SOC_SC_TIMEOUT_BY_PRI_CTRL0_fecq_arb_timeout_limit_END (9)
#define SOC_SC_TIMEOUT_BY_PRI_CTRL0_fecq_arb_timeout_en_START (11)
#define SOC_SC_TIMEOUT_BY_PRI_CTRL0_fecq_arb_timeout_en_END (11)
#define SOC_SC_TIMEOUT_BY_PRI_CTRL0_retry_arb_timeout_limit_START (12)
#define SOC_SC_TIMEOUT_BY_PRI_CTRL0_retry_arb_timeout_limit_END (21)
#define SOC_SC_TIMEOUT_BY_PRI_CTRL0_retry_timeout_en_START (23)
#define SOC_SC_TIMEOUT_BY_PRI_CTRL0_retry_timeout_en_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bypbuf_arb_timeout_limit : 10;
        unsigned int reserved_0 : 1;
        unsigned int bypbuf_arb_timeout_en : 1;
        unsigned int bypbuf_fecq_timeout_limit : 10;
        unsigned int reserved_1 : 1;
        unsigned int bypbuf_fecq_timeout_en : 1;
        unsigned int reserved_2 : 8;
    } reg;
} SOC_SC_TIMEOUT_BY_PRI_CTRL1_UNION;
#endif
#define SOC_SC_TIMEOUT_BY_PRI_CTRL1_bypbuf_arb_timeout_limit_START (0)
#define SOC_SC_TIMEOUT_BY_PRI_CTRL1_bypbuf_arb_timeout_limit_END (9)
#define SOC_SC_TIMEOUT_BY_PRI_CTRL1_bypbuf_arb_timeout_en_START (11)
#define SOC_SC_TIMEOUT_BY_PRI_CTRL1_bypbuf_arb_timeout_en_END (11)
#define SOC_SC_TIMEOUT_BY_PRI_CTRL1_bypbuf_fecq_timeout_limit_START (12)
#define SOC_SC_TIMEOUT_BY_PRI_CTRL1_bypbuf_fecq_timeout_limit_END (21)
#define SOC_SC_TIMEOUT_BY_PRI_CTRL1_bypbuf_fecq_timeout_en_START (23)
#define SOC_SC_TIMEOUT_BY_PRI_CTRL1_bypbuf_fecq_timeout_en_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int becq_arb_timeout_limit : 10;
        unsigned int reserved_0 : 1;
        unsigned int becq_arb_timeout_en : 1;
        unsigned int src2mstif_timeout_limit : 10;
        unsigned int reserved_1 : 1;
        unsigned int src2mstif_timeout_en : 1;
        unsigned int reserved_2 : 8;
    } reg;
} SOC_SC_TIMEOUT_BY_PRI_CTRL2_UNION;
#endif
#define SOC_SC_TIMEOUT_BY_PRI_CTRL2_becq_arb_timeout_limit_START (0)
#define SOC_SC_TIMEOUT_BY_PRI_CTRL2_becq_arb_timeout_limit_END (9)
#define SOC_SC_TIMEOUT_BY_PRI_CTRL2_becq_arb_timeout_en_START (11)
#define SOC_SC_TIMEOUT_BY_PRI_CTRL2_becq_arb_timeout_en_END (11)
#define SOC_SC_TIMEOUT_BY_PRI_CTRL2_src2mstif_timeout_limit_START (12)
#define SOC_SC_TIMEOUT_BY_PRI_CTRL2_src2mstif_timeout_limit_END (21)
#define SOC_SC_TIMEOUT_BY_PRI_CTRL2_src2mstif_timeout_en_START (23)
#define SOC_SC_TIMEOUT_BY_PRI_CTRL2_src2mstif_timeout_en_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dummy_reg_1 : 32;
    } reg;
} SOC_SC_DUMMY_REG1_UNION;
#endif
#define SOC_SC_DUMMY_REG1_dummy_reg_1_START (0)
#define SOC_SC_DUMMY_REG1_dummy_reg_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intlv_gran : 2;
        unsigned int reserved_0 : 6;
        unsigned int addr_shift_mode : 2;
        unsigned int rop_mode_sel : 1;
        unsigned int reserved_1 : 5;
        unsigned int addr_bound0 : 7;
        unsigned int reserved_2 : 1;
        unsigned int addr_bound1 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_SC_GLB_ADDR_CTRL_UNION;
#endif
#define SOC_SC_GLB_ADDR_CTRL_intlv_gran_START (0)
#define SOC_SC_GLB_ADDR_CTRL_intlv_gran_END (1)
#define SOC_SC_GLB_ADDR_CTRL_addr_shift_mode_START (8)
#define SOC_SC_GLB_ADDR_CTRL_addr_shift_mode_END (9)
#define SOC_SC_GLB_ADDR_CTRL_rop_mode_sel_START (10)
#define SOC_SC_GLB_ADDR_CTRL_rop_mode_sel_END (10)
#define SOC_SC_GLB_ADDR_CTRL_addr_bound0_START (16)
#define SOC_SC_GLB_ADDR_CTRL_addr_bound0_END (22)
#define SOC_SC_GLB_ADDR_CTRL_addr_bound1_START (24)
#define SOC_SC_GLB_ADDR_CTRL_addr_bound1_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int scramble_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SC_GLB_ADDR_CTRL1_UNION;
#endif
#define SOC_SC_GLB_ADDR_CTRL1_scramble_en_START (0)
#define SOC_SC_GLB_ADDR_CTRL1_scramble_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sf_en : 1;
        unsigned int gid_use_pa_en : 1;
        unsigned int set_scramble : 1;
        unsigned int sf_scramble_en : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_SC_GLB_PIPE_CTRL_UNION;
#endif
#define SOC_SC_GLB_PIPE_CTRL_sf_en_START (0)
#define SOC_SC_GLB_PIPE_CTRL_sf_en_END (0)
#define SOC_SC_GLB_PIPE_CTRL_gid_use_pa_en_START (1)
#define SOC_SC_GLB_PIPE_CTRL_gid_use_pa_en_END (1)
#define SOC_SC_GLB_PIPE_CTRL_set_scramble_START (2)
#define SOC_SC_GLB_PIPE_CTRL_set_scramble_END (2)
#define SOC_SC_GLB_PIPE_CTRL_sf_scramble_en_START (3)
#define SOC_SC_GLB_PIPE_CTRL_sf_scramble_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmt_en : 1;
        unsigned int dmt_en_cpu : 1;
        unsigned int bypbuf_dmt_en : 1;
        unsigned int bypbuf_dmt_en_cpu : 1;
        unsigned int dwt_en : 1;
        unsigned int dwt_en_cpu : 1;
        unsigned int bypbuf_dwt_en : 1;
        unsigned int bypbuf_dwt_en_cpu : 1;
        unsigned int addr_bcomp_sel : 1;
        unsigned int excl_event_dis : 1;
        unsigned int hazard_64b_opt_dis : 1;
        unsigned int sc_glb_bypass_en : 1;
        unsigned int sc_bypass_sel : 1;
        unsigned int parity_en : 1;
        unsigned int chi_work_mode : 1;
        unsigned int poc_excl_event_dis : 1;
        unsigned int stash_abandon_en : 1;
        unsigned int bypipe_cmo_fecq_sel : 1;
        unsigned int cfg_no_vtm_fl_buf_byp : 1;
        unsigned int stash_int_disable : 1;
        unsigned int pgid0_force_cmoen : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_SC_BASE_CTRL0_UNION;
#endif
#define SOC_SC_BASE_CTRL0_dmt_en_START (0)
#define SOC_SC_BASE_CTRL0_dmt_en_END (0)
#define SOC_SC_BASE_CTRL0_dmt_en_cpu_START (1)
#define SOC_SC_BASE_CTRL0_dmt_en_cpu_END (1)
#define SOC_SC_BASE_CTRL0_bypbuf_dmt_en_START (2)
#define SOC_SC_BASE_CTRL0_bypbuf_dmt_en_END (2)
#define SOC_SC_BASE_CTRL0_bypbuf_dmt_en_cpu_START (3)
#define SOC_SC_BASE_CTRL0_bypbuf_dmt_en_cpu_END (3)
#define SOC_SC_BASE_CTRL0_dwt_en_START (4)
#define SOC_SC_BASE_CTRL0_dwt_en_END (4)
#define SOC_SC_BASE_CTRL0_dwt_en_cpu_START (5)
#define SOC_SC_BASE_CTRL0_dwt_en_cpu_END (5)
#define SOC_SC_BASE_CTRL0_bypbuf_dwt_en_START (6)
#define SOC_SC_BASE_CTRL0_bypbuf_dwt_en_END (6)
#define SOC_SC_BASE_CTRL0_bypbuf_dwt_en_cpu_START (7)
#define SOC_SC_BASE_CTRL0_bypbuf_dwt_en_cpu_END (7)
#define SOC_SC_BASE_CTRL0_addr_bcomp_sel_START (8)
#define SOC_SC_BASE_CTRL0_addr_bcomp_sel_END (8)
#define SOC_SC_BASE_CTRL0_excl_event_dis_START (9)
#define SOC_SC_BASE_CTRL0_excl_event_dis_END (9)
#define SOC_SC_BASE_CTRL0_hazard_64b_opt_dis_START (10)
#define SOC_SC_BASE_CTRL0_hazard_64b_opt_dis_END (10)
#define SOC_SC_BASE_CTRL0_sc_glb_bypass_en_START (11)
#define SOC_SC_BASE_CTRL0_sc_glb_bypass_en_END (11)
#define SOC_SC_BASE_CTRL0_sc_bypass_sel_START (12)
#define SOC_SC_BASE_CTRL0_sc_bypass_sel_END (12)
#define SOC_SC_BASE_CTRL0_parity_en_START (13)
#define SOC_SC_BASE_CTRL0_parity_en_END (13)
#define SOC_SC_BASE_CTRL0_chi_work_mode_START (14)
#define SOC_SC_BASE_CTRL0_chi_work_mode_END (14)
#define SOC_SC_BASE_CTRL0_poc_excl_event_dis_START (15)
#define SOC_SC_BASE_CTRL0_poc_excl_event_dis_END (15)
#define SOC_SC_BASE_CTRL0_stash_abandon_en_START (16)
#define SOC_SC_BASE_CTRL0_stash_abandon_en_END (16)
#define SOC_SC_BASE_CTRL0_bypipe_cmo_fecq_sel_START (17)
#define SOC_SC_BASE_CTRL0_bypipe_cmo_fecq_sel_END (17)
#define SOC_SC_BASE_CTRL0_cfg_no_vtm_fl_buf_byp_START (18)
#define SOC_SC_BASE_CTRL0_cfg_no_vtm_fl_buf_byp_END (18)
#define SOC_SC_BASE_CTRL0_stash_int_disable_START (19)
#define SOC_SC_BASE_CTRL0_stash_int_disable_END (19)
#define SOC_SC_BASE_CTRL0_pgid0_force_cmoen_START (20)
#define SOC_SC_BASE_CTRL0_pgid0_force_cmoen_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_rank_intlv_gran : 5;
        unsigned int reserved_0 : 3;
        unsigned int ddr_rank_intlv_gran1 : 5;
        unsigned int reserved_1 : 3;
        unsigned int ddr_wakeup_period : 9;
        unsigned int reserved_2 : 3;
        unsigned int rank_mode_sel : 2;
        unsigned int rank_map_mode : 1;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_SC_FST_WAKEUP_CTRL0_UNION;
#endif
#define SOC_SC_FST_WAKEUP_CTRL0_ddr_rank_intlv_gran_START (0)
#define SOC_SC_FST_WAKEUP_CTRL0_ddr_rank_intlv_gran_END (4)
#define SOC_SC_FST_WAKEUP_CTRL0_ddr_rank_intlv_gran1_START (8)
#define SOC_SC_FST_WAKEUP_CTRL0_ddr_rank_intlv_gran1_END (12)
#define SOC_SC_FST_WAKEUP_CTRL0_ddr_wakeup_period_START (16)
#define SOC_SC_FST_WAKEUP_CTRL0_ddr_wakeup_period_END (24)
#define SOC_SC_FST_WAKEUP_CTRL0_rank_mode_sel_START (28)
#define SOC_SC_FST_WAKEUP_CTRL0_rank_mode_sel_END (29)
#define SOC_SC_FST_WAKEUP_CTRL0_rank_map_mode_START (30)
#define SOC_SC_FST_WAKEUP_CTRL0_rank_map_mode_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr_rank_hole : 6;
        unsigned int reserved_0 : 2;
        unsigned int size_rank_hole : 6;
        unsigned int reserved_1 : 2;
        unsigned int wakeup_rank_en : 1;
        unsigned int wakeup_ch_en : 1;
        unsigned int reserved_2 : 14;
    } reg;
} SOC_SC_FST_WAKEUP_CTRL1_UNION;
#endif
#define SOC_SC_FST_WAKEUP_CTRL1_addr_rank_hole_START (0)
#define SOC_SC_FST_WAKEUP_CTRL1_addr_rank_hole_END (5)
#define SOC_SC_FST_WAKEUP_CTRL1_size_rank_hole_START (8)
#define SOC_SC_FST_WAKEUP_CTRL1_size_rank_hole_END (13)
#define SOC_SC_FST_WAKEUP_CTRL1_wakeup_rank_en_START (16)
#define SOC_SC_FST_WAKEUP_CTRL1_wakeup_rank_en_END (16)
#define SOC_SC_FST_WAKEUP_CTRL1_wakeup_ch_en_START (17)
#define SOC_SC_FST_WAKEUP_CTRL1_wakeup_ch_en_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_rank_map : 32;
    } reg;
} SOC_SC_FST_WAKEUP_CTRL2_UNION;
#endif
#define SOC_SC_FST_WAKEUP_CTRL2_ddr_rank_map_START (0)
#define SOC_SC_FST_WAKEUP_CTRL2_ddr_rank_map_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_rank_map1 : 32;
    } reg;
} SOC_SC_FST_WAKEUP_CTRL3_UNION;
#endif
#define SOC_SC_FST_WAKEUP_CTRL3_ddr_rank_map1_START (0)
#define SOC_SC_FST_WAKEUP_CTRL3_ddr_rank_map1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wakeup_en : 1;
        unsigned int wakeup_chislv_en : 1;
        unsigned int wakeup_byp_en : 1;
        unsigned int wakeup_tpipe_en : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_SC_FST_WAKEUP_CTRL4_UNION;
#endif
#define SOC_SC_FST_WAKEUP_CTRL4_wakeup_en_START (0)
#define SOC_SC_FST_WAKEUP_CTRL4_wakeup_en_END (0)
#define SOC_SC_FST_WAKEUP_CTRL4_wakeup_chislv_en_START (1)
#define SOC_SC_FST_WAKEUP_CTRL4_wakeup_chislv_en_END (1)
#define SOC_SC_FST_WAKEUP_CTRL4_wakeup_byp_en_START (2)
#define SOC_SC_FST_WAKEUP_CTRL4_wakeup_byp_en_END (2)
#define SOC_SC_FST_WAKEUP_CTRL4_wakeup_tpipe_en_START (3)
#define SOC_SC_FST_WAKEUP_CTRL4_wakeup_tpipe_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sf_alloc_way_byp : 12;
        unsigned int scc_mode_bypass : 1;
        unsigned int smq_mig_dis : 1;
        unsigned int smq_flush_tmo_en : 1;
        unsigned int hc_silent_drop_cnt_en : 1;
        unsigned int sf_alloc_way_en : 12;
        unsigned int reserved : 4;
    } reg;
} SOC_SC_SMQ_CTRL_UNION;
#endif
#define SOC_SC_SMQ_CTRL_sf_alloc_way_byp_START (0)
#define SOC_SC_SMQ_CTRL_sf_alloc_way_byp_END (11)
#define SOC_SC_SMQ_CTRL_scc_mode_bypass_START (12)
#define SOC_SC_SMQ_CTRL_scc_mode_bypass_END (12)
#define SOC_SC_SMQ_CTRL_smq_mig_dis_START (13)
#define SOC_SC_SMQ_CTRL_smq_mig_dis_END (13)
#define SOC_SC_SMQ_CTRL_smq_flush_tmo_en_START (14)
#define SOC_SC_SMQ_CTRL_smq_flush_tmo_en_END (14)
#define SOC_SC_SMQ_CTRL_hc_silent_drop_cnt_en_START (15)
#define SOC_SC_SMQ_CTRL_hc_silent_drop_cnt_en_END (15)
#define SOC_SC_SMQ_CTRL_sf_alloc_way_en_START (16)
#define SOC_SC_SMQ_CTRL_sf_alloc_way_en_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int glb_way_en : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_GLB_WAY_EN_UNION;
#endif
#define SOC_SC_GLB_WAY_EN_glb_way_en_START (0)
#define SOC_SC_GLB_WAY_EN_glb_way_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_syncbuf_used_way : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_SYNCBUF_USED_WAY_UNION;
#endif
#define SOC_SC_SYNCBUF_USED_WAY_cfg_syncbuf_used_way_START (0)
#define SOC_SC_SYNCBUF_USED_WAY_cfg_syncbuf_used_way_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tag_glb_way_search : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_TAG_GLB_WAY_SEARCH_UNION;
#endif
#define SOC_SC_TAG_GLB_WAY_SEARCH_tag_glb_way_search_START (0)
#define SOC_SC_TAG_GLB_WAY_SEARCH_tag_glb_way_search_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sf_glb_way_search : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_SC_SF_GLB_WAY_SEARCH_UNION;
#endif
#define SOC_SC_SF_GLB_WAY_SEARCH_sf_glb_way_search_START (0)
#define SOC_SC_SF_GLB_WAY_SEARCH_sf_glb_way_search_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int biq_nesting_max : 5;
        unsigned int reserved_0 : 3;
        unsigned int invld_cmo_override : 2;
        unsigned int tpipe_dmem_spec_en : 1;
        unsigned int dmem_tpipe_rd_en : 1;
        unsigned int sn_ely_rd_en : 1;
        unsigned int sn_tpipe_rd_en : 1;
        unsigned int vacmo_cgid_unmatch_rpt_mask : 1;
        unsigned int tpipe_arb_req_ext_cpu : 1;
        unsigned int ecc_flush_cnt_max : 6;
        unsigned int tpipe_ely_nodmt_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int pipe_cpu_dmt_en : 1;
        unsigned int pipe_qtpe_dmt_en : 1;
        unsigned int tpipe_read_seprsp_en : 1;
        unsigned int reserved_2 : 5;
    } reg;
} SOC_SC_TPIPE_CTRL0_UNION;
#endif
#define SOC_SC_TPIPE_CTRL0_biq_nesting_max_START (0)
#define SOC_SC_TPIPE_CTRL0_biq_nesting_max_END (4)
#define SOC_SC_TPIPE_CTRL0_invld_cmo_override_START (8)
#define SOC_SC_TPIPE_CTRL0_invld_cmo_override_END (9)
#define SOC_SC_TPIPE_CTRL0_tpipe_dmem_spec_en_START (10)
#define SOC_SC_TPIPE_CTRL0_tpipe_dmem_spec_en_END (10)
#define SOC_SC_TPIPE_CTRL0_dmem_tpipe_rd_en_START (11)
#define SOC_SC_TPIPE_CTRL0_dmem_tpipe_rd_en_END (11)
#define SOC_SC_TPIPE_CTRL0_sn_ely_rd_en_START (12)
#define SOC_SC_TPIPE_CTRL0_sn_ely_rd_en_END (12)
#define SOC_SC_TPIPE_CTRL0_sn_tpipe_rd_en_START (13)
#define SOC_SC_TPIPE_CTRL0_sn_tpipe_rd_en_END (13)
#define SOC_SC_TPIPE_CTRL0_vacmo_cgid_unmatch_rpt_mask_START (14)
#define SOC_SC_TPIPE_CTRL0_vacmo_cgid_unmatch_rpt_mask_END (14)
#define SOC_SC_TPIPE_CTRL0_tpipe_arb_req_ext_cpu_START (15)
#define SOC_SC_TPIPE_CTRL0_tpipe_arb_req_ext_cpu_END (15)
#define SOC_SC_TPIPE_CTRL0_ecc_flush_cnt_max_START (16)
#define SOC_SC_TPIPE_CTRL0_ecc_flush_cnt_max_END (21)
#define SOC_SC_TPIPE_CTRL0_tpipe_ely_nodmt_en_START (22)
#define SOC_SC_TPIPE_CTRL0_tpipe_ely_nodmt_en_END (22)
#define SOC_SC_TPIPE_CTRL0_pipe_cpu_dmt_en_START (24)
#define SOC_SC_TPIPE_CTRL0_pipe_cpu_dmt_en_END (24)
#define SOC_SC_TPIPE_CTRL0_pipe_qtpe_dmt_en_START (25)
#define SOC_SC_TPIPE_CTRL0_pipe_qtpe_dmt_en_END (25)
#define SOC_SC_TPIPE_CTRL0_tpipe_read_seprsp_en_START (26)
#define SOC_SC_TPIPE_CTRL0_tpipe_read_seprsp_en_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spec_rd_id_en : 32;
    } reg;
} SOC_SC_TPIPE_CTRL1_UNION;
#endif
#define SOC_SC_TPIPE_CTRL1_spec_rd_id_en_START (0)
#define SOC_SC_TPIPE_CTRL1_spec_rd_id_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int write_wait_wdata : 1;
        unsigned int vic_policy_sel : 1;
        unsigned int cpbk_as_dfm : 1;
        unsigned int read_seprsp_en : 1;
        unsigned int alloc_cancel_en : 1;
        unsigned int dmem_spec_wr_en : 1;
        unsigned int spec_sf_hit_fail : 1;
        unsigned int snoop_latency_opt_dis : 1;
        unsigned int excl_uns_sel : 3;
        unsigned int reserved_0 : 1;
        unsigned int becq_addr_rel_th : 8;
        unsigned int dmem_to_fecq_dis : 1;
        unsigned int mstif_to_fecq_dis : 1;
        unsigned int reserved_1 : 10;
    } reg;
} SOC_SC_BECQ_CTRL0_UNION;
#endif
#define SOC_SC_BECQ_CTRL0_write_wait_wdata_START (0)
#define SOC_SC_BECQ_CTRL0_write_wait_wdata_END (0)
#define SOC_SC_BECQ_CTRL0_vic_policy_sel_START (1)
#define SOC_SC_BECQ_CTRL0_vic_policy_sel_END (1)
#define SOC_SC_BECQ_CTRL0_cpbk_as_dfm_START (2)
#define SOC_SC_BECQ_CTRL0_cpbk_as_dfm_END (2)
#define SOC_SC_BECQ_CTRL0_read_seprsp_en_START (3)
#define SOC_SC_BECQ_CTRL0_read_seprsp_en_END (3)
#define SOC_SC_BECQ_CTRL0_alloc_cancel_en_START (4)
#define SOC_SC_BECQ_CTRL0_alloc_cancel_en_END (4)
#define SOC_SC_BECQ_CTRL0_dmem_spec_wr_en_START (5)
#define SOC_SC_BECQ_CTRL0_dmem_spec_wr_en_END (5)
#define SOC_SC_BECQ_CTRL0_spec_sf_hit_fail_START (6)
#define SOC_SC_BECQ_CTRL0_spec_sf_hit_fail_END (6)
#define SOC_SC_BECQ_CTRL0_snoop_latency_opt_dis_START (7)
#define SOC_SC_BECQ_CTRL0_snoop_latency_opt_dis_END (7)
#define SOC_SC_BECQ_CTRL0_excl_uns_sel_START (8)
#define SOC_SC_BECQ_CTRL0_excl_uns_sel_END (10)
#define SOC_SC_BECQ_CTRL0_becq_addr_rel_th_START (12)
#define SOC_SC_BECQ_CTRL0_becq_addr_rel_th_END (19)
#define SOC_SC_BECQ_CTRL0_dmem_to_fecq_dis_START (20)
#define SOC_SC_BECQ_CTRL0_dmem_to_fecq_dis_END (20)
#define SOC_SC_BECQ_CTRL0_mstif_to_fecq_dis_START (21)
#define SOC_SC_BECQ_CTRL0_mstif_to_fecq_dis_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int becq_dmem_way_busy : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_BECQ_STATUS0_UNION;
#endif
#define SOC_SC_BECQ_STATUS0_becq_dmem_way_busy_START (0)
#define SOC_SC_BECQ_STATUS0_becq_dmem_way_busy_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int specrd_switch : 31;
        unsigned int specrd_switch_bypass : 1;
    } reg;
} SOC_SC_SPEC_RD_SWITCH_CTRL0_UNION;
#endif
#define SOC_SC_SPEC_RD_SWITCH_CTRL0_specrd_switch_START (0)
#define SOC_SC_SPEC_RD_SWITCH_CTRL0_specrd_switch_END (30)
#define SOC_SC_SPEC_RD_SWITCH_CTRL0_specrd_switch_bypass_START (31)
#define SOC_SC_SPEC_RD_SWITCH_CTRL0_specrd_switch_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bedb_fecq_byp_dis : 1;
        unsigned int bedb_dmem_byp_dis : 1;
        unsigned int bedb_mst_byp_dis : 1;
        unsigned int bedb_wr2mem_byp_dis : 1;
        unsigned int bedb_arb_update_sel : 1;
        unsigned int bedb_rcverr_rpt_en : 1;
        unsigned int bedb_unexpt_flit_dis : 1;
        unsigned int reserved_0 : 1;
        unsigned int bedb_dat_err_dis : 1;
        unsigned int bedb_ndat_err_dis : 1;
        unsigned int reserved_1 : 2;
        unsigned int bedb_slot_sel : 6;
        unsigned int reserved_2 : 2;
        unsigned int fedb_chi_lw_type : 2;
        unsigned int fedb_byp_dis : 1;
        unsigned int fedb_dat_err_dis : 1;
        unsigned int fedb_ndat_err_dis : 1;
        unsigned int fedb_rcverr_rpt_en : 1;
        unsigned int reserved_3 : 6;
    } reg;
} SOC_SC_FEDB_BEDB_CTRL0_UNION;
#endif
#define SOC_SC_FEDB_BEDB_CTRL0_bedb_fecq_byp_dis_START (0)
#define SOC_SC_FEDB_BEDB_CTRL0_bedb_fecq_byp_dis_END (0)
#define SOC_SC_FEDB_BEDB_CTRL0_bedb_dmem_byp_dis_START (1)
#define SOC_SC_FEDB_BEDB_CTRL0_bedb_dmem_byp_dis_END (1)
#define SOC_SC_FEDB_BEDB_CTRL0_bedb_mst_byp_dis_START (2)
#define SOC_SC_FEDB_BEDB_CTRL0_bedb_mst_byp_dis_END (2)
#define SOC_SC_FEDB_BEDB_CTRL0_bedb_wr2mem_byp_dis_START (3)
#define SOC_SC_FEDB_BEDB_CTRL0_bedb_wr2mem_byp_dis_END (3)
#define SOC_SC_FEDB_BEDB_CTRL0_bedb_arb_update_sel_START (4)
#define SOC_SC_FEDB_BEDB_CTRL0_bedb_arb_update_sel_END (4)
#define SOC_SC_FEDB_BEDB_CTRL0_bedb_rcverr_rpt_en_START (5)
#define SOC_SC_FEDB_BEDB_CTRL0_bedb_rcverr_rpt_en_END (5)
#define SOC_SC_FEDB_BEDB_CTRL0_bedb_unexpt_flit_dis_START (6)
#define SOC_SC_FEDB_BEDB_CTRL0_bedb_unexpt_flit_dis_END (6)
#define SOC_SC_FEDB_BEDB_CTRL0_bedb_dat_err_dis_START (8)
#define SOC_SC_FEDB_BEDB_CTRL0_bedb_dat_err_dis_END (8)
#define SOC_SC_FEDB_BEDB_CTRL0_bedb_ndat_err_dis_START (9)
#define SOC_SC_FEDB_BEDB_CTRL0_bedb_ndat_err_dis_END (9)
#define SOC_SC_FEDB_BEDB_CTRL0_bedb_slot_sel_START (12)
#define SOC_SC_FEDB_BEDB_CTRL0_bedb_slot_sel_END (17)
#define SOC_SC_FEDB_BEDB_CTRL0_fedb_chi_lw_type_START (20)
#define SOC_SC_FEDB_BEDB_CTRL0_fedb_chi_lw_type_END (21)
#define SOC_SC_FEDB_BEDB_CTRL0_fedb_byp_dis_START (22)
#define SOC_SC_FEDB_BEDB_CTRL0_fedb_byp_dis_END (22)
#define SOC_SC_FEDB_BEDB_CTRL0_fedb_dat_err_dis_START (23)
#define SOC_SC_FEDB_BEDB_CTRL0_fedb_dat_err_dis_END (23)
#define SOC_SC_FEDB_BEDB_CTRL0_fedb_ndat_err_dis_START (24)
#define SOC_SC_FEDB_BEDB_CTRL0_fedb_ndat_err_dis_END (24)
#define SOC_SC_FEDB_BEDB_CTRL0_fedb_rcverr_rpt_en_START (25)
#define SOC_SC_FEDB_BEDB_CTRL0_fedb_rcverr_rpt_en_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fedb_buf_slot_mask : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_FEDB_BEDB_CTRL1_UNION;
#endif
#define SOC_SC_FEDB_BEDB_CTRL1_fedb_buf_slot_mask_START (0)
#define SOC_SC_FEDB_BEDB_CTRL1_fedb_buf_slot_mask_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmem_multicycle : 2;
        unsigned int dmem_opt : 1;
        unsigned int reserved_0 : 5;
        unsigned int mstif_full_turnover_dis : 1;
        unsigned int mstif_full_turnover_opt_en : 1;
        unsigned int reserved_1 : 22;
    } reg;
} SOC_SC_DMEM_MSTINTF_CFG0_UNION;
#endif
#define SOC_SC_DMEM_MSTINTF_CFG0_dmem_multicycle_START (0)
#define SOC_SC_DMEM_MSTINTF_CFG0_dmem_multicycle_END (1)
#define SOC_SC_DMEM_MSTINTF_CFG0_dmem_opt_START (2)
#define SOC_SC_DMEM_MSTINTF_CFG0_dmem_opt_END (2)
#define SOC_SC_DMEM_MSTINTF_CFG0_mstif_full_turnover_dis_START (8)
#define SOC_SC_DMEM_MSTINTF_CFG0_mstif_full_turnover_dis_END (8)
#define SOC_SC_DMEM_MSTINTF_CFG0_mstif_full_turnover_opt_en_START (9)
#define SOC_SC_DMEM_MSTINTF_CFG0_mstif_full_turnover_opt_en_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int drrip_initial_age0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int drrip_initial_age1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int stash_age : 3;
        unsigned int reserved_2 : 1;
        unsigned int sdm_pcnt_mode : 1;
        unsigned int reserved_3 : 19;
    } reg;
} SOC_SC_VICPIPE_CTRL0_UNION;
#endif
#define SOC_SC_VICPIPE_CTRL0_drrip_initial_age0_START (0)
#define SOC_SC_VICPIPE_CTRL0_drrip_initial_age0_END (2)
#define SOC_SC_VICPIPE_CTRL0_drrip_initial_age1_START (4)
#define SOC_SC_VICPIPE_CTRL0_drrip_initial_age1_END (6)
#define SOC_SC_VICPIPE_CTRL0_stash_age_START (8)
#define SOC_SC_VICPIPE_CTRL0_stash_age_END (10)
#define SOC_SC_VICPIPE_CTRL0_sdm_pcnt_mode_START (12)
#define SOC_SC_VICPIPE_CTRL0_sdm_pcnt_mode_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fecq_ckg_byp : 1;
        unsigned int reserved_0 : 1;
        unsigned int fedb_ckg_byp : 1;
        unsigned int fedb_ckg_rs_byp : 1;
        unsigned int bedb_ckg_byp : 1;
        unsigned int bedb_slot_ckg_byp : 1;
        unsigned int bedb_bank_ckg_byp : 1;
        unsigned int bedb_mrgbuf_ckg_byp : 1;
        unsigned int bedb_rs_ckg_byp : 1;
        unsigned int tpipe_ckg_byp : 1;
        unsigned int biq_ckg_byp : 1;
        unsigned int vicram_ckg_byp : 1;
        unsigned int vpipe_ckg_byp : 1;
        unsigned int tlpc_ckg_byp : 1;
        unsigned int slpc_ckg_byp : 1;
        unsigned int dlpc_ckg_byp : 1;
        unsigned int mstif_ckg_byp : 1;
        unsigned int dmemif_ckg_byp : 1;
        unsigned int cmoq_ckg_byp : 1;
        unsigned int dmem_ckg_byp : 1;
        unsigned int bypbuf_ckg_byp : 1;
        unsigned int spipe_ckg_byp : 1;
        unsigned int cfg_ckg_byp : 1;
        unsigned int sc_lpc_ckg_byp : 1;
        unsigned int bypbuf_fifo_ckg_en : 1;
        unsigned int sdm_ckg_byp : 1;
        unsigned int dfx_ckg_byp : 1;
        unsigned int reserved_1 : 1;
        unsigned int cfc_ckg_byp : 1;
        unsigned int sc_slice_ckg_byp : 1;
        unsigned int smq_ckg_byp : 1;
        unsigned int sc_ckg_ext_en : 1;
    } reg;
} SOC_SC_CKG_CTRL0_UNION;
#endif
#define SOC_SC_CKG_CTRL0_fecq_ckg_byp_START (0)
#define SOC_SC_CKG_CTRL0_fecq_ckg_byp_END (0)
#define SOC_SC_CKG_CTRL0_fedb_ckg_byp_START (2)
#define SOC_SC_CKG_CTRL0_fedb_ckg_byp_END (2)
#define SOC_SC_CKG_CTRL0_fedb_ckg_rs_byp_START (3)
#define SOC_SC_CKG_CTRL0_fedb_ckg_rs_byp_END (3)
#define SOC_SC_CKG_CTRL0_bedb_ckg_byp_START (4)
#define SOC_SC_CKG_CTRL0_bedb_ckg_byp_END (4)
#define SOC_SC_CKG_CTRL0_bedb_slot_ckg_byp_START (5)
#define SOC_SC_CKG_CTRL0_bedb_slot_ckg_byp_END (5)
#define SOC_SC_CKG_CTRL0_bedb_bank_ckg_byp_START (6)
#define SOC_SC_CKG_CTRL0_bedb_bank_ckg_byp_END (6)
#define SOC_SC_CKG_CTRL0_bedb_mrgbuf_ckg_byp_START (7)
#define SOC_SC_CKG_CTRL0_bedb_mrgbuf_ckg_byp_END (7)
#define SOC_SC_CKG_CTRL0_bedb_rs_ckg_byp_START (8)
#define SOC_SC_CKG_CTRL0_bedb_rs_ckg_byp_END (8)
#define SOC_SC_CKG_CTRL0_tpipe_ckg_byp_START (9)
#define SOC_SC_CKG_CTRL0_tpipe_ckg_byp_END (9)
#define SOC_SC_CKG_CTRL0_biq_ckg_byp_START (10)
#define SOC_SC_CKG_CTRL0_biq_ckg_byp_END (10)
#define SOC_SC_CKG_CTRL0_vicram_ckg_byp_START (11)
#define SOC_SC_CKG_CTRL0_vicram_ckg_byp_END (11)
#define SOC_SC_CKG_CTRL0_vpipe_ckg_byp_START (12)
#define SOC_SC_CKG_CTRL0_vpipe_ckg_byp_END (12)
#define SOC_SC_CKG_CTRL0_tlpc_ckg_byp_START (13)
#define SOC_SC_CKG_CTRL0_tlpc_ckg_byp_END (13)
#define SOC_SC_CKG_CTRL0_slpc_ckg_byp_START (14)
#define SOC_SC_CKG_CTRL0_slpc_ckg_byp_END (14)
#define SOC_SC_CKG_CTRL0_dlpc_ckg_byp_START (15)
#define SOC_SC_CKG_CTRL0_dlpc_ckg_byp_END (15)
#define SOC_SC_CKG_CTRL0_mstif_ckg_byp_START (16)
#define SOC_SC_CKG_CTRL0_mstif_ckg_byp_END (16)
#define SOC_SC_CKG_CTRL0_dmemif_ckg_byp_START (17)
#define SOC_SC_CKG_CTRL0_dmemif_ckg_byp_END (17)
#define SOC_SC_CKG_CTRL0_cmoq_ckg_byp_START (18)
#define SOC_SC_CKG_CTRL0_cmoq_ckg_byp_END (18)
#define SOC_SC_CKG_CTRL0_dmem_ckg_byp_START (19)
#define SOC_SC_CKG_CTRL0_dmem_ckg_byp_END (19)
#define SOC_SC_CKG_CTRL0_bypbuf_ckg_byp_START (20)
#define SOC_SC_CKG_CTRL0_bypbuf_ckg_byp_END (20)
#define SOC_SC_CKG_CTRL0_spipe_ckg_byp_START (21)
#define SOC_SC_CKG_CTRL0_spipe_ckg_byp_END (21)
#define SOC_SC_CKG_CTRL0_cfg_ckg_byp_START (22)
#define SOC_SC_CKG_CTRL0_cfg_ckg_byp_END (22)
#define SOC_SC_CKG_CTRL0_sc_lpc_ckg_byp_START (23)
#define SOC_SC_CKG_CTRL0_sc_lpc_ckg_byp_END (23)
#define SOC_SC_CKG_CTRL0_bypbuf_fifo_ckg_en_START (24)
#define SOC_SC_CKG_CTRL0_bypbuf_fifo_ckg_en_END (24)
#define SOC_SC_CKG_CTRL0_sdm_ckg_byp_START (25)
#define SOC_SC_CKG_CTRL0_sdm_ckg_byp_END (25)
#define SOC_SC_CKG_CTRL0_dfx_ckg_byp_START (26)
#define SOC_SC_CKG_CTRL0_dfx_ckg_byp_END (26)
#define SOC_SC_CKG_CTRL0_cfc_ckg_byp_START (28)
#define SOC_SC_CKG_CTRL0_cfc_ckg_byp_END (28)
#define SOC_SC_CKG_CTRL0_sc_slice_ckg_byp_START (29)
#define SOC_SC_CKG_CTRL0_sc_slice_ckg_byp_END (29)
#define SOC_SC_CKG_CTRL0_smq_ckg_byp_START (30)
#define SOC_SC_CKG_CTRL0_smq_ckg_byp_END (30)
#define SOC_SC_CKG_CTRL0_sc_ckg_ext_en_START (31)
#define SOC_SC_CKG_CTRL0_sc_ckg_ext_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int statis_ckg_byp : 3;
        unsigned int fstwakeup_ckg_byp : 1;
        unsigned int becq_ckg_byp : 3;
        unsigned int reserved : 21;
        unsigned int sc_becq_slot_ckg_ext : 1;
        unsigned int sc_becq_wrap_ckg_ext : 3;
    } reg;
} SOC_SC_CKG_CTRL1_UNION;
#endif
#define SOC_SC_CKG_CTRL1_statis_ckg_byp_START (0)
#define SOC_SC_CKG_CTRL1_statis_ckg_byp_END (2)
#define SOC_SC_CKG_CTRL1_fstwakeup_ckg_byp_START (3)
#define SOC_SC_CKG_CTRL1_fstwakeup_ckg_byp_END (3)
#define SOC_SC_CKG_CTRL1_becq_ckg_byp_START (4)
#define SOC_SC_CKG_CTRL1_becq_ckg_byp_END (6)
#define SOC_SC_CKG_CTRL1_sc_becq_slot_ckg_ext_START (28)
#define SOC_SC_CKG_CTRL1_sc_becq_slot_ckg_ext_END (28)
#define SOC_SC_CKG_CTRL1_sc_becq_wrap_ckg_ext_START (29)
#define SOC_SC_CKG_CTRL1_sc_becq_wrap_ckg_ext_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gid_tz_secure : 32;
    } reg;
} SOC_SC_CFG_GID_SEC_CTRL_UNION;
#endif
#define SOC_SC_CFG_GID_SEC_CTRL_gid_tz_secure_START (0)
#define SOC_SC_CFG_GID_SEC_CTRL_gid_tz_secure_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gid_tz_secure1 : 32;
    } reg;
} SOC_SC_CFG_GID_SEC_CTRL1_UNION;
#endif
#define SOC_SC_CFG_GID_SEC_CTRL1_gid_tz_secure1_START (0)
#define SOC_SC_CFG_GID_SEC_CTRL1_gid_tz_secure1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cgid_tz_secure : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_CFG_CGID_SEC_CTRL_UNION;
#endif
#define SOC_SC_CFG_CGID_SEC_CTRL_cgid_tz_secure_START (0)
#define SOC_SC_CFG_CGID_SEC_CTRL_cgid_tz_secure_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_lock_sec_rgn_common : 1;
        unsigned int sc_lock_mpu : 1;
        unsigned int sc_lock_intlv : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_SC_SEC_BOOT_LOCK_CTRL0_UNION;
#endif
#define SOC_SC_SEC_BOOT_LOCK_CTRL0_sc_lock_sec_rgn_common_START (0)
#define SOC_SC_SEC_BOOT_LOCK_CTRL0_sc_lock_sec_rgn_common_END (0)
#define SOC_SC_SEC_BOOT_LOCK_CTRL0_sc_lock_mpu_START (1)
#define SOC_SC_SEC_BOOT_LOCK_CTRL0_sc_lock_mpu_END (1)
#define SOC_SC_SEC_BOOT_LOCK_CTRL0_sc_lock_intlv_START (2)
#define SOC_SC_SEC_BOOT_LOCK_CTRL0_sc_lock_intlv_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_lock_sec_rgn_split : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SC_SEC_BOOT_LOCK_CTRL1_UNION;
#endif
#define SOC_SC_SEC_BOOT_LOCK_CTRL1_sc_lock_sec_rgn_split_START (0)
#define SOC_SC_SEC_BOOT_LOCK_CTRL1_sc_lock_sec_rgn_split_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int status_sc_lock_sec_rgn_common : 1;
        unsigned int status_sc_lock_mpu : 1;
        unsigned int status_sc_lock_intlv : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_SC_SEC_BOOT_LOCK_STATUS0_UNION;
#endif
#define SOC_SC_SEC_BOOT_LOCK_STATUS0_status_sc_lock_sec_rgn_common_START (0)
#define SOC_SC_SEC_BOOT_LOCK_STATUS0_status_sc_lock_sec_rgn_common_END (0)
#define SOC_SC_SEC_BOOT_LOCK_STATUS0_status_sc_lock_mpu_START (1)
#define SOC_SC_SEC_BOOT_LOCK_STATUS0_status_sc_lock_mpu_END (1)
#define SOC_SC_SEC_BOOT_LOCK_STATUS0_status_sc_lock_intlv_START (2)
#define SOC_SC_SEC_BOOT_LOCK_STATUS0_status_sc_lock_intlv_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int status_sc_lock_sec_rgn_split : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SC_SEC_BOOT_LOCK_STATUS1_UNION;
#endif
#define SOC_SC_SEC_BOOT_LOCK_STATUS1_status_sc_lock_sec_rgn_split_START (0)
#define SOC_SC_SEC_BOOT_LOCK_STATUS1_status_sc_lock_sec_rgn_split_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ebit_overwrite_en : 1;
        unsigned int secc_fail_resperr_dis : 1;
        unsigned int dmem_ecc_byp : 1;
        unsigned int dmemif_resperr_ok_en : 1;
        unsigned int sw_trig_int_en : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_SC_SEC_USER_CTRL0_UNION;
#endif
#define SOC_SC_SEC_USER_CTRL0_ebit_overwrite_en_START (0)
#define SOC_SC_SEC_USER_CTRL0_ebit_overwrite_en_END (0)
#define SOC_SC_SEC_USER_CTRL0_secc_fail_resperr_dis_START (1)
#define SOC_SC_SEC_USER_CTRL0_secc_fail_resperr_dis_END (1)
#define SOC_SC_SEC_USER_CTRL0_dmem_ecc_byp_START (2)
#define SOC_SC_SEC_USER_CTRL0_dmem_ecc_byp_END (2)
#define SOC_SC_SEC_USER_CTRL0_dmemif_resperr_ok_en_START (3)
#define SOC_SC_SEC_USER_CTRL0_dmemif_resperr_ok_en_END (3)
#define SOC_SC_SEC_USER_CTRL0_sw_trig_int_en_START (4)
#define SOC_SC_SEC_USER_CTRL0_sw_trig_int_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pgid_drop_en0 : 32;
    } reg;
} SOC_SC_CFG_PGID_DROP_EN0_UNION;
#endif
#define SOC_SC_CFG_PGID_DROP_EN0_pgid_drop_en0_START (0)
#define SOC_SC_CFG_PGID_DROP_EN0_pgid_drop_en0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pgid_drop_en1 : 32;
    } reg;
} SOC_SC_CFG_PGID_DROP_EN1_UNION;
#endif
#define SOC_SC_CFG_PGID_DROP_EN1_pgid_drop_en1_START (0)
#define SOC_SC_CFG_PGID_DROP_EN1_pgid_drop_en1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trust_degrade : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SC_SCC_SEC_CTRL_UNION;
#endif
#define SOC_SC_SCC_SEC_CTRL_trust_degrade_START (0)
#define SOC_SC_SCC_SEC_CTRL_trust_degrade_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_mid : 8;
        unsigned int cfg_mid_mask : 8;
        unsigned int pgid_allow_start : 6;
        unsigned int reserved_0 : 2;
        unsigned int pgid_allow_end : 6;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_SC_CFG_MID_CTRL_UNION;
#endif
#define SOC_SC_CFG_MID_CTRL_cfg_mid_START (0)
#define SOC_SC_CFG_MID_CTRL_cfg_mid_END (7)
#define SOC_SC_CFG_MID_CTRL_cfg_mid_mask_START (8)
#define SOC_SC_CFG_MID_CTRL_cfg_mid_mask_END (15)
#define SOC_SC_CFG_MID_CTRL_pgid_allow_start_START (16)
#define SOC_SC_CFG_MID_CTRL_pgid_allow_start_END (21)
#define SOC_SC_CFG_MID_CTRL_pgid_allow_end_START (24)
#define SOC_SC_CFG_MID_CTRL_pgid_allow_end_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_trust_wr_ntrust_en : 32;
    } reg;
} SOC_SC_MID_TRUST_WR_NSTRUST_UNION;
#endif
#define SOC_SC_MID_TRUST_WR_NSTRUST_mid_trust_wr_ntrust_en_START (0)
#define SOC_SC_MID_TRUST_WR_NSTRUST_mid_trust_wr_ntrust_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trusted_wen : 1;
        unsigned int protected_wen : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_SC_DRC_SEC_CTRL_UNION;
#endif
#define SOC_SC_DRC_SEC_CTRL_trusted_wen_START (0)
#define SOC_SC_DRC_SEC_CTRL_trusted_wen_END (0)
#define SOC_SC_DRC_SEC_CTRL_protected_wen_START (1)
#define SOC_SC_DRC_SEC_CTRL_protected_wen_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dummy_reg_2 : 32;
    } reg;
} SOC_SC_DUMMY_REG2_UNION;
#endif
#define SOC_SC_DUMMY_REG2_dummy_reg_2_START (0)
#define SOC_SC_DUMMY_REG2_dummy_reg_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_glb_mask_abnml_s : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SC_ABNML_INT_S_GLB_MASK_UNION;
#endif
#define SOC_SC_ABNML_INT_S_GLB_MASK_int_glb_mask_abnml_s_START (0)
#define SOC_SC_ABNML_INT_S_GLB_MASK_int_glb_mask_abnml_s_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_clr_abnml_s : 1;
        unsigned int sw_trig_int_abnml_s : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_SC_ABNML_INT_S_CLR_UNION;
#endif
#define SOC_SC_ABNML_INT_S_CLR_int_clr_abnml_s_START (0)
#define SOC_SC_ABNML_INT_S_CLR_int_clr_abnml_s_END (0)
#define SOC_SC_ABNML_INT_S_CLR_sw_trig_int_abnml_s_START (1)
#define SOC_SC_ABNML_INT_S_CLR_sw_trig_int_abnml_s_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_mask_abnml_s : 32;
    } reg;
} SOC_SC_ABNML_INT_S_MASK_UNION;
#endif
#define SOC_SC_ABNML_INT_S_MASK_int_mask_abnml_s_START (0)
#define SOC_SC_ABNML_INT_S_MASK_int_mask_abnml_s_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_dis_abnml_s : 32;
    } reg;
} SOC_SC_ABNML_INT_S_DIS_UNION;
#endif
#define SOC_SC_ABNML_INT_S_DIS_int_dis_abnml_s_START (0)
#define SOC_SC_ABNML_INT_S_DIS_int_dis_abnml_s_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_org_status_abnml_s : 32;
    } reg;
} SOC_SC_ABNML_INT_S_ORG_STATUS_UNION;
#endif
#define SOC_SC_ABNML_INT_S_ORG_STATUS_int_org_status_abnml_s_START (0)
#define SOC_SC_ABNML_INT_S_ORG_STATUS_int_org_status_abnml_s_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_mask_status_abnml_s : 32;
    } reg;
} SOC_SC_ABNML_INT_S_MASK_STATUS_UNION;
#endif
#define SOC_SC_ABNML_INT_S_MASK_STATUS_int_mask_status_abnml_s_START (0)
#define SOC_SC_ABNML_INT_S_MASK_STATUS_int_mask_status_abnml_s_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_type_abnml_s : 6;
        unsigned int reserved_0 : 2;
        unsigned int sw_trig_int_type_abnml_s : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_SC_ABNML_INT_S_TYPE_UNION;
#endif
#define SOC_SC_ABNML_INT_S_TYPE_int_type_abnml_s_START (0)
#define SOC_SC_ABNML_INT_S_TYPE_int_type_abnml_s_END (5)
#define SOC_SC_ABNML_INT_S_TYPE_sw_trig_int_type_abnml_s_START (8)
#define SOC_SC_ABNML_INT_S_TYPE_sw_trig_int_type_abnml_s_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_info_abnml_s : 32;
    } reg;
} SOC_SC_ABNML_INT_S_INFO_UNION;
#endif
#define SOC_SC_ABNML_INT_S_INFO_int_info_abnml_s_START (0)
#define SOC_SC_ABNML_INT_S_INFO_int_info_abnml_s_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_glb_mask_parity : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SC_PARITY_INT_GLB_MASK_UNION;
#endif
#define SOC_SC_PARITY_INT_GLB_MASK_int_glb_mask_parity_START (0)
#define SOC_SC_PARITY_INT_GLB_MASK_int_glb_mask_parity_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_clr_parity : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SC_PARITY_INT_CLR_UNION;
#endif
#define SOC_SC_PARITY_INT_CLR_int_clr_parity_START (0)
#define SOC_SC_PARITY_INT_CLR_int_clr_parity_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_mask_parity : 32;
    } reg;
} SOC_SC_PARITY_INT_MASK_UNION;
#endif
#define SOC_SC_PARITY_INT_MASK_int_mask_parity_START (0)
#define SOC_SC_PARITY_INT_MASK_int_mask_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_dis_parity : 32;
    } reg;
} SOC_SC_PARITY_INT_DIS_UNION;
#endif
#define SOC_SC_PARITY_INT_DIS_int_dis_parity_START (0)
#define SOC_SC_PARITY_INT_DIS_int_dis_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_org_status_parity : 32;
    } reg;
} SOC_SC_PARITY_INT_ORG_STATUS_UNION;
#endif
#define SOC_SC_PARITY_INT_ORG_STATUS_int_org_status_parity_START (0)
#define SOC_SC_PARITY_INT_ORG_STATUS_int_org_status_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_mask_status_parity : 32;
    } reg;
} SOC_SC_PARITY_INT_MASK_STATUS_UNION;
#endif
#define SOC_SC_PARITY_INT_MASK_STATUS_int_mask_status_parity_START (0)
#define SOC_SC_PARITY_INT_MASK_STATUS_int_mask_status_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_type_parity : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_SC_PARITY_INT_TYPE_UNION;
#endif
#define SOC_SC_PARITY_INT_TYPE_int_type_parity_START (0)
#define SOC_SC_PARITY_INT_TYPE_int_type_parity_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_info_parity : 32;
    } reg;
} SOC_SC_PARITY_INT_INFO_UNION;
#endif
#define SOC_SC_PARITY_INT_INFO_int_info_parity_START (0)
#define SOC_SC_PARITY_INT_INFO_int_info_parity_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_addr : 25;
        unsigned int reserved : 7;
    } reg;
} SOC_SC_DBG_PORT_IN0_UNION;
#endif
#define SOC_SC_DBG_PORT_IN0_dbg_cfg_addr_START (0)
#define SOC_SC_DBG_PORT_IN0_dbg_cfg_addr_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_rd : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SC_DBG_PORT_IN1_UNION;
#endif
#define SOC_SC_DBG_PORT_IN1_dbg_cfg_rd_START (0)
#define SOC_SC_DBG_PORT_IN1_dbg_cfg_rd_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_rdata_vld : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SC_DBG_PORT_IN2_UNION;
#endif
#define SOC_SC_DBG_PORT_IN2_dbg_cfg_rdata_vld_START (0)
#define SOC_SC_DBG_PORT_IN2_dbg_cfg_rdata_vld_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_rdata : 32;
    } reg;
} SOC_SC_DBG_PORT_OUT_UNION;
#endif
#define SOC_SC_DBG_PORT_OUT_dbg_cfg_rdata_START (0)
#define SOC_SC_DBG_PORT_OUT_dbg_cfg_rdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_idle_status0 : 32;
    } reg;
} SOC_SC_IDLE_STATUS0_UNION;
#endif
#define SOC_SC_IDLE_STATUS0_sc_idle_status0_START (0)
#define SOC_SC_IDLE_STATUS0_sc_idle_status0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fecq_buf_th0 : 5;
        unsigned int reserved_0 : 3;
        unsigned int fecq_buf_th1 : 5;
        unsigned int reserved_1 : 19;
    } reg;
} SOC_SC_PMU_FECQ_CTRL0_UNION;
#endif
#define SOC_SC_PMU_FECQ_CTRL0_fecq_buf_th0_START (0)
#define SOC_SC_PMU_FECQ_CTRL0_fecq_buf_th0_END (4)
#define SOC_SC_PMU_FECQ_CTRL0_fecq_buf_th1_START (8)
#define SOC_SC_PMU_FECQ_CTRL0_fecq_buf_th1_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_fecq_bp_qid_en : 2;
        unsigned int reserved_0 : 6;
        unsigned int pmu_fecq_bp_en : 3;
        unsigned int reserved_1 : 21;
    } reg;
} SOC_SC_PMU_FECQ_CTRL1_UNION;
#endif
#define SOC_SC_PMU_FECQ_CTRL1_pmu_fecq_bp_qid_en_START (0)
#define SOC_SC_PMU_FECQ_CTRL1_pmu_fecq_bp_qid_en_END (1)
#define SOC_SC_PMU_FECQ_CTRL1_pmu_fecq_bp_en_START (8)
#define SOC_SC_PMU_FECQ_CTRL1_pmu_fecq_bp_en_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fedb_buf_sel : 8;
        unsigned int fedb_buf_th : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_SC_PMU_FEDB_CTRL0_UNION;
#endif
#define SOC_SC_PMU_FEDB_CTRL0_fedb_buf_sel_START (0)
#define SOC_SC_PMU_FEDB_CTRL0_fedb_buf_sel_END (7)
#define SOC_SC_PMU_FEDB_CTRL0_fedb_buf_th_START (8)
#define SOC_SC_PMU_FEDB_CTRL0_fedb_buf_th_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tpipe_pipe_req_type0 : 4;
        unsigned int tpipe_pipe_req_type1 : 4;
        unsigned int tpipe_spec_fail_type0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int tpipe_spec_fail_type1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int pmu_srbuf_th : 10;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_SC_PMU_TPIPE_CTRL0_UNION;
#endif
#define SOC_SC_PMU_TPIPE_CTRL0_tpipe_pipe_req_type0_START (0)
#define SOC_SC_PMU_TPIPE_CTRL0_tpipe_pipe_req_type0_END (3)
#define SOC_SC_PMU_TPIPE_CTRL0_tpipe_pipe_req_type1_START (4)
#define SOC_SC_PMU_TPIPE_CTRL0_tpipe_pipe_req_type1_END (7)
#define SOC_SC_PMU_TPIPE_CTRL0_tpipe_spec_fail_type0_START (8)
#define SOC_SC_PMU_TPIPE_CTRL0_tpipe_spec_fail_type0_END (10)
#define SOC_SC_PMU_TPIPE_CTRL0_tpipe_spec_fail_type1_START (12)
#define SOC_SC_PMU_TPIPE_CTRL0_tpipe_spec_fail_type1_END (14)
#define SOC_SC_PMU_TPIPE_CTRL0_pmu_srbuf_th_START (16)
#define SOC_SC_PMU_TPIPE_CTRL0_pmu_srbuf_th_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_tpipe_haz_type : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_SC_PMU_TPIPE_CTRL1_UNION;
#endif
#define SOC_SC_PMU_TPIPE_CTRL1_pmu_tpipe_haz_type_START (0)
#define SOC_SC_PMU_TPIPE_CTRL1_pmu_tpipe_haz_type_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_th_fecq_en : 4;
        unsigned int pmu_th_slot_en : 2;
        unsigned int reserved_0 : 2;
        unsigned int pmu_tag_hit_st : 3;
        unsigned int reserved_1 : 21;
    } reg;
} SOC_SC_PMU_BECQ_CTRL0_UNION;
#endif
#define SOC_SC_PMU_BECQ_CTRL0_pmu_th_fecq_en_START (0)
#define SOC_SC_PMU_BECQ_CTRL0_pmu_th_fecq_en_END (3)
#define SOC_SC_PMU_BECQ_CTRL0_pmu_th_slot_en_START (4)
#define SOC_SC_PMU_BECQ_CTRL0_pmu_th_slot_en_END (5)
#define SOC_SC_PMU_BECQ_CTRL0_pmu_tag_hit_st_START (8)
#define SOC_SC_PMU_BECQ_CTRL0_pmu_tag_hit_st_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_th_slot_num : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SC_PMU_BECQ_CTRL1_UNION;
#endif
#define SOC_SC_PMU_BECQ_CTRL1_pmu_th_slot_num_START (0)
#define SOC_SC_PMU_BECQ_CTRL1_pmu_th_slot_num_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_becq_fsm_en0 : 32;
    } reg;
} SOC_SC_PMU_BECQ_FSM_EN0_UNION;
#endif
#define SOC_SC_PMU_BECQ_FSM_EN0_pmu_becq_fsm_en0_START (0)
#define SOC_SC_PMU_BECQ_FSM_EN0_pmu_becq_fsm_en0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_becq_fsm_en1 : 32;
    } reg;
} SOC_SC_PMU_BECQ_FSM_EN1_UNION;
#endif
#define SOC_SC_PMU_BECQ_FSM_EN1_pmu_becq_fsm_en1_START (0)
#define SOC_SC_PMU_BECQ_FSM_EN1_pmu_becq_fsm_en1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_bypbuf_th0 : 7;
        unsigned int reserved_0 : 1;
        unsigned int pmu_bypbuf_th1 : 7;
        unsigned int reserved_1 : 1;
        unsigned int pmu_age_upd_clusterid_msk : 4;
        unsigned int pmu_age_upd_rrpv_msk : 4;
        unsigned int pmu_dmemif_rbuf_th : 3;
        unsigned int reserved_2 : 5;
    } reg;
} SOC_SC_PMU_OTHER_CTRL0_UNION;
#endif
#define SOC_SC_PMU_OTHER_CTRL0_pmu_bypbuf_th0_START (0)
#define SOC_SC_PMU_OTHER_CTRL0_pmu_bypbuf_th0_END (6)
#define SOC_SC_PMU_OTHER_CTRL0_pmu_bypbuf_th1_START (8)
#define SOC_SC_PMU_OTHER_CTRL0_pmu_bypbuf_th1_END (14)
#define SOC_SC_PMU_OTHER_CTRL0_pmu_age_upd_clusterid_msk_START (16)
#define SOC_SC_PMU_OTHER_CTRL0_pmu_age_upd_clusterid_msk_END (19)
#define SOC_SC_PMU_OTHER_CTRL0_pmu_age_upd_rrpv_msk_START (20)
#define SOC_SC_PMU_OTHER_CTRL0_pmu_age_upd_rrpv_msk_END (23)
#define SOC_SC_PMU_OTHER_CTRL0_pmu_dmemif_rbuf_th_START (24)
#define SOC_SC_PMU_OTHER_CTRL0_pmu_dmemif_rbuf_th_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_mst2sn_flt : 4;
        unsigned int pmu_mst2sn_mode_sel : 1;
        unsigned int reserved_0 : 3;
        unsigned int pmu_mst2sn_stream_sel : 4;
        unsigned int pmu_mstif_pri_bp : 2;
        unsigned int reserved_1 : 2;
        unsigned int pmu_mstif_rbuf_th : 4;
        unsigned int pmu_qos_allow_from_sc : 8;
        unsigned int reserved_2 : 4;
    } reg;
} SOC_SC_PMU_OTHER_CTRL1_UNION;
#endif
#define SOC_SC_PMU_OTHER_CTRL1_pmu_mst2sn_flt_START (0)
#define SOC_SC_PMU_OTHER_CTRL1_pmu_mst2sn_flt_END (3)
#define SOC_SC_PMU_OTHER_CTRL1_pmu_mst2sn_mode_sel_START (4)
#define SOC_SC_PMU_OTHER_CTRL1_pmu_mst2sn_mode_sel_END (4)
#define SOC_SC_PMU_OTHER_CTRL1_pmu_mst2sn_stream_sel_START (8)
#define SOC_SC_PMU_OTHER_CTRL1_pmu_mst2sn_stream_sel_END (11)
#define SOC_SC_PMU_OTHER_CTRL1_pmu_mstif_pri_bp_START (12)
#define SOC_SC_PMU_OTHER_CTRL1_pmu_mstif_pri_bp_END (13)
#define SOC_SC_PMU_OTHER_CTRL1_pmu_mstif_rbuf_th_START (16)
#define SOC_SC_PMU_OTHER_CTRL1_pmu_mstif_rbuf_th_END (19)
#define SOC_SC_PMU_OTHER_CTRL1_pmu_qos_allow_from_sc_START (20)
#define SOC_SC_PMU_OTHER_CTRL1_pmu_qos_allow_from_sc_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_flt_gid : 12;
        unsigned int reserved_0 : 4;
        unsigned int pmu_flt_gid_mask : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_SC_PMU_FLT_CTRL0_UNION;
#endif
#define SOC_SC_PMU_FLT_CTRL0_pmu_flt_gid_START (0)
#define SOC_SC_PMU_FLT_CTRL0_pmu_flt_gid_END (11)
#define SOC_SC_PMU_FLT_CTRL0_pmu_flt_gid_mask_START (16)
#define SOC_SC_PMU_FLT_CTRL0_pmu_flt_gid_mask_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_flt_mid : 16;
        unsigned int pmu_flt_mid_mask : 16;
    } reg;
} SOC_SC_PMU_FLT_CTRL1_UNION;
#endif
#define SOC_SC_PMU_FLT_CTRL1_pmu_flt_mid_START (0)
#define SOC_SC_PMU_FLT_CTRL1_pmu_flt_mid_END (15)
#define SOC_SC_PMU_FLT_CTRL1_pmu_flt_mid_mask_START (16)
#define SOC_SC_PMU_FLT_CTRL1_pmu_flt_mid_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_flt_mapm : 8;
        unsigned int pmu_flt_mpam_mask : 8;
        unsigned int pmu_flt_schint : 8;
        unsigned int pmu_flt_schint_mask : 8;
    } reg;
} SOC_SC_PMU_FLT_CTRL2_UNION;
#endif
#define SOC_SC_PMU_FLT_CTRL2_pmu_flt_mapm_START (0)
#define SOC_SC_PMU_FLT_CTRL2_pmu_flt_mapm_END (7)
#define SOC_SC_PMU_FLT_CTRL2_pmu_flt_mpam_mask_START (8)
#define SOC_SC_PMU_FLT_CTRL2_pmu_flt_mpam_mask_END (15)
#define SOC_SC_PMU_FLT_CTRL2_pmu_flt_schint_START (16)
#define SOC_SC_PMU_FLT_CTRL2_pmu_flt_schint_END (23)
#define SOC_SC_PMU_FLT_CTRL2_pmu_flt_schint_mask_START (24)
#define SOC_SC_PMU_FLT_CTRL2_pmu_flt_schint_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_flt_pri : 4;
        unsigned int pmu_flt_pri_mask : 4;
        unsigned int pmu_flt_paf : 2;
        unsigned int pmu_flt_paf_mask : 2;
        unsigned int pmu_flt_fecq_id : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_PMU_FLT_CTRL3_UNION;
#endif
#define SOC_SC_PMU_FLT_CTRL3_pmu_flt_pri_START (0)
#define SOC_SC_PMU_FLT_CTRL3_pmu_flt_pri_END (3)
#define SOC_SC_PMU_FLT_CTRL3_pmu_flt_pri_mask_START (4)
#define SOC_SC_PMU_FLT_CTRL3_pmu_flt_pri_mask_END (7)
#define SOC_SC_PMU_FLT_CTRL3_pmu_flt_paf_START (8)
#define SOC_SC_PMU_FLT_CTRL3_pmu_flt_paf_END (9)
#define SOC_SC_PMU_FLT_CTRL3_pmu_flt_paf_mask_START (10)
#define SOC_SC_PMU_FLT_CTRL3_pmu_flt_paf_mask_END (11)
#define SOC_SC_PMU_FLT_CTRL3_pmu_flt_fecq_id_START (12)
#define SOC_SC_PMU_FLT_CTRL3_pmu_flt_fecq_id_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_flt_req_opc : 14;
        unsigned int reserved_0 : 2;
        unsigned int pmu_flt_req_opc_mask : 14;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_SC_PMU_FLT_CTRL4_UNION;
#endif
#define SOC_SC_PMU_FLT_CTRL4_pmu_flt_req_opc_START (0)
#define SOC_SC_PMU_FLT_CTRL4_pmu_flt_req_opc_END (13)
#define SOC_SC_PMU_FLT_CTRL4_pmu_flt_req_opc_mask_START (16)
#define SOC_SC_PMU_FLT_CTRL4_pmu_flt_req_opc_mask_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_flt_snp_src : 8;
        unsigned int pmu_flt_snp_tgt : 4;
        unsigned int pmu_flt_srsp_src : 4;
        unsigned int pmu_flt_snpdata_src : 4;
        unsigned int pmu_snp_smp_en : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_SC_PMU_FLT_SNP_CTRL0_UNION;
#endif
#define SOC_SC_PMU_FLT_SNP_CTRL0_pmu_flt_snp_src_START (0)
#define SOC_SC_PMU_FLT_SNP_CTRL0_pmu_flt_snp_src_END (7)
#define SOC_SC_PMU_FLT_SNP_CTRL0_pmu_flt_snp_tgt_START (8)
#define SOC_SC_PMU_FLT_SNP_CTRL0_pmu_flt_snp_tgt_END (11)
#define SOC_SC_PMU_FLT_SNP_CTRL0_pmu_flt_srsp_src_START (12)
#define SOC_SC_PMU_FLT_SNP_CTRL0_pmu_flt_srsp_src_END (15)
#define SOC_SC_PMU_FLT_SNP_CTRL0_pmu_flt_snpdata_src_START (16)
#define SOC_SC_PMU_FLT_SNP_CTRL0_pmu_flt_snpdata_src_END (19)
#define SOC_SC_PMU_FLT_SNP_CTRL0_pmu_snp_smp_en_START (20)
#define SOC_SC_PMU_FLT_SNP_CTRL0_pmu_snp_smp_en_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_flt_snp_opc : 10;
        unsigned int reserved_0 : 6;
        unsigned int pmu_flt_snp_opc_mask : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_SC_PMU_FLT_SNP_CTRL1_UNION;
#endif
#define SOC_SC_PMU_FLT_SNP_CTRL1_pmu_flt_snp_opc_START (0)
#define SOC_SC_PMU_FLT_SNP_CTRL1_pmu_flt_snp_opc_END (9)
#define SOC_SC_PMU_FLT_SNP_CTRL1_pmu_flt_snp_opc_mask_START (16)
#define SOC_SC_PMU_FLT_SNP_CTRL1_pmu_flt_snp_opc_mask_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_snp_lat_th : 32;
    } reg;
} SOC_SC_PMU_SNP_SMP_TH_UNION;
#endif
#define SOC_SC_PMU_SNP_SMP_TH_pmu_snp_lat_th_START (0)
#define SOC_SC_PMU_SNP_SMP_TH_pmu_snp_lat_th_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_evcnt : 32;
    } reg;
} SOC_SC_PMU_EVCNT_UNION;
#endif
#define SOC_SC_PMU_EVCNT_pmu_evcnt_START (0)
#define SOC_SC_PMU_EVCNT_pmu_evcnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_evsvr : 32;
    } reg;
} SOC_SC_PMU_EVSVR_UNION;
#endif
#define SOC_SC_PMU_EVSVR_pmu_evsvr_START (0)
#define SOC_SC_PMU_EVSVR_pmu_evsvr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_evtype : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_SC_PMU_EVTYPE_UNION;
#endif
#define SOC_SC_PMU_EVTYPE_pmu_evtype_START (0)
#define SOC_SC_PMU_EVTYPE_pmu_evtype_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_cnten : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_PMU_CNTEN_UNION;
#endif
#define SOC_SC_PMU_CNTEN_pmu_cnten_START (0)
#define SOC_SC_PMU_CNTEN_pmu_cnten_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_overflow : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_PMU_OV_UNION;
#endif
#define SOC_SC_PMU_OV_pmu_overflow_START (0)
#define SOC_SC_PMU_OV_pmu_overflow_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_en : 1;
        unsigned int pmu_ovcap_en : 1;
        unsigned int pmu_ckg_byp : 1;
        unsigned int pmu_cap_clear_en : 1;
        unsigned int pmu_cfg_non_ull_en : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_SC_PMU_CFG_UNION;
#endif
#define SOC_SC_PMU_CFG_pmu_en_START (0)
#define SOC_SC_PMU_CFG_pmu_en_END (0)
#define SOC_SC_PMU_CFG_pmu_ovcap_en_START (1)
#define SOC_SC_PMU_CFG_pmu_ovcap_en_END (1)
#define SOC_SC_PMU_CFG_pmu_ckg_byp_START (2)
#define SOC_SC_PMU_CFG_pmu_ckg_byp_END (2)
#define SOC_SC_PMU_CFG_pmu_cap_clear_en_START (3)
#define SOC_SC_PMU_CFG_pmu_cap_clear_en_END (3)
#define SOC_SC_PMU_CFG_pmu_cfg_non_ull_en_START (4)
#define SOC_SC_PMU_CFG_pmu_cfg_non_ull_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_cap : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SC_PMU_CAPR_UNION;
#endif
#define SOC_SC_PMU_CAPR_pmu_cap_START (0)
#define SOC_SC_PMU_CAPR_pmu_cap_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_glb_mask_pmu : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SC_PMU_INT_GLB_MASK_UNION;
#endif
#define SOC_SC_PMU_INT_GLB_MASK_int_glb_mask_pmu_START (0)
#define SOC_SC_PMU_INT_GLB_MASK_int_glb_mask_pmu_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_clr_pmu : 1;
        unsigned int sw_trig_int_pmu : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_SC_PMU_INT_CLR_UNION;
#endif
#define SOC_SC_PMU_INT_CLR_int_clr_pmu_START (0)
#define SOC_SC_PMU_INT_CLR_int_clr_pmu_END (0)
#define SOC_SC_PMU_INT_CLR_sw_trig_int_pmu_START (1)
#define SOC_SC_PMU_INT_CLR_sw_trig_int_pmu_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_mask_pmu : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SC_PMU_INT_MASK_UNION;
#endif
#define SOC_SC_PMU_INT_MASK_int_mask_pmu_START (0)
#define SOC_SC_PMU_INT_MASK_int_mask_pmu_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_dis_pmu : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SC_PMU_INT_DIS_UNION;
#endif
#define SOC_SC_PMU_INT_DIS_int_dis_pmu_START (0)
#define SOC_SC_PMU_INT_DIS_int_dis_pmu_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_org_status_pmu : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SC_PMU_INT_ORG_STATUS_UNION;
#endif
#define SOC_SC_PMU_INT_ORG_STATUS_int_org_status_pmu_START (0)
#define SOC_SC_PMU_INT_ORG_STATUS_int_org_status_pmu_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_mask_status_pmu : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SC_PMU_INT_MASK_STATUS_UNION;
#endif
#define SOC_SC_PMU_INT_MASK_STATUS_int_mask_status_pmu_START (0)
#define SOC_SC_PMU_INT_MASK_STATUS_int_mask_status_pmu_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tmem_tdslpwk2clk : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_TMEM_SLP_PARAM_UNION;
#endif
#define SOC_SC_TMEM_SLP_PARAM_tmem_tdslpwk2clk_START (0)
#define SOC_SC_TMEM_SLP_PARAM_tmem_tdslpwk2clk_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmem_tdslpwk2clk : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_DMEM_SLP_PARAM_UNION;
#endif
#define SOC_SC_DMEM_SLP_PARAM_dmem_tdslpwk2clk_START (0)
#define SOC_SC_DMEM_SLP_PARAM_dmem_tdslpwk2clk_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int smem_tdslpwk2clk : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_SMEM_SLP_PARAM_UNION;
#endif
#define SOC_SC_SMEM_SLP_PARAM_smem_tdslpwk2clk_START (0)
#define SOC_SC_SMEM_SLP_PARAM_smem_tdslpwk2clk_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tmem_sta_ls_en : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_TMEM_STA_CFG0_UNION;
#endif
#define SOC_SC_TMEM_STA_CFG0_tmem_sta_ls_en_START (0)
#define SOC_SC_TMEM_STA_CFG0_tmem_sta_ls_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tmem_sta_ds_en : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_TMEM_STA_CFG1_UNION;
#endif
#define SOC_SC_TMEM_STA_CFG1_tmem_sta_ds_en_START (0)
#define SOC_SC_TMEM_STA_CFG1_tmem_sta_ds_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmem_sta_ls_en : 32;
    } reg;
} SOC_SC_DMEM_STA_CFG0_UNION;
#endif
#define SOC_SC_DMEM_STA_CFG0_dmem_sta_ls_en_START (0)
#define SOC_SC_DMEM_STA_CFG0_dmem_sta_ls_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmem_sta_ds_en : 32;
    } reg;
} SOC_SC_DMEM_STA_CFG1_UNION;
#endif
#define SOC_SC_DMEM_STA_CFG1_dmem_sta_ds_en_START (0)
#define SOC_SC_DMEM_STA_CFG1_dmem_sta_ds_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int smem_sta_ls_en : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_SC_SMEM_STA_CFG0_UNION;
#endif
#define SOC_SC_SMEM_STA_CFG0_smem_sta_ls_en_START (0)
#define SOC_SC_SMEM_STA_CFG0_smem_sta_ls_en_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int smem_sta_ds_en : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_SC_SMEM_STA_CFG1_UNION;
#endif
#define SOC_SC_SMEM_STA_CFG1_smem_sta_ds_en_START (0)
#define SOC_SC_SMEM_STA_CFG1_smem_sta_ds_en_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tmem_lpc_delay_time : 5;
        unsigned int reserved_0 : 3;
        unsigned int dmem_lpc_delay_time : 5;
        unsigned int reserved_1 : 3;
        unsigned int smem_lpc_delay_time : 5;
        unsigned int reserved_2 : 11;
    } reg;
} SOC_SC_MEM_LP_CTRL0_UNION;
#endif
#define SOC_SC_MEM_LP_CTRL0_tmem_lpc_delay_time_START (0)
#define SOC_SC_MEM_LP_CTRL0_tmem_lpc_delay_time_END (4)
#define SOC_SC_MEM_LP_CTRL0_dmem_lpc_delay_time_START (8)
#define SOC_SC_MEM_LP_CTRL0_dmem_lpc_delay_time_END (12)
#define SOC_SC_MEM_LP_CTRL0_smem_lpc_delay_time_START (16)
#define SOC_SC_MEM_LP_CTRL0_smem_lpc_delay_time_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int func_byp_tmem_dynlp : 1;
        unsigned int func_byp_dmem_dynlp : 6;
        unsigned int func_byp_smem_dynlp : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_SC_MEM_LP_CTRL1_UNION;
#endif
#define SOC_SC_MEM_LP_CTRL1_func_byp_tmem_dynlp_START (0)
#define SOC_SC_MEM_LP_CTRL1_func_byp_tmem_dynlp_END (0)
#define SOC_SC_MEM_LP_CTRL1_func_byp_dmem_dynlp_START (1)
#define SOC_SC_MEM_LP_CTRL1_func_byp_dmem_dynlp_END (6)
#define SOC_SC_MEM_LP_CTRL1_func_byp_smem_dynlp_START (7)
#define SOC_SC_MEM_LP_CTRL1_func_byp_smem_dynlp_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tmem_ds_tcnt : 8;
        unsigned int tmem_tintvl : 8;
        unsigned int tmem_slp_zcnt : 2;
        unsigned int reserved : 14;
    } reg;
} SOC_SC_TMEM_LP_SLP_CFG_UNION;
#endif
#define SOC_SC_TMEM_LP_SLP_CFG_tmem_ds_tcnt_START (0)
#define SOC_SC_TMEM_LP_SLP_CFG_tmem_ds_tcnt_END (7)
#define SOC_SC_TMEM_LP_SLP_CFG_tmem_tintvl_START (8)
#define SOC_SC_TMEM_LP_SLP_CFG_tmem_tintvl_END (15)
#define SOC_SC_TMEM_LP_SLP_CFG_tmem_slp_zcnt_START (16)
#define SOC_SC_TMEM_LP_SLP_CFG_tmem_slp_zcnt_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmem_ds_tcnt : 8;
        unsigned int dmem_tintvl : 8;
        unsigned int dmem_slp_zcnt : 2;
        unsigned int reserved : 14;
    } reg;
} SOC_SC_DMEM_LP_SLP_CFG_UNION;
#endif
#define SOC_SC_DMEM_LP_SLP_CFG_dmem_ds_tcnt_START (0)
#define SOC_SC_DMEM_LP_SLP_CFG_dmem_ds_tcnt_END (7)
#define SOC_SC_DMEM_LP_SLP_CFG_dmem_tintvl_START (8)
#define SOC_SC_DMEM_LP_SLP_CFG_dmem_tintvl_END (15)
#define SOC_SC_DMEM_LP_SLP_CFG_dmem_slp_zcnt_START (16)
#define SOC_SC_DMEM_LP_SLP_CFG_dmem_slp_zcnt_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int smem_ds_tcnt : 8;
        unsigned int smem_tintvl : 8;
        unsigned int smem_slp_zcnt : 2;
        unsigned int reserved : 14;
    } reg;
} SOC_SC_SMEM_LP_SLP_CFG_UNION;
#endif
#define SOC_SC_SMEM_LP_SLP_CFG_smem_ds_tcnt_START (0)
#define SOC_SC_SMEM_LP_SLP_CFG_smem_ds_tcnt_END (7)
#define SOC_SC_SMEM_LP_SLP_CFG_smem_tintvl_START (8)
#define SOC_SC_SMEM_LP_SLP_CFG_smem_tintvl_END (15)
#define SOC_SC_SMEM_LP_SLP_CFG_smem_slp_zcnt_START (16)
#define SOC_SC_SMEM_LP_SLP_CFG_smem_slp_zcnt_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tmem_pwrup_en : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_TMEM_WAY_PWRUP_UNION;
#endif
#define SOC_SC_TMEM_WAY_PWRUP_tmem_pwrup_en_START (0)
#define SOC_SC_TMEM_WAY_PWRUP_tmem_pwrup_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmem_pwrup_en : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_DMEM_WAY_PWRUP_UNION;
#endif
#define SOC_SC_DMEM_WAY_PWRUP_dmem_pwrup_en_START (0)
#define SOC_SC_DMEM_WAY_PWRUP_dmem_pwrup_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int smem_pwrup_en : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_SC_SMEM_WAY_PWRUP_UNION;
#endif
#define SOC_SC_SMEM_WAY_PWRUP_smem_pwrup_en_START (0)
#define SOC_SC_SMEM_WAY_PWRUP_smem_pwrup_en_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tmem_init_en : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_TMEM_WAY_INIT_UNION;
#endif
#define SOC_SC_TMEM_WAY_INIT_tmem_init_en_START (0)
#define SOC_SC_TMEM_WAY_INIT_tmem_init_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmem_init_en : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_DMEM_WAY_INIT_UNION;
#endif
#define SOC_SC_DMEM_WAY_INIT_dmem_init_en_START (0)
#define SOC_SC_DMEM_WAY_INIT_dmem_init_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int smem_init_en : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_SC_SMEM_WAY_INIT_UNION;
#endif
#define SOC_SC_SMEM_WAY_INIT_smem_init_en_START (0)
#define SOC_SC_SMEM_WAY_INIT_smem_init_en_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmem_ram_tmod : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_SC_DMEM_SPC_UNION;
#endif
#define SOC_SC_DMEM_SPC_dmem_ram_tmod_START (0)
#define SOC_SC_DMEM_SPC_dmem_ram_tmod_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bedb_ram_tmod : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_BEDB_SPC_UNION;
#endif
#define SOC_SC_BEDB_SPC_bedb_ram_tmod_START (0)
#define SOC_SC_BEDB_SPC_bedb_ram_tmod_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int victim_ram_tmod : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_VICTIM_SPC_UNION;
#endif
#define SOC_SC_VICTIM_SPC_victim_ram_tmod_START (0)
#define SOC_SC_VICTIM_SPC_victim_ram_tmod_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sfram_ram_tmod : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_SC_SFRAM_SPC_UNION;
#endif
#define SOC_SC_SFRAM_SPC_sfram_ram_tmod_START (0)
#define SOC_SC_SFRAM_SPC_sfram_ram_tmod_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tagram_ram_tmod : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_SC_TAGRAM_SPC_UNION;
#endif
#define SOC_SC_TAGRAM_SPC_tagram_ram_tmod_START (0)
#define SOC_SC_TAGRAM_SPC_tagram_ram_tmod_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_cgid_cnt : 16;
        unsigned int cgid_byp_switch_status : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_SC_CGID_STATUS0_UNION;
#endif
#define SOC_SC_CGID_STATUS0_sc_cgid_cnt_START (0)
#define SOC_SC_CGID_STATUS0_sc_cgid_cnt_END (15)
#define SOC_SC_CGID_STATUS0_cgid_byp_switch_status_START (16)
#define SOC_SC_CGID_STATUS0_cgid_byp_switch_status_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gid_byp_switch_status : 32;
    } reg;
} SOC_SC_GID_BYP_SWITCH_STATUS_UNION;
#endif
#define SOC_SC_GID_BYP_SWITCH_STATUS_gid_byp_switch_status_START (0)
#define SOC_SC_GID_BYP_SWITCH_STATUS_gid_byp_switch_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int statis_cnt_in : 32;
    } reg;
} SOC_SC_STATIS_CNT_IN_UNION;
#endif
#define SOC_SC_STATIS_CNT_IN_statis_cnt_in_START (0)
#define SOC_SC_STATIS_CNT_IN_statis_cnt_in_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int statis_cnt_out : 32;
    } reg;
} SOC_SC_STATIS_CNT_OUT_UNION;
#endif
#define SOC_SC_STATIS_CNT_OUT_statis_cnt_out_START (0)
#define SOC_SC_STATIS_CNT_OUT_statis_cnt_out_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pv_hc_cnt : 32;
    } reg;
} SOC_SC_SMQ_STATUS3_UNION;
#endif
#define SOC_SC_SMQ_STATUS3_pv_hc_cnt_START (0)
#define SOC_SC_SMQ_STATUS3_pv_hc_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pd_mig_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_SMQ_STATUS4_UNION;
#endif
#define SOC_SC_SMQ_STATUS4_pd_mig_cnt_START (0)
#define SOC_SC_SMQ_STATUS4_pd_mig_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_tmem_st_pwrup : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_TAGRAM_LP_STATUS0_UNION;
#endif
#define SOC_SC_TAGRAM_LP_STATUS0_dfx_tmem_st_pwrup_START (0)
#define SOC_SC_TAGRAM_LP_STATUS0_dfx_tmem_st_pwrup_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_tmem_init_state : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_TAGRAM_LP_STATUS1_UNION;
#endif
#define SOC_SC_TAGRAM_LP_STATUS1_dfx_tmem_init_state_START (0)
#define SOC_SC_TAGRAM_LP_STATUS1_dfx_tmem_init_state_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_smem_st_pwrup : 12;
        unsigned int reserved_0 : 4;
        unsigned int dfx_smem_init_state : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_SC_SFRAM_LP_STATUS_UNION;
#endif
#define SOC_SC_SFRAM_LP_STATUS_dfx_smem_st_pwrup_START (0)
#define SOC_SC_SFRAM_LP_STATUS_dfx_smem_st_pwrup_END (11)
#define SOC_SC_SFRAM_LP_STATUS_dfx_smem_init_state_START (16)
#define SOC_SC_SFRAM_LP_STATUS_dfx_smem_init_state_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_dmem_st_pwrup : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_DRAM_LP_STATUS0_UNION;
#endif
#define SOC_SC_DRAM_LP_STATUS0_dfx_dmem_st_pwrup_START (0)
#define SOC_SC_DRAM_LP_STATUS0_dfx_dmem_st_pwrup_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_dmem_init_state : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_DRAM_LP_STATUS1_UNION;
#endif
#define SOC_SC_DRAM_LP_STATUS1_dfx_dmem_init_state_START (0)
#define SOC_SC_DRAM_LP_STATUS1_dfx_dmem_init_state_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_tmem_dyn_ds : 1;
        unsigned int dfx_tmem_lpc_busy : 1;
        unsigned int dfx_tmem_normal : 16;
        unsigned int reserved : 14;
    } reg;
} SOC_SC_TAGRAM_LPC_DFX0_UNION;
#endif
#define SOC_SC_TAGRAM_LPC_DFX0_dfx_tmem_dyn_ds_START (0)
#define SOC_SC_TAGRAM_LPC_DFX0_dfx_tmem_dyn_ds_END (0)
#define SOC_SC_TAGRAM_LPC_DFX0_dfx_tmem_lpc_busy_START (1)
#define SOC_SC_TAGRAM_LPC_DFX0_dfx_tmem_lpc_busy_END (1)
#define SOC_SC_TAGRAM_LPC_DFX0_dfx_tmem_normal_START (2)
#define SOC_SC_TAGRAM_LPC_DFX0_dfx_tmem_normal_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_tmem_ds : 8;
        unsigned int dfx_tmem_dyn_ds_fsm : 3;
        unsigned int reserved : 21;
    } reg;
} SOC_SC_TAGRAM_LPC_DFX1_UNION;
#endif
#define SOC_SC_TAGRAM_LPC_DFX1_dfx_tmem_ds_START (0)
#define SOC_SC_TAGRAM_LPC_DFX1_dfx_tmem_ds_END (7)
#define SOC_SC_TAGRAM_LPC_DFX1_dfx_tmem_dyn_ds_fsm_START (8)
#define SOC_SC_TAGRAM_LPC_DFX1_dfx_tmem_dyn_ds_fsm_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_smem_dyn_ds : 1;
        unsigned int dfx_smem_lpc_busy : 1;
        unsigned int reserved_0 : 2;
        unsigned int dfx_smem_normal : 12;
        unsigned int dfx_smem_ds : 12;
        unsigned int dfx_smem_dyn_ds_fsm : 3;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_SC_SFRAM_LPC_DFX0_UNION;
#endif
#define SOC_SC_SFRAM_LPC_DFX0_dfx_smem_dyn_ds_START (0)
#define SOC_SC_SFRAM_LPC_DFX0_dfx_smem_dyn_ds_END (0)
#define SOC_SC_SFRAM_LPC_DFX0_dfx_smem_lpc_busy_START (1)
#define SOC_SC_SFRAM_LPC_DFX0_dfx_smem_lpc_busy_END (1)
#define SOC_SC_SFRAM_LPC_DFX0_dfx_smem_normal_START (4)
#define SOC_SC_SFRAM_LPC_DFX0_dfx_smem_normal_END (15)
#define SOC_SC_SFRAM_LPC_DFX0_dfx_smem_ds_START (16)
#define SOC_SC_SFRAM_LPC_DFX0_dfx_smem_ds_END (27)
#define SOC_SC_SFRAM_LPC_DFX0_dfx_smem_dyn_ds_fsm_START (28)
#define SOC_SC_SFRAM_LPC_DFX0_dfx_smem_dyn_ds_fsm_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_dmem_dyn_ds : 6;
        unsigned int dfx_dmem_lpc_busy : 1;
        unsigned int dfx_dmem_normal : 8;
        unsigned int reserved : 17;
    } reg;
} SOC_SC_DRAM_LPC_DFX0_UNION;
#endif
#define SOC_SC_DRAM_LPC_DFX0_dfx_dmem_dyn_ds_START (0)
#define SOC_SC_DRAM_LPC_DFX0_dfx_dmem_dyn_ds_END (5)
#define SOC_SC_DRAM_LPC_DFX0_dfx_dmem_lpc_busy_START (6)
#define SOC_SC_DRAM_LPC_DFX0_dfx_dmem_lpc_busy_END (6)
#define SOC_SC_DRAM_LPC_DFX0_dfx_dmem_normal_START (7)
#define SOC_SC_DRAM_LPC_DFX0_dfx_dmem_normal_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_dmem_ds : 32;
    } reg;
} SOC_SC_DRAM_LPC_DFX1_UNION;
#endif
#define SOC_SC_DRAM_LPC_DFX1_dfx_dmem_ds_START (0)
#define SOC_SC_DRAM_LPC_DFX1_dfx_dmem_ds_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_dmem_dyn_ds_fsm0 : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_SC_DRAM_LPC_DFX2_UNION;
#endif
#define SOC_SC_DRAM_LPC_DFX2_dfx_dmem_dyn_ds_fsm0_START (0)
#define SOC_SC_DRAM_LPC_DFX2_dfx_dmem_dyn_ds_fsm0_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int smq_mig_stat : 32;
    } reg;
} SOC_SC_SMQ_STATUS_UNION;
#endif
#define SOC_SC_SMQ_STATUS_smq_mig_stat_START (0)
#define SOC_SC_SMQ_STATUS_smq_mig_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int smq_mig_stat2 : 32;
    } reg;
} SOC_SC_SMQ_STATUS2_UNION;
#endif
#define SOC_SC_SMQ_STATUS2_smq_mig_stat2_START (0)
#define SOC_SC_SMQ_STATUS2_smq_mig_stat2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pgid_wr_revisit_age : 3;
        unsigned int reserved_0 : 1;
        unsigned int pgid_nwr_revisit_age : 3;
        unsigned int reserved_1 : 1;
        unsigned int pgid_initial_age : 3;
        unsigned int reserved_2 : 1;
        unsigned int pgid_wr_policy : 2;
        unsigned int pgid_rd_policy : 2;
        unsigned int pgid_priority : 2;
        unsigned int pgid_self_replaceable : 1;
        unsigned int reserved_3 : 1;
        unsigned int pgid_drop : 1;
        unsigned int pgid_drop_clr : 1;
        unsigned int pgid_drop_set : 1;
        unsigned int reserved_4 : 1;
        unsigned int pgid_disable : 1;
        unsigned int pgid_disable_clr : 1;
        unsigned int pgid_disable_set : 1;
        unsigned int reserved_5 : 1;
        unsigned int pgid_small_burst_size : 2;
        unsigned int pgid_small_burst_na : 1;
        unsigned int reserved_6 : 1;
    } reg;
} SOC_SC_GID_CFG_UNION;
#endif
#define SOC_SC_GID_CFG_pgid_wr_revisit_age_START (0)
#define SOC_SC_GID_CFG_pgid_wr_revisit_age_END (2)
#define SOC_SC_GID_CFG_pgid_nwr_revisit_age_START (4)
#define SOC_SC_GID_CFG_pgid_nwr_revisit_age_END (6)
#define SOC_SC_GID_CFG_pgid_initial_age_START (8)
#define SOC_SC_GID_CFG_pgid_initial_age_END (10)
#define SOC_SC_GID_CFG_pgid_wr_policy_START (12)
#define SOC_SC_GID_CFG_pgid_wr_policy_END (13)
#define SOC_SC_GID_CFG_pgid_rd_policy_START (14)
#define SOC_SC_GID_CFG_pgid_rd_policy_END (15)
#define SOC_SC_GID_CFG_pgid_priority_START (16)
#define SOC_SC_GID_CFG_pgid_priority_END (17)
#define SOC_SC_GID_CFG_pgid_self_replaceable_START (18)
#define SOC_SC_GID_CFG_pgid_self_replaceable_END (18)
#define SOC_SC_GID_CFG_pgid_drop_START (20)
#define SOC_SC_GID_CFG_pgid_drop_END (20)
#define SOC_SC_GID_CFG_pgid_drop_clr_START (21)
#define SOC_SC_GID_CFG_pgid_drop_clr_END (21)
#define SOC_SC_GID_CFG_pgid_drop_set_START (22)
#define SOC_SC_GID_CFG_pgid_drop_set_END (22)
#define SOC_SC_GID_CFG_pgid_disable_START (24)
#define SOC_SC_GID_CFG_pgid_disable_END (24)
#define SOC_SC_GID_CFG_pgid_disable_clr_START (25)
#define SOC_SC_GID_CFG_pgid_disable_clr_END (25)
#define SOC_SC_GID_CFG_pgid_disable_set_START (26)
#define SOC_SC_GID_CFG_pgid_disable_set_END (26)
#define SOC_SC_GID_CFG_pgid_small_burst_size_START (28)
#define SOC_SC_GID_CFG_pgid_small_burst_size_END (29)
#define SOC_SC_GID_CFG_pgid_small_burst_na_START (30)
#define SOC_SC_GID_CFG_pgid_small_burst_na_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rrpv_map_age0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int rrpv_map_age1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int rrpv_map_age2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int rrpv_map_age3 : 3;
        unsigned int reserved_3 : 1;
        unsigned int clusterid_rrpv_age_en : 4;
        unsigned int reserved_4 : 12;
    } reg;
} SOC_SC_REPLACE_RRPV_CFG_UNION;
#endif
#define SOC_SC_REPLACE_RRPV_CFG_rrpv_map_age0_START (0)
#define SOC_SC_REPLACE_RRPV_CFG_rrpv_map_age0_END (2)
#define SOC_SC_REPLACE_RRPV_CFG_rrpv_map_age1_START (4)
#define SOC_SC_REPLACE_RRPV_CFG_rrpv_map_age1_END (6)
#define SOC_SC_REPLACE_RRPV_CFG_rrpv_map_age2_START (8)
#define SOC_SC_REPLACE_RRPV_CFG_rrpv_map_age2_END (10)
#define SOC_SC_REPLACE_RRPV_CFG_rrpv_map_age3_START (12)
#define SOC_SC_REPLACE_RRPV_CFG_rrpv_map_age3_END (14)
#define SOC_SC_REPLACE_RRPV_CFG_clusterid_rrpv_age_en_START (16)
#define SOC_SC_REPLACE_RRPV_CFG_clusterid_rrpv_age_en_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ocfg_glb_sec_rgn_byp : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SC_GLB_SEC_REG_CTRL_UNION;
#endif
#define SOC_SC_GLB_SEC_REG_CTRL_ocfg_glb_sec_rgn_byp_START (0)
#define SOC_SC_GLB_SEC_REG_CTRL_ocfg_glb_sec_rgn_byp_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sec_rgn_lock_set : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_SEC_RGN_LOCK_SET_UNION;
#endif
#define SOC_SC_SEC_RGN_LOCK_SET_sec_rgn_lock_set_START (0)
#define SOC_SC_SEC_RGN_LOCK_SET_sec_rgn_lock_set_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sec_rgn_lock_clr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_SEC_RGN_LOCK_CLR_UNION;
#endif
#define SOC_SC_SEC_RGN_LOCK_CLR_sec_rgn_lock_clr_START (0)
#define SOC_SC_SEC_RGN_LOCK_CLR_sec_rgn_lock_clr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sec_rgn_lock : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_SC_SEC_RGN_LOCK_ST_UNION;
#endif
#define SOC_SC_SEC_RGN_LOCK_ST_sec_rgn_lock_START (0)
#define SOC_SC_SEC_RGN_LOCK_ST_sec_rgn_lock_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ocfg_sec_rgn_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int ocfg_sec_sp_rd : 2;
        unsigned int ocfg_sec_sp_wr : 2;
        unsigned int reserved_1 : 4;
        unsigned int ocfg_sec_mid_group : 3;
        unsigned int ocfg_sec_mid_compare : 1;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_SC_SEC_RGN_CTRL_UNION;
#endif
#define SOC_SC_SEC_RGN_CTRL_ocfg_sec_rgn_en_START (0)
#define SOC_SC_SEC_RGN_CTRL_ocfg_sec_rgn_en_END (0)
#define SOC_SC_SEC_RGN_CTRL_ocfg_sec_sp_rd_START (4)
#define SOC_SC_SEC_RGN_CTRL_ocfg_sec_sp_rd_END (5)
#define SOC_SC_SEC_RGN_CTRL_ocfg_sec_sp_wr_START (6)
#define SOC_SC_SEC_RGN_CTRL_ocfg_sec_sp_wr_END (7)
#define SOC_SC_SEC_RGN_CTRL_ocfg_sec_mid_group_START (12)
#define SOC_SC_SEC_RGN_CTRL_ocfg_sec_mid_group_END (14)
#define SOC_SC_SEC_RGN_CTRL_ocfg_sec_mid_compare_START (15)
#define SOC_SC_SEC_RGN_CTRL_ocfg_sec_mid_compare_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ocfg_sec_base_addr : 11;
        unsigned int reserved_0 : 5;
        unsigned int ocfg_sec_top_addr : 11;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_SC_SEC_RGN_ADDR_CTRL_UNION;
#endif
#define SOC_SC_SEC_RGN_ADDR_CTRL_ocfg_sec_base_addr_START (0)
#define SOC_SC_SEC_RGN_ADDR_CTRL_ocfg_sec_base_addr_END (10)
#define SOC_SC_SEC_RGN_ADDR_CTRL_ocfg_sec_top_addr_START (16)
#define SOC_SC_SEC_RGN_ADDR_CTRL_ocfg_sec_top_addr_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ocfg_sec_mid_rd : 32;
    } reg;
} SOC_SC_SEC_RGN_MID_CTRL_R_UNION;
#endif
#define SOC_SC_SEC_RGN_MID_CTRL_R_ocfg_sec_mid_rd_START (0)
#define SOC_SC_SEC_RGN_MID_CTRL_R_ocfg_sec_mid_rd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ocfg_sec_mid_wr : 32;
    } reg;
} SOC_SC_SEC_RGN_MID_CTRL_W_UNION;
#endif
#define SOC_SC_SEC_RGN_MID_CTRL_W_ocfg_sec_mid_wr_START (0)
#define SOC_SC_SEC_RGN_MID_CTRL_W_ocfg_sec_mid_wr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_syncbuf_glb_mask_abnml_s : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SC_SYNCBUF_ABNML_INT_S_GLB_MASK_UNION;
#endif
#define SOC_SC_SYNCBUF_ABNML_INT_S_GLB_MASK_int_syncbuf_glb_mask_abnml_s_START (0)
#define SOC_SC_SYNCBUF_ABNML_INT_S_GLB_MASK_int_syncbuf_glb_mask_abnml_s_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_syncbuf_clr_abnml_s : 1;
        unsigned int sw_trig_int_syncbuf_abnml_s : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_SC_SYNCBUF_ABNML_INT_S_CLR_UNION;
#endif
#define SOC_SC_SYNCBUF_ABNML_INT_S_CLR_int_syncbuf_clr_abnml_s_START (0)
#define SOC_SC_SYNCBUF_ABNML_INT_S_CLR_int_syncbuf_clr_abnml_s_END (0)
#define SOC_SC_SYNCBUF_ABNML_INT_S_CLR_sw_trig_int_syncbuf_abnml_s_START (1)
#define SOC_SC_SYNCBUF_ABNML_INT_S_CLR_sw_trig_int_syncbuf_abnml_s_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_syncbuf_mask_abnml_s : 32;
    } reg;
} SOC_SC_SYNCBUF_ABNML_INT_S_MASK_UNION;
#endif
#define SOC_SC_SYNCBUF_ABNML_INT_S_MASK_int_syncbuf_mask_abnml_s_START (0)
#define SOC_SC_SYNCBUF_ABNML_INT_S_MASK_int_syncbuf_mask_abnml_s_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_syncbuf_dis_abnml_s : 32;
    } reg;
} SOC_SC_SYNCBUF_ABNML_INT_S_DIS_UNION;
#endif
#define SOC_SC_SYNCBUF_ABNML_INT_S_DIS_int_syncbuf_dis_abnml_s_START (0)
#define SOC_SC_SYNCBUF_ABNML_INT_S_DIS_int_syncbuf_dis_abnml_s_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_syncbuf_org_status_abnml_s : 32;
    } reg;
} SOC_SC_SYNCBUF_ABNML_INT_S_ORG_STATUS_UNION;
#endif
#define SOC_SC_SYNCBUF_ABNML_INT_S_ORG_STATUS_int_syncbuf_org_status_abnml_s_START (0)
#define SOC_SC_SYNCBUF_ABNML_INT_S_ORG_STATUS_int_syncbuf_org_status_abnml_s_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_syncbuf_mask_status_abnml_s : 32;
    } reg;
} SOC_SC_SYNCBUF_ABNML_INT_S_MASK_STATUS_UNION;
#endif
#define SOC_SC_SYNCBUF_ABNML_INT_S_MASK_STATUS_int_syncbuf_mask_status_abnml_s_START (0)
#define SOC_SC_SYNCBUF_ABNML_INT_S_MASK_STATUS_int_syncbuf_mask_status_abnml_s_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_syncbuf_type_abnml_s : 6;
        unsigned int reserved_0 : 2;
        unsigned int sw_trig_int_syncbuf_type_abnml_s : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_SC_SYNCBUF_ABNML_INT_S_TYPE_UNION;
#endif
#define SOC_SC_SYNCBUF_ABNML_INT_S_TYPE_int_syncbuf_type_abnml_s_START (0)
#define SOC_SC_SYNCBUF_ABNML_INT_S_TYPE_int_syncbuf_type_abnml_s_END (5)
#define SOC_SC_SYNCBUF_ABNML_INT_S_TYPE_sw_trig_int_syncbuf_type_abnml_s_START (8)
#define SOC_SC_SYNCBUF_ABNML_INT_S_TYPE_sw_trig_int_syncbuf_type_abnml_s_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_syncbuf_info_abnml_s : 32;
    } reg;
} SOC_SC_SYNCBUF_ABNML_INT_S_INFO_UNION;
#endif
#define SOC_SC_SYNCBUF_ABNML_INT_S_INFO_int_syncbuf_info_abnml_s_START (0)
#define SOC_SC_SYNCBUF_ABNML_INT_S_INFO_int_syncbuf_info_abnml_s_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ocfg_glb_remap_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SC_GLB_REMAP_CTRL_UNION;
#endif
#define SOC_SC_GLB_REMAP_CTRL_ocfg_glb_remap_en_START (0)
#define SOC_SC_GLB_REMAP_CTRL_ocfg_glb_remap_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ocfg_addr_remap_x0 : 5;
        unsigned int reserved_0 : 3;
        unsigned int ocfg_addr_remap_x1 : 5;
        unsigned int reserved_1 : 3;
        unsigned int ocfg_addr_remap_x2 : 5;
        unsigned int reserved_2 : 3;
        unsigned int ocfg_addr_remap_x3 : 5;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_SC_BC_ADDR_REMAP0_UNION;
#endif
#define SOC_SC_BC_ADDR_REMAP0_ocfg_addr_remap_x0_START (0)
#define SOC_SC_BC_ADDR_REMAP0_ocfg_addr_remap_x0_END (4)
#define SOC_SC_BC_ADDR_REMAP0_ocfg_addr_remap_x1_START (8)
#define SOC_SC_BC_ADDR_REMAP0_ocfg_addr_remap_x1_END (12)
#define SOC_SC_BC_ADDR_REMAP0_ocfg_addr_remap_x2_START (16)
#define SOC_SC_BC_ADDR_REMAP0_ocfg_addr_remap_x2_END (20)
#define SOC_SC_BC_ADDR_REMAP0_ocfg_addr_remap_x3_START (24)
#define SOC_SC_BC_ADDR_REMAP0_ocfg_addr_remap_x3_END (28)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
