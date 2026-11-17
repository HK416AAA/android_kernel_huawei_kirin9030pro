#ifndef __SOC_QICE_GM_INTERFACE_H__
#define __SOC_QICE_GM_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QICE_GM_GLB_ADDR_CTRL_ADDR(base) ((base) + 0x0010UL)
#define SOC_QICE_GM_GLB_COH_CTRL_ADDR(base) ((base) + 0x0020UL)
#define SOC_QICE_GM_GLB_QTPEM_CTRL_ADDR(base) ((base) + 0x0030UL)
#define SOC_QICE_GM_GM_RTL_VER_ADDR(base) ((base) + 0x0400UL)
#define SOC_QICE_GM_GM_RTL_INFO_ADDR(base) ((base) + 0x0404UL)
#define SOC_QICE_GM_GM_RTL_INF1_ADDR(base) ((base) + 0x0408UL)
#define SOC_QICE_GM_GM_RTL_INF2_ADDR(base) ((base) + 0x040CUL)
#define SOC_QICE_GM_GM_CKG_CTRL_ADDR(base) ((base) + 0x0410UL)
#define SOC_QICE_GM_GM_TEST_EN_ADDR(base) ((base) + 0x0418UL)
#define SOC_QICE_GM_GM_SLP_NUM_ADDR(base) ((base) + 0x041CUL)
#define SOC_QICE_GM_GM_RD_OS_ADDR(base) ((base) + 0x0420UL)
#define SOC_QICE_GM_GM_WR_OS_ADDR(base) ((base) + 0x0424UL)
#define SOC_QICE_GM_GM_FST_ADDR1_ADDR(base) ((base) + 0x0428UL)
#define SOC_QICE_GM_GM_FST_ADDR0_ADDR(base) ((base) + 0x042CUL)
#define SOC_QICE_GM_GM_SLP_SERI_ADDR(base) ((base) + 0x0430UL)
#define SOC_QICE_GM_GM_SLP_LIST_ADDR(base) ((base) + 0x0434UL)
#define SOC_QICE_GM_GM_SLP_CFG0_ADDR(base,slp_num) (base) + 0x0440 + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_SLP_CFG1_ADDR(base,slp_num) (base) + 0x0444 + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_SLP_CFG2_ADDR(base,slp_num) (base) + 0x0448 + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_SLP_CFG3_ADDR(base,slp_num) (base) + 0x044C + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_SLP_CFG4_ADDR(base,slp_num) (base) + 0x0450 + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_SLP_CFG5_ADDR(base,slp_num) (base) + 0x0454 + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_SLP_CFG6_ADDR(base,slp_num) (base) + 0x0458 + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_SLP_CFG7_ADDR(base,slp_num) (base) + 0x045C + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_SLP_CFG8_ADDR(base,slp_num) (base) + 0x0460 + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_SLP_CFG9_ADDR(base,slp_num) (base) + 0x0464 + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_SLP_CFG10_ADDR(base,slp_num) (base) + 0x0468 + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_SLP_CFG11_ADDR(base,slp_num) (base) + 0x046C + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_SLP_CFG12_ADDR(base,slp_num) (base) + 0x0470 + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_SLP_CFG13_ADDR(base,slp_num) (base) + 0x0474 + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_SLP_CFG14_ADDR(base,slp_num) (base) + 0x0478 + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_CMD_CNT_ADDR(base) ((base) + 0x0600UL)
#define SOC_QICE_GM_GM_CMD_CNT_CLR_ADDR(base) ((base) + 0x0604UL)
#define SOC_QICE_GM_GM_CHECK_EN_ADDR(base) ((base) + 0x0608UL)
#define SOC_QICE_GM_GM_DFX_CFG0_ADDR(base) ((base) + 0x0E00UL)
#define SOC_QICE_GM_GM_DFX_CFG1_ADDR(base) ((base) + 0x0E04UL)
#define SOC_QICE_GM_GM_DFX_CFG2_ADDR(base) ((base) + 0x0E08UL)
#define SOC_QICE_GM_GM_DFX_CFG3_ADDR(base) ((base) + 0x0E0CUL)
#define SOC_QICE_GM_GM_DFX_CFG4_ADDR(base) ((base) + 0x0E10UL)
#define SOC_QICE_GM_GM_DFX_INT_CTRL0_ADDR(base) ((base) + 0x0E14UL)
#define SOC_QICE_GM_GM_DFX_INT_CTRL1_ADDR(base) ((base) + 0x0E18UL)
#define SOC_QICE_GM_GM_DFX_INT_CTRL2_ADDR(base) ((base) + 0x0E1CUL)
#define SOC_QICE_GM_GM_DFX_INT_CTRL3_ADDR(base) ((base) + 0x0E20UL)
#define SOC_QICE_GM_GM_DFX_INT_INO0_ADDR(base) ((base) + 0x0E24UL)
#define SOC_QICE_GM_GM_DFX_INT_INO1_ADDR(base) ((base) + 0x0E28UL)
#define SOC_QICE_GM_GM_DFX_INT_INO2_ADDR(base) ((base) + 0x0E2CUL)
#define SOC_QICE_GM_GM_DFX_INT_INO3_ADDR(base) ((base) + 0x0E30UL)
#define SOC_QICE_GM_GM_DFX_NS_INT_STATUS0_ADDR(base) ((base) + 0x0E34UL)
#define SOC_QICE_GM_GM_DFX_NS_INT_STATUS1_ADDR(base) ((base) + 0x0E38UL)
#define SOC_QICE_GM_GM_DFX_NS_INT_STATUS2_ADDR(base) ((base) + 0x0E3CUL)
#define SOC_QICE_GM_GM_DFX_TABLE_VLD0_ADDR(base) ((base) + 0x0E40UL)
#define SOC_QICE_GM_GM_DFX_TABLE_VLD1_ADDR(base) ((base) + 0x0E44UL)
#else
#define SOC_QICE_GM_GLB_ADDR_CTRL_ADDR(base) ((base) + 0x0010)
#define SOC_QICE_GM_GLB_COH_CTRL_ADDR(base) ((base) + 0x0020)
#define SOC_QICE_GM_GLB_QTPEM_CTRL_ADDR(base) ((base) + 0x0030)
#define SOC_QICE_GM_GM_RTL_VER_ADDR(base) ((base) + 0x0400)
#define SOC_QICE_GM_GM_RTL_INFO_ADDR(base) ((base) + 0x0404)
#define SOC_QICE_GM_GM_RTL_INF1_ADDR(base) ((base) + 0x0408)
#define SOC_QICE_GM_GM_RTL_INF2_ADDR(base) ((base) + 0x040C)
#define SOC_QICE_GM_GM_CKG_CTRL_ADDR(base) ((base) + 0x0410)
#define SOC_QICE_GM_GM_TEST_EN_ADDR(base) ((base) + 0x0418)
#define SOC_QICE_GM_GM_SLP_NUM_ADDR(base) ((base) + 0x041C)
#define SOC_QICE_GM_GM_RD_OS_ADDR(base) ((base) + 0x0420)
#define SOC_QICE_GM_GM_WR_OS_ADDR(base) ((base) + 0x0424)
#define SOC_QICE_GM_GM_FST_ADDR1_ADDR(base) ((base) + 0x0428)
#define SOC_QICE_GM_GM_FST_ADDR0_ADDR(base) ((base) + 0x042C)
#define SOC_QICE_GM_GM_SLP_SERI_ADDR(base) ((base) + 0x0430)
#define SOC_QICE_GM_GM_SLP_LIST_ADDR(base) ((base) + 0x0434)
#define SOC_QICE_GM_GM_SLP_CFG0_ADDR(base,slp_num) (base) + 0x0440 + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_SLP_CFG1_ADDR(base,slp_num) (base) + 0x0444 + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_SLP_CFG2_ADDR(base,slp_num) (base) + 0x0448 + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_SLP_CFG3_ADDR(base,slp_num) (base) + 0x044C + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_SLP_CFG4_ADDR(base,slp_num) (base) + 0x0450 + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_SLP_CFG5_ADDR(base,slp_num) (base) + 0x0454 + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_SLP_CFG6_ADDR(base,slp_num) (base) + 0x0458 + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_SLP_CFG7_ADDR(base,slp_num) (base) + 0x045C + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_SLP_CFG8_ADDR(base,slp_num) (base) + 0x0460 + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_SLP_CFG9_ADDR(base,slp_num) (base) + 0x0464 + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_SLP_CFG10_ADDR(base,slp_num) (base) + 0x0468 + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_SLP_CFG11_ADDR(base,slp_num) (base) + 0x046C + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_SLP_CFG12_ADDR(base,slp_num) (base) + 0x0470 + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_SLP_CFG13_ADDR(base,slp_num) (base) + 0x0474 + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_SLP_CFG14_ADDR(base,slp_num) (base) + 0x0478 + 0x40 * (slp_num)
#define SOC_QICE_GM_GM_CMD_CNT_ADDR(base) ((base) + 0x0600)
#define SOC_QICE_GM_GM_CMD_CNT_CLR_ADDR(base) ((base) + 0x0604)
#define SOC_QICE_GM_GM_CHECK_EN_ADDR(base) ((base) + 0x0608)
#define SOC_QICE_GM_GM_DFX_CFG0_ADDR(base) ((base) + 0x0E00)
#define SOC_QICE_GM_GM_DFX_CFG1_ADDR(base) ((base) + 0x0E04)
#define SOC_QICE_GM_GM_DFX_CFG2_ADDR(base) ((base) + 0x0E08)
#define SOC_QICE_GM_GM_DFX_CFG3_ADDR(base) ((base) + 0x0E0C)
#define SOC_QICE_GM_GM_DFX_CFG4_ADDR(base) ((base) + 0x0E10)
#define SOC_QICE_GM_GM_DFX_INT_CTRL0_ADDR(base) ((base) + 0x0E14)
#define SOC_QICE_GM_GM_DFX_INT_CTRL1_ADDR(base) ((base) + 0x0E18)
#define SOC_QICE_GM_GM_DFX_INT_CTRL2_ADDR(base) ((base) + 0x0E1C)
#define SOC_QICE_GM_GM_DFX_INT_CTRL3_ADDR(base) ((base) + 0x0E20)
#define SOC_QICE_GM_GM_DFX_INT_INO0_ADDR(base) ((base) + 0x0E24)
#define SOC_QICE_GM_GM_DFX_INT_INO1_ADDR(base) ((base) + 0x0E28)
#define SOC_QICE_GM_GM_DFX_INT_INO2_ADDR(base) ((base) + 0x0E2C)
#define SOC_QICE_GM_GM_DFX_INT_INO3_ADDR(base) ((base) + 0x0E30)
#define SOC_QICE_GM_GM_DFX_NS_INT_STATUS0_ADDR(base) ((base) + 0x0E34)
#define SOC_QICE_GM_GM_DFX_NS_INT_STATUS1_ADDR(base) ((base) + 0x0E38)
#define SOC_QICE_GM_GM_DFX_NS_INT_STATUS2_ADDR(base) ((base) + 0x0E3C)
#define SOC_QICE_GM_GM_DFX_TABLE_VLD0_ADDR(base) ((base) + 0x0E40)
#define SOC_QICE_GM_GM_DFX_TABLE_VLD1_ADDR(base) ((base) + 0x0E44)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intlv_gran : 2;
        unsigned int ddr_channel_mode : 1;
        unsigned int scramble_en : 1;
        unsigned int routing_split : 2;
        unsigned int reserved_0 : 2;
        unsigned int addr_shift_mode : 2;
        unsigned int reserved_1 : 2;
        unsigned int intlv_area_addr_0 : 6;
        unsigned int intlv_area_addr_1 : 6;
        unsigned int intlv_area_rop_mode_sel : 1;
        unsigned int reserved_2 : 7;
    } reg;
} SOC_QICE_GM_GLB_ADDR_CTRL_UNION;
#endif
#define SOC_QICE_GM_GLB_ADDR_CTRL_intlv_gran_START (0)
#define SOC_QICE_GM_GLB_ADDR_CTRL_intlv_gran_END (1)
#define SOC_QICE_GM_GLB_ADDR_CTRL_ddr_channel_mode_START (2)
#define SOC_QICE_GM_GLB_ADDR_CTRL_ddr_channel_mode_END (2)
#define SOC_QICE_GM_GLB_ADDR_CTRL_scramble_en_START (3)
#define SOC_QICE_GM_GLB_ADDR_CTRL_scramble_en_END (3)
#define SOC_QICE_GM_GLB_ADDR_CTRL_routing_split_START (4)
#define SOC_QICE_GM_GLB_ADDR_CTRL_routing_split_END (5)
#define SOC_QICE_GM_GLB_ADDR_CTRL_addr_shift_mode_START (8)
#define SOC_QICE_GM_GLB_ADDR_CTRL_addr_shift_mode_END (9)
#define SOC_QICE_GM_GLB_ADDR_CTRL_intlv_area_addr_0_START (12)
#define SOC_QICE_GM_GLB_ADDR_CTRL_intlv_area_addr_0_END (17)
#define SOC_QICE_GM_GLB_ADDR_CTRL_intlv_area_addr_1_START (18)
#define SOC_QICE_GM_GLB_ADDR_CTRL_intlv_area_addr_1_END (23)
#define SOC_QICE_GM_GLB_ADDR_CTRL_intlv_area_rop_mode_sel_START (24)
#define SOC_QICE_GM_GLB_ADDR_CTRL_intlv_area_rop_mode_sel_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 4;
        unsigned int sc_bypass_mode : 1;
        unsigned int sc_bwe_en : 1;
        unsigned int dmt_dis : 1;
        unsigned int cmo_mode : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_QICE_GM_GLB_COH_CTRL_UNION;
