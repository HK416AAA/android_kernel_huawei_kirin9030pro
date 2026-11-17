#ifndef __SOC_QIC_GPUDATABUS_INTERFACE_H__
#define __SOC_QIC_GPUDATABUS_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QIC_GPUDATABUS_IBX_RTL_VER_ADDR(base) ((base) + (0x0000UL))
#define SOC_QIC_GPUDATABUS_IBX_RTL_INFO_ADDR(base) ((base) + (0x0004UL))
#define SOC_QIC_GPUDATABUS_IBX_RTL_INF1_ADDR(base) ((base) + (0x0008UL))
#define SOC_QIC_GPUDATABUS_IBX_RTL_INF2_ADDR(base) ((base) + (0x000CUL))
#define SOC_QIC_GPUDATABUS_IBX_NML_CTRL_ADDR(base) ((base) + (0x0010UL))
#define SOC_QIC_GPUDATABUS_IBX_CKG_CTRL_ADDR(base) ((base) + (0x0014UL))
#else
#define SOC_QIC_GPUDATABUS_IBX_RTL_VER_ADDR(base) ((base) + (0x0000))
#define SOC_QIC_GPUDATABUS_IBX_RTL_INFO_ADDR(base) ((base) + (0x0004))
#define SOC_QIC_GPUDATABUS_IBX_RTL_INF1_ADDR(base) ((base) + (0x0008))
#define SOC_QIC_GPUDATABUS_IBX_RTL_INF2_ADDR(base) ((base) + (0x000C))
#define SOC_QIC_GPUDATABUS_IBX_NML_CTRL_ADDR(base) ((base) + (0x0010))
#define SOC_QIC_GPUDATABUS_IBX_CKG_CTRL_ADDR(base) ((base) + (0x0014))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QIC_GPUDATABUS_IBP_RTL_VER_ADDR(base) ((base) + (0x0000UL))
#define SOC_QIC_GPUDATABUS_IBP_RTL_INFO_ADDR(base) ((base) + (0x0004UL))
#define SOC_QIC_GPUDATABUS_IBP_RTL_INF1_ADDR(base) ((base) + (0x0008UL))
#define SOC_QIC_GPUDATABUS_IBP_RTL_INF2_ADDR(base) ((base) + (0x000CUL))
#define SOC_QIC_GPUDATABUS_IBP_CKG_CTRL_ADDR(base) ((base) + (0x0014UL))
#else
#define SOC_QIC_GPUDATABUS_IBP_RTL_VER_ADDR(base) ((base) + (0x0000))
#define SOC_QIC_GPUDATABUS_IBP_RTL_INFO_ADDR(base) ((base) + (0x0004))
#define SOC_QIC_GPUDATABUS_IBP_RTL_INF1_ADDR(base) ((base) + (0x0008))
#define SOC_QIC_GPUDATABUS_IBP_RTL_INF2_ADDR(base) ((base) + (0x000C))
#define SOC_QIC_GPUDATABUS_IBP_CKG_CTRL_ADDR(base) ((base) + (0x0014))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QIC_GPUDATABUS_IBQ_RTL_VER_ADDR(base) ((base) + (0x0000UL))
#define SOC_QIC_GPUDATABUS_IBQ_RTL_INFO_ADDR(base) ((base) + (0x0004UL))
#define SOC_QIC_GPUDATABUS_IBQ_RTL_INF1_ADDR(base) ((base) + (0x0008UL))
#define SOC_QIC_GPUDATABUS_IBQ_RTL_INF2_ADDR(base) ((base) + (0x000CUL))
#define SOC_QIC_GPUDATABUS_IBQ_CKG_CTRL_ADDR(base) ((base) + (0x0100UL))
#define SOC_QIC_GPUDATABUS_IBQ_RAM_TMOD_ADDR(base) ((base) + (0x0104UL))
#define SOC_QIC_GPUDATABUS_IBQ_RSV_RW_ADDR(base) ((base) + (0x0108UL))
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_FIX_CTRL_ADDR(base) ((base) + (0x0200UL))
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP0_ADDR(base) ((base) + (0x0210UL))
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP1_ADDR(base) ((base) + (0x0214UL))
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_RGLR_CTRL_ADDR(base) ((base) + (0x0220UL))
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_RGLR_ADDR(base) ((base) + (0x0224UL))
#define SOC_QIC_GPUDATABUS_IBQ_QOS_STA_LMTR_ADDR(base) ((base) + (0x0230UL))
#define SOC_QIC_GPUDATABUS_IBQ_QOS_DYN_LMTR_ADDR(base) ((base) + (0x0234UL))
#define SOC_QIC_GPUDATABUS_IBQ_QOS_STA_VC_LMTR_ADDR(base) ((base) + (0x0240+0x4*vc_num))
#define SOC_QIC_GPUDATABUS_IBQ_QOS_STA_OST_ADDR(base) ((base) + (0x0280UL))
#define SOC_QIC_GPUDATABUS_IBQ_QOS_STA_VC_OST_ADDR(base) ((base) + (0x0290+0x10*vc_num))
#define SOC_QIC_GPUDATABUS_IBQ_QOS_DYN_VC_OST_ADDR(base) ((base) + (0x0294+0x10*vc_num))
#define SOC_QIC_GPUDATABUS_IBQ_QOS_TOTAL_VC_OST_ADDR(base) ((base) + (0x0298+0x10*vc_num))
#define SOC_QIC_GPUDATABUS_IBQ_TES_CFG0_ADDR(base) ((base) + (0x0400UL))
#define SOC_QIC_GPUDATABUS_IBQ_TES_CFG1_ADDR(base) ((base) + (0x0404UL))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER0_ADDR(base) ((base) + (0x0410UL))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER1_ADDR(base) ((base) + (0x0414UL))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER2_ADDR(base) ((base) + (0x0418UL))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER3_ADDR(base) ((base) + (0x041CUL))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER4_0_ADDR(base) ((base) + (0x0420UL))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER4_1_ADDR(base) ((base) + (0x0424UL))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER4_2_ADDR(base) ((base) + (0x0428UL))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER4_3_ADDR(base) ((base) + (0x042CUL))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER5_0_ADDR(base) ((base) + (0x0430UL))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER5_1_ADDR(base) ((base) + (0x0434UL))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER5_2_ADDR(base) ((base) + (0x0438UL))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER5_3_ADDR(base) ((base) + (0x043CUL))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER6_ADDR(base) ((base) + (0x0440UL))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER7_ADDR(base) ((base) + (0x0444UL))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER8_ADDR(base) ((base) + (0x0448UL))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER9_ADDR(base) ((base) + (0x044CUL))
#define SOC_QIC_GPUDATABUS_IBQ_TES_INT_STAUS_ADDR(base) ((base) + (0x0450UL))
#define SOC_QIC_GPUDATABUS_IBQ_TES_INT_CLR_ADDR(base) ((base) + (0x0454UL))
#define SOC_QIC_GPUDATABUS_IBQ_TES_CNT_ADDR(base) ((base) + (0x0480+0x4*tes_cnt))
#define SOC_QIC_GPUDATABUS_IBQ_TES_INT_CFG_ADDR(base) ((base) + (0x04C0+0x4*tes_cnt))
#define SOC_QIC_GPUDATABUS_IBQ_DFX_BUSY_ADDR(base) ((base) + (0x0700UL))
#define SOC_QIC_GPUDATABUS_IBQ_DFX_OST_ADDR(base) ((base) + (0x0704UL))
#define SOC_QIC_GPUDATABUS_IBQ_DFX_QTP_PORT_ADDR(base) ((base) + (0x0708UL))
#define SOC_QIC_GPUDATABUS_IBQ_DFX_QSP_PORT_ADDR(base) ((base) + (0x070CUL))
#else
#define SOC_QIC_GPUDATABUS_IBQ_RTL_VER_ADDR(base) ((base) + (0x0000))
#define SOC_QIC_GPUDATABUS_IBQ_RTL_INFO_ADDR(base) ((base) + (0x0004))
#define SOC_QIC_GPUDATABUS_IBQ_RTL_INF1_ADDR(base) ((base) + (0x0008))
#define SOC_QIC_GPUDATABUS_IBQ_RTL_INF2_ADDR(base) ((base) + (0x000C))
#define SOC_QIC_GPUDATABUS_IBQ_CKG_CTRL_ADDR(base) ((base) + (0x0100))
#define SOC_QIC_GPUDATABUS_IBQ_RAM_TMOD_ADDR(base) ((base) + (0x0104))
#define SOC_QIC_GPUDATABUS_IBQ_RSV_RW_ADDR(base) ((base) + (0x0108))
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_FIX_CTRL_ADDR(base) ((base) + (0x0200))
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP0_ADDR(base) ((base) + (0x0210))
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP1_ADDR(base) ((base) + (0x0214))
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_RGLR_CTRL_ADDR(base) ((base) + (0x0220))
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_RGLR_ADDR(base) ((base) + (0x0224))
#define SOC_QIC_GPUDATABUS_IBQ_QOS_STA_LMTR_ADDR(base) ((base) + (0x0230))
#define SOC_QIC_GPUDATABUS_IBQ_QOS_DYN_LMTR_ADDR(base) ((base) + (0x0234))
#define SOC_QIC_GPUDATABUS_IBQ_QOS_STA_VC_LMTR_ADDR(base) ((base) + (0x0240+0x4*vc_num))
#define SOC_QIC_GPUDATABUS_IBQ_QOS_STA_OST_ADDR(base) ((base) + (0x0280))
#define SOC_QIC_GPUDATABUS_IBQ_QOS_STA_VC_OST_ADDR(base) ((base) + (0x0290+0x10*vc_num))
#define SOC_QIC_GPUDATABUS_IBQ_QOS_DYN_VC_OST_ADDR(base) ((base) + (0x0294+0x10*vc_num))
#define SOC_QIC_GPUDATABUS_IBQ_QOS_TOTAL_VC_OST_ADDR(base) ((base) + (0x0298+0x10*vc_num))
#define SOC_QIC_GPUDATABUS_IBQ_TES_CFG0_ADDR(base) ((base) + (0x0400))
#define SOC_QIC_GPUDATABUS_IBQ_TES_CFG1_ADDR(base) ((base) + (0x0404))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER0_ADDR(base) ((base) + (0x0410))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER1_ADDR(base) ((base) + (0x0414))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER2_ADDR(base) ((base) + (0x0418))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER3_ADDR(base) ((base) + (0x041C))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER4_0_ADDR(base) ((base) + (0x0420))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER4_1_ADDR(base) ((base) + (0x0424))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER4_2_ADDR(base) ((base) + (0x0428))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER4_3_ADDR(base) ((base) + (0x042C))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER5_0_ADDR(base) ((base) + (0x0430))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER5_1_ADDR(base) ((base) + (0x0434))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER5_2_ADDR(base) ((base) + (0x0438))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER5_3_ADDR(base) ((base) + (0x043C))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER6_ADDR(base) ((base) + (0x0440))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER7_ADDR(base) ((base) + (0x0444))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER8_ADDR(base) ((base) + (0x0448))
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER9_ADDR(base) ((base) + (0x044C))
#define SOC_QIC_GPUDATABUS_IBQ_TES_INT_STAUS_ADDR(base) ((base) + (0x0450))
#define SOC_QIC_GPUDATABUS_IBQ_TES_INT_CLR_ADDR(base) ((base) + (0x0454))
#define SOC_QIC_GPUDATABUS_IBQ_TES_CNT_ADDR(base) ((base) + (0x0480+0x4*tes_cnt))
#define SOC_QIC_GPUDATABUS_IBQ_TES_INT_CFG_ADDR(base) ((base) + (0x04C0+0x4*tes_cnt))
#define SOC_QIC_GPUDATABUS_IBQ_DFX_BUSY_ADDR(base) ((base) + (0x0700))
#define SOC_QIC_GPUDATABUS_IBQ_DFX_OST_ADDR(base) ((base) + (0x0704))
#define SOC_QIC_GPUDATABUS_IBQ_DFX_QTP_PORT_ADDR(base) ((base) + (0x0708))
#define SOC_QIC_GPUDATABUS_IBQ_DFX_QSP_PORT_ADDR(base) ((base) + (0x070C))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QIC_GPUDATABUS_RT_RTL_VER_ADDR(base) ((base) + (0x0000UL))
#define SOC_QIC_GPUDATABUS_RT_RTL_INFO_ADDR(base) ((base) + (0x0004UL))
#define SOC_QIC_GPUDATABUS_RT_RTL_INF1_ADDR(base) ((base) + (0x0008UL))
#define SOC_QIC_GPUDATABUS_RT_RTL_INF2_ADDR(base) ((base) + (0x000CUL))
#define SOC_QIC_GPUDATABUS_RT_CKG_CTRL_ADDR(base) ((base) + (0x0100UL))
#define SOC_QIC_GPUDATABUS_RT_RSV_RW_ADDR(base) ((base) + (0x0104UL))
#define SOC_QIC_GPUDATABUS_RT_QOS_OUP_LMTR_ADDR(base) ((base) + (0x0200+0x4*oup_num))
#define SOC_QIC_GPUDATABUS_RT_SFW_CTRL_ADDR(base) ((base) + (0x0300UL))
#else
#define SOC_QIC_GPUDATABUS_RT_RTL_VER_ADDR(base) ((base) + (0x0000))
#define SOC_QIC_GPUDATABUS_RT_RTL_INFO_ADDR(base) ((base) + (0x0004))
#define SOC_QIC_GPUDATABUS_RT_RTL_INF1_ADDR(base) ((base) + (0x0008))
#define SOC_QIC_GPUDATABUS_RT_RTL_INF2_ADDR(base) ((base) + (0x000C))
#define SOC_QIC_GPUDATABUS_RT_CKG_CTRL_ADDR(base) ((base) + (0x0100))
#define SOC_QIC_GPUDATABUS_RT_RSV_RW_ADDR(base) ((base) + (0x0104))
#define SOC_QIC_GPUDATABUS_RT_QOS_OUP_LMTR_ADDR(base) ((base) + (0x0200+0x4*oup_num))
#define SOC_QIC_GPUDATABUS_RT_SFW_CTRL_ADDR(base) ((base) + (0x0300))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QIC_GPUDATABUS_TBX_RTL_VER_ADDR(base) ((base) + (0x0000UL))
#define SOC_QIC_GPUDATABUS_TBX_RTL_INFO_ADDR(base) ((base) + (0x0004UL))
#define SOC_QIC_GPUDATABUS_TBX_RTL_INF1_ADDR(base) ((base) + (0x0008UL))
#define SOC_QIC_GPUDATABUS_TBX_RTL_INF2_ADDR(base) ((base) + (0x000CUL))
#define SOC_QIC_GPUDATABUS_TBX_NML_CTR_ADDR(base) ((base) + (0x0010UL))
#define SOC_QIC_GPUDATABUS_TBX_CKG_CTRL_ADDR(base) ((base) + (0x0014UL))
#else
#define SOC_QIC_GPUDATABUS_TBX_RTL_VER_ADDR(base) ((base) + (0x0000))
#define SOC_QIC_GPUDATABUS_TBX_RTL_INFO_ADDR(base) ((base) + (0x0004))
#define SOC_QIC_GPUDATABUS_TBX_RTL_INF1_ADDR(base) ((base) + (0x0008))
#define SOC_QIC_GPUDATABUS_TBX_RTL_INF2_ADDR(base) ((base) + (0x000C))
#define SOC_QIC_GPUDATABUS_TBX_NML_CTR_ADDR(base) ((base) + (0x0010))
#define SOC_QIC_GPUDATABUS_TBX_CKG_CTRL_ADDR(base) ((base) + (0x0014))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_QIC_GPUDATABUS_TBQ_RTL_VER_ADDR(base) ((base) + (0x0000UL))
#define SOC_QIC_GPUDATABUS_TBQ_RTL_INFO_ADDR(base) ((base) + (0x0004UL))
#define SOC_QIC_GPUDATABUS_TBQ_RTL_INF1_ADDR(base) ((base) + (0x0008UL))
#define SOC_QIC_GPUDATABUS_TBQ_RTL_INF2_ADDR(base) ((base) + (0x000CUL))
#define SOC_QIC_GPUDATABUS_TBQ_CKG_CTRL_ADDR(base) ((base) + (0x0100UL))
#define SOC_QIC_GPUDATABUS_TBQ_RSV_RW_ADDR(base) ((base) + (0x0108UL))
#define SOC_QIC_GPUDATABUS_TBQ_QOS_STA_LMTR_ADDR(base) ((base) + (0x0230UL))
#define SOC_QIC_GPUDATABUS_TBQ_QOS_STA_VC_LMTR_ADDR(base) ((base) + (0x0240+0x4*vc_num))
#define SOC_QIC_GPUDATABUS_TBQ_QOS_DYN_VC_LMTR_ADDR(base) ((base) + (0x0260+0x4*vc_num))
#define SOC_QIC_GPUDATABUS_TBQ_QOS_STA_OST_ADDR(base) ((base) + (0x0280UL))
#define SOC_QIC_GPUDATABUS_TBQ_QOS_STA_VC_OST_ADDR(base) ((base) + (0x0290+0x10*vc_num))
#define SOC_QIC_GPUDATABUS_TBQ_QOS_DYN_VC_OST_ADDR(base) ((base) + (0x0294+0x10*vc_num))
#define SOC_QIC_GPUDATABUS_TBQ_QOS_TOTAL_VC_OST_ADDR(base) ((base) + (0x0298+0x10*vc_num))
#define SOC_QIC_GPUDATABUS_TBQ_TES_CFG0_ADDR(base) ((base) + (0x0400UL))
#define SOC_QIC_GPUDATABUS_TBQ_TES_CFG1_ADDR(base) ((base) + (0x0404UL))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER0_ADDR(base) ((base) + (0x0410UL))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER1_ADDR(base) ((base) + (0x0414UL))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER2_ADDR(base) ((base) + (0x0418UL))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER3_ADDR(base) ((base) + (0x041CUL))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER4_0_ADDR(base) ((base) + (0x0420UL))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER4_1_ADDR(base) ((base) + (0x0424UL))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER4_2_ADDR(base) ((base) + (0x0428UL))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER4_3_ADDR(base) ((base) + (0x042CUL))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER5_0_ADDR(base) ((base) + (0x0430UL))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER5_1_ADDR(base) ((base) + (0x0434UL))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER5_2_ADDR(base) ((base) + (0x0438UL))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER5_3_ADDR(base) ((base) + (0x043CUL))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER6_ADDR(base) ((base) + (0x0440UL))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER7_ADDR(base) ((base) + (0x0444UL))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER8_ADDR(base) ((base) + (0x0448UL))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER9_ADDR(base) ((base) + (0x044CUL))
#define SOC_QIC_GPUDATABUS_TBQ_TES_INT_STAUS_ADDR(base) ((base) + (0x0450UL))
#define SOC_QIC_GPUDATABUS_TBQ_TES_INT_CLR_ADDR(base) ((base) + (0x0454UL))
#define SOC_QIC_GPUDATABUS_TBQ_TES_CNT_ADDR(base) ((base) + (0x0480+0x4*tes_cnt))
#define SOC_QIC_GPUDATABUS_TBQ_TES_INT_CFG_ADDR(base) ((base) + (0x04C0+0x4*tes_cnt))
#define SOC_QIC_GPUDATABUS_TBQ_DFX_BUSY_ADDR(base) ((base) + (0x0700UL))
#define SOC_QIC_GPUDATABUS_TBQ_DFX_OT_ADDR(base) ((base) + (0x0704UL))
#define SOC_QIC_GPUDATABUS_TBQ_DFX_QTP_PORT_ADDR(base) ((base) + (0x0708UL))
#define SOC_QIC_GPUDATABUS_TBQ_DFX_QSP_PORT_ADDR(base) ((base) + (0x070CUL))
#else
#define SOC_QIC_GPUDATABUS_TBQ_RTL_VER_ADDR(base) ((base) + (0x0000))
#define SOC_QIC_GPUDATABUS_TBQ_RTL_INFO_ADDR(base) ((base) + (0x0004))
#define SOC_QIC_GPUDATABUS_TBQ_RTL_INF1_ADDR(base) ((base) + (0x0008))
#define SOC_QIC_GPUDATABUS_TBQ_RTL_INF2_ADDR(base) ((base) + (0x000C))
#define SOC_QIC_GPUDATABUS_TBQ_CKG_CTRL_ADDR(base) ((base) + (0x0100))
#define SOC_QIC_GPUDATABUS_TBQ_RSV_RW_ADDR(base) ((base) + (0x0108))
#define SOC_QIC_GPUDATABUS_TBQ_QOS_STA_LMTR_ADDR(base) ((base) + (0x0230))
#define SOC_QIC_GPUDATABUS_TBQ_QOS_STA_VC_LMTR_ADDR(base) ((base) + (0x0240+0x4*vc_num))
#define SOC_QIC_GPUDATABUS_TBQ_QOS_DYN_VC_LMTR_ADDR(base) ((base) + (0x0260+0x4*vc_num))
#define SOC_QIC_GPUDATABUS_TBQ_QOS_STA_OST_ADDR(base) ((base) + (0x0280))
#define SOC_QIC_GPUDATABUS_TBQ_QOS_STA_VC_OST_ADDR(base) ((base) + (0x0290+0x10*vc_num))
#define SOC_QIC_GPUDATABUS_TBQ_QOS_DYN_VC_OST_ADDR(base) ((base) + (0x0294+0x10*vc_num))
#define SOC_QIC_GPUDATABUS_TBQ_QOS_TOTAL_VC_OST_ADDR(base) ((base) + (0x0298+0x10*vc_num))
#define SOC_QIC_GPUDATABUS_TBQ_TES_CFG0_ADDR(base) ((base) + (0x0400))
#define SOC_QIC_GPUDATABUS_TBQ_TES_CFG1_ADDR(base) ((base) + (0x0404))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER0_ADDR(base) ((base) + (0x0410))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER1_ADDR(base) ((base) + (0x0414))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER2_ADDR(base) ((base) + (0x0418))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER3_ADDR(base) ((base) + (0x041C))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER4_0_ADDR(base) ((base) + (0x0420))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER4_1_ADDR(base) ((base) + (0x0424))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER4_2_ADDR(base) ((base) + (0x0428))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER4_3_ADDR(base) ((base) + (0x042C))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER5_0_ADDR(base) ((base) + (0x0430))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER5_1_ADDR(base) ((base) + (0x0434))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER5_2_ADDR(base) ((base) + (0x0438))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER5_3_ADDR(base) ((base) + (0x043C))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER6_ADDR(base) ((base) + (0x0440))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER7_ADDR(base) ((base) + (0x0444))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER8_ADDR(base) ((base) + (0x0448))
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER9_ADDR(base) ((base) + (0x044C))
#define SOC_QIC_GPUDATABUS_TBQ_TES_INT_STAUS_ADDR(base) ((base) + (0x0450))
#define SOC_QIC_GPUDATABUS_TBQ_TES_INT_CLR_ADDR(base) ((base) + (0x0454))
#define SOC_QIC_GPUDATABUS_TBQ_TES_CNT_ADDR(base) ((base) + (0x0480+0x4*tes_cnt))
#define SOC_QIC_GPUDATABUS_TBQ_TES_INT_CFG_ADDR(base) ((base) + (0x04C0+0x4*tes_cnt))
#define SOC_QIC_GPUDATABUS_TBQ_DFX_BUSY_ADDR(base) ((base) + (0x0700))
#define SOC_QIC_GPUDATABUS_TBQ_DFX_OT_ADDR(base) ((base) + (0x0704))
#define SOC_QIC_GPUDATABUS_TBQ_DFX_QTP_PORT_ADDR(base) ((base) + (0x0708))
#define SOC_QIC_GPUDATABUS_TBQ_DFX_QSP_PORT_ADDR(base) ((base) + (0x070C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_tag : 8;
        unsigned int reserved_0: 8;
        unsigned int version : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_QIC_GPUDATABUS_IBX_RTL_VER_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBX_RTL_VER_rtl_tag_START (0)
