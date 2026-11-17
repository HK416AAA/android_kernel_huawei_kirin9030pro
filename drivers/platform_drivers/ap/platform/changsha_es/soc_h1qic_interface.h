#ifndef __SOC_H1QIC_INTERFACE_H__
#define __SOC_H1QIC_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_H1QIC_IBX_RTL_VER_ADDR(base) ((base) + (0x0000UL))
#define SOC_H1QIC_IBX_RTL_INFO_ADDR(base) ((base) + (0x0004UL))
#define SOC_H1QIC_IBX_RTL_INF1_ADDR(base) ((base) + (0x0008UL))
#define SOC_H1QIC_IBX_RTL_INF2_ADDR(base) ((base) + (0x000CUL))
#define SOC_H1QIC_IBX_NML_CTRL_ADDR(base) ((base) + (0x0010UL))
#define SOC_H1QIC_IBX_CKG_CTRL_ADDR(base) ((base) + (0x0014UL))
#else
#define SOC_H1QIC_IBX_RTL_VER_ADDR(base) ((base) + (0x0000))
#define SOC_H1QIC_IBX_RTL_INFO_ADDR(base) ((base) + (0x0004))
#define SOC_H1QIC_IBX_RTL_INF1_ADDR(base) ((base) + (0x0008))
#define SOC_H1QIC_IBX_RTL_INF2_ADDR(base) ((base) + (0x000C))
#define SOC_H1QIC_IBX_NML_CTRL_ADDR(base) ((base) + (0x0010))
#define SOC_H1QIC_IBX_CKG_CTRL_ADDR(base) ((base) + (0x0014))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_H1QIC_IBH_RTL_VER_ADDR(base) ((base) + (0x0000UL))
#define SOC_H1QIC_IBH_RTL_INFO_ADDR(base) ((base) + (0x0004UL))
#define SOC_H1QIC_IBH_RTL_INF1_ADDR(base) ((base) + (0x0008UL))
#define SOC_H1QIC_IBH_RTL_INF2_ADDR(base) ((base) + (0x000CUL))
#define SOC_H1QIC_IBH_NML_CTR_ADDR(base) ((base) + (0x0010UL))
#define SOC_H1QIC_IBH_CKG_CTRL_ADDR(base) ((base) + (0x0014UL))
#else
#define SOC_H1QIC_IBH_RTL_VER_ADDR(base) ((base) + (0x0000))
#define SOC_H1QIC_IBH_RTL_INFO_ADDR(base) ((base) + (0x0004))
#define SOC_H1QIC_IBH_RTL_INF1_ADDR(base) ((base) + (0x0008))
#define SOC_H1QIC_IBH_RTL_INF2_ADDR(base) ((base) + (0x000C))
#define SOC_H1QIC_IBH_NML_CTR_ADDR(base) ((base) + (0x0010))
#define SOC_H1QIC_IBH_CKG_CTRL_ADDR(base) ((base) + (0x0014))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_H1QIC_IBP_RTL_VER_ADDR(base) ((base) + (0x0000UL))
#define SOC_H1QIC_IBP_RTL_INFO_ADDR(base) ((base) + (0x0004UL))
#define SOC_H1QIC_IBP_RTL_INF1_ADDR(base) ((base) + (0x0008UL))
#define SOC_H1QIC_IBP_RTL_INF2_ADDR(base) ((base) + (0x000CUL))
#define SOC_H1QIC_IBP_CKG_CTRL_ADDR(base) ((base) + (0x0014UL))
#else
#define SOC_H1QIC_IBP_RTL_VER_ADDR(base) ((base) + (0x0000))
#define SOC_H1QIC_IBP_RTL_INFO_ADDR(base) ((base) + (0x0004))
#define SOC_H1QIC_IBP_RTL_INF1_ADDR(base) ((base) + (0x0008))
#define SOC_H1QIC_IBP_RTL_INF2_ADDR(base) ((base) + (0x000C))
#define SOC_H1QIC_IBP_CKG_CTRL_ADDR(base) ((base) + (0x0014))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_H1QIC_IBQ_RTL_VER_ADDR(base) ((base) + (0x0000UL))
#define SOC_H1QIC_IBQ_RTL_INFO_ADDR(base) ((base) + (0x0004UL))
#define SOC_H1QIC_IBQ_RTL_INF1_ADDR(base) ((base) + (0x0008UL))
#define SOC_H1QIC_IBQ_RTL_INF2_ADDR(base) ((base) + (0x000CUL))
#define SOC_H1QIC_IBQ_CUS_ADDR_RT_ADDR(base) ((base) + (0x080UL))
#define SOC_H1QIC_IBQ_CKG_CTRL_ADDR(base) ((base) + (0x0100UL))
#define SOC_H1QIC_IBQ_RAM_TMOD_ADDR(base) ((base) + (0x0104UL))
#define SOC_H1QIC_IBQ_RSV_RW_ADDR(base) ((base) + (0x0108UL))
#define SOC_H1QIC_IBQ_QOS_GEN_FIX_CTRL_ADDR(base) ((base) + (0x0200UL))
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP0_ADDR(base) ((base) + (0x0210UL))
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP1_ADDR(base) ((base) + (0x0214UL))
#define SOC_H1QIC_IBQ_QOS_GEN_RGLR_CTRL_ADDR(base) ((base) + (0x0220UL))
#define SOC_H1QIC_IBQ_QOS_GEN_RGLR_ADDR(base) ((base) + (0x0224UL))
#define SOC_H1QIC_IBQ_QOS_STA_LMTR_ADDR(base) ((base) + (0x0230UL))
#define SOC_H1QIC_IBQ_QOS_DYN_LMTR_ADDR(base) ((base) + (0x0234UL))
#define SOC_H1QIC_IBQ_QOS_STA_VC_LMTR_ADDR(base,vc_num) ((base) + (0x0240+0x4*(vc_num)))
#define SOC_H1QIC_IBQ_QOS_STA_OST_ADDR(base) ((base) + (0x0280UL))
#define SOC_H1QIC_IBQ_QOS_STA_VC_OST_ADDR(base,vc_num) ((base) + (0x0290+0x10*(vc_num)))
#define SOC_H1QIC_IBQ_QOS_DYN_VC_OST_ADDR(base,vc_num) ((base) + (0x0294+0x10*(vc_num)))
#define SOC_H1QIC_IBQ_QOS_TOTAL_VC_OST_ADDR(base,vc_num) ((base) + (0x0298+0x10*(vc_num)))
#define SOC_H1QIC_IBQ_TES_CFG0_ADDR(base) ((base) + (0x0400UL))
#define SOC_H1QIC_IBQ_TES_CFG1_ADDR(base) ((base) + (0x0404UL))
#define SOC_H1QIC_IBQ_TES_FILTER0_ADDR(base) ((base) + (0x0410UL))
#define SOC_H1QIC_IBQ_TES_FILTER1_ADDR(base) ((base) + (0x0414UL))
#define SOC_H1QIC_IBQ_TES_FILTER2_ADDR(base) ((base) + (0x0418UL))
#define SOC_H1QIC_IBQ_TES_FILTER3_ADDR(base) ((base) + (0x041CUL))
#define SOC_H1QIC_IBQ_TES_FILTER4_0_ADDR(base) ((base) + (0x0420UL))
#define SOC_H1QIC_IBQ_TES_FILTER4_1_ADDR(base) ((base) + (0x0424UL))
#define SOC_H1QIC_IBQ_TES_FILTER4_2_ADDR(base) ((base) + (0x0428UL))
#define SOC_H1QIC_IBQ_TES_FILTER4_3_ADDR(base) ((base) + (0x042CUL))
#define SOC_H1QIC_IBQ_TES_FILTER5_0_ADDR(base) ((base) + (0x0430UL))
#define SOC_H1QIC_IBQ_TES_FILTER5_1_ADDR(base) ((base) + (0x0434UL))
#define SOC_H1QIC_IBQ_TES_FILTER5_2_ADDR(base) ((base) + (0x0438UL))
#define SOC_H1QIC_IBQ_TES_FILTER5_3_ADDR(base) ((base) + (0x043CUL))
#define SOC_H1QIC_IBQ_TES_FILTER6_ADDR(base) ((base) + (0x0440UL))
#define SOC_H1QIC_IBQ_TES_FILTER7_ADDR(base) ((base) + (0x0444UL))
#define SOC_H1QIC_IBQ_TES_FILTER8_ADDR(base) ((base) + (0x0448UL))
#define SOC_H1QIC_IBQ_TES_FILTER9_ADDR(base) ((base) + (0x044CUL))
#define SOC_H1QIC_IBQ_TES_INT_STAUS_ADDR(base) ((base) + (0x0450UL))
#define SOC_H1QIC_IBQ_TES_INT_CLR_ADDR(base) ((base) + (0x0454UL))
#define SOC_H1QIC_IBQ_TES_CNT_ADDR(base) ((base) + (0x0480+0x4*tes_cnt))
#define SOC_H1QIC_IBQ_TES_INT_CFG_ADDR(base) ((base) + (0x04C0+0x4*tes_cnt))
#define SOC_H1QIC_IBQ_PARITY_INTR_CTRL_ADDR(base) ((base) + (0x0600UL))
#define SOC_H1QIC_IBQ_PARITY_INTR_CLR_ADDR(base) ((base) + (0x0604UL))
#define SOC_H1QIC_IBQ_PARITY_INTR_INFO0_ADDR(base) ((base) + (0x0608UL))
#define SOC_H1QIC_IBQ_PARITY_CMD_INJECT_ADDR(base) ((base) + (0x0610UL))
#define SOC_H1QIC_IBQ_PARITY_DATA_INJECT_ADDR(base) ((base) + (0x0614UL))
#define SOC_H1QIC_IBQ_DFX_BUSY_ADDR(base) ((base) + (0x0700UL))
#define SOC_H1QIC_IBQ_DFX_OST_ADDR(base) ((base) + (0x0704UL))
#define SOC_H1QIC_IBQ_DFX_QTP_PORT_ADDR(base) ((base) + (0x0708UL))
#define SOC_H1QIC_IBQ_DFX_QSP_PORT_ADDR(base) ((base) + (0x070CUL))
#define SOC_H1QIC_IBQ_RAM_ECC_CTRL_ADDR(base) ((base) + (0x0770UL))
#define SOC_H1QIC_IBQ_RAM_ECC_INTR_CLR_ADDR(base) ((base) + (0x0774UL))
#define SOC_H1QIC_IBQ_RAM_ECC_INFO0_ADDR(base) ((base) + (0x0778UL))
#define SOC_H1QIC_IBQ_RAM_ECC_INFO1_ADDR(base) ((base) + (0x077CUL))
#define SOC_H1QIC_IBQ_DECERR_CLR_ADDR(base) ((base) + (0x0780UL))
#define SOC_H1QIC_IBQ_DECERR_STATUS_ADDR(base) ((base) + (0x0784UL))
#define SOC_H1QIC_IBQ_DECERR_ADDR0_ADDR(base) ((base) + (0x0788UL))
#define SOC_H1QIC_IBQ_DECERR_ADDR1_ADDR(base) ((base) + (0x078CUL))
#else
#define SOC_H1QIC_IBQ_RTL_VER_ADDR(base) ((base) + (0x0000))
#define SOC_H1QIC_IBQ_RTL_INFO_ADDR(base) ((base) + (0x0004))
#define SOC_H1QIC_IBQ_RTL_INF1_ADDR(base) ((base) + (0x0008))
#define SOC_H1QIC_IBQ_RTL_INF2_ADDR(base) ((base) + (0x000C))
#define SOC_H1QIC_IBQ_CUS_ADDR_RT_ADDR(base) ((base) + (0x080))
#define SOC_H1QIC_IBQ_CKG_CTRL_ADDR(base) ((base) + (0x0100))
#define SOC_H1QIC_IBQ_RAM_TMOD_ADDR(base) ((base) + (0x0104))
#define SOC_H1QIC_IBQ_RSV_RW_ADDR(base) ((base) + (0x0108))
#define SOC_H1QIC_IBQ_QOS_GEN_FIX_CTRL_ADDR(base) ((base) + (0x0200))
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP0_ADDR(base) ((base) + (0x0210))
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP1_ADDR(base) ((base) + (0x0214))
#define SOC_H1QIC_IBQ_QOS_GEN_RGLR_CTRL_ADDR(base) ((base) + (0x0220))
#define SOC_H1QIC_IBQ_QOS_GEN_RGLR_ADDR(base) ((base) + (0x0224))
#define SOC_H1QIC_IBQ_QOS_STA_LMTR_ADDR(base) ((base) + (0x0230))
#define SOC_H1QIC_IBQ_QOS_DYN_LMTR_ADDR(base) ((base) + (0x0234))
#define SOC_H1QIC_IBQ_QOS_STA_VC_LMTR_ADDR(base,vc_num) ((base) + (0x0240+0x4*(vc_num)))
#define SOC_H1QIC_IBQ_QOS_STA_OST_ADDR(base) ((base) + (0x0280))
#define SOC_H1QIC_IBQ_QOS_STA_VC_OST_ADDR(base,vc_num) ((base) + (0x0290+0x10*(vc_num)))
#define SOC_H1QIC_IBQ_QOS_DYN_VC_OST_ADDR(base,vc_num) ((base) + (0x0294+0x10*(vc_num)))
#define SOC_H1QIC_IBQ_QOS_TOTAL_VC_OST_ADDR(base,vc_num) ((base) + (0x0298+0x10*(vc_num)))
#define SOC_H1QIC_IBQ_TES_CFG0_ADDR(base) ((base) + (0x0400))
#define SOC_H1QIC_IBQ_TES_CFG1_ADDR(base) ((base) + (0x0404))
#define SOC_H1QIC_IBQ_TES_FILTER0_ADDR(base) ((base) + (0x0410))
#define SOC_H1QIC_IBQ_TES_FILTER1_ADDR(base) ((base) + (0x0414))
#define SOC_H1QIC_IBQ_TES_FILTER2_ADDR(base) ((base) + (0x0418))
#define SOC_H1QIC_IBQ_TES_FILTER3_ADDR(base) ((base) + (0x041C))
#define SOC_H1QIC_IBQ_TES_FILTER4_0_ADDR(base) ((base) + (0x0420))
#define SOC_H1QIC_IBQ_TES_FILTER4_1_ADDR(base) ((base) + (0x0424))
#define SOC_H1QIC_IBQ_TES_FILTER4_2_ADDR(base) ((base) + (0x0428))
#define SOC_H1QIC_IBQ_TES_FILTER4_3_ADDR(base) ((base) + (0x042C))
#define SOC_H1QIC_IBQ_TES_FILTER5_0_ADDR(base) ((base) + (0x0430))
#define SOC_H1QIC_IBQ_TES_FILTER5_1_ADDR(base) ((base) + (0x0434))
#define SOC_H1QIC_IBQ_TES_FILTER5_2_ADDR(base) ((base) + (0x0438))
#define SOC_H1QIC_IBQ_TES_FILTER5_3_ADDR(base) ((base) + (0x043C))
#define SOC_H1QIC_IBQ_TES_FILTER6_ADDR(base) ((base) + (0x0440))
#define SOC_H1QIC_IBQ_TES_FILTER7_ADDR(base) ((base) + (0x0444))
#define SOC_H1QIC_IBQ_TES_FILTER8_ADDR(base) ((base) + (0x0448))
#define SOC_H1QIC_IBQ_TES_FILTER9_ADDR(base) ((base) + (0x044C))
#define SOC_H1QIC_IBQ_TES_INT_STAUS_ADDR(base) ((base) + (0x0450))
#define SOC_H1QIC_IBQ_TES_INT_CLR_ADDR(base) ((base) + (0x0454))
#define SOC_H1QIC_IBQ_TES_CNT_ADDR(base) ((base) + (0x0480+0x4*tes_cnt))
#define SOC_H1QIC_IBQ_TES_INT_CFG_ADDR(base) ((base) + (0x04C0+0x4*tes_cnt))
#define SOC_H1QIC_IBQ_PARITY_INTR_CTRL_ADDR(base) ((base) + (0x0600))
#define SOC_H1QIC_IBQ_PARITY_INTR_CLR_ADDR(base) ((base) + (0x0604))
#define SOC_H1QIC_IBQ_PARITY_INTR_INFO0_ADDR(base) ((base) + (0x0608))
#define SOC_H1QIC_IBQ_PARITY_CMD_INJECT_ADDR(base) ((base) + (0x0610))
#define SOC_H1QIC_IBQ_PARITY_DATA_INJECT_ADDR(base) ((base) + (0x0614))
#define SOC_H1QIC_IBQ_DFX_BUSY_ADDR(base) ((base) + (0x0700))
#define SOC_H1QIC_IBQ_DFX_OST_ADDR(base) ((base) + (0x0704))
#define SOC_H1QIC_IBQ_DFX_QTP_PORT_ADDR(base) ((base) + (0x0708))
#define SOC_H1QIC_IBQ_DFX_QSP_PORT_ADDR(base) ((base) + (0x070C))
#define SOC_H1QIC_IBQ_RAM_ECC_CTRL_ADDR(base) ((base) + (0x0770))
#define SOC_H1QIC_IBQ_RAM_ECC_INTR_CLR_ADDR(base) ((base) + (0x0774))
#define SOC_H1QIC_IBQ_RAM_ECC_INFO0_ADDR(base) ((base) + (0x0778))
#define SOC_H1QIC_IBQ_RAM_ECC_INFO1_ADDR(base) ((base) + (0x077C))
#define SOC_H1QIC_IBQ_DECERR_CLR_ADDR(base) ((base) + (0x0780))
#define SOC_H1QIC_IBQ_DECERR_STATUS_ADDR(base) ((base) + (0x0784))
#define SOC_H1QIC_IBQ_DECERR_ADDR0_ADDR(base) ((base) + (0x0788))
#define SOC_H1QIC_IBQ_DECERR_ADDR1_ADDR(base) ((base) + (0x078C))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_H1QIC_WA_RTL_VER_ADDR(base) ((base) + (0x0000UL))
#define SOC_H1QIC_WA_RTL_INFO_ADDR(base) ((base) + (0x0004UL))
#define SOC_H1QIC_WA_RTL_INF1_ADDR(base) ((base) + (0x0008UL))
#define SOC_H1QIC_WA_RTL_INF2_ADDR(base) ((base) + (0x000CUL))
#define SOC_H1QIC_WA_CKG_CTRL_ADDR(base) ((base) + (0x0010UL))
#define SOC_H1QIC_WA_NML_CTR_ADDR(base) ((base) + (0x0014UL))
#define SOC_H1QIC_WA_DFX_ST0_ADDR(base) ((base) + (0x0080UL))
#define SOC_H1QIC_WA_DFX_ST1_ADDR(base) ((base) + (0x0084UL))
#else
#define SOC_H1QIC_WA_RTL_VER_ADDR(base) ((base) + (0x0000))
#define SOC_H1QIC_WA_RTL_INFO_ADDR(base) ((base) + (0x0004))
#define SOC_H1QIC_WA_RTL_INF1_ADDR(base) ((base) + (0x0008))
#define SOC_H1QIC_WA_RTL_INF2_ADDR(base) ((base) + (0x000C))
#define SOC_H1QIC_WA_CKG_CTRL_ADDR(base) ((base) + (0x0010))
#define SOC_H1QIC_WA_NML_CTR_ADDR(base) ((base) + (0x0014))
#define SOC_H1QIC_WA_DFX_ST0_ADDR(base) ((base) + (0x0080))
#define SOC_H1QIC_WA_DFX_ST1_ADDR(base) ((base) + (0x0084))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_H1QIC_RT_RTL_VER_ADDR(base) ((base) + (0x0000UL))
#define SOC_H1QIC_RT_RTL_INFO_ADDR(base) ((base) + (0x0004UL))
#define SOC_H1QIC_RT_RTL_INF1_ADDR(base) ((base) + (0x0008UL))
#define SOC_H1QIC_RT_RTL_INF2_ADDR(base) ((base) + (0x000CUL))
#define SOC_H1QIC_RT_CKG_CTRL_ADDR(base) ((base) + (0x0100UL))
#define SOC_H1QIC_RT_RSV_RW_ADDR(base) ((base) + (0x0104UL))
#define SOC_H1QIC_RT_QOS_OUP_LMTR_ADDR(base) ((base) + (0x0200+0x4*oup_num))
#define SOC_H1QIC_RT_SFW_CTRL_ADDR(base) ((base) + (0x0300UL))
#define SOC_H1QIC_RT_ARB_OUP_TMOT_ADDR(base) ((base) + (0x0304UL))
#define SOC_H1QIC_RT_DFX_BUSY_ADDR(base) ((base) + (0x0700UL))
#else
#define SOC_H1QIC_RT_RTL_VER_ADDR(base) ((base) + (0x0000))
#define SOC_H1QIC_RT_RTL_INFO_ADDR(base) ((base) + (0x0004))
#define SOC_H1QIC_RT_RTL_INF1_ADDR(base) ((base) + (0x0008))
#define SOC_H1QIC_RT_RTL_INF2_ADDR(base) ((base) + (0x000C))
#define SOC_H1QIC_RT_CKG_CTRL_ADDR(base) ((base) + (0x0100))
#define SOC_H1QIC_RT_RSV_RW_ADDR(base) ((base) + (0x0104))
#define SOC_H1QIC_RT_QOS_OUP_LMTR_ADDR(base) ((base) + (0x0200+0x4*oup_num))
#define SOC_H1QIC_RT_SFW_CTRL_ADDR(base) ((base) + (0x0300))
#define SOC_H1QIC_RT_ARB_OUP_TMOT_ADDR(base) ((base) + (0x0304))
#define SOC_H1QIC_RT_DFX_BUSY_ADDR(base) ((base) + (0x0700))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_H1QIC_EM_INT_MSK_ADDR(base) ((base) + (0x0004UL))
#define SOC_H1QIC_EM_INT_ST_ADDR(base) ((base) + (0x0008UL))
#define SOC_H1QIC_EM_INT_CLR_ADDR(base) ((base) + (0x000CUL))
#define SOC_H1QIC_EM_CKG_CTRL_ADDR(base) ((base) + (0x0010UL))
#define SOC_H1QIC_EM_ERR_LOG0_ADDR(base) ((base) + (0x0020UL))
#define SOC_H1QIC_EM_ERR_LOG1_ADDR(base) ((base) + (0x0028UL))
#define SOC_H1QIC_EM_ERR_LOG2_ADDR(base) ((base) + (0x002CUL))
#define SOC_H1QIC_EM_ERR_LOG3_ADDR(base) ((base) + (0x0030UL))
#define SOC_H1QIC_EM_ERR_LOG4_ADDR(base) ((base) + (0x0034UL))
#define SOC_H1QIC_EM_ERR_LOG5_ADDR(base) ((base) + (0x0040UL))
#define SOC_H1QIC_EM_ERR_LOG6_ADDR(base) ((base) + (0x0044UL))
#define SOC_H1QIC_EM_ERR_LOG7_ADDR(base) ((base) + (0x0048UL))
#else
#define SOC_H1QIC_EM_INT_MSK_ADDR(base) ((base) + (0x0004))
#define SOC_H1QIC_EM_INT_ST_ADDR(base) ((base) + (0x0008))
#define SOC_H1QIC_EM_INT_CLR_ADDR(base) ((base) + (0x000C))
#define SOC_H1QIC_EM_CKG_CTRL_ADDR(base) ((base) + (0x0010))
#define SOC_H1QIC_EM_ERR_LOG0_ADDR(base) ((base) + (0x0020))
#define SOC_H1QIC_EM_ERR_LOG1_ADDR(base) ((base) + (0x0028))
#define SOC_H1QIC_EM_ERR_LOG2_ADDR(base) ((base) + (0x002C))
#define SOC_H1QIC_EM_ERR_LOG3_ADDR(base) ((base) + (0x0030))
#define SOC_H1QIC_EM_ERR_LOG4_ADDR(base) ((base) + (0x0034))
#define SOC_H1QIC_EM_ERR_LOG5_ADDR(base) ((base) + (0x0040))
#define SOC_H1QIC_EM_ERR_LOG6_ADDR(base) ((base) + (0x0044))
#define SOC_H1QIC_EM_ERR_LOG7_ADDR(base) ((base) + (0x0048))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_H1QIC_PKTC_MON_RTL_VER_ADDR(base) ((base) + (0x0000UL))
#define SOC_H1QIC_PKTC_MON_INTR_MASK_ADDR(base) ((base) + (0x0004UL))
#define SOC_H1QIC_PKTC_MON_INTR_STAT_ADDR(base) ((base) + (0x0008UL))
#define SOC_H1QIC_PKTC_MON_INTR_ORG_STAT_ADDR(base) ((base) + (0x000CUL))
#define SOC_H1QIC_PKTC_MON_INTR_CLR_ADDR(base) ((base) + (0x0010UL))
#define SOC_H1QIC_PKTC_MON_FILTER_ADDR_ORG_L_ADDR(base) ((base) + (0x0020+0x40*filter_num))
#define SOC_H1QIC_PKTC_MON_FILTER_ADDR_ORG_H_ADDR(base) ((base) + (0x0024+0x40*filter_num))
#define SOC_H1QIC_PKTC_MON_FILTER_ADDR_END_L_ADDR(base) ((base) + (0x0028+0x40*filter_num))
#define SOC_H1QIC_PKTC_MON_FILTER_ADDR_END_H_ADDR(base) ((base) + (0x002C+0x40*filter_num))
#define SOC_H1QIC_PKTC_MON_FILTER_OPC_ADDR(base) ((base) + (0x0030+0x40*filter_num))
#define SOC_H1QIC_PKTC_MON_FILTER_DSTID_ADDR(base) ((base) + (0x0034+0x40*filter_num))
#define SOC_H1QIC_PKTC_MON_FILTER_SRCID_ADDR(base) ((base) + (0x0038+0x40*filter_num))
#define SOC_H1QIC_PKTC_MON_FILTER_MMIDX_ADDR(base) ((base) + (0x003C+0x40*filter_num))
#define SOC_H1QIC_PKTC_MON_FILTER_SF_ADDR(base) ((base) + (0x0040+0x40*filter_num))
#define SOC_H1QIC_PKTC_MON_FILTER_USER_L_ADDR(base) ((base) + (0x0044+0x40*filter_num))
#define SOC_H1QIC_PKTC_MON_FILTER_USER_H_ADDR(base) ((base) + (0x0048+0x40*filter_num))
#define SOC_H1QIC_PKTC_MON_FILTER_USER_L_MASK_ADDR(base) ((base) + (0x004C+0x40*filter_num))
#define SOC_H1QIC_PKTC_MON_FILTER_USER_H_MASK_ADDR(base) ((base) + (0x0050+0x40*filter_num))
#define SOC_H1QIC_PKTC_MON_FILTER_QOS_ADDR(base) ((base) + (0x0058+0x40*filter_num))
#define SOC_H1QIC_PKTC_MON_FILTERMIX_ADDR(base) ((base) + (0x0220UL))
#define SOC_H1QIC_PKTC_MON_FILTER_HIT_ADDR(base) ((base) + (0x0224UL))
#define SOC_H1QIC_PKTC_MON_FIFO_SFW_EN_ADDR(base) ((base) + (0x0228UL))
#define SOC_H1QIC_PKTC_MON_CLK_CTRL_ADDR(base) ((base) + (0x022CUL))
#define SOC_H1QIC_PKTC_MON_EN_ADDR(base) ((base) + (0x0230UL))
#define SOC_H1QIC_PKTC_MON_COL_CFG_ADDR(base) ((base) + (0x0234UL))
#else
#define SOC_H1QIC_PKTC_MON_RTL_VER_ADDR(base) ((base) + (0x0000))
#define SOC_H1QIC_PKTC_MON_INTR_MASK_ADDR(base) ((base) + (0x0004))
#define SOC_H1QIC_PKTC_MON_INTR_STAT_ADDR(base) ((base) + (0x0008))
#define SOC_H1QIC_PKTC_MON_INTR_ORG_STAT_ADDR(base) ((base) + (0x000C))
#define SOC_H1QIC_PKTC_MON_INTR_CLR_ADDR(base) ((base) + (0x0010))
#define SOC_H1QIC_PKTC_MON_FILTER_ADDR_ORG_L_ADDR(base) ((base) + (0x0020+0x40*filter_num))
#define SOC_H1QIC_PKTC_MON_FILTER_ADDR_ORG_H_ADDR(base) ((base) + (0x0024+0x40*filter_num))
#define SOC_H1QIC_PKTC_MON_FILTER_ADDR_END_L_ADDR(base) ((base) + (0x0028+0x40*filter_num))
#define SOC_H1QIC_PKTC_MON_FILTER_ADDR_END_H_ADDR(base) ((base) + (0x002C+0x40*filter_num))
#define SOC_H1QIC_PKTC_MON_FILTER_OPC_ADDR(base) ((base) + (0x0030+0x40*filter_num))
#define SOC_H1QIC_PKTC_MON_FILTER_DSTID_ADDR(base) ((base) + (0x0034+0x40*filter_num))
#define SOC_H1QIC_PKTC_MON_FILTER_SRCID_ADDR(base) ((base) + (0x0038+0x40*filter_num))
#define SOC_H1QIC_PKTC_MON_FILTER_MMIDX_ADDR(base) ((base) + (0x003C+0x40*filter_num))
#define SOC_H1QIC_PKTC_MON_FILTER_SF_ADDR(base) ((base) + (0x0040+0x40*filter_num))
#define SOC_H1QIC_PKTC_MON_FILTER_USER_L_ADDR(base) ((base) + (0x0044+0x40*filter_num))
#define SOC_H1QIC_PKTC_MON_FILTER_USER_H_ADDR(base) ((base) + (0x0048+0x40*filter_num))
#define SOC_H1QIC_PKTC_MON_FILTER_USER_L_MASK_ADDR(base) ((base) + (0x004C+0x40*filter_num))
#define SOC_H1QIC_PKTC_MON_FILTER_USER_H_MASK_ADDR(base) ((base) + (0x0050+0x40*filter_num))
#define SOC_H1QIC_PKTC_MON_FILTER_QOS_ADDR(base) ((base) + (0x0058+0x40*filter_num))
#define SOC_H1QIC_PKTC_MON_FILTERMIX_ADDR(base) ((base) + (0x0220))
#define SOC_H1QIC_PKTC_MON_FILTER_HIT_ADDR(base) ((base) + (0x0224))
#define SOC_H1QIC_PKTC_MON_FIFO_SFW_EN_ADDR(base) ((base) + (0x0228))
#define SOC_H1QIC_PKTC_MON_CLK_CTRL_ADDR(base) ((base) + (0x022C))
#define SOC_H1QIC_PKTC_MON_EN_ADDR(base) ((base) + (0x0230))
#define SOC_H1QIC_PKTC_MON_COL_CFG_ADDR(base) ((base) + (0x0234))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_H1QIC_PKTC_COL_RTL_VER_ADDR(base) ((base) + (0x0000UL))
#define SOC_H1QIC_PKTC_COL_ATBID_ADDR(base) ((base) + (0x0004UL))
#define SOC_H1QIC_PKTC_COL_ARB_QOS_0_ADDR(base) ((base) + (0x000CUL))
#define SOC_H1QIC_PKTC_COL_ARB_QOS_1_ADDR(base) ((base) + (0x0010UL))
#define SOC_H1QIC_PKTC_COL_ARB_NODEID_0_ADDR(base) ((base) + (0x0014UL))
#define SOC_H1QIC_PKTC_COL_ARB_NODEID_1_ADDR(base) ((base) + (0x0018UL))
#define SOC_H1QIC_PKTC_COL_ARB_NODEID_2_ADDR(base) ((base) + (0x001CUL))
#define SOC_H1QIC_PKTC_COL_SYNC_PKT_INTERVAL_ADDR(base) ((base) + (0x0020UL))
#define SOC_H1QIC_PKTC_CLK_CTRL_ADDR(base) ((base) + (0x0024UL))
#else
#define SOC_H1QIC_PKTC_COL_RTL_VER_ADDR(base) ((base) + (0x0000))
#define SOC_H1QIC_PKTC_COL_ATBID_ADDR(base) ((base) + (0x0004))
#define SOC_H1QIC_PKTC_COL_ARB_QOS_0_ADDR(base) ((base) + (0x000C))
#define SOC_H1QIC_PKTC_COL_ARB_QOS_1_ADDR(base) ((base) + (0x0010))
#define SOC_H1QIC_PKTC_COL_ARB_NODEID_0_ADDR(base) ((base) + (0x0014))
#define SOC_H1QIC_PKTC_COL_ARB_NODEID_1_ADDR(base) ((base) + (0x0018))
#define SOC_H1QIC_PKTC_COL_ARB_NODEID_2_ADDR(base) ((base) + (0x001C))
#define SOC_H1QIC_PKTC_COL_SYNC_PKT_INTERVAL_ADDR(base) ((base) + (0x0020))
#define SOC_H1QIC_PKTC_CLK_CTRL_ADDR(base) ((base) + (0x0024))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_H1QIC_TBX_RTL_VER_ADDR(base) ((base) + (0x0000UL))
#define SOC_H1QIC_TBX_RTL_INFO_ADDR(base) ((base) + (0x0004UL))
#define SOC_H1QIC_TBX_RTL_INF1_ADDR(base) ((base) + (0x0008UL))
#define SOC_H1QIC_TBX_RTL_INF2_ADDR(base) ((base) + (0x000CUL))
#define SOC_H1QIC_TBX_NML_CTR_ADDR(base) ((base) + (0x0010UL))
#define SOC_H1QIC_TBX_CKG_CTRL_ADDR(base) ((base) + (0x0014UL))
#else
#define SOC_H1QIC_TBX_RTL_VER_ADDR(base) ((base) + (0x0000))
#define SOC_H1QIC_TBX_RTL_INFO_ADDR(base) ((base) + (0x0004))
#define SOC_H1QIC_TBX_RTL_INF1_ADDR(base) ((base) + (0x0008))
#define SOC_H1QIC_TBX_RTL_INF2_ADDR(base) ((base) + (0x000C))
#define SOC_H1QIC_TBX_NML_CTR_ADDR(base) ((base) + (0x0010))
#define SOC_H1QIC_TBX_CKG_CTRL_ADDR(base) ((base) + (0x0014))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_H1QIC_TBH_RTL_VER_ADDR(base) ((base) + (0x0000UL))
#define SOC_H1QIC_TBH_RTL_INFO_ADDR(base) ((base) + (0x0004UL))
#define SOC_H1QIC_TBH_RTL_INF1_ADDR(base) ((base) + (0x0008UL))
#define SOC_H1QIC_TBH_RTL_INF2_ADDR(base) ((base) + (0x000CUL))
#define SOC_H1QIC_TBH_CKG_CTRL_ADDR(base) ((base) + (0x0010UL))
#else
#define SOC_H1QIC_TBH_RTL_VER_ADDR(base) ((base) + (0x0000))
#define SOC_H1QIC_TBH_RTL_INFO_ADDR(base) ((base) + (0x0004))
#define SOC_H1QIC_TBH_RTL_INF1_ADDR(base) ((base) + (0x0008))
#define SOC_H1QIC_TBH_RTL_INF2_ADDR(base) ((base) + (0x000C))
#define SOC_H1QIC_TBH_CKG_CTRL_ADDR(base) ((base) + (0x0010))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_H1QIC_TBP_RTL_VER_ADDR(base) ((base) + (0x0000UL))
#define SOC_H1QIC_TBP_RTL_INFO_ADDR(base) ((base) + (0x0004UL))
#define SOC_H1QIC_TBP_RTL_INF1_ADDR(base) ((base) + (0x0008UL))
#define SOC_H1QIC_TBP_RTL_INF2_ADDR(base) ((base) + (0x000CUL))
#define SOC_H1QIC_TBP_CKG_CTRL_ADDR(base) ((base) + (0x0010UL))
#else
#define SOC_H1QIC_TBP_RTL_VER_ADDR(base) ((base) + (0x0000))
#define SOC_H1QIC_TBP_RTL_INFO_ADDR(base) ((base) + (0x0004))
#define SOC_H1QIC_TBP_RTL_INF1_ADDR(base) ((base) + (0x0008))
#define SOC_H1QIC_TBP_RTL_INF2_ADDR(base) ((base) + (0x000C))
#define SOC_H1QIC_TBP_CKG_CTRL_ADDR(base) ((base) + (0x0010))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_H1QIC_TBQ_RTL_VER_ADDR(base) ((base) + (0x0000UL))
#define SOC_H1QIC_TBQ_RTL_INFO_ADDR(base) ((base) + (0x0004UL))
#define SOC_H1QIC_TBQ_RTL_INF1_ADDR(base) ((base) + (0x0008UL))
#define SOC_H1QIC_TBQ_RTL_INF2_ADDR(base) ((base) + (0x000CUL))
#define SOC_H1QIC_TBQ_CKG_CTRL_ADDR(base) ((base) + (0x0100UL))
#define SOC_H1QIC_TBQ_RSV_RW_ADDR(base) ((base) + (0x0108UL))
#define SOC_H1QIC_TBQ_QOS_STA_LMTR_ADDR(base) ((base) + (0x0230UL))
#define SOC_H1QIC_TBQ_QOS_STA_VC_LMTR_ADDR(base,vc_num) ((base) + (0x0240+0x4*(vc_num)))
#define SOC_H1QIC_TBQ_QOS_DYN_VC_LMTR_ADDR(base,vc_num) ((base) + (0x0260+0x4*(vc_num)))
#define SOC_H1QIC_TBQ_QOS_STA_OST_ADDR(base) ((base) + (0x0280UL))
#define SOC_H1QIC_TBQ_QOS_STA_VC_OST_ADDR(base,vc_num) ((base) + (0x0290+0x10*(vc_num)))
#define SOC_H1QIC_TBQ_QOS_DYN_VC_OST_ADDR(base,vc_num) ((base) + (0x0294+0x10*(vc_num)))
#define SOC_H1QIC_TBQ_QOS_TOTAL_VC_OST_ADDR(base,vc_num) ((base) + (0x0298+0x10*(vc_num)))
#define SOC_H1QIC_TBQ_TES_CFG0_ADDR(base) ((base) + (0x0400UL))
#define SOC_H1QIC_TBQ_TES_CFG1_ADDR(base) ((base) + (0x0404UL))
#define SOC_H1QIC_TBQ_TES_FILTER0_ADDR(base) ((base) + (0x0410UL))
#define SOC_H1QIC_TBQ_TES_FILTER1_ADDR(base) ((base) + (0x0414UL))
#define SOC_H1QIC_TBQ_TES_FILTER2_ADDR(base) ((base) + (0x0418UL))
#define SOC_H1QIC_TBQ_TES_FILTER3_ADDR(base) ((base) + (0x041CUL))
#define SOC_H1QIC_TBQ_TES_FILTER4_0_ADDR(base) ((base) + (0x0420UL))
#define SOC_H1QIC_TBQ_TES_FILTER4_1_ADDR(base) ((base) + (0x0424UL))
#define SOC_H1QIC_TBQ_TES_FILTER4_2_ADDR(base) ((base) + (0x0428UL))
#define SOC_H1QIC_TBQ_TES_FILTER4_3_ADDR(base) ((base) + (0x042CUL))
#define SOC_H1QIC_TBQ_TES_FILTER5_0_ADDR(base) ((base) + (0x0430UL))
#define SOC_H1QIC_TBQ_TES_FILTER5_1_ADDR(base) ((base) + (0x0434UL))
#define SOC_H1QIC_TBQ_TES_FILTER5_2_ADDR(base) ((base) + (0x0438UL))
#define SOC_H1QIC_TBQ_TES_FILTER5_3_ADDR(base) ((base) + (0x043CUL))
#define SOC_H1QIC_TBQ_TES_FILTER6_ADDR(base) ((base) + (0x0440UL))
#define SOC_H1QIC_TBQ_TES_FILTER7_ADDR(base) ((base) + (0x0444UL))
#define SOC_H1QIC_TBQ_TES_FILTER8_ADDR(base) ((base) + (0x0448UL))
#define SOC_H1QIC_TBQ_TES_FILTER9_ADDR(base) ((base) + (0x044CUL))
#define SOC_H1QIC_TBQ_TES_INT_STAUS_ADDR(base) ((base) + (0x0450UL))
#define SOC_H1QIC_TBQ_TES_INT_CLR_ADDR(base) ((base) + (0x0454UL))
#define SOC_H1QIC_TBQ_TES_CNT_ADDR(base) ((base) + (0x0480+0x4*tes_cnt))
#define SOC_H1QIC_TBQ_TES_INT_CFG_ADDR(base) ((base) + (0x04C0+0x4*tes_cnt))
#define SOC_H1QIC_TBQ_PARITY_INTR_CTRL_ADDR(base) ((base) + (0x0600UL))
#define SOC_H1QIC_TBQ_PARITY_INTR_CLR_ADDR(base) ((base) + (0x0604UL))
#define SOC_H1QIC_TBQ_PARITY_INTR_INFO0_ADDR(base) ((base) + (0x0608UL))
#define SOC_H1QIC_TBQ_PARITY_CMD_INJECT_ADDR(base) ((base) + (0x0610UL))
#define SOC_H1QIC_TBQ_PARITY_DATA_INJECT_ADDR(base) ((base) + (0x0614UL))
#define SOC_H1QIC_TBQ_DFX_BUSY_ADDR(base) ((base) + (0x0700UL))
#define SOC_H1QIC_TBQ_DFX_OT_ADDR(base) ((base) + (0x0704UL))
#define SOC_H1QIC_TBQ_DFX_QTP_PORT_ADDR(base) ((base) + (0x0708UL))
#define SOC_H1QIC_TBQ_DFX_QSP_PORT_ADDR(base) ((base) + (0x070CUL))
#else
#define SOC_H1QIC_TBQ_RTL_VER_ADDR(base) ((base) + (0x0000))
#define SOC_H1QIC_TBQ_RTL_INFO_ADDR(base) ((base) + (0x0004))
#define SOC_H1QIC_TBQ_RTL_INF1_ADDR(base) ((base) + (0x0008))
#define SOC_H1QIC_TBQ_RTL_INF2_ADDR(base) ((base) + (0x000C))
#define SOC_H1QIC_TBQ_CKG_CTRL_ADDR(base) ((base) + (0x0100))
#define SOC_H1QIC_TBQ_RSV_RW_ADDR(base) ((base) + (0x0108))
#define SOC_H1QIC_TBQ_QOS_STA_LMTR_ADDR(base) ((base) + (0x0230))
#define SOC_H1QIC_TBQ_QOS_STA_VC_LMTR_ADDR(base,vc_num) ((base) + (0x0240+0x4*(vc_num)))
#define SOC_H1QIC_TBQ_QOS_DYN_VC_LMTR_ADDR(base,vc_num) ((base) + (0x0260+0x4*(vc_num)))
#define SOC_H1QIC_TBQ_QOS_STA_OST_ADDR(base) ((base) + (0x0280))
#define SOC_H1QIC_TBQ_QOS_STA_VC_OST_ADDR(base,vc_num) ((base) + (0x0290+0x10*(vc_num)))
#define SOC_H1QIC_TBQ_QOS_DYN_VC_OST_ADDR(base,vc_num) ((base) + (0x0294+0x10*(vc_num)))
#define SOC_H1QIC_TBQ_QOS_TOTAL_VC_OST_ADDR(base,vc_num) ((base) + (0x0298+0x10*(vc_num)))
#define SOC_H1QIC_TBQ_TES_CFG0_ADDR(base) ((base) + (0x0400))
#define SOC_H1QIC_TBQ_TES_CFG1_ADDR(base) ((base) + (0x0404))
#define SOC_H1QIC_TBQ_TES_FILTER0_ADDR(base) ((base) + (0x0410))
#define SOC_H1QIC_TBQ_TES_FILTER1_ADDR(base) ((base) + (0x0414))
#define SOC_H1QIC_TBQ_TES_FILTER2_ADDR(base) ((base) + (0x0418))
#define SOC_H1QIC_TBQ_TES_FILTER3_ADDR(base) ((base) + (0x041C))
#define SOC_H1QIC_TBQ_TES_FILTER4_0_ADDR(base) ((base) + (0x0420))
#define SOC_H1QIC_TBQ_TES_FILTER4_1_ADDR(base) ((base) + (0x0424))
#define SOC_H1QIC_TBQ_TES_FILTER4_2_ADDR(base) ((base) + (0x0428))
#define SOC_H1QIC_TBQ_TES_FILTER4_3_ADDR(base) ((base) + (0x042C))
#define SOC_H1QIC_TBQ_TES_FILTER5_0_ADDR(base) ((base) + (0x0430))
#define SOC_H1QIC_TBQ_TES_FILTER5_1_ADDR(base) ((base) + (0x0434))
#define SOC_H1QIC_TBQ_TES_FILTER5_2_ADDR(base) ((base) + (0x0438))
#define SOC_H1QIC_TBQ_TES_FILTER5_3_ADDR(base) ((base) + (0x043C))
#define SOC_H1QIC_TBQ_TES_FILTER6_ADDR(base) ((base) + (0x0440))
#define SOC_H1QIC_TBQ_TES_FILTER7_ADDR(base) ((base) + (0x0444))
#define SOC_H1QIC_TBQ_TES_FILTER8_ADDR(base) ((base) + (0x0448))
#define SOC_H1QIC_TBQ_TES_FILTER9_ADDR(base) ((base) + (0x044C))
#define SOC_H1QIC_TBQ_TES_INT_STAUS_ADDR(base) ((base) + (0x0450))
#define SOC_H1QIC_TBQ_TES_INT_CLR_ADDR(base) ((base) + (0x0454))
#define SOC_H1QIC_TBQ_TES_CNT_ADDR(base) ((base) + (0x0480+0x4*tes_cnt))
#define SOC_H1QIC_TBQ_TES_INT_CFG_ADDR(base) ((base) + (0x04C0+0x4*tes_cnt))
#define SOC_H1QIC_TBQ_PARITY_INTR_CTRL_ADDR(base) ((base) + (0x0600))
#define SOC_H1QIC_TBQ_PARITY_INTR_CLR_ADDR(base) ((base) + (0x0604))
#define SOC_H1QIC_TBQ_PARITY_INTR_INFO0_ADDR(base) ((base) + (0x0608))
#define SOC_H1QIC_TBQ_PARITY_CMD_INJECT_ADDR(base) ((base) + (0x0610))
#define SOC_H1QIC_TBQ_PARITY_DATA_INJECT_ADDR(base) ((base) + (0x0614))
#define SOC_H1QIC_TBQ_DFX_BUSY_ADDR(base) ((base) + (0x0700))
#define SOC_H1QIC_TBQ_DFX_OT_ADDR(base) ((base) + (0x0704))
#define SOC_H1QIC_TBQ_DFX_QTP_PORT_ADDR(base) ((base) + (0x0708))
#define SOC_H1QIC_TBQ_DFX_QSP_PORT_ADDR(base) ((base) + (0x070C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_tag : 8;
        unsigned int reserved_0: 8;
        unsigned int version : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_H1QIC_IBX_RTL_VER_UNION;
