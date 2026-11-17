#ifndef __SOC_FCM_PERI_INTERFACE_H__
#define __SOC_FCM_PERI_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FCM_PERI_FCM_BASE_CFG_ADDR(base) ((base) + (0x800UL))
#define SOC_FCM_PERI_FCM_CLK_EN_ADDR(base) ((base) + (0x808UL))
#define SOC_FCM_PERI_PD_FAST_WAKEUP_CFG_ADDR(base) ((base) + (0x80CUL))
#define SOC_FCM_PERI_FCM_RST_EN_ADDR(base) ((base) + (0x810UL))
#define SOC_FCM_PERI_FCM_RST_DIS_ADDR(base) ((base) + (0x814UL))
#define SOC_FCM_PERI_FCM_RST_STAT_ADDR(base) ((base) + (0x818UL))
#define SOC_FCM_PERI_ENYO_MITIGATION_CFG_ADDR(base) ((base) + (0x848UL))
#define SOC_FCM_PERI_FCM_ASP_POWERDN_REG_ADDR(base) ((base) + (0x85CUL))
#define SOC_FCM_PERI_FCM_QCHANNEL_CTL_REG_ADDR(base) ((base) + (0x860UL))
#define SOC_FCM_PERI_FCM_QCHANNEL_CFGCNT_REG0_ADDR(base) ((base) + (0x864UL))
#define SOC_FCM_PERI_FCM_QCHANNEL_CFGCNT_REG1_ADDR(base) ((base) + (0x868UL))
#define SOC_FCM_PERI_FCM_GIC_TEST_CFG_REG_ADDR(base) ((base) + (0x86CUL))
#define SOC_FCM_PERI_FCM_DLYCNT_CFG_REG_ADDR(base) ((base) + (0x884UL))
#define SOC_FCM_PERI_BLK_MIDR_VALUE_BIG_ADDR(base) ((base) + (0x8BCUL))
#define SOC_FCM_PERI_BLK_DEBUG_VALUE_BIG_ADDR(base) ((base) + (0x8C0UL))
#define SOC_FCM_PERI_BLK_MIDR_VALUE_MID_ADDR(base) ((base) + (0x8C4UL))
#define SOC_FCM_PERI_BLK_DEBUG_VALUE_MID_ADDR(base) ((base) + (0x8C8UL))
#define SOC_FCM_PERI_PCRTR_MID_PARA_A_ADDR(base) ((base) + (0x8CCUL))
#define SOC_FCM_PERI_PCRTR_MID_PARA_B_ADDR(base) ((base) + (0x8D0UL))
#define SOC_FCM_PERI_PCRTR_MID_PARA_C_ADDR(base) ((base) + (0x8D4UL))
#define SOC_FCM_PERI_PCRTR_BIG_PARA_A_ADDR(base) ((base) + (0x8D8UL))
#define SOC_FCM_PERI_PCRTR_BIG_PARA_B_ADDR(base) ((base) + (0x8DCUL))
#define SOC_FCM_PERI_PCRTR_BIG_PARA_C_ADDR(base) ((base) + (0x8E0UL))
#define SOC_FCM_PERI_CPU_LOAD_CNT_THRETHOD_ADDR(base) ((base) + (0x8E4UL))
#define SOC_FCM_PERI_FCM_MPMM_STATECFG_ADDR(base) ((base) + (0x8E8UL))
#define SOC_FCM_PERI_SC_EXCEL_CTRL_ADDR(base) ((base) + (0x8ECUL))
#define SOC_FCM_PERI_KARMA_2T1_CTL_ADDR(base) ((base) + (0x8F0UL))
#define SOC_FCM_PERI_PCRTR_PARA_SAMPLE_ADDR(base) ((base) + (0x8F8UL))
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_ADDR(base) ((base) + (0xC00UL))
#define SOC_FCM_PERI_FCM_LOCAL_STAT1_ADDR(base) ((base) + (0xC04UL))
#define SOC_FCM_PERI_FCM_LOCAL_STAT11_ADDR(base) ((base) + (0xC2CUL))
#define SOC_FCM_PERI_FCM_LOCAL_STAT21_ADDR(base) ((base) + (0xC54UL))
#define SOC_FCM_PERI_FCM_LOCAL_STAT22_ADDR(base) ((base) + (0xC58UL))
#define SOC_FCM_PERI_FCM_LOCAL_STAT23_ADDR(base) ((base) + (0xC5CUL))
#define SOC_FCM_PERI_FCM_LOCAL_STAT24_ADDR(base) ((base) + (0xC60UL))
#define SOC_FCM_PERI_FCM_LOCAL_STAT25_ADDR(base) ((base) + (0xC64UL))
#define SOC_FCM_PERI_FCM_LOCAL_STAT26_ADDR(base) ((base) + (0xC68UL))
#define SOC_FCM_PERI_FCM_LOCAL_STAT31_ADDR(base) ((base) + (0xC7CUL))
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_ADDR(base) ((base) + (0xC80UL))
#else
#define SOC_FCM_PERI_FCM_BASE_CFG_ADDR(base) ((base) + (0x800))
#define SOC_FCM_PERI_FCM_CLK_EN_ADDR(base) ((base) + (0x808))
#define SOC_FCM_PERI_PD_FAST_WAKEUP_CFG_ADDR(base) ((base) + (0x80C))
#define SOC_FCM_PERI_FCM_RST_EN_ADDR(base) ((base) + (0x810))
#define SOC_FCM_PERI_FCM_RST_DIS_ADDR(base) ((base) + (0x814))
#define SOC_FCM_PERI_FCM_RST_STAT_ADDR(base) ((base) + (0x818))
#define SOC_FCM_PERI_ENYO_MITIGATION_CFG_ADDR(base) ((base) + (0x848))
#define SOC_FCM_PERI_FCM_ASP_POWERDN_REG_ADDR(base) ((base) + (0x85C))
#define SOC_FCM_PERI_FCM_QCHANNEL_CTL_REG_ADDR(base) ((base) + (0x860))
#define SOC_FCM_PERI_FCM_QCHANNEL_CFGCNT_REG0_ADDR(base) ((base) + (0x864))
#define SOC_FCM_PERI_FCM_QCHANNEL_CFGCNT_REG1_ADDR(base) ((base) + (0x868))
#define SOC_FCM_PERI_FCM_GIC_TEST_CFG_REG_ADDR(base) ((base) + (0x86C))
#define SOC_FCM_PERI_FCM_DLYCNT_CFG_REG_ADDR(base) ((base) + (0x884))
#define SOC_FCM_PERI_BLK_MIDR_VALUE_BIG_ADDR(base) ((base) + (0x8BC))
#define SOC_FCM_PERI_BLK_DEBUG_VALUE_BIG_ADDR(base) ((base) + (0x8C0))
#define SOC_FCM_PERI_BLK_MIDR_VALUE_MID_ADDR(base) ((base) + (0x8C4))
#define SOC_FCM_PERI_BLK_DEBUG_VALUE_MID_ADDR(base) ((base) + (0x8C8))
#define SOC_FCM_PERI_PCRTR_MID_PARA_A_ADDR(base) ((base) + (0x8CC))
#define SOC_FCM_PERI_PCRTR_MID_PARA_B_ADDR(base) ((base) + (0x8D0))
#define SOC_FCM_PERI_PCRTR_MID_PARA_C_ADDR(base) ((base) + (0x8D4))
#define SOC_FCM_PERI_PCRTR_BIG_PARA_A_ADDR(base) ((base) + (0x8D8))
#define SOC_FCM_PERI_PCRTR_BIG_PARA_B_ADDR(base) ((base) + (0x8DC))
#define SOC_FCM_PERI_PCRTR_BIG_PARA_C_ADDR(base) ((base) + (0x8E0))
#define SOC_FCM_PERI_CPU_LOAD_CNT_THRETHOD_ADDR(base) ((base) + (0x8E4))
#define SOC_FCM_PERI_FCM_MPMM_STATECFG_ADDR(base) ((base) + (0x8E8))
#define SOC_FCM_PERI_SC_EXCEL_CTRL_ADDR(base) ((base) + (0x8EC))
#define SOC_FCM_PERI_KARMA_2T1_CTL_ADDR(base) ((base) + (0x8F0))
#define SOC_FCM_PERI_PCRTR_PARA_SAMPLE_ADDR(base) ((base) + (0x8F8))
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_ADDR(base) ((base) + (0xC00))
#define SOC_FCM_PERI_FCM_LOCAL_STAT1_ADDR(base) ((base) + (0xC04))
#define SOC_FCM_PERI_FCM_LOCAL_STAT11_ADDR(base) ((base) + (0xC2C))
#define SOC_FCM_PERI_FCM_LOCAL_STAT21_ADDR(base) ((base) + (0xC54))
#define SOC_FCM_PERI_FCM_LOCAL_STAT22_ADDR(base) ((base) + (0xC58))
#define SOC_FCM_PERI_FCM_LOCAL_STAT23_ADDR(base) ((base) + (0xC5C))
#define SOC_FCM_PERI_FCM_LOCAL_STAT24_ADDR(base) ((base) + (0xC60))
#define SOC_FCM_PERI_FCM_LOCAL_STAT25_ADDR(base) ((base) + (0xC64))
#define SOC_FCM_PERI_FCM_LOCAL_STAT26_ADDR(base) ((base) + (0xC68))
#define SOC_FCM_PERI_FCM_LOCAL_STAT31_ADDR(base) ((base) + (0xC7C))
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_ADDR(base) ((base) + (0xC80))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aa64naa32 : 8;
        unsigned int ctiirqack_sel : 1;
        unsigned int bisr_sd_bypass : 1;
        unsigned int reserved : 2;
        unsigned int vinithi : 4;
        unsigned int sys_cnt_en_dly : 6;
        unsigned int wfi_source_sel : 1;
        unsigned int fcm_bus_dbg_en : 1;
        unsigned int l3_dataram_sd_dly_bypass : 1;
        unsigned int acp_wakeup_bypass : 1;
        unsigned int dbgconnected : 1;
        unsigned int pmusnapshotreq : 1;
        unsigned int debug_block_wakeup_bypass : 1;
        unsigned int little_core_clkgate_sel : 1;
        unsigned int middle_core_clkgate_sel : 1;
        unsigned int big_core_clkgate_sel : 1;
    } reg;
} SOC_FCM_PERI_FCM_BASE_CFG_UNION;
#endif
#define SOC_FCM_PERI_FCM_BASE_CFG_aa64naa32_START (0)
#define SOC_FCM_PERI_FCM_BASE_CFG_aa64naa32_END (7)
#define SOC_FCM_PERI_FCM_BASE_CFG_ctiirqack_sel_START (8)
#define SOC_FCM_PERI_FCM_BASE_CFG_ctiirqack_sel_END (8)
#define SOC_FCM_PERI_FCM_BASE_CFG_bisr_sd_bypass_START (9)
#define SOC_FCM_PERI_FCM_BASE_CFG_bisr_sd_bypass_END (9)
#define SOC_FCM_PERI_FCM_BASE_CFG_vinithi_START (12)
#define SOC_FCM_PERI_FCM_BASE_CFG_vinithi_END (15)
#define SOC_FCM_PERI_FCM_BASE_CFG_sys_cnt_en_dly_START (16)
#define SOC_FCM_PERI_FCM_BASE_CFG_sys_cnt_en_dly_END (21)
#define SOC_FCM_PERI_FCM_BASE_CFG_wfi_source_sel_START (22)
#define SOC_FCM_PERI_FCM_BASE_CFG_wfi_source_sel_END (22)
#define SOC_FCM_PERI_FCM_BASE_CFG_fcm_bus_dbg_en_START (23)
#define SOC_FCM_PERI_FCM_BASE_CFG_fcm_bus_dbg_en_END (23)
#define SOC_FCM_PERI_FCM_BASE_CFG_l3_dataram_sd_dly_bypass_START (24)
#define SOC_FCM_PERI_FCM_BASE_CFG_l3_dataram_sd_dly_bypass_END (24)
#define SOC_FCM_PERI_FCM_BASE_CFG_acp_wakeup_bypass_START (25)
#define SOC_FCM_PERI_FCM_BASE_CFG_acp_wakeup_bypass_END (25)
#define SOC_FCM_PERI_FCM_BASE_CFG_dbgconnected_START (26)
#define SOC_FCM_PERI_FCM_BASE_CFG_dbgconnected_END (26)
#define SOC_FCM_PERI_FCM_BASE_CFG_pmusnapshotreq_START (27)
#define SOC_FCM_PERI_FCM_BASE_CFG_pmusnapshotreq_END (27)
#define SOC_FCM_PERI_FCM_BASE_CFG_debug_block_wakeup_bypass_START (28)
#define SOC_FCM_PERI_FCM_BASE_CFG_debug_block_wakeup_bypass_END (28)
#define SOC_FCM_PERI_FCM_BASE_CFG_little_core_clkgate_sel_START (29)
#define SOC_FCM_PERI_FCM_BASE_CFG_little_core_clkgate_sel_END (29)
#define SOC_FCM_PERI_FCM_BASE_CFG_middle_core_clkgate_sel_START (30)
#define SOC_FCM_PERI_FCM_BASE_CFG_middle_core_clkgate_sel_END (30)
#define SOC_FCM_PERI_FCM_BASE_CFG_big_core_clkgate_sel_START (31)
#define SOC_FCM_PERI_FCM_BASE_CFG_big_core_clkgate_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_coreclk_little : 4;
        unsigned int gt_clk_coreclk_middle : 3;
        unsigned int gt_clk_coreclk_big : 1;
        unsigned int gt_clk_adb_brg : 1;
        unsigned int gt_fcm_tidm0 : 1;
        unsigned int gt_clk_adb_brg_acp : 1;
        unsigned int gt_clk_atclk : 1;
        unsigned int gt_clk_atclk_top : 1;
        unsigned int gt_clk_periphclk : 1;
        unsigned int gt_clk_adb_brg_pp : 1;
        unsigned int gt_fcm_tidm1 : 1;
        unsigned int clken_masken : 16;
    } reg;
} SOC_FCM_PERI_FCM_CLK_EN_UNION;
#endif
#define SOC_FCM_PERI_FCM_CLK_EN_gt_clk_coreclk_little_START (0)
#define SOC_FCM_PERI_FCM_CLK_EN_gt_clk_coreclk_little_END (3)
#define SOC_FCM_PERI_FCM_CLK_EN_gt_clk_coreclk_middle_START (4)
#define SOC_FCM_PERI_FCM_CLK_EN_gt_clk_coreclk_middle_END (6)
#define SOC_FCM_PERI_FCM_CLK_EN_gt_clk_coreclk_big_START (7)
#define SOC_FCM_PERI_FCM_CLK_EN_gt_clk_coreclk_big_END (7)
#define SOC_FCM_PERI_FCM_CLK_EN_gt_clk_adb_brg_START (8)
#define SOC_FCM_PERI_FCM_CLK_EN_gt_clk_adb_brg_END (8)
#define SOC_FCM_PERI_FCM_CLK_EN_gt_fcm_tidm0_START (9)
#define SOC_FCM_PERI_FCM_CLK_EN_gt_fcm_tidm0_END (9)
#define SOC_FCM_PERI_FCM_CLK_EN_gt_clk_adb_brg_acp_START (10)
#define SOC_FCM_PERI_FCM_CLK_EN_gt_clk_adb_brg_acp_END (10)
#define SOC_FCM_PERI_FCM_CLK_EN_gt_clk_atclk_START (11)
#define SOC_FCM_PERI_FCM_CLK_EN_gt_clk_atclk_END (11)
#define SOC_FCM_PERI_FCM_CLK_EN_gt_clk_atclk_top_START (12)
#define SOC_FCM_PERI_FCM_CLK_EN_gt_clk_atclk_top_END (12)
#define SOC_FCM_PERI_FCM_CLK_EN_gt_clk_periphclk_START (13)
#define SOC_FCM_PERI_FCM_CLK_EN_gt_clk_periphclk_END (13)
#define SOC_FCM_PERI_FCM_CLK_EN_gt_clk_adb_brg_pp_START (14)
#define SOC_FCM_PERI_FCM_CLK_EN_gt_clk_adb_brg_pp_END (14)
#define SOC_FCM_PERI_FCM_CLK_EN_gt_fcm_tidm1_START (15)
#define SOC_FCM_PERI_FCM_CLK_EN_gt_fcm_tidm1_END (15)
#define SOC_FCM_PERI_FCM_CLK_EN_clken_masken_START (16)
#define SOC_FCM_PERI_FCM_CLK_EN_clken_masken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wakeup_rank_en : 1;
        unsigned int wakeup_ch_en : 1;
        unsigned int ddr_intlv_gran : 2;
        unsigned int ddr_ch4_order : 1;
        unsigned int ddr_addr_shift_mode : 1;
        unsigned int ddr_rank_map : 16;
        unsigned int ddr_rank_intlv_en : 1;
        unsigned int ddr_rank_intlv_gran : 5;
        unsigned int ddr_wakeup_prd : 2;
        unsigned int ddr_wakeup_sc_enable : 1;
        unsigned int gid_zero_sc : 1;
    } reg;
} SOC_FCM_PERI_PD_FAST_WAKEUP_CFG_UNION;
#endif
#define SOC_FCM_PERI_PD_FAST_WAKEUP_CFG_wakeup_rank_en_START (0)
#define SOC_FCM_PERI_PD_FAST_WAKEUP_CFG_wakeup_rank_en_END (0)
#define SOC_FCM_PERI_PD_FAST_WAKEUP_CFG_wakeup_ch_en_START (1)
#define SOC_FCM_PERI_PD_FAST_WAKEUP_CFG_wakeup_ch_en_END (1)
#define SOC_FCM_PERI_PD_FAST_WAKEUP_CFG_ddr_intlv_gran_START (2)
#define SOC_FCM_PERI_PD_FAST_WAKEUP_CFG_ddr_intlv_gran_END (3)
#define SOC_FCM_PERI_PD_FAST_WAKEUP_CFG_ddr_ch4_order_START (4)
#define SOC_FCM_PERI_PD_FAST_WAKEUP_CFG_ddr_ch4_order_END (4)
#define SOC_FCM_PERI_PD_FAST_WAKEUP_CFG_ddr_addr_shift_mode_START (5)
#define SOC_FCM_PERI_PD_FAST_WAKEUP_CFG_ddr_addr_shift_mode_END (5)
#define SOC_FCM_PERI_PD_FAST_WAKEUP_CFG_ddr_rank_map_START (6)
#define SOC_FCM_PERI_PD_FAST_WAKEUP_CFG_ddr_rank_map_END (21)
#define SOC_FCM_PERI_PD_FAST_WAKEUP_CFG_ddr_rank_intlv_en_START (22)
#define SOC_FCM_PERI_PD_FAST_WAKEUP_CFG_ddr_rank_intlv_en_END (22)
#define SOC_FCM_PERI_PD_FAST_WAKEUP_CFG_ddr_rank_intlv_gran_START (23)
#define SOC_FCM_PERI_PD_FAST_WAKEUP_CFG_ddr_rank_intlv_gran_END (27)
#define SOC_FCM_PERI_PD_FAST_WAKEUP_CFG_ddr_wakeup_prd_START (28)
#define SOC_FCM_PERI_PD_FAST_WAKEUP_CFG_ddr_wakeup_prd_END (29)
#define SOC_FCM_PERI_PD_FAST_WAKEUP_CFG_ddr_wakeup_sc_enable_START (30)
#define SOC_FCM_PERI_PD_FAST_WAKEUP_CFG_ddr_wakeup_sc_enable_END (30)
#define SOC_FCM_PERI_PD_FAST_WAKEUP_CFG_gid_zero_sc_START (31)
#define SOC_FCM_PERI_PD_FAST_WAKEUP_CFG_gid_zero_sc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int little_core_soft_rst_en : 4;
        unsigned int middle_core_soft_rst_en : 2;
        unsigned int big_core_soft_rst_en : 2;
        unsigned int adb_brg_m0_rst_en : 1;
        unsigned int adb_brg_m1_rst_en : 1;
        unsigned int adb_acp_rst_en : 1;
        unsigned int adb_pp_rst_en : 1;
        unsigned int big_cluster_rst_en : 1;
        unsigned int middle_cluster_rst_en : 1;
        unsigned int little_cluster_rst_en : 1;
        unsigned int atb_top_rst_en : 1;
        unsigned int atb_fcm_rst_en : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_FCM_PERI_FCM_RST_EN_UNION;
