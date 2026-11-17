#ifndef __PXP_ST_C_UNION_DEFINE_H__
#define __PXP_ST_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int qp_y_min : 8 ;
        unsigned int qp_y_max : 8 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_CMDBUF_D4;
typedef union {
    struct {
        unsigned int qp_u_min : 8 ;
        unsigned int qp_u_max : 8 ;
        unsigned int qp_v_min : 8 ;
        unsigned int qp_v_max : 8 ;
    } bits;
    unsigned int u32;
} U_CMDBUF_D5;
typedef struct {
    volatile unsigned int PRC_MSG_D0_D7[8] ;
    volatile unsigned int PRS_MSG_D0_D7[8] ;
    volatile unsigned int PRF_MSG_D0_D7[8] ;
    volatile unsigned int IQIT_MSG_D0_D7[8] ;
    volatile unsigned int INTRA_MSG_D0_D7[8] ;
    volatile unsigned int RCN_MSG_D0_D7[8] ;
    volatile unsigned int CMDBUF_D0 ;
    volatile unsigned int CMDBUF_D1 ;
    volatile unsigned int CMDBUF_D2 ;
    volatile unsigned int CMDBUF_D3 ;
    volatile U_CMDBUF_D4 CMDBUF_D4 ;
    volatile U_CMDBUF_D5 CMDBUF_D5 ;
    volatile unsigned int CMDBUF_D6 ;
    volatile unsigned int CMDBUF_D7 ;
    volatile unsigned int CMDBUF_D8 ;
    volatile unsigned int CMDBUF_D9 ;
    volatile unsigned int CMDBUF_D10 ;
    volatile unsigned int CMDBUF_D11 ;
    volatile unsigned int CMDBUF_D12 ;
    volatile unsigned int CMDBUF_D13 ;
    volatile unsigned int CMDBUF_D14 ;
    volatile unsigned int CMDBUF_D15 ;
    volatile unsigned int CMDBUF_D16_D31[16] ;
    volatile unsigned int LPF_MSG_D0_D15[16] ;
    volatile unsigned int PXPH_MSG_D0_D7[8] ;
    volatile unsigned int VCTRL_MSG_D0_D15[16] ;
    volatile unsigned int VCTRL_MSG_D16 ;
    volatile unsigned int VCTRL_MSG_D17 ;
    volatile unsigned int VCTRL_MSG_D18 ;
    volatile unsigned int VCTRL_MSG_D19 ;
    volatile unsigned int VCTRL_MSG_D20 ;
    volatile unsigned int VCTRL_MSG_D21 ;
    volatile unsigned int VCTRL_MSG_D22 ;
    volatile unsigned int VCTRL_MSG_D23 ;
} S_PXP_ST_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_CMDBUF_D4 CMDBUF_D4;
    volatile U_CMDBUF_D5 CMDBUF_D5;
} U_PXP_ST_REGS_TYPE;
#endif
