#ifndef __SOC_QICE_QTPE_WA_INTERFACE_H__
#define __SOC_QICE_QTPE_WA_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QICE_QTPE_WA_WA_INFO_ADDR(base) (base)
#define SOC_QICE_QTPE_WA_WA_RESERVED_RW_ADDR(base) ((base) + 0x0004UL)
#define SOC_QICE_QTPE_WA_WA_RESERVED_RO_ADDR(base) ((base) + 0x0008UL)
#define SOC_QICE_QTPE_WA_WA_CKG_BYPS_ADDR(base) ((base) + 0x000CUL)
#define SOC_QICE_QTPE_WA_WA_GLB_CTRL_ADDR(base) ((base) + 0x0030UL)
#define SOC_QICE_QTPE_WA_WA_ST_ADDR(base) ((base) + 0x0010UL)
#define SOC_QICE_QTPE_WA_WA_INI_ST_ADDR(base) ((base) + 0x0014UL)
#define SOC_QICE_QTPE_WA_WA_INT_INI_ADDR(base) ((base) + 0x0018UL)
#define SOC_QICE_QTPE_WA_WA_INT_CLEAR_ADDR(base) ((base) + 0x001CUL)
#define SOC_QICE_QTPE_WA_WA_INT_EN_ADDR(base) ((base) + 0x0020UL)
#define SOC_QICE_QTPE_WA_WA_MAX_LAT_CFG_ADDR(base) ((base) + 0x0024UL)
#define SOC_QICE_QTPE_WA_WA_MAX_LAT_ST_ADDR(base) ((base) + 0x0028UL)
#define SOC_QICE_QTPE_WA_WA_LPC_CTRL_ADDR(base) ((base) + 0x002CUL)
#define SOC_QICE_QTPE_WA_WA_INT_SNAP_ADDR(base) ((base) + 0x0038UL)
#define SOC_QICE_QTPE_WA_WA_LPC_ST_ADDR(base) ((base) + 0x0034UL)
#define SOC_QICE_QTPE_WA_WA_SFW_CTRL_ADDR(base) ((base) + 0x0100UL)
#define SOC_QICE_QTPE_WA_WA_INPORT_DFX_ST0_ADDR(base) ((base) + 0x0104UL)
#define SOC_QICE_QTPE_WA_WA_MEM_CTRL_ADDR(base) ((base) + 0x0108UL)
#define SOC_QICE_QTPE_WA_WA_OUTPORT_DFX_ST0_ADDR(base) ((base) + 0x0404UL)
#define SOC_QICE_QTPE_WA_WA_OUTPORT_DFX_ST1_ADDR(base) ((base) + 0x0408UL)
#else
#define SOC_QICE_QTPE_WA_WA_INFO_ADDR(base) (base)
#define SOC_QICE_QTPE_WA_WA_RESERVED_RW_ADDR(base) ((base) + 0x0004)
#define SOC_QICE_QTPE_WA_WA_RESERVED_RO_ADDR(base) ((base) + 0x0008)
#define SOC_QICE_QTPE_WA_WA_CKG_BYPS_ADDR(base) ((base) + 0x000C)
#define SOC_QICE_QTPE_WA_WA_GLB_CTRL_ADDR(base) ((base) + 0x0030)
#define SOC_QICE_QTPE_WA_WA_ST_ADDR(base) ((base) + 0x0010)
#define SOC_QICE_QTPE_WA_WA_INI_ST_ADDR(base) ((base) + 0x0014)
#define SOC_QICE_QTPE_WA_WA_INT_INI_ADDR(base) ((base) + 0x0018)
#define SOC_QICE_QTPE_WA_WA_INT_CLEAR_ADDR(base) ((base) + 0x001C)
#define SOC_QICE_QTPE_WA_WA_INT_EN_ADDR(base) ((base) + 0x0020)
#define SOC_QICE_QTPE_WA_WA_MAX_LAT_CFG_ADDR(base) ((base) + 0x0024)
#define SOC_QICE_QTPE_WA_WA_MAX_LAT_ST_ADDR(base) ((base) + 0x0028)
#define SOC_QICE_QTPE_WA_WA_LPC_CTRL_ADDR(base) ((base) + 0x002C)
#define SOC_QICE_QTPE_WA_WA_INT_SNAP_ADDR(base) ((base) + 0x0038)
#define SOC_QICE_QTPE_WA_WA_LPC_ST_ADDR(base) ((base) + 0x0034)
#define SOC_QICE_QTPE_WA_WA_SFW_CTRL_ADDR(base) ((base) + 0x0100)
#define SOC_QICE_QTPE_WA_WA_INPORT_DFX_ST0_ADDR(base) ((base) + 0x0104)
#define SOC_QICE_QTPE_WA_WA_MEM_CTRL_ADDR(base) ((base) + 0x0108)
#define SOC_QICE_QTPE_WA_WA_OUTPORT_DFX_ST0_ADDR(base) ((base) + 0x0404)
#define SOC_QICE_QTPE_WA_WA_OUTPORT_DFX_ST1_ADDR(base) ((base) + 0x0408)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wa_info : 32;
    } reg;
} SOC_QICE_QTPE_WA_WA_INFO_UNION;
#endif
#define SOC_QICE_QTPE_WA_WA_INFO_wa_info_START (0)
#define SOC_QICE_QTPE_WA_WA_INFO_wa_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wa_reserved_rw : 32;
    } reg;
} SOC_QICE_QTPE_WA_WA_RESERVED_RW_UNION;
#endif
#define SOC_QICE_QTPE_WA_WA_RESERVED_RW_wa_reserved_rw_START (0)
#define SOC_QICE_QTPE_WA_WA_RESERVED_RW_wa_reserved_rw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wa_reserved_ro : 32;
    } reg;
} SOC_QICE_QTPE_WA_WA_RESERVED_RO_UNION;
#endif
#define SOC_QICE_QTPE_WA_WA_RESERVED_RO_wa_reserved_ro_START (0)
#define SOC_QICE_QTPE_WA_WA_RESERVED_RO_wa_reserved_ro_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ckg_byps_inp : 1;
        unsigned int ckg_byps_outp : 1;
        unsigned int ckg_byps_nmg : 1;
        unsigned int ckg_byps_rs : 1;
        unsigned int ckg_byps_txfifo : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_QICE_QTPE_WA_WA_CKG_BYPS_UNION;
