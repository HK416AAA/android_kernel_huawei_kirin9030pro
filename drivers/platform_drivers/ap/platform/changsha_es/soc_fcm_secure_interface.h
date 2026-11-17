#ifndef __SOC_FCM_SECURE_INTERFACE_H__
#define __SOC_FCM_SECURE_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FCM_SECURE_R0SIZE_ADDR(base) ((base) + (0x000UL))
#define SOC_FCM_SECURE_DECPROT0STAT_ADDR(base) ((base) + (0x800UL))
#define SOC_FCM_SECURE_DECPROT0SET_ADDR(base) ((base) + (0x804UL))
#define SOC_FCM_SECURE_DECPROT0CLR_ADDR(base) ((base) + (0x808UL))
#define SOC_FCM_SECURE_DECPROT1STAT_ADDR(base) ((base) + (0x80CUL))
#define SOC_FCM_SECURE_DECPROT1SET_ADDR(base) ((base) + (0x810UL))
#define SOC_FCM_SECURE_DECPROT1CLR_ADDR(base) ((base) + (0x814UL))
#define SOC_FCM_SECURE_DECPROT2STAT_ADDR(base) ((base) + (0x818UL))
#define SOC_FCM_SECURE_DECPROT2SET_ADDR(base) ((base) + (0x81CUL))
#define SOC_FCM_SECURE_DECPROT2CLR_ADDR(base) ((base) + (0x820UL))
#define SOC_FCM_SECURE_DECPROT3STAT_ADDR(base) ((base) + (0x824UL))
#define SOC_FCM_SECURE_DECPROT3SET_ADDR(base) ((base) + (0x828UL))
#define SOC_FCM_SECURE_DECPROT3CLR_ADDR(base) ((base) + (0x82CUL))
#define SOC_FCM_SECURE_DECPROT4STAT_ADDR(base) ((base) + (0x830UL))
#define SOC_FCM_SECURE_DECPROT4SET_ADDR(base) ((base) + (0x834UL))
#define SOC_FCM_SECURE_DECPROT4CLR_ADDR(base) ((base) + (0x838UL))
#define SOC_FCM_SECURE_DECPROT5STAT_ADDR(base) ((base) + (0x83CUL))
#define SOC_FCM_SECURE_DECPROT5SET_ADDR(base) ((base) + (0x840UL))
#define SOC_FCM_SECURE_DECPROT5CLR_ADDR(base) ((base) + (0x844UL))
#define SOC_FCM_SECURE_DECPROT6STAT_ADDR(base) ((base) + (0x848UL))
#define SOC_FCM_SECURE_DECPROT6SET_ADDR(base) ((base) + (0x84CUL))
#define SOC_FCM_SECURE_DECPROT6CLR_ADDR(base) ((base) + (0x850UL))
#define SOC_FCM_SECURE_DECPROT7STAT_ADDR(base) ((base) + (0x854UL))
#define SOC_FCM_SECURE_DECPROT7SET_ADDR(base) ((base) + (0x858UL))
#define SOC_FCM_SECURE_DECPROT7CLR_ADDR(base) ((base) + (0x85CUL))
#define SOC_FCM_SECURE_DECPROT8STAT_ADDR(base) ((base) + (0x860UL))
#define SOC_FCM_SECURE_DECPROT8SET_ADDR(base) ((base) + (0x864UL))
#define SOC_FCM_SECURE_DECPROT8CLR_ADDR(base) ((base) + (0x868UL))
#define SOC_FCM_SECURE_REG0_STAT_ADDR(base) ((base) + (0x86CUL))
#define SOC_FCM_SECURE_REG1_STAT_ADDR(base) ((base) + (0x870UL))
#else
#define SOC_FCM_SECURE_R0SIZE_ADDR(base) ((base) + (0x000))
#define SOC_FCM_SECURE_DECPROT0STAT_ADDR(base) ((base) + (0x800))
#define SOC_FCM_SECURE_DECPROT0SET_ADDR(base) ((base) + (0x804))
#define SOC_FCM_SECURE_DECPROT0CLR_ADDR(base) ((base) + (0x808))
#define SOC_FCM_SECURE_DECPROT1STAT_ADDR(base) ((base) + (0x80C))
#define SOC_FCM_SECURE_DECPROT1SET_ADDR(base) ((base) + (0x810))
#define SOC_FCM_SECURE_DECPROT1CLR_ADDR(base) ((base) + (0x814))
#define SOC_FCM_SECURE_DECPROT2STAT_ADDR(base) ((base) + (0x818))
#define SOC_FCM_SECURE_DECPROT2SET_ADDR(base) ((base) + (0x81C))
#define SOC_FCM_SECURE_DECPROT2CLR_ADDR(base) ((base) + (0x820))
#define SOC_FCM_SECURE_DECPROT3STAT_ADDR(base) ((base) + (0x824))
#define SOC_FCM_SECURE_DECPROT3SET_ADDR(base) ((base) + (0x828))
#define SOC_FCM_SECURE_DECPROT3CLR_ADDR(base) ((base) + (0x82C))
#define SOC_FCM_SECURE_DECPROT4STAT_ADDR(base) ((base) + (0x830))
#define SOC_FCM_SECURE_DECPROT4SET_ADDR(base) ((base) + (0x834))
#define SOC_FCM_SECURE_DECPROT4CLR_ADDR(base) ((base) + (0x838))
#define SOC_FCM_SECURE_DECPROT5STAT_ADDR(base) ((base) + (0x83C))
#define SOC_FCM_SECURE_DECPROT5SET_ADDR(base) ((base) + (0x840))
#define SOC_FCM_SECURE_DECPROT5CLR_ADDR(base) ((base) + (0x844))
#define SOC_FCM_SECURE_DECPROT6STAT_ADDR(base) ((base) + (0x848))
#define SOC_FCM_SECURE_DECPROT6SET_ADDR(base) ((base) + (0x84C))
#define SOC_FCM_SECURE_DECPROT6CLR_ADDR(base) ((base) + (0x850))
#define SOC_FCM_SECURE_DECPROT7STAT_ADDR(base) ((base) + (0x854))
#define SOC_FCM_SECURE_DECPROT7SET_ADDR(base) ((base) + (0x858))
#define SOC_FCM_SECURE_DECPROT7CLR_ADDR(base) ((base) + (0x85C))
#define SOC_FCM_SECURE_DECPROT8STAT_ADDR(base) ((base) + (0x860))
#define SOC_FCM_SECURE_DECPROT8SET_ADDR(base) ((base) + (0x864))
#define SOC_FCM_SECURE_DECPROT8CLR_ADDR(base) ((base) + (0x868))
#define SOC_FCM_SECURE_REG0_STAT_ADDR(base) ((base) + (0x86C))
#define SOC_FCM_SECURE_REG1_STAT_ADDR(base) ((base) + (0x870))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_SECURE_R0SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tzpc_stat_local_cpu : 1;
        unsigned int tzpc_stat_local_core4 : 1;
        unsigned int tzpc_stat_local_core5 : 1;
        unsigned int tzpc_stat_local_core6 : 1;
        unsigned int tzpc_stat_local_core7 : 1;
        unsigned int tzpc_stat_local_core8 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int tzpc_stat_local_ip : 1;
        unsigned int tzpc_stat_local_linx_djtag : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 15;
    } reg;
} SOC_FCM_SECURE_DECPROT0STAT_UNION;
#endif
#define SOC_FCM_SECURE_DECPROT0STAT_tzpc_stat_local_cpu_START (0)
#define SOC_FCM_SECURE_DECPROT0STAT_tzpc_stat_local_cpu_END (0)
#define SOC_FCM_SECURE_DECPROT0STAT_tzpc_stat_local_core4_START (1)
#define SOC_FCM_SECURE_DECPROT0STAT_tzpc_stat_local_core4_END (1)
#define SOC_FCM_SECURE_DECPROT0STAT_tzpc_stat_local_core5_START (2)
#define SOC_FCM_SECURE_DECPROT0STAT_tzpc_stat_local_core5_END (2)
#define SOC_FCM_SECURE_DECPROT0STAT_tzpc_stat_local_core6_START (3)
#define SOC_FCM_SECURE_DECPROT0STAT_tzpc_stat_local_core6_END (3)
#define SOC_FCM_SECURE_DECPROT0STAT_tzpc_stat_local_core7_START (4)
#define SOC_FCM_SECURE_DECPROT0STAT_tzpc_stat_local_core7_END (4)
#define SOC_FCM_SECURE_DECPROT0STAT_tzpc_stat_local_core8_START (5)
#define SOC_FCM_SECURE_DECPROT0STAT_tzpc_stat_local_core8_END (5)
#define SOC_FCM_SECURE_DECPROT0STAT_tzpc_stat_local_ip_START (9)
#define SOC_FCM_SECURE_DECPROT0STAT_tzpc_stat_local_ip_END (9)
#define SOC_FCM_SECURE_DECPROT0STAT_tzpc_stat_local_linx_djtag_START (10)
#define SOC_FCM_SECURE_DECPROT0STAT_tzpc_stat_local_linx_djtag_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tzpc_stat_local_cpu : 1;
        unsigned int tzpc_stat_local_core4 : 1;
        unsigned int tzpc_stat_local_core5 : 1;
        unsigned int tzpc_stat_local_core6 : 1;
        unsigned int tzpc_stat_local_core7 : 1;
        unsigned int tzpc_stat_local_core8 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int tzpc_stat_local_ip : 1;
        unsigned int tzpc_stat_local_linx_djtag : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 15;
    } reg;
} SOC_FCM_SECURE_DECPROT0SET_UNION;
#endif
#define SOC_FCM_SECURE_DECPROT0SET_tzpc_stat_local_cpu_START (0)
#define SOC_FCM_SECURE_DECPROT0SET_tzpc_stat_local_cpu_END (0)
#define SOC_FCM_SECURE_DECPROT0SET_tzpc_stat_local_core4_START (1)
#define SOC_FCM_SECURE_DECPROT0SET_tzpc_stat_local_core4_END (1)
#define SOC_FCM_SECURE_DECPROT0SET_tzpc_stat_local_core5_START (2)
#define SOC_FCM_SECURE_DECPROT0SET_tzpc_stat_local_core5_END (2)
#define SOC_FCM_SECURE_DECPROT0SET_tzpc_stat_local_core6_START (3)
#define SOC_FCM_SECURE_DECPROT0SET_tzpc_stat_local_core6_END (3)
#define SOC_FCM_SECURE_DECPROT0SET_tzpc_stat_local_core7_START (4)
#define SOC_FCM_SECURE_DECPROT0SET_tzpc_stat_local_core7_END (4)
#define SOC_FCM_SECURE_DECPROT0SET_tzpc_stat_local_core8_START (5)
#define SOC_FCM_SECURE_DECPROT0SET_tzpc_stat_local_core8_END (5)
#define SOC_FCM_SECURE_DECPROT0SET_tzpc_stat_local_ip_START (9)
#define SOC_FCM_SECURE_DECPROT0SET_tzpc_stat_local_ip_END (9)
#define SOC_FCM_SECURE_DECPROT0SET_tzpc_stat_local_linx_djtag_START (10)
#define SOC_FCM_SECURE_DECPROT0SET_tzpc_stat_local_linx_djtag_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tzpc_stat_local_cpu : 1;
        unsigned int tzpc_stat_local_core4 : 1;
        unsigned int tzpc_stat_local_core5 : 1;
        unsigned int tzpc_stat_local_core6 : 1;
        unsigned int tzpc_stat_local_core7 : 1;
        unsigned int tzpc_stat_local_core8 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int tzpc_stat_local_ip : 1;
        unsigned int tzpc_stat_local_linx_djtag : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 15;
    } reg;
} SOC_FCM_SECURE_DECPROT0CLR_UNION;
#endif
#define SOC_FCM_SECURE_DECPROT0CLR_tzpc_stat_local_cpu_START (0)
#define SOC_FCM_SECURE_DECPROT0CLR_tzpc_stat_local_cpu_END (0)
#define SOC_FCM_SECURE_DECPROT0CLR_tzpc_stat_local_core4_START (1)
#define SOC_FCM_SECURE_DECPROT0CLR_tzpc_stat_local_core4_END (1)
#define SOC_FCM_SECURE_DECPROT0CLR_tzpc_stat_local_core5_START (2)
#define SOC_FCM_SECURE_DECPROT0CLR_tzpc_stat_local_core5_END (2)
#define SOC_FCM_SECURE_DECPROT0CLR_tzpc_stat_local_core6_START (3)
#define SOC_FCM_SECURE_DECPROT0CLR_tzpc_stat_local_core6_END (3)
#define SOC_FCM_SECURE_DECPROT0CLR_tzpc_stat_local_core7_START (4)
#define SOC_FCM_SECURE_DECPROT0CLR_tzpc_stat_local_core7_END (4)
#define SOC_FCM_SECURE_DECPROT0CLR_tzpc_stat_local_core8_START (5)
#define SOC_FCM_SECURE_DECPROT0CLR_tzpc_stat_local_core8_END (5)
#define SOC_FCM_SECURE_DECPROT0CLR_tzpc_stat_local_ip_START (9)
#define SOC_FCM_SECURE_DECPROT0CLR_tzpc_stat_local_ip_END (9)
#define SOC_FCM_SECURE_DECPROT0CLR_tzpc_stat_local_linx_djtag_START (10)
#define SOC_FCM_SECURE_DECPROT0CLR_tzpc_stat_local_linx_djtag_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tzpc_stat_cpu_pdc : 1;
        unsigned int reserved_0 : 1;
        unsigned int tzpc_stat_coresight : 1;
        unsigned int tzpc_stat_local_peri : 1;
        unsigned int tzpc_stat_hw_spi0 : 1;
        unsigned int tzpc_stat_local_gic : 1;
        unsigned int tzpc_stat_load_mon : 1;
        unsigned int tzpc_stat_hw_spi1 : 1;
        unsigned int tzpc_stat_rtm : 1;
        unsigned int reserved_1 : 5;
        unsigned int tzpc_stat_core_crg : 1;
        unsigned int reserved_2 : 17;
    } reg;
} SOC_FCM_SECURE_DECPROT1STAT_UNION;
#endif
#define SOC_FCM_SECURE_DECPROT1STAT_tzpc_stat_cpu_pdc_START (0)
#define SOC_FCM_SECURE_DECPROT1STAT_tzpc_stat_cpu_pdc_END (0)
#define SOC_FCM_SECURE_DECPROT1STAT_tzpc_stat_coresight_START (2)
#define SOC_FCM_SECURE_DECPROT1STAT_tzpc_stat_coresight_END (2)
#define SOC_FCM_SECURE_DECPROT1STAT_tzpc_stat_local_peri_START (3)
#define SOC_FCM_SECURE_DECPROT1STAT_tzpc_stat_local_peri_END (3)
#define SOC_FCM_SECURE_DECPROT1STAT_tzpc_stat_hw_spi0_START (4)
#define SOC_FCM_SECURE_DECPROT1STAT_tzpc_stat_hw_spi0_END (4)
#define SOC_FCM_SECURE_DECPROT1STAT_tzpc_stat_local_gic_START (5)
#define SOC_FCM_SECURE_DECPROT1STAT_tzpc_stat_local_gic_END (5)
#define SOC_FCM_SECURE_DECPROT1STAT_tzpc_stat_load_mon_START (6)
#define SOC_FCM_SECURE_DECPROT1STAT_tzpc_stat_load_mon_END (6)
#define SOC_FCM_SECURE_DECPROT1STAT_tzpc_stat_hw_spi1_START (7)
#define SOC_FCM_SECURE_DECPROT1STAT_tzpc_stat_hw_spi1_END (7)
#define SOC_FCM_SECURE_DECPROT1STAT_tzpc_stat_rtm_START (8)
#define SOC_FCM_SECURE_DECPROT1STAT_tzpc_stat_rtm_END (8)
#define SOC_FCM_SECURE_DECPROT1STAT_tzpc_stat_core_crg_START (14)
#define SOC_FCM_SECURE_DECPROT1STAT_tzpc_stat_core_crg_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tzpc_set_cpu_pdc : 1;
        unsigned int reserved_0 : 1;
        unsigned int tzpc_set_coresight : 1;
        unsigned int tzpc_set_local_peri : 1;
        unsigned int tzpc_set_hw_spi0 : 1;
        unsigned int tzpc_set_local_gic : 1;
        unsigned int tzpc_set_lp_mon : 1;
        unsigned int tzpc_set_hw_spi1 : 1;
        unsigned int tzpc_set_rtm : 1;
        unsigned int reserved_1 : 5;
        unsigned int tzpc_set_core_crg : 1;
        unsigned int reserved_2 : 17;
    } reg;
} SOC_FCM_SECURE_DECPROT1SET_UNION;
#endif
#define SOC_FCM_SECURE_DECPROT1SET_tzpc_set_cpu_pdc_START (0)
#define SOC_FCM_SECURE_DECPROT1SET_tzpc_set_cpu_pdc_END (0)
#define SOC_FCM_SECURE_DECPROT1SET_tzpc_set_coresight_START (2)
#define SOC_FCM_SECURE_DECPROT1SET_tzpc_set_coresight_END (2)
#define SOC_FCM_SECURE_DECPROT1SET_tzpc_set_local_peri_START (3)
#define SOC_FCM_SECURE_DECPROT1SET_tzpc_set_local_peri_END (3)
#define SOC_FCM_SECURE_DECPROT1SET_tzpc_set_hw_spi0_START (4)
#define SOC_FCM_SECURE_DECPROT1SET_tzpc_set_hw_spi0_END (4)
#define SOC_FCM_SECURE_DECPROT1SET_tzpc_set_local_gic_START (5)
#define SOC_FCM_SECURE_DECPROT1SET_tzpc_set_local_gic_END (5)
#define SOC_FCM_SECURE_DECPROT1SET_tzpc_set_lp_mon_START (6)
#define SOC_FCM_SECURE_DECPROT1SET_tzpc_set_lp_mon_END (6)
#define SOC_FCM_SECURE_DECPROT1SET_tzpc_set_hw_spi1_START (7)
#define SOC_FCM_SECURE_DECPROT1SET_tzpc_set_hw_spi1_END (7)
#define SOC_FCM_SECURE_DECPROT1SET_tzpc_set_rtm_START (8)
#define SOC_FCM_SECURE_DECPROT1SET_tzpc_set_rtm_END (8)
#define SOC_FCM_SECURE_DECPROT1SET_tzpc_set_core_crg_START (14)
#define SOC_FCM_SECURE_DECPROT1SET_tzpc_set_core_crg_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tzpc_clr_cpu_pdc : 1;
        unsigned int reserved_0 : 1;
        unsigned int tzpc_clr_coresight : 1;
        unsigned int tzpc_clr_local_peri : 1;
        unsigned int tzpc_clr_hw_spi0 : 1;
        unsigned int tzpc_clr_local_gic : 1;
        unsigned int tzpc_clr_lp_mon : 1;
        unsigned int tzpc_clr_hw_spi1 : 1;
        unsigned int tzpc_clr_rtm : 1;
        unsigned int reserved_1 : 5;
        unsigned int tzpc_clr_core_crg : 1;
        unsigned int reserved_2 : 17;
    } reg;
} SOC_FCM_SECURE_DECPROT1CLR_UNION;
#endif
#define SOC_FCM_SECURE_DECPROT1CLR_tzpc_clr_cpu_pdc_START (0)
#define SOC_FCM_SECURE_DECPROT1CLR_tzpc_clr_cpu_pdc_END (0)
#define SOC_FCM_SECURE_DECPROT1CLR_tzpc_clr_coresight_START (2)
#define SOC_FCM_SECURE_DECPROT1CLR_tzpc_clr_coresight_END (2)
#define SOC_FCM_SECURE_DECPROT1CLR_tzpc_clr_local_peri_START (3)
#define SOC_FCM_SECURE_DECPROT1CLR_tzpc_clr_local_peri_END (3)
#define SOC_FCM_SECURE_DECPROT1CLR_tzpc_clr_hw_spi0_START (4)
#define SOC_FCM_SECURE_DECPROT1CLR_tzpc_clr_hw_spi0_END (4)
#define SOC_FCM_SECURE_DECPROT1CLR_tzpc_clr_local_gic_START (5)
#define SOC_FCM_SECURE_DECPROT1CLR_tzpc_clr_local_gic_END (5)
#define SOC_FCM_SECURE_DECPROT1CLR_tzpc_clr_lp_mon_START (6)
#define SOC_FCM_SECURE_DECPROT1CLR_tzpc_clr_lp_mon_END (6)
#define SOC_FCM_SECURE_DECPROT1CLR_tzpc_clr_hw_spi1_START (7)
#define SOC_FCM_SECURE_DECPROT1CLR_tzpc_clr_hw_spi1_END (7)
#define SOC_FCM_SECURE_DECPROT1CLR_tzpc_clr_rtm_START (8)
#define SOC_FCM_SECURE_DECPROT1CLR_tzpc_clr_rtm_END (8)
#define SOC_FCM_SECURE_DECPROT1CLR_tzpc_clr_core_crg_START (14)
#define SOC_FCM_SECURE_DECPROT1CLR_tzpc_clr_core_crg_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tzpc_stat_cpuctrl_nsec0 : 1;
        unsigned int tzpc_stat_cpuctrl_nsec1 : 1;
        unsigned int tzpc_stat_cpuctrl_nsec2 : 1;
        unsigned int tzpc_stat_cpuctrl_sec3 : 1;
        unsigned int reserved : 12;
        unsigned int tzpc_stat_cpu_lpctrl : 16;
    } reg;
} SOC_FCM_SECURE_DECPROT2STAT_UNION;
#endif
#define SOC_FCM_SECURE_DECPROT2STAT_tzpc_stat_cpuctrl_nsec0_START (0)
#define SOC_FCM_SECURE_DECPROT2STAT_tzpc_stat_cpuctrl_nsec0_END (0)
#define SOC_FCM_SECURE_DECPROT2STAT_tzpc_stat_cpuctrl_nsec1_START (1)
#define SOC_FCM_SECURE_DECPROT2STAT_tzpc_stat_cpuctrl_nsec1_END (1)
#define SOC_FCM_SECURE_DECPROT2STAT_tzpc_stat_cpuctrl_nsec2_START (2)
#define SOC_FCM_SECURE_DECPROT2STAT_tzpc_stat_cpuctrl_nsec2_END (2)
#define SOC_FCM_SECURE_DECPROT2STAT_tzpc_stat_cpuctrl_sec3_START (3)
#define SOC_FCM_SECURE_DECPROT2STAT_tzpc_stat_cpuctrl_sec3_END (3)
#define SOC_FCM_SECURE_DECPROT2STAT_tzpc_stat_cpu_lpctrl_START (16)
#define SOC_FCM_SECURE_DECPROT2STAT_tzpc_stat_cpu_lpctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tzpc_set_cpuctrl_nsec0 : 1;
        unsigned int tzpc_set_cpuctrl_nsec1 : 1;
        unsigned int tzpc_set_cpuctrl_nsec2 : 1;
        unsigned int tzpc_set_cpuctrl_sec3 : 1;
        unsigned int reserved : 12;
        unsigned int tzpc_set_cpu_lpctrl : 16;
    } reg;
} SOC_FCM_SECURE_DECPROT2SET_UNION;
#endif
#define SOC_FCM_SECURE_DECPROT2SET_tzpc_set_cpuctrl_nsec0_START (0)
#define SOC_FCM_SECURE_DECPROT2SET_tzpc_set_cpuctrl_nsec0_END (0)
#define SOC_FCM_SECURE_DECPROT2SET_tzpc_set_cpuctrl_nsec1_START (1)
#define SOC_FCM_SECURE_DECPROT2SET_tzpc_set_cpuctrl_nsec1_END (1)
#define SOC_FCM_SECURE_DECPROT2SET_tzpc_set_cpuctrl_nsec2_START (2)
#define SOC_FCM_SECURE_DECPROT2SET_tzpc_set_cpuctrl_nsec2_END (2)
#define SOC_FCM_SECURE_DECPROT2SET_tzpc_set_cpuctrl_sec3_START (3)
#define SOC_FCM_SECURE_DECPROT2SET_tzpc_set_cpuctrl_sec3_END (3)
#define SOC_FCM_SECURE_DECPROT2SET_tzpc_set_cpu_lpctrl_START (16)
#define SOC_FCM_SECURE_DECPROT2SET_tzpc_set_cpu_lpctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tzpc_clr_cpuctrl_nsec0 : 1;
        unsigned int tzpc_clr_cpuctrl_nsec1 : 1;
        unsigned int tzpc_clr_cpuctrl_nsec2 : 1;
        unsigned int tzpc_clr_cpuctrl_sec3 : 1;
        unsigned int reserved : 12;
        unsigned int tzpc_clr_cpu_lpctrl : 16;
    } reg;
} SOC_FCM_SECURE_DECPROT2CLR_UNION;
#endif
#define SOC_FCM_SECURE_DECPROT2CLR_tzpc_clr_cpuctrl_nsec0_START (0)
#define SOC_FCM_SECURE_DECPROT2CLR_tzpc_clr_cpuctrl_nsec0_END (0)
#define SOC_FCM_SECURE_DECPROT2CLR_tzpc_clr_cpuctrl_nsec1_START (1)
#define SOC_FCM_SECURE_DECPROT2CLR_tzpc_clr_cpuctrl_nsec1_END (1)
#define SOC_FCM_SECURE_DECPROT2CLR_tzpc_clr_cpuctrl_nsec2_START (2)
#define SOC_FCM_SECURE_DECPROT2CLR_tzpc_clr_cpuctrl_nsec2_END (2)
#define SOC_FCM_SECURE_DECPROT2CLR_tzpc_clr_cpuctrl_sec3_START (3)
#define SOC_FCM_SECURE_DECPROT2CLR_tzpc_clr_cpuctrl_sec3_END (3)
#define SOC_FCM_SECURE_DECPROT2CLR_tzpc_clr_cpu_lpctrl_START (16)
#define SOC_FCM_SECURE_DECPROT2CLR_tzpc_clr_cpu_lpctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lit_tzpc_stat_local_cpu : 1;
        unsigned int lit_tzpc_stat_local_core0 : 1;
        unsigned int lit_tzpc_stat_local_core1 : 1;
        unsigned int lit_tzpc_stat_local_core2 : 1;
        unsigned int lit_tzpc_stat_local_core3 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int lit_tzpc_stat_local_ip : 1;
        unsigned int lit_tzpc_stat_local_linx_djtag : 1;
        unsigned int reserved_4 : 21;
    } reg;
} SOC_FCM_SECURE_DECPROT3STAT_UNION;
#endif
#define SOC_FCM_SECURE_DECPROT3STAT_lit_tzpc_stat_local_cpu_START (0)
#define SOC_FCM_SECURE_DECPROT3STAT_lit_tzpc_stat_local_cpu_END (0)
#define SOC_FCM_SECURE_DECPROT3STAT_lit_tzpc_stat_local_core0_START (1)
#define SOC_FCM_SECURE_DECPROT3STAT_lit_tzpc_stat_local_core0_END (1)
#define SOC_FCM_SECURE_DECPROT3STAT_lit_tzpc_stat_local_core1_START (2)
#define SOC_FCM_SECURE_DECPROT3STAT_lit_tzpc_stat_local_core1_END (2)
#define SOC_FCM_SECURE_DECPROT3STAT_lit_tzpc_stat_local_core2_START (3)
#define SOC_FCM_SECURE_DECPROT3STAT_lit_tzpc_stat_local_core2_END (3)
#define SOC_FCM_SECURE_DECPROT3STAT_lit_tzpc_stat_local_core3_START (4)
#define SOC_FCM_SECURE_DECPROT3STAT_lit_tzpc_stat_local_core3_END (4)
#define SOC_FCM_SECURE_DECPROT3STAT_lit_tzpc_stat_local_ip_START (9)
#define SOC_FCM_SECURE_DECPROT3STAT_lit_tzpc_stat_local_ip_END (9)
#define SOC_FCM_SECURE_DECPROT3STAT_lit_tzpc_stat_local_linx_djtag_START (10)
#define SOC_FCM_SECURE_DECPROT3STAT_lit_tzpc_stat_local_linx_djtag_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lit_tzpc_set_local_cpu : 1;
        unsigned int lit_tzpc_set_local_core0 : 1;
        unsigned int lit_tzpc_set_local_core1 : 1;
        unsigned int lit_tzpc_set_local_core2 : 1;
        unsigned int lit_tzpc_set_local_core3 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int lit_tzpc_set_local_ip : 1;
        unsigned int lit_tzpc_set_local_linx_djtag : 1;
        unsigned int reserved_4 : 21;
    } reg;
} SOC_FCM_SECURE_DECPROT3SET_UNION;
#endif
#define SOC_FCM_SECURE_DECPROT3SET_lit_tzpc_set_local_cpu_START (0)
#define SOC_FCM_SECURE_DECPROT3SET_lit_tzpc_set_local_cpu_END (0)
#define SOC_FCM_SECURE_DECPROT3SET_lit_tzpc_set_local_core0_START (1)
#define SOC_FCM_SECURE_DECPROT3SET_lit_tzpc_set_local_core0_END (1)
#define SOC_FCM_SECURE_DECPROT3SET_lit_tzpc_set_local_core1_START (2)
#define SOC_FCM_SECURE_DECPROT3SET_lit_tzpc_set_local_core1_END (2)
#define SOC_FCM_SECURE_DECPROT3SET_lit_tzpc_set_local_core2_START (3)
#define SOC_FCM_SECURE_DECPROT3SET_lit_tzpc_set_local_core2_END (3)
#define SOC_FCM_SECURE_DECPROT3SET_lit_tzpc_set_local_core3_START (4)
#define SOC_FCM_SECURE_DECPROT3SET_lit_tzpc_set_local_core3_END (4)
#define SOC_FCM_SECURE_DECPROT3SET_lit_tzpc_set_local_ip_START (9)
#define SOC_FCM_SECURE_DECPROT3SET_lit_tzpc_set_local_ip_END (9)
#define SOC_FCM_SECURE_DECPROT3SET_lit_tzpc_set_local_linx_djtag_START (10)
#define SOC_FCM_SECURE_DECPROT3SET_lit_tzpc_set_local_linx_djtag_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lit_tzpc_clr_local_cpu : 1;
        unsigned int lit_tzpc_clr_local_core0 : 1;
        unsigned int lit_tzpc_clr_local_core1 : 1;
        unsigned int lit_tzpc_clr_local_core2 : 1;
        unsigned int lit_tzpc_clr_local_core3 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int lit_tzpc_clr_local_ip : 1;
        unsigned int lit_tzpc_clr_local_linx_djtag : 1;
        unsigned int reserved_4 : 21;
    } reg;
} SOC_FCM_SECURE_DECPROT3CLR_UNION;
#endif
#define SOC_FCM_SECURE_DECPROT3CLR_lit_tzpc_clr_local_cpu_START (0)
#define SOC_FCM_SECURE_DECPROT3CLR_lit_tzpc_clr_local_cpu_END (0)
#define SOC_FCM_SECURE_DECPROT3CLR_lit_tzpc_clr_local_core0_START (1)
#define SOC_FCM_SECURE_DECPROT3CLR_lit_tzpc_clr_local_core0_END (1)
#define SOC_FCM_SECURE_DECPROT3CLR_lit_tzpc_clr_local_core1_START (2)
#define SOC_FCM_SECURE_DECPROT3CLR_lit_tzpc_clr_local_core1_END (2)
#define SOC_FCM_SECURE_DECPROT3CLR_lit_tzpc_clr_local_core2_START (3)
#define SOC_FCM_SECURE_DECPROT3CLR_lit_tzpc_clr_local_core2_END (3)
#define SOC_FCM_SECURE_DECPROT3CLR_lit_tzpc_clr_local_core3_START (4)
#define SOC_FCM_SECURE_DECPROT3CLR_lit_tzpc_clr_local_core3_END (4)
#define SOC_FCM_SECURE_DECPROT3CLR_lit_tzpc_clr_local_ip_START (9)
#define SOC_FCM_SECURE_DECPROT3CLR_lit_tzpc_clr_local_ip_END (9)
#define SOC_FCM_SECURE_DECPROT3CLR_lit_tzpc_clr_local_linx_djtag_START (10)
#define SOC_FCM_SECURE_DECPROT3CLR_lit_tzpc_clr_local_linx_djtag_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tzpc_stat_hc_pwoer : 1;
        unsigned int tzpc_stat_hc_pmu : 1;
        unsigned int tzpc_stat_hc_flush : 1;
        unsigned int tzpc_stat_hc_ras : 1;
        unsigned int tzpc_stat_hc_secure : 1;
        unsigned int tzpc_stat_hc_pwe : 1;
        unsigned int tzpc_stat_hc_mem : 1;
        unsigned int tzpc_stat_hc_mpam_ns : 1;
        unsigned int tzpc_stat_lit_core_amu : 1;
        unsigned int tzpc_stat_mid_core_amu : 1;
        unsigned int tzpc_stat_big_core_amu : 1;
        unsigned int tzpc_stat_lit_mpam : 1;
        unsigned int tzpc_stat_lit_ras : 1;
        unsigned int tzpc_stat_mid_mpam : 1;
        unsigned int tzpc_stat_mid_ras : 1;
        unsigned int tzpc_stat_big_mpam : 1;
        unsigned int tzpc_stat_big_ras : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_FCM_SECURE_DECPROT4STAT_UNION;
