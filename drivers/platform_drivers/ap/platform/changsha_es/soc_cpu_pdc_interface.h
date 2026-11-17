#ifndef __SOC_CPU_PDC_INTERFACE_H__
#define __SOC_CPU_PDC_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_CPU_PDC_PDCCTRL_ADDR(base) ((base) + (0x000UL))
#define SOC_CPU_PDC_ISOEN_ADDR(base) ((base) + (0x100UL))
#define SOC_CPU_PDC_ISODIS_ADDR(base) ((base) + (0x104UL))
#define SOC_CPU_PDC_ISOSTAT_ADDR(base) ((base) + (0x108UL))
#define SOC_CPU_PDC_PERPWREN_ADDR(base) ((base) + (0x110UL))
#define SOC_CPU_PDC_PERPWRDIS_ADDR(base) ((base) + (0x114UL))
#define SOC_CPU_PDC_PERPWRSTAT_ADDR(base) ((base) + (0x118UL))
#define SOC_CPU_PDC_PERPWRACK_ADDR(base) ((base) + (0x11CUL))
#define SOC_CPU_PDC_CPU_CLKEN_ADDR(base) ((base) + (0x120UL))
#define SOC_CPU_PDC_CPU_RSTEN_ADDR(base) ((base) + (0x124UL))
#define SOC_CPU_PDC_CPU_RSTDIS_ADDR(base) ((base) + (0x128UL))
#define SOC_CPU_PDC_CPU_RSTSTAT_ADDR(base) ((base) + (0x12CUL))
#define SOC_CPU_PDC_CPU_M0_ADBLPSTAT_ADDR(base) ((base) + (0x130UL))
#define SOC_CPU_PDC_CPU_M1_ADBLPSTAT_ADDR(base) ((base) + (0x134UL))
#define SOC_CPU_PDC_CPU_MP_ADBLPSTAT_ADDR(base) ((base) + (0x138UL))
#define SOC_CPU_PDC_CPU_ACP_ADBLPSTAT_ADDR(base) ((base) + (0x13CUL))
#define SOC_CPU_PDC_CPU_ADB_GT_CFG_ADDR(base) ((base) + (0x140UL))
#define SOC_CPU_PDC_CPU_STAT0_ADDR(base) ((base) + (0x144UL))
#define SOC_CPU_PDC_WAKEUPINT_STAT_ADDR(base) ((base) + (0x148UL))
#define SOC_CPU_PDC_CPU_LIT_ADBLPSTAT_ADDR(base) ((base) + (0x14CUL))
#define SOC_CPU_PDC_CPU_PDCEN_ADDR(base) ((base) + (0x200UL))
#define SOC_CPU_PDC_LITTLE_COREPWRINTEN_ADDR(base) ((base) + (0x204UL))
#define SOC_CPU_PDC_LITTLE_COREPWRINTSTAT_ADDR(base) ((base) + (0x208UL))
#define SOC_CPU_PDC_LITTLE_COREPOWERUP_ADDR(base) ((base) + (0x210UL))
#define SOC_CPU_PDC_LITTLE_COREPOWERDN_ADDR(base) ((base) + (0x214UL))
#define SOC_CPU_PDC_LITTLE_COREPOWERSTAT_ADDR(base) ((base) + (0x218UL))
#define SOC_CPU_PDC_LITTLE_COREPWRUPTIME_ADDR(base) ((base) + (0x21CUL))
#define SOC_CPU_PDC_LITTLE_COREPWRDNTIME_ADDR(base) ((base) + (0x220UL))
#define SOC_CPU_PDC_LITTLE_COREISOTIME_ADDR(base) ((base) + (0x224UL))
#define SOC_CPU_PDC_LITTLE_CORERSTTIME_ADDR(base) ((base) + (0x228UL))
#define SOC_CPU_PDC_LITTLE_COREURSTTIME_ADDR(base) ((base) + (0x22CUL))
#define SOC_CPU_PDC_MID_COREPWRUPTIME_ADDR(base) ((base) + (0x230UL))
#define SOC_CPU_PDC_MID_COREPWRDNTIME_ADDR(base) ((base) + (0x234UL))
#define SOC_CPU_PDC_MID_COREISOTIME_ADDR(base) ((base) + (0x238UL))
#define SOC_CPU_PDC_MID_CORERSTTIME_ADDR(base) ((base) + (0x23CUL))
#define SOC_CPU_PDC_MID_COREURSTTIME_ADDR(base) ((base) + (0x240UL))
#define SOC_CPU_PDC_BIG_COREPWRINTEN_ADDR(base) ((base) + (0x304UL))
#define SOC_CPU_PDC_BIG_COREPWRINTSTAT_ADDR(base) ((base) + (0x308UL))
#define SOC_CPU_PDC_BIG_COREGICMASK_ADDR(base) ((base) + (0x30CUL))
#define SOC_CPU_PDC_BIG_COREPOWERUP_ADDR(base) ((base) + (0x310UL))
#define SOC_CPU_PDC_BIG_COREPOWERDN_ADDR(base) ((base) + (0x314UL))
#define SOC_CPU_PDC_BIG_COREPOWERSTAT_ADDR(base) ((base) + (0x318UL))
#define SOC_CPU_PDC_BIG_COREPWRUPTIME_ADDR(base) ((base) + (0x31CUL))
#define SOC_CPU_PDC_BIG_COREPWRDNTIME_ADDR(base) ((base) + (0x320UL))
#define SOC_CPU_PDC_BIG_COREISOTIME_ADDR(base) ((base) + (0x324UL))
#define SOC_CPU_PDC_BIG_CORERSTTIME_ADDR(base) ((base) + (0x328UL))
#define SOC_CPU_PDC_BIG_COREURSTTIME_ADDR(base) ((base) + (0x32CUL))
#define SOC_CPU_PDC_MERGE_COREPWRINTSTAT_ADDR(base) ((base) + (0x330UL))
#define SOC_CPU_PDC_LITTLE_PWRDNTIME_ADDR(base) ((base) + (0x334UL))
#define SOC_CPU_PDC_MIDDLE_PWRDNTIME_ADDR(base) ((base) + (0x338UL))
#define SOC_CPU_PDC_BIG_PWRDNTIME_ADDR(base) ((base) + (0x33CUL))
#else
#define SOC_CPU_PDC_PDCCTRL_ADDR(base) ((base) + (0x000))
#define SOC_CPU_PDC_ISOEN_ADDR(base) ((base) + (0x100))
#define SOC_CPU_PDC_ISODIS_ADDR(base) ((base) + (0x104))
#define SOC_CPU_PDC_ISOSTAT_ADDR(base) ((base) + (0x108))
#define SOC_CPU_PDC_PERPWREN_ADDR(base) ((base) + (0x110))
#define SOC_CPU_PDC_PERPWRDIS_ADDR(base) ((base) + (0x114))
#define SOC_CPU_PDC_PERPWRSTAT_ADDR(base) ((base) + (0x118))
#define SOC_CPU_PDC_PERPWRACK_ADDR(base) ((base) + (0x11C))
#define SOC_CPU_PDC_CPU_CLKEN_ADDR(base) ((base) + (0x120))
#define SOC_CPU_PDC_CPU_RSTEN_ADDR(base) ((base) + (0x124))
#define SOC_CPU_PDC_CPU_RSTDIS_ADDR(base) ((base) + (0x128))
#define SOC_CPU_PDC_CPU_RSTSTAT_ADDR(base) ((base) + (0x12C))
#define SOC_CPU_PDC_CPU_M0_ADBLPSTAT_ADDR(base) ((base) + (0x130))
#define SOC_CPU_PDC_CPU_M1_ADBLPSTAT_ADDR(base) ((base) + (0x134))
#define SOC_CPU_PDC_CPU_MP_ADBLPSTAT_ADDR(base) ((base) + (0x138))
#define SOC_CPU_PDC_CPU_ACP_ADBLPSTAT_ADDR(base) ((base) + (0x13C))
#define SOC_CPU_PDC_CPU_ADB_GT_CFG_ADDR(base) ((base) + (0x140))
#define SOC_CPU_PDC_CPU_STAT0_ADDR(base) ((base) + (0x144))
#define SOC_CPU_PDC_WAKEUPINT_STAT_ADDR(base) ((base) + (0x148))
#define SOC_CPU_PDC_CPU_LIT_ADBLPSTAT_ADDR(base) ((base) + (0x14C))
#define SOC_CPU_PDC_CPU_PDCEN_ADDR(base) ((base) + (0x200))
#define SOC_CPU_PDC_LITTLE_COREPWRINTEN_ADDR(base) ((base) + (0x204))
#define SOC_CPU_PDC_LITTLE_COREPWRINTSTAT_ADDR(base) ((base) + (0x208))
#define SOC_CPU_PDC_LITTLE_COREPOWERUP_ADDR(base) ((base) + (0x210))
#define SOC_CPU_PDC_LITTLE_COREPOWERDN_ADDR(base) ((base) + (0x214))
#define SOC_CPU_PDC_LITTLE_COREPOWERSTAT_ADDR(base) ((base) + (0x218))
#define SOC_CPU_PDC_LITTLE_COREPWRUPTIME_ADDR(base) ((base) + (0x21C))
#define SOC_CPU_PDC_LITTLE_COREPWRDNTIME_ADDR(base) ((base) + (0x220))
#define SOC_CPU_PDC_LITTLE_COREISOTIME_ADDR(base) ((base) + (0x224))
#define SOC_CPU_PDC_LITTLE_CORERSTTIME_ADDR(base) ((base) + (0x228))
#define SOC_CPU_PDC_LITTLE_COREURSTTIME_ADDR(base) ((base) + (0x22C))
#define SOC_CPU_PDC_MID_COREPWRUPTIME_ADDR(base) ((base) + (0x230))
#define SOC_CPU_PDC_MID_COREPWRDNTIME_ADDR(base) ((base) + (0x234))
#define SOC_CPU_PDC_MID_COREISOTIME_ADDR(base) ((base) + (0x238))
#define SOC_CPU_PDC_MID_CORERSTTIME_ADDR(base) ((base) + (0x23C))
#define SOC_CPU_PDC_MID_COREURSTTIME_ADDR(base) ((base) + (0x240))
#define SOC_CPU_PDC_BIG_COREPWRINTEN_ADDR(base) ((base) + (0x304))
#define SOC_CPU_PDC_BIG_COREPWRINTSTAT_ADDR(base) ((base) + (0x308))
#define SOC_CPU_PDC_BIG_COREGICMASK_ADDR(base) ((base) + (0x30C))
#define SOC_CPU_PDC_BIG_COREPOWERUP_ADDR(base) ((base) + (0x310))
#define SOC_CPU_PDC_BIG_COREPOWERDN_ADDR(base) ((base) + (0x314))
#define SOC_CPU_PDC_BIG_COREPOWERSTAT_ADDR(base) ((base) + (0x318))
#define SOC_CPU_PDC_BIG_COREPWRUPTIME_ADDR(base) ((base) + (0x31C))
#define SOC_CPU_PDC_BIG_COREPWRDNTIME_ADDR(base) ((base) + (0x320))
#define SOC_CPU_PDC_BIG_COREISOTIME_ADDR(base) ((base) + (0x324))
#define SOC_CPU_PDC_BIG_CORERSTTIME_ADDR(base) ((base) + (0x328))
#define SOC_CPU_PDC_BIG_COREURSTTIME_ADDR(base) ((base) + (0x32C))
#define SOC_CPU_PDC_MERGE_COREPWRINTSTAT_ADDR(base) ((base) + (0x330))
#define SOC_CPU_PDC_LITTLE_PWRDNTIME_ADDR(base) ((base) + (0x334))
#define SOC_CPU_PDC_MIDDLE_PWRDNTIME_ADDR(base) ((base) + (0x338))
#define SOC_CPU_PDC_BIG_PWRDNTIME_ADDR(base) ((base) + (0x33C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitmasken_000 : 32;
    } reg;
} SOC_CPU_PDC_PDCCTRL_UNION;
#endif
#define SOC_CPU_PDC_PDCCTRL_bitmasken_000_START (0)
#define SOC_CPU_PDC_PDCCTRL_bitmasken_000_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_ISOEN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_ISODIS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_0_iso_stat : 1;
        unsigned int core_1_iso_stat : 1;
        unsigned int core_2_iso_stat : 1;
        unsigned int core_3_iso_stat : 1;
        unsigned int core_4_iso_stat : 1;
        unsigned int core_5_iso_stat : 1;
        unsigned int core_6_iso_stat : 1;
        unsigned int core_7_iso_stat : 1;
        unsigned int core_8_iso_stat : 1;
        unsigned int core_sl2_iso_stat : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_CPU_PDC_ISOSTAT_UNION;
