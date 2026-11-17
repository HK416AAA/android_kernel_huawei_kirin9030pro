#ifndef __SOC_QICE_QSP2TO1_WA_TOP_WRAP_INTERFACE_H__
#define __SOC_QICE_QSP2TO1_WA_TOP_WRAP_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_VC_PRI_ADDR(base) ((base) + 0x0400UL)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_CKG_CTRL_ADDR(base) ((base) + 0x0404UL)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_SUB_MODULE_BUSY_ADDR(base) ((base) + 0x0408UL)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_BUSY_ADDR(base) ((base) + 0x040CUL)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_QSP0_REQ_RX_STATE_ADDR(base) ((base) + 0x0410UL)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_QSP1_REQ_RX_STATE_ADDR(base) ((base) + 0x0414UL)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP0_REQ_RX_STATE_ADDR(base) ((base) + 0x0418UL)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP1_REQ_RX_STATE_ADDR(base) ((base) + 0x041CUL)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP0_RSP_RX_DWR_BUSY_ADDR(base) ((base) + 0x0420UL)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP1_RSP_RX_DWR_BUSY_ADDR(base) ((base) + 0x0424UL)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_QSP_M_REQ_TX_CRD_CNT_ADDR(base) ((base) + 0x0428UL)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_QSP_M_REQ_TX_BUSY_ADDR(base) ((base) + 0x042CUL)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_QSP_M_RSP_RX_STATE_ADDR(base) ((base) + 0x0430UL)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_RSP_BUF_STATE_ADDR(base) ((base) + 0x0434UL)
#else
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_VC_PRI_ADDR(base) ((base) + 0x0400)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_CKG_CTRL_ADDR(base) ((base) + 0x0404)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_SUB_MODULE_BUSY_ADDR(base) ((base) + 0x0408)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_BUSY_ADDR(base) ((base) + 0x040C)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_QSP0_REQ_RX_STATE_ADDR(base) ((base) + 0x0410)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_QSP1_REQ_RX_STATE_ADDR(base) ((base) + 0x0414)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP0_REQ_RX_STATE_ADDR(base) ((base) + 0x0418)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP1_REQ_RX_STATE_ADDR(base) ((base) + 0x041C)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP0_RSP_RX_DWR_BUSY_ADDR(base) ((base) + 0x0420)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP1_RSP_RX_DWR_BUSY_ADDR(base) ((base) + 0x0424)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_QSP_M_REQ_TX_CRD_CNT_ADDR(base) ((base) + 0x0428)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_QSP_M_REQ_TX_BUSY_ADDR(base) ((base) + 0x042C)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_QSP_M_RSP_RX_STATE_ADDR(base) ((base) + 0x0430)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_RSP_BUF_STATE_ADDR(base) ((base) + 0x0434)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vc0_pri : 2;
        unsigned int reserved_0: 2;
        unsigned int vc1_pri : 2;
        unsigned int reserved_1: 2;
        unsigned int vc2_pri : 2;
        unsigned int reserved_2: 2;
        unsigned int vc3_pri : 2;
        unsigned int reserved_3: 18;
    } reg;
} SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_VC_PRI_UNION;
#endif
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_VC_PRI_vc0_pri_START (0)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_VC_PRI_vc0_pri_END (1)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_VC_PRI_vc1_pri_START (4)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_VC_PRI_vc1_pri_END (5)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_VC_PRI_vc2_pri_START (8)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_VC_PRI_vc2_pri_END (9)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_VC_PRI_vc3_pri_START (12)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_VC_PRI_vc3_pri_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ckg_rs_byp_qsp1_req_rx_rdy : 1;
        unsigned int ckg_rs_byp_qsp0_rsp_tx_rdy : 1;
        unsigned int ckg_rs_byp_qsp1_rsp_tx_rdy : 1;
        unsigned int ckg_rs_byp_qsp2to1_rsp_rx_rdy : 1;
        unsigned int ckg_byp_top_req : 1;
        unsigned int ckg_byp_top_rsp : 1;
        unsigned int ckg_byp_qsp0_req : 1;
        unsigned int ckg_byp_qsp0_rsp : 1;
        unsigned int ckg_byp_qsp1_req : 1;
        unsigned int ckg_byp_qsp1_rsp : 1;
        unsigned int reserved : 21;
        unsigned int ckg_ext_ena : 1;
    } reg;
} SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_CKG_CTRL_UNION;
#endif
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_CKG_CTRL_ckg_rs_byp_qsp1_req_rx_rdy_START (0)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_CKG_CTRL_ckg_rs_byp_qsp1_req_rx_rdy_END (0)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_CKG_CTRL_ckg_rs_byp_qsp0_rsp_tx_rdy_START (1)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_CKG_CTRL_ckg_rs_byp_qsp0_rsp_tx_rdy_END (1)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_CKG_CTRL_ckg_rs_byp_qsp1_rsp_tx_rdy_START (2)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_CKG_CTRL_ckg_rs_byp_qsp1_rsp_tx_rdy_END (2)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_CKG_CTRL_ckg_rs_byp_qsp2to1_rsp_rx_rdy_START (3)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_CKG_CTRL_ckg_rs_byp_qsp2to1_rsp_rx_rdy_END (3)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_CKG_CTRL_ckg_byp_top_req_START (4)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_CKG_CTRL_ckg_byp_top_req_END (4)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_CKG_CTRL_ckg_byp_top_rsp_START (5)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_CKG_CTRL_ckg_byp_top_rsp_END (5)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_CKG_CTRL_ckg_byp_qsp0_req_START (6)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_CKG_CTRL_ckg_byp_qsp0_req_END (6)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_CKG_CTRL_ckg_byp_qsp0_rsp_START (7)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_CKG_CTRL_ckg_byp_qsp0_rsp_END (7)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_CKG_CTRL_ckg_byp_qsp1_req_START (8)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_CKG_CTRL_ckg_byp_qsp1_req_END (8)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_CKG_CTRL_ckg_byp_qsp1_rsp_START (9)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_CKG_CTRL_ckg_byp_qsp1_rsp_END (9)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_CKG_CTRL_ckg_ext_ena_START (31)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_CKG_CTRL_ckg_ext_ena_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wa_qsp0_req_busy : 1;
        unsigned int wa_qsp1_req_busy : 1;
        unsigned int wa_qsp0_rsp_busy : 1;
        unsigned int wa_qsp1_rsp_busy : 1;
        unsigned int qsp2to1_qsp0_req_busy : 1;
        unsigned int qsp2to1_qsp1_req_busy : 1;
        unsigned int qsp2to1_qsp0_rsp_busy : 1;
        unsigned int qsp2to1_qsp1_rsp_busy : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_SUB_MODULE_BUSY_UNION;
