#ifndef __SOC_NPU_AICORE_INTERFACE_H__
#define __SOC_NPU_AICORE_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_AICORE_SU_KIS_START_PC_L_ADDR(base) ((base) + (0x0080UL))
#define SOC_NPU_AICORE_SU_KIS_START_PC_H_ADDR(base) ((base) + (0x0084UL))
#define SOC_NPU_AICORE_SU_KIS_PARAM_BASE_L_ADDR(base) ((base) + (0x0088UL))
#define SOC_NPU_AICORE_SU_KIS_PARAM_BASE_H_ADDR(base) ((base) + (0x008CUL))
#define SOC_NPU_AICORE_SU_KIS_BLOCK_ID_DIM_ADDR(base) ((base) + (0x0090UL))
#define SOC_NPU_AICORE_SU_KIS_THREAD_ID_DIM_ADDR(base) ((base) + (0x0094UL))
#define SOC_NPU_AICORE_SU_KIS_SUBBLOCK_ID_ADDR(base) ((base) + (0x0098UL))
#define SOC_NPU_AICORE_SU_KIS_DATA_SIZE_ADDR(base) ((base) + (0x009CUL))
#define SOC_NPU_AICORE_SU_KIS_STACK_PHY_BASE_L_ADDR(base) ((base) + (0x00A0UL))
#define SOC_NPU_AICORE_SU_KIS_STACK_PHY_BASE_H_ADDR(base) ((base) + (0x00A4UL))
#define SOC_NPU_AICORE_KIS_SMMU_SUBSTREAMID_ADDR(base) ((base) + (0x00A8UL))
#define SOC_NPU_AICORE_KIS_SMMU_SUBSTREAMID_EN_ADDR(base) ((base) + (0x00ACUL))
#define SOC_NPU_AICORE_KIS_SU_PRELOAD_SAT_MODE_ADDR(base) ((base) + (0x00B0UL))
#define SOC_NPU_AICORE_KIS_TASK_CFG_ADDR(base) ((base) + (0x00B4UL))
#define SOC_NPU_AICORE_KIS_BIF_AXPROT_ADDR(base) ((base) + (0x00B8UL))
#define SOC_NPU_AICORE_KIS_PCIE_AXUSER_CFG_ADDR(base) ((base) + (0x00BCUL))
#define SOC_NPU_AICORE_KIS_FLOW_PARTID_CFG_ADDR(base) ((base) + (0x00C0UL))
#define SOC_NPU_AICORE_KIS_MTE_RATIO_CFG_ADDR(base) ((base) + (0x00C4UL))
#define SOC_NPU_AICORE_KIS_SU_GROUP_DIM_ID_CFG_ADDR(base) ((base) + (0x00C8UL))
#define SOC_NPU_AICORE_KIS_SU_GROUP_BLK_DIM_ID_CFG_ADDR(base) ((base) + (0x00CCUL))
#define SOC_NPU_AICORE_KIS_SU_DATA_MAIN_BASE_L_ADDR(base) ((base) + (0x00D0UL))
#define SOC_NPU_AICORE_KIS_SU_DATA_MAIN_BASE_H_ADDR(base) ((base) + (0x00D4UL))
#define SOC_NPU_AICORE_KIS_SU_DATA_UB_BASE_L_ADDR(base) ((base) + (0x00D8UL))
#define SOC_NPU_AICORE_KIS_SU_DATA_UB_BASE_H_ADDR(base) ((base) + (0x00DCUL))
#define SOC_NPU_AICORE_KIS_SIMT_STK_BASE_L_ADDR(base) ((base) + (0x00E0UL))
#define SOC_NPU_AICORE_KIS_SIMT_STK_BASE_H_ADDR(base) ((base) + (0x00E4UL))
#define SOC_NPU_AICORE_KIS_SIMT_WARP_STK_SIZE_ADDR(base) ((base) + (0x00E8UL))
#define SOC_NPU_AICORE_KIS_SIMT_UB_SIZE_ADDR(base) ((base) + (0x00ECUL))
#define SOC_NPU_AICORE_KIS_SIMT_DVG_WARP_STACK_SIZE_ADDR(base) ((base) + (0x00F0UL))
#define SOC_NPU_AICORE_KIS_BIF_STA_ARB_WEIGHT_ADDR(base) ((base) + (0x00F4UL))
#define SOC_NPU_AICORE_KIS_CFG_RSV_1_ADDR(base) ((base) + (0x00F8UL))
#else
#define SOC_NPU_AICORE_SU_KIS_START_PC_L_ADDR(base) ((base) + (0x0080))
#define SOC_NPU_AICORE_SU_KIS_START_PC_H_ADDR(base) ((base) + (0x0084))
#define SOC_NPU_AICORE_SU_KIS_PARAM_BASE_L_ADDR(base) ((base) + (0x0088))
#define SOC_NPU_AICORE_SU_KIS_PARAM_BASE_H_ADDR(base) ((base) + (0x008C))
#define SOC_NPU_AICORE_SU_KIS_BLOCK_ID_DIM_ADDR(base) ((base) + (0x0090))
#define SOC_NPU_AICORE_SU_KIS_THREAD_ID_DIM_ADDR(base) ((base) + (0x0094))
#define SOC_NPU_AICORE_SU_KIS_SUBBLOCK_ID_ADDR(base) ((base) + (0x0098))
#define SOC_NPU_AICORE_SU_KIS_DATA_SIZE_ADDR(base) ((base) + (0x009C))
#define SOC_NPU_AICORE_SU_KIS_STACK_PHY_BASE_L_ADDR(base) ((base) + (0x00A0))
#define SOC_NPU_AICORE_SU_KIS_STACK_PHY_BASE_H_ADDR(base) ((base) + (0x00A4))
#define SOC_NPU_AICORE_KIS_SMMU_SUBSTREAMID_ADDR(base) ((base) + (0x00A8))
#define SOC_NPU_AICORE_KIS_SMMU_SUBSTREAMID_EN_ADDR(base) ((base) + (0x00AC))
#define SOC_NPU_AICORE_KIS_SU_PRELOAD_SAT_MODE_ADDR(base) ((base) + (0x00B0))
#define SOC_NPU_AICORE_KIS_TASK_CFG_ADDR(base) ((base) + (0x00B4))
#define SOC_NPU_AICORE_KIS_BIF_AXPROT_ADDR(base) ((base) + (0x00B8))
#define SOC_NPU_AICORE_KIS_PCIE_AXUSER_CFG_ADDR(base) ((base) + (0x00BC))
#define SOC_NPU_AICORE_KIS_FLOW_PARTID_CFG_ADDR(base) ((base) + (0x00C0))
#define SOC_NPU_AICORE_KIS_MTE_RATIO_CFG_ADDR(base) ((base) + (0x00C4))
#define SOC_NPU_AICORE_KIS_SU_GROUP_DIM_ID_CFG_ADDR(base) ((base) + (0x00C8))
#define SOC_NPU_AICORE_KIS_SU_GROUP_BLK_DIM_ID_CFG_ADDR(base) ((base) + (0x00CC))
#define SOC_NPU_AICORE_KIS_SU_DATA_MAIN_BASE_L_ADDR(base) ((base) + (0x00D0))
#define SOC_NPU_AICORE_KIS_SU_DATA_MAIN_BASE_H_ADDR(base) ((base) + (0x00D4))
#define SOC_NPU_AICORE_KIS_SU_DATA_UB_BASE_L_ADDR(base) ((base) + (0x00D8))
#define SOC_NPU_AICORE_KIS_SU_DATA_UB_BASE_H_ADDR(base) ((base) + (0x00DC))
#define SOC_NPU_AICORE_KIS_SIMT_STK_BASE_L_ADDR(base) ((base) + (0x00E0))
#define SOC_NPU_AICORE_KIS_SIMT_STK_BASE_H_ADDR(base) ((base) + (0x00E4))
#define SOC_NPU_AICORE_KIS_SIMT_WARP_STK_SIZE_ADDR(base) ((base) + (0x00E8))
#define SOC_NPU_AICORE_KIS_SIMT_UB_SIZE_ADDR(base) ((base) + (0x00EC))
#define SOC_NPU_AICORE_KIS_SIMT_DVG_WARP_STACK_SIZE_ADDR(base) ((base) + (0x00F0))
#define SOC_NPU_AICORE_KIS_BIF_STA_ARB_WEIGHT_ADDR(base) ((base) + (0x00F4))
#define SOC_NPU_AICORE_KIS_CFG_RSV_1_ADDR(base) ((base) + (0x00F8))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_AICORE_SEC_AIC_SEC_EN_ADDR(base) ((base) + (0x1000UL))
#define SOC_NPU_AICORE_SEC_AIC_ERR_RESP_EN_ADDR(base) ((base) + (0x1004UL))
#define SOC_NPU_AICORE_SEC_AIC_RAM_ALWAYS_NOT_CLEAR_ADDR(base) ((base) + (0x1008UL))
#define SOC_NPU_AICORE_SC_REGS_SEC_ACCESS_EN_ADDR(base) ((base) + (0x11F0UL))
#define SOC_NPU_AICORE_SEC_SYS_VA_BASE_L_ADDR(base) ((base) + (0x1200UL))
#define SOC_NPU_AICORE_SEC_SYS_VA_BASE_H_ADDR(base) ((base) + (0x1204UL))
#define SOC_NPU_AICORE_AIC_UB_BASE_OFFSET_ADDR(base) ((base) + (0x1210UL))
#define SOC_NPU_AICORE_SEC_BIF_STREAM_NS_ADDR(base) ((base) + (0x1400UL))
#define SOC_NPU_AICORE_SEC_SMMU_SEC_STREAMID_ADDR(base) ((base) + (0x1404UL))
#define SOC_NPU_AICORE_SEC_AIC_ASIL_ADDR(base) ((base) + (0x1408UL))
#define SOC_NPU_AICORE_SEC_BIF_PARTID_CFG_ADDR(base) ((base) + (0x140CUL))
#define SOC_NPU_AICORE_SEC_BIF_PER_MON_AXPORT_ADDR(base) ((base) + (0x1410UL))
#define SOC_NPU_AICORE_SEC_MTE_PCIE_TYPE_BST_LN_ADDR(base) ((base) + (0x1500UL))
#define SOC_NPU_AICORE_SEC_MTE_PCIE_WIN_SZ_ADDR(base) ((base) + (0x1504UL))
#define SOC_NPU_AICORE_SEC_MTE_PCIE_WIN_BS_ADDR(base) ((base) + (0x1508UL))
#define SOC_NPU_AICORE_SEC_MTE_PCIE_ENABLE_ADDR(base) ((base) + (0x150CUL))
#else
#define SOC_NPU_AICORE_SEC_AIC_SEC_EN_ADDR(base) ((base) + (0x1000))
#define SOC_NPU_AICORE_SEC_AIC_ERR_RESP_EN_ADDR(base) ((base) + (0x1004))
#define SOC_NPU_AICORE_SEC_AIC_RAM_ALWAYS_NOT_CLEAR_ADDR(base) ((base) + (0x1008))
#define SOC_NPU_AICORE_SC_REGS_SEC_ACCESS_EN_ADDR(base) ((base) + (0x11F0))
#define SOC_NPU_AICORE_SEC_SYS_VA_BASE_L_ADDR(base) ((base) + (0x1200))
#define SOC_NPU_AICORE_SEC_SYS_VA_BASE_H_ADDR(base) ((base) + (0x1204))
#define SOC_NPU_AICORE_AIC_UB_BASE_OFFSET_ADDR(base) ((base) + (0x1210))
#define SOC_NPU_AICORE_SEC_BIF_STREAM_NS_ADDR(base) ((base) + (0x1400))
#define SOC_NPU_AICORE_SEC_SMMU_SEC_STREAMID_ADDR(base) ((base) + (0x1404))
#define SOC_NPU_AICORE_SEC_AIC_ASIL_ADDR(base) ((base) + (0x1408))
#define SOC_NPU_AICORE_SEC_BIF_PARTID_CFG_ADDR(base) ((base) + (0x140C))
#define SOC_NPU_AICORE_SEC_BIF_PER_MON_AXPORT_ADDR(base) ((base) + (0x1410))
#define SOC_NPU_AICORE_SEC_MTE_PCIE_TYPE_BST_LN_ADDR(base) ((base) + (0x1500))
#define SOC_NPU_AICORE_SEC_MTE_PCIE_WIN_SZ_ADDR(base) ((base) + (0x1504))
#define SOC_NPU_AICORE_SEC_MTE_PCIE_WIN_BS_ADDR(base) ((base) + (0x1508))
#define SOC_NPU_AICORE_SEC_MTE_PCIE_ENABLE_ADDR(base) ((base) + (0x150C))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_AICORE_GLB_AIC_CLK_GATE_MASK_ADDR(base) ((base) + (0x2000UL))
#define SOC_NPU_AICORE_GLB_AIC_EXCPT_CLR_ADDR(base) ((base) + (0x2010UL))
#define SOC_NPU_AICORE_GLB_AIC_SAFETY_REG_PTY_CTL_ADDR(base) ((base) + (0x2020UL))
#define SOC_NPU_AICORE_GLB_CONTEXT_SWITCH_CTRL_0_ADDR(base) ((base) + (0x2030UL))
#define SOC_NPU_AICORE_GLB_CONTEXT_SWITCH_CTRL_1_ADDR(base) ((base) + (0x2034UL))
#define SOC_NPU_AICORE_GLB_PMU_EN_ADDR(base) ((base) + (0x2400UL))
#define SOC_NPU_AICORE_GLB_L2_VADDR_BASE_L_ADDR(base) ((base) + (0x2410UL))
#define SOC_NPU_AICORE_GLB_L2_VADDR_BASE_H_ADDR(base) ((base) + (0x2414UL))
#define SOC_NPU_AICORE_GLB_PMU_IDX_ADDR(base,pmu_cnt_n) ((base) + (0x2500+0x4*(pmu_cnt_n)))
#define SOC_NPU_AICORE_GLB_ADDR_INTLV_CFG_ADDR(base) ((base) + (0x2808UL))
#else
#define SOC_NPU_AICORE_GLB_AIC_CLK_GATE_MASK_ADDR(base) ((base) + (0x2000))
#define SOC_NPU_AICORE_GLB_AIC_EXCPT_CLR_ADDR(base) ((base) + (0x2010))
#define SOC_NPU_AICORE_GLB_AIC_SAFETY_REG_PTY_CTL_ADDR(base) ((base) + (0x2020))
#define SOC_NPU_AICORE_GLB_CONTEXT_SWITCH_CTRL_0_ADDR(base) ((base) + (0x2030))
#define SOC_NPU_AICORE_GLB_CONTEXT_SWITCH_CTRL_1_ADDR(base) ((base) + (0x2034))
#define SOC_NPU_AICORE_GLB_PMU_EN_ADDR(base) ((base) + (0x2400))
#define SOC_NPU_AICORE_GLB_L2_VADDR_BASE_L_ADDR(base) ((base) + (0x2410))
#define SOC_NPU_AICORE_GLB_L2_VADDR_BASE_H_ADDR(base) ((base) + (0x2414))
#define SOC_NPU_AICORE_GLB_PMU_IDX_ADDR(base,pmu_cnt_n) ((base) + (0x2500+0x4*(pmu_cnt_n)))
#define SOC_NPU_AICORE_GLB_ADDR_INTLV_CFG_ADDR(base) ((base) + (0x2808))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_AICORE_SU_KIS_START_PC_L_ADDR(base) ((base) + (0x0080UL))
#define SOC_NPU_AICORE_SU_KIS_START_PC_H_ADDR(base) ((base) + (0x0084UL))
#define SOC_NPU_AICORE_KIS_SU_PRELOAD_SAT_MODE_ADDR(base) ((base) + (0x00B0UL))
#define SOC_NPU_AICORE_KIS_TASK_CFG_ADDR(base) ((base) + (0x00B4UL))
#define SOC_NPU_AICORE_KIS_BIF_AXPROT_ADDR(base) ((base) + (0x00B8UL))
#define SOC_NPU_AICORE_SEC_AIC_SEC_EN_ADDR(base) ((base) + (0x1000UL))
#define SOC_NPU_AICORE_SEC_AIC_ERR_RESP_EN_ADDR(base) ((base) + (0x1004UL))
#define SOC_NPU_AICORE_SEC_AIC_RAM_ALWAYS_NOT_CLEAR_ADDR(base) ((base) + (0x1008UL))
#define SOC_NPU_AICORE_SC_REGS_SEC_ACCESS_EN_ADDR(base) ((base) + (0x11F0UL))
#define SOC_NPU_AICORE_AIC_UB_BASE_OFFSET_ADDR(base) ((base) + (0x1210UL))
#define SOC_NPU_AICORE_GLB_AIC_CLK_GATE_MASK_ADDR(base) ((base) + (0x2000UL))
#define SOC_NPU_AICORE_GLB_AIC_EXCPT_CLR_ADDR(base) ((base) + (0x2010UL))
#define SOC_NPU_AICORE_GLB_AIC_SAFETY_REG_PTY_CTL_ADDR(base) ((base) + (0x2020UL))
#define SOC_NPU_AICORE_GLB_CONTEXT_SWITCH_CTRL_0_ADDR(base) ((base) + (0x2030UL))
#define SOC_NPU_AICORE_GLB_CONTEXT_SWITCH_CTRL_1_ADDR(base) ((base) + (0x2034UL))
#define SOC_NPU_AICORE_GLB_PMU_EN_ADDR(base) ((base) + (0x2400UL))
#define SOC_NPU_AICORE_SC_RUN_STALL_ADDR(base) ((base) + (0x4000UL))
#define SOC_NPU_AICORE_SC_TASK_SCHEDULE_MODE_ADDR(base) ((base) + (0x4004UL))
#define SOC_NPU_AICORE_SC_MEM_INIT_CFG_AND_STA_ADDR(base) ((base) + (0x4008UL))
#define SOC_NPU_AICORE_SC_START_GLB_CTRL_ADDR(base) ((base) + (0x4010UL))
#define SOC_NPU_AICORE_SC_AIC_CORE_INT_ADDR(base) ((base) + (0x4020UL))
#define SOC_NPU_AICORE_SC_AIC_CORE_INT_MASK_ADDR(base) ((base) + (0x4024UL))
#define SOC_NPU_AICORE_SC_AIC_FIRST_ERR_ID_ADDR(base) ((base) + (0x4028UL))
#define SOC_NPU_AICORE_SC_AIC_CURRENT_RUN_ID_ADDR(base) ((base) + (0x402CUL))
#define SOC_NPU_AICORE_SC_RST_CNT_CFG_ADDR(base) ((base) + (0x4030UL))
#define SOC_NPU_AICORE_SC_SOFT_RST_CFG_AND_STA_ADDR(base) ((base) + (0x4034UL))
#define SOC_NPU_AICORE_SC_CACHE_PRELOAD_INV_CFG_ADDR(base) ((base) + (0x4038UL))
#define SOC_NPU_AICORE_SC_SU_IC_INV_STATUS_ADDR(base) ((base) + (0x403CUL))
#define SOC_NPU_AICORE_SC_AIC_INNER_STATUS_ADDR(base) ((base) + (0x4040UL))
#define SOC_NPU_AICORE_SC_CLK_GATE_MASK_0_ADDR(base) ((base) + (0x4050UL))
#define SOC_NPU_AICORE_SC_DJTAG_CLK_BYPASS_ADDR(base) ((base) + (0x4054UL))
#define SOC_NPU_AICORE_SC_CLK_DELAY_CNT_ADDR(base) ((base) + (0x4058UL))
#define SOC_NPU_AICORE_SC_CFG_DELAY_CNT_ADDR(base) ((base) + (0x405CUL))
#define SOC_NPU_AICORE_SC_LOCK_BYPASS_0_ADDR(base) ((base) + (0x4070UL))
#define SOC_NPU_AICORE_SC_LOCK_BYPASS_1_ADDR(base) ((base) + (0x4074UL))
#define SOC_NPU_AICORE_SC_SYSCTRL_LOCK_ADDR(base) ((base) + (0x4078UL))
#define SOC_NPU_AICORE_SC_BUS_TIMEOUT_CFG_L_ADDR(base) ((base) + (0x40F0UL))
#define SOC_NPU_AICORE_SC_BUS_TIMEOUT_CFG_H_ADDR(base) ((base) + (0x40F4UL))
#define SOC_NPU_AICORE_SC_DBG_RW_CTRL_ADDR(base) ((base) + (0x4100UL))
#define SOC_NPU_AICORE_SC_DBG_ADDR_L_ADDR(base) ((base) + (0x4108UL))
#define SOC_NPU_AICORE_SC_DBG_ADDR_H_ADDR(base) ((base) + (0x410CUL))
#define SOC_NPU_AICORE_SC_DBG_DATA_0_ADDR(base) ((base) + (0x4110UL))
#define SOC_NPU_AICORE_SC_DBG_DATA_1_ADDR(base) ((base) + (0x4114UL))
#define SOC_NPU_AICORE_SC_DBG_DATA_2_ADDR(base) ((base) + (0x4118UL))
#define SOC_NPU_AICORE_SC_DBG_DATA_3_ADDR(base) ((base) + (0x411CUL))
#define SOC_NPU_AICORE_SC_DBG_DATA_4_ADDR(base) ((base) + (0x4120UL))
#define SOC_NPU_AICORE_SC_DBG_DATA_5_ADDR(base) ((base) + (0x4124UL))
#define SOC_NPU_AICORE_SC_DBG_DATA_6_ADDR(base) ((base) + (0x4128UL))
#define SOC_NPU_AICORE_SC_DBG_DATA_7_ADDR(base) ((base) + (0x412CUL))
#define SOC_NPU_AICORE_SC_DBG_STATUS_ADDR(base) ((base) + (0x4130UL))
#define SOC_NPU_AICORE_SC_EXIT_DBG_CTRL_ADDR(base) ((base) + (0x4140UL))
#define SOC_NPU_AICORE_SC_PMU_CTRL_CFG_ADDR(base) ((base) + (0x4200UL))
#define SOC_NPU_AICORE_SC_PMU_CNT_STATUS_ADDR(base) ((base) + (0x4204UL))
#define SOC_NPU_AICORE_SC_PMU_MIN_OV_CNT_L_ADDR(base) ((base) + (0x4208UL))
#define SOC_NPU_AICORE_SC_PMU_MIN_OV_CNT_H_ADDR(base) ((base) + (0x420CUL))
#define SOC_NPU_AICORE_SC_PMU_CNT_ADDR(base,pmu_cnt_n) ((base) + (0x4210+0x8*(pmu_cnt_n)))
#define SOC_NPU_AICORE_SC_PMU_TASK_CYC_CNT_L_ADDR(base) ((base) + (0x4260UL))
#define SOC_NPU_AICORE_SC_PMU_TASK_CYC_CNT_H_ADDR(base) ((base) + (0x4264UL))
#define SOC_NPU_AICORE_SC_PMU_AIC_KIST_TIMESTAMP_L_ADDR(base) ((base) + (0x4268UL))
#define SOC_NPU_AICORE_SC_PMU_AIC_KIST_TIMESTAMP_H_ADDR(base) ((base) + (0x426CUL))
#define SOC_NPU_AICORE_SC_PMU_RESERVED_0_ADDR(base) ((base) + (0x4270UL))
#define SOC_NPU_AICORE_SC_PMU_RESERVED_1_ADDR(base) ((base) + (0x4274UL))
#define SOC_NPU_AICORE_SC_PMU_RESERVED_2_ADDR(base) ((base) + (0x4278UL))
#define SOC_NPU_AICORE_SC_PMU_RESERVED_3_ADDR(base) ((base) + (0x427CUL))
#define SOC_NPU_AICORE_SC_PMU_START_CNT_CYC_L_ADDR(base) ((base) + (0x42A0UL))
#define SOC_NPU_AICORE_SC_PMU_START_CNT_CYC_H_ADDR(base) ((base) + (0x42A4UL))
#define SOC_NPU_AICORE_SC_PMU_STOP_CNT_CYC_L_ADDR(base) ((base) + (0x42A8UL))
#define SOC_NPU_AICORE_SC_PMU_STOP_CNT_CYC_H_ADDR(base) ((base) + (0x42ACUL))
#define SOC_NPU_AICORE_SC_AIC_TASK_CYC_CNT_L_ADDR(base) ((base) + (0x42B0UL))
#define SOC_NPU_AICORE_SC_AIC_TASK_CYC_CNT_H_ADDR(base) ((base) + (0x42B4UL))
#define SOC_NPU_AICORE_SC_ERROR_T0_0_ADDR(base) ((base) + (0x4700UL))
#define SOC_NPU_AICORE_SC_ERROR_MASK_0_ADDR(base) ((base) + (0x4720UL))
#define SOC_NPU_AICORE_SC_ERR_INFO_T0_0_ADDR(base) ((base) + (0x4730UL))
#define SOC_NPU_AICORE_SC_ERR_INFO_T0_1_ADDR(base) ((base) + (0x4734UL))
#define SOC_NPU_AICORE_SC_SAFETY_INT_ADDR(base) ((base) + (0x4750UL))
#define SOC_NPU_AICORE_SC_SAFETY_INT_MASK_ADDR(base) ((base) + (0x4754UL))
#define SOC_NPU_AICORE_SC_SAFETY_ERR_MASK_ADDR(base) ((base) + (0x4758UL))
#define SOC_NPU_AICORE_SC_SAFETY_INT_INJECT_ADDR(base) ((base) + (0x4760UL))
#define SOC_NPU_AICORE_SC_RESERVED_RO_REG0_ADDR(base) ((base) + (0x4800UL))
#define SOC_NPU_AICORE_SC_RESERVED_RO_REG1_ADDR(base) ((base) + (0x4804UL))
#define SOC_NPU_AICORE_SC_RESERVED_RO_REG2_RSV_ADDR(base) ((base) + (0x4808UL))
#define SOC_NPU_AICORE_SC_RESERVED_RO_REG3_RSV_ADDR(base) ((base) + (0x480CUL))
#define SOC_NPU_AICORE_SC_RESERVED_RW_REG0_ADDR(base) ((base) + (0x4810UL))
#define SOC_NPU_AICORE_SC_RESERVED_RW_REG1_ADDR(base) ((base) + (0x4814UL))
#define SOC_NPU_AICORE_SC_RESERVED_RW_REG2_RSV_ADDR(base) ((base) + (0x4818UL))
#define SOC_NPU_AICORE_SC_RESERVED_RW_REG3_RSV_ADDR(base) ((base) + (0x481CUL))
#define SOC_NPU_AICORE_SC_PRE_RST_STALL_CTRL_ADDR(base) ((base) + (0x48A0UL))
#define SOC_NPU_AICORE_SC_PRE_RST_STATUS_ADDR(base) ((base) + (0x48A4UL))
#define SOC_NPU_AICORE_SC_RST_MASK_N_CFG_ADDR(base) ((base) + (0x48A8UL))
#define SOC_NPU_AICORE_SC_PENDING_TASK_STATUS_ADDR(base) ((base) + (0x48B0UL))
#define SOC_NPU_AICORE_SC_CONTEXT_SWITCH_CFG_ST_ADDR(base) ((base) + (0x4980UL))
#define SOC_NPU_AICORE_SC_CHICKEN_BIT_CTRL_ADDR(base) ((base) + (0x4990UL))
#define SOC_NPU_AICORE_SC_INNER_STATUS_ADDR(base) ((base) + (0x4998UL))
#else
#define SOC_NPU_AICORE_SU_KIS_START_PC_L_ADDR(base) ((base) + (0x0080))
#define SOC_NPU_AICORE_SU_KIS_START_PC_H_ADDR(base) ((base) + (0x0084))
#define SOC_NPU_AICORE_KIS_SU_PRELOAD_SAT_MODE_ADDR(base) ((base) + (0x00B0))
#define SOC_NPU_AICORE_KIS_TASK_CFG_ADDR(base) ((base) + (0x00B4))
#define SOC_NPU_AICORE_KIS_BIF_AXPROT_ADDR(base) ((base) + (0x00B8))
#define SOC_NPU_AICORE_SEC_AIC_SEC_EN_ADDR(base) ((base) + (0x1000))
#define SOC_NPU_AICORE_SEC_AIC_ERR_RESP_EN_ADDR(base) ((base) + (0x1004))
#define SOC_NPU_AICORE_SEC_AIC_RAM_ALWAYS_NOT_CLEAR_ADDR(base) ((base) + (0x1008))
#define SOC_NPU_AICORE_SC_REGS_SEC_ACCESS_EN_ADDR(base) ((base) + (0x11F0))
#define SOC_NPU_AICORE_AIC_UB_BASE_OFFSET_ADDR(base) ((base) + (0x1210))
#define SOC_NPU_AICORE_GLB_AIC_CLK_GATE_MASK_ADDR(base) ((base) + (0x2000))
#define SOC_NPU_AICORE_GLB_AIC_EXCPT_CLR_ADDR(base) ((base) + (0x2010))
#define SOC_NPU_AICORE_GLB_AIC_SAFETY_REG_PTY_CTL_ADDR(base) ((base) + (0x2020))
#define SOC_NPU_AICORE_GLB_CONTEXT_SWITCH_CTRL_0_ADDR(base) ((base) + (0x2030))
#define SOC_NPU_AICORE_GLB_CONTEXT_SWITCH_CTRL_1_ADDR(base) ((base) + (0x2034))
#define SOC_NPU_AICORE_GLB_PMU_EN_ADDR(base) ((base) + (0x2400))
#define SOC_NPU_AICORE_SC_RUN_STALL_ADDR(base) ((base) + (0x4000))
#define SOC_NPU_AICORE_SC_TASK_SCHEDULE_MODE_ADDR(base) ((base) + (0x4004))
#define SOC_NPU_AICORE_SC_MEM_INIT_CFG_AND_STA_ADDR(base) ((base) + (0x4008))
#define SOC_NPU_AICORE_SC_START_GLB_CTRL_ADDR(base) ((base) + (0x4010))
#define SOC_NPU_AICORE_SC_AIC_CORE_INT_ADDR(base) ((base) + (0x4020))
#define SOC_NPU_AICORE_SC_AIC_CORE_INT_MASK_ADDR(base) ((base) + (0x4024))
#define SOC_NPU_AICORE_SC_AIC_FIRST_ERR_ID_ADDR(base) ((base) + (0x4028))
#define SOC_NPU_AICORE_SC_AIC_CURRENT_RUN_ID_ADDR(base) ((base) + (0x402C))
#define SOC_NPU_AICORE_SC_RST_CNT_CFG_ADDR(base) ((base) + (0x4030))
#define SOC_NPU_AICORE_SC_SOFT_RST_CFG_AND_STA_ADDR(base) ((base) + (0x4034))
#define SOC_NPU_AICORE_SC_CACHE_PRELOAD_INV_CFG_ADDR(base) ((base) + (0x4038))
#define SOC_NPU_AICORE_SC_SU_IC_INV_STATUS_ADDR(base) ((base) + (0x403C))
#define SOC_NPU_AICORE_SC_AIC_INNER_STATUS_ADDR(base) ((base) + (0x4040))
#define SOC_NPU_AICORE_SC_CLK_GATE_MASK_0_ADDR(base) ((base) + (0x4050))
#define SOC_NPU_AICORE_SC_DJTAG_CLK_BYPASS_ADDR(base) ((base) + (0x4054))
#define SOC_NPU_AICORE_SC_CLK_DELAY_CNT_ADDR(base) ((base) + (0x4058))
#define SOC_NPU_AICORE_SC_CFG_DELAY_CNT_ADDR(base) ((base) + (0x405C))
#define SOC_NPU_AICORE_SC_LOCK_BYPASS_0_ADDR(base) ((base) + (0x4070))
#define SOC_NPU_AICORE_SC_LOCK_BYPASS_1_ADDR(base) ((base) + (0x4074))
#define SOC_NPU_AICORE_SC_SYSCTRL_LOCK_ADDR(base) ((base) + (0x4078))
#define SOC_NPU_AICORE_SC_BUS_TIMEOUT_CFG_L_ADDR(base) ((base) + (0x40F0))
#define SOC_NPU_AICORE_SC_BUS_TIMEOUT_CFG_H_ADDR(base) ((base) + (0x40F4))
#define SOC_NPU_AICORE_SC_DBG_RW_CTRL_ADDR(base) ((base) + (0x4100))
#define SOC_NPU_AICORE_SC_DBG_ADDR_L_ADDR(base) ((base) + (0x4108))
#define SOC_NPU_AICORE_SC_DBG_ADDR_H_ADDR(base) ((base) + (0x410C))
#define SOC_NPU_AICORE_SC_DBG_DATA_0_ADDR(base) ((base) + (0x4110))
#define SOC_NPU_AICORE_SC_DBG_DATA_1_ADDR(base) ((base) + (0x4114))
#define SOC_NPU_AICORE_SC_DBG_DATA_2_ADDR(base) ((base) + (0x4118))
#define SOC_NPU_AICORE_SC_DBG_DATA_3_ADDR(base) ((base) + (0x411C))
#define SOC_NPU_AICORE_SC_DBG_DATA_4_ADDR(base) ((base) + (0x4120))
#define SOC_NPU_AICORE_SC_DBG_DATA_5_ADDR(base) ((base) + (0x4124))
#define SOC_NPU_AICORE_SC_DBG_DATA_6_ADDR(base) ((base) + (0x4128))
#define SOC_NPU_AICORE_SC_DBG_DATA_7_ADDR(base) ((base) + (0x412C))
#define SOC_NPU_AICORE_SC_DBG_STATUS_ADDR(base) ((base) + (0x4130))
#define SOC_NPU_AICORE_SC_EXIT_DBG_CTRL_ADDR(base) ((base) + (0x4140))
#define SOC_NPU_AICORE_SC_PMU_CTRL_CFG_ADDR(base) ((base) + (0x4200))
#define SOC_NPU_AICORE_SC_PMU_CNT_STATUS_ADDR(base) ((base) + (0x4204))
#define SOC_NPU_AICORE_SC_PMU_MIN_OV_CNT_L_ADDR(base) ((base) + (0x4208))
#define SOC_NPU_AICORE_SC_PMU_MIN_OV_CNT_H_ADDR(base) ((base) + (0x420C))
#define SOC_NPU_AICORE_SC_PMU_CNT_ADDR(base,pmu_cnt_n) ((base) + (0x4210+0x8*(pmu_cnt_n)))
#define SOC_NPU_AICORE_SC_PMU_TASK_CYC_CNT_L_ADDR(base) ((base) + (0x4260))
#define SOC_NPU_AICORE_SC_PMU_TASK_CYC_CNT_H_ADDR(base) ((base) + (0x4264))
#define SOC_NPU_AICORE_SC_PMU_AIC_KIST_TIMESTAMP_L_ADDR(base) ((base) + (0x4268))
#define SOC_NPU_AICORE_SC_PMU_AIC_KIST_TIMESTAMP_H_ADDR(base) ((base) + (0x426C))
#define SOC_NPU_AICORE_SC_PMU_RESERVED_0_ADDR(base) ((base) + (0x4270))
#define SOC_NPU_AICORE_SC_PMU_RESERVED_1_ADDR(base) ((base) + (0x4274))
#define SOC_NPU_AICORE_SC_PMU_RESERVED_2_ADDR(base) ((base) + (0x4278))
#define SOC_NPU_AICORE_SC_PMU_RESERVED_3_ADDR(base) ((base) + (0x427C))
#define SOC_NPU_AICORE_SC_PMU_START_CNT_CYC_L_ADDR(base) ((base) + (0x42A0))
#define SOC_NPU_AICORE_SC_PMU_START_CNT_CYC_H_ADDR(base) ((base) + (0x42A4))
#define SOC_NPU_AICORE_SC_PMU_STOP_CNT_CYC_L_ADDR(base) ((base) + (0x42A8))
#define SOC_NPU_AICORE_SC_PMU_STOP_CNT_CYC_H_ADDR(base) ((base) + (0x42AC))
#define SOC_NPU_AICORE_SC_AIC_TASK_CYC_CNT_L_ADDR(base) ((base) + (0x42B0))
#define SOC_NPU_AICORE_SC_AIC_TASK_CYC_CNT_H_ADDR(base) ((base) + (0x42B4))
#define SOC_NPU_AICORE_SC_ERROR_T0_0_ADDR(base) ((base) + (0x4700))
#define SOC_NPU_AICORE_SC_ERROR_MASK_0_ADDR(base) ((base) + (0x4720))
#define SOC_NPU_AICORE_SC_ERR_INFO_T0_0_ADDR(base) ((base) + (0x4730))
#define SOC_NPU_AICORE_SC_ERR_INFO_T0_1_ADDR(base) ((base) + (0x4734))
#define SOC_NPU_AICORE_SC_SAFETY_INT_ADDR(base) ((base) + (0x4750))
#define SOC_NPU_AICORE_SC_SAFETY_INT_MASK_ADDR(base) ((base) + (0x4754))
#define SOC_NPU_AICORE_SC_SAFETY_ERR_MASK_ADDR(base) ((base) + (0x4758))
#define SOC_NPU_AICORE_SC_SAFETY_INT_INJECT_ADDR(base) ((base) + (0x4760))
#define SOC_NPU_AICORE_SC_RESERVED_RO_REG0_ADDR(base) ((base) + (0x4800))
#define SOC_NPU_AICORE_SC_RESERVED_RO_REG1_ADDR(base) ((base) + (0x4804))
#define SOC_NPU_AICORE_SC_RESERVED_RO_REG2_RSV_ADDR(base) ((base) + (0x4808))
#define SOC_NPU_AICORE_SC_RESERVED_RO_REG3_RSV_ADDR(base) ((base) + (0x480C))
#define SOC_NPU_AICORE_SC_RESERVED_RW_REG0_ADDR(base) ((base) + (0x4810))
#define SOC_NPU_AICORE_SC_RESERVED_RW_REG1_ADDR(base) ((base) + (0x4814))
#define SOC_NPU_AICORE_SC_RESERVED_RW_REG2_RSV_ADDR(base) ((base) + (0x4818))
#define SOC_NPU_AICORE_SC_RESERVED_RW_REG3_RSV_ADDR(base) ((base) + (0x481C))
#define SOC_NPU_AICORE_SC_PRE_RST_STALL_CTRL_ADDR(base) ((base) + (0x48A0))
#define SOC_NPU_AICORE_SC_PRE_RST_STATUS_ADDR(base) ((base) + (0x48A4))
#define SOC_NPU_AICORE_SC_RST_MASK_N_CFG_ADDR(base) ((base) + (0x48A8))
#define SOC_NPU_AICORE_SC_PENDING_TASK_STATUS_ADDR(base) ((base) + (0x48B0))
#define SOC_NPU_AICORE_SC_CONTEXT_SWITCH_CFG_ST_ADDR(base) ((base) + (0x4980))
#define SOC_NPU_AICORE_SC_CHICKEN_BIT_CTRL_ADDR(base) ((base) + (0x4990))
#define SOC_NPU_AICORE_SC_INNER_STATUS_ADDR(base) ((base) + (0x4998))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_AICORE_SU_KIS_START_PC_L_ADDR(base) ((base) + (0x0080UL))
#define SOC_NPU_AICORE_SU_KIS_START_PC_H_ADDR(base) ((base) + (0x0084UL))
#define SOC_NPU_AICORE_SU_KIS_PARAM_BASE_L_ADDR(base) ((base) + (0x0088UL))
#define SOC_NPU_AICORE_SU_KIS_PARAM_BASE_H_ADDR(base) ((base) + (0x008CUL))
#define SOC_NPU_AICORE_SU_KIS_BLOCK_ID_DIM_ADDR(base) ((base) + (0x0090UL))
#define SOC_NPU_AICORE_SU_KIS_THREAD_ID_DIM_ADDR(base) ((base) + (0x0094UL))
#define SOC_NPU_AICORE_SU_KIS_SUBBLOCK_ID_ADDR(base) ((base) + (0x0098UL))
#define SOC_NPU_AICORE_SU_KIS_DATA_SIZE_ADDR(base) ((base) + (0x009CUL))
#define SOC_NPU_AICORE_SU_KIS_STACK_PHY_BASE_L_ADDR(base) ((base) + (0x00A0UL))
#define SOC_NPU_AICORE_SU_KIS_STACK_PHY_BASE_H_ADDR(base) ((base) + (0x00A4UL))
#define SOC_NPU_AICORE_KIS_SMMU_SUBSTREAMID_ADDR(base) ((base) + (0x00A8UL))
#define SOC_NPU_AICORE_KIS_SMMU_SUBSTREAMID_EN_ADDR(base) ((base) + (0x00ACUL))
#define SOC_NPU_AICORE_KIS_SU_PRELOAD_SAT_MODE_ADDR(base) ((base) + (0x00B0UL))
#define SOC_NPU_AICORE_KIS_TASK_CFG_ADDR(base) ((base) + (0x00B4UL))
#define SOC_NPU_AICORE_KIS_SU_GROUP_DIM_ID_CFG_ADDR(base) ((base) + (0x00C8UL))
#define SOC_NPU_AICORE_KIS_SU_GROUP_BLK_DIM_ID_CFG_ADDR(base) ((base) + (0x00CCUL))
#define SOC_NPU_AICORE_SU_KIS_DATA_MAIN_BASE_L_ADDR(base) ((base) + (0x00D0UL))
#define SOC_NPU_AICORE_SU_KIS_DATA_MAIN_BASE_H_ADDR(base) ((base) + (0x00D4UL))
#define SOC_NPU_AICORE_SU_KIS_DATA_UB_BASE_L_ADDR(base) ((base) + (0x00D8UL))
#define SOC_NPU_AICORE_SU_KIS_DATA_UB_BASE_H_ADDR(base) ((base) + (0x00DCUL))
#define SOC_NPU_AICORE_SEC_SYS_VA_BASE_L_ADDR(base) ((base) + (0x1200UL))
#define SOC_NPU_AICORE_SEC_SYS_VA_BASE_H_ADDR(base) ((base) + (0x1204UL))
#define SOC_NPU_AICORE_AIC_UB_BASE_OFFSET_ADDR(base) ((base) + (0x1210UL))
#define SOC_NPU_AICORE_GLB_AIC_CLK_GATE_MASK_ADDR(base) ((base) + (0x2000UL))
#define SOC_NPU_AICORE_GLB_AIC_EXCPT_CLR_ADDR(base) ((base) + (0x2010UL))
#define SOC_NPU_AICORE_GLB_AIC_SAFETY_REG_PTY_CTL_ADDR(base) ((base) + (0x2020UL))
#define SOC_NPU_AICORE_GLB_PMU_EN_ADDR(base) ((base) + (0x2400UL))
#define SOC_NPU_AICORE_GLB_L2_VADDR_BASE_L_ADDR(base) ((base) + (0x2410UL))
#define SOC_NPU_AICORE_GLB_L2_VADDR_BASE_H_ADDR(base) ((base) + (0x2414UL))
#define SOC_NPU_AICORE_GLB_PMU_IDX_ADDR(base,pmu_cnt_n) ((base) + (0x2500+0x4*(pmu_cnt_n)))
#define SOC_NPU_AICORE_SU_CLK_GATE_MASK_0_ADDR(base) ((base) + (0x5000UL))
#define SOC_NPU_AICORE_SU_CLK_DELAY_CNT_0_ADDR(base) ((base) + (0x5008UL))
#define SOC_NPU_AICORE_SU_CLK_DELAY_CNT_1_ADDR(base) ((base) + (0x500CUL))
#define SOC_NPU_AICORE_SU_ECC_CTRL_0_ADDR(base) ((base) + (0x5020UL))
#define SOC_NPU_AICORE_SU_ECC_INJECT_CTRL_0_ADDR(base) ((base) + (0x5024UL))
#define SOC_NPU_AICORE_SU_IFU_CTRL_ADDR(base) ((base) + (0x5030UL))
#define SOC_NPU_AICORE_SU_CCU_CTRL_ADDR(base) ((base) + (0x5040UL))
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_ADDR(base) ((base) + (0x5044UL))
#define SOC_NPU_AICORE_SU_LSU_CTRL_ADDR(base) ((base) + (0x5050UL))
#define SOC_NPU_AICORE_SU_LSU_MPU_CTRL_ADDR(base) ((base) + (0x5054UL))
#define SOC_NPU_AICORE_SU_LSU_STB_CTRL_ADDR(base) ((base) + (0x5058UL))
#define SOC_NPU_AICORE_SU_SEQ_CTRL_ADDR(base) ((base) + (0x5060UL))
#define SOC_NPU_AICORE_SU_SPR_STATUS_L_ADDR(base) ((base) + (0x5100UL))
#define SOC_NPU_AICORE_SU_SPR_STATUS_H_ADDR(base) ((base) + (0x5104UL))
#define SOC_NPU_AICORE_SU_SPR_CONDITION_L_ADDR(base) ((base) + (0x5108UL))
#define SOC_NPU_AICORE_SU_SPR_CONDITION_H_ADDR(base) ((base) + (0x510CUL))
#define SOC_NPU_AICORE_SU_SPR_ARCH_VER_L_ADDR(base) ((base) + (0x5110UL))
#define SOC_NPU_AICORE_SU_SPR_ARCH_VER_H_ADDR(base) ((base) + (0x5114UL))
#define SOC_NPU_AICORE_SU_SPR_COREID_ADDR(base) ((base) + (0x5118UL))
#define SOC_NPU_AICORE_SU_AIC_CORE_MODEL_ID_ADDR(base) ((base) + (0x511CUL))
#define SOC_NPU_AICORE_SU_AIC_ISA_VER_L_ADDR(base) ((base) + (0x5120UL))
#define SOC_NPU_AICORE_SU_AIC_ISA_VER_H_ADDR(base) ((base) + (0x5124UL))
#define SOC_NPU_AICORE_SU_AIC_UARCH_VER_L_ADDR(base) ((base) + (0x5128UL))
#define SOC_NPU_AICORE_SU_AIC_UARCH_VER_H_ADDR(base) ((base) + (0x512CUL))
#define SOC_NPU_AICORE_SU_AIC_GEN_HW_CFG_L_ADDR(base) ((base) + (0x5130UL))
#define SOC_NPU_AICORE_SU_AIC_GEN_HW_CFG_H_ADDR(base) ((base) + (0x5134UL))
#define SOC_NPU_AICORE_SU_AIC_BRANCH_VER_L_ADDR(base) ((base) + (0x5138UL))
#define SOC_NPU_AICORE_SU_AIC_BRANCH_VER_H_ADDR(base) ((base) + (0x513CUL))
#define SOC_NPU_AICORE_SU_IC_INV_VA_L_ADDR(base) ((base) + (0x5200UL))
#define SOC_NPU_AICORE_SU_IC_INV_VA_H_ADDR(base) ((base) + (0x5204UL))
#define SOC_NPU_AICORE_SU_DBG_CTRL_ADDR(base) ((base) + (0x5300UL))
#define SOC_NPU_AICORE_SU_DBG_INT_MASK_ADDR(base) ((base) + (0x5304UL))
#define SOC_NPU_AICORE_SU_DBG_STATUS_ADDR(base) ((base) + (0x5308UL))
#define SOC_NPU_AICORE_SU_HW_BKPT_EN_ADDR(base) ((base) + (0x5310UL))
#define SOC_NPU_AICORE_SU_HW_BKPT0_PC_L_ADDR(base) ((base) + (0x5320UL))
#define SOC_NPU_AICORE_SU_HW_BKPT0_PC_H_ADDR(base) ((base) + (0x5324UL))
#define SOC_NPU_AICORE_SU_HW_BKPT1_PC_L_ADDR(base) ((base) + (0x5328UL))
#define SOC_NPU_AICORE_SU_HW_BKPT1_PC_H_ADDR(base) ((base) + (0x532CUL))
#define SOC_NPU_AICORE_SU_HW_BKPT2_PC_L_ADDR(base) ((base) + (0x5330UL))
#define SOC_NPU_AICORE_SU_HW_BKPT2_PC_H_ADDR(base) ((base) + (0x5334UL))
#define SOC_NPU_AICORE_SU_HW_BKPT3_PC_L_ADDR(base) ((base) + (0x5338UL))
#define SOC_NPU_AICORE_SU_HW_BKPT3_PC_H_ADDR(base) ((base) + (0x533CUL))
#define SOC_NPU_AICORE_SU_HW_BKPT0_TWO_LEVLE_SMID_ADDR(base) ((base) + (0x53a0UL))
#define SOC_NPU_AICORE_SU_HW_BKPT1_TWO_LEVLE_SMID_ADDR(base) ((base) + (0x53a4UL))
#define SOC_NPU_AICORE_SU_HW_BKPT2_TWO_LEVLE_SMID_ADDR(base) ((base) + (0x53a8UL))
#define SOC_NPU_AICORE_SU_HW_BKPT3_TWO_LEVLE_SMID_ADDR(base) ((base) + (0x53aCUL))
#define SOC_NPU_AICORE_SU_PRE_RST_STALL_CTRL_ADDR(base) ((base) + (0x5600UL))
#define SOC_NPU_AICORE_SU_PRE_RST_STATUS_ADDR(base) ((base) + (0x5604UL))
#define SOC_NPU_AICORE_SU_INNER_STATUS_ADDR(base) ((base) + (0x5608UL))
#define SOC_NPU_AICORE_SU_ERROR_T0_0_ADDR(base) ((base) + (0x5700UL))
#define SOC_NPU_AICORE_SU_ERROR_T1_0_ADDR(base) ((base) + (0x5710UL))
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_ADDR(base) ((base) + (0x5720UL))
#define SOC_NPU_AICORE_SU_ERR_INFO_T0_0_ADDR(base) ((base) + (0x5730UL))
#define SOC_NPU_AICORE_SU_ERR_INFO_T0_1_ADDR(base) ((base) + (0x5734UL))
#define SOC_NPU_AICORE_SU_ERR_INFO_T0_2_ADDR(base) ((base) + (0x5738UL))
#define SOC_NPU_AICORE_SU_ERR_INFO_T0_3_ADDR(base) ((base) + (0x573CUL))
#define SOC_NPU_AICORE_SU_ERR_INFO_T1_0_ADDR(base) ((base) + (0x5750UL))
#define SOC_NPU_AICORE_SU_ERR_INFO_T1_1_ADDR(base) ((base) + (0x5754UL))
#define SOC_NPU_AICORE_SU_ERR_INFO_T1_2_ADDR(base) ((base) + (0x5758UL))
#define SOC_NPU_AICORE_SU_ERR_INFO_T1_3_ADDR(base) ((base) + (0x575CUL))
#define SOC_NPU_AICORE_SU_WARN_T0_0_ADDR(base) ((base) + (0x5900UL))
#define SOC_NPU_AICORE_SU_WARN_T1_0_ADDR(base) ((base) + (0x5908UL))
#define SOC_NPU_AICORE_SU_WARN_MASK_0_ADDR(base) ((base) + (0x5910UL))
#define SOC_NPU_AICORE_SU_1BIT_ECC_ERR_PB_ADDR_ADDR(base) ((base) + (0x5920UL))
#define SOC_NPU_AICORE_SU_1BIT_ECC_ERR_DTAG_ADDR_ADDR(base) ((base) + (0x5924UL))
#define SOC_NPU_AICORE_SU_1BIT_ECC_ERR_DDAT_ADDR_ADDR(base) ((base) + (0x5928UL))
#define SOC_NPU_AICORE_SU_SPR_STATUS_DFX_L_ADDR(base) ((base) + (0x5930UL))
#define SOC_NPU_AICORE_SU_SPR_STATUS_DFX_H_ADDR(base) ((base) + (0x5934UL))
#define SOC_NPU_AICORE_SU_SAFETY_1BIT_ECC_ERR_NUM_ADDR(base) ((base) + (0x5a00UL))
#define SOC_NPU_AICORE_SU_1BIT_ECC_MHIT_CNT_REG_ADDR(base) ((base) + (0x5a04UL))
#define SOC_NPU_AICORE_SU_SAFETY_1BIT_ECC_ERR_TH_ADDR(base) ((base) + (0x5a08UL))
#define SOC_NPU_AICORE_SU_TASK_START_PC_L_ADDR(base) ((base) + (0x5a80UL))
#define SOC_NPU_AICORE_SU_TASK_START_PC_H_ADDR(base) ((base) + (0x5a84UL))
#define SOC_NPU_AICORE_SU_RESERVED_RO_REG0_ADDR(base) ((base) + (0x5b00UL))
#define SOC_NPU_AICORE_SU_RESERVED_RO_REG1_ADDR(base) ((base) + (0x5b04UL))
#define SOC_NPU_AICORE_SU_RESERVED_RW_REG0_ADDR(base) ((base) + (0x5b08UL))
#define SOC_NPU_AICORE_SU_RESERVED_RW_REG1_ADDR(base) ((base) + (0x5b0CUL))
#else
#define SOC_NPU_AICORE_SU_KIS_START_PC_L_ADDR(base) ((base) + (0x0080))
#define SOC_NPU_AICORE_SU_KIS_START_PC_H_ADDR(base) ((base) + (0x0084))
#define SOC_NPU_AICORE_SU_KIS_PARAM_BASE_L_ADDR(base) ((base) + (0x0088))
#define SOC_NPU_AICORE_SU_KIS_PARAM_BASE_H_ADDR(base) ((base) + (0x008C))
#define SOC_NPU_AICORE_SU_KIS_BLOCK_ID_DIM_ADDR(base) ((base) + (0x0090))
#define SOC_NPU_AICORE_SU_KIS_THREAD_ID_DIM_ADDR(base) ((base) + (0x0094))
#define SOC_NPU_AICORE_SU_KIS_SUBBLOCK_ID_ADDR(base) ((base) + (0x0098))
#define SOC_NPU_AICORE_SU_KIS_DATA_SIZE_ADDR(base) ((base) + (0x009C))
#define SOC_NPU_AICORE_SU_KIS_STACK_PHY_BASE_L_ADDR(base) ((base) + (0x00A0))
#define SOC_NPU_AICORE_SU_KIS_STACK_PHY_BASE_H_ADDR(base) ((base) + (0x00A4))
#define SOC_NPU_AICORE_KIS_SMMU_SUBSTREAMID_ADDR(base) ((base) + (0x00A8))
#define SOC_NPU_AICORE_KIS_SMMU_SUBSTREAMID_EN_ADDR(base) ((base) + (0x00AC))
#define SOC_NPU_AICORE_KIS_SU_PRELOAD_SAT_MODE_ADDR(base) ((base) + (0x00B0))
#define SOC_NPU_AICORE_KIS_TASK_CFG_ADDR(base) ((base) + (0x00B4))
#define SOC_NPU_AICORE_KIS_SU_GROUP_DIM_ID_CFG_ADDR(base) ((base) + (0x00C8))
#define SOC_NPU_AICORE_KIS_SU_GROUP_BLK_DIM_ID_CFG_ADDR(base) ((base) + (0x00CC))
#define SOC_NPU_AICORE_SU_KIS_DATA_MAIN_BASE_L_ADDR(base) ((base) + (0x00D0))
#define SOC_NPU_AICORE_SU_KIS_DATA_MAIN_BASE_H_ADDR(base) ((base) + (0x00D4))
#define SOC_NPU_AICORE_SU_KIS_DATA_UB_BASE_L_ADDR(base) ((base) + (0x00D8))
#define SOC_NPU_AICORE_SU_KIS_DATA_UB_BASE_H_ADDR(base) ((base) + (0x00DC))
#define SOC_NPU_AICORE_SEC_SYS_VA_BASE_L_ADDR(base) ((base) + (0x1200))
#define SOC_NPU_AICORE_SEC_SYS_VA_BASE_H_ADDR(base) ((base) + (0x1204))
#define SOC_NPU_AICORE_AIC_UB_BASE_OFFSET_ADDR(base) ((base) + (0x1210))
#define SOC_NPU_AICORE_GLB_AIC_CLK_GATE_MASK_ADDR(base) ((base) + (0x2000))
#define SOC_NPU_AICORE_GLB_AIC_EXCPT_CLR_ADDR(base) ((base) + (0x2010))
#define SOC_NPU_AICORE_GLB_AIC_SAFETY_REG_PTY_CTL_ADDR(base) ((base) + (0x2020))
#define SOC_NPU_AICORE_GLB_PMU_EN_ADDR(base) ((base) + (0x2400))
#define SOC_NPU_AICORE_GLB_L2_VADDR_BASE_L_ADDR(base) ((base) + (0x2410))
#define SOC_NPU_AICORE_GLB_L2_VADDR_BASE_H_ADDR(base) ((base) + (0x2414))
#define SOC_NPU_AICORE_GLB_PMU_IDX_ADDR(base,pmu_cnt_n) ((base) + (0x2500+0x4*(pmu_cnt_n)))
#define SOC_NPU_AICORE_SU_CLK_GATE_MASK_0_ADDR(base) ((base) + (0x5000))
#define SOC_NPU_AICORE_SU_CLK_DELAY_CNT_0_ADDR(base) ((base) + (0x5008))
#define SOC_NPU_AICORE_SU_CLK_DELAY_CNT_1_ADDR(base) ((base) + (0x500C))
#define SOC_NPU_AICORE_SU_ECC_CTRL_0_ADDR(base) ((base) + (0x5020))
#define SOC_NPU_AICORE_SU_ECC_INJECT_CTRL_0_ADDR(base) ((base) + (0x5024))
#define SOC_NPU_AICORE_SU_IFU_CTRL_ADDR(base) ((base) + (0x5030))
#define SOC_NPU_AICORE_SU_CCU_CTRL_ADDR(base) ((base) + (0x5040))
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_ADDR(base) ((base) + (0x5044))
#define SOC_NPU_AICORE_SU_LSU_CTRL_ADDR(base) ((base) + (0x5050))
#define SOC_NPU_AICORE_SU_LSU_MPU_CTRL_ADDR(base) ((base) + (0x5054))
#define SOC_NPU_AICORE_SU_LSU_STB_CTRL_ADDR(base) ((base) + (0x5058))
#define SOC_NPU_AICORE_SU_SEQ_CTRL_ADDR(base) ((base) + (0x5060))
#define SOC_NPU_AICORE_SU_SPR_STATUS_L_ADDR(base) ((base) + (0x5100))
#define SOC_NPU_AICORE_SU_SPR_STATUS_H_ADDR(base) ((base) + (0x5104))
#define SOC_NPU_AICORE_SU_SPR_CONDITION_L_ADDR(base) ((base) + (0x5108))
#define SOC_NPU_AICORE_SU_SPR_CONDITION_H_ADDR(base) ((base) + (0x510C))
#define SOC_NPU_AICORE_SU_SPR_ARCH_VER_L_ADDR(base) ((base) + (0x5110))
#define SOC_NPU_AICORE_SU_SPR_ARCH_VER_H_ADDR(base) ((base) + (0x5114))
#define SOC_NPU_AICORE_SU_SPR_COREID_ADDR(base) ((base) + (0x5118))
#define SOC_NPU_AICORE_SU_AIC_CORE_MODEL_ID_ADDR(base) ((base) + (0x511C))
#define SOC_NPU_AICORE_SU_AIC_ISA_VER_L_ADDR(base) ((base) + (0x5120))
#define SOC_NPU_AICORE_SU_AIC_ISA_VER_H_ADDR(base) ((base) + (0x5124))
#define SOC_NPU_AICORE_SU_AIC_UARCH_VER_L_ADDR(base) ((base) + (0x5128))
#define SOC_NPU_AICORE_SU_AIC_UARCH_VER_H_ADDR(base) ((base) + (0x512C))
#define SOC_NPU_AICORE_SU_AIC_GEN_HW_CFG_L_ADDR(base) ((base) + (0x5130))
#define SOC_NPU_AICORE_SU_AIC_GEN_HW_CFG_H_ADDR(base) ((base) + (0x5134))
#define SOC_NPU_AICORE_SU_AIC_BRANCH_VER_L_ADDR(base) ((base) + (0x5138))
#define SOC_NPU_AICORE_SU_AIC_BRANCH_VER_H_ADDR(base) ((base) + (0x513C))
#define SOC_NPU_AICORE_SU_IC_INV_VA_L_ADDR(base) ((base) + (0x5200))
#define SOC_NPU_AICORE_SU_IC_INV_VA_H_ADDR(base) ((base) + (0x5204))
#define SOC_NPU_AICORE_SU_DBG_CTRL_ADDR(base) ((base) + (0x5300))
#define SOC_NPU_AICORE_SU_DBG_INT_MASK_ADDR(base) ((base) + (0x5304))
#define SOC_NPU_AICORE_SU_DBG_STATUS_ADDR(base) ((base) + (0x5308))
#define SOC_NPU_AICORE_SU_HW_BKPT_EN_ADDR(base) ((base) + (0x5310))
#define SOC_NPU_AICORE_SU_HW_BKPT0_PC_L_ADDR(base) ((base) + (0x5320))
#define SOC_NPU_AICORE_SU_HW_BKPT0_PC_H_ADDR(base) ((base) + (0x5324))
#define SOC_NPU_AICORE_SU_HW_BKPT1_PC_L_ADDR(base) ((base) + (0x5328))
#define SOC_NPU_AICORE_SU_HW_BKPT1_PC_H_ADDR(base) ((base) + (0x532C))
#define SOC_NPU_AICORE_SU_HW_BKPT2_PC_L_ADDR(base) ((base) + (0x5330))
#define SOC_NPU_AICORE_SU_HW_BKPT2_PC_H_ADDR(base) ((base) + (0x5334))
#define SOC_NPU_AICORE_SU_HW_BKPT3_PC_L_ADDR(base) ((base) + (0x5338))
#define SOC_NPU_AICORE_SU_HW_BKPT3_PC_H_ADDR(base) ((base) + (0x533C))
#define SOC_NPU_AICORE_SU_HW_BKPT0_TWO_LEVLE_SMID_ADDR(base) ((base) + (0x53a0))
#define SOC_NPU_AICORE_SU_HW_BKPT1_TWO_LEVLE_SMID_ADDR(base) ((base) + (0x53a4))
#define SOC_NPU_AICORE_SU_HW_BKPT2_TWO_LEVLE_SMID_ADDR(base) ((base) + (0x53a8))
#define SOC_NPU_AICORE_SU_HW_BKPT3_TWO_LEVLE_SMID_ADDR(base) ((base) + (0x53aC))
#define SOC_NPU_AICORE_SU_PRE_RST_STALL_CTRL_ADDR(base) ((base) + (0x5600))
#define SOC_NPU_AICORE_SU_PRE_RST_STATUS_ADDR(base) ((base) + (0x5604))
#define SOC_NPU_AICORE_SU_INNER_STATUS_ADDR(base) ((base) + (0x5608))
#define SOC_NPU_AICORE_SU_ERROR_T0_0_ADDR(base) ((base) + (0x5700))
#define SOC_NPU_AICORE_SU_ERROR_T1_0_ADDR(base) ((base) + (0x5710))
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_ADDR(base) ((base) + (0x5720))
#define SOC_NPU_AICORE_SU_ERR_INFO_T0_0_ADDR(base) ((base) + (0x5730))
#define SOC_NPU_AICORE_SU_ERR_INFO_T0_1_ADDR(base) ((base) + (0x5734))
#define SOC_NPU_AICORE_SU_ERR_INFO_T0_2_ADDR(base) ((base) + (0x5738))
#define SOC_NPU_AICORE_SU_ERR_INFO_T0_3_ADDR(base) ((base) + (0x573C))
#define SOC_NPU_AICORE_SU_ERR_INFO_T1_0_ADDR(base) ((base) + (0x5750))
#define SOC_NPU_AICORE_SU_ERR_INFO_T1_1_ADDR(base) ((base) + (0x5754))
#define SOC_NPU_AICORE_SU_ERR_INFO_T1_2_ADDR(base) ((base) + (0x5758))
#define SOC_NPU_AICORE_SU_ERR_INFO_T1_3_ADDR(base) ((base) + (0x575C))
#define SOC_NPU_AICORE_SU_WARN_T0_0_ADDR(base) ((base) + (0x5900))
#define SOC_NPU_AICORE_SU_WARN_T1_0_ADDR(base) ((base) + (0x5908))
#define SOC_NPU_AICORE_SU_WARN_MASK_0_ADDR(base) ((base) + (0x5910))
#define SOC_NPU_AICORE_SU_1BIT_ECC_ERR_PB_ADDR_ADDR(base) ((base) + (0x5920))
#define SOC_NPU_AICORE_SU_1BIT_ECC_ERR_DTAG_ADDR_ADDR(base) ((base) + (0x5924))
#define SOC_NPU_AICORE_SU_1BIT_ECC_ERR_DDAT_ADDR_ADDR(base) ((base) + (0x5928))
#define SOC_NPU_AICORE_SU_SPR_STATUS_DFX_L_ADDR(base) ((base) + (0x5930))
#define SOC_NPU_AICORE_SU_SPR_STATUS_DFX_H_ADDR(base) ((base) + (0x5934))
#define SOC_NPU_AICORE_SU_SAFETY_1BIT_ECC_ERR_NUM_ADDR(base) ((base) + (0x5a00))
#define SOC_NPU_AICORE_SU_1BIT_ECC_MHIT_CNT_REG_ADDR(base) ((base) + (0x5a04))
#define SOC_NPU_AICORE_SU_SAFETY_1BIT_ECC_ERR_TH_ADDR(base) ((base) + (0x5a08))
#define SOC_NPU_AICORE_SU_TASK_START_PC_L_ADDR(base) ((base) + (0x5a80))
#define SOC_NPU_AICORE_SU_TASK_START_PC_H_ADDR(base) ((base) + (0x5a84))
#define SOC_NPU_AICORE_SU_RESERVED_RO_REG0_ADDR(base) ((base) + (0x5b00))
#define SOC_NPU_AICORE_SU_RESERVED_RO_REG1_ADDR(base) ((base) + (0x5b04))
#define SOC_NPU_AICORE_SU_RESERVED_RW_REG0_ADDR(base) ((base) + (0x5b08))
#define SOC_NPU_AICORE_SU_RESERVED_RW_REG1_ADDR(base) ((base) + (0x5b0C))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_AICORE_SU_KIS_START_PC_L_ADDR(base) ((base) + (0x0080UL))
#define SOC_NPU_AICORE_SU_KIS_START_PC_H_ADDR(base) ((base) + (0x0084UL))
#define SOC_NPU_AICORE_AIC_UB_BASE_OFFSET_ADDR(base) ((base) + (0x1210UL))
#define SOC_NPU_AICORE_SEC_MTE_PCIE_TYPE_BST_LN_ADDR(base) ((base) + (0x1500UL))
#define SOC_NPU_AICORE_SEC_MTE_PCIE_WIN_SZ_ADDR(base) ((base) + (0x1504UL))
#define SOC_NPU_AICORE_SEC_MTE_PCIE_WIN_BS_ADDR(base) ((base) + (0x1508UL))
#define SOC_NPU_AICORE_SEC_MTE_PCIE_ENABLE_ADDR(base) ((base) + (0x150CUL))
#define SOC_NPU_AICORE_GLB_AIC_CLK_GATE_MASK_ADDR(base) ((base) + (0x2000UL))
#define SOC_NPU_AICORE_GLB_AIC_EXCPT_CLR_ADDR(base) ((base) + (0x2010UL))
#define SOC_NPU_AICORE_GLB_AIC_SAFETY_REG_PTY_CTL_ADDR(base) ((base) + (0x2020UL))
#define SOC_NPU_AICORE_GLB_CONTEXT_SWITCH_CTRL_0_ADDR(base) ((base) + (0x2030UL))
#define SOC_NPU_AICORE_GLB_CONTEXT_SWITCH_CTRL_1_ADDR(base) ((base) + (0x2034UL))
#define SOC_NPU_AICORE_GLB_PMU_EN_ADDR(base) ((base) + (0x2400UL))
#define SOC_NPU_AICORE_GLB_PMU_IDX_ADDR(base,pmu_cnt_n) ((base) + (0x2500+0x4*(pmu_cnt_n)))
#define SOC_NPU_AICORE_GLB_ADDR_INTLV_CFG_ADDR(base) ((base) + (0x2808UL))
#define SOC_NPU_AICORE_MTE_CLK_GATE_MASK_0_ADDR(base) ((base) + (0x6000UL))
#define SOC_NPU_AICORE_MTE_CLK_GATE_MASK_1_ADDR(base) ((base) + (0x6004UL))
#define SOC_NPU_AICORE_MTE_ECC_CTRL_0_ADDR(base) ((base) + (0x6020UL))
#define SOC_NPU_AICORE_MTE_ECC_INJECT_CTRL_0_ADDR(base) ((base) + (0x6024UL))
#define SOC_NPU_AICORE_MTE_FAULT_INJ_EN_ADDR(base) ((base) + (0x6028UL))
#define SOC_NPU_AICORE_MTE_FAULT_INJ_MASK_ADDR(base) ((base) + (0x602CUL))
#define SOC_NPU_AICORE_MTE_PRE_RST_STALL_CTRL_ADDR(base) ((base) + (0x6600UL))
#define SOC_NPU_AICORE_MTE_PRE_RST_STATUS_ADDR(base) ((base) + (0x6604UL))
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_ADDR(base) ((base) + (0x6700UL))
#define SOC_NPU_AICORE_MTE_ERROR_T0_1_ADDR(base) ((base) + (0x6704UL))
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_ADDR(base) ((base) + (0x6708UL))
#define SOC_NPU_AICORE_MTE_ERROR_T1_1_ADDR(base) ((base) + (0x670CUL))
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_ADDR(base) ((base) + (0x6710UL))
#define SOC_NPU_AICORE_MTE_ERROR_MASK_1_ADDR(base) ((base) + (0x6714UL))
#define SOC_NPU_AICORE_MTE_ERR_INFO_T0_0_ADDR(base) ((base) + (0x6718UL))
#define SOC_NPU_AICORE_MTE_ERR_INFO_T0_1_ADDR(base) ((base) + (0x671CUL))
#define SOC_NPU_AICORE_MTE_ERR_INFO_T0_2_ADDR(base) ((base) + (0x6720UL))
#define SOC_NPU_AICORE_MTE_ERR_INFO_T1_0_ADDR(base) ((base) + (0x6724UL))
#define SOC_NPU_AICORE_MTE_ERR_INFO_T1_1_ADDR(base) ((base) + (0x6728UL))
#define SOC_NPU_AICORE_MTE_ERR_INFO_T1_2_ADDR(base) ((base) + (0x673CUL))
#define SOC_NPU_AICORE_MTE_WARN_T0_0_ADDR(base) ((base) + (0x6900UL))
#define SOC_NPU_AICORE_MTE_WARN_T1_0_ADDR(base) ((base) + (0x6904UL))
#define SOC_NPU_AICORE_MTE_WARN_MASK_0_ADDR(base) ((base) + (0x6908UL))
#define SOC_NPU_AICORE_MTE_1BIT_ECC_ERR_ADDR_0_ADDR(base) ((base) + (0x6910UL))
#define SOC_NPU_AICORE_MTE_1BIT_ECC_ERR_ADDR_1_ADDR(base) ((base) + (0x6914UL))
#define SOC_NPU_AICORE_MTE_1BIT_ECC_ERR_ADDR_2_ADDR(base) ((base) + (0x6918UL))
#define SOC_NPU_AICORE_MTE_CTRL_ADDR(base) ((base) + (0x6A00UL))
#define SOC_NPU_AICORE_MTE_CTRL2_ADDR(base) ((base) + (0x6A04UL))
#define SOC_NPU_AICORE_MTE_AIPP_CTRL_ADDR(base) ((base) + (0x6A08UL))
#define SOC_NPU_AICORE_MTE_WAIPP_CTRL_ADDR(base) ((base) + (0x6A0CUL))
#define SOC_NPU_AICORE_MTE_RESERVED_RO_REG0_ADDR(base) ((base) + (0x6A1CUL))
#define SOC_NPU_AICORE_MTE_RESERVED_RO_REG1_ADDR(base) ((base) + (0x6A20UL))
#define SOC_NPU_AICORE_MTE_RESERVED_RW_REG0_ADDR(base) ((base) + (0x6A24UL))
#define SOC_NPU_AICORE_MTE_RESERVED_RW_REG1_ADDR(base) ((base) + (0x6A28UL))
#define SOC_NPU_AICORE_COMMON_BK_GLB_CLK_GATE_MASK_ADDR(base) ((base) + (0x6B04UL))
#define SOC_NPU_AICORE_COMMON_BK_MTE_CLK_GATE_MASK_0_ADDR(base) ((base) + (0x6B08UL))
#define SOC_NPU_AICORE_COMMON_BK_MTE_CLK_GATE_MASK_1_ADDR(base) ((base) + (0x6B0CUL))
#define SOC_NPU_AICORE_COMMON_BK_MTE_WARN_MASK_0_ADDR(base) ((base) + (0x6B10UL))
#define SOC_NPU_AICORE_COMMON_BK_MTE_ERROR_MASK_0_ADDR(base) ((base) + (0x6B14UL))
#else
#define SOC_NPU_AICORE_SU_KIS_START_PC_L_ADDR(base) ((base) + (0x0080))
#define SOC_NPU_AICORE_SU_KIS_START_PC_H_ADDR(base) ((base) + (0x0084))
#define SOC_NPU_AICORE_AIC_UB_BASE_OFFSET_ADDR(base) ((base) + (0x1210))
#define SOC_NPU_AICORE_SEC_MTE_PCIE_TYPE_BST_LN_ADDR(base) ((base) + (0x1500))
#define SOC_NPU_AICORE_SEC_MTE_PCIE_WIN_SZ_ADDR(base) ((base) + (0x1504))
#define SOC_NPU_AICORE_SEC_MTE_PCIE_WIN_BS_ADDR(base) ((base) + (0x1508))
#define SOC_NPU_AICORE_SEC_MTE_PCIE_ENABLE_ADDR(base) ((base) + (0x150C))
#define SOC_NPU_AICORE_GLB_AIC_CLK_GATE_MASK_ADDR(base) ((base) + (0x2000))
#define SOC_NPU_AICORE_GLB_AIC_EXCPT_CLR_ADDR(base) ((base) + (0x2010))
#define SOC_NPU_AICORE_GLB_AIC_SAFETY_REG_PTY_CTL_ADDR(base) ((base) + (0x2020))
#define SOC_NPU_AICORE_GLB_CONTEXT_SWITCH_CTRL_0_ADDR(base) ((base) + (0x2030))
#define SOC_NPU_AICORE_GLB_CONTEXT_SWITCH_CTRL_1_ADDR(base) ((base) + (0x2034))
#define SOC_NPU_AICORE_GLB_PMU_EN_ADDR(base) ((base) + (0x2400))
#define SOC_NPU_AICORE_GLB_PMU_IDX_ADDR(base,pmu_cnt_n) ((base) + (0x2500+0x4*(pmu_cnt_n)))
#define SOC_NPU_AICORE_GLB_ADDR_INTLV_CFG_ADDR(base) ((base) + (0x2808))
#define SOC_NPU_AICORE_MTE_CLK_GATE_MASK_0_ADDR(base) ((base) + (0x6000))
#define SOC_NPU_AICORE_MTE_CLK_GATE_MASK_1_ADDR(base) ((base) + (0x6004))
#define SOC_NPU_AICORE_MTE_ECC_CTRL_0_ADDR(base) ((base) + (0x6020))
#define SOC_NPU_AICORE_MTE_ECC_INJECT_CTRL_0_ADDR(base) ((base) + (0x6024))
#define SOC_NPU_AICORE_MTE_FAULT_INJ_EN_ADDR(base) ((base) + (0x6028))
#define SOC_NPU_AICORE_MTE_FAULT_INJ_MASK_ADDR(base) ((base) + (0x602C))
#define SOC_NPU_AICORE_MTE_PRE_RST_STALL_CTRL_ADDR(base) ((base) + (0x6600))
#define SOC_NPU_AICORE_MTE_PRE_RST_STATUS_ADDR(base) ((base) + (0x6604))
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_ADDR(base) ((base) + (0x6700))
#define SOC_NPU_AICORE_MTE_ERROR_T0_1_ADDR(base) ((base) + (0x6704))
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_ADDR(base) ((base) + (0x6708))
#define SOC_NPU_AICORE_MTE_ERROR_T1_1_ADDR(base) ((base) + (0x670C))
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_ADDR(base) ((base) + (0x6710))
#define SOC_NPU_AICORE_MTE_ERROR_MASK_1_ADDR(base) ((base) + (0x6714))
#define SOC_NPU_AICORE_MTE_ERR_INFO_T0_0_ADDR(base) ((base) + (0x6718))
#define SOC_NPU_AICORE_MTE_ERR_INFO_T0_1_ADDR(base) ((base) + (0x671C))
#define SOC_NPU_AICORE_MTE_ERR_INFO_T0_2_ADDR(base) ((base) + (0x6720))
#define SOC_NPU_AICORE_MTE_ERR_INFO_T1_0_ADDR(base) ((base) + (0x6724))
#define SOC_NPU_AICORE_MTE_ERR_INFO_T1_1_ADDR(base) ((base) + (0x6728))
#define SOC_NPU_AICORE_MTE_ERR_INFO_T1_2_ADDR(base) ((base) + (0x673C))
#define SOC_NPU_AICORE_MTE_WARN_T0_0_ADDR(base) ((base) + (0x6900))
#define SOC_NPU_AICORE_MTE_WARN_T1_0_ADDR(base) ((base) + (0x6904))
#define SOC_NPU_AICORE_MTE_WARN_MASK_0_ADDR(base) ((base) + (0x6908))
#define SOC_NPU_AICORE_MTE_1BIT_ECC_ERR_ADDR_0_ADDR(base) ((base) + (0x6910))
#define SOC_NPU_AICORE_MTE_1BIT_ECC_ERR_ADDR_1_ADDR(base) ((base) + (0x6914))
#define SOC_NPU_AICORE_MTE_1BIT_ECC_ERR_ADDR_2_ADDR(base) ((base) + (0x6918))
#define SOC_NPU_AICORE_MTE_CTRL_ADDR(base) ((base) + (0x6A00))
#define SOC_NPU_AICORE_MTE_CTRL2_ADDR(base) ((base) + (0x6A04))
#define SOC_NPU_AICORE_MTE_AIPP_CTRL_ADDR(base) ((base) + (0x6A08))
#define SOC_NPU_AICORE_MTE_WAIPP_CTRL_ADDR(base) ((base) + (0x6A0C))
#define SOC_NPU_AICORE_MTE_RESERVED_RO_REG0_ADDR(base) ((base) + (0x6A1C))
#define SOC_NPU_AICORE_MTE_RESERVED_RO_REG1_ADDR(base) ((base) + (0x6A20))
#define SOC_NPU_AICORE_MTE_RESERVED_RW_REG0_ADDR(base) ((base) + (0x6A24))
#define SOC_NPU_AICORE_MTE_RESERVED_RW_REG1_ADDR(base) ((base) + (0x6A28))
#define SOC_NPU_AICORE_COMMON_BK_GLB_CLK_GATE_MASK_ADDR(base) ((base) + (0x6B04))
#define SOC_NPU_AICORE_COMMON_BK_MTE_CLK_GATE_MASK_0_ADDR(base) ((base) + (0x6B08))
#define SOC_NPU_AICORE_COMMON_BK_MTE_CLK_GATE_MASK_1_ADDR(base) ((base) + (0x6B0C))
#define SOC_NPU_AICORE_COMMON_BK_MTE_WARN_MASK_0_ADDR(base) ((base) + (0x6B10))
#define SOC_NPU_AICORE_COMMON_BK_MTE_ERROR_MASK_0_ADDR(base) ((base) + (0x6B14))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_AICORE_SU_KIS_BLOCK_ID_DIM_ADDR(base) ((base) + (0x0090UL))
#define SOC_NPU_AICORE_SU_KIS_THREAD_ID_DIM_ADDR(base) ((base) + (0x0094UL))
#define SOC_NPU_AICORE_SU_KIS_SUBBLOCK_ID_ADDR(base) ((base) + (0x0098UL))
#define SOC_NPU_AICORE_KIS_SMMU_SUBSTREAMID_ADDR(base) ((base) + (0x00A8UL))
#define SOC_NPU_AICORE_KIS_SMMU_SUBSTREAMID_EN_ADDR(base) ((base) + (0x00ACUL))
#define SOC_NPU_AICORE_KIS_SIMT_STK_BASE_L_ADDR(base) ((base) + (0x00E0UL))
#define SOC_NPU_AICORE_KIS_SIMT_STK_BASE_H_ADDR(base) ((base) + (0x00E4UL))
#define SOC_NPU_AICORE_KIS_SIMT_WARP_STK_SIZE_ADDR(base) ((base) + (0x00E8UL))
#define SOC_NPU_AICORE_KIS_SIMT_UB_SIZE_ADDR(base) ((base) + (0x00ECUL))
#define SOC_NPU_AICORE_KIS_SIMT_DVG_WARP_STACK_SIZE_ADDR(base) ((base) + (0x00F0UL))
#define SOC_NPU_AICORE_SEC_SYS_VA_BASE_L_ADDR(base) ((base) + (0x1200UL))
#define SOC_NPU_AICORE_SEC_SYS_VA_BASE_H_ADDR(base) ((base) + (0x1204UL))
#define SOC_NPU_AICORE_AIC_UB_BASE_OFFSET_ADDR(base) ((base) + (0x1210UL))
#define SOC_NPU_AICORE_GLB_AIC_CLK_GATE_MASK_ADDR(base) ((base) + (0x2000UL))
#define SOC_NPU_AICORE_GLB_AIC_EXCPT_CLR_ADDR(base) ((base) + (0x2010UL))
#define SOC_NPU_AICORE_GLB_AIC_SAFETY_REG_PTY_CTL_ADDR(base) ((base) + (0x2020UL))
#define SOC_NPU_AICORE_GLB_PMU_EN_ADDR(base) ((base) + (0x2400UL))
#define SOC_NPU_AICORE_GLB_PMU_IDX_ADDR(base,pmu_cnt_n) ((base) + (0x2500+0x4*(pmu_cnt_n)))
#define SOC_NPU_AICORE_VEC_ECC_CTRL_0_ADDR(base) ((base) + (0x7000UL))
#define SOC_NPU_AICORE_VEC_ECC_INJECT_CTRL_0_ADDR(base) ((base) + (0x7004UL))
#define SOC_NPU_AICORE_VEC_CFG_ADDR(base) ((base) + (0x7008UL))
#define SOC_NPU_AICORE_VEC_SIMT_CFG_0_ADDR(base) ((base) + (0x0010UL))
#define SOC_NPU_AICORE_VEC_SIMT_CFG_1_ADDR(base) ((base) + (0x0014UL))
#define SOC_NPU_AICORE_VEC_CLK_GATE_MASK_0_ADDR(base) ((base) + (0x7040UL))
#define SOC_NPU_AICORE_VEC_CLK_GATE_MASK_1_ADDR(base) ((base) + (0x7044UL))
#define SOC_NPU_AICORE_VEC_FCSW_PERIOD_ADDR(base) ((base) + (0x7080UL))
#define SOC_NPU_AICORE_VEC_FCSW_THR_LOW_ADDR(base) ((base) + (0x7084UL))
#define SOC_NPU_AICORE_VEC_FCSW_THR_HIGH_ADDR(base) ((base) + (0x7088UL))
#define SOC_NPU_AICORE_VEC_PRE_RST_STALL_CTRL_ADDR(base) ((base) + (0x70C0UL))
#define SOC_NPU_AICORE_VEC_PRE_RST_STATUS_ADDR(base) ((base) + (0x70C4UL))
#define SOC_NPU_AICORE_VEC_SISS_MODE_EN_CFG_ADDR(base) ((base) + (0x7100UL))
#define SOC_NPU_AICORE_VEC_DBG_HW_BKPT_EN_ADDR(base) ((base) + (0x7104UL))
#define SOC_NPU_AICORE_VEC_DBG_CTRL_CFG_ADDR(base) ((base) + (0x7108UL))
#define SOC_NPU_AICORE_VEC_DBG_STATUS_ADDR(base) ((base) + (0x710CUL))
#define SOC_NPU_AICORE_VEC_DBG_BKPT_SID_CFG_ADDR(base) ((base) + (0x7110UL))
#define SOC_NPU_AICORE_VEC_DBG_BKPT_SSID_CFG_ADDR(base) ((base) + (0x7114UL))
#define SOC_NPU_AICORE_VEC_DBG_BKPT_ADDR_ADDR(base,dbg_bkpt_num) ((base) + (0x7118+0x4*(dbg_bkpt_num)))
#define SOC_NPU_AICORE_VEC_DBG_BKPT_ADDR_EXT_ADDR(base,dbg_bkpt_num) ((base) + (0x7128+0x4*(dbg_bkpt_num)))
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_ADDR(base) ((base) + (0x7700UL))
#define SOC_NPU_AICORE_VEC_ERROR_T0_2_ADDR(base) ((base) + (0x7708UL))
#define SOC_NPU_AICORE_VEC_ERROR_T1_0_ADDR(base) ((base) + (0x7710UL))
#define SOC_NPU_AICORE_VEC_ERROR_T1_2_ADDR(base) ((base) + (0x7718UL))
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_ADDR(base) ((base) + (0x7720UL))
#define SOC_NPU_AICORE_VEC_ERROR_MASK_2_ADDR(base) ((base) + (0x7728UL))
#define SOC_NPU_AICORE_VEC_ERR_INFO_T0_0_ADDR(base) ((base) + (0x7730UL))
#define SOC_NPU_AICORE_VEC_ERR_INFO_T0_1_ADDR(base) ((base) + (0x7734UL))
#define SOC_NPU_AICORE_VEC_ERR_INFO_T0_2_ADDR(base) ((base) + (0x7738UL))
#define SOC_NPU_AICORE_VEC_ERR_INFO_T0_3_ADDR(base) ((base) + (0x773CUL))
#define SOC_NPU_AICORE_VEC_ERR_INFO_T0_4_ADDR(base) ((base) + (0x7740UL))
#define SOC_NPU_AICORE_VEC_ERR_INFO_T0_5_ADDR(base) ((base) + (0x7744UL))
#define SOC_NPU_AICORE_VEC_ERR_INFO_T1_0_ADDR(base) ((base) + (0x7750UL))
#define SOC_NPU_AICORE_VEC_ERR_INFO_T1_1_ADDR(base) ((base) + (0x7754UL))
#define SOC_NPU_AICORE_VEC_ERR_INFO_T1_2_ADDR(base) ((base) + (0x7758UL))
#define SOC_NPU_AICORE_VEC_ERR_INFO_T1_3_ADDR(base) ((base) + (0x775CUL))
#define SOC_NPU_AICORE_VEC_ERR_INFO_T1_4_ADDR(base) ((base) + (0x7760UL))
#define SOC_NPU_AICORE_VEC_ERR_INFO_T1_5_ADDR(base) ((base) + (0x7764UL))
#define SOC_NPU_AICORE_VEC_WARN_T0_0_ADDR(base) ((base) + (0x7900UL))
#define SOC_NPU_AICORE_VEC_WARN_T1_0_ADDR(base) ((base) + (0x7910UL))
#define SOC_NPU_AICORE_VEC_WARN_MASK_0_ADDR(base) ((base) + (0x7920UL))
#define SOC_NPU_AICORE_VEC_WARN_INFO_T0_0_ADDR(base) ((base) + (0x7930UL))
#define SOC_NPU_AICORE_VEC_RESERVED_REG0_ADDR(base) ((base) + (0x7FE0UL))
#define SOC_NPU_AICORE_VEC_RESERVED_REG1_ADDR(base) ((base) + (0x7FE4UL))
#define SOC_NPU_AICORE_VEC_RESERVED_RO_REG0_ADDR(base) ((base) + (0x7FF0UL))
#define SOC_NPU_AICORE_VEC_RESERVED_RO_REG1_ADDR(base) ((base) + (0x7FF4UL))
#else
#define SOC_NPU_AICORE_SU_KIS_BLOCK_ID_DIM_ADDR(base) ((base) + (0x0090))
#define SOC_NPU_AICORE_SU_KIS_THREAD_ID_DIM_ADDR(base) ((base) + (0x0094))
#define SOC_NPU_AICORE_SU_KIS_SUBBLOCK_ID_ADDR(base) ((base) + (0x0098))
#define SOC_NPU_AICORE_KIS_SMMU_SUBSTREAMID_ADDR(base) ((base) + (0x00A8))
#define SOC_NPU_AICORE_KIS_SMMU_SUBSTREAMID_EN_ADDR(base) ((base) + (0x00AC))
#define SOC_NPU_AICORE_KIS_SIMT_STK_BASE_L_ADDR(base) ((base) + (0x00E0))
#define SOC_NPU_AICORE_KIS_SIMT_STK_BASE_H_ADDR(base) ((base) + (0x00E4))
#define SOC_NPU_AICORE_KIS_SIMT_WARP_STK_SIZE_ADDR(base) ((base) + (0x00E8))
#define SOC_NPU_AICORE_KIS_SIMT_UB_SIZE_ADDR(base) ((base) + (0x00EC))
#define SOC_NPU_AICORE_KIS_SIMT_DVG_WARP_STACK_SIZE_ADDR(base) ((base) + (0x00F0))
#define SOC_NPU_AICORE_SEC_SYS_VA_BASE_L_ADDR(base) ((base) + (0x1200))
#define SOC_NPU_AICORE_SEC_SYS_VA_BASE_H_ADDR(base) ((base) + (0x1204))
#define SOC_NPU_AICORE_AIC_UB_BASE_OFFSET_ADDR(base) ((base) + (0x1210))
#define SOC_NPU_AICORE_GLB_AIC_CLK_GATE_MASK_ADDR(base) ((base) + (0x2000))
#define SOC_NPU_AICORE_GLB_AIC_EXCPT_CLR_ADDR(base) ((base) + (0x2010))
#define SOC_NPU_AICORE_GLB_AIC_SAFETY_REG_PTY_CTL_ADDR(base) ((base) + (0x2020))
#define SOC_NPU_AICORE_GLB_PMU_EN_ADDR(base) ((base) + (0x2400))
#define SOC_NPU_AICORE_GLB_PMU_IDX_ADDR(base,pmu_cnt_n) ((base) + (0x2500+0x4*(pmu_cnt_n)))
#define SOC_NPU_AICORE_VEC_ECC_CTRL_0_ADDR(base) ((base) + (0x7000))
#define SOC_NPU_AICORE_VEC_ECC_INJECT_CTRL_0_ADDR(base) ((base) + (0x7004))
#define SOC_NPU_AICORE_VEC_CFG_ADDR(base) ((base) + (0x7008))
#define SOC_NPU_AICORE_VEC_SIMT_CFG_0_ADDR(base) ((base) + (0x0010))
#define SOC_NPU_AICORE_VEC_SIMT_CFG_1_ADDR(base) ((base) + (0x0014))
#define SOC_NPU_AICORE_VEC_CLK_GATE_MASK_0_ADDR(base) ((base) + (0x7040))
#define SOC_NPU_AICORE_VEC_CLK_GATE_MASK_1_ADDR(base) ((base) + (0x7044))
#define SOC_NPU_AICORE_VEC_FCSW_PERIOD_ADDR(base) ((base) + (0x7080))
#define SOC_NPU_AICORE_VEC_FCSW_THR_LOW_ADDR(base) ((base) + (0x7084))
#define SOC_NPU_AICORE_VEC_FCSW_THR_HIGH_ADDR(base) ((base) + (0x7088))
#define SOC_NPU_AICORE_VEC_PRE_RST_STALL_CTRL_ADDR(base) ((base) + (0x70C0))
#define SOC_NPU_AICORE_VEC_PRE_RST_STATUS_ADDR(base) ((base) + (0x70C4))
#define SOC_NPU_AICORE_VEC_SISS_MODE_EN_CFG_ADDR(base) ((base) + (0x7100))
#define SOC_NPU_AICORE_VEC_DBG_HW_BKPT_EN_ADDR(base) ((base) + (0x7104))
#define SOC_NPU_AICORE_VEC_DBG_CTRL_CFG_ADDR(base) ((base) + (0x7108))
#define SOC_NPU_AICORE_VEC_DBG_STATUS_ADDR(base) ((base) + (0x710C))
#define SOC_NPU_AICORE_VEC_DBG_BKPT_SID_CFG_ADDR(base) ((base) + (0x7110))
#define SOC_NPU_AICORE_VEC_DBG_BKPT_SSID_CFG_ADDR(base) ((base) + (0x7114))
#define SOC_NPU_AICORE_VEC_DBG_BKPT_ADDR_ADDR(base,dbg_bkpt_num) ((base) + (0x7118+0x4*(dbg_bkpt_num)))
#define SOC_NPU_AICORE_VEC_DBG_BKPT_ADDR_EXT_ADDR(base,dbg_bkpt_num) ((base) + (0x7128+0x4*(dbg_bkpt_num)))
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_ADDR(base) ((base) + (0x7700))
#define SOC_NPU_AICORE_VEC_ERROR_T0_2_ADDR(base) ((base) + (0x7708))
#define SOC_NPU_AICORE_VEC_ERROR_T1_0_ADDR(base) ((base) + (0x7710))
#define SOC_NPU_AICORE_VEC_ERROR_T1_2_ADDR(base) ((base) + (0x7718))
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_ADDR(base) ((base) + (0x7720))
#define SOC_NPU_AICORE_VEC_ERROR_MASK_2_ADDR(base) ((base) + (0x7728))
#define SOC_NPU_AICORE_VEC_ERR_INFO_T0_0_ADDR(base) ((base) + (0x7730))
#define SOC_NPU_AICORE_VEC_ERR_INFO_T0_1_ADDR(base) ((base) + (0x7734))
#define SOC_NPU_AICORE_VEC_ERR_INFO_T0_2_ADDR(base) ((base) + (0x7738))
#define SOC_NPU_AICORE_VEC_ERR_INFO_T0_3_ADDR(base) ((base) + (0x773C))
#define SOC_NPU_AICORE_VEC_ERR_INFO_T0_4_ADDR(base) ((base) + (0x7740))
#define SOC_NPU_AICORE_VEC_ERR_INFO_T0_5_ADDR(base) ((base) + (0x7744))
#define SOC_NPU_AICORE_VEC_ERR_INFO_T1_0_ADDR(base) ((base) + (0x7750))
#define SOC_NPU_AICORE_VEC_ERR_INFO_T1_1_ADDR(base) ((base) + (0x7754))
#define SOC_NPU_AICORE_VEC_ERR_INFO_T1_2_ADDR(base) ((base) + (0x7758))
#define SOC_NPU_AICORE_VEC_ERR_INFO_T1_3_ADDR(base) ((base) + (0x775C))
#define SOC_NPU_AICORE_VEC_ERR_INFO_T1_4_ADDR(base) ((base) + (0x7760))
#define SOC_NPU_AICORE_VEC_ERR_INFO_T1_5_ADDR(base) ((base) + (0x7764))
#define SOC_NPU_AICORE_VEC_WARN_T0_0_ADDR(base) ((base) + (0x7900))
#define SOC_NPU_AICORE_VEC_WARN_T1_0_ADDR(base) ((base) + (0x7910))
#define SOC_NPU_AICORE_VEC_WARN_MASK_0_ADDR(base) ((base) + (0x7920))
#define SOC_NPU_AICORE_VEC_WARN_INFO_T0_0_ADDR(base) ((base) + (0x7930))
#define SOC_NPU_AICORE_VEC_RESERVED_REG0_ADDR(base) ((base) + (0x7FE0))
#define SOC_NPU_AICORE_VEC_RESERVED_REG1_ADDR(base) ((base) + (0x7FE4))
#define SOC_NPU_AICORE_VEC_RESERVED_RO_REG0_ADDR(base) ((base) + (0x7FF0))
#define SOC_NPU_AICORE_VEC_RESERVED_RO_REG1_ADDR(base) ((base) + (0x7FF4))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_AICORE_GLB_AIC_CLK_GATE_MASK_ADDR(base) ((base) + (0x2000UL))
#define SOC_NPU_AICORE_GLB_AIC_EXCPT_CLR_ADDR(base) ((base) + (0x2010UL))
#define SOC_NPU_AICORE_GLB_AIC_SAFETY_REG_PTY_CTL_ADDR(base) ((base) + (0x2020UL))
#define SOC_NPU_AICORE_GLB_PMU_EN_ADDR(base) ((base) + (0x2400UL))
#define SOC_NPU_AICORE_GLB_PMU_IDX_ADDR(base,pmu_cnt_n) ((base) + (0x2500+0x4*(pmu_cnt_n)))
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_0_ADDR(base) ((base) + (0x8000UL))
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_1_ADDR(base) ((base) + (0x8004UL))
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_2_ADDR(base) ((base) + (0x8008UL))
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_3_ADDR(base) ((base) + (0x800CUL))
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_0_ADDR(base) ((base) + (0x8010UL))
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_1_ADDR(base) ((base) + (0x8014UL))
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_2_ADDR(base) ((base) + (0x8018UL))
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_3_ADDR(base) ((base) + (0x801CUL))
#define SOC_NPU_AICORE_CUBE_VDROP_CTRL_0_ADDR(base) ((base) + (0x8020UL))
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_4_ADDR(base) ((base) + (0x8024UL))
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_4_ADDR(base) ((base) + (0x8028UL))
#define SOC_NPU_AICORE_CUBE_ACTIVE_CTRL_0_ADDR(base) ((base) + (0x8030UL))
#define SOC_NPU_AICORE_CUBE_STALL_DMY_CTRL_0_ADDR(base) ((base) + (0x8040UL))
#define SOC_NPU_AICORE_CUBE_STALL_DMY_CTRL_1_ADDR(base) ((base) + (0x8044UL))
#define SOC_NPU_AICORE_CUBE_ECC_CTRL_0_ADDR(base) ((base) + (0x8050UL))
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_CTRL_0_ADDR(base) ((base) + (0x8054UL))
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0A_0_ADDR(base) ((base) + (0x8058UL))
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0A_WINO_0_ADDR(base) ((base) + (0x805cUL))
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0B_0_ADDR(base) ((base) + (0x8060UL))
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0B_WINO_0_ADDR(base) ((base) + (0x8064UL))
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0C_0_ADDR(base) ((base) + (0x8068UL))
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0C_1_ADDR(base) ((base) + (0x806cUL))
#define SOC_NPU_AICORE_CUBE_CTRL_0_ADDR(base) ((base) + (0x8080UL))
#define SOC_NPU_AICORE_CUBE_ICG_MASK_0_ADDR(base) ((base) + (0x8088UL))
#define SOC_NPU_AICORE_CUBE_ICG_MASK_1_ADDR(base) ((base) + (0x808cUL))
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0A_0_ADDR(base) ((base) + (0x8090UL))
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0A_1_ADDR(base) ((base) + (0x8094UL))
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0B_0_ADDR(base) ((base) + (0x8098UL))
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0B_1_ADDR(base) ((base) + (0x809CUL))
#define SOC_NPU_AICORE_CUBE_PRE_RST_STALL_CTRL_ADDR(base) ((base) + (0x8100UL))
#define SOC_NPU_AICORE_CUBE_PRE_RST_STATUS_ADDR(base) ((base) + (0x8104UL))
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_ADDR(base) ((base) + (0x8700UL))
#define SOC_NPU_AICORE_CUBE_ERROR_T0_1_ADDR(base) ((base) + (0x8704UL))
#define SOC_NPU_AICORE_CUBE_ERROR_T1_0_ADDR(base) ((base) + (0x8710UL))
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_ADDR(base) ((base) + (0x8720UL))
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_1_ADDR(base) ((base) + (0x8724UL))
#define SOC_NPU_AICORE_CUBE_ERR_INFO_T0_0_ADDR(base) ((base) + (0x8730UL))
#define SOC_NPU_AICORE_CUBE_ERR_INFO_T0_1_ADDR(base) ((base) + (0x8734UL))
#define SOC_NPU_AICORE_CUBE_ERR_INFO_T1_0_ADDR(base) ((base) + (0x8740UL))
#define SOC_NPU_AICORE_CUBE_ERR_INFO_T1_1_ADDR(base) ((base) + (0x8744UL))
#define SOC_NPU_AICORE_CUBE_WARN_T0_0_ADDR(base) ((base) + (0x8900UL))
#define SOC_NPU_AICORE_CUBE_WARN_T1_0_ADDR(base) ((base) + (0x8910UL))
#define SOC_NPU_AICORE_CUBE_WARN_MASK_0_ADDR(base) ((base) + (0x8920UL))
#define SOC_NPU_AICORE_CUBE_WARN_INFO_T0_0_ADDR(base) ((base) + (0x8930UL))
#define SOC_NPU_AICORE_CUBE_WARN_INFO_T0_1_ADDR(base) ((base) + (0x8934UL))
#define SOC_NPU_AICORE_CUBE_WARN_INFO_T1_0_ADDR(base) ((base) + (0x8940UL))
#define SOC_NPU_AICORE_CUBE_RESERVED_REG_0_ADDR(base) ((base) + (0x8FE0UL))
#define SOC_NPU_AICORE_CUBE_RESERVED_REG_1_ADDR(base) ((base) + (0x8FE4UL))
#define SOC_NPU_AICORE_CUBE_RESERVED_RO_REG_0_ADDR(base) ((base) + (0x8FF0UL))
#define SOC_NPU_AICORE_CUBE_RESERVED_RO_REG_1_ADDR(base) ((base) + (0x8FF4UL))
#else
#define SOC_NPU_AICORE_GLB_AIC_CLK_GATE_MASK_ADDR(base) ((base) + (0x2000))
#define SOC_NPU_AICORE_GLB_AIC_EXCPT_CLR_ADDR(base) ((base) + (0x2010))
#define SOC_NPU_AICORE_GLB_AIC_SAFETY_REG_PTY_CTL_ADDR(base) ((base) + (0x2020))
#define SOC_NPU_AICORE_GLB_PMU_EN_ADDR(base) ((base) + (0x2400))
#define SOC_NPU_AICORE_GLB_PMU_IDX_ADDR(base,pmu_cnt_n) ((base) + (0x2500+0x4*(pmu_cnt_n)))
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_0_ADDR(base) ((base) + (0x8000))
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_1_ADDR(base) ((base) + (0x8004))
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_2_ADDR(base) ((base) + (0x8008))
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_3_ADDR(base) ((base) + (0x800C))
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_0_ADDR(base) ((base) + (0x8010))
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_1_ADDR(base) ((base) + (0x8014))
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_2_ADDR(base) ((base) + (0x8018))
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_3_ADDR(base) ((base) + (0x801C))
#define SOC_NPU_AICORE_CUBE_VDROP_CTRL_0_ADDR(base) ((base) + (0x8020))
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_4_ADDR(base) ((base) + (0x8024))
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_4_ADDR(base) ((base) + (0x8028))
#define SOC_NPU_AICORE_CUBE_ACTIVE_CTRL_0_ADDR(base) ((base) + (0x8030))
#define SOC_NPU_AICORE_CUBE_STALL_DMY_CTRL_0_ADDR(base) ((base) + (0x8040))
#define SOC_NPU_AICORE_CUBE_STALL_DMY_CTRL_1_ADDR(base) ((base) + (0x8044))
#define SOC_NPU_AICORE_CUBE_ECC_CTRL_0_ADDR(base) ((base) + (0x8050))
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_CTRL_0_ADDR(base) ((base) + (0x8054))
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0A_0_ADDR(base) ((base) + (0x8058))
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0A_WINO_0_ADDR(base) ((base) + (0x805c))
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0B_0_ADDR(base) ((base) + (0x8060))
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0B_WINO_0_ADDR(base) ((base) + (0x8064))
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0C_0_ADDR(base) ((base) + (0x8068))
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0C_1_ADDR(base) ((base) + (0x806c))
#define SOC_NPU_AICORE_CUBE_CTRL_0_ADDR(base) ((base) + (0x8080))
#define SOC_NPU_AICORE_CUBE_ICG_MASK_0_ADDR(base) ((base) + (0x8088))
#define SOC_NPU_AICORE_CUBE_ICG_MASK_1_ADDR(base) ((base) + (0x808c))
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0A_0_ADDR(base) ((base) + (0x8090))
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0A_1_ADDR(base) ((base) + (0x8094))
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0B_0_ADDR(base) ((base) + (0x8098))
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0B_1_ADDR(base) ((base) + (0x809C))
#define SOC_NPU_AICORE_CUBE_PRE_RST_STALL_CTRL_ADDR(base) ((base) + (0x8100))
#define SOC_NPU_AICORE_CUBE_PRE_RST_STATUS_ADDR(base) ((base) + (0x8104))
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_ADDR(base) ((base) + (0x8700))
#define SOC_NPU_AICORE_CUBE_ERROR_T0_1_ADDR(base) ((base) + (0x8704))
#define SOC_NPU_AICORE_CUBE_ERROR_T1_0_ADDR(base) ((base) + (0x8710))
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_ADDR(base) ((base) + (0x8720))
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_1_ADDR(base) ((base) + (0x8724))
#define SOC_NPU_AICORE_CUBE_ERR_INFO_T0_0_ADDR(base) ((base) + (0x8730))
#define SOC_NPU_AICORE_CUBE_ERR_INFO_T0_1_ADDR(base) ((base) + (0x8734))
#define SOC_NPU_AICORE_CUBE_ERR_INFO_T1_0_ADDR(base) ((base) + (0x8740))
#define SOC_NPU_AICORE_CUBE_ERR_INFO_T1_1_ADDR(base) ((base) + (0x8744))
#define SOC_NPU_AICORE_CUBE_WARN_T0_0_ADDR(base) ((base) + (0x8900))
#define SOC_NPU_AICORE_CUBE_WARN_T1_0_ADDR(base) ((base) + (0x8910))
#define SOC_NPU_AICORE_CUBE_WARN_MASK_0_ADDR(base) ((base) + (0x8920))
#define SOC_NPU_AICORE_CUBE_WARN_INFO_T0_0_ADDR(base) ((base) + (0x8930))
#define SOC_NPU_AICORE_CUBE_WARN_INFO_T0_1_ADDR(base) ((base) + (0x8934))
#define SOC_NPU_AICORE_CUBE_WARN_INFO_T1_0_ADDR(base) ((base) + (0x8940))
#define SOC_NPU_AICORE_CUBE_RESERVED_REG_0_ADDR(base) ((base) + (0x8FE0))
#define SOC_NPU_AICORE_CUBE_RESERVED_REG_1_ADDR(base) ((base) + (0x8FE4))
#define SOC_NPU_AICORE_CUBE_RESERVED_RO_REG_0_ADDR(base) ((base) + (0x8FF0))
#define SOC_NPU_AICORE_CUBE_RESERVED_RO_REG_1_ADDR(base) ((base) + (0x8FF4))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_AICORE_AIC_UB_BASE_OFFSET_ADDR(base) ((base) + (0x1210UL))
#define SOC_NPU_AICORE_GLB_AIC_CLK_GATE_MASK_ADDR(base) ((base) + (0x2000UL))
#define SOC_NPU_AICORE_GLB_AIC_EXCPT_CLR_ADDR(base) ((base) + (0x2010UL))
#define SOC_NPU_AICORE_GLB_AIC_SAFETY_REG_PTY_CTL_ADDR(base) ((base) + (0x2020UL))
#define SOC_NPU_AICORE_GLB_PMU_EN_ADDR(base) ((base) + (0x2400UL))
#define SOC_NPU_AICORE_GLB_PMU_IDX_ADDR(base,pmu_cnt_n) ((base) + (0x2500+0x4*(pmu_cnt_n)))
#define SOC_NPU_AICORE_L1_CLK_GATE_MASK_0_ADDR(base) ((base) + (0xA000UL))
#define SOC_NPU_AICORE_L1_EFF_CLK_GATE_MASK_0_ADDR(base) ((base) + (0xA004UL))
#define SOC_NPU_AICORE_L1_EFF_CLK_EXT_EN_ADDR(base) ((base) + (0xA008UL))
#define SOC_NPU_AICORE_L1_ECC_CTRL_0_ADDR(base) ((base) + (0xA020UL))
#define SOC_NPU_AICORE_L1_ECC_INJECT_CTRL_0_ADDR(base) ((base) + (0xA024UL))
#define SOC_NPU_AICORE_L1_PRE_RST_STALL_CTRL_ADDR(base) ((base) + (0xA600UL))
#define SOC_NPU_AICORE_L1_PRE_RST_STATUS_ADDR(base) ((base) + (0xA604UL))
#define SOC_NPU_AICORE_L1_ERROR_T0_0_ADDR(base) ((base) + (0xA700UL))
#define SOC_NPU_AICORE_L1_ERROR_T0_1_ADDR(base) ((base) + (0xA704UL))
#define SOC_NPU_AICORE_L1_ERROR_T1_0_ADDR(base) ((base) + (0xA708UL))
#define SOC_NPU_AICORE_L1_ERROR_T1_1_ADDR(base) ((base) + (0xA70CUL))
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_ADDR(base) ((base) + (0xA710UL))
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_ADDR(base) ((base) + (0xA714UL))
#define SOC_NPU_AICORE_L1_ERR_INFO_T0_0_ADDR(base) ((base) + (0xA718UL))
#define SOC_NPU_AICORE_L1_ERR_INFO_T0_1_ADDR(base) ((base) + (0xA71CUL))
#define SOC_NPU_AICORE_L1_ERR_INFO_T1_0_ADDR(base) ((base) + (0xA720UL))
#define SOC_NPU_AICORE_L1_ERR_INFO_T1_1_ADDR(base) ((base) + (0xA724UL))
#define SOC_NPU_AICORE_L1_WARN_T0_0_ADDR(base) ((base) + (0xA900UL))
#define SOC_NPU_AICORE_L1_WARN_T1_0_ADDR(base) ((base) + (0xA904UL))
#define SOC_NPU_AICORE_L1_WARN_MASK_0_ADDR(base) ((base) + (0xA908UL))
#define SOC_NPU_AICORE_L1_1BIT_ECC_ERR_ADDR_0_ADDR(base) ((base) + (0xA910UL))
#define SOC_NPU_AICORE_L1_FIXP_CTRL_ADDR(base) ((base) + (0xAA00UL))
#define SOC_NPU_AICORE_L1_RESERVED_RO_REG0_ADDR(base) ((base) + (0xAA04UL))
#define SOC_NPU_AICORE_L1_RESERVED_RO_REG1_ADDR(base) ((base) + (0xAA08UL))
#define SOC_NPU_AICORE_L1_RESERVED_RW_REG0_ADDR(base) ((base) + (0xAA0CUL))
#define SOC_NPU_AICORE_L1_RESERVED_RW_REG1_ADDR(base) ((base) + (0xAA10UL))
#else
#define SOC_NPU_AICORE_AIC_UB_BASE_OFFSET_ADDR(base) ((base) + (0x1210))
#define SOC_NPU_AICORE_GLB_AIC_CLK_GATE_MASK_ADDR(base) ((base) + (0x2000))
#define SOC_NPU_AICORE_GLB_AIC_EXCPT_CLR_ADDR(base) ((base) + (0x2010))
#define SOC_NPU_AICORE_GLB_AIC_SAFETY_REG_PTY_CTL_ADDR(base) ((base) + (0x2020))
#define SOC_NPU_AICORE_GLB_PMU_EN_ADDR(base) ((base) + (0x2400))
#define SOC_NPU_AICORE_GLB_PMU_IDX_ADDR(base,pmu_cnt_n) ((base) + (0x2500+0x4*(pmu_cnt_n)))
#define SOC_NPU_AICORE_L1_CLK_GATE_MASK_0_ADDR(base) ((base) + (0xA000))
#define SOC_NPU_AICORE_L1_EFF_CLK_GATE_MASK_0_ADDR(base) ((base) + (0xA004))
#define SOC_NPU_AICORE_L1_EFF_CLK_EXT_EN_ADDR(base) ((base) + (0xA008))
#define SOC_NPU_AICORE_L1_ECC_CTRL_0_ADDR(base) ((base) + (0xA020))
#define SOC_NPU_AICORE_L1_ECC_INJECT_CTRL_0_ADDR(base) ((base) + (0xA024))
#define SOC_NPU_AICORE_L1_PRE_RST_STALL_CTRL_ADDR(base) ((base) + (0xA600))
#define SOC_NPU_AICORE_L1_PRE_RST_STATUS_ADDR(base) ((base) + (0xA604))
#define SOC_NPU_AICORE_L1_ERROR_T0_0_ADDR(base) ((base) + (0xA700))
#define SOC_NPU_AICORE_L1_ERROR_T0_1_ADDR(base) ((base) + (0xA704))
#define SOC_NPU_AICORE_L1_ERROR_T1_0_ADDR(base) ((base) + (0xA708))
#define SOC_NPU_AICORE_L1_ERROR_T1_1_ADDR(base) ((base) + (0xA70C))
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_ADDR(base) ((base) + (0xA710))
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_ADDR(base) ((base) + (0xA714))
#define SOC_NPU_AICORE_L1_ERR_INFO_T0_0_ADDR(base) ((base) + (0xA718))
#define SOC_NPU_AICORE_L1_ERR_INFO_T0_1_ADDR(base) ((base) + (0xA71C))
#define SOC_NPU_AICORE_L1_ERR_INFO_T1_0_ADDR(base) ((base) + (0xA720))
#define SOC_NPU_AICORE_L1_ERR_INFO_T1_1_ADDR(base) ((base) + (0xA724))
#define SOC_NPU_AICORE_L1_WARN_T0_0_ADDR(base) ((base) + (0xA900))
#define SOC_NPU_AICORE_L1_WARN_T1_0_ADDR(base) ((base) + (0xA904))
#define SOC_NPU_AICORE_L1_WARN_MASK_0_ADDR(base) ((base) + (0xA908))
#define SOC_NPU_AICORE_L1_1BIT_ECC_ERR_ADDR_0_ADDR(base) ((base) + (0xA910))
#define SOC_NPU_AICORE_L1_FIXP_CTRL_ADDR(base) ((base) + (0xAA00))
#define SOC_NPU_AICORE_L1_RESERVED_RO_REG0_ADDR(base) ((base) + (0xAA04))
#define SOC_NPU_AICORE_L1_RESERVED_RO_REG1_ADDR(base) ((base) + (0xAA08))
#define SOC_NPU_AICORE_L1_RESERVED_RW_REG0_ADDR(base) ((base) + (0xAA0C))
#define SOC_NPU_AICORE_L1_RESERVED_RW_REG1_ADDR(base) ((base) + (0xAA10))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_AICORE_KIS_SMMU_SUBSTREAMID_ADDR(base) ((base) + (0x00A8UL))
#define SOC_NPU_AICORE_KIS_SMMU_SUBSTREAMID_EN_ADDR(base) ((base) + (0x00ACUL))
#define SOC_NPU_AICORE_KIS_BIF_AXPROT_ADDR(base) ((base) + (0x00B8UL))
#define SOC_NPU_AICORE_KIS_PCIE_AXUSER_CFG_ADDR(base) ((base) + (0x00BCUL))
#define SOC_NPU_AICORE_KIS_FLOW_PARTID_CFG_ADDR(base) ((base) + (0x00C0UL))
#define SOC_NPU_AICORE_KIS_BIF_STA_ARB_WEIGHT_ADDR(base) ((base) + (0x00F4UL))
#define SOC_NPU_AICORE_SEC_BIF_STREAM_NS_ADDR(base) ((base) + (0x1400UL))
#define SOC_NPU_AICORE_SEC_SMMU_SEC_STREAMID_ADDR(base) ((base) + (0x1404UL))
#define SOC_NPU_AICORE_SEC_AIC_ASIL_ADDR(base) ((base) + (0x1408UL))
#define SOC_NPU_AICORE_SEC_BIF_PARTID_CFG_ADDR(base) ((base) + (0x140CUL))
#define SOC_NPU_AICORE_SEC_BIF_PER_MON_AXPORT_ADDR(base) ((base) + (0x1410UL))
#define SOC_NPU_AICORE_GLB_AIC_CLK_GATE_MASK_ADDR(base) ((base) + (0x2000UL))
#define SOC_NPU_AICORE_GLB_AIC_EXCPT_CLR_ADDR(base) ((base) + (0x2010UL))
#define SOC_NPU_AICORE_GLB_AIC_SAFETY_REG_PTY_CTL_ADDR(base) ((base) + (0x2020UL))
#define SOC_NPU_AICORE_GLB_PMU_EN_ADDR(base) ((base) + (0x2400UL))
#define SOC_NPU_AICORE_GLB_L2_VADDR_BASE_L_ADDR(base) ((base) + (0x2410UL))
#define SOC_NPU_AICORE_GLB_L2_VADDR_BASE_H_ADDR(base) ((base) + (0x2414UL))
#define SOC_NPU_AICORE_GLB_PMU_IDX_ADDR(base,pmu_cnt_n) ((base) + (0x2500+0x4*(pmu_cnt_n)))
#define SOC_NPU_AICORE_GLB_ADDR_INTLV_CFG_ADDR(base) ((base) + (0x2808UL))
#define SOC_NPU_AICORE_BIF_BUS_CFG_ADDR(base) ((base) + (0x9000UL))
#define SOC_NPU_AICORE_BIF_SMMU_STREAMID_ADDR(base) ((base) + (0x9004UL))
#define SOC_NPU_AICORE_BIF_DYN_AR_CORE_OST_ADDR(base) ((base) + (0x9008UL))
#define SOC_NPU_AICORE_BIF_DYN_AW_CORE_OST_ADDR(base) ((base) + (0x900CUL))
#define SOC_NPU_AICORE_BIF_STA_MTE_PORT_OST_ADDR(base) ((base) + (0x9010UL))
#define SOC_NPU_AICORE_BIF_SMMU_STREAMID_CFG_ADDR(base) ((base) + (0x9500UL))
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_OST_ADDR(base) ((base) + (0x9014UL))
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_OST_ADDR(base) ((base) + (0x9018UL))
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_LMTR_ADDR(base) ((base) + (0x901CUL))
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_LMTR_ADDR(base) ((base) + (0x9020UL))
#define SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_ADDR(base) ((base) + (0x9024UL))
#define SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_ADDR(base) ((base) + (0x9028UL))
#define SOC_NPU_AICORE_BIF_AXI_CLAMP_CTRL_ADDR(base) ((base) + (0x902CUL))
#define SOC_NPU_AICORE_BIF_BUFF_RESOURCE_CTRL_ADDR(base) ((base) + (0x9030UL))
#define SOC_NPU_AICORE_BIF_HYBRID_ENTRY_CTRL_DIS_ADDR(base) ((base) + (0x9034UL))
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_ADDR(base) ((base) + (0x9038UL))
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_OST_MERGE_ADDR(base) ((base) + (0x9200UL))
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_OST_MERGE_ADDR(base) ((base) + (0x9204UL))
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_LMTR_MERGE_ADDR(base) ((base) + (0x9208UL))
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_LMTR_MERGE_ADDR(base) ((base) + (0x920CUL))
#define SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_MERGE_ADDR(base) ((base) + (0x9210UL))
#define SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_MERGE_ADDR(base) ((base) + (0x9214UL))
#define SOC_NPU_AICORE_BIF_AXI_CLAMP_CTRL_MERGE_ADDR(base) ((base) + (0x9218UL))
#define SOC_NPU_AICORE_BIF_BUFF_RESOURCE_CTRL_MERGE_ADDR(base) ((base) + (0x9220UL))
#define SOC_NPU_AICORE_BIF_HYBRID_ENTRY_CTRL_DIS_MERGE_ADDR(base) ((base) + (0x9224UL))
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_BUSY_MERGE_ADDR(base) ((base) + (0x9228UL))
#define SOC_NPU_AICORE_BIF_OUTSTANDING_STATUS_ADDR(base) ((base) + (0x9300UL))
#define SOC_NPU_AICORE_BIF_CMD_TABLE_STATUS_ADDR(base) ((base) + (0x9304UL))
#define SOC_NPU_AICORE_BIF_BUSY_STATUS_ADDR(base) ((base) + (0x9308UL))
#define SOC_NPU_AICORE_BIF_RESERVED_REG0_ADDR(base) ((base) + (0x9350UL))
#else
#define SOC_NPU_AICORE_KIS_SMMU_SUBSTREAMID_ADDR(base) ((base) + (0x00A8))
#define SOC_NPU_AICORE_KIS_SMMU_SUBSTREAMID_EN_ADDR(base) ((base) + (0x00AC))
#define SOC_NPU_AICORE_KIS_BIF_AXPROT_ADDR(base) ((base) + (0x00B8))
#define SOC_NPU_AICORE_KIS_PCIE_AXUSER_CFG_ADDR(base) ((base) + (0x00BC))
#define SOC_NPU_AICORE_KIS_FLOW_PARTID_CFG_ADDR(base) ((base) + (0x00C0))
#define SOC_NPU_AICORE_KIS_BIF_STA_ARB_WEIGHT_ADDR(base) ((base) + (0x00F4))
#define SOC_NPU_AICORE_SEC_BIF_STREAM_NS_ADDR(base) ((base) + (0x1400))
#define SOC_NPU_AICORE_SEC_SMMU_SEC_STREAMID_ADDR(base) ((base) + (0x1404))
#define SOC_NPU_AICORE_SEC_AIC_ASIL_ADDR(base) ((base) + (0x1408))
#define SOC_NPU_AICORE_SEC_BIF_PARTID_CFG_ADDR(base) ((base) + (0x140C))
#define SOC_NPU_AICORE_SEC_BIF_PER_MON_AXPORT_ADDR(base) ((base) + (0x1410))
#define SOC_NPU_AICORE_GLB_AIC_CLK_GATE_MASK_ADDR(base) ((base) + (0x2000))
#define SOC_NPU_AICORE_GLB_AIC_EXCPT_CLR_ADDR(base) ((base) + (0x2010))
#define SOC_NPU_AICORE_GLB_AIC_SAFETY_REG_PTY_CTL_ADDR(base) ((base) + (0x2020))
#define SOC_NPU_AICORE_GLB_PMU_EN_ADDR(base) ((base) + (0x2400))
#define SOC_NPU_AICORE_GLB_L2_VADDR_BASE_L_ADDR(base) ((base) + (0x2410))
#define SOC_NPU_AICORE_GLB_L2_VADDR_BASE_H_ADDR(base) ((base) + (0x2414))
#define SOC_NPU_AICORE_GLB_PMU_IDX_ADDR(base,pmu_cnt_n) ((base) + (0x2500+0x4*(pmu_cnt_n)))
#define SOC_NPU_AICORE_GLB_ADDR_INTLV_CFG_ADDR(base) ((base) + (0x2808))
#define SOC_NPU_AICORE_BIF_BUS_CFG_ADDR(base) ((base) + (0x9000))
#define SOC_NPU_AICORE_BIF_SMMU_STREAMID_ADDR(base) ((base) + (0x9004))
#define SOC_NPU_AICORE_BIF_DYN_AR_CORE_OST_ADDR(base) ((base) + (0x9008))
#define SOC_NPU_AICORE_BIF_DYN_AW_CORE_OST_ADDR(base) ((base) + (0x900C))
#define SOC_NPU_AICORE_BIF_STA_MTE_PORT_OST_ADDR(base) ((base) + (0x9010))
#define SOC_NPU_AICORE_BIF_SMMU_STREAMID_CFG_ADDR(base) ((base) + (0x9500))
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_OST_ADDR(base) ((base) + (0x9014))
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_OST_ADDR(base) ((base) + (0x9018))
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_LMTR_ADDR(base) ((base) + (0x901C))
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_LMTR_ADDR(base) ((base) + (0x9020))
#define SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_ADDR(base) ((base) + (0x9024))
#define SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_ADDR(base) ((base) + (0x9028))
#define SOC_NPU_AICORE_BIF_AXI_CLAMP_CTRL_ADDR(base) ((base) + (0x902C))
#define SOC_NPU_AICORE_BIF_BUFF_RESOURCE_CTRL_ADDR(base) ((base) + (0x9030))
#define SOC_NPU_AICORE_BIF_HYBRID_ENTRY_CTRL_DIS_ADDR(base) ((base) + (0x9034))
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_ADDR(base) ((base) + (0x9038))
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_OST_MERGE_ADDR(base) ((base) + (0x9200))
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_OST_MERGE_ADDR(base) ((base) + (0x9204))
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_LMTR_MERGE_ADDR(base) ((base) + (0x9208))
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_LMTR_MERGE_ADDR(base) ((base) + (0x920C))
#define SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_MERGE_ADDR(base) ((base) + (0x9210))
#define SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_MERGE_ADDR(base) ((base) + (0x9214))
#define SOC_NPU_AICORE_BIF_AXI_CLAMP_CTRL_MERGE_ADDR(base) ((base) + (0x9218))
#define SOC_NPU_AICORE_BIF_BUFF_RESOURCE_CTRL_MERGE_ADDR(base) ((base) + (0x9220))
#define SOC_NPU_AICORE_BIF_HYBRID_ENTRY_CTRL_DIS_MERGE_ADDR(base) ((base) + (0x9224))
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_BUSY_MERGE_ADDR(base) ((base) + (0x9228))
#define SOC_NPU_AICORE_BIF_OUTSTANDING_STATUS_ADDR(base) ((base) + (0x9300))
#define SOC_NPU_AICORE_BIF_CMD_TABLE_STATUS_ADDR(base) ((base) + (0x9304))
#define SOC_NPU_AICORE_BIF_BUSY_STATUS_ADDR(base) ((base) + (0x9308))
#define SOC_NPU_AICORE_BIF_RESERVED_REG0_ADDR(base) ((base) + (0x9350))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 2;
        unsigned int kis_su_start_pc_l : 30;
    } reg;
} SOC_NPU_AICORE_SU_KIS_START_PC_L_UNION;
#endif
#define SOC_NPU_AICORE_SU_KIS_START_PC_L_kis_su_start_pc_l_START (2)
#define SOC_NPU_AICORE_SU_KIS_START_PC_L_kis_su_start_pc_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_su_start_pc_h : 16;
        unsigned int reserved : 8;
        unsigned int kis_l2_in_main : 8;
    } reg;
} SOC_NPU_AICORE_SU_KIS_START_PC_H_UNION;
#endif
#define SOC_NPU_AICORE_SU_KIS_START_PC_H_kis_su_start_pc_h_START (0)
#define SOC_NPU_AICORE_SU_KIS_START_PC_H_kis_su_start_pc_h_END (15)
#define SOC_NPU_AICORE_SU_KIS_START_PC_H_kis_l2_in_main_START (24)
#define SOC_NPU_AICORE_SU_KIS_START_PC_H_kis_l2_in_main_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_param_base_addr_l : 32;
    } reg;
} SOC_NPU_AICORE_SU_KIS_PARAM_BASE_L_UNION;
#endif
#define SOC_NPU_AICORE_SU_KIS_PARAM_BASE_L_kis_param_base_addr_l_START (0)
#define SOC_NPU_AICORE_SU_KIS_PARAM_BASE_L_kis_param_base_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_param_base_addr_h : 32;
    } reg;
} SOC_NPU_AICORE_SU_KIS_PARAM_BASE_H_UNION;
#endif
#define SOC_NPU_AICORE_SU_KIS_PARAM_BASE_H_kis_param_base_addr_h_START (0)
#define SOC_NPU_AICORE_SU_KIS_PARAM_BASE_H_kis_param_base_addr_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_block_id : 16;
        unsigned int kis_block_dim : 16;
    } reg;
} SOC_NPU_AICORE_SU_KIS_BLOCK_ID_DIM_UNION;
#endif
#define SOC_NPU_AICORE_SU_KIS_BLOCK_ID_DIM_kis_block_id_START (0)
#define SOC_NPU_AICORE_SU_KIS_BLOCK_ID_DIM_kis_block_id_END (15)
#define SOC_NPU_AICORE_SU_KIS_BLOCK_ID_DIM_kis_block_dim_START (16)
#define SOC_NPU_AICORE_SU_KIS_BLOCK_ID_DIM_kis_block_dim_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_thread_id : 16;
        unsigned int kis_thread_dim : 16;
    } reg;
} SOC_NPU_AICORE_SU_KIS_THREAD_ID_DIM_UNION;
#endif
#define SOC_NPU_AICORE_SU_KIS_THREAD_ID_DIM_kis_thread_id_START (0)
#define SOC_NPU_AICORE_SU_KIS_THREAD_ID_DIM_kis_thread_id_END (15)
#define SOC_NPU_AICORE_SU_KIS_THREAD_ID_DIM_kis_thread_dim_START (16)
#define SOC_NPU_AICORE_SU_KIS_THREAD_ID_DIM_kis_thread_dim_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_sub_block_id : 16;
        unsigned int kis_sub_block_dim : 16;
    } reg;
} SOC_NPU_AICORE_SU_KIS_SUBBLOCK_ID_UNION;
#endif
#define SOC_NPU_AICORE_SU_KIS_SUBBLOCK_ID_kis_sub_block_id_START (0)
#define SOC_NPU_AICORE_SU_KIS_SUBBLOCK_ID_kis_sub_block_id_END (15)
#define SOC_NPU_AICORE_SU_KIS_SUBBLOCK_ID_kis_sub_block_dim_START (16)
#define SOC_NPU_AICORE_SU_KIS_SUBBLOCK_ID_kis_sub_block_dim_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_data_size : 32;
    } reg;
} SOC_NPU_AICORE_SU_KIS_DATA_SIZE_UNION;
#endif
#define SOC_NPU_AICORE_SU_KIS_DATA_SIZE_kis_data_size_START (0)
#define SOC_NPU_AICORE_SU_KIS_DATA_SIZE_kis_data_size_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_stack_phy_base_l : 32;
    } reg;
} SOC_NPU_AICORE_SU_KIS_STACK_PHY_BASE_L_UNION;
#endif
#define SOC_NPU_AICORE_SU_KIS_STACK_PHY_BASE_L_kis_stack_phy_base_l_START (0)
#define SOC_NPU_AICORE_SU_KIS_STACK_PHY_BASE_L_kis_stack_phy_base_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_stack_phy_base_h : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_NPU_AICORE_SU_KIS_STACK_PHY_BASE_H_UNION;
#endif
#define SOC_NPU_AICORE_SU_KIS_STACK_PHY_BASE_H_kis_stack_phy_base_h_START (0)
#define SOC_NPU_AICORE_SU_KIS_STACK_PHY_BASE_H_kis_stack_phy_base_h_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_smmu_substreamid : 16;
        unsigned int kis_two_level_smmu_streamid : 16;
    } reg;
} SOC_NPU_AICORE_KIS_SMMU_SUBSTREAMID_UNION;
#endif
#define SOC_NPU_AICORE_KIS_SMMU_SUBSTREAMID_kis_smmu_substreamid_START (0)
#define SOC_NPU_AICORE_KIS_SMMU_SUBSTREAMID_kis_smmu_substreamid_END (15)
#define SOC_NPU_AICORE_KIS_SMMU_SUBSTREAMID_kis_two_level_smmu_streamid_START (16)
#define SOC_NPU_AICORE_KIS_SMMU_SUBSTREAMID_kis_two_level_smmu_streamid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_two_level_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_KIS_SMMU_SUBSTREAMID_EN_UNION;
#endif
#define SOC_NPU_AICORE_KIS_SMMU_SUBSTREAMID_EN_kis_two_level_en_START (0)
#define SOC_NPU_AICORE_KIS_SMMU_SUBSTREAMID_EN_kis_two_level_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_ifu_preload_cnt : 5;
        unsigned int reserved : 26;
        unsigned int kis_sat_mode : 1;
    } reg;
} SOC_NPU_AICORE_KIS_SU_PRELOAD_SAT_MODE_UNION;
#endif
#define SOC_NPU_AICORE_KIS_SU_PRELOAD_SAT_MODE_kis_ifu_preload_cnt_START (0)
#define SOC_NPU_AICORE_KIS_SU_PRELOAD_SAT_MODE_kis_ifu_preload_cnt_END (4)
#define SOC_NPU_AICORE_KIS_SU_PRELOAD_SAT_MODE_kis_sat_mode_START (31)
#define SOC_NPU_AICORE_KIS_SU_PRELOAD_SAT_MODE_kis_sat_mode_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_pmu_fifo_push_en : 1;
        unsigned int kis_task_restore : 1;
        unsigned int kis_mix_mode_task_en : 1;
        unsigned int reserved : 26;
        unsigned int kis_disable_ram_clear : 1;
        unsigned int kis_cache_inv_before_startup : 1;
        unsigned int kis_pipe_rst_before_startup : 1;
    } reg;
} SOC_NPU_AICORE_KIS_TASK_CFG_UNION;
#endif
#define SOC_NPU_AICORE_KIS_TASK_CFG_kis_pmu_fifo_push_en_START (0)
#define SOC_NPU_AICORE_KIS_TASK_CFG_kis_pmu_fifo_push_en_END (0)
#define SOC_NPU_AICORE_KIS_TASK_CFG_kis_task_restore_START (1)
#define SOC_NPU_AICORE_KIS_TASK_CFG_kis_task_restore_END (1)
#define SOC_NPU_AICORE_KIS_TASK_CFG_kis_mix_mode_task_en_START (2)
#define SOC_NPU_AICORE_KIS_TASK_CFG_kis_mix_mode_task_en_END (2)
#define SOC_NPU_AICORE_KIS_TASK_CFG_kis_disable_ram_clear_START (29)
#define SOC_NPU_AICORE_KIS_TASK_CFG_kis_disable_ram_clear_END (29)
#define SOC_NPU_AICORE_KIS_TASK_CFG_kis_cache_inv_before_startup_START (30)
#define SOC_NPU_AICORE_KIS_TASK_CFG_kis_cache_inv_before_startup_END (30)
#define SOC_NPU_AICORE_KIS_TASK_CFG_kis_pipe_rst_before_startup_START (31)
#define SOC_NPU_AICORE_KIS_TASK_CFG_kis_pipe_rst_before_startup_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_bif_privilege : 1;
        unsigned int kis_bif_non_secure : 1;
        unsigned int kis_bif_instr : 1;
        unsigned int kis_lite_tiny : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_NPU_AICORE_KIS_BIF_AXPROT_UNION;
#endif
#define SOC_NPU_AICORE_KIS_BIF_AXPROT_kis_bif_privilege_START (0)
#define SOC_NPU_AICORE_KIS_BIF_AXPROT_kis_bif_privilege_END (0)
#define SOC_NPU_AICORE_KIS_BIF_AXPROT_kis_bif_non_secure_START (1)
#define SOC_NPU_AICORE_KIS_BIF_AXPROT_kis_bif_non_secure_END (1)
#define SOC_NPU_AICORE_KIS_BIF_AXPROT_kis_bif_instr_START (2)
#define SOC_NPU_AICORE_KIS_BIF_AXPROT_kis_bif_instr_END (2)
#define SOC_NPU_AICORE_KIS_BIF_AXPROT_kis_lite_tiny_START (3)
#define SOC_NPU_AICORE_KIS_BIF_AXPROT_kis_lite_tiny_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_pcie_axuser : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_AICORE_KIS_PCIE_AXUSER_CFG_UNION;
#endif
#define SOC_NPU_AICORE_KIS_PCIE_AXUSER_CFG_kis_pcie_axuser_START (0)
#define SOC_NPU_AICORE_KIS_PCIE_AXUSER_CFG_kis_pcie_axuser_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_partid_for_data : 8;
        unsigned int kis_partid_for_inst : 8;
        unsigned int kis_cfg_ax_qos : 4;
        unsigned int kis_e2e_flow_ctrl_pmg : 2;
        unsigned int kis_e2e_flow_ctrl_ns : 1;
        unsigned int kis_stl_mode : 1;
        unsigned int kis_stl_mode_ssv : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_NPU_AICORE_KIS_FLOW_PARTID_CFG_UNION;
#endif
#define SOC_NPU_AICORE_KIS_FLOW_PARTID_CFG_kis_partid_for_data_START (0)
#define SOC_NPU_AICORE_KIS_FLOW_PARTID_CFG_kis_partid_for_data_END (7)
#define SOC_NPU_AICORE_KIS_FLOW_PARTID_CFG_kis_partid_for_inst_START (8)
#define SOC_NPU_AICORE_KIS_FLOW_PARTID_CFG_kis_partid_for_inst_END (15)
#define SOC_NPU_AICORE_KIS_FLOW_PARTID_CFG_kis_cfg_ax_qos_START (16)
#define SOC_NPU_AICORE_KIS_FLOW_PARTID_CFG_kis_cfg_ax_qos_END (19)
#define SOC_NPU_AICORE_KIS_FLOW_PARTID_CFG_kis_e2e_flow_ctrl_pmg_START (20)
#define SOC_NPU_AICORE_KIS_FLOW_PARTID_CFG_kis_e2e_flow_ctrl_pmg_END (21)
#define SOC_NPU_AICORE_KIS_FLOW_PARTID_CFG_kis_e2e_flow_ctrl_ns_START (22)
#define SOC_NPU_AICORE_KIS_FLOW_PARTID_CFG_kis_e2e_flow_ctrl_ns_END (22)
#define SOC_NPU_AICORE_KIS_FLOW_PARTID_CFG_kis_stl_mode_START (23)
#define SOC_NPU_AICORE_KIS_FLOW_PARTID_CFG_kis_stl_mode_END (23)
#define SOC_NPU_AICORE_KIS_FLOW_PARTID_CFG_kis_stl_mode_ssv_START (24)
#define SOC_NPU_AICORE_KIS_FLOW_PARTID_CFG_kis_stl_mode_ssv_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 2;
        unsigned int reserved_1: 2;
        unsigned int reserved_2: 28;
    } reg;
} SOC_NPU_AICORE_KIS_MTE_RATIO_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_group_id : 16;
        unsigned int kis_group_dim : 16;
    } reg;
} SOC_NPU_AICORE_KIS_SU_GROUP_DIM_ID_CFG_UNION;
#endif
#define SOC_NPU_AICORE_KIS_SU_GROUP_DIM_ID_CFG_kis_group_id_START (0)
#define SOC_NPU_AICORE_KIS_SU_GROUP_DIM_ID_CFG_kis_group_id_END (15)
#define SOC_NPU_AICORE_KIS_SU_GROUP_DIM_ID_CFG_kis_group_dim_START (16)
#define SOC_NPU_AICORE_KIS_SU_GROUP_DIM_ID_CFG_kis_group_dim_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_group_block_id : 16;
        unsigned int kis_group_block_dim : 16;
    } reg;
} SOC_NPU_AICORE_KIS_SU_GROUP_BLK_DIM_ID_CFG_UNION;
#endif
#define SOC_NPU_AICORE_KIS_SU_GROUP_BLK_DIM_ID_CFG_kis_group_block_id_START (0)
#define SOC_NPU_AICORE_KIS_SU_GROUP_BLK_DIM_ID_CFG_kis_group_block_id_END (15)
#define SOC_NPU_AICORE_KIS_SU_GROUP_BLK_DIM_ID_CFG_kis_group_block_dim_START (16)
#define SOC_NPU_AICORE_KIS_SU_GROUP_BLK_DIM_ID_CFG_kis_group_block_dim_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_data_main_base_l : 32;
    } reg;
} SOC_NPU_AICORE_KIS_SU_DATA_MAIN_BASE_L_UNION;
#endif
#define SOC_NPU_AICORE_KIS_SU_DATA_MAIN_BASE_L_kis_data_main_base_l_START (0)
#define SOC_NPU_AICORE_KIS_SU_DATA_MAIN_BASE_L_kis_data_main_base_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_data_main_base_h : 32;
    } reg;
} SOC_NPU_AICORE_KIS_SU_DATA_MAIN_BASE_H_UNION;
#endif
#define SOC_NPU_AICORE_KIS_SU_DATA_MAIN_BASE_H_kis_data_main_base_h_START (0)
#define SOC_NPU_AICORE_KIS_SU_DATA_MAIN_BASE_H_kis_data_main_base_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_data_ub_base_l : 32;
    } reg;
} SOC_NPU_AICORE_KIS_SU_DATA_UB_BASE_L_UNION;
#endif
#define SOC_NPU_AICORE_KIS_SU_DATA_UB_BASE_L_kis_data_ub_base_l_START (0)
#define SOC_NPU_AICORE_KIS_SU_DATA_UB_BASE_L_kis_data_ub_base_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_data_ub_base_h : 32;
    } reg;
} SOC_NPU_AICORE_KIS_SU_DATA_UB_BASE_H_UNION;
#endif
#define SOC_NPU_AICORE_KIS_SU_DATA_UB_BASE_H_kis_data_ub_base_h_START (0)
#define SOC_NPU_AICORE_KIS_SU_DATA_UB_BASE_H_kis_data_ub_base_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_simt_stk_base_l : 32;
    } reg;
} SOC_NPU_AICORE_KIS_SIMT_STK_BASE_L_UNION;
#endif
#define SOC_NPU_AICORE_KIS_SIMT_STK_BASE_L_kis_simt_stk_base_l_START (0)
#define SOC_NPU_AICORE_KIS_SIMT_STK_BASE_L_kis_simt_stk_base_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_simt_stk_base_h : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_AICORE_KIS_SIMT_STK_BASE_H_UNION;
#endif
#define SOC_NPU_AICORE_KIS_SIMT_STK_BASE_H_kis_simt_stk_base_h_START (0)
#define SOC_NPU_AICORE_KIS_SIMT_STK_BASE_H_kis_simt_stk_base_h_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_simt_warp_stk_size : 32;
    } reg;
} SOC_NPU_AICORE_KIS_SIMT_WARP_STK_SIZE_UNION;
#endif
#define SOC_NPU_AICORE_KIS_SIMT_WARP_STK_SIZE_kis_simt_warp_stk_size_START (0)
#define SOC_NPU_AICORE_KIS_SIMT_WARP_STK_SIZE_kis_simt_warp_stk_size_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_ub_size : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPU_AICORE_KIS_SIMT_UB_SIZE_UNION;
#endif
#define SOC_NPU_AICORE_KIS_SIMT_UB_SIZE_kis_ub_size_START (0)
#define SOC_NPU_AICORE_KIS_SIMT_UB_SIZE_kis_ub_size_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_simt_dvg_warp_stk_size : 32;
    } reg;
} SOC_NPU_AICORE_KIS_SIMT_DVG_WARP_STACK_SIZE_UNION;
#endif
#define SOC_NPU_AICORE_KIS_SIMT_DVG_WARP_STACK_SIZE_kis_simt_dvg_warp_stk_size_START (0)
#define SOC_NPU_AICORE_KIS_SIMT_DVG_WARP_STACK_SIZE_kis_simt_dvg_warp_stk_size_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_core_aw_arb_weight : 3;
        unsigned int sta_core_ar_arb_weight : 3;
        unsigned int reserved : 26;
    } reg;
} SOC_NPU_AICORE_KIS_BIF_STA_ARB_WEIGHT_UNION;
#endif
#define SOC_NPU_AICORE_KIS_BIF_STA_ARB_WEIGHT_sta_core_aw_arb_weight_START (0)
#define SOC_NPU_AICORE_KIS_BIF_STA_ARB_WEIGHT_sta_core_aw_arb_weight_END (2)
#define SOC_NPU_AICORE_KIS_BIF_STA_ARB_WEIGHT_sta_core_ar_arb_weight_START (3)
#define SOC_NPU_AICORE_KIS_BIF_STA_ARB_WEIGHT_sta_core_ar_arb_weight_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_KIS_CFG_RSV_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_sec_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_SEC_AIC_SEC_EN_UNION;
#endif
#define SOC_NPU_AICORE_SEC_AIC_SEC_EN_aic_sec_en_START (0)
#define SOC_NPU_AICORE_SEC_AIC_SEC_EN_aic_sec_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_err_resp_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_SEC_AIC_ERR_RESP_EN_UNION;
#endif
#define SOC_NPU_AICORE_SEC_AIC_ERR_RESP_EN_aic_err_resp_en_START (0)
#define SOC_NPU_AICORE_SEC_AIC_ERR_RESP_EN_aic_err_resp_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kist_ram_clear_allow_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_SEC_AIC_RAM_ALWAYS_NOT_CLEAR_UNION;
#endif
#define SOC_NPU_AICORE_SEC_AIC_RAM_ALWAYS_NOT_CLEAR_kist_ram_clear_allow_en_START (0)
#define SOC_NPU_AICORE_SEC_AIC_RAM_ALWAYS_NOT_CLEAR_kist_ram_clear_allow_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_page_regs_sec_en : 1;
        unsigned int sec_page_regs_sec_en : 1;
        unsigned int nsec_rd_sec_regs_dis : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_NPU_AICORE_SC_REGS_SEC_ACCESS_EN_UNION;
#endif
#define SOC_NPU_AICORE_SC_REGS_SEC_ACCESS_EN_kis_page_regs_sec_en_START (0)
#define SOC_NPU_AICORE_SC_REGS_SEC_ACCESS_EN_kis_page_regs_sec_en_END (0)
#define SOC_NPU_AICORE_SC_REGS_SEC_ACCESS_EN_sec_page_regs_sec_en_START (1)
#define SOC_NPU_AICORE_SC_REGS_SEC_ACCESS_EN_sec_page_regs_sec_en_END (1)
#define SOC_NPU_AICORE_SC_REGS_SEC_ACCESS_EN_nsec_rd_sec_regs_dis_START (2)
#define SOC_NPU_AICORE_SC_REGS_SEC_ACCESS_EN_nsec_rd_sec_regs_dis_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sys_va_base_l : 32;
    } reg;
} SOC_NPU_AICORE_SEC_SYS_VA_BASE_L_UNION;
#endif
#define SOC_NPU_AICORE_SEC_SYS_VA_BASE_L_sys_va_base_l_START (0)
#define SOC_NPU_AICORE_SEC_SYS_VA_BASE_L_sys_va_base_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sys_va_base_h : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_NPU_AICORE_SEC_SYS_VA_BASE_H_UNION;
#endif
#define SOC_NPU_AICORE_SEC_SYS_VA_BASE_H_sys_va_base_h_START (0)
#define SOC_NPU_AICORE_SEC_SYS_VA_BASE_H_sys_va_base_h_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ub_base_offset : 22;
        unsigned int reserved : 10;
    } reg;
} SOC_NPU_AICORE_AIC_UB_BASE_OFFSET_UNION;
#endif
#define SOC_NPU_AICORE_AIC_UB_BASE_OFFSET_ub_base_offset_START (0)
#define SOC_NPU_AICORE_AIC_UB_BASE_OFFSET_ub_base_offset_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bif_stream_ns : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_SEC_BIF_STREAM_NS_UNION;
#endif
#define SOC_NPU_AICORE_SEC_BIF_STREAM_NS_bif_stream_ns_START (0)
#define SOC_NPU_AICORE_SEC_BIF_STREAM_NS_bif_stream_ns_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int smmu_sec_strmid_unbp : 16;
        unsigned int smmu_sec_strmid_bp : 16;
    } reg;
} SOC_NPU_AICORE_SEC_SMMU_SEC_STREAMID_UNION;
#endif
#define SOC_NPU_AICORE_SEC_SMMU_SEC_STREAMID_smmu_sec_strmid_unbp_START (0)
#define SOC_NPU_AICORE_SEC_SMMU_SEC_STREAMID_smmu_sec_strmid_unbp_END (15)
#define SOC_NPU_AICORE_SEC_SMMU_SEC_STREAMID_smmu_sec_strmid_bp_START (16)
#define SOC_NPU_AICORE_SEC_SMMU_SEC_STREAMID_smmu_sec_strmid_bp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_bif_asil : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_NPU_AICORE_SEC_AIC_ASIL_UNION;
#endif
#define SOC_NPU_AICORE_SEC_AIC_ASIL_sc_bif_asil_START (0)
#define SOC_NPU_AICORE_SEC_AIC_ASIL_sc_bif_asil_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bif_partid_for_data : 8;
        unsigned int bif_partid_for_inst : 8;
        unsigned int reserved : 15;
        unsigned int bif_partid_qos_enable : 1;
    } reg;
} SOC_NPU_AICORE_SEC_BIF_PARTID_CFG_UNION;
#endif
#define SOC_NPU_AICORE_SEC_BIF_PARTID_CFG_bif_partid_for_data_START (0)
#define SOC_NPU_AICORE_SEC_BIF_PARTID_CFG_bif_partid_for_data_END (7)
#define SOC_NPU_AICORE_SEC_BIF_PARTID_CFG_bif_partid_for_inst_START (8)
#define SOC_NPU_AICORE_SEC_BIF_PARTID_CFG_bif_partid_for_inst_END (15)
#define SOC_NPU_AICORE_SEC_BIF_PARTID_CFG_bif_partid_qos_enable_START (31)
#define SOC_NPU_AICORE_SEC_BIF_PARTID_CFG_bif_partid_qos_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bif_axprot_perf : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_NPU_AICORE_SEC_BIF_PER_MON_AXPORT_UNION;
#endif
#define SOC_NPU_AICORE_SEC_BIF_PER_MON_AXPORT_bif_axprot_perf_START (0)
#define SOC_NPU_AICORE_SEC_BIF_PER_MON_AXPORT_bif_axprot_perf_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_pcie_type_burst_len : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_AICORE_SEC_MTE_PCIE_TYPE_BST_LN_UNION;
#endif
#define SOC_NPU_AICORE_SEC_MTE_PCIE_TYPE_BST_LN_mte_pcie_type_burst_len_START (0)
#define SOC_NPU_AICORE_SEC_MTE_PCIE_TYPE_BST_LN_mte_pcie_type_burst_len_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_pcie_win_size : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_NPU_AICORE_SEC_MTE_PCIE_WIN_SZ_UNION;
#endif
#define SOC_NPU_AICORE_SEC_MTE_PCIE_WIN_SZ_mte_pcie_win_size_START (0)
#define SOC_NPU_AICORE_SEC_MTE_PCIE_WIN_SZ_mte_pcie_win_size_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_pcie_win_base : 18;
        unsigned int reserved : 14;
    } reg;
} SOC_NPU_AICORE_SEC_MTE_PCIE_WIN_BS_UNION;
#endif
#define SOC_NPU_AICORE_SEC_MTE_PCIE_WIN_BS_mte_pcie_win_base_START (0)
#define SOC_NPU_AICORE_SEC_MTE_PCIE_WIN_BS_mte_pcie_win_base_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_pcie_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_SEC_MTE_PCIE_ENABLE_UNION;
#endif
#define SOC_NPU_AICORE_SEC_MTE_PCIE_ENABLE_mte_pcie_en_START (0)
#define SOC_NPU_AICORE_SEC_MTE_PCIE_ENABLE_mte_pcie_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_all_clk_en_mask : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_GLB_AIC_CLK_GATE_MASK_UNION;
#endif
#define SOC_NPU_AICORE_GLB_AIC_CLK_GATE_MASK_aic_all_clk_en_mask_START (0)
#define SOC_NPU_AICORE_GLB_AIC_CLK_GATE_MASK_aic_all_clk_en_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_exit_excpt_clr_p : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_GLB_AIC_EXCPT_CLR_UNION;
#endif
#define SOC_NPU_AICORE_GLB_AIC_EXCPT_CLR_aic_exit_excpt_clr_p_START (0)
#define SOC_NPU_AICORE_GLB_AIC_EXCPT_CLR_aic_exit_excpt_clr_p_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_parity_stop : 1;
        unsigned int aic_parity_mask : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_AICORE_GLB_AIC_SAFETY_REG_PTY_CTL_UNION;
#endif
#define SOC_NPU_AICORE_GLB_AIC_SAFETY_REG_PTY_CTL_aic_parity_stop_START (0)
#define SOC_NPU_AICORE_GLB_AIC_SAFETY_REG_PTY_CTL_aic_parity_stop_END (0)
#define SOC_NPU_AICORE_GLB_AIC_SAFETY_REG_PTY_CTL_aic_parity_mask_START (1)
#define SOC_NPU_AICORE_GLB_AIC_SAFETY_REG_PTY_CTL_aic_parity_mask_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 2;
        unsigned int switch_buffer_0 : 30;
    } reg;
} SOC_NPU_AICORE_GLB_CONTEXT_SWITCH_CTRL_0_UNION;
#endif
#define SOC_NPU_AICORE_GLB_CONTEXT_SWITCH_CTRL_0_switch_buffer_0_START (2)
#define SOC_NPU_AICORE_GLB_CONTEXT_SWITCH_CTRL_0_switch_buffer_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int switch_buffer_1 : 16;
        unsigned int reserved : 15;
        unsigned int context_switch_en : 1;
    } reg;
} SOC_NPU_AICORE_GLB_CONTEXT_SWITCH_CTRL_1_UNION;
#endif
#define SOC_NPU_AICORE_GLB_CONTEXT_SWITCH_CTRL_1_switch_buffer_1_START (0)
#define SOC_NPU_AICORE_GLB_CONTEXT_SWITCH_CTRL_1_switch_buffer_1_END (15)
#define SOC_NPU_AICORE_GLB_CONTEXT_SWITCH_CTRL_1_context_switch_en_START (31)
#define SOC_NPU_AICORE_GLB_CONTEXT_SWITCH_CTRL_1_context_switch_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_GLB_PMU_EN_UNION;
#endif
#define SOC_NPU_AICORE_GLB_PMU_EN_pmu_en_START (0)
#define SOC_NPU_AICORE_GLB_PMU_EN_pmu_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_vaddr_base_l : 32;
    } reg;
} SOC_NPU_AICORE_GLB_L2_VADDR_BASE_L_UNION;
#endif
#define SOC_NPU_AICORE_GLB_L2_VADDR_BASE_L_l2_vaddr_base_l_START (0)
#define SOC_NPU_AICORE_GLB_L2_VADDR_BASE_L_l2_vaddr_base_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_vaddr_base_h : 32;
    } reg;
} SOC_NPU_AICORE_GLB_L2_VADDR_BASE_H_UNION;
#endif
#define SOC_NPU_AICORE_GLB_L2_VADDR_BASE_H_l2_vaddr_base_h_START (0)
#define SOC_NPU_AICORE_GLB_L2_VADDR_BASE_H_l2_vaddr_base_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_idx : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_AICORE_GLB_PMU_IDX_UNION;
#endif
#define SOC_NPU_AICORE_GLB_PMU_IDX_pmu_idx_START (0)
#define SOC_NPU_AICORE_GLB_PMU_IDX_pmu_idx_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int addr_intlv_cfg : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_AICORE_GLB_ADDR_INTLV_CFG_UNION;
#endif
#define SOC_NPU_AICORE_GLB_ADDR_INTLV_CFG_addr_intlv_cfg_START (0)
#define SOC_NPU_AICORE_GLB_ADDR_INTLV_CFG_addr_intlv_cfg_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int psq_stop : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_SC_RUN_STALL_UNION;
#endif
#define SOC_NPU_AICORE_SC_RUN_STALL_psq_stop_START (0)
#define SOC_NPU_AICORE_SC_RUN_STALL_psq_stop_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_task_sch_host_cpu_mode : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_SC_TASK_SCHEDULE_MODE_UNION;
#endif
#define SOC_NPU_AICORE_SC_TASK_SCHEDULE_MODE_aic_task_sch_host_cpu_mode_START (0)
#define SOC_NPU_AICORE_SC_TASK_SCHEDULE_MODE_aic_task_sch_host_cpu_mode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_init_done : 1;
        unsigned int mte_init_done : 1;
        unsigned int cube_init_done : 1;
        unsigned int su_init_done : 1;
        unsigned int l1_init_done : 1;
        unsigned int reserved : 26;
        unsigned int mem_init_req_w1_p : 1;
    } reg;
} SOC_NPU_AICORE_SC_MEM_INIT_CFG_AND_STA_UNION;
#endif
#define SOC_NPU_AICORE_SC_MEM_INIT_CFG_AND_STA_vec_init_done_START (0)
#define SOC_NPU_AICORE_SC_MEM_INIT_CFG_AND_STA_vec_init_done_END (0)
#define SOC_NPU_AICORE_SC_MEM_INIT_CFG_AND_STA_mte_init_done_START (1)
#define SOC_NPU_AICORE_SC_MEM_INIT_CFG_AND_STA_mte_init_done_END (1)
#define SOC_NPU_AICORE_SC_MEM_INIT_CFG_AND_STA_cube_init_done_START (2)
#define SOC_NPU_AICORE_SC_MEM_INIT_CFG_AND_STA_cube_init_done_END (2)
#define SOC_NPU_AICORE_SC_MEM_INIT_CFG_AND_STA_su_init_done_START (3)
#define SOC_NPU_AICORE_SC_MEM_INIT_CFG_AND_STA_su_init_done_END (3)
#define SOC_NPU_AICORE_SC_MEM_INIT_CFG_AND_STA_l1_init_done_START (4)
#define SOC_NPU_AICORE_SC_MEM_INIT_CFG_AND_STA_l1_init_done_END (4)
#define SOC_NPU_AICORE_SC_MEM_INIT_CFG_AND_STA_mem_init_req_w1_p_START (31)
#define SOC_NPU_AICORE_SC_MEM_INIT_CFG_AND_STA_mem_init_req_w1_p_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kist_cfg_en : 1;
        unsigned int kist_icache_inv_en : 1;
        unsigned int kist_pipe_rst_en : 1;
        unsigned int kist_dcache_inv_en : 1;
        unsigned int kist_ram_always_clear : 1;
        unsigned int kist_warn_clr_en : 1;
        unsigned int kist_event_flag_clr_en : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_NPU_AICORE_SC_START_GLB_CTRL_UNION;
#endif
#define SOC_NPU_AICORE_SC_START_GLB_CTRL_kist_cfg_en_START (0)
#define SOC_NPU_AICORE_SC_START_GLB_CTRL_kist_cfg_en_END (0)
#define SOC_NPU_AICORE_SC_START_GLB_CTRL_kist_icache_inv_en_START (1)
#define SOC_NPU_AICORE_SC_START_GLB_CTRL_kist_icache_inv_en_END (1)
#define SOC_NPU_AICORE_SC_START_GLB_CTRL_kist_pipe_rst_en_START (2)
#define SOC_NPU_AICORE_SC_START_GLB_CTRL_kist_pipe_rst_en_END (2)
#define SOC_NPU_AICORE_SC_START_GLB_CTRL_kist_dcache_inv_en_START (3)
#define SOC_NPU_AICORE_SC_START_GLB_CTRL_kist_dcache_inv_en_END (3)
#define SOC_NPU_AICORE_SC_START_GLB_CTRL_kist_ram_always_clear_START (4)
#define SOC_NPU_AICORE_SC_START_GLB_CTRL_kist_ram_always_clear_END (4)
#define SOC_NPU_AICORE_SC_START_GLB_CTRL_kist_warn_clr_en_START (5)
#define SOC_NPU_AICORE_SC_START_GLB_CTRL_kist_warn_clr_en_END (5)
#define SOC_NPU_AICORE_SC_START_GLB_CTRL_kist_event_flag_clr_en_START (6)
#define SOC_NPU_AICORE_SC_START_GLB_CTRL_kist_event_flag_clr_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int task_done_int : 1;
        unsigned int task_dbg_int : 1;
        unsigned int task_excpt_int : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_NPU_AICORE_SC_AIC_CORE_INT_UNION;
#endif
#define SOC_NPU_AICORE_SC_AIC_CORE_INT_task_done_int_START (0)
#define SOC_NPU_AICORE_SC_AIC_CORE_INT_task_done_int_END (0)
#define SOC_NPU_AICORE_SC_AIC_CORE_INT_task_dbg_int_START (1)
#define SOC_NPU_AICORE_SC_AIC_CORE_INT_task_dbg_int_END (1)
#define SOC_NPU_AICORE_SC_AIC_CORE_INT_task_excpt_int_START (2)
#define SOC_NPU_AICORE_SC_AIC_CORE_INT_task_excpt_int_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int task_done_int_mask : 1;
        unsigned int task_dbg_int_mask : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 29;
    } reg;
} SOC_NPU_AICORE_SC_AIC_CORE_INT_MASK_UNION;
#endif
#define SOC_NPU_AICORE_SC_AIC_CORE_INT_MASK_task_done_int_mask_START (0)
#define SOC_NPU_AICORE_SC_AIC_CORE_INT_MASK_task_done_int_mask_END (0)
#define SOC_NPU_AICORE_SC_AIC_CORE_INT_MASK_task_dbg_int_mask_START (1)
#define SOC_NPU_AICORE_SC_AIC_CORE_INT_MASK_task_dbg_int_mask_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_first_err_id : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_SC_AIC_FIRST_ERR_ID_UNION;
#endif
#define SOC_NPU_AICORE_SC_AIC_FIRST_ERR_ID_aic_first_err_id_START (0)
#define SOC_NPU_AICORE_SC_AIC_FIRST_ERR_ID_aic_first_err_id_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_cur_run_id : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_SC_AIC_CURRENT_RUN_ID_UNION;
#endif
#define SOC_NPU_AICORE_SC_AIC_CURRENT_RUN_ID_aic_cur_run_id_START (0)
#define SOC_NPU_AICORE_SC_AIC_CURRENT_RUN_ID_aic_cur_run_id_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rst_cnt : 8;
        unsigned int rst_done_cnt : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_AICORE_SC_RST_CNT_CFG_UNION;
#endif
#define SOC_NPU_AICORE_SC_RST_CNT_CFG_rst_cnt_START (0)
#define SOC_NPU_AICORE_SC_RST_CNT_CFG_rst_cnt_END (7)
#define SOC_NPU_AICORE_SC_RST_CNT_CFG_rst_done_cnt_START (8)
#define SOC_NPU_AICORE_SC_RST_CNT_CFG_rst_done_cnt_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rst_all : 1;
        unsigned int rst_done : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_AICORE_SC_SOFT_RST_CFG_AND_STA_UNION;
#endif
#define SOC_NPU_AICORE_SC_SOFT_RST_CFG_AND_STA_rst_all_START (0)
#define SOC_NPU_AICORE_SC_SOFT_RST_CFG_AND_STA_rst_all_END (0)
#define SOC_NPU_AICORE_SC_SOFT_RST_CFG_AND_STA_rst_done_START (1)
#define SOC_NPU_AICORE_SC_SOFT_RST_CFG_AND_STA_rst_done_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_ic_inv_one : 1;
        unsigned int su_ic_inv_all : 1;
        unsigned int aic_all_cache_inv_req : 1;
        unsigned int reserved : 28;
        unsigned int su_ic_preload_req : 1;
    } reg;
} SOC_NPU_AICORE_SC_CACHE_PRELOAD_INV_CFG_UNION;
#endif
#define SOC_NPU_AICORE_SC_CACHE_PRELOAD_INV_CFG_su_ic_inv_one_START (0)
#define SOC_NPU_AICORE_SC_CACHE_PRELOAD_INV_CFG_su_ic_inv_one_END (0)
#define SOC_NPU_AICORE_SC_CACHE_PRELOAD_INV_CFG_su_ic_inv_all_START (1)
#define SOC_NPU_AICORE_SC_CACHE_PRELOAD_INV_CFG_su_ic_inv_all_END (1)
#define SOC_NPU_AICORE_SC_CACHE_PRELOAD_INV_CFG_aic_all_cache_inv_req_START (2)
#define SOC_NPU_AICORE_SC_CACHE_PRELOAD_INV_CFG_aic_all_cache_inv_req_END (2)
#define SOC_NPU_AICORE_SC_CACHE_PRELOAD_INV_CFG_su_ic_preload_req_START (31)
#define SOC_NPU_AICORE_SC_CACHE_PRELOAD_INV_CFG_su_ic_preload_req_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_ic_inv_done : 1;
        unsigned int vec_ic_inv_done : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_AICORE_SC_SU_IC_INV_STATUS_UNION;
#endif
#define SOC_NPU_AICORE_SC_SU_IC_INV_STATUS_su_ic_inv_done_START (0)
#define SOC_NPU_AICORE_SC_SU_IC_INV_STATUS_su_ic_inv_done_END (0)
#define SOC_NPU_AICORE_SC_SU_IC_INV_STATUS_vec_ic_inv_done_START (1)
#define SOC_NPU_AICORE_SC_SU_IC_INV_STATUS_vec_ic_inv_done_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_all_idle : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_SC_AIC_INNER_STATUS_UNION;
#endif
#define SOC_NPU_AICORE_SC_AIC_INNER_STATUS_aic_all_idle_START (0)
#define SOC_NPU_AICORE_SC_AIC_INNER_STATUS_aic_all_idle_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_clk_en_mask : 1;
        unsigned int pmu_clk_en_mask : 1;
        unsigned int slcsw_clk_en_mask : 1;
        unsigned int reserved : 28;
        unsigned int clk_global_en_mask : 1;
    } reg;
} SOC_NPU_AICORE_SC_CLK_GATE_MASK_0_UNION;
#endif
#define SOC_NPU_AICORE_SC_CLK_GATE_MASK_0_dbg_clk_en_mask_START (0)
#define SOC_NPU_AICORE_SC_CLK_GATE_MASK_0_dbg_clk_en_mask_END (0)
#define SOC_NPU_AICORE_SC_CLK_GATE_MASK_0_pmu_clk_en_mask_START (1)
#define SOC_NPU_AICORE_SC_CLK_GATE_MASK_0_pmu_clk_en_mask_END (1)
#define SOC_NPU_AICORE_SC_CLK_GATE_MASK_0_slcsw_clk_en_mask_START (2)
#define SOC_NPU_AICORE_SC_CLK_GATE_MASK_0_slcsw_clk_en_mask_END (2)
#define SOC_NPU_AICORE_SC_CLK_GATE_MASK_0_clk_global_en_mask_START (31)
#define SOC_NPU_AICORE_SC_CLK_GATE_MASK_0_clk_global_en_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int djtag_clk_bypass_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_SC_DJTAG_CLK_BYPASS_UNION;
#endif
#define SOC_NPU_AICORE_SC_DJTAG_CLK_BYPASS_djtag_clk_bypass_en_START (0)
#define SOC_NPU_AICORE_SC_DJTAG_CLK_BYPASS_djtag_clk_bypass_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_clk_top_off_dly_cnt : 8;
        unsigned int sc_mem_init_dly_cnt : 4;
        unsigned int sc_top_en_clk_dly_cnt : 4;
        unsigned int sc_rst_mask_dly_cnt : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_NPU_AICORE_SC_CLK_DELAY_CNT_UNION;
#endif
#define SOC_NPU_AICORE_SC_CLK_DELAY_CNT_sc_clk_top_off_dly_cnt_START (0)
#define SOC_NPU_AICORE_SC_CLK_DELAY_CNT_sc_clk_top_off_dly_cnt_END (7)
#define SOC_NPU_AICORE_SC_CLK_DELAY_CNT_sc_mem_init_dly_cnt_START (8)
#define SOC_NPU_AICORE_SC_CLK_DELAY_CNT_sc_mem_init_dly_cnt_END (11)
#define SOC_NPU_AICORE_SC_CLK_DELAY_CNT_sc_top_en_clk_dly_cnt_START (12)
#define SOC_NPU_AICORE_SC_CLK_DELAY_CNT_sc_top_en_clk_dly_cnt_END (15)
#define SOC_NPU_AICORE_SC_CLK_DELAY_CNT_sc_rst_mask_dly_cnt_START (16)
#define SOC_NPU_AICORE_SC_CLK_DELAY_CNT_sc_rst_mask_dly_cnt_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfg_write_done_dly_cnt : 8;
        unsigned int task_done_rpt_dly_cnt : 8;
        unsigned int task_dbg_rpt_dly_cnt : 8;
        unsigned int sc_cfg_write_dly_cnt : 3;
        unsigned int reserved : 5;
    } reg;
} SOC_NPU_AICORE_SC_CFG_DELAY_CNT_UNION;
#endif
#define SOC_NPU_AICORE_SC_CFG_DELAY_CNT_cfg_write_done_dly_cnt_START (0)
#define SOC_NPU_AICORE_SC_CFG_DELAY_CNT_cfg_write_done_dly_cnt_END (7)
#define SOC_NPU_AICORE_SC_CFG_DELAY_CNT_task_done_rpt_dly_cnt_START (8)
#define SOC_NPU_AICORE_SC_CFG_DELAY_CNT_task_done_rpt_dly_cnt_END (15)
#define SOC_NPU_AICORE_SC_CFG_DELAY_CNT_task_dbg_rpt_dly_cnt_START (16)
#define SOC_NPU_AICORE_SC_CFG_DELAY_CNT_task_dbg_rpt_dly_cnt_END (23)
#define SOC_NPU_AICORE_SC_CFG_DELAY_CNT_sc_cfg_write_dly_cnt_START (24)
#define SOC_NPU_AICORE_SC_CFG_DELAY_CNT_sc_cfg_write_dly_cnt_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lock_bypass0_srcid : 12;
        unsigned int reserved : 1;
        unsigned int lock_bypass0_lpid : 3;
        unsigned int lock_bypass0_mask_n : 15;
        unsigned int lock_bypass0_en : 1;
    } reg;
} SOC_NPU_AICORE_SC_LOCK_BYPASS_0_UNION;
#endif
#define SOC_NPU_AICORE_SC_LOCK_BYPASS_0_lock_bypass0_srcid_START (0)
#define SOC_NPU_AICORE_SC_LOCK_BYPASS_0_lock_bypass0_srcid_END (11)
#define SOC_NPU_AICORE_SC_LOCK_BYPASS_0_lock_bypass0_lpid_START (13)
#define SOC_NPU_AICORE_SC_LOCK_BYPASS_0_lock_bypass0_lpid_END (15)
#define SOC_NPU_AICORE_SC_LOCK_BYPASS_0_lock_bypass0_mask_n_START (16)
#define SOC_NPU_AICORE_SC_LOCK_BYPASS_0_lock_bypass0_mask_n_END (30)
#define SOC_NPU_AICORE_SC_LOCK_BYPASS_0_lock_bypass0_en_START (31)
#define SOC_NPU_AICORE_SC_LOCK_BYPASS_0_lock_bypass0_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lock_bypass1_srcid : 12;
        unsigned int reserved : 1;
        unsigned int lock_bypass1_lpid : 3;
        unsigned int lock_bypass1_mask_n : 15;
        unsigned int lock_bypass1_en : 1;
    } reg;
} SOC_NPU_AICORE_SC_LOCK_BYPASS_1_UNION;
#endif
#define SOC_NPU_AICORE_SC_LOCK_BYPASS_1_lock_bypass1_srcid_START (0)
#define SOC_NPU_AICORE_SC_LOCK_BYPASS_1_lock_bypass1_srcid_END (11)
#define SOC_NPU_AICORE_SC_LOCK_BYPASS_1_lock_bypass1_lpid_START (13)
#define SOC_NPU_AICORE_SC_LOCK_BYPASS_1_lock_bypass1_lpid_END (15)
#define SOC_NPU_AICORE_SC_LOCK_BYPASS_1_lock_bypass1_mask_n_START (16)
#define SOC_NPU_AICORE_SC_LOCK_BYPASS_1_lock_bypass1_mask_n_END (30)
#define SOC_NPU_AICORE_SC_LOCK_BYPASS_1_lock_bypass1_en_START (31)
#define SOC_NPU_AICORE_SC_LOCK_BYPASS_1_lock_bypass1_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sysctrl_lock : 32;
    } reg;
} SOC_NPU_AICORE_SC_SYSCTRL_LOCK_UNION;
#endif
#define SOC_NPU_AICORE_SC_SYSCTRL_LOCK_sysctrl_lock_START (0)
#define SOC_NPU_AICORE_SC_SYSCTRL_LOCK_sysctrl_lock_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_timeout_cnt : 32;
    } reg;
} SOC_NPU_AICORE_SC_BUS_TIMEOUT_CFG_L_UNION;
#endif
#define SOC_NPU_AICORE_SC_BUS_TIMEOUT_CFG_L_sc_timeout_cnt_START (0)
#define SOC_NPU_AICORE_SC_BUS_TIMEOUT_CFG_L_sc_timeout_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 31;
        unsigned int sc_bus_resp_timeout_en : 1;
    } reg;
} SOC_NPU_AICORE_SC_BUS_TIMEOUT_CFG_H_UNION;
#endif
#define SOC_NPU_AICORE_SC_BUS_TIMEOUT_CFG_H_sc_bus_resp_timeout_en_START (31)
#define SOC_NPU_AICORE_SC_BUS_TIMEOUT_CFG_H_sc_bus_resp_timeout_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_ctrl_wr : 1;
        unsigned int dbg_ctrl_rd : 1;
        unsigned int su_dbg_stall : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_NPU_AICORE_SC_DBG_RW_CTRL_UNION;
#endif
#define SOC_NPU_AICORE_SC_DBG_RW_CTRL_dbg_ctrl_wr_START (0)
#define SOC_NPU_AICORE_SC_DBG_RW_CTRL_dbg_ctrl_wr_END (0)
#define SOC_NPU_AICORE_SC_DBG_RW_CTRL_dbg_ctrl_rd_START (1)
#define SOC_NPU_AICORE_SC_DBG_RW_CTRL_dbg_ctrl_rd_END (1)
#define SOC_NPU_AICORE_SC_DBG_RW_CTRL_su_dbg_stall_START (2)
#define SOC_NPU_AICORE_SC_DBG_RW_CTRL_su_dbg_stall_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_addr_l : 32;
    } reg;
} SOC_NPU_AICORE_SC_DBG_ADDR_L_UNION;
#endif
#define SOC_NPU_AICORE_SC_DBG_ADDR_L_dbg_addr_l_START (0)
#define SOC_NPU_AICORE_SC_DBG_ADDR_L_dbg_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_addr_h : 24;
        unsigned int reserved : 8;
    } reg;
} SOC_NPU_AICORE_SC_DBG_ADDR_H_UNION;
#endif
#define SOC_NPU_AICORE_SC_DBG_ADDR_H_dbg_addr_h_START (0)
#define SOC_NPU_AICORE_SC_DBG_ADDR_H_dbg_addr_h_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_data_0 : 32;
    } reg;
} SOC_NPU_AICORE_SC_DBG_DATA_0_UNION;
#endif
#define SOC_NPU_AICORE_SC_DBG_DATA_0_dbg_data_0_START (0)
#define SOC_NPU_AICORE_SC_DBG_DATA_0_dbg_data_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_data_1 : 32;
    } reg;
} SOC_NPU_AICORE_SC_DBG_DATA_1_UNION;
#endif
#define SOC_NPU_AICORE_SC_DBG_DATA_1_dbg_data_1_START (0)
#define SOC_NPU_AICORE_SC_DBG_DATA_1_dbg_data_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_data_2 : 32;
    } reg;
} SOC_NPU_AICORE_SC_DBG_DATA_2_UNION;
#endif
#define SOC_NPU_AICORE_SC_DBG_DATA_2_dbg_data_2_START (0)
#define SOC_NPU_AICORE_SC_DBG_DATA_2_dbg_data_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_data_3 : 32;
    } reg;
} SOC_NPU_AICORE_SC_DBG_DATA_3_UNION;
#endif
#define SOC_NPU_AICORE_SC_DBG_DATA_3_dbg_data_3_START (0)
#define SOC_NPU_AICORE_SC_DBG_DATA_3_dbg_data_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_data_4 : 32;
    } reg;
} SOC_NPU_AICORE_SC_DBG_DATA_4_UNION;
#endif
#define SOC_NPU_AICORE_SC_DBG_DATA_4_dbg_data_4_START (0)
#define SOC_NPU_AICORE_SC_DBG_DATA_4_dbg_data_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_data_5 : 32;
    } reg;
} SOC_NPU_AICORE_SC_DBG_DATA_5_UNION;
#endif
#define SOC_NPU_AICORE_SC_DBG_DATA_5_dbg_data_5_START (0)
#define SOC_NPU_AICORE_SC_DBG_DATA_5_dbg_data_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_data_6 : 32;
    } reg;
} SOC_NPU_AICORE_SC_DBG_DATA_6_UNION;
#endif
#define SOC_NPU_AICORE_SC_DBG_DATA_6_dbg_data_6_START (0)
#define SOC_NPU_AICORE_SC_DBG_DATA_6_dbg_data_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_data_7 : 32;
    } reg;
} SOC_NPU_AICORE_SC_DBG_DATA_7_UNION;
#endif
#define SOC_NPU_AICORE_SC_DBG_DATA_7_dbg_data_7_START (0)
#define SOC_NPU_AICORE_SC_DBG_DATA_7_dbg_data_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_cache_invalid : 1;
        unsigned int dbg_access_fail : 1;
        unsigned int dbg_read_err : 1;
        unsigned int reserved : 28;
        unsigned int dbg_rw_done : 1;
    } reg;
} SOC_NPU_AICORE_SC_DBG_STATUS_UNION;
#endif
#define SOC_NPU_AICORE_SC_DBG_STATUS_dbg_cache_invalid_START (0)
#define SOC_NPU_AICORE_SC_DBG_STATUS_dbg_cache_invalid_END (0)
#define SOC_NPU_AICORE_SC_DBG_STATUS_dbg_access_fail_START (1)
#define SOC_NPU_AICORE_SC_DBG_STATUS_dbg_access_fail_END (1)
#define SOC_NPU_AICORE_SC_DBG_STATUS_dbg_read_err_START (2)
#define SOC_NPU_AICORE_SC_DBG_STATUS_dbg_read_err_END (2)
#define SOC_NPU_AICORE_SC_DBG_STATUS_dbg_rw_done_START (31)
#define SOC_NPU_AICORE_SC_DBG_STATUS_dbg_rw_done_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_resume_aic_p : 1;
        unsigned int dbg_resume_sc_p : 1;
        unsigned int aiv_dbg_over : 1;
        unsigned int dbg_ctrl_reserved : 29;
    } reg;
} SOC_NPU_AICORE_SC_EXIT_DBG_CTRL_UNION;
#endif
#define SOC_NPU_AICORE_SC_EXIT_DBG_CTRL_dbg_resume_aic_p_START (0)
#define SOC_NPU_AICORE_SC_EXIT_DBG_CTRL_dbg_resume_aic_p_END (0)
#define SOC_NPU_AICORE_SC_EXIT_DBG_CTRL_dbg_resume_sc_p_START (1)
#define SOC_NPU_AICORE_SC_EXIT_DBG_CTRL_dbg_resume_sc_p_END (1)
#define SOC_NPU_AICORE_SC_EXIT_DBG_CTRL_aiv_dbg_over_START (2)
#define SOC_NPU_AICORE_SC_EXIT_DBG_CTRL_aiv_dbg_over_END (2)
#define SOC_NPU_AICORE_SC_EXIT_DBG_CTRL_dbg_ctrl_reserved_START (3)
#define SOC_NPU_AICORE_SC_EXIT_DBG_CTRL_dbg_ctrl_reserved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int user_profile_mode : 1;
        unsigned int sample_profile_mode : 1;
        unsigned int aic_task_cyc_cnt_en : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_NPU_AICORE_SC_PMU_CTRL_CFG_UNION;
#endif
#define SOC_NPU_AICORE_SC_PMU_CTRL_CFG_user_profile_mode_START (0)
#define SOC_NPU_AICORE_SC_PMU_CTRL_CFG_user_profile_mode_END (0)
#define SOC_NPU_AICORE_SC_PMU_CTRL_CFG_sample_profile_mode_START (1)
#define SOC_NPU_AICORE_SC_PMU_CTRL_CFG_sample_profile_mode_END (1)
#define SOC_NPU_AICORE_SC_PMU_CTRL_CFG_aic_task_cyc_cnt_en_START (2)
#define SOC_NPU_AICORE_SC_PMU_CTRL_CFG_aic_task_cyc_cnt_en_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_overflow : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_SC_PMU_CNT_STATUS_UNION;
#endif
#define SOC_NPU_AICORE_SC_PMU_CNT_STATUS_pmu_overflow_START (0)
#define SOC_NPU_AICORE_SC_PMU_CNT_STATUS_pmu_overflow_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_min_ov_cnt_l : 32;
    } reg;
} SOC_NPU_AICORE_SC_PMU_MIN_OV_CNT_L_UNION;
#endif
#define SOC_NPU_AICORE_SC_PMU_MIN_OV_CNT_L_pmu_min_ov_cnt_l_START (0)
#define SOC_NPU_AICORE_SC_PMU_MIN_OV_CNT_L_pmu_min_ov_cnt_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_min_ov_cnt_h : 32;
    } reg;
} SOC_NPU_AICORE_SC_PMU_MIN_OV_CNT_H_UNION;
#endif
#define SOC_NPU_AICORE_SC_PMU_MIN_OV_CNT_H_pmu_min_ov_cnt_h_START (0)
#define SOC_NPU_AICORE_SC_PMU_MIN_OV_CNT_H_pmu_min_ov_cnt_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_cnt : 32;
    } reg;
} SOC_NPU_AICORE_SC_PMU_CNT_UNION;
#endif
#define SOC_NPU_AICORE_SC_PMU_CNT_pmu_cnt_START (0)
#define SOC_NPU_AICORE_SC_PMU_CNT_pmu_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_task_cyc_cnt_l : 32;
    } reg;
} SOC_NPU_AICORE_SC_PMU_TASK_CYC_CNT_L_UNION;
#endif
#define SOC_NPU_AICORE_SC_PMU_TASK_CYC_CNT_L_pmu_task_cyc_cnt_l_START (0)
#define SOC_NPU_AICORE_SC_PMU_TASK_CYC_CNT_L_pmu_task_cyc_cnt_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_task_cyc_cnt_h : 32;
    } reg;
} SOC_NPU_AICORE_SC_PMU_TASK_CYC_CNT_H_UNION;
#endif
#define SOC_NPU_AICORE_SC_PMU_TASK_CYC_CNT_H_pmu_task_cyc_cnt_h_START (0)
#define SOC_NPU_AICORE_SC_PMU_TASK_CYC_CNT_H_pmu_task_cyc_cnt_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_kist_timestamp_l : 32;
    } reg;
} SOC_NPU_AICORE_SC_PMU_AIC_KIST_TIMESTAMP_L_UNION;
#endif
#define SOC_NPU_AICORE_SC_PMU_AIC_KIST_TIMESTAMP_L_aic_kist_timestamp_l_START (0)
#define SOC_NPU_AICORE_SC_PMU_AIC_KIST_TIMESTAMP_L_aic_kist_timestamp_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_kist_timestamp_h : 32;
    } reg;
} SOC_NPU_AICORE_SC_PMU_AIC_KIST_TIMESTAMP_H_UNION;
#endif
#define SOC_NPU_AICORE_SC_PMU_AIC_KIST_TIMESTAMP_H_aic_kist_timestamp_h_START (0)
#define SOC_NPU_AICORE_SC_PMU_AIC_KIST_TIMESTAMP_H_aic_kist_timestamp_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_SC_PMU_RESERVED_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_SC_PMU_RESERVED_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_SC_PMU_RESERVED_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_SC_PMU_RESERVED_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_start_cnt_cyc_l : 32;
    } reg;
} SOC_NPU_AICORE_SC_PMU_START_CNT_CYC_L_UNION;
#endif
#define SOC_NPU_AICORE_SC_PMU_START_CNT_CYC_L_pmu_start_cnt_cyc_l_START (0)
#define SOC_NPU_AICORE_SC_PMU_START_CNT_CYC_L_pmu_start_cnt_cyc_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_start_cnt_cyc_h : 32;
    } reg;
} SOC_NPU_AICORE_SC_PMU_START_CNT_CYC_H_UNION;
#endif
#define SOC_NPU_AICORE_SC_PMU_START_CNT_CYC_H_pmu_start_cnt_cyc_h_START (0)
#define SOC_NPU_AICORE_SC_PMU_START_CNT_CYC_H_pmu_start_cnt_cyc_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_stop_cnt_cyc_l : 32;
    } reg;
} SOC_NPU_AICORE_SC_PMU_STOP_CNT_CYC_L_UNION;
#endif
#define SOC_NPU_AICORE_SC_PMU_STOP_CNT_CYC_L_pmu_stop_cnt_cyc_l_START (0)
#define SOC_NPU_AICORE_SC_PMU_STOP_CNT_CYC_L_pmu_stop_cnt_cyc_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_stop_cnt_cyc_h : 32;
    } reg;
} SOC_NPU_AICORE_SC_PMU_STOP_CNT_CYC_H_UNION;
#endif
#define SOC_NPU_AICORE_SC_PMU_STOP_CNT_CYC_H_pmu_stop_cnt_cyc_h_START (0)
#define SOC_NPU_AICORE_SC_PMU_STOP_CNT_CYC_H_pmu_stop_cnt_cyc_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_task_cyc_cnt_l : 32;
    } reg;
} SOC_NPU_AICORE_SC_AIC_TASK_CYC_CNT_L_UNION;
#endif
#define SOC_NPU_AICORE_SC_AIC_TASK_CYC_CNT_L_aic_task_cyc_cnt_l_START (0)
#define SOC_NPU_AICORE_SC_AIC_TASK_CYC_CNT_L_aic_task_cyc_cnt_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_task_cyc_cnt_h : 32;
    } reg;
} SOC_NPU_AICORE_SC_AIC_TASK_CYC_CNT_H_UNION;
#endif
#define SOC_NPU_AICORE_SC_AIC_TASK_CYC_CNT_H_aic_task_cyc_cnt_h_START (0)
#define SOC_NPU_AICORE_SC_AIC_TASK_CYC_CNT_H_aic_task_cyc_cnt_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_cnt_sw_bus_err_t0 : 1;
        unsigned int sc_reg_parity_err_t0 : 1;
        unsigned int sc_slow_csw_rob_ecc_err_t0 : 1;
        unsigned int sc_bus_resp_timeout_err : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_NPU_AICORE_SC_ERROR_T0_0_UNION;
#endif
#define SOC_NPU_AICORE_SC_ERROR_T0_0_sc_cnt_sw_bus_err_t0_START (0)
#define SOC_NPU_AICORE_SC_ERROR_T0_0_sc_cnt_sw_bus_err_t0_END (0)
#define SOC_NPU_AICORE_SC_ERROR_T0_0_sc_reg_parity_err_t0_START (1)
#define SOC_NPU_AICORE_SC_ERROR_T0_0_sc_reg_parity_err_t0_END (1)
#define SOC_NPU_AICORE_SC_ERROR_T0_0_sc_slow_csw_rob_ecc_err_t0_START (2)
#define SOC_NPU_AICORE_SC_ERROR_T0_0_sc_slow_csw_rob_ecc_err_t0_END (2)
#define SOC_NPU_AICORE_SC_ERROR_T0_0_sc_bus_resp_timeout_err_START (3)
#define SOC_NPU_AICORE_SC_ERROR_T0_0_sc_bus_resp_timeout_err_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_cnt_sw_bus_err_mask : 1;
        unsigned int sc_reg_parity_err_mask : 1;
        unsigned int sc_slow_csw_rob_ecc_err_mask : 1;
        unsigned int sc_bus_resp_timeout_err_mask : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_NPU_AICORE_SC_ERROR_MASK_0_UNION;
#endif
#define SOC_NPU_AICORE_SC_ERROR_MASK_0_sc_cnt_sw_bus_err_mask_START (0)
#define SOC_NPU_AICORE_SC_ERROR_MASK_0_sc_cnt_sw_bus_err_mask_END (0)
#define SOC_NPU_AICORE_SC_ERROR_MASK_0_sc_reg_parity_err_mask_START (1)
#define SOC_NPU_AICORE_SC_ERROR_MASK_0_sc_reg_parity_err_mask_END (1)
#define SOC_NPU_AICORE_SC_ERROR_MASK_0_sc_slow_csw_rob_ecc_err_mask_START (2)
#define SOC_NPU_AICORE_SC_ERROR_MASK_0_sc_slow_csw_rob_ecc_err_mask_END (2)
#define SOC_NPU_AICORE_SC_ERROR_MASK_0_sc_bus_resp_timeout_err_mask_START (3)
#define SOC_NPU_AICORE_SC_ERROR_MASK_0_sc_bus_resp_timeout_err_mask_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_cnt_sw_err_addr_l_t0 : 32;
    } reg;
} SOC_NPU_AICORE_SC_ERR_INFO_T0_0_UNION;
#endif
#define SOC_NPU_AICORE_SC_ERR_INFO_T0_0_sc_cnt_sw_err_addr_l_t0_START (0)
#define SOC_NPU_AICORE_SC_ERR_INFO_T0_0_sc_cnt_sw_err_addr_l_t0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_cnt_sw_err_addr_h_t0 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_AICORE_SC_ERR_INFO_T0_1_UNION;
#endif
#define SOC_NPU_AICORE_SC_ERR_INFO_T0_1_sc_cnt_sw_err_addr_h_t0_START (0)
#define SOC_NPU_AICORE_SC_ERR_INFO_T0_1_sc_cnt_sw_err_addr_h_t0_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int safety_ecc_err_int : 1;
        unsigned int safety_bus_err_int : 1;
        unsigned int safety_crc_err_int : 1;
        unsigned int safety_ecc_warm_int : 1;
        unsigned int safety_reg_pty_err_int : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_NPU_AICORE_SC_SAFETY_INT_UNION;
#endif
#define SOC_NPU_AICORE_SC_SAFETY_INT_safety_ecc_err_int_START (0)
#define SOC_NPU_AICORE_SC_SAFETY_INT_safety_ecc_err_int_END (0)
#define SOC_NPU_AICORE_SC_SAFETY_INT_safety_bus_err_int_START (1)
#define SOC_NPU_AICORE_SC_SAFETY_INT_safety_bus_err_int_END (1)
#define SOC_NPU_AICORE_SC_SAFETY_INT_safety_crc_err_int_START (2)
#define SOC_NPU_AICORE_SC_SAFETY_INT_safety_crc_err_int_END (2)
#define SOC_NPU_AICORE_SC_SAFETY_INT_safety_ecc_warm_int_START (3)
#define SOC_NPU_AICORE_SC_SAFETY_INT_safety_ecc_warm_int_END (3)
#define SOC_NPU_AICORE_SC_SAFETY_INT_safety_reg_pty_err_int_START (4)
#define SOC_NPU_AICORE_SC_SAFETY_INT_safety_reg_pty_err_int_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int safety_int_ecc_err_mask : 1;
        unsigned int safety_int_bus_err_mask : 1;
        unsigned int safety_int_crc_err_mask : 1;
        unsigned int safety_int_ecc_warm_mask : 1;
        unsigned int safety_int_reg_pty_err_mask : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_NPU_AICORE_SC_SAFETY_INT_MASK_UNION;
#endif
#define SOC_NPU_AICORE_SC_SAFETY_INT_MASK_safety_int_ecc_err_mask_START (0)
#define SOC_NPU_AICORE_SC_SAFETY_INT_MASK_safety_int_ecc_err_mask_END (0)
#define SOC_NPU_AICORE_SC_SAFETY_INT_MASK_safety_int_bus_err_mask_START (1)
#define SOC_NPU_AICORE_SC_SAFETY_INT_MASK_safety_int_bus_err_mask_END (1)
#define SOC_NPU_AICORE_SC_SAFETY_INT_MASK_safety_int_crc_err_mask_START (2)
#define SOC_NPU_AICORE_SC_SAFETY_INT_MASK_safety_int_crc_err_mask_END (2)
#define SOC_NPU_AICORE_SC_SAFETY_INT_MASK_safety_int_ecc_warm_mask_START (3)
#define SOC_NPU_AICORE_SC_SAFETY_INT_MASK_safety_int_ecc_warm_mask_END (3)
#define SOC_NPU_AICORE_SC_SAFETY_INT_MASK_safety_int_reg_pty_err_mask_START (4)
#define SOC_NPU_AICORE_SC_SAFETY_INT_MASK_safety_int_reg_pty_err_mask_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int safety_err_ecc_err_mask : 1;
        unsigned int safety_err_bus_err_mask : 1;
        unsigned int safety_err_crc_err_mask : 1;
        unsigned int safety_err_ecc_warm_mask : 1;
        unsigned int safety_err_reg_pty_err_mask : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_NPU_AICORE_SC_SAFETY_ERR_MASK_UNION;
#endif
#define SOC_NPU_AICORE_SC_SAFETY_ERR_MASK_safety_err_ecc_err_mask_START (0)
#define SOC_NPU_AICORE_SC_SAFETY_ERR_MASK_safety_err_ecc_err_mask_END (0)
#define SOC_NPU_AICORE_SC_SAFETY_ERR_MASK_safety_err_bus_err_mask_START (1)
#define SOC_NPU_AICORE_SC_SAFETY_ERR_MASK_safety_err_bus_err_mask_END (1)
#define SOC_NPU_AICORE_SC_SAFETY_ERR_MASK_safety_err_crc_err_mask_START (2)
#define SOC_NPU_AICORE_SC_SAFETY_ERR_MASK_safety_err_crc_err_mask_END (2)
#define SOC_NPU_AICORE_SC_SAFETY_ERR_MASK_safety_err_ecc_warm_mask_START (3)
#define SOC_NPU_AICORE_SC_SAFETY_ERR_MASK_safety_err_ecc_warm_mask_END (3)
#define SOC_NPU_AICORE_SC_SAFETY_ERR_MASK_safety_err_reg_pty_err_mask_START (4)
#define SOC_NPU_AICORE_SC_SAFETY_ERR_MASK_safety_err_reg_pty_err_mask_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int safety_ecc_err_int_inject : 1;
        unsigned int safety_bus_err_int_inject : 1;
        unsigned int safety_crc_err_int_inject : 1;
        unsigned int safety_ecc_warm_int_inject : 1;
        unsigned int safety_reg_pty_err_int_inject : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_NPU_AICORE_SC_SAFETY_INT_INJECT_UNION;
#endif
#define SOC_NPU_AICORE_SC_SAFETY_INT_INJECT_safety_ecc_err_int_inject_START (0)
#define SOC_NPU_AICORE_SC_SAFETY_INT_INJECT_safety_ecc_err_int_inject_END (0)
#define SOC_NPU_AICORE_SC_SAFETY_INT_INJECT_safety_bus_err_int_inject_START (1)
#define SOC_NPU_AICORE_SC_SAFETY_INT_INJECT_safety_bus_err_int_inject_END (1)
#define SOC_NPU_AICORE_SC_SAFETY_INT_INJECT_safety_crc_err_int_inject_START (2)
#define SOC_NPU_AICORE_SC_SAFETY_INT_INJECT_safety_crc_err_int_inject_END (2)
#define SOC_NPU_AICORE_SC_SAFETY_INT_INJECT_safety_ecc_warm_int_inject_START (3)
#define SOC_NPU_AICORE_SC_SAFETY_INT_INJECT_safety_ecc_warm_int_inject_END (3)
#define SOC_NPU_AICORE_SC_SAFETY_INT_INJECT_safety_reg_pty_err_int_inject_START (4)
#define SOC_NPU_AICORE_SC_SAFETY_INT_INJECT_safety_reg_pty_err_int_inject_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_reserved_ro_reg0 : 32;
    } reg;
} SOC_NPU_AICORE_SC_RESERVED_RO_REG0_UNION;
#endif
#define SOC_NPU_AICORE_SC_RESERVED_RO_REG0_sc_reserved_ro_reg0_START (0)
#define SOC_NPU_AICORE_SC_RESERVED_RO_REG0_sc_reserved_ro_reg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_reserved_ro_reg1 : 32;
    } reg;
} SOC_NPU_AICORE_SC_RESERVED_RO_REG1_UNION;
#endif
#define SOC_NPU_AICORE_SC_RESERVED_RO_REG1_sc_reserved_ro_reg1_START (0)
#define SOC_NPU_AICORE_SC_RESERVED_RO_REG1_sc_reserved_ro_reg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_SC_RESERVED_RO_REG2_RSV_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_SC_RESERVED_RO_REG3_RSV_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_reserved_rw_reg0 : 32;
    } reg;
} SOC_NPU_AICORE_SC_RESERVED_RW_REG0_UNION;
#endif
#define SOC_NPU_AICORE_SC_RESERVED_RW_REG0_sc_reserved_rw_reg0_START (0)
#define SOC_NPU_AICORE_SC_RESERVED_RW_REG0_sc_reserved_rw_reg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_reserved_rw_reg1 : 32;
    } reg;
} SOC_NPU_AICORE_SC_RESERVED_RW_REG1_UNION;
#endif
#define SOC_NPU_AICORE_SC_RESERVED_RW_REG1_sc_reserved_rw_reg1_START (0)
#define SOC_NPU_AICORE_SC_RESERVED_RW_REG1_sc_reserved_rw_reg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_SC_RESERVED_RW_REG2_RSV_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_SC_RESERVED_RW_REG3_RSV_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_pre_rst_stall : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_SC_PRE_RST_STALL_CTRL_UNION;
#endif
#define SOC_NPU_AICORE_SC_PRE_RST_STALL_CTRL_sc_pre_rst_stall_START (0)
#define SOC_NPU_AICORE_SC_PRE_RST_STALL_CTRL_sc_pre_rst_stall_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_pre_rst_rdy : 1;
        unsigned int sc_inner_status_busy : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_AICORE_SC_PRE_RST_STATUS_UNION;
#endif
#define SOC_NPU_AICORE_SC_PRE_RST_STATUS_sc_pre_rst_rdy_START (0)
#define SOC_NPU_AICORE_SC_PRE_RST_STATUS_sc_pre_rst_rdy_END (0)
#define SOC_NPU_AICORE_SC_PRE_RST_STATUS_sc_inner_status_busy_START (1)
#define SOC_NPU_AICORE_SC_PRE_RST_STATUS_sc_inner_status_busy_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sc_soft_rst_mask_n_cfg : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_SC_RST_MASK_N_CFG_UNION;
#endif
#define SOC_NPU_AICORE_SC_RST_MASK_N_CFG_sc_soft_rst_mask_n_cfg_START (0)
#define SOC_NPU_AICORE_SC_RST_MASK_N_CFG_sc_soft_rst_mask_n_cfg_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_pending_task_sta : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_SC_PENDING_TASK_STATUS_UNION;
#endif
#define SOC_NPU_AICORE_SC_PENDING_TASK_STATUS_aic_pending_task_sta_START (0)
#define SOC_NPU_AICORE_SC_PENDING_TASK_STATUS_aic_pending_task_sta_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aiv_slow_csw_stop : 1;
        unsigned int aiv_slow_csw_stall : 1;
        unsigned int reserved : 29;
        unsigned int slw_csw_busy : 1;
    } reg;
} SOC_NPU_AICORE_SC_CONTEXT_SWITCH_CFG_ST_UNION;
#endif
#define SOC_NPU_AICORE_SC_CONTEXT_SWITCH_CFG_ST_aiv_slow_csw_stop_START (0)
#define SOC_NPU_AICORE_SC_CONTEXT_SWITCH_CFG_ST_aiv_slow_csw_stop_END (0)
#define SOC_NPU_AICORE_SC_CONTEXT_SWITCH_CFG_ST_aiv_slow_csw_stall_START (1)
#define SOC_NPU_AICORE_SC_CONTEXT_SWITCH_CFG_ST_aiv_slow_csw_stall_END (1)
#define SOC_NPU_AICORE_SC_CONTEXT_SWITCH_CFG_ST_slw_csw_busy_START (31)
#define SOC_NPU_AICORE_SC_CONTEXT_SWITCH_CFG_ST_slw_csw_busy_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_run_task_one_by_one_en : 1;
        unsigned int aic_cross_core_bus_press_dis_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int aic_sc_active_excpt_dis : 1;
        unsigned int aic_sc_slow_csw_allow_dis : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_NPU_AICORE_SC_CHICKEN_BIT_CTRL_UNION;
#endif
#define SOC_NPU_AICORE_SC_CHICKEN_BIT_CTRL_aic_run_task_one_by_one_en_START (0)
#define SOC_NPU_AICORE_SC_CHICKEN_BIT_CTRL_aic_run_task_one_by_one_en_END (0)
#define SOC_NPU_AICORE_SC_CHICKEN_BIT_CTRL_aic_cross_core_bus_press_dis_en_START (1)
#define SOC_NPU_AICORE_SC_CHICKEN_BIT_CTRL_aic_cross_core_bus_press_dis_en_END (1)
#define SOC_NPU_AICORE_SC_CHICKEN_BIT_CTRL_aic_sc_active_excpt_dis_START (3)
#define SOC_NPU_AICORE_SC_CHICKEN_BIT_CTRL_aic_sc_active_excpt_dis_END (3)
#define SOC_NPU_AICORE_SC_CHICKEN_BIT_CTRL_aic_sc_slow_csw_allow_dis_START (4)
#define SOC_NPU_AICORE_SC_CHICKEN_BIT_CTRL_aic_sc_slow_csw_allow_dis_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_sc_inner_status : 32;
    } reg;
} SOC_NPU_AICORE_SC_INNER_STATUS_UNION;
#endif
#define SOC_NPU_AICORE_SC_INNER_STATUS_aic_sc_inner_status_START (0)
#define SOC_NPU_AICORE_SC_INNER_STATUS_aic_sc_inner_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_data_main_base_l : 32;
    } reg;
} SOC_NPU_AICORE_SU_KIS_DATA_MAIN_BASE_L_UNION;
#endif
#define SOC_NPU_AICORE_SU_KIS_DATA_MAIN_BASE_L_kis_data_main_base_l_START (0)
#define SOC_NPU_AICORE_SU_KIS_DATA_MAIN_BASE_L_kis_data_main_base_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_data_main_base_h : 32;
    } reg;
} SOC_NPU_AICORE_SU_KIS_DATA_MAIN_BASE_H_UNION;
#endif
#define SOC_NPU_AICORE_SU_KIS_DATA_MAIN_BASE_H_kis_data_main_base_h_START (0)
#define SOC_NPU_AICORE_SU_KIS_DATA_MAIN_BASE_H_kis_data_main_base_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_data_ub_base_l : 32;
    } reg;
} SOC_NPU_AICORE_SU_KIS_DATA_UB_BASE_L_UNION;
#endif
#define SOC_NPU_AICORE_SU_KIS_DATA_UB_BASE_L_kis_data_ub_base_l_START (0)
#define SOC_NPU_AICORE_SU_KIS_DATA_UB_BASE_L_kis_data_ub_base_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int kis_data_ub_base_h : 32;
    } reg;
} SOC_NPU_AICORE_SU_KIS_DATA_UB_BASE_H_UNION;
#endif
#define SOC_NPU_AICORE_SU_KIS_DATA_UB_BASE_H_kis_data_ub_base_h_START (0)
#define SOC_NPU_AICORE_SU_KIS_DATA_UB_BASE_H_kis_data_ub_base_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk_su_en_mask : 32;
    } reg;
} SOC_NPU_AICORE_SU_CLK_GATE_MASK_0_UNION;
#endif
#define SOC_NPU_AICORE_SU_CLK_GATE_MASK_0_clk_su_en_mask_START (0)
#define SOC_NPU_AICORE_SU_CLK_GATE_MASK_0_clk_su_en_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk_su_vec_delay_cnt : 5;
        unsigned int reserved_0 : 3;
        unsigned int clk_su_mte_delay_cnt : 5;
        unsigned int reserved_1 : 3;
        unsigned int clk_su_cube_delay_cnt : 5;
        unsigned int reserved_2 : 3;
        unsigned int clk_su_ub_delay_cnt : 5;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_NPU_AICORE_SU_CLK_DELAY_CNT_0_UNION;
#endif
#define SOC_NPU_AICORE_SU_CLK_DELAY_CNT_0_clk_su_vec_delay_cnt_START (0)
#define SOC_NPU_AICORE_SU_CLK_DELAY_CNT_0_clk_su_vec_delay_cnt_END (4)
#define SOC_NPU_AICORE_SU_CLK_DELAY_CNT_0_clk_su_mte_delay_cnt_START (8)
#define SOC_NPU_AICORE_SU_CLK_DELAY_CNT_0_clk_su_mte_delay_cnt_END (12)
#define SOC_NPU_AICORE_SU_CLK_DELAY_CNT_0_clk_su_cube_delay_cnt_START (16)
#define SOC_NPU_AICORE_SU_CLK_DELAY_CNT_0_clk_su_cube_delay_cnt_END (20)
#define SOC_NPU_AICORE_SU_CLK_DELAY_CNT_0_clk_su_ub_delay_cnt_START (24)
#define SOC_NPU_AICORE_SU_CLK_DELAY_CNT_0_clk_su_ub_delay_cnt_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk_su_fixp_delay_cnt : 5;
        unsigned int clk_su_iq_delay_cnt : 5;
        unsigned int clk_su_sc_active_delay_cnt : 4;
        unsigned int reserved : 18;
    } reg;
} SOC_NPU_AICORE_SU_CLK_DELAY_CNT_1_UNION;
#endif
#define SOC_NPU_AICORE_SU_CLK_DELAY_CNT_1_clk_su_fixp_delay_cnt_START (0)
#define SOC_NPU_AICORE_SU_CLK_DELAY_CNT_1_clk_su_fixp_delay_cnt_END (4)
#define SOC_NPU_AICORE_SU_CLK_DELAY_CNT_1_clk_su_iq_delay_cnt_START (5)
#define SOC_NPU_AICORE_SU_CLK_DELAY_CNT_1_clk_su_iq_delay_cnt_END (9)
#define SOC_NPU_AICORE_SU_CLK_DELAY_CNT_1_clk_su_sc_active_delay_cnt_START (10)
#define SOC_NPU_AICORE_SU_CLK_DELAY_CNT_1_clk_su_sc_active_delay_cnt_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_ecc_en_n : 1;
        unsigned int su_ecc_wb_en_n : 1;
        unsigned int su_ssbuf_ecc_en_n : 1;
        unsigned int su_ssbuf_ecc_wb_en_n : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_NPU_AICORE_SU_ECC_CTRL_0_UNION;
#endif
#define SOC_NPU_AICORE_SU_ECC_CTRL_0_su_ecc_en_n_START (0)
#define SOC_NPU_AICORE_SU_ECC_CTRL_0_su_ecc_en_n_END (0)
#define SOC_NPU_AICORE_SU_ECC_CTRL_0_su_ecc_wb_en_n_START (1)
#define SOC_NPU_AICORE_SU_ECC_CTRL_0_su_ecc_wb_en_n_END (1)
#define SOC_NPU_AICORE_SU_ECC_CTRL_0_su_ssbuf_ecc_en_n_START (2)
#define SOC_NPU_AICORE_SU_ECC_CTRL_0_su_ssbuf_ecc_en_n_END (2)
#define SOC_NPU_AICORE_SU_ECC_CTRL_0_su_ssbuf_ecc_wb_en_n_START (3)
#define SOC_NPU_AICORE_SU_ECC_CTRL_0_su_ssbuf_ecc_wb_en_n_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_icache_ecc_sb_inject : 1;
        unsigned int su_icache_ecc_mb_inject : 1;
        unsigned int su_dcache_ecc_sb_inject : 1;
        unsigned int su_dcache_ecc_mb_inject : 1;
        unsigned int su_veciq_ecc_sb_inject : 1;
        unsigned int su_veciq_ecc_mb_inject : 1;
        unsigned int su_rob_ecc_sb_inject : 1;
        unsigned int su_rob_ecc_mb_inject : 1;
        unsigned int su_ssbuf_ecc_sb_inject : 1;
        unsigned int su_ssbuf_ecc_mb_inject : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_AICORE_SU_ECC_INJECT_CTRL_0_UNION;
#endif
#define SOC_NPU_AICORE_SU_ECC_INJECT_CTRL_0_su_icache_ecc_sb_inject_START (0)
#define SOC_NPU_AICORE_SU_ECC_INJECT_CTRL_0_su_icache_ecc_sb_inject_END (0)
#define SOC_NPU_AICORE_SU_ECC_INJECT_CTRL_0_su_icache_ecc_mb_inject_START (1)
#define SOC_NPU_AICORE_SU_ECC_INJECT_CTRL_0_su_icache_ecc_mb_inject_END (1)
#define SOC_NPU_AICORE_SU_ECC_INJECT_CTRL_0_su_dcache_ecc_sb_inject_START (2)
#define SOC_NPU_AICORE_SU_ECC_INJECT_CTRL_0_su_dcache_ecc_sb_inject_END (2)
#define SOC_NPU_AICORE_SU_ECC_INJECT_CTRL_0_su_dcache_ecc_mb_inject_START (3)
#define SOC_NPU_AICORE_SU_ECC_INJECT_CTRL_0_su_dcache_ecc_mb_inject_END (3)
#define SOC_NPU_AICORE_SU_ECC_INJECT_CTRL_0_su_veciq_ecc_sb_inject_START (4)
#define SOC_NPU_AICORE_SU_ECC_INJECT_CTRL_0_su_veciq_ecc_sb_inject_END (4)
#define SOC_NPU_AICORE_SU_ECC_INJECT_CTRL_0_su_veciq_ecc_mb_inject_START (5)
#define SOC_NPU_AICORE_SU_ECC_INJECT_CTRL_0_su_veciq_ecc_mb_inject_END (5)
#define SOC_NPU_AICORE_SU_ECC_INJECT_CTRL_0_su_rob_ecc_sb_inject_START (6)
#define SOC_NPU_AICORE_SU_ECC_INJECT_CTRL_0_su_rob_ecc_sb_inject_END (6)
#define SOC_NPU_AICORE_SU_ECC_INJECT_CTRL_0_su_rob_ecc_mb_inject_START (7)
#define SOC_NPU_AICORE_SU_ECC_INJECT_CTRL_0_su_rob_ecc_mb_inject_END (7)
#define SOC_NPU_AICORE_SU_ECC_INJECT_CTRL_0_su_ssbuf_ecc_sb_inject_START (8)
#define SOC_NPU_AICORE_SU_ECC_INJECT_CTRL_0_su_ssbuf_ecc_sb_inject_END (8)
#define SOC_NPU_AICORE_SU_ECC_INJECT_CTRL_0_su_ssbuf_ecc_mb_inject_START (9)
#define SOC_NPU_AICORE_SU_ECC_INJECT_CTRL_0_su_ssbuf_ecc_mb_inject_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_ifu_prefetch_en : 2;
        unsigned int reserved_0 : 2;
        unsigned int su_ifu_ic_en : 1;
        unsigned int su_ifu_priority_push_en : 1;
        unsigned int su_ifu_read_merge_en : 1;
        unsigned int ifu_preload_stop : 1;
        unsigned int su_ifu_prefet_ost_lmt : 5;
        unsigned int reserved_1 : 19;
    } reg;
} SOC_NPU_AICORE_SU_IFU_CTRL_UNION;
#endif
#define SOC_NPU_AICORE_SU_IFU_CTRL_su_ifu_prefetch_en_START (0)
#define SOC_NPU_AICORE_SU_IFU_CTRL_su_ifu_prefetch_en_END (1)
#define SOC_NPU_AICORE_SU_IFU_CTRL_su_ifu_ic_en_START (4)
#define SOC_NPU_AICORE_SU_IFU_CTRL_su_ifu_ic_en_END (4)
#define SOC_NPU_AICORE_SU_IFU_CTRL_su_ifu_priority_push_en_START (5)
#define SOC_NPU_AICORE_SU_IFU_CTRL_su_ifu_priority_push_en_END (5)
#define SOC_NPU_AICORE_SU_IFU_CTRL_su_ifu_read_merge_en_START (6)
#define SOC_NPU_AICORE_SU_IFU_CTRL_su_ifu_read_merge_en_END (6)
#define SOC_NPU_AICORE_SU_IFU_CTRL_ifu_preload_stop_START (7)
#define SOC_NPU_AICORE_SU_IFU_CTRL_ifu_preload_stop_END (7)
#define SOC_NPU_AICORE_SU_IFU_CTRL_su_ifu_prefet_ost_lmt_START (8)
#define SOC_NPU_AICORE_SU_IFU_CTRL_su_ifu_prefet_ost_lmt_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_ccu_single_issue_mode : 1;
        unsigned int su_mte1_single_commit : 1;
        unsigned int su_mte2_single_commit : 1;
        unsigned int su_mte3_single_commit : 1;
        unsigned int su_vec_single_commit : 1;
        unsigned int su_cube_single_commit : 1;
        unsigned int su_global_single_commit : 1;
        unsigned int reserved_0 : 1;
        unsigned int su_mte4_single_commit : 1;
        unsigned int su_mte5_single_commit : 1;
        unsigned int su_dc_single_commit : 1;
        unsigned int su_fixp_single_commit : 1;
        unsigned int su_record_1st_ovflw_pc_en : 1;
        unsigned int su_ctrl_instrs_single_issue : 1;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_NPU_AICORE_SU_CCU_CTRL_UNION;
#endif
#define SOC_NPU_AICORE_SU_CCU_CTRL_su_ccu_single_issue_mode_START (0)
#define SOC_NPU_AICORE_SU_CCU_CTRL_su_ccu_single_issue_mode_END (0)
#define SOC_NPU_AICORE_SU_CCU_CTRL_su_mte1_single_commit_START (1)
#define SOC_NPU_AICORE_SU_CCU_CTRL_su_mte1_single_commit_END (1)
#define SOC_NPU_AICORE_SU_CCU_CTRL_su_mte2_single_commit_START (2)
#define SOC_NPU_AICORE_SU_CCU_CTRL_su_mte2_single_commit_END (2)
#define SOC_NPU_AICORE_SU_CCU_CTRL_su_mte3_single_commit_START (3)
#define SOC_NPU_AICORE_SU_CCU_CTRL_su_mte3_single_commit_END (3)
#define SOC_NPU_AICORE_SU_CCU_CTRL_su_vec_single_commit_START (4)
#define SOC_NPU_AICORE_SU_CCU_CTRL_su_vec_single_commit_END (4)
#define SOC_NPU_AICORE_SU_CCU_CTRL_su_cube_single_commit_START (5)
#define SOC_NPU_AICORE_SU_CCU_CTRL_su_cube_single_commit_END (5)
#define SOC_NPU_AICORE_SU_CCU_CTRL_su_global_single_commit_START (6)
#define SOC_NPU_AICORE_SU_CCU_CTRL_su_global_single_commit_END (6)
#define SOC_NPU_AICORE_SU_CCU_CTRL_su_mte4_single_commit_START (8)
#define SOC_NPU_AICORE_SU_CCU_CTRL_su_mte4_single_commit_END (8)
#define SOC_NPU_AICORE_SU_CCU_CTRL_su_mte5_single_commit_START (9)
#define SOC_NPU_AICORE_SU_CCU_CTRL_su_mte5_single_commit_END (9)
#define SOC_NPU_AICORE_SU_CCU_CTRL_su_dc_single_commit_START (10)
#define SOC_NPU_AICORE_SU_CCU_CTRL_su_dc_single_commit_END (10)
#define SOC_NPU_AICORE_SU_CCU_CTRL_su_fixp_single_commit_START (11)
#define SOC_NPU_AICORE_SU_CCU_CTRL_su_fixp_single_commit_END (11)
#define SOC_NPU_AICORE_SU_CCU_CTRL_su_record_1st_ovflw_pc_en_START (12)
#define SOC_NPU_AICORE_SU_CCU_CTRL_su_record_1st_ovflw_pc_en_END (12)
#define SOC_NPU_AICORE_SU_CCU_CTRL_su_ctrl_instrs_single_issue_START (13)
#define SOC_NPU_AICORE_SU_CCU_CTRL_su_ctrl_instrs_single_issue_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cross_core_flag0 : 1;
        unsigned int cross_core_flag1 : 1;
        unsigned int cross_core_flag2 : 1;
        unsigned int cross_core_flag3 : 1;
        unsigned int cross_core_flag4 : 1;
        unsigned int cross_core_flag5 : 1;
        unsigned int cross_core_flag6 : 1;
        unsigned int cross_core_flag7 : 1;
        unsigned int cross_core_flag8 : 1;
        unsigned int cross_core_flag9 : 1;
        unsigned int cross_core_flag10 : 1;
        unsigned int cross_core_flag11 : 1;
        unsigned int cross_core_flag12 : 1;
        unsigned int cross_core_flag13 : 1;
        unsigned int cross_core_flag14 : 1;
        unsigned int cross_core_flag15 : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_UNION;
#endif
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag0_START (0)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag0_END (0)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag1_START (1)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag1_END (1)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag2_START (2)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag2_END (2)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag3_START (3)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag3_END (3)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag4_START (4)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag4_END (4)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag5_START (5)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag5_END (5)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag6_START (6)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag6_END (6)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag7_START (7)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag7_END (7)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag8_START (8)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag8_END (8)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag9_START (9)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag9_END (9)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag10_START (10)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag10_END (10)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag11_START (11)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag11_END (11)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag12_START (12)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag12_END (12)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag13_START (13)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag13_END (13)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag14_START (14)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag14_END (14)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag15_START (15)
#define SOC_NPU_AICORE_SU_CROSS_CORE_FLAG_cross_core_flag15_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_stack_buffer_mode : 1;
        unsigned int su_lsu_fetcher_en : 1;
        unsigned int su_lsu_fetcher_fetchnum : 3;
        unsigned int su_lsu_fetcher_ost_cnt_lmt : 4;
        unsigned int su_lsu_fetcher_line_disp_num : 3;
        unsigned int su_lsu_fetcher_priority : 1;
        unsigned int su_lsu_ssbuf_en : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_NPU_AICORE_SU_LSU_CTRL_UNION;
#endif
#define SOC_NPU_AICORE_SU_LSU_CTRL_su_stack_buffer_mode_START (0)
#define SOC_NPU_AICORE_SU_LSU_CTRL_su_stack_buffer_mode_END (0)
#define SOC_NPU_AICORE_SU_LSU_CTRL_su_lsu_fetcher_en_START (1)
#define SOC_NPU_AICORE_SU_LSU_CTRL_su_lsu_fetcher_en_END (1)
#define SOC_NPU_AICORE_SU_LSU_CTRL_su_lsu_fetcher_fetchnum_START (2)
#define SOC_NPU_AICORE_SU_LSU_CTRL_su_lsu_fetcher_fetchnum_END (4)
#define SOC_NPU_AICORE_SU_LSU_CTRL_su_lsu_fetcher_ost_cnt_lmt_START (5)
#define SOC_NPU_AICORE_SU_LSU_CTRL_su_lsu_fetcher_ost_cnt_lmt_END (8)
#define SOC_NPU_AICORE_SU_LSU_CTRL_su_lsu_fetcher_line_disp_num_START (9)
#define SOC_NPU_AICORE_SU_LSU_CTRL_su_lsu_fetcher_line_disp_num_END (11)
#define SOC_NPU_AICORE_SU_LSU_CTRL_su_lsu_fetcher_priority_START (12)
#define SOC_NPU_AICORE_SU_LSU_CTRL_su_lsu_fetcher_priority_END (12)
#define SOC_NPU_AICORE_SU_LSU_CTRL_su_lsu_ssbuf_en_START (13)
#define SOC_NPU_AICORE_SU_LSU_CTRL_su_lsu_ssbuf_en_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ub_mem_attribute : 1;
        unsigned int reserved_0 : 7;
        unsigned int out_mem_attribute : 1;
        unsigned int reserved_1 : 7;
        unsigned int stack_mem_attribute : 1;
        unsigned int reserved_2 : 15;
    } reg;
} SOC_NPU_AICORE_SU_LSU_MPU_CTRL_UNION;
#endif
#define SOC_NPU_AICORE_SU_LSU_MPU_CTRL_ub_mem_attribute_START (0)
#define SOC_NPU_AICORE_SU_LSU_MPU_CTRL_ub_mem_attribute_END (0)
#define SOC_NPU_AICORE_SU_LSU_MPU_CTRL_out_mem_attribute_START (8)
#define SOC_NPU_AICORE_SU_LSU_MPU_CTRL_out_mem_attribute_END (8)
#define SOC_NPU_AICORE_SU_LSU_MPU_CTRL_stack_mem_attribute_START (16)
#define SOC_NPU_AICORE_SU_LSU_MPU_CTRL_stack_mem_attribute_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_stb_timeout_cnt : 10;
        unsigned int reserved : 21;
        unsigned int su_stb_timeout_en : 1;
    } reg;
} SOC_NPU_AICORE_SU_LSU_STB_CTRL_UNION;
#endif
#define SOC_NPU_AICORE_SU_LSU_STB_CTRL_su_stb_timeout_cnt_START (0)
#define SOC_NPU_AICORE_SU_LSU_STB_CTRL_su_stb_timeout_cnt_END (9)
#define SOC_NPU_AICORE_SU_LSU_STB_CTRL_su_stb_timeout_en_START (31)
#define SOC_NPU_AICORE_SU_LSU_STB_CTRL_su_stb_timeout_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_mte1_pld_pend_mask : 1;
        unsigned int su_mte2_pld_pend_mask : 1;
        unsigned int su_mte3_pld_pend_mask : 1;
        unsigned int su_vec_pld_pend_mask : 1;
        unsigned int su_cube_pld_pend_mask : 1;
        unsigned int su_fixp_pld_pend_mask : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_NPU_AICORE_SU_SEQ_CTRL_UNION;
#endif
#define SOC_NPU_AICORE_SU_SEQ_CTRL_su_mte1_pld_pend_mask_START (0)
#define SOC_NPU_AICORE_SU_SEQ_CTRL_su_mte1_pld_pend_mask_END (0)
#define SOC_NPU_AICORE_SU_SEQ_CTRL_su_mte2_pld_pend_mask_START (1)
#define SOC_NPU_AICORE_SU_SEQ_CTRL_su_mte2_pld_pend_mask_END (1)
#define SOC_NPU_AICORE_SU_SEQ_CTRL_su_mte3_pld_pend_mask_START (2)
#define SOC_NPU_AICORE_SU_SEQ_CTRL_su_mte3_pld_pend_mask_END (2)
#define SOC_NPU_AICORE_SU_SEQ_CTRL_su_vec_pld_pend_mask_START (3)
#define SOC_NPU_AICORE_SU_SEQ_CTRL_su_vec_pld_pend_mask_END (3)
#define SOC_NPU_AICORE_SU_SEQ_CTRL_su_cube_pld_pend_mask_START (4)
#define SOC_NPU_AICORE_SU_SEQ_CTRL_su_cube_pld_pend_mask_END (4)
#define SOC_NPU_AICORE_SU_SEQ_CTRL_su_fixp_pld_pend_mask_START (5)
#define SOC_NPU_AICORE_SU_SEQ_CTRL_su_fixp_pld_pend_mask_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_spr_status_l : 32;
    } reg;
} SOC_NPU_AICORE_SU_SPR_STATUS_L_UNION;
#endif
#define SOC_NPU_AICORE_SU_SPR_STATUS_L_su_spr_status_l_START (0)
#define SOC_NPU_AICORE_SU_SPR_STATUS_L_su_spr_status_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_spr_status_h : 32;
    } reg;
} SOC_NPU_AICORE_SU_SPR_STATUS_H_UNION;
#endif
#define SOC_NPU_AICORE_SU_SPR_STATUS_H_su_spr_status_h_START (0)
#define SOC_NPU_AICORE_SU_SPR_STATUS_H_su_spr_status_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_spr_condition_l : 32;
    } reg;
} SOC_NPU_AICORE_SU_SPR_CONDITION_L_UNION;
#endif
#define SOC_NPU_AICORE_SU_SPR_CONDITION_L_su_spr_condition_l_START (0)
#define SOC_NPU_AICORE_SU_SPR_CONDITION_L_su_spr_condition_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_spr_condition_h : 32;
    } reg;
} SOC_NPU_AICORE_SU_SPR_CONDITION_H_UNION;
#endif
#define SOC_NPU_AICORE_SU_SPR_CONDITION_H_su_spr_condition_h_START (0)
#define SOC_NPU_AICORE_SU_SPR_CONDITION_H_su_spr_condition_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_spr_arch_ver_l : 32;
    } reg;
} SOC_NPU_AICORE_SU_SPR_ARCH_VER_L_UNION;
#endif
#define SOC_NPU_AICORE_SU_SPR_ARCH_VER_L_su_spr_arch_ver_l_START (0)
#define SOC_NPU_AICORE_SU_SPR_ARCH_VER_L_su_spr_arch_ver_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_spr_arch_ver_h : 32;
    } reg;
} SOC_NPU_AICORE_SU_SPR_ARCH_VER_H_UNION;
#endif
#define SOC_NPU_AICORE_SU_SPR_ARCH_VER_H_su_spr_arch_ver_h_START (0)
#define SOC_NPU_AICORE_SU_SPR_ARCH_VER_H_su_spr_arch_ver_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_spr_coreid : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_AICORE_SU_SPR_COREID_UNION;
#endif
#define SOC_NPU_AICORE_SU_SPR_COREID_su_spr_coreid_START (0)
#define SOC_NPU_AICORE_SU_SPR_COREID_su_spr_coreid_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_core_model_id : 32;
    } reg;
} SOC_NPU_AICORE_SU_AIC_CORE_MODEL_ID_UNION;
#endif
#define SOC_NPU_AICORE_SU_AIC_CORE_MODEL_ID_aic_core_model_id_START (0)
#define SOC_NPU_AICORE_SU_AIC_CORE_MODEL_ID_aic_core_model_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_isa_ver_l : 32;
    } reg;
} SOC_NPU_AICORE_SU_AIC_ISA_VER_L_UNION;
#endif
#define SOC_NPU_AICORE_SU_AIC_ISA_VER_L_aic_isa_ver_l_START (0)
#define SOC_NPU_AICORE_SU_AIC_ISA_VER_L_aic_isa_ver_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_isa_ver_h : 32;
    } reg;
} SOC_NPU_AICORE_SU_AIC_ISA_VER_H_UNION;
#endif
#define SOC_NPU_AICORE_SU_AIC_ISA_VER_H_aic_isa_ver_h_START (0)
#define SOC_NPU_AICORE_SU_AIC_ISA_VER_H_aic_isa_ver_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_uarch_ver_l : 32;
    } reg;
} SOC_NPU_AICORE_SU_AIC_UARCH_VER_L_UNION;
#endif
#define SOC_NPU_AICORE_SU_AIC_UARCH_VER_L_aic_uarch_ver_l_START (0)
#define SOC_NPU_AICORE_SU_AIC_UARCH_VER_L_aic_uarch_ver_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_uarch_ver_h : 32;
    } reg;
} SOC_NPU_AICORE_SU_AIC_UARCH_VER_H_UNION;
#endif
#define SOC_NPU_AICORE_SU_AIC_UARCH_VER_H_aic_uarch_ver_h_START (0)
#define SOC_NPU_AICORE_SU_AIC_UARCH_VER_H_aic_uarch_ver_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_gen_hw_cfg_l : 32;
    } reg;
} SOC_NPU_AICORE_SU_AIC_GEN_HW_CFG_L_UNION;
#endif
#define SOC_NPU_AICORE_SU_AIC_GEN_HW_CFG_L_aic_gen_hw_cfg_l_START (0)
#define SOC_NPU_AICORE_SU_AIC_GEN_HW_CFG_L_aic_gen_hw_cfg_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_gen_hw_cfg_h : 32;
    } reg;
} SOC_NPU_AICORE_SU_AIC_GEN_HW_CFG_H_UNION;
#endif
#define SOC_NPU_AICORE_SU_AIC_GEN_HW_CFG_H_aic_gen_hw_cfg_h_START (0)
#define SOC_NPU_AICORE_SU_AIC_GEN_HW_CFG_H_aic_gen_hw_cfg_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_branch_ver_l : 32;
    } reg;
} SOC_NPU_AICORE_SU_AIC_BRANCH_VER_L_UNION;
#endif
#define SOC_NPU_AICORE_SU_AIC_BRANCH_VER_L_aic_branch_ver_l_START (0)
#define SOC_NPU_AICORE_SU_AIC_BRANCH_VER_L_aic_branch_ver_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_branch_ver_h : 32;
    } reg;
} SOC_NPU_AICORE_SU_AIC_BRANCH_VER_H_UNION;
#endif
#define SOC_NPU_AICORE_SU_AIC_BRANCH_VER_H_aic_branch_ver_h_START (0)
#define SOC_NPU_AICORE_SU_AIC_BRANCH_VER_H_aic_branch_ver_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 7;
        unsigned int su_ic_inv_va_l : 25;
    } reg;
} SOC_NPU_AICORE_SU_IC_INV_VA_L_UNION;
#endif
#define SOC_NPU_AICORE_SU_IC_INV_VA_L_su_ic_inv_va_l_START (7)
#define SOC_NPU_AICORE_SU_IC_INV_VA_L_su_ic_inv_va_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_ic_inv_va_h : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_AICORE_SU_IC_INV_VA_H_UNION;
#endif
#define SOC_NPU_AICORE_SU_IC_INV_VA_H_su_ic_inv_va_h_START (0)
#define SOC_NPU_AICORE_SU_IC_INV_VA_H_su_ic_inv_va_h_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int single_step_p : 1;
        unsigned int su_redirect_ifu : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_AICORE_SU_DBG_CTRL_UNION;
#endif
#define SOC_NPU_AICORE_SU_DBG_CTRL_single_step_p_START (0)
#define SOC_NPU_AICORE_SU_DBG_CTRL_single_step_p_END (0)
#define SOC_NPU_AICORE_SU_DBG_CTRL_su_redirect_ifu_START (1)
#define SOC_NPU_AICORE_SU_DBG_CTRL_su_redirect_ifu_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int single_step_done_int_mask : 1;
        unsigned int hw_break_point_hit_int_mask : 1;
        unsigned int sw_break_point_hit_int_mask : 1;
        unsigned int su_dbg_stall_int_mask : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_NPU_AICORE_SU_DBG_INT_MASK_UNION;
#endif
#define SOC_NPU_AICORE_SU_DBG_INT_MASK_single_step_done_int_mask_START (0)
#define SOC_NPU_AICORE_SU_DBG_INT_MASK_single_step_done_int_mask_END (0)
#define SOC_NPU_AICORE_SU_DBG_INT_MASK_hw_break_point_hit_int_mask_START (1)
#define SOC_NPU_AICORE_SU_DBG_INT_MASK_hw_break_point_hit_int_mask_END (1)
#define SOC_NPU_AICORE_SU_DBG_INT_MASK_sw_break_point_hit_int_mask_START (2)
#define SOC_NPU_AICORE_SU_DBG_INT_MASK_sw_break_point_hit_int_mask_END (2)
#define SOC_NPU_AICORE_SU_DBG_INT_MASK_su_dbg_stall_int_mask_START (3)
#define SOC_NPU_AICORE_SU_DBG_INT_MASK_su_dbg_stall_int_mask_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int single_step_done : 1;
        unsigned int hw_break_point_hit : 1;
        unsigned int sw_break_point_hit : 1;
        unsigned int su_dbg_stall_int : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_NPU_AICORE_SU_DBG_STATUS_UNION;
#endif
#define SOC_NPU_AICORE_SU_DBG_STATUS_single_step_done_START (0)
#define SOC_NPU_AICORE_SU_DBG_STATUS_single_step_done_END (0)
#define SOC_NPU_AICORE_SU_DBG_STATUS_hw_break_point_hit_START (1)
#define SOC_NPU_AICORE_SU_DBG_STATUS_hw_break_point_hit_END (1)
#define SOC_NPU_AICORE_SU_DBG_STATUS_sw_break_point_hit_START (2)
#define SOC_NPU_AICORE_SU_DBG_STATUS_sw_break_point_hit_END (2)
#define SOC_NPU_AICORE_SU_DBG_STATUS_su_dbg_stall_int_START (3)
#define SOC_NPU_AICORE_SU_DBG_STATUS_su_dbg_stall_int_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hw_bkpt_en : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_NPU_AICORE_SU_HW_BKPT_EN_UNION;
#endif
#define SOC_NPU_AICORE_SU_HW_BKPT_EN_hw_bkpt_en_START (0)
#define SOC_NPU_AICORE_SU_HW_BKPT_EN_hw_bkpt_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 2;
        unsigned int hw_bkpt0_pc_l : 30;
    } reg;
} SOC_NPU_AICORE_SU_HW_BKPT0_PC_L_UNION;
#endif
#define SOC_NPU_AICORE_SU_HW_BKPT0_PC_L_hw_bkpt0_pc_l_START (2)
#define SOC_NPU_AICORE_SU_HW_BKPT0_PC_L_hw_bkpt0_pc_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hw_bkpt0_pc_h : 16;
        unsigned int hw_bkpt0_id : 16;
    } reg;
} SOC_NPU_AICORE_SU_HW_BKPT0_PC_H_UNION;
#endif
#define SOC_NPU_AICORE_SU_HW_BKPT0_PC_H_hw_bkpt0_pc_h_START (0)
#define SOC_NPU_AICORE_SU_HW_BKPT0_PC_H_hw_bkpt0_pc_h_END (15)
#define SOC_NPU_AICORE_SU_HW_BKPT0_PC_H_hw_bkpt0_id_START (16)
#define SOC_NPU_AICORE_SU_HW_BKPT0_PC_H_hw_bkpt0_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 2;
        unsigned int hw_bkpt1_pc_l : 30;
    } reg;
} SOC_NPU_AICORE_SU_HW_BKPT1_PC_L_UNION;
#endif
#define SOC_NPU_AICORE_SU_HW_BKPT1_PC_L_hw_bkpt1_pc_l_START (2)
#define SOC_NPU_AICORE_SU_HW_BKPT1_PC_L_hw_bkpt1_pc_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hw_bkpt1_pc_h : 16;
        unsigned int hw_bkpt1_id : 16;
    } reg;
} SOC_NPU_AICORE_SU_HW_BKPT1_PC_H_UNION;
#endif
#define SOC_NPU_AICORE_SU_HW_BKPT1_PC_H_hw_bkpt1_pc_h_START (0)
#define SOC_NPU_AICORE_SU_HW_BKPT1_PC_H_hw_bkpt1_pc_h_END (15)
#define SOC_NPU_AICORE_SU_HW_BKPT1_PC_H_hw_bkpt1_id_START (16)
#define SOC_NPU_AICORE_SU_HW_BKPT1_PC_H_hw_bkpt1_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 2;
        unsigned int hw_bkpt2_pc_l : 30;
    } reg;
} SOC_NPU_AICORE_SU_HW_BKPT2_PC_L_UNION;
#endif
#define SOC_NPU_AICORE_SU_HW_BKPT2_PC_L_hw_bkpt2_pc_l_START (2)
#define SOC_NPU_AICORE_SU_HW_BKPT2_PC_L_hw_bkpt2_pc_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hw_bkpt2_pc_h : 16;
        unsigned int hw_bkpt2_id : 16;
    } reg;
} SOC_NPU_AICORE_SU_HW_BKPT2_PC_H_UNION;
#endif
#define SOC_NPU_AICORE_SU_HW_BKPT2_PC_H_hw_bkpt2_pc_h_START (0)
#define SOC_NPU_AICORE_SU_HW_BKPT2_PC_H_hw_bkpt2_pc_h_END (15)
#define SOC_NPU_AICORE_SU_HW_BKPT2_PC_H_hw_bkpt2_id_START (16)
#define SOC_NPU_AICORE_SU_HW_BKPT2_PC_H_hw_bkpt2_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 2;
        unsigned int hw_bkpt3_pc_l : 30;
    } reg;
} SOC_NPU_AICORE_SU_HW_BKPT3_PC_L_UNION;
#endif
#define SOC_NPU_AICORE_SU_HW_BKPT3_PC_L_hw_bkpt3_pc_l_START (2)
#define SOC_NPU_AICORE_SU_HW_BKPT3_PC_L_hw_bkpt3_pc_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hw_bkpt3_pc_h : 16;
        unsigned int hw_bkpt3_id : 16;
    } reg;
} SOC_NPU_AICORE_SU_HW_BKPT3_PC_H_UNION;
#endif
#define SOC_NPU_AICORE_SU_HW_BKPT3_PC_H_hw_bkpt3_pc_h_START (0)
#define SOC_NPU_AICORE_SU_HW_BKPT3_PC_H_hw_bkpt3_pc_h_END (15)
#define SOC_NPU_AICORE_SU_HW_BKPT3_PC_H_hw_bkpt3_id_START (16)
#define SOC_NPU_AICORE_SU_HW_BKPT3_PC_H_hw_bkpt3_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hw_bkpt0_id_2 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_AICORE_SU_HW_BKPT0_TWO_LEVLE_SMID_UNION;
#endif
#define SOC_NPU_AICORE_SU_HW_BKPT0_TWO_LEVLE_SMID_hw_bkpt0_id_2_START (0)
#define SOC_NPU_AICORE_SU_HW_BKPT0_TWO_LEVLE_SMID_hw_bkpt0_id_2_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hw_bkpt1_id_2 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_AICORE_SU_HW_BKPT1_TWO_LEVLE_SMID_UNION;
#endif
#define SOC_NPU_AICORE_SU_HW_BKPT1_TWO_LEVLE_SMID_hw_bkpt1_id_2_START (0)
#define SOC_NPU_AICORE_SU_HW_BKPT1_TWO_LEVLE_SMID_hw_bkpt1_id_2_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hw_bkpt2_id_2 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_AICORE_SU_HW_BKPT2_TWO_LEVLE_SMID_UNION;
#endif
#define SOC_NPU_AICORE_SU_HW_BKPT2_TWO_LEVLE_SMID_hw_bkpt2_id_2_START (0)
#define SOC_NPU_AICORE_SU_HW_BKPT2_TWO_LEVLE_SMID_hw_bkpt2_id_2_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hw_bkpt3_id_2 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_AICORE_SU_HW_BKPT3_TWO_LEVLE_SMID_UNION;
#endif
#define SOC_NPU_AICORE_SU_HW_BKPT3_TWO_LEVLE_SMID_hw_bkpt3_id_2_START (0)
#define SOC_NPU_AICORE_SU_HW_BKPT3_TWO_LEVLE_SMID_hw_bkpt3_id_2_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_pre_rst_stall : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_SU_PRE_RST_STALL_CTRL_UNION;
#endif
#define SOC_NPU_AICORE_SU_PRE_RST_STALL_CTRL_su_pre_rst_stall_START (0)
#define SOC_NPU_AICORE_SU_PRE_RST_STALL_CTRL_su_pre_rst_stall_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_pre_rst_rdy : 1;
        unsigned int su_ifu_pre_rst_rdy : 1;
        unsigned int su_lsu_pre_rst_rdy : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_NPU_AICORE_SU_PRE_RST_STATUS_UNION;
#endif
#define SOC_NPU_AICORE_SU_PRE_RST_STATUS_su_pre_rst_rdy_START (0)
#define SOC_NPU_AICORE_SU_PRE_RST_STATUS_su_pre_rst_rdy_END (0)
#define SOC_NPU_AICORE_SU_PRE_RST_STATUS_su_ifu_pre_rst_rdy_START (1)
#define SOC_NPU_AICORE_SU_PRE_RST_STATUS_su_ifu_pre_rst_rdy_END (1)
#define SOC_NPU_AICORE_SU_PRE_RST_STATUS_su_lsu_pre_rst_rdy_START (2)
#define SOC_NPU_AICORE_SU_PRE_RST_STATUS_su_lsu_pre_rst_rdy_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_mte2_mte3_busy : 1;
        unsigned int su_mte2_busy : 1;
        unsigned int su_mte3_busy : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_NPU_AICORE_SU_INNER_STATUS_UNION;
#endif
#define SOC_NPU_AICORE_SU_INNER_STATUS_su_mte2_mte3_busy_START (0)
#define SOC_NPU_AICORE_SU_INNER_STATUS_su_mte2_mte3_busy_END (0)
#define SOC_NPU_AICORE_SU_INNER_STATUS_su_mte2_busy_START (1)
#define SOC_NPU_AICORE_SU_INNER_STATUS_su_mte2_busy_END (1)
#define SOC_NPU_AICORE_SU_INNER_STATUS_su_mte3_busy_START (2)
#define SOC_NPU_AICORE_SU_INNER_STATUS_su_mte3_busy_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_ifu_bus_err_t0 : 1;
        unsigned int su_ccu_call_depth_ovrflw_t0 : 1;
        unsigned int su_ccu_div0_t0 : 1;
        unsigned int su_ccu_illegal_instr_t0 : 1;
        unsigned int su_ccu_neg_sqrt_t0 : 1;
        unsigned int su_ccu_ub_ecc_t0 : 1;
        unsigned int su_ccu_inf_nan_t0 : 1;
        unsigned int su_ccu_addr_err_t0 : 1;
        unsigned int su_ccu_bus_err_t0 : 1;
        unsigned int su_ccu_dc_data_ecc_t0 : 1;
        unsigned int su_ccu_dc_tag_ecc_t0 : 1;
        unsigned int su_ccu_div0_fp_t0 : 1;
        unsigned int su_ccu_neg_sqrt_fp_t0 : 1;
        unsigned int su_ccu_err_parity_err_t0 : 1;
        unsigned int su_ccu_seq_err_t0 : 1;
        unsigned int su_ccu_mpu_err_t0 : 1;
        unsigned int su_ccu_lsu_err_t0 : 1;
        unsigned int su_ccu_pb_ecc_err_t0 : 1;
        unsigned int su_ccu_safety_crc_err_t0 : 1;
        unsigned int su_ccu_lsu_atomic_err_t0 : 1;
        unsigned int su_ccu_cc_set_ovfl_err_t0 : 1;
        unsigned int su_safety_1bit_ecc_ovflw_err_t0 : 1;
        unsigned int reserved : 8;
        unsigned int su_hit_trap_err_t0 : 1;
        unsigned int warn_as_exception_t0 : 1;
    } reg;
} SOC_NPU_AICORE_SU_ERROR_T0_0_UNION;
#endif
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ifu_bus_err_t0_START (0)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ifu_bus_err_t0_END (0)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_call_depth_ovrflw_t0_START (1)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_call_depth_ovrflw_t0_END (1)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_div0_t0_START (2)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_div0_t0_END (2)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_illegal_instr_t0_START (3)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_illegal_instr_t0_END (3)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_neg_sqrt_t0_START (4)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_neg_sqrt_t0_END (4)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_ub_ecc_t0_START (5)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_ub_ecc_t0_END (5)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_inf_nan_t0_START (6)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_inf_nan_t0_END (6)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_addr_err_t0_START (7)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_addr_err_t0_END (7)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_bus_err_t0_START (8)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_bus_err_t0_END (8)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_dc_data_ecc_t0_START (9)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_dc_data_ecc_t0_END (9)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_dc_tag_ecc_t0_START (10)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_dc_tag_ecc_t0_END (10)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_div0_fp_t0_START (11)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_div0_fp_t0_END (11)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_neg_sqrt_fp_t0_START (12)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_neg_sqrt_fp_t0_END (12)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_err_parity_err_t0_START (13)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_err_parity_err_t0_END (13)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_seq_err_t0_START (14)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_seq_err_t0_END (14)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_mpu_err_t0_START (15)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_mpu_err_t0_END (15)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_lsu_err_t0_START (16)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_lsu_err_t0_END (16)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_pb_ecc_err_t0_START (17)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_pb_ecc_err_t0_END (17)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_safety_crc_err_t0_START (18)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_safety_crc_err_t0_END (18)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_lsu_atomic_err_t0_START (19)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_lsu_atomic_err_t0_END (19)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_cc_set_ovfl_err_t0_START (20)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_ccu_cc_set_ovfl_err_t0_END (20)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_safety_1bit_ecc_ovflw_err_t0_START (21)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_safety_1bit_ecc_ovflw_err_t0_END (21)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_hit_trap_err_t0_START (30)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_su_hit_trap_err_t0_END (30)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_warn_as_exception_t0_START (31)
#define SOC_NPU_AICORE_SU_ERROR_T0_0_warn_as_exception_t0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_SU_ERROR_T1_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_ifu_bus_err_mask : 1;
        unsigned int su_ccu_call_depth_ovrflw_mask : 1;
        unsigned int su_ccu_div0_mask : 1;
        unsigned int su_ccu_illegal_instr_mask : 1;
        unsigned int su_ccu_neg_sqrt_mask : 1;
        unsigned int su_ccu_ub_ecc_mask : 1;
        unsigned int su_ccu_inf_nan_mask : 1;
        unsigned int su_ccu_addr_err_mask : 1;
        unsigned int su_ccu_bus_err_mask : 1;
        unsigned int su_ccu_dc_data_ecc_mask : 1;
        unsigned int su_ccu_dc_tag_ecc_mask : 1;
        unsigned int su_ccu_div0_fp_mask : 1;
        unsigned int su_ccu_neg_sqrt_fp_mask : 1;
        unsigned int su_ccu_err_parity_err_mask : 1;
        unsigned int su_ccu_seq_err_mask : 1;
        unsigned int su_ccu_mpu_err_mask : 1;
        unsigned int su_ccu_lsu_err_mask : 1;
        unsigned int su_ccu_pb_ecc_err_mask : 1;
        unsigned int su_ccu_safety_crc_err_mask : 1;
        unsigned int su_ccu_lsu_atomic_err_mask : 1;
        unsigned int su_ccu_cc_set_ovfl_err_mask : 1;
        unsigned int su_safety_1bit_ecc_ovflw_err_mask : 1;
        unsigned int reserved : 8;
        unsigned int su_hit_trap_err_mask : 1;
        unsigned int warn_as_exception_mask : 1;
    } reg;
} SOC_NPU_AICORE_SU_ERROR_MASK_0_UNION;
#endif
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ifu_bus_err_mask_START (0)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ifu_bus_err_mask_END (0)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_call_depth_ovrflw_mask_START (1)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_call_depth_ovrflw_mask_END (1)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_div0_mask_START (2)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_div0_mask_END (2)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_illegal_instr_mask_START (3)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_illegal_instr_mask_END (3)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_neg_sqrt_mask_START (4)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_neg_sqrt_mask_END (4)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_ub_ecc_mask_START (5)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_ub_ecc_mask_END (5)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_inf_nan_mask_START (6)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_inf_nan_mask_END (6)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_addr_err_mask_START (7)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_addr_err_mask_END (7)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_bus_err_mask_START (8)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_bus_err_mask_END (8)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_dc_data_ecc_mask_START (9)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_dc_data_ecc_mask_END (9)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_dc_tag_ecc_mask_START (10)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_dc_tag_ecc_mask_END (10)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_div0_fp_mask_START (11)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_div0_fp_mask_END (11)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_neg_sqrt_fp_mask_START (12)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_neg_sqrt_fp_mask_END (12)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_err_parity_err_mask_START (13)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_err_parity_err_mask_END (13)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_seq_err_mask_START (14)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_seq_err_mask_END (14)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_mpu_err_mask_START (15)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_mpu_err_mask_END (15)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_lsu_err_mask_START (16)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_lsu_err_mask_END (16)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_pb_ecc_err_mask_START (17)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_pb_ecc_err_mask_END (17)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_safety_crc_err_mask_START (18)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_safety_crc_err_mask_END (18)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_lsu_atomic_err_mask_START (19)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_lsu_atomic_err_mask_END (19)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_cc_set_ovfl_err_mask_START (20)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_ccu_cc_set_ovfl_err_mask_END (20)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_safety_1bit_ecc_ovflw_err_mask_START (21)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_safety_1bit_ecc_ovflw_err_mask_END (21)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_hit_trap_err_mask_START (30)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_su_hit_trap_err_mask_END (30)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_warn_as_exception_mask_START (31)
#define SOC_NPU_AICORE_SU_ERROR_MASK_0_warn_as_exception_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_err_pc_t0 : 16;
        unsigned int reserved : 1;
        unsigned int su_err_addr_t0 : 15;
    } reg;
} SOC_NPU_AICORE_SU_ERR_INFO_T0_0_UNION;
#endif
#define SOC_NPU_AICORE_SU_ERR_INFO_T0_0_su_err_pc_t0_START (0)
#define SOC_NPU_AICORE_SU_ERR_INFO_T0_0_su_err_pc_t0_END (15)
#define SOC_NPU_AICORE_SU_ERR_INFO_T0_0_su_err_addr_t0_START (17)
#define SOC_NPU_AICORE_SU_ERR_INFO_T0_0_su_err_addr_t0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_bus_err_addr_l_t0 : 32;
    } reg;
} SOC_NPU_AICORE_SU_ERR_INFO_T0_1_UNION;
#endif
#define SOC_NPU_AICORE_SU_ERR_INFO_T0_1_su_bus_err_addr_l_t0_START (0)
#define SOC_NPU_AICORE_SU_ERR_INFO_T0_1_su_bus_err_addr_l_t0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_bus_err_addr_h_t0 : 16;
        unsigned int reserved : 11;
        unsigned int su_bus_err_type_t0 : 5;
    } reg;
} SOC_NPU_AICORE_SU_ERR_INFO_T0_2_UNION;
#endif
#define SOC_NPU_AICORE_SU_ERR_INFO_T0_2_su_bus_err_addr_h_t0_START (0)
#define SOC_NPU_AICORE_SU_ERR_INFO_T0_2_su_bus_err_addr_h_t0_END (15)
#define SOC_NPU_AICORE_SU_ERR_INFO_T0_2_su_bus_err_type_t0_START (27)
#define SOC_NPU_AICORE_SU_ERR_INFO_T0_2_su_bus_err_type_t0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_err_instr_t0 : 32;
    } reg;
} SOC_NPU_AICORE_SU_ERR_INFO_T0_3_UNION;
#endif
#define SOC_NPU_AICORE_SU_ERR_INFO_T0_3_su_err_instr_t0_START (0)
#define SOC_NPU_AICORE_SU_ERR_INFO_T0_3_su_err_instr_t0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_SU_ERR_INFO_T1_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_SU_ERR_INFO_T1_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_SU_ERR_INFO_T1_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_SU_ERR_INFO_T1_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_warn_int_ovfl_t0 : 1;
        unsigned int su_warn_fp_ovfl_t0 : 1;
        unsigned int su_warn_fp_undfl_t0 : 1;
        unsigned int su_warn_scalar_nan_inf_t0 : 1;
        unsigned int su_warn_scalar_sqrt_neg_t0 : 1;
        unsigned int su_warn_scalar_div0_t0 : 1;
        unsigned int su_warn_atomic_ovfl_t0 : 1;
        unsigned int su_warn_atomic_inf_t0 : 1;
        unsigned int su_warn_atomic_src_nan_t0 : 1;
        unsigned int su_warn_atomic_des_nan_t0 : 1;
        unsigned int su_warn_atomic_nan_both_t0 : 1;
        unsigned int su_warn_atomic_int_ovfl_t0 : 1;
        unsigned int su_warn_atomic_equal_err_t0 : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_NPU_AICORE_SU_WARN_T0_0_UNION;
#endif
#define SOC_NPU_AICORE_SU_WARN_T0_0_su_warn_int_ovfl_t0_START (0)
#define SOC_NPU_AICORE_SU_WARN_T0_0_su_warn_int_ovfl_t0_END (0)
#define SOC_NPU_AICORE_SU_WARN_T0_0_su_warn_fp_ovfl_t0_START (1)
#define SOC_NPU_AICORE_SU_WARN_T0_0_su_warn_fp_ovfl_t0_END (1)
#define SOC_NPU_AICORE_SU_WARN_T0_0_su_warn_fp_undfl_t0_START (2)
#define SOC_NPU_AICORE_SU_WARN_T0_0_su_warn_fp_undfl_t0_END (2)
#define SOC_NPU_AICORE_SU_WARN_T0_0_su_warn_scalar_nan_inf_t0_START (3)
#define SOC_NPU_AICORE_SU_WARN_T0_0_su_warn_scalar_nan_inf_t0_END (3)
#define SOC_NPU_AICORE_SU_WARN_T0_0_su_warn_scalar_sqrt_neg_t0_START (4)
#define SOC_NPU_AICORE_SU_WARN_T0_0_su_warn_scalar_sqrt_neg_t0_END (4)
#define SOC_NPU_AICORE_SU_WARN_T0_0_su_warn_scalar_div0_t0_START (5)
#define SOC_NPU_AICORE_SU_WARN_T0_0_su_warn_scalar_div0_t0_END (5)
#define SOC_NPU_AICORE_SU_WARN_T0_0_su_warn_atomic_ovfl_t0_START (6)
#define SOC_NPU_AICORE_SU_WARN_T0_0_su_warn_atomic_ovfl_t0_END (6)
#define SOC_NPU_AICORE_SU_WARN_T0_0_su_warn_atomic_inf_t0_START (7)
#define SOC_NPU_AICORE_SU_WARN_T0_0_su_warn_atomic_inf_t0_END (7)
#define SOC_NPU_AICORE_SU_WARN_T0_0_su_warn_atomic_src_nan_t0_START (8)
#define SOC_NPU_AICORE_SU_WARN_T0_0_su_warn_atomic_src_nan_t0_END (8)
#define SOC_NPU_AICORE_SU_WARN_T0_0_su_warn_atomic_des_nan_t0_START (9)
#define SOC_NPU_AICORE_SU_WARN_T0_0_su_warn_atomic_des_nan_t0_END (9)
#define SOC_NPU_AICORE_SU_WARN_T0_0_su_warn_atomic_nan_both_t0_START (10)
#define SOC_NPU_AICORE_SU_WARN_T0_0_su_warn_atomic_nan_both_t0_END (10)
#define SOC_NPU_AICORE_SU_WARN_T0_0_su_warn_atomic_int_ovfl_t0_START (11)
#define SOC_NPU_AICORE_SU_WARN_T0_0_su_warn_atomic_int_ovfl_t0_END (11)
#define SOC_NPU_AICORE_SU_WARN_T0_0_su_warn_atomic_equal_err_t0_START (12)
#define SOC_NPU_AICORE_SU_WARN_T0_0_su_warn_atomic_equal_err_t0_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_SU_WARN_T1_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_warn_int_ovfl_mask : 1;
        unsigned int su_warn_fp_ovfl_mask : 1;
        unsigned int su_warn_fp_undfl_mask : 1;
        unsigned int su_warn_scalar_nan_inf_mask : 1;
        unsigned int su_warn_scalar_sqrt_neg_mask : 1;
        unsigned int su_warn_scalar_div0_mask : 1;
        unsigned int su_warn_atomic_ovfl_mask : 1;
        unsigned int su_warn_atomic_inf_mask : 1;
        unsigned int su_warn_atomic_src_nan_mask : 1;
        unsigned int su_warn_atomic_des_nan_mask : 1;
        unsigned int su_warn_atomic_nan_both_mask : 1;
        unsigned int su_warn_atomic_int_ovfl_mask : 1;
        unsigned int su_warn_atomic_equal_err_mask : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_NPU_AICORE_SU_WARN_MASK_0_UNION;
#endif
#define SOC_NPU_AICORE_SU_WARN_MASK_0_su_warn_int_ovfl_mask_START (0)
#define SOC_NPU_AICORE_SU_WARN_MASK_0_su_warn_int_ovfl_mask_END (0)
#define SOC_NPU_AICORE_SU_WARN_MASK_0_su_warn_fp_ovfl_mask_START (1)
#define SOC_NPU_AICORE_SU_WARN_MASK_0_su_warn_fp_ovfl_mask_END (1)
#define SOC_NPU_AICORE_SU_WARN_MASK_0_su_warn_fp_undfl_mask_START (2)
#define SOC_NPU_AICORE_SU_WARN_MASK_0_su_warn_fp_undfl_mask_END (2)
#define SOC_NPU_AICORE_SU_WARN_MASK_0_su_warn_scalar_nan_inf_mask_START (3)
#define SOC_NPU_AICORE_SU_WARN_MASK_0_su_warn_scalar_nan_inf_mask_END (3)
#define SOC_NPU_AICORE_SU_WARN_MASK_0_su_warn_scalar_sqrt_neg_mask_START (4)
#define SOC_NPU_AICORE_SU_WARN_MASK_0_su_warn_scalar_sqrt_neg_mask_END (4)
#define SOC_NPU_AICORE_SU_WARN_MASK_0_su_warn_scalar_div0_mask_START (5)
#define SOC_NPU_AICORE_SU_WARN_MASK_0_su_warn_scalar_div0_mask_END (5)
#define SOC_NPU_AICORE_SU_WARN_MASK_0_su_warn_atomic_ovfl_mask_START (6)
#define SOC_NPU_AICORE_SU_WARN_MASK_0_su_warn_atomic_ovfl_mask_END (6)
#define SOC_NPU_AICORE_SU_WARN_MASK_0_su_warn_atomic_inf_mask_START (7)
#define SOC_NPU_AICORE_SU_WARN_MASK_0_su_warn_atomic_inf_mask_END (7)
#define SOC_NPU_AICORE_SU_WARN_MASK_0_su_warn_atomic_src_nan_mask_START (8)
#define SOC_NPU_AICORE_SU_WARN_MASK_0_su_warn_atomic_src_nan_mask_END (8)
#define SOC_NPU_AICORE_SU_WARN_MASK_0_su_warn_atomic_des_nan_mask_START (9)
#define SOC_NPU_AICORE_SU_WARN_MASK_0_su_warn_atomic_des_nan_mask_END (9)
#define SOC_NPU_AICORE_SU_WARN_MASK_0_su_warn_atomic_nan_both_mask_START (10)
#define SOC_NPU_AICORE_SU_WARN_MASK_0_su_warn_atomic_nan_both_mask_END (10)
#define SOC_NPU_AICORE_SU_WARN_MASK_0_su_warn_atomic_int_ovfl_mask_START (11)
#define SOC_NPU_AICORE_SU_WARN_MASK_0_su_warn_atomic_int_ovfl_mask_END (11)
#define SOC_NPU_AICORE_SU_WARN_MASK_0_su_warn_atomic_equal_err_mask_START (12)
#define SOC_NPU_AICORE_SU_WARN_MASK_0_su_warn_atomic_equal_err_mask_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_warn_pb_ecc_1bit_addr : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_AICORE_SU_1BIT_ECC_ERR_PB_ADDR_UNION;
#endif
#define SOC_NPU_AICORE_SU_1BIT_ECC_ERR_PB_ADDR_su_warn_pb_ecc_1bit_addr_START (0)
#define SOC_NPU_AICORE_SU_1BIT_ECC_ERR_PB_ADDR_su_warn_pb_ecc_1bit_addr_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_warn_dc_tag_ecc_1bit_addr : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_NPU_AICORE_SU_1BIT_ECC_ERR_DTAG_ADDR_UNION;
#endif
#define SOC_NPU_AICORE_SU_1BIT_ECC_ERR_DTAG_ADDR_su_warn_dc_tag_ecc_1bit_addr_START (0)
#define SOC_NPU_AICORE_SU_1BIT_ECC_ERR_DTAG_ADDR_su_warn_dc_tag_ecc_1bit_addr_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_warn_dc_data_ecc_1bit_addr : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_NPU_AICORE_SU_1BIT_ECC_ERR_DDAT_ADDR_UNION;
#endif
#define SOC_NPU_AICORE_SU_1BIT_ECC_ERR_DDAT_ADDR_su_warn_dc_data_ecc_1bit_addr_START (0)
#define SOC_NPU_AICORE_SU_1BIT_ECC_ERR_DDAT_ADDR_su_warn_dc_data_ecc_1bit_addr_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spr_status_dfx_l : 32;
    } reg;
} SOC_NPU_AICORE_SU_SPR_STATUS_DFX_L_UNION;
#endif
#define SOC_NPU_AICORE_SU_SPR_STATUS_DFX_L_spr_status_dfx_l_START (0)
#define SOC_NPU_AICORE_SU_SPR_STATUS_DFX_L_spr_status_dfx_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spr_status_dfx_h : 32;
    } reg;
} SOC_NPU_AICORE_SU_SPR_STATUS_DFX_H_UNION;
#endif
#define SOC_NPU_AICORE_SU_SPR_STATUS_DFX_H_spr_status_dfx_h_START (0)
#define SOC_NPU_AICORE_SU_SPR_STATUS_DFX_H_spr_status_dfx_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ecc_1bit_err_num : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_AICORE_SU_SAFETY_1BIT_ECC_ERR_NUM_UNION;
#endif
#define SOC_NPU_AICORE_SU_SAFETY_1BIT_ECC_ERR_NUM_ecc_1bit_err_num_START (0)
#define SOC_NPU_AICORE_SU_SAFETY_1BIT_ECC_ERR_NUM_ecc_1bit_err_num_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_1bit_ecc_multi_hit_cnt : 32;
    } reg;
} SOC_NPU_AICORE_SU_1BIT_ECC_MHIT_CNT_REG_UNION;
#endif
#define SOC_NPU_AICORE_SU_1BIT_ECC_MHIT_CNT_REG_aic_1bit_ecc_multi_hit_cnt_START (0)
#define SOC_NPU_AICORE_SU_1BIT_ECC_MHIT_CNT_REG_aic_1bit_ecc_multi_hit_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ecc_1bit_err_th : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_AICORE_SU_SAFETY_1BIT_ECC_ERR_TH_UNION;
#endif
#define SOC_NPU_AICORE_SU_SAFETY_1BIT_ECC_ERR_TH_ecc_1bit_err_th_START (0)
#define SOC_NPU_AICORE_SU_SAFETY_1BIT_ECC_ERR_TH_ecc_1bit_err_th_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 2;
        unsigned int su_task_start_pc_l : 30;
    } reg;
} SOC_NPU_AICORE_SU_TASK_START_PC_L_UNION;
#endif
#define SOC_NPU_AICORE_SU_TASK_START_PC_L_su_task_start_pc_l_START (2)
#define SOC_NPU_AICORE_SU_TASK_START_PC_L_su_task_start_pc_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_task_start_pc_h : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_AICORE_SU_TASK_START_PC_H_UNION;
#endif
#define SOC_NPU_AICORE_SU_TASK_START_PC_H_su_task_start_pc_h_START (0)
#define SOC_NPU_AICORE_SU_TASK_START_PC_H_su_task_start_pc_h_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_reserved_ro_reg0 : 32;
    } reg;
} SOC_NPU_AICORE_SU_RESERVED_RO_REG0_UNION;
#endif
#define SOC_NPU_AICORE_SU_RESERVED_RO_REG0_su_reserved_ro_reg0_START (0)
#define SOC_NPU_AICORE_SU_RESERVED_RO_REG0_su_reserved_ro_reg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_reserved_ro_reg1 : 32;
    } reg;
} SOC_NPU_AICORE_SU_RESERVED_RO_REG1_UNION;
#endif
#define SOC_NPU_AICORE_SU_RESERVED_RO_REG1_su_reserved_ro_reg1_START (0)
#define SOC_NPU_AICORE_SU_RESERVED_RO_REG1_su_reserved_ro_reg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_reserved_rw_reg0 : 32;
    } reg;
} SOC_NPU_AICORE_SU_RESERVED_RW_REG0_UNION;
#endif
#define SOC_NPU_AICORE_SU_RESERVED_RW_REG0_su_reserved_rw_reg0_START (0)
#define SOC_NPU_AICORE_SU_RESERVED_RW_REG0_su_reserved_rw_reg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int su_reserved_rw_reg1 : 32;
    } reg;
} SOC_NPU_AICORE_SU_RESERVED_RW_REG1_UNION;
#endif
#define SOC_NPU_AICORE_SU_RESERVED_RW_REG1_su_reserved_rw_reg1_START (0)
#define SOC_NPU_AICORE_SU_RESERVED_RW_REG1_su_reserved_rw_reg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk_mte_en_mask_0 : 32;
    } reg;
} SOC_NPU_AICORE_MTE_CLK_GATE_MASK_0_UNION;
#endif
#define SOC_NPU_AICORE_MTE_CLK_GATE_MASK_0_clk_mte_en_mask_0_START (0)
#define SOC_NPU_AICORE_MTE_CLK_GATE_MASK_0_clk_mte_en_mask_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk_mte_en_mask_1 : 32;
    } reg;
} SOC_NPU_AICORE_MTE_CLK_GATE_MASK_1_UNION;
#endif
#define SOC_NPU_AICORE_MTE_CLK_GATE_MASK_1_clk_mte_en_mask_1_START (0)
#define SOC_NPU_AICORE_MTE_CLK_GATE_MASK_1_clk_mte_en_mask_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_nddma_cache_ecc_en_n : 1;
        unsigned int mte_nddma_req_buf_ecc_en_n : 1;
        unsigned int mte_aipp_ecc_en_n : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_NPU_AICORE_MTE_ECC_CTRL_0_UNION;
#endif
#define SOC_NPU_AICORE_MTE_ECC_CTRL_0_mte_nddma_cache_ecc_en_n_START (0)
#define SOC_NPU_AICORE_MTE_ECC_CTRL_0_mte_nddma_cache_ecc_en_n_END (0)
#define SOC_NPU_AICORE_MTE_ECC_CTRL_0_mte_nddma_req_buf_ecc_en_n_START (1)
#define SOC_NPU_AICORE_MTE_ECC_CTRL_0_mte_nddma_req_buf_ecc_en_n_END (1)
#define SOC_NPU_AICORE_MTE_ECC_CTRL_0_mte_aipp_ecc_en_n_START (2)
#define SOC_NPU_AICORE_MTE_ECC_CTRL_0_mte_aipp_ecc_en_n_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_nddma_cache_ecc_sb_inject : 1;
        unsigned int mte_nddma_cache_ecc_mb_inject : 1;
        unsigned int mte_nddma_req_buf_ecc_sb_inject : 1;
        unsigned int mte_nddma_req_buf_ecc_mb_inject : 1;
        unsigned int mte_aipp_ecc_sb_inject : 1;
        unsigned int mte_aipp_ecc_mb_inject : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_NPU_AICORE_MTE_ECC_INJECT_CTRL_0_UNION;
#endif
#define SOC_NPU_AICORE_MTE_ECC_INJECT_CTRL_0_mte_nddma_cache_ecc_sb_inject_START (0)
#define SOC_NPU_AICORE_MTE_ECC_INJECT_CTRL_0_mte_nddma_cache_ecc_sb_inject_END (0)
#define SOC_NPU_AICORE_MTE_ECC_INJECT_CTRL_0_mte_nddma_cache_ecc_mb_inject_START (1)
#define SOC_NPU_AICORE_MTE_ECC_INJECT_CTRL_0_mte_nddma_cache_ecc_mb_inject_END (1)
#define SOC_NPU_AICORE_MTE_ECC_INJECT_CTRL_0_mte_nddma_req_buf_ecc_sb_inject_START (2)
#define SOC_NPU_AICORE_MTE_ECC_INJECT_CTRL_0_mte_nddma_req_buf_ecc_sb_inject_END (2)
#define SOC_NPU_AICORE_MTE_ECC_INJECT_CTRL_0_mte_nddma_req_buf_ecc_mb_inject_START (3)
#define SOC_NPU_AICORE_MTE_ECC_INJECT_CTRL_0_mte_nddma_req_buf_ecc_mb_inject_END (3)
#define SOC_NPU_AICORE_MTE_ECC_INJECT_CTRL_0_mte_aipp_ecc_sb_inject_START (4)
#define SOC_NPU_AICORE_MTE_ECC_INJECT_CTRL_0_mte_aipp_ecc_sb_inject_END (4)
#define SOC_NPU_AICORE_MTE_ECC_INJECT_CTRL_0_mte_aipp_ecc_mb_inject_START (5)
#define SOC_NPU_AICORE_MTE_ECC_INJECT_CTRL_0_mte_aipp_ecc_mb_inject_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_fault_inj_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_MTE_FAULT_INJ_EN_UNION;
#endif
#define SOC_NPU_AICORE_MTE_FAULT_INJ_EN_mte_fault_inj_en_START (0)
#define SOC_NPU_AICORE_MTE_FAULT_INJ_EN_mte_fault_inj_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_fault_inj_mask : 32;
    } reg;
} SOC_NPU_AICORE_MTE_FAULT_INJ_MASK_UNION;
#endif
#define SOC_NPU_AICORE_MTE_FAULT_INJ_MASK_mte_fault_inj_mask_START (0)
#define SOC_NPU_AICORE_MTE_FAULT_INJ_MASK_mte_fault_inj_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_pre_rst_stall : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_MTE_PRE_RST_STALL_CTRL_UNION;
#endif
#define SOC_NPU_AICORE_MTE_PRE_RST_STALL_CTRL_mte_pre_rst_stall_START (0)
#define SOC_NPU_AICORE_MTE_PRE_RST_STALL_CTRL_mte_pre_rst_stall_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_pre_rst_rdy : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_MTE_PRE_RST_STATUS_UNION;
#endif
#define SOC_NPU_AICORE_MTE_PRE_RST_STATUS_mte_pre_rst_rdy_START (0)
#define SOC_NPU_AICORE_MTE_PRE_RST_STATUS_mte_pre_rst_rdy_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_nddma_cache_ecc_t0 : 1;
        unsigned int mte_nddma_req_buf_ecc_t0 : 1;
        unsigned int mte_l1_ecc_t0 : 1;
        unsigned int mte_cfg_reg_parity_t0 : 1;
        unsigned int mte_l0a_rdwr_cflt_t0 : 1;
        unsigned int mte_l0b_rdwr_cflt_t0 : 1;
        unsigned int mte_timeout_t0 : 1;
        unsigned int mte_ub_rd_cflt_t0 : 1;
        unsigned int mte_ub_wr_cflt_t0 : 1;
        unsigned int mte_read_overflow_t0 : 1;
        unsigned int mte_write_overflow_t0 : 1;
        unsigned int mte_err_fifo_parity_t0 : 1;
        unsigned int mte_ub_wr_ovflw_t0 : 1;
        unsigned int mte_ub_rd_ovflw_t0 : 1;
        unsigned int mte_instr_illegal_cfg_t0 : 1;
        unsigned int mte_atm_add_addr_misalign_t0 : 1;
        unsigned int mte_instr_addr_misalign_t0 : 1;
        unsigned int mte_gdma_read_overflow_t0 : 1;
        unsigned int mte_gdma_write_overflow_t0 : 1;
        unsigned int mte_gdma_illegal_burst_num_t0 : 1;
        unsigned int mte_gdma_illegal_burst_len_t0 : 1;
        unsigned int mte_aipp_illegal_param_t0 : 1;
        unsigned int mte_err_unzip_t0 : 1;
        unsigned int mte_err_hebcd_t0 : 1;
        unsigned int mte_err_hebce_t0 : 1;
        unsigned int mte_err_waipp_t0 : 1;
        unsigned int mte_stb_ecc_t0 : 1;
        unsigned int mte_aipp_ecc_t0 : 1;
        unsigned int mte_tagmgr_buf_ecc_t0 : 1;
        unsigned int mte_ub_ecc_t0 : 1;
        unsigned int mte_rob_ecc_t0 : 1;
        unsigned int mte_biu_rdwr_resp_t0 : 1;
    } reg;
} SOC_NPU_AICORE_MTE_ERROR_T0_0_UNION;
#endif
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_nddma_cache_ecc_t0_START (0)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_nddma_cache_ecc_t0_END (0)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_nddma_req_buf_ecc_t0_START (1)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_nddma_req_buf_ecc_t0_END (1)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_l1_ecc_t0_START (2)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_l1_ecc_t0_END (2)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_cfg_reg_parity_t0_START (3)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_cfg_reg_parity_t0_END (3)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_l0a_rdwr_cflt_t0_START (4)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_l0a_rdwr_cflt_t0_END (4)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_l0b_rdwr_cflt_t0_START (5)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_l0b_rdwr_cflt_t0_END (5)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_timeout_t0_START (6)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_timeout_t0_END (6)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_ub_rd_cflt_t0_START (7)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_ub_rd_cflt_t0_END (7)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_ub_wr_cflt_t0_START (8)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_ub_wr_cflt_t0_END (8)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_read_overflow_t0_START (9)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_read_overflow_t0_END (9)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_write_overflow_t0_START (10)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_write_overflow_t0_END (10)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_err_fifo_parity_t0_START (11)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_err_fifo_parity_t0_END (11)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_ub_wr_ovflw_t0_START (12)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_ub_wr_ovflw_t0_END (12)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_ub_rd_ovflw_t0_START (13)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_ub_rd_ovflw_t0_END (13)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_instr_illegal_cfg_t0_START (14)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_instr_illegal_cfg_t0_END (14)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_atm_add_addr_misalign_t0_START (15)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_atm_add_addr_misalign_t0_END (15)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_instr_addr_misalign_t0_START (16)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_instr_addr_misalign_t0_END (16)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_gdma_read_overflow_t0_START (17)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_gdma_read_overflow_t0_END (17)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_gdma_write_overflow_t0_START (18)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_gdma_write_overflow_t0_END (18)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_gdma_illegal_burst_num_t0_START (19)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_gdma_illegal_burst_num_t0_END (19)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_gdma_illegal_burst_len_t0_START (20)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_gdma_illegal_burst_len_t0_END (20)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_aipp_illegal_param_t0_START (21)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_aipp_illegal_param_t0_END (21)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_err_unzip_t0_START (22)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_err_unzip_t0_END (22)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_err_hebcd_t0_START (23)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_err_hebcd_t0_END (23)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_err_hebce_t0_START (24)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_err_hebce_t0_END (24)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_err_waipp_t0_START (25)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_err_waipp_t0_END (25)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_stb_ecc_t0_START (26)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_stb_ecc_t0_END (26)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_aipp_ecc_t0_START (27)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_aipp_ecc_t0_END (27)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_tagmgr_buf_ecc_t0_START (28)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_tagmgr_buf_ecc_t0_END (28)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_ub_ecc_t0_START (29)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_ub_ecc_t0_END (29)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_rob_ecc_t0_START (30)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_rob_ecc_t0_END (30)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_biu_rdwr_resp_t0_START (31)
#define SOC_NPU_AICORE_MTE_ERROR_T0_0_mte_biu_rdwr_resp_t0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_MTE_ERROR_T0_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_nddma_cache_ecc_t1 : 1;
        unsigned int mte_nddma_req_buf_ecc_t1 : 1;
        unsigned int mte_l1_ecc_t1 : 1;
        unsigned int mte_cfg_reg_parity_t1 : 1;
        unsigned int mte_l0a_rdwr_cflt_t1 : 1;
        unsigned int mte_l0b_rdwr_cflt_t1 : 1;
        unsigned int mte_timeout_t1 : 1;
        unsigned int mte_ub_rd_cflt_t1 : 1;
        unsigned int mte_ub_wr_cflt_t1 : 1;
        unsigned int mte_read_overflow_t1 : 1;
        unsigned int mte_write_overflow_t1 : 1;
        unsigned int mte_err_fifo_parity_t1 : 1;
        unsigned int mte_ub_wr_ovflw_t1 : 1;
        unsigned int mte_ub_rd_ovflw_t1 : 1;
        unsigned int mte_instr_illegal_cfg_t1 : 1;
        unsigned int mte_atm_add_addr_misalign_t1 : 1;
        unsigned int mte_instr_addr_misalign_t1 : 1;
        unsigned int mte_gdma_read_overflow_t1 : 1;
        unsigned int mte_gdma_write_overflow_t1 : 1;
        unsigned int mte_gdma_illegal_burst_num_t1 : 1;
        unsigned int mte_gdma_illegal_burst_len_t1 : 1;
        unsigned int mte_aipp_illegal_param_t1 : 1;
        unsigned int mte_err_unzip_t1 : 1;
        unsigned int mte_err_hebcd_t1 : 1;
        unsigned int mte_err_hebce_t1 : 1;
        unsigned int mte_err_waipp_t1 : 1;
        unsigned int mte_stb_ecc_t1 : 1;
        unsigned int mte_aipp_ecc_t1 : 1;
        unsigned int mte_tagmgr_buf_ecc_t1 : 1;
        unsigned int mte_ub_ecc_t1 : 1;
        unsigned int mte_rob_ecc_t1 : 1;
        unsigned int mte_biu_rdwr_resp_t1 : 1;
    } reg;
} SOC_NPU_AICORE_MTE_ERROR_T1_0_UNION;
#endif
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_nddma_cache_ecc_t1_START (0)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_nddma_cache_ecc_t1_END (0)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_nddma_req_buf_ecc_t1_START (1)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_nddma_req_buf_ecc_t1_END (1)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_l1_ecc_t1_START (2)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_l1_ecc_t1_END (2)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_cfg_reg_parity_t1_START (3)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_cfg_reg_parity_t1_END (3)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_l0a_rdwr_cflt_t1_START (4)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_l0a_rdwr_cflt_t1_END (4)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_l0b_rdwr_cflt_t1_START (5)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_l0b_rdwr_cflt_t1_END (5)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_timeout_t1_START (6)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_timeout_t1_END (6)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_ub_rd_cflt_t1_START (7)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_ub_rd_cflt_t1_END (7)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_ub_wr_cflt_t1_START (8)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_ub_wr_cflt_t1_END (8)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_read_overflow_t1_START (9)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_read_overflow_t1_END (9)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_write_overflow_t1_START (10)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_write_overflow_t1_END (10)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_err_fifo_parity_t1_START (11)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_err_fifo_parity_t1_END (11)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_ub_wr_ovflw_t1_START (12)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_ub_wr_ovflw_t1_END (12)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_ub_rd_ovflw_t1_START (13)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_ub_rd_ovflw_t1_END (13)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_instr_illegal_cfg_t1_START (14)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_instr_illegal_cfg_t1_END (14)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_atm_add_addr_misalign_t1_START (15)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_atm_add_addr_misalign_t1_END (15)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_instr_addr_misalign_t1_START (16)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_instr_addr_misalign_t1_END (16)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_gdma_read_overflow_t1_START (17)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_gdma_read_overflow_t1_END (17)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_gdma_write_overflow_t1_START (18)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_gdma_write_overflow_t1_END (18)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_gdma_illegal_burst_num_t1_START (19)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_gdma_illegal_burst_num_t1_END (19)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_gdma_illegal_burst_len_t1_START (20)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_gdma_illegal_burst_len_t1_END (20)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_aipp_illegal_param_t1_START (21)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_aipp_illegal_param_t1_END (21)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_err_unzip_t1_START (22)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_err_unzip_t1_END (22)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_err_hebcd_t1_START (23)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_err_hebcd_t1_END (23)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_err_hebce_t1_START (24)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_err_hebce_t1_END (24)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_err_waipp_t1_START (25)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_err_waipp_t1_END (25)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_stb_ecc_t1_START (26)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_stb_ecc_t1_END (26)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_aipp_ecc_t1_START (27)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_aipp_ecc_t1_END (27)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_tagmgr_buf_ecc_t1_START (28)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_tagmgr_buf_ecc_t1_END (28)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_ub_ecc_t1_START (29)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_ub_ecc_t1_END (29)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_rob_ecc_t1_START (30)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_rob_ecc_t1_END (30)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_biu_rdwr_resp_t1_START (31)
#define SOC_NPU_AICORE_MTE_ERROR_T1_0_mte_biu_rdwr_resp_t1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_MTE_ERROR_T1_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_nddma_cache_ecc_mask : 1;
        unsigned int mte_nddma_req_buf_ecc_mask : 1;
        unsigned int mte_l1_ecc_mask : 1;
        unsigned int mte_cfg_reg_parity_mask : 1;
        unsigned int mte_l0a_rdwr_cflt_mask : 1;
        unsigned int mte_l0b_rdwr_cflt_mask : 1;
        unsigned int mte_timeout_mask : 1;
        unsigned int mte_ub_rd_cflt_mask : 1;
        unsigned int mte_ub_wr_cflt_mask : 1;
        unsigned int mte_read_overflow_mask : 1;
        unsigned int mte_write_overflow_mask : 1;
        unsigned int mte_err_fifo_parity_mask : 1;
        unsigned int mte_ub_wr_ovflw_mask : 1;
        unsigned int mte_ub_rd_ovflw_mask : 1;
        unsigned int mte_instr_illegal_cfg_mask : 1;
        unsigned int mte_atm_add_addr_misalign_mask : 1;
        unsigned int mte_instr_addr_misalign_mask : 1;
        unsigned int mte_gdma_read_overflow_mask : 1;
        unsigned int mte_gdma_write_overflow_mask : 1;
        unsigned int mte_gdma_illegal_burst_num_mask : 1;
        unsigned int mte_gdma_illegal_burst_len_mask : 1;
        unsigned int mte_aipp_illegal_param_mask : 1;
        unsigned int mte_err_unzip_mask : 1;
        unsigned int mte_err_hebcd_mask : 1;
        unsigned int mte_err_hebce_mask : 1;
        unsigned int mte_err_waipp_mask : 1;
        unsigned int mte_stb_ecc_mask : 1;
        unsigned int mte_aipp_ecc_mask : 1;
        unsigned int mte_tagmgr_buf_ecc_mask : 1;
        unsigned int mte_ub_ecc_mask : 1;
        unsigned int mte_rob_ecc_mask : 1;
        unsigned int mte_biu_rdwr_resp_mask : 1;
    } reg;
} SOC_NPU_AICORE_MTE_ERROR_MASK_0_UNION;
#endif
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_nddma_cache_ecc_mask_START (0)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_nddma_cache_ecc_mask_END (0)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_nddma_req_buf_ecc_mask_START (1)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_nddma_req_buf_ecc_mask_END (1)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_l1_ecc_mask_START (2)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_l1_ecc_mask_END (2)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_cfg_reg_parity_mask_START (3)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_cfg_reg_parity_mask_END (3)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_l0a_rdwr_cflt_mask_START (4)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_l0a_rdwr_cflt_mask_END (4)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_l0b_rdwr_cflt_mask_START (5)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_l0b_rdwr_cflt_mask_END (5)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_timeout_mask_START (6)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_timeout_mask_END (6)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_ub_rd_cflt_mask_START (7)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_ub_rd_cflt_mask_END (7)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_ub_wr_cflt_mask_START (8)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_ub_wr_cflt_mask_END (8)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_read_overflow_mask_START (9)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_read_overflow_mask_END (9)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_write_overflow_mask_START (10)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_write_overflow_mask_END (10)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_err_fifo_parity_mask_START (11)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_err_fifo_parity_mask_END (11)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_ub_wr_ovflw_mask_START (12)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_ub_wr_ovflw_mask_END (12)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_ub_rd_ovflw_mask_START (13)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_ub_rd_ovflw_mask_END (13)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_instr_illegal_cfg_mask_START (14)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_instr_illegal_cfg_mask_END (14)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_atm_add_addr_misalign_mask_START (15)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_atm_add_addr_misalign_mask_END (15)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_instr_addr_misalign_mask_START (16)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_instr_addr_misalign_mask_END (16)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_gdma_read_overflow_mask_START (17)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_gdma_read_overflow_mask_END (17)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_gdma_write_overflow_mask_START (18)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_gdma_write_overflow_mask_END (18)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_gdma_illegal_burst_num_mask_START (19)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_gdma_illegal_burst_num_mask_END (19)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_gdma_illegal_burst_len_mask_START (20)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_gdma_illegal_burst_len_mask_END (20)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_aipp_illegal_param_mask_START (21)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_aipp_illegal_param_mask_END (21)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_err_unzip_mask_START (22)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_err_unzip_mask_END (22)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_err_hebcd_mask_START (23)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_err_hebcd_mask_END (23)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_err_hebce_mask_START (24)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_err_hebce_mask_END (24)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_err_waipp_mask_START (25)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_err_waipp_mask_END (25)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_stb_ecc_mask_START (26)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_stb_ecc_mask_END (26)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_aipp_ecc_mask_START (27)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_aipp_ecc_mask_END (27)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_tagmgr_buf_ecc_mask_START (28)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_tagmgr_buf_ecc_mask_END (28)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_ub_ecc_mask_START (29)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_ub_ecc_mask_END (29)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_rob_ecc_mask_START (30)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_rob_ecc_mask_END (30)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_biu_rdwr_resp_mask_START (31)
#define SOC_NPU_AICORE_MTE_ERROR_MASK_0_mte_biu_rdwr_resp_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_MTE_ERROR_MASK_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_err_pc_t0 : 16;
        unsigned int mte_err_type_t0 : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_NPU_AICORE_MTE_ERR_INFO_T0_0_UNION;
#endif
#define SOC_NPU_AICORE_MTE_ERR_INFO_T0_0_mte_err_pc_t0_START (0)
#define SOC_NPU_AICORE_MTE_ERR_INFO_T0_0_mte_err_pc_t0_END (15)
#define SOC_NPU_AICORE_MTE_ERR_INFO_T0_0_mte_err_type_t0_START (16)
#define SOC_NPU_AICORE_MTE_ERR_INFO_T0_0_mte_err_type_t0_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_err_addr_l_t0 : 32;
    } reg;
} SOC_NPU_AICORE_MTE_ERR_INFO_T0_1_UNION;
#endif
#define SOC_NPU_AICORE_MTE_ERR_INFO_T0_1_mte_err_addr_l_t0_START (0)
#define SOC_NPU_AICORE_MTE_ERR_INFO_T0_1_mte_err_addr_l_t0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_err_addr_h_t0 : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_NPU_AICORE_MTE_ERR_INFO_T0_2_UNION;
#endif
#define SOC_NPU_AICORE_MTE_ERR_INFO_T0_2_mte_err_addr_h_t0_START (0)
#define SOC_NPU_AICORE_MTE_ERR_INFO_T0_2_mte_err_addr_h_t0_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_err_pc_t1 : 16;
        unsigned int mte_err_type_t1 : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_NPU_AICORE_MTE_ERR_INFO_T1_0_UNION;
#endif
#define SOC_NPU_AICORE_MTE_ERR_INFO_T1_0_mte_err_pc_t1_START (0)
#define SOC_NPU_AICORE_MTE_ERR_INFO_T1_0_mte_err_pc_t1_END (15)
#define SOC_NPU_AICORE_MTE_ERR_INFO_T1_0_mte_err_type_t1_START (16)
#define SOC_NPU_AICORE_MTE_ERR_INFO_T1_0_mte_err_type_t1_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_err_addr_l_t1 : 32;
    } reg;
} SOC_NPU_AICORE_MTE_ERR_INFO_T1_1_UNION;
#endif
#define SOC_NPU_AICORE_MTE_ERR_INFO_T1_1_mte_err_addr_l_t1_START (0)
#define SOC_NPU_AICORE_MTE_ERR_INFO_T1_1_mte_err_addr_l_t1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_err_addr_h_t1 : 11;
        unsigned int reserved : 21;
    } reg;
} SOC_NPU_AICORE_MTE_ERR_INFO_T1_2_UNION;
#endif
#define SOC_NPU_AICORE_MTE_ERR_INFO_T1_2_mte_err_addr_h_t1_START (0)
#define SOC_NPU_AICORE_MTE_ERR_INFO_T1_2_mte_err_addr_h_t1_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int warn_mte_nop_cfg_instr_t0 : 1;
        unsigned int warn_mte_atomic_fp_ovfl_t0 : 1;
        unsigned int warn_mte_atomic_fp_inf_t0 : 1;
        unsigned int warn_mte_atomic_fp_src_nan_t0 : 1;
        unsigned int warn_mte_atomic_fp_des_nan_t0 : 1;
        unsigned int warn_mte_atomic_fp_both_nan_t0 : 1;
        unsigned int warn_mte_atomic_int_ovfl_t0 : 1;
        unsigned int warn_mte_atomic_notequal_t0 : 1;
        unsigned int aipp_och4_pad_err_t0 : 1;
        unsigned int aipp_trans_mode_err_t0 : 1;
        unsigned int aipp_alu_saturation_t0 : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_NPU_AICORE_MTE_WARN_T0_0_UNION;
#endif
#define SOC_NPU_AICORE_MTE_WARN_T0_0_warn_mte_nop_cfg_instr_t0_START (0)
#define SOC_NPU_AICORE_MTE_WARN_T0_0_warn_mte_nop_cfg_instr_t0_END (0)
#define SOC_NPU_AICORE_MTE_WARN_T0_0_warn_mte_atomic_fp_ovfl_t0_START (1)
#define SOC_NPU_AICORE_MTE_WARN_T0_0_warn_mte_atomic_fp_ovfl_t0_END (1)
#define SOC_NPU_AICORE_MTE_WARN_T0_0_warn_mte_atomic_fp_inf_t0_START (2)
#define SOC_NPU_AICORE_MTE_WARN_T0_0_warn_mte_atomic_fp_inf_t0_END (2)
#define SOC_NPU_AICORE_MTE_WARN_T0_0_warn_mte_atomic_fp_src_nan_t0_START (3)
#define SOC_NPU_AICORE_MTE_WARN_T0_0_warn_mte_atomic_fp_src_nan_t0_END (3)
#define SOC_NPU_AICORE_MTE_WARN_T0_0_warn_mte_atomic_fp_des_nan_t0_START (4)
#define SOC_NPU_AICORE_MTE_WARN_T0_0_warn_mte_atomic_fp_des_nan_t0_END (4)
#define SOC_NPU_AICORE_MTE_WARN_T0_0_warn_mte_atomic_fp_both_nan_t0_START (5)
#define SOC_NPU_AICORE_MTE_WARN_T0_0_warn_mte_atomic_fp_both_nan_t0_END (5)
#define SOC_NPU_AICORE_MTE_WARN_T0_0_warn_mte_atomic_int_ovfl_t0_START (6)
#define SOC_NPU_AICORE_MTE_WARN_T0_0_warn_mte_atomic_int_ovfl_t0_END (6)
#define SOC_NPU_AICORE_MTE_WARN_T0_0_warn_mte_atomic_notequal_t0_START (7)
#define SOC_NPU_AICORE_MTE_WARN_T0_0_warn_mte_atomic_notequal_t0_END (7)
#define SOC_NPU_AICORE_MTE_WARN_T0_0_aipp_och4_pad_err_t0_START (8)
#define SOC_NPU_AICORE_MTE_WARN_T0_0_aipp_och4_pad_err_t0_END (8)
#define SOC_NPU_AICORE_MTE_WARN_T0_0_aipp_trans_mode_err_t0_START (9)
#define SOC_NPU_AICORE_MTE_WARN_T0_0_aipp_trans_mode_err_t0_END (9)
#define SOC_NPU_AICORE_MTE_WARN_T0_0_aipp_alu_saturation_t0_START (10)
#define SOC_NPU_AICORE_MTE_WARN_T0_0_aipp_alu_saturation_t0_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int warn_mte_nop_cfg_instr_t1 : 1;
        unsigned int warn_mte_atomic_fp_ovfl_t1 : 1;
        unsigned int warn_mte_atomic_fp_inf_t1 : 1;
        unsigned int warn_mte_atomic_fp_src_nan_t1 : 1;
        unsigned int warn_mte_atomic_fp_des_nan_t1 : 1;
        unsigned int warn_mte_atomic_fp_both_nan_t1 : 1;
        unsigned int warn_mte_atomic_int_ovfl_t1 : 1;
        unsigned int warn_mte_atomic_notequal_t1 : 1;
        unsigned int aipp_och4_pad_err_t1 : 1;
        unsigned int aipp_trans_mode_err_t1 : 1;
        unsigned int aipp_alu_saturation_t1 : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_NPU_AICORE_MTE_WARN_T1_0_UNION;
#endif
#define SOC_NPU_AICORE_MTE_WARN_T1_0_warn_mte_nop_cfg_instr_t1_START (0)
#define SOC_NPU_AICORE_MTE_WARN_T1_0_warn_mte_nop_cfg_instr_t1_END (0)
#define SOC_NPU_AICORE_MTE_WARN_T1_0_warn_mte_atomic_fp_ovfl_t1_START (1)
#define SOC_NPU_AICORE_MTE_WARN_T1_0_warn_mte_atomic_fp_ovfl_t1_END (1)
#define SOC_NPU_AICORE_MTE_WARN_T1_0_warn_mte_atomic_fp_inf_t1_START (2)
#define SOC_NPU_AICORE_MTE_WARN_T1_0_warn_mte_atomic_fp_inf_t1_END (2)
#define SOC_NPU_AICORE_MTE_WARN_T1_0_warn_mte_atomic_fp_src_nan_t1_START (3)
#define SOC_NPU_AICORE_MTE_WARN_T1_0_warn_mte_atomic_fp_src_nan_t1_END (3)
#define SOC_NPU_AICORE_MTE_WARN_T1_0_warn_mte_atomic_fp_des_nan_t1_START (4)
#define SOC_NPU_AICORE_MTE_WARN_T1_0_warn_mte_atomic_fp_des_nan_t1_END (4)
#define SOC_NPU_AICORE_MTE_WARN_T1_0_warn_mte_atomic_fp_both_nan_t1_START (5)
#define SOC_NPU_AICORE_MTE_WARN_T1_0_warn_mte_atomic_fp_both_nan_t1_END (5)
#define SOC_NPU_AICORE_MTE_WARN_T1_0_warn_mte_atomic_int_ovfl_t1_START (6)
#define SOC_NPU_AICORE_MTE_WARN_T1_0_warn_mte_atomic_int_ovfl_t1_END (6)
#define SOC_NPU_AICORE_MTE_WARN_T1_0_warn_mte_atomic_notequal_t1_START (7)
#define SOC_NPU_AICORE_MTE_WARN_T1_0_warn_mte_atomic_notequal_t1_END (7)
#define SOC_NPU_AICORE_MTE_WARN_T1_0_aipp_och4_pad_err_t1_START (8)
#define SOC_NPU_AICORE_MTE_WARN_T1_0_aipp_och4_pad_err_t1_END (8)
#define SOC_NPU_AICORE_MTE_WARN_T1_0_aipp_trans_mode_err_t1_START (9)
#define SOC_NPU_AICORE_MTE_WARN_T1_0_aipp_trans_mode_err_t1_END (9)
#define SOC_NPU_AICORE_MTE_WARN_T1_0_aipp_alu_saturation_t1_START (10)
#define SOC_NPU_AICORE_MTE_WARN_T1_0_aipp_alu_saturation_t1_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int warn_mte_nop_cfg_instr_mask : 1;
        unsigned int warn_mte_atomic_fp_ovfl_mask : 1;
        unsigned int warn_mte_atomic_fp_inf_mask : 1;
        unsigned int warn_mte_atomic_fp_src_nan_mask : 1;
        unsigned int warn_mte_atomic_fp_des_nan_mask : 1;
        unsigned int warn_mte_atomic_fp_both_nan_mask : 1;
        unsigned int warn_mte_atomic_int_ovfl_mask : 1;
        unsigned int warn_mte_atomic_notequal_mask : 1;
        unsigned int aipp_och4_pad_err_mask : 1;
        unsigned int aipp_trans_mode_err_mask : 1;
        unsigned int aipp_alu_saturation_mask : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_NPU_AICORE_MTE_WARN_MASK_0_UNION;
#endif
#define SOC_NPU_AICORE_MTE_WARN_MASK_0_warn_mte_nop_cfg_instr_mask_START (0)
#define SOC_NPU_AICORE_MTE_WARN_MASK_0_warn_mte_nop_cfg_instr_mask_END (0)
#define SOC_NPU_AICORE_MTE_WARN_MASK_0_warn_mte_atomic_fp_ovfl_mask_START (1)
#define SOC_NPU_AICORE_MTE_WARN_MASK_0_warn_mte_atomic_fp_ovfl_mask_END (1)
#define SOC_NPU_AICORE_MTE_WARN_MASK_0_warn_mte_atomic_fp_inf_mask_START (2)
#define SOC_NPU_AICORE_MTE_WARN_MASK_0_warn_mte_atomic_fp_inf_mask_END (2)
#define SOC_NPU_AICORE_MTE_WARN_MASK_0_warn_mte_atomic_fp_src_nan_mask_START (3)
#define SOC_NPU_AICORE_MTE_WARN_MASK_0_warn_mte_atomic_fp_src_nan_mask_END (3)
#define SOC_NPU_AICORE_MTE_WARN_MASK_0_warn_mte_atomic_fp_des_nan_mask_START (4)
#define SOC_NPU_AICORE_MTE_WARN_MASK_0_warn_mte_atomic_fp_des_nan_mask_END (4)
#define SOC_NPU_AICORE_MTE_WARN_MASK_0_warn_mte_atomic_fp_both_nan_mask_START (5)
#define SOC_NPU_AICORE_MTE_WARN_MASK_0_warn_mte_atomic_fp_both_nan_mask_END (5)
#define SOC_NPU_AICORE_MTE_WARN_MASK_0_warn_mte_atomic_int_ovfl_mask_START (6)
#define SOC_NPU_AICORE_MTE_WARN_MASK_0_warn_mte_atomic_int_ovfl_mask_END (6)
#define SOC_NPU_AICORE_MTE_WARN_MASK_0_warn_mte_atomic_notequal_mask_START (7)
#define SOC_NPU_AICORE_MTE_WARN_MASK_0_warn_mte_atomic_notequal_mask_END (7)
#define SOC_NPU_AICORE_MTE_WARN_MASK_0_aipp_och4_pad_err_mask_START (8)
#define SOC_NPU_AICORE_MTE_WARN_MASK_0_aipp_och4_pad_err_mask_END (8)
#define SOC_NPU_AICORE_MTE_WARN_MASK_0_aipp_trans_mode_err_mask_START (9)
#define SOC_NPU_AICORE_MTE_WARN_MASK_0_aipp_trans_mode_err_mask_END (9)
#define SOC_NPU_AICORE_MTE_WARN_MASK_0_aipp_alu_saturation_mask_START (10)
#define SOC_NPU_AICORE_MTE_WARN_MASK_0_aipp_alu_saturation_mask_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_warn_stb_ecc_1bit_addr : 16;
        unsigned int mte_warn_aipp_ecc_1bit_addr : 16;
    } reg;
} SOC_NPU_AICORE_MTE_1BIT_ECC_ERR_ADDR_0_UNION;
#endif
#define SOC_NPU_AICORE_MTE_1BIT_ECC_ERR_ADDR_0_mte_warn_stb_ecc_1bit_addr_START (0)
#define SOC_NPU_AICORE_MTE_1BIT_ECC_ERR_ADDR_0_mte_warn_stb_ecc_1bit_addr_END (15)
#define SOC_NPU_AICORE_MTE_1BIT_ECC_ERR_ADDR_0_mte_warn_aipp_ecc_1bit_addr_START (16)
#define SOC_NPU_AICORE_MTE_1BIT_ECC_ERR_ADDR_0_mte_warn_aipp_ecc_1bit_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_warn_rob_ecc_1bit_addr : 16;
        unsigned int mte_warn_tagmgr_buf_ecc_1bit_addr : 16;
    } reg;
} SOC_NPU_AICORE_MTE_1BIT_ECC_ERR_ADDR_1_UNION;
#endif
#define SOC_NPU_AICORE_MTE_1BIT_ECC_ERR_ADDR_1_mte_warn_rob_ecc_1bit_addr_START (0)
#define SOC_NPU_AICORE_MTE_1BIT_ECC_ERR_ADDR_1_mte_warn_rob_ecc_1bit_addr_END (15)
#define SOC_NPU_AICORE_MTE_1BIT_ECC_ERR_ADDR_1_mte_warn_tagmgr_buf_ecc_1bit_addr_START (16)
#define SOC_NPU_AICORE_MTE_1BIT_ECC_ERR_ADDR_1_mte_warn_tagmgr_buf_ecc_1bit_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_warn_nddma_cache_ecc_1bit_addr : 16;
        unsigned int mte_warn_nddma_req_buf_ecc_1bit_addr : 16;
    } reg;
} SOC_NPU_AICORE_MTE_1BIT_ECC_ERR_ADDR_2_UNION;
#endif
#define SOC_NPU_AICORE_MTE_1BIT_ECC_ERR_ADDR_2_mte_warn_nddma_cache_ecc_1bit_addr_START (0)
#define SOC_NPU_AICORE_MTE_1BIT_ECC_ERR_ADDR_2_mte_warn_nddma_cache_ecc_1bit_addr_END (15)
#define SOC_NPU_AICORE_MTE_1BIT_ECC_ERR_ADDR_2_mte_warn_nddma_req_buf_ecc_1bit_addr_START (16)
#define SOC_NPU_AICORE_MTE_1BIT_ECC_ERR_ADDR_2_mte_warn_nddma_req_buf_ecc_1bit_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_task_end_cfg : 8;
        unsigned int mte_sid_hw_remap_en : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_NPU_AICORE_MTE_CTRL_UNION;
#endif
#define SOC_NPU_AICORE_MTE_CTRL_mte_task_end_cfg_START (0)
#define SOC_NPU_AICORE_MTE_CTRL_mte_task_end_cfg_END (7)
#define SOC_NPU_AICORE_MTE_CTRL_mte_sid_hw_remap_en_START (8)
#define SOC_NPU_AICORE_MTE_CTRL_mte_sid_hw_remap_en_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_chicken_bit : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_AICORE_MTE_CTRL2_UNION;
#endif
#define SOC_NPU_AICORE_MTE_CTRL2_mte_chicken_bit_START (0)
#define SOC_NPU_AICORE_MTE_CTRL2_mte_chicken_bit_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_aipp_reserved : 32;
    } reg;
} SOC_NPU_AICORE_MTE_AIPP_CTRL_UNION;
#endif
#define SOC_NPU_AICORE_MTE_AIPP_CTRL_mte_aipp_reserved_START (0)
#define SOC_NPU_AICORE_MTE_AIPP_CTRL_mte_aipp_reserved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_waipp_reserved : 32;
    } reg;
} SOC_NPU_AICORE_MTE_WAIPP_CTRL_UNION;
#endif
#define SOC_NPU_AICORE_MTE_WAIPP_CTRL_mte_waipp_reserved_START (0)
#define SOC_NPU_AICORE_MTE_WAIPP_CTRL_mte_waipp_reserved_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_reserved_ro_reg0 : 32;
    } reg;
} SOC_NPU_AICORE_MTE_RESERVED_RO_REG0_UNION;
#endif
#define SOC_NPU_AICORE_MTE_RESERVED_RO_REG0_mte_reserved_ro_reg0_START (0)
#define SOC_NPU_AICORE_MTE_RESERVED_RO_REG0_mte_reserved_ro_reg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_reserved_ro_reg1 : 32;
    } reg;
} SOC_NPU_AICORE_MTE_RESERVED_RO_REG1_UNION;
#endif
#define SOC_NPU_AICORE_MTE_RESERVED_RO_REG1_mte_reserved_ro_reg1_START (0)
#define SOC_NPU_AICORE_MTE_RESERVED_RO_REG1_mte_reserved_ro_reg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_reserved_rw_reg0 : 32;
    } reg;
} SOC_NPU_AICORE_MTE_RESERVED_RW_REG0_UNION;
#endif
#define SOC_NPU_AICORE_MTE_RESERVED_RW_REG0_mte_reserved_rw_reg0_START (0)
#define SOC_NPU_AICORE_MTE_RESERVED_RW_REG0_mte_reserved_rw_reg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mte_reserved_rw_reg1 : 32;
    } reg;
} SOC_NPU_AICORE_MTE_RESERVED_RW_REG1_UNION;
#endif
#define SOC_NPU_AICORE_MTE_RESERVED_RW_REG1_mte_reserved_rw_reg1_START (0)
#define SOC_NPU_AICORE_MTE_RESERVED_RW_REG1_mte_reserved_rw_reg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bk_aic_all_clk_en_mask : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_COMMON_BK_GLB_CLK_GATE_MASK_UNION;
#endif
#define SOC_NPU_AICORE_COMMON_BK_GLB_CLK_GATE_MASK_bk_aic_all_clk_en_mask_START (0)
#define SOC_NPU_AICORE_COMMON_BK_GLB_CLK_GATE_MASK_bk_aic_all_clk_en_mask_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_COMMON_BK_MTE_CLK_GATE_MASK_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bk_clk_mte_en_mask_1 : 32;
    } reg;
} SOC_NPU_AICORE_COMMON_BK_MTE_CLK_GATE_MASK_1_UNION;
#endif
#define SOC_NPU_AICORE_COMMON_BK_MTE_CLK_GATE_MASK_1_bk_clk_mte_en_mask_1_START (0)
#define SOC_NPU_AICORE_COMMON_BK_MTE_CLK_GATE_MASK_1_bk_clk_mte_en_mask_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bk_warn_mte_nop_cfg_instr_mask : 1;
        unsigned int bk_warn_mte_atomic_fp_ovfl_mask : 1;
        unsigned int bk_warn_mte_atomic_fp_inf_mask : 1;
        unsigned int bk_warn_mte_atomic_fp_src_nan_mask : 1;
        unsigned int bk_warn_mte_atomic_fp_des_nan_mask : 1;
        unsigned int bk_warn_mte_atomic_fp_both_nan_mask : 1;
        unsigned int bk_warn_mte_atomic_int_ovfl_mask : 1;
        unsigned int bk_warn_mte_atomic_notequal_mask : 1;
        unsigned int bk_aipp_och4_pad_err_mask : 1;
        unsigned int bk_aipp_trans_mode_err_mask : 1;
        unsigned int bk_aipp_alu_saturation_mask : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_NPU_AICORE_COMMON_BK_MTE_WARN_MASK_0_UNION;
#endif
#define SOC_NPU_AICORE_COMMON_BK_MTE_WARN_MASK_0_bk_warn_mte_nop_cfg_instr_mask_START (0)
#define SOC_NPU_AICORE_COMMON_BK_MTE_WARN_MASK_0_bk_warn_mte_nop_cfg_instr_mask_END (0)
#define SOC_NPU_AICORE_COMMON_BK_MTE_WARN_MASK_0_bk_warn_mte_atomic_fp_ovfl_mask_START (1)
#define SOC_NPU_AICORE_COMMON_BK_MTE_WARN_MASK_0_bk_warn_mte_atomic_fp_ovfl_mask_END (1)
#define SOC_NPU_AICORE_COMMON_BK_MTE_WARN_MASK_0_bk_warn_mte_atomic_fp_inf_mask_START (2)
#define SOC_NPU_AICORE_COMMON_BK_MTE_WARN_MASK_0_bk_warn_mte_atomic_fp_inf_mask_END (2)
#define SOC_NPU_AICORE_COMMON_BK_MTE_WARN_MASK_0_bk_warn_mte_atomic_fp_src_nan_mask_START (3)
#define SOC_NPU_AICORE_COMMON_BK_MTE_WARN_MASK_0_bk_warn_mte_atomic_fp_src_nan_mask_END (3)
#define SOC_NPU_AICORE_COMMON_BK_MTE_WARN_MASK_0_bk_warn_mte_atomic_fp_des_nan_mask_START (4)
#define SOC_NPU_AICORE_COMMON_BK_MTE_WARN_MASK_0_bk_warn_mte_atomic_fp_des_nan_mask_END (4)
#define SOC_NPU_AICORE_COMMON_BK_MTE_WARN_MASK_0_bk_warn_mte_atomic_fp_both_nan_mask_START (5)
#define SOC_NPU_AICORE_COMMON_BK_MTE_WARN_MASK_0_bk_warn_mte_atomic_fp_both_nan_mask_END (5)
#define SOC_NPU_AICORE_COMMON_BK_MTE_WARN_MASK_0_bk_warn_mte_atomic_int_ovfl_mask_START (6)
#define SOC_NPU_AICORE_COMMON_BK_MTE_WARN_MASK_0_bk_warn_mte_atomic_int_ovfl_mask_END (6)
#define SOC_NPU_AICORE_COMMON_BK_MTE_WARN_MASK_0_bk_warn_mte_atomic_notequal_mask_START (7)
#define SOC_NPU_AICORE_COMMON_BK_MTE_WARN_MASK_0_bk_warn_mte_atomic_notequal_mask_END (7)
#define SOC_NPU_AICORE_COMMON_BK_MTE_WARN_MASK_0_bk_aipp_och4_pad_err_mask_START (8)
#define SOC_NPU_AICORE_COMMON_BK_MTE_WARN_MASK_0_bk_aipp_och4_pad_err_mask_END (8)
#define SOC_NPU_AICORE_COMMON_BK_MTE_WARN_MASK_0_bk_aipp_trans_mode_err_mask_START (9)
#define SOC_NPU_AICORE_COMMON_BK_MTE_WARN_MASK_0_bk_aipp_trans_mode_err_mask_END (9)
#define SOC_NPU_AICORE_COMMON_BK_MTE_WARN_MASK_0_bk_aipp_alu_saturation_mask_START (10)
#define SOC_NPU_AICORE_COMMON_BK_MTE_WARN_MASK_0_bk_aipp_alu_saturation_mask_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bk_mte_err_mask : 32;
    } reg;
} SOC_NPU_AICORE_COMMON_BK_MTE_ERROR_MASK_0_UNION;
#endif
#define SOC_NPU_AICORE_COMMON_BK_MTE_ERROR_MASK_0_bk_mte_err_mask_START (0)
#define SOC_NPU_AICORE_COMMON_BK_MTE_ERROR_MASK_0_bk_mte_err_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_ecc_en_n : 1;
        unsigned int vec_ecc_wb_en_n : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_AICORE_VEC_ECC_CTRL_0_UNION;
#endif
#define SOC_NPU_AICORE_VEC_ECC_CTRL_0_vec_ecc_en_n_START (0)
#define SOC_NPU_AICORE_VEC_ECC_CTRL_0_vec_ecc_en_n_END (0)
#define SOC_NPU_AICORE_VEC_ECC_CTRL_0_vec_ecc_wb_en_n_START (1)
#define SOC_NPU_AICORE_VEC_ECC_CTRL_0_vec_ecc_wb_en_n_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_ub_ecc_sb_inject : 1;
        unsigned int vec_ub_ecc_mb_inject : 1;
        unsigned int vec_ic_ecc_sb_inject : 1;
        unsigned int vec_ic_ecc_mb_inject : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_NPU_AICORE_VEC_ECC_INJECT_CTRL_0_UNION;
#endif
#define SOC_NPU_AICORE_VEC_ECC_INJECT_CTRL_0_vec_ub_ecc_sb_inject_START (0)
#define SOC_NPU_AICORE_VEC_ECC_INJECT_CTRL_0_vec_ub_ecc_sb_inject_END (0)
#define SOC_NPU_AICORE_VEC_ECC_INJECT_CTRL_0_vec_ub_ecc_mb_inject_START (1)
#define SOC_NPU_AICORE_VEC_ECC_INJECT_CTRL_0_vec_ub_ecc_mb_inject_END (1)
#define SOC_NPU_AICORE_VEC_ECC_INJECT_CTRL_0_vec_ic_ecc_sb_inject_START (2)
#define SOC_NPU_AICORE_VEC_ECC_INJECT_CTRL_0_vec_ic_ecc_sb_inject_END (2)
#define SOC_NPU_AICORE_VEC_ECC_INJECT_CTRL_0_vec_ic_ecc_mb_inject_START (3)
#define SOC_NPU_AICORE_VEC_ECC_INJECT_CTRL_0_vec_ic_ecc_mb_inject_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_runtime_thr : 20;
        unsigned int vec_prefetch_thr : 8;
        unsigned int vec_pfifo_peekn : 4;
    } reg;
} SOC_NPU_AICORE_VEC_CFG_UNION;
#endif
#define SOC_NPU_AICORE_VEC_CFG_vec_runtime_thr_START (0)
#define SOC_NPU_AICORE_VEC_CFG_vec_runtime_thr_END (19)
#define SOC_NPU_AICORE_VEC_CFG_vec_prefetch_thr_START (20)
#define SOC_NPU_AICORE_VEC_CFG_vec_prefetch_thr_END (27)
#define SOC_NPU_AICORE_VEC_CFG_vec_pfifo_peekn_START (28)
#define SOC_NPU_AICORE_VEC_CFG_vec_pfifo_peekn_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_simt_force_evc_thr_low : 11;
        unsigned int vec_simt_force_evc_thr_high : 11;
        unsigned int reserved : 10;
    } reg;
} SOC_NPU_AICORE_VEC_SIMT_CFG_0_UNION;
#endif
#define SOC_NPU_AICORE_VEC_SIMT_CFG_0_vec_simt_force_evc_thr_low_START (0)
#define SOC_NPU_AICORE_VEC_SIMT_CFG_0_vec_simt_force_evc_thr_low_END (10)
#define SOC_NPU_AICORE_VEC_SIMT_CFG_0_vec_simt_force_evc_thr_high_START (11)
#define SOC_NPU_AICORE_VEC_SIMT_CFG_0_vec_simt_force_evc_thr_high_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_simt_prefetch_hold_thr : 6;
        unsigned int vec_simt_exec_token_threshold : 12;
        unsigned int reserved : 14;
    } reg;
} SOC_NPU_AICORE_VEC_SIMT_CFG_1_UNION;
#endif
#define SOC_NPU_AICORE_VEC_SIMT_CFG_1_vec_simt_prefetch_hold_thr_START (0)
#define SOC_NPU_AICORE_VEC_SIMT_CFG_1_vec_simt_prefetch_hold_thr_END (5)
#define SOC_NPU_AICORE_VEC_SIMT_CFG_1_vec_simt_exec_token_threshold_START (6)
#define SOC_NPU_AICORE_VEC_SIMT_CFG_1_vec_simt_exec_token_threshold_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk_vec_en_mask_l : 32;
    } reg;
} SOC_NPU_AICORE_VEC_CLK_GATE_MASK_0_UNION;
#endif
#define SOC_NPU_AICORE_VEC_CLK_GATE_MASK_0_clk_vec_en_mask_l_START (0)
#define SOC_NPU_AICORE_VEC_CLK_GATE_MASK_0_clk_vec_en_mask_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk_vec_en_mask_h : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_NPU_AICORE_VEC_CLK_GATE_MASK_1_UNION;
#endif
#define SOC_NPU_AICORE_VEC_CLK_GATE_MASK_1_clk_vec_en_mask_h_START (0)
#define SOC_NPU_AICORE_VEC_CLK_GATE_MASK_1_clk_vec_en_mask_h_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_fast_csw_period : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_AICORE_VEC_FCSW_PERIOD_UNION;
#endif
#define SOC_NPU_AICORE_VEC_FCSW_PERIOD_vec_fast_csw_period_START (0)
#define SOC_NPU_AICORE_VEC_FCSW_PERIOD_vec_fast_csw_period_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_fast_csw_thr_low : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPU_AICORE_VEC_FCSW_THR_LOW_UNION;
#endif
#define SOC_NPU_AICORE_VEC_FCSW_THR_LOW_vec_fast_csw_thr_low_START (0)
#define SOC_NPU_AICORE_VEC_FCSW_THR_LOW_vec_fast_csw_thr_low_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_fast_csw_thr_high : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPU_AICORE_VEC_FCSW_THR_HIGH_UNION;
#endif
#define SOC_NPU_AICORE_VEC_FCSW_THR_HIGH_vec_fast_csw_thr_high_START (0)
#define SOC_NPU_AICORE_VEC_FCSW_THR_HIGH_vec_fast_csw_thr_high_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_pre_rst_stall : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_VEC_PRE_RST_STALL_CTRL_UNION;
#endif
#define SOC_NPU_AICORE_VEC_PRE_RST_STALL_CTRL_vec_pre_rst_stall_START (0)
#define SOC_NPU_AICORE_VEC_PRE_RST_STALL_CTRL_vec_pre_rst_stall_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_pre_rst_rdy : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_VEC_PRE_RST_STATUS_UNION;
#endif
#define SOC_NPU_AICORE_VEC_PRE_RST_STATUS_vec_pre_rst_rdy_START (0)
#define SOC_NPU_AICORE_VEC_PRE_RST_STATUS_vec_pre_rst_rdy_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_siss_mode_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_VEC_SISS_MODE_EN_CFG_UNION;
#endif
#define SOC_NPU_AICORE_VEC_SISS_MODE_EN_CFG_vec_siss_mode_en_START (0)
#define SOC_NPU_AICORE_VEC_SISS_MODE_EN_CFG_vec_siss_mode_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_dbg_bkpt_en : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_NPU_AICORE_VEC_DBG_HW_BKPT_EN_UNION;
#endif
#define SOC_NPU_AICORE_VEC_DBG_HW_BKPT_EN_vec_dbg_bkpt_en_START (0)
#define SOC_NPU_AICORE_VEC_DBG_HW_BKPT_EN_vec_dbg_bkpt_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_dbg_resume_p : 1;
        unsigned int vec_dbg_ss_p : 1;
        unsigned int vec_dbg_ss_warp_id : 6;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_AICORE_VEC_DBG_CTRL_CFG_UNION;
#endif
#define SOC_NPU_AICORE_VEC_DBG_CTRL_CFG_vec_dbg_resume_p_START (0)
#define SOC_NPU_AICORE_VEC_DBG_CTRL_CFG_vec_dbg_resume_p_END (0)
#define SOC_NPU_AICORE_VEC_DBG_CTRL_CFG_vec_dbg_ss_p_START (1)
#define SOC_NPU_AICORE_VEC_DBG_CTRL_CFG_vec_dbg_ss_p_END (1)
#define SOC_NPU_AICORE_VEC_DBG_CTRL_CFG_vec_dbg_ss_warp_id_START (2)
#define SOC_NPU_AICORE_VEC_DBG_CTRL_CFG_vec_dbg_ss_warp_id_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_dbg_bkpt_hit_p : 1;
        unsigned int vec_dbg_ss_done_p : 1;
        unsigned int vec_dbg_busy : 1;
        unsigned int vec_dbg_arch_mode : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_NPU_AICORE_VEC_DBG_STATUS_UNION;
#endif
#define SOC_NPU_AICORE_VEC_DBG_STATUS_vec_dbg_bkpt_hit_p_START (0)
#define SOC_NPU_AICORE_VEC_DBG_STATUS_vec_dbg_bkpt_hit_p_END (0)
#define SOC_NPU_AICORE_VEC_DBG_STATUS_vec_dbg_ss_done_p_START (1)
#define SOC_NPU_AICORE_VEC_DBG_STATUS_vec_dbg_ss_done_p_END (1)
#define SOC_NPU_AICORE_VEC_DBG_STATUS_vec_dbg_busy_START (2)
#define SOC_NPU_AICORE_VEC_DBG_STATUS_vec_dbg_busy_END (2)
#define SOC_NPU_AICORE_VEC_DBG_STATUS_vec_dbg_arch_mode_START (3)
#define SOC_NPU_AICORE_VEC_DBG_STATUS_vec_dbg_arch_mode_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_dbg_bkpt_sid : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_AICORE_VEC_DBG_BKPT_SID_CFG_UNION;
#endif
#define SOC_NPU_AICORE_VEC_DBG_BKPT_SID_CFG_vec_dbg_bkpt_sid_START (0)
#define SOC_NPU_AICORE_VEC_DBG_BKPT_SID_CFG_vec_dbg_bkpt_sid_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_dbg_bkpt_ssid : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_AICORE_VEC_DBG_BKPT_SSID_CFG_UNION;
#endif
#define SOC_NPU_AICORE_VEC_DBG_BKPT_SSID_CFG_vec_dbg_bkpt_ssid_START (0)
#define SOC_NPU_AICORE_VEC_DBG_BKPT_SSID_CFG_vec_dbg_bkpt_ssid_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_dbg_bkpt_addr : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_AICORE_VEC_DBG_BKPT_ADDR_UNION;
#endif
#define SOC_NPU_AICORE_VEC_DBG_BKPT_ADDR_vec_dbg_bkpt_addr_START (0)
#define SOC_NPU_AICORE_VEC_DBG_BKPT_ADDR_vec_dbg_bkpt_addr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_dbg_bkpt_addr_ext : 30;
        unsigned int reserved : 2;
    } reg;
} SOC_NPU_AICORE_VEC_DBG_BKPT_ADDR_EXT_UNION;
#endif
#define SOC_NPU_AICORE_VEC_DBG_BKPT_ADDR_EXT_vec_dbg_bkpt_addr_ext_START (0)
#define SOC_NPU_AICORE_VEC_DBG_BKPT_ADDR_EXT_vec_dbg_bkpt_addr_ext_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_err_ub_arb_data_excp_mte_t0 : 1;
        unsigned int vec_err_ub_arb_data_excp_su_t0 : 1;
        unsigned int vec_err_ub_arb_data_excp_vec_t0 : 1;
        unsigned int reserved_0 : 3;
        unsigned int vec_err_instr_timeout_t0 : 1;
        unsigned int vec_err_su_pld_undef_t0 : 1;
        unsigned int vec_err_su_pld_ill_cfg_t0 : 1;
        unsigned int vec_err_pc_ovfl_t0 : 1;
        unsigned int vec_err_instr_undef_t0 : 1;
        unsigned int vec_err_instr_ill_cfg_t0 : 1;
        unsigned int vec_err_hwlp_stack_ovfl_t0 : 1;
        unsigned int vec_err_hwlp_instr_num_mismatch_t0 : 1;
        unsigned int vec_err_biu_resp_err_t0 : 1;
        unsigned int vec_err_pb_ecc_mberr_t0 : 1;
        unsigned int vec_err_idata_inf_nan_t0 : 1;
        unsigned int vec_err_div_by_zero_t0 : 1;
        unsigned int vec_err_valu_neg_ln_t0 : 1;
        unsigned int vec_err_valu_neg_sqrt_t0 : 1;
        unsigned int vec_err_instr_misalign_t0 : 1;
        unsigned int vec_err_ub_addr_overflow_t0 : 1;
        unsigned int vec_err_ub_ecc_mberr_t0 : 1;
        unsigned int vec_err_vms_unsort_t0 : 1;
        unsigned int vec_err_csw_data_t0 : 1;
        unsigned int vec_err_sc_cfg_parity_t0 : 1;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_NPU_AICORE_VEC_ERROR_T0_0_UNION;
#endif
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_ub_arb_data_excp_mte_t0_START (0)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_ub_arb_data_excp_mte_t0_END (0)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_ub_arb_data_excp_su_t0_START (1)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_ub_arb_data_excp_su_t0_END (1)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_ub_arb_data_excp_vec_t0_START (2)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_ub_arb_data_excp_vec_t0_END (2)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_instr_timeout_t0_START (6)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_instr_timeout_t0_END (6)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_su_pld_undef_t0_START (7)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_su_pld_undef_t0_END (7)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_su_pld_ill_cfg_t0_START (8)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_su_pld_ill_cfg_t0_END (8)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_pc_ovfl_t0_START (9)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_pc_ovfl_t0_END (9)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_instr_undef_t0_START (10)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_instr_undef_t0_END (10)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_instr_ill_cfg_t0_START (11)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_instr_ill_cfg_t0_END (11)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_hwlp_stack_ovfl_t0_START (12)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_hwlp_stack_ovfl_t0_END (12)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_hwlp_instr_num_mismatch_t0_START (13)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_hwlp_instr_num_mismatch_t0_END (13)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_biu_resp_err_t0_START (14)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_biu_resp_err_t0_END (14)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_pb_ecc_mberr_t0_START (15)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_pb_ecc_mberr_t0_END (15)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_idata_inf_nan_t0_START (16)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_idata_inf_nan_t0_END (16)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_div_by_zero_t0_START (17)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_div_by_zero_t0_END (17)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_valu_neg_ln_t0_START (18)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_valu_neg_ln_t0_END (18)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_valu_neg_sqrt_t0_START (19)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_valu_neg_sqrt_t0_END (19)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_instr_misalign_t0_START (20)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_instr_misalign_t0_END (20)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_ub_addr_overflow_t0_START (21)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_ub_addr_overflow_t0_END (21)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_ub_ecc_mberr_t0_START (22)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_ub_ecc_mberr_t0_END (22)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_vms_unsort_t0_START (23)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_vms_unsort_t0_END (23)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_csw_data_t0_START (24)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_csw_data_t0_END (24)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_sc_cfg_parity_t0_START (25)
#define SOC_NPU_AICORE_VEC_ERROR_T0_0_vec_err_sc_cfg_parity_t0_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int simt_error_set_t0 : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_AICORE_VEC_ERROR_T0_2_UNION;
#endif
#define SOC_NPU_AICORE_VEC_ERROR_T0_2_simt_error_set_t0_START (0)
#define SOC_NPU_AICORE_VEC_ERROR_T0_2_simt_error_set_t0_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_VEC_ERROR_T1_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_VEC_ERROR_T1_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_err_ub_arb_data_excp_mte_mask : 1;
        unsigned int vec_err_ub_arb_data_excp_su_mask : 1;
        unsigned int vec_err_ub_arb_data_excp_vec_mask : 1;
        unsigned int reserved_0 : 3;
        unsigned int vec_err_instr_timeout_mask : 1;
        unsigned int vec_err_su_pld_undef_mask : 1;
        unsigned int vec_err_su_pld_ill_cfg_mask : 1;
        unsigned int vec_err_pc_ovfl_mask : 1;
        unsigned int vec_err_instr_undef_mask : 1;
        unsigned int vec_err_instr_ill_cfg_mask : 1;
        unsigned int vec_err_hwlp_stack_ovfl_mask : 1;
        unsigned int vec_err_hwlp_instr_num_mismatch_mask : 1;
        unsigned int vec_err_biu_resp_err_mask : 1;
        unsigned int vec_err_pb_ecc_mberr_mask : 1;
        unsigned int vec_err_idata_inf_nan_mask : 1;
        unsigned int vec_err_div_by_zero_mask : 1;
        unsigned int vec_err_valu_neg_ln_mask : 1;
        unsigned int vec_err_valu_neg_sqrt_mask : 1;
        unsigned int vec_err_instr_misalign_mask : 1;
        unsigned int vec_err_ub_addr_overflow_mask : 1;
        unsigned int vec_err_ub_ecc_mberr_mask : 1;
        unsigned int vec_err_vms_unsort_mask : 1;
        unsigned int vec_err_csw_data_mask : 1;
        unsigned int vec_err_sc_cfg_parity_mask : 1;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_NPU_AICORE_VEC_ERROR_MASK_0_UNION;
#endif
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_ub_arb_data_excp_mte_mask_START (0)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_ub_arb_data_excp_mte_mask_END (0)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_ub_arb_data_excp_su_mask_START (1)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_ub_arb_data_excp_su_mask_END (1)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_ub_arb_data_excp_vec_mask_START (2)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_ub_arb_data_excp_vec_mask_END (2)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_instr_timeout_mask_START (6)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_instr_timeout_mask_END (6)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_su_pld_undef_mask_START (7)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_su_pld_undef_mask_END (7)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_su_pld_ill_cfg_mask_START (8)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_su_pld_ill_cfg_mask_END (8)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_pc_ovfl_mask_START (9)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_pc_ovfl_mask_END (9)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_instr_undef_mask_START (10)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_instr_undef_mask_END (10)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_instr_ill_cfg_mask_START (11)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_instr_ill_cfg_mask_END (11)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_hwlp_stack_ovfl_mask_START (12)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_hwlp_stack_ovfl_mask_END (12)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_hwlp_instr_num_mismatch_mask_START (13)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_hwlp_instr_num_mismatch_mask_END (13)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_biu_resp_err_mask_START (14)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_biu_resp_err_mask_END (14)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_pb_ecc_mberr_mask_START (15)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_pb_ecc_mberr_mask_END (15)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_idata_inf_nan_mask_START (16)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_idata_inf_nan_mask_END (16)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_div_by_zero_mask_START (17)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_div_by_zero_mask_END (17)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_valu_neg_ln_mask_START (18)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_valu_neg_ln_mask_END (18)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_valu_neg_sqrt_mask_START (19)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_valu_neg_sqrt_mask_END (19)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_instr_misalign_mask_START (20)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_instr_misalign_mask_END (20)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_ub_addr_overflow_mask_START (21)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_ub_addr_overflow_mask_END (21)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_ub_ecc_mberr_mask_START (22)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_ub_ecc_mberr_mask_END (22)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_vms_unsort_mask_START (23)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_vms_unsort_mask_END (23)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_csw_data_mask_START (24)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_csw_data_mask_END (24)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_sc_cfg_parity_mask_START (25)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_0_vec_err_sc_cfg_parity_mask_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int simt_error_set_mask : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_AICORE_VEC_ERROR_MASK_2_UNION;
#endif
#define SOC_NPU_AICORE_VEC_ERROR_MASK_2_simt_error_set_mask_START (0)
#define SOC_NPU_AICORE_VEC_ERROR_MASK_2_simt_error_set_mask_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_err_su_pld_pc_t0 : 16;
        unsigned int vec_err_su_pld_opcode_t0 : 7;
        unsigned int reserved : 9;
    } reg;
} SOC_NPU_AICORE_VEC_ERR_INFO_T0_0_UNION;
#endif
#define SOC_NPU_AICORE_VEC_ERR_INFO_T0_0_vec_err_su_pld_pc_t0_START (0)
#define SOC_NPU_AICORE_VEC_ERR_INFO_T0_0_vec_err_su_pld_pc_t0_END (15)
#define SOC_NPU_AICORE_VEC_ERR_INFO_T0_0_vec_err_su_pld_opcode_t0_START (16)
#define SOC_NPU_AICORE_VEC_ERR_INFO_T0_0_vec_err_su_pld_opcode_t0_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_err_vf_instr_pc_l_t0 : 32;
    } reg;
} SOC_NPU_AICORE_VEC_ERR_INFO_T0_1_UNION;
#endif
#define SOC_NPU_AICORE_VEC_ERR_INFO_T0_1_vec_err_vf_instr_pc_l_t0_START (0)
#define SOC_NPU_AICORE_VEC_ERR_INFO_T0_1_vec_err_vf_instr_pc_l_t0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_err_vf_instr_pc_h_t0 : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_NPU_AICORE_VEC_ERR_INFO_T0_2_UNION;
#endif
#define SOC_NPU_AICORE_VEC_ERR_INFO_T0_2_vec_err_vf_instr_pc_h_t0_START (0)
#define SOC_NPU_AICORE_VEC_ERR_INFO_T0_2_vec_err_vf_instr_pc_h_t0_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_ub_err_addr_l_t0 : 32;
    } reg;
} SOC_NPU_AICORE_VEC_ERR_INFO_T0_3_UNION;
#endif
#define SOC_NPU_AICORE_VEC_ERR_INFO_T0_3_vec_ub_err_addr_l_t0_START (0)
#define SOC_NPU_AICORE_VEC_ERR_INFO_T0_3_vec_ub_err_addr_l_t0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_ub_err_addr_h_t0 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_VEC_ERR_INFO_T0_4_UNION;
#endif
#define SOC_NPU_AICORE_VEC_ERR_INFO_T0_4_vec_ub_err_addr_h_t0_START (0)
#define SOC_NPU_AICORE_VEC_ERR_INFO_T0_4_vec_ub_err_addr_h_t0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int simt_error_set_info_t0 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_VEC_ERR_INFO_T0_5_UNION;
#endif
#define SOC_NPU_AICORE_VEC_ERR_INFO_T0_5_simt_error_set_info_t0_START (0)
#define SOC_NPU_AICORE_VEC_ERR_INFO_T0_5_simt_error_set_info_t0_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_VEC_ERR_INFO_T1_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_VEC_ERR_INFO_T1_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_VEC_ERR_INFO_T1_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_VEC_ERR_INFO_T1_3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_VEC_ERR_INFO_T1_4_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int simt_error_set_info_t1 : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_VEC_ERR_INFO_T1_5_UNION;
#endif
#define SOC_NPU_AICORE_VEC_ERR_INFO_T1_5_simt_error_set_info_t1_START (0)
#define SOC_NPU_AICORE_VEC_ERR_INFO_T1_5_simt_error_set_info_t1_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_warn_fp_undflow_err_t0 : 1;
        unsigned int vec_warn_fp_ovflow_err_t0 : 1;
        unsigned int vec_warn_fp_conv_err_t0 : 1;
        unsigned int vec_warn_src_inf_nan_t0 : 1;
        unsigned int vec_warn_src_ln_neg_t0 : 1;
        unsigned int vec_warn_src_sqrt_neg_t0 : 1;
        unsigned int vec_warn_div0_t0 : 1;
        unsigned int vec_warn_nop_cfg_instr_t0 : 1;
        unsigned int vec_warn_int_ovflow_err_t0 : 1;
        unsigned int vec_warn_simt_set : 2;
        unsigned int reserved : 21;
    } reg;
} SOC_NPU_AICORE_VEC_WARN_T0_0_UNION;
#endif
#define SOC_NPU_AICORE_VEC_WARN_T0_0_vec_warn_fp_undflow_err_t0_START (0)
#define SOC_NPU_AICORE_VEC_WARN_T0_0_vec_warn_fp_undflow_err_t0_END (0)
#define SOC_NPU_AICORE_VEC_WARN_T0_0_vec_warn_fp_ovflow_err_t0_START (1)
#define SOC_NPU_AICORE_VEC_WARN_T0_0_vec_warn_fp_ovflow_err_t0_END (1)
#define SOC_NPU_AICORE_VEC_WARN_T0_0_vec_warn_fp_conv_err_t0_START (2)
#define SOC_NPU_AICORE_VEC_WARN_T0_0_vec_warn_fp_conv_err_t0_END (2)
#define SOC_NPU_AICORE_VEC_WARN_T0_0_vec_warn_src_inf_nan_t0_START (3)
#define SOC_NPU_AICORE_VEC_WARN_T0_0_vec_warn_src_inf_nan_t0_END (3)
#define SOC_NPU_AICORE_VEC_WARN_T0_0_vec_warn_src_ln_neg_t0_START (4)
#define SOC_NPU_AICORE_VEC_WARN_T0_0_vec_warn_src_ln_neg_t0_END (4)
#define SOC_NPU_AICORE_VEC_WARN_T0_0_vec_warn_src_sqrt_neg_t0_START (5)
#define SOC_NPU_AICORE_VEC_WARN_T0_0_vec_warn_src_sqrt_neg_t0_END (5)
#define SOC_NPU_AICORE_VEC_WARN_T0_0_vec_warn_div0_t0_START (6)
#define SOC_NPU_AICORE_VEC_WARN_T0_0_vec_warn_div0_t0_END (6)
#define SOC_NPU_AICORE_VEC_WARN_T0_0_vec_warn_nop_cfg_instr_t0_START (7)
#define SOC_NPU_AICORE_VEC_WARN_T0_0_vec_warn_nop_cfg_instr_t0_END (7)
#define SOC_NPU_AICORE_VEC_WARN_T0_0_vec_warn_int_ovflow_err_t0_START (8)
#define SOC_NPU_AICORE_VEC_WARN_T0_0_vec_warn_int_ovflow_err_t0_END (8)
#define SOC_NPU_AICORE_VEC_WARN_T0_0_vec_warn_simt_set_START (9)
#define SOC_NPU_AICORE_VEC_WARN_T0_0_vec_warn_simt_set_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_VEC_WARN_T1_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_warn_fp_undflow_err_mask : 1;
        unsigned int vec_warn_fp_ovflow_err_mask : 1;
        unsigned int vec_warn_fp_conv_err_mask : 1;
        unsigned int vec_warn_src_inf_nan_mask : 1;
        unsigned int vec_warn_src_ln_neg_mask : 1;
        unsigned int vec_warn_src_sqrt_neg_mask : 1;
        unsigned int vec_warn_div0_mask : 1;
        unsigned int vec_warn_nop_cfg_instr_mask : 1;
        unsigned int vec_warn_int_ovflow_err_mask : 1;
        unsigned int vec_warn_simt_set_mask : 2;
        unsigned int reserved : 21;
    } reg;
} SOC_NPU_AICORE_VEC_WARN_MASK_0_UNION;
#endif
#define SOC_NPU_AICORE_VEC_WARN_MASK_0_vec_warn_fp_undflow_err_mask_START (0)
#define SOC_NPU_AICORE_VEC_WARN_MASK_0_vec_warn_fp_undflow_err_mask_END (0)
#define SOC_NPU_AICORE_VEC_WARN_MASK_0_vec_warn_fp_ovflow_err_mask_START (1)
#define SOC_NPU_AICORE_VEC_WARN_MASK_0_vec_warn_fp_ovflow_err_mask_END (1)
#define SOC_NPU_AICORE_VEC_WARN_MASK_0_vec_warn_fp_conv_err_mask_START (2)
#define SOC_NPU_AICORE_VEC_WARN_MASK_0_vec_warn_fp_conv_err_mask_END (2)
#define SOC_NPU_AICORE_VEC_WARN_MASK_0_vec_warn_src_inf_nan_mask_START (3)
#define SOC_NPU_AICORE_VEC_WARN_MASK_0_vec_warn_src_inf_nan_mask_END (3)
#define SOC_NPU_AICORE_VEC_WARN_MASK_0_vec_warn_src_ln_neg_mask_START (4)
#define SOC_NPU_AICORE_VEC_WARN_MASK_0_vec_warn_src_ln_neg_mask_END (4)
#define SOC_NPU_AICORE_VEC_WARN_MASK_0_vec_warn_src_sqrt_neg_mask_START (5)
#define SOC_NPU_AICORE_VEC_WARN_MASK_0_vec_warn_src_sqrt_neg_mask_END (5)
#define SOC_NPU_AICORE_VEC_WARN_MASK_0_vec_warn_div0_mask_START (6)
#define SOC_NPU_AICORE_VEC_WARN_MASK_0_vec_warn_div0_mask_END (6)
#define SOC_NPU_AICORE_VEC_WARN_MASK_0_vec_warn_nop_cfg_instr_mask_START (7)
#define SOC_NPU_AICORE_VEC_WARN_MASK_0_vec_warn_nop_cfg_instr_mask_END (7)
#define SOC_NPU_AICORE_VEC_WARN_MASK_0_vec_warn_int_ovflow_err_mask_START (8)
#define SOC_NPU_AICORE_VEC_WARN_MASK_0_vec_warn_int_ovflow_err_mask_END (8)
#define SOC_NPU_AICORE_VEC_WARN_MASK_0_vec_warn_simt_set_mask_START (9)
#define SOC_NPU_AICORE_VEC_WARN_MASK_0_vec_warn_simt_set_mask_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_warn_ub_sberr_addr_t0 : 22;
        unsigned int reserved : 10;
    } reg;
} SOC_NPU_AICORE_VEC_WARN_INFO_T0_0_UNION;
#endif
#define SOC_NPU_AICORE_VEC_WARN_INFO_T0_0_vec_warn_ub_sberr_addr_t0_START (0)
#define SOC_NPU_AICORE_VEC_WARN_INFO_T0_0_vec_warn_ub_sberr_addr_t0_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_reserved_reg0 : 32;
    } reg;
} SOC_NPU_AICORE_VEC_RESERVED_REG0_UNION;
#endif
#define SOC_NPU_AICORE_VEC_RESERVED_REG0_vec_reserved_reg0_START (0)
#define SOC_NPU_AICORE_VEC_RESERVED_REG0_vec_reserved_reg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_reserved_reg1 : 32;
    } reg;
} SOC_NPU_AICORE_VEC_RESERVED_REG1_UNION;
#endif
#define SOC_NPU_AICORE_VEC_RESERVED_REG1_vec_reserved_reg1_START (0)
#define SOC_NPU_AICORE_VEC_RESERVED_REG1_vec_reserved_reg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_reserved_ro_reg0 : 32;
    } reg;
} SOC_NPU_AICORE_VEC_RESERVED_RO_REG0_UNION;
#endif
#define SOC_NPU_AICORE_VEC_RESERVED_RO_REG0_vec_reserved_ro_reg0_START (0)
#define SOC_NPU_AICORE_VEC_RESERVED_RO_REG0_vec_reserved_ro_reg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vec_reserved_ro_reg1 : 32;
    } reg;
} SOC_NPU_AICORE_VEC_RESERVED_RO_REG1_UNION;
#endif
#define SOC_NPU_AICORE_VEC_RESERVED_RO_REG1_vec_reserved_ro_reg1_START (0)
#define SOC_NPU_AICORE_VEC_RESERVED_RO_REG1_vec_reserved_ro_reg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_start_dmy_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int cube_start_dmy_max_k_ext_cycle : 4;
        unsigned int cube_start_dmy_cfg_cycle : 6;
        unsigned int reserved_1 : 2;
        unsigned int cube_start_dmy_k_step : 6;
        unsigned int reserved_2 : 2;
        unsigned int cube_start_dmy_k_step_cycle : 6;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
    } reg;
} SOC_NPU_AICORE_CUBE_START_DMY_CTRL_0_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_0_cube_start_dmy_en_START (0)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_0_cube_start_dmy_en_END (0)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_0_cube_start_dmy_max_k_ext_cycle_START (4)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_0_cube_start_dmy_max_k_ext_cycle_END (7)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_0_cube_start_dmy_cfg_cycle_START (8)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_0_cube_start_dmy_cfg_cycle_END (13)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_0_cube_start_dmy_k_step_START (16)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_0_cube_start_dmy_k_step_END (21)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_0_cube_start_dmy_k_step_cycle_START (24)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_0_cube_start_dmy_k_step_cycle_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_start_dmy_max_k_nm : 6;
        unsigned int reserved_0 : 2;
        unsigned int cube_start_dmy_max_k_wo : 6;
        unsigned int reserved_1 : 2;
        unsigned int cube_start_dmy_max_k_dw : 6;
        unsigned int reserved_2 : 2;
        unsigned int cube_start_dmy_max_k_sp : 6;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
    } reg;
} SOC_NPU_AICORE_CUBE_START_DMY_CTRL_1_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_1_cube_start_dmy_max_k_nm_START (0)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_1_cube_start_dmy_max_k_nm_END (5)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_1_cube_start_dmy_max_k_wo_START (8)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_1_cube_start_dmy_max_k_wo_END (13)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_1_cube_start_dmy_max_k_dw_START (16)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_1_cube_start_dmy_max_k_dw_END (21)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_1_cube_start_dmy_max_k_sp_START (24)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_1_cube_start_dmy_max_k_sp_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_start_dmy_init_k : 6;
        unsigned int reserved_0 : 2;
        unsigned int cube_start_dmy_interval_cycle : 6;
        unsigned int reserved_1 : 2;
        unsigned int cube_start_dmy_max_k_gw : 6;
        unsigned int reserved_2 : 2;
        unsigned int reserved_3 : 8;
    } reg;
} SOC_NPU_AICORE_CUBE_START_DMY_CTRL_2_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_2_cube_start_dmy_init_k_START (0)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_2_cube_start_dmy_init_k_END (5)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_2_cube_start_dmy_interval_cycle_START (8)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_2_cube_start_dmy_interval_cycle_END (13)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_2_cube_start_dmy_max_k_gw_START (16)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_2_cube_start_dmy_max_k_gw_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_start_dmy_data_a0 : 8;
        unsigned int cube_start_dmy_data_a1 : 8;
        unsigned int cube_start_dmy_data_b0 : 8;
        unsigned int cube_start_dmy_data_b1 : 8;
    } reg;
} SOC_NPU_AICORE_CUBE_START_DMY_CTRL_3_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_3_cube_start_dmy_data_a0_START (0)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_3_cube_start_dmy_data_a0_END (7)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_3_cube_start_dmy_data_a1_START (8)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_3_cube_start_dmy_data_a1_END (15)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_3_cube_start_dmy_data_b0_START (16)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_3_cube_start_dmy_data_b0_END (23)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_3_cube_start_dmy_data_b1_START (24)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_3_cube_start_dmy_data_b1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_end_dmy_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 4;
        unsigned int cube_end_dmy_cfg_cycle : 6;
        unsigned int reserved_2 : 2;
        unsigned int cube_end_dmy_k_step : 6;
        unsigned int reserved_3 : 2;
        unsigned int cube_end_dmy_k_step_cycle : 6;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
    } reg;
} SOC_NPU_AICORE_CUBE_END_DMY_CTRL_0_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_0_cube_end_dmy_en_START (0)
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_0_cube_end_dmy_en_END (0)
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_0_cube_end_dmy_cfg_cycle_START (8)
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_0_cube_end_dmy_cfg_cycle_END (13)
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_0_cube_end_dmy_k_step_START (16)
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_0_cube_end_dmy_k_step_END (21)
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_0_cube_end_dmy_k_step_cycle_START (24)
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_0_cube_end_dmy_k_step_cycle_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_end_dmy_max_k_nm : 6;
        unsigned int reserved_0 : 2;
        unsigned int cube_end_dmy_max_k_wo : 6;
        unsigned int reserved_1 : 2;
        unsigned int cube_end_dmy_max_k_dw : 6;
        unsigned int reserved_2 : 2;
        unsigned int cube_end_dmy_max_k_sp : 6;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
    } reg;
} SOC_NPU_AICORE_CUBE_END_DMY_CTRL_1_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_1_cube_end_dmy_max_k_nm_START (0)
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_1_cube_end_dmy_max_k_nm_END (5)
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_1_cube_end_dmy_max_k_wo_START (8)
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_1_cube_end_dmy_max_k_wo_END (13)
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_1_cube_end_dmy_max_k_dw_START (16)
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_1_cube_end_dmy_max_k_dw_END (21)
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_1_cube_end_dmy_max_k_sp_START (24)
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_1_cube_end_dmy_max_k_sp_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_end_dmy_last_k : 6;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 6;
        unsigned int reserved_2 : 2;
        unsigned int cube_end_dmy_max_k_gw : 6;
        unsigned int reserved_3 : 2;
        unsigned int reserved_4 : 8;
    } reg;
} SOC_NPU_AICORE_CUBE_END_DMY_CTRL_2_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_2_cube_end_dmy_last_k_START (0)
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_2_cube_end_dmy_last_k_END (5)
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_2_cube_end_dmy_max_k_gw_START (16)
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_2_cube_end_dmy_max_k_gw_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_end_dmy_data_a0 : 8;
        unsigned int cube_end_dmy_data_a1 : 8;
        unsigned int cube_end_dmy_data_b0 : 8;
        unsigned int cube_end_dmy_data_b1 : 8;
    } reg;
} SOC_NPU_AICORE_CUBE_END_DMY_CTRL_3_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_3_cube_end_dmy_data_a0_START (0)
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_3_cube_end_dmy_data_a0_END (7)
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_3_cube_end_dmy_data_a1_START (8)
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_3_cube_end_dmy_data_a1_END (15)
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_3_cube_end_dmy_data_b0_START (16)
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_3_cube_end_dmy_data_b0_END (23)
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_3_cube_end_dmy_data_b1_START (24)
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_3_cube_end_dmy_data_b1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_vdrop_en : 1;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 4;
        unsigned int cube_vdrop_cfg_cycle : 6;
        unsigned int reserved_2 : 2;
        unsigned int cube_vdrop_interval_cycle : 6;
        unsigned int reserved_3 : 9;
        unsigned int reserved_4 : 1;
    } reg;
} SOC_NPU_AICORE_CUBE_VDROP_CTRL_0_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_VDROP_CTRL_0_cube_vdrop_en_START (0)
#define SOC_NPU_AICORE_CUBE_VDROP_CTRL_0_cube_vdrop_en_END (0)
#define SOC_NPU_AICORE_CUBE_VDROP_CTRL_0_cube_vdrop_cfg_cycle_START (8)
#define SOC_NPU_AICORE_CUBE_VDROP_CTRL_0_cube_vdrop_cfg_cycle_END (13)
#define SOC_NPU_AICORE_CUBE_VDROP_CTRL_0_cube_vdrop_interval_cycle_START (16)
#define SOC_NPU_AICORE_CUBE_VDROP_CTRL_0_cube_vdrop_interval_cycle_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_start_dmy_max_k_mm : 6;
        unsigned int reserved_0 : 2;
        unsigned int cube_start_dmy_max_k_cv : 6;
        unsigned int reserved_1 : 2;
        unsigned int cube_start_dmy_early_en : 1;
        unsigned int reserved_2 : 15;
    } reg;
} SOC_NPU_AICORE_CUBE_START_DMY_CTRL_4_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_4_cube_start_dmy_max_k_mm_START (0)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_4_cube_start_dmy_max_k_mm_END (5)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_4_cube_start_dmy_max_k_cv_START (8)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_4_cube_start_dmy_max_k_cv_END (13)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_4_cube_start_dmy_early_en_START (16)
#define SOC_NPU_AICORE_CUBE_START_DMY_CTRL_4_cube_start_dmy_early_en_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_end_dmy_max_k_mm : 6;
        unsigned int reserved_0 : 2;
        unsigned int cube_end_dmy_max_k_cv : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_NPU_AICORE_CUBE_END_DMY_CTRL_4_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_4_cube_end_dmy_max_k_mm_START (0)
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_4_cube_end_dmy_max_k_mm_END (5)
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_4_cube_end_dmy_max_k_cv_START (8)
#define SOC_NPU_AICORE_CUBE_END_DMY_CTRL_4_cube_end_dmy_max_k_cv_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_glb_active_cfg_en : 1;
        unsigned int cube_glb_inactive_cfg_en : 1;
        unsigned int reserved_0 : 2;
        unsigned int cube_glb_active_interval_cycle : 6;
        unsigned int reserved_1 : 21;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_NPU_AICORE_CUBE_ACTIVE_CTRL_0_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_ACTIVE_CTRL_0_cube_glb_active_cfg_en_START (0)
#define SOC_NPU_AICORE_CUBE_ACTIVE_CTRL_0_cube_glb_active_cfg_en_END (0)
#define SOC_NPU_AICORE_CUBE_ACTIVE_CTRL_0_cube_glb_inactive_cfg_en_START (1)
#define SOC_NPU_AICORE_CUBE_ACTIVE_CTRL_0_cube_glb_inactive_cfg_en_END (1)
#define SOC_NPU_AICORE_CUBE_ACTIVE_CTRL_0_cube_glb_active_interval_cycle_START (4)
#define SOC_NPU_AICORE_CUBE_ACTIVE_CTRL_0_cube_glb_active_interval_cycle_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_stall_dmy_cfg : 4;
        unsigned int cube_stall_dmy_en : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_NPU_AICORE_CUBE_STALL_DMY_CTRL_0_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_STALL_DMY_CTRL_0_cube_stall_dmy_cfg_START (0)
#define SOC_NPU_AICORE_CUBE_STALL_DMY_CTRL_0_cube_stall_dmy_cfg_END (3)
#define SOC_NPU_AICORE_CUBE_STALL_DMY_CTRL_0_cube_stall_dmy_en_START (4)
#define SOC_NPU_AICORE_CUBE_STALL_DMY_CTRL_0_cube_stall_dmy_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_stall_dmy_data_a0 : 8;
        unsigned int cube_stall_dmy_data_a1 : 8;
        unsigned int cube_stall_dmy_data_b0 : 8;
        unsigned int cube_stall_dmy_data_b1 : 8;
    } reg;
} SOC_NPU_AICORE_CUBE_STALL_DMY_CTRL_1_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_STALL_DMY_CTRL_1_cube_stall_dmy_data_a0_START (0)
#define SOC_NPU_AICORE_CUBE_STALL_DMY_CTRL_1_cube_stall_dmy_data_a0_END (7)
#define SOC_NPU_AICORE_CUBE_STALL_DMY_CTRL_1_cube_stall_dmy_data_a1_START (8)
#define SOC_NPU_AICORE_CUBE_STALL_DMY_CTRL_1_cube_stall_dmy_data_a1_END (15)
#define SOC_NPU_AICORE_CUBE_STALL_DMY_CTRL_1_cube_stall_dmy_data_b0_START (16)
#define SOC_NPU_AICORE_CUBE_STALL_DMY_CTRL_1_cube_stall_dmy_data_b0_END (23)
#define SOC_NPU_AICORE_CUBE_STALL_DMY_CTRL_1_cube_stall_dmy_data_b1_START (24)
#define SOC_NPU_AICORE_CUBE_STALL_DMY_CTRL_1_cube_stall_dmy_data_b1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_ecc_l0a_en_n : 1;
        unsigned int cube_ecc_l0a_wb_en_n : 1;
        unsigned int cube_ecc_l0b_en_n : 1;
        unsigned int cube_ecc_l0b_wb_en_n : 1;
        unsigned int cube_ecc_l0c_en_n : 1;
        unsigned int cube_ecc_l0c_wb_en_n : 1;
        unsigned int reserved_0 : 25;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_NPU_AICORE_CUBE_ECC_CTRL_0_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_ECC_CTRL_0_cube_ecc_l0a_en_n_START (0)
#define SOC_NPU_AICORE_CUBE_ECC_CTRL_0_cube_ecc_l0a_en_n_END (0)
#define SOC_NPU_AICORE_CUBE_ECC_CTRL_0_cube_ecc_l0a_wb_en_n_START (1)
#define SOC_NPU_AICORE_CUBE_ECC_CTRL_0_cube_ecc_l0a_wb_en_n_END (1)
#define SOC_NPU_AICORE_CUBE_ECC_CTRL_0_cube_ecc_l0b_en_n_START (2)
#define SOC_NPU_AICORE_CUBE_ECC_CTRL_0_cube_ecc_l0b_en_n_END (2)
#define SOC_NPU_AICORE_CUBE_ECC_CTRL_0_cube_ecc_l0b_wb_en_n_START (3)
#define SOC_NPU_AICORE_CUBE_ECC_CTRL_0_cube_ecc_l0b_wb_en_n_END (3)
#define SOC_NPU_AICORE_CUBE_ECC_CTRL_0_cube_ecc_l0c_en_n_START (4)
#define SOC_NPU_AICORE_CUBE_ECC_CTRL_0_cube_ecc_l0c_en_n_END (4)
#define SOC_NPU_AICORE_CUBE_ECC_CTRL_0_cube_ecc_l0c_wb_en_n_START (5)
#define SOC_NPU_AICORE_CUBE_ECC_CTRL_0_cube_ecc_l0c_wb_en_n_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_ecc_l0a_sb_inject_en : 1;
        unsigned int cube_ecc_l0a_mb_inject_en : 1;
        unsigned int cube_ecc_l0a_wino_sb_inject_en : 1;
        unsigned int cube_ecc_l0a_wino_mb_inject_en : 1;
        unsigned int cube_ecc_l0b_sb_inject_en : 1;
        unsigned int cube_ecc_l0b_mb_inject_en : 1;
        unsigned int cube_ecc_l0b_wino_sb_inject_en : 1;
        unsigned int cube_ecc_l0b_wino_mb_inject_en : 1;
        unsigned int cube_ecc_l0c_sb_inject_en : 1;
        unsigned int cube_ecc_l0c_mb_inject_en : 1;
        unsigned int reserved_0 : 21;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_NPU_AICORE_CUBE_ECC_INJECT_CTRL_0_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_CTRL_0_cube_ecc_l0a_sb_inject_en_START (0)
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_CTRL_0_cube_ecc_l0a_sb_inject_en_END (0)
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_CTRL_0_cube_ecc_l0a_mb_inject_en_START (1)
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_CTRL_0_cube_ecc_l0a_mb_inject_en_END (1)
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_CTRL_0_cube_ecc_l0a_wino_sb_inject_en_START (2)
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_CTRL_0_cube_ecc_l0a_wino_sb_inject_en_END (2)
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_CTRL_0_cube_ecc_l0a_wino_mb_inject_en_START (3)
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_CTRL_0_cube_ecc_l0a_wino_mb_inject_en_END (3)
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_CTRL_0_cube_ecc_l0b_sb_inject_en_START (4)
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_CTRL_0_cube_ecc_l0b_sb_inject_en_END (4)
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_CTRL_0_cube_ecc_l0b_mb_inject_en_START (5)
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_CTRL_0_cube_ecc_l0b_mb_inject_en_END (5)
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_CTRL_0_cube_ecc_l0b_wino_sb_inject_en_START (6)
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_CTRL_0_cube_ecc_l0b_wino_sb_inject_en_END (6)
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_CTRL_0_cube_ecc_l0b_wino_mb_inject_en_START (7)
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_CTRL_0_cube_ecc_l0b_wino_mb_inject_en_END (7)
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_CTRL_0_cube_ecc_l0c_sb_inject_en_START (8)
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_CTRL_0_cube_ecc_l0c_sb_inject_en_END (8)
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_CTRL_0_cube_ecc_l0c_mb_inject_en_START (9)
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_CTRL_0_cube_ecc_l0c_mb_inject_en_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_ecc_l0a_inject_bank : 32;
    } reg;
} SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0A_0_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0A_0_cube_ecc_l0a_inject_bank_START (0)
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0A_0_cube_ecc_l0a_inject_bank_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_ecc_l0a_wino_inject_bank : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0A_WINO_0_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0A_WINO_0_cube_ecc_l0a_wino_inject_bank_START (0)
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0A_WINO_0_cube_ecc_l0a_wino_inject_bank_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_ecc_l0b_inject_bank : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0B_0_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0B_0_cube_ecc_l0b_inject_bank_START (0)
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0B_0_cube_ecc_l0b_inject_bank_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_ecc_l0b_wino_inject_bank : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0B_WINO_0_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0B_WINO_0_cube_ecc_l0b_wino_inject_bank_START (0)
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0B_WINO_0_cube_ecc_l0b_wino_inject_bank_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_ecc_l0c_inject_bank_0 : 32;
    } reg;
} SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0C_0_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0C_0_cube_ecc_l0c_inject_bank_0_START (0)
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0C_0_cube_ecc_l0c_inject_bank_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_ecc_l0c_inject_bank_1 : 32;
    } reg;
} SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0C_1_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0C_1_cube_ecc_l0c_inject_bank_1_START (0)
#define SOC_NPU_AICORE_CUBE_ECC_INJECT_BANK_L0C_1_cube_ecc_l0c_inject_bank_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_n2_mode : 1;
        unsigned int cube_dummy_must_s8 : 1;
        unsigned int reserved_0 : 2;
        unsigned int cube_hsw_cnt_range : 6;
        unsigned int cube_l0c_dependency_chk_byp : 1;
        unsigned int cube_sum_man_bw_mask : 2;
        unsigned int reserved_1 : 18;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_NPU_AICORE_CUBE_CTRL_0_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_CTRL_0_cube_n2_mode_START (0)
#define SOC_NPU_AICORE_CUBE_CTRL_0_cube_n2_mode_END (0)
#define SOC_NPU_AICORE_CUBE_CTRL_0_cube_dummy_must_s8_START (1)
#define SOC_NPU_AICORE_CUBE_CTRL_0_cube_dummy_must_s8_END (1)
#define SOC_NPU_AICORE_CUBE_CTRL_0_cube_hsw_cnt_range_START (4)
#define SOC_NPU_AICORE_CUBE_CTRL_0_cube_hsw_cnt_range_END (9)
#define SOC_NPU_AICORE_CUBE_CTRL_0_cube_l0c_dependency_chk_byp_START (10)
#define SOC_NPU_AICORE_CUBE_CTRL_0_cube_l0c_dependency_chk_byp_END (10)
#define SOC_NPU_AICORE_CUBE_CTRL_0_cube_sum_man_bw_mask_START (11)
#define SOC_NPU_AICORE_CUBE_CTRL_0_cube_sum_man_bw_mask_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_clk_en_mask_syscmd : 1;
        unsigned int cube_clk_en_mask_cube : 1;
        unsigned int cube_clk_en_mask_cube_n_mte : 1;
        unsigned int cube_clk_en_mask_cube_n_fixp : 1;
        unsigned int cube_clk_en_mask_clus_fixp : 1;
        unsigned int cube_clk_en_mask_clus_cube_n_fixp : 1;
        unsigned int cube_clk_en_mask_clus_l0b : 1;
        unsigned int cube_clk_en_mask_clus_cube : 1;
        unsigned int cube_clk_en_mask_pe : 1;
        unsigned int reserved_0 : 22;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_NPU_AICORE_CUBE_ICG_MASK_0_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_ICG_MASK_0_cube_clk_en_mask_syscmd_START (0)
#define SOC_NPU_AICORE_CUBE_ICG_MASK_0_cube_clk_en_mask_syscmd_END (0)
#define SOC_NPU_AICORE_CUBE_ICG_MASK_0_cube_clk_en_mask_cube_START (1)
#define SOC_NPU_AICORE_CUBE_ICG_MASK_0_cube_clk_en_mask_cube_END (1)
#define SOC_NPU_AICORE_CUBE_ICG_MASK_0_cube_clk_en_mask_cube_n_mte_START (2)
#define SOC_NPU_AICORE_CUBE_ICG_MASK_0_cube_clk_en_mask_cube_n_mte_END (2)
#define SOC_NPU_AICORE_CUBE_ICG_MASK_0_cube_clk_en_mask_cube_n_fixp_START (3)
#define SOC_NPU_AICORE_CUBE_ICG_MASK_0_cube_clk_en_mask_cube_n_fixp_END (3)
#define SOC_NPU_AICORE_CUBE_ICG_MASK_0_cube_clk_en_mask_clus_fixp_START (4)
#define SOC_NPU_AICORE_CUBE_ICG_MASK_0_cube_clk_en_mask_clus_fixp_END (4)
#define SOC_NPU_AICORE_CUBE_ICG_MASK_0_cube_clk_en_mask_clus_cube_n_fixp_START (5)
#define SOC_NPU_AICORE_CUBE_ICG_MASK_0_cube_clk_en_mask_clus_cube_n_fixp_END (5)
#define SOC_NPU_AICORE_CUBE_ICG_MASK_0_cube_clk_en_mask_clus_l0b_START (6)
#define SOC_NPU_AICORE_CUBE_ICG_MASK_0_cube_clk_en_mask_clus_l0b_END (6)
#define SOC_NPU_AICORE_CUBE_ICG_MASK_0_cube_clk_en_mask_clus_cube_START (7)
#define SOC_NPU_AICORE_CUBE_ICG_MASK_0_cube_clk_en_mask_clus_cube_END (7)
#define SOC_NPU_AICORE_CUBE_ICG_MASK_0_cube_clk_en_mask_pe_START (8)
#define SOC_NPU_AICORE_CUBE_ICG_MASK_0_cube_clk_en_mask_pe_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk_cube_en_mask : 32;
    } reg;
} SOC_NPU_AICORE_CUBE_ICG_MASK_1_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_ICG_MASK_1_clk_cube_en_mask_START (0)
#define SOC_NPU_AICORE_CUBE_ICG_MASK_1_clk_cube_en_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_pi_l0a_en : 1;
        unsigned int reserved_0 : 7;
        unsigned int cube_pi_l0a_mn_force_en : 8;
        unsigned int cube_pi_l0a_min_mul_on : 6;
        unsigned int reserved_1 : 2;
        unsigned int cube_pi_l0a_max_zero : 8;
    } reg;
} SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0A_0_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0A_0_cube_pi_l0a_en_START (0)
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0A_0_cube_pi_l0a_en_END (0)
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0A_0_cube_pi_l0a_mn_force_en_START (8)
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0A_0_cube_pi_l0a_mn_force_en_END (15)
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0A_0_cube_pi_l0a_min_mul_on_START (16)
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0A_0_cube_pi_l0a_min_mul_on_END (21)
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0A_0_cube_pi_l0a_max_zero_START (24)
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0A_0_cube_pi_l0a_max_zero_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_pi_l0a_dmy_data0 : 8;
        unsigned int cube_pi_l0a_dmy_data1 : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0A_1_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0A_1_cube_pi_l0a_dmy_data0_START (0)
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0A_1_cube_pi_l0a_dmy_data0_END (7)
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0A_1_cube_pi_l0a_dmy_data1_START (8)
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0A_1_cube_pi_l0a_dmy_data1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_pi_l0b_en : 1;
        unsigned int reserved_0 : 7;
        unsigned int cube_pi_l0b_mn_force_en : 4;
        unsigned int reserved_1 : 4;
        unsigned int cube_pi_l0b_min_mul_on : 6;
        unsigned int reserved_2 : 2;
        unsigned int cube_pi_l0b_max_zero : 8;
    } reg;
} SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0B_0_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0B_0_cube_pi_l0b_en_START (0)
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0B_0_cube_pi_l0b_en_END (0)
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0B_0_cube_pi_l0b_mn_force_en_START (8)
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0B_0_cube_pi_l0b_mn_force_en_END (11)
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0B_0_cube_pi_l0b_min_mul_on_START (16)
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0B_0_cube_pi_l0b_min_mul_on_END (21)
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0B_0_cube_pi_l0b_max_zero_START (24)
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0B_0_cube_pi_l0b_max_zero_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_pi_l0b_dmy_data0 : 8;
        unsigned int cube_pi_l0b_dmy_data1 : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0B_1_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0B_1_cube_pi_l0b_dmy_data0_START (0)
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0B_1_cube_pi_l0b_dmy_data0_END (7)
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0B_1_cube_pi_l0b_dmy_data1_START (8)
#define SOC_NPU_AICORE_CUBE_PI_DATA_PATTERN_L0B_1_cube_pi_l0b_dmy_data1_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_pre_rst_stall : 1;
        unsigned int reserved_0 : 30;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_NPU_AICORE_CUBE_PRE_RST_STALL_CTRL_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_PRE_RST_STALL_CTRL_cube_pre_rst_stall_START (0)
#define SOC_NPU_AICORE_CUBE_PRE_RST_STALL_CTRL_cube_pre_rst_stall_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_pre_rst_rdy : 1;
        unsigned int reserved_0 : 30;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_NPU_AICORE_CUBE_PRE_RST_STATUS_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_PRE_RST_STATUS_cube_pre_rst_rdy_START (0)
#define SOC_NPU_AICORE_CUBE_PRE_RST_STATUS_cube_pre_rst_rdy_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_err_l0a_rdwr_cflt_t0 : 1;
        unsigned int cube_err_l0b_rdwr_cflt_t0 : 1;
        unsigned int cube_err_l0c_rdwr_cflt_t0 : 1;
        unsigned int cube_err_l0c_self_rdwr_cflt_t0 : 1;
        unsigned int cube_err_invalid_data_t0 : 1;
        unsigned int cube_err_l0a_wrap_around_t0 : 1;
        unsigned int cube_err_l0b_wrap_around_t0 : 1;
        unsigned int cube_err_l0c_wrap_around_t0 : 1;
        unsigned int cube_err_l0a_ecc_mb_error_t0 : 1;
        unsigned int cube_err_l0b_ecc_mb_error_t0 : 1;
        unsigned int cube_err_l0c_ecc_mb_error_t0 : 1;
        unsigned int cube_err_illegal_inst_t0 : 1;
        unsigned int cube_err_hset_cnt_ovf_t0 : 1;
        unsigned int cube_err_hset_cnt_unf_t0 : 1;
        unsigned int cube_err_pbuf_wrap_around_t0 : 1;
        unsigned int cube_err_parity_err_t0 : 1;
        unsigned int reserved_0 : 15;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_NPU_AICORE_CUBE_ERROR_T0_0_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_l0a_rdwr_cflt_t0_START (0)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_l0a_rdwr_cflt_t0_END (0)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_l0b_rdwr_cflt_t0_START (1)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_l0b_rdwr_cflt_t0_END (1)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_l0c_rdwr_cflt_t0_START (2)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_l0c_rdwr_cflt_t0_END (2)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_l0c_self_rdwr_cflt_t0_START (3)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_l0c_self_rdwr_cflt_t0_END (3)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_invalid_data_t0_START (4)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_invalid_data_t0_END (4)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_l0a_wrap_around_t0_START (5)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_l0a_wrap_around_t0_END (5)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_l0b_wrap_around_t0_START (6)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_l0b_wrap_around_t0_END (6)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_l0c_wrap_around_t0_START (7)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_l0c_wrap_around_t0_END (7)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_l0a_ecc_mb_error_t0_START (8)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_l0a_ecc_mb_error_t0_END (8)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_l0b_ecc_mb_error_t0_START (9)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_l0b_ecc_mb_error_t0_END (9)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_l0c_ecc_mb_error_t0_START (10)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_l0c_ecc_mb_error_t0_END (10)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_illegal_inst_t0_START (11)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_illegal_inst_t0_END (11)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_hset_cnt_ovf_t0_START (12)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_hset_cnt_ovf_t0_END (12)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_hset_cnt_unf_t0_START (13)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_hset_cnt_unf_t0_END (13)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_pbuf_wrap_around_t0_START (14)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_pbuf_wrap_around_t0_END (14)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_parity_err_t0_START (15)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_0_cube_err_parity_err_t0_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_instr_undef : 1;
        unsigned int cube_instr_ill_cfg : 1;
        unsigned int cube_instr_addr_misalign : 1;
        unsigned int cube_fm_addr_ovflow : 1;
        unsigned int cube_nonbrc_bias_ovflow : 1;
        unsigned int cube_elw_addr_ovflow : 1;
        unsigned int cube_kernel_addr_ovflow : 1;
        unsigned int cube_fb_addr_ovflow : 1;
        unsigned int cube_bt_addr_ovflow : 1;
        unsigned int cube_result_addr_ovflow : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_AICORE_CUBE_ERROR_T0_1_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_ERROR_T0_1_cube_instr_undef_START (0)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_1_cube_instr_undef_END (0)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_1_cube_instr_ill_cfg_START (1)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_1_cube_instr_ill_cfg_END (1)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_1_cube_instr_addr_misalign_START (2)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_1_cube_instr_addr_misalign_END (2)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_1_cube_fm_addr_ovflow_START (3)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_1_cube_fm_addr_ovflow_END (3)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_1_cube_nonbrc_bias_ovflow_START (4)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_1_cube_nonbrc_bias_ovflow_END (4)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_1_cube_elw_addr_ovflow_START (5)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_1_cube_elw_addr_ovflow_END (5)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_1_cube_kernel_addr_ovflow_START (6)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_1_cube_kernel_addr_ovflow_END (6)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_1_cube_fb_addr_ovflow_START (7)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_1_cube_fb_addr_ovflow_END (7)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_1_cube_bt_addr_ovflow_START (8)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_1_cube_bt_addr_ovflow_END (8)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_1_cube_result_addr_ovflow_START (9)
#define SOC_NPU_AICORE_CUBE_ERROR_T0_1_cube_result_addr_ovflow_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_CUBE_ERROR_T1_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_err_l0a_rdwr_cflt_mask : 1;
        unsigned int cube_err_l0b_rdwr_cflt_mask : 1;
        unsigned int cube_err_l0c_rdwr_cflt_mask : 1;
        unsigned int cube_err_l0c_self_rdwr_cflt_mask : 1;
        unsigned int cube_err_invalid_data_mask : 1;
        unsigned int cube_err_l0a_wrap_around_mask : 1;
        unsigned int cube_err_l0b_wrap_around_mask : 1;
        unsigned int cube_err_l0c_wrap_around_mask : 1;
        unsigned int cube_err_l0a_ecc_mb_error_mask : 1;
        unsigned int cube_err_l0b_ecc_mb_error_mask : 1;
        unsigned int cube_err_l0c_ecc_mb_error_mask : 1;
        unsigned int cube_err_illegal_inst_mask : 1;
        unsigned int cube_err_hset_cnt_ovf_mask : 1;
        unsigned int cube_err_hset_cnt_unf_mask : 1;
        unsigned int cube_err_pbuf_wrap_around_mask : 1;
        unsigned int cube_err_parity_err_mask : 1;
        unsigned int reserved_0 : 15;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_NPU_AICORE_CUBE_ERROR_MASK_0_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_l0a_rdwr_cflt_mask_START (0)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_l0a_rdwr_cflt_mask_END (0)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_l0b_rdwr_cflt_mask_START (1)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_l0b_rdwr_cflt_mask_END (1)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_l0c_rdwr_cflt_mask_START (2)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_l0c_rdwr_cflt_mask_END (2)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_l0c_self_rdwr_cflt_mask_START (3)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_l0c_self_rdwr_cflt_mask_END (3)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_invalid_data_mask_START (4)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_invalid_data_mask_END (4)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_l0a_wrap_around_mask_START (5)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_l0a_wrap_around_mask_END (5)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_l0b_wrap_around_mask_START (6)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_l0b_wrap_around_mask_END (6)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_l0c_wrap_around_mask_START (7)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_l0c_wrap_around_mask_END (7)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_l0a_ecc_mb_error_mask_START (8)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_l0a_ecc_mb_error_mask_END (8)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_l0b_ecc_mb_error_mask_START (9)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_l0b_ecc_mb_error_mask_END (9)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_l0c_ecc_mb_error_mask_START (10)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_l0c_ecc_mb_error_mask_END (10)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_illegal_inst_mask_START (11)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_illegal_inst_mask_END (11)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_hset_cnt_ovf_mask_START (12)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_hset_cnt_ovf_mask_END (12)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_hset_cnt_unf_mask_START (13)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_hset_cnt_unf_mask_END (13)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_pbuf_wrap_around_mask_START (14)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_pbuf_wrap_around_mask_END (14)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_parity_err_mask_START (15)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_0_cube_err_parity_err_mask_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_instr_undef_mask : 1;
        unsigned int cube_instr_ill_cfg_mask : 1;
        unsigned int cube_instr_addr_misalign_mask : 1;
        unsigned int cube_fm_addr_ovflow_mask : 1;
        unsigned int cube_nonbrc_bias_ovflow_mask : 1;
        unsigned int cube_elw_addr_ovflow_mask : 1;
        unsigned int cube_kernel_addr_ovflow_mask : 1;
        unsigned int cube_fb_addr_ovflow_mask : 1;
        unsigned int cube_bt_addr_ovflow_mask : 1;
        unsigned int cube_result_addr_ovflow_mask : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_AICORE_CUBE_ERROR_MASK_1_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_1_cube_instr_undef_mask_START (0)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_1_cube_instr_undef_mask_END (0)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_1_cube_instr_ill_cfg_mask_START (1)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_1_cube_instr_ill_cfg_mask_END (1)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_1_cube_instr_addr_misalign_mask_START (2)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_1_cube_instr_addr_misalign_mask_END (2)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_1_cube_fm_addr_ovflow_mask_START (3)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_1_cube_fm_addr_ovflow_mask_END (3)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_1_cube_nonbrc_bias_ovflow_mask_START (4)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_1_cube_nonbrc_bias_ovflow_mask_END (4)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_1_cube_elw_addr_ovflow_mask_START (5)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_1_cube_elw_addr_ovflow_mask_END (5)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_1_cube_kernel_addr_ovflow_mask_START (6)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_1_cube_kernel_addr_ovflow_mask_END (6)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_1_cube_fb_addr_ovflow_mask_START (7)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_1_cube_fb_addr_ovflow_mask_END (7)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_1_cube_bt_addr_ovflow_mask_START (8)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_1_cube_bt_addr_ovflow_mask_END (8)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_1_cube_result_addr_ovflow_mask_START (9)
#define SOC_NPU_AICORE_CUBE_ERROR_MASK_1_cube_result_addr_ovflow_mask_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_err_addr_t0 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_AICORE_CUBE_ERR_INFO_T0_0_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_ERR_INFO_T0_0_cube_err_addr_t0_START (0)
#define SOC_NPU_AICORE_CUBE_ERR_INFO_T0_0_cube_err_addr_t0_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_err_pc_t0 : 16;
        unsigned int reserved_0 : 15;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_NPU_AICORE_CUBE_ERR_INFO_T0_1_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_ERR_INFO_T0_1_cube_err_pc_t0_START (0)
#define SOC_NPU_AICORE_CUBE_ERR_INFO_T0_1_cube_err_pc_t0_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 16;
        unsigned int reserved_1: 16;
    } reg;
} SOC_NPU_AICORE_CUBE_ERR_INFO_T1_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 16;
        unsigned int reserved_1: 15;
        unsigned int reserved_2: 1;
    } reg;
} SOC_NPU_AICORE_CUBE_ERR_INFO_T1_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_warn_l0a_ecc_sb_t0 : 1;
        unsigned int cube_warn_l0b_ecc_sb_t0 : 1;
        unsigned int cube_warn_l0c_ecc_sb_t0 : 1;
        unsigned int cube_warn_acc_ovf_t0 : 1;
        unsigned int cube_warn_acc_unf_t0 : 1;
        unsigned int cube_warn_l0abc_infnan_t0 : 1;
        unsigned int cube_warn_nop_cfg_instr_t0 : 1;
        unsigned int reserved_0 : 9;
        unsigned int reserved_1 : 15;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_NPU_AICORE_CUBE_WARN_T0_0_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_WARN_T0_0_cube_warn_l0a_ecc_sb_t0_START (0)
#define SOC_NPU_AICORE_CUBE_WARN_T0_0_cube_warn_l0a_ecc_sb_t0_END (0)
#define SOC_NPU_AICORE_CUBE_WARN_T0_0_cube_warn_l0b_ecc_sb_t0_START (1)
#define SOC_NPU_AICORE_CUBE_WARN_T0_0_cube_warn_l0b_ecc_sb_t0_END (1)
#define SOC_NPU_AICORE_CUBE_WARN_T0_0_cube_warn_l0c_ecc_sb_t0_START (2)
#define SOC_NPU_AICORE_CUBE_WARN_T0_0_cube_warn_l0c_ecc_sb_t0_END (2)
#define SOC_NPU_AICORE_CUBE_WARN_T0_0_cube_warn_acc_ovf_t0_START (3)
#define SOC_NPU_AICORE_CUBE_WARN_T0_0_cube_warn_acc_ovf_t0_END (3)
#define SOC_NPU_AICORE_CUBE_WARN_T0_0_cube_warn_acc_unf_t0_START (4)
#define SOC_NPU_AICORE_CUBE_WARN_T0_0_cube_warn_acc_unf_t0_END (4)
#define SOC_NPU_AICORE_CUBE_WARN_T0_0_cube_warn_l0abc_infnan_t0_START (5)
#define SOC_NPU_AICORE_CUBE_WARN_T0_0_cube_warn_l0abc_infnan_t0_END (5)
#define SOC_NPU_AICORE_CUBE_WARN_T0_0_cube_warn_nop_cfg_instr_t0_START (6)
#define SOC_NPU_AICORE_CUBE_WARN_T0_0_cube_warn_nop_cfg_instr_t0_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_CUBE_WARN_T1_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_warn_l0a_ecc_sb_mask : 1;
        unsigned int cube_warn_l0b_ecc_sb_mask : 1;
        unsigned int cube_warn_l0c_ecc_sb_mask : 1;
        unsigned int cube_warn_acc_ovf_mask : 1;
        unsigned int cube_warn_acc_unf_mask : 1;
        unsigned int cube_warn_l0abc_infnan_mask : 1;
        unsigned int cube_warn_nop_cfg_instr_mask : 1;
        unsigned int reserved_0 : 24;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_NPU_AICORE_CUBE_WARN_MASK_0_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_WARN_MASK_0_cube_warn_l0a_ecc_sb_mask_START (0)
#define SOC_NPU_AICORE_CUBE_WARN_MASK_0_cube_warn_l0a_ecc_sb_mask_END (0)
#define SOC_NPU_AICORE_CUBE_WARN_MASK_0_cube_warn_l0b_ecc_sb_mask_START (1)
#define SOC_NPU_AICORE_CUBE_WARN_MASK_0_cube_warn_l0b_ecc_sb_mask_END (1)
#define SOC_NPU_AICORE_CUBE_WARN_MASK_0_cube_warn_l0c_ecc_sb_mask_START (2)
#define SOC_NPU_AICORE_CUBE_WARN_MASK_0_cube_warn_l0c_ecc_sb_mask_END (2)
#define SOC_NPU_AICORE_CUBE_WARN_MASK_0_cube_warn_acc_ovf_mask_START (3)
#define SOC_NPU_AICORE_CUBE_WARN_MASK_0_cube_warn_acc_ovf_mask_END (3)
#define SOC_NPU_AICORE_CUBE_WARN_MASK_0_cube_warn_acc_unf_mask_START (4)
#define SOC_NPU_AICORE_CUBE_WARN_MASK_0_cube_warn_acc_unf_mask_END (4)
#define SOC_NPU_AICORE_CUBE_WARN_MASK_0_cube_warn_l0abc_infnan_mask_START (5)
#define SOC_NPU_AICORE_CUBE_WARN_MASK_0_cube_warn_l0abc_infnan_mask_END (5)
#define SOC_NPU_AICORE_CUBE_WARN_MASK_0_cube_warn_nop_cfg_instr_mask_START (6)
#define SOC_NPU_AICORE_CUBE_WARN_MASK_0_cube_warn_nop_cfg_instr_mask_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_warn_l0a_ecc_addr_t0 : 16;
        unsigned int cube_warn_pc_t0 : 16;
    } reg;
} SOC_NPU_AICORE_CUBE_WARN_INFO_T0_0_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_WARN_INFO_T0_0_cube_warn_l0a_ecc_addr_t0_START (0)
#define SOC_NPU_AICORE_CUBE_WARN_INFO_T0_0_cube_warn_l0a_ecc_addr_t0_END (15)
#define SOC_NPU_AICORE_CUBE_WARN_INFO_T0_0_cube_warn_pc_t0_START (16)
#define SOC_NPU_AICORE_CUBE_WARN_INFO_T0_0_cube_warn_pc_t0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_warn_l0c_ecc_addr_t0 : 16;
        unsigned int cube_warn_l0b_ecc_addr_t0 : 16;
    } reg;
} SOC_NPU_AICORE_CUBE_WARN_INFO_T0_1_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_WARN_INFO_T0_1_cube_warn_l0c_ecc_addr_t0_START (0)
#define SOC_NPU_AICORE_CUBE_WARN_INFO_T0_1_cube_warn_l0c_ecc_addr_t0_END (15)
#define SOC_NPU_AICORE_CUBE_WARN_INFO_T0_1_cube_warn_l0b_ecc_addr_t0_START (16)
#define SOC_NPU_AICORE_CUBE_WARN_INFO_T0_1_cube_warn_l0b_ecc_addr_t0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 16;
        unsigned int reserved_1: 16;
    } reg;
} SOC_NPU_AICORE_CUBE_WARN_INFO_T1_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_reserved_0 : 32;
    } reg;
} SOC_NPU_AICORE_CUBE_RESERVED_REG_0_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_RESERVED_REG_0_cube_reserved_0_START (0)
#define SOC_NPU_AICORE_CUBE_RESERVED_REG_0_cube_reserved_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_reserved_1 : 32;
    } reg;
} SOC_NPU_AICORE_CUBE_RESERVED_REG_1_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_RESERVED_REG_1_cube_reserved_1_START (0)
#define SOC_NPU_AICORE_CUBE_RESERVED_REG_1_cube_reserved_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_reserved_ro_0 : 32;
    } reg;
} SOC_NPU_AICORE_CUBE_RESERVED_RO_REG_0_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_RESERVED_RO_REG_0_cube_reserved_ro_0_START (0)
#define SOC_NPU_AICORE_CUBE_RESERVED_RO_REG_0_cube_reserved_ro_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cube_reserved_ro_1 : 32;
    } reg;
} SOC_NPU_AICORE_CUBE_RESERVED_RO_REG_1_UNION;
#endif
#define SOC_NPU_AICORE_CUBE_RESERVED_RO_REG_1_cube_reserved_ro_1_START (0)
#define SOC_NPU_AICORE_CUBE_RESERVED_RO_REG_1_cube_reserved_ro_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk_l1_en_mask : 32;
    } reg;
} SOC_NPU_AICORE_L1_CLK_GATE_MASK_0_UNION;
#endif
#define SOC_NPU_AICORE_L1_CLK_GATE_MASK_0_clk_l1_en_mask_START (0)
#define SOC_NPU_AICORE_L1_CLK_GATE_MASK_0_clk_l1_en_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk_l1_eff_en_mask : 32;
    } reg;
} SOC_NPU_AICORE_L1_EFF_CLK_GATE_MASK_0_UNION;
#endif
#define SOC_NPU_AICORE_L1_EFF_CLK_GATE_MASK_0_clk_l1_eff_en_mask_START (0)
#define SOC_NPU_AICORE_L1_EFF_CLK_GATE_MASK_0_clk_l1_eff_en_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk_l1_eff_clk_ext_en : 32;
    } reg;
} SOC_NPU_AICORE_L1_EFF_CLK_EXT_EN_UNION;
#endif
#define SOC_NPU_AICORE_L1_EFF_CLK_EXT_EN_clk_l1_eff_clk_ext_en_START (0)
#define SOC_NPU_AICORE_L1_EFF_CLK_EXT_EN_clk_l1_eff_clk_ext_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_ecc_en_n : 1;
        unsigned int l1_ecc_wb_en_n : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_AICORE_L1_ECC_CTRL_0_UNION;
#endif
#define SOC_NPU_AICORE_L1_ECC_CTRL_0_l1_ecc_en_n_START (0)
#define SOC_NPU_AICORE_L1_ECC_CTRL_0_l1_ecc_en_n_END (0)
#define SOC_NPU_AICORE_L1_ECC_CTRL_0_l1_ecc_wb_en_n_START (1)
#define SOC_NPU_AICORE_L1_ECC_CTRL_0_l1_ecc_wb_en_n_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_ecc_sb_inject : 1;
        unsigned int l1_ecc_mb_inject : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_AICORE_L1_ECC_INJECT_CTRL_0_UNION;
#endif
#define SOC_NPU_AICORE_L1_ECC_INJECT_CTRL_0_l1_ecc_sb_inject_START (0)
#define SOC_NPU_AICORE_L1_ECC_INJECT_CTRL_0_l1_ecc_sb_inject_END (0)
#define SOC_NPU_AICORE_L1_ECC_INJECT_CTRL_0_l1_ecc_mb_inject_START (1)
#define SOC_NPU_AICORE_L1_ECC_INJECT_CTRL_0_l1_ecc_mb_inject_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_pre_rst_stall : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_L1_PRE_RST_STALL_CTRL_UNION;
#endif
#define SOC_NPU_AICORE_L1_PRE_RST_STALL_CTRL_l1_pre_rst_stall_START (0)
#define SOC_NPU_AICORE_L1_PRE_RST_STALL_CTRL_l1_pre_rst_stall_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_pre_rst_rdy : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_L1_PRE_RST_STATUS_UNION;
#endif
#define SOC_NPU_AICORE_L1_PRE_RST_STATUS_l1_pre_rst_rdy_START (0)
#define SOC_NPU_AICORE_L1_PRE_RST_STATUS_l1_pre_rst_rdy_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_l0a_rdwr_cflt_t0 : 1;
        unsigned int l1_l0b_rdwr_cflt_t0 : 1;
        unsigned int l1_read_2d_overflow_t0 : 1;
        unsigned int l1_write_2d_overflow_t0 : 1;
        unsigned int l1_dws_pad_conf_err_t0 : 1;
        unsigned int l1_dws_fmap_h_illegal_t0 : 1;
        unsigned int l1_wino_l0b_write_overflow_t0 : 1;
        unsigned int l1_wino_l0b_read_overflow_t0 : 1;
        unsigned int l1_wino_l0a_write_overflow_t0 : 1;
        unsigned int l1_wino_l0a_read_overflow_t0 : 1;
        unsigned int l1_wino_illegal_v_cov_pad_ctl_t0 : 1;
        unsigned int l1_wino_illegal_h_cov_pad_ctl_t0 : 1;
        unsigned int l1_illegal_w_size_t0 : 1;
        unsigned int l1_illegal_h_size_t0 : 1;
        unsigned int l1_illegal_chn_size_t0 : 1;
        unsigned int l1_illegal_k_m_ext_step_t0 : 1;
        unsigned int l1_illegal_k_m_start_pos_t0 : 1;
        unsigned int l1_illegal_schn_cfg_t0 : 1;
        unsigned int l1_illegal_smallk_cfg_t0 : 1;
        unsigned int l1_illegal_fm_size_t0 : 1;
        unsigned int l1_illegal_l1_3d_size_t0 : 1;
        unsigned int l1_illegal_stride_t0 : 1;
        unsigned int l1_padding_cfg_t0 : 1;
        unsigned int l1_read_3d_overflow_t0 : 1;
        unsigned int l1_write_3d_overflow_t0 : 1;
        unsigned int l1_bas_raddr_obound_t0 : 1;
        unsigned int l1_cidx_overflow_t0 : 1;
        unsigned int l1_f1wpos_larger_fsize_t0 : 1;
        unsigned int l1_fmap_less_kernel_t0 : 1;
        unsigned int l1_fmapwh_larger_l1size_t0 : 1;
        unsigned int l1_fpos_larger_fsize_t0 : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_NPU_AICORE_L1_ERROR_T0_0_UNION;
#endif
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_l0a_rdwr_cflt_t0_START (0)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_l0a_rdwr_cflt_t0_END (0)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_l0b_rdwr_cflt_t0_START (1)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_l0b_rdwr_cflt_t0_END (1)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_read_2d_overflow_t0_START (2)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_read_2d_overflow_t0_END (2)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_write_2d_overflow_t0_START (3)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_write_2d_overflow_t0_END (3)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_dws_pad_conf_err_t0_START (4)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_dws_pad_conf_err_t0_END (4)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_dws_fmap_h_illegal_t0_START (5)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_dws_fmap_h_illegal_t0_END (5)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_wino_l0b_write_overflow_t0_START (6)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_wino_l0b_write_overflow_t0_END (6)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_wino_l0b_read_overflow_t0_START (7)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_wino_l0b_read_overflow_t0_END (7)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_wino_l0a_write_overflow_t0_START (8)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_wino_l0a_write_overflow_t0_END (8)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_wino_l0a_read_overflow_t0_START (9)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_wino_l0a_read_overflow_t0_END (9)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_wino_illegal_v_cov_pad_ctl_t0_START (10)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_wino_illegal_v_cov_pad_ctl_t0_END (10)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_wino_illegal_h_cov_pad_ctl_t0_START (11)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_wino_illegal_h_cov_pad_ctl_t0_END (11)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_illegal_w_size_t0_START (12)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_illegal_w_size_t0_END (12)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_illegal_h_size_t0_START (13)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_illegal_h_size_t0_END (13)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_illegal_chn_size_t0_START (14)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_illegal_chn_size_t0_END (14)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_illegal_k_m_ext_step_t0_START (15)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_illegal_k_m_ext_step_t0_END (15)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_illegal_k_m_start_pos_t0_START (16)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_illegal_k_m_start_pos_t0_END (16)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_illegal_schn_cfg_t0_START (17)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_illegal_schn_cfg_t0_END (17)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_illegal_smallk_cfg_t0_START (18)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_illegal_smallk_cfg_t0_END (18)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_illegal_fm_size_t0_START (19)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_illegal_fm_size_t0_END (19)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_illegal_l1_3d_size_t0_START (20)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_illegal_l1_3d_size_t0_END (20)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_illegal_stride_t0_START (21)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_illegal_stride_t0_END (21)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_padding_cfg_t0_START (22)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_padding_cfg_t0_END (22)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_read_3d_overflow_t0_START (23)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_read_3d_overflow_t0_END (23)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_write_3d_overflow_t0_START (24)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_write_3d_overflow_t0_END (24)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_bas_raddr_obound_t0_START (25)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_bas_raddr_obound_t0_END (25)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_cidx_overflow_t0_START (26)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_cidx_overflow_t0_END (26)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_f1wpos_larger_fsize_t0_START (27)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_f1wpos_larger_fsize_t0_END (27)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_fmap_less_kernel_t0_START (28)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_fmap_less_kernel_t0_END (28)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_fmapwh_larger_l1size_t0_START (29)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_fmapwh_larger_l1size_t0_END (29)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_fpos_larger_fsize_t0_START (30)
#define SOC_NPU_AICORE_L1_ERROR_T0_0_l1_fpos_larger_fsize_t0_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_err_fifo_parity_t0 : 1;
        unsigned int fixp_biu_rdwr_resp_t0 : 1;
        unsigned int fixp_stb_ecc_err_t0 : 1;
        unsigned int fixp_fbuf_wr_overflow_t0 : 1;
        unsigned int fixp_fbuf_rd_overflow_t0 : 1;
        unsigned int fixp_out_wr_overflow_t0 : 1;
        unsigned int fixp_l1_wr_overflow_t0 : 1;
        unsigned int fixp_l1_rd_overflow_t0 : 1;
        unsigned int fixp_l0c_rd_overflow_t0 : 1;
        unsigned int fixp_illegal_cfg_t0 : 1;
        unsigned int fixp_addr_misalgn_t0 : 1;
        unsigned int fixp_l0c_ecc_t0 : 1;
        unsigned int fixp_l0c_rdwr_cflt_t0 : 1;
        unsigned int fixp_ub_wr_overflow_t0 : 1;
        unsigned int l1_ub_wr_ovflw_t0 : 1;
        unsigned int l1_waitset_err_t0 : 1;
        unsigned int l1_l1_ecc_t0 : 1;
        unsigned int l1_gdma_read_overflow_t0 : 1;
        unsigned int l1_gdma_write_overflow_t0 : 1;
        unsigned int l1_instr_illegal_cfg_t0 : 1;
        unsigned int l1_instr_addr_misalign_t0 : 1;
        unsigned int l1_sc_cfg_parity_t0 : 1;
        unsigned int reserved : 10;
    } reg;
} SOC_NPU_AICORE_L1_ERROR_T0_1_UNION;
#endif
#define SOC_NPU_AICORE_L1_ERROR_T0_1_l1_err_fifo_parity_t0_START (0)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_l1_err_fifo_parity_t0_END (0)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_fixp_biu_rdwr_resp_t0_START (1)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_fixp_biu_rdwr_resp_t0_END (1)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_fixp_stb_ecc_err_t0_START (2)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_fixp_stb_ecc_err_t0_END (2)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_fixp_fbuf_wr_overflow_t0_START (3)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_fixp_fbuf_wr_overflow_t0_END (3)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_fixp_fbuf_rd_overflow_t0_START (4)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_fixp_fbuf_rd_overflow_t0_END (4)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_fixp_out_wr_overflow_t0_START (5)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_fixp_out_wr_overflow_t0_END (5)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_fixp_l1_wr_overflow_t0_START (6)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_fixp_l1_wr_overflow_t0_END (6)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_fixp_l1_rd_overflow_t0_START (7)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_fixp_l1_rd_overflow_t0_END (7)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_fixp_l0c_rd_overflow_t0_START (8)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_fixp_l0c_rd_overflow_t0_END (8)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_fixp_illegal_cfg_t0_START (9)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_fixp_illegal_cfg_t0_END (9)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_fixp_addr_misalgn_t0_START (10)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_fixp_addr_misalgn_t0_END (10)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_fixp_l0c_ecc_t0_START (11)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_fixp_l0c_ecc_t0_END (11)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_fixp_l0c_rdwr_cflt_t0_START (12)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_fixp_l0c_rdwr_cflt_t0_END (12)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_fixp_ub_wr_overflow_t0_START (13)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_fixp_ub_wr_overflow_t0_END (13)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_l1_ub_wr_ovflw_t0_START (14)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_l1_ub_wr_ovflw_t0_END (14)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_l1_waitset_err_t0_START (15)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_l1_waitset_err_t0_END (15)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_l1_l1_ecc_t0_START (16)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_l1_l1_ecc_t0_END (16)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_l1_gdma_read_overflow_t0_START (17)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_l1_gdma_read_overflow_t0_END (17)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_l1_gdma_write_overflow_t0_START (18)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_l1_gdma_write_overflow_t0_END (18)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_l1_instr_illegal_cfg_t0_START (19)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_l1_instr_illegal_cfg_t0_END (19)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_l1_instr_addr_misalign_t0_START (20)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_l1_instr_addr_misalign_t0_END (20)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_l1_sc_cfg_parity_t0_START (21)
#define SOC_NPU_AICORE_L1_ERROR_T0_1_l1_sc_cfg_parity_t0_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_L1_ERROR_T1_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_L1_ERROR_T1_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_l0a_rdwr_cflt_mask : 1;
        unsigned int l1_l0b_rdwr_cflt_mask : 1;
        unsigned int l1_read_2d_overflow_mask : 1;
        unsigned int l1_write_2d_overflow_mask : 1;
        unsigned int l1_dws_pad_conf_err_mask : 1;
        unsigned int l1_dws_fmap_h_illegal_mask : 1;
        unsigned int l1_wino_l0b_write_overflow_mask : 1;
        unsigned int l1_wino_l0b_read_overflow_mask : 1;
        unsigned int l1_wino_l0a_write_overflow_mask : 1;
        unsigned int l1_wino_l0a_read_overflow_mask : 1;
        unsigned int l1_wino_illegal_v_cov_pad_ctl_mask : 1;
        unsigned int l1_wino_illegal_h_cov_pad_ctl_mask : 1;
        unsigned int l1_illegal_w_size_mask : 1;
        unsigned int l1_illegal_h_size_mask : 1;
        unsigned int l1_illegal_chn_size_mask : 1;
        unsigned int l1_illegal_k_m_ext_step_mask : 1;
        unsigned int l1_illegal_k_m_start_pos_mask : 1;
        unsigned int l1_illegal_schn_cfg_mask : 1;
        unsigned int l1_illegal_smallk_cfg_mask : 1;
        unsigned int l1_illegal_fm_size_mask : 1;
        unsigned int l1_illegal_l1_3d_size_mask : 1;
        unsigned int l1_illegal_stride_mask : 1;
        unsigned int l1_padding_cfg_mask : 1;
        unsigned int l1_read_3d_overflow_mask : 1;
        unsigned int l1_write_3d_overflow_mask : 1;
        unsigned int l1_bas_raddr_obound_mask : 1;
        unsigned int l1_cidx_overflow_mask : 1;
        unsigned int l1_f1wpos_larger_fsize_mask : 1;
        unsigned int l1_fmap_less_kernel_mask : 1;
        unsigned int l1_fmapwh_larger_l1size_mask : 1;
        unsigned int l1_fpos_larger_fsize_mask : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_NPU_AICORE_L1_ERROR_MASK_0_UNION;
#endif
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_l0a_rdwr_cflt_mask_START (0)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_l0a_rdwr_cflt_mask_END (0)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_l0b_rdwr_cflt_mask_START (1)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_l0b_rdwr_cflt_mask_END (1)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_read_2d_overflow_mask_START (2)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_read_2d_overflow_mask_END (2)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_write_2d_overflow_mask_START (3)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_write_2d_overflow_mask_END (3)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_dws_pad_conf_err_mask_START (4)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_dws_pad_conf_err_mask_END (4)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_dws_fmap_h_illegal_mask_START (5)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_dws_fmap_h_illegal_mask_END (5)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_wino_l0b_write_overflow_mask_START (6)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_wino_l0b_write_overflow_mask_END (6)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_wino_l0b_read_overflow_mask_START (7)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_wino_l0b_read_overflow_mask_END (7)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_wino_l0a_write_overflow_mask_START (8)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_wino_l0a_write_overflow_mask_END (8)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_wino_l0a_read_overflow_mask_START (9)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_wino_l0a_read_overflow_mask_END (9)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_wino_illegal_v_cov_pad_ctl_mask_START (10)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_wino_illegal_v_cov_pad_ctl_mask_END (10)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_wino_illegal_h_cov_pad_ctl_mask_START (11)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_wino_illegal_h_cov_pad_ctl_mask_END (11)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_illegal_w_size_mask_START (12)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_illegal_w_size_mask_END (12)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_illegal_h_size_mask_START (13)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_illegal_h_size_mask_END (13)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_illegal_chn_size_mask_START (14)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_illegal_chn_size_mask_END (14)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_illegal_k_m_ext_step_mask_START (15)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_illegal_k_m_ext_step_mask_END (15)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_illegal_k_m_start_pos_mask_START (16)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_illegal_k_m_start_pos_mask_END (16)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_illegal_schn_cfg_mask_START (17)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_illegal_schn_cfg_mask_END (17)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_illegal_smallk_cfg_mask_START (18)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_illegal_smallk_cfg_mask_END (18)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_illegal_fm_size_mask_START (19)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_illegal_fm_size_mask_END (19)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_illegal_l1_3d_size_mask_START (20)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_illegal_l1_3d_size_mask_END (20)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_illegal_stride_mask_START (21)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_illegal_stride_mask_END (21)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_padding_cfg_mask_START (22)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_padding_cfg_mask_END (22)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_read_3d_overflow_mask_START (23)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_read_3d_overflow_mask_END (23)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_write_3d_overflow_mask_START (24)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_write_3d_overflow_mask_END (24)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_bas_raddr_obound_mask_START (25)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_bas_raddr_obound_mask_END (25)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_cidx_overflow_mask_START (26)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_cidx_overflow_mask_END (26)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_f1wpos_larger_fsize_mask_START (27)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_f1wpos_larger_fsize_mask_END (27)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_fmap_less_kernel_mask_START (28)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_fmap_less_kernel_mask_END (28)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_fmapwh_larger_l1size_mask_START (29)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_fmapwh_larger_l1size_mask_END (29)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_fpos_larger_fsize_mask_START (30)
#define SOC_NPU_AICORE_L1_ERROR_MASK_0_l1_fpos_larger_fsize_mask_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_err_fifo_parity_mask : 1;
        unsigned int fixp_biu_rdwr_resp_mask : 1;
        unsigned int fixp_stb_ecc_err_mask : 1;
        unsigned int fixp_fbuf_wr_overflow_mask : 1;
        unsigned int fixp_fbuf_rd_overflow_mask : 1;
        unsigned int fixp_out_wr_overflow_mask : 1;
        unsigned int fixp_l1_wr_overflow_mask : 1;
        unsigned int fixp_l1_rd_overflow_mask : 1;
        unsigned int fixp_l0c_rd_overflow_mask : 1;
        unsigned int fixp_illegal_cfg_mask : 1;
        unsigned int fixp_addr_misalgn_mask : 1;
        unsigned int fixp_l0c_ecc_mask : 1;
        unsigned int fixp_l0c_rdwr_cflt_mask : 1;
        unsigned int fixp_ub_wr_overflow_mask : 1;
        unsigned int l1_ub_wr_ovflw_mask : 1;
        unsigned int l1_waitset_err_mask : 1;
        unsigned int l1_l1_ecc_mask : 1;
        unsigned int l1_gdma_read_overflow_mask : 1;
        unsigned int l1_gdma_write_overflow_mask : 1;
        unsigned int l1_instr_illegal_cfg_mask : 1;
        unsigned int l1_instr_addr_misalign_mask : 1;
        unsigned int l1_sc_cfg_parity_mask : 1;
        unsigned int reserved : 10;
    } reg;
} SOC_NPU_AICORE_L1_ERROR_MASK_1_UNION;
#endif
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_l1_err_fifo_parity_mask_START (0)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_l1_err_fifo_parity_mask_END (0)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_fixp_biu_rdwr_resp_mask_START (1)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_fixp_biu_rdwr_resp_mask_END (1)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_fixp_stb_ecc_err_mask_START (2)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_fixp_stb_ecc_err_mask_END (2)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_fixp_fbuf_wr_overflow_mask_START (3)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_fixp_fbuf_wr_overflow_mask_END (3)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_fixp_fbuf_rd_overflow_mask_START (4)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_fixp_fbuf_rd_overflow_mask_END (4)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_fixp_out_wr_overflow_mask_START (5)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_fixp_out_wr_overflow_mask_END (5)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_fixp_l1_wr_overflow_mask_START (6)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_fixp_l1_wr_overflow_mask_END (6)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_fixp_l1_rd_overflow_mask_START (7)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_fixp_l1_rd_overflow_mask_END (7)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_fixp_l0c_rd_overflow_mask_START (8)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_fixp_l0c_rd_overflow_mask_END (8)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_fixp_illegal_cfg_mask_START (9)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_fixp_illegal_cfg_mask_END (9)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_fixp_addr_misalgn_mask_START (10)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_fixp_addr_misalgn_mask_END (10)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_fixp_l0c_ecc_mask_START (11)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_fixp_l0c_ecc_mask_END (11)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_fixp_l0c_rdwr_cflt_mask_START (12)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_fixp_l0c_rdwr_cflt_mask_END (12)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_fixp_ub_wr_overflow_mask_START (13)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_fixp_ub_wr_overflow_mask_END (13)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_l1_ub_wr_ovflw_mask_START (14)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_l1_ub_wr_ovflw_mask_END (14)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_l1_waitset_err_mask_START (15)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_l1_waitset_err_mask_END (15)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_l1_l1_ecc_mask_START (16)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_l1_l1_ecc_mask_END (16)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_l1_gdma_read_overflow_mask_START (17)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_l1_gdma_read_overflow_mask_END (17)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_l1_gdma_write_overflow_mask_START (18)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_l1_gdma_write_overflow_mask_END (18)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_l1_instr_illegal_cfg_mask_START (19)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_l1_instr_illegal_cfg_mask_END (19)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_l1_instr_addr_misalign_mask_START (20)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_l1_instr_addr_misalign_mask_END (20)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_l1_sc_cfg_parity_mask_START (21)
#define SOC_NPU_AICORE_L1_ERROR_MASK_1_l1_sc_cfg_parity_mask_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_err_addr_t0 : 16;
        unsigned int l1_err_type_t0 : 8;
        unsigned int reserved : 8;
    } reg;
} SOC_NPU_AICORE_L1_ERR_INFO_T0_0_UNION;
#endif
#define SOC_NPU_AICORE_L1_ERR_INFO_T0_0_l1_err_addr_t0_START (0)
#define SOC_NPU_AICORE_L1_ERR_INFO_T0_0_l1_err_addr_t0_END (15)
#define SOC_NPU_AICORE_L1_ERR_INFO_T0_0_l1_err_type_t0_START (16)
#define SOC_NPU_AICORE_L1_ERR_INFO_T0_0_l1_err_type_t0_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_err_pc_t0 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_AICORE_L1_ERR_INFO_T0_1_UNION;
#endif
#define SOC_NPU_AICORE_L1_ERR_INFO_T0_1_l1_err_pc_t0_START (0)
#define SOC_NPU_AICORE_L1_ERR_INFO_T0_1_l1_err_pc_t0_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_L1_ERR_INFO_T1_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_L1_ERR_INFO_T1_1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int warn_mte1_nop_cfg_instr_t0 : 1;
        unsigned int warn_fixp_nop_cfg_instr_t0 : 1;
        unsigned int warn_fixp_ovflow_err_t0 : 1;
        unsigned int warn_fixp_nan_inf_t0 : 1;
        unsigned int warn_fixp_conv_err_t0 : 1;
        unsigned int warn_fixp_stb_1bitecc_t0 : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_NPU_AICORE_L1_WARN_T0_0_UNION;
#endif
#define SOC_NPU_AICORE_L1_WARN_T0_0_warn_mte1_nop_cfg_instr_t0_START (0)
#define SOC_NPU_AICORE_L1_WARN_T0_0_warn_mte1_nop_cfg_instr_t0_END (0)
#define SOC_NPU_AICORE_L1_WARN_T0_0_warn_fixp_nop_cfg_instr_t0_START (1)
#define SOC_NPU_AICORE_L1_WARN_T0_0_warn_fixp_nop_cfg_instr_t0_END (1)
#define SOC_NPU_AICORE_L1_WARN_T0_0_warn_fixp_ovflow_err_t0_START (2)
#define SOC_NPU_AICORE_L1_WARN_T0_0_warn_fixp_ovflow_err_t0_END (2)
#define SOC_NPU_AICORE_L1_WARN_T0_0_warn_fixp_nan_inf_t0_START (3)
#define SOC_NPU_AICORE_L1_WARN_T0_0_warn_fixp_nan_inf_t0_END (3)
#define SOC_NPU_AICORE_L1_WARN_T0_0_warn_fixp_conv_err_t0_START (4)
#define SOC_NPU_AICORE_L1_WARN_T0_0_warn_fixp_conv_err_t0_END (4)
#define SOC_NPU_AICORE_L1_WARN_T0_0_warn_fixp_stb_1bitecc_t0_START (5)
#define SOC_NPU_AICORE_L1_WARN_T0_0_warn_fixp_stb_1bitecc_t0_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_AICORE_L1_WARN_T1_0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int warn_mte1_nop_cfg_instr_mask : 1;
        unsigned int warn_fixp_nop_cfg_instr_mask : 1;
        unsigned int warn_fixp_ovflow_err_mask : 1;
        unsigned int warn_fixp_nan_inf_mask : 1;
        unsigned int warn_fixp_conv_err_mask : 1;
        unsigned int warn_fixp_stb_1bitecc_mask : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_NPU_AICORE_L1_WARN_MASK_0_UNION;
#endif
#define SOC_NPU_AICORE_L1_WARN_MASK_0_warn_mte1_nop_cfg_instr_mask_START (0)
#define SOC_NPU_AICORE_L1_WARN_MASK_0_warn_mte1_nop_cfg_instr_mask_END (0)
#define SOC_NPU_AICORE_L1_WARN_MASK_0_warn_fixp_nop_cfg_instr_mask_START (1)
#define SOC_NPU_AICORE_L1_WARN_MASK_0_warn_fixp_nop_cfg_instr_mask_END (1)
#define SOC_NPU_AICORE_L1_WARN_MASK_0_warn_fixp_ovflow_err_mask_START (2)
#define SOC_NPU_AICORE_L1_WARN_MASK_0_warn_fixp_ovflow_err_mask_END (2)
#define SOC_NPU_AICORE_L1_WARN_MASK_0_warn_fixp_nan_inf_mask_START (3)
#define SOC_NPU_AICORE_L1_WARN_MASK_0_warn_fixp_nan_inf_mask_END (3)
#define SOC_NPU_AICORE_L1_WARN_MASK_0_warn_fixp_conv_err_mask_START (4)
#define SOC_NPU_AICORE_L1_WARN_MASK_0_warn_fixp_conv_err_mask_END (4)
#define SOC_NPU_AICORE_L1_WARN_MASK_0_warn_fixp_stb_1bitecc_mask_START (5)
#define SOC_NPU_AICORE_L1_WARN_MASK_0_warn_fixp_stb_1bitecc_mask_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_warn_l1_ecc_1bit_addr : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_NPU_AICORE_L1_1BIT_ECC_ERR_ADDR_0_UNION;
#endif
#define SOC_NPU_AICORE_L1_1BIT_ECC_ERR_ADDR_0_l1_warn_l1_ecc_1bit_addr_START (0)
#define SOC_NPU_AICORE_L1_1BIT_ECC_ERR_ADDR_0_l1_warn_l1_ecc_1bit_addr_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_sid_hw_remap_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_AICORE_L1_FIXP_CTRL_UNION;
#endif
#define SOC_NPU_AICORE_L1_FIXP_CTRL_l1_sid_hw_remap_en_START (0)
#define SOC_NPU_AICORE_L1_FIXP_CTRL_l1_sid_hw_remap_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_reserved_ro_reg0 : 32;
    } reg;
} SOC_NPU_AICORE_L1_RESERVED_RO_REG0_UNION;
#endif
#define SOC_NPU_AICORE_L1_RESERVED_RO_REG0_l1_reserved_ro_reg0_START (0)
#define SOC_NPU_AICORE_L1_RESERVED_RO_REG0_l1_reserved_ro_reg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_reserved_ro_reg1 : 32;
    } reg;
} SOC_NPU_AICORE_L1_RESERVED_RO_REG1_UNION;
#endif
#define SOC_NPU_AICORE_L1_RESERVED_RO_REG1_l1_reserved_ro_reg1_START (0)
#define SOC_NPU_AICORE_L1_RESERVED_RO_REG1_l1_reserved_ro_reg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_reserved_rw_reg0 : 32;
    } reg;
} SOC_NPU_AICORE_L1_RESERVED_RW_REG0_UNION;
#endif
#define SOC_NPU_AICORE_L1_RESERVED_RW_REG0_l1_reserved_rw_reg0_START (0)
#define SOC_NPU_AICORE_L1_RESERVED_RW_REG0_l1_reserved_rw_reg0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_reserved_rw_reg1 : 32;
    } reg;
} SOC_NPU_AICORE_L1_RESERVED_RW_REG1_UNION;
#endif
#define SOC_NPU_AICORE_L1_RESERVED_RW_REG1_l1_reserved_rw_reg1_START (0)
#define SOC_NPU_AICORE_L1_RESERVED_RW_REG1_l1_reserved_rw_reg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bus_cfg_awcache : 4;
        unsigned int bus_cfg_awuser_snpattr : 1;
        unsigned int bus_cfg_awuser_ssv : 1;
        unsigned int bus_cfg_awuser_fa : 1;
        unsigned int bus_cfg_awuser_fna : 1;
        unsigned int bus_cfg_awregion : 4;
        unsigned int bus_cfg_awqos : 4;
        unsigned int bus_cfg_arcache : 4;
        unsigned int bus_cfg_aruser_snpattr : 1;
        unsigned int bus_cfg_aruser_ssv : 1;
        unsigned int bus_cfg_aruser_fa : 1;
        unsigned int bus_cfg_aruser_fna : 1;
        unsigned int bus_cfg_arregion : 4;
        unsigned int bus_cfg_arqos : 4;
    } reg;
} SOC_NPU_AICORE_BIF_BUS_CFG_UNION;
#endif
#define SOC_NPU_AICORE_BIF_BUS_CFG_bus_cfg_awcache_START (0)
#define SOC_NPU_AICORE_BIF_BUS_CFG_bus_cfg_awcache_END (3)
#define SOC_NPU_AICORE_BIF_BUS_CFG_bus_cfg_awuser_snpattr_START (4)
#define SOC_NPU_AICORE_BIF_BUS_CFG_bus_cfg_awuser_snpattr_END (4)
#define SOC_NPU_AICORE_BIF_BUS_CFG_bus_cfg_awuser_ssv_START (5)
#define SOC_NPU_AICORE_BIF_BUS_CFG_bus_cfg_awuser_ssv_END (5)
#define SOC_NPU_AICORE_BIF_BUS_CFG_bus_cfg_awuser_fa_START (6)
#define SOC_NPU_AICORE_BIF_BUS_CFG_bus_cfg_awuser_fa_END (6)
#define SOC_NPU_AICORE_BIF_BUS_CFG_bus_cfg_awuser_fna_START (7)
#define SOC_NPU_AICORE_BIF_BUS_CFG_bus_cfg_awuser_fna_END (7)
#define SOC_NPU_AICORE_BIF_BUS_CFG_bus_cfg_awregion_START (8)
#define SOC_NPU_AICORE_BIF_BUS_CFG_bus_cfg_awregion_END (11)
#define SOC_NPU_AICORE_BIF_BUS_CFG_bus_cfg_awqos_START (12)
#define SOC_NPU_AICORE_BIF_BUS_CFG_bus_cfg_awqos_END (15)
#define SOC_NPU_AICORE_BIF_BUS_CFG_bus_cfg_arcache_START (16)
#define SOC_NPU_AICORE_BIF_BUS_CFG_bus_cfg_arcache_END (19)
#define SOC_NPU_AICORE_BIF_BUS_CFG_bus_cfg_aruser_snpattr_START (20)
#define SOC_NPU_AICORE_BIF_BUS_CFG_bus_cfg_aruser_snpattr_END (20)
#define SOC_NPU_AICORE_BIF_BUS_CFG_bus_cfg_aruser_ssv_START (21)
#define SOC_NPU_AICORE_BIF_BUS_CFG_bus_cfg_aruser_ssv_END (21)
#define SOC_NPU_AICORE_BIF_BUS_CFG_bus_cfg_aruser_fa_START (22)
#define SOC_NPU_AICORE_BIF_BUS_CFG_bus_cfg_aruser_fa_END (22)
#define SOC_NPU_AICORE_BIF_BUS_CFG_bus_cfg_aruser_fna_START (23)
#define SOC_NPU_AICORE_BIF_BUS_CFG_bus_cfg_aruser_fna_END (23)
#define SOC_NPU_AICORE_BIF_BUS_CFG_bus_cfg_arregion_START (24)
#define SOC_NPU_AICORE_BIF_BUS_CFG_bus_cfg_arregion_END (27)
#define SOC_NPU_AICORE_BIF_BUS_CFG_bus_cfg_arqos_START (28)
#define SOC_NPU_AICORE_BIF_BUS_CFG_bus_cfg_arqos_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bif_smmu_streamid : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_AICORE_BIF_SMMU_STREAMID_UNION;
#endif
#define SOC_NPU_AICORE_BIF_SMMU_STREAMID_bif_smmu_streamid_START (0)
#define SOC_NPU_AICORE_BIF_SMMU_STREAMID_bif_smmu_streamid_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dyn_ar_ostd_wl1 : 8;
        unsigned int dyn_ar_ostd_wl2 : 8;
        unsigned int dyn_ar_ostd_wl3 : 8;
        unsigned int dyn_ar_ostd_mode : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_NPU_AICORE_BIF_DYN_AR_CORE_OST_UNION;
#endif
#define SOC_NPU_AICORE_BIF_DYN_AR_CORE_OST_dyn_ar_ostd_wl1_START (0)
#define SOC_NPU_AICORE_BIF_DYN_AR_CORE_OST_dyn_ar_ostd_wl1_END (7)
#define SOC_NPU_AICORE_BIF_DYN_AR_CORE_OST_dyn_ar_ostd_wl2_START (8)
#define SOC_NPU_AICORE_BIF_DYN_AR_CORE_OST_dyn_ar_ostd_wl2_END (15)
#define SOC_NPU_AICORE_BIF_DYN_AR_CORE_OST_dyn_ar_ostd_wl3_START (16)
#define SOC_NPU_AICORE_BIF_DYN_AR_CORE_OST_dyn_ar_ostd_wl3_END (23)
#define SOC_NPU_AICORE_BIF_DYN_AR_CORE_OST_dyn_ar_ostd_mode_START (24)
#define SOC_NPU_AICORE_BIF_DYN_AR_CORE_OST_dyn_ar_ostd_mode_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dyn_aw_ostd_wl1 : 8;
        unsigned int dyn_aw_ostd_wl2 : 8;
        unsigned int dyn_aw_ostd_wl3 : 8;
        unsigned int dyn_aw_ostd_mode : 1;
        unsigned int reserved : 7;
    } reg;
} SOC_NPU_AICORE_BIF_DYN_AW_CORE_OST_UNION;
#endif
#define SOC_NPU_AICORE_BIF_DYN_AW_CORE_OST_dyn_aw_ostd_wl1_START (0)
#define SOC_NPU_AICORE_BIF_DYN_AW_CORE_OST_dyn_aw_ostd_wl1_END (7)
#define SOC_NPU_AICORE_BIF_DYN_AW_CORE_OST_dyn_aw_ostd_wl2_START (8)
#define SOC_NPU_AICORE_BIF_DYN_AW_CORE_OST_dyn_aw_ostd_wl2_END (15)
#define SOC_NPU_AICORE_BIF_DYN_AW_CORE_OST_dyn_aw_ostd_wl3_START (16)
#define SOC_NPU_AICORE_BIF_DYN_AW_CORE_OST_dyn_aw_ostd_wl3_END (23)
#define SOC_NPU_AICORE_BIF_DYN_AW_CORE_OST_dyn_aw_ostd_mode_START (24)
#define SOC_NPU_AICORE_BIF_DYN_AW_CORE_OST_dyn_aw_ostd_mode_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_mte_port_aw_ostd_wl : 8;
        unsigned int sta_mte_port_ar_ostd_wl : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_AICORE_BIF_STA_MTE_PORT_OST_UNION;
#endif
#define SOC_NPU_AICORE_BIF_STA_MTE_PORT_OST_sta_mte_port_aw_ostd_wl_START (0)
#define SOC_NPU_AICORE_BIF_STA_MTE_PORT_OST_sta_mte_port_aw_ostd_wl_END (7)
#define SOC_NPU_AICORE_BIF_STA_MTE_PORT_OST_sta_mte_port_ar_ostd_wl_START (8)
#define SOC_NPU_AICORE_BIF_STA_MTE_PORT_OST_sta_mte_port_ar_ostd_wl_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int smmu_bp_sel : 2;
        unsigned int smmu_ssidv_unbp : 1;
        unsigned int smmu_ssidv_bp : 1;
        unsigned int reserved : 12;
        unsigned int smmu_streamid_bp : 16;
    } reg;
} SOC_NPU_AICORE_BIF_SMMU_STREAMID_CFG_UNION;
#endif
#define SOC_NPU_AICORE_BIF_SMMU_STREAMID_CFG_smmu_bp_sel_START (0)
#define SOC_NPU_AICORE_BIF_SMMU_STREAMID_CFG_smmu_bp_sel_END (1)
#define SOC_NPU_AICORE_BIF_SMMU_STREAMID_CFG_smmu_ssidv_unbp_START (2)
#define SOC_NPU_AICORE_BIF_SMMU_STREAMID_CFG_smmu_ssidv_unbp_END (2)
#define SOC_NPU_AICORE_BIF_SMMU_STREAMID_CFG_smmu_ssidv_bp_START (3)
#define SOC_NPU_AICORE_BIF_SMMU_STREAMID_CFG_smmu_ssidv_bp_END (3)
#define SOC_NPU_AICORE_BIF_SMMU_STREAMID_CFG_smmu_streamid_bp_START (16)
#define SOC_NPU_AICORE_BIF_SMMU_STREAMID_CFG_smmu_streamid_bp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_ar_qos_allow : 2;
        unsigned int sta_ar_qos_allow_en : 1;
        unsigned int sta_ar_ostd_wl : 8;
        unsigned int sta_ar_ostd_mode : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_AICORE_BIF_STA_AR_ALL_OST_UNION;
#endif
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_OST_sta_ar_qos_allow_START (0)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_OST_sta_ar_qos_allow_END (1)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_OST_sta_ar_qos_allow_en_START (2)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_OST_sta_ar_qos_allow_en_END (2)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_OST_sta_ar_ostd_wl_START (3)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_OST_sta_ar_ostd_wl_END (10)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_OST_sta_ar_ostd_mode_START (11)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_OST_sta_ar_ostd_mode_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_aw_qos_allow : 2;
        unsigned int sta_aw_qos_allow_en : 1;
        unsigned int sta_aw_ostd_wl : 8;
        unsigned int sta_aw_ostd_mode : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_AICORE_BIF_STA_AW_ALL_OST_UNION;
#endif
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_OST_sta_aw_qos_allow_START (0)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_OST_sta_aw_qos_allow_END (1)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_OST_sta_aw_qos_allow_en_START (2)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_OST_sta_aw_qos_allow_en_END (2)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_OST_sta_aw_ostd_wl_START (3)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_OST_sta_aw_ostd_wl_END (10)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_OST_sta_aw_ostd_mode_START (11)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_OST_sta_aw_ostd_mode_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_ar_lmtr_bw : 8;
        unsigned int sta_ar_lmtr_sat : 8;
        unsigned int sta_ar_lmtr_lp : 2;
        unsigned int sta_ar_lmtr_mode : 1;
        unsigned int sta_ar_lmtr_en : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_NPU_AICORE_BIF_STA_AR_ALL_LMTR_UNION;
#endif
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_LMTR_sta_ar_lmtr_bw_START (0)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_LMTR_sta_ar_lmtr_bw_END (7)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_LMTR_sta_ar_lmtr_sat_START (8)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_LMTR_sta_ar_lmtr_sat_END (15)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_LMTR_sta_ar_lmtr_lp_START (16)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_LMTR_sta_ar_lmtr_lp_END (17)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_LMTR_sta_ar_lmtr_mode_START (18)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_LMTR_sta_ar_lmtr_mode_END (18)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_LMTR_sta_ar_lmtr_en_START (19)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_LMTR_sta_ar_lmtr_en_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_aw_lmtr_bw : 8;
        unsigned int sta_aw_lmtr_sat : 8;
        unsigned int sta_aw_lmtr_lp : 2;
        unsigned int sta_aw_lmtr_mode : 1;
        unsigned int sta_aw_lmtr_en : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_NPU_AICORE_BIF_STA_AW_ALL_LMTR_UNION;
#endif
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_LMTR_sta_aw_lmtr_bw_START (0)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_LMTR_sta_aw_lmtr_bw_END (7)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_LMTR_sta_aw_lmtr_sat_START (8)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_LMTR_sta_aw_lmtr_sat_END (15)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_LMTR_sta_aw_lmtr_lp_START (16)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_LMTR_sta_aw_lmtr_lp_END (17)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_LMTR_sta_aw_lmtr_mode_START (18)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_LMTR_sta_aw_lmtr_mode_END (18)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_LMTR_sta_aw_lmtr_en_START (19)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_LMTR_sta_aw_lmtr_en_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dyn_ar_lmtr_bw : 8;
        unsigned int dyn_ar_lmtr_sat : 8;
        unsigned int dyn_ar_lmtr_lp : 2;
        unsigned int dyn_ar_lmtr_mode : 1;
        unsigned int dyn_ar_lmtr_en : 1;
        unsigned int dyn_ar_lmtr_lvl_mode : 2;
        unsigned int reserved : 10;
    } reg;
} SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_UNION;
#endif
#define SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_dyn_ar_lmtr_bw_START (0)
#define SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_dyn_ar_lmtr_bw_END (7)
#define SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_dyn_ar_lmtr_sat_START (8)
#define SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_dyn_ar_lmtr_sat_END (15)
#define SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_dyn_ar_lmtr_lp_START (16)
#define SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_dyn_ar_lmtr_lp_END (17)
#define SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_dyn_ar_lmtr_mode_START (18)
#define SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_dyn_ar_lmtr_mode_END (18)
#define SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_dyn_ar_lmtr_en_START (19)
#define SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_dyn_ar_lmtr_en_END (19)
#define SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_dyn_ar_lmtr_lvl_mode_START (20)
#define SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_dyn_ar_lmtr_lvl_mode_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dyn_aw_lmtr_bw : 8;
        unsigned int dyn_aw_lmtr_sat : 8;
        unsigned int dyn_aw_lmtr_lp : 2;
        unsigned int dyn_aw_lmtr_mode : 1;
        unsigned int dyn_aw_lmtr_en : 1;
        unsigned int dyn_aw_lmtr_lvl_mode : 2;
        unsigned int reserved : 10;
    } reg;
} SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_UNION;
#endif
#define SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_dyn_aw_lmtr_bw_START (0)
#define SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_dyn_aw_lmtr_bw_END (7)
#define SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_dyn_aw_lmtr_sat_START (8)
#define SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_dyn_aw_lmtr_sat_END (15)
#define SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_dyn_aw_lmtr_lp_START (16)
#define SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_dyn_aw_lmtr_lp_END (17)
#define SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_dyn_aw_lmtr_mode_START (18)
#define SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_dyn_aw_lmtr_mode_END (18)
#define SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_dyn_aw_lmtr_en_START (19)
#define SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_dyn_aw_lmtr_en_END (19)
#define SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_dyn_aw_lmtr_lvl_mode_START (20)
#define SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_dyn_aw_lmtr_lvl_mode_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bus_axi_rst_ack : 1;
        unsigned int cfg_force_req_ack : 1;
        unsigned int bus_axi_rst_req : 1;
        unsigned int bus_axi_rst_bypass : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_NPU_AICORE_BIF_AXI_CLAMP_CTRL_UNION;
#endif
#define SOC_NPU_AICORE_BIF_AXI_CLAMP_CTRL_bus_axi_rst_ack_START (0)
#define SOC_NPU_AICORE_BIF_AXI_CLAMP_CTRL_bus_axi_rst_ack_END (0)
#define SOC_NPU_AICORE_BIF_AXI_CLAMP_CTRL_cfg_force_req_ack_START (1)
#define SOC_NPU_AICORE_BIF_AXI_CLAMP_CTRL_cfg_force_req_ack_END (1)
#define SOC_NPU_AICORE_BIF_AXI_CLAMP_CTRL_bus_axi_rst_req_START (2)
#define SOC_NPU_AICORE_BIF_AXI_CLAMP_CTRL_bus_axi_rst_req_END (2)
#define SOC_NPU_AICORE_BIF_AXI_CLAMP_CTRL_bus_axi_rst_bypass_START (3)
#define SOC_NPU_AICORE_BIF_AXI_CLAMP_CTRL_bus_axi_rst_bypass_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bif_rob_cmd_entry_dis_n : 5;
        unsigned int bif_wr_cmd_entry_dis_n : 5;
        unsigned int bif_wr_stb_entry_dis_n : 5;
        unsigned int reserved : 17;
    } reg;
} SOC_NPU_AICORE_BIF_BUFF_RESOURCE_CTRL_UNION;
#endif
#define SOC_NPU_AICORE_BIF_BUFF_RESOURCE_CTRL_bif_rob_cmd_entry_dis_n_START (0)
#define SOC_NPU_AICORE_BIF_BUFF_RESOURCE_CTRL_bif_rob_cmd_entry_dis_n_END (4)
#define SOC_NPU_AICORE_BIF_BUFF_RESOURCE_CTRL_bif_wr_cmd_entry_dis_n_START (5)
#define SOC_NPU_AICORE_BIF_BUFF_RESOURCE_CTRL_bif_wr_cmd_entry_dis_n_END (9)
#define SOC_NPU_AICORE_BIF_BUFF_RESOURCE_CTRL_bif_wr_stb_entry_dis_n_START (10)
#define SOC_NPU_AICORE_BIF_BUFF_RESOURCE_CTRL_bif_wr_stb_entry_dis_n_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bif_ar_hybrid_entry_ctrl_dis : 1;
        unsigned int bif_aw_hybrid_entry_ctrl_dis : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_AICORE_BIF_HYBRID_ENTRY_CTRL_DIS_UNION;
#endif
#define SOC_NPU_AICORE_BIF_HYBRID_ENTRY_CTRL_DIS_bif_ar_hybrid_entry_ctrl_dis_START (0)
#define SOC_NPU_AICORE_BIF_HYBRID_ENTRY_CTRL_DIS_bif_ar_hybrid_entry_ctrl_dis_END (0)
#define SOC_NPU_AICORE_BIF_HYBRID_ENTRY_CTRL_DIS_bif_aw_hybrid_entry_ctrl_dis_START (1)
#define SOC_NPU_AICORE_BIF_HYBRID_ENTRY_CTRL_DIS_bif_aw_hybrid_entry_ctrl_dis_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bif_clk_ar_port_en_mask : 16;
        unsigned int bif_clk_brif_rob_en_mask : 1;
        unsigned int bif_clk_brif_en_mask : 1;
        unsigned int bif_clk_bwif_stb_en_mask : 1;
        unsigned int bif_clk_bwif_en_mask : 1;
        unsigned int bif_clk_sta_ar_lmtr_en_make : 1;
        unsigned int bif_clk_sta_aw_lmtr_en_make : 1;
        unsigned int bif_clk_dyn_ar_lmtr_en_make : 1;
        unsigned int bif_clk_dyn_aw_lmtr_en_make : 1;
        unsigned int reserved : 8;
    } reg;
} SOC_NPU_AICORE_BIF_CLK_EN_MASK_UNION;
#endif
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_bif_clk_ar_port_en_mask_START (0)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_bif_clk_ar_port_en_mask_END (15)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_bif_clk_brif_rob_en_mask_START (16)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_bif_clk_brif_rob_en_mask_END (16)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_bif_clk_brif_en_mask_START (17)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_bif_clk_brif_en_mask_END (17)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_bif_clk_bwif_stb_en_mask_START (18)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_bif_clk_bwif_stb_en_mask_END (18)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_bif_clk_bwif_en_mask_START (19)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_bif_clk_bwif_en_mask_END (19)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_bif_clk_sta_ar_lmtr_en_make_START (20)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_bif_clk_sta_ar_lmtr_en_make_END (20)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_bif_clk_sta_aw_lmtr_en_make_START (21)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_bif_clk_sta_aw_lmtr_en_make_END (21)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_bif_clk_dyn_ar_lmtr_en_make_START (22)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_bif_clk_dyn_ar_lmtr_en_make_END (22)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_bif_clk_dyn_aw_lmtr_en_make_START (23)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_bif_clk_dyn_aw_lmtr_en_make_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_ar_qos_allow_merge : 2;
        unsigned int sta_ar_qos_allow_en_merge : 1;
        unsigned int sta_ar_ostd_wl_merge : 8;
        unsigned int sta_ar_ostd_mode_merge : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_AICORE_BIF_STA_AR_ALL_OST_MERGE_UNION;
#endif
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_OST_MERGE_sta_ar_qos_allow_merge_START (0)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_OST_MERGE_sta_ar_qos_allow_merge_END (1)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_OST_MERGE_sta_ar_qos_allow_en_merge_START (2)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_OST_MERGE_sta_ar_qos_allow_en_merge_END (2)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_OST_MERGE_sta_ar_ostd_wl_merge_START (3)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_OST_MERGE_sta_ar_ostd_wl_merge_END (10)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_OST_MERGE_sta_ar_ostd_mode_merge_START (11)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_OST_MERGE_sta_ar_ostd_mode_merge_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_aw_qos_allow_merge : 2;
        unsigned int sta_aw_qos_allow_en_merge : 1;
        unsigned int sta_aw_ostd_wl_merge : 8;
        unsigned int sta_aw_ostd_mode_merge : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_AICORE_BIF_STA_AW_ALL_OST_MERGE_UNION;
#endif
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_OST_MERGE_sta_aw_qos_allow_merge_START (0)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_OST_MERGE_sta_aw_qos_allow_merge_END (1)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_OST_MERGE_sta_aw_qos_allow_en_merge_START (2)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_OST_MERGE_sta_aw_qos_allow_en_merge_END (2)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_OST_MERGE_sta_aw_ostd_wl_merge_START (3)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_OST_MERGE_sta_aw_ostd_wl_merge_END (10)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_OST_MERGE_sta_aw_ostd_mode_merge_START (11)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_OST_MERGE_sta_aw_ostd_mode_merge_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_ar_lmtr_bw_merge : 8;
        unsigned int sta_ar_lmtr_sat_merge : 8;
        unsigned int sta_ar_lmtr_lp_merge : 2;
        unsigned int sta_ar_lmtr_mode_merge : 1;
        unsigned int sta_ar_lmtr_en_merge : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_NPU_AICORE_BIF_STA_AR_ALL_LMTR_MERGE_UNION;
#endif
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_LMTR_MERGE_sta_ar_lmtr_bw_merge_START (0)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_LMTR_MERGE_sta_ar_lmtr_bw_merge_END (7)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_LMTR_MERGE_sta_ar_lmtr_sat_merge_START (8)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_LMTR_MERGE_sta_ar_lmtr_sat_merge_END (15)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_LMTR_MERGE_sta_ar_lmtr_lp_merge_START (16)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_LMTR_MERGE_sta_ar_lmtr_lp_merge_END (17)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_LMTR_MERGE_sta_ar_lmtr_mode_merge_START (18)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_LMTR_MERGE_sta_ar_lmtr_mode_merge_END (18)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_LMTR_MERGE_sta_ar_lmtr_en_merge_START (19)
#define SOC_NPU_AICORE_BIF_STA_AR_ALL_LMTR_MERGE_sta_ar_lmtr_en_merge_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_aw_lmtr_bw_merge : 8;
        unsigned int sta_aw_lmtr_sat_merge : 8;
        unsigned int sta_aw_lmtr_lp_merge : 2;
        unsigned int sta_aw_lmtr_mode_merge : 1;
        unsigned int sta_aw_lmtr_en_merge : 1;
        unsigned int reserved : 12;
    } reg;
} SOC_NPU_AICORE_BIF_STA_AW_ALL_LMTR_MERGE_UNION;
#endif
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_LMTR_MERGE_sta_aw_lmtr_bw_merge_START (0)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_LMTR_MERGE_sta_aw_lmtr_bw_merge_END (7)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_LMTR_MERGE_sta_aw_lmtr_sat_merge_START (8)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_LMTR_MERGE_sta_aw_lmtr_sat_merge_END (15)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_LMTR_MERGE_sta_aw_lmtr_lp_merge_START (16)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_LMTR_MERGE_sta_aw_lmtr_lp_merge_END (17)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_LMTR_MERGE_sta_aw_lmtr_mode_merge_START (18)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_LMTR_MERGE_sta_aw_lmtr_mode_merge_END (18)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_LMTR_MERGE_sta_aw_lmtr_en_merge_START (19)
#define SOC_NPU_AICORE_BIF_STA_AW_ALL_LMTR_MERGE_sta_aw_lmtr_en_merge_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dyn_ar_lmtr_bw_merge : 8;
        unsigned int dyn_ar_lmtr_sat_merge : 8;
        unsigned int dyn_ar_lmtr_lp_merge : 2;
        unsigned int dyn_ar_lmtr_mode_merge : 1;
        unsigned int dyn_ar_lmtr_en_merge : 1;
        unsigned int dyn_ar_lmtr_lvl_mode_merge : 2;
        unsigned int reserved : 10;
    } reg;
} SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_MERGE_UNION;
#endif
#define SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_MERGE_dyn_ar_lmtr_bw_merge_START (0)
#define SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_MERGE_dyn_ar_lmtr_bw_merge_END (7)
#define SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_MERGE_dyn_ar_lmtr_sat_merge_START (8)
#define SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_MERGE_dyn_ar_lmtr_sat_merge_END (15)
#define SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_MERGE_dyn_ar_lmtr_lp_merge_START (16)
#define SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_MERGE_dyn_ar_lmtr_lp_merge_END (17)
#define SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_MERGE_dyn_ar_lmtr_mode_merge_START (18)
#define SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_MERGE_dyn_ar_lmtr_mode_merge_END (18)
#define SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_MERGE_dyn_ar_lmtr_en_merge_START (19)
#define SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_MERGE_dyn_ar_lmtr_en_merge_END (19)
#define SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_MERGE_dyn_ar_lmtr_lvl_mode_merge_START (20)
#define SOC_NPU_AICORE_BIF_DYN_AR_ALL_LMTR_MERGE_dyn_ar_lmtr_lvl_mode_merge_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dyn_aw_lmtr_bw_merge : 8;
        unsigned int dyn_aw_lmtr_sat_merge : 8;
        unsigned int dyn_aw_lmtr_lp_merge : 2;
        unsigned int dyn_aw_lmtr_mode_merge : 1;
        unsigned int dyn_aw_lmtr_en_merge : 1;
        unsigned int dyn_aw_lmtr_lvl_mode_merge : 2;
        unsigned int reserved : 10;
    } reg;
} SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_MERGE_UNION;
#endif
#define SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_MERGE_dyn_aw_lmtr_bw_merge_START (0)
#define SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_MERGE_dyn_aw_lmtr_bw_merge_END (7)
#define SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_MERGE_dyn_aw_lmtr_sat_merge_START (8)
#define SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_MERGE_dyn_aw_lmtr_sat_merge_END (15)
#define SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_MERGE_dyn_aw_lmtr_lp_merge_START (16)
#define SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_MERGE_dyn_aw_lmtr_lp_merge_END (17)
#define SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_MERGE_dyn_aw_lmtr_mode_merge_START (18)
#define SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_MERGE_dyn_aw_lmtr_mode_merge_END (18)
#define SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_MERGE_dyn_aw_lmtr_en_merge_START (19)
#define SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_MERGE_dyn_aw_lmtr_en_merge_END (19)
#define SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_MERGE_dyn_aw_lmtr_lvl_mode_merge_START (20)
#define SOC_NPU_AICORE_BIF_DYN_AW_ALL_LMTR_MERGE_dyn_aw_lmtr_lvl_mode_merge_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bus_axi_rst_ack_merge : 1;
        unsigned int cfg_force_req_ack_merge : 1;
        unsigned int bus_axi_rst_req_merge : 1;
        unsigned int bus_axi_rst_bypass_merge : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_NPU_AICORE_BIF_AXI_CLAMP_CTRL_MERGE_UNION;
#endif
#define SOC_NPU_AICORE_BIF_AXI_CLAMP_CTRL_MERGE_bus_axi_rst_ack_merge_START (0)
#define SOC_NPU_AICORE_BIF_AXI_CLAMP_CTRL_MERGE_bus_axi_rst_ack_merge_END (0)
#define SOC_NPU_AICORE_BIF_AXI_CLAMP_CTRL_MERGE_cfg_force_req_ack_merge_START (1)
#define SOC_NPU_AICORE_BIF_AXI_CLAMP_CTRL_MERGE_cfg_force_req_ack_merge_END (1)
#define SOC_NPU_AICORE_BIF_AXI_CLAMP_CTRL_MERGE_bus_axi_rst_req_merge_START (2)
#define SOC_NPU_AICORE_BIF_AXI_CLAMP_CTRL_MERGE_bus_axi_rst_req_merge_END (2)
#define SOC_NPU_AICORE_BIF_AXI_CLAMP_CTRL_MERGE_bus_axi_rst_bypass_merge_START (3)
#define SOC_NPU_AICORE_BIF_AXI_CLAMP_CTRL_MERGE_bus_axi_rst_bypass_merge_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bif_rob_cmd_entry_dis_n_merge : 5;
        unsigned int bif_wr_cmd_entry_dis_n_merge : 5;
        unsigned int bif_wr_stb_entry_dis_n_merge : 5;
        unsigned int reserved : 17;
    } reg;
} SOC_NPU_AICORE_BIF_BUFF_RESOURCE_CTRL_MERGE_UNION;
#endif
#define SOC_NPU_AICORE_BIF_BUFF_RESOURCE_CTRL_MERGE_bif_rob_cmd_entry_dis_n_merge_START (0)
#define SOC_NPU_AICORE_BIF_BUFF_RESOURCE_CTRL_MERGE_bif_rob_cmd_entry_dis_n_merge_END (4)
#define SOC_NPU_AICORE_BIF_BUFF_RESOURCE_CTRL_MERGE_bif_wr_cmd_entry_dis_n_merge_START (5)
#define SOC_NPU_AICORE_BIF_BUFF_RESOURCE_CTRL_MERGE_bif_wr_cmd_entry_dis_n_merge_END (9)
#define SOC_NPU_AICORE_BIF_BUFF_RESOURCE_CTRL_MERGE_bif_wr_stb_entry_dis_n_merge_START (10)
#define SOC_NPU_AICORE_BIF_BUFF_RESOURCE_CTRL_MERGE_bif_wr_stb_entry_dis_n_merge_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bif_ar_hybrid_entry_ctrl_dis_merge : 1;
        unsigned int bif_aw_hybrid_entry_ctrl_dis_merge : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_AICORE_BIF_HYBRID_ENTRY_CTRL_DIS_MERGE_UNION;
#endif
#define SOC_NPU_AICORE_BIF_HYBRID_ENTRY_CTRL_DIS_MERGE_bif_ar_hybrid_entry_ctrl_dis_merge_START (0)
#define SOC_NPU_AICORE_BIF_HYBRID_ENTRY_CTRL_DIS_MERGE_bif_ar_hybrid_entry_ctrl_dis_merge_END (0)
#define SOC_NPU_AICORE_BIF_HYBRID_ENTRY_CTRL_DIS_MERGE_bif_aw_hybrid_entry_ctrl_dis_merge_START (1)
#define SOC_NPU_AICORE_BIF_HYBRID_ENTRY_CTRL_DIS_MERGE_bif_aw_hybrid_entry_ctrl_dis_merge_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bif_clk_ar_port_en_mask_merge : 16;
        unsigned int bif_clk_brif_rob_en_mask_merge : 1;
        unsigned int bif_clk_brif_en_mask_merge : 1;
        unsigned int bif_clk_bwif_stb_en_mask_merge : 1;
        unsigned int bif_clk_bwif_en_mask_merge : 1;
        unsigned int bif_clk_sta_ar_lmtr_en_make_merge : 1;
        unsigned int bif_clk_sta_aw_lmtr_en_make_merge : 1;
        unsigned int bif_clk_dyn_ar_lmtr_en_make_merge : 1;
        unsigned int bif_clk_dyn_aw_lmtr_en_make_merge : 1;
        unsigned int reserved : 8;
    } reg;
} SOC_NPU_AICORE_BIF_CLK_EN_MASK_BUSY_MERGE_UNION;
#endif
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_BUSY_MERGE_bif_clk_ar_port_en_mask_merge_START (0)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_BUSY_MERGE_bif_clk_ar_port_en_mask_merge_END (15)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_BUSY_MERGE_bif_clk_brif_rob_en_mask_merge_START (16)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_BUSY_MERGE_bif_clk_brif_rob_en_mask_merge_END (16)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_BUSY_MERGE_bif_clk_brif_en_mask_merge_START (17)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_BUSY_MERGE_bif_clk_brif_en_mask_merge_END (17)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_BUSY_MERGE_bif_clk_bwif_stb_en_mask_merge_START (18)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_BUSY_MERGE_bif_clk_bwif_stb_en_mask_merge_END (18)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_BUSY_MERGE_bif_clk_bwif_en_mask_merge_START (19)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_BUSY_MERGE_bif_clk_bwif_en_mask_merge_END (19)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_BUSY_MERGE_bif_clk_sta_ar_lmtr_en_make_merge_START (20)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_BUSY_MERGE_bif_clk_sta_ar_lmtr_en_make_merge_END (20)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_BUSY_MERGE_bif_clk_sta_aw_lmtr_en_make_merge_START (21)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_BUSY_MERGE_bif_clk_sta_aw_lmtr_en_make_merge_END (21)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_BUSY_MERGE_bif_clk_dyn_ar_lmtr_en_make_merge_START (22)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_BUSY_MERGE_bif_clk_dyn_ar_lmtr_en_make_merge_END (22)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_BUSY_MERGE_bif_clk_dyn_aw_lmtr_en_make_merge_START (23)
#define SOC_NPU_AICORE_BIF_CLK_EN_MASK_BUSY_MERGE_bif_clk_dyn_aw_lmtr_en_make_merge_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_aw_otsd_cnt : 9;
        unsigned int sta_ar_otsd_cnt : 9;
        unsigned int sta_awack_ostd_cnt : 9;
        unsigned int reserved : 5;
    } reg;
} SOC_NPU_AICORE_BIF_OUTSTANDING_STATUS_UNION;
#endif
#define SOC_NPU_AICORE_BIF_OUTSTANDING_STATUS_sta_aw_otsd_cnt_START (0)
#define SOC_NPU_AICORE_BIF_OUTSTANDING_STATUS_sta_aw_otsd_cnt_END (8)
#define SOC_NPU_AICORE_BIF_OUTSTANDING_STATUS_sta_ar_otsd_cnt_START (9)
#define SOC_NPU_AICORE_BIF_OUTSTANDING_STATUS_sta_ar_otsd_cnt_END (17)
#define SOC_NPU_AICORE_BIF_OUTSTANDING_STATUS_sta_awack_ostd_cnt_START (18)
#define SOC_NPU_AICORE_BIF_OUTSTANDING_STATUS_sta_awack_ostd_cnt_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sta_aw_stb_table_cnt : 9;
        unsigned int sta_aw_cmd_table_cnt : 9;
        unsigned int sta_ar_cmd_table_cnt : 9;
        unsigned int reserved : 5;
    } reg;
} SOC_NPU_AICORE_BIF_CMD_TABLE_STATUS_UNION;
#endif
#define SOC_NPU_AICORE_BIF_CMD_TABLE_STATUS_sta_aw_stb_table_cnt_START (0)
#define SOC_NPU_AICORE_BIF_CMD_TABLE_STATUS_sta_aw_stb_table_cnt_END (8)
#define SOC_NPU_AICORE_BIF_CMD_TABLE_STATUS_sta_aw_cmd_table_cnt_START (9)
#define SOC_NPU_AICORE_BIF_CMD_TABLE_STATUS_sta_aw_cmd_table_cnt_END (17)
#define SOC_NPU_AICORE_BIF_CMD_TABLE_STATUS_sta_ar_cmd_table_cnt_START (18)
#define SOC_NPU_AICORE_BIF_CMD_TABLE_STATUS_sta_ar_cmd_table_cnt_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bif_busy : 1;
        unsigned int bwif_busy : 1;
        unsigned int brif_busy : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_NPU_AICORE_BIF_BUSY_STATUS_UNION;
#endif
#define SOC_NPU_AICORE_BIF_BUSY_STATUS_bif_busy_START (0)
#define SOC_NPU_AICORE_BIF_BUSY_STATUS_bif_busy_END (0)
#define SOC_NPU_AICORE_BIF_BUSY_STATUS_bwif_busy_START (1)
#define SOC_NPU_AICORE_BIF_BUSY_STATUS_bwif_busy_END (1)
#define SOC_NPU_AICORE_BIF_BUSY_STATUS_brif_busy_START (2)
#define SOC_NPU_AICORE_BIF_BUSY_STATUS_brif_busy_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bif_reserved_reg0 : 32;
    } reg;
} SOC_NPU_AICORE_BIF_RESERVED_REG0_UNION;
#endif
#define SOC_NPU_AICORE_BIF_RESERVED_REG0_bif_reserved_reg0_START (0)
#define SOC_NPU_AICORE_BIF_RESERVED_REG0_bif_reserved_reg0_END (31)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
