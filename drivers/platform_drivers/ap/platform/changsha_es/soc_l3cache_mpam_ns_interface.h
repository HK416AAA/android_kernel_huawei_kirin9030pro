#ifndef __SOC_L3CACHE_MPAM_NS_INTERFACE_H__
#define __SOC_L3CACHE_MPAM_NS_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IDR_NS_ADDR(base) ((base) + (0x0000UL))
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_SIDR_NS_ADDR(base) ((base) + (0x0008UL))
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IIDR_NS_ADDR(base) ((base) + (0x0018UL))
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_AIDR_NS_ADDR(base) ((base) + (0x0020UL))
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_CPOR_IDR_NS_ADDR(base) ((base) + (0x0030UL))
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_MSMON_IDR_NS_ADDR(base) ((base) + (0x0080UL))
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_CSUMON_IDR_NS_ADDR(base) ((base) + (0x0088UL))
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_MBWUMON_IDR_NS_ADDR(base) ((base) + (0x0090UL))
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_PART_SEL_NS_ADDR(base) ((base) + (0x0100UL))
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MON_SEL_NS_ADDR(base) ((base) + (0x0800UL))
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CAPT_EVNT_NS_ADDR(base) ((base) + (0x0808UL))
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_FLT_NS_ADDR(base) ((base) + (0x0810UL))
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_CTL_NS_ADDR(base) ((base) + (0x0818UL))
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_FLT_NS_ADDR(base) ((base) + (0x0820UL))
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_ADDR(base) ((base) + (0x0828UL))
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CSU_NS_ADDR(base) ((base) + (0x0840UL))
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CSU_CAPTURE_NS_ADDR(base) ((base) + (0x0848UL))
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_MBWU_NS_ADDR(base) ((base) + (0x0860UL))
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_MBWU_CAPTURE_NS_ADDR(base) ((base) + (0x0868UL))
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_CPBM_NS_ADDR(base) ((base) + (0x1000UL))
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_ALLOC_NS_ADDR(base) ((base) + (0x3000UL))
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_CPBM_NS_ADDR(base) ((base) + (0x4000UL))
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAM_OW_EL3_ADDR(base) ((base) + (NAUL))
#else
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IDR_NS_ADDR(base) ((base) + (0x0000))
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_SIDR_NS_ADDR(base) ((base) + (0x0008))
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IIDR_NS_ADDR(base) ((base) + (0x0018))
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_AIDR_NS_ADDR(base) ((base) + (0x0020))
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_CPOR_IDR_NS_ADDR(base) ((base) + (0x0030))
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_MSMON_IDR_NS_ADDR(base) ((base) + (0x0080))
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_CSUMON_IDR_NS_ADDR(base) ((base) + (0x0088))
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_MBWUMON_IDR_NS_ADDR(base) ((base) + (0x0090))
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_PART_SEL_NS_ADDR(base) ((base) + (0x0100))
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MON_SEL_NS_ADDR(base) ((base) + (0x0800))
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CAPT_EVNT_NS_ADDR(base) ((base) + (0x0808))
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_FLT_NS_ADDR(base) ((base) + (0x0810))
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_CTL_NS_ADDR(base) ((base) + (0x0818))
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_FLT_NS_ADDR(base) ((base) + (0x0820))
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_ADDR(base) ((base) + (0x0828))
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CSU_NS_ADDR(base) ((base) + (0x0840))
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CSU_CAPTURE_NS_ADDR(base) ((base) + (0x0848))
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_MBWU_NS_ADDR(base) ((base) + (0x0860))
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_MBWU_CAPTURE_NS_ADDR(base) ((base) + (0x0868))
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_CPBM_NS_ADDR(base) ((base) + (0x1000))
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_ALLOC_NS_ADDR(base) ((base) + (0x3000))
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_CPBM_NS_ADDR(base) ((base) + (0x4000))
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAM_OW_EL3_ADDR(base) ((base) + (NA))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int partid_max : 16;
        unsigned int pmg_max : 8;
        unsigned int has_ccap_part : 1;
        unsigned int has_cpor_part : 1;
        unsigned int has_mbw_part : 1;
        unsigned int has_pri_part : 1;
        unsigned int ext : 1;
        unsigned int has_impl_idr : 1;
        unsigned int has_msmon : 1;
        unsigned int has_partid_nrw : 1;
    } reg;
} SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IDR_NS_UNION;
#endif
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IDR_NS_partid_max_START (0)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IDR_NS_partid_max_END (15)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IDR_NS_pmg_max_START (16)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IDR_NS_pmg_max_END (23)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IDR_NS_has_ccap_part_START (24)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IDR_NS_has_ccap_part_END (24)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IDR_NS_has_cpor_part_START (25)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IDR_NS_has_cpor_part_END (25)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IDR_NS_has_mbw_part_START (26)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IDR_NS_has_mbw_part_END (26)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IDR_NS_has_pri_part_START (27)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IDR_NS_has_pri_part_END (27)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IDR_NS_ext_START (28)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IDR_NS_ext_END (28)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IDR_NS_has_impl_idr_START (29)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IDR_NS_has_impl_idr_END (29)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IDR_NS_has_msmon_START (30)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IDR_NS_has_msmon_END (30)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IDR_NS_has_partid_nrw_START (31)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IDR_NS_has_partid_nrw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int s_partid_max : 16;
        unsigned int s_pmg_max : 8;
        unsigned int res0 : 8;
    } reg;
} SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_SIDR_NS_UNION;
#endif
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_SIDR_NS_s_partid_max_START (0)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_SIDR_NS_s_partid_max_END (15)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_SIDR_NS_s_pmg_max_START (16)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_SIDR_NS_s_pmg_max_END (23)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_SIDR_NS_res0_START (24)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_SIDR_NS_res0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int implementer : 12;
        unsigned int revision : 4;
        unsigned int variant : 4;
        unsigned int productid : 12;
    } reg;
} SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IIDR_NS_UNION;
#endif
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IIDR_NS_implementer_START (0)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IIDR_NS_implementer_END (11)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IIDR_NS_revision_START (12)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IIDR_NS_revision_END (15)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IIDR_NS_variant_START (16)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IIDR_NS_variant_END (19)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IIDR_NS_productid_START (20)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_IIDR_NS_productid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int archminorrev : 4;
        unsigned int archmajorrev : 4;
        unsigned int res0 : 24;
    } reg;
} SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_AIDR_NS_UNION;
#endif
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_AIDR_NS_archminorrev_START (0)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_AIDR_NS_archminorrev_END (3)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_AIDR_NS_archmajorrev_START (4)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_AIDR_NS_archmajorrev_END (7)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_AIDR_NS_res0_START (8)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_AIDR_NS_res0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cpbm_wd : 16;
        unsigned int res0 : 16;
    } reg;
} SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_CPOR_IDR_NS_UNION;
#endif
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_CPOR_IDR_NS_cpbm_wd_START (0)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_CPOR_IDR_NS_cpbm_wd_END (15)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_CPOR_IDR_NS_res0_START (16)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_CPOR_IDR_NS_res0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int res0 : 16;
        unsigned int msmon_csu : 1;
        unsigned int msmon_mbwu : 1;
        unsigned int res1 : 13;
        unsigned int has_local_capt_evnt : 1;
    } reg;
} SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_MSMON_IDR_NS_UNION;
#endif
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_MSMON_IDR_NS_res0_START (0)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_MSMON_IDR_NS_res0_END (15)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_MSMON_IDR_NS_msmon_csu_START (16)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_MSMON_IDR_NS_msmon_csu_END (16)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_MSMON_IDR_NS_msmon_mbwu_START (17)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_MSMON_IDR_NS_msmon_mbwu_END (17)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_MSMON_IDR_NS_res1_START (18)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_MSMON_IDR_NS_res1_END (30)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_MSMON_IDR_NS_has_local_capt_evnt_START (31)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_MSMON_IDR_NS_has_local_capt_evnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int num_mon : 16;
        unsigned int res0 : 15;
        unsigned int has_capture : 1;
    } reg;
} SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_CSUMON_IDR_NS_UNION;
#endif
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_CSUMON_IDR_NS_num_mon_START (0)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_CSUMON_IDR_NS_num_mon_END (15)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_CSUMON_IDR_NS_res0_START (16)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_CSUMON_IDR_NS_res0_END (30)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_CSUMON_IDR_NS_has_capture_START (31)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_CSUMON_IDR_NS_has_capture_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int num_mon : 16;
        unsigned int scale : 5;
        unsigned int res0 : 8;
        unsigned int lwd : 1;
        unsigned int has_long : 1;
        unsigned int has_capture : 1;
    } reg;
} SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_MBWUMON_IDR_NS_UNION;
#endif
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_MBWUMON_IDR_NS_num_mon_START (0)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_MBWUMON_IDR_NS_num_mon_END (15)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_MBWUMON_IDR_NS_scale_START (16)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_MBWUMON_IDR_NS_scale_END (20)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_MBWUMON_IDR_NS_res0_START (21)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_MBWUMON_IDR_NS_res0_END (28)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_MBWUMON_IDR_NS_lwd_START (29)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_MBWUMON_IDR_NS_lwd_END (29)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_MBWUMON_IDR_NS_has_long_START (30)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_MBWUMON_IDR_NS_has_long_END (30)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_MBWUMON_IDR_NS_has_capture_START (31)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMF_MBWUMON_IDR_NS_has_capture_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int partid_sel : 16;
        unsigned int internal : 1;
        unsigned int res0 : 15;
    } reg;
} SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_PART_SEL_NS_UNION;
#endif
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_PART_SEL_NS_partid_sel_START (0)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_PART_SEL_NS_partid_sel_END (15)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_PART_SEL_NS_internal_START (16)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_PART_SEL_NS_internal_END (16)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_PART_SEL_NS_res0_START (17)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_PART_SEL_NS_res0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mon_sel : 16;
        unsigned int res0 : 8;
        unsigned int Ris : 4;
        unsigned int res1 : 4;
    } reg;
} SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MON_SEL_NS_UNION;
#endif
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MON_SEL_NS_mon_sel_START (0)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MON_SEL_NS_mon_sel_END (15)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MON_SEL_NS_res0_START (16)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MON_SEL_NS_res0_END (23)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MON_SEL_NS_Ris_START (24)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MON_SEL_NS_Ris_END (27)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MON_SEL_NS_res1_START (28)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MON_SEL_NS_res1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int now : 1;
        unsigned int all : 1;
        unsigned int res0 : 30;
    } reg;
} SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CAPT_EVNT_NS_UNION;
#endif
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CAPT_EVNT_NS_now_START (0)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CAPT_EVNT_NS_now_END (0)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CAPT_EVNT_NS_all_START (1)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CAPT_EVNT_NS_all_END (1)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CAPT_EVNT_NS_res0_START (2)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CAPT_EVNT_NS_res0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int partid : 16;
        unsigned int pmg : 8;
        unsigned int res0 : 8;
    } reg;
} SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_FLT_NS_UNION;
#endif
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_FLT_NS_partid_START (0)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_FLT_NS_partid_END (15)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_FLT_NS_pmg_START (16)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_FLT_NS_pmg_END (23)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_FLT_NS_res0_START (24)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_FLT_NS_res0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int type : 8;
        unsigned int res0 : 8;
        unsigned int match_partid : 1;
        unsigned int match_pmg : 1;
        unsigned int res1 : 1;
        unsigned int res2 : 1;
        unsigned int subtype : 4;
        unsigned int oflow_frz : 1;
        unsigned int oflow_intr : 1;
        unsigned int oflow_status : 1;
        unsigned int capt_reset : 1;
        unsigned int capt_evnt : 3;
        unsigned int en : 1;
    } reg;
} SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_CTL_NS_UNION;
#endif
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_CTL_NS_type_START (0)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_CTL_NS_type_END (7)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_CTL_NS_res0_START (8)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_CTL_NS_res0_END (15)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_CTL_NS_match_partid_START (16)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_CTL_NS_match_partid_END (16)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_CTL_NS_match_pmg_START (17)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_CTL_NS_match_pmg_END (17)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_CTL_NS_res1_START (18)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_CTL_NS_res1_END (18)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_CTL_NS_res2_START (19)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_CTL_NS_res2_END (19)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_CTL_NS_subtype_START (20)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_CTL_NS_subtype_END (23)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_CTL_NS_oflow_frz_START (24)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_CTL_NS_oflow_frz_END (24)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_CTL_NS_oflow_intr_START (25)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_CTL_NS_oflow_intr_END (25)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_CTL_NS_oflow_status_START (26)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_CTL_NS_oflow_status_END (26)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_CTL_NS_capt_reset_START (27)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_CTL_NS_capt_reset_END (27)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_CTL_NS_capt_evnt_START (28)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_CTL_NS_capt_evnt_END (30)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_CTL_NS_en_START (31)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_CSU_CTL_NS_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int partid : 16;
        unsigned int pmg : 8;
        unsigned int res0 : 8;
    } reg;
} SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_FLT_NS_UNION;
#endif
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_FLT_NS_partid_START (0)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_FLT_NS_partid_END (15)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_FLT_NS_pmg_START (16)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_FLT_NS_pmg_END (23)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_FLT_NS_res0_START (24)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_FLT_NS_res0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int type : 8;
        unsigned int res0 : 6;
        unsigned int oflow_intr_L : 1;
        unsigned int oflow_status_L : 1;
        unsigned int match_partid : 1;
        unsigned int match_pmg : 1;
        unsigned int res1 : 1;
        unsigned int sclen : 1;
        unsigned int subtype : 4;
        unsigned int oflow_frz : 1;
        unsigned int oflow_intr : 1;
        unsigned int oflow_status : 1;
        unsigned int capt_reset : 1;
        unsigned int capt_evnt : 3;
        unsigned int en : 1;
    } reg;
} SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_UNION;
#endif
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_type_START (0)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_type_END (7)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_res0_START (8)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_res0_END (13)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_oflow_intr_L_START (14)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_oflow_intr_L_END (14)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_oflow_status_L_START (15)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_oflow_status_L_END (15)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_match_partid_START (16)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_match_partid_END (16)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_match_pmg_START (17)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_match_pmg_END (17)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_res1_START (18)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_res1_END (18)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_sclen_START (19)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_sclen_END (19)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_subtype_START (20)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_subtype_END (23)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_oflow_frz_START (24)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_oflow_frz_END (24)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_oflow_intr_START (25)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_oflow_intr_END (25)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_oflow_status_START (26)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_oflow_status_END (26)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_capt_reset_START (27)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_capt_reset_END (27)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_capt_evnt_START (28)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_capt_evnt_END (30)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_en_START (31)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CFG_MBWU_CTL_NS_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int value : 30;
        unsigned int sign_bit : 1;
        unsigned int nrdy : 1;
    } reg;
} SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CSU_NS_UNION;
#endif
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CSU_NS_value_START (0)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CSU_NS_value_END (29)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CSU_NS_sign_bit_START (30)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CSU_NS_sign_bit_END (30)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CSU_NS_nrdy_START (31)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CSU_NS_nrdy_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int value : 31;
        unsigned int nrdy : 1;
    } reg;
} SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CSU_CAPTURE_NS_UNION;
#endif
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CSU_CAPTURE_NS_value_START (0)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CSU_CAPTURE_NS_value_END (30)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CSU_CAPTURE_NS_nrdy_START (31)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_CSU_CAPTURE_NS_nrdy_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int value : 31;
        unsigned int nrdy : 1;
    } reg;
} SOC_L3cache_MPAM_NS_NAMTSO_MSMON_MBWU_NS_UNION;
#endif
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_MBWU_NS_value_START (0)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_MBWU_NS_value_END (30)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_MBWU_NS_nrdy_START (31)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_MBWU_NS_nrdy_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int value : 31;
        unsigned int nrdy : 1;
    } reg;
} SOC_L3cache_MPAM_NS_NAMTSO_MSMON_MBWU_CAPTURE_NS_UNION;
#endif
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_MBWU_CAPTURE_NS_value_START (0)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_MBWU_CAPTURE_NS_value_END (30)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_MBWU_CAPTURE_NS_nrdy_START (31)
#define SOC_L3cache_MPAM_NS_NAMTSO_MSMON_MBWU_CAPTURE_NS_nrdy_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cpbm0 : 1;
        unsigned int cpbm1 : 1;
        unsigned int cpbm2 : 1;
        unsigned int cpbm3 : 1;
        unsigned int cpbm4 : 1;
        unsigned int cpbm5 : 1;
        unsigned int cpbm6 : 1;
        unsigned int cpbm7 : 1;
        unsigned int cpbm8 : 1;
        unsigned int cpbm9 : 1;
        unsigned int cpbm10 : 1;
        unsigned int cpbm11 : 1;
        unsigned int raz_wi : 20;
    } reg;
} SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_CPBM_NS_UNION;
#endif
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_CPBM_NS_cpbm0_START (0)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_CPBM_NS_cpbm0_END (0)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_CPBM_NS_cpbm1_START (1)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_CPBM_NS_cpbm1_END (1)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_CPBM_NS_cpbm2_START (2)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_CPBM_NS_cpbm2_END (2)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_CPBM_NS_cpbm3_START (3)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_CPBM_NS_cpbm3_END (3)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_CPBM_NS_cpbm4_START (4)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_CPBM_NS_cpbm4_END (4)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_CPBM_NS_cpbm5_START (5)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_CPBM_NS_cpbm5_END (5)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_CPBM_NS_cpbm6_START (6)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_CPBM_NS_cpbm6_END (6)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_CPBM_NS_cpbm7_START (7)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_CPBM_NS_cpbm7_END (7)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_CPBM_NS_cpbm8_START (8)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_CPBM_NS_cpbm8_END (8)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_CPBM_NS_cpbm9_START (9)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_CPBM_NS_cpbm9_END (9)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_CPBM_NS_cpbm10_START (10)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_CPBM_NS_cpbm10_END (10)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_CPBM_NS_cpbm11_START (11)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_CPBM_NS_cpbm11_END (11)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_CPBM_NS_raz_wi_START (12)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_CPBM_NS_raz_wi_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bib_alloc_partid : 4;
        unsigned int res0 : 28;
    } reg;
} SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_ALLOC_NS_UNION;
#endif
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_ALLOC_NS_bib_alloc_partid_START (0)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_ALLOC_NS_bib_alloc_partid_END (3)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_ALLOC_NS_res0_START (4)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_ALLOC_NS_res0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bib_cpbm0 : 1;
        unsigned int bib_cpbm1 : 1;
        unsigned int bib_cpbm2 : 1;
        unsigned int bib_cpbm3 : 1;
        unsigned int bib_cpbm4 : 1;
        unsigned int bib_cpbm5 : 1;
        unsigned int bib_cpbm6 : 1;
        unsigned int bib_cpbm7 : 1;
        unsigned int bib_cpbm8 : 1;
        unsigned int bib_cpbm9 : 1;
        unsigned int bib_cpbm10 : 1;
        unsigned int bib_cpbm11 : 1;
        unsigned int res0 : 20;
    } reg;
} SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_CPBM_NS_UNION;
#endif
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_CPBM_NS_bib_cpbm0_START (0)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_CPBM_NS_bib_cpbm0_END (0)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_CPBM_NS_bib_cpbm1_START (1)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_CPBM_NS_bib_cpbm1_END (1)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_CPBM_NS_bib_cpbm2_START (2)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_CPBM_NS_bib_cpbm2_END (2)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_CPBM_NS_bib_cpbm3_START (3)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_CPBM_NS_bib_cpbm3_END (3)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_CPBM_NS_bib_cpbm4_START (4)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_CPBM_NS_bib_cpbm4_END (4)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_CPBM_NS_bib_cpbm5_START (5)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_CPBM_NS_bib_cpbm5_END (5)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_CPBM_NS_bib_cpbm6_START (6)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_CPBM_NS_bib_cpbm6_END (6)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_CPBM_NS_bib_cpbm7_START (7)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_CPBM_NS_bib_cpbm7_END (7)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_CPBM_NS_bib_cpbm8_START (8)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_CPBM_NS_bib_cpbm8_END (8)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_CPBM_NS_bib_cpbm9_START (9)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_CPBM_NS_bib_cpbm9_END (9)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_CPBM_NS_bib_cpbm10_START (10)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_CPBM_NS_bib_cpbm10_END (10)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_CPBM_NS_bib_cpbm11_START (11)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_CPBM_NS_bib_cpbm11_END (11)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_CPBM_NS_res0_START (12)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAMCFG_BIB_CPBM_NS_res0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned long long value;
    struct
    {
        unsigned long long implementer : 12;
        unsigned long long revision : 4;
        unsigned long long variant : 4;
        unsigned long long productid : 12;
        unsigned long long wr_en : 1;
        unsigned long long res0 : 31;
    } reg;
} SOC_L3cache_MPAM_NS_NAMTSO_MPAM_OW_EL3_UNION;
#endif
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAM_OW_EL3_implementer_START (0)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAM_OW_EL3_implementer_END (11)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAM_OW_EL3_revision_START (12)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAM_OW_EL3_revision_END (15)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAM_OW_EL3_variant_START (16)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAM_OW_EL3_variant_END (19)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAM_OW_EL3_productid_START (20)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAM_OW_EL3_productid_END (31)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAM_OW_EL3_wr_en_START (32)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAM_OW_EL3_wr_en_END (32)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAM_OW_EL3_res0_START (33)
#define SOC_L3cache_MPAM_NS_NAMTSO_MPAM_OW_EL3_res0_END (63)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
