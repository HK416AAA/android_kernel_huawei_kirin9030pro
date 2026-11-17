#ifndef __SOC_CPU_RTM_INTERFACE_H__
#define __SOC_CPU_RTM_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_CPU_RTM_RTM_CTRL_ADDR(base) ((base) + (0x0000UL))
#define SOC_CPU_RTM_DMA_EN_ADDR(base) ((base) + (0x0004UL))
#define SOC_CPU_RTM_SOFTWARE_RESET_ADDR(base) ((base) + (0x0008UL))
#define SOC_CPU_RTM_RTM_FLUSH_ADDR(base) ((base) + (0x000CUL))
#define SOC_CPU_RTM_DMA_CTRL_ADDR(base) ((base) + (0x0010UL))
#define SOC_CPU_RTM_SDMA_ADDR_UPDATE_ADDR(base) ((base) + (0x0014UL))
#define SOC_CPU_RTM_CFG_DMA_DFX_SEL_ADDR(base) ((base) + (0x0018UL))
#define SOC_CPU_RTM_SDMA_ADDR_ARG_L_ADDR(base) ((base) + (0x001CUL))
#define SOC_CPU_RTM_SDMA_ADDR_ARG_H_ADDR(base) ((base) + (0x0020UL))
#define SOC_CPU_RTM_ADMA_SYSTEM_ADDR_0_L_ADDR(base) ((base) + (0x0024UL))
#define SOC_CPU_RTM_ADMA_SYSTEM_ADDR_0_H_ADDR(base) ((base) + (0x0028UL))
#define SOC_CPU_RTM_ADMA_SYSTEM_ADDR_1_L_ADDR(base) ((base) + (0x002CUL))
#define SOC_CPU_RTM_ADMA_SYSTEM_ADDR_1_H_ADDR(base) ((base) + (0x0030UL))
#define SOC_CPU_RTM_ADMA_SYSTEM_ADDR_2_L_ADDR(base) ((base) + (0x0034UL))
#define SOC_CPU_RTM_ADMA_SYSTEM_ADDR_2_H_ADDR(base) ((base) + (0x0038UL))
#define SOC_CPU_RTM_ADMA_BLK_COUNT_1_0_ADDR(base) ((base) + (0x003CUL))
#define SOC_CPU_RTM_ADMA_BLK_COUNT_2_ADDR(base) ((base) + (0x0040UL))
#define SOC_CPU_RTM_ADMA_BLK_SIZE_ADDR(base) ((base) + (0x0044UL))
#define SOC_CPU_RTM_RTM_MEM_CTRL_ADDR(base) ((base) + (0x0048UL))
#define SOC_CPU_RTM_RTM_DMA_STATE_ADDR(base) ((base) + (0x004CUL))
#define SOC_CPU_RTM_APB_RD_POINTER_DONE_ADDR(base) ((base) + (0x0050UL))
#define SOC_CPU_RTM_RTM_SYNC_CFG0_ADDR(base) ((base) + (0x0054UL))
#define SOC_CPU_RTM_RTM_SYNC_CFG1_ADDR(base) ((base) + (0x0058UL))
#define SOC_CPU_RTM_RTM_SYNC_CFG2_ADDR(base) ((base) + (0x005CUL))
#define SOC_CPU_RTM_RTM_SYNC_CFG3_ADDR(base) ((base) + (0x0060UL))
#define SOC_CPU_RTM_RTM_SYNC_CFG4_ADDR(base) ((base) + (0x0064UL))
#define SOC_CPU_RTM_RTM_SYNC_CFG5_ADDR(base) ((base) + (0x0068UL))
#define SOC_CPU_RTM_RTM_SYNC_CFG6_ADDR(base) ((base) + (0x006CUL))
#define SOC_CPU_RTM_RTM_SYNC_CFG7_ADDR(base) ((base) + (0x0070UL))
#define SOC_CPU_RTM_RTM_SYNC_CFG8_ADDR(base) ((base) + (0x0074UL))
#define SOC_CPU_RTM_RTM_SYNC_CFG9_ADDR(base) ((base) + (0x0078UL))
#define SOC_CPU_RTM_RTM_SYNC_CFG10_ADDR(base) ((base) + (0x007CUL))
#define SOC_CPU_RTM_RTM_SYNC_CFG11_ADDR(base) ((base) + (0x0080UL))
#define SOC_CPU_RTM_RTM_SYNC_CFG12_ADDR(base) ((base) + (0x0084UL))
#define SOC_CPU_RTM_RTM_SYNC_CFG13_ADDR(base) ((base) + (0x0088UL))
#define SOC_CPU_RTM_TRACE_CTRL_ADDR(base) ((base) + (0x008CUL))
#define SOC_CPU_RTM_SAMP_ON_TIME_L_ADDR(base) ((base) + (0x0090UL))
#define SOC_CPU_RTM_SAMP_ON_TIME_H_ADDR(base) ((base) + (0x0094UL))
#define SOC_CPU_RTM_SAMP_EN_TIME_L_ADDR(base) ((base) + (0x0098UL))
#define SOC_CPU_RTM_SAMP_EN_TIME_H_ADDR(base) ((base) + (0x009CUL))
#define SOC_CPU_RTM_TS_EN_TIME_L_ADDR(base) ((base) + (0x00A0UL))
#define SOC_CPU_RTM_TS_EN_TIME_H_ADDR(base) ((base) + (0x00A4UL))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID0_ADDR(base) ((base) + (0x00A8UL))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID1_ADDR(base) ((base) + (0x00ACUL))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID2_ADDR(base) ((base) + (0x00B0UL))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID3_ADDR(base) ((base) + (0x00B4UL))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID4_ADDR(base) ((base) + (0x00B8UL))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID5_ADDR(base) ((base) + (0x00BCUL))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID6_ADDR(base) ((base) + (0x00C0UL))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID7_ADDR(base) ((base) + (0x00C4UL))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID8_ADDR(base) ((base) + (0x00C8UL))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID9_ADDR(base) ((base) + (0x00CCUL))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID10_ADDR(base) ((base) + (0x00D0UL))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID11_ADDR(base) ((base) + (0x00D4UL))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID12_ADDR(base) ((base) + (0x00D8UL))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID13_ADDR(base) ((base) + (0x00DCUL))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID_LATMNT_ADDR(base) ((base) + (0x00E0UL))
#define SOC_CPU_RTM_RTM_INT0_STATE_ADDR(base) ((base) + (0x00E4UL))
#define SOC_CPU_RTM_RTM_INT0_STATE_ENABLE_ADDR(base) ((base) + (0x00E8UL))
#define SOC_CPU_RTM_RTM_INT0_SINGAL_ENABLE_ADDR(base) ((base) + (0x00ECUL))
#define SOC_CPU_RTM_RTM_INT_XPU_EN_ADDR(base) ((base) + (0x00F0UL))
#define SOC_CPU_RTM_RTM_INT1_STATE_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0xF4UL))
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x12CUL))
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x164UL))
#define SOC_CPU_RTM_RTM_INT2_STATE_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x19CUL))
#define SOC_CPU_RTM_RTM_INT2_STATE_ENABLE_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x1D4UL))
#define SOC_CPU_RTM_RTM_INT2_SINGAL_ENABLE_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x20CUL))
#define SOC_CPU_RTM_CFG_MONITOR_EN_ADDR(base) ((base) + (0x0244UL))
#define SOC_CPU_RTM_CFG_PERIOD_EVENT_MSK_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x248UL))
#define SOC_CPU_RTM_CFG_PERIOD_EVENT_TS_0_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x280UL))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_0_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x360UL))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_1_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x398UL))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_2_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x3D0UL))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_3_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x408UL))
#define SOC_CPU_RTM_CFG_FILTER_CTRL_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x440UL))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_MSK_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x478UL))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_0_ADDR(base) ((base) + (0x4B0UL))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_1_ADDR(base) ((base) + (0x4E8UL))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_2_ADDR(base) ((base) + (0x520UL))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_3_ADDR(base) ((base) + (0x558UL))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_4_ADDR(base) ((base) + (0x590UL))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_5_ADDR(base) ((base) + (0x5C8UL))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_6_ADDR(base) ((base) + (0x600UL))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_7_ADDR(base) ((base) + (0x638UL))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_8_ADDR(base) ((base) + (0x670UL))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_9_ADDR(base) ((base) + (0x6A8UL))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_10_ADDR(base) ((base) + (0x6E0UL))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_11_ADDR(base) ((base) + (0x718UL))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_12_ADDR(base) ((base) + (0x750UL))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_13_ADDR(base) ((base) + (0x788UL))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_14_ADDR(base) ((base) + (0x7C0UL))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_15_ADDR(base) ((base) + (0x7F8UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS0_ADDR(base) ((base) + (0x800UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS1_ADDR(base) ((base) + (0x804UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS2_ADDR(base) ((base) + (0x808UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS3_ADDR(base) ((base) + (0x080CUL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS0_ADDR(base) ((base) + (0x810UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS1_ADDR(base) ((base) + (0x814UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS2_ADDR(base) ((base) + (0x818UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS3_ADDR(base) ((base) + (0x081CUL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS0_ADDR(base) ((base) + (0x820UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS1_ADDR(base) ((base) + (0x824UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS2_ADDR(base) ((base) + (0x828UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS3_ADDR(base) ((base) + (0x082CUL))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_MSK_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x830UL))
#define SOC_CPU_RTM_CFG_TIMER_TMO_H_L_ADDR(base) ((base) + (0x868UL))
#define SOC_CPU_RTM_CFG_TIMER_TMO_H_H_ADDR(base) ((base) + (0x8A0UL))
#define SOC_CPU_RTM_CFG_TIMER_TMO_L_L_ADDR(base) ((base) + (0x8D8UL))
#define SOC_CPU_RTM_CFG_TIMER_TMO_L_H_ADDR(base) ((base) + (0x910UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS0_ADDR(base) ((base) + (0x914UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS1_ADDR(base) ((base) + (0x918UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS2_ADDR(base) ((base) + (0x91CUL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS3_ADDR(base) ((base) + (0x0920UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS0_ADDR(base) ((base) + (0x924UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS1_ADDR(base) ((base) + (0x928UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS2_ADDR(base) ((base) + (0x92CUL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS3_ADDR(base) ((base) + (0x0930UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS0_ADDR(base) ((base) + (0x934UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS1_ADDR(base) ((base) + (0x938UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS2_ADDR(base) ((base) + (0x93CUL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS3_ADDR(base) ((base) + (0x940UL))
#define SOC_CPU_RTM_DFX_SIG_MON_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x948UL))
#define SOC_CPU_RTM_DFX_RTM_TRACE_SAMPLE_ADDR(base) ((base) + (0x0980UL))
#define SOC_CPU_RTM_DFX_RTM_TRACE_GEN_ADDR(base) ((base) + (0x0984UL))
#define SOC_CPU_RTM_DFX_RTM_TRACE_MST_ADDR(base) ((base) + (0x0988UL))
#define SOC_CPU_RTM_DFX_RTM_BUFFER_ADDR(base) ((base) + (0x098CUL))
#define SOC_CPU_RTM_DFX_DMA_NEXT_SDMA_ADDR_ADDR(base) ((base) + (0x0990UL))
#define SOC_CPU_RTM_DFX_DMA_NEXT_ADMA_ADDR_L_ADDR(base) ((base) + (0x0994UL))
#define SOC_CPU_RTM_DFX_DMA_NEXT_ADMA_ADDR_H_ADDR(base) ((base) + (0x0998UL))
#define SOC_CPU_RTM_DFX_DMA_AXI_TRANSFER_CNT_ADDR(base) ((base) + (0x099CUL))
#define SOC_CPU_RTM_DFX_DMA_BLOCK_VALUE_ADDR(base) ((base) + (0x09A0UL))
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_0_ADDR(base) ((base) + (0x09A4UL))
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_1_ADDR(base) ((base) + (0x09A8UL))
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_2_ADDR(base) ((base) + (0x09ACUL))
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_3_ADDR(base) ((base) + (0x09B0UL))
#define SOC_CPU_RTM_DFX_DMA_BUFFER_ADDR_ADDR(base) ((base) + (0x09B4UL))
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_ADDR_L_ADDR(base) ((base) + (0x09B8UL))
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_ADDR_H_ADDR(base) ((base) + (0x09BCUL))
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_OTHERS_ADDR(base) ((base) + (0x09C0UL))
#define SOC_CPU_RTM_DFX_DMA_NEXT_SDMA_DESCR_ADDR_ADDR(base) ((base) + (0x09C4UL))
#define SOC_CPU_RTM_DFX_DMA_NEXT_ADMA_DESCR_ADDR_L_ADDR(base) ((base) + (0x09C8UL))
#define SOC_CPU_RTM_DFX_DMA_NEXT_ADMA_DESCR_ADDR_H_ADDR(base) ((base) + (0x09CCUL))
#define SOC_CPU_RTM_DFX_DMA_ADMA_DESCR_LEN_LEFT_ADDR(base) ((base) + (0x09D0UL))
#define SOC_CPU_RTM_DFX_DMA_CONTX_TABLE_VALUE_ADDR(base) ((base) + (0x09D4UL))
#define SOC_CPU_RTM_DFX_DMA_RESP_ERROR_INFO_ADDR(base) ((base) + (0x09D8UL))
#define SOC_CPU_RTM_DFX_DMA_AXI_SD_BUFFER_ADDR_ADDR(base) ((base) + (0x09DCUL))
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x9E0UL))
#define SOC_CPU_RTM_DFX_RTM_TASK_CTRL_0_ADDR(base) ((base) + (0x0A18UL))
#define SOC_CPU_RTM_DFX_RTM_TASK_CTRL_1_ADDR(base) ((base) + (0x0A1CUL))
#define SOC_CPU_RTM_DFX_DMA_TP_ADDR(base) ((base) + (0x0A20UL))
#define SOC_CPU_RTM_TEST_POINT_SEL_ADDR(base) ((base) + (0x0A24UL))
#define SOC_CPU_RTM_HARD_SAMP_EN_TIME_L_ADDR(base) ((base) + (0x0A28UL))
#define SOC_CPU_RTM_HARD_SAMP_EN_TIME_H_ADDR(base) ((base) + (0x0A2CUL))
#define SOC_CPU_RTM_HARD_TS_EN_TIME_L_ADDR(base) ((base) + (0x0A30UL))
#define SOC_CPU_RTM_HARD_TS_EN_TIME_H_ADDR(base) ((base) + (0x0A34UL))
#define SOC_CPU_RTM_EVENT_INDEX_VALID_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0xA38UL))
#define SOC_CPU_RTM_RTM_PROCESS_IDLE_ADDR(base) ((base) + (0x0A70UL))
#define SOC_CPU_RTM_RTM_CKG_BYPASS_ADDR(base) ((base) + (0x0A74UL))
#define SOC_CPU_RTM_RTM_CKG_WAKEUP_EN_ADDR(base) ((base) + (0x0A78UL))
#define SOC_CPU_RTM_RTM_CKG_BUSY_ADDR(base) ((base) + (0x0A7CUL))
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ADDR(base) ((base) + (0x0A80UL))
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ADDR(base) ((base) + (0x0A84UL))
#define SOC_CPU_RTM_AXI_CONF_ADDR(base) ((base) + (0x0A88UL))
#define SOC_CPU_RTM_LATENCY_CNT_SOFTWARE_RESET_ADDR(base) ((base) + (0x0B00UL))
#define SOC_CPU_RTM_LATENCY_CNT_CONFIG1_ADDR(base) ((base) + (0x0B04UL))
#define SOC_CPU_RTM_LATENCY_CNT_CONFIG2_ADDR(base) ((base) + (0x0B08UL))
#define SOC_CPU_RTM_LATENCY_CNT_CONFIG3_ADDR(base) ((base) + (0x0B0CUL))
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG1_ADDR(base) ((base) + (0x0B10UL))
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG2_ADDR(base) ((base) + (0x0B14UL))
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG3_ADDR(base) ((base) + (0x0B18UL))
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG4_ADDR(base) ((base) + (0x0B1CUL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS0_ADDR(base) ((base) + (0x0B20UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS1_ADDR(base) ((base) + (0x0B24UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS2_ADDR(base) ((base) + (0x0B28UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS3_ADDR(base) ((base) + (0x0B2CUL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS0_ADDR(base) ((base) + (0x0B30UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS1_ADDR(base) ((base) + (0x0B34UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS2_ADDR(base) ((base) + (0x0B38UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS3_ADDR(base) ((base) + (0x0B3CUL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS0_ADDR(base) ((base) + (0x0B40UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS1_ADDR(base) ((base) + (0x0B44UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS2_ADDR(base) ((base) + (0x0B48UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS3_ADDR(base) ((base) + (0x0B4CUL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS0_ADDR(base) ((base) + (0x0B50UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS1_ADDR(base) ((base) + (0x0B54UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS2_ADDR(base) ((base) + (0x0B58UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS3_ADDR(base) ((base) + (0x0B5CUL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS0_ADDR(base) ((base) + (0x0B60UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS1_ADDR(base) ((base) + (0x0B64UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS2_ADDR(base) ((base) + (0x0B68UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS3_ADDR(base) ((base) + (0x0B6CUL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS0_ADDR(base) ((base) + (0x0B70UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS1_ADDR(base) ((base) + (0x0B74UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS2_ADDR(base) ((base) + (0x0B78UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS3_ADDR(base) ((base) + (0x0B7CUL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS0_ADDR(base) ((base) + (0x0B80UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS1_ADDR(base) ((base) + (0x0B84UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS2_ADDR(base) ((base) + (0x0B88UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS3_ADDR(base) ((base) + (0x0B8CUL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS0_ADDR(base) ((base) + (0x0B90UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS1_ADDR(base) ((base) + (0x0B94UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS2_ADDR(base) ((base) + (0x0B98UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS3_ADDR(base) ((base) + (0x0B9CUL))
#define SOC_CPU_RTM_LATENCY_CNT_EVENT_STATE_ADDR(base) ((base) + (0x0BA0UL))
#define SOC_CPU_RTM_LATENCY_CNT_EVENT_CLR_ADDR(base) ((base) + (0x0BA4UL))
#define SOC_CPU_RTM_LATENCY_INT_LPID_ADDR(base) ((base) + (0x0BA8UL))
#define SOC_CPU_RTM_LATENCY_INT_CNT0_ADDR(base) ((base) + (0x0BACUL))
#define SOC_CPU_RTM_LATENCY_INT_CNT1_ADDR(base) ((base) + (0x0BB0UL))
#define SOC_CPU_RTM_LATENCY_INT_CNT2_ADDR(base) ((base) + (0x0BB4UL))
#define SOC_CPU_RTM_LATENCY_INT_CNT3_ADDR(base) ((base) + (0x0BB8UL))
#define SOC_CPU_RTM_LATENCY_INT_CNT4_ADDR(base) ((base) + (0x0BBCUL))
#define SOC_CPU_RTM_LATENCY_INT_CNT5_ADDR(base) ((base) + (0x0BC0UL))
#define SOC_CPU_RTM_LATENCY_INT_CNT6_ADDR(base) ((base) + (0x0BC4UL))
#define SOC_CPU_RTM_LATENCY_INT_CNT7_ADDR(base) ((base) + (0x0BC8UL))
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG5_ADDR(base) ((base) + (0x0BCCUL))
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG6_ADDR(base) ((base) + (0x0BD0UL))
#define SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO0_ADDR(base) ((base) + (0x0BD4UL))
#define SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO1_ADDR(base) ((base) + (0x0BD8UL))
#define SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO2_ADDR(base) ((base) + (0x0BDCUL))
#define SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO3_ADDR(base) ((base) + (0x0BE0UL))
#define SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO4_ADDR(base) ((base) + (0x0BE4UL))
#define SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO5_ADDR(base) ((base) + (0x0BE8UL))
#define SOC_CPU_RTM_MNT_DEBUG_EN_ADDR(base) ((base) + (0xC00UL))
#define SOC_CPU_RTM_MNT_DEBUG_SYNC_ALIGN_COUNT_ADDR(base) ((base) + (0xC04UL))
#define SOC_CPU_RTM_MNT_DEBUG_CNT_ADDR(base,debug_info_num) ((base) + ((debug_info_num)*0x4+0xC08UL))
#define SOC_CPU_RTM_RTM_SYNC_CFG14_1_ADDR(base) ((base) + (0xCB8UL))
#define SOC_CPU_RTM_RTM_SYNC_CFG15_1_ADDR(base) ((base) + (0xCBCUL))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID14_1_ADDR(base) ((base) + (0xCD4UL))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID15_1_ADDR(base) ((base) + (0xCD8UL))
#define SOC_CPU_RTM_RTM_INT1_STATE_14_1_ADDR(base) ((base) + (0xCF0UL))
#define SOC_CPU_RTM_RTM_INT1_STATE_15_1_ADDR(base) ((base) + (0xCF4UL))
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_14_1_ADDR(base) ((base) + (0xD0CUL))
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_15_1_ADDR(base) ((base) + (0xD10UL))
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_14_1_ADDR(base) ((base) + (0xD28UL))
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_15_1_ADDR(base) ((base) + (0xD2CUL))
#define SOC_CPU_RTM_RTM_INT2_STATE_14_1_ADDR(base) ((base) + (0xD40UL))
#define SOC_CPU_RTM_RTM_INT2_STATE_15_1_ADDR(base) ((base) + (0xD44UL))
#define SOC_CPU_RTM_RTM_INT2_STATE_ENABLE_14_1_ADDR(base) ((base) + (0xD5CUL))
#define SOC_CPU_RTM_RTM_INT2_STATE_ENABLE_15_1_ADDR(base) ((base) + (0xD60UL))
#define SOC_CPU_RTM_RTM_INT2_SINGAL_ENABLE_14_1_ADDR(base) ((base) + (0xD78UL))
#define SOC_CPU_RTM_RTM_INT2_SINGAL_ENABLE_15_1_ADDR(base) ((base) + (0xD7CUL))
#define SOC_CPU_RTM_CFG_PERIOD_EVENT_MSK_14_1_ADDR(base) ((base) + (0xDD4UL))
#define SOC_CPU_RTM_CFG_PERIOD_EVENT_MSK_15_1_ADDR(base) ((base) + (0xDD8UL))
#define SOC_CPU_RTM_CFG_PERIOD_EVENT_TS_0_14_1_ADDR(base) ((base) + (0xDF0UL))
#define SOC_CPU_RTM_CFG_PERIOD_EVENT_TS_0_15_1_ADDR(base) ((base) + (0xDF4UL))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_0_14_1_ADDR(base) ((base) + (0xE0CUL))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_0_15_1_ADDR(base) ((base) + (0xE10UL))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_1_14_1_ADDR(base) ((base) + (0xE28UL))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_1_15_1_ADDR(base) ((base) + (0xE2CUL))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_2_14_1_ADDR(base) ((base) + (0xE44UL))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_2_15_1_ADDR(base) ((base) + (0xE48UL))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_3_14_1_ADDR(base) ((base) + (0xE60UL))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_3_15_1_ADDR(base) ((base) + (0xE64UL))
#define SOC_CPU_RTM_CFG_FILTER_CTRL_14_1_ADDR(base) ((base) + (0xE7CUL))
#define SOC_CPU_RTM_CFG_FILTER_CTRL_15_1_ADDR(base) ((base) + (0xE80UL))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_MSK_14_1_ADDR(base) ((base) + (0xE98UL))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_MSK_15_1_ADDR(base) ((base) + (0xE9CUL))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_MSK_14_1_ADDR(base) ((base) + (0xEB4UL))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_MSK_15_1_ADDR(base) ((base) + (0xEB8UL))
#define SOC_CPU_RTM_DFX_SIG_MON_14_1_ADDR(base) ((base) + (0xED0UL))
#define SOC_CPU_RTM_DFX_SIG_MON_15_1_ADDR(base) ((base) + (0xED4UL))
#define SOC_CPU_RTM_EVENT_INDEX_VALID_14_1_ADDR(base) ((base) + (0xEECUL))
#define SOC_CPU_RTM_EVENT_INDEX_VALID_15_1_ADDR(base) ((base) + (0xEF0UL))
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_14_1_ADDR(base) ((base) + (0xF08UL))
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_15_1_ADDR(base) ((base) + (0xF0CUL))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_EN_ADDR(base) ((base) + (0xF24UL))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID0_ADDR(base) ((base) + (0xF28UL))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID1_ADDR(base) ((base) + (0xF2CUL))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID2_ADDR(base) ((base) + (0xF30UL))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_3_ADDR(base) ((base) + (0xF34UL))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_4_ADDR(base) ((base) + (0xF38UL))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_5_ADDR(base) ((base) + (0xF3CUL))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_6_ADDR(base) ((base) + (0xF40UL))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_7_ADDR(base) ((base) + (0xF44UL))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_8_ADDR(base) ((base) + (0xF48UL))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_9_ADDR(base) ((base) + (0xF4CUL))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_10_ADDR(base) ((base) + (0xF50UL))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_11_ADDR(base) ((base) + (0xF54UL))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_12_ADDR(base) ((base) + (0xF58UL))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_13_ADDR(base) ((base) + (0xF5CUL))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_14_ADDR(base) ((base) + (0xF60UL))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_15_ADDR(base) ((base) + (0xF64UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS0_ADDR(base) ((base) + (0xF80UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS1_ADDR(base) ((base) + (0xF84UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS2_ADDR(base) ((base) + (0xF88UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS3_ADDR(base) ((base) + (0xF8CUL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS0_ADDR(base) ((base) + (0xF90UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS1_ADDR(base) ((base) + (0xF94UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS2_ADDR(base) ((base) + (0xF98UL))
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS3_ADDR(base) ((base) + (0xF9CUL))
#define SOC_CPU_RTM_QoS_Sync_en_ADDR(base) ((base) + (0xFA0UL))
#else
#define SOC_CPU_RTM_RTM_CTRL_ADDR(base) ((base) + (0x0000))
#define SOC_CPU_RTM_DMA_EN_ADDR(base) ((base) + (0x0004))
#define SOC_CPU_RTM_SOFTWARE_RESET_ADDR(base) ((base) + (0x0008))
#define SOC_CPU_RTM_RTM_FLUSH_ADDR(base) ((base) + (0x000C))
#define SOC_CPU_RTM_DMA_CTRL_ADDR(base) ((base) + (0x0010))
#define SOC_CPU_RTM_SDMA_ADDR_UPDATE_ADDR(base) ((base) + (0x0014))
#define SOC_CPU_RTM_CFG_DMA_DFX_SEL_ADDR(base) ((base) + (0x0018))
#define SOC_CPU_RTM_SDMA_ADDR_ARG_L_ADDR(base) ((base) + (0x001C))
#define SOC_CPU_RTM_SDMA_ADDR_ARG_H_ADDR(base) ((base) + (0x0020))
#define SOC_CPU_RTM_ADMA_SYSTEM_ADDR_0_L_ADDR(base) ((base) + (0x0024))
#define SOC_CPU_RTM_ADMA_SYSTEM_ADDR_0_H_ADDR(base) ((base) + (0x0028))
#define SOC_CPU_RTM_ADMA_SYSTEM_ADDR_1_L_ADDR(base) ((base) + (0x002C))
#define SOC_CPU_RTM_ADMA_SYSTEM_ADDR_1_H_ADDR(base) ((base) + (0x0030))
#define SOC_CPU_RTM_ADMA_SYSTEM_ADDR_2_L_ADDR(base) ((base) + (0x0034))
#define SOC_CPU_RTM_ADMA_SYSTEM_ADDR_2_H_ADDR(base) ((base) + (0x0038))
#define SOC_CPU_RTM_ADMA_BLK_COUNT_1_0_ADDR(base) ((base) + (0x003C))
#define SOC_CPU_RTM_ADMA_BLK_COUNT_2_ADDR(base) ((base) + (0x0040))
#define SOC_CPU_RTM_ADMA_BLK_SIZE_ADDR(base) ((base) + (0x0044))
#define SOC_CPU_RTM_RTM_MEM_CTRL_ADDR(base) ((base) + (0x0048))
#define SOC_CPU_RTM_RTM_DMA_STATE_ADDR(base) ((base) + (0x004C))
#define SOC_CPU_RTM_APB_RD_POINTER_DONE_ADDR(base) ((base) + (0x0050))
#define SOC_CPU_RTM_RTM_SYNC_CFG0_ADDR(base) ((base) + (0x0054))
#define SOC_CPU_RTM_RTM_SYNC_CFG1_ADDR(base) ((base) + (0x0058))
#define SOC_CPU_RTM_RTM_SYNC_CFG2_ADDR(base) ((base) + (0x005C))
#define SOC_CPU_RTM_RTM_SYNC_CFG3_ADDR(base) ((base) + (0x0060))
#define SOC_CPU_RTM_RTM_SYNC_CFG4_ADDR(base) ((base) + (0x0064))
#define SOC_CPU_RTM_RTM_SYNC_CFG5_ADDR(base) ((base) + (0x0068))
#define SOC_CPU_RTM_RTM_SYNC_CFG6_ADDR(base) ((base) + (0x006C))
#define SOC_CPU_RTM_RTM_SYNC_CFG7_ADDR(base) ((base) + (0x0070))
#define SOC_CPU_RTM_RTM_SYNC_CFG8_ADDR(base) ((base) + (0x0074))
#define SOC_CPU_RTM_RTM_SYNC_CFG9_ADDR(base) ((base) + (0x0078))
#define SOC_CPU_RTM_RTM_SYNC_CFG10_ADDR(base) ((base) + (0x007C))
#define SOC_CPU_RTM_RTM_SYNC_CFG11_ADDR(base) ((base) + (0x0080))
#define SOC_CPU_RTM_RTM_SYNC_CFG12_ADDR(base) ((base) + (0x0084))
#define SOC_CPU_RTM_RTM_SYNC_CFG13_ADDR(base) ((base) + (0x0088))
#define SOC_CPU_RTM_TRACE_CTRL_ADDR(base) ((base) + (0x008C))
#define SOC_CPU_RTM_SAMP_ON_TIME_L_ADDR(base) ((base) + (0x0090))
#define SOC_CPU_RTM_SAMP_ON_TIME_H_ADDR(base) ((base) + (0x0094))
#define SOC_CPU_RTM_SAMP_EN_TIME_L_ADDR(base) ((base) + (0x0098))
#define SOC_CPU_RTM_SAMP_EN_TIME_H_ADDR(base) ((base) + (0x009C))
#define SOC_CPU_RTM_TS_EN_TIME_L_ADDR(base) ((base) + (0x00A0))
#define SOC_CPU_RTM_TS_EN_TIME_H_ADDR(base) ((base) + (0x00A4))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID0_ADDR(base) ((base) + (0x00A8))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID1_ADDR(base) ((base) + (0x00AC))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID2_ADDR(base) ((base) + (0x00B0))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID3_ADDR(base) ((base) + (0x00B4))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID4_ADDR(base) ((base) + (0x00B8))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID5_ADDR(base) ((base) + (0x00BC))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID6_ADDR(base) ((base) + (0x00C0))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID7_ADDR(base) ((base) + (0x00C4))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID8_ADDR(base) ((base) + (0x00C8))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID9_ADDR(base) ((base) + (0x00CC))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID10_ADDR(base) ((base) + (0x00D0))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID11_ADDR(base) ((base) + (0x00D4))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID12_ADDR(base) ((base) + (0x00D8))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID13_ADDR(base) ((base) + (0x00DC))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID_LATMNT_ADDR(base) ((base) + (0x00E0))
#define SOC_CPU_RTM_RTM_INT0_STATE_ADDR(base) ((base) + (0x00E4))
#define SOC_CPU_RTM_RTM_INT0_STATE_ENABLE_ADDR(base) ((base) + (0x00E8))
#define SOC_CPU_RTM_RTM_INT0_SINGAL_ENABLE_ADDR(base) ((base) + (0x00EC))
#define SOC_CPU_RTM_RTM_INT_XPU_EN_ADDR(base) ((base) + (0x00F0))
#define SOC_CPU_RTM_RTM_INT1_STATE_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0xF4))
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x12C))
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x164))
#define SOC_CPU_RTM_RTM_INT2_STATE_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x19C))
#define SOC_CPU_RTM_RTM_INT2_STATE_ENABLE_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x1D4))
#define SOC_CPU_RTM_RTM_INT2_SINGAL_ENABLE_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x20C))
#define SOC_CPU_RTM_CFG_MONITOR_EN_ADDR(base) ((base) + (0x0244))
#define SOC_CPU_RTM_CFG_PERIOD_EVENT_MSK_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x248))
#define SOC_CPU_RTM_CFG_PERIOD_EVENT_TS_0_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x280))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_0_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x360))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_1_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x398))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_2_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x3D0))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_3_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x408))
#define SOC_CPU_RTM_CFG_FILTER_CTRL_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x440))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_MSK_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x478))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_0_ADDR(base) ((base) + (0x4B0))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_1_ADDR(base) ((base) + (0x4E8))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_2_ADDR(base) ((base) + (0x520))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_3_ADDR(base) ((base) + (0x558))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_4_ADDR(base) ((base) + (0x590))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_5_ADDR(base) ((base) + (0x5C8))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_6_ADDR(base) ((base) + (0x600))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_7_ADDR(base) ((base) + (0x638))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_8_ADDR(base) ((base) + (0x670))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_9_ADDR(base) ((base) + (0x6A8))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_10_ADDR(base) ((base) + (0x6E0))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_11_ADDR(base) ((base) + (0x718))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_12_ADDR(base) ((base) + (0x750))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_13_ADDR(base) ((base) + (0x788))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_14_ADDR(base) ((base) + (0x7C0))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_15_ADDR(base) ((base) + (0x7F8))
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS0_ADDR(base) ((base) + (0x800))
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS1_ADDR(base) ((base) + (0x804))
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS2_ADDR(base) ((base) + (0x808))
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS3_ADDR(base) ((base) + (0x080C))
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS0_ADDR(base) ((base) + (0x810))
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS1_ADDR(base) ((base) + (0x814))
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS2_ADDR(base) ((base) + (0x818))
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS3_ADDR(base) ((base) + (0x081C))
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS0_ADDR(base) ((base) + (0x820))
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS1_ADDR(base) ((base) + (0x824))
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS2_ADDR(base) ((base) + (0x828))
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS3_ADDR(base) ((base) + (0x082C))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_MSK_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x830))
#define SOC_CPU_RTM_CFG_TIMER_TMO_H_L_ADDR(base) ((base) + (0x868))
#define SOC_CPU_RTM_CFG_TIMER_TMO_H_H_ADDR(base) ((base) + (0x8A0))
#define SOC_CPU_RTM_CFG_TIMER_TMO_L_L_ADDR(base) ((base) + (0x8D8))
#define SOC_CPU_RTM_CFG_TIMER_TMO_L_H_ADDR(base) ((base) + (0x910))
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS0_ADDR(base) ((base) + (0x914))
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS1_ADDR(base) ((base) + (0x918))
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS2_ADDR(base) ((base) + (0x91C))
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS3_ADDR(base) ((base) + (0x0920))
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS0_ADDR(base) ((base) + (0x924))
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS1_ADDR(base) ((base) + (0x928))
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS2_ADDR(base) ((base) + (0x92C))
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS3_ADDR(base) ((base) + (0x0930))
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS0_ADDR(base) ((base) + (0x934))
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS1_ADDR(base) ((base) + (0x938))
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS2_ADDR(base) ((base) + (0x93C))
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS3_ADDR(base) ((base) + (0x940))
#define SOC_CPU_RTM_DFX_SIG_MON_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x948))
#define SOC_CPU_RTM_DFX_RTM_TRACE_SAMPLE_ADDR(base) ((base) + (0x0980))
#define SOC_CPU_RTM_DFX_RTM_TRACE_GEN_ADDR(base) ((base) + (0x0984))
#define SOC_CPU_RTM_DFX_RTM_TRACE_MST_ADDR(base) ((base) + (0x0988))
#define SOC_CPU_RTM_DFX_RTM_BUFFER_ADDR(base) ((base) + (0x098C))
#define SOC_CPU_RTM_DFX_DMA_NEXT_SDMA_ADDR_ADDR(base) ((base) + (0x0990))
#define SOC_CPU_RTM_DFX_DMA_NEXT_ADMA_ADDR_L_ADDR(base) ((base) + (0x0994))
#define SOC_CPU_RTM_DFX_DMA_NEXT_ADMA_ADDR_H_ADDR(base) ((base) + (0x0998))
#define SOC_CPU_RTM_DFX_DMA_AXI_TRANSFER_CNT_ADDR(base) ((base) + (0x099C))
#define SOC_CPU_RTM_DFX_DMA_BLOCK_VALUE_ADDR(base) ((base) + (0x09A0))
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_0_ADDR(base) ((base) + (0x09A4))
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_1_ADDR(base) ((base) + (0x09A8))
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_2_ADDR(base) ((base) + (0x09AC))
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_3_ADDR(base) ((base) + (0x09B0))
#define SOC_CPU_RTM_DFX_DMA_BUFFER_ADDR_ADDR(base) ((base) + (0x09B4))
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_ADDR_L_ADDR(base) ((base) + (0x09B8))
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_ADDR_H_ADDR(base) ((base) + (0x09BC))
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_OTHERS_ADDR(base) ((base) + (0x09C0))
#define SOC_CPU_RTM_DFX_DMA_NEXT_SDMA_DESCR_ADDR_ADDR(base) ((base) + (0x09C4))
#define SOC_CPU_RTM_DFX_DMA_NEXT_ADMA_DESCR_ADDR_L_ADDR(base) ((base) + (0x09C8))
#define SOC_CPU_RTM_DFX_DMA_NEXT_ADMA_DESCR_ADDR_H_ADDR(base) ((base) + (0x09CC))
#define SOC_CPU_RTM_DFX_DMA_ADMA_DESCR_LEN_LEFT_ADDR(base) ((base) + (0x09D0))
#define SOC_CPU_RTM_DFX_DMA_CONTX_TABLE_VALUE_ADDR(base) ((base) + (0x09D4))
#define SOC_CPU_RTM_DFX_DMA_RESP_ERROR_INFO_ADDR(base) ((base) + (0x09D8))
#define SOC_CPU_RTM_DFX_DMA_AXI_SD_BUFFER_ADDR_ADDR(base) ((base) + (0x09DC))
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0x9E0))
#define SOC_CPU_RTM_DFX_RTM_TASK_CTRL_0_ADDR(base) ((base) + (0x0A18))
#define SOC_CPU_RTM_DFX_RTM_TASK_CTRL_1_ADDR(base) ((base) + (0x0A1C))
#define SOC_CPU_RTM_DFX_DMA_TP_ADDR(base) ((base) + (0x0A20))
#define SOC_CPU_RTM_TEST_POINT_SEL_ADDR(base) ((base) + (0x0A24))
#define SOC_CPU_RTM_HARD_SAMP_EN_TIME_L_ADDR(base) ((base) + (0x0A28))
#define SOC_CPU_RTM_HARD_SAMP_EN_TIME_H_ADDR(base) ((base) + (0x0A2C))
#define SOC_CPU_RTM_HARD_TS_EN_TIME_L_ADDR(base) ((base) + (0x0A30))
#define SOC_CPU_RTM_HARD_TS_EN_TIME_H_ADDR(base) ((base) + (0x0A34))
#define SOC_CPU_RTM_EVENT_INDEX_VALID_ADDR(base,sig_mon_num) ((base) + ((sig_mon_num)*0x4+0xA38))
#define SOC_CPU_RTM_RTM_PROCESS_IDLE_ADDR(base) ((base) + (0x0A70))
#define SOC_CPU_RTM_RTM_CKG_BYPASS_ADDR(base) ((base) + (0x0A74))
#define SOC_CPU_RTM_RTM_CKG_WAKEUP_EN_ADDR(base) ((base) + (0x0A78))
#define SOC_CPU_RTM_RTM_CKG_BUSY_ADDR(base) ((base) + (0x0A7C))
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ADDR(base) ((base) + (0x0A80))
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ADDR(base) ((base) + (0x0A84))
#define SOC_CPU_RTM_AXI_CONF_ADDR(base) ((base) + (0x0A88))
#define SOC_CPU_RTM_LATENCY_CNT_SOFTWARE_RESET_ADDR(base) ((base) + (0x0B00))
#define SOC_CPU_RTM_LATENCY_CNT_CONFIG1_ADDR(base) ((base) + (0x0B04))
#define SOC_CPU_RTM_LATENCY_CNT_CONFIG2_ADDR(base) ((base) + (0x0B08))
#define SOC_CPU_RTM_LATENCY_CNT_CONFIG3_ADDR(base) ((base) + (0x0B0C))
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG1_ADDR(base) ((base) + (0x0B10))
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG2_ADDR(base) ((base) + (0x0B14))
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG3_ADDR(base) ((base) + (0x0B18))
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG4_ADDR(base) ((base) + (0x0B1C))
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS0_ADDR(base) ((base) + (0x0B20))
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS1_ADDR(base) ((base) + (0x0B24))
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS2_ADDR(base) ((base) + (0x0B28))
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS3_ADDR(base) ((base) + (0x0B2C))
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS0_ADDR(base) ((base) + (0x0B30))
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS1_ADDR(base) ((base) + (0x0B34))
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS2_ADDR(base) ((base) + (0x0B38))
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS3_ADDR(base) ((base) + (0x0B3C))
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS0_ADDR(base) ((base) + (0x0B40))
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS1_ADDR(base) ((base) + (0x0B44))
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS2_ADDR(base) ((base) + (0x0B48))
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS3_ADDR(base) ((base) + (0x0B4C))
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS0_ADDR(base) ((base) + (0x0B50))
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS1_ADDR(base) ((base) + (0x0B54))
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS2_ADDR(base) ((base) + (0x0B58))
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS3_ADDR(base) ((base) + (0x0B5C))
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS0_ADDR(base) ((base) + (0x0B60))
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS1_ADDR(base) ((base) + (0x0B64))
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS2_ADDR(base) ((base) + (0x0B68))
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS3_ADDR(base) ((base) + (0x0B6C))
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS0_ADDR(base) ((base) + (0x0B70))
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS1_ADDR(base) ((base) + (0x0B74))
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS2_ADDR(base) ((base) + (0x0B78))
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS3_ADDR(base) ((base) + (0x0B7C))
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS0_ADDR(base) ((base) + (0x0B80))
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS1_ADDR(base) ((base) + (0x0B84))
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS2_ADDR(base) ((base) + (0x0B88))
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS3_ADDR(base) ((base) + (0x0B8C))
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS0_ADDR(base) ((base) + (0x0B90))
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS1_ADDR(base) ((base) + (0x0B94))
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS2_ADDR(base) ((base) + (0x0B98))
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS3_ADDR(base) ((base) + (0x0B9C))
#define SOC_CPU_RTM_LATENCY_CNT_EVENT_STATE_ADDR(base) ((base) + (0x0BA0))
#define SOC_CPU_RTM_LATENCY_CNT_EVENT_CLR_ADDR(base) ((base) + (0x0BA4))
#define SOC_CPU_RTM_LATENCY_INT_LPID_ADDR(base) ((base) + (0x0BA8))
#define SOC_CPU_RTM_LATENCY_INT_CNT0_ADDR(base) ((base) + (0x0BAC))
#define SOC_CPU_RTM_LATENCY_INT_CNT1_ADDR(base) ((base) + (0x0BB0))
#define SOC_CPU_RTM_LATENCY_INT_CNT2_ADDR(base) ((base) + (0x0BB4))
#define SOC_CPU_RTM_LATENCY_INT_CNT3_ADDR(base) ((base) + (0x0BB8))
#define SOC_CPU_RTM_LATENCY_INT_CNT4_ADDR(base) ((base) + (0x0BBC))
#define SOC_CPU_RTM_LATENCY_INT_CNT5_ADDR(base) ((base) + (0x0BC0))
#define SOC_CPU_RTM_LATENCY_INT_CNT6_ADDR(base) ((base) + (0x0BC4))
#define SOC_CPU_RTM_LATENCY_INT_CNT7_ADDR(base) ((base) + (0x0BC8))
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG5_ADDR(base) ((base) + (0x0BCC))
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG6_ADDR(base) ((base) + (0x0BD0))
#define SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO0_ADDR(base) ((base) + (0x0BD4))
#define SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO1_ADDR(base) ((base) + (0x0BD8))
#define SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO2_ADDR(base) ((base) + (0x0BDC))
#define SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO3_ADDR(base) ((base) + (0x0BE0))
#define SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO4_ADDR(base) ((base) + (0x0BE4))
#define SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO5_ADDR(base) ((base) + (0x0BE8))
#define SOC_CPU_RTM_MNT_DEBUG_EN_ADDR(base) ((base) + (0xC00))
#define SOC_CPU_RTM_MNT_DEBUG_SYNC_ALIGN_COUNT_ADDR(base) ((base) + (0xC04))
#define SOC_CPU_RTM_MNT_DEBUG_CNT_ADDR(base,debug_info_num) ((base) + ((debug_info_num)*0x4+0xC08))
#define SOC_CPU_RTM_RTM_SYNC_CFG14_1_ADDR(base) ((base) + (0xCB8))
#define SOC_CPU_RTM_RTM_SYNC_CFG15_1_ADDR(base) ((base) + (0xCBC))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID14_1_ADDR(base) ((base) + (0xCD4))
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID15_1_ADDR(base) ((base) + (0xCD8))
#define SOC_CPU_RTM_RTM_INT1_STATE_14_1_ADDR(base) ((base) + (0xCF0))
#define SOC_CPU_RTM_RTM_INT1_STATE_15_1_ADDR(base) ((base) + (0xCF4))
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_14_1_ADDR(base) ((base) + (0xD0C))
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_15_1_ADDR(base) ((base) + (0xD10))
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_14_1_ADDR(base) ((base) + (0xD28))
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_15_1_ADDR(base) ((base) + (0xD2C))
#define SOC_CPU_RTM_RTM_INT2_STATE_14_1_ADDR(base) ((base) + (0xD40))
#define SOC_CPU_RTM_RTM_INT2_STATE_15_1_ADDR(base) ((base) + (0xD44))
#define SOC_CPU_RTM_RTM_INT2_STATE_ENABLE_14_1_ADDR(base) ((base) + (0xD5C))
#define SOC_CPU_RTM_RTM_INT2_STATE_ENABLE_15_1_ADDR(base) ((base) + (0xD60))
#define SOC_CPU_RTM_RTM_INT2_SINGAL_ENABLE_14_1_ADDR(base) ((base) + (0xD78))
#define SOC_CPU_RTM_RTM_INT2_SINGAL_ENABLE_15_1_ADDR(base) ((base) + (0xD7C))
#define SOC_CPU_RTM_CFG_PERIOD_EVENT_MSK_14_1_ADDR(base) ((base) + (0xDD4))
#define SOC_CPU_RTM_CFG_PERIOD_EVENT_MSK_15_1_ADDR(base) ((base) + (0xDD8))
#define SOC_CPU_RTM_CFG_PERIOD_EVENT_TS_0_14_1_ADDR(base) ((base) + (0xDF0))
#define SOC_CPU_RTM_CFG_PERIOD_EVENT_TS_0_15_1_ADDR(base) ((base) + (0xDF4))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_0_14_1_ADDR(base) ((base) + (0xE0C))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_0_15_1_ADDR(base) ((base) + (0xE10))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_1_14_1_ADDR(base) ((base) + (0xE28))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_1_15_1_ADDR(base) ((base) + (0xE2C))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_2_14_1_ADDR(base) ((base) + (0xE44))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_2_15_1_ADDR(base) ((base) + (0xE48))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_3_14_1_ADDR(base) ((base) + (0xE60))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_3_15_1_ADDR(base) ((base) + (0xE64))
#define SOC_CPU_RTM_CFG_FILTER_CTRL_14_1_ADDR(base) ((base) + (0xE7C))
#define SOC_CPU_RTM_CFG_FILTER_CTRL_15_1_ADDR(base) ((base) + (0xE80))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_MSK_14_1_ADDR(base) ((base) + (0xE98))
#define SOC_CPU_RTM_CFG_HEADER_FILTER_MSK_15_1_ADDR(base) ((base) + (0xE9C))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_MSK_14_1_ADDR(base) ((base) + (0xEB4))
#define SOC_CPU_RTM_CFG_TRACE_FILTER_MSK_15_1_ADDR(base) ((base) + (0xEB8))
#define SOC_CPU_RTM_DFX_SIG_MON_14_1_ADDR(base) ((base) + (0xED0))
#define SOC_CPU_RTM_DFX_SIG_MON_15_1_ADDR(base) ((base) + (0xED4))
#define SOC_CPU_RTM_EVENT_INDEX_VALID_14_1_ADDR(base) ((base) + (0xEEC))
#define SOC_CPU_RTM_EVENT_INDEX_VALID_15_1_ADDR(base) ((base) + (0xEF0))
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_14_1_ADDR(base) ((base) + (0xF08))
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_15_1_ADDR(base) ((base) + (0xF0C))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_EN_ADDR(base) ((base) + (0xF24))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID0_ADDR(base) ((base) + (0xF28))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID1_ADDR(base) ((base) + (0xF2C))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID2_ADDR(base) ((base) + (0xF30))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_3_ADDR(base) ((base) + (0xF34))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_4_ADDR(base) ((base) + (0xF38))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_5_ADDR(base) ((base) + (0xF3C))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_6_ADDR(base) ((base) + (0xF40))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_7_ADDR(base) ((base) + (0xF44))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_8_ADDR(base) ((base) + (0xF48))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_9_ADDR(base) ((base) + (0xF4C))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_10_ADDR(base) ((base) + (0xF50))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_11_ADDR(base) ((base) + (0xF54))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_12_ADDR(base) ((base) + (0xF58))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_13_ADDR(base) ((base) + (0xF5C))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_14_ADDR(base) ((base) + (0xF60))
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_15_ADDR(base) ((base) + (0xF64))
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS0_ADDR(base) ((base) + (0xF80))
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS1_ADDR(base) ((base) + (0xF84))
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS2_ADDR(base) ((base) + (0xF88))
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS3_ADDR(base) ((base) + (0xF8C))
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS0_ADDR(base) ((base) + (0xF90))
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS1_ADDR(base) ((base) + (0xF94))
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS2_ADDR(base) ((base) + (0xF98))
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS3_ADDR(base) ((base) + (0xF9C))
#define SOC_CPU_RTM_QoS_Sync_en_ADDR(base) ((base) + (0xFA0))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtm_mode : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_CPU_RTM_RTM_CTRL_UNION;
#endif
#define SOC_CPU_RTM_RTM_CTRL_rtm_mode_START (0)
#define SOC_CPU_RTM_RTM_CTRL_rtm_mode_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CPU_RTM_DMA_EN_UNION;
#endif
#define SOC_CPU_RTM_DMA_EN_dma_en_START (0)
#define SOC_CPU_RTM_DMA_EN_dma_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int software_reset : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CPU_RTM_SOFTWARE_RESET_UNION;
#endif
#define SOC_CPU_RTM_SOFTWARE_RESET_software_reset_START (0)
#define SOC_CPU_RTM_SOFTWARE_RESET_software_reset_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int flush_en : 1;
        unsigned int handshakeon_bypass : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CPU_RTM_RTM_FLUSH_UNION;
#endif
#define SOC_CPU_RTM_RTM_FLUSH_flush_en_START (0)
#define SOC_CPU_RTM_RTM_FLUSH_flush_en_END (0)
#define SOC_CPU_RTM_RTM_FLUSH_handshakeon_bypass_START (1)
#define SOC_CPU_RTM_RTM_FLUSH_handshakeon_bypass_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_select : 2;
        unsigned int sdma_buffer_boundary : 3;
        unsigned int reserved : 27;
    } reg;
} SOC_CPU_RTM_DMA_CTRL_UNION;
#endif
#define SOC_CPU_RTM_DMA_CTRL_dma_select_START (0)
#define SOC_CPU_RTM_DMA_CTRL_dma_select_END (1)
#define SOC_CPU_RTM_DMA_CTRL_sdma_buffer_boundary_START (2)
#define SOC_CPU_RTM_DMA_CTRL_sdma_buffer_boundary_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sdma_addr_update : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CPU_RTM_SDMA_ADDR_UPDATE_UNION;
#endif
#define SOC_CPU_RTM_SDMA_ADDR_UPDATE_sdma_addr_update_START (0)
#define SOC_CPU_RTM_SDMA_ADDR_UPDATE_sdma_addr_update_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_dma_dfx_sel : 32;
    } reg;
} SOC_CPU_RTM_CFG_DMA_DFX_SEL_UNION;
#endif
#define SOC_CPU_RTM_CFG_DMA_DFX_SEL_cfg_dma_dfx_sel_START (0)
#define SOC_CPU_RTM_CFG_DMA_DFX_SEL_cfg_dma_dfx_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sdma_addr_arg_l : 32;
    } reg;
} SOC_CPU_RTM_SDMA_ADDR_ARG_L_UNION;
#endif
#define SOC_CPU_RTM_SDMA_ADDR_ARG_L_sdma_addr_arg_l_START (0)
#define SOC_CPU_RTM_SDMA_ADDR_ARG_L_sdma_addr_arg_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sdma_addr_arg_h : 32;
    } reg;
} SOC_CPU_RTM_SDMA_ADDR_ARG_H_UNION;
#endif
#define SOC_CPU_RTM_SDMA_ADDR_ARG_H_sdma_addr_arg_h_START (0)
#define SOC_CPU_RTM_SDMA_ADDR_ARG_H_sdma_addr_arg_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adma_system_addr_0_l : 32;
    } reg;
} SOC_CPU_RTM_ADMA_SYSTEM_ADDR_0_L_UNION;
#endif
#define SOC_CPU_RTM_ADMA_SYSTEM_ADDR_0_L_adma_system_addr_0_l_START (0)
#define SOC_CPU_RTM_ADMA_SYSTEM_ADDR_0_L_adma_system_addr_0_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adma_system_addr_0_h : 32;
    } reg;
} SOC_CPU_RTM_ADMA_SYSTEM_ADDR_0_H_UNION;
#endif
#define SOC_CPU_RTM_ADMA_SYSTEM_ADDR_0_H_adma_system_addr_0_h_START (0)
#define SOC_CPU_RTM_ADMA_SYSTEM_ADDR_0_H_adma_system_addr_0_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adma_system_addr_1_l : 32;
    } reg;
} SOC_CPU_RTM_ADMA_SYSTEM_ADDR_1_L_UNION;
#endif
#define SOC_CPU_RTM_ADMA_SYSTEM_ADDR_1_L_adma_system_addr_1_l_START (0)
#define SOC_CPU_RTM_ADMA_SYSTEM_ADDR_1_L_adma_system_addr_1_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adma_system_addr_1_h : 32;
    } reg;
} SOC_CPU_RTM_ADMA_SYSTEM_ADDR_1_H_UNION;
#endif
#define SOC_CPU_RTM_ADMA_SYSTEM_ADDR_1_H_adma_system_addr_1_h_START (0)
#define SOC_CPU_RTM_ADMA_SYSTEM_ADDR_1_H_adma_system_addr_1_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adma_system_addr_2_l : 32;
    } reg;
} SOC_CPU_RTM_ADMA_SYSTEM_ADDR_2_L_UNION;
#endif
#define SOC_CPU_RTM_ADMA_SYSTEM_ADDR_2_L_adma_system_addr_2_l_START (0)
#define SOC_CPU_RTM_ADMA_SYSTEM_ADDR_2_L_adma_system_addr_2_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adma_system_addr_2_h : 32;
    } reg;
} SOC_CPU_RTM_ADMA_SYSTEM_ADDR_2_H_UNION;
#endif
#define SOC_CPU_RTM_ADMA_SYSTEM_ADDR_2_H_adma_system_addr_2_h_START (0)
#define SOC_CPU_RTM_ADMA_SYSTEM_ADDR_2_H_adma_system_addr_2_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adma_blk_count_0 : 16;
        unsigned int adma_blk_count_1 : 16;
    } reg;
} SOC_CPU_RTM_ADMA_BLK_COUNT_1_0_UNION;
#endif
#define SOC_CPU_RTM_ADMA_BLK_COUNT_1_0_adma_blk_count_0_START (0)
#define SOC_CPU_RTM_ADMA_BLK_COUNT_1_0_adma_blk_count_0_END (15)
#define SOC_CPU_RTM_ADMA_BLK_COUNT_1_0_adma_blk_count_1_START (16)
#define SOC_CPU_RTM_ADMA_BLK_COUNT_1_0_adma_blk_count_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adma_blk_count_2 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CPU_RTM_ADMA_BLK_COUNT_2_UNION;
#endif
#define SOC_CPU_RTM_ADMA_BLK_COUNT_2_adma_blk_count_2_START (0)
#define SOC_CPU_RTM_ADMA_BLK_COUNT_2_adma_blk_count_2_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adma_blk_size : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_CPU_RTM_ADMA_BLK_SIZE_UNION;
#endif
#define SOC_CPU_RTM_ADMA_BLK_SIZE_adma_blk_size_START (0)
#define SOC_CPU_RTM_ADMA_BLK_SIZE_adma_blk_size_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtm_mem_ctrl : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CPU_RTM_RTM_MEM_CTRL_UNION;
#endif
#define SOC_CPU_RTM_RTM_MEM_CTRL_rtm_mem_ctrl_START (0)
#define SOC_CPU_RTM_RTM_MEM_CTRL_rtm_mem_ctrl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int partition_read_point : 2;
        unsigned int partition_write_point : 2;
        unsigned int partition_ready_count : 3;
        unsigned int partition_full : 1;
        unsigned int partition_empty : 1;
        unsigned int reserved : 7;
        unsigned int last_block_count : 16;
    } reg;
} SOC_CPU_RTM_RTM_DMA_STATE_UNION;
#endif
#define SOC_CPU_RTM_RTM_DMA_STATE_partition_read_point_START (0)
#define SOC_CPU_RTM_RTM_DMA_STATE_partition_read_point_END (1)
#define SOC_CPU_RTM_RTM_DMA_STATE_partition_write_point_START (2)
#define SOC_CPU_RTM_RTM_DMA_STATE_partition_write_point_END (3)
#define SOC_CPU_RTM_RTM_DMA_STATE_partition_ready_count_START (4)
#define SOC_CPU_RTM_RTM_DMA_STATE_partition_ready_count_END (6)
#define SOC_CPU_RTM_RTM_DMA_STATE_partition_full_START (7)
#define SOC_CPU_RTM_RTM_DMA_STATE_partition_full_END (7)
#define SOC_CPU_RTM_RTM_DMA_STATE_partition_empty_START (8)
#define SOC_CPU_RTM_RTM_DMA_STATE_partition_empty_END (8)
#define SOC_CPU_RTM_RTM_DMA_STATE_last_block_count_START (16)
#define SOC_CPU_RTM_RTM_DMA_STATE_last_block_count_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int apb_rd_pointer_done_done : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CPU_RTM_APB_RD_POINTER_DONE_UNION;
#endif
#define SOC_CPU_RTM_APB_RD_POINTER_DONE_apb_rd_pointer_done_done_START (0)
#define SOC_CPU_RTM_APB_RD_POINTER_DONE_apb_rd_pointer_done_done_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_sync_max_cnt0 : 10;
        unsigned int reserved_0 : 5;
        unsigned int dbg_en_cnt0 : 1;
        unsigned int cfg_sync_dly_cnt0 : 14;
        unsigned int reserved_1 : 1;
        unsigned int cfg_sync_en0 : 1;
    } reg;
} SOC_CPU_RTM_RTM_SYNC_CFG0_UNION;
#endif
#define SOC_CPU_RTM_RTM_SYNC_CFG0_cfg_sync_max_cnt0_START (0)
#define SOC_CPU_RTM_RTM_SYNC_CFG0_cfg_sync_max_cnt0_END (9)
#define SOC_CPU_RTM_RTM_SYNC_CFG0_dbg_en_cnt0_START (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG0_dbg_en_cnt0_END (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG0_cfg_sync_dly_cnt0_START (16)
#define SOC_CPU_RTM_RTM_SYNC_CFG0_cfg_sync_dly_cnt0_END (29)
#define SOC_CPU_RTM_RTM_SYNC_CFG0_cfg_sync_en0_START (31)
#define SOC_CPU_RTM_RTM_SYNC_CFG0_cfg_sync_en0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_sync_max_cnt1 : 10;
        unsigned int reserved_0 : 5;
        unsigned int dbg_en_cnt1 : 1;
        unsigned int cfg_sync_dly_cnt1 : 14;
        unsigned int reserved_1 : 1;
        unsigned int cfg_sync_en1 : 1;
    } reg;
} SOC_CPU_RTM_RTM_SYNC_CFG1_UNION;
#endif
#define SOC_CPU_RTM_RTM_SYNC_CFG1_cfg_sync_max_cnt1_START (0)
#define SOC_CPU_RTM_RTM_SYNC_CFG1_cfg_sync_max_cnt1_END (9)
#define SOC_CPU_RTM_RTM_SYNC_CFG1_dbg_en_cnt1_START (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG1_dbg_en_cnt1_END (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG1_cfg_sync_dly_cnt1_START (16)
#define SOC_CPU_RTM_RTM_SYNC_CFG1_cfg_sync_dly_cnt1_END (29)
#define SOC_CPU_RTM_RTM_SYNC_CFG1_cfg_sync_en1_START (31)
#define SOC_CPU_RTM_RTM_SYNC_CFG1_cfg_sync_en1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_sync_max_cnt2 : 10;
        unsigned int reserved_0 : 5;
        unsigned int dbg_en_cnt2 : 1;
        unsigned int cfg_sync_dly_cnt2 : 14;
        unsigned int reserved_1 : 1;
        unsigned int cfg_sync_en2 : 1;
    } reg;
} SOC_CPU_RTM_RTM_SYNC_CFG2_UNION;
#endif
#define SOC_CPU_RTM_RTM_SYNC_CFG2_cfg_sync_max_cnt2_START (0)
#define SOC_CPU_RTM_RTM_SYNC_CFG2_cfg_sync_max_cnt2_END (9)
#define SOC_CPU_RTM_RTM_SYNC_CFG2_dbg_en_cnt2_START (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG2_dbg_en_cnt2_END (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG2_cfg_sync_dly_cnt2_START (16)
#define SOC_CPU_RTM_RTM_SYNC_CFG2_cfg_sync_dly_cnt2_END (29)
#define SOC_CPU_RTM_RTM_SYNC_CFG2_cfg_sync_en2_START (31)
#define SOC_CPU_RTM_RTM_SYNC_CFG2_cfg_sync_en2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_sync_max_cnt3 : 10;
        unsigned int reserved_0 : 5;
        unsigned int dbg_en_cnt3 : 1;
        unsigned int cfg_sync_dly_cnt3 : 14;
        unsigned int reserved_1 : 1;
        unsigned int cfg_sync_en3 : 1;
    } reg;
} SOC_CPU_RTM_RTM_SYNC_CFG3_UNION;
#endif
#define SOC_CPU_RTM_RTM_SYNC_CFG3_cfg_sync_max_cnt3_START (0)
#define SOC_CPU_RTM_RTM_SYNC_CFG3_cfg_sync_max_cnt3_END (9)
#define SOC_CPU_RTM_RTM_SYNC_CFG3_dbg_en_cnt3_START (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG3_dbg_en_cnt3_END (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG3_cfg_sync_dly_cnt3_START (16)
#define SOC_CPU_RTM_RTM_SYNC_CFG3_cfg_sync_dly_cnt3_END (29)
#define SOC_CPU_RTM_RTM_SYNC_CFG3_cfg_sync_en3_START (31)
#define SOC_CPU_RTM_RTM_SYNC_CFG3_cfg_sync_en3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_sync_max_cnt4 : 10;
        unsigned int reserved_0 : 5;
        unsigned int dbg_en_cnt4 : 1;
        unsigned int cfg_sync_dly_cnt4 : 14;
        unsigned int reserved_1 : 1;
        unsigned int cfg_sync_en4 : 1;
    } reg;
} SOC_CPU_RTM_RTM_SYNC_CFG4_UNION;
#endif
#define SOC_CPU_RTM_RTM_SYNC_CFG4_cfg_sync_max_cnt4_START (0)
#define SOC_CPU_RTM_RTM_SYNC_CFG4_cfg_sync_max_cnt4_END (9)
#define SOC_CPU_RTM_RTM_SYNC_CFG4_dbg_en_cnt4_START (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG4_dbg_en_cnt4_END (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG4_cfg_sync_dly_cnt4_START (16)
#define SOC_CPU_RTM_RTM_SYNC_CFG4_cfg_sync_dly_cnt4_END (29)
#define SOC_CPU_RTM_RTM_SYNC_CFG4_cfg_sync_en4_START (31)
#define SOC_CPU_RTM_RTM_SYNC_CFG4_cfg_sync_en4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_sync_max_cnt5 : 10;
        unsigned int reserved_0 : 5;
        unsigned int dbg_en_cnt5 : 1;
        unsigned int cfg_sync_dly_cnt5 : 14;
        unsigned int reserved_1 : 1;
        unsigned int cfg_sync_en5 : 1;
    } reg;
} SOC_CPU_RTM_RTM_SYNC_CFG5_UNION;
#endif
#define SOC_CPU_RTM_RTM_SYNC_CFG5_cfg_sync_max_cnt5_START (0)
#define SOC_CPU_RTM_RTM_SYNC_CFG5_cfg_sync_max_cnt5_END (9)
#define SOC_CPU_RTM_RTM_SYNC_CFG5_dbg_en_cnt5_START (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG5_dbg_en_cnt5_END (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG5_cfg_sync_dly_cnt5_START (16)
#define SOC_CPU_RTM_RTM_SYNC_CFG5_cfg_sync_dly_cnt5_END (29)
#define SOC_CPU_RTM_RTM_SYNC_CFG5_cfg_sync_en5_START (31)
#define SOC_CPU_RTM_RTM_SYNC_CFG5_cfg_sync_en5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_sync_max_cnt6 : 10;
        unsigned int reserved_0 : 5;
        unsigned int dbg_en_cnt6 : 1;
        unsigned int cfg_sync_dly_cnt6 : 14;
        unsigned int reserved_1 : 1;
        unsigned int cfg_sync_en6 : 1;
    } reg;
} SOC_CPU_RTM_RTM_SYNC_CFG6_UNION;
#endif
#define SOC_CPU_RTM_RTM_SYNC_CFG6_cfg_sync_max_cnt6_START (0)
#define SOC_CPU_RTM_RTM_SYNC_CFG6_cfg_sync_max_cnt6_END (9)
#define SOC_CPU_RTM_RTM_SYNC_CFG6_dbg_en_cnt6_START (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG6_dbg_en_cnt6_END (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG6_cfg_sync_dly_cnt6_START (16)
#define SOC_CPU_RTM_RTM_SYNC_CFG6_cfg_sync_dly_cnt6_END (29)
#define SOC_CPU_RTM_RTM_SYNC_CFG6_cfg_sync_en6_START (31)
#define SOC_CPU_RTM_RTM_SYNC_CFG6_cfg_sync_en6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_sync_max_cnt7 : 10;
        unsigned int reserved_0 : 5;
        unsigned int dbg_en_cnt7 : 1;
        unsigned int cfg_sync_dly_cnt7 : 14;
        unsigned int reserved_1 : 1;
        unsigned int cfg_sync_en7 : 1;
    } reg;
} SOC_CPU_RTM_RTM_SYNC_CFG7_UNION;
#endif
#define SOC_CPU_RTM_RTM_SYNC_CFG7_cfg_sync_max_cnt7_START (0)
#define SOC_CPU_RTM_RTM_SYNC_CFG7_cfg_sync_max_cnt7_END (9)
#define SOC_CPU_RTM_RTM_SYNC_CFG7_dbg_en_cnt7_START (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG7_dbg_en_cnt7_END (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG7_cfg_sync_dly_cnt7_START (16)
#define SOC_CPU_RTM_RTM_SYNC_CFG7_cfg_sync_dly_cnt7_END (29)
#define SOC_CPU_RTM_RTM_SYNC_CFG7_cfg_sync_en7_START (31)
#define SOC_CPU_RTM_RTM_SYNC_CFG7_cfg_sync_en7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_sync_max_cnt8 : 10;
        unsigned int reserved_0 : 5;
        unsigned int dbg_en_cnt8 : 1;
        unsigned int cfg_sync_dly_cnt8 : 14;
        unsigned int reserved_1 : 1;
        unsigned int cfg_sync_en8 : 1;
    } reg;
} SOC_CPU_RTM_RTM_SYNC_CFG8_UNION;
#endif
#define SOC_CPU_RTM_RTM_SYNC_CFG8_cfg_sync_max_cnt8_START (0)
#define SOC_CPU_RTM_RTM_SYNC_CFG8_cfg_sync_max_cnt8_END (9)
#define SOC_CPU_RTM_RTM_SYNC_CFG8_dbg_en_cnt8_START (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG8_dbg_en_cnt8_END (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG8_cfg_sync_dly_cnt8_START (16)
#define SOC_CPU_RTM_RTM_SYNC_CFG8_cfg_sync_dly_cnt8_END (29)
#define SOC_CPU_RTM_RTM_SYNC_CFG8_cfg_sync_en8_START (31)
#define SOC_CPU_RTM_RTM_SYNC_CFG8_cfg_sync_en8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_sync_max_cnt9 : 10;
        unsigned int reserved_0 : 5;
        unsigned int dbg_en_cnt9 : 1;
        unsigned int cfg_sync_dly_cnt9 : 14;
        unsigned int reserved_1 : 1;
        unsigned int cfg_sync_en9 : 1;
    } reg;
} SOC_CPU_RTM_RTM_SYNC_CFG9_UNION;
#endif
#define SOC_CPU_RTM_RTM_SYNC_CFG9_cfg_sync_max_cnt9_START (0)
#define SOC_CPU_RTM_RTM_SYNC_CFG9_cfg_sync_max_cnt9_END (9)
#define SOC_CPU_RTM_RTM_SYNC_CFG9_dbg_en_cnt9_START (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG9_dbg_en_cnt9_END (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG9_cfg_sync_dly_cnt9_START (16)
#define SOC_CPU_RTM_RTM_SYNC_CFG9_cfg_sync_dly_cnt9_END (29)
#define SOC_CPU_RTM_RTM_SYNC_CFG9_cfg_sync_en9_START (31)
#define SOC_CPU_RTM_RTM_SYNC_CFG9_cfg_sync_en9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_sync_max_cnt10 : 10;
        unsigned int reserved_0 : 5;
        unsigned int dbg_en_cnt10 : 1;
        unsigned int cfg_sync_dly_cnt10 : 14;
        unsigned int reserved_1 : 1;
        unsigned int cfg_sync_en10 : 1;
    } reg;
} SOC_CPU_RTM_RTM_SYNC_CFG10_UNION;
#endif
#define SOC_CPU_RTM_RTM_SYNC_CFG10_cfg_sync_max_cnt10_START (0)
#define SOC_CPU_RTM_RTM_SYNC_CFG10_cfg_sync_max_cnt10_END (9)
#define SOC_CPU_RTM_RTM_SYNC_CFG10_dbg_en_cnt10_START (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG10_dbg_en_cnt10_END (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG10_cfg_sync_dly_cnt10_START (16)
#define SOC_CPU_RTM_RTM_SYNC_CFG10_cfg_sync_dly_cnt10_END (29)
#define SOC_CPU_RTM_RTM_SYNC_CFG10_cfg_sync_en10_START (31)
#define SOC_CPU_RTM_RTM_SYNC_CFG10_cfg_sync_en10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_sync_max_cnt11 : 10;
        unsigned int reserved_0 : 5;
        unsigned int dbg_en_cnt11 : 1;
        unsigned int cfg_sync_dly_cnt11 : 14;
        unsigned int reserved_1 : 1;
        unsigned int cfg_sync_en11 : 1;
    } reg;
} SOC_CPU_RTM_RTM_SYNC_CFG11_UNION;
#endif
#define SOC_CPU_RTM_RTM_SYNC_CFG11_cfg_sync_max_cnt11_START (0)
#define SOC_CPU_RTM_RTM_SYNC_CFG11_cfg_sync_max_cnt11_END (9)
#define SOC_CPU_RTM_RTM_SYNC_CFG11_dbg_en_cnt11_START (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG11_dbg_en_cnt11_END (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG11_cfg_sync_dly_cnt11_START (16)
#define SOC_CPU_RTM_RTM_SYNC_CFG11_cfg_sync_dly_cnt11_END (29)
#define SOC_CPU_RTM_RTM_SYNC_CFG11_cfg_sync_en11_START (31)
#define SOC_CPU_RTM_RTM_SYNC_CFG11_cfg_sync_en11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_sync_max_cnt12 : 10;
        unsigned int reserved_0 : 5;
        unsigned int dbg_en_cnt12 : 1;
        unsigned int cfg_sync_dly_cnt12 : 14;
        unsigned int reserved_1 : 1;
        unsigned int cfg_sync_en12 : 1;
    } reg;
} SOC_CPU_RTM_RTM_SYNC_CFG12_UNION;
#endif
#define SOC_CPU_RTM_RTM_SYNC_CFG12_cfg_sync_max_cnt12_START (0)
#define SOC_CPU_RTM_RTM_SYNC_CFG12_cfg_sync_max_cnt12_END (9)
#define SOC_CPU_RTM_RTM_SYNC_CFG12_dbg_en_cnt12_START (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG12_dbg_en_cnt12_END (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG12_cfg_sync_dly_cnt12_START (16)
#define SOC_CPU_RTM_RTM_SYNC_CFG12_cfg_sync_dly_cnt12_END (29)
#define SOC_CPU_RTM_RTM_SYNC_CFG12_cfg_sync_en12_START (31)
#define SOC_CPU_RTM_RTM_SYNC_CFG12_cfg_sync_en12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_sync_max_cnt13 : 10;
        unsigned int reserved_0 : 5;
        unsigned int dbg_en_cnt13 : 1;
        unsigned int cfg_sync_dly_cnt13 : 14;
        unsigned int reserved_1 : 1;
        unsigned int cfg_sync_en13 : 1;
    } reg;
} SOC_CPU_RTM_RTM_SYNC_CFG13_UNION;
#endif
#define SOC_CPU_RTM_RTM_SYNC_CFG13_cfg_sync_max_cnt13_START (0)
#define SOC_CPU_RTM_RTM_SYNC_CFG13_cfg_sync_max_cnt13_END (9)
#define SOC_CPU_RTM_RTM_SYNC_CFG13_dbg_en_cnt13_START (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG13_dbg_en_cnt13_END (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG13_cfg_sync_dly_cnt13_START (16)
#define SOC_CPU_RTM_RTM_SYNC_CFG13_cfg_sync_dly_cnt13_END (29)
#define SOC_CPU_RTM_RTM_SYNC_CFG13_cfg_sync_en13_START (31)
#define SOC_CPU_RTM_RTM_SYNC_CFG13_cfg_sync_en13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int samp_on_soft : 1;
        unsigned int ts_compress_en : 1;
        unsigned int id_compress_en : 1;
        unsigned int data_compress_en : 1;
        unsigned int channel_id_compress_en : 1;
        unsigned int cfg_master_id : 8;
        unsigned int reserved : 3;
        unsigned int trace_en_filter : 16;
    } reg;
} SOC_CPU_RTM_TRACE_CTRL_UNION;
#endif
#define SOC_CPU_RTM_TRACE_CTRL_samp_on_soft_START (0)
#define SOC_CPU_RTM_TRACE_CTRL_samp_on_soft_END (0)
#define SOC_CPU_RTM_TRACE_CTRL_ts_compress_en_START (1)
#define SOC_CPU_RTM_TRACE_CTRL_ts_compress_en_END (1)
#define SOC_CPU_RTM_TRACE_CTRL_id_compress_en_START (2)
#define SOC_CPU_RTM_TRACE_CTRL_id_compress_en_END (2)
#define SOC_CPU_RTM_TRACE_CTRL_data_compress_en_START (3)
#define SOC_CPU_RTM_TRACE_CTRL_data_compress_en_END (3)
#define SOC_CPU_RTM_TRACE_CTRL_channel_id_compress_en_START (4)
#define SOC_CPU_RTM_TRACE_CTRL_channel_id_compress_en_END (4)
#define SOC_CPU_RTM_TRACE_CTRL_cfg_master_id_START (5)
#define SOC_CPU_RTM_TRACE_CTRL_cfg_master_id_END (12)
#define SOC_CPU_RTM_TRACE_CTRL_trace_en_filter_START (16)
#define SOC_CPU_RTM_TRACE_CTRL_trace_en_filter_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int samp_on_time_l : 32;
    } reg;
} SOC_CPU_RTM_SAMP_ON_TIME_L_UNION;
#endif
#define SOC_CPU_RTM_SAMP_ON_TIME_L_samp_on_time_l_START (0)
#define SOC_CPU_RTM_SAMP_ON_TIME_L_samp_on_time_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int samp_on_time_h : 32;
    } reg;
} SOC_CPU_RTM_SAMP_ON_TIME_H_UNION;
#endif
#define SOC_CPU_RTM_SAMP_ON_TIME_H_samp_on_time_h_START (0)
#define SOC_CPU_RTM_SAMP_ON_TIME_H_samp_on_time_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int samp_en_time_l : 32;
    } reg;
} SOC_CPU_RTM_SAMP_EN_TIME_L_UNION;
#endif
#define SOC_CPU_RTM_SAMP_EN_TIME_L_samp_en_time_l_START (0)
#define SOC_CPU_RTM_SAMP_EN_TIME_L_samp_en_time_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int samp_en_time_h : 32;
    } reg;
} SOC_CPU_RTM_SAMP_EN_TIME_H_UNION;
#endif
#define SOC_CPU_RTM_SAMP_EN_TIME_H_samp_en_time_h_START (0)
#define SOC_CPU_RTM_SAMP_EN_TIME_H_samp_en_time_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ts_en_time_l : 32;
    } reg;
} SOC_CPU_RTM_TS_EN_TIME_L_UNION;
#endif
#define SOC_CPU_RTM_TS_EN_TIME_L_ts_en_time_l_START (0)
#define SOC_CPU_RTM_TS_EN_TIME_L_ts_en_time_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ts_en_time_h : 32;
    } reg;
} SOC_CPU_RTM_TS_EN_TIME_H_UNION;
#endif
#define SOC_CPU_RTM_TS_EN_TIME_H_ts_en_time_h_START (0)
#define SOC_CPU_RTM_TS_EN_TIME_H_ts_en_time_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_channel_valid0 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_CPU_RTM_TRACE_CHANNEL_VALID0_UNION;
#endif
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID0_trace_channel_valid0_START (0)
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID0_trace_channel_valid0_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_channel_valid1 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_CPU_RTM_TRACE_CHANNEL_VALID1_UNION;
#endif
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID1_trace_channel_valid1_START (0)
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID1_trace_channel_valid1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_channel_valid2 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_CPU_RTM_TRACE_CHANNEL_VALID2_UNION;
#endif
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID2_trace_channel_valid2_START (0)
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID2_trace_channel_valid2_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_channel_valid3 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_CPU_RTM_TRACE_CHANNEL_VALID3_UNION;
#endif
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID3_trace_channel_valid3_START (0)
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID3_trace_channel_valid3_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_channel_valid4 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_CPU_RTM_TRACE_CHANNEL_VALID4_UNION;
#endif
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID4_trace_channel_valid4_START (0)
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID4_trace_channel_valid4_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_channel_valid5 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_CPU_RTM_TRACE_CHANNEL_VALID5_UNION;
#endif
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID5_trace_channel_valid5_START (0)
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID5_trace_channel_valid5_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_channel_valid6 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_CPU_RTM_TRACE_CHANNEL_VALID6_UNION;
#endif
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID6_trace_channel_valid6_START (0)
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID6_trace_channel_valid6_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_channel_valid7 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_CPU_RTM_TRACE_CHANNEL_VALID7_UNION;
#endif
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID7_trace_channel_valid7_START (0)
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID7_trace_channel_valid7_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_channel_valid8 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_CPU_RTM_TRACE_CHANNEL_VALID8_UNION;
#endif
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID8_trace_channel_valid8_START (0)
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID8_trace_channel_valid8_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_channel_valid9 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_CPU_RTM_TRACE_CHANNEL_VALID9_UNION;
#endif
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID9_trace_channel_valid9_START (0)
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID9_trace_channel_valid9_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_channel_valid10 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_CPU_RTM_TRACE_CHANNEL_VALID10_UNION;
#endif
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID10_trace_channel_valid10_START (0)
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID10_trace_channel_valid10_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_channel_valid11 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_CPU_RTM_TRACE_CHANNEL_VALID11_UNION;
#endif
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID11_trace_channel_valid11_START (0)
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID11_trace_channel_valid11_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_channel_valid12 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CPU_RTM_TRACE_CHANNEL_VALID12_UNION;
#endif
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID12_trace_channel_valid12_START (0)
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID12_trace_channel_valid12_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_channel_valid13 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CPU_RTM_TRACE_CHANNEL_VALID13_UNION;
#endif
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID13_trace_channel_valid13_START (0)
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID13_trace_channel_valid13_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_channel_valid_latmon : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CPU_RTM_TRACE_CHANNEL_VALID_LATMNT_UNION;
#endif
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID_LATMNT_trace_channel_valid_latmon_START (0)
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID_LATMNT_trace_channel_valid_latmon_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sample_overflow : 1;
        unsigned int dma_descr : 1;
        unsigned int dma_rresp : 1;
        unsigned int dma_bresp : 1;
        unsigned int link_descr : 1;
        unsigned int adma_len_mismatch : 1;
        unsigned int adma_descr_invld : 1;
        unsigned int dma_intr : 1;
        unsigned int sdma_bndy_irq : 1;
        unsigned int flush_intr : 1;
        unsigned int latcnt_threshold_intr : 1;
        unsigned int latcnt_timeout_intr : 1;
        unsigned int cpu_crg_afifo_wfull : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_CPU_RTM_RTM_INT0_STATE_UNION;
#endif
#define SOC_CPU_RTM_RTM_INT0_STATE_sample_overflow_START (0)
#define SOC_CPU_RTM_RTM_INT0_STATE_sample_overflow_END (0)
#define SOC_CPU_RTM_RTM_INT0_STATE_dma_descr_START (1)
#define SOC_CPU_RTM_RTM_INT0_STATE_dma_descr_END (1)
#define SOC_CPU_RTM_RTM_INT0_STATE_dma_rresp_START (2)
#define SOC_CPU_RTM_RTM_INT0_STATE_dma_rresp_END (2)
#define SOC_CPU_RTM_RTM_INT0_STATE_dma_bresp_START (3)
#define SOC_CPU_RTM_RTM_INT0_STATE_dma_bresp_END (3)
#define SOC_CPU_RTM_RTM_INT0_STATE_link_descr_START (4)
#define SOC_CPU_RTM_RTM_INT0_STATE_link_descr_END (4)
#define SOC_CPU_RTM_RTM_INT0_STATE_adma_len_mismatch_START (5)
#define SOC_CPU_RTM_RTM_INT0_STATE_adma_len_mismatch_END (5)
#define SOC_CPU_RTM_RTM_INT0_STATE_adma_descr_invld_START (6)
#define SOC_CPU_RTM_RTM_INT0_STATE_adma_descr_invld_END (6)
#define SOC_CPU_RTM_RTM_INT0_STATE_dma_intr_START (7)
#define SOC_CPU_RTM_RTM_INT0_STATE_dma_intr_END (7)
#define SOC_CPU_RTM_RTM_INT0_STATE_sdma_bndy_irq_START (8)
#define SOC_CPU_RTM_RTM_INT0_STATE_sdma_bndy_irq_END (8)
#define SOC_CPU_RTM_RTM_INT0_STATE_flush_intr_START (9)
#define SOC_CPU_RTM_RTM_INT0_STATE_flush_intr_END (9)
#define SOC_CPU_RTM_RTM_INT0_STATE_latcnt_threshold_intr_START (10)
#define SOC_CPU_RTM_RTM_INT0_STATE_latcnt_threshold_intr_END (10)
#define SOC_CPU_RTM_RTM_INT0_STATE_latcnt_timeout_intr_START (11)
#define SOC_CPU_RTM_RTM_INT0_STATE_latcnt_timeout_intr_END (11)
#define SOC_CPU_RTM_RTM_INT0_STATE_cpu_crg_afifo_wfull_START (12)
#define SOC_CPU_RTM_RTM_INT0_STATE_cpu_crg_afifo_wfull_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sample_overflow_int_enable : 1;
        unsigned int dma_descr_int_enable : 1;
        unsigned int dma_rresp_int_enable : 1;
        unsigned int dma_bresp_int_enable : 1;
        unsigned int link_descr_int_enable : 1;
        unsigned int adma_len_mismatch_int_enable : 1;
        unsigned int adma_descr_invld_int_enable : 1;
        unsigned int dma_intr_int_enable : 1;
        unsigned int sdma_bndy_irq_enable : 1;
        unsigned int flush_intr_int_enable : 1;
        unsigned int latcnt_threshold_int_enable : 1;
        unsigned int latcnt_timeout_int_enable : 1;
        unsigned int cpu_crg_afifo_wfull_int_enable : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_CPU_RTM_RTM_INT0_STATE_ENABLE_UNION;
#endif
#define SOC_CPU_RTM_RTM_INT0_STATE_ENABLE_sample_overflow_int_enable_START (0)
#define SOC_CPU_RTM_RTM_INT0_STATE_ENABLE_sample_overflow_int_enable_END (0)
#define SOC_CPU_RTM_RTM_INT0_STATE_ENABLE_dma_descr_int_enable_START (1)
#define SOC_CPU_RTM_RTM_INT0_STATE_ENABLE_dma_descr_int_enable_END (1)
#define SOC_CPU_RTM_RTM_INT0_STATE_ENABLE_dma_rresp_int_enable_START (2)
#define SOC_CPU_RTM_RTM_INT0_STATE_ENABLE_dma_rresp_int_enable_END (2)
#define SOC_CPU_RTM_RTM_INT0_STATE_ENABLE_dma_bresp_int_enable_START (3)
#define SOC_CPU_RTM_RTM_INT0_STATE_ENABLE_dma_bresp_int_enable_END (3)
#define SOC_CPU_RTM_RTM_INT0_STATE_ENABLE_link_descr_int_enable_START (4)
#define SOC_CPU_RTM_RTM_INT0_STATE_ENABLE_link_descr_int_enable_END (4)
#define SOC_CPU_RTM_RTM_INT0_STATE_ENABLE_adma_len_mismatch_int_enable_START (5)
#define SOC_CPU_RTM_RTM_INT0_STATE_ENABLE_adma_len_mismatch_int_enable_END (5)
#define SOC_CPU_RTM_RTM_INT0_STATE_ENABLE_adma_descr_invld_int_enable_START (6)
#define SOC_CPU_RTM_RTM_INT0_STATE_ENABLE_adma_descr_invld_int_enable_END (6)
#define SOC_CPU_RTM_RTM_INT0_STATE_ENABLE_dma_intr_int_enable_START (7)
#define SOC_CPU_RTM_RTM_INT0_STATE_ENABLE_dma_intr_int_enable_END (7)
#define SOC_CPU_RTM_RTM_INT0_STATE_ENABLE_sdma_bndy_irq_enable_START (8)
#define SOC_CPU_RTM_RTM_INT0_STATE_ENABLE_sdma_bndy_irq_enable_END (8)
#define SOC_CPU_RTM_RTM_INT0_STATE_ENABLE_flush_intr_int_enable_START (9)
#define SOC_CPU_RTM_RTM_INT0_STATE_ENABLE_flush_intr_int_enable_END (9)
#define SOC_CPU_RTM_RTM_INT0_STATE_ENABLE_latcnt_threshold_int_enable_START (10)
#define SOC_CPU_RTM_RTM_INT0_STATE_ENABLE_latcnt_threshold_int_enable_END (10)
#define SOC_CPU_RTM_RTM_INT0_STATE_ENABLE_latcnt_timeout_int_enable_START (11)
#define SOC_CPU_RTM_RTM_INT0_STATE_ENABLE_latcnt_timeout_int_enable_END (11)
#define SOC_CPU_RTM_RTM_INT0_STATE_ENABLE_cpu_crg_afifo_wfull_int_enable_START (12)
#define SOC_CPU_RTM_RTM_INT0_STATE_ENABLE_cpu_crg_afifo_wfull_int_enable_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sample_overflow_signal_enable : 1;
        unsigned int dma_descr_signal_enable : 1;
        unsigned int dma_rresp_signal_enable : 1;
        unsigned int dma_bresp_signal_enable : 1;
        unsigned int link_descr_signal_enable : 1;
        unsigned int adma_len_mismatch_signal_enable : 1;
        unsigned int adma_descr_invld_signal_enable : 1;
        unsigned int dma_intr_signal_enable : 1;
        unsigned int sdma_bndy_irq_signal_enable : 1;
        unsigned int flush_intr_signal_enable : 1;
        unsigned int latcnt_threshold_int_signal_enable : 1;
        unsigned int latcnt_timeout_int_signal_enable : 1;
        unsigned int cpu_crg_afifo_wfull_signal_enable : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_CPU_RTM_RTM_INT0_SINGAL_ENABLE_UNION;
#endif
#define SOC_CPU_RTM_RTM_INT0_SINGAL_ENABLE_sample_overflow_signal_enable_START (0)
#define SOC_CPU_RTM_RTM_INT0_SINGAL_ENABLE_sample_overflow_signal_enable_END (0)
#define SOC_CPU_RTM_RTM_INT0_SINGAL_ENABLE_dma_descr_signal_enable_START (1)
#define SOC_CPU_RTM_RTM_INT0_SINGAL_ENABLE_dma_descr_signal_enable_END (1)
#define SOC_CPU_RTM_RTM_INT0_SINGAL_ENABLE_dma_rresp_signal_enable_START (2)
#define SOC_CPU_RTM_RTM_INT0_SINGAL_ENABLE_dma_rresp_signal_enable_END (2)
#define SOC_CPU_RTM_RTM_INT0_SINGAL_ENABLE_dma_bresp_signal_enable_START (3)
#define SOC_CPU_RTM_RTM_INT0_SINGAL_ENABLE_dma_bresp_signal_enable_END (3)
#define SOC_CPU_RTM_RTM_INT0_SINGAL_ENABLE_link_descr_signal_enable_START (4)
#define SOC_CPU_RTM_RTM_INT0_SINGAL_ENABLE_link_descr_signal_enable_END (4)
#define SOC_CPU_RTM_RTM_INT0_SINGAL_ENABLE_adma_len_mismatch_signal_enable_START (5)
#define SOC_CPU_RTM_RTM_INT0_SINGAL_ENABLE_adma_len_mismatch_signal_enable_END (5)
#define SOC_CPU_RTM_RTM_INT0_SINGAL_ENABLE_adma_descr_invld_signal_enable_START (6)
#define SOC_CPU_RTM_RTM_INT0_SINGAL_ENABLE_adma_descr_invld_signal_enable_END (6)
#define SOC_CPU_RTM_RTM_INT0_SINGAL_ENABLE_dma_intr_signal_enable_START (7)
#define SOC_CPU_RTM_RTM_INT0_SINGAL_ENABLE_dma_intr_signal_enable_END (7)
#define SOC_CPU_RTM_RTM_INT0_SINGAL_ENABLE_sdma_bndy_irq_signal_enable_START (8)
#define SOC_CPU_RTM_RTM_INT0_SINGAL_ENABLE_sdma_bndy_irq_signal_enable_END (8)
#define SOC_CPU_RTM_RTM_INT0_SINGAL_ENABLE_flush_intr_signal_enable_START (9)
#define SOC_CPU_RTM_RTM_INT0_SINGAL_ENABLE_flush_intr_signal_enable_END (9)
#define SOC_CPU_RTM_RTM_INT0_SINGAL_ENABLE_latcnt_threshold_int_signal_enable_START (10)
#define SOC_CPU_RTM_RTM_INT0_SINGAL_ENABLE_latcnt_threshold_int_signal_enable_END (10)
#define SOC_CPU_RTM_RTM_INT0_SINGAL_ENABLE_latcnt_timeout_int_signal_enable_START (11)
#define SOC_CPU_RTM_RTM_INT0_SINGAL_ENABLE_latcnt_timeout_int_signal_enable_END (11)
#define SOC_CPU_RTM_RTM_INT0_SINGAL_ENABLE_cpu_crg_afifo_wfull_signal_enable_START (12)
#define SOC_CPU_RTM_RTM_INT0_SINGAL_ENABLE_cpu_crg_afifo_wfull_signal_enable_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int xpu_common_int_enable : 1;
        unsigned int common_int_add_latcnt_enable : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CPU_RTM_RTM_INT_XPU_EN_UNION;
#endif
#define SOC_CPU_RTM_RTM_INT_XPU_EN_xpu_common_int_enable_START (0)
#define SOC_CPU_RTM_RTM_INT_XPU_EN_xpu_common_int_enable_END (0)
#define SOC_CPU_RTM_RTM_INT_XPU_EN_common_int_add_latcnt_enable_START (1)
#define SOC_CPU_RTM_RTM_INT_XPU_EN_common_int_add_latcnt_enable_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_cal_override : 1;
        unsigned int data_recv_corrupt : 1;
        unsigned int trace_en : 1;
        unsigned int period_tmo : 1;
        unsigned int header_chk_fail : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_CPU_RTM_RTM_INT1_STATE_UNION;
#endif
#define SOC_CPU_RTM_RTM_INT1_STATE_trace_cal_override_START (0)
#define SOC_CPU_RTM_RTM_INT1_STATE_trace_cal_override_END (0)
#define SOC_CPU_RTM_RTM_INT1_STATE_data_recv_corrupt_START (1)
#define SOC_CPU_RTM_RTM_INT1_STATE_data_recv_corrupt_END (1)
#define SOC_CPU_RTM_RTM_INT1_STATE_trace_en_START (2)
#define SOC_CPU_RTM_RTM_INT1_STATE_trace_en_END (2)
#define SOC_CPU_RTM_RTM_INT1_STATE_period_tmo_START (3)
#define SOC_CPU_RTM_RTM_INT1_STATE_period_tmo_END (3)
#define SOC_CPU_RTM_RTM_INT1_STATE_header_chk_fail_START (4)
#define SOC_CPU_RTM_RTM_INT1_STATE_header_chk_fail_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_cal_override_int_enable : 1;
        unsigned int data_recv_corrupt_int_enable : 1;
        unsigned int trace_en_int_enable : 1;
        unsigned int period_tmo_int_enable : 1;
        unsigned int header_chk_fail_int_enable : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_UNION;
#endif
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_trace_cal_override_int_enable_START (0)
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_trace_cal_override_int_enable_END (0)
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_data_recv_corrupt_int_enable_START (1)
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_data_recv_corrupt_int_enable_END (1)
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_trace_en_int_enable_START (2)
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_trace_en_int_enable_END (2)
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_period_tmo_int_enable_START (3)
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_period_tmo_int_enable_END (3)
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_header_chk_fail_int_enable_START (4)
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_header_chk_fail_int_enable_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_cal_override_signal_enable : 1;
        unsigned int data_recv_corrupt_signal_enable : 1;
        unsigned int trace_en_signal_enable : 1;
        unsigned int period_tmo_signal_enable : 1;
        unsigned int header_chk_fail_signal_enable : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_UNION;
#endif
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_trace_cal_override_signal_enable_START (0)
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_trace_cal_override_signal_enable_END (0)
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_data_recv_corrupt_signal_enable_START (1)
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_data_recv_corrupt_signal_enable_END (1)
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_trace_en_signal_enable_START (2)
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_trace_en_signal_enable_END (2)
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_period_tmo_signal_enable_START (3)
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_period_tmo_signal_enable_END (3)
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_header_chk_fail_signal_enable_START (4)
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_header_chk_fail_signal_enable_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_flag : 32;
    } reg;
} SOC_CPU_RTM_RTM_INT2_STATE_UNION;
#endif
#define SOC_CPU_RTM_RTM_INT2_STATE_trace_flag_START (0)
#define SOC_CPU_RTM_RTM_INT2_STATE_trace_flag_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_flag_int_enable : 32;
    } reg;
} SOC_CPU_RTM_RTM_INT2_STATE_ENABLE_UNION;
#endif
#define SOC_CPU_RTM_RTM_INT2_STATE_ENABLE_trace_flag_int_enable_START (0)
#define SOC_CPU_RTM_RTM_INT2_STATE_ENABLE_trace_flag_int_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_flag_signal_enable : 32;
    } reg;
} SOC_CPU_RTM_RTM_INT2_SINGAL_ENABLE_UNION;
#endif
#define SOC_CPU_RTM_RTM_INT2_SINGAL_ENABLE_trace_flag_signal_enable_START (0)
#define SOC_CPU_RTM_RTM_INT2_SINGAL_ENABLE_trace_flag_signal_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_monitor_en : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CPU_RTM_CFG_MONITOR_EN_UNION;
#endif
#define SOC_CPU_RTM_CFG_MONITOR_EN_cfg_monitor_en_START (0)
#define SOC_CPU_RTM_CFG_MONITOR_EN_cfg_monitor_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_period_event_msk : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_CPU_RTM_CFG_PERIOD_EVENT_MSK_UNION;
#endif
#define SOC_CPU_RTM_CFG_PERIOD_EVENT_MSK_cfg_period_event_msk_START (0)
#define SOC_CPU_RTM_CFG_PERIOD_EVENT_MSK_cfg_period_event_msk_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_period_event_ts_0 : 32;
    } reg;
} SOC_CPU_RTM_CFG_PERIOD_EVENT_TS_0_UNION;
#endif
#define SOC_CPU_RTM_CFG_PERIOD_EVENT_TS_0_cfg_period_event_ts_0_START (0)
#define SOC_CPU_RTM_CFG_PERIOD_EVENT_TS_0_cfg_period_event_ts_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_header_filter_cmp_0 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_0_UNION;
#endif
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_0_cfg_header_filter_cmp_0_START (0)
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_0_cfg_header_filter_cmp_0_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_header_filter_cmp_1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_1_UNION;
#endif
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_1_cfg_header_filter_cmp_1_START (0)
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_1_cfg_header_filter_cmp_1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_header_filter_cmp_2 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_2_UNION;
#endif
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_2_cfg_header_filter_cmp_2_START (0)
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_2_cfg_header_filter_cmp_2_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_header_filter_cmp_3 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_3_UNION;
#endif
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_3_cfg_header_filter_cmp_3_START (0)
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_3_cfg_header_filter_cmp_3_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_trace_filter_en : 1;
        unsigned int cfg_trace_filter_mode : 1;
        unsigned int cfg_header_filter_en : 1;
        unsigned int cfg_header_filter_mode : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_CPU_RTM_CFG_FILTER_CTRL_UNION;
