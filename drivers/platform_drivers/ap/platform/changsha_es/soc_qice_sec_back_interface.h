#ifndef __SOC_QICE_SEC_BACK_INTERFACE_H__
#define __SOC_QICE_SEC_BACK_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QICE_SEC_back_SEC_RGN_MAP0_ADDR(base,rgns) (base) + 0x400 + 0x20 * (rgns)
#define SOC_QICE_SEC_back_SEC_RGN_MAP1_ADDR(base,rgns) (base) + 0x404 + 0x20 * (rgns)
#define SOC_QICE_SEC_back_SEC_RGN_MAP2_ADDR(base,rgns) (base) + 0x408 + 0x20 * (rgns)
#define SOC_QICE_SEC_back_SEC_MID_WR_ADDR(base,mid_rgns) (base) + 0x40C + 0x20 * (mid_rgns)
#define SOC_QICE_SEC_back_SEC_MID_RD_ADDR(base,mid_rgns) (base) + 0x410 + 0x20 * (mid_rgns)
#define SOC_QICE_SEC_back_SEC_LD_SEL0_ADDR(base) ((base) + 0x414UL)
#define SOC_QICE_SEC_back_SEC_LD_SEL1_ADDR(base) ((base) + 0x418UL)
#define SOC_QICE_SEC_back_SEC_LD_SEL2_ADDR(base) ((base) + 0x41CUL)
#define SOC_QICE_SEC_back_SEC_GLB_CTRL_ADDR(base) ((base) + 0x434UL)
#define SOC_QICE_SEC_back_SEC_REQ_TYPE_ADDR(base) ((base) + 0x438UL)
#define SOC_QICE_SEC_back_ABNML_S_INT_CTRL_ADDR(base) ((base) + 0x43CUL)
#define SOC_QICE_SEC_back_ABNML_S_INT_STATUS_ADDR(base) ((base) + 0x454UL)
#define SOC_QICE_SEC_back_ABNML_S_INT_CLR_ADDR(base) ((base) + 0x458UL)
#define SOC_QICE_SEC_back_ABNML_S_INT_INFO0_ADDR(base) ((base) + 0x45CUL)
#define SOC_QICE_SEC_back_ABNML_S_INT_INFO1_ADDR(base) ((base) + 0x474UL)
#define SOC_QICE_SEC_back_ABNML_S_INT_INFO2_ADDR(base) ((base) + 0x478UL)
#define SOC_QICE_SEC_back_ABNML_S_INT_INFO3_ADDR(base) ((base) + 0x47CUL)
#define SOC_QICE_SEC_back_SEC_SUB_RGN0_ADDR(base,sub_rgns) (base) + 0x494 + 0x20 * (sub_rgns)
#define SOC_QICE_SEC_back_SEC_SUB_RGN1_ADDR(base,sub_rgns) (base) + 0x498 + 0x20 * (sub_rgns)
#define SOC_QICE_SEC_back_SEC_SUB_RGN2_ADDR(base,sub_rgns) (base) + 0x49C + 0x20 * (sub_rgns)
#define SOC_QICE_SEC_back_SEC_SUB_RGN3_ADDR(base,sub_rgns) (base) + 0x714 + 0x20 * (sub_rgns)
#else
#define SOC_QICE_SEC_back_SEC_RGN_MAP0_ADDR(base,rgns) (base) + 0x400 + 0x20 * (rgns)
#define SOC_QICE_SEC_back_SEC_RGN_MAP1_ADDR(base,rgns) (base) + 0x404 + 0x20 * (rgns)
#define SOC_QICE_SEC_back_SEC_RGN_MAP2_ADDR(base,rgns) (base) + 0x408 + 0x20 * (rgns)
#define SOC_QICE_SEC_back_SEC_MID_WR_ADDR(base,mid_rgns) (base) + 0x40C + 0x20 * (mid_rgns)
#define SOC_QICE_SEC_back_SEC_MID_RD_ADDR(base,mid_rgns) (base) + 0x410 + 0x20 * (mid_rgns)
#define SOC_QICE_SEC_back_SEC_LD_SEL0_ADDR(base) ((base) + 0x414)
#define SOC_QICE_SEC_back_SEC_LD_SEL1_ADDR(base) ((base) + 0x418)
#define SOC_QICE_SEC_back_SEC_LD_SEL2_ADDR(base) ((base) + 0x41C)
#define SOC_QICE_SEC_back_SEC_GLB_CTRL_ADDR(base) ((base) + 0x434)
#define SOC_QICE_SEC_back_SEC_REQ_TYPE_ADDR(base) ((base) + 0x438)
#define SOC_QICE_SEC_back_ABNML_S_INT_CTRL_ADDR(base) ((base) + 0x43C)
#define SOC_QICE_SEC_back_ABNML_S_INT_STATUS_ADDR(base) ((base) + 0x454)
#define SOC_QICE_SEC_back_ABNML_S_INT_CLR_ADDR(base) ((base) + 0x458)
#define SOC_QICE_SEC_back_ABNML_S_INT_INFO0_ADDR(base) ((base) + 0x45C)
#define SOC_QICE_SEC_back_ABNML_S_INT_INFO1_ADDR(base) ((base) + 0x474)
#define SOC_QICE_SEC_back_ABNML_S_INT_INFO2_ADDR(base) ((base) + 0x478)
#define SOC_QICE_SEC_back_ABNML_S_INT_INFO3_ADDR(base) ((base) + 0x47C)
#define SOC_QICE_SEC_back_SEC_SUB_RGN0_ADDR(base,sub_rgns) (base) + 0x494 + 0x20 * (sub_rgns)
#define SOC_QICE_SEC_back_SEC_SUB_RGN1_ADDR(base,sub_rgns) (base) + 0x498 + 0x20 * (sub_rgns)
#define SOC_QICE_SEC_back_SEC_SUB_RGN2_ADDR(base,sub_rgns) (base) + 0x49C + 0x20 * (sub_rgns)
#define SOC_QICE_SEC_back_SEC_SUB_RGN3_ADDR(base,sub_rgns) (base) + 0x714 + 0x20 * (sub_rgns)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rgn_base_addr : 20;
        unsigned int reserved_0 : 10;
        unsigned int sub_rgn_zone : 1;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_QICE_SEC_back_SEC_RGN_MAP0_UNION;
