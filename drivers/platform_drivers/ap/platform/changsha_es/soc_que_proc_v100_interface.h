#ifndef __SOC_QUE_PROC_V100_INTERFACE_H__
#define __SOC_QUE_PROC_V100_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QUE_PROC_V100_MSI_DEVICE_ID_ADDR(base) (base)
#define SOC_QUE_PROC_V100_QUE_CR_ADDR(base) ((base) + 0x004UL)
#define SOC_QUE_PROC_V100_QUE_MCQ_CONFIG_ADDR(base) ((base) + 0x008UL)
#define SOC_QUE_PROC_V100_ARB_CONFIG_ADDR(base) ((base) + 0x00CUL)
#define SOC_QUE_PROC_V100_QUE_MCQ_ESILBA_ADDR(base) ((base) + 0x010UL)
#define SOC_QUE_PROC_V100_QUE_MCQ_ESIUBA_ADDR(base) ((base) + 0x014UL)
#define SOC_QUE_PROC_V100_QUE_CFG_RAM_CTRL_ADDR(base) ((base) + 0x018UL)
#define SOC_QUE_PROC_V100_QUE_CFG_RAM_STATUS_ADDR(base) ((base) + 0x01CUL)
#define SOC_QUE_PROC_V100_QUE_SQ_I_ATTR0_ADDR(base,i) ((base) + 0x020UL + (i) * 0x1CUL)
#define SOC_QUE_PROC_V100_QUE_SQ_I_SQLBA0_ADDR(base,i) ((base) + 0x024UL + (i) * 0x1CUL)
#define SOC_QUE_PROC_V100_QUE_SQ_I_SQUBA0_ADDR(base,i) ((base) + 0x028UL + (i) * 0x1CUL)
#define SOC_QUE_PROC_V100_QUE_MCQ_PROMT_MSG_ADDR(base,i) ((base) + 0x02CUL + (i) * 0x1CUL)
#define SOC_QUE_PROC_V100_QUE_CQ_I_ATTR0_ADDR(base,i) ((base) + 0x30UL + (i) * 0x1CUL)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQLBA0_ADDR(base,s) ((base) + 0x34UL + (s) * 0x1CUL)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQLBA1_ADDR(base,s) ((base) + 0x264UL + (s) * 0x1CUL)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQLBA2_ADDR(base,s) ((base) + 0x494UL + (s) * 0x1CUL)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQLBA3_ADDR(base,s) ((base) + 0x6C4UL + (s) * 0x1CUL)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQUBA0_ADDR(base,s) ((base) + 0x38UL + (s) * 0x1CUL)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQUBA1_ADDR(base,s) ((base) + 0x268UL + (s) * 0x1CUL)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQUBA2_ADDR(base,s) ((base) + 0x498UL + (s) * 0x1CUL)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQUBA3_ADDR(base,s) ((base) + 0x6C8UL + (s) * 0x1CUL)
#define SOC_QUE_PROC_V100_QUE_SQ_I_SQH_ADDR(base,i) ((base) + 0x8E0UL + (i) * 0x8UL)
#define SOC_QUE_PROC_V100_QUE_SQ_I_SQT_ADDR(base,i) ((base) + 0x8E4UL + (i) * 0x8UL)
#define SOC_QUE_PROC_V100_QUE_SQ_I_SQIS_ADDR(base,i) ((base) + 0xB60UL + (i) * 0x8UL)
#define SOC_QUE_PROC_V100_QUE_SQ_I_SQIE_ADDR(base,i) ((base) + 0xB64UL + (i) * 0x8UL)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQH_ADDR(base,i) ((base) + 0xDE0UL + (i) * 0x8UL)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQT_ADDR(base,i) ((base) + 0xDE4UL + (i) * 0x8UL)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQIS_ADDR(base,i) ((base) + 0x1060UL + (i) * 0xcUL)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQIE_ADDR(base,i) ((base) + 0x1064UL + (i) * 0xcUL)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQIACR_ADDR(base,i) ((base) + 0x1068UL + (i) * 0xcUL)
#define SOC_QUE_PROC_V100_DFA_SQ_I_RTC_ADDR(base,j) ((base) + 0x1420UL + (j) * 0x14UL)
#define SOC_QUE_PROC_V100_DFA_SQ_I_RTS_ADDR(base,j) ((base) + 0x1424UL + (j) * 0x14UL)
#define SOC_QUE_PROC_V100_DFA_SQ_I_SQIS_ADDR(base,j) ((base) + 0x1428UL + (j) * 0x14UL)
#define SOC_QUE_PROC_V100_DFA_SQ_I_SQIE_ADDR(base,j) ((base) + 0x142CUL + (j) * 0x14UL)
#define SOC_QUE_PROC_V100_DFA_SQ_CFIG_ADDR(base,j) ((base) + 0x1430UL + (j) * 0x14UL)
#define SOC_QUE_PROC_V100_DFA_IO_TIMEOUT_CHECK_ADDR(base) ((base) + 0x1498UL)
#define SOC_QUE_PROC_V100_DFA_TR_TIMEOUT_STATUS_ADDR(base,k) ((base) + 0x149CUL + (k) * 0x4UL)
#define SOC_QUE_PROC_V100_IO_TIMEOUT_IDX_MSG_ADDR(base,y) ((base) + 0x14BCUL + (y) * 0x4UL)
#define SOC_QUE_PROC_V100_QUE_DMA0_RX_AXI_ERR_ADDRL_ADDR(base) ((base) + 0x18C4UL)
#define SOC_QUE_PROC_V100_QUE_DMA0_RX_AXI_ERR_ADDRU_ADDR(base) ((base) + 0x18C8UL)
#define SOC_QUE_PROC_V100_QUE_DMA0_TX_AXI_ERR_ADDRL_ADDR(base) ((base) + 0x18CCUL)
#define SOC_QUE_PROC_V100_QUE_DMA0_TX_AXI_ERR_ADDRU_ADDR(base) ((base) + 0x18D0UL)
#else
#define SOC_QUE_PROC_V100_MSI_DEVICE_ID_ADDR(base) (base)
#define SOC_QUE_PROC_V100_QUE_CR_ADDR(base) ((base) + 0x004)
#define SOC_QUE_PROC_V100_QUE_MCQ_CONFIG_ADDR(base) ((base) + 0x008)
#define SOC_QUE_PROC_V100_ARB_CONFIG_ADDR(base) ((base) + 0x00C)
#define SOC_QUE_PROC_V100_QUE_MCQ_ESILBA_ADDR(base) ((base) + 0x010)
#define SOC_QUE_PROC_V100_QUE_MCQ_ESIUBA_ADDR(base) ((base) + 0x014)
#define SOC_QUE_PROC_V100_QUE_CFG_RAM_CTRL_ADDR(base) ((base) + 0x018)
#define SOC_QUE_PROC_V100_QUE_CFG_RAM_STATUS_ADDR(base) ((base) + 0x01C)
#define SOC_QUE_PROC_V100_QUE_SQ_I_ATTR0_ADDR(base,i) ((base) + 0x020 + (i) * 0x1C)
#define SOC_QUE_PROC_V100_QUE_SQ_I_SQLBA0_ADDR(base,i) ((base) + 0x024 + (i) * 0x1C)
#define SOC_QUE_PROC_V100_QUE_SQ_I_SQUBA0_ADDR(base,i) ((base) + 0x028 + (i) * 0x1C)
#define SOC_QUE_PROC_V100_QUE_MCQ_PROMT_MSG_ADDR(base,i) ((base) + 0x02C + (i) * 0x1C)
#define SOC_QUE_PROC_V100_QUE_CQ_I_ATTR0_ADDR(base,i) ((base) + 0x30 + (i) * 0x1C)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQLBA0_ADDR(base,s) ((base) + 0x34 + (s) * 0x1C)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQLBA1_ADDR(base,s) ((base) + 0x264 + (s) * 0x1C)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQLBA2_ADDR(base,s) ((base) + 0x494 + (s) * 0x1C)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQLBA3_ADDR(base,s) ((base) + 0x6C4 + (s) * 0x1C)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQUBA0_ADDR(base,s) ((base) + 0x38 + (s) * 0x1C)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQUBA1_ADDR(base,s) ((base) + 0x268 + (s) * 0x1C)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQUBA2_ADDR(base,s) ((base) + 0x498 + (s) * 0x1C)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQUBA3_ADDR(base,s) ((base) + 0x6C8 + (s) * 0x1C)
#define SOC_QUE_PROC_V100_QUE_SQ_I_SQH_ADDR(base,i) ((base) + 0x8E0 + (i) * 0x8)
#define SOC_QUE_PROC_V100_QUE_SQ_I_SQT_ADDR(base,i) ((base) + 0x8E4 + (i) * 0x8)
#define SOC_QUE_PROC_V100_QUE_SQ_I_SQIS_ADDR(base,i) ((base) + 0xB60 + (i) * 0x8)
#define SOC_QUE_PROC_V100_QUE_SQ_I_SQIE_ADDR(base,i) ((base) + 0xB64 + (i) * 0x8)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQH_ADDR(base,i) ((base) + 0xDE0 + (i) * 0x8)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQT_ADDR(base,i) ((base) + 0xDE4 + (i) * 0x8)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQIS_ADDR(base,i) ((base) + 0x1060 + (i) * 0xc)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQIE_ADDR(base,i) ((base) + 0x1064 + (i) * 0xc)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQIACR_ADDR(base,i) ((base) + 0x1068 + (i) * 0xc)
#define SOC_QUE_PROC_V100_DFA_SQ_I_RTC_ADDR(base,j) ((base) + 0x1420 + (j) * 0x14)
#define SOC_QUE_PROC_V100_DFA_SQ_I_RTS_ADDR(base,j) ((base) + 0x1424 + (j) * 0x14)
#define SOC_QUE_PROC_V100_DFA_SQ_I_SQIS_ADDR(base,j) ((base) + 0x1428 + (j) * 0x14)
#define SOC_QUE_PROC_V100_DFA_SQ_I_SQIE_ADDR(base,j) ((base) + 0x142C + (j) * 0x14)
#define SOC_QUE_PROC_V100_DFA_SQ_CFIG_ADDR(base,j) ((base) + 0x1430 + (j) * 0x14)
#define SOC_QUE_PROC_V100_DFA_IO_TIMEOUT_CHECK_ADDR(base) ((base) + 0x1498)
#define SOC_QUE_PROC_V100_DFA_TR_TIMEOUT_STATUS_ADDR(base,k) ((base) + 0x149C + (k) * 0x4)
#define SOC_QUE_PROC_V100_IO_TIMEOUT_IDX_MSG_ADDR(base,y) ((base) + 0x14BC + (y) * 0x4)
#define SOC_QUE_PROC_V100_QUE_DMA0_RX_AXI_ERR_ADDRL_ADDR(base) ((base) + 0x18C4)
#define SOC_QUE_PROC_V100_QUE_DMA0_RX_AXI_ERR_ADDRU_ADDR(base) ((base) + 0x18C8)
#define SOC_QUE_PROC_V100_QUE_DMA0_TX_AXI_ERR_ADDRL_ADDR(base) ((base) + 0x18CC)
#define SOC_QUE_PROC_V100_QUE_DMA0_TX_AXI_ERR_ADDRU_ADDR(base) ((base) + 0x18D0)
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QUE_PROC_V100_DFA_UTRD_ADDR_ADDR(base) (base)
#define SOC_QUE_PROC_V100_DFA_CMD_ADDR_ADDR(base) ((base) + 0x0004UL)
#define SOC_QUE_PROC_V100_DFA_INFO_ADDR_ADDR(base) ((base) + 0x0008UL)
#define SOC_QUE_PROC_V100_QUE_PROC_IE_ADDR(base) ((base) + 0x000CUL)
#define SOC_QUE_PROC_V100_QUE_PROC_IS_ADDR(base) ((base) + 0x0010UL)
#define SOC_QUE_PROC_V100_QUE_PROC_IS_SET_ADDR(base) ((base) + 0x0014UL)
#define SOC_QUE_PROC_V100_DFA_CPU_RDY_ADDR(base) ((base) + 0x0018UL)
#define SOC_QUE_PROC_V100_CHECK_QUE_SQ_ADDR(base) ((base) + 0x001CUL)
#define SOC_QUE_PROC_V100_DFA_SQ_UPDATA_OTS_ADDR(base) ((base) + 0x0020UL)
#define SOC_QUE_PROC_V100_UFS_AXI_MST_USR_CFG_ADDR(base) ((base) + 0x0024UL)
#define SOC_QUE_PROC_V100_UFS_DMAC_OUTSTANDING_CFG_ADDR(base) ((base) + 0x0028UL)
#define SOC_QUE_PROC_V100_CFG_IO_LENTENCY_ADDR(base) ((base) + 0x002CUL)
#define SOC_QUE_PROC_V100_MAX_IO_LETENCY_ADDR(base) ((base) + 0x0030UL)
#define SOC_QUE_PROC_V100_CFG_DELAY_REGION0_ADDR(base) ((base) + 0x0034UL)
#define SOC_QUE_PROC_V100_CFG_DELAY_REGION1_ADDR(base) ((base) + 0x0038UL)
#define SOC_QUE_PROC_V100_CFG_DELAY_REGION2_ADDR(base) ((base) + 0x003CUL)
#define SOC_QUE_PROC_V100_CFG_DELAY_REGION3_ADDR(base) ((base) + 0x0040UL)
#define SOC_QUE_PROC_V100_DFA_IO_TIMEOUT_TRSH_ADDR(base) ((base) + 0x0044UL)
#define SOC_QUE_PROC_V100_DFA_IO_FINISH_TIME_ADDR(base,y) ((base) + 0x0048UL + (y) * 0x4UL)
#define SOC_QUE_PROC_V100_DFA_LUN_CHECK_ADDR(base) ((base) + 0x448UL)
#define SOC_QUE_PROC_V100_UFS_LU0_LGC_BLK_NUM_ADDR(base) ((base) + 0x044CUL)
#define SOC_QUE_PROC_V100_UFS_LU1_LGC_BLK_NUM_ADDR(base) ((base) + 0x0450UL)
#define SOC_QUE_PROC_V100_UFS_LU2_LGC_BLK_NUM_ADDR(base) ((base) + 0x0454UL)
#define SOC_QUE_PROC_V100_UFS_LU3_LGC_BLK_NUM_ADDR(base) ((base) + 0x0458UL)
#define SOC_QUE_PROC_V100_UFS_LU4_LGC_BLK_NUM_ADDR(base) ((base) + 0x045CUL)
#define SOC_QUE_PROC_V100_UFS_LU5_LGC_BLK_NUM_ADDR(base) ((base) + 0x0460UL)
#define SOC_QUE_PROC_V100_UFS_LU6_LGC_BLK_NUM_ADDR(base) ((base) + 0x0464UL)
#define SOC_QUE_PROC_V100_UFS_LU7_LGC_BLK_NUM_ADDR(base) ((base) + 0x0468UL)
#define SOC_QUE_PROC_V100_UFS_BOOT_LU_LGC_BLK_NUM_ADDR(base) ((base) + 0x046CUL)
#define SOC_QUE_PROC_V100_DFA_BLOCK_CG_CFG_ADDR(base) ((base) + 0x0470UL)
#define SOC_QUE_PROC_V100_DFA_IO_WR_DTCM_TIME_ADDR(base,y) (base) + 0x0474 + 0x4 * (y)
#define SOC_QUE_PROC_V100_CFG_IO_LENTENCY1_ADDR(base) ((base) + 0x0874UL)
#define SOC_QUE_PROC_V100_ARB_DFX_ADDR(base) ((base) + 0x0878UL)
#define SOC_QUE_PROC_V100_CMD_RD_DFX_ADDR(base) ((base) + 0x087CUL)
#define SOC_QUE_PROC_V100_CMD_WR_DFX_ADDR(base) ((base) + 0x0880UL)
#define SOC_QUE_PROC_V100_DMA_DFX_ADDR(base) ((base) + 0x0884UL)
#define SOC_QUE_PROC_V100_STORE_DFX_ADDR(base) ((base) + 0x0888UL)
#else
#define SOC_QUE_PROC_V100_DFA_UTRD_ADDR_ADDR(base) (base)
#define SOC_QUE_PROC_V100_DFA_CMD_ADDR_ADDR(base) ((base) + 0x0004)
#define SOC_QUE_PROC_V100_DFA_INFO_ADDR_ADDR(base) ((base) + 0x0008)
#define SOC_QUE_PROC_V100_QUE_PROC_IE_ADDR(base) ((base) + 0x000C)
#define SOC_QUE_PROC_V100_QUE_PROC_IS_ADDR(base) ((base) + 0x0010)
#define SOC_QUE_PROC_V100_QUE_PROC_IS_SET_ADDR(base) ((base) + 0x0014)
#define SOC_QUE_PROC_V100_DFA_CPU_RDY_ADDR(base) ((base) + 0x0018)
#define SOC_QUE_PROC_V100_CHECK_QUE_SQ_ADDR(base) ((base) + 0x001C)
#define SOC_QUE_PROC_V100_DFA_SQ_UPDATA_OTS_ADDR(base) ((base) + 0x0020)
#define SOC_QUE_PROC_V100_UFS_AXI_MST_USR_CFG_ADDR(base) ((base) + 0x0024)
#define SOC_QUE_PROC_V100_UFS_DMAC_OUTSTANDING_CFG_ADDR(base) ((base) + 0x0028)
#define SOC_QUE_PROC_V100_CFG_IO_LENTENCY_ADDR(base) ((base) + 0x002C)
#define SOC_QUE_PROC_V100_MAX_IO_LETENCY_ADDR(base) ((base) + 0x0030)
#define SOC_QUE_PROC_V100_CFG_DELAY_REGION0_ADDR(base) ((base) + 0x0034)
#define SOC_QUE_PROC_V100_CFG_DELAY_REGION1_ADDR(base) ((base) + 0x0038)
#define SOC_QUE_PROC_V100_CFG_DELAY_REGION2_ADDR(base) ((base) + 0x003C)
#define SOC_QUE_PROC_V100_CFG_DELAY_REGION3_ADDR(base) ((base) + 0x0040)
#define SOC_QUE_PROC_V100_DFA_IO_TIMEOUT_TRSH_ADDR(base) ((base) + 0x0044)
#define SOC_QUE_PROC_V100_DFA_IO_FINISH_TIME_ADDR(base,y) ((base) + 0x0048 + (y) * 0x4)
#define SOC_QUE_PROC_V100_DFA_LUN_CHECK_ADDR(base) ((base) + 0x448)
#define SOC_QUE_PROC_V100_UFS_LU0_LGC_BLK_NUM_ADDR(base) ((base) + 0x044C)
#define SOC_QUE_PROC_V100_UFS_LU1_LGC_BLK_NUM_ADDR(base) ((base) + 0x0450)
#define SOC_QUE_PROC_V100_UFS_LU2_LGC_BLK_NUM_ADDR(base) ((base) + 0x0454)
#define SOC_QUE_PROC_V100_UFS_LU3_LGC_BLK_NUM_ADDR(base) ((base) + 0x0458)
#define SOC_QUE_PROC_V100_UFS_LU4_LGC_BLK_NUM_ADDR(base) ((base) + 0x045C)
#define SOC_QUE_PROC_V100_UFS_LU5_LGC_BLK_NUM_ADDR(base) ((base) + 0x0460)
#define SOC_QUE_PROC_V100_UFS_LU6_LGC_BLK_NUM_ADDR(base) ((base) + 0x0464)
#define SOC_QUE_PROC_V100_UFS_LU7_LGC_BLK_NUM_ADDR(base) ((base) + 0x0468)
#define SOC_QUE_PROC_V100_UFS_BOOT_LU_LGC_BLK_NUM_ADDR(base) ((base) + 0x046C)
#define SOC_QUE_PROC_V100_DFA_BLOCK_CG_CFG_ADDR(base) ((base) + 0x0470)
#define SOC_QUE_PROC_V100_DFA_IO_WR_DTCM_TIME_ADDR(base,y) (base) + 0x0474 + 0x4 * (y)
#define SOC_QUE_PROC_V100_CFG_IO_LENTENCY1_ADDR(base) ((base) + 0x0874)
#define SOC_QUE_PROC_V100_ARB_DFX_ADDR(base) ((base) + 0x0878)
#define SOC_QUE_PROC_V100_CMD_RD_DFX_ADDR(base) ((base) + 0x087C)
#define SOC_QUE_PROC_V100_CMD_WR_DFX_ADDR(base) ((base) + 0x0880)
#define SOC_QUE_PROC_V100_DMA_DFX_ADDR(base) ((base) + 0x0884)
#define SOC_QUE_PROC_V100_STORE_DFX_ADDR(base) ((base) + 0x0888)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_user_id : 32;
    } reg;
} SOC_QUE_PROC_V100_MSI_DEVICE_ID_UNION;
#endif
#define SOC_QUE_PROC_V100_MSI_DEVICE_ID_cfg_user_id_START (0)
#define SOC_QUE_PROC_V100_MSI_DEVICE_ID_cfg_user_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_mcq_esie : 1;
        unsigned int cfg_msi_ots : 4;
        unsigned int reserved : 27;
    } reg;
} SOC_QUE_PROC_V100_QUE_CR_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_CR_cfg_mcq_esie_START (0)
#define SOC_QUE_PROC_V100_QUE_CR_cfg_mcq_esie_END (0)
#define SOC_QUE_PROC_V100_QUE_CR_cfg_msi_ots_START (1)
#define SOC_QUE_PROC_V100_QUE_CR_cfg_msi_ots_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_mcq_arb : 2;
        unsigned int reserved_0 : 6;
        unsigned int cfg_mcq_max_cmd : 8;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_QUE_PROC_V100_QUE_MCQ_CONFIG_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_MCQ_CONFIG_cfg_mcq_arb_START (0)
