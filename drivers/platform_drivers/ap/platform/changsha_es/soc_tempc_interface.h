#ifndef __SOC_TEMPC_INTERFACE_H__
#define __SOC_TEMPC_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_TEMPC_TEMPC_ALL_CFG_ADDR(base) ((base) + (0x000UL))
#define SOC_TEMPC_TEMP_HIGH_LF_TH_ADDR(base) ((base) + (0x004UL))
#define SOC_TEMPC_TEMP_HIGH_SD_TH_ADDR(base) ((base) + (0x008UL))
#define SOC_TEMPC_TEMP_HIGH_RST_TH_ADDR(base) ((base) + (0x00CUL))
#define SOC_TEMPC_TEMP_LOW_TH_ADDR(base) ((base) + (0x010UL))
#define SOC_TEMPC_TEMPC_INTR_ADDR(base) ((base) + (0x014UL))
#define SOC_TEMPC_TEMPC_INTR_CLR_ADDR(base) ((base) + (0x018UL))
#define SOC_TEMPC_TEMPC_INTR_MSK_ADDR(base) ((base) + (0x01cUL))
#define SOC_TEMPC_QUANT_SFT_BIT_ADDR(base) ((base) + (0x020UL))
#define SOC_TEMPC_TEMP_HOTSPOT_ADDR(base,HS_NUM) ((base) + (0x024+0x4*(HS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS0_ADDR(base,TS_NUM) ((base) + (0x064+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS1_ADDR(base,TS_NUM) ((base) + (0x0A4+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS2_ADDR(base,TS_NUM) ((base) + (0x0E4+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS3_ADDR(base,TS_NUM) ((base) + (0x124+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS4_ADDR(base,TS_NUM) ((base) + (0x164+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS5_ADDR(base,TS_NUM) ((base) + (0x1A4+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS6_ADDR(base,TS_NUM) ((base) + (0x1E4+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS7_ADDR(base,TS_NUM) ((base) + (0x224+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS8_ADDR(base,TS_NUM) ((base) + (0x264+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS9_ADDR(base,TS_NUM) ((base) + (0x2A4+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS10_ADDR(base,TS_NUM) ((base) + (0x2E4+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS11_ADDR(base,TS_NUM) ((base) + (0x324+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS12_ADDR(base,TS_NUM) ((base) + (0x364+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS13_ADDR(base,TS_NUM) ((base) + (0x3A4+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS14_ADDR(base,TS_NUM) ((base) + (0x3E4+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS15_ADDR(base,TS_NUM) ((base) + (0x424+0x4*(TS_NUM)))
#else
#define SOC_TEMPC_TEMPC_ALL_CFG_ADDR(base) ((base) + (0x000))
#define SOC_TEMPC_TEMP_HIGH_LF_TH_ADDR(base) ((base) + (0x004))
#define SOC_TEMPC_TEMP_HIGH_SD_TH_ADDR(base) ((base) + (0x008))
#define SOC_TEMPC_TEMP_HIGH_RST_TH_ADDR(base) ((base) + (0x00C))
#define SOC_TEMPC_TEMP_LOW_TH_ADDR(base) ((base) + (0x010))
#define SOC_TEMPC_TEMPC_INTR_ADDR(base) ((base) + (0x014))
#define SOC_TEMPC_TEMPC_INTR_CLR_ADDR(base) ((base) + (0x018))
#define SOC_TEMPC_TEMPC_INTR_MSK_ADDR(base) ((base) + (0x01c))
#define SOC_TEMPC_QUANT_SFT_BIT_ADDR(base) ((base) + (0x020))
#define SOC_TEMPC_TEMP_HOTSPOT_ADDR(base,HS_NUM) ((base) + (0x024+0x4*(HS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS0_ADDR(base,TS_NUM) ((base) + (0x064+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS1_ADDR(base,TS_NUM) ((base) + (0x0A4+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS2_ADDR(base,TS_NUM) ((base) + (0x0E4+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS3_ADDR(base,TS_NUM) ((base) + (0x124+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS4_ADDR(base,TS_NUM) ((base) + (0x164+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS5_ADDR(base,TS_NUM) ((base) + (0x1A4+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS6_ADDR(base,TS_NUM) ((base) + (0x1E4+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS7_ADDR(base,TS_NUM) ((base) + (0x224+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS8_ADDR(base,TS_NUM) ((base) + (0x264+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS9_ADDR(base,TS_NUM) ((base) + (0x2A4+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS10_ADDR(base,TS_NUM) ((base) + (0x2E4+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS11_ADDR(base,TS_NUM) ((base) + (0x324+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS12_ADDR(base,TS_NUM) ((base) + (0x364+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS13_ADDR(base,TS_NUM) ((base) + (0x3A4+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS14_ADDR(base,TS_NUM) ((base) + (0x3E4+0x4*(TS_NUM)))
#define SOC_TEMPC_TEMP_COEF_HS15_ADDR(base,TS_NUM) ((base) + (0x424+0x4*(TS_NUM)))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tempc_en : 1;
        unsigned int tempc_clk_en : 1;
        unsigned int reserved_0 : 14;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_TEMPC_TEMPC_ALL_CFG_UNION;
