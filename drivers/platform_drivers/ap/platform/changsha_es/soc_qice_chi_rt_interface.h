#ifndef __SOC_QICE_CHI_RT_INTERFACE_H__
#define __SOC_QICE_CHI_RT_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QICE_CHI_RT_GLB_ADDR_CTRL_ADDR(base) ((base) + 0x0010UL)
#define SOC_QICE_CHI_RT_RT_INFO_ADDR(base) ((base) + 0x0400UL)
#define SOC_QICE_CHI_RT_RT_RESERVED_RW_ADDR(base) ((base) + 0x0404UL)
#define SOC_QICE_CHI_RT_RT_RESERVED_RO_ADDR(base) ((base) + 0x0408UL)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_ADDR(base) ((base) + 0x040CUL)
#define SOC_QICE_CHI_RT_RT_CKG_BYPS_ADDR(base) ((base) + 0x0410UL)
#define SOC_QICE_CHI_RT_RT_MAX_LAT_CFG_ADDR(base) ((base) + 0x0414UL)
#define SOC_QICE_CHI_RT_RT_CKG_EXT_EN_ADDR(base) ((base) + 0x0418UL)
#define SOC_QICE_CHI_RT_RT_OUTPORT_CFC_CTRL_ADDR(base,outp_idx) ((base) + 0x041CUL + (outp_idx) * 0x0040UL)
#define SOC_QICE_CHI_RT_RT_DIS_LOW_LATENCY_CTRL_ADDR(base,inp_idx) ((base) + 0x0420UL + (inp_idx) * 0x0040UL)
#define SOC_QICE_CHI_RT_RT_INPORT_CFC_CTRL_ADDR(base,inp_idx) ((base) + 0x0424UL + (inp_idx) * 0x0040UL)
#define SOC_QICE_CHI_RT_RT_GLB_ST_ADDR(base) ((base) + 0x0e00UL)
#define SOC_QICE_CHI_RT_RT_GLB_INT_ST_ADDR(base) ((base) + 0x0e04UL)
#define SOC_QICE_CHI_RT_RT_MAX_LAT_ST_ADDR(base) ((base) + 0x0e08UL)
#define SOC_QICE_CHI_RT_RT_INPORT_LPC_ST_ADDR(base) ((base) + 0x0e0cUL)
#define SOC_QICE_CHI_RT_RT_OUTPORT_LPC_ST_ADDR(base) ((base) + 0x0e10UL)
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST0_ADDR(base,inp_idx) ((base) + 0x0e14UL + (inp_idx) * 0x0028UL)
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST2_ADDR(base,inp_idx) ((base) + 0x0e18UL + (inp_idx) * 0x0028UL)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_ST_ADDR(base,inp_idx) ((base) + 0x0e1cUL + (inp_idx) * 0x0028UL)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_INI_ADDR(base,inp_idx) ((base) + 0x0e20UL + (inp_idx) * 0x0028UL)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_CLEAR_ADDR(base,inp_idx) ((base) + 0x0e24UL + (inp_idx) * 0x0028UL)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_EN_ADDR(base,inp_idx) ((base) + 0x0e28UL + (inp_idx) * 0x0028UL)
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST4_ADDR(base,inp_idx) ((base) + 0x0e2cUL + (inp_idx) * 0x0028UL)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_SNP_ADDR(base,inp_idx) ((base) + 0x0e30UL + (inp_idx) * 0x0028UL)
#define SOC_QICE_CHI_RT_RT_OUTPORT_DFX_ST0_ADDR(base,outp_idx) ((base) + 0x0e34UL + (outp_idx) * 0x0028UL)
#define SOC_QICE_CHI_RT_RT_OUTPORT_DFX_ST1_ADDR(base,outp_idx) ((base) + 0x0e38UL + (outp_idx) * 0x0028UL)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_INFO0_ADDR(base) ((base) + 0x0fb0UL)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_INFO1_ADDR(base) ((base) + 0x0fb4UL)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_INFO2_ADDR(base) ((base) + 0x0fb8UL)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_INFO3_ADDR(base) ((base) + 0x0fbcUL)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_INFO4_ADDR(base) ((base) + 0x0fc0UL)
#else
#define SOC_QICE_CHI_RT_GLB_ADDR_CTRL_ADDR(base) ((base) + 0x0010)
#define SOC_QICE_CHI_RT_RT_INFO_ADDR(base) ((base) + 0x0400)
#define SOC_QICE_CHI_RT_RT_RESERVED_RW_ADDR(base) ((base) + 0x0404)
#define SOC_QICE_CHI_RT_RT_RESERVED_RO_ADDR(base) ((base) + 0x0408)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_ADDR(base) ((base) + 0x040C)
#define SOC_QICE_CHI_RT_RT_CKG_BYPS_ADDR(base) ((base) + 0x0410)
#define SOC_QICE_CHI_RT_RT_MAX_LAT_CFG_ADDR(base) ((base) + 0x0414)
#define SOC_QICE_CHI_RT_RT_CKG_EXT_EN_ADDR(base) ((base) + 0x0418)
#define SOC_QICE_CHI_RT_RT_OUTPORT_CFC_CTRL_ADDR(base,outp_idx) ((base) + 0x041C + (outp_idx) * 0x0040)
#define SOC_QICE_CHI_RT_RT_DIS_LOW_LATENCY_CTRL_ADDR(base,inp_idx) ((base) + 0x0420 + (inp_idx) * 0x0040)
#define SOC_QICE_CHI_RT_RT_INPORT_CFC_CTRL_ADDR(base,inp_idx) ((base) + 0x0424 + (inp_idx) * 0x0040)
#define SOC_QICE_CHI_RT_RT_GLB_ST_ADDR(base) ((base) + 0x0e00)
#define SOC_QICE_CHI_RT_RT_GLB_INT_ST_ADDR(base) ((base) + 0x0e04)
#define SOC_QICE_CHI_RT_RT_MAX_LAT_ST_ADDR(base) ((base) + 0x0e08)
#define SOC_QICE_CHI_RT_RT_INPORT_LPC_ST_ADDR(base) ((base) + 0x0e0c)
#define SOC_QICE_CHI_RT_RT_OUTPORT_LPC_ST_ADDR(base) ((base) + 0x0e10)
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST0_ADDR(base,inp_idx) ((base) + 0x0e14 + (inp_idx) * 0x0028)
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST2_ADDR(base,inp_idx) ((base) + 0x0e18 + (inp_idx) * 0x0028)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_ST_ADDR(base,inp_idx) ((base) + 0x0e1c + (inp_idx) * 0x0028)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_INI_ADDR(base,inp_idx) ((base) + 0x0e20 + (inp_idx) * 0x0028)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_CLEAR_ADDR(base,inp_idx) ((base) + 0x0e24 + (inp_idx) * 0x0028)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_EN_ADDR(base,inp_idx) ((base) + 0x0e28 + (inp_idx) * 0x0028)
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST4_ADDR(base,inp_idx) ((base) + 0x0e2c + (inp_idx) * 0x0028)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_SNP_ADDR(base,inp_idx) ((base) + 0x0e30 + (inp_idx) * 0x0028)
#define SOC_QICE_CHI_RT_RT_OUTPORT_DFX_ST0_ADDR(base,outp_idx) ((base) + 0x0e34 + (outp_idx) * 0x0028)
#define SOC_QICE_CHI_RT_RT_OUTPORT_DFX_ST1_ADDR(base,outp_idx) ((base) + 0x0e38 + (outp_idx) * 0x0028)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_INFO0_ADDR(base) ((base) + 0x0fb0)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_INFO1_ADDR(base) ((base) + 0x0fb4)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_INFO2_ADDR(base) ((base) + 0x0fb8)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_INFO3_ADDR(base) ((base) + 0x0fbc)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_INFO4_ADDR(base) ((base) + 0x0fc0)
#endif
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
} SOC_QICE_CHI_RT_GLB_ADDR_CTRL_UNION;
#endif
#define SOC_QICE_CHI_RT_GLB_ADDR_CTRL_intlv_gran_START (0)
#define SOC_QICE_CHI_RT_GLB_ADDR_CTRL_intlv_gran_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rt_info : 32;
    } reg;
} SOC_QICE_CHI_RT_RT_INFO_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_INFO_rt_info_START (0)
#define SOC_QICE_CHI_RT_RT_INFO_rt_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rt_reserved_rw : 32;
    } reg;
} SOC_QICE_CHI_RT_RT_RESERVED_RW_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_RESERVED_RW_rt_reserved_rw_START (0)
#define SOC_QICE_CHI_RT_RT_RESERVED_RW_rt_reserved_rw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rt_reserved_ro : 32;
    } reg;
} SOC_QICE_CHI_RT_RT_RESERVED_RO_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_RESERVED_RO_rt_reserved_ro_START (0)
#define SOC_QICE_CHI_RT_RT_RESERVED_RO_rt_reserved_ro_END (31)
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
} SOC_QICE_CHI_RT_RT_PRI_REMAP_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_0_START (0)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_0_END (1)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_1_START (2)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_1_END (3)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_2_START (4)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_2_END (5)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_3_START (6)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_3_END (7)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_4_START (8)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_4_END (9)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_5_START (10)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_5_END (11)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_6_START (12)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_6_END (13)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_7_START (14)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_7_END (15)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_8_START (16)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_8_END (17)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_9_START (18)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_9_END (19)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_10_START (20)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_10_END (21)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_11_START (22)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_11_END (23)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_12_START (24)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_12_END (25)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_13_START (26)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_13_END (27)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_14_START (28)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_14_END (29)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_15_START (30)
#define SOC_QICE_CHI_RT_RT_PRI_REMAP_pri_map_tbl_15_END (31)
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
} SOC_QICE_CHI_RT_RT_CKG_BYPS_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_CKG_BYPS_ckg_byps_inp_START (0)
#define SOC_QICE_CHI_RT_RT_CKG_BYPS_ckg_byps_inp_END (9)
#define SOC_QICE_CHI_RT_RT_CKG_BYPS_ckg_byps_outp_START (15)
#define SOC_QICE_CHI_RT_RT_CKG_BYPS_ckg_byps_outp_END (24)
#define SOC_QICE_CHI_RT_RT_CKG_BYPS_ckg_byps_inp_cfc_START (29)
#define SOC_QICE_CHI_RT_RT_CKG_BYPS_ckg_byps_inp_cfc_END (29)
#define SOC_QICE_CHI_RT_RT_CKG_BYPS_ckg_byps_nmg_START (30)
#define SOC_QICE_CHI_RT_RT_CKG_BYPS_ckg_byps_nmg_END (30)
#define SOC_QICE_CHI_RT_RT_CKG_BYPS_ckg_byps_outp_cfc_START (31)
#define SOC_QICE_CHI_RT_RT_CKG_BYPS_ckg_byps_outp_cfc_END (31)
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
} SOC_QICE_CHI_RT_RT_MAX_LAT_CFG_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_MAX_LAT_CFG_prescaler_START (0)
#define SOC_QICE_CHI_RT_RT_MAX_LAT_CFG_prescaler_END (2)
#define SOC_QICE_CHI_RT_RT_MAX_LAT_CFG_sat_en_START (8)
#define SOC_QICE_CHI_RT_RT_MAX_LAT_CFG_sat_en_END (8)
#define SOC_QICE_CHI_RT_RT_MAX_LAT_CFG_sat_clr_START (9)
#define SOC_QICE_CHI_RT_RT_MAX_LAT_CFG_sat_clr_END (9)
#define SOC_QICE_CHI_RT_RT_MAX_LAT_CFG_max_lat_inp_START (16)
#define SOC_QICE_CHI_RT_RT_MAX_LAT_CFG_max_lat_inp_END (19)
#define SOC_QICE_CHI_RT_RT_MAX_LAT_CFG_max_lat_outp_START (20)
#define SOC_QICE_CHI_RT_RT_MAX_LAT_CFG_max_lat_outp_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ckg_byps_inp_fifo : 10;
        unsigned int ckg_inp_fifo_busy : 10;
        unsigned int reserved : 11;
        unsigned int icfg_ckg_ext_ena : 1;
    } reg;
} SOC_QICE_CHI_RT_RT_CKG_EXT_EN_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_CKG_EXT_EN_ckg_byps_inp_fifo_START (0)
#define SOC_QICE_CHI_RT_RT_CKG_EXT_EN_ckg_byps_inp_fifo_END (9)
#define SOC_QICE_CHI_RT_RT_CKG_EXT_EN_ckg_inp_fifo_busy_START (10)
#define SOC_QICE_CHI_RT_RT_CKG_EXT_EN_ckg_inp_fifo_busy_END (19)
#define SOC_QICE_CHI_RT_RT_CKG_EXT_EN_icfg_ckg_ext_ena_START (31)
#define SOC_QICE_CHI_RT_RT_CKG_EXT_EN_icfg_ckg_ext_ena_END (31)
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
} SOC_QICE_CHI_RT_RT_OUTPORT_CFC_CTRL_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_OUTPORT_CFC_CTRL_outp_cfc0_saturation_START (8)
#define SOC_QICE_CHI_RT_RT_OUTPORT_CFC_CTRL_outp_cfc0_saturation_END (12)
#define SOC_QICE_CHI_RT_RT_OUTPORT_CFC_CTRL_outp_cfc0_lp_START (24)
#define SOC_QICE_CHI_RT_RT_OUTPORT_CFC_CTRL_outp_cfc0_lp_END (25)
#define SOC_QICE_CHI_RT_RT_OUTPORT_CFC_CTRL_outp_cfc0_en_START (31)
#define SOC_QICE_CHI_RT_RT_OUTPORT_CFC_CTRL_outp_cfc0_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int disable_low_latency : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_CHI_RT_RT_DIS_LOW_LATENCY_CTRL_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_DIS_LOW_LATENCY_CTRL_disable_low_latency_START (0)
#define SOC_QICE_CHI_RT_RT_DIS_LOW_LATENCY_CTRL_disable_low_latency_END (0)
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
} SOC_QICE_CHI_RT_RT_INPORT_CFC_CTRL_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_INPORT_CFC_CTRL_inp_cfc0_bw_START (0)
#define SOC_QICE_CHI_RT_RT_INPORT_CFC_CTRL_inp_cfc0_bw_END (7)
#define SOC_QICE_CHI_RT_RT_INPORT_CFC_CTRL_inp_cfc0_saturation_START (8)
#define SOC_QICE_CHI_RT_RT_INPORT_CFC_CTRL_inp_cfc0_saturation_END (15)
#define SOC_QICE_CHI_RT_RT_INPORT_CFC_CTRL_inp_cfc0_lp_START (24)
#define SOC_QICE_CHI_RT_RT_INPORT_CFC_CTRL_inp_cfc0_lp_END (25)
#define SOC_QICE_CHI_RT_RT_INPORT_CFC_CTRL_inp_cfc0_en_START (31)
#define SOC_QICE_CHI_RT_RT_INPORT_CFC_CTRL_inp_cfc0_en_END (31)
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
} SOC_QICE_CHI_RT_RT_GLB_ST_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_GLB_ST_dfx_inblk_busy_START (0)
#define SOC_QICE_CHI_RT_RT_GLB_ST_dfx_inblk_busy_END (9)
#define SOC_QICE_CHI_RT_RT_GLB_ST_dfx_outblk_busy_START (15)
#define SOC_QICE_CHI_RT_RT_GLB_ST_dfx_outblk_busy_END (24)
#define SOC_QICE_CHI_RT_RT_GLB_ST_dfx_rt_busy_START (30)
#define SOC_QICE_CHI_RT_RT_GLB_ST_dfx_rt_busy_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_inp_err_st : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_QICE_CHI_RT_RT_GLB_INT_ST_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_GLB_INT_ST_dfx_inp_err_st_START (0)
#define SOC_QICE_CHI_RT_RT_GLB_INT_ST_dfx_inp_err_st_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_bp_cnt : 16;
        unsigned int dfx_sat_cnt : 16;
    } reg;
} SOC_QICE_CHI_RT_RT_MAX_LAT_ST_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_MAX_LAT_ST_dfx_bp_cnt_START (0)
#define SOC_QICE_CHI_RT_RT_MAX_LAT_ST_dfx_bp_cnt_END (15)
#define SOC_QICE_CHI_RT_RT_MAX_LAT_ST_dfx_sat_cnt_START (16)
#define SOC_QICE_CHI_RT_RT_MAX_LAT_ST_dfx_sat_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_inp_lpc_req : 10;
        unsigned int dfx_inp_lpc_ack : 10;
        unsigned int reserved : 12;
    } reg;
} SOC_QICE_CHI_RT_RT_INPORT_LPC_ST_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_INPORT_LPC_ST_dfx_inp_lpc_req_START (0)
#define SOC_QICE_CHI_RT_RT_INPORT_LPC_ST_dfx_inp_lpc_req_END (9)
#define SOC_QICE_CHI_RT_RT_INPORT_LPC_ST_dfx_inp_lpc_ack_START (10)
#define SOC_QICE_CHI_RT_RT_INPORT_LPC_ST_dfx_inp_lpc_ack_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_outp_lpc_req : 10;
        unsigned int dfx_outp_lpc_ack : 10;
        unsigned int reserved : 12;
    } reg;
} SOC_QICE_CHI_RT_RT_OUTPORT_LPC_ST_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_OUTPORT_LPC_ST_dfx_outp_lpc_req_START (0)
#define SOC_QICE_CHI_RT_RT_OUTPORT_LPC_ST_dfx_outp_lpc_req_END (9)
#define SOC_QICE_CHI_RT_RT_OUTPORT_LPC_ST_dfx_outp_lpc_ack_START (10)
#define SOC_QICE_CHI_RT_RT_OUTPORT_LPC_ST_dfx_outp_lpc_ack_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_vcfifo_st : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_CHI_RT_RT_INPORT_DFX_ST0_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST0_dfx_vcfifo_st_START (0)
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST0_dfx_vcfifo_st_END (1)
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
} SOC_QICE_CHI_RT_RT_INPORT_DFX_ST2_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST2_dfx_outp0_arbfifo_st_START (0)
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST2_dfx_outp0_arbfifo_st_END (1)
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST2_dfx_outp1_arbfifo_st_START (2)
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST2_dfx_outp1_arbfifo_st_END (3)
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST2_dfx_outp2_arbfifo_st_START (4)
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST2_dfx_outp2_arbfifo_st_END (5)
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST2_dfx_outp3_arbfifo_st_START (6)
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST2_dfx_outp3_arbfifo_st_END (7)
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST2_dfx_outp4_arbfifo_st_START (8)
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST2_dfx_outp4_arbfifo_st_END (9)
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST2_dfx_outp5_arbfifo_st_START (10)
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST2_dfx_outp5_arbfifo_st_END (11)
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST2_dfx_outp6_arbfifo_st_START (12)
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST2_dfx_outp6_arbfifo_st_END (13)
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST2_dfx_outp7_arbfifo_st_START (14)
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST2_dfx_outp7_arbfifo_st_END (15)
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST2_dfx_outp8_arbfifo_st_START (16)
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST2_dfx_outp8_arbfifo_st_END (17)
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST2_dfx_outp9_arbfifo_st_START (18)
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST2_dfx_outp9_arbfifo_st_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_i2o_access_err_st : 1;
        unsigned int dfx_did_ovfl_st : 1;
        unsigned int dfx_rop_ovfl_st : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_QICE_CHI_RT_RT_INPORT_INT_ST_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_INPORT_INT_ST_dfx_i2o_access_err_st_START (0)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_ST_dfx_i2o_access_err_st_END (0)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_ST_dfx_did_ovfl_st_START (1)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_ST_dfx_did_ovfl_st_END (1)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_ST_dfx_rop_ovfl_st_START (2)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_ST_dfx_rop_ovfl_st_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_i2o_access_err_ini : 1;
        unsigned int dfx_did_ovfl_ini : 1;
        unsigned int dfx_rop_ovfl_ini : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_QICE_CHI_RT_RT_INPORT_INT_INI_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_INPORT_INT_INI_dfx_i2o_access_err_ini_START (0)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_INI_dfx_i2o_access_err_ini_END (0)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_INI_dfx_did_ovfl_ini_START (1)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_INI_dfx_did_ovfl_ini_END (1)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_INI_dfx_rop_ovfl_ini_START (2)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_INI_dfx_rop_ovfl_ini_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_err_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_CHI_RT_RT_INPORT_INT_CLEAR_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_INPORT_INT_CLEAR_dfx_err_clr_START (0)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_CLEAR_dfx_err_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_i2o_access_err_en : 1;
        unsigned int dfx_did_ovfl_en : 1;
        unsigned int dfx_rop_ovfl_en : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_QICE_CHI_RT_RT_INPORT_INT_EN_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_INPORT_INT_EN_dfx_i2o_access_err_en_START (0)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_EN_dfx_i2o_access_err_en_END (0)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_EN_dfx_did_ovfl_en_START (1)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_EN_dfx_did_ovfl_en_END (1)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_EN_dfx_rop_ovfl_en_START (2)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_EN_dfx_rop_ovfl_en_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_vc_req : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_QICE_CHI_RT_RT_INPORT_DFX_ST4_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST4_dfx_vc_req_START (0)
