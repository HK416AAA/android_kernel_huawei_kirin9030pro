#ifndef __BSPS_SC_C_UNION_DEFINE_H__
#define __BSPS_SC_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int reserved_0 : 13 ;
        unsigned int acc0_pxpc_int_en : 2 ;
        unsigned int reserved_1 : 17 ;
    } bits;
    unsigned int u32;
} U_SC_CTRL_EN0;
typedef union {
    struct {
        unsigned int reserved_0 : 13 ;
        unsigned int acc1_pxpc_int_en : 2 ;
        unsigned int reserved_1 : 17 ;
    } bits;
    unsigned int u32;
} U_SC_CTRL_EN1;
typedef union {
    struct {
        unsigned int riscv2bsp_cmd_acc0_nsf : 1 ;
        unsigned int riscv2bsp_cmd_acc1_nsf : 1 ;
        unsigned int riscv2bsp_cmd_acc2_nsf : 1 ;
        unsigned int riscv2bsp_cmd_acc3_nsf : 1 ;
        unsigned int riscv2bsp_flush_acc0_nsf : 1 ;
        unsigned int riscv2bsp_flush_acc1_nsf : 1 ;
        unsigned int riscv2bsp_flush_acc2_nsf : 1 ;
        unsigned int riscv2bsp_flush_acc3_nsf : 1 ;
        unsigned int reserved_0 : 24 ;
    } bits;
    unsigned int u32;
} U_SC_CTRL_EN4;
typedef union {
    struct {
        unsigned int riscv2bsp_cmd_acc0_sf : 1 ;
        unsigned int riscv2bsp_cmd_acc1_sf : 1 ;
        unsigned int riscv2bsp_cmd_acc2_sf : 1 ;
        unsigned int riscv2bsp_cmd_acc3_sf : 1 ;
        unsigned int riscv2bsp_flush_acc0_sf : 1 ;
        unsigned int riscv2bsp_flush_acc1_sf : 1 ;
        unsigned int riscv2bsp_flush_acc2_sf : 1 ;
        unsigned int riscv2bsp_flush_acc3_sf : 1 ;
        unsigned int riscv2bsp_powerdown : 1 ;
        unsigned int reserved_0 : 23 ;
    } bits;
    unsigned int u32;
} U_SC_CTRL_EN5;
typedef struct {
    volatile unsigned int reserved_0[384] ;
    volatile U_SC_CTRL_EN0 SC_CTRL_EN0 ;
    volatile unsigned int reserved_1[7] ;
    volatile U_SC_CTRL_EN1 SC_CTRL_EN1 ;
    volatile unsigned int reserved_2[7] ;
    volatile unsigned int SC_CTRL_EN2 ;
    volatile unsigned int reserved_3[7] ;
    volatile unsigned int SC_CTRL_EN3 ;
    volatile unsigned int reserved_4[7] ;
    volatile U_SC_CTRL_EN4 SC_CTRL_EN4 ;
    volatile unsigned int reserved_5[7] ;
    volatile U_SC_CTRL_EN5 SC_CTRL_EN5 ;
} S_BSPS_SC_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_SC_CTRL_EN0 SC_CTRL_EN0;
    volatile U_SC_CTRL_EN1 SC_CTRL_EN1;
    volatile U_SC_CTRL_EN4 SC_CTRL_EN4;
    volatile U_SC_CTRL_EN5 SC_CTRL_EN5;
} U_BSPS_SC_REGS_TYPE;
#endif
