#ifndef __SOC_UPC_EFUSEC_INTERFACE_H__
#define __SOC_UPC_EFUSEC_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_UPC_EFUSEC_EFUSEC_CFG_ADDR(base) ((base) + (0x000UL))
#define SOC_UPC_EFUSEC_EFUSEC_STATUS_ADDR(base) ((base) + (0x004UL))
#define SOC_UPC_EFUSEC_EFUSE_GROUP_ADDR(base) ((base) + (0x008UL))
#define SOC_UPC_EFUSEC_PG_VALUE_ADDR(base) ((base) + (0x00CUL))
#define SOC_UPC_EFUSEC_EFUSEC_COUNT_ADDR(base) ((base) + (0x010UL))
#define SOC_UPC_EFUSEC_PGM_COUNT_ADDR(base) ((base) + (0x014UL))
#define SOC_UPC_EFUSEC_EFUSEC_DATA_ADDR(base) ((base) + (0x018UL))
#define SOC_UPC_EFUSEC_HW_CFG_ADDR(base) ((base) + (0x01CUL))
#define SOC_UPC_EFUSEC_EFUSE_COUNT_RD_WRNEXTWR_ADDR(base) ((base) + (0x024UL))
#else
#define SOC_UPC_EFUSEC_EFUSEC_CFG_ADDR(base) ((base) + (0x000))
#define SOC_UPC_EFUSEC_EFUSEC_STATUS_ADDR(base) ((base) + (0x004))
#define SOC_UPC_EFUSEC_EFUSE_GROUP_ADDR(base) ((base) + (0x008))
#define SOC_UPC_EFUSEC_PG_VALUE_ADDR(base) ((base) + (0x00C))
#define SOC_UPC_EFUSEC_EFUSEC_COUNT_ADDR(base) ((base) + (0x010))
#define SOC_UPC_EFUSEC_PGM_COUNT_ADDR(base) ((base) + (0x014))
#define SOC_UPC_EFUSEC_EFUSEC_DATA_ADDR(base) ((base) + (0x018))
#define SOC_UPC_EFUSEC_HW_CFG_ADDR(base) ((base) + (0x01C))
#define SOC_UPC_EFUSEC_EFUSE_COUNT_RD_WRNEXTWR_ADDR(base) ((base) + (0x024))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pgen : 1;
        unsigned int pre_pg : 1;
        unsigned int rden : 1;
        unsigned int aib_sel : 1;
        unsigned int reserved : 1;
        unsigned int pd_en : 1;
        unsigned int mr_en : 1;
        unsigned int undefined : 25;
    } reg;
} SOC_UPC_EFUSEC_EFUSEC_CFG_UNION;
#endif
#define SOC_UPC_EFUSEC_EFUSEC_CFG_pgen_START (0)
#define SOC_UPC_EFUSEC_EFUSEC_CFG_pgen_END (0)
#define SOC_UPC_EFUSEC_EFUSEC_CFG_pre_pg_START (1)
#define SOC_UPC_EFUSEC_EFUSEC_CFG_pre_pg_END (1)
#define SOC_UPC_EFUSEC_EFUSEC_CFG_rden_START (2)
#define SOC_UPC_EFUSEC_EFUSEC_CFG_rden_END (2)
#define SOC_UPC_EFUSEC_EFUSEC_CFG_aib_sel_START (3)
#define SOC_UPC_EFUSEC_EFUSEC_CFG_aib_sel_END (3)
#define SOC_UPC_EFUSEC_EFUSEC_CFG_pd_en_START (5)
#define SOC_UPC_EFUSEC_EFUSEC_CFG_pd_en_END (5)
#define SOC_UPC_EFUSEC_EFUSEC_CFG_mr_en_START (6)
#define SOC_UPC_EFUSEC_EFUSEC_CFG_mr_en_END (6)
#define SOC_UPC_EFUSEC_EFUSEC_CFG_undefined_START (7)
#define SOC_UPC_EFUSEC_EFUSEC_CFG_undefined_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pg_status : 1;
        unsigned int rd_status : 1;
        unsigned int pgenb_status : 1;
        unsigned int rd_error : 1;
        unsigned int pd_status : 1;
        unsigned int undefined : 27;
    } reg;
} SOC_UPC_EFUSEC_EFUSEC_STATUS_UNION;
#endif
#define SOC_UPC_EFUSEC_EFUSEC_STATUS_pg_status_START (0)
#define SOC_UPC_EFUSEC_EFUSEC_STATUS_pg_status_END (0)
#define SOC_UPC_EFUSEC_EFUSEC_STATUS_rd_status_START (1)
#define SOC_UPC_EFUSEC_EFUSEC_STATUS_rd_status_END (1)
#define SOC_UPC_EFUSEC_EFUSEC_STATUS_pgenb_status_START (2)
#define SOC_UPC_EFUSEC_EFUSEC_STATUS_pgenb_status_END (2)
#define SOC_UPC_EFUSEC_EFUSEC_STATUS_rd_error_START (3)
#define SOC_UPC_EFUSEC_EFUSEC_STATUS_rd_error_END (3)
#define SOC_UPC_EFUSEC_EFUSEC_STATUS_pd_status_START (4)
#define SOC_UPC_EFUSEC_EFUSEC_STATUS_pd_status_END (4)
#define SOC_UPC_EFUSEC_EFUSEC_STATUS_undefined_START (5)
#define SOC_UPC_EFUSEC_EFUSEC_STATUS_undefined_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efuse_group : 7;
        unsigned int undefined : 25;
    } reg;
} SOC_UPC_EFUSEC_EFUSE_GROUP_UNION;
#endif
#define SOC_UPC_EFUSEC_EFUSE_GROUP_efuse_group_START (0)
#define SOC_UPC_EFUSEC_EFUSE_GROUP_efuse_group_END (6)
#define SOC_UPC_EFUSEC_EFUSE_GROUP_undefined_START (7)
#define SOC_UPC_EFUSEC_EFUSE_GROUP_undefined_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pg_value : 32;
    } reg;
} SOC_UPC_EFUSEC_PG_VALUE_UNION;
#endif
#define SOC_UPC_EFUSEC_PG_VALUE_pg_value_START (0)
#define SOC_UPC_EFUSEC_PG_VALUE_pg_value_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efusec_count : 8;
        unsigned int undefined : 24;
    } reg;
} SOC_UPC_EFUSEC_EFUSEC_COUNT_UNION;
#endif
#define SOC_UPC_EFUSEC_EFUSEC_COUNT_efusec_count_START (0)
#define SOC_UPC_EFUSEC_EFUSEC_COUNT_efusec_count_END (7)
#define SOC_UPC_EFUSEC_EFUSEC_COUNT_undefined_START (8)
#define SOC_UPC_EFUSEC_EFUSEC_COUNT_undefined_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pgm_count : 16;
        unsigned int undefined : 16;
    } reg;
} SOC_UPC_EFUSEC_PGM_COUNT_UNION;
#endif
#define SOC_UPC_EFUSEC_PGM_COUNT_pgm_count_START (0)
#define SOC_UPC_EFUSEC_PGM_COUNT_pgm_count_END (15)
#define SOC_UPC_EFUSEC_PGM_COUNT_undefined_START (16)
#define SOC_UPC_EFUSEC_PGM_COUNT_undefined_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efusec_data : 32;
    } reg;
} SOC_UPC_EFUSEC_EFUSEC_DATA_UNION;
#endif
#define SOC_UPC_EFUSEC_EFUSEC_DATA_efusec_data_START (0)
#define SOC_UPC_EFUSEC_EFUSEC_DATA_efusec_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int undefined : 32;
    } reg;
} SOC_UPC_EFUSEC_HW_CFG_UNION;
#endif
#define SOC_UPC_EFUSEC_HW_CFG_undefined_START (0)
#define SOC_UPC_EFUSEC_HW_CFG_undefined_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int efusec_count_rd : 8;
        unsigned int efusec_count_wr_wait_nextwr : 8;
        unsigned int undefined : 16;
    } reg;
} SOC_UPC_EFUSEC_EFUSE_COUNT_RD_WRNEXTWR_UNION;
#endif
#define SOC_UPC_EFUSEC_EFUSE_COUNT_RD_WRNEXTWR_efusec_count_rd_START (0)
#define SOC_UPC_EFUSEC_EFUSE_COUNT_RD_WRNEXTWR_efusec_count_rd_END (7)
#define SOC_UPC_EFUSEC_EFUSE_COUNT_RD_WRNEXTWR_efusec_count_wr_wait_nextwr_START (8)
#define SOC_UPC_EFUSEC_EFUSE_COUNT_RD_WRNEXTWR_efusec_count_wr_wait_nextwr_END (15)
#define SOC_UPC_EFUSEC_EFUSE_COUNT_RD_WRNEXTWR_undefined_START (16)
#define SOC_UPC_EFUSEC_EFUSE_COUNT_RD_WRNEXTWR_undefined_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
