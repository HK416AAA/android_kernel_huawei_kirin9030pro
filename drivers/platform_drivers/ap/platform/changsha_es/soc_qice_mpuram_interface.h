#ifndef __SOC_QICE_MPURAM_INTERFACE_H__
#define __SOC_QICE_MPURAM_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QICE_MPURAM_MPU_ADDR_ATTR_ADDR(base,mpu_regs) (base) + 0x4 * (mpu_regs)
#else
#define SOC_QICE_MPURAM_MPU_ADDR_ATTR_ADDR(base,mpu_regs) (base) + 0x4 * (mpu_regs)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mpu_addr_attr : 32;
    } reg;
} SOC_QICE_MPURAM_MPU_ADDR_ATTR_UNION;
#endif
#define SOC_QICE_MPURAM_MPU_ADDR_ATTR_mpu_addr_attr_START (0)
#define SOC_QICE_MPURAM_MPU_ADDR_ATTR_mpu_addr_attr_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