#define SOC_QIC_GPUDATABUS_IBX_RTL_VER_rtl_tag_END (7)
#define SOC_QIC_GPUDATABUS_IBX_RTL_VER_version_START (16)
#define SOC_QIC_GPUDATABUS_IBX_RTL_VER_version_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info0 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_IBX_RTL_INFO_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBX_RTL_INFO_rtl_info0_START (0)
#define SOC_QIC_GPUDATABUS_IBX_RTL_INFO_rtl_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info1 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_IBX_RTL_INF1_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBX_RTL_INF1_rtl_info1_START (0)
#define SOC_QIC_GPUDATABUS_IBX_RTL_INF1_rtl_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info2 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_IBX_RTL_INF2_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBX_RTL_INF2_rtl_info2_START (0)
#define SOC_QIC_GPUDATABUS_IBX_RTL_INF2_rtl_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int buffeable_dis : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_QIC_GPUDATABUS_IBX_NML_CTRL_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBX_NML_CTRL_buffeable_dis_START (0)
#define SOC_QIC_GPUDATABUS_IBX_NML_CTRL_buffeable_dis_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ckg_ext_ena : 1;
        unsigned int ckg_byp_inf : 1;
        unsigned int ckg_byp_req_ar : 1;
        unsigned int ckg_byp_req_aw : 1;
        unsigned int ckg_byp_rsp_r : 1;
        unsigned int ckg_byp_rsp_b : 1;
        unsigned int ckg_byp_cfg : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_QIC_GPUDATABUS_IBX_CKG_CTRL_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBX_CKG_CTRL_ckg_ext_ena_START (0)
