#ifndef __SOC_HI_I3C_V200_INTERFACE_H__
#define __SOC_HI_I3C_V200_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HI_I3C_V200_FRAME_CTRL1_ADDR(base) ((base) + (0x0000UL))
#define SOC_HI_I3C_V200_TRANSFER_CMD1_ADDR(base) ((base) + (0x0004UL))
#define SOC_HI_I3C_V200_TRANSFER_CMD2_ADDR(base) ((base) + (0x0008UL))
#define SOC_HI_I3C_V200_TRANSFER_CMD3_ADDR(base) ((base) + (0x000CUL))
#define SOC_HI_I3C_V200_TRANSFER_CMD4_ADDR(base) ((base) + (0x0010UL))
#define SOC_HI_I3C_V200_TX_DATA_PORT_ADDR(base) ((base) + (0x0014UL))
#define SOC_HI_I3C_V200_RX_DATA_PORT_ADDR(base) ((base) + (0x0018UL))
#define SOC_HI_I3C_V200_FIFO_CTRL_ADDR(base) ((base) + (0x001CUL))
#define SOC_HI_I3C_V200_FIFO_STATE_ADDR(base) ((base) + (0x0020UL))
#define SOC_HI_I3C_V200_DEVICE_TABLE_1_ADDR(base) ((base) + (0x0024UL))
#define SOC_HI_I3C_V200_DEVICE_TABLE_2_ADDR(base) ((base) + (0x0028UL))
#define SOC_HI_I3C_V200_DEVICE_TABLE_3_ADDR(base) ((base) + (0x002CUL))
#define SOC_HI_I3C_V200_DEVICE_TABLE_4_ADDR(base) ((base) + (0x0030UL))
#define SOC_HI_I3C_V200_DEVICE_TABLE_5_ADDR(base) ((base) + (0x0034UL))
#define SOC_HI_I3C_V200_DEVICE_TABLE_6_ADDR(base) ((base) + (0x0038UL))
#define SOC_HI_I3C_V200_DEVICE_TABLE_7_ADDR(base) ((base) + (0x003CUL))
#define SOC_HI_I3C_V200_DEVICE_TABLE_8_ADDR(base) ((base) + (0x0040UL))
#define SOC_HI_I3C_V200_DEVICE_TABLE_9_ADDR(base) ((base) + (0x0044UL))
#define SOC_HI_I3C_V200_DEVICE_TABLE_10_ADDR(base) ((base) + (0x0048UL))
#define SOC_HI_I3C_V200_DEVICE_TABLE_11_ADDR(base) ((base) + (0x004CUL))
#define SOC_HI_I3C_V200_RESP_STATE_ADDR(base) ((base) + (0x005CUL))
#define SOC_HI_I3C_V200_TRANS_STATE_ADDR(base) ((base) + (0x0060UL))
#define SOC_HI_I3C_V200_INT_MSTAT_ADDR(base) ((base) + (0x0068UL))
#define SOC_HI_I3C_V200_INT_STAT_ADDR(base) ((base) + (0x006CUL))
#define SOC_HI_I3C_V200_INT_MASK_ADDR(base) ((base) + (0x0070UL))
#define SOC_HI_I3C_V200_IBI_DTATA_ADDR(base) ((base) + (0x0074UL))
#define SOC_HI_I3C_V200_COUNTER_REG1_ADDR(base) ((base) + (0x0088UL))
#define SOC_HI_I3C_V200_COUNTER_REG2_ADDR(base) ((base) + (0x008CUL))
#define SOC_HI_I3C_V200_COUNTER_REG3_ADDR(base) ((base) + (0x0090UL))
#define SOC_HI_I3C_V200_COUNTER_REG4_ADDR(base) ((base) + (0x0094UL))
#define SOC_HI_I3C_V200_COUNTER_REG5_ADDR(base) ((base) + (0x0098UL))
#define SOC_HI_I3C_V200_COUNTER_REG6_ADDR(base) ((base) + (0x009CUL))
#define SOC_HI_I3C_V200_COUNTER_REG7_ADDR(base) ((base) + (0x0100UL))
#else
#define SOC_HI_I3C_V200_FRAME_CTRL1_ADDR(base) ((base) + (0x0000))
#define SOC_HI_I3C_V200_TRANSFER_CMD1_ADDR(base) ((base) + (0x0004))
#define SOC_HI_I3C_V200_TRANSFER_CMD2_ADDR(base) ((base) + (0x0008))
#define SOC_HI_I3C_V200_TRANSFER_CMD3_ADDR(base) ((base) + (0x000C))
#define SOC_HI_I3C_V200_TRANSFER_CMD4_ADDR(base) ((base) + (0x0010))
#define SOC_HI_I3C_V200_TX_DATA_PORT_ADDR(base) ((base) + (0x0014))
#define SOC_HI_I3C_V200_RX_DATA_PORT_ADDR(base) ((base) + (0x0018))
#define SOC_HI_I3C_V200_FIFO_CTRL_ADDR(base) ((base) + (0x001C))
#define SOC_HI_I3C_V200_FIFO_STATE_ADDR(base) ((base) + (0x0020))
#define SOC_HI_I3C_V200_DEVICE_TABLE_1_ADDR(base) ((base) + (0x0024))
#define SOC_HI_I3C_V200_DEVICE_TABLE_2_ADDR(base) ((base) + (0x0028))
#define SOC_HI_I3C_V200_DEVICE_TABLE_3_ADDR(base) ((base) + (0x002C))
#define SOC_HI_I3C_V200_DEVICE_TABLE_4_ADDR(base) ((base) + (0x0030))
#define SOC_HI_I3C_V200_DEVICE_TABLE_5_ADDR(base) ((base) + (0x0034))
#define SOC_HI_I3C_V200_DEVICE_TABLE_6_ADDR(base) ((base) + (0x0038))
#define SOC_HI_I3C_V200_DEVICE_TABLE_7_ADDR(base) ((base) + (0x003C))
#define SOC_HI_I3C_V200_DEVICE_TABLE_8_ADDR(base) ((base) + (0x0040))
#define SOC_HI_I3C_V200_DEVICE_TABLE_9_ADDR(base) ((base) + (0x0044))
#define SOC_HI_I3C_V200_DEVICE_TABLE_10_ADDR(base) ((base) + (0x0048))
#define SOC_HI_I3C_V200_DEVICE_TABLE_11_ADDR(base) ((base) + (0x004C))
#define SOC_HI_I3C_V200_RESP_STATE_ADDR(base) ((base) + (0x005C))
#define SOC_HI_I3C_V200_TRANS_STATE_ADDR(base) ((base) + (0x0060))
#define SOC_HI_I3C_V200_INT_MSTAT_ADDR(base) ((base) + (0x0068))
#define SOC_HI_I3C_V200_INT_STAT_ADDR(base) ((base) + (0x006C))
#define SOC_HI_I3C_V200_INT_MASK_ADDR(base) ((base) + (0x0070))
#define SOC_HI_I3C_V200_IBI_DTATA_ADDR(base) ((base) + (0x0074))
#define SOC_HI_I3C_V200_COUNTER_REG1_ADDR(base) ((base) + (0x0088))
#define SOC_HI_I3C_V200_COUNTER_REG2_ADDR(base) ((base) + (0x008C))
#define SOC_HI_I3C_V200_COUNTER_REG3_ADDR(base) ((base) + (0x0090))
#define SOC_HI_I3C_V200_COUNTER_REG4_ADDR(base) ((base) + (0x0094))
#define SOC_HI_I3C_V200_COUNTER_REG5_ADDR(base) ((base) + (0x0098))
#define SOC_HI_I3C_V200_COUNTER_REG6_ADDR(base) ((base) + (0x009C))
#define SOC_HI_I3C_V200_COUNTER_REG7_ADDR(base) ((base) + (0x0100))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sw_init : 1;
        unsigned int reserved_0 : 1;
        unsigned int iba_include : 1;
        unsigned int i2c_slave_present : 1;
        unsigned int hot_join_ctrl : 1;
        unsigned int ibi_ctrl : 1;
        unsigned int reserved_1 : 26;
    } reg;
} SOC_HI_I3C_V200_FRAME_CTRL1_UNION;
#endif
#define SOC_HI_I3C_V200_FRAME_CTRL1_sw_init_START (0)
#define SOC_HI_I3C_V200_FRAME_CTRL1_sw_init_END (0)
#define SOC_HI_I3C_V200_FRAME_CTRL1_iba_include_START (2)
#define SOC_HI_I3C_V200_FRAME_CTRL1_iba_include_END (2)
#define SOC_HI_I3C_V200_FRAME_CTRL1_i2c_slave_present_START (3)
#define SOC_HI_I3C_V200_FRAME_CTRL1_i2c_slave_present_END (3)
#define SOC_HI_I3C_V200_FRAME_CTRL1_hot_join_ctrl_START (4)
#define SOC_HI_I3C_V200_FRAME_CTRL1_hot_join_ctrl_END (4)
#define SOC_HI_I3C_V200_FRAME_CTRL1_ibi_ctrl_START (5)
#define SOC_HI_I3C_V200_FRAME_CTRL1_ibi_ctrl_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_sel_0 : 2;
        unsigned int reserved_0: 1;
        unsigned int tid : 4;
        unsigned int cmd : 8;
        unsigned int cp : 1;
        unsigned int dev_index : 4;
        unsigned int reserved_1: 5;
        unsigned int sdap : 1;
        unsigned int rnw : 1;
        unsigned int toc : 1;
        unsigned int reserved_2: 4;
    } reg;
} SOC_HI_I3C_V200_TRANSFER_CMD1_UNION;
#endif
#define SOC_HI_I3C_V200_TRANSFER_CMD1_cmd_sel_0_START (0)
#define SOC_HI_I3C_V200_TRANSFER_CMD1_cmd_sel_0_END (1)
#define SOC_HI_I3C_V200_TRANSFER_CMD1_tid_START (3)
#define SOC_HI_I3C_V200_TRANSFER_CMD1_tid_END (6)
#define SOC_HI_I3C_V200_TRANSFER_CMD1_cmd_START (7)
#define SOC_HI_I3C_V200_TRANSFER_CMD1_cmd_END (14)
#define SOC_HI_I3C_V200_TRANSFER_CMD1_cp_START (15)
#define SOC_HI_I3C_V200_TRANSFER_CMD1_cp_END (15)
#define SOC_HI_I3C_V200_TRANSFER_CMD1_dev_index_START (16)
#define SOC_HI_I3C_V200_TRANSFER_CMD1_dev_index_END (19)
#define SOC_HI_I3C_V200_TRANSFER_CMD1_sdap_START (25)
#define SOC_HI_I3C_V200_TRANSFER_CMD1_sdap_END (25)
#define SOC_HI_I3C_V200_TRANSFER_CMD1_rnw_START (26)
#define SOC_HI_I3C_V200_TRANSFER_CMD1_rnw_END (26)
#define SOC_HI_I3C_V200_TRANSFER_CMD1_toc_START (27)
#define SOC_HI_I3C_V200_TRANSFER_CMD1_toc_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_sel_1 : 2;
        unsigned int reserved : 9;
        unsigned int dma_en : 1;
        unsigned int data_length : 20;
    } reg;
} SOC_HI_I3C_V200_TRANSFER_CMD2_UNION;
#endif
#define SOC_HI_I3C_V200_TRANSFER_CMD2_cmd_sel_1_START (0)
#define SOC_HI_I3C_V200_TRANSFER_CMD2_cmd_sel_1_END (1)
#define SOC_HI_I3C_V200_TRANSFER_CMD2_dma_en_START (11)
#define SOC_HI_I3C_V200_TRANSFER_CMD2_dma_en_END (11)
#define SOC_HI_I3C_V200_TRANSFER_CMD2_data_length_START (12)
#define SOC_HI_I3C_V200_TRANSFER_CMD2_data_length_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_sel_2 : 2;
        unsigned int byte_strb : 3;
        unsigned int reserved : 3;
        unsigned int data_byte1 : 8;
        unsigned int data_byte2 : 8;
        unsigned int data_byte3 : 8;
    } reg;
} SOC_HI_I3C_V200_TRANSFER_CMD3_UNION;
#endif
#define SOC_HI_I3C_V200_TRANSFER_CMD3_cmd_sel_2_START (0)
#define SOC_HI_I3C_V200_TRANSFER_CMD3_cmd_sel_2_END (1)
#define SOC_HI_I3C_V200_TRANSFER_CMD3_byte_strb_START (2)
#define SOC_HI_I3C_V200_TRANSFER_CMD3_byte_strb_END (4)
#define SOC_HI_I3C_V200_TRANSFER_CMD3_data_byte1_START (8)
#define SOC_HI_I3C_V200_TRANSFER_CMD3_data_byte1_END (15)
#define SOC_HI_I3C_V200_TRANSFER_CMD3_data_byte2_START (16)
#define SOC_HI_I3C_V200_TRANSFER_CMD3_data_byte2_END (23)
#define SOC_HI_I3C_V200_TRANSFER_CMD3_data_byte3_START (24)
#define SOC_HI_I3C_V200_TRANSFER_CMD3_data_byte3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_sel_3 : 2;
        unsigned int reserved_0 : 1;
        unsigned int aac_tid : 4;
        unsigned int acc_cmd : 8;
        unsigned int reserved_1 : 1;
        unsigned int acc_dev_index : 4;
        unsigned int acc_dev_count : 4;
        unsigned int reserved_2 : 3;
        unsigned int aac_toc : 1;
        unsigned int reserved_3 : 4;
    } reg;
} SOC_HI_I3C_V200_TRANSFER_CMD4_UNION;
#endif
#define SOC_HI_I3C_V200_TRANSFER_CMD4_cmd_sel_3_START (0)
#define SOC_HI_I3C_V200_TRANSFER_CMD4_cmd_sel_3_END (1)
#define SOC_HI_I3C_V200_TRANSFER_CMD4_aac_tid_START (3)
#define SOC_HI_I3C_V200_TRANSFER_CMD4_aac_tid_END (6)
#define SOC_HI_I3C_V200_TRANSFER_CMD4_acc_cmd_START (7)
#define SOC_HI_I3C_V200_TRANSFER_CMD4_acc_cmd_END (14)
#define SOC_HI_I3C_V200_TRANSFER_CMD4_acc_dev_index_START (16)
#define SOC_HI_I3C_V200_TRANSFER_CMD4_acc_dev_index_END (19)
#define SOC_HI_I3C_V200_TRANSFER_CMD4_acc_dev_count_START (20)
#define SOC_HI_I3C_V200_TRANSFER_CMD4_acc_dev_count_END (23)
#define SOC_HI_I3C_V200_TRANSFER_CMD4_aac_toc_START (27)
#define SOC_HI_I3C_V200_TRANSFER_CMD4_aac_toc_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tx_data : 32;
    } reg;
} SOC_HI_I3C_V200_TX_DATA_PORT_UNION;
#endif
#define SOC_HI_I3C_V200_TX_DATA_PORT_tx_data_START (0)
#define SOC_HI_I3C_V200_TX_DATA_PORT_tx_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rx_data : 32;
    } reg;
} SOC_HI_I3C_V200_RX_DATA_PORT_UNION;
#endif
#define SOC_HI_I3C_V200_RX_DATA_PORT_rx_data_START (0)
#define SOC_HI_I3C_V200_RX_DATA_PORT_rx_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 11;
        unsigned int cmd_fifo_clr : 1;
        unsigned int rx_fifo_clr : 1;
        unsigned int tx_fifo_clr : 1;
        unsigned int cmd_fifo_thre : 2;
        unsigned int reserved_1 : 4;
        unsigned int rx_fifo_af_thre : 4;
        unsigned int tx_fifo_ae_thre : 4;
        unsigned int reserved_2 : 4;
    } reg;
} SOC_HI_I3C_V200_FIFO_CTRL_UNION;
#endif
#define SOC_HI_I3C_V200_FIFO_CTRL_cmd_fifo_clr_START (11)
#define SOC_HI_I3C_V200_FIFO_CTRL_cmd_fifo_clr_END (11)
#define SOC_HI_I3C_V200_FIFO_CTRL_rx_fifo_clr_START (12)
#define SOC_HI_I3C_V200_FIFO_CTRL_rx_fifo_clr_END (12)
#define SOC_HI_I3C_V200_FIFO_CTRL_tx_fifo_clr_START (13)
#define SOC_HI_I3C_V200_FIFO_CTRL_tx_fifo_clr_END (13)
#define SOC_HI_I3C_V200_FIFO_CTRL_cmd_fifo_thre_START (14)
#define SOC_HI_I3C_V200_FIFO_CTRL_cmd_fifo_thre_END (15)
#define SOC_HI_I3C_V200_FIFO_CTRL_rx_fifo_af_thre_START (20)
#define SOC_HI_I3C_V200_FIFO_CTRL_rx_fifo_af_thre_END (23)
#define SOC_HI_I3C_V200_FIFO_CTRL_tx_fifo_ae_thre_START (24)
#define SOC_HI_I3C_V200_FIFO_CTRL_tx_fifo_ae_thre_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fifo_state : 32;
    } reg;
} SOC_HI_I3C_V200_FIFO_STATE_UNION;
#endif
#define SOC_HI_I3C_V200_FIFO_STATE_fifo_state_START (0)
#define SOC_HI_I3C_V200_FIFO_STATE_fifo_state_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dev_static_addr_1 : 7;
        unsigned int reserved_0 : 9;
        unsigned int dev_dynamic_addr_1 : 8;
        unsigned int reserved_1 : 5;
        unsigned int dev_nack_retry_cnt_1 : 2;
        unsigned int i2c_device_1 : 1;
    } reg;
} SOC_HI_I3C_V200_DEVICE_TABLE_1_UNION;
#endif
#define SOC_HI_I3C_V200_DEVICE_TABLE_1_dev_static_addr_1_START (0)
#define SOC_HI_I3C_V200_DEVICE_TABLE_1_dev_static_addr_1_END (6)
#define SOC_HI_I3C_V200_DEVICE_TABLE_1_dev_dynamic_addr_1_START (16)
#define SOC_HI_I3C_V200_DEVICE_TABLE_1_dev_dynamic_addr_1_END (23)
#define SOC_HI_I3C_V200_DEVICE_TABLE_1_dev_nack_retry_cnt_1_START (29)
#define SOC_HI_I3C_V200_DEVICE_TABLE_1_dev_nack_retry_cnt_1_END (30)
#define SOC_HI_I3C_V200_DEVICE_TABLE_1_i2c_device_1_START (31)
#define SOC_HI_I3C_V200_DEVICE_TABLE_1_i2c_device_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dev_static_addr_2 : 7;
        unsigned int reserved_0 : 9;
        unsigned int dev_dynamic_addr_2 : 8;
        unsigned int reserved_1 : 5;
        unsigned int dev_nack_retry_cnt_2 : 2;
        unsigned int i2c_device_2 : 1;
    } reg;
} SOC_HI_I3C_V200_DEVICE_TABLE_2_UNION;
#endif
#define SOC_HI_I3C_V200_DEVICE_TABLE_2_dev_static_addr_2_START (0)
#define SOC_HI_I3C_V200_DEVICE_TABLE_2_dev_static_addr_2_END (6)
#define SOC_HI_I3C_V200_DEVICE_TABLE_2_dev_dynamic_addr_2_START (16)
#define SOC_HI_I3C_V200_DEVICE_TABLE_2_dev_dynamic_addr_2_END (23)
#define SOC_HI_I3C_V200_DEVICE_TABLE_2_dev_nack_retry_cnt_2_START (29)
#define SOC_HI_I3C_V200_DEVICE_TABLE_2_dev_nack_retry_cnt_2_END (30)
#define SOC_HI_I3C_V200_DEVICE_TABLE_2_i2c_device_2_START (31)
#define SOC_HI_I3C_V200_DEVICE_TABLE_2_i2c_device_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dev_static_addr_3 : 7;
        unsigned int reserved_0 : 9;
        unsigned int dev_dynamic_addr_3 : 8;
        unsigned int reserved_1 : 5;
        unsigned int dev_nack_retry_cnt_3 : 2;
        unsigned int i2c_device_3 : 1;
    } reg;
} SOC_HI_I3C_V200_DEVICE_TABLE_3_UNION;
#endif
#define SOC_HI_I3C_V200_DEVICE_TABLE_3_dev_static_addr_3_START (0)
#define SOC_HI_I3C_V200_DEVICE_TABLE_3_dev_static_addr_3_END (6)
#define SOC_HI_I3C_V200_DEVICE_TABLE_3_dev_dynamic_addr_3_START (16)
#define SOC_HI_I3C_V200_DEVICE_TABLE_3_dev_dynamic_addr_3_END (23)
#define SOC_HI_I3C_V200_DEVICE_TABLE_3_dev_nack_retry_cnt_3_START (29)
#define SOC_HI_I3C_V200_DEVICE_TABLE_3_dev_nack_retry_cnt_3_END (30)
#define SOC_HI_I3C_V200_DEVICE_TABLE_3_i2c_device_3_START (31)
#define SOC_HI_I3C_V200_DEVICE_TABLE_3_i2c_device_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dev_static_addr_4 : 7;
        unsigned int reserved_0 : 9;
        unsigned int dev_dynamic_addr_4 : 8;
        unsigned int reserved_1 : 5;
        unsigned int dev_nack_retry_cnt_4 : 2;
        unsigned int i2c_device_4 : 1;
    } reg;
} SOC_HI_I3C_V200_DEVICE_TABLE_4_UNION;
#endif
#define SOC_HI_I3C_V200_DEVICE_TABLE_4_dev_static_addr_4_START (0)
#define SOC_HI_I3C_V200_DEVICE_TABLE_4_dev_static_addr_4_END (6)
#define SOC_HI_I3C_V200_DEVICE_TABLE_4_dev_dynamic_addr_4_START (16)
#define SOC_HI_I3C_V200_DEVICE_TABLE_4_dev_dynamic_addr_4_END (23)
#define SOC_HI_I3C_V200_DEVICE_TABLE_4_dev_nack_retry_cnt_4_START (29)
#define SOC_HI_I3C_V200_DEVICE_TABLE_4_dev_nack_retry_cnt_4_END (30)
#define SOC_HI_I3C_V200_DEVICE_TABLE_4_i2c_device_4_START (31)
#define SOC_HI_I3C_V200_DEVICE_TABLE_4_i2c_device_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dev_static_addr_5 : 7;
        unsigned int reserved_0 : 9;
        unsigned int dev_dynamic_addr_5 : 8;
        unsigned int reserved_1 : 5;
        unsigned int dev_nack_retry_cnt_5 : 2;
        unsigned int i2c_device_5 : 1;
    } reg;
} SOC_HI_I3C_V200_DEVICE_TABLE_5_UNION;
#endif
#define SOC_HI_I3C_V200_DEVICE_TABLE_5_dev_static_addr_5_START (0)
#define SOC_HI_I3C_V200_DEVICE_TABLE_5_dev_static_addr_5_END (6)
#define SOC_HI_I3C_V200_DEVICE_TABLE_5_dev_dynamic_addr_5_START (16)
#define SOC_HI_I3C_V200_DEVICE_TABLE_5_dev_dynamic_addr_5_END (23)
#define SOC_HI_I3C_V200_DEVICE_TABLE_5_dev_nack_retry_cnt_5_START (29)
#define SOC_HI_I3C_V200_DEVICE_TABLE_5_dev_nack_retry_cnt_5_END (30)
#define SOC_HI_I3C_V200_DEVICE_TABLE_5_i2c_device_5_START (31)
#define SOC_HI_I3C_V200_DEVICE_TABLE_5_i2c_device_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dev_static_addr_6 : 7;
        unsigned int reserved_0 : 9;
        unsigned int dev_dynamic_addr_6 : 8;
        unsigned int reserved_1 : 5;
        unsigned int dev_nack_retry_cnt_6 : 2;
        unsigned int i2c_device_6 : 1;
    } reg;
} SOC_HI_I3C_V200_DEVICE_TABLE_6_UNION;
#endif
#define SOC_HI_I3C_V200_DEVICE_TABLE_6_dev_static_addr_6_START (0)
#define SOC_HI_I3C_V200_DEVICE_TABLE_6_dev_static_addr_6_END (6)
#define SOC_HI_I3C_V200_DEVICE_TABLE_6_dev_dynamic_addr_6_START (16)
#define SOC_HI_I3C_V200_DEVICE_TABLE_6_dev_dynamic_addr_6_END (23)
#define SOC_HI_I3C_V200_DEVICE_TABLE_6_dev_nack_retry_cnt_6_START (29)
#define SOC_HI_I3C_V200_DEVICE_TABLE_6_dev_nack_retry_cnt_6_END (30)
#define SOC_HI_I3C_V200_DEVICE_TABLE_6_i2c_device_6_START (31)
#define SOC_HI_I3C_V200_DEVICE_TABLE_6_i2c_device_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dev_static_addr_7 : 7;
        unsigned int reserved_0 : 9;
        unsigned int dev_dynamic_addr_7 : 8;
        unsigned int reserved_1 : 5;
        unsigned int dev_nack_retry_cnt_7 : 2;
        unsigned int i2c_device_7 : 1;
    } reg;
} SOC_HI_I3C_V200_DEVICE_TABLE_7_UNION;
#endif
#define SOC_HI_I3C_V200_DEVICE_TABLE_7_dev_static_addr_7_START (0)
#define SOC_HI_I3C_V200_DEVICE_TABLE_7_dev_static_addr_7_END (6)
#define SOC_HI_I3C_V200_DEVICE_TABLE_7_dev_dynamic_addr_7_START (16)
#define SOC_HI_I3C_V200_DEVICE_TABLE_7_dev_dynamic_addr_7_END (23)
#define SOC_HI_I3C_V200_DEVICE_TABLE_7_dev_nack_retry_cnt_7_START (29)
#define SOC_HI_I3C_V200_DEVICE_TABLE_7_dev_nack_retry_cnt_7_END (30)
#define SOC_HI_I3C_V200_DEVICE_TABLE_7_i2c_device_7_START (31)
#define SOC_HI_I3C_V200_DEVICE_TABLE_7_i2c_device_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dev_static_addr_8 : 7;
        unsigned int reserved_0 : 9;
        unsigned int dev_dynamic_addr_8 : 8;
        unsigned int reserved_1 : 5;
        unsigned int dev_nack_retry_cnt_8 : 2;
        unsigned int i2c_device_8 : 1;
    } reg;
} SOC_HI_I3C_V200_DEVICE_TABLE_8_UNION;
#endif
#define SOC_HI_I3C_V200_DEVICE_TABLE_8_dev_static_addr_8_START (0)
#define SOC_HI_I3C_V200_DEVICE_TABLE_8_dev_static_addr_8_END (6)
#define SOC_HI_I3C_V200_DEVICE_TABLE_8_dev_dynamic_addr_8_START (16)
#define SOC_HI_I3C_V200_DEVICE_TABLE_8_dev_dynamic_addr_8_END (23)
#define SOC_HI_I3C_V200_DEVICE_TABLE_8_dev_nack_retry_cnt_8_START (29)
#define SOC_HI_I3C_V200_DEVICE_TABLE_8_dev_nack_retry_cnt_8_END (30)
#define SOC_HI_I3C_V200_DEVICE_TABLE_8_i2c_device_8_START (31)
#define SOC_HI_I3C_V200_DEVICE_TABLE_8_i2c_device_8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dev_static_addr_9 : 7;
        unsigned int reserved_0 : 9;
        unsigned int dev_dynamic_addr_9 : 8;
        unsigned int reserved_1 : 5;
        unsigned int dev_nack_retry_cnt_9 : 2;
        unsigned int i2c_device_9 : 1;
    } reg;
} SOC_HI_I3C_V200_DEVICE_TABLE_9_UNION;
#endif
#define SOC_HI_I3C_V200_DEVICE_TABLE_9_dev_static_addr_9_START (0)
#define SOC_HI_I3C_V200_DEVICE_TABLE_9_dev_static_addr_9_END (6)
#define SOC_HI_I3C_V200_DEVICE_TABLE_9_dev_dynamic_addr_9_START (16)
#define SOC_HI_I3C_V200_DEVICE_TABLE_9_dev_dynamic_addr_9_END (23)
#define SOC_HI_I3C_V200_DEVICE_TABLE_9_dev_nack_retry_cnt_9_START (29)
#define SOC_HI_I3C_V200_DEVICE_TABLE_9_dev_nack_retry_cnt_9_END (30)
#define SOC_HI_I3C_V200_DEVICE_TABLE_9_i2c_device_9_START (31)
#define SOC_HI_I3C_V200_DEVICE_TABLE_9_i2c_device_9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dev_static_addr_10 : 7;
        unsigned int reserved_0 : 9;
        unsigned int dev_dynamic_addr_10 : 8;
        unsigned int reserved_1 : 5;
        unsigned int dev_nack_retry_cnt_10 : 2;
        unsigned int i2c_device_10 : 1;
    } reg;
} SOC_HI_I3C_V200_DEVICE_TABLE_10_UNION;
#endif
#define SOC_HI_I3C_V200_DEVICE_TABLE_10_dev_static_addr_10_START (0)
#define SOC_HI_I3C_V200_DEVICE_TABLE_10_dev_static_addr_10_END (6)
#define SOC_HI_I3C_V200_DEVICE_TABLE_10_dev_dynamic_addr_10_START (16)
#define SOC_HI_I3C_V200_DEVICE_TABLE_10_dev_dynamic_addr_10_END (23)
#define SOC_HI_I3C_V200_DEVICE_TABLE_10_dev_nack_retry_cnt_10_START (29)
#define SOC_HI_I3C_V200_DEVICE_TABLE_10_dev_nack_retry_cnt_10_END (30)
#define SOC_HI_I3C_V200_DEVICE_TABLE_10_i2c_device_10_START (31)
#define SOC_HI_I3C_V200_DEVICE_TABLE_10_i2c_device_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dev_static_addr_11 : 7;
        unsigned int reserved_0 : 9;
        unsigned int dev_dynamic_addr_11 : 8;
        unsigned int reserved_1 : 5;
        unsigned int dev_nack_retry_cnt_11 : 2;
        unsigned int i2c_device_11 : 1;
    } reg;
} SOC_HI_I3C_V200_DEVICE_TABLE_11_UNION;
#endif
#define SOC_HI_I3C_V200_DEVICE_TABLE_11_dev_static_addr_11_START (0)
#define SOC_HI_I3C_V200_DEVICE_TABLE_11_dev_static_addr_11_END (6)
#define SOC_HI_I3C_V200_DEVICE_TABLE_11_dev_dynamic_addr_11_START (16)
#define SOC_HI_I3C_V200_DEVICE_TABLE_11_dev_dynamic_addr_11_END (23)
#define SOC_HI_I3C_V200_DEVICE_TABLE_11_dev_nack_retry_cnt_11_START (29)
#define SOC_HI_I3C_V200_DEVICE_TABLE_11_dev_nack_retry_cnt_11_END (30)
#define SOC_HI_I3C_V200_DEVICE_TABLE_11_i2c_device_11_START (31)
#define SOC_HI_I3C_V200_DEVICE_TABLE_11_i2c_device_11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fsmc_rsp_state : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_HI_I3C_V200_RESP_STATE_UNION;
#endif
#define SOC_HI_I3C_V200_RESP_STATE_fsmc_rsp_state_START (0)
#define SOC_HI_I3C_V200_RESP_STATE_fsmc_rsp_state_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int fsmc_st_curr : 4;
        unsigned int fsmc_curr_trans_st : 4;
        unsigned int slv_rd_termn_state : 20;
        unsigned int sda_level : 1;
        unsigned int scl_level : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_HI_I3C_V200_TRANS_STATE_UNION;
