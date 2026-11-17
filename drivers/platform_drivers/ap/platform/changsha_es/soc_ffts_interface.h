#ifndef __SOC_FFTS_INTERFACE_H__
#define __SOC_FFTS_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FFTS_RDYTASKQ_PTR_ADDR(base,QOS_NUM) ((base) + ((QOS_NUM)*4+0x1040UL))
#define SOC_FFTS_RTB_READ_ATOMIC_ADDR(base,QOS_NUM) ((base) + ((QOS_NUM)*4+0x1060UL))
#define SOC_FFTS_TID_INFO_ADDR(base) ((base) + (0x1080UL))
#define SOC_FFTS_INTR_WK_SET_ADDR(base) ((base) + (0x1084UL))
#define SOC_FFTS_DOORBELL_ADDR(base) ((base) + (0x1088UL))
#define SOC_FFTS_TASK_PRE_ALLOC0_ADDR(base) ((base) + (0x108CUL))
#define SOC_FFTS_TASK_PRE_ALLOC1_ADDR(base) ((base) + (0x1090UL))
#define SOC_FFTS_TASKREQUEST_ADDR(base) ((base) + (0x1094UL))
#define SOC_FFTS_TASKRELEASE_ADDR(base) ((base) + (0x1098UL))
#define SOC_FFTS_TASKSTART_ADDR(base) ((base) + (0x109CUL))
#define SOC_FFTS_TASKDONE_ADDR(base) ((base) + (0x10A0UL))
#define SOC_FFTS_TASKEXCEPTION_ADDR(base) ((base) + (0x10A4UL))
#define SOC_FFTS_TASKCANCEL_ADDR(base) ((base) + (0x10A8UL))
#define SOC_FFTS_TASK_AUTO_REL_ADDR(base) ((base) + (0x10ACUL))
#define SOC_FFTS_PROC_TASKCNT_ADDR(base) ((base) + (0x10B0UL))
#define SOC_FFTS_PROC_VERCNT_ADDR(base) ((base) + (0x10B4UL))
#define SOC_FFTS_PROC_SIGCNT_ADDR(base) ((base) + (0x10B8UL))
#define SOC_FFTS_SEND_EVENT_ADDR(base) ((base) + (0x10BCUL))
#else
#define SOC_FFTS_RDYTASKQ_PTR_ADDR(base,QOS_NUM) ((base) + ((QOS_NUM)*4+0x1040))
#define SOC_FFTS_RTB_READ_ATOMIC_ADDR(base,QOS_NUM) ((base) + ((QOS_NUM)*4+0x1060))
#define SOC_FFTS_TID_INFO_ADDR(base) ((base) + (0x1080))
#define SOC_FFTS_INTR_WK_SET_ADDR(base) ((base) + (0x1084))
#define SOC_FFTS_DOORBELL_ADDR(base) ((base) + (0x1088))
#define SOC_FFTS_TASK_PRE_ALLOC0_ADDR(base) ((base) + (0x108C))
#define SOC_FFTS_TASK_PRE_ALLOC1_ADDR(base) ((base) + (0x1090))
#define SOC_FFTS_TASKREQUEST_ADDR(base) ((base) + (0x1094))
#define SOC_FFTS_TASKRELEASE_ADDR(base) ((base) + (0x1098))
#define SOC_FFTS_TASKSTART_ADDR(base) ((base) + (0x109C))
#define SOC_FFTS_TASKDONE_ADDR(base) ((base) + (0x10A0))
#define SOC_FFTS_TASKEXCEPTION_ADDR(base) ((base) + (0x10A4))
#define SOC_FFTS_TASKCANCEL_ADDR(base) ((base) + (0x10A8))
#define SOC_FFTS_TASK_AUTO_REL_ADDR(base) ((base) + (0x10AC))
#define SOC_FFTS_PROC_TASKCNT_ADDR(base) ((base) + (0x10B0))
#define SOC_FFTS_PROC_VERCNT_ADDR(base) ((base) + (0x10B4))
#define SOC_FFTS_PROC_SIGCNT_ADDR(base) ((base) + (0x10B8))
#define SOC_FFTS_SEND_EVENT_ADDR(base) ((base) + (0x10BC))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_FFTS_INITIAL_CTRL_ADDR(base) ((base) + (0x2000UL))
#define SOC_FFTS_SR_BACKUP_CTRL_ADDR(base) ((base) + (0x2004UL))
#define SOC_FFTS_SR_RESUME_CTRL_ADDR(base) ((base) + (0x2008UL))
#define SOC_FFTS_BASE_H_ADDR(base,ADDR_NUM) ((base) + ((ADDR_NUM)*8+0x2010UL))
#define SOC_FFTS_BASE_L_ADDR(base,ADDR_NUM) ((base) + ((ADDR_NUM)*8+0x2014UL))
#define SOC_FFTS_DDR_ATTR_CTRL_ADDR(base,ATTR_NUM) ((base) + ((ATTR_NUM)*4+0x2080UL))
#define SOC_FFTS_VERSION_ID_ADDR(base) ((base) + (0x20ACUL))
#define SOC_FFTS_RESERVED_ADDR(base) ((base) + (0x20B0UL))
#define SOC_FFTS_LPID_MAP_ADDR(base,ACPU_MID_NUM) ((base) + ((ACPU_MID_NUM)*4+0x2100UL))
#define SOC_FFTS_ISP_MAP_ADDR(base,ISPCPU_MID_NUM) ((base) + ((ISPCPU_MID_NUM)*4+0x2138UL))
#define SOC_FFTS_MDM_MAP_ADDR(base,MDM_MID_NUM) ((base) + ((MDM_MID_NUM)*4+0x2140UL))
#define SOC_FFTS_MISC_CPU_MAP0_ADDR(base,MISC_MID_NUM) ((base) + ((MISC_MID_NUM)*4+0x2150UL))
#define SOC_FFTS_MISC_CPU_MAP1_ADDR(base,MISC_MID_NUM) ((base) + ((MISC_MID_NUM)*4+0x2160UL))
#define SOC_FFTS_TASK_CNT_TH_ADDR(base) ((base) + (0x2200UL))
#define SOC_FFTS_VER_CNT_TH_ADDR(base) ((base) + (0x2204UL))
#define SOC_FFTS_SIG_CNT_TH_ADDR(base) ((base) + (0x2208UL))
#define SOC_FFTS_TASKVER_SIZE_ADDR(base) ((base) + (0x220CUL))
#define SOC_FFTS_SIGHASH_SIZE_ADDR(base) ((base) + (0x2210UL))
#define SOC_FFTS_QUEUE_SIZE_CTRL_ADDR(base) ((base) + (0x2214UL))
#define SOC_FFTS_RTB_INTR_TH_ADDR(base) ((base) + (0x2218UL))
#define SOC_FFTS_TASKIDX_REL_ADDR(base) ((base) + (0x221CUL))
#define SOC_FFTS_VERIDX_REL_ADDR(base) ((base) + (0x2220UL))
#define SOC_FFTS_SIGCNT_UPD_ADDR(base) ((base) + (0x2224UL))
#define SOC_FFTS_TH_RETRY_ADDR(base) ((base) + (0x2228UL))
#define SOC_FFTS_PROC_BLOCK_CTRL_ADDR(base) ((base) + (0x222CUL))
#define SOC_FFTS_PROC_BLOCK_START_ADDR(base) ((base) + (0x2230UL))
#define SOC_FFTS_PROC_CTXCLR_CTRL_ADDR(base) ((base) + (0x2234UL))
#define SOC_FFTS_PROC_BLOCK_DIS_ADDR(base) ((base) + (0x2238UL))
#define SOC_FFTS_PROC_BLOCK_ST_ADDR(base) ((base) + (0x223CUL))
#define SOC_FFTS_HWRTB_PTR_CTRL0_ADDR(base) ((base) + (0x2240UL))
#define SOC_FFTS_HWRTB_PTR_CTRL1_ADDR(base) ((base) + (0x2244UL))
#define SOC_FFTS_CACHE_CMO_CTRL_ADDR(base) ((base) + (0x2248UL))
#define SOC_FFTS_CACHE_CMO_ST_ADDR(base) ((base) + (0x224CUL))
#define SOC_FFTS_EVENT_BLOCK_ADDR(base) ((base) + (0x2250UL))
#define SOC_FFTS_EVENT2RTB_CTRL0_ADDR(base) ((base) + (0x2254UL))
#define SOC_FFTS_EVENT2RTB_CTRL1_ADDR(base) ((base) + (0x2258UL))
#define SOC_FFTS_EVENT2RTB_CTRL2_ADDR(base) ((base) + (0x22FCUL))
#define SOC_FFTS_EVENT2RTB_ST_ADDR(base) ((base) + (0x225CUL))
#define SOC_FFTS_RTB_SERACH_TH_ADDR(base) ((base) + (0x2260UL))
#define SOC_FFTS_BUS_QOS_CTRL_ADDR(base) ((base) + (0x2264UL))
#define SOC_FFTS_SPMEM_CTRL_ADDR(base) ((base) + (0x2268UL))
#define SOC_FFTS_CKG_EXT_CTRL_ADDR(base) ((base) + (0x226CUL))
#define SOC_FFTS_CKG_BYP_CTRL_ADDR(base) ((base) + (0x2270UL))
#define SOC_FFTS_MISC_CTRL_ADDR(base) ((base) + (0x2274UL))
#define SOC_FFTS_MISC_CTRL2_ADDR(base) ((base) + (0x2278UL))
#define SOC_FFTS_MSGMST_CTRL_ADDR(base) ((base) + (0x2280UL))
#define SOC_FFTS_AAE_POWERDOWN_TH_ADDR(base) ((base) + (0x2284UL))
#define SOC_FFTS_TIMEOUT_CTRL_ADDR(base,FFAP1_NUM) ((base) + ((FFAP1_NUM)*4+0x2380UL))
#define SOC_FFTS_REF_TIMER_CTRL_ADDR(base) ((base) + (0x228CUL))
#define SOC_FFTS_ST64BV0_OSTD_CTRL_ADDR(base) ((base) + (0x2290UL))
#define SOC_FFTS_HW_QOS_CTRL_ADDR(base,HW2_NUM) ((base) + ((HW2_NUM)*4+0x2294UL))
#define SOC_FFTS_HW_OSTD_LIMIT0_ADDR(base,HW2_NUM) ((base) + ((HW2_NUM)*4+0x22ACUL))
#define SOC_FFTS_HW_OSTD_LIMIT1_ADDR(base,HW2_NUM) ((base) + ((HW2_NUM)*4+0x22C4UL))
#define SOC_FFTS_HW_QOS_SET_ADDR(base,HW2_NUM) ((base) + ((HW2_NUM)*4+0x22DCUL))
#define SOC_FFTS_TASKIDX_RANGE_ADDR(base) ((base) + (0x22F4UL))
#define SOC_FFTS_SLV_OSTD_CTRL_ADDR(base) ((base) + (0x22F8UL))
#define SOC_FFTS_DFX_TASKCNT_ADDR(base) ((base) + (0x2300UL))
#define SOC_FFTS_DFX_VERCNT_ADDR(base) ((base) + (0x2304UL))
#define SOC_FFTS_DFX_SIGCNT_ADDR(base) ((base) + (0x2308UL))
#define SOC_FFTS_DFX_MSG_OST_ADDR(base) ((base) + (0x230CUL))
#define SOC_FFTS_DFX_DDR_OST_ADDR(base) ((base) + (0x2310UL))
#define SOC_FFTS_DFX_BUSY_ADDR(base) ((base) + (0x2314UL))
#define SOC_FFTS_DFX_UID_SEARCH_CNT_ADDR(base) ((base) + (0x2318UL))
#define SOC_FFTS_DFX_ABNORMAL_ADDR(base) ((base) + (0x231CUL))
#define SOC_FFTS_DFX_OSTD_ADDR(base) ((base) + (0x2320UL))
#define SOC_FFTS_DFX_CMDBUF_VLD_ADDR(base) ((base) + (0x2324UL))
#define SOC_FFTS_TASKIDX_ALLOC_ST_ADDR(base,TIDX_NUM) ((base) + ((TIDX_NUM)*4+0x2328UL))
#define SOC_FFTS_DFX_AAE_PWRCTRL_ADDR(base) ((base) + (0x2338UL))
#define SOC_FFTS_DFX_HW2_TASK_OST_ADDR(base,HW2_NUM) ((base) + ((HW2_NUM)*4+0x233CUL))
#define SOC_FFTS_PMU_EVCNT_ADDR(base,PMU_NUM) ((base) + ((PMU_NUM)*4+0x2400UL))
#define SOC_FFTS_PMU_EVSVR_ADDR(base,PMU_NUM) ((base) + ((PMU_NUM)*4+0x2420UL))
#define SOC_FFTS_PMU_EVTYPE_ADDR(base,PMU_NUM) ((base) + ((PMU_NUM)*4+0x2440UL))
#define SOC_FFTS_PMU_CNTEN_ADDR(base) ((base) + (0x2460UL))
#define SOC_FFTS_PMU_OV_ADDR(base) ((base) + (0x2464UL))
#define SOC_FFTS_PMU_CFG_ADDR(base) ((base) + (0x2468UL))
#define SOC_FFTS_PMU_CAPR_ADDR(base) ((base) + (0x246CUL))
#define SOC_FFTS_PMU_UID_FLT_ADDR(base) ((base) + (0x2470UL))
#define SOC_FFTS_PMU_HWTYPE_FLT_ADDR(base) ((base) + (0x2474UL))
#define SOC_FFTS_PMU_FLT_DDR_ADDR(base) ((base) + (0x2478UL))
#define SOC_FFTS_PMU_TASKFIFO_TH_ADDR(base) ((base) + (0x247CUL))
#define SOC_FFTS_INTR_QOS_HW1_ADDR(base,HW1_NUM) ((base) + ((HW1_NUM)*0x4+0x2560UL))
#define SOC_FFTS_INTR_NRML_MASK_HW1_ADDR(base,HW1_NUM) ((base) + ((HW1_NUM)*0x10+0x2570UL))
#define SOC_FFTS_INTR_NRML_CLR_HW1_ADDR(base,HW1_NUM) ((base) + ((HW1_NUM)*0x10+0x2574UL))
#define SOC_FFTS_INTR_NRML_ST_HW1_ADDR(base,HW1_NUM) ((base) + ((HW1_NUM)*0x10+0x2578UL))
#define SOC_FFTS_INTRQ_NRML_PTR_HW1_ADDR(base,HW1_NUM) ((base) + ((HW1_NUM)*0x10+0x257CUL))
#define SOC_FFTS_INTR_NRML_MASK_ADDR(base) ((base) + (0x2514UL))
#define SOC_FFTS_INTR_NRML_CLR_ADDR(base) ((base) + (0x2518UL))
#define SOC_FFTS_INTR_NRML_ST_ADDR(base) ((base) + (0x251CUL))
#define SOC_FFTS_INTRQ_NRML_PTR_ADDR(base) ((base) + (0x2520UL))
#define SOC_FFTS_INTR_ABNM_MASK_ADDR(base) ((base) + (0x2524UL))
#define SOC_FFTS_INTR_ABNM_CLR_ADDR(base) ((base) + (0x2528UL))
#define SOC_FFTS_INTR_ABNM_ST_ADDR(base) ((base) + (0x252CUL))
#define SOC_FFTS_INTRQ_ABNM_PTR_ADDR(base) ((base) + (0x2530UL))
#define SOC_FFTS_INTRQ_ABNM_MASK_ADDR(base) ((base) + (0x2534UL))
#define SOC_FFTS_INTRQ_ABNM_DFX_ST_ADDR(base) ((base) + (0x2538UL))
#define SOC_FFTS_INTRQ_ABNM_DFX_CLR_ADDR(base) ((base) + (0x253CUL))
#define SOC_FFTS_INTR_DFX_MASK_ADDR(base) ((base) + (0x2540UL))
#define SOC_FFTS_INTR_DFX_ORG_STATUS_ADDR(base) ((base) + (0x2544UL))
#define SOC_FFTS_INTR_DFX_MASK_STATUS_ADDR(base) ((base) + (0x2548UL))
#define SOC_FFTS_INTR_DFX_TYPE_ADDR(base) ((base) + (0x254CUL))
#define SOC_FFTS_INTR_DFX_INFO_ADDR(base) ((base) + (0x2550UL))
#define SOC_FFTS_DEBUG_ADDR_ADDR(base) ((base) + (0x2600UL))
#define SOC_FFTS_DEBUG_RD_EN_ADDR(base) ((base) + (0x2604UL))
#define SOC_FFTS_DEBUG_ST_ADDR(base) ((base) + (0x2608UL))
#define SOC_FFTS_DEBUG_INFO0_ADDR(base) ((base) + (0x260CUL))
#define SOC_FFTS_DEBUG_INFO1_ADDR(base) ((base) + (0x2610UL))
#define SOC_FFTS_DEBUG_INFO2_ADDR(base) ((base) + (0x2614UL))
#define SOC_FFTS_DEBUG_INFO3_ADDR(base) ((base) + (0x2618UL))
#define SOC_FFTS_PERF_RECORD_CTRL_ADDR(base) ((base) + (0x261CUL))
#define SOC_FFTS_PERF_RECORD_INTR_ADDR(base) ((base) + (0x2620UL))
#define SOC_FFTS_PERF_RECORD_WPTR_ADDR(base) ((base) + (0x2624UL))
#define SOC_FFTS_PERF_RECORD_RPTR_ADDR(base) ((base) + (0x2628UL))
#define SOC_FFTS_PERF_RECORD_FLUSH_ADDR(base) ((base) + (0x262CUL))
#define SOC_FFTS_PERF_UID_FLT_ADDR(base) ((base) + (0x2630UL))
#define SOC_FFTS_PERF_TYPE_FLT0_ADDR(base) ((base) + (0x2634UL))
#define SOC_FFTS_PERF_TYPE_FLT1_ADDR(base) ((base) + (0x2638UL))
#define SOC_FFTS_HWRTB_PTR_ADDR(base,HWRTB_NUM) ((base) + ((HWRTB_NUM)*4+0x3000UL))
#define SOC_FFTS_HW_LINK_ST_ADDR(base) ((base) + (0x30CCUL))
#define SOC_FFTS_HWRTB_STATUS_ADDR(base) ((base) + (0x30D0UL))
#define SOC_FFTS_HWRTB_FULL_STATUS_ADDR(base,HW2_NUM) ((base) + ((HW2_NUM)*4+0x30D4UL))
#define SOC_FFTS_REF_TIMER_VAL0_ADDR(base) ((base) + (0x30F0UL))
#define SOC_FFTS_REF_TIMER_VAL1_ADDR(base) ((base) + (0x30F4UL))
#define SOC_FFTS_DFX_FIFO_CNT_ADDR(base) ((base) + (0x30F8UL))
#else
#define SOC_FFTS_INITIAL_CTRL_ADDR(base) ((base) + (0x2000))
#define SOC_FFTS_SR_BACKUP_CTRL_ADDR(base) ((base) + (0x2004))
#define SOC_FFTS_SR_RESUME_CTRL_ADDR(base) ((base) + (0x2008))
#define SOC_FFTS_BASE_H_ADDR(base,ADDR_NUM) ((base) + ((ADDR_NUM)*8+0x2010))
#define SOC_FFTS_BASE_L_ADDR(base,ADDR_NUM) ((base) + ((ADDR_NUM)*8+0x2014))
#define SOC_FFTS_DDR_ATTR_CTRL_ADDR(base,ATTR_NUM) ((base) + ((ATTR_NUM)*4+0x2080))
#define SOC_FFTS_VERSION_ID_ADDR(base) ((base) + (0x20AC))
#define SOC_FFTS_RESERVED_ADDR(base) ((base) + (0x20B0))
#define SOC_FFTS_LPID_MAP_ADDR(base,ACPU_MID_NUM) ((base) + ((ACPU_MID_NUM)*4+0x2100))
#define SOC_FFTS_ISP_MAP_ADDR(base,ISPCPU_MID_NUM) ((base) + ((ISPCPU_MID_NUM)*4+0x2138))
#define SOC_FFTS_MDM_MAP_ADDR(base,MDM_MID_NUM) ((base) + ((MDM_MID_NUM)*4+0x2140))
#define SOC_FFTS_MISC_CPU_MAP0_ADDR(base,MISC_MID_NUM) ((base) + ((MISC_MID_NUM)*4+0x2150))
#define SOC_FFTS_MISC_CPU_MAP1_ADDR(base,MISC_MID_NUM) ((base) + ((MISC_MID_NUM)*4+0x2160))
#define SOC_FFTS_TASK_CNT_TH_ADDR(base) ((base) + (0x2200))
#define SOC_FFTS_VER_CNT_TH_ADDR(base) ((base) + (0x2204))
#define SOC_FFTS_SIG_CNT_TH_ADDR(base) ((base) + (0x2208))
#define SOC_FFTS_TASKVER_SIZE_ADDR(base) ((base) + (0x220C))
#define SOC_FFTS_SIGHASH_SIZE_ADDR(base) ((base) + (0x2210))
#define SOC_FFTS_QUEUE_SIZE_CTRL_ADDR(base) ((base) + (0x2214))
#define SOC_FFTS_RTB_INTR_TH_ADDR(base) ((base) + (0x2218))
#define SOC_FFTS_TASKIDX_REL_ADDR(base) ((base) + (0x221C))
#define SOC_FFTS_VERIDX_REL_ADDR(base) ((base) + (0x2220))
#define SOC_FFTS_SIGCNT_UPD_ADDR(base) ((base) + (0x2224))
#define SOC_FFTS_TH_RETRY_ADDR(base) ((base) + (0x2228))
#define SOC_FFTS_PROC_BLOCK_CTRL_ADDR(base) ((base) + (0x222C))
#define SOC_FFTS_PROC_BLOCK_START_ADDR(base) ((base) + (0x2230))
#define SOC_FFTS_PROC_CTXCLR_CTRL_ADDR(base) ((base) + (0x2234))
#define SOC_FFTS_PROC_BLOCK_DIS_ADDR(base) ((base) + (0x2238))
#define SOC_FFTS_PROC_BLOCK_ST_ADDR(base) ((base) + (0x223C))
#define SOC_FFTS_HWRTB_PTR_CTRL0_ADDR(base) ((base) + (0x2240))
#define SOC_FFTS_HWRTB_PTR_CTRL1_ADDR(base) ((base) + (0x2244))
#define SOC_FFTS_CACHE_CMO_CTRL_ADDR(base) ((base) + (0x2248))
#define SOC_FFTS_CACHE_CMO_ST_ADDR(base) ((base) + (0x224C))
#define SOC_FFTS_EVENT_BLOCK_ADDR(base) ((base) + (0x2250))
#define SOC_FFTS_EVENT2RTB_CTRL0_ADDR(base) ((base) + (0x2254))
#define SOC_FFTS_EVENT2RTB_CTRL1_ADDR(base) ((base) + (0x2258))
#define SOC_FFTS_EVENT2RTB_CTRL2_ADDR(base) ((base) + (0x22FC))
#define SOC_FFTS_EVENT2RTB_ST_ADDR(base) ((base) + (0x225C))
#define SOC_FFTS_RTB_SERACH_TH_ADDR(base) ((base) + (0x2260))
#define SOC_FFTS_BUS_QOS_CTRL_ADDR(base) ((base) + (0x2264))
#define SOC_FFTS_SPMEM_CTRL_ADDR(base) ((base) + (0x2268))
#define SOC_FFTS_CKG_EXT_CTRL_ADDR(base) ((base) + (0x226C))
#define SOC_FFTS_CKG_BYP_CTRL_ADDR(base) ((base) + (0x2270))
#define SOC_FFTS_MISC_CTRL_ADDR(base) ((base) + (0x2274))
#define SOC_FFTS_MISC_CTRL2_ADDR(base) ((base) + (0x2278))
#define SOC_FFTS_MSGMST_CTRL_ADDR(base) ((base) + (0x2280))
#define SOC_FFTS_AAE_POWERDOWN_TH_ADDR(base) ((base) + (0x2284))
#define SOC_FFTS_TIMEOUT_CTRL_ADDR(base,FFAP1_NUM) ((base) + ((FFAP1_NUM)*4+0x2380))
#define SOC_FFTS_REF_TIMER_CTRL_ADDR(base) ((base) + (0x228C))
#define SOC_FFTS_ST64BV0_OSTD_CTRL_ADDR(base) ((base) + (0x2290))
#define SOC_FFTS_HW_QOS_CTRL_ADDR(base,HW2_NUM) ((base) + ((HW2_NUM)*4+0x2294))
#define SOC_FFTS_HW_OSTD_LIMIT0_ADDR(base,HW2_NUM) ((base) + ((HW2_NUM)*4+0x22AC))
#define SOC_FFTS_HW_OSTD_LIMIT1_ADDR(base,HW2_NUM) ((base) + ((HW2_NUM)*4+0x22C4))
#define SOC_FFTS_HW_QOS_SET_ADDR(base,HW2_NUM) ((base) + ((HW2_NUM)*4+0x22DC))
#define SOC_FFTS_TASKIDX_RANGE_ADDR(base) ((base) + (0x22F4))
#define SOC_FFTS_SLV_OSTD_CTRL_ADDR(base) ((base) + (0x22F8))
#define SOC_FFTS_DFX_TASKCNT_ADDR(base) ((base) + (0x2300))
#define SOC_FFTS_DFX_VERCNT_ADDR(base) ((base) + (0x2304))
#define SOC_FFTS_DFX_SIGCNT_ADDR(base) ((base) + (0x2308))
#define SOC_FFTS_DFX_MSG_OST_ADDR(base) ((base) + (0x230C))
#define SOC_FFTS_DFX_DDR_OST_ADDR(base) ((base) + (0x2310))
#define SOC_FFTS_DFX_BUSY_ADDR(base) ((base) + (0x2314))
#define SOC_FFTS_DFX_UID_SEARCH_CNT_ADDR(base) ((base) + (0x2318))
#define SOC_FFTS_DFX_ABNORMAL_ADDR(base) ((base) + (0x231C))
#define SOC_FFTS_DFX_OSTD_ADDR(base) ((base) + (0x2320))
#define SOC_FFTS_DFX_CMDBUF_VLD_ADDR(base) ((base) + (0x2324))
#define SOC_FFTS_TASKIDX_ALLOC_ST_ADDR(base,TIDX_NUM) ((base) + ((TIDX_NUM)*4+0x2328))
#define SOC_FFTS_DFX_AAE_PWRCTRL_ADDR(base) ((base) + (0x2338))
#define SOC_FFTS_DFX_HW2_TASK_OST_ADDR(base,HW2_NUM) ((base) + ((HW2_NUM)*4+0x233C))
#define SOC_FFTS_PMU_EVCNT_ADDR(base,PMU_NUM) ((base) + ((PMU_NUM)*4+0x2400))
#define SOC_FFTS_PMU_EVSVR_ADDR(base,PMU_NUM) ((base) + ((PMU_NUM)*4+0x2420))
#define SOC_FFTS_PMU_EVTYPE_ADDR(base,PMU_NUM) ((base) + ((PMU_NUM)*4+0x2440))
#define SOC_FFTS_PMU_CNTEN_ADDR(base) ((base) + (0x2460))
#define SOC_FFTS_PMU_OV_ADDR(base) ((base) + (0x2464))
#define SOC_FFTS_PMU_CFG_ADDR(base) ((base) + (0x2468))
#define SOC_FFTS_PMU_CAPR_ADDR(base) ((base) + (0x246C))
#define SOC_FFTS_PMU_UID_FLT_ADDR(base) ((base) + (0x2470))
#define SOC_FFTS_PMU_HWTYPE_FLT_ADDR(base) ((base) + (0x2474))
#define SOC_FFTS_PMU_FLT_DDR_ADDR(base) ((base) + (0x2478))
#define SOC_FFTS_PMU_TASKFIFO_TH_ADDR(base) ((base) + (0x247C))
#define SOC_FFTS_INTR_QOS_HW1_ADDR(base,HW1_NUM) ((base) + ((HW1_NUM)*0x4+0x2560))
#define SOC_FFTS_INTR_NRML_MASK_HW1_ADDR(base,HW1_NUM) ((base) + ((HW1_NUM)*0x10+0x2570))
#define SOC_FFTS_INTR_NRML_CLR_HW1_ADDR(base,HW1_NUM) ((base) + ((HW1_NUM)*0x10+0x2574))
#define SOC_FFTS_INTR_NRML_ST_HW1_ADDR(base,HW1_NUM) ((base) + ((HW1_NUM)*0x10+0x2578))
#define SOC_FFTS_INTRQ_NRML_PTR_HW1_ADDR(base,HW1_NUM) ((base) + ((HW1_NUM)*0x10+0x257C))
#define SOC_FFTS_INTR_NRML_MASK_ADDR(base) ((base) + (0x2514))
#define SOC_FFTS_INTR_NRML_CLR_ADDR(base) ((base) + (0x2518))
#define SOC_FFTS_INTR_NRML_ST_ADDR(base) ((base) + (0x251C))
#define SOC_FFTS_INTRQ_NRML_PTR_ADDR(base) ((base) + (0x2520))
#define SOC_FFTS_INTR_ABNM_MASK_ADDR(base) ((base) + (0x2524))
#define SOC_FFTS_INTR_ABNM_CLR_ADDR(base) ((base) + (0x2528))
#define SOC_FFTS_INTR_ABNM_ST_ADDR(base) ((base) + (0x252C))
#define SOC_FFTS_INTRQ_ABNM_PTR_ADDR(base) ((base) + (0x2530))
#define SOC_FFTS_INTRQ_ABNM_MASK_ADDR(base) ((base) + (0x2534))
#define SOC_FFTS_INTRQ_ABNM_DFX_ST_ADDR(base) ((base) + (0x2538))
#define SOC_FFTS_INTRQ_ABNM_DFX_CLR_ADDR(base) ((base) + (0x253C))
#define SOC_FFTS_INTR_DFX_MASK_ADDR(base) ((base) + (0x2540))
#define SOC_FFTS_INTR_DFX_ORG_STATUS_ADDR(base) ((base) + (0x2544))
#define SOC_FFTS_INTR_DFX_MASK_STATUS_ADDR(base) ((base) + (0x2548))
#define SOC_FFTS_INTR_DFX_TYPE_ADDR(base) ((base) + (0x254C))
#define SOC_FFTS_INTR_DFX_INFO_ADDR(base) ((base) + (0x2550))
#define SOC_FFTS_DEBUG_ADDR_ADDR(base) ((base) + (0x2600))
#define SOC_FFTS_DEBUG_RD_EN_ADDR(base) ((base) + (0x2604))
#define SOC_FFTS_DEBUG_ST_ADDR(base) ((base) + (0x2608))
#define SOC_FFTS_DEBUG_INFO0_ADDR(base) ((base) + (0x260C))
#define SOC_FFTS_DEBUG_INFO1_ADDR(base) ((base) + (0x2610))
#define SOC_FFTS_DEBUG_INFO2_ADDR(base) ((base) + (0x2614))
#define SOC_FFTS_DEBUG_INFO3_ADDR(base) ((base) + (0x2618))
#define SOC_FFTS_PERF_RECORD_CTRL_ADDR(base) ((base) + (0x261C))
#define SOC_FFTS_PERF_RECORD_INTR_ADDR(base) ((base) + (0x2620))
#define SOC_FFTS_PERF_RECORD_WPTR_ADDR(base) ((base) + (0x2624))
#define SOC_FFTS_PERF_RECORD_RPTR_ADDR(base) ((base) + (0x2628))
#define SOC_FFTS_PERF_RECORD_FLUSH_ADDR(base) ((base) + (0x262C))
#define SOC_FFTS_PERF_UID_FLT_ADDR(base) ((base) + (0x2630))
#define SOC_FFTS_PERF_TYPE_FLT0_ADDR(base) ((base) + (0x2634))
#define SOC_FFTS_PERF_TYPE_FLT1_ADDR(base) ((base) + (0x2638))
#define SOC_FFTS_HWRTB_PTR_ADDR(base,HWRTB_NUM) ((base) + ((HWRTB_NUM)*4+0x3000))
#define SOC_FFTS_HW_LINK_ST_ADDR(base) ((base) + (0x30CC))
#define SOC_FFTS_HWRTB_STATUS_ADDR(base) ((base) + (0x30D0))
#define SOC_FFTS_HWRTB_FULL_STATUS_ADDR(base,HW2_NUM) ((base) + ((HW2_NUM)*4+0x30D4))
#define SOC_FFTS_REF_TIMER_VAL0_ADDR(base) ((base) + (0x30F0))
#define SOC_FFTS_REF_TIMER_VAL1_ADDR(base) ((base) + (0x30F4))
#define SOC_FFTS_DFX_FIFO_CNT_ADDR(base) ((base) + (0x30F8))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rdytask_read_ptr : 13;
        unsigned int reserved_0 : 3;
        unsigned int rdytask_write_ptr : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_FFTS_RDYTASKQ_PTR_UNION;