#endif
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_hc_pwoer_START (0)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_hc_pwoer_END (0)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_hc_pmu_START (1)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_hc_pmu_END (1)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_hc_flush_START (2)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_hc_flush_END (2)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_hc_ras_START (3)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_hc_ras_END (3)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_hc_secure_START (4)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_hc_secure_END (4)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_hc_pwe_START (5)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_hc_pwe_END (5)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_hc_mem_START (6)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_hc_mem_END (6)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_hc_mpam_ns_START (7)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_hc_mpam_ns_END (7)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_lit_core_amu_START (8)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_lit_core_amu_END (8)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_mid_core_amu_START (9)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_mid_core_amu_END (9)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_big_core_amu_START (10)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_big_core_amu_END (10)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_lit_mpam_START (11)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_lit_mpam_END (11)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_lit_ras_START (12)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_lit_ras_END (12)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_mid_mpam_START (13)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_mid_mpam_END (13)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_mid_ras_START (14)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_mid_ras_END (14)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_big_mpam_START (15)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_big_mpam_END (15)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_big_ras_START (16)
#define SOC_FCM_SECURE_DECPROT4STAT_tzpc_stat_big_ras_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tzpc_set_hc_pwoer : 1;
        unsigned int tzpc_set_hc_pmu : 1;
        unsigned int tzpc_set_hc_flush : 1;
        unsigned int tzpc_set_hc_ras : 1;
        unsigned int tzpc_set_hc_secure : 1;
        unsigned int tzpc_set_hc_pwe : 1;
        unsigned int tzpc_set_hc_mem : 1;
        unsigned int tzpc_set_hc_mpam_ns : 1;
        unsigned int tzpc_set_lit_core_amu : 1;
        unsigned int tzpc_set_mid_core_amu : 1;
        unsigned int tzpc_set_big_core_amu : 1;
        unsigned int tzpc_set_lit_mpam : 1;
        unsigned int tzpc_set_lit_ras : 1;
        unsigned int tzpc_set_mid_mpam : 1;
        unsigned int tzpc_set_mid_ras : 1;
        unsigned int tzpc_set_big_mpam : 1;
        unsigned int tzpc_set_big_ras : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_FCM_SECURE_DECPROT4SET_UNION;