#endif
#define SOC_QICE_GM_GLB_COH_CTRL_sc_bypass_mode_START (4)
#define SOC_QICE_GM_GLB_COH_CTRL_sc_bypass_mode_END (4)
#define SOC_QICE_GM_GLB_COH_CTRL_sc_bwe_en_START (5)
#define SOC_QICE_GM_GLB_COH_CTRL_sc_bwe_en_END (5)
#define SOC_QICE_GM_GLB_COH_CTRL_dmt_dis_START (6)
#define SOC_QICE_GM_GLB_COH_CTRL_dmt_dis_END (6)
#define SOC_QICE_GM_GLB_COH_CTRL_cmo_mode_START (7)
#define SOC_QICE_GM_GLB_COH_CTRL_cmo_mode_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qtpem_disable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_GM_GLB_QTPEM_CTRL_UNION;
#endif
#define SOC_QICE_GM_GLB_QTPEM_CTRL_qtpem_disable_START (0)
#define SOC_QICE_GM_GLB_QTPEM_CTRL_qtpem_disable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_tag : 8;
        unsigned int reserved_0: 8;
        unsigned int version : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_QICE_GM_GM_RTL_VER_UNION;
#endif
#define SOC_QICE_GM_GM_RTL_VER_rtl_tag_START (0)
#define SOC_QICE_GM_GM_RTL_VER_rtl_tag_END (7)
#define SOC_QICE_GM_GM_RTL_VER_version_START (16)
#define SOC_QICE_GM_GM_RTL_VER_version_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info0 : 32;
    } reg;
} SOC_QICE_GM_GM_RTL_INFO_UNION;
#endif
#define SOC_QICE_GM_GM_RTL_INFO_rtl_info0_START (0)
#define SOC_QICE_GM_GM_RTL_INFO_rtl_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info1 : 32;
    } reg;
} SOC_QICE_GM_GM_RTL_INF1_UNION;
#endif
#define SOC_QICE_GM_GM_RTL_INF1_rtl_info1_START (0)
#define SOC_QICE_GM_GM_RTL_INF1_rtl_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info2 : 32;
    } reg;
} SOC_QICE_GM_GM_RTL_INF2_UNION;
#endif
#define SOC_QICE_GM_GM_RTL_INF2_rtl_info2_START (0)
#define SOC_QICE_GM_GM_RTL_INF2_rtl_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ckg_byp_rs : 1;
        unsigned int ckg_byp_rswitch : 1;
        unsigned int ckg_byp_cfg : 1;
        unsigned int ckg_byp_lch : 1;
        unsigned int ckg_byp_tc : 1;
        unsigned int ckg_byp_tproc : 1;
        unsigned int ckg_byp_int : 1;
        unsigned int ckg_byp_qtpem : 1;
        unsigned int reserved : 23;
        unsigned int ckg_ext_ena : 1;
    } reg;
} SOC_QICE_GM_GM_CKG_CTRL_UNION;
#endif
#define SOC_QICE_GM_GM_CKG_CTRL_ckg_byp_rs_START (0)
#define SOC_QICE_GM_GM_CKG_CTRL_ckg_byp_rs_END (0)
#define SOC_QICE_GM_GM_CKG_CTRL_ckg_byp_rswitch_START (1)
#define SOC_QICE_GM_GM_CKG_CTRL_ckg_byp_rswitch_END (1)
#define SOC_QICE_GM_GM_CKG_CTRL_ckg_byp_cfg_START (2)
#define SOC_QICE_GM_GM_CKG_CTRL_ckg_byp_cfg_END (2)
#define SOC_QICE_GM_GM_CKG_CTRL_ckg_byp_lch_START (3)
#define SOC_QICE_GM_GM_CKG_CTRL_ckg_byp_lch_END (3)
#define SOC_QICE_GM_GM_CKG_CTRL_ckg_byp_tc_START (4)
#define SOC_QICE_GM_GM_CKG_CTRL_ckg_byp_tc_END (4)
#define SOC_QICE_GM_GM_CKG_CTRL_ckg_byp_tproc_START (5)
#define SOC_QICE_GM_GM_CKG_CTRL_ckg_byp_tproc_END (5)
#define SOC_QICE_GM_GM_CKG_CTRL_ckg_byp_int_START (6)
#define SOC_QICE_GM_GM_CKG_CTRL_ckg_byp_int_END (6)
#define SOC_QICE_GM_GM_CKG_CTRL_ckg_byp_qtpem_START (7)
#define SOC_QICE_GM_GM_CKG_CTRL_ckg_byp_qtpem_END (7)
#define SOC_QICE_GM_GM_CKG_CTRL_ckg_ext_ena_START (31)
#define SOC_QICE_GM_GM_CKG_CTRL_ckg_ext_ena_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int test_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_GM_GM_TEST_EN_UNION;
#endif
#define SOC_QICE_GM_GM_TEST_EN_test_en_START (0)
#define SOC_QICE_GM_GM_TEST_EN_test_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sloop_num : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_GM_GM_SLP_NUM_UNION;
#endif
#define SOC_QICE_GM_GM_SLP_NUM_sloop_num_START (0)
#define SOC_QICE_GM_GM_SLP_NUM_sloop_num_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int read_os : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_GM_GM_RD_OS_UNION;
#endif
#define SOC_QICE_GM_GM_RD_OS_read_os_START (0)
#define SOC_QICE_GM_GM_RD_OS_read_os_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int write_os : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_GM_GM_WR_OS_UNION;
#endif
#define SOC_QICE_GM_GM_WR_OS_write_os_START (0)
#define SOC_QICE_GM_GM_WR_OS_write_os_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int first_addr1 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_GM_GM_FST_ADDR1_UNION;
#endif
#define SOC_QICE_GM_GM_FST_ADDR1_first_addr1_START (0)
#define SOC_QICE_GM_GM_FST_ADDR1_first_addr1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int first_addr0 : 32;
    } reg;
} SOC_QICE_GM_GM_FST_ADDR0_UNION;
#endif
#define SOC_QICE_GM_GM_FST_ADDR0_first_addr0_START (0)
#define SOC_QICE_GM_GM_FST_ADDR0_first_addr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr_seria : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_GM_GM_SLP_SERI_UNION;
#endif
#define SOC_QICE_GM_GM_SLP_SERI_addr_seria_START (0)
#define SOC_QICE_GM_GM_SLP_SERI_addr_seria_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sloop_list : 32;
    } reg;
} SOC_QICE_GM_GM_SLP_LIST_UNION;
#endif
#define SOC_QICE_GM_GM_SLP_LIST_sloop_list_START (0)
#define SOC_QICE_GM_GM_SLP_LIST_sloop_list_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slp_time_cnt : 16;
        unsigned int slp_fini_mode : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_QICE_GM_GM_SLP_CFG0_UNION;