#endif
#define SOC_HI_I3C_V200_TRANS_STATE_fsmc_st_curr_START (0)
#define SOC_HI_I3C_V200_TRANS_STATE_fsmc_st_curr_END (3)
#define SOC_HI_I3C_V200_TRANS_STATE_fsmc_curr_trans_st_START (4)
#define SOC_HI_I3C_V200_TRANS_STATE_fsmc_curr_trans_st_END (7)
#define SOC_HI_I3C_V200_TRANS_STATE_slv_rd_termn_state_START (8)
#define SOC_HI_I3C_V200_TRANS_STATE_slv_rd_termn_state_END (27)
#define SOC_HI_I3C_V200_TRANS_STATE_sda_level_START (28)
#define SOC_HI_I3C_V200_TRANS_STATE_sda_level_END (28)
#define SOC_HI_I3C_V200_TRANS_STATE_scl_level_START (29)
#define SOC_HI_I3C_V200_TRANS_STATE_scl_level_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trans_err_int_mstat : 1;
        unsigned int rsp_int_mstat : 1;
        unsigned int ibi_int_mstat : 1;
        unsigned int slv_rd_termn_int_mstat : 1;
        unsigned int fifo_err_int_mstat : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_HI_I3C_V200_INT_MSTAT_UNION;