#endif
#define SOC_FFTS_RDYTASKQ_PTR_rdytask_read_ptr_START (0)
#define SOC_FFTS_RDYTASKQ_PTR_rdytask_read_ptr_END (12)
#define SOC_FFTS_RDYTASKQ_PTR_rdytask_write_ptr_START (16)
#define SOC_FFTS_RDYTASKQ_PTR_rdytask_write_ptr_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtb_read_ptr : 16;
        unsigned int rtb_read_ptr_succ : 1;
        unsigned int rtb_read_ptr_empty : 1;
        unsigned int rtb_read_ptr_cnt_ovfw : 1;
        unsigned int rtb_read_ptr_uid_block_n : 1;
        unsigned int reserved_0 : 4;
        unsigned int rtb_read_ptr_done : 1;
        unsigned int reserved_1 : 7;
    } reg;
} SOC_FFTS_RTB_READ_ATOMIC_UNION;
#endif
#define SOC_FFTS_RTB_READ_ATOMIC_rtb_read_ptr_START (0)
#define SOC_FFTS_RTB_READ_ATOMIC_rtb_read_ptr_END (15)
#define SOC_FFTS_RTB_READ_ATOMIC_rtb_read_ptr_succ_START (16)
#define SOC_FFTS_RTB_READ_ATOMIC_rtb_read_ptr_succ_END (16)
#define SOC_FFTS_RTB_READ_ATOMIC_rtb_read_ptr_empty_START (17)
#define SOC_FFTS_RTB_READ_ATOMIC_rtb_read_ptr_empty_END (17)
#define SOC_FFTS_RTB_READ_ATOMIC_rtb_read_ptr_cnt_ovfw_START (18)
#define SOC_FFTS_RTB_READ_ATOMIC_rtb_read_ptr_cnt_ovfw_END (18)
#define SOC_FFTS_RTB_READ_ATOMIC_rtb_read_ptr_uid_block_n_START (19)
#define SOC_FFTS_RTB_READ_ATOMIC_rtb_read_ptr_uid_block_n_END (19)
#define SOC_FFTS_RTB_READ_ATOMIC_rtb_read_ptr_done_START (24)
#define SOC_FFTS_RTB_READ_ATOMIC_rtb_read_ptr_done_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sq_read_ptr : 8;
        unsigned int sq_write_ptr : 8;
        unsigned int sync_wait : 1;
        unsigned int sync_error : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_FFTS_TID_INFO_UNION;