#endif
#define SOC_H1QIC_IBX_RTL_VER_rtl_tag_START (0)
#define SOC_H1QIC_IBX_RTL_VER_rtl_tag_END (7)
#define SOC_H1QIC_IBX_RTL_VER_version_START (16)
#define SOC_H1QIC_IBX_RTL_VER_version_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info0 : 32;
    } reg;
} SOC_H1QIC_IBX_RTL_INFO_UNION;
#endif
#define SOC_H1QIC_IBX_RTL_INFO_rtl_info0_START (0)
#define SOC_H1QIC_IBX_RTL_INFO_rtl_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info1 : 32;
    } reg;
} SOC_H1QIC_IBX_RTL_INF1_UNION;
#endif
#define SOC_H1QIC_IBX_RTL_INF1_rtl_info1_START (0)
#define SOC_H1QIC_IBX_RTL_INF1_rtl_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info2 : 32;
    } reg;
} SOC_H1QIC_IBX_RTL_INF2_UNION;
#endif
#define SOC_H1QIC_IBX_RTL_INF2_rtl_info2_START (0)
#define SOC_H1QIC_IBX_RTL_INF2_rtl_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int buffeable_dis : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_H1QIC_IBX_NML_CTRL_UNION;
#endif
#define SOC_H1QIC_IBX_NML_CTRL_buffeable_dis_START (0)
#define SOC_H1QIC_IBX_NML_CTRL_buffeable_dis_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ckg_ext_ena : 1;
        unsigned int ckg_byp_inf : 1;
        unsigned int ckg_byp_req_ar : 1;
        unsigned int ckg_byp_req_aw : 1;
        unsigned int ckg_byp_rsp_r : 1;
        unsigned int ckg_byp_rsp_b : 1;
        unsigned int ckg_byp_cfg : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_H1QIC_IBX_CKG_CTRL_UNION;
