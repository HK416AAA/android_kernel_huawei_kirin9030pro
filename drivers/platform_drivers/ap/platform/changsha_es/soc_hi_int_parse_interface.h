#ifndef __SOC_HI_INT_PARSE_INTERFACE_H__
#define __SOC_HI_INT_PARSE_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HI_INT_PARSE_CFG_AW_ADDR_L_ADDR(base) (base)
#define SOC_HI_INT_PARSE_INTR_CLR_IOMCU0_ADDR(base) ((base) + 0x004UL)
#define SOC_HI_INT_PARSE_INTR_CLR_IOMCU1_ADDR(base) ((base) + 0x008UL)
#define SOC_HI_INT_PARSE_INTR_MASK_IOMCU0_ADDR(base) ((base) + 0x00CUL)
#define SOC_HI_INT_PARSE_INTR_MASK_IOMCU1_ADDR(base) ((base) + 0x010UL)
#define SOC_HI_INT_PARSE_INTR_RAW_IOMCU0_ADDR(base) ((base) + 0x014UL)
#define SOC_HI_INT_PARSE_INTR_RAW_IOMCU1_ADDR(base) ((base) + 0x018UL)
#define SOC_HI_INT_PARSE_INTR_STAT_IOMCU0_ADDR(base) ((base) + 0x01CUL)
#define SOC_HI_INT_PARSE_INTR_STAT_IOMCU1_ADDR(base) ((base) + 0x020UL)
#define SOC_HI_INT_PARSE_INTR_CLR_ASP_ADDR(base) ((base) + 0x1000UL)
#define SOC_HI_INT_PARSE_INTR_MASK_ASP_ADDR(base) ((base) + 0x1004UL)
#define SOC_HI_INT_PARSE_INTR_RAW_ASP_ADDR(base) ((base) + 0x1008UL)
#define SOC_HI_INT_PARSE_INTR_STAT_ASP_ADDR(base) ((base) + 0x100CUL)
#define SOC_HI_INT_PARSE_INTR_CLR_TEE_ADDR(base) ((base) + 0x2000UL)
#define SOC_HI_INT_PARSE_INTR_MASK_TEE_ADDR(base) ((base) + 0x2004UL)
#define SOC_HI_INT_PARSE_INTR_RAW_TEE_ADDR(base) ((base) + 0x2008UL)
#define SOC_HI_INT_PARSE_INTR_STAT_TEE_ADDR(base) ((base) + 0x200CUL)
#define SOC_HI_INT_PARSE_INTR_CLR_REE_ADDR(base) ((base) + 0x3000UL)
#define SOC_HI_INT_PARSE_INTR_MASK_REE_ADDR(base) ((base) + 0x3004UL)
#define SOC_HI_INT_PARSE_INTR_RAW_REE_ADDR(base) ((base) + 0x3008UL)
#define SOC_HI_INT_PARSE_INTR_STAT_REE_ADDR(base) ((base) + 0x300CUL)
#define SOC_HI_INT_PARSE_INTR_CLR_ISP_ADDR(base) ((base) + 0x4000UL)
#define SOC_HI_INT_PARSE_INTR_MASK_ISP_ADDR(base) ((base) + 0x4004UL)
#define SOC_HI_INT_PARSE_INTR_RAW_ISP_ADDR(base) ((base) + 0x4008UL)
#define SOC_HI_INT_PARSE_INTR_STAT_ISP_ADDR(base) ((base) + 0x400CUL)
#define SOC_HI_INT_PARSE_INTR_CLR_MODEM_ADDR(base) ((base) + 0x5000UL)
#define SOC_HI_INT_PARSE_INTR_MASK_MODEM_ADDR(base) ((base) + 0x5004UL)
#define SOC_HI_INT_PARSE_INTR_RAW_MODEM_ADDR(base) ((base) + 0x5008UL)
#define SOC_HI_INT_PARSE_INTR_STAT_MODEM_ADDR(base) ((base) + 0x500CUL)
#else
#define SOC_HI_INT_PARSE_CFG_AW_ADDR_L_ADDR(base) (base)
#define SOC_HI_INT_PARSE_INTR_CLR_IOMCU0_ADDR(base) ((base) + 0x004)
#define SOC_HI_INT_PARSE_INTR_CLR_IOMCU1_ADDR(base) ((base) + 0x008)
#define SOC_HI_INT_PARSE_INTR_MASK_IOMCU0_ADDR(base) ((base) + 0x00C)
#define SOC_HI_INT_PARSE_INTR_MASK_IOMCU1_ADDR(base) ((base) + 0x010)
#define SOC_HI_INT_PARSE_INTR_RAW_IOMCU0_ADDR(base) ((base) + 0x014)
#define SOC_HI_INT_PARSE_INTR_RAW_IOMCU1_ADDR(base) ((base) + 0x018)
#define SOC_HI_INT_PARSE_INTR_STAT_IOMCU0_ADDR(base) ((base) + 0x01C)
#define SOC_HI_INT_PARSE_INTR_STAT_IOMCU1_ADDR(base) ((base) + 0x020)
#define SOC_HI_INT_PARSE_INTR_CLR_ASP_ADDR(base) ((base) + 0x1000)
#define SOC_HI_INT_PARSE_INTR_MASK_ASP_ADDR(base) ((base) + 0x1004)
#define SOC_HI_INT_PARSE_INTR_RAW_ASP_ADDR(base) ((base) + 0x1008)
#define SOC_HI_INT_PARSE_INTR_STAT_ASP_ADDR(base) ((base) + 0x100C)
#define SOC_HI_INT_PARSE_INTR_CLR_TEE_ADDR(base) ((base) + 0x2000)
#define SOC_HI_INT_PARSE_INTR_MASK_TEE_ADDR(base) ((base) + 0x2004)
#define SOC_HI_INT_PARSE_INTR_RAW_TEE_ADDR(base) ((base) + 0x2008)
#define SOC_HI_INT_PARSE_INTR_STAT_TEE_ADDR(base) ((base) + 0x200C)
#define SOC_HI_INT_PARSE_INTR_CLR_REE_ADDR(base) ((base) + 0x3000)
#define SOC_HI_INT_PARSE_INTR_MASK_REE_ADDR(base) ((base) + 0x3004)
#define SOC_HI_INT_PARSE_INTR_RAW_REE_ADDR(base) ((base) + 0x3008)
#define SOC_HI_INT_PARSE_INTR_STAT_REE_ADDR(base) ((base) + 0x300C)
#define SOC_HI_INT_PARSE_INTR_CLR_ISP_ADDR(base) ((base) + 0x4000)
#define SOC_HI_INT_PARSE_INTR_MASK_ISP_ADDR(base) ((base) + 0x4004)
#define SOC_HI_INT_PARSE_INTR_RAW_ISP_ADDR(base) ((base) + 0x4008)
#define SOC_HI_INT_PARSE_INTR_STAT_ISP_ADDR(base) ((base) + 0x400C)
#define SOC_HI_INT_PARSE_INTR_CLR_MODEM_ADDR(base) ((base) + 0x5000)
#define SOC_HI_INT_PARSE_INTR_MASK_MODEM_ADDR(base) ((base) + 0x5004)
#define SOC_HI_INT_PARSE_INTR_RAW_MODEM_ADDR(base) ((base) + 0x5008)
#define SOC_HI_INT_PARSE_INTR_STAT_MODEM_ADDR(base) ((base) + 0x500C)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_aw_addr_l : 32;
    } reg;
} SOC_HI_INT_PARSE_CFG_AW_ADDR_L_UNION;
#endif
#define SOC_HI_INT_PARSE_CFG_AW_ADDR_L_cfg_aw_addr_l_START (0)
#define SOC_HI_INT_PARSE_CFG_AW_ADDR_L_cfg_aw_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_clr_iomcu0 : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_HI_INT_PARSE_INTR_CLR_IOMCU0_UNION;
#endif
#define SOC_HI_INT_PARSE_INTR_CLR_IOMCU0_intr_clr_iomcu0_START (0)
#define SOC_HI_INT_PARSE_INTR_CLR_IOMCU0_intr_clr_iomcu0_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_clr_iomcu1 : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_HI_INT_PARSE_INTR_CLR_IOMCU1_UNION;
#endif
#define SOC_HI_INT_PARSE_INTR_CLR_IOMCU1_intr_clr_iomcu1_START (0)
#define SOC_HI_INT_PARSE_INTR_CLR_IOMCU1_intr_clr_iomcu1_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_mask_iomcu0 : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_HI_INT_PARSE_INTR_MASK_IOMCU0_UNION;
#endif
#define SOC_HI_INT_PARSE_INTR_MASK_IOMCU0_intr_mask_iomcu0_START (0)
#define SOC_HI_INT_PARSE_INTR_MASK_IOMCU0_intr_mask_iomcu0_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_mask_iomcu1 : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_HI_INT_PARSE_INTR_MASK_IOMCU1_UNION;
#endif
#define SOC_HI_INT_PARSE_INTR_MASK_IOMCU1_intr_mask_iomcu1_START (0)
#define SOC_HI_INT_PARSE_INTR_MASK_IOMCU1_intr_mask_iomcu1_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_raw_iomcu0 : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_HI_INT_PARSE_INTR_RAW_IOMCU0_UNION;
#endif
#define SOC_HI_INT_PARSE_INTR_RAW_IOMCU0_intr_raw_iomcu0_START (0)
#define SOC_HI_INT_PARSE_INTR_RAW_IOMCU0_intr_raw_iomcu0_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_raw_iomcu1 : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_HI_INT_PARSE_INTR_RAW_IOMCU1_UNION;
#endif
#define SOC_HI_INT_PARSE_INTR_RAW_IOMCU1_intr_raw_iomcu1_START (0)
#define SOC_HI_INT_PARSE_INTR_RAW_IOMCU1_intr_raw_iomcu1_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_stat_iomcu0 : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_HI_INT_PARSE_INTR_STAT_IOMCU0_UNION;
#endif
#define SOC_HI_INT_PARSE_INTR_STAT_IOMCU0_intr_stat_iomcu0_START (0)
#define SOC_HI_INT_PARSE_INTR_STAT_IOMCU0_intr_stat_iomcu0_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_stat_iomcu1 : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_HI_INT_PARSE_INTR_STAT_IOMCU1_UNION;
#endif
#define SOC_HI_INT_PARSE_INTR_STAT_IOMCU1_intr_stat_iomcu1_START (0)
#define SOC_HI_INT_PARSE_INTR_STAT_IOMCU1_intr_stat_iomcu1_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_clr_asp : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_HI_INT_PARSE_INTR_CLR_ASP_UNION;
#endif
#define SOC_HI_INT_PARSE_INTR_CLR_ASP_intr_clr_asp_START (0)
#define SOC_HI_INT_PARSE_INTR_CLR_ASP_intr_clr_asp_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_mask_asp : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_HI_INT_PARSE_INTR_MASK_ASP_UNION;
#endif
#define SOC_HI_INT_PARSE_INTR_MASK_ASP_intr_mask_asp_START (0)
#define SOC_HI_INT_PARSE_INTR_MASK_ASP_intr_mask_asp_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_raw_asp : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_HI_INT_PARSE_INTR_RAW_ASP_UNION;
#endif
#define SOC_HI_INT_PARSE_INTR_RAW_ASP_intr_raw_asp_START (0)
#define SOC_HI_INT_PARSE_INTR_RAW_ASP_intr_raw_asp_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_stat_asp : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_HI_INT_PARSE_INTR_STAT_ASP_UNION;
#endif
#define SOC_HI_INT_PARSE_INTR_STAT_ASP_intr_stat_asp_START (0)
#define SOC_HI_INT_PARSE_INTR_STAT_ASP_intr_stat_asp_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_clr_tee : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_HI_INT_PARSE_INTR_CLR_TEE_UNION;
#endif
#define SOC_HI_INT_PARSE_INTR_CLR_TEE_intr_clr_tee_START (0)
#define SOC_HI_INT_PARSE_INTR_CLR_TEE_intr_clr_tee_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_mask_tee : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_HI_INT_PARSE_INTR_MASK_TEE_UNION;
#endif
#define SOC_HI_INT_PARSE_INTR_MASK_TEE_intr_mask_tee_START (0)
#define SOC_HI_INT_PARSE_INTR_MASK_TEE_intr_mask_tee_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_raw_tee : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_HI_INT_PARSE_INTR_RAW_TEE_UNION;
#endif
#define SOC_HI_INT_PARSE_INTR_RAW_TEE_intr_raw_tee_START (0)
#define SOC_HI_INT_PARSE_INTR_RAW_TEE_intr_raw_tee_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_stat_tee : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_HI_INT_PARSE_INTR_STAT_TEE_UNION;
#endif
#define SOC_HI_INT_PARSE_INTR_STAT_TEE_intr_stat_tee_START (0)
#define SOC_HI_INT_PARSE_INTR_STAT_TEE_intr_stat_tee_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_clr_ree : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_HI_INT_PARSE_INTR_CLR_REE_UNION;
#endif
#define SOC_HI_INT_PARSE_INTR_CLR_REE_intr_clr_ree_START (0)
#define SOC_HI_INT_PARSE_INTR_CLR_REE_intr_clr_ree_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_mask_ree : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_HI_INT_PARSE_INTR_MASK_REE_UNION;
#endif
#define SOC_HI_INT_PARSE_INTR_MASK_REE_intr_mask_ree_START (0)
#define SOC_HI_INT_PARSE_INTR_MASK_REE_intr_mask_ree_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_raw_ree : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_HI_INT_PARSE_INTR_RAW_REE_UNION;
#endif
#define SOC_HI_INT_PARSE_INTR_RAW_REE_intr_raw_ree_START (0)
#define SOC_HI_INT_PARSE_INTR_RAW_REE_intr_raw_ree_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_stat_ree : 23;
        unsigned int reserved : 9;
    } reg;
} SOC_HI_INT_PARSE_INTR_STAT_REE_UNION;
#endif
#define SOC_HI_INT_PARSE_INTR_STAT_REE_intr_stat_ree_START (0)
#define SOC_HI_INT_PARSE_INTR_STAT_REE_intr_stat_ree_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_clr_isp : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_HI_INT_PARSE_INTR_CLR_ISP_UNION;
#endif
#define SOC_HI_INT_PARSE_INTR_CLR_ISP_intr_clr_isp_START (0)
#define SOC_HI_INT_PARSE_INTR_CLR_ISP_intr_clr_isp_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_mask_isp : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_HI_INT_PARSE_INTR_MASK_ISP_UNION;
#endif
#define SOC_HI_INT_PARSE_INTR_MASK_ISP_intr_mask_isp_START (0)
#define SOC_HI_INT_PARSE_INTR_MASK_ISP_intr_mask_isp_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_raw_isp : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_HI_INT_PARSE_INTR_RAW_ISP_UNION;
#endif
#define SOC_HI_INT_PARSE_INTR_RAW_ISP_intr_raw_isp_START (0)
#define SOC_HI_INT_PARSE_INTR_RAW_ISP_intr_raw_isp_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_stat_isp : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_HI_INT_PARSE_INTR_STAT_ISP_UNION;
#endif
#define SOC_HI_INT_PARSE_INTR_STAT_ISP_intr_stat_isp_START (0)
#define SOC_HI_INT_PARSE_INTR_STAT_ISP_intr_stat_isp_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_clr_modem : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HI_INT_PARSE_INTR_CLR_MODEM_UNION;
#endif
#define SOC_HI_INT_PARSE_INTR_CLR_MODEM_intr_clr_modem_START (0)
#define SOC_HI_INT_PARSE_INTR_CLR_MODEM_intr_clr_modem_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_mask_modem : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HI_INT_PARSE_INTR_MASK_MODEM_UNION;
#endif
#define SOC_HI_INT_PARSE_INTR_MASK_MODEM_intr_mask_modem_START (0)
#define SOC_HI_INT_PARSE_INTR_MASK_MODEM_intr_mask_modem_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_raw_modem : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HI_INT_PARSE_INTR_RAW_MODEM_UNION;
#endif
#define SOC_HI_INT_PARSE_INTR_RAW_MODEM_intr_raw_modem_START (0)
#define SOC_HI_INT_PARSE_INTR_RAW_MODEM_intr_raw_modem_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_stat_modem : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_HI_INT_PARSE_INTR_STAT_MODEM_UNION;
#endif
#define SOC_HI_INT_PARSE_INTR_STAT_MODEM_intr_stat_modem_START (0)
#define SOC_HI_INT_PARSE_INTR_STAT_MODEM_intr_stat_modem_END (1)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
