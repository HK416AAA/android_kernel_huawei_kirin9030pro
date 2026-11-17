#ifndef __SOC_SDEMMC_INTERFACE_H__
#define __SOC_SDEMMC_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_SDEMMC_SDMA_ADDR_ARG_ADDR(base) (base)
#define SOC_SDEMMC_BLOCK_SIZE_ADDR(base) ((base) + 0x04UL)
#define SOC_SDEMMC_ARGUMENT_ADDR(base) ((base) + 0x08UL)
#define SOC_SDEMMC_COMMAND_TRANSFER_MODE_ADDR(base) ((base) + 0x0CUL)
#define SOC_SDEMMC_RESPONSE_0_ADDR(base) ((base) + 0x10UL)
#define SOC_SDEMMC_RESPONSE_32_ADDR(base) ((base) + 0x14UL)
#define SOC_SDEMMC_RESPONSE_64_ADDR(base) ((base) + 0x18UL)
#define SOC_SDEMMC_RESPONSE_96_ADDR(base) ((base) + 0x1CUL)
#define SOC_SDEMMC_BUFFER_DATA_PORT_ADDR(base) ((base) + 0x20UL)
#define SOC_SDEMMC_PRESENT_STATE_ADDR(base) ((base) + 0x24UL)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_ADDR(base) ((base) + 0x28UL)
#define SOC_SDEMMC_CLOCK_CONTROL_ADDR(base) ((base) + 0x2CUL)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_ADDR(base) ((base) + 0x30UL)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_ADDR(base) ((base) + 0x34UL)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_ADDR(base) ((base) + 0x38UL)
#define SOC_SDEMMC_HOST_CONTROL2_AUTO_CMD_ERROR_STATUS_ADDR(base) ((base) + 0x3CUL)
#define SOC_SDEMMC_CAPABILITIES0_ADDR(base) ((base) + 0x40UL)
#define SOC_SDEMMC_CAPABILITIES1_ADDR(base) ((base) + 0x44UL)
#define SOC_SDEMMC_CURRENT_CAPABILITIES0_ADDR(base) ((base) + 0x48UL)
#define SOC_SDEMMC_CURRENT_CAPABILITIES1_ADDR(base) ((base) + 0x4CUL)
#define SOC_SDEMMC_FORCE_EVENT_ADDR(base) ((base) + 0x50UL)
#define SOC_SDEMMC_ADMA_ERROR_STATUS_ADDR(base) ((base) + 0x54UL)
#define SOC_SDEMMC_ADMA_SYSTEM_ADDRESS_LOWER_ADDR(base) ((base) + 0x58UL)
#define SOC_SDEMMC_ADMA_SYSTEM_ADDRESS1_UPPER_ADDR(base) ((base) + 0x5CUL)
#define SOC_SDEMMC_PRESET_VALUE0_ADDR(base) ((base) + 0x60UL)
#define SOC_SDEMMC_PRESET_VALUE1_ADDR(base) ((base) + 0x64UL)
#define SOC_SDEMMC_PRESET_VALUE2_ADDR(base) ((base) + 0x68UL)
#define SOC_SDEMMC_PRESET_VALUE3_ADDR(base) ((base) + 0x6CUL)
#define SOC_SDEMMC_CRG_CTRL_0_ADDR(base) ((base) + 0x80UL)
#define SOC_SDEMMC_CRG_CTRL_1_ADDR(base) ((base) + 0x84UL)
#define SOC_SDEMMC_TUNING_RESULT_VALUE_ADDR(base) ((base) + 0x88UL)
#define SOC_SDEMMC_TIMING_CTRL_0_ADDR(base) ((base) + 0x90UL)
#define SOC_SDEMMC_TIMING_CTRL_1_ADDR(base) ((base) + 0x94UL)
#define SOC_SDEMMC_TIMING_CTRL_2_ADDR(base) ((base) + 0x98UL)
#define SOC_SDEMMC_AXI_PARA_ADDR(base) ((base) + 0xA0UL)
#define SOC_SDEMMC_SHARED_BUS_CONTROL_ADDR(base) ((base) + 0xE0UL)
#define SOC_SDEMMC_VERSION_SLOT_INTERRUPT_STATUS_ADDR(base) ((base) + 0xFCUL)
#define SOC_SDEMMC_ECO_RSV_RW_ADDR(base) ((base) + 0x800UL)
#define SOC_SDEMMC_ECO_RSV_RO_ADDR(base) ((base) + 0x804UL)
#define SOC_SDEMMC_DFX_BUF_CTRL_STAT_ADDR(base) ((base) + 0x808UL)
#define SOC_SDEMMC_DFX_BUF_APBCTRL_ADDR(base) ((base) + 0x80CUL)
#define SOC_SDEMMC_DFX_DATAPATH_BLK_ADDR(base) ((base) + 0x810UL)
#define SOC_SDEMMC_DFX_DATAPATH_BUF_CTRL_ADDR(base) ((base) + 0x814UL)
#define SOC_SDEMMC_DFX_DATAPATH_P2S_S2P_ADDR(base) ((base) + 0x818UL)
#define SOC_SDEMMC_DFX_DATAPATH_CTRL_ADDR(base) ((base) + 0x81CUL)
#define SOC_SDEMMC_DFX_DATAPATH_CRC_STATUS_ADDR(base) ((base) + 0x820UL)
#define SOC_SDEMMC_DFX_DATAPATH_BOOT_CTRL_ADDR(base) ((base) + 0x824UL)
#define SOC_SDEMMC_DFX_SDINTF_DOUT_ADDR(base) ((base) + 0x828UL)
#define SOC_SDEMMC_DFX_SDINTF_DIN_ADDR(base) ((base) + 0x82CUL)
#define SOC_SDEMMC_DFX_SDINTF_AFIFO_ADDR(base) ((base) + 0x830UL)
#define SOC_SDEMMC_DFX_BYTE_CNT_SENT_ADDR(base) ((base) + 0x834UL)
#define SOC_SDEMMC_DFX_BYTE_CNT_RECEIVED_ADDR(base) ((base) + 0x838UL)
#define SOC_SDEMMC_DFX_BLK_TRANSFER_ADDR(base) ((base) + 0x83CUL)
#define SOC_SDEMMC_DFX_BLK_TRY_ADDR(base) ((base) + 0x840UL)
#define SOC_SDEMMC_DFX_RD_BLK_GAP_LAT_ADDR(base) ((base) + 0x844UL)
#define SOC_SDEMMC_DFT_RD_BLK_GAP_LAT_LAST_ADDR(base) ((base) + 0x848UL)
#define SOC_SDEMMC_DFX_CRC_STATUS_LAT_ADDR(base) ((base) + 0x84CUL)
#define SOC_SDEMMC_DFX_DATAPATH_CTRL_1_ADDR(base) ((base) + 0x850UL)
#define SOC_SDEMMC_TUNING_PHASES_RESULT_ADDR(base) ((base) + 0x854UL)
#define SOC_SDEMMC_DFX_TUNING_ADDR(base) ((base) + 0x858UL)
#define SOC_SDEMMC_DFX_TUNING_1_ADDR(base) ((base) + 0x85CUL)
#define SOC_SDEMMC_DFX_CMDPATH_ADDR(base) ((base) + 0x860UL)
#define SOC_SDEMMC_DFT_CONFIG_ADDR(base) ((base) + 0x864UL)
#define SOC_SDEMMC_DFX_DMA_CTRL_SEL_ADDR(base) ((base) + 0x900UL)
#define SOC_SDEMMC_DFX_DMA_NEXT_SDMA_ADDR_ADDR(base) ((base) + 0x904UL)
#define SOC_SDEMMC_DFX_DMA_NEXT_ADMA_ADDR_L_ADDR(base) ((base) + 0x908UL)
#define SOC_SDEMMC_DFX_DMA_NEXT_ADMA_ADDR_H_ADDR(base) ((base) + 0x90CUL)
#define SOC_SDEMMC_DFX_DMA_AXI_TRANSFER_CNT_ADDR(base) ((base) + 0x910UL)
#define SOC_SDEMMC_DFX_DMA_BLOCK_VALUE_ADDR(base) ((base) + 0x914UL)
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_0_ADDR(base) ((base) + 0x918UL)
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_1_ADDR(base) ((base) + 0x91CUL)
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_2_ADDR(base) ((base) + 0x920UL)
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_3_ADDR(base) ((base) + 0x924UL)
#define SOC_SDEMMC_DFX_DMA_BUFFER_ADDR_ADDR(base) ((base) + 0x928UL)
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_ADDR_L_ADDR(base) ((base) + 0x92CUL)
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_ADDR_H_ADDR(base) ((base) + 0x930UL)
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_OTHERS_ADDR(base) ((base) + 0x934UL)
#define SOC_SDEMMC_DFX_DMA_NEXT_SDMA_DESCR_ADDR_ADDR(base) ((base) + 0x938UL)
#define SOC_SDEMMC_DFX_DMA_NEXT_ADMA_DESCR_ADDR_L_ADDR(base) ((base) + 0x93CUL)
#define SOC_SDEMMC_DFX_DMA_NEXT_ADMA_DESCR_ADDR_H_ADDR(base) ((base) + 0x940UL)
#define SOC_SDEMMC_DFX_DMA_ADMA_DESCR_LEN_LEFT_ADDR(base) ((base) + 0x944UL)
#define SOC_SDEMMC_DFX_DMA_CONTX_TABLE_VALUE_ADDR(base) ((base) + 0x948UL)
#define SOC_SDEMMC_DFX_DMA_RESP_ERROR_INFO_ADDR(base) ((base) + 0x94CUL)
#define SOC_SDEMMC_DFX_DMA_AXI_SD_BUFFER_ADDR_ADDR(base) ((base) + 0x950UL)
#else
#define SOC_SDEMMC_SDMA_ADDR_ARG_ADDR(base) (base)
#define SOC_SDEMMC_BLOCK_SIZE_ADDR(base) ((base) + 0x04)
#define SOC_SDEMMC_ARGUMENT_ADDR(base) ((base) + 0x08)
#define SOC_SDEMMC_COMMAND_TRANSFER_MODE_ADDR(base) ((base) + 0x0C)
#define SOC_SDEMMC_RESPONSE_0_ADDR(base) ((base) + 0x10)
#define SOC_SDEMMC_RESPONSE_32_ADDR(base) ((base) + 0x14)
#define SOC_SDEMMC_RESPONSE_64_ADDR(base) ((base) + 0x18)
#define SOC_SDEMMC_RESPONSE_96_ADDR(base) ((base) + 0x1C)
#define SOC_SDEMMC_BUFFER_DATA_PORT_ADDR(base) ((base) + 0x20)
#define SOC_SDEMMC_PRESENT_STATE_ADDR(base) ((base) + 0x24)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_ADDR(base) ((base) + 0x28)
#define SOC_SDEMMC_CLOCK_CONTROL_ADDR(base) ((base) + 0x2C)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_ADDR(base) ((base) + 0x30)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_ADDR(base) ((base) + 0x34)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_ADDR(base) ((base) + 0x38)
#define SOC_SDEMMC_HOST_CONTROL2_AUTO_CMD_ERROR_STATUS_ADDR(base) ((base) + 0x3C)
#define SOC_SDEMMC_CAPABILITIES0_ADDR(base) ((base) + 0x40)
#define SOC_SDEMMC_CAPABILITIES1_ADDR(base) ((base) + 0x44)
#define SOC_SDEMMC_CURRENT_CAPABILITIES0_ADDR(base) ((base) + 0x48)
#define SOC_SDEMMC_CURRENT_CAPABILITIES1_ADDR(base) ((base) + 0x4C)
#define SOC_SDEMMC_FORCE_EVENT_ADDR(base) ((base) + 0x50)
#define SOC_SDEMMC_ADMA_ERROR_STATUS_ADDR(base) ((base) + 0x54)
#define SOC_SDEMMC_ADMA_SYSTEM_ADDRESS_LOWER_ADDR(base) ((base) + 0x58)
#define SOC_SDEMMC_ADMA_SYSTEM_ADDRESS1_UPPER_ADDR(base) ((base) + 0x5C)
#define SOC_SDEMMC_PRESET_VALUE0_ADDR(base) ((base) + 0x60)
#define SOC_SDEMMC_PRESET_VALUE1_ADDR(base) ((base) + 0x64)
#define SOC_SDEMMC_PRESET_VALUE2_ADDR(base) ((base) + 0x68)
#define SOC_SDEMMC_PRESET_VALUE3_ADDR(base) ((base) + 0x6C)
#define SOC_SDEMMC_CRG_CTRL_0_ADDR(base) ((base) + 0x80)
#define SOC_SDEMMC_CRG_CTRL_1_ADDR(base) ((base) + 0x84)
#define SOC_SDEMMC_TUNING_RESULT_VALUE_ADDR(base) ((base) + 0x88)
#define SOC_SDEMMC_TIMING_CTRL_0_ADDR(base) ((base) + 0x90)
#define SOC_SDEMMC_TIMING_CTRL_1_ADDR(base) ((base) + 0x94)
#define SOC_SDEMMC_TIMING_CTRL_2_ADDR(base) ((base) + 0x98)
#define SOC_SDEMMC_AXI_PARA_ADDR(base) ((base) + 0xA0)
#define SOC_SDEMMC_SHARED_BUS_CONTROL_ADDR(base) ((base) + 0xE0)
#define SOC_SDEMMC_VERSION_SLOT_INTERRUPT_STATUS_ADDR(base) ((base) + 0xFC)
#define SOC_SDEMMC_ECO_RSV_RW_ADDR(base) ((base) + 0x800)
#define SOC_SDEMMC_ECO_RSV_RO_ADDR(base) ((base) + 0x804)
#define SOC_SDEMMC_DFX_BUF_CTRL_STAT_ADDR(base) ((base) + 0x808)
#define SOC_SDEMMC_DFX_BUF_APBCTRL_ADDR(base) ((base) + 0x80C)
#define SOC_SDEMMC_DFX_DATAPATH_BLK_ADDR(base) ((base) + 0x810)
#define SOC_SDEMMC_DFX_DATAPATH_BUF_CTRL_ADDR(base) ((base) + 0x814)
#define SOC_SDEMMC_DFX_DATAPATH_P2S_S2P_ADDR(base) ((base) + 0x818)
#define SOC_SDEMMC_DFX_DATAPATH_CTRL_ADDR(base) ((base) + 0x81C)
#define SOC_SDEMMC_DFX_DATAPATH_CRC_STATUS_ADDR(base) ((base) + 0x820)
#define SOC_SDEMMC_DFX_DATAPATH_BOOT_CTRL_ADDR(base) ((base) + 0x824)
#define SOC_SDEMMC_DFX_SDINTF_DOUT_ADDR(base) ((base) + 0x828)
#define SOC_SDEMMC_DFX_SDINTF_DIN_ADDR(base) ((base) + 0x82C)
#define SOC_SDEMMC_DFX_SDINTF_AFIFO_ADDR(base) ((base) + 0x830)
#define SOC_SDEMMC_DFX_BYTE_CNT_SENT_ADDR(base) ((base) + 0x834)
#define SOC_SDEMMC_DFX_BYTE_CNT_RECEIVED_ADDR(base) ((base) + 0x838)
#define SOC_SDEMMC_DFX_BLK_TRANSFER_ADDR(base) ((base) + 0x83C)
#define SOC_SDEMMC_DFX_BLK_TRY_ADDR(base) ((base) + 0x840)
#define SOC_SDEMMC_DFX_RD_BLK_GAP_LAT_ADDR(base) ((base) + 0x844)
#define SOC_SDEMMC_DFT_RD_BLK_GAP_LAT_LAST_ADDR(base) ((base) + 0x848)
#define SOC_SDEMMC_DFX_CRC_STATUS_LAT_ADDR(base) ((base) + 0x84C)
#define SOC_SDEMMC_DFX_DATAPATH_CTRL_1_ADDR(base) ((base) + 0x850)
#define SOC_SDEMMC_TUNING_PHASES_RESULT_ADDR(base) ((base) + 0x854)
#define SOC_SDEMMC_DFX_TUNING_ADDR(base) ((base) + 0x858)
#define SOC_SDEMMC_DFX_TUNING_1_ADDR(base) ((base) + 0x85C)
#define SOC_SDEMMC_DFX_CMDPATH_ADDR(base) ((base) + 0x860)
#define SOC_SDEMMC_DFT_CONFIG_ADDR(base) ((base) + 0x864)
#define SOC_SDEMMC_DFX_DMA_CTRL_SEL_ADDR(base) ((base) + 0x900)
#define SOC_SDEMMC_DFX_DMA_NEXT_SDMA_ADDR_ADDR(base) ((base) + 0x904)
#define SOC_SDEMMC_DFX_DMA_NEXT_ADMA_ADDR_L_ADDR(base) ((base) + 0x908)
#define SOC_SDEMMC_DFX_DMA_NEXT_ADMA_ADDR_H_ADDR(base) ((base) + 0x90C)
#define SOC_SDEMMC_DFX_DMA_AXI_TRANSFER_CNT_ADDR(base) ((base) + 0x910)
#define SOC_SDEMMC_DFX_DMA_BLOCK_VALUE_ADDR(base) ((base) + 0x914)
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_0_ADDR(base) ((base) + 0x918)
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_1_ADDR(base) ((base) + 0x91C)
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_2_ADDR(base) ((base) + 0x920)
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_3_ADDR(base) ((base) + 0x924)
#define SOC_SDEMMC_DFX_DMA_BUFFER_ADDR_ADDR(base) ((base) + 0x928)
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_ADDR_L_ADDR(base) ((base) + 0x92C)
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_ADDR_H_ADDR(base) ((base) + 0x930)
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_OTHERS_ADDR(base) ((base) + 0x934)
#define SOC_SDEMMC_DFX_DMA_NEXT_SDMA_DESCR_ADDR_ADDR(base) ((base) + 0x938)
#define SOC_SDEMMC_DFX_DMA_NEXT_ADMA_DESCR_ADDR_L_ADDR(base) ((base) + 0x93C)
#define SOC_SDEMMC_DFX_DMA_NEXT_ADMA_DESCR_ADDR_H_ADDR(base) ((base) + 0x940)
#define SOC_SDEMMC_DFX_DMA_ADMA_DESCR_LEN_LEFT_ADDR(base) ((base) + 0x944)
#define SOC_SDEMMC_DFX_DMA_CONTX_TABLE_VALUE_ADDR(base) ((base) + 0x948)
#define SOC_SDEMMC_DFX_DMA_RESP_ERROR_INFO_ADDR(base) ((base) + 0x94C)
#define SOC_SDEMMC_DFX_DMA_AXI_SD_BUFFER_ADDR_ADDR(base) ((base) + 0x950)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sdma_addr_arg : 32;
    } reg;
} SOC_SDEMMC_SDMA_ADDR_ARG_UNION;
#endif
#define SOC_SDEMMC_SDMA_ADDR_ARG_sdma_addr_arg_START (0)
#define SOC_SDEMMC_SDMA_ADDR_ARG_sdma_addr_arg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int transfer_block_size : 12;
        unsigned int sdma_buffer_boundary : 3;
        unsigned int reserved : 1;
        unsigned int block_count : 16;
    } reg;
} SOC_SDEMMC_BLOCK_SIZE_UNION;
#endif
#define SOC_SDEMMC_BLOCK_SIZE_transfer_block_size_START (0)
#define SOC_SDEMMC_BLOCK_SIZE_transfer_block_size_END (11)
#define SOC_SDEMMC_BLOCK_SIZE_sdma_buffer_boundary_START (12)
#define SOC_SDEMMC_BLOCK_SIZE_sdma_buffer_boundary_END (14)
#define SOC_SDEMMC_BLOCK_SIZE_block_count_START (16)
#define SOC_SDEMMC_BLOCK_SIZE_block_count_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_argument : 32;
    } reg;
} SOC_SDEMMC_ARGUMENT_UNION;
#endif
#define SOC_SDEMMC_ARGUMENT_cmd_argument_START (0)
#define SOC_SDEMMC_ARGUMENT_cmd_argument_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_enable : 1;
        unsigned int block_count_enable : 1;
        unsigned int auto_cmd_enable : 2;
        unsigned int transfer_direction : 1;
        unsigned int multi_block_select : 1;
        unsigned int reserved_0 : 10;
        unsigned int response_type : 2;
        unsigned int reserved_1 : 1;
        unsigned int command_crc_check_enable : 1;
        unsigned int command_index_check_enable : 1;
        unsigned int data_present_select : 1;
        unsigned int command_type : 2;
        unsigned int command_index : 6;
        unsigned int boot_ack_en : 1;
        unsigned int man_boot_en : 1;
    } reg;
} SOC_SDEMMC_COMMAND_TRANSFER_MODE_UNION;
#endif
#define SOC_SDEMMC_COMMAND_TRANSFER_MODE_dma_enable_START (0)
#define SOC_SDEMMC_COMMAND_TRANSFER_MODE_dma_enable_END (0)
#define SOC_SDEMMC_COMMAND_TRANSFER_MODE_block_count_enable_START (1)
#define SOC_SDEMMC_COMMAND_TRANSFER_MODE_block_count_enable_END (1)
#define SOC_SDEMMC_COMMAND_TRANSFER_MODE_auto_cmd_enable_START (2)
#define SOC_SDEMMC_COMMAND_TRANSFER_MODE_auto_cmd_enable_END (3)
#define SOC_SDEMMC_COMMAND_TRANSFER_MODE_transfer_direction_START (4)
#define SOC_SDEMMC_COMMAND_TRANSFER_MODE_transfer_direction_END (4)
#define SOC_SDEMMC_COMMAND_TRANSFER_MODE_multi_block_select_START (5)
#define SOC_SDEMMC_COMMAND_TRANSFER_MODE_multi_block_select_END (5)
#define SOC_SDEMMC_COMMAND_TRANSFER_MODE_response_type_START (16)
#define SOC_SDEMMC_COMMAND_TRANSFER_MODE_response_type_END (17)
#define SOC_SDEMMC_COMMAND_TRANSFER_MODE_command_crc_check_enable_START (19)
#define SOC_SDEMMC_COMMAND_TRANSFER_MODE_command_crc_check_enable_END (19)
#define SOC_SDEMMC_COMMAND_TRANSFER_MODE_command_index_check_enable_START (20)
#define SOC_SDEMMC_COMMAND_TRANSFER_MODE_command_index_check_enable_END (20)
#define SOC_SDEMMC_COMMAND_TRANSFER_MODE_data_present_select_START (21)
#define SOC_SDEMMC_COMMAND_TRANSFER_MODE_data_present_select_END (21)
#define SOC_SDEMMC_COMMAND_TRANSFER_MODE_command_type_START (22)
#define SOC_SDEMMC_COMMAND_TRANSFER_MODE_command_type_END (23)
#define SOC_SDEMMC_COMMAND_TRANSFER_MODE_command_index_START (24)
#define SOC_SDEMMC_COMMAND_TRANSFER_MODE_command_index_END (29)
#define SOC_SDEMMC_COMMAND_TRANSFER_MODE_boot_ack_en_START (30)
#define SOC_SDEMMC_COMMAND_TRANSFER_MODE_boot_ack_en_END (30)
#define SOC_SDEMMC_COMMAND_TRANSFER_MODE_man_boot_en_START (31)
#define SOC_SDEMMC_COMMAND_TRANSFER_MODE_man_boot_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int response_0 : 32;
    } reg;
} SOC_SDEMMC_RESPONSE_0_UNION;
#endif
#define SOC_SDEMMC_RESPONSE_0_response_0_START (00)
#define SOC_SDEMMC_RESPONSE_0_response_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int response_32 : 32;
    } reg;
} SOC_SDEMMC_RESPONSE_32_UNION;
#endif
#define SOC_SDEMMC_RESPONSE_32_response_32_START (00)
#define SOC_SDEMMC_RESPONSE_32_response_32_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int response_64 : 32;
    } reg;
} SOC_SDEMMC_RESPONSE_64_UNION;
#endif
#define SOC_SDEMMC_RESPONSE_64_response_64_START (00)
#define SOC_SDEMMC_RESPONSE_64_response_64_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int response_96 : 32;
    } reg;
} SOC_SDEMMC_RESPONSE_96_UNION;
#endif
#define SOC_SDEMMC_RESPONSE_96_response_96_START (00)
#define SOC_SDEMMC_RESPONSE_96_response_96_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buffer_data : 32;
    } reg;
} SOC_SDEMMC_BUFFER_DATA_PORT_UNION;
#endif
#define SOC_SDEMMC_BUFFER_DATA_PORT_buffer_data_START (00)
#define SOC_SDEMMC_BUFFER_DATA_PORT_buffer_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_inhibit_cmd : 1;
        unsigned int cmd_inhibit_dat : 1;
        unsigned int dat_line_active : 1;
        unsigned int retuning_request : 1;
        unsigned int reserved_0 : 4;
        unsigned int write_transfer_active : 1;
        unsigned int read_transfer_active : 1;
        unsigned int buffer_write_enable : 1;
        unsigned int buffer_read_enable : 1;
        unsigned int reserved_1 : 4;
        unsigned int card_inserted : 1;
        unsigned int card_state_stable : 1;
        unsigned int card_detect_pin_level : 1;
        unsigned int write_protect : 1;
        unsigned int dat_signal_level : 4;
        unsigned int cmd_signal_level : 1;
        unsigned int reserved_2 : 7;
    } reg;
} SOC_SDEMMC_PRESENT_STATE_UNION;
#endif
#define SOC_SDEMMC_PRESENT_STATE_cmd_inhibit_cmd_START (0)
#define SOC_SDEMMC_PRESENT_STATE_cmd_inhibit_cmd_END (0)
#define SOC_SDEMMC_PRESENT_STATE_cmd_inhibit_dat_START (1)
#define SOC_SDEMMC_PRESENT_STATE_cmd_inhibit_dat_END (1)
#define SOC_SDEMMC_PRESENT_STATE_dat_line_active_START (2)
#define SOC_SDEMMC_PRESENT_STATE_dat_line_active_END (2)
#define SOC_SDEMMC_PRESENT_STATE_retuning_request_START (3)
#define SOC_SDEMMC_PRESENT_STATE_retuning_request_END (3)
#define SOC_SDEMMC_PRESENT_STATE_write_transfer_active_START (8)
#define SOC_SDEMMC_PRESENT_STATE_write_transfer_active_END (8)
#define SOC_SDEMMC_PRESENT_STATE_read_transfer_active_START (9)
#define SOC_SDEMMC_PRESENT_STATE_read_transfer_active_END (9)
#define SOC_SDEMMC_PRESENT_STATE_buffer_write_enable_START (10)
#define SOC_SDEMMC_PRESENT_STATE_buffer_write_enable_END (10)
#define SOC_SDEMMC_PRESENT_STATE_buffer_read_enable_START (11)
#define SOC_SDEMMC_PRESENT_STATE_buffer_read_enable_END (11)
#define SOC_SDEMMC_PRESENT_STATE_card_inserted_START (16)
#define SOC_SDEMMC_PRESENT_STATE_card_inserted_END (16)
#define SOC_SDEMMC_PRESENT_STATE_card_state_stable_START (17)
#define SOC_SDEMMC_PRESENT_STATE_card_state_stable_END (17)
#define SOC_SDEMMC_PRESENT_STATE_card_detect_pin_level_START (18)
#define SOC_SDEMMC_PRESENT_STATE_card_detect_pin_level_END (18)
#define SOC_SDEMMC_PRESENT_STATE_write_protect_START (19)
#define SOC_SDEMMC_PRESENT_STATE_write_protect_END (19)
#define SOC_SDEMMC_PRESENT_STATE_dat_signal_level_START (20)
#define SOC_SDEMMC_PRESENT_STATE_dat_signal_level_END (23)
#define SOC_SDEMMC_PRESENT_STATE_cmd_signal_level_START (24)
#define SOC_SDEMMC_PRESENT_STATE_cmd_signal_level_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int led_control : 1;
        unsigned int data_transfer_width : 1;
        unsigned int high_speed_enable : 1;
        unsigned int dma_select : 2;
        unsigned int extended_data_transfer_width : 1;
        unsigned int card_detect_test_level : 1;
        unsigned int card_detect_signal_selection : 1;
        unsigned int sd_bus_power : 1;
        unsigned int sd_bus_voltage : 3;
        unsigned int reserved_0 : 4;
        unsigned int stop_at_block_gap_request : 1;
        unsigned int continue_request : 1;
        unsigned int read_wait_control : 1;
        unsigned int interrupt_at_block_gap : 1;
        unsigned int reserved_1 : 4;
        unsigned int wakeup_event_enable_interrupt : 1;
        unsigned int wakeup_event_enable_insert : 1;
        unsigned int wakeup_event_enable_removal : 1;
        unsigned int reserved_2 : 5;
    } reg;
} SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_UNION;
#endif
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_led_control_START (0)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_led_control_END (0)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_data_transfer_width_START (1)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_data_transfer_width_END (1)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_high_speed_enable_START (2)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_high_speed_enable_END (2)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_dma_select_START (3)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_dma_select_END (4)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_extended_data_transfer_width_START (5)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_extended_data_transfer_width_END (5)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_card_detect_test_level_START (6)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_card_detect_test_level_END (6)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_card_detect_signal_selection_START (7)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_card_detect_signal_selection_END (7)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_sd_bus_power_START (8)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_sd_bus_power_END (8)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_sd_bus_voltage_START (9)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_sd_bus_voltage_END (11)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_stop_at_block_gap_request_START (16)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_stop_at_block_gap_request_END (16)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_continue_request_START (17)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_continue_request_END (17)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_read_wait_control_START (18)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_read_wait_control_END (18)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_interrupt_at_block_gap_START (19)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_interrupt_at_block_gap_END (19)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_wakeup_event_enable_interrupt_START (24)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_wakeup_event_enable_interrupt_END (24)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_wakeup_event_enable_insert_START (25)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_wakeup_event_enable_insert_END (25)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_wakeup_event_enable_removal_START (26)
#define SOC_SDEMMC_HOST_CONTROL_BLOCK_GAP_CONTROL_wakeup_event_enable_removal_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int internal_clock_enable : 1;
        unsigned int internal_clock_stable : 1;
        unsigned int sd_clock_enable : 1;
        unsigned int reserved_0 : 2;
        unsigned int clock_generator_select : 1;
        unsigned int sdclk_freq_upper : 2;
        unsigned int sdclk_freq : 8;
        unsigned int data_timeout_counter : 4;
        unsigned int reserved_1 : 4;
        unsigned int software_reset_all : 1;
        unsigned int software_reset_cmd : 1;
        unsigned int software_reset_dat : 1;
        unsigned int reserved_2 : 5;
    } reg;
} SOC_SDEMMC_CLOCK_CONTROL_UNION;
#endif
#define SOC_SDEMMC_CLOCK_CONTROL_internal_clock_enable_START (0)
#define SOC_SDEMMC_CLOCK_CONTROL_internal_clock_enable_END (0)
#define SOC_SDEMMC_CLOCK_CONTROL_internal_clock_stable_START (1)
#define SOC_SDEMMC_CLOCK_CONTROL_internal_clock_stable_END (1)
#define SOC_SDEMMC_CLOCK_CONTROL_sd_clock_enable_START (2)
#define SOC_SDEMMC_CLOCK_CONTROL_sd_clock_enable_END (2)
#define SOC_SDEMMC_CLOCK_CONTROL_clock_generator_select_START (5)
#define SOC_SDEMMC_CLOCK_CONTROL_clock_generator_select_END (5)
#define SOC_SDEMMC_CLOCK_CONTROL_sdclk_freq_upper_START (6)
#define SOC_SDEMMC_CLOCK_CONTROL_sdclk_freq_upper_END (7)
#define SOC_SDEMMC_CLOCK_CONTROL_sdclk_freq_START (8)
#define SOC_SDEMMC_CLOCK_CONTROL_sdclk_freq_END (15)
#define SOC_SDEMMC_CLOCK_CONTROL_data_timeout_counter_START (16)
#define SOC_SDEMMC_CLOCK_CONTROL_data_timeout_counter_END (19)
#define SOC_SDEMMC_CLOCK_CONTROL_software_reset_all_START (24)
#define SOC_SDEMMC_CLOCK_CONTROL_software_reset_all_END (24)
#define SOC_SDEMMC_CLOCK_CONTROL_software_reset_cmd_START (25)
#define SOC_SDEMMC_CLOCK_CONTROL_software_reset_cmd_END (25)
#define SOC_SDEMMC_CLOCK_CONTROL_software_reset_dat_START (26)
#define SOC_SDEMMC_CLOCK_CONTROL_software_reset_dat_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int command_complete : 1;
        unsigned int transfer_complete : 1;
        unsigned int block_gap_event : 1;
        unsigned int dma_interrupt : 1;
        unsigned int buffer_write_ready : 1;
        unsigned int buffer_read_ready : 1;
        unsigned int card_insertion : 1;
        unsigned int card_removal : 1;
        unsigned int card_interrupt : 1;
        unsigned int int_a : 1;
        unsigned int int_b : 1;
        unsigned int int_c : 1;
        unsigned int retuning_event : 1;
        unsigned int dma_link_interrupt : 1;
        unsigned int reserved_0 : 1;
        unsigned int error_interrupt : 1;
        unsigned int command_timeout_error : 1;
        unsigned int command_crc_error : 1;
        unsigned int command_end_bit_error : 1;
        unsigned int command_index_error : 1;
        unsigned int data_timeout_error : 1;
        unsigned int data_crc_error : 1;
        unsigned int data_end_bit_error : 1;
        unsigned int current_limit_error : 1;
        unsigned int auto_cmd12_error : 1;
        unsigned int adma_error : 1;
        unsigned int tuning_error : 1;
        unsigned int reserved_1 : 1;
        unsigned int axi_rresp_error : 1;
        unsigned int axi_bresp_error : 1;
        unsigned int vendor_specific_error_status : 2;
    } reg;
} SOC_SDEMMC_INTERRUPT_ERROR_STATUS_UNION;
#endif
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_command_complete_START (0)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_command_complete_END (0)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_transfer_complete_START (1)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_transfer_complete_END (1)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_block_gap_event_START (2)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_block_gap_event_END (2)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_dma_interrupt_START (3)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_dma_interrupt_END (3)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_buffer_write_ready_START (4)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_buffer_write_ready_END (4)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_buffer_read_ready_START (5)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_buffer_read_ready_END (5)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_card_insertion_START (6)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_card_insertion_END (6)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_card_removal_START (7)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_card_removal_END (7)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_card_interrupt_START (8)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_card_interrupt_END (8)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_int_a_START (9)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_int_a_END (9)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_int_b_START (10)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_int_b_END (10)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_int_c_START (11)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_int_c_END (11)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_retuning_event_START (12)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_retuning_event_END (12)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_dma_link_interrupt_START (13)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_dma_link_interrupt_END (13)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_error_interrupt_START (15)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_error_interrupt_END (15)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_command_timeout_error_START (16)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_command_timeout_error_END (16)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_command_crc_error_START (17)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_command_crc_error_END (17)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_command_end_bit_error_START (18)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_command_end_bit_error_END (18)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_command_index_error_START (19)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_command_index_error_END (19)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_data_timeout_error_START (20)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_data_timeout_error_END (20)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_data_crc_error_START (21)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_data_crc_error_END (21)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_data_end_bit_error_START (22)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_data_end_bit_error_END (22)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_current_limit_error_START (23)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_current_limit_error_END (23)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_auto_cmd12_error_START (24)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_auto_cmd12_error_END (24)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_adma_error_START (25)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_adma_error_END (25)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_tuning_error_START (26)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_tuning_error_END (26)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_axi_rresp_error_START (28)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_axi_rresp_error_END (28)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_axi_bresp_error_START (29)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_axi_bresp_error_END (29)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_vendor_specific_error_status_START (30)
#define SOC_SDEMMC_INTERRUPT_ERROR_STATUS_vendor_specific_error_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int command_complete_enable : 1;
        unsigned int transfer_complete_enable : 1;
        unsigned int block_gap_event_enable : 1;
        unsigned int dma_interrupt_enable : 1;
        unsigned int buffer_write_ready_enable : 1;
        unsigned int buffer_read_ready_enable : 1;
        unsigned int card_insertion_enable : 1;
        unsigned int card_removal_enable : 1;
        unsigned int card_interrupt_enable : 1;
        unsigned int int_a_enable : 1;
        unsigned int int_b_enable : 1;
        unsigned int int_c_enable : 1;
        unsigned int retuning_event_enable : 1;
        unsigned int dma_link_int_enable : 1;
        unsigned int reserved_0 : 1;
        unsigned int error_interrupt_enable : 1;
        unsigned int command_timeout_error_enable : 1;
        unsigned int command_crc_error_enable : 1;
        unsigned int command_end_bit_error_enable : 1;
        unsigned int command_index_error_enable : 1;
        unsigned int data_timeout_error_enable : 1;
        unsigned int data_crc_error_enable : 1;
        unsigned int data_end_bit_error_enable : 1;
        unsigned int current_limit_error_enable : 1;
        unsigned int auto_cmd12_error_enable : 1;
        unsigned int adma_error_enable : 1;
        unsigned int tuning_error_enable : 1;
        unsigned int reserved_1 : 1;
        unsigned int axi_rresp_error_enable : 1;
        unsigned int axi_bresp_error_enable : 1;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_UNION;
