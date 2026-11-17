#ifndef __SOC_FCM_LOCAL_IP_INTERFACE_H__
#define __SOC_FCM_LOCAL_IP_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FCM_LOCAL_IP_CTRL0_ADDR(base) ((base) + (0x800UL))
#define SOC_FCM_LOCAL_IP_CLKEN1_ADDR(base) ((base) + (0x804UL))
#define SOC_FCM_LOCAL_IP_CLKEN2_ADDR(base) ((base) + (0x808UL))
#define SOC_FCM_LOCAL_IP_RST_EN_ADDR(base) ((base) + (0x80CUL))
#define SOC_FCM_LOCAL_IP_RST_DIS_ADDR(base) ((base) + (0x810UL))
#define SOC_FCM_LOCAL_IP_RST_STAT_ADDR(base) ((base) + (0x814UL))
#define SOC_FCM_LOCAL_IP_CTRL4_ADDR(base) ((base) + (0x818UL))
#define SOC_FCM_LOCAL_IP_CTRL5_ADDR(base) ((base) + (0x81CUL))
#define SOC_FCM_LOCAL_IP_CTRL6_ADDR(base) ((base) + (0x820UL))
#define SOC_FCM_LOCAL_IP_CTRL7_ADDR(base) ((base) + (0x824UL))
#define SOC_FCM_LOCAL_IP_CTRL8_ADDR(base) ((base) + (0x828UL))
#define SOC_FCM_LOCAL_IP_CTRL9_ADDR(base) ((base) + (0x82CUL))
#define SOC_FCM_LOCAL_IP_CTRL10_ADDR(base) ((base) + (0x830UL))
#define SOC_FCM_LOCAL_IP_CTRL11_ADDR(base) ((base) + (0x834UL))
#define SOC_FCM_LOCAL_IP_CTRL12_ADDR(base) ((base) + (0x838UL))
#define SOC_FCM_LOCAL_IP_CTRL13_ADDR(base) ((base) + (0x83CUL))
#define SOC_FCM_LOCAL_IP_CTRL14_ADDR(base) ((base) + (0x840UL))
#define SOC_FCM_LOCAL_IP_CTRL16_ADDR(base) ((base) + (0x848UL))
#define SOC_FCM_LOCAL_IP_CTRL17_ADDR(base) ((base) + (0x084CUL))
#define SOC_FCM_LOCAL_IP_CTRL18_ADDR(base) ((base) + (0x0850UL))
#define SOC_FCM_LOCAL_IP_CTRL19_ADDR(base) ((base) + (0x0854UL))
#define SOC_FCM_LOCAL_IP_CTRL20_ADDR(base) ((base) + (0x0858UL))
#define SOC_FCM_LOCAL_IP_CTRL21_ADDR(base) ((base) + (0x085CUL))
#define SOC_FCM_LOCAL_IP_CTRL22_ADDR(base) ((base) + (0x0860UL))
#define SOC_FCM_LOCAL_IP_CTRL24_ADDR(base) ((base) + (0x868UL))
#define SOC_FCM_LOCAL_IP_CTRL26_ADDR(base) ((base) + (0x870UL))
#define SOC_FCM_LOCAL_IP_CTRL27_ADDR(base) ((base) + (0x874UL))
#define SOC_FCM_LOCAL_IP_CTRL28_ADDR(base) ((base) + (0x878UL))
#define SOC_FCM_LOCAL_IP_CTRL29_ADDR(base) ((base) + (0x87cUL))
#define SOC_FCM_LOCAL_IP_CTRL30_ADDR(base) ((base) + (0x880UL))
#define SOC_FCM_LOCAL_IP_CTRL31_ADDR(base) ((base) + (0x884UL))
#define SOC_FCM_LOCAL_IP_CTRL32_ADDR(base) ((base) + (0x888UL))
#define SOC_FCM_LOCAL_IP_CTRL33_ADDR(base) ((base) + (0x88CUL))
#define SOC_FCM_LOCAL_IP_CTRL34_ADDR(base) ((base) + (0x890UL))
#define SOC_FCM_LOCAL_IP_CTRL35_ADDR(base) ((base) + (0x894UL))
#define SOC_FCM_LOCAL_IP_CTRL36_ADDR(base) ((base) + (0x898UL))
#define SOC_FCM_LOCAL_IP_CTRL37_ADDR(base) ((base) + (0x89CUL))
#define SOC_FCM_LOCAL_IP_CTRL38_ADDR(base) ((base) + (0x8A0UL))
#define SOC_FCM_LOCAL_IP_CTRL39_ADDR(base) ((base) + (0x8A4UL))
#define SOC_FCM_LOCAL_IP_CTRL40_ADDR(base) ((base) + (0x8A8UL))
#define SOC_FCM_LOCAL_IP_CTRL41_ADDR(base) ((base) + (0x8ACUL))
#define SOC_FCM_LOCAL_IP_CTRL42_ADDR(base) ((base) + (0x8B0UL))
#define SOC_FCM_LOCAL_IP_CTRL43_ADDR(base) ((base) + (0x8B4UL))
#define SOC_FCM_LOCAL_IP_CTRL44_ADDR(base) ((base) + (0x8B8UL))
#define SOC_FCM_LOCAL_IP_CTRL45_ADDR(base) ((base) + (0x8BCUL))
#define SOC_FCM_LOCAL_IP_CTRL46_ADDR(base) ((base) + (0x8C0UL))
#define SOC_FCM_LOCAL_IP_CTRL47_ADDR(base) ((base) + (0x8C4UL))
#define SOC_FCM_LOCAL_IP_CTRL48_ADDR(base) ((base) + (0x8C8UL))
#define SOC_FCM_LOCAL_IP_STAT0_ADDR(base) ((base) + (0xC00UL))
#define SOC_FCM_LOCAL_IP_STAT1_ADDR(base) ((base) + (0xC04UL))
#define SOC_FCM_LOCAL_IP_STAT2_ADDR(base) ((base) + (0xC08UL))
#define SOC_FCM_LOCAL_IP_STAT3_ADDR(base) ((base) + (0xC0CUL))
#define SOC_FCM_LOCAL_IP_STAT4_ADDR(base) ((base) + (0xC10UL))
#define SOC_FCM_LOCAL_IP_STAT5_ADDR(base) ((base) + (0xC14UL))
#define SOC_FCM_LOCAL_IP_STAT6_ADDR(base) ((base) + (0xC18UL))
#define SOC_FCM_LOCAL_IP_STAT7_ADDR(base) ((base) + (0xC1CUL))
#define SOC_FCM_LOCAL_IP_STAT8_ADDR(base) ((base) + (0xC20UL))
#define SOC_FCM_LOCAL_IP_STAT9_ADDR(base) ((base) + (0xC24UL))
#define SOC_FCM_LOCAL_IP_STAT10_ADDR(base) ((base) + (0xC28UL))
#define SOC_FCM_LOCAL_IP_STAT11_ADDR(base) ((base) + (0xC2CUL))
#define SOC_FCM_LOCAL_IP_STAT12_ADDR(base) ((base) + (0xC30UL))
#define SOC_FCM_LOCAL_IP_STAT13_ADDR(base) ((base) + (0xC34UL))
#define SOC_FCM_LOCAL_IP_STAT14_ADDR(base) ((base) + (0xC38UL))
#define SOC_FCM_LOCAL_IP_STAT15_ADDR(base) ((base) + (0xC3CUL))
#define SOC_FCM_LOCAL_IP_STAT16_ADDR(base) ((base) + (0xC40UL))
#define SOC_FCM_LOCAL_IP_STAT17_ADDR(base) ((base) + (0xC44UL))
#define SOC_FCM_LOCAL_IP_STAT18_ADDR(base) ((base) + (0xC48UL))
#define SOC_FCM_LOCAL_IP_STAT19_ADDR(base) ((base) + (0xC4CUL))
#define SOC_FCM_LOCAL_IP_STAT20_ADDR(base) ((base) + (0x0C50UL))
#define SOC_FCM_LOCAL_IP_STAT21_ADDR(base) ((base) + (0x0C54UL))
#define SOC_FCM_LOCAL_IP_STAT22_ADDR(base) ((base) + (0x0C58UL))
#define SOC_FCM_LOCAL_IP_STAT23_ADDR(base) ((base) + (0x0C5CUL))
#define SOC_FCM_LOCAL_IP_STAT24_ADDR(base) ((base) + (0x0C60UL))
#define SOC_FCM_LOCAL_IP_STAT25_ADDR(base) ((base) + (0x0C64UL))
#define SOC_FCM_LOCAL_IP_STAT26_ADDR(base) ((base) + (0x0C68UL))
#define SOC_FCM_LOCAL_IP_STAT27_ADDR(base) ((base) + (0x0C6CUL))
#define SOC_FCM_LOCAL_IP_STAT28_ADDR(base) ((base) + (0x0C70UL))
#define SOC_FCM_LOCAL_IP_STAT29_ADDR(base) ((base) + (0x0C74UL))
#define SOC_FCM_LOCAL_IP_STAT30_ADDR(base) ((base) + (0x0C78UL))
#define SOC_FCM_LOCAL_IP_STAT31_ADDR(base) ((base) + (0x0C7CUL))
#define SOC_FCM_LOCAL_IP_STAT32_ADDR(base) ((base) + (0x0C80UL))
#define SOC_FCM_LOCAL_IP_STAT33_ADDR(base) ((base) + (0x0C84UL))
#define SOC_FCM_LOCAL_IP_STAT34_ADDR(base) ((base) + (0x0C88UL))
#define SOC_FCM_LOCAL_IP_STAT35_ADDR(base) ((base) + (0x0C8CUL))
#define SOC_FCM_LOCAL_IP_STAT36_ADDR(base) ((base) + (0x0C90UL))
#define SOC_FCM_LOCAL_IP_STAT37_ADDR(base) ((base) + (0x0C94UL))
#define SOC_FCM_LOCAL_IP_STAT38_ADDR(base) ((base) + (0x0C98UL))
#define SOC_FCM_LOCAL_IP_STAT39_ADDR(base) ((base) + (0x0C9CUL))
#define SOC_FCM_LOCAL_IP_STAT40_ADDR(base) ((base) + (0x0CA0UL))
#else
#define SOC_FCM_LOCAL_IP_CTRL0_ADDR(base) ((base) + (0x800))
#define SOC_FCM_LOCAL_IP_CLKEN1_ADDR(base) ((base) + (0x804))
#define SOC_FCM_LOCAL_IP_CLKEN2_ADDR(base) ((base) + (0x808))
#define SOC_FCM_LOCAL_IP_RST_EN_ADDR(base) ((base) + (0x80C))
#define SOC_FCM_LOCAL_IP_RST_DIS_ADDR(base) ((base) + (0x810))
#define SOC_FCM_LOCAL_IP_RST_STAT_ADDR(base) ((base) + (0x814))
#define SOC_FCM_LOCAL_IP_CTRL4_ADDR(base) ((base) + (0x818))
#define SOC_FCM_LOCAL_IP_CTRL5_ADDR(base) ((base) + (0x81C))
#define SOC_FCM_LOCAL_IP_CTRL6_ADDR(base) ((base) + (0x820))
#define SOC_FCM_LOCAL_IP_CTRL7_ADDR(base) ((base) + (0x824))
#define SOC_FCM_LOCAL_IP_CTRL8_ADDR(base) ((base) + (0x828))
#define SOC_FCM_LOCAL_IP_CTRL9_ADDR(base) ((base) + (0x82C))
#define SOC_FCM_LOCAL_IP_CTRL10_ADDR(base) ((base) + (0x830))
#define SOC_FCM_LOCAL_IP_CTRL11_ADDR(base) ((base) + (0x834))
#define SOC_FCM_LOCAL_IP_CTRL12_ADDR(base) ((base) + (0x838))
#define SOC_FCM_LOCAL_IP_CTRL13_ADDR(base) ((base) + (0x83C))
#define SOC_FCM_LOCAL_IP_CTRL14_ADDR(base) ((base) + (0x840))
#define SOC_FCM_LOCAL_IP_CTRL16_ADDR(base) ((base) + (0x848))
#define SOC_FCM_LOCAL_IP_CTRL17_ADDR(base) ((base) + (0x084C))
#define SOC_FCM_LOCAL_IP_CTRL18_ADDR(base) ((base) + (0x0850))
#define SOC_FCM_LOCAL_IP_CTRL19_ADDR(base) ((base) + (0x0854))
#define SOC_FCM_LOCAL_IP_CTRL20_ADDR(base) ((base) + (0x0858))
#define SOC_FCM_LOCAL_IP_CTRL21_ADDR(base) ((base) + (0x085C))
#define SOC_FCM_LOCAL_IP_CTRL22_ADDR(base) ((base) + (0x0860))
#define SOC_FCM_LOCAL_IP_CTRL24_ADDR(base) ((base) + (0x868))
#define SOC_FCM_LOCAL_IP_CTRL26_ADDR(base) ((base) + (0x870))
#define SOC_FCM_LOCAL_IP_CTRL27_ADDR(base) ((base) + (0x874))
#define SOC_FCM_LOCAL_IP_CTRL28_ADDR(base) ((base) + (0x878))
#define SOC_FCM_LOCAL_IP_CTRL29_ADDR(base) ((base) + (0x87c))
#define SOC_FCM_LOCAL_IP_CTRL30_ADDR(base) ((base) + (0x880))
#define SOC_FCM_LOCAL_IP_CTRL31_ADDR(base) ((base) + (0x884))
#define SOC_FCM_LOCAL_IP_CTRL32_ADDR(base) ((base) + (0x888))
#define SOC_FCM_LOCAL_IP_CTRL33_ADDR(base) ((base) + (0x88C))
#define SOC_FCM_LOCAL_IP_CTRL34_ADDR(base) ((base) + (0x890))
#define SOC_FCM_LOCAL_IP_CTRL35_ADDR(base) ((base) + (0x894))
#define SOC_FCM_LOCAL_IP_CTRL36_ADDR(base) ((base) + (0x898))
#define SOC_FCM_LOCAL_IP_CTRL37_ADDR(base) ((base) + (0x89C))
#define SOC_FCM_LOCAL_IP_CTRL38_ADDR(base) ((base) + (0x8A0))
#define SOC_FCM_LOCAL_IP_CTRL39_ADDR(base) ((base) + (0x8A4))
#define SOC_FCM_LOCAL_IP_CTRL40_ADDR(base) ((base) + (0x8A8))
#define SOC_FCM_LOCAL_IP_CTRL41_ADDR(base) ((base) + (0x8AC))
#define SOC_FCM_LOCAL_IP_CTRL42_ADDR(base) ((base) + (0x8B0))
#define SOC_FCM_LOCAL_IP_CTRL43_ADDR(base) ((base) + (0x8B4))
#define SOC_FCM_LOCAL_IP_CTRL44_ADDR(base) ((base) + (0x8B8))
#define SOC_FCM_LOCAL_IP_CTRL45_ADDR(base) ((base) + (0x8BC))
#define SOC_FCM_LOCAL_IP_CTRL46_ADDR(base) ((base) + (0x8C0))
#define SOC_FCM_LOCAL_IP_CTRL47_ADDR(base) ((base) + (0x8C4))
#define SOC_FCM_LOCAL_IP_CTRL48_ADDR(base) ((base) + (0x8C8))
#define SOC_FCM_LOCAL_IP_STAT0_ADDR(base) ((base) + (0xC00))
#define SOC_FCM_LOCAL_IP_STAT1_ADDR(base) ((base) + (0xC04))
#define SOC_FCM_LOCAL_IP_STAT2_ADDR(base) ((base) + (0xC08))
#define SOC_FCM_LOCAL_IP_STAT3_ADDR(base) ((base) + (0xC0C))
#define SOC_FCM_LOCAL_IP_STAT4_ADDR(base) ((base) + (0xC10))
#define SOC_FCM_LOCAL_IP_STAT5_ADDR(base) ((base) + (0xC14))
#define SOC_FCM_LOCAL_IP_STAT6_ADDR(base) ((base) + (0xC18))
#define SOC_FCM_LOCAL_IP_STAT7_ADDR(base) ((base) + (0xC1C))
#define SOC_FCM_LOCAL_IP_STAT8_ADDR(base) ((base) + (0xC20))
#define SOC_FCM_LOCAL_IP_STAT9_ADDR(base) ((base) + (0xC24))
#define SOC_FCM_LOCAL_IP_STAT10_ADDR(base) ((base) + (0xC28))
#define SOC_FCM_LOCAL_IP_STAT11_ADDR(base) ((base) + (0xC2C))
#define SOC_FCM_LOCAL_IP_STAT12_ADDR(base) ((base) + (0xC30))
#define SOC_FCM_LOCAL_IP_STAT13_ADDR(base) ((base) + (0xC34))
#define SOC_FCM_LOCAL_IP_STAT14_ADDR(base) ((base) + (0xC38))
#define SOC_FCM_LOCAL_IP_STAT15_ADDR(base) ((base) + (0xC3C))
#define SOC_FCM_LOCAL_IP_STAT16_ADDR(base) ((base) + (0xC40))
#define SOC_FCM_LOCAL_IP_STAT17_ADDR(base) ((base) + (0xC44))
#define SOC_FCM_LOCAL_IP_STAT18_ADDR(base) ((base) + (0xC48))
#define SOC_FCM_LOCAL_IP_STAT19_ADDR(base) ((base) + (0xC4C))
#define SOC_FCM_LOCAL_IP_STAT20_ADDR(base) ((base) + (0x0C50))
#define SOC_FCM_LOCAL_IP_STAT21_ADDR(base) ((base) + (0x0C54))
#define SOC_FCM_LOCAL_IP_STAT22_ADDR(base) ((base) + (0x0C58))
#define SOC_FCM_LOCAL_IP_STAT23_ADDR(base) ((base) + (0x0C5C))
#define SOC_FCM_LOCAL_IP_STAT24_ADDR(base) ((base) + (0x0C60))
#define SOC_FCM_LOCAL_IP_STAT25_ADDR(base) ((base) + (0x0C64))
#define SOC_FCM_LOCAL_IP_STAT26_ADDR(base) ((base) + (0x0C68))
#define SOC_FCM_LOCAL_IP_STAT27_ADDR(base) ((base) + (0x0C6C))
#define SOC_FCM_LOCAL_IP_STAT28_ADDR(base) ((base) + (0x0C70))
#define SOC_FCM_LOCAL_IP_STAT29_ADDR(base) ((base) + (0x0C74))
#define SOC_FCM_LOCAL_IP_STAT30_ADDR(base) ((base) + (0x0C78))
#define SOC_FCM_LOCAL_IP_STAT31_ADDR(base) ((base) + (0x0C7C))
#define SOC_FCM_LOCAL_IP_STAT32_ADDR(base) ((base) + (0x0C80))
#define SOC_FCM_LOCAL_IP_STAT33_ADDR(base) ((base) + (0x0C84))
#define SOC_FCM_LOCAL_IP_STAT34_ADDR(base) ((base) + (0x0C88))
#define SOC_FCM_LOCAL_IP_STAT35_ADDR(base) ((base) + (0x0C8C))
#define SOC_FCM_LOCAL_IP_STAT36_ADDR(base) ((base) + (0x0C90))
#define SOC_FCM_LOCAL_IP_STAT37_ADDR(base) ((base) + (0x0C94))
#define SOC_FCM_LOCAL_IP_STAT38_ADDR(base) ((base) + (0x0C98))
#define SOC_FCM_LOCAL_IP_STAT39_ADDR(base) ((base) + (0x0C9C))
#define SOC_FCM_LOCAL_IP_STAT40_ADDR(base) ((base) + (0x0CA0))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 15;
        unsigned int sel_core_pi_flag : 2;
        unsigned int bypass_wfe_wakeup_ctl : 1;
        unsigned int bypass_wfe_wakeup_ctl_sel_gear : 2;
        unsigned int bypass_wfe_wakeup_ctl_cfg_cnt : 10;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL0_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL0_sel_core_pi_flag_START (15)