#endif
#define SOC_FCM_PERI_FCM_RST_EN_little_core_soft_rst_en_START (0)
#define SOC_FCM_PERI_FCM_RST_EN_little_core_soft_rst_en_END (3)
#define SOC_FCM_PERI_FCM_RST_EN_middle_core_soft_rst_en_START (4)
#define SOC_FCM_PERI_FCM_RST_EN_middle_core_soft_rst_en_END (5)
#define SOC_FCM_PERI_FCM_RST_EN_big_core_soft_rst_en_START (6)
#define SOC_FCM_PERI_FCM_RST_EN_big_core_soft_rst_en_END (7)
#define SOC_FCM_PERI_FCM_RST_EN_adb_brg_m0_rst_en_START (8)
#define SOC_FCM_PERI_FCM_RST_EN_adb_brg_m0_rst_en_END (8)
#define SOC_FCM_PERI_FCM_RST_EN_adb_brg_m1_rst_en_START (9)
#define SOC_FCM_PERI_FCM_RST_EN_adb_brg_m1_rst_en_END (9)
#define SOC_FCM_PERI_FCM_RST_EN_adb_acp_rst_en_START (10)
#define SOC_FCM_PERI_FCM_RST_EN_adb_acp_rst_en_END (10)
#define SOC_FCM_PERI_FCM_RST_EN_adb_pp_rst_en_START (11)
#define SOC_FCM_PERI_FCM_RST_EN_adb_pp_rst_en_END (11)
#define SOC_FCM_PERI_FCM_RST_EN_big_cluster_rst_en_START (12)
#define SOC_FCM_PERI_FCM_RST_EN_big_cluster_rst_en_END (12)
#define SOC_FCM_PERI_FCM_RST_EN_middle_cluster_rst_en_START (13)
#define SOC_FCM_PERI_FCM_RST_EN_middle_cluster_rst_en_END (13)
#define SOC_FCM_PERI_FCM_RST_EN_little_cluster_rst_en_START (14)
#define SOC_FCM_PERI_FCM_RST_EN_little_cluster_rst_en_END (14)
#define SOC_FCM_PERI_FCM_RST_EN_atb_top_rst_en_START (15)
#define SOC_FCM_PERI_FCM_RST_EN_atb_top_rst_en_END (15)
#define SOC_FCM_PERI_FCM_RST_EN_atb_fcm_rst_en_START (16)
#define SOC_FCM_PERI_FCM_RST_EN_atb_fcm_rst_en_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int little_core_soft_rst_dis : 4;
        unsigned int middle_core_soft_rst_dis : 2;
        unsigned int big_core_soft_rst_dis : 2;
        unsigned int adb_brg_m0_rst_dis : 1;
        unsigned int adb_brg_m1_rst_dis : 1;
        unsigned int adb_acp_rst_dis : 1;
        unsigned int adb_pp_rst_dis : 1;
        unsigned int big_cluster_rst_dis : 1;
        unsigned int middle_cluster_rst_dis : 1;
        unsigned int little_cluster_rst_dis : 1;
        unsigned int atb_top_rst_dis : 1;
        unsigned int atb_fcm_rst_dis : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_FCM_PERI_FCM_RST_DIS_UNION;
