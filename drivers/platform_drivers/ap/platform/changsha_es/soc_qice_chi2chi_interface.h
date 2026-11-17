#ifndef __SOC_QICE_CHI2CHI_INTERFACE_H__
#define __SOC_QICE_CHI2CHI_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QICE_CHI2CHI_CMD_TYPE_EN_ADDR(base) (base)
#define SOC_QICE_CHI2CHI_GID_MAP_0_ADDR(base) ((base) + 0x0004UL)
#define SOC_QICE_CHI2CHI_GID_MAP_1_ADDR(base) ((base) + 0x0008UL)
#define SOC_QICE_CHI2CHI_GID_MAP_2_ADDR(base) ((base) + 0x000CUL)
#define SOC_QICE_CHI2CHI_CMD_FLOW_CTRL_ADDR(base) ((base) + 0x0010UL)
#define SOC_QICE_CHI2CHI_INT_STATUS_RAW_ADDR(base) ((base) + 0x0014UL)
#define SOC_QICE_CHI2CHI_INT_STATUS_STATUS_ADDR(base) ((base) + 0x0018UL)
#define SOC_QICE_CHI2CHI_INT_EN_ADDR(base) ((base) + 0x001CUL)
#define SOC_QICE_CHI2CHI_INT_CLR_ADDR(base) ((base) + 0x0020UL)
#define SOC_QICE_CHI2CHI_INT_TYPE_ADDR(base) ((base) + 0x0024UL)
#define SOC_QICE_CHI2CHI_INT_INFO_0_ADDR(base) ((base) + 0x0028UL)
#define SOC_QICE_CHI2CHI_INT_INFO_1_ADDR(base) ((base) + 0x002CUL)
#define SOC_QICE_CHI2CHI_INT_INFO_2_ADDR(base) ((base) + 0x0030UL)
#define SOC_QICE_CHI2CHI_INT_INFO_3_ADDR(base) ((base) + 0x0034UL)
#define SOC_QICE_CHI2CHI_LINK_ACTIVE_ADDR(base) ((base) + 0x0038UL)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ADDR(base) ((base) + 0x003CUL)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ADDR(base) ((base) + 0x0040UL)
#define SOC_QICE_CHI2CHI_DEF_SLV_SEL_ADDR(base) ((base) + 0x0044UL)
#define SOC_QICE_CHI2CHI_DEF_SLV_SLOT_VLD_ADDR(base) ((base) + 0x0048UL)
#define SOC_QICE_CHI2CHI_DEF_SLV_SLOT_INFO_0_ADDR(base) ((base) + 0x004CUL)
#define SOC_QICE_CHI2CHI_DEF_SLV_SLOT_INFO_1_ADDR(base) ((base) + 0x0050UL)
#define SOC_QICE_CHI2CHI_DEF_SLV_SLOT_MSG_INFO_ADDR(base) ((base) + 0x0054UL)
#define SOC_QICE_CHI2CHI_CHI_MST_ACTIVE_ADDR(base) ((base) + 0x0058UL)
#define SOC_QICE_CHI2CHI_CHI_SLV_ACTIVE_ADDR(base) ((base) + 0x005CUL)
#define SOC_QICE_CHI2CHI_CHI_MST_CREDIT_CNT_ADDR(base) ((base) + 0x0060UL)
#define SOC_QICE_CHI2CHI_CHI_SLV_CREDIT_CNT_ADDR(base) ((base) + 0x0064UL)
#define SOC_QICE_CHI2CHI_NON_CACHEABLE_FORCE_ADDR(base) ((base) + 0x0800UL)
#define SOC_QICE_CHI2CHI_SEC_RGN_CTRL_ADDR(base) ((base) + 0x0C00UL)
#define SOC_QICE_CHI2CHI_EACH_SEC_RGN_CFG_0_ADDR(base,SEC_RGN_NUM) ((base) + 4 * (SEC_RGN_NUM) + 0xC04UL)
#define SOC_QICE_CHI2CHI_EACH_SEC_RGN_CFG_1_ADDR(base,SEC_RGN_NUM) ((base) + 4 * (SEC_RGN_NUM) + 0xC24UL)
#define SOC_QICE_CHI2CHI_S_CMD_TYPE_EN_ADDR(base) ((base) + 0x0C44UL)
#else
#define SOC_QICE_CHI2CHI_CMD_TYPE_EN_ADDR(base) (base)
#define SOC_QICE_CHI2CHI_GID_MAP_0_ADDR(base) ((base) + 0x0004)
#define SOC_QICE_CHI2CHI_GID_MAP_1_ADDR(base) ((base) + 0x0008)
#define SOC_QICE_CHI2CHI_GID_MAP_2_ADDR(base) ((base) + 0x000C)
#define SOC_QICE_CHI2CHI_CMD_FLOW_CTRL_ADDR(base) ((base) + 0x0010)
#define SOC_QICE_CHI2CHI_INT_STATUS_RAW_ADDR(base) ((base) + 0x0014)
#define SOC_QICE_CHI2CHI_INT_STATUS_STATUS_ADDR(base) ((base) + 0x0018)
#define SOC_QICE_CHI2CHI_INT_EN_ADDR(base) ((base) + 0x001C)
#define SOC_QICE_CHI2CHI_INT_CLR_ADDR(base) ((base) + 0x0020)
#define SOC_QICE_CHI2CHI_INT_TYPE_ADDR(base) ((base) + 0x0024)
#define SOC_QICE_CHI2CHI_INT_INFO_0_ADDR(base) ((base) + 0x0028)
#define SOC_QICE_CHI2CHI_INT_INFO_1_ADDR(base) ((base) + 0x002C)
#define SOC_QICE_CHI2CHI_INT_INFO_2_ADDR(base) ((base) + 0x0030)
#define SOC_QICE_CHI2CHI_INT_INFO_3_ADDR(base) ((base) + 0x0034)
#define SOC_QICE_CHI2CHI_LINK_ACTIVE_ADDR(base) ((base) + 0x0038)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ADDR(base) ((base) + 0x003C)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ADDR(base) ((base) + 0x0040)
#define SOC_QICE_CHI2CHI_DEF_SLV_SEL_ADDR(base) ((base) + 0x0044)
#define SOC_QICE_CHI2CHI_DEF_SLV_SLOT_VLD_ADDR(base) ((base) + 0x0048)
#define SOC_QICE_CHI2CHI_DEF_SLV_SLOT_INFO_0_ADDR(base) ((base) + 0x004C)
#define SOC_QICE_CHI2CHI_DEF_SLV_SLOT_INFO_1_ADDR(base) ((base) + 0x0050)
#define SOC_QICE_CHI2CHI_DEF_SLV_SLOT_MSG_INFO_ADDR(base) ((base) + 0x0054)
#define SOC_QICE_CHI2CHI_CHI_MST_ACTIVE_ADDR(base) ((base) + 0x0058)
#define SOC_QICE_CHI2CHI_CHI_SLV_ACTIVE_ADDR(base) ((base) + 0x005C)
#define SOC_QICE_CHI2CHI_CHI_MST_CREDIT_CNT_ADDR(base) ((base) + 0x0060)
#define SOC_QICE_CHI2CHI_CHI_SLV_CREDIT_CNT_ADDR(base) ((base) + 0x0064)
#define SOC_QICE_CHI2CHI_NON_CACHEABLE_FORCE_ADDR(base) ((base) + 0x0800)
#define SOC_QICE_CHI2CHI_SEC_RGN_CTRL_ADDR(base) ((base) + 0x0C00)
#define SOC_QICE_CHI2CHI_EACH_SEC_RGN_CFG_0_ADDR(base,SEC_RGN_NUM) ((base) + 4 * (SEC_RGN_NUM) + 0xC04)
#define SOC_QICE_CHI2CHI_EACH_SEC_RGN_CFG_1_ADDR(base,SEC_RGN_NUM) ((base) + 4 * (SEC_RGN_NUM) + 0xC24)
#define SOC_QICE_CHI2CHI_S_CMD_TYPE_EN_ADDR(base) ((base) + 0x0C44)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_cmo_en : 1;
        unsigned int icfg_we_en : 1;
        unsigned int icfg_sta_en : 1;
        unsigned int icfg_drc_sta_en : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_CHI2CHI_CMD_TYPE_EN_UNION;
