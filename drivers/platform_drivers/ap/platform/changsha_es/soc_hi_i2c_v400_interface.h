#ifndef __SOC_HI_I2C_V400_INTERFACE_H__
#define __SOC_HI_I2C_V400_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HI_I2C_V400_FRAME_CTRL_ADDR(base) ((base) + (0x0000UL))
#define SOC_HI_I2C_V400_SLV_ADDR_ADDR(base) ((base) + (0x0004UL))
#define SOC_HI_I2C_V400_CMD_TXDATA_ADDR(base) ((base) + (0x0008UL))
#define SOC_HI_I2C_V400_RXDATA_ADDR(base) ((base) + (0x000CUL))
#define SOC_HI_I2C_V400_SS_SCL_HCNT_ADDR(base) ((base) + (0x0010UL))
#define SOC_HI_I2C_V400_SS_SCL_LCNT_ADDR(base) ((base) + (0x0014UL))
#define SOC_HI_I2C_V400_FS_SCL_HCNT_ADDR(base) ((base) + (0x0018UL))
#define SOC_HI_I2C_V400_FS_SCL_LCNT_ADDR(base) ((base) + (0x001CUL))
#define SOC_HI_I2C_V400_HS_SCL_HCNT_ADDR(base) ((base) + (0x0020UL))
#define SOC_HI_I2C_V400_HS_SCL_LCNT_ADDR(base) ((base) + (0x0024UL))
#define SOC_HI_I2C_V400_FIFO_CTRL_ADDR(base) ((base) + (0x0028UL))
#define SOC_HI_I2C_V400_FIFO_STATE_ADDR(base) ((base) + (0x002CUL))
#define SOC_HI_I2C_V400_SDA_HOLD_ADDR(base) ((base) + (0x0030UL))
#define SOC_HI_I2C_V400_DMA_CTRL_ADDR(base) ((base) + (0x0034UL))
#define SOC_HI_I2C_V400_FS_SPK_LEN_ADDR(base) ((base) + (0x0038UL))
#define SOC_HI_I2C_V400_HS_SPK_LEN_ADDR(base) ((base) + (0x003CUL))
#define SOC_HI_I2C_V400_INT_MSTAT_ADDR(base) ((base) + (0x0044UL))
#define SOC_HI_I2C_V400_INT_CLR_ADDR(base) ((base) + (0x0048UL))
#define SOC_HI_I2C_V400_INT_MASK_ADDR(base) ((base) + (0x004CUL))
#define SOC_HI_I2C_V400_TRANS_STATE_ADDR(base) ((base) + (0x0050UL))
#define SOC_HI_I2C_V400_TRANS_ERR_ADDR(base) ((base) + (0x0054UL))
#else
#define SOC_HI_I2C_V400_FRAME_CTRL_ADDR(base) ((base) + (0x0000))
#define SOC_HI_I2C_V400_SLV_ADDR_ADDR(base) ((base) + (0x0004))
#define SOC_HI_I2C_V400_CMD_TXDATA_ADDR(base) ((base) + (0x0008))
#define SOC_HI_I2C_V400_RXDATA_ADDR(base) ((base) + (0x000C))
#define SOC_HI_I2C_V400_SS_SCL_HCNT_ADDR(base) ((base) + (0x0010))
#define SOC_HI_I2C_V400_SS_SCL_LCNT_ADDR(base) ((base) + (0x0014))
#define SOC_HI_I2C_V400_FS_SCL_HCNT_ADDR(base) ((base) + (0x0018))
#define SOC_HI_I2C_V400_FS_SCL_LCNT_ADDR(base) ((base) + (0x001C))
#define SOC_HI_I2C_V400_HS_SCL_HCNT_ADDR(base) ((base) + (0x0020))
#define SOC_HI_I2C_V400_HS_SCL_LCNT_ADDR(base) ((base) + (0x0024))
#define SOC_HI_I2C_V400_FIFO_CTRL_ADDR(base) ((base) + (0x0028))
#define SOC_HI_I2C_V400_FIFO_STATE_ADDR(base) ((base) + (0x002C))
#define SOC_HI_I2C_V400_SDA_HOLD_ADDR(base) ((base) + (0x0030))
#define SOC_HI_I2C_V400_DMA_CTRL_ADDR(base) ((base) + (0x0034))
#define SOC_HI_I2C_V400_FS_SPK_LEN_ADDR(base) ((base) + (0x0038))
#define SOC_HI_I2C_V400_HS_SPK_LEN_ADDR(base) ((base) + (0x003C))
#define SOC_HI_I2C_V400_INT_MSTAT_ADDR(base) ((base) + (0x0044))
#define SOC_HI_I2C_V400_INT_CLR_ADDR(base) ((base) + (0x0048))
#define SOC_HI_I2C_V400_INT_MASK_ADDR(base) ((base) + (0x004C))
#define SOC_HI_I2C_V400_TRANS_STATE_ADDR(base) ((base) + (0x0050))
#define SOC_HI_I2C_V400_TRANS_ERR_ADDR(base) ((base) + (0x0054))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int speed_mode : 2;
        unsigned int slv_addr_10bit : 1;
        unsigned int restart_en : 1;
        unsigned int hs_mstcode_addr : 3;
        unsigned int reserved : 25;
    } reg;
} SOC_HI_I2C_V400_FRAME_CTRL_UNION;
#endif
#define SOC_HI_I2C_V400_FRAME_CTRL_speed_mode_START (0)
#define SOC_HI_I2C_V400_FRAME_CTRL_speed_mode_END (1)
#define SOC_HI_I2C_V400_FRAME_CTRL_slv_addr_10bit_START (2)
#define SOC_HI_I2C_V400_FRAME_CTRL_slv_addr_10bit_END (2)
#define SOC_HI_I2C_V400_FRAME_CTRL_restart_en_START (3)
#define SOC_HI_I2C_V400_FRAME_CTRL_restart_en_END (3)
#define SOC_HI_I2C_V400_FRAME_CTRL_hs_mstcode_addr_START (4)
#define SOC_HI_I2C_V400_FRAME_CTRL_hs_mstcode_addr_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int slv_addr : 10;
        unsigned int gc_sbyte_mode : 1;
        unsigned int gc_sbyte_en : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_HI_I2C_V400_SLV_ADDR_UNION;