#endif
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_command_complete_enable_START (0)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_command_complete_enable_END (0)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_transfer_complete_enable_START (1)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_transfer_complete_enable_END (1)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_block_gap_event_enable_START (2)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_block_gap_event_enable_END (2)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_dma_interrupt_enable_START (3)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_dma_interrupt_enable_END (3)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_buffer_write_ready_enable_START (4)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_buffer_write_ready_enable_END (4)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_buffer_read_ready_enable_START (5)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_buffer_read_ready_enable_END (5)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_card_insertion_enable_START (6)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_card_insertion_enable_END (6)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_card_removal_enable_START (7)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_card_removal_enable_END (7)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_card_interrupt_enable_START (8)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_card_interrupt_enable_END (8)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_int_a_enable_START (9)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_int_a_enable_END (9)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_int_b_enable_START (10)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_int_b_enable_END (10)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_int_c_enable_START (11)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_int_c_enable_END (11)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_retuning_event_enable_START (12)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_retuning_event_enable_END (12)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_dma_link_int_enable_START (13)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_dma_link_int_enable_END (13)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_error_interrupt_enable_START (15)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_error_interrupt_enable_END (15)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_command_timeout_error_enable_START (16)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_command_timeout_error_enable_END (16)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_command_crc_error_enable_START (17)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_command_crc_error_enable_END (17)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_command_end_bit_error_enable_START (18)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_command_end_bit_error_enable_END (18)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_command_index_error_enable_START (19)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_command_index_error_enable_END (19)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_data_timeout_error_enable_START (20)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_data_timeout_error_enable_END (20)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_data_crc_error_enable_START (21)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_data_crc_error_enable_END (21)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_data_end_bit_error_enable_START (22)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_data_end_bit_error_enable_END (22)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_current_limit_error_enable_START (23)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_current_limit_error_enable_END (23)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_auto_cmd12_error_enable_START (24)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_auto_cmd12_error_enable_END (24)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_adma_error_enable_START (25)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_adma_error_enable_END (25)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_tuning_error_enable_START (26)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_tuning_error_enable_END (26)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_axi_rresp_error_enable_START (28)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_axi_rresp_error_enable_END (28)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_axi_bresp_error_enable_START (29)
#define SOC_SDEMMC_INTERRUPT_STATUS_ENABLE_axi_bresp_error_enable_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int command_complete_signal_enable : 1;
        unsigned int transfer_complete_signal_enable : 1;
        unsigned int block_gap_event_signal_enable : 1;
        unsigned int dma_interrupt_signal_enable : 1;
        unsigned int buffer_write_ready_signal_enable : 1;
        unsigned int buffer_read_ready_signal_enable : 1;
        unsigned int card_insertion_signal_enable : 1;
        unsigned int card_removal_signal_enable : 1;
        unsigned int card_interrupt_signal_enable : 1;
        unsigned int int_a_signal_enable : 1;
        unsigned int int_b_signal_enable : 1;
        unsigned int int_c_signal_enable : 1;
        unsigned int retuning_eventsignal_enable : 1;
        unsigned int dma_link_int_signal_enable : 1;
        unsigned int reserved_0 : 1;
        unsigned int error_interrupt_signal_enable : 1;
        unsigned int command_timeout_error_signal_enable : 1;
        unsigned int command_crc_error_signal_enable : 1;
        unsigned int command_end_bit_error_signal_enable : 1;
        unsigned int command_index_error_signal_enable : 1;
        unsigned int data_timeout_error_signal_enable : 1;
        unsigned int data_crc_error_signal_enable : 1;
        unsigned int data_end_bit_error_signal_enable : 1;
        unsigned int current_limit_error_signal_enable : 1;
        unsigned int auto_cmd12_error_signal_enable : 1;
        unsigned int adma_error_signal_enable : 1;
        unsigned int tuning_error_signal_enable : 1;
        unsigned int reserved_1 : 1;
        unsigned int axi_rresp_error_signal_enable : 1;
        unsigned int axi_bresp_error_signal_enable : 1;
        unsigned int vendor_specific_error_signal_enable : 2;
    } reg;
} SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_UNION;
#endif
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_command_complete_signal_enable_START (0)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_command_complete_signal_enable_END (0)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_transfer_complete_signal_enable_START (1)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_transfer_complete_signal_enable_END (1)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_block_gap_event_signal_enable_START (2)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_block_gap_event_signal_enable_END (2)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_dma_interrupt_signal_enable_START (3)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_dma_interrupt_signal_enable_END (3)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_buffer_write_ready_signal_enable_START (4)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_buffer_write_ready_signal_enable_END (4)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_buffer_read_ready_signal_enable_START (5)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_buffer_read_ready_signal_enable_END (5)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_card_insertion_signal_enable_START (6)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_card_insertion_signal_enable_END (6)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_card_removal_signal_enable_START (7)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_card_removal_signal_enable_END (7)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_card_interrupt_signal_enable_START (8)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_card_interrupt_signal_enable_END (8)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_int_a_signal_enable_START (9)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_int_a_signal_enable_END (9)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_int_b_signal_enable_START (10)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_int_b_signal_enable_END (10)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_int_c_signal_enable_START (11)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_int_c_signal_enable_END (11)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_retuning_eventsignal_enable_START (12)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_retuning_eventsignal_enable_END (12)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_dma_link_int_signal_enable_START (13)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_dma_link_int_signal_enable_END (13)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_error_interrupt_signal_enable_START (15)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_error_interrupt_signal_enable_END (15)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_command_timeout_error_signal_enable_START (16)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_command_timeout_error_signal_enable_END (16)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_command_crc_error_signal_enable_START (17)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_command_crc_error_signal_enable_END (17)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_command_end_bit_error_signal_enable_START (18)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_command_end_bit_error_signal_enable_END (18)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_command_index_error_signal_enable_START (19)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_command_index_error_signal_enable_END (19)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_data_timeout_error_signal_enable_START (20)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_data_timeout_error_signal_enable_END (20)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_data_crc_error_signal_enable_START (21)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_data_crc_error_signal_enable_END (21)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_data_end_bit_error_signal_enable_START (22)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_data_end_bit_error_signal_enable_END (22)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_current_limit_error_signal_enable_START (23)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_current_limit_error_signal_enable_END (23)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_auto_cmd12_error_signal_enable_START (24)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_auto_cmd12_error_signal_enable_END (24)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_adma_error_signal_enable_START (25)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_adma_error_signal_enable_END (25)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_tuning_error_signal_enable_START (26)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_tuning_error_signal_enable_END (26)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_axi_rresp_error_signal_enable_START (28)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_axi_rresp_error_signal_enable_END (28)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_axi_bresp_error_signal_enable_START (29)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_axi_bresp_error_signal_enable_END (29)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_vendor_specific_error_signal_enable_START (30)
#define SOC_SDEMMC_INTERRUPT_SIGNAL_ENABLE_vendor_specific_error_signal_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int auto_cmd12_not_executed : 1;
        unsigned int auto_cmd_timeout_error : 1;
        unsigned int auto_cmd_crc_error : 1;
        unsigned int auto_cmd_end_bit_error : 1;
        unsigned int auto_cmd_index_error : 1;
        unsigned int reserved_0 : 2;
        unsigned int command_not_issued_by_auto_cmd12_error : 1;
        unsigned int reserved_1 : 8;
        unsigned int uhs_mode_select : 3;
        unsigned int signaling_1p8v_enable : 1;
        unsigned int driver_strength_select : 2;
        unsigned int execute_tuning : 1;
        unsigned int sampling_clock_select : 1;
        unsigned int reserved_2 : 6;
        unsigned int asynchronous_interrupt_enable : 1;
        unsigned int preset_value_enable : 1;
    } reg;
} SOC_SDEMMC_HOST_CONTROL2_AUTO_CMD_ERROR_STATUS_UNION;
#endif
#define SOC_SDEMMC_HOST_CONTROL2_AUTO_CMD_ERROR_STATUS_auto_cmd12_not_executed_START (0)
#define SOC_SDEMMC_HOST_CONTROL2_AUTO_CMD_ERROR_STATUS_auto_cmd12_not_executed_END (0)
#define SOC_SDEMMC_HOST_CONTROL2_AUTO_CMD_ERROR_STATUS_auto_cmd_timeout_error_START (1)
#define SOC_SDEMMC_HOST_CONTROL2_AUTO_CMD_ERROR_STATUS_auto_cmd_timeout_error_END (1)
#define SOC_SDEMMC_HOST_CONTROL2_AUTO_CMD_ERROR_STATUS_auto_cmd_crc_error_START (2)
#define SOC_SDEMMC_HOST_CONTROL2_AUTO_CMD_ERROR_STATUS_auto_cmd_crc_error_END (2)
#define SOC_SDEMMC_HOST_CONTROL2_AUTO_CMD_ERROR_STATUS_auto_cmd_end_bit_error_START (3)
#define SOC_SDEMMC_HOST_CONTROL2_AUTO_CMD_ERROR_STATUS_auto_cmd_end_bit_error_END (3)
#define SOC_SDEMMC_HOST_CONTROL2_AUTO_CMD_ERROR_STATUS_auto_cmd_index_error_START (4)
#define SOC_SDEMMC_HOST_CONTROL2_AUTO_CMD_ERROR_STATUS_auto_cmd_index_error_END (4)
#define SOC_SDEMMC_HOST_CONTROL2_AUTO_CMD_ERROR_STATUS_command_not_issued_by_auto_cmd12_error_START (7)
#define SOC_SDEMMC_HOST_CONTROL2_AUTO_CMD_ERROR_STATUS_command_not_issued_by_auto_cmd12_error_END (7)
#define SOC_SDEMMC_HOST_CONTROL2_AUTO_CMD_ERROR_STATUS_uhs_mode_select_START (16)
#define SOC_SDEMMC_HOST_CONTROL2_AUTO_CMD_ERROR_STATUS_uhs_mode_select_END (18)
#define SOC_SDEMMC_HOST_CONTROL2_AUTO_CMD_ERROR_STATUS_signaling_1p8v_enable_START (19)
#define SOC_SDEMMC_HOST_CONTROL2_AUTO_CMD_ERROR_STATUS_signaling_1p8v_enable_END (19)
#define SOC_SDEMMC_HOST_CONTROL2_AUTO_CMD_ERROR_STATUS_driver_strength_select_START (20)
#define SOC_SDEMMC_HOST_CONTROL2_AUTO_CMD_ERROR_STATUS_driver_strength_select_END (21)
#define SOC_SDEMMC_HOST_CONTROL2_AUTO_CMD_ERROR_STATUS_execute_tuning_START (22)
#define SOC_SDEMMC_HOST_CONTROL2_AUTO_CMD_ERROR_STATUS_execute_tuning_END (22)
#define SOC_SDEMMC_HOST_CONTROL2_AUTO_CMD_ERROR_STATUS_sampling_clock_select_START (23)
#define SOC_SDEMMC_HOST_CONTROL2_AUTO_CMD_ERROR_STATUS_sampling_clock_select_END (23)
#define SOC_SDEMMC_HOST_CONTROL2_AUTO_CMD_ERROR_STATUS_asynchronous_interrupt_enable_START (30)
#define SOC_SDEMMC_HOST_CONTROL2_AUTO_CMD_ERROR_STATUS_asynchronous_interrupt_enable_END (30)
#define SOC_SDEMMC_HOST_CONTROL2_AUTO_CMD_ERROR_STATUS_preset_value_enable_START (31)
#define SOC_SDEMMC_HOST_CONTROL2_AUTO_CMD_ERROR_STATUS_preset_value_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int timeout_clock_frequency : 6;
        unsigned int reserved_0 : 1;
        unsigned int timeout_clock_unit : 1;
        unsigned int base_clock_frequency_for_sd_clock : 8;
        unsigned int max_block_length : 2;
        unsigned int support_8b_for_embedded : 1;
        unsigned int adma2_support : 1;
        unsigned int reserved_1 : 1;
        unsigned int high_speed_support : 1;
        unsigned int sdma_support : 1;
        unsigned int suspend_resume_support : 1;
        unsigned int voltage_support_3p3v : 1;
        unsigned int voltage_support_3p0v : 1;
        unsigned int voltage_support_1p8v : 1;
        unsigned int reserved_2 : 1;
        unsigned int system_64b_bus_support : 1;
        unsigned int asyn_interrupt_support : 1;
        unsigned int slot_type : 2;
    } reg;
} SOC_SDEMMC_CAPABILITIES0_UNION;
#endif
#define SOC_SDEMMC_CAPABILITIES0_timeout_clock_frequency_START (0)
#define SOC_SDEMMC_CAPABILITIES0_timeout_clock_frequency_END (5)
#define SOC_SDEMMC_CAPABILITIES0_timeout_clock_unit_START (7)
#define SOC_SDEMMC_CAPABILITIES0_timeout_clock_unit_END (7)
#define SOC_SDEMMC_CAPABILITIES0_base_clock_frequency_for_sd_clock_START (8)
#define SOC_SDEMMC_CAPABILITIES0_base_clock_frequency_for_sd_clock_END (15)
#define SOC_SDEMMC_CAPABILITIES0_max_block_length_START (16)
#define SOC_SDEMMC_CAPABILITIES0_max_block_length_END (17)
#define SOC_SDEMMC_CAPABILITIES0_support_8b_for_embedded_START (18)
#define SOC_SDEMMC_CAPABILITIES0_support_8b_for_embedded_END (18)
#define SOC_SDEMMC_CAPABILITIES0_adma2_support_START (19)
#define SOC_SDEMMC_CAPABILITIES0_adma2_support_END (19)
#define SOC_SDEMMC_CAPABILITIES0_high_speed_support_START (21)
#define SOC_SDEMMC_CAPABILITIES0_high_speed_support_END (21)
#define SOC_SDEMMC_CAPABILITIES0_sdma_support_START (22)
#define SOC_SDEMMC_CAPABILITIES0_sdma_support_END (22)
#define SOC_SDEMMC_CAPABILITIES0_suspend_resume_support_START (23)
#define SOC_SDEMMC_CAPABILITIES0_suspend_resume_support_END (23)
#define SOC_SDEMMC_CAPABILITIES0_voltage_support_3p3v_START (24)
#define SOC_SDEMMC_CAPABILITIES0_voltage_support_3p3v_END (24)
#define SOC_SDEMMC_CAPABILITIES0_voltage_support_3p0v_START (25)
#define SOC_SDEMMC_CAPABILITIES0_voltage_support_3p0v_END (25)
#define SOC_SDEMMC_CAPABILITIES0_voltage_support_1p8v_START (26)
#define SOC_SDEMMC_CAPABILITIES0_voltage_support_1p8v_END (26)
#define SOC_SDEMMC_CAPABILITIES0_system_64b_bus_support_START (28)
#define SOC_SDEMMC_CAPABILITIES0_system_64b_bus_support_END (28)
#define SOC_SDEMMC_CAPABILITIES0_asyn_interrupt_support_START (29)
#define SOC_SDEMMC_CAPABILITIES0_asyn_interrupt_support_END (29)
#define SOC_SDEMMC_CAPABILITIES0_slot_type_START (30)
#define SOC_SDEMMC_CAPABILITIES0_slot_type_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sdr50_support : 1;
        unsigned int sdr104_support : 1;
        unsigned int ddr50_support : 1;
        unsigned int reserved_0 : 1;
        unsigned int driver_type_a_support : 1;
        unsigned int driver_type_c_support : 1;
        unsigned int driver_type_d_support : 1;
        unsigned int reserved_1 : 1;
        unsigned int retuning_timer_count : 4;
        unsigned int reserved_2 : 1;
        unsigned int tuning_sdr50 : 1;
        unsigned int retuning_modes : 2;
        unsigned int clock_multiplier : 8;
        unsigned int reserved_3 : 8;
    } reg;
} SOC_SDEMMC_CAPABILITIES1_UNION;
#endif
#define SOC_SDEMMC_CAPABILITIES1_sdr50_support_START (0)
#define SOC_SDEMMC_CAPABILITIES1_sdr50_support_END (0)
#define SOC_SDEMMC_CAPABILITIES1_sdr104_support_START (1)
#define SOC_SDEMMC_CAPABILITIES1_sdr104_support_END (1)
#define SOC_SDEMMC_CAPABILITIES1_ddr50_support_START (2)
#define SOC_SDEMMC_CAPABILITIES1_ddr50_support_END (2)
#define SOC_SDEMMC_CAPABILITIES1_driver_type_a_support_START (4)
#define SOC_SDEMMC_CAPABILITIES1_driver_type_a_support_END (4)
#define SOC_SDEMMC_CAPABILITIES1_driver_type_c_support_START (5)
#define SOC_SDEMMC_CAPABILITIES1_driver_type_c_support_END (5)
#define SOC_SDEMMC_CAPABILITIES1_driver_type_d_support_START (6)
#define SOC_SDEMMC_CAPABILITIES1_driver_type_d_support_END (6)
#define SOC_SDEMMC_CAPABILITIES1_retuning_timer_count_START (8)
#define SOC_SDEMMC_CAPABILITIES1_retuning_timer_count_END (11)
#define SOC_SDEMMC_CAPABILITIES1_tuning_sdr50_START (13)
#define SOC_SDEMMC_CAPABILITIES1_tuning_sdr50_END (13)
#define SOC_SDEMMC_CAPABILITIES1_retuning_modes_START (14)
#define SOC_SDEMMC_CAPABILITIES1_retuning_modes_END (15)
#define SOC_SDEMMC_CAPABILITIES1_clock_multiplier_START (16)
#define SOC_SDEMMC_CAPABILITIES1_clock_multiplier_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int maximum_current : 32;
    } reg;
} SOC_SDEMMC_CURRENT_CAPABILITIES0_UNION;
#endif
#define SOC_SDEMMC_CURRENT_CAPABILITIES0_maximum_current_START (0)
#define SOC_SDEMMC_CURRENT_CAPABILITIES0_maximum_current_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_SDEMMC_CURRENT_CAPABILITIES1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int force_event : 32;
    } reg;
} SOC_SDEMMC_FORCE_EVENT_UNION;
#endif
#define SOC_SDEMMC_FORCE_EVENT_force_event_START (0)
#define SOC_SDEMMC_FORCE_EVENT_force_event_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adma_error_state : 2;
        unsigned int adma_length_mismatch_error : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_SDEMMC_ADMA_ERROR_STATUS_UNION;
