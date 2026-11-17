#ifndef __SOC_QICE_RT_INTERFACE_H__
#define __SOC_QICE_RT_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QICE_RT_RT_INFO_ADDR(base) ((base) + 0x0400UL)
#define SOC_QICE_RT_RT_RESERVED_RW_ADDR(base) ((base) + 0x0404UL)
#define SOC_QICE_RT_RT_RESERVED_RO_ADDR(base) ((base) + 0x0408UL)
#define SOC_QICE_RT_RT_CKG_BYPS_ADDR(base) ((base) + 0x040CUL)
#define SOC_QICE_RT_RT_MAX_LAT_CFG_ADDR(base) ((base) + 0x0410UL)
#define SOC_QICE_RT_RT_CKG_EXT_EN_ADDR(base) ((base) + 0x0414UL)
#define SOC_QICE_RT_RT_OUTPORT_CFC_CTRL_ADDR(base,outp_idx) ((base) + 0x0418UL + (outp_idx) * 0x0020UL)
#define SOC_QICE_RT_RT_DIS_LOW_LATENCY_CTRL_ADDR(base,inp_idx) ((base) + 0x041cUL + (inp_idx) * 0x0020UL)
#define SOC_QICE_RT_RT_GLB_ST_ADDR(base) ((base) + 0x0600UL)
#define SOC_QICE_RT_RT_GLB_INT_ST_ADDR(base) ((base) + 0x0604UL)
#define SOC_QICE_RT_RT_MAX_LAT_ST_ADDR(base) ((base) + 0x0608UL)
#define SOC_QICE_RT_RT_INPORT_LPC_ST_ADDR(base) ((base) + 0x060cUL)
#define SOC_QICE_RT_RT_OUTPORT_LPC_ST_ADDR(base) ((base) + 0x0610UL)
#define SOC_QICE_RT_RT_INPORT_DFX_ST0_ADDR(base,inp_idx) ((base) + 0x0614UL + (inp_idx) * 0x0028UL)
#define SOC_QICE_RT_RT_INPORT_DFX_ST2_ADDR(base,inp_idx) ((base) + 0x0618UL + (inp_idx) * 0x0028UL)
#define SOC_QICE_RT_RT_INPORT_INT_ST_ADDR(base,inp_idx) ((base) + 0x061cUL + (inp_idx) * 0x0028UL)
#define SOC_QICE_RT_RT_INPORT_INT_INI_ADDR(base,inp_idx) ((base) + 0x0620UL + (inp_idx) * 0x0028UL)
#define SOC_QICE_RT_RT_INPORT_INT_CLEAR_ADDR(base,inp_idx) ((base) + 0x0624UL + (inp_idx) * 0x0028UL)
#define SOC_QICE_RT_RT_INPORT_INT_EN_ADDR(base,inp_idx) ((base) + 0x0628UL + (inp_idx) * 0x0028UL)
#define SOC_QICE_RT_RT_INPORT_DFX_ST4_ADDR(base,inp_idx) ((base) + 0x062cUL + (inp_idx) * 0x0028UL)
#define SOC_QICE_RT_RT_INPORT_INT_SNP_ADDR(base,inp_idx) ((base) + 0x0630UL + (inp_idx) * 0x0028UL)
#define SOC_QICE_RT_RT_OUTPORT_DFX_ST0_ADDR(base,outp_idx) ((base) + 0x0634UL + (outp_idx) * 0x0028UL)
#define SOC_QICE_RT_RT_OUTPORT_DFX_ST1_ADDR(base,outp_idx) ((base) + 0x0638UL + (outp_idx) * 0x0028UL)
#else
#define SOC_QICE_RT_RT_INFO_ADDR(base) ((base) + 0x0400)
#define SOC_QICE_RT_RT_RESERVED_RW_ADDR(base) ((base) + 0x0404)
#define SOC_QICE_RT_RT_RESERVED_RO_ADDR(base) ((base) + 0x0408)
#define SOC_QICE_RT_RT_CKG_BYPS_ADDR(base) ((base) + 0x040C)
#define SOC_QICE_RT_RT_MAX_LAT_CFG_ADDR(base) ((base) + 0x0410)
#define SOC_QICE_RT_RT_CKG_EXT_EN_ADDR(base) ((base) + 0x0414)
#define SOC_QICE_RT_RT_OUTPORT_CFC_CTRL_ADDR(base,outp_idx) ((base) + 0x0418 + (outp_idx) * 0x0020)
#define SOC_QICE_RT_RT_DIS_LOW_LATENCY_CTRL_ADDR(base,inp_idx) ((base) + 0x041c + (inp_idx) * 0x0020)
#define SOC_QICE_RT_RT_GLB_ST_ADDR(base) ((base) + 0x0600)
#define SOC_QICE_RT_RT_GLB_INT_ST_ADDR(base) ((base) + 0x0604)
#define SOC_QICE_RT_RT_MAX_LAT_ST_ADDR(base) ((base) + 0x0608)
#define SOC_QICE_RT_RT_INPORT_LPC_ST_ADDR(base) ((base) + 0x060c)
#define SOC_QICE_RT_RT_OUTPORT_LPC_ST_ADDR(base) ((base) + 0x0610)
#define SOC_QICE_RT_RT_INPORT_DFX_ST0_ADDR(base,inp_idx) ((base) + 0x0614 + (inp_idx) * 0x0028)
#define SOC_QICE_RT_RT_INPORT_DFX_ST2_ADDR(base,inp_idx) ((base) + 0x0618 + (inp_idx) * 0x0028)
#define SOC_QICE_RT_RT_INPORT_INT_ST_ADDR(base,inp_idx) ((base) + 0x061c + (inp_idx) * 0x0028)
#define SOC_QICE_RT_RT_INPORT_INT_INI_ADDR(base,inp_idx) ((base) + 0x0620 + (inp_idx) * 0x0028)
#define SOC_QICE_RT_RT_INPORT_INT_CLEAR_ADDR(base,inp_idx) ((base) + 0x0624 + (inp_idx) * 0x0028)
#define SOC_QICE_RT_RT_INPORT_INT_EN_ADDR(base,inp_idx) ((base) + 0x0628 + (inp_idx) * 0x0028)
#define SOC_QICE_RT_RT_INPORT_DFX_ST4_ADDR(base,inp_idx) ((base) + 0x062c + (inp_idx) * 0x0028)
#define SOC_QICE_RT_RT_INPORT_INT_SNP_ADDR(base,inp_idx) ((base) + 0x0630 + (inp_idx) * 0x0028)
#define SOC_QICE_RT_RT_OUTPORT_DFX_ST0_ADDR(base,outp_idx) ((base) + 0x0634 + (outp_idx) * 0x0028)
#define SOC_QICE_RT_RT_OUTPORT_DFX_ST1_ADDR(base,outp_idx) ((base) + 0x0638 + (outp_idx) * 0x0028)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rt_info : 32;
    } reg;
} SOC_QICE_RT_RT_INFO_UNION;
#endif
#define SOC_QICE_RT_RT_INFO_rt_info_START (0)
#define SOC_QICE_RT_RT_INFO_rt_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rt_reserved_rw : 32;
    } reg;
} SOC_QICE_RT_RT_RESERVED_RW_UNION;
#endif
#define SOC_QICE_RT_RT_RESERVED_RW_rt_reserved_rw_START (0)
#define SOC_QICE_RT_RT_RESERVED_RW_rt_reserved_rw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rt_reserved_ro : 32;
    } reg;
} SOC_QICE_RT_RT_RESERVED_RO_UNION;
#endif
#define SOC_QICE_RT_RT_RESERVED_RO_rt_reserved_ro_START (0)
#define SOC_QICE_RT_RT_RESERVED_RO_rt_reserved_ro_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ckg_byps_inp : 12;
        unsigned int reserved_0 : 3;
        unsigned int ckg_byps_outp : 12;
        unsigned int reserved_1 : 3;
        unsigned int ckg_byps_nmg : 1;
        unsigned int ckg_byps_cfc : 1;
    } reg;
} SOC_QICE_RT_RT_CKG_BYPS_UNION;
#endif
#define SOC_QICE_RT_RT_CKG_BYPS_ckg_byps_inp_START (0)
#define SOC_QICE_RT_RT_CKG_BYPS_ckg_byps_inp_END (11)
#define SOC_QICE_RT_RT_CKG_BYPS_ckg_byps_outp_START (15)
#define SOC_QICE_RT_RT_CKG_BYPS_ckg_byps_outp_END (26)
#define SOC_QICE_RT_RT_CKG_BYPS_ckg_byps_nmg_START (30)
#define SOC_QICE_RT_RT_CKG_BYPS_ckg_byps_nmg_END (30)
#define SOC_QICE_RT_RT_CKG_BYPS_ckg_byps_cfc_START (31)
#define SOC_QICE_RT_RT_CKG_BYPS_ckg_byps_cfc_END (31)
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
} SOC_QICE_RT_RT_MAX_LAT_CFG_UNION;
#endif
#define SOC_QICE_RT_RT_MAX_LAT_CFG_prescaler_START (0)
#define SOC_QICE_RT_RT_MAX_LAT_CFG_prescaler_END (2)
#define SOC_QICE_RT_RT_MAX_LAT_CFG_sat_en_START (8)
#define SOC_QICE_RT_RT_MAX_LAT_CFG_sat_en_END (8)
#define SOC_QICE_RT_RT_MAX_LAT_CFG_sat_clr_START (9)
#define SOC_QICE_RT_RT_MAX_LAT_CFG_sat_clr_END (9)
#define SOC_QICE_RT_RT_MAX_LAT_CFG_max_lat_inp_START (16)
#define SOC_QICE_RT_RT_MAX_LAT_CFG_max_lat_inp_END (19)
#define SOC_QICE_RT_RT_MAX_LAT_CFG_max_lat_outp_START (20)
#define SOC_QICE_RT_RT_MAX_LAT_CFG_max_lat_outp_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ckg_byps_inp_fifo : 12;
        unsigned int reserved_0 : 3;
        unsigned int ckg_inp_fifo_busy : 12;
        unsigned int reserved_1 : 4;
        unsigned int icfg_ckg_ext_ena : 1;
    } reg;
} SOC_QICE_RT_RT_CKG_EXT_EN_UNION;
#endif
#define SOC_QICE_RT_RT_CKG_EXT_EN_ckg_byps_inp_fifo_START (0)
#define SOC_QICE_RT_RT_CKG_EXT_EN_ckg_byps_inp_fifo_END (11)
#define SOC_QICE_RT_RT_CKG_EXT_EN_ckg_inp_fifo_busy_START (15)
#define SOC_QICE_RT_RT_CKG_EXT_EN_ckg_inp_fifo_busy_END (26)
#define SOC_QICE_RT_RT_CKG_EXT_EN_icfg_ckg_ext_ena_START (31)
#define SOC_QICE_RT_RT_CKG_EXT_EN_icfg_ckg_ext_ena_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 8;
        unsigned int cfc0_saturation : 5;
        unsigned int reserved_1 : 11;
        unsigned int cfc0_lp : 2;
        unsigned int reserved_2 : 5;
        unsigned int cfc0_en : 1;
    } reg;
} SOC_QICE_RT_RT_OUTPORT_CFC_CTRL_UNION;
#endif
#define SOC_QICE_RT_RT_OUTPORT_CFC_CTRL_cfc0_saturation_START (8)
#define SOC_QICE_RT_RT_OUTPORT_CFC_CTRL_cfc0_saturation_END (12)
#define SOC_QICE_RT_RT_OUTPORT_CFC_CTRL_cfc0_lp_START (24)
#define SOC_QICE_RT_RT_OUTPORT_CFC_CTRL_cfc0_lp_END (25)
#define SOC_QICE_RT_RT_OUTPORT_CFC_CTRL_cfc0_en_START (31)
#define SOC_QICE_RT_RT_OUTPORT_CFC_CTRL_cfc0_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int disable_low_latency : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_RT_RT_DIS_LOW_LATENCY_CTRL_UNION;
#endif
#define SOC_QICE_RT_RT_DIS_LOW_LATENCY_CTRL_disable_low_latency_START (0)
#define SOC_QICE_RT_RT_DIS_LOW_LATENCY_CTRL_disable_low_latency_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_inblk_busy : 12;
        unsigned int reserved_0 : 3;
        unsigned int dfx_outblk_busy : 12;
        unsigned int reserved_1 : 3;
        unsigned int dfx_rt_busy : 1;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_QICE_RT_RT_GLB_ST_UNION;