#endif
#define SOC_QICE_CHI2CHI_CMD_TYPE_EN_icfg_cmo_en_START (0)
#define SOC_QICE_CHI2CHI_CMD_TYPE_EN_icfg_cmo_en_END (0)
#define SOC_QICE_CHI2CHI_CMD_TYPE_EN_icfg_we_en_START (1)
#define SOC_QICE_CHI2CHI_CMD_TYPE_EN_icfg_we_en_END (1)
#define SOC_QICE_CHI2CHI_CMD_TYPE_EN_icfg_sta_en_START (2)
#define SOC_QICE_CHI2CHI_CMD_TYPE_EN_icfg_sta_en_END (2)
#define SOC_QICE_CHI2CHI_CMD_TYPE_EN_icfg_drc_sta_en_START (3)
#define SOC_QICE_CHI2CHI_CMD_TYPE_EN_icfg_drc_sta_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_gid_1 : 6;
        unsigned int icfg_gid_2 : 6;
        unsigned int icfg_gid_3 : 6;
        unsigned int icfg_gid_4 : 6;
        unsigned int icfg_gid_5 : 6;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_CHI2CHI_GID_MAP_0_UNION;
#endif
#define SOC_QICE_CHI2CHI_GID_MAP_0_icfg_gid_1_START (0)
#define SOC_QICE_CHI2CHI_GID_MAP_0_icfg_gid_1_END (5)
#define SOC_QICE_CHI2CHI_GID_MAP_0_icfg_gid_2_START (6)
#define SOC_QICE_CHI2CHI_GID_MAP_0_icfg_gid_2_END (11)
#define SOC_QICE_CHI2CHI_GID_MAP_0_icfg_gid_3_START (12)
#define SOC_QICE_CHI2CHI_GID_MAP_0_icfg_gid_3_END (17)
#define SOC_QICE_CHI2CHI_GID_MAP_0_icfg_gid_4_START (18)
#define SOC_QICE_CHI2CHI_GID_MAP_0_icfg_gid_4_END (23)
#define SOC_QICE_CHI2CHI_GID_MAP_0_icfg_gid_5_START (24)
#define SOC_QICE_CHI2CHI_GID_MAP_0_icfg_gid_5_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_gid_6 : 6;
        unsigned int icfg_gid_7 : 6;
        unsigned int icfg_gid_8 : 6;
        unsigned int icfg_gid_9 : 6;
        unsigned int icfg_gid_10 : 6;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_CHI2CHI_GID_MAP_1_UNION;