#endif
#define SOC_CPU_RTM_CFG_FILTER_CTRL_cfg_trace_filter_en_START (0)
#define SOC_CPU_RTM_CFG_FILTER_CTRL_cfg_trace_filter_en_END (0)
#define SOC_CPU_RTM_CFG_FILTER_CTRL_cfg_trace_filter_mode_START (1)
#define SOC_CPU_RTM_CFG_FILTER_CTRL_cfg_trace_filter_mode_END (1)
#define SOC_CPU_RTM_CFG_FILTER_CTRL_cfg_header_filter_en_START (2)
#define SOC_CPU_RTM_CFG_FILTER_CTRL_cfg_header_filter_en_END (2)
#define SOC_CPU_RTM_CFG_FILTER_CTRL_cfg_header_filter_mode_START (3)
#define SOC_CPU_RTM_CFG_FILTER_CTRL_cfg_header_filter_mode_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_header_filter_msk : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_CPU_RTM_CFG_HEADER_FILTER_MSK_UNION;
#endif
#define SOC_CPU_RTM_CFG_HEADER_FILTER_MSK_cfg_header_filter_msk_START (0)
#define SOC_CPU_RTM_CFG_HEADER_FILTER_MSK_cfg_header_filter_msk_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_trace_filter_cmp_0 : 32;
    } reg;
} SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_0_UNION;
#endif
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_0_cfg_trace_filter_cmp_0_START (0)
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_0_cfg_trace_filter_cmp_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_trace_filter_cmp_1 : 32;
    } reg;
} SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_1_UNION;
#endif
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_1_cfg_trace_filter_cmp_1_START (0)
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_1_cfg_trace_filter_cmp_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_trace_filter_cmp_2 : 32;
    } reg;
} SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_2_UNION;
#endif
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_2_cfg_trace_filter_cmp_2_START (0)
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_2_cfg_trace_filter_cmp_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_trace_filter_cmp_3 : 32;
    } reg;
} SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_3_UNION;
#endif
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_3_cfg_trace_filter_cmp_3_START (0)
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_3_cfg_trace_filter_cmp_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_trace_filter_cmp_4 : 32;
    } reg;
} SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_4_UNION;
#endif
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_4_cfg_trace_filter_cmp_4_START (0)
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_4_cfg_trace_filter_cmp_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_trace_filter_cmp_5 : 32;
    } reg;
} SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_5_UNION;
#endif
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_5_cfg_trace_filter_cmp_5_START (0)
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_5_cfg_trace_filter_cmp_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_trace_filter_cmp_6 : 32;
    } reg;
} SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_6_UNION;
#endif
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_6_cfg_trace_filter_cmp_6_START (0)
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_6_cfg_trace_filter_cmp_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_trace_filter_cmp_7 : 32;
    } reg;
} SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_7_UNION;
#endif
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_7_cfg_trace_filter_cmp_7_START (0)
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_7_cfg_trace_filter_cmp_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_trace_filter_cmp_8 : 32;
    } reg;
} SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_8_UNION;
#endif
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_8_cfg_trace_filter_cmp_8_START (0)
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_8_cfg_trace_filter_cmp_8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_trace_filter_cmp_9 : 32;
    } reg;
} SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_9_UNION;
#endif
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_9_cfg_trace_filter_cmp_9_START (0)
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_9_cfg_trace_filter_cmp_9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_trace_filter_cmp_10 : 32;
    } reg;
} SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_10_UNION;
#endif
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_10_cfg_trace_filter_cmp_10_START (0)
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_10_cfg_trace_filter_cmp_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_trace_filter_cmp_11 : 32;
    } reg;
} SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_11_UNION;
#endif
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_11_cfg_trace_filter_cmp_11_START (0)
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_11_cfg_trace_filter_cmp_11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_trace_filter_cmp_12 : 32;
    } reg;
} SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_12_UNION;
#endif
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_12_cfg_trace_filter_cmp_12_START (0)
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_12_cfg_trace_filter_cmp_12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_trace_filter_cmp_13 : 32;
    } reg;
} SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_13_UNION;
#endif
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_13_cfg_trace_filter_cmp_13_START (0)
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_13_cfg_trace_filter_cmp_13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_trace_filter_cmp_14 : 32;
    } reg;
} SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_14_UNION;
#endif
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_14_cfg_trace_filter_cmp_14_START (0)
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_14_cfg_trace_filter_cmp_14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_trace_filter_cmp_15 : 32;
    } reg;
} SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_15_UNION;
#endif
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_15_cfg_trace_filter_cmp_15_START (0)
#define SOC_CPU_RTM_CFG_TRACE_FILTER_CMP_15_cfg_trace_filter_cmp_15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid8_latency_qos0_avg0 : 9;
        unsigned int lpid8_latency_qos0_min0 : 9;
        unsigned int lpid8_latency_qos0_max0 : 9;
        unsigned int lpid8_qos0 : 3;
        unsigned int lpid8_cnt4_qos0_valid : 1;
        unsigned int lpid8_cnt8_qos0_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS0_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS0_lpid8_latency_qos0_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS0_lpid8_latency_qos0_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS0_lpid8_latency_qos0_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS0_lpid8_latency_qos0_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS0_lpid8_latency_qos0_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS0_lpid8_latency_qos0_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS0_lpid8_qos0_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS0_lpid8_qos0_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS0_lpid8_cnt4_qos0_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS0_lpid8_cnt4_qos0_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS0_lpid8_cnt8_qos0_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS0_lpid8_cnt8_qos0_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid8_latency_qos1_avg0 : 9;
        unsigned int lpid8_latency_qos1_min0 : 9;
        unsigned int lpid8_latency_qos1_max0 : 9;
        unsigned int lpid8_qos1 : 3;
        unsigned int lpid8_cnt4_qos1_valid : 1;
        unsigned int lpid8_cnt8_qos1_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS1_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS1_lpid8_latency_qos1_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS1_lpid8_latency_qos1_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS1_lpid8_latency_qos1_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS1_lpid8_latency_qos1_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS1_lpid8_latency_qos1_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS1_lpid8_latency_qos1_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS1_lpid8_qos1_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS1_lpid8_qos1_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS1_lpid8_cnt4_qos1_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS1_lpid8_cnt4_qos1_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS1_lpid8_cnt8_qos1_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS1_lpid8_cnt8_qos1_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid8_latency_qos2_avg0 : 9;
        unsigned int lpid8_latency_qos2_min0 : 9;
        unsigned int lpid8_latency_qos2_max0 : 9;
        unsigned int lpid8_qos2 : 3;
        unsigned int lpid8_cnt4_qos2_valid : 1;
        unsigned int lpid8_cnt8_qos2_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS2_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS2_lpid8_latency_qos2_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS2_lpid8_latency_qos2_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS2_lpid8_latency_qos2_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS2_lpid8_latency_qos2_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS2_lpid8_latency_qos2_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS2_lpid8_latency_qos2_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS2_lpid8_qos2_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS2_lpid8_qos2_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS2_lpid8_cnt4_qos2_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS2_lpid8_cnt4_qos2_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS2_lpid8_cnt8_qos2_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS2_lpid8_cnt8_qos2_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid8_latency_qos3_avg0 : 9;
        unsigned int lpid8_latency_qos3_min0 : 9;
        unsigned int lpid8_latency_qos3_max0 : 9;
        unsigned int lpid8_qos3 : 3;
        unsigned int lpid8_cnt4_qos3_valid : 1;
        unsigned int lpid8_cnt8_qos3_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS3_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS3_lpid8_latency_qos3_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS3_lpid8_latency_qos3_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS3_lpid8_latency_qos3_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS3_lpid8_latency_qos3_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS3_lpid8_latency_qos3_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS3_lpid8_latency_qos3_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS3_lpid8_qos3_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS3_lpid8_qos3_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS3_lpid8_cnt4_qos3_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS3_lpid8_cnt4_qos3_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS3_lpid8_cnt8_qos3_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID8_QOS3_lpid8_cnt8_qos3_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid9_latency_qos0_avg0 : 9;
        unsigned int lpid9_latency_qos0_min0 : 9;
        unsigned int lpid9_latency_qos0_max0 : 9;
        unsigned int lpid9_qos0 : 3;
        unsigned int lpid9_cnt4_qos0_valid : 1;
        unsigned int lpid9_cnt8_qos0_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS0_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS0_lpid9_latency_qos0_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS0_lpid9_latency_qos0_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS0_lpid9_latency_qos0_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS0_lpid9_latency_qos0_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS0_lpid9_latency_qos0_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS0_lpid9_latency_qos0_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS0_lpid9_qos0_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS0_lpid9_qos0_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS0_lpid9_cnt4_qos0_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS0_lpid9_cnt4_qos0_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS0_lpid9_cnt8_qos0_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS0_lpid9_cnt8_qos0_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid9_latency_qos1_avg0 : 9;
        unsigned int lpid9_latency_qos1_min0 : 9;
        unsigned int lpid9_latency_qos1_max0 : 9;
        unsigned int lpid9_qos1 : 3;
        unsigned int lpid9_cnt4_qos1_valid : 1;
        unsigned int lpid9_cnt8_qos1_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS1_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS1_lpid9_latency_qos1_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS1_lpid9_latency_qos1_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS1_lpid9_latency_qos1_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS1_lpid9_latency_qos1_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS1_lpid9_latency_qos1_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS1_lpid9_latency_qos1_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS1_lpid9_qos1_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS1_lpid9_qos1_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS1_lpid9_cnt4_qos1_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS1_lpid9_cnt4_qos1_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS1_lpid9_cnt8_qos1_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS1_lpid9_cnt8_qos1_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid9_latency_qos2_avg0 : 9;
        unsigned int lpid9_latency_qos2_min0 : 9;
        unsigned int lpid9_latency_qos2_max0 : 9;
        unsigned int lpid9_qos2 : 3;
        unsigned int lpid9_cnt4_qos2_valid : 1;
        unsigned int lpid9_cnt8_qos2_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS2_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS2_lpid9_latency_qos2_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS2_lpid9_latency_qos2_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS2_lpid9_latency_qos2_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS2_lpid9_latency_qos2_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS2_lpid9_latency_qos2_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS2_lpid9_latency_qos2_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS2_lpid9_qos2_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS2_lpid9_qos2_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS2_lpid9_cnt4_qos2_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS2_lpid9_cnt4_qos2_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS2_lpid9_cnt8_qos2_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS2_lpid9_cnt8_qos2_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid9_latency_qos3_avg0 : 9;
        unsigned int lpid9_latency_qos3_min0 : 9;
        unsigned int lpid9_latency_qos3_max0 : 9;
        unsigned int lpid9_qos3 : 3;
        unsigned int lpid9_cnt4_qos3_valid : 1;
        unsigned int lpid9_cnt8_qos3_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS3_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS3_lpid9_latency_qos3_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS3_lpid9_latency_qos3_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS3_lpid9_latency_qos3_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS3_lpid9_latency_qos3_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS3_lpid9_latency_qos3_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS3_lpid9_latency_qos3_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS3_lpid9_qos3_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS3_lpid9_qos3_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS3_lpid9_cnt4_qos3_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS3_lpid9_cnt4_qos3_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS3_lpid9_cnt8_qos3_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID9_QOS3_lpid9_cnt8_qos3_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid10_latency_qos0_avg0 : 9;
        unsigned int lpid10_latency_qos0_min0 : 9;
        unsigned int lpid10_latency_qos0_max0 : 9;
        unsigned int lpid10_qos0 : 3;
        unsigned int lpid10_cnt4_qos0_valid : 1;
        unsigned int lpid10_cnt8_qos0_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS0_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS0_lpid10_latency_qos0_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS0_lpid10_latency_qos0_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS0_lpid10_latency_qos0_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS0_lpid10_latency_qos0_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS0_lpid10_latency_qos0_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS0_lpid10_latency_qos0_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS0_lpid10_qos0_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS0_lpid10_qos0_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS0_lpid10_cnt4_qos0_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS0_lpid10_cnt4_qos0_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS0_lpid10_cnt8_qos0_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS0_lpid10_cnt8_qos0_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid10_latency_qos1_avg0 : 9;
        unsigned int lpid10_latency_qos1_min0 : 9;
        unsigned int lpid10_latency_qos1_max0 : 9;
        unsigned int lpid10_qos1 : 3;
        unsigned int lpid10_cnt4_qos1_valid : 1;
        unsigned int lpid10_cnt8_qos1_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS1_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS1_lpid10_latency_qos1_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS1_lpid10_latency_qos1_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS1_lpid10_latency_qos1_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS1_lpid10_latency_qos1_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS1_lpid10_latency_qos1_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS1_lpid10_latency_qos1_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS1_lpid10_qos1_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS1_lpid10_qos1_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS1_lpid10_cnt4_qos1_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS1_lpid10_cnt4_qos1_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS1_lpid10_cnt8_qos1_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS1_lpid10_cnt8_qos1_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid10_latency_qos2_avg0 : 9;
        unsigned int lpid10_latency_qos2_min0 : 9;
        unsigned int lpid10_latency_qos2_max0 : 9;
        unsigned int lpid10_qos2 : 3;
        unsigned int lpid10_cnt4_qos2_valid : 1;
        unsigned int lpid10_cnt8_qos2_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS2_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS2_lpid10_latency_qos2_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS2_lpid10_latency_qos2_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS2_lpid10_latency_qos2_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS2_lpid10_latency_qos2_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS2_lpid10_latency_qos2_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS2_lpid10_latency_qos2_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS2_lpid10_qos2_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS2_lpid10_qos2_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS2_lpid10_cnt4_qos2_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS2_lpid10_cnt4_qos2_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS2_lpid10_cnt8_qos2_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS2_lpid10_cnt8_qos2_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid10_latency_qos3_avg0 : 9;
        unsigned int lpid10_latency_qos3_min0 : 9;
        unsigned int lpid10_latency_qos3_max0 : 9;
        unsigned int lpid10_qos3 : 3;
        unsigned int lpid10_cnt4_qos3_valid : 1;
        unsigned int lpid10_cnt8_qos3_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS3_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS3_lpid10_latency_qos3_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS3_lpid10_latency_qos3_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS3_lpid10_latency_qos3_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS3_lpid10_latency_qos3_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS3_lpid10_latency_qos3_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS3_lpid10_latency_qos3_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS3_lpid10_qos3_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS3_lpid10_qos3_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS3_lpid10_cnt4_qos3_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS3_lpid10_cnt4_qos3_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS3_lpid10_cnt8_qos3_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID10_QOS3_lpid10_cnt8_qos3_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_trace_cnt_filter_msk : 16;
        unsigned int cfg_trace_sig_filter_msk : 16;
    } reg;
} SOC_CPU_RTM_CFG_TRACE_FILTER_MSK_UNION;
#endif
#define SOC_CPU_RTM_CFG_TRACE_FILTER_MSK_cfg_trace_cnt_filter_msk_START (0)
#define SOC_CPU_RTM_CFG_TRACE_FILTER_MSK_cfg_trace_cnt_filter_msk_END (15)
#define SOC_CPU_RTM_CFG_TRACE_FILTER_MSK_cfg_trace_sig_filter_msk_START (16)
#define SOC_CPU_RTM_CFG_TRACE_FILTER_MSK_cfg_trace_sig_filter_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_timer_tmo_h_l : 32;
    } reg;
} SOC_CPU_RTM_CFG_TIMER_TMO_H_L_UNION;
#endif
#define SOC_CPU_RTM_CFG_TIMER_TMO_H_L_cfg_timer_tmo_h_l_START (0)
#define SOC_CPU_RTM_CFG_TIMER_TMO_H_L_cfg_timer_tmo_h_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_timer_tmo_h_h : 32;
    } reg;
} SOC_CPU_RTM_CFG_TIMER_TMO_H_H_UNION;
#endif
#define SOC_CPU_RTM_CFG_TIMER_TMO_H_H_cfg_timer_tmo_h_h_START (0)
#define SOC_CPU_RTM_CFG_TIMER_TMO_H_H_cfg_timer_tmo_h_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_timer_tmo_l_l : 32;
    } reg;
} SOC_CPU_RTM_CFG_TIMER_TMO_L_L_UNION;
#endif
#define SOC_CPU_RTM_CFG_TIMER_TMO_L_L_cfg_timer_tmo_l_l_START (0)
#define SOC_CPU_RTM_CFG_TIMER_TMO_L_L_cfg_timer_tmo_l_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_timer_tmo_l_h : 32;
    } reg;
} SOC_CPU_RTM_CFG_TIMER_TMO_L_H_UNION;
#endif
#define SOC_CPU_RTM_CFG_TIMER_TMO_L_H_cfg_timer_tmo_l_h_START (0)
#define SOC_CPU_RTM_CFG_TIMER_TMO_L_H_cfg_timer_tmo_l_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid11_latency_qos0_avg0 : 9;
        unsigned int lpid11_latency_qos0_min0 : 9;
        unsigned int lpid11_latency_qos0_max0 : 9;
        unsigned int lpid11_qos0 : 3;
        unsigned int lpid11_cnt4_qos0_valid : 1;
        unsigned int lpid11_cnt8_qos0_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS0_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS0_lpid11_latency_qos0_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS0_lpid11_latency_qos0_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS0_lpid11_latency_qos0_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS0_lpid11_latency_qos0_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS0_lpid11_latency_qos0_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS0_lpid11_latency_qos0_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS0_lpid11_qos0_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS0_lpid11_qos0_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS0_lpid11_cnt4_qos0_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS0_lpid11_cnt4_qos0_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS0_lpid11_cnt8_qos0_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS0_lpid11_cnt8_qos0_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid11_latency_qos1_avg0 : 9;
        unsigned int lpid11_latency_qos1_min0 : 9;
        unsigned int lpid11_latency_qos1_max0 : 9;
        unsigned int lpid11_qos1 : 3;
        unsigned int lpid11_cnt4_qos1_valid : 1;
        unsigned int lpid11_cnt8_qos1_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS1_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS1_lpid11_latency_qos1_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS1_lpid11_latency_qos1_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS1_lpid11_latency_qos1_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS1_lpid11_latency_qos1_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS1_lpid11_latency_qos1_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS1_lpid11_latency_qos1_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS1_lpid11_qos1_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS1_lpid11_qos1_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS1_lpid11_cnt4_qos1_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS1_lpid11_cnt4_qos1_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS1_lpid11_cnt8_qos1_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS1_lpid11_cnt8_qos1_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid11_latency_qos2_avg0 : 9;
        unsigned int lpid11_latency_qos2_min0 : 9;
        unsigned int lpid11_latency_qos2_max0 : 9;
        unsigned int lpid11_qos2 : 3;
        unsigned int lpid11_cnt4_qos2_valid : 1;
        unsigned int lpid11_cnt8_qos2_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS2_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS2_lpid11_latency_qos2_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS2_lpid11_latency_qos2_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS2_lpid11_latency_qos2_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS2_lpid11_latency_qos2_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS2_lpid11_latency_qos2_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS2_lpid11_latency_qos2_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS2_lpid11_qos2_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS2_lpid11_qos2_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS2_lpid11_cnt4_qos2_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS2_lpid11_cnt4_qos2_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS2_lpid11_cnt8_qos2_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS2_lpid11_cnt8_qos2_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid11_latency_qos3_avg0 : 9;
        unsigned int lpid11_latency_qos3_min0 : 9;
        unsigned int lpid11_latency_qos3_max0 : 9;
        unsigned int lpid11_qos3 : 3;
        unsigned int lpid11_cnt4_qos3_valid : 1;
        unsigned int lpid11_cnt8_qos3_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS3_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS3_lpid11_latency_qos3_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS3_lpid11_latency_qos3_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS3_lpid11_latency_qos3_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS3_lpid11_latency_qos3_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS3_lpid11_latency_qos3_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS3_lpid11_latency_qos3_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS3_lpid11_qos3_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS3_lpid11_qos3_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS3_lpid11_cnt4_qos3_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS3_lpid11_cnt4_qos3_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS3_lpid11_cnt8_qos3_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID11_QOS3_lpid11_cnt8_qos3_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid12_latency_qos0_avg0 : 9;
        unsigned int lpid12_latency_qos0_min0 : 9;
        unsigned int lpid12_latency_qos0_max0 : 9;
        unsigned int lpid12_qos0 : 3;
        unsigned int lpid12_cnt4_qos0_valid : 1;
        unsigned int lpid12_cnt8_qos0_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS0_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS0_lpid12_latency_qos0_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS0_lpid12_latency_qos0_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS0_lpid12_latency_qos0_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS0_lpid12_latency_qos0_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS0_lpid12_latency_qos0_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS0_lpid12_latency_qos0_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS0_lpid12_qos0_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS0_lpid12_qos0_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS0_lpid12_cnt4_qos0_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS0_lpid12_cnt4_qos0_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS0_lpid12_cnt8_qos0_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS0_lpid12_cnt8_qos0_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid12_latency_qos1_avg0 : 9;
        unsigned int lpid12_latency_qos1_min0 : 9;
        unsigned int lpid12_latency_qos1_max0 : 9;
        unsigned int lpid12_qos1 : 3;
        unsigned int lpid12_cnt4_qos1_valid : 1;
        unsigned int lpid12_cnt8_qos1_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS1_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS1_lpid12_latency_qos1_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS1_lpid12_latency_qos1_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS1_lpid12_latency_qos1_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS1_lpid12_latency_qos1_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS1_lpid12_latency_qos1_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS1_lpid12_latency_qos1_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS1_lpid12_qos1_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS1_lpid12_qos1_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS1_lpid12_cnt4_qos1_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS1_lpid12_cnt4_qos1_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS1_lpid12_cnt8_qos1_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS1_lpid12_cnt8_qos1_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid12_latency_qos2_avg0 : 9;
        unsigned int lpid12_latency_qos2_min0 : 9;
        unsigned int lpid12_latency_qos2_max0 : 9;
        unsigned int lpid12_qos2 : 3;
        unsigned int lpid12_cnt4_qos2_valid : 1;
        unsigned int lpid12_cnt8_qos2_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS2_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS2_lpid12_latency_qos2_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS2_lpid12_latency_qos2_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS2_lpid12_latency_qos2_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS2_lpid12_latency_qos2_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS2_lpid12_latency_qos2_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS2_lpid12_latency_qos2_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS2_lpid12_qos2_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS2_lpid12_qos2_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS2_lpid12_cnt4_qos2_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS2_lpid12_cnt4_qos2_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS2_lpid12_cnt8_qos2_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS2_lpid12_cnt8_qos2_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid12_latency_qos3_avg0 : 9;
        unsigned int lpid12_latency_qos3_min0 : 9;
        unsigned int lpid12_latency_qos3_max0 : 9;
        unsigned int lpid12_qos3 : 3;
        unsigned int lpid12_cnt4_qos3_valid : 1;
        unsigned int lpid12_cnt8_qos3_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS3_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS3_lpid12_latency_qos3_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS3_lpid12_latency_qos3_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS3_lpid12_latency_qos3_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS3_lpid12_latency_qos3_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS3_lpid12_latency_qos3_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS3_lpid12_latency_qos3_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS3_lpid12_qos3_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS3_lpid12_qos3_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS3_lpid12_cnt4_qos3_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS3_lpid12_cnt4_qos3_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS3_lpid12_cnt8_qos3_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID12_QOS3_lpid12_cnt8_qos3_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid13_latency_qos0_avg0 : 9;
        unsigned int lpid13_latency_qos0_min0 : 9;
        unsigned int lpid13_latency_qos0_max0 : 9;
        unsigned int lpid13_qos0 : 3;
        unsigned int lpid13_cnt4_qos0_valid : 1;
        unsigned int lpid13_cnt8_qos0_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS0_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS0_lpid13_latency_qos0_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS0_lpid13_latency_qos0_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS0_lpid13_latency_qos0_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS0_lpid13_latency_qos0_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS0_lpid13_latency_qos0_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS0_lpid13_latency_qos0_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS0_lpid13_qos0_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS0_lpid13_qos0_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS0_lpid13_cnt4_qos0_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS0_lpid13_cnt4_qos0_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS0_lpid13_cnt8_qos0_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS0_lpid13_cnt8_qos0_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid13_latency_qos1_avg0 : 9;
        unsigned int lpid13_latency_qos1_min0 : 9;
        unsigned int lpid13_latency_qos1_max0 : 9;
        unsigned int lpid13_qos1 : 3;
        unsigned int lpid13_cnt4_qos1_valid : 1;
        unsigned int lpid13_cnt8_qos1_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS1_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS1_lpid13_latency_qos1_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS1_lpid13_latency_qos1_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS1_lpid13_latency_qos1_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS1_lpid13_latency_qos1_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS1_lpid13_latency_qos1_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS1_lpid13_latency_qos1_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS1_lpid13_qos1_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS1_lpid13_qos1_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS1_lpid13_cnt4_qos1_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS1_lpid13_cnt4_qos1_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS1_lpid13_cnt8_qos1_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS1_lpid13_cnt8_qos1_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid13_latency_qos2_avg0 : 9;
        unsigned int lpid13_latency_qos2_min0 : 9;
        unsigned int lpid13_latency_qos2_max0 : 9;
        unsigned int lpid13_qos2 : 3;
        unsigned int lpid13_cnt4_qos2_valid : 1;
        unsigned int lpid13_cnt8_qos2_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS2_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS2_lpid13_latency_qos2_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS2_lpid13_latency_qos2_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS2_lpid13_latency_qos2_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS2_lpid13_latency_qos2_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS2_lpid13_latency_qos2_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS2_lpid13_latency_qos2_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS2_lpid13_qos2_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS2_lpid13_qos2_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS2_lpid13_cnt4_qos2_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS2_lpid13_cnt4_qos2_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS2_lpid13_cnt8_qos2_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS2_lpid13_cnt8_qos2_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid13_latency_qos3_avg0 : 9;
        unsigned int lpid13_latency_qos3_min0 : 9;
        unsigned int lpid13_latency_qos3_max0 : 9;
        unsigned int lpid13_qos3 : 3;
        unsigned int lpid13_cnt4_qos3_valid : 1;
        unsigned int lpid13_cnt8_qos3_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS3_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS3_lpid13_latency_qos3_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS3_lpid13_latency_qos3_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS3_lpid13_latency_qos3_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS3_lpid13_latency_qos3_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS3_lpid13_latency_qos3_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS3_lpid13_latency_qos3_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS3_lpid13_qos3_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS3_lpid13_qos3_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS3_lpid13_cnt4_qos3_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS3_lpid13_cnt4_qos3_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS3_lpid13_cnt8_qos3_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID13_QOS3_lpid13_cnt8_qos3_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_trace_cnt_cal_div_stop : 1;
        unsigned int dfx_trace_cnt_cal_id : 4;
        unsigned int dfx_trace_cnt_cal_run : 1;
        unsigned int dfx_data_revc_st : 3;
        unsigned int reserved : 23;
    } reg;
} SOC_CPU_RTM_DFX_SIG_MON_UNION;
#endif
#define SOC_CPU_RTM_DFX_SIG_MON_dfx_trace_cnt_cal_div_stop_START (0)
#define SOC_CPU_RTM_DFX_SIG_MON_dfx_trace_cnt_cal_div_stop_END (0)
#define SOC_CPU_RTM_DFX_SIG_MON_dfx_trace_cnt_cal_id_START (1)
#define SOC_CPU_RTM_DFX_SIG_MON_dfx_trace_cnt_cal_id_END (4)
#define SOC_CPU_RTM_DFX_SIG_MON_dfx_trace_cnt_cal_run_START (5)
#define SOC_CPU_RTM_DFX_SIG_MON_dfx_trace_cnt_cal_run_END (5)
#define SOC_CPU_RTM_DFX_SIG_MON_dfx_data_revc_st_START (6)
#define SOC_CPU_RTM_DFX_SIG_MON_dfx_data_revc_st_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_rtm_trace_sample : 32;
    } reg;
} SOC_CPU_RTM_DFX_RTM_TRACE_SAMPLE_UNION;
#endif
#define SOC_CPU_RTM_DFX_RTM_TRACE_SAMPLE_dfx_rtm_trace_sample_START (0)
#define SOC_CPU_RTM_DFX_RTM_TRACE_SAMPLE_dfx_rtm_trace_sample_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_rtm_trace_gen : 32;
    } reg;
} SOC_CPU_RTM_DFX_RTM_TRACE_GEN_UNION;
#endif
#define SOC_CPU_RTM_DFX_RTM_TRACE_GEN_dfx_rtm_trace_gen_START (0)
#define SOC_CPU_RTM_DFX_RTM_TRACE_GEN_dfx_rtm_trace_gen_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_rtm_trace_mst : 32;
    } reg;
} SOC_CPU_RTM_DFX_RTM_TRACE_MST_UNION;
#endif
#define SOC_CPU_RTM_DFX_RTM_TRACE_MST_dfx_rtm_trace_mst_START (0)
#define SOC_CPU_RTM_DFX_RTM_TRACE_MST_dfx_rtm_trace_mst_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_rtm_buffer : 32;
    } reg;
} SOC_CPU_RTM_DFX_RTM_BUFFER_UNION;
#endif
#define SOC_CPU_RTM_DFX_RTM_BUFFER_dfx_rtm_buffer_START (0)
#define SOC_CPU_RTM_DFX_RTM_BUFFER_dfx_rtm_buffer_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_dma_next_sdma_addr : 32;
    } reg;
} SOC_CPU_RTM_DFX_DMA_NEXT_SDMA_ADDR_UNION;
#endif
#define SOC_CPU_RTM_DFX_DMA_NEXT_SDMA_ADDR_dfx_dma_next_sdma_addr_START (0)
#define SOC_CPU_RTM_DFX_DMA_NEXT_SDMA_ADDR_dfx_dma_next_sdma_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_dma_next_adma_addr_l : 32;
    } reg;
} SOC_CPU_RTM_DFX_DMA_NEXT_ADMA_ADDR_L_UNION;
#endif
#define SOC_CPU_RTM_DFX_DMA_NEXT_ADMA_ADDR_L_dfx_dma_next_adma_addr_l_START (0)
#define SOC_CPU_RTM_DFX_DMA_NEXT_ADMA_ADDR_L_dfx_dma_next_adma_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_dma_next_adma_addr_h : 32;
    } reg;
} SOC_CPU_RTM_DFX_DMA_NEXT_ADMA_ADDR_H_UNION;
#endif
#define SOC_CPU_RTM_DFX_DMA_NEXT_ADMA_ADDR_H_dfx_dma_next_adma_addr_h_START (0)
#define SOC_CPU_RTM_DFX_DMA_NEXT_ADMA_ADDR_H_dfx_dma_next_adma_addr_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int axi_write_cnt : 8;
        unsigned int axi_aw_w_cnt : 8;
        unsigned int axi_read_cnt : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_CPU_RTM_DFX_DMA_AXI_TRANSFER_CNT_UNION;
