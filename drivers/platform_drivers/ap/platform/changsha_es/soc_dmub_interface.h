#ifndef __SOC_DMUB_INTERFACE_H__
#define __SOC_DMUB_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_DMUB_GLB_RTL_VER_ADDR(base) ((base) + (0x0000UL))
#define SOC_DMUB_GLB_CKG_BYP_ADDR(base) ((base) + (0x0004UL))
#define SOC_DMUB_DDR_BUSY_CNT_SET_ADDR(base) ((base) + (0x0008UL))
#define SOC_DMUB_CFG_REMAP0_ADDR(base) ((base) + (0x0010UL))
#define SOC_DMUB_CFG_REMAP1_ADDR(base) ((base) + (0x0014UL))
#define SOC_DMUB_CFG_REMAP2_ADDR(base) ((base) + (0x0018UL))
#define SOC_DMUB_CFG_REMAP3_ADDR(base) ((base) + (0x001CUL))
#define SOC_DMUB_CFG_REMAP4_ADDR(base) ((base) + (0x0020UL))
#define SOC_DMUB_CFG_REMAP5_ADDR(base) ((base) + (0x0024UL))
#define SOC_DMUB_SC_DMC_DCQ_LVL_ADDR(base) ((base) + (0x0030UL))
#define SOC_DMUB_DMC_PRI_LVL0_ADDR(base) ((base) + (0x0034UL))
#define SOC_DMUB_DMC_PRI_LVL1_ADDR(base) ((base) + (0x0038UL))
#define SOC_DMUB_DMC_PRI_LVL2_ADDR(base) ((base) + (0x003cUL))
#define SOC_DMUB_DMC_DVFS_QOS_ALLOW_ADDR(base) ((base) + (0x0040UL))
#define SOC_DMUB_SC_DVFS_QOS_ALLOW_ADDR(base) ((base) + (0x0044UL))
#define SOC_DMUB_DVFS_HOLD_CTRL_ADDR(base) ((base) + (0x0048UL))
#define SOC_DMUB_DVFS_RELEASE_CTRL_ADDR(base) ((base) + (0x004cUL))
#define SOC_DMUB_SC_DVFS_TIME_P_ADDR(base) ((base) + (0x0050UL))
#define SOC_DMUB_ADDR_REMAP_SEC_LOCK_ADDR(base) ((base) + (0x0054UL))
#define SOC_DMUB_DFX_STATUS0_ADDR(base) ((base) + (0x0070UL))
#else
#define SOC_DMUB_GLB_RTL_VER_ADDR(base) ((base) + (0x0000))
#define SOC_DMUB_GLB_CKG_BYP_ADDR(base) ((base) + (0x0004))
#define SOC_DMUB_DDR_BUSY_CNT_SET_ADDR(base) ((base) + (0x0008))
#define SOC_DMUB_CFG_REMAP0_ADDR(base) ((base) + (0x0010))
#define SOC_DMUB_CFG_REMAP1_ADDR(base) ((base) + (0x0014))
#define SOC_DMUB_CFG_REMAP2_ADDR(base) ((base) + (0x0018))
#define SOC_DMUB_CFG_REMAP3_ADDR(base) ((base) + (0x001C))
#define SOC_DMUB_CFG_REMAP4_ADDR(base) ((base) + (0x0020))
#define SOC_DMUB_CFG_REMAP5_ADDR(base) ((base) + (0x0024))
#define SOC_DMUB_SC_DMC_DCQ_LVL_ADDR(base) ((base) + (0x0030))
#define SOC_DMUB_DMC_PRI_LVL0_ADDR(base) ((base) + (0x0034))
#define SOC_DMUB_DMC_PRI_LVL1_ADDR(base) ((base) + (0x0038))
#define SOC_DMUB_DMC_PRI_LVL2_ADDR(base) ((base) + (0x003c))
#define SOC_DMUB_DMC_DVFS_QOS_ALLOW_ADDR(base) ((base) + (0x0040))
#define SOC_DMUB_SC_DVFS_QOS_ALLOW_ADDR(base) ((base) + (0x0044))
#define SOC_DMUB_DVFS_HOLD_CTRL_ADDR(base) ((base) + (0x0048))
#define SOC_DMUB_DVFS_RELEASE_CTRL_ADDR(base) ((base) + (0x004c))
#define SOC_DMUB_SC_DVFS_TIME_P_ADDR(base) ((base) + (0x0050))
#define SOC_DMUB_ADDR_REMAP_SEC_LOCK_ADDR(base) ((base) + (0x0054))
#define SOC_DMUB_DFX_STATUS0_ADDR(base) ((base) + (0x0070))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_tag : 8;
        unsigned int reserved_0: 8;
        unsigned int version : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_DMUB_GLB_RTL_VER_UNION;
