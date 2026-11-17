#ifndef __SOC_FCM_LOCAL_MID_CORE_INTERFACE_H__
#define __SOC_FCM_LOCAL_MID_CORE_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL0_ADDR(base) ((base) + (0x800UL))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL1_ADDR(base) ((base) + (0x804UL))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL2_ADDR(base) ((base) + (0x808UL))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL3_ADDR(base) ((base) + (0x80cUL))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL4_ADDR(base) ((base) + (0x810UL))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL5_ADDR(base) ((base) + (0x814UL))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL6_ADDR(base) ((base) + (0x818UL))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL7_ADDR(base) ((base) + (0x81cUL))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL8_ADDR(base) ((base) + (0x820UL))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL9_ADDR(base) ((base) + (0x824UL))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL10_ADDR(base) ((base) + (0x828UL))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL11_ADDR(base) ((base) + (0x82cUL))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL12_ADDR(base) ((base) + (0x830UL))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL16_ADDR(base) ((base) + (0x0840UL))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EN_CFG_REG_ADDR(base) ((base) + (0x878UL))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_GLB_CTL_REG_ADDR(base) ((base) + (0x87CUL))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT0_CTL_REG_ADDR(base) ((base) + (0x880UL))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT1_CTL_REG_ADDR(base) ((base) + (0x884UL))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT2_CTL_REG_ADDR(base) ((base) + (0x888UL))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT3_CTL_REG_ADDR(base) ((base) + (0x88CUL))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT4_CTL_REG_ADDR(base) ((base) + (0x890UL))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT5_CTL_REG_ADDR(base) ((base) + (0x894UL))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT6_CTL_REG_ADDR(base) ((base) + (0x898UL))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT7_CTL_REG_ADDR(base) ((base) + (0x89CUL))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT8_CTL_REG_ADDR(base) ((base) + (0x8A0UL))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT9_CTL_REG_ADDR(base) ((base) + (0x8A4UL))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT10_CTL_REG_ADDR(base) ((base) + (0x8A8UL))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT11_CTL_REG_ADDR(base) ((base) + (0x8ACUL))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT12_CTL_REG_ADDR(base) ((base) + (0x8B0UL))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT13_CTL_REG_ADDR(base) ((base) + (0x8B4UL))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT14_CTL_REG_ADDR(base) ((base) + (0x8B8UL))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT15_CTL_REG_ADDR(base) ((base) + (0x8BCUL))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT0_ADDR(base) ((base) + (0xC00UL))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT1_ADDR(base) ((base) + (0xC04UL))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT2_ADDR(base) ((base) + (0xC08UL))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT3_ADDR(base) ((base) + (0xC0CUL))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT4_ADDR(base) ((base) + (0xC10UL))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT5_ADDR(base) ((base) + (0xC14UL))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT6_ADDR(base) ((base) + (0xC18UL))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT7_ADDR(base) ((base) + (0xC1CUL))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT8_ADDR(base) ((base) + (0xC20UL))
#else
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL0_ADDR(base) ((base) + (0x800))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL1_ADDR(base) ((base) + (0x804))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL2_ADDR(base) ((base) + (0x808))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL3_ADDR(base) ((base) + (0x80c))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL4_ADDR(base) ((base) + (0x810))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL5_ADDR(base) ((base) + (0x814))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL6_ADDR(base) ((base) + (0x818))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL7_ADDR(base) ((base) + (0x81c))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL8_ADDR(base) ((base) + (0x820))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL9_ADDR(base) ((base) + (0x824))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL10_ADDR(base) ((base) + (0x828))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL11_ADDR(base) ((base) + (0x82c))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL12_ADDR(base) ((base) + (0x830))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL16_ADDR(base) ((base) + (0x0840))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EN_CFG_REG_ADDR(base) ((base) + (0x878))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_GLB_CTL_REG_ADDR(base) ((base) + (0x87C))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT0_CTL_REG_ADDR(base) ((base) + (0x880))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT1_CTL_REG_ADDR(base) ((base) + (0x884))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT2_CTL_REG_ADDR(base) ((base) + (0x888))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT3_CTL_REG_ADDR(base) ((base) + (0x88C))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT4_CTL_REG_ADDR(base) ((base) + (0x890))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT5_CTL_REG_ADDR(base) ((base) + (0x894))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT6_CTL_REG_ADDR(base) ((base) + (0x898))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT7_CTL_REG_ADDR(base) ((base) + (0x89C))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT8_CTL_REG_ADDR(base) ((base) + (0x8A0))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT9_CTL_REG_ADDR(base) ((base) + (0x8A4))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT10_CTL_REG_ADDR(base) ((base) + (0x8A8))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT11_CTL_REG_ADDR(base) ((base) + (0x8AC))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT12_CTL_REG_ADDR(base) ((base) + (0x8B0))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT13_CTL_REG_ADDR(base) ((base) + (0x8B4))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT14_CTL_REG_ADDR(base) ((base) + (0x8B8))
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT15_CTL_REG_ADDR(base) ((base) + (0x8BC))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT0_ADDR(base) ((base) + (0xC00))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT1_ADDR(base) ((base) + (0xC04))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT2_ADDR(base) ((base) + (0xC08))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT3_ADDR(base) ((base) + (0xC0C))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT4_ADDR(base) ((base) + (0xC10))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT5_ADDR(base) ((base) + (0xC14))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT6_ADDR(base) ((base) + (0xC18))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT7_ADDR(base) ((base) + (0xC1C))
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT8_ADDR(base) ((base) + (0xC20))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtm_event_cnt_en : 18;
        unsigned int reserved : 11;
        unsigned int sel_dpm_src : 1;
        unsigned int rtm_glb_en : 1;
        unsigned int fvt_glb_en : 1;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL0_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL0_rtm_event_cnt_en_START (0)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL0_rtm_event_cnt_en_END (17)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL0_sel_dpm_src_START (29)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL0_sel_dpm_src_END (29)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL0_rtm_glb_en_START (30)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL0_rtm_glb_en_END (30)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL0_fvt_glb_en_START (31)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL0_fvt_glb_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtm_cnt_en : 19;
        unsigned int reserved : 13;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL1_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL1_rtm_cnt_en_START (0)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL1_rtm_cnt_en_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fvt_event_sel0 : 3;
        unsigned int fvt_event_sel1 : 3;
        unsigned int reserved_0 : 4;
        unsigned int fvt_event_cnt_en : 10;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL2_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL2_fvt_event_sel0_START (0)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL2_fvt_event_sel0_END (2)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL2_fvt_event_sel1_START (3)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL2_fvt_event_sel1_END (5)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL2_fvt_event_cnt_en_START (10)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL2_fvt_event_cnt_en_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int thread_or_core_sel_thread0 : 1;
        unsigned int reserved_1 : 9;
        unsigned int thread_or_core_sel_thread1 : 1;
        unsigned int reserved_2 : 20;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL3_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL3_thread_or_core_sel_thread0_START (1)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL3_thread_or_core_sel_thread0_END (1)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL3_thread_or_core_sel_thread1_START (11)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL3_thread_or_core_sel_thread1_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fvt_ovr_info_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL4_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL4_fvt_ovr_info_clr_START (0)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL4_fvt_ovr_info_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtm_ovr_info_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL5_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL5_rtm_ovr_info_clr_START (0)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL5_rtm_ovr_info_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pi_cfg_extend_cnt : 16;
        unsigned int pi_cfg_cycle_low : 6;
        unsigned int pi_cfg_cycle_high : 6;
        unsigned int reserved : 4;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL6_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL6_pi_cfg_extend_cnt_START (0)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL6_pi_cfg_extend_cnt_END (15)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL6_pi_cfg_cycle_low_START (16)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL6_pi_cfg_cycle_low_END (21)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL6_pi_cfg_cycle_high_START (22)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL6_pi_cfg_cycle_high_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_cfg_extend_cnt : 16;
        unsigned int flux_cfg_cycle_low : 6;
        unsigned int flux_cfg_cycle_high : 6;
        unsigned int reserved : 4;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL7_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL7_flux_cfg_extend_cnt_START (0)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL7_flux_cfg_extend_cnt_END (15)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL7_flux_cfg_cycle_low_START (16)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL7_flux_cfg_cycle_low_END (21)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL7_flux_cfg_cycle_high_START (22)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL7_flux_cfg_cycle_high_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_cpm_dop_en : 1;
        unsigned int mask_ctl0 : 1;
        unsigned int mask_ctl1 : 1;
        unsigned int mask_ctl2 : 1;
        unsigned int reserved_0 : 4;
        unsigned int core_flux_req_evt_th : 8;
        unsigned int reserved_1 : 2;
        unsigned int core_flux_req_win : 8;
        unsigned int reserved_2 : 2;
        unsigned int bypass_flushreq_win : 1;
        unsigned int core_flux_req_win_en : 1;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL8_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL8_gt_cpm_dop_en_START (0)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL8_gt_cpm_dop_en_END (0)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL8_mask_ctl0_START (1)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL8_mask_ctl0_END (1)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL8_mask_ctl1_START (2)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL8_mask_ctl1_END (2)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL8_mask_ctl2_START (3)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL8_mask_ctl2_END (3)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL8_core_flux_req_evt_th_START (8)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL8_core_flux_req_evt_th_END (15)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL8_core_flux_req_win_START (18)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL8_core_flux_req_win_END (25)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL8_bypass_flushreq_win_START (28)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL8_bypass_flushreq_win_END (28)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL8_core_flux_req_win_en_START (29)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL8_core_flux_req_win_en_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL9_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL9_cfg_en_START (0)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL9_cfg_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tde_cfg_info : 32;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL10_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL10_tde_cfg_info_START (0)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL10_tde_cfg_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tde_cfg_rst : 1;
        unsigned int tde_cfg_vld : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL11_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL11_tde_cfg_rst_START (0)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL11_tde_cfg_rst_END (0)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL11_tde_cfg_vld_START (1)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL11_tde_cfg_vld_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clkoff_rtm : 1;
        unsigned int clkoff_fvt : 1;
        unsigned int clkoff_cpuload : 1;
        unsigned int reserved_0 : 13;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL12_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL12_clkoff_rtm_START (0)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL12_clkoff_rtm_END (0)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL12_clkoff_fvt_START (1)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL12_clkoff_fvt_END (1)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL12_clkoff_cpuload_START (2)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL12_clkoff_cpuload_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtm_event_22_28_mux_t0 : 1;
        unsigned int rtm_event_23_29_mux_t0 : 1;
        unsigned int rtm_event_24_30_mux_t0 : 1;
        unsigned int rtm_event_25_31_mux_t0 : 1;
        unsigned int rtm_event_22_28_mux_t1 : 1;
        unsigned int rtm_event_23_29_mux_t1 : 1;
        unsigned int rtm_event_24_30_mux_t1 : 1;
        unsigned int rtm_event_25_31_mux_t1 : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL16_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL16_rtm_event_22_28_mux_t0_START (0)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL16_rtm_event_22_28_mux_t0_END (0)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL16_rtm_event_23_29_mux_t0_START (1)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL16_rtm_event_23_29_mux_t0_END (1)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL16_rtm_event_24_30_mux_t0_START (2)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL16_rtm_event_24_30_mux_t0_END (2)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL16_rtm_event_25_31_mux_t0_START (3)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL16_rtm_event_25_31_mux_t0_END (3)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL16_rtm_event_22_28_mux_t1_START (4)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL16_rtm_event_22_28_mux_t1_END (4)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL16_rtm_event_23_29_mux_t1_START (5)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL16_rtm_event_23_29_mux_t1_END (5)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL16_rtm_event_24_30_mux_t1_START (6)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL16_rtm_event_24_30_mux_t1_END (6)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL16_rtm_event_25_31_mux_t1_START (7)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_CTRL16_rtm_event_25_31_mux_t1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cpu_load_event_en : 16;
        unsigned int enable_mask : 16;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EN_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EN_CFG_REG_cpu_load_event_en_START (0)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EN_CFG_REG_cpu_load_event_en_END (15)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EN_CFG_REG_enable_mask_START (16)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EN_CFG_REG_enable_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cpu_load_glb_ctl : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_GLB_CTL_REG_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_GLB_CTL_REG_cpu_load_glb_ctl_START (0)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_GLB_CTL_REG_cpu_load_glb_ctl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cpu_load_event_0_threshold : 6;
        unsigned int reserved_0 : 2;
        unsigned int cpu_load_event_0_win : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT0_CTL_REG_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT0_CTL_REG_cpu_load_event_0_threshold_START (0)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT0_CTL_REG_cpu_load_event_0_threshold_END (5)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT0_CTL_REG_cpu_load_event_0_win_START (8)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT0_CTL_REG_cpu_load_event_0_win_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cpu_load_event_1_threshold : 6;
        unsigned int reserved_0 : 2;
        unsigned int cpu_load_event_1_win : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT1_CTL_REG_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT1_CTL_REG_cpu_load_event_1_threshold_START (0)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT1_CTL_REG_cpu_load_event_1_threshold_END (5)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT1_CTL_REG_cpu_load_event_1_win_START (8)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT1_CTL_REG_cpu_load_event_1_win_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cpu_load_event_2_threshold : 6;
        unsigned int reserved_0 : 2;
        unsigned int cpu_load_event_2_win : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT2_CTL_REG_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT2_CTL_REG_cpu_load_event_2_threshold_START (0)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT2_CTL_REG_cpu_load_event_2_threshold_END (5)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT2_CTL_REG_cpu_load_event_2_win_START (8)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT2_CTL_REG_cpu_load_event_2_win_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cpu_load_event_3_threshold : 6;
        unsigned int reserved_0 : 2;
        unsigned int cpu_load_event_3_win : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT3_CTL_REG_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT3_CTL_REG_cpu_load_event_3_threshold_START (0)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT3_CTL_REG_cpu_load_event_3_threshold_END (5)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT3_CTL_REG_cpu_load_event_3_win_START (8)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT3_CTL_REG_cpu_load_event_3_win_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cpu_load_event_4_threshold : 6;
        unsigned int reserved_0 : 2;
        unsigned int cpu_load_event_4_win : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT4_CTL_REG_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT4_CTL_REG_cpu_load_event_4_threshold_START (0)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT4_CTL_REG_cpu_load_event_4_threshold_END (5)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT4_CTL_REG_cpu_load_event_4_win_START (8)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT4_CTL_REG_cpu_load_event_4_win_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cpu_load_event_5_threshold : 6;
        unsigned int reserved_0 : 2;
        unsigned int cpu_load_event_5_win : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT5_CTL_REG_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT5_CTL_REG_cpu_load_event_5_threshold_START (0)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT5_CTL_REG_cpu_load_event_5_threshold_END (5)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT5_CTL_REG_cpu_load_event_5_win_START (8)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT5_CTL_REG_cpu_load_event_5_win_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cpu_load_event_6_threshold : 6;
        unsigned int reserved_0 : 2;
        unsigned int cpu_load_event_6_win : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT6_CTL_REG_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT6_CTL_REG_cpu_load_event_6_threshold_START (0)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT6_CTL_REG_cpu_load_event_6_threshold_END (5)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT6_CTL_REG_cpu_load_event_6_win_START (8)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT6_CTL_REG_cpu_load_event_6_win_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cpu_load_event_7_threshold : 6;
        unsigned int reserved_0 : 2;
        unsigned int cpu_load_event_7_win : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT7_CTL_REG_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT7_CTL_REG_cpu_load_event_7_threshold_START (0)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT7_CTL_REG_cpu_load_event_7_threshold_END (5)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT7_CTL_REG_cpu_load_event_7_win_START (8)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT7_CTL_REG_cpu_load_event_7_win_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cpu_load_event_8_threshold : 6;
        unsigned int reserved_0 : 2;
        unsigned int cpu_load_event_8_win : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT8_CTL_REG_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT8_CTL_REG_cpu_load_event_8_threshold_START (0)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT8_CTL_REG_cpu_load_event_8_threshold_END (5)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT8_CTL_REG_cpu_load_event_8_win_START (8)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT8_CTL_REG_cpu_load_event_8_win_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cpu_load_event_9_threshold : 6;
        unsigned int reserved_0 : 2;
        unsigned int cpu_load_event_9_win : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT9_CTL_REG_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT9_CTL_REG_cpu_load_event_9_threshold_START (0)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT9_CTL_REG_cpu_load_event_9_threshold_END (5)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT9_CTL_REG_cpu_load_event_9_win_START (8)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT9_CTL_REG_cpu_load_event_9_win_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cpu_load_event_10_threshold : 6;
        unsigned int reserved_0 : 2;
        unsigned int cpu_load_event_10_win : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT10_CTL_REG_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT10_CTL_REG_cpu_load_event_10_threshold_START (0)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT10_CTL_REG_cpu_load_event_10_threshold_END (5)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT10_CTL_REG_cpu_load_event_10_win_START (8)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT10_CTL_REG_cpu_load_event_10_win_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cpu_load_event_11_threshold : 6;
        unsigned int reserved_0 : 2;
        unsigned int cpu_load_event_11_win : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT11_CTL_REG_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT11_CTL_REG_cpu_load_event_11_threshold_START (0)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT11_CTL_REG_cpu_load_event_11_threshold_END (5)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT11_CTL_REG_cpu_load_event_11_win_START (8)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT11_CTL_REG_cpu_load_event_11_win_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cpu_load_event_12_threshold : 6;
        unsigned int reserved_0 : 2;
        unsigned int cpu_load_event_12_win : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT12_CTL_REG_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT12_CTL_REG_cpu_load_event_12_threshold_START (0)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT12_CTL_REG_cpu_load_event_12_threshold_END (5)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT12_CTL_REG_cpu_load_event_12_win_START (8)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT12_CTL_REG_cpu_load_event_12_win_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cpu_load_event_13_threshold : 6;
        unsigned int reserved_0 : 2;
        unsigned int cpu_load_event_13_win : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT13_CTL_REG_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT13_CTL_REG_cpu_load_event_13_threshold_START (0)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT13_CTL_REG_cpu_load_event_13_threshold_END (5)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT13_CTL_REG_cpu_load_event_13_win_START (8)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT13_CTL_REG_cpu_load_event_13_win_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cpu_load_event_14_threshold : 6;
        unsigned int reserved_0 : 2;
        unsigned int cpu_load_event_14_win : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT14_CTL_REG_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT14_CTL_REG_cpu_load_event_14_threshold_START (0)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT14_CTL_REG_cpu_load_event_14_threshold_END (5)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT14_CTL_REG_cpu_load_event_14_win_START (8)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT14_CTL_REG_cpu_load_event_14_win_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cpu_load_event_15_threshold : 6;
        unsigned int reserved_0 : 2;
        unsigned int cpu_load_event_15_win : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT15_CTL_REG_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT15_CTL_REG_cpu_load_event_15_threshold_START (0)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT15_CTL_REG_cpu_load_event_15_threshold_END (5)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT15_CTL_REG_cpu_load_event_15_win_START (8)
