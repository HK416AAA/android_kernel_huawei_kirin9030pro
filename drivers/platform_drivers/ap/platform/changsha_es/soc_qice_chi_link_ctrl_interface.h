#ifndef __SOC_QICE_CHI_LINK_CTRL_INTERFACE_H__
#define __SOC_QICE_CHI_LINK_CTRL_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QICE_CHI_LINK_CTRL_GLB_ADDR_CTRL_ADDR(base) ((base) + 0x0010UL)
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_LINK_INFO_ADDR(base) ((base) + 0x0400UL)
#define SOC_QICE_CHI_LINK_CTRL_LINK_RESERVED_RW_ADDR(base) ((base) + 0x0404UL)
#define SOC_QICE_CHI_LINK_CTRL_LINK_RESERVED_RO_ADDR(base) ((base) + 0x0408UL)
#define SOC_QICE_CHI_LINK_CTRL_LINK_CKG_BYPS_ADDR(base) ((base) + 0x0410UL)
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_LINK_CKG_EXT_EN_ADDR(base) ((base) + 0x0414UL)
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_LINK_SYSCOACK_ADDR(base) ((base) + 0x0418UL)
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_LINK_TXSACTIVE_ADDR(base) ((base) + 0x041CUL)
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_DVM_TGTID_SEL_ADDR(base) ((base) + 0x0420UL)
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_QTPE_EM_CFG_ADDR(base) ((base) + 0x0424UL)
#define SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_LINK_STAT_ADDR(base) ((base) + 0xE00UL)
#define SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_SYSCO_STAT_ADDR(base) ((base) + 0xE04UL)
#define SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_CKG_STAT_ADDR(base) ((base) + 0xE08UL)
#else
#define SOC_QICE_CHI_LINK_CTRL_GLB_ADDR_CTRL_ADDR(base) ((base) + 0x0010)
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_LINK_INFO_ADDR(base) ((base) + 0x0400)
#define SOC_QICE_CHI_LINK_CTRL_LINK_RESERVED_RW_ADDR(base) ((base) + 0x0404)
#define SOC_QICE_CHI_LINK_CTRL_LINK_RESERVED_RO_ADDR(base) ((base) + 0x0408)
#define SOC_QICE_CHI_LINK_CTRL_LINK_CKG_BYPS_ADDR(base) ((base) + 0x0410)
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_LINK_CKG_EXT_EN_ADDR(base) ((base) + 0x0414)
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_LINK_SYSCOACK_ADDR(base) ((base) + 0x0418)
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_LINK_TXSACTIVE_ADDR(base) ((base) + 0x041C)
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_DVM_TGTID_SEL_ADDR(base) ((base) + 0x0420)
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_QTPE_EM_CFG_ADDR(base) ((base) + 0x0424)
#define SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_LINK_STAT_ADDR(base) ((base) + 0xE00)
#define SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_SYSCO_STAT_ADDR(base) ((base) + 0xE04)
#define SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_CKG_STAT_ADDR(base) ((base) + 0xE08)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intlv_gran : 2;
        unsigned int reserved_0 : 1;
        unsigned int scramble_en : 1;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 2;
        unsigned int reserved_3 : 2;
        unsigned int reserved_4 : 22;
    } reg;
} SOC_QICE_CHI_LINK_CTRL_GLB_ADDR_CTRL_UNION;
#endif
#define SOC_QICE_CHI_LINK_CTRL_GLB_ADDR_CTRL_intlv_gran_START (0)
#define SOC_QICE_CHI_LINK_CTRL_GLB_ADDR_CTRL_intlv_gran_END (1)
#define SOC_QICE_CHI_LINK_CTRL_GLB_ADDR_CTRL_scramble_en_START (3)
#define SOC_QICE_CHI_LINK_CTRL_GLB_ADDR_CTRL_scramble_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int chirt_link_info : 32;
    } reg;
} SOC_QICE_CHI_LINK_CTRL_CHIRT_LINK_INFO_UNION;
#endif
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_LINK_INFO_chirt_link_info_START (0)
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_LINK_INFO_chirt_link_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int link_reserved_rw : 32;
    } reg;
} SOC_QICE_CHI_LINK_CTRL_LINK_RESERVED_RW_UNION;
#endif
#define SOC_QICE_CHI_LINK_CTRL_LINK_RESERVED_RW_link_reserved_rw_START (0)
#define SOC_QICE_CHI_LINK_CTRL_LINK_RESERVED_RW_link_reserved_rw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int link_reserved_ro : 32;
    } reg;
} SOC_QICE_CHI_LINK_CTRL_LINK_RESERVED_RO_UNION;
#endif
#define SOC_QICE_CHI_LINK_CTRL_LINK_RESERVED_RO_link_reserved_ro_START (0)
#define SOC_QICE_CHI_LINK_CTRL_LINK_RESERVED_RO_link_reserved_ro_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ckg_byp_ckg_cfg : 1;
        unsigned int ckg_byp_ckg_lk_rs : 1;
        unsigned int ckg_byp_ckg_lk : 1;
        unsigned int ckg_byp_ckg_rs_req : 1;
        unsigned int ckg_byp_ckg_rs_wdata : 1;
        unsigned int ckg_byp_ckg_rs_rdata : 1;
        unsigned int ckg_byp_ckg_rs_srsp : 1;
        unsigned int ckg_byp_ckg_rs_crsp : 1;
        unsigned int ckg_byp_ckg_rs_snp : 1;
        unsigned int ckg_byp_ckg_sysco : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_QICE_CHI_LINK_CTRL_LINK_CKG_BYPS_UNION;