#endif
#define SOC_DMUB_GLB_RTL_VER_rtl_tag_START (0)
#define SOC_DMUB_GLB_RTL_VER_rtl_tag_END (7)
#define SOC_DMUB_GLB_RTL_VER_version_START (16)
#define SOC_DMUB_GLB_RTL_VER_version_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gate_en_dcq : 1;
        unsigned int gate_en_dcq_stat : 1;
        unsigned int ckg_byp_dcq : 1;
        unsigned int ckg_byp_cfg : 1;
        unsigned int ckg_byp_rs : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_DMUB_GLB_CKG_BYP_UNION;
#endif
#define SOC_DMUB_GLB_CKG_BYP_gate_en_dcq_START (0)
#define SOC_DMUB_GLB_CKG_BYP_gate_en_dcq_END (0)
#define SOC_DMUB_GLB_CKG_BYP_gate_en_dcq_stat_START (1)
#define SOC_DMUB_GLB_CKG_BYP_gate_en_dcq_stat_END (1)
#define SOC_DMUB_GLB_CKG_BYP_ckg_byp_dcq_START (2)
#define SOC_DMUB_GLB_CKG_BYP_ckg_byp_dcq_END (2)
#define SOC_DMUB_GLB_CKG_BYP_ckg_byp_cfg_START (3)
#define SOC_DMUB_GLB_CKG_BYP_ckg_byp_cfg_END (3)
#define SOC_DMUB_GLB_CKG_BYP_ckg_byp_rs_START (4)
#define SOC_DMUB_GLB_CKG_BYP_ckg_byp_rs_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_busy_cnt_set : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_DMUB_DDR_BUSY_CNT_SET_UNION;
#endif
#define SOC_DMUB_DDR_BUSY_CNT_SET_ddr_busy_cnt_set_START (0)
#define SOC_DMUB_DDR_BUSY_CNT_SET_ddr_busy_cnt_set_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int region0 : 5;
        unsigned int region1 : 5;
        unsigned int region2 : 5;
        unsigned int region3 : 5;
        unsigned int region4 : 5;
        unsigned int region5 : 5;
        unsigned int reserved : 2;
    } reg;
} SOC_DMUB_CFG_REMAP0_UNION;
#endif
#define SOC_DMUB_CFG_REMAP0_region0_START (0)
#define SOC_DMUB_CFG_REMAP0_region0_END (4)
#define SOC_DMUB_CFG_REMAP0_region1_START (5)
#define SOC_DMUB_CFG_REMAP0_region1_END (9)
#define SOC_DMUB_CFG_REMAP0_region2_START (10)
#define SOC_DMUB_CFG_REMAP0_region2_END (14)
#define SOC_DMUB_CFG_REMAP0_region3_START (15)
#define SOC_DMUB_CFG_REMAP0_region3_END (19)
#define SOC_DMUB_CFG_REMAP0_region4_START (20)
#define SOC_DMUB_CFG_REMAP0_region4_END (24)
#define SOC_DMUB_CFG_REMAP0_region5_START (25)
#define SOC_DMUB_CFG_REMAP0_region5_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int region6 : 5;
        unsigned int region7 : 5;
        unsigned int region8 : 5;
        unsigned int region9 : 5;
        unsigned int region10 : 5;
        unsigned int region11 : 5;
        unsigned int reserved : 2;
    } reg;
} SOC_DMUB_CFG_REMAP1_UNION;
#endif
#define SOC_DMUB_CFG_REMAP1_region6_START (0)
#define SOC_DMUB_CFG_REMAP1_region6_END (4)
#define SOC_DMUB_CFG_REMAP1_region7_START (5)
#define SOC_DMUB_CFG_REMAP1_region7_END (9)
#define SOC_DMUB_CFG_REMAP1_region8_START (10)
#define SOC_DMUB_CFG_REMAP1_region8_END (14)
#define SOC_DMUB_CFG_REMAP1_region9_START (15)
#define SOC_DMUB_CFG_REMAP1_region9_END (19)
#define SOC_DMUB_CFG_REMAP1_region10_START (20)
#define SOC_DMUB_CFG_REMAP1_region10_END (24)
#define SOC_DMUB_CFG_REMAP1_region11_START (25)
#define SOC_DMUB_CFG_REMAP1_region11_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int region12 : 5;
        unsigned int region13 : 5;
        unsigned int region14 : 5;
        unsigned int region15 : 5;
        unsigned int region16 : 5;
        unsigned int region17 : 5;
        unsigned int reserved : 2;
    } reg;
} SOC_DMUB_CFG_REMAP2_UNION;
#endif
#define SOC_DMUB_CFG_REMAP2_region12_START (0)
#define SOC_DMUB_CFG_REMAP2_region12_END (4)
#define SOC_DMUB_CFG_REMAP2_region13_START (5)
#define SOC_DMUB_CFG_REMAP2_region13_END (9)
#define SOC_DMUB_CFG_REMAP2_region14_START (10)
#define SOC_DMUB_CFG_REMAP2_region14_END (14)
#define SOC_DMUB_CFG_REMAP2_region15_START (15)
#define SOC_DMUB_CFG_REMAP2_region15_END (19)
#define SOC_DMUB_CFG_REMAP2_region16_START (20)
#define SOC_DMUB_CFG_REMAP2_region16_END (24)
#define SOC_DMUB_CFG_REMAP2_region17_START (25)
#define SOC_DMUB_CFG_REMAP2_region17_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int region18 : 5;
        unsigned int region19 : 5;
        unsigned int region20 : 5;
        unsigned int region21 : 5;
        unsigned int region22 : 5;
        unsigned int region23 : 5;
        unsigned int reserved : 2;
    } reg;
} SOC_DMUB_CFG_REMAP3_UNION;
#endif
#define SOC_DMUB_CFG_REMAP3_region18_START (0)
#define SOC_DMUB_CFG_REMAP3_region18_END (4)
#define SOC_DMUB_CFG_REMAP3_region19_START (5)
#define SOC_DMUB_CFG_REMAP3_region19_END (9)
#define SOC_DMUB_CFG_REMAP3_region20_START (10)
#define SOC_DMUB_CFG_REMAP3_region20_END (14)
#define SOC_DMUB_CFG_REMAP3_region21_START (15)
#define SOC_DMUB_CFG_REMAP3_region21_END (19)
#define SOC_DMUB_CFG_REMAP3_region22_START (20)
#define SOC_DMUB_CFG_REMAP3_region22_END (24)
#define SOC_DMUB_CFG_REMAP3_region23_START (25)
#define SOC_DMUB_CFG_REMAP3_region23_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int region24 : 5;
        unsigned int region25 : 5;
        unsigned int region26 : 5;
        unsigned int region27 : 5;
        unsigned int region28 : 5;
        unsigned int region29 : 5;
        unsigned int reserved : 2;
    } reg;
} SOC_DMUB_CFG_REMAP4_UNION;
#endif
#define SOC_DMUB_CFG_REMAP4_region24_START (0)
#define SOC_DMUB_CFG_REMAP4_region24_END (4)
#define SOC_DMUB_CFG_REMAP4_region25_START (5)
#define SOC_DMUB_CFG_REMAP4_region25_END (9)
#define SOC_DMUB_CFG_REMAP4_region26_START (10)
#define SOC_DMUB_CFG_REMAP4_region26_END (14)
#define SOC_DMUB_CFG_REMAP4_region27_START (15)
#define SOC_DMUB_CFG_REMAP4_region27_END (19)
#define SOC_DMUB_CFG_REMAP4_region28_START (20)
#define SOC_DMUB_CFG_REMAP4_region28_END (24)
#define SOC_DMUB_CFG_REMAP4_region29_START (25)
#define SOC_DMUB_CFG_REMAP4_region29_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int region30 : 5;
        unsigned int region31 : 5;
        unsigned int reserved : 22;
    } reg;
} SOC_DMUB_CFG_REMAP5_UNION;
#endif
#define SOC_DMUB_CFG_REMAP5_region30_START (0)
#define SOC_DMUB_CFG_REMAP5_region30_END (4)
#define SOC_DMUB_CFG_REMAP5_region31_START (5)
#define SOC_DMUB_CFG_REMAP5_region31_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_dmc_dcq_lvl0 : 9;
        unsigned int sc_dmc_dcq_lvl1 : 9;
        unsigned int sc_dmc_dcq_lvl2 : 9;
        unsigned int reserved : 4;
        unsigned int sc_dmc_dcq_lvl_en : 1;
    } reg;
} SOC_DMUB_SC_DMC_DCQ_LVL_UNION;
#endif
#define SOC_DMUB_SC_DMC_DCQ_LVL_sc_dmc_dcq_lvl0_START (0)
#define SOC_DMUB_SC_DMC_DCQ_LVL_sc_dmc_dcq_lvl0_END (8)
#define SOC_DMUB_SC_DMC_DCQ_LVL_sc_dmc_dcq_lvl1_START (9)
#define SOC_DMUB_SC_DMC_DCQ_LVL_sc_dmc_dcq_lvl1_END (17)
#define SOC_DMUB_SC_DMC_DCQ_LVL_sc_dmc_dcq_lvl2_START (18)
#define SOC_DMUB_SC_DMC_DCQ_LVL_sc_dmc_dcq_lvl2_END (26)
#define SOC_DMUB_SC_DMC_DCQ_LVL_sc_dmc_dcq_lvl_en_START (31)
#define SOC_DMUB_SC_DMC_DCQ_LVL_sc_dmc_dcq_lvl_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_pri_lvl0 : 9;
        unsigned int dmc_pri_lvl1 : 9;
        unsigned int dmc_pri_lvl2 : 9;
        unsigned int reserved : 4;
        unsigned int dmc_pri_en : 1;
    } reg;
} SOC_DMUB_DMC_PRI_LVL0_UNION;
#endif
#define SOC_DMUB_DMC_PRI_LVL0_dmc_pri_lvl0_START (0)
#define SOC_DMUB_DMC_PRI_LVL0_dmc_pri_lvl0_END (8)
#define SOC_DMUB_DMC_PRI_LVL0_dmc_pri_lvl1_START (9)
#define SOC_DMUB_DMC_PRI_LVL0_dmc_pri_lvl1_END (17)
#define SOC_DMUB_DMC_PRI_LVL0_dmc_pri_lvl2_START (18)
#define SOC_DMUB_DMC_PRI_LVL0_dmc_pri_lvl2_END (26)
#define SOC_DMUB_DMC_PRI_LVL0_dmc_pri_en_START (31)
#define SOC_DMUB_DMC_PRI_LVL0_dmc_pri_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_pri_lvl3 : 9;
        unsigned int dmc_pri_lvl4 : 9;
        unsigned int dmc_pri_lvl5 : 9;
        unsigned int reserved : 5;
    } reg;
} SOC_DMUB_DMC_PRI_LVL1_UNION;
#endif
#define SOC_DMUB_DMC_PRI_LVL1_dmc_pri_lvl3_START (0)
#define SOC_DMUB_DMC_PRI_LVL1_dmc_pri_lvl3_END (8)
#define SOC_DMUB_DMC_PRI_LVL1_dmc_pri_lvl4_START (9)
#define SOC_DMUB_DMC_PRI_LVL1_dmc_pri_lvl4_END (17)
#define SOC_DMUB_DMC_PRI_LVL1_dmc_pri_lvl5_START (18)
#define SOC_DMUB_DMC_PRI_LVL1_dmc_pri_lvl5_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dmc_pri_lvl6 : 9;
        unsigned int dmc_pri_lvl7 : 9;
        unsigned int reserved : 14;
    } reg;
} SOC_DMUB_DMC_PRI_LVL2_UNION;
#endif
#define SOC_DMUB_DMC_PRI_LVL2_dmc_pri_lvl6_START (0)
#define SOC_DMUB_DMC_PRI_LVL2_dmc_pri_lvl6_END (8)
#define SOC_DMUB_DMC_PRI_LVL2_dmc_pri_lvl7_START (9)
#define SOC_DMUB_DMC_PRI_LVL2_dmc_pri_lvl7_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dvfs_qos_allow_ddr2tb : 8;
        unsigned int reserved : 23;
        unsigned int dvfs_dmc_pri_en : 1;
    } reg;
} SOC_DMUB_DMC_DVFS_QOS_ALLOW_UNION;
#endif
#define SOC_DMUB_DMC_DVFS_QOS_ALLOW_dvfs_qos_allow_ddr2tb_START (0)
#define SOC_DMUB_DMC_DVFS_QOS_ALLOW_dvfs_qos_allow_ddr2tb_END (7)
#define SOC_DMUB_DMC_DVFS_QOS_ALLOW_dvfs_dmc_pri_en_START (31)
#define SOC_DMUB_DMC_DVFS_QOS_ALLOW_dvfs_dmc_pri_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dvfs_qos_allow_ddr2sc_lv1 : 3;
        unsigned int reserved_0 : 1;
        unsigned int dvfs_qos_allow_ddr2sc_lv2 : 3;
        unsigned int reserved_1 : 1;
        unsigned int dvfs_qos_allow_ddr2sc_lv3 : 3;
        unsigned int reserved_2 : 20;
        unsigned int dvfs_sc_pri_en : 1;
    } reg;
} SOC_DMUB_SC_DVFS_QOS_ALLOW_UNION;
#endif
#define SOC_DMUB_SC_DVFS_QOS_ALLOW_dvfs_qos_allow_ddr2sc_lv1_START (0)
#define SOC_DMUB_SC_DVFS_QOS_ALLOW_dvfs_qos_allow_ddr2sc_lv1_END (2)
#define SOC_DMUB_SC_DVFS_QOS_ALLOW_dvfs_qos_allow_ddr2sc_lv2_START (4)
#define SOC_DMUB_SC_DVFS_QOS_ALLOW_dvfs_qos_allow_ddr2sc_lv2_END (6)
#define SOC_DMUB_SC_DVFS_QOS_ALLOW_dvfs_qos_allow_ddr2sc_lv3_START (8)
#define SOC_DMUB_SC_DVFS_QOS_ALLOW_dvfs_qos_allow_ddr2sc_lv3_END (10)
#define SOC_DMUB_SC_DVFS_QOS_ALLOW_dvfs_sc_pri_en_START (31)
#define SOC_DMUB_SC_DVFS_QOS_ALLOW_dvfs_sc_pri_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dvfs_hold_time : 14;
        unsigned int reserved : 17;
        unsigned int dvfs_hold_byp : 1;
    } reg;
} SOC_DMUB_DVFS_HOLD_CTRL_UNION;
#endif
#define SOC_DMUB_DVFS_HOLD_CTRL_dvfs_hold_time_START (0)
#define SOC_DMUB_DVFS_HOLD_CTRL_dvfs_hold_time_END (13)
#define SOC_DMUB_DVFS_HOLD_CTRL_dvfs_hold_byp_START (31)
#define SOC_DMUB_DVFS_HOLD_CTRL_dvfs_hold_byp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dvfs_release_lvl : 9;
        unsigned int reserved : 22;
        unsigned int dvfs_sft_byp : 1;
    } reg;
} SOC_DMUB_DVFS_RELEASE_CTRL_UNION;
#endif
#define SOC_DMUB_DVFS_RELEASE_CTRL_dvfs_release_lvl_START (0)
#define SOC_DMUB_DVFS_RELEASE_CTRL_dvfs_release_lvl_END (8)
#define SOC_DMUB_DVFS_RELEASE_CTRL_dvfs_sft_byp_START (31)
#define SOC_DMUB_DVFS_RELEASE_CTRL_dvfs_sft_byp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dvfs_time_p1 : 14;
        unsigned int reserved_0 : 2;
        unsigned int dvfs_time_p2 : 14;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_DMUB_SC_DVFS_TIME_P_UNION;
