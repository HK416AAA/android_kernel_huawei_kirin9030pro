#ifndef __SOC_QICE_FC_INTERFACE_H__
#define __SOC_QICE_FC_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QICE_FC_FC_FLUX_REQ_ADDR(base,flux_req_num) (base) + 0x400 + 0x4 * (flux_req_num)
#define SOC_QICE_FC_FC_FLUX_CTRL_ADDR(base,flux_ctrl_num) (base) + 0x500 + 0x4 * (flux_ctrl_num)
#define SOC_QICE_FC_FC_VC_BP_CTRL_ADDR(base,vc_num) (base) + 0x600 + 0x4 * (vc_num)
#define SOC_QICE_FC_FC_HN_BP_CTRL_ADDR(base) ((base) + 0x610UL)
#define SOC_QICE_FC_FC_SYS_QOS_CTRL_ADDR(base) ((base) + 0x614UL)
#define SOC_QICE_FC_FC_SC_QOS_CTRL_ADDR(base) ((base) + 0x618UL)
#define SOC_QICE_FC_FC_R_QOS2SYS_ALLOW_REMAP0_ADDR(base) ((base) + 0x620UL)
#define SOC_QICE_FC_FC_R_QOS2SYS_ALLOW_REMAP1_ADDR(base) ((base) + 0x624UL)
#define SOC_QICE_FC_FC_W_QOS2SYS_ALLOW_REMAP0_ADDR(base) ((base) + 0x628UL)
#define SOC_QICE_FC_FC_W_QOS2SYS_ALLOW_REMAP1_ADDR(base) ((base) + 0x62CUL)
#define SOC_QICE_FC_FC_W_QOS2SC_ALLOW_REMAP0_ADDR(base) ((base) + 0x630UL)
#define SOC_QICE_FC_FC_W_QOS2SC_ALLOW_REMAP1_ADDR(base) ((base) + 0x634UL)
#define SOC_QICE_FC_FC_R_VC1_QOS2SYS_ALLOW_REMAP0_ADDR(base) ((base) + 0x638UL)
#define SOC_QICE_FC_FC_R_VC1_QOS2SYS_ALLOW_REMAP1_ADDR(base) ((base) + 0x63CUL)
#define SOC_QICE_FC_FC_W_VC1_QOS2SYS_ALLOW_REMAP0_ADDR(base) ((base) + 0x640UL)
#define SOC_QICE_FC_FC_W_VC1_QOS2SYS_ALLOW_REMAP1_ADDR(base) ((base) + 0x644UL)
#define SOC_QICE_FC_FC_R_VC2_QOS2SYS_ALLOW_REMAP0_ADDR(base) ((base) + 0x648UL)
#define SOC_QICE_FC_FC_R_VC2_QOS2SYS_ALLOW_REMAP1_ADDR(base) ((base) + 0x64CUL)
#define SOC_QICE_FC_FC_W_VC2_QOS2SYS_ALLOW_REMAP0_ADDR(base) ((base) + 0x650UL)
#define SOC_QICE_FC_FC_W_VC2_QOS2SYS_ALLOW_REMAP1_ADDR(base) ((base) + 0x654UL)
#define SOC_QICE_FC_FC_R_VC3_QOS2SYS_ALLOW_REMAP0_ADDR(base) ((base) + 0x658UL)
#define SOC_QICE_FC_FC_R_VC3_QOS2SYS_ALLOW_REMAP1_ADDR(base) ((base) + 0x65CUL)
#define SOC_QICE_FC_FC_W_VC3_QOS2SYS_ALLOW_REMAP0_ADDR(base) ((base) + 0x660UL)
#define SOC_QICE_FC_FC_W_VC3_QOS2SYS_ALLOW_REMAP1_ADDR(base) ((base) + 0x664UL)
#define SOC_QICE_FC_FC_FLUX_REQ_MSK0_ADDR(base) ((base) + 0x0C00UL)
#define SOC_QICE_FC_FC_FLUX_REQ_MSK1_ADDR(base) ((base) + 0x0C04UL)
#define SOC_QICE_FC_FC_FLUX_REQ_MSK2_ADDR(base) ((base) + 0x0C08UL)
#else
#define SOC_QICE_FC_FC_FLUX_REQ_ADDR(base,flux_req_num) (base) + 0x400 + 0x4 * (flux_req_num)
#define SOC_QICE_FC_FC_FLUX_CTRL_ADDR(base,flux_ctrl_num) (base) + 0x500 + 0x4 * (flux_ctrl_num)
#define SOC_QICE_FC_FC_VC_BP_CTRL_ADDR(base,vc_num) (base) + 0x600 + 0x4 * (vc_num)
#define SOC_QICE_FC_FC_HN_BP_CTRL_ADDR(base) ((base) + 0x610)
#define SOC_QICE_FC_FC_SYS_QOS_CTRL_ADDR(base) ((base) + 0x614)
#define SOC_QICE_FC_FC_SC_QOS_CTRL_ADDR(base) ((base) + 0x618)
#define SOC_QICE_FC_FC_R_QOS2SYS_ALLOW_REMAP0_ADDR(base) ((base) + 0x620)
#define SOC_QICE_FC_FC_R_QOS2SYS_ALLOW_REMAP1_ADDR(base) ((base) + 0x624)
#define SOC_QICE_FC_FC_W_QOS2SYS_ALLOW_REMAP0_ADDR(base) ((base) + 0x628)
#define SOC_QICE_FC_FC_W_QOS2SYS_ALLOW_REMAP1_ADDR(base) ((base) + 0x62C)
#define SOC_QICE_FC_FC_W_QOS2SC_ALLOW_REMAP0_ADDR(base) ((base) + 0x630)
#define SOC_QICE_FC_FC_W_QOS2SC_ALLOW_REMAP1_ADDR(base) ((base) + 0x634)
#define SOC_QICE_FC_FC_R_VC1_QOS2SYS_ALLOW_REMAP0_ADDR(base) ((base) + 0x638)
#define SOC_QICE_FC_FC_R_VC1_QOS2SYS_ALLOW_REMAP1_ADDR(base) ((base) + 0x63C)
#define SOC_QICE_FC_FC_W_VC1_QOS2SYS_ALLOW_REMAP0_ADDR(base) ((base) + 0x640)
#define SOC_QICE_FC_FC_W_VC1_QOS2SYS_ALLOW_REMAP1_ADDR(base) ((base) + 0x644)
#define SOC_QICE_FC_FC_R_VC2_QOS2SYS_ALLOW_REMAP0_ADDR(base) ((base) + 0x648)
#define SOC_QICE_FC_FC_R_VC2_QOS2SYS_ALLOW_REMAP1_ADDR(base) ((base) + 0x64C)
#define SOC_QICE_FC_FC_W_VC2_QOS2SYS_ALLOW_REMAP0_ADDR(base) ((base) + 0x650)
#define SOC_QICE_FC_FC_W_VC2_QOS2SYS_ALLOW_REMAP1_ADDR(base) ((base) + 0x654)
#define SOC_QICE_FC_FC_R_VC3_QOS2SYS_ALLOW_REMAP0_ADDR(base) ((base) + 0x658)
#define SOC_QICE_FC_FC_R_VC3_QOS2SYS_ALLOW_REMAP1_ADDR(base) ((base) + 0x65C)
#define SOC_QICE_FC_FC_W_VC3_QOS2SYS_ALLOW_REMAP0_ADDR(base) ((base) + 0x660)
#define SOC_QICE_FC_FC_W_VC3_QOS2SYS_ALLOW_REMAP1_ADDR(base) ((base) + 0x664)
#define SOC_QICE_FC_FC_FLUX_REQ_MSK0_ADDR(base) ((base) + 0x0C00)
#define SOC_QICE_FC_FC_FLUX_REQ_MSK1_ADDR(base) ((base) + 0x0C04)
#define SOC_QICE_FC_FC_FLUX_REQ_MSK2_ADDR(base) ((base) + 0x0C08)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mst_flux_req_en : 1;
        unsigned int reserved_0 : 7;
        unsigned int mst_flux_req_pri_wl : 4;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_QICE_FC_FC_FLUX_REQ_UNION;