#define SOC_QUE_PROC_V100_QUE_MCQ_CONFIG_cfg_mcq_arb_END (1)
#define SOC_QUE_PROC_V100_QUE_MCQ_CONFIG_cfg_mcq_max_cmd_START (8)
#define SOC_QUE_PROC_V100_QUE_MCQ_CONFIG_cfg_mcq_max_cmd_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int que_arb_timeout_thsh : 4;
        unsigned int que_arb_timeout_ts : 3;
        unsigned int reserved : 25;
    } reg;
} SOC_QUE_PROC_V100_ARB_CONFIG_UNION;
#endif
#define SOC_QUE_PROC_V100_ARB_CONFIG_que_arb_timeout_thsh_START (00)
#define SOC_QUE_PROC_V100_ARB_CONFIG_que_arb_timeout_thsh_END (03)
#define SOC_QUE_PROC_V100_ARB_CONFIG_que_arb_timeout_ts_START (04)
#define SOC_QUE_PROC_V100_ARB_CONFIG_que_arb_timeout_ts_END (06)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_mcq_esilba : 32;
    } reg;
} SOC_QUE_PROC_V100_QUE_MCQ_ESILBA_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_MCQ_ESILBA_cfg_mcq_esilba_START (0)
#define SOC_QUE_PROC_V100_QUE_MCQ_ESILBA_cfg_mcq_esilba_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_mcq_esiuba : 32;
    } reg;
} SOC_QUE_PROC_V100_QUE_MCQ_ESIUBA_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_MCQ_ESIUBA_cfg_mcq_esiuba_START (0)
#define SOC_QUE_PROC_V100_QUE_MCQ_ESIUBA_cfg_mcq_esiuba_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int que_cfg_ram_ctrl : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_QUE_PROC_V100_QUE_CFG_RAM_CTRL_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_CFG_RAM_CTRL_que_cfg_ram_ctrl_START (0)
#define SOC_QUE_PROC_V100_QUE_CFG_RAM_CTRL_que_cfg_ram_ctrl_END (01)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int que_cfg_ram_status : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_QUE_PROC_V100_QUE_CFG_RAM_STATUS_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_CFG_RAM_STATUS_que_cfg_ram_status_START (0)
#define SOC_QUE_PROC_V100_QUE_CFG_RAM_STATUS_que_cfg_ram_status_END (01)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sq_sqsize : 10;
        unsigned int reserved_0 : 6;
        unsigned int cfg_sq_cqid : 8;
        unsigned int reserved_1 : 7;
        unsigned int cfg_sq_sqen : 1;
    } reg;
} SOC_QUE_PROC_V100_QUE_SQ_I_ATTR0_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_SQ_I_ATTR0_cfg_sq_sqsize_START (0)
#define SOC_QUE_PROC_V100_QUE_SQ_I_ATTR0_cfg_sq_sqsize_END (9)
#define SOC_QUE_PROC_V100_QUE_SQ_I_ATTR0_cfg_sq_cqid_START (16)
#define SOC_QUE_PROC_V100_QUE_SQ_I_ATTR0_cfg_sq_cqid_END (23)
#define SOC_QUE_PROC_V100_QUE_SQ_I_ATTR0_cfg_sq_sqen_START (31)
#define SOC_QUE_PROC_V100_QUE_SQ_I_ATTR0_cfg_sq_sqen_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 10;
        unsigned int cfg_sq_sqlba : 22;
    } reg;
} SOC_QUE_PROC_V100_QUE_SQ_I_SQLBA0_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_SQ_I_SQLBA0_cfg_sq_sqlba_START (10)
#define SOC_QUE_PROC_V100_QUE_SQ_I_SQLBA0_cfg_sq_sqlba_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sq_squba : 32;
    } reg;
} SOC_QUE_PROC_V100_QUE_SQ_I_SQUBA0_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_SQ_I_SQUBA0_cfg_sq_squba_START (0)
#define SOC_QUE_PROC_V100_QUE_SQ_I_SQUBA0_cfg_sq_squba_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_pmt_en : 1;
        unsigned int cfg_pmt_tail : 12;
        unsigned int reserved : 19;
    } reg;
} SOC_QUE_PROC_V100_QUE_MCQ_PROMT_MSG_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_MCQ_PROMT_MSG_cfg_pmt_en_START (0)
#define SOC_QUE_PROC_V100_QUE_MCQ_PROMT_MSG_cfg_pmt_en_END (0)
#define SOC_QUE_PROC_V100_QUE_MCQ_PROMT_MSG_cfg_pmt_tail_START (1)
#define SOC_QUE_PROC_V100_QUE_MCQ_PROMT_MSG_cfg_pmt_tail_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_cq_cqsize : 10;
        unsigned int reserved : 21;
        unsigned int cfg_cq_cqen : 1;
    } reg;
} SOC_QUE_PROC_V100_QUE_CQ_I_ATTR0_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_CQ_I_ATTR0_cfg_cq_cqsize_START (0)
#define SOC_QUE_PROC_V100_QUE_CQ_I_ATTR0_cfg_cq_cqsize_END (9)
#define SOC_QUE_PROC_V100_QUE_CQ_I_ATTR0_cfg_cq_cqen_START (31)
#define SOC_QUE_PROC_V100_QUE_CQ_I_ATTR0_cfg_cq_cqen_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 10;
        unsigned int cfg_cq_cqlba0 : 22;
    } reg;
} SOC_QUE_PROC_V100_QUE_CQ_I_CQLBA0_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQLBA0_cfg_cq_cqlba0_START (10)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQLBA0_cfg_cq_cqlba0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 10;
        unsigned int cfg_cq_cqlba1 : 22;
    } reg;
} SOC_QUE_PROC_V100_QUE_CQ_I_CQLBA1_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQLBA1_cfg_cq_cqlba1_START (10)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQLBA1_cfg_cq_cqlba1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 10;
        unsigned int cfg_cq_cqlba2 : 22;
    } reg;
} SOC_QUE_PROC_V100_QUE_CQ_I_CQLBA2_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQLBA2_cfg_cq_cqlba2_START (10)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQLBA2_cfg_cq_cqlba2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 10;
        unsigned int cfg_cq_cqlba3 : 22;
    } reg;
} SOC_QUE_PROC_V100_QUE_CQ_I_CQLBA3_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQLBA3_cfg_cq_cqlba3_START (10)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQLBA3_cfg_cq_cqlba3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_cq_cquba0 : 32;
    } reg;
} SOC_QUE_PROC_V100_QUE_CQ_I_CQUBA0_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQUBA0_cfg_cq_cquba0_START (0)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQUBA0_cfg_cq_cquba0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_cq_cquba1 : 32;
    } reg;
} SOC_QUE_PROC_V100_QUE_CQ_I_CQUBA1_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQUBA1_cfg_cq_cquba1_START (0)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQUBA1_cfg_cq_cquba1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_cq_cquba2 : 32;
    } reg;
} SOC_QUE_PROC_V100_QUE_CQ_I_CQUBA2_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQUBA2_cfg_cq_cquba2_START (0)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQUBA2_cfg_cq_cquba2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_cq_cquba3 : 32;
    } reg;
} SOC_QUE_PROC_V100_QUE_CQ_I_CQUBA3_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQUBA3_cfg_cq_cquba3_START (0)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQUBA3_cfg_cq_cquba3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sq_sqh : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_QUE_PROC_V100_QUE_SQ_I_SQH_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_SQ_I_SQH_cfg_sq_sqh_START (0)
#define SOC_QUE_PROC_V100_QUE_SQ_I_SQH_cfg_sq_sqh_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sq_sqt : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_QUE_PROC_V100_QUE_SQ_I_SQT_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_SQ_I_SQT_cfg_sq_sqt_START (0)
#define SOC_QUE_PROC_V100_QUE_SQ_I_SQT_cfg_sq_sqt_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sq_hefs : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int cfg_sq_cds : 1;
        unsigned int reserved_2 : 28;
    } reg;
} SOC_QUE_PROC_V100_QUE_SQ_I_SQIS_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_SQ_I_SQIS_cfg_sq_hefs_START (0)
#define SOC_QUE_PROC_V100_QUE_SQ_I_SQIS_cfg_sq_hefs_END (0)
#define SOC_QUE_PROC_V100_QUE_SQ_I_SQIS_cfg_sq_cds_START (3)
#define SOC_QUE_PROC_V100_QUE_SQ_I_SQIS_cfg_sq_cds_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sq_hefie : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int cfg_sq_cdie : 1;
        unsigned int reserved_2 : 28;
    } reg;
} SOC_QUE_PROC_V100_QUE_SQ_I_SQIE_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_SQ_I_SQIE_cfg_sq_hefie_START (0)
#define SOC_QUE_PROC_V100_QUE_SQ_I_SQIE_cfg_sq_hefie_END (0)
#define SOC_QUE_PROC_V100_QUE_SQ_I_SQIE_cfg_sq_cdie_START (3)
#define SOC_QUE_PROC_V100_QUE_SQ_I_SQIE_cfg_sq_cdie_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_cq_cqh : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_QUE_PROC_V100_QUE_CQ_I_CQH_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQH_cfg_cq_cqh_START (0)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQH_cfg_cq_cqh_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_cq_cqt : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_QUE_PROC_V100_QUE_CQ_I_CQT_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQT_cfg_cq_cqt_START (0)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQT_cfg_cq_cqt_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_cq_teps : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QUE_PROC_V100_QUE_CQ_I_CQIS_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQIS_cfg_cq_teps_START (0)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQIS_cfg_cq_teps_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_cq_tepie : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QUE_PROC_V100_QUE_CQ_I_CQIE_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQIE_cfg_cq_tepie_START (0)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQIE_cfg_cq_tepie_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_cq_iatoval : 8;
        unsigned int cfg_cq_iacth : 5;
        unsigned int reserved_0 : 3;
        unsigned int cfg_cq_ctr : 1;
        unsigned int reserved_1 : 3;
        unsigned int cfg_cq_iasb : 1;
        unsigned int reserved_2 : 3;
        unsigned int cfg_cq_iapwen : 1;
        unsigned int reserved_3 : 6;
        unsigned int cfg_cq_iaen : 1;
    } reg;
} SOC_QUE_PROC_V100_QUE_CQ_I_CQIACR_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQIACR_cfg_cq_iatoval_START (0)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQIACR_cfg_cq_iatoval_END (7)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQIACR_cfg_cq_iacth_START (8)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQIACR_cfg_cq_iacth_END (12)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQIACR_cfg_cq_ctr_START (16)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQIACR_cfg_cq_ctr_END (16)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQIACR_cfg_cq_iasb_START (20)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQIACR_cfg_cq_iasb_END (20)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQIACR_cfg_cq_iapwen_START (24)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQIACR_cfg_cq_iapwen_END (24)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQIACR_cfg_cq_iaen_START (31)
#define SOC_QUE_PROC_V100_QUE_CQ_I_CQIACR_cfg_cq_iaen_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sq_stop : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QUE_PROC_V100_DFA_SQ_I_RTC_UNION;
#endif
#define SOC_QUE_PROC_V100_DFA_SQ_I_RTC_cfg_sq_stop_START (0)
#define SOC_QUE_PROC_V100_DFA_SQ_I_RTC_cfg_sq_stop_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_sq_sts : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QUE_PROC_V100_DFA_SQ_I_RTS_UNION;
#endif
#define SOC_QUE_PROC_V100_DFA_SQ_I_RTS_cfg_sq_sts_START (0)
#define SOC_QUE_PROC_V100_DFA_SQ_I_RTS_cfg_sq_sts_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_sq_sss : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QUE_PROC_V100_DFA_SQ_I_SQIS_UNION;
#endif
#define SOC_QUE_PROC_V100_DFA_SQ_I_SQIS_dfa_sq_sss_START (0)
#define SOC_QUE_PROC_V100_DFA_SQ_I_SQIS_dfa_sq_sss_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_sq_ssie : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QUE_PROC_V100_DFA_SQ_I_SQIE_UNION;
#endif
#define SOC_QUE_PROC_V100_DFA_SQ_I_SQIE_dfa_sq_ssie_START (0)
#define SOC_QUE_PROC_V100_DFA_SQ_I_SQIE_dfa_sq_ssie_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_sq_ots : 9;
        unsigned int dfa_sq_qos : 3;
        unsigned int dfa_pmt_qos : 3;
        unsigned int reserved : 17;
    } reg;
} SOC_QUE_PROC_V100_DFA_SQ_CFIG_UNION;
#endif
#define SOC_QUE_PROC_V100_DFA_SQ_CFIG_dfa_sq_ots_START (0)
#define SOC_QUE_PROC_V100_DFA_SQ_CFIG_dfa_sq_ots_END (8)
#define SOC_QUE_PROC_V100_DFA_SQ_CFIG_dfa_sq_qos_START (9)
#define SOC_QUE_PROC_V100_DFA_SQ_CFIG_dfa_sq_qos_END (11)
#define SOC_QUE_PROC_V100_DFA_SQ_CFIG_dfa_pmt_qos_START (12)
#define SOC_QUE_PROC_V100_DFA_SQ_CFIG_dfa_pmt_qos_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_io_timeout_trsh : 7;
        unsigned int cfg_io_timeout_check_en : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_QUE_PROC_V100_DFA_IO_TIMEOUT_CHECK_UNION;