#endif
#define SOC_CPU_RTM_DFX_DMA_AXI_TRANSFER_CNT_axi_write_cnt_START (0)
#define SOC_CPU_RTM_DFX_DMA_AXI_TRANSFER_CNT_axi_write_cnt_END (7)
#define SOC_CPU_RTM_DFX_DMA_AXI_TRANSFER_CNT_axi_aw_w_cnt_START (8)
#define SOC_CPU_RTM_DFX_DMA_AXI_TRANSFER_CNT_axi_aw_w_cnt_END (15)
#define SOC_CPU_RTM_DFX_DMA_AXI_TRANSFER_CNT_axi_read_cnt_START (16)
#define SOC_CPU_RTM_DFX_DMA_AXI_TRANSFER_CNT_axi_read_cnt_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int block_count_left : 16;
        unsigned int block_size_left : 12;
        unsigned int reserved : 4;
    } reg;
} SOC_CPU_RTM_DFX_DMA_BLOCK_VALUE_UNION;
#endif
#define SOC_CPU_RTM_DFX_DMA_BLOCK_VALUE_block_count_left_START (0)
#define SOC_CPU_RTM_DFX_DMA_BLOCK_VALUE_block_count_left_END (15)
#define SOC_CPU_RTM_DFX_DMA_BLOCK_VALUE_block_size_left_START (16)
#define SOC_CPU_RTM_DFX_DMA_BLOCK_VALUE_block_size_left_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adma_descriptor_0 : 32;
    } reg;
} SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_0_UNION;
#endif
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_0_adma_descriptor_0_START (0)
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_0_adma_descriptor_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adma_descriptor_1 : 32;
    } reg;
} SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_1_UNION;
#endif
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_1_adma_descriptor_1_START (0)
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_1_adma_descriptor_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adma_descriptor_2 : 32;
    } reg;
} SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_2_UNION;
#endif
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_2_adma_descriptor_2_START (0)
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_2_adma_descriptor_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adma_descriptor_3 : 32;
    } reg;
} SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_3_UNION;
#endif
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_3_adma_descriptor_3_START (0)
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_3_adma_descriptor_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int next_sram_byte_addr : 3;
        unsigned int next_sram_addr : 9;
        unsigned int reserved : 20;
    } reg;
} SOC_CPU_RTM_DFX_DMA_BUFFER_ADDR_UNION;
#endif
#define SOC_CPU_RTM_DFX_DMA_BUFFER_ADDR_next_sram_byte_addr_START (0)
#define SOC_CPU_RTM_DFX_DMA_BUFFER_ADDR_next_sram_byte_addr_END (2)
#define SOC_CPU_RTM_DFX_DMA_BUFFER_ADDR_next_sram_addr_START (3)
#define SOC_CPU_RTM_DFX_DMA_BUFFER_ADDR_next_sram_addr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_dma_descriptor_addr_l : 32;
    } reg;
} SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_ADDR_L_UNION;
#endif
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_ADDR_L_dfx_dma_descriptor_addr_l_START (0)
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_ADDR_L_dfx_dma_descriptor_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_dma_descriptor_addr_h : 32;
    } reg;
} SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_ADDR_H_UNION;
#endif
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_ADDR_H_dfx_dma_descriptor_addr_h_START (0)
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_ADDR_H_dfx_dma_descriptor_addr_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trans_descr_len_left : 17;
        unsigned int trans_descr_attr : 6;
        unsigned int trans_descr_valid : 1;
        unsigned int reserved : 8;
    } reg;
} SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_OTHERS_UNION;
#endif
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_OTHERS_trans_descr_len_left_START (0)
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_OTHERS_trans_descr_len_left_END (16)
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_OTHERS_trans_descr_attr_START (17)
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_OTHERS_trans_descr_attr_END (22)
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_OTHERS_trans_descr_valid_START (23)
#define SOC_CPU_RTM_DFX_DMA_DESCRIPTOR_OTHERS_trans_descr_valid_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sdma_next_descriptor_addr : 32;
    } reg;
} SOC_CPU_RTM_DFX_DMA_NEXT_SDMA_DESCR_ADDR_UNION;
#endif
#define SOC_CPU_RTM_DFX_DMA_NEXT_SDMA_DESCR_ADDR_sdma_next_descriptor_addr_START (0)
#define SOC_CPU_RTM_DFX_DMA_NEXT_SDMA_DESCR_ADDR_sdma_next_descriptor_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adma_next_descriptor_addr_l : 32;
    } reg;
} SOC_CPU_RTM_DFX_DMA_NEXT_ADMA_DESCR_ADDR_L_UNION;
#endif
#define SOC_CPU_RTM_DFX_DMA_NEXT_ADMA_DESCR_ADDR_L_adma_next_descriptor_addr_l_START (0)
#define SOC_CPU_RTM_DFX_DMA_NEXT_ADMA_DESCR_ADDR_L_adma_next_descriptor_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adma_next_descriptor_addr_h : 32;
    } reg;
} SOC_CPU_RTM_DFX_DMA_NEXT_ADMA_DESCR_ADDR_H_UNION;
#endif
#define SOC_CPU_RTM_DFX_DMA_NEXT_ADMA_DESCR_ADDR_H_adma_next_descriptor_addr_h_START (0)
#define SOC_CPU_RTM_DFX_DMA_NEXT_ADMA_DESCR_ADDR_H_adma_next_descriptor_addr_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adma_descriptor_length_left : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_CPU_RTM_DFX_DMA_ADMA_DESCR_LEN_LEFT_UNION;
#endif
#define SOC_CPU_RTM_DFX_DMA_ADMA_DESCR_LEN_LEFT_adma_descriptor_length_left_START (0)
#define SOC_CPU_RTM_DFX_DMA_ADMA_DESCR_LEN_LEFT_adma_descriptor_length_left_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_contx_table_value : 32;
    } reg;
} SOC_CPU_RTM_DFX_DMA_CONTX_TABLE_VALUE_UNION;
#endif
#define SOC_CPU_RTM_DFX_DMA_CONTX_TABLE_VALUE_dma_contx_table_value_START (0)
#define SOC_CPU_RTM_DFX_DMA_CONTX_TABLE_VALUE_dma_contx_table_value_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma_rresp_error_rid : 5;
        unsigned int dma_bresp_error_bid : 5;
        unsigned int reserved : 22;
    } reg;
} SOC_CPU_RTM_DFX_DMA_RESP_ERROR_INFO_UNION;
#endif
#define SOC_CPU_RTM_DFX_DMA_RESP_ERROR_INFO_dma_rresp_error_rid_START (0)
#define SOC_CPU_RTM_DFX_DMA_RESP_ERROR_INFO_dma_rresp_error_rid_END (4)
#define SOC_CPU_RTM_DFX_DMA_RESP_ERROR_INFO_dma_bresp_error_bid_START (5)
#define SOC_CPU_RTM_DFX_DMA_RESP_ERROR_INFO_dma_bresp_error_bid_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sd2axi_address : 16;
        unsigned int axi2sd_address : 16;
    } reg;
} SOC_CPU_RTM_DFX_DMA_AXI_SD_BUFFER_ADDR_UNION;
#endif
#define SOC_CPU_RTM_DFX_DMA_AXI_SD_BUFFER_ADDR_sd2axi_address_START (0)
#define SOC_CPU_RTM_DFX_DMA_AXI_SD_BUFFER_ADDR_sd2axi_address_END (15)
#define SOC_CPU_RTM_DFX_DMA_AXI_SD_BUFFER_ADDR_axi2sd_address_START (16)
#define SOC_CPU_RTM_DFX_DMA_AXI_SD_BUFFER_ADDR_axi2sd_address_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tp_send_in_progress : 1;
        unsigned int tp_group_counter : 4;
        unsigned int reserved_0 : 1;
        unsigned int tp_rtm_ready : 1;
        unsigned int tp_rtm_req : 1;
        unsigned int tp_rtm_sync : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_UNION;
