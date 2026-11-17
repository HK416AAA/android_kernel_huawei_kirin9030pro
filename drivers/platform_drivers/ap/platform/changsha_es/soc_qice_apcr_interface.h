#ifndef __SOC_QICE_APCR_INTERFACE_H__
#define __SOC_QICE_APCR_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QICE_APCR_APCR_CTRL_ADDR(base) (base)
#define SOC_QICE_APCR_PROT_CTRL_ADDR(base) ((base) + 0x0004UL)
#define SOC_QICE_APCR_PMST_CTRL_ADDR(base) ((base) + 0x0008UL)
#define SOC_QICE_APCR_CHAIN_WACK_ADDR(base) ((base) + 0x000CUL)
#define SOC_QICE_APCR_LOCK_SEL_ADDR(base) ((base) + 0x0010UL)
#define SOC_QICE_APCR_REQ_ERR_TYPE_ADDR(base) ((base) + 0x0014UL)
#define SOC_QICE_APCR_TIMEOUT_CNT_MIN_VALUE_ADDR(base) ((base) + 0x0018UL)
#define SOC_QICE_APCR_APC_KPU_CFG_S_ADDR(base) ((base) + 0x001CUL)
#define SOC_QICE_APCR_PNODE_EN_ADDR(base,pn_idx) (base) + 0x020 + 0x4 * (pn_idx)
#else
#define SOC_QICE_APCR_APCR_CTRL_ADDR(base) (base)
#define SOC_QICE_APCR_PROT_CTRL_ADDR(base) ((base) + 0x0004)
#define SOC_QICE_APCR_PMST_CTRL_ADDR(base) ((base) + 0x0008)
#define SOC_QICE_APCR_CHAIN_WACK_ADDR(base) ((base) + 0x000C)
#define SOC_QICE_APCR_LOCK_SEL_ADDR(base) ((base) + 0x0010)
#define SOC_QICE_APCR_REQ_ERR_TYPE_ADDR(base) ((base) + 0x0014)
#define SOC_QICE_APCR_TIMEOUT_CNT_MIN_VALUE_ADDR(base) ((base) + 0x0018)
#define SOC_QICE_APCR_APC_KPU_CFG_S_ADDR(base) ((base) + 0x001C)
#define SOC_QICE_APCR_PNODE_EN_ADDR(base,pn_idx) (base) + 0x020 + 0x4 * (pn_idx)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int prdata_prot : 8;
        unsigned int prdata_tout : 8;
        unsigned int pslverr_prot : 1;
        unsigned int pslverr_tout : 1;
        unsigned int reserved_0 : 2;
        unsigned int tout_prd : 4;
        unsigned int nersp_prd : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_QICE_APCR_APCR_CTRL_UNION;
#endif
#define SOC_QICE_APCR_APCR_CTRL_prdata_prot_START (0)
#define SOC_QICE_APCR_APCR_CTRL_prdata_prot_END (7)
#define SOC_QICE_APCR_APCR_CTRL_prdata_tout_START (8)
#define SOC_QICE_APCR_APCR_CTRL_prdata_tout_END (15)
#define SOC_QICE_APCR_APCR_CTRL_pslverr_prot_START (16)
#define SOC_QICE_APCR_APCR_CTRL_pslverr_prot_END (16)
#define SOC_QICE_APCR_APCR_CTRL_pslverr_tout_START (17)
#define SOC_QICE_APCR_APCR_CTRL_pslverr_tout_END (17)
#define SOC_QICE_APCR_APCR_CTRL_tout_prd_START (20)
#define SOC_QICE_APCR_APCR_CTRL_tout_prd_END (23)
#define SOC_QICE_APCR_APCR_CTRL_nersp_prd_START (24)
#define SOC_QICE_APCR_APCR_CTRL_nersp_prd_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int protzone_cfg_s2ns : 1;
        unsigned int reserved_0 : 3;
        unsigned int protzone_cfg_ns2s : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_QICE_APCR_PROT_CTRL_UNION;
#endif
#define SOC_QICE_APCR_PROT_CTRL_protzone_cfg_s2ns_START (0)
#define SOC_QICE_APCR_PROT_CTRL_protzone_cfg_s2ns_END (0)
#define SOC_QICE_APCR_PROT_CTRL_protzone_cfg_ns2s_START (4)
#define SOC_QICE_APCR_PROT_CTRL_protzone_cfg_ns2s_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmst_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_APCR_PMST_CTRL_UNION;
#endif
#define SOC_QICE_APCR_PMST_CTRL_pmst_en_START (0)
#define SOC_QICE_APCR_PMST_CTRL_pmst_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int chain_wack_en : 32;
    } reg;
} SOC_QICE_APCR_CHAIN_WACK_UNION;
#endif
#define SOC_QICE_APCR_CHAIN_WACK_chain_wack_en_START (0)
#define SOC_QICE_APCR_CHAIN_WACK_chain_wack_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmst_ctrl_lock_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_APCR_LOCK_SEL_UNION;
#endif
#define SOC_QICE_APCR_LOCK_SEL_pmst_ctrl_lock_sel_START (0)
#define SOC_QICE_APCR_LOCK_SEL_pmst_ctrl_lock_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apc_req_prot_err : 1;
        unsigned int apc_req_timeout : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_APCR_REQ_ERR_TYPE_UNION;
#endif
#define SOC_QICE_APCR_REQ_ERR_TYPE_apc_req_prot_err_START (0)
#define SOC_QICE_APCR_REQ_ERR_TYPE_apc_req_prot_err_END (0)
#define SOC_QICE_APCR_REQ_ERR_TYPE_apc_req_timeout_START (1)
#define SOC_QICE_APCR_REQ_ERR_TYPE_apc_req_timeout_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timeout_cnt_min_value : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_APCR_TIMEOUT_CNT_MIN_VALUE_UNION;
#endif
#define SOC_QICE_APCR_TIMEOUT_CNT_MIN_VALUE_timeout_cnt_min_value_START (0)
#define SOC_QICE_APCR_TIMEOUT_CNT_MIN_VALUE_timeout_cnt_min_value_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int apc_kpu_cfg_s : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_APCR_APC_KPU_CFG_S_UNION;
#endif
#define SOC_QICE_APCR_APC_KPU_CFG_S_apc_kpu_cfg_s_START (0)
#define SOC_QICE_APCR_APC_KPU_CFG_S_apc_kpu_cfg_s_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pnode_en : 32;
    } reg;
} SOC_QICE_APCR_PNODE_EN_UNION;
#endif
#define SOC_QICE_APCR_PNODE_EN_pnode_en_START (0)
#define SOC_QICE_APCR_PNODE_EN_pnode_en_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
