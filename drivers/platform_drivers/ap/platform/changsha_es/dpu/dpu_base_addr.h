#ifndef DPU_BASE_ADDR_H
#define DPU_BASE_ADDR_H 
#define ATF_SUB_RESERVED_BL31_SHARE_MEM_PHYMEM_BASE 0x10941000
#define ATF_SUB_RESERVED_BL31_SHARE_MEM_PHYMEM_SIZE (0x10000)
#ifndef __SOC_H_FOR_ASM__
#define SOC_SCTRL_SCBAKDATA0_ADDR(base) ((base) + (0x40CUL))
#define SOC_SCTRL_SCBAKDATA4_ADDR(base) ((base) + (0x41CUL))
#define SOC_SCTRL_SCBAKDATA11_ADDR(base) ((base) + (0x438UL))
#define SOC_CRGPERIPH_PERRSTEN0_ADDR(base) ((base) + (0x060UL))
#define SOC_CRGPERIPH_PERRSTDIS0_ADDR(base) ((base) + (0x064UL))
#define SOC_CRGPERIPH_PERRSTSTAT0_ADDR(base) ((base) + (0x068UL))
#define SOC_CRGPERIPH_PEREN12_ADDR(base) ((base) + (0x470UL))
#define SOC_CRGPERIPH_PERDIS12_ADDR(base) ((base) + (0x474UL))
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_ADDR(base) ((base) + (0x668UL))
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE0_ADDR(base) ((base) + (0x950UL))
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE1_ADDR(base) ((base) + (0x954UL))
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ADDR(base) ((base) + (0xA84UL))
#define SOC_CRGPERIPH_PPLL2_BCTRL1_ADDR(base) ((base) + (0xA88UL))
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_ADDR(base) ((base) + (0xC44UL))
#define SOC_CRGPERIPH_PLL_FSM_STAT0_ADDR(base) ((base) + (0xC48UL))
#define SOC_CRGPERIPH_PLL_FSM_STAT1_ADDR(base) ((base) + (0xC4CUL))
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ADDR(base) ((base) + (0xC50UL))
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL1_ADDR(base) ((base) + (0xC60UL))
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL2_ADDR(base) ((base) + (0xC6CUL))
#define SOC_MEDIA1_CRG_PERCLKEN1_ADDR(base) ((base) + (0x018UL))
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ADDR(base) ((base) + (0x038UL))
#define SOC_MEDIA1_CRG_CLKDIV0_ADDR(base) ((base) + (0x060UL))
#define SOC_MEDIA1_CRG_CLKDIV2_ADDR(base) ((base) + (0x068UL))
#define SOC_MEDIA1_CRG_DSS_DVFS_ADDR(base) ((base) + (0x100UL))
#define SOC_MEDIA1_CRG_DSS_DVFS_AUTODIV_ADDR(base) ((base) + (0x104UL))
#define SOC_PMCTRL_PERI_CTRL5_ADDR(base) ((base) + (0x354UL))
#else
#define SOC_SCTRL_SCBAKDATA0_ADDR(base) ((base) + (0x40C))
#define SOC_SCTRL_SCBAKDATA4_ADDR(base) ((base) + (0x41C))
#define SOC_SCTRL_SCBAKDATA11_ADDR(base) ((base) + (0x438))
#define SOC_CRGPERIPH_PERRSTEN0_ADDR(base) ((base) + (0x060))
#define SOC_CRGPERIPH_PERRSTDIS0_ADDR(base) ((base) + (0x064))
#define SOC_CRGPERIPH_PERRSTSTAT0_ADDR(base) ((base) + (0x068))
#define SOC_CRGPERIPH_PEREN12_ADDR(base) ((base) + (0x470))
#define SOC_CRGPERIPH_PERDIS12_ADDR(base) ((base) + (0x474))
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_ADDR(base) ((base) + (0x668))
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE0_ADDR(base) ((base) + (0x950))
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE1_ADDR(base) ((base) + (0x954))
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ADDR(base) ((base) + (0xA84))
#define SOC_CRGPERIPH_PPLL2_BCTRL1_ADDR(base) ((base) + (0xA88))
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_ADDR(base) ((base) + (0xC44))
#define SOC_CRGPERIPH_PLL_FSM_STAT0_ADDR(base) ((base) + (0xC48))
#define SOC_CRGPERIPH_PLL_FSM_STAT1_ADDR(base) ((base) + (0xC4C))
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ADDR(base) ((base) + (0xC50))
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL1_ADDR(base) ((base) + (0xC60))
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL2_ADDR(base) ((base) + (0xC6C))
#define SOC_MEDIA1_CRG_PERCLKEN1_ADDR(base) ((base) + (0x018))
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ADDR(base) ((base) + (0x038))
#define SOC_MEDIA1_CRG_CLKDIV0_ADDR(base) ((base) + (0x060))
#define SOC_MEDIA1_CRG_CLKDIV2_ADDR(base) ((base) + (0x068))
#define SOC_MEDIA1_CRG_DSS_DVFS_ADDR(base) ((base) + (0x100))
#define SOC_MEDIA1_CRG_DSS_DVFS_AUTODIV_ADDR(base) ((base) + (0x104))
#define SOC_PMCTRL_PERI_CTRL5_ADDR(base) ((base) + (0x354))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA0_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA0_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA0_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA4_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA4_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA4_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bakdata : 32;
    } reg;
} SOC_SCTRL_SCBAKDATA11_UNION;
#endif
#define SOC_SCTRL_SCBAKDATA11_bakdata_START (0)
#define SOC_SCTRL_SCBAKDATA11_bakdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_dpctrl_pixel : 1;
        unsigned int ip_rst_time_stamp : 1;
        unsigned int ip_rst_onewire : 1;
        unsigned int ip_rst_pasensor_peri : 1;
        unsigned int ip_rst_resource_lock : 1;
        unsigned int ip_rst_sdcu : 1;
        unsigned int ip_rst_onewire_ref : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_mdmperi_bus : 1;
        unsigned int ip_rst_lat_mon_qice : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_lat_mon_npu : 1;
        unsigned int reserved_3 : 1;
        unsigned int ip_rst_i2c7 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int ip_rst_perf_stat : 1;
        unsigned int ip_rst_i2c6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int ip_rst_noc_mdm_cfg : 1;
        unsigned int ip_rst_power_stat : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int ip_rst_ufs_dfa_cpu : 1;
        unsigned int ip_rst_ufs_dfa_sys : 1;
        unsigned int reserved_13 : 1;
        unsigned int ip_rst_bist_sync : 1;
    } reg;
} SOC_CRGPERIPH_PERRSTEN0_UNION;
#endif
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_dpctrl_pixel_START (0)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_dpctrl_pixel_END (0)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_time_stamp_START (1)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_time_stamp_END (1)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_onewire_START (2)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_onewire_END (2)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_pasensor_peri_START (3)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_pasensor_peri_END (3)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_resource_lock_START (4)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_resource_lock_END (4)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_sdcu_START (5)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_sdcu_END (5)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_onewire_ref_START (6)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_onewire_ref_END (6)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_mdmperi_bus_START (8)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_mdmperi_bus_END (8)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_lat_mon_qice_START (9)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_lat_mon_qice_END (9)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_lat_mon_npu_START (12)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_lat_mon_npu_END (12)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_i2c7_START (14)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_i2c7_END (14)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_perf_stat_START (18)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_perf_stat_END (18)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_i2c6_START (19)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_i2c6_END (19)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_noc_mdm_cfg_START (23)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_noc_mdm_cfg_END (23)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_power_stat_START (24)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_power_stat_END (24)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_ufs_dfa_cpu_START (28)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_ufs_dfa_cpu_END (28)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_ufs_dfa_sys_START (29)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_ufs_dfa_sys_END (29)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_bist_sync_START (31)
#define SOC_CRGPERIPH_PERRSTEN0_ip_rst_bist_sync_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_dpctrl_pixel : 1;
        unsigned int ip_rst_time_stamp : 1;
        unsigned int ip_rst_onewire : 1;
        unsigned int ip_rst_pasensor_peri : 1;
        unsigned int ip_rst_resource_lock : 1;
        unsigned int ip_rst_sdcu : 1;
        unsigned int ip_rst_onewire_ref : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_mdmperi_bus : 1;
        unsigned int ip_rst_lat_mon_qice : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_lat_mon_npu : 1;
        unsigned int reserved_3 : 1;
        unsigned int ip_rst_i2c7 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int ip_rst_perf_stat : 1;
        unsigned int ip_rst_i2c6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int ip_rst_noc_mdm_cfg : 1;
        unsigned int ip_rst_power_stat : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int ip_rst_ufs_dfa_cpu : 1;
        unsigned int ip_rst_ufs_dfa_sys : 1;
        unsigned int reserved_13 : 1;
        unsigned int ip_rst_bist_sync : 1;
    } reg;
} SOC_CRGPERIPH_PERRSTDIS0_UNION;
#endif
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_dpctrl_pixel_START (0)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_dpctrl_pixel_END (0)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_time_stamp_START (1)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_time_stamp_END (1)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_onewire_START (2)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_onewire_END (2)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_pasensor_peri_START (3)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_pasensor_peri_END (3)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_resource_lock_START (4)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_resource_lock_END (4)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_sdcu_START (5)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_sdcu_END (5)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_onewire_ref_START (6)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_onewire_ref_END (6)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_mdmperi_bus_START (8)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_mdmperi_bus_END (8)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_lat_mon_qice_START (9)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_lat_mon_qice_END (9)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_lat_mon_npu_START (12)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_lat_mon_npu_END (12)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_i2c7_START (14)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_i2c7_END (14)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_perf_stat_START (18)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_perf_stat_END (18)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_i2c6_START (19)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_i2c6_END (19)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_noc_mdm_cfg_START (23)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_noc_mdm_cfg_END (23)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_power_stat_START (24)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_power_stat_END (24)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_ufs_dfa_cpu_START (28)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_ufs_dfa_cpu_END (28)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_ufs_dfa_sys_START (29)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_ufs_dfa_sys_END (29)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_bist_sync_START (31)
#define SOC_CRGPERIPH_PERRSTDIS0_ip_rst_bist_sync_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_dpctrl_pixel : 1;
        unsigned int ip_rst_time_stamp : 1;
        unsigned int ip_rst_onewire : 1;
        unsigned int ip_rst_pasensor_peri : 1;
        unsigned int ip_rst_resource_lock : 1;
        unsigned int ip_rst_sdcu : 1;
        unsigned int ip_rst_onewire_ref : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_rst_mdmperi_bus : 1;
        unsigned int ip_rst_lat_mon_qice : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_lat_mon_npu : 1;
        unsigned int reserved_3 : 1;
        unsigned int ip_rst_i2c7 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int ip_rst_perf_stat : 1;
        unsigned int ip_rst_i2c6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int ip_rst_noc_mdm_cfg : 1;
        unsigned int ip_rst_power_stat : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int ip_rst_ufs_dfa_cpu : 1;
        unsigned int ip_rst_ufs_dfa_sys : 1;
        unsigned int reserved_13 : 1;
        unsigned int ip_rst_bist_sync : 1;
    } reg;
} SOC_CRGPERIPH_PERRSTSTAT0_UNION;
#endif
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_dpctrl_pixel_START (0)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_dpctrl_pixel_END (0)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_time_stamp_START (1)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_time_stamp_END (1)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_onewire_START (2)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_onewire_END (2)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_pasensor_peri_START (3)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_pasensor_peri_END (3)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_resource_lock_START (4)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_resource_lock_END (4)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_sdcu_START (5)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_sdcu_END (5)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_onewire_ref_START (6)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_onewire_ref_END (6)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_mdmperi_bus_START (8)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_mdmperi_bus_END (8)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_lat_mon_qice_START (9)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_lat_mon_qice_END (9)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_lat_mon_npu_START (12)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_lat_mon_npu_END (12)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_i2c7_START (14)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_i2c7_END (14)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_perf_stat_START (18)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_perf_stat_END (18)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_i2c6_START (19)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_i2c6_END (19)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_noc_mdm_cfg_START (23)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_noc_mdm_cfg_END (23)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_power_stat_START (24)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_power_stat_END (24)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_ufs_dfa_cpu_START (28)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_ufs_dfa_cpu_END (28)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_ufs_dfa_sys_START (29)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_ufs_dfa_sys_END (29)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_bist_sync_START (31)
#define SOC_CRGPERIPH_PERRSTSTAT0_ip_rst_bist_sync_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_i3c4 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_pclk_atgs_sys : 1;
        unsigned int gt_clk_modem_top : 1;
        unsigned int gt_clk_mdm_drx2dbg : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_clk_intr_hub : 1;
        unsigned int gt_clk_cpu_pctrl : 1;
        unsigned int gt_clk_npu_pctrl : 1;
        unsigned int gt_clk_media2_pctrl : 1;
        unsigned int gt_clk_media1_pctrl : 1;
        unsigned int gt_clk_hsdt0_pcmp_xctrl : 1;
        unsigned int gt_clk_hsdt1_pcmp_xctrl : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int gt_clk_dpctrl_16m : 1;
        unsigned int gt_clk_dpctrl_pixel : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 8;
    } reg;
} SOC_CRGPERIPH_PEREN12_UNION;
#endif
#define SOC_CRGPERIPH_PEREN12_gt_clk_i3c4_START (0)
#define SOC_CRGPERIPH_PEREN12_gt_clk_i3c4_END (0)
#define SOC_CRGPERIPH_PEREN12_gt_pclk_atgs_sys_START (3)
#define SOC_CRGPERIPH_PEREN12_gt_pclk_atgs_sys_END (3)
#define SOC_CRGPERIPH_PEREN12_gt_clk_modem_top_START (4)
#define SOC_CRGPERIPH_PEREN12_gt_clk_modem_top_END (4)
#define SOC_CRGPERIPH_PEREN12_gt_clk_mdm_drx2dbg_START (5)
#define SOC_CRGPERIPH_PEREN12_gt_clk_mdm_drx2dbg_END (5)
#define SOC_CRGPERIPH_PEREN12_gt_clk_intr_hub_START (8)
#define SOC_CRGPERIPH_PEREN12_gt_clk_intr_hub_END (8)
#define SOC_CRGPERIPH_PEREN12_gt_clk_cpu_pctrl_START (9)
#define SOC_CRGPERIPH_PEREN12_gt_clk_cpu_pctrl_END (9)
#define SOC_CRGPERIPH_PEREN12_gt_clk_npu_pctrl_START (10)
#define SOC_CRGPERIPH_PEREN12_gt_clk_npu_pctrl_END (10)
#define SOC_CRGPERIPH_PEREN12_gt_clk_media2_pctrl_START (11)
#define SOC_CRGPERIPH_PEREN12_gt_clk_media2_pctrl_END (11)
#define SOC_CRGPERIPH_PEREN12_gt_clk_media1_pctrl_START (12)
#define SOC_CRGPERIPH_PEREN12_gt_clk_media1_pctrl_END (12)
#define SOC_CRGPERIPH_PEREN12_gt_clk_hsdt0_pcmp_xctrl_START (13)
#define SOC_CRGPERIPH_PEREN12_gt_clk_hsdt0_pcmp_xctrl_END (13)
#define SOC_CRGPERIPH_PEREN12_gt_clk_hsdt1_pcmp_xctrl_START (14)
#define SOC_CRGPERIPH_PEREN12_gt_clk_hsdt1_pcmp_xctrl_END (14)
#define SOC_CRGPERIPH_PEREN12_gt_clk_dpctrl_16m_START (21)
#define SOC_CRGPERIPH_PEREN12_gt_clk_dpctrl_16m_END (21)
#define SOC_CRGPERIPH_PEREN12_gt_clk_dpctrl_pixel_START (22)
#define SOC_CRGPERIPH_PEREN12_gt_clk_dpctrl_pixel_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_i3c4 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_pclk_atgs_sys : 1;
        unsigned int gt_clk_modem_top : 1;
        unsigned int gt_clk_mdm_drx2dbg : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_clk_intr_hub : 1;
        unsigned int gt_clk_cpu_pctrl : 1;
        unsigned int gt_clk_npu_pctrl : 1;
        unsigned int gt_clk_media2_pctrl : 1;
        unsigned int gt_clk_media1_pctrl : 1;
        unsigned int gt_clk_hsdt0_pcmp_xctrl : 1;
        unsigned int gt_clk_hsdt1_pcmp_xctrl : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int gt_clk_dpctrl_16m : 1;
        unsigned int gt_clk_dpctrl_pixel : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 8;
    } reg;
} SOC_CRGPERIPH_PERDIS12_UNION;
#endif
#define SOC_CRGPERIPH_PERDIS12_gt_clk_i3c4_START (0)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_i3c4_END (0)
#define SOC_CRGPERIPH_PERDIS12_gt_pclk_atgs_sys_START (3)
#define SOC_CRGPERIPH_PERDIS12_gt_pclk_atgs_sys_END (3)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_modem_top_START (4)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_modem_top_END (4)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_mdm_drx2dbg_START (5)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_mdm_drx2dbg_END (5)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_intr_hub_START (8)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_intr_hub_END (8)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_cpu_pctrl_START (9)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_cpu_pctrl_END (9)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_npu_pctrl_START (10)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_npu_pctrl_END (10)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_media2_pctrl_START (11)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_media2_pctrl_END (11)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_media1_pctrl_START (12)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_media1_pctrl_END (12)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_hsdt0_pcmp_xctrl_START (13)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_hsdt0_pcmp_xctrl_END (13)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_hsdt1_pcmp_xctrl_START (14)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_hsdt1_pcmp_xctrl_END (14)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_dpctrl_16m_START (21)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_dpctrl_16m_END (21)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_dpctrl_pixel_START (22)
#define SOC_CRGPERIPH_PERDIS12_gt_clk_dpctrl_pixel_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hw_dss_dvfs_pll_gt0 : 1;
        unsigned int hw_dss_dvfs_pll_gt1 : 1;
        unsigned int hw_dss_dvfs_pll_gt2 : 1;
        unsigned int hw_dss_dvfs_pll_gt3 : 1;
        unsigned int hw_dss_dvfs_pll_en0 : 1;
        unsigned int reserved_0 : 1;
        unsigned int hw_dss_dvfs_pll_en2 : 1;
        unsigned int hw_dss_dvfs_pll_en3 : 1;
        unsigned int hw_dss_dvfs_pll_lock0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int hw_dss_dvfs_pll_lock2 : 1;
        unsigned int hw_dss_dvfs_pll_lock3 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 16;
    } reg;
} SOC_CRGPERIPH_HW_DSS_DVFS_STAT_UNION;
#endif
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_gt0_START (0)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_gt0_END (0)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_gt1_START (1)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_gt1_END (1)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_gt2_START (2)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_gt2_END (2)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_gt3_START (3)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_gt3_END (3)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_en0_START (4)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_en0_END (4)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_en2_START (6)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_en2_END (6)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_en3_START (7)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_en3_END (7)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_lock0_START (8)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_lock0_END (8)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_lock2_START (10)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_lock2_END (10)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_lock3_START (11)
#define SOC_CRGPERIPH_HW_DSS_DVFS_STAT_hw_dss_dvfs_pll_lock3_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ppll1_en_fsm_vote : 5;
        unsigned int ppll2_en_fsm_vote : 5;
        unsigned int ppll3_en_fsm_vote : 5;
        unsigned int reserved : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PLL_FSM_NS_VOTE0_UNION;