#endif
#define SOC_DMUB_SC_DVFS_TIME_P_dvfs_time_p1_START (0)
#define SOC_DMUB_SC_DVFS_TIME_P_dvfs_time_p1_END (13)
#define SOC_DMUB_SC_DVFS_TIME_P_dvfs_time_p2_START (16)
#define SOC_DMUB_SC_DVFS_TIME_P_dvfs_time_p2_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr_remap_set_lock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DMUB_ADDR_REMAP_SEC_LOCK_UNION;
#endif
#define SOC_DMUB_ADDR_REMAP_SEC_LOCK_addr_remap_set_lock_START (0)
#define SOC_DMUB_ADDR_REMAP_SEC_LOCK_addr_remap_set_lock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dvfs_going_ddr2sc : 1;
        unsigned int dvfs_going_ddr2tb : 1;
        unsigned int dvfs_going_lock : 1;
        unsigned int dvfs_going_dmc2dcq_sync : 1;
        unsigned int qos_allow_ddr2tb : 8;
        unsigned int reserved_0 : 1;
        unsigned int qos_allow_ddr2sc : 3;
        unsigned int reserved_1 : 3;
        unsigned int dcq_ostd : 9;
        unsigned int pready : 1;
        unsigned int ddrc_clk_en_dcq : 1;
        unsigned int clk_en_stat : 1;
        unsigned int ddrc_buf_busy : 1;
    } reg;
} SOC_DMUB_DFX_STATUS0_UNION;
#endif
#define SOC_DMUB_DFX_STATUS0_dvfs_going_ddr2sc_START (0)
#define SOC_DMUB_DFX_STATUS0_dvfs_going_ddr2sc_END (0)
#define SOC_DMUB_DFX_STATUS0_dvfs_going_ddr2tb_START (1)
#define SOC_DMUB_DFX_STATUS0_dvfs_going_ddr2tb_END (1)
#define SOC_DMUB_DFX_STATUS0_dvfs_going_lock_START (2)
#define SOC_DMUB_DFX_STATUS0_dvfs_going_lock_END (2)
#define SOC_DMUB_DFX_STATUS0_dvfs_going_dmc2dcq_sync_START (3)
#define SOC_DMUB_DFX_STATUS0_dvfs_going_dmc2dcq_sync_END (3)
#define SOC_DMUB_DFX_STATUS0_qos_allow_ddr2tb_START (4)
#define SOC_DMUB_DFX_STATUS0_qos_allow_ddr2tb_END (11)
#define SOC_DMUB_DFX_STATUS0_qos_allow_ddr2sc_START (13)
#define SOC_DMUB_DFX_STATUS0_qos_allow_ddr2sc_END (15)
#define SOC_DMUB_DFX_STATUS0_dcq_ostd_START (19)
#define SOC_DMUB_DFX_STATUS0_dcq_ostd_END (27)
#define SOC_DMUB_DFX_STATUS0_pready_START (28)
#define SOC_DMUB_DFX_STATUS0_pready_END (28)
#define SOC_DMUB_DFX_STATUS0_ddrc_clk_en_dcq_START (29)
#define SOC_DMUB_DFX_STATUS0_ddrc_clk_en_dcq_END (29)
#define SOC_DMUB_DFX_STATUS0_clk_en_stat_START (30)
#define SOC_DMUB_DFX_STATUS0_clk_en_stat_END (30)
#define SOC_DMUB_DFX_STATUS0_ddrc_buf_busy_START (31)
#define SOC_DMUB_DFX_STATUS0_ddrc_buf_busy_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
