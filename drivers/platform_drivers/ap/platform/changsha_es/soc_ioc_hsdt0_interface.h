#ifndef __SOC_IOC_HSDT0_INTERFACE_H__
#define __SOC_IOC_HSDT0_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_IOC_HSDT0_IOCG_SE_0_ADDR(base) ((base) + 0xe00UL)
#define SOC_IOC_HSDT0_IOCG_SE_1_ADDR(base) ((base) + 0xe04UL)
#define SOC_IOC_HSDT0_IOCG_SE_2_ADDR(base) ((base) + 0xe08UL)
#define SOC_IOC_HSDT0_IOCG_SE_3_ADDR(base) ((base) + 0xe0cUL)
#define SOC_IOC_HSDT0_IOCG_SE_4_ADDR(base) ((base) + 0xe10UL)
#define SOC_IOC_HSDT0_IOCG_SE_5_ADDR(base) ((base) + 0xe14UL)
#else
#define SOC_IOC_HSDT0_IOCG_SE_0_ADDR(base) ((base) + 0xe00)
#define SOC_IOC_HSDT0_IOCG_SE_1_ADDR(base) ((base) + 0xe04)
#define SOC_IOC_HSDT0_IOCG_SE_2_ADDR(base) ((base) + 0xe08)
#define SOC_IOC_HSDT0_IOCG_SE_3_ADDR(base) ((base) + 0xe0c)
#define SOC_IOC_HSDT0_IOCG_SE_4_ADDR(base) ((base) + 0xe10)
#define SOC_IOC_HSDT0_IOCG_SE_5_ADDR(base) ((base) + 0xe14)
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_IOC_HSDT0_IOMG_SE_0_ADDR(base) ((base) + 0x600UL)
#define SOC_IOC_HSDT0_IOMG_SE_1_ADDR(base) ((base) + 0x604UL)
#define SOC_IOC_HSDT0_IOMG_SE_2_ADDR(base) ((base) + 0x608UL)
#define SOC_IOC_HSDT0_IOMG_SE_3_ADDR(base) ((base) + 0x60cUL)
#define SOC_IOC_HSDT0_IOMG_SE_4_ADDR(base) ((base) + 0x610UL)
#define SOC_IOC_HSDT0_IOMG_SE_5_ADDR(base) ((base) + 0x614UL)
#else
#define SOC_IOC_HSDT0_IOMG_SE_0_ADDR(base) ((base) + 0x600)
#define SOC_IOC_HSDT0_IOMG_SE_1_ADDR(base) ((base) + 0x604)
#define SOC_IOC_HSDT0_IOMG_SE_2_ADDR(base) ((base) + 0x608)
#define SOC_IOC_HSDT0_IOMG_SE_3_ADDR(base) ((base) + 0x60c)
#define SOC_IOC_HSDT0_IOMG_SE_4_ADDR(base) ((base) + 0x610)
#define SOC_IOC_HSDT0_IOMG_SE_5_ADDR(base) ((base) + 0x614)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_0_pu : 1;
        unsigned int iocg_se_0_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_0_st : 1;
        unsigned int iocg_se_0_ds0 : 1;
        unsigned int iocg_se_0_ds1 : 1;
        unsigned int iocg_se_0_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_0_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_HSDT0_IOCG_SE_0_UNION;
