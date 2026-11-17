#ifndef __SOC_QICE_QDBES_INTERFACE_H__
#define __SOC_QICE_QDBES_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QICE_QDBES_QDBES_INFO_ADDR(base) ((base) + 0x0400UL)
#define SOC_QICE_QDBES_QDBES_RESERVED_RW_ADDR(base) ((base) + 0x0404UL)
#define SOC_QICE_QDBES_QDBES_RESERVED_RO_ADDR(base) ((base) + 0x0408UL)
#define SOC_QICE_QDBES_QDBES_CTRL0_ADDR(base) ((base) + 0x040CUL)
#define SOC_QICE_QDBES_QDBES_CTRL1_ADDR(base) ((base) + 0x0410UL)
#define SOC_QICE_QDBES_QDBES_CTRL2_ADDR(base) ((base) + 0x0414UL)
#define SOC_QICE_QDBES_QDBES_QOS_LMTR0_CTRL_ADDR(base) ((base) + 0x0640UL)
#define SOC_QICE_QDBES_QDBES_QOS_LMTR1_CTRL_ADDR(base) ((base) + 0x0644UL)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_ADDR(base) ((base) + 0x0e00UL)
#define SOC_QICE_QDBES_QDBES_LP_STAT1_ADDR(base) ((base) + 0xe04UL)
#define SOC_QICE_QDBES_QDBES_TXREQ_DFX_ST0_ADDR(base) ((base) + 0xe08UL)
#define SOC_QICE_QDBES_QDBES_TXREQ_DFX_ST1_ADDR(base) ((base) + 0xe0cUL)
#define SOC_QICE_QDBES_QDBES_TXDATA_DFX_ST0_ADDR(base) ((base) + 0xe10UL)
#define SOC_QICE_QDBES_QDBES_TXDATA_DFX_ST1_ADDR(base) ((base) + 0xe14UL)
#define SOC_QICE_QDBES_QDBES_TXSRSP_DFX_ST0_ADDR(base) ((base) + 0xe18UL)
#define SOC_QICE_QDBES_QDBES_TXSRSP_DFX_ST1_ADDR(base) ((base) + 0xe1cUL)
#define SOC_QICE_QDBES_QDBES_RXDATA_DFX_ST0_ADDR(base) ((base) + 0xe20UL)
#define SOC_QICE_QDBES_QDBES_RXDATA_DFX_ST1_ADDR(base) ((base) + 0xe24UL)
#define SOC_QICE_QDBES_QDBES_RXCRSP_DFX_ST0_ADDR(base) ((base) + 0xe28UL)
#define SOC_QICE_QDBES_QDBES_RXCRSP_DFX_ST1_ADDR(base) ((base) + 0xe2cUL)
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST0_ADDR(base) ((base) + 0xe30UL)
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST1_ADDR(base) ((base) + 0xe34UL)
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST2_ADDR(base) ((base) + 0xe38UL)
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST3_ADDR(base) ((base) + 0xe3cUL)
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST4_ADDR(base) ((base) + 0xe40UL)
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST5_ADDR(base) ((base) + 0xe44UL)
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST6_ADDR(base) ((base) + 0xe48UL)
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST7_ADDR(base) ((base) + 0xe4cUL)
#else
#define SOC_QICE_QDBES_QDBES_INFO_ADDR(base) ((base) + 0x0400)
#define SOC_QICE_QDBES_QDBES_RESERVED_RW_ADDR(base) ((base) + 0x0404)
#define SOC_QICE_QDBES_QDBES_RESERVED_RO_ADDR(base) ((base) + 0x0408)
#define SOC_QICE_QDBES_QDBES_CTRL0_ADDR(base) ((base) + 0x040C)
#define SOC_QICE_QDBES_QDBES_CTRL1_ADDR(base) ((base) + 0x0410)
#define SOC_QICE_QDBES_QDBES_CTRL2_ADDR(base) ((base) + 0x0414)
#define SOC_QICE_QDBES_QDBES_QOS_LMTR0_CTRL_ADDR(base) ((base) + 0x0640)
#define SOC_QICE_QDBES_QDBES_QOS_LMTR1_CTRL_ADDR(base) ((base) + 0x0644)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_ADDR(base) ((base) + 0x0e00)
#define SOC_QICE_QDBES_QDBES_LP_STAT1_ADDR(base) ((base) + 0xe04)
#define SOC_QICE_QDBES_QDBES_TXREQ_DFX_ST0_ADDR(base) ((base) + 0xe08)
#define SOC_QICE_QDBES_QDBES_TXREQ_DFX_ST1_ADDR(base) ((base) + 0xe0c)
#define SOC_QICE_QDBES_QDBES_TXDATA_DFX_ST0_ADDR(base) ((base) + 0xe10)
#define SOC_QICE_QDBES_QDBES_TXDATA_DFX_ST1_ADDR(base) ((base) + 0xe14)
#define SOC_QICE_QDBES_QDBES_TXSRSP_DFX_ST0_ADDR(base) ((base) + 0xe18)
#define SOC_QICE_QDBES_QDBES_TXSRSP_DFX_ST1_ADDR(base) ((base) + 0xe1c)
#define SOC_QICE_QDBES_QDBES_RXDATA_DFX_ST0_ADDR(base) ((base) + 0xe20)
#define SOC_QICE_QDBES_QDBES_RXDATA_DFX_ST1_ADDR(base) ((base) + 0xe24)
#define SOC_QICE_QDBES_QDBES_RXCRSP_DFX_ST0_ADDR(base) ((base) + 0xe28)
#define SOC_QICE_QDBES_QDBES_RXCRSP_DFX_ST1_ADDR(base) ((base) + 0xe2c)
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST0_ADDR(base) ((base) + 0xe30)
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST1_ADDR(base) ((base) + 0xe34)
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST2_ADDR(base) ((base) + 0xe38)
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST3_ADDR(base) ((base) + 0xe3c)
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST4_ADDR(base) ((base) + 0xe40)
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST5_ADDR(base) ((base) + 0xe44)
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST6_ADDR(base) ((base) + 0xe48)
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST7_ADDR(base) ((base) + 0xe4c)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qdbes_info : 32;
    } reg;
} SOC_QICE_QDBES_QDBES_INFO_UNION;
#endif
#define SOC_QICE_QDBES_QDBES_INFO_qdbes_info_START (0)
#define SOC_QICE_QDBES_QDBES_INFO_qdbes_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qdbes_reserved_rw : 32;
    } reg;
} SOC_QICE_QDBES_QDBES_RESERVED_RW_UNION;
#endif
#define SOC_QICE_QDBES_QDBES_RESERVED_RW_qdbes_reserved_rw_START (0)
#define SOC_QICE_QDBES_QDBES_RESERVED_RW_qdbes_reserved_rw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qdbes_reserved_ro : 32;
    } reg;
} SOC_QICE_QDBES_QDBES_RESERVED_RO_UNION;
#endif
#define SOC_QICE_QDBES_QDBES_RESERVED_RO_qdbes_reserved_ro_START (0)
#define SOC_QICE_QDBES_QDBES_RESERVED_RO_qdbes_reserved_ro_END (31)
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
        unsigned int ckg_byps_rxdata : 1;
        unsigned int ckg_byps_rxcrsp : 1;
        unsigned int ckg_byps_rdsync_rxdata : 1;
        unsigned int ckg_byps_rdsync_rxcrsp : 1;
        unsigned int ckg_byps_nmg : 1;
        unsigned int ckg_byps_pmc : 1;
        unsigned int ckg_byps_token : 1;
        unsigned int ckg_byps_topclk : 1;
        unsigned int ckg_ext_ena_txreq : 1;
        unsigned int ckg_ext_ena_txdata : 1;
        unsigned int ckg_ext_ena_txsrsp : 1;
        unsigned int ckg_ext_ena_rxdata : 1;
        unsigned int ckg_ext_ena_rxcrsp : 1;
        unsigned int ckg_ext_ena_rdsync_rxdata : 1;
        unsigned int ckg_ext_ena_rdsync_rxcrsp : 1;
        unsigned int ckg_ext_ena_nmg : 1;
        unsigned int ckg_ext_ena_pmc : 1;
        unsigned int ckg_ext_ena_token : 1;
        unsigned int ckg_ext_ena_topclk : 1;
        unsigned int reserved : 4;
    } reg;
} SOC_QICE_QDBES_QDBES_CTRL0_UNION;
#endif
#define SOC_QICE_QDBES_QDBES_CTRL0_meta_dff_byps_txreq_START (0)
#define SOC_QICE_QDBES_QDBES_CTRL0_meta_dff_byps_txreq_END (0)
#define SOC_QICE_QDBES_QDBES_CTRL0_meta_dff_byps_txdata_START (1)
#define SOC_QICE_QDBES_QDBES_CTRL0_meta_dff_byps_txdata_END (1)
#define SOC_QICE_QDBES_QDBES_CTRL0_meta_dff_byps_txsrsp_START (2)
#define SOC_QICE_QDBES_QDBES_CTRL0_meta_dff_byps_txsrsp_END (2)
#define SOC_QICE_QDBES_QDBES_CTRL0_meta_dff_byps_rxdata_START (3)
#define SOC_QICE_QDBES_QDBES_CTRL0_meta_dff_byps_rxdata_END (3)
#define SOC_QICE_QDBES_QDBES_CTRL0_meta_dff_byps_rxcrsp_START (4)
#define SOC_QICE_QDBES_QDBES_CTRL0_meta_dff_byps_rxcrsp_END (4)
#define SOC_QICE_QDBES_QDBES_CTRL0_meta_dff_byps_token_START (5)
#define SOC_QICE_QDBES_QDBES_CTRL0_meta_dff_byps_token_END (5)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_byps_txreq_START (6)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_byps_txreq_END (6)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_byps_txdata_START (7)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_byps_txdata_END (7)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_byps_txsrsp_START (8)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_byps_txsrsp_END (8)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_byps_rxdata_START (9)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_byps_rxdata_END (9)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_byps_rxcrsp_START (10)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_byps_rxcrsp_END (10)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_byps_rdsync_rxdata_START (11)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_byps_rdsync_rxdata_END (11)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_byps_rdsync_rxcrsp_START (12)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_byps_rdsync_rxcrsp_END (12)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_byps_nmg_START (13)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_byps_nmg_END (13)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_byps_pmc_START (14)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_byps_pmc_END (14)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_byps_token_START (15)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_byps_token_END (15)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_byps_topclk_START (16)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_byps_topclk_END (16)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_ext_ena_txreq_START (17)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_ext_ena_txreq_END (17)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_ext_ena_txdata_START (18)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_ext_ena_txdata_END (18)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_ext_ena_txsrsp_START (19)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_ext_ena_txsrsp_END (19)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_ext_ena_rxdata_START (20)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_ext_ena_rxdata_END (20)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_ext_ena_rxcrsp_START (21)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_ext_ena_rxcrsp_END (21)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_ext_ena_rdsync_rxdata_START (22)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_ext_ena_rdsync_rxdata_END (22)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_ext_ena_rdsync_rxcrsp_START (23)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_ext_ena_rdsync_rxcrsp_END (23)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_ext_ena_nmg_START (24)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_ext_ena_nmg_END (24)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_ext_ena_pmc_START (25)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_ext_ena_pmc_END (25)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_ext_ena_token_START (26)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_ext_ena_token_END (26)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_ext_ena_topclk_START (27)
#define SOC_QICE_QDBES_QDBES_CTRL0_ckg_ext_ena_topclk_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int meta_dff_byps_nopending : 1;
        unsigned int ckg_byps_wrsync_txsrsp : 1;
        unsigned int ckg_byps_wrsync_txdata : 1;
        unsigned int ckg_byps_wrsync_txreq : 1;
        unsigned int ckg_byps_token_sync : 1;
        unsigned int ckg_ext_ena_wrsync_txsrsp : 1;
        unsigned int ckg_ext_ena_wrsync_txdata : 1;
        unsigned int ckg_ext_ena_wrsync_txreq : 1;
        unsigned int ckg_ext_ena_token_sync : 1;
        unsigned int meta_dff_byps_2qdbem : 1;
        unsigned int ckg_byps_all_2qdbem : 1;
        unsigned int qdbe_use_qtp_conn_2qdbem : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_QICE_QDBES_QDBES_CTRL1_UNION;