#define SOC_QIC_GPUDATABUS_IBX_CKG_CTRL_ckg_ext_ena_END (0)
#define SOC_QIC_GPUDATABUS_IBX_CKG_CTRL_ckg_byp_inf_START (1)
#define SOC_QIC_GPUDATABUS_IBX_CKG_CTRL_ckg_byp_inf_END (1)
#define SOC_QIC_GPUDATABUS_IBX_CKG_CTRL_ckg_byp_req_ar_START (2)
#define SOC_QIC_GPUDATABUS_IBX_CKG_CTRL_ckg_byp_req_ar_END (2)
#define SOC_QIC_GPUDATABUS_IBX_CKG_CTRL_ckg_byp_req_aw_START (3)
#define SOC_QIC_GPUDATABUS_IBX_CKG_CTRL_ckg_byp_req_aw_END (3)
#define SOC_QIC_GPUDATABUS_IBX_CKG_CTRL_ckg_byp_rsp_r_START (4)
#define SOC_QIC_GPUDATABUS_IBX_CKG_CTRL_ckg_byp_rsp_r_END (4)
#define SOC_QIC_GPUDATABUS_IBX_CKG_CTRL_ckg_byp_rsp_b_START (5)
#define SOC_QIC_GPUDATABUS_IBX_CKG_CTRL_ckg_byp_rsp_b_END (5)
#define SOC_QIC_GPUDATABUS_IBX_CKG_CTRL_ckg_byp_cfg_START (6)
#define SOC_QIC_GPUDATABUS_IBX_CKG_CTRL_ckg_byp_cfg_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_tag : 8;
        unsigned int reserved_0: 8;
        unsigned int version : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_QIC_GPUDATABUS_IBP_RTL_VER_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBP_RTL_VER_rtl_tag_START (0)
