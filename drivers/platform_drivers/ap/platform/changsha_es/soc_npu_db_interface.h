#ifndef __SOC_NPU_DB_INTERFACE_H__
#define __SOC_NPU_DB_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_DB_RAM_CONFIG_ADDR(base) ((base) + (0x0000UL))
#define SOC_NPU_DB_ECC_INT_MASK_ADDR(base) ((base) + (0x0008UL))
#define SOC_NPU_DB_ECC_INT_STATUS_ADDR(base) ((base) + (0x000cUL))
#define SOC_NPU_DB_DB_INT_SUMMARY_ADDR(base) ((base) + (0x0010UL))
#define SOC_NPU_DB_DB_INT_MASK0_ADDR(base) ((base) + (0x0020UL))
#define SOC_NPU_DB_DB_INT_MASK1_ADDR(base) ((base) + (0x0024UL))
#define SOC_NPU_DB_DB_INT_MASK2_ADDR(base) ((base) + (0x0028UL))
#define SOC_NPU_DB_DB_INT_MASK3_ADDR(base) ((base) + (0x002cUL))
#define SOC_NPU_DB_DB_INT_STATUS0_ADDR(base) ((base) + (0x00a0UL))
#define SOC_NPU_DB_DB_INT_STATUS1_ADDR(base) ((base) + (0x00a4UL))
#define SOC_NPU_DB_DB_INT_STATUS2_ADDR(base) ((base) + (0x00a8UL))
#define SOC_NPU_DB_DB_INT_STATUS3_ADDR(base) ((base) + (0x00acUL))
#define SOC_NPU_DB_DB_SEC_REG_ADDR(base) ((base) + (0x0200UL))
#define SOC_NPU_DB_DB_SEC_MID0_REG_ADDR(base) ((base) + (0x0210UL))
#define SOC_NPU_DB_DB_SEC_MID1_REG_ADDR(base) ((base) + (0x0214UL))
#define SOC_NPU_DB_DB_SEC_MID2_REG_ADDR(base) ((base) + (0x0218UL))
#define SOC_NPU_DB_DB_SEC_MID3_REG_ADDR(base) ((base) + (0x021cUL))
#else
#define SOC_NPU_DB_RAM_CONFIG_ADDR(base) ((base) + (0x0000))
#define SOC_NPU_DB_ECC_INT_MASK_ADDR(base) ((base) + (0x0008))
#define SOC_NPU_DB_ECC_INT_STATUS_ADDR(base) ((base) + (0x000c))
#define SOC_NPU_DB_DB_INT_SUMMARY_ADDR(base) ((base) + (0x0010))
#define SOC_NPU_DB_DB_INT_MASK0_ADDR(base) ((base) + (0x0020))
#define SOC_NPU_DB_DB_INT_MASK1_ADDR(base) ((base) + (0x0024))
#define SOC_NPU_DB_DB_INT_MASK2_ADDR(base) ((base) + (0x0028))
#define SOC_NPU_DB_DB_INT_MASK3_ADDR(base) ((base) + (0x002c))
#define SOC_NPU_DB_DB_INT_STATUS0_ADDR(base) ((base) + (0x00a0))
#define SOC_NPU_DB_DB_INT_STATUS1_ADDR(base) ((base) + (0x00a4))
#define SOC_NPU_DB_DB_INT_STATUS2_ADDR(base) ((base) + (0x00a8))
#define SOC_NPU_DB_DB_INT_STATUS3_ADDR(base) ((base) + (0x00ac))
#define SOC_NPU_DB_DB_SEC_REG_ADDR(base) ((base) + (0x0200))
#define SOC_NPU_DB_DB_SEC_MID0_REG_ADDR(base) ((base) + (0x0210))
#define SOC_NPU_DB_DB_SEC_MID1_REG_ADDR(base) ((base) + (0x0214))
#define SOC_NPU_DB_DB_SEC_MID2_REG_ADDR(base) ((base) + (0x0218))
#define SOC_NPU_DB_DB_SEC_MID3_REG_ADDR(base) ((base) + (0x021c))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int ecc_on_bresp : 1;
        unsigned int reserved_1 : 30;
    } reg;
} SOC_NPU_DB_RAM_CONFIG_UNION;
#endif
#define SOC_NPU_DB_RAM_CONFIG_ecc_on_bresp_START (1)
#define SOC_NPU_DB_RAM_CONFIG_ecc_on_bresp_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ecc_1bit_err_mask : 1;
        unsigned int ecc_2bit_err_mask : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_DB_ECC_INT_MASK_UNION;
#endif
#define SOC_NPU_DB_ECC_INT_MASK_ecc_1bit_err_mask_START (0)
#define SOC_NPU_DB_ECC_INT_MASK_ecc_1bit_err_mask_END (0)
#define SOC_NPU_DB_ECC_INT_MASK_ecc_2bit_err_mask_START (1)
#define SOC_NPU_DB_ECC_INT_MASK_ecc_2bit_err_mask_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ecc_1bit_err_status : 1;
        unsigned int ecc_2bit_err_status : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_DB_ECC_INT_STATUS_UNION;