#endif
#define SOC_QICE_QDBES_QDBES_CTRL1_meta_dff_byps_nopending_START (0)
#define SOC_QICE_QDBES_QDBES_CTRL1_meta_dff_byps_nopending_END (0)
#define SOC_QICE_QDBES_QDBES_CTRL1_ckg_byps_wrsync_txsrsp_START (1)
#define SOC_QICE_QDBES_QDBES_CTRL1_ckg_byps_wrsync_txsrsp_END (1)
#define SOC_QICE_QDBES_QDBES_CTRL1_ckg_byps_wrsync_txdata_START (2)
#define SOC_QICE_QDBES_QDBES_CTRL1_ckg_byps_wrsync_txdata_END (2)
#define SOC_QICE_QDBES_QDBES_CTRL1_ckg_byps_wrsync_txreq_START (3)
#define SOC_QICE_QDBES_QDBES_CTRL1_ckg_byps_wrsync_txreq_END (3)
#define SOC_QICE_QDBES_QDBES_CTRL1_ckg_byps_token_sync_START (4)
#define SOC_QICE_QDBES_QDBES_CTRL1_ckg_byps_token_sync_END (4)
#define SOC_QICE_QDBES_QDBES_CTRL1_ckg_ext_ena_wrsync_txsrsp_START (5)
#define SOC_QICE_QDBES_QDBES_CTRL1_ckg_ext_ena_wrsync_txsrsp_END (5)
#define SOC_QICE_QDBES_QDBES_CTRL1_ckg_ext_ena_wrsync_txdata_START (6)
#define SOC_QICE_QDBES_QDBES_CTRL1_ckg_ext_ena_wrsync_txdata_END (6)
#define SOC_QICE_QDBES_QDBES_CTRL1_ckg_ext_ena_wrsync_txreq_START (7)
#define SOC_QICE_QDBES_QDBES_CTRL1_ckg_ext_ena_wrsync_txreq_END (7)
#define SOC_QICE_QDBES_QDBES_CTRL1_ckg_ext_ena_token_sync_START (8)
#define SOC_QICE_QDBES_QDBES_CTRL1_ckg_ext_ena_token_sync_END (8)
#define SOC_QICE_QDBES_QDBES_CTRL1_meta_dff_byps_2qdbem_START (9)
#define SOC_QICE_QDBES_QDBES_CTRL1_meta_dff_byps_2qdbem_END (9)
#define SOC_QICE_QDBES_QDBES_CTRL1_ckg_byps_all_2qdbem_START (10)
#define SOC_QICE_QDBES_QDBES_CTRL1_ckg_byps_all_2qdbem_END (10)
#define SOC_QICE_QDBES_QDBES_CTRL1_qdbe_use_qtp_conn_2qdbem_START (11)
#define SOC_QICE_QDBES_QDBES_CTRL1_qdbe_use_qtp_conn_2qdbem_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnt_in_thr : 6;
        unsigned int cnt_out_thr : 6;
        unsigned int reserved : 20;
    } reg;
} SOC_QICE_QDBES_QDBES_CTRL2_UNION;
#endif
#define SOC_QICE_QDBES_QDBES_CTRL2_cnt_in_thr_START (0)
#define SOC_QICE_QDBES_QDBES_CTRL2_cnt_in_thr_END (5)
#define SOC_QICE_QDBES_QDBES_CTRL2_cnt_out_thr_START (6)
#define SOC_QICE_QDBES_QDBES_CTRL2_cnt_out_thr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfc0_bw : 8;
        unsigned int cfc0_sat : 8;
        unsigned int reserved_0: 8;
        unsigned int cfc0_lp : 2;
        unsigned int reserved_1: 4;
        unsigned int cfc0_type : 1;
        unsigned int cfc0_en : 1;
    } reg;
} SOC_QICE_QDBES_QDBES_QOS_LMTR0_CTRL_UNION;
#endif
#define SOC_QICE_QDBES_QDBES_QOS_LMTR0_CTRL_cfc0_bw_START (0)
#define SOC_QICE_QDBES_QDBES_QOS_LMTR0_CTRL_cfc0_bw_END (7)
#define SOC_QICE_QDBES_QDBES_QOS_LMTR0_CTRL_cfc0_sat_START (8)
#define SOC_QICE_QDBES_QDBES_QOS_LMTR0_CTRL_cfc0_sat_END (15)
#define SOC_QICE_QDBES_QDBES_QOS_LMTR0_CTRL_cfc0_lp_START (24)
#define SOC_QICE_QDBES_QDBES_QOS_LMTR0_CTRL_cfc0_lp_END (25)
#define SOC_QICE_QDBES_QDBES_QOS_LMTR0_CTRL_cfc0_type_START (30)
#define SOC_QICE_QDBES_QDBES_QOS_LMTR0_CTRL_cfc0_type_END (30)
#define SOC_QICE_QDBES_QDBES_QOS_LMTR0_CTRL_cfc0_en_START (31)
#define SOC_QICE_QDBES_QDBES_QOS_LMTR0_CTRL_cfc0_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfc1_bw : 8;
        unsigned int cfc1_sat : 8;
        unsigned int reserved_0: 8;
        unsigned int cfc1_lp : 2;
        unsigned int reserved_1: 5;
        unsigned int cfc1_en : 1;
    } reg;
} SOC_QICE_QDBES_QDBES_QOS_LMTR1_CTRL_UNION;
#endif
#define SOC_QICE_QDBES_QDBES_QOS_LMTR1_CTRL_cfc1_bw_START (0)
#define SOC_QICE_QDBES_QDBES_QOS_LMTR1_CTRL_cfc1_bw_END (7)
#define SOC_QICE_QDBES_QDBES_QOS_LMTR1_CTRL_cfc1_sat_START (8)
#define SOC_QICE_QDBES_QDBES_QOS_LMTR1_CTRL_cfc1_sat_END (15)
#define SOC_QICE_QDBES_QDBES_QOS_LMTR1_CTRL_cfc1_lp_START (24)
#define SOC_QICE_QDBES_QDBES_QOS_LMTR1_CTRL_cfc1_lp_END (25)
#define SOC_QICE_QDBES_QDBES_QOS_LMTR1_CTRL_cfc1_en_START (31)
#define SOC_QICE_QDBES_QDBES_QOS_LMTR1_CTRL_cfc1_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pwrd_qdbes_txreq_ack : 1;
        unsigned int pwrd_qdbes_txreq_req : 1;
        unsigned int pwrd_qdbes_txdata_ack : 1;
        unsigned int pwrd_qdbes_txdata_req : 1;
        unsigned int pwrd_qdbes_txsrsp_ack : 1;
        unsigned int pwrd_qdbes_txsrsp_req : 1;
        unsigned int pwrd_qdbes_rxdata_ack : 1;
        unsigned int pwrd_qdbes_rxdata_req : 1;
        unsigned int pwrd_qdbes_rxcrsp_ack : 1;
        unsigned int pwrd_qdbes_rxcrsp_req : 1;
        unsigned int qdbe_brg_conn_ack : 1;
        unsigned int qdbe_brg_conn_req : 1;
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
        unsigned int pw_stat : 3;
        unsigned int reserved : 7;
    } reg;
} SOC_QICE_QDBES_QDBES_LP_STAT0_UNION;
#endif
#define SOC_QICE_QDBES_QDBES_LP_STAT0_pwrd_qdbes_txreq_ack_START (0)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_pwrd_qdbes_txreq_ack_END (0)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_pwrd_qdbes_txreq_req_START (1)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_pwrd_qdbes_txreq_req_END (1)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_pwrd_qdbes_txdata_ack_START (2)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_pwrd_qdbes_txdata_ack_END (2)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_pwrd_qdbes_txdata_req_START (3)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_pwrd_qdbes_txdata_req_END (3)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_pwrd_qdbes_txsrsp_ack_START (4)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_pwrd_qdbes_txsrsp_ack_END (4)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_pwrd_qdbes_txsrsp_req_START (5)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_pwrd_qdbes_txsrsp_req_END (5)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_pwrd_qdbes_rxdata_ack_START (6)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_pwrd_qdbes_rxdata_ack_END (6)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_pwrd_qdbes_rxdata_req_START (7)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_pwrd_qdbes_rxdata_req_END (7)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_pwrd_qdbes_rxcrsp_ack_START (8)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_pwrd_qdbes_rxcrsp_ack_END (8)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_pwrd_qdbes_rxcrsp_req_START (9)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_pwrd_qdbes_rxcrsp_req_END (9)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_qdbe_brg_conn_ack_START (10)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_qdbe_brg_conn_ack_END (10)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_qdbe_brg_conn_req_START (11)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_qdbe_brg_conn_req_END (11)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_rptr_clr_done_txreq_START (12)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_rptr_clr_done_txreq_END (12)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_wptr_clr_done_txreq_START (13)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_wptr_clr_done_txreq_END (13)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_rptr_clr_done_txdata_START (14)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_rptr_clr_done_txdata_END (14)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_wptr_clr_done_txdata_START (15)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_wptr_clr_done_txdata_END (15)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_rptr_clr_done_txsrsp_START (16)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_rptr_clr_done_txsrsp_END (16)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_wptr_clr_done_txsrsp_START (17)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_wptr_clr_done_txsrsp_END (17)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_rptr_clr_done_rxdata_START (18)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_rptr_clr_done_rxdata_END (18)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_wptr_clr_done_rxdata_START (19)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_wptr_clr_done_rxdata_END (19)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_rptr_clr_done_rxcrsp_START (20)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_rptr_clr_done_rxcrsp_END (20)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_wptr_clr_done_rxcrsp_START (21)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_wptr_clr_done_rxcrsp_END (21)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_pw_stat_START (22)
#define SOC_QICE_QDBES_QDBES_LP_STAT0_pw_stat_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ckg_busy_token : 1;
        unsigned int dfx_busy_pmc : 1;
        unsigned int ckg_busy_topclk : 1;
        unsigned int token_ack_clr : 1;
        unsigned int token_req_clr : 1;
        unsigned int cnt_done_in : 1;
        unsigned int cnt_done_out : 1;
        unsigned int qdbe_brg_nopending_comb_sync : 1;
        unsigned int ckg_wakeup_token_sync : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_QICE_QDBES_QDBES_LP_STAT1_UNION;
