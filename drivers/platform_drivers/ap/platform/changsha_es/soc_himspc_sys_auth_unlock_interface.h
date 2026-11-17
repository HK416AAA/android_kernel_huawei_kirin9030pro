#ifndef __SOC_HIMSPC_SYS_AUTH_UNLOCK_INTERFACE_H__
#define __SOC_HIMSPC_SYS_AUTH_UNLOCK_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_LPMCU_MPU_LOCK_ENABLE_ADDR(base) (base)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_LPMCU_MPU_UNLOCK_ENABLE_ADDR(base) ((base) + 0x0004UL)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_ENABLE_ACPU_LOCK_ENABLE_ADDR(base) ((base) + 0x0008UL)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_ENABLE_ACPU_UNLOCK_ENABLE_ADDR(base) ((base) + 0x000CUL)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_QICE_BYPASS_ADDR(base) ((base) + 0x0020UL)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGTH_CTRL_AUTH_ENABLE_ADDR(base) ((base) + 0x0024UL)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGTH_CTRL_AUTH_DISABLE_ADDR(base) ((base) + 0x0028UL)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGTH_DATA_AUTH_ENABLE_ADDR(base) ((base) + 0x002CUL)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGTH_DATA_AUTH_DISABLE_ADDR(base) ((base) + 0x0030UL)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_LPMCU_MPU_LOCK_STATUS_ADDR(base) ((base) + 0x0034UL)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_ACPU_PAGE_TABLE_LOCK_STATUS_ADDR(base) ((base) + 0x0038UL)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGHT_CTRL_AUTH_EN_STATUS_ADDR(base) ((base) + 0x0044UL)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGHT_DATA_AUTH_EN_STATUS_ADDR(base) ((base) + 0x0048UL)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG0_VERIFY_RES_ADDR(base) ((base) + 0x004CUL)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG1_VERIFY_RES_ADDR(base) ((base) + 0x0050UL)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG2_VERIFY_RES_ADDR(base) ((base) + 0x0054UL)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG3_VERIFY_RES_ADDR(base) ((base) + 0x0058UL)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG4_VERIFY_RES_ADDR(base) ((base) + 0x005CUL)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG5_VERIFY_RES_ADDR(base) ((base) + 0x0060UL)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG6_VERIFY_RES_ADDR(base) ((base) + 0x0064UL)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG7_VERIFY_RES_ADDR(base) ((base) + 0x0068UL)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG_DCV_CONFIG_ADDR(base) ((base) + 0x006CUL)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_CFG_RESERVE0_ADDR(base) ((base) + 0x0070UL)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_CFG_RESERVE1_ADDR(base) ((base) + 0x0074UL)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_LPMCU_DMA_MONOPLIZE_ADDR(base) ((base) + 0x0080UL)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_PERI_IPC_RESET_LOCK_ENABLE_ADDR(base) ((base) + 0x0084UL)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_PERI_IPC_RESET_UNLOCK_ENABLE_ADDR(base) ((base) + 0x0088UL)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_PERI_IPC_RESET_LOCK_STATUS_ADDR(base) ((base) + 0x008CUL)
#else
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_LPMCU_MPU_LOCK_ENABLE_ADDR(base) (base)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_LPMCU_MPU_UNLOCK_ENABLE_ADDR(base) ((base) + 0x0004)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_ENABLE_ACPU_LOCK_ENABLE_ADDR(base) ((base) + 0x0008)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_ENABLE_ACPU_UNLOCK_ENABLE_ADDR(base) ((base) + 0x000C)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_QICE_BYPASS_ADDR(base) ((base) + 0x0020)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGTH_CTRL_AUTH_ENABLE_ADDR(base) ((base) + 0x0024)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGTH_CTRL_AUTH_DISABLE_ADDR(base) ((base) + 0x0028)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGTH_DATA_AUTH_ENABLE_ADDR(base) ((base) + 0x002C)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGTH_DATA_AUTH_DISABLE_ADDR(base) ((base) + 0x0030)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_LPMCU_MPU_LOCK_STATUS_ADDR(base) ((base) + 0x0034)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_ACPU_PAGE_TABLE_LOCK_STATUS_ADDR(base) ((base) + 0x0038)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGHT_CTRL_AUTH_EN_STATUS_ADDR(base) ((base) + 0x0044)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGHT_DATA_AUTH_EN_STATUS_ADDR(base) ((base) + 0x0048)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG0_VERIFY_RES_ADDR(base) ((base) + 0x004C)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG1_VERIFY_RES_ADDR(base) ((base) + 0x0050)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG2_VERIFY_RES_ADDR(base) ((base) + 0x0054)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG3_VERIFY_RES_ADDR(base) ((base) + 0x0058)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG4_VERIFY_RES_ADDR(base) ((base) + 0x005C)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG5_VERIFY_RES_ADDR(base) ((base) + 0x0060)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG6_VERIFY_RES_ADDR(base) ((base) + 0x0064)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG7_VERIFY_RES_ADDR(base) ((base) + 0x0068)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG_DCV_CONFIG_ADDR(base) ((base) + 0x006C)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_CFG_RESERVE0_ADDR(base) ((base) + 0x0070)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_CFG_RESERVE1_ADDR(base) ((base) + 0x0074)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_LPMCU_DMA_MONOPLIZE_ADDR(base) ((base) + 0x0080)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_PERI_IPC_RESET_LOCK_ENABLE_ADDR(base) ((base) + 0x0084)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_PERI_IPC_RESET_UNLOCK_ENABLE_ADDR(base) ((base) + 0x0088)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_PERI_IPC_RESET_LOCK_STATUS_ADDR(base) ((base) + 0x008C)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_mpu_lock_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_SYS_AUTH_UNLOCK_LPMCU_MPU_LOCK_ENABLE_UNION;
#endif
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_LPMCU_MPU_LOCK_ENABLE_lpmcu_mpu_lock_enable_START (0)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_LPMCU_MPU_LOCK_ENABLE_lpmcu_mpu_lock_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_mpu_unlock_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_SYS_AUTH_UNLOCK_LPMCU_MPU_UNLOCK_ENABLE_UNION;
#endif
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_LPMCU_MPU_UNLOCK_ENABLE_lpmcu_mpu_unlock_enable_START (0)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_LPMCU_MPU_UNLOCK_ENABLE_lpmcu_mpu_unlock_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_enable_acpu_lock_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_ENABLE_ACPU_LOCK_ENABLE_UNION;
#endif
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_ENABLE_ACPU_LOCK_ENABLE_mspc_enable_acpu_lock_enable_START (0)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_ENABLE_ACPU_LOCK_ENABLE_mspc_enable_acpu_lock_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_enable_acpu_unlock_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_ENABLE_ACPU_UNLOCK_ENABLE_UNION;
#endif
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_ENABLE_ACPU_UNLOCK_ENABLE_mspc_enable_acpu_unlock_enable_START (0)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_ENABLE_ACPU_UNLOCK_ENABLE_mspc_enable_acpu_unlock_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_qice_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_QICE_BYPASS_UNION;
#endif
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_QICE_BYPASS_mspc_qice_bypass_START (0)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_QICE_BYPASS_mspc_qice_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coresight_ctrl_auth_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGTH_CTRL_AUTH_ENABLE_UNION;
#endif
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGTH_CTRL_AUTH_ENABLE_coresight_ctrl_auth_enable_START (0)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGTH_CTRL_AUTH_ENABLE_coresight_ctrl_auth_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coresight_ctrl_auth_disable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGTH_CTRL_AUTH_DISABLE_UNION;
#endif
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGTH_CTRL_AUTH_DISABLE_coresight_ctrl_auth_disable_START (0)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGTH_CTRL_AUTH_DISABLE_coresight_ctrl_auth_disable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coresight_data_auth_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGTH_DATA_AUTH_ENABLE_UNION;
#endif
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGTH_DATA_AUTH_ENABLE_coresight_data_auth_enable_START (0)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGTH_DATA_AUTH_ENABLE_coresight_data_auth_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coresight_data_auth_disable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGTH_DATA_AUTH_DISABLE_UNION;
#endif
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGTH_DATA_AUTH_DISABLE_coresight_data_auth_disable_START (0)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGTH_DATA_AUTH_DISABLE_coresight_data_auth_disable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_pmp_lock_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_SYS_AUTH_UNLOCK_LPMCU_MPU_LOCK_STATUS_UNION;
#endif
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_LPMCU_MPU_LOCK_STATUS_lpmcu_pmp_lock_status_START (0)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_LPMCU_MPU_LOCK_STATUS_lpmcu_pmp_lock_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int acpu_page_table_lock_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_SYS_AUTH_UNLOCK_ACPU_PAGE_TABLE_LOCK_STATUS_UNION;
#endif
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_ACPU_PAGE_TABLE_LOCK_STATUS_acpu_page_table_lock_status_START (0)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_ACPU_PAGE_TABLE_LOCK_STATUS_acpu_page_table_lock_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coresight_ctrl_auth_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGHT_CTRL_AUTH_EN_STATUS_UNION;
#endif
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGHT_CTRL_AUTH_EN_STATUS_coresight_ctrl_auth_en_START (0)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGHT_CTRL_AUTH_EN_STATUS_coresight_ctrl_auth_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int coresight_data_auth_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGHT_DATA_AUTH_EN_STATUS_UNION;
#endif
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGHT_DATA_AUTH_EN_STATUS_coresight_data_auth_en_START (0)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_CORESIGHT_DATA_AUTH_EN_STATUS_coresight_data_auth_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_img0_verify_res : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG0_VERIFY_RES_UNION;
#endif
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG0_VERIFY_RES_mspc_img0_verify_res_START (0)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG0_VERIFY_RES_mspc_img0_verify_res_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_img1_verify_res : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG1_VERIFY_RES_UNION;
#endif
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG1_VERIFY_RES_mspc_img1_verify_res_START (0)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG1_VERIFY_RES_mspc_img1_verify_res_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_img2_verify_res : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG2_VERIFY_RES_UNION;
#endif
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG2_VERIFY_RES_mspc_img2_verify_res_START (0)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG2_VERIFY_RES_mspc_img2_verify_res_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_img3_verify_res : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG3_VERIFY_RES_UNION;
#endif
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG3_VERIFY_RES_mspc_img3_verify_res_START (0)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG3_VERIFY_RES_mspc_img3_verify_res_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_img4_verify_res : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG4_VERIFY_RES_UNION;
#endif
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG4_VERIFY_RES_mspc_img4_verify_res_START (0)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG4_VERIFY_RES_mspc_img4_verify_res_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_img5_verify_res : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG5_VERIFY_RES_UNION;
#endif
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG5_VERIFY_RES_mspc_img5_verify_res_START (0)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG5_VERIFY_RES_mspc_img5_verify_res_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_img6_verify_res : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG6_VERIFY_RES_UNION;
#endif
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG6_VERIFY_RES_mspc_img6_verify_res_START (0)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG6_VERIFY_RES_mspc_img6_verify_res_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_img7_verify_res : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG7_VERIFY_RES_UNION;
#endif
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG7_VERIFY_RES_mspc_img7_verify_res_START (0)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG7_VERIFY_RES_mspc_img7_verify_res_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_img0_dcv_config : 1;
        unsigned int mspc_img1_dcv_config : 1;
        unsigned int mspc_img2_dcv_config : 1;
        unsigned int mspc_img3_dcv_config : 1;
        unsigned int mspc_img4_dcv_config : 1;
        unsigned int mspc_img5_dcv_config : 1;
        unsigned int mspc_img6_dcv_config : 1;
        unsigned int mspc_img7_dcv_config : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG_DCV_CONFIG_UNION;