#endif
#define SOC_H1QIC_IBX_CKG_CTRL_ckg_ext_ena_START (0)
#define SOC_H1QIC_IBX_CKG_CTRL_ckg_ext_ena_END (0)
#define SOC_H1QIC_IBX_CKG_CTRL_ckg_byp_inf_START (1)
#define SOC_H1QIC_IBX_CKG_CTRL_ckg_byp_inf_END (1)
#define SOC_H1QIC_IBX_CKG_CTRL_ckg_byp_req_ar_START (2)
#define SOC_H1QIC_IBX_CKG_CTRL_ckg_byp_req_ar_END (2)
#define SOC_H1QIC_IBX_CKG_CTRL_ckg_byp_req_aw_START (3)
#define SOC_H1QIC_IBX_CKG_CTRL_ckg_byp_req_aw_END (3)
#define SOC_H1QIC_IBX_CKG_CTRL_ckg_byp_rsp_r_START (4)
#define SOC_H1QIC_IBX_CKG_CTRL_ckg_byp_rsp_r_END (4)
#define SOC_H1QIC_IBX_CKG_CTRL_ckg_byp_rsp_b_START (5)
#define SOC_H1QIC_IBX_CKG_CTRL_ckg_byp_rsp_b_END (5)
#define SOC_H1QIC_IBX_CKG_CTRL_ckg_byp_cfg_START (6)
#define SOC_H1QIC_IBX_CKG_CTRL_ckg_byp_cfg_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_tag : 8;
        unsigned int reserved_0: 8;
        unsigned int version : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_H1QIC_IBH_RTL_VER_UNION;
#endif
#define SOC_H1QIC_IBH_RTL_VER_rtl_tag_START (0)
#define SOC_H1QIC_IBH_RTL_VER_rtl_tag_END (7)
#define SOC_H1QIC_IBH_RTL_VER_version_START (16)
#define SOC_H1QIC_IBH_RTL_VER_version_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info0 : 32;
    } reg;
} SOC_H1QIC_IBH_RTL_INFO_UNION;
#endif
#define SOC_H1QIC_IBH_RTL_INFO_rtl_info0_START (0)
#define SOC_H1QIC_IBH_RTL_INFO_rtl_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info1 : 32;
    } reg;
} SOC_H1QIC_IBH_RTL_INF1_UNION;
#endif
#define SOC_H1QIC_IBH_RTL_INF1_rtl_info1_START (0)
#define SOC_H1QIC_IBH_RTL_INF1_rtl_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info2 : 32;
    } reg;
} SOC_H1QIC_IBH_RTL_INF2_UNION;
#endif
#define SOC_H1QIC_IBH_RTL_INF2_rtl_info2_START (0)
#define SOC_H1QIC_IBH_RTL_INF2_rtl_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int buffeable_dis : 1;
        unsigned int cacheable_dis : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_H1QIC_IBH_NML_CTR_UNION;
#endif
#define SOC_H1QIC_IBH_NML_CTR_buffeable_dis_START (0)
#define SOC_H1QIC_IBH_NML_CTR_buffeable_dis_END (0)
#define SOC_H1QIC_IBH_NML_CTR_cacheable_dis_START (1)
#define SOC_H1QIC_IBH_NML_CTR_cacheable_dis_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ckg_ext_ena : 1;
        unsigned int ckg_byp : 1;
        unsigned int ckg_byp_cfg : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_H1QIC_IBH_CKG_CTRL_UNION;
#endif
#define SOC_H1QIC_IBH_CKG_CTRL_ckg_ext_ena_START (0)
#define SOC_H1QIC_IBH_CKG_CTRL_ckg_ext_ena_END (0)
#define SOC_H1QIC_IBH_CKG_CTRL_ckg_byp_START (1)
#define SOC_H1QIC_IBH_CKG_CTRL_ckg_byp_END (1)
#define SOC_H1QIC_IBH_CKG_CTRL_ckg_byp_cfg_START (2)
#define SOC_H1QIC_IBH_CKG_CTRL_ckg_byp_cfg_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_tag : 8;
        unsigned int reserved_0: 8;
        unsigned int version : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_H1QIC_IBP_RTL_VER_UNION;
#endif
#define SOC_H1QIC_IBP_RTL_VER_rtl_tag_START (0)
#define SOC_H1QIC_IBP_RTL_VER_rtl_tag_END (7)
#define SOC_H1QIC_IBP_RTL_VER_version_START (16)
#define SOC_H1QIC_IBP_RTL_VER_version_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info0 : 32;
    } reg;
} SOC_H1QIC_IBP_RTL_INFO_UNION;
#endif
#define SOC_H1QIC_IBP_RTL_INFO_rtl_info0_START (0)
#define SOC_H1QIC_IBP_RTL_INFO_rtl_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info1 : 32;
    } reg;
} SOC_H1QIC_IBP_RTL_INF1_UNION;
#endif
#define SOC_H1QIC_IBP_RTL_INF1_rtl_info1_START (0)
#define SOC_H1QIC_IBP_RTL_INF1_rtl_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info2 : 32;
    } reg;
} SOC_H1QIC_IBP_RTL_INF2_UNION;
#endif
#define SOC_H1QIC_IBP_RTL_INF2_rtl_info2_START (0)
#define SOC_H1QIC_IBP_RTL_INF2_rtl_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ckg_ext_ena : 1;
        unsigned int ckg_byp : 1;
        unsigned int ckg_byp_cfg : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_H1QIC_IBP_CKG_CTRL_UNION;
#endif
#define SOC_H1QIC_IBP_CKG_CTRL_ckg_ext_ena_START (0)
#define SOC_H1QIC_IBP_CKG_CTRL_ckg_ext_ena_END (0)
#define SOC_H1QIC_IBP_CKG_CTRL_ckg_byp_START (1)
#define SOC_H1QIC_IBP_CKG_CTRL_ckg_byp_END (1)
#define SOC_H1QIC_IBP_CKG_CTRL_ckg_byp_cfg_START (2)
#define SOC_H1QIC_IBP_CKG_CTRL_ckg_byp_cfg_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_tag : 8;
        unsigned int reserved_0: 8;
        unsigned int version : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_H1QIC_IBQ_RTL_VER_UNION;
#endif
#define SOC_H1QIC_IBQ_RTL_VER_rtl_tag_START (0)
#define SOC_H1QIC_IBQ_RTL_VER_rtl_tag_END (7)
#define SOC_H1QIC_IBQ_RTL_VER_version_START (16)
#define SOC_H1QIC_IBQ_RTL_VER_version_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info0 : 32;
    } reg;
} SOC_H1QIC_IBQ_RTL_INFO_UNION;
#endif
#define SOC_H1QIC_IBQ_RTL_INFO_rtl_info0_START (0)
#define SOC_H1QIC_IBQ_RTL_INFO_rtl_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info1 : 32;
    } reg;
} SOC_H1QIC_IBQ_RTL_INF1_UNION;
#endif
#define SOC_H1QIC_IBQ_RTL_INF1_rtl_info1_START (0)
#define SOC_H1QIC_IBQ_RTL_INF1_rtl_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info2 : 32;
    } reg;
} SOC_H1QIC_IBQ_RTL_INF2_UNION;
#endif
#define SOC_H1QIC_IBQ_RTL_INF2_rtl_info2_START (0)
#define SOC_H1QIC_IBQ_RTL_INF2_rtl_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cus_addr_rt : 32;
    } reg;
} SOC_H1QIC_IBQ_CUS_ADDR_RT_UNION;
#endif
#define SOC_H1QIC_IBQ_CUS_ADDR_RT_cus_addr_rt_START (0)
#define SOC_H1QIC_IBQ_CUS_ADDR_RT_cus_addr_rt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ckg_ext_ena : 1;
        unsigned int ckg_byp_ibq : 1;
        unsigned int ckg_byp_req : 1;
        unsigned int ckg_byp_rsp : 1;
        unsigned int ckg_byp_ct : 1;
        unsigned int ckg_byp_qos : 1;
        unsigned int ckg_byp_cfc : 1;
        unsigned int ckg_byp_tes : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_H1QIC_IBQ_CKG_CTRL_UNION;
#endif
#define SOC_H1QIC_IBQ_CKG_CTRL_ckg_ext_ena_START (0)
#define SOC_H1QIC_IBQ_CKG_CTRL_ckg_ext_ena_END (0)
#define SOC_H1QIC_IBQ_CKG_CTRL_ckg_byp_ibq_START (1)
#define SOC_H1QIC_IBQ_CKG_CTRL_ckg_byp_ibq_END (1)
#define SOC_H1QIC_IBQ_CKG_CTRL_ckg_byp_req_START (2)
#define SOC_H1QIC_IBQ_CKG_CTRL_ckg_byp_req_END (2)
#define SOC_H1QIC_IBQ_CKG_CTRL_ckg_byp_rsp_START (3)
#define SOC_H1QIC_IBQ_CKG_CTRL_ckg_byp_rsp_END (3)
#define SOC_H1QIC_IBQ_CKG_CTRL_ckg_byp_ct_START (4)
#define SOC_H1QIC_IBQ_CKG_CTRL_ckg_byp_ct_END (4)
#define SOC_H1QIC_IBQ_CKG_CTRL_ckg_byp_qos_START (5)
#define SOC_H1QIC_IBQ_CKG_CTRL_ckg_byp_qos_END (5)
#define SOC_H1QIC_IBQ_CKG_CTRL_ckg_byp_cfc_START (6)
#define SOC_H1QIC_IBQ_CKG_CTRL_ckg_byp_cfc_END (6)
#define SOC_H1QIC_IBQ_CKG_CTRL_ckg_byp_tes_START (7)
#define SOC_H1QIC_IBQ_CKG_CTRL_ckg_byp_tes_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ram_tmod : 32;
    } reg;
} SOC_H1QIC_IBQ_RAM_TMOD_UNION;
#endif
#define SOC_H1QIC_IBQ_RAM_TMOD_ram_tmod_START (0)
#define SOC_H1QIC_IBQ_RAM_TMOD_ram_tmod_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rsv_rw : 32;
    } reg;
} SOC_H1QIC_IBQ_RSV_RW_UNION;
#endif
#define SOC_H1QIC_IBQ_RSV_RW_rsv_rw_START (0)
#define SOC_H1QIC_IBQ_RSV_RW_rsv_rw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qos_gen_fix_mode : 1;
        unsigned int reserved_0 : 15;
        unsigned int qos_gen_fix_r_pri : 4;
        unsigned int qos_gen_fix_w_pri : 4;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_H1QIC_IBQ_QOS_GEN_FIX_CTRL_UNION;