#endif
#define SOC_QICE_CHI2CHI_GID_MAP_1_icfg_gid_6_START (0)
#define SOC_QICE_CHI2CHI_GID_MAP_1_icfg_gid_6_END (5)
#define SOC_QICE_CHI2CHI_GID_MAP_1_icfg_gid_7_START (6)
#define SOC_QICE_CHI2CHI_GID_MAP_1_icfg_gid_7_END (11)
#define SOC_QICE_CHI2CHI_GID_MAP_1_icfg_gid_8_START (12)
#define SOC_QICE_CHI2CHI_GID_MAP_1_icfg_gid_8_END (17)
#define SOC_QICE_CHI2CHI_GID_MAP_1_icfg_gid_9_START (18)
#define SOC_QICE_CHI2CHI_GID_MAP_1_icfg_gid_9_END (23)
#define SOC_QICE_CHI2CHI_GID_MAP_1_icfg_gid_10_START (24)
#define SOC_QICE_CHI2CHI_GID_MAP_1_icfg_gid_10_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_gid_11 : 6;
        unsigned int icfg_gid_12 : 6;
        unsigned int icfg_gid_13 : 6;
        unsigned int icfg_gid_14 : 6;
        unsigned int icfg_gid_15 : 6;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_CHI2CHI_GID_MAP_2_UNION;
#endif
#define SOC_QICE_CHI2CHI_GID_MAP_2_icfg_gid_11_START (0)
#define SOC_QICE_CHI2CHI_GID_MAP_2_icfg_gid_11_END (5)
#define SOC_QICE_CHI2CHI_GID_MAP_2_icfg_gid_12_START (6)
#define SOC_QICE_CHI2CHI_GID_MAP_2_icfg_gid_12_END (11)
#define SOC_QICE_CHI2CHI_GID_MAP_2_icfg_gid_13_START (12)
#define SOC_QICE_CHI2CHI_GID_MAP_2_icfg_gid_13_END (17)
#define SOC_QICE_CHI2CHI_GID_MAP_2_icfg_gid_14_START (18)
#define SOC_QICE_CHI2CHI_GID_MAP_2_icfg_gid_14_END (23)
#define SOC_QICE_CHI2CHI_GID_MAP_2_icfg_gid_15_START (24)
#define SOC_QICE_CHI2CHI_GID_MAP_2_icfg_gid_15_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_nonsnpattr_force : 1;
        unsigned int icfg_nonexpcompack_force : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_CHI2CHI_CMD_FLOW_CTRL_UNION;
#endif
#define SOC_QICE_CHI2CHI_CMD_FLOW_CTRL_icfg_nonsnpattr_force_START (0)
#define SOC_QICE_CHI2CHI_CMD_FLOW_CTRL_icfg_nonsnpattr_force_END (0)
#define SOC_QICE_CHI2CHI_CMD_FLOW_CTRL_icfg_nonexpcompack_force_START (1)
#define SOC_QICE_CHI2CHI_CMD_FLOW_CTRL_icfg_nonexpcompack_force_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_secrgn_intercept_raw : 1;
        unsigned int int_req_opc_err_raw : 1;
        unsigned int int_wdata_resp_err_raw : 1;
        unsigned int int_excl_intercept_raw : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_CHI2CHI_INT_STATUS_RAW_UNION;