#endif
#define SOC_QICE_QTPE_WA_WA_CKG_BYPS_ckg_byps_inp_START (0)
#define SOC_QICE_QTPE_WA_WA_CKG_BYPS_ckg_byps_inp_END (0)
#define SOC_QICE_QTPE_WA_WA_CKG_BYPS_ckg_byps_outp_START (1)
#define SOC_QICE_QTPE_WA_WA_CKG_BYPS_ckg_byps_outp_END (1)
#define SOC_QICE_QTPE_WA_WA_CKG_BYPS_ckg_byps_nmg_START (2)
#define SOC_QICE_QTPE_WA_WA_CKG_BYPS_ckg_byps_nmg_END (2)
#define SOC_QICE_QTPE_WA_WA_CKG_BYPS_ckg_byps_rs_START (3)
#define SOC_QICE_QTPE_WA_WA_CKG_BYPS_ckg_byps_rs_END (3)
#define SOC_QICE_QTPE_WA_WA_CKG_BYPS_ckg_byps_txfifo_START (4)
#define SOC_QICE_QTPE_WA_WA_CKG_BYPS_ckg_byps_txfifo_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sync_ctrl_push : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_QTPE_WA_WA_GLB_CTRL_UNION;
#endif
#define SOC_QICE_QTPE_WA_WA_GLB_CTRL_sync_ctrl_push_START (0)
#define SOC_QICE_QTPE_WA_WA_GLB_CTRL_sync_ctrl_push_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_inblk_busy : 1;
        unsigned int dfx_outblk_busy : 1;
        unsigned int sync_vld : 1;
        unsigned int dfx_nopend_st : 1;
        unsigned int dfx_wa_sub_busy : 4;
        unsigned int dfx_two2one_busy : 4;
        unsigned int dfx_one2zero_busy : 4;
        unsigned int dfx_wdtr_busy : 4;
        unsigned int dfx_zero2one_busy : 4;
        unsigned int dfx_one2two_busy : 4;
        unsigned int dfx_rs_bp : 4;
    } reg;
} SOC_QICE_QTPE_WA_WA_ST_UNION;
#endif
#define SOC_QICE_QTPE_WA_WA_ST_dfx_inblk_busy_START (0)
#define SOC_QICE_QTPE_WA_WA_ST_dfx_inblk_busy_END (0)
#define SOC_QICE_QTPE_WA_WA_ST_dfx_outblk_busy_START (1)
#define SOC_QICE_QTPE_WA_WA_ST_dfx_outblk_busy_END (1)
#define SOC_QICE_QTPE_WA_WA_ST_sync_vld_START (2)
#define SOC_QICE_QTPE_WA_WA_ST_sync_vld_END (2)
#define SOC_QICE_QTPE_WA_WA_ST_dfx_nopend_st_START (3)
#define SOC_QICE_QTPE_WA_WA_ST_dfx_nopend_st_END (3)
#define SOC_QICE_QTPE_WA_WA_ST_dfx_wa_sub_busy_START (4)
#define SOC_QICE_QTPE_WA_WA_ST_dfx_wa_sub_busy_END (7)
#define SOC_QICE_QTPE_WA_WA_ST_dfx_two2one_busy_START (8)
#define SOC_QICE_QTPE_WA_WA_ST_dfx_two2one_busy_END (11)
#define SOC_QICE_QTPE_WA_WA_ST_dfx_one2zero_busy_START (12)
#define SOC_QICE_QTPE_WA_WA_ST_dfx_one2zero_busy_END (15)
#define SOC_QICE_QTPE_WA_WA_ST_dfx_wdtr_busy_START (16)
#define SOC_QICE_QTPE_WA_WA_ST_dfx_wdtr_busy_END (19)
#define SOC_QICE_QTPE_WA_WA_ST_dfx_zero2one_busy_START (20)
#define SOC_QICE_QTPE_WA_WA_ST_dfx_zero2one_busy_END (23)
#define SOC_QICE_QTPE_WA_WA_ST_dfx_one2two_busy_START (24)
#define SOC_QICE_QTPE_WA_WA_ST_dfx_one2two_busy_END (27)
#define SOC_QICE_QTPE_WA_WA_ST_dfx_rs_bp_START (28)
#define SOC_QICE_QTPE_WA_WA_ST_dfx_rs_bp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_rop_unq_err_st : 1;
        unsigned int dfx_did_unq_err_st : 1;
        unsigned int dfx_vc_access_err_st : 1;
        unsigned int dfx_vc_hop_err_st : 1;
        unsigned int dfx_vc_top_err_st : 1;
        unsigned int dfx_vc_hop_top_err_st : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_QICE_QTPE_WA_WA_INI_ST_UNION;
