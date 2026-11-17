#ifndef __SOC_QICE_QDBEM_INTERFACE_H__
#define __SOC_QICE_QDBEM_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QICE_QDBEM_QDBEM_INFO_ADDR(base) ((base) + 0x0400UL)
#define SOC_QICE_QDBEM_QDBEM_RESERVED_RW_ADDR(base) ((base) + 0x0404UL)
#define SOC_QICE_QDBEM_QDBEM_RESERVED_RO_ADDR(base) ((base) + 0x0408UL)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ADDR(base) ((base) + 0x040CUL)
#define SOC_QICE_QDBEM_QDBEM_CTRL1_ADDR(base) ((base) + 0x0410UL)
#define SOC_QICE_QDBEM_QDBEM_CTRL2_ADDR(base) ((base) + 0x0414UL)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_ADDR(base) ((base) + 0x0e00UL)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT1_ADDR(base) ((base) + 0xe04UL)
#define SOC_QICE_QDBEM_QDBEM_TXREQ_DFX_ST0_ADDR(base) ((base) + 0xe08UL)
#define SOC_QICE_QDBEM_QDBEM_TXREQ_DFX_ST1_ADDR(base) ((base) + 0xe0cUL)
#define SOC_QICE_QDBEM_QDBEM_TXDATA_DFX_ST0_ADDR(base) ((base) + 0xe10UL)
#define SOC_QICE_QDBEM_QDBEM_TXDATA_DFX_ST1_ADDR(base) ((base) + 0xe14UL)
#define SOC_QICE_QDBEM_QDBEM_TXSRSP_DFX_ST0_ADDR(base) ((base) + 0xe18UL)
#define SOC_QICE_QDBEM_QDBEM_TXSRSP_DFX_ST1_ADDR(base) ((base) + 0xe1cUL)
#define SOC_QICE_QDBEM_QDBEM_RXDATA_DFX_ST0_ADDR(base) ((base) + 0xe20UL)
#define SOC_QICE_QDBEM_QDBEM_RXDATA_DFX_ST1_ADDR(base) ((base) + 0xe24UL)
#define SOC_QICE_QDBEM_QDBEM_RXCRSP_DFX_ST0_ADDR(base) ((base) + 0xe28UL)
#define SOC_QICE_QDBEM_QDBEM_RXCRSP_DFX_ST1_ADDR(base) ((base) + 0xe2cUL)
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST0_ADDR(base) ((base) + 0xe30UL)
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST1_ADDR(base) ((base) + 0xe34UL)
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST2_ADDR(base) ((base) + 0xe38UL)
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST3_ADDR(base) ((base) + 0xe3cUL)
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST4_ADDR(base) ((base) + 0xe40UL)
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST5_ADDR(base) ((base) + 0xe44UL)
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST6_ADDR(base) ((base) + 0xe48UL)
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST7_ADDR(base) ((base) + 0xe4cUL)
#else
#define SOC_QICE_QDBEM_QDBEM_INFO_ADDR(base) ((base) + 0x0400)
#define SOC_QICE_QDBEM_QDBEM_RESERVED_RW_ADDR(base) ((base) + 0x0404)
#define SOC_QICE_QDBEM_QDBEM_RESERVED_RO_ADDR(base) ((base) + 0x0408)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ADDR(base) ((base) + 0x040C)
#define SOC_QICE_QDBEM_QDBEM_CTRL1_ADDR(base) ((base) + 0x0410)
#define SOC_QICE_QDBEM_QDBEM_CTRL2_ADDR(base) ((base) + 0x0414)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_ADDR(base) ((base) + 0x0e00)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT1_ADDR(base) ((base) + 0xe04)
#define SOC_QICE_QDBEM_QDBEM_TXREQ_DFX_ST0_ADDR(base) ((base) + 0xe08)
#define SOC_QICE_QDBEM_QDBEM_TXREQ_DFX_ST1_ADDR(base) ((base) + 0xe0c)
#define SOC_QICE_QDBEM_QDBEM_TXDATA_DFX_ST0_ADDR(base) ((base) + 0xe10)
#define SOC_QICE_QDBEM_QDBEM_TXDATA_DFX_ST1_ADDR(base) ((base) + 0xe14)
#define SOC_QICE_QDBEM_QDBEM_TXSRSP_DFX_ST0_ADDR(base) ((base) + 0xe18)
#define SOC_QICE_QDBEM_QDBEM_TXSRSP_DFX_ST1_ADDR(base) ((base) + 0xe1c)
#define SOC_QICE_QDBEM_QDBEM_RXDATA_DFX_ST0_ADDR(base) ((base) + 0xe20)
#define SOC_QICE_QDBEM_QDBEM_RXDATA_DFX_ST1_ADDR(base) ((base) + 0xe24)
#define SOC_QICE_QDBEM_QDBEM_RXCRSP_DFX_ST0_ADDR(base) ((base) + 0xe28)
#define SOC_QICE_QDBEM_QDBEM_RXCRSP_DFX_ST1_ADDR(base) ((base) + 0xe2c)
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST0_ADDR(base) ((base) + 0xe30)
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST1_ADDR(base) ((base) + 0xe34)
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST2_ADDR(base) ((base) + 0xe38)
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST3_ADDR(base) ((base) + 0xe3c)
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST4_ADDR(base) ((base) + 0xe40)
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST5_ADDR(base) ((base) + 0xe44)
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST6_ADDR(base) ((base) + 0xe48)
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST7_ADDR(base) ((base) + 0xe4c)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qdbem_info : 32;
    } reg;
} SOC_QICE_QDBEM_QDBEM_INFO_UNION;
#endif
#define SOC_QICE_QDBEM_QDBEM_INFO_qdbem_info_START (0)
#define SOC_QICE_QDBEM_QDBEM_INFO_qdbem_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qdbem_reserved_rw : 32;
    } reg;
} SOC_QICE_QDBEM_QDBEM_RESERVED_RW_UNION;
#endif
#define SOC_QICE_QDBEM_QDBEM_RESERVED_RW_qdbem_reserved_rw_START (0)
#define SOC_QICE_QDBEM_QDBEM_RESERVED_RW_qdbem_reserved_rw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qdbem_reserved_ro : 32;
    } reg;
} SOC_QICE_QDBEM_QDBEM_RESERVED_RO_UNION;
#endif
#define SOC_QICE_QDBEM_QDBEM_RESERVED_RO_qdbem_reserved_ro_START (0)
#define SOC_QICE_QDBEM_QDBEM_RESERVED_RO_qdbem_reserved_ro_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int meta_dff_byps_txreq : 1;
        unsigned int meta_dff_byps_txdata : 1;
        unsigned int meta_dff_byps_txsrsp : 1;
        unsigned int meta_dff_byps_rxdata : 1;
        unsigned int meta_dff_byps_rxcrsp : 1;
        unsigned int meta_dff_byps_token : 1;
        unsigned int ckg_byps_txreq : 1;
        unsigned int ckg_byps_txdata : 1;
        unsigned int ckg_byps_txsrsp : 1;
        unsigned int ckg_byps_rdsync_txreq : 1;
        unsigned int ckg_byps_rdsync_txdata : 1;
        unsigned int ckg_byps_rdsync_txsrsp : 1;
        unsigned int ckg_byps_rxdata : 1;
        unsigned int ckg_byps_rxcrsp : 1;
        unsigned int ckg_byps_nmg : 1;
        unsigned int ckg_byps_pmc : 1;
        unsigned int ckg_byps_token : 1;
        unsigned int ckg_byps_topclk : 1;
        unsigned int ckg_ext_ena_txreq : 1;
        unsigned int ckg_ext_ena_txdata : 1;
        unsigned int ckg_ext_ena_txsrsp : 1;
        unsigned int ckg_ext_ena_rdsync_txreq : 1;
        unsigned int ckg_ext_ena_rdsync_txdata : 1;
        unsigned int ckg_ext_ena_rdsync_txsrsp : 1;
        unsigned int ckg_ext_ena_rxdata : 1;
        unsigned int ckg_ext_ena_rxcrsp : 1;
        unsigned int ckg_ext_ena_nmg : 1;
        unsigned int ckg_ext_ena_pmc : 1;
        unsigned int ckg_ext_ena_token : 1;
        unsigned int ckg_ext_ena_topclk : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_QICE_QDBEM_QDBEM_CTRL0_UNION;