#endif
#define SOC_QICE_CHI2CHI_INT_STATUS_RAW_int_secrgn_intercept_raw_START (0)
#define SOC_QICE_CHI2CHI_INT_STATUS_RAW_int_secrgn_intercept_raw_END (0)
#define SOC_QICE_CHI2CHI_INT_STATUS_RAW_int_req_opc_err_raw_START (1)
#define SOC_QICE_CHI2CHI_INT_STATUS_RAW_int_req_opc_err_raw_END (1)
#define SOC_QICE_CHI2CHI_INT_STATUS_RAW_int_wdata_resp_err_raw_START (2)
#define SOC_QICE_CHI2CHI_INT_STATUS_RAW_int_wdata_resp_err_raw_END (2)
#define SOC_QICE_CHI2CHI_INT_STATUS_RAW_int_excl_intercept_raw_START (3)
#define SOC_QICE_CHI2CHI_INT_STATUS_RAW_int_excl_intercept_raw_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_secrgn_intercept : 1;
        unsigned int int_req_opc_err : 1;
        unsigned int int_wdata_resp_err : 1;
        unsigned int int_excl_intercept : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_CHI2CHI_INT_STATUS_STATUS_UNION;
#endif
#define SOC_QICE_CHI2CHI_INT_STATUS_STATUS_int_secrgn_intercept_START (0)
#define SOC_QICE_CHI2CHI_INT_STATUS_STATUS_int_secrgn_intercept_END (0)
#define SOC_QICE_CHI2CHI_INT_STATUS_STATUS_int_req_opc_err_START (1)
#define SOC_QICE_CHI2CHI_INT_STATUS_STATUS_int_req_opc_err_END (1)
#define SOC_QICE_CHI2CHI_INT_STATUS_STATUS_int_wdata_resp_err_START (2)
#define SOC_QICE_CHI2CHI_INT_STATUS_STATUS_int_wdata_resp_err_END (2)
#define SOC_QICE_CHI2CHI_INT_STATUS_STATUS_int_excl_intercept_START (3)
#define SOC_QICE_CHI2CHI_INT_STATUS_STATUS_int_excl_intercept_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_secrgn_intercept_en : 1;
        unsigned int int_req_opc_err_en : 1;
        unsigned int int_wdata_resp_err_en : 1;
        unsigned int int_excl_intercept_en : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_CHI2CHI_INT_EN_UNION;
#endif
#define SOC_QICE_CHI2CHI_INT_EN_int_secrgn_intercept_en_START (0)
#define SOC_QICE_CHI2CHI_INT_EN_int_secrgn_intercept_en_END (0)
#define SOC_QICE_CHI2CHI_INT_EN_int_req_opc_err_en_START (1)
#define SOC_QICE_CHI2CHI_INT_EN_int_req_opc_err_en_END (1)
#define SOC_QICE_CHI2CHI_INT_EN_int_wdata_resp_err_en_START (2)
#define SOC_QICE_CHI2CHI_INT_EN_int_wdata_resp_err_en_END (2)
#define SOC_QICE_CHI2CHI_INT_EN_int_excl_intercept_en_START (3)
#define SOC_QICE_CHI2CHI_INT_EN_int_excl_intercept_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_secrgn_intercept_clr : 1;
        unsigned int int_req_opc_err_clr : 1;
        unsigned int int_wdata_resp_err_clr : 1;
        unsigned int int_excl_intercept_clr : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_CHI2CHI_INT_CLR_UNION;
