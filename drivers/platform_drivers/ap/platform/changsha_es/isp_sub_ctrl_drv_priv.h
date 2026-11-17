#ifndef __ISP_SUB_CTRL_DRV_PRIV_H__
#define __ISP_SUB_CTRL_DRV_PRIV_H__ 
typedef union {
 struct {
  unsigned int hidma_clk_en : 1 ;
  unsigned int isp_ipc_clk_en : 1 ;
  unsigned int isp_tim_clk_en : 1 ;
  unsigned int rsv_0 : 1 ;
  unsigned int isp_tbu_clk_en : 1 ;
  unsigned int gt_clk_ixc_cluster : 21 ;
  unsigned int rsv_1 : 6 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_SUBSYS_CORE_CLK_EN;
typedef union {
 struct {
  unsigned int st_hidma_clk : 1 ;
  unsigned int st_isp_ipc_clk : 1 ;
  unsigned int st_isp_tim_clk : 1 ;
  unsigned int rsv_2 : 1 ;
  unsigned int st_isp_tbu_clk : 1 ;
  unsigned int st_clk_ixc_cluster : 21 ;
  unsigned int rsv_3 : 6 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_SUBSYS_CORE_CLK_ST;
typedef union {
 struct {
  unsigned int hidma_soft_rst_n : 1 ;
  unsigned int isp_ipc_soft_rst_n : 1 ;
  unsigned int isp_tim_soft_rst_n : 1 ;
  unsigned int rsv_4 : 1 ;
  unsigned int isp_tbu_soft_rst_n : 1 ;
  unsigned int srst_ixc_cluster : 21 ;
  unsigned int rsv_5 : 6 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_SUBSYS_CORE_SOFT_RST;
typedef union {
 struct {
  unsigned int dbg_timer_en : 1 ;
  unsigned int ixc_cluster_clkrst_bypass : 21 ;
  unsigned int oisp_ispctrl_force_clk_on : 1 ;
  unsigned int cg_global_oisp_func : 1 ;
  unsigned int rsv_6 : 8 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_SUBSYS_CORE_MISC;
typedef union {
 struct {
  unsigned int qic_timeout_en_oisp : 1 ;
  unsigned int pdc_oisp_syspdc_pwrd_req : 1 ;
  unsigned int rsv_7 : 30 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_OISP_QIC_CTRL;
typedef union {
 struct {
  unsigned int pdc_oisp_syspdc_pwrd_ack : 1 ;
  unsigned int rsv_8 : 31 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_OISP_QIC_STATUS;
typedef union {
 struct {
  unsigned int ipp_himinibus_x2p_ckg_en : 1 ;
  unsigned int rsv_9 : 31 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_IPP_BUS_CTRL;
typedef union {
 struct {
  unsigned int subctrl_to_core_grp0 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CORE_CTRL_0;
typedef union {
 struct {
  unsigned int vic0_out_irq_mask : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_VIC0_OUT0;
typedef union {
 struct {
  unsigned int vic0_in_irq_level_mask : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_VIC0_IN0;
typedef union {
 struct {
  unsigned int vic0_in_irq_level_force : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_VIC0_IN1;
typedef union {
 struct {
  unsigned int vic1_out_irq_mask : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_VIC1_OUT0;
typedef union {
 struct {
  unsigned int vic1_in_irq_level_mask : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_VIC1_IN0;
typedef union {
 struct {
  unsigned int vic1_in_irq_level_force : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_VIC1_IN1;
typedef union {
 struct {
  unsigned int lst_low_cam_6_sampled : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_LST_LOW_CAM_6_SAMPLED;
typedef union {
 struct {
  unsigned int lst_high_cam_6_sampled : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_LST_HIGH_CAM_6_SAMPLED;
typedef union {
 struct {
  unsigned int lst_low_cam_1_sampled : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_LST_LOW_CAM_1_SAMPLED;
typedef union {
 struct {
  unsigned int lst_high_cam_1_sampled : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_LST_HIGH_CAM_1_SAMPLED;
typedef union {
 struct {
  unsigned int lst_low_cam_2_sampled : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_LST_LOW_CAM_2_SAMPLED;
typedef union {
 struct {
  unsigned int lst_high_cam_2_sampled : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_LST_HIGH_CAM_2_SAMPLED;
typedef union {
 struct {
  unsigned int lst_low_cam_3_sampled : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_LST_LOW_CAM_3_SAMPLED;
typedef union {
 struct {
  unsigned int lst_high_cam_3_sampled : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_LST_HIGH_CAM_3_SAMPLED;
typedef union {
 struct {
  unsigned int lst_low_cam_4_sampled : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_LST_LOW_CAM_4_SAMPLED;
typedef union {
 struct {
  unsigned int lst_high_cam_4_sampled : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_LST_HIGH_CAM_4_SAMPLED;
typedef union {
 struct {
  unsigned int lst_low_cam_5_sampled : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_LST_LOW_CAM_5_SAMPLED;
typedef union {
 struct {
  unsigned int lst_high_cam_5_sampled : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_LST_HIGH_CAM_5_SAMPLED;
typedef union {
 struct {
  unsigned int lst_low : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_LST_LOW;
typedef union {
 struct {
  unsigned int lst_high : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_LST_HIGH;
typedef union {
 struct {
  unsigned int qic_timeout_st_qic_oisp : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_OISP_QIC_TIME_OUT_ST;
typedef union {
 struct {
  unsigned int qic_oisp_pwrd_debug_en : 1 ;
  unsigned int rsv_10 : 31 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_OISP_QIC_PWRD_DEBUG_EN;
typedef union {
 struct {
  unsigned int qic_oisp_timeout_st_msk : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_OISP_QIC_TIMEOUT_ST_MSK;
typedef union {
 struct {
  unsigned int isp_bus_overf_prot_flag : 1 ;
  unsigned int rsv_11 : 31 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CORE_STATUS;
typedef union {
 struct {
  unsigned int ipp_himinibus_x2p_idle : 1 ;
  unsigned int rsv_12 : 1 ;
  unsigned int qic_isp_qic_nopending_combo : 1 ;
  unsigned int cpu_subchip_bus_nopending : 6 ;
  unsigned int qic_oisp_qic_nopending_combo : 1 ;
  unsigned int rsv_13 : 22 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_SUBSYS_BUS_IDLE_STATUS;
typedef union {
 struct {
  unsigned int oisp_mcu_corewait : 1 ;
  unsigned int rsv_14 : 31 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_OISP_CPU_CTRL;
typedef union {
 struct {
  unsigned int isp_core_ctrl_0 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CORE_CTRL0;
typedef union {
 struct {
  unsigned int isp_core_ctrl_1 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CORE_CTRL1;
typedef union {
 struct {
  unsigned int isp_core_ctrl_2 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CORE_CTRL2;
typedef union {
 struct {
  unsigned int isp_core_ctrl_3 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CORE_CTRL3;
typedef union {
 struct {
  unsigned int isp_core_cfg_adb_ctrl : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CORE_CFG_ADB_CTRL;
typedef union {
 struct {
  unsigned int isp_core_cfg_adb_status : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CORE_CFG_ADB_ST;
typedef union {
 struct {
  unsigned int isp_core_rt_adb_ctrl : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CORE_RT_ADB_CTRL;
typedef union {
 struct {
  unsigned int isp_core_rt_adb_status : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CORE_RT_ADB_ST;
typedef union {
 struct {
  unsigned int isp_core_srt_adb_ctrl : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CORE_SRT_ADB_CTRL;
typedef union {
 struct {
  unsigned int isp_core_srt_adb_status : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CORE_SRT_ADB_ST;
typedef union {
 struct {
  unsigned int isp_core_sc_adb_ctrl : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CORE_SC_ADB_CTRL;
typedef union {
 struct {
  unsigned int isp_core_sc_adb_status : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CORE_SC_ADB_ST;
typedef union {
 struct {
  unsigned int isp_core_nrt_adb_ctrl : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CORE_NRT_ADB_CTRL;
typedef union {
 struct {
  unsigned int isp_core_nrt_adb_status : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CORE_NRT_ADB_ST;
typedef union {
 struct {
  unsigned int isp_core_vc_sc : 2 ;
  unsigned int rsv_15 : 30 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CORE_VC_SC;
typedef union {
 struct {
  unsigned int dpm_enable : 1 ;
  unsigned int dpm_src : 1 ;
  unsigned int dpm_mode : 2 ;
  unsigned int rsv_16 : 28 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_LM_CTRL;
typedef union {
 struct {
  unsigned int tcmdma_aclk0_force_on : 1 ;
  unsigned int tcmdma_aclk1_force_on : 1 ;
  unsigned int rsv_17 : 30 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_TCMDMA_CTRL_0;
typedef union {
 struct {
  unsigned int tcmdma_mem_ctrl_tp : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_TCMDMA_MEM_CTRL;
typedef union {
 struct {
  unsigned int isp_subsys_irq_ctrl : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_SUBSYS_IRQ_CTRL;
typedef union {
 struct {
  unsigned int external_irq_set : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_SUBSYS_EXT_IRQ_SET;
typedef union {
 struct {
  unsigned int external_irq_msk : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_SUBSYS_EXT_IRQ_MSK;
typedef union {
 struct {
  unsigned int external_irq_clr : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_SUBSYS_EXT_IRQ_CLR;
typedef union {
 struct {
  unsigned int external_irq_ris : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_SUBSYS_EXT_IRQ_RIS;
typedef union {
 struct {
  unsigned int reserved_for_state_sync_1 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_1;
typedef union {
 struct {
  unsigned int reserved_for_state_sync_2 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_2;
typedef union {
 struct {
  unsigned int reserved_for_state_sync_3 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_3;
typedef union {
 struct {
  unsigned int reserved_for_state_sync_4 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_4;
typedef union {
 struct {
  unsigned int reserved_for_state_sync_5 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_5;
typedef union {
 struct {
  unsigned int reserved_for_state_sync_6 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_6;
typedef union {
 struct {
  unsigned int reserved_for_state_sync_7 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_7;
typedef union {
 struct {
  unsigned int reserved_for_state_sync_8 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_8;
typedef union {
 struct {
  unsigned int reserved_for_state_sync_9 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_9;
typedef union {
 struct {
  unsigned int reserved_for_state_sync_10 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_10;
typedef union {
 struct {
  unsigned int reserved_for_state_sync_11 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_11;
typedef union {
 struct {
  unsigned int reserved_for_state_sync_12 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_12;
typedef union {
 struct {
  unsigned int reserved_for_state_sync_13 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_13;
typedef union {
 struct {
  unsigned int reserved_for_state_sync_14 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_14;
typedef union {
 struct {
  unsigned int reserved_for_state_sync_15 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_15;
typedef union {
 struct {
  unsigned int reserved_for_state_sync_16 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_16;
typedef union {
 struct {
  unsigned int vic0_in_irq_level_mask_high : 16 ;
  unsigned int rsv_18 : 16 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_VIC0_IN2;
typedef union {
 struct {
  unsigned int vic0_in_irq_level_force_high : 16 ;
  unsigned int rsv_19 : 16 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_VIC0_IN3;
typedef union {
 struct {
  unsigned int vic0_out_irq_mask_high : 16 ;
  unsigned int rsv_20 : 16 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_VIC0_OUT1;
typedef union {
 struct {
  unsigned int isp_cpu_ctrl0 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_CTRL_0;
typedef union {
 struct {
  unsigned int isp_cpu_ctrl1 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_CTRL_1;
typedef union {
 struct {
  unsigned int isp_cpu_ctrl2 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_CTRL_2;
typedef union {
 struct {
  unsigned int isp_cpu_ctrl3 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_CTRL_3;
typedef union {
 struct {
  unsigned int isp_cpu_ctrl4 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_CTRL_4;
typedef union {
 struct {
  unsigned int isp_cpu_ctrl5 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_CTRL_5;
typedef union {
 struct {
  unsigned int isp_cpu_ctrl6 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_CTRL_6;
typedef union {
 struct {
  unsigned int isp_cpu_ctrl7 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_CTRL_7;
typedef union {
 struct {
  unsigned int isp_cpu_ctrl8 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_CTRL_8;
typedef union {
 struct {
  unsigned int isp_cpu_ctrl9 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_CTRL_9;
typedef union {
 struct {
  unsigned int isp_cpu_ctrl10 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_CTRL_10;
typedef union {
 struct {
  unsigned int isp_cpu_ctrl11 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_CTRL_11;
typedef union {
 struct {
  unsigned int isp_cpu_ctrl12 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_CTRL_12;
typedef union {
 struct {
  unsigned int isp_cpu_ctrl13 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_CTRL_13;
typedef union {
 struct {
  unsigned int isp_cpu_ctrl14 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_CTRL_14;
typedef union {
 struct {
  unsigned int isp_cpu_ctrl15 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_CTRL_15;
typedef union {
 struct {
  unsigned int isp_cpu_ctrl16 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_CTRL_16;
typedef union {
 struct {
  unsigned int isp_cpu_status_0 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_STATUS_0;
typedef union {
 struct {
  unsigned int isp_cpu_status_1 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_STATUS_1;
typedef union {
 struct {
  unsigned int isp_cpu_status_2 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_STATUS_2;
typedef union {
 struct {
  unsigned int isp_cpu_status_3 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_STATUS_3;
typedef union {
 struct {
  unsigned int isp_cpu_status_4 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_STATUS_4;
typedef union {
 struct {
  unsigned int isp_cpu_status_5 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_STATUS_5;
typedef union {
 struct {
  unsigned int isp_cpu_status_6 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_STATUS_6;
typedef union {
 struct {
  unsigned int isp_cpu_status_7 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_STATUS_7;
typedef union {
 struct {
  unsigned int isp_cpu_status_8 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_STATUS_8;
typedef union {
 struct {
  unsigned int isp_cpu_status_9 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_STATUS_9;
typedef union {
 struct {
  unsigned int isp_cpu_status_10 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_STATUS_10;
typedef union {
 struct {
  unsigned int isp_cpu_status_11 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_STATUS_11;
typedef union {
 struct {
  unsigned int isp_cpu_status_12 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_STATUS_12;
typedef union {
 struct {
  unsigned int isp_cpu_status_13 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_STATUS_13;
typedef union {
 struct {
  unsigned int isp_cpu_status_14 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_STATUS_14;
typedef union {
 struct {
  unsigned int isp_cpu_status_15 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_STATUS_15;
typedef union {
 struct {
  unsigned int reserved_reg : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_RESERVED_REG;
typedef union {
 struct {
  unsigned int subctrl_to_core_grp1 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CORE_CTRL_1;
typedef union {
 struct {
  unsigned int subctrl_to_core_grps : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CORE_CTRL_S;
typedef union {
 struct {
  unsigned int subctrl_to_sub_grps : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_SUB_CTRL_S;
typedef union {
 struct {
  unsigned int vic2_out_irq_mask : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_VIC2_OUT0;
typedef union {
 struct {
  unsigned int vic2_in_irq_level_mask : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_VIC2_IN0;
typedef union {
 struct {
  unsigned int vic2_in_irq_level_force : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_VIC2_IN1;
typedef union {
 struct {
  unsigned int isp_cpu_ctrl_s_0 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_CTRL_S_0;
typedef union {
 struct {
  unsigned int isp_cpu_ctrl_s_1 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_CTRL_S_1;
typedef union {
 struct {
  unsigned int isp_cpu_ctrl_s_2 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_CTRL_S_2;
typedef union {
 struct {
  unsigned int isp_cpu_ctrl_s_3 : 32 ;
 } bits;
 unsigned int u32;
} ISP_SUB_CTRL_ISP_CPU_CTRL_S_3;
typedef struct {
 ISP_SUB_CTRL_SUBSYS_CORE_CLK_EN SUBSYS_CORE_CLK_EN ;
 ISP_SUB_CTRL_SUBSYS_CORE_CLK_ST SUBSYS_CORE_CLK_ST ;
 ISP_SUB_CTRL_SUBSYS_CORE_SOFT_RST SUBSYS_CORE_SOFT_RST ;
 ISP_SUB_CTRL_SUBSYS_CORE_MISC SUBSYS_CORE_MISC ;
 ISP_SUB_CTRL_OISP_QIC_CTRL OISP_QIC_CTRL ;
 ISP_SUB_CTRL_OISP_QIC_STATUS OISP_QIC_STATUS ;
 ISP_SUB_CTRL_IPP_BUS_CTRL IPP_BUS_CTRL ;
 ISP_SUB_CTRL_ISP_CORE_CTRL_0 ISP_CORE_CTRL_0 ;
 ISP_SUB_CTRL_VIC0_OUT0 VIC0_OUT0 ;
 ISP_SUB_CTRL_VIC0_IN0 VIC0_IN0 ;
 ISP_SUB_CTRL_VIC0_IN1 VIC0_IN1 ;
 ISP_SUB_CTRL_VIC1_OUT0 VIC1_OUT0 ;
 ISP_SUB_CTRL_VIC1_IN0 VIC1_IN0 ;
 ISP_SUB_CTRL_VIC1_IN1 VIC1_IN1 ;
 ISP_SUB_CTRL_LST_LOW_CAM_6_SAMPLED LST_LOW_CAM_6_SAMPLED ;
 ISP_SUB_CTRL_LST_HIGH_CAM_6_SAMPLED LST_HIGH_CAM_6_SAMPLED ;
 ISP_SUB_CTRL_LST_LOW_CAM_1_SAMPLED LST_LOW_CAM_1_SAMPLED ;
 ISP_SUB_CTRL_LST_HIGH_CAM_1_SAMPLED LST_HIGH_CAM_1_SAMPLED ;
 ISP_SUB_CTRL_LST_LOW_CAM_2_SAMPLED LST_LOW_CAM_2_SAMPLED ;
 ISP_SUB_CTRL_LST_HIGH_CAM_2_SAMPLED LST_HIGH_CAM_2_SAMPLED ;
 ISP_SUB_CTRL_LST_LOW_CAM_3_SAMPLED LST_LOW_CAM_3_SAMPLED ;
 ISP_SUB_CTRL_LST_HIGH_CAM_3_SAMPLED LST_HIGH_CAM_3_SAMPLED ;
 ISP_SUB_CTRL_LST_LOW_CAM_4_SAMPLED LST_LOW_CAM_4_SAMPLED ;
 ISP_SUB_CTRL_LST_HIGH_CAM_4_SAMPLED LST_HIGH_CAM_4_SAMPLED ;
 ISP_SUB_CTRL_LST_LOW_CAM_5_SAMPLED LST_LOW_CAM_5_SAMPLED ;
 ISP_SUB_CTRL_LST_HIGH_CAM_5_SAMPLED LST_HIGH_CAM_5_SAMPLED ;
 ISP_SUB_CTRL_LST_LOW LST_LOW ;
 ISP_SUB_CTRL_LST_HIGH LST_HIGH ;
 ISP_SUB_CTRL_OISP_QIC_TIME_OUT_ST OISP_QIC_TIME_OUT_ST ;
 ISP_SUB_CTRL_OISP_QIC_PWRD_DEBUG_EN OISP_QIC_PWRD_DEBUG_EN ;
 ISP_SUB_CTRL_OISP_QIC_TIMEOUT_ST_MSK OISP_QIC_TIMEOUT_ST_MSK ;
 ISP_SUB_CTRL_ISP_CORE_STATUS ISP_CORE_STATUS ;
 ISP_SUB_CTRL_ISP_SUBSYS_BUS_IDLE_STATUS ISP_SUBSYS_BUS_IDLE_STATUS ;
 ISP_SUB_CTRL_OISP_CPU_CTRL OISP_CPU_CTRL ;
 ISP_SUB_CTRL_ISP_CORE_CTRL0 ISP_CORE_CTRL0 ;
 ISP_SUB_CTRL_ISP_CORE_CTRL1 ISP_CORE_CTRL1 ;
 ISP_SUB_CTRL_ISP_CORE_CTRL2 ISP_CORE_CTRL2 ;
 ISP_SUB_CTRL_ISP_CORE_CTRL3 ISP_CORE_CTRL3 ;
 ISP_SUB_CTRL_ISP_CORE_CFG_ADB_CTRL ISP_CORE_CFG_ADB_CTRL ;
 ISP_SUB_CTRL_ISP_CORE_CFG_ADB_ST ISP_CORE_CFG_ADB_ST ;
 ISP_SUB_CTRL_ISP_CORE_RT_ADB_CTRL ISP_CORE_RT_ADB_CTRL ;
 ISP_SUB_CTRL_ISP_CORE_RT_ADB_ST ISP_CORE_RT_ADB_ST ;
 ISP_SUB_CTRL_ISP_CORE_SRT_ADB_CTRL ISP_CORE_SRT_ADB_CTRL ;
 ISP_SUB_CTRL_ISP_CORE_SRT_ADB_ST ISP_CORE_SRT_ADB_ST ;
 ISP_SUB_CTRL_ISP_CORE_SC_ADB_CTRL ISP_CORE_SC_ADB_CTRL ;
 ISP_SUB_CTRL_ISP_CORE_SC_ADB_ST ISP_CORE_SC_ADB_ST ;
 ISP_SUB_CTRL_ISP_CORE_NRT_ADB_CTRL ISP_CORE_NRT_ADB_CTRL ;
 ISP_SUB_CTRL_ISP_CORE_NRT_ADB_ST ISP_CORE_NRT_ADB_ST ;
 ISP_SUB_CTRL_ISP_CORE_VC_SC ISP_CORE_VC_SC ;
 ISP_SUB_CTRL_LM_CTRL LM_CTRL ;
 ISP_SUB_CTRL_TCMDMA_CTRL_0 TCMDMA_CTRL_0 ;
 ISP_SUB_CTRL_TCMDMA_MEM_CTRL TCMDMA_MEM_CTRL ;
 ISP_SUB_CTRL_ISP_SUBSYS_IRQ_CTRL ISP_SUBSYS_IRQ_CTRL ;
 ISP_SUB_CTRL_ISP_SUBSYS_EXT_IRQ_SET ISP_SUBSYS_EXT_IRQ_SET ;
 ISP_SUB_CTRL_ISP_SUBSYS_EXT_IRQ_MSK ISP_SUBSYS_EXT_IRQ_MSK ;
 ISP_SUB_CTRL_ISP_SUBSYS_EXT_IRQ_CLR ISP_SUBSYS_EXT_IRQ_CLR ;
 ISP_SUB_CTRL_ISP_SUBSYS_EXT_IRQ_RIS ISP_SUBSYS_EXT_IRQ_RIS ;
 ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_1 RESERVED_FOR_CPU_STATE_SYNC_1 ;
 ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_2 RESERVED_FOR_CPU_STATE_SYNC_2 ;
 ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_3 RESERVED_FOR_CPU_STATE_SYNC_3 ;
 ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_4 RESERVED_FOR_CPU_STATE_SYNC_4 ;
 ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_5 RESERVED_FOR_CPU_STATE_SYNC_5 ;
 ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_6 RESERVED_FOR_CPU_STATE_SYNC_6 ;
 ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_7 RESERVED_FOR_CPU_STATE_SYNC_7 ;
 ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_8 RESERVED_FOR_CPU_STATE_SYNC_8 ;
 ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_9 RESERVED_FOR_CPU_STATE_SYNC_9 ;
 ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_10 RESERVED_FOR_CPU_STATE_SYNC_10 ;
 ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_11 RESERVED_FOR_CPU_STATE_SYNC_11 ;
 ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_12 RESERVED_FOR_CPU_STATE_SYNC_12 ;
 ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_13 RESERVED_FOR_CPU_STATE_SYNC_13 ;
 ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_14 RESERVED_FOR_CPU_STATE_SYNC_14 ;
 ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_15 RESERVED_FOR_CPU_STATE_SYNC_15 ;
 ISP_SUB_CTRL_RESERVED_FOR_CPU_STATE_SYNC_16 RESERVED_FOR_CPU_STATE_SYNC_16 ;
 ISP_SUB_CTRL_VIC0_IN2 VIC0_IN2 ;
 ISP_SUB_CTRL_VIC0_IN3 VIC0_IN3 ;
 ISP_SUB_CTRL_VIC0_OUT1 VIC0_OUT1 ;
 ISP_SUB_CTRL_ISP_CPU_CTRL_0 ISP_CPU_CTRL_0 ;
 ISP_SUB_CTRL_ISP_CPU_CTRL_1 ISP_CPU_CTRL_1 ;
 ISP_SUB_CTRL_ISP_CPU_CTRL_2 ISP_CPU_CTRL_2 ;
 ISP_SUB_CTRL_ISP_CPU_CTRL_3 ISP_CPU_CTRL_3 ;
 ISP_SUB_CTRL_ISP_CPU_CTRL_4 ISP_CPU_CTRL_4 ;
 ISP_SUB_CTRL_ISP_CPU_CTRL_5 ISP_CPU_CTRL_5 ;
 ISP_SUB_CTRL_ISP_CPU_CTRL_6 ISP_CPU_CTRL_6 ;
 ISP_SUB_CTRL_ISP_CPU_CTRL_7 ISP_CPU_CTRL_7 ;
 ISP_SUB_CTRL_ISP_CPU_CTRL_8 ISP_CPU_CTRL_8 ;
 ISP_SUB_CTRL_ISP_CPU_CTRL_9 ISP_CPU_CTRL_9 ;
 ISP_SUB_CTRL_ISP_CPU_CTRL_10 ISP_CPU_CTRL_10 ;
 ISP_SUB_CTRL_ISP_CPU_CTRL_11 ISP_CPU_CTRL_11 ;
 ISP_SUB_CTRL_ISP_CPU_CTRL_12 ISP_CPU_CTRL_12 ;
 ISP_SUB_CTRL_ISP_CPU_CTRL_13 ISP_CPU_CTRL_13 ;
 ISP_SUB_CTRL_ISP_CPU_CTRL_14 ISP_CPU_CTRL_14 ;
 ISP_SUB_CTRL_ISP_CPU_CTRL_15 ISP_CPU_CTRL_15 ;
 ISP_SUB_CTRL_ISP_CPU_CTRL_16 ISP_CPU_CTRL_16 ;
 ISP_SUB_CTRL_ISP_CPU_STATUS_0 ISP_CPU_STATUS_0 ;
 ISP_SUB_CTRL_ISP_CPU_STATUS_1 ISP_CPU_STATUS_1 ;
 ISP_SUB_CTRL_ISP_CPU_STATUS_2 ISP_CPU_STATUS_2 ;
 ISP_SUB_CTRL_ISP_CPU_STATUS_3 ISP_CPU_STATUS_3 ;
 ISP_SUB_CTRL_ISP_CPU_STATUS_4 ISP_CPU_STATUS_4 ;
 ISP_SUB_CTRL_ISP_CPU_STATUS_5 ISP_CPU_STATUS_5 ;
 ISP_SUB_CTRL_ISP_CPU_STATUS_6 ISP_CPU_STATUS_6 ;
 ISP_SUB_CTRL_ISP_CPU_STATUS_7 ISP_CPU_STATUS_7 ;
 ISP_SUB_CTRL_ISP_CPU_STATUS_8 ISP_CPU_STATUS_8 ;
 ISP_SUB_CTRL_ISP_CPU_STATUS_9 ISP_CPU_STATUS_9 ;
 ISP_SUB_CTRL_ISP_CPU_STATUS_10 ISP_CPU_STATUS_10 ;
 ISP_SUB_CTRL_ISP_CPU_STATUS_11 ISP_CPU_STATUS_11 ;
 ISP_SUB_CTRL_ISP_CPU_STATUS_12 ISP_CPU_STATUS_12 ;
 ISP_SUB_CTRL_ISP_CPU_STATUS_13 ISP_CPU_STATUS_13 ;
 ISP_SUB_CTRL_ISP_CPU_STATUS_14 ISP_CPU_STATUS_14 ;
 ISP_SUB_CTRL_ISP_CPU_STATUS_15 ISP_CPU_STATUS_15 ;
 ISP_SUB_CTRL_RESERVED_REG RESERVED_REG ;
 ISP_SUB_CTRL_ISP_CORE_CTRL_1 ISP_CORE_CTRL_1 ;
 ISP_SUB_CTRL_ISP_CORE_CTRL_S ISP_CORE_CTRL_S ;
 ISP_SUB_CTRL_ISP_SUB_CTRL_S ISP_SUB_CTRL_S ;
 ISP_SUB_CTRL_VIC2_OUT0 VIC2_OUT0 ;
 ISP_SUB_CTRL_VIC2_IN0 VIC2_IN0 ;
 ISP_SUB_CTRL_VIC2_IN1 VIC2_IN1 ;
 ISP_SUB_CTRL_ISP_CPU_CTRL_S_0 ISP_CPU_CTRL_S_0 ;
 ISP_SUB_CTRL_ISP_CPU_CTRL_S_1 ISP_CPU_CTRL_S_1 ;
 ISP_SUB_CTRL_ISP_CPU_CTRL_S_2 ISP_CPU_CTRL_S_2 ;
 ISP_SUB_CTRL_ISP_CPU_CTRL_S_3 ISP_CPU_CTRL_S_3 ;
} S_ISP_SUB_CTRL_REG_REGS_TYPE;
#endif