#endif
#define SOC_FCM_PERI_FCM_RST_DIS_little_core_soft_rst_dis_START (0)
#define SOC_FCM_PERI_FCM_RST_DIS_little_core_soft_rst_dis_END (3)
#define SOC_FCM_PERI_FCM_RST_DIS_middle_core_soft_rst_dis_START (4)
#define SOC_FCM_PERI_FCM_RST_DIS_middle_core_soft_rst_dis_END (5)
#define SOC_FCM_PERI_FCM_RST_DIS_big_core_soft_rst_dis_START (6)
#define SOC_FCM_PERI_FCM_RST_DIS_big_core_soft_rst_dis_END (7)
#define SOC_FCM_PERI_FCM_RST_DIS_adb_brg_m0_rst_dis_START (8)
#define SOC_FCM_PERI_FCM_RST_DIS_adb_brg_m0_rst_dis_END (8)
#define SOC_FCM_PERI_FCM_RST_DIS_adb_brg_m1_rst_dis_START (9)
#define SOC_FCM_PERI_FCM_RST_DIS_adb_brg_m1_rst_dis_END (9)
#define SOC_FCM_PERI_FCM_RST_DIS_adb_acp_rst_dis_START (10)
#define SOC_FCM_PERI_FCM_RST_DIS_adb_acp_rst_dis_END (10)
#define SOC_FCM_PERI_FCM_RST_DIS_adb_pp_rst_dis_START (11)
#define SOC_FCM_PERI_FCM_RST_DIS_adb_pp_rst_dis_END (11)
#define SOC_FCM_PERI_FCM_RST_DIS_big_cluster_rst_dis_START (12)
#define SOC_FCM_PERI_FCM_RST_DIS_big_cluster_rst_dis_END (12)
#define SOC_FCM_PERI_FCM_RST_DIS_middle_cluster_rst_dis_START (13)
#define SOC_FCM_PERI_FCM_RST_DIS_middle_cluster_rst_dis_END (13)
#define SOC_FCM_PERI_FCM_RST_DIS_little_cluster_rst_dis_START (14)
#define SOC_FCM_PERI_FCM_RST_DIS_little_cluster_rst_dis_END (14)
#define SOC_FCM_PERI_FCM_RST_DIS_atb_top_rst_dis_START (15)
#define SOC_FCM_PERI_FCM_RST_DIS_atb_top_rst_dis_END (15)
#define SOC_FCM_PERI_FCM_RST_DIS_atb_fcm_rst_dis_START (16)
#define SOC_FCM_PERI_FCM_RST_DIS_atb_fcm_rst_dis_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int little_core_soft_rst_stat : 4;
        unsigned int middle_core_soft_rst_stat : 2;
        unsigned int big_core_soft_rst_stat : 2;
        unsigned int adb_brg_m0_rst_stat : 1;
        unsigned int adb_brg_m1_rst_stat : 1;
        unsigned int adb_acp_rst_stat : 1;
        unsigned int adb_pp_rst_stat : 1;
        unsigned int big_cluster_rst_stat : 1;
        unsigned int middle_cluster_rst_stat : 1;
        unsigned int little_cluster_rst_stat : 1;
        unsigned int atb_top_rst_stat : 1;
        unsigned int atb_fcm_rst_stat : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_FCM_PERI_FCM_RST_STAT_UNION;