#endif
#define SOC_HI_I3C_V200_INT_MSTAT_trans_err_int_mstat_START (0)
#define SOC_HI_I3C_V200_INT_MSTAT_trans_err_int_mstat_END (0)
#define SOC_HI_I3C_V200_INT_MSTAT_rsp_int_mstat_START (1)
#define SOC_HI_I3C_V200_INT_MSTAT_rsp_int_mstat_END (1)
#define SOC_HI_I3C_V200_INT_MSTAT_ibi_int_mstat_START (2)
#define SOC_HI_I3C_V200_INT_MSTAT_ibi_int_mstat_END (2)
#define SOC_HI_I3C_V200_INT_MSTAT_slv_rd_termn_int_mstat_START (3)
#define SOC_HI_I3C_V200_INT_MSTAT_slv_rd_termn_int_mstat_END (3)
#define SOC_HI_I3C_V200_INT_MSTAT_fifo_err_int_mstat_START (4)
#define SOC_HI_I3C_V200_INT_MSTAT_fifo_err_int_mstat_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trans_err_int : 1;
        unsigned int rsp_int : 1;
        unsigned int ibi_int : 1;
        unsigned int slv_rd_termn_int : 1;
        unsigned int fifo_err_int : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_HI_I3C_V200_INT_STAT_UNION;