#define SOC_FCM_LOCAL_MID_CORE_BIG_LOAD_EVENT15_CTL_REG_cpu_load_event_15_win_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtm0_over_info_31_0 : 32;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT0_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT0_rtm0_over_info_31_0_START (0)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT0_rtm0_over_info_31_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtm0_over_info_32 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT1_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT1_rtm0_over_info_32_START (0)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT1_rtm0_over_info_32_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtm1_over_info_31_0 : 32;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT2_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT2_rtm1_over_info_31_0_START (0)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT2_rtm1_over_info_31_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtm1_over_info_32 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT3_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT3_rtm1_over_info_32_START (0)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT3_rtm1_over_info_32_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fvt0_over_info : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT4_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT4_fvt0_over_info_START (0)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT4_fvt0_over_info_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fvt1_over_info : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT5_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT5_fvt1_over_info_START (0)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT5_fvt1_over_info_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tde_check_status : 32;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT6_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT6_tde_check_status_START (0)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT6_tde_check_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tde_final_result : 1;
        unsigned int tde_cfg_ready : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT7_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT7_tde_final_result_START (0)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT7_tde_final_result_END (0)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT7_tde_cfg_ready_START (1)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT7_tde_cfg_ready_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cpu_cycle_cnt_record : 22;
        unsigned int reserved : 10;
    } reg;
} SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT8_UNION;
#endif
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT8_cpu_cycle_cnt_record_START (0)
#define SOC_FCM_LOCAL_MID_CORE_FCM_LOCAL_CORE_STAT8_cpu_cycle_cnt_record_END (21)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
