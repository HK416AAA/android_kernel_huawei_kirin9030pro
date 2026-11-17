#ifndef __SOC_L3CACHE_RAS_INTERFACE_H__
#define __SOC_L3CACHE_RAS_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_L3cache_RAS_NAMTSORAS_ERR0FR_ADDR(base) ((base) + (0x0000UL))
#define SOC_L3cache_RAS_NAMTSORAS_ERR0CTLR_ADDR(base) ((base) + (0x0008UL))
#define SOC_L3cache_RAS_NAMTSORAS_ERR0STATUS_ADDR(base) ((base) + (0x0010UL))
#define SOC_L3cache_RAS_NAMTSORAS_ERR0MISC0_ADDR(base) ((base) + (0x0020UL))
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_ADDR(base) ((base) + (0x0800UL))
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGCTL_ADDR(base) ((base) + (0x0808UL))
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGCDN_ADDR(base) ((base) + (0x0810UL))
#else
#define SOC_L3cache_RAS_NAMTSORAS_ERR0FR_ADDR(base) ((base) + (0x0000))
#define SOC_L3cache_RAS_NAMTSORAS_ERR0CTLR_ADDR(base) ((base) + (0x0008))
#define SOC_L3cache_RAS_NAMTSORAS_ERR0STATUS_ADDR(base) ((base) + (0x0010))
#define SOC_L3cache_RAS_NAMTSORAS_ERR0MISC0_ADDR(base) ((base) + (0x0020))
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_ADDR(base) ((base) + (0x0800))
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGCTL_ADDR(base) ((base) + (0x0808))
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGCDN_ADDR(base) ((base) + (0x0810))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long ed : 2;
        unsigned long long de : 2;
        unsigned long long ui : 2;
        unsigned long long fi : 2;
        unsigned long long ue : 2;
        unsigned long long cfi : 2;
        unsigned long long cec : 3;
        unsigned long long rp : 1;
        unsigned long long dui : 2;
        unsigned long long ceo : 2;
        unsigned long long inj : 2;
        unsigned long long ci : 2;
        unsigned long long ts : 2;
        unsigned long long reserved_0: 6;
        unsigned long long reserved_1: 32;
    } reg;
} SOC_L3cache_RAS_NAMTSORAS_ERR0FR_UNION;
#endif
#define SOC_L3cache_RAS_NAMTSORAS_ERR0FR_ed_START (0)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0FR_ed_END (1)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0FR_de_START (2)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0FR_de_END (3)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0FR_ui_START (4)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0FR_ui_END (5)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0FR_fi_START (6)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0FR_fi_END (7)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0FR_ue_START (8)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0FR_ue_END (9)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0FR_cfi_START (10)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0FR_cfi_END (11)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0FR_cec_START (12)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0FR_cec_END (14)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0FR_rp_START (15)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0FR_rp_END (15)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0FR_dui_START (16)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0FR_dui_END (17)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0FR_ceo_START (18)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0FR_ceo_END (19)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0FR_inj_START (20)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0FR_inj_END (21)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0FR_ci_START (22)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0FR_ci_END (23)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0FR_ts_START (24)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0FR_ts_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long ed : 1;
        unsigned long long reserved_0: 1;
        unsigned long long ui : 1;
        unsigned long long fi : 1;
        unsigned long long reserved_1: 4;
        unsigned long long cfi : 1;
        unsigned long long reserved_2: 23;
        unsigned long long reserved_3: 32;
    } reg;
} SOC_L3cache_RAS_NAMTSORAS_ERR0CTLR_UNION;
#endif
#define SOC_L3cache_RAS_NAMTSORAS_ERR0CTLR_ed_START (0)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0CTLR_ed_END (0)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0CTLR_ui_START (2)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0CTLR_ui_END (2)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0CTLR_fi_START (3)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0CTLR_fi_END (3)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0CTLR_cfi_START (8)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0CTLR_cfi_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long serr : 8;
        unsigned long long ierr : 8;
        unsigned long long res0 : 6;
        unsigned long long pn : 1;
        unsigned long long de : 1;
        unsigned long long ce : 2;
        unsigned long long mv : 1;
        unsigned long long of : 1;
        unsigned long long er : 1;
        unsigned long long ue : 1;
        unsigned long long v : 1;
        unsigned long long av : 1;
        unsigned long long reserved : 32;
    } reg;
} SOC_L3cache_RAS_NAMTSORAS_ERR0STATUS_UNION;
#endif
#define SOC_L3cache_RAS_NAMTSORAS_ERR0STATUS_serr_START (0)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0STATUS_serr_END (7)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0STATUS_ierr_START (8)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0STATUS_ierr_END (15)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0STATUS_res0_START (16)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0STATUS_res0_END (21)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0STATUS_pn_START (22)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0STATUS_pn_END (22)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0STATUS_de_START (23)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0STATUS_de_END (23)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0STATUS_ce_START (24)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0STATUS_ce_END (25)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0STATUS_mv_START (26)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0STATUS_mv_END (26)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0STATUS_of_START (27)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0STATUS_of_END (27)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0STATUS_er_START (28)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0STATUS_er_END (28)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0STATUS_ue_START (29)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0STATUS_ue_END (29)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0STATUS_v_START (30)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0STATUS_v_END (30)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0STATUS_av_START (31)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0STATUS_av_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long ind : 1;
        unsigned long long lvl : 3;
        unsigned long long res0 : 2;
        unsigned long long indx : 18;
        unsigned long long res1 : 3;
        unsigned long long way : 5;
        unsigned long long cecr : 7;
        unsigned long long ofr : 1;
        unsigned long long ceco : 7;
        unsigned long long ofo : 1;
        unsigned long long reserved : 16;
    } reg;
} SOC_L3cache_RAS_NAMTSORAS_ERR0MISC0_UNION;
#endif
#define SOC_L3cache_RAS_NAMTSORAS_ERR0MISC0_ind_START (0)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0MISC0_ind_END (0)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0MISC0_lvl_START (1)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0MISC0_lvl_END (3)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0MISC0_res0_START (4)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0MISC0_res0_END (5)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0MISC0_indx_START (6)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0MISC0_indx_END (23)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0MISC0_res1_START (24)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0MISC0_res1_END (26)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0MISC0_way_START (27)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0MISC0_way_END (31)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0MISC0_cecr_START (32)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0MISC0_cecr_END (38)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0MISC0_ofr_START (39)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0MISC0_ofr_END (39)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0MISC0_ceco_START (40)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0MISC0_ceco_END (46)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0MISC0_ofo_START (47)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0MISC0_ofo_END (47)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long of : 1;
        unsigned long long uc : 1;
        unsigned long long ueu : 1;
        unsigned long long uer : 1;
        unsigned long long ueo : 1;
        unsigned long long de : 1;
        unsigned long long ce : 2;
        unsigned long long ci : 1;
        unsigned long long er : 1;
        unsigned long long pn : 1;
        unsigned long long av : 1;
        unsigned long long mv : 1;
        unsigned long long reserved_0: 16;
        unsigned long long syn : 1;
        unsigned long long r : 1;
        unsigned long long reserved_1: 33;
    } reg;
} SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_UNION;
#endif
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_of_START (0)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_of_END (0)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_uc_START (1)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_uc_END (1)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_ueu_START (2)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_ueu_END (2)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_uer_START (3)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_uer_END (3)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_ueo_START (4)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_ueo_END (4)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_de_START (5)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_de_END (5)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_ce_START (6)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_ce_END (7)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_ci_START (8)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_ci_END (8)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_er_START (9)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_er_END (9)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_pn_START (10)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_pn_END (10)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_av_START (11)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_av_END (11)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_mv_START (12)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_mv_END (12)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_syn_START (29)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_syn_END (29)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_r_START (30)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGF_r_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long reserved_0: 1;
        unsigned long long uc : 1;
        unsigned long long reserved_1: 3;
        unsigned long long de : 1;
        unsigned long long ce : 1;
        unsigned long long reserved_2: 23;
        unsigned long long r : 1;
        unsigned long long cdnen : 1;
        unsigned long long reserved_3: 32;
    } reg;
} SOC_L3cache_RAS_NAMTSORAS_ERR0PFGCTL_UNION;
#endif
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGCTL_uc_START (1)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGCTL_uc_END (1)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGCTL_de_START (5)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGCTL_de_END (5)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGCTL_ce_START (6)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGCTL_ce_END (6)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGCTL_r_START (30)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGCTL_r_END (30)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGCTL_cdnen_START (31)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGCTL_cdnen_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long cdn : 32;
        unsigned long long reserved : 32;
    } reg;
} SOC_L3cache_RAS_NAMTSORAS_ERR0PFGCDN_UNION;
#endif
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGCDN_cdn_START (0)
#define SOC_L3cache_RAS_NAMTSORAS_ERR0PFGCDN_cdn_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
