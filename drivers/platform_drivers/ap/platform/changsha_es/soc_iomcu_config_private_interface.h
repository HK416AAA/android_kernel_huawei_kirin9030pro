#ifndef __SOC_IOMCU_CONFIG_PRIVATE_INTERFACE_H__
#define __SOC_IOMCU_CONFIG_PRIVATE_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_IOMCU_CONFIG_PRIVATE_DDR_ACCESS_WINDOW0_ADDR(base) ((base) + (0x000UL))
#define SOC_IOMCU_CONFIG_PRIVATE_DDR_ACCESS_WINDOW1_ADDR(base) ((base) + (0x004UL))
#define SOC_IOMCU_CONFIG_PRIVATE_IOMCU_CONFIG_RESERVED_0_ADDR(base) ((base) + (0x008UL))
#else
#define SOC_IOMCU_CONFIG_PRIVATE_DDR_ACCESS_WINDOW0_ADDR(base) ((base) + (0x000))
#define SOC_IOMCU_CONFIG_PRIVATE_DDR_ACCESS_WINDOW1_ADDR(base) ((base) + (0x004))
#define SOC_IOMCU_CONFIG_PRIVATE_IOMCU_CONFIG_RESERVED_0_ADDR(base) ((base) + (0x008))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_access_window0 : 32;
    } reg;
} SOC_IOMCU_CONFIG_PRIVATE_DDR_ACCESS_WINDOW0_UNION;
#endif
#define SOC_IOMCU_CONFIG_PRIVATE_DDR_ACCESS_WINDOW0_ddr_access_window0_START (0)
#define SOC_IOMCU_CONFIG_PRIVATE_DDR_ACCESS_WINDOW0_ddr_access_window0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_access_window1 : 32;
    } reg;
} SOC_IOMCU_CONFIG_PRIVATE_DDR_ACCESS_WINDOW1_UNION;
#endif
#define SOC_IOMCU_CONFIG_PRIVATE_DDR_ACCESS_WINDOW1_ddr_access_window1_START (0)
#define SOC_IOMCU_CONFIG_PRIVATE_DDR_ACCESS_WINDOW1_ddr_access_window1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_config_reserve0 : 32;
    } reg;
} SOC_IOMCU_CONFIG_PRIVATE_IOMCU_CONFIG_RESERVED_0_UNION;
#endif
#define SOC_IOMCU_CONFIG_PRIVATE_IOMCU_CONFIG_RESERVED_0_iomcu_config_reserve0_START (0)
#define SOC_IOMCU_CONFIG_PRIVATE_IOMCU_CONFIG_RESERVED_0_iomcu_config_reserve0_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