#endif
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE0_ppll1_en_fsm_vote_START (0)
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE0_ppll1_en_fsm_vote_END (4)
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE0_ppll2_en_fsm_vote_START (5)
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE0_ppll2_en_fsm_vote_END (9)
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE0_ppll3_en_fsm_vote_START (10)
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE0_ppll3_en_fsm_vote_END (14)
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE0_bitmasken_START (16)
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ppll7_en_fsm_vote : 5;
        unsigned int ppll2_b_en_fsm_vote : 5;
        unsigned int ppll6_en_fsm_vote : 5;
        unsigned int reserved : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PLL_FSM_NS_VOTE1_UNION;
#endif
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE1_ppll7_en_fsm_vote_START (0)
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE1_ppll7_en_fsm_vote_END (4)
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE1_ppll2_b_en_fsm_vote_START (5)
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE1_ppll2_b_en_fsm_vote_END (9)
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE1_ppll6_en_fsm_vote_START (10)
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE1_ppll6_en_fsm_vote_END (14)
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE1_bitmasken_START (16)
#define SOC_CRGPERIPH_PLL_FSM_NS_VOTE1_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ppll2_b_en : 1;
        unsigned int ppll2_b_bp : 1;
        unsigned int ppll2_b_refdiv : 6;
        unsigned int ppll2_b_fbdiv : 12;
        unsigned int ppll2_b_postdiv1 : 3;
        unsigned int ppll2_b_postdiv2 : 3;
        unsigned int ppll2_b_lock : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_CRGPERIPH_PPLL2_BCTRL0_UNION;