#endif
#define SOC_FCM_PERI_FCM_RST_STAT_little_core_soft_rst_stat_START (0)
#define SOC_FCM_PERI_FCM_RST_STAT_little_core_soft_rst_stat_END (3)
#define SOC_FCM_PERI_FCM_RST_STAT_middle_core_soft_rst_stat_START (4)
#define SOC_FCM_PERI_FCM_RST_STAT_middle_core_soft_rst_stat_END (5)
#define SOC_FCM_PERI_FCM_RST_STAT_big_core_soft_rst_stat_START (6)
#define SOC_FCM_PERI_FCM_RST_STAT_big_core_soft_rst_stat_END (7)
#define SOC_FCM_PERI_FCM_RST_STAT_adb_brg_m0_rst_stat_START (8)
#define SOC_FCM_PERI_FCM_RST_STAT_adb_brg_m0_rst_stat_END (8)
#define SOC_FCM_PERI_FCM_RST_STAT_adb_brg_m1_rst_stat_START (9)
#define SOC_FCM_PERI_FCM_RST_STAT_adb_brg_m1_rst_stat_END (9)
#define SOC_FCM_PERI_FCM_RST_STAT_adb_acp_rst_stat_START (10)
#define SOC_FCM_PERI_FCM_RST_STAT_adb_acp_rst_stat_END (10)
#define SOC_FCM_PERI_FCM_RST_STAT_adb_pp_rst_stat_START (11)
#define SOC_FCM_PERI_FCM_RST_STAT_adb_pp_rst_stat_END (11)
#define SOC_FCM_PERI_FCM_RST_STAT_big_cluster_rst_stat_START (12)
#define SOC_FCM_PERI_FCM_RST_STAT_big_cluster_rst_stat_END (12)
#define SOC_FCM_PERI_FCM_RST_STAT_middle_cluster_rst_stat_START (13)
#define SOC_FCM_PERI_FCM_RST_STAT_middle_cluster_rst_stat_END (13)
#define SOC_FCM_PERI_FCM_RST_STAT_little_cluster_rst_stat_START (14)
#define SOC_FCM_PERI_FCM_RST_STAT_little_cluster_rst_stat_END (14)
#define SOC_FCM_PERI_FCM_RST_STAT_atb_top_rst_stat_START (15)
#define SOC_FCM_PERI_FCM_RST_STAT_atb_top_rst_stat_END (15)
#define SOC_FCM_PERI_FCM_RST_STAT_atb_fcm_rst_stat_START (16)
#define SOC_FCM_PERI_FCM_RST_STAT_atb_fcm_rst_stat_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enyo_mpmm_en : 4;
        unsigned int reserved : 12;
        unsigned int aw_cmd_ost_cfg : 8;
        unsigned int ar_cmd_ost_cfg : 8;
    } reg;
} SOC_FCM_PERI_ENYO_MITIGATION_CFG_UNION;
#endif
#define SOC_FCM_PERI_ENYO_MITIGATION_CFG_enyo_mpmm_en_START (0)
#define SOC_FCM_PERI_ENYO_MITIGATION_CFG_enyo_mpmm_en_END (3)
#define SOC_FCM_PERI_ENYO_MITIGATION_CFG_aw_cmd_ost_cfg_START (16)
#define SOC_FCM_PERI_ENYO_MITIGATION_CFG_aw_cmd_ost_cfg_END (23)
#define SOC_FCM_PERI_ENYO_MITIGATION_CFG_ar_cmd_ost_cfg_START (24)
#define SOC_FCM_PERI_ENYO_MITIGATION_CFG_ar_cmd_ost_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int asp_power_reg_cpu : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_FCM_PERI_FCM_ASP_POWERDN_REG_UNION;
#endif
#define SOC_FCM_PERI_FCM_ASP_POWERDN_REG_asp_power_reg_cpu_START (0)
#define SOC_FCM_PERI_FCM_ASP_POWERDN_REG_asp_power_reg_cpu_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_sclk_q_channel_en : 1;
        unsigned int fcm_atclk_q_channel_en : 1;
        unsigned int fcm_pclk_q_channel_en : 1;
        unsigned int fcm_gicclk_q_channel_en : 1;
        unsigned int fcm_debug_clk_q_channel_en : 1;
        unsigned int fcm_debug_pwr_q_channel_qreqn : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_FCM_PERI_FCM_QCHANNEL_CTL_REG_UNION;
