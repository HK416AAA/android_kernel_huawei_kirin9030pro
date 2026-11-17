#ifndef __SOC_SCE_REE_HICRYPTO_INTERFACE_H__
#define __SOC_SCE_REE_HICRYPTO_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_SCE_REE_HICRYPTO_SCE_MODE_ADDR(base) (base)
#define SOC_SCE_REE_HICRYPTO_SCE_RX_DAT_LEN_ADDR(base) ((base) + 0x0004UL)
#define SOC_SCE_REE_HICRYPTO_SCE_CFG_ADDR(base) ((base) + 0x0008UL)
#define SOC_SCE_REE_HICRYPTO_SCE_STATE_ADDR(base) ((base) + 0x000CUL)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_ADDR(base) ((base) + 0x0010UL)
#define SOC_SCE_REE_HICRYPTO_SCE_STR_RUN_ADDR(base) ((base) + 0x0014UL)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_ADDR(base) ((base) + 0x0018UL)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_EN_ADDR(base) ((base) + 0x001CUL)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_CLR_ADDR(base) ((base) + 0x0020UL)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_ADDR(base) ((base) + 0x0024UL)
#define SOC_SCE_REE_HICRYPTO_SCE_TX_DAT_LEN_ADDR(base) ((base) + 0x0030UL)
#define SOC_SCE_REE_HICRYPTO_SCE_REG_LOCK_ADDR(base) ((base) + 0x0034UL)
#define SOC_SCE_REE_HICRYPTO_SCE_DIN_ADDR(base,j) ((base) + 0x0040UL + (j) * 4)
#define SOC_SCE_REE_HICRYPTO_SCE_IVIN2_ADDR(base,n) ((base) + 0x0080UL + (n) * 4)
#define SOC_SCE_REE_HICRYPTO_SCE_DOUT_ADDR(base,k) ((base) + 0x00C0UL + (k) * 4)
#define SOC_SCE_REE_HICRYPTO_SCE_IVOUT2_ADDR(base,n) ((base) + 0x0100UL + (n) * 4)
#define SOC_SCE_REE_HICRYPTO_SCE_PADDING_EN_ADDR(base) ((base) + 0x01CCUL)
#define SOC_SCE_REE_HICRYPTO_EFUSEC_DBG_ADDR(base) ((base) + 0x01D0UL)
#define SOC_SCE_REE_HICRYPTO_GCM_AAD_LENGTH_ADDR(base) ((base) + 0x01D8UL)
#define SOC_SCE_REE_HICRYPTO_SCE_IVIN1_ADDR(base,j) ((base) + 0x01E0UL + (j) * 4)
#define SOC_SCE_REE_HICRYPTO_SCE_IVOUT1_ADDR(base,j) ((base) + 0x01F0UL + (j) * 4)
#define SOC_SCE_REE_HICRYPTO_SCE_DATA_LENTH_ALL_ADDR(base) ((base) + 0x0200UL)
#define SOC_SCE_REE_HICRYPTO_SCE_RX_READ_THRSH_ADDR(base) ((base) + 0x0208UL)
#define SOC_SCE_REE_HICRYPTO_AES_TAG_OUT_ADDR(base,j) ((base) + 0x0230UL + (j) * 4)
#define SOC_SCE_REE_HICRYPTO_RX_RES_BURST_ADDR(base) ((base) + 0x240UL)
#define SOC_SCE_REE_HICRYPTO_RX_RES_WORD_ADDR(base) ((base) + 0x244UL)
#define SOC_SCE_REE_HICRYPTO_RX_REQ_BURST_ADDR(base) ((base) + 0x248UL)
#define SOC_SCE_REE_HICRYPTO_RX_ROAD_WORD_ADDR(base) ((base) + 0x24CUL)
#define SOC_SCE_REE_HICRYPTO_TX_REQ_BURST_ADDR(base) ((base) + 0x250UL)
#define SOC_SCE_REE_HICRYPTO_TX_RES_BURST_ADDR(base) ((base) + 0x254UL)
#define SOC_SCE_REE_HICRYPTO_TX_REMAIN_BURST_ADDR(base) ((base) + 0x258UL)
#define SOC_SCE_REE_HICRYPTO_TX_REMAIN_WORD_ADDR(base) ((base) + 0x25CUL)
#define SOC_SCE_REE_HICRYPTO_FIFO_RX_WDATA_ADDR(base,j) ((base) + 0x260UL + (j) * 4)
#define SOC_SCE_REE_HICRYPTO_FIFO_RX_RDATA_ADDR(base,j) ((base) + 0x270UL + (j) * 4)
#define SOC_SCE_REE_HICRYPTO_FIFO_TX_WDATA_ADDR(base,j) ((base) + 0x280UL + (j) * 4)
#define SOC_SCE_REE_HICRYPTO_FIFO_TX_RDATA_ADDR(base,j) ((base) + 0x290UL + (j) * 4)
#define SOC_SCE_REE_HICRYPTO_SCE_SRC_ADDR_ADDR(base) ((base) + 0x02C0UL)
#define SOC_SCE_REE_HICRYPTO_SCE_DES_ADDR_ADDR(base) ((base) + 0x02C4UL)
#define SOC_SCE_REE_HICRYPTO_SCE_IV_BYPASS_ADDR(base) ((base) + 0x02CCUL)
#define SOC_SCE_REE_HICRYPTO_INT_SCE_MASK_EN_ADDR(base) ((base) + 0x02D0UL)
#define SOC_SCE_REE_HICRYPTO_INT_SCE_MASK_ADDR(base) ((base) + 0x02D4UL)
#define SOC_SCE_REE_HICRYPTO_INT_SCE_ADDR(base) ((base) + 0x02D8UL)
#define SOC_SCE_REE_HICRYPTO_INT_SCE_CLR_ADDR(base) ((base) + 0x02DCUL)
#define SOC_SCE_REE_HICRYPTO_SCE_PROT_ADDR(base) ((base) + 0x02F0UL)
#define SOC_SCE_REE_HICRYPTO_SCE_TP_MUX_ADDR(base) ((base) + 0x02F4UL)
#define SOC_SCE_REE_HICRYPTO_SCE_CACHE_CTRL_ADDR(base) ((base) + 0x300UL)
#define SOC_SCE_REE_HICRYPTO_DSCRP_MODE_EN_ADDR(base) ((base) + 0x0318UL)
#define SOC_SCE_REE_HICRYPTO_DSCRP_FIFO_WORD_ADDR(base) ((base) + 0x031cUL)
#define SOC_SCE_REE_HICRYPTO_DSCRP_CTRL_ADDR(base) ((base) + 0x0320UL)
#define SOC_SCE_REE_HICRYPTO_DSCRP_FIFO_STATUS_ADDR(base) ((base) + 0x0324UL)
#define SOC_SCE_REE_HICRYPTO_DSCRP_COUNTER_ADDR(base) ((base) + 0x0328UL)
#define SOC_SCE_REE_HICRYPTO_DSCRP_COMPLETE_CNT_ADDR(base) ((base) + 0x032CUL)
#define SOC_SCE_REE_HICRYPTO_SCE_RAM_ADDR_ADDR(base) ((base) + 0x0330UL)
#define SOC_SCE_REE_HICRYPTO_SCE_RAM_DATA_ADDR(base) ((base) + 0x0334UL)
#define SOC_SCE_REE_HICRYPTO_SCE_RAM_READY_ADDR(base) ((base) + 0x0338UL)
#define SOC_SCE_REE_HICRYPTO_SCE_RAM_CLEAR_ADDR(base) ((base) + 0x033CUL)
#define SOC_SCE_REE_HICRYPTO_SCE_KEY_ADDR(base,g) ((base) + 0x0340UL + (g) * 4)
#define SOC_SCE_REE_HICRYPTO_KEY_REG_LOCK_ADDR(base) ((base) + 0x0428UL)
#define SOC_SCE_REE_HICRYPTO_DSCRP_COMPLETE_INDEX_ADDR(base) ((base) + 0x042CUL)
#define SOC_SCE_REE_HICRYPTO_HMAC_CONFIG_ADDR(base) ((base) + 0x0430UL)
#define SOC_SCE_REE_HICRYPTO_AEAD_CTRL_ADDR(base) ((base) + 0x0438UL)
#define SOC_SCE_REE_HICRYPTO_BDQ_WPTR_ADDR(base) ((base) + 0x043CUL)
#define SOC_SCE_REE_HICRYPTO_BDQ_RPTR_ADDR(base) ((base) + 0x0440UL)
#define SOC_SCE_REE_HICRYPTO_BDQ_RPTR_PF_ADDR(base) ((base) + 0x0444UL)
#define SOC_SCE_REE_HICRYPTO_BDQ_DEPTH_ADDR(base) ((base) + 0x0448UL)
#define SOC_SCE_REE_HICRYPTO_BDQ_INIT_PTR_LOW_ADDR(base) ((base) + 0x044CUL)
#define SOC_SCE_REE_HICRYPTO_DSCRP_PF_FIFO_CTRL_ADDR(base) ((base) + 0x0450UL)
#else
#define SOC_SCE_REE_HICRYPTO_SCE_MODE_ADDR(base) (base)
#define SOC_SCE_REE_HICRYPTO_SCE_RX_DAT_LEN_ADDR(base) ((base) + 0x0004)
#define SOC_SCE_REE_HICRYPTO_SCE_CFG_ADDR(base) ((base) + 0x0008)
#define SOC_SCE_REE_HICRYPTO_SCE_STATE_ADDR(base) ((base) + 0x000C)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_ADDR(base) ((base) + 0x0010)
#define SOC_SCE_REE_HICRYPTO_SCE_STR_RUN_ADDR(base) ((base) + 0x0014)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_ADDR(base) ((base) + 0x0018)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_EN_ADDR(base) ((base) + 0x001C)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_CLR_ADDR(base) ((base) + 0x0020)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_ADDR(base) ((base) + 0x0024)
#define SOC_SCE_REE_HICRYPTO_SCE_TX_DAT_LEN_ADDR(base) ((base) + 0x0030)
#define SOC_SCE_REE_HICRYPTO_SCE_REG_LOCK_ADDR(base) ((base) + 0x0034)
#define SOC_SCE_REE_HICRYPTO_SCE_DIN_ADDR(base,j) ((base) + 0x0040 + (j) * 4)
#define SOC_SCE_REE_HICRYPTO_SCE_IVIN2_ADDR(base,n) ((base) + 0x0080 + (n) * 4)
#define SOC_SCE_REE_HICRYPTO_SCE_DOUT_ADDR(base,k) ((base) + 0x00C0 + (k) * 4)
#define SOC_SCE_REE_HICRYPTO_SCE_IVOUT2_ADDR(base,n) ((base) + 0x0100 + (n) * 4)
#define SOC_SCE_REE_HICRYPTO_SCE_PADDING_EN_ADDR(base) ((base) + 0x01CC)
#define SOC_SCE_REE_HICRYPTO_EFUSEC_DBG_ADDR(base) ((base) + 0x01D0)
#define SOC_SCE_REE_HICRYPTO_GCM_AAD_LENGTH_ADDR(base) ((base) + 0x01D8)
#define SOC_SCE_REE_HICRYPTO_SCE_IVIN1_ADDR(base,j) ((base) + 0x01E0 + (j) * 4)
#define SOC_SCE_REE_HICRYPTO_SCE_IVOUT1_ADDR(base,j) ((base) + 0x01F0 + (j) * 4)
#define SOC_SCE_REE_HICRYPTO_SCE_DATA_LENTH_ALL_ADDR(base) ((base) + 0x0200)
#define SOC_SCE_REE_HICRYPTO_SCE_RX_READ_THRSH_ADDR(base) ((base) + 0x0208)
#define SOC_SCE_REE_HICRYPTO_AES_TAG_OUT_ADDR(base,j) ((base) + 0x0230 + (j) * 4)
#define SOC_SCE_REE_HICRYPTO_RX_RES_BURST_ADDR(base) ((base) + 0x240)
#define SOC_SCE_REE_HICRYPTO_RX_RES_WORD_ADDR(base) ((base) + 0x244)
#define SOC_SCE_REE_HICRYPTO_RX_REQ_BURST_ADDR(base) ((base) + 0x248)
#define SOC_SCE_REE_HICRYPTO_RX_ROAD_WORD_ADDR(base) ((base) + 0x24C)
#define SOC_SCE_REE_HICRYPTO_TX_REQ_BURST_ADDR(base) ((base) + 0x250)
#define SOC_SCE_REE_HICRYPTO_TX_RES_BURST_ADDR(base) ((base) + 0x254)
#define SOC_SCE_REE_HICRYPTO_TX_REMAIN_BURST_ADDR(base) ((base) + 0x258)
#define SOC_SCE_REE_HICRYPTO_TX_REMAIN_WORD_ADDR(base) ((base) + 0x25C)
#define SOC_SCE_REE_HICRYPTO_FIFO_RX_WDATA_ADDR(base,j) ((base) + 0x260 + (j) * 4)
#define SOC_SCE_REE_HICRYPTO_FIFO_RX_RDATA_ADDR(base,j) ((base) + 0x270 + (j) * 4)
#define SOC_SCE_REE_HICRYPTO_FIFO_TX_WDATA_ADDR(base,j) ((base) + 0x280 + (j) * 4)
#define SOC_SCE_REE_HICRYPTO_FIFO_TX_RDATA_ADDR(base,j) ((base) + 0x290 + (j) * 4)
#define SOC_SCE_REE_HICRYPTO_SCE_SRC_ADDR_ADDR(base) ((base) + 0x02C0)
#define SOC_SCE_REE_HICRYPTO_SCE_DES_ADDR_ADDR(base) ((base) + 0x02C4)
#define SOC_SCE_REE_HICRYPTO_SCE_IV_BYPASS_ADDR(base) ((base) + 0x02CC)
#define SOC_SCE_REE_HICRYPTO_INT_SCE_MASK_EN_ADDR(base) ((base) + 0x02D0)
#define SOC_SCE_REE_HICRYPTO_INT_SCE_MASK_ADDR(base) ((base) + 0x02D4)
#define SOC_SCE_REE_HICRYPTO_INT_SCE_ADDR(base) ((base) + 0x02D8)
#define SOC_SCE_REE_HICRYPTO_INT_SCE_CLR_ADDR(base) ((base) + 0x02DC)
#define SOC_SCE_REE_HICRYPTO_SCE_PROT_ADDR(base) ((base) + 0x02F0)
#define SOC_SCE_REE_HICRYPTO_SCE_TP_MUX_ADDR(base) ((base) + 0x02F4)
#define SOC_SCE_REE_HICRYPTO_SCE_CACHE_CTRL_ADDR(base) ((base) + 0x300)
#define SOC_SCE_REE_HICRYPTO_DSCRP_MODE_EN_ADDR(base) ((base) + 0x0318)
#define SOC_SCE_REE_HICRYPTO_DSCRP_FIFO_WORD_ADDR(base) ((base) + 0x031c)
#define SOC_SCE_REE_HICRYPTO_DSCRP_CTRL_ADDR(base) ((base) + 0x0320)
#define SOC_SCE_REE_HICRYPTO_DSCRP_FIFO_STATUS_ADDR(base) ((base) + 0x0324)
#define SOC_SCE_REE_HICRYPTO_DSCRP_COUNTER_ADDR(base) ((base) + 0x0328)
#define SOC_SCE_REE_HICRYPTO_DSCRP_COMPLETE_CNT_ADDR(base) ((base) + 0x032C)
#define SOC_SCE_REE_HICRYPTO_SCE_RAM_ADDR_ADDR(base) ((base) + 0x0330)
#define SOC_SCE_REE_HICRYPTO_SCE_RAM_DATA_ADDR(base) ((base) + 0x0334)
#define SOC_SCE_REE_HICRYPTO_SCE_RAM_READY_ADDR(base) ((base) + 0x0338)
#define SOC_SCE_REE_HICRYPTO_SCE_RAM_CLEAR_ADDR(base) ((base) + 0x033C)
#define SOC_SCE_REE_HICRYPTO_SCE_KEY_ADDR(base,g) ((base) + 0x0340 + (g) * 4)
#define SOC_SCE_REE_HICRYPTO_KEY_REG_LOCK_ADDR(base) ((base) + 0x0428)
#define SOC_SCE_REE_HICRYPTO_DSCRP_COMPLETE_INDEX_ADDR(base) ((base) + 0x042C)
#define SOC_SCE_REE_HICRYPTO_HMAC_CONFIG_ADDR(base) ((base) + 0x0430)
#define SOC_SCE_REE_HICRYPTO_AEAD_CTRL_ADDR(base) ((base) + 0x0438)
#define SOC_SCE_REE_HICRYPTO_BDQ_WPTR_ADDR(base) ((base) + 0x043C)
#define SOC_SCE_REE_HICRYPTO_BDQ_RPTR_ADDR(base) ((base) + 0x0440)
#define SOC_SCE_REE_HICRYPTO_BDQ_RPTR_PF_ADDR(base) ((base) + 0x0444)
#define SOC_SCE_REE_HICRYPTO_BDQ_DEPTH_ADDR(base) ((base) + 0x0448)
#define SOC_SCE_REE_HICRYPTO_BDQ_INIT_PTR_LOW_ADDR(base) ((base) + 0x044C)
#define SOC_SCE_REE_HICRYPTO_DSCRP_PF_FIFO_CTRL_ADDR(base) ((base) + 0x0450)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_rx_dma_mode : 3;
        unsigned int reserved_0 : 1;
        unsigned int sce_ip_sel : 4;
        unsigned int sce_tx_dma_mode : 3;
        unsigned int reserved_1 : 21;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_MODE_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_MODE_sce_rx_dma_mode_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_MODE_sce_rx_dma_mode_END (2)
