#ifndef __SOC_NPU_TINY_SCTRL_INTERFACE_H__
#define __SOC_NPU_TINY_SCTRL_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL0_ADDR(base) ((base) + (0x000UL))
#define SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL1_ADDR(base) ((base) + (0x004UL))
#else
#define SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL0_ADDR(base) ((base) + (0x000))
#define SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL1_ADDR(base) ((base) + (0x004))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int npu_ts_tiny_awcache : 4;
        unsigned int npu_ts_tiny_awdomain : 2;
        unsigned int npu_ts_tiny_awmpam : 4;
        unsigned int reserved_0 : 6;
        unsigned int npu_ts_tiny_arcache : 4;
        unsigned int npu_ts_tiny_ardomain : 2;
        unsigned int npu_ts_tiny_armpam : 4;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL0_UNION;
#endif
#define SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL0_npu_ts_tiny_awcache_START (0)
#define SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL0_npu_ts_tiny_awcache_END (3)
#define SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL0_npu_ts_tiny_awdomain_START (4)
#define SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL0_npu_ts_tiny_awdomain_END (5)
#define SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL0_npu_ts_tiny_awmpam_START (6)
#define SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL0_npu_ts_tiny_awmpam_END (9)
#define SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL0_npu_ts_tiny_arcache_START (16)
#define SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL0_npu_ts_tiny_arcache_END (19)
#define SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL0_npu_ts_tiny_ardomain_START (20)
#define SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL0_npu_ts_tiny_ardomain_END (21)
#define SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL0_npu_ts_tiny_armpam_START (22)
#define SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL0_npu_ts_tiny_armpam_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int npu_aic_tiny_awcache : 4;
        unsigned int npu_aic_tiny_awdomain : 2;
        unsigned int npu_aic_tiny_awmpam : 4;
        unsigned int reserved_0 : 6;
        unsigned int npu_aic_tiny_arcache : 4;
        unsigned int npu_aic_tiny_ardomain : 2;
        unsigned int npu_aic_tiny_armpam : 4;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL1_UNION;
#endif
#define SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL1_npu_aic_tiny_awcache_START (0)
#define SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL1_npu_aic_tiny_awcache_END (3)
#define SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL1_npu_aic_tiny_awdomain_START (4)
#define SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL1_npu_aic_tiny_awdomain_END (5)
#define SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL1_npu_aic_tiny_awmpam_START (6)
#define SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL1_npu_aic_tiny_awmpam_END (9)
#define SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL1_npu_aic_tiny_arcache_START (16)
#define SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL1_npu_aic_tiny_arcache_END (19)
#define SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL1_npu_aic_tiny_ardomain_START (20)
#define SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL1_npu_aic_tiny_ardomain_END (21)
#define SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL1_npu_aic_tiny_armpam_START (22)
#define SOC_NPU_TINY_SCTRL_NPU_LITE_CTRL1_npu_aic_tiny_armpam_END (25)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