#define SOC_QIC_GPUDATABUS_IBP_RTL_VER_rtl_tag_END (7)
#define SOC_QIC_GPUDATABUS_IBP_RTL_VER_version_START (16)
#define SOC_QIC_GPUDATABUS_IBP_RTL_VER_version_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info0 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_IBP_RTL_INFO_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBP_RTL_INFO_rtl_info0_START (0)
#define SOC_QIC_GPUDATABUS_IBP_RTL_INFO_rtl_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info1 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_IBP_RTL_INF1_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBP_RTL_INF1_rtl_info1_START (0)
#define SOC_QIC_GPUDATABUS_IBP_RTL_INF1_rtl_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info2 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_IBP_RTL_INF2_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBP_RTL_INF2_rtl_info2_START (0)
#define SOC_QIC_GPUDATABUS_IBP_RTL_INF2_rtl_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ckg_ext_ena : 1;
        unsigned int ckg_byp : 1;
        unsigned int ckg_byp_cfg : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_QIC_GPUDATABUS_IBP_CKG_CTRL_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBP_CKG_CTRL_ckg_ext_ena_START (0)
#define SOC_QIC_GPUDATABUS_IBP_CKG_CTRL_ckg_ext_ena_END (0)
#define SOC_QIC_GPUDATABUS_IBP_CKG_CTRL_ckg_byp_START (1)
#define SOC_QIC_GPUDATABUS_IBP_CKG_CTRL_ckg_byp_END (1)
#define SOC_QIC_GPUDATABUS_IBP_CKG_CTRL_ckg_byp_cfg_START (2)
#define SOC_QIC_GPUDATABUS_IBP_CKG_CTRL_ckg_byp_cfg_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_tag : 8;
        unsigned int reserved_0: 8;
        unsigned int version : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_RTL_VER_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_RTL_VER_rtl_tag_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_RTL_VER_rtl_tag_END (7)
#define SOC_QIC_GPUDATABUS_IBQ_RTL_VER_version_START (16)
#define SOC_QIC_GPUDATABUS_IBQ_RTL_VER_version_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info0 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_RTL_INFO_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_RTL_INFO_rtl_info0_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_RTL_INFO_rtl_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info1 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_RTL_INF1_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_RTL_INF1_rtl_info1_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_RTL_INF1_rtl_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info2 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_RTL_INF2_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_RTL_INF2_rtl_info2_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_RTL_INF2_rtl_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
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
} SOC_QIC_GPUDATABUS_IBQ_CKG_CTRL_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_CKG_CTRL_ckg_ext_ena_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_CKG_CTRL_ckg_ext_ena_END (0)
#define SOC_QIC_GPUDATABUS_IBQ_CKG_CTRL_ckg_byp_ibq_START (1)
#define SOC_QIC_GPUDATABUS_IBQ_CKG_CTRL_ckg_byp_ibq_END (1)
#define SOC_QIC_GPUDATABUS_IBQ_CKG_CTRL_ckg_byp_req_START (2)
#define SOC_QIC_GPUDATABUS_IBQ_CKG_CTRL_ckg_byp_req_END (2)
#define SOC_QIC_GPUDATABUS_IBQ_CKG_CTRL_ckg_byp_rsp_START (3)
#define SOC_QIC_GPUDATABUS_IBQ_CKG_CTRL_ckg_byp_rsp_END (3)
#define SOC_QIC_GPUDATABUS_IBQ_CKG_CTRL_ckg_byp_ct_START (4)
#define SOC_QIC_GPUDATABUS_IBQ_CKG_CTRL_ckg_byp_ct_END (4)
#define SOC_QIC_GPUDATABUS_IBQ_CKG_CTRL_ckg_byp_qos_START (5)
#define SOC_QIC_GPUDATABUS_IBQ_CKG_CTRL_ckg_byp_qos_END (5)
#define SOC_QIC_GPUDATABUS_IBQ_CKG_CTRL_ckg_byp_cfc_START (6)
#define SOC_QIC_GPUDATABUS_IBQ_CKG_CTRL_ckg_byp_cfc_END (6)
#define SOC_QIC_GPUDATABUS_IBQ_CKG_CTRL_ckg_byp_tes_START (7)
#define SOC_QIC_GPUDATABUS_IBQ_CKG_CTRL_ckg_byp_tes_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ram_tmod : 32;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_RAM_TMOD_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_RAM_TMOD_ram_tmod_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_RAM_TMOD_ram_tmod_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rsv_rw : 32;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_RSV_RW_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_RSV_RW_rsv_rw_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_RSV_RW_rsv_rw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qos_gen_fix_mode : 1;
        unsigned int reserved_0 : 15;
        unsigned int qos_gen_fix_r_pri : 4;
        unsigned int qos_gen_fix_w_pri : 4;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_FIX_CTRL_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_FIX_CTRL_qos_gen_fix_mode_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_FIX_CTRL_qos_gen_fix_mode_END (0)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_FIX_CTRL_qos_gen_fix_r_pri_START (16)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_FIX_CTRL_qos_gen_fix_r_pri_END (19)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_FIX_CTRL_qos_gen_fix_w_pri_START (20)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_FIX_CTRL_qos_gen_fix_w_pri_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gen_remap_pri0 : 4;
        unsigned int gen_remap_pri1 : 4;
        unsigned int gen_remap_pri2 : 4;
        unsigned int gen_remap_pri3 : 4;
        unsigned int gen_remap_pri4 : 4;
        unsigned int gen_remap_pri5 : 4;
        unsigned int gen_remap_pri6 : 4;
        unsigned int gen_remap_pri7 : 4;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP0_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP0_gen_remap_pri0_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP0_gen_remap_pri0_END (3)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP0_gen_remap_pri1_START (4)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP0_gen_remap_pri1_END (7)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP0_gen_remap_pri2_START (8)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP0_gen_remap_pri2_END (11)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP0_gen_remap_pri3_START (12)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP0_gen_remap_pri3_END (15)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP0_gen_remap_pri4_START (16)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP0_gen_remap_pri4_END (19)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP0_gen_remap_pri5_START (20)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP0_gen_remap_pri5_END (23)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP0_gen_remap_pri6_START (24)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP0_gen_remap_pri6_END (27)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP0_gen_remap_pri7_START (28)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP0_gen_remap_pri7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gen_remap_pri8 : 4;
        unsigned int gen_remap_pri9 : 4;
        unsigned int gen_remap_pri10 : 4;
        unsigned int gen_remap_pri11 : 4;
        unsigned int gen_remap_pri12 : 4;
        unsigned int gen_remap_pri13 : 4;
        unsigned int gen_remap_pri14 : 4;
        unsigned int gen_remap_pri15 : 4;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP1_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP1_gen_remap_pri8_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP1_gen_remap_pri8_END (3)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP1_gen_remap_pri9_START (4)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP1_gen_remap_pri9_END (7)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP1_gen_remap_pri10_START (8)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP1_gen_remap_pri10_END (11)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP1_gen_remap_pri11_START (12)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP1_gen_remap_pri11_END (15)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP1_gen_remap_pri12_START (16)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP1_gen_remap_pri12_END (19)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP1_gen_remap_pri13_START (20)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP1_gen_remap_pri13_END (23)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP1_gen_remap_pri14_START (24)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP1_gen_remap_pri14_END (27)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP1_gen_remap_pri15_START (28)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_REMAP1_gen_remap_pri15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qos_gen_rglr_mode : 1;
        unsigned int reserved_0 : 3;
        unsigned int qos_gen_rglr_max : 1;
        unsigned int reserved_1 : 11;
        unsigned int qos_gen_rglr_r_low : 4;
        unsigned int qos_gen_rglr_r_high : 4;
        unsigned int qos_gen_rglr_w_low : 4;
        unsigned int qos_gen_rglr_w_high : 4;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_RGLR_CTRL_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_RGLR_CTRL_qos_gen_rglr_mode_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_RGLR_CTRL_qos_gen_rglr_mode_END (0)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_RGLR_CTRL_qos_gen_rglr_max_START (4)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_RGLR_CTRL_qos_gen_rglr_max_END (4)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_RGLR_CTRL_qos_gen_rglr_r_low_START (16)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_RGLR_CTRL_qos_gen_rglr_r_low_END (19)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_RGLR_CTRL_qos_gen_rglr_r_high_START (20)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_RGLR_CTRL_qos_gen_rglr_r_high_END (23)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_RGLR_CTRL_qos_gen_rglr_w_low_START (24)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_RGLR_CTRL_qos_gen_rglr_w_low_END (27)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_RGLR_CTRL_qos_gen_rglr_w_high_START (28)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_RGLR_CTRL_qos_gen_rglr_w_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qos_gen_rglr_bw : 8;
        unsigned int qos_gen_rglr_sat : 8;
        unsigned int reserved_0 : 8;
        unsigned int qos_gen_rglr_lp : 2;
        unsigned int reserved_1 : 5;
        unsigned int qos_gen_rglr_en : 1;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_RGLR_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_RGLR_qos_gen_rglr_bw_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_RGLR_qos_gen_rglr_bw_END (7)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_RGLR_qos_gen_rglr_sat_START (8)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_RGLR_qos_gen_rglr_sat_END (15)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_RGLR_qos_gen_rglr_lp_START (24)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_RGLR_qos_gen_rglr_lp_END (25)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_RGLR_qos_gen_rglr_en_START (31)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_GEN_RGLR_qos_gen_rglr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_lmtr_bw : 8;
        unsigned int sta_lmtr_sat : 8;
        unsigned int reserved_0 : 8;
        unsigned int sta_lmtr_lp : 2;
        unsigned int reserved_1 : 5;
        unsigned int sta_lmtr_en : 1;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_QOS_STA_LMTR_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_QOS_STA_LMTR_sta_lmtr_bw_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_STA_LMTR_sta_lmtr_bw_END (7)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_STA_LMTR_sta_lmtr_sat_START (8)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_STA_LMTR_sta_lmtr_sat_END (15)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_STA_LMTR_sta_lmtr_lp_START (24)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_STA_LMTR_sta_lmtr_lp_END (25)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_STA_LMTR_sta_lmtr_en_START (31)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_STA_LMTR_sta_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dyn_lmtr_bw : 8;
        unsigned int dyn_lmtr_sat : 8;
        unsigned int reserved_0 : 8;
        unsigned int dyn_lmtr_lp : 2;
        unsigned int reserved_1 : 5;
        unsigned int dyn_lmtr_en : 1;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_QOS_DYN_LMTR_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_QOS_DYN_LMTR_dyn_lmtr_bw_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_DYN_LMTR_dyn_lmtr_bw_END (7)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_DYN_LMTR_dyn_lmtr_sat_START (8)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_DYN_LMTR_dyn_lmtr_sat_END (15)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_DYN_LMTR_dyn_lmtr_lp_START (24)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_DYN_LMTR_dyn_lmtr_lp_END (25)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_DYN_LMTR_dyn_lmtr_en_START (31)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_DYN_LMTR_dyn_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_vc_lmtr_bw : 8;
        unsigned int sta_vc_lmtr_sat : 8;
        unsigned int reserved_0 : 8;
        unsigned int sta_vc_lmtr_lp : 2;
        unsigned int reserved_1 : 5;
        unsigned int sta_vc_lmtr_en : 1;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_QOS_STA_VC_LMTR_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_bw_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_bw_END (7)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_sat_START (8)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_sat_END (15)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_lp_START (24)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_lp_END (25)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_en_START (31)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_ost_wl : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_QOS_STA_OST_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_QOS_STA_OST_sta_ost_wl_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_STA_OST_sta_ost_wl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_vc_ost_wl : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_QOS_STA_VC_OST_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_QOS_STA_VC_OST_sta_vc_ost_wl_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_STA_VC_OST_sta_vc_ost_wl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dyn_vc_ost_wl : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_QOS_DYN_VC_OST_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_QOS_DYN_VC_OST_dyn_vc_ost_wl_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_DYN_VC_OST_dyn_vc_ost_wl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vc_total_ost_wl : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_QOS_TOTAL_VC_OST_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_QOS_TOTAL_VC_OST_vc_total_ost_wl_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_QOS_TOTAL_VC_OST_vc_total_ost_wl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_stat_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int tes_stat_mode : 2;
        unsigned int reserved_1 : 2;
        unsigned int tes_stat_cnt_mode : 24;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_TES_CFG0_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_TES_CFG0_tes_stat_en_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_TES_CFG0_tes_stat_en_END (0)