#define SOC_SCE_REE_HICRYPTO_SCE_MODE_sce_ip_sel_START (4)
#define SOC_SCE_REE_HICRYPTO_SCE_MODE_sce_ip_sel_END (7)
#define SOC_SCE_REE_HICRYPTO_SCE_MODE_sce_tx_dma_mode_START (8)
#define SOC_SCE_REE_HICRYPTO_SCE_MODE_sce_tx_dma_mode_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_rx_dat_len : 32;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_RX_DAT_LEN_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_RX_DAT_LEN_sce_rx_dat_len_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_RX_DAT_LEN_sce_rx_dat_len_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int xts_init_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 2;
        unsigned int sce_decrypt : 1;
        unsigned int reserved_2 : 3;
        unsigned int sce_mode : 4;
        unsigned int sce_key_length : 2;
        unsigned int reserved_3 : 2;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 3;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 3;
        unsigned int tdes : 1;
        unsigned int reserved_8 : 3;
        unsigned int tx_big_little_end : 1;
        unsigned int rx_big_little_end : 1;
        unsigned int sce_padding_sel : 1;
        unsigned int reserved_9 : 1;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_CFG_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_CFG_xts_init_en_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_CFG_xts_init_en_END (0)
#define SOC_SCE_REE_HICRYPTO_SCE_CFG_sce_decrypt_START (4)
#define SOC_SCE_REE_HICRYPTO_SCE_CFG_sce_decrypt_END (4)
#define SOC_SCE_REE_HICRYPTO_SCE_CFG_sce_mode_START (8)
#define SOC_SCE_REE_HICRYPTO_SCE_CFG_sce_mode_END (11)
#define SOC_SCE_REE_HICRYPTO_SCE_CFG_sce_key_length_START (12)
#define SOC_SCE_REE_HICRYPTO_SCE_CFG_sce_key_length_END (13)
#define SOC_SCE_REE_HICRYPTO_SCE_CFG_tdes_START (24)
#define SOC_SCE_REE_HICRYPTO_SCE_CFG_tdes_END (24)
#define SOC_SCE_REE_HICRYPTO_SCE_CFG_tx_big_little_end_START (28)
#define SOC_SCE_REE_HICRYPTO_SCE_CFG_tx_big_little_end_END (28)
#define SOC_SCE_REE_HICRYPTO_SCE_CFG_rx_big_little_end_START (29)
#define SOC_SCE_REE_HICRYPTO_SCE_CFG_rx_big_little_end_END (29)
#define SOC_SCE_REE_HICRYPTO_SCE_CFG_sce_padding_sel_START (30)
#define SOC_SCE_REE_HICRYPTO_SCE_CFG_sce_padding_sel_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gcm_tag_compare_flag : 1;
        unsigned int reserved_0 : 3;
        unsigned int sce_busy_reg : 1;
        unsigned int reserved_1 : 3;
        unsigned int sce_done_reg : 1;
        unsigned int sce_hmac_done_reg : 1;
        unsigned int reserved_2 : 2;
        unsigned int ctrl_rx_busy : 1;
        unsigned int reserved_3 : 3;
        unsigned int ctrl_tx_busy : 1;
        unsigned int reserved_4 : 15;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_STATE_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_STATE_gcm_tag_compare_flag_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_STATE_gcm_tag_compare_flag_END (0)