#endif
#define SOC_SDEMMC_ADMA_ERROR_STATUS_adma_error_state_START (0)
#define SOC_SDEMMC_ADMA_ERROR_STATUS_adma_error_state_END (1)
#define SOC_SDEMMC_ADMA_ERROR_STATUS_adma_length_mismatch_error_START (2)
#define SOC_SDEMMC_ADMA_ERROR_STATUS_adma_length_mismatch_error_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adma_system_address_lower : 32;
    } reg;
} SOC_SDEMMC_ADMA_SYSTEM_ADDRESS_LOWER_UNION;
#endif
#define SOC_SDEMMC_ADMA_SYSTEM_ADDRESS_LOWER_adma_system_address_lower_START (0)
#define SOC_SDEMMC_ADMA_SYSTEM_ADDRESS_LOWER_adma_system_address_lower_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adma_system_address1_upper : 32;
    } reg;
} SOC_SDEMMC_ADMA_SYSTEM_ADDRESS1_UPPER_UNION;
#endif
#define SOC_SDEMMC_ADMA_SYSTEM_ADDRESS1_UPPER_adma_system_address1_upper_START (0)
#define SOC_SDEMMC_ADMA_SYSTEM_ADDRESS1_UPPER_adma_system_address1_upper_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int preset_value0 : 32;
    } reg;
} SOC_SDEMMC_PRESET_VALUE0_UNION;
#endif
#define SOC_SDEMMC_PRESET_VALUE0_preset_value0_START (00)
#define SOC_SDEMMC_PRESET_VALUE0_preset_value0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int preset_value1 : 32;
    } reg;
} SOC_SDEMMC_PRESET_VALUE1_UNION;
#endif
#define SOC_SDEMMC_PRESET_VALUE1_preset_value1_START (00)
#define SOC_SDEMMC_PRESET_VALUE1_preset_value1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int preset_value2 : 32;
    } reg;
} SOC_SDEMMC_PRESET_VALUE2_UNION;
#endif
#define SOC_SDEMMC_PRESET_VALUE2_preset_value2_START (00)
#define SOC_SDEMMC_PRESET_VALUE2_preset_value2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int preset_value3 : 32;
    } reg;
} SOC_SDEMMC_PRESET_VALUE3_UNION;
#endif
#define SOC_SDEMMC_PRESET_VALUE3_preset_value3_START (00)
#define SOC_SDEMMC_PRESET_VALUE3_preset_value3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 8;
        unsigned int sdemmc_clk_dly_sample : 5;
        unsigned int reserved_1 : 3;
        unsigned int sdemmc_clk_dly_drv : 5;
        unsigned int reserved_2 : 3;
        unsigned int sdemmc_clk_div : 4;
        unsigned int reserved_3 : 3;
        unsigned int sdemmc_samp_sel : 1;
    } reg;
} SOC_SDEMMC_CRG_CTRL_0_UNION;
#endif
#define SOC_SDEMMC_CRG_CTRL_0_sdemmc_clk_dly_sample_START (8)
#define SOC_SDEMMC_CRG_CTRL_0_sdemmc_clk_dly_sample_END (12)
#define SOC_SDEMMC_CRG_CTRL_0_sdemmc_clk_dly_drv_START (16)
#define SOC_SDEMMC_CRG_CTRL_0_sdemmc_clk_dly_drv_END (20)
#define SOC_SDEMMC_CRG_CTRL_0_sdemmc_clk_div_START (24)
#define SOC_SDEMMC_CRG_CTRL_0_sdemmc_clk_div_END (27)
#define SOC_SDEMMC_CRG_CTRL_0_sdemmc_samp_sel_START (31)
#define SOC_SDEMMC_CRG_CTRL_0_sdemmc_samp_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sdemmc_clk_dw_sel : 1;
        unsigned int sdemmc_clk_dw_cfg : 1;
        unsigned int sdemmc_buf_wr_rdy_bus : 1;
        unsigned int sdemmc_buf_wr_rdy_sd : 1;
        unsigned int sdemmc_buf_rd_rdy_bus : 1;
        unsigned int sdemmc_buf_rd_rdy_sd : 1;
        unsigned int reserved_0 : 2;
        unsigned int icfg_ckg_byp_ckg_buf : 1;
        unsigned int icfg_ckg_byp_ckg_datapath : 1;
        unsigned int icfg_ckg_byp_ckg_cmdpath : 1;
        unsigned int icfg_ckg_byp_ckg_samp_datapath : 1;
        unsigned int icfg_ckg_byp_ckg_samp_cmdpath : 1;
        unsigned int icfg_ckg_byp_ckg_dma : 1;
        unsigned int icfg_ckg_byp_ckg_buf_bus : 1;
        unsigned int icfg_ckg_byp_ckg_apb : 1;
        unsigned int reserved_1 : 4;
        unsigned int ckg_busy_buf_wr : 1;
        unsigned int ckg_busy_buf_rd : 1;
        unsigned int ckg_busy_datapath : 1;
        unsigned int ckg_busy_cmdpath : 1;
        unsigned int ckg_busy_samp_datapath : 1;
        unsigned int ckg_busy_samp_cmdpath : 1;
        unsigned int ckg_busy_dma : 1;
        unsigned int ckg_busy_buf_bus : 1;
        unsigned int ckg_busy_apb : 1;
        unsigned int reserved_2 : 1;
        unsigned int clock_enable : 1;
        unsigned int sw_done : 1;
    } reg;
} SOC_SDEMMC_CRG_CTRL_1_UNION;
#endif
#define SOC_SDEMMC_CRG_CTRL_1_sdemmc_clk_dw_sel_START (0)
#define SOC_SDEMMC_CRG_CTRL_1_sdemmc_clk_dw_sel_END (0)
#define SOC_SDEMMC_CRG_CTRL_1_sdemmc_clk_dw_cfg_START (1)
#define SOC_SDEMMC_CRG_CTRL_1_sdemmc_clk_dw_cfg_END (1)
#define SOC_SDEMMC_CRG_CTRL_1_sdemmc_buf_wr_rdy_bus_START (2)
#define SOC_SDEMMC_CRG_CTRL_1_sdemmc_buf_wr_rdy_bus_END (2)
#define SOC_SDEMMC_CRG_CTRL_1_sdemmc_buf_wr_rdy_sd_START (3)
#define SOC_SDEMMC_CRG_CTRL_1_sdemmc_buf_wr_rdy_sd_END (3)
#define SOC_SDEMMC_CRG_CTRL_1_sdemmc_buf_rd_rdy_bus_START (4)
#define SOC_SDEMMC_CRG_CTRL_1_sdemmc_buf_rd_rdy_bus_END (4)
#define SOC_SDEMMC_CRG_CTRL_1_sdemmc_buf_rd_rdy_sd_START (5)
#define SOC_SDEMMC_CRG_CTRL_1_sdemmc_buf_rd_rdy_sd_END (5)
#define SOC_SDEMMC_CRG_CTRL_1_icfg_ckg_byp_ckg_buf_START (8)
#define SOC_SDEMMC_CRG_CTRL_1_icfg_ckg_byp_ckg_buf_END (8)
#define SOC_SDEMMC_CRG_CTRL_1_icfg_ckg_byp_ckg_datapath_START (9)
#define SOC_SDEMMC_CRG_CTRL_1_icfg_ckg_byp_ckg_datapath_END (9)
#define SOC_SDEMMC_CRG_CTRL_1_icfg_ckg_byp_ckg_cmdpath_START (10)
#define SOC_SDEMMC_CRG_CTRL_1_icfg_ckg_byp_ckg_cmdpath_END (10)
#define SOC_SDEMMC_CRG_CTRL_1_icfg_ckg_byp_ckg_samp_datapath_START (11)
#define SOC_SDEMMC_CRG_CTRL_1_icfg_ckg_byp_ckg_samp_datapath_END (11)
#define SOC_SDEMMC_CRG_CTRL_1_icfg_ckg_byp_ckg_samp_cmdpath_START (12)
#define SOC_SDEMMC_CRG_CTRL_1_icfg_ckg_byp_ckg_samp_cmdpath_END (12)
#define SOC_SDEMMC_CRG_CTRL_1_icfg_ckg_byp_ckg_dma_START (13)
#define SOC_SDEMMC_CRG_CTRL_1_icfg_ckg_byp_ckg_dma_END (13)
#define SOC_SDEMMC_CRG_CTRL_1_icfg_ckg_byp_ckg_buf_bus_START (14)
#define SOC_SDEMMC_CRG_CTRL_1_icfg_ckg_byp_ckg_buf_bus_END (14)
#define SOC_SDEMMC_CRG_CTRL_1_icfg_ckg_byp_ckg_apb_START (15)
#define SOC_SDEMMC_CRG_CTRL_1_icfg_ckg_byp_ckg_apb_END (15)
#define SOC_SDEMMC_CRG_CTRL_1_ckg_busy_buf_wr_START (20)
#define SOC_SDEMMC_CRG_CTRL_1_ckg_busy_buf_wr_END (20)
#define SOC_SDEMMC_CRG_CTRL_1_ckg_busy_buf_rd_START (21)
#define SOC_SDEMMC_CRG_CTRL_1_ckg_busy_buf_rd_END (21)
#define SOC_SDEMMC_CRG_CTRL_1_ckg_busy_datapath_START (22)
#define SOC_SDEMMC_CRG_CTRL_1_ckg_busy_datapath_END (22)
#define SOC_SDEMMC_CRG_CTRL_1_ckg_busy_cmdpath_START (23)
#define SOC_SDEMMC_CRG_CTRL_1_ckg_busy_cmdpath_END (23)
#define SOC_SDEMMC_CRG_CTRL_1_ckg_busy_samp_datapath_START (24)
#define SOC_SDEMMC_CRG_CTRL_1_ckg_busy_samp_datapath_END (24)
#define SOC_SDEMMC_CRG_CTRL_1_ckg_busy_samp_cmdpath_START (25)
#define SOC_SDEMMC_CRG_CTRL_1_ckg_busy_samp_cmdpath_END (25)
#define SOC_SDEMMC_CRG_CTRL_1_ckg_busy_dma_START (26)
#define SOC_SDEMMC_CRG_CTRL_1_ckg_busy_dma_END (26)
#define SOC_SDEMMC_CRG_CTRL_1_ckg_busy_buf_bus_START (27)
#define SOC_SDEMMC_CRG_CTRL_1_ckg_busy_buf_bus_END (27)
#define SOC_SDEMMC_CRG_CTRL_1_ckg_busy_apb_START (28)
#define SOC_SDEMMC_CRG_CTRL_1_ckg_busy_apb_END (28)
#define SOC_SDEMMC_CRG_CTRL_1_clock_enable_START (30)
#define SOC_SDEMMC_CRG_CTRL_1_clock_enable_END (30)
#define SOC_SDEMMC_CRG_CTRL_1_sw_done_START (31)
#define SOC_SDEMMC_CRG_CTRL_1_sw_done_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tuning_result_value : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_SDEMMC_TUNING_RESULT_VALUE_UNION;
#endif
#define SOC_SDEMMC_TUNING_RESULT_VALUE_tuning_result_value_START (0)
#define SOC_SDEMMC_TUNING_RESULT_VALUE_tuning_result_value_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_cmd_timeout_cnt : 8;
        unsigned int cfg_cmd_resp_cnt : 8;
        unsigned int cfg_write_auto_cmd12_start : 5;
        unsigned int cfg_read_wait_start : 3;
        unsigned int cfg_read_auto_cmd12_start : 6;
        unsigned int cfg_read_wait_mode : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_SDEMMC_TIMING_CTRL_0_UNION;
