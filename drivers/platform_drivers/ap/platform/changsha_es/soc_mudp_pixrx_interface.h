#ifndef __SOC_MUDP_PIXRX_INTERFACE_H__
#define __SOC_MUDP_PIXRX_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MUDP_PIXRX_CCH_CAP_ADDR(base) (base)
#define SOC_MUDP_PIXRX_CCH_INT_EN_ADDR(base) ((base) + 0x4UL)
#define SOC_MUDP_PIXRX_CCH_INT_ADDR(base) ((base) + 0x8UL)
#define SOC_MUDP_PIXRX_CCH_PRI_MODE_ADDR(base) ((base) + 0xCUL)
#define SOC_MUDP_PIXRX_CCH_EN_ADDR(base,ChNum) (base) + 0x10 + 0x40 * (ChNum)
#define SOC_MUDP_PIXRX_CMDBUF_BASE_L_ADDR(base,ChNum) (base) + 0x14 + 0x40 * (ChNum)
#define SOC_MUDP_PIXRX_CMDBUF_BASE_H_ADDR(base,ChNum) (base) + 0x18 + 0x40 * (ChNum)
#define SOC_MUDP_PIXRX_CMDBUF_LEN_ADDR(base,ChNum) (base) + 0x1C + 0x40 * (ChNum)
#define SOC_MUDP_PIXRX_CMDBUF_WADDR_ADDR(base,ChNum) (base) + 0x20 + 0x40 * (ChNum)
#define SOC_MUDP_PIXRX_CMDBUF_RADDR_ADDR(base,ChNum) (base) + 0x24 + 0x40 * (ChNum)
#define SOC_MUDP_PIXRX_RSPBUF_BASE_L_ADDR(base,ChNum) (base) + 0x28 + 0x40 * (ChNum)
#define SOC_MUDP_PIXRX_RSPBUF_BASE_H_ADDR(base,ChNum) (base) + 0x2C + 0x40 * (ChNum)
#define SOC_MUDP_PIXRX_RSPBUF_LEN_ADDR(base,ChNum) (base) + 0x30 + 0x40 * (ChNum)
#define SOC_MUDP_PIXRX_RSPBUF_ADDR_ADDR(base,ChNum) (base) + 0x34 + 0x40 * (ChNum)
#define SOC_MUDP_PIXRX_CMDBUF_INT_EN_ADDR(base,ChNum) (base) + 0x38 + 0x40 * (ChNum)
#define SOC_MUDP_PIXRX_CMDBUF_INT_STATUS_ADDR(base,ChNum) (base) + 0x3C + 0x40 * (ChNum)
#define SOC_MUDP_PIXRX_DBGBUF_BASE_L_ADDR(base) ((base) + 0x410UL)
#define SOC_MUDP_PIXRX_DBGBUF_BASE_H_ADDR(base) ((base) + 0x414UL)
#define SOC_MUDP_PIXRX_DBGBUF_LEN_ADDR(base) ((base) + 0x418UL)
#define SOC_MUDP_PIXRX_DEBUG_INT_EN_ADDR(base) ((base) + 0x41CUL)
#define SOC_MUDP_PIXRX_DEBUG_INT_ADDR(base) ((base) + 0x420UL)
#define SOC_MUDP_PIXRX_DBGBUF_ADDR_ADDR(base) ((base) + 0x424UL)
#define SOC_MUDP_PIXRX_INT_IBI_ADDR(base) ((base) + 0x428UL)
#define SOC_MUDP_PIXRX_INT_DRVIC_ADDR(base,RegNum) (base) + 0x42C + 0x4 * (RegNum)
#define SOC_MUDP_PIXRX_CCH_SYNC_SEND_EN_ADDR(base) ((base) + 0x490UL)
#define SOC_MUDP_PIXRX_TIMEOUT_THRSD_ADDR(base) ((base) + 0x494UL)
#define SOC_MUDP_PIXRX_TX_THRSD_ADDR(base) ((base) + 0x498UL)
#define SOC_MUDP_PIXRX_RSP_PARS_CTRL_ADDR(base) ((base) + 0x49CUL)
#define SOC_MUDP_PIXRX_CCH_RX_BUFF_ADDR(base) ((base) + 0x4A0UL)
#define SOC_MUDP_PIXRX_AXI_Master_axuser_ADDR(base) ((base) + 0x4A4UL)
#define SOC_MUDP_PIXRX_AXI_Master_QOS_ADDR(base) ((base) + 0x4ACUL)
#define SOC_MUDP_PIXRX_AXI_Master_pprot_ADDR(base) ((base) + 0x4B0UL)
#define SOC_MUDP_PIXRX_DEBUG_IRQ_ADDR(base) ((base) + 0x4B4UL)
#define SOC_MUDP_PIXRX_DEBUG_ALIGN192_ADDR(base) ((base) + 0x4B8UL)
#define SOC_MUDP_PIXRX_DEBUG_RSP_PARS_ADDR(base) ((base) + 0x4BCUL)
#define SOC_MUDP_PIXRX_DEBUG_AXI_WR_ADDR(base) ((base) + 0x4C0UL)
#define SOC_MUDP_PIXRX_DEBUG_CCH_RX_CTRL_ADDR(base) ((base) + 0x4C4UL)
#define SOC_MUDP_PIXRX_DEBUG_CCH_TX_CTRL_VC0_ADDR(base) ((base) + 0x4C8UL)
#define SOC_MUDP_PIXRX_DEBUG_CCH_TX_CTRL_VC1_ADDR(base) ((base) + 0x4CCUL)
#define SOC_MUDP_PIXRX_DEBUG_CCH_TX_RD_ADDR(base) ((base) + 0x4D0UL)
#define SOC_MUDP_PIXRX_DEBUG_CCH_TX_ARB_ADDR(base) ((base) + 0x4D4UL)
#define SOC_MUDP_PIXRX_DEBUG_CCH_ALIGN_32_ADDR(base) ((base) + 0x4D8UL)
#define SOC_MUDP_PIXRX_DEBUG_CCH_CMD_PARS_ADDR(base) ((base) + 0x4DCUL)
#define SOC_MUDP_PIXRX_PIX_CTRL_ADDR(base) ((base) + 0X700UL)
#define SOC_MUDP_PIXRX_PIX_SOURCE_ID_ADDR(base) ((base) + 0x704UL)
#define SOC_MUDP_PIXRX_CFG_DBG_PIX_TOTAL_FRAME_NUM_ADDR(base) ((base) + 0X708UL)
#define SOC_MUDP_PIXRX_CFG_DBG_PIX_TOTAL_PACKAGE_NUM_ADDR(base) ((base) + 0x70CUL)
#define SOC_MUDP_PIXRX_CFG_DBG_PIX_FRAME_FATAL_TYPE_0_ADDR(base) ((base) + 0x710UL)
#define SOC_MUDP_PIXRX_CFG_DBG_PIX_FRAME_FATAL_TYPE_1_ADDR(base) ((base) + 0x714UL)
#define SOC_MUDP_PIXRX_DEC_BUF_CTRL_ADDR(base) ((base) + 0x800UL)
#define SOC_MUDP_PIXRX_DEC_BUF_MEM_CTRL_ADDR(base) ((base) + 0x804UL)
#define SOC_MUDP_PIXRX_DEC_BUF_STATE_ADDR(base) ((base) + 0x808UL)
#define SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_CTRL0_ADDR(base) ((base) + 0x80CUL)
#define SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_CTRL1_ADDR(base) ((base) + 0x810UL)
#define SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_STATE1_ADDR(base) ((base) + 0x814UL)
#define SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_STATE0_ADDR(base) ((base) + 0x818UL)
#define SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_STATE2_ADDR(base) ((base) + 0x81CUL)
#define SOC_MUDP_PIXRX_DEC_HEBCD_POST_PROC_ADDR(base) ((base) + 0x820UL)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL0_ADDR(base) ((base) + 0x824UL)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL1_ADDR(base) ((base) + 0x828UL)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL2_ADDR(base) ((base) + 0x82CUL)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_STATE0_ADDR(base) ((base) + 0x830UL)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_STATE1_ADDR(base) ((base) + 0x834UL)
#define SOC_MUDP_PIXRX_DEC_HEBCD_CTRL0_ADDR(base) ((base) + 0x838UL)
#define SOC_MUDP_PIXRX_DEC_HEBCD_CTRL1_ADDR(base) ((base) + 0x83CUL)
#define SOC_MUDP_PIXRX_DEC_HEBCD_CTRL2_ADDR(base) ((base) + 0x840UL)
#define SOC_MUDP_PIXRX_DEC_HEBCD_DBG0_ADDR(base) ((base) + 0x844UL)
#define SOC_MUDP_PIXRX_DEC_HEBCD_DBG1_ADDR(base) ((base) + 0x848UL)
#define SOC_MUDP_PIXRX_DEC_ERR_CTRL0_ADDR(base) ((base) + 0x860UL)
#define SOC_MUDP_PIXRX_DEC_ERR_CTRL1_ADDR(base) ((base) + 0x864UL)
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_ADDR(base) ((base) + 0x868UL)
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_ADDR(base) ((base) + 0x86CUL)
#define SOC_MUDP_PIXRX_CRG_RST_CTRL_ADDR(base) ((base) + 0x0900UL)
#define SOC_MUDP_PIXRX_CRG_CLK_SEL_ADDR(base) ((base) + 0x0904UL)
#define SOC_MUDP_PIXRX_CRG_CLK_AUTO_EN_ADDR(base) ((base) + 0x0908UL)
#define SOC_MUDP_PIXRX_CRG_CLK_STATUS_ADDR(base) ((base) + 0x090CUL)
#else
#define SOC_MUDP_PIXRX_CCH_CAP_ADDR(base) (base)
#define SOC_MUDP_PIXRX_CCH_INT_EN_ADDR(base) ((base) + 0x4)
#define SOC_MUDP_PIXRX_CCH_INT_ADDR(base) ((base) + 0x8)
#define SOC_MUDP_PIXRX_CCH_PRI_MODE_ADDR(base) ((base) + 0xC)
#define SOC_MUDP_PIXRX_CCH_EN_ADDR(base,ChNum) (base) + 0x10 + 0x40 * (ChNum)
#define SOC_MUDP_PIXRX_CMDBUF_BASE_L_ADDR(base,ChNum) (base) + 0x14 + 0x40 * (ChNum)
#define SOC_MUDP_PIXRX_CMDBUF_BASE_H_ADDR(base,ChNum) (base) + 0x18 + 0x40 * (ChNum)
#define SOC_MUDP_PIXRX_CMDBUF_LEN_ADDR(base,ChNum) (base) + 0x1C + 0x40 * (ChNum)
#define SOC_MUDP_PIXRX_CMDBUF_WADDR_ADDR(base,ChNum) (base) + 0x20 + 0x40 * (ChNum)
#define SOC_MUDP_PIXRX_CMDBUF_RADDR_ADDR(base,ChNum) (base) + 0x24 + 0x40 * (ChNum)
#define SOC_MUDP_PIXRX_RSPBUF_BASE_L_ADDR(base,ChNum) (base) + 0x28 + 0x40 * (ChNum)
#define SOC_MUDP_PIXRX_RSPBUF_BASE_H_ADDR(base,ChNum) (base) + 0x2C + 0x40 * (ChNum)
#define SOC_MUDP_PIXRX_RSPBUF_LEN_ADDR(base,ChNum) (base) + 0x30 + 0x40 * (ChNum)
#define SOC_MUDP_PIXRX_RSPBUF_ADDR_ADDR(base,ChNum) (base) + 0x34 + 0x40 * (ChNum)
#define SOC_MUDP_PIXRX_CMDBUF_INT_EN_ADDR(base,ChNum) (base) + 0x38 + 0x40 * (ChNum)
#define SOC_MUDP_PIXRX_CMDBUF_INT_STATUS_ADDR(base,ChNum) (base) + 0x3C + 0x40 * (ChNum)
#define SOC_MUDP_PIXRX_DBGBUF_BASE_L_ADDR(base) ((base) + 0x410)
#define SOC_MUDP_PIXRX_DBGBUF_BASE_H_ADDR(base) ((base) + 0x414)
#define SOC_MUDP_PIXRX_DBGBUF_LEN_ADDR(base) ((base) + 0x418)
#define SOC_MUDP_PIXRX_DEBUG_INT_EN_ADDR(base) ((base) + 0x41C)
#define SOC_MUDP_PIXRX_DEBUG_INT_ADDR(base) ((base) + 0x420)
#define SOC_MUDP_PIXRX_DBGBUF_ADDR_ADDR(base) ((base) + 0x424)
#define SOC_MUDP_PIXRX_INT_IBI_ADDR(base) ((base) + 0x428)
#define SOC_MUDP_PIXRX_INT_DRVIC_ADDR(base,RegNum) (base) + 0x42C + 0x4 * (RegNum)
#define SOC_MUDP_PIXRX_CCH_SYNC_SEND_EN_ADDR(base) ((base) + 0x490)
#define SOC_MUDP_PIXRX_TIMEOUT_THRSD_ADDR(base) ((base) + 0x494)
#define SOC_MUDP_PIXRX_TX_THRSD_ADDR(base) ((base) + 0x498)
#define SOC_MUDP_PIXRX_RSP_PARS_CTRL_ADDR(base) ((base) + 0x49C)
#define SOC_MUDP_PIXRX_CCH_RX_BUFF_ADDR(base) ((base) + 0x4A0)
#define SOC_MUDP_PIXRX_AXI_Master_axuser_ADDR(base) ((base) + 0x4A4)
#define SOC_MUDP_PIXRX_AXI_Master_QOS_ADDR(base) ((base) + 0x4AC)
#define SOC_MUDP_PIXRX_AXI_Master_pprot_ADDR(base) ((base) + 0x4B0)
#define SOC_MUDP_PIXRX_DEBUG_IRQ_ADDR(base) ((base) + 0x4B4)
#define SOC_MUDP_PIXRX_DEBUG_ALIGN192_ADDR(base) ((base) + 0x4B8)
#define SOC_MUDP_PIXRX_DEBUG_RSP_PARS_ADDR(base) ((base) + 0x4BC)
#define SOC_MUDP_PIXRX_DEBUG_AXI_WR_ADDR(base) ((base) + 0x4C0)
#define SOC_MUDP_PIXRX_DEBUG_CCH_RX_CTRL_ADDR(base) ((base) + 0x4C4)
#define SOC_MUDP_PIXRX_DEBUG_CCH_TX_CTRL_VC0_ADDR(base) ((base) + 0x4C8)
#define SOC_MUDP_PIXRX_DEBUG_CCH_TX_CTRL_VC1_ADDR(base) ((base) + 0x4CC)
#define SOC_MUDP_PIXRX_DEBUG_CCH_TX_RD_ADDR(base) ((base) + 0x4D0)
#define SOC_MUDP_PIXRX_DEBUG_CCH_TX_ARB_ADDR(base) ((base) + 0x4D4)
#define SOC_MUDP_PIXRX_DEBUG_CCH_ALIGN_32_ADDR(base) ((base) + 0x4D8)
#define SOC_MUDP_PIXRX_DEBUG_CCH_CMD_PARS_ADDR(base) ((base) + 0x4DC)
#define SOC_MUDP_PIXRX_PIX_CTRL_ADDR(base) ((base) + 0X700)
#define SOC_MUDP_PIXRX_PIX_SOURCE_ID_ADDR(base) ((base) + 0x704)
#define SOC_MUDP_PIXRX_CFG_DBG_PIX_TOTAL_FRAME_NUM_ADDR(base) ((base) + 0X708)
#define SOC_MUDP_PIXRX_CFG_DBG_PIX_TOTAL_PACKAGE_NUM_ADDR(base) ((base) + 0x70C)
#define SOC_MUDP_PIXRX_CFG_DBG_PIX_FRAME_FATAL_TYPE_0_ADDR(base) ((base) + 0x710)
#define SOC_MUDP_PIXRX_CFG_DBG_PIX_FRAME_FATAL_TYPE_1_ADDR(base) ((base) + 0x714)
#define SOC_MUDP_PIXRX_DEC_BUF_CTRL_ADDR(base) ((base) + 0x800)
#define SOC_MUDP_PIXRX_DEC_BUF_MEM_CTRL_ADDR(base) ((base) + 0x804)
#define SOC_MUDP_PIXRX_DEC_BUF_STATE_ADDR(base) ((base) + 0x808)
#define SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_CTRL0_ADDR(base) ((base) + 0x80C)
#define SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_CTRL1_ADDR(base) ((base) + 0x810)
#define SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_STATE1_ADDR(base) ((base) + 0x814)
#define SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_STATE0_ADDR(base) ((base) + 0x818)
#define SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_STATE2_ADDR(base) ((base) + 0x81C)
#define SOC_MUDP_PIXRX_DEC_HEBCD_POST_PROC_ADDR(base) ((base) + 0x820)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL0_ADDR(base) ((base) + 0x824)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL1_ADDR(base) ((base) + 0x828)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL2_ADDR(base) ((base) + 0x82C)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_STATE0_ADDR(base) ((base) + 0x830)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_STATE1_ADDR(base) ((base) + 0x834)
#define SOC_MUDP_PIXRX_DEC_HEBCD_CTRL0_ADDR(base) ((base) + 0x838)
#define SOC_MUDP_PIXRX_DEC_HEBCD_CTRL1_ADDR(base) ((base) + 0x83C)
#define SOC_MUDP_PIXRX_DEC_HEBCD_CTRL2_ADDR(base) ((base) + 0x840)
#define SOC_MUDP_PIXRX_DEC_HEBCD_DBG0_ADDR(base) ((base) + 0x844)
#define SOC_MUDP_PIXRX_DEC_HEBCD_DBG1_ADDR(base) ((base) + 0x848)
#define SOC_MUDP_PIXRX_DEC_ERR_CTRL0_ADDR(base) ((base) + 0x860)
#define SOC_MUDP_PIXRX_DEC_ERR_CTRL1_ADDR(base) ((base) + 0x864)
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_ADDR(base) ((base) + 0x868)
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_ADDR(base) ((base) + 0x86C)
#define SOC_MUDP_PIXRX_CRG_RST_CTRL_ADDR(base) ((base) + 0x0900)
#define SOC_MUDP_PIXRX_CRG_CLK_SEL_ADDR(base) ((base) + 0x0904)
#define SOC_MUDP_PIXRX_CRG_CLK_AUTO_EN_ADDR(base) ((base) + 0x0908)
#define SOC_MUDP_PIXRX_CRG_CLK_STATUS_ADDR(base) ((base) + 0x090C)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_cap0 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MUDP_PIXRX_CCH_CAP_UNION;
#endif
#define SOC_MUDP_PIXRX_CCH_CAP_cch_cap0_START (0)
#define SOC_MUDP_PIXRX_CCH_CAP_cch_cap0_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_int_cmd_done_enable : 1;
        unsigned int cch_int_cmd_err_enable : 1;
        unsigned int cch_int_interrupt_err_enable : 1;
        unsigned int cch_int_interrupt_receive_enable : 1;
        unsigned int pix_int_st_err_pld_line_num_enable : 1;
        unsigned int pix_int_st_err_pld_data_len_enable : 1;
        unsigned int pix_int_st_source_id_enable : 1;
        unsigned int pix_int_st_packet_header_crc_enable : 1;
        unsigned int pix_int_st_payload_crc_enable : 1;
        unsigned int pix_int_st_packet_dt_enable : 1;
        unsigned int pix_int_st_frame_number_nomatch_enable : 1;
        unsigned int pix_int_st_two_continuous_fend_enable : 1;
        unsigned int pix_int_st_two_continuous_fstart_enable : 1;
        unsigned int pix_int_st_frame_seq_enable : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_MUDP_PIXRX_CCH_INT_EN_UNION;
