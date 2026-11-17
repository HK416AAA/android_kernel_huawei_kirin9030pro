#ifndef __SOC_FCM_LOCALS_INTERFACE_H__
#define __SOC_FCM_LOCALS_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FCM_LOCALS_FCM_BOOT_CFG_REG_ADDR(base) ((base) + (0x004UL))
#define SOC_FCM_LOCALS_FCM_PERIPORT_ADDR_CFG_REG_ADDR(base) ((base) + (0x008UL))
#define SOC_FCM_LOCALS_FCM_SECURE_DEBUG_CFG_REG_ADDR(base) ((base) + (0x00CUL))
#define SOC_FCM_LOCALS_FCM_CORE0_BOOT_CFG_REG_ADDR(base) ((base) + (0x010UL))
#define SOC_FCM_LOCALS_FCM_CORE1_BOOT_CFG_REG_ADDR(base) ((base) + (0x014UL))
#define SOC_FCM_LOCALS_FCM_CORE2_BOOT_CFG_REG_ADDR(base) ((base) + (0x018UL))
#define SOC_FCM_LOCALS_FCM_CORE3_BOOT_CFG_REG_ADDR(base) ((base) + (0x01CUL))
#define SOC_FCM_LOCALS_FCM_CORE4_BOOT_CFG_REG_ADDR(base) ((base) + (0x020UL))
#define SOC_FCM_LOCALS_FCM_CORE5_BOOT_CFG_REG_ADDR(base) ((base) + (0x024UL))
#define SOC_FCM_LOCALS_FCM_CORE6_BOOT_CFG_REG_ADDR(base) ((base) + (0x028UL))
#define SOC_FCM_LOCALS_FCM_CORE7_BOOT_CFG_REG_ADDR(base) ((base) + (0x02CUL))
#define SOC_FCM_LOCALS_FCM_GIC_REQ_CFG_REG_ADDR(base) ((base) + (0x030UL))
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL13_ADDR(base) ((base) + (0x034UL))
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL14_ADDR(base) ((base) + (0x038UL))
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL15_ADDR(base) ((base) + (0x03CUL))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT0_ADDR(base) ((base) + (0x200UL))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT1_ADDR(base) ((base) + (0x204UL))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT2_ADDR(base) ((base) + (0x208UL))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT3_ADDR(base) ((base) + (0x20CUL))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT4_ADDR(base) ((base) + (0x210UL))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT5_ADDR(base) ((base) + (0x214UL))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT6_ADDR(base) ((base) + (0x218UL))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT7_ADDR(base) ((base) + (0x21CUL))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT14_ADDR(base) ((base) + (0x238UL))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT15_ADDR(base) ((base) + (0x23CUL))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT16_ADDR(base) ((base) + (0x240UL))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT17_ADDR(base) ((base) + (0x244UL))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT18_ADDR(base) ((base) + (0x248UL))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT19_ADDR(base) ((base) + (0x24CUL))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT20_ADDR(base) ((base) + (0x250UL))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT21_ADDR(base) ((base) + (0x254UL))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT22_ADDR(base) ((base) + (0x258UL))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT23_ADDR(base) ((base) + (0x25CUL))
#else
#define SOC_FCM_LOCALS_FCM_BOOT_CFG_REG_ADDR(base) ((base) + (0x004))
#define SOC_FCM_LOCALS_FCM_PERIPORT_ADDR_CFG_REG_ADDR(base) ((base) + (0x008))
#define SOC_FCM_LOCALS_FCM_SECURE_DEBUG_CFG_REG_ADDR(base) ((base) + (0x00C))
#define SOC_FCM_LOCALS_FCM_CORE0_BOOT_CFG_REG_ADDR(base) ((base) + (0x010))
#define SOC_FCM_LOCALS_FCM_CORE1_BOOT_CFG_REG_ADDR(base) ((base) + (0x014))
#define SOC_FCM_LOCALS_FCM_CORE2_BOOT_CFG_REG_ADDR(base) ((base) + (0x018))
#define SOC_FCM_LOCALS_FCM_CORE3_BOOT_CFG_REG_ADDR(base) ((base) + (0x01C))
#define SOC_FCM_LOCALS_FCM_CORE4_BOOT_CFG_REG_ADDR(base) ((base) + (0x020))
#define SOC_FCM_LOCALS_FCM_CORE5_BOOT_CFG_REG_ADDR(base) ((base) + (0x024))
#define SOC_FCM_LOCALS_FCM_CORE6_BOOT_CFG_REG_ADDR(base) ((base) + (0x028))
#define SOC_FCM_LOCALS_FCM_CORE7_BOOT_CFG_REG_ADDR(base) ((base) + (0x02C))
#define SOC_FCM_LOCALS_FCM_GIC_REQ_CFG_REG_ADDR(base) ((base) + (0x030))
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL13_ADDR(base) ((base) + (0x034))
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL14_ADDR(base) ((base) + (0x038))
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL15_ADDR(base) ((base) + (0x03C))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT0_ADDR(base) ((base) + (0x200))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT1_ADDR(base) ((base) + (0x204))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT2_ADDR(base) ((base) + (0x208))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT3_ADDR(base) ((base) + (0x20C))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT4_ADDR(base) ((base) + (0x210))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT5_ADDR(base) ((base) + (0x214))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT6_ADDR(base) ((base) + (0x218))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT7_ADDR(base) ((base) + (0x21C))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT14_ADDR(base) ((base) + (0x238))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT15_ADDR(base) ((base) + (0x23C))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT16_ADDR(base) ((base) + (0x240))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT17_ADDR(base) ((base) + (0x244))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT18_ADDR(base) ((base) + (0x248))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT19_ADDR(base) ((base) + (0x24C))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT20_ADDR(base) ((base) + (0x250))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT21_ADDR(base) ((base) + (0x254))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT22_ADDR(base) ((base) + (0x258))
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT23_ADDR(base) ((base) + (0x25C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rvbaraddr0_high : 4;
        unsigned int rvbaraddr1_high : 4;
        unsigned int rvbaraddr2_high : 4;
        unsigned int rvbaraddr3_high : 4;
        unsigned int rvbaraddr4_high : 4;
        unsigned int rvbaraddr5_high : 4;
        unsigned int rvbaraddr6_high : 4;
        unsigned int rvbaraddr7_high : 4;
    } reg;
} SOC_FCM_LOCALS_FCM_BOOT_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_BOOT_CFG_REG_rvbaraddr0_high_START (0)
#define SOC_FCM_LOCALS_FCM_BOOT_CFG_REG_rvbaraddr0_high_END (3)
#define SOC_FCM_LOCALS_FCM_BOOT_CFG_REG_rvbaraddr1_high_START (4)
#define SOC_FCM_LOCALS_FCM_BOOT_CFG_REG_rvbaraddr1_high_END (7)
#define SOC_FCM_LOCALS_FCM_BOOT_CFG_REG_rvbaraddr2_high_START (8)
#define SOC_FCM_LOCALS_FCM_BOOT_CFG_REG_rvbaraddr2_high_END (11)
#define SOC_FCM_LOCALS_FCM_BOOT_CFG_REG_rvbaraddr3_high_START (12)
#define SOC_FCM_LOCALS_FCM_BOOT_CFG_REG_rvbaraddr3_high_END (15)
#define SOC_FCM_LOCALS_FCM_BOOT_CFG_REG_rvbaraddr4_high_START (16)
#define SOC_FCM_LOCALS_FCM_BOOT_CFG_REG_rvbaraddr4_high_END (19)
#define SOC_FCM_LOCALS_FCM_BOOT_CFG_REG_rvbaraddr5_high_START (20)
#define SOC_FCM_LOCALS_FCM_BOOT_CFG_REG_rvbaraddr5_high_END (23)
#define SOC_FCM_LOCALS_FCM_BOOT_CFG_REG_rvbaraddr6_high_START (24)
#define SOC_FCM_LOCALS_FCM_BOOT_CFG_REG_rvbaraddr6_high_END (27)
#define SOC_FCM_LOCALS_FCM_BOOT_CFG_REG_rvbaraddr7_high_START (28)
#define SOC_FCM_LOCALS_FCM_BOOT_CFG_REG_rvbaraddr7_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int astartmp : 16;
        unsigned int aendmp : 16;
    } reg;
} SOC_FCM_LOCALS_FCM_PERIPORT_ADDR_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_PERIPORT_ADDR_CFG_REG_astartmp_START (0)
#define SOC_FCM_LOCALS_FCM_PERIPORT_ADDR_CFG_REG_astartmp_END (15)
#define SOC_FCM_LOCALS_FCM_PERIPORT_ADDR_CFG_REG_aendmp_START (16)
#define SOC_FCM_LOCALS_FCM_PERIPORT_ADDR_CFG_REG_aendmp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int secure_debug_en : 1;
        unsigned int soft_debug_halted : 1;
        unsigned int ananke_stretch_l2ramclk_en : 1;
        unsigned int enyo_middle_stretch_l2ramclk_en : 1;
        unsigned int enyo_fast_stretch_l2ramclk_en : 1;
        unsigned int fcm_stretch_l3ramclk_en : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_FCM_LOCALS_FCM_SECURE_DEBUG_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_SECURE_DEBUG_CFG_REG_secure_debug_en_START (0)