#endif
#define SOC_HI_I2C_V400_SLV_ADDR_slv_addr_START (0)
#define SOC_HI_I2C_V400_SLV_ADDR_slv_addr_END (9)
#define SOC_HI_I2C_V400_SLV_ADDR_gc_sbyte_mode_START (10)
#define SOC_HI_I2C_V400_SLV_ADDR_gc_sbyte_mode_END (10)
#define SOC_HI_I2C_V400_SLV_ADDR_gc_sbyte_en_START (11)
#define SOC_HI_I2C_V400_SLV_ADDR_gc_sbyte_en_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_data : 8;
        unsigned int rnw : 1;
        unsigned int p_en : 1;
        unsigned int sr_en : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_HI_I2C_V400_CMD_TXDATA_UNION;
#endif
#define SOC_HI_I2C_V400_CMD_TXDATA_tx_data_START (0)
#define SOC_HI_I2C_V400_CMD_TXDATA_tx_data_END (7)
#define SOC_HI_I2C_V400_CMD_TXDATA_rnw_START (8)
#define SOC_HI_I2C_V400_CMD_TXDATA_rnw_END (8)
#define SOC_HI_I2C_V400_CMD_TXDATA_p_en_START (9)
#define SOC_HI_I2C_V400_CMD_TXDATA_p_en_END (9)
#define SOC_HI_I2C_V400_CMD_TXDATA_sr_en_START (10)
#define SOC_HI_I2C_V400_CMD_TXDATA_sr_en_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_data : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HI_I2C_V400_RXDATA_UNION;
#endif
#define SOC_HI_I2C_V400_RXDATA_rx_data_START (0)
#define SOC_HI_I2C_V400_RXDATA_rx_data_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ss_scl_hcnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HI_I2C_V400_SS_SCL_HCNT_UNION;
#endif
#define SOC_HI_I2C_V400_SS_SCL_HCNT_ss_scl_hcnt_START (0)
#define SOC_HI_I2C_V400_SS_SCL_HCNT_ss_scl_hcnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ss_scl_lcnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HI_I2C_V400_SS_SCL_LCNT_UNION;
#endif
#define SOC_HI_I2C_V400_SS_SCL_LCNT_ss_scl_lcnt_START (0)
#define SOC_HI_I2C_V400_SS_SCL_LCNT_ss_scl_lcnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fs_scl_hcnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HI_I2C_V400_FS_SCL_HCNT_UNION;
#endif
#define SOC_HI_I2C_V400_FS_SCL_HCNT_fs_scl_hcnt_START (0)
#define SOC_HI_I2C_V400_FS_SCL_HCNT_fs_scl_hcnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fs_scl_lcnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HI_I2C_V400_FS_SCL_LCNT_UNION;
#endif
#define SOC_HI_I2C_V400_FS_SCL_LCNT_fs_scl_lcnt_START (0)
#define SOC_HI_I2C_V400_FS_SCL_LCNT_fs_scl_lcnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hs_scl_hcnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HI_I2C_V400_HS_SCL_HCNT_UNION;
#endif
#define SOC_HI_I2C_V400_HS_SCL_HCNT_hs_scl_hcnt_START (0)
#define SOC_HI_I2C_V400_HS_SCL_HCNT_hs_scl_hcnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hs_scl_lcnt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HI_I2C_V400_HS_SCL_LCNT_UNION;
#endif
#define SOC_HI_I2C_V400_HS_SCL_LCNT_hs_scl_lcnt_START (0)
#define SOC_HI_I2C_V400_HS_SCL_LCNT_hs_scl_lcnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_fifo_clr : 1;
        unsigned int tx_fifo_clr : 1;
        unsigned int rx_fifo_af_thre : 6;
        unsigned int tx_fifo_ae_thre : 6;
        unsigned int reserved : 18;
    } reg;
} SOC_HI_I2C_V400_FIFO_CTRL_UNION;
#endif
#define SOC_HI_I2C_V400_FIFO_CTRL_rx_fifo_clr_START (0)
#define SOC_HI_I2C_V400_FIFO_CTRL_rx_fifo_clr_END (0)
#define SOC_HI_I2C_V400_FIFO_CTRL_tx_fifo_clr_START (1)
#define SOC_HI_I2C_V400_FIFO_CTRL_tx_fifo_clr_END (1)
#define SOC_HI_I2C_V400_FIFO_CTRL_rx_fifo_af_thre_START (2)
#define SOC_HI_I2C_V400_FIFO_CTRL_rx_fifo_af_thre_END (7)
#define SOC_HI_I2C_V400_FIFO_CTRL_tx_fifo_ae_thre_START (8)
#define SOC_HI_I2C_V400_FIFO_CTRL_tx_fifo_ae_thre_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fifo_state : 32;
    } reg;
} SOC_HI_I2C_V400_FIFO_STATE_UNION;
#endif
#define SOC_HI_I2C_V400_FIFO_STATE_fifo_state_START (0)
#define SOC_HI_I2C_V400_FIFO_STATE_fifo_state_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sda_hold_tx : 16;
        unsigned int sda_hold_rx : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_HI_I2C_V400_SDA_HOLD_UNION;