#endif
#define SOC_MUDP_PIXRX_CCH_INT_EN_cch_int_cmd_done_enable_START (0)
#define SOC_MUDP_PIXRX_CCH_INT_EN_cch_int_cmd_done_enable_END (0)
#define SOC_MUDP_PIXRX_CCH_INT_EN_cch_int_cmd_err_enable_START (1)
#define SOC_MUDP_PIXRX_CCH_INT_EN_cch_int_cmd_err_enable_END (1)
#define SOC_MUDP_PIXRX_CCH_INT_EN_cch_int_interrupt_err_enable_START (2)
#define SOC_MUDP_PIXRX_CCH_INT_EN_cch_int_interrupt_err_enable_END (2)
#define SOC_MUDP_PIXRX_CCH_INT_EN_cch_int_interrupt_receive_enable_START (3)
#define SOC_MUDP_PIXRX_CCH_INT_EN_cch_int_interrupt_receive_enable_END (3)
#define SOC_MUDP_PIXRX_CCH_INT_EN_pix_int_st_err_pld_line_num_enable_START (4)
#define SOC_MUDP_PIXRX_CCH_INT_EN_pix_int_st_err_pld_line_num_enable_END (4)
#define SOC_MUDP_PIXRX_CCH_INT_EN_pix_int_st_err_pld_data_len_enable_START (5)
#define SOC_MUDP_PIXRX_CCH_INT_EN_pix_int_st_err_pld_data_len_enable_END (5)
#define SOC_MUDP_PIXRX_CCH_INT_EN_pix_int_st_source_id_enable_START (6)
#define SOC_MUDP_PIXRX_CCH_INT_EN_pix_int_st_source_id_enable_END (6)
#define SOC_MUDP_PIXRX_CCH_INT_EN_pix_int_st_packet_header_crc_enable_START (7)
#define SOC_MUDP_PIXRX_CCH_INT_EN_pix_int_st_packet_header_crc_enable_END (7)
#define SOC_MUDP_PIXRX_CCH_INT_EN_pix_int_st_payload_crc_enable_START (8)
#define SOC_MUDP_PIXRX_CCH_INT_EN_pix_int_st_payload_crc_enable_END (8)
#define SOC_MUDP_PIXRX_CCH_INT_EN_pix_int_st_packet_dt_enable_START (9)
#define SOC_MUDP_PIXRX_CCH_INT_EN_pix_int_st_packet_dt_enable_END (9)
#define SOC_MUDP_PIXRX_CCH_INT_EN_pix_int_st_frame_number_nomatch_enable_START (10)
#define SOC_MUDP_PIXRX_CCH_INT_EN_pix_int_st_frame_number_nomatch_enable_END (10)
#define SOC_MUDP_PIXRX_CCH_INT_EN_pix_int_st_two_continuous_fend_enable_START (11)
#define SOC_MUDP_PIXRX_CCH_INT_EN_pix_int_st_two_continuous_fend_enable_END (11)
#define SOC_MUDP_PIXRX_CCH_INT_EN_pix_int_st_two_continuous_fstart_enable_START (12)
#define SOC_MUDP_PIXRX_CCH_INT_EN_pix_int_st_two_continuous_fstart_enable_END (12)
#define SOC_MUDP_PIXRX_CCH_INT_EN_pix_int_st_frame_seq_enable_START (13)
#define SOC_MUDP_PIXRX_CCH_INT_EN_pix_int_st_frame_seq_enable_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_int_cmd_done : 1;
        unsigned int cch_int_cmd_err : 1;
        unsigned int cch_int_interrupt_err : 1;
        unsigned int cch_int_interrupt_receive : 1;
        unsigned int pix_int_st_err_pld_line_num : 1;
        unsigned int pix_int_st_err_pld_data_len : 1;
        unsigned int pix_int_st_source_id : 1;
        unsigned int pix_int_st_packet_header_crc : 1;
        unsigned int pix_int_st_payload_crc : 1;
        unsigned int pix_int_st_packet_dt : 1;
        unsigned int pix_int_st_frame_number_nomatch : 1;
        unsigned int pix_int_st_two_continuous_fend : 1;
        unsigned int pix_int_st_two_continuous_fstart : 1;
        unsigned int pix_int_st_frame_seq : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_MUDP_PIXRX_CCH_INT_UNION;