#endif
#define SOC_QICE_QDBEM_QDBEM_CTRL0_meta_dff_byps_txreq_START (0)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_meta_dff_byps_txreq_END (0)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_meta_dff_byps_txdata_START (1)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_meta_dff_byps_txdata_END (1)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_meta_dff_byps_txsrsp_START (2)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_meta_dff_byps_txsrsp_END (2)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_meta_dff_byps_rxdata_START (3)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_meta_dff_byps_rxdata_END (3)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_meta_dff_byps_rxcrsp_START (4)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_meta_dff_byps_rxcrsp_END (4)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_meta_dff_byps_token_START (5)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_meta_dff_byps_token_END (5)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_byps_txreq_START (6)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_byps_txreq_END (6)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_byps_txdata_START (7)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_byps_txdata_END (7)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_byps_txsrsp_START (8)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_byps_txsrsp_END (8)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_byps_rdsync_txreq_START (9)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_byps_rdsync_txreq_END (9)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_byps_rdsync_txdata_START (10)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_byps_rdsync_txdata_END (10)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_byps_rdsync_txsrsp_START (11)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_byps_rdsync_txsrsp_END (11)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_byps_rxdata_START (12)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_byps_rxdata_END (12)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_byps_rxcrsp_START (13)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_byps_rxcrsp_END (13)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_byps_nmg_START (14)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_byps_nmg_END (14)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_byps_pmc_START (15)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_byps_pmc_END (15)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_byps_token_START (16)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_byps_token_END (16)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_byps_topclk_START (17)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_byps_topclk_END (17)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_ext_ena_txreq_START (18)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_ext_ena_txreq_END (18)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_ext_ena_txdata_START (19)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_ext_ena_txdata_END (19)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_ext_ena_txsrsp_START (20)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_ext_ena_txsrsp_END (20)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_ext_ena_rdsync_txreq_START (21)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_ext_ena_rdsync_txreq_END (21)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_ext_ena_rdsync_txdata_START (22)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_ext_ena_rdsync_txdata_END (22)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_ext_ena_rdsync_txsrsp_START (23)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_ext_ena_rdsync_txsrsp_END (23)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_ext_ena_rxdata_START (24)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_ext_ena_rxdata_END (24)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_ext_ena_rxcrsp_START (25)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_ext_ena_rxcrsp_END (25)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_ext_ena_nmg_START (26)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_ext_ena_nmg_END (26)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_ext_ena_pmc_START (27)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_ext_ena_pmc_END (27)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_ext_ena_token_START (28)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_ext_ena_token_END (28)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_ext_ena_topclk_START (29)
#define SOC_QICE_QDBEM_QDBEM_CTRL0_ckg_ext_ena_topclk_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ckg_byps_wrsync_rxdata : 1;
        unsigned int ckg_byps_wrsync_rxcrsp : 1;
        unsigned int ckg_byps_token_sync : 1;
        unsigned int ckg_byps_debounce : 1;
        unsigned int ckg_ext_ena_wrsync_rxdata : 1;
        unsigned int ckg_ext_ena_wrsync_rxcrsp : 1;
        unsigned int ckg_ext_ena_token_sync : 1;
        unsigned int ckg_ext_ena_debounce : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_QICE_QDBEM_QDBEM_CTRL1_UNION;