#endif
#define SOC_FFTS_TID_INFO_sq_read_ptr_START (0)
#define SOC_FFTS_TID_INFO_sq_read_ptr_END (7)
#define SOC_FFTS_TID_INFO_sq_write_ptr_START (8)
#define SOC_FFTS_TID_INFO_sq_write_ptr_END (15)
#define SOC_FFTS_TID_INFO_sync_wait_START (16)
#define SOC_FFTS_TID_INFO_sync_wait_END (16)
#define SOC_FFTS_TID_INFO_sync_error_START (17)
#define SOC_FFTS_TID_INFO_sync_error_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_qos_en_set : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_FFTS_INTR_WK_SET_UNION;
#endif
#define SOC_FFTS_INTR_WK_SET_intr_qos_en_set_START (0)
#define SOC_FFTS_INTR_WK_SET_intr_qos_en_set_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ffts_doorbell : 32;
    } reg;
} SOC_FFTS_DOORBELL_UNION;
#endif
#define SOC_FFTS_DOORBELL_ffts_doorbell_START (0)
#define SOC_FFTS_DOORBELL_ffts_doorbell_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int task_prealloc0 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FFTS_TASK_PRE_ALLOC0_UNION;
#endif
#define SOC_FFTS_TASK_PRE_ALLOC0_task_prealloc0_START (0)
#define SOC_FFTS_TASK_PRE_ALLOC0_task_prealloc0_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int task_prealloc1 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FFTS_TASK_PRE_ALLOC1_UNION;
#endif
#define SOC_FFTS_TASK_PRE_ALLOC1_task_prealloc1_START (0)
#define SOC_FFTS_TASK_PRE_ALLOC1_task_prealloc1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int taskrequest : 32;
    } reg;
} SOC_FFTS_TASKREQUEST_UNION;
#endif
#define SOC_FFTS_TASKREQUEST_taskrequest_START (0)
#define SOC_FFTS_TASKREQUEST_taskrequest_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int taskrelease : 32;
    } reg;
} SOC_FFTS_TASKRELEASE_UNION;
#endif
#define SOC_FFTS_TASKRELEASE_taskrelease_START (0)
#define SOC_FFTS_TASKRELEASE_taskrelease_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int taskstart : 32;
    } reg;
} SOC_FFTS_TASKSTART_UNION;
#endif
#define SOC_FFTS_TASKSTART_taskstart_START (0)
#define SOC_FFTS_TASKSTART_taskstart_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int taskdone_taskidx : 16;
        unsigned int taskdone_submitcnt : 16;
    } reg;
} SOC_FFTS_TASKDONE_UNION;
#endif
#define SOC_FFTS_TASKDONE_taskdone_taskidx_START (0)
#define SOC_FFTS_TASKDONE_taskdone_taskidx_END (15)
#define SOC_FFTS_TASKDONE_taskdone_submitcnt_START (16)
#define SOC_FFTS_TASKDONE_taskdone_submitcnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int taskexception_taskidx : 16;
        unsigned int taskexception_submitcnt : 16;
    } reg;
} SOC_FFTS_TASKEXCEPTION_UNION;
#endif
#define SOC_FFTS_TASKEXCEPTION_taskexception_taskidx_START (0)
#define SOC_FFTS_TASKEXCEPTION_taskexception_taskidx_END (15)
#define SOC_FFTS_TASKEXCEPTION_taskexception_submitcnt_START (16)
#define SOC_FFTS_TASKEXCEPTION_taskexception_submitcnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int taskcancel_taskidx : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FFTS_TASKCANCEL_UNION;
#endif
#define SOC_FFTS_TASKCANCEL_taskcancel_taskidx_START (0)
#define SOC_FFTS_TASKCANCEL_taskcancel_taskidx_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int task_autorel_taskidx : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FFTS_TASK_AUTO_REL_UNION;
#endif
#define SOC_FFTS_TASK_AUTO_REL_task_autorel_taskidx_START (0)
#define SOC_FFTS_TASK_AUTO_REL_task_autorel_taskidx_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int proc_taskcnt : 32;
    } reg;
} SOC_FFTS_PROC_TASKCNT_UNION;
#endif
#define SOC_FFTS_PROC_TASKCNT_proc_taskcnt_START (0)
#define SOC_FFTS_PROC_TASKCNT_proc_taskcnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int proc_vercnt : 32;
    } reg;
} SOC_FFTS_PROC_VERCNT_UNION;
#endif
#define SOC_FFTS_PROC_VERCNT_proc_vercnt_START (0)
#define SOC_FFTS_PROC_VERCNT_proc_vercnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int proc_sigcnt : 32;
    } reg;
} SOC_FFTS_PROC_SIGCNT_UNION;
#endif
#define SOC_FFTS_PROC_SIGCNT_proc_sigcnt_START (0)
#define SOC_FFTS_PROC_SIGCNT_proc_sigcnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int send_eventid : 10;
        unsigned int send_event_except : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_FFTS_SEND_EVENT_UNION;