#endif
#define SOC_QICE_FC_FC_FLUX_REQ_mst_flux_req_en_START (0)
#define SOC_QICE_FC_FC_FLUX_REQ_mst_flux_req_en_END (0)
#define SOC_QICE_FC_FC_FLUX_REQ_mst_flux_req_pri_wl_START (8)
#define SOC_QICE_FC_FC_FLUX_REQ_mst_flux_req_pri_wl_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mst_flux_ctrl_en : 1;
        unsigned int reserved_0 : 7;
        unsigned int mst_flux_ctrl_r_wl : 4;
        unsigned int mst_flux_ctrl_w_wl : 4;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_QICE_FC_FC_FLUX_CTRL_UNION;
#endif
#define SOC_QICE_FC_FC_FLUX_CTRL_mst_flux_ctrl_en_START (0)
#define SOC_QICE_FC_FC_FLUX_CTRL_mst_flux_ctrl_en_END (0)
#define SOC_QICE_FC_FC_FLUX_CTRL_mst_flux_ctrl_r_wl_START (8)
#define SOC_QICE_FC_FC_FLUX_CTRL_mst_flux_ctrl_r_wl_END (11)
#define SOC_QICE_FC_FC_FLUX_CTRL_mst_flux_ctrl_w_wl_START (12)
#define SOC_QICE_FC_FC_FLUX_CTRL_mst_flux_ctrl_w_wl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vc_flux_req_en : 1;
        unsigned int vc_dmc_qos_allow_en : 1;
        unsigned int vc_sc_qos_allow_en : 1;
        unsigned int vc_hn_qos_allow_en : 1;
        unsigned int reserved_0 : 4;
        unsigned int vc_bp_r_pri_wl : 4;
        unsigned int vc_bp_w_pri_wl : 4;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_QICE_FC_FC_VC_BP_CTRL_UNION;
#endif
#define SOC_QICE_FC_FC_VC_BP_CTRL_vc_flux_req_en_START (0)
#define SOC_QICE_FC_FC_VC_BP_CTRL_vc_flux_req_en_END (0)
#define SOC_QICE_FC_FC_VC_BP_CTRL_vc_dmc_qos_allow_en_START (1)
#define SOC_QICE_FC_FC_VC_BP_CTRL_vc_dmc_qos_allow_en_END (1)
#define SOC_QICE_FC_FC_VC_BP_CTRL_vc_sc_qos_allow_en_START (2)
#define SOC_QICE_FC_FC_VC_BP_CTRL_vc_sc_qos_allow_en_END (2)
#define SOC_QICE_FC_FC_VC_BP_CTRL_vc_hn_qos_allow_en_START (3)
#define SOC_QICE_FC_FC_VC_BP_CTRL_vc_hn_qos_allow_en_END (3)
#define SOC_QICE_FC_FC_VC_BP_CTRL_vc_bp_r_pri_wl_START (8)
#define SOC_QICE_FC_FC_VC_BP_CTRL_vc_bp_r_pri_wl_END (11)
#define SOC_QICE_FC_FC_VC_BP_CTRL_vc_bp_w_pri_wl_START (12)
#define SOC_QICE_FC_FC_VC_BP_CTRL_vc_bp_w_pri_wl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hn_flux_req_en : 1;
        unsigned int hn_dmc_qos_allow_en : 1;
        unsigned int hn_sc_qos_allow_en : 1;
        unsigned int hn_hn_qos_allow_en : 1;
        unsigned int reserved_0 : 4;
        unsigned int hn_bp_r_pri_wl : 4;
        unsigned int hn_bp_w_pri_wl : 4;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_QICE_FC_FC_HN_BP_CTRL_UNION;
#endif
#define SOC_QICE_FC_FC_HN_BP_CTRL_hn_flux_req_en_START (0)
#define SOC_QICE_FC_FC_HN_BP_CTRL_hn_flux_req_en_END (0)
#define SOC_QICE_FC_FC_HN_BP_CTRL_hn_dmc_qos_allow_en_START (1)
#define SOC_QICE_FC_FC_HN_BP_CTRL_hn_dmc_qos_allow_en_END (1)
#define SOC_QICE_FC_FC_HN_BP_CTRL_hn_sc_qos_allow_en_START (2)
#define SOC_QICE_FC_FC_HN_BP_CTRL_hn_sc_qos_allow_en_END (2)
#define SOC_QICE_FC_FC_HN_BP_CTRL_hn_hn_qos_allow_en_START (3)
#define SOC_QICE_FC_FC_HN_BP_CTRL_hn_hn_qos_allow_en_END (3)
#define SOC_QICE_FC_FC_HN_BP_CTRL_hn_bp_r_pri_wl_START (8)
#define SOC_QICE_FC_FC_HN_BP_CTRL_hn_bp_r_pri_wl_END (11)
#define SOC_QICE_FC_FC_HN_BP_CTRL_hn_bp_w_pri_wl_START (12)
#define SOC_QICE_FC_FC_HN_BP_CTRL_hn_bp_w_pri_wl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sys_flux_req_en : 1;
        unsigned int sys_dmc_qos_allow_en : 1;
        unsigned int sys_sc_qos_allow_en : 1;
        unsigned int sys_hn_qos_allow_en : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_FC_FC_SYS_QOS_CTRL_UNION;