#endif
#define SOC_QICE_RT_RT_GLB_ST_dfx_inblk_busy_START (0)
#define SOC_QICE_RT_RT_GLB_ST_dfx_inblk_busy_END (11)
#define SOC_QICE_RT_RT_GLB_ST_dfx_outblk_busy_START (15)
#define SOC_QICE_RT_RT_GLB_ST_dfx_outblk_busy_END (26)
#define SOC_QICE_RT_RT_GLB_ST_dfx_rt_busy_START (30)
#define SOC_QICE_RT_RT_GLB_ST_dfx_rt_busy_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_inp_err_st : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_QICE_RT_RT_GLB_INT_ST_UNION;
#endif
#define SOC_QICE_RT_RT_GLB_INT_ST_dfx_inp_err_st_START (0)
#define SOC_QICE_RT_RT_GLB_INT_ST_dfx_inp_err_st_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_bp_cnt : 16;
        unsigned int dfx_sat_cnt : 16;
    } reg;
} SOC_QICE_RT_RT_MAX_LAT_ST_UNION;
#endif
#define SOC_QICE_RT_RT_MAX_LAT_ST_dfx_bp_cnt_START (0)
#define SOC_QICE_RT_RT_MAX_LAT_ST_dfx_bp_cnt_END (15)
#define SOC_QICE_RT_RT_MAX_LAT_ST_dfx_sat_cnt_START (16)
#define SOC_QICE_RT_RT_MAX_LAT_ST_dfx_sat_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_inp_lpc_req : 12;
        unsigned int reserved_0 : 3;
        unsigned int dfx_inp_lpc_ack : 12;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_QICE_RT_RT_INPORT_LPC_ST_UNION;
