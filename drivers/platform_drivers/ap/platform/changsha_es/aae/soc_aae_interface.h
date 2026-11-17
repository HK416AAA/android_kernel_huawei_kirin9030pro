#ifndef __SOC_AAE_INTERFACE_H__
#define __SOC_AAE_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define AAE_GLB_PART0_AAE_VESION_ADDR(base) ((base) + (0x0000))
#define AAE_GLB_PART0_FPGA_VERSION_ADDR(base) ((base) + (0x0004))
#define AAE_GLB_PART0_AAE_JTAG_MODE_ADDR(base) ((base) + (0x0008))
#define AAE_GLB_PART0_AAE_PART_CLK_EN_ADDR(base) ((base) + (0x0010))
#define AAE_GLB_PART0_AAE_PART_RST_EN_ADDR(base) ((base) + (0x0014))
#define AAE_GLB_PART0_MODULE_CLK_SEL_ADDR(base) ((base) + (0x0020))
#define AAE_GLB_PART0_MODULE_CLK_EN_ADDR(base) ((base) + (0x0024))
#define AAE_GLB_PART0_AAE_PM_CTRL_ADDR(base) ((base) + (0x0040))
#define AAE_GLB_PART0_AAE_SPRAM_CTRL_S_ADDR(base) ((base) + (0x0044))
#define AAE_GLB_PART0_AAE_TPRAM_CTRL_TP_ADDR(base) ((base) + (0x0048))
#define AAE_GLB_PART0_AAE_TPRAM_CTRL_BP_ADDR(base) ((base) + (0x004C))
#define AAE_GLB_PART0_AAE_SPRAM_CTRL_SPC_ADDR(base) ((base) + (0x0050))
#define AAE_GLB_PART0_AAE_TPRAM_CTRL_TPL_ADDR(base) ((base) + (0x0054))
#define AAE_GLB_PART0_AAE_TPRAM_CTRL_BPL_ADDR(base) ((base) + (0x0058))
#define AAE_GLB_PART0_AAE_NS_OFFLINE0_TO_GIC_O_ADDR(base) ((base) + (0x0100))
#define AAE_GLB_PART0_AAE_NS_OFFLINE0_TO_GIC_MSK_ADDR(base) ((base) + (0x0104))
#define AAE_GLB_PART0_AAE_NS_OFFLINE1_TO_GIC_O_ADDR(base) ((base) + (0x0108))
#define AAE_GLB_PART0_AAE_NS_OFFLINE1_TO_GIC_MSK_ADDR(base) ((base) + (0x010C))
#define AAE_GLB_PART0_AAE_NS_OFFLINE0_TO_IOMCU_O_ADDR(base) ((base) + (0x0110))
#define AAE_GLB_PART0_AAE_NS_OFFLINE0_TO_IOMCU_MSK_ADDR(base) ((base) + (0x0114))
#define AAE_GLB_PART0_AAE_NS_OFFLINE1_TO_IOMCU_O_ADDR(base) ((base) + (0x0118))
#define AAE_GLB_PART0_AAE_NS_OFFLINE1_TO_IOMCU_MSK_ADDR(base) ((base) + (0x011C))
#define AAE_GLB_PART0_AAE_S_OFFLINE0_TO_GIC_O_ADDR(base) ((base) + (0x0120))
#define AAE_GLB_PART0_AAE_S_OFFLINE0_TO_GIC_MSK_ADDR(base) ((base) + (0x0124))
#define AAE_GLB_PART0_AAE_S_OFFLINE1_TO_GIC_O_ADDR(base) ((base) + (0x0128))
#define AAE_GLB_PART0_AAE_S_OFFLINE1_TO_GIC_MSK_ADDR(base) ((base) + (0x012C))
#define AAE_GLB_PART0_AAE_S_OFFLINE0_TO_LPMCU_O_ADDR(base) ((base) + (0x0130))
#define AAE_GLB_PART0_AAE_S_OFFLINE0_TO_LPMCU_MSK_ADDR(base) ((base) + (0x0134))
#define AAE_GLB_PART0_AAE_S_OFFLINE1_TO_LPMCU_O_ADDR(base) ((base) + (0x0138))
#define AAE_GLB_PART0_AAE_S_OFFLINE1_TO_LPMCU_MSK_ADDR(base) ((base) + (0x013C))
#define AAE_GLB_PART0_DBG_IRQ_NS_GIC_ADDR(base) ((base) + (0x0180))
#define AAE_GLB_PART0_DBG_IRQ_S_GIC_ADDR(base) ((base) + (0x0184))
#define AAE_GLB_PART0_DBG_IRQ_NS_IOMCU_ADDR(base) ((base) + (0x0188))
#define AAE_GLB_PART0_DBG_IRQ_S_LPMCU_ADDR(base) ((base) + (0x018C))
#define AAE_GLB_PART0_CMD_NS_INT_O_ADDR(base) ((base) + (0x0200))
#define AAE_GLB_PART0_CMD_NS_INT_MSK_ADDR(base) ((base) + (0x0204))
#define AAE_GLB_PART0_SMART_DMA0_NS_INT_O_ADDR(base) ((base) + (0x0208))
#define AAE_GLB_PART0_SMART_DMA0_NS_INT_MSK_ADDR(base) ((base) + (0x020C))
#define AAE_GLB_PART0_ROT_WDMA_NS_INT_O_ADDR(base) ((base) + (0x0210))
#define AAE_GLB_PART0_ROT_WDMA_NS_INT_MSK_ADDR(base) ((base) + (0x0214))
#define AAE_GLB_PART0_DACC_NS_INT_O_ADDR(base) ((base) + (0x0218))
#define AAE_GLB_PART0_DACC_NS_INT_MSK_ADDR(base) ((base) + (0x021C))
#define AAE_GLB_PART0_DACC_S_INT_O_ADDR(base) ((base) + (0x0220))
#define AAE_GLB_PART0_DACC_S_INT_MSK_ADDR(base) ((base) + (0x0224))
#define AAE_GLB_PART0_HDR_NS_INT_O_ADDR(base) ((base) + (0x0228))
#define AAE_GLB_PART0_HDR_NS_INT_MSK_ADDR(base) ((base) + (0x022C))
#define AAE_GLB_PART0_PIPE_CTRL0_NS_INT_O_ADDR(base) ((base) + (0x0230))
#define AAE_GLB_PART0_PIPE_CTRL0_NS_INT_MSK_ADDR(base) ((base) + (0x0234))
#define AAE_GLB_PART0_PIPE_CTRL1_NS_INT_O_ADDR(base) ((base) + (0x0238))
#define AAE_GLB_PART0_PIPE_CTRL1_NS_INT_MSK_ADDR(base) ((base) + (0x023C))
#define AAE_GLB_PART0_PIPE_CTRL2_NS_INT_O_ADDR(base) ((base) + (0x0240))
#define AAE_GLB_PART0_PIPE_CTRL2_NS_INT_MSK_ADDR(base) ((base) + (0x0244))
#define AAE_GLB_PART0_PIPE_CTRL3_NS_INT_O_ADDR(base) ((base) + (0x0248))
#define AAE_GLB_PART0_PIPE_CTRL3_NS_INT_MSK_ADDR(base) ((base) + (0x024C))
#define AAE_GLB_PART0_DBG_CTRL0_ADDR(base) ((base) + (0x0300))
#define AAE_GLB_PART0_DBG_IP_CYCLE_CNT_ADDR(base) ((base) + (0x0304))
#define AAE_GLB_PART0_DBG_IP_STATE0_ADDR(base) ((base) + (0x0308))
#define AAE_GLB_PART0_DBG_IP_STATE1_ADDR(base) ((base) + (0x030C))
#define AAE_GLB_PART0_DBG_CTRL1_ADDR(base) ((base) + (0x0310))
#define AAE_GLB_PART0_DBG_OV_YCNT0_ADDR(base) ((base) + (0x0314))
#define AAE_GLB_PART0_DBG_CFG_CTRL_ADDR(base) ((base) + (0x0318))
#define AAE_GLB_PART0_DBG_CFG_STATE_ADDR(base) ((base) + (0x031C))
#define AAE_GLB_PART0_DBG_CFG_ADDR_ADDR(base) ((base) + (0x0320))
#define AAE_GLB_PART0_DBG_FLUSH_EN_ADDR(base) ((base) + (0x0324))
#define AAE_GLB_PART0_DBG_FLUSH_CLR_ADDR(base) ((base) + (0x0328))
#define AAE_GLB_PART0_DBG_FLUSH_ST_ADDR(base) ((base) + (0x032C))
#define AAE_GLB_PART0_DBG_RESV0_ADDR(base) ((base) + (0x0330))
#define AAE_GLB_PART0_DBG_RESV1_ADDR(base) ((base) + (0x0334))
#define AAE_GLB_PART0_DBG_RESV2_ADDR(base) ((base) + (0x0338))
#define AAE_GLB_PART0_FRAME_NUM_FLUSH_ADDR(base) ((base) + (0x033C))
#define AAE_GLB_PART0_SCENE0_FRAME_NUM_ADDR(base) ((base) + (0x0340))
#define AAE_GLB_PART0_CRC_CTRL_ADDR(base) ((base) + (0x0400))
#define AAE_GLB_PART0_CRC_RESULT0_ADDR(base) ((base) + (0x0404))
#define AAE_GLB_PART0_CRC_FRAME_CNT0_ADDR(base) ((base) + (0x0408))
#define AAE_GLB_PART0_CRC_RESULT1_ADDR(base) ((base) + (0x040C))
#define AAE_GLB_PART0_CRC_FRAME_CNT1_ADDR(base) ((base) + (0x0410))
#define AAE_GLB_PART0_CRC_INT1_ADDR(base) ((base) + (0x0414))
#define AAE_GLB_PART0_SDMA_CTRL0_ADDR(base,sdn) ((base) + (0x0500+0x40*(sdn)))
#define AAE_GLB_PART0_SDMA_CTRL1_ADDR(base,sdn) ((base) + (0x0504+0x40*(sdn)))
#define AAE_GLB_PART0_SDMA_CTRL2_ADDR(base,sdn) ((base) + (0x0508+0x40*(sdn)))
#define AAE_GLB_PART0_SDMA_DBG_RESERVED0_ADDR(base,sdn) ((base) + (0x050c+0x40*(sdn)))
#define AAE_GLB_PART0_SDMA_DBG_OUT0_ADDR(base,sdn) ((base) + (0x0510+0x40*(sdn)))
#define AAE_GLB_PART0_SDMA_DBG_OUT1_ADDR(base,sdn) ((base) + (0x0514+0x40*(sdn)))
#define AAE_GLB_PART0_SDMA_DBG_MONITOR0_ADDR(base,sdn) ((base) + (0x0518+0x40*(sdn)))
#define AAE_GLB_PART0_SDMA_DBG_MONITOR1_ADDR(base,sdn) ((base) + (0x051c+0x40*(sdn)))
#define AAE_GLB_PART0_SDMA_DBG_MONITOR2_ADDR(base,sdn) ((base) + (0x0520+0x40*(sdn)))
#define AAE_GLB_PART0_SDMA_DBG_MONITOR3_ADDR(base,sdn) ((base) + (0x0524+0x40*(sdn)))
#define AAE_GLB_PART0_SDMA_DBG_MONITOR4_ADDR(base,sdn) ((base) + (0x0528+0x40*(sdn)))
#define AAE_GLB_PART0_SDMA_DBG_MONITOR5_ADDR(base,sdn) ((base) + (0x052c+0x40*(sdn)))
#define AAE_GLB_PART0_SDMA_CTRL3_ADDR(base,sdn) ((base) + (0x0530+0x40*(sdn)))
#define AAE_GLB_PART0_SDMA_DBG_OUT2_ADDR(base,sdn) ((base) + (0x0534+0x40*(sdn)))
#define AAE_GLB_PART0_SDMA_DBG_RESERVED1_ADDR(base,sdn) ((base) + (0x0538+0x40*(sdn)))
#define AAE_GLB_PART0_SDMA_W_DBG0_ADDR(base,sdn) ((base) + (0x0900+0x40*(sdn)))
#define AAE_GLB_PART0_SDMA_W_DBG1_ADDR(base,sdn) ((base) + (0x0904+0x40*(sdn)))
#define AAE_GLB_PART0_SDMA_W_DBG2_ADDR(base,sdn) ((base) + (0x0908+0x40*(sdn)))
#define AAE_GLB_PART0_SDMA_W_DBG3_ADDR(base,sdn) ((base) + (0x090C+0x40*(sdn)))
#define AAE_GLB_PART0_SROT_DBG_OUT0_ADDR(base,srn) ((base) + (0x0D00+0x30*(srn)))
#define AAE_GLB_PART0_SROT_DBG_OUT1_ADDR(base,srn) ((base) + (0x0D04+0x30*(srn)))
#define AAE_GLB_PART0_SROT_DBG_OUT2_ADDR(base,srn) ((base) + (0x0D08+0x30*(srn)))
#define AAE_GLB_PART0_SROT_DBG_OUT3_ADDR(base,srn) ((base) + (0x0D0C+0x30*(srn)))
#define AAE_GLB_PART0_SROT_DBG_OUT4_ADDR(base,srn) ((base) + (0x0D10+0x30*(srn)))
#define AAE_GLB_PART0_SROT_DBG_OUT5_ADDR(base,srn) ((base) + (0x0D14+0x30*(srn)))
#define AAE_GLB_PART0_SROT_DBG_OUT6_ADDR(base,srn) ((base) + (0x0D18+0x30*(srn)))
#define AAE_GLB_PART0_SROT_DBG_OUT7_ADDR(base,srn) ((base) + (0x0D1C+0x30*(srn)))
#define AAE_GLB_PART0_SROT_DBG_RESERVED_ADDR(base,srn) ((base) + (0x0D20+0x30*(srn)))
#define AAE_GLB_PART0_SROT_CTRL0_ADDR(base,srn) ((base) + (0x0D24+0x30*(srn)))
#define AAE_GLB_PART1_AAE_PART1_CLK_SEL_ADDR(base) ((base) + (0x0000))
#define AAE_GLB_PART1_AAE_PART1_CLK_EN_ADDR(base) ((base) + (0x0004))
#define AAE_DM_CMDLIST_ADDR_H_ADDR(base) ((base) + (0x0000))
#define AAE_DM_CMDLIST_ADDR0_ADDR(base) ((base) + (0x0004))
#define AAE_DM_CMDLIST_ADDR1_ADDR(base) ((base) + (0x0008))
#define AAE_DM_CMDLIST_ADDR2_ADDR(base) ((base) + (0x000C))
#define AAE_DM_CMDLIST_ADDR3_ADDR(base) ((base) + (0x0010))
#define AAE_DM_CMDLIST_ADDR4_ADDR(base) ((base) + (0x0014))
#define AAE_DM_CMDLIST_ADDR5_ADDR(base) ((base) + (0x0018))
#define AAE_DM_CMDLIST_ADDR6_ADDR(base) ((base) + (0x001C))
#define AAE_DM_CMDLIST_ADDR7_ADDR(base) ((base) + (0x0020))
#define AAE_DM_CMDLIST_ADDR8_ADDR(base) ((base) + (0x0024))
#define AAE_DM_CMDLIST_ADDR9_ADDR(base) ((base) + (0x0028))
#define AAE_DM_CMDLIST_ADDR10_ADDR(base) ((base) + (0x002C))
#define AAE_DM_CMDLIST_ADDR11_ADDR(base) ((base) + (0x0030))
#define AAE_DM_CMDLIST_ADDR12_ADDR(base) ((base) + (0x0034))
#define AAE_DM_CMDLIST_ADDR13_ADDR(base) ((base) + (0x0038))
#define AAE_DM_CMDLIST_ADDR14_ADDR(base) ((base) + (0x003C))
#define AAE_DM_SROT_NUMBER_ADDR(base) ((base) + (0x0050))
#define AAE_DM_HIOF_NUMBER_ADDR(base) ((base) + (0x0054))
#define AAE_DM_LAYER_NUMBER_ADDR(base) ((base) + (0x0058))
#define AAE_DM_HDR_INPUT_IMG_WIDTH_ADDR(base) ((base) + (0x0060))
#define AAE_DM_HDR_OUTPUT_IMG_WIDTH_ADDR(base) ((base) + (0x0064))
#define AAE_DM_HDR_INPUT_FMT_ADDR(base) ((base) + (0x0068))
#define AAE_DM_HDR_RESERVED_ADDR(base) ((base) + (0x006C))
#define AAE_DM_BLPP_INPUT_IMG_WIDTH_ADDR(base) ((base) + (0x0070))
#define AAE_DM_BLPP_OUTPUT_IMG_WIDTH_ADDR(base) ((base) + (0x0074))
#define AAE_DM_BLPP_INPUT_FMT_ADDR(base) ((base) + (0x0078))
#define AAE_DM_BLPP_OUTPUT_FMT_ADDR(base) ((base) + (0x007C))
#define AAE_DM_CLD0_INPUT_IMG_WIDTH_ADDR(base) ((base) + (0x0080))
#define AAE_DM_CLD0_OUTPUT_IMG_WIDTH_ADDR(base) ((base) + (0x0084))
#define AAE_DM_CLD0_INPUT_FMT_ADDR(base) ((base) + (0x0088))
#define AAE_DM_CLD0_OUTPUT_FMT_ADDR(base) ((base) + (0x008C))
#define AAE_DM_CLD1_INPUT_IMG_WIDTH_ADDR(base) ((base) + (0x0090))
#define AAE_DM_CLD1_OUTPUT_IMG_WIDTH_ADDR(base) ((base) + (0x0094))
#define AAE_DM_CLD1_INPUT_FMT_ADDR(base) ((base) + (0x0098))
#define AAE_DM_CLD1_OUTPUT_FMT_ADDR(base) ((base) + (0x009C))
#define AAE_DM_AIHDR_INPUT_IMG_WIDTH_ADDR(base) ((base) + (0x00A0))
#define AAE_DM_AIHDR_OUTPUT_IMG_WIDTH_ADDR(base) ((base) + (0x00A4))
#define AAE_DM_AIHDR_INPUT_FMT_ADDR(base) ((base) + (0x00A8))
#define AAE_DM_AIHDR_RESERVED_ADDR(base) ((base) + (0x00AC))
#define AAE_DM_SCL0_INPUT_IMG_WIDTH_ADDR(base) ((base) + (0x00B0))
#define AAE_DM_SCL0_OUTPUT_IMG_WIDTH_ADDR(base) ((base) + (0x00B4))
#define AAE_DM_SCL0_TYPE_ADDR(base) ((base) + (0x00B8))
#define AAE_DM_SCL0_THRESHOLD_ADDR(base) ((base) + (0x00BC))
#define AAE_DM_SCL1_INPUT_IMG_WIDTH_ADDR(base) ((base) + (0x00C0))
#define AAE_DM_SCL1_OUTPUT_IMG_WIDTH_ADDR(base) ((base) + (0x00C4))
#define AAE_DM_SCL1_TYPE_ADDR(base) ((base) + (0x00C8))
#define AAE_DM_SCL1_THRESHOLD_ADDR(base) ((base) + (0x00CC))
#define AAE_DM_SCL2_INPUT_IMG_WIDTH_ADDR(base) ((base) + (0x00D0))
#define AAE_DM_SCL2_OUTPUT_IMG_WIDTH_ADDR(base) ((base) + (0x00D4))
#define AAE_DM_SCL2_TYPE_ADDR(base) ((base) + (0x00D8))
#define AAE_DM_SCL2_THRESHOLD_ADDR(base) ((base) + (0x00DC))
#define AAE_DM_SCL3_INPUT_IMG_WIDTH_ADDR(base) ((base) + (0x00E0))
#define AAE_DM_SCL3_OUTPUT_IMG_WIDTH_ADDR(base) ((base) + (0x00E4))
#define AAE_DM_SCL3_TYPE_ADDR(base) ((base) + (0x00E8))
#define AAE_DM_SCL3_THRESHOLD_ADDR(base) ((base) + (0x00EC))
#define AAE_DM_SCL4_INPUT_IMG_WIDTH_ADDR(base) ((base) + (0x00F0))
#define AAE_DM_SCL4_OUTPUT_IMG_WIDTH_ADDR(base) ((base) + (0x00F4))
#define AAE_DM_SCL4_TYPE_ADDR(base) ((base) + (0x00F8))
#define AAE_DM_SCL4_THRESHOLD_ADDR(base) ((base) + (0x00FC))
#define AAE_DM_BLUR_INPUT_IMG_WIDTH_ADDR(base) ((base) + (0x0100))
#define AAE_DM_BLUR_OUTPUT_IMG_WIDTH_ADDR(base) ((base) + (0x0104))
#define AAE_DM_BLUR_INPUT_FMT_ADDR(base) ((base) + (0x0108))
#define AAE_DM_BLUR_RESERVED_ADDR(base) ((base) + (0x010C))
#define AAE_DM_WARP_INPUT_IMG_WIDTH_ADDR(base) ((base) + (0x0110))
#define AAE_DM_WARP_OUTPUT_IMG_WIDTH_ADDR(base) ((base) + (0x0114))
#define AAE_DM_WARP_INPUT_FMT_ADDR(base) ((base) + (0x0118))
#define AAE_DM_WARP_RESERVED_ADDR(base) ((base) + (0x011C))
#define AAE_DM_HIOF_INPUT_IMG_WIDTH_ADDR(base) ((base) + (0x0120))
#define AAE_DM_HIOF_OUTPUT_IMG_WIDTH_ADDR(base) ((base) + (0x0124))
#define AAE_DM_HIOF_INPUT_FMT_ADDR(base) ((base) + (0x0128))
#define AAE_DM_HIOF_RESERVED_ADDR(base) ((base) + (0x012C))
#define AAE_DM_WDFC_INPUT_IMG_WIDTH_ADDR(base) ((base) + (0x0130))
#define AAE_DM_WDFC_OUTPUT_IMG_WIDTH_ADDR(base) ((base) + (0x0134))
#define AAE_DM_WDFC_INPUT_FMT_ADDR(base) ((base) + (0x0138))
#define AAE_DM_WDFC_RESERVED_ADDR(base) ((base) + (0x013C))
#define AAE_DM_WCH_INPUT_IMG_WIDTH_ADDR(base) ((base) + (0x0140))
#define AAE_DM_WCH_INPUT_IMG_STRY_ADDR(base) ((base) + (0x0144))
#define AAE_DM_WCH_SEL_ADDR(base) ((base) + (0x0148))
#define AAE_DM_WCH_RESERVED_1_ADDR(base) ((base) + (0x014C))
#define AAE_DM_ITF_INPUT_IMG_WIDTH_ADDR(base) ((base) + (0x0150))
#define AAE_DM_ITF_SEL_ADDR(base) ((base) + (0x0154))
#define AAE_DM_ITF_RESERVED_1_ADDR(base) ((base) + (0x0158))
#define AAE_DM_ITF_RESERVED_2_ADDR(base) ((base) + (0x015C))
#define AAE_DM_OV_IMG_WIDTH_ADDR(base) ((base) + (0x0160))
#define AAE_DM_OV_BLAYER_ENDX_ADDR(base) ((base) + (0x0164))
#define AAE_DM_OV_BLAYER_ENDY_ADDR(base) ((base) + (0x0168))
#define AAE_DM_OV_BG_COLOR_RGB_ADDR(base) ((base) + (0x016C))
#define AAE_DM_OV_ORDER0_ADDR(base) ((base) + (0x0170))
#define AAE_DM_OV_RESERVED_0_ADDR(base) ((base) + (0x0174))
#define AAE_DM_SCENE_MODE_ADDR(base) ((base) + (0x0178))
#define AAE_DM_OV_RESERVED_2_ADDR(base) ((base) + (0x017C))
#define AAE_DM_LAYER_HEIGHT_ADDR(base,ln) ((base) + (0x0180+(ln)*0x60))
#define AAE_DM_LAYER_MASK_Y0_ADDR(base,ln) ((base) + (0x0184+(ln)*0x60))
#define AAE_DM_LAYER_MASK_Y1_ADDR(base,ln) ((base) + (0x0188+(ln)*0x60))
#define AAE_DM_LAYER_ROT_EN_ADDR(base,ln) ((base) + (0x018c+(ln)*0x60))
#define AAE_DM_LAYER_SBLK_TYPE_ADDR(base,ln) ((base) + (0x0190+(ln)*0x60))
#define AAE_DM_LAYER_STRETCH3_LINE_ADDR(base,ln) ((base) + (0x0194+(ln)*0x60))
#define AAE_DM_LAYER_START_ADDR3_H_ADDR(base,ln) ((base) + (0x0198+(ln)*0x60))
#define AAE_DM_LAYER_START_ADDR0_L_ADDR(base,ln) ((base) + (0x019c+(ln)*0x60))
#define AAE_DM_LAYER_START_ADDR1_L_ADDR(base,ln) ((base) + (0x01a0+(ln)*0x60))
#define AAE_DM_LAYER_START_ADDR2_L_ADDR(base,ln) ((base) + (0x01a4+(ln)*0x60))
#define AAE_DM_LAYER_START_ADDR3_L_ADDR(base,ln) ((base) + (0x01a8+(ln)*0x60))
#define AAE_DM_LAYER_STRIDE0_ADDR(base,ln) ((base) + (0x01ac+(ln)*0x60))
#define AAE_DM_LAYER_STRIDE1_ADDR(base,ln) ((base) + (0x01b0+(ln)*0x60))
#define AAE_DM_LAYER_STRIDE2_ADDR(base,ln) ((base) + (0x01b4+(ln)*0x60))
#define AAE_DM_LAYER_STRIDE3_ADDR(base,ln) ((base) + (0x01b8+(ln)*0x60))
#define AAE_DM_LAYER_BOT_CROP_ADDR(base,ln) ((base) + (0x01bc+(ln)*0x60))
#define AAE_DM_LAYER_CLIP_LEFT_ADDR(base,ln) ((base) + (0x01c0+(ln)*0x60))
#define AAE_DM_LAYER_OV_DFC_CFG_ADDR(base,ln) ((base) + (0x01c4+(ln)*0x60))
#define AAE_DM_LAYER_OV_STARTY_ADDR(base,ln) ((base) + (0x01c8+(ln)*0x60))
#define AAE_DM_LAYER_OV_ENDY_ADDR(base,ln) ((base) + (0x01cc+(ln)*0x60))
#define AAE_DM_LAYER_OV_PATTERN_A_ADDR(base,ln) ((base) + (0x01d0+(ln)*0x60))
#define AAE_DM_LAYER_OV_PATTERN_RGB_ADDR(base,ln) ((base) + (0x01d4+(ln)*0x60))
#define AAE_DM_LAYER_OV_MODE_ADDR(base,ln) ((base) + (0x01d8+(ln)*0x60))
#define AAE_DM_LAYER_OV_ALPHA_ADDR(base,ln) ((base) + (0x01dc+(ln)*0x60))
#define AAE_DGP0_DGP_CLK_SEL_ADDR(base) ((base) + (0x0000))
#define AAE_DGP0_DGP_CLK_EN_ADDR(base) ((base) + (0x0004))
#define AAE_DGP0_HDR_CFG_ADDR(base) ((base) + (0x0008))
#define AAE_DGP0_DGP1_ADDR(base) ((base) + (0x000C))
#define AAE_DGP0_ARSR1_CFG_ADDR(base) ((base) + (0x0010))
#define AAE_DGP0_VSCF0_CFG_ADDR(base) ((base) + (0x0014))
#define AAE_DGP0_CLD_CFG_ADDR(base) ((base) + (0x0018))
#define AAE_DGP0_OV_ADDR(base) ((base) + (0x001C))
#define AAE_DGP0_WDFC_CFG_ADDR(base) ((base) + (0x0020))
#define AAE_DGP0_DEFAULT_LAYER_ID_ADDR(base) ((base) + (0x0024))
#define AAE_DGP0_OS_THR_ADDR(base,node_id0) ((base) + (0x0028+(node_id0)*0x4))
#define AAE_DGP0_LAYER_OV_Y_S0_ADDR(base,pre_ch0) ((base) + (0x0044+(pre_ch0)*0x4))
#define AAE_DGP0_DIM_FLAG_REG_S0_ADDR(base) ((base) + (0x0084))
#define AAE_DGP0_LAYER_OV_Y_S1_ADDR(base,pre_ch1) ((base) + (0x0090+(pre_ch1)*0x4))
#define AAE_DGP0_DIM_FLAG_REG_S1_ADDR(base) ((base) + (0x00b0))
#define AAE_DGP0_INFO_RDY_NEED_DBG_ST0_ADDR(base) ((base) + (0x0100))
#define AAE_DGP0_INFO_RDY_NEED_DBG_ST1_ADDR(base) ((base) + (0x0104))
#define AAE_DGP0_INFO_LINE_ID_DBG_S01_ADDR(base) ((base) + (0x0108))
#define AAE_DGP0_INFO_LINE_ID_DBG_S23_ADDR(base) ((base) + (0x010C))
#define AAE_DGP0_INFO_TIMEOUT_INT_ADDR(base) ((base) + (0x0110))
#define AAE_DGP0_INFO_TIMEOUT_INT_MASK_ADDR(base) ((base) + (0x0114))
#define AAE_DGP0_INFO_TIMEOUT_THR_ADDR(base) ((base) + (0x0118))
#define AAE_DGP0_DBG_CLR_ADDR(base) ((base) + (0x011C))
#define AAE_DGP0_DBG_INFO_CNT_ADDR(base,node_id0) ((base) + (0x0124+(node_id0)*0x4))
#define AAE_DGP0_DBG_DATA_CNT_ADDR(base,node_id0) ((base) + (0x0140+(node_id0)*0x4))
#define AAE_DGP1_DGP_CLK_SEL_ADDR(base) ((base) + (0x0000))
#define AAE_DGP1_DGP_CLK_EN_ADDR(base) ((base) + (0x0004))
#define AAE_DGP1_SCF2D0_CFG_ADDR(base) ((base) + (0x0008))
#define AAE_DGP1_BLUR_CFG_ADDR(base) ((base) + (0x000C))
#define AAE_DGP1_SCF2D1_CFG_ADDR(base) ((base) + (0x0010))
#define AAE_DGP1_BLPP_CFG_ADDR(base) ((base) + (0x0014))
#define AAE_DGP1_AIHDR_CFG_ADDR(base) ((base) + (0x0018))
#define AAE_DGP1_WARP_CFG_ADDR(base) ((base) + (0x001C))
#define AAE_DGP1_HIOF_CFG_ADDR(base) ((base) + (0x0020))
#define AAE_DGP1_OS_THR_ADDR(base,node_id1) ((base) + (0x0028+(node_id1)*0x4))
#define AAE_DGP1_INFO_RDY_NEED_DBG_ST0_ADDR(base) ((base) + (0x0100))
#define AAE_DGP1_INFO_RDY_NEED_DBG_ST1_ADDR(base) ((base) + (0x0104))
#define AAE_DGP1_INFO_LINE_ID_DBG_S01_ADDR(base) ((base) + (0x0108))
#define AAE_DGP1_INFO_TIMEOUT_INT_ADDR(base) ((base) + (0x010C))
#define AAE_DGP1_INFO_TIMEOUT_INT_MASK_ADDR(base) ((base) + (0x0110))
#define AAE_DGP1_INFO_TIMEOUT_THR_ADDR(base) ((base) + (0x0114))
#define AAE_DGP1_DBG_CLR_ADDR(base) ((base) + (0x0118))
#define AAE_DGP1_DBG_INFO_CNT_ADDR(base,node_id1) ((base) + (0x0120+(node_id1)*0x4))
#define AAE_DGP1_DBG_DATA_CNT_ADDR(base,node_id1) ((base) + (0x013C+(node_id1)*0x4))
#define AAE_INFO_SRC_SCENE0_LAYER_SIZE_ADDR(base) ((base) + (0x0000))
#define AAE_INFO_SRC_SCENE1_LAYER_SIZE_ADDR(base) ((base) + (0x0004))
#define AAE_INFO_SRC_SCENE2_LAYER_SIZE_ADDR(base) ((base) + (0x0008))
#define AAE_INFO_SRC_SCENE4_LAYER_SIZE_ADDR(base) ((base) + (0x000C))
#define AAE_INFO_SRC_SCENE0_DBUF_DEPTH_ADDR(base) ((base) + (0x0010))
#define AAE_INFO_SRC_SCENE1_DBUF_DEPTH_ADDR(base) ((base) + (0x0014))
#define AAE_INFO_SRC_SCENE2_DBUF_DEPTH_ADDR(base) ((base) + (0x0018))
#define AAE_INFO_SRC_SCENE4_DBUF_DEPTH_ADDR(base) ((base) + (0x001C))
#define AAE_INFO_SRC_SCENE0_DBUF_DEPTH_EXTRA_ADDR(base) ((base) + (0x0020))
#define AAE_INFO_SRC_SCENE1_DBUF_DEPTH_EXTRA_ADDR(base) ((base) + (0x0024))
#define AAE_INFO_SRC_SCENE2_DBUF_DEPTH_EXTRA_ADDR(base) ((base) + (0x0028))
#define AAE_INFO_SRC_SCENE4_DBUF_DEPTH_EXTRA_ADDR(base) ((base) + (0x002C))
#define AAE_INFO_SRC_SCENE0_DBUF_QOS_ADDR(base) ((base) + (0x0030))
#define AAE_INFO_SRC_SCENE1_DBUF_QOS_ADDR(base) ((base) + (0x0034))
#define AAE_INFO_SRC_SCENE2_DBUF_QOS_ADDR(base) ((base) + (0x0038))
#define AAE_INFO_SRC_SCENE4_DBUF_QOS_ADDR(base) ((base) + (0x003C))
#define AAE_INFO_SRC_SCENE0_DBUF_CTRL_ADDR(base) ((base) + (0x0040))
#define AAE_INFO_SRC_SCENE1_DBUF_CTRL_ADDR(base) ((base) + (0x0044))
#define AAE_INFO_SRC_SCENE2_DBUF_CTRL_ADDR(base) ((base) + (0x0048))
#define AAE_INFO_SRC_SCENE4_DBUF_CTRL_ADDR(base) ((base) + (0x004C))
#define AAE_INFO_SRC_SCENE0_PIPE_OS_NUM_ADDR(base) ((base) + (0x0050))
#define AAE_INFO_SRC_SCENE1_PIPE_OS_NUM_ADDR(base) ((base) + (0x0054))
#define AAE_INFO_SRC_SCENE2_PIPE_OS_NUM_ADDR(base) ((base) + (0x0058))
#define AAE_INFO_SRC_SCENE4_PIPE_OS_NUM_ADDR(base) ((base) + (0x005C))
#define AAE_INFO_SRC_SCENE0_INFO_DEBUG0_ADDR(base) ((base) + (0x0060))
#define AAE_INFO_SRC_SCENE1_INFO_DEBUG0_ADDR(base) ((base) + (0x0064))
#define AAE_INFO_SRC_SCENE2_INFO_DEBUG0_ADDR(base) ((base) + (0x0068))
#define AAE_INFO_SRC_SCENE4_INFO_DEBUG0_ADDR(base) ((base) + (0x006C))
#define AAE_INFO_SRC_SCENE0_INFO_DEBUG1_ADDR(base) ((base) + (0x0070))
#define AAE_INFO_SRC_SCENE1_INFO_DEBUG1_ADDR(base) ((base) + (0x0074))
#define AAE_INFO_SRC_SCENE2_INFO_DEBUG1_ADDR(base) ((base) + (0x0078))
#define AAE_INFO_SRC_SCENE4_INFO_DEBUG1_ADDR(base) ((base) + (0x007C))
#define AAE_INFO_SRC_SCENE0_INFO_PAUSE_NUM_ADDR(base) ((base) + (0x0080))
#define AAE_INFO_SRC_SCENE1_INFO_PAUSE_NUM_ADDR(base) ((base) + (0x0084))
#define AAE_INFO_SRC_SCENE2_INFO_PAUSE_NUM_ADDR(base) ((base) + (0x0088))
#define AAE_INFO_SRC_SCENE4_INFO_PAUSE_NUM_ADDR(base) ((base) + (0x008C))
#define AAE_INFO_SRC_SCENE0_DBUF_VACT_QOS_ADDR(base) ((base) + (0x0090))
#define AAE_INFO_SRC_SCENE1_DBUF_VACT_QOS_ADDR(base) ((base) + (0x0094))
#define AAE_INFO_SRC_SCENE2_DBUF_VACT_QOS_ADDR(base) ((base) + (0x0098))
#define AAE_INFO_SRC_SCENE4_DBUF_VACT_QOS_ADDR(base) ((base) + (0x009C))
#define AAE_INFO_SRC_SCENE0_INFO_SEL_ADDR(base) ((base) + (0x00A0))
#define AAE_INFO_SRC_SCENE1_INFO_SEL_ADDR(base) ((base) + (0x00A4))
#define AAE_INFO_SRC_SCENE2_INFO_SEL_ADDR(base) ((base) + (0x00A8))
#define AAE_INFO_SRC_SCENE4_INFO_SEL_ADDR(base) ((base) + (0x00AC))
#define AAE_INFO_SRC_SCENE0_PRE_OS_NUM_ADDR(base) ((base) + (0x00B0))
#define AAE_INFO_SRC_SCENE1_PRE_OS_NUM_ADDR(base) ((base) + (0x00B4))
#define AAE_INFO_SRC_SCENE2_PRE_OS_NUM_ADDR(base) ((base) + (0x00B8))
#define AAE_INFO_SRC_SCENE4_PRE_OS_NUM_ADDR(base) ((base) + (0x00BC))
#define AAE_INFO_SRC_LAYER_ID_ADDR(base) ((base) + (0x00C0))
#define AAE_WR_CTRL_CLK_SEL_ADDR(base) ((base) + (0x0000))
#define AAE_WR_CTRL_CLK_EN_ADDR(base) ((base) + (0x0004))
#define AAE_WR_CTRL_CTRL_MODE_ADDR(base) ((base) + (0x0008))
#define AAE_WR_CTRL_CH0_LAYER_ID_ADDR(base) ((base) + (0x000C))
#define AAE_WR_CTRL_CH1_LAYER_ID_ADDR(base) ((base) + (0x0010))
#define AAE_WR_CTRL_CH2_LAYER_ID_ADDR(base) ((base) + (0x0014))
#define AAE_WR_CTRL_CH3_LAYER_ID_ADDR(base) ((base) + (0x0018))
#define AAE_WR_CTRL_CH4_LAYER_ID_ADDR(base) ((base) + (0x001C))
#define AAE_WR_CTRL_CH5_LAYER_ID_ADDR(base) ((base) + (0x0020))
#define AAE_WR_CTRL_CH6_LAYER_ID_ADDR(base) ((base) + (0x0024))
#define AAE_WR_CTRL_CH7_LAYER_ID_ADDR(base) ((base) + (0x0028))
#define AAE_WR_CTRL_CH8_LAYER_ID_ADDR(base) ((base) + (0x002C))
#define AAE_WR_CTRL_CH9_LAYER_ID_ADDR(base) ((base) + (0x0030))
#define AAE_WR_CTRL_CH10_LAYER_ID_ADDR(base) ((base) + (0x0034))
#define AAE_WR_CTRL_CH11_LAYER_ID_ADDR(base) ((base) + (0x0038))
#define AAE_WR_CTRL_CH0_DBG_ADDR(base) ((base) + (0x0040))
#define AAE_WR_CTRL_CH1_DBG_ADDR(base) ((base) + (0x0044))
#define AAE_WR_CTRL_CH2_DBG_ADDR(base) ((base) + (0x0048))
#define AAE_WR_CTRL_CH3_DBG_ADDR(base) ((base) + (0x004C))
#define AAE_WR_CTRL_CH4_DBG_ADDR(base) ((base) + (0x0050))
#define AAE_WR_CTRL_CH5_DBG_ADDR(base) ((base) + (0x0054))
#define AAE_WR_CTRL_CH6_DBG_ADDR(base) ((base) + (0x0058))
#define AAE_WR_CTRL_CH7_DBG_ADDR(base) ((base) + (0x005C))
#define AAE_WR_CTRL_CH8_DBG_ADDR(base) ((base) + (0x0060))
#define AAE_WR_CTRL_CH9_DBG_ADDR(base) ((base) + (0x0064))
#define AAE_WR_CTRL_CH10_DBG_ADDR(base) ((base) + (0x0068))
#define AAE_WR_CTRL_CH11_DBG_ADDR(base) ((base) + (0x006C))
#define AAE_PIPE_CTRL_PIPE_CLK_EN_ADDR(base) ((base) + (0x0000))
#define AAE_PIPE_CTRL_PIPE_CLK_SEL_ADDR(base) ((base) + (0x0004))
#define AAE_PIPE_CTRL_PIPE_MEM_CTRL_ADDR(base) ((base) + (0x0008))
#define AAE_PIPE_CTRL_SOUR_AUTO_CTRL_ADDR(base) ((base) + (0x000C))
#define AAE_PIPE_CTRL_DEBUG_CTRL_ADDR(base) ((base) + (0x0010))
#define AAE_PIPE_CTRL_IDLE_DISP_CTRL_ADDR(base) ((base) + (0x0014))
#define AAE_PIPE_CTRL_PIPE_SCN0_FLUX_CTRL_ADDR(base) ((base) + (0x0018))
#define AAE_PIPE_CTRL_PIPE_SCN1_FLUX_CTRL_ADDR(base) ((base) + (0x001C))
#define AAE_PIPE_CTRL_PIPE_SCN2_FLUX_CTRL_ADDR(base) ((base) + (0x0020))
#define AAE_PIPE_CTRL_PIPE_SCN4_FLUX_CTRL_ADDR(base) ((base) + (0x0024))
#define AAE_PIPE_CTRL_PIPE_DCPT_STATE_ADDR(base) ((base) + (0x0028))
#define AAE_PIPE_CTRL_PIPE_USE_STATE_ADDR(base) ((base) + (0x002C))
#define AAE_PIPE_CTRL_PIPE_PRE_CHECK_STATE_ADDR(base) ((base) + (0x0030))
#define AAE_PIPE_CTRL_PIPE_SCN_STATE_ADDR(base) ((base) + (0x0034))
#define AAE_PIPE_CTRL_PIPE_DBG_CTRL_ADDR(base) ((base) + (0x0038))
#define AAE_PIPE_CTRL_PIPE_DBG0_ADDR(base) ((base) + (0x003C))
#define AAE_PIPE_CTRL_PIPE_DBG1_ADDR(base) ((base) + (0x0040))
#define AAE_PIPE_CTRL_PIPE_DBG2_ADDR(base) ((base) + (0x0044))
#define AAE_PIPE_CTRL_PIPE_DBG3_ADDR(base) ((base) + (0x0048))
#define AAE_PIPE_CTRL_PIPE_DBG4_ADDR(base) ((base) + (0x004C))
#define AAE_PIPE_CTRL_PIPE_DBG5_ADDR(base) ((base) + (0x0050))
#define AAE_PIPE_CTRL_PIPE_DBG6_ADDR(base) ((base) + (0x0054))
#define AAE_PIPE_CTRL_PIPE_DBG7_ADDR(base) ((base) + (0x0058))
#define AAE_PIPE_CTRL_PIPE_DBG8_ADDR(base) ((base) + (0x005C))
#define AAE_PIPE_CTRL_PIPE_DBG9_ADDR(base) ((base) + (0x0060))
#define AAE_PIPE_CTRL_PIPE_DBG10_ADDR(base) ((base) + (0x0064))
#define AAE_PIPE_CTRL_PIPE_DBG11_ADDR(base) ((base) + (0x0068))
#define AAE_PIPE_CTRL_PIPE_DBG12_ADDR(base) ((base) + (0x006C))
#define AAE_PIPE_CTRL_PIPE_DBG13_ADDR(base) ((base) + (0x0070))
#define AAE_PIPE_CTRL_PIPE_DBG14_ADDR(base) ((base) + (0x0074))
#define AAE_PIPE_CTRL_PIPE_DBG15_ADDR(base) ((base) + (0x0078))
#define AAE_PIPE_CTRL_PIPE_DBG16_ADDR(base) ((base) + (0x007C))
#define AAE_PIPE_CTRL_PIPE_DBG17_ADDR(base) ((base) + (0x0080))
#define AAE_PIPE_CTRL_PIPE_DBG18_ADDR(base) ((base) + (0x0084))
#define AAE_PIPE_CTRL_PIPE_DBG19_ADDR(base) ((base) + (0x0088))
#define AAE_PIPE_CTRL_PIPE_DBG20_ADDR(base) ((base) + (0x008C))
#define AAE_PIPE_CTRL_PIPE_DBG21_ADDR(base) ((base) + (0x0090))
#define AAE_PIPE_CTRL_PIPE_DBG22_ADDR(base) ((base) + (0x0094))
#define AAE_PIPE_CTRL_PIPE_DBG23_ADDR(base) ((base) + (0x0098))
#define AAE_PIPE_CTRL_PIPE_DBG24_ADDR(base) ((base) + (0x009C))
#define AAE_PIPE_CTRL_PIPE_DBG25_ADDR(base) ((base) + (0x0100))
#define AAE_PIPE_CTRL_PIPE_DBG26_ADDR(base) ((base) + (0x0104))
#define AAE_PIPE_CTRL_PIPE_DBG27_ADDR(base) ((base) + (0x0108))
#define AAE_PIPE_CTRL_PIPE_DBG28_ADDR(base) ((base) + (0x010C))
#define AAE_PIPE_CTRL_PIPE_DBG29_ADDR(base) ((base) + (0x0114))
#define AAE_PIPE_CTRL_FIFO_AFULL_THR_ADDR(base) ((base) + (0x0118))
#define AAE_PIPE_CTRL_RUN_IDX_REQ_IRQ_MASK_ADDR(base) ((base) + (0x011C))
#define AAE_PIPE_CTRL_RUN_REQ_TIME_THR_ADDR(base) ((base) + (0x0120))
#define AAE_PIPE_CTRL_IDX_REQ_TIME_THR_ADDR(base) ((base) + (0x0124))
#define AAE_PIPE_CTRL_RD_SHADOW_ADDR(base) ((base) + (0x0140))
#define AAE_PIPE_CTRL_REG_DEFAULT_ADDR(base) ((base) + (0x0144))
#define AAE_RD_CTRL_BITEXT_CTL_ADDR(base) ((base) + (0x0100))
#define AAE_RD_CTRL_BITEXT_REG_INI0_0_ADDR(base) ((base) + (0x0104))
#define AAE_RD_CTRL_BITEXT_REG_INI0_1_ADDR(base) ((base) + (0x0108))
#define AAE_RD_CTRL_BITEXT_REG_INI0_2_ADDR(base) ((base) + (0x010C))
#define AAE_RD_CTRL_BITEXT_REG_INI0_3_ADDR(base) ((base) + (0x0110))
#define AAE_RD_CTRL_BITEXT_REG_INI1_0_ADDR(base) ((base) + (0x0114))
#define AAE_RD_CTRL_BITEXT_REG_INI1_1_ADDR(base) ((base) + (0x0118))
#define AAE_RD_CTRL_BITEXT_REG_INI1_2_ADDR(base) ((base) + (0x011C))
#define AAE_RD_CTRL_BITEXT_REG_INI1_3_ADDR(base) ((base) + (0x0120))
#define AAE_RD_CTRL_BITEXT_REG_INI2_0_ADDR(base) ((base) + (0x0124))
#define AAE_RD_CTRL_BITEXT_REG_INI2_1_ADDR(base) ((base) + (0x0128))
#define AAE_RD_CTRL_BITEXT_REG_INI2_2_ADDR(base) ((base) + (0x012C))
#define AAE_RD_CTRL_BITEXT_REG_INI2_3_ADDR(base) ((base) + (0x0130))
#define AAE_RD_CTRL_BITEXT_POWER_CTRL_C_ADDR(base) ((base) + (0x0134))
#define AAE_RD_CTRL_BITEXT_POWER_CTRL_SHIFT_ADDR(base) ((base) + (0x0138))
#define AAE_RD_CTRL_BITEXT_FILT_00_ADDR(base) ((base) + (0x013C))
#define AAE_RD_CTRL_BITEXT_FILT_01_ADDR(base) ((base) + (0x0140))
#define AAE_RD_CTRL_BITEXT_FILT_02_ADDR(base) ((base) + (0x0144))
#define AAE_RD_CTRL_BITEXT_FILT_10_ADDR(base) ((base) + (0x0148))
#define AAE_RD_CTRL_BITEXT_FILT_11_ADDR(base) ((base) + (0x014C))
#define AAE_RD_CTRL_BITEXT_FILT_12_ADDR(base) ((base) + (0x0150))
#define AAE_RD_CTRL_BITEXT_FILT_20_ADDR(base) ((base) + (0x0154))
#define AAE_RD_CTRL_BITEXT_FILT_21_ADDR(base) ((base) + (0x0158))
#define AAE_RD_CTRL_BITEXT_FILT_22_ADDR(base) ((base) + (0x015C))
#define AAE_RD_CTRL_BITEXT_THD_R0_ADDR(base) ((base) + (0x0160))
#define AAE_RD_CTRL_BITEXT_THD_R1_ADDR(base) ((base) + (0x0164))
#define AAE_RD_CTRL_BITEXT_THD_G0_ADDR(base) ((base) + (0x0168))
#define AAE_RD_CTRL_BITEXT_THD_G1_ADDR(base) ((base) + (0x016C))
#define AAE_RD_CTRL_BITEXT_THD_B0_ADDR(base) ((base) + (0x0170))
#define AAE_RD_CTRL_BITEXT_THD_B1_ADDR(base) ((base) + (0x0174))
#define AAE_RD_CTRL_BITEXT_RESERVED0_ADDR(base) ((base) + (0x0178))
#define AAE_RD_CTRL_BITEXT_RESERVED1_ADDR(base) ((base) + (0x017C))
#define AAE_RD_CTRL_S0L0_GLB_ALPHA01_ADDR(base) ((base) + (0x0180))
#define AAE_RD_CTRL_S0L1_GLB_ALPHA01_ADDR(base) ((base) + (0x0184))
#define AAE_RD_CTRL_S0L2_GLB_ALPHA01_ADDR(base) ((base) + (0x0188))
#define AAE_RD_CTRL_S0L3_GLB_ALPHA01_ADDR(base) ((base) + (0x018C))
#define AAE_RD_CTRL_S0L4_GLB_ALPHA01_ADDR(base) ((base) + (0x0190))
#define AAE_RD_CTRL_S0L5_GLB_ALPHA01_ADDR(base) ((base) + (0x0194))
#define AAE_RD_CTRL_S0L6_GLB_ALPHA01_ADDR(base) ((base) + (0x0198))
#define AAE_RD_CTRL_S0L7_GLB_ALPHA01_ADDR(base) ((base) + (0x019C))
#define AAE_RD_CTRL_S0L8_GLB_ALPHA01_ADDR(base) ((base) + (0x01A0))
#define AAE_RD_CTRL_S0L9_GLB_ALPHA01_ADDR(base) ((base) + (0x01A4))
#define AAE_RD_CTRL_S0L10_GLB_ALPHA01_ADDR(base) ((base) + (0x01A8))
#define AAE_RD_CTRL_S0L11_GLB_ALPHA01_ADDR(base) ((base) + (0x01AC))
#define AAE_RD_CTRL_S0L12_GLB_ALPHA01_ADDR(base) ((base) + (0x01B0))
#define AAE_RD_CTRL_S0L13_GLB_ALPHA01_ADDR(base) ((base) + (0x01B4))
#define AAE_RD_CTRL_S0L14_GLB_ALPHA01_ADDR(base) ((base) + (0x01B8))
#define AAE_RD_CTRL_S0L15_GLB_ALPHA01_ADDR(base) ((base) + (0x01BC))
#define AAE_RD_CTRL_S0L0_GLB_ALPHA23_ADDR(base) ((base) + (0x01C0))
#define AAE_RD_CTRL_S0L1_GLB_ALPHA23_ADDR(base) ((base) + (0x01C4))
#define AAE_RD_CTRL_S0L2_GLB_ALPHA23_ADDR(base) ((base) + (0x01C8))
#define AAE_RD_CTRL_S0L3_GLB_ALPHA23_ADDR(base) ((base) + (0x01CC))
#define AAE_RD_CTRL_S0L4_GLB_ALPHA23_ADDR(base) ((base) + (0x01D0))
#define AAE_RD_CTRL_S0L5_GLB_ALPHA23_ADDR(base) ((base) + (0x01D4))
#define AAE_RD_CTRL_S0L6_GLB_ALPHA23_ADDR(base) ((base) + (0x01D8))
#define AAE_RD_CTRL_S0L7_GLB_ALPHA23_ADDR(base) ((base) + (0x01DC))
#define AAE_RD_CTRL_S0L8_GLB_ALPHA23_ADDR(base) ((base) + (0x01E0))
#define AAE_RD_CTRL_S0L9_GLB_ALPHA23_ADDR(base) ((base) + (0x01E4))
#define AAE_RD_CTRL_S0L10_GLB_ALPHA23_ADDR(base) ((base) + (0x01E8))
#define AAE_RD_CTRL_S0L11_GLB_ALPHA23_ADDR(base) ((base) + (0x01EC))
#define AAE_RD_CTRL_S0L12_GLB_ALPHA23_ADDR(base) ((base) + (0x01F0))
#define AAE_RD_CTRL_S0L13_GLB_ALPHA23_ADDR(base) ((base) + (0x01F4))
#define AAE_RD_CTRL_S0L14_GLB_ALPHA23_ADDR(base) ((base) + (0x01F8))
#define AAE_RD_CTRL_S0L15_GLB_ALPHA23_ADDR(base) ((base) + (0x01FC))
#define AAE_RD_CTRL_S1L0_GLB_ALPHA01_ADDR(base) ((base) + (0x0200))
#define AAE_RD_CTRL_S1L1_GLB_ALPHA01_ADDR(base) ((base) + (0x0204))
#define AAE_RD_CTRL_S1L2_GLB_ALPHA01_ADDR(base) ((base) + (0x0208))
#define AAE_RD_CTRL_S1L3_GLB_ALPHA01_ADDR(base) ((base) + (0x020C))
#define AAE_RD_CTRL_S1L4_GLB_ALPHA01_ADDR(base) ((base) + (0x0210))
#define AAE_RD_CTRL_S1L5_GLB_ALPHA01_ADDR(base) ((base) + (0x0214))
#define AAE_RD_CTRL_S1L6_GLB_ALPHA01_ADDR(base) ((base) + (0x0218))
#define AAE_RD_CTRL_S1L7_GLB_ALPHA01_ADDR(base) ((base) + (0x021C))
#define AAE_RD_CTRL_S1L0_GLB_ALPHA23_ADDR(base) ((base) + (0x0220))
#define AAE_RD_CTRL_S1L1_GLB_ALPHA23_ADDR(base) ((base) + (0x0224))
#define AAE_RD_CTRL_S1L2_GLB_ALPHA23_ADDR(base) ((base) + (0x0228))
#define AAE_RD_CTRL_S1L3_GLB_ALPHA23_ADDR(base) ((base) + (0x022C))
#define AAE_RD_CTRL_S1L4_GLB_ALPHA23_ADDR(base) ((base) + (0x0230))
#define AAE_RD_CTRL_S1L5_GLB_ALPHA23_ADDR(base) ((base) + (0x0234))
#define AAE_RD_CTRL_S1L6_GLB_ALPHA23_ADDR(base) ((base) + (0x0238))
#define AAE_RD_CTRL_S1L7_GLB_ALPHA23_ADDR(base) ((base) + (0x023C))
#define AAE_RD_CTRL_S2L0_GLB_ALPHA01_ADDR(base) ((base) + (0x0240))
#define AAE_RD_CTRL_S2L0_GLB_ALPHA23_ADDR(base) ((base) + (0x0244))
#define AAE_RD_CTRL_S3L0_GLB_ALPHA01_ADDR(base) ((base) + (0x0248))
#define AAE_RD_CTRL_S3L0_GLB_ALPHA23_ADDR(base) ((base) + (0x024C))
#define AAE_RD_CTRL_CLK_SEL_ADDR(base) ((base) + (0x0250))
#define AAE_RD_CTRL_CLK_EN_ADDR(base) ((base) + (0x0254))
#define AAE_RD_CTRL_ARSR1_CH_SEL_ADDR(base) ((base) + (0x0258))
#define AAE_RD_CTRL_CLK_DBG1_ADDR(base) ((base) + (0x025C))
#define AAE_RD_CTRL_CH0_DBG0_ADDR(base) ((base) + (0x0260))
#define AAE_RD_CTRL_CH0_DBG1_ADDR(base) ((base) + (0x0264))
#define AAE_RD_CTRL_CH0_DBG2_ADDR(base) ((base) + (0x0268))
#define AAE_RD_CTRL_CH0_DBG3_ADDR(base) ((base) + (0x026C))
#define AAE_RD_CTRL_CH1_DBG0_ADDR(base) ((base) + (0x0270))
#define AAE_RD_CTRL_CH1_DBG1_ADDR(base) ((base) + (0x0274))
#define AAE_RD_CTRL_CH1_DBG2_ADDR(base) ((base) + (0x0278))
#define AAE_RD_CTRL_CH1_DBG3_ADDR(base) ((base) + (0x027C))
#define AAE_RD_CTRL_CH2_DBG0_ADDR(base) ((base) + (0x0280))
#define AAE_RD_CTRL_CH2_DBG1_ADDR(base) ((base) + (0x0284))
#define AAE_RD_CTRL_CH2_DBG2_ADDR(base) ((base) + (0x0288))
#define AAE_RD_CTRL_CH2_DBG3_ADDR(base) ((base) + (0x028C))
#define AAE_RD_CTRL_CH3_DBG0_ADDR(base) ((base) + (0x0290))
#define AAE_RD_CTRL_CH3_DBG1_ADDR(base) ((base) + (0x0294))
#define AAE_RD_CTRL_CH3_DBG2_ADDR(base) ((base) + (0x0298))
#define AAE_RD_CTRL_CH3_DBG3_ADDR(base) ((base) + (0x029C))
#define AAE_RD_CTRL_CH4_DBG0_ADDR(base) ((base) + (0x02A0))
#define AAE_RD_CTRL_CH4_DBG1_ADDR(base) ((base) + (0x02A4))
#define AAE_RD_CTRL_CH4_DBG2_ADDR(base) ((base) + (0x02A8))
#define AAE_RD_CTRL_CH4_DBG3_ADDR(base) ((base) + (0x02AC))
#define AAE_RD_CTRL_CH5_DBG0_ADDR(base) ((base) + (0x02B0))
#define AAE_RD_CTRL_CH5_DBG1_ADDR(base) ((base) + (0x02B4))
#define AAE_RD_CTRL_CH5_DBG2_ADDR(base) ((base) + (0x02B8))
#define AAE_RD_CTRL_CH5_DBG3_ADDR(base) ((base) + (0x02BC))
#define AAE_RD_CTRL_CH6_DBG0_ADDR(base) ((base) + (0x02C0))
#define AAE_RD_CTRL_CH6_DBG1_ADDR(base) ((base) + (0x02C4))
#define AAE_RD_CTRL_CH6_DBG2_ADDR(base) ((base) + (0x02C8))
#define AAE_RD_CTRL_CH6_DBG3_ADDR(base) ((base) + (0x02CC))
#define AAE_RD_CTRL_CH7_DBG0_ADDR(base) ((base) + (0x02D0))
#define AAE_RD_CTRL_CH7_DBG1_ADDR(base) ((base) + (0x02D4))
#define AAE_RD_CTRL_CH7_DBG2_ADDR(base) ((base) + (0x02D8))
#define AAE_RD_CTRL_CH7_DBG3_ADDR(base) ((base) + (0x02DC))
#define AAE_RD_CTRL_CH8_DBG0_ADDR(base) ((base) + (0x02E0))
#define AAE_RD_CTRL_CH8_DBG1_ADDR(base) ((base) + (0x02E4))
#define AAE_RD_CTRL_CH8_DBG2_ADDR(base) ((base) + (0x02E8))
#define AAE_RD_CTRL_CH8_DBG3_ADDR(base) ((base) + (0x02EC))
#define AAE_RD_CTRL_CH9_DBG0_ADDR(base) ((base) + (0x02F0))
#define AAE_RD_CTRL_CH9_DBG1_ADDR(base) ((base) + (0x02F4))
#define AAE_RD_CTRL_CH9_DBG2_ADDR(base) ((base) + (0x02F8))
#define AAE_RD_CTRL_CH9_DBG3_ADDR(base) ((base) + (0x02FC))
#define AAE_RD_CTRL_CH10_DBG0_ADDR(base) ((base) + (0x0300))
#define AAE_RD_CTRL_CH10_DBG1_ADDR(base) ((base) + (0x0304))
#define AAE_RD_CTRL_CH10_DBG2_ADDR(base) ((base) + (0x0308))
#define AAE_RD_CTRL_CH10_DBG3_ADDR(base) ((base) + (0x030C))
#define AAE_RD_CTRL_CH11_DBG0_ADDR(base) ((base) + (0x0310))
#define AAE_RD_CTRL_CH11_DBG1_ADDR(base) ((base) + (0x0314))
#define AAE_RD_CTRL_CH11_DBG2_ADDR(base) ((base) + (0x0318))
#define AAE_RD_CTRL_CH11_DBG3_ADDR(base) ((base) + (0x031C))
#define AAE_RD_CTRL_CH12_DBG0_ADDR(base) ((base) + (0x0320))
#define AAE_RD_CTRL_CH12_DBG1_ADDR(base) ((base) + (0x0324))
#define AAE_RD_CTRL_CH12_DBG2_ADDR(base) ((base) + (0x0328))
#define AAE_RD_CTRL_CH12_DBG3_ADDR(base) ((base) + (0x032C))
#define AAE_RD_CTRL_CH13_DBG0_ADDR(base) ((base) + (0x0330))
#define AAE_RD_CTRL_CH13_DBG1_ADDR(base) ((base) + (0x0334))
#define AAE_RD_CTRL_CH13_DBG2_ADDR(base) ((base) + (0x0338))
#define AAE_RD_CTRL_CH13_DBG3_ADDR(base) ((base) + (0x033C))
#define AAE_RD_CTRL_CH14_DBG0_ADDR(base) ((base) + (0x0340))
#define AAE_RD_CTRL_CH14_DBG1_ADDR(base) ((base) + (0x0344))
#define AAE_RD_CTRL_CH14_DBG2_ADDR(base) ((base) + (0x0348))
#define AAE_RD_CTRL_CH14_DBG3_ADDR(base) ((base) + (0x034C))
#define AAE_RD_CTRL_CH15_DBG0_ADDR(base) ((base) + (0x0350))
#define AAE_RD_CTRL_CH15_DBG1_ADDR(base) ((base) + (0x0354))
#define AAE_RD_CTRL_CH15_DBG2_ADDR(base) ((base) + (0x0358))
#define AAE_RD_CTRL_CH15_DBG3_ADDR(base) ((base) + (0x035C))
#define AAE_RD_CTRL_CH16_DBG0_ADDR(base) ((base) + (0x0360))
#define AAE_RD_CTRL_CH16_DBG1_ADDR(base) ((base) + (0x0364))
#define AAE_RD_CTRL_CH16_DBG2_ADDR(base) ((base) + (0x0368))
#define AAE_RD_CTRL_CH16_DBG3_ADDR(base) ((base) + (0x036C))
#define AAE_RD_CTRL_NOP_LINE_END_FLAG_ADDR(base) ((base) + (0x0370))
#define AAE_RD_CTRL_CTRL_MODE_ADDR(base) ((base) + (0x0374))
#define AAE_RD_CTRL_CH0_LAYER_ID_ADDR(base) ((base) + (0x0378))
#define AAE_RD_CTRL_CH1_LAYER_ID_ADDR(base) ((base) + (0x037C))
#define AAE_RD_CTRL_CH2_LAYER_ID_ADDR(base) ((base) + (0x0380))
#define AAE_RD_CTRL_CH3_LAYER_ID_ADDR(base) ((base) + (0x0384))
#define AAE_RD_CTRL_CH4_LAYER_ID_ADDR(base) ((base) + (0x0388))
#define AAE_RD_CTRL_CH5_LAYER_ID_ADDR(base) ((base) + (0x038C))
#define AAE_RD_CTRL_CH6_LAYER_ID_ADDR(base) ((base) + (0x0390))
#define AAE_RD_CTRL_CH7_LAYER_ID_ADDR(base) ((base) + (0x0394))
#define AAE_RD_CTRL_CH8_LAYER_ID_ADDR(base) ((base) + (0x0398))
#define AAE_RD_CTRL_CH9_LAYER_ID_ADDR(base) ((base) + (0x039C))
#define AAE_RD_CTRL_CH10_LAYER_ID_ADDR(base) ((base) + (0x0400))
#define AAE_RD_CTRL_CH11_LAYER_ID_ADDR(base) ((base) + (0x0404))
#define AAE_RD_CTRL_CH12_LAYER_ID_ADDR(base) ((base) + (0x0408))
#define AAE_RD_CTRL_CH13_LAYER_ID_ADDR(base) ((base) + (0x040C))
#define AAE_RD_CTRL_CH14_LAYER_ID_ADDR(base) ((base) + (0x0410))
#define AAE_RD_CTRL_CH15_LAYER_ID_ADDR(base) ((base) + (0x0414))
#define AAE_RD_CTRL_CH16_LAYER_ID_ADDR(base) ((base) + (0x0418))
#define AAE_RD_CTRL_SCN0_LINE_NUM_ADDR(base) ((base) + (0x041C))
#define AAE_RD_CTRL_SCN1_LINE_NUM_ADDR(base) ((base) + (0x0420))
#define AAE_RD_CTRL_SCN2_LINE_NUM_ADDR(base) ((base) + (0x0424))
#define AAE_RD_CTRL_SCN3_LINE_NUM_ADDR(base) ((base) + (0x0428))
#define AAE_RD_CTRL_LINE_CNT_CLEAR_ADDR(base) ((base) + (0x042C))
#define AAE_RD_CTRL_SCN0_LINE_CNT_ADDR(base) ((base) + (0x0430))
#define AAE_RD_CTRL_SCN1_LINE_CNT_ADDR(base) ((base) + (0x0434))
#define AAE_RD_CTRL_SCN2_LINE_CNT_ADDR(base) ((base) + (0x0438))
#define AAE_RD_CTRL_SCN3_LINE_CNT_ADDR(base) ((base) + (0x043C))
#define AAE_RDFC_PACK_WRAP_S0_SWAP_ALPHA_ADDR(base,rdfc_scn0_layer_num) ((base) + (0x0000+(rdfc_scn0_layer_num)*0x4))
#define AAE_RDFC_PACK_WRAP_S1_SWAP_ALPHA_ADDR(base,rdfc_scn1_layer_num) ((base) + (0x0040+(rdfc_scn1_layer_num)*0x4))
#define AAE_RDFC_PACK_WRAP_S2_SWAP_ALPHA_ADDR(base,rdfc_scn2_layer_num) ((base) + (0x0060+(rdfc_scn2_layer_num)*0x4))
#define AAE_RDFC_PACK_WRAP_S4_SWAP_ALPHA_ADDR(base,rdfc_scn4_layer_num) ((base) + (0x0064+(rdfc_scn4_layer_num)*0x4))
#define AAE_RDFC_PACK_WRAP_RDFC_DEBUG0_ADDR(base) ((base) + (0x00a0))
#define AAE_RDFC_PACK_WRAP_RDFC_DEBUG1_ADDR(base) ((base) + (0x00a4))
#define AAE_DBCU_SMARTDMA_0_AXI_SEL_ADDR(base) ((base) + (0x0000))
#define AAE_DBCU_SMARTDMA_1_AXI_SEL_ADDR(base) ((base) + (0x0004))
#define AAE_DBCU_SMARTDMA_2_AXI_SEL_ADDR(base) ((base) + (0x0008))
#define AAE_DBCU_SMARTDMA_3_AXI_SEL_ADDR(base) ((base) + (0x000C))
#define AAE_DBCU_WCH_0_AXI_SEL_ADDR(base) ((base) + (0x0010))
#define AAE_DBCU_WCH_1_AXI_SEL_ADDR(base) ((base) + (0x0014))
#define AAE_DBCU_WCH_2_AXI_SEL_ADDR(base) ((base) + (0x0018))
#define AAE_DBCU_CMDLIST_AXI_SEL_ADDR(base) ((base) + (0x001C))
#define AAE_DBCU_ARCACH0_ADDR_THRH_ADDR(base) ((base) + (0x0020))
#define AAE_DBCU_ARCACH0_ADDR_THRL_ADDR(base) ((base) + (0x0024))
#define AAE_DBCU_ARCACH0_VALUE0_ADDR(base) ((base) + (0x0028))
#define AAE_DBCU_ARCACH0_VALUE1_ADDR(base) ((base) + (0x002C))
#define AAE_DBCU_ARCACH1_ADDR_THRH_ADDR(base) ((base) + (0x0030))
#define AAE_DBCU_ARCACH1_ADDR_THRL_ADDR(base) ((base) + (0x0034))
#define AAE_DBCU_ARCACH1_VALUE0_ADDR(base) ((base) + (0x0038))
#define AAE_DBCU_ARCACH1_VALUE1_ADDR(base) ((base) + (0x003C))
#define AAE_DBCU_AWCACH0_ADDR_THRH_ADDR(base) ((base) + (0x0040))
#define AAE_DBCU_AWCACH0_ADDR_THRL_ADDR(base) ((base) + (0x0044))
#define AAE_DBCU_AWCACH0_VALUE0_ADDR(base) ((base) + (0x0048))
#define AAE_DBCU_AWCACH0_VALUE1_ADDR(base) ((base) + (0x004C))
#define AAE_DBCU_ARCACH2_ADDR_THRH_ADDR(base) ((base) + (0x0050))
#define AAE_DBCU_ARCACH2_ADDR_THRL_ADDR(base) ((base) + (0x0054))
#define AAE_DBCU_ARCACH2_VALUE0_ADDR(base) ((base) + (0x0058))
#define AAE_DBCU_ARCACH2_VALUE1_ADDR(base) ((base) + (0x005C))
#define AAE_DBCU_AWCACH2_ADDR_THRH_ADDR(base) ((base) + (0x0060))
#define AAE_DBCU_AWCACH2_ADDR_THRL_ADDR(base) ((base) + (0x0064))
#define AAE_DBCU_AWCACH2_VALUE0_ADDR(base) ((base) + (0x0068))
#define AAE_DBCU_AWCACH2_VALUE1_ADDR(base) ((base) + (0x006C))
#define AAE_DBCU_ARCACH3_ADDR_THRH_ADDR(base) ((base) + (0x0070))
#define AAE_DBCU_ARCACH3_ADDR_THRL_ADDR(base) ((base) + (0x0074))
#define AAE_DBCU_ARCACH3_VALUE0_ADDR(base) ((base) + (0x0078))
#define AAE_DBCU_ARCACH3_VALUE1_ADDR(base) ((base) + (0x007C))
#define AAE_DBCU_SMARTDMA_0_MID_ADDR(base) ((base) + (0x0400))
#define AAE_DBCU_SMARTDMA_1_MID_ADDR(base) ((base) + (0x0404))
#define AAE_DBCU_SMARTDMA_2_MID_ADDR(base) ((base) + (0x0408))
#define AAE_DBCU_SMARTDMA_3_MID_ADDR(base) ((base) + (0x040C))
#define AAE_DBCU_WCH_0_MID_ADDR(base) ((base) + (0x0410))
#define AAE_DBCU_WCH_1_MID_ADDR(base) ((base) + (0x0414))
#define AAE_DBCU_WCH_2_MID_ADDR(base) ((base) + (0x0418))
#define AAE_DBCU_CMDLIST_MID_ADDR(base) ((base) + (0x041C))
#define AAE_DBCU_MMU0_ID_ATTR_ADDR(base) ((base) + (0x0420))
#define AAE_DBCU_MMU1_ID_ATTR_ADDR(base) ((base) + (0x050C))
#define AAE_DBCU_MMU0_ID_ATTR_NS_ADDR(base) ((base) + (0x05F8))
#define AAE_DBCU_MMU1_ID_ATTR_NS_ADDR(base) ((base) + (0x06E4))
#define AAE_DBCU_AXI2_RID_MSK0_ADDR(base) ((base) + (0x0800))
#define AAE_DBCU_AXI2_RID_MSK1_ADDR(base) ((base) + (0x0804))
#define AAE_DBCU_AXI2_WID_MSK_ADDR(base) ((base) + (0x0808))
#define AAE_DBCU_AXI2_R_QOS_MAP_ADDR(base) ((base) + (0x080C))
#define AAE_DBCU_AXI3_RID_MSK0_ADDR(base) ((base) + (0x0810))
#define AAE_DBCU_AXI3_RID_MSK1_ADDR(base) ((base) + (0x0814))
#define AAE_DBCU_AXI3_R_QOS_MAP_ADDR(base) ((base) + (0x0818))
#define AAE_DBCU_AXI0_RID_MSK0_ADDR(base) ((base) + (0x081C))
#define AAE_DBCU_AXI0_RID_MSK1_ADDR(base) ((base) + (0x0820))
#define AAE_DBCU_AXI0_WID_MSK_ADDR(base) ((base) + (0x0824))
#define AAE_DBCU_AXI0_R_QOS_MAP_ADDR(base) ((base) + (0x0828))
#define AAE_DBCU_AXI1_RID_MSK0_ADDR(base) ((base) + (0x082C))
#define AAE_DBCU_AXI1_RID_MSK1_ADDR(base) ((base) + (0x0830))
#define AAE_DBCU_AXI1_R_QOS_MAP_ADDR(base) ((base) + (0x0834))
#define AAE_DBCU_AXI0_READ_FLUX_HIGH_CFG_ADDR(base) ((base) + (0x0838))
#define AAE_DBCU_AXI0_READ_FLUX_LOW_CFG_ADDR(base) ((base) + (0x083C))
#define AAE_DBCU_AXI0_WRITE_FLUX_HIGH_CFG_ADDR(base) ((base) + (0x0840))
#define AAE_DBCU_AXI0_WRITE_FLUX_LOW_CFG_ADDR(base) ((base) + (0x0844))
#define AAE_DBCU_AXI1_READ_FLUX_HIGH_CFG_ADDR(base) ((base) + (0x0848))
#define AAE_DBCU_AXI1_READ_FLUX_LOW_CFG_ADDR(base) ((base) + (0x084C))
#define AAE_DBCU_AXI2_READ_FLUX_HIGH_CFG_ADDR(base) ((base) + (0x0850))
#define AAE_DBCU_AXI2_READ_FLUX_LOW_CFG_ADDR(base) ((base) + (0x0854))
#define AAE_DBCU_AXI2_WRITE_FLUX_HIGH_CFG_ADDR(base) ((base) + (0x0858))
#define AAE_DBCU_AXI2_WRITE_FLUX_LOW_CFG_ADDR(base) ((base) + (0x085C))
#define AAE_DBCU_AXI3_READ_FLUX_HIGH_CFG_ADDR(base) ((base) + (0x0860))
#define AAE_DBCU_AXI3_READ_FLUX_LOW_CFG_ADDR(base) ((base) + (0x0864))
#define AAE_DBCU_CLK_SEL_0_ADDR(base) ((base) + (0x0868))
#define AAE_DBCU_CLK_SEL_1_ADDR(base) ((base) + (0x086C))
#define AAE_DBCU_CLK_EN_0_ADDR(base) ((base) + (0x0870))
#define AAE_DBCU_CLK_EN_1_ADDR(base) ((base) + (0x0874))
#define AAE_DBCU_MONITOR_TIMER_INI_ADDR(base) ((base) + (0x0878))
#define AAE_DBCU_DEBUG_BUF_BASE_ADDR(base) ((base) + (0x087C))
#define AAE_DBCU_DEBUG_CTRL_ADDR(base) ((base) + (0x0880))
#define AAE_DBCU_AIF_SHADOW_READ_ADDR(base) ((base) + (0x0884))
#define AAE_DBCU_MONITOR_EN_ADDR(base) ((base) + (0x0888))
#define AAE_DBCU_MONITOR_CTRL_ADDR(base) ((base) + (0x088C))
#define AAE_DBCU_MONITOR_SAMPLE_MUN_ADDR(base) ((base) + (0x0890))
#define AAE_DBCU_MONITOR_SAMPLE_TIME_ADDR(base) ((base) + (0x0894))
#define AAE_DBCU_MONITOR_SAMPLE_FLOW_ADDR(base) ((base) + (0x0898))
#define AAE_DBCU_AXI_DOMAIN_CFG_ADDR(base) ((base) + (0x089C))
#define AAE_DBCU_RELOAD_CTRL_ADDR(base) ((base) + (0x08A0))
#define AAE_DBCU_MONITOR_WR_ST_0_ADDR(base) ((base) + (0x08D0))
#define AAE_DBCU_MONITOR_WR_ST_1_ADDR(base) ((base) + (0x08E0))
#define AAE_DBCU_MONITOR_WR_ST_2_ADDR(base) ((base) + (0x08E4))
#define AAE_DBCU_MONITOR_WR_ST_3_ADDR(base) ((base) + (0x08E8))
#define AAE_DBCU_MONITOR_WR_ST_4_ADDR(base) ((base) + (0x08EC))
#define AAE_DBCU_MONITOR_WR_ST_5_ADDR(base) ((base) + (0x08F0))
#define AAE_DBCU_MONITOR_WR_ST_6_ADDR(base) ((base) + (0x08F4))
#define AAE_DBCU_MONITOR_WR_ST_7_ADDR(base) ((base) + (0x08F8))
#define AAE_DBCU_MONITOR_WR_ST_8_ADDR(base) ((base) + (0x08FC))
#define AAE_DBCU_MONITOR_RD_ST_0_ADDR(base) ((base) + (0x0900))
#define AAE_DBCU_MONITOR_RD_ST_1_ADDR(base) ((base) + (0x0910))
#define AAE_DBCU_MONITOR_RD_ST_2_ADDR(base) ((base) + (0x0914))
#define AAE_DBCU_MONITOR_RD_ST_3_ADDR(base) ((base) + (0x0918))
#define AAE_DBCU_MONITOR_RD_ST_4_ADDR(base) ((base) + (0x091C))
#define AAE_DBCU_MONITOR_RD_ST_5_ADDR(base) ((base) + (0x0920))
#define AAE_DBCU_MONITOR_RD_ST_6_ADDR(base) ((base) + (0x0924))
#define AAE_DBCU_MONITOR_RD_ST_7_ADDR(base) ((base) + (0x0928))
#define AAE_DBCU_MONITOR_RD_ST_8_ADDR(base) ((base) + (0x092C))
#define AAE_DBCU_MONITOR_OS_R0_ADDR(base) ((base) + (0x0930))
#define AAE_DBCU_MONITOR_OS_R1_ADDR(base) ((base) + (0x0940))
#define AAE_DBCU_MONITOR_OS_R2_ADDR(base) ((base) + (0x0944))
#define AAE_DBCU_MONITOR_OS_R3_ADDR(base) ((base) + (0x0948))
#define AAE_DBCU_MONITOR_OS_R4_ADDR(base) ((base) + (0x094C))
#define AAE_DBCU_MONITOR_OS_W0_ADDR(base) ((base) + (0x0950))
#define AAE_DBCU_MONITOR_OS_W1_ADDR(base) ((base) + (0x0960))
#define AAE_DBCU_MONITOR_OS_W2_ADDR(base) ((base) + (0x0964))
#define AAE_DBCU_MONITOR_OS_W3_ADDR(base) ((base) + (0x096C))
#define AAE_DBCU_AIF_STAT_0_ADDR(base) ((base) + (0x0970))
#define AAE_DBCU_AIF_STAT_1_ADDR(base) ((base) + (0x0974))
#define AAE_DBCU_AIF_STAT_2_ADDR(base) ((base) + (0x0978))
#define AAE_DBCU_AIF_STAT_3_ADDR(base) ((base) + (0x097C))
#define AAE_DBCU_AIF_STAT_4_ADDR(base) ((base) + (0x0980))
#define AAE_DBCU_AIF_STAT_5_ADDR(base) ((base) + (0x0984))
#define AAE_DBCU_AIF_STAT_6_ADDR(base) ((base) + (0x0988))
#define AAE_DBCU_AIF_STAT_7_ADDR(base) ((base) + (0x098C))
#define AAE_DBCU_AIF_STAT_8_ADDR(base) ((base) + (0x0990))
#define AAE_DBCU_AIF_STAT_9_ADDR(base) ((base) + (0x0994))
#define AAE_DBCU_AIF_STAT_10_ADDR(base) ((base) + (0x0998))
#define AAE_DBCU_AIF_STAT_11_ADDR(base) ((base) + (0x099C))
#define AAE_DBCU_AIF_STAT_12_ADDR(base) ((base) + (0x09A0))
#define AAE_DBCU_AIF_STAT_13_ADDR(base) ((base) + (0x09A4))
#define AAE_DBCU_AIF_STAT_14_ADDR(base) ((base) + (0x09A8))
#define AAE_DBCU_AIF_STAT_15_ADDR(base) ((base) + (0x09AC))
#define AAE_DBCU_MIF_SHADOW_READ_ADDR(base) ((base) + (0x0B08))
#define AAE_DBCU_AIF_CMD_RELOAD_ADDR(base) ((base) + (0x0B0C))
#define AAE_DBCU_MIF_CTRL_SMARTDMA_0_ADDR(base) ((base) + (0x0B10))
#define AAE_DBCU_MIF_LEAD_SMARTDMA_0_ADDR(base) ((base) + (0x0B14))
#define AAE_DBCU_MIF_OS_SMARTDMA_0_ADDR(base) ((base) + (0x0B18))
#define AAE_DBCU_MIF_STAT_SMARTDMA_0_ADDR(base) ((base) + (0x0B1C))
#define AAE_DBCU_MIF_CTRL_SMARTDMA_1_ADDR(base) ((base) + (0x0B20))
#define AAE_DBCU_MIF_LEAD_SMARTDMA_1_ADDR(base) ((base) + (0x0B24))
#define AAE_DBCU_MIF_OS_SMARTDMA_1_ADDR(base) ((base) + (0x0B28))
#define AAE_DBCU_MIF_STAT_SMARTDMA_1_ADDR(base) ((base) + (0x0B2C))
#define AAE_DBCU_MIF_CTRL_SMARTDMA_2_ADDR(base) ((base) + (0x0B30))
#define AAE_DBCU_MIF_LEAD_SMARTDMA_2_ADDR(base) ((base) + (0x0B34))
#define AAE_DBCU_MIF_OS_SMARTDMA_2_ADDR(base) ((base) + (0x0B38))
#define AAE_DBCU_MIF_STAT_SMARTDMA_2_ADDR(base) ((base) + (0x0B3C))
#define AAE_DBCU_MIF_CTRL_SMARTDMA_3_ADDR(base) ((base) + (0x0B40))
#define AAE_DBCU_MIF_LEAD_SMARTDMA_3_ADDR(base) ((base) + (0x0B44))
#define AAE_DBCU_MIF_OS_SMARTDMA_3_ADDR(base) ((base) + (0x0B48))
#define AAE_DBCU_MIF_STAT_SMARTDMA_3_ADDR(base) ((base) + (0x0B4C))
#define AAE_DBCU_MIF_CTRL_WCH0_ADDR(base) ((base) + (0x0B50))
#define AAE_DBCU_MIF_LEAD_CTRL_WCH0_ADDR(base) ((base) + (0x0B54))
#define AAE_DBCU_MIF_OS_CTRL_WCH0_ADDR(base) ((base) + (0x0B58))
#define AAE_DBCU_MIF_STAT_WCH0_ADDR(base) ((base) + (0x0B5C))
#define AAE_DBCU_MIF_CTRL_WCH1_ADDR(base) ((base) + (0x0B60))
#define AAE_DBCU_MIF_LEAD_CTRL_WCH1_ADDR(base) ((base) + (0x0B64))
#define AAE_DBCU_MIF_OS_CTRL_WCH1_ADDR(base) ((base) + (0x0B68))
#define AAE_DBCU_MIF_STAT_WCH1_ADDR(base) ((base) + (0x0B6C))
#define AAE_DBCU_MIF_CTRL_WCH2_ADDR(base) ((base) + (0x0B70))
#define AAE_DBCU_MIF_LEAD_CTRL_WCH2_ADDR(base) ((base) + (0x0B74))
#define AAE_DBCU_MIF_OS_CTRL_WCH2_ADDR(base) ((base) + (0x0B78))
#define AAE_DBCU_MIF_STAT_WCH2_ADDR(base) ((base) + (0x0B7C))
#define AAE_RD_BLK_CTRL_BLK_RD_EN_ADDR(base) ((base) + (0x0000))
#define AAE_RD_BLK_CTRL_DBG0_ADDR(base) ((base) + (0x0004))
#define AAE_RD_BLK_CTRL_DBG1_ADDR(base) ((base) + (0x0008))
#define AAE_RD_BLK_CTRL_DBG2_ADDR(base) ((base) + (0x000C))
#define AAE_RD_BLK_CTRL_DBG3_ADDR(base) ((base) + (0x0010))
#define AAE_RD_BLK_CTRL_DBG4_ADDR(base) ((base) + (0x0014))
#define AAE_ROT_WDMA_DMA_CTRL0_ADDR(base) ((base) + (0x0000))
#define AAE_ROT_WDMA_DMA_CTRL1_ADDR(base) ((base) + (0x0004))
#define AAE_ROT_WDMA_DMA_IMG_SIZE_ADDR(base) ((base) + (0x0008))
#define AAE_ROT_WDMA_DMA_PTR0_ADDR(base) ((base) + (0x000C))
#define AAE_ROT_WDMA_DMA_STRIDE0_ADDR(base) ((base) + (0x0010))
#define AAE_ROT_WDMA_DMA_PTR1_ADDR(base) ((base) + (0x0014))
#define AAE_ROT_WDMA_DMA_STRIDE1_ADDR(base) ((base) + (0x0018))
#define AAE_ROT_WDMA_DMA_PTR2_ADDR(base) ((base) + (0x001C))
#define AAE_ROT_WDMA_DMA_STRIDE2_ADDR(base) ((base) + (0x0020))
#define AAE_ROT_WDMA_DMA_PTR3_ADDR(base) ((base) + (0x0024))
#define AAE_ROT_WDMA_DMA_STRIDE3_ADDR(base) ((base) + (0x0028))
#define AAE_ROT_WDMA_DMA_CMP_HDR_PTR_OFT_ADDR(base) ((base) + (0x002C))
#define AAE_ROT_WDMA_DMA_CH_SEGMENT_CTRL_ADDR(base) ((base) + (0x0030))
#define AAE_ROT_WDMA_DMA_CMP_CTRL_ADDR(base) ((base) + (0x0034))
#define AAE_ROT_WDMA_DMA_CMP_PIC_BLKS_ADDR(base) ((base) + (0x0038))
#define AAE_ROT_WDMA_DMA_CMP_MEM_CTRL0_ADDR(base) ((base) + (0x003C))
#define AAE_ROT_WDMA_DMA_CMP_MEM_CTRL1_ADDR(base) ((base) + (0x0040))
#define AAE_ROT_WDMA_DMA_CMP_RESEVED_ADDR(base) ((base) + (0x0044))
#define AAE_ROT_WDMA_DMA_CMP_INFO_OUT0_ADDR(base) ((base) + (0x0048))
#define AAE_ROT_WDMA_DMA_CMP_INFO_OUT1_ADDR(base) ((base) + (0x004C))
#define AAE_ROT_WDMA_DMA_INTR_ADDR(base) ((base) + (0x0050))
#define AAE_ROT_WDMA_DMA_RSV_IN0_ADDR(base) ((base) + (0x0054))
#define AAE_ROT_WDMA_DMA_RSV_IN1_ADDR(base) ((base) + (0x0058))
#define AAE_ROT_WDMA_DMA_RSV_IN2_ADDR(base) ((base) + (0x005C))
#define AAE_ROT_WDMA_DMA_RSV_IN3_ADDR(base) ((base) + (0x0060))
#define AAE_ROT_WDMA_DMA_MONITOR_OUT0_ADDR(base) ((base) + (0x0064))
#define AAE_ROT_WDMA_DMA_MONITOR_OUT1_ADDR(base) ((base) + (0x0068))
#define AAE_ROT_WDMA_DMA_MONITOR_OUT2_ADDR(base) ((base) + (0x006C))
#define AAE_ROT_WDMA_DMA_MONITOR_OUT3_ADDR(base) ((base) + (0x0070))
#define AAE_ROT_WDMA_DMA_MONITOR_OUT4_ADDR(base) ((base) + (0x0074))
#define AAE_ROT_WDMA_DMA_MONITOR_OUT5_ADDR(base) ((base) + (0x0078))
#define AAE_ROT_WDMA_WTL_CTRL_ADDR(base) ((base) + (0x00A0))
#define AAE_ROT_WDMA_WLT_LINE_THRESHOLD1_ADDR(base) ((base) + (0x00A4))
#define AAE_ROT_WDMA_WLT_LINE_THRESHOLD3_ADDR(base) ((base) + (0x00A8))
#define AAE_ROT_WDMA_WLT_BASE_LINE_OFFSET_ADDR(base) ((base) + (0x00AC))
#define AAE_ROT_WDMA_WLT_DMA_ADDR_ADDR(base) ((base) + (0x00B0))
#define AAE_ROT_WDMA_WLT_DMA_QOS_ADDR(base) ((base) + (0x00B4))
#define AAE_ROT_WDMA_WLT_C_LINE_NUM_ADDR(base) ((base) + (0x00B8))
#define AAE_ROT_WDMA_WLT_C_SLICE_NUM_ADDR(base) ((base) + (0x00BC))
#define AAE_ROT_WDMA_REG_DEFAULT_ADDR(base) ((base) + (0x00D0))
#define AAE_ROT_WDMA_CH_RD_SHADOW_ADDR(base) ((base) + (0x00D4))
#define AAE_ROT_WDMA_CH_CTL_ADDR(base) ((base) + (0x00D8))
#define AAE_ROT_WDMA_CH_SECU_EN_ADDR(base) ((base) + (0x00DC))
#define AAE_ROT_WDMA_CH_SW_END_REQ_ADDR(base) ((base) + (0x00E0))
#define AAE_ROT_WDMA_CH_CLK_SEL_ADDR(base) ((base) + (0x00E4))
#define AAE_ROT_WDMA_CH_CLK_EN_ADDR(base) ((base) + (0x00E8))
#define AAE_ROT_WDMA_CH_DBG0_ADDR(base) ((base) + (0x00EC))
#define AAE_ROT_WDMA_CH_DBG1_ADDR(base) ((base) + (0x00F0))
#define AAE_ROT_WDMA_CH_DBG2_ADDR(base) ((base) + (0x00F4))
#define AAE_ROT_WDMA_CH_DBG3_ADDR(base) ((base) + (0x00F8))
#define AAE_ROT_WDMA_CH_DBG4_ADDR(base) ((base) + (0x00FC))
#define AAE_ROT_WDMA_CH_DBG5_ADDR(base) ((base) + (0x00C0))
#define AAE_ROT_WDMA_FRM_END_WCH_DELAY_ADDR(base) ((base) + (0x00C4))
#define AAE_ROT_WDMA_WB_ERR_CTRL_ADDR(base) ((base) + (0x00C8))
#define AAE_ROT_WDMA_CH_DBG6_ADDR(base) ((base) + (0x00CC))
#define AAE_ROT_WDMA_ROT_FIRST_LNS_ADDR(base) ((base) + (0x0580))
#define AAE_ROT_WDMA_ROT_STATE_ADDR(base) ((base) + (0x0584))
#define AAE_ROT_WDMA_ROT_MEM_CTRL_ADDR(base) ((base) + (0x0588))
#define AAE_ROT_WDMA_ROT_SIZE_ADDR(base) ((base) + (0x058C))
#define AAE_ROT_WDMA_ROT_422_MODE_ADDR(base) ((base) + (0x0590))
#define AAE_ROT_WDMA_ROT_BYPASS_ADDR(base) ((base) + (0x0594))
#define AAE_ROT_WDMA_CH_DEBUG_SEL_ADDR(base) ((base) + (0x600))
#define AAE_ROT_WDMA_DMA_ADDR_EXT_ADDR(base) ((base) + (0x604))
#define AAE_ROT_WDMA_REG_CTRL_ADDR(base) ((base) + (0x608))
#define AAE_ROT_WDMA_REG_CTRL_FLUSH_EN_ADDR(base) ((base) + (0x60C))
#define AAE_ROT_WDMA_REG_CTRL_DEBUG_ADDR(base) ((base) + (0x610))
#define AAE_ROT_WDMA_REG_CTRL_STATE_ADDR(base) ((base) + (0x614))
#define AAE_ROT_WDMA_R_LB_DEBUG0_ADDR(base) ((base) + (0x620))
#define AAE_ROT_WDMA_R_LB_DEBUG1_ADDR(base) ((base) + (0x624))
#define AAE_ROT_WDMA_R_LB_DEBUG2_ADDR(base) ((base) + (0x628))
#define AAE_ROT_WDMA_R_LB_DEBUG3_ADDR(base) ((base) + (0x62C))
#define AAE_ROT_WDMA_REG_CTRL_LAYER_ID_ADDR(base) ((base) + (0x630))
#define AAE_ROT_WDMA_RGB2Y_IMG_SIZE_ADDR(base) ((base) + (0x634))
#define AAE_ROT_WDMA_RGB2Y_P00_ADDR(base) ((base) + (0x638))
#define AAE_ROT_WDMA_RGB2Y_P01_ADDR(base) ((base) + (0x63C))
#define AAE_ROT_WDMA_RGB2Y_P02_ADDR(base) ((base) + (0x640))
#define AAE_ROT_WDMA_RGB2Y_CTRL_ADDR(base) ((base) + (0x644))
#define AAE_RCH_OV_RCH_OV0_TOP_CLK_SEL_ADDR(base) ((base) + (0x0000))
#define AAE_RCH_OV_RCH_OV0_TOP_CLK_EN_ADDR(base) ((base) + (0x0004))
#define AAE_RCH_OV_RCH_OV1_TOP_CLK_SEL_ADDR(base) ((base) + (0x0008))
#define AAE_RCH_OV_RCH_OV1_TOP_CLK_EN_ADDR(base) ((base) + (0x000C))
#define AAE_RCH_OV_RCH_OV2_TOP_CLK_SEL_ADDR(base) ((base) + (0x0010))
#define AAE_RCH_OV_RCH_OV2_TOP_CLK_EN_ADDR(base) ((base) + (0x0014))
#define AAE_RCH_OV_RCH_OV3_TOP_CLK_SEL_ADDR(base) ((base) + (0x0018))
#define AAE_RCH_OV_RCH_OV3_TOP_CLK_EN_ADDR(base) ((base) + (0x001C))
#define AAE_RCH_OV_WRAP_CLK_SEL_ADDR(base) ((base) + (0x0020))
#define AAE_RCH_OV_WRAP_CLK_EN_ADDR(base) ((base) + (0x0024))
#define AAE_RCH_OV_RCH_DBG0_ADDR(base) ((base) + (0x0030))
#define AAE_RCH_OV_RCH_DBG1_ADDR(base) ((base) + (0x0034))
#define AAE_RCH_OV_RCH_DBG2_ADDR(base) ((base) + (0x0038))
#define AAE_RCH_OV_RCH_DBG3_ADDR(base) ((base) + (0x003C))
#define AAE_RCH_OV_RCH_DBG4_ADDR(base) ((base) + (0x0040))
#define AAE_RCH_OV_RCH_DBG5_ADDR(base) ((base) + (0x0044))
#define AAE_RCH_OV_RCH_DBG6_ADDR(base) ((base) + (0x0048))
#define AAE_RCH_OV_RCH_DBG7_ADDR(base) ((base) + (0x004C))
#define AAE_RCH_OV_RCH_DBG8_ADDR(base) ((base) + (0x0050))
#define AAE_RCH_OV_RCH_DBG9_ADDR(base) ((base) + (0x0054))
#define AAE_RCH_OV_RCH_DBG10_ADDR(base) ((base) + (0x0058))
#define AAE_RCH_OV_RCH_DBG11_ADDR(base) ((base) + (0x005C))
#define AAE_RCH_OV_OV_MEM_CTRL_0_ADDR(base) ((base) + (0x0060))
#define AAE_RCH_OV_OV_MEM_CTRL_1_ADDR(base) ((base) + (0x0064))
#define AAE_RCH_OV_OV_MEM_CTRL_2_ADDR(base) ((base) + (0x0068))
#define AAE_RCH_OV_OV_MEM_CTRL_3_ADDR(base) ((base) + (0x006C))
#define AAE_RCH_OV_RCH_DBG12_ADDR(base) ((base) + (0x0070))
#define AAE_RCH_OV_RCH_DBG13_ADDR(base) ((base) + (0x0074))
#define AAE_RCH_OV_RCH_DBG14_ADDR(base) ((base) + (0x0078))
#define AAE_RCH_OV_RCH_DBG15_ADDR(base) ((base) + (0x007C))
#define AAE_RCH_OV_RCH_DBG16_ADDR(base) ((base) + (0x0080))
#define AAE_RCH_OV_RCH_DBG17_ADDR(base) ((base) + (0x0084))
#define AAE_RCH_OV_RCH_DBG18_ADDR(base) ((base) + (0x0088))
#define AAE_RCH_OV_RCH_DBG19_ADDR(base) ((base) + (0x008C))
#define AAE_RCH_OV_BITEXT_CTL_ADDR(base,i0) ((base) + (0x0100+0x100*(i0)))
#define AAE_RCH_OV_BITEXT_REG_INI0_0_ADDR(base,i0) ((base) + (0x0104+0x100*(i0)))
#define AAE_RCH_OV_BITEXT_REG_INI0_1_ADDR(base,i0) ((base) + (0x0108+0x100*(i0)))
#define AAE_RCH_OV_BITEXT_REG_INI0_2_ADDR(base,i0) ((base) + (0x010C+0x100*(i0)))
#define AAE_RCH_OV_BITEXT_REG_INI0_3_ADDR(base,i0) ((base) + (0x0110+0x100*(i0)))
#define AAE_RCH_OV_BITEXT_REG_INI1_0_ADDR(base,i0) ((base) + (0x0114+0x100*(i0)))
#define AAE_RCH_OV_BITEXT_REG_INI1_1_ADDR(base,i0) ((base) + (0x0118+0x100*(i0)))
#define AAE_RCH_OV_BITEXT_REG_INI1_2_ADDR(base,i0) ((base) + (0x011C+0x100*(i0)))
#define AAE_RCH_OV_BITEXT_REG_INI1_3_ADDR(base,i0) ((base) + (0x0120+0x100*(i0)))
#define AAE_RCH_OV_BITEXT_REG_INI2_0_ADDR(base,i0) ((base) + (0x0124+0x100*(i0)))
#define AAE_RCH_OV_BITEXT_REG_INI2_1_ADDR(base,i0) ((base) + (0x0128+0x100*(i0)))
#define AAE_RCH_OV_BITEXT_REG_INI2_2_ADDR(base,i0) ((base) + (0x012C+0x100*(i0)))
#define AAE_RCH_OV_BITEXT_REG_INI2_3_ADDR(base,i0) ((base) + (0x0130+0x100*(i0)))
#define AAE_RCH_OV_BITEXT_POWER_CTRL_C_ADDR(base,i0) ((base) + (0x0134+0x100*(i0)))
#define AAE_RCH_OV_BITEXT_POWER_CTRL_SHIFT_ADDR(base,i0) ((base) + (0x0138+0x100*(i0)))
#define AAE_RCH_OV_BITEXT_FILT_00_ADDR(base,i0) ((base) + (0x013C+0x100*(i0)))
#define AAE_RCH_OV_BITEXT_FILT_01_ADDR(base,i0) ((base) + (0x0140+0x100*(i0)))
#define AAE_RCH_OV_BITEXT_FILT_02_ADDR(base,i0) ((base) + (0x0144+0x100*(i0)))
#define AAE_RCH_OV_BITEXT_FILT_10_ADDR(base,i0) ((base) + (0x0148+0x100*(i0)))
#define AAE_RCH_OV_BITEXT_FILT_11_ADDR(base,i0) ((base) + (0x014C+0x100*(i0)))
#define AAE_RCH_OV_BITEXT_FILT_12_ADDR(base,i0) ((base) + (0x0150+0x100*(i0)))
#define AAE_RCH_OV_BITEXT_FILT_20_ADDR(base,i0) ((base) + (0x0154+0x100*(i0)))
#define AAE_RCH_OV_BITEXT_FILT_21_ADDR(base,i0) ((base) + (0x0158+0x100*(i0)))
#define AAE_RCH_OV_BITEXT_FILT_22_ADDR(base,i0) ((base) + (0x015C+0x100*(i0)))
#define AAE_RCH_OV_BITEXT_THD_R0_ADDR(base,i0) ((base) + (0x0160+0x100*(i0)))
#define AAE_RCH_OV_BITEXT_THD_R1_ADDR(base,i0) ((base) + (0x0164+0x100*(i0)))
#define AAE_RCH_OV_BITEXT_THD_G0_ADDR(base,i0) ((base) + (0x0168+0x100*(i0)))
#define AAE_RCH_OV_BITEXT_THD_G1_ADDR(base,i0) ((base) + (0x016C+0x100*(i0)))
#define AAE_RCH_OV_BITEXT_THD_B0_ADDR(base,i0) ((base) + (0x0170+0x100*(i0)))
#define AAE_RCH_OV_BITEXT_THD_B1_ADDR(base,i0) ((base) + (0x0174+0x100*(i0)))
#define AAE_RCH_OV_DFC_GLB_ALPHA23_ADDR(base,i0) ((base) + (0x0178+0x100*(i0)))
#define AAE_RCH_OV_BITEXT0_DBG0_ADDR(base,i0) ((base) + (0x017C+0x100*(i0)))
#define AAE_RCH_OV_CSC_IDC0_ADDR(base,j0) ((base) + (0x0300+0x80*(j0)))
#define AAE_RCH_OV_CSC_IDC2_ADDR(base,j0) ((base) + (0x0304+0x80*(j0)))
#define AAE_RCH_OV_CSC_ODC0_ADDR(base,j0) ((base) + (0x0308+0x80*(j0)))
#define AAE_RCH_OV_CSC_ODC2_ADDR(base,j0) ((base) + (0x030C+0x80*(j0)))
#define AAE_RCH_OV_CSC_P00_ADDR(base,j0) ((base) + (0x0310+0x80*(j0)))
#define AAE_RCH_OV_CSC_P01_ADDR(base,j0) ((base) + (0x0314+0x80*(j0)))
#define AAE_RCH_OV_CSC_P02_ADDR(base,j0) ((base) + (0x0318+0x80*(j0)))
#define AAE_RCH_OV_CSC_P10_ADDR(base,j0) ((base) + (0x031C+0x80*(j0)))
#define AAE_RCH_OV_CSC_P11_ADDR(base,j0) ((base) + (0x0320+0x80*(j0)))
#define AAE_RCH_OV_CSC_P12_ADDR(base,j0) ((base) + (0x0324+0x80*(j0)))
#define AAE_RCH_OV_CSC_P20_ADDR(base,j0) ((base) + (0x0328+0x80*(j0)))
#define AAE_RCH_OV_CSC_P21_ADDR(base,j0) ((base) + (0x032C+0x80*(j0)))
#define AAE_RCH_OV_CSC_P22_ADDR(base,j0) ((base) + (0x0330+0x80*(j0)))
#define AAE_RCH_OV_CSC_MPREC_ADDR(base,j0) ((base) + (0x0338+0x80*(j0)))
#define AAE_RCH_OV_MITM_CTRL_ADDR(base,k0) ((base) + (0x0810+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_DEGAMMA_STEP1_ADDR(base,k0) ((base) + (0x0814+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_DEGAMMA_STEP2_ADDR(base,k0) ((base) + (0x0818+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_DEGAMMA_POS1_ADDR(base,k0) ((base) + (0x081C+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_DEGAMMA_POS2_ADDR(base,k0) ((base) + (0x0820+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_DEGAMMA_POS3_ADDR(base,k0) ((base) + (0x0824+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_DEGAMMA_POS4_ADDR(base,k0) ((base) + (0x0828+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_DEGAMMA_NUM1_ADDR(base,k0) ((base) + (0x082C+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_DEGAMMA_NUM2_ADDR(base,k0) ((base) + (0x0830+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_GAMUT_COEF00_0_ADDR(base,k0) ((base) + (0x0834+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_GAMUT_COEF01_0_ADDR(base,k0) ((base) + (0x0838+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_GAMUT_COEF02_0_ADDR(base,k0) ((base) + (0x083C+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_GAMUT_COEF10_0_ADDR(base,k0) ((base) + (0x0840+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_GAMUT_COEF11_0_ADDR(base,k0) ((base) + (0x0844+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_GAMUT_COEF12_0_ADDR(base,k0) ((base) + (0x0848+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_GAMUT_COEF20_0_ADDR(base,k0) ((base) + (0x084C+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_GAMUT_COEF21_0_ADDR(base,k0) ((base) + (0x0850+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_GAMUT_COEF22_0_ADDR(base,k0) ((base) + (0x0854+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_GAMUT_SCALE_ADDR(base,k0) ((base) + (0x0858+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_GAMUT_CLIP_MAX_ADDR(base,k0) ((base) + (0x085C+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_GAMMA_STEP1_ADDR(base,k0) ((base) + (0x0860+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_GAMMA_STEP2_ADDR(base,k0) ((base) + (0x0864+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_GAMMA_POS1_ADDR(base,k0) ((base) + (0x0868+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_GAMMA_POS2_ADDR(base,k0) ((base) + (0x086C+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_GAMMA_POS3_ADDR(base,k0) ((base) + (0x0870+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_GAMMA_POS4_ADDR(base,k0) ((base) + (0x0874+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_GAMMA_POS5_ADDR(base,k0) ((base) + (0x0878+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_GAMMA_POS6_ADDR(base,k0) ((base) + (0x087C+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_GAMMA_POS7_ADDR(base,k0) ((base) + (0x0880+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_GAMMA_POS8_ADDR(base,k0) ((base) + (0x0884+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_GAMMA_NUM1_ADDR(base,k0) ((base) + (0x0888+0x200*(k0)))
#define AAE_RCH_OV_MITM_SLF_GAMMA_NUM2_ADDR(base,k0) ((base) + (0x088C+0x200*(k0)))
#define AAE_RCH_OV_MITM_ALPHA_ADDR(base,k0) ((base) + (0x0890+0x200*(k0)))
#define AAE_RCH_OV_MITM_DEGAMMA_LUT_ADDR(base,y1,k0) ((base) + (（0x0894+0x200*(k0)）+0x4*(y1)))
#define AAE_RCH_OV_MITM_GAMMA_LUT_ADDR(base,y1,k0) ((base) + (（0x0914+0x200*(k0)）+0x4*(y1)))
#define AAE_RCH_OV_MITM_DBG0_ADDR(base,k0) ((base) + (0x0994+0x200*(k0)))
#define AAE_RCH_OV_MITM_DBG1_ADDR(base,k0) ((base) + (0x0998+0x200*(k0)))
#define AAE_RCH_OV_LAYER_SRCLOKEY_ADDR(base) ((base) + (0x0c00))
#define AAE_RCH_OV_LAYER_SRCHIKEY_ADDR(base) ((base) + (0x0c04))
#define AAE_RCH_OV_LAYER_DSTLOKEY_ADDR(base) ((base) + (0x0c08))
#define AAE_RCH_OV_LAYER_DSTHIKEY_ADDR(base) ((base) + (0x0c0c))
#define AAE_RCH_OV_LAYER_ALPHA_MODE_ADDR(base) ((base) + (0x0c10))
#define AAE_RCH_OV_OV0_DBG0_ADDR(base) ((base) + (0x0c14))
#define AAE_RCH_OV_OV0_DBG1_ADDR(base) ((base) + (0x0c18))
#define AAE_RCH_OV_OV0_DBG2_ADDR(base) ((base) + (0x0c1c))
#define AAE_RCH_OV_OV0_DBG3_ADDR(base) ((base) + (0x0c20))
#define AAE_RCH_OV_OV1_DBG0_ADDR(base) ((base) + (0x0c24))
#define AAE_RCH_OV_OV1_DBG1_ADDR(base) ((base) + (0x0c28))
#define AAE_RCH_OV_OV1_DBG2_ADDR(base) ((base) + (0x0c2c))
#define AAE_RCH_OV_OV1_DBG3_ADDR(base) ((base) + (0x0c30))
#define AAE_RCH_OV_OV2_DBG0_ADDR(base) ((base) + (0x0c34))
#define AAE_RCH_OV_OV2_DBG1_ADDR(base) ((base) + (0x0c38))
#define AAE_RCH_OV_OV2_DBG2_ADDR(base) ((base) + (0x0c3c))
#define AAE_RCH_OV_OV2_DBG3_ADDR(base) ((base) + (0x0c40))
#define AAE_RCH_OV_OV3_DBG0_ADDR(base) ((base) + (0x0c44))
#define AAE_RCH_OV_OV3_DBG1_ADDR(base) ((base) + (0x0c48))
#define AAE_RCH_OV_OV3_DBG2_ADDR(base) ((base) + (0x0c4c))
#define AAE_RCH_OV_OV3_DBG3_ADDR(base) ((base) + (0x0c50))
#define AAE_RCH_OV_SCENE_LCNT_CTRL_ADDR(base) ((base) + (0x0c54))
#define AAE_RCH_OV_SCENE_LCNT_THR01_ADDR(base) ((base) + (0x0c58))
#define AAE_RCH_OV_SCENE_LCNT_THR23_ADDR(base) ((base) + (0x0c5c))
#define AAE_RCH_OV_RXX0_DBG0_ADDR(base) ((base) + (0x0d00))
#define AAE_RCH_OV_RXX0_DBG1_ADDR(base) ((base) + (0x0d04))
#define AAE_RCH_OV_RXX0_DBG2_ADDR(base) ((base) + (0x0d08))
#define AAE_RCH_OV_RXX0_DBG3_ADDR(base) ((base) + (0x0d0c))
#define AAE_RCH_OV_RXX1_DBG0_ADDR(base) ((base) + (0x0d10))
#define AAE_RCH_OV_RXX1_DBG1_ADDR(base) ((base) + (0x0d14))
#define AAE_RCH_OV_RXX1_DBG2_ADDR(base) ((base) + (0x0d18))
#define AAE_RCH_OV_RXX1_DBG3_ADDR(base) ((base) + (0x0d1c))
#define AAE_RCH_OV_RXX2_DBG0_ADDR(base) ((base) + (0x0d20))
#define AAE_RCH_OV_RXX2_DBG1_ADDR(base) ((base) + (0x0d24))
#define AAE_RCH_OV_RXX2_DBG2_ADDR(base) ((base) + (0x0d28))
#define AAE_RCH_OV_RXX2_DBG3_ADDR(base) ((base) + (0x0d2c))
#define AAE_RCH_OV_RXX3_DBG0_ADDR(base) ((base) + (0x0d30))
#define AAE_RCH_OV_RXX3_DBG1_ADDR(base) ((base) + (0x0d34))
#define AAE_RCH_OV_RXX3_DBG2_ADDR(base) ((base) + (0x0d38))
#define AAE_RCH_OV_RXX3_DBG3_ADDR(base) ((base) + (0x0d3c))
#define AAE_RCH_OV_WXX0_DBG0_ADDR(base) ((base) + (0x0d40))
#define AAE_RCH_OV_WXX0_DBG1_ADDR(base) ((base) + (0x0d44))
#define AAE_RCH_OV_WXX0_DBG2_ADDR(base) ((base) + (0x0d48))
#define AAE_RCH_OV_WXX0_DBG3_ADDR(base) ((base) + (0x0d4c))
#define AAE_RCH_OV_WXX1_DBG0_ADDR(base) ((base) + (0x0d50))
#define AAE_RCH_OV_WXX1_DBG1_ADDR(base) ((base) + (0x0d54))
#define AAE_RCH_OV_WXX1_DBG2_ADDR(base) ((base) + (0x0d58))
#define AAE_RCH_OV_WXX1_DBG3_ADDR(base) ((base) + (0x0d5c))
#define AAE_RCH_OV_WXX2_DBG0_ADDR(base) ((base) + (0x0d60))
#define AAE_RCH_OV_WXX2_DBG1_ADDR(base) ((base) + (0x0d64))
#define AAE_RCH_OV_WXX2_DBG2_ADDR(base) ((base) + (0x0d68))
#define AAE_RCH_OV_WXX2_DBG3_ADDR(base) ((base) + (0x0d6c))
#define AAE_RCH_OV_WXX3_DBG0_ADDR(base) ((base) + (0x0d70))
#define AAE_RCH_OV_WXX3_DBG1_ADDR(base) ((base) + (0x0d74))
#define AAE_RCH_OV_WXX3_DBG2_ADDR(base) ((base) + (0x0d78))
#define AAE_RCH_OV_WXX3_DBG3_ADDR(base) ((base) + (0x0d7c))
#define AAE_HDR_RD_SHADOW_ADDR(base) ((base) + (0x0000))
#define AAE_HDR_REG_DEFAULT_ADDR(base) ((base) + (0x0004))
#define AAE_HDR_TOP_CLK_SEL_ADDR(base) ((base) + (0x0008))
#define AAE_HDR_TOP_CLK_EN_ADDR(base) ((base) + (0x000C))
#define AAE_HDR_REG_CTRL_ADDR(base) ((base) + (0x0010))
#define AAE_HDR_REG_CTRL_FLUSH_EN_ADDR(base) ((base) + (0x0014))
#define AAE_HDR_REG_CTRL_DEBUG_ADDR(base) ((base) + (0x0018))
#define AAE_HDR_REG_CTRL_STATE_ADDR(base) ((base) + (0x001C))
#define AAE_HDR_R_LB_DEBUG0_ADDR(base) ((base) + (0x0030))
#define AAE_HDR_R_LB_DEBUG1_ADDR(base) ((base) + (0x0034))
#define AAE_HDR_R_LB_DEBUG2_ADDR(base) ((base) + (0x0038))
#define AAE_HDR_R_LB_DEBUG3_ADDR(base) ((base) + (0x003C))
#define AAE_HDR_W_LB_DEBUG0_ADDR(base) ((base) + (0x0040))
#define AAE_HDR_W_LB_DEBUG1_ADDR(base) ((base) + (0x0044))
#define AAE_HDR_W_LB_DEBUG2_ADDR(base) ((base) + (0x0048))
#define AAE_HDR_W_LB_DEBUG3_ADDR(base) ((base) + (0x004C))
#define AAE_HDR_REG_CTRL_LAYER_ID_ADDR(base) ((base) + (0x0050))
#define AAE_HDR_CSC_CTRL_ADDR(base) ((base) + (0x0200))
#define AAE_HDR_CSC_IDC0_ADDR(base) ((base) + (0x0204))
#define AAE_HDR_CSC_IDC2_ADDR(base) ((base) + (0x0208))
#define AAE_HDR_CSC_ODC0_ADDR(base) ((base) + (0x020C))
#define AAE_HDR_CSC_ODC2_ADDR(base) ((base) + (0x0210))
#define AAE_HDR_CSC_P00_ADDR(base) ((base) + (0x0214))
#define AAE_HDR_CSC_P01_ADDR(base) ((base) + (0x0218))
#define AAE_HDR_CSC_P02_ADDR(base) ((base) + (0x021C))
#define AAE_HDR_CSC_P10_ADDR(base) ((base) + (0x0220))
#define AAE_HDR_CSC_P11_ADDR(base) ((base) + (0x0224))
#define AAE_HDR_CSC_P12_ADDR(base) ((base) + (0x0228))
#define AAE_HDR_CSC_P20_ADDR(base) ((base) + (0x022C))
#define AAE_HDR_CSC_P21_ADDR(base) ((base) + (0x0230))
#define AAE_HDR_CSC_P22_ADDR(base) ((base) + (0x0234))
#define AAE_HDR_MEM_CTRL_ADDR(base) ((base) + (0x0238))
#define AAE_HDR_CTRL_ADDR(base) ((base) + (0x023C))
#define AAE_HDR_SIZE_ADDR(base) ((base) + (0x0240))
#define AAE_HDR_INV_SIZE_ADDR(base) ((base) + (0x0244))
#define AAE_HDR_MEAN_STT_ADDR(base) ((base) + (0x0248))
#define AAE_HDR_STAT_X_ADDR(base) ((base) + (0x24C))
#define AAE_HDR_RGB2Y_CTRL1_ADDR(base) ((base) + (0x250))
#define AAE_HDR_RGB2Y_CTRL2_ADDR(base) ((base) + (0x0254))
#define AAE_HDR_EOTF_STEP1_ADDR(base) ((base) + (0x0258))
#define AAE_HDR_EOTF_STEP2_ADDR(base) ((base) + (0x025C))
#define AAE_HDR_EOTF_POS1_ADDR(base) ((base) + (0x0260))
#define AAE_HDR_EOTF_POS2_ADDR(base) ((base) + (0x0264))
#define AAE_HDR_EOTF_POS3_ADDR(base) ((base) + (0x0268))
#define AAE_HDR_EOTF_POS4_ADDR(base) ((base) + (0x026C))
#define AAE_HDR_EOTF_NUM1_ADDR(base) ((base) + (0x0270))
#define AAE_HDR_EOTF_NUM2_ADDR(base) ((base) + (0x0274))
#define AAE_HDR_EOTF_NUM3_ADDR(base) ((base) + (0x0278))
#define AAE_HDR_EOTF_NUM4_ADDR(base) ((base) + (0x027C))
#define AAE_HDR_GTM_MIN_E_ADDR(base) ((base) + (0x0280))
#define AAE_HDR_GTM_MIN_O_ADDR(base) ((base) + (0x0284))
#define AAE_HDR_GTM_RGB2Y_CTRL1_ADDR(base) ((base) + (0x0288))
#define AAE_HDR_GTM_RGB2Y_CTRL2_ADDR(base) ((base) + (0x028C))
#define AAE_HDR_GTM_LUMA_CLIP1_ADDR(base) ((base) + (0x0290))
#define AAE_HDR_GTM_LUMA_RATIO_LUT_STEP_ADDR(base) ((base) + (0x0294))
#define AAE_HDR_GTM_LUMA_OUT_BIT_ADDR(base) ((base) + (0x0298))
#define AAE_HDR_GTM_LUMA_LUT_THRES_ADDR(base) ((base) + (0x029C))
#define AAE_HDR_LTM_HALF_BLOCK_ADDR(base) ((base) + (0x310))
#define AAE_HDR_LTM_INTP_XY_ADDR(base) ((base) + (0x314))
#define AAE_HDR_LTM_CELL_SIZE_ADDR(base) ((base) + (0x324))
#define AAE_HDR_LTM_CELL_INVW_ADDR(base) ((base) + (0x328))
#define AAE_HDR_LTM_CELL_INVH_ADDR(base) ((base) + (0x32C))
#define AAE_HDR_LTM_PQ2GAMMA_END_PT_ADDR(base) ((base) + (0x330))
#define AAE_HDR_LTM_CTRL_ADDR(base) ((base) + (0x334))
#define AAE_HDR_LTM_CSP1_ADDR(base) ((base) + (0x338))
#define AAE_HDR_LTM_CSP2_ADDR(base) ((base) + (0x33C))
#define AAE_HDR_LTM_CSP3_ADDR(base) ((base) + (0x340))
#define AAE_HDR_LTM_CSP4_ADDR(base) ((base) + (0x344))
#define AAE_HDR_LTM_CSP5_ADDR(base) ((base) + (0x348))
#define AAE_HDR_LTM_CSP6_ADDR(base) ((base) + (0x34C))
#define AAE_HDR_LTM_CSP7_ADDR(base) ((base) + (0x350))
#define AAE_HDR_LTM_CSP8_ADDR(base) ((base) + (0x354))
#define AAE_HDR_LTM_CSP9_ADDR(base) ((base) + (0x358))
#define AAE_HDR_LTM_CSN1_ADDR(base) ((base) + (0x35C))
#define AAE_HDR_LTM_CSN2_ADDR(base) ((base) + (0x360))
#define AAE_HDR_LTM_CSN3_ADDR(base) ((base) + (0x364))
#define AAE_HDR_LTM_CSN4_ADDR(base) ((base) + (0x368))
#define AAE_HDR_LTM_CSN5_ADDR(base) ((base) + (0x36C))
#define AAE_HDR_LTM_CSN6_ADDR(base) ((base) + (0x370))
#define AAE_HDR_LTM_CSN7_ADDR(base) ((base) + (0x374))
#define AAE_HDR_LTM_CSN8_ADDR(base) ((base) + (0x378))
#define AAE_HDR_LTM_CSN9_ADDR(base) ((base) + (0x37C))
#define AAE_HDR_LTM_WTZ1_ADDR(base) ((base) + (0x380))
#define AAE_HDR_LTM_WTZ2_ADDR(base) ((base) + (0x384))
#define AAE_HDR_OETF_STEP1_ADDR(base) ((base) + (0x3A0))
#define AAE_HDR_OETF_STEP2_ADDR(base) ((base) + (0x3A4))
#define AAE_HDR_OETF_POS1_ADDR(base) ((base) + (0x3A8))
#define AAE_HDR_OETF_POS2_ADDR(base) ((base) + (0x3AC))
#define AAE_HDR_OETF_POS3_ADDR(base) ((base) + (0x3B0))
#define AAE_HDR_OETF_POS4_ADDR(base) ((base) + (0x3B4))
#define AAE_HDR_OETF_NUM1_ADDR(base) ((base) + (0x3B8))
#define AAE_HDR_OETF_NUM2_ADDR(base) ((base) + (0x3BC))
#define AAE_HDR_OETF_NUM3_ADDR(base) ((base) + (0x3C0))
#define AAE_HDR_OETF_NUM4_ADDR(base) ((base) + (0x3C4))
#define AAE_HDR_CHROMA_RGB2Y_CTRL1_ADDR(base) ((base) + (0x3C8))
#define AAE_HDR_CHROMA_RGB2Y_CTRL2_ADDR(base) ((base) + (0x3CC))
#define AAE_HDR_CHROMA_RATIO_LUT00_ADDR(base) ((base) + (0x3D0))
#define AAE_HDR_CHROMA_RATIO_LUT01_ADDR(base) ((base) + (0x3D4))
#define AAE_HDR_CHROMA_RATIO_LUT02_ADDR(base) ((base) + (0x3D8))
#define AAE_HDR_CHROMA_RATIO_LUT03_ADDR(base) ((base) + (0x3DC))
#define AAE_HDR_CHROMA_RATIO_LUT04_ADDR(base) ((base) + (0x3E0))
#define AAE_HDR_CHROMA_RATIO_LUT05_ADDR(base) ((base) + (0x3E4))
#define AAE_HDR_CHROMA_RATIO_LUT06_ADDR(base) ((base) + (0x3E8))
#define AAE_HDR_CHROMA_RATIO_LUT07_ADDR(base) ((base) + (0x3EC))
#define AAE_HDR_CHROMA_RATIO_LUT_CLIP_ADDR(base) ((base) + (0x3F0))
#define AAE_HDR_CHROMA_RATIO_LUT_STEP_ADDR(base) ((base) + (0x3F4))
#define AAE_HDR_CHROMA_OUT_BIT_ADDR(base) ((base) + (0x400))
#define AAE_HDR_CHROMA_RATIO_CLIP_ADDR(base) ((base) + (0x404))
#define AAE_HDR_CHROMA_CTRL_ADDR(base) ((base) + (0x408))
#define AAE_HDR_CSC1_IDC0_ADDR(base) ((base) + (0x40C))
#define AAE_HDR_CSC1_IDC2_ADDR(base) ((base) + (0x410))
#define AAE_HDR_CSC1_ODC0_ADDR(base) ((base) + (0x414))
#define AAE_HDR_CSC1_ODC2_ADDR(base) ((base) + (0x418))
#define AAE_HDR_CSC1_P00_ADDR(base) ((base) + (0x41C))
#define AAE_HDR_CSC1_P01_ADDR(base) ((base) + (0x420))
#define AAE_HDR_CSC1_P02_ADDR(base) ((base) + (0x424))
#define AAE_HDR_CSC1_P10_ADDR(base) ((base) + (0x428))
#define AAE_HDR_CSC1_P11_ADDR(base) ((base) + (0x42C))
#define AAE_HDR_CSC1_P12_ADDR(base) ((base) + (0x430))
#define AAE_HDR_CSC1_P20_ADDR(base) ((base) + (0x434))
#define AAE_HDR_CSC1_P21_ADDR(base) ((base) + (0x438))
#define AAE_HDR_CSC1_P22_ADDR(base) ((base) + (0x43C))
#define AAE_HDR_CSC2_IDC0_ADDR(base) ((base) + (0x440))
#define AAE_HDR_CSC2_IDC2_ADDR(base) ((base) + (0x444))
#define AAE_HDR_CSC2_ODC0_ADDR(base) ((base) + (0x448))
#define AAE_HDR_CSC2_ODC2_ADDR(base) ((base) + (0x44C))
#define AAE_HDR_CSC2_P00_ADDR(base) ((base) + (0x450))
#define AAE_HDR_CSC2_P01_ADDR(base) ((base) + (0x454))
#define AAE_HDR_CSC2_P02_ADDR(base) ((base) + (0x458))
#define AAE_HDR_CSC2_P10_ADDR(base) ((base) + (0x45C))
#define AAE_HDR_CSC2_P11_ADDR(base) ((base) + (0x460))
#define AAE_HDR_CSC2_P12_ADDR(base) ((base) + (0x464))
#define AAE_HDR_CSC2_P20_ADDR(base) ((base) + (0x468))
#define AAE_HDR_CSC2_P21_ADDR(base) ((base) + (0x46C))
#define AAE_HDR_CSC2_P22_ADDR(base) ((base) + (0x470))
#define AAE_HDR_LTM_MSK_ADDR(base) ((base) + (0x474))
#define AAE_HDR_DBG_ADDR(base) ((base) + (0x478))
#define AAE_HDR_RX_P0_CNT_ADDR(base) ((base) + (0x47C))
#define AAE_HDR_RX_P1_CNT_ADDR(base) ((base) + (0x480))
#define AAE_HDR_FRAME_START_CNT_ADDR(base) ((base) + (0x484))
#define AAE_HDR_TX_P0_CNT_ADDR(base) ((base) + (0x488))
#define AAE_HDR_TX_P1_CNT_ADDR(base) ((base) + (0x48C))
#define AAE_HDR_FRAME_END_CNT_ADDR(base) ((base) + (0x490))
#define AAE_HDR_GTM_TX_CNT0_ADDR(base) ((base) + (0x494))
#define AAE_HDR_GTM_TX_CNT1_ADDR(base) ((base) + (0x498))
#define AAE_HDR_OETF_RX_CNT0_ADDR(base) ((base) + (0x49C))
#define AAE_HDR_OETF_RX_CNT1_ADDR(base) ((base) + (0x4A0))
#define AAE_HDR_STAT_P0_CNT_ADDR(base) ((base) + (0x4A4))
#define AAE_HDR_STAT_P1_CNT_ADDR(base) ((base) + (0x4A8))
#define AAE_HDR_DEGAMMA_EN_ADDR(base) ((base) + (0x0A00))
#define AAE_HDR_DEGAMMA_MEM_CTRL_ADDR(base) ((base) + (0x0A04))
#define AAE_HDR_DEGAMMA_LUT_SEL_ADDR(base) ((base) + (0x0A08))
#define AAE_HDR_DEGAMMA_DBG0_ADDR(base) ((base) + (0x0A0C))
#define AAE_HDR_DEGAMMA_DBG1_ADDR(base) ((base) + (0x0A10))
#define AAE_HDR_GMP_EN_ADDR(base) ((base) + (0x0A14))
#define AAE_HDR_GMP_MEM_CTRL_ADDR(base) ((base) + (0x0A18))
#define AAE_HDR_GMP_LUT_SEL_ADDR(base) ((base) + (0x0A1C))
#define AAE_HDR_GMP_DBG_W0_ADDR(base) ((base) + (0x0A20))
#define AAE_HDR_GMP_DBG_R0_ADDR(base) ((base) + (0x0A24))
#define AAE_HDR_GMP_DBG_R1_ADDR(base) ((base) + (0x0A28))
#define AAE_HDR_GMP_DBG_R2_ADDR(base) ((base) + (0x0A2C))
#define AAE_HDR_GAMMA_EN_ADDR(base) ((base) + (0x0A30))
#define AAE_HDR_GAMMA_MEM_CTRL_ADDR(base) ((base) + (0x0A34))
#define AAE_HDR_GAMMA_LUT_SEL_ADDR(base) ((base) + (0x0A38))
#define AAE_HDR_GAMMA_DBG0_ADDR(base) ((base) + (0x0A3C))
#define AAE_HDR_GAMMA_DBG1_ADDR(base) ((base) + (0x0A40))
#define AAE_HDR_EOTF_LUT_COEF_ADDR(base,q) ((base) + (0x1000+0x4*(q)))
#define AAE_HDR_OETF_LUT_COEF_ADDR(base,q) ((base) + (0x1204+0x4*(q)))
#define AAE_HDR_GTM_LUMA_LUT0_ADDR(base,y1) ((base) + (0x1408+0x4*(y1)))
#define AAE_HDR_LTM_TMS_ADDR(base,y2) ((base) + (0x1488+0x4*(y2)))
#define AAE_HDR_GTM_LUMA_LUT_ADDR(base,y3) ((base) + (0x150C+0x4*(y3)))
#define AAE_HDR_GTM_CHROMA_LUT_ADDR(base,y3) ((base) + (0x170C+0x4*(y3)))
#define AAE_HDR_GTM_CHROMA0_LUT_ADDR(base,y5) ((base) + (0x190C+0x4*(y5)))
#define AAE_HDR_GTM_CHROMA1_LUT_ADDR(base,y5) ((base) + (0x1A0C+0x4*(y5)))
#define AAE_HDR_GTM_CHROMA2_LUT_ADDR(base,y5) ((base) + (0x1B0C+0x4*(y5)))
#define AAE_HDR_LTM_PQ2GAMMA_LUT_ADDR(base,y3) ((base) + (0x1C0C+0x4*(y3)))
#define AAE_HDR_GLOBAL_HIST_BUFF_ADDR(base,y4) ((base) + (0x1E0C+0x4*(y4)))
#define AAE_HDR_LTM_HIST_ADDR(base,y5) ((base) + (0x220C+0x4*(y5)))
#define AAE_HDR_LTM_LOCALGAMMA_LUT_ADDR(base,y6) ((base) + (0x230C+0x4*(y6)))
#define AAE_HDR_LTM_VGRID_ADDR(base,y7) ((base) + (0x2C0C+0x4*(y7)))
#define AAE_HDR_LTM_VSUM_ADDR(base,y8) ((base) + (0x3530+0x4*(y8)))
#define AAE_HDR_LTM_PCNT_ADDR(base,y8) ((base) + (0x45A4+0x4*(y8)))
#define AAE_HDR_DEGAMMA_R_COEF_ADDR(base,q) ((base) + (0x7300+0x4*(q)))
#define AAE_HDR_DEGAMMA_G_COEF_ADDR(base,q) ((base) + (0x7700+0x4*(q)))
#define AAE_HDR_DEGAMMA_B_COEF_ADDR(base,q) ((base) + (0x7B00+0x4*(q)))
#define AAE_HDR_GAMMA_R_COEF_ADDR(base,q) ((base) + (0x8000+0x4*(q)))
#define AAE_HDR_GAMMA_G_COEF_ADDR(base,q) ((base) + (0x8400+0x4*(q)))
#define AAE_HDR_GAMMA_B_COEF_ADDR(base,q) ((base) + (0x8800+0x4*(q)))
#define AAE_HDR_GMP_COEF_ADDR(base,u1) ((base) + (0x9000+0x4*(u1)))
#define AAE_ARSR_RD_SHADOW_ADDR(base) ((base) + (0x0000))
#define AAE_ARSR_REG_DEFAULT_ADDR(base) ((base) + (0x0004))
#define AAE_ARSR_TOP_CLK_SEL_ADDR(base) ((base) + (0x0008))
#define AAE_ARSR_TOP_CLK_EN_ADDR(base) ((base) + (0x000C))
#define AAE_ARSR_REG_CTRL_ADDR(base) ((base) + (0x0010))
#define AAE_ARSR_REG_CTRL_FLUSH_EN_ADDR(base) ((base) + (0x0014))
#define AAE_ARSR_REG_CTRL_DEBUG_ADDR(base) ((base) + (0x0018))
#define AAE_ARSR_REG_CTRL_STATE_ADDR(base) ((base) + (0x001C))
#define AAE_ARSR_R_LB_DEBUG0_ADDR(base) ((base) + (0x0030))
#define AAE_ARSR_R_LB_DEBUG1_ADDR(base) ((base) + (0x0034))
#define AAE_ARSR_R_LB_DEBUG2_ADDR(base) ((base) + (0x0038))
#define AAE_ARSR_R_LB_DEBUG3_ADDR(base) ((base) + (0x003C))
#define AAE_ARSR_W_LB_DEBUG0_ADDR(base) ((base) + (0x0040))
#define AAE_ARSR_W_LB_DEBUG1_ADDR(base) ((base) + (0x0044))
#define AAE_ARSR_W_LB_DEBUG2_ADDR(base) ((base) + (0x0048))
#define AAE_ARSR_W_LB_DEBUG3_ADDR(base) ((base) + (0x004C))
#define AAE_ARSR_REG_CTRL_LAYER_ID_ADDR(base) ((base) + (0x0050))
#define AAE_ARSR_DFC_DISP_SIZE_ADDR(base) ((base) + (0x0100))
#define AAE_ARSR_DFC_PIX_IN_NUM_ADDR(base) ((base) + (0x0104))
#define AAE_ARSR_DFC_GLB_ALPHA01_ADDR(base) ((base) + (0x0108))
#define AAE_ARSR_DFC_DISP_FMT_ADDR(base) ((base) + (0x010C))
#define AAE_ARSR_DFC_CLIP_CTL_HRZ_ADDR(base) ((base) + (0x0110))
#define AAE_ARSR_DFC_CLIP_CTL_VRZ_ADDR(base) ((base) + (0x0114))
#define AAE_ARSR_DFC_CTL_CLIP_EN_ADDR(base) ((base) + (0x0118))
#define AAE_ARSR_DFC_ICG_MODULE_ADDR(base) ((base) + (0x011C))
#define AAE_ARSR_DFC_DITHER_ENABLE_ADDR(base) ((base) + (0x0120))
#define AAE_ARSR_DFC_PADDING_CTL_ADDR(base) ((base) + (0x0124))
#define AAE_ARSR_DFC_GLB_ALPHA23_ADDR(base) ((base) + (0x0128))
#define AAE_ARSR_BITEXT_CTL_ADDR(base) ((base) + (0x0140))
#define AAE_ARSR_BITEXT_REG_INI0_0_ADDR(base) ((base) + (0x0144))
#define AAE_ARSR_BITEXT_REG_INI0_1_ADDR(base) ((base) + (0x0148))
#define AAE_ARSR_BITEXT_REG_INI0_2_ADDR(base) ((base) + (0x014C))
#define AAE_ARSR_BITEXT_REG_INI0_3_ADDR(base) ((base) + (0x0150))
#define AAE_ARSR_BITEXT_REG_INI1_0_ADDR(base) ((base) + (0x0154))
#define AAE_ARSR_BITEXT_REG_INI1_1_ADDR(base) ((base) + (0x0158))
#define AAE_ARSR_BITEXT_REG_INI1_2_ADDR(base) ((base) + (0x015C))
#define AAE_ARSR_BITEXT_REG_INI1_3_ADDR(base) ((base) + (0x0160))
#define AAE_ARSR_BITEXT_REG_INI2_0_ADDR(base) ((base) + (0x0164))
#define AAE_ARSR_BITEXT_REG_INI2_1_ADDR(base) ((base) + (0x0168))
#define AAE_ARSR_BITEXT_REG_INI2_2_ADDR(base) ((base) + (0x016C))
#define AAE_ARSR_BITEXT_REG_INI2_3_ADDR(base) ((base) + (0x0170))
#define AAE_ARSR_BITEXT_POWER_CTRL_C_ADDR(base) ((base) + (0x0174))
#define AAE_ARSR_BITEXT_POWER_CTRL_SHIFT_ADDR(base) ((base) + (0x0178))
#define AAE_ARSR_BITEXT_FILT_00_ADDR(base) ((base) + (0x017C))
#define AAE_ARSR_BITEXT_FILT_01_ADDR(base) ((base) + (0x0180))
#define AAE_ARSR_BITEXT_FILT_02_ADDR(base) ((base) + (0x0184))
#define AAE_ARSR_BITEXT_FILT_10_ADDR(base) ((base) + (0x0188))
#define AAE_ARSR_BITEXT_FILT_11_ADDR(base) ((base) + (0x018C))
#define AAE_ARSR_BITEXT_FILT_12_ADDR(base) ((base) + (0x0190))
#define AAE_ARSR_BITEXT_FILT_20_ADDR(base) ((base) + (0x0194))
#define AAE_ARSR_BITEXT_FILT_21_ADDR(base) ((base) + (0x01A0))
#define AAE_ARSR_BITEXT_FILT_22_ADDR(base) ((base) + (0x01A4))
#define AAE_ARSR_BITEXT_THD_R0_ADDR(base) ((base) + (0x01A8))
#define AAE_ARSR_BITEXT_THD_R1_ADDR(base) ((base) + (0x01AC))
#define AAE_ARSR_BITEXT_THD_G0_ADDR(base) ((base) + (0x01B0))
#define AAE_ARSR_BITEXT_THD_G1_ADDR(base) ((base) + (0x01B4))
#define AAE_ARSR_BITEXT_THD_B0_ADDR(base) ((base) + (0x01B8))
#define AAE_ARSR_BITEXT_THD_B1_ADDR(base) ((base) + (0x01BC))
#define AAE_ARSR_BITEXT0_DBG0_ADDR(base) ((base) + (0x01C0))
#define AAE_ARSR_CSC_IDC0_ADDR(base) ((base) + (0x01C4))
#define AAE_ARSR_CSC_IDC2_ADDR(base) ((base) + (0x01C8))
#define AAE_ARSR_CSC_ODC0_ADDR(base) ((base) + (0x01CC))
#define AAE_ARSR_CSC_ODC2_ADDR(base) ((base) + (0x01D0))
#define AAE_ARSR_CSC_P00_ADDR(base) ((base) + (0x01D4))
#define AAE_ARSR_CSC_P01_ADDR(base) ((base) + (0x01D8))
#define AAE_ARSR_CSC_P02_ADDR(base) ((base) + (0x01DC))
#define AAE_ARSR_CSC_P10_ADDR(base) ((base) + (0x01E0))
#define AAE_ARSR_CSC_P11_ADDR(base) ((base) + (0x01E4))
#define AAE_ARSR_CSC_P12_ADDR(base) ((base) + (0x01E8))
#define AAE_ARSR_CSC_P20_ADDR(base) ((base) + (0x01EC))
#define AAE_ARSR_CSC_P21_ADDR(base) ((base) + (0x01F0))
#define AAE_ARSR_CSC_P22_ADDR(base) ((base) + (0x01F4))
#define AAE_ARSR_CSC_ICG_MODULE_ADDR(base) ((base) + (0x01F8))
#define AAE_ARSR_CSC_MPREC_ADDR(base) ((base) + (0x01FC))
#define AAE_ARSR_SCF_EN_HSCL_STR_ADDR(base) ((base) + (0x0200))
#define AAE_ARSR_SCF_EN_VSCL_STR_ADDR(base) ((base) + (0x0204))
#define AAE_ARSR_SCF_H_V_ORDER_ADDR(base) ((base) + (0x0208))
#define AAE_ARSR_SCF_CH_CORE_GT_ADDR(base) ((base) + (0x020C))
#define AAE_ARSR_SCF_INPUT_WIDTH_HEIGHT_ADDR(base) ((base) + (0x0210))
#define AAE_ARSR_SCF_OUTPUT_WIDTH_HEIGHT_ADDR(base) ((base) + (0x0214))
#define AAE_ARSR_SCF_COEF_MEM_CTRL_ADDR(base) ((base) + (0x0218))
#define AAE_ARSR_SCF_EN_HSCL_ADDR(base) ((base) + (0x021C))
#define AAE_ARSR_SCF_EN_VSCL_ADDR(base) ((base) + (0x0220))
#define AAE_ARSR_SCF_ACC_HSCL_ADDR(base) ((base) + (0x0224))
#define AAE_ARSR_SCF_ACC_HSCL1_ADDR(base) ((base) + (0x0228))
#define AAE_ARSR_SCF_INC_HSCL_ADDR(base) ((base) + (0x0234))
#define AAE_ARSR_SCF_ACC_VSCL_ADDR(base) ((base) + (0x0238))
#define AAE_ARSR_SCF_ACC_VSCL1_ADDR(base) ((base) + (0x023C))
#define AAE_ARSR_SCF_INC_VSCL_ADDR(base) ((base) + (0x0248))
#define AAE_ARSR_SCF_EN_NONLINEAR_ADDR(base) ((base) + (0x024C))
#define AAE_ARSR_SCF_EN_MMP_ADDR(base) ((base) + (0x027C))
#define AAE_ARSR_SCF_DB_H0_ADDR(base) ((base) + (0x0280))
#define AAE_ARSR_SCF_DB_H1_ADDR(base) ((base) + (0x0284))
#define AAE_ARSR_SCF_DB_V0_ADDR(base) ((base) + (0x0288))
#define AAE_ARSR_SCF_DB_V1_ADDR(base) ((base) + (0x028C))
#define AAE_ARSR_SCF_LB_MEM_CTRL_ADDR(base) ((base) + (0x0290))
#define AAE_ARSR_INPUT_WIDTH_HEIGHT_ADDR(base) ((base) + (0x0300))
#define AAE_ARSR_OUTPUT_WIDTH_HEIGHT_ADDR(base) ((base) + (0x0304))
#define AAE_ARSR_IHLEFT_ADDR(base) ((base) + (0x0308))
#define AAE_ARSR_IHLEFT1_ADDR(base) ((base) + (0x030C))
#define AAE_ARSR_IHRIGHT_ADDR(base) ((base) + (0x0310))
#define AAE_ARSR_IHRIGHT1_ADDR(base) ((base) + (0x0314))
#define AAE_ARSR_IVTOP_ADDR(base) ((base) + (0x0318))
#define AAE_ARSR_IVBOTTOM_ADDR(base) ((base) + (0x031C))
#define AAE_ARSR_IVBOTTOM1_ADDR(base) ((base) + (0x0320))
#define AAE_ARSR_IHINC_ADDR(base) ((base) + (0x0324))
#define AAE_ARSR_IVINC_ADDR(base) ((base) + (0x0328))
#define AAE_ARSR_OFFSET_ADDR(base) ((base) + (0x032C))
#define AAE_ARSR_MODE_ADDR(base) ((base) + (0x0330))
#define AAE_ARSR_SKIN_THRES_Y_ADDR(base) ((base) + (0x0334))
#define AAE_ARSR_SKIN_THRES_U_ADDR(base) ((base) + (0x0338))
#define AAE_ARSR_SKIN_THRES_V_ADDR(base) ((base) + (0x033C))
#define AAE_ARSR_SKIN_CFG0_ADDR(base) ((base) + (0x0340))
#define AAE_ARSR_SKIN_CFG1_ADDR(base) ((base) + (0x0344))
#define AAE_ARSR_SKIN_CFG2_ADDR(base) ((base) + (0x0348))
#define AAE_ARSR_SHOOT_CFG1_ADDR(base) ((base) + (0x034C))
#define AAE_ARSR_SHOOT_CFG2_ADDR(base) ((base) + (0x0350))
#define AAE_ARSR_SHOOT_CFG3_ADDR(base) ((base) + (0x0354))
#define AAE_ARSR_SHARP_CFG3_ADDR(base) ((base) + (0x0358))
#define AAE_ARSR_SHARP_CFG4_ADDR(base) ((base) + (0x035C))
#define AAE_ARSR_SHARP_CFG5_ADDR(base) ((base) + (0x0360))
#define AAE_ARSR_SHARP_CFG6_ADDR(base) ((base) + (0x0364))
#define AAE_ARSR_SHARP_CFG7_ADDR(base) ((base) + (0x0368))
#define AAE_ARSR_SHARP_CFG8_ADDR(base) ((base) + (0x036C))
#define AAE_ARSR_SHARPLEVEL_ADDR(base) ((base) + (0x0370))
#define AAE_ARSR_SHPGAIN_LOW_ADDR(base) ((base) + (0x0374))
#define AAE_ARSR_SHPGAIN_MID_ADDR(base) ((base) + (0x0378))
#define AAE_ARSR_SHPGAIN_HIGH_ADDR(base) ((base) + (0x037C))
#define AAE_ARSR_GAINCTRLSLOPH_MF_ADDR(base) ((base) + (0x0380))
#define AAE_ARSR_GAINCTRLSLOPL_MF_ADDR(base) ((base) + (0x0384))
#define AAE_ARSR_GAINCTRLSLOPH_HF_ADDR(base) ((base) + (0x0388))
#define AAE_ARSR_GAINCTRLSLOPL_HF_ADDR(base) ((base) + (0x038C))
#define AAE_ARSR_MF_LMT_ADDR(base) ((base) + (0x0390))
#define AAE_ARSR_GAIN_MF_ADDR(base) ((base) + (0x0394))
#define AAE_ARSR_MF_B_ADDR(base) ((base) + (0x0398))
#define AAE_ARSR_HF_LMT_ADDR(base) ((base) + (0x039C))
#define AAE_ARSR_GAIN_HF_ADDR(base) ((base) + (0x03A0))
#define AAE_ARSR_HF_B_ADDR(base) ((base) + (0x03A4))
#define AAE_ARSR_LF_CTRL_ADDR(base) ((base) + (0x03A8))
#define AAE_ARSR_LF_VAR_ADDR(base) ((base) + (0x03AC))
#define AAE_ARSR_LF_CTRL_SLOP_ADDR(base) ((base) + (0x03B0))
#define AAE_ARSR_HF_SELECT_ADDR(base) ((base) + (0x03B4))
#define AAE_ARSR_SHARP_CFG2_H_ADDR(base) ((base) + (0x03B8))
#define AAE_ARSR_SHARP_CFG2_L_ADDR(base) ((base) + (0x03BC))
#define AAE_ARSR_TEXTURW_ANALYSTS_ADDR(base) ((base) + (0x03D0))
#define AAE_ARSR_INTPLSHOOTCTRL_ADDR(base) ((base) + (0x03D4))
#define AAE_ARSR_ARSR2P_DEBUG0_ADDR(base) ((base) + (0x03D8))
#define AAE_ARSR_ARSR2P_DEBUG1_ADDR(base) ((base) + (0x03DC))
#define AAE_ARSR_ARSR2P_DEBUG2_ADDR(base) ((base) + (0x03E0))
#define AAE_ARSR_ARSR2P_DEBUG3_ADDR(base) ((base) + (0x03E4))
#define AAE_ARSR_ARSR2P_LB_MEM_CTRL_ADDR(base) ((base) + (0x03E8))
#define AAE_ARSR_COEF_MEM_CTRL_ADDR(base) ((base) + (0x03EC))
#define AAE_ARSR_POST_CSC_IDC0_ADDR(base) ((base) + (0x0400))
#define AAE_ARSR_POST_CSC_IDC2_ADDR(base) ((base) + (0x0404))
#define AAE_ARSR_POST_CSC_ODC0_ADDR(base) ((base) + (0x0408))
#define AAE_ARSR_POST_CSC_ODC2_ADDR(base) ((base) + (0x040C))
#define AAE_ARSR_POST_CSC_P00_ADDR(base) ((base) + (0x0410))
#define AAE_ARSR_POST_CSC_P01_ADDR(base) ((base) + (0x0414))
#define AAE_ARSR_POST_CSC_P02_ADDR(base) ((base) + (0x0418))
#define AAE_ARSR_POST_CSC_P10_ADDR(base) ((base) + (0x041C))
#define AAE_ARSR_POST_CSC_P11_ADDR(base) ((base) + (0x0420))
#define AAE_ARSR_POST_CSC_P12_ADDR(base) ((base) + (0x0424))
#define AAE_ARSR_POST_CSC_P20_ADDR(base) ((base) + (0x0428))
#define AAE_ARSR_POST_CSC_P21_ADDR(base) ((base) + (0x042C))
#define AAE_ARSR_POST_CSC_P22_ADDR(base) ((base) + (0x0430))
#define AAE_ARSR_POST_CSC_MODULE_EN_ADDR(base) ((base) + (0x0434))
#define AAE_ARSR_POST_CSC_MPREC_ADDR(base) ((base) + (0x0438))
#define AAE_ARSR_POST_CLIP_DISP_SIZE_ADDR(base) ((base) + (0x0480))
#define AAE_ARSR_POST_CLIP_CTL_HRZ_ADDR(base) ((base) + (0x0484))
#define AAE_ARSR_POST_CLIP_CTL_VRZ_ADDR(base) ((base) + (0x0488))
#define AAE_ARSR_POST_CLIP_EN_ADDR(base) ((base) + (0x048C))
#define AAE_ARSR_1VINC_ADDR(base) ((base) + (0x04A0))
#define AAE_ARSR_V0_SCF_VIDEO_6TAP_COEF_ADDR(base,l) ((base) + (0x1000+0x4*(l)))
#define AAE_ARSR_V0_SCF_VIDEO_5TAP_COEF_ADDR(base,m) ((base) + (0x3000+0x4*(m)))
#define AAE_ARSR_V0_SCF_VIDEO_4TAP_COEF_ADDR(base,n) ((base) + (0x3800+0x4*(n)))
#define AAE_ARSR_COEFY_V_ADDR(base,o) ((base) + (0x5000+0x4*(o)))
#define AAE_ARSR_COEFY_H_ADDR(base,p) ((base) + (0x5100+0x4*(p)))
#define AAE_ARSR_COEFA_V_ADDR(base,o) ((base) + (0x5300+0x4*(o)))
#define AAE_ARSR_COEFA_H_ADDR(base,p) ((base) + (0x5400+0x4*(p)))
#define AAE_ARSR_COEFUV_V_ADDR(base,o) ((base) + (0x5600+0x4*(o)))
#define AAE_ARSR_COEFUV_H_ADDR(base,p) ((base) + (0x5700+0x4*(p)))
#define AAE_VSCF_RD_SHADOW_ADDR(base) ((base) + (0x0000))
#define AAE_VSCF_REG_DEFAULT_ADDR(base) ((base) + (0x0004))
#define AAE_VSCF_TOP_CLK_SEL_ADDR(base) ((base) + (0x0008))
#define AAE_VSCF_TOP_CLK_EN_ADDR(base) ((base) + (0x000C))
#define AAE_VSCF_REG_CTRL_ADDR(base) ((base) + (0x0010))
#define AAE_VSCF_REG_CTRL_FLUSH_EN_ADDR(base) ((base) + (0x0014))
#define AAE_VSCF_REG_CTRL_DEBUG_ADDR(base) ((base) + (0x0018))
#define AAE_VSCF_REG_CTRL_STATE_ADDR(base) ((base) + (0x001C))
#define AAE_VSCF_R_LB_DEBUG0_ADDR(base) ((base) + (0x0030))
#define AAE_VSCF_R_LB_DEBUG1_ADDR(base) ((base) + (0x0034))
#define AAE_VSCF_R_LB_DEBUG2_ADDR(base) ((base) + (0x0038))
#define AAE_VSCF_R_LB_DEBUG3_ADDR(base) ((base) + (0x003C))
#define AAE_VSCF_W_LB_DEBUG0_ADDR(base) ((base) + (0x0040))
#define AAE_VSCF_W_LB_DEBUG1_ADDR(base) ((base) + (0x0044))
#define AAE_VSCF_W_LB_DEBUG2_ADDR(base) ((base) + (0x0048))
#define AAE_VSCF_W_LB_DEBUG3_ADDR(base) ((base) + (0x004C))
#define AAE_VSCF_REG_CTRL_LAYER_ID_ADDR(base) ((base) + (0x0050))
#define AAE_VSCF_DFC_DISP_SIZE_ADDR(base) ((base) + (0x0100))
#define AAE_VSCF_DFC_PIX_IN_NUM_ADDR(base) ((base) + (0x0104))
#define AAE_VSCF_DFC_GLB_ALPHA01_ADDR(base) ((base) + (0x0108))
#define AAE_VSCF_DFC_DISP_FMT_ADDR(base) ((base) + (0x010C))
#define AAE_VSCF_DFC_CLIP_CTL_HRZ_ADDR(base) ((base) + (0x0110))
#define AAE_VSCF_DFC_CLIP_CTL_VRZ_ADDR(base) ((base) + (0x0114))
#define AAE_VSCF_DFC_CTL_CLIP_EN_ADDR(base) ((base) + (0x0118))
#define AAE_VSCF_DFC_ICG_MODULE_ADDR(base) ((base) + (0x011C))
#define AAE_VSCF_DFC_DITHER_ENABLE_ADDR(base) ((base) + (0x0120))
#define AAE_VSCF_DFC_PADDING_CTL_ADDR(base) ((base) + (0x0124))
#define AAE_VSCF_DFC_GLB_ALPHA23_ADDR(base) ((base) + (0x0128))
#define AAE_VSCF_BITEXT_CTL_ADDR(base) ((base) + (0x0140))
#define AAE_VSCF_BITEXT_REG_INI0_0_ADDR(base) ((base) + (0x0144))
#define AAE_VSCF_BITEXT_REG_INI0_1_ADDR(base) ((base) + (0x0148))
#define AAE_VSCF_BITEXT_REG_INI0_2_ADDR(base) ((base) + (0x014C))
#define AAE_VSCF_BITEXT_REG_INI0_3_ADDR(base) ((base) + (0x0150))
#define AAE_VSCF_BITEXT_REG_INI1_0_ADDR(base) ((base) + (0x0154))
#define AAE_VSCF_BITEXT_REG_INI1_1_ADDR(base) ((base) + (0x0158))
#define AAE_VSCF_BITEXT_REG_INI1_2_ADDR(base) ((base) + (0x015C))
#define AAE_VSCF_BITEXT_REG_INI1_3_ADDR(base) ((base) + (0x0160))
#define AAE_VSCF_BITEXT_REG_INI2_0_ADDR(base) ((base) + (0x0164))
#define AAE_VSCF_BITEXT_REG_INI2_1_ADDR(base) ((base) + (0x0168))
#define AAE_VSCF_BITEXT_REG_INI2_2_ADDR(base) ((base) + (0x016C))
#define AAE_VSCF_BITEXT_REG_INI2_3_ADDR(base) ((base) + (0x0170))
#define AAE_VSCF_BITEXT_POWER_CTRL_C_ADDR(base) ((base) + (0x0174))
#define AAE_VSCF_BITEXT_POWER_CTRL_SHIFT_ADDR(base) ((base) + (0x0178))
#define AAE_VSCF_BITEXT_FILT_00_ADDR(base) ((base) + (0x017C))
#define AAE_VSCF_BITEXT_FILT_01_ADDR(base) ((base) + (0x0180))
#define AAE_VSCF_BITEXT_FILT_02_ADDR(base) ((base) + (0x0184))
#define AAE_VSCF_BITEXT_FILT_10_ADDR(base) ((base) + (0x0188))
#define AAE_VSCF_BITEXT_FILT_11_ADDR(base) ((base) + (0x018C))
#define AAE_VSCF_BITEXT_FILT_12_ADDR(base) ((base) + (0x0190))
#define AAE_VSCF_BITEXT_FILT_20_ADDR(base) ((base) + (0x0194))
#define AAE_VSCF_BITEXT_FILT_21_ADDR(base) ((base) + (0x01A0))
#define AAE_VSCF_BITEXT_FILT_22_ADDR(base) ((base) + (0x01A4))
#define AAE_VSCF_BITEXT_THD_R0_ADDR(base) ((base) + (0x01A8))
#define AAE_VSCF_BITEXT_THD_R1_ADDR(base) ((base) + (0x01AC))
#define AAE_VSCF_BITEXT_THD_G0_ADDR(base) ((base) + (0x01B0))
#define AAE_VSCF_BITEXT_THD_G1_ADDR(base) ((base) + (0x01B4))
#define AAE_VSCF_BITEXT_THD_B0_ADDR(base) ((base) + (0x01B8))
#define AAE_VSCF_BITEXT_THD_B1_ADDR(base) ((base) + (0x01BC))
#define AAE_VSCF_BITEXT0_DBG0_ADDR(base) ((base) + (0x01C0))
#define AAE_VSCF_CSC_IDC0_ADDR(base) ((base) + (0x01C4))
#define AAE_VSCF_CSC_IDC2_ADDR(base) ((base) + (0x01C8))
#define AAE_VSCF_CSC_ODC0_ADDR(base) ((base) + (0x01CC))
#define AAE_VSCF_CSC_ODC2_ADDR(base) ((base) + (0x01D0))
#define AAE_VSCF_CSC_P00_ADDR(base) ((base) + (0x01D4))
#define AAE_VSCF_CSC_P01_ADDR(base) ((base) + (0x01D8))
#define AAE_VSCF_CSC_P02_ADDR(base) ((base) + (0x01DC))
#define AAE_VSCF_CSC_P10_ADDR(base) ((base) + (0x01E0))
#define AAE_VSCF_CSC_P11_ADDR(base) ((base) + (0x01E4))
#define AAE_VSCF_CSC_P12_ADDR(base) ((base) + (0x01E8))
#define AAE_VSCF_CSC_P20_ADDR(base) ((base) + (0x01EC))
#define AAE_VSCF_CSC_P21_ADDR(base) ((base) + (0x01F0))
#define AAE_VSCF_CSC_P22_ADDR(base) ((base) + (0x01F4))
#define AAE_VSCF_CSC_ICG_MODULE_ADDR(base) ((base) + (0x01F8))
#define AAE_VSCF_CSC_MPREC_ADDR(base) ((base) + (0x01FC))
#define AAE_VSCF_SCF_EN_HSCL_STR_ADDR(base) ((base) + (0x0200))
#define AAE_VSCF_SCF_EN_VSCL_STR_ADDR(base) ((base) + (0x0204))
#define AAE_VSCF_SCF_H_V_ORDER_ADDR(base) ((base) + (0x0208))
#define AAE_VSCF_SCF_CH_CORE_GT_ADDR(base) ((base) + (0x020C))
#define AAE_VSCF_SCF_INPUT_WIDTH_HEIGHT_ADDR(base) ((base) + (0x0210))
#define AAE_VSCF_SCF_OUTPUT_WIDTH_HEIGHT_ADDR(base) ((base) + (0x0214))
#define AAE_VSCF_SCF_COEF_MEM_CTRL_ADDR(base) ((base) + (0x0218))
#define AAE_VSCF_SCF_EN_HSCL_ADDR(base) ((base) + (0x021C))
#define AAE_VSCF_SCF_EN_VSCL_ADDR(base) ((base) + (0x0220))
#define AAE_VSCF_SCF_ACC_HSCL_ADDR(base) ((base) + (0x0224))
#define AAE_VSCF_SCF_ACC_HSCL1_ADDR(base) ((base) + (0x0228))
#define AAE_VSCF_SCF_INC_HSCL_ADDR(base) ((base) + (0x0234))
#define AAE_VSCF_SCF_ACC_VSCL_ADDR(base) ((base) + (0x0238))
#define AAE_VSCF_SCF_ACC_VSCL1_ADDR(base) ((base) + (0x023C))
#define AAE_VSCF_SCF_INC_VSCL_ADDR(base) ((base) + (0x0248))
#define AAE_VSCF_SCF_EN_NONLINEAR_ADDR(base) ((base) + (0x024C))
#define AAE_VSCF_SCF_EN_MMP_ADDR(base) ((base) + (0x027C))
#define AAE_VSCF_SCF_DB_H0_ADDR(base) ((base) + (0x0280))
#define AAE_VSCF_SCF_DB_H1_ADDR(base) ((base) + (0x0284))
#define AAE_VSCF_SCF_DB_V0_ADDR(base) ((base) + (0x0288))
#define AAE_VSCF_SCF_DB_V1_ADDR(base) ((base) + (0x028C))
#define AAE_VSCF_SCF_LB_MEM_CTRL_ADDR(base) ((base) + (0x0290))
#define AAE_VSCF_POST_CLIP_DISP_SIZE_ADDR(base) ((base) + (0x0480))
#define AAE_VSCF_POST_CLIP_CTL_HRZ_ADDR(base) ((base) + (0x0484))
#define AAE_VSCF_POST_CLIP_CTL_VRZ_ADDR(base) ((base) + (0x0488))
#define AAE_VSCF_POST_CLIP_EN_ADDR(base) ((base) + (0x048C))
#define AAE_VSCF_V0_SCF_VIDEO_6TAP_COEF_ADDR(base,l) ((base) + (0x1000+0x4*(l)))
#define AAE_VSCF_V0_SCF_VIDEO_5TAP_COEF_ADDR(base,m) ((base) + (0x3000+0x4*(m)))
#define AAE_VSCF_V0_SCF_VIDEO_4TAP_COEF_ADDR(base,n) ((base) + (0x3800+0x4*(n)))
#define AAE_CLD_RGB_ADDR(base) ((base) + (0x0000))
#define AAE_CLD_CLK_EN_ADDR(base) ((base) + (0x0004))
#define AAE_CLD_CLK_SEL_ADDR(base) ((base) + (0x0008))
#define AAE_CLD_DBG_ADDR(base) ((base) + (0x000C))
#define AAE_CLD_DBG1_ADDR(base) ((base) + (0x0010))
#define AAE_CLD_DBG2_ADDR(base) ((base) + (0x0014))
#define AAE_CLD_DBG3_ADDR(base) ((base) + (0x0018))
#define AAE_CLD_DBG4_ADDR(base) ((base) + (0x001C))
#define AAE_CLD_DBG5_ADDR(base) ((base) + (0x0020))
#define AAE_CLD_DBG6_ADDR(base) ((base) + (0x0024))
#define AAE_CLD_DBG7_ADDR(base) ((base) + (0x0028))
#define AAE_CLD_EN_ADDR(base) ((base) + (0x002C))
#define AAE_CLD_SIZE_ADDR(base) ((base) + (0x0030))
#define AAE_CLD_REG_CTRL_ADDR(base) ((base) + (0x0040))
#define AAE_CLD_REG_CTRL_FLUSH_EN_ADDR(base) ((base) + (0x0044))
#define AAE_CLD_REG_CTRL_DEBUG_ADDR(base) ((base) + (0x0048))
#define AAE_CLD_REG_CTRL_STATE_ADDR(base) ((base) + (0x004C))
#define AAE_CLD_REG_CTRL_LAYER_ID_ADDR(base) ((base) + (0x0050))
#define AAE_CLD_REG_RD_SHADOW_ADDR(base) ((base) + (0x0090))
#define AAE_CLD_REG_DEFAULT_ADDR(base) ((base) + (0x0094))
#define AAE_CLD_R_LB_DEBUG0_ADDR(base) ((base) + (0x0100))
#define AAE_CLD_R_LB_DEBUG1_ADDR(base) ((base) + (0x0104))
#define AAE_CLD_R_LB_DEBUG2_ADDR(base) ((base) + (0x0108))
#define AAE_CLD_R_LB_DEBUG3_ADDR(base) ((base) + (0x010C))
#define AAE_CLD_W_LB_DEBUG0_ADDR(base) ((base) + (0x0110))
#define AAE_CLD_W_LB_DEBUG1_ADDR(base) ((base) + (0x0114))
#define AAE_CLD_W_LB_DEBUG2_ADDR(base) ((base) + (0x0118))
#define AAE_CLD_W_LB_DEBUG3_ADDR(base) ((base) + (0x011C))
#define AAE_LB_WRAP_CLK_SEL_ADDR(base) ((base) + (0x0000))
#define AAE_LB_WRAP_CLK_EN_ADDR(base) ((base) + (0x0004))
#define AAE_LB_WRAP_LBUF_CTL_CLK_SEL_ADDR(base) ((base) + (0x0020))
#define AAE_LB_WRAP_LBUF_CTL_CLK_EN_ADDR(base) ((base) + (0x0024))
#define AAE_LB_WRAP_MEM_DSLP_CTRL_ADDR(base) ((base) + (0x0028))
#define AAE_LB_WRAP_LBUF_CTL_STATE_ADDR(base) ((base) + (0x002C))
#define AAE_LB_WRAP_LBUF_RF_USE_NUM_ADDR(base) ((base) + (0x0030))
#define AAE_LB_WRAP_LBUF_DBG_RF_NUM_ADDR(base) ((base) + (0x0034))
#define AAE_LB_WRAP_LBUF_DBG_RF_NUM1_ADDR(base) ((base) + (0x0038))
#define AAE_LB_WRAP_LBUF_DBG_FRM_CNT_ADDR(base) ((base) + (0x003C))
#define AAE_LB_WRAP_LBUF_DBG_RUN_SEL_ADDR(base) ((base) + (0x0040))
#define AAE_LB_WRAP_LBUF_RUN_STATE_ADDR(base) ((base) + (0x0044))
#define AAE_LB_WRAP_LBUF_RUN_MST_STATE_ADDR(base) ((base) + (0x0048))
#define AAE_LB_WRAP_LBUF_RUN_CTL_STATE_ADDR(base) ((base) + (0x004C))
#define AAE_LB_WRAP_LBUF_RUN_WR_STATE_ADDR(base) ((base) + (0x0050))
#define AAE_LB_WRAP_LBUF_RUN_RD_STATE_ADDR(base) ((base) + (0x0054))
#define AAE_LB_WRAP_LBUF_RUN_RD2_STATE_ADDR(base) ((base) + (0x0058))
#define AAE_LB_WRAP_LBUF_CLR_RLST_RDY_ADDR(base) ((base) + (0x005C))
#define AAE_LB_WRAP_LBUF_CLR_RLST_RUN_IDX_ADDR(base) ((base) + (0x0060))
#define AAE_LB_WRAP_LBUF_DBG_WB_EN_ADDR(base) ((base) + (0x0064))
#define AAE_LB_WRAP_LBUF_PART_CLK_SEL_ADDR(base) ((base) + (0x0100))
#define AAE_LB_WRAP_LBUF_PART_CLK_EN_ADDR(base) ((base) + (0x0104))
#define AAE_LB_WRAP_LBUF_MEM_CTRL_ADDR(base) ((base) + (0x0108))
#define AAE_LB_WRAP_DEBUG_CTRL_ADDR(base) ((base) + (0x010C))
#define AAE_LB_WRAP_LBUF_PART_RMST_PASS_ADDR(base) ((base) + (0x0110))
#define AAE_LB_WRAP_LBUF_PART_WMST_PASS_ADDR(base) ((base) + (0x0114))
#define AAE_LB_WRAP_LBUF_PART_IDX_DATA_ADDR(base) ((base) + (0x0118))
#define AAE_LB_WRAP_LBUF_PART_RUN_DAT_ADDR(base) ((base) + (0x011C))
#define AAE_WDFC_REG_DEFAULT_ADDR(base) ((base) + (0x00D0))
#define AAE_WDFC_CH_RD_SHADOW_ADDR(base) ((base) + (0x00D4))
#define AAE_WDFC_CH_SW_END_REQ_ADDR(base) ((base) + (0x00E0))
#define AAE_WDFC_CH_CLK_SEL_ADDR(base) ((base) + (0x00E4))
#define AAE_WDFC_CH_CLK_EN_ADDR(base) ((base) + (0x00E8))
#define AAE_WDFC_CH_DBG0_ADDR(base) ((base) + (0x00EC))
#define AAE_WDFC_CH_DBG1_ADDR(base) ((base) + (0x00F0))
#define AAE_WDFC_CH_DBG2_ADDR(base) ((base) + (0x00F4))
#define AAE_WDFC_CH_DBG3_ADDR(base) ((base) + (0x00F8))
#define AAE_WDFC_CH_DBG4_ADDR(base) ((base) + (0x00FC))
#define AAE_WDFC_CH_DBG5_ADDR(base) ((base) + (0x00C0))
#define AAE_WDFC_CH_DBG6_ADDR(base) ((base) + (0x00CC))
#define AAE_WDFC_DFC_DISP_SIZE_ADDR(base) ((base) + (0x0100))
#define AAE_WDFC_DFC_PIX_IN_NUM_ADDR(base) ((base) + (0x0104))
#define AAE_WDFC_DFC_GLB_ALPHA01_ADDR(base) ((base) + (0x0108))
#define AAE_WDFC_DFC_DISP_FMT_ADDR(base) ((base) + (0x010C))
#define AAE_WDFC_DFC_CLIP_CTL_HRZ_ADDR(base) ((base) + (0x0110))
#define AAE_WDFC_DFC_CLIP_CTL_VRZ_ADDR(base) ((base) + (0x0114))
#define AAE_WDFC_DFC_CTL_CLIP_EN_ADDR(base) ((base) + (0x0118))
#define AAE_WDFC_DFC_ICG_MODULE_ADDR(base) ((base) + (0x011C))
#define AAE_WDFC_DFC_DITHER_ENABLE_ADDR(base) ((base) + (0x0120))
#define AAE_WDFC_DFC_PADDING_CTL_ADDR(base) ((base) + (0x0124))
#define AAE_WDFC_DFC_GLB_ALPHA23_ADDR(base) ((base) + (0x0128))
#define AAE_WDFC_DFC_GLB_ALPHA_ADDR(base) ((base) + (0x012C))
#define AAE_WDFC_DFC_ALPHA_CTL_ADDR(base) ((base) + (0x0130))
#define AAE_WDFC_DFC_ALPHA_THD_ADDR(base) ((base) + (0x0134))
#define AAE_WDFC_BITEXT_CTL_ADDR(base) ((base) + (0x0140))
#define AAE_WDFC_BITEXT_REG_INI0_0_ADDR(base) ((base) + (0x0144))
#define AAE_WDFC_BITEXT_REG_INI0_1_ADDR(base) ((base) + (0x0148))
#define AAE_WDFC_BITEXT_REG_INI0_2_ADDR(base) ((base) + (0x014C))
#define AAE_WDFC_BITEXT_REG_INI0_3_ADDR(base) ((base) + (0x0150))
#define AAE_WDFC_BITEXT_REG_INI1_0_ADDR(base) ((base) + (0x0154))
#define AAE_WDFC_BITEXT_REG_INI1_1_ADDR(base) ((base) + (0x0158))
#define AAE_WDFC_BITEXT_REG_INI1_2_ADDR(base) ((base) + (0x015C))
#define AAE_WDFC_BITEXT_REG_INI1_3_ADDR(base) ((base) + (0x0160))
#define AAE_WDFC_BITEXT_REG_INI2_0_ADDR(base) ((base) + (0x0164))
#define AAE_WDFC_BITEXT_REG_INI2_1_ADDR(base) ((base) + (0x0168))
#define AAE_WDFC_BITEXT_REG_INI2_2_ADDR(base) ((base) + (0x016C))
#define AAE_WDFC_BITEXT_REG_INI2_3_ADDR(base) ((base) + (0x0170))
#define AAE_WDFC_BITEXT_POWER_CTRL_C_ADDR(base) ((base) + (0x0174))
#define AAE_WDFC_BITEXT_POWER_CTRL_SHIFT_ADDR(base) ((base) + (0x0178))
#define AAE_WDFC_BITEXT_FILT_00_ADDR(base) ((base) + (0x017C))
#define AAE_WDFC_BITEXT_FILT_01_ADDR(base) ((base) + (0x0180))
#define AAE_WDFC_BITEXT_FILT_02_ADDR(base) ((base) + (0x0184))
#define AAE_WDFC_BITEXT_FILT_10_ADDR(base) ((base) + (0x0188))
#define AAE_WDFC_BITEXT_FILT_11_ADDR(base) ((base) + (0x018C))
#define AAE_WDFC_BITEXT_FILT_12_ADDR(base) ((base) + (0x0190))
#define AAE_WDFC_BITEXT_FILT_20_ADDR(base) ((base) + (0x0194))
#define AAE_WDFC_BITEXT_FILT_21_ADDR(base) ((base) + (0x01A0))
#define AAE_WDFC_BITEXT_FILT_22_ADDR(base) ((base) + (0x01A4))
#define AAE_WDFC_BITEXT_THD_R0_ADDR(base) ((base) + (0x01A8))
#define AAE_WDFC_BITEXT_THD_R1_ADDR(base) ((base) + (0x01AC))
#define AAE_WDFC_BITEXT_THD_G0_ADDR(base) ((base) + (0x01B0))
#define AAE_WDFC_BITEXT_THD_G1_ADDR(base) ((base) + (0x01B4))
#define AAE_WDFC_BITEXT_THD_B0_ADDR(base) ((base) + (0x01B8))
#define AAE_WDFC_BITEXT_THD_B1_ADDR(base) ((base) + (0x01BC))
#define AAE_WDFC_BITEXT0_DBG0_ADDR(base) ((base) + (0x01C0))
#define AAE_WDFC_DITHER_CTL1_ADDR(base) ((base) + (0x01D0))
#define AAE_WDFC_DITHER_TRI_THD10_ADDR(base) ((base) + (0x01DC))
#define AAE_WDFC_DITHER_TRI_THD10_UNI_ADDR(base) ((base) + (0x01E8))
#define AAE_WDFC_BAYER_CTL_ADDR(base) ((base) + (0x01EC))
#define AAE_WDFC_BAYER_MATRIX_PART1_ADDR(base) ((base) + (0x01F4))
#define AAE_WDFC_BAYER_MATRIX_PART0_ADDR(base) ((base) + (0x01F8))
#define AAE_WDFC_CLIP_DISP_SIZE_ADDR(base) ((base) + (0x0480))
#define AAE_WDFC_CLIP_CTL_HRZ_ADDR(base) ((base) + (0x0484))
#define AAE_WDFC_CLIP_CTL_VRZ_ADDR(base) ((base) + (0x0488))
#define AAE_WDFC_CLIP_EN_ADDR(base) ((base) + (0x048C))
#define AAE_WDFC_CSC_IDC0_ADDR(base) ((base) + (0x0500))
#define AAE_WDFC_CSC_IDC2_ADDR(base) ((base) + (0x0504))
#define AAE_WDFC_CSC_ODC0_ADDR(base) ((base) + (0x0508))
#define AAE_WDFC_CSC_ODC2_ADDR(base) ((base) + (0x050C))
#define AAE_WDFC_CSC_P00_ADDR(base) ((base) + (0x0510))
#define AAE_WDFC_CSC_P01_ADDR(base) ((base) + (0x0514))
#define AAE_WDFC_CSC_P02_ADDR(base) ((base) + (0x0518))
#define AAE_WDFC_CSC_P10_ADDR(base) ((base) + (0x051C))
#define AAE_WDFC_CSC_P11_ADDR(base) ((base) + (0x0520))
#define AAE_WDFC_CSC_P12_ADDR(base) ((base) + (0x0524))
#define AAE_WDFC_CSC_P20_ADDR(base) ((base) + (0x0528))
#define AAE_WDFC_CSC_P21_ADDR(base) ((base) + (0x052C))
#define AAE_WDFC_CSC_P22_ADDR(base) ((base) + (0x0530))
#define AAE_WDFC_CSC_ICG_MODULE_ADDR(base) ((base) + (0x0534))
#define AAE_WDFC_REG_CTRL_ADDR(base) ((base) + (0x608))
#define AAE_WDFC_REG_CTRL_FLUSH_EN_ADDR(base) ((base) + (0x60C))
#define AAE_WDFC_REG_CTRL_DEBUG_ADDR(base) ((base) + (0x610))
#define AAE_SCF2D_RD_SHADOW_ADDR(base) ((base) + (0x0000))
#define AAE_SCF2D_REG_DEFAULT_ADDR(base) ((base) + (0x0004))
#define AAE_SCF2D_TOP_CLK_SEL_ADDR(base) ((base) + (0x0008))
#define AAE_SCF2D_TOP_CLK_EN_ADDR(base) ((base) + (0x000C))
#define AAE_SCF2D_REG_CTRL_ADDR(base) ((base) + (0x0010))
#define AAE_SCF2D_REG_CTRL_FLUSH_EN_ADDR(base) ((base) + (0x0014))
#define AAE_SCF2D_REG_CTRL_DEBUG_ADDR(base) ((base) + (0x0018))
#define AAE_SCF2D_REG_CTRL_STATE_ADDR(base) ((base) + (0x001C))
#define AAE_SCF2D_REG_CTRL_LAYER_ID_ADDR(base) ((base) + (0x0080))
#define AAE_SCF2D_CSC_IDC0_ADDR(base) ((base) + (0x0020))
#define AAE_SCF2D_CSC_IDC2_ADDR(base) ((base) + (0x0024))
#define AAE_SCF2D_CSC_ODC0_ADDR(base) ((base) + (0x0028))
#define AAE_SCF2D_CSC_ODC2_ADDR(base) ((base) + (0x002C))
#define AAE_SCF2D_CSC_P00_ADDR(base) ((base) + (0x0030))
#define AAE_SCF2D_CSC_P01_ADDR(base) ((base) + (0x0034))
#define AAE_SCF2D_CSC_P02_ADDR(base) ((base) + (0x0038))
#define AAE_SCF2D_CSC_P10_ADDR(base) ((base) + (0x003C))
#define AAE_SCF2D_CSC_P11_ADDR(base) ((base) + (0x0040))
#define AAE_SCF2D_CSC_P12_ADDR(base) ((base) + (0x0044))
#define AAE_SCF2D_CSC_P20_ADDR(base) ((base) + (0x0048))
#define AAE_SCF2D_CSC_P21_ADDR(base) ((base) + (0x004C))
#define AAE_SCF2D_CSC_P22_ADDR(base) ((base) + (0x0050))
#define AAE_SCF2D_CSC_ICG_MODULE_ADDR(base) ((base) + (0x0054))
#define AAE_SCF2D_CSC_MPREC_ADDR(base) ((base) + (0x0058))
#define AAE_SCF2D_EN_ADDR(base) ((base) + (0x0120))
#define AAE_SCF2D_INPUT_SIZE_ADDR(base) ((base) + (0x0124))
#define AAE_SCF2D_OUTPUT_SIZE_ADDR(base) ((base) + (0x0128))
#define AAE_SCF2D_HINC_ADDR(base) ((base) + (0x012C))
#define AAE_SCF2D_VINC_ADDR(base) ((base) + (0x0130))
#define AAE_SCF2D_HLEFT1_INT_ADDR(base) ((base) + (0x0134))
#define AAE_SCF2D_HLEFT1_FRAC_ADDR(base) ((base) + (0x0138))
#define AAE_SCF2D_HRIGHT1_INT_ADDR(base) ((base) + (0x013C))
#define AAE_SCF2D_HRIGHT1_FRAC_ADDR(base) ((base) + (0x0140))
#define AAE_SCF2D_HLEFT_INT_ADDR(base) ((base) + (0x0144))
#define AAE_SCF2D_HLEFT_FRAC_ADDR(base) ((base) + (0x0148))
#define AAE_SCF2D_HRIGHT_INT_ADDR(base) ((base) + (0x014C))
#define AAE_SCF2D_HRIGHT_FRAC_ADDR(base) ((base) + (0x0150))
#define AAE_SCF2D_VTOP_INT_ADDR(base) ((base) + (0x0154))
#define AAE_SCF2D_VTOP_FRAC_ADDR(base) ((base) + (0x0158))
#define AAE_SCF2D_VBOTTOM_INT_ADDR(base) ((base) + (0x015C))
#define AAE_SCF2D_VBOTTOM_FRAC_ADDR(base) ((base) + (0x0160))
#define AAE_SCF2D_LB_MEM_CTRL_ADDR(base) ((base) + (0x0180))
#define AAE_SCF2D_DBG0_ADDR(base) ((base) + (0x0184))
#define AAE_SCF2D_DBG1_ADDR(base) ((base) + (0x0188))
#define AAE_BLUR_RD_SHADOW_ADDR(base) ((base) + (0x0000))
#define AAE_BLUR_REG_DEFAULT_ADDR(base) ((base) + (0x0004))
#define AAE_BLUR_WRAP_CLK_SEL_ADDR(base) ((base) + (0x0008))
#define AAE_BLUR_WRAP_CLK_EN_ADDR(base) ((base) + (0x000C))
#define AAE_BLUR_REG_CTRL_ADDR(base) ((base) + (0x0010))
#define AAE_BLUR_REG_CTRL_FLUSH_EN_ADDR(base) ((base) + (0x0014))
#define AAE_BLUR_REG_CTRL_DEBUG_ADDR(base) ((base) + (0x0018))
#define AAE_BLUR_REG_CTRL_STATE_ADDR(base) ((base) + (0x001C))
#define AAE_BLUR_REG_CTRL_LAYER_ID_ADDR(base) ((base) + (0x0080))
#define AAE_BLUR_EN_ADDR(base) ((base) + (0x0090))
#define AAE_BLUR_INPUT_SIZE_ADDR(base) ((base) + (0x0094))
#define AAE_BLUR_OUTPUT_SIZE_ADDR(base) ((base) + (0x0098))
#define AAE_BLUR_DBG0_ADDR(base) ((base) + (0x009C))
#define AAE_BLUR_DBG1_ADDR(base) ((base) + (0x00A0))
#define AAE_BLUR_PREMULT_EN_ADDR(base) ((base) + (0x0110))
#define AAE_BLUR_GFILT_EN_ADDR(base) ((base) + (0x0120))
#define AAE_BLUR_GFILT_KNL_SIZE_ADDR(base) ((base) + (0x0124))
#define AAE_BLUR_GFILT_H_COEF_ADDR(base,blur_gfilt) ((base) + (0x0128+0x4*(blur_gfilt)))
#define AAE_BLUR_GFILT_V_COEF_ADDR(base,blur_gfilt) ((base) + (0x01AC+0x4*(blur_gfilt)))
#define AAE_BLUR_GFILT_LB_MEM_CTRL_ADDR(base) ((base) + (0x0230))
#define AAE_BLUR_GFILT_DBG0_ADDR(base) ((base) + (0x0234))
#define AAE_BLUR_GFILT_DBG1_ADDR(base) ((base) + (0x0238))
#define AAE_BLUR_CLIP_LEFT_ADDR(base) ((base) + (0x0250))
#define AAE_BLUR_CLIP_RIGHT_ADDR(base) ((base) + (0x0254))
#define AAE_BLUR_CLIP_EN_ADDR(base) ((base) + (0x0258))
#define AAE_BLUR_CLIP_DBG_ADDR(base) ((base) + (0x025C))
#define AAE_BLUR_MEAN_COLOR_EN_ADDR(base) ((base) + (0x0270))
#define AAE_BLUR_MEAN_COLOR_R_ADDR(base) ((base) + (0x0274))
#define AAE_BLUR_MEAN_COLOR_G_ADDR(base) ((base) + (0x0278))
#define AAE_BLUR_MEAN_COLOR_B_ADDR(base) ((base) + (0x027C))
#define AAE_BLUR_MEAN_COLOR_A_ADDR(base) ((base) + (0x0280))
#define AAE_HIOF_RD_SHADOW_ADDR(base) ((base) + (0x0000))
#define AAE_HIOF_REG_DEFAULT_ADDR(base) ((base) + (0x0004))
#define AAE_HIOF_WRAP_CLK_SEL_ADDR(base) ((base) + (0x0008))
#define AAE_HIOF_WRAP_CLK_EN_ADDR(base) ((base) + (0x000C))
#define AAE_HIOF_REG_CTRL_ADDR(base) ((base) + (0x0010))
#define AAE_HIOF_REG_CTRL_FLUSH_EN_ADDR(base) ((base) + (0x0014))
#define AAE_HIOF_REG_CTRL_DEBUG_ADDR(base) ((base) + (0x0018))
#define AAE_HIOF_REG_CTRL_STATE_ADDR(base) ((base) + (0x001C))
#define AAE_HIOF_EN_ADDR(base) ((base) + (0x0020))
#define AAE_HIOF_LAYER_ID_ADDR(base) ((base) + (0x0024))
#define AAE_HIOF_LEVEL_ADDR(base) ((base) + (0x0028))
#define AAE_HIOF_CFG_ADDR(base) ((base) + (0x002C))
#define AAE_HIOF_SIZE_CFG_ADDR(base) ((base) + (0x0030))
#define AAE_HIOF_SIZE_CFG1_ADDR(base) ((base) + (0x0034))
#define AAE_HIOF_SIZE_CFG2_ADDR(base) ((base) + (0x0038))
#define AAE_HIOF_REF0_STORE_SIZE_ADDR(base) ((base) + (0x003C))
#define AAE_HIOF_REF1_STORE_SIZE_ADDR(base) ((base) + (0x0040))
#define AAE_HIOF_CUR0_STORE_SIZE_ADDR(base) ((base) + (0x0044))
#define AAE_HIOF_CUR1_STORE_SIZE_ADDR(base) ((base) + (0x0048))
#define AAE_HIOF_MV0_STORE_SIZE_ADDR(base) ((base) + (0x004C))
#define AAE_HIOF_MV1_STORE_SIZE_ADDR(base) ((base) + (0x0050))
#define AAE_HIOF_W_STRIDE_ADDR(base) ((base) + (0x0054))
#define AAE_HIOF_OUTPUT0_CTRL_ADDR(base) ((base) + (0x0058))
#define AAE_HIOF_OUTPUT1_CTRL_ADDR(base) ((base) + (0x005C))
#define AAE_HIOF_CUR_WIDTH_AFT_STRIDE_ADDR(base) ((base) + (0x0060))
#define AAE_HIOF_OFFSET_ADDR(base) ((base) + (0x0064))
#define AAE_HIOF_COEFF_CFG_ADDR(base) ((base) + (0x0068))
#define AAE_HIOF_THRESHOLD_CFG_ADDR(base) ((base) + (0x006C))
#define AAE_HIOF_MV_ADJ_CFG0_ADDR(base) ((base) + (0x0070))
#define AAE_HIOF_MV_ADJ_CFG1_ADDR(base) ((base) + (0x0074))
#define AAE_HIOF_MOTION_STATUS_ADDR(base) ((base) + (0x0078))
#define AAE_HIOF_PSNR_MSE_ADDR(base) ((base) + (0x007C))
#define AAE_HIOF_MEM_CTRL_ADDR(base) ((base) + (0x0080))
#define AAE_HIOF_DEBUG_RO1_ADDR(base) ((base) + (0x180))
#define AAE_HIOF_DEBUG_RO2_ADDR(base) ((base) + (0x184))
#define AAE_HIOF_DEBUG_RW_ADDR(base) ((base) + (0x188))
#define AAE_AIHDR_ENABLE_ADDR(base) ((base) + (0x0000))
#define AAE_AIHDR_IMAGE_ADDR(base) ((base) + (0x0004))
#define AAE_AIHDR_DERIV_WIDTH_ADDR(base) ((base) + (0x0008))
#define AAE_AIHDR_DERIV_HEIGHT_ADDR(base) ((base) + (0x000C))
#define AAE_AIHDR_STRIPE_OFFSET_X_ADDR(base) ((base) + (0x0010))
#define AAE_AIHDR_AITTONE_GRID_BLOCK_OFFSET_X_ADDR(base) ((base) + (0x0014))
#define AAE_AIHDR_RGB2Y_R0_ADDR(base) ((base) + (0x0018))
#define AAE_AIHDR_RGB2Y_G0_ADDR(base) ((base) + (0x001C))
#define AAE_AIHDR_RGB2Y_B0_ADDR(base) ((base) + (0x0020))
#define AAE_AIHDR_RGB2Y_R1_ADDR(base) ((base) + (0x0024))
#define AAE_AIHDR_RGB2Y_G1_ADDR(base) ((base) + (0x0028))
#define AAE_AIHDR_RGB2Y_B1_ADDR(base) ((base) + (0x002C))
#define AAE_AIHDR_GAIN_LUT_ADDR(base,aihdr_r256) ((base) + (0x0090+0x4*(aihdr_r256)))
#define AAE_AIHDR_STATUS_ADDR(base) ((base) + (0x0490))
#define AAE_AIHDR_BLENDING_WEIGHT_ADDR(base) ((base) + (0x0494))
#define AAE_AIHDR_DEBUG_0_ADDR(base) ((base) + (0x0504))
#define AAE_AIHDR_DEBUG_1_ADDR(base) ((base) + (0x0508))
#define AAE_AIHDR_EC_0_ADDR(base) ((base) + (0x0510))
#define AAE_AIHDR_EC_1_ADDR(base) ((base) + (0x0514))
#define AAE_AIHDR_WRAP_CTRL_ADDR(base) ((base) + (0x0720))
#define AAE_AIHDR_WRAP_SIZE_ADDR(base) ((base) + (0x0724))
#define AAE_AIHDR_WRAP_DEBUG_0_ADDR(base) ((base) + (0x0744))
#define AAE_AIHDR_WRAP_DEBUG_1_ADDR(base) ((base) + (0x0748))
#define AAE_AIHDR_WRAP_MEM_CTRL_ADDR(base) ((base) + (0x074C))
#define AAE_AIHDR_CSC_IDC0_ADDR(base) ((base) + (0x07C4))
#define AAE_AIHDR_CSC_IDC2_ADDR(base) ((base) + (0x07C8))
#define AAE_AIHDR_CSC_ODC0_ADDR(base) ((base) + (0x07CC))
#define AAE_AIHDR_CSC_ODC2_ADDR(base) ((base) + (0x07D0))
#define AAE_AIHDR_CSC_P00_ADDR(base) ((base) + (0x07D4))
#define AAE_AIHDR_CSC_P01_ADDR(base) ((base) + (0x07D8))
#define AAE_AIHDR_CSC_P02_ADDR(base) ((base) + (0x07DC))
#define AAE_AIHDR_CSC_P10_ADDR(base) ((base) + (0x07E0))
#define AAE_AIHDR_CSC_P11_ADDR(base) ((base) + (0x07E4))
#define AAE_AIHDR_CSC_P12_ADDR(base) ((base) + (0x07E8))
#define AAE_AIHDR_CSC_P20_ADDR(base) ((base) + (0x07EC))
#define AAE_AIHDR_CSC_P21_ADDR(base) ((base) + (0x07F0))
#define AAE_AIHDR_CSC_P22_ADDR(base) ((base) + (0x07F4))
#define AAE_AIHDR_CSC_ICG_MODULE_ADDR(base) ((base) + (0x07F8))
#define AAE_AIHDR_CSC_MPREC_ADDR(base) ((base) + (0x07FC))
#define AAE_AIHDR_REG_CTRL_FLUSH_EN_ADDR(base) ((base) + (0x0800))
#define AAE_AIHDR_REG_CTRL_DEBUG_ADDR(base) ((base) + (0x0804))
#define AAE_AIHDR_WRAP_RD_SHADOW_ADDR(base) ((base) + (0x0820))
#define AAE_AIHDR_REG_DEFAULT_ADDR(base) ((base) + (0x0824))
#define AAE_BLPP_RD_SHADOW_ADDR(base) ((base) + (0x0000))
#define AAE_BLPP_REG_DEFAULT_ADDR(base) ((base) + (0x0004))
#define AAE_BLPP_WRAP_CLK_SEL_ADDR(base) ((base) + (0x0008))
#define AAE_BLPP_WRAP_CLK_EN_ADDR(base) ((base) + (0x000C))
#define AAE_BLPP_REG_CTRL_ADDR(base) ((base) + (0x0010))
#define AAE_BLPP_REG_CTRL_FLUSH_EN_ADDR(base) ((base) + (0x0014))
#define AAE_BLPP_REG_CTRL_DEBUG_ADDR(base) ((base) + (0x0018))
#define AAE_BLPP_REG_CTRL_STATE_ADDR(base) ((base) + (0x001C))
#define AAE_BLPP_REG_CTRL_LAYER_ID_ADDR(base) ((base) + (0x0080))
#define AAE_BLPP_EN_ADDR(base) ((base) + (0x0090))
#define AAE_BLPP_SIZE_ADDR(base) ((base) + (0x0094))
#define AAE_BLPP_DBG0_ADDR(base) ((base) + (0x0098))
#define AAE_BLPP_DBG1_ADDR(base) ((base) + (0x009C))
#define AAE_BLPP_CANCEL_PREMULT_EN_ADDR(base) ((base) + (0x0110))
#define AAE_BLPP_NOISE_EN_ADDR(base) ((base) + (0x0120))
#define AAE_BLPP_NOISE_BLK_STR_H_POS_ADDR(base) ((base) + (0x0124))
#define AAE_BLPP_NOISE_RATIO_ADDR(base) ((base) + (0x0128))
#define AAE_BLPP_NOISE_VAL_PARA_ADDR(base) ((base) + (0x012C))
#define AAE_BLPP_COLOR_MATRIX_EN_ADDR(base) ((base) + (0x0140))
#define AAE_BLPP_COLOR_MATRIX_COEF_ADDR(base,blpp_cmcoef) ((base) + (0x0144+0x4*(blpp_cmcoef)))
#define AAE_BLPP_PREMULT_EN_ADDR(base) ((base) + (0x0200))
#define AAE_BLPP_COLOR_MASK_EN_ADDR(base) ((base) + (0x0210))
#define AAE_BLPP_COLOR_MASK_R_G_ADDR(base) ((base) + (0x0214))
#define AAE_BLPP_COLOR_MASK_B_A_ADDR(base) ((base) + (0x0218))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aae_vesion : 32;
    } reg;
} AAE_GLB_PART0_AAE_VESION_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fpga_version : 32;
    } reg;
} AAE_GLB_PART0_FPGA_VERSION_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aae_jtag_mode : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_GLB_PART0_AAE_JTAG_MODE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clk_part0_en : 1;
        unsigned int clk_part1_en : 1;
        unsigned int reserved : 30;
    } reg;
} AAE_GLB_PART0_AAE_PART_CLK_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rst_part0_en : 1;
        unsigned int rst_part1_en : 1;
        unsigned int reserved : 30;
    } reg;
} AAE_GLB_PART0_AAE_PART_RST_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clk_aae_core_pipe_ctrl0_sel : 1;
        unsigned int clk_aae_core_pipe_ctrl1_sel : 1;
        unsigned int clk_aae_core_pipe_ctrl2_sel : 1;
        unsigned int clk_aae_core_pipe_ctrl3_sel : 1;
        unsigned int clk_aae_core_rd_ctrl1_sel : 1;
        unsigned int clk_aae_core_rd_ctrl2_sel : 1;
        unsigned int clk_aae_core_wr_ctrl1_sel : 1;
        unsigned int clk_aae_core_wr_ctrl2_sel : 1;
        unsigned int clk_aae_core_rd_blk_ctrl_sel : 1;
        unsigned int clk_aae_core_rdfc_pack_sel : 1;
        unsigned int clk_aae_core_lb_wrap_sel : 1;
        unsigned int clk_aae_core_info_src_sel : 1;
        unsigned int clk_aae_core_sdma0_sel : 1;
        unsigned int clk_aae_wdfc_sel : 1;
        unsigned int clk_aae_core_wdma0_sel : 1;
        unsigned int clk_aae_core_cmd_sel : 1;
        unsigned int clk_aae_core_dcmd_sel : 1;
        unsigned int clk_aae_core_ov_sel : 1;
        unsigned int clk_aae_core_arsr0_sel : 1;
        unsigned int reserved_0 : 1;
        unsigned int clk_aae_core_vscf0_sel : 1;
        unsigned int reserved_1 : 1;
        unsigned int clk_aae_core_cld_sel : 1;
        unsigned int clk_aae_core_hdr_sel : 1;
        unsigned int clk_aae_core_dbcu_sel : 1;
        unsigned int clk_aae_core_part0_lbus_sel : 1;
        unsigned int clk_aae_core_glb_sel : 1;
        unsigned int clk_aae_core_dbg_sel : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 2;
    } reg;
} AAE_GLB_PART0_MODULE_CLK_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clk_aae_core_pipe_ctrl0_en : 1;
        unsigned int clk_aae_core_pipe_ctrl1_en : 1;
        unsigned int clk_aae_core_pipe_ctrl2_en : 1;
        unsigned int clk_aae_core_pipe_ctrl3_en : 1;
        unsigned int clk_aae_core_rd_ctr1_en : 1;
        unsigned int clk_aae_core_rd_ctrl2_en : 1;
        unsigned int clk_aae_core_wr_ctrl1_en : 1;
        unsigned int clk_aae_core_wr_ctrl2_en : 1;
        unsigned int clk_aae_core_rd_blk_ctrl_en : 1;
        unsigned int clk_aae_core_rdfc_pack_en : 1;
        unsigned int clk_aae_core_lb_wrap_en : 1;
        unsigned int clk_aae_core_info_src_en : 1;
        unsigned int clk_aae_core_sdma0_en : 1;
        unsigned int clk_aae_core_wdfc_en : 1;
        unsigned int clk_aae_core_wdma0_en : 1;
        unsigned int clk_aae_core_cmd_en : 1;
        unsigned int clk_aae_core_dcmd_en : 1;
        unsigned int clk_aae_core_ov_en : 1;
        unsigned int clk_aae_core_arsr0_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int clk_aae_core_vscf0_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int clk_aae_core_cld_en : 1;
        unsigned int clk_aae_core_hdr_en : 1;
        unsigned int clk_aae_core_dbcu_en : 1;
        unsigned int clk_aae_core_part0_lbus_en : 1;
        unsigned int clk_aae_core_glb_en : 1;
        unsigned int clk_aae_core_dbg_en : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 2;
    } reg;
} AAE_GLB_PART0_MODULE_CLK_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dss_pm_ctrl : 32;
    } reg;
} AAE_GLB_PART0_AAE_PM_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dss_mem_ctrl : 32;
    } reg;
} AAE_GLB_PART0_AAE_SPRAM_CTRL_S_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dss_mem_ctrl_tp : 32;
    } reg;
} AAE_GLB_PART0_AAE_TPRAM_CTRL_TP_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dss_mem_ctrl_bp : 32;
    } reg;
} AAE_GLB_PART0_AAE_TPRAM_CTRL_BP_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dss_mem_ctrl_spc : 32;
    } reg;
} AAE_GLB_PART0_AAE_SPRAM_CTRL_SPC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dss_mem_ctrl_tpl : 32;
    } reg;
} AAE_GLB_PART0_AAE_TPRAM_CTRL_TPL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dss_mem_ctrl_bpl : 32;
    } reg;
} AAE_GLB_PART0_AAE_TPRAM_CTRL_BPL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aae_ns_offline0_to_gic_o : 9;
        unsigned int reserved : 23;
    } reg;
} AAE_GLB_PART0_AAE_NS_OFFLINE0_TO_GIC_O_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aae_ns_offline0_to_gic_msk : 9;
        unsigned int reserved : 23;
    } reg;
} AAE_GLB_PART0_AAE_NS_OFFLINE0_TO_GIC_MSK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aae_ns_offline1_to_gic_o : 9;
        unsigned int reserved : 23;
    } reg;
} AAE_GLB_PART0_AAE_NS_OFFLINE1_TO_GIC_O_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aae_ns_offline1_to_gic_msk : 9;
        unsigned int reserved : 23;
    } reg;
} AAE_GLB_PART0_AAE_NS_OFFLINE1_TO_GIC_MSK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aae_ns_offline0_to_iomcu_o : 9;
        unsigned int reserved : 23;
    } reg;
} AAE_GLB_PART0_AAE_NS_OFFLINE0_TO_IOMCU_O_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aae_ns_offline0_to_iomcu_msk : 9;
        unsigned int reserved : 23;
    } reg;
} AAE_GLB_PART0_AAE_NS_OFFLINE0_TO_IOMCU_MSK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aae_ns_offline1_to_iomcu_o : 9;
        unsigned int reserved : 23;
    } reg;
} AAE_GLB_PART0_AAE_NS_OFFLINE1_TO_IOMCU_O_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aae_ns_offline1_to_iomcu_msk : 9;
        unsigned int reserved : 23;
    } reg;
} AAE_GLB_PART0_AAE_NS_OFFLINE1_TO_IOMCU_MSK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aae_s_offline0_to_gic_o : 9;
        unsigned int reserved : 23;
    } reg;
} AAE_GLB_PART0_AAE_S_OFFLINE0_TO_GIC_O_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aae_s_offline0_to_gic_msk : 9;
        unsigned int reserved : 23;
    } reg;
} AAE_GLB_PART0_AAE_S_OFFLINE0_TO_GIC_MSK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aae_s_offline1_to_gic_o : 9;
        unsigned int reserved : 23;
    } reg;
} AAE_GLB_PART0_AAE_S_OFFLINE1_TO_GIC_O_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aae_s_offline1_to_gic_msk : 9;
        unsigned int reserved : 23;
    } reg;
} AAE_GLB_PART0_AAE_S_OFFLINE1_TO_GIC_MSK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aae_s_offline0_to_lpmcu_o : 9;
        unsigned int reserved : 23;
    } reg;
} AAE_GLB_PART0_AAE_S_OFFLINE0_TO_LPMCU_O_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aae_s_offline0_to_lpmcu_msk : 9;
        unsigned int reserved : 23;
    } reg;
} AAE_GLB_PART0_AAE_S_OFFLINE0_TO_LPMCU_MSK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aae_s_offline1_to_lpmcu_o : 9;
        unsigned int reserved : 23;
    } reg;
} AAE_GLB_PART0_AAE_S_OFFLINE1_TO_LPMCU_O_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aae_s_offline1_to_lpmcu_msk : 9;
        unsigned int reserved : 23;
    } reg;
} AAE_GLB_PART0_AAE_S_OFFLINE1_TO_LPMCU_MSK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_irq_not_safe_gic : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_GLB_PART0_DBG_IRQ_NS_GIC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_irq_safe_gic : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_GLB_PART0_DBG_IRQ_S_GIC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_irq_not_safe_iomcu : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_GLB_PART0_DBG_IRQ_NS_IOMCU_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_irq_safe_lpmcu : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_GLB_PART0_DBG_IRQ_S_LPMCU_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmd_ns_int_o : 9;
        unsigned int reserved : 23;
    } reg;
} AAE_GLB_PART0_CMD_NS_INT_O_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmd_ns_int_msk : 9;
        unsigned int reserved : 23;
    } reg;
} AAE_GLB_PART0_CMD_NS_INT_MSK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smart_dma0_ns_int_o : 14;
        unsigned int reserved : 18;
    } reg;
} AAE_GLB_PART0_SMART_DMA0_NS_INT_O_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int smart_dma0_ns_int_msk : 14;
        unsigned int reserved : 18;
    } reg;
} AAE_GLB_PART0_SMART_DMA0_NS_INT_MSK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rot_wdma_ns_int_o : 14;
        unsigned int reserved : 18;
    } reg;
} AAE_GLB_PART0_ROT_WDMA_NS_INT_O_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rot_wdma_ns_int_msk : 14;
        unsigned int reserved : 18;
    } reg;
} AAE_GLB_PART0_ROT_WDMA_NS_INT_MSK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dacc_ns_int_o : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_GLB_PART0_DACC_NS_INT_O_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dacc_ns_int_msk : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_GLB_PART0_DACC_NS_INT_MSK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dacc_s_int_o : 7;
        unsigned int reserved : 25;
    } reg;
} AAE_GLB_PART0_DACC_S_INT_O_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dacc_s_int_msk : 7;
        unsigned int reserved : 25;
    } reg;
} AAE_GLB_PART0_DACC_S_INT_MSK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ns_int_o : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_GLB_PART0_HDR_NS_INT_O_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ns_int_msk : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_GLB_PART0_HDR_NS_INT_MSK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_ctrl0_ns_int_o : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_GLB_PART0_PIPE_CTRL0_NS_INT_O_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_ctrl0_ns_int_msk : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_GLB_PART0_PIPE_CTRL0_NS_INT_MSK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_ctrl1_ns_int_o : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_GLB_PART0_PIPE_CTRL1_NS_INT_O_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_ctrl1_ns_int_msk : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_GLB_PART0_PIPE_CTRL1_NS_INT_MSK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_ctrl2_ns_int_o : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_GLB_PART0_PIPE_CTRL2_NS_INT_O_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_ctrl2_ns_int_msk : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_GLB_PART0_PIPE_CTRL2_NS_INT_MSK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_ctrl3_ns_int_o : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_GLB_PART0_PIPE_CTRL3_NS_INT_O_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_ctrl3_ns_int_msk : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_GLB_PART0_PIPE_CTRL3_NS_INT_MSK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_ip_sel : 8;
        unsigned int dbg_ip_vsync_sel : 3;
        unsigned int dbg_ip_en : 1;
        unsigned int reserved : 20;
    } reg;
} AAE_GLB_PART0_DBG_CTRL0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_ip_cycle_cnt0 : 16;
        unsigned int dbg_ip_cycle_cnt1 : 16;
    } reg;
} AAE_GLB_PART0_DBG_IP_CYCLE_CNT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_ip_state0 : 32;
    } reg;
} AAE_GLB_PART0_DBG_IP_STATE0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_ip_state1 : 32;
    } reg;
} AAE_GLB_PART0_DBG_IP_STATE1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_ov_ycnt_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_GLB_PART0_DBG_CTRL1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_ov_scene_id0_ycnt : 16;
        unsigned int dbg_ov_scene_id1_ycnt : 16;
    } reg;
} AAE_GLB_PART0_DBG_OV_YCNT0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_cfg_ctrl : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_GLB_PART0_DBG_CFG_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_cfg_state : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_GLB_PART0_DBG_CFG_STATE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_cfg_addr : 32;
    } reg;
} AAE_GLB_PART0_DBG_CFG_ADDR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_flush_en : 4;
        unsigned int reserved : 28;
    } reg;
} AAE_GLB_PART0_DBG_FLUSH_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_flush_clr : 4;
        unsigned int reserved : 28;
    } reg;
} AAE_GLB_PART0_DBG_FLUSH_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_flush_st : 4;
        unsigned int reserved : 28;
    } reg;
} AAE_GLB_PART0_DBG_FLUSH_ST_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_data5 : 32;
    } reg;
} AAE_GLB_PART0_DBG_RESV0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_data6 : 32;
    } reg;
} AAE_GLB_PART0_DBG_RESV1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_data7 : 32;
    } reg;
} AAE_GLB_PART0_DBG_RESV2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scene0_flush_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_GLB_PART0_FRAME_NUM_FLUSH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scene0_num : 32;
    } reg;
} AAE_GLB_PART0_SCENE0_FRAME_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int crc_cfg_en0 : 1;
        unsigned int crc_cfg_en1 : 1;
        unsigned int reserved : 30;
    } reg;
} AAE_GLB_PART0_CRC_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int crc_result0 : 32;
    } reg;
} AAE_GLB_PART0_CRC_RESULT0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int crc_frame_cnt0 : 32;
    } reg;
} AAE_GLB_PART0_CRC_FRAME_CNT0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int crc_result1 : 32;
    } reg;
} AAE_GLB_PART0_CRC_RESULT1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int crc_frame_cnt1 : 32;
    } reg;
} AAE_GLB_PART0_CRC_FRAME_CNT1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int crc_int0 : 1;
        unsigned int crc_int1 : 1;
        unsigned int reserved : 30;
    } reg;
} AAE_GLB_PART0_CRC_INT1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_ddrr_os_pld : 6;
        unsigned int dma_ddrr_os_hdr : 6;
        unsigned int dma_va_en : 1;
        unsigned int dma_dual_en : 1;
        unsigned int dma_srot_balance_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int dma_cmd_fifo_afull_thr : 3;
        unsigned int dma_rsv : 5;
        unsigned int reserved_1 : 8;
    } reg;
} AAE_GLB_PART0_SDMA_CTRL0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_hebc_raw_mode_en : 1;
        unsigned int dma_err_int_en : 1;
        unsigned int dma_check_en : 1;
        unsigned int reserved : 29;
    } reg;
} AAE_GLB_PART0_SDMA_CTRL1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_clkgate_off : 1;
        unsigned int dma_mem_sd_off : 1;
        unsigned int dma_auto_clk_gt_en : 1;
        unsigned int reserved : 29;
    } reg;
} AAE_GLB_PART0_SDMA_CTRL2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_dbg_reserved0 : 32;
    } reg;
} AAE_GLB_PART0_SDMA_DBG_RESERVED0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_dbg_out0 : 32;
    } reg;
} AAE_GLB_PART0_SDMA_DBG_OUT0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_dbg_out1 : 32;
    } reg;
} AAE_GLB_PART0_SDMA_DBG_OUT1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_dbg_monitor0 : 32;
    } reg;
} AAE_GLB_PART0_SDMA_DBG_MONITOR0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_dbg_monitor1 : 32;
    } reg;
} AAE_GLB_PART0_SDMA_DBG_MONITOR1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_dbg_monitor2 : 32;
    } reg;
} AAE_GLB_PART0_SDMA_DBG_MONITOR2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_dbg_monitor3 : 32;
    } reg;
} AAE_GLB_PART0_SDMA_DBG_MONITOR3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_dbg_monitor4 : 32;
    } reg;
} AAE_GLB_PART0_SDMA_DBG_MONITOR4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_dbg_monitor5 : 32;
    } reg;
} AAE_GLB_PART0_SDMA_DBG_MONITOR5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sdma_ctrl3 : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_GLB_PART0_SDMA_CTRL3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sdma_dbg_out2 : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_GLB_PART0_SDMA_DBG_OUT2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_dbg_reserved1 : 32;
    } reg;
} AAE_GLB_PART0_SDMA_DBG_RESERVED1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sdma_w_dbg0 : 32;
    } reg;
} AAE_GLB_PART0_SDMA_W_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sdma_w_dbg1 : 32;
    } reg;
} AAE_GLB_PART0_SDMA_W_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sdma_w_dbg2 : 32;
    } reg;
} AAE_GLB_PART0_SDMA_W_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sdma_w_dbg3 : 32;
    } reg;
} AAE_GLB_PART0_SDMA_W_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int srot_dbg_out0 : 32;
    } reg;
} AAE_GLB_PART0_SROT_DBG_OUT0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int srot_dbg_out1 : 32;
    } reg;
} AAE_GLB_PART0_SROT_DBG_OUT1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int srot_dbg_out2 : 32;
    } reg;
} AAE_GLB_PART0_SROT_DBG_OUT2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int srot_dbg_out3 : 32;
    } reg;
} AAE_GLB_PART0_SROT_DBG_OUT3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int srot_dbg_out4 : 32;
    } reg;
} AAE_GLB_PART0_SROT_DBG_OUT4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int srot_dbg_out5 : 32;
    } reg;
} AAE_GLB_PART0_SROT_DBG_OUT5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int srot_dbg_out6 : 32;
    } reg;
} AAE_GLB_PART0_SROT_DBG_OUT6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int srot_dbg_out7 : 32;
    } reg;
} AAE_GLB_PART0_SROT_DBG_OUT7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int srot_dbg_reserved : 32;
    } reg;
} AAE_GLB_PART0_SROT_DBG_RESERVED_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int srot_ctl0 : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_GLB_PART0_SROT_CTRL0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clk_aae_core_glb1_sel : 1;
        unsigned int clk_aae_core_scf2d0_sel : 1;
        unsigned int clk_aae_core_scf2d1_sel : 1;
        unsigned int clk_aae_core_blur_sel : 1;
        unsigned int clk_aae_core_blpp_sel : 1;
        unsigned int clk_aae_core_aihdr_sel : 1;
        unsigned int clk_aae_core_dgp1_sel : 1;
        unsigned int clk_aae_core_hiof_sel : 1;
        unsigned int clk_aae_core_warp_sel : 1;
        unsigned int reserved : 23;
    } reg;
} AAE_GLB_PART1_AAE_PART1_CLK_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clk_aae_core_glb1_en : 1;
        unsigned int clk_aae_core_scf2d0_en : 1;
        unsigned int clk_aae_core_scf2d1_en : 1;
        unsigned int clk_aae_core_blur_en : 1;
        unsigned int clk_aae_core_blpp_en : 1;
        unsigned int clk_aae_core_aihdr_en : 1;
        unsigned int clk_aae_core_dgp1_en : 1;
        unsigned int clk_aae_core_hiof_en : 1;
        unsigned int clk_aae_core_warp_en : 1;
        unsigned int reserved : 23;
    } reg;
} AAE_GLB_PART1_AAE_PART1_CLK_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmdlist_addr_h : 32;
    } reg;
} AAE_DM_CMDLIST_ADDR_H_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmdlist_addr0 : 32;
    } reg;
} AAE_DM_CMDLIST_ADDR0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmdlist_addr1 : 32;
    } reg;
} AAE_DM_CMDLIST_ADDR1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmdlist_addr2 : 32;
    } reg;
} AAE_DM_CMDLIST_ADDR2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmdlist_addr3 : 32;
    } reg;
} AAE_DM_CMDLIST_ADDR3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmdlist_addr4 : 32;
    } reg;
} AAE_DM_CMDLIST_ADDR4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmdlist_addr5 : 32;
    } reg;
} AAE_DM_CMDLIST_ADDR5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmdlist_addr6 : 32;
    } reg;
} AAE_DM_CMDLIST_ADDR6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmdlist_addr7 : 32;
    } reg;
} AAE_DM_CMDLIST_ADDR7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmdlist_addr8 : 32;
    } reg;
} AAE_DM_CMDLIST_ADDR8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmdlist_addr9 : 32;
    } reg;
} AAE_DM_CMDLIST_ADDR9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmdlist_addr10 : 32;
    } reg;
} AAE_DM_CMDLIST_ADDR10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmdlist_addr11 : 32;
    } reg;
} AAE_DM_CMDLIST_ADDR11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmdlist_addr12 : 32;
    } reg;
} AAE_DM_CMDLIST_ADDR12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmdlist_addr13 : 32;
    } reg;
} AAE_DM_CMDLIST_ADDR13_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cmdlist_addr14 : 32;
    } reg;
} AAE_DM_CMDLIST_ADDR14_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aihdr_number : 8;
        unsigned int hdr_number : 8;
        unsigned int blpp_number : 8;
        unsigned int srot_number : 8;
    } reg;
} AAE_DM_SROT_NUMBER_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cld_number : 8;
        unsigned int scl_number : 8;
        unsigned int blur_number : 8;
        unsigned int hiof_number : 8;
    } reg;
} AAE_DM_HIOF_NUMBER_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int warp_number : 8;
        unsigned int wdma_number : 8;
        unsigned int wdfc_number : 8;
        unsigned int layer_number : 8;
    } reg;
} AAE_DM_LAYER_NUMBER_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_input_img_height : 16;
        unsigned int hdr_input_img_width : 16;
    } reg;
} AAE_DM_HDR_INPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_output_img_height : 16;
        unsigned int hdr_output_img_width : 16;
    } reg;
} AAE_DM_HDR_OUTPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_layer_id : 8;
        unsigned int hdr_order0 : 8;
        unsigned int hdr_sel : 8;
        unsigned int hdr_input_fmt : 8;
    } reg;
} AAE_DM_HDR_INPUT_FMT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_output_fmt : 8;
        unsigned int hdr_reserved : 24;
    } reg;
} AAE_DM_HDR_RESERVED_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blpp_input_img_height : 16;
        unsigned int blpp_input_img_width : 16;
    } reg;
} AAE_DM_BLPP_INPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blpp_output_img_height : 16;
        unsigned int blpp_output_img_width : 16;
    } reg;
} AAE_DM_BLPP_OUTPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blpp_layer_id : 8;
        unsigned int blpp_order0 : 8;
        unsigned int blpp_sel : 8;
        unsigned int blpp_input_fmt : 8;
    } reg;
} AAE_DM_BLPP_INPUT_FMT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blpp_output_fmt : 8;
        unsigned int blpp_reserved : 24;
    } reg;
} AAE_DM_BLPP_OUTPUT_FMT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cld0_input_img_height : 16;
        unsigned int cld0_input_img_width : 16;
    } reg;
} AAE_DM_CLD0_INPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cld0_output_img_height : 16;
        unsigned int cld0_output_img_width : 16;
    } reg;
} AAE_DM_CLD0_OUTPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cld0_layer_id : 8;
        unsigned int cld0_order0 : 8;
        unsigned int cld0_sel : 8;
        unsigned int cld0_input_fmt : 8;
    } reg;
} AAE_DM_CLD0_INPUT_FMT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cld0_output_fmt : 8;
        unsigned int cld0_reserved : 24;
    } reg;
} AAE_DM_CLD0_OUTPUT_FMT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cld1_input_img_height : 16;
        unsigned int cld1_input_img_width : 16;
    } reg;
} AAE_DM_CLD1_INPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cld1_output_img_height : 16;
        unsigned int cld1_output_img_width : 16;
    } reg;
} AAE_DM_CLD1_OUTPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cld1_layer_id : 8;
        unsigned int cld1_order0 : 8;
        unsigned int cld1_sel : 8;
        unsigned int cld1_input_fmt : 8;
    } reg;
} AAE_DM_CLD1_INPUT_FMT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cld1_output_fmt : 8;
        unsigned int cld1_reserved : 24;
    } reg;
} AAE_DM_CLD1_OUTPUT_FMT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aihdr_input_img_height : 16;
        unsigned int aihdr_input_img_width : 16;
    } reg;
} AAE_DM_AIHDR_INPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aihdr_output_img_height : 16;
        unsigned int aihdr_output_img_width : 16;
    } reg;
} AAE_DM_AIHDR_OUTPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aihdr_layer_id : 8;
        unsigned int aihdr_order0 : 8;
        unsigned int aihdr_sel : 8;
        unsigned int aihdr_input_fmt : 8;
    } reg;
} AAE_DM_AIHDR_INPUT_FMT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aihdr_output_fmt : 8;
        unsigned int aihdr_grid_layer_id : 8;
        unsigned int aihdr_reserved : 16;
    } reg;
} AAE_DM_AIHDR_RESERVED_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scl0_input_img_height : 16;
        unsigned int scl0_input_img_width : 16;
    } reg;
} AAE_DM_SCL0_INPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scl0_output_img_height : 16;
        unsigned int scl0_output_img_width : 16;
    } reg;
} AAE_DM_SCL0_OUTPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scl0_layer_id : 8;
        unsigned int scl0_order0 : 8;
        unsigned int scl0_sel : 8;
        unsigned int scl0_type : 8;
    } reg;
} AAE_DM_SCL0_TYPE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scl0_pre_post_sel : 8;
        unsigned int scl0_input_fmt : 8;
        unsigned int scl0_output_fmt : 8;
        unsigned int scl0_threshold : 8;
    } reg;
} AAE_DM_SCL0_THRESHOLD_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scl1_input_img_height : 16;
        unsigned int scl1_input_img_width : 16;
    } reg;
} AAE_DM_SCL1_INPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scl1_output_img_height : 16;
        unsigned int scl1_output_img_width : 16;
    } reg;
} AAE_DM_SCL1_OUTPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scl1_layer_id : 8;
        unsigned int scl1_order0 : 8;
        unsigned int scl1_sel : 8;
        unsigned int scl1_type : 8;
    } reg;
} AAE_DM_SCL1_TYPE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scl1_pre_post_sel : 8;
        unsigned int scl1_input_fmt : 8;
        unsigned int scl1_output_fmt : 8;
        unsigned int scl1_threshold : 8;
    } reg;
} AAE_DM_SCL1_THRESHOLD_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scl2_input_img_height : 16;
        unsigned int scl2_input_img_width : 16;
    } reg;
} AAE_DM_SCL2_INPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scl2_output_img_height : 16;
        unsigned int scl2_output_img_width : 16;
    } reg;
} AAE_DM_SCL2_OUTPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scl2_layer_id : 8;
        unsigned int scl2_order0 : 8;
        unsigned int scl2_sel : 8;
        unsigned int scl2_type : 8;
    } reg;
} AAE_DM_SCL2_TYPE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scl2_pre_post_sel : 8;
        unsigned int scl2_input_fmt : 8;
        unsigned int scl2_output_fmt : 8;
        unsigned int scl2_threshold : 8;
    } reg;
} AAE_DM_SCL2_THRESHOLD_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scl3_input_img_height : 16;
        unsigned int scl3_input_img_width : 16;
    } reg;
} AAE_DM_SCL3_INPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scl3_output_img_height : 16;
        unsigned int scl3_output_img_width : 16;
    } reg;
} AAE_DM_SCL3_OUTPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scl3_layer_id : 8;
        unsigned int scl3_order0 : 8;
        unsigned int scl3_sel : 8;
        unsigned int scl3_type : 8;
    } reg;
} AAE_DM_SCL3_TYPE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scl3_pre_post_sel : 8;
        unsigned int scl3_input_fmt : 8;
        unsigned int scl3_output_fmt : 8;
        unsigned int scl3_threshold : 8;
    } reg;
} AAE_DM_SCL3_THRESHOLD_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scl4_input_img_height : 16;
        unsigned int scl4_input_img_width : 16;
    } reg;
} AAE_DM_SCL4_INPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scl4_output_img_height : 16;
        unsigned int scl4_output_img_width : 16;
    } reg;
} AAE_DM_SCL4_OUTPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scl4_layer_id : 8;
        unsigned int scl4_order0 : 8;
        unsigned int scl4_sel : 8;
        unsigned int scl4_type : 8;
    } reg;
} AAE_DM_SCL4_TYPE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scl4_pre_post_sel : 8;
        unsigned int scl4_input_fmt : 8;
        unsigned int scl4_output_fmt : 8;
        unsigned int scl4_threshold : 8;
    } reg;
} AAE_DM_SCL4_THRESHOLD_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blur_input_img_height : 16;
        unsigned int blur_input_img_width : 16;
    } reg;
} AAE_DM_BLUR_INPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blur_output_img_height : 16;
        unsigned int blur_output_img_width : 16;
    } reg;
} AAE_DM_BLUR_OUTPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blur_layer_id : 8;
        unsigned int blur_order0 : 8;
        unsigned int blur_sel : 8;
        unsigned int blur_input_fmt : 8;
    } reg;
} AAE_DM_BLUR_INPUT_FMT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blur_output_fmt : 8;
        unsigned int blur_reserved : 24;
    } reg;
} AAE_DM_BLUR_RESERVED_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int warp_input_img_height : 16;
        unsigned int warp_input_img_width : 16;
    } reg;
} AAE_DM_WARP_INPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int warp_output_img_height : 16;
        unsigned int warp_output_img_width : 16;
    } reg;
} AAE_DM_WARP_OUTPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int warp_layer_id : 8;
        unsigned int warp_order0 : 8;
        unsigned int warp_sel : 8;
        unsigned int warp_input_fmt : 8;
    } reg;
} AAE_DM_WARP_INPUT_FMT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int warp_output_fmt : 8;
        unsigned int warp_reserved : 24;
    } reg;
} AAE_DM_WARP_RESERVED_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hiof_input_img_height : 16;
        unsigned int hiof_input_img_width : 16;
    } reg;
} AAE_DM_HIOF_INPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hiof_output_img_height : 16;
        unsigned int hiof_output_img_width : 16;
    } reg;
} AAE_DM_HIOF_OUTPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hiof_cur_layer_id : 8;
        unsigned int hiof_order0 : 8;
        unsigned int hiof_sel : 8;
        unsigned int hiof_input_fmt : 8;
    } reg;
} AAE_DM_HIOF_INPUT_FMT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hiof_output_fmt : 8;
        unsigned int hiof_ref_layer_id : 8;
        unsigned int hiof_mv_layer_id : 8;
        unsigned int hiof_reserved : 8;
    } reg;
} AAE_DM_HIOF_RESERVED_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdfc_input_img_height : 16;
        unsigned int wdfc_input_img_width : 16;
    } reg;
} AAE_DM_WDFC_INPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdfc_output_img_height : 16;
        unsigned int wdfc_output_img_width : 16;
    } reg;
} AAE_DM_WDFC_OUTPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdfc_layer_id : 8;
        unsigned int wdfc_order0 : 8;
        unsigned int wdfc_sel : 8;
        unsigned int wdfc_input_fmt : 8;
    } reg;
} AAE_DM_WDFC_INPUT_FMT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdfc_output_fmt : 8;
        unsigned int wdfc_reserved : 24;
    } reg;
} AAE_DM_WDFC_RESERVED_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wch_input_img_height : 16;
        unsigned int wch_input_img_width : 16;
    } reg;
} AAE_DM_WCH_INPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wch_input_img_strx : 16;
        unsigned int wch_input_img_stry : 16;
    } reg;
} AAE_DM_WCH_INPUT_IMG_STRY_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wch_input_fmt : 8;
        unsigned int wch_reserved_0 : 16;
        unsigned int wch_sel : 8;
    } reg;
} AAE_DM_WCH_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wch_reserved_1 : 32;
    } reg;
} AAE_DM_WCH_RESERVED_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int itf_input_img_height : 16;
        unsigned int itf_input_img_width : 16;
    } reg;
} AAE_DM_ITF_INPUT_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int itf_input_fmt : 8;
        unsigned int itf_reserved_0 : 16;
        unsigned int itf_sel : 8;
    } reg;
} AAE_DM_ITF_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int itf_reserved_1 : 32;
    } reg;
} AAE_DM_ITF_RESERVED_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int itf_reserved_2 : 32;
    } reg;
} AAE_DM_ITF_RESERVED_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov_img_height : 16;
        unsigned int ov_img_width : 16;
    } reg;
} AAE_DM_OV_IMG_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov_blayer_startx : 16;
        unsigned int ov_blayer_endx : 16;
    } reg;
} AAE_DM_OV_BLAYER_ENDX_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov_blayer_starty : 16;
        unsigned int ov_blayer_endy : 16;
    } reg;
} AAE_DM_OV_BLAYER_ENDY_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov_bg_color_rgb : 32;
    } reg;
} AAE_DM_OV_BG_COLOR_RGB_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov_bg_color_cfg : 16;
        unsigned int ov_sel : 8;
        unsigned int ov_order0 : 8;
    } reg;
} AAE_DM_OV_ORDER0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov_order1 : 8;
        unsigned int ov_reserved_0 : 24;
    } reg;
} AAE_DM_OV_RESERVED_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scene_mode : 8;
        unsigned int scene_reserved : 24;
    } reg;
} AAE_DM_SCENE_MODE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov_reserved_2 : 32;
    } reg;
} AAE_DM_OV_RESERVED_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_width : 16;
        unsigned int layer_height : 16;
    } reg;
} AAE_DM_LAYER_HEIGHT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_mask_x0 : 16;
        unsigned int layer_mask_y0 : 16;
    } reg;
} AAE_DM_LAYER_MASK_Y0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_mask_x1 : 16;
        unsigned int layer_mask_y1 : 16;
    } reg;
} AAE_DM_LAYER_MASK_Y1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_mask_en : 8;
        unsigned int layer_dma_fmt : 8;
        unsigned int layer_fbc_type : 8;
        unsigned int layer_rot_en : 8;
    } reg;
} AAE_DM_LAYER_ROT_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_id : 8;
        unsigned int layer_stretch_en : 8;
        unsigned int layer_scramble_mode : 2;
        unsigned int layer_tag_mode_en : 1;
        unsigned int layer_yuv_trans : 1;
        unsigned int reserved : 4;
        unsigned int layer_sblk_type : 8;
    } reg;
} AAE_DM_LAYER_SBLK_TYPE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_stretch0_line : 8;
        unsigned int layer_stretch1_line : 8;
        unsigned int layer_stretch2_line : 8;
        unsigned int layer_stretch3_line : 8;
    } reg;
} AAE_DM_LAYER_STRETCH3_LINE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_start_addr0_h : 8;
        unsigned int layer_start_addr1_h : 8;
        unsigned int layer_start_addr2_h : 8;
        unsigned int layer_start_addr3_h : 8;
    } reg;
} AAE_DM_LAYER_START_ADDR3_H_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_start_addr0_l : 32;
    } reg;
} AAE_DM_LAYER_START_ADDR0_L_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_start_addr1_l : 32;
    } reg;
} AAE_DM_LAYER_START_ADDR1_L_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_start_addr2_l : 32;
    } reg;
} AAE_DM_LAYER_START_ADDR2_L_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_start_addr3_l : 32;
    } reg;
} AAE_DM_LAYER_START_ADDR3_L_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_stride0 : 32;
    } reg;
} AAE_DM_LAYER_STRIDE0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_stride1 : 32;
    } reg;
} AAE_DM_LAYER_STRIDE1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_stride2 : 32;
    } reg;
} AAE_DM_LAYER_STRIDE2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_stride3 : 16;
        unsigned int layer_rsv0 : 16;
    } reg;
} AAE_DM_LAYER_STRIDE3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_clip_right : 8;
        unsigned int layer_nxt_order : 8;
        unsigned int layer_top_crop : 8;
        unsigned int layer_bot_crop : 8;
    } reg;
} AAE_DM_LAYER_BOT_CROP_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_vmirr_en : 8;
        unsigned int layer_hmirr_en : 8;
        unsigned int layer_ov_pattern_type : 8;
        unsigned int layer_clip_left : 8;
    } reg;
} AAE_DM_LAYER_CLIP_LEFT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_ov_dfc_ax_swap : 1;
        unsigned int layer_ov_dfc_uv_swap : 1;
        unsigned int layer_ov_dfc_rb_swap : 1;
        unsigned int layer_ov_dfc_glb_alpha1 : 10;
        unsigned int layer_ov_dfc_glb_alpha0 : 10;
        unsigned int layer_ov_fmt : 6;
        unsigned int reserved : 2;
        unsigned int layer_ov_mitm_degamma_reg_sel : 1;
    } reg;
} AAE_DM_LAYER_OV_DFC_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_ov_startx : 16;
        unsigned int layer_ov_starty : 16;
    } reg;
} AAE_DM_LAYER_OV_STARTY_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_ov_endx : 16;
        unsigned int layer_ov_endy : 16;
    } reg;
} AAE_DM_LAYER_OV_ENDY_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_ov_module_en_rsv : 1;
        unsigned int layer_ov_csc_reg_sel : 4;
        unsigned int layer_ov_bitext_reg_reg_sel : 1;
        unsigned int layer_ov_mitm_en : 6;
        unsigned int layer_ov_csc_en : 1;
        unsigned int layer_ov_dfc_en : 1;
        unsigned int layer_ov_mitm_gamut_reg_sel : 1;
        unsigned int layer_ov_mitm_gama_reg_sel : 1;
        unsigned int layer_ov_pattern_a : 10;
        unsigned int layer_ov_enable : 1;
        unsigned int layer_rop_en : 1;
        unsigned int layer_trop_en : 1;
        unsigned int reserved : 3;
    } reg;
} AAE_DM_LAYER_OV_PATTERN_A_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_ov_pattern_rgb : 30;
        unsigned int reserved : 2;
    } reg;
} AAE_DM_LAYER_OV_PATTERN_RGB_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_ov_alpha_smode : 1;
        unsigned int layer_ov_fix_mode : 1;
        unsigned int layer_ov_dst_pmode : 1;
        unsigned int layer_ov_dst_gmode : 2;
        unsigned int layer_ov_dst_amode : 2;
        unsigned int layer_ov_src_mmode : 1;
        unsigned int layer_ov_src_pmode : 1;
        unsigned int layer_ov_src_gmode : 2;
        unsigned int layer_ov_src_amode : 2;
        unsigned int layer_ov_auto_nosrc : 1;
        unsigned int layer_ov_src_cfg : 1;
        unsigned int layer_ov_trop_code : 4;
        unsigned int layer_ov_rop_code : 8;
        unsigned int layer_clip_en : 1;
        unsigned int layer_bitext_en : 3;
        unsigned int reserved : 1;
    } reg;
} AAE_DM_LAYER_OV_MODE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_ov_dst_global_alpha : 10;
        unsigned int layer_ov_src_global_alpha : 10;
        unsigned int layer_ov_alpha_offdst : 2;
        unsigned int layer_ov_alpha_offsrc : 1;
        unsigned int layer_ov_alpha : 9;
    } reg;
} AAE_DM_LAYER_OV_ALPHA_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dgp_clk_sel : 32;
    } reg;
} AAE_DGP0_DGP_CLK_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dgp_clk_en : 32;
    } reg;
} AAE_DGP0_DGP_CLK_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_enable : 1;
        unsigned int hdr_scene_id : 4;
        unsigned int hdr_layer_id : 5;
        unsigned int hdr_start_order : 1;
        unsigned int hdr_next_order : 4;
        unsigned int hdr_end_order : 1;
        unsigned int hdr_pre_order : 4;
        unsigned int hdr_layer_id_1 : 5;
        unsigned int hdr_layer_id_2 : 5;
        unsigned int reserved : 2;
    } reg;
} AAE_DGP0_HDR_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dgp1_enable : 1;
        unsigned int dgp1_scene_id : 4;
        unsigned int dgp1_layer_id : 5;
        unsigned int dgp1_start_order : 1;
        unsigned int dgp1_next_order : 4;
        unsigned int dgp1_end_order : 1;
        unsigned int dgp1_pre_order : 4;
        unsigned int dgp1_layer_id_1 : 5;
        unsigned int dgp1_layer_id_2 : 5;
        unsigned int reserved : 2;
    } reg;
} AAE_DGP0_DGP1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arsr1_enable : 1;
        unsigned int arsr1_scene_id : 4;
        unsigned int arsr1_layer_id : 5;
        unsigned int arsr1_start_order : 1;
        unsigned int arsr1_next_order : 4;
        unsigned int arsr1_end_order : 1;
        unsigned int arsr1_pre_order : 4;
        unsigned int arsr1_layer_id_1 : 5;
        unsigned int arsr1_layer_id_2 : 5;
        unsigned int reserved : 2;
    } reg;
} AAE_DGP0_ARSR1_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vscf0_enable : 1;
        unsigned int vscf0_scene_id : 4;
        unsigned int vscf0_layer_id : 5;
        unsigned int vscf0_start_order : 1;
        unsigned int vscf0_next_order : 4;
        unsigned int vscf0_end_order : 1;
        unsigned int vscf0_pre_order : 4;
        unsigned int vscf0_layer_id_1 : 5;
        unsigned int vscf0_layer_id_2 : 5;
        unsigned int reserved : 2;
    } reg;
} AAE_DGP0_VSCF0_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cld_enable : 1;
        unsigned int cld_scene_id : 4;
        unsigned int cld_layer_id : 5;
        unsigned int cld_start_order : 1;
        unsigned int cld_next_order : 4;
        unsigned int cld_end_order : 1;
        unsigned int cld_pre_order : 4;
        unsigned int cld_layer_id_1 : 5;
        unsigned int cld_layer_id_2 : 5;
        unsigned int reserved : 2;
    } reg;
} AAE_DGP0_CLD_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov_enable : 1;
        unsigned int ov_scene_id : 4;
        unsigned int ov_layer_id : 5;
        unsigned int ov_start_order : 1;
        unsigned int ov_next_order : 4;
        unsigned int ov_end_order : 1;
        unsigned int ov_pre_order : 4;
        unsigned int ov_layer_id_1 : 5;
        unsigned int ov_layer_id_2 : 5;
        unsigned int reserved : 2;
    } reg;
} AAE_DGP0_OV_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wdfc_enable : 1;
        unsigned int wdfc_scene_id : 4;
        unsigned int wdfc_layer_id : 5;
        unsigned int wdfc_start_order : 1;
        unsigned int wdfc_next_order : 4;
        unsigned int wdfc_end_order : 1;
        unsigned int wdfc_pre_order : 4;
        unsigned int wdfc_layer_id_1 : 5;
        unsigned int wdfc_layer_id_2 : 5;
        unsigned int reserved : 2;
    } reg;
} AAE_DGP0_WDFC_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int default_layer_id : 8;
        unsigned int reserved : 24;
    } reg;
} AAE_DGP0_DEFAULT_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int info_os_thr : 8;
        unsigned int data_os_thr : 8;
        unsigned int os_en : 1;
        unsigned int reserved : 15;
    } reg;
} AAE_DGP0_OS_THR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_ov_start_y_s0 : 13;
        unsigned int reserved_0 : 3;
        unsigned int layer_ov_end_y_s0 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} AAE_DGP0_LAYER_OV_Y_S0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_dim_flag_s0 : 16;
        unsigned int pixel_layer_num_s0 : 5;
        unsigned int reserved : 10;
        unsigned int ov_pattern_en_s0 : 1;
    } reg;
} AAE_DGP0_DIM_FLAG_REG_S0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_ov_start_y_s1 : 13;
        unsigned int reserved_0 : 3;
        unsigned int layer_ov_end_y_s1 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} AAE_DGP0_LAYER_OV_Y_S1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_dim_flag_s1 : 16;
        unsigned int pixel_layer_num_s1 : 5;
        unsigned int reserved : 10;
        unsigned int ov_pattern_en_s1 : 1;
    } reg;
} AAE_DGP0_DIM_FLAG_REG_S1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int info_rdy_need_dbg_st0 : 32;
    } reg;
} AAE_DGP0_INFO_RDY_NEED_DBG_ST0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int info_rdy_need_dbg_st1 : 32;
    } reg;
} AAE_DGP0_INFO_RDY_NEED_DBG_ST1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int info_line_id_dbg_s0 : 13;
        unsigned int reserved_0 : 3;
        unsigned int info_line_id_dbg_s1 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} AAE_DGP0_INFO_LINE_ID_DBG_S01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int info_line_id_dbg_s2 : 13;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 13;
        unsigned int reserved_2 : 3;
    } reg;
} AAE_DGP0_INFO_LINE_ID_DBG_S23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int info_timeout_int : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_DGP0_INFO_TIMEOUT_INT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int info_timeout_int_mask : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_DGP0_INFO_TIMEOUT_INT_MASK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int info_timeout_thr : 32;
    } reg;
} AAE_DGP0_INFO_TIMEOUT_THR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_clr : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_DGP0_DBG_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_pst_info_cnt : 16;
        unsigned int dbg_pre_info_cnt : 16;
    } reg;
} AAE_DGP0_DBG_INFO_CNT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_pst_data_cnt : 16;
        unsigned int dbg_pre_data_cnt : 16;
    } reg;
} AAE_DGP0_DBG_DATA_CNT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dgp_clk_sel : 32;
    } reg;
} AAE_DGP1_DGP_CLK_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dgp_clk_en : 32;
    } reg;
} AAE_DGP1_DGP_CLK_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf2d0_enable : 1;
        unsigned int scf2d0_scene_id : 4;
        unsigned int scf2d0_layer_id : 5;
        unsigned int scf2d0_start_order : 1;
        unsigned int scf2d0_next_order : 4;
        unsigned int scf2d0_end_order : 1;
        unsigned int scf2d0_pre_order : 4;
        unsigned int scf2d0_layer_id_1 : 5;
        unsigned int scf2d0_layer_id_2 : 5;
        unsigned int reserved : 2;
    } reg;
} AAE_DGP1_SCF2D0_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blur_enable : 1;
        unsigned int blur_scene_id : 4;
        unsigned int blur_layer_id : 5;
        unsigned int blur_start_order : 1;
        unsigned int blur_next_order : 4;
        unsigned int blur_end_order : 1;
        unsigned int blur_pre_order : 4;
        unsigned int blur_layer_id_1 : 5;
        unsigned int blur_layer_id_2 : 5;
        unsigned int reserved : 2;
    } reg;
} AAE_DGP1_BLUR_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf2d1_enable : 1;
        unsigned int scf2d1_scene_id : 4;
        unsigned int scf2d1_layer_id : 5;
        unsigned int scf2d1_start_order : 1;
        unsigned int scf2d1_next_order : 4;
        unsigned int scf2d1_end_order : 1;
        unsigned int scf2d1_pre_order : 4;
        unsigned int scf2d1_layer_id_1 : 5;
        unsigned int scf2d1_layer_id_2 : 5;
        unsigned int reserved : 2;
    } reg;
} AAE_DGP1_SCF2D1_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blpp_enable : 1;
        unsigned int blpp_scene_id : 4;
        unsigned int blpp_layer_id : 5;
        unsigned int blpp_start_order : 1;
        unsigned int blpp_next_order : 4;
        unsigned int blpp_end_order : 1;
        unsigned int blpp_pre_order : 4;
        unsigned int blpp_layer_id_1 : 5;
        unsigned int blpp_layer_id_2 : 5;
        unsigned int reserved : 2;
    } reg;
} AAE_DGP1_BLPP_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aihdr_enable : 1;
        unsigned int aihdr_scene_id : 4;
        unsigned int aihdr_layer_id : 5;
        unsigned int aihdr_start_order : 1;
        unsigned int aihdr_next_order : 4;
        unsigned int aihdr_end_order : 1;
        unsigned int aihdr_pre_order : 4;
        unsigned int aihdr_layer_id_1 : 5;
        unsigned int aihdr_layer_id_2 : 5;
        unsigned int reserved : 2;
    } reg;
} AAE_DGP1_AIHDR_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int warp_enable : 1;
        unsigned int warp_scene_id : 4;
        unsigned int warp_layer_id : 5;
        unsigned int warp_start_order : 1;
        unsigned int warp_next_order : 4;
        unsigned int warp_end_order : 1;
        unsigned int warp_pre_order : 4;
        unsigned int warp_layer_id_1 : 5;
        unsigned int warp_layer_id_2 : 5;
        unsigned int reserved : 2;
    } reg;
} AAE_DGP1_WARP_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hiof_enable : 1;
        unsigned int hiof_scene_id : 4;
        unsigned int hiof_layer_id : 5;
        unsigned int hiof_start_order : 1;
        unsigned int hiof_next_order : 4;
        unsigned int hiof_end_order : 1;
        unsigned int hiof_pre_order : 4;
        unsigned int hiof_layer_id_1 : 5;
        unsigned int hiof_layer_id_2 : 5;
        unsigned int reserved : 2;
    } reg;
} AAE_DGP1_HIOF_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int info_os_thr : 8;
        unsigned int data_os_thr : 8;
        unsigned int os_en : 1;
        unsigned int reserved : 15;
    } reg;
} AAE_DGP1_OS_THR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int info_rdy_need_dbg_st0 : 32;
    } reg;
} AAE_DGP1_INFO_RDY_NEED_DBG_ST0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int info_rdy_need_dbg_st1 : 32;
    } reg;
} AAE_DGP1_INFO_RDY_NEED_DBG_ST1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int info_line_id_dbg_s0 : 13;
        unsigned int reserved_0 : 3;
        unsigned int info_line_id_dbg_s1 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} AAE_DGP1_INFO_LINE_ID_DBG_S01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int info_timeout_int : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_DGP1_INFO_TIMEOUT_INT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int info_timeout_int_mask : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_DGP1_INFO_TIMEOUT_INT_MASK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int info_timeout_thr : 32;
    } reg;
} AAE_DGP1_INFO_TIMEOUT_THR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_clr : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_DGP1_DBG_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_pst_info_cnt : 16;
        unsigned int dbg_pre_info_cnt : 16;
    } reg;
} AAE_DGP1_DBG_INFO_CNT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_pst_data_cnt : 16;
        unsigned int dbg_pre_data_cnt : 16;
    } reg;
} AAE_DGP1_DBG_DATA_CNT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer_height : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_INFO_SRC_SCENE0_LAYER_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_layer_height : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_INFO_SRC_SCENE1_LAYER_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn2_layer_height : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_INFO_SRC_SCENE2_LAYER_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn4_layer_height : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_INFO_SRC_SCENE4_LAYER_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_dbuf_depth : 8;
        unsigned int scn0_dbuf_level0 : 8;
        unsigned int scn0_dbuf_level1 : 8;
        unsigned int scn0_dbuf_level2 : 8;
    } reg;
} AAE_INFO_SRC_SCENE0_DBUF_DEPTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_dbuf_depth : 8;
        unsigned int scn1_dbuf_level0 : 8;
        unsigned int scn1_dbuf_level1 : 8;
        unsigned int scn1_dbuf_level2 : 8;
    } reg;
} AAE_INFO_SRC_SCENE1_DBUF_DEPTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn2_dbuf_depth : 8;
        unsigned int scn2_dbuf_level0 : 8;
        unsigned int scn2_dbuf_level1 : 8;
        unsigned int scn2_dbuf_level2 : 8;
    } reg;
} AAE_INFO_SRC_SCENE2_DBUF_DEPTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn4_dbuf_depth : 8;
        unsigned int scn4_dbuf_level0 : 8;
        unsigned int scn4_dbuf_level1 : 8;
        unsigned int scn4_dbuf_level2 : 8;
    } reg;
} AAE_INFO_SRC_SCENE4_DBUF_DEPTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_dbuf_depth_extra : 8;
        unsigned int reserved : 24;
    } reg;
} AAE_INFO_SRC_SCENE0_DBUF_DEPTH_EXTRA_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_dbuf_depth_extra : 8;
        unsigned int reserved : 24;
    } reg;
} AAE_INFO_SRC_SCENE1_DBUF_DEPTH_EXTRA_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn2_dbuf_depth_extra : 8;
        unsigned int reserved : 24;
    } reg;
} AAE_INFO_SRC_SCENE2_DBUF_DEPTH_EXTRA_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn4_dbuf_depth_extra : 8;
        unsigned int reserved : 24;
    } reg;
} AAE_INFO_SRC_SCENE4_DBUF_DEPTH_EXTRA_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_dbuf_qos0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int scn0_dbuf_qos1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int scn0_dbuf_qos2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int scn0_dbuf_qos3 : 3;
        unsigned int reserved_3 : 17;
    } reg;
} AAE_INFO_SRC_SCENE0_DBUF_QOS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_dbuf_qos0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int scn1_dbuf_qos1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int scn1_dbuf_qos2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int scn1_dbuf_qos3 : 3;
        unsigned int reserved_3 : 17;
    } reg;
} AAE_INFO_SRC_SCENE1_DBUF_QOS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn2_dbuf_qos0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int scn2_dbuf_qos1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int scn2_dbuf_qos2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int scn2_dbuf_qos3 : 3;
        unsigned int reserved_3 : 17;
    } reg;
} AAE_INFO_SRC_SCENE2_DBUF_QOS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn4_dbuf_qos0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int scn4_dbuf_qos1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int scn4_dbuf_qos2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int scn4_dbuf_qos3 : 3;
        unsigned int reserved_3 : 17;
    } reg;
} AAE_INFO_SRC_SCENE4_DBUF_QOS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_vact_depth_en : 1;
        unsigned int scn0_vact_qos_en : 1;
        unsigned int reserved : 30;
    } reg;
} AAE_INFO_SRC_SCENE0_DBUF_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_vact_depth_en : 1;
        unsigned int scn1_vact_qos_en : 1;
        unsigned int reserved : 30;
    } reg;
} AAE_INFO_SRC_SCENE1_DBUF_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn2_vact_depth_en : 1;
        unsigned int scn2_vact_qos_en : 1;
        unsigned int reserved : 30;
    } reg;
} AAE_INFO_SRC_SCENE2_DBUF_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn4_vact_depth_en : 1;
        unsigned int scn4_vact_qos_en : 1;
        unsigned int reserved : 30;
    } reg;
} AAE_INFO_SRC_SCENE4_DBUF_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_info_os : 8;
        unsigned int reserved : 24;
    } reg;
} AAE_INFO_SRC_SCENE0_PIPE_OS_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_info_os : 8;
        unsigned int reserved : 24;
    } reg;
} AAE_INFO_SRC_SCENE1_PIPE_OS_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn2_info_os : 8;
        unsigned int reserved : 24;
    } reg;
} AAE_INFO_SRC_SCENE2_PIPE_OS_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn4_info_os : 8;
        unsigned int reserved : 24;
    } reg;
} AAE_INFO_SRC_SCENE4_PIPE_OS_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_info_dbg0 : 32;
    } reg;
} AAE_INFO_SRC_SCENE0_INFO_DEBUG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_info_dbg0 : 32;
    } reg;
} AAE_INFO_SRC_SCENE1_INFO_DEBUG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn2_info_dbg0 : 32;
    } reg;
} AAE_INFO_SRC_SCENE2_INFO_DEBUG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn4_info_dbg0 : 32;
    } reg;
} AAE_INFO_SRC_SCENE4_INFO_DEBUG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_info_dbg1 : 32;
    } reg;
} AAE_INFO_SRC_SCENE0_INFO_DEBUG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_info_dbg1 : 32;
    } reg;
} AAE_INFO_SRC_SCENE1_INFO_DEBUG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn2_info_dbg1 : 32;
    } reg;
} AAE_INFO_SRC_SCENE2_INFO_DEBUG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn4_info_dbg1 : 32;
    } reg;
} AAE_INFO_SRC_SCENE4_INFO_DEBUG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_info_pause_num : 32;
    } reg;
} AAE_INFO_SRC_SCENE0_INFO_PAUSE_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_info_pause_num : 32;
    } reg;
} AAE_INFO_SRC_SCENE1_INFO_PAUSE_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn2_info_pause_num : 32;
    } reg;
} AAE_INFO_SRC_SCENE2_INFO_PAUSE_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn4_info_pause_num : 32;
    } reg;
} AAE_INFO_SRC_SCENE4_INFO_PAUSE_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_dbuf_vact_qos0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int scn0_dbuf_vact_qos1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int scn0_dbuf_vact_qos2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int scn0_dbuf_vact_qos3 : 3;
        unsigned int reserved_3 : 17;
    } reg;
} AAE_INFO_SRC_SCENE0_DBUF_VACT_QOS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_dbuf_vact_qos0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int scn1_dbuf_vact_qos1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int scn1_dbuf_vact_qos2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int scn1_dbuf_vact_qos3 : 3;
        unsigned int reserved_3 : 17;
    } reg;
} AAE_INFO_SRC_SCENE1_DBUF_VACT_QOS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn2_dbuf_vact_qos0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int scn2_dbuf_vact_qos1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int scn2_dbuf_vact_qos2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int scn2_dbuf_vact_qos3 : 3;
        unsigned int reserved_3 : 17;
    } reg;
} AAE_INFO_SRC_SCENE2_DBUF_VACT_QOS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn4_dbuf_vact_qos0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int scn4_dbuf_vact_qos1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int scn4_dbuf_vact_qos2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int scn4_dbuf_vact_qos3 : 3;
        unsigned int reserved_3 : 17;
    } reg;
} AAE_INFO_SRC_SCENE4_DBUF_VACT_QOS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_info_pause_en : 1;
        unsigned int scn0_dbuf_qos_sel : 1;
        unsigned int scn0_dbuf_vact_qos_sel : 1;
        unsigned int reserved : 29;
    } reg;
} AAE_INFO_SRC_SCENE0_INFO_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_info_pause_en : 1;
        unsigned int scn1_dbuf_qos_sel : 1;
        unsigned int scn1_dbuf_vact_qos_sel : 1;
        unsigned int reserved : 29;
    } reg;
} AAE_INFO_SRC_SCENE1_INFO_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn2_info_pause_en : 1;
        unsigned int scn2_dbuf_qos_sel : 1;
        unsigned int scn2_dbuf_vact_qos_sel : 1;
        unsigned int reserved : 29;
    } reg;
} AAE_INFO_SRC_SCENE2_INFO_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn4_info_pause_en : 1;
        unsigned int scn4_dbuf_qos_sel : 1;
        unsigned int scn4_dbuf_vact_qos_sel : 1;
        unsigned int reserved : 29;
    } reg;
} AAE_INFO_SRC_SCENE4_INFO_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_pre_info_os : 8;
        unsigned int scn0_line_num_per_lb : 4;
        unsigned int reserved : 20;
    } reg;
} AAE_INFO_SRC_SCENE0_PRE_OS_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_pre_info_os : 8;
        unsigned int scn1_line_num_per_lb : 4;
        unsigned int reserved : 20;
    } reg;
} AAE_INFO_SRC_SCENE1_PRE_OS_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn2_pre_info_os : 8;
        unsigned int scn2_line_num_per_lb : 4;
        unsigned int reserved : 20;
    } reg;
} AAE_INFO_SRC_SCENE2_PRE_OS_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn4_pre_info_os : 8;
        unsigned int scn4_line_num_per_lb : 4;
        unsigned int reserved : 20;
    } reg;
} AAE_INFO_SRC_SCENE4_PRE_OS_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_id : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_INFO_SRC_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clk_sel : 32;
    } reg;
} AAE_WR_CTRL_CLK_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clk_en : 32;
    } reg;
} AAE_WR_CTRL_CLK_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctrl_mode : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_WR_CTRL_CTRL_MODE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch0_layer_id : 32;
    } reg;
} AAE_WR_CTRL_CH0_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch1_layer_id : 32;
    } reg;
} AAE_WR_CTRL_CH1_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch2_layer_id : 32;
    } reg;
} AAE_WR_CTRL_CH2_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch3_layer_id : 32;
    } reg;
} AAE_WR_CTRL_CH3_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch4_layer_id : 32;
    } reg;
} AAE_WR_CTRL_CH4_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch5_layer_id : 32;
    } reg;
} AAE_WR_CTRL_CH5_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch6_layer_id : 32;
    } reg;
} AAE_WR_CTRL_CH6_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch7_layer_id : 32;
    } reg;
} AAE_WR_CTRL_CH7_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch8_layer_id : 32;
    } reg;
} AAE_WR_CTRL_CH8_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch9_layer_id : 32;
    } reg;
} AAE_WR_CTRL_CH9_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch10_layer_id : 32;
    } reg;
} AAE_WR_CTRL_CH10_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch11_layer_id : 32;
    } reg;
} AAE_WR_CTRL_CH11_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch0_dbg : 32;
    } reg;
} AAE_WR_CTRL_CH0_DBG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch1_dbg : 32;
    } reg;
} AAE_WR_CTRL_CH1_DBG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch2_dbg : 32;
    } reg;
} AAE_WR_CTRL_CH2_DBG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch3_dbg : 32;
    } reg;
} AAE_WR_CTRL_CH3_DBG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch4_dbg : 32;
    } reg;
} AAE_WR_CTRL_CH4_DBG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch5_dbg : 32;
    } reg;
} AAE_WR_CTRL_CH5_DBG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch6_dbg : 32;
    } reg;
} AAE_WR_CTRL_CH6_DBG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch7_dbg : 32;
    } reg;
} AAE_WR_CTRL_CH7_DBG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch8_dbg : 32;
    } reg;
} AAE_WR_CTRL_CH8_DBG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch9_dbg : 32;
    } reg;
} AAE_WR_CTRL_CH9_DBG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch10_dbg : 32;
    } reg;
} AAE_WR_CTRL_CH10_DBG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch11_dbg : 32;
    } reg;
} AAE_WR_CTRL_CH11_DBG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_clk_en : 8;
        unsigned int reserved : 24;
    } reg;
} AAE_PIPE_CTRL_PIPE_CLK_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_clk_sel : 8;
        unsigned int reserved : 24;
    } reg;
} AAE_PIPE_CTRL_PIPE_CLK_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_mem_dslp_en : 1;
        unsigned int pipe_mem_ctrl : 4;
        unsigned int reserved : 27;
    } reg;
} AAE_PIPE_CTRL_PIPE_MEM_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sdma_auto_ctrl_en : 1;
        unsigned int ov_auto_ctrl_en : 1;
        unsigned int reserved : 30;
    } reg;
} AAE_PIPE_CTRL_SOUR_AUTO_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mst_check_en : 1;
        unsigned int scn_check_sel : 4;
        unsigned int reserved : 27;
    } reg;
} AAE_PIPE_CTRL_DEBUG_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_idle_disp_en : 1;
        unsigned int post_idle_disp_en : 1;
        unsigned int ov_idle_disp_en : 1;
        unsigned int reserved : 29;
    } reg;
} AAE_PIPE_CTRL_IDLE_DISP_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_lb_num_wr : 8;
        unsigned int scn0_lb_num_rd : 8;
        unsigned int reserved : 16;
    } reg;
} AAE_PIPE_CTRL_PIPE_SCN0_FLUX_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_lb_num_wr : 8;
        unsigned int scn1_lb_num_rd : 8;
        unsigned int reserved : 16;
    } reg;
} AAE_PIPE_CTRL_PIPE_SCN1_FLUX_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn2_lb_num_wr : 8;
        unsigned int scn2_lb_num_rd : 8;
        unsigned int reserved : 16;
    } reg;
} AAE_PIPE_CTRL_PIPE_SCN2_FLUX_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn4_lb_num_wr : 8;
        unsigned int scn4_lb_num_rd : 8;
        unsigned int reserved : 16;
    } reg;
} AAE_PIPE_CTRL_PIPE_SCN4_FLUX_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dcpt_state : 4;
        unsigned int reserved : 28;
    } reg;
} AAE_PIPE_CTRL_PIPE_DCPT_STATE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int uvup_use_state : 1;
        unsigned int cld0_use_state : 1;
        unsigned int hdr_use_state : 1;
        unsigned int vscf0_use_state : 1;
        unsigned int vscf1_use_state : 1;
        unsigned int arsr1_use_state : 1;
        unsigned int pre_bps_use_state : 1;
        unsigned int lut0_use_state : 1;
        unsigned int lut1_use_state : 1;
        unsigned int lut2_use_state : 1;
        unsigned int idle_use_state : 1;
        unsigned int dpp0_use_state : 1;
        unsigned int dpp1_use_state : 1;
        unsigned int dsc0_use_state : 1;
        unsigned int post_bps_use_state : 1;
        unsigned int itf0_use_state : 1;
        unsigned int itf1_use_state : 1;
        unsigned int itf2_use_state : 1;
        unsigned int wch1_use_state : 1;
        unsigned int reserved : 13;
    } reg;
} AAE_PIPE_CTRL_PIPE_USE_STATE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int uvup_chk_state : 1;
        unsigned int cld0_chk_state : 1;
        unsigned int hdr_chk_state : 1;
        unsigned int vscf0_chk_state : 1;
        unsigned int vscf1_chk_state : 1;
        unsigned int arsr1_chk_state : 1;
        unsigned int pre_bps_chk_state : 1;
        unsigned int lut0_chk_state : 1;
        unsigned int lut1_chk_state : 1;
        unsigned int lut2_chk_state : 1;
        unsigned int idle_chk_state : 1;
        unsigned int dpp0_chk_state : 1;
        unsigned int dpp1_chk_state : 1;
        unsigned int dsc0_chk_state : 1;
        unsigned int post_bps_chk_state : 1;
        unsigned int itf0_chk_state : 1;
        unsigned int itf1_chk_state : 1;
        unsigned int itf2_chk_state : 1;
        unsigned int wch1_chk_state : 1;
        unsigned int reserved : 13;
    } reg;
} AAE_PIPE_CTRL_PIPE_PRE_CHECK_STATE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_scn_cur_mst : 6;
        unsigned int pipe_scn_dst_mst : 6;
        unsigned int pipe_scn_rf_fmt : 4;
        unsigned int pipe_scn_idx_num : 6;
        unsigned int pipe_scn_pln_num : 2;
        unsigned int pipe_scn_run_idx : 7;
        unsigned int pipe_scn_rw_flag : 1;
    } reg;
} AAE_PIPE_CTRL_PIPE_SCN_STATE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int pipe_dbg_wb_sel : 8;
        unsigned int reserved_1 : 20;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out0 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out1 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out2 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out3 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out4 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out5 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out6 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out7 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out8 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out9 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out10 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out11 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out12 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out13 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG13_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out14 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG14_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out15 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG15_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out16 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG16_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out17 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG17_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out18 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG18_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out19 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG19_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out20 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG20_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out21 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG21_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out22 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG22_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out23 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out24 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG24_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out25 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG25_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out26 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG26_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out27 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG27_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out28 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG28_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_dbg_out29 : 32;
    } reg;
} AAE_PIPE_CTRL_PIPE_DBG29_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sdma_fifo_afull_thr : 4;
        unsigned int pre_fifo_afull_thr : 8;
        unsigned int ov_fifo_afull_thr : 7;
        unsigned int post_fifo_afull_thr : 7;
        unsigned int itf_fifo_afull_thr : 4;
        unsigned int reserved : 2;
    } reg;
} AAE_PIPE_CTRL_FIFO_AFULL_THR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int run_req_irq_mask : 1;
        unsigned int idx_req_irq_mask : 1;
        unsigned int reserved : 30;
    } reg;
} AAE_PIPE_CTRL_RUN_IDX_REQ_IRQ_MASK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int run_req_time_thr : 32;
    } reg;
} AAE_PIPE_CTRL_RUN_REQ_TIME_THR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int idx_req_time_thr : 32;
    } reg;
} AAE_PIPE_CTRL_IDX_REQ_TIME_THR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_rd_shadow : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_PIPE_CTRL_RD_SHADOW_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_default : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_PIPE_CTRL_REG_DEFAULT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int bitext_reg_ini_cfg_en : 1;
        unsigned int reserved_3 : 28;
    } reg;
} AAE_RD_CTRL_BITEXT_CTL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_0 : 32;
    } reg;
} AAE_RD_CTRL_BITEXT_REG_INI0_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_1 : 32;
    } reg;
} AAE_RD_CTRL_BITEXT_REG_INI0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_2 : 32;
    } reg;
} AAE_RD_CTRL_BITEXT_REG_INI0_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_3 : 31;
        unsigned int reserved : 1;
    } reg;
} AAE_RD_CTRL_BITEXT_REG_INI0_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_0 : 32;
    } reg;
} AAE_RD_CTRL_BITEXT_REG_INI1_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_1 : 32;
    } reg;
} AAE_RD_CTRL_BITEXT_REG_INI1_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_2 : 32;
    } reg;
} AAE_RD_CTRL_BITEXT_REG_INI1_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_3 : 31;
        unsigned int reserved : 1;
    } reg;
} AAE_RD_CTRL_BITEXT_REG_INI1_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_0 : 32;
    } reg;
} AAE_RD_CTRL_BITEXT_REG_INI2_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_1 : 32;
    } reg;
} AAE_RD_CTRL_BITEXT_REG_INI2_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_2 : 32;
    } reg;
} AAE_RD_CTRL_BITEXT_REG_INI2_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_3 : 31;
        unsigned int reserved : 1;
    } reg;
} AAE_RD_CTRL_BITEXT_REG_INI2_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_power_ctrl_c : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_RD_CTRL_BITEXT_POWER_CTRL_C_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_power_ctrl_shift : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_RD_CTRL_BITEXT_POWER_CTRL_SHIFT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_00 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_RD_CTRL_BITEXT_FILT_00_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_01 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_RD_CTRL_BITEXT_FILT_01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_02 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_RD_CTRL_BITEXT_FILT_02_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_10 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_RD_CTRL_BITEXT_FILT_10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_11 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_RD_CTRL_BITEXT_FILT_11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_12 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_RD_CTRL_BITEXT_FILT_12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_20 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_RD_CTRL_BITEXT_FILT_20_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_21 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_RD_CTRL_BITEXT_FILT_21_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_22 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_RD_CTRL_BITEXT_FILT_22_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_r0 : 32;
    } reg;
} AAE_RD_CTRL_BITEXT_THD_R0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_r1 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_RD_CTRL_BITEXT_THD_R1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_g0 : 32;
    } reg;
} AAE_RD_CTRL_BITEXT_THD_G0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_g1 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_RD_CTRL_BITEXT_THD_G1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_b0 : 32;
    } reg;
} AAE_RD_CTRL_BITEXT_THD_B0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_b1 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_RD_CTRL_BITEXT_THD_B1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} AAE_RD_CTRL_BITEXT_RESERVED0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} AAE_RD_CTRL_BITEXT_RESERVED1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer0_glb_alpha1 : 10;
        unsigned int reserved_0 : 2;
        unsigned int scn0_layer0_bitext_en : 1;
        unsigned int scn0_layer0_bitext_rgb_en : 1;
        unsigned int scn0_layer0_bitext_alpha_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int scn0_layer0_glb_alpha0 : 10;
        unsigned int reserved_2 : 6;
    } reg;
} AAE_RD_CTRL_S0L0_GLB_ALPHA01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer1_glb_alpha1 : 10;
        unsigned int reserved_0 : 2;
        unsigned int scn0_layer1_bitext_en : 1;
        unsigned int scn0_layer1_bitext_rgb_en : 1;
        unsigned int scn0_layer1_bitext_alpha_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int scn0_layer1_glb_alpha0 : 10;
        unsigned int reserved_2 : 6;
    } reg;
} AAE_RD_CTRL_S0L1_GLB_ALPHA01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer2_glb_alpha1 : 10;
        unsigned int reserved_0 : 2;
        unsigned int scn0_layer2_bitext_en : 1;
        unsigned int scn0_layer2_bitext_rgb_en : 1;
        unsigned int scn0_layer2_bitext_alpha_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int scn0_layer2_glb_alpha0 : 10;
        unsigned int reserved_2 : 6;
    } reg;
} AAE_RD_CTRL_S0L2_GLB_ALPHA01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer3_glb_alpha1 : 10;
        unsigned int reserved_0 : 2;
        unsigned int scn0_layer3_bitext_en : 1;
        unsigned int scn0_layer3_bitext_rgb_en : 1;
        unsigned int scn0_layer3_bitext_alpha_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int scn0_layer3_glb_alpha0 : 10;
        unsigned int reserved_2 : 6;
    } reg;
} AAE_RD_CTRL_S0L3_GLB_ALPHA01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer4_glb_alpha1 : 10;
        unsigned int reserved_0 : 2;
        unsigned int scn0_layer4_bitext_en : 1;
        unsigned int scn0_layer4_bitext_rgb_en : 1;
        unsigned int scn0_layer4_bitext_alpha_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int scn0_layer4_glb_alpha0 : 10;
        unsigned int reserved_2 : 6;
    } reg;
} AAE_RD_CTRL_S0L4_GLB_ALPHA01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer5_glb_alpha1 : 10;
        unsigned int reserved_0 : 2;
        unsigned int scn0_layer5_bitext_en : 1;
        unsigned int scn0_layer5_bitext_rgb_en : 1;
        unsigned int scn0_layer5_bitext_alpha_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int scn0_layer5_glb_alpha0 : 10;
        unsigned int reserved_2 : 6;
    } reg;
} AAE_RD_CTRL_S0L5_GLB_ALPHA01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer6_glb_alpha1 : 10;
        unsigned int reserved_0 : 2;
        unsigned int scn0_layer6_bitext_en : 1;
        unsigned int scn0_layer6_bitext_rgb_en : 1;
        unsigned int scn0_layer6_bitext_alpha_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int scn0_layer6_glb_alpha0 : 10;
        unsigned int reserved_2 : 6;
    } reg;
} AAE_RD_CTRL_S0L6_GLB_ALPHA01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer7_glb_alpha1 : 10;
        unsigned int reserved_0 : 2;
        unsigned int scn0_layer7_bitext_en : 1;
        unsigned int scn0_layer7_bitext_rgb_en : 1;
        unsigned int scn0_layer7_bitext_alpha_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int scn0_layer7_glb_alpha0 : 10;
        unsigned int reserved_2 : 6;
    } reg;
} AAE_RD_CTRL_S0L7_GLB_ALPHA01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer8_glb_alpha1 : 10;
        unsigned int reserved_0 : 2;
        unsigned int scn0_layer8_bitext_en : 1;
        unsigned int scn0_layer8_bitext_rgb_en : 1;
        unsigned int scn0_layer8_bitext_alpha_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int scn0_layer8_glb_alpha0 : 10;
        unsigned int reserved_2 : 6;
    } reg;
} AAE_RD_CTRL_S0L8_GLB_ALPHA01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer9_glb_alpha1 : 10;
        unsigned int reserved_0 : 2;
        unsigned int scn0_layer9_bitext_en : 1;
        unsigned int scn0_layer9_bitext_rgb_en : 1;
        unsigned int scn0_layer9_bitext_alpha_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int scn0_layer9_glb_alpha0 : 10;
        unsigned int reserved_2 : 6;
    } reg;
} AAE_RD_CTRL_S0L9_GLB_ALPHA01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer10_glb_alpha1 : 10;
        unsigned int reserved_0 : 2;
        unsigned int scn0_layer10_bitext_en : 1;
        unsigned int scn0_layer10_bitext_rgb_en : 1;
        unsigned int scn0_layer10_bitext_alpha_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int scn0_layer10_glb_alpha0 : 10;
        unsigned int reserved_2 : 6;
    } reg;
} AAE_RD_CTRL_S0L10_GLB_ALPHA01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer11_glb_alpha1 : 10;
        unsigned int reserved_0 : 2;
        unsigned int scn0_layer11_bitext_en : 1;
        unsigned int scn0_layer11_bitext_rgb_en : 1;
        unsigned int scn0_layer11_bitext_alpha_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int scn0_layer11_glb_alpha0 : 10;
        unsigned int reserved_2 : 6;
    } reg;
} AAE_RD_CTRL_S0L11_GLB_ALPHA01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer12_glb_alpha1 : 10;
        unsigned int reserved_0 : 2;
        unsigned int scn0_layer12_bitext_en : 1;
        unsigned int scn0_layer12_bitext_rgb_en : 1;
        unsigned int scn0_layer12_bitext_alpha_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int scn0_layer12_glb_alpha0 : 10;
        unsigned int reserved_2 : 6;
    } reg;
} AAE_RD_CTRL_S0L12_GLB_ALPHA01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer13_glb_alpha1 : 10;
        unsigned int reserved_0 : 2;
        unsigned int scn0_layer13_bitext_en : 1;
        unsigned int scn0_layer13_bitext_rgb_en : 1;
        unsigned int scn0_layer13_bitext_alpha_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int scn0_layer13_glb_alpha0 : 10;
        unsigned int reserved_2 : 6;
    } reg;
} AAE_RD_CTRL_S0L13_GLB_ALPHA01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer14_glb_alpha1 : 10;
        unsigned int reserved_0 : 2;
        unsigned int scn0_layer14_bitext_en : 1;
        unsigned int scn0_layer14_bitext_rgb_en : 1;
        unsigned int scn0_layer14_bitext_alpha_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int scn0_layer14_glb_alpha0 : 10;
        unsigned int reserved_2 : 6;
    } reg;
} AAE_RD_CTRL_S0L14_GLB_ALPHA01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer15_glb_alpha1 : 10;
        unsigned int reserved_0 : 2;
        unsigned int scn0_layer15_bitext_en : 1;
        unsigned int scn0_layer15_bitext_rgb_en : 1;
        unsigned int scn0_layer15_bitext_alpha_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int scn0_layer15_glb_alpha0 : 10;
        unsigned int reserved_2 : 6;
    } reg;
} AAE_RD_CTRL_S0L15_GLB_ALPHA01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer0_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int scn0_layer0_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RD_CTRL_S0L0_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer1_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int scn0_layer1_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RD_CTRL_S0L1_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer2_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int scn0_layer2_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RD_CTRL_S0L2_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer3_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int scn0_layer3_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RD_CTRL_S0L3_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer4_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int scn0_layer4_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RD_CTRL_S0L4_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer5_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int scn0_layer5_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RD_CTRL_S0L5_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer6_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int scn0_layer6_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RD_CTRL_S0L6_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer7_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int scn0_layer7_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RD_CTRL_S0L7_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer8_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int scn0_layer8_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RD_CTRL_S0L8_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer9_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int scn0_layer9_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RD_CTRL_S0L9_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer10_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int scn0_layer10_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RD_CTRL_S0L10_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer11_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int scn0_layer11_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RD_CTRL_S0L11_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer12_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int scn0_layer12_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RD_CTRL_S0L12_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer13_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int scn0_layer13_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RD_CTRL_S0L13_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer14_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int scn0_layer14_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RD_CTRL_S0L14_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_layer15_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int scn0_layer15_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RD_CTRL_S0L15_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_layer0_glb_alpha1 : 10;
        unsigned int reserved_0 : 2;
        unsigned int scn1_layer0_bitext_en : 1;
        unsigned int scn1_layer0_bitext_rgb_en : 1;
        unsigned int scn1_layer0_bitext_alpha_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int scn1_layer0_glb_alpha0 : 10;
        unsigned int reserved_2 : 6;
    } reg;
} AAE_RD_CTRL_S1L0_GLB_ALPHA01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_layer1_glb_alpha1 : 10;
        unsigned int reserved_0 : 2;
        unsigned int scn1_layer1_bitext_en : 1;
        unsigned int scn1_layer1_bitext_rgb_en : 1;
        unsigned int scn1_layer1_bitext_alpha_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int scn1_layer1_glb_alpha0 : 10;
        unsigned int reserved_2 : 6;
    } reg;
} AAE_RD_CTRL_S1L1_GLB_ALPHA01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_layer2_glb_alpha1 : 10;
        unsigned int reserved_0 : 2;
        unsigned int scn1_layer2_bitext_en : 1;
        unsigned int scn1_layer2_bitext_rgb_en : 1;
        unsigned int scn1_layer2_bitext_alpha_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int scn1_layer2_glb_alpha0 : 10;
        unsigned int reserved_2 : 6;
    } reg;
} AAE_RD_CTRL_S1L2_GLB_ALPHA01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_layer3_glb_alpha1 : 10;
        unsigned int reserved_0 : 2;
        unsigned int scn1_layer3_bitext_en : 1;
        unsigned int scn1_layer3_bitext_rgb_en : 1;
        unsigned int scn1_layer3_bitext_alpha_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int scn1_layer3_glb_alpha0 : 10;
        unsigned int reserved_2 : 6;
    } reg;
} AAE_RD_CTRL_S1L3_GLB_ALPHA01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_layer4_glb_alpha1 : 10;
        unsigned int reserved_0 : 2;
        unsigned int scn1_layer4_bitext_en : 1;
        unsigned int scn1_layer4_bitext_rgb_en : 1;
        unsigned int scn1_layer4_bitext_alpha_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int scn1_layer4_glb_alpha0 : 10;
        unsigned int reserved_2 : 6;
    } reg;
} AAE_RD_CTRL_S1L4_GLB_ALPHA01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_layer5_glb_alpha1 : 10;
        unsigned int reserved_0 : 2;
        unsigned int scn1_layer5_bitext_en : 1;
        unsigned int scn1_layer5_bitext_rgb_en : 1;
        unsigned int scn1_layer5_bitext_alpha_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int scn1_layer5_glb_alpha0 : 10;
        unsigned int reserved_2 : 6;
    } reg;
} AAE_RD_CTRL_S1L5_GLB_ALPHA01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_layer6_glb_alpha1 : 10;
        unsigned int reserved_0 : 2;
        unsigned int scn1_layer6_bitext_en : 1;
        unsigned int scn1_layer6_bitext_rgb_en : 1;
        unsigned int scn1_layer6_bitext_alpha_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int scn1_layer6_glb_alpha0 : 10;
        unsigned int reserved_2 : 6;
    } reg;
} AAE_RD_CTRL_S1L6_GLB_ALPHA01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_layer7_glb_alpha1 : 10;
        unsigned int reserved_0 : 2;
        unsigned int scn1_layer7_bitext_en : 1;
        unsigned int scn1_layer7_bitext_rgb_en : 1;
        unsigned int scn1_layer7_bitext_alpha_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int scn1_layer7_glb_alpha0 : 10;
        unsigned int reserved_2 : 6;
    } reg;
} AAE_RD_CTRL_S1L7_GLB_ALPHA01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_layer0_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int scn1_layer0_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RD_CTRL_S1L0_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_layer1_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int scn1_layer1_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RD_CTRL_S1L1_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_layer2_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int scn1_layer2_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RD_CTRL_S1L2_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_layer3_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int scn1_layer3_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RD_CTRL_S1L3_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_layer4_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int scn1_layer4_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RD_CTRL_S1L4_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_layer5_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int scn1_layer5_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RD_CTRL_S1L5_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_layer6_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int scn1_layer6_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RD_CTRL_S1L6_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_layer7_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int scn1_layer7_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RD_CTRL_S1L7_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn2_layer0_glb_alpha1 : 10;
        unsigned int reserved_0 : 2;
        unsigned int scn2_layer0_bitext_en : 1;
        unsigned int scn2_layer0_bitext_rgb_en : 1;
        unsigned int scn2_layer0_bitext_alpha_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int scn2_layer0_glb_alpha0 : 10;
        unsigned int reserved_2 : 6;
    } reg;
} AAE_RD_CTRL_S2L0_GLB_ALPHA01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn2_layer0_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int scn2_layer0_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RD_CTRL_S2L0_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn3_layer0_glb_alpha1 : 10;
        unsigned int reserved_0 : 2;
        unsigned int scn3_layer0_bitext_en : 1;
        unsigned int scn3_layer0_bitext_rgb_en : 1;
        unsigned int scn3_layer0_bitext_alpha_en : 1;
        unsigned int reserved_1 : 1;
        unsigned int scn3_layer0_glb_alpha0 : 10;
        unsigned int reserved_2 : 6;
    } reg;
} AAE_RD_CTRL_S3L0_GLB_ALPHA01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn3_layer0_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int scn3_layer0_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RD_CTRL_S3L0_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch0_clk_sel : 1;
        unsigned int ch1_clk_sel : 1;
        unsigned int ch2_clk_sel : 1;
        unsigned int ch3_clk_sel : 1;
        unsigned int ch4_clk_sel : 1;
        unsigned int ch5_clk_sel : 1;
        unsigned int ch6_clk_sel : 1;
        unsigned int ch7_clk_sel : 1;
        unsigned int ch8_clk_sel : 1;
        unsigned int ch9_clk_sel : 1;
        unsigned int ch10_clk_sel : 1;
        unsigned int ch11_clk_sel : 1;
        unsigned int ch12_clk_sel : 1;
        unsigned int ch13_clk_sel : 1;
        unsigned int ch14_clk_sel : 1;
        unsigned int ch15_clk_sel : 1;
        unsigned int ch16_clk_sel : 1;
        unsigned int reserved : 15;
    } reg;
} AAE_RD_CTRL_CLK_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch0_clk_en : 1;
        unsigned int ch1_clk_en : 1;
        unsigned int ch2_clk_en : 1;
        unsigned int ch3_clk_en : 1;
        unsigned int ch4_clk_en : 1;
        unsigned int ch5_clk_en : 1;
        unsigned int ch6_clk_en : 1;
        unsigned int ch7_clk_en : 1;
        unsigned int ch8_clk_en : 1;
        unsigned int ch9_clk_en : 1;
        unsigned int ch10_clk_en : 1;
        unsigned int ch11_clk_en : 1;
        unsigned int ch12_clk_en : 1;
        unsigned int ch13_clk_en : 1;
        unsigned int ch14_clk_en : 1;
        unsigned int ch15_clk_en : 1;
        unsigned int ch16_clk_en : 1;
        unsigned int reserved : 15;
    } reg;
} AAE_RD_CTRL_CLK_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pre_arsr1_ch_sel : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_RD_CTRL_ARSR1_CH_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} AAE_RD_CTRL_CLK_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch0_dbg0 : 32;
    } reg;
} AAE_RD_CTRL_CH0_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch0_dbg1 : 32;
    } reg;
} AAE_RD_CTRL_CH0_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch0_dbg2 : 32;
    } reg;
} AAE_RD_CTRL_CH0_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch0_dbg3 : 32;
    } reg;
} AAE_RD_CTRL_CH0_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch1_dbg0 : 32;
    } reg;
} AAE_RD_CTRL_CH1_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch1_dbg1 : 32;
    } reg;
} AAE_RD_CTRL_CH1_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch1_dbg2 : 32;
    } reg;
} AAE_RD_CTRL_CH1_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch1_dbg3 : 32;
    } reg;
} AAE_RD_CTRL_CH1_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch2_dbg0 : 32;
    } reg;
} AAE_RD_CTRL_CH2_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch2_dbg1 : 32;
    } reg;
} AAE_RD_CTRL_CH2_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch2_dbg2 : 32;
    } reg;
} AAE_RD_CTRL_CH2_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch2_dbg3 : 32;
    } reg;
} AAE_RD_CTRL_CH2_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch3_dbg0 : 32;
    } reg;
} AAE_RD_CTRL_CH3_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch3_dbg1 : 32;
    } reg;
} AAE_RD_CTRL_CH3_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch3_dbg2 : 32;
    } reg;
} AAE_RD_CTRL_CH3_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch3_dbg3 : 32;
    } reg;
} AAE_RD_CTRL_CH3_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch4_dbg0 : 32;
    } reg;
} AAE_RD_CTRL_CH4_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch4_dbg1 : 32;
    } reg;
} AAE_RD_CTRL_CH4_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch4_dbg2 : 32;
    } reg;
} AAE_RD_CTRL_CH4_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch4_dbg3 : 32;
    } reg;
} AAE_RD_CTRL_CH4_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch5_dbg0 : 32;
    } reg;
} AAE_RD_CTRL_CH5_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch5_dbg1 : 32;
    } reg;
} AAE_RD_CTRL_CH5_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch5_dbg2 : 32;
    } reg;
} AAE_RD_CTRL_CH5_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch5_dbg3 : 32;
    } reg;
} AAE_RD_CTRL_CH5_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch6_dbg0 : 32;
    } reg;
} AAE_RD_CTRL_CH6_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch6_dbg1 : 32;
    } reg;
} AAE_RD_CTRL_CH6_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch6_dbg2 : 32;
    } reg;
} AAE_RD_CTRL_CH6_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch6_dbg3 : 32;
    } reg;
} AAE_RD_CTRL_CH6_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch7_dbg0 : 32;
    } reg;
} AAE_RD_CTRL_CH7_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch7_dbg1 : 32;
    } reg;
} AAE_RD_CTRL_CH7_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch7_dbg2 : 32;
    } reg;
} AAE_RD_CTRL_CH7_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch7_dbg3 : 32;
    } reg;
} AAE_RD_CTRL_CH7_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch8_dbg0 : 32;
    } reg;
} AAE_RD_CTRL_CH8_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch8_dbg1 : 32;
    } reg;
} AAE_RD_CTRL_CH8_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch8_dbg2 : 32;
    } reg;
} AAE_RD_CTRL_CH8_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch8_dbg3 : 32;
    } reg;
} AAE_RD_CTRL_CH8_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch9_dbg0 : 32;
    } reg;
} AAE_RD_CTRL_CH9_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch9_dbg1 : 32;
    } reg;
} AAE_RD_CTRL_CH9_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch9_dbg2 : 32;
    } reg;
} AAE_RD_CTRL_CH9_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch9_dbg3 : 32;
    } reg;
} AAE_RD_CTRL_CH9_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch10_dbg0 : 32;
    } reg;
} AAE_RD_CTRL_CH10_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch10_dbg1 : 32;
    } reg;
} AAE_RD_CTRL_CH10_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch10_dbg2 : 32;
    } reg;
} AAE_RD_CTRL_CH10_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch10_dbg3 : 32;
    } reg;
} AAE_RD_CTRL_CH10_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch11_dbg0 : 32;
    } reg;
} AAE_RD_CTRL_CH11_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch11_dbg1 : 32;
    } reg;
} AAE_RD_CTRL_CH11_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch11_dbg2 : 32;
    } reg;
} AAE_RD_CTRL_CH11_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch11_dbg3 : 32;
    } reg;
} AAE_RD_CTRL_CH11_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch12_dbg0 : 32;
    } reg;
} AAE_RD_CTRL_CH12_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch12_dbg1 : 32;
    } reg;
} AAE_RD_CTRL_CH12_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch12_dbg2 : 32;
    } reg;
} AAE_RD_CTRL_CH12_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch12_dbg3 : 32;
    } reg;
} AAE_RD_CTRL_CH12_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch13_dbg0 : 32;
    } reg;
} AAE_RD_CTRL_CH13_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch13_dbg1 : 32;
    } reg;
} AAE_RD_CTRL_CH13_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch13_dbg2 : 32;
    } reg;
} AAE_RD_CTRL_CH13_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch13_dbg3 : 32;
    } reg;
} AAE_RD_CTRL_CH13_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch14_dbg0 : 32;
    } reg;
} AAE_RD_CTRL_CH14_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch14_dbg1 : 32;
    } reg;
} AAE_RD_CTRL_CH14_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch14_dbg2 : 32;
    } reg;
} AAE_RD_CTRL_CH14_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch14_dbg3 : 32;
    } reg;
} AAE_RD_CTRL_CH14_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch15_dbg0 : 32;
    } reg;
} AAE_RD_CTRL_CH15_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch15_dbg1 : 32;
    } reg;
} AAE_RD_CTRL_CH15_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch15_dbg2 : 32;
    } reg;
} AAE_RD_CTRL_CH15_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch15_dbg3 : 32;
    } reg;
} AAE_RD_CTRL_CH15_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch16_dbg0 : 32;
    } reg;
} AAE_RD_CTRL_CH16_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch16_dbg1 : 32;
    } reg;
} AAE_RD_CTRL_CH16_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch16_dbg2 : 32;
    } reg;
} AAE_RD_CTRL_CH16_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch16_dbg3 : 32;
    } reg;
} AAE_RD_CTRL_CH16_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nop_line_end_flag : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_RD_CTRL_NOP_LINE_END_FLAG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctrl_mode : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_RD_CTRL_CTRL_MODE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch0_layer_id : 32;
    } reg;
} AAE_RD_CTRL_CH0_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch1_layer_id : 32;
    } reg;
} AAE_RD_CTRL_CH1_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch2_layer_id : 32;
    } reg;
} AAE_RD_CTRL_CH2_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch3_layer_id : 32;
    } reg;
} AAE_RD_CTRL_CH3_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch4_layer_id : 32;
    } reg;
} AAE_RD_CTRL_CH4_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch5_layer_id : 32;
    } reg;
} AAE_RD_CTRL_CH5_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch6_layer_id : 32;
    } reg;
} AAE_RD_CTRL_CH6_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch7_layer_id : 32;
    } reg;
} AAE_RD_CTRL_CH7_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch8_layer_id : 32;
    } reg;
} AAE_RD_CTRL_CH8_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch9_layer_id : 32;
    } reg;
} AAE_RD_CTRL_CH9_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch10_layer_id : 32;
    } reg;
} AAE_RD_CTRL_CH10_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch11_layer_id : 32;
    } reg;
} AAE_RD_CTRL_CH11_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch12_layer_id : 32;
    } reg;
} AAE_RD_CTRL_CH12_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch13_layer_id : 32;
    } reg;
} AAE_RD_CTRL_CH13_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch14_layer_id : 32;
    } reg;
} AAE_RD_CTRL_CH14_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch15_layer_id : 32;
    } reg;
} AAE_RD_CTRL_CH15_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch16_layer_id : 32;
    } reg;
} AAE_RD_CTRL_CH16_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_line_num : 32;
    } reg;
} AAE_RD_CTRL_SCN0_LINE_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_line_num : 32;
    } reg;
} AAE_RD_CTRL_SCN1_LINE_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn2_line_num : 32;
    } reg;
} AAE_RD_CTRL_SCN2_LINE_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn3_line_num : 32;
    } reg;
} AAE_RD_CTRL_SCN3_LINE_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_line_cnt_clear : 1;
        unsigned int scn1_line_cnt_clear : 1;
        unsigned int scn2_line_cnt_clear : 1;
        unsigned int scn3_line_cnt_clear : 1;
        unsigned int reserved : 28;
    } reg;
} AAE_RD_CTRL_LINE_CNT_CLEAR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn0_line_cnt : 32;
    } reg;
} AAE_RD_CTRL_SCN0_LINE_CNT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn1_line_cnt : 32;
    } reg;
} AAE_RD_CTRL_SCN1_LINE_CNT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn2_line_cnt : 32;
    } reg;
} AAE_RD_CTRL_SCN2_LINE_CNT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scn3_line_cnt : 32;
    } reg;
} AAE_RD_CTRL_SCN3_LINE_CNT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int s0_swap_alpha : 23;
        unsigned int reserved : 9;
    } reg;
} AAE_RDFC_PACK_WRAP_S0_SWAP_ALPHA_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int s1_swap_alpha : 23;
        unsigned int reserved : 9;
    } reg;
} AAE_RDFC_PACK_WRAP_S1_SWAP_ALPHA_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int s2_swap_alpha : 23;
        unsigned int reserved : 9;
    } reg;
} AAE_RDFC_PACK_WRAP_S2_SWAP_ALPHA_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int s4_swap_alpha : 23;
        unsigned int reserved : 9;
    } reg;
} AAE_RDFC_PACK_WRAP_S4_SWAP_ALPHA_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdfc_dbg0 : 32;
    } reg;
} AAE_RDFC_PACK_WRAP_RDFC_DEBUG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rdfc_dbg1 : 32;
    } reg;
} AAE_RDFC_PACK_WRAP_RDFC_DEBUG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_sel_0 : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_DBCU_SMARTDMA_0_AXI_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_sel_1 : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_DBCU_SMARTDMA_1_AXI_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_sel_2 : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_DBCU_SMARTDMA_2_AXI_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_sel_3 : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_DBCU_SMARTDMA_3_AXI_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_sel_4 : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_DBCU_WCH_0_AXI_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_sel_5 : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_DBCU_WCH_1_AXI_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_sel_6 : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_DBCU_WCH_2_AXI_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_sel_7 : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_DBCU_CMDLIST_AXI_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arcache0_addr_thrh : 32;
    } reg;
} AAE_DBCU_ARCACH0_ADDR_THRH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arcache0_addr_thrl : 32;
    } reg;
} AAE_DBCU_ARCACH0_ADDR_THRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arcache0_value0 : 4;
        unsigned int arcache0_addr_thrh_h4bit : 4;
        unsigned int reserved : 24;
    } reg;
} AAE_DBCU_ARCACH0_VALUE0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arcache0_value1 : 4;
        unsigned int arcache0_addr_thrl_h4bit : 4;
        unsigned int reserved : 24;
    } reg;
} AAE_DBCU_ARCACH0_VALUE1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arcache1_addr_thrh : 32;
    } reg;
} AAE_DBCU_ARCACH1_ADDR_THRH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arcache1_addr_thrl : 32;
    } reg;
} AAE_DBCU_ARCACH1_ADDR_THRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arcache1_value0 : 4;
        unsigned int arcache1_addr_thrh_h4bit : 4;
        unsigned int reserved : 24;
    } reg;
} AAE_DBCU_ARCACH1_VALUE0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arcache1_value1 : 4;
        unsigned int arcache1_addr_thrl_h4bit : 4;
        unsigned int reserved : 24;
    } reg;
} AAE_DBCU_ARCACH1_VALUE1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awcache0_addr_thrh : 32;
    } reg;
} AAE_DBCU_AWCACH0_ADDR_THRH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awcache0_addr_thrl : 32;
    } reg;
} AAE_DBCU_AWCACH0_ADDR_THRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awcache0_value0 : 4;
        unsigned int awcache0_addr_thrh_h4bit : 4;
        unsigned int reserved : 24;
    } reg;
} AAE_DBCU_AWCACH0_VALUE0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awcache0_value1 : 4;
        unsigned int awcache0_addr_thrl_h4bit : 4;
        unsigned int reserved : 24;
    } reg;
} AAE_DBCU_AWCACH0_VALUE1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arcache2_addr_thrh : 32;
    } reg;
} AAE_DBCU_ARCACH2_ADDR_THRH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arcache2_addr_thrl : 32;
    } reg;
} AAE_DBCU_ARCACH2_ADDR_THRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arcache2_value0 : 4;
        unsigned int arcache2_addr_thrh_h4bit : 4;
        unsigned int reserved : 24;
    } reg;
} AAE_DBCU_ARCACH2_VALUE0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arcache2_value1 : 4;
        unsigned int arcache2_addr_thrl_h4bit : 4;
        unsigned int reserved : 24;
    } reg;
} AAE_DBCU_ARCACH2_VALUE1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awcache2_addr_thrh : 32;
    } reg;
} AAE_DBCU_AWCACH2_ADDR_THRH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awcache2_addr_thrl : 32;
    } reg;
} AAE_DBCU_AWCACH2_ADDR_THRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awcache2_value0 : 4;
        unsigned int awcache2_addr_thrh_h4bit : 4;
        unsigned int reserved : 24;
    } reg;
} AAE_DBCU_AWCACH2_VALUE0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awcache2_value1 : 4;
        unsigned int awcache2_addr_thrl_h4bit : 4;
        unsigned int reserved : 24;
    } reg;
} AAE_DBCU_AWCACH2_VALUE1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arcache3_addr_thrh : 32;
    } reg;
} AAE_DBCU_ARCACH3_ADDR_THRH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arcache3_addr_thrl : 32;
    } reg;
} AAE_DBCU_ARCACH3_ADDR_THRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arcache3_value0 : 4;
        unsigned int arcache3_addr_thrh_h4bit : 4;
        unsigned int reserved : 24;
    } reg;
} AAE_DBCU_ARCACH3_VALUE0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arcache3_value1 : 4;
        unsigned int arcache3_addr_thrl_h4bit : 4;
        unsigned int reserved : 24;
    } reg;
} AAE_DBCU_ARCACH3_VALUE1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_0 : 8;
        unsigned int reserved : 24;
    } reg;
} AAE_DBCU_SMARTDMA_0_MID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_1 : 8;
        unsigned int reserved : 24;
    } reg;
} AAE_DBCU_SMARTDMA_1_MID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_2 : 8;
        unsigned int reserved : 24;
    } reg;
} AAE_DBCU_SMARTDMA_2_MID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_3 : 8;
        unsigned int reserved : 24;
    } reg;
} AAE_DBCU_SMARTDMA_3_MID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_4 : 8;
        unsigned int reserved : 24;
    } reg;
} AAE_DBCU_WCH_0_MID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_5 : 8;
        unsigned int reserved : 24;
    } reg;
} AAE_DBCU_WCH_1_MID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_6 : 8;
        unsigned int reserved : 24;
    } reg;
} AAE_DBCU_WCH_2_MID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mid_7 : 8;
        unsigned int reserved : 24;
    } reg;
} AAE_DBCU_CMDLIST_MID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_sid : 8;
        unsigned int ch_secsid : 1;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 6;
        unsigned int ch_ssidv : 1;
        unsigned int ch_sc_hint : 4;
        unsigned int ch_gid : 6;
        unsigned int ch_gid_en : 1;
        unsigned int ch_ptl_as_ful : 1;
        unsigned int reserved_2 : 2;
    } reg;
} AAE_DBCU_MMU0_ID_ATTR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbcu_mmuid : 32;
    } reg;
} AAE_DBCU_MMU1_ID_ATTR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_sid_ns : 8;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 6;
        unsigned int ch_ssidv_ns : 1;
        unsigned int ch_sc_hint_ns : 4;
        unsigned int ch_gid_ns : 6;
        unsigned int ch_gid_en_ns : 1;
        unsigned int ch_ptl_as_ful_ns : 1;
        unsigned int reserved_2 : 2;
    } reg;
} AAE_DBCU_MMU0_ID_ATTR_NS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mpam_ns : 4;
        unsigned int ch_ssid_ns : 12;
        unsigned int axi_domain_ns : 2;
        unsigned int reserved_ns : 14;
    } reg;
} AAE_DBCU_MMU1_ID_ATTR_NS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi2_rid_msk0 : 32;
    } reg;
} AAE_DBCU_AXI2_RID_MSK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi2_rid_msk1 : 32;
    } reg;
} AAE_DBCU_AXI2_RID_MSK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi2_wid_msk : 32;
    } reg;
} AAE_DBCU_AXI2_WID_MSK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi2_rd_qos_map : 8;
        unsigned int axi2_wr_qos_map : 8;
        unsigned int axi2_rd_prs_map : 8;
        unsigned int axi2_wr_prs_map : 8;
    } reg;
} AAE_DBCU_AXI2_R_QOS_MAP_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi3_rid_msk0 : 32;
    } reg;
} AAE_DBCU_AXI3_RID_MSK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi3_rid_msk1 : 32;
    } reg;
} AAE_DBCU_AXI3_RID_MSK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi3_rd_qos_map : 8;
        unsigned int reserved_0 : 8;
        unsigned int axi3_rd_prs_map : 8;
        unsigned int reserved_1 : 8;
    } reg;
} AAE_DBCU_AXI3_R_QOS_MAP_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi0_rid_msk0 : 32;
    } reg;
} AAE_DBCU_AXI0_RID_MSK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi0_rid_msk1 : 32;
    } reg;
} AAE_DBCU_AXI0_RID_MSK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi0_wid_msk : 32;
    } reg;
} AAE_DBCU_AXI0_WID_MSK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi0_rd_qos_map : 8;
        unsigned int axi0_wr_qos_map : 8;
        unsigned int axi0_rd_prs_map : 8;
        unsigned int axi0_wr_prs_map : 8;
    } reg;
} AAE_DBCU_AXI0_R_QOS_MAP_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi1_rid_msk0 : 32;
    } reg;
} AAE_DBCU_AXI1_RID_MSK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi1_rid_msk1 : 32;
    } reg;
} AAE_DBCU_AXI1_RID_MSK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi1_rd_qos_map : 8;
        unsigned int reserved_0 : 8;
        unsigned int axi1_rd_prs_map : 8;
        unsigned int reserved_1 : 8;
    } reg;
} AAE_DBCU_AXI1_R_QOS_MAP_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi0_bwc_en_high_r : 1;
        unsigned int axi0_saturation_high_r : 14;
        unsigned int axi0_bandwidth_high_r : 13;
        unsigned int reserved : 4;
    } reg;
} AAE_DBCU_AXI0_READ_FLUX_HIGH_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi0_bwc_en_low_r : 1;
        unsigned int axi0_saturation_low_r : 14;
        unsigned int axi0_bandwidth_low_r : 13;
        unsigned int reserved : 4;
    } reg;
} AAE_DBCU_AXI0_READ_FLUX_LOW_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi0_bwc_en_high_w : 1;
        unsigned int axi0_saturation_high_w : 14;
        unsigned int axi0_bandwidth_high_w : 13;
        unsigned int reserved : 4;
    } reg;
} AAE_DBCU_AXI0_WRITE_FLUX_HIGH_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi0_bwc_en_low_w : 1;
        unsigned int axi0_saturation_low_w : 14;
        unsigned int axi0_bandwidth_low_w : 13;
        unsigned int reserved : 4;
    } reg;
} AAE_DBCU_AXI0_WRITE_FLUX_LOW_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi1_bwc_en_high_r : 1;
        unsigned int axi1_saturation_high_r : 14;
        unsigned int axi1_bandwidth_high_r : 13;
        unsigned int reserved : 4;
    } reg;
} AAE_DBCU_AXI1_READ_FLUX_HIGH_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi1_bwc_en_low_r : 1;
        unsigned int axi1_saturation_low_r : 14;
        unsigned int axi1_bandwidth_low_r : 13;
        unsigned int reserved : 4;
    } reg;
} AAE_DBCU_AXI1_READ_FLUX_LOW_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi2_bwc_en_high_r : 1;
        unsigned int axi2_saturation_high_r : 14;
        unsigned int axi2_bandwidth_high_r : 13;
        unsigned int reserved : 4;
    } reg;
} AAE_DBCU_AXI2_READ_FLUX_HIGH_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi2_bwc_en_low_r : 1;
        unsigned int axi2_saturation_low_r : 14;
        unsigned int axi2_bandwidth_low_r : 13;
        unsigned int reserved : 4;
    } reg;
} AAE_DBCU_AXI2_READ_FLUX_LOW_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi2_bwc_en_high_w : 1;
        unsigned int axi2_saturation_high_w : 14;
        unsigned int axi2_bandwidth_high_w : 13;
        unsigned int reserved : 4;
    } reg;
} AAE_DBCU_AXI2_WRITE_FLUX_HIGH_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi2_bwc_en_low_w : 1;
        unsigned int axi2_saturation_low_w : 14;
        unsigned int axi2_bandwidth_low_w : 13;
        unsigned int reserved : 4;
    } reg;
} AAE_DBCU_AXI2_WRITE_FLUX_LOW_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi3_bwc_en_high_r : 1;
        unsigned int axi3_saturation_high_r : 14;
        unsigned int axi3_bandwidth_high_r : 13;
        unsigned int reserved : 4;
    } reg;
} AAE_DBCU_AXI3_READ_FLUX_HIGH_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi3_bwc_en_low_r : 1;
        unsigned int axi3_saturation_low_r : 14;
        unsigned int axi3_bandwidth_low_r : 13;
        unsigned int reserved : 4;
    } reg;
} AAE_DBCU_AXI3_READ_FLUX_LOW_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbcu_clk_sel_0 : 32;
    } reg;
} AAE_DBCU_CLK_SEL_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbcu_clk_sel_1 : 32;
    } reg;
} AAE_DBCU_CLK_SEL_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbcu_clk_en_0 : 32;
    } reg;
} AAE_DBCU_CLK_EN_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbcu_clk_en_1 : 32;
    } reg;
} AAE_DBCU_CLK_EN_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_ini : 32;
    } reg;
} AAE_DBCU_MONITOR_TIMER_INI_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int debug_base : 28;
    } reg;
} AAE_DBCU_DEBUG_BUF_BASE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flux_mode : 1;
        unsigned int addr_protect_en : 1;
        unsigned int reserved : 14;
        unsigned int debug_depth : 16;
    } reg;
} AAE_DBCU_DEBUG_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_rd_shadow : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_DBCU_AIF_SHADOW_READ_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int monitor_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_DBCU_MONITOR_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mon_axi_sel_w : 2;
        unsigned int mon_axi_sel_r : 2;
        unsigned int sample_mode : 2;
        unsigned int reserved_0 : 2;
        unsigned int sample_cmd_type : 2;
        unsigned int sample_mid : 9;
        unsigned int mon_sel : 3;
        unsigned int reserved_1 : 10;
    } reg;
} AAE_DBCU_MONITOR_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int window_end_num : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_DBCU_MONITOR_SAMPLE_MUN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int window_end_time : 32;
    } reg;
} AAE_DBCU_MONITOR_SAMPLE_TIME_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int window_end_flow : 32;
    } reg;
} AAE_DBCU_MONITOR_SAMPLE_FLOW_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi0_domain_r : 2;
        unsigned int axi0_domain_w : 2;
        unsigned int axi1_domain_r : 2;
        unsigned int axi2_domain_r : 2;
        unsigned int axi2_domain_w : 2;
        unsigned int axi3_domain_r : 2;
        unsigned int reserved : 20;
    } reg;
} AAE_DBCU_AXI_DOMAIN_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int online_scene0_reload : 1;
        unsigned int online_scene1_reload : 1;
        unsigned int online_scene2_reload : 1;
        unsigned int online_scene3_reload : 1;
        unsigned int offline_scene4_reload : 1;
        unsigned int offline_scene5_reload : 1;
        unsigned int offline_scene6_reload : 1;
        unsigned int reserved : 25;
    } reg;
} AAE_DBCU_RELOAD_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int real_cycle_w : 32;
    } reg;
} AAE_DBCU_MONITOR_WR_ST_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int window_cycle_w : 32;
    } reg;
} AAE_DBCU_MONITOR_WR_ST_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int writedata : 32;
    } reg;
} AAE_DBCU_MONITOR_WR_ST_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_cmd_cnt : 32;
    } reg;
} AAE_DBCU_MONITOR_WR_ST_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_done_cnt : 32;
    } reg;
} AAE_DBCU_MONITOR_WR_ST_4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wburst_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_DBCU_MONITOR_WR_ST_5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int avr_wrcycle_cnt : 32;
    } reg;
} AAE_DBCU_MONITOR_WR_ST_6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int min_wrcycle_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_DBCU_MONITOR_WR_ST_7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int max_wrcycle_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_DBCU_MONITOR_WR_ST_8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int real_cycle_r : 32;
    } reg;
} AAE_DBCU_MONITOR_RD_ST_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int window_cycle_r : 32;
    } reg;
} AAE_DBCU_MONITOR_RD_ST_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int readdata : 32;
    } reg;
} AAE_DBCU_MONITOR_RD_ST_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_cmd_cnt : 32;
    } reg;
} AAE_DBCU_MONITOR_RD_ST_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_done_cnt : 32;
    } reg;
} AAE_DBCU_MONITOR_RD_ST_4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rburst_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_DBCU_MONITOR_RD_ST_5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int avr_rdcycle_cnt : 32;
    } reg;
} AAE_DBCU_MONITOR_RD_ST_6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int min_rdcycle_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_DBCU_MONITOR_RD_ST_7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int max_rdcycle_cnt : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_DBCU_MONITOR_RD_ST_8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int channel_os_zero_r : 32;
    } reg;
} AAE_DBCU_MONITOR_OS_R0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int channel_os_r0 : 32;
    } reg;
} AAE_DBCU_MONITOR_OS_R1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int channel_os_r1 : 32;
    } reg;
} AAE_DBCU_MONITOR_OS_R2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} AAE_DBCU_MONITOR_OS_R3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_os_r : 32;
    } reg;
} AAE_DBCU_MONITOR_OS_R4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int channel_os_zero_w : 32;
    } reg;
} AAE_DBCU_MONITOR_OS_W0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int channel_os_w0 : 32;
    } reg;
} AAE_DBCU_MONITOR_OS_W1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} AAE_DBCU_MONITOR_OS_W2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_os_w : 32;
    } reg;
} AAE_DBCU_MONITOR_OS_W3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_0 : 32;
    } reg;
} AAE_DBCU_AIF_STAT_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_1 : 32;
    } reg;
} AAE_DBCU_AIF_STAT_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_2 : 32;
    } reg;
} AAE_DBCU_AIF_STAT_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_3 : 32;
    } reg;
} AAE_DBCU_AIF_STAT_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_4 : 32;
    } reg;
} AAE_DBCU_AIF_STAT_4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_5 : 32;
    } reg;
} AAE_DBCU_AIF_STAT_5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_6 : 32;
    } reg;
} AAE_DBCU_AIF_STAT_6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_7 : 32;
    } reg;
} AAE_DBCU_AIF_STAT_7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_8 : 32;
    } reg;
} AAE_DBCU_AIF_STAT_8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_9 : 32;
    } reg;
} AAE_DBCU_AIF_STAT_9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_10 : 32;
    } reg;
} AAE_DBCU_AIF_STAT_10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_11 : 32;
    } reg;
} AAE_DBCU_AIF_STAT_11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_12 : 32;
    } reg;
} AAE_DBCU_AIF_STAT_12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_13 : 32;
    } reg;
} AAE_DBCU_AIF_STAT_13_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_14 : 32;
    } reg;
} AAE_DBCU_AIF_STAT_14_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_stat_15 : 32;
    } reg;
} AAE_DBCU_AIF_STAT_15_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mif_rd_shadow : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_DBCU_MIF_SHADOW_READ_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aif_cmd_reload : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_DBCU_AIF_CMD_RELOAD_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pref_en_r0 : 1;
        unsigned int reserved_0 : 1;
        unsigned int pref_pg_en_r0 : 2;
        unsigned int reserved_1 : 28;
    } reg;
} AAE_DBCU_MIF_CTRL_SMARTDMA_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sub0_lead_num_r0 : 7;
        unsigned int sub1_lead_num_r0 : 7;
        unsigned int reserved : 18;
    } reg;
} AAE_DBCU_MIF_LEAD_SMARTDMA_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sub0_os_num_r0 : 8;
        unsigned int sub1_os_num_r0 : 8;
        unsigned int reserved : 16;
    } reg;
} AAE_DBCU_MIF_OS_SMARTDMA_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sub0_pref_cnt_r0 : 8;
        unsigned int sub1_pref_cnt_r0 : 8;
        unsigned int reserved : 16;
    } reg;
} AAE_DBCU_MIF_STAT_SMARTDMA_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pref_en_r1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int pref_pg_en_r1 : 2;
        unsigned int reserved_1 : 28;
    } reg;
} AAE_DBCU_MIF_CTRL_SMARTDMA_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sub0_lead_num_r1 : 7;
        unsigned int sub1_lead_num_r1 : 7;
        unsigned int reserved : 18;
    } reg;
} AAE_DBCU_MIF_LEAD_SMARTDMA_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sub0_os_num_r1 : 8;
        unsigned int sub1_os_num_r1 : 8;
        unsigned int reserved : 16;
    } reg;
} AAE_DBCU_MIF_OS_SMARTDMA_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sub0_pref_cnt_r1 : 8;
        unsigned int sub1_pref_cnt_r1 : 8;
        unsigned int reserved : 16;
    } reg;
} AAE_DBCU_MIF_STAT_SMARTDMA_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pref_en_r2 : 1;
        unsigned int reserved_0 : 1;
        unsigned int pref_pg_en_r2 : 2;
        unsigned int reserved_1 : 28;
    } reg;
} AAE_DBCU_MIF_CTRL_SMARTDMA_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sub0_lead_num_r2 : 7;
        unsigned int sub1_lead_num_r2 : 7;
        unsigned int reserved : 18;
    } reg;
} AAE_DBCU_MIF_LEAD_SMARTDMA_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sub0_os_num_r2 : 8;
        unsigned int sub1_os_num_r2 : 8;
        unsigned int reserved : 16;
    } reg;
} AAE_DBCU_MIF_OS_SMARTDMA_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sub0_pref_cnt_r2 : 8;
        unsigned int sub1_pref_cnt_r2 : 8;
        unsigned int reserved : 16;
    } reg;
} AAE_DBCU_MIF_STAT_SMARTDMA_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pref_en_r3 : 1;
        unsigned int reserved_0 : 1;
        unsigned int pref_pg_en_r3 : 2;
        unsigned int reserved_1 : 28;
    } reg;
} AAE_DBCU_MIF_CTRL_SMARTDMA_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sub0_lead_num_r3 : 7;
        unsigned int sub1_lead_num_r3 : 7;
        unsigned int reserved : 18;
    } reg;
} AAE_DBCU_MIF_LEAD_SMARTDMA_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sub0_os_num_r3 : 8;
        unsigned int sub1_os_num_r3 : 8;
        unsigned int reserved : 16;
    } reg;
} AAE_DBCU_MIF_OS_SMARTDMA_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sub0_pref_cnt_r3 : 8;
        unsigned int sub1_pref_cnt_r3 : 8;
        unsigned int reserved : 16;
    } reg;
} AAE_DBCU_MIF_STAT_SMARTDMA_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pref_en_w0 : 1;
        unsigned int pref_pg_en_w0 : 4;
        unsigned int reserved : 27;
    } reg;
} AAE_DBCU_MIF_CTRL_WCH0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sub0_lead_num_w0 : 7;
        unsigned int sub1_lead_num_w0 : 7;
        unsigned int sub2_lead_num_w0 : 7;
        unsigned int sub3_lead_num_w0 : 7;
        unsigned int reserved : 4;
    } reg;
} AAE_DBCU_MIF_LEAD_CTRL_WCH0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sub0_os_num_w0 : 8;
        unsigned int sub1_os_num_w0 : 8;
        unsigned int sub2_os_num_w0 : 8;
        unsigned int sub3_os_num_w0 : 8;
    } reg;
} AAE_DBCU_MIF_OS_CTRL_WCH0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sub0_pref_cnt_w0 : 8;
        unsigned int sub1_pref_cnt_w0 : 8;
        unsigned int sub2_pref_cnt_w0 : 8;
        unsigned int sub3_pref_cnt_w0 : 8;
    } reg;
} AAE_DBCU_MIF_STAT_WCH0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pref_en_w1 : 1;
        unsigned int pref_pg_en_w1 : 4;
        unsigned int reserved : 27;
    } reg;
} AAE_DBCU_MIF_CTRL_WCH1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sub0_lead_num_w1 : 7;
        unsigned int sub1_lead_num_w1 : 7;
        unsigned int sub2_lead_num_w1 : 7;
        unsigned int sub3_lead_num_w1 : 7;
        unsigned int reserved : 4;
    } reg;
} AAE_DBCU_MIF_LEAD_CTRL_WCH1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sub0_os_num_w1 : 8;
        unsigned int sub1_os_num_w1 : 8;
        unsigned int sub2_os_num_w1 : 8;
        unsigned int sub3_os_num_w1 : 8;
    } reg;
} AAE_DBCU_MIF_OS_CTRL_WCH1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sub0_pref_cnt_w1 : 8;
        unsigned int sub1_pref_cnt_w1 : 8;
        unsigned int sub2_pref_cnt_w1 : 8;
        unsigned int sub3_pref_cnt_w1 : 8;
    } reg;
} AAE_DBCU_MIF_STAT_WCH1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pref_en_w2 : 1;
        unsigned int pref_pg_en_w2 : 4;
        unsigned int reserved : 27;
    } reg;
} AAE_DBCU_MIF_CTRL_WCH2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sub0_lead_num_w2 : 7;
        unsigned int sub1_lead_num_w2 : 7;
        unsigned int sub2_lead_num_w2 : 7;
        unsigned int sub3_lead_num_w2 : 7;
        unsigned int reserved : 4;
    } reg;
} AAE_DBCU_MIF_LEAD_CTRL_WCH2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sub0_os_num_w2 : 8;
        unsigned int sub1_os_num_w2 : 8;
        unsigned int sub2_os_num_w2 : 8;
        unsigned int sub3_os_num_w2 : 8;
    } reg;
} AAE_DBCU_MIF_OS_CTRL_WCH2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sub0_pref_cnt_w2 : 8;
        unsigned int sub1_pref_cnt_w2 : 8;
        unsigned int sub2_pref_cnt_w2 : 8;
        unsigned int sub3_pref_cnt_w2 : 8;
    } reg;
} AAE_DBCU_MIF_STAT_WCH2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blk_rd_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_RD_BLK_CTRL_BLK_RD_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_blk_ctrl_dbg0 : 32;
    } reg;
} AAE_RD_BLK_CTRL_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_blk_ctrl_dbg1 : 32;
    } reg;
} AAE_RD_BLK_CTRL_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_blk_ctrl_dbg2 : 32;
    } reg;
} AAE_RD_BLK_CTRL_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_blk_ctrl_dbg3 : 32;
    } reg;
} AAE_RD_BLK_CTRL_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_blk_ctrl_dbg4 : 32;
    } reg;
} AAE_RD_BLK_CTRL_DBG4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_mode : 3;
        unsigned int dma_va_en : 1;
        unsigned int dma_rot_en : 1;
        unsigned int dma_hmirr_en : 1;
        unsigned int dma_vmirr_en : 1;
        unsigned int reserved : 25;
    } reg;
} AAE_ROT_WDMA_DMA_CTRL0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_pix_fmt : 6;
        unsigned int reserved_0 : 1;
        unsigned int dma_os : 6;
        unsigned int dma_threshold : 3;
        unsigned int dma_qos : 3;
        unsigned int reserved_1 : 13;
    } reg;
} AAE_ROT_WDMA_DMA_CTRL1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_img_width : 16;
        unsigned int dma_img_height : 16;
    } reg;
} AAE_ROT_WDMA_DMA_IMG_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_ptr0 : 32;
    } reg;
} AAE_ROT_WDMA_DMA_PTR0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_stride0 : 24;
        unsigned int reserved : 8;
    } reg;
} AAE_ROT_WDMA_DMA_STRIDE0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_ptr1 : 32;
    } reg;
} AAE_ROT_WDMA_DMA_PTR1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_stride1 : 24;
        unsigned int reserved : 8;
    } reg;
} AAE_ROT_WDMA_DMA_STRIDE1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_ptr2 : 32;
    } reg;
} AAE_ROT_WDMA_DMA_PTR2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_stride2 : 24;
        unsigned int reserved : 8;
    } reg;
} AAE_ROT_WDMA_DMA_STRIDE2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_ptr3 : 32;
    } reg;
} AAE_ROT_WDMA_DMA_PTR3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_stride3 : 24;
        unsigned int reserved : 8;
    } reg;
} AAE_ROT_WDMA_DMA_STRIDE3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_cmp_hdr_ptr_oft : 32;
    } reg;
} AAE_ROT_WDMA_DMA_CMP_HDR_PTR_OFT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_ch_segment : 16;
        unsigned int reserved_0 : 4;
        unsigned int dma_ch_segment_en : 1;
        unsigned int reserved_1 : 11;
    } reg;
} AAE_ROT_WDMA_DMA_CH_SEGMENT_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_cmp_yuv_trans : 1;
        unsigned int dma_cmp_tag_en : 1;
        unsigned int dma_cmp_raw_en : 1;
        unsigned int dma_cmp_spblk_compact_num : 5;
        unsigned int dma_cmp_spblk_layout : 2;
        unsigned int dma_cmp_spblk_layout_switch_en : 1;
        unsigned int dma_cmp_scramble_mode : 4;
        unsigned int reserved : 17;
    } reg;
} AAE_ROT_WDMA_DMA_CMP_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_cmp_pic_blks : 24;
        unsigned int reserved : 8;
    } reg;
} AAE_ROT_WDMA_DMA_CMP_PIC_BLKS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_cmp_mem_ctrl0 : 32;
    } reg;
} AAE_ROT_WDMA_DMA_CMP_MEM_CTRL0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_cmp_mem_ctrl1 : 32;
    } reg;
} AAE_ROT_WDMA_DMA_CMP_MEM_CTRL1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_cmp_reserved : 32;
    } reg;
} AAE_ROT_WDMA_DMA_CMP_RESEVED_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_cmp_info_out0 : 32;
    } reg;
} AAE_ROT_WDMA_DMA_CMP_INFO_OUT0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_cmp_info_out1 : 32;
    } reg;
} AAE_ROT_WDMA_DMA_CMP_INFO_OUT1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_intr : 8;
        unsigned int wch_intr : 8;
        unsigned int reserved : 16;
    } reg;
} AAE_ROT_WDMA_DMA_INTR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_rsv_in0 : 32;
    } reg;
} AAE_ROT_WDMA_DMA_RSV_IN0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_rsv_in1 : 32;
    } reg;
} AAE_ROT_WDMA_DMA_RSV_IN1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_rsv_in2 : 32;
    } reg;
} AAE_ROT_WDMA_DMA_RSV_IN2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_rsv_in3 : 32;
    } reg;
} AAE_ROT_WDMA_DMA_RSV_IN3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_monitor_out0 : 32;
    } reg;
} AAE_ROT_WDMA_DMA_MONITOR_OUT0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_monitor_out1 : 32;
    } reg;
} AAE_ROT_WDMA_DMA_MONITOR_OUT1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_monitor_out2 : 32;
    } reg;
} AAE_ROT_WDMA_DMA_MONITOR_OUT2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_monitor_out3 : 32;
    } reg;
} AAE_ROT_WDMA_DMA_MONITOR_OUT3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_monitor_out4 : 32;
    } reg;
} AAE_ROT_WDMA_DMA_MONITOR_OUT4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_monitor_out5 : 32;
    } reg;
} AAE_ROT_WDMA_DMA_MONITOR_OUT5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wlt_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_ROT_WDMA_WTL_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wlt_line_threshold0 : 16;
        unsigned int wlt_line_threshold1 : 16;
    } reg;
} AAE_ROT_WDMA_WLT_LINE_THRESHOLD1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wlt_line_threshold2 : 16;
        unsigned int wlt_line_threshold3 : 16;
    } reg;
} AAE_ROT_WDMA_WLT_LINE_THRESHOLD3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wlt_base_line_offset : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_ROT_WDMA_WLT_BASE_LINE_OFFSET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wlt_dma_addr : 32;
    } reg;
} AAE_ROT_WDMA_WLT_DMA_ADDR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wlt_dma_qos : 3;
        unsigned int reserved : 29;
    } reg;
} AAE_ROT_WDMA_WLT_DMA_QOS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wlt_y_line_num : 16;
        unsigned int wlt_c_line_num : 16;
    } reg;
} AAE_ROT_WDMA_WLT_C_LINE_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wlt_y_slice_num : 3;
        unsigned int wlt_c_slice_num : 3;
        unsigned int reserved : 26;
    } reg;
} AAE_ROT_WDMA_WLT_C_SLICE_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_default : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_ROT_WDMA_REG_DEFAULT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rwch_rd_shadow : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_ROT_WDMA_CH_RD_SHADOW_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_en : 1;
        unsigned int ch_version_sel : 1;
        unsigned int reserved_0 : 1;
        unsigned int ch_block_en : 1;
        unsigned int ch_last_block : 1;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 1;
        unsigned int ch_dmac_en : 1;
        unsigned int reserved_3 : 7;
        unsigned int reserved_4 : 16;
    } reg;
} AAE_ROT_WDMA_CH_CTL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_secu_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_ROT_WDMA_CH_SECU_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_sw_end_req : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_ROT_WDMA_CH_SW_END_REQ_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_clk_sel : 32;
    } reg;
} AAE_ROT_WDMA_CH_CLK_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_clk_en : 32;
    } reg;
} AAE_ROT_WDMA_CH_CLK_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_dbg0 : 32;
    } reg;
} AAE_ROT_WDMA_CH_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_dbg1 : 32;
    } reg;
} AAE_ROT_WDMA_CH_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_dbg2 : 32;
    } reg;
} AAE_ROT_WDMA_CH_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_dbg3 : 32;
    } reg;
} AAE_ROT_WDMA_CH_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_dbg4 : 32;
    } reg;
} AAE_ROT_WDMA_CH_DBG4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_dbg5 : 32;
    } reg;
} AAE_ROT_WDMA_CH_DBG5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int frm_end_wch_delay : 32;
    } reg;
} AAE_ROT_WDMA_FRM_END_WCH_DELAY_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wb_err_cycle_threshold : 30;
        unsigned int wb_err_ints_unmask : 1;
        unsigned int wb_err_bypass : 1;
    } reg;
} AAE_ROT_WDMA_WB_ERR_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_dbg6 : 32;
    } reg;
} AAE_ROT_WDMA_CH_DBG6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rot_first_lns_en : 1;
        unsigned int rot_first_lns : 5;
        unsigned int reserved : 26;
    } reg;
} AAE_ROT_WDMA_ROT_FIRST_LNS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rot_state : 32;
    } reg;
} AAE_ROT_WDMA_ROT_STATE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rot_mem_ctrl : 4;
        unsigned int rot_auto_lp_en : 1;
        unsigned int reserved : 27;
    } reg;
} AAE_ROT_WDMA_ROT_MEM_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rot_img_width : 13;
        unsigned int reserved_0 : 3;
        unsigned int rot_img_height : 13;
        unsigned int reserved_1 : 3;
    } reg;
} AAE_ROT_WDMA_ROT_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rot_yuv422_mode : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_ROT_WDMA_ROT_422_MODE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rot_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_ROT_WDMA_ROT_BYPASS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_debug_sel : 4;
        unsigned int reserved : 28;
    } reg;
} AAE_ROT_WDMA_CH_DEBUG_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_addr_ext0 : 4;
        unsigned int reserved : 28;
    } reg;
} AAE_ROT_WDMA_DMA_ADDR_EXT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_scene_id : 3;
        unsigned int reserved : 29;
    } reg;
} AAE_ROT_WDMA_REG_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_flush_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_ROT_WDMA_REG_CTRL_FLUSH_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_dbg : 32;
    } reg;
} AAE_ROT_WDMA_REG_CTRL_DEBUG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_state : 32;
    } reg;
} AAE_ROT_WDMA_REG_CTRL_STATE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_lb_debug0 : 32;
    } reg;
} AAE_ROT_WDMA_R_LB_DEBUG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_lb_debug1 : 32;
    } reg;
} AAE_ROT_WDMA_R_LB_DEBUG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_lb_debug2 : 32;
    } reg;
} AAE_ROT_WDMA_R_LB_DEBUG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_lb_debug3 : 32;
    } reg;
} AAE_ROT_WDMA_R_LB_DEBUG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_layer_id : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_ROT_WDMA_REG_CTRL_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rgb2y_input_height : 13;
        unsigned int reserved_0 : 3;
        unsigned int rgb2y_input_width : 13;
        unsigned int reserved_1 : 3;
    } reg;
} AAE_ROT_WDMA_RGB2Y_IMG_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rgb2yuv_p00 : 14;
        unsigned int reserved : 18;
    } reg;
} AAE_ROT_WDMA_RGB2Y_P00_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rgb2yuv_p01 : 14;
        unsigned int reserved : 18;
    } reg;
} AAE_ROT_WDMA_RGB2Y_P01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rgb2yuv_p02 : 14;
        unsigned int reserved : 18;
    } reg;
} AAE_ROT_WDMA_RGB2Y_P02_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rgb2yuv_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_ROT_WDMA_RGB2Y_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_ov0_top_clk_sel : 32;
    } reg;
} AAE_RCH_OV_RCH_OV0_TOP_CLK_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_ov0_top_clk_en : 32;
    } reg;
} AAE_RCH_OV_RCH_OV0_TOP_CLK_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_ov1_top_clk_sel : 32;
    } reg;
} AAE_RCH_OV_RCH_OV1_TOP_CLK_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_ov1_top_clk_en : 32;
    } reg;
} AAE_RCH_OV_RCH_OV1_TOP_CLK_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_ov2_top_clk_sel : 32;
    } reg;
} AAE_RCH_OV_RCH_OV2_TOP_CLK_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_ov2_top_clk_en : 32;
    } reg;
} AAE_RCH_OV_RCH_OV2_TOP_CLK_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_ov3_top_clk_sel : 32;
    } reg;
} AAE_RCH_OV_RCH_OV3_TOP_CLK_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_ov3_top_clk_en : 32;
    } reg;
} AAE_RCH_OV_RCH_OV3_TOP_CLK_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_ov_wrap_clk_sel : 32;
    } reg;
} AAE_RCH_OV_WRAP_CLK_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_ov_wrap_clk_en : 32;
    } reg;
} AAE_RCH_OV_WRAP_CLK_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_dbg0 : 32;
    } reg;
} AAE_RCH_OV_RCH_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_dbg1 : 32;
    } reg;
} AAE_RCH_OV_RCH_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_dbg2 : 32;
    } reg;
} AAE_RCH_OV_RCH_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_dbg3 : 32;
    } reg;
} AAE_RCH_OV_RCH_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_dbg4 : 32;
    } reg;
} AAE_RCH_OV_RCH_DBG4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_dbg5 : 32;
    } reg;
} AAE_RCH_OV_RCH_DBG5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_dbg6 : 32;
    } reg;
} AAE_RCH_OV_RCH_DBG6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_dbg7 : 32;
    } reg;
} AAE_RCH_OV_RCH_DBG7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_dbg8 : 32;
    } reg;
} AAE_RCH_OV_RCH_DBG8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_dbg9 : 32;
    } reg;
} AAE_RCH_OV_RCH_DBG9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_dbg10 : 32;
    } reg;
} AAE_RCH_OV_RCH_DBG10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_dbg11 : 32;
    } reg;
} AAE_RCH_OV_RCH_DBG11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov_mem_ctrl_0 : 4;
        unsigned int reserved : 28;
    } reg;
} AAE_RCH_OV_OV_MEM_CTRL_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov_mem_ctrl_1 : 4;
        unsigned int reserved : 28;
    } reg;
} AAE_RCH_OV_OV_MEM_CTRL_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov_mem_ctrl_2 : 4;
        unsigned int reserved : 28;
    } reg;
} AAE_RCH_OV_OV_MEM_CTRL_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov_mem_ctrl_3 : 4;
        unsigned int reserved : 28;
    } reg;
} AAE_RCH_OV_OV_MEM_CTRL_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_dbg12 : 32;
    } reg;
} AAE_RCH_OV_RCH_DBG12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_dbg13 : 32;
    } reg;
} AAE_RCH_OV_RCH_DBG13_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_dbg14 : 32;
    } reg;
} AAE_RCH_OV_RCH_DBG14_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_dbg15 : 32;
    } reg;
} AAE_RCH_OV_RCH_DBG15_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_dbg16 : 32;
    } reg;
} AAE_RCH_OV_RCH_DBG16_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_dbg17 : 32;
    } reg;
} AAE_RCH_OV_RCH_DBG17_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_dbg18 : 32;
    } reg;
} AAE_RCH_OV_RCH_DBG18_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rch_dbg19 : 32;
    } reg;
} AAE_RCH_OV_RCH_DBG19_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int bitext_reg_ini_cfg_en : 1;
        unsigned int reserved_3 : 28;
    } reg;
} AAE_RCH_OV_BITEXT_CTL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_0 : 32;
    } reg;
} AAE_RCH_OV_BITEXT_REG_INI0_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_1 : 32;
    } reg;
} AAE_RCH_OV_BITEXT_REG_INI0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_2 : 32;
    } reg;
} AAE_RCH_OV_BITEXT_REG_INI0_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_3 : 31;
        unsigned int reserved : 1;
    } reg;
} AAE_RCH_OV_BITEXT_REG_INI0_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_0 : 32;
    } reg;
} AAE_RCH_OV_BITEXT_REG_INI1_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_1 : 32;
    } reg;
} AAE_RCH_OV_BITEXT_REG_INI1_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_2 : 32;
    } reg;
} AAE_RCH_OV_BITEXT_REG_INI1_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_3 : 31;
        unsigned int reserved : 1;
    } reg;
} AAE_RCH_OV_BITEXT_REG_INI1_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_0 : 32;
    } reg;
} AAE_RCH_OV_BITEXT_REG_INI2_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_1 : 32;
    } reg;
} AAE_RCH_OV_BITEXT_REG_INI2_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_2 : 32;
    } reg;
} AAE_RCH_OV_BITEXT_REG_INI2_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_3 : 31;
        unsigned int reserved : 1;
    } reg;
} AAE_RCH_OV_BITEXT_REG_INI2_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_power_ctrl_c : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_RCH_OV_BITEXT_POWER_CTRL_C_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_power_ctrl_shift : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_RCH_OV_BITEXT_POWER_CTRL_SHIFT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_00 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_RCH_OV_BITEXT_FILT_00_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_01 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_RCH_OV_BITEXT_FILT_01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_02 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_RCH_OV_BITEXT_FILT_02_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_10 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_RCH_OV_BITEXT_FILT_10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_11 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_RCH_OV_BITEXT_FILT_11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_12 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_RCH_OV_BITEXT_FILT_12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_20 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_RCH_OV_BITEXT_FILT_20_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_21 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_RCH_OV_BITEXT_FILT_21_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_22 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_RCH_OV_BITEXT_FILT_22_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_r0 : 32;
    } reg;
} AAE_RCH_OV_BITEXT_THD_R0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_r1 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_RCH_OV_BITEXT_THD_R1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_g0 : 32;
    } reg;
} AAE_RCH_OV_BITEXT_THD_G0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_g1 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_RCH_OV_BITEXT_THD_G1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_b0 : 32;
    } reg;
} AAE_RCH_OV_BITEXT_THD_B0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_b1 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_RCH_OV_BITEXT_THD_B1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int dfc_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RCH_OV_DFC_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_dbg0 : 32;
    } reg;
} AAE_RCH_OV_BITEXT0_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_idc0 : 11;
        unsigned int reserved_0: 5;
        unsigned int csc_idc1 : 11;
        unsigned int reserved_1: 5;
    } reg;
} AAE_RCH_OV_CSC_IDC0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_idc2 : 11;
        unsigned int reserved : 21;
    } reg;
} AAE_RCH_OV_CSC_IDC2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_odc0 : 11;
        unsigned int reserved_0: 5;
        unsigned int csc_odc1 : 11;
        unsigned int reserved_1: 5;
    } reg;
} AAE_RCH_OV_CSC_ODC0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_odc2 : 11;
        unsigned int reserved : 21;
    } reg;
} AAE_RCH_OV_CSC_ODC2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p00 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_RCH_OV_CSC_P00_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p01 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_RCH_OV_CSC_P01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p02 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_RCH_OV_CSC_P02_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p10 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_RCH_OV_CSC_P10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p11 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_RCH_OV_CSC_P11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p12 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_RCH_OV_CSC_P12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p20 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_RCH_OV_CSC_P20_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p21 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_RCH_OV_CSC_P21_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p22 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_RCH_OV_CSC_P22_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_mprec : 3;
        unsigned int reserved : 29;
    } reg;
} AAE_RCH_OV_CSC_MPREC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int mitm_ppro_bypass : 1;
        unsigned int reserved_1 : 30;
    } reg;
} AAE_RCH_OV_MITM_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_degmm_x1_step : 4;
        unsigned int reserved_0 : 4;
        unsigned int mitm_slf_degmm_x2_step : 4;
        unsigned int reserved_1 : 4;
        unsigned int mitm_slf_degmm_x3_step : 4;
        unsigned int reserved_2 : 4;
        unsigned int mitm_slf_degmm_x4_step : 4;
        unsigned int reserved_3 : 4;
    } reg;
} AAE_RCH_OV_MITM_SLF_DEGAMMA_STEP1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_degmm_x5_step : 4;
        unsigned int reserved_0 : 4;
        unsigned int mitm_slf_degmm_x6_step : 4;
        unsigned int reserved_1 : 4;
        unsigned int mitm_slf_degmm_x7_step : 4;
        unsigned int reserved_2 : 4;
        unsigned int mitm_slf_degmm_x8_step : 4;
        unsigned int reserved_3 : 4;
    } reg;
} AAE_RCH_OV_MITM_SLF_DEGAMMA_STEP2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_degmm_x1_pos : 10;
        unsigned int reserved_0 : 6;
        unsigned int mitm_slf_degmm_x2_pos : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RCH_OV_MITM_SLF_DEGAMMA_POS1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_degmm_x3_pos : 10;
        unsigned int reserved_0 : 6;
        unsigned int mitm_slf_degmm_x4_pos : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RCH_OV_MITM_SLF_DEGAMMA_POS2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_degmm_x5_pos : 10;
        unsigned int reserved_0 : 6;
        unsigned int mitm_slf_degmm_x6_pos : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RCH_OV_MITM_SLF_DEGAMMA_POS3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_degmm_x7_pos : 10;
        unsigned int reserved_0 : 6;
        unsigned int mitm_slf_degmm_x8_pos : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RCH_OV_MITM_SLF_DEGAMMA_POS4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_degmm_x1_num : 6;
        unsigned int reserved_0 : 2;
        unsigned int mitm_slf_degmm_x2_num : 6;
        unsigned int reserved_1 : 2;
        unsigned int mitm_slf_degmm_x3_num : 6;
        unsigned int reserved_2 : 2;
        unsigned int mitm_slf_degmm_x4_num : 6;
        unsigned int reserved_3 : 2;
    } reg;
} AAE_RCH_OV_MITM_SLF_DEGAMMA_NUM1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_degmm_x5_num : 6;
        unsigned int reserved_0 : 2;
        unsigned int mitm_slf_degmm_x6_num : 6;
        unsigned int reserved_1 : 2;
        unsigned int mitm_slf_degmm_x7_num : 6;
        unsigned int reserved_2 : 2;
        unsigned int mitm_slf_degmm_x8_num : 6;
        unsigned int reserved_3 : 2;
    } reg;
} AAE_RCH_OV_MITM_SLF_DEGAMMA_NUM2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_gamut_coef00 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_RCH_OV_MITM_SLF_GAMUT_COEF00_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_gamut_coef01 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_RCH_OV_MITM_SLF_GAMUT_COEF01_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_gamut_coef02 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_RCH_OV_MITM_SLF_GAMUT_COEF02_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_gamut_coef10 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_RCH_OV_MITM_SLF_GAMUT_COEF10_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_gamut_coef11 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_RCH_OV_MITM_SLF_GAMUT_COEF11_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_gamut_coef12 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_RCH_OV_MITM_SLF_GAMUT_COEF12_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_gamut_coef20 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_RCH_OV_MITM_SLF_GAMUT_COEF20_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_gamut_coef21 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_RCH_OV_MITM_SLF_GAMUT_COEF21_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_gamut_coef22 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_RCH_OV_MITM_SLF_GAMUT_COEF22_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_gamut_scale : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_RCH_OV_MITM_SLF_GAMUT_SCALE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_gamut_clip_max : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_RCH_OV_MITM_SLF_GAMUT_CLIP_MAX_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_gmm_x1_step : 5;
        unsigned int reserved_0 : 3;
        unsigned int mitm_slf_gmm_x2_step : 5;
        unsigned int reserved_1 : 3;
        unsigned int mitm_slf_gmm_x3_step : 5;
        unsigned int reserved_2 : 3;
        unsigned int mitm_slf_gmm_x4_step : 5;
        unsigned int reserved_3 : 3;
    } reg;
} AAE_RCH_OV_MITM_SLF_GAMMA_STEP1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_gmm_x5_step : 5;
        unsigned int reserved_0 : 3;
        unsigned int mitm_slf_gmm_x6_step : 5;
        unsigned int reserved_1 : 3;
        unsigned int mitm_slf_gmm_x7_step : 5;
        unsigned int reserved_2 : 3;
        unsigned int mitm_slf_gmm_x8_step : 5;
        unsigned int reserved_3 : 3;
    } reg;
} AAE_RCH_OV_MITM_SLF_GAMMA_STEP2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_gmm_x1_pos : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_RCH_OV_MITM_SLF_GAMMA_POS1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_gmm_x2_pos : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_RCH_OV_MITM_SLF_GAMMA_POS2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_gmm_x3_pos : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_RCH_OV_MITM_SLF_GAMMA_POS3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_gmm_x4_pos : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_RCH_OV_MITM_SLF_GAMMA_POS4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_gmm_x5_pos : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_RCH_OV_MITM_SLF_GAMMA_POS5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_gmm_x6_pos : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_RCH_OV_MITM_SLF_GAMMA_POS6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_gmm_x7_pos : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_RCH_OV_MITM_SLF_GAMMA_POS7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_gmm_x8_pos : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_RCH_OV_MITM_SLF_GAMMA_POS8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_gmm_x1_num : 6;
        unsigned int reserved_0 : 2;
        unsigned int mitm_slf_gmm_x2_num : 6;
        unsigned int reserved_1 : 2;
        unsigned int mitm_slf_gmm_x3_num : 6;
        unsigned int reserved_2 : 2;
        unsigned int mitm_slf_gmm_x4_num : 6;
        unsigned int reserved_3 : 2;
    } reg;
} AAE_RCH_OV_MITM_SLF_GAMMA_NUM1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_slf_gmm_x5_num : 6;
        unsigned int reserved_0 : 2;
        unsigned int mitm_slf_gmm_x6_num : 6;
        unsigned int reserved_1 : 2;
        unsigned int mitm_slf_gmm_x7_num : 6;
        unsigned int reserved_2 : 2;
        unsigned int mitm_slf_gmm_x8_num : 6;
        unsigned int reserved_3 : 2;
    } reg;
} AAE_RCH_OV_MITM_SLF_GAMMA_NUM2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_alpha_b : 10;
        unsigned int reserved_0 : 6;
        unsigned int mitm_alpha_a : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RCH_OV_MITM_ALPHA_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_degamma_even_coef : 16;
        unsigned int mitm_degamma_odd_coef : 16;
    } reg;
} AAE_RCH_OV_MITM_DEGAMMA_LUT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_gamma_even_coef : 10;
        unsigned int reserved_0 : 6;
        unsigned int mitm_gamma_odd_coef : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_RCH_OV_MITM_GAMMA_LUT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_dbg0 : 32;
    } reg;
} AAE_RCH_OV_MITM_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mitm_dbg1 : 32;
    } reg;
} AAE_RCH_OV_MITM_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_src_locolorkey : 30;
        unsigned int reserved : 2;
    } reg;
} AAE_RCH_OV_LAYER_SRCLOKEY_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_src_hicolorkey : 30;
        unsigned int reserved : 2;
    } reg;
} AAE_RCH_OV_LAYER_SRCHIKEY_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_dst_locolorkey : 30;
        unsigned int reserved : 2;
    } reg;
} AAE_RCH_OV_LAYER_DSTLOKEY_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_dst_hicolorkey : 30;
        unsigned int reserved : 2;
    } reg;
} AAE_RCH_OV_LAYER_DSTHIKEY_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blayer_bgcolor_en : 1;
        unsigned int reserved_0 : 7;
        unsigned int layer_fix_mode : 1;
        unsigned int layer_dst_pmode : 1;
        unsigned int layer_alpha_offdst : 2;
        unsigned int layer_dst_gmode : 2;
        unsigned int layer_dst_amode : 2;
        unsigned int reserved_1 : 7;
        unsigned int layer_src_mmode : 1;
        unsigned int layer_alpha_smode : 1;
        unsigned int layer_src_pmode : 1;
        unsigned int layer_src_lmode : 1;
        unsigned int layer_alpha_offsrc : 1;
        unsigned int layer_src_gmode : 2;
        unsigned int layer_src_amode : 2;
    } reg;
} AAE_RCH_OV_LAYER_ALPHA_MODE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov0_dbg0 : 32;
    } reg;
} AAE_RCH_OV_OV0_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov0_dbg1 : 32;
    } reg;
} AAE_RCH_OV_OV0_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov0_dbg2 : 32;
    } reg;
} AAE_RCH_OV_OV0_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov0_dbg3 : 32;
    } reg;
} AAE_RCH_OV_OV0_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov1_dbg0 : 32;
    } reg;
} AAE_RCH_OV_OV1_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov1_dbg1 : 32;
    } reg;
} AAE_RCH_OV_OV1_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov1_dbg2 : 32;
    } reg;
} AAE_RCH_OV_OV1_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov1_dbg3 : 32;
    } reg;
} AAE_RCH_OV_OV1_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov2_dbg0 : 32;
    } reg;
} AAE_RCH_OV_OV2_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov2_dbg1 : 32;
    } reg;
} AAE_RCH_OV_OV2_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov2_dbg2 : 32;
    } reg;
} AAE_RCH_OV_OV2_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov2_dbg3 : 32;
    } reg;
} AAE_RCH_OV_OV2_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov3_dbg0 : 32;
    } reg;
} AAE_RCH_OV_OV3_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov3_dbg1 : 32;
    } reg;
} AAE_RCH_OV_OV3_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov3_dbg2 : 32;
    } reg;
} AAE_RCH_OV_OV3_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ov3_dbg3 : 32;
    } reg;
} AAE_RCH_OV_OV3_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scene_lcnt_en : 1;
        unsigned int scene_lcnt_id : 3;
        unsigned int reserved : 28;
    } reg;
} AAE_RCH_OV_SCENE_LCNT_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scene_lcnt_thr0 : 16;
        unsigned int scene_lcnt_thr1 : 16;
    } reg;
} AAE_RCH_OV_SCENE_LCNT_THR01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scene_lcnt_thr2 : 16;
        unsigned int scene_lcnt_thr3 : 16;
    } reg;
} AAE_RCH_OV_SCENE_LCNT_THR23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rxx0_dbg0 : 32;
    } reg;
} AAE_RCH_OV_RXX0_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rxx0_dbg1 : 32;
    } reg;
} AAE_RCH_OV_RXX0_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rxx0_dbg2 : 32;
    } reg;
} AAE_RCH_OV_RXX0_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rxx0_dbg3 : 32;
    } reg;
} AAE_RCH_OV_RXX0_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rxx1_dbg0 : 32;
    } reg;
} AAE_RCH_OV_RXX1_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rxx1_dbg1 : 32;
    } reg;
} AAE_RCH_OV_RXX1_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rxx1_dbg2 : 32;
    } reg;
} AAE_RCH_OV_RXX1_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rxx1_dbg3 : 32;
    } reg;
} AAE_RCH_OV_RXX1_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rxx2_dbg0 : 32;
    } reg;
} AAE_RCH_OV_RXX2_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rxx2_dbg1 : 32;
    } reg;
} AAE_RCH_OV_RXX2_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rxx2_dbg2 : 32;
    } reg;
} AAE_RCH_OV_RXX2_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rxx2_dbg3 : 32;
    } reg;
} AAE_RCH_OV_RXX2_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rxx3_dbg0 : 32;
    } reg;
} AAE_RCH_OV_RXX3_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rxx3_dbg1 : 32;
    } reg;
} AAE_RCH_OV_RXX3_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rxx3_dbg2 : 32;
    } reg;
} AAE_RCH_OV_RXX3_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rxx3_dbg3 : 32;
    } reg;
} AAE_RCH_OV_RXX3_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wxx0_dbg0 : 32;
    } reg;
} AAE_RCH_OV_WXX0_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wxx0_dbg1 : 32;
    } reg;
} AAE_RCH_OV_WXX0_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wxx0_dbg2 : 32;
    } reg;
} AAE_RCH_OV_WXX0_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wxx0_dbg3 : 32;
    } reg;
} AAE_RCH_OV_WXX0_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wxx1_dbg0 : 32;
    } reg;
} AAE_RCH_OV_WXX1_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wxx1_dbg1 : 32;
    } reg;
} AAE_RCH_OV_WXX1_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wxx1_dbg2 : 32;
    } reg;
} AAE_RCH_OV_WXX1_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wxx1_dbg3 : 32;
    } reg;
} AAE_RCH_OV_WXX1_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wxx2_dbg0 : 32;
    } reg;
} AAE_RCH_OV_WXX2_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wxx2_dbg1 : 32;
    } reg;
} AAE_RCH_OV_WXX2_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wxx2_dbg2 : 32;
    } reg;
} AAE_RCH_OV_WXX2_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wxx2_dbg3 : 32;
    } reg;
} AAE_RCH_OV_WXX2_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wxx3_dbg0 : 32;
    } reg;
} AAE_RCH_OV_WXX3_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wxx3_dbg1 : 32;
    } reg;
} AAE_RCH_OV_WXX3_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wxx3_dbg2 : 32;
    } reg;
} AAE_RCH_OV_WXX3_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wxx3_dbg3 : 32;
    } reg;
} AAE_RCH_OV_WXX3_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_top_rd_shadow : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_HDR_RD_SHADOW_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_default : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_HDR_REG_DEFAULT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_top_clk_sel : 32;
    } reg;
} AAE_HDR_TOP_CLK_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_top_clk_en : 32;
    } reg;
} AAE_HDR_TOP_CLK_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_scene_id : 3;
        unsigned int reserved : 29;
    } reg;
} AAE_HDR_REG_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_flush_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_HDR_REG_CTRL_FLUSH_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_debug : 32;
    } reg;
} AAE_HDR_REG_CTRL_DEBUG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} AAE_HDR_REG_CTRL_STATE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} AAE_HDR_R_LB_DEBUG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} AAE_HDR_R_LB_DEBUG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} AAE_HDR_R_LB_DEBUG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} AAE_HDR_R_LB_DEBUG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} AAE_HDR_W_LB_DEBUG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} AAE_HDR_W_LB_DEBUG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} AAE_HDR_W_LB_DEBUG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} AAE_HDR_W_LB_DEBUG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 5;
        unsigned int reserved_1: 27;
    } reg;
} AAE_HDR_REG_CTRL_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int hdr_csc_isinrgb : 1;
        unsigned int reserved_1 : 30;
    } reg;
} AAE_HDR_CSC_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc_idc0 : 16;
        unsigned int hdr_csc_idc1 : 16;
    } reg;
} AAE_HDR_CSC_IDC0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc_idc2 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC_IDC2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc_odc0 : 16;
        unsigned int hdr_csc_odc1 : 16;
    } reg;
} AAE_HDR_CSC_ODC0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc_odc2 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC_ODC2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc_p00 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC_P00_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc_p01 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC_P01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc_p02 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC_P02_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc_p10 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC_P10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc_p11 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC_P11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc_p12 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC_P12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc_p20 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC_P20_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc_p21 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC_P21_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc_p22 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC_P22_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_gtm_mem_ctrl : 4;
        unsigned int reserved : 28;
    } reg;
} AAE_HDR_MEM_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_en : 1;
        unsigned int hdr_stt_en : 1;
        unsigned int hdr_gtm_luma_en : 1;
        unsigned int hdr_ltm_ace_en : 1;
        unsigned int hdr_ltm_drc_en : 1;
        unsigned int hdr_luma_n2l_en : 1;
        unsigned int hdr_color_proc_en : 1;
        unsigned int hdr_gtm_lut_sel : 1;
        unsigned int hdr_gtm_en : 1;
        unsigned int hdr_oetf_en : 1;
        unsigned int hdr_eotf_en : 1;
        unsigned int reserved : 21;
    } reg;
} AAE_HDR_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_height : 16;
        unsigned int hdr_width : 16;
    } reg;
} AAE_HDR_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_inv_size : 28;
        unsigned int reserved : 4;
    } reg;
} AAE_HDR_INV_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_stt_mean_y : 10;
        unsigned int reserved : 22;
    } reg;
} AAE_HDR_MEAN_STT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_stat_x_start : 16;
        unsigned int hdr_stat_x_end : 16;
    } reg;
} AAE_HDR_STAT_X_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_rgb2y_wt : 6;
        unsigned int reserved_0 : 2;
        unsigned int hdr_rgb2y_trans_r : 12;
        unsigned int reserved_1 : 12;
    } reg;
} AAE_HDR_RGB2Y_CTRL1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_rgb2y_trans_g : 12;
        unsigned int reserved_0 : 4;
        unsigned int hdr_rgb2y_trans_b : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_HDR_RGB2Y_CTRL2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_eotf_step0 : 5;
        unsigned int reserved_0 : 3;
        unsigned int hdr_eotf_step1 : 5;
        unsigned int reserved_1 : 3;
        unsigned int hdr_eotf_step2 : 5;
        unsigned int reserved_2 : 3;
        unsigned int hdr_eotf_step3 : 5;
        unsigned int reserved_3 : 3;
    } reg;
} AAE_HDR_EOTF_STEP1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_eotf_step4 : 5;
        unsigned int reserved_0 : 3;
        unsigned int hdr_eotf_step5 : 5;
        unsigned int reserved_1 : 3;
        unsigned int hdr_eotf_step6 : 5;
        unsigned int reserved_2 : 3;
        unsigned int hdr_eotf_step7 : 5;
        unsigned int reserved_3 : 3;
    } reg;
} AAE_HDR_EOTF_STEP2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_eotf_pos0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hdr_eotf_pos1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_HDR_EOTF_POS1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_eotf_pos2 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hdr_eotf_pos3 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_HDR_EOTF_POS2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_eotf_pos4 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hdr_eotf_pos5 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_HDR_EOTF_POS3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_eotf_pos6 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hdr_eotf_pos7 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_HDR_EOTF_POS4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_eotf_num0 : 9;
        unsigned int reserved_0 : 7;
        unsigned int hdr_eotf_num1 : 9;
        unsigned int reserved_1 : 7;
    } reg;
} AAE_HDR_EOTF_NUM1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_eotf_num2 : 9;
        unsigned int reserved_0 : 7;
        unsigned int hdr_eotf_num3 : 9;
        unsigned int reserved_1 : 7;
    } reg;
} AAE_HDR_EOTF_NUM2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_eotf_num4 : 9;
        unsigned int reserved_0 : 7;
        unsigned int hdr_eotf_num5 : 9;
        unsigned int reserved_1 : 7;
    } reg;
} AAE_HDR_EOTF_NUM3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_eotf_num6 : 9;
        unsigned int reserved_0 : 7;
        unsigned int hdr_eotf_num7 : 9;
        unsigned int reserved_1 : 7;
    } reg;
} AAE_HDR_EOTF_NUM4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_gtm_input_min_e : 14;
        unsigned int reserved_0 : 2;
        unsigned int hdr_gtm_output_min_e : 14;
        unsigned int reserved_1 : 2;
    } reg;
} AAE_HDR_GTM_MIN_E_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_gtm_input_min_o : 16;
        unsigned int hdr_gtm_output_min_o : 16;
    } reg;
} AAE_HDR_GTM_MIN_O_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_gtm_rgb2y_wt : 6;
        unsigned int reserved_0 : 2;
        unsigned int hdr_gtm_rgb2y_trans_r : 12;
        unsigned int reserved_1 : 12;
    } reg;
} AAE_HDR_GTM_RGB2Y_CTRL1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_gtm_rgb2y_trans_g : 12;
        unsigned int reserved_0 : 4;
        unsigned int hdr_gtm_rgb2y_trans_b : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_HDR_GTM_RGB2Y_CTRL2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_gtm_ratiolut0inclip : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_GTM_LUMA_CLIP1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_gtm_luma_ratio_lut_step0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int hdr_gtm_luma_ratio_lut_step1 : 4;
        unsigned int reserved_1 : 24;
    } reg;
} AAE_HDR_GTM_LUMA_RATIO_LUT_STEP_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_gtm_luma_out_bit0 : 4;
        unsigned int hdr_gtm_luma_out_bit1 : 4;
        unsigned int reserved : 24;
    } reg;
} AAE_HDR_GTM_LUMA_OUT_BIT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_gtm_luma_lut_thres : 12;
        unsigned int reserved : 20;
    } reg;
} AAE_HDR_GTM_LUMA_LUT_THRES_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_half_block_h : 16;
        unsigned int hdr_ltm_half_block_w : 16;
    } reg;
} AAE_HDR_LTM_HALF_BLOCK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_reciprocal_x : 10;
        unsigned int hdr_ltm_fixbit_x : 5;
        unsigned int reserved_0 : 1;
        unsigned int hdr_ltm_reciprocal_y : 10;
        unsigned int hdr_ltm_fixbit_y : 5;
        unsigned int reserved_1 : 1;
    } reg;
} AAE_HDR_LTM_INTP_XY_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_cell_height : 11;
        unsigned int reserved_0 : 5;
        unsigned int hdr_ltm_cell_width : 11;
        unsigned int reserved_1 : 5;
    } reg;
} AAE_HDR_LTM_CELL_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_inv_cellw : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_HDR_LTM_CELL_INVW_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_inv_cellh : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_HDR_LTM_CELL_INVH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_PQ2Gamma_endpoint : 14;
        unsigned int reserved : 18;
    } reg;
} AAE_HDR_LTM_PQ2GAMMA_END_PT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_vgrid_auto_en : 1;
        unsigned int hdr_ltm_wt_op : 1;
        unsigned int reserved_0 : 3;
        unsigned int hdr_ltm_l2n_en : 1;
        unsigned int hdr_ltm_stat_en : 1;
        unsigned int ltm_ihist_lut_sel : 1;
        unsigned int stat_step : 3;
        unsigned int ltm_damp : 8;
        unsigned int reserved_1 : 13;
    } reg;
} AAE_HDR_LTM_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_csp0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hdr_ltm_csp1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_HDR_LTM_CSP1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_csp2 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hdr_ltm_csp3 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_HDR_LTM_CSP2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_csp4 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hdr_ltm_csp5 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_HDR_LTM_CSP3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_csp6 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hdr_ltm_csp7 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_HDR_LTM_CSP4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_csp8 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hdr_ltm_csp9 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_HDR_LTM_CSP5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_csp10 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hdr_ltm_csp11 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_HDR_LTM_CSP6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_csp12 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hdr_ltm_csp13 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_HDR_LTM_CSP7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_csp14 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hdr_ltm_csp15 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_HDR_LTM_CSP8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_csp016 : 10;
        unsigned int reserved : 22;
    } reg;
} AAE_HDR_LTM_CSP9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_csn0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hdr_ltm_csn1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_HDR_LTM_CSN1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_csn2 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hdr_ltm_csn3 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_HDR_LTM_CSN2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_csn4 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hdr_ltm_csn5 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_HDR_LTM_CSN3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_csn6 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hdr_ltm_csn7 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_HDR_LTM_CSN4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_csn8 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hdr_ltm_csn9 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_HDR_LTM_CSN5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_csn10 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hdr_ltm_csn11 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_HDR_LTM_CSN6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_csn12 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hdr_ltm_csn13 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_HDR_LTM_CSN7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_csn14 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hdr_ltm_csn15 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_HDR_LTM_CSN8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_csn16 : 10;
        unsigned int reserved : 22;
    } reg;
} AAE_HDR_LTM_CSN9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_wtz0 : 8;
        unsigned int hdr_ltm_wtz1 : 8;
        unsigned int hdr_ltm_wtz2 : 8;
        unsigned int hdr_ltm_wtz3 : 8;
    } reg;
} AAE_HDR_LTM_WTZ1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_wtz4 : 8;
        unsigned int hdr_ltm_wtz5 : 8;
        unsigned int hdr_ltm_wtz6 : 8;
        unsigned int reserved : 8;
    } reg;
} AAE_HDR_LTM_WTZ2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_oetf_step0 : 5;
        unsigned int reserved_0 : 3;
        unsigned int hdr_oetf_step1 : 5;
        unsigned int reserved_1 : 3;
        unsigned int hdr_oetf_step2 : 5;
        unsigned int reserved_2 : 3;
        unsigned int hdr_oetf_step3 : 5;
        unsigned int reserved_3 : 3;
    } reg;
} AAE_HDR_OETF_STEP1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_oetf_step4 : 5;
        unsigned int reserved_0 : 3;
        unsigned int hdr_oetf_step5 : 5;
        unsigned int reserved_1 : 3;
        unsigned int hdr_oetf_step6 : 5;
        unsigned int reserved_2 : 3;
        unsigned int hdr_oetf_step7 : 5;
        unsigned int reserved_3 : 3;
    } reg;
} AAE_HDR_OETF_STEP2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_oetf_pos0 : 16;
        unsigned int hdr_oetf_pos1 : 16;
    } reg;
} AAE_HDR_OETF_POS1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_oetf_pos2 : 16;
        unsigned int hdr_oetf_pos3 : 16;
    } reg;
} AAE_HDR_OETF_POS2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_oetf_pos4 : 16;
        unsigned int hdr_oetf_pos5 : 16;
    } reg;
} AAE_HDR_OETF_POS3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_oetf_pos6 : 16;
        unsigned int hdr_oetf_pos7 : 16;
    } reg;
} AAE_HDR_OETF_POS4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_oetf_num0 : 9;
        unsigned int reserved_0 : 7;
        unsigned int hdr_oetf_num1 : 9;
        unsigned int reserved_1 : 7;
    } reg;
} AAE_HDR_OETF_NUM1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_oetf_num2 : 9;
        unsigned int reserved_0 : 7;
        unsigned int hdr_oetf_num3 : 9;
        unsigned int reserved_1 : 7;
    } reg;
} AAE_HDR_OETF_NUM2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_oetf_num4 : 9;
        unsigned int reserved_0 : 7;
        unsigned int hdr_oetf_num5 : 9;
        unsigned int reserved_1 : 7;
    } reg;
} AAE_HDR_OETF_NUM3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_oetf_num6 : 9;
        unsigned int reserved_0 : 7;
        unsigned int hdr_oetf_num7 : 9;
        unsigned int reserved_1 : 7;
    } reg;
} AAE_HDR_OETF_NUM4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_chroma_rgb2y_wt : 6;
        unsigned int reserved_0 : 2;
        unsigned int hdr_chroma_rgb2y_trans_r : 12;
        unsigned int reserved_1 : 12;
    } reg;
} AAE_HDR_CHROMA_RGB2Y_CTRL1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_chroma_rgb2y_trans_g : 12;
        unsigned int reserved_0 : 4;
        unsigned int hdr_chroma_rgb2y_trans_b : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_HDR_CHROMA_RGB2Y_CTRL2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_chroma_ratiolut00 : 12;
        unsigned int reserved_0 : 4;
        unsigned int hdr_chroma_ratiolut01 : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_HDR_CHROMA_RATIO_LUT00_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_chroma_ratiolut02 : 12;
        unsigned int reserved_0 : 4;
        unsigned int hdr_chroma_ratiolut03 : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_HDR_CHROMA_RATIO_LUT01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_chroma_ratiolut04 : 12;
        unsigned int reserved_0 : 4;
        unsigned int hdr_chroma_ratiolut05 : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_HDR_CHROMA_RATIO_LUT02_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_chroma_ratiolut06 : 12;
        unsigned int reserved_0 : 4;
        unsigned int hdr_chroma_ratiolut07 : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_HDR_CHROMA_RATIO_LUT03_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_chroma_ratiolut08 : 12;
        unsigned int reserved_0 : 4;
        unsigned int hdr_chroma_ratiolut09 : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_HDR_CHROMA_RATIO_LUT04_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_chroma_ratiolut010 : 12;
        unsigned int reserved_0 : 4;
        unsigned int hdr_chroma_ratiolut011 : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_HDR_CHROMA_RATIO_LUT05_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_chroma_ratiolut012 : 12;
        unsigned int reserved_0 : 4;
        unsigned int hdr_chroma_ratiolut013 : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_HDR_CHROMA_RATIO_LUT06_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_chroma_ratiolut014 : 12;
        unsigned int reserved_0 : 4;
        unsigned int hdr_chroma_ratiolut015 : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_HDR_CHROMA_RATIO_LUT07_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_chroma_ratiolut1_inclip : 14;
        unsigned int reserved_0 : 2;
        unsigned int hdr_chroma_ratiolut_outclip : 14;
        unsigned int reserved_1 : 2;
    } reg;
} AAE_HDR_CHROMA_RATIO_LUT_CLIP_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_chroma_ratiolut_step0 : 2;
        unsigned int reserved_0 : 2;
        unsigned int hdr_chroma_ratiolut_step1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int hdr_chroma_lut_thres : 8;
        unsigned int reserved_2 : 16;
    } reg;
} AAE_HDR_CHROMA_RATIO_LUT_STEP_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_chroma_outbit0 : 5;
        unsigned int reserved_0 : 3;
        unsigned int hdr_chroma_outbit1 : 5;
        unsigned int reserved_1 : 3;
        unsigned int hdr_chroma_outbit2 : 3;
        unsigned int reserved_2 : 13;
    } reg;
} AAE_HDR_CHROMA_OUT_BIT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_chroma_ratio_clip : 14;
        unsigned int reserved : 18;
    } reg;
} AAE_HDR_CHROMA_RATIO_CLIP_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_chroma_yuv_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_HDR_CHROMA_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc1_idc0 : 16;
        unsigned int hdr_csc1_idc1 : 16;
    } reg;
} AAE_HDR_CSC1_IDC0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc1_idc2 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC1_IDC2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc1_odc0 : 16;
        unsigned int hdr_csc1_odc1 : 16;
    } reg;
} AAE_HDR_CSC1_ODC0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc1_odc2 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC1_ODC2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc1_p00 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC1_P00_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc1_p01 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC1_P01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc1_p02 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC1_P02_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc1_p10 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC1_P10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc1_p11 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC1_P11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc1_p12 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC1_P12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc1_p20 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC1_P20_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc1_p21 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC1_P21_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc1_p22 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC1_P22_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc2_idc0 : 16;
        unsigned int hdr_csc2_idc1 : 16;
    } reg;
} AAE_HDR_CSC2_IDC0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc2_idc2 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC2_IDC2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc2_odc0 : 16;
        unsigned int hdr_csc2_odc1 : 16;
    } reg;
} AAE_HDR_CSC2_ODC0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc2_odc2 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC2_ODC2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc2_p00 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC2_P00_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc2_p01 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC2_P01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc2_p02 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC2_P02_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc2_p10 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC2_P10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc2_p11 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC2_P11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc2_p12 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC2_P12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc2_p20 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC2_P20_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc2_p21 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC2_P21_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_csc2_p22 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HDR_CSC2_P22_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int msk_min : 14;
        unsigned int reserved_0: 2;
        unsigned int msk_max : 14;
        unsigned int reserved_1: 2;
    } reg;
} AAE_HDR_LTM_MSK_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_dbg : 32;
    } reg;
} AAE_HDR_DBG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rx_p0_cnt : 32;
    } reg;
} AAE_HDR_RX_P0_CNT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rx_p1_cnt : 32;
    } reg;
} AAE_HDR_RX_P1_CNT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int frame_start_cnt : 32;
    } reg;
} AAE_HDR_FRAME_START_CNT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tx_p0_cnt : 32;
    } reg;
} AAE_HDR_TX_P0_CNT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tx_p1_cnt : 32;
    } reg;
} AAE_HDR_TX_P1_CNT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int frame_end_cnt : 32;
    } reg;
} AAE_HDR_FRAME_END_CNT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gtm_tx_cnt0 : 32;
    } reg;
} AAE_HDR_GTM_TX_CNT0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gtm_tx_cnt1 : 32;
    } reg;
} AAE_HDR_GTM_TX_CNT1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int oetf_rx_cnt0 : 32;
    } reg;
} AAE_HDR_OETF_RX_CNT0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int oetf_rx_cnt1 : 32;
    } reg;
} AAE_HDR_OETF_RX_CNT1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stat_p0_cnt : 32;
    } reg;
} AAE_HDR_STAT_P0_CNT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stat_p1_cnt : 32;
    } reg;
} AAE_HDR_STAT_P1_CNT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int degamma_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_HDR_DEGAMMA_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int degamma_mem_ctrl : 4;
        unsigned int reserved : 28;
    } reg;
} AAE_HDR_DEGAMMA_MEM_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int degamma_lut_sel : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_HDR_DEGAMMA_LUT_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int degamma_dbg0 : 32;
    } reg;
} AAE_HDR_DEGAMMA_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int degamma_dbg1 : 32;
    } reg;
} AAE_HDR_DEGAMMA_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gmp_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_HDR_GMP_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gmp_mem_ctrl : 4;
        unsigned int reserved : 28;
    } reg;
} AAE_HDR_GMP_MEM_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gmp_lut_sel : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_HDR_GMP_LUT_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gmp_dbg_w0 : 32;
    } reg;
} AAE_HDR_GMP_DBG_W0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gmp_dbg_r0 : 32;
    } reg;
} AAE_HDR_GMP_DBG_R0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gmp_dbg_r1 : 32;
    } reg;
} AAE_HDR_GMP_DBG_R1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gmp_dbg_r2 : 32;
    } reg;
} AAE_HDR_GMP_DBG_R2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gamma_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_HDR_GAMMA_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gamma_mem_ctrl : 4;
        unsigned int reserved : 28;
    } reg;
} AAE_HDR_GAMMA_MEM_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gamma_lut_sel : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_HDR_GAMMA_LUT_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gamma_dbg0 : 32;
    } reg;
} AAE_HDR_GAMMA_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gamma_dbg1 : 32;
    } reg;
} AAE_HDR_GAMMA_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_eotf_even_coef : 16;
        unsigned int hdr_eotf_odd_coef : 16;
    } reg;
} AAE_HDR_EOTF_LUT_COEF_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_oetf_even_coef : 12;
        unsigned int reserved_0 : 4;
        unsigned int hdr_oetf_odd_coef : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_HDR_OETF_LUT_COEF_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_gtm_lumalut0_even_coef : 16;
        unsigned int hdr_gtm_lumalut0_odd_coef : 16;
    } reg;
} AAE_HDR_GTM_LUMA_LUT0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_tms0 : 15;
        unsigned int reserved_0 : 1;
        unsigned int hdr_ltm_tms1 : 15;
        unsigned int reserved_1 : 1;
    } reg;
} AAE_HDR_LTM_TMS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int u_hdr_gtm_luma_even_coef : 16;
        unsigned int u_hdr_gtm_luma_odd_coef : 16;
    } reg;
} AAE_HDR_GTM_LUMA_LUT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int u_hdr_gtm_chroma_even_coef : 12;
        unsigned int reserved_0 : 4;
        unsigned int u_hdr_gtm_chroma_odd_coef : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_HDR_GTM_CHROMA_LUT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int u_hdr_gtm_chroma0_even_coef : 14;
        unsigned int reserved_0 : 2;
        unsigned int u_hdr_gtm_chroma0_odd_coef : 14;
        unsigned int reserved_1 : 2;
    } reg;
} AAE_HDR_GTM_CHROMA0_LUT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int u_hdr_gtm_chroma1_even_coef : 14;
        unsigned int reserved_0 : 2;
        unsigned int u_hdr_gtm_chroma1_odd_coef : 14;
        unsigned int reserved_1 : 2;
    } reg;
} AAE_HDR_GTM_CHROMA1_LUT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int u_hdr_gtm_chroma2_even_coef : 14;
        unsigned int reserved_0 : 2;
        unsigned int u_hdr_gtm_chroma2_odd_coef : 14;
        unsigned int reserved_1 : 2;
    } reg;
} AAE_HDR_GTM_CHROMA2_LUT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_pq2gamma_lut0 : 14;
        unsigned int reserved_0 : 2;
        unsigned int hdr_ltm_pq2gamma_lut1 : 14;
        unsigned int reserved_1 : 2;
    } reg;
} AAE_HDR_LTM_PQ2GAMMA_LUT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_global_hist_buff : 25;
        unsigned int reserved : 7;
    } reg;
} AAE_HDR_GLOBAL_HIST_BUFF_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_ihist : 25;
        unsigned int reserved : 7;
    } reg;
} AAE_HDR_LTM_HIST_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_localgamma_lut0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hdr_ltm_localgamma_lut1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_HDR_LTM_LOCALGAMMA_LUT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_vgrid0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int hdr_ltm_vgrid1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_HDR_LTM_VGRID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_vsum : 22;
        unsigned int reserved : 10;
    } reg;
} AAE_HDR_LTM_VSUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hdr_ltm_pcnt : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_HDR_LTM_PCNT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int u_degamma_r_even_coef : 12;
        unsigned int reserved_0 : 4;
        unsigned int u_degamma_r_odd_coef : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_HDR_DEGAMMA_R_COEF_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int u_degamma_g_even_coef : 12;
        unsigned int reserved_0 : 4;
        unsigned int u_degamma_g_odd_coef : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_HDR_DEGAMMA_G_COEF_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int u_degamma_b_even_coef : 12;
        unsigned int reserved_0 : 4;
        unsigned int u_degamma_b_odd_coef : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_HDR_DEGAMMA_B_COEF_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int u_gamma_r_even_coef : 12;
        unsigned int reserved_0 : 4;
        unsigned int u_gamma_r_odd_coef : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_HDR_GAMMA_R_COEF_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int u_gamma_g_even_coef : 12;
        unsigned int reserved_0 : 4;
        unsigned int u_gamma_g_odd_coef : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_HDR_GAMMA_G_COEF_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int u_gamma_b_even_coef : 12;
        unsigned int reserved_0 : 4;
        unsigned int u_gamma_b_odd_coef : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_HDR_GAMMA_B_COEF_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int u_gmp_coef : 32;
    } reg;
} AAE_HDR_GMP_COEF_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arsr_top_rd_shadow : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_ARSR_RD_SHADOW_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_default : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_ARSR_REG_DEFAULT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arsr_top_clk_sel : 32;
    } reg;
} AAE_ARSR_TOP_CLK_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arsr_top_clk_en : 32;
    } reg;
} AAE_ARSR_TOP_CLK_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_scene_id : 3;
        unsigned int reserved : 29;
    } reg;
} AAE_ARSR_REG_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_flush_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_ARSR_REG_CTRL_FLUSH_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_dbg : 32;
    } reg;
} AAE_ARSR_REG_CTRL_DEBUG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_state : 32;
    } reg;
} AAE_ARSR_REG_CTRL_STATE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_lb_debug0 : 32;
    } reg;
} AAE_ARSR_R_LB_DEBUG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_lb_debug1 : 32;
    } reg;
} AAE_ARSR_R_LB_DEBUG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_lb_debug2 : 32;
    } reg;
} AAE_ARSR_R_LB_DEBUG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_lb_debug3 : 32;
    } reg;
} AAE_ARSR_R_LB_DEBUG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w_lb_debug0 : 32;
    } reg;
} AAE_ARSR_W_LB_DEBUG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w_lb_debug1 : 32;
    } reg;
} AAE_ARSR_W_LB_DEBUG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w_lb_debug2 : 32;
    } reg;
} AAE_ARSR_W_LB_DEBUG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w_lb_debug3 : 32;
    } reg;
} AAE_ARSR_W_LB_DEBUG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_layer_id : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_ARSR_REG_CTRL_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_size_vrt : 13;
        unsigned int reserved_0 : 3;
        unsigned int dfc_size_hrz : 13;
        unsigned int reserved_1 : 3;
    } reg;
} AAE_ARSR_DFC_DISP_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_pix_in_num : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_ARSR_DFC_PIX_IN_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_glb_alpha1 : 10;
        unsigned int reserved_0 : 6;
        unsigned int dfc_glb_alpha0 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_ARSR_DFC_GLB_ALPHA01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_ax_swap : 1;
        unsigned int dfc_img_fmt : 5;
        unsigned int dfc_uv_swap : 1;
        unsigned int dfc_rb_swap : 1;
        unsigned int reserved : 24;
    } reg;
} AAE_ARSR_DFC_DISP_FMT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_right_clip : 6;
        unsigned int reserved_0 : 10;
        unsigned int dfc_left_clip : 6;
        unsigned int reserved_1 : 10;
    } reg;
} AAE_ARSR_DFC_CLIP_CTL_HRZ_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_bot_clip : 6;
        unsigned int reserved_0 : 10;
        unsigned int dfc_top_clip : 6;
        unsigned int reserved_1 : 10;
    } reg;
} AAE_ARSR_DFC_CLIP_CTL_VRZ_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_ctl_clip_enable : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_ARSR_DFC_CTL_CLIP_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_module_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_ARSR_DFC_ICG_MODULE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_dither_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_ARSR_DFC_DITHER_ENABLE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_left_pad : 6;
        unsigned int reserved_0 : 2;
        unsigned int dfc_right_pad : 6;
        unsigned int reserved_1 : 2;
        unsigned int dfc_top_pad : 6;
        unsigned int reserved_2 : 2;
        unsigned int dfc_bot_pad : 6;
        unsigned int reserved_3 : 1;
        unsigned int dfc_ctl_pad_enable : 1;
    } reg;
} AAE_ARSR_DFC_PADDING_CTL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int dfc_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_ARSR_DFC_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_en : 1;
        unsigned int bitext_rgb_en : 1;
        unsigned int bitext_alpha_en : 1;
        unsigned int bitext_reg_ini_cfg_en : 1;
        unsigned int reserved : 28;
    } reg;
} AAE_ARSR_BITEXT_CTL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_0 : 32;
    } reg;
} AAE_ARSR_BITEXT_REG_INI0_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_1 : 32;
    } reg;
} AAE_ARSR_BITEXT_REG_INI0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_2 : 32;
    } reg;
} AAE_ARSR_BITEXT_REG_INI0_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_3 : 31;
        unsigned int reserved : 1;
    } reg;
} AAE_ARSR_BITEXT_REG_INI0_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_0 : 32;
    } reg;
} AAE_ARSR_BITEXT_REG_INI1_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_1 : 32;
    } reg;
} AAE_ARSR_BITEXT_REG_INI1_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_2 : 32;
    } reg;
} AAE_ARSR_BITEXT_REG_INI1_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_3 : 31;
        unsigned int reserved : 1;
    } reg;
} AAE_ARSR_BITEXT_REG_INI1_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_0 : 32;
    } reg;
} AAE_ARSR_BITEXT_REG_INI2_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_1 : 32;
    } reg;
} AAE_ARSR_BITEXT_REG_INI2_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_2 : 32;
    } reg;
} AAE_ARSR_BITEXT_REG_INI2_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_3 : 31;
        unsigned int reserved : 1;
    } reg;
} AAE_ARSR_BITEXT_REG_INI2_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_power_ctrl_c : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_ARSR_BITEXT_POWER_CTRL_C_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_power_ctrl_shift : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_ARSR_BITEXT_POWER_CTRL_SHIFT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_00 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_ARSR_BITEXT_FILT_00_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_01 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_ARSR_BITEXT_FILT_01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_02 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_ARSR_BITEXT_FILT_02_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_10 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_ARSR_BITEXT_FILT_10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_11 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_ARSR_BITEXT_FILT_11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_12 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_ARSR_BITEXT_FILT_12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_20 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_ARSR_BITEXT_FILT_20_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_21 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_ARSR_BITEXT_FILT_21_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_22 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_ARSR_BITEXT_FILT_22_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_r0 : 32;
    } reg;
} AAE_ARSR_BITEXT_THD_R0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_r1 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_ARSR_BITEXT_THD_R1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_g0 : 32;
    } reg;
} AAE_ARSR_BITEXT_THD_G0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_g1 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_ARSR_BITEXT_THD_G1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_b0 : 32;
    } reg;
} AAE_ARSR_BITEXT_THD_B0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_b1 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_ARSR_BITEXT_THD_B1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_dbg0 : 32;
    } reg;
} AAE_ARSR_BITEXT0_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_idc0 : 11;
        unsigned int reserved_0: 5;
        unsigned int csc_idc1 : 11;
        unsigned int reserved_1: 5;
    } reg;
} AAE_ARSR_CSC_IDC0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_idc2 : 11;
        unsigned int reserved : 21;
    } reg;
} AAE_ARSR_CSC_IDC2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_odc0 : 11;
        unsigned int reserved_0: 5;
        unsigned int csc_odc1 : 11;
        unsigned int reserved_1: 5;
    } reg;
} AAE_ARSR_CSC_ODC0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_odc2 : 11;
        unsigned int reserved : 21;
    } reg;
} AAE_ARSR_CSC_ODC2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p00 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_ARSR_CSC_P00_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p01 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_ARSR_CSC_P01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p02 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_ARSR_CSC_P02_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p10 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_ARSR_CSC_P10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p11 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_ARSR_CSC_P11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p12 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_ARSR_CSC_P12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p20 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_ARSR_CSC_P20_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p21 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_ARSR_CSC_P21_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p22 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_ARSR_CSC_P22_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_module_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_ARSR_CSC_ICG_MODULE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_mprec : 3;
        unsigned int reserved : 29;
    } reg;
} AAE_ARSR_CSC_MPREC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_en_hscl_str : 1;
        unsigned int scf_en_hscl_str_a : 1;
        unsigned int reserved : 30;
    } reg;
} AAE_ARSR_SCF_EN_HSCL_STR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_en_vscl_str : 1;
        unsigned int scf_en_vscl_str_a : 1;
        unsigned int reserved : 30;
    } reg;
} AAE_ARSR_SCF_EN_VSCL_STR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_h_v_order : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_ARSR_SCF_H_V_ORDER_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_a_core_gt : 1;
        unsigned int scf_r_core_gt : 1;
        unsigned int scf_g_core_gt : 1;
        unsigned int scf_b_core_gt : 1;
        unsigned int reserved : 28;
    } reg;
} AAE_ARSR_SCF_CH_CORE_GT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_input_height : 13;
        unsigned int reserved_0 : 3;
        unsigned int scf_input_width : 13;
        unsigned int reserved_1 : 3;
    } reg;
} AAE_ARSR_SCF_INPUT_WIDTH_HEIGHT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_output_height : 13;
        unsigned int reserved_0 : 3;
        unsigned int scf_output_width : 13;
        unsigned int reserved_1 : 3;
    } reg;
} AAE_ARSR_SCF_OUTPUT_WIDTH_HEIGHT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_hcoef_mem_ctrl : 4;
        unsigned int scf_vcoef_mem_ctrl : 4;
        unsigned int reserved : 24;
    } reg;
} AAE_ARSR_SCF_COEF_MEM_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_en_hscl_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_ARSR_SCF_EN_HSCL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_en_vscl_en : 1;
        unsigned int scf_out_buffer_en : 1;
        unsigned int reserved : 30;
    } reg;
} AAE_ARSR_SCF_EN_VSCL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_acc_hscl : 30;
        unsigned int reserved : 2;
    } reg;
} AAE_ARSR_SCF_ACC_HSCL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_acc_hscl1 : 19;
        unsigned int reserved : 13;
    } reg;
} AAE_ARSR_SCF_ACC_HSCL1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_inc_hscl : 24;
        unsigned int reserved : 8;
    } reg;
} AAE_ARSR_SCF_INC_HSCL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_acc_vscl : 30;
        unsigned int reserved : 2;
    } reg;
} AAE_ARSR_SCF_ACC_VSCL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_acc_vscl1 : 19;
        unsigned int reserved : 13;
    } reg;
} AAE_ARSR_SCF_ACC_VSCL1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_inc_vscl : 24;
        unsigned int reserved : 8;
    } reg;
} AAE_ARSR_SCF_INC_VSCL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_sw_rst : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_ARSR_SCF_EN_NONLINEAR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_en_mmp : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_ARSR_SCF_EN_MMP_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_debug_h0 : 32;
    } reg;
} AAE_ARSR_SCF_DB_H0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_debug_h1 : 32;
    } reg;
} AAE_ARSR_SCF_DB_H1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_debug_v0 : 32;
    } reg;
} AAE_ARSR_SCF_DB_V0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_debug_v1 : 32;
    } reg;
} AAE_ARSR_SCF_DB_V1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_lb_mem_ctrl : 4;
        unsigned int reserved : 28;
    } reg;
} AAE_ARSR_SCF_LB_MEM_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arsr_input_height : 13;
        unsigned int reserved_0 : 3;
        unsigned int arsr_input_width : 13;
        unsigned int reserved_1 : 3;
    } reg;
} AAE_ARSR_INPUT_WIDTH_HEIGHT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arsr_output_height : 13;
        unsigned int reserved_0 : 3;
        unsigned int arsr_output_width : 13;
        unsigned int reserved_1 : 3;
    } reg;
} AAE_ARSR_OUTPUT_WIDTH_HEIGHT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ihleft : 29;
        unsigned int reserved : 3;
    } reg;
} AAE_ARSR_IHLEFT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ihleft1 : 29;
        unsigned int reserved : 3;
    } reg;
} AAE_ARSR_IHLEFT1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ihright : 29;
        unsigned int reserved : 3;
    } reg;
} AAE_ARSR_IHRIGHT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ihright1 : 29;
        unsigned int reserved : 3;
    } reg;
} AAE_ARSR_IHRIGHT1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivtop : 29;
        unsigned int reserved : 3;
    } reg;
} AAE_ARSR_IVTOP_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivbottom : 29;
        unsigned int reserved : 3;
    } reg;
} AAE_ARSR_IVBOTTOM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivbottom1 : 29;
        unsigned int reserved : 3;
    } reg;
} AAE_ARSR_IVBOTTOM1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ihinc : 22;
        unsigned int reserved : 10;
    } reg;
} AAE_ARSR_IHINC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivinc : 22;
        unsigned int reserved : 10;
    } reg;
} AAE_ARSR_IVINC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int uv_voffset : 6;
        unsigned int reserved_0 : 10;
        unsigned int uv_hoffset : 6;
        unsigned int reserved_1 : 10;
    } reg;
} AAE_ARSR_OFFSET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bypass : 1;
        unsigned int sharpenen : 1;
        unsigned int shootdetecten : 1;
        unsigned int skinctrlen : 1;
        unsigned int textureanalysisen : 1;
        unsigned int diintplen : 1;
        unsigned int nearesten : 1;
        unsigned int prescaleren : 1;
        unsigned int nointplen : 1;
        unsigned int dbg_en : 3;
        unsigned int lowpower_en : 1;
        unsigned int arsr2p_ppro_bypass : 1;
        unsigned int data_format : 1;
        unsigned int reserved : 17;
    } reg;
} AAE_ARSR_MODE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ythresl : 10;
        unsigned int ythresh : 10;
        unsigned int yexpectvalue : 10;
        unsigned int reserved : 2;
    } reg;
} AAE_ARSR_SKIN_THRES_Y_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int uthresl : 10;
        unsigned int uthresh : 10;
        unsigned int uexpectvalue : 10;
        unsigned int reserved : 2;
    } reg;
} AAE_ARSR_SKIN_THRES_U_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vthresl : 10;
        unsigned int vthresh : 10;
        unsigned int vexpectvalue : 10;
        unsigned int reserved : 2;
    } reg;
} AAE_ARSR_SKIN_THRES_V_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int yslop : 13;
        unsigned int clipdata : 10;
        unsigned int reserved : 9;
    } reg;
} AAE_ARSR_SKIN_CFG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int uslop : 13;
        unsigned int reserved : 19;
    } reg;
} AAE_ARSR_SKIN_CFG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vslop : 13;
        unsigned int reserved : 19;
    } reg;
} AAE_ARSR_SKIN_CFG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shootslop1 : 15;
        unsigned int reserved_0 : 1;
        unsigned int shootgradalpha : 6;
        unsigned int reserved_1 : 10;
    } reg;
} AAE_ARSR_SHOOT_CFG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shootgradsubthrl : 11;
        unsigned int reserved_0 : 5;
        unsigned int shootgradsubthrh : 11;
        unsigned int reserved_1 : 5;
    } reg;
} AAE_ARSR_SHOOT_CFG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shootshpratio : 6;
        unsigned int reserved : 26;
    } reg;
} AAE_ARSR_SHOOT_CFG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shptocuthigh0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int shptocuthigh1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_ARSR_SHARP_CFG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sharpshootctrll : 10;
        unsigned int reserved_0 : 6;
        unsigned int sharpshootctrlh : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_ARSR_SHARP_CFG4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} AAE_ARSR_SHARP_CFG5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blendshootctrl : 10;
        unsigned int reserved_0 : 6;
        unsigned int sharpcoring : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_ARSR_SHARP_CFG6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int skinthresh : 5;
        unsigned int reserved_0 : 3;
        unsigned int skinthresl : 5;
        unsigned int reserved_1 : 19;
    } reg;
} AAE_ARSR_SHARP_CFG7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int linearshratiol : 8;
        unsigned int reserved_0 : 8;
        unsigned int linearshratioh : 8;
        unsigned int reserved_1 : 8;
    } reg;
} AAE_ARSR_SHARP_CFG8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sharplevel_mf : 4;
        unsigned int reserved_0 : 12;
        unsigned int sharplevel_hf : 4;
        unsigned int reserved_1 : 12;
    } reg;
} AAE_ARSR_SHARPLEVEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shpgainlow_mf : 12;
        unsigned int reserved_0 : 4;
        unsigned int shpgainlow_hf : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_ARSR_SHPGAIN_LOW_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shpgainmid_mf : 12;
        unsigned int reserved_0 : 4;
        unsigned int shpgainmid_hf : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_ARSR_SHPGAIN_MID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shpgainhigh_mf : 12;
        unsigned int reserved_0 : 4;
        unsigned int shpgainhigh_hf : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_ARSR_SHPGAIN_HIGH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gainctrlsloph_mf : 22;
        unsigned int reserved : 10;
    } reg;
} AAE_ARSR_GAINCTRLSLOPH_MF_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gainctrlslopl_mf : 22;
        unsigned int reserved : 10;
    } reg;
} AAE_ARSR_GAINCTRLSLOPL_MF_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gainctrlsloph_hf : 22;
        unsigned int reserved : 10;
    } reg;
} AAE_ARSR_GAINCTRLSLOPH_HF_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gainctrlslopl_hf : 22;
        unsigned int reserved : 10;
    } reg;
} AAE_ARSR_GAINCTRLSLOPL_HF_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mf_lmt : 10;
        unsigned int reserved : 22;
    } reg;
} AAE_ARSR_MF_LMT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gain_mf_l : 12;
        unsigned int reserved_0: 4;
        unsigned int gain_mf_h : 12;
        unsigned int reserved_1: 4;
    } reg;
} AAE_ARSR_GAIN_MF_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mf_b : 23;
        unsigned int reserved : 9;
    } reg;
} AAE_ARSR_MF_B_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hf_lmt : 10;
        unsigned int reserved : 22;
    } reg;
} AAE_ARSR_HF_LMT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gain_hf_l : 12;
        unsigned int reserved_0: 4;
        unsigned int gain_hf_h : 12;
        unsigned int reserved_1: 4;
    } reg;
} AAE_ARSR_GAIN_HF_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hf_b : 23;
        unsigned int reserved : 9;
    } reg;
} AAE_ARSR_HF_B_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lf_ctrl_l : 8;
        unsigned int reserved_0: 8;
        unsigned int lf_ctrl_h : 8;
        unsigned int reserved_1: 8;
    } reg;
} AAE_ARSR_LF_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lf_var_l : 10;
        unsigned int reserved_0: 6;
        unsigned int lf_var_h : 10;
        unsigned int reserved_1: 6;
    } reg;
} AAE_ARSR_LF_VAR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lf_ctrl_slop : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_ARSR_LF_CTRL_SLOP_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hf_select : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_ARSR_HF_SELECT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shpgainvarhigh0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int shpgainvarhigh1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_ARSR_SHARP_CFG2_H_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shpgainvarlow0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int shpgainvarlow1 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_ARSR_SHARP_CFG2_L_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int difflow : 8;
        unsigned int reserved_0: 8;
        unsigned int diffhigh : 8;
        unsigned int reserved_1: 8;
    } reg;
} AAE_ARSR_TEXTURW_ANALYSTS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intplshootctrl : 10;
        unsigned int reserved : 22;
    } reg;
} AAE_ARSR_INTPLSHOOTCTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arsr2p_debug_h0 : 32;
    } reg;
} AAE_ARSR_ARSR2P_DEBUG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arsr2p_debug_h1 : 32;
    } reg;
} AAE_ARSR_ARSR2P_DEBUG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arsr2p_debug_v0 : 32;
    } reg;
} AAE_ARSR_ARSR2P_DEBUG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arsr2p_debug_v1 : 32;
    } reg;
} AAE_ARSR_ARSR2P_DEBUG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arsr_lb_mem_ctrl : 4;
        unsigned int reserved : 28;
    } reg;
} AAE_ARSR_ARSR2P_LB_MEM_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arsr_hcoef_mem_ctrl : 4;
        unsigned int arsr_vcoef_mem_ctrl : 4;
        unsigned int reserved : 24;
    } reg;
} AAE_ARSR_COEF_MEM_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_csc_idc0 : 11;
        unsigned int reserved_0 : 5;
        unsigned int post_csc_idc1 : 11;
        unsigned int reserved_1 : 5;
    } reg;
} AAE_ARSR_POST_CSC_IDC0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_csc_idc2 : 11;
        unsigned int reserved : 21;
    } reg;
} AAE_ARSR_POST_CSC_IDC2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_csc_odc0 : 11;
        unsigned int reserved_0 : 5;
        unsigned int post_csc_odc1 : 11;
        unsigned int reserved_1 : 5;
    } reg;
} AAE_ARSR_POST_CSC_ODC0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_csc_odc2 : 11;
        unsigned int reserved : 21;
    } reg;
} AAE_ARSR_POST_CSC_ODC2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_csc_p00 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_ARSR_POST_CSC_P00_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_csc_p01 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_ARSR_POST_CSC_P01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_csc_p02 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_ARSR_POST_CSC_P02_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_csc_p10 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_ARSR_POST_CSC_P10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_csc_p11 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_ARSR_POST_CSC_P11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_csc_p12 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_ARSR_POST_CSC_P12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_csc_p20 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_ARSR_POST_CSC_P20_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_csc_p21 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_ARSR_POST_CSC_P21_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_csc_p22 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_ARSR_POST_CSC_P22_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_csc_module_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_ARSR_POST_CSC_MODULE_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_csc_mprec : 3;
        unsigned int reserved : 29;
    } reg;
} AAE_ARSR_POST_CSC_MPREC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_clip_size_vrt : 13;
        unsigned int reserved_0 : 3;
        unsigned int post_clip_size_hrz : 13;
        unsigned int reserved_1 : 3;
    } reg;
} AAE_ARSR_POST_CLIP_DISP_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_clip_right : 6;
        unsigned int reserved_0 : 10;
        unsigned int post_clip_left : 6;
        unsigned int reserved_1 : 10;
    } reg;
} AAE_ARSR_POST_CLIP_CTL_HRZ_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_clip_bot : 6;
        unsigned int reserved_0 : 10;
        unsigned int post_clip_top : 6;
        unsigned int reserved_1 : 10;
    } reg;
} AAE_ARSR_POST_CLIP_CTL_VRZ_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_clip_enable : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_ARSR_POST_CLIP_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arsr_1vinc : 22;
        unsigned int reserved : 10;
    } reg;
} AAE_ARSR_1VINC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_video_6tap_coef : 32;
    } reg;
} AAE_ARSR_V0_SCF_VIDEO_6TAP_COEF_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_video_5tap_coef : 32;
    } reg;
} AAE_ARSR_V0_SCF_VIDEO_5TAP_COEF_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_video_4tap_coef : 32;
    } reg;
} AAE_ARSR_V0_SCF_VIDEO_4TAP_COEF_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coefy_v : 27;
        unsigned int reserved : 5;
    } reg;
} AAE_ARSR_COEFY_V_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coefy_h : 27;
        unsigned int reserved : 5;
    } reg;
} AAE_ARSR_COEFY_H_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coefa_v : 18;
        unsigned int reserved : 14;
    } reg;
} AAE_ARSR_COEFA_V_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coefa_h : 18;
        unsigned int reserved : 14;
    } reg;
} AAE_ARSR_COEFA_H_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coefuv_v : 18;
        unsigned int reserved : 14;
    } reg;
} AAE_ARSR_COEFUV_V_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coefuv_h : 18;
        unsigned int reserved : 14;
    } reg;
} AAE_ARSR_COEFUV_H_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vscf_top_rd_shadow : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_VSCF_RD_SHADOW_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_default : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_VSCF_REG_DEFAULT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vscf_top_clk_sel : 32;
    } reg;
} AAE_VSCF_TOP_CLK_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vscf_top_clk_en : 32;
    } reg;
} AAE_VSCF_TOP_CLK_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_scene_id : 3;
        unsigned int reserved : 29;
    } reg;
} AAE_VSCF_REG_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_flush_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_VSCF_REG_CTRL_FLUSH_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_dbg : 32;
    } reg;
} AAE_VSCF_REG_CTRL_DEBUG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_state : 32;
    } reg;
} AAE_VSCF_REG_CTRL_STATE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_lb_debug0 : 32;
    } reg;
} AAE_VSCF_R_LB_DEBUG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_lb_debug1 : 32;
    } reg;
} AAE_VSCF_R_LB_DEBUG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_lb_debug2 : 32;
    } reg;
} AAE_VSCF_R_LB_DEBUG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_lb_debug3 : 32;
    } reg;
} AAE_VSCF_R_LB_DEBUG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w_lb_debug0 : 32;
    } reg;
} AAE_VSCF_W_LB_DEBUG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w_lb_debug1 : 32;
    } reg;
} AAE_VSCF_W_LB_DEBUG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w_lb_debug2 : 32;
    } reg;
} AAE_VSCF_W_LB_DEBUG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w_lb_debug3 : 32;
    } reg;
} AAE_VSCF_W_LB_DEBUG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_layer_id : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_VSCF_REG_CTRL_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_size_vrt : 13;
        unsigned int reserved_0 : 3;
        unsigned int dfc_size_hrz : 13;
        unsigned int reserved_1 : 3;
    } reg;
} AAE_VSCF_DFC_DISP_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_pix_in_num : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_VSCF_DFC_PIX_IN_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_glb_alpha1 : 10;
        unsigned int reserved_0 : 6;
        unsigned int dfc_glb_alpha0 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_VSCF_DFC_GLB_ALPHA01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_ax_swap : 1;
        unsigned int dfc_img_fmt : 5;
        unsigned int dfc_uv_swap : 1;
        unsigned int dfc_rb_swap : 1;
        unsigned int reserved : 24;
    } reg;
} AAE_VSCF_DFC_DISP_FMT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_right_clip : 6;
        unsigned int reserved_0 : 10;
        unsigned int dfc_left_clip : 6;
        unsigned int reserved_1 : 10;
    } reg;
} AAE_VSCF_DFC_CLIP_CTL_HRZ_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_bot_clip : 6;
        unsigned int reserved_0 : 10;
        unsigned int dfc_top_clip : 6;
        unsigned int reserved_1 : 10;
    } reg;
} AAE_VSCF_DFC_CLIP_CTL_VRZ_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_ctl_clip_enable : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_VSCF_DFC_CTL_CLIP_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_module_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_VSCF_DFC_ICG_MODULE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_dither_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_VSCF_DFC_DITHER_ENABLE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_left_pad : 6;
        unsigned int reserved_0 : 2;
        unsigned int dfc_right_pad : 6;
        unsigned int reserved_1 : 2;
        unsigned int dfc_top_pad : 6;
        unsigned int reserved_2 : 2;
        unsigned int dfc_bot_pad : 6;
        unsigned int dfc_pad_pre_bypass : 1;
        unsigned int dfc_ctl_pad_enable : 1;
    } reg;
} AAE_VSCF_DFC_PADDING_CTL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int dfc_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_VSCF_DFC_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_en : 1;
        unsigned int bitext_rgb_en : 1;
        unsigned int bitext_alpha_en : 1;
        unsigned int bitext_reg_ini_cfg_en : 1;
        unsigned int reserved : 28;
    } reg;
} AAE_VSCF_BITEXT_CTL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_0 : 32;
    } reg;
} AAE_VSCF_BITEXT_REG_INI0_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_1 : 32;
    } reg;
} AAE_VSCF_BITEXT_REG_INI0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_2 : 32;
    } reg;
} AAE_VSCF_BITEXT_REG_INI0_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_3 : 31;
        unsigned int reserved : 1;
    } reg;
} AAE_VSCF_BITEXT_REG_INI0_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_0 : 32;
    } reg;
} AAE_VSCF_BITEXT_REG_INI1_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_1 : 32;
    } reg;
} AAE_VSCF_BITEXT_REG_INI1_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_2 : 32;
    } reg;
} AAE_VSCF_BITEXT_REG_INI1_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_3 : 31;
        unsigned int reserved : 1;
    } reg;
} AAE_VSCF_BITEXT_REG_INI1_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_0 : 32;
    } reg;
} AAE_VSCF_BITEXT_REG_INI2_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_1 : 32;
    } reg;
} AAE_VSCF_BITEXT_REG_INI2_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_2 : 32;
    } reg;
} AAE_VSCF_BITEXT_REG_INI2_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_3 : 31;
        unsigned int reserved : 1;
    } reg;
} AAE_VSCF_BITEXT_REG_INI2_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_power_ctrl_c : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_VSCF_BITEXT_POWER_CTRL_C_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_power_ctrl_shift : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_VSCF_BITEXT_POWER_CTRL_SHIFT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_00 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_VSCF_BITEXT_FILT_00_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_01 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_VSCF_BITEXT_FILT_01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_02 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_VSCF_BITEXT_FILT_02_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_10 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_VSCF_BITEXT_FILT_10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_11 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_VSCF_BITEXT_FILT_11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_12 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_VSCF_BITEXT_FILT_12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_20 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_VSCF_BITEXT_FILT_20_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_21 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_VSCF_BITEXT_FILT_21_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_22 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_VSCF_BITEXT_FILT_22_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_r0 : 32;
    } reg;
} AAE_VSCF_BITEXT_THD_R0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_r1 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_VSCF_BITEXT_THD_R1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_g0 : 32;
    } reg;
} AAE_VSCF_BITEXT_THD_G0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_g1 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_VSCF_BITEXT_THD_G1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_b0 : 32;
    } reg;
} AAE_VSCF_BITEXT_THD_B0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_b1 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_VSCF_BITEXT_THD_B1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_dbg0 : 32;
    } reg;
} AAE_VSCF_BITEXT0_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_idc0 : 11;
        unsigned int reserved_0: 5;
        unsigned int csc_idc1 : 11;
        unsigned int reserved_1: 5;
    } reg;
} AAE_VSCF_CSC_IDC0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_idc2 : 11;
        unsigned int reserved : 21;
    } reg;
} AAE_VSCF_CSC_IDC2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_odc0 : 11;
        unsigned int reserved_0: 5;
        unsigned int csc_odc1 : 11;
        unsigned int reserved_1: 5;
    } reg;
} AAE_VSCF_CSC_ODC0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_odc2 : 11;
        unsigned int reserved : 21;
    } reg;
} AAE_VSCF_CSC_ODC2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p00 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_VSCF_CSC_P00_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p01 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_VSCF_CSC_P01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p02 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_VSCF_CSC_P02_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p10 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_VSCF_CSC_P10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p11 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_VSCF_CSC_P11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p12 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_VSCF_CSC_P12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p20 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_VSCF_CSC_P20_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p21 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_VSCF_CSC_P21_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p22 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_VSCF_CSC_P22_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_module_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_VSCF_CSC_ICG_MODULE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_mprec : 3;
        unsigned int reserved : 29;
    } reg;
} AAE_VSCF_CSC_MPREC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_en_hscl_str : 1;
        unsigned int scf_en_hscl_str_a : 1;
        unsigned int reserved : 30;
    } reg;
} AAE_VSCF_SCF_EN_HSCL_STR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_en_vscl_str : 1;
        unsigned int scf_en_vscl_str_a : 1;
        unsigned int reserved : 30;
    } reg;
} AAE_VSCF_SCF_EN_VSCL_STR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_h_v_order : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_VSCF_SCF_H_V_ORDER_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_a_core_gt : 1;
        unsigned int scf_r_core_gt : 1;
        unsigned int scf_g_core_gt : 1;
        unsigned int scf_b_core_gt : 1;
        unsigned int reserved : 28;
    } reg;
} AAE_VSCF_SCF_CH_CORE_GT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_input_height : 13;
        unsigned int reserved_0 : 3;
        unsigned int scf_input_width : 13;
        unsigned int reserved_1 : 3;
    } reg;
} AAE_VSCF_SCF_INPUT_WIDTH_HEIGHT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_output_height : 13;
        unsigned int reserved_0 : 3;
        unsigned int scf_output_width : 13;
        unsigned int reserved_1 : 3;
    } reg;
} AAE_VSCF_SCF_OUTPUT_WIDTH_HEIGHT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_hcoef_mem_ctrl : 4;
        unsigned int scf_vcoef_mem_ctrl : 4;
        unsigned int reserved : 24;
    } reg;
} AAE_VSCF_SCF_COEF_MEM_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_en_hscl_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_VSCF_SCF_EN_HSCL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_en_vscl_en : 1;
        unsigned int scf_out_buffer_en : 1;
        unsigned int reserved : 30;
    } reg;
} AAE_VSCF_SCF_EN_VSCL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_acc_hscl : 30;
        unsigned int reserved : 2;
    } reg;
} AAE_VSCF_SCF_ACC_HSCL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_acc_hscl1 : 19;
        unsigned int reserved : 13;
    } reg;
} AAE_VSCF_SCF_ACC_HSCL1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_inc_hscl : 24;
        unsigned int reserved : 8;
    } reg;
} AAE_VSCF_SCF_INC_HSCL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_acc_vscl : 30;
        unsigned int reserved : 2;
    } reg;
} AAE_VSCF_SCF_ACC_VSCL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_acc_vscl1 : 19;
        unsigned int reserved : 13;
    } reg;
} AAE_VSCF_SCF_ACC_VSCL1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_inc_vscl : 24;
        unsigned int reserved : 8;
    } reg;
} AAE_VSCF_SCF_INC_VSCL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_sw_rst : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_VSCF_SCF_EN_NONLINEAR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_en_mmp : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_VSCF_SCF_EN_MMP_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_debug_h0 : 32;
    } reg;
} AAE_VSCF_SCF_DB_H0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_debug_h1 : 32;
    } reg;
} AAE_VSCF_SCF_DB_H1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_debug_v0 : 32;
    } reg;
} AAE_VSCF_SCF_DB_V0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_debug_v1 : 32;
    } reg;
} AAE_VSCF_SCF_DB_V1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_lb_mem_ctrl : 4;
        unsigned int reserved : 28;
    } reg;
} AAE_VSCF_SCF_LB_MEM_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_clip_size_vrt : 13;
        unsigned int reserved_0 : 3;
        unsigned int post_clip_size_hrz : 13;
        unsigned int reserved_1 : 3;
    } reg;
} AAE_VSCF_POST_CLIP_DISP_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_clip_right : 6;
        unsigned int reserved_0 : 10;
        unsigned int post_clip_left : 6;
        unsigned int reserved_1 : 10;
    } reg;
} AAE_VSCF_POST_CLIP_CTL_HRZ_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_clip_bot : 6;
        unsigned int reserved_0 : 10;
        unsigned int post_clip_top : 6;
        unsigned int reserved_1 : 10;
    } reg;
} AAE_VSCF_POST_CLIP_CTL_VRZ_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int post_clip_enable : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_VSCF_POST_CLIP_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_video_6tap_coef : 32;
    } reg;
} AAE_VSCF_V0_SCF_VIDEO_6TAP_COEF_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_video_5tap_coef : 32;
    } reg;
} AAE_VSCF_V0_SCF_VIDEO_5TAP_COEF_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf_video_4tap_coef : 32;
    } reg;
} AAE_VSCF_V0_SCF_VIDEO_4TAP_COEF_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cld_rgb : 24;
        unsigned int reserved : 8;
    } reg;
} AAE_CLD_RGB_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cld_clk_en : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_CLD_CLK_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cld_clk_sel : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_CLD_CLK_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cld_dbg : 32;
    } reg;
} AAE_CLD_DBG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cld_dbg1 : 32;
    } reg;
} AAE_CLD_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cld_dbg2 : 32;
    } reg;
} AAE_CLD_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cld_dbg3 : 32;
    } reg;
} AAE_CLD_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cld_dbg4 : 32;
    } reg;
} AAE_CLD_DBG4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cld_dbg5 : 32;
    } reg;
} AAE_CLD_DBG5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cld_dbg6 : 32;
    } reg;
} AAE_CLD_DBG6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cld_dbg7 : 32;
    } reg;
} AAE_CLD_DBG7_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cld_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_CLD_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cld_size_hrz : 13;
        unsigned int cld_size_vrt : 13;
        unsigned int reserved : 6;
    } reg;
} AAE_CLD_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_scene_id : 3;
        unsigned int reserved : 29;
    } reg;
} AAE_CLD_REG_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_flush_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_CLD_REG_CTRL_FLUSH_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_dbg : 32;
    } reg;
} AAE_CLD_REG_CTRL_DEBUG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_state : 32;
    } reg;
} AAE_CLD_REG_CTRL_STATE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_layer_id : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_CLD_REG_CTRL_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_rd_shadow : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_CLD_REG_RD_SHADOW_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_default : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_CLD_REG_DEFAULT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_lb_debug0 : 32;
    } reg;
} AAE_CLD_R_LB_DEBUG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_lb_debug1 : 32;
    } reg;
} AAE_CLD_R_LB_DEBUG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_lb_debug2 : 32;
    } reg;
} AAE_CLD_R_LB_DEBUG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_lb_debug3 : 32;
    } reg;
} AAE_CLD_R_LB_DEBUG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w_lb_debug0 : 32;
    } reg;
} AAE_CLD_W_LB_DEBUG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w_lb_debug1 : 32;
    } reg;
} AAE_CLD_W_LB_DEBUG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w_lb_debug2 : 32;
    } reg;
} AAE_CLD_W_LB_DEBUG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w_lb_debug3 : 32;
    } reg;
} AAE_CLD_W_LB_DEBUG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lb_wrap_clk_sel : 32;
    } reg;
} AAE_LB_WRAP_CLK_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lb_wrap_clk_en : 32;
    } reg;
} AAE_LB_WRAP_CLK_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lbuf_ctl_clk_sel : 32;
    } reg;
} AAE_LB_WRAP_LBUF_CTL_CLK_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lbuf_ctl_clk_en : 32;
    } reg;
} AAE_LB_WRAP_LBUF_CTL_CLK_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lbuf_mem_dslp_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_LB_WRAP_MEM_DSLP_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lbuf_run_state : 4;
        unsigned int lbuf_idx_state : 4;
        unsigned int reserved : 24;
    } reg;
} AAE_LB_WRAP_LBUF_CTL_STATE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lbuf_rf_use_num : 32;
    } reg;
} AAE_LB_WRAP_LBUF_RF_USE_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lbuf_dbg_rf_num : 32;
    } reg;
} AAE_LB_WRAP_LBUF_DBG_RF_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lbuf_dbg_rf_num1 : 32;
    } reg;
} AAE_LB_WRAP_LBUF_DBG_RF_NUM1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lbuf_dbg_frm_cnt : 32;
    } reg;
} AAE_LB_WRAP_LBUF_DBG_FRM_CNT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int run_check_sel : 8;
        unsigned int reserved : 24;
    } reg;
} AAE_LB_WRAP_LBUF_DBG_RUN_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lbuf_run_vir_idx : 14;
        unsigned int reserved_0 : 2;
        unsigned int lbuf_run_idx_num : 6;
        unsigned int reserved_1 : 2;
        unsigned int lbuf_run_rf_fmt : 4;
        unsigned int reserved_2 : 4;
    } reg;
} AAE_LB_WRAP_LBUF_RUN_STATE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lbuf_run_wr_mst : 6;
        unsigned int reserved_0 : 2;
        unsigned int lbuf_run_rd_mst : 6;
        unsigned int reserved_1 : 2;
        unsigned int lbuf_run_wln_num : 6;
        unsigned int reserved_2 : 2;
        unsigned int lbuf_run_rln_num : 6;
        unsigned int reserved_3 : 2;
    } reg;
} AAE_LB_WRAP_LBUF_RUN_MST_STATE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lbuf_run_vld : 1;
        unsigned int lbuf_run_wr_more : 1;
        unsigned int lbuf_run_w_image : 1;
        unsigned int lbuf_run_rep_rd : 1;
        unsigned int lbuf_run_wr_allow : 1;
        unsigned int lbuf_run_rd_allow : 1;
        unsigned int lbuf_run_rd2_allow : 1;
        unsigned int reserved_0 : 1;
        unsigned int lbuf_run_all_h : 14;
        unsigned int reserved_1 : 10;
    } reg;
} AAE_LB_WRAP_LBUF_RUN_CTL_STATE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lbuf_run_done_w_cnt : 14;
        unsigned int reserved_0 : 2;
        unsigned int lbuf_run_mst_w_cnt : 14;
        unsigned int reserved_1 : 2;
    } reg;
} AAE_LB_WRAP_LBUF_RUN_WR_STATE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lbuf_run_done_r_cnt : 14;
        unsigned int reserved_0 : 2;
        unsigned int lbuf_run_mst_r_cnt : 14;
        unsigned int reserved_1 : 2;
    } reg;
} AAE_LB_WRAP_LBUF_RUN_RD_STATE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lbuf_run_done_r2_cnt : 14;
        unsigned int reserved_0 : 2;
        unsigned int lbuf_run_mst_r2_cnt : 14;
        unsigned int reserved_1 : 2;
    } reg;
} AAE_LB_WRAP_LBUF_RUN_RD2_STATE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lbuf_clr_rlst_rdy : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_LB_WRAP_LBUF_CLR_RLST_RDY_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lbuf_clr_rlst_run_idx : 7;
        unsigned int reserved : 25;
    } reg;
} AAE_LB_WRAP_LBUF_CLR_RLST_RUN_IDX_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lbuf_dbg_wb_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_LB_WRAP_LBUF_DBG_WB_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lbuf_part_clk_sel : 32;
    } reg;
} AAE_LB_WRAP_LBUF_PART_CLK_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lbuf_part_clk_en : 32;
    } reg;
} AAE_LB_WRAP_LBUF_PART_CLK_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lbuf_mem_ctrl : 4;
        unsigned int reserved : 28;
    } reg;
} AAE_LB_WRAP_LBUF_MEM_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int part_dbg_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int dbg_r_sel : 4;
        unsigned int reserved_1 : 24;
    } reg;
} AAE_LB_WRAP_DEBUG_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int part_rmst_pass : 32;
    } reg;
} AAE_LB_WRAP_LBUF_PART_RMST_PASS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int part_wmst_pass : 32;
    } reg;
} AAE_LB_WRAP_LBUF_PART_WMST_PASS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int part_idx_dbg : 32;
    } reg;
} AAE_LB_WRAP_LBUF_PART_IDX_DATA_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int part_run_dbg : 32;
    } reg;
} AAE_LB_WRAP_LBUF_PART_RUN_DAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_default : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_WDFC_REG_DEFAULT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rwch_rd_shadow : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_WDFC_CH_RD_SHADOW_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_sw_end_req : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_WDFC_CH_SW_END_REQ_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_clk_sel : 32;
    } reg;
} AAE_WDFC_CH_CLK_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_clk_en : 32;
    } reg;
} AAE_WDFC_CH_CLK_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_dbg0 : 32;
    } reg;
} AAE_WDFC_CH_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_dbg1 : 32;
    } reg;
} AAE_WDFC_CH_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_dbg2 : 32;
    } reg;
} AAE_WDFC_CH_DBG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_dbg3 : 32;
    } reg;
} AAE_WDFC_CH_DBG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_dbg4 : 32;
    } reg;
} AAE_WDFC_CH_DBG4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_dbg5 : 32;
    } reg;
} AAE_WDFC_CH_DBG5_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ch_dbg6 : 32;
    } reg;
} AAE_WDFC_CH_DBG6_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_size_vrt : 13;
        unsigned int reserved_0 : 3;
        unsigned int dfc_size_hrz : 13;
        unsigned int reserved_1 : 3;
    } reg;
} AAE_WDFC_DFC_DISP_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_pix_in_num : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_WDFC_DFC_PIX_IN_NUM_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_glb_alpha1 : 10;
        unsigned int reserved_0 : 6;
        unsigned int dfc_glb_alpha0 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_WDFC_DFC_GLB_ALPHA01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_ax_swap : 1;
        unsigned int dfc_img_fmt : 5;
        unsigned int dfc_uv_swap : 1;
        unsigned int dfc_rb_swap : 1;
        unsigned int reserved : 24;
    } reg;
} AAE_WDFC_DFC_DISP_FMT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 6;
        unsigned int reserved_1: 10;
        unsigned int reserved_2: 6;
        unsigned int reserved_3: 10;
    } reg;
} AAE_WDFC_DFC_CLIP_CTL_HRZ_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 6;
        unsigned int reserved_1: 10;
        unsigned int reserved_2: 6;
        unsigned int reserved_3: 10;
    } reg;
} AAE_WDFC_DFC_CLIP_CTL_VRZ_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 31;
    } reg;
} AAE_WDFC_DFC_CTL_CLIP_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_module_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_WDFC_DFC_ICG_MODULE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_dither_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_WDFC_DFC_DITHER_ENABLE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_left_pad : 6;
        unsigned int reserved_0 : 2;
        unsigned int dfc_right_pad : 6;
        unsigned int reserved_1 : 2;
        unsigned int dfc_top_pad : 6;
        unsigned int reserved_2 : 2;
        unsigned int dfc_bot_pad : 6;
        unsigned int dfc_pad_pre_bypass : 1;
        unsigned int dfc_ctl_pad_enable : 1;
    } reg;
} AAE_WDFC_DFC_PADDING_CTL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfc_glb_alpha3 : 10;
        unsigned int reserved_0 : 6;
        unsigned int dfc_glb_alpha2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_WDFC_DFC_GLB_ALPHA23_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 16;
        unsigned int dfc_glb_alpha : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_WDFC_DFC_GLB_ALPHA_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bayer_alpha_handle_mode : 2;
        unsigned int bayer_alpha_shift_mode : 2;
        unsigned int reserved : 28;
    } reg;
} AAE_WDFC_DFC_ALPHA_CTL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bayer_alpha_thd : 30;
        unsigned int reserved : 2;
    } reg;
} AAE_WDFC_DFC_ALPHA_THD_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int bitext_reg_ini_cfg_en : 1;
        unsigned int reserved_3 : 28;
    } reg;
} AAE_WDFC_BITEXT_CTL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_0 : 32;
    } reg;
} AAE_WDFC_BITEXT_REG_INI0_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_1 : 32;
    } reg;
} AAE_WDFC_BITEXT_REG_INI0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_2 : 32;
    } reg;
} AAE_WDFC_BITEXT_REG_INI0_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini0_3 : 31;
        unsigned int reserved : 1;
    } reg;
} AAE_WDFC_BITEXT_REG_INI0_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_0 : 32;
    } reg;
} AAE_WDFC_BITEXT_REG_INI1_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_1 : 32;
    } reg;
} AAE_WDFC_BITEXT_REG_INI1_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_2 : 32;
    } reg;
} AAE_WDFC_BITEXT_REG_INI1_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini1_3 : 31;
        unsigned int reserved : 1;
    } reg;
} AAE_WDFC_BITEXT_REG_INI1_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_0 : 32;
    } reg;
} AAE_WDFC_BITEXT_REG_INI2_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_1 : 32;
    } reg;
} AAE_WDFC_BITEXT_REG_INI2_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_2 : 32;
    } reg;
} AAE_WDFC_BITEXT_REG_INI2_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_reg_ini2_3 : 31;
        unsigned int reserved : 1;
    } reg;
} AAE_WDFC_BITEXT_REG_INI2_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_power_ctrl_c : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_WDFC_BITEXT_POWER_CTRL_C_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_power_ctrl_shift : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_WDFC_BITEXT_POWER_CTRL_SHIFT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_00 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_WDFC_BITEXT_FILT_00_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_01 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_WDFC_BITEXT_FILT_01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_02 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_WDFC_BITEXT_FILT_02_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_10 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_WDFC_BITEXT_FILT_10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_11 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_WDFC_BITEXT_FILT_11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_12 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_WDFC_BITEXT_FILT_12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_20 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_WDFC_BITEXT_FILT_20_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_21 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_WDFC_BITEXT_FILT_21_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_filt_22 : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_WDFC_BITEXT_FILT_22_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_r0 : 32;
    } reg;
} AAE_WDFC_BITEXT_THD_R0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_r1 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_WDFC_BITEXT_THD_R1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_g0 : 32;
    } reg;
} AAE_WDFC_BITEXT_THD_G0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_g1 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_WDFC_BITEXT_THD_G1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_b0 : 32;
    } reg;
} AAE_WDFC_BITEXT_THD_B0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_thd_b1 : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_WDFC_BITEXT_THD_B1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bitext_dbg0 : 32;
    } reg;
} AAE_WDFC_BITEXT0_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dither_en : 1;
        unsigned int dither_hifreq_noise_mode : 2;
        unsigned int dither_rgb_shift_mode : 1;
        unsigned int dither_unifrom_en : 1;
        unsigned int bayer_rgb_en : 1;
        unsigned int reserved : 26;
    } reg;
} AAE_WDFC_DITHER_CTL1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dither_tri_thd10_b : 10;
        unsigned int dither_tri_thd10_g : 10;
        unsigned int dither_tri_thd10_r : 10;
        unsigned int reserved : 2;
    } reg;
} AAE_WDFC_DITHER_TRI_THD10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dither_tri_thd10_uni_b : 10;
        unsigned int dither_tri_thd10_uni_g : 10;
        unsigned int dither_tri_thd10_uni_r : 10;
        unsigned int reserved : 2;
    } reg;
} AAE_WDFC_DITHER_TRI_THD10_UNI_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 16;
        unsigned int bayer_offset : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_WDFC_BAYER_CTL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bayer_matrix_part1 : 32;
    } reg;
} AAE_WDFC_BAYER_MATRIX_PART1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bayer_matrix_part0 : 32;
    } reg;
} AAE_WDFC_BAYER_MATRIX_PART0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clip_size_vrt : 13;
        unsigned int reserved_0 : 3;
        unsigned int clip_size_hrz : 13;
        unsigned int reserved_1 : 3;
    } reg;
} AAE_WDFC_CLIP_DISP_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clip_right : 6;
        unsigned int reserved_0 : 10;
        unsigned int clip_left : 6;
        unsigned int reserved_1 : 10;
    } reg;
} AAE_WDFC_CLIP_CTL_HRZ_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clip_bot : 6;
        unsigned int reserved_0: 10;
        unsigned int clip_top : 6;
        unsigned int reserved_1: 10;
    } reg;
} AAE_WDFC_CLIP_CTL_VRZ_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clip_enable : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_WDFC_CLIP_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_idc0 : 11;
        unsigned int reserved_0: 5;
        unsigned int csc_idc1 : 11;
        unsigned int reserved_1: 5;
    } reg;
} AAE_WDFC_CSC_IDC0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_idc2 : 11;
        unsigned int reserved : 21;
    } reg;
} AAE_WDFC_CSC_IDC2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_odc0 : 11;
        unsigned int reserved_0: 5;
        unsigned int csc_odc1 : 11;
        unsigned int reserved_1: 5;
    } reg;
} AAE_WDFC_CSC_ODC0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_odc2 : 11;
        unsigned int reserved : 21;
    } reg;
} AAE_WDFC_CSC_ODC2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p00 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_WDFC_CSC_P00_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p01 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_WDFC_CSC_P01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p02 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_WDFC_CSC_P02_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p10 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_WDFC_CSC_P10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p11 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_WDFC_CSC_P11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p12 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_WDFC_CSC_P12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p20 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_WDFC_CSC_P20_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p21 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_WDFC_CSC_P21_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p22 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_WDFC_CSC_P22_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_module_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_WDFC_CSC_ICG_MODULE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_scene_id : 3;
        unsigned int reserved : 29;
    } reg;
} AAE_WDFC_REG_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_flush_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_WDFC_REG_CTRL_FLUSH_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_dbg : 32;
    } reg;
} AAE_WDFC_REG_CTRL_DEBUG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf2d_top_rd_shadow : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_SCF2D_RD_SHADOW_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_default : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_SCF2D_REG_DEFAULT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf2d_top_clk_sel : 32;
    } reg;
} AAE_SCF2D_TOP_CLK_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf2d_top_clk_en : 32;
    } reg;
} AAE_SCF2D_TOP_CLK_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_scene_id : 3;
        unsigned int reserved : 29;
    } reg;
} AAE_SCF2D_REG_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_flush_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_SCF2D_REG_CTRL_FLUSH_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_dbg : 32;
    } reg;
} AAE_SCF2D_REG_CTRL_DEBUG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_state : 32;
    } reg;
} AAE_SCF2D_REG_CTRL_STATE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_layer_id : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_SCF2D_REG_CTRL_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_idc0 : 11;
        unsigned int reserved_0: 5;
        unsigned int csc_idc1 : 11;
        unsigned int reserved_1: 5;
    } reg;
} AAE_SCF2D_CSC_IDC0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_idc2 : 11;
        unsigned int reserved : 21;
    } reg;
} AAE_SCF2D_CSC_IDC2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_odc0 : 11;
        unsigned int reserved_0: 5;
        unsigned int csc_odc1 : 11;
        unsigned int reserved_1: 5;
    } reg;
} AAE_SCF2D_CSC_ODC0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_odc2 : 11;
        unsigned int reserved : 21;
    } reg;
} AAE_SCF2D_CSC_ODC2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p00 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_SCF2D_CSC_P00_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p01 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_SCF2D_CSC_P01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p02 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_SCF2D_CSC_P02_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p10 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_SCF2D_CSC_P10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p11 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_SCF2D_CSC_P11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p12 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_SCF2D_CSC_P12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p20 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_SCF2D_CSC_P20_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p21 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_SCF2D_CSC_P21_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p22 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_SCF2D_CSC_P22_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_module_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_SCF2D_CSC_ICG_MODULE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_mprec : 3;
        unsigned int reserved : 29;
    } reg;
} AAE_SCF2D_CSC_MPREC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf2d_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_SCF2D_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf2d_input_width : 14;
        unsigned int reserved_0 : 2;
        unsigned int scf2d_input_height : 14;
        unsigned int reserved_1 : 2;
    } reg;
} AAE_SCF2D_INPUT_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf2d_output_width : 14;
        unsigned int reserved_0 : 2;
        unsigned int scf2d_output_height : 14;
        unsigned int reserved_1 : 2;
    } reg;
} AAE_SCF2D_OUTPUT_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf2d_hinc : 30;
        unsigned int reserved : 2;
    } reg;
} AAE_SCF2D_HINC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf2d_vinc : 30;
        unsigned int reserved : 2;
    } reg;
} AAE_SCF2D_VINC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf2d_hleft1_int : 14;
        unsigned int reserved : 18;
    } reg;
} AAE_SCF2D_HLEFT1_INT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf2d_hleft1_frac : 24;
        unsigned int reserved : 8;
    } reg;
} AAE_SCF2D_HLEFT1_FRAC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf2d_hright1_int : 14;
        unsigned int reserved : 18;
    } reg;
} AAE_SCF2D_HRIGHT1_INT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf2d_hright1_frac : 24;
        unsigned int reserved : 8;
    } reg;
} AAE_SCF2D_HRIGHT1_FRAC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf2d_hleft_int : 14;
        unsigned int reserved : 18;
    } reg;
} AAE_SCF2D_HLEFT_INT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf2d_hleft_frac : 24;
        unsigned int reserved : 8;
    } reg;
} AAE_SCF2D_HLEFT_FRAC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf2d_hright_int : 14;
        unsigned int reserved : 18;
    } reg;
} AAE_SCF2D_HRIGHT_INT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf2d_hright_frac : 24;
        unsigned int reserved : 8;
    } reg;
} AAE_SCF2D_HRIGHT_FRAC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf2d_vtop_int : 14;
        unsigned int reserved : 18;
    } reg;
} AAE_SCF2D_VTOP_INT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf2d_vtop_frac : 24;
        unsigned int reserved : 8;
    } reg;
} AAE_SCF2D_VTOP_FRAC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf2d_vbottom_int : 14;
        unsigned int reserved : 18;
    } reg;
} AAE_SCF2D_VBOTTOM_INT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf2d_vbottom_frac : 24;
        unsigned int reserved : 8;
    } reg;
} AAE_SCF2D_VBOTTOM_FRAC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf2d_lb_mem_ctrl : 4;
        unsigned int reserved : 28;
    } reg;
} AAE_SCF2D_LB_MEM_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf2d_debug0 : 32;
    } reg;
} AAE_SCF2D_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scf2d_debug1 : 32;
    } reg;
} AAE_SCF2D_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blur_wrap_rd_shadow : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_BLUR_RD_SHADOW_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_default : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_BLUR_REG_DEFAULT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blur_wrap_clk_sel : 32;
    } reg;
} AAE_BLUR_WRAP_CLK_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blur_wrap_clk_en : 32;
    } reg;
} AAE_BLUR_WRAP_CLK_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_scene_id : 3;
        unsigned int reserved : 29;
    } reg;
} AAE_BLUR_REG_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_flush_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_BLUR_REG_CTRL_FLUSH_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_dbg : 32;
    } reg;
} AAE_BLUR_REG_CTRL_DEBUG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_state : 32;
    } reg;
} AAE_BLUR_REG_CTRL_STATE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_layer_id : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_BLUR_REG_CTRL_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blur_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_BLUR_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blur_input_width : 14;
        unsigned int reserved_0 : 2;
        unsigned int blur_input_height : 14;
        unsigned int reserved_1 : 2;
    } reg;
} AAE_BLUR_INPUT_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blur_output_width : 14;
        unsigned int reserved_0 : 2;
        unsigned int blur_output_height : 14;
        unsigned int reserved_1 : 2;
    } reg;
} AAE_BLUR_OUTPUT_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blur_debug0 : 32;
    } reg;
} AAE_BLUR_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blur_debug1 : 32;
    } reg;
} AAE_BLUR_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int premult_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_BLUR_PREMULT_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gfilt_h_en : 1;
        unsigned int gfilt_v_en : 1;
        unsigned int reserved : 30;
    } reg;
} AAE_BLUR_GFILT_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gfilt_h_knl_size : 6;
        unsigned int reserved_0 : 10;
        unsigned int gfilt_v_knl_size : 6;
        unsigned int reserved_1 : 10;
    } reg;
} AAE_BLUR_GFILT_KNL_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gfilt_h_coef : 32;
    } reg;
} AAE_BLUR_GFILT_H_COEF_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gfilt_v_coef : 32;
    } reg;
} AAE_BLUR_GFILT_V_COEF_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gfilt_lb_mem_ctrl : 4;
        unsigned int reserved : 28;
    } reg;
} AAE_BLUR_GFILT_LB_MEM_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gfilt_debug0 : 32;
    } reg;
} AAE_BLUR_GFILT_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gfilt_debug1 : 32;
    } reg;
} AAE_BLUR_GFILT_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clip_left : 6;
        unsigned int reserved : 26;
    } reg;
} AAE_BLUR_CLIP_LEFT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clip_right : 6;
        unsigned int reserved : 26;
    } reg;
} AAE_BLUR_CLIP_RIGHT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clip_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_BLUR_CLIP_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int clip_dbg : 32;
    } reg;
} AAE_BLUR_CLIP_DBG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mean_color_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_BLUR_MEAN_COLOR_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mean_color_r : 10;
        unsigned int reserved : 22;
    } reg;
} AAE_BLUR_MEAN_COLOR_R_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mean_color_g : 10;
        unsigned int reserved : 22;
    } reg;
} AAE_BLUR_MEAN_COLOR_G_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mean_color_b : 10;
        unsigned int reserved : 22;
    } reg;
} AAE_BLUR_MEAN_COLOR_B_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mean_color_a : 10;
        unsigned int reserved : 22;
    } reg;
} AAE_BLUR_MEAN_COLOR_A_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hiof_wrap_rd_shadow : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_HIOF_RD_SHADOW_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_default : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_HIOF_REG_DEFAULT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hiof_wrap_clk_sel : 32;
    } reg;
} AAE_HIOF_WRAP_CLK_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hiof_wrap_clk_en : 32;
    } reg;
} AAE_HIOF_WRAP_CLK_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_scene_id : 3;
        unsigned int reserved : 29;
    } reg;
} AAE_HIOF_REG_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_flush_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_HIOF_REG_CTRL_FLUSH_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_dbg : 32;
    } reg;
} AAE_HIOF_REG_CTRL_DEBUG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_state : 32;
    } reg;
} AAE_HIOF_REG_CTRL_STATE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hiof0_en : 1;
        unsigned int hiof1_en : 1;
        unsigned int reserved : 30;
    } reg;
} AAE_HIOF_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ref_layer_id : 5;
        unsigned int reserved_0 : 3;
        unsigned int cur_layer_id : 5;
        unsigned int reserved_1 : 3;
        unsigned int mv_layer_id : 5;
        unsigned int reserved_2 : 11;
    } reg;
} AAE_HIOF_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int level : 2;
        unsigned int reserved : 30;
    } reg;
} AAE_HIOF_LEVEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mode : 2;
        unsigned int spena : 1;
        unsigned int iter_check_en : 1;
        unsigned int iter_num : 4;
        unsigned int flat_en : 1;
        unsigned int reserved : 23;
    } reg;
} AAE_HIOF_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int height : 12;
        unsigned int reserved_0: 4;
        unsigned int width : 12;
        unsigned int reserved_1: 4;
    } reg;
} AAE_HIOF_SIZE_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mv_inheight : 12;
        unsigned int reserved_0 : 4;
        unsigned int mv_inwidth : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_HIOF_SIZE_CFG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int width0 : 12;
        unsigned int reserved_0: 4;
        unsigned int width1 : 12;
        unsigned int reserved_1: 4;
    } reg;
} AAE_HIOF_SIZE_CFG2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hiof0_ref_store_stt : 12;
        unsigned int reserved_0 : 4;
        unsigned int hiof0_ref_store_end : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_HIOF_REF0_STORE_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hiof1_ref_store_stt : 12;
        unsigned int reserved_0 : 4;
        unsigned int hiof1_ref_store_end : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_HIOF_REF1_STORE_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hiof0_cur_store_stt : 12;
        unsigned int reserved_0 : 4;
        unsigned int hiof0_cur_store_end : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_HIOF_CUR0_STORE_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hiof1_cur_store_stt : 12;
        unsigned int reserved_0 : 4;
        unsigned int hiof1_cur_store_end : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_HIOF_CUR1_STORE_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hiof0_mv_store_stt : 12;
        unsigned int reserved_0 : 4;
        unsigned int hiof0_mv_store_end : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_HIOF_MV0_STORE_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hiof1_mv_store_stt : 12;
        unsigned int reserved_0 : 4;
        unsigned int hiof1_mv_store_end : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_HIOF_MV1_STORE_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w_stride : 4;
        unsigned int reserved : 28;
    } reg;
} AAE_HIOF_W_STRIDE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hiof0_mv_width : 12;
        unsigned int reserved_0 : 4;
        unsigned int hiof0_mv_clip_left : 7;
        unsigned int reserved_1 : 1;
        unsigned int hiof0_mv_clip_right : 7;
        unsigned int reserved_2 : 1;
    } reg;
} AAE_HIOF_OUTPUT0_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hiof1_mv_width : 12;
        unsigned int reserved_0 : 4;
        unsigned int hiof1_mv_clip_left : 7;
        unsigned int reserved_1 : 1;
        unsigned int hiof1_mv_clip_right : 7;
        unsigned int reserved_2 : 1;
    } reg;
} AAE_HIOF_OUTPUT1_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hiof0_cur_width_aft_stride : 12;
        unsigned int reserved_0 : 4;
        unsigned int hiof1_cur_width_aft_stride : 12;
        unsigned int reserved_1 : 4;
    } reg;
} AAE_HIOF_CUR_WIDTH_AFT_STRIDE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int offset : 16;
        unsigned int reserved : 16;
    } reg;
} AAE_HIOF_OFFSET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coeff0 : 9;
        unsigned int reserved_0: 7;
        unsigned int coeff1 : 9;
        unsigned int reserved_1: 7;
    } reg;
} AAE_HIOF_COEFF_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flat_thr : 12;
        unsigned int ismotion_thr : 4;
        unsigned int confilv_thr : 12;
        unsigned int att_max : 4;
    } reg;
} AAE_HIOF_THRESHOLD_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int confi_th : 5;
        unsigned int reserved_0 : 3;
        unsigned int padding_num : 5;
        unsigned int reserved_1 : 19;
    } reg;
} AAE_HIOF_MV_ADJ_CFG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int of_mv_th : 12;
        unsigned int of_cnt_th : 19;
        unsigned int reserved : 1;
    } reg;
} AAE_HIOF_MV_ADJ_CFG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int motion_flag : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_HIOF_MOTION_STATUS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int psnr_mse : 32;
    } reg;
} AAE_HIOF_PSNR_MSE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hiof_mem_ctrl : 4;
        unsigned int reserved : 28;
    } reg;
} AAE_HIOF_MEM_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_ro1 : 32;
    } reg;
} AAE_HIOF_DEBUG_RO1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_ro2 : 32;
    } reg;
} AAE_HIOF_DEBUG_RO2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_rw : 32;
    } reg;
} AAE_HIOF_DEBUG_RW_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bypass : 1;
        unsigned int bit_mode : 1;
        unsigned int reserved : 30;
    } reg;
} AAE_AIHDR_ENABLE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stripe_width : 14;
        unsigned int reserved_0 : 2;
        unsigned int stripe_height : 14;
        unsigned int reserved_1 : 2;
    } reg;
} AAE_AIHDR_IMAGE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int deriv_width : 21;
        unsigned int reserved : 11;
    } reg;
} AAE_AIHDR_DERIV_WIDTH_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int deriv_height : 21;
        unsigned int reserved : 11;
    } reg;
} AAE_AIHDR_DERIV_HEIGHT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stripe_offset_x : 15;
        unsigned int reserved : 17;
    } reg;
} AAE_AIHDR_STRIPE_OFFSET_X_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int start_block_x : 5;
        unsigned int reserved_0 : 11;
        unsigned int end_block_x : 5;
        unsigned int reserved_1 : 11;
    } reg;
} AAE_AIHDR_AITTONE_GRID_BLOCK_OFFSET_X_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_wt_0 : 10;
        unsigned int reserved : 22;
    } reg;
} AAE_AIHDR_RGB2Y_R0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int g_wt_0 : 10;
        unsigned int reserved : 22;
    } reg;
} AAE_AIHDR_RGB2Y_G0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int b_wt_0 : 10;
        unsigned int reserved : 22;
    } reg;
} AAE_AIHDR_RGB2Y_B0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_wt_1 : 10;
        unsigned int reserved : 22;
    } reg;
} AAE_AIHDR_RGB2Y_R1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int g_wt_1 : 10;
        unsigned int reserved : 22;
    } reg;
} AAE_AIHDR_RGB2Y_G1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int b_wt_1 : 10;
        unsigned int reserved : 22;
    } reg;
} AAE_AIHDR_RGB2Y_B1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gain_lut : 12;
        unsigned int reserved : 20;
    } reg;
} AAE_AIHDR_GAIN_LUT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int status : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_AIHDR_STATUS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blending_weight : 11;
        unsigned int reserved : 21;
    } reg;
} AAE_AIHDR_BLENDING_WEIGHT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug0 : 32;
    } reg;
} AAE_AIHDR_DEBUG_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug1 : 32;
    } reg;
} AAE_AIHDR_DEBUG_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ec_0 : 32;
    } reg;
} AAE_AIHDR_EC_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ec_1 : 32;
    } reg;
} AAE_AIHDR_EC_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int grid_mode : 1;
        unsigned int grid_info_en : 1;
        unsigned int force_clk_on : 1;
        unsigned int grid_info_os : 4;
        unsigned int grid_layer_id : 5;
        unsigned int scene_id : 4;
        unsigned int start_ctrl : 1;
        unsigned int grid_info_num_fst : 2;
        unsigned int sd_en_off : 1;
        unsigned int reserved : 12;
    } reg;
} AAE_AIHDR_WRAP_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int layer_width : 14;
        unsigned int reserved_0 : 1;
        unsigned int layer_height : 14;
        unsigned int reserved_1 : 3;
    } reg;
} AAE_AIHDR_WRAP_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wrap_debug0 : 32;
    } reg;
} AAE_AIHDR_WRAP_DEBUG_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wrap_debug1 : 32;
    } reg;
} AAE_AIHDR_WRAP_DEBUG_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int aihdr_mem_ctrl : 4;
        unsigned int reserved : 28;
    } reg;
} AAE_AIHDR_WRAP_MEM_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_idc0 : 11;
        unsigned int reserved_0: 5;
        unsigned int csc_idc1 : 11;
        unsigned int reserved_1: 5;
    } reg;
} AAE_AIHDR_CSC_IDC0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_idc2 : 11;
        unsigned int reserved : 21;
    } reg;
} AAE_AIHDR_CSC_IDC2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_odc0 : 11;
        unsigned int reserved_0: 5;
        unsigned int csc_odc1 : 11;
        unsigned int reserved_1: 5;
    } reg;
} AAE_AIHDR_CSC_ODC0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_odc2 : 11;
        unsigned int reserved : 21;
    } reg;
} AAE_AIHDR_CSC_ODC2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p00 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_AIHDR_CSC_P00_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p01 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_AIHDR_CSC_P01_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p02 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_AIHDR_CSC_P02_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p10 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_AIHDR_CSC_P10_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p11 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_AIHDR_CSC_P11_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p12 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_AIHDR_CSC_P12_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p20 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_AIHDR_CSC_P20_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p21 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_AIHDR_CSC_P21_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_p22 : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_AIHDR_CSC_P22_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_module_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_AIHDR_CSC_ICG_MODULE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csc_mprec : 3;
        unsigned int reserved : 29;
    } reg;
} AAE_AIHDR_CSC_MPREC_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_flush_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_AIHDR_REG_CTRL_FLUSH_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_dbg : 32;
    } reg;
} AAE_AIHDR_REG_CTRL_DEBUG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pipe_rd_shadow : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_AIHDR_WRAP_RD_SHADOW_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_default : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_AIHDR_REG_DEFAULT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blpp_wrap_rd_shadow : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_BLPP_RD_SHADOW_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_default : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_BLPP_REG_DEFAULT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blpp_wrap_clk_sel : 32;
    } reg;
} AAE_BLPP_WRAP_CLK_SEL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blpp_wrap_clk_en : 32;
    } reg;
} AAE_BLPP_WRAP_CLK_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_scene_id : 3;
        unsigned int reserved : 29;
    } reg;
} AAE_BLPP_REG_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_flush_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_BLPP_REG_CTRL_FLUSH_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_dbg : 32;
    } reg;
} AAE_BLPP_REG_CTRL_DEBUG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_state : 32;
    } reg;
} AAE_BLPP_REG_CTRL_STATE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reg_ctrl_layer_id : 5;
        unsigned int reserved : 27;
    } reg;
} AAE_BLPP_REG_CTRL_LAYER_ID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blpp_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_BLPP_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blpp_width : 14;
        unsigned int reserved_0 : 2;
        unsigned int blpp_height : 14;
        unsigned int reserved_1 : 2;
    } reg;
} AAE_BLPP_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blpp_debug0 : 32;
    } reg;
} AAE_BLPP_DBG0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int blpp_debug1 : 32;
    } reg;
} AAE_BLPP_DBG1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cancel_premult_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_BLPP_CANCEL_PREMULT_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int noise_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_BLPP_NOISE_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int noise_blk_str_h_pos : 14;
        unsigned int reserved : 18;
    } reg;
} AAE_BLPP_NOISE_BLK_STR_H_POS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int noise_ratio : 17;
        unsigned int reserved : 15;
    } reg;
} AAE_BLPP_NOISE_RATIO_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int noise_value : 3;
        unsigned int noise_upclip : 4;
        unsigned int noise_dnclip : 4;
        unsigned int reserved : 21;
    } reg;
} AAE_BLPP_NOISE_VAL_PARA_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int color_matrix_en : 1;
        unsigned int clmatrix_a_ch_replace_en : 1;
        unsigned int clmatrix_a_ch_replace_val : 10;
        unsigned int reserved : 20;
    } reg;
} AAE_BLPP_COLOR_MATRIX_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int color_matrix_coef : 32;
    } reg;
} AAE_BLPP_COLOR_MATRIX_COEF_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int premult_en : 1;
        unsigned int reserved : 31;
    } reg;
} AAE_BLPP_PREMULT_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int color_mask_en : 1;
        unsigned int clmask_premult_en : 1;
        unsigned int clmask_cxl_premult_en : 1;
        unsigned int clmask_a_ch_replace_en : 1;
        unsigned int clmask_a_ch_replace_val : 10;
        unsigned int reserved : 18;
    } reg;
} AAE_BLPP_COLOR_MASK_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int color_mask_r : 10;
        unsigned int reserved_0 : 6;
        unsigned int color_mask_g : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_BLPP_COLOR_MASK_R_G_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int color_mask_b : 10;
        unsigned int reserved_0 : 6;
        unsigned int color_mask_a : 10;
        unsigned int reserved_1 : 6;
    } reg;
} AAE_BLPP_COLOR_MASK_B_A_UNION;
#endif
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