#endif
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_SUB_MODULE_BUSY_wa_qsp0_req_busy_START (0)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_SUB_MODULE_BUSY_wa_qsp0_req_busy_END (0)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_SUB_MODULE_BUSY_wa_qsp1_req_busy_START (1)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_SUB_MODULE_BUSY_wa_qsp1_req_busy_END (1)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_SUB_MODULE_BUSY_wa_qsp0_rsp_busy_START (2)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_SUB_MODULE_BUSY_wa_qsp0_rsp_busy_END (2)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_SUB_MODULE_BUSY_wa_qsp1_rsp_busy_START (3)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_SUB_MODULE_BUSY_wa_qsp1_rsp_busy_END (3)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_SUB_MODULE_BUSY_qsp2to1_qsp0_req_busy_START (4)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_SUB_MODULE_BUSY_qsp2to1_qsp0_req_busy_END (4)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_SUB_MODULE_BUSY_qsp2to1_qsp1_req_busy_START (5)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_SUB_MODULE_BUSY_qsp2to1_qsp1_req_busy_END (5)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_SUB_MODULE_BUSY_qsp2to1_qsp0_rsp_busy_START (6)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_SUB_MODULE_BUSY_qsp2to1_qsp0_rsp_busy_END (6)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_SUB_MODULE_BUSY_qsp2to1_qsp1_rsp_busy_START (7)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_SUB_MODULE_BUSY_qsp2to1_qsp1_rsp_busy_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qsp2to1_wa_top_wrap_busy : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_BUSY_UNION;
#endif
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_BUSY_qsp2to1_wa_top_wrap_busy_START (0)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_BUSY_qsp2to1_wa_top_wrap_busy_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qsp2to1_qsp0_req_rx_fifo_empty_n : 4;
        unsigned int qsp2to1_qsp0_req_rx_fifo_full : 4;
        unsigned int qsp2to1_qsp0_req_rx_crd_initial : 4;
        unsigned int qsp2to1_qsp0_req_rx_busy : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_QSP0_REQ_RX_STATE_UNION;