#endif
#define SOC_QICE_CHI2CHI_INT_CLR_int_secrgn_intercept_clr_START (0)
#define SOC_QICE_CHI2CHI_INT_CLR_int_secrgn_intercept_clr_END (0)
#define SOC_QICE_CHI2CHI_INT_CLR_int_req_opc_err_clr_START (1)
#define SOC_QICE_CHI2CHI_INT_CLR_int_req_opc_err_clr_END (1)
#define SOC_QICE_CHI2CHI_INT_CLR_int_wdata_resp_err_clr_START (2)
#define SOC_QICE_CHI2CHI_INT_CLR_int_wdata_resp_err_clr_END (2)
#define SOC_QICE_CHI2CHI_INT_CLR_int_excl_intercept_clr_START (3)
#define SOC_QICE_CHI2CHI_INT_CLR_int_excl_intercept_clr_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_type : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_CHI2CHI_INT_TYPE_UNION;
#endif
#define SOC_QICE_CHI2CHI_INT_TYPE_int_type_START (0)
#define SOC_QICE_CHI2CHI_INT_TYPE_int_type_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_info_0 : 32;
    } reg;
} SOC_QICE_CHI2CHI_INT_INFO_0_UNION;
#endif
#define SOC_QICE_CHI2CHI_INT_INFO_0_int_info_0_START (0)
#define SOC_QICE_CHI2CHI_INT_INFO_0_int_info_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_info_1 : 32;
    } reg;
} SOC_QICE_CHI2CHI_INT_INFO_1_UNION;
#endif
#define SOC_QICE_CHI2CHI_INT_INFO_1_int_info_1_START (0)
#define SOC_QICE_CHI2CHI_INT_INFO_1_int_info_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_info_2 : 32;
    } reg;
} SOC_QICE_CHI2CHI_INT_INFO_2_UNION;
#endif
#define SOC_QICE_CHI2CHI_INT_INFO_2_int_info_2_START (0)
#define SOC_QICE_CHI2CHI_INT_INFO_2_int_info_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_info_3 : 32;
    } reg;
} SOC_QICE_CHI2CHI_INT_INFO_3_UNION;
#endif
#define SOC_QICE_CHI2CHI_INT_INFO_3_int_info_3_START (0)
#define SOC_QICE_CHI2CHI_INT_INFO_3_int_info_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int link_active_en : 1;
        unsigned int cur_stat_tx : 2;
        unsigned int cur_stat_rx : 2;
        unsigned int reserved : 27;
    } reg;
} SOC_QICE_CHI2CHI_LINK_ACTIVE_UNION;
#endif
#define SOC_QICE_CHI2CHI_LINK_ACTIVE_link_active_en_START (0)
#define SOC_QICE_CHI2CHI_LINK_ACTIVE_link_active_en_END (0)
#define SOC_QICE_CHI2CHI_LINK_ACTIVE_cur_stat_tx_START (1)
#define SOC_QICE_CHI2CHI_LINK_ACTIVE_cur_stat_tx_END (2)
#define SOC_QICE_CHI2CHI_LINK_ACTIVE_cur_stat_rx_START (3)
#define SOC_QICE_CHI2CHI_LINK_ACTIVE_cur_stat_rx_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ckg_byp_def_slv : 1;
        unsigned int ckg_byp_msg_rt : 1;
        unsigned int ckg_byp_chi_mst_req : 1;
        unsigned int ckg_byp_chi_mst_srsp : 1;
        unsigned int ckg_byp_chi_mst_wdata : 1;
        unsigned int ckg_byp_chi_mst_crsp : 1;
        unsigned int ckg_byp_chi_mst_rdata : 1;
        unsigned int ckg_byp_chi_mst_snp : 1;
        unsigned int ckg_byp_chi_mst_lk : 1;
        unsigned int ckg_byp_chi_slv_req : 1;
        unsigned int ckg_byp_chi_slv_srsp : 1;
        unsigned int ckg_byp_chi_slv_wdata : 1;
        unsigned int ckg_byp_chi_slv_crsp : 1;
        unsigned int ckg_byp_chi_slv_rdata : 1;
        unsigned int ckg_byp_chi_slv_snp : 1;
        unsigned int ckg_byp_apb : 1;
        unsigned int ckg_byp_dfx : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_QICE_CHI2CHI_CFG_CKG_BYP_UNION;
#endif
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_def_slv_START (0)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_def_slv_END (0)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_msg_rt_START (1)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_msg_rt_END (1)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_chi_mst_req_START (2)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_chi_mst_req_END (2)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_chi_mst_srsp_START (3)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_chi_mst_srsp_END (3)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_chi_mst_wdata_START (4)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_chi_mst_wdata_END (4)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_chi_mst_crsp_START (5)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_chi_mst_crsp_END (5)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_chi_mst_rdata_START (6)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_chi_mst_rdata_END (6)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_chi_mst_snp_START (7)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_chi_mst_snp_END (7)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_chi_mst_lk_START (8)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_chi_mst_lk_END (8)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_chi_slv_req_START (9)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_chi_slv_req_END (9)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_chi_slv_srsp_START (10)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_chi_slv_srsp_END (10)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_chi_slv_wdata_START (11)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_chi_slv_wdata_END (11)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_chi_slv_crsp_START (12)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_chi_slv_crsp_END (12)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_chi_slv_rdata_START (13)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_chi_slv_rdata_END (13)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_chi_slv_snp_START (14)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_chi_slv_snp_END (14)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_apb_START (15)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_apb_END (15)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_dfx_START (16)
#define SOC_QICE_CHI2CHI_CFG_CKG_BYP_ckg_byp_dfx_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ckg_def_slv_busy : 1;
        unsigned int ckg_msg_rt_busy : 1;
        unsigned int ckg_chi_mst_req_busy : 1;
        unsigned int ckg_chi_mst_srsp_busy : 1;
        unsigned int ckg_chi_mst_wdata_busy : 1;
        unsigned int ckg_chi_mst_crsp_busy : 1;
        unsigned int ckg_chi_mst_rdata_busy : 1;
        unsigned int ckg_chi_mst_snp_busy : 1;
        unsigned int ckg_chi_mst_lk_busy : 1;
        unsigned int ckg_chi_slv_req_busy : 1;
        unsigned int ckg_chi_slv_srsp_busy : 1;
        unsigned int ckg_chi_slv_wdata_busy : 1;
        unsigned int ckg_chi_slv_crsp_busy : 1;
        unsigned int ckg_chi_slv_rdata_busy : 1;
        unsigned int ckg_chi_slv_snp_busy : 1;
        unsigned int ckg_apb_busy : 1;
        unsigned int ckg_dfx_busy : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_QICE_CHI2CHI_DFX_CKG_BUSY_UNION;