#endif
#define SOC_CPU_PDC_ISOSTAT_core_0_iso_stat_START (0)
#define SOC_CPU_PDC_ISOSTAT_core_0_iso_stat_END (0)
#define SOC_CPU_PDC_ISOSTAT_core_1_iso_stat_START (1)
#define SOC_CPU_PDC_ISOSTAT_core_1_iso_stat_END (1)
#define SOC_CPU_PDC_ISOSTAT_core_2_iso_stat_START (2)
#define SOC_CPU_PDC_ISOSTAT_core_2_iso_stat_END (2)
#define SOC_CPU_PDC_ISOSTAT_core_3_iso_stat_START (3)
#define SOC_CPU_PDC_ISOSTAT_core_3_iso_stat_END (3)
#define SOC_CPU_PDC_ISOSTAT_core_4_iso_stat_START (4)
#define SOC_CPU_PDC_ISOSTAT_core_4_iso_stat_END (4)
#define SOC_CPU_PDC_ISOSTAT_core_5_iso_stat_START (5)
#define SOC_CPU_PDC_ISOSTAT_core_5_iso_stat_END (5)
#define SOC_CPU_PDC_ISOSTAT_core_6_iso_stat_START (6)
#define SOC_CPU_PDC_ISOSTAT_core_6_iso_stat_END (6)
#define SOC_CPU_PDC_ISOSTAT_core_7_iso_stat_START (7)
#define SOC_CPU_PDC_ISOSTAT_core_7_iso_stat_END (7)
#define SOC_CPU_PDC_ISOSTAT_core_8_iso_stat_START (8)
#define SOC_CPU_PDC_ISOSTAT_core_8_iso_stat_END (8)
#define SOC_CPU_PDC_ISOSTAT_core_sl2_iso_stat_START (9)
#define SOC_CPU_PDC_ISOSTAT_core_sl2_iso_stat_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_PERPWREN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_PERPWRDIS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_0_mtcmos_stat : 1;
        unsigned int core_1_mtcmos_stat : 1;
        unsigned int core_2_mtcmos_stat : 1;
        unsigned int core_3_mtcmos_stat : 1;
        unsigned int core_4_mtcmos_stat : 1;
        unsigned int core_5_mtcmos_stat : 1;
        unsigned int core_6_mtcmos_stat : 1;
        unsigned int core_7_mtcmos_stat : 1;
        unsigned int core_8_mtcmos_stat : 1;
        unsigned int core_01_l2_mtcmos_stat : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_CPU_PDC_PERPWRSTAT_UNION;