#endif
#define SOC_QUE_PROC_V100_DFA_IO_TIMEOUT_CHECK_cfg_io_timeout_trsh_START (00)
#define SOC_QUE_PROC_V100_DFA_IO_TIMEOUT_CHECK_cfg_io_timeout_trsh_END (06)
#define SOC_QUE_PROC_V100_DFA_IO_TIMEOUT_CHECK_cfg_io_timeout_check_en_START (07)
#define SOC_QUE_PROC_V100_DFA_IO_TIMEOUT_CHECK_cfg_io_timeout_check_en_END (07)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cmd_proc_timeout : 32;
    } reg;
} SOC_QUE_PROC_V100_DFA_TR_TIMEOUT_STATUS_UNION;
#endif
#define SOC_QUE_PROC_V100_DFA_TR_TIMEOUT_STATUS_cmd_proc_timeout_START (0)
#define SOC_QUE_PROC_V100_DFA_TR_TIMEOUT_STATUS_cmd_proc_timeout_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_mcq_idx_msg : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_QUE_PROC_V100_IO_TIMEOUT_IDX_MSG_UNION;
#endif
#define SOC_QUE_PROC_V100_IO_TIMEOUT_IDX_MSG_cfg_mcq_idx_msg_START (0)
#define SOC_QUE_PROC_V100_IO_TIMEOUT_IDX_MSG_cfg_mcq_idx_msg_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rx_axi_err_addrl : 32;
    } reg;
} SOC_QUE_PROC_V100_QUE_DMA0_RX_AXI_ERR_ADDRL_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_DMA0_RX_AXI_ERR_ADDRL_dma_rx_axi_err_addrl_START (0)
#define SOC_QUE_PROC_V100_QUE_DMA0_RX_AXI_ERR_ADDRL_dma_rx_axi_err_addrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rx_axi_err_addru : 32;
    } reg;
} SOC_QUE_PROC_V100_QUE_DMA0_RX_AXI_ERR_ADDRU_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_DMA0_RX_AXI_ERR_ADDRU_dma_rx_axi_err_addru_START (0)
#define SOC_QUE_PROC_V100_QUE_DMA0_RX_AXI_ERR_ADDRU_dma_rx_axi_err_addru_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_tx_axi_err_addrl : 32;
    } reg;
} SOC_QUE_PROC_V100_QUE_DMA0_TX_AXI_ERR_ADDRL_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_DMA0_TX_AXI_ERR_ADDRL_dma_tx_axi_err_addrl_START (0)
#define SOC_QUE_PROC_V100_QUE_DMA0_TX_AXI_ERR_ADDRL_dma_tx_axi_err_addrl_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_tx_axi_err_addru : 32;
    } reg;
} SOC_QUE_PROC_V100_QUE_DMA0_TX_AXI_ERR_ADDRU_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_DMA0_TX_AXI_ERR_ADDRU_dma_tx_axi_err_addru_START (0)
#define SOC_QUE_PROC_V100_QUE_DMA0_TX_AXI_ERR_ADDRU_dma_tx_axi_err_addru_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_utrd_ba : 32;
    } reg;
} SOC_QUE_PROC_V100_DFA_UTRD_ADDR_UNION;
#endif
#define SOC_QUE_PROC_V100_DFA_UTRD_ADDR_cfg_utrd_ba_START (0)
#define SOC_QUE_PROC_V100_DFA_UTRD_ADDR_cfg_utrd_ba_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_cmd_ba : 32;
    } reg;
} SOC_QUE_PROC_V100_DFA_CMD_ADDR_UNION;
#endif
#define SOC_QUE_PROC_V100_DFA_CMD_ADDR_cfg_cmd_ba_START (0)
#define SOC_QUE_PROC_V100_DFA_CMD_ADDR_cfg_cmd_ba_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_info_ba : 32;
    } reg;
} SOC_QUE_PROC_V100_DFA_INFO_ADDR_UNION;
#endif
#define SOC_QUE_PROC_V100_DFA_INFO_ADDR_cfg_info_ba_START (0)
#define SOC_QUE_PROC_V100_DFA_INFO_ADDR_cfg_info_ba_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_que_utrd_err_int_en : 1;
        unsigned int dfa_que_upiu_err_int_en : 1;
        unsigned int dfa_wakeup_int_en : 1;
        unsigned int dfa_fatel_err_int_en : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_QUE_PROC_V100_QUE_PROC_IE_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_PROC_IE_dfa_que_utrd_err_int_en_START (0)