#endif
#define SOC_SDEMMC_TIMING_CTRL_0_cfg_cmd_timeout_cnt_START (0)
#define SOC_SDEMMC_TIMING_CTRL_0_cfg_cmd_timeout_cnt_END (7)
#define SOC_SDEMMC_TIMING_CTRL_0_cfg_cmd_resp_cnt_START (8)
#define SOC_SDEMMC_TIMING_CTRL_0_cfg_cmd_resp_cnt_END (15)
#define SOC_SDEMMC_TIMING_CTRL_0_cfg_write_auto_cmd12_start_START (16)
#define SOC_SDEMMC_TIMING_CTRL_0_cfg_write_auto_cmd12_start_END (20)
#define SOC_SDEMMC_TIMING_CTRL_0_cfg_read_wait_start_START (21)
#define SOC_SDEMMC_TIMING_CTRL_0_cfg_read_wait_start_END (23)
#define SOC_SDEMMC_TIMING_CTRL_0_cfg_read_auto_cmd12_start_START (24)
#define SOC_SDEMMC_TIMING_CTRL_0_cfg_read_auto_cmd12_start_END (29)
#define SOC_SDEMMC_TIMING_CTRL_0_cfg_read_wait_mode_START (30)
#define SOC_SDEMMC_TIMING_CTRL_0_cfg_read_wait_mode_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int crc_st_chk_dly : 8;
        unsigned int crc_st_det_dly : 7;
        unsigned int crc_st_det_dly_mode : 1;
        unsigned int nsb_cfg : 8;
        unsigned int cfg_sdio_int_dly : 8;
    } reg;
} SOC_SDEMMC_TIMING_CTRL_1_UNION;
#endif
#define SOC_SDEMMC_TIMING_CTRL_1_crc_st_chk_dly_START (0)
#define SOC_SDEMMC_TIMING_CTRL_1_crc_st_chk_dly_END (7)
#define SOC_SDEMMC_TIMING_CTRL_1_crc_st_det_dly_START (8)
#define SOC_SDEMMC_TIMING_CTRL_1_crc_st_det_dly_END (14)
#define SOC_SDEMMC_TIMING_CTRL_1_crc_st_det_dly_mode_START (15)
#define SOC_SDEMMC_TIMING_CTRL_1_crc_st_det_dly_mode_END (15)
#define SOC_SDEMMC_TIMING_CTRL_1_nsb_cfg_START (16)
#define SOC_SDEMMC_TIMING_CTRL_1_nsb_cfg_END (23)
#define SOC_SDEMMC_TIMING_CTRL_1_cfg_sdio_int_dly_START (24)
#define SOC_SDEMMC_TIMING_CTRL_1_cfg_sdio_int_dly_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_stop_sdclk_rd_mode : 1;
        unsigned int cfg_stop_sdclk_rd_start : 4;
        unsigned int reserved_0 : 3;
        unsigned int cfg_wr_blk_start : 3;
        unsigned int reserved_1 : 5;
        unsigned int cfg_data_timeout_step : 3;
        unsigned int reserved_2 : 9;
        unsigned int cfg_crc_status_bypass : 1;
        unsigned int reserved_3 : 2;
        unsigned int cfg_cmd_wo_dat_th : 1;
    } reg;
} SOC_SDEMMC_TIMING_CTRL_2_UNION;
#endif
#define SOC_SDEMMC_TIMING_CTRL_2_cfg_stop_sdclk_rd_mode_START (0)
#define SOC_SDEMMC_TIMING_CTRL_2_cfg_stop_sdclk_rd_mode_END (0)
#define SOC_SDEMMC_TIMING_CTRL_2_cfg_stop_sdclk_rd_start_START (1)
#define SOC_SDEMMC_TIMING_CTRL_2_cfg_stop_sdclk_rd_start_END (4)
#define SOC_SDEMMC_TIMING_CTRL_2_cfg_wr_blk_start_START (8)
#define SOC_SDEMMC_TIMING_CTRL_2_cfg_wr_blk_start_END (10)
#define SOC_SDEMMC_TIMING_CTRL_2_cfg_data_timeout_step_START (16)
#define SOC_SDEMMC_TIMING_CTRL_2_cfg_data_timeout_step_END (18)
#define SOC_SDEMMC_TIMING_CTRL_2_cfg_crc_status_bypass_START (28)
#define SOC_SDEMMC_TIMING_CTRL_2_cfg_crc_status_bypass_END (28)
#define SOC_SDEMMC_TIMING_CTRL_2_cfg_cmd_wo_dat_th_START (31)
#define SOC_SDEMMC_TIMING_CTRL_2_cfg_cmd_wo_dat_th_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ArDomain : 2;
        unsigned int ArCache : 4;
        unsigned int reserved_0: 2;
        unsigned int AwDomain : 2;
        unsigned int AwCache : 4;
        unsigned int reserved_1: 18;
    } reg;
} SOC_SDEMMC_AXI_PARA_UNION;
#endif
#define SOC_SDEMMC_AXI_PARA_ArDomain_START (0)
#define SOC_SDEMMC_AXI_PARA_ArDomain_END (1)
#define SOC_SDEMMC_AXI_PARA_ArCache_START (2)
#define SOC_SDEMMC_AXI_PARA_ArCache_END (5)
#define SOC_SDEMMC_AXI_PARA_AwDomain_START (8)
#define SOC_SDEMMC_AXI_PARA_AwDomain_END (9)
#define SOC_SDEMMC_AXI_PARA_AwCache_START (10)
#define SOC_SDEMMC_AXI_PARA_AwCache_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int shared_bus_control : 32;
    } reg;
} SOC_SDEMMC_SHARED_BUS_CONTROL_UNION;
#endif
#define SOC_SDEMMC_SHARED_BUS_CONTROL_shared_bus_control_START (00)
#define SOC_SDEMMC_SHARED_BUS_CONTROL_shared_bus_control_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int interrupt_signal_for_each_slot : 8;
        unsigned int reserved : 8;
        unsigned int spec_version : 8;
        unsigned int vendor_version : 8;
    } reg;
} SOC_SDEMMC_VERSION_SLOT_INTERRUPT_STATUS_UNION;
#endif
#define SOC_SDEMMC_VERSION_SLOT_INTERRUPT_STATUS_interrupt_signal_for_each_slot_START (0)
#define SOC_SDEMMC_VERSION_SLOT_INTERRUPT_STATUS_interrupt_signal_for_each_slot_END (7)
#define SOC_SDEMMC_VERSION_SLOT_INTERRUPT_STATUS_spec_version_START (16)
#define SOC_SDEMMC_VERSION_SLOT_INTERRUPT_STATUS_spec_version_END (23)
#define SOC_SDEMMC_VERSION_SLOT_INTERRUPT_STATUS_vendor_version_START (24)
#define SOC_SDEMMC_VERSION_SLOT_INTERRUPT_STATUS_vendor_version_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eco_rsv_rw : 32;
    } reg;
} SOC_SDEMMC_ECO_RSV_RW_UNION;
#endif
#define SOC_SDEMMC_ECO_RSV_RW_eco_rsv_rw_START (0)
#define SOC_SDEMMC_ECO_RSV_RW_eco_rsv_rw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eco_rsv_ro : 32;
    } reg;
} SOC_SDEMMC_ECO_RSV_RO_UNION;
#endif
#define SOC_SDEMMC_ECO_RSV_RO_eco_rsv_ro_START (0)
#define SOC_SDEMMC_ECO_RSV_RO_eco_rsv_ro_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buf_ctrl_stat : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_SDEMMC_DFX_BUF_CTRL_STAT_UNION;
#endif
#define SOC_SDEMMC_DFX_BUF_CTRL_STAT_buf_ctrl_stat_START (0)
#define SOC_SDEMMC_DFX_BUF_CTRL_STAT_buf_ctrl_stat_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buf_apbctrl : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_SDEMMC_DFX_BUF_APBCTRL_UNION;
#endif
#define SOC_SDEMMC_DFX_BUF_APBCTRL_buf_apbctrl_START (0)
#define SOC_SDEMMC_DFX_BUF_APBCTRL_buf_apbctrl_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int datapath_blk : 31;
        unsigned int reserved : 1;
    } reg;
} SOC_SDEMMC_DFX_DATAPATH_BLK_UNION;
#endif
#define SOC_SDEMMC_DFX_DATAPATH_BLK_datapath_blk_START (0)
#define SOC_SDEMMC_DFX_DATAPATH_BLK_datapath_blk_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int datapath_buf_ctrl : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_SDEMMC_DFX_DATAPATH_BUF_CTRL_UNION;
#endif
#define SOC_SDEMMC_DFX_DATAPATH_BUF_CTRL_datapath_buf_ctrl_START (0)
#define SOC_SDEMMC_DFX_DATAPATH_BUF_CTRL_datapath_buf_ctrl_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int datapath_p2s_s2p : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_SDEMMC_DFX_DATAPATH_P2S_S2P_UNION;
#endif
#define SOC_SDEMMC_DFX_DATAPATH_P2S_S2P_datapath_p2s_s2p_START (0)
#define SOC_SDEMMC_DFX_DATAPATH_P2S_S2P_datapath_p2s_s2p_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int datapath_ctrl : 32;
    } reg;
} SOC_SDEMMC_DFX_DATAPATH_CTRL_UNION;
#endif
#define SOC_SDEMMC_DFX_DATAPATH_CTRL_datapath_ctrl_START (0)
#define SOC_SDEMMC_DFX_DATAPATH_CTRL_datapath_ctrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int datapath_crc_status : 19;
        unsigned int reserved : 13;
    } reg;
} SOC_SDEMMC_DFX_DATAPATH_CRC_STATUS_UNION;
#endif
#define SOC_SDEMMC_DFX_DATAPATH_CRC_STATUS_datapath_crc_status_START (0)
#define SOC_SDEMMC_DFX_DATAPATH_CRC_STATUS_datapath_crc_status_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int datapath_boot_ctrl : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_SDEMMC_DFX_DATAPATH_BOOT_CTRL_UNION;
#endif
#define SOC_SDEMMC_DFX_DATAPATH_BOOT_CTRL_datapath_boot_ctrl_START (0)
#define SOC_SDEMMC_DFX_DATAPATH_BOOT_CTRL_datapath_boot_ctrl_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sdintf_dout : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_SDEMMC_DFX_SDINTF_DOUT_UNION;
#endif
#define SOC_SDEMMC_DFX_SDINTF_DOUT_sdintf_dout_START (0)
#define SOC_SDEMMC_DFX_SDINTF_DOUT_sdintf_dout_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sdintf_din : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_SDEMMC_DFX_SDINTF_DIN_UNION;
#endif
#define SOC_SDEMMC_DFX_SDINTF_DIN_sdintf_din_START (0)
#define SOC_SDEMMC_DFX_SDINTF_DIN_sdintf_din_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sdintf_afifo : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_SDEMMC_DFX_SDINTF_AFIFO_UNION;
#endif
#define SOC_SDEMMC_DFX_SDINTF_AFIFO_sdintf_afifo_START (0)
#define SOC_SDEMMC_DFX_SDINTF_AFIFO_sdintf_afifo_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int byte_cnt_sent : 32;
    } reg;
} SOC_SDEMMC_DFX_BYTE_CNT_SENT_UNION;
#endif
#define SOC_SDEMMC_DFX_BYTE_CNT_SENT_byte_cnt_sent_START (0)
#define SOC_SDEMMC_DFX_BYTE_CNT_SENT_byte_cnt_sent_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int byte_cnt_received : 32;
    } reg;
} SOC_SDEMMC_DFX_BYTE_CNT_RECEIVED_UNION;
#endif
#define SOC_SDEMMC_DFX_BYTE_CNT_RECEIVED_byte_cnt_received_START (0)
#define SOC_SDEMMC_DFX_BYTE_CNT_RECEIVED_byte_cnt_received_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int blk_cnt_received : 16;
        unsigned int blk_cnt_sent : 16;
    } reg;
} SOC_SDEMMC_DFX_BLK_TRANSFER_UNION;
#endif
#define SOC_SDEMMC_DFX_BLK_TRANSFER_blk_cnt_received_START (0)
#define SOC_SDEMMC_DFX_BLK_TRANSFER_blk_cnt_received_END (15)
#define SOC_SDEMMC_DFX_BLK_TRANSFER_blk_cnt_sent_START (16)
#define SOC_SDEMMC_DFX_BLK_TRANSFER_blk_cnt_sent_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int blk_cnt_received_try : 16;
        unsigned int blk_cnt_sent_try : 16;
    } reg;
} SOC_SDEMMC_DFX_BLK_TRY_UNION;
#endif
#define SOC_SDEMMC_DFX_BLK_TRY_blk_cnt_received_try_START (0)
#define SOC_SDEMMC_DFX_BLK_TRY_blk_cnt_received_try_END (15)
#define SOC_SDEMMC_DFX_BLK_TRY_blk_cnt_sent_try_START (16)
#define SOC_SDEMMC_DFX_BLK_TRY_blk_cnt_sent_try_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int RD_BLK_GAP_LAT_MIN : 4;
        unsigned int RD_BLK_GAP_LAT_MAX : 15;
        unsigned int reserved_0 : 5;
        unsigned int SD_CLK_STOP_TIMES : 6;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_SDEMMC_DFX_RD_BLK_GAP_LAT_UNION;