#define SOC_SCE_REE_HICRYPTO_SCE_STATE_sce_busy_reg_START (4)
#define SOC_SCE_REE_HICRYPTO_SCE_STATE_sce_busy_reg_END (4)
#define SOC_SCE_REE_HICRYPTO_SCE_STATE_sce_done_reg_START (8)
#define SOC_SCE_REE_HICRYPTO_SCE_STATE_sce_done_reg_END (8)
#define SOC_SCE_REE_HICRYPTO_SCE_STATE_sce_hmac_done_reg_START (9)
#define SOC_SCE_REE_HICRYPTO_SCE_STATE_sce_hmac_done_reg_END (9)
#define SOC_SCE_REE_HICRYPTO_SCE_STATE_ctrl_rx_busy_START (12)
#define SOC_SCE_REE_HICRYPTO_SCE_STATE_ctrl_rx_busy_END (12)
#define SOC_SCE_REE_HICRYPTO_SCE_STATE_ctrl_tx_busy_START (16)
#define SOC_SCE_REE_HICRYPTO_SCE_STATE_ctrl_tx_busy_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hmac_fifo_cnt : 4;
        unsigned int hmac_fifo_empty : 1;
        unsigned int hmac_fifo_full : 1;
        unsigned int hmac_fifo_aempty : 1;
        unsigned int hmac_fifo_afull : 1;
        unsigned int fifo_rx_afull : 1;
        unsigned int fifo_rx_aempty : 1;
        unsigned int fifo_rx_empty : 1;
        unsigned int fifo_rx_full : 1;
        unsigned int fifo_rx_cnt : 8;
        unsigned int fifo_tx_afull : 1;
        unsigned int fifo_tx_aempty : 1;
        unsigned int fifo_tx_empty : 1;
        unsigned int fifo_tx_full : 1;
        unsigned int fifo_tx_cnt : 8;
    } reg;
} SOC_SCE_REE_HICRYPTO_FIFO_LINE_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_hmac_fifo_cnt_START (0)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_hmac_fifo_cnt_END (3)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_hmac_fifo_empty_START (4)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_hmac_fifo_empty_END (4)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_hmac_fifo_full_START (5)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_hmac_fifo_full_END (5)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_hmac_fifo_aempty_START (6)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_hmac_fifo_aempty_END (6)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_hmac_fifo_afull_START (7)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_hmac_fifo_afull_END (7)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_fifo_rx_afull_START (8)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_fifo_rx_afull_END (8)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_fifo_rx_aempty_START (9)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_fifo_rx_aempty_END (9)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_fifo_rx_empty_START (10)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_fifo_rx_empty_END (10)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_fifo_rx_full_START (11)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_fifo_rx_full_END (11)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_fifo_rx_cnt_START (12)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_fifo_rx_cnt_END (19)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_fifo_tx_afull_START (20)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_fifo_tx_afull_END (20)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_fifo_tx_aempty_START (21)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_fifo_tx_aempty_END (21)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_fifo_tx_empty_START (22)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_fifo_tx_empty_END (22)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_fifo_tx_full_START (23)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_fifo_tx_full_END (23)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_fifo_tx_cnt_START (24)
#define SOC_SCE_REE_HICRYPTO_FIFO_LINE_fifo_tx_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_run : 1;
        unsigned int reserved_0: 3;
        unsigned int sce_str : 1;
        unsigned int reserved_1: 3;
        unsigned int reserved_2: 24;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_STR_RUN_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_STR_RUN_sce_run_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_STR_RUN_sce_run_END (0)