#endif
#define SOC_QICE_QDBEM_QDBEM_CTRL1_ckg_byps_wrsync_rxdata_START (0)
#define SOC_QICE_QDBEM_QDBEM_CTRL1_ckg_byps_wrsync_rxdata_END (0)
#define SOC_QICE_QDBEM_QDBEM_CTRL1_ckg_byps_wrsync_rxcrsp_START (1)
#define SOC_QICE_QDBEM_QDBEM_CTRL1_ckg_byps_wrsync_rxcrsp_END (1)
#define SOC_QICE_QDBEM_QDBEM_CTRL1_ckg_byps_token_sync_START (2)
#define SOC_QICE_QDBEM_QDBEM_CTRL1_ckg_byps_token_sync_END (2)
#define SOC_QICE_QDBEM_QDBEM_CTRL1_ckg_byps_debounce_START (3)
#define SOC_QICE_QDBEM_QDBEM_CTRL1_ckg_byps_debounce_END (3)
#define SOC_QICE_QDBEM_QDBEM_CTRL1_ckg_ext_ena_wrsync_rxdata_START (4)
#define SOC_QICE_QDBEM_QDBEM_CTRL1_ckg_ext_ena_wrsync_rxdata_END (4)
#define SOC_QICE_QDBEM_QDBEM_CTRL1_ckg_ext_ena_wrsync_rxcrsp_START (5)
#define SOC_QICE_QDBEM_QDBEM_CTRL1_ckg_ext_ena_wrsync_rxcrsp_END (5)
#define SOC_QICE_QDBEM_QDBEM_CTRL1_ckg_ext_ena_token_sync_START (6)
#define SOC_QICE_QDBEM_QDBEM_CTRL1_ckg_ext_ena_token_sync_END (6)
#define SOC_QICE_QDBEM_QDBEM_CTRL1_ckg_ext_ena_debounce_START (7)
#define SOC_QICE_QDBEM_QDBEM_CTRL1_ckg_ext_ena_debounce_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnt_in_thr : 6;
        unsigned int cnt_out_thr : 6;
        unsigned int debounce_cnt_in : 6;
        unsigned int debounce_cnt_out : 6;
        unsigned int qdbe_use_qtp_conn : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_QICE_QDBEM_QDBEM_CTRL2_UNION;