#endif
#define SOC_QICE_QTPE_WA_WA_INI_ST_dfx_rop_unq_err_st_START (0)
#define SOC_QICE_QTPE_WA_WA_INI_ST_dfx_rop_unq_err_st_END (0)
#define SOC_QICE_QTPE_WA_WA_INI_ST_dfx_did_unq_err_st_START (1)
#define SOC_QICE_QTPE_WA_WA_INI_ST_dfx_did_unq_err_st_END (1)
#define SOC_QICE_QTPE_WA_WA_INI_ST_dfx_vc_access_err_st_START (2)
#define SOC_QICE_QTPE_WA_WA_INI_ST_dfx_vc_access_err_st_END (2)
#define SOC_QICE_QTPE_WA_WA_INI_ST_dfx_vc_hop_err_st_START (3)
#define SOC_QICE_QTPE_WA_WA_INI_ST_dfx_vc_hop_err_st_END (3)
#define SOC_QICE_QTPE_WA_WA_INI_ST_dfx_vc_top_err_st_START (4)
#define SOC_QICE_QTPE_WA_WA_INI_ST_dfx_vc_top_err_st_END (4)
#define SOC_QICE_QTPE_WA_WA_INI_ST_dfx_vc_hop_top_err_st_START (5)
#define SOC_QICE_QTPE_WA_WA_INI_ST_dfx_vc_hop_top_err_st_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_rop_unq_err_ini : 1;
        unsigned int dfx_did_unq_err_ini : 1;
        unsigned int dfx_vc_access_err_ini : 1;
        unsigned int dfx_vc_hop_err_ini : 1;
        unsigned int dfx_vc_top_err_ini : 1;
        unsigned int dfx_vc_hop_top_err_ini : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_QICE_QTPE_WA_WA_INT_INI_UNION;