#endif
#define SOC_TEMPC_TEMPC_ALL_CFG_tempc_en_START (0)
#define SOC_TEMPC_TEMPC_ALL_CFG_tempc_en_END (0)
#define SOC_TEMPC_TEMPC_ALL_CFG_tempc_clk_en_START (1)
#define SOC_TEMPC_TEMPC_ALL_CFG_tempc_clk_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_high_lf_th : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_TEMPC_TEMP_HIGH_LF_TH_UNION;
#endif
#define SOC_TEMPC_TEMP_HIGH_LF_TH_temp_high_lf_th_START (0)
#define SOC_TEMPC_TEMP_HIGH_LF_TH_temp_high_lf_th_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_high_sd_th : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_TEMPC_TEMP_HIGH_SD_TH_UNION;
#endif
#define SOC_TEMPC_TEMP_HIGH_SD_TH_temp_high_sd_th_START (0)
#define SOC_TEMPC_TEMP_HIGH_SD_TH_temp_high_sd_th_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_high_rst_th : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_TEMPC_TEMP_HIGH_RST_TH_UNION;
#endif
#define SOC_TEMPC_TEMP_HIGH_RST_TH_temp_high_rst_th_START (0)
#define SOC_TEMPC_TEMP_HIGH_RST_TH_temp_high_rst_th_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_low_th : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_TEMPC_TEMP_LOW_TH_UNION;
#endif
#define SOC_TEMPC_TEMP_LOW_TH_temp_low_th_START (0)
#define SOC_TEMPC_TEMP_LOW_TH_temp_low_th_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tempc_intr : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_TEMPC_TEMPC_INTR_UNION;
#endif
#define SOC_TEMPC_TEMPC_INTR_tempc_intr_START (0)
#define SOC_TEMPC_TEMPC_INTR_tempc_intr_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tempc_intr_clr : 4;
        unsigned int reserved_0 : 12;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_TEMPC_TEMPC_INTR_CLR_UNION;
#endif
#define SOC_TEMPC_TEMPC_INTR_CLR_tempc_intr_clr_START (0)
#define SOC_TEMPC_TEMPC_INTR_CLR_tempc_intr_clr_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tempc_intr_msk : 4;
        unsigned int reserved_0 : 12;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_TEMPC_TEMPC_INTR_MSK_UNION;
