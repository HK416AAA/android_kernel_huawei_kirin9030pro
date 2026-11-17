#ifndef __SCD_ST_C_UNION_DEFINE_H__
#define __SCD_ST_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int scr_eaten : 30 ;
        unsigned int slice_flag : 1 ;
        unsigned int reserved_0 : 1 ;
    } bits;
    unsigned int u32;
} U_SCD_ST_D1;
typedef union {
    struct {
        unsigned int reserved_0 : 28 ;
        unsigned int sc_addr_offset_msb : 4 ;
    } bits;
    unsigned int u32;
} U_SCD_ST_D2;
typedef struct {
    volatile unsigned int SCD_ST_D0 ;
    volatile U_SCD_ST_D1 SCD_ST_D1 ;
    volatile U_SCD_ST_D2 SCD_ST_D2 ;
} S_SCD_ST_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_SCD_ST_D1 SCD_ST_D1;
    volatile U_SCD_ST_D2 SCD_ST_D2;
} U_SCD_ST_REGS_TYPE;
#endif