#define SOC_FCM_LOCAL_IP_CTRL0_sel_core_pi_flag_END (16)
#define SOC_FCM_LOCAL_IP_CTRL0_bypass_wfe_wakeup_ctl_START (17)
#define SOC_FCM_LOCAL_IP_CTRL0_bypass_wfe_wakeup_ctl_END (17)
#define SOC_FCM_LOCAL_IP_CTRL0_bypass_wfe_wakeup_ctl_sel_gear_START (18)
#define SOC_FCM_LOCAL_IP_CTRL0_bypass_wfe_wakeup_ctl_sel_gear_END (19)
#define SOC_FCM_LOCAL_IP_CTRL0_bypass_wfe_wakeup_ctl_cfg_cnt_START (20)
#define SOC_FCM_LOCAL_IP_CTRL0_bypass_wfe_wakeup_ctl_cfg_cnt_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clkoff_l3_rtm : 1;
        unsigned int clkoff_pi_trace : 1;
        unsigned int clkoff_hwp : 1;
        unsigned int reserved : 13;
        unsigned int clken_masken1 : 16;
    } reg;
} SOC_FCM_LOCAL_IP_CLKEN1_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CLKEN1_clkoff_l3_rtm_START (0)
#define SOC_FCM_LOCAL_IP_CLKEN1_clkoff_l3_rtm_END (0)
#define SOC_FCM_LOCAL_IP_CLKEN1_clkoff_pi_trace_START (1)
#define SOC_FCM_LOCAL_IP_CLKEN1_clkoff_pi_trace_END (1)
#define SOC_FCM_LOCAL_IP_CLKEN1_clkoff_hwp_START (2)
#define SOC_FCM_LOCAL_IP_CLKEN1_clkoff_hwp_END (2)
#define SOC_FCM_LOCAL_IP_CLKEN1_clken_masken1_START (16)
#define SOC_FCM_LOCAL_IP_CLKEN1_clken_masken1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 16;
        unsigned int clken_masken2 : 16;
    } reg;
} SOC_FCM_LOCAL_IP_CLKEN2_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CLKEN2_clken_masken2_START (16)
#define SOC_FCM_LOCAL_IP_CLKEN2_clken_masken2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 31;
    } reg;
} SOC_FCM_LOCAL_IP_RST_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 31;
    } reg;
} SOC_FCM_LOCAL_IP_RST_DIS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 31;
    } reg;
} SOC_FCM_LOCAL_IP_RST_STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m_soft_cfg_partid0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int m_soft_cfg_partid1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int m_soft_cfg_partid2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int m_soft_cfg_partid3 : 3;
        unsigned int reserved_3 : 1;
        unsigned int m_soft_cfg_partid4 : 3;
        unsigned int reserved_4 : 1;
        unsigned int m_soft_cfg_partid5 : 3;
        unsigned int reserved_5 : 1;
        unsigned int m_soft_cfg_partid6 : 3;
        unsigned int reserved_6 : 1;
        unsigned int m_soft_cfg_partid7 : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL5_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL5_m_soft_cfg_partid0_START (0)
#define SOC_FCM_LOCAL_IP_CTRL5_m_soft_cfg_partid0_END (2)
#define SOC_FCM_LOCAL_IP_CTRL5_m_soft_cfg_partid1_START (4)
#define SOC_FCM_LOCAL_IP_CTRL5_m_soft_cfg_partid1_END (6)
#define SOC_FCM_LOCAL_IP_CTRL5_m_soft_cfg_partid2_START (8)
#define SOC_FCM_LOCAL_IP_CTRL5_m_soft_cfg_partid2_END (10)
#define SOC_FCM_LOCAL_IP_CTRL5_m_soft_cfg_partid3_START (12)
#define SOC_FCM_LOCAL_IP_CTRL5_m_soft_cfg_partid3_END (14)
#define SOC_FCM_LOCAL_IP_CTRL5_m_soft_cfg_partid4_START (16)
#define SOC_FCM_LOCAL_IP_CTRL5_m_soft_cfg_partid4_END (18)
#define SOC_FCM_LOCAL_IP_CTRL5_m_soft_cfg_partid5_START (20)
#define SOC_FCM_LOCAL_IP_CTRL5_m_soft_cfg_partid5_END (22)
#define SOC_FCM_LOCAL_IP_CTRL5_m_soft_cfg_partid6_START (24)
#define SOC_FCM_LOCAL_IP_CTRL5_m_soft_cfg_partid6_END (26)
#define SOC_FCM_LOCAL_IP_CTRL5_m_soft_cfg_partid7_START (28)
#define SOC_FCM_LOCAL_IP_CTRL5_m_soft_cfg_partid7_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m_soft_cfg_partid8 : 3;
        unsigned int reserved_0 : 1;
        unsigned int m_soft_cfg_partid9 : 3;
        unsigned int reserved_1 : 1;
        unsigned int m_soft_cfg_partid10 : 3;
        unsigned int reserved_2 : 1;
        unsigned int m_soft_cfg_partid11 : 3;
        unsigned int reserved_3 : 1;
        unsigned int m_soft_cfg_partid12 : 3;
        unsigned int reserved_4 : 1;
        unsigned int m_soft_cfg_partid13 : 3;
        unsigned int reserved_5 : 1;
        unsigned int m_soft_cfg_partid14 : 3;
        unsigned int reserved_6 : 1;
        unsigned int m_soft_cfg_partid15 : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL6_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL6_m_soft_cfg_partid8_START (0)
#define SOC_FCM_LOCAL_IP_CTRL6_m_soft_cfg_partid8_END (2)
#define SOC_FCM_LOCAL_IP_CTRL6_m_soft_cfg_partid9_START (4)
#define SOC_FCM_LOCAL_IP_CTRL6_m_soft_cfg_partid9_END (6)
#define SOC_FCM_LOCAL_IP_CTRL6_m_soft_cfg_partid10_START (8)
#define SOC_FCM_LOCAL_IP_CTRL6_m_soft_cfg_partid10_END (10)
#define SOC_FCM_LOCAL_IP_CTRL6_m_soft_cfg_partid11_START (12)
#define SOC_FCM_LOCAL_IP_CTRL6_m_soft_cfg_partid11_END (14)
#define SOC_FCM_LOCAL_IP_CTRL6_m_soft_cfg_partid12_START (16)
#define SOC_FCM_LOCAL_IP_CTRL6_m_soft_cfg_partid12_END (18)
#define SOC_FCM_LOCAL_IP_CTRL6_m_soft_cfg_partid13_START (20)
#define SOC_FCM_LOCAL_IP_CTRL6_m_soft_cfg_partid13_END (22)
#define SOC_FCM_LOCAL_IP_CTRL6_m_soft_cfg_partid14_START (24)
#define SOC_FCM_LOCAL_IP_CTRL6_m_soft_cfg_partid14_END (26)
#define SOC_FCM_LOCAL_IP_CTRL6_m_soft_cfg_partid15_START (28)
#define SOC_FCM_LOCAL_IP_CTRL6_m_soft_cfg_partid15_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m0_cfg_qos_reg0_0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int m0_cfg_qos_reg0_1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int m0_cfg_qos_reg0_2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int m0_cfg_qos_reg0_3 : 3;
        unsigned int reserved_3 : 1;
        unsigned int m0_cfg_qos_reg0_4 : 3;
        unsigned int reserved_4 : 1;
        unsigned int m0_cfg_qos_reg0_5 : 3;
        unsigned int reserved_5 : 1;
        unsigned int m0_cfg_qos_reg0_6 : 3;
        unsigned int reserved_6 : 1;
        unsigned int m0_cfg_qos_reg0_7 : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL7_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL7_m0_cfg_qos_reg0_0_START (0)
#define SOC_FCM_LOCAL_IP_CTRL7_m0_cfg_qos_reg0_0_END (2)
#define SOC_FCM_LOCAL_IP_CTRL7_m0_cfg_qos_reg0_1_START (4)
#define SOC_FCM_LOCAL_IP_CTRL7_m0_cfg_qos_reg0_1_END (6)
#define SOC_FCM_LOCAL_IP_CTRL7_m0_cfg_qos_reg0_2_START (8)
#define SOC_FCM_LOCAL_IP_CTRL7_m0_cfg_qos_reg0_2_END (10)
#define SOC_FCM_LOCAL_IP_CTRL7_m0_cfg_qos_reg0_3_START (12)
#define SOC_FCM_LOCAL_IP_CTRL7_m0_cfg_qos_reg0_3_END (14)
#define SOC_FCM_LOCAL_IP_CTRL7_m0_cfg_qos_reg0_4_START (16)
#define SOC_FCM_LOCAL_IP_CTRL7_m0_cfg_qos_reg0_4_END (18)
#define SOC_FCM_LOCAL_IP_CTRL7_m0_cfg_qos_reg0_5_START (20)
#define SOC_FCM_LOCAL_IP_CTRL7_m0_cfg_qos_reg0_5_END (22)
#define SOC_FCM_LOCAL_IP_CTRL7_m0_cfg_qos_reg0_6_START (24)
#define SOC_FCM_LOCAL_IP_CTRL7_m0_cfg_qos_reg0_6_END (26)
#define SOC_FCM_LOCAL_IP_CTRL7_m0_cfg_qos_reg0_7_START (28)
#define SOC_FCM_LOCAL_IP_CTRL7_m0_cfg_qos_reg0_7_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m0_cfg_qos_reg1_0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int m0_cfg_qos_reg1_1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int m0_cfg_qos_reg1_2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int m0_cfg_qos_reg1_3 : 3;
        unsigned int reserved_3 : 1;
        unsigned int m0_cfg_qos_reg1_4 : 3;
        unsigned int reserved_4 : 1;
        unsigned int m0_cfg_qos_reg1_5 : 3;
        unsigned int reserved_5 : 1;
        unsigned int m0_cfg_qos_reg1_6 : 3;
        unsigned int reserved_6 : 1;
        unsigned int m0_cfg_qos_reg1_7 : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL8_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL8_m0_cfg_qos_reg1_0_START (0)
