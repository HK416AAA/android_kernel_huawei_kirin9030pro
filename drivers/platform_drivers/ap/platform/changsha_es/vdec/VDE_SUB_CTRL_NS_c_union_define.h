#ifndef __VDE_SUB_CTRL_NS_C_UNION_DEFINE_H__
#define __VDE_SUB_CTRL_NS_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int mcu_clk_en : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_MCU_CRG0;
typedef union {
    struct {
        unsigned int reserved_0 : 1 ;
        unsigned int ipc_clk_en : 1 ;
        unsigned int tim_clk_en : 1 ;
        unsigned int uart_clk_en : 1 ;
        unsigned int reserved_1 : 28 ;
    } bits;
    unsigned int u32;
} U_MCU_CRG1;
typedef union {
    struct {
        unsigned int scd_clk_en : 1 ;
        unsigned int reserved_0 : 3 ;
        unsigned int bsp_clk_en : 1 ;
        unsigned int reserved_1 : 3 ;
        unsigned int pxpc_clk_en : 1 ;
        unsigned int pxpc_vdec_clk_en : 1 ;
        unsigned int reserved_2 : 2 ;
        unsigned int pxp_hw_clk_en : 1 ;
        unsigned int hw_qic_clk_axi_en : 1 ;
        unsigned int reserved_3 : 2 ;
        unsigned int core_qic_clk_vdec_en : 1 ;
        unsigned int core_qic_clk_axi_en : 1 ;
        unsigned int reserved_4 : 2 ;
        unsigned int calc_data_qic_clk_vdec_en : 1 ;
        unsigned int calc_data_qic_clk_pxpc_en : 1 ;
        unsigned int calc_data_qic_clk_pxphw_en : 1 ;
        unsigned int reserved_5 : 1 ;
        unsigned int core_cfg_qic_clk_vdec_en : 1 ;
        unsigned int core_cfg_qic_clk_pxpc_en : 1 ;
        unsigned int reserved_6 : 2 ;
        unsigned int smmu_clk_axi_en : 1 ;
        unsigned int reserved_7 : 3 ;
    } bits;
    unsigned int u32;
} U_VDEC_CRG;
typedef union {
    struct {
        unsigned int calc_vdec_clk_en : 1 ;
        unsigned int calc_axi_clk_en : 1 ;
        unsigned int calc_pxpc_clk_en : 1 ;
        unsigned int calc_in_sys_clk_en : 1 ;
        unsigned int reserved_0 : 28 ;
    } bits;
    unsigned int u32;
} U_VDEC_ROOT_CRG;
typedef union {
    struct {
        unsigned int mcu_por_rst : 1 ;
        unsigned int mcu_wdt_rst : 1 ;
        unsigned int reserved_0 : 6 ;
        unsigned int mcu_core_wait : 1 ;
        unsigned int reserved_1 : 23 ;
    } bits;
    unsigned int u32;
} U_MCU_RST0;
typedef union {
    struct {
        unsigned int reserved_0 : 1 ;
        unsigned int ipc_soft_rst : 1 ;
        unsigned int tim_soft_rst : 1 ;
        unsigned int uart_soft_rst : 1 ;
        unsigned int reserved_1 : 28 ;
    } bits;
    unsigned int u32;
} U_MCU_RST1;
typedef union {
    struct {
        unsigned int scd_soft_rst : 1 ;
        unsigned int reserved_0 : 3 ;
        unsigned int bsp_soft_rst : 1 ;
        unsigned int reserved_1 : 3 ;
        unsigned int pxpc_dbg_soft_rst : 1 ;
        unsigned int pxpc_vdec_soft_rst : 1 ;
        unsigned int pxpc_top_soft_rst : 1 ;
        unsigned int reserved_2 : 1 ;
        unsigned int pxphw_soft_rst : 1 ;
        unsigned int hw_qic_clk_axi_soft_rst : 1 ;
        unsigned int reserved_3 : 2 ;
        unsigned int core_qic_clk_vdec_soft_rst : 1 ;
        unsigned int core_qic_clk_axi_soft_rst : 1 ;
        unsigned int reserved_4 : 2 ;
        unsigned int calc_data_qic_clk_vdec_soft_rst : 1 ;
        unsigned int calc_data_qic_clk_pxpc_soft_rst : 1 ;
        unsigned int calc_data_qic_clk_pxphw_soft_rst : 1 ;
        unsigned int reserved_5 : 1 ;
        unsigned int core_cfg_qic_clk_vdec_soft_rst : 1 ;
        unsigned int core_cfg_qic_clk_pxpc_soft_rst : 1 ;
        unsigned int reserved_6 : 2 ;
        unsigned int smmu_clk_axi_soft_rst : 1 ;
        unsigned int hts_soft_rst : 1 ;
        unsigned int reserved_7 : 2 ;
    } bits;
    unsigned int u32;
} U_VDEC_RST;
typedef union {
    struct {
        unsigned int calc_vdec_soft_rst : 1 ;
        unsigned int calc_axi_soft_rst : 1 ;
        unsigned int calc_pxpc_soft_rst : 1 ;
        unsigned int reserved_0 : 29 ;
    } bits;
    unsigned int u32;
} U_VDEC_ROOT_RST;
typedef union {
    struct {
        unsigned int pxp_hw_clk_gt_en : 1 ;
        unsigned int reserved_0 : 1 ;
        unsigned int reserved_1 : 1 ;
        unsigned int scd_clk_gt_en : 1 ;
        unsigned int reserved_2 : 12 ;
        unsigned int mem_clk_gt_en : 1 ;
        unsigned int mem_clk_gt_en_bsp : 1 ;
        unsigned int mem_clk_gt_en_pxpc : 1 ;
        unsigned int reserved_3 : 13 ;
    } bits;
    unsigned int u32;
} U_VDE_CK_EN;
typedef union {
    struct {
        unsigned int task_indicator_bsp0 : 8 ;
        unsigned int task_thredth_bsp0 : 8 ;
        unsigned int task_indicator_bsp1 : 8 ;
        unsigned int task_thredth_bsp1 : 8 ;
    } bits;
    unsigned int u32;
} U_BSP_TASK_INDICATOR0_NS;
typedef union {
    struct {
        unsigned int task_indicator_pxpc : 8 ;
        unsigned int task_thredth_pxpc : 8 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_PXPC_TASK_INDICATOR_NS;
typedef union {
    struct {
        unsigned int new_task_pause_bsp0 : 1 ;
        unsigned int new_task_pause_bsp1 : 1 ;
        unsigned int reserved_0 : 14 ;
        unsigned int new_task_pause_pxpc : 1 ;
        unsigned int reserved_1 : 15 ;
    } bits;
    unsigned int u32;
} U_NEW_TASK_NS;
typedef union {
    struct {
        unsigned int intr_pxpc_wr_ns : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_INTR_NS_PXPC_WR0;
typedef union {
    struct {
        unsigned int intr_pxpc_ns : 18 ;
        unsigned int reserved_0 : 14 ;
    } bits;
    unsigned int u32;
} U_INTR_NS_PXPC0;
typedef union {
    struct {
        unsigned int intr_pxpc_acpu_ns : 18 ;
        unsigned int reserved_0 : 14 ;
    } bits;
    unsigned int u32;
} U_INTR_NS_PXPC1;
typedef union {
    struct {
        unsigned int intr_bsp_ns1 : 4 ;
        unsigned int reserved_0 : 28 ;
    } bits;
    unsigned int u32;
} U_INTR_NS_BSP2;
typedef union {
    struct {
        unsigned int intr_bsp_acpu_ns1 : 4 ;
        unsigned int reserved_0 : 28 ;
    } bits;
    unsigned int u32;
} U_INTR_NS_BSP3;
typedef union {
    struct {
        unsigned int intr_pxpc_mask : 18 ;
        unsigned int reserved_0 : 14 ;
    } bits;
    unsigned int u32;
} U_INTR_MASK_NS_PXPC0;
typedef union {
    struct {
        unsigned int intr_pxpc_acpu_mask : 18 ;
        unsigned int reserved_0 : 14 ;
    } bits;
    unsigned int u32;
} U_INTR_MASK_NS_PXPC1;
typedef union {
    struct {
        unsigned int intr_bsp_mask1 : 4 ;
        unsigned int reserved_0 : 28 ;
    } bits;
    unsigned int u32;
} U_INTR_MASK_NS_BSP2;
typedef union {
    struct {
        unsigned int intr_bsp_acpu_mask1 : 4 ;
        unsigned int reserved_0 : 28 ;
    } bits;
    unsigned int u32;
} U_INTR_MASK_NS_BSP3;
typedef union {
    struct {
        unsigned int intr_pxpc_clr : 16 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_INTR_CLR_NS_PXPC0;
typedef union {
    struct {
        unsigned int intr_120hz_sel_ns : 2 ;
        unsigned int reserved_0 : 30 ;
    } bits;
    unsigned int u32;
} U_INTR_SEL_NS_DSS_SYNC;
typedef union {
    struct {
        unsigned int bsp_subtask_intr0_cnt_ns : 4 ;
        unsigned int bsp_subtask_intr1_cnt_ns : 4 ;
        unsigned int reserved_0 : 8 ;
        unsigned int bsp_task_intr0_cnt_ns : 4 ;
        unsigned int bsp_task_intr1_cnt_ns : 4 ;
        unsigned int reserved_1 : 8 ;
    } bits;
    unsigned int u32;
} U_INTR_CNT_STAT0_NS;
typedef union {
    struct {
        unsigned int dss_120hz_intr_cnt_ns : 4 ;
        unsigned int pxpc_frm_intr_cnt_ns : 4 ;
        unsigned int pxpc_task_intr_cnt_ns : 4 ;
        unsigned int pxpc_maintask_intr_cnt_ns : 4 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_INTR_CNT_STAT1_NS;
typedef union {
    struct {
        unsigned int intr_cnt_rsv_ns : 4 ;
        unsigned int reserved_0 : 28 ;
    } bits;
    unsigned int u32;
} U_INTR_CNT_RSV_NS;
typedef union {
    struct {
        unsigned int scd_srst_req : 1 ;
        unsigned int reserved_0 : 7 ;
        unsigned int scd_force_ack : 1 ;
        unsigned int reserved_1 : 7 ;
        unsigned int scd_srst_ok : 1 ;
        unsigned int reserved_2 : 15 ;
    } bits;
    unsigned int u32;
} U_SCD_SOFTRST_CFG;
typedef union {
    struct {
        unsigned int vdec_idle : 1 ;
        unsigned int vdec_scd_idle : 1 ;
        unsigned int vdec_bsp_idle : 1 ;
        unsigned int reserved_0 : 1 ;
        unsigned int reserved_1 : 1 ;
        unsigned int reserved_2 : 1 ;
        unsigned int reserved_3 : 1 ;
        unsigned int vdec_pxpc_idle : 1 ;
        unsigned int vdec_pxpc_bus_idle : 1 ;
        unsigned int reserved_4 : 1 ;
        unsigned int vdec_pxp_hw_idle : 1 ;
        unsigned int vdec_core_data_qic_idle : 1 ;
        unsigned int vdec_core_cfg_qic_idle : 1 ;
        unsigned int vdec_cfg_qic_idle : 1 ;
        unsigned int tbu_idle : 1 ;
        unsigned int reserved_5 : 1 ;
        unsigned int tbu_dti_rs_idle : 1 ;
        unsigned int media1_vdec_qic_msg_idle : 1 ;
        unsigned int reserved_6 : 14 ;
    } bits;
    unsigned int u32;
} U_VDEC_IDLE_ST;
typedef union {
    struct {
        unsigned int vdec_idle_bp : 24 ;
        unsigned int mcu_idle_cfg : 1 ;
        unsigned int reserved_0 : 7 ;
    } bits;
    unsigned int u32;
} U_VDEC_IDLE_BY;
typedef union {
    struct {
        unsigned int core_data_qic_riscv_awpush : 4 ;
        unsigned int core_data_qic_riscv_arpush : 4 ;
        unsigned int core_data_qic_scd_awpush : 4 ;
        unsigned int core_data_qic_scd_arpush : 4 ;
        unsigned int reserved_0 : 16 ;
    } bits;
    unsigned int u32;
} U_CORE_DATA_QIC_PUSH;
typedef union {
    struct {
        unsigned int mcu_soft_nmi : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_MCU_NMI;
typedef union {
    struct {
        unsigned int reserved_0 : 1 ;
        unsigned int reserved_1 : 1 ;
        unsigned int reserved_2 : 1 ;
        unsigned int reserved_3 : 1 ;
        unsigned int vdec_mcu_dbgen : 1 ;
        unsigned int reserved_4 : 27 ;
    } bits;
    unsigned int u32;
} U_MCU_HW_BUF_LEN;
typedef union {
    struct {
        unsigned int mcu_ddr_addr_high4 : 4 ;
        unsigned int reserved_0 : 28 ;
    } bits;
    unsigned int u32;
} U_MCU_ADDR_HIGH;
typedef union {
    struct {
        unsigned int mcu_instr_fetch_en : 1 ;
        unsigned int mcu_hart_id : 4 ;
        unsigned int mcu_dm_clk_off_n : 1 ;
        unsigned int reserved_0 : 26 ;
    } bits;
    unsigned int u32;
} U_MCU_CTRL0;
typedef union {
    struct {
        unsigned int mcu_sleep_mode : 1 ;
        unsigned int mcu_debug_mode : 1 ;
        unsigned int mcu_in_nmi_hdlr : 1 ;
        unsigned int mcu_in_async_excp_hdlr : 1 ;
        unsigned int mcu_ahbs_store_idle : 1 ;
        unsigned int mcu_dcsr_stoptime : 1 ;
        unsigned int mcu_in_double_excp_hdlr : 1 ;
        unsigned int mcu_top_dfx_cmt_vld0 : 1 ;
        unsigned int mcu_top_dfx_cmt_vld1 : 1 ;
        unsigned int reserved_0 : 3 ;
        unsigned int mcu_dfx_cmt_gpr_vld0 : 1 ;
        unsigned int mcu_dfx_cmt_gpr_vld1 : 1 ;
        unsigned int mcu_dfx_cmt_gpr_idx0 : 5 ;
        unsigned int mcu_dfx_cmt_gpr_idx1 : 5 ;
        unsigned int reserved_1 : 8 ;
    } bits;
    unsigned int u32;
} U_MCU_DBG_SIGNAL0;
typedef union {
    struct {
        unsigned int div_num0 : 6 ;
        unsigned int dfs_force_busy0 : 1 ;
        unsigned int dfs_en0 : 1 ;
        unsigned int dfs_wait_cnt0 : 8 ;
        unsigned int div_num1 : 6 ;
        unsigned int dfs_force_busy1 : 1 ;
        unsigned int dfs_en1 : 1 ;
        unsigned int dfs_wait_cnt1 : 8 ;
    } bits;
    unsigned int u32;
} U_CORE_DFS_CFG;
typedef struct {
    volatile unsigned int VDE_VERSION ;
    volatile unsigned int reserved_0[3] ;
    volatile U_MCU_CRG0 MCU_CRG0 ;
    volatile U_MCU_CRG1 MCU_CRG1 ;
    volatile U_VDEC_CRG VDEC_CRG ;
    volatile U_VDEC_ROOT_CRG VDEC_ROOT_CRG ;
    volatile U_MCU_RST0 MCU_RST0 ;
    volatile U_MCU_RST1 MCU_RST1 ;
    volatile U_VDEC_RST VDEC_RST ;
    volatile U_VDEC_ROOT_RST VDEC_ROOT_RST ;
    volatile U_VDE_CK_EN VDE_CK_EN ;
    volatile unsigned int reserved_1[3] ;
    volatile U_BSP_TASK_INDICATOR0_NS BSP_TASK_INDICATOR0_NS ;
    volatile unsigned int BSP_TASK_INDICATOR1_NS ;
    volatile U_PXPC_TASK_INDICATOR_NS PXPC_TASK_INDICATOR_NS ;
    volatile U_NEW_TASK_NS NEW_TASK_NS ;
    volatile unsigned int reserved_2[4] ;
    volatile U_INTR_NS_PXPC_WR0 INTR_NS_PXPC_WR0 ;
    volatile U_INTR_NS_PXPC0 INTR_NS_PXPC0 ;
    volatile U_INTR_NS_PXPC1 INTR_NS_PXPC1 ;
    volatile unsigned int reserved_3 ;
    volatile unsigned int INTR_NS_BSP_WR0 ;
    volatile unsigned int INTR_NS_BSP0 ;
    volatile unsigned int INTR_NS_BSP1 ;
    volatile U_INTR_NS_BSP2 INTR_NS_BSP2 ;
    volatile U_INTR_NS_BSP3 INTR_NS_BSP3 ;
    volatile unsigned int INTR_NS_VDEC ;
    volatile unsigned int INTR_NS_VDEC1 ;
    volatile unsigned int reserved_4 ;
    volatile U_INTR_MASK_NS_PXPC0 INTR_MASK_NS_PXPC0 ;
    volatile U_INTR_MASK_NS_PXPC1 INTR_MASK_NS_PXPC1 ;
    volatile unsigned int reserved_5[2] ;
    volatile unsigned int INTR_MASK_NS_BSP0 ;
    volatile unsigned int INTR_MASK_NS_BSP1 ;
    volatile U_INTR_MASK_NS_BSP2 INTR_MASK_NS_BSP2 ;
    volatile U_INTR_MASK_NS_BSP3 INTR_MASK_NS_BSP3 ;
    volatile unsigned int INTR_MASK_NS_VDEC ;
    volatile unsigned int INTR_MASK_NS_VDEC1 ;
    volatile unsigned int reserved_6[2] ;
    volatile U_INTR_CLR_NS_PXPC0 INTR_CLR_NS_PXPC0 ;
    volatile unsigned int reserved_7[3] ;
    volatile unsigned int INTR_CLR_NS_BSP0 ;
    volatile unsigned int reserved_8[3] ;
    volatile unsigned int INTR_CLR_NS_VDEC ;
    volatile U_INTR_SEL_NS_DSS_SYNC INTR_SEL_NS_DSS_SYNC ;
    volatile unsigned int reserved_9[6] ;
    volatile U_INTR_CNT_STAT0_NS INTR_CNT_STAT0_NS ;
    volatile U_INTR_CNT_STAT1_NS INTR_CNT_STAT1_NS ;
    volatile unsigned int reserved_10[2] ;
    volatile U_INTR_CNT_RSV_NS INTR_CNT_RSV_NS[8] ;
    volatile unsigned int reserved_11[4] ;
    volatile U_SCD_SOFTRST_CFG SCD_SOFTRST_CFG ;
    volatile unsigned int SOFTRST_STA0 ;
    volatile unsigned int SOFTRST_STA1 ;
    volatile unsigned int reserved_12 ;
    volatile U_VDEC_IDLE_ST VDEC_IDLE_ST ;
    volatile unsigned int CFG_QIC_NO_PENDING_RD ;
    volatile unsigned int CFG_QIC_NO_PENDING_WR ;
    volatile unsigned int CFG_QIC_NO_PENDING_RT ;
    volatile unsigned int CFG_QIC_NO_PENDING_TB ;
    volatile unsigned int CORE_CFG_QIC_NO_PENDING_RD ;
    volatile unsigned int CORE_CFG_QIC_NO_PENDING_WR ;
    volatile unsigned int CORE_CFG_QIC_NO_PENDING_RT ;
    volatile unsigned int CORE_CFG_QIC_NO_PENDING_TB ;
    volatile unsigned int CORE_DATA_QIC_NO_PENDING ;
    volatile unsigned int reserved_13[6] ;
    volatile U_VDEC_IDLE_BY VDEC_IDLE_BY ;
    volatile unsigned int reserved_14[3] ;
    volatile unsigned int VDEC_SPMEM_CTRL_0 ;
    volatile unsigned int VDEC_TPMEM_CTRL_0 ;
    volatile unsigned int VDEC_BPMEM_CTRL_0 ;
    volatile unsigned int VDEC_SPMEM_CTRL_1 ;
    volatile unsigned int reserved_15[20] ;
    volatile U_CORE_DATA_QIC_PUSH CORE_DATA_QIC_PUSH ;
    volatile unsigned int reserved_16[67] ;
    volatile unsigned int MCU_POR_PC ;
    volatile unsigned int reserved_17 ;
    volatile U_MCU_NMI MCU_NMI ;
    volatile unsigned int reserved_18[9] ;
    volatile U_MCU_HW_BUF_LEN MCU_HW_BUF_LEN ;
    volatile U_MCU_ADDR_HIGH MCU_ADDR_HIGH ;
    volatile unsigned int reserved_19[18] ;
    volatile U_MCU_CTRL0 MCU_CTRL0 ;
    volatile unsigned int MCU_INSTR_MEM_CTRL0_LOW ;
    volatile unsigned int MCU_INSTR_MEM_CTRL0_HIGH ;
    volatile unsigned int MCU_INSTR_MEM_CTRL1_LOW ;
    volatile unsigned int MCU_INSTR_MEM_CTRL1_HIGH ;
    volatile unsigned int MCU_INSTR_MEM_CTRL2_LOW ;
    volatile unsigned int MCU_INSTR_MEM_CTRL2_HIGH ;
    volatile unsigned int reserved_20[21] ;
    volatile U_MCU_DBG_SIGNAL0 MCU_DBG_SIGNAL0 ;
    volatile unsigned int MCU_DFX_CMT_PC0 ;
    volatile unsigned int MCU_DFX_CMT_PC1 ;
    volatile unsigned int MCU_DFX_CMT_GPR_DATA0 ;
    volatile unsigned int MCU_DFX_CMT_GPR_DATA1 ;
    volatile unsigned int MCU_DFX_GPR_DATA_0_31[32] ;
    volatile unsigned int reserved_21[27] ;
    volatile U_CORE_DFS_CFG CORE_DFS_CFG ;
} S_VDE_SUB_CTRL_NS_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_MCU_CRG0 MCU_CRG0;
    volatile U_MCU_CRG1 MCU_CRG1;
    volatile U_VDEC_CRG VDEC_CRG;
    volatile U_VDEC_ROOT_CRG VDEC_ROOT_CRG;
    volatile U_MCU_RST0 MCU_RST0;
    volatile U_MCU_RST1 MCU_RST1;
    volatile U_VDEC_RST VDEC_RST;
    volatile U_VDEC_ROOT_RST VDEC_ROOT_RST;
    volatile U_VDE_CK_EN VDE_CK_EN;
    volatile U_BSP_TASK_INDICATOR0_NS BSP_TASK_INDICATOR0_NS;
    volatile U_PXPC_TASK_INDICATOR_NS PXPC_TASK_INDICATOR_NS;
    volatile U_NEW_TASK_NS NEW_TASK_NS;
    volatile U_INTR_NS_PXPC_WR0 INTR_NS_PXPC_WR0;
    volatile U_INTR_NS_PXPC0 INTR_NS_PXPC0;
    volatile U_INTR_NS_PXPC1 INTR_NS_PXPC1;
    volatile U_INTR_NS_BSP2 INTR_NS_BSP2;
    volatile U_INTR_NS_BSP3 INTR_NS_BSP3;
    volatile U_INTR_MASK_NS_PXPC0 INTR_MASK_NS_PXPC0;
    volatile U_INTR_MASK_NS_PXPC1 INTR_MASK_NS_PXPC1;
    volatile U_INTR_MASK_NS_BSP2 INTR_MASK_NS_BSP2;
    volatile U_INTR_MASK_NS_BSP3 INTR_MASK_NS_BSP3;
    volatile U_INTR_CLR_NS_PXPC0 INTR_CLR_NS_PXPC0;
    volatile U_INTR_SEL_NS_DSS_SYNC INTR_SEL_NS_DSS_SYNC;
    volatile U_INTR_CNT_STAT0_NS INTR_CNT_STAT0_NS;
    volatile U_INTR_CNT_STAT1_NS INTR_CNT_STAT1_NS;
    volatile U_INTR_CNT_RSV_NS INTR_CNT_RSV_NS;
    volatile U_SCD_SOFTRST_CFG SCD_SOFTRST_CFG;
    volatile U_VDEC_IDLE_ST VDEC_IDLE_ST;
    volatile U_VDEC_IDLE_BY VDEC_IDLE_BY;
    volatile U_CORE_DATA_QIC_PUSH CORE_DATA_QIC_PUSH;
    volatile U_MCU_NMI MCU_NMI;
    volatile U_MCU_HW_BUF_LEN MCU_HW_BUF_LEN;
    volatile U_MCU_ADDR_HIGH MCU_ADDR_HIGH;
    volatile U_MCU_CTRL0 MCU_CTRL0;
    volatile U_MCU_DBG_SIGNAL0 MCU_DBG_SIGNAL0;
    volatile U_CORE_DFS_CFG CORE_DFS_CFG;
} U_VDE_SUB_CTRL_NS_REGS_TYPE;
#endif