#endif
#define SOC_FCM_PERI_FCM_QCHANNEL_CTL_REG_fcm_sclk_q_channel_en_START (0)
#define SOC_FCM_PERI_FCM_QCHANNEL_CTL_REG_fcm_sclk_q_channel_en_END (0)
#define SOC_FCM_PERI_FCM_QCHANNEL_CTL_REG_fcm_atclk_q_channel_en_START (1)
#define SOC_FCM_PERI_FCM_QCHANNEL_CTL_REG_fcm_atclk_q_channel_en_END (1)
#define SOC_FCM_PERI_FCM_QCHANNEL_CTL_REG_fcm_pclk_q_channel_en_START (2)
#define SOC_FCM_PERI_FCM_QCHANNEL_CTL_REG_fcm_pclk_q_channel_en_END (2)
#define SOC_FCM_PERI_FCM_QCHANNEL_CTL_REG_fcm_gicclk_q_channel_en_START (3)
#define SOC_FCM_PERI_FCM_QCHANNEL_CTL_REG_fcm_gicclk_q_channel_en_END (3)
#define SOC_FCM_PERI_FCM_QCHANNEL_CTL_REG_fcm_debug_clk_q_channel_en_START (4)
#define SOC_FCM_PERI_FCM_QCHANNEL_CTL_REG_fcm_debug_clk_q_channel_en_END (4)
#define SOC_FCM_PERI_FCM_QCHANNEL_CTL_REG_fcm_debug_pwr_q_channel_qreqn_START (5)
#define SOC_FCM_PERI_FCM_QCHANNEL_CTL_REG_fcm_debug_pwr_q_channel_qreqn_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_sclk_q_channel_cfgcnt : 7;
        unsigned int reserved_0 : 1;
        unsigned int fcm_atclk_q_channel_cfgcnt : 7;
        unsigned int reserved_1 : 1;
        unsigned int fcm_pclk_q_channel_cfgcnt : 7;
        unsigned int reserved_2 : 1;
        unsigned int fcm_gicclk_q_channel_cfgcnt : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_FCM_PERI_FCM_QCHANNEL_CFGCNT_REG0_UNION;
#endif
#define SOC_FCM_PERI_FCM_QCHANNEL_CFGCNT_REG0_fcm_sclk_q_channel_cfgcnt_START (0)
#define SOC_FCM_PERI_FCM_QCHANNEL_CFGCNT_REG0_fcm_sclk_q_channel_cfgcnt_END (6)
#define SOC_FCM_PERI_FCM_QCHANNEL_CFGCNT_REG0_fcm_atclk_q_channel_cfgcnt_START (8)
#define SOC_FCM_PERI_FCM_QCHANNEL_CFGCNT_REG0_fcm_atclk_q_channel_cfgcnt_END (14)
#define SOC_FCM_PERI_FCM_QCHANNEL_CFGCNT_REG0_fcm_pclk_q_channel_cfgcnt_START (16)
#define SOC_FCM_PERI_FCM_QCHANNEL_CFGCNT_REG0_fcm_pclk_q_channel_cfgcnt_END (22)
#define SOC_FCM_PERI_FCM_QCHANNEL_CFGCNT_REG0_fcm_gicclk_q_channel_cfgcnt_START (24)
#define SOC_FCM_PERI_FCM_QCHANNEL_CFGCNT_REG0_fcm_gicclk_q_channel_cfgcnt_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_debug_clk_q_channel_cfgcnt : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_FCM_PERI_FCM_QCHANNEL_CFGCNT_REG1_UNION;
#endif
#define SOC_FCM_PERI_FCM_QCHANNEL_CFGCNT_REG1_fcm_debug_clk_q_channel_cfgcnt_START (0)
#define SOC_FCM_PERI_FCM_QCHANNEL_CFGCNT_REG1_fcm_debug_clk_q_channel_cfgcnt_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nirq_test : 8;
        unsigned int nfiq_test : 8;
        unsigned int reserved_0 : 12;
        unsigned int giccdisable : 1;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_FCM_PERI_FCM_GIC_TEST_CFG_REG_UNION;
#endif
#define SOC_FCM_PERI_FCM_GIC_TEST_CFG_REG_nirq_test_START (0)
#define SOC_FCM_PERI_FCM_GIC_TEST_CFG_REG_nirq_test_END (7)
#define SOC_FCM_PERI_FCM_GIC_TEST_CFG_REG_nfiq_test_START (8)
#define SOC_FCM_PERI_FCM_GIC_TEST_CFG_REG_nfiq_test_END (15)
#define SOC_FCM_PERI_FCM_GIC_TEST_CFG_REG_giccdisable_START (28)
#define SOC_FCM_PERI_FCM_GIC_TEST_CFG_REG_giccdisable_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fcm_dly_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_FCM_PERI_FCM_DLYCNT_CFG_REG_UNION;
#endif
#define SOC_FCM_PERI_FCM_DLYCNT_CFG_REG_fcm_dly_cnt_START (0)
#define SOC_FCM_PERI_FCM_DLYCNT_CFG_REG_fcm_dly_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blk_midr_value_big : 32;
    } reg;
} SOC_FCM_PERI_BLK_MIDR_VALUE_BIG_UNION;
#endif
#define SOC_FCM_PERI_BLK_MIDR_VALUE_BIG_blk_midr_value_big_START (0)
#define SOC_FCM_PERI_BLK_MIDR_VALUE_BIG_blk_midr_value_big_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int big_debug_part_num : 12;
        unsigned int big_pidr_version : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_FCM_PERI_BLK_DEBUG_VALUE_BIG_UNION;
#endif
#define SOC_FCM_PERI_BLK_DEBUG_VALUE_BIG_big_debug_part_num_START (0)
#define SOC_FCM_PERI_BLK_DEBUG_VALUE_BIG_big_debug_part_num_END (11)
#define SOC_FCM_PERI_BLK_DEBUG_VALUE_BIG_big_pidr_version_START (12)
#define SOC_FCM_PERI_BLK_DEBUG_VALUE_BIG_big_pidr_version_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blk_midr_value_mid : 32;
    } reg;
} SOC_FCM_PERI_BLK_MIDR_VALUE_MID_UNION;
#endif
#define SOC_FCM_PERI_BLK_MIDR_VALUE_MID_blk_midr_value_mid_START (0)
#define SOC_FCM_PERI_BLK_MIDR_VALUE_MID_blk_midr_value_mid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_debug_part_num : 12;
        unsigned int mid_pidr_version : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_FCM_PERI_BLK_DEBUG_VALUE_MID_UNION;