#endif
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG_DCV_CONFIG_mspc_img0_dcv_config_START (0)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG_DCV_CONFIG_mspc_img0_dcv_config_END (0)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG_DCV_CONFIG_mspc_img1_dcv_config_START (1)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG_DCV_CONFIG_mspc_img1_dcv_config_END (1)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG_DCV_CONFIG_mspc_img2_dcv_config_START (2)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG_DCV_CONFIG_mspc_img2_dcv_config_END (2)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG_DCV_CONFIG_mspc_img3_dcv_config_START (3)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG_DCV_CONFIG_mspc_img3_dcv_config_END (3)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG_DCV_CONFIG_mspc_img4_dcv_config_START (4)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG_DCV_CONFIG_mspc_img4_dcv_config_END (4)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG_DCV_CONFIG_mspc_img5_dcv_config_START (5)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG_DCV_CONFIG_mspc_img5_dcv_config_END (5)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG_DCV_CONFIG_mspc_img6_dcv_config_START (6)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG_DCV_CONFIG_mspc_img6_dcv_config_END (6)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG_DCV_CONFIG_mspc_img7_dcv_config_START (7)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_IMG_DCV_CONFIG_mspc_img7_dcv_config_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_cfg_reserve0 : 32;
    } reg;
} SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_CFG_RESERVE0_UNION;
#endif
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_CFG_RESERVE0_mspc_cfg_reserve0_START (0)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_CFG_RESERVE0_mspc_cfg_reserve0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_cfg_reserve1 : 32;
    } reg;
} SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_CFG_RESERVE1_UNION;
#endif
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_CFG_RESERVE1_mspc_cfg_reserve1_START (0)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_MSPC_CFG_RESERVE1_mspc_cfg_reserve1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_dma_monoplize : 16;
        unsigned int lpmcu_dma_monoplize_errrsp_en : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_HIMSPC_SYS_AUTH_UNLOCK_LPMCU_DMA_MONOPLIZE_UNION;