#endif
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ppll2_b_en_START (0)
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ppll2_b_en_END (0)
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ppll2_b_bp_START (1)
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ppll2_b_bp_END (1)
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ppll2_b_refdiv_START (2)
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ppll2_b_refdiv_END (7)
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ppll2_b_fbdiv_START (8)
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ppll2_b_fbdiv_END (19)
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ppll2_b_postdiv1_START (20)
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ppll2_b_postdiv1_END (22)
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ppll2_b_postdiv2_START (23)
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ppll2_b_postdiv2_END (25)
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ppll2_b_lock_START (26)
#define SOC_CRGPERIPH_PPLL2_BCTRL0_ppll2_b_lock_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ppll2_b_fracdiv : 24;
        unsigned int ppll2_b_int_mod : 1;
        unsigned int ppll2_b_cfg_vld : 1;
        unsigned int gt_clk_ppll2_b : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_CRGPERIPH_PPLL2_BCTRL1_UNION;
#endif
#define SOC_CRGPERIPH_PPLL2_BCTRL1_ppll2_b_fracdiv_START (0)
#define SOC_CRGPERIPH_PPLL2_BCTRL1_ppll2_b_fracdiv_END (23)
#define SOC_CRGPERIPH_PPLL2_BCTRL1_ppll2_b_int_mod_START (24)
#define SOC_CRGPERIPH_PPLL2_BCTRL1_ppll2_b_int_mod_END (24)
#define SOC_CRGPERIPH_PPLL2_BCTRL1_ppll2_b_cfg_vld_START (25)
#define SOC_CRGPERIPH_PPLL2_BCTRL1_ppll2_b_cfg_vld_END (25)
#define SOC_CRGPERIPH_PPLL2_BCTRL1_gt_clk_ppll2_b_START (26)
#define SOC_CRGPERIPH_PPLL2_BCTRL1_gt_clk_ppll2_b_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pll_lock_dbc_en : 1;
        unsigned int pll_fsm_intr_en : 1;
        unsigned int pll_wait_en : 1;
        unsigned int pll_timeout_en : 1;
        unsigned int pll_intr_lmt : 3;
        unsigned int pll_wait_lmt : 8;
        unsigned int pll_timeout_lmt : 8;
        unsigned int reserved : 9;
    } reg;
} SOC_CRGPERIPH_PLL_FSM_CTRL1_UNION;
#endif
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_pll_lock_dbc_en_START (0)
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_pll_lock_dbc_en_END (0)
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_pll_fsm_intr_en_START (1)
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_pll_fsm_intr_en_END (1)
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_pll_wait_en_START (2)
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_pll_wait_en_END (2)
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_pll_timeout_en_START (3)
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_pll_timeout_en_END (3)
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_pll_intr_lmt_START (4)
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_pll_intr_lmt_END (6)
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_pll_wait_lmt_START (7)
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_pll_wait_lmt_END (14)
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_pll_timeout_lmt_START (15)
#define SOC_CRGPERIPH_PLL_FSM_CTRL1_pll_timeout_lmt_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pll1_intr_cnt : 3;
        unsigned int pll2_intr_cnt : 3;
        unsigned int pll2_b_intr_cnt : 3;
        unsigned int pll3_intr_cnt : 3;
        unsigned int pll7_intr_cnt : 3;
        unsigned int pll6_intr_cnt : 3;
        unsigned int reserved : 5;
        unsigned int pll6_fsm_intr : 1;
        unsigned int pll1_fsm_intr : 1;
        unsigned int pll2_fsm_intr : 1;
        unsigned int ppll2_b_fsm_intr : 1;
        unsigned int pll3_fsm_intr : 1;
        unsigned int pll7_fsm_intr : 1;
        unsigned int aupll_fsm_intr : 1;
        unsigned int pll5_fsm_intr : 1;
        unsigned int intr_pll_fsm : 1;
    } reg;
} SOC_CRGPERIPH_PLL_FSM_STAT0_UNION;
#endif
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll1_intr_cnt_START (0)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll1_intr_cnt_END (2)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll2_intr_cnt_START (3)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll2_intr_cnt_END (5)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll2_b_intr_cnt_START (6)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll2_b_intr_cnt_END (8)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll3_intr_cnt_START (9)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll3_intr_cnt_END (11)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll7_intr_cnt_START (12)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll7_intr_cnt_END (14)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll6_intr_cnt_START (15)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll6_intr_cnt_END (17)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll6_fsm_intr_START (23)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll6_fsm_intr_END (23)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll1_fsm_intr_START (24)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll1_fsm_intr_END (24)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll2_fsm_intr_START (25)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll2_fsm_intr_END (25)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_ppll2_b_fsm_intr_START (26)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_ppll2_b_fsm_intr_END (26)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll3_fsm_intr_START (27)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll3_fsm_intr_END (27)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll7_fsm_intr_START (28)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll7_fsm_intr_END (28)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_aupll_fsm_intr_START (29)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_aupll_fsm_intr_END (29)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll5_fsm_intr_START (30)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_pll5_fsm_intr_END (30)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_intr_pll_fsm_START (31)
#define SOC_CRGPERIPH_PLL_FSM_STAT0_intr_pll_fsm_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pll1_curr_stat : 4;
        unsigned int pll2_curr_stat : 4;
        unsigned int pll2_b_curr_stat : 4;
        unsigned int pll3_curr_stat : 4;
        unsigned int pll7_curr_stat : 4;
        unsigned int pll6_curr_stat : 4;
        unsigned int reserved : 8;
    } reg;
} SOC_CRGPERIPH_PLL_FSM_STAT1_UNION;
#endif
#define SOC_CRGPERIPH_PLL_FSM_STAT1_pll1_curr_stat_START (0)
#define SOC_CRGPERIPH_PLL_FSM_STAT1_pll1_curr_stat_END (3)
#define SOC_CRGPERIPH_PLL_FSM_STAT1_pll2_curr_stat_START (4)
#define SOC_CRGPERIPH_PLL_FSM_STAT1_pll2_curr_stat_END (7)
#define SOC_CRGPERIPH_PLL_FSM_STAT1_pll2_b_curr_stat_START (8)
#define SOC_CRGPERIPH_PLL_FSM_STAT1_pll2_b_curr_stat_END (11)
#define SOC_CRGPERIPH_PLL_FSM_STAT1_pll3_curr_stat_START (12)
#define SOC_CRGPERIPH_PLL_FSM_STAT1_pll3_curr_stat_END (15)
#define SOC_CRGPERIPH_PLL_FSM_STAT1_pll7_curr_stat_START (16)
#define SOC_CRGPERIPH_PLL_FSM_STAT1_pll7_curr_stat_END (19)
#define SOC_CRGPERIPH_PLL_FSM_STAT1_pll6_curr_stat_START (20)
#define SOC_CRGPERIPH_PLL_FSM_STAT1_pll6_curr_stat_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int ppll1_gt_stat : 1;
        unsigned int ppll2_gt_stat : 1;
        unsigned int ppll2_b_gt_stat : 1;
        unsigned int ppll3_gt_stat : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int ppll6_gt_stat : 1;
        unsigned int ppll7_gt_stat : 1;
        unsigned int reserved_3 : 1;
        unsigned int ppll1_bypass : 1;
        unsigned int ppll2_bypass : 1;
        unsigned int ppll2_b_bypass : 1;
        unsigned int ppll3_bypass : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int ppll6_bypass : 1;
        unsigned int ppll7_bypass : 1;
        unsigned int reserved_6 : 1;
        unsigned int ppll1_en_stat : 1;
        unsigned int ppll2_en_stat : 1;
        unsigned int ppll2_b_en_stat : 1;
        unsigned int ppll3_en_stat : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int ppll6_en_stat : 1;
        unsigned int ppll7_en_stat : 1;
        unsigned int reserved_9 : 5;
    } reg;
} SOC_CRGPERIPH_PLL_VOTE_STAT0_UNION;
#endif
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll1_gt_stat_START (1)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll1_gt_stat_END (1)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll2_gt_stat_START (2)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll2_gt_stat_END (2)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll2_b_gt_stat_START (3)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll2_b_gt_stat_END (3)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll3_gt_stat_START (4)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll3_gt_stat_END (4)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll6_gt_stat_START (7)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll6_gt_stat_END (7)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll7_gt_stat_START (8)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll7_gt_stat_END (8)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll1_bypass_START (10)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll1_bypass_END (10)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll2_bypass_START (11)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll2_bypass_END (11)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll2_b_bypass_START (12)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll2_b_bypass_END (12)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll3_bypass_START (13)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll3_bypass_END (13)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll6_bypass_START (16)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll6_bypass_END (16)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll7_bypass_START (17)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll7_bypass_END (17)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll1_en_stat_START (19)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll1_en_stat_END (19)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll2_en_stat_START (20)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll2_en_stat_END (20)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll2_b_en_stat_START (21)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll2_b_en_stat_END (21)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll3_en_stat_START (22)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll3_en_stat_END (22)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll6_en_stat_START (25)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll6_en_stat_END (25)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll7_en_stat_START (26)
#define SOC_CRGPERIPH_PLL_VOTE_STAT0_ppll7_en_stat_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 5;
        unsigned int ppll6_en_vote : 5;
        unsigned int ppll7_en_vote : 5;
        unsigned int reserved_1 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PLL_EN_VOTE_CTRL1_UNION;