#endif
#define SOC_FCM_PERI_BLK_DEBUG_VALUE_MID_mid_debug_part_num_START (0)
#define SOC_FCM_PERI_BLK_DEBUG_VALUE_MID_mid_debug_part_num_END (11)
#define SOC_FCM_PERI_BLK_DEBUG_VALUE_MID_mid_pidr_version_START (12)
#define SOC_FCM_PERI_BLK_DEBUG_VALUE_MID_mid_pidr_version_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcrtr_mid_para_a : 32;
    } reg;
} SOC_FCM_PERI_PCRTR_MID_PARA_A_UNION;
#endif
#define SOC_FCM_PERI_PCRTR_MID_PARA_A_pcrtr_mid_para_a_START (0)
#define SOC_FCM_PERI_PCRTR_MID_PARA_A_pcrtr_mid_para_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcrtr_mid_para_b : 32;
    } reg;
} SOC_FCM_PERI_PCRTR_MID_PARA_B_UNION;
#endif
#define SOC_FCM_PERI_PCRTR_MID_PARA_B_pcrtr_mid_para_b_START (0)
#define SOC_FCM_PERI_PCRTR_MID_PARA_B_pcrtr_mid_para_b_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcrtr_mid_para_c : 32;
    } reg;
} SOC_FCM_PERI_PCRTR_MID_PARA_C_UNION;
#endif
#define SOC_FCM_PERI_PCRTR_MID_PARA_C_pcrtr_mid_para_c_START (0)
#define SOC_FCM_PERI_PCRTR_MID_PARA_C_pcrtr_mid_para_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcrtr_big_para_a : 32;
    } reg;
} SOC_FCM_PERI_PCRTR_BIG_PARA_A_UNION;
#endif
#define SOC_FCM_PERI_PCRTR_BIG_PARA_A_pcrtr_big_para_a_START (0)
#define SOC_FCM_PERI_PCRTR_BIG_PARA_A_pcrtr_big_para_a_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcrtr_big_para_b : 32;
    } reg;
} SOC_FCM_PERI_PCRTR_BIG_PARA_B_UNION;
#endif
#define SOC_FCM_PERI_PCRTR_BIG_PARA_B_pcrtr_big_para_b_START (0)
#define SOC_FCM_PERI_PCRTR_BIG_PARA_B_pcrtr_big_para_b_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcrtr_big_para_c : 32;
    } reg;
} SOC_FCM_PERI_PCRTR_BIG_PARA_C_UNION;
#endif
#define SOC_FCM_PERI_PCRTR_BIG_PARA_C_pcrtr_big_para_c_START (0)
#define SOC_FCM_PERI_PCRTR_BIG_PARA_C_pcrtr_big_para_c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cpu_load_cnt_threthod : 32;
    } reg;
} SOC_FCM_PERI_CPU_LOAD_CNT_THRETHOD_UNION;
#endif
#define SOC_FCM_PERI_CPU_LOAD_CNT_THRETHOD_cpu_load_cnt_threthod_START (0)
#define SOC_FCM_PERI_CPU_LOAD_CNT_THRETHOD_cpu_load_cnt_threthod_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mpmm_state7 : 2;
        unsigned int mpmm_state6 : 2;
        unsigned int mpmm_state5 : 2;
        unsigned int mpmm_state4 : 2;
        unsigned int ppm_ctl7 : 4;
        unsigned int ppm_ctl6 : 4;
        unsigned int ppm_ctl5 : 4;
        unsigned int ppm_ctl4 : 4;
        unsigned int reserved : 8;
    } reg;
} SOC_FCM_PERI_FCM_MPMM_STATECFG_UNION;
#endif
#define SOC_FCM_PERI_FCM_MPMM_STATECFG_mpmm_state7_START (0)
#define SOC_FCM_PERI_FCM_MPMM_STATECFG_mpmm_state7_END (1)
#define SOC_FCM_PERI_FCM_MPMM_STATECFG_mpmm_state6_START (2)
#define SOC_FCM_PERI_FCM_MPMM_STATECFG_mpmm_state6_END (3)
#define SOC_FCM_PERI_FCM_MPMM_STATECFG_mpmm_state5_START (4)
#define SOC_FCM_PERI_FCM_MPMM_STATECFG_mpmm_state5_END (5)
#define SOC_FCM_PERI_FCM_MPMM_STATECFG_mpmm_state4_START (6)
#define SOC_FCM_PERI_FCM_MPMM_STATECFG_mpmm_state4_END (7)
#define SOC_FCM_PERI_FCM_MPMM_STATECFG_ppm_ctl7_START (8)
#define SOC_FCM_PERI_FCM_MPMM_STATECFG_ppm_ctl7_END (11)
#define SOC_FCM_PERI_FCM_MPMM_STATECFG_ppm_ctl6_START (12)
#define SOC_FCM_PERI_FCM_MPMM_STATECFG_ppm_ctl6_END (15)
#define SOC_FCM_PERI_FCM_MPMM_STATECFG_ppm_ctl5_START (16)
#define SOC_FCM_PERI_FCM_MPMM_STATECFG_ppm_ctl5_END (19)
#define SOC_FCM_PERI_FCM_MPMM_STATECFG_ppm_ctl4_START (20)
#define SOC_FCM_PERI_FCM_MPMM_STATECFG_ppm_ctl4_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sc_excel_ctrl_m0 : 16;
        unsigned int sc_excel_ctrl_m1 : 16;
    } reg;
} SOC_FCM_PERI_SC_EXCEL_CTRL_UNION;
#endif
#define SOC_FCM_PERI_SC_EXCEL_CTRL_sc_excel_ctrl_m0_START (0)
#define SOC_FCM_PERI_SC_EXCEL_CTRL_sc_excel_ctrl_m0_END (15)
#define SOC_FCM_PERI_SC_EXCEL_CTRL_sc_excel_ctrl_m1_START (16)
#define SOC_FCM_PERI_SC_EXCEL_CTRL_sc_excel_ctrl_m1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int karma_2t1_bypass_enable : 1;
        unsigned int karma_2t1_bypass_enable_acp : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FCM_PERI_KARMA_2T1_CTL_UNION;
#endif
#define SOC_FCM_PERI_KARMA_2T1_CTL_karma_2t1_bypass_enable_START (0)
#define SOC_FCM_PERI_KARMA_2T1_CTL_karma_2t1_bypass_enable_END (0)
#define SOC_FCM_PERI_KARMA_2T1_CTL_karma_2t1_bypass_enable_acp_START (1)
#define SOC_FCM_PERI_KARMA_2T1_CTL_karma_2t1_bypass_enable_acp_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pcrtr_mid_para_vld : 1;
        unsigned int pcrtr_big_para_vld : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FCM_PERI_PCRTR_PARA_SAMPLE_UNION;
#endif
#define SOC_FCM_PERI_PCRTR_PARA_SAMPLE_pcrtr_mid_para_vld_START (0)
#define SOC_FCM_PERI_PCRTR_PARA_SAMPLE_pcrtr_mid_para_vld_END (0)
#define SOC_FCM_PERI_PCRTR_PARA_SAMPLE_pcrtr_big_para_vld_START (1)
#define SOC_FCM_PERI_PCRTR_PARA_SAMPLE_pcrtr_big_para_vld_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int atclk_qacceptn : 1;
        unsigned int atclk_qactive : 1;
        unsigned int atclk_qdeny : 1;
        unsigned int atclk_qreqn : 1;
        unsigned int gicclk_qacceptn : 1;
        unsigned int gicclk_qactive : 1;
        unsigned int gicclk_qdeny : 1;
        unsigned int gicclk_qreqn : 1;
        unsigned int pclk_qacceptn : 1;
        unsigned int pclk_qactive : 1;
        unsigned int pclk_qdeny : 1;
        unsigned int pclk_qreqn : 1;
        unsigned int sclk_qacceptn : 1;
        unsigned int sclk_qactive : 1;
        unsigned int sclk_qdeny : 1;
        unsigned int sclk_qreqn : 1;
        unsigned int pdbgclk_qacceptn : 1;
        unsigned int pdbgclk_qactive : 1;
        unsigned int pdbgtclk_qdeny : 1;
        unsigned int pdbgtclk_qreqn : 1;
        unsigned int pwr_qacceptn : 1;
        unsigned int pwr_qactive : 1;
        unsigned int pwr_qdeny : 1;
        unsigned int pwr_qreqn : 1;
        unsigned int awakeupm0 : 1;
        unsigned int awakeupm1 : 1;
        unsigned int awakeupmp : 1;
        unsigned int acp_valid_comb : 1;
        unsigned int clusterdbgpwrupreq : 1;
        unsigned int busy_shaper : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_FCM_PERI_FCM_LOCAL_STAT0_UNION;
