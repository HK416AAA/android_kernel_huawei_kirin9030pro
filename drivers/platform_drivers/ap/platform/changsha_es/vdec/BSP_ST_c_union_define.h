#ifndef __BSP_ST_C_UNION_DEFINE_H__
#define __BSP_ST_C_UNION_DEFINE_H__ 
typedef union
{
    struct
    {
        unsigned int task_early_end_error_cnt : 16 ;
        unsigned int task_no_end_error_cnt : 16 ;
    } bits;
    unsigned int u32;
} U_BSP_MSG_D4;
typedef union
{
    struct
    {
        unsigned int bs_over_error_cnt : 16 ;
        unsigned int bs_redund_error_cnt : 16 ;
    } bits;
    unsigned int u32;
} U_BSP_MSG_D5;
typedef union
{
    struct
    {
        unsigned int dec_para_error_cnt : 16 ;
        unsigned int bs_value_error_cnt : 16 ;
    } bits;
    unsigned int u32;
} U_BSP_MSG_D6;
typedef union
{
    struct
    {
        unsigned int bs_ofst_error_cnt : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_BSP_MSG_D7;
typedef struct
{
    unsigned int BSP_MSG_D0;
    unsigned int BSP_MSG_D1;
    unsigned int BSP_MSG_D2;
    unsigned int BSP_MSG_D3;
    U_BSP_MSG_D4 BSP_MSG_D4;
    U_BSP_MSG_D5 BSP_MSG_D5;
    U_BSP_MSG_D6 BSP_MSG_D6;
    U_BSP_MSG_D7 BSP_MSG_D7;
    unsigned int BSP_MSG_D8;
} S_BSP_ST_REGS_TYPE;
typedef union {
    unsigned int u32;
} U_BSP_ST_REGS_TYPE;
#endif