#endif
#define SOC_QICE_GM_GM_SLP_CFG0_slp_time_cnt_START (0)
#define SOC_QICE_GM_GM_SLP_CFG0_slp_time_cnt_END (15)
#define SOC_QICE_GM_GM_SLP_CFG0_slp_fini_mode_START (16)
#define SOC_QICE_GM_GM_SLP_CFG0_slp_fini_mode_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slp_read_len : 8;
        unsigned int slp_write_len : 8;
        unsigned int slp_burst_type : 2;
        unsigned int slp_seque_mode : 2;
        unsigned int slp_read_prop : 3;
        unsigned int slp_write_prop : 3;
        unsigned int reserved : 6;
    } reg;
} SOC_QICE_GM_GM_SLP_CFG1_UNION;
#endif
#define SOC_QICE_GM_GM_SLP_CFG1_slp_read_len_START (0)
#define SOC_QICE_GM_GM_SLP_CFG1_slp_read_len_END (7)
#define SOC_QICE_GM_GM_SLP_CFG1_slp_write_len_START (8)
#define SOC_QICE_GM_GM_SLP_CFG1_slp_write_len_END (15)
#define SOC_QICE_GM_GM_SLP_CFG1_slp_burst_type_START (16)
#define SOC_QICE_GM_GM_SLP_CFG1_slp_burst_type_END (17)
#define SOC_QICE_GM_GM_SLP_CFG1_slp_seque_mode_START (18)
#define SOC_QICE_GM_GM_SLP_CFG1_slp_seque_mode_END (19)
#define SOC_QICE_GM_GM_SLP_CFG1_slp_read_prop_START (20)
#define SOC_QICE_GM_GM_SLP_CFG1_slp_read_prop_END (22)
#define SOC_QICE_GM_GM_SLP_CFG1_slp_write_prop_START (23)
#define SOC_QICE_GM_GM_SLP_CFG1_slp_write_prop_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slp_data_byte : 32;
    } reg;
} SOC_QICE_GM_GM_SLP_CFG2_UNION;
#endif
#define SOC_QICE_GM_GM_SLP_CFG2_slp_data_byte_START (0)
#define SOC_QICE_GM_GM_SLP_CFG2_slp_data_byte_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slp_wdat0_pat : 8;
        unsigned int slp_wdat1_pat : 8;
        unsigned int slp_wdat0_prop : 3;
        unsigned int slp_wdat1_prop : 3;
        unsigned int slp_wdata_mode : 1;
        unsigned int reserved : 9;
    } reg;
} SOC_QICE_GM_GM_SLP_CFG3_UNION;
#endif
#define SOC_QICE_GM_GM_SLP_CFG3_slp_wdat0_pat_START (0)
#define SOC_QICE_GM_GM_SLP_CFG3_slp_wdat0_pat_END (7)
#define SOC_QICE_GM_GM_SLP_CFG3_slp_wdat1_pat_START (8)
#define SOC_QICE_GM_GM_SLP_CFG3_slp_wdat1_pat_END (15)
#define SOC_QICE_GM_GM_SLP_CFG3_slp_wdat0_prop_START (16)
#define SOC_QICE_GM_GM_SLP_CFG3_slp_wdat0_prop_END (18)
#define SOC_QICE_GM_GM_SLP_CFG3_slp_wdat1_prop_START (19)
#define SOC_QICE_GM_GM_SLP_CFG3_slp_wdat1_prop_END (21)
#define SOC_QICE_GM_GM_SLP_CFG3_slp_wdata_mode_START (22)
#define SOC_QICE_GM_GM_SLP_CFG3_slp_wdata_mode_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slp_addr_mode : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_GM_GM_SLP_CFG4_UNION;
#endif
#define SOC_QICE_GM_GM_SLP_CFG4_slp_addr_mode_START (0)
#define SOC_QICE_GM_GM_SLP_CFG4_slp_addr_mode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slp_addr_mask0 : 32;
    } reg;
} SOC_QICE_GM_GM_SLP_CFG5_UNION;
#endif
#define SOC_QICE_GM_GM_SLP_CFG5_slp_addr_mask0_START (0)
#define SOC_QICE_GM_GM_SLP_CFG5_slp_addr_mask0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slp_addr_mask1 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_GM_GM_SLP_CFG6_UNION;
#endif
#define SOC_QICE_GM_GM_SLP_CFG6_slp_addr_mask1_START (0)
#define SOC_QICE_GM_GM_SLP_CFG6_slp_addr_mask1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slp_mask_cfg0 : 32;
    } reg;
} SOC_QICE_GM_GM_SLP_CFG7_UNION;
#endif
#define SOC_QICE_GM_GM_SLP_CFG7_slp_mask_cfg0_START (0)
#define SOC_QICE_GM_GM_SLP_CFG7_slp_mask_cfg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slp_mask_cfg1 : 4;
        unsigned int slp_coreid : 6;
        unsigned int slp_snoop : 4;
        unsigned int slp_arcache : 4;
        unsigned int slp_awcache : 4;
        unsigned int slp_ardomain : 2;
        unsigned int slp_awdomain : 2;
        unsigned int slp_gid_add : 2;
        unsigned int reserved : 4;
    } reg;
} SOC_QICE_GM_GM_SLP_CFG8_UNION;
#endif
#define SOC_QICE_GM_GM_SLP_CFG8_slp_mask_cfg1_START (0)
#define SOC_QICE_GM_GM_SLP_CFG8_slp_mask_cfg1_END (3)
#define SOC_QICE_GM_GM_SLP_CFG8_slp_coreid_START (4)
#define SOC_QICE_GM_GM_SLP_CFG8_slp_coreid_END (9)
#define SOC_QICE_GM_GM_SLP_CFG8_slp_snoop_START (10)
#define SOC_QICE_GM_GM_SLP_CFG8_slp_snoop_END (13)
#define SOC_QICE_GM_GM_SLP_CFG8_slp_arcache_START (14)
#define SOC_QICE_GM_GM_SLP_CFG8_slp_arcache_END (17)
#define SOC_QICE_GM_GM_SLP_CFG8_slp_awcache_START (18)
#define SOC_QICE_GM_GM_SLP_CFG8_slp_awcache_END (21)
#define SOC_QICE_GM_GM_SLP_CFG8_slp_ardomain_START (22)
#define SOC_QICE_GM_GM_SLP_CFG8_slp_ardomain_END (23)
#define SOC_QICE_GM_GM_SLP_CFG8_slp_awdomain_START (24)
#define SOC_QICE_GM_GM_SLP_CFG8_slp_awdomain_END (25)
#define SOC_QICE_GM_GM_SLP_CFG8_slp_gid_add_START (26)
#define SOC_QICE_GM_GM_SLP_CFG8_slp_gid_add_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slp_qos : 4;
        unsigned int slp_nsaid : 2;
        unsigned int slp_ns_flag : 1;
        unsigned int slp_memattr : 4;
        unsigned int slp_lpid : 5;
        unsigned int slp_lock : 1;
        unsigned int slp_expcompack : 1;
        unsigned int slp_gid : 4;
        unsigned int slp_sc_hint : 4;
        unsigned int slp_par_full : 1;
        unsigned int slp_pbha : 4;
        unsigned int slp_encry : 1;
    } reg;
} SOC_QICE_GM_GM_SLP_CFG9_UNION;
#endif
#define SOC_QICE_GM_GM_SLP_CFG9_slp_qos_START (0)
#define SOC_QICE_GM_GM_SLP_CFG9_slp_qos_END (3)
#define SOC_QICE_GM_GM_SLP_CFG9_slp_nsaid_START (4)
#define SOC_QICE_GM_GM_SLP_CFG9_slp_nsaid_END (5)
#define SOC_QICE_GM_GM_SLP_CFG9_slp_ns_flag_START (6)
#define SOC_QICE_GM_GM_SLP_CFG9_slp_ns_flag_END (6)
#define SOC_QICE_GM_GM_SLP_CFG9_slp_memattr_START (7)
#define SOC_QICE_GM_GM_SLP_CFG9_slp_memattr_END (10)
#define SOC_QICE_GM_GM_SLP_CFG9_slp_lpid_START (11)
#define SOC_QICE_GM_GM_SLP_CFG9_slp_lpid_END (15)
#define SOC_QICE_GM_GM_SLP_CFG9_slp_lock_START (16)
#define SOC_QICE_GM_GM_SLP_CFG9_slp_lock_END (16)
#define SOC_QICE_GM_GM_SLP_CFG9_slp_expcompack_START (17)
#define SOC_QICE_GM_GM_SLP_CFG9_slp_expcompack_END (17)
#define SOC_QICE_GM_GM_SLP_CFG9_slp_gid_START (18)
#define SOC_QICE_GM_GM_SLP_CFG9_slp_gid_END (21)
#define SOC_QICE_GM_GM_SLP_CFG9_slp_sc_hint_START (22)
#define SOC_QICE_GM_GM_SLP_CFG9_slp_sc_hint_END (25)
#define SOC_QICE_GM_GM_SLP_CFG9_slp_par_full_START (26)
#define SOC_QICE_GM_GM_SLP_CFG9_slp_par_full_END (26)
#define SOC_QICE_GM_GM_SLP_CFG9_slp_pbha_START (27)
#define SOC_QICE_GM_GM_SLP_CFG9_slp_pbha_END (30)
#define SOC_QICE_GM_GM_SLP_CFG9_slp_encry_START (31)
#define SOC_QICE_GM_GM_SLP_CFG9_slp_encry_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slp_delay : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_QICE_GM_GM_SLP_CFG10_UNION;
#endif
#define SOC_QICE_GM_GM_SLP_CFG10_slp_delay_START (0)
#define SOC_QICE_GM_GM_SLP_CFG10_slp_delay_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slp_vcnum : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_GM_GM_SLP_CFG11_UNION;
#endif
#define SOC_QICE_GM_GM_SLP_CFG11_slp_vcnum_START (0)
#define SOC_QICE_GM_GM_SLP_CFG11_slp_vcnum_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slp_num : 32;
    } reg;
} SOC_QICE_GM_GM_SLP_CFG12_UNION;
#endif
#define SOC_QICE_GM_GM_SLP_CFG12_slp_num_START (0)
#define SOC_QICE_GM_GM_SLP_CFG12_slp_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slp_num_read : 19;
        unsigned int reserved : 13;
    } reg;
} SOC_QICE_GM_GM_SLP_CFG13_UNION;
#endif
#define SOC_QICE_GM_GM_SLP_CFG13_slp_num_read_START (0)
#define SOC_QICE_GM_GM_SLP_CFG13_slp_num_read_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slp_num_write : 19;
        unsigned int reserved : 13;
    } reg;
} SOC_QICE_GM_GM_SLP_CFG14_UNION;
#endif
#define SOC_QICE_GM_GM_SLP_CFG14_slp_num_write_START (0)
#define SOC_QICE_GM_GM_SLP_CFG14_slp_num_write_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_cnt : 32;
    } reg;
} SOC_QICE_GM_GM_CMD_CNT_UNION;
#endif
#define SOC_QICE_GM_GM_CMD_CNT_cmd_cnt_START (0)
#define SOC_QICE_GM_GM_CMD_CNT_cmd_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_cnt_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_GM_GM_CMD_CNT_CLR_UNION;
#endif
#define SOC_QICE_GM_GM_CMD_CNT_CLR_cmd_cnt_clr_START (0)
#define SOC_QICE_GM_GM_CMD_CNT_CLR_cmd_cnt_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int data_check_en : 1;
        unsigned int cmd_cnt_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_QICE_GM_GM_CHECK_EN_UNION;