#endif
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_def_slv_busy_START (0)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_def_slv_busy_END (0)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_msg_rt_busy_START (1)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_msg_rt_busy_END (1)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_chi_mst_req_busy_START (2)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_chi_mst_req_busy_END (2)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_chi_mst_srsp_busy_START (3)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_chi_mst_srsp_busy_END (3)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_chi_mst_wdata_busy_START (4)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_chi_mst_wdata_busy_END (4)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_chi_mst_crsp_busy_START (5)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_chi_mst_crsp_busy_END (5)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_chi_mst_rdata_busy_START (6)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_chi_mst_rdata_busy_END (6)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_chi_mst_snp_busy_START (7)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_chi_mst_snp_busy_END (7)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_chi_mst_lk_busy_START (8)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_chi_mst_lk_busy_END (8)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_chi_slv_req_busy_START (9)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_chi_slv_req_busy_END (9)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_chi_slv_srsp_busy_START (10)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_chi_slv_srsp_busy_END (10)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_chi_slv_wdata_busy_START (11)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_chi_slv_wdata_busy_END (11)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_chi_slv_crsp_busy_START (12)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_chi_slv_crsp_busy_END (12)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_chi_slv_rdata_busy_START (13)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_chi_slv_rdata_busy_END (13)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_chi_slv_snp_busy_START (14)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_chi_slv_snp_busy_END (14)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_apb_busy_START (15)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_apb_busy_END (15)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_dfx_busy_START (16)
#define SOC_QICE_CHI2CHI_DFX_CKG_BUSY_ckg_dfx_busy_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_defslv_entry_sel : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_CHI2CHI_DEF_SLV_SEL_UNION;
#endif
#define SOC_QICE_CHI2CHI_DEF_SLV_SEL_icfg_defslv_entry_sel_START (0)
#define SOC_QICE_CHI2CHI_DEF_SLV_SEL_icfg_defslv_entry_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_defslv_slot_vld : 32;
    } reg;
} SOC_QICE_CHI2CHI_DEF_SLV_SLOT_VLD_UNION;
#endif
#define SOC_QICE_CHI2CHI_DEF_SLV_SLOT_VLD_dfx_defslv_slot_vld_START (0)
#define SOC_QICE_CHI2CHI_DEF_SLV_SLOT_VLD_dfx_defslv_slot_vld_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_defslv_slot_info_0 : 32;
    } reg;
} SOC_QICE_CHI2CHI_DEF_SLV_SLOT_INFO_0_UNION;
#endif
#define SOC_QICE_CHI2CHI_DEF_SLV_SLOT_INFO_0_dfx_defslv_slot_info_0_START (0)
#define SOC_QICE_CHI2CHI_DEF_SLV_SLOT_INFO_0_dfx_defslv_slot_info_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_defslv_slot_info_1 : 32;
    } reg;
} SOC_QICE_CHI2CHI_DEF_SLV_SLOT_INFO_1_UNION;
#endif
#define SOC_QICE_CHI2CHI_DEF_SLV_SLOT_INFO_1_dfx_defslv_slot_info_1_START (0)
#define SOC_QICE_CHI2CHI_DEF_SLV_SLOT_INFO_1_dfx_defslv_slot_info_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_defslv_slot_msg_info : 32;
    } reg;
} SOC_QICE_CHI2CHI_DEF_SLV_SLOT_MSG_INFO_UNION;
#endif
#define SOC_QICE_CHI2CHI_DEF_SLV_SLOT_MSG_INFO_dfx_defslv_slot_msg_info_START (0)
#define SOC_QICE_CHI2CHI_DEF_SLV_SLOT_MSG_INFO_dfx_defslv_slot_msg_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int chi_mst_txsactive : 1;
        unsigned int chi_mst_rxsactive : 1;
        unsigned int chi_mst_tx_link_active_req : 1;
        unsigned int chi_mst_tx_link_active_ack : 1;
        unsigned int chi_mst_rx_link_active_req : 1;
        unsigned int chi_mst_rx_link_active_ack : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_QICE_CHI2CHI_CHI_MST_ACTIVE_UNION;