#define SOC_QIC_GPUDATABUS_IBQ_TES_CFG0_tes_stat_mode_START (4)
#define SOC_QIC_GPUDATABUS_IBQ_TES_CFG0_tes_stat_mode_END (5)
#define SOC_QIC_GPUDATABUS_IBQ_TES_CFG0_tes_stat_cnt_mode_START (8)
#define SOC_QIC_GPUDATABUS_IBQ_TES_CFG0_tes_stat_cnt_mode_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_latcy_mode : 1;
        unsigned int reserved_0 : 3;
        unsigned int tes_latcy_prescaler : 10;
        unsigned int reserved_1 : 2;
        unsigned int tes_pfm_tes_align_mode : 1;
        unsigned int tes_pfm_tes_cmd_type : 1;
        unsigned int reserved_2 : 14;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_TES_CFG1_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_TES_CFG1_tes_latcy_mode_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_TES_CFG1_tes_latcy_mode_END (0)
#define SOC_QIC_GPUDATABUS_IBQ_TES_CFG1_tes_latcy_prescaler_START (4)
#define SOC_QIC_GPUDATABUS_IBQ_TES_CFG1_tes_latcy_prescaler_END (13)
#define SOC_QIC_GPUDATABUS_IBQ_TES_CFG1_tes_pfm_tes_align_mode_START (16)
#define SOC_QIC_GPUDATABUS_IBQ_TES_CFG1_tes_pfm_tes_align_mode_END (16)
#define SOC_QIC_GPUDATABUS_IBQ_TES_CFG1_tes_pfm_tes_cmd_type_START (17)
#define SOC_QIC_GPUDATABUS_IBQ_TES_CFG1_tes_pfm_tes_cmd_type_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_addr_s0 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_TES_FILTER0_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER0_tes_addr_s0_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER0_tes_addr_s0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_addr_s1 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_TES_FILTER1_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER1_tes_addr_s1_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER1_tes_addr_s1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_addr_e0 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_TES_FILTER2_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER2_tes_addr_e0_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER2_tes_addr_e0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_addr_e1 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_TES_FILTER3_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER3_tes_addr_e1_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER3_tes_addr_e1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_user0 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_TES_FILTER4_0_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER4_0_tes_user0_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER4_0_tes_user0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_user1 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_TES_FILTER4_1_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER4_1_tes_user1_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER4_1_tes_user1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_user2 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_TES_FILTER4_2_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER4_2_tes_user2_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER4_2_tes_user2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_user3 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_TES_FILTER4_3_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER4_3_tes_user3_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER4_3_tes_user3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_user_msk0 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_TES_FILTER5_0_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER5_0_tes_user_msk0_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER5_0_tes_user_msk0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_user_msk1 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_TES_FILTER5_1_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER5_1_tes_user_msk1_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER5_1_tes_user_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_user_msk2 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_TES_FILTER5_2_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER5_2_tes_user_msk2_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER5_2_tes_user_msk2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_user_msk3 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_TES_FILTER5_3_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER5_3_tes_user_msk3_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER5_3_tes_user_msk3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_exclid : 8;
        unsigned int tes_exclid_msk : 8;
        unsigned int tes_sf : 8;
        unsigned int tes_sf_msk : 8;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_TES_FILTER6_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER6_tes_exclid_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER6_tes_exclid_END (7)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER6_tes_exclid_msk_START (8)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER6_tes_exclid_msk_END (15)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER6_tes_sf_START (16)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER6_tes_sf_END (23)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER6_tes_sf_msk_START (24)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER6_tes_sf_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_qos : 8;
        unsigned int tes_tid : 8;
        unsigned int tes_tid_msk : 8;
        unsigned int tes_lck : 4;
        unsigned int tes_lck_msk : 4;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_TES_FILTER7_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER7_tes_qos_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER7_tes_qos_END (7)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER7_tes_tid_START (8)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER7_tes_tid_END (15)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER7_tes_tid_msk_START (16)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER7_tes_tid_msk_END (23)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER7_tes_lck_START (24)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER7_tes_lck_END (27)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER7_tes_lck_msk_START (28)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER7_tes_lck_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_tsize_min : 16;
        unsigned int tes_tsize_max : 16;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_TES_FILTER8_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER8_tes_tsize_min_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER8_tes_tsize_min_END (15)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER8_tes_tsize_max_START (16)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER8_tes_tsize_max_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
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
} SOC_QIC_GPUDATABUS_IBQ_TES_FILTER9_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER9_tes_dstid_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER9_tes_dstid_END (7)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER9_tes_dstid_msk_START (8)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER9_tes_dstid_msk_END (15)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER9_tes_vcnum_START (16)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER9_tes_vcnum_END (19)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER9_tes_vcnum_msk_START (20)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER9_tes_vcnum_msk_END (23)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER9_tes_burst_START (24)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER9_tes_burst_END (24)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER9_tes_burst_msk_START (25)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER9_tes_burst_msk_END (25)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER9_tes_wr_START (26)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER9_tes_wr_END (26)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER9_tes_wr_msk_START (27)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER9_tes_wr_msk_END (27)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER9_tes_rd_START (28)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER9_tes_rd_END (28)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER9_tes_rd_msk_START (29)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER9_tes_rd_msk_END (29)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER9_tes_splt_cmd_START (30)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER9_tes_splt_cmd_END (30)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER9_tes_splt_cmd_msk_START (31)
#define SOC_QIC_GPUDATABUS_IBQ_TES_FILTER9_tes_splt_cmd_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_stat_cnt_int : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_TES_INT_STAUS_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_TES_INT_STAUS_tes_stat_cnt_int_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_TES_INT_STAUS_tes_stat_cnt_int_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_stat_cnt_int_clr : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_TES_INT_CLR_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_TES_INT_CLR_tes_stat_cnt_int_clr_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_TES_INT_CLR_tes_stat_cnt_int_clr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_stat_cnt : 32;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_TES_CNT_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_TES_CNT_tes_stat_cnt_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_TES_CNT_tes_stat_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_stat_cnt_int_th : 32;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_TES_INT_CFG_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_TES_INT_CFG_tes_stat_cnt_int_th_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_TES_INT_CFG_tes_stat_cnt_int_th_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_busy : 32;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_DFX_BUSY_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_DFX_BUSY_dfx_busy_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_DFX_BUSY_dfx_busy_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_ost_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_DFX_OST_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_DFX_OST_dfx_ost_cnt_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_DFX_OST_dfx_ost_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_qtp_req_bp : 8;
        unsigned int dfx_qtp_req_trans : 8;
        unsigned int dfx_qtp_rsp_bp : 1;
        unsigned int dfx_qtp_rsp_trans : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_DFX_QTP_PORT_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_DFX_QTP_PORT_dfx_qtp_req_bp_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_DFX_QTP_PORT_dfx_qtp_req_bp_END (7)