#endif
#define SOC_HI_I2C_V400_SDA_HOLD_sda_hold_tx_START (0)
#define SOC_HI_I2C_V400_SDA_HOLD_sda_hold_tx_END (15)
#define SOC_HI_I2C_V400_SDA_HOLD_sda_hold_rx_START (16)
#define SOC_HI_I2C_V400_SDA_HOLD_sda_hold_rx_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HI_I2C_V400_DMA_CTRL_UNION;
#endif
#define SOC_HI_I2C_V400_DMA_CTRL_dma_en_START (0)
#define SOC_HI_I2C_V400_DMA_CTRL_dma_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fs_spk_len : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HI_I2C_V400_FS_SPK_LEN_UNION;
#endif
#define SOC_HI_I2C_V400_FS_SPK_LEN_fs_spk_len_START (0)
#define SOC_HI_I2C_V400_FS_SPK_LEN_fs_spk_len_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hs_spk_len : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_HI_I2C_V400_HS_SPK_LEN_UNION;
#endif
#define SOC_HI_I2C_V400_HS_SPK_LEN_hs_spk_len_START (0)
#define SOC_HI_I2C_V400_HS_SPK_LEN_hs_spk_len_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trans_cmplt_int_mstat : 1;
        unsigned int trans_err_int_mstat : 1;
        unsigned int fifo_err_int_mstat : 1;
        unsigned int rx_afull_int_mstat : 1;
        unsigned int tx_aempty_int_mstat : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_HI_I2C_V400_INT_MSTAT_UNION;