#endif
#define SOC_NPU_DB_ECC_INT_STATUS_ecc_1bit_err_status_START (0)
#define SOC_NPU_DB_ECC_INT_STATUS_ecc_1bit_err_status_END (0)
#define SOC_NPU_DB_ECC_INT_STATUS_ecc_2bit_err_status_START (1)
#define SOC_NPU_DB_ECC_INT_STATUS_ecc_2bit_err_status_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int db_int_summary : 32;
    } reg;
} SOC_NPU_DB_DB_INT_SUMMARY_UNION;
#endif
#define SOC_NPU_DB_DB_INT_SUMMARY_db_int_summary_START (0)
#define SOC_NPU_DB_DB_INT_SUMMARY_db_int_summary_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int db_int_mask0 : 32;
    } reg;
} SOC_NPU_DB_DB_INT_MASK0_UNION;
#endif
#define SOC_NPU_DB_DB_INT_MASK0_db_int_mask0_START (0)
#define SOC_NPU_DB_DB_INT_MASK0_db_int_mask0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int db_int_mask1 : 32;
    } reg;
} SOC_NPU_DB_DB_INT_MASK1_UNION;
#endif
#define SOC_NPU_DB_DB_INT_MASK1_db_int_mask1_START (0)
#define SOC_NPU_DB_DB_INT_MASK1_db_int_mask1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int db_int_mask2 : 32;
    } reg;
} SOC_NPU_DB_DB_INT_MASK2_UNION;
#endif
#define SOC_NPU_DB_DB_INT_MASK2_db_int_mask2_START (0)
#define SOC_NPU_DB_DB_INT_MASK2_db_int_mask2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int db_int_mask3 : 32;
    } reg;
} SOC_NPU_DB_DB_INT_MASK3_UNION;
#endif
#define SOC_NPU_DB_DB_INT_MASK3_db_int_mask3_START (0)
#define SOC_NPU_DB_DB_INT_MASK3_db_int_mask3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int db_int_status0 : 32;
    } reg;
} SOC_NPU_DB_DB_INT_STATUS0_UNION;
#endif
#define SOC_NPU_DB_DB_INT_STATUS0_db_int_status0_START (0)
#define SOC_NPU_DB_DB_INT_STATUS0_db_int_status0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int db_int_status1 : 32;
    } reg;
} SOC_NPU_DB_DB_INT_STATUS1_UNION;
#endif
#define SOC_NPU_DB_DB_INT_STATUS1_db_int_status1_START (0)
#define SOC_NPU_DB_DB_INT_STATUS1_db_int_status1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int db_int_status2 : 32;
    } reg;
} SOC_NPU_DB_DB_INT_STATUS2_UNION;
#endif
#define SOC_NPU_DB_DB_INT_STATUS2_db_int_status2_START (0)
#define SOC_NPU_DB_DB_INT_STATUS2_db_int_status2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int db_int_status3 : 32;
    } reg;
} SOC_NPU_DB_DB_INT_STATUS3_UNION;
#endif
#define SOC_NPU_DB_DB_INT_STATUS3_db_int_status3_START (0)
#define SOC_NPU_DB_DB_INT_STATUS3_db_int_status3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int db_sec_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_DB_DB_SEC_REG_UNION;
#endif
#define SOC_NPU_DB_DB_SEC_REG_db_sec_en_START (0)
#define SOC_NPU_DB_DB_SEC_REG_db_sec_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int db_sec_mid0 : 16;
        unsigned int db_sec_mid0_mask : 16;
    } reg;
} SOC_NPU_DB_DB_SEC_MID0_REG_UNION;
#endif
#define SOC_NPU_DB_DB_SEC_MID0_REG_db_sec_mid0_START (0)
#define SOC_NPU_DB_DB_SEC_MID0_REG_db_sec_mid0_END (15)
#define SOC_NPU_DB_DB_SEC_MID0_REG_db_sec_mid0_mask_START (16)
#define SOC_NPU_DB_DB_SEC_MID0_REG_db_sec_mid0_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int db_sec_mid1 : 16;
        unsigned int db_sec_mid1_mask : 16;
    } reg;
} SOC_NPU_DB_DB_SEC_MID1_REG_UNION;
#endif
#define SOC_NPU_DB_DB_SEC_MID1_REG_db_sec_mid1_START (0)
#define SOC_NPU_DB_DB_SEC_MID1_REG_db_sec_mid1_END (15)
#define SOC_NPU_DB_DB_SEC_MID1_REG_db_sec_mid1_mask_START (16)
#define SOC_NPU_DB_DB_SEC_MID1_REG_db_sec_mid1_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int db_sec_mid2 : 16;
        unsigned int db_sec_mid2_mask : 16;
    } reg;
} SOC_NPU_DB_DB_SEC_MID2_REG_UNION;
#endif
#define SOC_NPU_DB_DB_SEC_MID2_REG_db_sec_mid2_START (0)
#define SOC_NPU_DB_DB_SEC_MID2_REG_db_sec_mid2_END (15)
#define SOC_NPU_DB_DB_SEC_MID2_REG_db_sec_mid2_mask_START (16)
#define SOC_NPU_DB_DB_SEC_MID2_REG_db_sec_mid2_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int db_sec_mid3 : 16;
        unsigned int db_sec_mid3_mask : 16;
    } reg;
} SOC_NPU_DB_DB_SEC_MID3_REG_UNION;
#endif
#define SOC_NPU_DB_DB_SEC_MID3_REG_db_sec_mid3_START (0)
#define SOC_NPU_DB_DB_SEC_MID3_REG_db_sec_mid3_END (15)
#define SOC_NPU_DB_DB_SEC_MID3_REG_db_sec_mid3_mask_START (16)
#define SOC_NPU_DB_DB_SEC_MID3_REG_db_sec_mid3_mask_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