#define SOC_QUE_PROC_V100_QUE_PROC_IE_dfa_que_utrd_err_int_en_END (0)
#define SOC_QUE_PROC_V100_QUE_PROC_IE_dfa_que_upiu_err_int_en_START (1)
#define SOC_QUE_PROC_V100_QUE_PROC_IE_dfa_que_upiu_err_int_en_END (1)
#define SOC_QUE_PROC_V100_QUE_PROC_IE_dfa_wakeup_int_en_START (2)
#define SOC_QUE_PROC_V100_QUE_PROC_IE_dfa_wakeup_int_en_END (2)
#define SOC_QUE_PROC_V100_QUE_PROC_IE_dfa_fatel_err_int_en_START (3)
#define SOC_QUE_PROC_V100_QUE_PROC_IE_dfa_fatel_err_int_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_que_utrd_err_int : 1;
        unsigned int dfa_que_upiu_err_int : 1;
        unsigned int dfa_wakeup_int : 1;
        unsigned int dfa_fatel_err_int : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_QUE_PROC_V100_QUE_PROC_IS_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_PROC_IS_dfa_que_utrd_err_int_START (0)
#define SOC_QUE_PROC_V100_QUE_PROC_IS_dfa_que_utrd_err_int_END (0)
#define SOC_QUE_PROC_V100_QUE_PROC_IS_dfa_que_upiu_err_int_START (1)
#define SOC_QUE_PROC_V100_QUE_PROC_IS_dfa_que_upiu_err_int_END (1)
#define SOC_QUE_PROC_V100_QUE_PROC_IS_dfa_wakeup_int_START (2)
#define SOC_QUE_PROC_V100_QUE_PROC_IS_dfa_wakeup_int_END (2)
#define SOC_QUE_PROC_V100_QUE_PROC_IS_dfa_fatel_err_int_START (3)
#define SOC_QUE_PROC_V100_QUE_PROC_IS_dfa_fatel_err_int_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_que_utrd_err_int_sim : 1;
        unsigned int dfa_que_upiu_err_int_sim : 1;
        unsigned int dfa_wakeup_int_sim : 1;
        unsigned int dfa_fatel_err_int_sim : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_QUE_PROC_V100_QUE_PROC_IS_SET_UNION;