#endif
#define SOC_CPU_PDC_PERPWRSTAT_core_0_mtcmos_stat_START (0)
#define SOC_CPU_PDC_PERPWRSTAT_core_0_mtcmos_stat_END (0)
#define SOC_CPU_PDC_PERPWRSTAT_core_1_mtcmos_stat_START (1)
#define SOC_CPU_PDC_PERPWRSTAT_core_1_mtcmos_stat_END (1)
#define SOC_CPU_PDC_PERPWRSTAT_core_2_mtcmos_stat_START (2)
#define SOC_CPU_PDC_PERPWRSTAT_core_2_mtcmos_stat_END (2)
#define SOC_CPU_PDC_PERPWRSTAT_core_3_mtcmos_stat_START (3)
#define SOC_CPU_PDC_PERPWRSTAT_core_3_mtcmos_stat_END (3)
#define SOC_CPU_PDC_PERPWRSTAT_core_4_mtcmos_stat_START (4)
#define SOC_CPU_PDC_PERPWRSTAT_core_4_mtcmos_stat_END (4)
#define SOC_CPU_PDC_PERPWRSTAT_core_5_mtcmos_stat_START (5)
#define SOC_CPU_PDC_PERPWRSTAT_core_5_mtcmos_stat_END (5)
#define SOC_CPU_PDC_PERPWRSTAT_core_6_mtcmos_stat_START (6)
#define SOC_CPU_PDC_PERPWRSTAT_core_6_mtcmos_stat_END (6)
#define SOC_CPU_PDC_PERPWRSTAT_core_7_mtcmos_stat_START (7)
#define SOC_CPU_PDC_PERPWRSTAT_core_7_mtcmos_stat_END (7)
#define SOC_CPU_PDC_PERPWRSTAT_core_8_mtcmos_stat_START (8)
#define SOC_CPU_PDC_PERPWRSTAT_core_8_mtcmos_stat_END (8)
#define SOC_CPU_PDC_PERPWRSTAT_core_01_l2_mtcmos_stat_START (9)
#define SOC_CPU_PDC_PERPWRSTAT_core_01_l2_mtcmos_stat_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_0_mtcmos_ack_and : 1;
        unsigned int core_1_mtcmos_ack_and : 1;
        unsigned int core_2_mtcmos_ack_and : 1;
        unsigned int core_3_mtcmos_ack_and : 1;
        unsigned int core_4_mtcmos_ack_and : 1;
        unsigned int core_5_mtcmos_ack_and : 1;
        unsigned int core_6_mtcmos_ack_and : 1;
        unsigned int core_7_mtcmos_ack_and : 1;
        unsigned int core_8_mtcmos_ack_and : 1;
        unsigned int core_01_l2_mtcmos_ack_and : 1;
        unsigned int reserved_0 : 6;
        unsigned int core_0_mtcmos_ack_or : 1;
        unsigned int core_1_mtcmos_ack_or : 1;
        unsigned int core_2_mtcmos_ack_or : 1;
        unsigned int core_3_mtcmos_ack_or : 1;
        unsigned int core_4_mtcmos_ack_or : 1;
        unsigned int core_5_mtcmos_ack_or : 1;
        unsigned int core_6_mtcmos_ack_or : 1;
        unsigned int core_7_mtcmos_ack_or : 1;
        unsigned int core_8_mtcmos_ack_or : 1;
        unsigned int core_01_l2_mtcmos_ack_or : 1;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_CPU_PDC_PERPWRACK_UNION;
