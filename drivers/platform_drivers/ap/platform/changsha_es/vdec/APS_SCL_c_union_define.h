#ifndef __APS_SCL_C_UNION_DEFINE_H__
#define __APS_SCL_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int q16x16_dc0 : 8 ;
        unsigned int q16x16_dc1 : 8 ;
        unsigned int q16x16_dc2 : 8 ;
        unsigned int q16x16_dc3 : 8 ;
    } bits;
    unsigned int u32;
} U_APS_QM_D346;
typedef union {
    struct {
        unsigned int q16x16_dc4 : 8 ;
        unsigned int q16x16_dc5 : 8 ;
        unsigned int q32x32_dc0 : 8 ;
        unsigned int q32x32_dc1 : 8 ;
    } bits;
    unsigned int u32;
} U_APS_QM_D347;
typedef union {
    struct {
        unsigned int q32x32_dc2 : 8 ;
        unsigned int q32x32_dc3 : 8 ;
        unsigned int q32x32_dc4 : 8 ;
        unsigned int q32x32_dc5 : 8 ;
    } bits;
    unsigned int u32;
} U_APS_QM_D348;
typedef union {
    struct {
        unsigned int reserved_0 : 8 ;
        unsigned int reserved_1 : 8 ;
        unsigned int q64x64_dc0 : 8 ;
        unsigned int q64x64_dc1 : 8 ;
    } bits;
    unsigned int u32;
} U_APS_QM_D349;
typedef struct {
    volatile unsigned int APS_QM_D0[16] ;
    volatile unsigned int APS_QM_D16[16] ;
    volatile unsigned int APS_QM_D32[16] ;
    volatile unsigned int APS_QM_D48[16] ;
    volatile unsigned int APS_QM_D64[16] ;
    volatile unsigned int APS_QM_D80[16] ;
    volatile unsigned int APS_QM_D96[16] ;
    volatile unsigned int APS_QM_D112[16] ;
    volatile unsigned int APS_QM_D128[16] ;
    volatile unsigned int APS_QM_D144[16] ;
    volatile unsigned int APS_QM_D160[16] ;
    volatile unsigned int APS_QM_D176[16] ;
    volatile unsigned int APS_QM_D192[16] ;
    volatile unsigned int APS_QM_D208[16] ;
    volatile unsigned int APS_QM_D224[16] ;
    volatile unsigned int APS_QM_D240[16] ;
    volatile unsigned int APS_QM_D256[16] ;
    volatile unsigned int APS_QM_D272[16] ;
    volatile unsigned int APS_QM_D288[16] ;
    volatile unsigned int APS_QM_D304[16] ;
    volatile unsigned int APS_QM_D320[4] ;
    volatile unsigned int APS_QM_D324[4] ;
    volatile unsigned int APS_QM_D328[4] ;
    volatile unsigned int APS_QM_D332[4] ;
    volatile unsigned int APS_QM_D336[4] ;
    volatile unsigned int APS_QM_D340[4] ;
    volatile unsigned int APS_QM_D344 ;
    volatile unsigned int APS_QM_D345 ;
    volatile U_APS_QM_D346 APS_QM_D346 ;
    volatile U_APS_QM_D347 APS_QM_D347 ;
    volatile U_APS_QM_D348 APS_QM_D348 ;
    volatile U_APS_QM_D349 APS_QM_D349 ;
    volatile unsigned int reserved0 ;
    volatile unsigned int reserved1 ;
} S_APS_SCL_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_APS_QM_D346 APS_QM_D346;
    volatile U_APS_QM_D347 APS_QM_D347;
    volatile U_APS_QM_D348 APS_QM_D348;
    volatile U_APS_QM_D349 APS_QM_D349;
} U_APS_SCL_REGS_TYPE;
#endif