#endif
#define SOC_FFTS_SEND_EVENT_send_eventid_START (0)
#define SOC_FFTS_SEND_EVENT_send_eventid_END (9)
#define SOC_FFTS_SEND_EVENT_send_event_except_START (10)
#define SOC_FFTS_SEND_EVENT_send_event_except_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int inital_start : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FFTS_INITIAL_CTRL_UNION;
#endif
#define SOC_FFTS_INITIAL_CTRL_inital_start_START (0)
#define SOC_FFTS_INITIAL_CTRL_inital_start_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sr_backup_start : 1;
        unsigned int sr_backup_finish : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FFTS_SR_BACKUP_CTRL_UNION;
#endif
#define SOC_FFTS_SR_BACKUP_CTRL_sr_backup_start_START (0)
#define SOC_FFTS_SR_BACKUP_CTRL_sr_backup_start_END (0)
#define SOC_FFTS_SR_BACKUP_CTRL_sr_backup_finish_START (1)
#define SOC_FFTS_SR_BACKUP_CTRL_sr_backup_finish_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sr_resume_start : 1;
        unsigned int sr_resume_finish : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FFTS_SR_RESUME_CTRL_UNION;
#endif
#define SOC_FFTS_SR_RESUME_CTRL_sr_resume_start_START (0)
#define SOC_FFTS_SR_RESUME_CTRL_sr_resume_start_END (0)
#define SOC_FFTS_SR_RESUME_CTRL_sr_resume_finish_START (1)
#define SOC_FFTS_SR_RESUME_CTRL_sr_resume_finish_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int base_addr_h : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_FFTS_BASE_H_UNION;
#endif
#define SOC_FFTS_BASE_H_base_addr_h_START (0)
#define SOC_FFTS_BASE_H_base_addr_h_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 7;
        unsigned int base_addr_l : 25;
    } reg;
} SOC_FFTS_BASE_L_UNION;
#endif
#define SOC_FFTS_BASE_L_base_addr_l_START (7)
#define SOC_FFTS_BASE_L_base_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int attr_gid : 6;
        unsigned int attr_schint : 4;
        unsigned int attr_awcache : 4;
        unsigned int attr_arcache : 4;
        unsigned int attr_axdomain : 2;
        unsigned int attr_mpam : 4;
        unsigned int reserved : 8;
    } reg;
} SOC_FFTS_DDR_ATTR_CTRL_UNION;
#endif
#define SOC_FFTS_DDR_ATTR_CTRL_attr_gid_START (0)
#define SOC_FFTS_DDR_ATTR_CTRL_attr_gid_END (5)
#define SOC_FFTS_DDR_ATTR_CTRL_attr_schint_START (6)
#define SOC_FFTS_DDR_ATTR_CTRL_attr_schint_END (9)
#define SOC_FFTS_DDR_ATTR_CTRL_attr_awcache_START (10)
#define SOC_FFTS_DDR_ATTR_CTRL_attr_awcache_END (13)
#define SOC_FFTS_DDR_ATTR_CTRL_attr_arcache_START (14)
#define SOC_FFTS_DDR_ATTR_CTRL_attr_arcache_END (17)
#define SOC_FFTS_DDR_ATTR_CTRL_attr_axdomain_START (18)
#define SOC_FFTS_DDR_ATTR_CTRL_attr_axdomain_END (19)
#define SOC_FFTS_DDR_ATTR_CTRL_attr_mpam_START (20)
#define SOC_FFTS_DDR_ATTR_CTRL_attr_mpam_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ffts_version_id : 32;
    } reg;
} SOC_FFTS_VERSION_ID_UNION;
#endif
#define SOC_FFTS_VERSION_ID_ffts_version_id_START (0)
#define SOC_FFTS_VERSION_ID_ffts_version_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ffts_reserved : 32;
    } reg;
} SOC_FFTS_RESERVED_UNION;
#endif
#define SOC_FFTS_RESERVED_ffts_reserved_START (0)
#define SOC_FFTS_RESERVED_ffts_reserved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lpid_uid_map : 12;
        unsigned int lpid_qos_map : 3;
        unsigned int reserved : 1;
        unsigned int lpid_tid_map : 16;
    } reg;
} SOC_FFTS_LPID_MAP_UNION;
#endif
#define SOC_FFTS_LPID_MAP_lpid_uid_map_START (0)
#define SOC_FFTS_LPID_MAP_lpid_uid_map_END (11)
#define SOC_FFTS_LPID_MAP_lpid_qos_map_START (12)
#define SOC_FFTS_LPID_MAP_lpid_qos_map_END (14)
#define SOC_FFTS_LPID_MAP_lpid_tid_map_START (16)
#define SOC_FFTS_LPID_MAP_lpid_tid_map_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int isp_uid_map : 12;
        unsigned int isp_qos_map : 3;
        unsigned int reserved : 1;
        unsigned int isp_tid_map : 16;
    } reg;
} SOC_FFTS_ISP_MAP_UNION;
#endif
#define SOC_FFTS_ISP_MAP_isp_uid_map_START (0)
#define SOC_FFTS_ISP_MAP_isp_uid_map_END (11)
#define SOC_FFTS_ISP_MAP_isp_qos_map_START (12)
#define SOC_FFTS_ISP_MAP_isp_qos_map_END (14)
#define SOC_FFTS_ISP_MAP_isp_tid_map_START (16)
#define SOC_FFTS_ISP_MAP_isp_tid_map_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mdm_uid_map : 12;
        unsigned int mdm_qos_map : 3;
        unsigned int reserved : 1;
        unsigned int mdm_tid_map : 16;
    } reg;
} SOC_FFTS_MDM_MAP_UNION;
#endif
#define SOC_FFTS_MDM_MAP_mdm_uid_map_START (0)
#define SOC_FFTS_MDM_MAP_mdm_uid_map_END (11)
#define SOC_FFTS_MDM_MAP_mdm_qos_map_START (12)
#define SOC_FFTS_MDM_MAP_mdm_qos_map_END (14)
#define SOC_FFTS_MDM_MAP_mdm_tid_map_START (16)
#define SOC_FFTS_MDM_MAP_mdm_tid_map_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int misc_mid_map : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_FFTS_MISC_CPU_MAP0_UNION;
#endif
#define SOC_FFTS_MISC_CPU_MAP0_misc_mid_map_START (0)
#define SOC_FFTS_MISC_CPU_MAP0_misc_mid_map_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int misc_uid_map : 12;
        unsigned int misc_qos_map : 3;
        unsigned int reserved : 1;
        unsigned int misc_tid_map : 16;
    } reg;
} SOC_FFTS_MISC_CPU_MAP1_UNION;
#endif
#define SOC_FFTS_MISC_CPU_MAP1_misc_uid_map_START (0)
#define SOC_FFTS_MISC_CPU_MAP1_misc_uid_map_END (11)
#define SOC_FFTS_MISC_CPU_MAP1_misc_qos_map_START (12)
#define SOC_FFTS_MISC_CPU_MAP1_misc_qos_map_END (14)
#define SOC_FFTS_MISC_CPU_MAP1_misc_tid_map_START (16)
#define SOC_FFTS_MISC_CPU_MAP1_misc_tid_map_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int taskctx_proc_th : 16;
        unsigned int taskctx_total_th : 16;
    } reg;
} SOC_FFTS_TASK_CNT_TH_UNION;
#endif
#define SOC_FFTS_TASK_CNT_TH_taskctx_proc_th_START (0)
#define SOC_FFTS_TASK_CNT_TH_taskctx_proc_th_END (15)
#define SOC_FFTS_TASK_CNT_TH_taskctx_total_th_START (16)
#define SOC_FFTS_TASK_CNT_TH_taskctx_total_th_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int verctx_proc_th : 16;
        unsigned int verctx_total_th : 16;
    } reg;
} SOC_FFTS_VER_CNT_TH_UNION;
#endif
#define SOC_FFTS_VER_CNT_TH_verctx_proc_th_START (0)
#define SOC_FFTS_VER_CNT_TH_verctx_proc_th_END (15)
#define SOC_FFTS_VER_CNT_TH_verctx_total_th_START (16)
#define SOC_FFTS_VER_CNT_TH_verctx_total_th_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sig_proc_th : 16;
        unsigned int sig_total_th : 16;
    } reg;
} SOC_FFTS_SIG_CNT_TH_UNION;
#endif
#define SOC_FFTS_SIG_CNT_TH_sig_proc_th_START (0)
#define SOC_FFTS_SIG_CNT_TH_sig_proc_th_END (15)
#define SOC_FFTS_SIG_CNT_TH_sig_total_th_START (16)
#define SOC_FFTS_SIG_CNT_TH_sig_total_th_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ver_idx_size : 4;
        unsigned int task_idx_size : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_FFTS_TASKVER_SIZE_UNION;
#endif
#define SOC_FFTS_TASKVER_SIZE_ver_idx_size_START (0)
#define SOC_FFTS_TASKVER_SIZE_ver_idx_size_END (3)
#define SOC_FFTS_TASKVER_SIZE_task_idx_size_START (4)
#define SOC_FFTS_TASKVER_SIZE_task_idx_size_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sighash_size : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_FFTS_SIGHASH_SIZE_UNION;
#endif
#define SOC_FFTS_SIGHASH_SIZE_sighash_size_START (0)
#define SOC_FFTS_SIGHASH_SIZE_sighash_size_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_prtb_size : 3;
        unsigned int reserved_0 : 1;
        unsigned int ddr_sq_size : 2;
        unsigned int reserved_1 : 26;
    } reg;
} SOC_FFTS_QUEUE_SIZE_CTRL_UNION;
#endif
#define SOC_FFTS_QUEUE_SIZE_CTRL_ddr_prtb_size_START (0)
#define SOC_FFTS_QUEUE_SIZE_CTRL_ddr_prtb_size_END (2)
#define SOC_FFTS_QUEUE_SIZE_CTRL_ddr_sq_size_START (4)
#define SOC_FFTS_QUEUE_SIZE_CTRL_ddr_sq_size_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int prtb_intr_th_size : 13;
        unsigned int reserved_0 : 3;
        unsigned int hwrtb_intr_th_size : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_FFTS_RTB_INTR_TH_UNION;
#endif
#define SOC_FFTS_RTB_INTR_TH_prtb_intr_th_size_START (0)
#define SOC_FFTS_RTB_INTR_TH_prtb_intr_th_size_END (12)
#define SOC_FFTS_RTB_INTR_TH_hwrtb_intr_th_size_START (16)
#define SOC_FFTS_RTB_INTR_TH_hwrtb_intr_th_size_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int release_taskidx : 16;
        unsigned int release_taskidx_en : 1;
        unsigned int release_taskidx_idle : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_FFTS_TASKIDX_REL_UNION;
#endif
#define SOC_FFTS_TASKIDX_REL_release_taskidx_START (0)
#define SOC_FFTS_TASKIDX_REL_release_taskidx_END (15)
#define SOC_FFTS_TASKIDX_REL_release_taskidx_en_START (16)
#define SOC_FFTS_TASKIDX_REL_release_taskidx_en_END (16)
#define SOC_FFTS_TASKIDX_REL_release_taskidx_idle_START (17)
#define SOC_FFTS_TASKIDX_REL_release_taskidx_idle_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int release_veridx : 16;
        unsigned int release_veridx_en : 1;
        unsigned int release_veridx_idle : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_FFTS_VERIDX_REL_UNION;
