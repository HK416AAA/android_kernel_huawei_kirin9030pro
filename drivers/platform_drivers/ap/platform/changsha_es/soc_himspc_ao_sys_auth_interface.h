#ifndef __SOC_HIMSPC_AO_SYS_AUTH_INTERFACE_H__
#define __SOC_HIMSPC_AO_SYS_AUTH_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HIMSPC_AO_SYS_AUTH_LPMCU_DFT_AUTH_ENABLE_ADDR(base) (base)
#define SOC_HIMSPC_AO_SYS_AUTH_AO_IPC_RESET_LOCK_ENABLE_ADDR(base) ((base) + 0x0004UL)
#define SOC_HIMSPC_AO_SYS_AUTH_AO_IPC_RESET_UNLOCK_ENABLE_ADDR(base) ((base) + 0x0008UL)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC0_ADDR(base) ((base) + 0x0014UL)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC1_ADDR(base) ((base) + 0x0018UL)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC2_ADDR(base) ((base) + 0x001CUL)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC3_ADDR(base) ((base) + 0x0020UL)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC4_ADDR(base) ((base) + 0x0024UL)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC5_ADDR(base) ((base) + 0x0028UL)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC6_ADDR(base) ((base) + 0x002CUL)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC7_ADDR(base) ((base) + 0x0030UL)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC8_ADDR(base) ((base) + 0x0034UL)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC9_ADDR(base) ((base) + 0x0038UL)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC10_ADDR(base) ((base) + 0x003CUL)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC11_ADDR(base) ((base) + 0x0040UL)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC12_ADDR(base) ((base) + 0x0044UL)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC13_ADDR(base) ((base) + 0x0048UL)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC14_ADDR(base) ((base) + 0x004CUL)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC15_ADDR(base) ((base) + 0x0050UL)
#define SOC_HIMSPC_AO_SYS_AUTH_AO_IPC_RESET_LOCK_STATUS_ADDR(base) ((base) + 0x0054UL)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_CFG_RESERVE0_ADDR(base) ((base) + 0x005CUL)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_CFG_RESERVE1_ADDR(base) ((base) + 0x0060UL)
#define SOC_HIMSPC_AO_SYS_AUTH_TEE2MSPE_DERIVE_DATA0_ADDR(base) ((base) + 0x0064UL)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC2MSPE_DERIVE_DATA1_ADDR(base) ((base) + 0x0068UL)
#define SOC_HIMSPC_AO_SYS_AUTH_TEE2MSPE_DERIVE_DATA_SECCFG_ADDR(base) ((base) + 0x006CUL)
#define SOC_HIMSPC_AO_SYS_AUTH_DMIC_SECURITY_EN_ADDR(base) ((base) + 0x0070UL)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPE_DERIVE_SEED_CLR_ADDR(base) ((base) + 0x1000UL)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPE_DERIVE_SEED_CLR_SECCFG_ADDR(base) ((base) + 0x1004UL)
#else
#define SOC_HIMSPC_AO_SYS_AUTH_LPMCU_DFT_AUTH_ENABLE_ADDR(base) (base)
#define SOC_HIMSPC_AO_SYS_AUTH_AO_IPC_RESET_LOCK_ENABLE_ADDR(base) ((base) + 0x0004)
#define SOC_HIMSPC_AO_SYS_AUTH_AO_IPC_RESET_UNLOCK_ENABLE_ADDR(base) ((base) + 0x0008)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC0_ADDR(base) ((base) + 0x0014)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC1_ADDR(base) ((base) + 0x0018)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC2_ADDR(base) ((base) + 0x001C)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC3_ADDR(base) ((base) + 0x0020)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC4_ADDR(base) ((base) + 0x0024)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC5_ADDR(base) ((base) + 0x0028)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC6_ADDR(base) ((base) + 0x002C)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC7_ADDR(base) ((base) + 0x0030)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC8_ADDR(base) ((base) + 0x0034)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC9_ADDR(base) ((base) + 0x0038)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC10_ADDR(base) ((base) + 0x003C)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC11_ADDR(base) ((base) + 0x0040)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC12_ADDR(base) ((base) + 0x0044)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC13_ADDR(base) ((base) + 0x0048)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC14_ADDR(base) ((base) + 0x004C)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC15_ADDR(base) ((base) + 0x0050)
#define SOC_HIMSPC_AO_SYS_AUTH_AO_IPC_RESET_LOCK_STATUS_ADDR(base) ((base) + 0x0054)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_CFG_RESERVE0_ADDR(base) ((base) + 0x005C)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_CFG_RESERVE1_ADDR(base) ((base) + 0x0060)
#define SOC_HIMSPC_AO_SYS_AUTH_TEE2MSPE_DERIVE_DATA0_ADDR(base) ((base) + 0x0064)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC2MSPE_DERIVE_DATA1_ADDR(base) ((base) + 0x0068)
#define SOC_HIMSPC_AO_SYS_AUTH_TEE2MSPE_DERIVE_DATA_SECCFG_ADDR(base) ((base) + 0x006C)
#define SOC_HIMSPC_AO_SYS_AUTH_DMIC_SECURITY_EN_ADDR(base) ((base) + 0x0070)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPE_DERIVE_SEED_CLR_ADDR(base) ((base) + 0x1000)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPE_DERIVE_SEED_CLR_SECCFG_ADDR(base) ((base) + 0x1004)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpmcu_dft_auth_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_AO_SYS_AUTH_LPMCU_DFT_AUTH_ENABLE_UNION;
#endif
#define SOC_HIMSPC_AO_SYS_AUTH_LPMCU_DFT_AUTH_ENABLE_lpmcu_dft_auth_enable_START (0)
#define SOC_HIMSPC_AO_SYS_AUTH_LPMCU_DFT_AUTH_ENABLE_lpmcu_dft_auth_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ao_ipc_reset_lock_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_AO_SYS_AUTH_AO_IPC_RESET_LOCK_ENABLE_UNION;
#endif
#define SOC_HIMSPC_AO_SYS_AUTH_AO_IPC_RESET_LOCK_ENABLE_ao_ipc_reset_lock_enable_START (0)
#define SOC_HIMSPC_AO_SYS_AUTH_AO_IPC_RESET_LOCK_ENABLE_ao_ipc_reset_lock_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ao_ipc_reset_unlock_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_AO_SYS_AUTH_AO_IPC_RESET_UNLOCK_ENABLE_UNION;
#endif
#define SOC_HIMSPC_AO_SYS_AUTH_AO_IPC_RESET_UNLOCK_ENABLE_ao_ipc_reset_unlock_enable_START (0)
#define SOC_HIMSPC_AO_SYS_AUTH_AO_IPC_RESET_UNLOCK_ENABLE_ao_ipc_reset_unlock_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_anti_rollback_mac0 : 32;
    } reg;
} SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC0_UNION;
#endif
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC0_mspc_anti_rollback_mac0_START (0)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC0_mspc_anti_rollback_mac0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_anti_rollback_mac1 : 32;
    } reg;
} SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC1_UNION;
#endif
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC1_mspc_anti_rollback_mac1_START (0)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC1_mspc_anti_rollback_mac1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_anti_rollback_mac2 : 32;
    } reg;
} SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC2_UNION;
#endif
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC2_mspc_anti_rollback_mac2_START (0)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC2_mspc_anti_rollback_mac2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_anti_rollback_mac3 : 32;
    } reg;
} SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC3_UNION;
#endif
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC3_mspc_anti_rollback_mac3_START (0)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC3_mspc_anti_rollback_mac3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_anti_rollback_mac4 : 32;
    } reg;
} SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC4_UNION;
#endif
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC4_mspc_anti_rollback_mac4_START (0)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC4_mspc_anti_rollback_mac4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_anti_rollback_mac5 : 32;
    } reg;
} SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC5_UNION;
#endif
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC5_mspc_anti_rollback_mac5_START (0)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC5_mspc_anti_rollback_mac5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_anti_rollback_mac6 : 32;
    } reg;
} SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC6_UNION;
#endif
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC6_mspc_anti_rollback_mac6_START (0)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC6_mspc_anti_rollback_mac6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_anti_rollback_mac7 : 32;
    } reg;
} SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC7_UNION;
#endif
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC7_mspc_anti_rollback_mac7_START (0)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC7_mspc_anti_rollback_mac7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_anti_rollback_mac8 : 32;
    } reg;
} SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC8_UNION;
#endif
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC8_mspc_anti_rollback_mac8_START (0)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC8_mspc_anti_rollback_mac8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_anti_rollback_mac9 : 32;
    } reg;
} SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC9_UNION;
#endif
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC9_mspc_anti_rollback_mac9_START (0)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC9_mspc_anti_rollback_mac9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_anti_rollback_mac10 : 32;
    } reg;
} SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC10_UNION;
#endif
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC10_mspc_anti_rollback_mac10_START (0)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC10_mspc_anti_rollback_mac10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_anti_rollback_mac11 : 32;
    } reg;
} SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC11_UNION;
#endif
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC11_mspc_anti_rollback_mac11_START (0)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC11_mspc_anti_rollback_mac11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_anti_rollback_mac12 : 32;
    } reg;
} SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC12_UNION;
#endif
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC12_mspc_anti_rollback_mac12_START (0)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC12_mspc_anti_rollback_mac12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_anti_rollback_mac13 : 32;
    } reg;
} SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC13_UNION;
#endif
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC13_mspc_anti_rollback_mac13_START (0)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC13_mspc_anti_rollback_mac13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_anti_rollback_mac14 : 32;
    } reg;
} SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC14_UNION;
#endif
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC14_mspc_anti_rollback_mac14_START (0)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC14_mspc_anti_rollback_mac14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_anti_rollback_mac15 : 32;
    } reg;
} SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC15_UNION;
#endif
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC15_mspc_anti_rollback_mac15_START (0)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_ANTI_ROLLBACK_MAC15_mspc_anti_rollback_mac15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ao_ipc_reset_lock_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_AO_SYS_AUTH_AO_IPC_RESET_LOCK_STATUS_UNION;
#endif
#define SOC_HIMSPC_AO_SYS_AUTH_AO_IPC_RESET_LOCK_STATUS_ao_ipc_reset_lock_status_START (0)
#define SOC_HIMSPC_AO_SYS_AUTH_AO_IPC_RESET_LOCK_STATUS_ao_ipc_reset_lock_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_cfg_reserve0 : 32;
    } reg;
} SOC_HIMSPC_AO_SYS_AUTH_MSPC_CFG_RESERVE0_UNION;
#endif
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_CFG_RESERVE0_mspc_cfg_reserve0_START (0)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_CFG_RESERVE0_mspc_cfg_reserve0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc_cfg_reserve1 : 32;
    } reg;
} SOC_HIMSPC_AO_SYS_AUTH_MSPC_CFG_RESERVE1_UNION;
#endif
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_CFG_RESERVE1_mspc_cfg_reserve1_START (0)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC_CFG_RESERVE1_mspc_cfg_reserve1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tee2mspe_derive_data0 : 32;
    } reg;
} SOC_HIMSPC_AO_SYS_AUTH_TEE2MSPE_DERIVE_DATA0_UNION;
#endif
#define SOC_HIMSPC_AO_SYS_AUTH_TEE2MSPE_DERIVE_DATA0_tee2mspe_derive_data0_START (0)
#define SOC_HIMSPC_AO_SYS_AUTH_TEE2MSPE_DERIVE_DATA0_tee2mspe_derive_data0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspc2mspe_derive_data1 : 32;
    } reg;
} SOC_HIMSPC_AO_SYS_AUTH_MSPC2MSPE_DERIVE_DATA1_UNION;
#endif
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC2MSPE_DERIVE_DATA1_mspc2mspe_derive_data1_START (0)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPC2MSPE_DERIVE_DATA1_mspc2mspe_derive_data1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tee2mspe_derive_data_seccfg : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_AO_SYS_AUTH_TEE2MSPE_DERIVE_DATA_SECCFG_UNION;
#endif
#define SOC_HIMSPC_AO_SYS_AUTH_TEE2MSPE_DERIVE_DATA_SECCFG_tee2mspe_derive_data_seccfg_START (0)
#define SOC_HIMSPC_AO_SYS_AUTH_TEE2MSPE_DERIVE_DATA_SECCFG_tee2mspe_derive_data_seccfg_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmic_security_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_AO_SYS_AUTH_DMIC_SECURITY_EN_UNION;
#endif
#define SOC_HIMSPC_AO_SYS_AUTH_DMIC_SECURITY_EN_dmic_security_en_START (0)
#define SOC_HIMSPC_AO_SYS_AUTH_DMIC_SECURITY_EN_dmic_security_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspe_derive_seed_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_AO_SYS_AUTH_MSPE_DERIVE_SEED_CLR_UNION;
#endif
#define SOC_HIMSPC_AO_SYS_AUTH_MSPE_DERIVE_SEED_CLR_mspe_derive_seed_clr_START (0)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPE_DERIVE_SEED_CLR_mspe_derive_seed_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mspe_derive_seed_clr_seccfg : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HIMSPC_AO_SYS_AUTH_MSPE_DERIVE_SEED_CLR_SECCFG_UNION;
#endif
#define SOC_HIMSPC_AO_SYS_AUTH_MSPE_DERIVE_SEED_CLR_SECCFG_mspe_derive_seed_clr_seccfg_START (0)
#define SOC_HIMSPC_AO_SYS_AUTH_MSPE_DERIVE_SEED_CLR_SECCFG_mspe_derive_seed_clr_seccfg_END (0)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