#endif
#define SOC_QICE_RT_RT_INPORT_LPC_ST_dfx_inp_lpc_req_START (0)
#define SOC_QICE_RT_RT_INPORT_LPC_ST_dfx_inp_lpc_req_END (11)
#define SOC_QICE_RT_RT_INPORT_LPC_ST_dfx_inp_lpc_ack_START (15)
#define SOC_QICE_RT_RT_INPORT_LPC_ST_dfx_inp_lpc_ack_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_outp_lpc_req : 12;
        unsigned int reserved_0 : 3;
        unsigned int dfx_outp_lpc_ack : 12;
        unsigned int reserved_1 : 5;
    } reg;
} SOC_QICE_RT_RT_OUTPORT_LPC_ST_UNION;
#endif
#define SOC_QICE_RT_RT_OUTPORT_LPC_ST_dfx_outp_lpc_req_START (0)
#define SOC_QICE_RT_RT_OUTPORT_LPC_ST_dfx_outp_lpc_req_END (11)
#define SOC_QICE_RT_RT_OUTPORT_LPC_ST_dfx_outp_lpc_ack_START (15)
#define SOC_QICE_RT_RT_OUTPORT_LPC_ST_dfx_outp_lpc_ack_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_vcfifo_st : 2;
        unsigned int dfx_inp_0_exp_rs_st : 1;
        unsigned int dfx_inp_1_exp_rs_st : 1;
        unsigned int dfx_inp_2_exp_rs_st : 1;
        unsigned int dfx_inp_3_exp_rs_st : 1;
        unsigned int dfx_inp_4_exp_rs_st : 1;
        unsigned int dfx_inp_5_exp_rs_st : 1;
        unsigned int dfx_inp_6_exp_rs_st : 1;
        unsigned int dfx_inp_7_exp_rs_st : 1;
        unsigned int dfx_inp_8_exp_rs_st : 1;
        unsigned int dfx_inp_9_exp_rs_st : 1;
        unsigned int dfx_inp_10_exp_rs_st : 1;
        unsigned int dfx_inp_11_exp_rs_st : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_QICE_RT_RT_INPORT_DFX_ST0_UNION;