#endif
#define SOC_FFTS_VERIDX_REL_release_veridx_START (0)
#define SOC_FFTS_VERIDX_REL_release_veridx_END (15)
#define SOC_FFTS_VERIDX_REL_release_veridx_en_START (16)
#define SOC_FFTS_VERIDX_REL_release_veridx_en_END (16)
#define SOC_FFTS_VERIDX_REL_release_veridx_idle_START (17)
#define SOC_FFTS_VERIDX_REL_release_veridx_idle_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sigctx_cnt_sub_num : 16;
        unsigned int sigctx_cnt_sub_en : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_FFTS_SIGCNT_UPD_UNION;
#endif
#define SOC_FFTS_SIGCNT_UPD_sigctx_cnt_sub_num_START (0)
#define SOC_FFTS_SIGCNT_UPD_sigctx_cnt_sub_num_END (15)
#define SOC_FFTS_SIGCNT_UPD_sigctx_cnt_sub_en_START (16)
#define SOC_FFTS_SIGCNT_UPD_sigctx_cnt_sub_en_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int retry_tid : 16;
        unsigned int retry_uid : 12;
        unsigned int retry_en : 1;
        unsigned int retry_busy : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_FFTS_TH_RETRY_UNION;
#endif
#define SOC_FFTS_TH_RETRY_retry_tid_START (0)
#define SOC_FFTS_TH_RETRY_retry_tid_END (15)
#define SOC_FFTS_TH_RETRY_retry_uid_START (16)
#define SOC_FFTS_TH_RETRY_retry_uid_END (27)
#define SOC_FFTS_TH_RETRY_retry_en_START (28)
#define SOC_FFTS_TH_RETRY_retry_en_END (28)
#define SOC_FFTS_TH_RETRY_retry_busy_START (29)
#define SOC_FFTS_TH_RETRY_retry_busy_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int proc_block_auto_clean : 1;
        unsigned int reserved_0 : 3;
        unsigned int proc_block_auto_cmo : 2;
        unsigned int reserved_1 : 26;
    } reg;
} SOC_FFTS_PROC_BLOCK_CTRL_UNION;
#endif
#define SOC_FFTS_PROC_BLOCK_CTRL_proc_block_auto_clean_START (0)
#define SOC_FFTS_PROC_BLOCK_CTRL_proc_block_auto_clean_END (0)
#define SOC_FFTS_PROC_BLOCK_CTRL_proc_block_auto_cmo_START (4)
#define SOC_FFTS_PROC_BLOCK_CTRL_proc_block_auto_cmo_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int proc_block_en : 1;
        unsigned int proc_block_hwtype2_en : 4;
        unsigned int reserved_0 : 11;
        unsigned int proc_block_uid : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_FFTS_PROC_BLOCK_START_UNION;
#endif
#define SOC_FFTS_PROC_BLOCK_START_proc_block_en_START (0)
#define SOC_FFTS_PROC_BLOCK_START_proc_block_en_END (0)
#define SOC_FFTS_PROC_BLOCK_START_proc_block_hwtype2_en_START (1)
#define SOC_FFTS_PROC_BLOCK_START_proc_block_hwtype2_en_END (4)
#define SOC_FFTS_PROC_BLOCK_START_proc_block_uid_START (16)
#define SOC_FFTS_PROC_BLOCK_START_proc_block_uid_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int proc_block_ctxclr_en : 1;
        unsigned int proc_bucket_clear_en : 1;
        unsigned int reserved_0 : 6;
        unsigned int proc_block_ctxclr_state : 8;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_FFTS_PROC_CTXCLR_CTRL_UNION;
#endif
#define SOC_FFTS_PROC_CTXCLR_CTRL_proc_block_ctxclr_en_START (0)
#define SOC_FFTS_PROC_CTXCLR_CTRL_proc_block_ctxclr_en_END (0)
#define SOC_FFTS_PROC_CTXCLR_CTRL_proc_bucket_clear_en_START (1)
#define SOC_FFTS_PROC_CTXCLR_CTRL_proc_bucket_clear_en_END (1)
#define SOC_FFTS_PROC_CTXCLR_CTRL_proc_block_ctxclr_state_START (8)
#define SOC_FFTS_PROC_CTXCLR_CTRL_proc_block_ctxclr_state_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int proc_block_dis : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FFTS_PROC_BLOCK_DIS_UNION;
#endif
#define SOC_FFTS_PROC_BLOCK_DIS_proc_block_dis_START (0)
#define SOC_FFTS_PROC_BLOCK_DIS_proc_block_dis_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int proc_block_state : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_FFTS_PROC_BLOCK_ST_UNION;
#endif
#define SOC_FFTS_PROC_BLOCK_ST_proc_block_state_START (0)
#define SOC_FFTS_PROC_BLOCK_ST_proc_block_state_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwrtb_set_wptr : 12;
        unsigned int hwrtb_set_wptr_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int hwrtb_set_rptr : 12;
        unsigned int hwrtb_set_rptr_en : 1;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_FFTS_HWRTB_PTR_CTRL0_UNION;
#endif
#define SOC_FFTS_HWRTB_PTR_CTRL0_hwrtb_set_wptr_START (0)
#define SOC_FFTS_HWRTB_PTR_CTRL0_hwrtb_set_wptr_END (11)
#define SOC_FFTS_HWRTB_PTR_CTRL0_hwrtb_set_wptr_en_START (12)
#define SOC_FFTS_HWRTB_PTR_CTRL0_hwrtb_set_wptr_en_END (12)
#define SOC_FFTS_HWRTB_PTR_CTRL0_hwrtb_set_rptr_START (16)
#define SOC_FFTS_HWRTB_PTR_CTRL0_hwrtb_set_rptr_END (27)
#define SOC_FFTS_HWRTB_PTR_CTRL0_hwrtb_set_rptr_en_START (28)
#define SOC_FFTS_HWRTB_PTR_CTRL0_hwrtb_set_rptr_en_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwrtb_set_hwtype : 6;
        unsigned int hwrtb_set_qos : 3;
        unsigned int hwrtb_set_full_status : 8;
        unsigned int hwrtb_set_status : 2;
        unsigned int hwrtb_set_status_en : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_FFTS_HWRTB_PTR_CTRL1_UNION;
#endif
#define SOC_FFTS_HWRTB_PTR_CTRL1_hwrtb_set_hwtype_START (0)
#define SOC_FFTS_HWRTB_PTR_CTRL1_hwrtb_set_hwtype_END (5)
#define SOC_FFTS_HWRTB_PTR_CTRL1_hwrtb_set_qos_START (6)
#define SOC_FFTS_HWRTB_PTR_CTRL1_hwrtb_set_qos_END (8)
#define SOC_FFTS_HWRTB_PTR_CTRL1_hwrtb_set_full_status_START (9)
#define SOC_FFTS_HWRTB_PTR_CTRL1_hwrtb_set_full_status_END (16)
#define SOC_FFTS_HWRTB_PTR_CTRL1_hwrtb_set_status_START (17)
#define SOC_FFTS_HWRTB_PTR_CTRL1_hwrtb_set_status_END (18)
#define SOC_FFTS_HWRTB_PTR_CTRL1_hwrtb_set_status_en_START (19)
#define SOC_FFTS_HWRTB_PTR_CTRL1_hwrtb_set_status_en_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cache_flush_start : 1;
        unsigned int cache_flush_type : 15;
        unsigned int cache_flush_uid : 12;
        unsigned int reserved : 4;
    } reg;
} SOC_FFTS_CACHE_CMO_CTRL_UNION;
#endif
#define SOC_FFTS_CACHE_CMO_CTRL_cache_flush_start_START (0)
#define SOC_FFTS_CACHE_CMO_CTRL_cache_flush_start_END (0)
#define SOC_FFTS_CACHE_CMO_CTRL_cache_flush_type_START (1)
#define SOC_FFTS_CACHE_CMO_CTRL_cache_flush_type_END (15)
#define SOC_FFTS_CACHE_CMO_CTRL_cache_flush_uid_START (16)
#define SOC_FFTS_CACHE_CMO_CTRL_cache_flush_uid_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cache_flush_finish : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FFTS_CACHE_CMO_ST_UNION;
#endif
#define SOC_FFTS_CACHE_CMO_ST_cache_flush_finish_START (0)
#define SOC_FFTS_CACHE_CMO_ST_cache_flush_finish_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hw_event_block_en : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FFTS_EVENT_BLOCK_UNION;
#endif
#define SOC_FFTS_EVENT_BLOCK_hw_event_block_en_START (0)
#define SOC_FFTS_EVENT_BLOCK_hw_event_block_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event2rtb_taskidx : 16;
        unsigned int event2rtb_uid : 12;
        unsigned int event2rtb_qos : 3;
        unsigned int event2rtb_en : 1;
    } reg;
} SOC_FFTS_EVENT2RTB_CTRL0_UNION;
#endif
#define SOC_FFTS_EVENT2RTB_CTRL0_event2rtb_taskidx_START (0)
#define SOC_FFTS_EVENT2RTB_CTRL0_event2rtb_taskidx_END (15)
#define SOC_FFTS_EVENT2RTB_CTRL0_event2rtb_uid_START (16)
#define SOC_FFTS_EVENT2RTB_CTRL0_event2rtb_uid_END (27)
#define SOC_FFTS_EVENT2RTB_CTRL0_event2rtb_qos_START (28)
#define SOC_FFTS_EVENT2RTB_CTRL0_event2rtb_qos_END (30)
#define SOC_FFTS_EVENT2RTB_CTRL0_event2rtb_en_START (31)
#define SOC_FFTS_EVENT2RTB_CTRL0_event2rtb_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event2rtb_funcptr_32_38 : 7;
        unsigned int event2rtb_userbits : 1;
        unsigned int event2rtb_errprocess : 1;
        unsigned int event2rtb_hwtype : 6;
        unsigned int event2rtb_opcode : 3;
        unsigned int event2rtb_pathtype : 3;
        unsigned int event2rtb_blk_ignore : 1;
        unsigned int reserved : 10;
    } reg;
} SOC_FFTS_EVENT2RTB_CTRL1_UNION;
#endif
#define SOC_FFTS_EVENT2RTB_CTRL1_event2rtb_funcptr_32_38_START (0)
#define SOC_FFTS_EVENT2RTB_CTRL1_event2rtb_funcptr_32_38_END (6)
#define SOC_FFTS_EVENT2RTB_CTRL1_event2rtb_userbits_START (7)
#define SOC_FFTS_EVENT2RTB_CTRL1_event2rtb_userbits_END (7)
#define SOC_FFTS_EVENT2RTB_CTRL1_event2rtb_errprocess_START (8)
#define SOC_FFTS_EVENT2RTB_CTRL1_event2rtb_errprocess_END (8)
#define SOC_FFTS_EVENT2RTB_CTRL1_event2rtb_hwtype_START (9)
#define SOC_FFTS_EVENT2RTB_CTRL1_event2rtb_hwtype_END (14)
#define SOC_FFTS_EVENT2RTB_CTRL1_event2rtb_opcode_START (15)
#define SOC_FFTS_EVENT2RTB_CTRL1_event2rtb_opcode_END (17)
#define SOC_FFTS_EVENT2RTB_CTRL1_event2rtb_pathtype_START (18)
#define SOC_FFTS_EVENT2RTB_CTRL1_event2rtb_pathtype_END (20)
#define SOC_FFTS_EVENT2RTB_CTRL1_event2rtb_blk_ignore_START (21)
#define SOC_FFTS_EVENT2RTB_CTRL1_event2rtb_blk_ignore_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event2rtb_funcptr_0_31 : 32;
    } reg;
} SOC_FFTS_EVENT2RTB_CTRL2_UNION;
#endif
#define SOC_FFTS_EVENT2RTB_CTRL2_event2rtb_funcptr_0_31_START (0)
#define SOC_FFTS_EVENT2RTB_CTRL2_event2rtb_funcptr_0_31_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event2rtb_done : 1;
        unsigned int event2rtb_succ : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FFTS_EVENT2RTB_ST_UNION;
#endif
#define SOC_FFTS_EVENT2RTB_ST_event2rtb_done_START (0)
#define SOC_FFTS_EVENT2RTB_ST_event2rtb_done_END (0)
#define SOC_FFTS_EVENT2RTB_ST_event2rtb_succ_START (1)
#define SOC_FFTS_EVENT2RTB_ST_event2rtb_succ_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwrtb_search_th : 13;
        unsigned int reserved_0 : 3;
        unsigned int prtb_search_th : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_FFTS_RTB_SERACH_TH_UNION;