#endif
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_atclk_qacceptn_START (0)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_atclk_qacceptn_END (0)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_atclk_qactive_START (1)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_atclk_qactive_END (1)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_atclk_qdeny_START (2)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_atclk_qdeny_END (2)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_atclk_qreqn_START (3)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_atclk_qreqn_END (3)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_gicclk_qacceptn_START (4)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_gicclk_qacceptn_END (4)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_gicclk_qactive_START (5)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_gicclk_qactive_END (5)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_gicclk_qdeny_START (6)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_gicclk_qdeny_END (6)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_gicclk_qreqn_START (7)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_gicclk_qreqn_END (7)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_pclk_qacceptn_START (8)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_pclk_qacceptn_END (8)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_pclk_qactive_START (9)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_pclk_qactive_END (9)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_pclk_qdeny_START (10)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_pclk_qdeny_END (10)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_pclk_qreqn_START (11)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_pclk_qreqn_END (11)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_sclk_qacceptn_START (12)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_sclk_qacceptn_END (12)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_sclk_qactive_START (13)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_sclk_qactive_END (13)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_sclk_qdeny_START (14)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_sclk_qdeny_END (14)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_sclk_qreqn_START (15)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_sclk_qreqn_END (15)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_pdbgclk_qacceptn_START (16)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_pdbgclk_qacceptn_END (16)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_pdbgclk_qactive_START (17)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_pdbgclk_qactive_END (17)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_pdbgtclk_qdeny_START (18)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_pdbgtclk_qdeny_END (18)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_pdbgtclk_qreqn_START (19)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_pdbgtclk_qreqn_END (19)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_pwr_qacceptn_START (20)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_pwr_qacceptn_END (20)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_pwr_qactive_START (21)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_pwr_qactive_END (21)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_pwr_qdeny_START (22)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_pwr_qdeny_END (22)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_pwr_qreqn_START (23)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_pwr_qreqn_END (23)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_awakeupm0_START (24)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_awakeupm0_END (24)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_awakeupm1_START (25)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_awakeupm1_END (25)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_awakeupmp_START (26)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_awakeupmp_END (26)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_acp_valid_comb_START (27)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_acp_valid_comb_END (27)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_clusterdbgpwrupreq_START (28)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_clusterdbgpwrupreq_END (28)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_busy_shaper_START (29)
#define SOC_FCM_PERI_FCM_LOCAL_STAT0_busy_shaper_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int standbywfi_pdc_core : 8;
        unsigned int standbywfi_vdm_core : 8;
        unsigned int standbywfe_core : 8;
        unsigned int standbywfi_pdc_fcm : 1;
        unsigned int standbywfi_vdm_fcm : 1;
        unsigned int standbywfe_fcm : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_FCM_PERI_FCM_LOCAL_STAT1_UNION;
#endif
#define SOC_FCM_PERI_FCM_LOCAL_STAT1_standbywfi_pdc_core_START (0)
#define SOC_FCM_PERI_FCM_LOCAL_STAT1_standbywfi_pdc_core_END (7)
#define SOC_FCM_PERI_FCM_LOCAL_STAT1_standbywfi_vdm_core_START (8)
#define SOC_FCM_PERI_FCM_LOCAL_STAT1_standbywfi_vdm_core_END (15)
#define SOC_FCM_PERI_FCM_LOCAL_STAT1_standbywfe_core_START (16)
#define SOC_FCM_PERI_FCM_LOCAL_STAT1_standbywfe_core_END (23)
#define SOC_FCM_PERI_FCM_LOCAL_STAT1_standbywfi_pdc_fcm_START (24)
#define SOC_FCM_PERI_FCM_LOCAL_STAT1_standbywfi_pdc_fcm_END (24)
#define SOC_FCM_PERI_FCM_LOCAL_STAT1_standbywfi_vdm_fcm_START (25)
#define SOC_FCM_PERI_FCM_LOCAL_STAT1_standbywfi_vdm_fcm_END (25)
#define SOC_FCM_PERI_FCM_LOCAL_STAT1_standbywfe_fcm_START (26)
#define SOC_FCM_PERI_FCM_LOCAL_STAT1_standbywfe_fcm_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coreinstrrun : 8;
        unsigned int coreinstrret : 8;
        unsigned int pmusnapshotack : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_FCM_PERI_FCM_LOCAL_STAT11_UNION;
#endif
#define SOC_FCM_PERI_FCM_LOCAL_STAT11_coreinstrrun_START (0)
#define SOC_FCM_PERI_FCM_LOCAL_STAT11_coreinstrrun_END (7)
#define SOC_FCM_PERI_FCM_LOCAL_STAT11_coreinstrret_START (8)
#define SOC_FCM_PERI_FCM_LOCAL_STAT11_coreinstrret_END (15)
#define SOC_FCM_PERI_FCM_LOCAL_STAT11_pmusnapshotack_START (16)
#define SOC_FCM_PERI_FCM_LOCAL_STAT11_pmusnapshotack_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 31;
    } reg;
} SOC_FCM_PERI_FCM_LOCAL_STAT21_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbgack : 8;
        unsigned int dbgpwrupreq : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_FCM_PERI_FCM_LOCAL_STAT22_UNION;
#endif
#define SOC_FCM_PERI_FCM_LOCAL_STAT22_dbgack_START (0)
#define SOC_FCM_PERI_FCM_LOCAL_STAT22_dbgack_END (7)
#define SOC_FCM_PERI_FCM_LOCAL_STAT22_dbgpwrupreq_START (8)
#define SOC_FCM_PERI_FCM_LOCAL_STAT22_dbgpwrupreq_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_aps_dpm : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_FCM_PERI_FCM_LOCAL_STAT23_UNION;
#endif
#define SOC_FCM_PERI_FCM_LOCAL_STAT23_intr_aps_dpm_START (0)
#define SOC_FCM_PERI_FCM_LOCAL_STAT23_intr_aps_dpm_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int snoop_cnt_m0 : 6;
        unsigned int reserved_0 : 2;
        unsigned int snoop_cnt_m1 : 6;
        unsigned int reserved_1 : 2;
        unsigned int ar_cnt_acp : 6;
        unsigned int reserved_2 : 2;
        unsigned int aw_cnt_acp : 6;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_FCM_PERI_FCM_LOCAL_STAT24_UNION;