#define SOC_FCM_LOCAL_IP_CTRL8_m0_cfg_qos_reg1_0_END (2)
#define SOC_FCM_LOCAL_IP_CTRL8_m0_cfg_qos_reg1_1_START (4)
#define SOC_FCM_LOCAL_IP_CTRL8_m0_cfg_qos_reg1_1_END (6)
#define SOC_FCM_LOCAL_IP_CTRL8_m0_cfg_qos_reg1_2_START (8)
#define SOC_FCM_LOCAL_IP_CTRL8_m0_cfg_qos_reg1_2_END (10)
#define SOC_FCM_LOCAL_IP_CTRL8_m0_cfg_qos_reg1_3_START (12)
#define SOC_FCM_LOCAL_IP_CTRL8_m0_cfg_qos_reg1_3_END (14)
#define SOC_FCM_LOCAL_IP_CTRL8_m0_cfg_qos_reg1_4_START (16)
#define SOC_FCM_LOCAL_IP_CTRL8_m0_cfg_qos_reg1_4_END (18)
#define SOC_FCM_LOCAL_IP_CTRL8_m0_cfg_qos_reg1_5_START (20)
#define SOC_FCM_LOCAL_IP_CTRL8_m0_cfg_qos_reg1_5_END (22)
#define SOC_FCM_LOCAL_IP_CTRL8_m0_cfg_qos_reg1_6_START (24)
#define SOC_FCM_LOCAL_IP_CTRL8_m0_cfg_qos_reg1_6_END (26)
#define SOC_FCM_LOCAL_IP_CTRL8_m0_cfg_qos_reg1_7_START (28)
#define SOC_FCM_LOCAL_IP_CTRL8_m0_cfg_qos_reg1_7_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m0_cfg_qos_reg2_0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int m0_cfg_qos_reg2_1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int m0_cfg_qos_reg2_2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int m0_cfg_qos_reg2_3 : 3;
        unsigned int reserved_3 : 1;
        unsigned int m0_cfg_qos_reg2_4 : 3;
        unsigned int reserved_4 : 1;
        unsigned int m0_cfg_qos_reg2_5 : 3;
        unsigned int reserved_5 : 1;
        unsigned int m0_cfg_qos_reg2_6 : 3;
        unsigned int reserved_6 : 1;
        unsigned int m0_cfg_qos_reg2_7 : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL9_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL9_m0_cfg_qos_reg2_0_START (0)
#define SOC_FCM_LOCAL_IP_CTRL9_m0_cfg_qos_reg2_0_END (2)
#define SOC_FCM_LOCAL_IP_CTRL9_m0_cfg_qos_reg2_1_START (4)
#define SOC_FCM_LOCAL_IP_CTRL9_m0_cfg_qos_reg2_1_END (6)
#define SOC_FCM_LOCAL_IP_CTRL9_m0_cfg_qos_reg2_2_START (8)
#define SOC_FCM_LOCAL_IP_CTRL9_m0_cfg_qos_reg2_2_END (10)
#define SOC_FCM_LOCAL_IP_CTRL9_m0_cfg_qos_reg2_3_START (12)
#define SOC_FCM_LOCAL_IP_CTRL9_m0_cfg_qos_reg2_3_END (14)
#define SOC_FCM_LOCAL_IP_CTRL9_m0_cfg_qos_reg2_4_START (16)
#define SOC_FCM_LOCAL_IP_CTRL9_m0_cfg_qos_reg2_4_END (18)
#define SOC_FCM_LOCAL_IP_CTRL9_m0_cfg_qos_reg2_5_START (20)
#define SOC_FCM_LOCAL_IP_CTRL9_m0_cfg_qos_reg2_5_END (22)
#define SOC_FCM_LOCAL_IP_CTRL9_m0_cfg_qos_reg2_6_START (24)
#define SOC_FCM_LOCAL_IP_CTRL9_m0_cfg_qos_reg2_6_END (26)
#define SOC_FCM_LOCAL_IP_CTRL9_m0_cfg_qos_reg2_7_START (28)
#define SOC_FCM_LOCAL_IP_CTRL9_m0_cfg_qos_reg2_7_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m0_cfg_qos_reg3_0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int m0_cfg_qos_reg3_1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int m0_cfg_qos_reg3_2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int m0_cfg_qos_reg3_3 : 3;
        unsigned int reserved_3 : 1;
        unsigned int m0_cfg_qos_reg3_4 : 3;
        unsigned int reserved_4 : 1;
        unsigned int m0_cfg_qos_reg3_5 : 3;
        unsigned int reserved_5 : 1;
        unsigned int m0_cfg_qos_reg3_6 : 3;
        unsigned int reserved_6 : 1;
        unsigned int m0_cfg_qos_reg3_7 : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL10_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL10_m0_cfg_qos_reg3_0_START (0)
#define SOC_FCM_LOCAL_IP_CTRL10_m0_cfg_qos_reg3_0_END (2)
#define SOC_FCM_LOCAL_IP_CTRL10_m0_cfg_qos_reg3_1_START (4)
#define SOC_FCM_LOCAL_IP_CTRL10_m0_cfg_qos_reg3_1_END (6)
#define SOC_FCM_LOCAL_IP_CTRL10_m0_cfg_qos_reg3_2_START (8)
#define SOC_FCM_LOCAL_IP_CTRL10_m0_cfg_qos_reg3_2_END (10)
#define SOC_FCM_LOCAL_IP_CTRL10_m0_cfg_qos_reg3_3_START (12)
#define SOC_FCM_LOCAL_IP_CTRL10_m0_cfg_qos_reg3_3_END (14)
#define SOC_FCM_LOCAL_IP_CTRL10_m0_cfg_qos_reg3_4_START (16)
#define SOC_FCM_LOCAL_IP_CTRL10_m0_cfg_qos_reg3_4_END (18)
#define SOC_FCM_LOCAL_IP_CTRL10_m0_cfg_qos_reg3_5_START (20)
#define SOC_FCM_LOCAL_IP_CTRL10_m0_cfg_qos_reg3_5_END (22)
#define SOC_FCM_LOCAL_IP_CTRL10_m0_cfg_qos_reg3_6_START (24)
#define SOC_FCM_LOCAL_IP_CTRL10_m0_cfg_qos_reg3_6_END (26)
#define SOC_FCM_LOCAL_IP_CTRL10_m0_cfg_qos_reg3_7_START (28)
#define SOC_FCM_LOCAL_IP_CTRL10_m0_cfg_qos_reg3_7_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m0_cfg_qos_reg4_0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int m0_cfg_qos_reg4_1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int m0_cfg_qos_reg4_2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int m0_cfg_qos_reg4_3 : 3;
        unsigned int reserved_3 : 1;
        unsigned int m0_cfg_qos_reg4_4 : 3;
        unsigned int reserved_4 : 1;
        unsigned int m0_cfg_qos_reg4_5 : 3;
        unsigned int reserved_5 : 1;
        unsigned int m0_cfg_qos_reg4_6 : 3;
        unsigned int reserved_6 : 1;
        unsigned int m0_cfg_qos_reg4_7 : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL11_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL11_m0_cfg_qos_reg4_0_START (0)
#define SOC_FCM_LOCAL_IP_CTRL11_m0_cfg_qos_reg4_0_END (2)
#define SOC_FCM_LOCAL_IP_CTRL11_m0_cfg_qos_reg4_1_START (4)
#define SOC_FCM_LOCAL_IP_CTRL11_m0_cfg_qos_reg4_1_END (6)
#define SOC_FCM_LOCAL_IP_CTRL11_m0_cfg_qos_reg4_2_START (8)
#define SOC_FCM_LOCAL_IP_CTRL11_m0_cfg_qos_reg4_2_END (10)
#define SOC_FCM_LOCAL_IP_CTRL11_m0_cfg_qos_reg4_3_START (12)
#define SOC_FCM_LOCAL_IP_CTRL11_m0_cfg_qos_reg4_3_END (14)
#define SOC_FCM_LOCAL_IP_CTRL11_m0_cfg_qos_reg4_4_START (16)
#define SOC_FCM_LOCAL_IP_CTRL11_m0_cfg_qos_reg4_4_END (18)
#define SOC_FCM_LOCAL_IP_CTRL11_m0_cfg_qos_reg4_5_START (20)
#define SOC_FCM_LOCAL_IP_CTRL11_m0_cfg_qos_reg4_5_END (22)
#define SOC_FCM_LOCAL_IP_CTRL11_m0_cfg_qos_reg4_6_START (24)
#define SOC_FCM_LOCAL_IP_CTRL11_m0_cfg_qos_reg4_6_END (26)
#define SOC_FCM_LOCAL_IP_CTRL11_m0_cfg_qos_reg4_7_START (28)
#define SOC_FCM_LOCAL_IP_CTRL11_m0_cfg_qos_reg4_7_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m0_cfg_qos_reg5_0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int m0_cfg_qos_reg5_1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int m0_cfg_qos_reg5_2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int m0_cfg_qos_reg5_3 : 3;
        unsigned int reserved_3 : 1;
        unsigned int m0_cfg_qos_reg5_4 : 3;
        unsigned int reserved_4 : 1;
        unsigned int m0_cfg_qos_reg5_5 : 3;
        unsigned int reserved_5 : 1;
        unsigned int m0_cfg_qos_reg5_6 : 3;
        unsigned int reserved_6 : 1;
        unsigned int m0_cfg_qos_reg5_7 : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL12_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL12_m0_cfg_qos_reg5_0_START (0)
#define SOC_FCM_LOCAL_IP_CTRL12_m0_cfg_qos_reg5_0_END (2)
#define SOC_FCM_LOCAL_IP_CTRL12_m0_cfg_qos_reg5_1_START (4)
#define SOC_FCM_LOCAL_IP_CTRL12_m0_cfg_qos_reg5_1_END (6)
#define SOC_FCM_LOCAL_IP_CTRL12_m0_cfg_qos_reg5_2_START (8)
#define SOC_FCM_LOCAL_IP_CTRL12_m0_cfg_qos_reg5_2_END (10)
#define SOC_FCM_LOCAL_IP_CTRL12_m0_cfg_qos_reg5_3_START (12)
#define SOC_FCM_LOCAL_IP_CTRL12_m0_cfg_qos_reg5_3_END (14)
#define SOC_FCM_LOCAL_IP_CTRL12_m0_cfg_qos_reg5_4_START (16)
#define SOC_FCM_LOCAL_IP_CTRL12_m0_cfg_qos_reg5_4_END (18)
#define SOC_FCM_LOCAL_IP_CTRL12_m0_cfg_qos_reg5_5_START (20)
#define SOC_FCM_LOCAL_IP_CTRL12_m0_cfg_qos_reg5_5_END (22)
#define SOC_FCM_LOCAL_IP_CTRL12_m0_cfg_qos_reg5_6_START (24)
#define SOC_FCM_LOCAL_IP_CTRL12_m0_cfg_qos_reg5_6_END (26)
#define SOC_FCM_LOCAL_IP_CTRL12_m0_cfg_qos_reg5_7_START (28)
#define SOC_FCM_LOCAL_IP_CTRL12_m0_cfg_qos_reg5_7_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m0_cfg_qos_reg6_0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int m0_cfg_qos_reg6_1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int m0_cfg_qos_reg6_2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int m0_cfg_qos_reg6_3 : 3;
        unsigned int reserved_3 : 1;
        unsigned int m0_cfg_qos_reg6_4 : 3;
        unsigned int reserved_4 : 1;
        unsigned int m0_cfg_qos_reg6_5 : 3;
        unsigned int reserved_5 : 1;
        unsigned int m0_cfg_qos_reg6_6 : 3;
        unsigned int reserved_6 : 1;
        unsigned int m0_cfg_qos_reg6_7 : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL13_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL13_m0_cfg_qos_reg6_0_START (0)
#define SOC_FCM_LOCAL_IP_CTRL13_m0_cfg_qos_reg6_0_END (2)
#define SOC_FCM_LOCAL_IP_CTRL13_m0_cfg_qos_reg6_1_START (4)
#define SOC_FCM_LOCAL_IP_CTRL13_m0_cfg_qos_reg6_1_END (6)
#define SOC_FCM_LOCAL_IP_CTRL13_m0_cfg_qos_reg6_2_START (8)
#define SOC_FCM_LOCAL_IP_CTRL13_m0_cfg_qos_reg6_2_END (10)
#define SOC_FCM_LOCAL_IP_CTRL13_m0_cfg_qos_reg6_3_START (12)
#define SOC_FCM_LOCAL_IP_CTRL13_m0_cfg_qos_reg6_3_END (14)
#define SOC_FCM_LOCAL_IP_CTRL13_m0_cfg_qos_reg6_4_START (16)
#define SOC_FCM_LOCAL_IP_CTRL13_m0_cfg_qos_reg6_4_END (18)
#define SOC_FCM_LOCAL_IP_CTRL13_m0_cfg_qos_reg6_5_START (20)
#define SOC_FCM_LOCAL_IP_CTRL13_m0_cfg_qos_reg6_5_END (22)
#define SOC_FCM_LOCAL_IP_CTRL13_m0_cfg_qos_reg6_6_START (24)
#define SOC_FCM_LOCAL_IP_CTRL13_m0_cfg_qos_reg6_6_END (26)
#define SOC_FCM_LOCAL_IP_CTRL13_m0_cfg_qos_reg6_7_START (28)
#define SOC_FCM_LOCAL_IP_CTRL13_m0_cfg_qos_reg6_7_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m0_cfg_qos_reg7_0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int m0_cfg_qos_reg7_1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int m0_cfg_qos_reg7_2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int m0_cfg_qos_reg7_3 : 3;
        unsigned int reserved_3 : 1;
        unsigned int m0_cfg_qos_reg7_4 : 3;
        unsigned int reserved_4 : 1;
        unsigned int m0_cfg_qos_reg7_5 : 3;
        unsigned int reserved_5 : 1;
        unsigned int m0_cfg_qos_reg7_6 : 3;
        unsigned int reserved_6 : 1;
        unsigned int m0_cfg_qos_reg7_7 : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL14_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL14_m0_cfg_qos_reg7_0_START (0)