#define SOC_SCE_REE_HICRYPTO_SCE_STR_RUN_sce_str_START (4)
#define SOC_SCE_REE_HICRYPTO_SCE_STR_RUN_sce_str_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aes_alarm : 4;
        unsigned int sm4_alarm : 4;
        unsigned int des_alarm : 4;
        unsigned int sce_alarm : 1;
        unsigned int reg_check_alarm : 1;
        unsigned int reg_access_alarm : 1;
        unsigned int rx_response_alarm : 1;
        unsigned int tx_response_alarm : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_ALARM_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_aes_alarm_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_aes_alarm_END (3)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_sm4_alarm_START (4)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_sm4_alarm_END (7)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_des_alarm_START (8)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_des_alarm_END (11)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_sce_alarm_START (12)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_sce_alarm_END (12)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_reg_check_alarm_START (13)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_reg_check_alarm_END (13)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_reg_access_alarm_START (14)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_reg_access_alarm_END (14)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_rx_response_alarm_START (15)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_rx_response_alarm_END (15)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_tx_response_alarm_START (16)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_tx_response_alarm_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aes_alaram_mask_en : 4;
        unsigned int sm4_alaram_mask_en : 4;
        unsigned int des_alaram_mask_en : 4;
        unsigned int alarm_mask_en : 4;
        unsigned int reg_check_alarm_mask_en : 4;
        unsigned int reg_access_alarm_mask_en : 4;
        unsigned int rx_response_alarm_mask_en : 4;
        unsigned int tx_response_alarm_mask_en : 4;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_EN_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_EN_aes_alaram_mask_en_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_EN_aes_alaram_mask_en_END (3)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_EN_sm4_alaram_mask_en_START (4)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_EN_sm4_alaram_mask_en_END (7)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_EN_des_alaram_mask_en_START (8)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_EN_des_alaram_mask_en_END (11)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_EN_alarm_mask_en_START (12)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_EN_alarm_mask_en_END (15)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_EN_reg_check_alarm_mask_en_START (16)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_EN_reg_check_alarm_mask_en_END (19)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_EN_reg_access_alarm_mask_en_START (20)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_EN_reg_access_alarm_mask_en_END (23)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_EN_rx_response_alarm_mask_en_START (24)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_EN_rx_response_alarm_mask_en_END (27)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_EN_tx_response_alarm_mask_en_START (28)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_EN_tx_response_alarm_mask_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aes_alaram_clr : 4;
        unsigned int sm4_alaram_clr : 4;
        unsigned int des_alaram_clr : 4;
        unsigned int alaram_clr : 4;
        unsigned int reg_check_alarm_clr : 4;
        unsigned int reg_access_alarm_clr : 4;
        unsigned int rx_response_alarm_clr : 4;
        unsigned int tx_response_alarm_clr : 4;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_ALARM_CLR_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_CLR_aes_alaram_clr_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_CLR_aes_alaram_clr_END (3)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_CLR_sm4_alaram_clr_START (4)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_CLR_sm4_alaram_clr_END (7)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_CLR_des_alaram_clr_START (8)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_CLR_des_alaram_clr_END (11)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_CLR_alaram_clr_START (12)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_CLR_alaram_clr_END (15)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_CLR_reg_check_alarm_clr_START (16)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_CLR_reg_check_alarm_clr_END (19)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_CLR_reg_access_alarm_clr_START (20)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_CLR_reg_access_alarm_clr_END (23)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_CLR_rx_response_alarm_clr_START (24)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_CLR_rx_response_alarm_clr_END (27)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_CLR_tx_response_alarm_clr_START (28)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_CLR_tx_response_alarm_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aes_alaram_mask : 4;
        unsigned int sm4_alaram_mask : 4;
        unsigned int des_alaram_mask : 4;
        unsigned int sce_alarm_mask : 1;
        unsigned int reg_check_alarm_mask : 1;
        unsigned int reg_access_alarm_mask : 1;
        unsigned int rx_response_alarm_mask : 1;
        unsigned int tx_response_alarm_mask : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_aes_alaram_mask_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_aes_alaram_mask_END (3)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_sm4_alaram_mask_START (4)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_sm4_alaram_mask_END (7)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_des_alaram_mask_START (8)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_des_alaram_mask_END (11)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_sce_alarm_mask_START (12)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_sce_alarm_mask_END (12)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_reg_check_alarm_mask_START (13)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_reg_check_alarm_mask_END (13)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_reg_access_alarm_mask_START (14)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_reg_access_alarm_mask_END (14)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_rx_response_alarm_mask_START (15)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_rx_response_alarm_mask_END (15)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_tx_response_alarm_mask_START (16)