#endif
#define SOC_H1QIC_IBQ_QOS_GEN_FIX_CTRL_qos_gen_fix_mode_START (0)
#define SOC_H1QIC_IBQ_QOS_GEN_FIX_CTRL_qos_gen_fix_mode_END (0)
#define SOC_H1QIC_IBQ_QOS_GEN_FIX_CTRL_qos_gen_fix_r_pri_START (16)
#define SOC_H1QIC_IBQ_QOS_GEN_FIX_CTRL_qos_gen_fix_r_pri_END (19)
#define SOC_H1QIC_IBQ_QOS_GEN_FIX_CTRL_qos_gen_fix_w_pri_START (20)
#define SOC_H1QIC_IBQ_QOS_GEN_FIX_CTRL_qos_gen_fix_w_pri_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gen_remap_pri0 : 4;
        unsigned int gen_remap_pri1 : 4;
        unsigned int gen_remap_pri2 : 4;
        unsigned int gen_remap_pri3 : 4;
        unsigned int gen_remap_pri4 : 4;
        unsigned int gen_remap_pri5 : 4;
        unsigned int gen_remap_pri6 : 4;
        unsigned int gen_remap_pri7 : 4;
    } reg;
} SOC_H1QIC_IBQ_QOS_GEN_REMAP0_UNION;
#endif
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP0_gen_remap_pri0_START (0)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP0_gen_remap_pri0_END (3)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP0_gen_remap_pri1_START (4)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP0_gen_remap_pri1_END (7)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP0_gen_remap_pri2_START (8)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP0_gen_remap_pri2_END (11)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP0_gen_remap_pri3_START (12)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP0_gen_remap_pri3_END (15)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP0_gen_remap_pri4_START (16)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP0_gen_remap_pri4_END (19)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP0_gen_remap_pri5_START (20)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP0_gen_remap_pri5_END (23)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP0_gen_remap_pri6_START (24)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP0_gen_remap_pri6_END (27)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP0_gen_remap_pri7_START (28)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP0_gen_remap_pri7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gen_remap_pri8 : 4;
        unsigned int gen_remap_pri9 : 4;
        unsigned int gen_remap_pri10 : 4;
        unsigned int gen_remap_pri11 : 4;
        unsigned int gen_remap_pri12 : 4;
        unsigned int gen_remap_pri13 : 4;
        unsigned int gen_remap_pri14 : 4;
        unsigned int gen_remap_pri15 : 4;
    } reg;
} SOC_H1QIC_IBQ_QOS_GEN_REMAP1_UNION;
#endif
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP1_gen_remap_pri8_START (0)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP1_gen_remap_pri8_END (3)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP1_gen_remap_pri9_START (4)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP1_gen_remap_pri9_END (7)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP1_gen_remap_pri10_START (8)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP1_gen_remap_pri10_END (11)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP1_gen_remap_pri11_START (12)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP1_gen_remap_pri11_END (15)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP1_gen_remap_pri12_START (16)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP1_gen_remap_pri12_END (19)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP1_gen_remap_pri13_START (20)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP1_gen_remap_pri13_END (23)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP1_gen_remap_pri14_START (24)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP1_gen_remap_pri14_END (27)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP1_gen_remap_pri15_START (28)
#define SOC_H1QIC_IBQ_QOS_GEN_REMAP1_gen_remap_pri15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qos_gen_rglr_mode : 1;
        unsigned int reserved_0 : 3;
        unsigned int qos_gen_rglr_max : 1;
        unsigned int reserved_1 : 11;
        unsigned int qos_gen_rglr_r_low : 4;
        unsigned int qos_gen_rglr_r_high : 4;
        unsigned int qos_gen_rglr_w_low : 4;
        unsigned int qos_gen_rglr_w_high : 4;
    } reg;
} SOC_H1QIC_IBQ_QOS_GEN_RGLR_CTRL_UNION;
#endif
#define SOC_H1QIC_IBQ_QOS_GEN_RGLR_CTRL_qos_gen_rglr_mode_START (0)
#define SOC_H1QIC_IBQ_QOS_GEN_RGLR_CTRL_qos_gen_rglr_mode_END (0)
#define SOC_H1QIC_IBQ_QOS_GEN_RGLR_CTRL_qos_gen_rglr_max_START (4)
#define SOC_H1QIC_IBQ_QOS_GEN_RGLR_CTRL_qos_gen_rglr_max_END (4)
#define SOC_H1QIC_IBQ_QOS_GEN_RGLR_CTRL_qos_gen_rglr_r_low_START (16)
#define SOC_H1QIC_IBQ_QOS_GEN_RGLR_CTRL_qos_gen_rglr_r_low_END (19)
#define SOC_H1QIC_IBQ_QOS_GEN_RGLR_CTRL_qos_gen_rglr_r_high_START (20)
#define SOC_H1QIC_IBQ_QOS_GEN_RGLR_CTRL_qos_gen_rglr_r_high_END (23)
#define SOC_H1QIC_IBQ_QOS_GEN_RGLR_CTRL_qos_gen_rglr_w_low_START (24)
#define SOC_H1QIC_IBQ_QOS_GEN_RGLR_CTRL_qos_gen_rglr_w_low_END (27)
#define SOC_H1QIC_IBQ_QOS_GEN_RGLR_CTRL_qos_gen_rglr_w_high_START (28)
#define SOC_H1QIC_IBQ_QOS_GEN_RGLR_CTRL_qos_gen_rglr_w_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qos_gen_rglr_bw : 8;
        unsigned int qos_gen_rglr_sat : 8;
        unsigned int reserved_0 : 8;
        unsigned int qos_gen_rglr_lp : 2;
        unsigned int reserved_1 : 5;
        unsigned int qos_gen_rglr_en : 1;
    } reg;
} SOC_H1QIC_IBQ_QOS_GEN_RGLR_UNION;
#endif
#define SOC_H1QIC_IBQ_QOS_GEN_RGLR_qos_gen_rglr_bw_START (0)
#define SOC_H1QIC_IBQ_QOS_GEN_RGLR_qos_gen_rglr_bw_END (7)
#define SOC_H1QIC_IBQ_QOS_GEN_RGLR_qos_gen_rglr_sat_START (8)
#define SOC_H1QIC_IBQ_QOS_GEN_RGLR_qos_gen_rglr_sat_END (15)
#define SOC_H1QIC_IBQ_QOS_GEN_RGLR_qos_gen_rglr_lp_START (24)
#define SOC_H1QIC_IBQ_QOS_GEN_RGLR_qos_gen_rglr_lp_END (25)
#define SOC_H1QIC_IBQ_QOS_GEN_RGLR_qos_gen_rglr_en_START (31)
#define SOC_H1QIC_IBQ_QOS_GEN_RGLR_qos_gen_rglr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sta_lmtr_bw : 8;
        unsigned int sta_lmtr_sat : 8;
        unsigned int reserved_0 : 8;
        unsigned int sta_lmtr_lp : 2;
        unsigned int reserved_1 : 5;
        unsigned int sta_lmtr_en : 1;
    } reg;
} SOC_H1QIC_IBQ_QOS_STA_LMTR_UNION;
#endif
#define SOC_H1QIC_IBQ_QOS_STA_LMTR_sta_lmtr_bw_START (0)
#define SOC_H1QIC_IBQ_QOS_STA_LMTR_sta_lmtr_bw_END (7)
#define SOC_H1QIC_IBQ_QOS_STA_LMTR_sta_lmtr_sat_START (8)
#define SOC_H1QIC_IBQ_QOS_STA_LMTR_sta_lmtr_sat_END (15)
#define SOC_H1QIC_IBQ_QOS_STA_LMTR_sta_lmtr_lp_START (24)
#define SOC_H1QIC_IBQ_QOS_STA_LMTR_sta_lmtr_lp_END (25)
#define SOC_H1QIC_IBQ_QOS_STA_LMTR_sta_lmtr_en_START (31)
#define SOC_H1QIC_IBQ_QOS_STA_LMTR_sta_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dyn_lmtr_bw : 8;
        unsigned int dyn_lmtr_sat : 8;
        unsigned int reserved_0 : 8;
        unsigned int dyn_lmtr_lp : 2;
        unsigned int reserved_1 : 5;
        unsigned int dyn_lmtr_en : 1;
    } reg;
} SOC_H1QIC_IBQ_QOS_DYN_LMTR_UNION;
#endif
#define SOC_H1QIC_IBQ_QOS_DYN_LMTR_dyn_lmtr_bw_START (0)
#define SOC_H1QIC_IBQ_QOS_DYN_LMTR_dyn_lmtr_bw_END (7)
#define SOC_H1QIC_IBQ_QOS_DYN_LMTR_dyn_lmtr_sat_START (8)
#define SOC_H1QIC_IBQ_QOS_DYN_LMTR_dyn_lmtr_sat_END (15)
#define SOC_H1QIC_IBQ_QOS_DYN_LMTR_dyn_lmtr_lp_START (24)
#define SOC_H1QIC_IBQ_QOS_DYN_LMTR_dyn_lmtr_lp_END (25)
#define SOC_H1QIC_IBQ_QOS_DYN_LMTR_dyn_lmtr_en_START (31)
#define SOC_H1QIC_IBQ_QOS_DYN_LMTR_dyn_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sta_vc_lmtr_bw : 8;
        unsigned int sta_vc_lmtr_sat : 8;
        unsigned int reserved_0 : 8;
        unsigned int sta_vc_lmtr_lp : 2;
        unsigned int reserved_1 : 5;
        unsigned int sta_vc_lmtr_en : 1;
    } reg;
} SOC_H1QIC_IBQ_QOS_STA_VC_LMTR_UNION;
#endif
#define SOC_H1QIC_IBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_bw_START (0)
#define SOC_H1QIC_IBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_bw_END (7)
#define SOC_H1QIC_IBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_sat_START (8)
#define SOC_H1QIC_IBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_sat_END (15)
#define SOC_H1QIC_IBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_lp_START (24)
#define SOC_H1QIC_IBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_lp_END (25)
#define SOC_H1QIC_IBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_en_START (31)
#define SOC_H1QIC_IBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sta_ost_wl : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_H1QIC_IBQ_QOS_STA_OST_UNION;
#endif
#define SOC_H1QIC_IBQ_QOS_STA_OST_sta_ost_wl_START (0)
#define SOC_H1QIC_IBQ_QOS_STA_OST_sta_ost_wl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sta_vc_ost_wl : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_H1QIC_IBQ_QOS_STA_VC_OST_UNION;
#endif
#define SOC_H1QIC_IBQ_QOS_STA_VC_OST_sta_vc_ost_wl_START (0)
#define SOC_H1QIC_IBQ_QOS_STA_VC_OST_sta_vc_ost_wl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dyn_vc_ost_wl : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_H1QIC_IBQ_QOS_DYN_VC_OST_UNION;
#endif
#define SOC_H1QIC_IBQ_QOS_DYN_VC_OST_dyn_vc_ost_wl_START (0)
#define SOC_H1QIC_IBQ_QOS_DYN_VC_OST_dyn_vc_ost_wl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vc_total_ost_wl : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_H1QIC_IBQ_QOS_TOTAL_VC_OST_UNION;
#endif
#define SOC_H1QIC_IBQ_QOS_TOTAL_VC_OST_vc_total_ost_wl_START (0)
#define SOC_H1QIC_IBQ_QOS_TOTAL_VC_OST_vc_total_ost_wl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_stat_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int tes_stat_mode : 2;
        unsigned int reserved_1 : 2;
        unsigned int tes_stat_cnt_mode : 24;
    } reg;
} SOC_H1QIC_IBQ_TES_CFG0_UNION;
#endif
#define SOC_H1QIC_IBQ_TES_CFG0_tes_stat_en_START (0)
#define SOC_H1QIC_IBQ_TES_CFG0_tes_stat_en_END (0)
#define SOC_H1QIC_IBQ_TES_CFG0_tes_stat_mode_START (4)
#define SOC_H1QIC_IBQ_TES_CFG0_tes_stat_mode_END (5)
#define SOC_H1QIC_IBQ_TES_CFG0_tes_stat_cnt_mode_START (8)
#define SOC_H1QIC_IBQ_TES_CFG0_tes_stat_cnt_mode_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_latcy_mode : 1;
        unsigned int reserved_0 : 3;
        unsigned int tes_latcy_prescaler : 10;
        unsigned int reserved_1 : 2;
        unsigned int tes_pfm_tes_align_mode : 1;
        unsigned int tes_pfm_tes_cmd_type : 1;
        unsigned int reserved_2 : 14;
    } reg;
} SOC_H1QIC_IBQ_TES_CFG1_UNION;
#endif
#define SOC_H1QIC_IBQ_TES_CFG1_tes_latcy_mode_START (0)
#define SOC_H1QIC_IBQ_TES_CFG1_tes_latcy_mode_END (0)
#define SOC_H1QIC_IBQ_TES_CFG1_tes_latcy_prescaler_START (4)
#define SOC_H1QIC_IBQ_TES_CFG1_tes_latcy_prescaler_END (13)
#define SOC_H1QIC_IBQ_TES_CFG1_tes_pfm_tes_align_mode_START (16)
#define SOC_H1QIC_IBQ_TES_CFG1_tes_pfm_tes_align_mode_END (16)
#define SOC_H1QIC_IBQ_TES_CFG1_tes_pfm_tes_cmd_type_START (17)
#define SOC_H1QIC_IBQ_TES_CFG1_tes_pfm_tes_cmd_type_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_addr_s0 : 32;
    } reg;
} SOC_H1QIC_IBQ_TES_FILTER0_UNION;
#endif
#define SOC_H1QIC_IBQ_TES_FILTER0_tes_addr_s0_START (0)
#define SOC_H1QIC_IBQ_TES_FILTER0_tes_addr_s0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_addr_s1 : 32;
    } reg;
} SOC_H1QIC_IBQ_TES_FILTER1_UNION;
#endif
#define SOC_H1QIC_IBQ_TES_FILTER1_tes_addr_s1_START (0)
#define SOC_H1QIC_IBQ_TES_FILTER1_tes_addr_s1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_addr_e0 : 32;
    } reg;
} SOC_H1QIC_IBQ_TES_FILTER2_UNION;
#endif
#define SOC_H1QIC_IBQ_TES_FILTER2_tes_addr_e0_START (0)
#define SOC_H1QIC_IBQ_TES_FILTER2_tes_addr_e0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_addr_e1 : 32;
    } reg;
} SOC_H1QIC_IBQ_TES_FILTER3_UNION;
#endif
#define SOC_H1QIC_IBQ_TES_FILTER3_tes_addr_e1_START (0)
#define SOC_H1QIC_IBQ_TES_FILTER3_tes_addr_e1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_user0 : 32;
    } reg;
} SOC_H1QIC_IBQ_TES_FILTER4_0_UNION;
#endif
#define SOC_H1QIC_IBQ_TES_FILTER4_0_tes_user0_START (0)
#define SOC_H1QIC_IBQ_TES_FILTER4_0_tes_user0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_user1 : 32;
    } reg;
} SOC_H1QIC_IBQ_TES_FILTER4_1_UNION;
#endif
#define SOC_H1QIC_IBQ_TES_FILTER4_1_tes_user1_START (0)
#define SOC_H1QIC_IBQ_TES_FILTER4_1_tes_user1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_user2 : 32;
    } reg;
} SOC_H1QIC_IBQ_TES_FILTER4_2_UNION;
#endif
#define SOC_H1QIC_IBQ_TES_FILTER4_2_tes_user2_START (0)
#define SOC_H1QIC_IBQ_TES_FILTER4_2_tes_user2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_user3 : 32;
    } reg;
} SOC_H1QIC_IBQ_TES_FILTER4_3_UNION;
#endif
#define SOC_H1QIC_IBQ_TES_FILTER4_3_tes_user3_START (0)
#define SOC_H1QIC_IBQ_TES_FILTER4_3_tes_user3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_user_msk0 : 32;
    } reg;
} SOC_H1QIC_IBQ_TES_FILTER5_0_UNION;
#endif
#define SOC_H1QIC_IBQ_TES_FILTER5_0_tes_user_msk0_START (0)
#define SOC_H1QIC_IBQ_TES_FILTER5_0_tes_user_msk0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_user_msk1 : 32;
    } reg;
} SOC_H1QIC_IBQ_TES_FILTER5_1_UNION;
#endif
#define SOC_H1QIC_IBQ_TES_FILTER5_1_tes_user_msk1_START (0)
#define SOC_H1QIC_IBQ_TES_FILTER5_1_tes_user_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_user_msk2 : 32;
    } reg;
} SOC_H1QIC_IBQ_TES_FILTER5_2_UNION;
#endif
#define SOC_H1QIC_IBQ_TES_FILTER5_2_tes_user_msk2_START (0)
#define SOC_H1QIC_IBQ_TES_FILTER5_2_tes_user_msk2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_user_msk3 : 32;
    } reg;
} SOC_H1QIC_IBQ_TES_FILTER5_3_UNION;
#endif
#define SOC_H1QIC_IBQ_TES_FILTER5_3_tes_user_msk3_START (0)
#define SOC_H1QIC_IBQ_TES_FILTER5_3_tes_user_msk3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_exclid : 8;
        unsigned int tes_exclid_msk : 8;
        unsigned int tes_sf : 8;
        unsigned int tes_sf_msk : 8;
    } reg;
} SOC_H1QIC_IBQ_TES_FILTER6_UNION;
#endif
#define SOC_H1QIC_IBQ_TES_FILTER6_tes_exclid_START (0)
#define SOC_H1QIC_IBQ_TES_FILTER6_tes_exclid_END (7)
#define SOC_H1QIC_IBQ_TES_FILTER6_tes_exclid_msk_START (8)
#define SOC_H1QIC_IBQ_TES_FILTER6_tes_exclid_msk_END (15)
#define SOC_H1QIC_IBQ_TES_FILTER6_tes_sf_START (16)
#define SOC_H1QIC_IBQ_TES_FILTER6_tes_sf_END (23)
#define SOC_H1QIC_IBQ_TES_FILTER6_tes_sf_msk_START (24)
#define SOC_H1QIC_IBQ_TES_FILTER6_tes_sf_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_qos : 8;
        unsigned int tes_tid : 8;
        unsigned int tes_tid_msk : 8;
        unsigned int tes_lck : 4;
        unsigned int tes_lck_msk : 4;
    } reg;
} SOC_H1QIC_IBQ_TES_FILTER7_UNION;
#endif
#define SOC_H1QIC_IBQ_TES_FILTER7_tes_qos_START (0)
#define SOC_H1QIC_IBQ_TES_FILTER7_tes_qos_END (7)
#define SOC_H1QIC_IBQ_TES_FILTER7_tes_tid_START (8)
#define SOC_H1QIC_IBQ_TES_FILTER7_tes_tid_END (15)
#define SOC_H1QIC_IBQ_TES_FILTER7_tes_tid_msk_START (16)
#define SOC_H1QIC_IBQ_TES_FILTER7_tes_tid_msk_END (23)
#define SOC_H1QIC_IBQ_TES_FILTER7_tes_lck_START (24)
#define SOC_H1QIC_IBQ_TES_FILTER7_tes_lck_END (27)
#define SOC_H1QIC_IBQ_TES_FILTER7_tes_lck_msk_START (28)
#define SOC_H1QIC_IBQ_TES_FILTER7_tes_lck_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_tsize_min : 16;
        unsigned int tes_tsize_max : 16;
    } reg;
} SOC_H1QIC_IBQ_TES_FILTER8_UNION;
#endif
#define SOC_H1QIC_IBQ_TES_FILTER8_tes_tsize_min_START (0)
#define SOC_H1QIC_IBQ_TES_FILTER8_tes_tsize_min_END (15)
#define SOC_H1QIC_IBQ_TES_FILTER8_tes_tsize_max_START (16)
#define SOC_H1QIC_IBQ_TES_FILTER8_tes_tsize_max_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_dstid : 8;
        unsigned int tes_dstid_msk : 8;
        unsigned int tes_vcnum : 4;
        unsigned int tes_vcnum_msk : 4;
        unsigned int tes_burst : 1;
        unsigned int tes_burst_msk : 1;
        unsigned int tes_wr : 1;
        unsigned int tes_wr_msk : 1;
        unsigned int tes_rd : 1;
        unsigned int tes_rd_msk : 1;
        unsigned int tes_splt_cmd : 1;
        unsigned int tes_splt_cmd_msk : 1;
    } reg;
} SOC_H1QIC_IBQ_TES_FILTER9_UNION;
#endif
#define SOC_H1QIC_IBQ_TES_FILTER9_tes_dstid_START (0)
#define SOC_H1QIC_IBQ_TES_FILTER9_tes_dstid_END (7)
#define SOC_H1QIC_IBQ_TES_FILTER9_tes_dstid_msk_START (8)
#define SOC_H1QIC_IBQ_TES_FILTER9_tes_dstid_msk_END (15)
#define SOC_H1QIC_IBQ_TES_FILTER9_tes_vcnum_START (16)
#define SOC_H1QIC_IBQ_TES_FILTER9_tes_vcnum_END (19)
#define SOC_H1QIC_IBQ_TES_FILTER9_tes_vcnum_msk_START (20)
#define SOC_H1QIC_IBQ_TES_FILTER9_tes_vcnum_msk_END (23)
#define SOC_H1QIC_IBQ_TES_FILTER9_tes_burst_START (24)
#define SOC_H1QIC_IBQ_TES_FILTER9_tes_burst_END (24)
#define SOC_H1QIC_IBQ_TES_FILTER9_tes_burst_msk_START (25)
#define SOC_H1QIC_IBQ_TES_FILTER9_tes_burst_msk_END (25)
#define SOC_H1QIC_IBQ_TES_FILTER9_tes_wr_START (26)
#define SOC_H1QIC_IBQ_TES_FILTER9_tes_wr_END (26)
#define SOC_H1QIC_IBQ_TES_FILTER9_tes_wr_msk_START (27)
#define SOC_H1QIC_IBQ_TES_FILTER9_tes_wr_msk_END (27)
#define SOC_H1QIC_IBQ_TES_FILTER9_tes_rd_START (28)
#define SOC_H1QIC_IBQ_TES_FILTER9_tes_rd_END (28)
#define SOC_H1QIC_IBQ_TES_FILTER9_tes_rd_msk_START (29)
#define SOC_H1QIC_IBQ_TES_FILTER9_tes_rd_msk_END (29)
#define SOC_H1QIC_IBQ_TES_FILTER9_tes_splt_cmd_START (30)
#define SOC_H1QIC_IBQ_TES_FILTER9_tes_splt_cmd_END (30)
#define SOC_H1QIC_IBQ_TES_FILTER9_tes_splt_cmd_msk_START (31)
#define SOC_H1QIC_IBQ_TES_FILTER9_tes_splt_cmd_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_stat_cnt_int : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_H1QIC_IBQ_TES_INT_STAUS_UNION;
#endif
#define SOC_H1QIC_IBQ_TES_INT_STAUS_tes_stat_cnt_int_START (0)
#define SOC_H1QIC_IBQ_TES_INT_STAUS_tes_stat_cnt_int_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_stat_cnt_int_clr : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_H1QIC_IBQ_TES_INT_CLR_UNION;
#endif
#define SOC_H1QIC_IBQ_TES_INT_CLR_tes_stat_cnt_int_clr_START (0)
#define SOC_H1QIC_IBQ_TES_INT_CLR_tes_stat_cnt_int_clr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_stat_cnt : 32;
    } reg;
} SOC_H1QIC_IBQ_TES_CNT_UNION;
#endif
#define SOC_H1QIC_IBQ_TES_CNT_tes_stat_cnt_START (0)
#define SOC_H1QIC_IBQ_TES_CNT_tes_stat_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_stat_cnt_int_th : 32;
    } reg;
} SOC_H1QIC_IBQ_TES_INT_CFG_UNION;
#endif
#define SOC_H1QIC_IBQ_TES_INT_CFG_tes_stat_cnt_int_th_START (0)
#define SOC_H1QIC_IBQ_TES_INT_CFG_tes_stat_cnt_int_th_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int parity_dis : 3;
        unsigned int reserved_0 : 1;
        unsigned int parity_intr_mask : 3;
        unsigned int reserved_1 : 25;
    } reg;
} SOC_H1QIC_IBQ_PARITY_INTR_CTRL_UNION;
#endif
#define SOC_H1QIC_IBQ_PARITY_INTR_CTRL_parity_dis_START (0)
#define SOC_H1QIC_IBQ_PARITY_INTR_CTRL_parity_dis_END (2)
#define SOC_H1QIC_IBQ_PARITY_INTR_CTRL_parity_intr_mask_START (4)
#define SOC_H1QIC_IBQ_PARITY_INTR_CTRL_parity_intr_mask_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int parity_intr_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_H1QIC_IBQ_PARITY_INTR_CLR_UNION;
#endif
#define SOC_H1QIC_IBQ_PARITY_INTR_CLR_parity_intr_clr_START (0)
#define SOC_H1QIC_IBQ_PARITY_INTR_CLR_parity_intr_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int parity_mask_status : 4;
        unsigned int reserved_0 : 4;
        unsigned int parity_org_status : 4;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_H1QIC_IBQ_PARITY_INTR_INFO0_UNION;