#endif
#define SOC_SDEMMC_DFX_RD_BLK_GAP_LAT_RD_BLK_GAP_LAT_MIN_START (0)
#define SOC_SDEMMC_DFX_RD_BLK_GAP_LAT_RD_BLK_GAP_LAT_MIN_END (3)
#define SOC_SDEMMC_DFX_RD_BLK_GAP_LAT_RD_BLK_GAP_LAT_MAX_START (4)
#define SOC_SDEMMC_DFX_RD_BLK_GAP_LAT_RD_BLK_GAP_LAT_MAX_END (18)
#define SOC_SDEMMC_DFX_RD_BLK_GAP_LAT_SD_CLK_STOP_TIMES_START (24)
#define SOC_SDEMMC_DFX_RD_BLK_GAP_LAT_SD_CLK_STOP_TIMES_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int RD_BLK_GAP_LAT_LAST : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_SDEMMC_DFT_RD_BLK_GAP_LAT_LAST_UNION;
#endif
#define SOC_SDEMMC_DFT_RD_BLK_GAP_LAT_LAST_RD_BLK_GAP_LAT_LAST_START (0)
#define SOC_SDEMMC_DFT_RD_BLK_GAP_LAT_LAST_RD_BLK_GAP_LAT_LAST_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int CRC_STATUS_LAT_MIN : 3;
        unsigned int CRC_STATUS_LAT_MAX : 9;
        unsigned int CRC_STATUS_LAT_LAST : 9;
        unsigned int reserved : 11;
    } reg;
} SOC_SDEMMC_DFX_CRC_STATUS_LAT_UNION;
#endif
#define SOC_SDEMMC_DFX_CRC_STATUS_LAT_CRC_STATUS_LAT_MIN_START (0)
#define SOC_SDEMMC_DFX_CRC_STATUS_LAT_CRC_STATUS_LAT_MIN_END (2)
#define SOC_SDEMMC_DFX_CRC_STATUS_LAT_CRC_STATUS_LAT_MAX_START (3)
#define SOC_SDEMMC_DFX_CRC_STATUS_LAT_CRC_STATUS_LAT_MAX_END (11)
#define SOC_SDEMMC_DFX_CRC_STATUS_LAT_CRC_STATUS_LAT_LAST_START (12)
#define SOC_SDEMMC_DFX_CRC_STATUS_LAT_CRC_STATUS_LAT_LAST_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int datapath_ctrl_1 : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_SDEMMC_DFX_DATAPATH_CTRL_1_UNION;
#endif
#define SOC_SDEMMC_DFX_DATAPATH_CTRL_1_datapath_ctrl_1_START (0)
#define SOC_SDEMMC_DFX_DATAPATH_CTRL_1_datapath_ctrl_1_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tuning_phases_result : 32;
    } reg;
} SOC_SDEMMC_TUNING_PHASES_RESULT_UNION;
#endif
#define SOC_SDEMMC_TUNING_PHASES_RESULT_tuning_phases_result_START (0)
#define SOC_SDEMMC_TUNING_PHASES_RESULT_tuning_phases_result_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tuning_st : 3;
        unsigned int tuning_result : 5;
        unsigned int cur_tuning_phase : 6;
        unsigned int tuning_executing : 1;
        unsigned int phase0_is_ok : 1;
        unsigned int width_from_phase0 : 5;
        unsigned int sample_tuning_done : 1;
        unsigned int reserved_0 : 2;
        unsigned int start_phase : 5;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_SDEMMC_DFX_TUNING_UNION;