#endif
#define SOC_MUDP_PIXRX_CCH_INT_cch_int_cmd_done_START (0)
#define SOC_MUDP_PIXRX_CCH_INT_cch_int_cmd_done_END (0)
#define SOC_MUDP_PIXRX_CCH_INT_cch_int_cmd_err_START (1)
#define SOC_MUDP_PIXRX_CCH_INT_cch_int_cmd_err_END (1)
#define SOC_MUDP_PIXRX_CCH_INT_cch_int_interrupt_err_START (2)
#define SOC_MUDP_PIXRX_CCH_INT_cch_int_interrupt_err_END (2)
#define SOC_MUDP_PIXRX_CCH_INT_cch_int_interrupt_receive_START (3)
#define SOC_MUDP_PIXRX_CCH_INT_cch_int_interrupt_receive_END (3)
#define SOC_MUDP_PIXRX_CCH_INT_pix_int_st_err_pld_line_num_START (4)
#define SOC_MUDP_PIXRX_CCH_INT_pix_int_st_err_pld_line_num_END (4)
#define SOC_MUDP_PIXRX_CCH_INT_pix_int_st_err_pld_data_len_START (5)
#define SOC_MUDP_PIXRX_CCH_INT_pix_int_st_err_pld_data_len_END (5)
#define SOC_MUDP_PIXRX_CCH_INT_pix_int_st_source_id_START (6)
#define SOC_MUDP_PIXRX_CCH_INT_pix_int_st_source_id_END (6)
#define SOC_MUDP_PIXRX_CCH_INT_pix_int_st_packet_header_crc_START (7)
#define SOC_MUDP_PIXRX_CCH_INT_pix_int_st_packet_header_crc_END (7)
#define SOC_MUDP_PIXRX_CCH_INT_pix_int_st_payload_crc_START (8)
#define SOC_MUDP_PIXRX_CCH_INT_pix_int_st_payload_crc_END (8)
#define SOC_MUDP_PIXRX_CCH_INT_pix_int_st_packet_dt_START (9)
#define SOC_MUDP_PIXRX_CCH_INT_pix_int_st_packet_dt_END (9)
#define SOC_MUDP_PIXRX_CCH_INT_pix_int_st_frame_number_nomatch_START (10)
#define SOC_MUDP_PIXRX_CCH_INT_pix_int_st_frame_number_nomatch_END (10)
#define SOC_MUDP_PIXRX_CCH_INT_pix_int_st_two_continuous_fend_START (11)
#define SOC_MUDP_PIXRX_CCH_INT_pix_int_st_two_continuous_fend_END (11)
#define SOC_MUDP_PIXRX_CCH_INT_pix_int_st_two_continuous_fstart_START (12)
#define SOC_MUDP_PIXRX_CCH_INT_pix_int_st_two_continuous_fstart_END (12)
#define SOC_MUDP_PIXRX_CCH_INT_pix_int_st_frame_seq_START (13)
#define SOC_MUDP_PIXRX_CCH_INT_pix_int_st_frame_seq_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_priority_mode : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MUDP_PIXRX_CCH_PRI_MODE_UNION;
#endif
#define SOC_MUDP_PIXRX_CCH_PRI_MODE_cch_priority_mode_START (0)
#define SOC_MUDP_PIXRX_CCH_PRI_MODE_cch_priority_mode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_buf_clr : 1;
        unsigned int cch_buf_en : 1;
        unsigned int cch_buf_int_mode : 1;
        unsigned int cch_buf_idle : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_MUDP_PIXRX_CCH_EN_UNION;
#endif
#define SOC_MUDP_PIXRX_CCH_EN_cch_buf_clr_START (0)
#define SOC_MUDP_PIXRX_CCH_EN_cch_buf_clr_END (0)
#define SOC_MUDP_PIXRX_CCH_EN_cch_buf_en_START (1)
#define SOC_MUDP_PIXRX_CCH_EN_cch_buf_en_END (1)
#define SOC_MUDP_PIXRX_CCH_EN_cch_buf_int_mode_START (2)
#define SOC_MUDP_PIXRX_CCH_EN_cch_buf_int_mode_END (2)
#define SOC_MUDP_PIXRX_CCH_EN_cch_buf_idle_START (3)
#define SOC_MUDP_PIXRX_CCH_EN_cch_buf_idle_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_cmdbuf_addr_l : 32;
    } reg;
} SOC_MUDP_PIXRX_CMDBUF_BASE_L_UNION;
#endif
#define SOC_MUDP_PIXRX_CMDBUF_BASE_L_cch_cmdbuf_addr_l_START (0)
#define SOC_MUDP_PIXRX_CMDBUF_BASE_L_cch_cmdbuf_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_cmdbuf_addr_h : 32;
    } reg;
} SOC_MUDP_PIXRX_CMDBUF_BASE_H_UNION;
#endif
#define SOC_MUDP_PIXRX_CMDBUF_BASE_H_cch_cmdbuf_addr_h_START (0)
#define SOC_MUDP_PIXRX_CMDBUF_BASE_H_cch_cmdbuf_addr_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_cmdbuf_length : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MUDP_PIXRX_CMDBUF_LEN_UNION;
#endif
#define SOC_MUDP_PIXRX_CMDBUF_LEN_cch_cmdbuf_length_START (0)
#define SOC_MUDP_PIXRX_CMDBUF_LEN_cch_cmdbuf_length_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_cmdbuf_waddr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MUDP_PIXRX_CMDBUF_WADDR_UNION;
#endif
#define SOC_MUDP_PIXRX_CMDBUF_WADDR_cch_cmdbuf_waddr_START (0)
#define SOC_MUDP_PIXRX_CMDBUF_WADDR_cch_cmdbuf_waddr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_cmdbuf_raddr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MUDP_PIXRX_CMDBUF_RADDR_UNION;
#endif
#define SOC_MUDP_PIXRX_CMDBUF_RADDR_cch_cmdbuf_raddr_START (0)
#define SOC_MUDP_PIXRX_CMDBUF_RADDR_cch_cmdbuf_raddr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_rspbuf_addr_l : 32;
    } reg;
} SOC_MUDP_PIXRX_RSPBUF_BASE_L_UNION;
#endif
#define SOC_MUDP_PIXRX_RSPBUF_BASE_L_cch_rspbuf_addr_l_START (0)
#define SOC_MUDP_PIXRX_RSPBUF_BASE_L_cch_rspbuf_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_rspbuf_addr_h : 32;
    } reg;
} SOC_MUDP_PIXRX_RSPBUF_BASE_H_UNION;
#endif
#define SOC_MUDP_PIXRX_RSPBUF_BASE_H_cch_rspbuf_addr_h_START (0)
#define SOC_MUDP_PIXRX_RSPBUF_BASE_H_cch_rspbuf_addr_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_rspbuf_length : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MUDP_PIXRX_RSPBUF_LEN_UNION;
#endif
#define SOC_MUDP_PIXRX_RSPBUF_LEN_cch_rspbuf_length_START (0)
#define SOC_MUDP_PIXRX_RSPBUF_LEN_cch_rspbuf_length_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_rspbuf_waddr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MUDP_PIXRX_RSPBUF_ADDR_UNION;
#endif
#define SOC_MUDP_PIXRX_RSPBUF_ADDR_cch_rspbuf_waddr_START (0)
#define SOC_MUDP_PIXRX_RSPBUF_ADDR_cch_rspbuf_waddr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_int_proc_status_enable : 1;
        unsigned int cch_int_rsppkt_pb_err_enable : 1;
        unsigned int cch_int_rsppkt_hpb_err_enable : 1;
        unsigned int cch_int_timeout_enable : 1;
        unsigned int cch_int_cmd_pars_err_enable : 1;
        unsigned int cch_int_cmd_os_of_enable : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_MUDP_PIXRX_CMDBUF_INT_EN_UNION;