#endif
#define SOC_CPU_PDC_PERPWRACK_core_0_mtcmos_ack_and_START (0)
#define SOC_CPU_PDC_PERPWRACK_core_0_mtcmos_ack_and_END (0)
#define SOC_CPU_PDC_PERPWRACK_core_1_mtcmos_ack_and_START (1)
#define SOC_CPU_PDC_PERPWRACK_core_1_mtcmos_ack_and_END (1)
#define SOC_CPU_PDC_PERPWRACK_core_2_mtcmos_ack_and_START (2)
#define SOC_CPU_PDC_PERPWRACK_core_2_mtcmos_ack_and_END (2)
#define SOC_CPU_PDC_PERPWRACK_core_3_mtcmos_ack_and_START (3)
#define SOC_CPU_PDC_PERPWRACK_core_3_mtcmos_ack_and_END (3)
#define SOC_CPU_PDC_PERPWRACK_core_4_mtcmos_ack_and_START (4)
#define SOC_CPU_PDC_PERPWRACK_core_4_mtcmos_ack_and_END (4)
#define SOC_CPU_PDC_PERPWRACK_core_5_mtcmos_ack_and_START (5)
#define SOC_CPU_PDC_PERPWRACK_core_5_mtcmos_ack_and_END (5)
#define SOC_CPU_PDC_PERPWRACK_core_6_mtcmos_ack_and_START (6)
#define SOC_CPU_PDC_PERPWRACK_core_6_mtcmos_ack_and_END (6)
#define SOC_CPU_PDC_PERPWRACK_core_7_mtcmos_ack_and_START (7)
#define SOC_CPU_PDC_PERPWRACK_core_7_mtcmos_ack_and_END (7)
#define SOC_CPU_PDC_PERPWRACK_core_8_mtcmos_ack_and_START (8)
#define SOC_CPU_PDC_PERPWRACK_core_8_mtcmos_ack_and_END (8)
#define SOC_CPU_PDC_PERPWRACK_core_01_l2_mtcmos_ack_and_START (9)
#define SOC_CPU_PDC_PERPWRACK_core_01_l2_mtcmos_ack_and_END (9)
#define SOC_CPU_PDC_PERPWRACK_core_0_mtcmos_ack_or_START (16)
#define SOC_CPU_PDC_PERPWRACK_core_0_mtcmos_ack_or_END (16)
#define SOC_CPU_PDC_PERPWRACK_core_1_mtcmos_ack_or_START (17)
#define SOC_CPU_PDC_PERPWRACK_core_1_mtcmos_ack_or_END (17)
#define SOC_CPU_PDC_PERPWRACK_core_2_mtcmos_ack_or_START (18)
#define SOC_CPU_PDC_PERPWRACK_core_2_mtcmos_ack_or_END (18)
#define SOC_CPU_PDC_PERPWRACK_core_3_mtcmos_ack_or_START (19)
#define SOC_CPU_PDC_PERPWRACK_core_3_mtcmos_ack_or_END (19)
#define SOC_CPU_PDC_PERPWRACK_core_4_mtcmos_ack_or_START (20)
#define SOC_CPU_PDC_PERPWRACK_core_4_mtcmos_ack_or_END (20)
#define SOC_CPU_PDC_PERPWRACK_core_5_mtcmos_ack_or_START (21)
#define SOC_CPU_PDC_PERPWRACK_core_5_mtcmos_ack_or_END (21)
#define SOC_CPU_PDC_PERPWRACK_core_6_mtcmos_ack_or_START (22)
#define SOC_CPU_PDC_PERPWRACK_core_6_mtcmos_ack_or_END (22)
#define SOC_CPU_PDC_PERPWRACK_core_7_mtcmos_ack_or_START (23)
#define SOC_CPU_PDC_PERPWRACK_core_7_mtcmos_ack_or_END (23)
#define SOC_CPU_PDC_PERPWRACK_core_8_mtcmos_ack_or_START (24)
#define SOC_CPU_PDC_PERPWRACK_core_8_mtcmos_ack_or_END (24)
#define SOC_CPU_PDC_PERPWRACK_core_01_l2_mtcmos_ack_or_START (25)
#define SOC_CPU_PDC_PERPWRACK_core_01_l2_mtcmos_ack_or_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_hc_gicclk_en : 1;
        unsigned int gt_periphclk_top_en : 1;
        unsigned int gt_clk_ananke_en : 1;
        unsigned int gt_clk_scu_en : 1;
        unsigned int gt_hc_atclk_top_en : 1;
        unsigned int gt_hc_pclkdbg_top_en : 1;
        unsigned int reserved_0 : 2;
        unsigned int gt_top_pclkdbg_top_en : 1;
        unsigned int gt_atclk_top_en : 1;
        unsigned int gt_lit_gicclk_en : 1;
        unsigned int reserved_1 : 3;
        unsigned int gt_lit_atclk_top_en : 1;
        unsigned int gt_lit_pclkdbg_top_en : 1;
        unsigned int bitmasken_120 : 16;
    } reg;
} SOC_CPU_PDC_CPU_CLKEN_UNION;
#endif
#define SOC_CPU_PDC_CPU_CLKEN_gt_hc_gicclk_en_START (0)
#define SOC_CPU_PDC_CPU_CLKEN_gt_hc_gicclk_en_END (0)
#define SOC_CPU_PDC_CPU_CLKEN_gt_periphclk_top_en_START (1)
#define SOC_CPU_PDC_CPU_CLKEN_gt_periphclk_top_en_END (1)
#define SOC_CPU_PDC_CPU_CLKEN_gt_clk_ananke_en_START (2)
#define SOC_CPU_PDC_CPU_CLKEN_gt_clk_ananke_en_END (2)
#define SOC_CPU_PDC_CPU_CLKEN_gt_clk_scu_en_START (3)
#define SOC_CPU_PDC_CPU_CLKEN_gt_clk_scu_en_END (3)
#define SOC_CPU_PDC_CPU_CLKEN_gt_hc_atclk_top_en_START (4)
#define SOC_CPU_PDC_CPU_CLKEN_gt_hc_atclk_top_en_END (4)
#define SOC_CPU_PDC_CPU_CLKEN_gt_hc_pclkdbg_top_en_START (5)
#define SOC_CPU_PDC_CPU_CLKEN_gt_hc_pclkdbg_top_en_END (5)
#define SOC_CPU_PDC_CPU_CLKEN_gt_top_pclkdbg_top_en_START (8)
#define SOC_CPU_PDC_CPU_CLKEN_gt_top_pclkdbg_top_en_END (8)
#define SOC_CPU_PDC_CPU_CLKEN_gt_atclk_top_en_START (9)
#define SOC_CPU_PDC_CPU_CLKEN_gt_atclk_top_en_END (9)
#define SOC_CPU_PDC_CPU_CLKEN_gt_lit_gicclk_en_START (10)
#define SOC_CPU_PDC_CPU_CLKEN_gt_lit_gicclk_en_END (10)
#define SOC_CPU_PDC_CPU_CLKEN_gt_lit_atclk_top_en_START (14)
#define SOC_CPU_PDC_CPU_CLKEN_gt_lit_atclk_top_en_END (14)
#define SOC_CPU_PDC_CPU_CLKEN_gt_lit_pclkdbg_top_en_START (15)
#define SOC_CPU_PDC_CPU_CLKEN_gt_lit_pclkdbg_top_en_END (15)
#define SOC_CPU_PDC_CPU_CLKEN_bitmasken_120_START (16)
#define SOC_CPU_PDC_CPU_CLKEN_bitmasken_120_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 3;
        unsigned int reserved_2 : 1;
        unsigned int hc_presetdbg_rst_req_en : 1;
        unsigned int hc_coresight_soft_rst_req_en : 1;
        unsigned int reserved_3 : 1;
        unsigned int hc_scu_soft_rst_req_en : 1;
        unsigned int lit_presetdbg_rst_req_en : 1;
        unsigned int lit_coresight_soft_rst_req_en : 1;
        unsigned int reserved_4 : 1;
        unsigned int lit_scu_soft_rst_req_en : 1;
        unsigned int subchip_atreset_top_req_en : 1;
        unsigned int subchip_preset_top_req_en : 1;
        unsigned int subchip_coresightreset_top_req_en : 1;
        unsigned int reserved_5 : 1;
        unsigned int hc_cluster_soft_rst_req_en : 1;
        unsigned int lit_cluster_soft_rst_req_en : 1;
        unsigned int top_cluster_soft_rst_req_en : 1;
        unsigned int reserved_6 : 9;
    } reg;
} SOC_CPU_PDC_CPU_RSTEN_UNION;
#endif
#define SOC_CPU_PDC_CPU_RSTEN_hc_presetdbg_rst_req_en_START (8)
#define SOC_CPU_PDC_CPU_RSTEN_hc_presetdbg_rst_req_en_END (8)
#define SOC_CPU_PDC_CPU_RSTEN_hc_coresight_soft_rst_req_en_START (9)
#define SOC_CPU_PDC_CPU_RSTEN_hc_coresight_soft_rst_req_en_END (9)
#define SOC_CPU_PDC_CPU_RSTEN_hc_scu_soft_rst_req_en_START (11)
#define SOC_CPU_PDC_CPU_RSTEN_hc_scu_soft_rst_req_en_END (11)
#define SOC_CPU_PDC_CPU_RSTEN_lit_presetdbg_rst_req_en_START (12)
#define SOC_CPU_PDC_CPU_RSTEN_lit_presetdbg_rst_req_en_END (12)
#define SOC_CPU_PDC_CPU_RSTEN_lit_coresight_soft_rst_req_en_START (13)
#define SOC_CPU_PDC_CPU_RSTEN_lit_coresight_soft_rst_req_en_END (13)
#define SOC_CPU_PDC_CPU_RSTEN_lit_scu_soft_rst_req_en_START (15)
#define SOC_CPU_PDC_CPU_RSTEN_lit_scu_soft_rst_req_en_END (15)
#define SOC_CPU_PDC_CPU_RSTEN_subchip_atreset_top_req_en_START (16)
#define SOC_CPU_PDC_CPU_RSTEN_subchip_atreset_top_req_en_END (16)
#define SOC_CPU_PDC_CPU_RSTEN_subchip_preset_top_req_en_START (17)
#define SOC_CPU_PDC_CPU_RSTEN_subchip_preset_top_req_en_END (17)
#define SOC_CPU_PDC_CPU_RSTEN_subchip_coresightreset_top_req_en_START (18)
#define SOC_CPU_PDC_CPU_RSTEN_subchip_coresightreset_top_req_en_END (18)
#define SOC_CPU_PDC_CPU_RSTEN_hc_cluster_soft_rst_req_en_START (20)
#define SOC_CPU_PDC_CPU_RSTEN_hc_cluster_soft_rst_req_en_END (20)
#define SOC_CPU_PDC_CPU_RSTEN_lit_cluster_soft_rst_req_en_START (21)
#define SOC_CPU_PDC_CPU_RSTEN_lit_cluster_soft_rst_req_en_END (21)
#define SOC_CPU_PDC_CPU_RSTEN_top_cluster_soft_rst_req_en_START (22)
#define SOC_CPU_PDC_CPU_RSTEN_top_cluster_soft_rst_req_en_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 3;
        unsigned int reserved_2 : 1;
        unsigned int hc_presetdbg_rst_req_dis : 1;
        unsigned int hc_coresight_soft_rst_req_dis : 1;
        unsigned int reserved_3 : 1;
        unsigned int hc_scu_soft_rst_req_dis : 1;
        unsigned int lit_presetdbg_rst_req_dis : 1;
        unsigned int lit_coresight_soft_rst_req_dis : 1;
        unsigned int reserved_4 : 1;
        unsigned int lit_scu_soft_rst_req_dis : 1;
        unsigned int subchip_atreset_top_req_dis : 1;
        unsigned int subchip_preset_top_req_dis : 1;
        unsigned int subchip_coresightreset_top_req_dis : 1;
        unsigned int reserved_5 : 1;
        unsigned int hc_cluster_soft_rst_req_dis : 1;
        unsigned int lit_cluster_soft_rst_req_dis : 1;
        unsigned int top_cluster_soft_rst_req_dis : 1;
        unsigned int reserved_6 : 9;
    } reg;
} SOC_CPU_PDC_CPU_RSTDIS_UNION;
#endif
#define SOC_CPU_PDC_CPU_RSTDIS_hc_presetdbg_rst_req_dis_START (8)
#define SOC_CPU_PDC_CPU_RSTDIS_hc_presetdbg_rst_req_dis_END (8)
#define SOC_CPU_PDC_CPU_RSTDIS_hc_coresight_soft_rst_req_dis_START (9)
#define SOC_CPU_PDC_CPU_RSTDIS_hc_coresight_soft_rst_req_dis_END (9)
#define SOC_CPU_PDC_CPU_RSTDIS_hc_scu_soft_rst_req_dis_START (11)
#define SOC_CPU_PDC_CPU_RSTDIS_hc_scu_soft_rst_req_dis_END (11)
#define SOC_CPU_PDC_CPU_RSTDIS_lit_presetdbg_rst_req_dis_START (12)
#define SOC_CPU_PDC_CPU_RSTDIS_lit_presetdbg_rst_req_dis_END (12)
#define SOC_CPU_PDC_CPU_RSTDIS_lit_coresight_soft_rst_req_dis_START (13)
#define SOC_CPU_PDC_CPU_RSTDIS_lit_coresight_soft_rst_req_dis_END (13)
#define SOC_CPU_PDC_CPU_RSTDIS_lit_scu_soft_rst_req_dis_START (15)
#define SOC_CPU_PDC_CPU_RSTDIS_lit_scu_soft_rst_req_dis_END (15)
#define SOC_CPU_PDC_CPU_RSTDIS_subchip_atreset_top_req_dis_START (16)
#define SOC_CPU_PDC_CPU_RSTDIS_subchip_atreset_top_req_dis_END (16)
#define SOC_CPU_PDC_CPU_RSTDIS_subchip_preset_top_req_dis_START (17)
#define SOC_CPU_PDC_CPU_RSTDIS_subchip_preset_top_req_dis_END (17)
#define SOC_CPU_PDC_CPU_RSTDIS_subchip_coresightreset_top_req_dis_START (18)
#define SOC_CPU_PDC_CPU_RSTDIS_subchip_coresightreset_top_req_dis_END (18)
#define SOC_CPU_PDC_CPU_RSTDIS_hc_cluster_soft_rst_req_dis_START (20)
#define SOC_CPU_PDC_CPU_RSTDIS_hc_cluster_soft_rst_req_dis_END (20)
#define SOC_CPU_PDC_CPU_RSTDIS_lit_cluster_soft_rst_req_dis_START (21)
#define SOC_CPU_PDC_CPU_RSTDIS_lit_cluster_soft_rst_req_dis_END (21)
#define SOC_CPU_PDC_CPU_RSTDIS_top_cluster_soft_rst_req_dis_START (22)
#define SOC_CPU_PDC_CPU_RSTDIS_top_cluster_soft_rst_req_dis_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 3;
        unsigned int reserved_2 : 1;
        unsigned int hc_presetdbg_rst_req_stat : 1;
        unsigned int hc_coresight_soft_rst_req_stat : 1;
        unsigned int reserved_3 : 1;
        unsigned int hc_scu_soft_rst_req_stat : 1;
        unsigned int lit_presetdbg_rst_req_stat : 1;
        unsigned int lit_coresight_soft_rst_req_stat : 1;
        unsigned int reserved_4 : 1;
        unsigned int lit_scu_soft_rst_req_stat : 1;
        unsigned int subchip_atreset_top_req_stat : 1;
        unsigned int subchip_preset_top_req_stat : 1;
        unsigned int subchip_coresightreset_top_req_stat : 1;
        unsigned int reserved_5 : 1;
        unsigned int hc_cluster_soft_rst_req_stat : 1;
        unsigned int lit_cluster_soft_rst_req_stat : 1;
        unsigned int top_cluster_soft_rst_req_stat : 1;
        unsigned int reserved_6 : 9;
    } reg;
} SOC_CPU_PDC_CPU_RSTSTAT_UNION;
#endif
#define SOC_CPU_PDC_CPU_RSTSTAT_hc_presetdbg_rst_req_stat_START (8)
#define SOC_CPU_PDC_CPU_RSTSTAT_hc_presetdbg_rst_req_stat_END (8)
#define SOC_CPU_PDC_CPU_RSTSTAT_hc_coresight_soft_rst_req_stat_START (9)
#define SOC_CPU_PDC_CPU_RSTSTAT_hc_coresight_soft_rst_req_stat_END (9)
#define SOC_CPU_PDC_CPU_RSTSTAT_hc_scu_soft_rst_req_stat_START (11)
#define SOC_CPU_PDC_CPU_RSTSTAT_hc_scu_soft_rst_req_stat_END (11)
#define SOC_CPU_PDC_CPU_RSTSTAT_lit_presetdbg_rst_req_stat_START (12)
#define SOC_CPU_PDC_CPU_RSTSTAT_lit_presetdbg_rst_req_stat_END (12)
#define SOC_CPU_PDC_CPU_RSTSTAT_lit_coresight_soft_rst_req_stat_START (13)
#define SOC_CPU_PDC_CPU_RSTSTAT_lit_coresight_soft_rst_req_stat_END (13)
#define SOC_CPU_PDC_CPU_RSTSTAT_lit_scu_soft_rst_req_stat_START (15)
#define SOC_CPU_PDC_CPU_RSTSTAT_lit_scu_soft_rst_req_stat_END (15)
#define SOC_CPU_PDC_CPU_RSTSTAT_subchip_atreset_top_req_stat_START (16)
#define SOC_CPU_PDC_CPU_RSTSTAT_subchip_atreset_top_req_stat_END (16)
#define SOC_CPU_PDC_CPU_RSTSTAT_subchip_preset_top_req_stat_START (17)
#define SOC_CPU_PDC_CPU_RSTSTAT_subchip_preset_top_req_stat_END (17)
#define SOC_CPU_PDC_CPU_RSTSTAT_subchip_coresightreset_top_req_stat_START (18)
#define SOC_CPU_PDC_CPU_RSTSTAT_subchip_coresightreset_top_req_stat_END (18)
#define SOC_CPU_PDC_CPU_RSTSTAT_hc_cluster_soft_rst_req_stat_START (20)
#define SOC_CPU_PDC_CPU_RSTSTAT_hc_cluster_soft_rst_req_stat_END (20)
#define SOC_CPU_PDC_CPU_RSTSTAT_lit_cluster_soft_rst_req_stat_START (21)
#define SOC_CPU_PDC_CPU_RSTSTAT_lit_cluster_soft_rst_req_stat_END (21)
#define SOC_CPU_PDC_CPU_RSTSTAT_top_cluster_soft_rst_req_stat_START (22)
#define SOC_CPU_PDC_CPU_RSTSTAT_top_cluster_soft_rst_req_stat_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pwrqreq_adb_m0 : 1;
        unsigned int reserved_0 : 1;
        unsigned int pwrqactive_adb_m0 : 1;
        unsigned int pwrqaccept_adb_m0 : 1;
        unsigned int pwrqdeney_adb_m0 : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_CPU_PDC_CPU_M0_ADBLPSTAT_UNION;