#endif
#define SOC_QICE_RT_RT_INPORT_DFX_ST0_dfx_vcfifo_st_START (0)
#define SOC_QICE_RT_RT_INPORT_DFX_ST0_dfx_vcfifo_st_END (1)
#define SOC_QICE_RT_RT_INPORT_DFX_ST0_dfx_inp_0_exp_rs_st_START (2)
#define SOC_QICE_RT_RT_INPORT_DFX_ST0_dfx_inp_0_exp_rs_st_END (2)
#define SOC_QICE_RT_RT_INPORT_DFX_ST0_dfx_inp_1_exp_rs_st_START (3)
#define SOC_QICE_RT_RT_INPORT_DFX_ST0_dfx_inp_1_exp_rs_st_END (3)
#define SOC_QICE_RT_RT_INPORT_DFX_ST0_dfx_inp_2_exp_rs_st_START (4)
#define SOC_QICE_RT_RT_INPORT_DFX_ST0_dfx_inp_2_exp_rs_st_END (4)
#define SOC_QICE_RT_RT_INPORT_DFX_ST0_dfx_inp_3_exp_rs_st_START (5)
#define SOC_QICE_RT_RT_INPORT_DFX_ST0_dfx_inp_3_exp_rs_st_END (5)
#define SOC_QICE_RT_RT_INPORT_DFX_ST0_dfx_inp_4_exp_rs_st_START (6)
#define SOC_QICE_RT_RT_INPORT_DFX_ST0_dfx_inp_4_exp_rs_st_END (6)
#define SOC_QICE_RT_RT_INPORT_DFX_ST0_dfx_inp_5_exp_rs_st_START (7)
#define SOC_QICE_RT_RT_INPORT_DFX_ST0_dfx_inp_5_exp_rs_st_END (7)
#define SOC_QICE_RT_RT_INPORT_DFX_ST0_dfx_inp_6_exp_rs_st_START (8)
#define SOC_QICE_RT_RT_INPORT_DFX_ST0_dfx_inp_6_exp_rs_st_END (8)
#define SOC_QICE_RT_RT_INPORT_DFX_ST0_dfx_inp_7_exp_rs_st_START (9)
#define SOC_QICE_RT_RT_INPORT_DFX_ST0_dfx_inp_7_exp_rs_st_END (9)
#define SOC_QICE_RT_RT_INPORT_DFX_ST0_dfx_inp_8_exp_rs_st_START (10)
#define SOC_QICE_RT_RT_INPORT_DFX_ST0_dfx_inp_8_exp_rs_st_END (10)
#define SOC_QICE_RT_RT_INPORT_DFX_ST0_dfx_inp_9_exp_rs_st_START (11)
#define SOC_QICE_RT_RT_INPORT_DFX_ST0_dfx_inp_9_exp_rs_st_END (11)
#define SOC_QICE_RT_RT_INPORT_DFX_ST0_dfx_inp_10_exp_rs_st_START (12)
#define SOC_QICE_RT_RT_INPORT_DFX_ST0_dfx_inp_10_exp_rs_st_END (12)
#define SOC_QICE_RT_RT_INPORT_DFX_ST0_dfx_inp_11_exp_rs_st_START (13)
#define SOC_QICE_RT_RT_INPORT_DFX_ST0_dfx_inp_11_exp_rs_st_END (13)
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
        unsigned int dfx_outp10_arbfifo_st : 2;
        unsigned int dfx_outp11_arbfifo_st : 2;
        unsigned int reserved : 8;
    } reg;
} SOC_QICE_RT_RT_INPORT_DFX_ST2_UNION;
#endif
#define SOC_QICE_RT_RT_INPORT_DFX_ST2_dfx_outp0_arbfifo_st_START (0)
#define SOC_QICE_RT_RT_INPORT_DFX_ST2_dfx_outp0_arbfifo_st_END (1)
#define SOC_QICE_RT_RT_INPORT_DFX_ST2_dfx_outp1_arbfifo_st_START (2)
#define SOC_QICE_RT_RT_INPORT_DFX_ST2_dfx_outp1_arbfifo_st_END (3)
#define SOC_QICE_RT_RT_INPORT_DFX_ST2_dfx_outp2_arbfifo_st_START (4)
#define SOC_QICE_RT_RT_INPORT_DFX_ST2_dfx_outp2_arbfifo_st_END (5)
#define SOC_QICE_RT_RT_INPORT_DFX_ST2_dfx_outp3_arbfifo_st_START (6)
#define SOC_QICE_RT_RT_INPORT_DFX_ST2_dfx_outp3_arbfifo_st_END (7)
#define SOC_QICE_RT_RT_INPORT_DFX_ST2_dfx_outp4_arbfifo_st_START (8)
#define SOC_QICE_RT_RT_INPORT_DFX_ST2_dfx_outp4_arbfifo_st_END (9)
#define SOC_QICE_RT_RT_INPORT_DFX_ST2_dfx_outp5_arbfifo_st_START (10)
#define SOC_QICE_RT_RT_INPORT_DFX_ST2_dfx_outp5_arbfifo_st_END (11)
#define SOC_QICE_RT_RT_INPORT_DFX_ST2_dfx_outp6_arbfifo_st_START (12)
#define SOC_QICE_RT_RT_INPORT_DFX_ST2_dfx_outp6_arbfifo_st_END (13)
#define SOC_QICE_RT_RT_INPORT_DFX_ST2_dfx_outp7_arbfifo_st_START (14)
#define SOC_QICE_RT_RT_INPORT_DFX_ST2_dfx_outp7_arbfifo_st_END (15)
#define SOC_QICE_RT_RT_INPORT_DFX_ST2_dfx_outp8_arbfifo_st_START (16)
#define SOC_QICE_RT_RT_INPORT_DFX_ST2_dfx_outp8_arbfifo_st_END (17)
#define SOC_QICE_RT_RT_INPORT_DFX_ST2_dfx_outp9_arbfifo_st_START (18)
#define SOC_QICE_RT_RT_INPORT_DFX_ST2_dfx_outp9_arbfifo_st_END (19)
#define SOC_QICE_RT_RT_INPORT_DFX_ST2_dfx_outp10_arbfifo_st_START (20)
#define SOC_QICE_RT_RT_INPORT_DFX_ST2_dfx_outp10_arbfifo_st_END (21)
#define SOC_QICE_RT_RT_INPORT_DFX_ST2_dfx_outp11_arbfifo_st_START (22)
#define SOC_QICE_RT_RT_INPORT_DFX_ST2_dfx_outp11_arbfifo_st_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_i2o_access_err_st : 1;
        unsigned int dfx_did_ovfl_st : 1;
        unsigned int dfx_rop_ovfl_st : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_QICE_RT_RT_INPORT_INT_ST_UNION;