#endif
#define SOC_FFTS_RTB_SERACH_TH_hwrtb_search_th_START (0)
#define SOC_FFTS_RTB_SERACH_TH_hwrtb_search_th_END (12)
#define SOC_FFTS_RTB_SERACH_TH_prtb_search_th_START (16)
#define SOC_FFTS_RTB_SERACH_TH_prtb_search_th_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int msgmst_qos : 3;
        unsigned int ddrmst_qos : 3;
        unsigned int reserved : 26;
    } reg;
} SOC_FFTS_BUS_QOS_CTRL_UNION;
#endif
#define SOC_FFTS_BUS_QOS_CTRL_msgmst_qos_START (0)
#define SOC_FFTS_BUS_QOS_CTRL_msgmst_qos_END (2)
#define SOC_FFTS_BUS_QOS_CTRL_ddrmst_qos_START (3)
#define SOC_FFTS_BUS_QOS_CTRL_ddrmst_qos_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_s : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_FFTS_SPMEM_CTRL_UNION;
#endif
#define SOC_FFTS_SPMEM_CTRL_mem_ctrl_s_START (0)
#define SOC_FFTS_SPMEM_CTRL_mem_ctrl_s_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ckg_ctrl_ext : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_FFTS_CKG_EXT_CTRL_UNION;
#endif
#define SOC_FFTS_CKG_EXT_CTRL_ckg_ctrl_ext_START (0)
#define SOC_FFTS_CKG_EXT_CTRL_ckg_ctrl_ext_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ckg_ctrl_byp : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_FFTS_CKG_BYP_CTRL_UNION;
#endif
#define SOC_FFTS_CKG_BYP_CTRL_ckg_ctrl_byp_START (0)
#define SOC_FFTS_CKG_BYP_CTRL_ckg_ctrl_byp_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int taskstart_dis_th : 5;
        unsigned int task_release_dis : 1;
        unsigned int reserved_0 : 2;
        unsigned int event_dstid_chkbyp : 1;
        unsigned int bucket_dis : 1;
        unsigned int submitctx_chkbyp : 1;
        unsigned int taskx_ctx_chkbyp : 1;
        unsigned int chain_search_max : 4;
        unsigned int st64_submit_intrq_en : 1;
        unsigned int reserved_1 : 15;
    } reg;
} SOC_FFTS_MISC_CTRL_UNION;
#endif
#define SOC_FFTS_MISC_CTRL_taskstart_dis_th_START (0)
#define SOC_FFTS_MISC_CTRL_taskstart_dis_th_END (4)
#define SOC_FFTS_MISC_CTRL_task_release_dis_START (5)
#define SOC_FFTS_MISC_CTRL_task_release_dis_END (5)
#define SOC_FFTS_MISC_CTRL_event_dstid_chkbyp_START (8)
#define SOC_FFTS_MISC_CTRL_event_dstid_chkbyp_END (8)
#define SOC_FFTS_MISC_CTRL_bucket_dis_START (9)
#define SOC_FFTS_MISC_CTRL_bucket_dis_END (9)
#define SOC_FFTS_MISC_CTRL_submitctx_chkbyp_START (10)
#define SOC_FFTS_MISC_CTRL_submitctx_chkbyp_END (10)
#define SOC_FFTS_MISC_CTRL_taskx_ctx_chkbyp_START (11)
#define SOC_FFTS_MISC_CTRL_taskx_ctx_chkbyp_END (11)
#define SOC_FFTS_MISC_CTRL_chain_search_max_START (12)
#define SOC_FFTS_MISC_CTRL_chain_search_max_END (15)
#define SOC_FFTS_MISC_CTRL_st64_submit_intrq_en_START (16)
#define SOC_FFTS_MISC_CTRL_st64_submit_intrq_en_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sigq_para_dis : 1;
        unsigned int taskq_para_dis : 1;
        unsigned int sync_opt_en : 1;
        unsigned int task_search_perf_en : 1;
        unsigned int task_clr_perf_en : 1;
        unsigned int thctx_use_64b_en : 1;
        unsigned int procctx_use_64b_en : 1;
        unsigned int cfgslv_mid_hazard_en : 1;
        unsigned int sigcache_bypass : 2;
        unsigned int vercache_bypass : 2;
        unsigned int taskcache_bypass : 2;
        unsigned int thcache_para_dis : 1;
        unsigned int proccache_para_dis : 1;
        unsigned int submitrecv_npd_dis : 1;
        unsigned int aae_powerctrl_dis : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_FFTS_MISC_CTRL2_UNION;
#endif
#define SOC_FFTS_MISC_CTRL2_sigq_para_dis_START (0)
#define SOC_FFTS_MISC_CTRL2_sigq_para_dis_END (0)
#define SOC_FFTS_MISC_CTRL2_taskq_para_dis_START (1)
#define SOC_FFTS_MISC_CTRL2_taskq_para_dis_END (1)
#define SOC_FFTS_MISC_CTRL2_sync_opt_en_START (2)
#define SOC_FFTS_MISC_CTRL2_sync_opt_en_END (2)
#define SOC_FFTS_MISC_CTRL2_task_search_perf_en_START (3)
#define SOC_FFTS_MISC_CTRL2_task_search_perf_en_END (3)
#define SOC_FFTS_MISC_CTRL2_task_clr_perf_en_START (4)
#define SOC_FFTS_MISC_CTRL2_task_clr_perf_en_END (4)
#define SOC_FFTS_MISC_CTRL2_thctx_use_64b_en_START (5)
#define SOC_FFTS_MISC_CTRL2_thctx_use_64b_en_END (5)
#define SOC_FFTS_MISC_CTRL2_procctx_use_64b_en_START (6)
#define SOC_FFTS_MISC_CTRL2_procctx_use_64b_en_END (6)
#define SOC_FFTS_MISC_CTRL2_cfgslv_mid_hazard_en_START (7)
#define SOC_FFTS_MISC_CTRL2_cfgslv_mid_hazard_en_END (7)
#define SOC_FFTS_MISC_CTRL2_sigcache_bypass_START (8)
#define SOC_FFTS_MISC_CTRL2_sigcache_bypass_END (9)
#define SOC_FFTS_MISC_CTRL2_vercache_bypass_START (10)
#define SOC_FFTS_MISC_CTRL2_vercache_bypass_END (11)
#define SOC_FFTS_MISC_CTRL2_taskcache_bypass_START (12)
#define SOC_FFTS_MISC_CTRL2_taskcache_bypass_END (13)
#define SOC_FFTS_MISC_CTRL2_thcache_para_dis_START (14)
#define SOC_FFTS_MISC_CTRL2_thcache_para_dis_END (14)
#define SOC_FFTS_MISC_CTRL2_proccache_para_dis_START (15)
#define SOC_FFTS_MISC_CTRL2_proccache_para_dis_END (15)
#define SOC_FFTS_MISC_CTRL2_submitrecv_npd_dis_START (16)
#define SOC_FFTS_MISC_CTRL2_submitrecv_npd_dis_END (16)
#define SOC_FFTS_MISC_CTRL2_aae_powerctrl_dis_START (17)
#define SOC_FFTS_MISC_CTRL2_aae_powerctrl_dis_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int msgmst_bp_th : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_FFTS_MSGMST_CTRL_UNION;
#endif
#define SOC_FFTS_MSGMST_CTRL_msgmst_bp_th_START (0)
#define SOC_FFTS_MSGMST_CTRL_msgmst_bp_th_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aae_powerdown_th : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_FFTS_AAE_POWERDOWN_TH_UNION;
#endif
#define SOC_FFTS_AAE_POWERDOWN_TH_aae_powerdown_th_START (0)
#define SOC_FFTS_AAE_POWERDOWN_TH_aae_powerdown_th_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ffap1_timeout_th : 32;
    } reg;
} SOC_FFTS_TIMEOUT_CTRL_UNION;
#endif
#define SOC_FFTS_TIMEOUT_CTRL_ffap1_timeout_th_START (0)
#define SOC_FFTS_TIMEOUT_CTRL_ffap1_timeout_th_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ref_timer_en : 1;
        unsigned int ref_timer_clr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FFTS_REF_TIMER_CTRL_UNION;
#endif
#define SOC_FFTS_REF_TIMER_CTRL_ref_timer_en_START (0)
#define SOC_FFTS_REF_TIMER_CTRL_ref_timer_en_END (0)
#define SOC_FFTS_REF_TIMER_CTRL_ref_timer_clr_START (1)
#define SOC_FFTS_REF_TIMER_CTRL_ref_timer_clr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st64b_ostd_th : 4;
        unsigned int dbell_cmdbuf_th : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_FFTS_ST64BV0_OSTD_CTRL_UNION;
#endif
#define SOC_FFTS_ST64BV0_OSTD_CTRL_st64b_ostd_th_START (0)
#define SOC_FFTS_ST64BV0_OSTD_CTRL_st64b_ostd_th_END (3)
#define SOC_FFTS_ST64BV0_OSTD_CTRL_dbell_cmdbuf_th_START (4)
#define SOC_FFTS_ST64BV0_OSTD_CTRL_dbell_cmdbuf_th_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hw2_qos_remap : 24;
        unsigned int hw2_qos_policy : 2;
        unsigned int reserved : 6;
    } reg;
} SOC_FFTS_HW_QOS_CTRL_UNION;
#endif
#define SOC_FFTS_HW_QOS_CTRL_hw2_qos_remap_START (0)
#define SOC_FFTS_HW_QOS_CTRL_hw2_qos_remap_END (23)
#define SOC_FFTS_HW_QOS_CTRL_hw2_qos_policy_START (24)
#define SOC_FFTS_HW_QOS_CTRL_hw2_qos_policy_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hw2_ostd_permit_qos3 : 6;
        unsigned int hw2_ostd_permit_qos2 : 6;
        unsigned int hw2_ostd_permit_qos1 : 6;
        unsigned int hw2_ostd_permit_qos0 : 6;
        unsigned int reserved : 8;
    } reg;
} SOC_FFTS_HW_OSTD_LIMIT0_UNION;
#endif
#define SOC_FFTS_HW_OSTD_LIMIT0_hw2_ostd_permit_qos3_START (0)
#define SOC_FFTS_HW_OSTD_LIMIT0_hw2_ostd_permit_qos3_END (5)
#define SOC_FFTS_HW_OSTD_LIMIT0_hw2_ostd_permit_qos2_START (6)
#define SOC_FFTS_HW_OSTD_LIMIT0_hw2_ostd_permit_qos2_END (11)
#define SOC_FFTS_HW_OSTD_LIMIT0_hw2_ostd_permit_qos1_START (12)
#define SOC_FFTS_HW_OSTD_LIMIT0_hw2_ostd_permit_qos1_END (17)
#define SOC_FFTS_HW_OSTD_LIMIT0_hw2_ostd_permit_qos0_START (18)
#define SOC_FFTS_HW_OSTD_LIMIT0_hw2_ostd_permit_qos0_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hw2_ostd_permit_qos7 : 6;
        unsigned int hw2_ostd_permit_qos6 : 6;
        unsigned int hw2_ostd_permit_qos5 : 6;
        unsigned int hw2_ostd_permit_qos4 : 6;
        unsigned int reserved : 8;
    } reg;
} SOC_FFTS_HW_OSTD_LIMIT1_UNION;
#endif
#define SOC_FFTS_HW_OSTD_LIMIT1_hw2_ostd_permit_qos7_START (0)
#define SOC_FFTS_HW_OSTD_LIMIT1_hw2_ostd_permit_qos7_END (5)
#define SOC_FFTS_HW_OSTD_LIMIT1_hw2_ostd_permit_qos6_START (6)
#define SOC_FFTS_HW_OSTD_LIMIT1_hw2_ostd_permit_qos6_END (11)
#define SOC_FFTS_HW_OSTD_LIMIT1_hw2_ostd_permit_qos5_START (12)
#define SOC_FFTS_HW_OSTD_LIMIT1_hw2_ostd_permit_qos5_END (17)
#define SOC_FFTS_HW_OSTD_LIMIT1_hw2_ostd_permit_qos4_START (18)
#define SOC_FFTS_HW_OSTD_LIMIT1_hw2_ostd_permit_qos4_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hw2_ostd_set_val : 6;
        unsigned int hw2_ostd_set_en : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_FFTS_HW_QOS_SET_UNION;