#endif
#define SOC_CPU_PDC_CPU_M0_ADBLPSTAT_pwrqreq_adb_m0_START (0)
#define SOC_CPU_PDC_CPU_M0_ADBLPSTAT_pwrqreq_adb_m0_END (0)
#define SOC_CPU_PDC_CPU_M0_ADBLPSTAT_pwrqactive_adb_m0_START (2)
#define SOC_CPU_PDC_CPU_M0_ADBLPSTAT_pwrqactive_adb_m0_END (2)
#define SOC_CPU_PDC_CPU_M0_ADBLPSTAT_pwrqaccept_adb_m0_START (3)
#define SOC_CPU_PDC_CPU_M0_ADBLPSTAT_pwrqaccept_adb_m0_END (3)
#define SOC_CPU_PDC_CPU_M0_ADBLPSTAT_pwrqdeney_adb_m0_START (4)
#define SOC_CPU_PDC_CPU_M0_ADBLPSTAT_pwrqdeney_adb_m0_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pwrqreq_adb_m1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int pwrqactive_adb_m1 : 1;
        unsigned int pwrqaccept_adb_m1 : 1;
        unsigned int pwrqdeney_adb_m1 : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_CPU_PDC_CPU_M1_ADBLPSTAT_UNION;
#endif
#define SOC_CPU_PDC_CPU_M1_ADBLPSTAT_pwrqreq_adb_m1_START (0)
#define SOC_CPU_PDC_CPU_M1_ADBLPSTAT_pwrqreq_adb_m1_END (0)
#define SOC_CPU_PDC_CPU_M1_ADBLPSTAT_pwrqactive_adb_m1_START (2)
#define SOC_CPU_PDC_CPU_M1_ADBLPSTAT_pwrqactive_adb_m1_END (2)
#define SOC_CPU_PDC_CPU_M1_ADBLPSTAT_pwrqaccept_adb_m1_START (3)
#define SOC_CPU_PDC_CPU_M1_ADBLPSTAT_pwrqaccept_adb_m1_END (3)
#define SOC_CPU_PDC_CPU_M1_ADBLPSTAT_pwrqdeney_adb_m1_START (4)
#define SOC_CPU_PDC_CPU_M1_ADBLPSTAT_pwrqdeney_adb_m1_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pwrqreq_adb_mp : 1;
        unsigned int reserved_0 : 1;
        unsigned int pwrqactive_adb_mp : 1;
        unsigned int pwrqaccept_adb_mp : 1;
        unsigned int pwrqdeney_adb_mp : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_CPU_PDC_CPU_MP_ADBLPSTAT_UNION;