#endif
#define SOC_IOC_HSDT0_IOCG_SE_0_iocg_se_0_pu_START (0)
#define SOC_IOC_HSDT0_IOCG_SE_0_iocg_se_0_pu_END (0)
#define SOC_IOC_HSDT0_IOCG_SE_0_iocg_se_0_pd_START (1)
#define SOC_IOC_HSDT0_IOCG_SE_0_iocg_se_0_pd_END (1)
#define SOC_IOC_HSDT0_IOCG_SE_0_iocg_se_0_st_START (3)
#define SOC_IOC_HSDT0_IOCG_SE_0_iocg_se_0_st_END (3)
#define SOC_IOC_HSDT0_IOCG_SE_0_iocg_se_0_ds0_START (4)
#define SOC_IOC_HSDT0_IOCG_SE_0_iocg_se_0_ds0_END (4)
#define SOC_IOC_HSDT0_IOCG_SE_0_iocg_se_0_ds1_START (5)
#define SOC_IOC_HSDT0_IOCG_SE_0_iocg_se_0_ds1_END (5)
#define SOC_IOC_HSDT0_IOCG_SE_0_iocg_se_0_ds2_START (6)
#define SOC_IOC_HSDT0_IOCG_SE_0_iocg_se_0_ds2_END (6)
#define SOC_IOC_HSDT0_IOCG_SE_0_iocg_se_0_sl_START (8)
#define SOC_IOC_HSDT0_IOCG_SE_0_iocg_se_0_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_1_pu : 1;
        unsigned int iocg_se_1_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_1_st : 1;
        unsigned int iocg_se_1_ds0 : 1;
        unsigned int iocg_se_1_ds1 : 1;
        unsigned int iocg_se_1_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_1_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_HSDT0_IOCG_SE_1_UNION;
#endif
#define SOC_IOC_HSDT0_IOCG_SE_1_iocg_se_1_pu_START (0)
#define SOC_IOC_HSDT0_IOCG_SE_1_iocg_se_1_pu_END (0)
#define SOC_IOC_HSDT0_IOCG_SE_1_iocg_se_1_pd_START (1)
#define SOC_IOC_HSDT0_IOCG_SE_1_iocg_se_1_pd_END (1)
#define SOC_IOC_HSDT0_IOCG_SE_1_iocg_se_1_st_START (3)
#define SOC_IOC_HSDT0_IOCG_SE_1_iocg_se_1_st_END (3)
#define SOC_IOC_HSDT0_IOCG_SE_1_iocg_se_1_ds0_START (4)
#define SOC_IOC_HSDT0_IOCG_SE_1_iocg_se_1_ds0_END (4)
#define SOC_IOC_HSDT0_IOCG_SE_1_iocg_se_1_ds1_START (5)
#define SOC_IOC_HSDT0_IOCG_SE_1_iocg_se_1_ds1_END (5)
#define SOC_IOC_HSDT0_IOCG_SE_1_iocg_se_1_ds2_START (6)
#define SOC_IOC_HSDT0_IOCG_SE_1_iocg_se_1_ds2_END (6)
#define SOC_IOC_HSDT0_IOCG_SE_1_iocg_se_1_sl_START (8)
#define SOC_IOC_HSDT0_IOCG_SE_1_iocg_se_1_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_2_pu : 1;
        unsigned int iocg_se_2_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_2_st : 1;
        unsigned int iocg_se_2_ds0 : 1;
        unsigned int iocg_se_2_ds1 : 1;
        unsigned int iocg_se_2_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_2_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_HSDT0_IOCG_SE_2_UNION;
