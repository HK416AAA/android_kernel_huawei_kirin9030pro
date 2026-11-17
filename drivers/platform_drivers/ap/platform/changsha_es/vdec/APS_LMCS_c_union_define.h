#ifndef __APS_LMCS_C_UNION_DEFINE_H__
#define __APS_LMCS_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int lmcs_pivot_tb : 10 ;
        unsigned int lmcs_bin_idx_tb : 4 ;
        unsigned int reserved_0 : 2 ;
        unsigned int lmcs_chroma_scale_tb : 16 ;
    } bits;
    unsigned int u32;
} U_APS_LMCS_D0;
typedef union {
    struct {
        unsigned int lmcs_invscale_coeff_tb : 16 ;
        unsigned int lmcs_scale_coeff_tb : 16 ;
    } bits;
    unsigned int u32;
} U_APS_LMCS_D16;
typedef struct {
    volatile U_APS_LMCS_D0 APS_LMCS_D0[16] ;
    volatile U_APS_LMCS_D16 APS_LMCS_D16[16] ;
} S_APS_LMCS_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_APS_LMCS_D0 APS_LMCS_D0;
    volatile U_APS_LMCS_D16 APS_LMCS_D16;
} U_APS_LMCS_REGS_TYPE;
#endif