#endif
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_hc_pwoer_START (0)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_hc_pwoer_END (0)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_hc_pmu_START (1)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_hc_pmu_END (1)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_hc_flush_START (2)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_hc_flush_END (2)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_hc_ras_START (3)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_hc_ras_END (3)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_hc_secure_START (4)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_hc_secure_END (4)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_hc_pwe_START (5)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_hc_pwe_END (5)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_hc_mem_START (6)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_hc_mem_END (6)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_hc_mpam_ns_START (7)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_hc_mpam_ns_END (7)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_lit_core_amu_START (8)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_lit_core_amu_END (8)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_mid_core_amu_START (9)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_mid_core_amu_END (9)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_big_core_amu_START (10)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_big_core_amu_END (10)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_lit_mpam_START (11)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_lit_mpam_END (11)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_lit_ras_START (12)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_lit_ras_END (12)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_mid_mpam_START (13)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_mid_mpam_END (13)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_mid_ras_START (14)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_mid_ras_END (14)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_big_mpam_START (15)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_big_mpam_END (15)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_big_ras_START (16)
#define SOC_FCM_SECURE_DECPROT4SET_tzpc_set_big_ras_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tzpc_clr_hc_pwoer : 1;
        unsigned int tzpc_clr_hc_pmu : 1;
        unsigned int tzpc_clr_hc_flush : 1;
        unsigned int tzpc_clr_hc_ras : 1;
        unsigned int tzpc_clr_hc_secure : 1;
        unsigned int tzpc_clr_hc_pwe : 1;
        unsigned int tzpc_clr_hc_mem : 1;
        unsigned int tzpc_clr_hc_mpam_ns : 1;
        unsigned int tzpc_clr_lit_core_amu : 1;
        unsigned int tzpc_clr_mid_core_amu : 1;
        unsigned int tzpc_clr_big_core_amu : 1;
        unsigned int tzpc_clr_lit_mpam : 1;
        unsigned int tzpc_clr_lit_ras : 1;
        unsigned int tzpc_clr_mid_mpam : 1;
        unsigned int tzpc_clr_mid_ras : 1;
        unsigned int tzpc_clr_big_mpam : 1;
        unsigned int tzpc_clr_big_ras : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_FCM_SECURE_DECPROT4CLR_UNION;