#define SOC_SCE_REE_HICRYPTO_SCE_ALARM_MASK_tx_response_alarm_mask_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_tx_dat_len : 32;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_TX_DAT_LEN_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_TX_DAT_LEN_sce_tx_dat_len_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_TX_DAT_LEN_sce_tx_dat_len_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_reg_lock : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_REG_LOCK_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_REG_LOCK_sce_reg_lock_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_REG_LOCK_sce_reg_lock_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_din : 32;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_DIN_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_DIN_sce_din_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_DIN_sce_din_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_ivin2 : 32;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_IVIN2_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_IVIN2_sce_ivin2_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_IVIN2_sce_ivin2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_dout : 32;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_DOUT_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_DOUT_sce_dout_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_DOUT_sce_dout_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_ivout2 : 32;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_IVOUT2_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_IVOUT2_sce_ivout2_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_IVOUT2_sce_ivout2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_padding_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_PADDING_EN_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_PADDING_EN_sce_padding_en_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_PADDING_EN_sce_padding_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int debug_disable : 1;
        unsigned int tdes_disable : 1;
        unsigned int des_disable : 1;
        unsigned int sm4_disable : 1;
        unsigned int sm3_disable : 1;
        unsigned int sha1_disable : 1;
        unsigned int md5_disable : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_SCE_REE_HICRYPTO_EFUSEC_DBG_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_EFUSEC_DBG_debug_disable_START (0)