#define SOC_QIC_GPUDATABUS_IBQ_DFX_QTP_PORT_dfx_qtp_req_trans_START (8)
#define SOC_QIC_GPUDATABUS_IBQ_DFX_QTP_PORT_dfx_qtp_req_trans_END (15)
#define SOC_QIC_GPUDATABUS_IBQ_DFX_QTP_PORT_dfx_qtp_rsp_bp_START (16)
#define SOC_QIC_GPUDATABUS_IBQ_DFX_QTP_PORT_dfx_qtp_rsp_bp_END (16)
#define SOC_QIC_GPUDATABUS_IBQ_DFX_QTP_PORT_dfx_qtp_rsp_trans_START (17)
#define SOC_QIC_GPUDATABUS_IBQ_DFX_QTP_PORT_dfx_qtp_rsp_trans_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_qsp_req_bp : 8;
        unsigned int dfx_qsp_req_trans : 8;
        unsigned int dfx_qsp_rsp_bp : 1;
        unsigned int dfx_qsp_rsp_trans : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_QIC_GPUDATABUS_IBQ_DFX_QSP_PORT_UNION;
#endif
#define SOC_QIC_GPUDATABUS_IBQ_DFX_QSP_PORT_dfx_qsp_req_bp_START (0)
#define SOC_QIC_GPUDATABUS_IBQ_DFX_QSP_PORT_dfx_qsp_req_bp_END (7)
#define SOC_QIC_GPUDATABUS_IBQ_DFX_QSP_PORT_dfx_qsp_req_trans_START (8)
#define SOC_QIC_GPUDATABUS_IBQ_DFX_QSP_PORT_dfx_qsp_req_trans_END (15)
#define SOC_QIC_GPUDATABUS_IBQ_DFX_QSP_PORT_dfx_qsp_rsp_bp_START (16)
#define SOC_QIC_GPUDATABUS_IBQ_DFX_QSP_PORT_dfx_qsp_rsp_bp_END (16)
#define SOC_QIC_GPUDATABUS_IBQ_DFX_QSP_PORT_dfx_qsp_rsp_trans_START (17)
#define SOC_QIC_GPUDATABUS_IBQ_DFX_QSP_PORT_dfx_qsp_rsp_trans_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_tag : 8;
        unsigned int reserved_0: 8;
        unsigned int version : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_QIC_GPUDATABUS_RT_RTL_VER_UNION;
#endif
#define SOC_QIC_GPUDATABUS_RT_RTL_VER_rtl_tag_START (0)
#define SOC_QIC_GPUDATABUS_RT_RTL_VER_rtl_tag_END (7)
#define SOC_QIC_GPUDATABUS_RT_RTL_VER_version_START (16)
#define SOC_QIC_GPUDATABUS_RT_RTL_VER_version_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info0 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_RT_RTL_INFO_UNION;
#endif
#define SOC_QIC_GPUDATABUS_RT_RTL_INFO_rtl_info0_START (0)
#define SOC_QIC_GPUDATABUS_RT_RTL_INFO_rtl_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info1 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_RT_RTL_INF1_UNION;
#endif
#define SOC_QIC_GPUDATABUS_RT_RTL_INF1_rtl_info1_START (0)
#define SOC_QIC_GPUDATABUS_RT_RTL_INF1_rtl_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info2 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_RT_RTL_INF2_UNION;
#endif
#define SOC_QIC_GPUDATABUS_RT_RTL_INF2_rtl_info2_START (0)
#define SOC_QIC_GPUDATABUS_RT_RTL_INF2_rtl_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ckg_ext_ena : 1;
        unsigned int ckg_byp_rt : 1;
        unsigned int ckg_byp_inp : 1;
        unsigned int ckg_byp_oup : 1;
        unsigned int ckg_byp_cfc : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_QIC_GPUDATABUS_RT_CKG_CTRL_UNION;
#endif
#define SOC_QIC_GPUDATABUS_RT_CKG_CTRL_ckg_ext_ena_START (0)
#define SOC_QIC_GPUDATABUS_RT_CKG_CTRL_ckg_ext_ena_END (0)
#define SOC_QIC_GPUDATABUS_RT_CKG_CTRL_ckg_byp_rt_START (1)
#define SOC_QIC_GPUDATABUS_RT_CKG_CTRL_ckg_byp_rt_END (1)
#define SOC_QIC_GPUDATABUS_RT_CKG_CTRL_ckg_byp_inp_START (2)
#define SOC_QIC_GPUDATABUS_RT_CKG_CTRL_ckg_byp_inp_END (2)
#define SOC_QIC_GPUDATABUS_RT_CKG_CTRL_ckg_byp_oup_START (3)
#define SOC_QIC_GPUDATABUS_RT_CKG_CTRL_ckg_byp_oup_END (3)
#define SOC_QIC_GPUDATABUS_RT_CKG_CTRL_ckg_byp_cfc_START (4)
#define SOC_QIC_GPUDATABUS_RT_CKG_CTRL_ckg_byp_cfc_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rsv_rw : 32;
    } reg;
} SOC_QIC_GPUDATABUS_RT_RSV_RW_UNION;
#endif
#define SOC_QIC_GPUDATABUS_RT_RSV_RW_rsv_rw_START (0)
#define SOC_QIC_GPUDATABUS_RT_RSV_RW_rsv_rw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_lmtr_bw : 8;
        unsigned int sta_lmtr_sat : 8;
        unsigned int reserved_0 : 8;
        unsigned int sta_lmtr_lp : 2;
        unsigned int reserved_1 : 5;
        unsigned int sta_lmtr_en : 1;
    } reg;
} SOC_QIC_GPUDATABUS_RT_QOS_OUP_LMTR_UNION;
#endif
#define SOC_QIC_GPUDATABUS_RT_QOS_OUP_LMTR_sta_lmtr_bw_START (0)
#define SOC_QIC_GPUDATABUS_RT_QOS_OUP_LMTR_sta_lmtr_bw_END (7)
#define SOC_QIC_GPUDATABUS_RT_QOS_OUP_LMTR_sta_lmtr_sat_START (8)
#define SOC_QIC_GPUDATABUS_RT_QOS_OUP_LMTR_sta_lmtr_sat_END (15)
#define SOC_QIC_GPUDATABUS_RT_QOS_OUP_LMTR_sta_lmtr_lp_START (24)
#define SOC_QIC_GPUDATABUS_RT_QOS_OUP_LMTR_sta_lmtr_lp_END (25)
#define SOC_QIC_GPUDATABUS_RT_QOS_OUP_LMTR_sta_lmtr_en_START (31)
#define SOC_QIC_GPUDATABUS_RT_QOS_OUP_LMTR_sta_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int inp_sfw_en : 16;
        unsigned int oup_sfw_en : 16;
    } reg;
} SOC_QIC_GPUDATABUS_RT_SFW_CTRL_UNION;
#endif
#define SOC_QIC_GPUDATABUS_RT_SFW_CTRL_inp_sfw_en_START (0)
#define SOC_QIC_GPUDATABUS_RT_SFW_CTRL_inp_sfw_en_END (15)
#define SOC_QIC_GPUDATABUS_RT_SFW_CTRL_oup_sfw_en_START (16)
#define SOC_QIC_GPUDATABUS_RT_SFW_CTRL_oup_sfw_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_tag : 8;
        unsigned int reserved_0: 8;
        unsigned int version : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_QIC_GPUDATABUS_TBX_RTL_VER_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBX_RTL_VER_rtl_tag_START (0)
#define SOC_QIC_GPUDATABUS_TBX_RTL_VER_rtl_tag_END (7)
#define SOC_QIC_GPUDATABUS_TBX_RTL_VER_version_START (16)
#define SOC_QIC_GPUDATABUS_TBX_RTL_VER_version_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info0 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_TBX_RTL_INFO_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBX_RTL_INFO_rtl_info0_START (0)
#define SOC_QIC_GPUDATABUS_TBX_RTL_INFO_rtl_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info1 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_TBX_RTL_INF1_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBX_RTL_INF1_rtl_info1_START (0)
#define SOC_QIC_GPUDATABUS_TBX_RTL_INF1_rtl_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info2 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_TBX_RTL_INF2_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBX_RTL_INF2_rtl_info2_START (0)
#define SOC_QIC_GPUDATABUS_TBX_RTL_INF2_rtl_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arcache_cfg : 4;
        unsigned int awcache_cfg : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_QIC_GPUDATABUS_TBX_NML_CTR_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBX_NML_CTR_arcache_cfg_START (0)