#endif
#define SOC_QICE_QDBES_QDBES_LP_STAT1_ckg_busy_token_START (0)
#define SOC_QICE_QDBES_QDBES_LP_STAT1_ckg_busy_token_END (0)
#define SOC_QICE_QDBES_QDBES_LP_STAT1_dfx_busy_pmc_START (1)
#define SOC_QICE_QDBES_QDBES_LP_STAT1_dfx_busy_pmc_END (1)
#define SOC_QICE_QDBES_QDBES_LP_STAT1_ckg_busy_topclk_START (2)
#define SOC_QICE_QDBES_QDBES_LP_STAT1_ckg_busy_topclk_END (2)
#define SOC_QICE_QDBES_QDBES_LP_STAT1_token_ack_clr_START (3)
#define SOC_QICE_QDBES_QDBES_LP_STAT1_token_ack_clr_END (3)
#define SOC_QICE_QDBES_QDBES_LP_STAT1_token_req_clr_START (4)
#define SOC_QICE_QDBES_QDBES_LP_STAT1_token_req_clr_END (4)
#define SOC_QICE_QDBES_QDBES_LP_STAT1_cnt_done_in_START (5)
#define SOC_QICE_QDBES_QDBES_LP_STAT1_cnt_done_in_END (5)
#define SOC_QICE_QDBES_QDBES_LP_STAT1_cnt_done_out_START (6)
#define SOC_QICE_QDBES_QDBES_LP_STAT1_cnt_done_out_END (6)
#define SOC_QICE_QDBES_QDBES_LP_STAT1_qdbe_brg_nopending_comb_sync_START (7)
#define SOC_QICE_QDBES_QDBES_LP_STAT1_qdbe_brg_nopending_comb_sync_END (7)
#define SOC_QICE_QDBES_QDBES_LP_STAT1_ckg_wakeup_token_sync_START (8)
#define SOC_QICE_QDBES_QDBES_LP_STAT1_ckg_wakeup_token_sync_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_txreq_stat : 32;
    } reg;
} SOC_QICE_QDBES_QDBES_TXREQ_DFX_ST0_UNION;
#endif
#define SOC_QICE_QDBES_QDBES_TXREQ_DFX_ST0_dfx_txreq_stat_START (0)
#define SOC_QICE_QDBES_QDBES_TXREQ_DFX_ST0_dfx_txreq_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_txreq_txcrdt_cnt : 32;
    } reg;
} SOC_QICE_QDBES_QDBES_TXREQ_DFX_ST1_UNION;
#endif
#define SOC_QICE_QDBES_QDBES_TXREQ_DFX_ST1_dfx_txreq_txcrdt_cnt_START (0)
#define SOC_QICE_QDBES_QDBES_TXREQ_DFX_ST1_dfx_txreq_txcrdt_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_txdata_stat : 32;
    } reg;
} SOC_QICE_QDBES_QDBES_TXDATA_DFX_ST0_UNION;
#endif
#define SOC_QICE_QDBES_QDBES_TXDATA_DFX_ST0_dfx_txdata_stat_START (0)
#define SOC_QICE_QDBES_QDBES_TXDATA_DFX_ST0_dfx_txdata_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_txdata_txcrdt_cnt : 32;
    } reg;
} SOC_QICE_QDBES_QDBES_TXDATA_DFX_ST1_UNION;
#endif
#define SOC_QICE_QDBES_QDBES_TXDATA_DFX_ST1_dfx_txdata_txcrdt_cnt_START (0)
#define SOC_QICE_QDBES_QDBES_TXDATA_DFX_ST1_dfx_txdata_txcrdt_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_txsrsp_stat : 32;
    } reg;
} SOC_QICE_QDBES_QDBES_TXSRSP_DFX_ST0_UNION;
#endif
#define SOC_QICE_QDBES_QDBES_TXSRSP_DFX_ST0_dfx_txsrsp_stat_START (0)
#define SOC_QICE_QDBES_QDBES_TXSRSP_DFX_ST0_dfx_txsrsp_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_txsrsp_txcrdt_cnt : 32;
    } reg;
} SOC_QICE_QDBES_QDBES_TXSRSP_DFX_ST1_UNION;
#endif
#define SOC_QICE_QDBES_QDBES_TXSRSP_DFX_ST1_dfx_txsrsp_txcrdt_cnt_START (0)
#define SOC_QICE_QDBES_QDBES_TXSRSP_DFX_ST1_dfx_txsrsp_txcrdt_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_rxdata_stat : 32;
    } reg;
} SOC_QICE_QDBES_QDBES_RXDATA_DFX_ST0_UNION;
#endif
#define SOC_QICE_QDBES_QDBES_RXDATA_DFX_ST0_dfx_rxdata_stat_START (0)
#define SOC_QICE_QDBES_QDBES_RXDATA_DFX_ST0_dfx_rxdata_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_rxdata_vccrdt_cnt : 32;
    } reg;
} SOC_QICE_QDBES_QDBES_RXDATA_DFX_ST1_UNION;
#endif
#define SOC_QICE_QDBES_QDBES_RXDATA_DFX_ST1_dfx_rxdata_vccrdt_cnt_START (0)
#define SOC_QICE_QDBES_QDBES_RXDATA_DFX_ST1_dfx_rxdata_vccrdt_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_rxcrsp_stat : 32;
    } reg;
} SOC_QICE_QDBES_QDBES_RXCRSP_DFX_ST0_UNION;
#endif
#define SOC_QICE_QDBES_QDBES_RXCRSP_DFX_ST0_dfx_rxcrsp_stat_START (0)
#define SOC_QICE_QDBES_QDBES_RXCRSP_DFX_ST0_dfx_rxcrsp_stat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_rxcrsp_vccrdt_cnt : 32;
    } reg;
} SOC_QICE_QDBES_QDBES_RXCRSP_DFX_ST1_UNION;
#endif
#define SOC_QICE_QDBES_QDBES_RXCRSP_DFX_ST1_dfx_rxcrsp_vccrdt_cnt_START (0)
#define SOC_QICE_QDBES_QDBES_RXCRSP_DFX_ST1_dfx_rxcrsp_vccrdt_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_token_cnt_0 : 32;
    } reg;
} SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST0_UNION;
#endif
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST0_dfx_token_cnt_0_START (0)
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST0_dfx_token_cnt_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_token_cnt_1 : 32;
    } reg;
} SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST1_UNION;
#endif
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST1_dfx_token_cnt_1_START (0)
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST1_dfx_token_cnt_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_token_cnt_2 : 32;
    } reg;
} SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST2_UNION;
#endif
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST2_dfx_token_cnt_2_START (0)
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST2_dfx_token_cnt_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_token_cnt_3 : 32;
    } reg;
} SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST3_UNION;
#endif
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST3_dfx_token_cnt_3_START (0)
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST3_dfx_token_cnt_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_token_cnt_4 : 32;
    } reg;
} SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST4_UNION;
#endif
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST4_dfx_token_cnt_4_START (0)
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST4_dfx_token_cnt_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_token_cnt_5 : 32;
    } reg;
} SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST5_UNION;
#endif
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST5_dfx_token_cnt_5_START (0)
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST5_dfx_token_cnt_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_token_cnt_6 : 32;
    } reg;
} SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST6_UNION;
#endif
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST6_dfx_token_cnt_6_START (0)
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST6_dfx_token_cnt_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_token_cnt_7 : 32;
    } reg;
} SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST7_UNION;
#endif
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST7_dfx_token_cnt_7_START (0)
#define SOC_QICE_QDBES_QDBES_TOKEN_DFX_ST7_dfx_token_cnt_7_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