#define SOC_SCE_REE_HICRYPTO_EFUSEC_DBG_debug_disable_END (0)
#define SOC_SCE_REE_HICRYPTO_EFUSEC_DBG_tdes_disable_START (1)
#define SOC_SCE_REE_HICRYPTO_EFUSEC_DBG_tdes_disable_END (1)
#define SOC_SCE_REE_HICRYPTO_EFUSEC_DBG_des_disable_START (2)
#define SOC_SCE_REE_HICRYPTO_EFUSEC_DBG_des_disable_END (2)
#define SOC_SCE_REE_HICRYPTO_EFUSEC_DBG_sm4_disable_START (3)
#define SOC_SCE_REE_HICRYPTO_EFUSEC_DBG_sm4_disable_END (3)
#define SOC_SCE_REE_HICRYPTO_EFUSEC_DBG_sm3_disable_START (4)
#define SOC_SCE_REE_HICRYPTO_EFUSEC_DBG_sm3_disable_END (4)
#define SOC_SCE_REE_HICRYPTO_EFUSEC_DBG_sha1_disable_START (5)
#define SOC_SCE_REE_HICRYPTO_EFUSEC_DBG_sha1_disable_END (5)
#define SOC_SCE_REE_HICRYPTO_EFUSEC_DBG_md5_disable_START (6)
#define SOC_SCE_REE_HICRYPTO_EFUSEC_DBG_md5_disable_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gcm_aad_length : 32;
    } reg;
} SOC_SCE_REE_HICRYPTO_GCM_AAD_LENGTH_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_GCM_AAD_LENGTH_gcm_aad_length_START (0)
#define SOC_SCE_REE_HICRYPTO_GCM_AAD_LENGTH_gcm_aad_length_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_ivin1 : 32;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_IVIN1_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_IVIN1_sce_ivin1_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_IVIN1_sce_ivin1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_ivout1 : 32;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_IVOUT1_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_IVOUT1_sce_ivout1_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_IVOUT1_sce_ivout1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_data_lenth_all : 32;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_DATA_LENTH_ALL_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_DATA_LENTH_ALL_sce_data_lenth_all_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_DATA_LENTH_ALL_sce_data_lenth_all_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_rx_read_thrsh : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_RX_READ_THRSH_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_RX_READ_THRSH_sce_rx_read_thrsh_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_RX_READ_THRSH_sce_rx_read_thrsh_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aes_tag_out : 32;
    } reg;
} SOC_SCE_REE_HICRYPTO_AES_TAG_OUT_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_AES_TAG_OUT_aes_tag_out_START (0)
#define SOC_SCE_REE_HICRYPTO_AES_TAG_OUT_aes_tag_out_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnt_res_burst_rx : 32;
    } reg;
} SOC_SCE_REE_HICRYPTO_RX_RES_BURST_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_RX_RES_BURST_cnt_res_burst_rx_START (0)
#define SOC_SCE_REE_HICRYPTO_RX_RES_BURST_cnt_res_burst_rx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnt_res_word_rx : 32;
    } reg;
} SOC_SCE_REE_HICRYPTO_RX_RES_WORD_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_RX_RES_WORD_cnt_res_word_rx_START (0)
#define SOC_SCE_REE_HICRYPTO_RX_RES_WORD_cnt_res_word_rx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnt_req_burst_rx : 32;
    } reg;
} SOC_SCE_REE_HICRYPTO_RX_REQ_BURST_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_RX_REQ_BURST_cnt_req_burst_rx_START (0)
#define SOC_SCE_REE_HICRYPTO_RX_REQ_BURST_cnt_req_burst_rx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnt_road_word_rx : 32;
    } reg;
} SOC_SCE_REE_HICRYPTO_RX_ROAD_WORD_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_RX_ROAD_WORD_cnt_road_word_rx_START (0)
#define SOC_SCE_REE_HICRYPTO_RX_ROAD_WORD_cnt_road_word_rx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnt_req_burst_tx : 32;
    } reg;
} SOC_SCE_REE_HICRYPTO_TX_REQ_BURST_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_TX_REQ_BURST_cnt_req_burst_tx_START (0)
#define SOC_SCE_REE_HICRYPTO_TX_REQ_BURST_cnt_req_burst_tx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnt_res_burst_tx : 32;
    } reg;
} SOC_SCE_REE_HICRYPTO_TX_RES_BURST_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_TX_RES_BURST_cnt_res_burst_tx_START (0)
#define SOC_SCE_REE_HICRYPTO_TX_RES_BURST_cnt_res_burst_tx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnt_remain_burst_tx : 32;
    } reg;
} SOC_SCE_REE_HICRYPTO_TX_REMAIN_BURST_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_TX_REMAIN_BURST_cnt_remain_burst_tx_START (0)
#define SOC_SCE_REE_HICRYPTO_TX_REMAIN_BURST_cnt_remain_burst_tx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnt_remain_word_tx : 32;
    } reg;
} SOC_SCE_REE_HICRYPTO_TX_REMAIN_WORD_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_TX_REMAIN_WORD_cnt_remain_word_tx_START (0)
#define SOC_SCE_REE_HICRYPTO_TX_REMAIN_WORD_cnt_remain_word_tx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fifo_rx_wdata : 32;
    } reg;
} SOC_SCE_REE_HICRYPTO_FIFO_RX_WDATA_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_FIFO_RX_WDATA_fifo_rx_wdata_START (0)
#define SOC_SCE_REE_HICRYPTO_FIFO_RX_WDATA_fifo_rx_wdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fifo_rx_rdata : 32;
    } reg;
} SOC_SCE_REE_HICRYPTO_FIFO_RX_RDATA_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_FIFO_RX_RDATA_fifo_rx_rdata_START (0)
#define SOC_SCE_REE_HICRYPTO_FIFO_RX_RDATA_fifo_rx_rdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fifo_tx_wdata : 32;
    } reg;
} SOC_SCE_REE_HICRYPTO_FIFO_TX_WDATA_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_FIFO_TX_WDATA_fifo_tx_wdata_START (0)
#define SOC_SCE_REE_HICRYPTO_FIFO_TX_WDATA_fifo_tx_wdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fifo_tx_rdata : 32;
    } reg;
} SOC_SCE_REE_HICRYPTO_FIFO_TX_RDATA_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_FIFO_TX_RDATA_fifo_tx_rdata_START (0)
#define SOC_SCE_REE_HICRYPTO_FIFO_TX_RDATA_fifo_tx_rdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_src_addr_low : 32;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_SRC_ADDR_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_SRC_ADDR_sce_src_addr_low_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_SRC_ADDR_sce_src_addr_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_des_addr_low : 32;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_DES_ADDR_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_DES_ADDR_sce_des_addr_low_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_DES_ADDR_sce_des_addr_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iv_sel : 4;
        unsigned int sce_src_addr_high : 12;
        unsigned int sce_des_addr_high : 12;
        unsigned int reserved : 4;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_IV_BYPASS_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_IV_BYPASS_iv_sel_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_IV_BYPASS_iv_sel_END (3)
#define SOC_SCE_REE_HICRYPTO_SCE_IV_BYPASS_sce_src_addr_high_START (4)
#define SOC_SCE_REE_HICRYPTO_SCE_IV_BYPASS_sce_src_addr_high_END (15)
#define SOC_SCE_REE_HICRYPTO_SCE_IV_BYPASS_sce_des_addr_high_START (16)
#define SOC_SCE_REE_HICRYPTO_SCE_IV_BYPASS_sce_des_addr_high_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_master_int_mask_en : 4;
        unsigned int dscrp_finish_int_mask_en : 4;
        unsigned int dscrp_aempty_int_mask_en : 4;
        unsigned int dscrp_overflow_int_mask_en : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_SCE_REE_HICRYPTO_INT_SCE_MASK_EN_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_INT_SCE_MASK_EN_sce_master_int_mask_en_START (0)