#endif
#define SOC_MUDP_PIXRX_CMDBUF_INT_EN_cch_int_proc_status_enable_START (0)
#define SOC_MUDP_PIXRX_CMDBUF_INT_EN_cch_int_proc_status_enable_END (0)
#define SOC_MUDP_PIXRX_CMDBUF_INT_EN_cch_int_rsppkt_pb_err_enable_START (1)
#define SOC_MUDP_PIXRX_CMDBUF_INT_EN_cch_int_rsppkt_pb_err_enable_END (1)
#define SOC_MUDP_PIXRX_CMDBUF_INT_EN_cch_int_rsppkt_hpb_err_enable_START (2)
#define SOC_MUDP_PIXRX_CMDBUF_INT_EN_cch_int_rsppkt_hpb_err_enable_END (2)
#define SOC_MUDP_PIXRX_CMDBUF_INT_EN_cch_int_timeout_enable_START (3)
#define SOC_MUDP_PIXRX_CMDBUF_INT_EN_cch_int_timeout_enable_END (3)
#define SOC_MUDP_PIXRX_CMDBUF_INT_EN_cch_int_cmd_pars_err_enable_START (4)
#define SOC_MUDP_PIXRX_CMDBUF_INT_EN_cch_int_cmd_pars_err_enable_END (4)
#define SOC_MUDP_PIXRX_CMDBUF_INT_EN_cch_int_cmd_os_of_enable_START (5)
#define SOC_MUDP_PIXRX_CMDBUF_INT_EN_cch_int_cmd_os_of_enable_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_int_proc_status : 1;
        unsigned int cch_int_rsppkt_pb_err : 1;
        unsigned int cch_int_rsppkt_hpb_err : 1;
        unsigned int cch_int_timeout : 1;
        unsigned int cch_int_cmd_pars_err : 1;
        unsigned int cch_int_cmd_os_of : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_MUDP_PIXRX_CMDBUF_INT_STATUS_UNION;
#endif
#define SOC_MUDP_PIXRX_CMDBUF_INT_STATUS_cch_int_proc_status_START (0)
#define SOC_MUDP_PIXRX_CMDBUF_INT_STATUS_cch_int_proc_status_END (0)
#define SOC_MUDP_PIXRX_CMDBUF_INT_STATUS_cch_int_rsppkt_pb_err_START (1)
#define SOC_MUDP_PIXRX_CMDBUF_INT_STATUS_cch_int_rsppkt_pb_err_END (1)
#define SOC_MUDP_PIXRX_CMDBUF_INT_STATUS_cch_int_rsppkt_hpb_err_START (2)
#define SOC_MUDP_PIXRX_CMDBUF_INT_STATUS_cch_int_rsppkt_hpb_err_END (2)
#define SOC_MUDP_PIXRX_CMDBUF_INT_STATUS_cch_int_timeout_START (3)
#define SOC_MUDP_PIXRX_CMDBUF_INT_STATUS_cch_int_timeout_END (3)
#define SOC_MUDP_PIXRX_CMDBUF_INT_STATUS_cch_int_cmd_pars_err_START (4)
#define SOC_MUDP_PIXRX_CMDBUF_INT_STATUS_cch_int_cmd_pars_err_END (4)
#define SOC_MUDP_PIXRX_CMDBUF_INT_STATUS_cch_int_cmd_os_of_START (5)
#define SOC_MUDP_PIXRX_CMDBUF_INT_STATUS_cch_int_cmd_os_of_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_dbgbuf_addr_l : 32;
    } reg;
} SOC_MUDP_PIXRX_DBGBUF_BASE_L_UNION;
#endif
#define SOC_MUDP_PIXRX_DBGBUF_BASE_L_cch_dbgbuf_addr_l_START (0)
#define SOC_MUDP_PIXRX_DBGBUF_BASE_L_cch_dbgbuf_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_dbgbuf_addr_h : 32;
    } reg;
} SOC_MUDP_PIXRX_DBGBUF_BASE_H_UNION;
#endif
#define SOC_MUDP_PIXRX_DBGBUF_BASE_H_cch_dbgbuf_addr_h_START (0)
#define SOC_MUDP_PIXRX_DBGBUF_BASE_H_cch_dbgbuf_addr_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_dbgbuf_length : 16;
        unsigned int cch_dbgbuf_en : 1;
        unsigned int cch_dbgbuf_clr : 1;
        unsigned int cch_dbgbuf_idle : 1;
        unsigned int reserved : 13;
    } reg;
} SOC_MUDP_PIXRX_DBGBUF_LEN_UNION;
#endif
#define SOC_MUDP_PIXRX_DBGBUF_LEN_cch_dbgbuf_length_START (0)
#define SOC_MUDP_PIXRX_DBGBUF_LEN_cch_dbgbuf_length_END (15)
#define SOC_MUDP_PIXRX_DBGBUF_LEN_cch_dbgbuf_en_START (16)
#define SOC_MUDP_PIXRX_DBGBUF_LEN_cch_dbgbuf_en_END (16)
#define SOC_MUDP_PIXRX_DBGBUF_LEN_cch_dbgbuf_clr_START (17)
#define SOC_MUDP_PIXRX_DBGBUF_LEN_cch_dbgbuf_clr_END (17)
#define SOC_MUDP_PIXRX_DBGBUF_LEN_cch_dbgbuf_idle_START (18)
#define SOC_MUDP_PIXRX_DBGBUF_LEN_cch_dbgbuf_idle_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_int_hotjoin_enable : 1;
        unsigned int cch_int_ibi_enable : 1;
        unsigned int cch_int_drvic_enable : 1;
        unsigned int cch_int_dbg_enable : 1;
        unsigned int cch_int_intpkt_pb_err_enable : 1;
        unsigned int cch_int_intpkt_hpb_err_enable : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_MUDP_PIXRX_DEBUG_INT_EN_UNION;
#endif
#define SOC_MUDP_PIXRX_DEBUG_INT_EN_cch_int_hotjoin_enable_START (0)
#define SOC_MUDP_PIXRX_DEBUG_INT_EN_cch_int_hotjoin_enable_END (0)
#define SOC_MUDP_PIXRX_DEBUG_INT_EN_cch_int_ibi_enable_START (1)
#define SOC_MUDP_PIXRX_DEBUG_INT_EN_cch_int_ibi_enable_END (1)
#define SOC_MUDP_PIXRX_DEBUG_INT_EN_cch_int_drvic_enable_START (2)
#define SOC_MUDP_PIXRX_DEBUG_INT_EN_cch_int_drvic_enable_END (2)
#define SOC_MUDP_PIXRX_DEBUG_INT_EN_cch_int_dbg_enable_START (3)
#define SOC_MUDP_PIXRX_DEBUG_INT_EN_cch_int_dbg_enable_END (3)
#define SOC_MUDP_PIXRX_DEBUG_INT_EN_cch_int_intpkt_pb_err_enable_START (4)
#define SOC_MUDP_PIXRX_DEBUG_INT_EN_cch_int_intpkt_pb_err_enable_END (4)
#define SOC_MUDP_PIXRX_DEBUG_INT_EN_cch_int_intpkt_hpb_err_enable_START (5)
#define SOC_MUDP_PIXRX_DEBUG_INT_EN_cch_int_intpkt_hpb_err_enable_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_int_hotjoin : 1;
        unsigned int cch_int_ibi : 1;
        unsigned int cch_int_drvic : 1;
        unsigned int cch_int_dbg : 1;
        unsigned int cch_int_intpkt_pb_err : 1;
        unsigned int cch_int_intpkt_hpb_err : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_MUDP_PIXRX_DEBUG_INT_UNION;