#endif
#define SOC_SDEMMC_DFX_TUNING_tuning_st_START (0)
#define SOC_SDEMMC_DFX_TUNING_tuning_st_END (2)
#define SOC_SDEMMC_DFX_TUNING_tuning_result_START (3)
#define SOC_SDEMMC_DFX_TUNING_tuning_result_END (7)
#define SOC_SDEMMC_DFX_TUNING_cur_tuning_phase_START (8)
#define SOC_SDEMMC_DFX_TUNING_cur_tuning_phase_END (13)
#define SOC_SDEMMC_DFX_TUNING_tuning_executing_START (14)
#define SOC_SDEMMC_DFX_TUNING_tuning_executing_END (14)
#define SOC_SDEMMC_DFX_TUNING_phase0_is_ok_START (15)
#define SOC_SDEMMC_DFX_TUNING_phase0_is_ok_END (15)
#define SOC_SDEMMC_DFX_TUNING_width_from_phase0_START (16)
#define SOC_SDEMMC_DFX_TUNING_width_from_phase0_END (20)
#define SOC_SDEMMC_DFX_TUNING_sample_tuning_done_START (21)
#define SOC_SDEMMC_DFX_TUNING_sample_tuning_done_END (21)
#define SOC_SDEMMC_DFX_TUNING_start_phase_START (24)
#define SOC_SDEMMC_DFX_TUNING_start_phase_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cur_width : 5;
        unsigned int sample_clock_select_set : 1;
        unsigned int tuning_phase_error : 1;
        unsigned int reserved_0 : 1;
        unsigned int best_width : 5;
        unsigned int reserved_1 : 3;
        unsigned int best_sample_phase : 5;
        unsigned int reserved_2 : 11;
    } reg;
} SOC_SDEMMC_DFX_TUNING_1_UNION;
#endif
#define SOC_SDEMMC_DFX_TUNING_1_cur_width_START (0)
#define SOC_SDEMMC_DFX_TUNING_1_cur_width_END (4)
#define SOC_SDEMMC_DFX_TUNING_1_sample_clock_select_set_START (5)
#define SOC_SDEMMC_DFX_TUNING_1_sample_clock_select_set_END (5)
#define SOC_SDEMMC_DFX_TUNING_1_tuning_phase_error_START (6)
#define SOC_SDEMMC_DFX_TUNING_1_tuning_phase_error_END (6)
#define SOC_SDEMMC_DFX_TUNING_1_best_width_START (8)
#define SOC_SDEMMC_DFX_TUNING_1_best_width_END (12)
#define SOC_SDEMMC_DFX_TUNING_1_best_sample_phase_START (16)
#define SOC_SDEMMC_DFX_TUNING_1_best_sample_phase_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_cmdpath : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_SDEMMC_DFX_CMDPATH_UNION;
#endif
#define SOC_SDEMMC_DFX_CMDPATH_dfx_cmdpath_START (0)
#define SOC_SDEMMC_DFX_CMDPATH_dfx_cmdpath_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pin_dir_set : 1;
        unsigned int pin_cmd_dir : 1;
        unsigned int pin_dat_dir : 4;
        unsigned int reserved_0 : 2;
        unsigned int tp_sel : 4;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_SDEMMC_DFT_CONFIG_UNION;