#define SOC_QIC_GPUDATABUS_TBX_NML_CTR_arcache_cfg_END (3)
#define SOC_QIC_GPUDATABUS_TBX_NML_CTR_awcache_cfg_START (4)
#define SOC_QIC_GPUDATABUS_TBX_NML_CTR_awcache_cfg_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ckg_ext_ena : 1;
        unsigned int ckg_byp_inf : 1;
        unsigned int ckg_byp_req_ar : 1;
        unsigned int ckg_byp_req_aw : 1;
        unsigned int ckg_byp_rsp_r : 1;
        unsigned int ckg_byp_rsp_b : 1;
        unsigned int ckg_byp_cfg : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_QIC_GPUDATABUS_TBX_CKG_CTRL_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBX_CKG_CTRL_ckg_ext_ena_START (0)
#define SOC_QIC_GPUDATABUS_TBX_CKG_CTRL_ckg_ext_ena_END (0)
#define SOC_QIC_GPUDATABUS_TBX_CKG_CTRL_ckg_byp_inf_START (1)
#define SOC_QIC_GPUDATABUS_TBX_CKG_CTRL_ckg_byp_inf_END (1)
#define SOC_QIC_GPUDATABUS_TBX_CKG_CTRL_ckg_byp_req_ar_START (2)
#define SOC_QIC_GPUDATABUS_TBX_CKG_CTRL_ckg_byp_req_ar_END (2)
#define SOC_QIC_GPUDATABUS_TBX_CKG_CTRL_ckg_byp_req_aw_START (3)
#define SOC_QIC_GPUDATABUS_TBX_CKG_CTRL_ckg_byp_req_aw_END (3)
#define SOC_QIC_GPUDATABUS_TBX_CKG_CTRL_ckg_byp_rsp_r_START (4)
#define SOC_QIC_GPUDATABUS_TBX_CKG_CTRL_ckg_byp_rsp_r_END (4)
#define SOC_QIC_GPUDATABUS_TBX_CKG_CTRL_ckg_byp_rsp_b_START (5)
#define SOC_QIC_GPUDATABUS_TBX_CKG_CTRL_ckg_byp_rsp_b_END (5)
#define SOC_QIC_GPUDATABUS_TBX_CKG_CTRL_ckg_byp_cfg_START (6)
#define SOC_QIC_GPUDATABUS_TBX_CKG_CTRL_ckg_byp_cfg_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_tag : 8;
        unsigned int reserved_0: 8;
        unsigned int version : 12;
        unsigned int reserved_1: 4;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_RTL_VER_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_RTL_VER_rtl_tag_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_RTL_VER_rtl_tag_END (7)
#define SOC_QIC_GPUDATABUS_TBQ_RTL_VER_version_START (16)
#define SOC_QIC_GPUDATABUS_TBQ_RTL_VER_version_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info0 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_RTL_INFO_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_RTL_INFO_rtl_info0_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_RTL_INFO_rtl_info0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info1 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_RTL_INF1_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_RTL_INF1_rtl_info1_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_RTL_INF1_rtl_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtl_info2 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_RTL_INF2_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_RTL_INF2_rtl_info2_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_RTL_INF2_rtl_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
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
} SOC_QIC_GPUDATABUS_TBQ_CKG_CTRL_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_CKG_CTRL_ckg_ext_ena_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_CKG_CTRL_ckg_ext_ena_END (0)
#define SOC_QIC_GPUDATABUS_TBQ_CKG_CTRL_ckg_byp_tbq_START (1)
#define SOC_QIC_GPUDATABUS_TBQ_CKG_CTRL_ckg_byp_tbq_END (1)
#define SOC_QIC_GPUDATABUS_TBQ_CKG_CTRL_ckg_byp_req_START (2)
#define SOC_QIC_GPUDATABUS_TBQ_CKG_CTRL_ckg_byp_req_END (2)
#define SOC_QIC_GPUDATABUS_TBQ_CKG_CTRL_ckg_byp_rsp_START (3)
#define SOC_QIC_GPUDATABUS_TBQ_CKG_CTRL_ckg_byp_rsp_END (3)
#define SOC_QIC_GPUDATABUS_TBQ_CKG_CTRL_ckg_byp_ct_START (4)
#define SOC_QIC_GPUDATABUS_TBQ_CKG_CTRL_ckg_byp_ct_END (4)
#define SOC_QIC_GPUDATABUS_TBQ_CKG_CTRL_ckg_byp_qos_START (5)
#define SOC_QIC_GPUDATABUS_TBQ_CKG_CTRL_ckg_byp_qos_END (5)
#define SOC_QIC_GPUDATABUS_TBQ_CKG_CTRL_ckg_byp_cfc_START (6)
#define SOC_QIC_GPUDATABUS_TBQ_CKG_CTRL_ckg_byp_cfc_END (6)
#define SOC_QIC_GPUDATABUS_TBQ_CKG_CTRL_ckg_byp_tes_START (7)
#define SOC_QIC_GPUDATABUS_TBQ_CKG_CTRL_ckg_byp_tes_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rsv_rw : 32;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_RSV_RW_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_RSV_RW_rsv_rw_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_RSV_RW_rsv_rw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_lmtr_bw : 8;
        unsigned int sta_lmtr_sat : 8;
        unsigned int reserved_0 : 8;
        unsigned int sta_lmtr_lp : 2;
        unsigned int reserved_1 : 5;
        unsigned int sta_lmtr_en : 1;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_QOS_STA_LMTR_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_QOS_STA_LMTR_sta_lmtr_bw_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_QOS_STA_LMTR_sta_lmtr_bw_END (7)
#define SOC_QIC_GPUDATABUS_TBQ_QOS_STA_LMTR_sta_lmtr_sat_START (8)
#define SOC_QIC_GPUDATABUS_TBQ_QOS_STA_LMTR_sta_lmtr_sat_END (15)
#define SOC_QIC_GPUDATABUS_TBQ_QOS_STA_LMTR_sta_lmtr_lp_START (24)
#define SOC_QIC_GPUDATABUS_TBQ_QOS_STA_LMTR_sta_lmtr_lp_END (25)
#define SOC_QIC_GPUDATABUS_TBQ_QOS_STA_LMTR_sta_lmtr_en_START (31)
#define SOC_QIC_GPUDATABUS_TBQ_QOS_STA_LMTR_sta_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_vc_lmtr_bw : 8;
        unsigned int sta_vc_lmtr_sat : 8;
        unsigned int reserved_0 : 8;
        unsigned int sta_vc_lmtr_lp : 2;
        unsigned int reserved_1 : 5;
        unsigned int sta_vc_lmtr_en : 1;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_QOS_STA_VC_LMTR_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_bw_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_bw_END (7)
#define SOC_QIC_GPUDATABUS_TBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_sat_START (8)
#define SOC_QIC_GPUDATABUS_TBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_sat_END (15)
#define SOC_QIC_GPUDATABUS_TBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_lp_START (24)
#define SOC_QIC_GPUDATABUS_TBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_lp_END (25)
#define SOC_QIC_GPUDATABUS_TBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_en_START (31)
#define SOC_QIC_GPUDATABUS_TBQ_QOS_STA_VC_LMTR_sta_vc_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dyn_vc_lmtr_bw : 8;
        unsigned int dyn_vc_lmtr_sat : 8;
        unsigned int reserved_0 : 8;
        unsigned int dyn_vc_lmtr_lp : 2;
        unsigned int reserved_1 : 5;
        unsigned int dyn_vc_lmtr_en : 1;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_QOS_DYN_VC_LMTR_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_QOS_DYN_VC_LMTR_dyn_vc_lmtr_bw_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_QOS_DYN_VC_LMTR_dyn_vc_lmtr_bw_END (7)
#define SOC_QIC_GPUDATABUS_TBQ_QOS_DYN_VC_LMTR_dyn_vc_lmtr_sat_START (8)
#define SOC_QIC_GPUDATABUS_TBQ_QOS_DYN_VC_LMTR_dyn_vc_lmtr_sat_END (15)
#define SOC_QIC_GPUDATABUS_TBQ_QOS_DYN_VC_LMTR_dyn_vc_lmtr_lp_START (24)
#define SOC_QIC_GPUDATABUS_TBQ_QOS_DYN_VC_LMTR_dyn_vc_lmtr_lp_END (25)
#define SOC_QIC_GPUDATABUS_TBQ_QOS_DYN_VC_LMTR_dyn_vc_lmtr_en_START (31)
#define SOC_QIC_GPUDATABUS_TBQ_QOS_DYN_VC_LMTR_dyn_vc_lmtr_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_ost_wl : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_QOS_STA_OST_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_QOS_STA_OST_sta_ost_wl_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_QOS_STA_OST_sta_ost_wl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_vc_ost_wl : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_QOS_STA_VC_OST_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_QOS_STA_VC_OST_sta_vc_ost_wl_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_QOS_STA_VC_OST_sta_vc_ost_wl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dyn_vc_ost_wl : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_QOS_DYN_VC_OST_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_QOS_DYN_VC_OST_dyn_vc_ost_wl_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_QOS_DYN_VC_OST_dyn_vc_ost_wl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vc_total_ost_wl : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_QOS_TOTAL_VC_OST_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_QOS_TOTAL_VC_OST_vc_total_ost_wl_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_QOS_TOTAL_VC_OST_vc_total_ost_wl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_stat_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int tes_stat_mode : 2;
        unsigned int reserved_1 : 2;
        unsigned int tes_stat_cnt_mode : 24;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_TES_CFG0_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_TES_CFG0_tes_stat_en_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_TES_CFG0_tes_stat_en_END (0)