#endif
#define SOC_QUE_PROC_V100_QUE_PROC_IS_SET_dfa_que_utrd_err_int_sim_START (0)
#define SOC_QUE_PROC_V100_QUE_PROC_IS_SET_dfa_que_utrd_err_int_sim_END (0)
#define SOC_QUE_PROC_V100_QUE_PROC_IS_SET_dfa_que_upiu_err_int_sim_START (1)
#define SOC_QUE_PROC_V100_QUE_PROC_IS_SET_dfa_que_upiu_err_int_sim_END (1)
#define SOC_QUE_PROC_V100_QUE_PROC_IS_SET_dfa_wakeup_int_sim_START (2)
#define SOC_QUE_PROC_V100_QUE_PROC_IS_SET_dfa_wakeup_int_sim_END (2)
#define SOC_QUE_PROC_V100_QUE_PROC_IS_SET_dfa_fatel_err_int_sim_START (3)
#define SOC_QUE_PROC_V100_QUE_PROC_IS_SET_dfa_fatel_err_int_sim_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_rdy : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QUE_PROC_V100_DFA_CPU_RDY_UNION;
#endif
#define SOC_QUE_PROC_V100_DFA_CPU_RDY_dfa_rdy_START (0)
#define SOC_QUE_PROC_V100_DFA_CPU_RDY_dfa_rdy_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_sq0_updata : 1;
        unsigned int dfa_sq1_updata : 1;
        unsigned int dfa_sq2_updata : 1;
        unsigned int dfa_sq3_updata : 1;
        unsigned int dfa_sq4_updata : 1;
        unsigned int dfa_sq_idx_updata : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_QUE_PROC_V100_CHECK_QUE_SQ_UNION;