#endif
#define SOC_H1QIC_IBQ_PARITY_INTR_INFO0_parity_mask_status_START (0)
#define SOC_H1QIC_IBQ_PARITY_INTR_INFO0_parity_mask_status_END (3)
#define SOC_H1QIC_IBQ_PARITY_INTR_INFO0_parity_org_status_START (8)
#define SOC_H1QIC_IBQ_PARITY_INTR_INFO0_parity_org_status_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int parity_cmd_inject : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_H1QIC_IBQ_PARITY_CMD_INJECT_UNION;
#endif
#define SOC_H1QIC_IBQ_PARITY_CMD_INJECT_parity_cmd_inject_START (0)
#define SOC_H1QIC_IBQ_PARITY_CMD_INJECT_parity_cmd_inject_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int parity_data_inject : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_H1QIC_IBQ_PARITY_DATA_INJECT_UNION;
#endif
#define SOC_H1QIC_IBQ_PARITY_DATA_INJECT_parity_data_inject_START (0)
#define SOC_H1QIC_IBQ_PARITY_DATA_INJECT_parity_data_inject_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_busy : 32;
    } reg;
} SOC_H1QIC_IBQ_DFX_BUSY_UNION;
#endif
#define SOC_H1QIC_IBQ_DFX_BUSY_dfx_busy_START (0)
#define SOC_H1QIC_IBQ_DFX_BUSY_dfx_busy_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_ost_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_H1QIC_IBQ_DFX_OST_UNION;
#endif
#define SOC_H1QIC_IBQ_DFX_OST_dfx_ost_cnt_START (0)
#define SOC_H1QIC_IBQ_DFX_OST_dfx_ost_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_qtp_req_bp : 8;
        unsigned int dfx_qtp_req_trans : 8;
        unsigned int dfx_qtp_rsp_bp : 1;
        unsigned int dfx_qtp_rsp_trans : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_H1QIC_IBQ_DFX_QTP_PORT_UNION;
#endif
#define SOC_H1QIC_IBQ_DFX_QTP_PORT_dfx_qtp_req_bp_START (0)
#define SOC_H1QIC_IBQ_DFX_QTP_PORT_dfx_qtp_req_bp_END (7)
#define SOC_H1QIC_IBQ_DFX_QTP_PORT_dfx_qtp_req_trans_START (8)
#define SOC_H1QIC_IBQ_DFX_QTP_PORT_dfx_qtp_req_trans_END (15)
#define SOC_H1QIC_IBQ_DFX_QTP_PORT_dfx_qtp_rsp_bp_START (16)
#define SOC_H1QIC_IBQ_DFX_QTP_PORT_dfx_qtp_rsp_bp_END (16)
#define SOC_H1QIC_IBQ_DFX_QTP_PORT_dfx_qtp_rsp_trans_START (17)
#define SOC_H1QIC_IBQ_DFX_QTP_PORT_dfx_qtp_rsp_trans_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_qsp_req_bp : 8;
        unsigned int dfx_qsp_req_trans : 8;
        unsigned int dfx_qsp_rsp_bp : 1;
        unsigned int dfx_qsp_rsp_trans : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_H1QIC_IBQ_DFX_QSP_PORT_UNION;
#endif
#define SOC_H1QIC_IBQ_DFX_QSP_PORT_dfx_qsp_req_bp_START (0)
#define SOC_H1QIC_IBQ_DFX_QSP_PORT_dfx_qsp_req_bp_END (7)
#define SOC_H1QIC_IBQ_DFX_QSP_PORT_dfx_qsp_req_trans_START (8)
#define SOC_H1QIC_IBQ_DFX_QSP_PORT_dfx_qsp_req_trans_END (15)
#define SOC_H1QIC_IBQ_DFX_QSP_PORT_dfx_qsp_rsp_bp_START (16)
#define SOC_H1QIC_IBQ_DFX_QSP_PORT_dfx_qsp_rsp_bp_END (16)
#define SOC_H1QIC_IBQ_DFX_QSP_PORT_dfx_qsp_rsp_trans_START (17)
#define SOC_H1QIC_IBQ_DFX_QSP_PORT_dfx_qsp_rsp_trans_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ram_ecc_dis : 1;
        unsigned int reserved_0 : 3;
        unsigned int ram_ecc_merr_rsp : 1;
        unsigned int reserved_1 : 3;
        unsigned int ram_ecc_serr_intr_th : 4;
        unsigned int reserved_2 : 4;
        unsigned int ram_ecc_intr_dis : 2;
        unsigned int reserved_3 : 6;
        unsigned int ram_ecc_intr_mask : 2;
        unsigned int reserved_4 : 6;
    } reg;
} SOC_H1QIC_IBQ_RAM_ECC_CTRL_UNION;
#endif
#define SOC_H1QIC_IBQ_RAM_ECC_CTRL_ram_ecc_dis_START (0)
#define SOC_H1QIC_IBQ_RAM_ECC_CTRL_ram_ecc_dis_END (0)
#define SOC_H1QIC_IBQ_RAM_ECC_CTRL_ram_ecc_merr_rsp_START (4)
#define SOC_H1QIC_IBQ_RAM_ECC_CTRL_ram_ecc_merr_rsp_END (4)
#define SOC_H1QIC_IBQ_RAM_ECC_CTRL_ram_ecc_serr_intr_th_START (8)
#define SOC_H1QIC_IBQ_RAM_ECC_CTRL_ram_ecc_serr_intr_th_END (11)
#define SOC_H1QIC_IBQ_RAM_ECC_CTRL_ram_ecc_intr_dis_START (16)
#define SOC_H1QIC_IBQ_RAM_ECC_CTRL_ram_ecc_intr_dis_END (17)
#define SOC_H1QIC_IBQ_RAM_ECC_CTRL_ram_ecc_intr_mask_START (24)
#define SOC_H1QIC_IBQ_RAM_ECC_CTRL_ram_ecc_intr_mask_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ram_ecc_intr_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_H1QIC_IBQ_RAM_ECC_INTR_CLR_UNION;
#endif
#define SOC_H1QIC_IBQ_RAM_ECC_INTR_CLR_ram_ecc_intr_clr_START (0)
#define SOC_H1QIC_IBQ_RAM_ECC_INTR_CLR_ram_ecc_intr_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ram_ecc_serr_addr : 16;
        unsigned int ram_ecc_serr_cnt : 4;
        unsigned int reserved : 12;
    } reg;
} SOC_H1QIC_IBQ_RAM_ECC_INFO0_UNION;
#endif
#define SOC_H1QIC_IBQ_RAM_ECC_INFO0_ram_ecc_serr_addr_START (0)
#define SOC_H1QIC_IBQ_RAM_ECC_INFO0_ram_ecc_serr_addr_END (15)
#define SOC_H1QIC_IBQ_RAM_ECC_INFO0_ram_ecc_serr_cnt_START (16)
#define SOC_H1QIC_IBQ_RAM_ECC_INFO0_ram_ecc_serr_cnt_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ram_ecc_merr_addr : 16;
        unsigned int ram_ecc_merr_cnt : 4;
        unsigned int reserved : 12;
    } reg;
} SOC_H1QIC_IBQ_RAM_ECC_INFO1_UNION;
#endif
#define SOC_H1QIC_IBQ_RAM_ECC_INFO1_ram_ecc_merr_addr_START (0)
#define SOC_H1QIC_IBQ_RAM_ECC_INFO1_ram_ecc_merr_addr_END (15)
#define SOC_H1QIC_IBQ_RAM_ECC_INFO1_ram_ecc_merr_cnt_START (16)
#define SOC_H1QIC_IBQ_RAM_ECC_INFO1_ram_ecc_merr_cnt_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int decerr_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_H1QIC_IBQ_DECERR_CLR_UNION;
#endif
#define SOC_H1QIC_IBQ_DECERR_CLR_decerr_clr_START (0)
#define SOC_H1QIC_IBQ_DECERR_CLR_decerr_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int decerr_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_H1QIC_IBQ_DECERR_STATUS_UNION;
#endif
#define SOC_H1QIC_IBQ_DECERR_STATUS_decerr_status_START (0)
#define SOC_H1QIC_IBQ_DECERR_STATUS_decerr_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int decerr_addr0 : 32;
    } reg;
} SOC_H1QIC_IBQ_DECERR_ADDR0_UNION;
#endif
#define SOC_H1QIC_IBQ_DECERR_ADDR0_decerr_addr0_START (0)
#define SOC_H1QIC_IBQ_DECERR_ADDR0_decerr_addr0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int decerr_addr1 : 32;
    } reg;
} SOC_H1QIC_IBQ_DECERR_ADDR1_UNION;
#endif
#define SOC_H1QIC_IBQ_DECERR_ADDR1_decerr_addr1_START (0)
#define SOC_H1QIC_IBQ_DECERR_ADDR1_decerr_addr1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_tag : 8;
        unsigned int reserved_0: 8;
        unsigned int version : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_H1QIC_WA_RTL_VER_UNION;
#endif
#define SOC_H1QIC_WA_RTL_VER_rtl_tag_START (0)
#define SOC_H1QIC_WA_RTL_VER_rtl_tag_END (7)
#define SOC_H1QIC_WA_RTL_VER_version_START (16)
#define SOC_H1QIC_WA_RTL_VER_version_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info0 : 32;
    } reg;
} SOC_H1QIC_WA_RTL_INFO_UNION;
#endif
#define SOC_H1QIC_WA_RTL_INFO_rtl_info0_START (0)
#define SOC_H1QIC_WA_RTL_INFO_rtl_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info1 : 32;
    } reg;
} SOC_H1QIC_WA_RTL_INF1_UNION;
#endif
#define SOC_H1QIC_WA_RTL_INF1_rtl_info1_START (0)
#define SOC_H1QIC_WA_RTL_INF1_rtl_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info2 : 32;
    } reg;
} SOC_H1QIC_WA_RTL_INF2_UNION;
#endif
#define SOC_H1QIC_WA_RTL_INF2_rtl_info2_START (0)
#define SOC_H1QIC_WA_RTL_INF2_rtl_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ckg_ext_ena : 1;
        unsigned int ckg_byp_wa : 1;
        unsigned int ckg_byp_cfg : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_H1QIC_WA_CKG_CTRL_UNION;
#endif
#define SOC_H1QIC_WA_CKG_CTRL_ckg_ext_ena_START (0)
#define SOC_H1QIC_WA_CKG_CTRL_ckg_ext_ena_END (0)
#define SOC_H1QIC_WA_CKG_CTRL_ckg_byp_wa_START (1)
#define SOC_H1QIC_WA_CKG_CTRL_ckg_byp_wa_END (1)
#define SOC_H1QIC_WA_CKG_CTRL_ckg_byp_cfg_START (2)
#define SOC_H1QIC_WA_CKG_CTRL_ckg_byp_cfg_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int icfg_sfw_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_H1QIC_WA_NML_CTR_UNION;
#endif
#define SOC_H1QIC_WA_NML_CTR_icfg_sfw_en_START (0)
#define SOC_H1QIC_WA_NML_CTR_icfg_sfw_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_rx_bp : 8;
        unsigned int dfx_rx_empty : 8;
        unsigned int dfx_cmdp_busy : 8;
        unsigned int dfx_dwr_busy : 8;
    } reg;
} SOC_H1QIC_WA_DFX_ST0_UNION;
#endif
#define SOC_H1QIC_WA_DFX_ST0_dfx_rx_bp_START (0)
#define SOC_H1QIC_WA_DFX_ST0_dfx_rx_bp_END (7)
#define SOC_H1QIC_WA_DFX_ST0_dfx_rx_empty_START (8)
#define SOC_H1QIC_WA_DFX_ST0_dfx_rx_empty_END (15)
#define SOC_H1QIC_WA_DFX_ST0_dfx_cmdp_busy_START (16)
#define SOC_H1QIC_WA_DFX_ST0_dfx_cmdp_busy_END (23)
#define SOC_H1QIC_WA_DFX_ST0_dfx_dwr_busy_START (24)
#define SOC_H1QIC_WA_DFX_ST0_dfx_dwr_busy_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_sfwfifo_st : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_H1QIC_WA_DFX_ST1_UNION;
#endif
#define SOC_H1QIC_WA_DFX_ST1_dfx_sfwfifo_st_START (0)
#define SOC_H1QIC_WA_DFX_ST1_dfx_sfwfifo_st_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_tag : 8;
        unsigned int reserved_0: 8;
        unsigned int version : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_H1QIC_RT_RTL_VER_UNION;