#endif
#define SOC_SDEMMC_DFT_CONFIG_pin_dir_set_START (0)
#define SOC_SDEMMC_DFT_CONFIG_pin_dir_set_END (0)
#define SOC_SDEMMC_DFT_CONFIG_pin_cmd_dir_START (1)
#define SOC_SDEMMC_DFT_CONFIG_pin_cmd_dir_END (1)
#define SOC_SDEMMC_DFT_CONFIG_pin_dat_dir_START (2)
#define SOC_SDEMMC_DFT_CONFIG_pin_dat_dir_END (5)
#define SOC_SDEMMC_DFT_CONFIG_tp_sel_START (8)
#define SOC_SDEMMC_DFT_CONFIG_tp_sel_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_dma_ctrl_sel : 32;
    } reg;
} SOC_SDEMMC_DFX_DMA_CTRL_SEL_UNION;
#endif
#define SOC_SDEMMC_DFX_DMA_CTRL_SEL_dfx_dma_ctrl_sel_START (0)
#define SOC_SDEMMC_DFX_DMA_CTRL_SEL_dfx_dma_ctrl_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_dma_next_sdma_addr : 32;
    } reg;
} SOC_SDEMMC_DFX_DMA_NEXT_SDMA_ADDR_UNION;
#endif
#define SOC_SDEMMC_DFX_DMA_NEXT_SDMA_ADDR_dfx_dma_next_sdma_addr_START (0)
#define SOC_SDEMMC_DFX_DMA_NEXT_SDMA_ADDR_dfx_dma_next_sdma_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_dma_next_adma_addr_l : 32;
    } reg;
} SOC_SDEMMC_DFX_DMA_NEXT_ADMA_ADDR_L_UNION;
#endif
#define SOC_SDEMMC_DFX_DMA_NEXT_ADMA_ADDR_L_dfx_dma_next_adma_addr_l_START (0)
#define SOC_SDEMMC_DFX_DMA_NEXT_ADMA_ADDR_L_dfx_dma_next_adma_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_dma_next_adma_addr_h : 32;
    } reg;
} SOC_SDEMMC_DFX_DMA_NEXT_ADMA_ADDR_H_UNION;
#endif
#define SOC_SDEMMC_DFX_DMA_NEXT_ADMA_ADDR_H_dfx_dma_next_adma_addr_h_START (0)
#define SOC_SDEMMC_DFX_DMA_NEXT_ADMA_ADDR_H_dfx_dma_next_adma_addr_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int axi_write_cnt : 8;
        unsigned int axi_aw_w_cnt : 8;
        unsigned int axi_read_cnt : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_SDEMMC_DFX_DMA_AXI_TRANSFER_CNT_UNION;