#endif
#define SOC_QUE_PROC_V100_CHECK_QUE_SQ_dfa_sq0_updata_START (0)
#define SOC_QUE_PROC_V100_CHECK_QUE_SQ_dfa_sq0_updata_END (0)
#define SOC_QUE_PROC_V100_CHECK_QUE_SQ_dfa_sq1_updata_START (1)
#define SOC_QUE_PROC_V100_CHECK_QUE_SQ_dfa_sq1_updata_END (1)
#define SOC_QUE_PROC_V100_CHECK_QUE_SQ_dfa_sq2_updata_START (2)
#define SOC_QUE_PROC_V100_CHECK_QUE_SQ_dfa_sq2_updata_END (2)
#define SOC_QUE_PROC_V100_CHECK_QUE_SQ_dfa_sq3_updata_START (3)
#define SOC_QUE_PROC_V100_CHECK_QUE_SQ_dfa_sq3_updata_END (3)
#define SOC_QUE_PROC_V100_CHECK_QUE_SQ_dfa_sq4_updata_START (4)
#define SOC_QUE_PROC_V100_CHECK_QUE_SQ_dfa_sq4_updata_END (4)
#define SOC_QUE_PROC_V100_CHECK_QUE_SQ_dfa_sq_idx_updata_START (5)
#define SOC_QUE_PROC_V100_CHECK_QUE_SQ_dfa_sq_idx_updata_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_sq0_ots : 2;
        unsigned int dfa_sq1_ots : 2;
        unsigned int dfa_sq2_ots : 2;
        unsigned int dfa_sq3_ots : 2;
        unsigned int dfa_sq4_ots : 2;
        unsigned int reserved : 22;
    } reg;
} SOC_QUE_PROC_V100_DFA_SQ_UPDATA_OTS_UNION;
#endif
#define SOC_QUE_PROC_V100_DFA_SQ_UPDATA_OTS_dfa_sq0_ots_START (0)
#define SOC_QUE_PROC_V100_DFA_SQ_UPDATA_OTS_dfa_sq0_ots_END (1)
#define SOC_QUE_PROC_V100_DFA_SQ_UPDATA_OTS_dfa_sq1_ots_START (2)
#define SOC_QUE_PROC_V100_DFA_SQ_UPDATA_OTS_dfa_sq1_ots_END (3)
#define SOC_QUE_PROC_V100_DFA_SQ_UPDATA_OTS_dfa_sq2_ots_START (4)
#define SOC_QUE_PROC_V100_DFA_SQ_UPDATA_OTS_dfa_sq2_ots_END (5)
#define SOC_QUE_PROC_V100_DFA_SQ_UPDATA_OTS_dfa_sq3_ots_START (6)
#define SOC_QUE_PROC_V100_DFA_SQ_UPDATA_OTS_dfa_sq3_ots_END (7)
#define SOC_QUE_PROC_V100_DFA_SQ_UPDATA_OTS_dfa_sq4_ots_START (8)
#define SOC_QUE_PROC_V100_DFA_SQ_UPDATA_OTS_dfa_sq4_ots_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_ufs_axi_wr_user : 8;
        unsigned int cfg_ufs_axi_rd_user : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_QUE_PROC_V100_UFS_AXI_MST_USR_CFG_UNION;
#endif
#define SOC_QUE_PROC_V100_UFS_AXI_MST_USR_CFG_cfg_ufs_axi_wr_user_START (0)
#define SOC_QUE_PROC_V100_UFS_AXI_MST_USR_CFG_cfg_ufs_axi_wr_user_END (7)
#define SOC_QUE_PROC_V100_UFS_AXI_MST_USR_CFG_cfg_ufs_axi_rd_user_START (8)
#define SOC_QUE_PROC_V100_UFS_AXI_MST_USR_CFG_cfg_ufs_axi_rd_user_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dma_rx_ost_num_cfg : 4;
        unsigned int dma_tx_ost_num_cfg : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_QUE_PROC_V100_UFS_DMAC_OUTSTANDING_CFG_UNION;