#endif
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL1_ppll6_en_vote_START (5)
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL1_ppll6_en_vote_END (9)
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL1_ppll7_en_vote_START (10)
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL1_ppll7_en_vote_END (14)
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL1_bitmasken_START (16)
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL1_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 5;
        unsigned int reserved_1 : 5;
        unsigned int ppll2_b_en_vote : 5;
        unsigned int reserved_2 : 1;
        unsigned int bitmasken : 16;
    } reg;
} SOC_CRGPERIPH_PLL_EN_VOTE_CTRL2_UNION;
#endif
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL2_ppll2_b_en_vote_START (10)
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL2_ppll2_b_en_vote_END (14)
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL2_bitmasken_START (16)
#define SOC_CRGPERIPH_PLL_EN_VOTE_CTRL2_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_clk_hpm : 1;
        unsigned int gt_pclk_autodiv_aclk_vcodec_tcu : 1;
        unsigned int gt_pclk_autodiv_vdec : 1;
        unsigned int gt_pclk_autodiv_venc : 1;
        unsigned int gt_pclk_autodiv_dss : 1;
        unsigned int gt_pclk_atgm_aae : 1;
        unsigned int gt_clk_aae_tcxo : 1;
        unsigned int gt_clk_aae_core : 1;
        unsigned int gt_clk_media1_lbist0 : 1;
        unsigned int gt_clk_media1_lbist1 : 1;
        unsigned int gt_pclk_media1_lbist0 : 1;
        unsigned int gt_pclk_media1_lbist1 : 1;
        unsigned int gt_clk_aae_dti_brg_ini : 1;
        unsigned int gt_clk_aae_dti_brg : 1;
        unsigned int gt_pclk_autodiv_aae : 1;
        unsigned int gt_clk_aae_qic : 1;
        unsigned int gt_clk_aae_part1 : 1;
        unsigned int gt_clk_aae_top : 1;
        unsigned int gt_clk_wrap_hpm : 1;
        unsigned int gt_clk_lat_mon_dss : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_MEDIA1_CRG_PERCLKEN1_UNION;