#endif
#define SOC_SDEMMC_DFX_DMA_AXI_TRANSFER_CNT_axi_write_cnt_START (0)
#define SOC_SDEMMC_DFX_DMA_AXI_TRANSFER_CNT_axi_write_cnt_END (7)
#define SOC_SDEMMC_DFX_DMA_AXI_TRANSFER_CNT_axi_aw_w_cnt_START (8)
#define SOC_SDEMMC_DFX_DMA_AXI_TRANSFER_CNT_axi_aw_w_cnt_END (15)
#define SOC_SDEMMC_DFX_DMA_AXI_TRANSFER_CNT_axi_read_cnt_START (16)
#define SOC_SDEMMC_DFX_DMA_AXI_TRANSFER_CNT_axi_read_cnt_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int block_count_left : 16;
        unsigned int block_size_left : 12;
        unsigned int reserved : 4;
    } reg;
} SOC_SDEMMC_DFX_DMA_BLOCK_VALUE_UNION;
#endif
#define SOC_SDEMMC_DFX_DMA_BLOCK_VALUE_block_count_left_START (0)
#define SOC_SDEMMC_DFX_DMA_BLOCK_VALUE_block_count_left_END (15)
#define SOC_SDEMMC_DFX_DMA_BLOCK_VALUE_block_size_left_START (16)
#define SOC_SDEMMC_DFX_DMA_BLOCK_VALUE_block_size_left_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adma_descriptor_0 : 32;
    } reg;
} SOC_SDEMMC_DFX_DMA_DESCRIPTOR_0_UNION;
#endif
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_0_adma_descriptor_0_START (0)
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_0_adma_descriptor_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adma_descriptor_1 : 32;
    } reg;
} SOC_SDEMMC_DFX_DMA_DESCRIPTOR_1_UNION;
#endif
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_1_adma_descriptor_1_START (0)
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_1_adma_descriptor_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adma_descriptor_2 : 32;
    } reg;
} SOC_SDEMMC_DFX_DMA_DESCRIPTOR_2_UNION;
#endif
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_2_adma_descriptor_2_START (0)
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_2_adma_descriptor_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adma_descriptor_3 : 32;
    } reg;
} SOC_SDEMMC_DFX_DMA_DESCRIPTOR_3_UNION;
#endif
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_3_adma_descriptor_3_START (0)
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_3_adma_descriptor_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int next_sram_byte_addr : 2;
        unsigned int next_sram_addr : 9;
        unsigned int reserved : 21;
    } reg;
} SOC_SDEMMC_DFX_DMA_BUFFER_ADDR_UNION;
#endif
#define SOC_SDEMMC_DFX_DMA_BUFFER_ADDR_next_sram_byte_addr_START (0)
#define SOC_SDEMMC_DFX_DMA_BUFFER_ADDR_next_sram_byte_addr_END (1)
#define SOC_SDEMMC_DFX_DMA_BUFFER_ADDR_next_sram_addr_START (2)
#define SOC_SDEMMC_DFX_DMA_BUFFER_ADDR_next_sram_addr_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_dma_descriptor_addr_l : 32;
    } reg;
} SOC_SDEMMC_DFX_DMA_DESCRIPTOR_ADDR_L_UNION;
#endif
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_ADDR_L_dfx_dma_descriptor_addr_l_START (0)
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_ADDR_L_dfx_dma_descriptor_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_dma_descriptor_addr_h : 32;
    } reg;
} SOC_SDEMMC_DFX_DMA_DESCRIPTOR_ADDR_H_UNION;
#endif
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_ADDR_H_dfx_dma_descriptor_addr_h_START (0)
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_ADDR_H_dfx_dma_descriptor_addr_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int trans_descr_len_left : 17;
        unsigned int trans_descr_attr : 6;
        unsigned int trans_descr_valid : 1;
        unsigned int reserved : 8;
    } reg;
} SOC_SDEMMC_DFX_DMA_DESCRIPTOR_OTHERS_UNION;
#endif
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_OTHERS_trans_descr_len_left_START (0)
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_OTHERS_trans_descr_len_left_END (16)
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_OTHERS_trans_descr_attr_START (17)
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_OTHERS_trans_descr_attr_END (22)
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_OTHERS_trans_descr_valid_START (23)
#define SOC_SDEMMC_DFX_DMA_DESCRIPTOR_OTHERS_trans_descr_valid_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sdma_next_descriptor_addr : 32;
    } reg;
} SOC_SDEMMC_DFX_DMA_NEXT_SDMA_DESCR_ADDR_UNION;
#endif
#define SOC_SDEMMC_DFX_DMA_NEXT_SDMA_DESCR_ADDR_sdma_next_descriptor_addr_START (0)
#define SOC_SDEMMC_DFX_DMA_NEXT_SDMA_DESCR_ADDR_sdma_next_descriptor_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adma_next_descriptor_addr_l : 32;
    } reg;
} SOC_SDEMMC_DFX_DMA_NEXT_ADMA_DESCR_ADDR_L_UNION;
#endif
#define SOC_SDEMMC_DFX_DMA_NEXT_ADMA_DESCR_ADDR_L_adma_next_descriptor_addr_l_START (0)
#define SOC_SDEMMC_DFX_DMA_NEXT_ADMA_DESCR_ADDR_L_adma_next_descriptor_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adma_next_descriptor_addr_h : 32;
    } reg;
} SOC_SDEMMC_DFX_DMA_NEXT_ADMA_DESCR_ADDR_H_UNION;
#endif
#define SOC_SDEMMC_DFX_DMA_NEXT_ADMA_DESCR_ADDR_H_adma_next_descriptor_addr_h_START (0)
#define SOC_SDEMMC_DFX_DMA_NEXT_ADMA_DESCR_ADDR_H_adma_next_descriptor_addr_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int adma_descriptor_length_left : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_SDEMMC_DFX_DMA_ADMA_DESCR_LEN_LEFT_UNION;
#endif
#define SOC_SDEMMC_DFX_DMA_ADMA_DESCR_LEN_LEFT_adma_descriptor_length_left_START (0)
#define SOC_SDEMMC_DFX_DMA_ADMA_DESCR_LEN_LEFT_adma_descriptor_length_left_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_contx_table_value : 32;
    } reg;
} SOC_SDEMMC_DFX_DMA_CONTX_TABLE_VALUE_UNION;
#endif
#define SOC_SDEMMC_DFX_DMA_CONTX_TABLE_VALUE_dma_contx_table_value_START (0)
#define SOC_SDEMMC_DFX_DMA_CONTX_TABLE_VALUE_dma_contx_table_value_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rresp_error_rid : 5;
        unsigned int dma_bresp_error_bid : 5;
        unsigned int reserved : 22;
    } reg;
} SOC_SDEMMC_DFX_DMA_RESP_ERROR_INFO_UNION;
#endif
#define SOC_SDEMMC_DFX_DMA_RESP_ERROR_INFO_dma_rresp_error_rid_START (0)
#define SOC_SDEMMC_DFX_DMA_RESP_ERROR_INFO_dma_rresp_error_rid_END (4)
#define SOC_SDEMMC_DFX_DMA_RESP_ERROR_INFO_dma_bresp_error_bid_START (5)
#define SOC_SDEMMC_DFX_DMA_RESP_ERROR_INFO_dma_bresp_error_bid_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sd2axi_address : 16;
        unsigned int axi2sd_address : 16;
    } reg;
} SOC_SDEMMC_DFX_DMA_AXI_SD_BUFFER_ADDR_UNION;
#endif
#define SOC_SDEMMC_DFX_DMA_AXI_SD_BUFFER_ADDR_sd2axi_address_START (0)
#define SOC_SDEMMC_DFX_DMA_AXI_SD_BUFFER_ADDR_sd2axi_address_END (15)
#define SOC_SDEMMC_DFX_DMA_AXI_SD_BUFFER_ADDR_axi2sd_address_START (16)
#define SOC_SDEMMC_DFX_DMA_AXI_SD_BUFFER_ADDR_axi2sd_address_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