#endif
#define SOC_MUDP_PIXRX_DEBUG_INT_cch_int_hotjoin_START (0)
#define SOC_MUDP_PIXRX_DEBUG_INT_cch_int_hotjoin_END (0)
#define SOC_MUDP_PIXRX_DEBUG_INT_cch_int_ibi_START (1)
#define SOC_MUDP_PIXRX_DEBUG_INT_cch_int_ibi_END (1)
#define SOC_MUDP_PIXRX_DEBUG_INT_cch_int_drvic_START (2)
#define SOC_MUDP_PIXRX_DEBUG_INT_cch_int_drvic_END (2)
#define SOC_MUDP_PIXRX_DEBUG_INT_cch_int_dbg_START (3)
#define SOC_MUDP_PIXRX_DEBUG_INT_cch_int_dbg_END (3)
#define SOC_MUDP_PIXRX_DEBUG_INT_cch_int_intpkt_pb_err_START (4)
#define SOC_MUDP_PIXRX_DEBUG_INT_cch_int_intpkt_pb_err_END (4)
#define SOC_MUDP_PIXRX_DEBUG_INT_cch_int_intpkt_hpb_err_START (5)
#define SOC_MUDP_PIXRX_DEBUG_INT_cch_int_intpkt_hpb_err_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_dbgbuf_waddr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MUDP_PIXRX_DBGBUF_ADDR_UNION;
#endif
#define SOC_MUDP_PIXRX_DBGBUF_ADDR_cch_dbgbuf_waddr_START (0)
#define SOC_MUDP_PIXRX_DBGBUF_ADDR_cch_dbgbuf_waddr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_ibi_data : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_MUDP_PIXRX_INT_IBI_UNION;
#endif
#define SOC_MUDP_PIXRX_INT_IBI_int_ibi_data_START (0)
#define SOC_MUDP_PIXRX_INT_IBI_int_ibi_data_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int int_drvic_data : 32;
    } reg;
} SOC_MUDP_PIXRX_INT_DRVIC_UNION;
#endif
#define SOC_MUDP_PIXRX_INT_DRVIC_int_drvic_data_START (0)
#define SOC_MUDP_PIXRX_INT_DRVIC_int_drvic_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_sync_send_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MUDP_PIXRX_CCH_SYNC_SEND_EN_UNION;
#endif
#define SOC_MUDP_PIXRX_CCH_SYNC_SEND_EN_cch_sync_send_en_START (0)
#define SOC_MUDP_PIXRX_CCH_SYNC_SEND_EN_cch_sync_send_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timeout_thrsd : 8;
        unsigned int sleep_delay : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_MUDP_PIXRX_TIMEOUT_THRSD_UNION;
#endif
#define SOC_MUDP_PIXRX_TIMEOUT_THRSD_timeout_thrsd_START (0)
#define SOC_MUDP_PIXRX_TIMEOUT_THRSD_timeout_thrsd_END (7)
#define SOC_MUDP_PIXRX_TIMEOUT_THRSD_sleep_delay_START (8)
#define SOC_MUDP_PIXRX_TIMEOUT_THRSD_sleep_delay_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_buff_afull_thrsd : 8;
        unsigned int tx_max_thrsd : 16;
        unsigned int reserved : 8;
    } reg;
} SOC_MUDP_PIXRX_TX_THRSD_UNION;
#endif
#define SOC_MUDP_PIXRX_TX_THRSD_rx_buff_afull_thrsd_START (0)
#define SOC_MUDP_PIXRX_TX_THRSD_rx_buff_afull_thrsd_END (7)
#define SOC_MUDP_PIXRX_TX_THRSD_tx_max_thrsd_START (8)
#define SOC_MUDP_PIXRX_TX_THRSD_tx_max_thrsd_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rs_dec_bypass : 1;
        unsigned int cch_cfg_err_sel : 1;
        unsigned int cch_int_err_sel : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_MUDP_PIXRX_RSP_PARS_CTRL_UNION;
#endif
#define SOC_MUDP_PIXRX_RSP_PARS_CTRL_rs_dec_bypass_START (0)
#define SOC_MUDP_PIXRX_RSP_PARS_CTRL_rs_dec_bypass_END (0)
#define SOC_MUDP_PIXRX_RSP_PARS_CTRL_cch_cfg_err_sel_START (1)
#define SOC_MUDP_PIXRX_RSP_PARS_CTRL_cch_cfg_err_sel_END (1)
#define SOC_MUDP_PIXRX_RSP_PARS_CTRL_cch_int_err_sel_START (2)
#define SOC_MUDP_PIXRX_RSP_PARS_CTRL_cch_int_err_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_mem_ctrl_bp_d1w2r : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_MUDP_PIXRX_CCH_RX_BUFF_UNION;
#endif
#define SOC_MUDP_PIXRX_CCH_RX_BUFF_cch_mem_ctrl_bp_d1w2r_START (0)
#define SOC_MUDP_PIXRX_CCH_RX_BUFF_cch_mem_ctrl_bp_d1w2r_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_axi_mst_axuser_awschint : 4;
        unsigned int cch_axi_mst_axuser_arschint : 4;
        unsigned int cch_axi_mst_axuser_aw_ptlasful : 1;
        unsigned int cch_axi_mst_axuser_ar_ptlasful : 1;
        unsigned int cch_axi_mst_axuser_awdomain : 2;
        unsigned int cch_axi_mst_axuser_ardomain : 2;
        unsigned int cch_axi_mst_axuser_awcache : 4;
        unsigned int cch_axi_mst_axuser_arcache : 4;
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 4;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_MUDP_PIXRX_AXI_Master_axuser_UNION;
#endif
#define SOC_MUDP_PIXRX_AXI_Master_axuser_cch_axi_mst_axuser_awschint_START (0)
#define SOC_MUDP_PIXRX_AXI_Master_axuser_cch_axi_mst_axuser_awschint_END (3)
#define SOC_MUDP_PIXRX_AXI_Master_axuser_cch_axi_mst_axuser_arschint_START (4)
#define SOC_MUDP_PIXRX_AXI_Master_axuser_cch_axi_mst_axuser_arschint_END (7)
#define SOC_MUDP_PIXRX_AXI_Master_axuser_cch_axi_mst_axuser_aw_ptlasful_START (8)
#define SOC_MUDP_PIXRX_AXI_Master_axuser_cch_axi_mst_axuser_aw_ptlasful_END (8)
#define SOC_MUDP_PIXRX_AXI_Master_axuser_cch_axi_mst_axuser_ar_ptlasful_START (9)
#define SOC_MUDP_PIXRX_AXI_Master_axuser_cch_axi_mst_axuser_ar_ptlasful_END (9)
#define SOC_MUDP_PIXRX_AXI_Master_axuser_cch_axi_mst_axuser_awdomain_START (10)
#define SOC_MUDP_PIXRX_AXI_Master_axuser_cch_axi_mst_axuser_awdomain_END (11)
#define SOC_MUDP_PIXRX_AXI_Master_axuser_cch_axi_mst_axuser_ardomain_START (12)
#define SOC_MUDP_PIXRX_AXI_Master_axuser_cch_axi_mst_axuser_ardomain_END (13)
#define SOC_MUDP_PIXRX_AXI_Master_axuser_cch_axi_mst_axuser_awcache_START (14)
#define SOC_MUDP_PIXRX_AXI_Master_axuser_cch_axi_mst_axuser_awcache_END (17)
#define SOC_MUDP_PIXRX_AXI_Master_axuser_cch_axi_mst_axuser_arcache_START (18)
#define SOC_MUDP_PIXRX_AXI_Master_axuser_cch_axi_mst_axuser_arcache_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_axi_mst_awqos : 4;
        unsigned int cch_axi_mst_arqos : 4;
        unsigned int cch_axi_mst_axuser_argid : 6;
        unsigned int cch_axi_mst_axuser_awgid : 6;
        unsigned int reserved : 12;
    } reg;
} SOC_MUDP_PIXRX_AXI_Master_QOS_UNION;
#endif
#define SOC_MUDP_PIXRX_AXI_Master_QOS_cch_axi_mst_awqos_START (0)
#define SOC_MUDP_PIXRX_AXI_Master_QOS_cch_axi_mst_awqos_END (3)
#define SOC_MUDP_PIXRX_AXI_Master_QOS_cch_axi_mst_arqos_START (4)
#define SOC_MUDP_PIXRX_AXI_Master_QOS_cch_axi_mst_arqos_END (7)
#define SOC_MUDP_PIXRX_AXI_Master_QOS_cch_axi_mst_axuser_argid_START (8)
#define SOC_MUDP_PIXRX_AXI_Master_QOS_cch_axi_mst_axuser_argid_END (13)
#define SOC_MUDP_PIXRX_AXI_Master_QOS_cch_axi_mst_axuser_awgid_START (14)
#define SOC_MUDP_PIXRX_AXI_Master_QOS_cch_axi_mst_axuser_awgid_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_axi_mst_prot : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MUDP_PIXRX_AXI_Master_pprot_UNION;
#endif
#define SOC_MUDP_PIXRX_AXI_Master_pprot_cch_axi_mst_prot_START (0)
#define SOC_MUDP_PIXRX_AXI_Master_pprot_cch_axi_mst_prot_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_debug_irq : 32;
    } reg;
} SOC_MUDP_PIXRX_DEBUG_IRQ_UNION;
#endif
#define SOC_MUDP_PIXRX_DEBUG_IRQ_cch_debug_irq_START (0)
#define SOC_MUDP_PIXRX_DEBUG_IRQ_cch_debug_irq_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_debug_align192 : 32;
    } reg;
} SOC_MUDP_PIXRX_DEBUG_ALIGN192_UNION;
#endif
#define SOC_MUDP_PIXRX_DEBUG_ALIGN192_cch_debug_align192_START (0)
#define SOC_MUDP_PIXRX_DEBUG_ALIGN192_cch_debug_align192_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_debug_rsp_pars : 32;
    } reg;
} SOC_MUDP_PIXRX_DEBUG_RSP_PARS_UNION;
#endif
#define SOC_MUDP_PIXRX_DEBUG_RSP_PARS_cch_debug_rsp_pars_START (0)
#define SOC_MUDP_PIXRX_DEBUG_RSP_PARS_cch_debug_rsp_pars_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_debug_axi_wr : 32;
    } reg;
} SOC_MUDP_PIXRX_DEBUG_AXI_WR_UNION;
#endif
#define SOC_MUDP_PIXRX_DEBUG_AXI_WR_cch_debug_axi_wr_START (0)
#define SOC_MUDP_PIXRX_DEBUG_AXI_WR_cch_debug_axi_wr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cch_debug_rx_ctrl : 32;
    } reg;
} SOC_MUDP_PIXRX_DEBUG_CCH_RX_CTRL_UNION;
#endif
#define SOC_MUDP_PIXRX_DEBUG_CCH_RX_CTRL_cch_debug_rx_ctrl_START (0)
#define SOC_MUDP_PIXRX_DEBUG_CCH_RX_CTRL_cch_debug_rx_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dbg_cch_txctrl_vc0 : 32;
    } reg;
} SOC_MUDP_PIXRX_DEBUG_CCH_TX_CTRL_VC0_UNION;
#endif
#define SOC_MUDP_PIXRX_DEBUG_CCH_TX_CTRL_VC0_cfg_dbg_cch_txctrl_vc0_START (0)
#define SOC_MUDP_PIXRX_DEBUG_CCH_TX_CTRL_VC0_cfg_dbg_cch_txctrl_vc0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dbg_cch_txctrl_vc1 : 32;
    } reg;
} SOC_MUDP_PIXRX_DEBUG_CCH_TX_CTRL_VC1_UNION;
#endif
#define SOC_MUDP_PIXRX_DEBUG_CCH_TX_CTRL_VC1_cfg_dbg_cch_txctrl_vc1_START (0)
#define SOC_MUDP_PIXRX_DEBUG_CCH_TX_CTRL_VC1_cfg_dbg_cch_txctrl_vc1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dbg_cch_txrd : 32;
    } reg;
} SOC_MUDP_PIXRX_DEBUG_CCH_TX_RD_UNION;
#endif
#define SOC_MUDP_PIXRX_DEBUG_CCH_TX_RD_cfg_dbg_cch_txrd_START (0)
#define SOC_MUDP_PIXRX_DEBUG_CCH_TX_RD_cfg_dbg_cch_txrd_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dbg_cch_txarb : 32;
    } reg;
} SOC_MUDP_PIXRX_DEBUG_CCH_TX_ARB_UNION;
#endif
#define SOC_MUDP_PIXRX_DEBUG_CCH_TX_ARB_cfg_dbg_cch_txarb_START (0)
#define SOC_MUDP_PIXRX_DEBUG_CCH_TX_ARB_cfg_dbg_cch_txarb_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_debug_align_32 : 32;
    } reg;
} SOC_MUDP_PIXRX_DEBUG_CCH_ALIGN_32_UNION;
#endif
#define SOC_MUDP_PIXRX_DEBUG_CCH_ALIGN_32_cfg_debug_align_32_START (0)
#define SOC_MUDP_PIXRX_DEBUG_CCH_ALIGN_32_cfg_debug_align_32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_debug_cmd_pars : 32;
    } reg;
} SOC_MUDP_PIXRX_DEBUG_CCH_CMD_PARS_UNION;
#endif
#define SOC_MUDP_PIXRX_DEBUG_CCH_CMD_PARS_cfg_debug_cmd_pars_START (0)
#define SOC_MUDP_PIXRX_DEBUG_CCH_CMD_PARS_cfg_debug_cmd_pars_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dbg_cnt_en : 1;
        unsigned int reserved_0 : 15;
        unsigned int soft_resetn : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_MUDP_PIXRX_PIX_CTRL_UNION;