#endif
#define SOC_H1QIC_RT_RTL_VER_rtl_tag_START (0)
#define SOC_H1QIC_RT_RTL_VER_rtl_tag_END (7)
#define SOC_H1QIC_RT_RTL_VER_version_START (16)
#define SOC_H1QIC_RT_RTL_VER_version_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info0 : 32;
    } reg;
} SOC_H1QIC_RT_RTL_INFO_UNION;
#endif
#define SOC_H1QIC_RT_RTL_INFO_rtl_info0_START (0)
#define SOC_H1QIC_RT_RTL_INFO_rtl_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info1 : 32;
    } reg;
} SOC_H1QIC_RT_RTL_INF1_UNION;
#endif
#define SOC_H1QIC_RT_RTL_INF1_rtl_info1_START (0)
#define SOC_H1QIC_RT_RTL_INF1_rtl_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info2 : 32;
    } reg;
} SOC_H1QIC_RT_RTL_INF2_UNION;
#endif
#define SOC_H1QIC_RT_RTL_INF2_rtl_info2_START (0)
#define SOC_H1QIC_RT_RTL_INF2_rtl_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ckg_ext_ena : 1;
        unsigned int ckg_byp_rt : 1;
        unsigned int ckg_byp_inp : 1;
        unsigned int ckg_byp_oup : 1;
        unsigned int ckg_byp_cfc : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_H1QIC_RT_CKG_CTRL_UNION;
#endif
#define SOC_H1QIC_RT_CKG_CTRL_ckg_ext_ena_START (0)
#define SOC_H1QIC_RT_CKG_CTRL_ckg_ext_ena_END (0)
#define SOC_H1QIC_RT_CKG_CTRL_ckg_byp_rt_START (1)
#define SOC_H1QIC_RT_CKG_CTRL_ckg_byp_rt_END (1)
#define SOC_H1QIC_RT_CKG_CTRL_ckg_byp_inp_START (2)
#define SOC_H1QIC_RT_CKG_CTRL_ckg_byp_inp_END (2)
#define SOC_H1QIC_RT_CKG_CTRL_ckg_byp_oup_START (3)
#define SOC_H1QIC_RT_CKG_CTRL_ckg_byp_oup_END (3)
#define SOC_H1QIC_RT_CKG_CTRL_ckg_byp_cfc_START (4)
#define SOC_H1QIC_RT_CKG_CTRL_ckg_byp_cfc_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rsv_rw : 32;
    } reg;
} SOC_H1QIC_RT_RSV_RW_UNION;
#endif
#define SOC_H1QIC_RT_RSV_RW_rsv_rw_START (0)
#define SOC_H1QIC_RT_RSV_RW_rsv_rw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sta_lmtr_bw : 8;
        unsigned int sta_lmtr_sat : 8;
        unsigned int reserved_0 : 8;
        unsigned int sta_lmtr_lp : 2;
        unsigned int reserved_1 : 5;
        unsigned int sta_lmtr_en : 1;
    } reg;
} SOC_H1QIC_RT_QOS_OUP_LMTR_UNION;
#endif
#define SOC_H1QIC_RT_QOS_OUP_LMTR_sta_lmtr_bw_START (0)
#define SOC_H1QIC_RT_QOS_OUP_LMTR_sta_lmtr_bw_END (7)
#define SOC_H1QIC_RT_QOS_OUP_LMTR_sta_lmtr_sat_START (8)
#define SOC_H1QIC_RT_QOS_OUP_LMTR_sta_lmtr_sat_END (15)
#define SOC_H1QIC_RT_QOS_OUP_LMTR_sta_lmtr_lp_START (24)
#define SOC_H1QIC_RT_QOS_OUP_LMTR_sta_lmtr_lp_END (25)
#define SOC_H1QIC_RT_QOS_OUP_LMTR_sta_lmtr_en_START (31)
#define SOC_H1QIC_RT_QOS_OUP_LMTR_sta_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int inp_sfw_en : 16;
        unsigned int oup_sfw_en : 16;
    } reg;
} SOC_H1QIC_RT_SFW_CTRL_UNION;
#endif
#define SOC_H1QIC_RT_SFW_CTRL_inp_sfw_en_START (0)
#define SOC_H1QIC_RT_SFW_CTRL_inp_sfw_en_END (15)
#define SOC_H1QIC_RT_SFW_CTRL_oup_sfw_en_START (16)
#define SOC_H1QIC_RT_SFW_CTRL_oup_sfw_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_busy : 32;
    } reg;
} SOC_H1QIC_RT_DFX_BUSY_UNION;
#endif
#define SOC_H1QIC_RT_DFX_BUSY_dfx_busy_START (0)
#define SOC_H1QIC_RT_DFX_BUSY_dfx_busy_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int emp_cmd_msk : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_H1QIC_EM_INT_MSK_UNION;
#endif
#define SOC_H1QIC_EM_INT_MSK_emp_cmd_msk_START (0)
#define SOC_H1QIC_EM_INT_MSK_emp_cmd_msk_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int emp_cmd_int_vld : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_H1QIC_EM_INT_ST_UNION;
#endif
#define SOC_H1QIC_EM_INT_ST_emp_cmd_int_vld_START (0)
#define SOC_H1QIC_EM_INT_ST_emp_cmd_int_vld_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int emp_cmd_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_H1QIC_EM_INT_CLR_UNION;
#endif
#define SOC_H1QIC_EM_INT_CLR_emp_cmd_clr_START (0)
#define SOC_H1QIC_EM_INT_CLR_emp_cmd_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ckg_ext_ena : 1;
        unsigned int ckg_byp : 1;
        unsigned int ckg_byp_cfg : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_H1QIC_EM_CKG_CTRL_UNION;
#endif
#define SOC_H1QIC_EM_CKG_CTRL_ckg_ext_ena_START (0)
#define SOC_H1QIC_EM_CKG_CTRL_ckg_ext_ena_END (0)
#define SOC_H1QIC_EM_CKG_CTRL_ckg_byp_START (1)
#define SOC_H1QIC_EM_CKG_CTRL_ckg_byp_END (1)
#define SOC_H1QIC_EM_CKG_CTRL_ckg_byp_cfg_START (2)
#define SOC_H1QIC_EM_CKG_CTRL_ckg_byp_cfg_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int emp_cmd_opc : 4;
        unsigned int reserved_0 : 3;
        unsigned int emp_cmd_burst : 1;
        unsigned int emp_cmd_excl : 1;
        unsigned int reserved_1 : 3;
        unsigned int emp_cmd_status : 4;
        unsigned int reserved_2 : 4;
        unsigned int emp_cmd_tsize : 12;
    } reg;
} SOC_H1QIC_EM_ERR_LOG0_UNION;
#endif
#define SOC_H1QIC_EM_ERR_LOG0_emp_cmd_opc_START (0)
#define SOC_H1QIC_EM_ERR_LOG0_emp_cmd_opc_END (3)
#define SOC_H1QIC_EM_ERR_LOG0_emp_cmd_burst_START (7)
#define SOC_H1QIC_EM_ERR_LOG0_emp_cmd_burst_END (7)
#define SOC_H1QIC_EM_ERR_LOG0_emp_cmd_excl_START (8)
#define SOC_H1QIC_EM_ERR_LOG0_emp_cmd_excl_END (8)
#define SOC_H1QIC_EM_ERR_LOG0_emp_cmd_status_START (12)
#define SOC_H1QIC_EM_ERR_LOG0_emp_cmd_status_END (15)
#define SOC_H1QIC_EM_ERR_LOG0_emp_cmd_tsize_START (20)
#define SOC_H1QIC_EM_ERR_LOG0_emp_cmd_tsize_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int emp_cmd_mmidx : 8;
        unsigned int emp_cmd_tbid : 8;
        unsigned int emp_cmd_ibid : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_H1QIC_EM_ERR_LOG1_UNION;
#endif
#define SOC_H1QIC_EM_ERR_LOG1_emp_cmd_mmidx_START (0)
#define SOC_H1QIC_EM_ERR_LOG1_emp_cmd_mmidx_END (7)
#define SOC_H1QIC_EM_ERR_LOG1_emp_cmd_tbid_START (8)
#define SOC_H1QIC_EM_ERR_LOG1_emp_cmd_tbid_END (15)
#define SOC_H1QIC_EM_ERR_LOG1_emp_cmd_ibid_START (16)
#define SOC_H1QIC_EM_ERR_LOG1_emp_cmd_ibid_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int emp_cmd_tid : 32;
    } reg;
} SOC_H1QIC_EM_ERR_LOG2_UNION;
#endif
#define SOC_H1QIC_EM_ERR_LOG2_emp_cmd_tid_START (0)
#define SOC_H1QIC_EM_ERR_LOG2_emp_cmd_tid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int emp_cmd_addr_l : 32;
    } reg;
} SOC_H1QIC_EM_ERR_LOG3_UNION;
#endif
#define SOC_H1QIC_EM_ERR_LOG3_emp_cmd_addr_l_START (0)
#define SOC_H1QIC_EM_ERR_LOG3_emp_cmd_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int emp_cmd_addr_h : 32;
    } reg;
} SOC_H1QIC_EM_ERR_LOG4_UNION;
#endif
#define SOC_H1QIC_EM_ERR_LOG4_emp_cmd_addr_h_START (0)
#define SOC_H1QIC_EM_ERR_LOG4_emp_cmd_addr_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int emp_cmd_user_l : 32;
    } reg;
} SOC_H1QIC_EM_ERR_LOG5_UNION;
#endif
#define SOC_H1QIC_EM_ERR_LOG5_emp_cmd_user_l_START (0)
#define SOC_H1QIC_EM_ERR_LOG5_emp_cmd_user_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int emp_cmd_user_h : 32;
    } reg;
} SOC_H1QIC_EM_ERR_LOG6_UNION;
#endif
#define SOC_H1QIC_EM_ERR_LOG6_emp_cmd_user_h_START (0)
#define SOC_H1QIC_EM_ERR_LOG6_emp_cmd_user_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int emp_cmd_sf_l : 32;
    } reg;
} SOC_H1QIC_EM_ERR_LOG7_UNION;
#endif
#define SOC_H1QIC_EM_ERR_LOG7_emp_cmd_sf_l_START (0)
#define SOC_H1QIC_EM_ERR_LOG7_emp_cmd_sf_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_H1QIC_PKTC_MON_RTL_VER_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int filter_hit_intr_mask : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_H1QIC_PKTC_MON_INTR_MASK_UNION;
#endif
#define SOC_H1QIC_PKTC_MON_INTR_MASK_filter_hit_intr_mask_START (0)
#define SOC_H1QIC_PKTC_MON_INTR_MASK_filter_hit_intr_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int filter_hit_intr_stat : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_H1QIC_PKTC_MON_INTR_STAT_UNION;
#endif
#define SOC_H1QIC_PKTC_MON_INTR_STAT_filter_hit_intr_stat_START (0)
#define SOC_H1QIC_PKTC_MON_INTR_STAT_filter_hit_intr_stat_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int filter_hit_intr_org_stat : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_H1QIC_PKTC_MON_INTR_ORG_STAT_UNION;
#endif
#define SOC_H1QIC_PKTC_MON_INTR_ORG_STAT_filter_hit_intr_org_stat_START (0)
#define SOC_H1QIC_PKTC_MON_INTR_ORG_STAT_filter_hit_intr_org_stat_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int filter_hit_intr_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_H1QIC_PKTC_MON_INTR_CLR_UNION;
#endif
#define SOC_H1QIC_PKTC_MON_INTR_CLR_filter_hit_intr_clr_START (0)
#define SOC_H1QIC_PKTC_MON_INTR_CLR_filter_hit_intr_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int filter_addr_org_l : 32;
    } reg;
} SOC_H1QIC_PKTC_MON_FILTER_ADDR_ORG_L_UNION;
#endif
#define SOC_H1QIC_PKTC_MON_FILTER_ADDR_ORG_L_filter_addr_org_l_START (0)
#define SOC_H1QIC_PKTC_MON_FILTER_ADDR_ORG_L_filter_addr_org_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int filter_addr_org_h : 32;
    } reg;
} SOC_H1QIC_PKTC_MON_FILTER_ADDR_ORG_H_UNION;
#endif
#define SOC_H1QIC_PKTC_MON_FILTER_ADDR_ORG_H_filter_addr_org_h_START (0)
#define SOC_H1QIC_PKTC_MON_FILTER_ADDR_ORG_H_filter_addr_org_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int filter_addr_end_l : 32;
    } reg;
} SOC_H1QIC_PKTC_MON_FILTER_ADDR_END_L_UNION;
#endif
#define SOC_H1QIC_PKTC_MON_FILTER_ADDR_END_L_filter_addr_end_l_START (0)
#define SOC_H1QIC_PKTC_MON_FILTER_ADDR_END_L_filter_addr_end_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int filter_addr_end_h : 32;
    } reg;
} SOC_H1QIC_PKTC_MON_FILTER_ADDR_END_H_UNION;
#endif
#define SOC_H1QIC_PKTC_MON_FILTER_ADDR_END_H_filter_addr_end_h_START (0)
#define SOC_H1QIC_PKTC_MON_FILTER_ADDR_END_H_filter_addr_end_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int filter_opc : 16;
        unsigned int filter_opc_mask : 16;
    } reg;
} SOC_H1QIC_PKTC_MON_FILTER_OPC_UNION;
#endif
#define SOC_H1QIC_PKTC_MON_FILTER_OPC_filter_opc_START (0)
#define SOC_H1QIC_PKTC_MON_FILTER_OPC_filter_opc_END (15)
#define SOC_H1QIC_PKTC_MON_FILTER_OPC_filter_opc_mask_START (16)
#define SOC_H1QIC_PKTC_MON_FILTER_OPC_filter_opc_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int filter_did : 16;
        unsigned int filter_did_mask : 16;
    } reg;
} SOC_H1QIC_PKTC_MON_FILTER_DSTID_UNION;
#endif
#define SOC_H1QIC_PKTC_MON_FILTER_DSTID_filter_did_START (0)
#define SOC_H1QIC_PKTC_MON_FILTER_DSTID_filter_did_END (15)
#define SOC_H1QIC_PKTC_MON_FILTER_DSTID_filter_did_mask_START (16)
#define SOC_H1QIC_PKTC_MON_FILTER_DSTID_filter_did_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int filter_sid : 16;
        unsigned int filter_sid_mask : 16;
    } reg;
} SOC_H1QIC_PKTC_MON_FILTER_SRCID_UNION;
#endif
#define SOC_H1QIC_PKTC_MON_FILTER_SRCID_filter_sid_START (0)
#define SOC_H1QIC_PKTC_MON_FILTER_SRCID_filter_sid_END (15)
#define SOC_H1QIC_PKTC_MON_FILTER_SRCID_filter_sid_mask_START (16)
#define SOC_H1QIC_PKTC_MON_FILTER_SRCID_filter_sid_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int filter_mmidx : 16;
        unsigned int filter_mmidx_mask : 16;
    } reg;
} SOC_H1QIC_PKTC_MON_FILTER_MMIDX_UNION;
#endif
#define SOC_H1QIC_PKTC_MON_FILTER_MMIDX_filter_mmidx_START (0)
#define SOC_H1QIC_PKTC_MON_FILTER_MMIDX_filter_mmidx_END (15)
#define SOC_H1QIC_PKTC_MON_FILTER_MMIDX_filter_mmidx_mask_START (16)
#define SOC_H1QIC_PKTC_MON_FILTER_MMIDX_filter_mmidx_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int filter_sf : 16;
        unsigned int filter_sf_mask : 16;
    } reg;
} SOC_H1QIC_PKTC_MON_FILTER_SF_UNION;
#endif
#define SOC_H1QIC_PKTC_MON_FILTER_SF_filter_sf_START (0)
#define SOC_H1QIC_PKTC_MON_FILTER_SF_filter_sf_END (15)
#define SOC_H1QIC_PKTC_MON_FILTER_SF_filter_sf_mask_START (16)
#define SOC_H1QIC_PKTC_MON_FILTER_SF_filter_sf_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int filter_user_l : 32;
    } reg;
} SOC_H1QIC_PKTC_MON_FILTER_USER_L_UNION;
#endif
#define SOC_H1QIC_PKTC_MON_FILTER_USER_L_filter_user_l_START (0)
#define SOC_H1QIC_PKTC_MON_FILTER_USER_L_filter_user_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int filter_user_h : 32;
    } reg;
} SOC_H1QIC_PKTC_MON_FILTER_USER_H_UNION;
#endif
#define SOC_H1QIC_PKTC_MON_FILTER_USER_H_filter_user_h_START (0)
#define SOC_H1QIC_PKTC_MON_FILTER_USER_H_filter_user_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int filter_user_l_mask : 32;
    } reg;
} SOC_H1QIC_PKTC_MON_FILTER_USER_L_MASK_UNION;
#endif
#define SOC_H1QIC_PKTC_MON_FILTER_USER_L_MASK_filter_user_l_mask_START (0)
#define SOC_H1QIC_PKTC_MON_FILTER_USER_L_MASK_filter_user_l_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int filter_user_h_mask : 32;
    } reg;
} SOC_H1QIC_PKTC_MON_FILTER_USER_H_MASK_UNION;
#endif
#define SOC_H1QIC_PKTC_MON_FILTER_USER_H_MASK_filter_user_h_mask_START (0)
#define SOC_H1QIC_PKTC_MON_FILTER_USER_H_MASK_filter_user_h_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int filter_qos : 32;
    } reg;
} SOC_H1QIC_PKTC_MON_FILTER_QOS_UNION;
#endif
#define SOC_H1QIC_PKTC_MON_FILTER_QOS_filter_qos_START (0)
#define SOC_H1QIC_PKTC_MON_FILTER_QOS_filter_qos_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int filter_en : 8;
        unsigned int filter_reverse : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_H1QIC_PKTC_MON_FILTERMIX_UNION;
#endif
#define SOC_H1QIC_PKTC_MON_FILTERMIX_filter_en_START (0)
#define SOC_H1QIC_PKTC_MON_FILTERMIX_filter_en_END (7)
#define SOC_H1QIC_PKTC_MON_FILTERMIX_filter_reverse_START (8)
#define SOC_H1QIC_PKTC_MON_FILTERMIX_filter_reverse_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mon_filter_hit : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_H1QIC_PKTC_MON_FILTER_HIT_UNION;
#endif
#define SOC_H1QIC_PKTC_MON_FILTER_HIT_mon_filter_hit_START (0)
#define SOC_H1QIC_PKTC_MON_FILTER_HIT_mon_filter_hit_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mon_fifo_sfw_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_H1QIC_PKTC_MON_FIFO_SFW_EN_UNION;
#endif
#define SOC_H1QIC_PKTC_MON_FIFO_SFW_EN_mon_fifo_sfw_en_START (0)
#define SOC_H1QIC_PKTC_MON_FIFO_SFW_EN_mon_fifo_sfw_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mon_ckg_ext_ena : 1;
        unsigned int mon_ckg_byp_cfg : 1;
        unsigned int mon_ckg_byp_mon : 1;
        unsigned int mon_ckg_byp_unpkt : 1;
        unsigned int mon_ckg_byp_pkt : 1;
        unsigned int mon_ckg_byp_fifo : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_H1QIC_PKTC_MON_CLK_CTRL_UNION;