#endif
#define SOC_QICE_GM_GM_CHECK_EN_data_check_en_START (0)
#define SOC_QICE_GM_GM_CHECK_EN_data_check_en_END (0)
#define SOC_QICE_GM_GM_CHECK_EN_cmd_cnt_en_START (1)
#define SOC_QICE_GM_GM_CHECK_EN_cmd_cnt_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slp_finish : 1;
        unsigned int slp_idnum : 4;
        unsigned int slp_type : 2;
        unsigned int slp_remain : 20;
        unsigned int slp_state : 3;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_GM_GM_DFX_CFG0_UNION;
#endif
#define SOC_QICE_GM_GM_DFX_CFG0_slp_finish_START (0)
#define SOC_QICE_GM_GM_DFX_CFG0_slp_finish_END (0)
#define SOC_QICE_GM_GM_DFX_CFG0_slp_idnum_START (1)
#define SOC_QICE_GM_GM_DFX_CFG0_slp_idnum_END (4)
#define SOC_QICE_GM_GM_DFX_CFG0_slp_type_START (5)
#define SOC_QICE_GM_GM_DFX_CFG0_slp_type_END (6)
#define SOC_QICE_GM_GM_DFX_CFG0_slp_remain_START (7)
#define SOC_QICE_GM_GM_DFX_CFG0_slp_remain_END (26)
#define SOC_QICE_GM_GM_DFX_CFG0_slp_state_START (27)
#define SOC_QICE_GM_GM_DFX_CFG0_slp_state_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int write_os_cnt : 8;
        unsigned int read_os_cnt : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_GM_GM_DFX_CFG1_UNION;