#endif
#define SOC_QICE_CHI2CHI_CHI_MST_ACTIVE_chi_mst_txsactive_START (0)
#define SOC_QICE_CHI2CHI_CHI_MST_ACTIVE_chi_mst_txsactive_END (0)
#define SOC_QICE_CHI2CHI_CHI_MST_ACTIVE_chi_mst_rxsactive_START (1)
#define SOC_QICE_CHI2CHI_CHI_MST_ACTIVE_chi_mst_rxsactive_END (1)
#define SOC_QICE_CHI2CHI_CHI_MST_ACTIVE_chi_mst_tx_link_active_req_START (2)
#define SOC_QICE_CHI2CHI_CHI_MST_ACTIVE_chi_mst_tx_link_active_req_END (2)
#define SOC_QICE_CHI2CHI_CHI_MST_ACTIVE_chi_mst_tx_link_active_ack_START (3)
#define SOC_QICE_CHI2CHI_CHI_MST_ACTIVE_chi_mst_tx_link_active_ack_END (3)
#define SOC_QICE_CHI2CHI_CHI_MST_ACTIVE_chi_mst_rx_link_active_req_START (4)
#define SOC_QICE_CHI2CHI_CHI_MST_ACTIVE_chi_mst_rx_link_active_req_END (4)
#define SOC_QICE_CHI2CHI_CHI_MST_ACTIVE_chi_mst_rx_link_active_ack_START (5)
#define SOC_QICE_CHI2CHI_CHI_MST_ACTIVE_chi_mst_rx_link_active_ack_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int chi_slv_txsactive : 1;
        unsigned int chi_slv_rxsactive : 1;
        unsigned int chi_slv_tx_link_active_req : 1;
        unsigned int chi_slv_tx_link_active_ack : 1;
        unsigned int chi_slv_rx_link_active_req : 1;
        unsigned int chi_slv_rx_link_active_ack : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_QICE_CHI2CHI_CHI_SLV_ACTIVE_UNION;
#endif
#define SOC_QICE_CHI2CHI_CHI_SLV_ACTIVE_chi_slv_txsactive_START (0)
#define SOC_QICE_CHI2CHI_CHI_SLV_ACTIVE_chi_slv_txsactive_END (0)
#define SOC_QICE_CHI2CHI_CHI_SLV_ACTIVE_chi_slv_rxsactive_START (1)
#define SOC_QICE_CHI2CHI_CHI_SLV_ACTIVE_chi_slv_rxsactive_END (1)
#define SOC_QICE_CHI2CHI_CHI_SLV_ACTIVE_chi_slv_tx_link_active_req_START (2)
#define SOC_QICE_CHI2CHI_CHI_SLV_ACTIVE_chi_slv_tx_link_active_req_END (2)
#define SOC_QICE_CHI2CHI_CHI_SLV_ACTIVE_chi_slv_tx_link_active_ack_START (3)
#define SOC_QICE_CHI2CHI_CHI_SLV_ACTIVE_chi_slv_tx_link_active_ack_END (3)
#define SOC_QICE_CHI2CHI_CHI_SLV_ACTIVE_chi_slv_rx_link_active_req_START (4)
#define SOC_QICE_CHI2CHI_CHI_SLV_ACTIVE_chi_slv_rx_link_active_req_END (4)
#define SOC_QICE_CHI2CHI_CHI_SLV_ACTIVE_chi_slv_rx_link_active_ack_START (5)
#define SOC_QICE_CHI2CHI_CHI_SLV_ACTIVE_chi_slv_rx_link_active_ack_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int chi_mst_snp_rx_crd_cnt : 5;
        unsigned int chi_mst_rdata_rx_crd_cnt : 5;
        unsigned int chi_mst_crsp_rx_crd_cnt : 5;
        unsigned int chi_mst_srsp_tx_crd_cnt : 5;
        unsigned int chi_mst_wdata_tx_crd_cnt : 5;
        unsigned int chi_mst_req_tx_crd_cnt : 5;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_CHI2CHI_CHI_MST_CREDIT_CNT_UNION;
#endif
#define SOC_QICE_CHI2CHI_CHI_MST_CREDIT_CNT_chi_mst_snp_rx_crd_cnt_START (0)
#define SOC_QICE_CHI2CHI_CHI_MST_CREDIT_CNT_chi_mst_snp_rx_crd_cnt_END (4)
#define SOC_QICE_CHI2CHI_CHI_MST_CREDIT_CNT_chi_mst_rdata_rx_crd_cnt_START (5)
#define SOC_QICE_CHI2CHI_CHI_MST_CREDIT_CNT_chi_mst_rdata_rx_crd_cnt_END (9)
#define SOC_QICE_CHI2CHI_CHI_MST_CREDIT_CNT_chi_mst_crsp_rx_crd_cnt_START (10)
#define SOC_QICE_CHI2CHI_CHI_MST_CREDIT_CNT_chi_mst_crsp_rx_crd_cnt_END (14)
#define SOC_QICE_CHI2CHI_CHI_MST_CREDIT_CNT_chi_mst_srsp_tx_crd_cnt_START (15)
#define SOC_QICE_CHI2CHI_CHI_MST_CREDIT_CNT_chi_mst_srsp_tx_crd_cnt_END (19)
#define SOC_QICE_CHI2CHI_CHI_MST_CREDIT_CNT_chi_mst_wdata_tx_crd_cnt_START (20)
#define SOC_QICE_CHI2CHI_CHI_MST_CREDIT_CNT_chi_mst_wdata_tx_crd_cnt_END (24)
#define SOC_QICE_CHI2CHI_CHI_MST_CREDIT_CNT_chi_mst_req_tx_crd_cnt_START (25)
#define SOC_QICE_CHI2CHI_CHI_MST_CREDIT_CNT_chi_mst_req_tx_crd_cnt_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int chi_slv_snp_tx_crd_cnt : 5;
        unsigned int chi_slv_rdata_tx_crd_cnt : 5;
        unsigned int chi_slv_crsp_tx_crd_cnt : 5;
        unsigned int chi_slv_srsp_rx_crd_cnt : 5;
        unsigned int chi_slv_wdata_rx_crd_cnt : 5;
        unsigned int chi_slv_req_rx_crd_cnt : 5;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_CHI2CHI_CHI_SLV_CREDIT_CNT_UNION;