#endif
#define SOC_FFTS_HW_QOS_SET_hw2_ostd_set_val_START (0)
#define SOC_FFTS_HW_QOS_SET_hw2_ostd_set_val_END (5)
#define SOC_FFTS_HW_QOS_SET_hw2_ostd_set_en_START (6)
#define SOC_FFTS_HW_QOS_SET_hw2_ostd_set_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int taskidx_range_0 : 7;
        unsigned int reserved_0 : 1;
        unsigned int taskidx_range_1 : 7;
        unsigned int reserved_1 : 17;
    } reg;
} SOC_FFTS_TASKIDX_RANGE_UNION;
#endif
#define SOC_FFTS_TASKIDX_RANGE_taskidx_range_0_START (0)
#define SOC_FFTS_TASKIDX_RANGE_taskidx_range_0_END (6)
#define SOC_FFTS_TASKIDX_RANGE_taskidx_range_1_START (8)
#define SOC_FFTS_TASKIDX_RANGE_taskidx_range_1_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfgslv_cc_ostd_th : 6;
        unsigned int cfgslv_acpu_ostd_th : 6;
        unsigned int reserved : 20;
    } reg;
} SOC_FFTS_SLV_OSTD_CTRL_UNION;
#endif
#define SOC_FFTS_SLV_OSTD_CTRL_cfgslv_cc_ostd_th_START (0)
#define SOC_FFTS_SLV_OSTD_CTRL_cfgslv_cc_ostd_th_END (5)
#define SOC_FFTS_SLV_OSTD_CTRL_cfgslv_acpu_ostd_th_START (6)
#define SOC_FFTS_SLV_OSTD_CTRL_cfgslv_acpu_ostd_th_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int taskctx_cnt : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_FFTS_DFX_TASKCNT_UNION;
#endif
#define SOC_FFTS_DFX_TASKCNT_taskctx_cnt_START (0)
#define SOC_FFTS_DFX_TASKCNT_taskctx_cnt_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int verctx_cnt : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_FFTS_DFX_VERCNT_UNION;
#endif
#define SOC_FFTS_DFX_VERCNT_verctx_cnt_START (0)
#define SOC_FFTS_DFX_VERCNT_verctx_cnt_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sigctx_cnt : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_FFTS_DFX_SIGCNT_UNION;
#endif
#define SOC_FFTS_DFX_SIGCNT_sigctx_cnt_START (0)
#define SOC_FFTS_DFX_SIGCNT_sigctx_cnt_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int msg_ost_total : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_FFTS_DFX_MSG_OST_UNION;
#endif
#define SOC_FFTS_DFX_MSG_OST_msg_ost_total_START (0)
#define SOC_FFTS_DFX_MSG_OST_msg_ost_total_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_ost_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_FFTS_DFX_DDR_OST_UNION;
#endif
#define SOC_FFTS_DFX_DDR_OST_ddr_ost_cnt_START (0)
#define SOC_FFTS_DFX_DDR_OST_ddr_ost_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ffts_dfx_busy : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_FFTS_DFX_BUSY_UNION;
#endif
#define SOC_FFTS_DFX_BUSY_ffts_dfx_busy_START (0)
#define SOC_FFTS_DFX_BUSY_ffts_dfx_busy_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_search_uid_cnt : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_FFTS_DFX_UID_SEARCH_CNT_UNION;
#endif
#define SOC_FFTS_DFX_UID_SEARCH_CNT_dfx_search_uid_cnt_START (0)
#define SOC_FFTS_DFX_UID_SEARCH_CNT_dfx_search_uid_cnt_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_abnm_ctrl_state : 8;
        unsigned int dfx_sync_state : 16;
        unsigned int reserved : 8;
    } reg;
} SOC_FFTS_DFX_ABNORMAL_UNION;
#endif
#define SOC_FFTS_DFX_ABNORMAL_dfx_abnm_ctrl_state_START (0)
#define SOC_FFTS_DFX_ABNORMAL_dfx_abnm_ctrl_state_END (7)
#define SOC_FFTS_DFX_ABNORMAL_dfx_sync_state_START (8)
#define SOC_FFTS_DFX_ABNORMAL_dfx_sync_state_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_st64b_ostd : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_FFTS_DFX_OSTD_UNION;
#endif
#define SOC_FFTS_DFX_OSTD_dfx_st64b_ostd_START (0)
#define SOC_FFTS_DFX_OSTD_dfx_st64b_ostd_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_sqbuf_vld : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_FFTS_DFX_CMDBUF_VLD_UNION;
#endif
#define SOC_FFTS_DFX_CMDBUF_VLD_dfx_sqbuf_vld_START (0)
#define SOC_FFTS_DFX_CMDBUF_VLD_dfx_sqbuf_vld_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int taskidx_used_st : 32;
    } reg;
} SOC_FFTS_TASKIDX_ALLOC_ST_UNION;
#endif
#define SOC_FFTS_TASKIDX_ALLOC_ST_taskidx_used_st_START (0)
#define SOC_FFTS_TASKIDX_ALLOC_ST_taskidx_used_st_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_aae_power_info : 16;
        unsigned int aae_power_st_up : 1;
        unsigned int aae_power_st_dn : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_FFTS_DFX_AAE_PWRCTRL_UNION;
#endif
#define SOC_FFTS_DFX_AAE_PWRCTRL_dfx_aae_power_info_START (0)
#define SOC_FFTS_DFX_AAE_PWRCTRL_dfx_aae_power_info_END (15)
#define SOC_FFTS_DFX_AAE_PWRCTRL_aae_power_st_up_START (16)
#define SOC_FFTS_DFX_AAE_PWRCTRL_aae_power_st_up_END (16)
#define SOC_FFTS_DFX_AAE_PWRCTRL_aae_power_st_dn_START (17)
#define SOC_FFTS_DFX_AAE_PWRCTRL_aae_power_st_dn_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_hwtype_task_ostd : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_FFTS_DFX_HW2_TASK_OST_UNION;
#endif
#define SOC_FFTS_DFX_HW2_TASK_OST_dfx_hwtype_task_ostd_START (0)
#define SOC_FFTS_DFX_HW2_TASK_OST_dfx_hwtype_task_ostd_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_evcnt : 32;
    } reg;
} SOC_FFTS_PMU_EVCNT_UNION;
#endif
#define SOC_FFTS_PMU_EVCNT_pmu_evcnt_START (0)
#define SOC_FFTS_PMU_EVCNT_pmu_evcnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_evsvr : 32;
    } reg;
} SOC_FFTS_PMU_EVSVR_UNION;
#endif
#define SOC_FFTS_PMU_EVSVR_pmu_evsvr_START (0)
#define SOC_FFTS_PMU_EVSVR_pmu_evsvr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_evtype : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_FFTS_PMU_EVTYPE_UNION;
#endif
#define SOC_FFTS_PMU_EVTYPE_pmu_evtype_START (0)
#define SOC_FFTS_PMU_EVTYPE_pmu_evtype_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_cnten : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_FFTS_PMU_CNTEN_UNION;
#endif
#define SOC_FFTS_PMU_CNTEN_pmu_cnten_START (0)
#define SOC_FFTS_PMU_CNTEN_pmu_cnten_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_overflow : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_FFTS_PMU_OV_UNION;
#endif
#define SOC_FFTS_PMU_OV_pmu_overflow_START (0)
#define SOC_FFTS_PMU_OV_pmu_overflow_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_en : 1;
        unsigned int pmu_ovcap_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FFTS_PMU_CFG_UNION;
#endif
#define SOC_FFTS_PMU_CFG_pmu_en_START (0)
#define SOC_FFTS_PMU_CFG_pmu_en_END (0)
#define SOC_FFTS_PMU_CFG_pmu_ovcap_en_START (1)
#define SOC_FFTS_PMU_CFG_pmu_ovcap_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_cap : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FFTS_PMU_CAPR_UNION;
#endif
#define SOC_FFTS_PMU_CAPR_pmu_cap_START (0)
#define SOC_FFTS_PMU_CAPR_pmu_cap_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_flt_uid_val : 12;
        unsigned int pmu_flt_uid_mask : 12;
        unsigned int reserved : 8;
    } reg;
} SOC_FFTS_PMU_UID_FLT_UNION;
#endif
#define SOC_FFTS_PMU_UID_FLT_pmu_flt_uid_val_START (0)
#define SOC_FFTS_PMU_UID_FLT_pmu_flt_uid_val_END (11)
#define SOC_FFTS_PMU_UID_FLT_pmu_flt_uid_mask_START (12)
#define SOC_FFTS_PMU_UID_FLT_pmu_flt_uid_mask_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_flt_hwtype3 : 16;
        unsigned int pmu_flt_hwtype2 : 6;
        unsigned int reserved : 10;
    } reg;
} SOC_FFTS_PMU_HWTYPE_FLT_UNION;
#endif
#define SOC_FFTS_PMU_HWTYPE_FLT_pmu_flt_hwtype3_START (0)
#define SOC_FFTS_PMU_HWTYPE_FLT_pmu_flt_hwtype3_END (15)
#define SOC_FFTS_PMU_HWTYPE_FLT_pmu_flt_hwtype2_START (16)
#define SOC_FFTS_PMU_HWTYPE_FLT_pmu_flt_hwtype2_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_flt_ddr_en : 22;
        unsigned int reserved : 10;
    } reg;
} SOC_FFTS_PMU_FLT_DDR_UNION;
#endif
#define SOC_FFTS_PMU_FLT_DDR_pmu_flt_ddr_en_START (0)
#define SOC_FFTS_PMU_FLT_DDR_pmu_flt_ddr_en_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_taskfifo_th0 : 8;
        unsigned int pmu_taskfifo_th1 : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_FFTS_PMU_TASKFIFO_TH_UNION;
#endif
#define SOC_FFTS_PMU_TASKFIFO_TH_pmu_taskfifo_th0_START (0)
#define SOC_FFTS_PMU_TASKFIFO_TH_pmu_taskfifo_th0_END (7)
#define SOC_FFTS_PMU_TASKFIFO_TH_pmu_taskfifo_th1_START (8)
#define SOC_FFTS_PMU_TASKFIFO_TH_pmu_taskfifo_th1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hw1_prtb_qos_en : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_FFTS_INTR_QOS_HW1_UNION;
#endif
#define SOC_FFTS_INTR_QOS_HW1_hw1_prtb_qos_en_START (0)
#define SOC_FFTS_INTR_QOS_HW1_hw1_prtb_qos_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hw1_intr_normal_mask : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FFTS_INTR_NRML_MASK_HW1_UNION;
#endif
#define SOC_FFTS_INTR_NRML_MASK_HW1_hw1_intr_normal_mask_START (0)
#define SOC_FFTS_INTR_NRML_MASK_HW1_hw1_intr_normal_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hw1_intr_normal_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FFTS_INTR_NRML_CLR_HW1_UNION;
#endif
#define SOC_FFTS_INTR_NRML_CLR_HW1_hw1_intr_normal_clr_START (0)
#define SOC_FFTS_INTR_NRML_CLR_HW1_hw1_intr_normal_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hw1_intr_normal_st : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FFTS_INTR_NRML_ST_HW1_UNION;
#endif
#define SOC_FFTS_INTR_NRML_ST_HW1_hw1_intr_normal_st_START (0)
#define SOC_FFTS_INTR_NRML_ST_HW1_hw1_intr_normal_st_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hw1_intrq_normal_rptr : 12;
        unsigned int hw1_intrq_normal_rptr_upd : 1;
        unsigned int reserved_0 : 3;
        unsigned int hw1_intrq_normal_wptr : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_FFTS_INTRQ_NRML_PTR_HW1_UNION;
#endif
#define SOC_FFTS_INTRQ_NRML_PTR_HW1_hw1_intrq_normal_rptr_START (0)
#define SOC_FFTS_INTRQ_NRML_PTR_HW1_hw1_intrq_normal_rptr_END (11)
#define SOC_FFTS_INTRQ_NRML_PTR_HW1_hw1_intrq_normal_rptr_upd_START (12)
#define SOC_FFTS_INTRQ_NRML_PTR_HW1_hw1_intrq_normal_rptr_upd_END (12)
#define SOC_FFTS_INTRQ_NRML_PTR_HW1_hw1_intrq_normal_wptr_START (16)
#define SOC_FFTS_INTRQ_NRML_PTR_HW1_hw1_intrq_normal_wptr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_normal_mask : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FFTS_INTR_NRML_MASK_UNION;
#endif
#define SOC_FFTS_INTR_NRML_MASK_intr_normal_mask_START (0)
#define SOC_FFTS_INTR_NRML_MASK_intr_normal_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_normal_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FFTS_INTR_NRML_CLR_UNION;
#endif
#define SOC_FFTS_INTR_NRML_CLR_intr_normal_clr_START (0)
#define SOC_FFTS_INTR_NRML_CLR_intr_normal_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_normal_st : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FFTS_INTR_NRML_ST_UNION;
#endif
#define SOC_FFTS_INTR_NRML_ST_intr_normal_st_START (0)
#define SOC_FFTS_INTR_NRML_ST_intr_normal_st_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intrq_normal_rptr : 12;
        unsigned int intrq_normal_rptr_upd : 1;
        unsigned int reserved_0 : 3;
        unsigned int intrq_normal_wptr : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_FFTS_INTRQ_NRML_PTR_UNION;