#endif
#define SOC_QICE_GM_GM_DFX_CFG1_write_os_cnt_START (0)
#define SOC_QICE_GM_GM_DFX_CFG1_write_os_cnt_END (7)
#define SOC_QICE_GM_GM_DFX_CFG1_read_os_cnt_START (8)
#define SOC_QICE_GM_GM_DFX_CFG1_read_os_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_wreq_vc0_crd_cnt : 8;
        unsigned int dfx_wreq_vc1_crd_cnt : 8;
        unsigned int dfx_wreq_vc2_crd_cnt : 8;
        unsigned int dfx_wreq_vc3_crd_cnt : 8;
    } reg;
} SOC_QICE_GM_GM_DFX_CFG2_UNION;
#endif
#define SOC_QICE_GM_GM_DFX_CFG2_dfx_wreq_vc0_crd_cnt_START (0)
#define SOC_QICE_GM_GM_DFX_CFG2_dfx_wreq_vc0_crd_cnt_END (7)
#define SOC_QICE_GM_GM_DFX_CFG2_dfx_wreq_vc1_crd_cnt_START (8)
#define SOC_QICE_GM_GM_DFX_CFG2_dfx_wreq_vc1_crd_cnt_END (15)
#define SOC_QICE_GM_GM_DFX_CFG2_dfx_wreq_vc2_crd_cnt_START (16)
#define SOC_QICE_GM_GM_DFX_CFG2_dfx_wreq_vc2_crd_cnt_END (23)
#define SOC_QICE_GM_GM_DFX_CFG2_dfx_wreq_vc3_crd_cnt_START (24)
#define SOC_QICE_GM_GM_DFX_CFG2_dfx_wreq_vc3_crd_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_rreq_vc0_crd_cnt : 8;
        unsigned int dfx_rreq_vc1_crd_cnt : 8;
        unsigned int dfx_rreq_vc2_crd_cnt : 8;
        unsigned int dfx_rreq_vc3_crd_cnt : 8;
    } reg;
} SOC_QICE_GM_GM_DFX_CFG3_UNION;
#endif
#define SOC_QICE_GM_GM_DFX_CFG3_dfx_rreq_vc0_crd_cnt_START (0)
#define SOC_QICE_GM_GM_DFX_CFG3_dfx_rreq_vc0_crd_cnt_END (7)
#define SOC_QICE_GM_GM_DFX_CFG3_dfx_rreq_vc1_crd_cnt_START (8)
#define SOC_QICE_GM_GM_DFX_CFG3_dfx_rreq_vc1_crd_cnt_END (15)
#define SOC_QICE_GM_GM_DFX_CFG3_dfx_rreq_vc2_crd_cnt_START (16)
#define SOC_QICE_GM_GM_DFX_CFG3_dfx_rreq_vc2_crd_cnt_END (23)
#define SOC_QICE_GM_GM_DFX_CFG3_dfx_rreq_vc3_crd_cnt_START (24)
#define SOC_QICE_GM_GM_DFX_CFG3_dfx_rreq_vc3_crd_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_rdata_rxempty : 1;
        unsigned int dfx_rdata_rxfull : 1;
        unsigned int dfx_rdata_rxbusy : 1;
        unsigned int dfx_crsp_rxempty : 1;
        unsigned int dfx_crsp_rxfull : 1;
        unsigned int dfx_crsp_rxbusy : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_QICE_GM_GM_DFX_CFG4_UNION;