#endif
#define SOC_MUDP_PIXRX_PIX_CTRL_cfg_dbg_cnt_en_START (0)
#define SOC_MUDP_PIXRX_PIX_CTRL_cfg_dbg_cnt_en_END (0)
#define SOC_MUDP_PIXRX_PIX_CTRL_soft_resetn_START (16)
#define SOC_MUDP_PIXRX_PIX_CTRL_soft_resetn_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int source_id : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_MUDP_PIXRX_PIX_SOURCE_ID_UNION;
#endif
#define SOC_MUDP_PIXRX_PIX_SOURCE_ID_source_id_START (0)
#define SOC_MUDP_PIXRX_PIX_SOURCE_ID_source_id_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dbg_total_frame_number : 32;
    } reg;
} SOC_MUDP_PIXRX_CFG_DBG_PIX_TOTAL_FRAME_NUM_UNION;
#endif
#define SOC_MUDP_PIXRX_CFG_DBG_PIX_TOTAL_FRAME_NUM_cfg_dbg_total_frame_number_START (0)
#define SOC_MUDP_PIXRX_CFG_DBG_PIX_TOTAL_FRAME_NUM_cfg_dbg_total_frame_number_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dbg_total_package_number : 32;
    } reg;
} SOC_MUDP_PIXRX_CFG_DBG_PIX_TOTAL_PACKAGE_NUM_UNION;
#endif
#define SOC_MUDP_PIXRX_CFG_DBG_PIX_TOTAL_PACKAGE_NUM_cfg_dbg_total_package_number_START (0)
#define SOC_MUDP_PIXRX_CFG_DBG_PIX_TOTAL_PACKAGE_NUM_cfg_dbg_total_package_number_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dbg_err_frame_num : 16;
        unsigned int cfg_dbg_err_channel_id : 6;
        unsigned int reserved : 10;
    } reg;
} SOC_MUDP_PIXRX_CFG_DBG_PIX_FRAME_FATAL_TYPE_0_UNION;
#endif
#define SOC_MUDP_PIXRX_CFG_DBG_PIX_FRAME_FATAL_TYPE_0_cfg_dbg_err_frame_num_START (0)
#define SOC_MUDP_PIXRX_CFG_DBG_PIX_FRAME_FATAL_TYPE_0_cfg_dbg_err_frame_num_END (15)
#define SOC_MUDP_PIXRX_CFG_DBG_PIX_FRAME_FATAL_TYPE_0_cfg_dbg_err_channel_id_START (16)
#define SOC_MUDP_PIXRX_CFG_DBG_PIX_FRAME_FATAL_TYPE_0_cfg_dbg_err_channel_id_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_dbg_err_line_num : 16;
        unsigned int cfg_dbg_err_msg_type : 2;
        unsigned int reserved : 14;
    } reg;
} SOC_MUDP_PIXRX_CFG_DBG_PIX_FRAME_FATAL_TYPE_1_UNION;
#endif
#define SOC_MUDP_PIXRX_CFG_DBG_PIX_FRAME_FATAL_TYPE_1_cfg_dbg_err_line_num_START (0)
#define SOC_MUDP_PIXRX_CFG_DBG_PIX_FRAME_FATAL_TYPE_1_cfg_dbg_err_line_num_END (15)
#define SOC_MUDP_PIXRX_CFG_DBG_PIX_FRAME_FATAL_TYPE_1_cfg_dbg_err_msg_type_START (16)
#define SOC_MUDP_PIXRX_CFG_DBG_PIX_FRAME_FATAL_TYPE_1_cfg_dbg_err_msg_type_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dec_buf_force_en : 1;
        unsigned int dec_buf_force_dis : 1;
        unsigned int dec_buf_force_clr : 1;
        unsigned int dec_buf_flush_en : 1;
        unsigned int dec_dt_cmp_code : 8;
        unsigned int split2hebcd_force_none : 1;
        unsigned int split2bypass_force_all : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_MUDP_PIXRX_DEC_BUF_CTRL_UNION;
#endif
#define SOC_MUDP_PIXRX_DEC_BUF_CTRL_dec_buf_force_en_START (0)
#define SOC_MUDP_PIXRX_DEC_BUF_CTRL_dec_buf_force_en_END (0)
#define SOC_MUDP_PIXRX_DEC_BUF_CTRL_dec_buf_force_dis_START (1)
#define SOC_MUDP_PIXRX_DEC_BUF_CTRL_dec_buf_force_dis_END (1)
#define SOC_MUDP_PIXRX_DEC_BUF_CTRL_dec_buf_force_clr_START (2)
#define SOC_MUDP_PIXRX_DEC_BUF_CTRL_dec_buf_force_clr_END (2)
#define SOC_MUDP_PIXRX_DEC_BUF_CTRL_dec_buf_flush_en_START (3)
#define SOC_MUDP_PIXRX_DEC_BUF_CTRL_dec_buf_flush_en_END (3)
#define SOC_MUDP_PIXRX_DEC_BUF_CTRL_dec_dt_cmp_code_START (4)
#define SOC_MUDP_PIXRX_DEC_BUF_CTRL_dec_dt_cmp_code_END (11)
#define SOC_MUDP_PIXRX_DEC_BUF_CTRL_split2hebcd_force_none_START (12)
#define SOC_MUDP_PIXRX_DEC_BUF_CTRL_split2hebcd_force_none_END (12)
#define SOC_MUDP_PIXRX_DEC_BUF_CTRL_split2bypass_force_all_START (13)
#define SOC_MUDP_PIXRX_DEC_BUF_CTRL_split2bypass_force_all_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dec_mem_ctrl_bp_d1w2r : 16;
        unsigned int dec_mem_ds_pre_wake_num : 8;
        unsigned int dec_mem_ds_auto_en : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_MUDP_PIXRX_DEC_BUF_MEM_CTRL_UNION;
#endif
#define SOC_MUDP_PIXRX_DEC_BUF_MEM_CTRL_dec_mem_ctrl_bp_d1w2r_START (0)
#define SOC_MUDP_PIXRX_DEC_BUF_MEM_CTRL_dec_mem_ctrl_bp_d1w2r_END (15)
#define SOC_MUDP_PIXRX_DEC_BUF_MEM_CTRL_dec_mem_ds_pre_wake_num_START (16)
#define SOC_MUDP_PIXRX_DEC_BUF_MEM_CTRL_dec_mem_ds_pre_wake_num_END (23)
#define SOC_MUDP_PIXRX_DEC_BUF_MEM_CTRL_dec_mem_ds_auto_en_START (24)
#define SOC_MUDP_PIXRX_DEC_BUF_MEM_CTRL_dec_mem_ds_auto_en_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dec_buf_state : 15;
        unsigned int reserved_0 : 1;
        unsigned int hend_buf_state : 11;
        unsigned int hebcd_chn_state : 1;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_MUDP_PIXRX_DEC_BUF_STATE_UNION;
#endif
#define SOC_MUDP_PIXRX_DEC_BUF_STATE_dec_buf_state_START (0)
#define SOC_MUDP_PIXRX_DEC_BUF_STATE_dec_buf_state_END (14)
#define SOC_MUDP_PIXRX_DEC_BUF_STATE_hend_buf_state_START (16)
#define SOC_MUDP_PIXRX_DEC_BUF_STATE_hend_buf_state_END (26)
#define SOC_MUDP_PIXRX_DEC_BUF_STATE_hebcd_chn_state_START (27)
#define SOC_MUDP_PIXRX_DEC_BUF_STATE_hebcd_chn_state_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int line_blk_num : 8;
        unsigned int hend_wait_time : 8;
        unsigned int blk_start_wait_time : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_CTRL0_UNION;