#endif
#define SOC_QICE_QDBEM_QDBEM_CTRL2_cnt_in_thr_START (0)
#define SOC_QICE_QDBEM_QDBEM_CTRL2_cnt_in_thr_END (5)
#define SOC_QICE_QDBEM_QDBEM_CTRL2_cnt_out_thr_START (6)
#define SOC_QICE_QDBEM_QDBEM_CTRL2_cnt_out_thr_END (11)
#define SOC_QICE_QDBEM_QDBEM_CTRL2_debounce_cnt_in_START (12)
#define SOC_QICE_QDBEM_QDBEM_CTRL2_debounce_cnt_in_END (17)
#define SOC_QICE_QDBEM_QDBEM_CTRL2_debounce_cnt_out_START (18)
#define SOC_QICE_QDBEM_QDBEM_CTRL2_debounce_cnt_out_END (23)
#define SOC_QICE_QDBEM_QDBEM_CTRL2_qdbe_use_qtp_conn_START (24)
#define SOC_QICE_QDBEM_QDBEM_CTRL2_qdbe_use_qtp_conn_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pwrd_qdbem_txreq_ack : 1;
        unsigned int pwrd_qdbem_txreq_req : 1;
        unsigned int pwrd_qdbem_txdata_ack : 1;
        unsigned int pwrd_qdbem_txdata_req : 1;
        unsigned int pwrd_qdbem_txsrsp_ack : 1;
        unsigned int pwrd_qdbem_txsrsp_req : 1;
        unsigned int pwrd_qdbem_rxdata_ack : 1;
        unsigned int pwrd_qdbem_rxdata_req : 1;
        unsigned int pwrd_qdbem_rxcrsp_ack : 1;
        unsigned int pwrd_qdbem_rxcrsp_req : 1;
        unsigned int qdbe_brg_conn_ack : 1;
        unsigned int qdbe_brg_conn_req : 1;
        unsigned int qdbe_pwrd_ack : 1;
        unsigned int qdbe_pwrd_req : 1;
        unsigned int rptr_clr_done_txreq : 1;
        unsigned int wptr_clr_done_txreq : 1;
        unsigned int rptr_clr_done_txdata : 1;
        unsigned int wptr_clr_done_txdata : 1;
        unsigned int rptr_clr_done_txsrsp : 1;
        unsigned int wptr_clr_done_txsrsp : 1;
        unsigned int rptr_clr_done_rxdata : 1;
        unsigned int wptr_clr_done_rxdata : 1;
        unsigned int rptr_clr_done_rxcrsp : 1;
        unsigned int wptr_clr_done_rxcrsp : 1;
        unsigned int pw_stat : 4;
        unsigned int reserved : 4;
    } reg;
} SOC_QICE_QDBEM_QDBEM_LP_STAT0_UNION;
#endif
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_pwrd_qdbem_txreq_ack_START (0)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_pwrd_qdbem_txreq_ack_END (0)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_pwrd_qdbem_txreq_req_START (1)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_pwrd_qdbem_txreq_req_END (1)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_pwrd_qdbem_txdata_ack_START (2)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_pwrd_qdbem_txdata_ack_END (2)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_pwrd_qdbem_txdata_req_START (3)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_pwrd_qdbem_txdata_req_END (3)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_pwrd_qdbem_txsrsp_ack_START (4)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_pwrd_qdbem_txsrsp_ack_END (4)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_pwrd_qdbem_txsrsp_req_START (5)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_pwrd_qdbem_txsrsp_req_END (5)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_pwrd_qdbem_rxdata_ack_START (6)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_pwrd_qdbem_rxdata_ack_END (6)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_pwrd_qdbem_rxdata_req_START (7)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_pwrd_qdbem_rxdata_req_END (7)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_pwrd_qdbem_rxcrsp_ack_START (8)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_pwrd_qdbem_rxcrsp_ack_END (8)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_pwrd_qdbem_rxcrsp_req_START (9)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_pwrd_qdbem_rxcrsp_req_END (9)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_qdbe_brg_conn_ack_START (10)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_qdbe_brg_conn_ack_END (10)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_qdbe_brg_conn_req_START (11)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_qdbe_brg_conn_req_END (11)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_qdbe_pwrd_ack_START (12)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_qdbe_pwrd_ack_END (12)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_qdbe_pwrd_req_START (13)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_qdbe_pwrd_req_END (13)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_rptr_clr_done_txreq_START (14)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_rptr_clr_done_txreq_END (14)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_wptr_clr_done_txreq_START (15)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_wptr_clr_done_txreq_END (15)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_rptr_clr_done_txdata_START (16)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_rptr_clr_done_txdata_END (16)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_wptr_clr_done_txdata_START (17)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_wptr_clr_done_txdata_END (17)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_rptr_clr_done_txsrsp_START (18)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_rptr_clr_done_txsrsp_END (18)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_wptr_clr_done_txsrsp_START (19)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_wptr_clr_done_txsrsp_END (19)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_rptr_clr_done_rxdata_START (20)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_rptr_clr_done_rxdata_END (20)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_wptr_clr_done_rxdata_START (21)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_wptr_clr_done_rxdata_END (21)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_rptr_clr_done_rxcrsp_START (22)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_rptr_clr_done_rxcrsp_END (22)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_wptr_clr_done_rxcrsp_START (23)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_wptr_clr_done_rxcrsp_END (23)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_pw_stat_START (24)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT0_pw_stat_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ckg_busy_token : 1;
        unsigned int dfx_busy_pmc : 1;
        unsigned int ckg_busy_topclk : 1;
        unsigned int token_ack_clr : 1;
        unsigned int token_req_fencing : 1;
        unsigned int token_req_clr : 1;
        unsigned int cnt_done_in : 1;
        unsigned int cnt_done_out : 1;
        unsigned int qdbe_ibqe_nopending_comb : 1;
        unsigned int qdbe_nopending_comb_use : 1;
        unsigned int ckg_wakeup_token_sync : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_QICE_QDBEM_QDBEM_LP_STAT1_UNION;
