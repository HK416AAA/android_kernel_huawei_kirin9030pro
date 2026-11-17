#ifndef __SOC_QICE_GS_DMI_INTERFACE_H__
#define __SOC_QICE_GS_DMI_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QICE_GS_DMI_GEN_FUN_EN_ADDR(base) ((base) + (0x0400UL))
#define SOC_QICE_GS_DMI_PATTERN_GOLDEN_ADDR(base) ((base) + (0x0404UL))
#define SOC_QICE_GS_DMI_CMD_CNT_ADDR(base) ((base) + (0x0408UL))
#define SOC_QICE_GS_DMI_CKG_BYP_ADDR(base) ((base) + (0x040cUL))
#define SOC_QICE_GS_DMI_PATTERN_GOLDEN1_ADDR(base) ((base) + (0x0410UL))
#define SOC_QICE_GS_DMI_CMD_CNT_CLR_CFG_ADDR(base) ((base) + (0x0420UL))
#define SOC_QICE_GS_DMI_DFX_INT_CFG_ADDR(base) ((base) + (0x0e10UL))
#define SOC_QICE_GS_DMI_DFX_INT_REC0_ADDR(base) ((base) + (0x0e14UL))
#define SOC_QICE_GS_DMI_DFX_INT_REC1_ADDR(base) ((base) + (0x0e18UL))
#define SOC_QICE_GS_DMI_DFX_INT_CLR_CFG_ADDR(base) ((base) + (0x0e1cUL))
#else
#define SOC_QICE_GS_DMI_GEN_FUN_EN_ADDR(base) ((base) + (0x0400))
#define SOC_QICE_GS_DMI_PATTERN_GOLDEN_ADDR(base) ((base) + (0x0404))
#define SOC_QICE_GS_DMI_CMD_CNT_ADDR(base) ((base) + (0x0408))
#define SOC_QICE_GS_DMI_CKG_BYP_ADDR(base) ((base) + (0x040c))
#define SOC_QICE_GS_DMI_PATTERN_GOLDEN1_ADDR(base) ((base) + (0x0410))
#define SOC_QICE_GS_DMI_CMD_CNT_CLR_CFG_ADDR(base) ((base) + (0x0420))
#define SOC_QICE_GS_DMI_DFX_INT_CFG_ADDR(base) ((base) + (0x0e10))
#define SOC_QICE_GS_DMI_DFX_INT_REC0_ADDR(base) ((base) + (0x0e14))
#define SOC_QICE_GS_DMI_DFX_INT_REC1_ADDR(base) ((base) + (0x0e18))
#define SOC_QICE_GS_DMI_DFX_INT_CLR_CFG_ADDR(base) ((base) + (0x0e1c))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_addr_check_en : 1;
        unsigned int cfg_data_check_en : 1;
        unsigned int cfg_cmd_cnt_en : 1;
        unsigned int cfg_read_mode : 2;
        unsigned int cfg_ddr_channel_mode : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_QICE_GS_DMI_GEN_FUN_EN_UNION;
#endif
#define SOC_QICE_GS_DMI_GEN_FUN_EN_cfg_addr_check_en_START (0)
#define SOC_QICE_GS_DMI_GEN_FUN_EN_cfg_addr_check_en_END (0)
#define SOC_QICE_GS_DMI_GEN_FUN_EN_cfg_data_check_en_START (1)
#define SOC_QICE_GS_DMI_GEN_FUN_EN_cfg_data_check_en_END (1)
#define SOC_QICE_GS_DMI_GEN_FUN_EN_cfg_cmd_cnt_en_START (2)
#define SOC_QICE_GS_DMI_GEN_FUN_EN_cfg_cmd_cnt_en_END (2)
#define SOC_QICE_GS_DMI_GEN_FUN_EN_cfg_read_mode_START (3)
#define SOC_QICE_GS_DMI_GEN_FUN_EN_cfg_read_mode_END (4)
#define SOC_QICE_GS_DMI_GEN_FUN_EN_cfg_ddr_channel_mode_START (5)
#define SOC_QICE_GS_DMI_GEN_FUN_EN_cfg_ddr_channel_mode_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pattern_golden : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_QICE_GS_DMI_PATTERN_GOLDEN_UNION;
#endif
#define SOC_QICE_GS_DMI_PATTERN_GOLDEN_cfg_pattern_golden_START (0)
#define SOC_QICE_GS_DMI_PATTERN_GOLDEN_cfg_pattern_golden_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gs_sum_cmd : 32;
    } reg;
} SOC_QICE_GS_DMI_CMD_CNT_UNION;
#endif
#define SOC_QICE_GS_DMI_CMD_CNT_gs_sum_cmd_START (0)
#define SOC_QICE_GS_DMI_CMD_CNT_gs_sum_cmd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ckg_byp_cfg : 1;
        unsigned int cfg_ckg_byp_gs : 1;
        unsigned int cfg_ckg_byp_int : 1;
        unsigned int cfg_ckg_ext_ena_cfg : 1;
        unsigned int cfg_ckg_ext_ena_gs : 1;
        unsigned int cfg_ckg_ext_ena_int : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_QICE_GS_DMI_CKG_BYP_UNION;