#endif
#define SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_CTRL0_line_blk_num_START (0)
#define SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_CTRL0_line_blk_num_END (7)
#define SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_CTRL0_hend_wait_time_START (8)
#define SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_CTRL0_hend_wait_time_END (15)
#define SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_CTRL0_blk_start_wait_time_START (16)
#define SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_CTRL0_blk_start_wait_time_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hvalid_wait_time : 16;
        unsigned int hvalid_wait_start_sel : 1;
        unsigned int hvalid_wait_end_sel : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_CTRL1_UNION;
#endif
#define SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_CTRL1_hvalid_wait_time_START (0)
#define SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_CTRL1_hvalid_wait_time_END (15)
#define SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_CTRL1_hvalid_wait_start_sel_START (16)
#define SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_CTRL1_hvalid_wait_start_sel_END (16)
#define SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_CTRL1_hvalid_wait_end_sel_START (17)
#define SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_CTRL1_hvalid_wait_end_sel_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_hsp_state1 : 32;
    } reg;
} SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_STATE1_UNION;
#endif
#define SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_STATE1_dbg_hsp_state1_START (0)
#define SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_STATE1_dbg_hsp_state1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_hsp_state0 : 32;
    } reg;
} SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_STATE0_UNION;
#endif
#define SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_STATE0_dbg_hsp_state0_START (0)
#define SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_STATE0_dbg_hsp_state0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_hsp_state : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_STATE2_UNION;
#endif
#define SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_STATE2_dbg_hsp_state_START (0)
#define SOC_MUDP_PIXRX_DEC_HEBCD_HEADER_STATE2_dbg_hsp_state_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bayer_format : 1;
        unsigned int line_patch_en : 1;
        unsigned int line_pixel_num : 15;
        unsigned int hebcd_hend_wait_time : 8;
        unsigned int reserved : 7;
    } reg;
} SOC_MUDP_PIXRX_DEC_HEBCD_POST_PROC_UNION;
#endif
#define SOC_MUDP_PIXRX_DEC_HEBCD_POST_PROC_bayer_format_START (0)
#define SOC_MUDP_PIXRX_DEC_HEBCD_POST_PROC_bayer_format_END (0)
#define SOC_MUDP_PIXRX_DEC_HEBCD_POST_PROC_line_patch_en_START (1)
#define SOC_MUDP_PIXRX_DEC_HEBCD_POST_PROC_line_patch_en_END (1)
#define SOC_MUDP_PIXRX_DEC_HEBCD_POST_PROC_line_pixel_num_START (2)
#define SOC_MUDP_PIXRX_DEC_HEBCD_POST_PROC_line_pixel_num_END (16)
#define SOC_MUDP_PIXRX_DEC_HEBCD_POST_PROC_hebcd_hend_wait_time_START (17)
#define SOC_MUDP_PIXRX_DEC_HEBCD_POST_PROC_hebcd_hend_wait_time_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int decout_vc_force_en : 1;
        unsigned int decout_vc_force : 4;
        unsigned int decout_dt_force_en : 1;
        unsigned int decout_dt_force : 6;
        unsigned int decout_vc_filter_en : 1;
        unsigned int decout_vc_filter : 7;
        unsigned int decout_dt_filter_en : 1;
        unsigned int decout_dt_filter : 8;
        unsigned int reserved : 3;
    } reg;
} SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL0_UNION;
#endif
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL0_decout_vc_force_en_START (0)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL0_decout_vc_force_en_END (0)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL0_decout_vc_force_START (1)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL0_decout_vc_force_END (4)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL0_decout_dt_force_en_START (5)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL0_decout_dt_force_en_END (5)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL0_decout_dt_force_START (6)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL0_decout_dt_force_END (11)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL0_decout_vc_filter_en_START (12)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL0_decout_vc_filter_en_END (12)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL0_decout_vc_filter_START (13)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL0_decout_vc_filter_END (19)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL0_decout_dt_filter_en_START (20)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL0_decout_dt_filter_en_END (20)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL0_decout_dt_filter_START (21)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL0_decout_dt_filter_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int raw08_cmp_dt_code : 8;
        unsigned int raw10_cmp_dt_code : 8;
        unsigned int raw12_cmp_dt_code : 8;
        unsigned int raw14_cmp_dt_code : 8;
    } reg;
} SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL1_UNION;
#endif
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL1_raw08_cmp_dt_code_START (0)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL1_raw08_cmp_dt_code_END (7)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL1_raw10_cmp_dt_code_START (8)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL1_raw10_cmp_dt_code_END (15)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL1_raw12_cmp_dt_code_START (16)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL1_raw12_cmp_dt_code_END (23)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL1_raw14_cmp_dt_code_START (24)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL1_raw14_cmp_dt_code_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int raw08_dt_code : 6;
        unsigned int raw10_dt_code : 6;
        unsigned int raw12_dt_code : 6;
        unsigned int raw14_dt_code : 6;
        unsigned int reserved : 8;
    } reg;
} SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL2_UNION;
#endif
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL2_raw08_dt_code_START (0)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL2_raw08_dt_code_END (5)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL2_raw10_dt_code_START (6)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL2_raw10_dt_code_END (11)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL2_raw12_dt_code_START (12)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL2_raw12_dt_code_END (17)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL2_raw14_dt_code_START (18)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_CTRL2_raw14_dt_code_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_decout_vvalid : 16;
        unsigned int dbg_decout_hvalid : 16;
    } reg;
} SOC_MUDP_PIXRX_DEC_PIX2BYTE_STATE0_UNION;
#endif
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_STATE0_dbg_decout_vvalid_START (0)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_STATE0_dbg_decout_vvalid_END (15)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_STATE0_dbg_decout_hvalid_START (16)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_STATE0_dbg_decout_hvalid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_pix2byte_state : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_MUDP_PIXRX_DEC_PIX2BYTE_STATE1_UNION;
#endif
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_STATE1_dbg_pix2byte_state_START (0)
#define SOC_MUDP_PIXRX_DEC_PIX2BYTE_STATE1_dbg_pix2byte_state_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int raw08_hebcd_code : 9;
        unsigned int raw10_hebcd_code : 9;
        unsigned int raw12_hebcd_code : 9;
        unsigned int reserved : 5;
    } reg;
} SOC_MUDP_PIXRX_DEC_HEBCD_CTRL0_UNION;
#endif
#define SOC_MUDP_PIXRX_DEC_HEBCD_CTRL0_raw08_hebcd_code_START (0)
#define SOC_MUDP_PIXRX_DEC_HEBCD_CTRL0_raw08_hebcd_code_END (8)
#define SOC_MUDP_PIXRX_DEC_HEBCD_CTRL0_raw10_hebcd_code_START (9)
#define SOC_MUDP_PIXRX_DEC_HEBCD_CTRL0_raw10_hebcd_code_END (17)
#define SOC_MUDP_PIXRX_DEC_HEBCD_CTRL0_raw12_hebcd_code_START (18)
#define SOC_MUDP_PIXRX_DEC_HEBCD_CTRL0_raw12_hebcd_code_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int raw14_hebcd_code : 9;
        unsigned int hebcd_dt_force_en : 1;
        unsigned int hebcd_dt_force : 9;
        unsigned int hebcd_auto_clk_gt_en : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_MUDP_PIXRX_DEC_HEBCD_CTRL1_UNION;
#endif
#define SOC_MUDP_PIXRX_DEC_HEBCD_CTRL1_raw14_hebcd_code_START (0)
#define SOC_MUDP_PIXRX_DEC_HEBCD_CTRL1_raw14_hebcd_code_END (8)
#define SOC_MUDP_PIXRX_DEC_HEBCD_CTRL1_hebcd_dt_force_en_START (9)
#define SOC_MUDP_PIXRX_DEC_HEBCD_CTRL1_hebcd_dt_force_en_END (9)
#define SOC_MUDP_PIXRX_DEC_HEBCD_CTRL1_hebcd_dt_force_START (10)
#define SOC_MUDP_PIXRX_DEC_HEBCD_CTRL1_hebcd_dt_force_END (18)
#define SOC_MUDP_PIXRX_DEC_HEBCD_CTRL1_hebcd_auto_clk_gt_en_START (19)
#define SOC_MUDP_PIXRX_DEC_HEBCD_CTRL1_hebcd_auto_clk_gt_en_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hebcd_cmp_reserved : 32;
    } reg;
} SOC_MUDP_PIXRX_DEC_HEBCD_CTRL2_UNION;
#endif
#define SOC_MUDP_PIXRX_DEC_HEBCD_CTRL2_hebcd_cmp_reserved_START (0)
#define SOC_MUDP_PIXRX_DEC_HEBCD_CTRL2_hebcd_cmp_reserved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hebcd_dbg_out0 : 32;
    } reg;
} SOC_MUDP_PIXRX_DEC_HEBCD_DBG0_UNION;
#endif
#define SOC_MUDP_PIXRX_DEC_HEBCD_DBG0_hebcd_dbg_out0_START (0)
#define SOC_MUDP_PIXRX_DEC_HEBCD_DBG0_hebcd_dbg_out0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hebcd_dbg_out1 : 32;
    } reg;
} SOC_MUDP_PIXRX_DEC_HEBCD_DBG1_UNION;
#endif
#define SOC_MUDP_PIXRX_DEC_HEBCD_DBG1_hebcd_dbg_out1_START (0)
#define SOC_MUDP_PIXRX_DEC_HEBCD_DBG1_hebcd_dbg_out1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dec_err_req_clr_mask : 16;
        unsigned int dec_err_req_patch_mask : 16;
    } reg;
} SOC_MUDP_PIXRX_DEC_ERR_CTRL0_UNION;
#endif
#define SOC_MUDP_PIXRX_DEC_ERR_CTRL0_dec_err_req_clr_mask_START (0)
#define SOC_MUDP_PIXRX_DEC_ERR_CTRL0_dec_err_req_clr_mask_END (15)
#define SOC_MUDP_PIXRX_DEC_ERR_CTRL0_dec_err_req_patch_mask_START (16)
#define SOC_MUDP_PIXRX_DEC_ERR_CTRL0_dec_err_req_patch_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dec_err_req_flush_mask : 16;
        unsigned int dec_req_clr : 1;
        unsigned int dec_req_patch : 1;
        unsigned int dec_req_flush : 1;
        unsigned int reserved : 13;
    } reg;
} SOC_MUDP_PIXRX_DEC_ERR_CTRL1_UNION;
#endif
#define SOC_MUDP_PIXRX_DEC_ERR_CTRL1_dec_err_req_flush_mask_START (0)
#define SOC_MUDP_PIXRX_DEC_ERR_CTRL1_dec_err_req_flush_mask_END (15)
#define SOC_MUDP_PIXRX_DEC_ERR_CTRL1_dec_req_clr_START (16)
#define SOC_MUDP_PIXRX_DEC_ERR_CTRL1_dec_req_clr_END (16)
#define SOC_MUDP_PIXRX_DEC_ERR_CTRL1_dec_req_patch_START (17)
#define SOC_MUDP_PIXRX_DEC_ERR_CTRL1_dec_req_patch_END (17)
#define SOC_MUDP_PIXRX_DEC_ERR_CTRL1_dec_req_flush_START (18)
#define SOC_MUDP_PIXRX_DEC_ERR_CTRL1_dec_req_flush_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dec_int_hebcd_dt_err_enable : 1;
        unsigned int dec_int_hebcd_hend_wait_timeout_enable : 1;
        unsigned int dec_int_hebcd_blk_pixel_num_err_enable : 1;
        unsigned int dec_int_buf_full_enable : 1;
        unsigned int dec_int_hend_buf_full_enable : 1;
        unsigned int dec_int_hend_wait_timeout_enable : 1;
        unsigned int dec_int_blk_start_timeout_enable : 1;
        unsigned int dec_int_hvalid_wait_timeout_enable : 1;
        unsigned int dec_int_hsp_buf_empty_err_enable : 1;
        unsigned int dec_int_hsp_blk_end_buf_err_enable : 1;
        unsigned int dec_int_hebcd_decmp_err0_enable : 1;
        unsigned int dec_int_hebcd_decmp_err1_enable : 1;
        unsigned int dec_int_hebcd_decmp_err2_enable : 1;
        unsigned int dec_int_hebcd_decmp_err3_enable : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_MUDP_PIXRX_DEC_INTR_ENABLE_UNION;