#define SOC_QICE_CHI_RT_RT_INPORT_DFX_ST4_dfx_vc_req_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_i2o_access_err_snap : 1;
        unsigned int dfx_did_ovfl_snap : 1;
        unsigned int dfx_rop_ovfl_snap : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_QICE_CHI_RT_RT_INPORT_INT_SNP_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_INPORT_INT_SNP_dfx_i2o_access_err_snap_START (0)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_SNP_dfx_i2o_access_err_snap_END (0)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_SNP_dfx_did_ovfl_snap_START (1)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_SNP_dfx_did_ovfl_snap_END (1)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_SNP_dfx_rop_ovfl_snap_START (2)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_SNP_dfx_rop_ovfl_snap_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_vc_crdt_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_CHI_RT_RT_OUTPORT_DFX_ST0_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_OUTPORT_DFX_ST0_dfx_vc_crdt_cnt_START (0)
#define SOC_QICE_CHI_RT_RT_OUTPORT_DFX_ST0_dfx_vc_crdt_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_vccrdt_vld : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_CHI_RT_RT_OUTPORT_DFX_ST1_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_OUTPORT_DFX_ST1_dfx_vccrdt_vld_START (0)
#define SOC_QICE_CHI_RT_RT_OUTPORT_DFX_ST1_dfx_vccrdt_vld_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_inp_err_info0 : 32;
    } reg;
} SOC_QICE_CHI_RT_RT_INPORT_INT_INFO0_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_INPORT_INT_INFO0_dfx_inp_err_info0_START (0)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_INFO0_dfx_inp_err_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_inp_err_info1 : 32;
    } reg;
} SOC_QICE_CHI_RT_RT_INPORT_INT_INFO1_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_INPORT_INT_INFO1_dfx_inp_err_info1_START (0)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_INFO1_dfx_inp_err_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_inp_err_info2 : 32;
    } reg;
} SOC_QICE_CHI_RT_RT_INPORT_INT_INFO2_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_INPORT_INT_INFO2_dfx_inp_err_info2_START (0)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_INFO2_dfx_inp_err_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_inp_err_info3 : 32;
    } reg;
} SOC_QICE_CHI_RT_RT_INPORT_INT_INFO3_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_INPORT_INT_INFO3_dfx_inp_err_info3_START (0)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_INFO3_dfx_inp_err_info3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_inp_err_info4 : 32;
    } reg;
} SOC_QICE_CHI_RT_RT_INPORT_INT_INFO4_UNION;
#endif
#define SOC_QICE_CHI_RT_RT_INPORT_INT_INFO4_dfx_inp_err_info4_START (0)
#define SOC_QICE_CHI_RT_RT_INPORT_INT_INFO4_dfx_inp_err_info4_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