#endif
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_tp_send_in_progress_START (0)
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_tp_send_in_progress_END (0)
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_tp_group_counter_START (1)
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_tp_group_counter_END (4)
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_tp_rtm_ready_START (6)
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_tp_rtm_ready_END (6)
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_tp_rtm_req_START (7)
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_tp_rtm_req_END (7)
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_tp_rtm_sync_START (8)
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_tp_rtm_sync_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tp_fifo_byte_count : 11;
        unsigned int tp_total_blk_count : 20;
        unsigned int tp_data_trans_complete : 1;
    } reg;
} SOC_CPU_RTM_DFX_RTM_TASK_CTRL_0_UNION;
#endif
#define SOC_CPU_RTM_DFX_RTM_TASK_CTRL_0_tp_fifo_byte_count_START (0)
#define SOC_CPU_RTM_DFX_RTM_TASK_CTRL_0_tp_fifo_byte_count_END (10)
#define SOC_CPU_RTM_DFX_RTM_TASK_CTRL_0_tp_total_blk_count_START (11)
#define SOC_CPU_RTM_DFX_RTM_TASK_CTRL_0_tp_total_blk_count_END (30)
#define SOC_CPU_RTM_DFX_RTM_TASK_CTRL_0_tp_data_trans_complete_START (31)
#define SOC_CPU_RTM_DFX_RTM_TASK_CTRL_0_tp_data_trans_complete_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tp_task_ctrl_fsm : 3;
        unsigned int tp_partition_index : 2;
        unsigned int tp_flush_done : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_CPU_RTM_DFX_RTM_TASK_CTRL_1_UNION;