#endif
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_LPMCU_DMA_MONOPLIZE_lpmcu_dma_monoplize_START (0)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_LPMCU_DMA_MONOPLIZE_lpmcu_dma_monoplize_END (15)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_LPMCU_DMA_MONOPLIZE_lpmcu_dma_monoplize_errrsp_en_START (16)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_LPMCU_DMA_MONOPLIZE_lpmcu_dma_monoplize_errrsp_en_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_ipc_reset_lock_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_SYS_AUTH_UNLOCK_PERI_IPC_RESET_LOCK_ENABLE_UNION;
#endif
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_PERI_IPC_RESET_LOCK_ENABLE_peri_ipc_reset_lock_enable_START (0)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_PERI_IPC_RESET_LOCK_ENABLE_peri_ipc_reset_lock_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_ipc_reset_unlock_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_SYS_AUTH_UNLOCK_PERI_IPC_RESET_UNLOCK_ENABLE_UNION;
#endif
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_PERI_IPC_RESET_UNLOCK_ENABLE_peri_ipc_reset_unlock_enable_START (0)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_PERI_IPC_RESET_UNLOCK_ENABLE_peri_ipc_reset_unlock_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int peri_ipc_reset_lock_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_SYS_AUTH_UNLOCK_PERI_IPC_RESET_LOCK_STATUS_UNION;
#endif
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_PERI_IPC_RESET_LOCK_STATUS_peri_ipc_reset_lock_status_START (0)
#define SOC_HIMSPC_SYS_AUTH_UNLOCK_PERI_IPC_RESET_LOCK_STATUS_peri_ipc_reset_lock_status_END (0)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
