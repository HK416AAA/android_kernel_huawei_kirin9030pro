#ifndef __SOC_QICE_MPUCFG_INTERFACE_H__
#define __SOC_QICE_MPUCFG_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QICE_MPUCFG_MPUCFG_CTRL_ADDR(base) ((base) + 0x0410UL)
#define SOC_QICE_MPUCFG_MPUCFG_TRUST_WR_NTRUST_ADDR(base,mpu_mid_idx) (base) + 0x0420 + 0x4 * (mpu_mid_idx)
#define SOC_QICE_MPUCFG_MPUCFG_TRUST_WR_PROT_ADDR(base,mpu_mid_idx) (base) + 0x0440 + 0x4 * (mpu_mid_idx)
#define SOC_QICE_MPUCFG_MPUCFG_PROT_WR_NTRUST_ADDR(base,mpu_mid_idx) (base) + 0x0480 + 0x4 * (mpu_mid_idx)
#define SOC_QICE_MPUCFG_MPUCFG_RANDOM_L_ADDR(base) ((base) + 0x04C0UL)
#define SOC_QICE_MPUCFG_MPUCFG_RANDOM_H_ADDR(base) ((base) + 0x04C4UL)
#define SOC_QICE_MPUCFG_MPUCFG_RTL_INF_ADDR(base) ((base) + 0x0F00UL)
#define SOC_QICE_MPUCFG_MPUCFG_RSV_RW_ADDR(base) ((base) + 0x0F08UL)
#else
#define SOC_QICE_MPUCFG_MPUCFG_CTRL_ADDR(base) ((base) + 0x0410)
#define SOC_QICE_MPUCFG_MPUCFG_TRUST_WR_NTRUST_ADDR(base,mpu_mid_idx) (base) + 0x0420 + 0x4 * (mpu_mid_idx)
#define SOC_QICE_MPUCFG_MPUCFG_TRUST_WR_PROT_ADDR(base,mpu_mid_idx) (base) + 0x0440 + 0x4 * (mpu_mid_idx)
#define SOC_QICE_MPUCFG_MPUCFG_PROT_WR_NTRUST_ADDR(base,mpu_mid_idx) (base) + 0x0480 + 0x4 * (mpu_mid_idx)
#define SOC_QICE_MPUCFG_MPUCFG_RANDOM_L_ADDR(base) ((base) + 0x04C0)
#define SOC_QICE_MPUCFG_MPUCFG_RANDOM_H_ADDR(base) ((base) + 0x04C4)
#define SOC_QICE_MPUCFG_MPUCFG_RTL_INF_ADDR(base) ((base) + 0x0F00)
#define SOC_QICE_MPUCFG_MPUCFG_RSV_RW_ADDR(base) ((base) + 0x0F08)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mpu_en : 1;
        unsigned int mpu_fix_allow : 1;
        unsigned int reserved_0 : 2;
        unsigned int mpu_addr_zone : 2;
        unsigned int reserved_1 : 2;
        unsigned int mpu_cfg_rd_sel : 4;
        unsigned int mpu_cfg_wbe : 1;
        unsigned int reserved_2 : 3;
        unsigned int mpu_cmd_type : 6;
        unsigned int reserved_3 : 10;
    } reg;
} SOC_QICE_MPUCFG_MPUCFG_CTRL_UNION;
#endif
#define SOC_QICE_MPUCFG_MPUCFG_CTRL_mpu_en_START (0)
#define SOC_QICE_MPUCFG_MPUCFG_CTRL_mpu_en_END (0)
#define SOC_QICE_MPUCFG_MPUCFG_CTRL_mpu_fix_allow_START (1)
#define SOC_QICE_MPUCFG_MPUCFG_CTRL_mpu_fix_allow_END (1)
#define SOC_QICE_MPUCFG_MPUCFG_CTRL_mpu_addr_zone_START (4)
#define SOC_QICE_MPUCFG_MPUCFG_CTRL_mpu_addr_zone_END (5)
#define SOC_QICE_MPUCFG_MPUCFG_CTRL_mpu_cfg_rd_sel_START (8)
#define SOC_QICE_MPUCFG_MPUCFG_CTRL_mpu_cfg_rd_sel_END (11)
#define SOC_QICE_MPUCFG_MPUCFG_CTRL_mpu_cfg_wbe_START (12)
#define SOC_QICE_MPUCFG_MPUCFG_CTRL_mpu_cfg_wbe_END (12)
#define SOC_QICE_MPUCFG_MPUCFG_CTRL_mpu_cmd_type_START (16)
#define SOC_QICE_MPUCFG_MPUCFG_CTRL_mpu_cmd_type_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mpu_mid_trust_wr_ntrust : 32;
    } reg;
} SOC_QICE_MPUCFG_MPUCFG_TRUST_WR_NTRUST_UNION;
#endif
#define SOC_QICE_MPUCFG_MPUCFG_TRUST_WR_NTRUST_mpu_mid_trust_wr_ntrust_START (0)
#define SOC_QICE_MPUCFG_MPUCFG_TRUST_WR_NTRUST_mpu_mid_trust_wr_ntrust_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mpu_mid_trust_wr_prot : 32;
    } reg;
} SOC_QICE_MPUCFG_MPUCFG_TRUST_WR_PROT_UNION;
#endif
#define SOC_QICE_MPUCFG_MPUCFG_TRUST_WR_PROT_mpu_mid_trust_wr_prot_START (0)
#define SOC_QICE_MPUCFG_MPUCFG_TRUST_WR_PROT_mpu_mid_trust_wr_prot_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mpu_mid_prot_wr_ntrust : 32;
    } reg;
} SOC_QICE_MPUCFG_MPUCFG_PROT_WR_NTRUST_UNION;
#endif
#define SOC_QICE_MPUCFG_MPUCFG_PROT_WR_NTRUST_mpu_mid_prot_wr_ntrust_START (0)
#define SOC_QICE_MPUCFG_MPUCFG_PROT_WR_NTRUST_mpu_mid_prot_wr_ntrust_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mpu_random_l : 32;
    } reg;
} SOC_QICE_MPUCFG_MPUCFG_RANDOM_L_UNION;
#endif
#define SOC_QICE_MPUCFG_MPUCFG_RANDOM_L_mpu_random_l_START (0)
#define SOC_QICE_MPUCFG_MPUCFG_RANDOM_L_mpu_random_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mpu_random_h : 32;
    } reg;
} SOC_QICE_MPUCFG_MPUCFG_RANDOM_H_UNION;
#endif
#define SOC_QICE_MPUCFG_MPUCFG_RANDOM_H_mpu_random_h_START (0)
#define SOC_QICE_MPUCFG_MPUCFG_RANDOM_H_mpu_random_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info : 32;
    } reg;
} SOC_QICE_MPUCFG_MPUCFG_RTL_INF_UNION;
#endif
#define SOC_QICE_MPUCFG_MPUCFG_RTL_INF_rtl_info_START (0)
#define SOC_QICE_MPUCFG_MPUCFG_RTL_INF_rtl_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rsv_rw : 32;
    } reg;
} SOC_QICE_MPUCFG_MPUCFG_RSV_RW_UNION;
#endif
#define SOC_QICE_MPUCFG_MPUCFG_RSV_RW_rsv_rw_START (0)
#define SOC_QICE_MPUCFG_MPUCFG_RSV_RW_rsv_rw_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
