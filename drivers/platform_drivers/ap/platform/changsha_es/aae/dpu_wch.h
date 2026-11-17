#ifndef AAE_ROT_WDMA_H
#define AAE_ROT_WDMA_H 
#include "soc_aae_interface.h"
#include "soc_dpu_define.h"
enum wch_num_idx {
 WCH_0 = 0,
 WCH_1,
 WCH_2,
};
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_ptr0_h: 8;
        unsigned int reserved : 24;
    } reg;
} AAE_ROT_WDMA_DMA_PTR0_H_UNION;
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_ptr1_h: 8;
        unsigned int reserved : 24;
    } reg;
} AAE_ROT_WDMA_DMA_PTR1_H_UNION;
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_ptr2_h: 8;
        unsigned int reserved : 24;
    } reg;
} AAE_ROT_WDMA_DMA_PTR2_H_UNION;
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_ptr3_h: 8;
        unsigned int reserved : 24;
    } reg;
} AAE_ROT_WDMA_DMA_PTR3_H_UNION;
#endif
struct dpu_wch_wdma {
 AAE_ROT_WDMA_DMA_CTRL0_UNION dma_ctrl0;
 AAE_ROT_WDMA_DMA_CTRL1_UNION dma_ctrl1;
 AAE_ROT_WDMA_DMA_IMG_SIZE_UNION dma_img_size;
 AAE_ROT_WDMA_DMA_PTR0_UNION dma_ptr0;
 AAE_ROT_WDMA_DMA_STRIDE0_UNION dma_stride0;
 AAE_ROT_WDMA_DMA_PTR1_UNION dma_ptr1;
 AAE_ROT_WDMA_DMA_STRIDE1_UNION dma_stride1;
 AAE_ROT_WDMA_DMA_PTR2_UNION dma_ptr2;
 AAE_ROT_WDMA_DMA_STRIDE2_UNION dma_stride2;
 AAE_ROT_WDMA_DMA_PTR3_UNION dma_ptr3;
 AAE_ROT_WDMA_DMA_STRIDE3_UNION dma_stride3;
 AAE_ROT_WDMA_DMA_CMP_HDR_PTR_OFT_UNION dma_cmp_hdr_ptr_oft;
 AAE_ROT_WDMA_DMA_CH_SEGMENT_CTRL_UNION dma_ch_segment_ctrl;
 AAE_ROT_WDMA_DMA_CMP_CTRL_UNION dma_cmp_ctrl;
 AAE_ROT_WDMA_DMA_CMP_PIC_BLKS_UNION dma_cmp_pic_blks;
 AAE_ROT_WDMA_DMA_CMP_MEM_CTRL0_UNION dma_cmp_mem_ctrl0;
 AAE_ROT_WDMA_DMA_CMP_MEM_CTRL1_UNION dma_cmp_mem_ctrl1;
 AAE_ROT_WDMA_DMA_CMP_RESEVED_UNION dma_cmp_reserved;
 AAE_ROT_WDMA_DMA_CMP_INFO_OUT0_UNION dma_cmp_inf0_out0;
 AAE_ROT_WDMA_DMA_CMP_INFO_OUT1_UNION dma_cmp_inf0_out1;
 AAE_ROT_WDMA_DMA_INTR_UNION dma_intr;
 AAE_ROT_WDMA_DMA_RSV_IN0_UNION dma_rsv_in0;
 AAE_ROT_WDMA_DMA_RSV_IN1_UNION dma_rsv_in1;
 AAE_ROT_WDMA_DMA_RSV_IN2_UNION dma_rsv_in2;
 AAE_ROT_WDMA_DMA_RSV_IN3_UNION dma_rsv_in3;
 AAE_ROT_WDMA_DMA_MONITOR_OUT0_UNION dma_monitor_out0;
 AAE_ROT_WDMA_DMA_MONITOR_OUT1_UNION dma_monitor_out1;
 AAE_ROT_WDMA_DMA_MONITOR_OUT2_UNION dma_monitor_out2;
 AAE_ROT_WDMA_DMA_MONITOR_OUT3_UNION dma_monitor_out3;
 AAE_ROT_WDMA_DMA_MONITOR_OUT4_UNION dma_monitor_out4;
 AAE_ROT_WDMA_DMA_MONITOR_OUT5_UNION dma_monitor_out5;
 AAE_ROT_WDMA_DMA_PTR0_H_UNION dma_ptr0_h;
 AAE_ROT_WDMA_DMA_PTR1_H_UNION dma_ptr1_h;
 AAE_ROT_WDMA_DMA_PTR2_H_UNION dma_ptr2_h;
 AAE_ROT_WDMA_DMA_PTR3_H_UNION dma_ptr3_h;
};
struct dpu_wch_wlt {
 AAE_ROT_WDMA_WTL_CTRL_UNION wlt_ctrl;
 AAE_ROT_WDMA_WLT_LINE_THRESHOLD1_UNION wlt_line_threshold1;
 AAE_ROT_WDMA_WLT_LINE_THRESHOLD3_UNION wlt_line_threshold3;
 AAE_ROT_WDMA_WLT_BASE_LINE_OFFSET_UNION wlt_base_line_offset;
 AAE_ROT_WDMA_WLT_DMA_ADDR_UNION wlt_dma_addr;
 AAE_ROT_WDMA_WLT_DMA_QOS_UNION wlt_dma_qos;
 AAE_ROT_WDMA_WLT_C_LINE_NUM_UNION wlt_c_line_num;
 AAE_ROT_WDMA_WLT_C_SLICE_NUM_UNION wlt_c_slice_num;
};
struct dpu_wch_reg {
 AAE_ROT_WDMA_REG_DEFAULT_UNION reg_default;
 AAE_ROT_WDMA_CH_RD_SHADOW_UNION ch_rd_shadow;
 AAE_ROT_WDMA_CH_CTL_UNION ch_ctl;
 AAE_ROT_WDMA_CH_SECU_EN_UNION ch_secu_en;
 AAE_ROT_WDMA_CH_SW_END_REQ_UNION ch_sw_end_req;
 AAE_ROT_WDMA_CH_CLK_SEL_UNION ch_clk_sel;
 AAE_ROT_WDMA_CH_CLK_EN_UNION ch_clk_en;
 AAE_ROT_WDMA_CH_DBG0_UNION ch_dbg0;
 AAE_ROT_WDMA_CH_DBG1_UNION ch_dbg1;
 AAE_ROT_WDMA_CH_DBG2_UNION ch_dbg2;
 AAE_ROT_WDMA_CH_DBG3_UNION ch_dbg3;
 AAE_ROT_WDMA_CH_DBG4_UNION ch_dbg4;
 AAE_ROT_WDMA_CH_DBG5_UNION ch_dbg5;
 AAE_ROT_WDMA_FRM_END_WCH_DELAY_UNION frm_end_wch_delay;
};
struct dpu_wch_rot {
 AAE_ROT_WDMA_ROT_FIRST_LNS_UNION rot_first_lns;
 AAE_ROT_WDMA_ROT_STATE_UNION rot_state;
 AAE_ROT_WDMA_ROT_MEM_CTRL_UNION rot_mem_ctrl;
 AAE_ROT_WDMA_ROT_SIZE_UNION rot_size;
 AAE_ROT_WDMA_ROT_422_MODE_UNION rot_422_mode;
 AAE_ROT_WDMA_ROT_BYPASS_UNION rot_bypass;
};
struct dpu_wch_debug {
 AAE_ROT_WDMA_CH_DEBUG_SEL_UNION ch_debug_sel;
 AAE_ROT_WDMA_DMA_ADDR_EXT_UNION dma_addr_ext;
};
struct dpu_wch_wrap_ctrl {
 AAE_ROT_WDMA_REG_CTRL_UNION reg_ctrl;
 AAE_ROT_WDMA_REG_CTRL_FLUSH_EN_UNION reg_ctrl_flush_en;
 AAE_ROT_WDMA_REG_CTRL_DEBUG_UNION reg_ctrl_debug;
 AAE_ROT_WDMA_REG_CTRL_STATE_UNION reg_ctrl_state;
 AAE_ROT_WDMA_R_LB_DEBUG0_UNION r_lb_debug0;
 AAE_ROT_WDMA_R_LB_DEBUG1_UNION r_lb_debug1;
 AAE_ROT_WDMA_R_LB_DEBUG2_UNION r_lb_debug2;
 AAE_ROT_WDMA_R_LB_DEBUG3_UNION r_lb_debug3;
 AAE_ROT_WDMA_REG_CTRL_LAYER_ID_UNION reg_ctrl_layer_id;
};
struct dpu_wch_rgb2y {
 AAE_ROT_WDMA_RGB2Y_IMG_SIZE_UNION rgb2y_img_size;
 AAE_ROT_WDMA_RGB2Y_P00_UNION rgb2y_p00;
 AAE_ROT_WDMA_RGB2Y_P01_UNION rgb2y_p01;
 AAE_ROT_WDMA_RGB2Y_P02_UNION rgb2y_p02;
 AAE_ROT_WDMA_RGB2Y_CTRL_UNION rgb2y_ctrl;
};
#endif