#endif
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_hpm_START (0)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_hpm_END (0)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_autodiv_aclk_vcodec_tcu_START (1)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_autodiv_aclk_vcodec_tcu_END (1)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_autodiv_vdec_START (2)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_autodiv_vdec_END (2)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_autodiv_venc_START (3)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_autodiv_venc_END (3)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_autodiv_dss_START (4)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_autodiv_dss_END (4)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_atgm_aae_START (5)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_atgm_aae_END (5)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_aae_tcxo_START (6)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_aae_tcxo_END (6)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_aae_core_START (7)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_aae_core_END (7)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_media1_lbist0_START (8)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_media1_lbist0_END (8)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_media1_lbist1_START (9)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_media1_lbist1_END (9)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_media1_lbist0_START (10)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_media1_lbist0_END (10)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_media1_lbist1_START (11)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_media1_lbist1_END (11)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_aae_dti_brg_ini_START (12)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_aae_dti_brg_ini_END (12)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_aae_dti_brg_START (13)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_aae_dti_brg_END (13)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_autodiv_aae_START (14)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_pclk_autodiv_aae_END (14)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_aae_qic_START (15)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_aae_qic_END (15)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_aae_part1_START (16)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_aae_part1_END (16)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_aae_top_START (17)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_aae_top_END (17)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_wrap_hpm_START (18)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_wrap_hpm_END (18)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_lat_mon_dss_START (19)
#define SOC_MEDIA1_CRG_PERCLKEN1_gt_clk_lat_mon_dss_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_rst_dss_crg : 1;
        unsigned int ip_rst_dss : 1;
        unsigned int ip_prst_atgm_dss : 1;
        unsigned int ip_prst_atgm_vdec : 1;
        unsigned int ip_rst_tcu_m1 : 1;
        unsigned int ip_prst_apb_brg_tcu : 1;
        unsigned int ip_rst_vdec_pxpc : 1;
        unsigned int ip_rst_vdec : 1;
        unsigned int ip_arst_vdec : 1;
        unsigned int ip_prst_vdec : 1;
        unsigned int ip_prst_atgm_venc : 1;
        unsigned int ip_rst_dss_disp1_crg : 1;
        unsigned int ip_rst_dss_disp1 : 1;
        unsigned int ip_rst_media_qic_data : 1;
        unsigned int ip_rst_qice_data : 1;
        unsigned int ip_rst_cs_vdec : 1;
        unsigned int ip_rst_cs_venc : 1;
        unsigned int ip_rst_venc : 1;
        unsigned int ip_prst_venc : 1;
        unsigned int ip_arst_venc : 1;
        unsigned int ip_rst_hpm : 1;
        unsigned int ip_rst_dbg_cs : 1;
        unsigned int ip_rst_qic_dss : 1;
        unsigned int ip_rst_media1_wrap_crg : 1;
        unsigned int ip_rst_cs_dss : 1;
        unsigned int ip_rst_cs_aae : 1;
        unsigned int ip_rst_wrap_hpm0 : 1;
        unsigned int ip_rst_wrap_hpm1 : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_MEDIA1_CRG_PERRSTSTAT0_UNION;