#endif
#define SOC_QUE_PROC_V100_UFS_DMAC_OUTSTANDING_CFG_dma_rx_ost_num_cfg_START (0)
#define SOC_QUE_PROC_V100_UFS_DMAC_OUTSTANDING_CFG_dma_rx_ost_num_cfg_END (3)
#define SOC_QUE_PROC_V100_UFS_DMAC_OUTSTANDING_CFG_dma_tx_ost_num_cfg_START (4)
#define SOC_QUE_PROC_V100_UFS_DMAC_OUTSTANDING_CFG_dma_tx_ost_num_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_delay_region0 : 15;
        unsigned int cfg_delay_region1 : 15;
        unsigned int reserved : 2;
    } reg;
} SOC_QUE_PROC_V100_CFG_IO_LENTENCY_UNION;
#endif
#define SOC_QUE_PROC_V100_CFG_IO_LENTENCY_cfg_delay_region0_START (0)
#define SOC_QUE_PROC_V100_CFG_IO_LENTENCY_cfg_delay_region0_END (14)
#define SOC_QUE_PROC_V100_CFG_IO_LENTENCY_cfg_delay_region1_START (15)
#define SOC_QUE_PROC_V100_CFG_IO_LENTENCY_cfg_delay_region1_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_io_max_latency : 15;
        unsigned int cfg_clr_max_latency : 1;
        unsigned int que_cnt_timeout_ts : 3;
        unsigned int que_cnt_en : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_QUE_PROC_V100_MAX_IO_LETENCY_UNION;
#endif
#define SOC_QUE_PROC_V100_MAX_IO_LETENCY_cfg_io_max_latency_START (0)
#define SOC_QUE_PROC_V100_MAX_IO_LETENCY_cfg_io_max_latency_END (14)
#define SOC_QUE_PROC_V100_MAX_IO_LETENCY_cfg_clr_max_latency_START (15)
#define SOC_QUE_PROC_V100_MAX_IO_LETENCY_cfg_clr_max_latency_END (15)
#define SOC_QUE_PROC_V100_MAX_IO_LETENCY_que_cnt_timeout_ts_START (16)
#define SOC_QUE_PROC_V100_MAX_IO_LETENCY_que_cnt_timeout_ts_END (18)
#define SOC_QUE_PROC_V100_MAX_IO_LETENCY_que_cnt_en_START (19)
#define SOC_QUE_PROC_V100_MAX_IO_LETENCY_que_cnt_en_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_io_num0 : 32;
    } reg;
} SOC_QUE_PROC_V100_CFG_DELAY_REGION0_UNION;
#endif
#define SOC_QUE_PROC_V100_CFG_DELAY_REGION0_cfg_io_num0_START (0)
#define SOC_QUE_PROC_V100_CFG_DELAY_REGION0_cfg_io_num0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_io_num1 : 32;
    } reg;
} SOC_QUE_PROC_V100_CFG_DELAY_REGION1_UNION;
#endif
#define SOC_QUE_PROC_V100_CFG_DELAY_REGION1_cfg_io_num1_START (0)
#define SOC_QUE_PROC_V100_CFG_DELAY_REGION1_cfg_io_num1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_io_num2 : 32;
    } reg;
} SOC_QUE_PROC_V100_CFG_DELAY_REGION2_UNION;
#endif
#define SOC_QUE_PROC_V100_CFG_DELAY_REGION2_cfg_io_num2_START (0)
#define SOC_QUE_PROC_V100_CFG_DELAY_REGION2_cfg_io_num2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_io_num3 : 32;
    } reg;
} SOC_QUE_PROC_V100_CFG_DELAY_REGION3_UNION;
#endif
#define SOC_QUE_PROC_V100_CFG_DELAY_REGION3_cfg_io_num3_START (0)
#define SOC_QUE_PROC_V100_CFG_DELAY_REGION3_cfg_io_num3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_timeout_ts : 3;
        unsigned int dfa_io_timeout_trsh : 10;
        unsigned int dfa_io_timeout_check_en : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_QUE_PROC_V100_DFA_IO_TIMEOUT_TRSH_UNION;