#endif
#define SOC_CPU_PDC_CPU_MP_ADBLPSTAT_pwrqreq_adb_mp_START (0)
#define SOC_CPU_PDC_CPU_MP_ADBLPSTAT_pwrqreq_adb_mp_END (0)
#define SOC_CPU_PDC_CPU_MP_ADBLPSTAT_pwrqactive_adb_mp_START (2)
#define SOC_CPU_PDC_CPU_MP_ADBLPSTAT_pwrqactive_adb_mp_END (2)
#define SOC_CPU_PDC_CPU_MP_ADBLPSTAT_pwrqaccept_adb_mp_START (3)
#define SOC_CPU_PDC_CPU_MP_ADBLPSTAT_pwrqaccept_adb_mp_END (3)
#define SOC_CPU_PDC_CPU_MP_ADBLPSTAT_pwrqdeney_adb_mp_START (4)
#define SOC_CPU_PDC_CPU_MP_ADBLPSTAT_pwrqdeney_adb_mp_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pwrqreq_adb_acp : 1;
        unsigned int reserved_0 : 1;
        unsigned int pwrqactive_adb_acp : 1;
        unsigned int pwrqaccept_adb_acp : 1;
        unsigned int pwrqdeney_adb_acp : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_CPU_PDC_CPU_ACP_ADBLPSTAT_UNION;