#define SOC_FCM_LOCAL_IP_CTRL14_m0_cfg_qos_reg7_0_END (2)
#define SOC_FCM_LOCAL_IP_CTRL14_m0_cfg_qos_reg7_1_START (4)
#define SOC_FCM_LOCAL_IP_CTRL14_m0_cfg_qos_reg7_1_END (6)
#define SOC_FCM_LOCAL_IP_CTRL14_m0_cfg_qos_reg7_2_START (8)
#define SOC_FCM_LOCAL_IP_CTRL14_m0_cfg_qos_reg7_2_END (10)
#define SOC_FCM_LOCAL_IP_CTRL14_m0_cfg_qos_reg7_3_START (12)
#define SOC_FCM_LOCAL_IP_CTRL14_m0_cfg_qos_reg7_3_END (14)
#define SOC_FCM_LOCAL_IP_CTRL14_m0_cfg_qos_reg7_4_START (16)
#define SOC_FCM_LOCAL_IP_CTRL14_m0_cfg_qos_reg7_4_END (18)
#define SOC_FCM_LOCAL_IP_CTRL14_m0_cfg_qos_reg7_5_START (20)
#define SOC_FCM_LOCAL_IP_CTRL14_m0_cfg_qos_reg7_5_END (22)
#define SOC_FCM_LOCAL_IP_CTRL14_m0_cfg_qos_reg7_6_START (24)
#define SOC_FCM_LOCAL_IP_CTRL14_m0_cfg_qos_reg7_6_END (26)
#define SOC_FCM_LOCAL_IP_CTRL14_m0_cfg_qos_reg7_7_START (28)
#define SOC_FCM_LOCAL_IP_CTRL14_m0_cfg_qos_reg7_7_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pi_trace_int_unmask_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL16_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL16_pi_trace_int_unmask_en_START (0)
#define SOC_FCM_LOCAL_IP_CTRL16_pi_trace_int_unmask_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_l_process_monitor_cpu : 32;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL17_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL17_cfg_l_process_monitor_cpu_START (0)
#define SOC_FCM_LOCAL_IP_CTRL17_cfg_l_process_monitor_cpu_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_h_process_monitor_cpu : 32;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL18_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL18_cfg_h_process_monitor_cpu_START (0)
#define SOC_FCM_LOCAL_IP_CTRL18_cfg_h_process_monitor_cpu_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int en_process_monitor_cpu : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL19_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL19_en_process_monitor_cpu_START (0)
#define SOC_FCM_LOCAL_IP_CTRL19_en_process_monitor_cpu_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_l_process_monitor_cluster : 32;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL20_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL20_cfg_l_process_monitor_cluster_START (0)
#define SOC_FCM_LOCAL_IP_CTRL20_cfg_l_process_monitor_cluster_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_h_process_monitor_cluster : 32;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL21_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL21_cfg_h_process_monitor_cluster_START (0)
#define SOC_FCM_LOCAL_IP_CTRL21_cfg_h_process_monitor_cluster_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int en_process_monitor_cluster : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL22_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL22_en_process_monitor_cluster_START (0)
#define SOC_FCM_LOCAL_IP_CTRL22_en_process_monitor_cluster_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pi_trace_int_clr_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL24_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL24_pi_trace_int_clr_en_START (0)
#define SOC_FCM_LOCAL_IP_CTRL24_pi_trace_int_clr_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sel_cpm_flag : 3;
        unsigned int reserved_0 : 7;
        unsigned int sel_core_for_cnt_pi_flag : 2;
        unsigned int reserved_1 : 8;
        unsigned int cfg_flag_to_csys_etb_cnt : 5;
        unsigned int reserved_2 : 5;
        unsigned int cpm_flag_mask : 1;
        unsigned int didt_flag_mask : 1;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL26_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL26_sel_cpm_flag_START (0)
#define SOC_FCM_LOCAL_IP_CTRL26_sel_cpm_flag_END (2)
#define SOC_FCM_LOCAL_IP_CTRL26_sel_core_for_cnt_pi_flag_START (10)
#define SOC_FCM_LOCAL_IP_CTRL26_sel_core_for_cnt_pi_flag_END (11)
#define SOC_FCM_LOCAL_IP_CTRL26_cfg_flag_to_csys_etb_cnt_START (20)
#define SOC_FCM_LOCAL_IP_CTRL26_cfg_flag_to_csys_etb_cnt_END (24)
#define SOC_FCM_LOCAL_IP_CTRL26_cpm_flag_mask_START (30)
#define SOC_FCM_LOCAL_IP_CTRL26_cpm_flag_mask_END (30)
#define SOC_FCM_LOCAL_IP_CTRL26_didt_flag_mask_START (31)
#define SOC_FCM_LOCAL_IP_CTRL26_didt_flag_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clr_pi_flag_cnt : 1;
        unsigned int pi_trace_cfg_cnt_en : 1;
        unsigned int pi_trace_clean_cnt_en : 1;
        unsigned int fcm_rtm_cnt_over_clr : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL27_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL27_clr_pi_flag_cnt_START (0)
#define SOC_FCM_LOCAL_IP_CTRL27_clr_pi_flag_cnt_END (0)
#define SOC_FCM_LOCAL_IP_CTRL27_pi_trace_cfg_cnt_en_START (1)
#define SOC_FCM_LOCAL_IP_CTRL27_pi_trace_cfg_cnt_en_END (1)
#define SOC_FCM_LOCAL_IP_CTRL27_pi_trace_clean_cnt_en_START (2)
#define SOC_FCM_LOCAL_IP_CTRL27_pi_trace_clean_cnt_en_END (2)
#define SOC_FCM_LOCAL_IP_CTRL27_fcm_rtm_cnt_over_clr_START (3)
#define SOC_FCM_LOCAL_IP_CTRL27_fcm_rtm_cnt_over_clr_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pi_trace_cfg_cnt : 9;
        unsigned int pi_trace_backpress_en : 1;
        unsigned int l3_rtm_cnt_en : 12;
        unsigned int reserved : 5;
        unsigned int mask_flux_ctl : 5;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL28_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL28_pi_trace_cfg_cnt_START (0)
#define SOC_FCM_LOCAL_IP_CTRL28_pi_trace_cfg_cnt_END (8)
#define SOC_FCM_LOCAL_IP_CTRL28_pi_trace_backpress_en_START (9)
#define SOC_FCM_LOCAL_IP_CTRL28_pi_trace_backpress_en_END (9)
#define SOC_FCM_LOCAL_IP_CTRL28_l3_rtm_cnt_en_START (10)
#define SOC_FCM_LOCAL_IP_CTRL28_l3_rtm_cnt_en_END (21)
#define SOC_FCM_LOCAL_IP_CTRL28_mask_flux_ctl_START (27)
#define SOC_FCM_LOCAL_IP_CTRL28_mask_flux_ctl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sl2_rtm_glb_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL29_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL29_sl2_rtm_glb_en_START (0)
#define SOC_FCM_LOCAL_IP_CTRL29_sl2_rtm_glb_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sample_cfg_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL30_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL30_sample_cfg_en_START (0)
#define SOC_FCM_LOCAL_IP_CTRL30_sample_cfg_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core4_code_fix_freq : 8;
        unsigned int core4_code_value_consist : 1;
        unsigned int core4_rnd_sel : 3;
        unsigned int core4_wait_num_freq_cnt : 1;
        unsigned int core4_delta_50pct : 5;
        unsigned int core4_cnt_thr_50pct : 3;
        unsigned int core4_delta_ofset : 2;
        unsigned int core4_sum_tgt_ofset : 4;
        unsigned int core4_cnt_thr_ofset : 3;
        unsigned int core4_code_max_freq : 1;
        unsigned int core4_rosc_clk_chk_en : 1;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL31_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL31_core4_code_fix_freq_START (0)
#define SOC_FCM_LOCAL_IP_CTRL31_core4_code_fix_freq_END (7)
#define SOC_FCM_LOCAL_IP_CTRL31_core4_code_value_consist_START (8)
#define SOC_FCM_LOCAL_IP_CTRL31_core4_code_value_consist_END (8)
#define SOC_FCM_LOCAL_IP_CTRL31_core4_rnd_sel_START (9)
#define SOC_FCM_LOCAL_IP_CTRL31_core4_rnd_sel_END (11)
#define SOC_FCM_LOCAL_IP_CTRL31_core4_wait_num_freq_cnt_START (12)
#define SOC_FCM_LOCAL_IP_CTRL31_core4_wait_num_freq_cnt_END (12)
#define SOC_FCM_LOCAL_IP_CTRL31_core4_delta_50pct_START (13)
#define SOC_FCM_LOCAL_IP_CTRL31_core4_delta_50pct_END (17)
#define SOC_FCM_LOCAL_IP_CTRL31_core4_cnt_thr_50pct_START (18)
#define SOC_FCM_LOCAL_IP_CTRL31_core4_cnt_thr_50pct_END (20)
#define SOC_FCM_LOCAL_IP_CTRL31_core4_delta_ofset_START (21)
#define SOC_FCM_LOCAL_IP_CTRL31_core4_delta_ofset_END (22)
#define SOC_FCM_LOCAL_IP_CTRL31_core4_sum_tgt_ofset_START (23)
#define SOC_FCM_LOCAL_IP_CTRL31_core4_sum_tgt_ofset_END (26)
#define SOC_FCM_LOCAL_IP_CTRL31_core4_cnt_thr_ofset_START (27)
#define SOC_FCM_LOCAL_IP_CTRL31_core4_cnt_thr_ofset_END (29)
#define SOC_FCM_LOCAL_IP_CTRL31_core4_code_max_freq_START (30)
#define SOC_FCM_LOCAL_IP_CTRL31_core4_code_max_freq_END (30)
#define SOC_FCM_LOCAL_IP_CTRL31_core4_rosc_clk_chk_en_START (31)
#define SOC_FCM_LOCAL_IP_CTRL31_core4_rosc_clk_chk_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core4_tgt_val_freq : 4;
        unsigned int core4_flip_num_freq : 1;
        unsigned int core4_dcd_start_sft : 1;
        unsigned int core4_d2a_comp_clk_div_level : 1;
        unsigned int core4_clk_dcd_en : 1;
        unsigned int core4_div_phase4_pd : 1;
        unsigned int core4_clk_mux_cfg : 1;
        unsigned int core4_clk_div_en : 1;
        unsigned int core4_clk_mux_sel : 3;
        unsigned int core4_dcd_50pct_en : 1;
        unsigned int core4_chop_en : 1;
        unsigned int core4_dcd_ofst_en : 1;
        unsigned int core4_rosc_clk_en : 1;
        unsigned int core4_rosc_clk_test_en : 1;
        unsigned int core4_test_en : 1;
        unsigned int core4_test_div8_en : 1;
        unsigned int core4_test_sel : 3;
        unsigned int core4_cal_clk_test_en : 1;
        unsigned int core4_clk_mux_test_en : 1;
        unsigned int core4_clkp_dc_test_en : 1;
        unsigned int core4_clkn_dc_test_en : 1;
        unsigned int core4_vtest_en : 1;
        unsigned int core4_clk_phsel : 1;
        unsigned int core4_state_sel : 2;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL32_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL32_core4_tgt_val_freq_START (0)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_tgt_val_freq_END (3)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_flip_num_freq_START (4)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_flip_num_freq_END (4)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_dcd_start_sft_START (5)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_dcd_start_sft_END (5)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_d2a_comp_clk_div_level_START (6)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_d2a_comp_clk_div_level_END (6)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_clk_dcd_en_START (7)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_clk_dcd_en_END (7)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_div_phase4_pd_START (8)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_div_phase4_pd_END (8)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_clk_mux_cfg_START (9)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_clk_mux_cfg_END (9)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_clk_div_en_START (10)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_clk_div_en_END (10)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_clk_mux_sel_START (11)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_clk_mux_sel_END (13)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_dcd_50pct_en_START (14)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_dcd_50pct_en_END (14)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_chop_en_START (15)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_chop_en_END (15)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_dcd_ofst_en_START (16)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_dcd_ofst_en_END (16)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_rosc_clk_en_START (17)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_rosc_clk_en_END (17)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_rosc_clk_test_en_START (18)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_rosc_clk_test_en_END (18)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_test_en_START (19)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_test_en_END (19)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_test_div8_en_START (20)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_test_div8_en_END (20)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_test_sel_START (21)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_test_sel_END (23)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_cal_clk_test_en_START (24)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_cal_clk_test_en_END (24)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_clk_mux_test_en_START (25)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_clk_mux_test_en_END (25)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_clkp_dc_test_en_START (26)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_clkp_dc_test_en_END (26)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_clkn_dc_test_en_START (27)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_clkn_dc_test_en_END (27)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_vtest_en_START (28)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_vtest_en_END (28)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_clk_phsel_START (29)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_clk_phsel_END (29)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_state_sel_START (30)
#define SOC_FCM_LOCAL_IP_CTRL32_core4_state_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core5_core5_code_fix_freq : 8;
        unsigned int core5_core5_code_value_consist : 1;
        unsigned int core5_core5_rnd_sel : 3;
        unsigned int core5_core5_wait_num_freq_cnt : 1;
        unsigned int core5_core5_delta_50pct : 5;
        unsigned int core5_core5_cnt_thr_50pct : 3;
        unsigned int core5_core5_delta_ofset : 2;
        unsigned int core5_core5_sum_tgt_ofset : 4;
        unsigned int core5_core5_cnt_thr_ofset : 3;
        unsigned int core5_core5_code_max_freq : 1;
        unsigned int core5_core5_rosc_clk_chk_en : 1;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL33_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL33_core5_core5_code_fix_freq_START (0)