#endif
#define SOC_QICE_QDBEM_QDBEM_LP_STAT1_ckg_busy_token_START (0)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT1_ckg_busy_token_END (0)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT1_dfx_busy_pmc_START (1)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT1_dfx_busy_pmc_END (1)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT1_ckg_busy_topclk_START (2)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT1_ckg_busy_topclk_END (2)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT1_token_ack_clr_START (3)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT1_token_ack_clr_END (3)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT1_token_req_fencing_START (4)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT1_token_req_fencing_END (4)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT1_token_req_clr_START (5)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT1_token_req_clr_END (5)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT1_cnt_done_in_START (6)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT1_cnt_done_in_END (6)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT1_cnt_done_out_START (7)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT1_cnt_done_out_END (7)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT1_qdbe_ibqe_nopending_comb_START (8)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT1_qdbe_ibqe_nopending_comb_END (8)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT1_qdbe_nopending_comb_use_START (9)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT1_qdbe_nopending_comb_use_END (9)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT1_ckg_wakeup_token_sync_START (10)
#define SOC_QICE_QDBEM_QDBEM_LP_STAT1_ckg_wakeup_token_sync_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_txreq_stat : 32;
    } reg;
} SOC_QICE_QDBEM_QDBEM_TXREQ_DFX_ST0_UNION;
#endif
#define SOC_QICE_QDBEM_QDBEM_TXREQ_DFX_ST0_dfx_txreq_stat_START (0)
#define SOC_QICE_QDBEM_QDBEM_TXREQ_DFX_ST0_dfx_txreq_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_txreq_vccrdt_cnt : 32;
    } reg;
} SOC_QICE_QDBEM_QDBEM_TXREQ_DFX_ST1_UNION;
#endif
#define SOC_QICE_QDBEM_QDBEM_TXREQ_DFX_ST1_dfx_txreq_vccrdt_cnt_START (0)
#define SOC_QICE_QDBEM_QDBEM_TXREQ_DFX_ST1_dfx_txreq_vccrdt_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_txdata_stat : 32;
    } reg;
} SOC_QICE_QDBEM_QDBEM_TXDATA_DFX_ST0_UNION;
#endif
#define SOC_QICE_QDBEM_QDBEM_TXDATA_DFX_ST0_dfx_txdata_stat_START (0)
#define SOC_QICE_QDBEM_QDBEM_TXDATA_DFX_ST0_dfx_txdata_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_txdata_vccrdt_cnt : 32;
    } reg;
} SOC_QICE_QDBEM_QDBEM_TXDATA_DFX_ST1_UNION;
#endif
#define SOC_QICE_QDBEM_QDBEM_TXDATA_DFX_ST1_dfx_txdata_vccrdt_cnt_START (0)
#define SOC_QICE_QDBEM_QDBEM_TXDATA_DFX_ST1_dfx_txdata_vccrdt_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_txsrsp_stat : 32;
    } reg;
} SOC_QICE_QDBEM_QDBEM_TXSRSP_DFX_ST0_UNION;
#endif
#define SOC_QICE_QDBEM_QDBEM_TXSRSP_DFX_ST0_dfx_txsrsp_stat_START (0)
#define SOC_QICE_QDBEM_QDBEM_TXSRSP_DFX_ST0_dfx_txsrsp_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_txsrsp_vccrdt_cnt : 32;
    } reg;
} SOC_QICE_QDBEM_QDBEM_TXSRSP_DFX_ST1_UNION;
#endif
#define SOC_QICE_QDBEM_QDBEM_TXSRSP_DFX_ST1_dfx_txsrsp_vccrdt_cnt_START (0)
#define SOC_QICE_QDBEM_QDBEM_TXSRSP_DFX_ST1_dfx_txsrsp_vccrdt_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_rxdata_stat : 32;
    } reg;
} SOC_QICE_QDBEM_QDBEM_RXDATA_DFX_ST0_UNION;
#endif
#define SOC_QICE_QDBEM_QDBEM_RXDATA_DFX_ST0_dfx_rxdata_stat_START (0)
#define SOC_QICE_QDBEM_QDBEM_RXDATA_DFX_ST0_dfx_rxdata_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_rxdata_txcrdt_cnt : 32;
    } reg;
} SOC_QICE_QDBEM_QDBEM_RXDATA_DFX_ST1_UNION;
#endif
#define SOC_QICE_QDBEM_QDBEM_RXDATA_DFX_ST1_dfx_rxdata_txcrdt_cnt_START (0)
#define SOC_QICE_QDBEM_QDBEM_RXDATA_DFX_ST1_dfx_rxdata_txcrdt_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_rxcrsp_stat : 32;
    } reg;
} SOC_QICE_QDBEM_QDBEM_RXCRSP_DFX_ST0_UNION;
#endif
#define SOC_QICE_QDBEM_QDBEM_RXCRSP_DFX_ST0_dfx_rxcrsp_stat_START (0)
#define SOC_QICE_QDBEM_QDBEM_RXCRSP_DFX_ST0_dfx_rxcrsp_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_rxcrsp_txcrdt_cnt : 32;
    } reg;
} SOC_QICE_QDBEM_QDBEM_RXCRSP_DFX_ST1_UNION;
#endif
#define SOC_QICE_QDBEM_QDBEM_RXCRSP_DFX_ST1_dfx_rxcrsp_txcrdt_cnt_START (0)
#define SOC_QICE_QDBEM_QDBEM_RXCRSP_DFX_ST1_dfx_rxcrsp_txcrdt_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_token_cnt_0 : 32;
    } reg;
} SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST0_UNION;
#endif
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST0_dfx_token_cnt_0_START (0)
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST0_dfx_token_cnt_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_token_cnt_1 : 32;
    } reg;
} SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST1_UNION;
#endif
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST1_dfx_token_cnt_1_START (0)
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST1_dfx_token_cnt_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_token_cnt_2 : 32;
    } reg;
} SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST2_UNION;
#endif
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST2_dfx_token_cnt_2_START (0)
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST2_dfx_token_cnt_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_token_cnt_3 : 32;
    } reg;
} SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST3_UNION;
#endif
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST3_dfx_token_cnt_3_START (0)
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST3_dfx_token_cnt_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_token_cnt_4 : 32;
    } reg;
} SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST4_UNION;
#endif
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST4_dfx_token_cnt_4_START (0)
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST4_dfx_token_cnt_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_token_cnt_5 : 32;
    } reg;
} SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST5_UNION;
#endif
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST5_dfx_token_cnt_5_START (0)
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST5_dfx_token_cnt_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_token_cnt_6 : 32;
    } reg;
} SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST6_UNION;
#endif
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST6_dfx_token_cnt_6_START (0)
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST6_dfx_token_cnt_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_token_cnt_7 : 32;
    } reg;
} SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST7_UNION;
#endif
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST7_dfx_token_cnt_7_START (0)
#define SOC_QICE_QDBEM_QDBEM_TOKEN_DFX_ST7_dfx_token_cnt_7_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