#endif
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_QSP0_REQ_RX_STATE_qsp2to1_qsp0_req_rx_fifo_empty_n_START (0)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_QSP0_REQ_RX_STATE_qsp2to1_qsp0_req_rx_fifo_empty_n_END (3)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_QSP0_REQ_RX_STATE_qsp2to1_qsp0_req_rx_fifo_full_START (4)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_QSP0_REQ_RX_STATE_qsp2to1_qsp0_req_rx_fifo_full_END (7)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_QSP0_REQ_RX_STATE_qsp2to1_qsp0_req_rx_crd_initial_START (8)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_QSP0_REQ_RX_STATE_qsp2to1_qsp0_req_rx_crd_initial_END (11)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_QSP0_REQ_RX_STATE_qsp2to1_qsp0_req_rx_busy_START (12)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_QSP0_REQ_RX_STATE_qsp2to1_qsp0_req_rx_busy_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qsp2to1_qsp1_req_rx_fifo_empty_n : 4;
        unsigned int qsp2to1_qsp1_req_rx_fifo_full : 4;
        unsigned int qsp2to1_qsp1_req_rx_crd_initial : 4;
        unsigned int qsp2to1_qsp1_req_rx_busy : 4;
        unsigned int qsp2to1_qsp1_req_rx_bp : 1;
        unsigned int qsp2to1_qsp1_req_rx_wait_n : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_QSP1_REQ_RX_STATE_UNION;
#endif
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_QSP1_REQ_RX_STATE_qsp2to1_qsp1_req_rx_fifo_empty_n_START (0)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_QSP1_REQ_RX_STATE_qsp2to1_qsp1_req_rx_fifo_empty_n_END (3)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_QSP1_REQ_RX_STATE_qsp2to1_qsp1_req_rx_fifo_full_START (4)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_QSP1_REQ_RX_STATE_qsp2to1_qsp1_req_rx_fifo_full_END (7)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_QSP1_REQ_RX_STATE_qsp2to1_qsp1_req_rx_crd_initial_START (8)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_QSP1_REQ_RX_STATE_qsp2to1_qsp1_req_rx_crd_initial_END (11)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_QSP1_REQ_RX_STATE_qsp2to1_qsp1_req_rx_busy_START (12)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_QSP1_REQ_RX_STATE_qsp2to1_qsp1_req_rx_busy_END (15)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_QSP1_REQ_RX_STATE_qsp2to1_qsp1_req_rx_bp_START (16)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_QSP1_REQ_RX_STATE_qsp2to1_qsp1_req_rx_bp_END (16)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_QSP1_REQ_RX_STATE_qsp2to1_qsp1_req_rx_wait_n_START (17)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_QSP1_REQ_RX_STATE_qsp2to1_qsp1_req_rx_wait_n_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wa_qsp0_req_rx_fifo_empty_n : 4;
        unsigned int wa_qsp0_req_rx_fifo_full : 4;
        unsigned int wa_qsp0_dwr_req_busy : 4;
        unsigned int wa_qsp0_req_rx_busy : 4;
        unsigned int wa_qsp0_oup_tx_busy : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP0_REQ_RX_STATE_UNION;
#endif
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP0_REQ_RX_STATE_wa_qsp0_req_rx_fifo_empty_n_START (0)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP0_REQ_RX_STATE_wa_qsp0_req_rx_fifo_empty_n_END (3)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP0_REQ_RX_STATE_wa_qsp0_req_rx_fifo_full_START (4)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP0_REQ_RX_STATE_wa_qsp0_req_rx_fifo_full_END (7)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP0_REQ_RX_STATE_wa_qsp0_dwr_req_busy_START (8)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP0_REQ_RX_STATE_wa_qsp0_dwr_req_busy_END (11)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP0_REQ_RX_STATE_wa_qsp0_req_rx_busy_START (12)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP0_REQ_RX_STATE_wa_qsp0_req_rx_busy_END (15)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP0_REQ_RX_STATE_wa_qsp0_oup_tx_busy_START (16)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP0_REQ_RX_STATE_wa_qsp0_oup_tx_busy_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wa_qsp1_req_rx_fifo_empty_n : 4;
        unsigned int wa_qsp1_req_rx_fifo_full : 4;
        unsigned int wa_qsp1_dwr_req_busy : 4;
        unsigned int wa_qsp1_req_rx_busy : 4;
        unsigned int wa_qsp1_oup_tx_busy : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP1_REQ_RX_STATE_UNION;