#define SOC_FCM_LOCAL_IP_CTRL33_core5_core5_code_fix_freq_END (7)
#define SOC_FCM_LOCAL_IP_CTRL33_core5_core5_code_value_consist_START (8)
#define SOC_FCM_LOCAL_IP_CTRL33_core5_core5_code_value_consist_END (8)
#define SOC_FCM_LOCAL_IP_CTRL33_core5_core5_rnd_sel_START (9)
#define SOC_FCM_LOCAL_IP_CTRL33_core5_core5_rnd_sel_END (11)
#define SOC_FCM_LOCAL_IP_CTRL33_core5_core5_wait_num_freq_cnt_START (12)
#define SOC_FCM_LOCAL_IP_CTRL33_core5_core5_wait_num_freq_cnt_END (12)
#define SOC_FCM_LOCAL_IP_CTRL33_core5_core5_delta_50pct_START (13)
#define SOC_FCM_LOCAL_IP_CTRL33_core5_core5_delta_50pct_END (17)
#define SOC_FCM_LOCAL_IP_CTRL33_core5_core5_cnt_thr_50pct_START (18)
#define SOC_FCM_LOCAL_IP_CTRL33_core5_core5_cnt_thr_50pct_END (20)
#define SOC_FCM_LOCAL_IP_CTRL33_core5_core5_delta_ofset_START (21)
#define SOC_FCM_LOCAL_IP_CTRL33_core5_core5_delta_ofset_END (22)
#define SOC_FCM_LOCAL_IP_CTRL33_core5_core5_sum_tgt_ofset_START (23)
#define SOC_FCM_LOCAL_IP_CTRL33_core5_core5_sum_tgt_ofset_END (26)
#define SOC_FCM_LOCAL_IP_CTRL33_core5_core5_cnt_thr_ofset_START (27)
#define SOC_FCM_LOCAL_IP_CTRL33_core5_core5_cnt_thr_ofset_END (29)
#define SOC_FCM_LOCAL_IP_CTRL33_core5_core5_code_max_freq_START (30)
#define SOC_FCM_LOCAL_IP_CTRL33_core5_core5_code_max_freq_END (30)
#define SOC_FCM_LOCAL_IP_CTRL33_core5_core5_rosc_clk_chk_en_START (31)
#define SOC_FCM_LOCAL_IP_CTRL33_core5_core5_rosc_clk_chk_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core5_tgt_val_freq : 4;
        unsigned int core5_flip_num_freq : 1;
        unsigned int core5_dcd_start_sft : 1;
        unsigned int core5_d2a_comp_clk_div_level : 1;
        unsigned int core5_clk_dcd_en : 1;
        unsigned int core5_div_phase4_pd : 1;
        unsigned int core5_clk_mux_cfg : 1;
        unsigned int core5_clk_div_en : 1;
        unsigned int core5_clk_mux_sel : 3;
        unsigned int core5_dcd_50pct_en : 1;
        unsigned int core5_chop_en : 1;
        unsigned int core5_dcd_ofst_en : 1;
        unsigned int core5_rosc_clk_en : 1;
        unsigned int core5_rosc_clk_test_en : 1;
        unsigned int core5_test_en : 1;
        unsigned int core5_test_div8_en : 1;
        unsigned int core5_test_sel : 3;
        unsigned int core5_cal_clk_test_en : 1;
        unsigned int core5_clk_mux_test_en : 1;
        unsigned int core5_clkp_dc_test_en : 1;
        unsigned int core5_clkn_dc_test_en : 1;
        unsigned int core5_vtest_en : 1;
        unsigned int core5_clk_phsel : 1;
        unsigned int core5_state_sel : 2;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL34_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL34_core5_tgt_val_freq_START (0)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_tgt_val_freq_END (3)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_flip_num_freq_START (4)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_flip_num_freq_END (4)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_dcd_start_sft_START (5)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_dcd_start_sft_END (5)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_d2a_comp_clk_div_level_START (6)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_d2a_comp_clk_div_level_END (6)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_clk_dcd_en_START (7)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_clk_dcd_en_END (7)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_div_phase4_pd_START (8)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_div_phase4_pd_END (8)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_clk_mux_cfg_START (9)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_clk_mux_cfg_END (9)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_clk_div_en_START (10)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_clk_div_en_END (10)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_clk_mux_sel_START (11)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_clk_mux_sel_END (13)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_dcd_50pct_en_START (14)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_dcd_50pct_en_END (14)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_chop_en_START (15)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_chop_en_END (15)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_dcd_ofst_en_START (16)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_dcd_ofst_en_END (16)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_rosc_clk_en_START (17)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_rosc_clk_en_END (17)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_rosc_clk_test_en_START (18)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_rosc_clk_test_en_END (18)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_test_en_START (19)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_test_en_END (19)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_test_div8_en_START (20)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_test_div8_en_END (20)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_test_sel_START (21)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_test_sel_END (23)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_cal_clk_test_en_START (24)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_cal_clk_test_en_END (24)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_clk_mux_test_en_START (25)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_clk_mux_test_en_END (25)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_clkp_dc_test_en_START (26)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_clkp_dc_test_en_END (26)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_clkn_dc_test_en_START (27)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_clkn_dc_test_en_END (27)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_vtest_en_START (28)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_vtest_en_END (28)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_clk_phsel_START (29)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_clk_phsel_END (29)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_state_sel_START (30)
#define SOC_FCM_LOCAL_IP_CTRL34_core5_state_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core6_code_fix_freq : 8;
        unsigned int core6_code_value_consist : 1;
        unsigned int core6_rnd_sel : 3;
        unsigned int core6_wait_num_freq_cnt : 1;
        unsigned int core6_delta_50pct : 5;
        unsigned int core6_cnt_thr_50pct : 3;
        unsigned int core6_delta_ofset : 2;
        unsigned int core6_sum_tgt_ofset : 4;
        unsigned int core6_cnt_thr_ofset : 3;
        unsigned int core6_code_max_freq : 1;
        unsigned int core6_rosc_clk_chk_en : 1;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL35_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL35_core6_code_fix_freq_START (0)
#define SOC_FCM_LOCAL_IP_CTRL35_core6_code_fix_freq_END (7)
#define SOC_FCM_LOCAL_IP_CTRL35_core6_code_value_consist_START (8)
#define SOC_FCM_LOCAL_IP_CTRL35_core6_code_value_consist_END (8)
#define SOC_FCM_LOCAL_IP_CTRL35_core6_rnd_sel_START (9)
#define SOC_FCM_LOCAL_IP_CTRL35_core6_rnd_sel_END (11)
#define SOC_FCM_LOCAL_IP_CTRL35_core6_wait_num_freq_cnt_START (12)
#define SOC_FCM_LOCAL_IP_CTRL35_core6_wait_num_freq_cnt_END (12)
#define SOC_FCM_LOCAL_IP_CTRL35_core6_delta_50pct_START (13)
#define SOC_FCM_LOCAL_IP_CTRL35_core6_delta_50pct_END (17)
#define SOC_FCM_LOCAL_IP_CTRL35_core6_cnt_thr_50pct_START (18)
#define SOC_FCM_LOCAL_IP_CTRL35_core6_cnt_thr_50pct_END (20)
#define SOC_FCM_LOCAL_IP_CTRL35_core6_delta_ofset_START (21)
#define SOC_FCM_LOCAL_IP_CTRL35_core6_delta_ofset_END (22)
#define SOC_FCM_LOCAL_IP_CTRL35_core6_sum_tgt_ofset_START (23)
#define SOC_FCM_LOCAL_IP_CTRL35_core6_sum_tgt_ofset_END (26)
#define SOC_FCM_LOCAL_IP_CTRL35_core6_cnt_thr_ofset_START (27)
#define SOC_FCM_LOCAL_IP_CTRL35_core6_cnt_thr_ofset_END (29)
#define SOC_FCM_LOCAL_IP_CTRL35_core6_code_max_freq_START (30)
#define SOC_FCM_LOCAL_IP_CTRL35_core6_code_max_freq_END (30)
#define SOC_FCM_LOCAL_IP_CTRL35_core6_rosc_clk_chk_en_START (31)
#define SOC_FCM_LOCAL_IP_CTRL35_core6_rosc_clk_chk_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core6_tgt_val_freq : 4;
        unsigned int core6_flip_num_freq : 1;
        unsigned int core6_dcd_start_sft : 1;
        unsigned int core6_d2a_comp_clk_div_level : 1;
        unsigned int core6_clk_dcd_en : 1;
        unsigned int core6_div_phase4_pd : 1;
        unsigned int core6_clk_mux_cfg : 1;
        unsigned int core6_clk_div_en : 1;
        unsigned int core6_clk_mux_sel : 3;
        unsigned int core6_dcd_50pct_en : 1;
        unsigned int core6_chop_en : 1;
        unsigned int core6_dcd_ofst_en : 1;
        unsigned int core6_rosc_clk_en : 1;
        unsigned int core6_rosc_clk_test_en : 1;
        unsigned int core6_test_en : 1;
        unsigned int core6_test_div8_en : 1;
        unsigned int core6_test_sel : 3;
        unsigned int core6_cal_clk_test_en : 1;
        unsigned int core6_clk_mux_test_en : 1;
        unsigned int core6_clkp_dc_test_en : 1;
        unsigned int core6_clkn_dc_test_en : 1;
        unsigned int core6_vtest_en : 1;
        unsigned int core6_clk_phsel : 1;
        unsigned int core6_state_sel : 2;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL36_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL36_core6_tgt_val_freq_START (0)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_tgt_val_freq_END (3)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_flip_num_freq_START (4)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_flip_num_freq_END (4)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_dcd_start_sft_START (5)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_dcd_start_sft_END (5)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_d2a_comp_clk_div_level_START (6)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_d2a_comp_clk_div_level_END (6)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_clk_dcd_en_START (7)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_clk_dcd_en_END (7)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_div_phase4_pd_START (8)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_div_phase4_pd_END (8)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_clk_mux_cfg_START (9)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_clk_mux_cfg_END (9)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_clk_div_en_START (10)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_clk_div_en_END (10)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_clk_mux_sel_START (11)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_clk_mux_sel_END (13)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_dcd_50pct_en_START (14)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_dcd_50pct_en_END (14)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_chop_en_START (15)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_chop_en_END (15)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_dcd_ofst_en_START (16)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_dcd_ofst_en_END (16)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_rosc_clk_en_START (17)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_rosc_clk_en_END (17)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_rosc_clk_test_en_START (18)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_rosc_clk_test_en_END (18)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_test_en_START (19)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_test_en_END (19)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_test_div8_en_START (20)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_test_div8_en_END (20)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_test_sel_START (21)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_test_sel_END (23)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_cal_clk_test_en_START (24)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_cal_clk_test_en_END (24)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_clk_mux_test_en_START (25)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_clk_mux_test_en_END (25)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_clkp_dc_test_en_START (26)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_clkp_dc_test_en_END (26)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_clkn_dc_test_en_START (27)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_clkn_dc_test_en_END (27)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_vtest_en_START (28)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_vtest_en_END (28)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_clk_phsel_START (29)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_clk_phsel_END (29)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_state_sel_START (30)
#define SOC_FCM_LOCAL_IP_CTRL36_core6_state_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core7_code_fix_freq : 8;
        unsigned int core7_code_value_consist : 1;
        unsigned int core7_rnd_sel : 3;
        unsigned int core7_wait_num_freq_cnt : 1;
        unsigned int core7_delta_50pct : 5;
        unsigned int core7_cnt_thr_50pct : 3;
        unsigned int core7_delta_ofset : 2;
        unsigned int core7_sum_tgt_ofset : 4;
        unsigned int core7_cnt_thr_ofset : 3;
        unsigned int core7_code_max_freq : 1;
        unsigned int core7_rosc_clk_chk_en : 1;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL37_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL37_core7_code_fix_freq_START (0)
#define SOC_FCM_LOCAL_IP_CTRL37_core7_code_fix_freq_END (7)
#define SOC_FCM_LOCAL_IP_CTRL37_core7_code_value_consist_START (8)
#define SOC_FCM_LOCAL_IP_CTRL37_core7_code_value_consist_END (8)
#define SOC_FCM_LOCAL_IP_CTRL37_core7_rnd_sel_START (9)
#define SOC_FCM_LOCAL_IP_CTRL37_core7_rnd_sel_END (11)
#define SOC_FCM_LOCAL_IP_CTRL37_core7_wait_num_freq_cnt_START (12)
#define SOC_FCM_LOCAL_IP_CTRL37_core7_wait_num_freq_cnt_END (12)
#define SOC_FCM_LOCAL_IP_CTRL37_core7_delta_50pct_START (13)
#define SOC_FCM_LOCAL_IP_CTRL37_core7_delta_50pct_END (17)
#define SOC_FCM_LOCAL_IP_CTRL37_core7_cnt_thr_50pct_START (18)
#define SOC_FCM_LOCAL_IP_CTRL37_core7_cnt_thr_50pct_END (20)
#define SOC_FCM_LOCAL_IP_CTRL37_core7_delta_ofset_START (21)
#define SOC_FCM_LOCAL_IP_CTRL37_core7_delta_ofset_END (22)
#define SOC_FCM_LOCAL_IP_CTRL37_core7_sum_tgt_ofset_START (23)
#define SOC_FCM_LOCAL_IP_CTRL37_core7_sum_tgt_ofset_END (26)
#define SOC_FCM_LOCAL_IP_CTRL37_core7_cnt_thr_ofset_START (27)
#define SOC_FCM_LOCAL_IP_CTRL37_core7_cnt_thr_ofset_END (29)
#define SOC_FCM_LOCAL_IP_CTRL37_core7_code_max_freq_START (30)
#define SOC_FCM_LOCAL_IP_CTRL37_core7_code_max_freq_END (30)
#define SOC_FCM_LOCAL_IP_CTRL37_core7_rosc_clk_chk_en_START (31)
#define SOC_FCM_LOCAL_IP_CTRL37_core7_rosc_clk_chk_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core7_tgt_val_freq : 4;
        unsigned int core7_flip_num_freq : 1;
        unsigned int core7_dcd_start_sft : 1;
        unsigned int core7_d2a_comp_clk_div_level : 1;
        unsigned int core7_clk_dcd_en : 1;
        unsigned int core7_div_phase4_pd : 1;
        unsigned int core7_clk_mux_cfg : 1;
        unsigned int core7_clk_div_en : 1;
        unsigned int core7_clk_mux_sel : 3;
        unsigned int core7_dcd_50pct_en : 1;
        unsigned int core7_chop_en : 1;
        unsigned int core7_dcd_ofst_en : 1;
        unsigned int core7_rosc_clk_en : 1;
        unsigned int core7_rosc_clk_test_en : 1;
        unsigned int core7_test_en : 1;
        unsigned int core7_test_div8_en : 1;
        unsigned int core7_test_sel : 3;
        unsigned int core7_cal_clk_test_en : 1;
        unsigned int core7_clk_mux_test_en : 1;
        unsigned int core7_clkp_dc_test_en : 1;
        unsigned int core7_clkn_dc_test_en : 1;
        unsigned int core7_vtest_en : 1;
        unsigned int core7_clk_phsel : 1;
        unsigned int core7_state_sel : 2;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL38_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL38_core7_tgt_val_freq_START (0)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_tgt_val_freq_END (3)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_flip_num_freq_START (4)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_flip_num_freq_END (4)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_dcd_start_sft_START (5)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_dcd_start_sft_END (5)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_d2a_comp_clk_div_level_START (6)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_d2a_comp_clk_div_level_END (6)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_clk_dcd_en_START (7)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_clk_dcd_en_END (7)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_div_phase4_pd_START (8)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_div_phase4_pd_END (8)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_clk_mux_cfg_START (9)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_clk_mux_cfg_END (9)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_clk_div_en_START (10)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_clk_div_en_END (10)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_clk_mux_sel_START (11)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_clk_mux_sel_END (13)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_dcd_50pct_en_START (14)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_dcd_50pct_en_END (14)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_chop_en_START (15)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_chop_en_END (15)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_dcd_ofst_en_START (16)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_dcd_ofst_en_END (16)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_rosc_clk_en_START (17)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_rosc_clk_en_END (17)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_rosc_clk_test_en_START (18)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_rosc_clk_test_en_END (18)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_test_en_START (19)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_test_en_END (19)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_test_div8_en_START (20)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_test_div8_en_END (20)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_test_sel_START (21)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_test_sel_END (23)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_cal_clk_test_en_START (24)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_cal_clk_test_en_END (24)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_clk_mux_test_en_START (25)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_clk_mux_test_en_END (25)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_clkp_dc_test_en_START (26)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_clkp_dc_test_en_END (26)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_clkn_dc_test_en_START (27)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_clkn_dc_test_en_END (27)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_vtest_en_START (28)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_vtest_en_END (28)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_clk_phsel_START (29)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_clk_phsel_END (29)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_state_sel_START (30)