#endif
#define SOC_QICE_RT_RT_INPORT_INT_ST_dfx_i2o_access_err_st_START (0)
#define SOC_QICE_RT_RT_INPORT_INT_ST_dfx_i2o_access_err_st_END (0)
#define SOC_QICE_RT_RT_INPORT_INT_ST_dfx_did_ovfl_st_START (1)
#define SOC_QICE_RT_RT_INPORT_INT_ST_dfx_did_ovfl_st_END (1)
#define SOC_QICE_RT_RT_INPORT_INT_ST_dfx_rop_ovfl_st_START (2)
#define SOC_QICE_RT_RT_INPORT_INT_ST_dfx_rop_ovfl_st_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_i2o_access_err_ini : 1;
        unsigned int dfx_did_ovfl_ini : 1;
        unsigned int dfx_rop_ovfl_ini : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_QICE_RT_RT_INPORT_INT_INI_UNION;
#endif
#define SOC_QICE_RT_RT_INPORT_INT_INI_dfx_i2o_access_err_ini_START (0)
#define SOC_QICE_RT_RT_INPORT_INT_INI_dfx_i2o_access_err_ini_END (0)
#define SOC_QICE_RT_RT_INPORT_INT_INI_dfx_did_ovfl_ini_START (1)
#define SOC_QICE_RT_RT_INPORT_INT_INI_dfx_did_ovfl_ini_END (1)
#define SOC_QICE_RT_RT_INPORT_INT_INI_dfx_rop_ovfl_ini_START (2)
#define SOC_QICE_RT_RT_INPORT_INT_INI_dfx_rop_ovfl_ini_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_err_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_RT_RT_INPORT_INT_CLEAR_UNION;
#endif
#define SOC_QICE_RT_RT_INPORT_INT_CLEAR_dfx_err_clr_START (0)
#define SOC_QICE_RT_RT_INPORT_INT_CLEAR_dfx_err_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_i2o_access_err_en : 1;
        unsigned int dfx_did_ovfl_en : 1;
        unsigned int dfx_rop_ovfl_en : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_QICE_RT_RT_INPORT_INT_EN_UNION;
