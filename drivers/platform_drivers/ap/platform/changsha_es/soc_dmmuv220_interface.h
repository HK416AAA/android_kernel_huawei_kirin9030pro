#ifndef __SOC_DMMUV220_INTERFACE_H__
#define __SOC_DMMUV220_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DMMUV220_FAMA_REMAP_AW_SRC_ADDR(base,R) ((base) + (0x400+16*(R)))
#define SOC_DMMUV220_FAMA_REMAP_AW_LEN_ADDR(base,R) ((base) + (0x404+16*(R)))
#define SOC_DMMUV220_FAMA_REMAP_AW_DST_ADDR(base,R) ((base) + (0x408+16*(R)))
#define SOC_DMMUV220_FAMA_REMAP_AW_USER_ADDR(base,R) ((base) + (0x40C+16*(R)))
#define SOC_DMMUV220_FAMA_REMAP_AR_SRC_ADDR(base,R) ((base) + (0x700+16*(R)))
#define SOC_DMMUV220_FAMA_REMAP_AR_LEN_ADDR(base,R) ((base) + (0x704+16*(R)))
#define SOC_DMMUV220_FAMA_REMAP_AR_DST_ADDR(base,R) ((base) + (0x708+16*(R)))
#define SOC_DMMUV220_FAMA_REMAP_AR_USER_ADDR(base,R) ((base) + (0x70C+16*(R)))
#define SOC_DMMUV220_FAMA_AW_USER_DEFAULT_ADDR(base) ((base) + (0x980UL))
#define SOC_DMMUV220_FAMA_AR_USER_DEFAULT_ADDR(base) ((base) + (0x984UL))
#define SOC_DMMUV220_FAMA_BP_OTSD_CNT_ADDR(base) ((base) + (0x98CUL))
#define SOC_DMMUV220_FAMA_REMAP_BYPASS_ADDR(base) ((base) + (0x990UL))
#define SOC_DMMUV220_FAMA_REMAP_INT_CFG0_ADDR(base) ((base) + (0x994UL))
#define SOC_DMMUV220_FAMA_REMAP_INT_CFG1_ADDR(base) ((base) + (0x998UL))
#define SOC_DMMUV220_FAMA_REMAP_WCMD_REG0_ADDR(base) ((base) + (0x99CUL))
#define SOC_DMMUV220_FAMA_REMAP_WCMD_REG1_ADDR(base) ((base) + (0x9A0UL))
#define SOC_DMMUV220_FAMA_REMAP_RCMD_REG0_ADDR(base) ((base) + (0x9A4UL))
#define SOC_DMMUV220_FAMA_REMAP_RCMD_REG1_ADDR(base) ((base) + (0x9A8UL))
#define SOC_DMMUV220_FAMA_MISS_ADDR_AW_ADDR(base) ((base) + (0x9B4UL))
#define SOC_DMMUV220_FAMA_MISS_ADDR_AR_ADDR(base) ((base) + (0x9B8UL))
#else
#define SOC_DMMUV220_FAMA_REMAP_AW_SRC_ADDR(base,R) ((base) + (0x400+16*(R)))
#define SOC_DMMUV220_FAMA_REMAP_AW_LEN_ADDR(base,R) ((base) + (0x404+16*(R)))
#define SOC_DMMUV220_FAMA_REMAP_AW_DST_ADDR(base,R) ((base) + (0x408+16*(R)))
#define SOC_DMMUV220_FAMA_REMAP_AW_USER_ADDR(base,R) ((base) + (0x40C+16*(R)))
#define SOC_DMMUV220_FAMA_REMAP_AR_SRC_ADDR(base,R) ((base) + (0x700+16*(R)))
#define SOC_DMMUV220_FAMA_REMAP_AR_LEN_ADDR(base,R) ((base) + (0x704+16*(R)))
#define SOC_DMMUV220_FAMA_REMAP_AR_DST_ADDR(base,R) ((base) + (0x708+16*(R)))
#define SOC_DMMUV220_FAMA_REMAP_AR_USER_ADDR(base,R) ((base) + (0x70C+16*(R)))
#define SOC_DMMUV220_FAMA_AW_USER_DEFAULT_ADDR(base) ((base) + (0x980))
#define SOC_DMMUV220_FAMA_AR_USER_DEFAULT_ADDR(base) ((base) + (0x984))
#define SOC_DMMUV220_FAMA_BP_OTSD_CNT_ADDR(base) ((base) + (0x98C))
#define SOC_DMMUV220_FAMA_REMAP_BYPASS_ADDR(base) ((base) + (0x990))
#define SOC_DMMUV220_FAMA_REMAP_INT_CFG0_ADDR(base) ((base) + (0x994))
#define SOC_DMMUV220_FAMA_REMAP_INT_CFG1_ADDR(base) ((base) + (0x998))
#define SOC_DMMUV220_FAMA_REMAP_WCMD_REG0_ADDR(base) ((base) + (0x99C))
#define SOC_DMMUV220_FAMA_REMAP_WCMD_REG1_ADDR(base) ((base) + (0x9A0))
#define SOC_DMMUV220_FAMA_REMAP_RCMD_REG0_ADDR(base) ((base) + (0x9A4))
#define SOC_DMMUV220_FAMA_REMAP_RCMD_REG1_ADDR(base) ((base) + (0x9A8))
#define SOC_DMMUV220_FAMA_MISS_ADDR_AW_ADDR(base) ((base) + (0x9B4))
#define SOC_DMMUV220_FAMA_MISS_ADDR_AR_ADDR(base) ((base) + (0x9B8))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_aw_addr_src : 28;
        unsigned int icfg_aw_en : 1;
        unsigned int reserved : 3;
    } reg;
} SOC_DMMUV220_FAMA_REMAP_AW_SRC_UNION;
#endif
#define SOC_DMMUV220_FAMA_REMAP_AW_SRC_icfg_aw_addr_src_START (0)
#define SOC_DMMUV220_FAMA_REMAP_AW_SRC_icfg_aw_addr_src_END (27)
#define SOC_DMMUV220_FAMA_REMAP_AW_SRC_icfg_aw_en_START (28)
#define SOC_DMMUV220_FAMA_REMAP_AW_SRC_icfg_aw_en_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_aw_addr_len : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_DMMUV220_FAMA_REMAP_AW_LEN_UNION;
#endif
#define SOC_DMMUV220_FAMA_REMAP_AW_LEN_icfg_aw_addr_len_START (0)
#define SOC_DMMUV220_FAMA_REMAP_AW_LEN_icfg_aw_addr_len_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_aw_addr_dst : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_DMMUV220_FAMA_REMAP_AW_DST_UNION;
#endif
#define SOC_DMMUV220_FAMA_REMAP_AW_DST_icfg_aw_addr_dst_START (0)
#define SOC_DMMUV220_FAMA_REMAP_AW_DST_icfg_aw_addr_dst_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_aw_user : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DMMUV220_FAMA_REMAP_AW_USER_UNION;
#endif
#define SOC_DMMUV220_FAMA_REMAP_AW_USER_icfg_aw_user_START (0)
#define SOC_DMMUV220_FAMA_REMAP_AW_USER_icfg_aw_user_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_ar_addr_src : 28;
        unsigned int icfg_ar_en : 1;
        unsigned int reserved : 3;
    } reg;
} SOC_DMMUV220_FAMA_REMAP_AR_SRC_UNION;
#endif
#define SOC_DMMUV220_FAMA_REMAP_AR_SRC_icfg_ar_addr_src_START (0)
#define SOC_DMMUV220_FAMA_REMAP_AR_SRC_icfg_ar_addr_src_END (27)
#define SOC_DMMUV220_FAMA_REMAP_AR_SRC_icfg_ar_en_START (28)
#define SOC_DMMUV220_FAMA_REMAP_AR_SRC_icfg_ar_en_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_ar_addr_len : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_DMMUV220_FAMA_REMAP_AR_LEN_UNION;
#endif
#define SOC_DMMUV220_FAMA_REMAP_AR_LEN_icfg_ar_addr_len_START (0)
#define SOC_DMMUV220_FAMA_REMAP_AR_LEN_icfg_ar_addr_len_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_ar_addr_dst : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_DMMUV220_FAMA_REMAP_AR_DST_UNION;
#endif
#define SOC_DMMUV220_FAMA_REMAP_AR_DST_icfg_ar_addr_dst_START (0)
#define SOC_DMMUV220_FAMA_REMAP_AR_DST_icfg_ar_addr_dst_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_ar_user : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DMMUV220_FAMA_REMAP_AR_USER_UNION;
#endif
#define SOC_DMMUV220_FAMA_REMAP_AR_USER_icfg_ar_user_START (0)
#define SOC_DMMUV220_FAMA_REMAP_AR_USER_icfg_ar_user_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_aw_user_default : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DMMUV220_FAMA_AW_USER_DEFAULT_UNION;
#endif
#define SOC_DMMUV220_FAMA_AW_USER_DEFAULT_icfg_aw_user_default_START (0)
#define SOC_DMMUV220_FAMA_AW_USER_DEFAULT_icfg_aw_user_default_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_ar_user_default : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DMMUV220_FAMA_AR_USER_DEFAULT_UNION;
#endif
#define SOC_DMMUV220_FAMA_AR_USER_DEFAULT_icfg_ar_user_default_START (0)
#define SOC_DMMUV220_FAMA_AR_USER_DEFAULT_icfg_ar_user_default_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wr_otsd_cnt : 8;
        unsigned int rd_otsd_cnt : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_DMMUV220_FAMA_BP_OTSD_CNT_UNION;