#endif
#define SOC_CPU_RTM_DFX_RTM_TASK_CTRL_1_tp_task_ctrl_fsm_START (0)
#define SOC_CPU_RTM_DFX_RTM_TASK_CTRL_1_tp_task_ctrl_fsm_END (2)
#define SOC_CPU_RTM_DFX_RTM_TASK_CTRL_1_tp_partition_index_START (3)
#define SOC_CPU_RTM_DFX_RTM_TASK_CTRL_1_tp_partition_index_END (4)
#define SOC_CPU_RTM_DFX_RTM_TASK_CTRL_1_tp_flush_done_START (5)
#define SOC_CPU_RTM_DFX_RTM_TASK_CTRL_1_tp_flush_done_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tp_dma_resperr_tid : 5;
        unsigned int tp_dma_resperr_sts : 1;
        unsigned int tp_dma_resperr_trig : 1;
        unsigned int tp_dma_is_error : 1;
        unsigned int tp_dma_trans_done : 1;
        unsigned int tp_dma_is_idle : 1;
        unsigned int tp_dma_wakeup : 1;
        unsigned int tp_dma_halt_ack : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_CPU_RTM_DFX_DMA_TP_UNION;
#endif
#define SOC_CPU_RTM_DFX_DMA_TP_tp_dma_resperr_tid_START (0)
#define SOC_CPU_RTM_DFX_DMA_TP_tp_dma_resperr_tid_END (4)
#define SOC_CPU_RTM_DFX_DMA_TP_tp_dma_resperr_sts_START (5)
#define SOC_CPU_RTM_DFX_DMA_TP_tp_dma_resperr_sts_END (5)
#define SOC_CPU_RTM_DFX_DMA_TP_tp_dma_resperr_trig_START (6)
#define SOC_CPU_RTM_DFX_DMA_TP_tp_dma_resperr_trig_END (6)
#define SOC_CPU_RTM_DFX_DMA_TP_tp_dma_is_error_START (7)
#define SOC_CPU_RTM_DFX_DMA_TP_tp_dma_is_error_END (7)
#define SOC_CPU_RTM_DFX_DMA_TP_tp_dma_trans_done_START (8)
#define SOC_CPU_RTM_DFX_DMA_TP_tp_dma_trans_done_END (8)
#define SOC_CPU_RTM_DFX_DMA_TP_tp_dma_is_idle_START (9)
#define SOC_CPU_RTM_DFX_DMA_TP_tp_dma_is_idle_END (9)
#define SOC_CPU_RTM_DFX_DMA_TP_tp_dma_wakeup_START (10)
#define SOC_CPU_RTM_DFX_DMA_TP_tp_dma_wakeup_END (10)
#define SOC_CPU_RTM_DFX_DMA_TP_tp_dma_halt_ack_START (11)
#define SOC_CPU_RTM_DFX_DMA_TP_tp_dma_halt_ack_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int test_point_sel : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_CPU_RTM_TEST_POINT_SEL_UNION;
#endif
#define SOC_CPU_RTM_TEST_POINT_SEL_test_point_sel_START (0)
#define SOC_CPU_RTM_TEST_POINT_SEL_test_point_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hard_samp_en_time_l : 32;
    } reg;
} SOC_CPU_RTM_HARD_SAMP_EN_TIME_L_UNION;
#endif
#define SOC_CPU_RTM_HARD_SAMP_EN_TIME_L_hard_samp_en_time_l_START (0)
#define SOC_CPU_RTM_HARD_SAMP_EN_TIME_L_hard_samp_en_time_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hard_samp_en_time_h : 32;
    } reg;
} SOC_CPU_RTM_HARD_SAMP_EN_TIME_H_UNION;
#endif
#define SOC_CPU_RTM_HARD_SAMP_EN_TIME_H_hard_samp_en_time_h_START (0)
#define SOC_CPU_RTM_HARD_SAMP_EN_TIME_H_hard_samp_en_time_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hard_ts_en_time_l : 32;
    } reg;
} SOC_CPU_RTM_HARD_TS_EN_TIME_L_UNION;
#endif
#define SOC_CPU_RTM_HARD_TS_EN_TIME_L_hard_ts_en_time_l_START (0)
#define SOC_CPU_RTM_HARD_TS_EN_TIME_L_hard_ts_en_time_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hard_ts_en_time_h : 32;
    } reg;
} SOC_CPU_RTM_HARD_TS_EN_TIME_H_UNION;
#endif
#define SOC_CPU_RTM_HARD_TS_EN_TIME_H_hard_ts_en_time_h_START (0)
#define SOC_CPU_RTM_HARD_TS_EN_TIME_H_hard_ts_en_time_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_index_valid : 21;
        unsigned int reserved : 11;
    } reg;
} SOC_CPU_RTM_EVENT_INDEX_VALID_UNION;
#endif
#define SOC_CPU_RTM_EVENT_INDEX_VALID_event_index_valid_START (0)
#define SOC_CPU_RTM_EVENT_INDEX_VALID_event_index_valid_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtm_prccess_idle : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CPU_RTM_RTM_PROCESS_IDLE_UNION;
#endif
#define SOC_CPU_RTM_RTM_PROCESS_IDLE_rtm_prccess_idle_START (0)
#define SOC_CPU_RTM_RTM_PROCESS_IDLE_rtm_prccess_idle_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ckg_byp_ckg_rtm_apb : 1;
        unsigned int ckg_byp_ckg_rtm_sync : 1;
        unsigned int ckg_byp_ckg_rtm_sync_align : 1;
        unsigned int ckg_byp_ckg_rtm_sigmon : 1;
        unsigned int ckg_byp_ckg_rtm_trace_sample : 1;
        unsigned int ckg_byp_ckg_rtm_trace_gen : 1;
        unsigned int ckg_byp_ckg_rtm_trace_mst : 1;
        unsigned int ckg_byp_ckg_rtm_buffer : 1;
        unsigned int ckg_byp_ckg_rtm_task_ctrl_dma : 1;
        unsigned int ckg_byp_ckg_rtm_fc_counter : 1;
        unsigned int ckg_byp_ckg_rtm_cpu_crg_dbg : 1;
        unsigned int ckg_byp_ckg_rtm_latcnt : 1;
        unsigned int ckg_byp_ckg_rtm_latmonitor : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_CPU_RTM_RTM_CKG_BYPASS_UNION;
#endif
#define SOC_CPU_RTM_RTM_CKG_BYPASS_ckg_byp_ckg_rtm_apb_START (0)
#define SOC_CPU_RTM_RTM_CKG_BYPASS_ckg_byp_ckg_rtm_apb_END (0)
#define SOC_CPU_RTM_RTM_CKG_BYPASS_ckg_byp_ckg_rtm_sync_START (1)
#define SOC_CPU_RTM_RTM_CKG_BYPASS_ckg_byp_ckg_rtm_sync_END (1)
#define SOC_CPU_RTM_RTM_CKG_BYPASS_ckg_byp_ckg_rtm_sync_align_START (2)
#define SOC_CPU_RTM_RTM_CKG_BYPASS_ckg_byp_ckg_rtm_sync_align_END (2)
#define SOC_CPU_RTM_RTM_CKG_BYPASS_ckg_byp_ckg_rtm_sigmon_START (3)
#define SOC_CPU_RTM_RTM_CKG_BYPASS_ckg_byp_ckg_rtm_sigmon_END (3)
#define SOC_CPU_RTM_RTM_CKG_BYPASS_ckg_byp_ckg_rtm_trace_sample_START (4)
#define SOC_CPU_RTM_RTM_CKG_BYPASS_ckg_byp_ckg_rtm_trace_sample_END (4)
#define SOC_CPU_RTM_RTM_CKG_BYPASS_ckg_byp_ckg_rtm_trace_gen_START (5)
#define SOC_CPU_RTM_RTM_CKG_BYPASS_ckg_byp_ckg_rtm_trace_gen_END (5)
#define SOC_CPU_RTM_RTM_CKG_BYPASS_ckg_byp_ckg_rtm_trace_mst_START (6)
#define SOC_CPU_RTM_RTM_CKG_BYPASS_ckg_byp_ckg_rtm_trace_mst_END (6)
#define SOC_CPU_RTM_RTM_CKG_BYPASS_ckg_byp_ckg_rtm_buffer_START (7)
#define SOC_CPU_RTM_RTM_CKG_BYPASS_ckg_byp_ckg_rtm_buffer_END (7)
#define SOC_CPU_RTM_RTM_CKG_BYPASS_ckg_byp_ckg_rtm_task_ctrl_dma_START (8)
#define SOC_CPU_RTM_RTM_CKG_BYPASS_ckg_byp_ckg_rtm_task_ctrl_dma_END (8)
#define SOC_CPU_RTM_RTM_CKG_BYPASS_ckg_byp_ckg_rtm_fc_counter_START (9)
#define SOC_CPU_RTM_RTM_CKG_BYPASS_ckg_byp_ckg_rtm_fc_counter_END (9)
#define SOC_CPU_RTM_RTM_CKG_BYPASS_ckg_byp_ckg_rtm_cpu_crg_dbg_START (10)
#define SOC_CPU_RTM_RTM_CKG_BYPASS_ckg_byp_ckg_rtm_cpu_crg_dbg_END (10)
#define SOC_CPU_RTM_RTM_CKG_BYPASS_ckg_byp_ckg_rtm_latcnt_START (11)
#define SOC_CPU_RTM_RTM_CKG_BYPASS_ckg_byp_ckg_rtm_latcnt_END (11)
#define SOC_CPU_RTM_RTM_CKG_BYPASS_ckg_byp_ckg_rtm_latmonitor_START (12)
#define SOC_CPU_RTM_RTM_CKG_BYPASS_ckg_byp_ckg_rtm_latmonitor_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ckg_wakeup_en_rtm_apb : 1;
        unsigned int ckg_wakeup_en_rtm_sync : 1;
        unsigned int ckg_wakeup_en_rtm_sync_align : 1;
        unsigned int ckg_wakeup_en_rtm_sigmon : 1;
        unsigned int ckg_wakeup_en_rtm_trace_sample : 1;
        unsigned int ckg_wakeup_en_rtm_trace_gen : 1;
        unsigned int ckg_wakeup_en_rtm_trace_mst : 1;
        unsigned int ckg_wakeup_en_rtm_buffer : 1;
        unsigned int ckg_wakeup_en_rtm_task_ctrl_dma : 1;
        unsigned int ckg_wakeup_en_rtm_fc_counter : 1;
        unsigned int ckg_wakeup_en_rtm_cpu_crg_dbg : 1;
        unsigned int ckg_wakeup_en_rtm_latcnt : 1;
        unsigned int ckg_wakeup_en_rtm_latmonitor : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_CPU_RTM_RTM_CKG_WAKEUP_EN_UNION;
#endif
#define SOC_CPU_RTM_RTM_CKG_WAKEUP_EN_ckg_wakeup_en_rtm_apb_START (0)
#define SOC_CPU_RTM_RTM_CKG_WAKEUP_EN_ckg_wakeup_en_rtm_apb_END (0)
#define SOC_CPU_RTM_RTM_CKG_WAKEUP_EN_ckg_wakeup_en_rtm_sync_START (1)
#define SOC_CPU_RTM_RTM_CKG_WAKEUP_EN_ckg_wakeup_en_rtm_sync_END (1)
#define SOC_CPU_RTM_RTM_CKG_WAKEUP_EN_ckg_wakeup_en_rtm_sync_align_START (2)
#define SOC_CPU_RTM_RTM_CKG_WAKEUP_EN_ckg_wakeup_en_rtm_sync_align_END (2)
#define SOC_CPU_RTM_RTM_CKG_WAKEUP_EN_ckg_wakeup_en_rtm_sigmon_START (3)
#define SOC_CPU_RTM_RTM_CKG_WAKEUP_EN_ckg_wakeup_en_rtm_sigmon_END (3)
#define SOC_CPU_RTM_RTM_CKG_WAKEUP_EN_ckg_wakeup_en_rtm_trace_sample_START (4)
#define SOC_CPU_RTM_RTM_CKG_WAKEUP_EN_ckg_wakeup_en_rtm_trace_sample_END (4)
#define SOC_CPU_RTM_RTM_CKG_WAKEUP_EN_ckg_wakeup_en_rtm_trace_gen_START (5)
#define SOC_CPU_RTM_RTM_CKG_WAKEUP_EN_ckg_wakeup_en_rtm_trace_gen_END (5)
#define SOC_CPU_RTM_RTM_CKG_WAKEUP_EN_ckg_wakeup_en_rtm_trace_mst_START (6)
#define SOC_CPU_RTM_RTM_CKG_WAKEUP_EN_ckg_wakeup_en_rtm_trace_mst_END (6)
#define SOC_CPU_RTM_RTM_CKG_WAKEUP_EN_ckg_wakeup_en_rtm_buffer_START (7)
#define SOC_CPU_RTM_RTM_CKG_WAKEUP_EN_ckg_wakeup_en_rtm_buffer_END (7)
#define SOC_CPU_RTM_RTM_CKG_WAKEUP_EN_ckg_wakeup_en_rtm_task_ctrl_dma_START (8)
#define SOC_CPU_RTM_RTM_CKG_WAKEUP_EN_ckg_wakeup_en_rtm_task_ctrl_dma_END (8)
#define SOC_CPU_RTM_RTM_CKG_WAKEUP_EN_ckg_wakeup_en_rtm_fc_counter_START (9)
#define SOC_CPU_RTM_RTM_CKG_WAKEUP_EN_ckg_wakeup_en_rtm_fc_counter_END (9)
#define SOC_CPU_RTM_RTM_CKG_WAKEUP_EN_ckg_wakeup_en_rtm_cpu_crg_dbg_START (10)
#define SOC_CPU_RTM_RTM_CKG_WAKEUP_EN_ckg_wakeup_en_rtm_cpu_crg_dbg_END (10)
#define SOC_CPU_RTM_RTM_CKG_WAKEUP_EN_ckg_wakeup_en_rtm_latcnt_START (11)
#define SOC_CPU_RTM_RTM_CKG_WAKEUP_EN_ckg_wakeup_en_rtm_latcnt_END (11)
#define SOC_CPU_RTM_RTM_CKG_WAKEUP_EN_ckg_wakeup_en_rtm_latmonitor_START (12)
#define SOC_CPU_RTM_RTM_CKG_WAKEUP_EN_ckg_wakeup_en_rtm_latmonitor_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ckg_busy_rtm_apb : 1;
        unsigned int ckg_busy_rtm_sync_align : 1;
        unsigned int ckg_busy_rtm_trace_sample : 1;
        unsigned int ckg_busy_rtm_trace_gen : 1;
        unsigned int ckg_busy_rtm_trace_mst : 1;
        unsigned int ckg_busy_rtm_buffer : 1;
        unsigned int ckg_busy_rtm_task_ctrl_dma : 1;
        unsigned int ckg_busy_rtm_fc_counter : 1;
        unsigned int ckg_busy_rtm_cpu_crg_dbg : 1;
        unsigned int ckg_busy_rtm_latcnt : 1;
        unsigned int ckg_busy_rtm_latmonitor0 : 1;
        unsigned int ckg_busy_rtm_latmonitor1 : 1;
        unsigned int ckg_busy_rtm_latmonitor2 : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_CPU_RTM_RTM_CKG_BUSY_UNION;
