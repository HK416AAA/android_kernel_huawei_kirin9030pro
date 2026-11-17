#ifndef __PMIC_6563_v350_H__
#define __PMIC_6563_v350_H__ 
#ifdef __cplusplus
   #if __cplusplus
        extern "C" {
   #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define COMMON_PMIC_BUCK0_VSET_ADDR(base) ((base) + (0x01EUL))
#define COMMON_PMIC_BUCK0_ONOFF_ECO_ADDR(base) ((base) + (0x01FUL))
#else
#define COMMON_PMIC_BUCK0_VSET_ADDR(base) ((base) + (0x01E))
#define COMMON_PMIC_BUCK0_ONOFF_ECO_ADDR(base) ((base) + (0x01F))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char b0_vset : 8;
    } reg;
} COMMON_PMIC_BUCK0_VSET_UNION;
#endif
#define COMMON_PMIC_BUCK0_VSET_b0_vset_START (0)
#define COMMON_PMIC_BUCK0_VSET_b0_vset_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned char value;
    struct {
        unsigned char reg_b0_en : 1;
        unsigned char reserved : 7;
    } reg;
} COMMON_PMIC_BUCK0_ONOFF_ECO_UNION;
#endif
#define COMMON_PMIC_BUCK0_ONOFF_reg_b0_en_START (0)
#define COMMON_PMIC_BUCK0_ONOFF_reg_b0_en_END (0)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