#endif
#define SOC_QICE_QTPE_WA_WA_INT_INI_dfx_rop_unq_err_ini_START (0)
#define SOC_QICE_QTPE_WA_WA_INT_INI_dfx_rop_unq_err_ini_END (0)
#define SOC_QICE_QTPE_WA_WA_INT_INI_dfx_did_unq_err_ini_START (1)
#define SOC_QICE_QTPE_WA_WA_INT_INI_dfx_did_unq_err_ini_END (1)
#define SOC_QICE_QTPE_WA_WA_INT_INI_dfx_vc_access_err_ini_START (2)
#define SOC_QICE_QTPE_WA_WA_INT_INI_dfx_vc_access_err_ini_END (2)
#define SOC_QICE_QTPE_WA_WA_INT_INI_dfx_vc_hop_err_ini_START (3)
#define SOC_QICE_QTPE_WA_WA_INT_INI_dfx_vc_hop_err_ini_END (3)
#define SOC_QICE_QTPE_WA_WA_INT_INI_dfx_vc_top_err_ini_START (4)
#define SOC_QICE_QTPE_WA_WA_INT_INI_dfx_vc_top_err_ini_END (4)
#define SOC_QICE_QTPE_WA_WA_INT_INI_dfx_vc_hop_top_err_ini_START (5)
#define SOC_QICE_QTPE_WA_WA_INT_INI_dfx_vc_hop_top_err_ini_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_err_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_QTPE_WA_WA_INT_CLEAR_UNION;
#endif
#define SOC_QICE_QTPE_WA_WA_INT_CLEAR_dfx_err_clr_START (0)
#define SOC_QICE_QTPE_WA_WA_INT_CLEAR_dfx_err_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_rop_unq_err_en : 1;
        unsigned int dfx_did_unq_err_en : 1;
        unsigned int dfx_vc_access_err_en : 1;
        unsigned int dfx_vc_hop_err_en : 1;
        unsigned int dfx_vc_top_err_en : 1;
        unsigned int dfx_vc_hop_top_err_en : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_QICE_QTPE_WA_WA_INT_EN_UNION;
#endif
#define SOC_QICE_QTPE_WA_WA_INT_EN_dfx_rop_unq_err_en_START (0)
#define SOC_QICE_QTPE_WA_WA_INT_EN_dfx_rop_unq_err_en_END (0)
#define SOC_QICE_QTPE_WA_WA_INT_EN_dfx_did_unq_err_en_START (1)
#define SOC_QICE_QTPE_WA_WA_INT_EN_dfx_did_unq_err_en_END (1)
#define SOC_QICE_QTPE_WA_WA_INT_EN_dfx_vc_access_err_en_START (2)
#define SOC_QICE_QTPE_WA_WA_INT_EN_dfx_vc_access_err_en_END (2)
#define SOC_QICE_QTPE_WA_WA_INT_EN_dfx_vc_hop_err_en_START (3)
#define SOC_QICE_QTPE_WA_WA_INT_EN_dfx_vc_hop_err_en_END (3)
#define SOC_QICE_QTPE_WA_WA_INT_EN_dfx_vc_top_err_en_START (4)
#define SOC_QICE_QTPE_WA_WA_INT_EN_dfx_vc_top_err_en_END (4)
#define SOC_QICE_QTPE_WA_WA_INT_EN_dfx_vc_hop_top_err_en_START (5)
#define SOC_QICE_QTPE_WA_WA_INT_EN_dfx_vc_hop_top_err_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int prescaler : 3;
        unsigned int reserved_0 : 5;
        unsigned int sat_en : 1;
        unsigned int sat_clr : 1;
        unsigned int reserved_1 : 2;
        unsigned int max_lat_vc : 4;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_QICE_QTPE_WA_WA_MAX_LAT_CFG_UNION;