#endif
#define SOC_DMMUV220_FAMA_BP_OTSD_CNT_wr_otsd_cnt_START (0)
#define SOC_DMMUV220_FAMA_BP_OTSD_CNT_wr_otsd_cnt_END (7)
#define SOC_DMMUV220_FAMA_BP_OTSD_CNT_rd_otsd_cnt_START (8)
#define SOC_DMMUV220_FAMA_BP_OTSD_CNT_rd_otsd_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bp_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int ckg_en : 1;
        unsigned int icfg_dmmu_bypass : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 26;
    } reg;
} SOC_DMMUV220_FAMA_REMAP_BYPASS_UNION;
#endif
#define SOC_DMMUV220_FAMA_REMAP_BYPASS_bp_en_START (0)
#define SOC_DMMUV220_FAMA_REMAP_BYPASS_bp_en_END (0)
#define SOC_DMMUV220_FAMA_REMAP_BYPASS_ckg_en_START (3)
#define SOC_DMMUV220_FAMA_REMAP_BYPASS_ckg_en_END (3)
#define SOC_DMMUV220_FAMA_REMAP_BYPASS_icfg_dmmu_bypass_START (4)
#define SOC_DMMUV220_FAMA_REMAP_BYPASS_icfg_dmmu_bypass_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_clear : 1;
        unsigned int int_mask : 1;
        unsigned int int_mask_bp : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_DMMUV220_FAMA_REMAP_INT_CFG0_UNION;