#define SOC_QIC_GPUDATABUS_TBQ_TES_CFG0_tes_stat_mode_START (4)
#define SOC_QIC_GPUDATABUS_TBQ_TES_CFG0_tes_stat_mode_END (5)
#define SOC_QIC_GPUDATABUS_TBQ_TES_CFG0_tes_stat_cnt_mode_START (8)
#define SOC_QIC_GPUDATABUS_TBQ_TES_CFG0_tes_stat_cnt_mode_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_latcy_mode : 1;
        unsigned int reserved_0 : 3;
        unsigned int tes_latcy_prescaler : 10;
        unsigned int reserved_1 : 2;
        unsigned int tes_pfm_tes_align_mode : 1;
        unsigned int tes_pfm_tes_cmd_type : 1;
        unsigned int reserved_2 : 14;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_TES_CFG1_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_TES_CFG1_tes_latcy_mode_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_TES_CFG1_tes_latcy_mode_END (0)
#define SOC_QIC_GPUDATABUS_TBQ_TES_CFG1_tes_latcy_prescaler_START (4)
#define SOC_QIC_GPUDATABUS_TBQ_TES_CFG1_tes_latcy_prescaler_END (13)
#define SOC_QIC_GPUDATABUS_TBQ_TES_CFG1_tes_pfm_tes_align_mode_START (16)
#define SOC_QIC_GPUDATABUS_TBQ_TES_CFG1_tes_pfm_tes_align_mode_END (16)
#define SOC_QIC_GPUDATABUS_TBQ_TES_CFG1_tes_pfm_tes_cmd_type_START (17)
#define SOC_QIC_GPUDATABUS_TBQ_TES_CFG1_tes_pfm_tes_cmd_type_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_addr_s0 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_TES_FILTER0_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER0_tes_addr_s0_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER0_tes_addr_s0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_addr_s1 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_TES_FILTER1_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER1_tes_addr_s1_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER1_tes_addr_s1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_addr_e0 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_TES_FILTER2_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER2_tes_addr_e0_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER2_tes_addr_e0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_addr_e1 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_TES_FILTER3_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER3_tes_addr_e1_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER3_tes_addr_e1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_user0 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_TES_FILTER4_0_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER4_0_tes_user0_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER4_0_tes_user0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_user1 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_TES_FILTER4_1_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER4_1_tes_user1_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER4_1_tes_user1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_user2 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_TES_FILTER4_2_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER4_2_tes_user2_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER4_2_tes_user2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_user3 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_TES_FILTER4_3_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER4_3_tes_user3_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER4_3_tes_user3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_user_msk0 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_TES_FILTER5_0_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER5_0_tes_user_msk0_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER5_0_tes_user_msk0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_user_msk1 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_TES_FILTER5_1_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER5_1_tes_user_msk1_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER5_1_tes_user_msk1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_user_msk2 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_TES_FILTER5_2_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER5_2_tes_user_msk2_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER5_2_tes_user_msk2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_user_msk3 : 32;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_TES_FILTER5_3_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER5_3_tes_user_msk3_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER5_3_tes_user_msk3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_exclid : 8;
        unsigned int tes_exclid_msk : 8;
        unsigned int tes_sf : 8;
        unsigned int tes_sf_msk : 8;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_TES_FILTER6_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER6_tes_exclid_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER6_tes_exclid_END (7)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER6_tes_exclid_msk_START (8)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER6_tes_exclid_msk_END (15)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER6_tes_sf_START (16)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER6_tes_sf_END (23)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER6_tes_sf_msk_START (24)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER6_tes_sf_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_qos : 8;
        unsigned int tes_tid : 8;
        unsigned int tes_tid_msk : 8;
        unsigned int tes_lck : 4;
        unsigned int tes_lck_msk : 4;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_TES_FILTER7_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER7_tes_qos_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER7_tes_qos_END (7)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER7_tes_tid_START (8)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER7_tes_tid_END (15)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER7_tes_tid_msk_START (16)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER7_tes_tid_msk_END (23)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER7_tes_lck_START (24)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER7_tes_lck_END (27)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER7_tes_lck_msk_START (28)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER7_tes_lck_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_tsize_min : 16;
        unsigned int tes_tsize_max : 16;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_TES_FILTER8_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER8_tes_tsize_min_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER8_tes_tsize_min_END (15)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER8_tes_tsize_max_START (16)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER8_tes_tsize_max_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
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
} SOC_QIC_GPUDATABUS_TBQ_TES_FILTER9_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER9_tes_srcid_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER9_tes_srcid_END (7)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER9_tes_srcid_msk_START (8)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER9_tes_srcid_msk_END (15)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER9_tes_vcnum_START (16)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER9_tes_vcnum_END (19)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER9_tes_vcnum_msk_START (20)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER9_tes_vcnum_msk_END (23)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER9_tes_burst_START (24)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER9_tes_burst_END (24)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER9_tes_burst_msk_START (25)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER9_tes_burst_msk_END (25)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER9_tes_wr_START (26)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER9_tes_wr_END (26)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER9_tes_wr_msk_START (27)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER9_tes_wr_msk_END (27)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER9_tes_rd_START (28)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER9_tes_rd_END (28)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER9_tes_rd_msk_START (29)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER9_tes_rd_msk_END (29)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER9_tes_splt_cmd_START (30)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER9_tes_splt_cmd_END (30)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER9_tes_splt_cmd_msk_START (31)
#define SOC_QIC_GPUDATABUS_TBQ_TES_FILTER9_tes_splt_cmd_msk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_stat_cnt_int : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_TES_INT_STAUS_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_TES_INT_STAUS_tes_stat_cnt_int_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_TES_INT_STAUS_tes_stat_cnt_int_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_stat_cnt_int_clr : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_TES_INT_CLR_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_TES_INT_CLR_tes_stat_cnt_int_clr_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_TES_INT_CLR_tes_stat_cnt_int_clr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_stat_cnt : 32;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_TES_CNT_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_TES_CNT_tes_stat_cnt_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_TES_CNT_tes_stat_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tes_stat_cnt_int_th : 32;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_TES_INT_CFG_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_TES_INT_CFG_tes_stat_cnt_int_th_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_TES_INT_CFG_tes_stat_cnt_int_th_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_busy : 32;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_DFX_BUSY_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_DFX_BUSY_dfx_busy_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_DFX_BUSY_dfx_busy_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_ostd_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_DFX_OT_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_DFX_OT_dfx_ostd_cnt_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_DFX_OT_dfx_ostd_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_qtp_req_bp : 8;
        unsigned int dfx_qtp_req_trans : 8;
        unsigned int dfx_qtp_rsp_bp : 1;
        unsigned int dfx_qtp_rsp_trans : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_DFX_QTP_PORT_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_DFX_QTP_PORT_dfx_qtp_req_bp_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_DFX_QTP_PORT_dfx_qtp_req_bp_END (7)
#define SOC_QIC_GPUDATABUS_TBQ_DFX_QTP_PORT_dfx_qtp_req_trans_START (8)
#define SOC_QIC_GPUDATABUS_TBQ_DFX_QTP_PORT_dfx_qtp_req_trans_END (15)
#define SOC_QIC_GPUDATABUS_TBQ_DFX_QTP_PORT_dfx_qtp_rsp_bp_START (16)
#define SOC_QIC_GPUDATABUS_TBQ_DFX_QTP_PORT_dfx_qtp_rsp_bp_END (16)
#define SOC_QIC_GPUDATABUS_TBQ_DFX_QTP_PORT_dfx_qtp_rsp_trans_START (17)
#define SOC_QIC_GPUDATABUS_TBQ_DFX_QTP_PORT_dfx_qtp_rsp_trans_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_qsp_req_bp : 8;
        unsigned int dfx_qsp_req_trans : 8;
        unsigned int dfx_qsp_rsp_bp : 1;
        unsigned int dfx_qsp_rsp_trans : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_QIC_GPUDATABUS_TBQ_DFX_QSP_PORT_UNION;
#endif
#define SOC_QIC_GPUDATABUS_TBQ_DFX_QSP_PORT_dfx_qsp_req_bp_START (0)
#define SOC_QIC_GPUDATABUS_TBQ_DFX_QSP_PORT_dfx_qsp_req_bp_END (7)
#define SOC_QIC_GPUDATABUS_TBQ_DFX_QSP_PORT_dfx_qsp_req_trans_START (8)
#define SOC_QIC_GPUDATABUS_TBQ_DFX_QSP_PORT_dfx_qsp_req_trans_END (15)
#define SOC_QIC_GPUDATABUS_TBQ_DFX_QSP_PORT_dfx_qsp_rsp_bp_START (16)
#define SOC_QIC_GPUDATABUS_TBQ_DFX_QSP_PORT_dfx_qsp_rsp_bp_END (16)
#define SOC_QIC_GPUDATABUS_TBQ_DFX_QSP_PORT_dfx_qsp_rsp_trans_START (17)
#define SOC_QIC_GPUDATABUS_TBQ_DFX_QSP_PORT_dfx_qsp_rsp_trans_END (17)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