#endif
#define SOC_HI_I3C_V200_INT_STAT_trans_err_int_START (0)
#define SOC_HI_I3C_V200_INT_STAT_trans_err_int_END (0)
#define SOC_HI_I3C_V200_INT_STAT_rsp_int_START (1)
#define SOC_HI_I3C_V200_INT_STAT_rsp_int_END (1)
#define SOC_HI_I3C_V200_INT_STAT_ibi_int_START (2)
#define SOC_HI_I3C_V200_INT_STAT_ibi_int_END (2)
#define SOC_HI_I3C_V200_INT_STAT_slv_rd_termn_int_START (3)
#define SOC_HI_I3C_V200_INT_STAT_slv_rd_termn_int_END (3)
#define SOC_HI_I3C_V200_INT_STAT_fifo_err_int_START (4)
#define SOC_HI_I3C_V200_INT_STAT_fifo_err_int_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trans_err_int_mask : 1;
        unsigned int rsp_int_mask : 1;
        unsigned int ibi_int_mask : 1;
        unsigned int slv_rd_termn_int_mask : 1;
        unsigned int fifo_err_int_mask : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_HI_I3C_V200_INT_MASK_UNION;
#endif
#define SOC_HI_I3C_V200_INT_MASK_trans_err_int_mask_START (0)
#define SOC_HI_I3C_V200_INT_MASK_trans_err_int_mask_END (0)
#define SOC_HI_I3C_V200_INT_MASK_rsp_int_mask_START (1)
#define SOC_HI_I3C_V200_INT_MASK_rsp_int_mask_END (1)
#define SOC_HI_I3C_V200_INT_MASK_ibi_int_mask_START (2)
#define SOC_HI_I3C_V200_INT_MASK_ibi_int_mask_END (2)
#define SOC_HI_I3C_V200_INT_MASK_slv_rd_termn_int_mask_START (3)
#define SOC_HI_I3C_V200_INT_MASK_slv_rd_termn_int_mask_END (3)
#define SOC_HI_I3C_V200_INT_MASK_fifo_err_int_mask_START (4)
#define SOC_HI_I3C_V200_INT_MASK_fifo_err_int_mask_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ibi_pure_data : 8;
        unsigned int ibi_psm : 3;
        unsigned int ibi_ack : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_HI_I3C_V200_IBI_DTATA_UNION;