#endif
#define SOC_FCM_PERI_FCM_LOCAL_STAT24_snoop_cnt_m0_START (0)
#define SOC_FCM_PERI_FCM_LOCAL_STAT24_snoop_cnt_m0_END (5)
#define SOC_FCM_PERI_FCM_LOCAL_STAT24_snoop_cnt_m1_START (8)
#define SOC_FCM_PERI_FCM_LOCAL_STAT24_snoop_cnt_m1_END (13)
#define SOC_FCM_PERI_FCM_LOCAL_STAT24_ar_cnt_acp_START (16)
#define SOC_FCM_PERI_FCM_LOCAL_STAT24_ar_cnt_acp_END (21)
#define SOC_FCM_PERI_FCM_LOCAL_STAT24_aw_cnt_acp_START (24)
#define SOC_FCM_PERI_FCM_LOCAL_STAT24_aw_cnt_acp_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w_cnt_acp : 6;
        unsigned int reserved_0: 2;
        unsigned int b_cnt_acp : 6;
        unsigned int reserved_1: 2;
        unsigned int r_cnt_acp : 6;
        unsigned int reserved_2: 10;
    } reg;
} SOC_FCM_PERI_FCM_LOCAL_STAT25_UNION;
#endif
#define SOC_FCM_PERI_FCM_LOCAL_STAT25_w_cnt_acp_START (0)
#define SOC_FCM_PERI_FCM_LOCAL_STAT25_w_cnt_acp_END (5)
#define SOC_FCM_PERI_FCM_LOCAL_STAT25_b_cnt_acp_START (8)
#define SOC_FCM_PERI_FCM_LOCAL_STAT25_b_cnt_acp_END (13)
#define SOC_FCM_PERI_FCM_LOCAL_STAT25_r_cnt_acp_START (16)
#define SOC_FCM_PERI_FCM_LOCAL_STAT25_r_cnt_acp_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int acp_arvalid : 1;
        unsigned int acp_arready : 1;
        unsigned int acp_rvalid : 1;
        unsigned int acp_rready : 1;
        unsigned int acp_awvalid : 1;
        unsigned int acp_awready : 1;
        unsigned int acp_wvalid : 1;
        unsigned int acp_wready : 1;
        unsigned int acp_wlast : 1;
        unsigned int acp_bvalid : 1;
        unsigned int acp_bready : 1;
        unsigned int acp_rlast : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_FCM_PERI_FCM_LOCAL_STAT26_UNION;
#endif
#define SOC_FCM_PERI_FCM_LOCAL_STAT26_acp_arvalid_START (0)
#define SOC_FCM_PERI_FCM_LOCAL_STAT26_acp_arvalid_END (0)
#define SOC_FCM_PERI_FCM_LOCAL_STAT26_acp_arready_START (1)
#define SOC_FCM_PERI_FCM_LOCAL_STAT26_acp_arready_END (1)
#define SOC_FCM_PERI_FCM_LOCAL_STAT26_acp_rvalid_START (2)
#define SOC_FCM_PERI_FCM_LOCAL_STAT26_acp_rvalid_END (2)
#define SOC_FCM_PERI_FCM_LOCAL_STAT26_acp_rready_START (3)
#define SOC_FCM_PERI_FCM_LOCAL_STAT26_acp_rready_END (3)
#define SOC_FCM_PERI_FCM_LOCAL_STAT26_acp_awvalid_START (4)
#define SOC_FCM_PERI_FCM_LOCAL_STAT26_acp_awvalid_END (4)
#define SOC_FCM_PERI_FCM_LOCAL_STAT26_acp_awready_START (5)
#define SOC_FCM_PERI_FCM_LOCAL_STAT26_acp_awready_END (5)
#define SOC_FCM_PERI_FCM_LOCAL_STAT26_acp_wvalid_START (6)
#define SOC_FCM_PERI_FCM_LOCAL_STAT26_acp_wvalid_END (6)
#define SOC_FCM_PERI_FCM_LOCAL_STAT26_acp_wready_START (7)
#define SOC_FCM_PERI_FCM_LOCAL_STAT26_acp_wready_END (7)
#define SOC_FCM_PERI_FCM_LOCAL_STAT26_acp_wlast_START (8)
#define SOC_FCM_PERI_FCM_LOCAL_STAT26_acp_wlast_END (8)
#define SOC_FCM_PERI_FCM_LOCAL_STAT26_acp_bvalid_START (9)
#define SOC_FCM_PERI_FCM_LOCAL_STAT26_acp_bvalid_END (9)
#define SOC_FCM_PERI_FCM_LOCAL_STAT26_acp_bready_START (10)
#define SOC_FCM_PERI_FCM_LOCAL_STAT26_acp_bready_END (10)
#define SOC_FCM_PERI_FCM_LOCAL_STAT26_acp_rlast_START (11)
#define SOC_FCM_PERI_FCM_LOCAL_STAT26_acp_rlast_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_sdo : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FCM_PERI_FCM_LOCAL_STAT31_UNION;
#endif
#define SOC_FCM_PERI_FCM_LOCAL_STAT31_ip_sdo_START (0)
#define SOC_FCM_PERI_FCM_LOCAL_STAT31_ip_sdo_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int m0_aw_cnt : 4;
        unsigned int m0_aw_fifo_empty : 1;
        unsigned int m0_aw_fifo_full : 1;
        unsigned int m0_ar_cnt : 5;
        unsigned int m0_ar_fifo_empty : 1;
        unsigned int m0_ar_fifo_full : 1;
        unsigned int m1_aw_cnt : 4;
        unsigned int m1_aw_fifo_empty : 1;
        unsigned int m1_aw_fifo_full : 1;
        unsigned int m1_ar_cnt : 5;
        unsigned int m1_ar_fifo_empty : 1;
        unsigned int m1_ar_fifo_full : 1;
        unsigned int m0_dfx_bready_bp_awarb : 1;
        unsigned int m0_dfx_ready_bp_ararb : 1;
        unsigned int m0_dfx_acready_bp_arfifo : 1;
        unsigned int m1_dfx_bready_bp_awarb : 1;
        unsigned int m1_dfx_ready_bp_ararb : 1;
        unsigned int m1_dfx_acready_bp_arfifo : 1;
    } reg;
} SOC_FCM_PERI_FCM_LOCAL_STAT32_UNION;
#endif
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m0_aw_cnt_START (0)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m0_aw_cnt_END (3)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m0_aw_fifo_empty_START (4)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m0_aw_fifo_empty_END (4)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m0_aw_fifo_full_START (5)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m0_aw_fifo_full_END (5)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m0_ar_cnt_START (6)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m0_ar_cnt_END (10)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m0_ar_fifo_empty_START (11)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m0_ar_fifo_empty_END (11)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m0_ar_fifo_full_START (12)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m0_ar_fifo_full_END (12)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m1_aw_cnt_START (13)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m1_aw_cnt_END (16)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m1_aw_fifo_empty_START (17)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m1_aw_fifo_empty_END (17)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m1_aw_fifo_full_START (18)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m1_aw_fifo_full_END (18)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m1_ar_cnt_START (19)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m1_ar_cnt_END (23)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m1_ar_fifo_empty_START (24)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m1_ar_fifo_empty_END (24)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m1_ar_fifo_full_START (25)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m1_ar_fifo_full_END (25)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m0_dfx_bready_bp_awarb_START (26)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m0_dfx_bready_bp_awarb_END (26)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m0_dfx_ready_bp_ararb_START (27)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m0_dfx_ready_bp_ararb_END (27)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m0_dfx_acready_bp_arfifo_START (28)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m0_dfx_acready_bp_arfifo_END (28)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m1_dfx_bready_bp_awarb_START (29)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m1_dfx_bready_bp_awarb_END (29)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m1_dfx_ready_bp_ararb_START (30)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m1_dfx_ready_bp_ararb_END (30)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m1_dfx_acready_bp_arfifo_START (31)
#define SOC_FCM_PERI_FCM_LOCAL_STAT32_m1_dfx_acready_bp_arfifo_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
