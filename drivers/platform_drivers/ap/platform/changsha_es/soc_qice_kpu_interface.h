#ifndef __SOC_QICE_KPU_INTERFACE_H__
#define __SOC_QICE_KPU_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QICE_KPU_KPU_BYP_ADDR(base) ((base) + 0x400UL)
#define SOC_QICE_KPU_KPU_CHK_MID_BYP_ADDR(base) ((base) + 0x404UL)
#define SOC_QICE_KPU_KPU_CHK_TYPE_BYP_ADDR(base) ((base) + 0x408UL)
#define SOC_QICE_KPU_KPU_RGN_MAP0_ADDR(base,rgns) (base) + 0x410 + 0x10 * (rgns)
#define SOC_QICE_KPU_KPU_RGN_MAP1_ADDR(base,rgns) (base) + 0x414 + 0x10 * (rgns)
#else
#define SOC_QICE_KPU_KPU_BYP_ADDR(base) ((base) + 0x400)
#define SOC_QICE_KPU_KPU_CHK_MID_BYP_ADDR(base) ((base) + 0x404)
#define SOC_QICE_KPU_KPU_CHK_TYPE_BYP_ADDR(base) ((base) + 0x408)
#define SOC_QICE_KPU_KPU_RGN_MAP0_ADDR(base,rgns) (base) + 0x410 + 0x10 * (rgns)
#define SOC_QICE_KPU_KPU_RGN_MAP1_ADDR(base,rgns) (base) + 0x414 + 0x10 * (rgns)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kpu_byp : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_KPU_KPU_BYP_UNION;
#endif
#define SOC_QICE_KPU_KPU_BYP_kpu_byp_START (0)
#define SOC_QICE_KPU_KPU_BYP_kpu_byp_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kpu_chk_mid_byp : 32;
    } reg;
} SOC_QICE_KPU_KPU_CHK_MID_BYP_UNION;
#endif
#define SOC_QICE_KPU_KPU_CHK_MID_BYP_kpu_chk_mid_byp_START (0)
#define SOC_QICE_KPU_KPU_CHK_MID_BYP_kpu_chk_mid_byp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kpu_chk_rcmd_byp : 1;
        unsigned int kpu_chk_wcmd_byp : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_KPU_KPU_CHK_TYPE_BYP_UNION;
#endif
#define SOC_QICE_KPU_KPU_CHK_TYPE_BYP_kpu_chk_rcmd_byp_START (0)
#define SOC_QICE_KPU_KPU_CHK_TYPE_BYP_kpu_chk_rcmd_byp_END (0)
#define SOC_QICE_KPU_KPU_CHK_TYPE_BYP_kpu_chk_wcmd_byp_START (1)
#define SOC_QICE_KPU_KPU_CHK_TYPE_BYP_kpu_chk_wcmd_byp_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rgn_base_addr : 24;
        unsigned int reserved : 7;
        unsigned int rgn_en : 1;
    } reg;
} SOC_QICE_KPU_KPU_RGN_MAP0_UNION;
#endif
#define SOC_QICE_KPU_KPU_RGN_MAP0_rgn_base_addr_START (0)
#define SOC_QICE_KPU_KPU_RGN_MAP0_rgn_base_addr_END (23)
#define SOC_QICE_KPU_KPU_RGN_MAP0_rgn_en_START (31)
#define SOC_QICE_KPU_KPU_RGN_MAP0_rgn_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rgn_top_addr : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_QICE_KPU_KPU_RGN_MAP1_UNION;
#endif
#define SOC_QICE_KPU_KPU_RGN_MAP1_rgn_top_addr_START (0)
#define SOC_QICE_KPU_KPU_RGN_MAP1_rgn_top_addr_END (23)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