#endif
#define SOC_HI_I3C_V200_IBI_DTATA_ibi_pure_data_START (0)
#define SOC_HI_I3C_V200_IBI_DTATA_ibi_pure_data_END (7)
#define SOC_HI_I3C_V200_IBI_DTATA_ibi_psm_START (8)
#define SOC_HI_I3C_V200_IBI_DTATA_ibi_psm_END (10)
#define SOC_HI_I3C_V200_IBI_DTATA_ibi_ack_START (11)
#define SOC_HI_I3C_V200_IBI_DTATA_ibi_ack_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2c_scl_high : 9;
        unsigned int i2c_scl_low : 10;
        unsigned int reserved : 13;
    } reg;
} SOC_HI_I3C_V200_COUNTER_REG1_UNION;
#endif
#define SOC_HI_I3C_V200_COUNTER_REG1_i2c_scl_high_START (0)
#define SOC_HI_I3C_V200_COUNTER_REG1_i2c_scl_high_END (8)
#define SOC_HI_I3C_V200_COUNTER_REG1_i2c_scl_low_START (9)
#define SOC_HI_I3C_V200_COUNTER_REG1_i2c_scl_low_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i2c_bus_free : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_HI_I3C_V200_COUNTER_REG2_UNION;
#endif
#define SOC_HI_I3C_V200_COUNTER_REG2_i2c_bus_free_START (0)
#define SOC_HI_I3C_V200_COUNTER_REG2_i2c_bus_free_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 10;
        unsigned int i3c_od_high : 6;
        unsigned int i3c_od_low : 16;
    } reg;
} SOC_HI_I3C_V200_COUNTER_REG3_UNION;
#endif
#define SOC_HI_I3C_V200_COUNTER_REG3_i3c_od_high_START (10)
#define SOC_HI_I3C_V200_COUNTER_REG3_i3c_od_high_END (15)
#define SOC_HI_I3C_V200_COUNTER_REG3_i3c_od_low_START (16)
#define SOC_HI_I3C_V200_COUNTER_REG3_i3c_od_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i3c_od_cas : 25;
        unsigned int reserved : 7;
    } reg;
} SOC_HI_I3C_V200_COUNTER_REG4_UNION;
#endif
#define SOC_HI_I3C_V200_COUNTER_REG4_i3c_od_cas_START (0)
#define SOC_HI_I3C_V200_COUNTER_REG4_i3c_od_cas_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i3c_od_idle : 19;
        unsigned int reserved_0 : 2;
        unsigned int i3c_tbit_ext_low : 4;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_HI_I3C_V200_COUNTER_REG5_UNION;
#endif
#define SOC_HI_I3C_V200_COUNTER_REG5_i3c_od_idle_START (0)
#define SOC_HI_I3C_V200_COUNTER_REG5_i3c_od_idle_END (18)
#define SOC_HI_I3C_V200_COUNTER_REG5_i3c_tbit_ext_low_START (21)
#define SOC_HI_I3C_V200_COUNTER_REG5_i3c_tbit_ext_low_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int i3c_pp_low : 19;
        unsigned int reserved : 13;
    } reg;
} SOC_HI_I3C_V200_COUNTER_REG6_UNION;
#endif
#define SOC_HI_I3C_V200_COUNTER_REG6_i3c_pp_low_START (0)
#define SOC_HI_I3C_V200_COUNTER_REG6_i3c_pp_low_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 8;
        unsigned int i3c_pp_high : 8;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_HI_I3C_V200_COUNTER_REG7_UNION;
#endif
#define SOC_HI_I3C_V200_COUNTER_REG7_i3c_pp_high_START (8)
#define SOC_HI_I3C_V200_COUNTER_REG7_i3c_pp_high_END (15)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