#define SOC_FCM_LOCAL_IP_CTRL38_core7_state_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core8_0_code_fix_freq : 8;
        unsigned int core8_0_code_value_consist : 1;
        unsigned int core8_0_rnd_sel : 3;
        unsigned int core8_0_wait_num_freq_cnt : 1;
        unsigned int core8_0_delta_50pct : 5;
        unsigned int core8_0_cnt_thr_50pct : 3;
        unsigned int core8_0_delta_ofset : 2;
        unsigned int core8_0_sum_tgt_ofset : 4;
        unsigned int core8_0_cnt_thr_ofset : 3;
        unsigned int core8_0_code_max_freq : 1;
        unsigned int core8_0_rosc_clk_chk_en : 1;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL39_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL39_core8_0_code_fix_freq_START (0)
#define SOC_FCM_LOCAL_IP_CTRL39_core8_0_code_fix_freq_END (7)
#define SOC_FCM_LOCAL_IP_CTRL39_core8_0_code_value_consist_START (8)
#define SOC_FCM_LOCAL_IP_CTRL39_core8_0_code_value_consist_END (8)
#define SOC_FCM_LOCAL_IP_CTRL39_core8_0_rnd_sel_START (9)
#define SOC_FCM_LOCAL_IP_CTRL39_core8_0_rnd_sel_END (11)
#define SOC_FCM_LOCAL_IP_CTRL39_core8_0_wait_num_freq_cnt_START (12)
#define SOC_FCM_LOCAL_IP_CTRL39_core8_0_wait_num_freq_cnt_END (12)
#define SOC_FCM_LOCAL_IP_CTRL39_core8_0_delta_50pct_START (13)
#define SOC_FCM_LOCAL_IP_CTRL39_core8_0_delta_50pct_END (17)
#define SOC_FCM_LOCAL_IP_CTRL39_core8_0_cnt_thr_50pct_START (18)
#define SOC_FCM_LOCAL_IP_CTRL39_core8_0_cnt_thr_50pct_END (20)
#define SOC_FCM_LOCAL_IP_CTRL39_core8_0_delta_ofset_START (21)
#define SOC_FCM_LOCAL_IP_CTRL39_core8_0_delta_ofset_END (22)
#define SOC_FCM_LOCAL_IP_CTRL39_core8_0_sum_tgt_ofset_START (23)
#define SOC_FCM_LOCAL_IP_CTRL39_core8_0_sum_tgt_ofset_END (26)
#define SOC_FCM_LOCAL_IP_CTRL39_core8_0_cnt_thr_ofset_START (27)
#define SOC_FCM_LOCAL_IP_CTRL39_core8_0_cnt_thr_ofset_END (29)
#define SOC_FCM_LOCAL_IP_CTRL39_core8_0_code_max_freq_START (30)
#define SOC_FCM_LOCAL_IP_CTRL39_core8_0_code_max_freq_END (30)
#define SOC_FCM_LOCAL_IP_CTRL39_core8_0_rosc_clk_chk_en_START (31)
#define SOC_FCM_LOCAL_IP_CTRL39_core8_0_rosc_clk_chk_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core8_0_tgt_val_freq : 4;
        unsigned int core8_0_flip_num_freq : 1;
        unsigned int core8_0_dcd_start_sft : 1;
        unsigned int core8_0_d2a_comp_clk_div_level : 1;
        unsigned int core8_0_clk_dcd_en : 1;
        unsigned int core8_0_div_phase4_pd : 1;
        unsigned int core8_0_clk_mux_cfg : 1;
        unsigned int core8_0_clk_div_en : 1;
        unsigned int core8_0_clk_mux_sel : 3;
        unsigned int core8_0_dcd_50pct_en : 1;
        unsigned int core8_0_chop_en : 1;
        unsigned int core8_0_dcd_ofst_en : 1;
        unsigned int core8_0_rosc_clk_en : 1;
        unsigned int core8_0_rosc_clk_test_en : 1;
        unsigned int core8_0_test_en : 1;
        unsigned int core8_0_test_div8_en : 1;
        unsigned int core8_0_test_sel : 3;
        unsigned int core8_0_cal_clk_test_en : 1;
        unsigned int core8_0_clk_mux_test_en : 1;
        unsigned int core8_0_clkp_dc_test_en : 1;
        unsigned int core8_0_clkn_dc_test_en : 1;
        unsigned int core8_0_vtest_en : 1;
        unsigned int core8_0_clk_phsel : 1;
        unsigned int core8_0_state_sel : 2;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL40_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_tgt_val_freq_START (0)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_tgt_val_freq_END (3)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_flip_num_freq_START (4)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_flip_num_freq_END (4)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_dcd_start_sft_START (5)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_dcd_start_sft_END (5)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_d2a_comp_clk_div_level_START (6)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_d2a_comp_clk_div_level_END (6)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_clk_dcd_en_START (7)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_clk_dcd_en_END (7)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_div_phase4_pd_START (8)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_div_phase4_pd_END (8)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_clk_mux_cfg_START (9)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_clk_mux_cfg_END (9)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_clk_div_en_START (10)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_clk_div_en_END (10)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_clk_mux_sel_START (11)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_clk_mux_sel_END (13)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_dcd_50pct_en_START (14)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_dcd_50pct_en_END (14)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_chop_en_START (15)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_chop_en_END (15)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_dcd_ofst_en_START (16)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_dcd_ofst_en_END (16)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_rosc_clk_en_START (17)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_rosc_clk_en_END (17)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_rosc_clk_test_en_START (18)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_rosc_clk_test_en_END (18)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_test_en_START (19)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_test_en_END (19)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_test_div8_en_START (20)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_test_div8_en_END (20)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_test_sel_START (21)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_test_sel_END (23)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_cal_clk_test_en_START (24)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_cal_clk_test_en_END (24)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_clk_mux_test_en_START (25)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_clk_mux_test_en_END (25)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_clkp_dc_test_en_START (26)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_clkp_dc_test_en_END (26)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_clkn_dc_test_en_START (27)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_clkn_dc_test_en_END (27)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_vtest_en_START (28)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_vtest_en_END (28)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_clk_phsel_START (29)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_clk_phsel_END (29)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_state_sel_START (30)
#define SOC_FCM_LOCAL_IP_CTRL40_core8_0_state_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core8_1_code_fix_freq : 8;
        unsigned int core8_1_code_value_consist : 1;
        unsigned int core8_1_rnd_sel : 3;
        unsigned int core8_1_wait_num_freq_cnt : 1;
        unsigned int core8_1_delta_50pct : 5;
        unsigned int core8_1_cnt_thr_50pct : 3;
        unsigned int core8_1_delta_ofset : 2;
        unsigned int core8_1_sum_tgt_ofset : 4;
        unsigned int core8_1_cnt_thr_ofset : 3;
        unsigned int core8_1_code_max_freq : 1;
        unsigned int core8_1_rosc_clk_chk_en : 1;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL41_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL41_core8_1_code_fix_freq_START (0)
#define SOC_FCM_LOCAL_IP_CTRL41_core8_1_code_fix_freq_END (7)
#define SOC_FCM_LOCAL_IP_CTRL41_core8_1_code_value_consist_START (8)
#define SOC_FCM_LOCAL_IP_CTRL41_core8_1_code_value_consist_END (8)
#define SOC_FCM_LOCAL_IP_CTRL41_core8_1_rnd_sel_START (9)
#define SOC_FCM_LOCAL_IP_CTRL41_core8_1_rnd_sel_END (11)
#define SOC_FCM_LOCAL_IP_CTRL41_core8_1_wait_num_freq_cnt_START (12)
#define SOC_FCM_LOCAL_IP_CTRL41_core8_1_wait_num_freq_cnt_END (12)
#define SOC_FCM_LOCAL_IP_CTRL41_core8_1_delta_50pct_START (13)
#define SOC_FCM_LOCAL_IP_CTRL41_core8_1_delta_50pct_END (17)
#define SOC_FCM_LOCAL_IP_CTRL41_core8_1_cnt_thr_50pct_START (18)
#define SOC_FCM_LOCAL_IP_CTRL41_core8_1_cnt_thr_50pct_END (20)
#define SOC_FCM_LOCAL_IP_CTRL41_core8_1_delta_ofset_START (21)
#define SOC_FCM_LOCAL_IP_CTRL41_core8_1_delta_ofset_END (22)
#define SOC_FCM_LOCAL_IP_CTRL41_core8_1_sum_tgt_ofset_START (23)
#define SOC_FCM_LOCAL_IP_CTRL41_core8_1_sum_tgt_ofset_END (26)
#define SOC_FCM_LOCAL_IP_CTRL41_core8_1_cnt_thr_ofset_START (27)
#define SOC_FCM_LOCAL_IP_CTRL41_core8_1_cnt_thr_ofset_END (29)
#define SOC_FCM_LOCAL_IP_CTRL41_core8_1_code_max_freq_START (30)
#define SOC_FCM_LOCAL_IP_CTRL41_core8_1_code_max_freq_END (30)
#define SOC_FCM_LOCAL_IP_CTRL41_core8_1_rosc_clk_chk_en_START (31)
#define SOC_FCM_LOCAL_IP_CTRL41_core8_1_rosc_clk_chk_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core8_1_tgt_val_freq : 4;
        unsigned int core8_1_flip_num_freq : 1;
        unsigned int core8_1_dcd_start_sft : 1;
        unsigned int core8_1_d2a_comp_clk_div_level : 1;
        unsigned int core8_1_clk_dcd_en : 1;
        unsigned int core8_1_div_phase4_pd : 1;
        unsigned int core8_1_clk_mux_cfg : 1;
        unsigned int core8_1_clk_div_en : 1;
        unsigned int core8_1_clk_mux_sel : 3;
        unsigned int core8_1_dcd_50pct_en : 1;
        unsigned int core8_1_chop_en : 1;
        unsigned int core8_1_dcd_ofst_en : 1;
        unsigned int core8_1_rosc_clk_en : 1;
        unsigned int core8_1_rosc_clk_test_en : 1;
        unsigned int core8_1_test_en : 1;
        unsigned int core8_1_test_div8_en : 1;
        unsigned int core8_1_test_sel : 3;
        unsigned int core8_1_cal_clk_test_en : 1;
        unsigned int core8_1_clk_mux_test_en : 1;
        unsigned int core8_1_clkp_dc_test_en : 1;
        unsigned int core8_1_clkn_dc_test_en : 1;
        unsigned int core8_1_vtest_en : 1;
        unsigned int core8_1_clk_phsel : 1;
        unsigned int core8_1_state_sel : 2;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL42_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_tgt_val_freq_START (0)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_tgt_val_freq_END (3)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_flip_num_freq_START (4)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_flip_num_freq_END (4)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_dcd_start_sft_START (5)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_dcd_start_sft_END (5)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_d2a_comp_clk_div_level_START (6)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_d2a_comp_clk_div_level_END (6)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_clk_dcd_en_START (7)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_clk_dcd_en_END (7)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_div_phase4_pd_START (8)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_div_phase4_pd_END (8)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_clk_mux_cfg_START (9)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_clk_mux_cfg_END (9)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_clk_div_en_START (10)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_clk_div_en_END (10)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_clk_mux_sel_START (11)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_clk_mux_sel_END (13)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_dcd_50pct_en_START (14)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_dcd_50pct_en_END (14)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_chop_en_START (15)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_chop_en_END (15)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_dcd_ofst_en_START (16)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_dcd_ofst_en_END (16)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_rosc_clk_en_START (17)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_rosc_clk_en_END (17)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_rosc_clk_test_en_START (18)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_rosc_clk_test_en_END (18)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_test_en_START (19)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_test_en_END (19)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_test_div8_en_START (20)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_test_div8_en_END (20)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_test_sel_START (21)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_test_sel_END (23)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_cal_clk_test_en_START (24)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_cal_clk_test_en_END (24)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_clk_mux_test_en_START (25)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_clk_mux_test_en_END (25)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_clkp_dc_test_en_START (26)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_clkp_dc_test_en_END (26)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_clkn_dc_test_en_START (27)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_clkn_dc_test_en_END (27)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_vtest_en_START (28)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_vtest_en_END (28)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_clk_phsel_START (29)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_clk_phsel_END (29)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_state_sel_START (30)
#define SOC_FCM_LOCAL_IP_CTRL42_core8_1_state_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core8_2_code_fix_freq : 8;
        unsigned int core8_2_code_value_consist : 1;
        unsigned int core8_2_rnd_sel : 3;
        unsigned int core8_2_wait_num_freq_cnt : 1;
        unsigned int core8_2_delta_50pct : 5;
        unsigned int core8_2_cnt_thr_50pct : 3;
        unsigned int core8_2_delta_ofset : 2;
        unsigned int core8_2_sum_tgt_ofset : 4;
        unsigned int core8_2_cnt_thr_ofset : 3;
        unsigned int core8_2_code_max_freq : 1;
        unsigned int core8_2_rosc_clk_chk_en : 1;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL43_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL43_core8_2_code_fix_freq_START (0)