#endif
#define SOC_QICE_CHI_LINK_CTRL_LINK_CKG_BYPS_ckg_byp_ckg_cfg_START (0)
#define SOC_QICE_CHI_LINK_CTRL_LINK_CKG_BYPS_ckg_byp_ckg_cfg_END (0)
#define SOC_QICE_CHI_LINK_CTRL_LINK_CKG_BYPS_ckg_byp_ckg_lk_rs_START (1)
#define SOC_QICE_CHI_LINK_CTRL_LINK_CKG_BYPS_ckg_byp_ckg_lk_rs_END (1)
#define SOC_QICE_CHI_LINK_CTRL_LINK_CKG_BYPS_ckg_byp_ckg_lk_START (2)
#define SOC_QICE_CHI_LINK_CTRL_LINK_CKG_BYPS_ckg_byp_ckg_lk_END (2)
#define SOC_QICE_CHI_LINK_CTRL_LINK_CKG_BYPS_ckg_byp_ckg_rs_req_START (3)
#define SOC_QICE_CHI_LINK_CTRL_LINK_CKG_BYPS_ckg_byp_ckg_rs_req_END (3)
#define SOC_QICE_CHI_LINK_CTRL_LINK_CKG_BYPS_ckg_byp_ckg_rs_wdata_START (4)
#define SOC_QICE_CHI_LINK_CTRL_LINK_CKG_BYPS_ckg_byp_ckg_rs_wdata_END (4)
#define SOC_QICE_CHI_LINK_CTRL_LINK_CKG_BYPS_ckg_byp_ckg_rs_rdata_START (5)
#define SOC_QICE_CHI_LINK_CTRL_LINK_CKG_BYPS_ckg_byp_ckg_rs_rdata_END (5)
#define SOC_QICE_CHI_LINK_CTRL_LINK_CKG_BYPS_ckg_byp_ckg_rs_srsp_START (6)
#define SOC_QICE_CHI_LINK_CTRL_LINK_CKG_BYPS_ckg_byp_ckg_rs_srsp_END (6)
#define SOC_QICE_CHI_LINK_CTRL_LINK_CKG_BYPS_ckg_byp_ckg_rs_crsp_START (7)
#define SOC_QICE_CHI_LINK_CTRL_LINK_CKG_BYPS_ckg_byp_ckg_rs_crsp_END (7)
#define SOC_QICE_CHI_LINK_CTRL_LINK_CKG_BYPS_ckg_byp_ckg_rs_snp_START (8)
#define SOC_QICE_CHI_LINK_CTRL_LINK_CKG_BYPS_ckg_byp_ckg_rs_snp_END (8)
#define SOC_QICE_CHI_LINK_CTRL_LINK_CKG_BYPS_ckg_byp_ckg_sysco_START (9)
#define SOC_QICE_CHI_LINK_CTRL_LINK_CKG_BYPS_ckg_byp_ckg_sysco_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 31;
        unsigned int icfg_ckg_ext_ena : 1;
    } reg;
} SOC_QICE_CHI_LINK_CTRL_CHIRT_LINK_CKG_EXT_EN_UNION;
#endif
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_LINK_CKG_EXT_EN_icfg_ckg_ext_ena_START (31)
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_LINK_CKG_EXT_EN_icfg_ckg_ext_ena_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_syscoack_enable_high : 1;
        unsigned int icfg_syscoack_enable_low : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_CHI_LINK_CTRL_CHIRT_LINK_SYSCOACK_UNION;