#endif
#define SOC_HI_I2C_V400_INT_MSTAT_trans_cmplt_int_mstat_START (0)
#define SOC_HI_I2C_V400_INT_MSTAT_trans_cmplt_int_mstat_END (0)
#define SOC_HI_I2C_V400_INT_MSTAT_trans_err_int_mstat_START (1)
#define SOC_HI_I2C_V400_INT_MSTAT_trans_err_int_mstat_END (1)
#define SOC_HI_I2C_V400_INT_MSTAT_fifo_err_int_mstat_START (2)
#define SOC_HI_I2C_V400_INT_MSTAT_fifo_err_int_mstat_END (2)
#define SOC_HI_I2C_V400_INT_MSTAT_rx_afull_int_mstat_START (3)
#define SOC_HI_I2C_V400_INT_MSTAT_rx_afull_int_mstat_END (3)
#define SOC_HI_I2C_V400_INT_MSTAT_tx_aempty_int_mstat_START (4)
#define SOC_HI_I2C_V400_INT_MSTAT_tx_aempty_int_mstat_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trans_cmplt_int : 1;
        unsigned int trans_err_int : 1;
        unsigned int fifo_err_int : 1;
        unsigned int rx_afull_int : 1;
        unsigned int tx_aempty_int : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_HI_I2C_V400_INT_CLR_UNION;
#endif
#define SOC_HI_I2C_V400_INT_CLR_trans_cmplt_int_START (0)
#define SOC_HI_I2C_V400_INT_CLR_trans_cmplt_int_END (0)
#define SOC_HI_I2C_V400_INT_CLR_trans_err_int_START (1)
#define SOC_HI_I2C_V400_INT_CLR_trans_err_int_END (1)
#define SOC_HI_I2C_V400_INT_CLR_fifo_err_int_START (2)
#define SOC_HI_I2C_V400_INT_CLR_fifo_err_int_END (2)
#define SOC_HI_I2C_V400_INT_CLR_rx_afull_int_START (3)
#define SOC_HI_I2C_V400_INT_CLR_rx_afull_int_END (3)
#define SOC_HI_I2C_V400_INT_CLR_tx_aempty_int_START (4)
#define SOC_HI_I2C_V400_INT_CLR_tx_aempty_int_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trans_cmplt_int_mask : 1;
        unsigned int trans_err_int_mask : 1;
        unsigned int fifo_err_int_mask : 1;
        unsigned int rx_afull_int_mask : 1;
        unsigned int tx_aempty_int_mask : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_HI_I2C_V400_INT_MASK_UNION;
#endif
#define SOC_HI_I2C_V400_INT_MASK_trans_cmplt_int_mask_START (0)
#define SOC_HI_I2C_V400_INT_MASK_trans_cmplt_int_mask_END (0)
#define SOC_HI_I2C_V400_INT_MASK_trans_err_int_mask_START (1)
#define SOC_HI_I2C_V400_INT_MASK_trans_err_int_mask_END (1)
#define SOC_HI_I2C_V400_INT_MASK_fifo_err_int_mask_START (2)
#define SOC_HI_I2C_V400_INT_MASK_fifo_err_int_mask_END (2)
#define SOC_HI_I2C_V400_INT_MASK_rx_afull_int_mask_START (3)
#define SOC_HI_I2C_V400_INT_MASK_rx_afull_int_mask_END (3)
#define SOC_HI_I2C_V400_INT_MASK_tx_aempty_int_mask_START (4)
#define SOC_HI_I2C_V400_INT_MASK_tx_aempty_int_mask_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mtc_st_curr : 5;
        unsigned int sda_level : 1;
        unsigned int scl_level : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_HI_I2C_V400_TRANS_STATE_UNION;
#endif
#define SOC_HI_I2C_V400_TRANS_STATE_mtc_st_curr_START (0)
#define SOC_HI_I2C_V400_TRANS_STATE_mtc_st_curr_END (4)
#define SOC_HI_I2C_V400_TRANS_STATE_sda_level_START (5)
#define SOC_HI_I2C_V400_TRANS_STATE_sda_level_END (5)
#define SOC_HI_I2C_V400_TRANS_STATE_scl_level_START (6)
#define SOC_HI_I2C_V400_TRANS_STATE_scl_level_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trans_err_state : 32;
    } reg;
} SOC_HI_I2C_V400_TRANS_ERR_UNION;
#endif
#define SOC_HI_I2C_V400_TRANS_ERR_trans_err_state_START (0)
#define SOC_HI_I2C_V400_TRANS_ERR_trans_err_state_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