#define SOC_FCM_LOCAL_IP_CTRL43_core8_2_code_fix_freq_END (7)
#define SOC_FCM_LOCAL_IP_CTRL43_core8_2_code_value_consist_START (8)
#define SOC_FCM_LOCAL_IP_CTRL43_core8_2_code_value_consist_END (8)
#define SOC_FCM_LOCAL_IP_CTRL43_core8_2_rnd_sel_START (9)
#define SOC_FCM_LOCAL_IP_CTRL43_core8_2_rnd_sel_END (11)
#define SOC_FCM_LOCAL_IP_CTRL43_core8_2_wait_num_freq_cnt_START (12)
#define SOC_FCM_LOCAL_IP_CTRL43_core8_2_wait_num_freq_cnt_END (12)
#define SOC_FCM_LOCAL_IP_CTRL43_core8_2_delta_50pct_START (13)
#define SOC_FCM_LOCAL_IP_CTRL43_core8_2_delta_50pct_END (17)
#define SOC_FCM_LOCAL_IP_CTRL43_core8_2_cnt_thr_50pct_START (18)
#define SOC_FCM_LOCAL_IP_CTRL43_core8_2_cnt_thr_50pct_END (20)
#define SOC_FCM_LOCAL_IP_CTRL43_core8_2_delta_ofset_START (21)
#define SOC_FCM_LOCAL_IP_CTRL43_core8_2_delta_ofset_END (22)
#define SOC_FCM_LOCAL_IP_CTRL43_core8_2_sum_tgt_ofset_START (23)
#define SOC_FCM_LOCAL_IP_CTRL43_core8_2_sum_tgt_ofset_END (26)
#define SOC_FCM_LOCAL_IP_CTRL43_core8_2_cnt_thr_ofset_START (27)
#define SOC_FCM_LOCAL_IP_CTRL43_core8_2_cnt_thr_ofset_END (29)
#define SOC_FCM_LOCAL_IP_CTRL43_core8_2_code_max_freq_START (30)
#define SOC_FCM_LOCAL_IP_CTRL43_core8_2_code_max_freq_END (30)
#define SOC_FCM_LOCAL_IP_CTRL43_core8_2_rosc_clk_chk_en_START (31)
#define SOC_FCM_LOCAL_IP_CTRL43_core8_2_rosc_clk_chk_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core8_2_tgt_val_freq : 4;
        unsigned int core8_2_flip_num_freq : 1;
        unsigned int core8_2_dcd_start_sft : 1;
        unsigned int core8_2_d2a_comp_clk_div_level : 1;
        unsigned int core8_2_clk_dcd_en : 1;
        unsigned int core8_2_div_phase4_pd : 1;
        unsigned int core8_2_clk_mux_cfg : 1;
        unsigned int core8_2_clk_div_en : 1;
        unsigned int core8_2_clk_mux_sel : 3;
        unsigned int core8_2_dcd_50pct_en : 1;
        unsigned int core8_2_chop_en : 1;
        unsigned int core8_2_dcd_ofst_en : 1;
        unsigned int core8_2_rosc_clk_en : 1;
        unsigned int core8_2_rosc_clk_test_en : 1;
        unsigned int core8_2_test_en : 1;
        unsigned int core8_2_test_div8_en : 1;
        unsigned int core8_2_test_sel : 3;
        unsigned int core8_2_cal_clk_test_en : 1;
        unsigned int core8_2_clk_mux_test_en : 1;
        unsigned int core8_2_clkp_dc_test_en : 1;
        unsigned int core8_2_clkn_dc_test_en : 1;
        unsigned int core8_2_vtest_en : 1;
        unsigned int core8_2_clk_phsel : 1;
        unsigned int core8_2_state_sel : 2;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL44_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_tgt_val_freq_START (0)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_tgt_val_freq_END (3)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_flip_num_freq_START (4)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_flip_num_freq_END (4)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_dcd_start_sft_START (5)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_dcd_start_sft_END (5)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_d2a_comp_clk_div_level_START (6)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_d2a_comp_clk_div_level_END (6)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_clk_dcd_en_START (7)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_clk_dcd_en_END (7)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_div_phase4_pd_START (8)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_div_phase4_pd_END (8)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_clk_mux_cfg_START (9)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_clk_mux_cfg_END (9)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_clk_div_en_START (10)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_clk_div_en_END (10)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_clk_mux_sel_START (11)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_clk_mux_sel_END (13)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_dcd_50pct_en_START (14)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_dcd_50pct_en_END (14)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_chop_en_START (15)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_chop_en_END (15)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_dcd_ofst_en_START (16)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_dcd_ofst_en_END (16)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_rosc_clk_en_START (17)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_rosc_clk_en_END (17)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_rosc_clk_test_en_START (18)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_rosc_clk_test_en_END (18)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_test_en_START (19)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_test_en_END (19)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_test_div8_en_START (20)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_test_div8_en_END (20)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_test_sel_START (21)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_test_sel_END (23)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_cal_clk_test_en_START (24)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_cal_clk_test_en_END (24)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_clk_mux_test_en_START (25)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_clk_mux_test_en_END (25)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_clkp_dc_test_en_START (26)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_clkp_dc_test_en_END (26)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_clkn_dc_test_en_START (27)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_clkn_dc_test_en_END (27)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_vtest_en_START (28)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_vtest_en_END (28)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_clk_phsel_START (29)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_clk_phsel_END (29)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_state_sel_START (30)
#define SOC_FCM_LOCAL_IP_CTRL44_core8_2_state_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core4_ready_dcd2dcc : 1;
        unsigned int core4_cpu_dcd_lp_ctrl_stat : 4;
        unsigned int core4_cpu_dcd_en : 1;
        unsigned int core4_cpu_dcd_mode : 1;
        unsigned int core4_dcd_rst_req_sft : 1;
        unsigned int core4_a2d_samp_clk_div_level : 2;
        unsigned int core4_a2d_rosc_cal_rst_req : 1;
        unsigned int core4_a2d_samp_rst_req : 1;
        unsigned int core4_detect_mode : 1;
        unsigned int core4_freq_cal_enable : 1;
        unsigned int core4_hw_mode : 1;
        unsigned int reserved : 17;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL45_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL45_core4_ready_dcd2dcc_START (0)
#define SOC_FCM_LOCAL_IP_CTRL45_core4_ready_dcd2dcc_END (0)
#define SOC_FCM_LOCAL_IP_CTRL45_core4_cpu_dcd_lp_ctrl_stat_START (1)
#define SOC_FCM_LOCAL_IP_CTRL45_core4_cpu_dcd_lp_ctrl_stat_END (4)
#define SOC_FCM_LOCAL_IP_CTRL45_core4_cpu_dcd_en_START (5)
#define SOC_FCM_LOCAL_IP_CTRL45_core4_cpu_dcd_en_END (5)
#define SOC_FCM_LOCAL_IP_CTRL45_core4_cpu_dcd_mode_START (6)
#define SOC_FCM_LOCAL_IP_CTRL45_core4_cpu_dcd_mode_END (6)
#define SOC_FCM_LOCAL_IP_CTRL45_core4_dcd_rst_req_sft_START (7)
#define SOC_FCM_LOCAL_IP_CTRL45_core4_dcd_rst_req_sft_END (7)
#define SOC_FCM_LOCAL_IP_CTRL45_core4_a2d_samp_clk_div_level_START (8)
#define SOC_FCM_LOCAL_IP_CTRL45_core4_a2d_samp_clk_div_level_END (9)
#define SOC_FCM_LOCAL_IP_CTRL45_core4_a2d_rosc_cal_rst_req_START (10)
#define SOC_FCM_LOCAL_IP_CTRL45_core4_a2d_rosc_cal_rst_req_END (10)
#define SOC_FCM_LOCAL_IP_CTRL45_core4_a2d_samp_rst_req_START (11)
#define SOC_FCM_LOCAL_IP_CTRL45_core4_a2d_samp_rst_req_END (11)
#define SOC_FCM_LOCAL_IP_CTRL45_core4_detect_mode_START (12)
#define SOC_FCM_LOCAL_IP_CTRL45_core4_detect_mode_END (12)
#define SOC_FCM_LOCAL_IP_CTRL45_core4_freq_cal_enable_START (13)
#define SOC_FCM_LOCAL_IP_CTRL45_core4_freq_cal_enable_END (13)
#define SOC_FCM_LOCAL_IP_CTRL45_core4_hw_mode_START (14)
#define SOC_FCM_LOCAL_IP_CTRL45_core4_hw_mode_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core5_ready_dcd2dcc : 1;
        unsigned int core5_cpu_dcd_lp_ctrl_stat : 4;
        unsigned int core5_cpu_dcd_en : 1;
        unsigned int core5_cpu_dcd_mode : 1;
        unsigned int core4_dcd_rst_req_sft : 1;
        unsigned int core5_a2d_samp_clk_div_level : 2;
        unsigned int core5_a2d_rosc_cal_rst_req : 1;
        unsigned int core5_a2d_samp_rst_req : 1;
        unsigned int core5_detect_mode : 1;
        unsigned int core5_freq_cal_enable : 1;
        unsigned int core5_hw_mode : 1;
        unsigned int reserved : 17;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL46_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL46_core5_ready_dcd2dcc_START (0)
#define SOC_FCM_LOCAL_IP_CTRL46_core5_ready_dcd2dcc_END (0)
#define SOC_FCM_LOCAL_IP_CTRL46_core5_cpu_dcd_lp_ctrl_stat_START (1)
#define SOC_FCM_LOCAL_IP_CTRL46_core5_cpu_dcd_lp_ctrl_stat_END (4)
#define SOC_FCM_LOCAL_IP_CTRL46_core5_cpu_dcd_en_START (5)
#define SOC_FCM_LOCAL_IP_CTRL46_core5_cpu_dcd_en_END (5)
#define SOC_FCM_LOCAL_IP_CTRL46_core5_cpu_dcd_mode_START (6)
#define SOC_FCM_LOCAL_IP_CTRL46_core5_cpu_dcd_mode_END (6)
#define SOC_FCM_LOCAL_IP_CTRL46_core4_dcd_rst_req_sft_START (7)
#define SOC_FCM_LOCAL_IP_CTRL46_core4_dcd_rst_req_sft_END (7)
#define SOC_FCM_LOCAL_IP_CTRL46_core5_a2d_samp_clk_div_level_START (8)
#define SOC_FCM_LOCAL_IP_CTRL46_core5_a2d_samp_clk_div_level_END (9)
#define SOC_FCM_LOCAL_IP_CTRL46_core5_a2d_rosc_cal_rst_req_START (10)
#define SOC_FCM_LOCAL_IP_CTRL46_core5_a2d_rosc_cal_rst_req_END (10)
#define SOC_FCM_LOCAL_IP_CTRL46_core5_a2d_samp_rst_req_START (11)
#define SOC_FCM_LOCAL_IP_CTRL46_core5_a2d_samp_rst_req_END (11)
#define SOC_FCM_LOCAL_IP_CTRL46_core5_detect_mode_START (12)
#define SOC_FCM_LOCAL_IP_CTRL46_core5_detect_mode_END (12)
#define SOC_FCM_LOCAL_IP_CTRL46_core5_freq_cal_enable_START (13)
#define SOC_FCM_LOCAL_IP_CTRL46_core5_freq_cal_enable_END (13)
#define SOC_FCM_LOCAL_IP_CTRL46_core5_hw_mode_START (14)
#define SOC_FCM_LOCAL_IP_CTRL46_core5_hw_mode_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core6_ready_dcd2dcc : 1;
        unsigned int core6_cpu_dcd_lp_ctrl_stat : 4;
        unsigned int core6_cpu_dcd_en : 1;
        unsigned int core6_cpu_dcd_mode : 1;
        unsigned int core6_dcd_rst_req_sft : 1;
        unsigned int core6_a2d_samp_clk_div_level : 2;
        unsigned int core6_a2d_rosc_cal_rst_req : 1;
        unsigned int core6_a2d_samp_rst_req : 1;
        unsigned int core6_detect_mode : 1;
        unsigned int core6_freq_cal_enable : 1;
        unsigned int core6_hw_mode : 1;
        unsigned int reserved : 17;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL47_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL47_core6_ready_dcd2dcc_START (0)