#endif
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_LINK_SYSCOACK_icfg_syscoack_enable_high_START (0)
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_LINK_SYSCOACK_icfg_syscoack_enable_high_END (0)
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_LINK_SYSCOACK_icfg_syscoack_enable_low_START (1)
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_LINK_SYSCOACK_icfg_syscoack_enable_low_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_txsactive_high : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_CHI_LINK_CTRL_CHIRT_LINK_TXSACTIVE_UNION;
#endif
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_LINK_TXSACTIVE_icfg_txsactive_high_START (0)
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_LINK_TXSACTIVE_icfg_txsactive_high_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_dvm_tgtid_sel : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_CHI_LINK_CTRL_CHIRT_DVM_TGTID_SEL_UNION;
#endif
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_DVM_TGTID_SEL_icfg_dvm_tgtid_sel_START (0)
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_DVM_TGTID_SEL_icfg_dvm_tgtid_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int icfg_ckg_byp_qtpe_em : 1;
        unsigned int icfg_qtpe_em_disable : 1;
        unsigned int dfx_ckg_busy_qtpe_em : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_QICE_CHI_LINK_CTRL_CHIRT_QTPE_EM_CFG_UNION;
#endif
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_QTPE_EM_CFG_icfg_ckg_byp_qtpe_em_START (0)
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_QTPE_EM_CFG_icfg_ckg_byp_qtpe_em_END (0)
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_QTPE_EM_CFG_icfg_qtpe_em_disable_START (1)
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_QTPE_EM_CFG_icfg_qtpe_em_disable_END (1)
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_QTPE_EM_CFG_dfx_ckg_busy_qtpe_em_START (2)
#define SOC_QICE_CHI_LINK_CTRL_CHIRT_QTPE_EM_CFG_dfx_ckg_busy_qtpe_em_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_rx_link_stat : 2;
        unsigned int dfx_tx_link_stat : 2;
        unsigned int dfx_get_all_crd : 1;
        unsigned int dfx_link_busy : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_LINK_STAT_UNION;
#endif
#define SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_LINK_STAT_dfx_rx_link_stat_START (0)
#define SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_LINK_STAT_dfx_rx_link_stat_END (1)
#define SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_LINK_STAT_dfx_tx_link_stat_START (2)
#define SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_LINK_STAT_dfx_tx_link_stat_END (3)
#define SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_LINK_STAT_dfx_get_all_crd_START (4)
#define SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_LINK_STAT_dfx_get_all_crd_END (4)
#define SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_LINK_STAT_dfx_link_busy_START (5)
#define SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_LINK_STAT_dfx_link_busy_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_chi_cpu_syscoreq : 1;
        unsigned int dfx_chi_cpu_syscoack : 1;
        unsigned int dfx_chi_sc_syscoreq : 8;
        unsigned int reserved_0 : 2;
        unsigned int dfx_chi_sc_syscoack : 8;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 10;
    } reg;
} SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_SYSCO_STAT_UNION;
#endif
#define SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_SYSCO_STAT_dfx_chi_cpu_syscoreq_START (0)
#define SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_SYSCO_STAT_dfx_chi_cpu_syscoreq_END (0)
#define SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_SYSCO_STAT_dfx_chi_cpu_syscoack_START (1)
#define SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_SYSCO_STAT_dfx_chi_cpu_syscoack_END (1)
#define SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_SYSCO_STAT_dfx_chi_sc_syscoreq_START (2)
#define SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_SYSCO_STAT_dfx_chi_sc_syscoreq_END (9)
#define SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_SYSCO_STAT_dfx_chi_sc_syscoack_START (12)
#define SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_SYSCO_STAT_dfx_chi_sc_syscoack_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_ckg_busy_sysco : 1;
        unsigned int dfx_ckg_busy_lk : 1;
        unsigned int dfx_ckg_busy_cfg : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_CKG_STAT_UNION;
#endif
#define SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_CKG_STAT_dfx_ckg_busy_sysco_START (0)
#define SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_CKG_STAT_dfx_ckg_busy_sysco_END (0)
#define SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_CKG_STAT_dfx_ckg_busy_lk_START (1)
#define SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_CKG_STAT_dfx_ckg_busy_lk_END (1)
#define SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_CKG_STAT_dfx_ckg_busy_cfg_START (2)
#define SOC_QICE_CHI_LINK_CTRL_CHI_RT_DFX_CKG_STAT_dfx_ckg_busy_cfg_END (2)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