#endif
#define SOC_DMMUV220_FAMA_REMAP_INT_CFG0_int_clear_START (0)
#define SOC_DMMUV220_FAMA_REMAP_INT_CFG0_int_clear_END (0)
#define SOC_DMMUV220_FAMA_REMAP_INT_CFG0_int_mask_START (1)
#define SOC_DMMUV220_FAMA_REMAP_INT_CFG0_int_mask_END (1)
#define SOC_DMMUV220_FAMA_REMAP_INT_CFG0_int_mask_bp_START (2)
#define SOC_DMMUV220_FAMA_REMAP_INT_CFG0_int_mask_bp_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_int_miss_r : 1;
        unsigned int st_int_miss_w : 1;
        unsigned int st_int_miss_r_masked : 1;
        unsigned int st_int_miss_w_masked : 1;
        unsigned int int_dmmu : 1;
        unsigned int st_int_bp : 1;
        unsigned int st_int_bp_masked : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_DMMUV220_FAMA_REMAP_INT_CFG1_UNION;
#endif
#define SOC_DMMUV220_FAMA_REMAP_INT_CFG1_st_int_miss_r_START (0)
#define SOC_DMMUV220_FAMA_REMAP_INT_CFG1_st_int_miss_r_END (0)
#define SOC_DMMUV220_FAMA_REMAP_INT_CFG1_st_int_miss_w_START (1)
#define SOC_DMMUV220_FAMA_REMAP_INT_CFG1_st_int_miss_w_END (1)
#define SOC_DMMUV220_FAMA_REMAP_INT_CFG1_st_int_miss_r_masked_START (2)
#define SOC_DMMUV220_FAMA_REMAP_INT_CFG1_st_int_miss_r_masked_END (2)
#define SOC_DMMUV220_FAMA_REMAP_INT_CFG1_st_int_miss_w_masked_START (3)
#define SOC_DMMUV220_FAMA_REMAP_INT_CFG1_st_int_miss_w_masked_END (3)
#define SOC_DMMUV220_FAMA_REMAP_INT_CFG1_int_dmmu_START (4)
#define SOC_DMMUV220_FAMA_REMAP_INT_CFG1_int_dmmu_END (4)
#define SOC_DMMUV220_FAMA_REMAP_INT_CFG1_st_int_bp_START (5)
#define SOC_DMMUV220_FAMA_REMAP_INT_CFG1_st_int_bp_END (5)
#define SOC_DMMUV220_FAMA_REMAP_INT_CFG1_st_int_bp_masked_START (6)
#define SOC_DMMUV220_FAMA_REMAP_INT_CFG1_st_int_bp_masked_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wcmd_reg0 : 32;
    } reg;
} SOC_DMMUV220_FAMA_REMAP_WCMD_REG0_UNION;
#endif
#define SOC_DMMUV220_FAMA_REMAP_WCMD_REG0_wcmd_reg0_START (0)
#define SOC_DMMUV220_FAMA_REMAP_WCMD_REG0_wcmd_reg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wcmd_reg1 : 32;
    } reg;
} SOC_DMMUV220_FAMA_REMAP_WCMD_REG1_UNION;
#endif
#define SOC_DMMUV220_FAMA_REMAP_WCMD_REG1_wcmd_reg1_START (0)
#define SOC_DMMUV220_FAMA_REMAP_WCMD_REG1_wcmd_reg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rcmd_reg0 : 32;
    } reg;
} SOC_DMMUV220_FAMA_REMAP_RCMD_REG0_UNION;
#endif
#define SOC_DMMUV220_FAMA_REMAP_RCMD_REG0_rcmd_reg0_START (0)
#define SOC_DMMUV220_FAMA_REMAP_RCMD_REG0_rcmd_reg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rcmd_reg1 : 32;
    } reg;
} SOC_DMMUV220_FAMA_REMAP_RCMD_REG1_UNION;
#endif
#define SOC_DMMUV220_FAMA_REMAP_RCMD_REG1_rcmd_reg1_START (0)
#define SOC_DMMUV220_FAMA_REMAP_RCMD_REG1_rcmd_reg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_miss_addr_aw : 28;
        unsigned int icfg_miss_addr_aw_en : 1;
        unsigned int reserved : 3;
    } reg;
} SOC_DMMUV220_FAMA_MISS_ADDR_AW_UNION;
#endif
#define SOC_DMMUV220_FAMA_MISS_ADDR_AW_icfg_miss_addr_aw_START (0)
#define SOC_DMMUV220_FAMA_MISS_ADDR_AW_icfg_miss_addr_aw_END (27)
#define SOC_DMMUV220_FAMA_MISS_ADDR_AW_icfg_miss_addr_aw_en_START (28)
#define SOC_DMMUV220_FAMA_MISS_ADDR_AW_icfg_miss_addr_aw_en_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_miss_addr_ar : 28;
        unsigned int icfg_miss_addr_ar_en : 1;
        unsigned int reserved : 3;
    } reg;
} SOC_DMMUV220_FAMA_MISS_ADDR_AR_UNION;
#endif
#define SOC_DMMUV220_FAMA_MISS_ADDR_AR_icfg_miss_addr_ar_START (0)
#define SOC_DMMUV220_FAMA_MISS_ADDR_AR_icfg_miss_addr_ar_END (27)
#define SOC_DMMUV220_FAMA_MISS_ADDR_AR_icfg_miss_addr_ar_en_START (28)
#define SOC_DMMUV220_FAMA_MISS_ADDR_AR_icfg_miss_addr_ar_en_END (28)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