#endif
#define SOC_QICE_GM_GM_DFX_CFG4_dfx_rdata_rxempty_START (0)
#define SOC_QICE_GM_GM_DFX_CFG4_dfx_rdata_rxempty_END (0)
#define SOC_QICE_GM_GM_DFX_CFG4_dfx_rdata_rxfull_START (1)
#define SOC_QICE_GM_GM_DFX_CFG4_dfx_rdata_rxfull_END (1)
#define SOC_QICE_GM_GM_DFX_CFG4_dfx_rdata_rxbusy_START (2)
#define SOC_QICE_GM_GM_DFX_CFG4_dfx_rdata_rxbusy_END (2)
#define SOC_QICE_GM_GM_DFX_CFG4_dfx_crsp_rxempty_START (3)
#define SOC_QICE_GM_GM_DFX_CFG4_dfx_crsp_rxempty_END (3)
#define SOC_QICE_GM_GM_DFX_CFG4_dfx_crsp_rxfull_START (4)
#define SOC_QICE_GM_GM_DFX_CFG4_dfx_crsp_rxfull_END (4)
#define SOC_QICE_GM_GM_DFX_CFG4_dfx_crsp_rxbusy_START (5)
#define SOC_QICE_GM_GM_DFX_CFG4_dfx_crsp_rxbusy_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnal_ns_int_mask : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_GM_GM_DFX_INT_CTRL0_UNION;
#endif
#define SOC_QICE_GM_GM_DFX_INT_CTRL0_abnal_ns_int_mask_START (0)
#define SOC_QICE_GM_GM_DFX_INT_CTRL0_abnal_ns_int_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnal_ns_int_dis : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_GM_GM_DFX_INT_CTRL1_UNION;
#endif
#define SOC_QICE_GM_GM_DFX_INT_CTRL1_abnal_ns_int_dis_START (0)
#define SOC_QICE_GM_GM_DFX_INT_CTRL1_abnal_ns_int_dis_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_GM_GM_DFX_INT_CTRL2_UNION;
#endif
#define SOC_QICE_GM_GM_DFX_INT_CTRL2_abnml_ns_int_clr_START (0)
#define SOC_QICE_GM_GM_DFX_INT_CTRL2_abnml_ns_int_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_glb_mask : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_GM_GM_DFX_INT_CTRL3_UNION;
#endif
#define SOC_QICE_GM_GM_DFX_INT_CTRL3_abnml_ns_int_glb_mask_START (0)
#define SOC_QICE_GM_GM_DFX_INT_CTRL3_abnml_ns_int_glb_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_info0 : 32;
    } reg;
} SOC_QICE_GM_GM_DFX_INT_INO0_UNION;
#endif
#define SOC_QICE_GM_GM_DFX_INT_INO0_abnml_ns_int_info0_START (0)
#define SOC_QICE_GM_GM_DFX_INT_INO0_abnml_ns_int_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_info1 : 32;
    } reg;
} SOC_QICE_GM_GM_DFX_INT_INO1_UNION;
#endif
#define SOC_QICE_GM_GM_DFX_INT_INO1_abnml_ns_int_info1_START (0)
#define SOC_QICE_GM_GM_DFX_INT_INO1_abnml_ns_int_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_info2 : 32;
    } reg;
} SOC_QICE_GM_GM_DFX_INT_INO2_UNION;
#endif
#define SOC_QICE_GM_GM_DFX_INT_INO2_abnml_ns_int_info2_START (0)
#define SOC_QICE_GM_GM_DFX_INT_INO2_abnml_ns_int_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_info3 : 32;
    } reg;
} SOC_QICE_GM_GM_DFX_INT_INO3_UNION;
#endif
#define SOC_QICE_GM_GM_DFX_INT_INO3_abnml_ns_int_info3_START (0)
#define SOC_QICE_GM_GM_DFX_INT_INO3_abnml_ns_int_info3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_int_type : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_QICE_GM_GM_DFX_NS_INT_STATUS0_UNION;
#endif
#define SOC_QICE_GM_GM_DFX_NS_INT_STATUS0_abnml_ns_int_type_START (0)
#define SOC_QICE_GM_GM_DFX_NS_INT_STATUS0_abnml_ns_int_type_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_org_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_GM_GM_DFX_NS_INT_STATUS1_UNION;
#endif
#define SOC_QICE_GM_GM_DFX_NS_INT_STATUS1_abnml_ns_org_status_START (0)
#define SOC_QICE_GM_GM_DFX_NS_INT_STATUS1_abnml_ns_org_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int abnml_ns_mask_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_GM_GM_DFX_NS_INT_STATUS2_UNION;
#endif
#define SOC_QICE_GM_GM_DFX_NS_INT_STATUS2_abnml_ns_mask_status_START (0)
#define SOC_QICE_GM_GM_DFX_NS_INT_STATUS2_abnml_ns_mask_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int table_vld0 : 32;
    } reg;
} SOC_QICE_GM_GM_DFX_TABLE_VLD0_UNION;
#endif
#define SOC_QICE_GM_GM_DFX_TABLE_VLD0_table_vld0_START (0)
#define SOC_QICE_GM_GM_DFX_TABLE_VLD0_table_vld0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int table_vld1 : 32;
    } reg;
} SOC_QICE_GM_GM_DFX_TABLE_VLD1_UNION;
#endif
#define SOC_QICE_GM_GM_DFX_TABLE_VLD1_table_vld1_START (0)
#define SOC_QICE_GM_GM_DFX_TABLE_VLD1_table_vld1_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