#endif
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_dss_crg_START (0)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_dss_crg_END (0)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_dss_START (1)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_dss_END (1)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_prst_atgm_dss_START (2)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_prst_atgm_dss_END (2)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_prst_atgm_vdec_START (3)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_prst_atgm_vdec_END (3)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_tcu_m1_START (4)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_tcu_m1_END (4)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_prst_apb_brg_tcu_START (5)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_prst_apb_brg_tcu_END (5)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_vdec_pxpc_START (6)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_vdec_pxpc_END (6)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_vdec_START (7)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_vdec_END (7)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_arst_vdec_START (8)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_arst_vdec_END (8)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_prst_vdec_START (9)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_prst_vdec_END (9)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_prst_atgm_venc_START (10)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_prst_atgm_venc_END (10)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_dss_disp1_crg_START (11)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_dss_disp1_crg_END (11)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_dss_disp1_START (12)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_dss_disp1_END (12)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_media_qic_data_START (13)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_media_qic_data_END (13)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_qice_data_START (14)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_qice_data_END (14)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_cs_vdec_START (15)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_cs_vdec_END (15)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_cs_venc_START (16)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_cs_venc_END (16)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_venc_START (17)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_venc_END (17)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_prst_venc_START (18)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_prst_venc_END (18)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_arst_venc_START (19)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_arst_venc_END (19)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_hpm_START (20)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_hpm_END (20)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_dbg_cs_START (21)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_dbg_cs_END (21)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_qic_dss_START (22)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_qic_dss_END (22)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_media1_wrap_crg_START (23)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_media1_wrap_crg_END (23)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_cs_dss_START (24)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_cs_dss_END (24)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_cs_aae_START (25)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_cs_aae_END (25)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_wrap_hpm0_START (26)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_wrap_hpm0_END (26)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_wrap_hpm1_START (27)
#define SOC_MEDIA1_CRG_PERRSTSTAT0_ip_rst_wrap_hpm1_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sel_dss_pll : 4;
        unsigned int sel_vdec_pll : 4;
        unsigned int sel_vcodec_axi_pll : 4;
        unsigned int reserved : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA1_CRG_CLKDIV0_UNION;