#endif
#define SOC_CPU_RTM_RTM_CKG_BUSY_ckg_busy_rtm_apb_START (0)
#define SOC_CPU_RTM_RTM_CKG_BUSY_ckg_busy_rtm_apb_END (0)
#define SOC_CPU_RTM_RTM_CKG_BUSY_ckg_busy_rtm_sync_align_START (1)
#define SOC_CPU_RTM_RTM_CKG_BUSY_ckg_busy_rtm_sync_align_END (1)
#define SOC_CPU_RTM_RTM_CKG_BUSY_ckg_busy_rtm_trace_sample_START (2)
#define SOC_CPU_RTM_RTM_CKG_BUSY_ckg_busy_rtm_trace_sample_END (2)
#define SOC_CPU_RTM_RTM_CKG_BUSY_ckg_busy_rtm_trace_gen_START (3)
#define SOC_CPU_RTM_RTM_CKG_BUSY_ckg_busy_rtm_trace_gen_END (3)
#define SOC_CPU_RTM_RTM_CKG_BUSY_ckg_busy_rtm_trace_mst_START (4)
#define SOC_CPU_RTM_RTM_CKG_BUSY_ckg_busy_rtm_trace_mst_END (4)
#define SOC_CPU_RTM_RTM_CKG_BUSY_ckg_busy_rtm_buffer_START (5)
#define SOC_CPU_RTM_RTM_CKG_BUSY_ckg_busy_rtm_buffer_END (5)
#define SOC_CPU_RTM_RTM_CKG_BUSY_ckg_busy_rtm_task_ctrl_dma_START (6)
#define SOC_CPU_RTM_RTM_CKG_BUSY_ckg_busy_rtm_task_ctrl_dma_END (6)
#define SOC_CPU_RTM_RTM_CKG_BUSY_ckg_busy_rtm_fc_counter_START (7)
#define SOC_CPU_RTM_RTM_CKG_BUSY_ckg_busy_rtm_fc_counter_END (7)
#define SOC_CPU_RTM_RTM_CKG_BUSY_ckg_busy_rtm_cpu_crg_dbg_START (8)
#define SOC_CPU_RTM_RTM_CKG_BUSY_ckg_busy_rtm_cpu_crg_dbg_END (8)
#define SOC_CPU_RTM_RTM_CKG_BUSY_ckg_busy_rtm_latcnt_START (9)
#define SOC_CPU_RTM_RTM_CKG_BUSY_ckg_busy_rtm_latcnt_END (9)
#define SOC_CPU_RTM_RTM_CKG_BUSY_ckg_busy_rtm_latmonitor0_START (10)
#define SOC_CPU_RTM_RTM_CKG_BUSY_ckg_busy_rtm_latmonitor0_END (10)
#define SOC_CPU_RTM_RTM_CKG_BUSY_ckg_busy_rtm_latmonitor1_START (11)
#define SOC_CPU_RTM_RTM_CKG_BUSY_ckg_busy_rtm_latmonitor1_END (11)
#define SOC_CPU_RTM_RTM_CKG_BUSY_ckg_busy_rtm_latmonitor2_START (12)
#define SOC_CPU_RTM_RTM_CKG_BUSY_ckg_busy_rtm_latmonitor2_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ckg_busy_rtm_sync0 : 1;
        unsigned int ckg_busy_rtm_sync1 : 1;
        unsigned int ckg_busy_rtm_sync2 : 1;
        unsigned int ckg_busy_rtm_sync3 : 1;
        unsigned int ckg_busy_rtm_sync4 : 1;
        unsigned int ckg_busy_rtm_sync5 : 1;
        unsigned int ckg_busy_rtm_sync6 : 1;
        unsigned int ckg_busy_rtm_sync7 : 1;
        unsigned int ckg_busy_rtm_sync8 : 1;
        unsigned int ckg_busy_rtm_sync9 : 1;
        unsigned int ckg_busy_rtm_sync10 : 1;
        unsigned int ckg_busy_rtm_sync11 : 1;
        unsigned int ckg_busy_rtm_sync12 : 1;
        unsigned int ckg_busy_rtm_sync13 : 1;
        unsigned int ckg_busy_rtm_sync14_1 : 1;
        unsigned int ckg_busy_rtm_sync15_1 : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_UNION;
#endif
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync0_START (0)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync0_END (0)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync1_START (1)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync1_END (1)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync2_START (2)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync2_END (2)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync3_START (3)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync3_END (3)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync4_START (4)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync4_END (4)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync5_START (5)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync5_END (5)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync6_START (6)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync6_END (6)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync7_START (7)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync7_END (7)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync8_START (8)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync8_END (8)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync9_START (9)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync9_END (9)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync10_START (10)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync10_END (10)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync11_START (11)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync11_END (11)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync12_START (12)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync12_END (12)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync13_START (13)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync13_END (13)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync14_1_START (14)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync14_1_END (14)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync15_1_START (15)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SYNC_ckg_busy_rtm_sync15_1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ckg_busy_rtm_sigmon0 : 1;
        unsigned int ckg_busy_rtm_sigmon1 : 1;
        unsigned int ckg_busy_rtm_sigmon2 : 1;
        unsigned int ckg_busy_rtm_sigmon3 : 1;
        unsigned int ckg_busy_rtm_sigmon4 : 1;
        unsigned int ckg_busy_rtm_sigmon5 : 1;
        unsigned int ckg_busy_rtm_sigmon6 : 1;
        unsigned int ckg_busy_rtm_sigmon7 : 1;
        unsigned int ckg_busy_rtm_sigmon8 : 1;
        unsigned int ckg_busy_rtm_sigmon9 : 1;
        unsigned int ckg_busy_rtm_sigmon10 : 1;
        unsigned int ckg_busy_rtm_sigmon11 : 1;
        unsigned int ckg_busy_rtm_sigmon12 : 1;
        unsigned int ckg_busy_rtm_sigmon13 : 1;
        unsigned int ckg_busy_rtm_sigmon14_1 : 1;
        unsigned int ckg_busy_rtm_sigmon15_1 : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_UNION;
#endif
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon0_START (0)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon0_END (0)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon1_START (1)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon1_END (1)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon2_START (2)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon2_END (2)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon3_START (3)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon3_END (3)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon4_START (4)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon4_END (4)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon5_START (5)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon5_END (5)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon6_START (6)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon6_END (6)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon7_START (7)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon7_END (7)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon8_START (8)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon8_END (8)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon9_START (9)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon9_END (9)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon10_START (10)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon10_END (10)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon11_START (11)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon11_END (11)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon12_START (12)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon12_END (12)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon13_START (13)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon13_END (13)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon14_1_START (14)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon14_1_END (14)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon15_1_START (15)
#define SOC_CPU_RTM_RTM_CKG_BUSY_SIGMON_ckg_busy_rtm_sigmon15_1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int awcache : 4;
        unsigned int arcache : 4;
        unsigned int awdomain : 2;
        unsigned int ardomain : 2;
        unsigned int reserved : 20;
    } reg;
} SOC_CPU_RTM_AXI_CONF_UNION;
#endif
#define SOC_CPU_RTM_AXI_CONF_awcache_START (0)
#define SOC_CPU_RTM_AXI_CONF_awcache_END (3)
#define SOC_CPU_RTM_AXI_CONF_arcache_START (4)
#define SOC_CPU_RTM_AXI_CONF_arcache_END (7)
#define SOC_CPU_RTM_AXI_CONF_awdomain_START (8)
#define SOC_CPU_RTM_AXI_CONF_awdomain_END (9)
#define SOC_CPU_RTM_AXI_CONF_ardomain_START (10)
#define SOC_CPU_RTM_AXI_CONF_ardomain_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int software_reset_latency_cnt : 1;
        unsigned int software_reset_latency_monitor : 1;
        unsigned int reserved : 14;
        unsigned int latcnt_clr_latency_cnt : 16;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_SOFTWARE_RESET_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_SOFTWARE_RESET_software_reset_latency_cnt_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_SOFTWARE_RESET_software_reset_latency_cnt_END (0)
#define SOC_CPU_RTM_LATENCY_CNT_SOFTWARE_RESET_software_reset_latency_monitor_START (1)
#define SOC_CPU_RTM_LATENCY_CNT_SOFTWARE_RESET_software_reset_latency_monitor_END (1)
#define SOC_CPU_RTM_LATENCY_CNT_SOFTWARE_RESET_latcnt_clr_latency_cnt_START (16)
#define SOC_CPU_RTM_LATENCY_CNT_SOFTWARE_RESET_latcnt_clr_latency_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int latcnt_auto_clr_timeout : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_CONFIG1_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_CONFIG1_latcnt_auto_clr_timeout_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_CONFIG1_latcnt_auto_clr_timeout_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int latcnt_int_threshold : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_CONFIG2_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_CONFIG2_latcnt_int_threshold_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_CONFIG2_latcnt_int_threshold_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int latcnt_min_cnt : 16;
        unsigned int latcnt_max_cnt : 16;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_CONFIG3_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_CONFIG3_latcnt_min_cnt_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_CONFIG3_latcnt_min_cnt_END (15)
#define SOC_CPU_RTM_LATENCY_CNT_CONFIG3_latcnt_max_cnt_START (16)
#define SOC_CPU_RTM_LATENCY_CNT_CONFIG3_latcnt_max_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int latmnt_cfg_en : 3;
        unsigned int reserved_0 : 2;
        unsigned int latmnt_read_type_byp : 5;
        unsigned int latmnt_data_size_chk_byp : 1;
        unsigned int latmnt_debug_en : 1;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_CPU_RTM_LATENCY_MONITOR_CONFIG1_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG1_latmnt_cfg_en_START (0)
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG1_latmnt_cfg_en_END (2)
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG1_latmnt_read_type_byp_START (5)
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG1_latmnt_read_type_byp_END (9)
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG1_latmnt_data_size_chk_byp_START (10)
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG1_latmnt_data_size_chk_byp_END (10)
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG1_latmnt_debug_en_START (11)
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG1_latmnt_debug_en_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int latmnt_crsp_retry_opcode_match : 21;
        unsigned int reserved : 11;
    } reg;
} SOC_CPU_RTM_LATENCY_MONITOR_CONFIG2_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG2_latmnt_crsp_retry_opcode_match_START (0)
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG2_latmnt_crsp_retry_opcode_match_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int latmnt_rxdata_retry_fwdstate_match : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_CPU_RTM_LATENCY_MONITOR_CONFIG3_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG3_latmnt_rxdata_retry_fwdstate_match_START (0)
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG3_latmnt_rxdata_retry_fwdstate_match_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int latmnt_rxdata_done_opcode_match : 16;
        unsigned int latmnt_crsp_retry_resperr_match : 4;
        unsigned int reserved : 12;
    } reg;
} SOC_CPU_RTM_LATENCY_MONITOR_CONFIG4_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG4_latmnt_rxdata_done_opcode_match_START (0)
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG4_latmnt_rxdata_done_opcode_match_END (15)
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG4_latmnt_crsp_retry_resperr_match_START (16)
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG4_latmnt_crsp_retry_resperr_match_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid0_latency_qos0_avg0 : 9;
        unsigned int lpid0_latency_qos0_min0 : 9;
        unsigned int lpid0_latency_qos0_max0 : 9;
        unsigned int lpid0_qos0 : 3;
        unsigned int lpid0_cnt4_qos0_valid : 1;
        unsigned int lpid0_cnt8_qos0_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS0_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS0_lpid0_latency_qos0_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS0_lpid0_latency_qos0_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS0_lpid0_latency_qos0_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS0_lpid0_latency_qos0_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS0_lpid0_latency_qos0_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS0_lpid0_latency_qos0_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS0_lpid0_qos0_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS0_lpid0_qos0_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS0_lpid0_cnt4_qos0_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS0_lpid0_cnt4_qos0_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS0_lpid0_cnt8_qos0_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS0_lpid0_cnt8_qos0_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid0_latency_qos1_avg0 : 9;
        unsigned int lpid0_latency_qos1_min0 : 9;
        unsigned int lpid0_latency_qos1_max0 : 9;
        unsigned int lpid0_qos1 : 3;
        unsigned int lpid0_cnt4_qos1_valid : 1;
        unsigned int lpid0_cnt8_qos1_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS1_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS1_lpid0_latency_qos1_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS1_lpid0_latency_qos1_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS1_lpid0_latency_qos1_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS1_lpid0_latency_qos1_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS1_lpid0_latency_qos1_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS1_lpid0_latency_qos1_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS1_lpid0_qos1_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS1_lpid0_qos1_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS1_lpid0_cnt4_qos1_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS1_lpid0_cnt4_qos1_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS1_lpid0_cnt8_qos1_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS1_lpid0_cnt8_qos1_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid0_latency_qos2_avg0 : 9;
        unsigned int lpid0_latency_qos2_min0 : 9;
        unsigned int lpid0_latency_qos2_max0 : 9;
        unsigned int lpid0_qos2 : 3;
        unsigned int lpid0_cnt4_qos2_valid : 1;
        unsigned int lpid0_cnt8_qos2_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS2_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS2_lpid0_latency_qos2_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS2_lpid0_latency_qos2_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS2_lpid0_latency_qos2_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS2_lpid0_latency_qos2_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS2_lpid0_latency_qos2_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS2_lpid0_latency_qos2_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS2_lpid0_qos2_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS2_lpid0_qos2_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS2_lpid0_cnt4_qos2_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS2_lpid0_cnt4_qos2_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS2_lpid0_cnt8_qos2_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS2_lpid0_cnt8_qos2_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid0_latency_qos3_avg0 : 9;
        unsigned int lpid0_latency_qos3_min0 : 9;
        unsigned int lpid0_latency_qos3_max0 : 9;
        unsigned int lpid0_qos3 : 3;
        unsigned int lpid0_cnt4_qos3_valid : 1;
        unsigned int lpid0_cnt8_qos3_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS3_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS3_lpid0_latency_qos3_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS3_lpid0_latency_qos3_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS3_lpid0_latency_qos3_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS3_lpid0_latency_qos3_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS3_lpid0_latency_qos3_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS3_lpid0_latency_qos3_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS3_lpid0_qos3_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS3_lpid0_qos3_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS3_lpid0_cnt4_qos3_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS3_lpid0_cnt4_qos3_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS3_lpid0_cnt8_qos3_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID0_QOS3_lpid0_cnt8_qos3_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid1_latency_qos0_avg0 : 9;
        unsigned int lpid1_latency_qos0_min0 : 9;
        unsigned int lpid1_latency_qos0_max0 : 9;
        unsigned int lpid1_qos0 : 3;
        unsigned int lpid1_cnt4_qos0_valid : 1;
        unsigned int lpid1_cnt8_qos0_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS0_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS0_lpid1_latency_qos0_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS0_lpid1_latency_qos0_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS0_lpid1_latency_qos0_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS0_lpid1_latency_qos0_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS0_lpid1_latency_qos0_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS0_lpid1_latency_qos0_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS0_lpid1_qos0_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS0_lpid1_qos0_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS0_lpid1_cnt4_qos0_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS0_lpid1_cnt4_qos0_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS0_lpid1_cnt8_qos0_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS0_lpid1_cnt8_qos0_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid1_latency_qos1_avg0 : 9;
        unsigned int lpid1_latency_qos1_min0 : 9;
        unsigned int lpid1_latency_qos1_max0 : 9;
        unsigned int lpid1_qos1 : 3;
        unsigned int lpid1_cnt4_qos1_valid : 1;
        unsigned int lpid1_cnt8_qos1_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS1_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS1_lpid1_latency_qos1_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS1_lpid1_latency_qos1_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS1_lpid1_latency_qos1_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS1_lpid1_latency_qos1_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS1_lpid1_latency_qos1_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS1_lpid1_latency_qos1_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS1_lpid1_qos1_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS1_lpid1_qos1_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS1_lpid1_cnt4_qos1_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS1_lpid1_cnt4_qos1_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS1_lpid1_cnt8_qos1_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS1_lpid1_cnt8_qos1_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid1_latency_qos2_avg0 : 9;
        unsigned int lpid1_latency_qos2_min0 : 9;
        unsigned int lpid1_latency_qos2_max0 : 9;
        unsigned int lpid1_qos2 : 3;
        unsigned int lpid1_cnt4_qos2_valid : 1;
        unsigned int lpid1_cnt8_qos2_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS2_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS2_lpid1_latency_qos2_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS2_lpid1_latency_qos2_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS2_lpid1_latency_qos2_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS2_lpid1_latency_qos2_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS2_lpid1_latency_qos2_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS2_lpid1_latency_qos2_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS2_lpid1_qos2_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS2_lpid1_qos2_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS2_lpid1_cnt4_qos2_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS2_lpid1_cnt4_qos2_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS2_lpid1_cnt8_qos2_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS2_lpid1_cnt8_qos2_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid1_latency_qos3_avg0 : 9;
        unsigned int lpid1_latency_qos3_min0 : 9;
        unsigned int lpid1_latency_qos3_max0 : 9;
        unsigned int lpid1_qos3 : 3;
        unsigned int lpid1_cnt4_qos3_valid : 1;
        unsigned int lpid1_cnt8_qos3_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS3_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS3_lpid1_latency_qos3_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS3_lpid1_latency_qos3_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS3_lpid1_latency_qos3_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS3_lpid1_latency_qos3_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS3_lpid1_latency_qos3_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS3_lpid1_latency_qos3_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS3_lpid1_qos3_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS3_lpid1_qos3_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS3_lpid1_cnt4_qos3_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS3_lpid1_cnt4_qos3_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS3_lpid1_cnt8_qos3_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID1_QOS3_lpid1_cnt8_qos3_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid2_latency_qos0_avg0 : 9;
        unsigned int lpid2_latency_qos0_min0 : 9;
        unsigned int lpid2_latency_qos0_max0 : 9;
        unsigned int lpid2_qos0 : 3;
        unsigned int lpid2_cnt4_qos0_valid : 1;
        unsigned int lpid2_cnt8_qos0_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS0_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS0_lpid2_latency_qos0_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS0_lpid2_latency_qos0_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS0_lpid2_latency_qos0_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS0_lpid2_latency_qos0_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS0_lpid2_latency_qos0_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS0_lpid2_latency_qos0_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS0_lpid2_qos0_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS0_lpid2_qos0_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS0_lpid2_cnt4_qos0_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS0_lpid2_cnt4_qos0_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS0_lpid2_cnt8_qos0_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS0_lpid2_cnt8_qos0_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid2_latency_qos1_avg0 : 9;
        unsigned int lpid2_latency_qos1_min0 : 9;
        unsigned int lpid2_latency_qos1_max0 : 9;
        unsigned int lpid2_qos1 : 3;
        unsigned int lpid2_cnt4_qos1_valid : 1;
        unsigned int lpid2_cnt8_qos1_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS1_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS1_lpid2_latency_qos1_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS1_lpid2_latency_qos1_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS1_lpid2_latency_qos1_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS1_lpid2_latency_qos1_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS1_lpid2_latency_qos1_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS1_lpid2_latency_qos1_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS1_lpid2_qos1_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS1_lpid2_qos1_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS1_lpid2_cnt4_qos1_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS1_lpid2_cnt4_qos1_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS1_lpid2_cnt8_qos1_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS1_lpid2_cnt8_qos1_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid2_latency_qos2_avg0 : 9;
        unsigned int lpid2_latency_qos2_min0 : 9;
        unsigned int lpid2_latency_qos2_max0 : 9;
        unsigned int lpid2_qos2 : 3;
        unsigned int lpid2_cnt4_qos2_valid : 1;
        unsigned int lpid2_cnt8_qos2_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS2_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS2_lpid2_latency_qos2_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS2_lpid2_latency_qos2_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS2_lpid2_latency_qos2_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS2_lpid2_latency_qos2_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS2_lpid2_latency_qos2_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS2_lpid2_latency_qos2_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS2_lpid2_qos2_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS2_lpid2_qos2_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS2_lpid2_cnt4_qos2_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS2_lpid2_cnt4_qos2_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS2_lpid2_cnt8_qos2_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS2_lpid2_cnt8_qos2_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid2_latency_qos3_avg0 : 9;
        unsigned int lpid2_latency_qos3_min0 : 9;
        unsigned int lpid2_latency_qos3_max0 : 9;
        unsigned int lpid2_qos3 : 3;
        unsigned int lpid2_cnt4_qos3_valid : 1;
        unsigned int lpid2_cnt8_qos3_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS3_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS3_lpid2_latency_qos3_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS3_lpid2_latency_qos3_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS3_lpid2_latency_qos3_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS3_lpid2_latency_qos3_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS3_lpid2_latency_qos3_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS3_lpid2_latency_qos3_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS3_lpid2_qos3_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS3_lpid2_qos3_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS3_lpid2_cnt4_qos3_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS3_lpid2_cnt4_qos3_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS3_lpid2_cnt8_qos3_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID2_QOS3_lpid2_cnt8_qos3_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid3_latency_qos0_avg0 : 9;
        unsigned int lpid3_latency_qos0_min0 : 9;
        unsigned int lpid3_latency_qos0_max0 : 9;
        unsigned int lpid3_qos0 : 3;
        unsigned int lpid3_cnt4_qos0_valid : 1;
        unsigned int lpid3_cnt8_qos0_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS0_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS0_lpid3_latency_qos0_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS0_lpid3_latency_qos0_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS0_lpid3_latency_qos0_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS0_lpid3_latency_qos0_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS0_lpid3_latency_qos0_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS0_lpid3_latency_qos0_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS0_lpid3_qos0_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS0_lpid3_qos0_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS0_lpid3_cnt4_qos0_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS0_lpid3_cnt4_qos0_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS0_lpid3_cnt8_qos0_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS0_lpid3_cnt8_qos0_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid3_latency_qos1_avg0 : 9;
        unsigned int lpid3_latency_qos1_min0 : 9;
        unsigned int lpid3_latency_qos1_max0 : 9;
        unsigned int lpid3_qos1 : 3;
        unsigned int lpid3_cnt4_qos1_valid : 1;
        unsigned int lpid3_cnt8_qos1_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS1_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS1_lpid3_latency_qos1_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS1_lpid3_latency_qos1_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS1_lpid3_latency_qos1_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS1_lpid3_latency_qos1_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS1_lpid3_latency_qos1_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS1_lpid3_latency_qos1_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS1_lpid3_qos1_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS1_lpid3_qos1_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS1_lpid3_cnt4_qos1_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS1_lpid3_cnt4_qos1_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS1_lpid3_cnt8_qos1_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS1_lpid3_cnt8_qos1_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid3_latency_qos2_avg0 : 9;
        unsigned int lpid3_latency_qos2_min0 : 9;
        unsigned int lpid3_latency_qos2_max0 : 9;
        unsigned int lpid3_qos2 : 3;
        unsigned int lpid3_cnt4_qos2_valid : 1;
        unsigned int lpid3_cnt8_qos2_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS2_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS2_lpid3_latency_qos2_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS2_lpid3_latency_qos2_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS2_lpid3_latency_qos2_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS2_lpid3_latency_qos2_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS2_lpid3_latency_qos2_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS2_lpid3_latency_qos2_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS2_lpid3_qos2_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS2_lpid3_qos2_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS2_lpid3_cnt4_qos2_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS2_lpid3_cnt4_qos2_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS2_lpid3_cnt8_qos2_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS2_lpid3_cnt8_qos2_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid3_latency_qos3_avg0 : 9;
        unsigned int lpid3_latency_qos3_min0 : 9;
        unsigned int lpid3_latency_qos3_max0 : 9;
        unsigned int lpid3_qos3 : 3;
        unsigned int lpid3_cnt4_qos3_valid : 1;
        unsigned int lpid3_cnt8_qos3_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS3_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS3_lpid3_latency_qos3_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS3_lpid3_latency_qos3_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS3_lpid3_latency_qos3_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS3_lpid3_latency_qos3_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS3_lpid3_latency_qos3_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS3_lpid3_latency_qos3_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS3_lpid3_qos3_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS3_lpid3_qos3_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS3_lpid3_cnt4_qos3_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS3_lpid3_cnt4_qos3_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS3_lpid3_cnt8_qos3_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID3_QOS3_lpid3_cnt8_qos3_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid4_latency_qos0_avg0 : 9;
        unsigned int lpid4_latency_qos0_min0 : 9;
        unsigned int lpid4_latency_qos0_max0 : 9;
        unsigned int lpid4_qos0 : 3;
        unsigned int lpid4_cnt4_qos0_valid : 1;
        unsigned int lpid4_cnt8_qos0_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS0_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS0_lpid4_latency_qos0_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS0_lpid4_latency_qos0_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS0_lpid4_latency_qos0_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS0_lpid4_latency_qos0_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS0_lpid4_latency_qos0_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS0_lpid4_latency_qos0_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS0_lpid4_qos0_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS0_lpid4_qos0_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS0_lpid4_cnt4_qos0_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS0_lpid4_cnt4_qos0_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS0_lpid4_cnt8_qos0_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS0_lpid4_cnt8_qos0_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid4_latency_qos1_avg0 : 9;
        unsigned int lpid4_latency_qos1_min0 : 9;
        unsigned int lpid4_latency_qos1_max0 : 9;
        unsigned int lpid4_qos1 : 3;
        unsigned int lpid4_cnt4_qos1_valid : 1;
        unsigned int lpid4_cnt8_qos1_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS1_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS1_lpid4_latency_qos1_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS1_lpid4_latency_qos1_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS1_lpid4_latency_qos1_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS1_lpid4_latency_qos1_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS1_lpid4_latency_qos1_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS1_lpid4_latency_qos1_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS1_lpid4_qos1_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS1_lpid4_qos1_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS1_lpid4_cnt4_qos1_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS1_lpid4_cnt4_qos1_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS1_lpid4_cnt8_qos1_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS1_lpid4_cnt8_qos1_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid4_latency_qos2_avg0 : 9;
        unsigned int lpid4_latency_qos2_min0 : 9;
        unsigned int lpid4_latency_qos2_max0 : 9;
        unsigned int lpid4_qos2 : 3;
        unsigned int lpid4_cnt4_qos2_valid : 1;
        unsigned int lpid4_cnt8_qos2_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS2_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS2_lpid4_latency_qos2_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS2_lpid4_latency_qos2_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS2_lpid4_latency_qos2_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS2_lpid4_latency_qos2_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS2_lpid4_latency_qos2_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS2_lpid4_latency_qos2_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS2_lpid4_qos2_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS2_lpid4_qos2_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS2_lpid4_cnt4_qos2_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS2_lpid4_cnt4_qos2_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS2_lpid4_cnt8_qos2_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS2_lpid4_cnt8_qos2_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid4_latency_qos3_avg0 : 9;
        unsigned int lpid4_latency_qos3_min0 : 9;
        unsigned int lpid4_latency_qos3_max0 : 9;
        unsigned int lpid4_qos3 : 3;
        unsigned int lpid4_cnt4_qos3_valid : 1;
        unsigned int lpid4_cnt8_qos3_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS3_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS3_lpid4_latency_qos3_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS3_lpid4_latency_qos3_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS3_lpid4_latency_qos3_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS3_lpid4_latency_qos3_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS3_lpid4_latency_qos3_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS3_lpid4_latency_qos3_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS3_lpid4_qos3_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS3_lpid4_qos3_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS3_lpid4_cnt4_qos3_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS3_lpid4_cnt4_qos3_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS3_lpid4_cnt8_qos3_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID4_QOS3_lpid4_cnt8_qos3_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid5_latency_qos0_avg0 : 9;
        unsigned int lpid5_latency_qos0_min0 : 9;
        unsigned int lpid5_latency_qos0_max0 : 9;
        unsigned int lpid5_qos0 : 3;
        unsigned int lpid5_cnt4_qos0_valid : 1;
        unsigned int lpid5_cnt8_qos0_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS0_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS0_lpid5_latency_qos0_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS0_lpid5_latency_qos0_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS0_lpid5_latency_qos0_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS0_lpid5_latency_qos0_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS0_lpid5_latency_qos0_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS0_lpid5_latency_qos0_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS0_lpid5_qos0_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS0_lpid5_qos0_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS0_lpid5_cnt4_qos0_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS0_lpid5_cnt4_qos0_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS0_lpid5_cnt8_qos0_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS0_lpid5_cnt8_qos0_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid5_latency_qos1_avg0 : 9;
        unsigned int lpid5_latency_qos1_min0 : 9;
        unsigned int lpid5_latency_qos1_max0 : 9;
        unsigned int lpid5_qos1 : 3;
        unsigned int lpid5_cnt4_qos1_valid : 1;
        unsigned int lpid5_cnt8_qos1_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS1_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS1_lpid5_latency_qos1_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS1_lpid5_latency_qos1_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS1_lpid5_latency_qos1_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS1_lpid5_latency_qos1_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS1_lpid5_latency_qos1_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS1_lpid5_latency_qos1_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS1_lpid5_qos1_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS1_lpid5_qos1_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS1_lpid5_cnt4_qos1_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS1_lpid5_cnt4_qos1_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS1_lpid5_cnt8_qos1_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS1_lpid5_cnt8_qos1_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid5_latency_qos2_avg0 : 9;
        unsigned int lpid5_latency_qos2_min0 : 9;
        unsigned int lpid5_latency_qos2_max0 : 9;
        unsigned int lpid5_qos2 : 3;
        unsigned int lpid5_cnt4_qos2_valid : 1;
        unsigned int lpid5_cnt8_qos2_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS2_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS2_lpid5_latency_qos2_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS2_lpid5_latency_qos2_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS2_lpid5_latency_qos2_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS2_lpid5_latency_qos2_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS2_lpid5_latency_qos2_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS2_lpid5_latency_qos2_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS2_lpid5_qos2_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS2_lpid5_qos2_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS2_lpid5_cnt4_qos2_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS2_lpid5_cnt4_qos2_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS2_lpid5_cnt8_qos2_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS2_lpid5_cnt8_qos2_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid5_latency_qos3_avg0 : 9;
        unsigned int lpid5_latency_qos3_min0 : 9;
        unsigned int lpid5_latency_qos3_max0 : 9;
        unsigned int lpid5_qos3 : 3;
        unsigned int lpid5_cnt4_qos3_valid : 1;
        unsigned int lpid5_cnt8_qos3_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS3_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS3_lpid5_latency_qos3_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS3_lpid5_latency_qos3_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS3_lpid5_latency_qos3_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS3_lpid5_latency_qos3_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS3_lpid5_latency_qos3_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS3_lpid5_latency_qos3_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS3_lpid5_qos3_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS3_lpid5_qos3_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS3_lpid5_cnt4_qos3_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS3_lpid5_cnt4_qos3_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS3_lpid5_cnt8_qos3_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID5_QOS3_lpid5_cnt8_qos3_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid6_latency_qos0_avg0 : 9;
        unsigned int lpid6_latency_qos0_min0 : 9;
        unsigned int lpid6_latency_qos0_max0 : 9;
        unsigned int lpid6_qos0 : 3;
        unsigned int lpid6_cnt4_qos0_valid : 1;
        unsigned int lpid6_cnt8_qos0_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS0_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS0_lpid6_latency_qos0_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS0_lpid6_latency_qos0_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS0_lpid6_latency_qos0_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS0_lpid6_latency_qos0_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS0_lpid6_latency_qos0_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS0_lpid6_latency_qos0_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS0_lpid6_qos0_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS0_lpid6_qos0_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS0_lpid6_cnt4_qos0_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS0_lpid6_cnt4_qos0_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS0_lpid6_cnt8_qos0_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS0_lpid6_cnt8_qos0_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid6_latency_qos1_avg0 : 9;
        unsigned int lpid6_latency_qos1_min0 : 9;
        unsigned int lpid6_latency_qos1_max0 : 9;
        unsigned int lpid6_qos1 : 3;
        unsigned int lpid6_cnt4_qos1_valid : 1;
        unsigned int lpid6_cnt8_qos1_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS1_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS1_lpid6_latency_qos1_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS1_lpid6_latency_qos1_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS1_lpid6_latency_qos1_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS1_lpid6_latency_qos1_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS1_lpid6_latency_qos1_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS1_lpid6_latency_qos1_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS1_lpid6_qos1_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS1_lpid6_qos1_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS1_lpid6_cnt4_qos1_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS1_lpid6_cnt4_qos1_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS1_lpid6_cnt8_qos1_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS1_lpid6_cnt8_qos1_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid6_latency_qos2_avg0 : 9;
        unsigned int lpid6_latency_qos2_min0 : 9;
        unsigned int lpid6_latency_qos2_max0 : 9;
        unsigned int lpid6_qos2 : 3;
        unsigned int lpid6_cnt4_qos2_valid : 1;
        unsigned int lpid6_cnt8_qos2_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS2_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS2_lpid6_latency_qos2_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS2_lpid6_latency_qos2_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS2_lpid6_latency_qos2_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS2_lpid6_latency_qos2_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS2_lpid6_latency_qos2_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS2_lpid6_latency_qos2_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS2_lpid6_qos2_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS2_lpid6_qos2_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS2_lpid6_cnt4_qos2_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS2_lpid6_cnt4_qos2_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS2_lpid6_cnt8_qos2_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS2_lpid6_cnt8_qos2_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid6_latency_qos3_avg0 : 9;
        unsigned int lpid6_latency_qos3_min0 : 9;
        unsigned int lpid6_latency_qos3_max0 : 9;
        unsigned int lpid6_qos3 : 3;
        unsigned int lpid6_cnt4_qos3_valid : 1;
        unsigned int lpid6_cnt8_qos3_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS3_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS3_lpid6_latency_qos3_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS3_lpid6_latency_qos3_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS3_lpid6_latency_qos3_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS3_lpid6_latency_qos3_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS3_lpid6_latency_qos3_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS3_lpid6_latency_qos3_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS3_lpid6_qos3_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS3_lpid6_qos3_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS3_lpid6_cnt4_qos3_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS3_lpid6_cnt4_qos3_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS3_lpid6_cnt8_qos3_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID6_QOS3_lpid6_cnt8_qos3_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid7_latency_qos0_avg0 : 9;
        unsigned int lpid7_latency_qos0_min0 : 9;
        unsigned int lpid7_latency_qos0_max0 : 9;
        unsigned int lpid7_qos0 : 3;
        unsigned int lpid7_cnt4_qos0_valid : 1;
        unsigned int lpid7_cnt8_qos0_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS0_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS0_lpid7_latency_qos0_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS0_lpid7_latency_qos0_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS0_lpid7_latency_qos0_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS0_lpid7_latency_qos0_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS0_lpid7_latency_qos0_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS0_lpid7_latency_qos0_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS0_lpid7_qos0_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS0_lpid7_qos0_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS0_lpid7_cnt4_qos0_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS0_lpid7_cnt4_qos0_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS0_lpid7_cnt8_qos0_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS0_lpid7_cnt8_qos0_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid7_latency_qos1_avg0 : 9;
        unsigned int lpid7_latency_qos1_min0 : 9;
        unsigned int lpid7_latency_qos1_max0 : 9;
        unsigned int lpid7_qos1 : 3;
        unsigned int lpid7_cnt4_qos1_valid : 1;
        unsigned int lpid7_cnt8_qos1_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS1_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS1_lpid7_latency_qos1_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS1_lpid7_latency_qos1_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS1_lpid7_latency_qos1_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS1_lpid7_latency_qos1_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS1_lpid7_latency_qos1_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS1_lpid7_latency_qos1_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS1_lpid7_qos1_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS1_lpid7_qos1_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS1_lpid7_cnt4_qos1_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS1_lpid7_cnt4_qos1_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS1_lpid7_cnt8_qos1_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS1_lpid7_cnt8_qos1_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid7_latency_qos2_avg0 : 9;
        unsigned int lpid7_latency_qos2_min0 : 9;
        unsigned int lpid7_latency_qos2_max0 : 9;
        unsigned int lpid7_qos2 : 3;
        unsigned int lpid7_cnt4_qos2_valid : 1;
        unsigned int lpid7_cnt8_qos2_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS2_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS2_lpid7_latency_qos2_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS2_lpid7_latency_qos2_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS2_lpid7_latency_qos2_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS2_lpid7_latency_qos2_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS2_lpid7_latency_qos2_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS2_lpid7_latency_qos2_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS2_lpid7_qos2_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS2_lpid7_qos2_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS2_lpid7_cnt4_qos2_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS2_lpid7_cnt4_qos2_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS2_lpid7_cnt8_qos2_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS2_lpid7_cnt8_qos2_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid7_latency_qos3_avg0 : 9;
        unsigned int lpid7_latency_qos3_min0 : 9;
        unsigned int lpid7_latency_qos3_max0 : 9;
        unsigned int lpid7_qos3 : 3;
        unsigned int lpid7_cnt4_qos3_valid : 1;
        unsigned int lpid7_cnt8_qos3_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS3_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS3_lpid7_latency_qos3_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS3_lpid7_latency_qos3_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS3_lpid7_latency_qos3_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS3_lpid7_latency_qos3_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS3_lpid7_latency_qos3_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS3_lpid7_latency_qos3_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS3_lpid7_qos3_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS3_lpid7_qos3_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS3_lpid7_cnt4_qos3_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS3_lpid7_cnt4_qos3_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS3_lpid7_cnt8_qos3_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID7_QOS3_lpid7_cnt8_qos3_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int latency_event_state : 32;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_EVENT_STATE_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_EVENT_STATE_latency_event_state_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_EVENT_STATE_latency_event_state_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int latency_event_clear : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_EVENT_CLR_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_EVENT_CLR_latency_event_clear_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_EVENT_CLR_latency_event_clear_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int latency_int_lpid_onehot : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CPU_RTM_LATENCY_INT_LPID_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_INT_LPID_latency_int_lpid_onehot_START (0)