#define SOC_FCM_LOCALS_FCM_SECURE_DEBUG_CFG_REG_secure_debug_en_END (0)
#define SOC_FCM_LOCALS_FCM_SECURE_DEBUG_CFG_REG_soft_debug_halted_START (1)
#define SOC_FCM_LOCALS_FCM_SECURE_DEBUG_CFG_REG_soft_debug_halted_END (1)
#define SOC_FCM_LOCALS_FCM_SECURE_DEBUG_CFG_REG_ananke_stretch_l2ramclk_en_START (2)
#define SOC_FCM_LOCALS_FCM_SECURE_DEBUG_CFG_REG_ananke_stretch_l2ramclk_en_END (2)
#define SOC_FCM_LOCALS_FCM_SECURE_DEBUG_CFG_REG_enyo_middle_stretch_l2ramclk_en_START (3)
#define SOC_FCM_LOCALS_FCM_SECURE_DEBUG_CFG_REG_enyo_middle_stretch_l2ramclk_en_END (3)
#define SOC_FCM_LOCALS_FCM_SECURE_DEBUG_CFG_REG_enyo_fast_stretch_l2ramclk_en_START (4)
#define SOC_FCM_LOCALS_FCM_SECURE_DEBUG_CFG_REG_enyo_fast_stretch_l2ramclk_en_END (4)
#define SOC_FCM_LOCALS_FCM_SECURE_DEBUG_CFG_REG_fcm_stretch_l3ramclk_en_START (5)
#define SOC_FCM_LOCALS_FCM_SECURE_DEBUG_CFG_REG_fcm_stretch_l3ramclk_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rvbaraddr0 : 32;
    } reg;
} SOC_FCM_LOCALS_FCM_CORE0_BOOT_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_CORE0_BOOT_CFG_REG_rvbaraddr0_START (0)
#define SOC_FCM_LOCALS_FCM_CORE0_BOOT_CFG_REG_rvbaraddr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rvbaraddr1 : 32;
    } reg;
} SOC_FCM_LOCALS_FCM_CORE1_BOOT_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_CORE1_BOOT_CFG_REG_rvbaraddr1_START (0)
#define SOC_FCM_LOCALS_FCM_CORE1_BOOT_CFG_REG_rvbaraddr1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rvbaraddr2 : 32;
    } reg;
} SOC_FCM_LOCALS_FCM_CORE2_BOOT_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_CORE2_BOOT_CFG_REG_rvbaraddr2_START (0)
#define SOC_FCM_LOCALS_FCM_CORE2_BOOT_CFG_REG_rvbaraddr2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rvbaraddr3 : 32;
    } reg;
} SOC_FCM_LOCALS_FCM_CORE3_BOOT_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_CORE3_BOOT_CFG_REG_rvbaraddr3_START (0)
#define SOC_FCM_LOCALS_FCM_CORE3_BOOT_CFG_REG_rvbaraddr3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rvbaraddr4 : 32;
    } reg;
} SOC_FCM_LOCALS_FCM_CORE4_BOOT_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_CORE4_BOOT_CFG_REG_rvbaraddr4_START (0)
#define SOC_FCM_LOCALS_FCM_CORE4_BOOT_CFG_REG_rvbaraddr4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rvbaraddr5 : 32;
    } reg;
} SOC_FCM_LOCALS_FCM_CORE5_BOOT_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_CORE5_BOOT_CFG_REG_rvbaraddr5_START (0)
#define SOC_FCM_LOCALS_FCM_CORE5_BOOT_CFG_REG_rvbaraddr5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rvbaraddr6 : 32;
    } reg;
} SOC_FCM_LOCALS_FCM_CORE6_BOOT_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_CORE6_BOOT_CFG_REG_rvbaraddr6_START (0)
#define SOC_FCM_LOCALS_FCM_CORE6_BOOT_CFG_REG_rvbaraddr6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rvbaraddr7 : 32;
    } reg;
} SOC_FCM_LOCALS_FCM_CORE7_BOOT_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_CORE7_BOOT_CFG_REG_rvbaraddr7_START (0)
#define SOC_FCM_LOCALS_FCM_CORE7_BOOT_CFG_REG_rvbaraddr7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gic_req_for_pending : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FCM_LOCALS_FCM_GIC_REQ_CFG_REG_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_GIC_REQ_CFG_REG_gic_req_for_pending_START (0)
#define SOC_FCM_LOCALS_FCM_GIC_REQ_CFG_REG_gic_req_for_pending_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int acp_ardomain : 2;
        unsigned int acp_awdomain : 2;
        unsigned int reserved : 28;
    } reg;
} SOC_FCM_LOCALS_FCM_LOCAL_CTRL13_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL13_acp_ardomain_START (0)
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL13_acp_ardomain_END (1)
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL13_acp_awdomain_START (2)
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL13_acp_awdomain_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbgnopwrdwn_patch : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_LOCALS_FCM_LOCAL_CTRL14_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL14_dbgnopwrdwn_patch_START (0)
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL14_dbgnopwrdwn_patch_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_eventi_npu_enable : 1;
        unsigned int enable_mid_core_mitigation : 1;
        unsigned int enable_mid_corewfe_include_maxpower : 1;
        unsigned int enable_big_core_mitigation : 1;
        unsigned int enable_big_corewfe_include_maxpower : 1;
        unsigned int enable_mid_core_renamefix : 1;
        unsigned int enable_big_core_renamefix : 1;
        unsigned int enable_mid_core_didt : 1;
        unsigned int enable_big_core_didt : 1;
        unsigned int pcr_m_sel : 2;
        unsigned int pcr_b_sel : 2;
        unsigned int cpu_m_pi_sel : 4;
        unsigned int cpu_b_pi_sel : 3;
        unsigned int reserved : 12;
    } reg;
} SOC_FCM_LOCALS_FCM_LOCAL_CTRL15_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL15_tcu_eventi_npu_enable_START (0)
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL15_tcu_eventi_npu_enable_END (0)
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL15_enable_mid_core_mitigation_START (1)
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL15_enable_mid_core_mitigation_END (1)
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL15_enable_mid_corewfe_include_maxpower_START (2)
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL15_enable_mid_corewfe_include_maxpower_END (2)
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL15_enable_big_core_mitigation_START (3)
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL15_enable_big_core_mitigation_END (3)
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL15_enable_big_corewfe_include_maxpower_START (4)
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL15_enable_big_corewfe_include_maxpower_END (4)
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL15_enable_mid_core_renamefix_START (5)
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL15_enable_mid_core_renamefix_END (5)
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL15_enable_big_core_renamefix_START (6)
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL15_enable_big_core_renamefix_END (6)
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL15_enable_mid_core_didt_START (7)
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL15_enable_mid_core_didt_END (7)
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL15_enable_big_core_didt_START (8)
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL15_enable_big_core_didt_END (8)
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL15_pcr_m_sel_START (9)
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL15_pcr_m_sel_END (10)
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL15_pcr_b_sel_START (11)
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL15_pcr_b_sel_END (12)
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL15_cpu_m_pi_sel_START (13)
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL15_cpu_m_pi_sel_END (16)
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL15_cpu_b_pi_sel_START (17)
#define SOC_FCM_LOCALS_FCM_LOCAL_CTRL15_cpu_b_pi_sel_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_l3_sdo_dbg : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_FCM_LOCALS_FCM_LOCAL_STAT0_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT0_fcm_l3_sdo_dbg_START (0)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT0_fcm_l3_sdo_dbg_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_l3_dso_dbg : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_FCM_LOCALS_FCM_LOCAL_STAT1_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT1_fcm_l3_dso_dbg_START (0)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT1_fcm_l3_dso_dbg_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ananke0_sdo_dbg : 1;
        unsigned int ananke1_sdo_dbg : 1;
        unsigned int ananke2_sdo_dbg : 1;
        unsigned int ananke3_sdo_dbg : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_FCM_LOCALS_FCM_LOCAL_STAT2_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT2_ananke0_sdo_dbg_START (0)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT2_ananke0_sdo_dbg_END (0)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT2_ananke1_sdo_dbg_START (1)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT2_ananke1_sdo_dbg_END (1)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT2_ananke2_sdo_dbg_START (2)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT2_ananke2_sdo_dbg_END (2)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT2_ananke3_sdo_dbg_START (3)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT2_ananke3_sdo_dbg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ananke0_dso_dbg : 4;
        unsigned int ananke1_dso_dbg : 4;
        unsigned int ananke2_dso_dbg : 4;
        unsigned int ananke3_dso_dbg : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_FCM_LOCALS_FCM_LOCAL_STAT3_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT3_ananke0_dso_dbg_START (0)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT3_ananke0_dso_dbg_END (3)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT3_ananke1_dso_dbg_START (4)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT3_ananke1_dso_dbg_END (7)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT3_ananke2_dso_dbg_START (8)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT3_ananke2_dso_dbg_END (11)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT3_ananke3_dso_dbg_START (12)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT3_ananke3_dso_dbg_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_enyo0_sdo_dbg : 1;
        unsigned int mid_enyo1_sdo_dbg : 1;
        unsigned int mid_enyo2_sdo_dbg : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_FCM_LOCALS_FCM_LOCAL_STAT4_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT4_mid_enyo0_sdo_dbg_START (0)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT4_mid_enyo0_sdo_dbg_END (0)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT4_mid_enyo1_sdo_dbg_START (1)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT4_mid_enyo1_sdo_dbg_END (1)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT4_mid_enyo2_sdo_dbg_START (2)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT4_mid_enyo2_sdo_dbg_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_enyo0_dso_dbg : 10;
        unsigned int mid_enyo1_dso_dbg : 10;
        unsigned int mid_enyo2_dso_dbg : 10;
        unsigned int reserved : 2;
    } reg;
} SOC_FCM_LOCALS_FCM_LOCAL_STAT5_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT5_mid_enyo0_dso_dbg_START (0)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT5_mid_enyo0_dso_dbg_END (9)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT5_mid_enyo1_dso_dbg_START (10)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT5_mid_enyo1_dso_dbg_END (19)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT5_mid_enyo2_dso_dbg_START (20)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT5_mid_enyo2_dso_dbg_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int big_enyo0_sdo_dbg : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_LOCALS_FCM_LOCAL_STAT6_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT6_big_enyo0_sdo_dbg_START (0)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT6_big_enyo0_sdo_dbg_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int big_enyo0_dso_dbg : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_FCM_LOCALS_FCM_LOCAL_STAT7_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT7_big_enyo0_dso_dbg_START (0)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT7_big_enyo0_dso_dbg_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_pc_tidm_org_tidm0 : 10;
        unsigned int fcm_pc_stdcell_org_tidm0 : 10;
        unsigned int fcm_pc_vld_tidm0 : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_FCM_LOCALS_FCM_LOCAL_STAT14_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT14_fcm_pc_tidm_org_tidm0_START (0)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT14_fcm_pc_tidm_org_tidm0_END (9)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT14_fcm_pc_stdcell_org_tidm0_START (10)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT14_fcm_pc_stdcell_org_tidm0_END (19)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT14_fcm_pc_vld_tidm0_START (20)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT14_fcm_pc_vld_tidm0_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_pc_tidm_org_tidm1 : 10;
        unsigned int fcm_pc_stdcell_org_tidm1 : 10;
        unsigned int fcm_pc_vld_tidm1 : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_FCM_LOCALS_FCM_LOCAL_STAT15_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT15_fcm_pc_tidm_org_tidm1_START (0)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT15_fcm_pc_tidm_org_tidm1_END (9)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT15_fcm_pc_stdcell_org_tidm1_START (10)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT15_fcm_pc_stdcell_org_tidm1_END (19)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT15_fcm_pc_vld_tidm1_START (20)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT15_fcm_pc_vld_tidm1_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core0_pc_tidm_org_tidm0 : 10;
        unsigned int core0_pc_stdcell_org_tidm0 : 10;
        unsigned int core0_pc_vld_tidm0 : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_FCM_LOCALS_FCM_LOCAL_STAT16_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT16_core0_pc_tidm_org_tidm0_START (0)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT16_core0_pc_tidm_org_tidm0_END (9)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT16_core0_pc_stdcell_org_tidm0_START (10)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT16_core0_pc_stdcell_org_tidm0_END (19)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT16_core0_pc_vld_tidm0_START (20)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT16_core0_pc_vld_tidm0_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core1_pc_tidm_org_tidm0 : 10;
        unsigned int core1_pc_stdcell_org_tidm0 : 10;
        unsigned int core1_pc_vld_tidm0 : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_FCM_LOCALS_FCM_LOCAL_STAT17_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT17_core1_pc_tidm_org_tidm0_START (0)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT17_core1_pc_tidm_org_tidm0_END (9)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT17_core1_pc_stdcell_org_tidm0_START (10)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT17_core1_pc_stdcell_org_tidm0_END (19)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT17_core1_pc_vld_tidm0_START (20)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT17_core1_pc_vld_tidm0_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core2_pc_tidm_org_tidm0 : 10;
        unsigned int core2_pc_stdcell_org_tidm0 : 10;
        unsigned int core2_pc_vld_tidm0 : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_FCM_LOCALS_FCM_LOCAL_STAT18_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT18_core2_pc_tidm_org_tidm0_START (0)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT18_core2_pc_tidm_org_tidm0_END (9)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT18_core2_pc_stdcell_org_tidm0_START (10)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT18_core2_pc_stdcell_org_tidm0_END (19)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT18_core2_pc_vld_tidm0_START (20)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT18_core2_pc_vld_tidm0_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core3_pc_tidm_org_tidm0 : 10;
        unsigned int core3_pc_stdcell_org_tidm0 : 10;
        unsigned int core3_pc_vld_tidm0 : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_FCM_LOCALS_FCM_LOCAL_STAT19_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT19_core3_pc_tidm_org_tidm0_START (0)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT19_core3_pc_tidm_org_tidm0_END (9)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT19_core3_pc_stdcell_org_tidm0_START (10)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT19_core3_pc_stdcell_org_tidm0_END (19)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT19_core3_pc_vld_tidm0_START (20)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT19_core3_pc_vld_tidm0_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core4_pc_tidm_org_tidm0 : 10;
        unsigned int core4_pc_stdcell_org_tidm0 : 10;
        unsigned int core4_pc_vld_tidm0 : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_FCM_LOCALS_FCM_LOCAL_STAT20_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT20_core4_pc_tidm_org_tidm0_START (0)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT20_core4_pc_tidm_org_tidm0_END (9)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT20_core4_pc_stdcell_org_tidm0_START (10)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT20_core4_pc_stdcell_org_tidm0_END (19)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT20_core4_pc_vld_tidm0_START (20)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT20_core4_pc_vld_tidm0_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core5_pc_tidm_org_tidm0 : 10;
        unsigned int core5_pc_stdcell_org_tidm0 : 10;
        unsigned int core5_pc_vld_tidm0 : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_FCM_LOCALS_FCM_LOCAL_STAT21_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT21_core5_pc_tidm_org_tidm0_START (0)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT21_core5_pc_tidm_org_tidm0_END (9)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT21_core5_pc_stdcell_org_tidm0_START (10)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT21_core5_pc_stdcell_org_tidm0_END (19)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT21_core5_pc_vld_tidm0_START (20)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT21_core5_pc_vld_tidm0_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core6_pc_tidm_org_tidm0 : 10;
        unsigned int core6_pc_stdcell_org_tidm0 : 10;
        unsigned int core6_pc_vld_tidm0 : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_FCM_LOCALS_FCM_LOCAL_STAT22_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT22_core6_pc_tidm_org_tidm0_START (0)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT22_core6_pc_tidm_org_tidm0_END (9)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT22_core6_pc_stdcell_org_tidm0_START (10)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT22_core6_pc_stdcell_org_tidm0_END (19)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT22_core6_pc_vld_tidm0_START (20)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT22_core6_pc_vld_tidm0_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core7_pc_tidm_org_tidm0 : 10;
        unsigned int core7_pc_stdcell_org_tidm0 : 10;
        unsigned int core7_pc_vld_tidm0 : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_FCM_LOCALS_FCM_LOCAL_STAT23_UNION;
#endif
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT23_core7_pc_tidm_org_tidm0_START (0)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT23_core7_pc_tidm_org_tidm0_END (9)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT23_core7_pc_stdcell_org_tidm0_START (10)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT23_core7_pc_stdcell_org_tidm0_END (19)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT23_core7_pc_vld_tidm0_START (20)
#define SOC_FCM_LOCALS_FCM_LOCAL_STAT23_core7_pc_vld_tidm0_END (20)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