#define SOC_SCE_REE_HICRYPTO_INT_SCE_MASK_EN_sce_master_int_mask_en_END (3)
#define SOC_SCE_REE_HICRYPTO_INT_SCE_MASK_EN_dscrp_finish_int_mask_en_START (4)
#define SOC_SCE_REE_HICRYPTO_INT_SCE_MASK_EN_dscrp_finish_int_mask_en_END (7)
#define SOC_SCE_REE_HICRYPTO_INT_SCE_MASK_EN_dscrp_aempty_int_mask_en_START (8)
#define SOC_SCE_REE_HICRYPTO_INT_SCE_MASK_EN_dscrp_aempty_int_mask_en_END (11)
#define SOC_SCE_REE_HICRYPTO_INT_SCE_MASK_EN_dscrp_overflow_int_mask_en_START (12)
#define SOC_SCE_REE_HICRYPTO_INT_SCE_MASK_EN_dscrp_overflow_int_mask_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_int_mask : 4;
        unsigned int sce_int_status : 4;
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_SCE_REE_HICRYPTO_INT_SCE_MASK_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_INT_SCE_MASK_sce_int_mask_START (0)
#define SOC_SCE_REE_HICRYPTO_INT_SCE_MASK_sce_int_mask_END (3)
#define SOC_SCE_REE_HICRYPTO_INT_SCE_MASK_sce_int_status_START (4)
#define SOC_SCE_REE_HICRYPTO_INT_SCE_MASK_sce_int_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_int : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_SCE_REE_HICRYPTO_INT_SCE_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_INT_SCE_sce_int_START (0)
#define SOC_SCE_REE_HICRYPTO_INT_SCE_sce_int_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_master_int_clr : 4;
        unsigned int dscrp_finish_int_clr : 4;
        unsigned int dscrp_aempty_int_clr : 4;
        unsigned int dscrp_overflow_int_clr : 4;
        unsigned int reserved : 16;
    } reg;
} SOC_SCE_REE_HICRYPTO_INT_SCE_CLR_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_INT_SCE_CLR_sce_master_int_clr_START (0)
#define SOC_SCE_REE_HICRYPTO_INT_SCE_CLR_sce_master_int_clr_END (3)
#define SOC_SCE_REE_HICRYPTO_INT_SCE_CLR_dscrp_finish_int_clr_START (4)
#define SOC_SCE_REE_HICRYPTO_INT_SCE_CLR_dscrp_finish_int_clr_END (7)
#define SOC_SCE_REE_HICRYPTO_INT_SCE_CLR_dscrp_aempty_int_clr_START (8)
#define SOC_SCE_REE_HICRYPTO_INT_SCE_CLR_dscrp_aempty_int_clr_END (11)
#define SOC_SCE_REE_HICRYPTO_INT_SCE_CLR_dscrp_overflow_int_clr_START (12)
#define SOC_SCE_REE_HICRYPTO_INT_SCE_CLR_dscrp_overflow_int_clr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dw_axi_gm_prot : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_PROT_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_PROT_dw_axi_gm_prot_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_PROT_dw_axi_gm_prot_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_tp_mux : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_TP_MUX_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_TP_MUX_sce_tp_mux_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_TP_MUX_sce_tp_mux_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mcache_wr : 4;
        unsigned int mcache_rd : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_CACHE_CTRL_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_CACHE_CTRL_mcache_wr_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_CACHE_CTRL_mcache_wr_END (3)
#define SOC_SCE_REE_HICRYPTO_SCE_CACHE_CTRL_mcache_rd_START (4)
#define SOC_SCE_REE_HICRYPTO_SCE_CACHE_CTRL_mcache_rd_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dscrp_mode_en : 4;
        unsigned int dscrp_reset : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_SCE_REE_HICRYPTO_DSCRP_MODE_EN_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_DSCRP_MODE_EN_dscrp_mode_en_START (0)
#define SOC_SCE_REE_HICRYPTO_DSCRP_MODE_EN_dscrp_mode_en_END (3)
#define SOC_SCE_REE_HICRYPTO_DSCRP_MODE_EN_dscrp_reset_START (4)
#define SOC_SCE_REE_HICRYPTO_DSCRP_MODE_EN_dscrp_reset_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dscrp_fifo_word : 32;
    } reg;
} SOC_SCE_REE_HICRYPTO_DSCRP_FIFO_WORD_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_DSCRP_FIFO_WORD_dscrp_fifo_word_START (0)
#define SOC_SCE_REE_HICRYPTO_DSCRP_FIFO_WORD_dscrp_fifo_word_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dscrp_fifo_waterline : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_SCE_REE_HICRYPTO_DSCRP_CTRL_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_DSCRP_CTRL_dscrp_fifo_waterline_START (0)
#define SOC_SCE_REE_HICRYPTO_DSCRP_CTRL_dscrp_fifo_waterline_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dscrp_fifo_cnt : 12;
        unsigned int dscrp_fifo_empty : 1;
        unsigned int dscrp_fifo_full : 1;
        unsigned int dscrp_fifo_aempty : 1;
        unsigned int dscrp_fifo_afull : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_SCE_REE_HICRYPTO_DSCRP_FIFO_STATUS_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_DSCRP_FIFO_STATUS_dscrp_fifo_cnt_START (0)
#define SOC_SCE_REE_HICRYPTO_DSCRP_FIFO_STATUS_dscrp_fifo_cnt_END (11)
#define SOC_SCE_REE_HICRYPTO_DSCRP_FIFO_STATUS_dscrp_fifo_empty_START (12)
#define SOC_SCE_REE_HICRYPTO_DSCRP_FIFO_STATUS_dscrp_fifo_empty_END (12)
#define SOC_SCE_REE_HICRYPTO_DSCRP_FIFO_STATUS_dscrp_fifo_full_START (13)
#define SOC_SCE_REE_HICRYPTO_DSCRP_FIFO_STATUS_dscrp_fifo_full_END (13)
#define SOC_SCE_REE_HICRYPTO_DSCRP_FIFO_STATUS_dscrp_fifo_aempty_START (14)
#define SOC_SCE_REE_HICRYPTO_DSCRP_FIFO_STATUS_dscrp_fifo_aempty_END (14)
#define SOC_SCE_REE_HICRYPTO_DSCRP_FIFO_STATUS_dscrp_fifo_afull_START (15)
#define SOC_SCE_REE_HICRYPTO_DSCRP_FIFO_STATUS_dscrp_fifo_afull_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dscrp_rd_cnt : 16;
        unsigned int dscrp_wr_cnt : 16;
    } reg;
} SOC_SCE_REE_HICRYPTO_DSCRP_COUNTER_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_DSCRP_COUNTER_dscrp_rd_cnt_START (0)
#define SOC_SCE_REE_HICRYPTO_DSCRP_COUNTER_dscrp_rd_cnt_END (15)
#define SOC_SCE_REE_HICRYPTO_DSCRP_COUNTER_dscrp_wr_cnt_START (16)
#define SOC_SCE_REE_HICRYPTO_DSCRP_COUNTER_dscrp_wr_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dscrp_complete_cnt : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_SCE_REE_HICRYPTO_DSCRP_COMPLETE_CNT_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_DSCRP_COMPLETE_CNT_dscrp_complete_cnt_START (0)
#define SOC_SCE_REE_HICRYPTO_DSCRP_COMPLETE_CNT_dscrp_complete_cnt_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_ram_addr : 11;
        unsigned int sce_ram_wren : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_RAM_ADDR_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_RAM_ADDR_sce_ram_addr_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_RAM_ADDR_sce_ram_addr_END (10)