#define SOC_CPU_RTM_LATENCY_INT_LPID_latency_int_lpid_onehot_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int latency0cnt_intr_latch : 16;
        unsigned int latency1cnt_intr_latch : 16;
    } reg;
} SOC_CPU_RTM_LATENCY_INT_CNT0_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_INT_CNT0_latency0cnt_intr_latch_START (0)
#define SOC_CPU_RTM_LATENCY_INT_CNT0_latency0cnt_intr_latch_END (15)
#define SOC_CPU_RTM_LATENCY_INT_CNT0_latency1cnt_intr_latch_START (16)
#define SOC_CPU_RTM_LATENCY_INT_CNT0_latency1cnt_intr_latch_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int latency2cnt_intr_latch : 16;
        unsigned int latency3cnt_intr_latch : 16;
    } reg;
} SOC_CPU_RTM_LATENCY_INT_CNT1_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_INT_CNT1_latency2cnt_intr_latch_START (0)
#define SOC_CPU_RTM_LATENCY_INT_CNT1_latency2cnt_intr_latch_END (15)
#define SOC_CPU_RTM_LATENCY_INT_CNT1_latency3cnt_intr_latch_START (16)
#define SOC_CPU_RTM_LATENCY_INT_CNT1_latency3cnt_intr_latch_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int latency4cnt_intr_latch : 16;
        unsigned int latency5cnt_intr_latch : 16;
    } reg;
} SOC_CPU_RTM_LATENCY_INT_CNT2_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_INT_CNT2_latency4cnt_intr_latch_START (0)
#define SOC_CPU_RTM_LATENCY_INT_CNT2_latency4cnt_intr_latch_END (15)
#define SOC_CPU_RTM_LATENCY_INT_CNT2_latency5cnt_intr_latch_START (16)
#define SOC_CPU_RTM_LATENCY_INT_CNT2_latency5cnt_intr_latch_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int latency6cnt_intr_latch : 16;
        unsigned int latency7cnt_intr_latch : 16;
    } reg;
} SOC_CPU_RTM_LATENCY_INT_CNT3_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_INT_CNT3_latency6cnt_intr_latch_START (0)
#define SOC_CPU_RTM_LATENCY_INT_CNT3_latency6cnt_intr_latch_END (15)
#define SOC_CPU_RTM_LATENCY_INT_CNT3_latency7cnt_intr_latch_START (16)
#define SOC_CPU_RTM_LATENCY_INT_CNT3_latency7cnt_intr_latch_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int latency8cnt_intr_latch : 16;
        unsigned int latency9cnt_intr_latch : 16;
    } reg;
} SOC_CPU_RTM_LATENCY_INT_CNT4_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_INT_CNT4_latency8cnt_intr_latch_START (0)
#define SOC_CPU_RTM_LATENCY_INT_CNT4_latency8cnt_intr_latch_END (15)
#define SOC_CPU_RTM_LATENCY_INT_CNT4_latency9cnt_intr_latch_START (16)
#define SOC_CPU_RTM_LATENCY_INT_CNT4_latency9cnt_intr_latch_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int latency10cnt_intr_latch : 16;
        unsigned int latency11cnt_intr_latch : 16;
    } reg;
} SOC_CPU_RTM_LATENCY_INT_CNT5_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_INT_CNT5_latency10cnt_intr_latch_START (0)
#define SOC_CPU_RTM_LATENCY_INT_CNT5_latency10cnt_intr_latch_END (15)
#define SOC_CPU_RTM_LATENCY_INT_CNT5_latency11cnt_intr_latch_START (16)
#define SOC_CPU_RTM_LATENCY_INT_CNT5_latency11cnt_intr_latch_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int latency12cnt_intr_latch : 16;
        unsigned int latency13cnt_intr_latch : 16;
    } reg;
} SOC_CPU_RTM_LATENCY_INT_CNT6_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_INT_CNT6_latency12cnt_intr_latch_START (0)
#define SOC_CPU_RTM_LATENCY_INT_CNT6_latency12cnt_intr_latch_END (15)
#define SOC_CPU_RTM_LATENCY_INT_CNT6_latency13cnt_intr_latch_START (16)
#define SOC_CPU_RTM_LATENCY_INT_CNT6_latency13cnt_intr_latch_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int latency14cnt_intr_latch : 16;
        unsigned int latency15cnt_intr_latch : 16;
    } reg;
} SOC_CPU_RTM_LATENCY_INT_CNT7_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_INT_CNT7_latency14cnt_intr_latch_START (0)
#define SOC_CPU_RTM_LATENCY_INT_CNT7_latency14cnt_intr_latch_END (15)
#define SOC_CPU_RTM_LATENCY_INT_CNT7_latency15cnt_intr_latch_START (16)
#define SOC_CPU_RTM_LATENCY_INT_CNT7_latency15cnt_intr_latch_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int latmnt_rsv_config_bakup1 : 32;
    } reg;
} SOC_CPU_RTM_LATENCY_MONITOR_CONFIG5_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG5_latmnt_rsv_config_bakup1_START (0)
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG5_latmnt_rsv_config_bakup1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int latmnt_rsv_config_bakup2 : 32;
    } reg;
} SOC_CPU_RTM_LATENCY_MONITOR_CONFIG6_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG6_latmnt_rsv_config_bakup2_START (0)
#define SOC_CPU_RTM_LATENCY_MONITOR_CONFIG6_latmnt_rsv_config_bakup2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int latmnt_debug_state0 : 32;
    } reg;
} SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO0_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO0_latmnt_debug_state0_START (0)
#define SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO0_latmnt_debug_state0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int latmnt_debug_state1 : 32;
    } reg;
} SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO1_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO1_latmnt_debug_state1_START (0)
#define SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO1_latmnt_debug_state1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int latmnt_debug_state2 : 32;
    } reg;
} SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO2_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO2_latmnt_debug_state2_START (0)
#define SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO2_latmnt_debug_state2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int latmnt_debug_state3 : 32;
    } reg;
} SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO3_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO3_latmnt_debug_state3_START (0)
#define SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO3_latmnt_debug_state3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int latmnt_debug_state4 : 32;
    } reg;
} SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO4_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO4_latmnt_debug_state4_START (0)
#define SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO4_latmnt_debug_state4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int latmnt_debug_state5 : 32;
    } reg;
} SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO5_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO5_latmnt_debug_state5_START (0)
#define SOC_CPU_RTM_LATENCY_MONITOR_DEBUG_INFO5_latmnt_debug_state5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mnt_debug_latch : 1;
        unsigned int reserved_0 : 7;
        unsigned int mnt_debug_index : 8;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_CPU_RTM_MNT_DEBUG_EN_UNION;
#endif
#define SOC_CPU_RTM_MNT_DEBUG_EN_mnt_debug_latch_START (0)
#define SOC_CPU_RTM_MNT_DEBUG_EN_mnt_debug_latch_END (0)
#define SOC_CPU_RTM_MNT_DEBUG_EN_mnt_debug_index_START (8)
#define SOC_CPU_RTM_MNT_DEBUG_EN_mnt_debug_index_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mnt_debug_sync_align_count : 32;
    } reg;
} SOC_CPU_RTM_MNT_DEBUG_SYNC_ALIGN_COUNT_UNION;
#endif
#define SOC_CPU_RTM_MNT_DEBUG_SYNC_ALIGN_COUNT_mnt_debug_sync_align_count_START (0)
#define SOC_CPU_RTM_MNT_DEBUG_SYNC_ALIGN_COUNT_mnt_debug_sync_align_count_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mnt_debug_test_info : 32;
    } reg;
} SOC_CPU_RTM_MNT_DEBUG_CNT_UNION;
#endif
#define SOC_CPU_RTM_MNT_DEBUG_CNT_mnt_debug_test_info_START (0)
#define SOC_CPU_RTM_MNT_DEBUG_CNT_mnt_debug_test_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_sync_max_cnt14_1 : 10;
        unsigned int reserved_0 : 5;
        unsigned int dbg_en_cnt14_1 : 1;
        unsigned int cfg_sync_dly_cnt14_1 : 14;
        unsigned int reserved_1 : 1;
        unsigned int cfg_sync_en14_1 : 1;
    } reg;
} SOC_CPU_RTM_RTM_SYNC_CFG14_1_UNION;
#endif
#define SOC_CPU_RTM_RTM_SYNC_CFG14_1_cfg_sync_max_cnt14_1_START (0)
#define SOC_CPU_RTM_RTM_SYNC_CFG14_1_cfg_sync_max_cnt14_1_END (9)
#define SOC_CPU_RTM_RTM_SYNC_CFG14_1_dbg_en_cnt14_1_START (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG14_1_dbg_en_cnt14_1_END (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG14_1_cfg_sync_dly_cnt14_1_START (16)
#define SOC_CPU_RTM_RTM_SYNC_CFG14_1_cfg_sync_dly_cnt14_1_END (29)
#define SOC_CPU_RTM_RTM_SYNC_CFG14_1_cfg_sync_en14_1_START (31)
#define SOC_CPU_RTM_RTM_SYNC_CFG14_1_cfg_sync_en14_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_sync_max_cnt15_1 : 10;
        unsigned int reserved_0 : 5;
        unsigned int dbg_en_cnt15_1 : 1;
        unsigned int cfg_sync_dly_cnt15_1 : 14;
        unsigned int reserved_1 : 1;
        unsigned int cfg_sync_en15_1 : 1;
    } reg;
} SOC_CPU_RTM_RTM_SYNC_CFG15_1_UNION;
#endif
#define SOC_CPU_RTM_RTM_SYNC_CFG15_1_cfg_sync_max_cnt15_1_START (0)
#define SOC_CPU_RTM_RTM_SYNC_CFG15_1_cfg_sync_max_cnt15_1_END (9)
#define SOC_CPU_RTM_RTM_SYNC_CFG15_1_dbg_en_cnt15_1_START (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG15_1_dbg_en_cnt15_1_END (15)
#define SOC_CPU_RTM_RTM_SYNC_CFG15_1_cfg_sync_dly_cnt15_1_START (16)
#define SOC_CPU_RTM_RTM_SYNC_CFG15_1_cfg_sync_dly_cnt15_1_END (29)
#define SOC_CPU_RTM_RTM_SYNC_CFG15_1_cfg_sync_en15_1_START (31)
#define SOC_CPU_RTM_RTM_SYNC_CFG15_1_cfg_sync_en15_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_channel_valid14_1 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_CPU_RTM_TRACE_CHANNEL_VALID14_1_UNION;
#endif
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID14_1_trace_channel_valid14_1_START (0)
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID14_1_trace_channel_valid14_1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_channel_valid15_1 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_CPU_RTM_TRACE_CHANNEL_VALID15_1_UNION;
#endif
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID15_1_trace_channel_valid15_1_START (0)
#define SOC_CPU_RTM_TRACE_CHANNEL_VALID15_1_trace_channel_valid15_1_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_cal_override_14_1 : 1;
        unsigned int data_recv_corrupt_14_1 : 1;
        unsigned int trace_en_14_1 : 1;
        unsigned int period_tmo_14_1 : 1;
        unsigned int header_chk_fail_14_1 : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_CPU_RTM_RTM_INT1_STATE_14_1_UNION;
#endif
#define SOC_CPU_RTM_RTM_INT1_STATE_14_1_trace_cal_override_14_1_START (0)
#define SOC_CPU_RTM_RTM_INT1_STATE_14_1_trace_cal_override_14_1_END (0)
#define SOC_CPU_RTM_RTM_INT1_STATE_14_1_data_recv_corrupt_14_1_START (1)
#define SOC_CPU_RTM_RTM_INT1_STATE_14_1_data_recv_corrupt_14_1_END (1)
#define SOC_CPU_RTM_RTM_INT1_STATE_14_1_trace_en_14_1_START (2)
#define SOC_CPU_RTM_RTM_INT1_STATE_14_1_trace_en_14_1_END (2)
#define SOC_CPU_RTM_RTM_INT1_STATE_14_1_period_tmo_14_1_START (3)
#define SOC_CPU_RTM_RTM_INT1_STATE_14_1_period_tmo_14_1_END (3)
#define SOC_CPU_RTM_RTM_INT1_STATE_14_1_header_chk_fail_14_1_START (4)
#define SOC_CPU_RTM_RTM_INT1_STATE_14_1_header_chk_fail_14_1_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_cal_override_15_1 : 1;
        unsigned int data_recv_corrupt_15_1 : 1;
        unsigned int trace_en_15_1 : 1;
        unsigned int period_tmo_15_1 : 1;
        unsigned int header_chk_fail_15_1 : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_CPU_RTM_RTM_INT1_STATE_15_1_UNION;
#endif
#define SOC_CPU_RTM_RTM_INT1_STATE_15_1_trace_cal_override_15_1_START (0)
#define SOC_CPU_RTM_RTM_INT1_STATE_15_1_trace_cal_override_15_1_END (0)
#define SOC_CPU_RTM_RTM_INT1_STATE_15_1_data_recv_corrupt_15_1_START (1)
#define SOC_CPU_RTM_RTM_INT1_STATE_15_1_data_recv_corrupt_15_1_END (1)
#define SOC_CPU_RTM_RTM_INT1_STATE_15_1_trace_en_15_1_START (2)
#define SOC_CPU_RTM_RTM_INT1_STATE_15_1_trace_en_15_1_END (2)
#define SOC_CPU_RTM_RTM_INT1_STATE_15_1_period_tmo_15_1_START (3)
#define SOC_CPU_RTM_RTM_INT1_STATE_15_1_period_tmo_15_1_END (3)
#define SOC_CPU_RTM_RTM_INT1_STATE_15_1_header_chk_fail_15_1_START (4)
#define SOC_CPU_RTM_RTM_INT1_STATE_15_1_header_chk_fail_15_1_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_cal_override_int_enable_14_1 : 1;
        unsigned int data_recv_corrupt_int_enable_14_1 : 1;
        unsigned int trace_en_int_enable_14_1 : 1;
        unsigned int period_tmo_int_enable_14_1 : 1;
        unsigned int header_chk_fail_int_enable_14_1 : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_14_1_UNION;
#endif
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_14_1_trace_cal_override_int_enable_14_1_START (0)
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_14_1_trace_cal_override_int_enable_14_1_END (0)
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_14_1_data_recv_corrupt_int_enable_14_1_START (1)
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_14_1_data_recv_corrupt_int_enable_14_1_END (1)
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_14_1_trace_en_int_enable_14_1_START (2)
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_14_1_trace_en_int_enable_14_1_END (2)
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_14_1_period_tmo_int_enable_14_1_START (3)
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_14_1_period_tmo_int_enable_14_1_END (3)
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_14_1_header_chk_fail_int_enable_14_1_START (4)
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_14_1_header_chk_fail_int_enable_14_1_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_cal_override_int_enable_15_1 : 1;
        unsigned int data_recv_corrupt_int_enable_15_1 : 1;
        unsigned int trace_en_int_enable_15_1 : 1;
        unsigned int period_tmo_int_enable_15_1 : 1;
        unsigned int header_chk_fail_int_enable_15_1 : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_15_1_UNION;
#endif
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_15_1_trace_cal_override_int_enable_15_1_START (0)
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_15_1_trace_cal_override_int_enable_15_1_END (0)
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_15_1_data_recv_corrupt_int_enable_15_1_START (1)
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_15_1_data_recv_corrupt_int_enable_15_1_END (1)
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_15_1_trace_en_int_enable_15_1_START (2)
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_15_1_trace_en_int_enable_15_1_END (2)
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_15_1_period_tmo_int_enable_15_1_START (3)
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_15_1_period_tmo_int_enable_15_1_END (3)
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_15_1_header_chk_fail_int_enable_15_1_START (4)
#define SOC_CPU_RTM_RTM_INT1_STATE_ENABLE_15_1_header_chk_fail_int_enable_15_1_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_cal_override_signal_enable_14_1 : 1;
        unsigned int data_recv_corrupt_signal_enable_14_1 : 1;
        unsigned int trace_en_signal_enable_14_1 : 1;
        unsigned int period_tmo_signal_enable_14_1 : 1;
        unsigned int header_chk_fail_signal_enable_14_1 : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_14_1_UNION;
#endif
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_14_1_trace_cal_override_signal_enable_14_1_START (0)
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_14_1_trace_cal_override_signal_enable_14_1_END (0)
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_14_1_data_recv_corrupt_signal_enable_14_1_START (1)
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_14_1_data_recv_corrupt_signal_enable_14_1_END (1)
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_14_1_trace_en_signal_enable_14_1_START (2)
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_14_1_trace_en_signal_enable_14_1_END (2)
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_14_1_period_tmo_signal_enable_14_1_START (3)
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_14_1_period_tmo_signal_enable_14_1_END (3)
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_14_1_header_chk_fail_signal_enable_14_1_START (4)
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_14_1_header_chk_fail_signal_enable_14_1_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_cal_override_signal_enable_15_1 : 1;
        unsigned int data_recv_corrupt_signal_enable_15_1 : 1;
        unsigned int trace_en_signal_enable_15_1 : 1;
        unsigned int period_tmo_signal_enable_15_1 : 1;
        unsigned int header_chk_fail_signal_enable_15_1 : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_15_1_UNION;
#endif
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_15_1_trace_cal_override_signal_enable_15_1_START (0)
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_15_1_trace_cal_override_signal_enable_15_1_END (0)
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_15_1_data_recv_corrupt_signal_enable_15_1_START (1)
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_15_1_data_recv_corrupt_signal_enable_15_1_END (1)
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_15_1_trace_en_signal_enable_15_1_START (2)
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_15_1_trace_en_signal_enable_15_1_END (2)
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_15_1_period_tmo_signal_enable_15_1_START (3)
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_15_1_period_tmo_signal_enable_15_1_END (3)
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_15_1_header_chk_fail_signal_enable_15_1_START (4)
#define SOC_CPU_RTM_RTM_INT1_SINGAL_ENABLE_15_1_header_chk_fail_signal_enable_15_1_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_flag_14_1 : 32;
    } reg;
} SOC_CPU_RTM_RTM_INT2_STATE_14_1_UNION;
#endif
#define SOC_CPU_RTM_RTM_INT2_STATE_14_1_trace_flag_14_1_START (0)
#define SOC_CPU_RTM_RTM_INT2_STATE_14_1_trace_flag_14_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_flag_15_1 : 32;
    } reg;
} SOC_CPU_RTM_RTM_INT2_STATE_15_1_UNION;
#endif
#define SOC_CPU_RTM_RTM_INT2_STATE_15_1_trace_flag_15_1_START (0)
#define SOC_CPU_RTM_RTM_INT2_STATE_15_1_trace_flag_15_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_flag_int_enable_14_1 : 32;
    } reg;
} SOC_CPU_RTM_RTM_INT2_STATE_ENABLE_14_1_UNION;
#endif
#define SOC_CPU_RTM_RTM_INT2_STATE_ENABLE_14_1_trace_flag_int_enable_14_1_START (0)
#define SOC_CPU_RTM_RTM_INT2_STATE_ENABLE_14_1_trace_flag_int_enable_14_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_flag_int_enable_15_1 : 32;
    } reg;
} SOC_CPU_RTM_RTM_INT2_STATE_ENABLE_15_1_UNION;
#endif
#define SOC_CPU_RTM_RTM_INT2_STATE_ENABLE_15_1_trace_flag_int_enable_15_1_START (0)
#define SOC_CPU_RTM_RTM_INT2_STATE_ENABLE_15_1_trace_flag_int_enable_15_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_flag_signal_enable_14_1 : 32;
    } reg;
} SOC_CPU_RTM_RTM_INT2_SINGAL_ENABLE_14_1_UNION;
#endif
#define SOC_CPU_RTM_RTM_INT2_SINGAL_ENABLE_14_1_trace_flag_signal_enable_14_1_START (0)
#define SOC_CPU_RTM_RTM_INT2_SINGAL_ENABLE_14_1_trace_flag_signal_enable_14_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int trace_flag_signal_enable_15_1 : 32;
    } reg;
} SOC_CPU_RTM_RTM_INT2_SINGAL_ENABLE_15_1_UNION;
#endif
#define SOC_CPU_RTM_RTM_INT2_SINGAL_ENABLE_15_1_trace_flag_signal_enable_15_1_START (0)
#define SOC_CPU_RTM_RTM_INT2_SINGAL_ENABLE_15_1_trace_flag_signal_enable_15_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_period_event_msk_14_1 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_CPU_RTM_CFG_PERIOD_EVENT_MSK_14_1_UNION;
#endif
#define SOC_CPU_RTM_CFG_PERIOD_EVENT_MSK_14_1_cfg_period_event_msk_14_1_START (0)
#define SOC_CPU_RTM_CFG_PERIOD_EVENT_MSK_14_1_cfg_period_event_msk_14_1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_period_event_msk_15_1 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_CPU_RTM_CFG_PERIOD_EVENT_MSK_15_1_UNION;
#endif
#define SOC_CPU_RTM_CFG_PERIOD_EVENT_MSK_15_1_cfg_period_event_msk_15_1_START (0)
#define SOC_CPU_RTM_CFG_PERIOD_EVENT_MSK_15_1_cfg_period_event_msk_15_1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_period_event_ts_0_14_1 : 32;
    } reg;
} SOC_CPU_RTM_CFG_PERIOD_EVENT_TS_0_14_1_UNION;
#endif
#define SOC_CPU_RTM_CFG_PERIOD_EVENT_TS_0_14_1_cfg_period_event_ts_0_14_1_START (0)
#define SOC_CPU_RTM_CFG_PERIOD_EVENT_TS_0_14_1_cfg_period_event_ts_0_14_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_period_event_ts_0_15_1 : 32;
    } reg;
} SOC_CPU_RTM_CFG_PERIOD_EVENT_TS_0_15_1_UNION;
#endif
#define SOC_CPU_RTM_CFG_PERIOD_EVENT_TS_0_15_1_cfg_period_event_ts_0_15_1_START (0)
#define SOC_CPU_RTM_CFG_PERIOD_EVENT_TS_0_15_1_cfg_period_event_ts_0_15_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_header_filter_cmp_0_14_1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_0_14_1_UNION;
#endif
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_0_14_1_cfg_header_filter_cmp_0_14_1_START (0)
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_0_14_1_cfg_header_filter_cmp_0_14_1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_header_filter_cmp_0_15_1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_0_15_1_UNION;
#endif
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_0_15_1_cfg_header_filter_cmp_0_15_1_START (0)
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_0_15_1_cfg_header_filter_cmp_0_15_1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_header_filter_cmp_1_14_1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_1_14_1_UNION;
#endif
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_1_14_1_cfg_header_filter_cmp_1_14_1_START (0)
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_1_14_1_cfg_header_filter_cmp_1_14_1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_header_filter_cmp_1_15_1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_1_15_1_UNION;
#endif
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_1_15_1_cfg_header_filter_cmp_1_15_1_START (0)
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_1_15_1_cfg_header_filter_cmp_1_15_1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_header_filter_cmp_2_14_1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_2_14_1_UNION;
#endif
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_2_14_1_cfg_header_filter_cmp_2_14_1_START (0)
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_2_14_1_cfg_header_filter_cmp_2_14_1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_header_filter_cmp_2_15_1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_2_15_1_UNION;
#endif
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_2_15_1_cfg_header_filter_cmp_2_15_1_START (0)
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_2_15_1_cfg_header_filter_cmp_2_15_1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_header_filter_cmp_3_14_1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_3_14_1_UNION;
#endif
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_3_14_1_cfg_header_filter_cmp_3_14_1_START (0)
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_3_14_1_cfg_header_filter_cmp_3_14_1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_header_filter_cmp_3_15_1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_3_15_1_UNION;
#endif
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_3_15_1_cfg_header_filter_cmp_3_15_1_START (0)
#define SOC_CPU_RTM_CFG_HEADER_FILTER_CMP_3_15_1_cfg_header_filter_cmp_3_15_1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_trace_filter_en_14_1 : 1;
        unsigned int cfg_trace_filter_mode_14_1 : 1;
        unsigned int cfg_header_filter_en_14_1 : 1;
        unsigned int cfg_header_filter_mode_14_1 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_CPU_RTM_CFG_FILTER_CTRL_14_1_UNION;