#endif
#define SOC_QICE_RT_RT_INPORT_INT_EN_dfx_i2o_access_err_en_START (0)
#define SOC_QICE_RT_RT_INPORT_INT_EN_dfx_i2o_access_err_en_END (0)
#define SOC_QICE_RT_RT_INPORT_INT_EN_dfx_did_ovfl_en_START (1)
#define SOC_QICE_RT_RT_INPORT_INT_EN_dfx_did_ovfl_en_END (1)
#define SOC_QICE_RT_RT_INPORT_INT_EN_dfx_rop_ovfl_en_START (2)
#define SOC_QICE_RT_RT_INPORT_INT_EN_dfx_rop_ovfl_en_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_vc_req : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_QICE_RT_RT_INPORT_DFX_ST4_UNION;
#endif
#define SOC_QICE_RT_RT_INPORT_DFX_ST4_dfx_vc_req_START (0)
#define SOC_QICE_RT_RT_INPORT_DFX_ST4_dfx_vc_req_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_i2o_access_err_snap : 1;
        unsigned int dfx_did_ovfl_snap : 1;
        unsigned int dfx_rop_ovfl_snap : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_QICE_RT_RT_INPORT_INT_SNP_UNION;
#endif
#define SOC_QICE_RT_RT_INPORT_INT_SNP_dfx_i2o_access_err_snap_START (0)
#define SOC_QICE_RT_RT_INPORT_INT_SNP_dfx_i2o_access_err_snap_END (0)
#define SOC_QICE_RT_RT_INPORT_INT_SNP_dfx_did_ovfl_snap_START (1)
#define SOC_QICE_RT_RT_INPORT_INT_SNP_dfx_did_ovfl_snap_END (1)
#define SOC_QICE_RT_RT_INPORT_INT_SNP_dfx_rop_ovfl_snap_START (2)
#define SOC_QICE_RT_RT_INPORT_INT_SNP_dfx_rop_ovfl_snap_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_vc_crdt_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_RT_RT_OUTPORT_DFX_ST0_UNION;
#endif
#define SOC_QICE_RT_RT_OUTPORT_DFX_ST0_dfx_vc_crdt_cnt_START (0)
#define SOC_QICE_RT_RT_OUTPORT_DFX_ST0_dfx_vc_crdt_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_vccrdt_vld : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_RT_RT_OUTPORT_DFX_ST1_UNION;
#endif
#define SOC_QICE_RT_RT_OUTPORT_DFX_ST1_dfx_vccrdt_vld_START (0)
#define SOC_QICE_RT_RT_OUTPORT_DFX_ST1_dfx_vccrdt_vld_END (0)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