#endif
#define SOC_QUE_PROC_V100_DFA_IO_TIMEOUT_TRSH_dfa_timeout_ts_START (0)
#define SOC_QUE_PROC_V100_DFA_IO_TIMEOUT_TRSH_dfa_timeout_ts_END (2)
#define SOC_QUE_PROC_V100_DFA_IO_TIMEOUT_TRSH_dfa_io_timeout_trsh_START (3)
#define SOC_QUE_PROC_V100_DFA_IO_TIMEOUT_TRSH_dfa_io_timeout_trsh_END (12)
#define SOC_QUE_PROC_V100_DFA_IO_TIMEOUT_TRSH_dfa_io_timeout_check_en_START (13)
#define SOC_QUE_PROC_V100_DFA_IO_TIMEOUT_TRSH_dfa_io_timeout_check_en_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_io_finish_time : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_QUE_PROC_V100_DFA_IO_FINISH_TIME_UNION;
#endif
#define SOC_QUE_PROC_V100_DFA_IO_FINISH_TIME_dfa_io_finish_time_START (0)
#define SOC_QUE_PROC_V100_DFA_IO_FINISH_TIME_dfa_io_finish_time_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_max_lu : 8;
        unsigned int cfg_wboot_lu : 8;
        unsigned int cfg_lun_check_en : 1;
        unsigned int cfg_lba_check_en : 1;
        unsigned int cfg_utrd_reservebit_check : 1;
        unsigned int cfg_upiu_change_en : 1;
        unsigned int que_idle_freqdown_en : 1;
        unsigned int reserved : 11;
    } reg;
} SOC_QUE_PROC_V100_DFA_LUN_CHECK_UNION;
#endif
#define SOC_QUE_PROC_V100_DFA_LUN_CHECK_cfg_max_lu_START (0)
#define SOC_QUE_PROC_V100_DFA_LUN_CHECK_cfg_max_lu_END (7)
#define SOC_QUE_PROC_V100_DFA_LUN_CHECK_cfg_wboot_lu_START (8)
#define SOC_QUE_PROC_V100_DFA_LUN_CHECK_cfg_wboot_lu_END (15)
#define SOC_QUE_PROC_V100_DFA_LUN_CHECK_cfg_lun_check_en_START (16)
#define SOC_QUE_PROC_V100_DFA_LUN_CHECK_cfg_lun_check_en_END (16)
#define SOC_QUE_PROC_V100_DFA_LUN_CHECK_cfg_lba_check_en_START (17)
#define SOC_QUE_PROC_V100_DFA_LUN_CHECK_cfg_lba_check_en_END (17)
#define SOC_QUE_PROC_V100_DFA_LUN_CHECK_cfg_utrd_reservebit_check_START (18)
#define SOC_QUE_PROC_V100_DFA_LUN_CHECK_cfg_utrd_reservebit_check_END (18)
#define SOC_QUE_PROC_V100_DFA_LUN_CHECK_cfg_upiu_change_en_START (19)
#define SOC_QUE_PROC_V100_DFA_LUN_CHECK_cfg_upiu_change_en_END (19)
#define SOC_QUE_PROC_V100_DFA_LUN_CHECK_que_idle_freqdown_en_START (20)
#define SOC_QUE_PROC_V100_DFA_LUN_CHECK_que_idle_freqdown_en_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ufs_lu0_lgc_blk_num : 32;
    } reg;
} SOC_QUE_PROC_V100_UFS_LU0_LGC_BLK_NUM_UNION;
#endif
#define SOC_QUE_PROC_V100_UFS_LU0_LGC_BLK_NUM_ufs_lu0_lgc_blk_num_START (0)
#define SOC_QUE_PROC_V100_UFS_LU0_LGC_BLK_NUM_ufs_lu0_lgc_blk_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ufs_lu1_lgc_blk_num : 32;
    } reg;
} SOC_QUE_PROC_V100_UFS_LU1_LGC_BLK_NUM_UNION;
#endif
#define SOC_QUE_PROC_V100_UFS_LU1_LGC_BLK_NUM_ufs_lu1_lgc_blk_num_START (0)
#define SOC_QUE_PROC_V100_UFS_LU1_LGC_BLK_NUM_ufs_lu1_lgc_blk_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ufs_lu2_lgc_blk_num : 32;
    } reg;
} SOC_QUE_PROC_V100_UFS_LU2_LGC_BLK_NUM_UNION;
#endif
#define SOC_QUE_PROC_V100_UFS_LU2_LGC_BLK_NUM_ufs_lu2_lgc_blk_num_START (0)
#define SOC_QUE_PROC_V100_UFS_LU2_LGC_BLK_NUM_ufs_lu2_lgc_blk_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ufs_lu3_lgc_blk_num : 32;
    } reg;
} SOC_QUE_PROC_V100_UFS_LU3_LGC_BLK_NUM_UNION;
#endif
#define SOC_QUE_PROC_V100_UFS_LU3_LGC_BLK_NUM_ufs_lu3_lgc_blk_num_START (0)
#define SOC_QUE_PROC_V100_UFS_LU3_LGC_BLK_NUM_ufs_lu3_lgc_blk_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ufs_lu4_lgc_blk_num : 32;
    } reg;
} SOC_QUE_PROC_V100_UFS_LU4_LGC_BLK_NUM_UNION;
#endif
#define SOC_QUE_PROC_V100_UFS_LU4_LGC_BLK_NUM_ufs_lu4_lgc_blk_num_START (0)
#define SOC_QUE_PROC_V100_UFS_LU4_LGC_BLK_NUM_ufs_lu4_lgc_blk_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ufs_lu5_lgc_blk_num : 32;
    } reg;
} SOC_QUE_PROC_V100_UFS_LU5_LGC_BLK_NUM_UNION;
#endif
#define SOC_QUE_PROC_V100_UFS_LU5_LGC_BLK_NUM_ufs_lu5_lgc_blk_num_START (0)
#define SOC_QUE_PROC_V100_UFS_LU5_LGC_BLK_NUM_ufs_lu5_lgc_blk_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ufs_lu6_lgc_blk_num : 32;
    } reg;
} SOC_QUE_PROC_V100_UFS_LU6_LGC_BLK_NUM_UNION;
#endif
#define SOC_QUE_PROC_V100_UFS_LU6_LGC_BLK_NUM_ufs_lu6_lgc_blk_num_START (0)
#define SOC_QUE_PROC_V100_UFS_LU6_LGC_BLK_NUM_ufs_lu6_lgc_blk_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ufs_lu7_lgc_blk_num : 32;
    } reg;
} SOC_QUE_PROC_V100_UFS_LU7_LGC_BLK_NUM_UNION;
#endif
#define SOC_QUE_PROC_V100_UFS_LU7_LGC_BLK_NUM_ufs_lu7_lgc_blk_num_START (0)
#define SOC_QUE_PROC_V100_UFS_LU7_LGC_BLK_NUM_ufs_lu7_lgc_blk_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ufs_boot_lu_lgc_blk_num : 32;
    } reg;
} SOC_QUE_PROC_V100_UFS_BOOT_LU_LGC_BLK_NUM_UNION;
#endif
#define SOC_QUE_PROC_V100_UFS_BOOT_LU_LGC_BLK_NUM_ufs_boot_lu_lgc_blk_num_START (0)
#define SOC_QUE_PROC_V100_UFS_BOOT_LU_LGC_BLK_NUM_ufs_boot_lu_lgc_blk_num_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qproc_sysclk_cg_sw_en : 1;
        unsigned int acore_cfg_reg_cg_sw_en : 1;
        unsigned int dfa_cfg_reg_cg_sw_en : 1;
        unsigned int qproc_arb_cg_sw_en : 1;
        unsigned int qproc_utrd_wr_cg_sw_en : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_QUE_PROC_V100_DFA_BLOCK_CG_CFG_UNION;
#endif
#define SOC_QUE_PROC_V100_DFA_BLOCK_CG_CFG_qproc_sysclk_cg_sw_en_START (0)
#define SOC_QUE_PROC_V100_DFA_BLOCK_CG_CFG_qproc_sysclk_cg_sw_en_END (0)
#define SOC_QUE_PROC_V100_DFA_BLOCK_CG_CFG_acore_cfg_reg_cg_sw_en_START (1)
#define SOC_QUE_PROC_V100_DFA_BLOCK_CG_CFG_acore_cfg_reg_cg_sw_en_END (1)
#define SOC_QUE_PROC_V100_DFA_BLOCK_CG_CFG_dfa_cfg_reg_cg_sw_en_START (2)
#define SOC_QUE_PROC_V100_DFA_BLOCK_CG_CFG_dfa_cfg_reg_cg_sw_en_END (2)
#define SOC_QUE_PROC_V100_DFA_BLOCK_CG_CFG_qproc_arb_cg_sw_en_START (3)
#define SOC_QUE_PROC_V100_DFA_BLOCK_CG_CFG_qproc_arb_cg_sw_en_END (3)
#define SOC_QUE_PROC_V100_DFA_BLOCK_CG_CFG_qproc_utrd_wr_cg_sw_en_START (4)
#define SOC_QUE_PROC_V100_DFA_BLOCK_CG_CFG_qproc_utrd_wr_cg_sw_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfa_io_wr_dtcm_time : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_QUE_PROC_V100_DFA_IO_WR_DTCM_TIME_UNION;
#endif
#define SOC_QUE_PROC_V100_DFA_IO_WR_DTCM_TIME_dfa_io_wr_dtcm_time_START (0)
#define SOC_QUE_PROC_V100_DFA_IO_WR_DTCM_TIME_dfa_io_wr_dtcm_time_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_delay_region2 : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_QUE_PROC_V100_CFG_IO_LENTENCY1_UNION;
#endif
#define SOC_QUE_PROC_V100_CFG_IO_LENTENCY1_cfg_delay_region2_START (0)
#define SOC_QUE_PROC_V100_CFG_IO_LENTENCY1_cfg_delay_region2_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int que_proc_arb_dfx : 32;
    } reg;
} SOC_QUE_PROC_V100_ARB_DFX_UNION;
#endif
#define SOC_QUE_PROC_V100_ARB_DFX_que_proc_arb_dfx_START (0)
#define SOC_QUE_PROC_V100_ARB_DFX_que_proc_arb_dfx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int que_proc_cmd_rd_dfx : 32;
    } reg;
} SOC_QUE_PROC_V100_CMD_RD_DFX_UNION;
#endif
#define SOC_QUE_PROC_V100_CMD_RD_DFX_que_proc_cmd_rd_dfx_START (0)
#define SOC_QUE_PROC_V100_CMD_RD_DFX_que_proc_cmd_rd_dfx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int que_proc_cmd_wr_dfx : 32;
    } reg;
} SOC_QUE_PROC_V100_CMD_WR_DFX_UNION;
#endif
#define SOC_QUE_PROC_V100_CMD_WR_DFX_que_proc_cmd_wr_dfx_START (0)
#define SOC_QUE_PROC_V100_CMD_WR_DFX_que_proc_cmd_wr_dfx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int que_proc_dma_dfx : 32;
    } reg;
} SOC_QUE_PROC_V100_DMA_DFX_UNION;
#endif
#define SOC_QUE_PROC_V100_DMA_DFX_que_proc_dma_dfx_START (0)
#define SOC_QUE_PROC_V100_DMA_DFX_que_proc_dma_dfx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int que_store_load_dfx : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_QUE_PROC_V100_STORE_DFX_UNION;
#endif
#define SOC_QUE_PROC_V100_STORE_DFX_que_store_load_dfx_START (0)
#define SOC_QUE_PROC_V100_STORE_DFX_que_store_load_dfx_END (3)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