#endif
#define SOC_QICE_QTPE_WA_WA_MAX_LAT_CFG_prescaler_START (0)
#define SOC_QICE_QTPE_WA_WA_MAX_LAT_CFG_prescaler_END (2)
#define SOC_QICE_QTPE_WA_WA_MAX_LAT_CFG_sat_en_START (8)
#define SOC_QICE_QTPE_WA_WA_MAX_LAT_CFG_sat_en_END (8)
#define SOC_QICE_QTPE_WA_WA_MAX_LAT_CFG_sat_clr_START (9)
#define SOC_QICE_QTPE_WA_WA_MAX_LAT_CFG_sat_clr_END (9)
#define SOC_QICE_QTPE_WA_WA_MAX_LAT_CFG_max_lat_vc_START (12)
#define SOC_QICE_QTPE_WA_WA_MAX_LAT_CFG_max_lat_vc_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_bp_cnt : 16;
        unsigned int dfx_sat_cnt : 16;
    } reg;
} SOC_QICE_QTPE_WA_WA_MAX_LAT_ST_UNION;
#endif
#define SOC_QICE_QTPE_WA_WA_MAX_LAT_ST_dfx_bp_cnt_START (0)
#define SOC_QICE_QTPE_WA_WA_MAX_LAT_ST_dfx_bp_cnt_END (15)
#define SOC_QICE_QTPE_WA_WA_MAX_LAT_ST_dfx_sat_cnt_START (16)
#define SOC_QICE_QTPE_WA_WA_MAX_LAT_ST_dfx_sat_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int inp_lpc_ctrl : 1;
        unsigned int inp_lpc_req_sft : 1;
        unsigned int outp_lpc_ctrl : 1;
        unsigned int outp_lpc_req_sft : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_QTPE_WA_WA_LPC_CTRL_UNION;
#endif
#define SOC_QICE_QTPE_WA_WA_LPC_CTRL_inp_lpc_ctrl_START (0)
#define SOC_QICE_QTPE_WA_WA_LPC_CTRL_inp_lpc_ctrl_END (0)
#define SOC_QICE_QTPE_WA_WA_LPC_CTRL_inp_lpc_req_sft_START (1)
#define SOC_QICE_QTPE_WA_WA_LPC_CTRL_inp_lpc_req_sft_END (1)
#define SOC_QICE_QTPE_WA_WA_LPC_CTRL_outp_lpc_ctrl_START (2)
#define SOC_QICE_QTPE_WA_WA_LPC_CTRL_outp_lpc_ctrl_END (2)
#define SOC_QICE_QTPE_WA_WA_LPC_CTRL_outp_lpc_req_sft_START (3)
#define SOC_QICE_QTPE_WA_WA_LPC_CTRL_outp_lpc_req_sft_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_rop_unq_err_snap : 1;
        unsigned int dfx_did_unq_err_snap : 1;
        unsigned int dfx_vc_access_err_snap : 1;
        unsigned int dfx_vc_hop_err_snap : 1;
        unsigned int dfx_vc_top_err_snap : 1;
        unsigned int dfx_vc_hop_top_err_snap : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_QICE_QTPE_WA_WA_INT_SNAP_UNION;
#endif
#define SOC_QICE_QTPE_WA_WA_INT_SNAP_dfx_rop_unq_err_snap_START (0)
#define SOC_QICE_QTPE_WA_WA_INT_SNAP_dfx_rop_unq_err_snap_END (0)
#define SOC_QICE_QTPE_WA_WA_INT_SNAP_dfx_did_unq_err_snap_START (1)
#define SOC_QICE_QTPE_WA_WA_INT_SNAP_dfx_did_unq_err_snap_END (1)
#define SOC_QICE_QTPE_WA_WA_INT_SNAP_dfx_vc_access_err_snap_START (2)
#define SOC_QICE_QTPE_WA_WA_INT_SNAP_dfx_vc_access_err_snap_END (2)
#define SOC_QICE_QTPE_WA_WA_INT_SNAP_dfx_vc_hop_err_snap_START (3)
#define SOC_QICE_QTPE_WA_WA_INT_SNAP_dfx_vc_hop_err_snap_END (3)
#define SOC_QICE_QTPE_WA_WA_INT_SNAP_dfx_vc_top_err_snap_START (4)
#define SOC_QICE_QTPE_WA_WA_INT_SNAP_dfx_vc_top_err_snap_END (4)
#define SOC_QICE_QTPE_WA_WA_INT_SNAP_dfx_vc_hop_top_err_snap_START (5)
#define SOC_QICE_QTPE_WA_WA_INT_SNAP_dfx_vc_hop_top_err_snap_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_inp_lpc_req : 1;
        unsigned int dfx_inp_lpc_ack : 1;
        unsigned int dfx_outp_lpc_req : 1;
        unsigned int dfx_outp_lpc_ack : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_QTPE_WA_WA_LPC_ST_UNION;