#endif
#define SOC_QICE_SEC_back_SEC_RGN_MAP0_rgn_base_addr_START (0)
#define SOC_QICE_SEC_back_SEC_RGN_MAP0_rgn_base_addr_END (19)
#define SOC_QICE_SEC_back_SEC_RGN_MAP0_sub_rgn_zone_START (30)
#define SOC_QICE_SEC_back_SEC_RGN_MAP0_sub_rgn_zone_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rgn_top_addr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_QICE_SEC_back_SEC_RGN_MAP1_UNION;
#endif
#define SOC_QICE_SEC_back_SEC_RGN_MAP1_rgn_top_addr_START (0)
#define SOC_QICE_SEC_back_SEC_RGN_MAP1_rgn_top_addr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sp : 4;
        unsigned int reserved : 27;
        unsigned int rgn_en : 1;
    } reg;
} SOC_QICE_SEC_back_SEC_RGN_MAP2_UNION;
#endif
#define SOC_QICE_SEC_back_SEC_RGN_MAP2_sp_START (0)
#define SOC_QICE_SEC_back_SEC_RGN_MAP2_sp_END (3)
#define SOC_QICE_SEC_back_SEC_RGN_MAP2_rgn_en_START (31)
#define SOC_QICE_SEC_back_SEC_RGN_MAP2_rgn_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_sel_wr : 32;
    } reg;
} SOC_QICE_SEC_back_SEC_MID_WR_UNION;
#endif
#define SOC_QICE_SEC_back_SEC_MID_WR_mid_sel_wr_START (0)
#define SOC_QICE_SEC_back_SEC_MID_WR_mid_sel_wr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mid_sel_rd : 32;
    } reg;
} SOC_QICE_SEC_back_SEC_MID_RD_UNION;
#endif
#define SOC_QICE_SEC_back_SEC_MID_RD_mid_sel_rd_START (0)
#define SOC_QICE_SEC_back_SEC_MID_RD_mid_sel_rd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ld_rgns_sel0 : 32;
    } reg;
} SOC_QICE_SEC_back_SEC_LD_SEL0_UNION;
#endif
#define SOC_QICE_SEC_back_SEC_LD_SEL0_ld_rgns_sel0_START (0)
#define SOC_QICE_SEC_back_SEC_LD_SEL0_ld_rgns_sel0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ld_rgns_sel1 : 32;
    } reg;
} SOC_QICE_SEC_back_SEC_LD_SEL1_UNION;
#endif
#define SOC_QICE_SEC_back_SEC_LD_SEL1_ld_rgns_sel1_START (0)
#define SOC_QICE_SEC_back_SEC_LD_SEL1_ld_rgns_sel1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ld_rgns_sel2 : 32;
    } reg;
} SOC_QICE_SEC_back_SEC_LD_SEL2_UNION;
#endif
#define SOC_QICE_SEC_back_SEC_LD_SEL2_ld_rgns_sel2_START (0)
#define SOC_QICE_SEC_back_SEC_LD_SEL2_ld_rgns_sel2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sec_rgn_byp : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_SEC_back_SEC_GLB_CTRL_UNION;
#endif
#define SOC_QICE_SEC_back_SEC_GLB_CTRL_sec_rgn_byp_START (0)
#define SOC_QICE_SEC_back_SEC_GLB_CTRL_sec_rgn_byp_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sec_req_type : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_SEC_back_SEC_REQ_TYPE_UNION;
#endif
#define SOC_QICE_SEC_back_SEC_REQ_TYPE_sec_req_type_START (0)
#define SOC_QICE_SEC_back_SEC_REQ_TYPE_sec_req_type_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_s_int_glb_mask : 1;
        unsigned int reserved_0 : 7;
        unsigned int abnml_s_err_rsp_dis : 1;
        unsigned int reserved_1 : 7;
        unsigned int abnml_s_int_dis : 3;
        unsigned int reserved_2 : 5;
        unsigned int abnml_s_int_mask : 3;
        unsigned int abnml_wr_s_int_mask : 1;
        unsigned int abnml_rd_s_int_mask : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_QICE_SEC_back_ABNML_S_INT_CTRL_UNION;