#endif
#define SOC_TEMPC_TEMPC_INTR_MSK_tempc_intr_msk_START (0)
#define SOC_TEMPC_TEMPC_INTR_MSK_tempc_intr_msk_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int quant_sft_bit : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_TEMPC_QUANT_SFT_BIT_UNION;
#endif
#define SOC_TEMPC_QUANT_SFT_BIT_quant_sft_bit_START (0)
#define SOC_TEMPC_QUANT_SFT_BIT_quant_sft_bit_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_hotspot : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_TEMPC_TEMP_HOTSPOT_UNION;
#endif
#define SOC_TEMPC_TEMP_HOTSPOT_temp_hotspot_START (0)
#define SOC_TEMPC_TEMP_HOTSPOT_temp_hotspot_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_coef_hs0 : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_TEMPC_TEMP_COEF_HS0_UNION;
#endif
#define SOC_TEMPC_TEMP_COEF_HS0_temp_coef_hs0_START (0)
#define SOC_TEMPC_TEMP_COEF_HS0_temp_coef_hs0_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_coef_hs1 : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_TEMPC_TEMP_COEF_HS1_UNION;
#endif
#define SOC_TEMPC_TEMP_COEF_HS1_temp_coef_hs1_START (0)
#define SOC_TEMPC_TEMP_COEF_HS1_temp_coef_hs1_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_coef_hs2 : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_TEMPC_TEMP_COEF_HS2_UNION;
#endif
#define SOC_TEMPC_TEMP_COEF_HS2_temp_coef_hs2_START (0)
#define SOC_TEMPC_TEMP_COEF_HS2_temp_coef_hs2_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_coef_hs3 : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_TEMPC_TEMP_COEF_HS3_UNION;
#endif
#define SOC_TEMPC_TEMP_COEF_HS3_temp_coef_hs3_START (0)
#define SOC_TEMPC_TEMP_COEF_HS3_temp_coef_hs3_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_coef_hs4 : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_TEMPC_TEMP_COEF_HS4_UNION;
#endif
#define SOC_TEMPC_TEMP_COEF_HS4_temp_coef_hs4_START (0)
#define SOC_TEMPC_TEMP_COEF_HS4_temp_coef_hs4_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_coef_hs5 : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_TEMPC_TEMP_COEF_HS5_UNION;
#endif
#define SOC_TEMPC_TEMP_COEF_HS5_temp_coef_hs5_START (0)
#define SOC_TEMPC_TEMP_COEF_HS5_temp_coef_hs5_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_coef_hs6 : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_TEMPC_TEMP_COEF_HS6_UNION;
#endif
#define SOC_TEMPC_TEMP_COEF_HS6_temp_coef_hs6_START (0)
#define SOC_TEMPC_TEMP_COEF_HS6_temp_coef_hs6_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_coef_hs7 : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_TEMPC_TEMP_COEF_HS7_UNION;
#endif
#define SOC_TEMPC_TEMP_COEF_HS7_temp_coef_hs7_START (0)
#define SOC_TEMPC_TEMP_COEF_HS7_temp_coef_hs7_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_coef_hs8 : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_TEMPC_TEMP_COEF_HS8_UNION;
#endif
#define SOC_TEMPC_TEMP_COEF_HS8_temp_coef_hs8_START (0)
#define SOC_TEMPC_TEMP_COEF_HS8_temp_coef_hs8_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_coef_hs9 : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_TEMPC_TEMP_COEF_HS9_UNION;
#endif
#define SOC_TEMPC_TEMP_COEF_HS9_temp_coef_hs9_START (0)
#define SOC_TEMPC_TEMP_COEF_HS9_temp_coef_hs9_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_coef_hs10 : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_TEMPC_TEMP_COEF_HS10_UNION;
#endif
#define SOC_TEMPC_TEMP_COEF_HS10_temp_coef_hs10_START (0)
#define SOC_TEMPC_TEMP_COEF_HS10_temp_coef_hs10_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_coef_hs11 : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_TEMPC_TEMP_COEF_HS11_UNION;
#endif
#define SOC_TEMPC_TEMP_COEF_HS11_temp_coef_hs11_START (0)
#define SOC_TEMPC_TEMP_COEF_HS11_temp_coef_hs11_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_coef_hs12 : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_TEMPC_TEMP_COEF_HS12_UNION;
#endif
#define SOC_TEMPC_TEMP_COEF_HS12_temp_coef_hs12_START (0)
#define SOC_TEMPC_TEMP_COEF_HS12_temp_coef_hs12_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_coef_hs13 : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_TEMPC_TEMP_COEF_HS13_UNION;
#endif
#define SOC_TEMPC_TEMP_COEF_HS13_temp_coef_hs13_START (0)
#define SOC_TEMPC_TEMP_COEF_HS13_temp_coef_hs13_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_coef_hs14 : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_TEMPC_TEMP_COEF_HS14_UNION;
#endif
#define SOC_TEMPC_TEMP_COEF_HS14_temp_coef_hs14_START (0)
#define SOC_TEMPC_TEMP_COEF_HS14_temp_coef_hs14_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int temp_coef_hs15 : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_TEMPC_TEMP_COEF_HS15_UNION;
#endif
#define SOC_TEMPC_TEMP_COEF_HS15_temp_coef_hs15_START (0)
#define SOC_TEMPC_TEMP_COEF_HS15_temp_coef_hs15_END (14)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