#endif
#define SOC_H1QIC_PKTC_MON_CLK_CTRL_mon_ckg_ext_ena_START (0)
#define SOC_H1QIC_PKTC_MON_CLK_CTRL_mon_ckg_ext_ena_END (0)
#define SOC_H1QIC_PKTC_MON_CLK_CTRL_mon_ckg_byp_cfg_START (1)
#define SOC_H1QIC_PKTC_MON_CLK_CTRL_mon_ckg_byp_cfg_END (1)
#define SOC_H1QIC_PKTC_MON_CLK_CTRL_mon_ckg_byp_mon_START (2)
#define SOC_H1QIC_PKTC_MON_CLK_CTRL_mon_ckg_byp_mon_END (2)
#define SOC_H1QIC_PKTC_MON_CLK_CTRL_mon_ckg_byp_unpkt_START (3)
#define SOC_H1QIC_PKTC_MON_CLK_CTRL_mon_ckg_byp_unpkt_END (3)
#define SOC_H1QIC_PKTC_MON_CLK_CTRL_mon_ckg_byp_pkt_START (4)
#define SOC_H1QIC_PKTC_MON_CLK_CTRL_mon_ckg_byp_pkt_END (4)
#define SOC_H1QIC_PKTC_MON_CLK_CTRL_mon_ckg_byp_fifo_START (5)
#define SOC_H1QIC_PKTC_MON_CLK_CTRL_mon_ckg_byp_fifo_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mon_en : 32;
    } reg;
} SOC_H1QIC_PKTC_MON_EN_UNION;
#endif
#define SOC_H1QIC_PKTC_MON_EN_mon_en_START (0)
#define SOC_H1QIC_PKTC_MON_EN_mon_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int col_err_pld : 1;
        unsigned int wreq_col_without_data : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_H1QIC_PKTC_MON_COL_CFG_UNION;
#endif
#define SOC_H1QIC_PKTC_MON_COL_CFG_col_err_pld_START (0)
#define SOC_H1QIC_PKTC_MON_COL_CFG_col_err_pld_END (0)
#define SOC_H1QIC_PKTC_MON_COL_CFG_wreq_col_without_data_START (1)
#define SOC_H1QIC_PKTC_MON_COL_CFG_wreq_col_without_data_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 32;
    } reg;
} SOC_H1QIC_PKTC_COL_RTL_VER_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int col_atbid : 32;
    } reg;
} SOC_H1QIC_PKTC_COL_ATBID_UNION;
#endif
#define SOC_H1QIC_PKTC_COL_ATBID_col_atbid_START (0)
#define SOC_H1QIC_PKTC_COL_ATBID_col_atbid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int col_arb_qos_0 : 32;
    } reg;
} SOC_H1QIC_PKTC_COL_ARB_QOS_0_UNION;
#endif
#define SOC_H1QIC_PKTC_COL_ARB_QOS_0_col_arb_qos_0_START (0)
#define SOC_H1QIC_PKTC_COL_ARB_QOS_0_col_arb_qos_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int col_arb_qos_1 : 32;
    } reg;
} SOC_H1QIC_PKTC_COL_ARB_QOS_1_UNION;
#endif
#define SOC_H1QIC_PKTC_COL_ARB_QOS_1_col_arb_qos_1_START (0)
#define SOC_H1QIC_PKTC_COL_ARB_QOS_1_col_arb_qos_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int col_nodeid_0 : 32;
    } reg;
} SOC_H1QIC_PKTC_COL_ARB_NODEID_0_UNION;
#endif
#define SOC_H1QIC_PKTC_COL_ARB_NODEID_0_col_nodeid_0_START (0)
#define SOC_H1QIC_PKTC_COL_ARB_NODEID_0_col_nodeid_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int col_nodeid_1 : 32;
    } reg;
} SOC_H1QIC_PKTC_COL_ARB_NODEID_1_UNION;
#endif
#define SOC_H1QIC_PKTC_COL_ARB_NODEID_1_col_nodeid_1_START (0)
#define SOC_H1QIC_PKTC_COL_ARB_NODEID_1_col_nodeid_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int col_nodeid_2 : 32;
    } reg;
} SOC_H1QIC_PKTC_COL_ARB_NODEID_2_UNION;
#endif
#define SOC_H1QIC_PKTC_COL_ARB_NODEID_2_col_nodeid_2_START (0)
#define SOC_H1QIC_PKTC_COL_ARB_NODEID_2_col_nodeid_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sync_pkt_ins_interval : 32;
    } reg;
} SOC_H1QIC_PKTC_COL_SYNC_PKT_INTERVAL_UNION;
#endif
#define SOC_H1QIC_PKTC_COL_SYNC_PKT_INTERVAL_sync_pkt_ins_interval_START (0)
#define SOC_H1QIC_PKTC_COL_SYNC_PKT_INTERVAL_sync_pkt_ins_interval_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int col_ckg_ext_ena : 1;
        unsigned int col_ckg_byp_col : 1;
        unsigned int col_ckg_byp_cfg : 1;
        unsigned int col_ckg_byp_pkt : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_H1QIC_PKTC_CLK_CTRL_UNION;
#endif
#define SOC_H1QIC_PKTC_CLK_CTRL_col_ckg_ext_ena_START (0)
#define SOC_H1QIC_PKTC_CLK_CTRL_col_ckg_ext_ena_END (0)
#define SOC_H1QIC_PKTC_CLK_CTRL_col_ckg_byp_col_START (1)
#define SOC_H1QIC_PKTC_CLK_CTRL_col_ckg_byp_col_END (1)
#define SOC_H1QIC_PKTC_CLK_CTRL_col_ckg_byp_cfg_START (2)
#define SOC_H1QIC_PKTC_CLK_CTRL_col_ckg_byp_cfg_END (2)
#define SOC_H1QIC_PKTC_CLK_CTRL_col_ckg_byp_pkt_START (3)
#define SOC_H1QIC_PKTC_CLK_CTRL_col_ckg_byp_pkt_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_tag : 8;
        unsigned int reserved_0: 8;
        unsigned int version : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_H1QIC_TBX_RTL_VER_UNION;
#endif
#define SOC_H1QIC_TBX_RTL_VER_rtl_tag_START (0)
#define SOC_H1QIC_TBX_RTL_VER_rtl_tag_END (7)
#define SOC_H1QIC_TBX_RTL_VER_version_START (16)
#define SOC_H1QIC_TBX_RTL_VER_version_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info0 : 32;
    } reg;
} SOC_H1QIC_TBX_RTL_INFO_UNION;
#endif
#define SOC_H1QIC_TBX_RTL_INFO_rtl_info0_START (0)
#define SOC_H1QIC_TBX_RTL_INFO_rtl_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info1 : 32;
    } reg;
} SOC_H1QIC_TBX_RTL_INF1_UNION;
#endif
#define SOC_H1QIC_TBX_RTL_INF1_rtl_info1_START (0)
#define SOC_H1QIC_TBX_RTL_INF1_rtl_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info2 : 32;
    } reg;
} SOC_H1QIC_TBX_RTL_INF2_UNION;
#endif
#define SOC_H1QIC_TBX_RTL_INF2_rtl_info2_START (0)
#define SOC_H1QIC_TBX_RTL_INF2_rtl_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int arcache_cfg : 4;
        unsigned int awcache_cfg : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_H1QIC_TBX_NML_CTR_UNION;
#endif
#define SOC_H1QIC_TBX_NML_CTR_arcache_cfg_START (0)
#define SOC_H1QIC_TBX_NML_CTR_arcache_cfg_END (3)
#define SOC_H1QIC_TBX_NML_CTR_awcache_cfg_START (4)
#define SOC_H1QIC_TBX_NML_CTR_awcache_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ckg_ext_ena : 1;
        unsigned int ckg_byp_inf : 1;
        unsigned int ckg_byp_req_ar : 1;
        unsigned int ckg_byp_req_aw : 1;
        unsigned int ckg_byp_rsp_r : 1;
        unsigned int ckg_byp_rsp_b : 1;
        unsigned int ckg_byp_cfg : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_H1QIC_TBX_CKG_CTRL_UNION;
#endif
#define SOC_H1QIC_TBX_CKG_CTRL_ckg_ext_ena_START (0)
#define SOC_H1QIC_TBX_CKG_CTRL_ckg_ext_ena_END (0)
#define SOC_H1QIC_TBX_CKG_CTRL_ckg_byp_inf_START (1)
#define SOC_H1QIC_TBX_CKG_CTRL_ckg_byp_inf_END (1)
#define SOC_H1QIC_TBX_CKG_CTRL_ckg_byp_req_ar_START (2)
#define SOC_H1QIC_TBX_CKG_CTRL_ckg_byp_req_ar_END (2)
#define SOC_H1QIC_TBX_CKG_CTRL_ckg_byp_req_aw_START (3)
#define SOC_H1QIC_TBX_CKG_CTRL_ckg_byp_req_aw_END (3)
#define SOC_H1QIC_TBX_CKG_CTRL_ckg_byp_rsp_r_START (4)
#define SOC_H1QIC_TBX_CKG_CTRL_ckg_byp_rsp_r_END (4)
#define SOC_H1QIC_TBX_CKG_CTRL_ckg_byp_rsp_b_START (5)
#define SOC_H1QIC_TBX_CKG_CTRL_ckg_byp_rsp_b_END (5)
#define SOC_H1QIC_TBX_CKG_CTRL_ckg_byp_cfg_START (6)
#define SOC_H1QIC_TBX_CKG_CTRL_ckg_byp_cfg_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_tag : 8;
        unsigned int reserved_0: 8;
        unsigned int version : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_H1QIC_TBH_RTL_VER_UNION;
#endif
#define SOC_H1QIC_TBH_RTL_VER_rtl_tag_START (0)
#define SOC_H1QIC_TBH_RTL_VER_rtl_tag_END (7)
#define SOC_H1QIC_TBH_RTL_VER_version_START (16)
#define SOC_H1QIC_TBH_RTL_VER_version_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info0 : 32;
    } reg;
} SOC_H1QIC_TBH_RTL_INFO_UNION;
#endif
#define SOC_H1QIC_TBH_RTL_INFO_rtl_info0_START (0)
#define SOC_H1QIC_TBH_RTL_INFO_rtl_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info1 : 32;
    } reg;
} SOC_H1QIC_TBH_RTL_INF1_UNION;
#endif
#define SOC_H1QIC_TBH_RTL_INF1_rtl_info1_START (0)
#define SOC_H1QIC_TBH_RTL_INF1_rtl_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info2 : 32;
    } reg;
} SOC_H1QIC_TBH_RTL_INF2_UNION;
#endif
#define SOC_H1QIC_TBH_RTL_INF2_rtl_info2_START (0)
#define SOC_H1QIC_TBH_RTL_INF2_rtl_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ckg_ext_ena : 1;
        unsigned int ckg_byp : 1;
        unsigned int ckg_byp_cfg : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_H1QIC_TBH_CKG_CTRL_UNION;
#endif
#define SOC_H1QIC_TBH_CKG_CTRL_ckg_ext_ena_START (0)
#define SOC_H1QIC_TBH_CKG_CTRL_ckg_ext_ena_END (0)
#define SOC_H1QIC_TBH_CKG_CTRL_ckg_byp_START (1)
#define SOC_H1QIC_TBH_CKG_CTRL_ckg_byp_END (1)
#define SOC_H1QIC_TBH_CKG_CTRL_ckg_byp_cfg_START (2)
#define SOC_H1QIC_TBH_CKG_CTRL_ckg_byp_cfg_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_tag : 8;
        unsigned int reserved_0: 8;
        unsigned int version : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_H1QIC_TBP_RTL_VER_UNION;
#endif
#define SOC_H1QIC_TBP_RTL_VER_rtl_tag_START (0)
#define SOC_H1QIC_TBP_RTL_VER_rtl_tag_END (7)
#define SOC_H1QIC_TBP_RTL_VER_version_START (16)
#define SOC_H1QIC_TBP_RTL_VER_version_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info0 : 32;
    } reg;
} SOC_H1QIC_TBP_RTL_INFO_UNION;
#endif
#define SOC_H1QIC_TBP_RTL_INFO_rtl_info0_START (0)
#define SOC_H1QIC_TBP_RTL_INFO_rtl_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info1 : 32;
    } reg;
} SOC_H1QIC_TBP_RTL_INF1_UNION;
#endif
#define SOC_H1QIC_TBP_RTL_INF1_rtl_info1_START (0)
#define SOC_H1QIC_TBP_RTL_INF1_rtl_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info2 : 32;
    } reg;
} SOC_H1QIC_TBP_RTL_INF2_UNION;
#endif
#define SOC_H1QIC_TBP_RTL_INF2_rtl_info2_START (0)
#define SOC_H1QIC_TBP_RTL_INF2_rtl_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ckg_ext_ena : 1;
        unsigned int ckg_byp : 1;
        unsigned int ckg_byp_cfg : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_H1QIC_TBP_CKG_CTRL_UNION;
#endif
#define SOC_H1QIC_TBP_CKG_CTRL_ckg_ext_ena_START (0)
#define SOC_H1QIC_TBP_CKG_CTRL_ckg_ext_ena_END (0)
#define SOC_H1QIC_TBP_CKG_CTRL_ckg_byp_START (1)
#define SOC_H1QIC_TBP_CKG_CTRL_ckg_byp_END (1)
#define SOC_H1QIC_TBP_CKG_CTRL_ckg_byp_cfg_START (2)
#define SOC_H1QIC_TBP_CKG_CTRL_ckg_byp_cfg_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_tag : 8;
        unsigned int reserved_0: 8;
        unsigned int version : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_H1QIC_TBQ_RTL_VER_UNION;
#endif
#define SOC_H1QIC_TBQ_RTL_VER_rtl_tag_START (0)
#define SOC_H1QIC_TBQ_RTL_VER_rtl_tag_END (7)
#define SOC_H1QIC_TBQ_RTL_VER_version_START (16)
#define SOC_H1QIC_TBQ_RTL_VER_version_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info0 : 32;
    } reg;
} SOC_H1QIC_TBQ_RTL_INFO_UNION;
#endif
#define SOC_H1QIC_TBQ_RTL_INFO_rtl_info0_START (0)
#define SOC_H1QIC_TBQ_RTL_INFO_rtl_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info1 : 32;
    } reg;
} SOC_H1QIC_TBQ_RTL_INF1_UNION;
#endif
#define SOC_H1QIC_TBQ_RTL_INF1_rtl_info1_START (0)
#define SOC_H1QIC_TBQ_RTL_INF1_rtl_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rtl_info2 : 32;
    } reg;
} SOC_H1QIC_TBQ_RTL_INF2_UNION;
#endif
#define SOC_H1QIC_TBQ_RTL_INF2_rtl_info2_START (0)
#define SOC_H1QIC_TBQ_RTL_INF2_rtl_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ckg_ext_ena : 1;
        unsigned int ckg_byp_tbq : 1;
        unsigned int ckg_byp_req : 1;
        unsigned int ckg_byp_rsp : 1;
        unsigned int ckg_byp_ct : 1;
        unsigned int ckg_byp_qos : 1;
        unsigned int ckg_byp_cfc : 1;
        unsigned int ckg_byp_tes : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_H1QIC_TBQ_CKG_CTRL_UNION;