#define SOC_SCE_REE_HICRYPTO_SCE_RAM_ADDR_sce_ram_wren_START (11)
#define SOC_SCE_REE_HICRYPTO_SCE_RAM_ADDR_sce_ram_wren_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_ram_data : 32;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_RAM_DATA_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_RAM_DATA_sce_ram_data_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_RAM_DATA_sce_ram_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_ram_ready : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_RAM_READY_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_RAM_READY_sce_ram_ready_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_RAM_READY_sce_ram_ready_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_ram_clear : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_RAM_CLEAR_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_RAM_CLEAR_sce_ram_clear_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_RAM_CLEAR_sce_ram_clear_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sce_config_key : 32;
    } reg;
} SOC_SCE_REE_HICRYPTO_SCE_KEY_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_SCE_KEY_sce_config_key_START (0)
#define SOC_SCE_REE_HICRYPTO_SCE_KEY_sce_config_key_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int key_reg_lock : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_SCE_REE_HICRYPTO_KEY_REG_LOCK_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_KEY_REG_LOCK_key_reg_lock_START (0)
#define SOC_SCE_REE_HICRYPTO_KEY_REG_LOCK_key_reg_lock_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dscrp_complete_index : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_SCE_REE_HICRYPTO_DSCRP_COMPLETE_INDEX_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_DSCRP_COMPLETE_INDEX_dscrp_complete_index_START (0)
#define SOC_SCE_REE_HICRYPTO_DSCRP_COMPLETE_INDEX_dscrp_complete_index_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hmac_mode_en : 4;
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 4;
        unsigned int hmac_init_en : 4;
        unsigned int iv_src_sel : 4;
        unsigned int hmac_accum_data_en : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 10;
    } reg;
} SOC_SCE_REE_HICRYPTO_HMAC_CONFIG_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_HMAC_CONFIG_hmac_mode_en_START (0)
#define SOC_SCE_REE_HICRYPTO_HMAC_CONFIG_hmac_mode_en_END (3)
#define SOC_SCE_REE_HICRYPTO_HMAC_CONFIG_hmac_init_en_START (12)
#define SOC_SCE_REE_HICRYPTO_HMAC_CONFIG_hmac_init_en_END (15)
#define SOC_SCE_REE_HICRYPTO_HMAC_CONFIG_iv_src_sel_START (16)
#define SOC_SCE_REE_HICRYPTO_HMAC_CONFIG_iv_src_sel_END (19)
#define SOC_SCE_REE_HICRYPTO_HMAC_CONFIG_hmac_accum_data_en_START (20)
#define SOC_SCE_REE_HICRYPTO_HMAC_CONFIG_hmac_accum_data_en_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int data_path_sel : 2;
        unsigned int auth_hash_sel : 4;
        unsigned int reserved : 26;
    } reg;
} SOC_SCE_REE_HICRYPTO_AEAD_CTRL_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_AEAD_CTRL_data_path_sel_START (0)
#define SOC_SCE_REE_HICRYPTO_AEAD_CTRL_data_path_sel_END (1)
#define SOC_SCE_REE_HICRYPTO_AEAD_CTRL_auth_hash_sel_START (2)
#define SOC_SCE_REE_HICRYPTO_AEAD_CTRL_auth_hash_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bdq_wptr : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SCE_REE_HICRYPTO_BDQ_WPTR_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_BDQ_WPTR_bdq_wptr_START (0)
#define SOC_SCE_REE_HICRYPTO_BDQ_WPTR_bdq_wptr_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bdq_rptr : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SCE_REE_HICRYPTO_BDQ_RPTR_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_BDQ_RPTR_bdq_rptr_START (0)
#define SOC_SCE_REE_HICRYPTO_BDQ_RPTR_bdq_rptr_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bdq_rptr_pf : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SCE_REE_HICRYPTO_BDQ_RPTR_PF_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_BDQ_RPTR_PF_bdq_rptr_pf_START (0)
#define SOC_SCE_REE_HICRYPTO_BDQ_RPTR_PF_bdq_rptr_pf_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bdq_depth : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_SCE_REE_HICRYPTO_BDQ_DEPTH_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_BDQ_DEPTH_bdq_depth_START (0)
#define SOC_SCE_REE_HICRYPTO_BDQ_DEPTH_bdq_depth_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bdq_init_ptr_low : 32;
    } reg;
} SOC_SCE_REE_HICRYPTO_BDQ_INIT_PTR_LOW_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_BDQ_INIT_PTR_LOW_bdq_init_ptr_low_START (0)
#define SOC_SCE_REE_HICRYPTO_BDQ_INIT_PTR_LOW_bdq_init_ptr_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 8;
        unsigned int dscrp_pf_fifo_en : 4;
        unsigned int bdq_init_ptr_high : 4;
        unsigned int reserved_2 : 8;
    } reg;
} SOC_SCE_REE_HICRYPTO_DSCRP_PF_FIFO_CTRL_UNION;
#endif
#define SOC_SCE_REE_HICRYPTO_DSCRP_PF_FIFO_CTRL_dscrp_pf_fifo_en_START (16)
#define SOC_SCE_REE_HICRYPTO_DSCRP_PF_FIFO_CTRL_dscrp_pf_fifo_en_END (19)
#define SOC_SCE_REE_HICRYPTO_DSCRP_PF_FIFO_CTRL_bdq_init_ptr_high_START (20)
#define SOC_SCE_REE_HICRYPTO_DSCRP_PF_FIFO_CTRL_bdq_init_ptr_high_END (23)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