#endif
#define SOC_IOC_HSDT0_IOCG_SE_2_iocg_se_2_pu_START (0)
#define SOC_IOC_HSDT0_IOCG_SE_2_iocg_se_2_pu_END (0)
#define SOC_IOC_HSDT0_IOCG_SE_2_iocg_se_2_pd_START (1)
#define SOC_IOC_HSDT0_IOCG_SE_2_iocg_se_2_pd_END (1)
#define SOC_IOC_HSDT0_IOCG_SE_2_iocg_se_2_st_START (3)
#define SOC_IOC_HSDT0_IOCG_SE_2_iocg_se_2_st_END (3)
#define SOC_IOC_HSDT0_IOCG_SE_2_iocg_se_2_ds0_START (4)
#define SOC_IOC_HSDT0_IOCG_SE_2_iocg_se_2_ds0_END (4)
#define SOC_IOC_HSDT0_IOCG_SE_2_iocg_se_2_ds1_START (5)
#define SOC_IOC_HSDT0_IOCG_SE_2_iocg_se_2_ds1_END (5)
#define SOC_IOC_HSDT0_IOCG_SE_2_iocg_se_2_ds2_START (6)
#define SOC_IOC_HSDT0_IOCG_SE_2_iocg_se_2_ds2_END (6)
#define SOC_IOC_HSDT0_IOCG_SE_2_iocg_se_2_sl_START (8)
#define SOC_IOC_HSDT0_IOCG_SE_2_iocg_se_2_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_3_pu : 1;
        unsigned int iocg_se_3_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_3_st : 1;
        unsigned int iocg_se_3_ds0 : 1;
        unsigned int iocg_se_3_ds1 : 1;
        unsigned int iocg_se_3_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_3_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_HSDT0_IOCG_SE_3_UNION;
#endif
#define SOC_IOC_HSDT0_IOCG_SE_3_iocg_se_3_pu_START (0)
#define SOC_IOC_HSDT0_IOCG_SE_3_iocg_se_3_pu_END (0)
#define SOC_IOC_HSDT0_IOCG_SE_3_iocg_se_3_pd_START (1)
#define SOC_IOC_HSDT0_IOCG_SE_3_iocg_se_3_pd_END (1)
#define SOC_IOC_HSDT0_IOCG_SE_3_iocg_se_3_st_START (3)
#define SOC_IOC_HSDT0_IOCG_SE_3_iocg_se_3_st_END (3)
#define SOC_IOC_HSDT0_IOCG_SE_3_iocg_se_3_ds0_START (4)
#define SOC_IOC_HSDT0_IOCG_SE_3_iocg_se_3_ds0_END (4)
#define SOC_IOC_HSDT0_IOCG_SE_3_iocg_se_3_ds1_START (5)
#define SOC_IOC_HSDT0_IOCG_SE_3_iocg_se_3_ds1_END (5)
#define SOC_IOC_HSDT0_IOCG_SE_3_iocg_se_3_ds2_START (6)
#define SOC_IOC_HSDT0_IOCG_SE_3_iocg_se_3_ds2_END (6)
#define SOC_IOC_HSDT0_IOCG_SE_3_iocg_se_3_sl_START (8)
#define SOC_IOC_HSDT0_IOCG_SE_3_iocg_se_3_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_4_pu : 1;
        unsigned int iocg_se_4_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_4_st : 1;
        unsigned int iocg_se_4_ds0 : 1;
        unsigned int iocg_se_4_ds1 : 1;
        unsigned int iocg_se_4_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_4_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_HSDT0_IOCG_SE_4_UNION;
#endif
#define SOC_IOC_HSDT0_IOCG_SE_4_iocg_se_4_pu_START (0)
#define SOC_IOC_HSDT0_IOCG_SE_4_iocg_se_4_pu_END (0)
#define SOC_IOC_HSDT0_IOCG_SE_4_iocg_se_4_pd_START (1)
#define SOC_IOC_HSDT0_IOCG_SE_4_iocg_se_4_pd_END (1)
#define SOC_IOC_HSDT0_IOCG_SE_4_iocg_se_4_st_START (3)
#define SOC_IOC_HSDT0_IOCG_SE_4_iocg_se_4_st_END (3)
#define SOC_IOC_HSDT0_IOCG_SE_4_iocg_se_4_ds0_START (4)
#define SOC_IOC_HSDT0_IOCG_SE_4_iocg_se_4_ds0_END (4)
#define SOC_IOC_HSDT0_IOCG_SE_4_iocg_se_4_ds1_START (5)
#define SOC_IOC_HSDT0_IOCG_SE_4_iocg_se_4_ds1_END (5)
#define SOC_IOC_HSDT0_IOCG_SE_4_iocg_se_4_ds2_START (6)
#define SOC_IOC_HSDT0_IOCG_SE_4_iocg_se_4_ds2_END (6)
#define SOC_IOC_HSDT0_IOCG_SE_4_iocg_se_4_sl_START (8)
#define SOC_IOC_HSDT0_IOCG_SE_4_iocg_se_4_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iocg_se_5_pu : 1;
        unsigned int iocg_se_5_pd : 1;
        unsigned int reserved_0 : 1;
        unsigned int iocg_se_5_st : 1;
        unsigned int iocg_se_5_ds0 : 1;
        unsigned int iocg_se_5_ds1 : 1;
        unsigned int iocg_se_5_ds2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int iocg_se_5_sl : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_IOC_HSDT0_IOCG_SE_5_UNION;