#define SOC_FCM_LOCAL_IP_CTRL47_core6_ready_dcd2dcc_END (0)
#define SOC_FCM_LOCAL_IP_CTRL47_core6_cpu_dcd_lp_ctrl_stat_START (1)
#define SOC_FCM_LOCAL_IP_CTRL47_core6_cpu_dcd_lp_ctrl_stat_END (4)
#define SOC_FCM_LOCAL_IP_CTRL47_core6_cpu_dcd_en_START (5)
#define SOC_FCM_LOCAL_IP_CTRL47_core6_cpu_dcd_en_END (5)
#define SOC_FCM_LOCAL_IP_CTRL47_core6_cpu_dcd_mode_START (6)
#define SOC_FCM_LOCAL_IP_CTRL47_core6_cpu_dcd_mode_END (6)
#define SOC_FCM_LOCAL_IP_CTRL47_core6_dcd_rst_req_sft_START (7)
#define SOC_FCM_LOCAL_IP_CTRL47_core6_dcd_rst_req_sft_END (7)
#define SOC_FCM_LOCAL_IP_CTRL47_core6_a2d_samp_clk_div_level_START (8)
#define SOC_FCM_LOCAL_IP_CTRL47_core6_a2d_samp_clk_div_level_END (9)
#define SOC_FCM_LOCAL_IP_CTRL47_core6_a2d_rosc_cal_rst_req_START (10)
#define SOC_FCM_LOCAL_IP_CTRL47_core6_a2d_rosc_cal_rst_req_END (10)
#define SOC_FCM_LOCAL_IP_CTRL47_core6_a2d_samp_rst_req_START (11)
#define SOC_FCM_LOCAL_IP_CTRL47_core6_a2d_samp_rst_req_END (11)
#define SOC_FCM_LOCAL_IP_CTRL47_core6_detect_mode_START (12)
#define SOC_FCM_LOCAL_IP_CTRL47_core6_detect_mode_END (12)
#define SOC_FCM_LOCAL_IP_CTRL47_core6_freq_cal_enable_START (13)
#define SOC_FCM_LOCAL_IP_CTRL47_core6_freq_cal_enable_END (13)
#define SOC_FCM_LOCAL_IP_CTRL47_core6_hw_mode_START (14)
#define SOC_FCM_LOCAL_IP_CTRL47_core6_hw_mode_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core7_ready_dcd2dcc : 1;
        unsigned int core7_cpu_dcd_lp_ctrl_stat : 4;
        unsigned int core7_cpu_dcd_en : 1;
        unsigned int core7_cpu_dcd_mode : 1;
        unsigned int core7_dcd_rst_req_sft : 1;
        unsigned int core7_a2d_samp_clk_div_level : 2;
        unsigned int core7_a2d_rosc_cal_rst_req : 1;
        unsigned int core7_a2d_samp_rst_req : 1;
        unsigned int core7_detect_mode : 1;
        unsigned int core7_freq_cal_enable : 1;
        unsigned int core7_hw_mode : 1;
        unsigned int reserved : 17;
    } reg;
} SOC_FCM_LOCAL_IP_CTRL48_UNION;
#endif
#define SOC_FCM_LOCAL_IP_CTRL48_core7_ready_dcd2dcc_START (0)
#define SOC_FCM_LOCAL_IP_CTRL48_core7_ready_dcd2dcc_END (0)
#define SOC_FCM_LOCAL_IP_CTRL48_core7_cpu_dcd_lp_ctrl_stat_START (1)
#define SOC_FCM_LOCAL_IP_CTRL48_core7_cpu_dcd_lp_ctrl_stat_END (4)
#define SOC_FCM_LOCAL_IP_CTRL48_core7_cpu_dcd_en_START (5)
#define SOC_FCM_LOCAL_IP_CTRL48_core7_cpu_dcd_en_END (5)
#define SOC_FCM_LOCAL_IP_CTRL48_core7_cpu_dcd_mode_START (6)
#define SOC_FCM_LOCAL_IP_CTRL48_core7_cpu_dcd_mode_END (6)
#define SOC_FCM_LOCAL_IP_CTRL48_core7_dcd_rst_req_sft_START (7)
#define SOC_FCM_LOCAL_IP_CTRL48_core7_dcd_rst_req_sft_END (7)
#define SOC_FCM_LOCAL_IP_CTRL48_core7_a2d_samp_clk_div_level_START (8)
#define SOC_FCM_LOCAL_IP_CTRL48_core7_a2d_samp_clk_div_level_END (9)
#define SOC_FCM_LOCAL_IP_CTRL48_core7_a2d_rosc_cal_rst_req_START (10)
#define SOC_FCM_LOCAL_IP_CTRL48_core7_a2d_rosc_cal_rst_req_END (10)
#define SOC_FCM_LOCAL_IP_CTRL48_core7_a2d_samp_rst_req_START (11)
#define SOC_FCM_LOCAL_IP_CTRL48_core7_a2d_samp_rst_req_END (11)
#define SOC_FCM_LOCAL_IP_CTRL48_core7_detect_mode_START (12)
#define SOC_FCM_LOCAL_IP_CTRL48_core7_detect_mode_END (12)
#define SOC_FCM_LOCAL_IP_CTRL48_core7_freq_cal_enable_START (13)
#define SOC_FCM_LOCAL_IP_CTRL48_core7_freq_cal_enable_END (13)
#define SOC_FCM_LOCAL_IP_CTRL48_core7_hw_mode_START (14)
#define SOC_FCM_LOCAL_IP_CTRL48_core7_hw_mode_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ts_value_reserved_0_low : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT0_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT0_ts_value_reserved_0_low_START (0)
#define SOC_FCM_LOCAL_IP_STAT0_ts_value_reserved_0_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ts_value_reserved_0_high : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT1_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT1_ts_value_reserved_0_high_START (0)
#define SOC_FCM_LOCAL_IP_STAT1_ts_value_reserved_0_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ts_value_reserved_1_low : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT2_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT2_ts_value_reserved_1_low_START (0)
#define SOC_FCM_LOCAL_IP_STAT2_ts_value_reserved_1_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ts_value_reserved_1_high : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT3_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT3_ts_value_reserved_1_high_START (0)
#define SOC_FCM_LOCAL_IP_STAT3_ts_value_reserved_1_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ts_value_reserved_2_low : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT4_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT4_ts_value_reserved_2_low_START (0)
#define SOC_FCM_LOCAL_IP_STAT4_ts_value_reserved_2_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ts_value_reserved_2_high : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT5_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT5_ts_value_reserved_2_high_START (0)
#define SOC_FCM_LOCAL_IP_STAT5_ts_value_reserved_2_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ts_value_reserved_3_low : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT6_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT6_ts_value_reserved_3_low_START (0)
#define SOC_FCM_LOCAL_IP_STAT6_ts_value_reserved_3_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ts_value_reserved_3_high : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT7_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT7_ts_value_reserved_3_high_START (0)
#define SOC_FCM_LOCAL_IP_STAT7_ts_value_reserved_3_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ts_value_reserved_4_low : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT8_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT8_ts_value_reserved_4_low_START (0)
#define SOC_FCM_LOCAL_IP_STAT8_ts_value_reserved_4_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ts_value_reserved_4_high : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT9_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT9_ts_value_reserved_4_high_START (0)
#define SOC_FCM_LOCAL_IP_STAT9_ts_value_reserved_4_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ts_value_reserved_5_low : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT10_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT10_ts_value_reserved_5_low_START (0)
#define SOC_FCM_LOCAL_IP_STAT10_ts_value_reserved_5_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ts_value_reserved_5_high : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT11_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT11_ts_value_reserved_5_high_START (0)
#define SOC_FCM_LOCAL_IP_STAT11_ts_value_reserved_5_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int corex_current_pi_dfx0_core_unm : 2;
        unsigned int corex_current_pi_dfx0_pi_reason : 2;
        unsigned int reserved : 28;
    } reg;
} SOC_FCM_LOCAL_IP_STAT12_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT12_corex_current_pi_dfx0_core_unm_START (0)
#define SOC_FCM_LOCAL_IP_STAT12_corex_current_pi_dfx0_core_unm_END (1)
#define SOC_FCM_LOCAL_IP_STAT12_corex_current_pi_dfx0_pi_reason_START (2)
#define SOC_FCM_LOCAL_IP_STAT12_corex_current_pi_dfx0_pi_reason_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int corex_current_pi_dfx1_core_unm : 2;
        unsigned int corex_current_pi_dfx1_pi_reason : 2;
        unsigned int reserved : 28;
    } reg;
} SOC_FCM_LOCAL_IP_STAT13_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT13_corex_current_pi_dfx1_core_unm_START (0)
#define SOC_FCM_LOCAL_IP_STAT13_corex_current_pi_dfx1_core_unm_END (1)
#define SOC_FCM_LOCAL_IP_STAT13_corex_current_pi_dfx1_pi_reason_START (2)
#define SOC_FCM_LOCAL_IP_STAT13_corex_current_pi_dfx1_pi_reason_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int corex_current_pi_dfx2_core_unm : 2;
        unsigned int corex_current_pi_dfx2_pi_reason : 2;
        unsigned int reserved : 28;
    } reg;
} SOC_FCM_LOCAL_IP_STAT14_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT14_corex_current_pi_dfx2_core_unm_START (0)
#define SOC_FCM_LOCAL_IP_STAT14_corex_current_pi_dfx2_core_unm_END (1)
#define SOC_FCM_LOCAL_IP_STAT14_corex_current_pi_dfx2_pi_reason_START (2)
#define SOC_FCM_LOCAL_IP_STAT14_corex_current_pi_dfx2_pi_reason_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int corex_current_pi_dfx3_core_unm : 2;
        unsigned int corex_current_pi_dfx3_pi_reason : 2;
        unsigned int reserved : 28;
    } reg;
} SOC_FCM_LOCAL_IP_STAT15_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT15_corex_current_pi_dfx3_core_unm_START (0)
#define SOC_FCM_LOCAL_IP_STAT15_corex_current_pi_dfx3_core_unm_END (1)
#define SOC_FCM_LOCAL_IP_STAT15_corex_current_pi_dfx3_pi_reason_START (2)
#define SOC_FCM_LOCAL_IP_STAT15_corex_current_pi_dfx3_pi_reason_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int corex_current_pi_dfx4_core_unm : 2;
        unsigned int corex_current_pi_dfx4_pi_reason : 2;
        unsigned int reserved : 28;
    } reg;
} SOC_FCM_LOCAL_IP_STAT16_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT16_corex_current_pi_dfx4_core_unm_START (0)
#define SOC_FCM_LOCAL_IP_STAT16_corex_current_pi_dfx4_core_unm_END (1)
#define SOC_FCM_LOCAL_IP_STAT16_corex_current_pi_dfx4_pi_reason_START (2)
#define SOC_FCM_LOCAL_IP_STAT16_corex_current_pi_dfx4_pi_reason_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int corex_current_pi_dfx5_core_unm : 2;
        unsigned int corex_current_pi_dfx5_pi_reason : 2;
        unsigned int reserved : 28;
    } reg;
} SOC_FCM_LOCAL_IP_STAT17_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT17_corex_current_pi_dfx5_core_unm_START (0)
#define SOC_FCM_LOCAL_IP_STAT17_corex_current_pi_dfx5_core_unm_END (1)
#define SOC_FCM_LOCAL_IP_STAT17_corex_current_pi_dfx5_pi_reason_START (2)
#define SOC_FCM_LOCAL_IP_STAT17_corex_current_pi_dfx5_pi_reason_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int corex_cnt_cpm_flag : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT18_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT18_corex_cnt_cpm_flag_START (0)
#define SOC_FCM_LOCAL_IP_STAT18_corex_cnt_cpm_flag_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int l3_rtm_cnt_over : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_FCM_LOCAL_IP_STAT19_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT19_l3_rtm_cnt_over_START (0)
#define SOC_FCM_LOCAL_IP_STAT19_l3_rtm_cnt_over_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rpt_process_monitor_cpu : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT20_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT20_rpt_process_monitor_cpu_START (0)
#define SOC_FCM_LOCAL_IP_STAT20_rpt_process_monitor_cpu_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rpt_process_monitor_cluster : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT21_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT21_rpt_process_monitor_cluster_START (0)
#define SOC_FCM_LOCAL_IP_STAT21_rpt_process_monitor_cluster_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core4_cpu_dcd_stat : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT22_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT22_core4_cpu_dcd_stat_START (0)
#define SOC_FCM_LOCAL_IP_STAT22_core4_cpu_dcd_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core5_cpu_dcd_stat : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT23_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT23_core5_cpu_dcd_stat_START (0)
#define SOC_FCM_LOCAL_IP_STAT23_core5_cpu_dcd_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core6_cpu_dcd_stat : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT24_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT24_core6_cpu_dcd_stat_START (0)
#define SOC_FCM_LOCAL_IP_STAT24_core6_cpu_dcd_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core7_cpu_dcd_stat : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT25_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT25_core7_cpu_dcd_stat_START (0)
#define SOC_FCM_LOCAL_IP_STAT25_core7_cpu_dcd_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core8_cpu_dcd_stat_0 : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT26_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT26_core8_cpu_dcd_stat_0_START (0)
#define SOC_FCM_LOCAL_IP_STAT26_core8_cpu_dcd_stat_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core8_cpu_dcd_stat_1 : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT27_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT27_core8_cpu_dcd_stat_1_START (0)
#define SOC_FCM_LOCAL_IP_STAT27_core8_cpu_dcd_stat_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core8_cpu_dcd_stat_2 : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT28_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT28_core8_cpu_dcd_stat_2_START (0)
#define SOC_FCM_LOCAL_IP_STAT28_core8_cpu_dcd_stat_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core4_valid_dcc2dcd : 1;
        unsigned int core4_dcd_duty_flag : 1;
        unsigned int core4_dcd_duty_offset : 16;
        unsigned int core4_cpu_dcd_rsv_out : 8;
        unsigned int reserved : 6;
    } reg;
} SOC_FCM_LOCAL_IP_STAT29_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT29_core4_valid_dcc2dcd_START (0)
#define SOC_FCM_LOCAL_IP_STAT29_core4_valid_dcc2dcd_END (0)
#define SOC_FCM_LOCAL_IP_STAT29_core4_dcd_duty_flag_START (1)
#define SOC_FCM_LOCAL_IP_STAT29_core4_dcd_duty_flag_END (1)
#define SOC_FCM_LOCAL_IP_STAT29_core4_dcd_duty_offset_START (2)
#define SOC_FCM_LOCAL_IP_STAT29_core4_dcd_duty_offset_END (17)
#define SOC_FCM_LOCAL_IP_STAT29_core4_cpu_dcd_rsv_out_START (18)
#define SOC_FCM_LOCAL_IP_STAT29_core4_cpu_dcd_rsv_out_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core5_valid_dcc2dcd : 1;
        unsigned int core5_dcd_duty_flag : 1;
        unsigned int core5_dcd_duty_offset : 16;
        unsigned int core5_cpu_dcd_rsv_out : 8;
        unsigned int reserved : 6;
    } reg;
} SOC_FCM_LOCAL_IP_STAT30_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT30_core5_valid_dcc2dcd_START (0)
#define SOC_FCM_LOCAL_IP_STAT30_core5_valid_dcc2dcd_END (0)
#define SOC_FCM_LOCAL_IP_STAT30_core5_dcd_duty_flag_START (1)
#define SOC_FCM_LOCAL_IP_STAT30_core5_dcd_duty_flag_END (1)
#define SOC_FCM_LOCAL_IP_STAT30_core5_dcd_duty_offset_START (2)
#define SOC_FCM_LOCAL_IP_STAT30_core5_dcd_duty_offset_END (17)
#define SOC_FCM_LOCAL_IP_STAT30_core5_cpu_dcd_rsv_out_START (18)
#define SOC_FCM_LOCAL_IP_STAT30_core5_cpu_dcd_rsv_out_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core6_valid_dcc2dcd : 1;
        unsigned int core6_dcd_duty_flag : 1;
        unsigned int core6_dcd_duty_offset : 16;
        unsigned int core6_cpu_dcd_rsv_out : 8;
        unsigned int reserved : 6;
    } reg;
} SOC_FCM_LOCAL_IP_STAT31_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT31_core6_valid_dcc2dcd_START (0)
#define SOC_FCM_LOCAL_IP_STAT31_core6_valid_dcc2dcd_END (0)
#define SOC_FCM_LOCAL_IP_STAT31_core6_dcd_duty_flag_START (1)
#define SOC_FCM_LOCAL_IP_STAT31_core6_dcd_duty_flag_END (1)
#define SOC_FCM_LOCAL_IP_STAT31_core6_dcd_duty_offset_START (2)
#define SOC_FCM_LOCAL_IP_STAT31_core6_dcd_duty_offset_END (17)
#define SOC_FCM_LOCAL_IP_STAT31_core6_cpu_dcd_rsv_out_START (18)
#define SOC_FCM_LOCAL_IP_STAT31_core6_cpu_dcd_rsv_out_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core7_valid_dcc2dcd : 1;
        unsigned int core7_dcd_duty_flag : 1;
        unsigned int core7_dcd_duty_offset : 16;
        unsigned int core7_cpu_dcd_rsv_out : 8;
        unsigned int reserved : 6;
    } reg;
} SOC_FCM_LOCAL_IP_STAT32_UNION;
#endif
#define SOC_FCM_LOCAL_IP_STAT32_core7_valid_dcc2dcd_START (0)
#define SOC_FCM_LOCAL_IP_STAT32_core7_valid_dcc2dcd_END (0)
#define SOC_FCM_LOCAL_IP_STAT32_core7_dcd_duty_flag_START (1)
#define SOC_FCM_LOCAL_IP_STAT32_core7_dcd_duty_flag_END (1)
#define SOC_FCM_LOCAL_IP_STAT32_core7_dcd_duty_offset_START (2)
#define SOC_FCM_LOCAL_IP_STAT32_core7_dcd_duty_offset_END (17)
#define SOC_FCM_LOCAL_IP_STAT32_core7_cpu_dcd_rsv_out_START (18)
#define SOC_FCM_LOCAL_IP_STAT32_core7_cpu_dcd_rsv_out_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT33_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT34_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT35_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT36_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT37_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT38_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT39_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_LOCAL_IP_STAT40_UNION;
#endif
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