#endif
#define SOC_FFTS_INTRQ_NRML_PTR_intrq_normal_rptr_START (0)
#define SOC_FFTS_INTRQ_NRML_PTR_intrq_normal_rptr_END (11)
#define SOC_FFTS_INTRQ_NRML_PTR_intrq_normal_rptr_upd_START (12)
#define SOC_FFTS_INTRQ_NRML_PTR_intrq_normal_rptr_upd_END (12)
#define SOC_FFTS_INTRQ_NRML_PTR_intrq_normal_wptr_START (16)
#define SOC_FFTS_INTRQ_NRML_PTR_intrq_normal_wptr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_abnormal_mask : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_FFTS_INTR_ABNM_MASK_UNION;
#endif
#define SOC_FFTS_INTR_ABNM_MASK_intr_abnormal_mask_START (0)
#define SOC_FFTS_INTR_ABNM_MASK_intr_abnormal_mask_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_abnormal_clr : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_FFTS_INTR_ABNM_CLR_UNION;
#endif
#define SOC_FFTS_INTR_ABNM_CLR_intr_abnormal_clr_START (0)
#define SOC_FFTS_INTR_ABNM_CLR_intr_abnormal_clr_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intr_abnormal_st : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_FFTS_INTR_ABNM_ST_UNION;
#endif
#define SOC_FFTS_INTR_ABNM_ST_intr_abnormal_st_START (0)
#define SOC_FFTS_INTR_ABNM_ST_intr_abnormal_st_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intrq_abnormal_rptr : 12;
        unsigned int intrq_abnormal_rptr_upd : 1;
        unsigned int reserved_0 : 3;
        unsigned int intrq_abnormal_wptr : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_FFTS_INTRQ_ABNM_PTR_UNION;
#endif
#define SOC_FFTS_INTRQ_ABNM_PTR_intrq_abnormal_rptr_START (0)
#define SOC_FFTS_INTRQ_ABNM_PTR_intrq_abnormal_rptr_END (11)
#define SOC_FFTS_INTRQ_ABNM_PTR_intrq_abnormal_rptr_upd_START (12)
#define SOC_FFTS_INTRQ_ABNM_PTR_intrq_abnormal_rptr_upd_END (12)
#define SOC_FFTS_INTRQ_ABNM_PTR_intrq_abnormal_wptr_START (16)
#define SOC_FFTS_INTRQ_ABNM_PTR_intrq_abnormal_wptr_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intrq_abnormal_mask : 32;
    } reg;
} SOC_FFTS_INTRQ_ABNM_MASK_UNION;
#endif
#define SOC_FFTS_INTRQ_ABNM_MASK_intrq_abnormal_mask_START (0)
#define SOC_FFTS_INTRQ_ABNM_MASK_intrq_abnormal_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intrq_abnormal_dfx_st : 32;
    } reg;
} SOC_FFTS_INTRQ_ABNM_DFX_ST_UNION;
#endif
#define SOC_FFTS_INTRQ_ABNM_DFX_ST_intrq_abnormal_dfx_st_START (0)
#define SOC_FFTS_INTRQ_ABNM_DFX_ST_intrq_abnormal_dfx_st_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int intrq_abnormal_dfx_clr : 32;
    } reg;
} SOC_FFTS_INTRQ_ABNM_DFX_CLR_UNION;
#endif
#define SOC_FFTS_INTRQ_ABNM_DFX_CLR_intrq_abnormal_dfx_clr_START (0)
#define SOC_FFTS_INTRQ_ABNM_DFX_CLR_intrq_abnormal_dfx_clr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_int_mask : 32;
    } reg;
} SOC_FFTS_INTR_DFX_MASK_UNION;
#endif
#define SOC_FFTS_INTR_DFX_MASK_dfx_int_mask_START (0)
#define SOC_FFTS_INTR_DFX_MASK_dfx_int_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_int_org_status : 32;
    } reg;
} SOC_FFTS_INTR_DFX_ORG_STATUS_UNION;
#endif
#define SOC_FFTS_INTR_DFX_ORG_STATUS_dfx_int_org_status_START (0)
#define SOC_FFTS_INTR_DFX_ORG_STATUS_dfx_int_org_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_int_mask_status : 32;
    } reg;
} SOC_FFTS_INTR_DFX_MASK_STATUS_UNION;
#endif
#define SOC_FFTS_INTR_DFX_MASK_STATUS_dfx_int_mask_status_START (0)
#define SOC_FFTS_INTR_DFX_MASK_STATUS_dfx_int_mask_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_int_type : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_FFTS_INTR_DFX_TYPE_UNION;
#endif
#define SOC_FFTS_INTR_DFX_TYPE_dfx_int_type_START (0)
#define SOC_FFTS_INTR_DFX_TYPE_dfx_int_type_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_int_info : 32;
    } reg;
} SOC_FFTS_INTR_DFX_INFO_UNION;
#endif
#define SOC_FFTS_INTR_DFX_INFO_dfx_int_info_START (0)
#define SOC_FFTS_INTR_DFX_INFO_dfx_int_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_addr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FFTS_DEBUG_ADDR_UNION;
#endif
#define SOC_FFTS_DEBUG_ADDR_dbg_cfg_addr_START (0)
#define SOC_FFTS_DEBUG_ADDR_dbg_cfg_addr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_rd : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FFTS_DEBUG_RD_EN_UNION;
#endif
#define SOC_FFTS_DEBUG_RD_EN_dbg_cfg_rd_START (0)
#define SOC_FFTS_DEBUG_RD_EN_dbg_cfg_rd_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_data_vld : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_FFTS_DEBUG_ST_UNION;
#endif
#define SOC_FFTS_DEBUG_ST_dbg_cfg_data_vld_START (0)
#define SOC_FFTS_DEBUG_ST_dbg_cfg_data_vld_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_rdata0 : 32;
    } reg;
} SOC_FFTS_DEBUG_INFO0_UNION;
#endif
#define SOC_FFTS_DEBUG_INFO0_dbg_cfg_rdata0_START (0)
#define SOC_FFTS_DEBUG_INFO0_dbg_cfg_rdata0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_rdata1 : 32;
    } reg;
} SOC_FFTS_DEBUG_INFO1_UNION;
#endif
#define SOC_FFTS_DEBUG_INFO1_dbg_cfg_rdata1_START (0)
#define SOC_FFTS_DEBUG_INFO1_dbg_cfg_rdata1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_rdata2 : 32;
    } reg;
} SOC_FFTS_DEBUG_INFO2_UNION;
#endif
#define SOC_FFTS_DEBUG_INFO2_dbg_cfg_rdata2_START (0)
#define SOC_FFTS_DEBUG_INFO2_dbg_cfg_rdata2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cfg_rdata3 : 32;
    } reg;
} SOC_FFTS_DEBUG_INFO3_UNION;
#endif
#define SOC_FFTS_DEBUG_INFO3_dbg_cfg_rdata3_START (0)
#define SOC_FFTS_DEBUG_INFO3_dbg_cfg_rdata3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int perf_record_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int perf_record_mode : 1;
        unsigned int reserved_1 : 3;
        unsigned int perf_record_size : 6;
        unsigned int reserved_2 : 18;
    } reg;
} SOC_FFTS_PERF_RECORD_CTRL_UNION;
#endif
#define SOC_FFTS_PERF_RECORD_CTRL_perf_record_en_START (0)
#define SOC_FFTS_PERF_RECORD_CTRL_perf_record_en_END (0)
#define SOC_FFTS_PERF_RECORD_CTRL_perf_record_mode_START (4)
#define SOC_FFTS_PERF_RECORD_CTRL_perf_record_mode_END (4)
#define SOC_FFTS_PERF_RECORD_CTRL_perf_record_size_START (8)
#define SOC_FFTS_PERF_RECORD_CTRL_perf_record_size_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int perf_record_intr_th : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_FFTS_PERF_RECORD_INTR_UNION;
#endif
#define SOC_FFTS_PERF_RECORD_INTR_perf_record_intr_th_START (0)
#define SOC_FFTS_PERF_RECORD_INTR_perf_record_intr_th_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int perf_record_wptr : 24;
        unsigned int perf_record_wptr_clr : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_FFTS_PERF_RECORD_WPTR_UNION;
#endif
#define SOC_FFTS_PERF_RECORD_WPTR_perf_record_wptr_START (0)
#define SOC_FFTS_PERF_RECORD_WPTR_perf_record_wptr_END (23)
#define SOC_FFTS_PERF_RECORD_WPTR_perf_record_wptr_clr_START (24)
#define SOC_FFTS_PERF_RECORD_WPTR_perf_record_wptr_clr_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int perf_record_rptr : 24;
        unsigned int perf_record_rptr_upd : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_FFTS_PERF_RECORD_RPTR_UNION;
#endif
#define SOC_FFTS_PERF_RECORD_RPTR_perf_record_rptr_START (0)
#define SOC_FFTS_PERF_RECORD_RPTR_perf_record_rptr_END (23)
#define SOC_FFTS_PERF_RECORD_RPTR_perf_record_rptr_upd_START (24)
#define SOC_FFTS_PERF_RECORD_RPTR_perf_record_rptr_upd_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int perf_record_flush : 1;
        unsigned int perf_record_auto_flush : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_FFTS_PERF_RECORD_FLUSH_UNION;
#endif
#define SOC_FFTS_PERF_RECORD_FLUSH_perf_record_flush_START (0)
#define SOC_FFTS_PERF_RECORD_FLUSH_perf_record_flush_END (0)
#define SOC_FFTS_PERF_RECORD_FLUSH_perf_record_auto_flush_START (1)
#define SOC_FFTS_PERF_RECORD_FLUSH_perf_record_auto_flush_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int perf_record_uid_flt : 12;
        unsigned int perf_record_uid_flt_en : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_FFTS_PERF_UID_FLT_UNION;
#endif
#define SOC_FFTS_PERF_UID_FLT_perf_record_uid_flt_START (0)
#define SOC_FFTS_PERF_UID_FLT_perf_record_uid_flt_END (11)
#define SOC_FFTS_PERF_UID_FLT_perf_record_uid_flt_en_START (12)
#define SOC_FFTS_PERF_UID_FLT_perf_record_uid_flt_en_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int perf_record_cmd3_flt : 2;
        unsigned int perf_record_cmd2_flt : 6;
        unsigned int perf_record_cmd1_flt : 16;
        unsigned int perf_record_cmd0_flt : 8;
    } reg;
} SOC_FFTS_PERF_TYPE_FLT0_UNION;
#endif
#define SOC_FFTS_PERF_TYPE_FLT0_perf_record_cmd3_flt_START (0)
#define SOC_FFTS_PERF_TYPE_FLT0_perf_record_cmd3_flt_END (1)
#define SOC_FFTS_PERF_TYPE_FLT0_perf_record_cmd2_flt_START (2)
#define SOC_FFTS_PERF_TYPE_FLT0_perf_record_cmd2_flt_END (7)
#define SOC_FFTS_PERF_TYPE_FLT0_perf_record_cmd1_flt_START (8)
#define SOC_FFTS_PERF_TYPE_FLT0_perf_record_cmd1_flt_END (23)
#define SOC_FFTS_PERF_TYPE_FLT0_perf_record_cmd0_flt_START (24)
#define SOC_FFTS_PERF_TYPE_FLT0_perf_record_cmd0_flt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int perf_record_type_flt : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FFTS_PERF_TYPE_FLT1_UNION;
#endif
#define SOC_FFTS_PERF_TYPE_FLT1_perf_record_type_flt_START (0)
#define SOC_FFTS_PERF_TYPE_FLT1_perf_record_type_flt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwrtb_rptr : 16;
        unsigned int hwrtb_wptr : 16;
    } reg;
} SOC_FFTS_HWRTB_PTR_UNION;
#endif
#define SOC_FFTS_HWRTB_PTR_hwrtb_rptr_START (0)
#define SOC_FFTS_HWRTB_PTR_hwrtb_rptr_END (15)
#define SOC_FFTS_HWRTB_PTR_hwrtb_wptr_START (16)
#define SOC_FFTS_HWRTB_PTR_hwrtb_wptr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hw_link_st : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_FFTS_HW_LINK_ST_UNION;
#endif
#define SOC_FFTS_HW_LINK_ST_hw_link_st_START (0)
#define SOC_FFTS_HW_LINK_ST_hw_link_st_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwrtb_status : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_FFTS_HWRTB_STATUS_UNION;
#endif
#define SOC_FFTS_HWRTB_STATUS_hwrtb_status_START (0)
#define SOC_FFTS_HWRTB_STATUS_hwrtb_status_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwrtb_full_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_FFTS_HWRTB_FULL_STATUS_UNION;
#endif
#define SOC_FFTS_HWRTB_FULL_STATUS_hwrtb_full_status_START (0)
#define SOC_FFTS_HWRTB_FULL_STATUS_hwrtb_full_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ref_timer_val0 : 32;
    } reg;
} SOC_FFTS_REF_TIMER_VAL0_UNION;
#endif
#define SOC_FFTS_REF_TIMER_VAL0_ref_timer_val0_START (0)
#define SOC_FFTS_REF_TIMER_VAL0_ref_timer_val0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ref_timer_val1 : 32;
    } reg;
} SOC_FFTS_REF_TIMER_VAL1_UNION;
#endif
#define SOC_FFTS_REF_TIMER_VAL1_ref_timer_val1_START (0)
#define SOC_FFTS_REF_TIMER_VAL1_ref_timer_val1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int task_cmd_fifo_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_FFTS_DFX_FIFO_CNT_UNION;
#endif
#define SOC_FFTS_DFX_FIFO_CNT_task_cmd_fifo_cnt_START (0)
#define SOC_FFTS_DFX_FIFO_CNT_task_cmd_fifo_cnt_END (7)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