#endif
#define SOC_IOC_HSDT0_IOCG_SE_5_iocg_se_5_pu_START (0)
#define SOC_IOC_HSDT0_IOCG_SE_5_iocg_se_5_pu_END (0)
#define SOC_IOC_HSDT0_IOCG_SE_5_iocg_se_5_pd_START (1)
#define SOC_IOC_HSDT0_IOCG_SE_5_iocg_se_5_pd_END (1)
#define SOC_IOC_HSDT0_IOCG_SE_5_iocg_se_5_st_START (3)
#define SOC_IOC_HSDT0_IOCG_SE_5_iocg_se_5_st_END (3)
#define SOC_IOC_HSDT0_IOCG_SE_5_iocg_se_5_ds0_START (4)
#define SOC_IOC_HSDT0_IOCG_SE_5_iocg_se_5_ds0_END (4)
#define SOC_IOC_HSDT0_IOCG_SE_5_iocg_se_5_ds1_START (5)
#define SOC_IOC_HSDT0_IOCG_SE_5_iocg_se_5_ds1_END (5)
#define SOC_IOC_HSDT0_IOCG_SE_5_iocg_se_5_ds2_START (6)
#define SOC_IOC_HSDT0_IOCG_SE_5_iocg_se_5_ds2_END (6)
#define SOC_IOC_HSDT0_IOCG_SE_5_iocg_se_5_sl_START (8)
#define SOC_IOC_HSDT0_IOCG_SE_5_iocg_se_5_sl_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_0 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_IOC_HSDT0_IOMG_SE_0_UNION;
#endif
#define SOC_IOC_HSDT0_IOMG_SE_0_iomg_se_0_START (0)
#define SOC_IOC_HSDT0_IOMG_SE_0_iomg_se_0_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_1 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_IOC_HSDT0_IOMG_SE_1_UNION;
#endif
#define SOC_IOC_HSDT0_IOMG_SE_1_iomg_se_1_START (0)
#define SOC_IOC_HSDT0_IOMG_SE_1_iomg_se_1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_2 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_HSDT0_IOMG_SE_2_UNION;
#endif
#define SOC_IOC_HSDT0_IOMG_SE_2_iomg_se_2_START (0)
#define SOC_IOC_HSDT0_IOMG_SE_2_iomg_se_2_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_3 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOC_HSDT0_IOMG_SE_3_UNION;
#endif
#define SOC_IOC_HSDT0_IOMG_SE_3_iomg_se_3_START (0)
#define SOC_IOC_HSDT0_IOMG_SE_3_iomg_se_3_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_4 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_IOC_HSDT0_IOMG_SE_4_UNION;
#endif
#define SOC_IOC_HSDT0_IOMG_SE_4_iomg_se_4_START (0)
#define SOC_IOC_HSDT0_IOMG_SE_4_iomg_se_4_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomg_se_5 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_IOC_HSDT0_IOMG_SE_5_UNION;
#endif
#define SOC_IOC_HSDT0_IOMG_SE_5_iomg_se_5_START (0)
#define SOC_IOC_HSDT0_IOMG_SE_5_iomg_se_5_END (1)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