#endif
#define SOC_CPU_PDC_CPU_ACP_ADBLPSTAT_pwrqreq_adb_acp_START (0)
#define SOC_CPU_PDC_CPU_ACP_ADBLPSTAT_pwrqreq_adb_acp_END (0)
#define SOC_CPU_PDC_CPU_ACP_ADBLPSTAT_pwrqactive_adb_acp_START (2)
#define SOC_CPU_PDC_CPU_ACP_ADBLPSTAT_pwrqactive_adb_acp_END (2)
#define SOC_CPU_PDC_CPU_ACP_ADBLPSTAT_pwrqaccept_adb_acp_START (3)
#define SOC_CPU_PDC_CPU_ACP_ADBLPSTAT_pwrqaccept_adb_acp_END (3)
#define SOC_CPU_PDC_CPU_ACP_ADBLPSTAT_pwrqdeney_adb_acp_START (4)
#define SOC_CPU_PDC_CPU_ACP_ADBLPSTAT_pwrqdeney_adb_acp_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qactive_cfgcnt : 7;
        unsigned int gt_clk_bypass : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_CPU_PDC_CPU_ADB_GT_CFG_UNION;
#endif
#define SOC_CPU_PDC_CPU_ADB_GT_CFG_qactive_cfgcnt_START (0)
#define SOC_CPU_PDC_CPU_ADB_GT_CFG_qactive_cfgcnt_END (6)
#define SOC_CPU_PDC_CPU_ADB_GT_CFG_gt_clk_bypass_START (7)
#define SOC_CPU_PDC_CPU_ADB_GT_CFG_gt_clk_bypass_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 19;
        unsigned int core_idle : 9;
        unsigned int l3_idle : 1;
        unsigned int dbgack : 1;
        unsigned int etf_full : 1;
        unsigned int share_l2_idle : 1;
    } reg;
} SOC_CPU_PDC_CPU_STAT0_UNION;
#endif
#define SOC_CPU_PDC_CPU_STAT0_core_idle_START (19)
#define SOC_CPU_PDC_CPU_STAT0_core_idle_END (27)
#define SOC_CPU_PDC_CPU_STAT0_l3_idle_START (28)
#define SOC_CPU_PDC_CPU_STAT0_l3_idle_END (28)
#define SOC_CPU_PDC_CPU_STAT0_dbgack_START (29)
#define SOC_CPU_PDC_CPU_STAT0_dbgack_END (29)
#define SOC_CPU_PDC_CPU_STAT0_etf_full_START (30)
#define SOC_CPU_PDC_CPU_STAT0_etf_full_END (30)
#define SOC_CPU_PDC_CPU_STAT0_share_l2_idle_START (31)
#define SOC_CPU_PDC_CPU_STAT0_share_l2_idle_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_gic_wake_request_0 : 1;
        unsigned int intr_gic_wake_request_1 : 1;
        unsigned int intr_gic_wake_request_2 : 1;
        unsigned int intr_gic_wake_request_3 : 1;
        unsigned int intr_gic_wake_request_4_t0 : 1;
        unsigned int intr_gic_wake_request_4_t1 : 1;
        unsigned int intr_gic_wake_request_5_t0 : 1;
        unsigned int intr_gic_wake_request_5_t1 : 1;
        unsigned int intr_gic_wake_request_6_t0 : 1;
        unsigned int intr_gic_wake_request_6_t1 : 1;
        unsigned int intr_gic_wake_request_7_t0 : 1;
        unsigned int intr_gic_wake_request_7_t1 : 1;
        unsigned int intr_gic_wake_request_8_t0 : 1;
        unsigned int intr_gic_wake_request_8_t1 : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_CPU_PDC_WAKEUPINT_STAT_UNION;