#endif
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP1_REQ_RX_STATE_wa_qsp1_req_rx_fifo_empty_n_START (0)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP1_REQ_RX_STATE_wa_qsp1_req_rx_fifo_empty_n_END (3)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP1_REQ_RX_STATE_wa_qsp1_req_rx_fifo_full_START (4)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP1_REQ_RX_STATE_wa_qsp1_req_rx_fifo_full_END (7)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP1_REQ_RX_STATE_wa_qsp1_dwr_req_busy_START (8)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP1_REQ_RX_STATE_wa_qsp1_dwr_req_busy_END (11)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP1_REQ_RX_STATE_wa_qsp1_req_rx_busy_START (12)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP1_REQ_RX_STATE_wa_qsp1_req_rx_busy_END (15)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP1_REQ_RX_STATE_wa_qsp1_oup_tx_busy_START (16)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP1_REQ_RX_STATE_wa_qsp1_oup_tx_busy_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wa_qsp0_dwr_rsp_busy : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP0_RSP_RX_DWR_BUSY_UNION;
#endif
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP0_RSP_RX_DWR_BUSY_wa_qsp0_dwr_rsp_busy_START (0)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP0_RSP_RX_DWR_BUSY_wa_qsp0_dwr_rsp_busy_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wa_qsp1_dwr_rsp_busy : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP1_RSP_RX_DWR_BUSY_UNION;
#endif
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP1_RSP_RX_DWR_BUSY_wa_qsp1_dwr_rsp_busy_START (0)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_WA_QSP1_RSP_RX_DWR_BUSY_wa_qsp1_dwr_rsp_busy_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qsp2to1_qsp_req_tx_crd_cnt : 32;
    } reg;
} SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_QSP_M_REQ_TX_CRD_CNT_UNION;
#endif
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_QSP_M_REQ_TX_CRD_CNT_qsp2to1_qsp_req_tx_crd_cnt_START (0)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_QSP_M_REQ_TX_CRD_CNT_qsp2to1_qsp_req_tx_crd_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qsp2to1_qsp_req_tx_busy : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_QSP_M_REQ_TX_BUSY_UNION;
#endif
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_QSP_M_REQ_TX_BUSY_qsp2to1_qsp_req_tx_busy_START (0)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_QSP_M_REQ_TX_BUSY_qsp2to1_qsp_req_tx_busy_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qsp2to1_qsp_rsp_rx_wait_n : 1;
        unsigned int qsp2to1_qsp_rsp_rx_bp : 1;
        unsigned int qsp2to1_qsp_rsp_rx_busy : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_QSP_M_RSP_RX_STATE_UNION;
#endif
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_QSP_M_RSP_RX_STATE_qsp2to1_qsp_rsp_rx_wait_n_START (0)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_QSP_M_RSP_RX_STATE_qsp2to1_qsp_rsp_rx_wait_n_END (0)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_QSP_M_RSP_RX_STATE_qsp2to1_qsp_rsp_rx_bp_START (1)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_QSP_M_RSP_RX_STATE_qsp2to1_qsp_rsp_rx_bp_END (1)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_QSP_M_RSP_RX_STATE_qsp2to1_qsp_rsp_rx_busy_START (2)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_QSP_M_RSP_RX_STATE_qsp2to1_qsp_rsp_rx_busy_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rsp_buf0_fifo_empty_n : 1;
        unsigned int rsp_buf0_fifo_full : 1;
        unsigned int rsp_buf1_fifo_empty_n : 1;
        unsigned int rsp_buf1_fifo_full : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_RSP_BUF_STATE_UNION;
#endif
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_RSP_BUF_STATE_rsp_buf0_fifo_empty_n_START (0)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_RSP_BUF_STATE_rsp_buf0_fifo_empty_n_END (0)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_RSP_BUF_STATE_rsp_buf0_fifo_full_START (1)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_RSP_BUF_STATE_rsp_buf0_fifo_full_END (1)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_RSP_BUF_STATE_rsp_buf1_fifo_empty_n_START (2)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_RSP_BUF_STATE_rsp_buf1_fifo_empty_n_END (2)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_RSP_BUF_STATE_rsp_buf1_fifo_full_START (3)
#define SOC_QICE_QSP2TO1_WA_TOP_WRAP_QSP2TO1_WA_TOP_WRAP_RSP_BUF_STATE_rsp_buf1_fifo_full_END (3)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