#endif
#define SOC_QICE_CHI2CHI_CHI_SLV_CREDIT_CNT_chi_slv_snp_tx_crd_cnt_START (0)
#define SOC_QICE_CHI2CHI_CHI_SLV_CREDIT_CNT_chi_slv_snp_tx_crd_cnt_END (4)
#define SOC_QICE_CHI2CHI_CHI_SLV_CREDIT_CNT_chi_slv_rdata_tx_crd_cnt_START (5)
#define SOC_QICE_CHI2CHI_CHI_SLV_CREDIT_CNT_chi_slv_rdata_tx_crd_cnt_END (9)
#define SOC_QICE_CHI2CHI_CHI_SLV_CREDIT_CNT_chi_slv_crsp_tx_crd_cnt_START (10)
#define SOC_QICE_CHI2CHI_CHI_SLV_CREDIT_CNT_chi_slv_crsp_tx_crd_cnt_END (14)
#define SOC_QICE_CHI2CHI_CHI_SLV_CREDIT_CNT_chi_slv_srsp_rx_crd_cnt_START (15)
#define SOC_QICE_CHI2CHI_CHI_SLV_CREDIT_CNT_chi_slv_srsp_rx_crd_cnt_END (19)
#define SOC_QICE_CHI2CHI_CHI_SLV_CREDIT_CNT_chi_slv_wdata_rx_crd_cnt_START (20)
#define SOC_QICE_CHI2CHI_CHI_SLV_CREDIT_CNT_chi_slv_wdata_rx_crd_cnt_END (24)
#define SOC_QICE_CHI2CHI_CHI_SLV_CREDIT_CNT_chi_slv_req_rx_crd_cnt_START (25)
#define SOC_QICE_CHI2CHI_CHI_SLV_CREDIT_CNT_chi_slv_req_rx_crd_cnt_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_noncacheable_force : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_CHI2CHI_NON_CACHEABLE_FORCE_UNION;
#endif
#define SOC_QICE_CHI2CHI_NON_CACHEABLE_FORCE_icfg_noncacheable_force_START (0)
#define SOC_QICE_CHI2CHI_NON_CACHEABLE_FORCE_icfg_noncacheable_force_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_all_sec_rgn_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_CHI2CHI_SEC_RGN_CTRL_UNION;
#endif
#define SOC_QICE_CHI2CHI_SEC_RGN_CTRL_icfg_all_sec_rgn_en_START (0)
#define SOC_QICE_CHI2CHI_SEC_RGN_CTRL_icfg_all_sec_rgn_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_sec_rgn_base_addr : 20;
        unsigned int reserved : 11;
        unsigned int icfg_each_sec_rgn_en : 1;
    } reg;
} SOC_QICE_CHI2CHI_EACH_SEC_RGN_CFG_0_UNION;
#endif
#define SOC_QICE_CHI2CHI_EACH_SEC_RGN_CFG_0_icfg_sec_rgn_base_addr_START (0)
#define SOC_QICE_CHI2CHI_EACH_SEC_RGN_CFG_0_icfg_sec_rgn_base_addr_END (19)
#define SOC_QICE_CHI2CHI_EACH_SEC_RGN_CFG_0_icfg_each_sec_rgn_en_START (31)
#define SOC_QICE_CHI2CHI_EACH_SEC_RGN_CFG_0_icfg_each_sec_rgn_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_sec_rgn_top_addr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_QICE_CHI2CHI_EACH_SEC_RGN_CFG_1_UNION;
#endif
#define SOC_QICE_CHI2CHI_EACH_SEC_RGN_CFG_1_icfg_sec_rgn_top_addr_START (0)
#define SOC_QICE_CHI2CHI_EACH_SEC_RGN_CFG_1_icfg_sec_rgn_top_addr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_s_cmo_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_CHI2CHI_S_CMD_TYPE_EN_UNION;
#endif
#define SOC_QICE_CHI2CHI_S_CMD_TYPE_EN_icfg_s_cmo_en_START (0)
#define SOC_QICE_CHI2CHI_S_CMD_TYPE_EN_icfg_s_cmo_en_END (0)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