#endif
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_hc_pwoer_START (0)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_hc_pwoer_END (0)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_hc_pmu_START (1)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_hc_pmu_END (1)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_hc_flush_START (2)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_hc_flush_END (2)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_hc_ras_START (3)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_hc_ras_END (3)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_hc_secure_START (4)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_hc_secure_END (4)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_hc_pwe_START (5)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_hc_pwe_END (5)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_hc_mem_START (6)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_hc_mem_END (6)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_hc_mpam_ns_START (7)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_hc_mpam_ns_END (7)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_lit_core_amu_START (8)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_lit_core_amu_END (8)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_mid_core_amu_START (9)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_mid_core_amu_END (9)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_big_core_amu_START (10)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_big_core_amu_END (10)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_lit_mpam_START (11)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_lit_mpam_END (11)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_lit_ras_START (12)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_lit_ras_END (12)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_mid_mpam_START (13)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_mid_mpam_END (13)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_mid_ras_START (14)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_mid_ras_END (14)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_big_mpam_START (15)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_big_mpam_END (15)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_big_ras_START (16)
#define SOC_FCM_SECURE_DECPROT4CLR_tzpc_clr_big_ras_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_SECURE_DECPROT5STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_SECURE_DECPROT5SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_SECURE_DECPROT5CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_SECURE_DECPROT6STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_SECURE_DECPROT6SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_SECURE_DECPROT6CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_SECURE_DECPROT7STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_SECURE_DECPROT7SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_SECURE_DECPROT7CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_SECURE_DECPROT8STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_SECURE_DECPROT8SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_SECURE_DECPROT8CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_SECURE_REG0_STAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_FCM_SECURE_REG1_STAT_UNION;
#endif
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