#endif
#define SOC_QICE_SEC_back_ABNML_S_INT_CTRL_abnml_s_int_glb_mask_START (0)
#define SOC_QICE_SEC_back_ABNML_S_INT_CTRL_abnml_s_int_glb_mask_END (0)
#define SOC_QICE_SEC_back_ABNML_S_INT_CTRL_abnml_s_err_rsp_dis_START (8)
#define SOC_QICE_SEC_back_ABNML_S_INT_CTRL_abnml_s_err_rsp_dis_END (8)
#define SOC_QICE_SEC_back_ABNML_S_INT_CTRL_abnml_s_int_dis_START (16)
#define SOC_QICE_SEC_back_ABNML_S_INT_CTRL_abnml_s_int_dis_END (18)
#define SOC_QICE_SEC_back_ABNML_S_INT_CTRL_abnml_s_int_mask_START (24)
#define SOC_QICE_SEC_back_ABNML_S_INT_CTRL_abnml_s_int_mask_END (26)
#define SOC_QICE_SEC_back_ABNML_S_INT_CTRL_abnml_wr_s_int_mask_START (27)
#define SOC_QICE_SEC_back_ABNML_S_INT_CTRL_abnml_wr_s_int_mask_END (27)
#define SOC_QICE_SEC_back_ABNML_S_INT_CTRL_abnml_rd_s_int_mask_START (28)
#define SOC_QICE_SEC_back_ABNML_S_INT_CTRL_abnml_rd_s_int_mask_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_s_int_mask_status : 3;
        unsigned int reserved_0 : 5;
        unsigned int abnml_s_int_overrun : 1;
        unsigned int reserved_1 : 7;
        unsigned int abnml_s_int_org_status : 3;
        unsigned int reserved_2 : 5;
        unsigned int abnml_s_int_type : 2;
        unsigned int reserved_3 : 6;
    } reg;
} SOC_QICE_SEC_back_ABNML_S_INT_STATUS_UNION;
#endif
#define SOC_QICE_SEC_back_ABNML_S_INT_STATUS_abnml_s_int_mask_status_START (0)
#define SOC_QICE_SEC_back_ABNML_S_INT_STATUS_abnml_s_int_mask_status_END (2)
#define SOC_QICE_SEC_back_ABNML_S_INT_STATUS_abnml_s_int_overrun_START (8)
#define SOC_QICE_SEC_back_ABNML_S_INT_STATUS_abnml_s_int_overrun_END (8)
#define SOC_QICE_SEC_back_ABNML_S_INT_STATUS_abnml_s_int_org_status_START (16)
#define SOC_QICE_SEC_back_ABNML_S_INT_STATUS_abnml_s_int_org_status_END (18)
#define SOC_QICE_SEC_back_ABNML_S_INT_STATUS_abnml_s_int_type_START (24)
#define SOC_QICE_SEC_back_ABNML_S_INT_STATUS_abnml_s_int_type_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_s_int_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_SEC_back_ABNML_S_INT_CLR_UNION;
#endif
#define SOC_QICE_SEC_back_ABNML_S_INT_CLR_abnml_s_int_clr_START (0)
#define SOC_QICE_SEC_back_ABNML_S_INT_CLR_abnml_s_int_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_s_int_info0 : 32;
    } reg;
} SOC_QICE_SEC_back_ABNML_S_INT_INFO0_UNION;
#endif
#define SOC_QICE_SEC_back_ABNML_S_INT_INFO0_abnml_s_int_info0_START (0)
#define SOC_QICE_SEC_back_ABNML_S_INT_INFO0_abnml_s_int_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_s_int_info1 : 32;
    } reg;
} SOC_QICE_SEC_back_ABNML_S_INT_INFO1_UNION;
#endif
#define SOC_QICE_SEC_back_ABNML_S_INT_INFO1_abnml_s_int_info1_START (0)
#define SOC_QICE_SEC_back_ABNML_S_INT_INFO1_abnml_s_int_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_s_int_info2 : 32;
    } reg;
} SOC_QICE_SEC_back_ABNML_S_INT_INFO2_UNION;
#endif
#define SOC_QICE_SEC_back_ABNML_S_INT_INFO2_abnml_s_int_info2_START (0)
#define SOC_QICE_SEC_back_ABNML_S_INT_INFO2_abnml_s_int_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_s_int_info3 : 32;
    } reg;
} SOC_QICE_SEC_back_ABNML_S_INT_INFO3_UNION;
#endif
#define SOC_QICE_SEC_back_ABNML_S_INT_INFO3_abnml_s_int_info3_START (0)
#define SOC_QICE_SEC_back_ABNML_S_INT_INFO3_abnml_s_int_info3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sub_rgn_disable0 : 32;
    } reg;
} SOC_QICE_SEC_back_SEC_SUB_RGN0_UNION;
#endif
#define SOC_QICE_SEC_back_SEC_SUB_RGN0_sub_rgn_disable0_START (0)
#define SOC_QICE_SEC_back_SEC_SUB_RGN0_sub_rgn_disable0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sub_rgn_disable1 : 32;
    } reg;
} SOC_QICE_SEC_back_SEC_SUB_RGN1_UNION;
#endif
#define SOC_QICE_SEC_back_SEC_SUB_RGN1_sub_rgn_disable1_START (0)
#define SOC_QICE_SEC_back_SEC_SUB_RGN1_sub_rgn_disable1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sub_rgn_disable2 : 32;
    } reg;
} SOC_QICE_SEC_back_SEC_SUB_RGN2_UNION;
#endif
#define SOC_QICE_SEC_back_SEC_SUB_RGN2_sub_rgn_disable2_START (0)
#define SOC_QICE_SEC_back_SEC_SUB_RGN2_sub_rgn_disable2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sub_rgn_disable3 : 32;
    } reg;
} SOC_QICE_SEC_back_SEC_SUB_RGN3_UNION;
#endif
#define SOC_QICE_SEC_back_SEC_SUB_RGN3_sub_rgn_disable3_START (0)
#define SOC_QICE_SEC_back_SEC_SUB_RGN3_sub_rgn_disable3_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