#endif
#define SOC_QICE_GS_DMI_CKG_BYP_cfg_ckg_byp_cfg_START (0)
#define SOC_QICE_GS_DMI_CKG_BYP_cfg_ckg_byp_cfg_END (0)
#define SOC_QICE_GS_DMI_CKG_BYP_cfg_ckg_byp_gs_START (1)
#define SOC_QICE_GS_DMI_CKG_BYP_cfg_ckg_byp_gs_END (1)
#define SOC_QICE_GS_DMI_CKG_BYP_cfg_ckg_byp_int_START (2)
#define SOC_QICE_GS_DMI_CKG_BYP_cfg_ckg_byp_int_END (2)
#define SOC_QICE_GS_DMI_CKG_BYP_cfg_ckg_ext_ena_cfg_START (3)
#define SOC_QICE_GS_DMI_CKG_BYP_cfg_ckg_ext_ena_cfg_END (3)
#define SOC_QICE_GS_DMI_CKG_BYP_cfg_ckg_ext_ena_gs_START (4)
#define SOC_QICE_GS_DMI_CKG_BYP_cfg_ckg_ext_ena_gs_END (4)
#define SOC_QICE_GS_DMI_CKG_BYP_cfg_ckg_ext_ena_int_START (5)
#define SOC_QICE_GS_DMI_CKG_BYP_cfg_ckg_ext_ena_int_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pattern_golden1 : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_QICE_GS_DMI_PATTERN_GOLDEN1_UNION;
#endif
#define SOC_QICE_GS_DMI_PATTERN_GOLDEN1_cfg_pattern_golden1_START (0)
#define SOC_QICE_GS_DMI_PATTERN_GOLDEN1_cfg_pattern_golden1_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_cmd_cnt_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_GS_DMI_CMD_CNT_CLR_CFG_UNION;
#endif
#define SOC_QICE_GS_DMI_CMD_CNT_CLR_CFG_cfg_cmd_cnt_clr_START (0)
#define SOC_QICE_GS_DMI_CMD_CNT_CLR_CFG_cfg_cmd_cnt_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_int_dis : 4;
        unsigned int icfg_int_mask : 4;
        unsigned int icfg_int_glb_mask : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_QICE_GS_DMI_DFX_INT_CFG_UNION;
#endif
#define SOC_QICE_GS_DMI_DFX_INT_CFG_icfg_int_dis_START (0)
#define SOC_QICE_GS_DMI_DFX_INT_CFG_icfg_int_dis_END (3)
#define SOC_QICE_GS_DMI_DFX_INT_CFG_icfg_int_mask_START (4)
#define SOC_QICE_GS_DMI_DFX_INT_CFG_icfg_int_mask_END (7)
#define SOC_QICE_GS_DMI_DFX_INT_CFG_icfg_int_glb_mask_START (8)
#define SOC_QICE_GS_DMI_DFX_INT_CFG_icfg_int_glb_mask_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ocfg_int_info0 : 32;
    } reg;
} SOC_QICE_GS_DMI_DFX_INT_REC0_UNION;
#endif
#define SOC_QICE_GS_DMI_DFX_INT_REC0_ocfg_int_info0_START (0)
#define SOC_QICE_GS_DMI_DFX_INT_REC0_ocfg_int_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ocfg_int_info1 : 2;
        unsigned int ocfg_int_type : 2;
        unsigned int ocfg_int_org_status : 4;
        unsigned int ocfg_int_mask_status : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_QICE_GS_DMI_DFX_INT_REC1_UNION;
#endif
#define SOC_QICE_GS_DMI_DFX_INT_REC1_ocfg_int_info1_START (0)
#define SOC_QICE_GS_DMI_DFX_INT_REC1_ocfg_int_info1_END (1)
#define SOC_QICE_GS_DMI_DFX_INT_REC1_ocfg_int_type_START (2)
#define SOC_QICE_GS_DMI_DFX_INT_REC1_ocfg_int_type_END (3)
#define SOC_QICE_GS_DMI_DFX_INT_REC1_ocfg_int_org_status_START (4)
#define SOC_QICE_GS_DMI_DFX_INT_REC1_ocfg_int_org_status_END (7)
#define SOC_QICE_GS_DMI_DFX_INT_REC1_ocfg_int_mask_status_START (8)
#define SOC_QICE_GS_DMI_DFX_INT_REC1_ocfg_int_mask_status_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_int_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_GS_DMI_DFX_INT_CLR_CFG_UNION;
#endif
#define SOC_QICE_GS_DMI_DFX_INT_CLR_CFG_icfg_int_clr_START (0)
#define SOC_QICE_GS_DMI_DFX_INT_CLR_CFG_icfg_int_clr_END (0)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