#endif
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_dec_int_hebcd_dt_err_enable_START (0)
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_dec_int_hebcd_dt_err_enable_END (0)
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_dec_int_hebcd_hend_wait_timeout_enable_START (1)
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_dec_int_hebcd_hend_wait_timeout_enable_END (1)
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_dec_int_hebcd_blk_pixel_num_err_enable_START (2)
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_dec_int_hebcd_blk_pixel_num_err_enable_END (2)
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_dec_int_buf_full_enable_START (3)
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_dec_int_buf_full_enable_END (3)
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_dec_int_hend_buf_full_enable_START (4)
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_dec_int_hend_buf_full_enable_END (4)
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_dec_int_hend_wait_timeout_enable_START (5)
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_dec_int_hend_wait_timeout_enable_END (5)
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_dec_int_blk_start_timeout_enable_START (6)
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_dec_int_blk_start_timeout_enable_END (6)
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_dec_int_hvalid_wait_timeout_enable_START (7)
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_dec_int_hvalid_wait_timeout_enable_END (7)
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_dec_int_hsp_buf_empty_err_enable_START (8)
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_dec_int_hsp_buf_empty_err_enable_END (8)
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_dec_int_hsp_blk_end_buf_err_enable_START (9)
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_dec_int_hsp_blk_end_buf_err_enable_END (9)
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_dec_int_hebcd_decmp_err0_enable_START (10)
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_dec_int_hebcd_decmp_err0_enable_END (10)
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_dec_int_hebcd_decmp_err1_enable_START (11)
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_dec_int_hebcd_decmp_err1_enable_END (11)
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_dec_int_hebcd_decmp_err2_enable_START (12)
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_dec_int_hebcd_decmp_err2_enable_END (12)
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_dec_int_hebcd_decmp_err3_enable_START (13)
#define SOC_MUDP_PIXRX_DEC_INTR_ENABLE_dec_int_hebcd_decmp_err3_enable_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dec_int_hebcd_dt_err : 1;
        unsigned int dec_int_hebcd_hend_wait_timeout : 1;
        unsigned int dec_int_hebcd_blk_pixel_num_err : 1;
        unsigned int dec_int_buf_full : 1;
        unsigned int dec_int_hend_buf_full : 1;
        unsigned int dec_int_hend_wait_timeout : 1;
        unsigned int dec_int_blk_start_timeout : 1;
        unsigned int dec_int_hvalid_wait_timeout : 1;
        unsigned int dec_int_hsp_buf_empty_err : 1;
        unsigned int dec_int_hsp_blk_end_buf_err : 1;
        unsigned int dec_int_hebcd_decmp_err0 : 1;
        unsigned int dec_int_hebcd_decmp_err1 : 1;
        unsigned int dec_int_hebcd_decmp_err2 : 1;
        unsigned int dec_int_hebcd_decmp_err3 : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_UNION;
#endif
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_dec_int_hebcd_dt_err_START (0)
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_dec_int_hebcd_dt_err_END (0)
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_dec_int_hebcd_hend_wait_timeout_START (1)
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_dec_int_hebcd_hend_wait_timeout_END (1)
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_dec_int_hebcd_blk_pixel_num_err_START (2)
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_dec_int_hebcd_blk_pixel_num_err_END (2)
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_dec_int_buf_full_START (3)
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_dec_int_buf_full_END (3)
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_dec_int_hend_buf_full_START (4)
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_dec_int_hend_buf_full_END (4)
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_dec_int_hend_wait_timeout_START (5)
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_dec_int_hend_wait_timeout_END (5)
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_dec_int_blk_start_timeout_START (6)
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_dec_int_blk_start_timeout_END (6)
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_dec_int_hvalid_wait_timeout_START (7)
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_dec_int_hvalid_wait_timeout_END (7)
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_dec_int_hsp_buf_empty_err_START (8)
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_dec_int_hsp_buf_empty_err_END (8)
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_dec_int_hsp_blk_end_buf_err_START (9)
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_dec_int_hsp_blk_end_buf_err_END (9)
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_dec_int_hebcd_decmp_err0_START (10)
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_dec_int_hebcd_decmp_err0_END (10)
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_dec_int_hebcd_decmp_err1_START (11)
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_dec_int_hebcd_decmp_err1_END (11)
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_dec_int_hebcd_decmp_err2_START (12)
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_dec_int_hebcd_decmp_err2_END (12)
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_dec_int_hebcd_decmp_err3_START (13)
#define SOC_MUDP_PIXRX_DEC_ORI_INTR_STATUS_dec_int_hebcd_decmp_err3_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rst_cch_n : 1;
        unsigned int rst_unp_n : 1;
        unsigned int rst_dec_n : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_MUDP_PIXRX_CRG_RST_CTRL_UNION;
#endif
#define SOC_MUDP_PIXRX_CRG_RST_CTRL_rst_cch_n_START (0)
#define SOC_MUDP_PIXRX_CRG_RST_CTRL_rst_cch_n_END (0)
#define SOC_MUDP_PIXRX_CRG_RST_CTRL_rst_unp_n_START (1)
#define SOC_MUDP_PIXRX_CRG_RST_CTRL_rst_unp_n_END (1)
#define SOC_MUDP_PIXRX_CRG_RST_CTRL_rst_dec_n_START (2)
#define SOC_MUDP_PIXRX_CRG_RST_CTRL_rst_dec_n_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk_sel_cch : 1;
        unsigned int clk_sel_unp : 1;
        unsigned int clk_sel_dec : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_MUDP_PIXRX_CRG_CLK_SEL_UNION;
#endif
#define SOC_MUDP_PIXRX_CRG_CLK_SEL_clk_sel_cch_START (0)
#define SOC_MUDP_PIXRX_CRG_CLK_SEL_clk_sel_cch_END (0)
#define SOC_MUDP_PIXRX_CRG_CLK_SEL_clk_sel_unp_START (1)
#define SOC_MUDP_PIXRX_CRG_CLK_SEL_clk_sel_unp_END (1)
#define SOC_MUDP_PIXRX_CRG_CLK_SEL_clk_sel_dec_START (2)
#define SOC_MUDP_PIXRX_CRG_CLK_SEL_clk_sel_dec_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int auto_clk_en_cch : 1;
        unsigned int auto_clk_en_unp : 1;
        unsigned int auto_clk_en_dec : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_MUDP_PIXRX_CRG_CLK_AUTO_EN_UNION;
#endif
#define SOC_MUDP_PIXRX_CRG_CLK_AUTO_EN_auto_clk_en_cch_START (0)
#define SOC_MUDP_PIXRX_CRG_CLK_AUTO_EN_auto_clk_en_cch_END (0)
#define SOC_MUDP_PIXRX_CRG_CLK_AUTO_EN_auto_clk_en_unp_START (1)
#define SOC_MUDP_PIXRX_CRG_CLK_AUTO_EN_auto_clk_en_unp_END (1)
#define SOC_MUDP_PIXRX_CRG_CLK_AUTO_EN_auto_clk_en_dec_START (2)
#define SOC_MUDP_PIXRX_CRG_CLK_AUTO_EN_auto_clk_en_dec_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk_status_cch : 1;
        unsigned int clk_status_unp : 1;
        unsigned int clk_status_dec : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_MUDP_PIXRX_CRG_CLK_STATUS_UNION;
#endif
#define SOC_MUDP_PIXRX_CRG_CLK_STATUS_clk_status_cch_START (0)
#define SOC_MUDP_PIXRX_CRG_CLK_STATUS_clk_status_cch_END (0)
#define SOC_MUDP_PIXRX_CRG_CLK_STATUS_clk_status_unp_START (1)
#define SOC_MUDP_PIXRX_CRG_CLK_STATUS_clk_status_unp_END (1)
#define SOC_MUDP_PIXRX_CRG_CLK_STATUS_clk_status_dec_START (2)
#define SOC_MUDP_PIXRX_CRG_CLK_STATUS_clk_status_dec_END (2)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
