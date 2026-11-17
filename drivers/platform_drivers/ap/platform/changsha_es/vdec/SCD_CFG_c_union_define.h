#ifndef __SCD_CFG_C_UNION_DEFINE_H__
#define __SCD_CFG_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int list_addr_st_msb : 4 ;
        unsigned int reserved_0 : 12 ;
        unsigned int list_addr_end_msb : 4 ;
        unsigned int reserved_1 : 12 ;
    } bits;
    unsigned int u32;
} U_SCD_CFG_D2;
typedef struct {
    volatile unsigned int SCD_CFG_D0 ;
    volatile unsigned int SCD_CFG_D1 ;
    volatile U_SCD_CFG_D2 SCD_CFG_D2 ;
    volatile unsigned int SCD_CFG_D3 ;
} S_SCD_CFG_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_SCD_CFG_D2 SCD_CFG_D2;
} U_SCD_CFG_REGS_TYPE;
#endif