#endif
#define SOC_QICE_FC_FC_SYS_QOS_CTRL_sys_flux_req_en_START (0)
#define SOC_QICE_FC_FC_SYS_QOS_CTRL_sys_flux_req_en_END (0)
#define SOC_QICE_FC_FC_SYS_QOS_CTRL_sys_dmc_qos_allow_en_START (1)
#define SOC_QICE_FC_FC_SYS_QOS_CTRL_sys_dmc_qos_allow_en_END (1)
#define SOC_QICE_FC_FC_SYS_QOS_CTRL_sys_sc_qos_allow_en_START (2)
#define SOC_QICE_FC_FC_SYS_QOS_CTRL_sys_sc_qos_allow_en_END (2)
#define SOC_QICE_FC_FC_SYS_QOS_CTRL_sys_hn_qos_allow_en_START (3)
#define SOC_QICE_FC_FC_SYS_QOS_CTRL_sys_hn_qos_allow_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_flux_req_en : 1;
        unsigned int sc_dmc_qos_allow_en : 1;
        unsigned int sc_sc_qos_allow_en : 1;
        unsigned int sc_hn_qos_allow_en : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_FC_FC_SC_QOS_CTRL_UNION;
#endif
#define SOC_QICE_FC_FC_SC_QOS_CTRL_sc_flux_req_en_START (0)
#define SOC_QICE_FC_FC_SC_QOS_CTRL_sc_flux_req_en_END (0)
#define SOC_QICE_FC_FC_SC_QOS_CTRL_sc_dmc_qos_allow_en_START (1)
#define SOC_QICE_FC_FC_SC_QOS_CTRL_sc_dmc_qos_allow_en_END (1)
#define SOC_QICE_FC_FC_SC_QOS_CTRL_sc_sc_qos_allow_en_START (2)
#define SOC_QICE_FC_FC_SC_QOS_CTRL_sc_sc_qos_allow_en_END (2)
#define SOC_QICE_FC_FC_SC_QOS_CTRL_sc_hn_qos_allow_en_START (3)
#define SOC_QICE_FC_FC_SC_QOS_CTRL_sc_hn_qos_allow_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pri0_remap_qos2sys_allow_r : 4;
        unsigned int pri1_remap_qos2sys_allow_r : 4;
        unsigned int pri2_remap_qos2sys_allow_r : 4;
        unsigned int pri3_remap_qos2sys_allow_r : 4;
        unsigned int pri4_remap_qos2sys_allow_r : 4;
        unsigned int pri5_remap_qos2sys_allow_r : 4;
        unsigned int pri6_remap_qos2sys_allow_r : 4;
        unsigned int pri7_remap_qos2sys_allow_r : 4;
    } reg;
} SOC_QICE_FC_FC_R_QOS2SYS_ALLOW_REMAP0_UNION;
#endif
#define SOC_QICE_FC_FC_R_QOS2SYS_ALLOW_REMAP0_pri0_remap_qos2sys_allow_r_START (0)
#define SOC_QICE_FC_FC_R_QOS2SYS_ALLOW_REMAP0_pri0_remap_qos2sys_allow_r_END (3)
#define SOC_QICE_FC_FC_R_QOS2SYS_ALLOW_REMAP0_pri1_remap_qos2sys_allow_r_START (4)
#define SOC_QICE_FC_FC_R_QOS2SYS_ALLOW_REMAP0_pri1_remap_qos2sys_allow_r_END (7)
#define SOC_QICE_FC_FC_R_QOS2SYS_ALLOW_REMAP0_pri2_remap_qos2sys_allow_r_START (8)
#define SOC_QICE_FC_FC_R_QOS2SYS_ALLOW_REMAP0_pri2_remap_qos2sys_allow_r_END (11)
#define SOC_QICE_FC_FC_R_QOS2SYS_ALLOW_REMAP0_pri3_remap_qos2sys_allow_r_START (12)
#define SOC_QICE_FC_FC_R_QOS2SYS_ALLOW_REMAP0_pri3_remap_qos2sys_allow_r_END (15)
#define SOC_QICE_FC_FC_R_QOS2SYS_ALLOW_REMAP0_pri4_remap_qos2sys_allow_r_START (16)
#define SOC_QICE_FC_FC_R_QOS2SYS_ALLOW_REMAP0_pri4_remap_qos2sys_allow_r_END (19)
#define SOC_QICE_FC_FC_R_QOS2SYS_ALLOW_REMAP0_pri5_remap_qos2sys_allow_r_START (20)
#define SOC_QICE_FC_FC_R_QOS2SYS_ALLOW_REMAP0_pri5_remap_qos2sys_allow_r_END (23)
#define SOC_QICE_FC_FC_R_QOS2SYS_ALLOW_REMAP0_pri6_remap_qos2sys_allow_r_START (24)
#define SOC_QICE_FC_FC_R_QOS2SYS_ALLOW_REMAP0_pri6_remap_qos2sys_allow_r_END (27)
#define SOC_QICE_FC_FC_R_QOS2SYS_ALLOW_REMAP0_pri7_remap_qos2sys_allow_r_START (28)
#define SOC_QICE_FC_FC_R_QOS2SYS_ALLOW_REMAP0_pri7_remap_qos2sys_allow_r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pri8_remap_qos2sys_allow_r : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_FC_FC_R_QOS2SYS_ALLOW_REMAP1_UNION;
#endif
#define SOC_QICE_FC_FC_R_QOS2SYS_ALLOW_REMAP1_pri8_remap_qos2sys_allow_r_START (0)
#define SOC_QICE_FC_FC_R_QOS2SYS_ALLOW_REMAP1_pri8_remap_qos2sys_allow_r_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pri0_remap_qos2sys_allow_w : 4;
        unsigned int pri1_remap_qos2sys_allow_w : 4;
        unsigned int pri2_remap_qos2sys_allow_w : 4;
        unsigned int pri3_remap_qos2sys_allow_w : 4;
        unsigned int pri4_remap_qos2sys_allow_w : 4;
        unsigned int pri5_remap_qos2sys_allow_w : 4;
        unsigned int pri6_remap_qos2sys_allow_w : 4;
        unsigned int pri7_remap_qos2sys_allow_w : 4;
    } reg;
} SOC_QICE_FC_FC_W_QOS2SYS_ALLOW_REMAP0_UNION;
#endif
#define SOC_QICE_FC_FC_W_QOS2SYS_ALLOW_REMAP0_pri0_remap_qos2sys_allow_w_START (0)
#define SOC_QICE_FC_FC_W_QOS2SYS_ALLOW_REMAP0_pri0_remap_qos2sys_allow_w_END (3)
#define SOC_QICE_FC_FC_W_QOS2SYS_ALLOW_REMAP0_pri1_remap_qos2sys_allow_w_START (4)
#define SOC_QICE_FC_FC_W_QOS2SYS_ALLOW_REMAP0_pri1_remap_qos2sys_allow_w_END (7)
#define SOC_QICE_FC_FC_W_QOS2SYS_ALLOW_REMAP0_pri2_remap_qos2sys_allow_w_START (8)
#define SOC_QICE_FC_FC_W_QOS2SYS_ALLOW_REMAP0_pri2_remap_qos2sys_allow_w_END (11)
#define SOC_QICE_FC_FC_W_QOS2SYS_ALLOW_REMAP0_pri3_remap_qos2sys_allow_w_START (12)
#define SOC_QICE_FC_FC_W_QOS2SYS_ALLOW_REMAP0_pri3_remap_qos2sys_allow_w_END (15)
#define SOC_QICE_FC_FC_W_QOS2SYS_ALLOW_REMAP0_pri4_remap_qos2sys_allow_w_START (16)
#define SOC_QICE_FC_FC_W_QOS2SYS_ALLOW_REMAP0_pri4_remap_qos2sys_allow_w_END (19)
#define SOC_QICE_FC_FC_W_QOS2SYS_ALLOW_REMAP0_pri5_remap_qos2sys_allow_w_START (20)
#define SOC_QICE_FC_FC_W_QOS2SYS_ALLOW_REMAP0_pri5_remap_qos2sys_allow_w_END (23)
#define SOC_QICE_FC_FC_W_QOS2SYS_ALLOW_REMAP0_pri6_remap_qos2sys_allow_w_START (24)
#define SOC_QICE_FC_FC_W_QOS2SYS_ALLOW_REMAP0_pri6_remap_qos2sys_allow_w_END (27)
#define SOC_QICE_FC_FC_W_QOS2SYS_ALLOW_REMAP0_pri7_remap_qos2sys_allow_w_START (28)
#define SOC_QICE_FC_FC_W_QOS2SYS_ALLOW_REMAP0_pri7_remap_qos2sys_allow_w_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pri8_remap_qos2sys_allow_w : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_FC_FC_W_QOS2SYS_ALLOW_REMAP1_UNION;
#endif
#define SOC_QICE_FC_FC_W_QOS2SYS_ALLOW_REMAP1_pri8_remap_qos2sys_allow_w_START (0)
#define SOC_QICE_FC_FC_W_QOS2SYS_ALLOW_REMAP1_pri8_remap_qos2sys_allow_w_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pri0_remap_qos2sc_allow : 4;
        unsigned int pri1_remap_qos2sc_allow : 4;
        unsigned int pri2_remap_qos2sc_allow : 4;
        unsigned int pri3_remap_qos2sc_allow : 4;
        unsigned int pri4_remap_qos2sc_allow : 4;
        unsigned int pri5_remap_qos2sc_allow : 4;
        unsigned int pri6_remap_qos2sc_allow : 4;
        unsigned int pri7_remap_qos2sc_allow : 4;
    } reg;
} SOC_QICE_FC_FC_W_QOS2SC_ALLOW_REMAP0_UNION;
#endif
#define SOC_QICE_FC_FC_W_QOS2SC_ALLOW_REMAP0_pri0_remap_qos2sc_allow_START (0)
#define SOC_QICE_FC_FC_W_QOS2SC_ALLOW_REMAP0_pri0_remap_qos2sc_allow_END (3)
#define SOC_QICE_FC_FC_W_QOS2SC_ALLOW_REMAP0_pri1_remap_qos2sc_allow_START (4)
#define SOC_QICE_FC_FC_W_QOS2SC_ALLOW_REMAP0_pri1_remap_qos2sc_allow_END (7)
#define SOC_QICE_FC_FC_W_QOS2SC_ALLOW_REMAP0_pri2_remap_qos2sc_allow_START (8)
#define SOC_QICE_FC_FC_W_QOS2SC_ALLOW_REMAP0_pri2_remap_qos2sc_allow_END (11)
#define SOC_QICE_FC_FC_W_QOS2SC_ALLOW_REMAP0_pri3_remap_qos2sc_allow_START (12)
#define SOC_QICE_FC_FC_W_QOS2SC_ALLOW_REMAP0_pri3_remap_qos2sc_allow_END (15)
#define SOC_QICE_FC_FC_W_QOS2SC_ALLOW_REMAP0_pri4_remap_qos2sc_allow_START (16)
#define SOC_QICE_FC_FC_W_QOS2SC_ALLOW_REMAP0_pri4_remap_qos2sc_allow_END (19)
#define SOC_QICE_FC_FC_W_QOS2SC_ALLOW_REMAP0_pri5_remap_qos2sc_allow_START (20)
#define SOC_QICE_FC_FC_W_QOS2SC_ALLOW_REMAP0_pri5_remap_qos2sc_allow_END (23)
#define SOC_QICE_FC_FC_W_QOS2SC_ALLOW_REMAP0_pri6_remap_qos2sc_allow_START (24)
#define SOC_QICE_FC_FC_W_QOS2SC_ALLOW_REMAP0_pri6_remap_qos2sc_allow_END (27)
#define SOC_QICE_FC_FC_W_QOS2SC_ALLOW_REMAP0_pri7_remap_qos2sc_allow_START (28)
#define SOC_QICE_FC_FC_W_QOS2SC_ALLOW_REMAP0_pri7_remap_qos2sc_allow_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pri8_remap_qos2sc_allow : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_FC_FC_W_QOS2SC_ALLOW_REMAP1_UNION;
#endif
#define SOC_QICE_FC_FC_W_QOS2SC_ALLOW_REMAP1_pri8_remap_qos2sc_allow_START (0)
#define SOC_QICE_FC_FC_W_QOS2SC_ALLOW_REMAP1_pri8_remap_qos2sc_allow_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pri0_remap_qos2sys_allow_r_vc1 : 4;
        unsigned int pri1_remap_qos2sys_allow_r_vc1 : 4;
        unsigned int pri2_remap_qos2sys_allow_r_vc1 : 4;
        unsigned int pri3_remap_qos2sys_allow_r_vc1 : 4;
        unsigned int pri4_remap_qos2sys_allow_r_vc1 : 4;
        unsigned int pri5_remap_qos2sys_allow_r_vc1 : 4;
        unsigned int pri6_remap_qos2sys_allow_r_vc1 : 4;
        unsigned int pri7_remap_qos2sys_allow_r_vc1 : 4;
    } reg;
} SOC_QICE_FC_FC_R_VC1_QOS2SYS_ALLOW_REMAP0_UNION;
#endif
#define SOC_QICE_FC_FC_R_VC1_QOS2SYS_ALLOW_REMAP0_pri0_remap_qos2sys_allow_r_vc1_START (0)
#define SOC_QICE_FC_FC_R_VC1_QOS2SYS_ALLOW_REMAP0_pri0_remap_qos2sys_allow_r_vc1_END (3)
#define SOC_QICE_FC_FC_R_VC1_QOS2SYS_ALLOW_REMAP0_pri1_remap_qos2sys_allow_r_vc1_START (4)
#define SOC_QICE_FC_FC_R_VC1_QOS2SYS_ALLOW_REMAP0_pri1_remap_qos2sys_allow_r_vc1_END (7)
#define SOC_QICE_FC_FC_R_VC1_QOS2SYS_ALLOW_REMAP0_pri2_remap_qos2sys_allow_r_vc1_START (8)
#define SOC_QICE_FC_FC_R_VC1_QOS2SYS_ALLOW_REMAP0_pri2_remap_qos2sys_allow_r_vc1_END (11)
#define SOC_QICE_FC_FC_R_VC1_QOS2SYS_ALLOW_REMAP0_pri3_remap_qos2sys_allow_r_vc1_START (12)
#define SOC_QICE_FC_FC_R_VC1_QOS2SYS_ALLOW_REMAP0_pri3_remap_qos2sys_allow_r_vc1_END (15)
#define SOC_QICE_FC_FC_R_VC1_QOS2SYS_ALLOW_REMAP0_pri4_remap_qos2sys_allow_r_vc1_START (16)
#define SOC_QICE_FC_FC_R_VC1_QOS2SYS_ALLOW_REMAP0_pri4_remap_qos2sys_allow_r_vc1_END (19)
#define SOC_QICE_FC_FC_R_VC1_QOS2SYS_ALLOW_REMAP0_pri5_remap_qos2sys_allow_r_vc1_START (20)
#define SOC_QICE_FC_FC_R_VC1_QOS2SYS_ALLOW_REMAP0_pri5_remap_qos2sys_allow_r_vc1_END (23)
#define SOC_QICE_FC_FC_R_VC1_QOS2SYS_ALLOW_REMAP0_pri6_remap_qos2sys_allow_r_vc1_START (24)
#define SOC_QICE_FC_FC_R_VC1_QOS2SYS_ALLOW_REMAP0_pri6_remap_qos2sys_allow_r_vc1_END (27)
#define SOC_QICE_FC_FC_R_VC1_QOS2SYS_ALLOW_REMAP0_pri7_remap_qos2sys_allow_r_vc1_START (28)
#define SOC_QICE_FC_FC_R_VC1_QOS2SYS_ALLOW_REMAP0_pri7_remap_qos2sys_allow_r_vc1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pri8_remap_qos2sys_allow_r_vc1 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_FC_FC_R_VC1_QOS2SYS_ALLOW_REMAP1_UNION;
#endif
#define SOC_QICE_FC_FC_R_VC1_QOS2SYS_ALLOW_REMAP1_pri8_remap_qos2sys_allow_r_vc1_START (0)
#define SOC_QICE_FC_FC_R_VC1_QOS2SYS_ALLOW_REMAP1_pri8_remap_qos2sys_allow_r_vc1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pri0_remap_qos2sys_allow_w_vc1 : 4;
        unsigned int pri1_remap_qos2sys_allow_w_vc1 : 4;
        unsigned int pri2_remap_qos2sys_allow_w_vc1 : 4;
        unsigned int pri3_remap_qos2sys_allow_w_vc1 : 4;
        unsigned int pri4_remap_qos2sys_allow_w_vc1 : 4;
        unsigned int pri5_remap_qos2sys_allow_w_vc1 : 4;
        unsigned int pri6_remap_qos2sys_allow_w_vc1 : 4;
        unsigned int pri7_remap_qos2sys_allow_w_vc1 : 4;
    } reg;
} SOC_QICE_FC_FC_W_VC1_QOS2SYS_ALLOW_REMAP0_UNION;
#endif
#define SOC_QICE_FC_FC_W_VC1_QOS2SYS_ALLOW_REMAP0_pri0_remap_qos2sys_allow_w_vc1_START (0)
#define SOC_QICE_FC_FC_W_VC1_QOS2SYS_ALLOW_REMAP0_pri0_remap_qos2sys_allow_w_vc1_END (3)
#define SOC_QICE_FC_FC_W_VC1_QOS2SYS_ALLOW_REMAP0_pri1_remap_qos2sys_allow_w_vc1_START (4)
#define SOC_QICE_FC_FC_W_VC1_QOS2SYS_ALLOW_REMAP0_pri1_remap_qos2sys_allow_w_vc1_END (7)
#define SOC_QICE_FC_FC_W_VC1_QOS2SYS_ALLOW_REMAP0_pri2_remap_qos2sys_allow_w_vc1_START (8)
#define SOC_QICE_FC_FC_W_VC1_QOS2SYS_ALLOW_REMAP0_pri2_remap_qos2sys_allow_w_vc1_END (11)
#define SOC_QICE_FC_FC_W_VC1_QOS2SYS_ALLOW_REMAP0_pri3_remap_qos2sys_allow_w_vc1_START (12)
#define SOC_QICE_FC_FC_W_VC1_QOS2SYS_ALLOW_REMAP0_pri3_remap_qos2sys_allow_w_vc1_END (15)
#define SOC_QICE_FC_FC_W_VC1_QOS2SYS_ALLOW_REMAP0_pri4_remap_qos2sys_allow_w_vc1_START (16)
#define SOC_QICE_FC_FC_W_VC1_QOS2SYS_ALLOW_REMAP0_pri4_remap_qos2sys_allow_w_vc1_END (19)
#define SOC_QICE_FC_FC_W_VC1_QOS2SYS_ALLOW_REMAP0_pri5_remap_qos2sys_allow_w_vc1_START (20)
#define SOC_QICE_FC_FC_W_VC1_QOS2SYS_ALLOW_REMAP0_pri5_remap_qos2sys_allow_w_vc1_END (23)
#define SOC_QICE_FC_FC_W_VC1_QOS2SYS_ALLOW_REMAP0_pri6_remap_qos2sys_allow_w_vc1_START (24)
#define SOC_QICE_FC_FC_W_VC1_QOS2SYS_ALLOW_REMAP0_pri6_remap_qos2sys_allow_w_vc1_END (27)
#define SOC_QICE_FC_FC_W_VC1_QOS2SYS_ALLOW_REMAP0_pri7_remap_qos2sys_allow_w_vc1_START (28)
#define SOC_QICE_FC_FC_W_VC1_QOS2SYS_ALLOW_REMAP0_pri7_remap_qos2sys_allow_w_vc1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pri8_remap_qos2sys_allow_w_vc1 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_FC_FC_W_VC1_QOS2SYS_ALLOW_REMAP1_UNION;
#endif
#define SOC_QICE_FC_FC_W_VC1_QOS2SYS_ALLOW_REMAP1_pri8_remap_qos2sys_allow_w_vc1_START (0)
#define SOC_QICE_FC_FC_W_VC1_QOS2SYS_ALLOW_REMAP1_pri8_remap_qos2sys_allow_w_vc1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pri0_remap_qos2sys_allow_r_vc2 : 4;
        unsigned int pri1_remap_qos2sys_allow_r_vc2 : 4;
        unsigned int pri2_remap_qos2sys_allow_r_vc2 : 4;
        unsigned int pri3_remap_qos2sys_allow_r_vc2 : 4;
        unsigned int pri4_remap_qos2sys_allow_r_vc2 : 4;
        unsigned int pri5_remap_qos2sys_allow_r_vc2 : 4;
        unsigned int pri6_remap_qos2sys_allow_r_vc2 : 4;
        unsigned int pri7_remap_qos2sys_allow_r_vc2 : 4;
    } reg;
} SOC_QICE_FC_FC_R_VC2_QOS2SYS_ALLOW_REMAP0_UNION;
#endif
#define SOC_QICE_FC_FC_R_VC2_QOS2SYS_ALLOW_REMAP0_pri0_remap_qos2sys_allow_r_vc2_START (0)
#define SOC_QICE_FC_FC_R_VC2_QOS2SYS_ALLOW_REMAP0_pri0_remap_qos2sys_allow_r_vc2_END (3)
#define SOC_QICE_FC_FC_R_VC2_QOS2SYS_ALLOW_REMAP0_pri1_remap_qos2sys_allow_r_vc2_START (4)
#define SOC_QICE_FC_FC_R_VC2_QOS2SYS_ALLOW_REMAP0_pri1_remap_qos2sys_allow_r_vc2_END (7)
#define SOC_QICE_FC_FC_R_VC2_QOS2SYS_ALLOW_REMAP0_pri2_remap_qos2sys_allow_r_vc2_START (8)
#define SOC_QICE_FC_FC_R_VC2_QOS2SYS_ALLOW_REMAP0_pri2_remap_qos2sys_allow_r_vc2_END (11)
#define SOC_QICE_FC_FC_R_VC2_QOS2SYS_ALLOW_REMAP0_pri3_remap_qos2sys_allow_r_vc2_START (12)
#define SOC_QICE_FC_FC_R_VC2_QOS2SYS_ALLOW_REMAP0_pri3_remap_qos2sys_allow_r_vc2_END (15)
#define SOC_QICE_FC_FC_R_VC2_QOS2SYS_ALLOW_REMAP0_pri4_remap_qos2sys_allow_r_vc2_START (16)
#define SOC_QICE_FC_FC_R_VC2_QOS2SYS_ALLOW_REMAP0_pri4_remap_qos2sys_allow_r_vc2_END (19)
#define SOC_QICE_FC_FC_R_VC2_QOS2SYS_ALLOW_REMAP0_pri5_remap_qos2sys_allow_r_vc2_START (20)
#define SOC_QICE_FC_FC_R_VC2_QOS2SYS_ALLOW_REMAP0_pri5_remap_qos2sys_allow_r_vc2_END (23)
#define SOC_QICE_FC_FC_R_VC2_QOS2SYS_ALLOW_REMAP0_pri6_remap_qos2sys_allow_r_vc2_START (24)
#define SOC_QICE_FC_FC_R_VC2_QOS2SYS_ALLOW_REMAP0_pri6_remap_qos2sys_allow_r_vc2_END (27)
#define SOC_QICE_FC_FC_R_VC2_QOS2SYS_ALLOW_REMAP0_pri7_remap_qos2sys_allow_r_vc2_START (28)
#define SOC_QICE_FC_FC_R_VC2_QOS2SYS_ALLOW_REMAP0_pri7_remap_qos2sys_allow_r_vc2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pri8_remap_qos2sys_allow_r_vc2 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_FC_FC_R_VC2_QOS2SYS_ALLOW_REMAP1_UNION;
#endif
#define SOC_QICE_FC_FC_R_VC2_QOS2SYS_ALLOW_REMAP1_pri8_remap_qos2sys_allow_r_vc2_START (0)
#define SOC_QICE_FC_FC_R_VC2_QOS2SYS_ALLOW_REMAP1_pri8_remap_qos2sys_allow_r_vc2_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pri0_remap_qos2sys_allow_w_vc2 : 4;
        unsigned int pri1_remap_qos2sys_allow_w_vc2 : 4;
        unsigned int pri2_remap_qos2sys_allow_w_vc2 : 4;
        unsigned int pri3_remap_qos2sys_allow_w_vc2 : 4;
        unsigned int pri4_remap_qos2sys_allow_w_vc2 : 4;
        unsigned int pri5_remap_qos2sys_allow_w_vc2 : 4;
        unsigned int pri6_remap_qos2sys_allow_w_vc2 : 4;
        unsigned int pri7_remap_qos2sys_allow_w_vc2 : 4;
    } reg;
} SOC_QICE_FC_FC_W_VC2_QOS2SYS_ALLOW_REMAP0_UNION;
#endif
#define SOC_QICE_FC_FC_W_VC2_QOS2SYS_ALLOW_REMAP0_pri0_remap_qos2sys_allow_w_vc2_START (0)
#define SOC_QICE_FC_FC_W_VC2_QOS2SYS_ALLOW_REMAP0_pri0_remap_qos2sys_allow_w_vc2_END (3)
#define SOC_QICE_FC_FC_W_VC2_QOS2SYS_ALLOW_REMAP0_pri1_remap_qos2sys_allow_w_vc2_START (4)
#define SOC_QICE_FC_FC_W_VC2_QOS2SYS_ALLOW_REMAP0_pri1_remap_qos2sys_allow_w_vc2_END (7)
#define SOC_QICE_FC_FC_W_VC2_QOS2SYS_ALLOW_REMAP0_pri2_remap_qos2sys_allow_w_vc2_START (8)
#define SOC_QICE_FC_FC_W_VC2_QOS2SYS_ALLOW_REMAP0_pri2_remap_qos2sys_allow_w_vc2_END (11)
#define SOC_QICE_FC_FC_W_VC2_QOS2SYS_ALLOW_REMAP0_pri3_remap_qos2sys_allow_w_vc2_START (12)
#define SOC_QICE_FC_FC_W_VC2_QOS2SYS_ALLOW_REMAP0_pri3_remap_qos2sys_allow_w_vc2_END (15)
#define SOC_QICE_FC_FC_W_VC2_QOS2SYS_ALLOW_REMAP0_pri4_remap_qos2sys_allow_w_vc2_START (16)
#define SOC_QICE_FC_FC_W_VC2_QOS2SYS_ALLOW_REMAP0_pri4_remap_qos2sys_allow_w_vc2_END (19)
#define SOC_QICE_FC_FC_W_VC2_QOS2SYS_ALLOW_REMAP0_pri5_remap_qos2sys_allow_w_vc2_START (20)
#define SOC_QICE_FC_FC_W_VC2_QOS2SYS_ALLOW_REMAP0_pri5_remap_qos2sys_allow_w_vc2_END (23)
#define SOC_QICE_FC_FC_W_VC2_QOS2SYS_ALLOW_REMAP0_pri6_remap_qos2sys_allow_w_vc2_START (24)
#define SOC_QICE_FC_FC_W_VC2_QOS2SYS_ALLOW_REMAP0_pri6_remap_qos2sys_allow_w_vc2_END (27)
#define SOC_QICE_FC_FC_W_VC2_QOS2SYS_ALLOW_REMAP0_pri7_remap_qos2sys_allow_w_vc2_START (28)
#define SOC_QICE_FC_FC_W_VC2_QOS2SYS_ALLOW_REMAP0_pri7_remap_qos2sys_allow_w_vc2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pri8_remap_qos2sys_allow_w_vc2 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_FC_FC_W_VC2_QOS2SYS_ALLOW_REMAP1_UNION;
#endif
#define SOC_QICE_FC_FC_W_VC2_QOS2SYS_ALLOW_REMAP1_pri8_remap_qos2sys_allow_w_vc2_START (0)
#define SOC_QICE_FC_FC_W_VC2_QOS2SYS_ALLOW_REMAP1_pri8_remap_qos2sys_allow_w_vc2_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pri0_remap_qos2sys_allow_r_vc3 : 4;
        unsigned int pri1_remap_qos2sys_allow_r_vc3 : 4;
        unsigned int pri2_remap_qos2sys_allow_r_vc3 : 4;
        unsigned int pri3_remap_qos2sys_allow_r_vc3 : 4;
        unsigned int pri4_remap_qos2sys_allow_r_vc3 : 4;
        unsigned int pri5_remap_qos2sys_allow_r_vc3 : 4;
        unsigned int pri6_remap_qos2sys_allow_r_vc3 : 4;
        unsigned int pri7_remap_qos2sys_allow_r_vc3 : 4;
    } reg;
} SOC_QICE_FC_FC_R_VC3_QOS2SYS_ALLOW_REMAP0_UNION;
#endif
#define SOC_QICE_FC_FC_R_VC3_QOS2SYS_ALLOW_REMAP0_pri0_remap_qos2sys_allow_r_vc3_START (0)
#define SOC_QICE_FC_FC_R_VC3_QOS2SYS_ALLOW_REMAP0_pri0_remap_qos2sys_allow_r_vc3_END (3)
#define SOC_QICE_FC_FC_R_VC3_QOS2SYS_ALLOW_REMAP0_pri1_remap_qos2sys_allow_r_vc3_START (4)
#define SOC_QICE_FC_FC_R_VC3_QOS2SYS_ALLOW_REMAP0_pri1_remap_qos2sys_allow_r_vc3_END (7)
#define SOC_QICE_FC_FC_R_VC3_QOS2SYS_ALLOW_REMAP0_pri2_remap_qos2sys_allow_r_vc3_START (8)
#define SOC_QICE_FC_FC_R_VC3_QOS2SYS_ALLOW_REMAP0_pri2_remap_qos2sys_allow_r_vc3_END (11)
#define SOC_QICE_FC_FC_R_VC3_QOS2SYS_ALLOW_REMAP0_pri3_remap_qos2sys_allow_r_vc3_START (12)
#define SOC_QICE_FC_FC_R_VC3_QOS2SYS_ALLOW_REMAP0_pri3_remap_qos2sys_allow_r_vc3_END (15)
#define SOC_QICE_FC_FC_R_VC3_QOS2SYS_ALLOW_REMAP0_pri4_remap_qos2sys_allow_r_vc3_START (16)
#define SOC_QICE_FC_FC_R_VC3_QOS2SYS_ALLOW_REMAP0_pri4_remap_qos2sys_allow_r_vc3_END (19)
#define SOC_QICE_FC_FC_R_VC3_QOS2SYS_ALLOW_REMAP0_pri5_remap_qos2sys_allow_r_vc3_START (20)
#define SOC_QICE_FC_FC_R_VC3_QOS2SYS_ALLOW_REMAP0_pri5_remap_qos2sys_allow_r_vc3_END (23)
#define SOC_QICE_FC_FC_R_VC3_QOS2SYS_ALLOW_REMAP0_pri6_remap_qos2sys_allow_r_vc3_START (24)
#define SOC_QICE_FC_FC_R_VC3_QOS2SYS_ALLOW_REMAP0_pri6_remap_qos2sys_allow_r_vc3_END (27)
#define SOC_QICE_FC_FC_R_VC3_QOS2SYS_ALLOW_REMAP0_pri7_remap_qos2sys_allow_r_vc3_START (28)
#define SOC_QICE_FC_FC_R_VC3_QOS2SYS_ALLOW_REMAP0_pri7_remap_qos2sys_allow_r_vc3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pri8_remap_qos2sys_allow_r_vc3 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_FC_FC_R_VC3_QOS2SYS_ALLOW_REMAP1_UNION;
#endif
#define SOC_QICE_FC_FC_R_VC3_QOS2SYS_ALLOW_REMAP1_pri8_remap_qos2sys_allow_r_vc3_START (0)
#define SOC_QICE_FC_FC_R_VC3_QOS2SYS_ALLOW_REMAP1_pri8_remap_qos2sys_allow_r_vc3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pri0_remap_qos2sys_allow_w_vc3 : 4;
        unsigned int pri1_remap_qos2sys_allow_w_vc3 : 4;
        unsigned int pri2_remap_qos2sys_allow_w_vc3 : 4;
        unsigned int pri3_remap_qos2sys_allow_w_vc3 : 4;
        unsigned int pri4_remap_qos2sys_allow_w_vc3 : 4;
        unsigned int pri5_remap_qos2sys_allow_w_vc3 : 4;
        unsigned int pri6_remap_qos2sys_allow_w_vc3 : 4;
        unsigned int pri7_remap_qos2sys_allow_w_vc3 : 4;
    } reg;
} SOC_QICE_FC_FC_W_VC3_QOS2SYS_ALLOW_REMAP0_UNION;
#endif
#define SOC_QICE_FC_FC_W_VC3_QOS2SYS_ALLOW_REMAP0_pri0_remap_qos2sys_allow_w_vc3_START (0)
#define SOC_QICE_FC_FC_W_VC3_QOS2SYS_ALLOW_REMAP0_pri0_remap_qos2sys_allow_w_vc3_END (3)
#define SOC_QICE_FC_FC_W_VC3_QOS2SYS_ALLOW_REMAP0_pri1_remap_qos2sys_allow_w_vc3_START (4)
#define SOC_QICE_FC_FC_W_VC3_QOS2SYS_ALLOW_REMAP0_pri1_remap_qos2sys_allow_w_vc3_END (7)
#define SOC_QICE_FC_FC_W_VC3_QOS2SYS_ALLOW_REMAP0_pri2_remap_qos2sys_allow_w_vc3_START (8)
#define SOC_QICE_FC_FC_W_VC3_QOS2SYS_ALLOW_REMAP0_pri2_remap_qos2sys_allow_w_vc3_END (11)
#define SOC_QICE_FC_FC_W_VC3_QOS2SYS_ALLOW_REMAP0_pri3_remap_qos2sys_allow_w_vc3_START (12)
#define SOC_QICE_FC_FC_W_VC3_QOS2SYS_ALLOW_REMAP0_pri3_remap_qos2sys_allow_w_vc3_END (15)
#define SOC_QICE_FC_FC_W_VC3_QOS2SYS_ALLOW_REMAP0_pri4_remap_qos2sys_allow_w_vc3_START (16)
#define SOC_QICE_FC_FC_W_VC3_QOS2SYS_ALLOW_REMAP0_pri4_remap_qos2sys_allow_w_vc3_END (19)
#define SOC_QICE_FC_FC_W_VC3_QOS2SYS_ALLOW_REMAP0_pri5_remap_qos2sys_allow_w_vc3_START (20)
#define SOC_QICE_FC_FC_W_VC3_QOS2SYS_ALLOW_REMAP0_pri5_remap_qos2sys_allow_w_vc3_END (23)
#define SOC_QICE_FC_FC_W_VC3_QOS2SYS_ALLOW_REMAP0_pri6_remap_qos2sys_allow_w_vc3_START (24)
#define SOC_QICE_FC_FC_W_VC3_QOS2SYS_ALLOW_REMAP0_pri6_remap_qos2sys_allow_w_vc3_END (27)
#define SOC_QICE_FC_FC_W_VC3_QOS2SYS_ALLOW_REMAP0_pri7_remap_qos2sys_allow_w_vc3_START (28)
#define SOC_QICE_FC_FC_W_VC3_QOS2SYS_ALLOW_REMAP0_pri7_remap_qos2sys_allow_w_vc3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pri8_remap_qos2sys_allow_w_vc3 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_FC_FC_W_VC3_QOS2SYS_ALLOW_REMAP1_UNION;
#endif
#define SOC_QICE_FC_FC_W_VC3_QOS2SYS_ALLOW_REMAP1_pri8_remap_qos2sys_allow_w_vc3_START (0)
#define SOC_QICE_FC_FC_W_VC3_QOS2SYS_ALLOW_REMAP1_pri8_remap_qos2sys_allow_w_vc3_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_flux_req_msk0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_FC_FC_FLUX_REQ_MSK0_UNION;
#endif
#define SOC_QICE_FC_FC_FLUX_REQ_MSK0_icfg_flux_req_msk0_START (0)
#define SOC_QICE_FC_FC_FLUX_REQ_MSK0_icfg_flux_req_msk0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_flux_req_msk1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_FC_FC_FLUX_REQ_MSK1_UNION;
#endif
#define SOC_QICE_FC_FC_FLUX_REQ_MSK1_icfg_flux_req_msk1_START (0)
#define SOC_QICE_FC_FC_FLUX_REQ_MSK1_icfg_flux_req_msk1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_flux_req_msk2 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_FC_FC_FLUX_REQ_MSK2_UNION;
#endif
#define SOC_QICE_FC_FC_FLUX_REQ_MSK2_icfg_flux_req_msk2_START (0)
#define SOC_QICE_FC_FC_FLUX_REQ_MSK2_icfg_flux_req_msk2_END (7)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