#endif
#define SOC_CPU_RTM_CFG_FILTER_CTRL_14_1_cfg_trace_filter_en_14_1_START (0)
#define SOC_CPU_RTM_CFG_FILTER_CTRL_14_1_cfg_trace_filter_en_14_1_END (0)
#define SOC_CPU_RTM_CFG_FILTER_CTRL_14_1_cfg_trace_filter_mode_14_1_START (1)
#define SOC_CPU_RTM_CFG_FILTER_CTRL_14_1_cfg_trace_filter_mode_14_1_END (1)
#define SOC_CPU_RTM_CFG_FILTER_CTRL_14_1_cfg_header_filter_en_14_1_START (2)
#define SOC_CPU_RTM_CFG_FILTER_CTRL_14_1_cfg_header_filter_en_14_1_END (2)
#define SOC_CPU_RTM_CFG_FILTER_CTRL_14_1_cfg_header_filter_mode_14_1_START (3)
#define SOC_CPU_RTM_CFG_FILTER_CTRL_14_1_cfg_header_filter_mode_14_1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_trace_filter_en_15_1 : 1;
        unsigned int cfg_trace_filter_mode_15_1 : 1;
        unsigned int cfg_header_filter_en_15_1 : 1;
        unsigned int cfg_header_filter_mode_15_1 : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_CPU_RTM_CFG_FILTER_CTRL_15_1_UNION;
#endif
#define SOC_CPU_RTM_CFG_FILTER_CTRL_15_1_cfg_trace_filter_en_15_1_START (0)
#define SOC_CPU_RTM_CFG_FILTER_CTRL_15_1_cfg_trace_filter_en_15_1_END (0)
#define SOC_CPU_RTM_CFG_FILTER_CTRL_15_1_cfg_trace_filter_mode_15_1_START (1)
#define SOC_CPU_RTM_CFG_FILTER_CTRL_15_1_cfg_trace_filter_mode_15_1_END (1)
#define SOC_CPU_RTM_CFG_FILTER_CTRL_15_1_cfg_header_filter_en_15_1_START (2)
#define SOC_CPU_RTM_CFG_FILTER_CTRL_15_1_cfg_header_filter_en_15_1_END (2)
#define SOC_CPU_RTM_CFG_FILTER_CTRL_15_1_cfg_header_filter_mode_15_1_START (3)
#define SOC_CPU_RTM_CFG_FILTER_CTRL_15_1_cfg_header_filter_mode_15_1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_header_filter_msk_14_1 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_CPU_RTM_CFG_HEADER_FILTER_MSK_14_1_UNION;
#endif
#define SOC_CPU_RTM_CFG_HEADER_FILTER_MSK_14_1_cfg_header_filter_msk_14_1_START (0)
#define SOC_CPU_RTM_CFG_HEADER_FILTER_MSK_14_1_cfg_header_filter_msk_14_1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_header_filter_msk_15_1 : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_CPU_RTM_CFG_HEADER_FILTER_MSK_15_1_UNION;
#endif
#define SOC_CPU_RTM_CFG_HEADER_FILTER_MSK_15_1_cfg_header_filter_msk_15_1_START (0)
#define SOC_CPU_RTM_CFG_HEADER_FILTER_MSK_15_1_cfg_header_filter_msk_15_1_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_trace_cnt_filter_msk_14_1 : 16;
        unsigned int cfg_trace_sig_filter_msk_14_1 : 16;
    } reg;
} SOC_CPU_RTM_CFG_TRACE_FILTER_MSK_14_1_UNION;
#endif
#define SOC_CPU_RTM_CFG_TRACE_FILTER_MSK_14_1_cfg_trace_cnt_filter_msk_14_1_START (0)
#define SOC_CPU_RTM_CFG_TRACE_FILTER_MSK_14_1_cfg_trace_cnt_filter_msk_14_1_END (15)
#define SOC_CPU_RTM_CFG_TRACE_FILTER_MSK_14_1_cfg_trace_sig_filter_msk_14_1_START (16)
#define SOC_CPU_RTM_CFG_TRACE_FILTER_MSK_14_1_cfg_trace_sig_filter_msk_14_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cfg_trace_cnt_filter_msk_15_1 : 16;
        unsigned int cfg_trace_sig_filter_msk_15_1 : 16;
    } reg;
} SOC_CPU_RTM_CFG_TRACE_FILTER_MSK_15_1_UNION;
#endif
#define SOC_CPU_RTM_CFG_TRACE_FILTER_MSK_15_1_cfg_trace_cnt_filter_msk_15_1_START (0)
#define SOC_CPU_RTM_CFG_TRACE_FILTER_MSK_15_1_cfg_trace_cnt_filter_msk_15_1_END (15)
#define SOC_CPU_RTM_CFG_TRACE_FILTER_MSK_15_1_cfg_trace_sig_filter_msk_15_1_START (16)
#define SOC_CPU_RTM_CFG_TRACE_FILTER_MSK_15_1_cfg_trace_sig_filter_msk_15_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_trace_cnt_cal_div_stop_14_1 : 1;
        unsigned int dfx_trace_cnt_cal_id_14_1 : 4;
        unsigned int dfx_trace_cnt_cal_run_14_1 : 1;
        unsigned int dfx_data_revc_st_14_1 : 3;
        unsigned int reserved : 23;
    } reg;
} SOC_CPU_RTM_DFX_SIG_MON_14_1_UNION;
#endif
#define SOC_CPU_RTM_DFX_SIG_MON_14_1_dfx_trace_cnt_cal_div_stop_14_1_START (0)
#define SOC_CPU_RTM_DFX_SIG_MON_14_1_dfx_trace_cnt_cal_div_stop_14_1_END (0)
#define SOC_CPU_RTM_DFX_SIG_MON_14_1_dfx_trace_cnt_cal_id_14_1_START (1)
#define SOC_CPU_RTM_DFX_SIG_MON_14_1_dfx_trace_cnt_cal_id_14_1_END (4)
#define SOC_CPU_RTM_DFX_SIG_MON_14_1_dfx_trace_cnt_cal_run_14_1_START (5)
#define SOC_CPU_RTM_DFX_SIG_MON_14_1_dfx_trace_cnt_cal_run_14_1_END (5)
#define SOC_CPU_RTM_DFX_SIG_MON_14_1_dfx_data_revc_st_14_1_START (6)
#define SOC_CPU_RTM_DFX_SIG_MON_14_1_dfx_data_revc_st_14_1_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_trace_cnt_cal_div_stop_15_1 : 1;
        unsigned int dfx_trace_cnt_cal_id_15_1 : 4;
        unsigned int dfx_trace_cnt_cal_run_15_1 : 1;
        unsigned int dfx_data_revc_st_15_1 : 3;
        unsigned int reserved : 23;
    } reg;
} SOC_CPU_RTM_DFX_SIG_MON_15_1_UNION;
#endif
#define SOC_CPU_RTM_DFX_SIG_MON_15_1_dfx_trace_cnt_cal_div_stop_15_1_START (0)
#define SOC_CPU_RTM_DFX_SIG_MON_15_1_dfx_trace_cnt_cal_div_stop_15_1_END (0)
#define SOC_CPU_RTM_DFX_SIG_MON_15_1_dfx_trace_cnt_cal_id_15_1_START (1)
#define SOC_CPU_RTM_DFX_SIG_MON_15_1_dfx_trace_cnt_cal_id_15_1_END (4)
#define SOC_CPU_RTM_DFX_SIG_MON_15_1_dfx_trace_cnt_cal_run_15_1_START (5)
#define SOC_CPU_RTM_DFX_SIG_MON_15_1_dfx_trace_cnt_cal_run_15_1_END (5)
#define SOC_CPU_RTM_DFX_SIG_MON_15_1_dfx_data_revc_st_15_1_START (6)
#define SOC_CPU_RTM_DFX_SIG_MON_15_1_dfx_data_revc_st_15_1_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_index_valid_14_1 : 21;
        unsigned int reserved : 11;
    } reg;
} SOC_CPU_RTM_EVENT_INDEX_VALID_14_1_UNION;
#endif
#define SOC_CPU_RTM_EVENT_INDEX_VALID_14_1_event_index_valid_14_1_START (0)
#define SOC_CPU_RTM_EVENT_INDEX_VALID_14_1_event_index_valid_14_1_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_index_valid_15_1 : 21;
        unsigned int reserved : 11;
    } reg;
} SOC_CPU_RTM_EVENT_INDEX_VALID_15_1_UNION;
#endif
#define SOC_CPU_RTM_EVENT_INDEX_VALID_15_1_event_index_valid_15_1_START (0)
#define SOC_CPU_RTM_EVENT_INDEX_VALID_15_1_event_index_valid_15_1_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tp_send_in_progress_14_1 : 1;
        unsigned int tp_group_counter_14_1 : 5;
        unsigned int tp_rtm_ready_14_1 : 1;
        unsigned int tp_rtm_req_14_1 : 1;
        unsigned int tp_rtm_sync_14_1 : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_14_1_UNION;
#endif
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_14_1_tp_send_in_progress_14_1_START (0)
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_14_1_tp_send_in_progress_14_1_END (0)
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_14_1_tp_group_counter_14_1_START (1)
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_14_1_tp_group_counter_14_1_END (5)
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_14_1_tp_rtm_ready_14_1_START (6)
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_14_1_tp_rtm_ready_14_1_END (6)
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_14_1_tp_rtm_req_14_1_START (7)
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_14_1_tp_rtm_req_14_1_END (7)
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_14_1_tp_rtm_sync_14_1_START (8)
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_14_1_tp_rtm_sync_14_1_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tp_send_in_progress_15_1 : 1;
        unsigned int tp_group_counter_15_1 : 5;
        unsigned int tp_rtm_ready_15_1 : 1;
        unsigned int tp_rtm_req_15_1 : 1;
        unsigned int tp_rtm_sync_15_1 : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_15_1_UNION;
#endif
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_15_1_tp_send_in_progress_15_1_START (0)
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_15_1_tp_send_in_progress_15_1_END (0)
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_15_1_tp_group_counter_15_1_START (1)
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_15_1_tp_group_counter_15_1_END (5)
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_15_1_tp_rtm_ready_15_1_START (6)
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_15_1_tp_rtm_ready_15_1_END (6)
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_15_1_tp_rtm_req_15_1_START (7)
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_15_1_tp_rtm_req_15_1_END (7)
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_15_1_tp_rtm_sync_15_1_START (8)
#define SOC_CPU_RTM_DFX_RTM_SYNC_NORMAL_15_1_tp_rtm_sync_15_1_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int LAT_MON_QoS_EN : 1;
        unsigned int LAT_MON_4_OR_8_CFG : 16;
        unsigned int reserved : 15;
    } reg;
} SOC_CPU_RTM_LATENCE_MONITOR_QOS_EN_UNION;
#endif
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_EN_LAT_MON_QoS_EN_START (0)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_EN_LAT_MON_QoS_EN_END (0)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_EN_LAT_MON_4_OR_8_CFG_START (1)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_EN_LAT_MON_4_OR_8_CFG_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lat_mon_lpid0_qos0 : 3;
        unsigned int lat_mon_lpid0_qos1 : 3;
        unsigned int lat_mon_lpid0_qos2 : 3;
        unsigned int lat_mon_lpid0_qos3 : 3;
        unsigned int reserved : 20;
    } reg;
} SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID0_UNION;
#endif
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID0_lat_mon_lpid0_qos0_START (0)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID0_lat_mon_lpid0_qos0_END (2)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID0_lat_mon_lpid0_qos1_START (3)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID0_lat_mon_lpid0_qos1_END (5)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID0_lat_mon_lpid0_qos2_START (6)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID0_lat_mon_lpid0_qos2_END (8)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID0_lat_mon_lpid0_qos3_START (9)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID0_lat_mon_lpid0_qos3_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lat_mon_lpid1_qos0 : 3;
        unsigned int lat_mon_lpid1_qos1 : 3;
        unsigned int lat_mon_lpid1_qos2 : 3;
        unsigned int lat_mon_lpid1_qos3 : 3;
        unsigned int reserved : 20;
    } reg;
} SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID1_UNION;
#endif
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID1_lat_mon_lpid1_qos0_START (0)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID1_lat_mon_lpid1_qos0_END (2)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID1_lat_mon_lpid1_qos1_START (3)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID1_lat_mon_lpid1_qos1_END (5)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID1_lat_mon_lpid1_qos2_START (6)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID1_lat_mon_lpid1_qos2_END (8)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID1_lat_mon_lpid1_qos3_START (9)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID1_lat_mon_lpid1_qos3_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lat_mon_lpid2_qos0 : 3;
        unsigned int lat_mon_lpid2_qos1 : 3;
        unsigned int lat_mon_lpid2_qos2 : 3;
        unsigned int lat_mon_lpid2_qos3 : 3;
        unsigned int reserved : 20;
    } reg;
} SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID2_UNION;
#endif
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID2_lat_mon_lpid2_qos0_START (0)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID2_lat_mon_lpid2_qos0_END (2)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID2_lat_mon_lpid2_qos1_START (3)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID2_lat_mon_lpid2_qos1_END (5)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID2_lat_mon_lpid2_qos2_START (6)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID2_lat_mon_lpid2_qos2_END (8)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID2_lat_mon_lpid2_qos3_START (9)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_LPID2_lat_mon_lpid2_qos3_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lat_mon_lpid3_qos0 : 3;
        unsigned int lat_mon_lpid3_qos1 : 3;
        unsigned int lat_mon_lpid3_qos2 : 3;
        unsigned int lat_mon_lpid3_qos3 : 3;
        unsigned int reserved : 20;
    } reg;
} SOC_CPU_RTM_LATENCE_MONITOR_QOS_3_UNION;
#endif
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_3_lat_mon_lpid3_qos0_START (0)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_3_lat_mon_lpid3_qos0_END (2)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_3_lat_mon_lpid3_qos1_START (3)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_3_lat_mon_lpid3_qos1_END (5)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_3_lat_mon_lpid3_qos2_START (6)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_3_lat_mon_lpid3_qos2_END (8)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_3_lat_mon_lpid3_qos3_START (9)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_3_lat_mon_lpid3_qos3_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lat_mon_lpid4_qos0 : 3;
        unsigned int lat_mon_lpid4_qos1 : 3;
        unsigned int lat_mon_lpid4_qos2 : 3;
        unsigned int lat_mon_lpid4_qos3 : 3;
        unsigned int reserved : 20;
    } reg;
} SOC_CPU_RTM_LATENCE_MONITOR_QOS_4_UNION;
#endif
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_4_lat_mon_lpid4_qos0_START (0)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_4_lat_mon_lpid4_qos0_END (2)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_4_lat_mon_lpid4_qos1_START (3)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_4_lat_mon_lpid4_qos1_END (5)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_4_lat_mon_lpid4_qos2_START (6)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_4_lat_mon_lpid4_qos2_END (8)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_4_lat_mon_lpid4_qos3_START (9)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_4_lat_mon_lpid4_qos3_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lat_mon_lpid5_qos0 : 3;
        unsigned int lat_mon_lpid5_qos1 : 3;
        unsigned int lat_mon_lpid5_qos2 : 3;
        unsigned int lat_mon_lpid5_qos3 : 3;
        unsigned int reserved : 20;
    } reg;
} SOC_CPU_RTM_LATENCE_MONITOR_QOS_5_UNION;
#endif
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_5_lat_mon_lpid5_qos0_START (0)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_5_lat_mon_lpid5_qos0_END (2)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_5_lat_mon_lpid5_qos1_START (3)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_5_lat_mon_lpid5_qos1_END (5)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_5_lat_mon_lpid5_qos2_START (6)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_5_lat_mon_lpid5_qos2_END (8)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_5_lat_mon_lpid5_qos3_START (9)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_5_lat_mon_lpid5_qos3_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lat_mon_lpid6_qos0 : 3;
        unsigned int lat_mon_lpid6_qos1 : 3;
        unsigned int lat_mon_lpid6_qos2 : 3;
        unsigned int lat_mon_lpid6_qos3 : 3;
        unsigned int reserved : 20;
    } reg;
} SOC_CPU_RTM_LATENCE_MONITOR_QOS_6_UNION;
#endif
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_6_lat_mon_lpid6_qos0_START (0)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_6_lat_mon_lpid6_qos0_END (2)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_6_lat_mon_lpid6_qos1_START (3)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_6_lat_mon_lpid6_qos1_END (5)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_6_lat_mon_lpid6_qos2_START (6)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_6_lat_mon_lpid6_qos2_END (8)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_6_lat_mon_lpid6_qos3_START (9)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_6_lat_mon_lpid6_qos3_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lat_mon_lpid7_qos0 : 3;
        unsigned int lat_mon_lpid7_qos1 : 3;
        unsigned int lat_mon_lpid7_qos2 : 3;
        unsigned int lat_mon_lpid7_qos3 : 3;
        unsigned int reserved : 20;
    } reg;
} SOC_CPU_RTM_LATENCE_MONITOR_QOS_7_UNION;
#endif
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_7_lat_mon_lpid7_qos0_START (0)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_7_lat_mon_lpid7_qos0_END (2)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_7_lat_mon_lpid7_qos1_START (3)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_7_lat_mon_lpid7_qos1_END (5)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_7_lat_mon_lpid7_qos2_START (6)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_7_lat_mon_lpid7_qos2_END (8)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_7_lat_mon_lpid7_qos3_START (9)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_7_lat_mon_lpid7_qos3_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lat_mon_lpid8_qos0 : 3;
        unsigned int lat_mon_lpid8_qos1 : 3;
        unsigned int lat_mon_lpid8_qos2 : 3;
        unsigned int lat_mon_lpid8_qos3 : 3;
        unsigned int reserved : 20;
    } reg;
} SOC_CPU_RTM_LATENCE_MONITOR_QOS_8_UNION;
#endif
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_8_lat_mon_lpid8_qos0_START (0)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_8_lat_mon_lpid8_qos0_END (2)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_8_lat_mon_lpid8_qos1_START (3)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_8_lat_mon_lpid8_qos1_END (5)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_8_lat_mon_lpid8_qos2_START (6)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_8_lat_mon_lpid8_qos2_END (8)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_8_lat_mon_lpid8_qos3_START (9)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_8_lat_mon_lpid8_qos3_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lat_mon_lpid9_qos0 : 3;
        unsigned int lat_mon_lpid9_qos1 : 3;
        unsigned int lat_mon_lpid9_qos2 : 3;
        unsigned int lat_mon_lpid9_qos3 : 3;
        unsigned int reserved : 20;
    } reg;
} SOC_CPU_RTM_LATENCE_MONITOR_QOS_9_UNION;
#endif
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_9_lat_mon_lpid9_qos0_START (0)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_9_lat_mon_lpid9_qos0_END (2)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_9_lat_mon_lpid9_qos1_START (3)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_9_lat_mon_lpid9_qos1_END (5)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_9_lat_mon_lpid9_qos2_START (6)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_9_lat_mon_lpid9_qos2_END (8)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_9_lat_mon_lpid9_qos3_START (9)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_9_lat_mon_lpid9_qos3_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lat_mon_lpid10_qos0 : 3;
        unsigned int lat_mon_lpid10_qos1 : 3;
        unsigned int lat_mon_lpid10_qos2 : 3;
        unsigned int lat_mon_lpid10_qos3 : 3;
        unsigned int reserved : 20;
    } reg;
} SOC_CPU_RTM_LATENCE_MONITOR_QOS_10_UNION;
#endif
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_10_lat_mon_lpid10_qos0_START (0)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_10_lat_mon_lpid10_qos0_END (2)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_10_lat_mon_lpid10_qos1_START (3)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_10_lat_mon_lpid10_qos1_END (5)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_10_lat_mon_lpid10_qos2_START (6)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_10_lat_mon_lpid10_qos2_END (8)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_10_lat_mon_lpid10_qos3_START (9)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_10_lat_mon_lpid10_qos3_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lat_mon_lpid11_qos0 : 3;
        unsigned int lat_mon_lpid11_qos1 : 3;
        unsigned int lat_mon_lpid11_qos2 : 3;
        unsigned int lat_mon_lpid11_qos3 : 3;
        unsigned int reserved : 20;
    } reg;
} SOC_CPU_RTM_LATENCE_MONITOR_QOS_11_UNION;
#endif
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_11_lat_mon_lpid11_qos0_START (0)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_11_lat_mon_lpid11_qos0_END (2)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_11_lat_mon_lpid11_qos1_START (3)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_11_lat_mon_lpid11_qos1_END (5)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_11_lat_mon_lpid11_qos2_START (6)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_11_lat_mon_lpid11_qos2_END (8)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_11_lat_mon_lpid11_qos3_START (9)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_11_lat_mon_lpid11_qos3_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lat_mon_lpid12_qos0 : 3;
        unsigned int lat_mon_lpid12_qos1 : 3;
        unsigned int lat_mon_lpid12_qos2 : 3;
        unsigned int lat_mon_lpid12_qos3 : 3;
        unsigned int reserved : 20;
    } reg;
} SOC_CPU_RTM_LATENCE_MONITOR_QOS_12_UNION;
#endif
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_12_lat_mon_lpid12_qos0_START (0)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_12_lat_mon_lpid12_qos0_END (2)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_12_lat_mon_lpid12_qos1_START (3)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_12_lat_mon_lpid12_qos1_END (5)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_12_lat_mon_lpid12_qos2_START (6)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_12_lat_mon_lpid12_qos2_END (8)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_12_lat_mon_lpid12_qos3_START (9)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_12_lat_mon_lpid12_qos3_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lat_mon_lpid13_qos0 : 3;
        unsigned int lat_mon_lpid13_qos1 : 3;
        unsigned int lat_mon_lpid13_qos2 : 3;
        unsigned int lat_mon_lpid13_qos3 : 3;
        unsigned int reserved : 20;
    } reg;
} SOC_CPU_RTM_LATENCE_MONITOR_QOS_13_UNION;
#endif
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_13_lat_mon_lpid13_qos0_START (0)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_13_lat_mon_lpid13_qos0_END (2)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_13_lat_mon_lpid13_qos1_START (3)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_13_lat_mon_lpid13_qos1_END (5)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_13_lat_mon_lpid13_qos2_START (6)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_13_lat_mon_lpid13_qos2_END (8)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_13_lat_mon_lpid13_qos3_START (9)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_13_lat_mon_lpid13_qos3_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lat_mon_lpid14_qos0 : 3;
        unsigned int lat_mon_lpid14_qos1 : 3;
        unsigned int lat_mon_lpid14_qos2 : 3;
        unsigned int lat_mon_lpid14_qos3 : 3;
        unsigned int reserved : 20;
    } reg;
} SOC_CPU_RTM_LATENCE_MONITOR_QOS_14_UNION;
#endif
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_14_lat_mon_lpid14_qos0_START (0)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_14_lat_mon_lpid14_qos0_END (2)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_14_lat_mon_lpid14_qos1_START (3)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_14_lat_mon_lpid14_qos1_END (5)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_14_lat_mon_lpid14_qos2_START (6)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_14_lat_mon_lpid14_qos2_END (8)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_14_lat_mon_lpid14_qos3_START (9)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_14_lat_mon_lpid14_qos3_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lat_mon_lpid15_qos0 : 3;
        unsigned int lat_mon_lpid15_qos1 : 3;
        unsigned int lat_mon_lpid15_qos2 : 3;
        unsigned int lat_mon_lpid15_qos3 : 3;
        unsigned int reserved : 20;
    } reg;
} SOC_CPU_RTM_LATENCE_MONITOR_QOS_15_UNION;
#endif
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_15_lat_mon_lpid15_qos0_START (0)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_15_lat_mon_lpid15_qos0_END (2)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_15_lat_mon_lpid15_qos1_START (3)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_15_lat_mon_lpid15_qos1_END (5)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_15_lat_mon_lpid15_qos2_START (6)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_15_lat_mon_lpid15_qos2_END (8)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_15_lat_mon_lpid15_qos3_START (9)
#define SOC_CPU_RTM_LATENCE_MONITOR_QOS_15_lat_mon_lpid15_qos3_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid14_latency_qos0_avg0 : 9;
        unsigned int lpid14_latency_qos0_min0 : 9;
        unsigned int lpid14_latency_qos0_max0 : 9;
        unsigned int lpid14_qos0 : 3;
        unsigned int lpid14_cnt4_qos0_valid : 1;
        unsigned int lpid14_cnt8_qos0_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS0_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS0_lpid14_latency_qos0_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS0_lpid14_latency_qos0_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS0_lpid14_latency_qos0_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS0_lpid14_latency_qos0_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS0_lpid14_latency_qos0_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS0_lpid14_latency_qos0_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS0_lpid14_qos0_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS0_lpid14_qos0_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS0_lpid14_cnt4_qos0_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS0_lpid14_cnt4_qos0_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS0_lpid14_cnt8_qos0_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS0_lpid14_cnt8_qos0_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid14_latency_qos1_avg0 : 9;
        unsigned int lpid14_latency_qos1_min0 : 9;
        unsigned int lpid14_latency_qos1_max0 : 9;
        unsigned int lpid14_qos1 : 3;
        unsigned int lpid14_cnt4_qos1_valid : 1;
        unsigned int lpid14_cnt8_qos1_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS1_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS1_lpid14_latency_qos1_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS1_lpid14_latency_qos1_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS1_lpid14_latency_qos1_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS1_lpid14_latency_qos1_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS1_lpid14_latency_qos1_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS1_lpid14_latency_qos1_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS1_lpid14_qos1_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS1_lpid14_qos1_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS1_lpid14_cnt4_qos1_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS1_lpid14_cnt4_qos1_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS1_lpid14_cnt8_qos1_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS1_lpid14_cnt8_qos1_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid14_latency_qos2_avg0 : 9;
        unsigned int lpid14_latency_qos2_min0 : 9;
        unsigned int lpid14_latency_qos2_max0 : 9;
        unsigned int lpid14_qos2 : 3;
        unsigned int lpid14_cnt4_qos2_valid : 1;
        unsigned int lpid14_cnt8_qos2_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS2_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS2_lpid14_latency_qos2_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS2_lpid14_latency_qos2_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS2_lpid14_latency_qos2_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS2_lpid14_latency_qos2_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS2_lpid14_latency_qos2_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS2_lpid14_latency_qos2_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS2_lpid14_qos2_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS2_lpid14_qos2_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS2_lpid14_cnt4_qos2_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS2_lpid14_cnt4_qos2_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS2_lpid14_cnt8_qos2_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS2_lpid14_cnt8_qos2_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid14_latency_qos3_avg0 : 9;
        unsigned int lpid14_latency_qos3_min0 : 9;
        unsigned int lpid14_latency_qos3_max0 : 9;
        unsigned int lpid14_qos3 : 3;
        unsigned int lpid14_cnt4_qos3_valid : 1;
        unsigned int lpid14_cnt8_qos3_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS3_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS3_lpid14_latency_qos3_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS3_lpid14_latency_qos3_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS3_lpid14_latency_qos3_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS3_lpid14_latency_qos3_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS3_lpid14_latency_qos3_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS3_lpid14_latency_qos3_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS3_lpid14_qos3_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS3_lpid14_qos3_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS3_lpid14_cnt4_qos3_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS3_lpid14_cnt4_qos3_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS3_lpid14_cnt8_qos3_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID14_QOS3_lpid14_cnt8_qos3_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid15_latency_qos0_avg0 : 9;
        unsigned int lpid15_latency_qos0_min0 : 9;
        unsigned int lpid15_latency_qos0_max0 : 9;
        unsigned int lpid15_qos0 : 3;
        unsigned int lpid15_cnt4_qos0_valid : 1;
        unsigned int lpid15_cnt8_qos0_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS0_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS0_lpid15_latency_qos0_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS0_lpid15_latency_qos0_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS0_lpid15_latency_qos0_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS0_lpid15_latency_qos0_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS0_lpid15_latency_qos0_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS0_lpid15_latency_qos0_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS0_lpid15_qos0_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS0_lpid15_qos0_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS0_lpid15_cnt4_qos0_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS0_lpid15_cnt4_qos0_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS0_lpid15_cnt8_qos0_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS0_lpid15_cnt8_qos0_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid15_latency_qos1_avg0 : 9;
        unsigned int lpid15_latency_qos1_min0 : 9;
        unsigned int lpid15_latency_qos1_max0 : 9;
        unsigned int lpid15_qos1 : 3;
        unsigned int lpid15_cnt4_qos1_valid : 1;
        unsigned int lpid15_cnt8_qos1_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS1_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS1_lpid15_latency_qos1_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS1_lpid15_latency_qos1_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS1_lpid15_latency_qos1_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS1_lpid15_latency_qos1_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS1_lpid15_latency_qos1_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS1_lpid15_latency_qos1_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS1_lpid15_qos1_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS1_lpid15_qos1_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS1_lpid15_cnt4_qos1_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS1_lpid15_cnt4_qos1_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS1_lpid15_cnt8_qos1_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS1_lpid15_cnt8_qos1_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid15_latency_qos2_avg0 : 9;
        unsigned int lpid15_latency_qos2_min0 : 9;
        unsigned int lpid15_latency_qos2_max0 : 9;
        unsigned int lpid15_qos2 : 3;
        unsigned int lpid15_cnt4_qos2_valid : 1;
        unsigned int lpid15_cnt8_qos2_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS2_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS2_lpid15_latency_qos2_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS2_lpid15_latency_qos2_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS2_lpid15_latency_qos2_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS2_lpid15_latency_qos2_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS2_lpid15_latency_qos2_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS2_lpid15_latency_qos2_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS2_lpid15_qos2_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS2_lpid15_qos2_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS2_lpid15_cnt4_qos2_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS2_lpid15_cnt4_qos2_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS2_lpid15_cnt8_qos2_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS2_lpid15_cnt8_qos2_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lpid15_latency_qos3_avg0 : 9;
        unsigned int lpid15_latency_qos3_min0 : 9;
        unsigned int lpid15_latency_qos3_max0 : 9;
        unsigned int lpid15_qos3 : 3;
        unsigned int lpid15_cnt4_qos3_valid : 1;
        unsigned int lpid15_cnt8_qos3_valid : 1;
    } reg;
} SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS3_UNION;
#endif
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS3_lpid15_latency_qos3_avg0_START (0)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS3_lpid15_latency_qos3_avg0_END (8)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS3_lpid15_latency_qos3_min0_START (9)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS3_lpid15_latency_qos3_min0_END (17)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS3_lpid15_latency_qos3_max0_START (18)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS3_lpid15_latency_qos3_max0_END (26)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS3_lpid15_qos3_START (27)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS3_lpid15_qos3_END (29)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS3_lpid15_cnt4_qos3_valid_START (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS3_lpid15_cnt4_qos3_valid_END (30)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS3_lpid15_cnt8_qos3_valid_START (31)
#define SOC_CPU_RTM_LATENCY_CNT_LPID15_QOS3_lpid15_cnt8_qos3_valid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sync_pulse_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CPU_RTM_QoS_Sync_en_UNION;
#endif
#define SOC_CPU_RTM_QoS_Sync_en_sync_pulse_en_START (0)
#define SOC_CPU_RTM_QoS_Sync_en_sync_pulse_en_END (0)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