#endif
#define SOC_CPU_PDC_WAKEUPINT_STAT_intr_gic_wake_request_0_START (0)
#define SOC_CPU_PDC_WAKEUPINT_STAT_intr_gic_wake_request_0_END (0)
#define SOC_CPU_PDC_WAKEUPINT_STAT_intr_gic_wake_request_1_START (1)
#define SOC_CPU_PDC_WAKEUPINT_STAT_intr_gic_wake_request_1_END (1)
#define SOC_CPU_PDC_WAKEUPINT_STAT_intr_gic_wake_request_2_START (2)
#define SOC_CPU_PDC_WAKEUPINT_STAT_intr_gic_wake_request_2_END (2)
#define SOC_CPU_PDC_WAKEUPINT_STAT_intr_gic_wake_request_3_START (3)
#define SOC_CPU_PDC_WAKEUPINT_STAT_intr_gic_wake_request_3_END (3)
#define SOC_CPU_PDC_WAKEUPINT_STAT_intr_gic_wake_request_4_t0_START (4)
#define SOC_CPU_PDC_WAKEUPINT_STAT_intr_gic_wake_request_4_t0_END (4)
#define SOC_CPU_PDC_WAKEUPINT_STAT_intr_gic_wake_request_4_t1_START (5)
#define SOC_CPU_PDC_WAKEUPINT_STAT_intr_gic_wake_request_4_t1_END (5)
#define SOC_CPU_PDC_WAKEUPINT_STAT_intr_gic_wake_request_5_t0_START (6)
#define SOC_CPU_PDC_WAKEUPINT_STAT_intr_gic_wake_request_5_t0_END (6)
#define SOC_CPU_PDC_WAKEUPINT_STAT_intr_gic_wake_request_5_t1_START (7)
#define SOC_CPU_PDC_WAKEUPINT_STAT_intr_gic_wake_request_5_t1_END (7)
#define SOC_CPU_PDC_WAKEUPINT_STAT_intr_gic_wake_request_6_t0_START (8)
#define SOC_CPU_PDC_WAKEUPINT_STAT_intr_gic_wake_request_6_t0_END (8)
#define SOC_CPU_PDC_WAKEUPINT_STAT_intr_gic_wake_request_6_t1_START (9)
#define SOC_CPU_PDC_WAKEUPINT_STAT_intr_gic_wake_request_6_t1_END (9)
#define SOC_CPU_PDC_WAKEUPINT_STAT_intr_gic_wake_request_7_t0_START (10)
#define SOC_CPU_PDC_WAKEUPINT_STAT_intr_gic_wake_request_7_t0_END (10)
#define SOC_CPU_PDC_WAKEUPINT_STAT_intr_gic_wake_request_7_t1_START (11)
#define SOC_CPU_PDC_WAKEUPINT_STAT_intr_gic_wake_request_7_t1_END (11)
#define SOC_CPU_PDC_WAKEUPINT_STAT_intr_gic_wake_request_8_t0_START (12)
#define SOC_CPU_PDC_WAKEUPINT_STAT_intr_gic_wake_request_8_t0_END (12)
#define SOC_CPU_PDC_WAKEUPINT_STAT_intr_gic_wake_request_8_t1_START (13)
#define SOC_CPU_PDC_WAKEUPINT_STAT_intr_gic_wake_request_8_t1_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pwrqreq_adb_lit : 1;
        unsigned int reserved_0 : 1;
        unsigned int pwrqactive_adb_lit : 1;
        unsigned int pwrqaccept_adb_lit : 1;
        unsigned int pwrqdeney_adb_lit : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_CPU_PDC_CPU_LIT_ADBLPSTAT_UNION;
#endif
#define SOC_CPU_PDC_CPU_LIT_ADBLPSTAT_pwrqreq_adb_lit_START (0)
#define SOC_CPU_PDC_CPU_LIT_ADBLPSTAT_pwrqreq_adb_lit_END (0)
#define SOC_CPU_PDC_CPU_LIT_ADBLPSTAT_pwrqactive_adb_lit_START (2)
#define SOC_CPU_PDC_CPU_LIT_ADBLPSTAT_pwrqactive_adb_lit_END (2)
#define SOC_CPU_PDC_CPU_LIT_ADBLPSTAT_pwrqaccept_adb_lit_START (3)
#define SOC_CPU_PDC_CPU_LIT_ADBLPSTAT_pwrqaccept_adb_lit_END (3)
#define SOC_CPU_PDC_CPU_LIT_ADBLPSTAT_pwrqdeney_adb_lit_START (4)
#define SOC_CPU_PDC_CPU_LIT_ADBLPSTAT_pwrqdeney_adb_lit_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitmasken_200 : 32;
    } reg;
} SOC_CPU_PDC_CPU_PDCEN_UNION;
#endif
#define SOC_CPU_PDC_CPU_PDCEN_bitmasken_200_START (0)
#define SOC_CPU_PDC_CPU_PDCEN_bitmasken_200_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitmasken_204 : 32;
    } reg;
} SOC_CPU_PDC_LITTLE_COREPWRINTEN_UNION;
#endif
#define SOC_CPU_PDC_LITTLE_COREPWRINTEN_bitmasken_204_START (0)
#define SOC_CPU_PDC_LITTLE_COREPWRINTEN_bitmasken_204_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_LITTLE_COREPWRINTSTAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_LITTLE_COREPOWERUP_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_LITTLE_COREPOWERDN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_LITTLE_COREPOWERSTAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_LITTLE_COREPWRUPTIME_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_LITTLE_COREPWRDNTIME_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_LITTLE_COREISOTIME_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_LITTLE_CORERSTTIME_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_LITTLE_COREURSTTIME_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_MID_COREPWRUPTIME_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_MID_COREPWRDNTIME_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_MID_COREISOTIME_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_MID_CORERSTTIME_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_MID_COREURSTTIME_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitmasken_304 : 32;
    } reg;
} SOC_CPU_PDC_BIG_COREPWRINTEN_UNION;
#endif
#define SOC_CPU_PDC_BIG_COREPWRINTEN_bitmasken_304_START (0)
#define SOC_CPU_PDC_BIG_COREPWRINTEN_bitmasken_304_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_BIG_COREPWRINTSTAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitmasken_30C : 32;
    } reg;
} SOC_CPU_PDC_BIG_COREGICMASK_UNION;
#endif
#define SOC_CPU_PDC_BIG_COREGICMASK_bitmasken_30C_START (0)
#define SOC_CPU_PDC_BIG_COREGICMASK_bitmasken_30C_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_BIG_COREPOWERUP_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_BIG_COREPOWERDN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_BIG_COREPOWERSTAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_BIG_COREPWRUPTIME_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_BIG_COREPWRDNTIME_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_BIG_COREISOTIME_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_BIG_CORERSTTIME_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_BIG_COREURSTTIME_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_MERGE_COREPWRINTSTAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_LITTLE_PWRDNTIME_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_MIDDLE_PWRDNTIME_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_CPU_PDC_BIG_PWRDNTIME_UNION;
#endif
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