#endif
#define SOC_H1QIC_TBQ_CKG_CTRL_ckg_ext_ena_START (0)
#define SOC_H1QIC_TBQ_CKG_CTRL_ckg_ext_ena_END (0)
#define SOC_H1QIC_TBQ_CKG_CTRL_ckg_byp_tbq_START (1)
#define SOC_H1QIC_TBQ_CKG_CTRL_ckg_byp_tbq_END (1)
#define SOC_H1QIC_TBQ_CKG_CTRL_ckg_byp_req_START (2)
#define SOC_H1QIC_TBQ_CKG_CTRL_ckg_byp_req_END (2)
#define SOC_H1QIC_TBQ_CKG_CTRL_ckg_byp_rsp_START (3)
#define SOC_H1QIC_TBQ_CKG_CTRL_ckg_byp_rsp_END (3)
#define SOC_H1QIC_TBQ_CKG_CTRL_ckg_byp_ct_START (4)
#define SOC_H1QIC_TBQ_CKG_CTRL_ckg_byp_ct_END (4)
#define SOC_H1QIC_TBQ_CKG_CTRL_ckg_byp_qos_START (5)
#define SOC_H1QIC_TBQ_CKG_CTRL_ckg_byp_qos_END (5)
#define SOC_H1QIC_TBQ_CKG_CTRL_ckg_byp_cfc_START (6)
#define SOC_H1QIC_TBQ_CKG_CTRL_ckg_byp_cfc_END (6)
#define SOC_H1QIC_TBQ_CKG_CTRL_ckg_byp_tes_START (7)
#define SOC_H1QIC_TBQ_CKG_CTRL_ckg_byp_tes_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rsv_rw : 32;
    } reg;
} SOC_H1QIC_TBQ_RSV_RW_UNION;
#endif
#define SOC_H1QIC_TBQ_RSV_RW_rsv_rw_START (0)
#define SOC_H1QIC_TBQ_RSV_RW_rsv_rw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sta_lmtr_bw : 8;
        unsigned int sta_lmtr_sat : 8;
        unsigned int reserved_0 : 8;
        unsigned int sta_lmtr_lp : 2;
        unsigned int reserved_1 : 5;
        unsigned int sta_lmtr_en : 1;
    } reg;
} SOC_H1QIC_TBQ_QOS_STA_LMTR_UNION;
#endif
#define SOC_H1QIC_TBQ_QOS_STA_LMTR_sta_lmtr_bw_START (0)
#define SOC_H1QIC_TBQ_QOS_STA_LMTR_sta_lmtr_bw_END (7)
#define SOC_H1QIC_TBQ_QOS_STA_LMTR_sta_lmtr_sat_START (8)
#define SOC_H1QIC_TBQ_QOS_STA_LMTR_sta_lmtr_sat_END (15)
#define SOC_H1QIC_TBQ_QOS_STA_LMTR_sta_lmtr_lp_START (24)
#define SOC_H1QIC_TBQ_QOS_STA_LMTR_sta_lmtr_lp_END (25)
#define SOC_H1QIC_TBQ_QOS_STA_LMTR_sta_lmtr_en_START (31)
#define SOC_H1QIC_TBQ_QOS_STA_LMTR_sta_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sta_vc_lmtr_bw : 8;
        unsigned int sta_vc_lmtr_sat : 8;
        unsigned int reserved_0 : 8;
        unsigned int sta_vc_lmtr_lp : 2;
        unsigned int reserved_1 : 5;
        unsigned int sta_vc_lmtr_en : 1;
    } reg;
} SOC_H1QIC_TBQ_QOS_STA_VC_LMTR_UNION;
#endif
#define SOC_H1QIC_TBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_bw_START (0)
#define SOC_H1QIC_TBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_bw_END (7)
#define SOC_H1QIC_TBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_sat_START (8)
#define SOC_H1QIC_TBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_sat_END (15)
#define SOC_H1QIC_TBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_lp_START (24)
#define SOC_H1QIC_TBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_lp_END (25)
#define SOC_H1QIC_TBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_en_START (31)
#define SOC_H1QIC_TBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dyn_vc_lmtr_bw : 8;
        unsigned int dyn_vc_lmtr_sat : 8;
        unsigned int reserved_0 : 8;
        unsigned int dyn_vc_lmtr_lp : 2;
        unsigned int reserved_1 : 5;
        unsigned int dyn_vc_lmtr_en : 1;
    } reg;
} SOC_H1QIC_TBQ_QOS_DYN_VC_LMTR_UNION;
#endif
#define SOC_H1QIC_TBQ_QOS_DYN_VC_LMTR_dyn_vc_lmtr_bw_START (0)
#define SOC_H1QIC_TBQ_QOS_DYN_VC_LMTR_dyn_vc_lmtr_bw_END (7)
#define SOC_H1QIC_TBQ_QOS_DYN_VC_LMTR_dyn_vc_lmtr_sat_START (8)
#define SOC_H1QIC_TBQ_QOS_DYN_VC_LMTR_dyn_vc_lmtr_sat_END (15)
#define SOC_H1QIC_TBQ_QOS_DYN_VC_LMTR_dyn_vc_lmtr_lp_START (24)
#define SOC_H1QIC_TBQ_QOS_DYN_VC_LMTR_dyn_vc_lmtr_lp_END (25)
#define SOC_H1QIC_TBQ_QOS_DYN_VC_LMTR_dyn_vc_lmtr_en_START (31)
#define SOC_H1QIC_TBQ_QOS_DYN_VC_LMTR_dyn_vc_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sta_ost_wl : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_H1QIC_TBQ_QOS_STA_OST_UNION;
#endif
#define SOC_H1QIC_TBQ_QOS_STA_OST_sta_ost_wl_START (0)
#define SOC_H1QIC_TBQ_QOS_STA_OST_sta_ost_wl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sta_vc_ost_wl : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_H1QIC_TBQ_QOS_STA_VC_OST_UNION;
#endif
#define SOC_H1QIC_TBQ_QOS_STA_VC_OST_sta_vc_ost_wl_START (0)
#define SOC_H1QIC_TBQ_QOS_STA_VC_OST_sta_vc_ost_wl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dyn_vc_ost_wl : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_H1QIC_TBQ_QOS_DYN_VC_OST_UNION;
#endif
#define SOC_H1QIC_TBQ_QOS_DYN_VC_OST_dyn_vc_ost_wl_START (0)
#define SOC_H1QIC_TBQ_QOS_DYN_VC_OST_dyn_vc_ost_wl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vc_total_ost_wl : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_H1QIC_TBQ_QOS_TOTAL_VC_OST_UNION;
#endif
#define SOC_H1QIC_TBQ_QOS_TOTAL_VC_OST_vc_total_ost_wl_START (0)
#define SOC_H1QIC_TBQ_QOS_TOTAL_VC_OST_vc_total_ost_wl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_stat_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int tes_stat_mode : 2;
        unsigned int reserved_1 : 2;
        unsigned int tes_stat_cnt_mode : 24;
    } reg;
} SOC_H1QIC_TBQ_TES_CFG0_UNION;
#endif
#define SOC_H1QIC_TBQ_TES_CFG0_tes_stat_en_START (0)
#define SOC_H1QIC_TBQ_TES_CFG0_tes_stat_en_END (0)
#define SOC_H1QIC_TBQ_TES_CFG0_tes_stat_mode_START (4)
#define SOC_H1QIC_TBQ_TES_CFG0_tes_stat_mode_END (5)
#define SOC_H1QIC_TBQ_TES_CFG0_tes_stat_cnt_mode_START (8)
#define SOC_H1QIC_TBQ_TES_CFG0_tes_stat_cnt_mode_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_latcy_mode : 1;
        unsigned int reserved_0 : 3;
        unsigned int tes_latcy_prescaler : 10;
        unsigned int reserved_1 : 2;
        unsigned int tes_pfm_tes_align_mode : 1;
        unsigned int tes_pfm_tes_cmd_type : 1;
        unsigned int reserved_2 : 14;
    } reg;
} SOC_H1QIC_TBQ_TES_CFG1_UNION;
#endif
#define SOC_H1QIC_TBQ_TES_CFG1_tes_latcy_mode_START (0)
#define SOC_H1QIC_TBQ_TES_CFG1_tes_latcy_mode_END (0)
#define SOC_H1QIC_TBQ_TES_CFG1_tes_latcy_prescaler_START (4)
#define SOC_H1QIC_TBQ_TES_CFG1_tes_latcy_prescaler_END (13)
#define SOC_H1QIC_TBQ_TES_CFG1_tes_pfm_tes_align_mode_START (16)
#define SOC_H1QIC_TBQ_TES_CFG1_tes_pfm_tes_align_mode_END (16)
#define SOC_H1QIC_TBQ_TES_CFG1_tes_pfm_tes_cmd_type_START (17)
#define SOC_H1QIC_TBQ_TES_CFG1_tes_pfm_tes_cmd_type_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_addr_s0 : 32;
    } reg;
} SOC_H1QIC_TBQ_TES_FILTER0_UNION;
#endif
#define SOC_H1QIC_TBQ_TES_FILTER0_tes_addr_s0_START (0)
#define SOC_H1QIC_TBQ_TES_FILTER0_tes_addr_s0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_addr_s1 : 32;
    } reg;
} SOC_H1QIC_TBQ_TES_FILTER1_UNION;
#endif
#define SOC_H1QIC_TBQ_TES_FILTER1_tes_addr_s1_START (0)
#define SOC_H1QIC_TBQ_TES_FILTER1_tes_addr_s1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_addr_e0 : 32;
    } reg;
} SOC_H1QIC_TBQ_TES_FILTER2_UNION;
#endif
#define SOC_H1QIC_TBQ_TES_FILTER2_tes_addr_e0_START (0)
#define SOC_H1QIC_TBQ_TES_FILTER2_tes_addr_e0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_addr_e1 : 32;
    } reg;
} SOC_H1QIC_TBQ_TES_FILTER3_UNION;
#endif
#define SOC_H1QIC_TBQ_TES_FILTER3_tes_addr_e1_START (0)
#define SOC_H1QIC_TBQ_TES_FILTER3_tes_addr_e1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_user0 : 32;
    } reg;
} SOC_H1QIC_TBQ_TES_FILTER4_0_UNION;
#endif
#define SOC_H1QIC_TBQ_TES_FILTER4_0_tes_user0_START (0)
#define SOC_H1QIC_TBQ_TES_FILTER4_0_tes_user0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_user1 : 32;
    } reg;
} SOC_H1QIC_TBQ_TES_FILTER4_1_UNION;
#endif
#define SOC_H1QIC_TBQ_TES_FILTER4_1_tes_user1_START (0)
#define SOC_H1QIC_TBQ_TES_FILTER4_1_tes_user1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_user2 : 32;
    } reg;
} SOC_H1QIC_TBQ_TES_FILTER4_2_UNION;
#endif
#define SOC_H1QIC_TBQ_TES_FILTER4_2_tes_user2_START (0)
#define SOC_H1QIC_TBQ_TES_FILTER4_2_tes_user2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_user3 : 32;
    } reg;
} SOC_H1QIC_TBQ_TES_FILTER4_3_UNION;
#endif
#define SOC_H1QIC_TBQ_TES_FILTER4_3_tes_user3_START (0)
#define SOC_H1QIC_TBQ_TES_FILTER4_3_tes_user3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_user_msk0 : 32;
    } reg;
} SOC_H1QIC_TBQ_TES_FILTER5_0_UNION;
#endif
#define SOC_H1QIC_TBQ_TES_FILTER5_0_tes_user_msk0_START (0)
#define SOC_H1QIC_TBQ_TES_FILTER5_0_tes_user_msk0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_user_msk1 : 32;
    } reg;
} SOC_H1QIC_TBQ_TES_FILTER5_1_UNION;
#endif
#define SOC_H1QIC_TBQ_TES_FILTER5_1_tes_user_msk1_START (0)
#define SOC_H1QIC_TBQ_TES_FILTER5_1_tes_user_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_user_msk2 : 32;
    } reg;
} SOC_H1QIC_TBQ_TES_FILTER5_2_UNION;
#endif
#define SOC_H1QIC_TBQ_TES_FILTER5_2_tes_user_msk2_START (0)
#define SOC_H1QIC_TBQ_TES_FILTER5_2_tes_user_msk2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_user_msk3 : 32;
    } reg;
} SOC_H1QIC_TBQ_TES_FILTER5_3_UNION;
#endif
#define SOC_H1QIC_TBQ_TES_FILTER5_3_tes_user_msk3_START (0)
#define SOC_H1QIC_TBQ_TES_FILTER5_3_tes_user_msk3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_exclid : 8;
        unsigned int tes_exclid_msk : 8;
        unsigned int tes_sf : 8;
        unsigned int tes_sf_msk : 8;
    } reg;
} SOC_H1QIC_TBQ_TES_FILTER6_UNION;
#endif
#define SOC_H1QIC_TBQ_TES_FILTER6_tes_exclid_START (0)
#define SOC_H1QIC_TBQ_TES_FILTER6_tes_exclid_END (7)
#define SOC_H1QIC_TBQ_TES_FILTER6_tes_exclid_msk_START (8)
#define SOC_H1QIC_TBQ_TES_FILTER6_tes_exclid_msk_END (15)
#define SOC_H1QIC_TBQ_TES_FILTER6_tes_sf_START (16)
#define SOC_H1QIC_TBQ_TES_FILTER6_tes_sf_END (23)
#define SOC_H1QIC_TBQ_TES_FILTER6_tes_sf_msk_START (24)
#define SOC_H1QIC_TBQ_TES_FILTER6_tes_sf_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_qos : 8;
        unsigned int tes_tid : 8;
        unsigned int tes_tid_msk : 8;
        unsigned int tes_lck : 4;
        unsigned int tes_lck_msk : 4;
    } reg;
} SOC_H1QIC_TBQ_TES_FILTER7_UNION;
#endif
#define SOC_H1QIC_TBQ_TES_FILTER7_tes_qos_START (0)
#define SOC_H1QIC_TBQ_TES_FILTER7_tes_qos_END (7)
#define SOC_H1QIC_TBQ_TES_FILTER7_tes_tid_START (8)
#define SOC_H1QIC_TBQ_TES_FILTER7_tes_tid_END (15)
#define SOC_H1QIC_TBQ_TES_FILTER7_tes_tid_msk_START (16)
#define SOC_H1QIC_TBQ_TES_FILTER7_tes_tid_msk_END (23)
#define SOC_H1QIC_TBQ_TES_FILTER7_tes_lck_START (24)
#define SOC_H1QIC_TBQ_TES_FILTER7_tes_lck_END (27)
#define SOC_H1QIC_TBQ_TES_FILTER7_tes_lck_msk_START (28)
#define SOC_H1QIC_TBQ_TES_FILTER7_tes_lck_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_tsize_min : 16;
        unsigned int tes_tsize_max : 16;
    } reg;
} SOC_H1QIC_TBQ_TES_FILTER8_UNION;
#endif
#define SOC_H1QIC_TBQ_TES_FILTER8_tes_tsize_min_START (0)
#define SOC_H1QIC_TBQ_TES_FILTER8_tes_tsize_min_END (15)
#define SOC_H1QIC_TBQ_TES_FILTER8_tes_tsize_max_START (16)
#define SOC_H1QIC_TBQ_TES_FILTER8_tes_tsize_max_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_srcid : 8;
        unsigned int tes_srcid_msk : 8;
        unsigned int tes_vcnum : 4;
        unsigned int tes_vcnum_msk : 4;
        unsigned int tes_burst : 1;
        unsigned int tes_burst_msk : 1;
        unsigned int tes_wr : 1;
        unsigned int tes_wr_msk : 1;
        unsigned int tes_rd : 1;
        unsigned int tes_rd_msk : 1;
        unsigned int tes_splt_cmd : 1;
        unsigned int tes_splt_cmd_msk : 1;
    } reg;
} SOC_H1QIC_TBQ_TES_FILTER9_UNION;
#endif
#define SOC_H1QIC_TBQ_TES_FILTER9_tes_srcid_START (0)
#define SOC_H1QIC_TBQ_TES_FILTER9_tes_srcid_END (7)
#define SOC_H1QIC_TBQ_TES_FILTER9_tes_srcid_msk_START (8)
#define SOC_H1QIC_TBQ_TES_FILTER9_tes_srcid_msk_END (15)
#define SOC_H1QIC_TBQ_TES_FILTER9_tes_vcnum_START (16)
#define SOC_H1QIC_TBQ_TES_FILTER9_tes_vcnum_END (19)
#define SOC_H1QIC_TBQ_TES_FILTER9_tes_vcnum_msk_START (20)
#define SOC_H1QIC_TBQ_TES_FILTER9_tes_vcnum_msk_END (23)
#define SOC_H1QIC_TBQ_TES_FILTER9_tes_burst_START (24)
#define SOC_H1QIC_TBQ_TES_FILTER9_tes_burst_END (24)
#define SOC_H1QIC_TBQ_TES_FILTER9_tes_burst_msk_START (25)
#define SOC_H1QIC_TBQ_TES_FILTER9_tes_burst_msk_END (25)
#define SOC_H1QIC_TBQ_TES_FILTER9_tes_wr_START (26)
#define SOC_H1QIC_TBQ_TES_FILTER9_tes_wr_END (26)
#define SOC_H1QIC_TBQ_TES_FILTER9_tes_wr_msk_START (27)
#define SOC_H1QIC_TBQ_TES_FILTER9_tes_wr_msk_END (27)
#define SOC_H1QIC_TBQ_TES_FILTER9_tes_rd_START (28)
#define SOC_H1QIC_TBQ_TES_FILTER9_tes_rd_END (28)
#define SOC_H1QIC_TBQ_TES_FILTER9_tes_rd_msk_START (29)
#define SOC_H1QIC_TBQ_TES_FILTER9_tes_rd_msk_END (29)
#define SOC_H1QIC_TBQ_TES_FILTER9_tes_splt_cmd_START (30)
#define SOC_H1QIC_TBQ_TES_FILTER9_tes_splt_cmd_END (30)
#define SOC_H1QIC_TBQ_TES_FILTER9_tes_splt_cmd_msk_START (31)
#define SOC_H1QIC_TBQ_TES_FILTER9_tes_splt_cmd_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_stat_cnt_int : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_H1QIC_TBQ_TES_INT_STAUS_UNION;
#endif
#define SOC_H1QIC_TBQ_TES_INT_STAUS_tes_stat_cnt_int_START (0)
#define SOC_H1QIC_TBQ_TES_INT_STAUS_tes_stat_cnt_int_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_stat_cnt_int_clr : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_H1QIC_TBQ_TES_INT_CLR_UNION;
#endif
#define SOC_H1QIC_TBQ_TES_INT_CLR_tes_stat_cnt_int_clr_START (0)
#define SOC_H1QIC_TBQ_TES_INT_CLR_tes_stat_cnt_int_clr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_stat_cnt : 32;
    } reg;
} SOC_H1QIC_TBQ_TES_CNT_UNION;
#endif
#define SOC_H1QIC_TBQ_TES_CNT_tes_stat_cnt_START (0)
#define SOC_H1QIC_TBQ_TES_CNT_tes_stat_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tes_stat_cnt_int_th : 32;
    } reg;
} SOC_H1QIC_TBQ_TES_INT_CFG_UNION;
#endif
#define SOC_H1QIC_TBQ_TES_INT_CFG_tes_stat_cnt_int_th_START (0)
#define SOC_H1QIC_TBQ_TES_INT_CFG_tes_stat_cnt_int_th_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int parity_dis : 3;
        unsigned int reserved_0 : 1;
        unsigned int parity_intr_mask : 3;
        unsigned int reserved_1 : 25;
    } reg;
} SOC_H1QIC_TBQ_PARITY_INTR_CTRL_UNION;
#endif
#define SOC_H1QIC_TBQ_PARITY_INTR_CTRL_parity_dis_START (0)
#define SOC_H1QIC_TBQ_PARITY_INTR_CTRL_parity_dis_END (2)
#define SOC_H1QIC_TBQ_PARITY_INTR_CTRL_parity_intr_mask_START (4)
#define SOC_H1QIC_TBQ_PARITY_INTR_CTRL_parity_intr_mask_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int parity_intr_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_H1QIC_TBQ_PARITY_INTR_CLR_UNION;
#endif
#define SOC_H1QIC_TBQ_PARITY_INTR_CLR_parity_intr_clr_START (0)
#define SOC_H1QIC_TBQ_PARITY_INTR_CLR_parity_intr_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int parity_mask_status : 4;
        unsigned int reserved_0 : 4;
        unsigned int parity_org_status : 4;
        unsigned int reserved_1 : 20;
    } reg;
} SOC_H1QIC_TBQ_PARITY_INTR_INFO0_UNION;
#endif
#define SOC_H1QIC_TBQ_PARITY_INTR_INFO0_parity_mask_status_START (0)
#define SOC_H1QIC_TBQ_PARITY_INTR_INFO0_parity_mask_status_END (3)
#define SOC_H1QIC_TBQ_PARITY_INTR_INFO0_parity_org_status_START (8)
#define SOC_H1QIC_TBQ_PARITY_INTR_INFO0_parity_org_status_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int parity_cmd_inject : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_H1QIC_TBQ_PARITY_CMD_INJECT_UNION;
#endif
#define SOC_H1QIC_TBQ_PARITY_CMD_INJECT_parity_cmd_inject_START (0)
#define SOC_H1QIC_TBQ_PARITY_CMD_INJECT_parity_cmd_inject_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int parity_data_inject : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_H1QIC_TBQ_PARITY_DATA_INJECT_UNION;
#endif
#define SOC_H1QIC_TBQ_PARITY_DATA_INJECT_parity_data_inject_START (0)
#define SOC_H1QIC_TBQ_PARITY_DATA_INJECT_parity_data_inject_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_busy : 32;
    } reg;
} SOC_H1QIC_TBQ_DFX_BUSY_UNION;
#endif
#define SOC_H1QIC_TBQ_DFX_BUSY_dfx_busy_START (0)
#define SOC_H1QIC_TBQ_DFX_BUSY_dfx_busy_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_ostd_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_H1QIC_TBQ_DFX_OT_UNION;
#endif
#define SOC_H1QIC_TBQ_DFX_OT_dfx_ostd_cnt_START (0)
#define SOC_H1QIC_TBQ_DFX_OT_dfx_ostd_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_qtp_req_bp : 8;
        unsigned int dfx_qtp_req_trans : 8;
        unsigned int dfx_qtp_rsp_bp : 1;
        unsigned int dfx_qtp_rsp_trans : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_H1QIC_TBQ_DFX_QTP_PORT_UNION;
#endif
#define SOC_H1QIC_TBQ_DFX_QTP_PORT_dfx_qtp_req_bp_START (0)
#define SOC_H1QIC_TBQ_DFX_QTP_PORT_dfx_qtp_req_bp_END (7)
#define SOC_H1QIC_TBQ_DFX_QTP_PORT_dfx_qtp_req_trans_START (8)
#define SOC_H1QIC_TBQ_DFX_QTP_PORT_dfx_qtp_req_trans_END (15)
#define SOC_H1QIC_TBQ_DFX_QTP_PORT_dfx_qtp_rsp_bp_START (16)
#define SOC_H1QIC_TBQ_DFX_QTP_PORT_dfx_qtp_rsp_bp_END (16)
#define SOC_H1QIC_TBQ_DFX_QTP_PORT_dfx_qtp_rsp_trans_START (17)
#define SOC_H1QIC_TBQ_DFX_QTP_PORT_dfx_qtp_rsp_trans_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfx_qsp_req_bp : 8;
        unsigned int dfx_qsp_req_trans : 8;
        unsigned int dfx_qsp_rsp_bp : 1;
        unsigned int dfx_qsp_rsp_trans : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_H1QIC_TBQ_DFX_QSP_PORT_UNION;
#endif
#define SOC_H1QIC_TBQ_DFX_QSP_PORT_dfx_qsp_req_bp_START (0)
#define SOC_H1QIC_TBQ_DFX_QSP_PORT_dfx_qsp_req_bp_END (7)
#define SOC_H1QIC_TBQ_DFX_QSP_PORT_dfx_qsp_req_trans_START (8)
#define SOC_H1QIC_TBQ_DFX_QSP_PORT_dfx_qsp_req_trans_END (15)
#define SOC_H1QIC_TBQ_DFX_QSP_PORT_dfx_qsp_rsp_bp_START (16)
#define SOC_H1QIC_TBQ_DFX_QSP_PORT_dfx_qsp_rsp_bp_END (16)
#define SOC_H1QIC_TBQ_DFX_QSP_PORT_dfx_qsp_rsp_trans_START (17)
#define SOC_H1QIC_TBQ_DFX_QSP_PORT_dfx_qsp_rsp_trans_END (17)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
