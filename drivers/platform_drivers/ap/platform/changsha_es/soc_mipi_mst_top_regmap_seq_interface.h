#ifndef __SOC_MIPI_MST_TOP_REGMAP_SEQ_INTERFACE_H__
#define __SOC_MIPI_MST_TOP_REGMAP_SEQ_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_DATA_4_ADDR(base) ((base) + (0x0UL))
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_DATA_3_ADDR(base) ((base) + (0x4UL))
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_DATA_2_ADDR(base) ((base) + (0x8UL))
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_DATA_1_ADDR(base) ((base) + (0xCUL))
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_DATA_0_ADDR(base) ((base) + (0x10UL))
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_START_CTRL_ADDR(base) ((base) + (0x14UL))
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PRI_BIT_CTRL_ADDR(base) ((base) + (0x18UL))
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PACK_DATA_3_ADDR(base) ((base) + (0x40UL))
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PACK_DATA_2_ADDR(base) ((base) + (0x44UL))
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PACK_DATA_1_ADDR(base) ((base) + (0x48UL))
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PACK_DATA_0_ADDR(base) ((base) + (0x4CUL))
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PACK_START_CTRL_ADDR(base) ((base) + (0x50UL))
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_RFFE_MIPI_MST_CKG_EN_ADDR(base) ((base) + (0x80UL))
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_RFFE_MIPI_MST_CKG_DIS_ADDR(base) ((base) + (0x84UL))
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_RFFE_MIPI_MST_CKG_STA_ADDR(base) ((base) + (0x88UL))
#else
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_DATA_4_ADDR(base) ((base) + (0x0))
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_DATA_3_ADDR(base) ((base) + (0x4))
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_DATA_2_ADDR(base) ((base) + (0x8))
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_DATA_1_ADDR(base) ((base) + (0xC))
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_DATA_0_ADDR(base) ((base) + (0x10))
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_START_CTRL_ADDR(base) ((base) + (0x14))
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PRI_BIT_CTRL_ADDR(base) ((base) + (0x18))
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PACK_DATA_3_ADDR(base) ((base) + (0x40))
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PACK_DATA_2_ADDR(base) ((base) + (0x44))
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PACK_DATA_1_ADDR(base) ((base) + (0x48))
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PACK_DATA_0_ADDR(base) ((base) + (0x4C))
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PACK_START_CTRL_ADDR(base) ((base) + (0x50))
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_RFFE_MIPI_MST_CKG_EN_ADDR(base) ((base) + (0x80))
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_RFFE_MIPI_MST_CKG_DIS_ADDR(base) ((base) + (0x84))
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_RFFE_MIPI_MST_CKG_STA_ADDR(base) ((base) + (0x88))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned short value;
    struct {
        unsigned short cpu_mipi_norm_data_4 : 16;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_DATA_4_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_DATA_4_cpu_mipi_norm_data_4_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_DATA_4_cpu_mipi_norm_data_4_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned short value;
    struct {
        unsigned short cpu_mipi_norm_data_3 : 16;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_DATA_3_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_DATA_3_cpu_mipi_norm_data_3_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_DATA_3_cpu_mipi_norm_data_3_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned short value;
    struct {
        unsigned short cpu_mipi_norm_data_2 : 16;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_DATA_2_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_DATA_2_cpu_mipi_norm_data_2_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_DATA_2_cpu_mipi_norm_data_2_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned short value;
    struct {
        unsigned short cpu_mipi_norm_data_1 : 16;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_DATA_1_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_DATA_1_cpu_mipi_norm_data_1_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_DATA_1_cpu_mipi_norm_data_1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned short value;
    struct {
        unsigned short cpu_mipi_norm_data_0 : 16;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_DATA_0_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_DATA_0_cpu_mipi_norm_data_0_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_DATA_0_cpu_mipi_norm_data_0_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned short value;
    struct {
        unsigned short cpu_mipi_norm_start_ind : 1;
        unsigned short cpu_mipi_norm_data_valid_num : 3;
        unsigned short cpu_mipi_pri_bit_index : 5;
        unsigned short reserved_0 : 3;
        unsigned short cpu_mipi_pri_bit_en : 1;
        unsigned short cpu_mipi_pri_bit_mdm_num : 1;
        unsigned short cpu_mipi_pri_bit_value : 1;
        unsigned short reserved_1 : 1;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_START_CTRL_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_START_CTRL_cpu_mipi_norm_start_ind_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_START_CTRL_cpu_mipi_norm_start_ind_END (0)
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_START_CTRL_cpu_mipi_norm_data_valid_num_START (1)
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_START_CTRL_cpu_mipi_norm_data_valid_num_END (3)
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_START_CTRL_cpu_mipi_pri_bit_index_START (4)
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_START_CTRL_cpu_mipi_pri_bit_index_END (8)
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_START_CTRL_cpu_mipi_pri_bit_en_START (12)
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_START_CTRL_cpu_mipi_pri_bit_en_END (12)
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_START_CTRL_cpu_mipi_pri_bit_mdm_num_START (13)
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_START_CTRL_cpu_mipi_pri_bit_mdm_num_END (13)
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_START_CTRL_cpu_mipi_pri_bit_value_START (14)
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_NORM_START_CTRL_cpu_mipi_pri_bit_value_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned short value;
    struct {
        unsigned short cpu_mipi_pri_bit_send_en : 1;
        unsigned short reserved : 15;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PRI_BIT_CTRL_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PRI_BIT_CTRL_cpu_mipi_pri_bit_send_en_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PRI_BIT_CTRL_cpu_mipi_pri_bit_send_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned short value;
    struct {
        unsigned short cpu_mipi_pack_data_3 : 16;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PACK_DATA_3_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PACK_DATA_3_cpu_mipi_pack_data_3_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PACK_DATA_3_cpu_mipi_pack_data_3_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned short value;
    struct {
        unsigned short cpu_mipi_pack_data_2 : 16;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PACK_DATA_2_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PACK_DATA_2_cpu_mipi_pack_data_2_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PACK_DATA_2_cpu_mipi_pack_data_2_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned short value;
    struct {
        unsigned short cpu_mipi_pack_data_1 : 16;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PACK_DATA_1_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PACK_DATA_1_cpu_mipi_pack_data_1_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PACK_DATA_1_cpu_mipi_pack_data_1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned short value;
    struct {
        unsigned short cpu_mipi_pack_data_0 : 16;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PACK_DATA_0_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PACK_DATA_0_cpu_mipi_pack_data_0_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PACK_DATA_0_cpu_mipi_pack_data_0_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned short value;
    struct {
        unsigned short cpu_mipi_pack_start_ind : 1;
        unsigned short reserved : 15;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PACK_START_CTRL_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PACK_START_CTRL_cpu_mipi_pack_start_ind_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_MIPI_PACK_START_CTRL_cpu_mipi_pack_start_ind_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned short value;
    struct {
        unsigned short cpu_mipi_mst_ckg_en : 1;
        unsigned short reserved : 15;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_SEQ_RFFE_MIPI_MST_CKG_EN_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_RFFE_MIPI_MST_CKG_EN_cpu_mipi_mst_ckg_en_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_RFFE_MIPI_MST_CKG_EN_cpu_mipi_mst_ckg_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned short value;
    struct {
        unsigned short cpu_mipi_mst_ckg_dis : 1;
        unsigned short reserved : 15;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_SEQ_RFFE_MIPI_MST_CKG_DIS_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_RFFE_MIPI_MST_CKG_DIS_cpu_mipi_mst_ckg_dis_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_RFFE_MIPI_MST_CKG_DIS_cpu_mipi_mst_ckg_dis_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned short value;
    struct {
        unsigned short cpu_mipi_mst_ckg_sta : 1;
        unsigned short reserved : 15;
    } reg;
} SOC_MIPI_MST_TOP_REGMAP_SEQ_RFFE_MIPI_MST_CKG_STA_UNION;
#endif
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_RFFE_MIPI_MST_CKG_STA_cpu_mipi_mst_ckg_sta_START (0)
#define SOC_MIPI_MST_TOP_REGMAP_SEQ_RFFE_MIPI_MST_CKG_STA_cpu_mipi_mst_ckg_sta_END (0)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