#endif
#define SOC_QICE_QTPE_WA_WA_LPC_ST_dfx_inp_lpc_req_START (0)
#define SOC_QICE_QTPE_WA_WA_LPC_ST_dfx_inp_lpc_req_END (0)
#define SOC_QICE_QTPE_WA_WA_LPC_ST_dfx_inp_lpc_ack_START (1)
#define SOC_QICE_QTPE_WA_WA_LPC_ST_dfx_inp_lpc_ack_END (1)
#define SOC_QICE_QTPE_WA_WA_LPC_ST_dfx_outp_lpc_req_START (2)
#define SOC_QICE_QTPE_WA_WA_LPC_ST_dfx_outp_lpc_req_END (2)
#define SOC_QICE_QTPE_WA_WA_LPC_ST_dfx_outp_lpc_ack_START (3)
#define SOC_QICE_QTPE_WA_WA_LPC_ST_dfx_outp_lpc_ack_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fifo_sfw_en : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_QTPE_WA_WA_SFW_CTRL_UNION;
#endif
#define SOC_QICE_QTPE_WA_WA_SFW_CTRL_fifo_sfw_en_START (0)
#define SOC_QICE_QTPE_WA_WA_SFW_CTRL_fifo_sfw_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_vcfifo_st : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_QTPE_WA_WA_INPORT_DFX_ST0_UNION;
#endif
#define SOC_QICE_QTPE_WA_WA_INPORT_DFX_ST0_dfx_vcfifo_st_START (0)
#define SOC_QICE_QTPE_WA_WA_INPORT_DFX_ST0_dfx_vcfifo_st_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_tpmem_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_QTPE_WA_WA_MEM_CTRL_UNION;
#endif
#define SOC_QICE_QTPE_WA_WA_MEM_CTRL_icfg_tpmem_ctrl_START (0)
#define SOC_QICE_QTPE_WA_WA_MEM_CTRL_icfg_tpmem_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_vc0_crdt_cnt : 8;
        unsigned int dfx_vc1_crdt_cnt : 8;
        unsigned int dfx_vc2_crdt_cnt : 8;
        unsigned int dfx_vc3_crdt_cnt : 8;
    } reg;
} SOC_QICE_QTPE_WA_WA_OUTPORT_DFX_ST0_UNION;
#endif
#define SOC_QICE_QTPE_WA_WA_OUTPORT_DFX_ST0_dfx_vc0_crdt_cnt_START (0)
#define SOC_QICE_QTPE_WA_WA_OUTPORT_DFX_ST0_dfx_vc0_crdt_cnt_END (7)
#define SOC_QICE_QTPE_WA_WA_OUTPORT_DFX_ST0_dfx_vc1_crdt_cnt_START (8)
#define SOC_QICE_QTPE_WA_WA_OUTPORT_DFX_ST0_dfx_vc1_crdt_cnt_END (15)
#define SOC_QICE_QTPE_WA_WA_OUTPORT_DFX_ST0_dfx_vc2_crdt_cnt_START (16)
#define SOC_QICE_QTPE_WA_WA_OUTPORT_DFX_ST0_dfx_vc2_crdt_cnt_END (23)
#define SOC_QICE_QTPE_WA_WA_OUTPORT_DFX_ST0_dfx_vc3_crdt_cnt_START (24)
#define SOC_QICE_QTPE_WA_WA_OUTPORT_DFX_ST0_dfx_vc3_crdt_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_vccrdt_vld : 4;
        unsigned int dfx_sfwfifo_st : 8;
        unsigned int reserved : 20;
    } reg;
} SOC_QICE_QTPE_WA_WA_OUTPORT_DFX_ST1_UNION;
#endif
#define SOC_QICE_QTPE_WA_WA_OUTPORT_DFX_ST1_dfx_vccrdt_vld_START (0)
#define SOC_QICE_QTPE_WA_WA_OUTPORT_DFX_ST1_dfx_vccrdt_vld_END (3)
#define SOC_QICE_QTPE_WA_WA_OUTPORT_DFX_ST1_dfx_sfwfifo_st_START (4)
#define SOC_QICE_QTPE_WA_WA_OUTPORT_DFX_ST1_dfx_sfwfifo_st_END (11)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