#endif
#define SOC_MEDIA1_CRG_CLKDIV0_sel_dss_pll_START (0)
#define SOC_MEDIA1_CRG_CLKDIV0_sel_dss_pll_END (3)
#define SOC_MEDIA1_CRG_CLKDIV0_sel_vdec_pll_START (4)
#define SOC_MEDIA1_CRG_CLKDIV0_sel_vdec_pll_END (7)
#define SOC_MEDIA1_CRG_CLKDIV0_sel_vcodec_axi_pll_START (8)
#define SOC_MEDIA1_CRG_CLKDIV0_sel_vcodec_axi_pll_END (11)
#define SOC_MEDIA1_CRG_CLKDIV0_bitmasken_START (16)
#define SOC_MEDIA1_CRG_CLKDIV0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_dss : 6;
        unsigned int reserved_0: 2;
        unsigned int div_vdec : 6;
        unsigned int reserved_1: 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA1_CRG_CLKDIV2_UNION;
#endif
#define SOC_MEDIA1_CRG_CLKDIV2_div_dss_START (0)
#define SOC_MEDIA1_CRG_CLKDIV2_div_dss_END (5)
#define SOC_MEDIA1_CRG_CLKDIV2_div_vdec_START (8)
#define SOC_MEDIA1_CRG_CLKDIV2_div_vdec_END (13)
#define SOC_MEDIA1_CRG_CLKDIV2_bitmasken_START (16)
#define SOC_MEDIA1_CRG_CLKDIV2_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hw_dvfs_en : 1;
        unsigned int reserved_0 : 15;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_MEDIA1_CRG_DSS_DVFS_UNION;
#endif
#define SOC_MEDIA1_CRG_DSS_DVFS_hw_dvfs_en_START (0)
#define SOC_MEDIA1_CRG_DSS_DVFS_hw_dvfs_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hw_sel_dss_pll : 4;
        unsigned int hw_div_dss : 6;
        unsigned int reserved : 22;
    } reg;
} SOC_MEDIA1_CRG_DSS_DVFS_AUTODIV_UNION;
#endif
#define SOC_MEDIA1_CRG_DSS_DVFS_AUTODIV_hw_sel_dss_pll_START (0)
#define SOC_MEDIA1_CRG_DSS_DVFS_AUTODIV_hw_sel_dss_pll_END (3)
#define SOC_MEDIA1_CRG_DSS_DVFS_AUTODIV_hw_div_dss_START (4)
#define SOC_MEDIA1_CRG_DSS_DVFS_AUTODIV_hw_div_dss_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_PMCTRL_PERI_CTRL5_UNION;
#endif
#endif
