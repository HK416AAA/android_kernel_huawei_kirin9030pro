#ifndef __SOC_DACC_AAE_INTERFACE_H__
#define __SOC_DACC_AAE_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_DACC_AAE_SW_EXT_INT_REG_ADDR(base) ((base) + (0x0000))
#define SOC_DACC_AAE_SW_EXT_INT_MASK_REG_ADDR(base) ((base) + (0x0004))
#define SOC_DACC_AAE_POR_RESET_PC_REG_ADDR(base) ((base) + (0x0008))
#define SOC_DACC_AAE_CORE_CONFIG_REG_ADDR(base) ((base) + (0x000c))
#define SOC_DACC_AAE_CORE_STATUS_REG_ADDR(base) ((base) + (0x0010))
#define SOC_DACC_AAE_CORE_MON_PC_REG_ADDR(base) ((base) + (0x0014))
#define SOC_DACC_AAE_CORE_MON_LR_REG_ADDR(base) ((base) + (0x0018))
#define SOC_DACC_AAE_DMA_TRANS_START_ADDR_ADDR(base) ((base) + (0x001c))
#define SOC_DACC_AAE_DMA_TRANS_WORD_NUM_ADDR(base) ((base) + (0x0020))
#define SOC_DACC_AAE_DMA_TRANS_START_REG_ADDR(base) ((base) + (0x0024))
#define SOC_DACC_AAE_MOD_END_INT_MASK_REG_ADDR(base) ((base) + (0x0030))
#define SOC_DACC_AAE_MISC_INT_MASK_REG_ADDR(base) ((base) + (0x0038))
#define SOC_DACC_AAE_MOD_EXIT_MEM_DS_REG_ADDR(base) ((base) + (0x003c))
#define SOC_DACC_AAE_MOD_END_INT_CLR_REG_ADDR(base) ((base) + (0x0048))
#define SOC_DACC_AAE_MISC_INT_CLR_REG_ADDR(base) ((base) + (0x004c))
#define SOC_DACC_AAE_RISCV_2_ACPU_REG_ADDR(base) ((base) + (0x0050))
#define SOC_DACC_AAE_MINIBUS_1T01_CKG_EN_ADDR(base) ((base) + (0x0054))
#define SOC_DACC_AAE_MINIBUS_1T01_STATE_ADDR(base) ((base) + (0x0058))
#define SOC_DACC_AAE_CKG_EN_ADDR(base) ((base) + (0x005c))
#define SOC_DACC_AAE_LUT_LAYER_ID_ADDR(base) ((base) + (0x0060))
#define SOC_DACC_AAE_LP_DOZE_CFG_ADDR(base) ((base) + (0x0064))
#define SOC_DACC_AAE_ACPU_2_RISCV_INTR_TRIG_ADDR(base) ((base) + (0x006c))
#define SOC_DACC_AAE_ACPU_2_RISCV_INTR_MASK_ADDR(base) ((base) + (0x0070))
#define SOC_DACC_AAE_ACPU_2_RISCV_INTR_CLR_ADDR(base) ((base) + (0x0074))
#define SOC_DACC_AAE_WB_SOURCE_SEL_REG_ADDR(base) ((base) + (0x0078))
#define SOC_DACC_AAE_TCXO_CNTER_VALUE_ADDR(base) ((base) + (0x007c))
#define SOC_DACC_AAE_CLD_REFRESH_LINE_NUM_ADDR(base) ((base) + (0x0084))
#define SOC_DACC_AAE_RISCV_CFG_MISC_REG_ADDR(base) ((base) + (0x0088))
#define SOC_DACC_AAE_SSID_NUM_ADDR(base) ((base) + (0x008c))
#define SOC_DACC_AAE_VER_ID_REG_ADDR(base) ((base) + (0x00fc))
#define SOC_DACC_AAE_SW_CMD_REG0_ADDR(base) ((base) + (0x01e0))
#define SOC_DACC_AAE_SW_CMD_REG1_ADDR(base) ((base) + (0x01e4))
#define SOC_DACC_AAE_CMD_BUF_NUM_ADDR(base) ((base) + (0x01e8))
#define SOC_DACC_AAE_SW_CMD_TX_REG_ADDR(base) ((base) + (0x01ec))
#define SOC_DACC_AAE_CLK_SEL_REG_ADDR(base,s12) ((base) + (0x0340+(s12)*0x8))
#define SOC_DACC_AAE_CLK_EN_REG_ADDR(base,s12) ((base) + (0x0344+(s12)*0x8))
#define SOC_DACC_AAE_NEW_FRAME_RDY_CFG_ADDR(base,s12) ((base) + (0x0404+(s12)*0x400))
#define SOC_DACC_AAE_CTL_SW_EN_RELOAD_ADDR(base,s12) ((base) + (0x0408+(s12)*0x400))
#define SOC_DACC_AAE_RISCV_CFG_OVER_REG_ADDR(base,s12) ((base) + (0x0410+(s12)*0x400))
#define SOC_DACC_AAE_CTL_SW_INTR_EN_REG_ADDR(base,s12) ((base) + (0x0414+(s12)*0x400))
#define SOC_DACC_AAE_CTL_CFG_MODE0_ADDR(base,s12) ((base) + (0x0424+(s12)*0x400))
#define SOC_DACC_AAE_CFG_RD_SHADOW_ADDR(base,s12) ((base) + (0x0428+(s12)*0x400))
#define SOC_DACC_AAE_CTL_CLEAR_TIMEOUT_EN_REG_ADDR(base,s12) ((base) + (0x042C+(s12)*0x400))
#define SOC_DACC_AAE_ACPU_2_RISCV_LOG_REG_ADDR(base,s12) ((base) + (0x043C+(s12)*0x400))
#define SOC_DACC_AAE_RISCV_2_ACPU_LOG_REG_ADDR(base,s12) ((base) + (0x0440+(s12)*0x400))
#define SOC_DACC_AAE_SCMD_START_REG_ADDR(base,s12) ((base) + (0x0450+(s12)*0x400))
#define SOC_DACC_AAE_DCMD_START_REG_ADDR(base,s12) ((base) + (0x0454+(s12)*0x400))
#define SOC_DACC_AAE_ACPU_PARA_ADDR_REG_ADDR(base,s12) ((base) + (0x0458+(s12)*0x400))
#define SOC_DACC_AAE_RISCV_PARA_ADDR_REG_ADDR(base,s12) ((base) + (0x045C+(s12)*0x400))
#define SOC_DACC_AAE_LAYER_DIM_FLAG_REG_ADDR(base,s12) ((base) + (0x0460+(s12)*0x400))
#define SOC_DACC_AAE_GENERAL_CFG_0_REG_ADDR(base,s12) ((base) + (0x0464+(s12)*0x400))
#define SOC_DACC_AAE_GENERAL_CFG_1_REG_ADDR(base,s12) ((base) + (0x0468+(s12)*0x400))
#define SOC_DACC_AAE_DCMD_INTS_MASK_REG_ADDR(base,s12) ((base) + (0x0474+(s12)*0x400))
#define SOC_DACC_AAE_DCMD_STATUS_REG_ADDR(base,s12) ((base) + (0x0478+(s12)*0x400))
#define SOC_DACC_AAE_LAYER_NUM_REG_ADDR(base,s12) ((base) + (0x047C+(s12)*0x400))
#define SOC_DACC_AAE_CTL_SW_START_REG_ADDR(base) ((base) + (0x1480))
#define SOC_DACC_AAE_RISCV_CFG_XPU_INT_REG_ADDR(base) ((base) + (0x1100))
#define SOC_DACC_AAE_RISCV_CFG_XPU_INT_MASK_REG_ADDR(base) ((base) + (0x1104))
#define SOC_DACC_AAE_XPU_CFG_RISCV_INT_REG_ADDR(base) ((base) + (0x1108))
#define SOC_DACC_AAE_XPU_CFG_RISCV_INT_CLR_REG_ADDR(base) ((base) + (0x110c))
#define SOC_DACC_AAE_XPU_CFG_RISCV_INT_MASK_REG_ADDR(base) ((base) + (0x1110))
#define SOC_DACC_AAE_XPU_RISCV_COMM_INFO_0_ADDR(base) ((base) + (0x1114))
#define SOC_DACC_AAE_XPU_RISCV_COMM_INFO_1_ADDR(base) ((base) + (0x1118))
#define SOC_DACC_AAE_DBG_0_INFO_ADDR(base,s12) ((base) + (0x052c+(s12)*0x400))
#define SOC_DACC_AAE_DBG_1_INFO_ADDR(base,s12) ((base) + (0x0530+(s12)*0x400))
#define SOC_DACC_AAE_DBG_2_INFO_ADDR(base,s12) ((base) + (0x0534+(s12)*0x400))
#define SOC_DACC_AAE_DBG_3_INFO_ADDR(base,s12) ((base) + (0x0538+(s12)*0x400))
#define SOC_DACC_AAE_DBG_4_INFO_ADDR(base,s12) ((base) + (0x053c+(s12)*0x400))
#define SOC_DACC_AAE_DBG_5_INFO_ADDR(base,s12) ((base) + (0x0540+(s12)*0x400))
#define SOC_DACC_AAE_OV_WR_LINEREG_S0_ADDR(base) ((base) + (0x0000))
#define SOC_DACC_AAE_LAYER_LB_PARA0_S0_ADDR(base,pre_ch0) ((base) + (0x0004+(pre_ch0)*0x1c))
#define SOC_DACC_AAE_LAYER_LB_PARA1_S0_ADDR(base,pre_ch0) ((base) + (0x0008+(pre_ch0)*0x1c))
#define SOC_DACC_AAE_LAYER_LB_PARA2_S0_ADDR(base,pre_ch0) ((base) + (0x000c+(pre_ch0)*0x1c))
#define SOC_DACC_AAE_LAYER_INFO_IN_S0_ADDR(base,pre_ch0) ((base) + (0x0010+(pre_ch0)*0x1c))
#define SOC_DACC_AAE_LAYER_INFO_OUT_S0_ADDR(base,pre_ch0) ((base) + (0x0014+(pre_ch0)*0x1c))
#define SOC_DACC_AAE_LAYER_CLIP_INFO_S0_ADDR(base,pre_ch0) ((base) + (0x0018+(pre_ch0)*0x1c))
#define SOC_DACC_AAE_LAYER_LB_INFO_S0_ADDR(base,pre_ch0) ((base) + (0x001c+(pre_ch0)*0x1c))
#define SOC_DACC_AAE_OV_WR_LINEREG_S1_ADDR(base) ((base) + (0x0300))
#define SOC_DACC_AAE_LAYER_LB_PARA0_S1_ADDR(base,pre_ch1) ((base) + (0x0304+(pre_ch1)*0x1c))
#define SOC_DACC_AAE_LAYER_LB_PARA1_S1_ADDR(base,pre_ch1) ((base) + (0x0308+(pre_ch1)*0x1c))
#define SOC_DACC_AAE_LAYER_LB_PARA2_S1_ADDR(base,pre_ch1) ((base) + (0x030c+(pre_ch1)*0x1c))
#define SOC_DACC_AAE_LAYER_INFO_IN_S1_ADDR(base,pre_ch1) ((base) + (0x0310+(pre_ch1)*0x1c))
#define SOC_DACC_AAE_LAYER_INFO_OUT_S1_ADDR(base,pre_ch1) ((base) + (0x0314+(pre_ch1)*0x1c))
#define SOC_DACC_AAE_LAYER_CLIP_INFO_S1_ADDR(base,pre_ch1) ((base) + (0x0318+(pre_ch1)*0x1c))
#define SOC_DACC_AAE_LAYER_LB_INFO_S1_ADDR(base,pre_ch1) ((base) + (0x031c+(pre_ch1)*0x1c))
#define SOC_DACC_AAE_TOTAL_RD_LINE_NUM_S0_ADDR(base) ((base) + (0x0500))
#define SOC_DACC_AAE_TOTAL_WR_LINE_NUM_S0_ADDR(base) ((base) + (0x0504))
#define SOC_DACC_AAE_TOTAL_RD_LINE_NUM_S1_ADDR(base) ((base) + (0x0508))
#define SOC_DACC_AAE_TOTAL_WR_LINE_NUM_S1_ADDR(base) ((base) + (0x050C))
#define SOC_DACC_AAE_PRE_PIPE_FLAG_ADDR(base) ((base) + (0x0e50))
#define SOC_DACC_AAE_SCENE_0_WB_INFO_REG_ADDR(base) ((base) + (0x0e60))
#define SOC_DACC_AAE_SCENE_RD_INFO_REG_ADDR(base,post_ch) ((base) + (0x0e70+(post_ch)*0x10))
#define SOC_DACC_AAE_SCENE_WR_INFO_REG_ADDR(base,post_ch) ((base) + (0x0e74+(post_ch)*0x10))
#define SOC_DACC_AAE_SCENE_LB_R_INFO_REG_ADDR(base,post_ch) ((base) + (0x0e78+(post_ch)*0x10))
#define SOC_DACC_AAE_SCENE_LB_W_INFO_REG_ADDR(base,post_ch) ((base) + (0x0e7c+(post_ch)*0x10))
#define SOC_DACC_AAE_WDMA_INFO_REG_ADDR(base) ((base) + (0x0e00))
#define SOC_DACC_AAE_WDMA_LB_INFO_REG_ADDR(base) ((base) + (0x0e04))
#define SOC_DACC_AAE_ITF1_INFO_REG_ADDR(base) ((base) + (0x0e08))
#define SOC_DACC_AAE_ITF1_LB_INFO_REG_ADDR(base) ((base) + (0x0e0c))
#define SOC_DACC_AAE_ITF2_INFO_REG_ADDR(base) ((base) + (0x0e10))
#define SOC_DACC_AAE_ITF2_LB_INFO_REG_ADDR(base) ((base) + (0x0e14))
#define SOC_DACC_AAE_WCH0_INFO_REG_ADDR(base) ((base) + (0x0e18))
#define SOC_DACC_AAE_WCH0_LB_INFO_REG_ADDR(base) ((base) + (0x0e1c))
#define SOC_DACC_AAE_WCH1_INFO_REG_ADDR(base) ((base) + (0x0e20))
#define SOC_DACC_AAE_WCH1_LB_INFO_REG_ADDR(base) ((base) + (0x0e24))
#define SOC_DACC_AAE_CMDLIST_CH_PENDING_CLR_ADDR(base,i) ((base) + (0x0000+0x40*(i)))
#define SOC_DACC_AAE_CMDLIST_CH_CTRL_ADDR(base,i) ((base) + (0x0004+0x40*(i)))
#define SOC_DACC_AAE_CMDLIST_CH_STATUS_ADDR(base,i) ((base) + (0x0008+0x40*(i)))
#define SOC_DACC_AAE_CMDLIST_CH_STAAD_ADDR(base,i) ((base) + (0x000C+0x40*(i)))
#define SOC_DACC_AAE_CMDLIST_CH_CURAD_ADDR(base,i) ((base) + (0x0010+0x40*(i)))
#define SOC_DACC_AAE_CMDLIST_CH_INTE_ADDR(base,i) ((base) + (0x0014+0x40*(i)))
#define SOC_DACC_AAE_CMDLIST_CH_INTC_ADDR(base,i) ((base) + (0x0018+0x40*(i)))
#define SOC_DACC_AAE_CMDLIST_CH_INTS_ADDR(base,i) ((base) + (0x001C+0x40*(i)))
#define SOC_DACC_AAE_CMDLIST_CH_DBG_ADDR(base,i) ((base) + (0x0028+0x40*(i)))
#define SOC_DACC_AAE_CMDLIST_DBG_ADDR(base) ((base) + (0x0700))
#define SOC_DACC_AAE_BUF_DBG_EN_ADDR(base) ((base) + (0x0704))
#define SOC_DACC_AAE_BUF_DBG_CNT_CLR_ADDR(base) ((base) + (0x0708))
#define SOC_DACC_AAE_BUF_DBG_CNT_ADDR(base) ((base) + (0x070C))
#define SOC_DACC_AAE_CMDLIST_TIMEOUT_TH_ADDR(base) ((base) + (0x0710))
#define SOC_DACC_AAE_CMDLIST_START_ADDR(base) ((base) + (0x0714))
#define SOC_DACC_AAE_CMDLIST_ADDR_MASK_EN_ADDR(base) ((base) + (0x0718))
#define SOC_DACC_AAE_CMDLIST_ADDR_MASK_DIS_ADDR(base) ((base) + (0x071C))
#define SOC_DACC_AAE_CMDLIST_ADDR_MASK_STATUS_ADDR(base) ((base) + (0x0720))
#define SOC_DACC_AAE_CMDLIST_TASK_CONTINUE_ADDR(base) ((base) + (0x0724))
#define SOC_DACC_AAE_CMDLIST_TASK_STATUS_ADDR(base) ((base) + (0x0728))
#define SOC_DACC_AAE_CMDLIST_CTRL_ADDR(base) ((base) + (0x072C))
#define SOC_DACC_AAE_CMDLIST_SECU_ADDR(base) ((base) + (0x0730))
#define SOC_DACC_AAE_CMDLIST_INTS_ADDR(base) ((base) + (0x0734))
#define SOC_DACC_AAE_CMDLIST_SWRST_ADDR(base) ((base) + (0x0738))
#define SOC_DACC_AAE_CMD_MEM_CTRL_ADDR(base) ((base) + (0x073C))
#define SOC_DACC_AAE_CMD_CLK_SEL_ADDR(base) ((base) + (0x0740))
#define SOC_DACC_AAE_CMD_CLK_EN_ADDR(base) ((base) + (0x0744))
#define SOC_DACC_AAE_CMD_SW_RELOAD_PROT_ADDR(base) ((base) + (0x0748))
#define SOC_DACC_AAE_CMD_SYNC_MODE_ADDR(base) ((base) + (0x074C))
#define SOC_DACC_AAE_CMD_CFG_FLAG_ADDR(base) ((base) + (0x0750))
#define SOC_DACC_AAE_CMD_SYNC_DBG_ADDR(base) ((base) + (0x0754))
#define SOC_DACC_AAE_CH0_CFG_TIME_EN_ADDR(base) ((base) + (0x0758))
#define SOC_DACC_AAE_CH0_CFG_TIME_CNT_ADDR(base) ((base) + (0x077C))
#define SOC_DACC_AAE_SCE0_CFG_SIGNAL_ADDR(base) ((base) + (0x0780))
#define SOC_DACC_AAE_SCE1_CFG_SIGNAL_ADDR(base) ((base) + (0x0784))
#define SOC_DACC_AAE_SCE2_CFG_SIGNAL_ADDR(base) ((base) + (0x0788))
#define SOC_DACC_AAE_SCE3_CFG_SIGNAL_ADDR(base) ((base) + (0x078c))
#define SOC_DACC_AAE_SCE4_CFG_SIGNAL_ADDR(base) ((base) + (0x0790))
#define SOC_DACC_AAE_SCE5_CFG_SIGNAL_ADDR(base) ((base) + (0x0794))
#define SOC_DACC_AAE_SCE6_CFG_SIGNAL_ADDR(base) ((base) + (0x0798))
#define SOC_DACC_AAE_LBUSIF_MSTATE_ADDR(base) ((base) + (0x079c))
#define SOC_DACC_AAE_TWO_SAME_FRAME_BYPASS_ADDR(base) ((base) + (0x07a0))
#define SOC_DACC_AAE_CMDLIST_CH8_STAAD_ADDR(base) ((base) + (0x07a4))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sw_ext_ints : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DACC_AAE_SW_EXT_INT_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sw_ext_ints_mask : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DACC_AAE_SW_EXT_INT_MASK_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_rst_pc : 32;
    } reg;
} SOC_DACC_AAE_POR_RESET_PC_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_hart_id : 4;
        unsigned int core_wait : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_DACC_AAE_CORE_CONFIG_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_sleep_mode : 1;
        unsigned int core_debug_mode : 1;
        unsigned int core_hard_fault_mode : 1;
        unsigned int core_in_nmi_handle : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_DACC_AAE_CORE_STATUS_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_mon_pc : 32;
    } reg;
} SOC_DACC_AAE_CORE_MON_PC_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int core_mon_lr : 32;
    } reg;
} SOC_DACC_AAE_CORE_MON_LR_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_trans_start_addr : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_DACC_AAE_DMA_TRANS_START_ADDR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_trans_word_num : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_DACC_AAE_DMA_TRANS_WORD_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_trans_start : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DACC_AAE_DMA_TRANS_START_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mod_end_int_mask : 32;
    } reg;
} SOC_DACC_AAE_MOD_END_INT_MASK_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int te_0_mask : 1;
        unsigned int te_1_mask : 1;
        unsigned int dcmd_para_dma_mask : 1;
        unsigned int hts_slave_err_mask : 1;
        unsigned int hts_master_err_mask : 1;
        unsigned int hts_slave_int_mask : 1;
        unsigned int acpu_clear_mask : 1;
        unsigned int clear_ack_mask : 1;
        unsigned int doze_lfc_quit_mask : 1;
        unsigned int online_cld_int_mask : 4;
        unsigned int online_underflow_int_mask : 4;
        unsigned int scl_end_int_mask : 1;
        unsigned int ffap1_wkup_int_mask : 1;
        unsigned int ffap1_misc_int_mask : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_DACC_AAE_MISC_INT_MASK_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mod_exit_mem_ds : 32;
    } reg;
} SOC_DACC_AAE_MOD_EXIT_MEM_DS_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arsr0_end_int_clr : 1;
        unsigned int arsr1_end_int_clr : 1;
        unsigned int vscf0_end_int_clr : 1;
        unsigned int vscf1_end_int_clr : 1;
        unsigned int uvup_end_int_clr : 1;
        unsigned int aihdr_end_int_clr : 1;
        unsigned int scf2d0_end_int_clr : 1;
        unsigned int scf2d1_end_int_clr : 1;
        unsigned int wdfc_end_int_clr : 1;
        unsigned int blpp_end_int_clr : 1;
        unsigned int blur_end_int_clr : 1;
        unsigned int cld_end_int_clr : 1;
        unsigned int hiof_end_int_clr : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 16;
        unsigned int s4_bot_clip_end_int_clr : 1;
    } reg;
} SOC_DACC_AAE_MOD_END_INT_CLR_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov_int_0_clr : 1;
        unsigned int ov_int_1_clr : 1;
        unsigned int ov_int_2_clr : 1;
        unsigned int ov_int_3_clr : 1;
        unsigned int timer_0_clr : 1;
        unsigned int timer_1_clr : 1;
        unsigned int timer_2_clr : 1;
        unsigned int timer_3_clr : 1;
        unsigned int scene_0_clear_clr : 1;
        unsigned int scene_1_clear_clr : 1;
        unsigned int scene_2_clear_clr : 1;
        unsigned int scene_3_clear_clr : 1;
        unsigned int scene_4_clear_clr : 1;
        unsigned int scene_5_clear_clr : 1;
        unsigned int scene_6_clear_clr : 1;
        unsigned int hts_slave_err_clr : 1;
        unsigned int hts_master_err_clr : 1;
        unsigned int hts_slave_int_clr : 1;
        unsigned int online_cld_int_clr : 4;
        unsigned int online_underflow_int_clr : 4;
        unsigned int timer_4_clr : 1;
        unsigned int timer_5_clr : 1;
        unsigned int timer_6_clr : 1;
        unsigned int ffap1_wkup_int_clr : 1;
        unsigned int ffap1_misc_int_clr : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_DACC_AAE_MISC_INT_CLR_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int riscv_2_acpu_info : 32;
    } reg;
} SOC_DACC_AAE_RISCV_2_ACPU_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p2h_ckg_en : 1;
        unsigned int h2p_ckg_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DACC_AAE_MINIBUS_1T01_CKG_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int p2h_idle : 1;
        unsigned int h2p_idle : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DACC_AAE_MINIBUS_1T01_STATE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ckg_en : 1;
        unsigned int tcxo_dbg_counter_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_DACC_AAE_CKG_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int demura_lut_layer_id : 5;
        unsigned int demura_lut_en : 1;
        unsigned int deburnin_lut_layer_id : 5;
        unsigned int deburnin_lut_en : 1;
        unsigned int od_lut_layer_id : 5;
        unsigned int od_lut_en : 1;
        unsigned int idle_display_en : 1;
        unsigned int reserved_0 : 5;
        unsigned int aihdr_grid_layer_id : 5;
        unsigned int aihdr_grid_en : 1;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_DACC_AAE_LUT_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_sctrl_doze1_entry : 1;
        unsigned int cfg_sctrl_doze1_wake : 1;
        unsigned int dss_clk_gate_on : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_DACC_AAE_LP_DOZE_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int acpu_2_riscv_intr_trig : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DACC_AAE_ACPU_2_RISCV_INTR_TRIG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int acpu_2_riscv_intr_mask : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DACC_AAE_ACPU_2_RISCV_INTR_MASK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int acpu_2_riscv_intr_clr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DACC_AAE_ACPU_2_RISCV_INTR_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wb_source_sel : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_DACC_AAE_WB_SOURCE_SEL_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcxo_dbg_counter : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_DACC_AAE_TCXO_CNTER_VALUE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cld_refresh_line_num : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_DACC_AAE_CLD_REFRESH_LINE_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lbus_mask_en : 1;
        unsigned int dacc_idle_flag : 1;
        unsigned int dacc_idle_flag_mask : 1;
        unsigned int reserved : 13;
        unsigned int bitmasken : 16;
    } reg;
} SOC_DACC_AAE_RISCV_CFG_MISC_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmdlist_va_h7 : 7;
        unsigned int reserved_0 : 1;
        unsigned int ssid_num : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_DACC_AAE_SSID_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int version_id : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_DACC_AAE_VER_ID_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sw_cmd_reg0 : 32;
    } reg;
} SOC_DACC_AAE_SW_CMD_REG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sw_cmd_reg1 : 32;
    } reg;
} SOC_DACC_AAE_SW_CMD_REG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmd_buf_num : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_DACC_AAE_CMD_BUF_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sw_cmd_tx : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DACC_AAE_SW_CMD_TX_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dacc_clk_sel : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DACC_AAE_CLK_SEL_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dacc_clk_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DACC_AAE_CLK_EN_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int new_frame_rdy_cfg : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DACC_AAE_NEW_FRAME_RDY_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctl_sw_reload_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DACC_AAE_CTL_SW_EN_RELOAD_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int riscv_cfg_over : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DACC_AAE_RISCV_CFG_OVER_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctl_sw_intr_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DACC_AAE_CTL_SW_INTR_EN_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctl_cfg_mode : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DACC_AAE_CTL_CFG_MODE0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_rd_shadow_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DACC_AAE_CFG_RD_SHADOW_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctl_clear_timeout_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DACC_AAE_CTL_CLEAR_TIMEOUT_EN_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int acpu_2_riscv_log_info : 32;
    } reg;
} SOC_DACC_AAE_ACPU_2_RISCV_LOG_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int riscv_2_acpu_log_info : 32;
    } reg;
} SOC_DACC_AAE_RISCV_2_ACPU_LOG_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scmd_start : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DACC_AAE_SCMD_START_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dcmd_start : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DACC_AAE_DCMD_START_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int acpu_para_addr : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_DACC_AAE_ACPU_PARA_ADDR_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int riscv_para_addr : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_DACC_AAE_RISCV_PARA_ADDR_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_dim_flag : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DACC_AAE_LAYER_DIM_FLAG_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int general_cfg_0 : 32;
    } reg;
} SOC_DACC_AAE_GENERAL_CFG_0_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int general_cfg_1 : 32;
    } reg;
} SOC_DACC_AAE_GENERAL_CFG_1_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dcmd_ints_mask : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DACC_AAE_DCMD_INTS_MASK_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dcmd_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DACC_AAE_DCMD_STATUS_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pixel_layer_num : 5;
        unsigned int reserved_0 : 3;
        unsigned int lut_layer_num : 2;
        unsigned int reserved_1 : 22;
    } reg;
} SOC_DACC_AAE_LAYER_NUM_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctl_sw_start : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DACC_AAE_CTL_SW_START_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int riscv_cfg_xpu_ints : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DACC_AAE_RISCV_CFG_XPU_INT_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int riscv_cfg_xpu_ints_mask : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DACC_AAE_RISCV_CFG_XPU_INT_MASK_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int xpu_cfg_riscv_ints : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DACC_AAE_XPU_CFG_RISCV_INT_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int xpu_cfg_riscv_ints_clr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DACC_AAE_XPU_CFG_RISCV_INT_CLR_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int xpu_cfg_riscv_ints_mask : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_DACC_AAE_XPU_CFG_RISCV_INT_MASK_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int xpu_riscv_comm_info_0 : 32;
    } reg;
} SOC_DACC_AAE_XPU_RISCV_COMM_INFO_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int xpu_riscv_comm_info_1 : 32;
    } reg;
} SOC_DACC_AAE_XPU_RISCV_COMM_INFO_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_0_info : 32;
    } reg;
} SOC_DACC_AAE_DBG_0_INFO_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_1_info : 32;
    } reg;
} SOC_DACC_AAE_DBG_1_INFO_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_2_info : 32;
    } reg;
} SOC_DACC_AAE_DBG_2_INFO_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_3_info : 32;
    } reg;
} SOC_DACC_AAE_DBG_3_INFO_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_4_info : 32;
    } reg;
} SOC_DACC_AAE_DBG_4_INFO_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_5_info : 32;
    } reg;
} SOC_DACC_AAE_DBG_5_INFO_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov_w_linereg_cnt_s0 : 3;
        unsigned int ov_w_linereg_flag_s0 : 1;
        unsigned int ov_wtotal_s0 : 6;
        unsigned int reserved : 21;
        unsigned int pre_wr_minus_one : 1;
    } reg;
} SOC_DACC_AAE_OV_WR_LINEREG_S0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov_r_linereg_cnt_s0 : 3;
        unsigned int ov_r_linereg_flag_s0 : 1;
        unsigned int ov_rtotal_s0 : 6;
        unsigned int reserved_0 : 6;
        unsigned int dma_w_linereg_cnt_y_s0 : 3;
        unsigned int dma_w_linereg_flag_y_s0 : 1;
        unsigned int dma_wtotal_y_s0 : 6;
        unsigned int reserved_1 : 4;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_DACC_AAE_LAYER_LB_PARA0_S0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_w_linereg_cnt_v_s0 : 3;
        unsigned int dma_w_linereg_flag_v_s0 : 1;
        unsigned int dma_wtotal_v_s0 : 6;
        unsigned int reserved_0 : 6;
        unsigned int dma_w_linereg_cnt_u_s0 : 3;
        unsigned int dma_w_linereg_flag_u_s0 : 1;
        unsigned int dma_wtotal_u_s0 : 6;
        unsigned int reserved_1 : 4;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_DACC_AAE_LAYER_LB_PARA1_S0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_block_high_s0 : 13;
        unsigned int reserved_0 : 3;
        unsigned int dma_block_width_s0 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_DACC_AAE_LAYER_LB_PARA2_S0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_input_img_height_s0 : 14;
        unsigned int reserved_0 : 2;
        unsigned int pre_input_img_width_s0 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_DACC_AAE_LAYER_INFO_IN_S0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_output_img_height_s0 : 14;
        unsigned int reserved_0 : 2;
        unsigned int pre_output_img_width_s0 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_DACC_AAE_LAYER_INFO_OUT_S0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bottom_clip_value_s0 : 7;
        unsigned int reserved_0 : 1;
        unsigned int top_clip_value_s0 : 7;
        unsigned int reserved_1 : 1;
        unsigned int right_clip_value_s0 : 7;
        unsigned int reserved_2 : 1;
        unsigned int left_clip_value_s0 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_DACC_AAE_LAYER_CLIP_INFO_S0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int input_format_s0 : 6;
        unsigned int output_format_s0 : 6;
        unsigned int first_mod_idx_s0 : 6;
        unsigned int linereg_start_idx_s0 : 14;
    } reg;
} SOC_DACC_AAE_LAYER_LB_INFO_S0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov_w_linereg_cnt_s1 : 3;
        unsigned int ov_w_linereg_flag_s1 : 1;
        unsigned int ov_wtotal_s1 : 6;
        unsigned int reserved : 22;
    } reg;
} SOC_DACC_AAE_OV_WR_LINEREG_S1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov_r_linereg_cnt_s1 : 3;
        unsigned int ov_r_linereg_flag_s1 : 1;
        unsigned int ov_rtotal_s1 : 6;
        unsigned int reserved_0 : 6;
        unsigned int dma_w_linereg_cnt_y_s1 : 3;
        unsigned int dma_w_linereg_flag_y_s1 : 1;
        unsigned int dma_wtotal_y_s1 : 6;
        unsigned int reserved_1 : 4;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_DACC_AAE_LAYER_LB_PARA0_S1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_w_linereg_cnt_v_s1 : 3;
        unsigned int dma_w_linereg_flag_v_s1 : 1;
        unsigned int dma_wtotal_v_s1 : 6;
        unsigned int reserved_0 : 6;
        unsigned int dma_w_linereg_cnt_u_s1 : 3;
        unsigned int dma_w_linereg_flag_u_s1 : 1;
        unsigned int dma_wtotal_u_s1 : 6;
        unsigned int reserved_1 : 4;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_DACC_AAE_LAYER_LB_PARA1_S1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_block_high_s1 : 13;
        unsigned int reserved_0 : 3;
        unsigned int dma_block_width_s1 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_DACC_AAE_LAYER_LB_PARA2_S1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_input_img_height_s1 : 14;
        unsigned int reserved_0 : 2;
        unsigned int pre_input_img_width_s1 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_DACC_AAE_LAYER_INFO_IN_S1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_output_img_height_s1 : 14;
        unsigned int reserved_0 : 2;
        unsigned int pre_output_img_width_s1 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_DACC_AAE_LAYER_INFO_OUT_S1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bottom_clip_value_s1 : 7;
        unsigned int reserved_0 : 1;
        unsigned int top_clip_value_s1 : 7;
        unsigned int reserved_1 : 1;
        unsigned int right_clip_value_s1 : 7;
        unsigned int reserved_2 : 1;
        unsigned int left_clip_value_s1 : 7;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_DACC_AAE_LAYER_CLIP_INFO_S1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int input_format_s1 : 6;
        unsigned int output_format_s1 : 6;
        unsigned int first_mod_idx_s1 : 6;
        unsigned int linereg_start_idx_s1 : 14;
    } reg;
} SOC_DACC_AAE_LAYER_LB_INFO_S1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int total_rd_line_num_s0 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DACC_AAE_TOTAL_RD_LINE_NUM_S0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int total_wr_line_num_s0 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DACC_AAE_TOTAL_WR_LINE_NUM_S0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int total_rd_line_num_s1 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DACC_AAE_TOTAL_RD_LINE_NUM_S1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int total_wr_line_num_s1 : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_DACC_AAE_TOTAL_WR_LINE_NUM_S1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_pipe_no_instr_flag : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DACC_AAE_PRE_PIPE_FLAG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int idle_display_en : 1;
        unsigned int od_wb_en : 1;
        unsigned int ov_wb_en : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_DACC_AAE_SCENE_0_WB_INFO_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_input_img_height : 14;
        unsigned int reserved_0 : 2;
        unsigned int post_input_img_width : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_DACC_AAE_SCENE_RD_INFO_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_output_img_height : 14;
        unsigned int reserved_0 : 2;
        unsigned int post_output_img_width : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_DACC_AAE_SCENE_WR_INFO_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int linereg_r_cnt : 3;
        unsigned int linereg_r_flag : 1;
        unsigned int linereg_rtotal : 6;
        unsigned int input_format : 6;
        unsigned int linereg_rd_start_idx : 15;
        unsigned int ov_wb_en_flag : 1;
    } reg;
} SOC_DACC_AAE_SCENE_LB_R_INFO_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int linereg_w_cnt : 3;
        unsigned int linereg_w_flag : 1;
        unsigned int linereg_wtotal : 6;
        unsigned int output_format : 6;
        unsigned int linereg_wr_start_idx : 15;
        unsigned int ddic_dsc_wb_en_flag : 1;
    } reg;
} SOC_DACC_AAE_SCENE_LB_W_INFO_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int input_img_height_s0 : 14;
        unsigned int reserved_0 : 2;
        unsigned int input_img_width_s0 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_DACC_AAE_WDMA_INFO_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int linereg_r_cnt_s0 : 3;
        unsigned int linereg_r_flag_s0 : 1;
        unsigned int linereg_rtotal_s0 : 6;
        unsigned int input_format_s0 : 6;
        unsigned int linereg_start_idx_s0 : 15;
        unsigned int reserved : 1;
    } reg;
} SOC_DACC_AAE_WDMA_LB_INFO_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int input_img_height_s1 : 14;
        unsigned int reserved_0 : 2;
        unsigned int input_img_width_s1 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_DACC_AAE_ITF1_INFO_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int linereg_r_cnt_s1 : 3;
        unsigned int linereg_r_flag_s1 : 1;
        unsigned int linereg_rtotal_s1 : 6;
        unsigned int input_format_s1 : 6;
        unsigned int linereg_start_idx_s1 : 15;
        unsigned int reserved : 1;
    } reg;
} SOC_DACC_AAE_ITF1_LB_INFO_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int input_img_height_s2 : 14;
        unsigned int reserved_0 : 2;
        unsigned int input_img_width_s2 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_DACC_AAE_ITF2_INFO_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int linereg_r_cnt_s2 : 3;
        unsigned int linereg_r_flag_s2 : 1;
        unsigned int linereg_rtotal_s2 : 6;
        unsigned int input_format_s2 : 6;
        unsigned int linereg_start_idx_s2 : 15;
        unsigned int reserved : 1;
    } reg;
} SOC_DACC_AAE_ITF2_LB_INFO_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int input_img_height_w0 : 14;
        unsigned int reserved_0 : 2;
        unsigned int input_img_width_w0 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_DACC_AAE_WCH0_INFO_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int linereg_r_cnt_w0 : 3;
        unsigned int linereg_r_flag_w0 : 1;
        unsigned int linereg_rtotal_w0 : 6;
        unsigned int input_format_w0 : 6;
        unsigned int linereg_start_idx_w0 : 15;
        unsigned int reserved : 1;
    } reg;
} SOC_DACC_AAE_WCH0_LB_INFO_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int input_img_height_w1 : 14;
        unsigned int reserved_0 : 2;
        unsigned int input_img_width_w1 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_DACC_AAE_WCH1_INFO_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int linereg_r_cnt_w1 : 3;
        unsigned int linereg_r_flag_w1 : 1;
        unsigned int linereg_rtotal_w1 : 6;
        unsigned int input_format_w1 : 6;
        unsigned int linereg_start_idx_w1 : 15;
        unsigned int reserved : 1;
    } reg;
} SOC_DACC_AAE_WCH1_LB_INFO_REG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_pending_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DACC_AAE_CMDLIST_CH_PENDING_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_enable : 1;
        unsigned int ch_auto_single : 1;
        unsigned int ch_start_sel : 3;
        unsigned int ch_pause : 1;
        unsigned int ch_scene_sel : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_DACC_AAE_CMDLIST_CH_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_ctl_fsm : 4;
        unsigned int reserved : 4;
        unsigned int ch_dma_fsm : 2;
        unsigned int ch_idle : 1;
        unsigned int oa_idle : 1;
        unsigned int ch_cmd_done_id : 10;
        unsigned int ch_cmd_id : 10;
    } reg;
} SOC_DACC_AAE_CMDLIST_CH_STATUS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int ch_start_addr : 28;
    } reg;
} SOC_DACC_AAE_CMDLIST_CH_STAAD_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_cnt : 4;
        unsigned int ch_curr_addr : 28;
    } reg;
} SOC_DACC_AAE_CMDLIST_CH_CURAD_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_onedone_inte : 1;
        unsigned int ch_alldone_inte : 1;
        unsigned int ch_axi_err_inte : 1;
        unsigned int ch_pending_inte : 1;
        unsigned int ch_start_inte : 1;
        unsigned int ch_badcmd_inte : 1;
        unsigned int ch_timeout_inte : 1;
        unsigned int ch_taskdone_inte : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_DACC_AAE_CMDLIST_CH_INTE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_onedone_intc : 1;
        unsigned int ch_alldone_intc : 1;
        unsigned int ch_axi_err_intc : 1;
        unsigned int ch_pending_intc : 1;
        unsigned int ch_start_intc : 1;
        unsigned int ch_badcmd_intc : 1;
        unsigned int ch_timeout_intc : 1;
        unsigned int ch_taskdone_intc : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_DACC_AAE_CMDLIST_CH_INTC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_onedone_ints : 1;
        unsigned int ch_alldone_ints : 1;
        unsigned int ch_axi_err_ints : 1;
        unsigned int ch_pending_ints : 1;
        unsigned int ch_start_ints : 1;
        unsigned int ch_badcmd_ints : 1;
        unsigned int ch_timeout_ints : 1;
        unsigned int ch_taskdone_ints : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_DACC_AAE_CMDLIST_CH_INTS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmd_dbg0 : 1;
        unsigned int cmd_dbg1 : 1;
        unsigned int cmd_dbg2 : 1;
        unsigned int cmd_dbg3 : 1;
        unsigned int cmd_dbg4 : 1;
        unsigned int cmd_dbg5 : 1;
        unsigned int cmd_dbg6 : 1;
        unsigned int cmd_dbg7 : 1;
        unsigned int cmd_dbg8 : 1;
        unsigned int cmd_dbg9 : 1;
        unsigned int cmd_dbg10 : 1;
        unsigned int cmd_dbg11 : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_DACC_AAE_CMDLIST_CH_DBG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmd_axi_dbg : 32;
    } reg;
} SOC_DACC_AAE_CMDLIST_DBG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int buf_dbg_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DACC_AAE_BUF_DBG_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int buf_dbg_cnt_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DACC_AAE_BUF_DBG_CNT_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int buf_dbg_cnt_th : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_DACC_AAE_BUF_DBG_CNT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int timeout_th : 32;
    } reg;
} SOC_DACC_AAE_CMDLIST_TIMEOUT_TH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int start : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_DACC_AAE_CMDLIST_START_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mask_en : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_DACC_AAE_CMDLIST_ADDR_MASK_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mask_dis : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_DACC_AAE_CMDLIST_ADDR_MASK_DIS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int addr_mask_status : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_DACC_AAE_CMDLIST_ADDR_MASK_STATUS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_continue : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_DACC_AAE_CMDLIST_TASK_CONTINUE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int task_status : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_DACC_AAE_CMDLIST_TASK_STATUS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_mid : 4;
        unsigned int axi_qos : 2;
        unsigned int axi_mainpress : 2;
        unsigned int axi_outstd_depth : 4;
        unsigned int buf0_outstd_depth : 2;
        unsigned int buf1_outstd_depth : 2;
        unsigned int buf2_outstd_depth : 2;
        unsigned int buf3_outstd_depth : 2;
        unsigned int buf4_outstd_depth : 2;
        unsigned int buf5_outstd_depth : 2;
        unsigned int buf6_outstd_depth : 2;
        unsigned int reserved : 6;
    } reg;
} SOC_DACC_AAE_CMDLIST_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_secu : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_DACC_AAE_CMDLIST_SECU_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_ints : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_DACC_AAE_CMDLIST_INTS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_swreset : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_DACC_AAE_CMDLIST_SWRST_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmd_mem_ctrl : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_DACC_AAE_CMD_MEM_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmd_clk_sel : 32;
    } reg;
} SOC_DACC_AAE_CMD_CLK_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmd_clk_en : 32;
    } reg;
} SOC_DACC_AAE_CMD_CLK_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmd_sw_reload_prot : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DACC_AAE_CMD_SW_RELOAD_PROT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmd_sync_mode : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DACC_AAE_CMD_SYNC_MODE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmd_cfg_flag : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DACC_AAE_CMD_CFG_FLAG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmd_sync_dbg : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_DACC_AAE_CMD_SYNC_DBG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_cfg_time_en0 : 1;
        unsigned int ch_cfg_time_en1 : 1;
        unsigned int ch_cfg_time_en2 : 1;
        unsigned int ch_cfg_ch_id : 4;
        unsigned int reserved_0 : 1;
        unsigned int ch_cfg_time_node_id : 10;
        unsigned int reserved_1 : 14;
    } reg;
} SOC_DACC_AAE_CH0_CFG_TIME_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_cfg_time_cnt : 32;
    } reg;
} SOC_DACC_AAE_CH0_CFG_TIME_CNT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sce0_scene_fsm_cs : 4;
        unsigned int sce0_dma_fsm_cs : 3;
        unsigned int reserved_0 : 1;
        unsigned int sce0_fifo_empty : 1;
        unsigned int reserved_1 : 3;
        unsigned int sce0_buf_empty : 1;
        unsigned int reserved_2 : 3;
        unsigned int sce0_dcpt_fsm : 2;
        unsigned int reserved_3 : 2;
        unsigned int sce0_dcpt_fifo_empty : 1;
        unsigned int reserved_4 : 3;
        unsigned int sce0_dm_cnt : 8;
    } reg;
} SOC_DACC_AAE_SCE0_CFG_SIGNAL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sce1_scene_fsm_cs : 4;
        unsigned int sce1_dma_fsm_cs : 3;
        unsigned int reserved_0 : 1;
        unsigned int sce1_fifo_empty : 1;
        unsigned int reserved_1 : 3;
        unsigned int sce1_buf_empty : 1;
        unsigned int reserved_2 : 3;
        unsigned int sce1_dcpt_fsm : 2;
        unsigned int reserved_3 : 2;
        unsigned int sce1_dcpt_fifo_empty : 1;
        unsigned int reserved_4 : 3;
        unsigned int sce1_dm_cnt : 8;
    } reg;
} SOC_DACC_AAE_SCE1_CFG_SIGNAL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sce2_scene_fsm_cs : 4;
        unsigned int sce2_dma_fsm_cs : 3;
        unsigned int reserved_0 : 1;
        unsigned int sce2_fifo_empty : 1;
        unsigned int reserved_1 : 3;
        unsigned int sce2_buf_empty : 1;
        unsigned int reserved_2 : 3;
        unsigned int sce2_dcpt_fsm : 2;
        unsigned int reserved_3 : 2;
        unsigned int sce2_dcpt_fifo_empty : 1;
        unsigned int reserved_4 : 3;
        unsigned int sce2_dm_cnt : 8;
    } reg;
} SOC_DACC_AAE_SCE2_CFG_SIGNAL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sce3_scene_fsm_cs : 4;
        unsigned int sce3_dma_fsm_cs : 3;
        unsigned int reserved_0 : 1;
        unsigned int sce3_fifo_empty : 1;
        unsigned int reserved_1 : 3;
        unsigned int sce3_buf_empty : 1;
        unsigned int reserved_2 : 3;
        unsigned int sce3_dcpt_fsm : 2;
        unsigned int reserved_3 : 2;
        unsigned int sce3_dcpt_fifo_empty : 1;
        unsigned int reserved_4 : 3;
        unsigned int sce3_dm_cnt : 8;
    } reg;
} SOC_DACC_AAE_SCE3_CFG_SIGNAL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sce4_scene_fsm_cs : 4;
        unsigned int sce4_dma_fsm_cs : 3;
        unsigned int reserved_0 : 1;
        unsigned int sce4_fifo_empty : 1;
        unsigned int reserved_1 : 3;
        unsigned int sce4_buf_empty : 1;
        unsigned int reserved_2 : 3;
        unsigned int sce4_dcpt_fsm : 2;
        unsigned int reserved_3 : 2;
        unsigned int sce4_dcpt_fifo_empty : 1;
        unsigned int reserved_4 : 3;
        unsigned int sce4_dm_cnt : 8;
    } reg;
} SOC_DACC_AAE_SCE4_CFG_SIGNAL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sce5_scene_fsm_cs : 4;
        unsigned int sce5_dma_fsm_cs : 3;
        unsigned int reserved_0 : 1;
        unsigned int sce5_fifo_empty : 1;
        unsigned int reserved_1 : 3;
        unsigned int sce5_buf_empty : 1;
        unsigned int reserved_2 : 3;
        unsigned int sce5_dcpt_fsm : 2;
        unsigned int reserved_3 : 2;
        unsigned int sce5_dcpt_fifo_empty : 1;
        unsigned int reserved_4 : 3;
        unsigned int sce5_dm_cnt : 8;
    } reg;
} SOC_DACC_AAE_SCE5_CFG_SIGNAL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sce6_scene_fsm_cs : 4;
        unsigned int sce6_dma_fsm_cs : 3;
        unsigned int reserved_0 : 1;
        unsigned int sce6_fifo_empty : 1;
        unsigned int reserved_1 : 3;
        unsigned int sce6_buf_empty : 1;
        unsigned int reserved_2 : 3;
        unsigned int sce6_dcpt_fsm : 2;
        unsigned int reserved_3 : 2;
        unsigned int sce6_dcpt_fifo_empty : 1;
        unsigned int reserved_4 : 3;
        unsigned int sce6_dm_cnt : 8;
    } reg;
} SOC_DACC_AAE_SCE6_CFG_SIGNAL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lbusif_mstate : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_DACC_AAE_LBUSIF_MSTATE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int two_same_frame_bypass : 1;
        unsigned int scene_dacc_int_ctrl : 7;
        unsigned int scene_int_delay_cycle : 6;
        unsigned int reserved : 18;
    } reg;
} SOC_DACC_AAE_TWO_SAME_FRAME_BYPASS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int ch8_start_addr : 28;
    } reg;
} SOC_DACC_AAE_CMDLIST_CH8_STAAD_UNION;
#endif
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
