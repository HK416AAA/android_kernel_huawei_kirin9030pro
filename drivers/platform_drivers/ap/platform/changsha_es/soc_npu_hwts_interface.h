#ifndef __SOC_NPU_HWTS_INTERFACE_H__
#define __SOC_NPU_HWTS_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_HWTS_HWTS_SEC_EN_ADDR(base) ((base) + (0x0UL))
#define SOC_NPU_HWTS_HWTS_HOST_MID_CFG_ADDR(base) ((base) + (0x4UL))
#define SOC_NPU_HWTS_HWTS_HOST_MID_CFG_EN_ADDR(base) ((base) + (0x8UL))
#define SOC_NPU_HWTS_HWTS_GLB_CTRL_S_ADDR(base) ((base) + (0xcUL))
#define SOC_NPU_HWTS_HWTS_FFRT_CFG0_ADDR(base) ((base) + (0x10UL))
#define SOC_NPU_HWTS_HWTS_LOG_PMU_CFG0_ADDR(base) ((base) + (0x14UL))
#define SOC_NPU_HWTS_HWTS_SQ_SEC_EN_ADDR(base,m) ((base) + (0x80+0x4*(m)))
#define SOC_NPU_HWTS_HWTS_SYNC_CTRL_ADDR(base) ((base) + (0xc0UL))
#define SOC_NPU_HWTS_HWTS_LOCK_CORE_CTRL_ADDR(base) ((base) + (0xc4UL))
#define SOC_NPU_HWTS_HWTS_AIC_BASE_ADDR_CFG0_ADDR(base) ((base) + (0x1000UL))
#define SOC_NPU_HWTS_HWTS_AIC_BASE_ADDR_CFG1_ADDR(base) ((base) + (0x1004UL))
#define SOC_NPU_HWTS_HWTS_AIV_BASE_ADDR_CFG0_ADDR(base) ((base) + (0x1008UL))
#define SOC_NPU_HWTS_HWTS_AIV_BASE_ADDR_CFG1_ADDR(base) ((base) + (0x100cUL))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_BASE_ADDR_CFG0_ADDR(base) ((base) + (0x1010UL))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_BASE_ADDR_CFG1_ADDR(base) ((base) + (0x1014UL))
#define SOC_NPU_HWTS_HWTS_MDC_BASE_ADDR_CFG0_ADDR(base) ((base) + (0x1040UL))
#define SOC_NPU_HWTS_HWTS_MDC_BASE_ADDR_CFG1_ADDR(base) ((base) + (0x1044UL))
#define SOC_NPU_HWTS_HWTS_S_SQ_SWAP_BUF_BASE_ADDR_CFG0_ADDR(base) ((base) + (0x1080UL))
#define SOC_NPU_HWTS_HWTS_S_SQ_SWAP_BUF_BASE_ADDR_CFG1_ADDR(base) ((base) + (0x1084UL))
#define SOC_NPU_HWTS_HWTS_FFRT_SWAPBUF_ADDR_CFG_ADDR(base) ((base) + (0x1088UL))
#define SOC_NPU_HWTS_HWTS_FFRT_SWAPBUF_IDX_CFG_ADDR(base) ((base) + (0x108cUL))
#define SOC_NPU_HWTS_HWTS_FFRT_MDC_BLKDIM_CFG_ADDR(base) ((base) + (0x1090UL))
#define SOC_NPU_HWTS_HWTS_NOTIFY_SEND_ERR_EN_ADDR(base) ((base) + (0x1094UL))
#define SOC_NPU_HWTS_HWTS_HTS_NOTIFY_UPPER_ADDR(base) ((base) + (0x1098UL))
#define SOC_NPU_HWTS_HWTS_POWER_CTRL0_ADDR(base) ((base) + (0x10a0UL))
#define SOC_NPU_HWTS_HWTS_POWER_CTRL1_ADDR(base) ((base) + (0x10a4UL))
#define SOC_NPU_HWTS_HWTS_POWER_CTRL2_ADDR(base) ((base) + (0x10a8UL))
#define SOC_NPU_HWTS_HWTS_POWER_CTRL3_ADDR(base) ((base) + (0x10acUL))
#define SOC_NPU_HWTS_HWTS_POWER_CTRL4_ADDR(base) ((base) + (0x10b0UL))
#define SOC_NPU_HWTS_HWTS_POWER_CTRL5_ADDR(base) ((base) + (0x10b4UL))
#define SOC_NPU_HWTS_HWTS_BOOTUP_CFG0_ADDR(base,core_idx) ((base) + (0x10c0+(core_idx)*0x10UL))
#define SOC_NPU_HWTS_HWTS_BOOTUP_CFG1_ADDR(base,core_idx) ((base) + (0x10c4+(core_idx)*0x10UL))
#define SOC_NPU_HWTS_HWTS_BOOTDOWN_CFG0_ADDR(base,core_idx) ((base) + (0x10c8+(core_idx)*0x10UL))
#define SOC_NPU_HWTS_HWTS_BOOTDOWN_CFG1_ADDR(base,core_idx) ((base) + (0x10cc+(core_idx)*0x10UL))
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING0_ADDR(base) ((base) + (0x1100UL))
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING1_ADDR(base) ((base) + (0x1104UL))
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING2_ADDR(base) ((base) + (0x1108UL))
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING3_ADDR(base) ((base) + (0x1200UL))
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING4_ADDR(base) ((base) + (0x1204UL))
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING5_ADDR(base) ((base) + (0x1208UL))
#define SOC_NPU_HWTS_HWTS_NS_SQ_SWAP_BUF_BASE_ADDR_CFG0_ADDR(base) ((base) + (0x2000UL))
#define SOC_NPU_HWTS_HWTS_NS_SQ_SWAP_BUF_BASE_ADDR_CFG1_ADDR(base) ((base) + (0x2004UL))
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING0_ADDR(base) ((base) + (0x2100UL))
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING1_ADDR(base) ((base) + (0x2104UL))
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING2_ADDR(base) ((base) + (0x2108UL))
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING3_ADDR(base) ((base) + (0x210cUL))
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING4_ADDR(base) ((base) + (0x2110UL))
#define SOC_NPU_HWTS_HWTS_GLB_CTRL0_ADDR(base) ((base) + (0x2800UL))
#define SOC_NPU_HWTS_HWTS_GLB_CTRL1_ADDR(base) ((base) + (0x2804UL))
#define SOC_NPU_HWTS_HWTS_GLB_CTRL2_ADDR(base) ((base) + (0x2808UL))
#define SOC_NPU_HWTS_HWTS_GLB_CTRL3_ADDR(base) ((base) + (0x280cUL))
#define SOC_NPU_HWTS_HWTS_GLB_CTRL4_ADDR(base) ((base) + (0x2810UL))
#define SOC_NPU_HWTS_HWTS_GLB_CTRL5_ADDR(base) ((base) + (0x2c00UL))
#define SOC_NPU_HWTS_HWTS_NOTIFYID_CTRL_ADDR(base) ((base) + (0x2c80+ sync_grp*0x4UL))
#define SOC_NPU_HWTS_HWTS_HTS_EVENT_SEND_CTRL_ADDR(base) ((base) + (0x2cc0UL))
#define SOC_NPU_HWTS_HWTS_FFRT_CTRL0_ADDR(base) ((base) + (0x2cc4UL))
#define SOC_NPU_HWTS_HWTS_FFRT_CTRL1_ADDR(base) ((base) + (0x2cc8UL))
#define SOC_NPU_HWTS_HWTS_RW_ECO0_RESERVED_ADDR(base) ((base) + (0x2ff0UL))
#define SOC_NPU_HWTS_HWTS_RW_ECO1_RESERVED_ADDR(base) ((base) + (0x2ff4UL))
#define SOC_NPU_HWTS_HWTS_RO_ECO0_RESERVED_ADDR(base) ((base) + (0x2ff8UL))
#define SOC_NPU_HWTS_HWTS_RO_ECO1_RESERVED_ADDR(base) ((base) + (0x2ffcUL))
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_CTRL0_ADDR(base) ((base) + (0x3000UL))
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_CTRL1_ADDR(base) ((base) + (0x3004UL))
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_CTRL2_ADDR(base) ((base) + (0x3008UL))
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_CTRL3_ADDR(base) ((base) + (0x300cUL))
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_CTRL4_ADDR(base) ((base) + (0x3010UL))
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_DFX0_ADDR(base) ((base) + (0x3040UL))
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_DFX1_ADDR(base) ((base) + (0x3044UL))
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_CTRL0_ADDR(base) ((base) + (0x3100UL))
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_CTRL1_ADDR(base) ((base) + (0x3104UL))
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_CTRL2_ADDR(base) ((base) + (0x3108UL))
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_CTRL3_ADDR(base) ((base) + (0x310cUL))
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_CTRL4_ADDR(base) ((base) + (0x3110UL))
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_DFX0_ADDR(base) ((base) + (0x3140UL))
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_DFX1_ADDR(base) ((base) + (0x3144UL))
#define SOC_NPU_HWTS_HWTS_MASTER_BUS_DFX0_ADDR(base) ((base) + (0x3200UL))
#define SOC_NPU_HWTS_HWTS_MASTER_BUS_DFX1_ADDR(base) ((base) + (0x3204UL))
#define SOC_NPU_HWTS_HWTS_MASTER_BUS_DFX2_ADDR(base) ((base) + (0x3208UL))
#define SOC_NPU_HWTS_HWTS_POWER_DFX0_ADDR(base,core_idx) ((base) + (0x3300+(core_idx)*0x10UL))
#else
#define SOC_NPU_HWTS_HWTS_SEC_EN_ADDR(base) ((base) + (0x0))
#define SOC_NPU_HWTS_HWTS_HOST_MID_CFG_ADDR(base) ((base) + (0x4))
#define SOC_NPU_HWTS_HWTS_HOST_MID_CFG_EN_ADDR(base) ((base) + (0x8))
#define SOC_NPU_HWTS_HWTS_GLB_CTRL_S_ADDR(base) ((base) + (0xcUL))
#define SOC_NPU_HWTS_HWTS_FFRT_CFG0_ADDR(base) ((base) + (0x10))
#define SOC_NPU_HWTS_HWTS_LOG_PMU_CFG0_ADDR(base) ((base) + (0x14))
#define SOC_NPU_HWTS_HWTS_SQ_SEC_EN_ADDR(base,m) ((base) + (0x80+0x4*(m)))
#define SOC_NPU_HWTS_HWTS_SYNC_CTRL_ADDR(base) ((base) + (0xc0))
#define SOC_NPU_HWTS_HWTS_LOCK_CORE_CTRL_ADDR(base) ((base) + (0xc4))
#define SOC_NPU_HWTS_HWTS_AIC_BASE_ADDR_CFG0_ADDR(base) ((base) + (0x1000))
#define SOC_NPU_HWTS_HWTS_AIC_BASE_ADDR_CFG1_ADDR(base) ((base) + (0x1004))
#define SOC_NPU_HWTS_HWTS_AIV_BASE_ADDR_CFG0_ADDR(base) ((base) + (0x1008))
#define SOC_NPU_HWTS_HWTS_AIV_BASE_ADDR_CFG1_ADDR(base) ((base) + (0x100c))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_BASE_ADDR_CFG0_ADDR(base) ((base) + (0x1010))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_BASE_ADDR_CFG1_ADDR(base) ((base) + (0x1014))
#define SOC_NPU_HWTS_HWTS_MDC_BASE_ADDR_CFG0_ADDR(base) ((base) + (0x1040))
#define SOC_NPU_HWTS_HWTS_MDC_BASE_ADDR_CFG1_ADDR(base) ((base) + (0x1044))
#define SOC_NPU_HWTS_HWTS_S_SQ_SWAP_BUF_BASE_ADDR_CFG0_ADDR(base) ((base) + (0x1080))
#define SOC_NPU_HWTS_HWTS_S_SQ_SWAP_BUF_BASE_ADDR_CFG1_ADDR(base) ((base) + (0x1084))
#define SOC_NPU_HWTS_HWTS_FFRT_SWAPBUF_ADDR_CFG_ADDR(base) ((base) + (0x1088))
#define SOC_NPU_HWTS_HWTS_FFRT_SWAPBUF_IDX_CFG_ADDR(base) ((base) + (0x108c))
#define SOC_NPU_HWTS_HWTS_FFRT_MDC_BLKDIM_CFG_ADDR(base) ((base) + (0x1090))
#define SOC_NPU_HWTS_HWTS_NOTIFY_SEND_ERR_EN_ADDR(base) ((base) + (0x1094))
#define SOC_NPU_HWTS_HWTS_HTS_NOTIFY_UPPER_ADDR(base) ((base) + (0x1098))
#define SOC_NPU_HWTS_HWTS_POWER_CTRL0_ADDR(base) ((base) + (0x10a0))
#define SOC_NPU_HWTS_HWTS_POWER_CTRL1_ADDR(base) ((base) + (0x10a4))
#define SOC_NPU_HWTS_HWTS_POWER_CTRL2_ADDR(base) ((base) + (0x10a8))
#define SOC_NPU_HWTS_HWTS_POWER_CTRL3_ADDR(base) ((base) + (0x10ac))
#define SOC_NPU_HWTS_HWTS_POWER_CTRL4_ADDR(base) ((base) + (0x10b0))
#define SOC_NPU_HWTS_HWTS_POWER_CTRL5_ADDR(base) ((base) + (0x10b4))
#define SOC_NPU_HWTS_HWTS_BOOTUP_CFG0_ADDR(base,core_idx) ((base) + (0x10c0+(core_idx)*0x10))
#define SOC_NPU_HWTS_HWTS_BOOTUP_CFG1_ADDR(base,core_idx) ((base) + (0x10c4+(core_idx)*0x10))
#define SOC_NPU_HWTS_HWTS_BOOTDOWN_CFG0_ADDR(base,core_idx) ((base) + (0x10c8+(core_idx)*0x10))
#define SOC_NPU_HWTS_HWTS_BOOTDOWN_CFG1_ADDR(base,core_idx) ((base) + (0x10cc+(core_idx)*0x10))
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING0_ADDR(base) ((base) + (0x1100))
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING1_ADDR(base) ((base) + (0x1104))
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING2_ADDR(base) ((base) + (0x1108))
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING3_ADDR(base) ((base) + (0x1200))
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING4_ADDR(base) ((base) + (0x1204))
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING5_ADDR(base) ((base) + (0x1208))
#define SOC_NPU_HWTS_HWTS_NS_SQ_SWAP_BUF_BASE_ADDR_CFG0_ADDR(base) ((base) + (0x2000))
#define SOC_NPU_HWTS_HWTS_NS_SQ_SWAP_BUF_BASE_ADDR_CFG1_ADDR(base) ((base) + (0x2004))
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING0_ADDR(base) ((base) + (0x2100))
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING1_ADDR(base) ((base) + (0x2104))
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING2_ADDR(base) ((base) + (0x2108))
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING3_ADDR(base) ((base) + (0x210c))
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING4_ADDR(base) ((base) + (0x2110))
#define SOC_NPU_HWTS_HWTS_GLB_CTRL0_ADDR(base) ((base) + (0x2800))
#define SOC_NPU_HWTS_HWTS_GLB_CTRL1_ADDR(base) ((base) + (0x2804))
#define SOC_NPU_HWTS_HWTS_GLB_CTRL2_ADDR(base) ((base) + (0x2808))
#define SOC_NPU_HWTS_HWTS_GLB_CTRL3_ADDR(base) ((base) + (0x280c))
#define SOC_NPU_HWTS_HWTS_GLB_CTRL4_ADDR(base) ((base) + (0x2810))
#define SOC_NPU_HWTS_HWTS_GLB_CTRL5_ADDR(base) ((base) + (0x2c00))
#define SOC_NPU_HWTS_HWTS_NOTIFYID_CTRL_ADDR(base) ((base) + (0x2c80+ sync_grp*0x4))
#define SOC_NPU_HWTS_HWTS_HTS_EVENT_SEND_CTRL_ADDR(base) ((base) + (0x2cc0))
#define SOC_NPU_HWTS_HWTS_FFRT_CTRL0_ADDR(base) ((base) + (0x2cc4))
#define SOC_NPU_HWTS_HWTS_FFRT_CTRL1_ADDR(base) ((base) + (0x2cc8))
#define SOC_NPU_HWTS_HWTS_RW_ECO0_RESERVED_ADDR(base) ((base) + (0x2ff0))
#define SOC_NPU_HWTS_HWTS_RW_ECO1_RESERVED_ADDR(base) ((base) + (0x2ff4))
#define SOC_NPU_HWTS_HWTS_RO_ECO0_RESERVED_ADDR(base) ((base) + (0x2ff8))
#define SOC_NPU_HWTS_HWTS_RO_ECO1_RESERVED_ADDR(base) ((base) + (0x2ffc))
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_CTRL0_ADDR(base) ((base) + (0x3000))
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_CTRL1_ADDR(base) ((base) + (0x3004))
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_CTRL2_ADDR(base) ((base) + (0x3008))
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_CTRL3_ADDR(base) ((base) + (0x300c))
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_CTRL4_ADDR(base) ((base) + (0x3010))
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_DFX0_ADDR(base) ((base) + (0x3040))
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_DFX1_ADDR(base) ((base) + (0x3044))
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_CTRL0_ADDR(base) ((base) + (0x3100))
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_CTRL1_ADDR(base) ((base) + (0x3104))
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_CTRL2_ADDR(base) ((base) + (0x3108))
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_CTRL3_ADDR(base) ((base) + (0x310c))
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_CTRL4_ADDR(base) ((base) + (0x3110))
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_DFX0_ADDR(base) ((base) + (0x3140))
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_DFX1_ADDR(base) ((base) + (0x3144))
#define SOC_NPU_HWTS_HWTS_MASTER_BUS_DFX0_ADDR(base) ((base) + (0x3200))
#define SOC_NPU_HWTS_HWTS_MASTER_BUS_DFX1_ADDR(base) ((base) + (0x3204))
#define SOC_NPU_HWTS_HWTS_MASTER_BUS_DFX2_ADDR(base) ((base) + (0x3208))
#define SOC_NPU_HWTS_HWTS_POWER_DFX0_ADDR(base,core_idx) ((base) + (0x3300+(core_idx)*0x10))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_HWTS_HWTS_AICV_CTRL0_ADDR(base) ((base) + (0x4000UL))
#define SOC_NPU_HWTS_HWTS_AICV_CTRL1_ADDR(base) ((base) + (0x4200UL))
#define SOC_NPU_HWTS_HWTS_AICV_CTRL2_ADDR(base) ((base) + (0x4204UL))
#define SOC_NPU_HWTS_HWTS_AICV_CTRL4_ADDR(base) ((base) + (0x4400UL))
#define SOC_NPU_HWTS_HWTS_AIC_POOL_ENABLE_CTRL_ADDR(base,vmg_idx) ((base) + (0x5000+0x8*(vmg_idx)))
#define SOC_NPU_HWTS_HWTS_AIC_POOL_DISABLE_CTRL_ADDR(base,vmg_idx) ((base) + (0x5004+0x8*(vmg_idx)))
#define SOC_NPU_HWTS_HWTS_AIC_POOL_STATUS_ADDR(base,vmg_idx) ((base) + (0x5100+0x4*(vmg_idx)))
#define SOC_NPU_HWTS_HWTS_AIV_POOL_ENABLE_CTRL_ADDR(base,vmg_idx) ((base) + (0x5200+0x8*(vmg_idx)))
#define SOC_NPU_HWTS_HWTS_AIV_POOL_DISABLE_CTRL_ADDR(base,vmg_idx) ((base) + (0x5204+0x8*(vmg_idx)))
#define SOC_NPU_HWTS_HWTS_AIV_POOL_STATUS_ADDR(base,vmg_idx) ((base) + (0x5300+0x4*(vmg_idx)))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_POOL_ENABLE_CTRL_ADDR(base,vmg_idx) ((base) + (0x5400+0x8*(vmg_idx)))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_POOL_DISABLE_CTRL_ADDR(base,vmg_idx) ((base) + (0x5404+0x8*(vmg_idx)))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_POOL_STATUS_ADDR(base,vmg_idx) ((base) + (0x5500+0x4*(vmg_idx)))
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT0_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6000+(pmu_grp_idx)*0x40UL))
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT1_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6004+(pmu_grp_idx)*0x40UL))
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT2_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6008+(pmu_grp_idx)*0x40UL))
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT3_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x600c+(pmu_grp_idx)*0x40UL))
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT4_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6010+(pmu_grp_idx)*0x40UL))
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT5_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6014+(pmu_grp_idx)*0x40UL))
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT6_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6018+(pmu_grp_idx)*0x40UL))
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT7_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x601c+(pmu_grp_idx)*0x40UL))
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT0_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6400+(pmu_grp_idx)*0x40UL))
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT1_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6404+(pmu_grp_idx)*0x40UL))
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT2_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6408+(pmu_grp_idx)*0x40UL))
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT3_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x640c+(pmu_grp_idx)*0x40UL))
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT4_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6410+(pmu_grp_idx)*0x40UL))
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT5_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6414+(pmu_grp_idx)*0x40UL))
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT6_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6418+(pmu_grp_idx)*0x40UL))
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT7_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x641c+(pmu_grp_idx)*0x40UL))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT0_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6800+(pmu_grp_idx)*0x40UL))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT1_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6804+(pmu_grp_idx)*0x40UL))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT2_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6808+(pmu_grp_idx)*0x40UL))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT3_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x680c+(pmu_grp_idx)*0x40UL))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT4_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6810+(pmu_grp_idx)*0x40UL))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT5_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6814+(pmu_grp_idx)*0x40UL))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT6_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6818+(pmu_grp_idx)*0x40UL))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT7_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x681c+(pmu_grp_idx)*0x40UL))
#define SOC_NPU_HWTS_HWTS_PMU_CNT_IDX_UPDATE_ADDR(base,pmu_grp_idx) ((base) + (0x6c00+(pmu_grp_idx)*0x40UL))
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX0_ADDR(base,aic_idx) ((base) + (0x7000+(aic_idx)*0x20UL))
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX1_ADDR(base,aic_idx) ((base) + (0x7004+(aic_idx)*0x20UL))
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX2_ADDR(base,aic_idx) ((base) + (0x7008+(aic_idx)*0x20UL))
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX3_ADDR(base,aic_idx) ((base) + (0x700c+(aic_idx)*0x20UL))
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_CTRL_ADDR(base,aic_idx) ((base) + (0x701c+(aic_idx)*0x20UL))
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_ADDR(base,aiv_idx) ((base) + (0x7400+(aiv_idx)*0x20UL))
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX1_ADDR(base,aiv_idx) ((base) + (0x7404+(aiv_idx)*0x20UL))
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX2_ADDR(base,aiv_idx) ((base) + (0x7408+(aiv_idx)*0x20UL))
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX3_ADDR(base,aiv_idx) ((base) + (0x740c+(aiv_idx)*0x20UL))
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_CTRL_ADDR(base,aiv_idx) ((base) + (0x741c+(aiv_idx)*0x20UL))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX0_ADDR(base,eff_aic_idx) ((base) + (0x7600+(eff_aic_idx)*0x20UL))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX1_ADDR(base,eff_aic_idx) ((base) + (0x7604+(eff_aic_idx)*0x20UL))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX2_ADDR(base,eff_aic_idx) ((base) + (0x7608+(eff_aic_idx)*0x20UL))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX3_ADDR(base,eff_aic_idx) ((base) + (0x760c+(eff_aic_idx)*0x20UL))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_CTRL_ADDR(base,eff_aic_idx) ((base) + (0x761c+(eff_aic_idx)*0x20UL))
#define SOC_NPU_HWTS_HWTS_UTILIZATION_CTRL0_ADDR(base) ((base) + (0x7800UL))
#define SOC_NPU_HWTS_HWTS_UTILIZATION_CTRL1_ADDR(base) ((base) + (0x7804UL))
#define SOC_NPU_HWTS_HWTS_UTILIZATION_CTRL2_ADDR(base,vm_idx) ((base) + (0x7900+(vm_idx)*0x10UL))
#define SOC_NPU_HWTS_HWTS_UTILIZATION_CTRL3_ADDR(base,vm_idx) ((base) + (0x7904+(vm_idx)*0x10UL))
#define SOC_NPU_HWTS_HWTS_UTILIZATION_CTRL4_ADDR(base,vm_idx) ((base) + (0x7908+(vm_idx)*0x10UL))
#else
#define SOC_NPU_HWTS_HWTS_AICV_CTRL0_ADDR(base) ((base) + (0x4000))
#define SOC_NPU_HWTS_HWTS_AICV_CTRL1_ADDR(base) ((base) + (0x4200))
#define SOC_NPU_HWTS_HWTS_AICV_CTRL2_ADDR(base) ((base) + (0x4204))
#define SOC_NPU_HWTS_HWTS_AICV_CTRL4_ADDR(base) ((base) + (0x4400))
#define SOC_NPU_HWTS_HWTS_AIC_POOL_ENABLE_CTRL_ADDR(base,vmg_idx) ((base) + (0x5000+0x8*(vmg_idx)))
#define SOC_NPU_HWTS_HWTS_AIC_POOL_DISABLE_CTRL_ADDR(base,vmg_idx) ((base) + (0x5004+0x8*(vmg_idx)))
#define SOC_NPU_HWTS_HWTS_AIC_POOL_STATUS_ADDR(base,vmg_idx) ((base) + (0x5100+0x4*(vmg_idx)))
#define SOC_NPU_HWTS_HWTS_AIV_POOL_ENABLE_CTRL_ADDR(base,vmg_idx) ((base) + (0x5200+0x8*(vmg_idx)))
#define SOC_NPU_HWTS_HWTS_AIV_POOL_DISABLE_CTRL_ADDR(base,vmg_idx) ((base) + (0x5204+0x8*(vmg_idx)))
#define SOC_NPU_HWTS_HWTS_AIV_POOL_STATUS_ADDR(base,vmg_idx) ((base) + (0x5300+0x4*(vmg_idx)))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_POOL_ENABLE_CTRL_ADDR(base,vmg_idx) ((base) + (0x5400+0x8*(vmg_idx)))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_POOL_DISABLE_CTRL_ADDR(base,vmg_idx) ((base) + (0x5404+0x8*(vmg_idx)))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_POOL_STATUS_ADDR(base,vmg_idx) ((base) + (0x5500+0x4*(vmg_idx)))
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT0_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6000+(pmu_grp_idx)*0x40))
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT1_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6004+(pmu_grp_idx)*0x40))
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT2_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6008+(pmu_grp_idx)*0x40))
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT3_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x600c+(pmu_grp_idx)*0x40))
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT4_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6010+(pmu_grp_idx)*0x40))
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT5_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6014+(pmu_grp_idx)*0x40))
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT6_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6018+(pmu_grp_idx)*0x40))
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT7_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x601c+(pmu_grp_idx)*0x40))
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT0_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6400+(pmu_grp_idx)*0x40))
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT1_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6404+(pmu_grp_idx)*0x40))
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT2_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6408+(pmu_grp_idx)*0x40))
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT3_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x640c+(pmu_grp_idx)*0x40))
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT4_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6410+(pmu_grp_idx)*0x40))
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT5_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6414+(pmu_grp_idx)*0x40))
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT6_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6418+(pmu_grp_idx)*0x40))
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT7_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x641c+(pmu_grp_idx)*0x40))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT0_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6800+(pmu_grp_idx)*0x40))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT1_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6804+(pmu_grp_idx)*0x40))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT2_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6808+(pmu_grp_idx)*0x40))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT3_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x680c+(pmu_grp_idx)*0x40))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT4_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6810+(pmu_grp_idx)*0x40))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT5_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6814+(pmu_grp_idx)*0x40))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT6_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x6818+(pmu_grp_idx)*0x40))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT7_IDX_ADDR(base,pmu_grp_idx) ((base) + (0x681c+(pmu_grp_idx)*0x40))
#define SOC_NPU_HWTS_HWTS_PMU_CNT_IDX_UPDATE_ADDR(base,pmu_grp_idx) ((base) + (0x6c00+(pmu_grp_idx)*0x40))
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX0_ADDR(base,aic_idx) ((base) + (0x7000+(aic_idx)*0x20))
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX1_ADDR(base,aic_idx) ((base) + (0x7004+(aic_idx)*0x20))
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX2_ADDR(base,aic_idx) ((base) + (0x7008+(aic_idx)*0x20))
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX3_ADDR(base,aic_idx) ((base) + (0x700c+(aic_idx)*0x20))
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_CTRL_ADDR(base,aic_idx) ((base) + (0x701c+(aic_idx)*0x20UL))
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_ADDR(base,aiv_idx) ((base) + (0x7400+(aiv_idx)*0x20))
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX1_ADDR(base,aiv_idx) ((base) + (0x7404+(aiv_idx)*0x20))
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX2_ADDR(base,aiv_idx) ((base) + (0x7408+(aiv_idx)*0x20))
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX3_ADDR(base,aiv_idx) ((base) + (0x740c+(aiv_idx)*0x20))
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_CTRL_ADDR(base,aiv_idx) ((base) + (0x741c+(aiv_idx)*0x20UL))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX0_ADDR(base,eff_aic_idx) ((base) + (0x7600+(eff_aic_idx)*0x20))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX1_ADDR(base,eff_aic_idx) ((base) + (0x7604+(eff_aic_idx)*0x20))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX2_ADDR(base,eff_aic_idx) ((base) + (0x7608+(eff_aic_idx)*0x20))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX3_ADDR(base,eff_aic_idx) ((base) + (0x760c+(eff_aic_idx)*0x20))
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_CTRL_ADDR(base,eff_aic_idx) ((base) + (0x761c+(eff_aic_idx)*0x20UL))
#define SOC_NPU_HWTS_HWTS_UTILIZATION_CTRL0_ADDR(base) ((base) + (0x7800))
#define SOC_NPU_HWTS_HWTS_UTILIZATION_CTRL1_ADDR(base) ((base) + (0x7804))
#define SOC_NPU_HWTS_HWTS_UTILIZATION_CTRL2_ADDR(base,vm_idx) ((base) + (0x7900+(vm_idx)*0x10))
#define SOC_NPU_HWTS_HWTS_UTILIZATION_CTRL3_ADDR(base,vm_idx) ((base) + (0x7904+(vm_idx)*0x10))
#define SOC_NPU_HWTS_HWTS_UTILIZATION_CTRL4_ADDR(base,vm_idx) ((base) + (0x7908+(vm_idx)*0x10))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_HWTS_HWTS_SWAPIN_CTRL0_ADDR(base,vmg_idx) ((base) + (0x8000+0x20*(vmg_idx)))
#define SOC_NPU_HWTS_VIRTUALIZATION_GLB_CFG_ADDR(base,vmg_idx) ((base) + (0x8010+0x20*(vmg_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_CTRL_ADDR(base,vm_idx) ((base) + (0x8800+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_STATUS_ADDR(base,vm_idx) ((base) + (0x8804+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_CFG_ADDR(base,vm_idx) ((base) + (0x8808+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_SHADOW_L_ADDR(base,vm_idx) ((base) + (0x8810+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_SHADOW_H_ADDR(base,vm_idx) ((base) + (0x8814+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_MAX_TOKEN_SHADOW_L_ADDR(base,vm_idx) ((base) + (0x8818+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_MAX_TOKEN_SHADOW_H_ADDR(base,vm_idx) ((base) + (0x881c+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_REFILL_SHADOW_L_ADDR(base,vm_idx) ((base) + (0x8820+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_REFILL_SHADOW_H_ADDR(base,vm_idx) ((base) + (0x8824+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_REMAIN_TOKEN_L_ADDR(base,vm_idx) ((base) + (0x8840+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_REMAIN_TOKEN_H_ADDR(base,vm_idx) ((base) + (0x8844+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_L_ADDR(base,vm_idx) ((base) + (0x8848+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_H_ADDR(base,vm_idx) ((base) + (0x884c+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_TOKEN_MAX_L_ADDR(base,vm_idx) ((base) + (0x8850+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_TOKEN_MAX_H_ADDR(base,vm_idx) ((base) + (0x8854+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_TOKEN_MIN_L_ADDR(base,vm_idx) ((base) + (0x8858+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_TOKEN_MIN_H_ADDR(base,vm_idx) ((base) + (0x885c+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_REFILL_TOKEN_L_ADDR(base,vm_idx) ((base) + (0x8860+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_REFILL_TOKEN_H_ADDR(base,vm_idx) ((base) + (0x8864+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_STATIS_TOKEN_MIN_L_ADDR(base,vm_idx) ((base) + (0x8868+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_STATIS_TOKEN_MIN_H_ADDR(base,vm_idx) ((base) + (0x886c+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_STATIS_TOKEN_MAX_L_ADDR(base,vm_idx) ((base) + (0x8870+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_STATIS_TOKEN_MAX_H_ADDR(base,vm_idx) ((base) + (0x8874+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_DFX_CTRL0_ADDR(base,vm_idx) ((base) + (0x8878+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_DFX_CTRL1_ADDR(base,vm_idx) ((base) + (0x887c+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_DFX_GLB_CTRL_ADDR(base) ((base) + (0x8c00UL))
#else
#define SOC_NPU_HWTS_HWTS_SWAPIN_CTRL0_ADDR(base,vmg_idx) ((base) + (0x8000+0x20*(vmg_idx)))
#define SOC_NPU_HWTS_VIRTUALIZATION_GLB_CFG_ADDR(base,vmg_idx) ((base) + (0x8010+0x20*(vmg_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_CTRL_ADDR(base,vm_idx) ((base) + (0x8800+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_STATUS_ADDR(base,vm_idx) ((base) + (0x8804+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_CFG_ADDR(base,vm_idx) ((base) + (0x8808+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_SHADOW_L_ADDR(base,vm_idx) ((base) + (0x8810+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_SHADOW_H_ADDR(base,vm_idx) ((base) + (0x8814+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_MAX_TOKEN_SHADOW_L_ADDR(base,vm_idx) ((base) + (0x8818+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_MAX_TOKEN_SHADOW_H_ADDR(base,vm_idx) ((base) + (0x881c+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_REFILL_SHADOW_L_ADDR(base,vm_idx) ((base) + (0x8820+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_REFILL_SHADOW_H_ADDR(base,vm_idx) ((base) + (0x8824+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_REMAIN_TOKEN_L_ADDR(base,vm_idx) ((base) + (0x8840+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_REMAIN_TOKEN_H_ADDR(base,vm_idx) ((base) + (0x8844+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_L_ADDR(base,vm_idx) ((base) + (0x8848+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_H_ADDR(base,vm_idx) ((base) + (0x884c+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_TOKEN_MAX_L_ADDR(base,vm_idx) ((base) + (0x8850+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_TOKEN_MAX_H_ADDR(base,vm_idx) ((base) + (0x8854+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_TOKEN_MIN_L_ADDR(base,vm_idx) ((base) + (0x8858+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_TOKEN_MIN_H_ADDR(base,vm_idx) ((base) + (0x885c+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_REFILL_TOKEN_L_ADDR(base,vm_idx) ((base) + (0x8860+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_REFILL_TOKEN_H_ADDR(base,vm_idx) ((base) + (0x8864+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_STATIS_TOKEN_MIN_L_ADDR(base,vm_idx) ((base) + (0x8868+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_STATIS_TOKEN_MIN_H_ADDR(base,vm_idx) ((base) + (0x886c+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_STATIS_TOKEN_MAX_L_ADDR(base,vm_idx) ((base) + (0x8870+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_STATIS_TOKEN_MAX_H_ADDR(base,vm_idx) ((base) + (0x8874+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_DFX_CTRL0_ADDR(base,vm_idx) ((base) + (0x8878+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_DFX_CTRL1_ADDR(base,vm_idx) ((base) + (0x887c+0x80*(vm_idx)))
#define SOC_NPU_HWTS_VIRTUAL_DFX_GLB_CTRL_ADDR(base) ((base) + (0x8c00))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_CTRL0_ADDR(base,prof_idx) ((base) + (0x9000+(prof_idx)*0x1000UL))
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_CTRL1_ADDR(base,prof_idx) ((base) + (0x9004+(prof_idx)*0x1000UL))
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_BASE_ADDR0_ADDR(base,prof_idx) ((base) + (0x9008+(prof_idx)*0x1000UL))
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_BASE_ADDR1_ADDR(base,prof_idx) ((base) + (0x900c+(prof_idx)*0x1000UL))
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_WPTR_INITIAL_ADDR(base,prof_idx) ((base) + (0x9010+(prof_idx)*0x1000UL))
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_WPTR_ADDR(base,prof_idx) ((base) + (0x9014+(prof_idx)*0x1000UL))
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_RPTR_ADDR(base,prof_idx) ((base) + (0x9018+(prof_idx)*0x1000UL))
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_SSID_ADDR(base,prof_idx) ((base) + (0x901c+(prof_idx)*0x1000UL))
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_SSID_EN_ADDR(base,prof_idx) ((base) + (0x9020+(prof_idx)*0x1000UL))
#define SOC_NPU_HWTS_HWTS_DFX_LOG_CTRL0_ADDR(base,log_idx) ((base) + (0x9040+(log_idx)*0x1000UL))
#define SOC_NPU_HWTS_HWTS_DFX_LOG_CTRL1_ADDR(base,log_idx) ((base) + (0x9044+(log_idx)*0x1000UL))
#define SOC_NPU_HWTS_HWTS_DFX_LOG_BASE_ADDR0_ADDR(base,log_idx) ((base) + (0x9048+(log_idx)*0x1000UL))
#define SOC_NPU_HWTS_HWTS_DFX_LOG_BASE_ADDR1_ADDR(base,log_idx) ((base) + (0x904c+(log_idx)*0x1000UL))
#define SOC_NPU_HWTS_HWTS_DFX_LOG_WPTR_INITIAL_ADDR(base,log_idx) ((base) + (0x9050+(log_idx)*0x1000UL))
#define SOC_NPU_HWTS_HWTS_DFX_LOG_WPTR_ADDR(base,log_idx) ((base) + (0x9054+(log_idx)*0x1000UL))
#define SOC_NPU_HWTS_HWTS_DFX_LOG_RPTR_ADDR(base,log_idx) ((base) + (0x9058+(log_idx)*0x1000UL))
#define SOC_NPU_HWTS_HWTS_DFX_LOG_SSID_ADDR(base,log_idx) ((base) + (0x905c+(log_idx)*0x1000UL))
#define SOC_NPU_HWTS_HWTS_DFX_LOG_SSID_EN_ADDR(base,log_idx) ((base) + (0x9060+(log_idx)*0x1000UL))
#else
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_CTRL0_ADDR(base,prof_idx) ((base) + (0x9000+(prof_idx)*0x1000))
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_CTRL1_ADDR(base,prof_idx) ((base) + (0x9004+(prof_idx)*0x1000))
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_BASE_ADDR0_ADDR(base,prof_idx) ((base) + (0x9008+(prof_idx)*0x1000))
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_BASE_ADDR1_ADDR(base,prof_idx) ((base) + (0x900c+(prof_idx)*0x1000))
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_WPTR_INITIAL_ADDR(base,prof_idx) ((base) + (0x9010+(prof_idx)*0x1000))
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_WPTR_ADDR(base,prof_idx) ((base) + (0x9014+(prof_idx)*0x1000))
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_RPTR_ADDR(base,prof_idx) ((base) + (0x9018+(prof_idx)*0x1000))
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_SSID_ADDR(base,prof_idx) ((base) + (0x901c+(prof_idx)*0x1000))
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_SSID_EN_ADDR(base,prof_idx) ((base) + (0x9020+(prof_idx)*0x1000))
#define SOC_NPU_HWTS_HWTS_DFX_LOG_CTRL0_ADDR(base,log_idx) ((base) + (0x9040+(log_idx)*0x1000))
#define SOC_NPU_HWTS_HWTS_DFX_LOG_CTRL1_ADDR(base,log_idx) ((base) + (0x9044+(log_idx)*0x1000))
#define SOC_NPU_HWTS_HWTS_DFX_LOG_BASE_ADDR0_ADDR(base,log_idx) ((base) + (0x9048+(log_idx)*0x1000))
#define SOC_NPU_HWTS_HWTS_DFX_LOG_BASE_ADDR1_ADDR(base,log_idx) ((base) + (0x904c+(log_idx)*0x1000))
#define SOC_NPU_HWTS_HWTS_DFX_LOG_WPTR_INITIAL_ADDR(base,log_idx) ((base) + (0x9050+(log_idx)*0x1000))
#define SOC_NPU_HWTS_HWTS_DFX_LOG_WPTR_ADDR(base,log_idx) ((base) + (0x9054+(log_idx)*0x1000))
#define SOC_NPU_HWTS_HWTS_DFX_LOG_RPTR_ADDR(base,log_idx) ((base) + (0x9058+(log_idx)*0x1000))
#define SOC_NPU_HWTS_HWTS_DFX_LOG_SSID_ADDR(base,log_idx) ((base) + (0x905c+(log_idx)*0x1000))
#define SOC_NPU_HWTS_HWTS_DFX_LOG_SSID_EN_ADDR(base,log_idx) ((base) + (0x9060+(log_idx)*0x1000))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_ADDR(base,ffrt_entry_idx) ((base) + (0x20000+0x100*(ffrt_entry_idx)))
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO0_ADDR(base,ffrt_entry_idx) ((base) + (0x20040+0x100*(ffrt_entry_idx)))
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO1_ADDR(base,ffrt_entry_idx) ((base) + (0x20044+0x100*(ffrt_entry_idx)))
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO2_ADDR(base,ffrt_entry_idx) ((base) + (0x20048+0x100*(ffrt_entry_idx)))
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO3_ADDR(base,ffrt_entry_idx) ((base) + (0x2004c+0x100*(ffrt_entry_idx)))
#define SOC_NPU_HWTS_HWTS_FFRT_ACTIVE_ENTRY_INFO0_ADDR(base,ffrt_active_entry_idx) ((base) + (0x20050+0x100*(ffrt_active_entry_idx)))
#define SOC_NPU_HWTS_HWTS_FFRT_ACTIVE_ENTRY_INFO1_ADDR(base,ffrt_active_entry_idx) ((base) + (0x20054+0x100*(ffrt_active_entry_idx)))
#define SOC_NPU_HWTS_HWTS_FFRT_ACTIVE_ENTRY_INFO2_ADDR(base,ffrt_active_entry_idx) ((base) + (0x20058+0x100*(ffrt_active_entry_idx)))
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_DFX0_ADDR(base) ((base) + (0x20080UL))
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_DFX1_ADDR(base) ((base) + (0x20084UL))
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_DFX2_ADDR(base) ((base) + (0x20088UL))
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_DFX3_ADDR(base) ((base) + (0x2008cUL))
#else
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_ADDR(base,ffrt_entry_idx) ((base) + (0x20000+0x100*(ffrt_entry_idx)))
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO0_ADDR(base,ffrt_entry_idx) ((base) + (0x20040+0x100*(ffrt_entry_idx)))
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO1_ADDR(base,ffrt_entry_idx) ((base) + (0x20044+0x100*(ffrt_entry_idx)))
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO2_ADDR(base,ffrt_entry_idx) ((base) + (0x20048+0x100*(ffrt_entry_idx)))
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO3_ADDR(base,ffrt_entry_idx) ((base) + (0x2004c+0x100*(ffrt_entry_idx)))
#define SOC_NPU_HWTS_HWTS_FFRT_ACTIVE_ENTRY_INFO0_ADDR(base,ffrt_active_entry_idx) ((base) + (0x20050+0x100*(ffrt_active_entry_idx)))
#define SOC_NPU_HWTS_HWTS_FFRT_ACTIVE_ENTRY_INFO1_ADDR(base,ffrt_active_entry_idx) ((base) + (0x20054+0x100*(ffrt_active_entry_idx)))
#define SOC_NPU_HWTS_HWTS_FFRT_ACTIVE_ENTRY_INFO2_ADDR(base,ffrt_active_entry_idx) ((base) + (0x20058+0x100*(ffrt_active_entry_idx)))
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_DFX0_ADDR(base) ((base) + (0x20080))
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_DFX1_ADDR(base) ((base) + (0x20084))
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_DFX2_ADDR(base) ((base) + (0x20088))
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_DFX3_ADDR(base) ((base) + (0x2008c))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_HWTS_HWTS_RTSQ_BASE_ADDR0_ADDR(base,r) ((base) + (0xe000+(r)*0x100UL))
#define SOC_NPU_HWTS_HWTS_RTSQ_BASE_ADDR1_ADDR(base,r) ((base) + (0xe004+(r)*0x100UL))
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG0_ADDR(base,r) ((base) + (0xe008+(r)*0x100UL))
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG1_ADDR(base,r) ((base) + (0xe00c+(r)*0x100UL))
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG2_ADDR(base,r) ((base) + (0xe010+(r)*0x100UL))
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG3_ADDR(base,r) ((base) + (0xe014+(r)*0x100UL))
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG4_ADDR(base,r) ((base) + (0xe018+(r)*0x100UL))
#define SOC_NPU_HWTS_HWTS_RTCQ_BASE_ADDR0_ADDR(base,r) ((base) + (0xe020+(r)*0x100UL))
#define SOC_NPU_HWTS_HWTS_RTCQ_BASE_ADDR1_ADDR(base,r) ((base) + (0xe024+(r)*0x100UL))
#define SOC_NPU_HWTS_HWTS_RTCQ_CFG0_ADDR(base,r) ((base) + (0xe028+(r)*0x100UL))
#define SOC_NPU_HWTS_HWTS_RTSQ_CONTEXT_SWITCH_BUF_CTRL0_ADDR(base,r) ((base) + (0xe02c+(r)*0x100UL))
#define SOC_NPU_HWTS_HWTS_RTSQ_CONTEXT_SWITCH_BUF_CTRL1_ADDR(base,r) ((base) + (0xe030+(r)*0x100UL))
#define SOC_NPU_HWTS_HWTS_RTSQ_SW_STATUS_ADDR(base,r) ((base) + (0xe07c+(r)*0x100UL))
#define SOC_NPU_HWTS_ACSQ_FSM_IP_OWN_STATE_ADDR(base,r) ((base) + (0xe080+(r)*0x100UL))
#define SOC_NPU_HWTS_ACSQ_FSM_IP_DEBUG_STATE_ADDR(base,r) ((base) + (0xe084+(r)*0x100UL))
#define SOC_NPU_HWTS_ACSQ_FSM_IP_EXCEPTION_STATE_ADDR(base,r) ((base) + (0xe088+(r)*0x100UL))
#define SOC_NPU_HWTS_ACSQ_FSM_IP_TRAP_STATE_ADDR(base,r) ((base) + (0xe08c+(r)*0x100UL))
#define SOC_NPU_HWTS_ACSQ_FSM_IP_DONE_STATE_ADDR(base,r) ((base) + (0xe090+(r)*0x100UL))
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL0_ADDR(base,r) ((base) + (0xe094+(r)*0x100UL))
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL1_ADDR(base,r) ((base) + (0xe098+(r)*0x100UL))
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL2_ADDR(base,r) ((base) + (0xe09c+(r)*0x100UL))
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL3_ADDR(base,r) ((base) + (0xe0a0+(r)*0x100UL))
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL4_ADDR(base,r) ((base) + (0xe0a4+(r)*0x100UL))
#define SOC_NPU_HWTS_ACSQ_TO_RTSQ_MAP0_ADDR(base,r) ((base) + (0xe0f8+(r)*0x100UL))
#define SOC_NPU_HWTS_ACSQ_TO_RTSQ_MAP1_ADDR(base,r) ((base) + (0xe0fc+(r)*0x100UL))
#else
#define SOC_NPU_HWTS_HWTS_RTSQ_BASE_ADDR0_ADDR(base,r) ((base) + (0xe000+(r)*0x100))
#define SOC_NPU_HWTS_HWTS_RTSQ_BASE_ADDR1_ADDR(base,r) ((base) + (0xe004+(r)*0x100))
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG0_ADDR(base,r) ((base) + (0xe008+(r)*0x100))
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG1_ADDR(base,r) ((base) + (0xe00c+(r)*0x100))
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG2_ADDR(base,r) ((base) + (0xe010+(r)*0x100))
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG3_ADDR(base,r) ((base) + (0xe014+(r)*0x100))
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG4_ADDR(base,r) ((base) + (0xe018+(r)*0x100))
#define SOC_NPU_HWTS_HWTS_RTCQ_BASE_ADDR0_ADDR(base,r) ((base) + (0xe020+(r)*0x100))
#define SOC_NPU_HWTS_HWTS_RTCQ_BASE_ADDR1_ADDR(base,r) ((base) + (0xe024+(r)*0x100))
#define SOC_NPU_HWTS_HWTS_RTCQ_CFG0_ADDR(base,r) ((base) + (0xe028+(r)*0x100))
#define SOC_NPU_HWTS_HWTS_RTSQ_CONTEXT_SWITCH_BUF_CTRL0_ADDR(base,r) ((base) + (0xe02c+(r)*0x100))
#define SOC_NPU_HWTS_HWTS_RTSQ_CONTEXT_SWITCH_BUF_CTRL1_ADDR(base,r) ((base) + (0xe030+(r)*0x100))
#define SOC_NPU_HWTS_HWTS_RTSQ_SW_STATUS_ADDR(base,r) ((base) + (0xe07c+(r)*0x100))
#define SOC_NPU_HWTS_ACSQ_FSM_IP_OWN_STATE_ADDR(base,r) ((base) + (0xe080+(r)*0x100))
#define SOC_NPU_HWTS_ACSQ_FSM_IP_DEBUG_STATE_ADDR(base,r) ((base) + (0xe084+(r)*0x100))
#define SOC_NPU_HWTS_ACSQ_FSM_IP_EXCEPTION_STATE_ADDR(base,r) ((base) + (0xe088+(r)*0x100))
#define SOC_NPU_HWTS_ACSQ_FSM_IP_TRAP_STATE_ADDR(base,r) ((base) + (0xe08c+(r)*0x100))
#define SOC_NPU_HWTS_ACSQ_FSM_IP_DONE_STATE_ADDR(base,r) ((base) + (0xe090+(r)*0x100))
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL0_ADDR(base,r) ((base) + (0xe094+(r)*0x100))
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL1_ADDR(base,r) ((base) + (0xe098+(r)*0x100))
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL2_ADDR(base,r) ((base) + (0xe09c+(r)*0x100))
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL3_ADDR(base,r) ((base) + (0xe0a0+(r)*0x100))
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL4_ADDR(base,r) ((base) + (0xe0a4+(r)*0x100))
#define SOC_NPU_HWTS_ACSQ_TO_RTSQ_MAP0_ADDR(base,r) ((base) + (0xe0f8+(r)*0x100))
#define SOC_NPU_HWTS_ACSQ_TO_RTSQ_MAP1_ADDR(base,r) ((base) + (0xe0fc+(r)*0x100))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_HWTS_HWTS_HTS_EVENT_TABLE_ADDR(base,k) ((base) + (0xf000+(k)*0x0004UL))
#define SOC_NPU_HWTS_HWTS_HTS_ERROR_DFX_ADDR(base) ((base) + (0xfd00UL))
#else
#define SOC_NPU_HWTS_HWTS_HTS_EVENT_TABLE_ADDR(base,k) ((base) + (0xf000+(k)*0x0004))
#define SOC_NPU_HWTS_HWTS_HTS_ERROR_DFX_ADDR(base) ((base) + (0xfd00))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG0_ADDR(base,n0) ((base) + (0x10000+(n0)*0x100UL))
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG1_ADDR(base,n0) ((base) + (0x10004+(n0)*0x100UL))
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG2_ADDR(base,n0) ((base) + (0x10008+(n0)*0x100UL))
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG3_ADDR(base,n0) ((base) + (0x1000c+(n0)*0x100UL))
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG4_ADDR(base,n0) ((base) + (0x10010+(n0)*0x100UL))
#define SOC_NPU_HWTS_HWTS_P0_TASK_CTRL_ADDR(base,n0) ((base) + (0x10040+(n0)*0x100UL))
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_COND0_ADDR(base,n0) ((base) + (0x10060+(n0)*0x100UL))
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_COND1_ADDR(base,n0) ((base) + (0x10064+(n0)*0x100UL))
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_TO_ACSQ_MAP0_ADDR(base,n0) ((base) + (0x10080+(n0)*0x100UL))
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_TO_ACSQ_MAP1_ADDR(base,n0) ((base) + (0x10084+(n0)*0x100UL))
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_DFX0_ADDR(base,n0) ((base) + (0x10088+(n0)*0x100UL))
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_DFX1_ADDR(base,n0) ((base) + (0x1008c+(n0)*0x100UL))
#else
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG0_ADDR(base,n0) ((base) + (0x10000+(n0)*0x100))
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG1_ADDR(base,n0) ((base) + (0x10004+(n0)*0x100))
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG2_ADDR(base,n0) ((base) + (0x10008+(n0)*0x100))
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG3_ADDR(base,n0) ((base) + (0x1000c+(n0)*0x100))
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG4_ADDR(base,n0) ((base) + (0x10010+(n0)*0x100))
#define SOC_NPU_HWTS_HWTS_P0_TASK_CTRL_ADDR(base,n0) ((base) + (0x10040+(n0)*0x100))
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_COND0_ADDR(base,n0) ((base) + (0x10060+(n0)*0x100))
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_COND1_ADDR(base,n0) ((base) + (0x10064+(n0)*0x100))
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_TO_ACSQ_MAP0_ADDR(base,n0) ((base) + (0x10080+(n0)*0x100))
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_TO_ACSQ_MAP1_ADDR(base,n0) ((base) + (0x10084+(n0)*0x100))
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_DFX0_ADDR(base,n0) ((base) + (0x10088+(n0)*0x100))
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_DFX1_ADDR(base,n0) ((base) + (0x1008c+(n0)*0x100))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_HWTS_HWTS_P0_RTCQ_CFG0_ADDR(base,n0) ((base) + (0x100c0+(n0)*0x100UL))
#define SOC_NPU_HWTS_HWTS_P0_RTCQ_CFG1_ADDR(base,n0) ((base) + (0x100c4+(n0)*0x100UL))
#define SOC_NPU_HWTS_HWTS_P0_RTCQ_CFG2_ADDR(base,n0) ((base) + (0x100c8+(n0)*0x100UL))
#else
#define SOC_NPU_HWTS_HWTS_P0_RTCQ_CFG0_ADDR(base,n0) ((base) + (0x100c0+(n0)*0x100))
#define SOC_NPU_HWTS_HWTS_P0_RTCQ_CFG1_ADDR(base,n0) ((base) + (0x100c4+(n0)*0x100))
#define SOC_NPU_HWTS_HWTS_P0_RTCQ_CFG2_ADDR(base,n0) ((base) + (0x100c8+(n0)*0x100))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_ADDR(base) ((base) + (0x80600UL))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_INTERRUPT_ADDR(base) ((base) + (0x80608UL))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_ADDR(base) ((base) + (0x80610UL))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_FORCE_ADDR(base) ((base) + (0x80650UL))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_ADDR(base) ((base) + (0x80680UL))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK0_ADDR(base) ((base) + (0x80688UL))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_ADDR(base) ((base) + (0x80690UL))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK1_ADDR(base) ((base) + (0x806c0UL))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK1_ADDR(base) ((base) + (0x806c8UL))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK1_ADDR(base) ((base) + (0x806d0UL))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_ADDR(base) ((base) + (0x80700UL))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK2_ADDR(base) ((base) + (0x80708UL))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_ADDR(base) ((base) + (0x80710UL))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_SET_ADDR(base) ((base) + (0x80780UL))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK0_SET_ADDR(base) ((base) + (0x80788UL))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_SET_ADDR(base) ((base) + (0x80790UL))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK1_SET_ADDR(base) ((base) + (0x807c0UL))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK1_SET_ADDR(base) ((base) + (0x807c8UL))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK1_SET_ADDR(base) ((base) + (0x807d0UL))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_SET_ADDR(base) ((base) + (0x80800UL))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK2_SET_ADDR(base) ((base) + (0x80808UL))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_SET_ADDR(base) ((base) + (0x80810UL))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_CLR_ADDR(base) ((base) + (0x80880UL))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK0_CLR_ADDR(base) ((base) + (0x80888UL))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_CLR_ADDR(base) ((base) + (0x80890UL))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK1_CLR_ADDR(base) ((base) + (0x808c0UL))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK1_CLR_ADDR(base) ((base) + (0x808c8UL))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK1_CLR_ADDR(base) ((base) + (0x808d0UL))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_CLR_ADDR(base) ((base) + (0x80900UL))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK2_CLR_ADDR(base) ((base) + (0x80908UL))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_CLR_ADDR(base) ((base) + (0x80910UL))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING0_ADDR(base) ((base) + (0x80980UL))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_INTERRUPT_PENDING0_ADDR(base) ((base) + (0x80988UL))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING0_ADDR(base) ((base) + (0x80990UL))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING1_ADDR(base) ((base) + (0x809c0UL))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_INTERRUPT_PENDING1_ADDR(base) ((base) + (0x809c8UL))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING1_ADDR(base) ((base) + (0x809d0UL))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING2_ADDR(base) ((base) + (0x80a00UL))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_INTERRUPT_PENDING2_ADDR(base) ((base) + (0x80a08UL))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING2_ADDR(base) ((base) + (0x80a10UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_INTERRUPT_ADDR(base,m) ((base) + (0x81000+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_INTERRUPT_ADDR(base) ((base) + (0x81080+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_INTERRUPT_ADDR(base) ((base) + (0x81100+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_INTERRUPT_ADDR(base) ((base) + (0x81180+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_INTERRUPT_ADDR(base,m) ((base) + (0x81480+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_INTERRUPT_ADDR(base,m) ((base) + (0x81500+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_INTERRUPT_ADDR(base) ((base) + (0x81800+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_INTERRUPT_ADDR(base,m) ((base) + (0x81880+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_INTERRUPT_ADDR(base) ((base) + (0x81c00+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_INTERRUPT_ADDR(base,m) ((base) + (0x81c80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_INTERRUPT_ADDR(base) ((base) + (0x81d00+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_INTERRUPT_ADDR(base) ((base) + (0x81d80+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_INTERRUPT_ADDR(base) ((base) + (0x81e00+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_FORCE_ADDR(base,m) ((base) + (0x82000+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_FORCE_ADDR(base) ((base) + (0x82080+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_FORCE_ADDR(base) ((base) + (0x82100+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_FORCE_ADDR(base) ((base) + (0x82180+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_FORCE_ADDR(base,m) ((base) + (0x82480+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_FORCE_ADDR(base,m) ((base) + (0x82500+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_FORCE_ADDR(base) ((base) + (0x82800+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_FORCE_ADDR(base,m) ((base) + (0x82880+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_FORCE_ADDR(base) ((base) + (0x82c00+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_FORCE_ADDR(base,m) ((base) + (0x82c80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_FORCE_ADDR(base) ((base) + (0x82d00+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_FORCE_ADDR(base) ((base) + (0x82d80+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_FORCE_ADDR(base) ((base) + (0x82e00+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_MASK0_ADDR(base,m) ((base) + (0x83000+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_MASK0_ADDR(base,m) ((base) + (0x83080+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_MASK0_ADDR(base,m) ((base) + (0x83100+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_MASK0_ADDR(base,m) ((base) + (0x83180+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_MASK0_ADDR(base,m) ((base) + (0x83480+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_MASK0_ADDR(base,m) ((base) + (0x83500+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_MASK0_ADDR(base,m) ((base) + (0x83800+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_MASK0_ADDR(base,m) ((base) + (0x83880+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_MASK0_ADDR(base,m) ((base) + (0x83c00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_MASK0_ADDR(base,m) ((base) + (0x83c80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_MASK0_ADDR(base,m) ((base) + (0x83d00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_MASK0_ADDR(base,m) ((base) + (0x83d80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_MASK0_ADDR(base,m) ((base) + (0x83e00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_MASK1_ADDR(base,m) ((base) + (0x84000+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_MASK1_ADDR(base,m) ((base) + (0x84080+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_MASK1_ADDR(base,m) ((base) + (0x84100+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_MASK1_ADDR(base,m) ((base) + (0x84180+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_MASK1_ADDR(base,m) ((base) + (0x84480+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_MASK1_ADDR(base,m) ((base) + (0x84500+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_MASK1_ADDR(base,m) ((base) + (0x84800+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_MASK1_ADDR(base,m) ((base) + (0x84880+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_MASK1_ADDR(base,m) ((base) + (0x84c00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_MASK1_ADDR(base,m) ((base) + (0x84c80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_MASK1_ADDR(base,m) ((base) + (0x84d00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_MASK1_ADDR(base,m) ((base) + (0x84d80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_MASK1_ADDR(base,m) ((base) + (0x84e00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_MASK2_ADDR(base,m) ((base) + (0x85000+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_MASK2_ADDR(base,m) ((base) + (0x85080+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_MASK2_ADDR(base,m) ((base) + (0x85100+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_MASK2_ADDR(base,m) ((base) + (0x85180+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_MASK2_ADDR(base,m) ((base) + (0x85480+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_MASK2_ADDR(base,m) ((base) + (0x85500+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_MASK2_ADDR(base,m) ((base) + (0x85800+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_MASK2_ADDR(base,m) ((base) + (0x85880+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_MASK2_ADDR(base,m) ((base) + (0x85c00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_MASK2_ADDR(base,m) ((base) + (0x85c80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_MASK2_ADDR(base,m) ((base) + (0x85d00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_MASK2_ADDR(base,m) ((base) + (0x85d80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_MASK2_ADDR(base,m) ((base) + (0x85e00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_MASK0_SET_ADDR(base,m) ((base) + (0x86000+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_MASK0_SET_ADDR(base,m) ((base) + (0x86080+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_MASK0_SET_ADDR(base,m) ((base) + (0x86100+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_MASK0_SET_ADDR(base,m) ((base) + (0x86180+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_MASK0_SET_ADDR(base,m) ((base) + (0x86480+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_MASK0_SET_ADDR(base,m) ((base) + (0x86500+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_MASK0_SET_ADDR(base,m) ((base) + (0x86800+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_MASK0_SET_ADDR(base,m) ((base) + (0x86880+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_MASK0_SET_ADDR(base,m) ((base) + (0x86c00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_MASK0_SET_ADDR(base,m) ((base) + (0x86c80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_MASK0_SET_ADDR(base,m) ((base) + (0x86d00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_MASK0_SET_ADDR(base,m) ((base) + (0x86d80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_MASK0_SET_ADDR(base,m) ((base) + (0x86e00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_MASK1_SET_ADDR(base,m) ((base) + (0x87000+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_MASK1_SET_ADDR(base,m) ((base) + (0x87080+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_MASK1_SET_ADDR(base,m) ((base) + (0x87100+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_MASK1_SET_ADDR(base,m) ((base) + (0x87180+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_MASK1_SET_ADDR(base,m) ((base) + (0x87480+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_MASK1_SET_ADDR(base,m) ((base) + (0x87500+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_MASK1_SET_ADDR(base,m) ((base) + (0x87800+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_MASK1_SET_ADDR(base,m) ((base) + (0x87880+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_MASK1_SET_ADDR(base,m) ((base) + (0x87c00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_MASK1_SET_ADDR(base,m) ((base) + (0x87c80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_MASK1_SET_ADDR(base,m) ((base) + (0x87d00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_MASK1_SET_ADDR(base,m) ((base) + (0x87d80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_MASK1_SET_ADDR(base,m) ((base) + (0x87e00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_MASK2_SET_ADDR(base,m) ((base) + (0x88000+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_MASK2_SET_ADDR(base,m) ((base) + (0x88080+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_MASK2_SET_ADDR(base,m) ((base) + (0x88100+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_MASK2_SET_ADDR(base,m) ((base) + (0x88180+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_MASK2_SET_ADDR(base,m) ((base) + (0x88480+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_MASK2_SET_ADDR(base,m) ((base) + (0x88500+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_MASK2_SET_ADDR(base,m) ((base) + (0x88800+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_MASK2_SET_ADDR(base,m) ((base) + (0x88880+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_MASK2_SET_ADDR(base,m) ((base) + (0x88c00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_MASK2_SET_ADDR(base,m) ((base) + (0x88c80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_MASK2_SET_ADDR(base,m) ((base) + (0x88d00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_MASK2_SET_ADDR(base,m) ((base) + (0x88d80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_MASK2_SET_ADDR(base,m) ((base) + (0x88e00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_MASK0_CLR_ADDR(base,m) ((base) + (0x89000+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_MASK0_CLR_ADDR(base,m) ((base) + (0x89080+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_MASK0_CLR_ADDR(base,m) ((base) + (0x89100+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_MASK0_CLR_ADDR(base,m) ((base) + (0x89180+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_MASK0_CLR_ADDR(base,m) ((base) + (0x89480+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_MASK0_CLR_ADDR(base,m) ((base) + (0x89500+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_MASK0_CLR_ADDR(base,m) ((base) + (0x89800+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_MASK0_CLR_ADDR(base,m) ((base) + (0x89880+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_MASK0_CLR_ADDR(base,m) ((base) + (0x89c00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_MASK0_CLR_ADDR(base,m) ((base) + (0x89c80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_MASK0_CLR_ADDR(base,m) ((base) + (0x89d00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_MASK0_CLR_ADDR(base,m) ((base) + (0x89d80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_MASK0_CLR_ADDR(base,m) ((base) + (0x89e00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_MASK1_CLR_ADDR(base,m) ((base) + (0x8a000+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_MASK1_CLR_ADDR(base,m) ((base) + (0x8a080+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_MASK1_CLR_ADDR(base,m) ((base) + (0x8a100+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_MASK1_CLR_ADDR(base,m) ((base) + (0x8a180+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_MASK1_CLR_ADDR(base,m) ((base) + (0x8a480+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_MASK1_CLR_ADDR(base,m) ((base) + (0x8a500+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_MASK1_CLR_ADDR(base,m) ((base) + (0x8a800+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_MASK1_CLR_ADDR(base,m) ((base) + (0x8a880+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_MASK1_CLR_ADDR(base,m) ((base) + (0x8ac00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_MASK1_CLR_ADDR(base,m) ((base) + (0x8ac80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_MASK1_CLR_ADDR(base,m) ((base) + (0x8ad00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_MASK1_CLR_ADDR(base,m) ((base) + (0x8ad80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_MASK1_CLR_ADDR(base,m) ((base) + (0x8ae00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_MASK2_CLR_ADDR(base,m) ((base) + (0x8b000+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_MASK2_CLR_ADDR(base,m) ((base) + (0x8b080+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_MASK2_CLR_ADDR(base,m) ((base) + (0x8b100+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_MASK2_CLR_ADDR(base,m) ((base) + (0x8b180+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_MASK2_CLR_ADDR(base,m) ((base) + (0x8b480+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_MASK2_CLR_ADDR(base,m) ((base) + (0x8b500+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_MASK2_CLR_ADDR(base,m) ((base) + (0x8b800+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_MASK2_CLR_ADDR(base,m) ((base) + (0x8b880+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_MASK2_CLR_ADDR(base,m) ((base) + (0x8bc00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_MASK2_CLR_ADDR(base,m) ((base) + (0x8bc80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_MASK2_CLR_ADDR(base,m) ((base) + (0x8bd00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_MASK2_CLR_ADDR(base,m) ((base) + (0x8bd80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_MASK2_CLR_ADDR(base,m) ((base) + (0x8be00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_INTERRUPT_PENDING0_ADDR(base,m) ((base) + (0x8c000+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_INTERRUPT_PENDING0_ADDR(base) ((base) + (0x8c080+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_INTERRUPT_PENDING0_ADDR(base) ((base) + (0x8c100+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_INTERRUPT_PENDING0_ADDR(base) ((base) + (0x8c180+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_INTERRUPT_PENDING0_ADDR(base,m) ((base) + (0x8c480+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_INTERRUPT_PENDING0_ADDR(base,m) ((base) + (0x8c500+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_INTERRUPT_PENDING0_ADDR(base) ((base) + (0x8c800+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_INTERRUPT_PENDING0_ADDR(base,m) ((base) + (0x8c880+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_INTERRUPT_PENDING0_ADDR(base) ((base) + (0x8cc00+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_INTERRUPT_PENDING0_ADDR(base,m) ((base) + (0x8cc80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_INTERRUPT_PENDING0_ADDR(base) ((base) + (0x8cd00+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_INTERRUPT_PENDING0_ADDR(base) ((base) + (0x8cd80+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_INTERRUPT_PENDING0_ADDR(base) ((base) + (0x8ce00+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_INTERRUPT_PENDING1_ADDR(base,m) ((base) + (0x8d000+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_INTERRUPT_PENDING1_ADDR(base) ((base) + (0x8d080+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_INTERRUPT_PENDING1_ADDR(base) ((base) + (0x8d100+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_INTERRUPT_PENDING1_ADDR(base) ((base) + (0x8d180+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_INTERRUPT_PENDING1_ADDR(base,m) ((base) + (0x8d480+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_INTERRUPT_PENDING1_ADDR(base,m) ((base) + (0x8d500+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_INTERRUPT_PENDING1_ADDR(base) ((base) + (0x8d800+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_INTERRUPT_PENDING1_ADDR(base,m) ((base) + (0x8d880+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_INTERRUPT_PENDING1_ADDR(base) ((base) + (0x8dc00+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_INTERRUPT_PENDING1_ADDR(base,m) ((base) + (0x8dc80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_INTERRUPT_PENDING1_ADDR(base) ((base) + (0x8dd00+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_INTERRUPT_PENDING1_ADDR(base) ((base) + (0x8dd80+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_INTERRUPT_PENDING1_ADDR(base) ((base) + (0x8de00+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_INTERRUPT_PENDING2_ADDR(base,m) ((base) + (0x8e000+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_INTERRUPT_PENDING2_ADDR(base) ((base) + (0x8e080+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_INTERRUPT_PENDING2_ADDR(base) ((base) + (0x8e100+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_INTERRUPT_PENDING2_ADDR(base) ((base) + (0x8e180+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_INTERRUPT_PENDING2_ADDR(base,m) ((base) + (0x8e480+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_INTERRUPT_PENDING2_ADDR(base,m) ((base) + (0x8e500+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_INTERRUPT_PENDING2_ADDR(base) ((base) + (0x8e800+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_INTERRUPT_PENDING2_ADDR(base,m) ((base) + (0x8e880+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_INTERRUPT_PENDING2_ADDR(base) ((base) + (0x8ec00+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_INTERRUPT_PENDING2_ADDR(base,m) ((base) + (0x8ec80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_INTERRUPT_PENDING2_ADDR(base) ((base) + (0x8ed00+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_INTERRUPT_PENDING2_ADDR(base) ((base) + (0x8ed80+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_INTERRUPT_PENDING2_ADDR(base) ((base) + (0x8ee00+0*0x4UL))
#else
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_ADDR(base) ((base) + (0x80600))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_INTERRUPT_ADDR(base) ((base) + (0x80608))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_ADDR(base) ((base) + (0x80610))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_FORCE_ADDR(base) ((base) + (0x80650))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_ADDR(base) ((base) + (0x80680))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK0_ADDR(base) ((base) + (0x80688))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_ADDR(base) ((base) + (0x80690))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK1_ADDR(base) ((base) + (0x806c0))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK1_ADDR(base) ((base) + (0x806c8))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK1_ADDR(base) ((base) + (0x806d0))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_ADDR(base) ((base) + (0x80700))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK2_ADDR(base) ((base) + (0x80708))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_ADDR(base) ((base) + (0x80710))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_SET_ADDR(base) ((base) + (0x80780))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK0_SET_ADDR(base) ((base) + (0x80788))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_SET_ADDR(base) ((base) + (0x80790))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK1_SET_ADDR(base) ((base) + (0x807c0))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK1_SET_ADDR(base) ((base) + (0x807c8))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK1_SET_ADDR(base) ((base) + (0x807d0))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_SET_ADDR(base) ((base) + (0x80800))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK2_SET_ADDR(base) ((base) + (0x80808))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_SET_ADDR(base) ((base) + (0x80810))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_CLR_ADDR(base) ((base) + (0x80880))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK0_CLR_ADDR(base) ((base) + (0x80888))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_CLR_ADDR(base) ((base) + (0x80890))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK1_CLR_ADDR(base) ((base) + (0x808c0))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK1_CLR_ADDR(base) ((base) + (0x808c8))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK1_CLR_ADDR(base) ((base) + (0x808d0))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_CLR_ADDR(base) ((base) + (0x80900))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK2_CLR_ADDR(base) ((base) + (0x80908))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_CLR_ADDR(base) ((base) + (0x80910))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING0_ADDR(base) ((base) + (0x80980))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_INTERRUPT_PENDING0_ADDR(base) ((base) + (0x80988))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING0_ADDR(base) ((base) + (0x80990))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING1_ADDR(base) ((base) + (0x809c0))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_INTERRUPT_PENDING1_ADDR(base) ((base) + (0x809c8))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING1_ADDR(base) ((base) + (0x809d0))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING2_ADDR(base) ((base) + (0x80a00))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_INTERRUPT_PENDING2_ADDR(base) ((base) + (0x80a08))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING2_ADDR(base) ((base) + (0x80a10))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_INTERRUPT_ADDR(base,m) ((base) + (0x81000+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_INTERRUPT_ADDR(base) ((base) + (0x81080+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_INTERRUPT_ADDR(base) ((base) + (0x81100+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_INTERRUPT_ADDR(base) ((base) + (0x81180+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_INTERRUPT_ADDR(base,m) ((base) + (0x81480+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_INTERRUPT_ADDR(base,m) ((base) + (0x81500+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_INTERRUPT_ADDR(base) ((base) + (0x81800+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_INTERRUPT_ADDR(base,m) ((base) + (0x81880+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_INTERRUPT_ADDR(base) ((base) + (0x81c00+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_INTERRUPT_ADDR(base,m) ((base) + (0x81c80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_INTERRUPT_ADDR(base) ((base) + (0x81d00+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_INTERRUPT_ADDR(base) ((base) + (0x81d80+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_INTERRUPT_ADDR(base) ((base) + (0x81e00+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_FORCE_ADDR(base,m) ((base) + (0x82000+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_FORCE_ADDR(base) ((base) + (0x82080+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_FORCE_ADDR(base) ((base) + (0x82100+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_FORCE_ADDR(base) ((base) + (0x82180+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_FORCE_ADDR(base,m) ((base) + (0x82480+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_FORCE_ADDR(base,m) ((base) + (0x82500+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_FORCE_ADDR(base) ((base) + (0x82800+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_FORCE_ADDR(base,m) ((base) + (0x82880+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_FORCE_ADDR(base) ((base) + (0x82c00+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_FORCE_ADDR(base,m) ((base) + (0x82c80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_FORCE_ADDR(base) ((base) + (0x82d00+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_FORCE_ADDR(base) ((base) + (0x82d80+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_FORCE_ADDR(base) ((base) + (0x82e00+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_MASK0_ADDR(base,m) ((base) + (0x83000+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_MASK0_ADDR(base,m) ((base) + (0x83080+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_MASK0_ADDR(base,m) ((base) + (0x83100+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_MASK0_ADDR(base,m) ((base) + (0x83180+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_MASK0_ADDR(base,m) ((base) + (0x83480+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_MASK0_ADDR(base,m) ((base) + (0x83500+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_MASK0_ADDR(base,m) ((base) + (0x83800+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_MASK0_ADDR(base,m) ((base) + (0x83880+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_MASK0_ADDR(base,m) ((base) + (0x83c00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_MASK0_ADDR(base,m) ((base) + (0x83c80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_MASK0_ADDR(base,m) ((base) + (0x83d00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_MASK0_ADDR(base,m) ((base) + (0x83d80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_MASK0_ADDR(base,m) ((base) + (0x83e00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_MASK1_ADDR(base,m) ((base) + (0x84000+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_MASK1_ADDR(base,m) ((base) + (0x84080+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_MASK1_ADDR(base,m) ((base) + (0x84100+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_MASK1_ADDR(base,m) ((base) + (0x84180+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_MASK1_ADDR(base,m) ((base) + (0x84480+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_MASK1_ADDR(base,m) ((base) + (0x84500+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_MASK1_ADDR(base,m) ((base) + (0x84800+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_MASK1_ADDR(base,m) ((base) + (0x84880+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_MASK1_ADDR(base,m) ((base) + (0x84c00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_MASK1_ADDR(base,m) ((base) + (0x84c80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_MASK1_ADDR(base,m) ((base) + (0x84d00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_MASK1_ADDR(base,m) ((base) + (0x84d80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_MASK1_ADDR(base,m) ((base) + (0x84e00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_MASK2_ADDR(base,m) ((base) + (0x85000+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_MASK2_ADDR(base,m) ((base) + (0x85080+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_MASK2_ADDR(base,m) ((base) + (0x85100+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_MASK2_ADDR(base,m) ((base) + (0x85180+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_MASK2_ADDR(base,m) ((base) + (0x85480+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_MASK2_ADDR(base,m) ((base) + (0x85500+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_MASK2_ADDR(base,m) ((base) + (0x85800+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_MASK2_ADDR(base,m) ((base) + (0x85880+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_MASK2_ADDR(base,m) ((base) + (0x85c00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_MASK2_ADDR(base,m) ((base) + (0x85c80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_MASK2_ADDR(base,m) ((base) + (0x85d00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_MASK2_ADDR(base,m) ((base) + (0x85d80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_MASK2_ADDR(base,m) ((base) + (0x85e00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_MASK0_SET_ADDR(base,m) ((base) + (0x86000+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_MASK0_SET_ADDR(base,m) ((base) + (0x86080+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_MASK0_SET_ADDR(base,m) ((base) + (0x86100+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_MASK0_SET_ADDR(base,m) ((base) + (0x86180+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_MASK0_SET_ADDR(base,m) ((base) + (0x86480+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_MASK0_SET_ADDR(base,m) ((base) + (0x86500+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_MASK0_SET_ADDR(base,m) ((base) + (0x86800+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_MASK0_SET_ADDR(base,m) ((base) + (0x86880+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_MASK0_SET_ADDR(base,m) ((base) + (0x86c00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_MASK0_SET_ADDR(base,m) ((base) + (0x86c80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_MASK0_SET_ADDR(base,m) ((base) + (0x86d00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_MASK0_SET_ADDR(base,m) ((base) + (0x86d80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_MASK0_SET_ADDR(base,m) ((base) + (0x86e00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_MASK1_SET_ADDR(base,m) ((base) + (0x87000+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_MASK1_SET_ADDR(base,m) ((base) + (0x87080+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_MASK1_SET_ADDR(base,m) ((base) + (0x87100+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_MASK1_SET_ADDR(base,m) ((base) + (0x87180+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_MASK1_SET_ADDR(base,m) ((base) + (0x87480+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_MASK1_SET_ADDR(base,m) ((base) + (0x87500+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_MASK1_SET_ADDR(base,m) ((base) + (0x87800+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_MASK1_SET_ADDR(base,m) ((base) + (0x87880+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_MASK1_SET_ADDR(base,m) ((base) + (0x87c00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_MASK1_SET_ADDR(base,m) ((base) + (0x87c80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_MASK1_SET_ADDR(base,m) ((base) + (0x87d00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_MASK1_SET_ADDR(base,m) ((base) + (0x87d80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_MASK1_SET_ADDR(base,m) ((base) + (0x87e00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_MASK2_SET_ADDR(base,m) ((base) + (0x88000+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_MASK2_SET_ADDR(base,m) ((base) + (0x88080+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_MASK2_SET_ADDR(base,m) ((base) + (0x88100+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_MASK2_SET_ADDR(base,m) ((base) + (0x88180+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_MASK2_SET_ADDR(base,m) ((base) + (0x88480+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_MASK2_SET_ADDR(base,m) ((base) + (0x88500+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_MASK2_SET_ADDR(base,m) ((base) + (0x88800+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_MASK2_SET_ADDR(base,m) ((base) + (0x88880+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_MASK2_SET_ADDR(base,m) ((base) + (0x88c00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_MASK2_SET_ADDR(base,m) ((base) + (0x88c80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_MASK2_SET_ADDR(base,m) ((base) + (0x88d00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_MASK2_SET_ADDR(base,m) ((base) + (0x88d80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_MASK2_SET_ADDR(base,m) ((base) + (0x88e00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_MASK0_CLR_ADDR(base,m) ((base) + (0x89000+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_MASK0_CLR_ADDR(base,m) ((base) + (0x89080+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_MASK0_CLR_ADDR(base,m) ((base) + (0x89100+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_MASK0_CLR_ADDR(base,m) ((base) + (0x89180+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_MASK0_CLR_ADDR(base,m) ((base) + (0x89480+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_MASK0_CLR_ADDR(base,m) ((base) + (0x89500+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_MASK0_CLR_ADDR(base,m) ((base) + (0x89800+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_MASK0_CLR_ADDR(base,m) ((base) + (0x89880+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_MASK0_CLR_ADDR(base,m) ((base) + (0x89c00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_MASK0_CLR_ADDR(base,m) ((base) + (0x89c80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_MASK0_CLR_ADDR(base,m) ((base) + (0x89d00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_MASK0_CLR_ADDR(base,m) ((base) + (0x89d80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_MASK0_CLR_ADDR(base,m) ((base) + (0x89e00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_MASK1_CLR_ADDR(base,m) ((base) + (0x8a000+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_MASK1_CLR_ADDR(base,m) ((base) + (0x8a080+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_MASK1_CLR_ADDR(base,m) ((base) + (0x8a100+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_MASK1_CLR_ADDR(base,m) ((base) + (0x8a180+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_MASK1_CLR_ADDR(base,m) ((base) + (0x8a480+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_MASK1_CLR_ADDR(base,m) ((base) + (0x8a500+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_MASK1_CLR_ADDR(base,m) ((base) + (0x8a800+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_MASK1_CLR_ADDR(base,m) ((base) + (0x8a880+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_MASK1_CLR_ADDR(base,m) ((base) + (0x8ac00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_MASK1_CLR_ADDR(base,m) ((base) + (0x8ac80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_MASK1_CLR_ADDR(base,m) ((base) + (0x8ad00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_MASK1_CLR_ADDR(base,m) ((base) + (0x8ad80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_MASK1_CLR_ADDR(base,m) ((base) + (0x8ae00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_MASK2_CLR_ADDR(base,m) ((base) + (0x8b000+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_MASK2_CLR_ADDR(base,m) ((base) + (0x8b080+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_MASK2_CLR_ADDR(base,m) ((base) + (0x8b100+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_MASK2_CLR_ADDR(base,m) ((base) + (0x8b180+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_MASK2_CLR_ADDR(base,m) ((base) + (0x8b480+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_MASK2_CLR_ADDR(base,m) ((base) + (0x8b500+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_MASK2_CLR_ADDR(base,m) ((base) + (0x8b800+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_MASK2_CLR_ADDR(base,m) ((base) + (0x8b880+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_MASK2_CLR_ADDR(base,m) ((base) + (0x8bc00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_MASK2_CLR_ADDR(base,m) ((base) + (0x8bc80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_MASK2_CLR_ADDR(base,m) ((base) + (0x8bd00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_MASK2_CLR_ADDR(base,m) ((base) + (0x8bd80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_MASK2_CLR_ADDR(base,m) ((base) + (0x8be00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_INTERRUPT_PENDING0_ADDR(base,m) ((base) + (0x8c000+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_INTERRUPT_PENDING0_ADDR(base) ((base) + (0x8c080+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_INTERRUPT_PENDING0_ADDR(base) ((base) + (0x8c100+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_INTERRUPT_PENDING0_ADDR(base) ((base) + (0x8c180+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_INTERRUPT_PENDING0_ADDR(base,m) ((base) + (0x8c480+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_INTERRUPT_PENDING0_ADDR(base,m) ((base) + (0x8c500+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_INTERRUPT_PENDING0_ADDR(base) ((base) + (0x8c800+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_INTERRUPT_PENDING0_ADDR(base,m) ((base) + (0x8c880+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_INTERRUPT_PENDING0_ADDR(base) ((base) + (0x8cc00+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_INTERRUPT_PENDING0_ADDR(base,m) ((base) + (0x8cc80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_INTERRUPT_PENDING0_ADDR(base) ((base) + (0x8cd00+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_INTERRUPT_PENDING0_ADDR(base) ((base) + (0x8cd80+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_INTERRUPT_PENDING0_ADDR(base) ((base) + (0x8ce00+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_INTERRUPT_PENDING1_ADDR(base,m) ((base) + (0x8d000+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_INTERRUPT_PENDING1_ADDR(base) ((base) + (0x8d080+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_INTERRUPT_PENDING1_ADDR(base) ((base) + (0x8d100+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_INTERRUPT_PENDING1_ADDR(base) ((base) + (0x8d180+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_INTERRUPT_PENDING1_ADDR(base,m) ((base) + (0x8d480+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_INTERRUPT_PENDING1_ADDR(base,m) ((base) + (0x8d500+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_INTERRUPT_PENDING1_ADDR(base) ((base) + (0x8d800+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_INTERRUPT_PENDING1_ADDR(base,m) ((base) + (0x8d880+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_INTERRUPT_PENDING1_ADDR(base) ((base) + (0x8dc00+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_INTERRUPT_PENDING1_ADDR(base,m) ((base) + (0x8dc80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_INTERRUPT_PENDING1_ADDR(base) ((base) + (0x8dd00+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_INTERRUPT_PENDING1_ADDR(base) ((base) + (0x8dd80+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_INTERRUPT_PENDING1_ADDR(base) ((base) + (0x8de00+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_INTERRUPT_PENDING2_ADDR(base,m) ((base) + (0x8e000+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_INTERRUPT_PENDING2_ADDR(base) ((base) + (0x8e080+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_INTERRUPT_PENDING2_ADDR(base) ((base) + (0x8e100+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_INTERRUPT_PENDING2_ADDR(base) ((base) + (0x8e180+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_INTERRUPT_PENDING2_ADDR(base,m) ((base) + (0x8e480+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_INTERRUPT_PENDING2_ADDR(base,m) ((base) + (0x8e500+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_INTERRUPT_PENDING2_ADDR(base) ((base) + (0x8e800+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_INTERRUPT_PENDING2_ADDR(base,m) ((base) + (0x8e880+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_INTERRUPT_PENDING2_ADDR(base) ((base) + (0x8ec00+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_INTERRUPT_PENDING2_ADDR(base,m) ((base) + (0x8ec80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_INTERRUPT_PENDING2_ADDR(base) ((base) + (0x8ed00+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_INTERRUPT_PENDING2_ADDR(base) ((base) + (0x8ed80+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_INTERRUPT_PENDING2_ADDR(base) ((base) + (0x8ee00+0*0x4))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_ADDR(base) ((base) + (0xc0600UL))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_INTERRUPT_ADDR(base) ((base) + (0xc0608UL))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_ADDR(base) ((base) + (0xc0610UL))
#define SOC_NPU_HWTS_HWTS_L1_DFX_INTERRUPT_ADDR(base) ((base) + (0xc0618UL))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_FORCE_ADDR(base) ((base) + (0xc0650UL))
#define SOC_NPU_HWTS_HWTS_L1_DFX_INTERRUPT_FORCE_ADDR(base) ((base) + (0xc0658UL))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_ADDR(base) ((base) + (0xc0680UL))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK0_ADDR(base) ((base) + (0xc0688UL))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_ADDR(base) ((base) + (0xc0690UL))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK1_ADDR(base) ((base) + (0xc06c0UL))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK1_ADDR(base) ((base) + (0xc06c8UL))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK1_ADDR(base) ((base) + (0xc06d0UL))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_ADDR(base) ((base) + (0xc0700UL))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK2_ADDR(base) ((base) + (0xc0708UL))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_ADDR(base) ((base) + (0xc0710UL))
#define SOC_NPU_HWTS_HWTS_L1_DFX_MASK_ADDR(base) ((base) + (0xc0758UL))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_SET_ADDR(base) ((base) + (0xc0780UL))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK0_SET_ADDR(base) ((base) + (0xc0788UL))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_SET_ADDR(base) ((base) + (0xc0790UL))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK1_SET_ADDR(base) ((base) + (0xc07c0UL))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK1_SET_ADDR(base) ((base) + (0xc07c8UL))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK1_SET_ADDR(base) ((base) + (0xc07d0UL))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_SET_ADDR(base) ((base) + (0xc0800UL))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK2_SET_ADDR(base) ((base) + (0xc0808UL))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_SET_ADDR(base) ((base) + (0xc0810UL))
#define SOC_NPU_HWTS_HWTS_L1_DFX_MASK_SET_ADDR(base) ((base) + (0xc0858UL))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_CLR_ADDR(base) ((base) + (0xc0880UL))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK0_CLR_ADDR(base) ((base) + (0xc0888UL))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_CLR_ADDR(base) ((base) + (0xc0890UL))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK1_CLR_ADDR(base) ((base) + (0xc08c0UL))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK1_CLR_ADDR(base) ((base) + (0xc08c8UL))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK1_CLR_ADDR(base) ((base) + (0xc08d0UL))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_CLR_ADDR(base) ((base) + (0xc0900UL))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK2_CLR_ADDR(base) ((base) + (0xc0908UL))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_CLR_ADDR(base) ((base) + (0xc0910UL))
#define SOC_NPU_HWTS_HWTS_L1_DFX_MASK_CLR_ADDR(base) ((base) + (0xc0958UL))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xc0980UL))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xc0988UL))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xc0990UL))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xc09c0UL))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xc09c8UL))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xc09d0UL))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xc0a00UL))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xc0a08UL))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xc0a10UL))
#define SOC_NPU_HWTS_HWTS_L1_DFX_INTERRUPT_PENDING_ADDR(base) ((base) + (0xc0a58UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_INTERRUPT_ADDR(base,m) ((base) + (0xc1000+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_INTERRUPT_ADDR(base) ((base) + (0xc1080+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_INTERRUPT_ADDR(base) ((base) + (0xc1100+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_INTERRUPT_ADDR(base) ((base) + (0xc1180+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_INTERRUPT_ADDR(base,m) ((base) + (0xc1480+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_INTERRUPT_ADDR(base,m) ((base) + (0xc1500+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_INTERRUPT_ADDR(base) ((base) + (0xc1800+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_INTERRUPT_ADDR(base,m) ((base) + (0xc1880+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_INTERRUPT_ADDR(base) ((base) + (0xc1c00+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_INTERRUPT_ADDR(base,m) ((base) + (0xc1c80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_INTERRUPT_ADDR(base) ((base) + (0xc1d00+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_INTERRUPT_ADDR(base) ((base) + (0xc1d80+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR_NS_INTERRUPT0_ADDR(base) ((base) + (0xc1d90UL))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR_NS_INTERRUPT1_ADDR(base) ((base) + (0xc1d94UL))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN_NS_INTERRUPT0_ADDR(base) ((base) + (0xc1d98UL))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN_NS_INTERRUPT1_ADDR(base) ((base) + (0xc1d9cUL))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_INTERRUPT_ADDR(base) ((base) + (0xc1e00+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_LOG_ALMOST_FULL_INTERRUPT_ADDR(base) ((base) + (0xc1e80+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_PROFILE_ALMOST_FULL_INTERRUPT_ADDR(base) ((base) + (0xc1f80+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_FORCE_ADDR(base,m) ((base) + (0xc2000+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_FORCE_ADDR(base) ((base) + (0xc2080+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_FORCE_ADDR(base) ((base) + (0xc2100+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_FORCE_ADDR(base) ((base) + (0xc2180+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_FORCE_ADDR(base,m) ((base) + (0xc2480+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_FORCE_ADDR(base,m) ((base) + (0xc2500+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_FORCE_ADDR(base) ((base) + (0xc2800+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_FORCE_ADDR(base,m) ((base) + (0xc2880+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_FORCE_ADDR(base) ((base) + (0xc2c00+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_FORCE_ADDR(base,m) ((base) + (0xc2c80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_FORCE_ADDR(base) ((base) + (0xc2d00+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_FORCE_ADDR(base) ((base) + (0xc2d80+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR_NS_FORCE0_ADDR(base) ((base) + (0xc2d90+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR_NS_FORCE1_ADDR(base) ((base) + (0xc2d90+1*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN_NS_FORCE0_ADDR(base) ((base) + (0xc2d90+2*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN_NS_FORCE1_ADDR(base) ((base) + (0xc2d90+3*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_FORCE_ADDR(base) ((base) + (0xc2e00+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DFX_LOG_ALMOST_FULL_FORCE_ADDR(base) ((base) + (0xc2e80+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DFX_PROFILE_ALMOST_FULL_FORCE_ADDR(base) ((base) + (0xc2f80+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_MASK0_ADDR(base,m) ((base) + (0xc3000+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_MASK0_ADDR(base,m) ((base) + (0xc3080+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_MASK0_ADDR(base,m) ((base) + (0xc3100+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_MASK0_ADDR(base,m) ((base) + (0xc3180+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_MASK0_ADDR(base,m) ((base) + (0xc3480+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_MASK0_ADDR(base,m) ((base) + (0xc3500+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_MASK0_ADDR(base,m) ((base) + (0xc3800+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_MASK0_ADDR(base,m) ((base) + (0xc3880+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_MASK0_ADDR(base,m) ((base) + (0xc3c00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_MASK0_ADDR(base,m) ((base) + (0xc3c80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_MASK0_ADDR(base,m) ((base) + (0xc3d00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_MASK0_ADDR(base,m) ((base) + (0xc3d80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_MASK0_ADDR(base,m) ((base) + (0xc3e00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_LOG_ALMOST_FULL_MASK_ADDR(base) ((base) + (0xc3e80+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_PROFILE_ALMOST_FULL_MASK_ADDR(base) ((base) + (0xc3f80+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_MASK1_ADDR(base,m) ((base) + (0xc4000+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_MASK1_ADDR(base,m) ((base) + (0xc4080+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_MASK1_ADDR(base,m) ((base) + (0xc4100+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_MASK1_ADDR(base,m) ((base) + (0xc4180+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_MASK1_ADDR(base,m) ((base) + (0xc4480+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_MASK1_ADDR(base,m) ((base) + (0xc4500+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_MASK1_ADDR(base,m) ((base) + (0xc4800+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_MASK1_ADDR(base,m) ((base) + (0xc4880+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_MASK1_ADDR(base,m) ((base) + (0xc4c00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_MASK1_ADDR(base,m) ((base) + (0xc4c80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_MASK1_ADDR(base,m) ((base) + (0xc4d00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_MASK1_ADDR(base,m) ((base) + (0xc4d80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_MASK1_ADDR(base,m) ((base) + (0xc4e00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_MASK2_ADDR(base,m) ((base) + (0xc5000+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_MASK2_ADDR(base,m) ((base) + (0xc5080+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_MASK2_ADDR(base,m) ((base) + (0xc5100+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_MASK2_ADDR(base,m) ((base) + (0xc5180+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_MASK2_ADDR(base,m) ((base) + (0xc5480+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_MASK2_ADDR(base,m) ((base) + (0xc5500+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_MASK2_ADDR(base,m) ((base) + (0xc5800+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_MASK2_ADDR(base,m) ((base) + (0xc5880+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_MASK2_ADDR(base,m) ((base) + (0xc5c00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_MASK2_ADDR(base,m) ((base) + (0xc5c80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_MASK2_ADDR(base,m) ((base) + (0xc5d00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_MASK2_ADDR(base,m) ((base) + (0xc5d80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_MASK2_ADDR(base,m) ((base) + (0xc5e00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_MASK0_SET_ADDR(base,m) ((base) + (0xc6000+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_MASK0_SET_ADDR(base,m) ((base) + (0xc6080+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_MASK0_SET_ADDR(base,m) ((base) + (0xc6100+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_MASK0_SET_ADDR(base,m) ((base) + (0xc6180+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_MASK0_SET_ADDR(base,m) ((base) + (0xc6480+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_MASK0_SET_ADDR(base,m) ((base) + (0xc6500+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_MASK0_SET_ADDR(base,m) ((base) + (0xc6800+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_MASK0_SET_ADDR(base,m) ((base) + (0xc6880+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_MASK0_SET_ADDR(base,m) ((base) + (0xc6c00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_MASK0_SET_ADDR(base,m) ((base) + (0xc6c80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_MASK0_SET_ADDR(base,m) ((base) + (0xc6d00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_MASK0_SET_ADDR(base,m) ((base) + (0xc6d80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_MASK0_SET_ADDR(base,m) ((base) + (0xc6e00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_LOG_ALMOST_FULL_MASK_SET_ADDR(base) ((base) + (0xc6e80+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_PROFILE_ALMOST_FULL_MASK_SET_ADDR(base) ((base) + (0xc6f80+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_MASK1_SET_ADDR(base,m) ((base) + (0xc7000+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_MASK1_SET_ADDR(base,m) ((base) + (0xc7080+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_MASK1_SET_ADDR(base,m) ((base) + (0xc7100+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_MASK1_SET_ADDR(base,m) ((base) + (0xc7180+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_MASK1_SET_ADDR(base,m) ((base) + (0xc7480+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_MASK1_SET_ADDR(base,m) ((base) + (0xc7500+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_MASK1_SET_ADDR(base,m) ((base) + (0xc7800+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_MASK1_SET_ADDR(base,m) ((base) + (0xc7880+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_MASK1_SET_ADDR(base,m) ((base) + (0xc7c00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_MASK1_SET_ADDR(base,m) ((base) + (0xc7c80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_MASK1_SET_ADDR(base,m) ((base) + (0xc7d00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_MASK1_SET_ADDR(base,m) ((base) + (0xc7d80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_MASK1_SET_ADDR(base,m) ((base) + (0xc7e00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_MASK2_SET_ADDR(base,m) ((base) + (0xc8000+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_MASK2_SET_ADDR(base,m) ((base) + (0xc8080+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_MASK2_SET_ADDR(base,m) ((base) + (0xc8100+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_MASK2_SET_ADDR(base,m) ((base) + (0xc8180+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_MASK2_SET_ADDR(base,m) ((base) + (0xc8480+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_MASK2_SET_ADDR(base,m) ((base) + (0xc8500+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_MASK2_SET_ADDR(base,m) ((base) + (0xc8800+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_MASK2_SET_ADDR(base,m) ((base) + (0xc8880+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_MASK2_SET_ADDR(base,m) ((base) + (0xc8c00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_MASK2_SET_ADDR(base,m) ((base) + (0xc8c80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_MASK2_SET_ADDR(base,m) ((base) + (0xc8d00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_MASK2_SET_ADDR(base,m) ((base) + (0xc8d80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_MASK2_SET_ADDR(base,m) ((base) + (0xc8e00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_MASK0_CLR_ADDR(base,m) ((base) + (0xc9000+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_MASK0_CLR_ADDR(base,m) ((base) + (0xc9080+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_MASK0_CLR_ADDR(base,m) ((base) + (0xc9100+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_MASK0_CLR_ADDR(base,m) ((base) + (0xc9180+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_MASK0_CLR_ADDR(base,m) ((base) + (0xc9480+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_MASK0_CLR_ADDR(base,m) ((base) + (0xc9500+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_MASK0_CLR_ADDR(base,m) ((base) + (0xc9800+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_MASK0_CLR_ADDR(base,m) ((base) + (0xc9880+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_MASK0_CLR_ADDR(base,m) ((base) + (0xc9c00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_MASK0_CLR_ADDR(base,m) ((base) + (0xc9c80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_MASK0_CLR_ADDR(base,m) ((base) + (0xc9d00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_MASK0_CLR_ADDR(base,m) ((base) + (0xc9d80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_MASK0_CLR_ADDR(base,m) ((base) + (0xc9e00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_LOG_ALMOST_FULL_MASK_CLR_ADDR(base) ((base) + (0xc9e80+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_PROFILE_ALMOST_FULL_MASK_CLR_ADDR(base) ((base) + (0xc9f80+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_MASK1_CLR_ADDR(base,m) ((base) + (0xca000+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_MASK1_CLR_ADDR(base,m) ((base) + (0xca080+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_MASK1_CLR_ADDR(base,m) ((base) + (0xca100+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_MASK1_CLR_ADDR(base,m) ((base) + (0xca180+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_MASK1_CLR_ADDR(base,m) ((base) + (0xca480+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_MASK1_CLR_ADDR(base,m) ((base) + (0xca500+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_MASK1_CLR_ADDR(base,m) ((base) + (0xca800+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_MASK1_CLR_ADDR(base,m) ((base) + (0xca880+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_MASK1_CLR_ADDR(base,m) ((base) + (0xcac00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_MASK1_CLR_ADDR(base,m) ((base) + (0xcac80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_MASK1_CLR_ADDR(base,m) ((base) + (0xcad00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_MASK1_CLR_ADDR(base,m) ((base) + (0xcad80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_MASK1_CLR_ADDR(base,m) ((base) + (0xcae00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_MASK2_CLR_ADDR(base,m) ((base) + (0xcb000+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_MASK2_CLR_ADDR(base,m) ((base) + (0xcb080+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_MASK2_CLR_ADDR(base,m) ((base) + (0xcb100+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_MASK2_CLR_ADDR(base,m) ((base) + (0xcb180+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_MASK2_CLR_ADDR(base,m) ((base) + (0xcb480+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_MASK2_CLR_ADDR(base,m) ((base) + (0xcb500+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_MASK2_CLR_ADDR(base,m) ((base) + (0xcb800+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_MASK2_CLR_ADDR(base,m) ((base) + (0xcb880+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_MASK2_CLR_ADDR(base,m) ((base) + (0xcbc00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_MASK2_CLR_ADDR(base,m) ((base) + (0xcbc80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_MASK2_CLR_ADDR(base,m) ((base) + (0xcbd00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_MASK2_CLR_ADDR(base,m) ((base) + (0xcbd80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_MASK2_CLR_ADDR(base,m) ((base) + (0xcbe00+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_INTERRUPT_PENDING0_ADDR(base,m) ((base) + (0xcc000+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xcc080+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xcc100+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xcc180+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_INTERRUPT_PENDING0_ADDR(base,m) ((base) + (0xcc480+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_INTERRUPT_PENDING0_ADDR(base,m) ((base) + (0xcc500+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xcc800+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_INTERRUPT_PENDING0_ADDR(base,m) ((base) + (0xcc880+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xccc00+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_INTERRUPT_PENDING0_ADDR(base,m) ((base) + (0xccc80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xccd00+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xccd80+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR0_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xccd90+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR1_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xccd90+1*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN0_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xccd90+2*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN1_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xccd90+3*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xcce00+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_LOG_ALMOST_FULL_INTERRUPT_PENDING_ADDR(base) ((base) + (0xcce80+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_PROFILE_ALMOST_FULL_INTERRUPT_PENDING_ADDR(base) ((base) + (0xccf80+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_INTERRUPT_PENDING1_ADDR(base,m) ((base) + (0xcd000+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xcd080+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xcd100+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xcd180+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_INTERRUPT_PENDING1_ADDR(base,m) ((base) + (0xcd480+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_INTERRUPT_PENDING1_ADDR(base,m) ((base) + (0xcd500+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xcd800+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_INTERRUPT_PENDING1_ADDR(base,m) ((base) + (0xcd880+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xcdc00+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_INTERRUPT_PENDING1_ADDR(base,m) ((base) + (0xcdc80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xcdd00+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xcdd80+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR0_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xcdd90+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR1_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xcdd90+1*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN0_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xcdd90+2*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN1_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xcdd90+3*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xcde00+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_INTERRUPT_PENDING2_ADDR(base,m) ((base) + (0xce000+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xce080+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xce100+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xce180+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_INTERRUPT_PENDING2_ADDR(base,m) ((base) + (0xce480+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_INTERRUPT_PENDING2_ADDR(base,m) ((base) + (0xce500+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xce800+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_INTERRUPT_PENDING2_ADDR(base,m) ((base) + (0xce880+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xcec00+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_INTERRUPT_PENDING2_ADDR(base,m) ((base) + (0xcec80+(m)*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xced00+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xced80+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR0_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xced90+0*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR1_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xced90+1*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN0_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xced90+2*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN1_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xced90+3*0x4UL))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xcee00+0*0x4UL))
#else
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_ADDR(base) ((base) + (0xc0600))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_INTERRUPT_ADDR(base) ((base) + (0xc0608))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_ADDR(base) ((base) + (0xc0610))
#define SOC_NPU_HWTS_HWTS_L1_DFX_INTERRUPT_ADDR(base) ((base) + (0xc0618))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_FORCE_ADDR(base) ((base) + (0xc0650))
#define SOC_NPU_HWTS_HWTS_L1_DFX_INTERRUPT_FORCE_ADDR(base) ((base) + (0xc0658))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_ADDR(base) ((base) + (0xc0680))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK0_ADDR(base) ((base) + (0xc0688))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_ADDR(base) ((base) + (0xc0690))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK1_ADDR(base) ((base) + (0xc06c0))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK1_ADDR(base) ((base) + (0xc06c8))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK1_ADDR(base) ((base) + (0xc06d0))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_ADDR(base) ((base) + (0xc0700))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK2_ADDR(base) ((base) + (0xc0708))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_ADDR(base) ((base) + (0xc0710))
#define SOC_NPU_HWTS_HWTS_L1_DFX_MASK_ADDR(base) ((base) + (0xc0758))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_SET_ADDR(base) ((base) + (0xc0780))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK0_SET_ADDR(base) ((base) + (0xc0788))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_SET_ADDR(base) ((base) + (0xc0790))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK1_SET_ADDR(base) ((base) + (0xc07c0))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK1_SET_ADDR(base) ((base) + (0xc07c8))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK1_SET_ADDR(base) ((base) + (0xc07d0))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_SET_ADDR(base) ((base) + (0xc0800))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK2_SET_ADDR(base) ((base) + (0xc0808))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_SET_ADDR(base) ((base) + (0xc0810))
#define SOC_NPU_HWTS_HWTS_L1_DFX_MASK_SET_ADDR(base) ((base) + (0xc0858))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_CLR_ADDR(base) ((base) + (0xc0880))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK0_CLR_ADDR(base) ((base) + (0xc0888))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_CLR_ADDR(base) ((base) + (0xc0890))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK1_CLR_ADDR(base) ((base) + (0xc08c0))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK1_CLR_ADDR(base) ((base) + (0xc08c8))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK1_CLR_ADDR(base) ((base) + (0xc08d0))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_CLR_ADDR(base) ((base) + (0xc0900))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK2_CLR_ADDR(base) ((base) + (0xc0908))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_CLR_ADDR(base) ((base) + (0xc0910))
#define SOC_NPU_HWTS_HWTS_L1_DFX_MASK_CLR_ADDR(base) ((base) + (0xc0958))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xc0980))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xc0988))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xc0990))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xc09c0))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xc09c8))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xc09d0))
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xc0a00))
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xc0a08))
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xc0a10))
#define SOC_NPU_HWTS_HWTS_L1_DFX_INTERRUPT_PENDING_ADDR(base) ((base) + (0xc0a58))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_INTERRUPT_ADDR(base,m) ((base) + (0xc1000+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_INTERRUPT_ADDR(base) ((base) + (0xc1080+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_INTERRUPT_ADDR(base) ((base) + (0xc1100+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_INTERRUPT_ADDR(base) ((base) + (0xc1180+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_INTERRUPT_ADDR(base,m) ((base) + (0xc1480+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_INTERRUPT_ADDR(base,m) ((base) + (0xc1500+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_INTERRUPT_ADDR(base) ((base) + (0xc1800+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_INTERRUPT_ADDR(base,m) ((base) + (0xc1880+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_INTERRUPT_ADDR(base) ((base) + (0xc1c00+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_INTERRUPT_ADDR(base,m) ((base) + (0xc1c80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_INTERRUPT_ADDR(base) ((base) + (0xc1d00+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_INTERRUPT_ADDR(base) ((base) + (0xc1d80+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR_NS_INTERRUPT0_ADDR(base) ((base) + (0xc1d90))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR_NS_INTERRUPT1_ADDR(base) ((base) + (0xc1d94))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN_NS_INTERRUPT0_ADDR(base) ((base) + (0xc1d98))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN_NS_INTERRUPT1_ADDR(base) ((base) + (0xc1d9c))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_INTERRUPT_ADDR(base) ((base) + (0xc1e00+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_LOG_ALMOST_FULL_INTERRUPT_ADDR(base) ((base) + (0xc1e80+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_PROFILE_ALMOST_FULL_INTERRUPT_ADDR(base) ((base) + (0xc1f80+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_FORCE_ADDR(base,m) ((base) + (0xc2000+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_FORCE_ADDR(base) ((base) + (0xc2080+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_FORCE_ADDR(base) ((base) + (0xc2100+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_FORCE_ADDR(base) ((base) + (0xc2180+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_FORCE_ADDR(base,m) ((base) + (0xc2480+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_FORCE_ADDR(base,m) ((base) + (0xc2500+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_FORCE_ADDR(base) ((base) + (0xc2800+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_FORCE_ADDR(base,m) ((base) + (0xc2880+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_FORCE_ADDR(base) ((base) + (0xc2c00+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_FORCE_ADDR(base,m) ((base) + (0xc2c80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_FORCE_ADDR(base) ((base) + (0xc2d00+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_FORCE_ADDR(base) ((base) + (0xc2d80+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR_NS_FORCE0_ADDR(base) ((base) + (0xc2d90+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR_NS_FORCE1_ADDR(base) ((base) + (0xc2d90+1*0x4))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN_NS_FORCE0_ADDR(base) ((base) + (0xc2d90+2*0x4))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN_NS_FORCE1_ADDR(base) ((base) + (0xc2d90+3*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_FORCE_ADDR(base) ((base) + (0xc2e00+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DFX_LOG_ALMOST_FULL_FORCE_ADDR(base) ((base) + (0xc2e80+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DFX_PROFILE_ALMOST_FULL_FORCE_ADDR(base) ((base) + (0xc2f80+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_MASK0_ADDR(base,m) ((base) + (0xc3000+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_MASK0_ADDR(base,m) ((base) + (0xc3080+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_MASK0_ADDR(base,m) ((base) + (0xc3100+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_MASK0_ADDR(base,m) ((base) + (0xc3180+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_MASK0_ADDR(base,m) ((base) + (0xc3480+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_MASK0_ADDR(base,m) ((base) + (0xc3500+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_MASK0_ADDR(base,m) ((base) + (0xc3800+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_MASK0_ADDR(base,m) ((base) + (0xc3880+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_MASK0_ADDR(base,m) ((base) + (0xc3c00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_MASK0_ADDR(base,m) ((base) + (0xc3c80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_MASK0_ADDR(base,m) ((base) + (0xc3d00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_MASK0_ADDR(base,m) ((base) + (0xc3d80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_MASK0_ADDR(base,m) ((base) + (0xc3e00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_LOG_ALMOST_FULL_MASK_ADDR(base) ((base) + (0xc3e80+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_PROFILE_ALMOST_FULL_MASK_ADDR(base) ((base) + (0xc3f80+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_MASK1_ADDR(base,m) ((base) + (0xc4000+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_MASK1_ADDR(base,m) ((base) + (0xc4080+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_MASK1_ADDR(base,m) ((base) + (0xc4100+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_MASK1_ADDR(base,m) ((base) + (0xc4180+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_MASK1_ADDR(base,m) ((base) + (0xc4480+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_MASK1_ADDR(base,m) ((base) + (0xc4500+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_MASK1_ADDR(base,m) ((base) + (0xc4800+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_MASK1_ADDR(base,m) ((base) + (0xc4880+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_MASK1_ADDR(base,m) ((base) + (0xc4c00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_MASK1_ADDR(base,m) ((base) + (0xc4c80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_MASK1_ADDR(base,m) ((base) + (0xc4d00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_MASK1_ADDR(base,m) ((base) + (0xc4d80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_MASK1_ADDR(base,m) ((base) + (0xc4e00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_MASK2_ADDR(base,m) ((base) + (0xc5000+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_MASK2_ADDR(base,m) ((base) + (0xc5080+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_MASK2_ADDR(base,m) ((base) + (0xc5100+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_MASK2_ADDR(base,m) ((base) + (0xc5180+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_MASK2_ADDR(base,m) ((base) + (0xc5480+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_MASK2_ADDR(base,m) ((base) + (0xc5500+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_MASK2_ADDR(base,m) ((base) + (0xc5800+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_MASK2_ADDR(base,m) ((base) + (0xc5880+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_MASK2_ADDR(base,m) ((base) + (0xc5c00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_MASK2_ADDR(base,m) ((base) + (0xc5c80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_MASK2_ADDR(base,m) ((base) + (0xc5d00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_MASK2_ADDR(base,m) ((base) + (0xc5d80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_MASK2_ADDR(base,m) ((base) + (0xc5e00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_MASK0_SET_ADDR(base,m) ((base) + (0xc6000+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_MASK0_SET_ADDR(base,m) ((base) + (0xc6080+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_MASK0_SET_ADDR(base,m) ((base) + (0xc6100+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_MASK0_SET_ADDR(base,m) ((base) + (0xc6180+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_MASK0_SET_ADDR(base,m) ((base) + (0xc6480+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_MASK0_SET_ADDR(base,m) ((base) + (0xc6500+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_MASK0_SET_ADDR(base,m) ((base) + (0xc6800+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_MASK0_SET_ADDR(base,m) ((base) + (0xc6880+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_MASK0_SET_ADDR(base,m) ((base) + (0xc6c00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_MASK0_SET_ADDR(base,m) ((base) + (0xc6c80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_MASK0_SET_ADDR(base,m) ((base) + (0xc6d00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_MASK0_SET_ADDR(base,m) ((base) + (0xc6d80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_MASK0_SET_ADDR(base,m) ((base) + (0xc6e00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_LOG_ALMOST_FULL_MASK_SET_ADDR(base) ((base) + (0xc6e80+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_PROFILE_ALMOST_FULL_MASK_SET_ADDR(base) ((base) + (0xc6f80+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_MASK1_SET_ADDR(base,m) ((base) + (0xc7000+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_MASK1_SET_ADDR(base,m) ((base) + (0xc7080+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_MASK1_SET_ADDR(base,m) ((base) + (0xc7100+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_MASK1_SET_ADDR(base,m) ((base) + (0xc7180+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_MASK1_SET_ADDR(base,m) ((base) + (0xc7480+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_MASK1_SET_ADDR(base,m) ((base) + (0xc7500+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_MASK1_SET_ADDR(base,m) ((base) + (0xc7800+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_MASK1_SET_ADDR(base,m) ((base) + (0xc7880+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_MASK1_SET_ADDR(base,m) ((base) + (0xc7c00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_MASK1_SET_ADDR(base,m) ((base) + (0xc7c80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_MASK1_SET_ADDR(base,m) ((base) + (0xc7d00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_MASK1_SET_ADDR(base,m) ((base) + (0xc7d80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_MASK1_SET_ADDR(base,m) ((base) + (0xc7e00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_MASK2_SET_ADDR(base,m) ((base) + (0xc8000+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_MASK2_SET_ADDR(base,m) ((base) + (0xc8080+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_MASK2_SET_ADDR(base,m) ((base) + (0xc8100+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_MASK2_SET_ADDR(base,m) ((base) + (0xc8180+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_MASK2_SET_ADDR(base,m) ((base) + (0xc8480+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_MASK2_SET_ADDR(base,m) ((base) + (0xc8500+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_MASK2_SET_ADDR(base,m) ((base) + (0xc8800+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_MASK2_SET_ADDR(base,m) ((base) + (0xc8880+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_MASK2_SET_ADDR(base,m) ((base) + (0xc8c00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_MASK2_SET_ADDR(base,m) ((base) + (0xc8c80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_MASK2_SET_ADDR(base,m) ((base) + (0xc8d00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_MASK2_SET_ADDR(base,m) ((base) + (0xc8d80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_MASK2_SET_ADDR(base,m) ((base) + (0xc8e00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_MASK0_CLR_ADDR(base,m) ((base) + (0xc9000+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_MASK0_CLR_ADDR(base,m) ((base) + (0xc9080+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_MASK0_CLR_ADDR(base,m) ((base) + (0xc9100+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_MASK0_CLR_ADDR(base,m) ((base) + (0xc9180+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_MASK0_CLR_ADDR(base,m) ((base) + (0xc9480+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_MASK0_CLR_ADDR(base,m) ((base) + (0xc9500+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_MASK0_CLR_ADDR(base,m) ((base) + (0xc9800+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_MASK0_CLR_ADDR(base,m) ((base) + (0xc9880+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_MASK0_CLR_ADDR(base,m) ((base) + (0xc9c00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_MASK0_CLR_ADDR(base,m) ((base) + (0xc9c80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_MASK0_CLR_ADDR(base,m) ((base) + (0xc9d00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_MASK0_CLR_ADDR(base,m) ((base) + (0xc9d80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_MASK0_CLR_ADDR(base,m) ((base) + (0xc9e00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_LOG_ALMOST_FULL_MASK_CLR_ADDR(base) ((base) + (0xc9e80+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_PROFILE_ALMOST_FULL_MASK_CLR_ADDR(base) ((base) + (0xc9f80+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_MASK1_CLR_ADDR(base,m) ((base) + (0xca000+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_MASK1_CLR_ADDR(base,m) ((base) + (0xca080+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_MASK1_CLR_ADDR(base,m) ((base) + (0xca100+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_MASK1_CLR_ADDR(base,m) ((base) + (0xca180+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_MASK1_CLR_ADDR(base,m) ((base) + (0xca480+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_MASK1_CLR_ADDR(base,m) ((base) + (0xca500+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_MASK1_CLR_ADDR(base,m) ((base) + (0xca800+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_MASK1_CLR_ADDR(base,m) ((base) + (0xca880+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_MASK1_CLR_ADDR(base,m) ((base) + (0xcac00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_MASK1_CLR_ADDR(base,m) ((base) + (0xcac80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_MASK1_CLR_ADDR(base,m) ((base) + (0xcad00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_MASK1_CLR_ADDR(base,m) ((base) + (0xcad80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_MASK1_CLR_ADDR(base,m) ((base) + (0xcae00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_MASK2_CLR_ADDR(base,m) ((base) + (0xcb000+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_MASK2_CLR_ADDR(base,m) ((base) + (0xcb080+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_MASK2_CLR_ADDR(base,m) ((base) + (0xcb100+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_MASK2_CLR_ADDR(base,m) ((base) + (0xcb180+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_MASK2_CLR_ADDR(base,m) ((base) + (0xcb480+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_MASK2_CLR_ADDR(base,m) ((base) + (0xcb500+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_MASK2_CLR_ADDR(base,m) ((base) + (0xcb800+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_MASK2_CLR_ADDR(base,m) ((base) + (0xcb880+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_MASK2_CLR_ADDR(base,m) ((base) + (0xcbc00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_MASK2_CLR_ADDR(base,m) ((base) + (0xcbc80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_MASK2_CLR_ADDR(base,m) ((base) + (0xcbd00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_MASK2_CLR_ADDR(base,m) ((base) + (0xcbd80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_MASK2_CLR_ADDR(base,m) ((base) + (0xcbe00+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_INTERRUPT_PENDING0_ADDR(base,m) ((base) + (0xcc000+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xcc080+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xcc100+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xcc180+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_INTERRUPT_PENDING0_ADDR(base,m) ((base) + (0xcc480+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_INTERRUPT_PENDING0_ADDR(base,m) ((base) + (0xcc500+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xcc800+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_INTERRUPT_PENDING0_ADDR(base,m) ((base) + (0xcc880+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xccc00+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_INTERRUPT_PENDING0_ADDR(base,m) ((base) + (0xccc80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xccd00+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xccd80+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR0_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xccd90+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR1_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xccd90+1*0x4))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN0_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xccd90+2*0x4))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN1_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xccd90+3*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_INTERRUPT_PENDING0_ADDR(base) ((base) + (0xcce00+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_LOG_ALMOST_FULL_INTERRUPT_PENDING_ADDR(base) ((base) + (0xcce80+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_PROFILE_ALMOST_FULL_INTERRUPT_PENDING_ADDR(base) ((base) + (0xccf80+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_INTERRUPT_PENDING1_ADDR(base,m) ((base) + (0xcd000+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xcd080+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xcd100+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xcd180+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_INTERRUPT_PENDING1_ADDR(base,m) ((base) + (0xcd480+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_INTERRUPT_PENDING1_ADDR(base,m) ((base) + (0xcd500+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xcd800+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_INTERRUPT_PENDING1_ADDR(base,m) ((base) + (0xcd880+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xcdc00+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_INTERRUPT_PENDING1_ADDR(base,m) ((base) + (0xcdc80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xcdd00+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xcdd80+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR0_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xcdd90+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR1_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xcdd90+1*0x4))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN0_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xcdd90+2*0x4))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN1_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xcdd90+3*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_INTERRUPT_PENDING1_ADDR(base) ((base) + (0xcde00+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_INTERRUPT_PENDING2_ADDR(base,m) ((base) + (0xce000+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xce080+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xce100+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xce180+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_INTERRUPT_PENDING2_ADDR(base,m) ((base) + (0xce480+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_INTERRUPT_PENDING2_ADDR(base,m) ((base) + (0xce500+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xce800+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_INTERRUPT_PENDING2_ADDR(base,m) ((base) + (0xce880+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xcec00+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_INTERRUPT_PENDING2_ADDR(base,m) ((base) + (0xcec80+(m)*0x4))
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xced00+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xced80+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR0_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xced90+0*0x4))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR1_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xced90+1*0x4))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN0_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xced90+2*0x4))
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN1_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xced90+3*0x4))
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_INTERRUPT_PENDING2_ADDR(base) ((base) + (0xcee00+0*0x4))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_HWTS_TINY_AXCACHE_SETTING0_ADDR(base) ((base) + (0x102000UL))
#define SOC_NPU_HWTS_TINY_AXCACHE_SETTING1_ADDR(base) ((base) + (0x102004UL))
#define SOC_NPU_HWTS_TINY_SQ_SWAP_BUF_BASE_ADDR_CFG0_ADDR(base) ((base) + (0x102008UL))
#define SOC_NPU_HWTS_TINY_SQ_SWAP_BUF_BASE_ADDR_CFG1_ADDR(base) ((base) + (0x10200cUL))
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_CTRL0_ADDR(base) ((base) + (0x102100UL))
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_CTRL1_ADDR(base) ((base) + (0x102104UL))
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_BASE_ADDR0_ADDR(base) ((base) + (0x102108UL))
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_BASE_ADDR1_ADDR(base) ((base) + (0x10210cUL))
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_WPTR_INITIAL_ADDR(base) ((base) + (0x102110UL))
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_WPTR_ADDR(base) ((base) + (0x102114UL))
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_RPTR_ADDR(base) ((base) + (0x102118UL))
#define SOC_NPU_HWTS_TINY_DFX_LOG_CTRL0_ADDR(base) ((base) + (0x102300UL))
#define SOC_NPU_HWTS_TINY_DFX_LOG_CTRL1_ADDR(base) ((base) + (0x102304UL))
#define SOC_NPU_HWTS_TINY_DFX_LOG_BASE_ADDR0_ADDR(base) ((base) + (0x102308UL))
#define SOC_NPU_HWTS_TINY_DFX_LOG_BASE_ADDR1_ADDR(base) ((base) + (0x10230cUL))
#define SOC_NPU_HWTS_TINY_DFX_LOG_WPTR_INITIAL_ADDR(base) ((base) + (0x102310UL))
#define SOC_NPU_HWTS_TINY_DFX_LOG_WPTR_ADDR(base) ((base) + (0x102314UL))
#define SOC_NPU_HWTS_TINY_DFX_LOG_RPTR_ADDR(base) ((base) + (0x102318UL))
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING0_ADDR(base) ((base) + (0x108200UL))
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING1_ADDR(base) ((base) + (0x108204UL))
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING2_ADDR(base) ((base) + (0x108208UL))
#else
#define SOC_NPU_HWTS_TINY_AXCACHE_SETTING0_ADDR(base) ((base) + (0x102000))
#define SOC_NPU_HWTS_TINY_AXCACHE_SETTING1_ADDR(base) ((base) + (0x102004))
#define SOC_NPU_HWTS_TINY_SQ_SWAP_BUF_BASE_ADDR_CFG0_ADDR(base) ((base) + (0x102008))
#define SOC_NPU_HWTS_TINY_SQ_SWAP_BUF_BASE_ADDR_CFG1_ADDR(base) ((base) + (0x10200c))
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_CTRL0_ADDR(base) ((base) + (0x102100))
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_CTRL1_ADDR(base) ((base) + (0x102104))
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_BASE_ADDR0_ADDR(base) ((base) + (0x102108))
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_BASE_ADDR1_ADDR(base) ((base) + (0x10210c))
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_WPTR_INITIAL_ADDR(base) ((base) + (0x102110))
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_WPTR_ADDR(base) ((base) + (0x102114))
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_RPTR_ADDR(base) ((base) + (0x102118))
#define SOC_NPU_HWTS_TINY_DFX_LOG_CTRL0_ADDR(base) ((base) + (0x102300))
#define SOC_NPU_HWTS_TINY_DFX_LOG_CTRL1_ADDR(base) ((base) + (0x102304))
#define SOC_NPU_HWTS_TINY_DFX_LOG_BASE_ADDR0_ADDR(base) ((base) + (0x102308))
#define SOC_NPU_HWTS_TINY_DFX_LOG_BASE_ADDR1_ADDR(base) ((base) + (0x10230c))
#define SOC_NPU_HWTS_TINY_DFX_LOG_WPTR_INITIAL_ADDR(base) ((base) + (0x102310))
#define SOC_NPU_HWTS_TINY_DFX_LOG_WPTR_ADDR(base) ((base) + (0x102314))
#define SOC_NPU_HWTS_TINY_DFX_LOG_RPTR_ADDR(base) ((base) + (0x102318))
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING0_ADDR(base) ((base) + (0x108200))
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING1_ADDR(base) ((base) + (0x108204))
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING2_ADDR(base) ((base) + (0x108208))
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_ADDR(base) ((base) + (0x109000UL))
#define SOC_NPU_HWTS_TINY_L1_DEBUG_INTERRUPT_ADDR(base) ((base) + (0x109004UL))
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_ADDR(base) ((base) + (0x109008UL))
#define SOC_NPU_HWTS_TINY_L1_DFX_INTERRUPT_ADDR(base) ((base) + (0x10900cUL))
#define SOC_NPU_HWTS_TINY_L1_DFX_INTERRUPT_FORCE_ADDR(base) ((base) + (0x109020UL))
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_FORCE_ADDR(base) ((base) + (0x109024UL))
#define SOC_NPU_HWTS_TINY_L1_NORMAL_MASK_ADDR(base) ((base) + (0x109080UL))
#define SOC_NPU_HWTS_TINY_L1_DEBUG_MASK_ADDR(base) ((base) + (0x109084UL))
#define SOC_NPU_HWTS_TINY_L1_ERROR_MASK_ADDR(base) ((base) + (0x109088UL))
#define SOC_NPU_HWTS_TINY_L1_DFX_MASK_ADDR(base) ((base) + (0x10908cUL))
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_PENDING_ADDR(base) ((base) + (0x109100UL))
#define SOC_NPU_HWTS_TINY_L1_DEBUG_INTERRUPT_PENDING_ADDR(base) ((base) + (0x109104UL))
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_PENDING_ADDR(base) ((base) + (0x109108UL))
#define SOC_NPU_HWTS_TINY_L1_DFX_INTERRUPT_PENDING_ADDR(base) ((base) + (0x10910cUL))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQE_DONE_INTERRUPT_ADDR(base,m) ((base) + (0x10a000+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_PRE_PAUSED_INTERRUPT_ADDR(base) ((base) + (0x10a100+0*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_POST_PAUSED_INTERRUPT_ADDR(base) ((base) + (0x10a200+0*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQ_FULL_INTERRUPT_ADDR(base) ((base) + (0x10a300+0*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_TASK_PAUSED_INTERRUPT_ADDR(base,m) ((base) + (0x10a400+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQ_DONE_INTERRUPT_ADDR(base,m) ((base) + (0x10a500+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQE_WRITTEN_INTERRUPT_ADDR(base,m) ((base) + (0x10a600+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_TASK_DEBUG_INTERRUPT_ADDR(base) ((base) + (0x10a700+0*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_DEBUG_PAUSED_INTERRUPT_ADDR(base,m) ((base) + (0x10a800+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_TASK_ERROR_INTERRUPT_ADDR(base) ((base) + (0x10a900+0*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_TASK_TIMEOUT_INTERRUPT_ADDR(base,m) ((base) + (0x10aa00+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_TASK_TRAP_INTERRUPT_ADDR(base) ((base) + (0x10ab00+0*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_SQE_ERROR_INTERRUPT_ADDR(base) ((base) + (0x10ac00+0*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_SW_STATUS_ERROR_INTERRUPT_ADDR(base) ((base) + (0x10ad00+0*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQE_DONE_FORCE_ADDR(base,m) ((base) + (0x10ae00+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_PRE_PAUSED_FORCE_ADDR(base) ((base) + (0x10af00+0*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_POST_PAUSED_FORCE_ADDR(base) ((base) + (0x10b000+0*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQ_FULL_FORCE_ADDR(base) ((base) + (0x10b100+0*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_TASK_PAUSED_FORCE_ADDR(base,m) ((base) + (0x10b200+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQ_DONE_FORCE_ADDR(base,m) ((base) + (0x10b300+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQE_WRITTEN_FORCE_ADDR(base,m) ((base) + (0x10b400+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_TASK_DEBUG_FORCE_ADDR(base) ((base) + (0x10b500+0*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_DEBUG_PAUSED_FORCE_ADDR(base,m) ((base) + (0x10b600+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_TASK_ERROR_FORCE_ADDR(base) ((base) + (0x10b700+0*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_TASK_TIMEOUT_FORCE_ADDR(base,m) ((base) + (0x10b800+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_TASK_TRAP_FORCE_ADDR(base) ((base) + (0x10b900+0*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_SQE_ERROR_FORCE_ADDR(base) ((base) + (0x10ba00+0*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_SW_STATUS_ERROR_FORCE_ADDR(base) ((base) + (0x10bb00+0*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQE_DONE_MASK_ADDR(base,m) ((base) + (0x10bc00+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_PRE_PAUSED_MASK_ADDR(base,m) ((base) + (0x10bd00+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_POST_PAUSED_MASK_ADDR(base,m) ((base) + (0x10be00+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQ_FULL_MASK_ADDR(base,m) ((base) + (0x10bf00+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_TASK_PAUSED_MASK_ADDR(base,m) ((base) + (0x10c000+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQ_DONE_MASK_ADDR(base,m) ((base) + (0x10c100+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQE_WRITTEN_MASK_ADDR(base,m) ((base) + (0x10c200+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_TASK_DEBUG_MASK_ADDR(base,m) ((base) + (0x10c300+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_DEBUG_PAUSED_MASK_ADDR(base,m) ((base) + (0x10c400+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_TASK_ERROR_MASK_ADDR(base,m) ((base) + (0x10c500+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_TASK_TIMEOUT_MASK_ADDR(base,m) ((base) + (0x10c600+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_TASK_TRAP_MASK_ADDR(base,m) ((base) + (0x10c700+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_SQE_ERROR_MASK_ADDR(base,m) ((base) + (0x10c800+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_SW_STATUS_ERROR_MASK_ADDR(base,m) ((base) + (0x10c900+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQE_DONE_INTERRUPT_PENDING_ADDR(base,m) ((base) + (0x10ca00+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_PRE_PAUSED_INTERRUPT_PENDING_ADDR(base) ((base) + (0x10cb00+0*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_POST_PAUSED_INTERRUPT_PENDING_ADDR(base) ((base) + (0x10cc00+0*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQ_FULL_INTERRUPT_PENDING_ADDR(base) ((base) + (0x10cd00+0*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_TASK_PAUSED_INTERRUPT_PENDING_ADDR(base,m) ((base) + (0x10ce00+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQ_DONE_INTERRUPT_PENDING_ADDR(base,m) ((base) + (0x10cf00+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQE_WRITTEN_INTERRUPT_PENDING_ADDR(base,m) ((base) + (0x10d000+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_TASK_DEBUG_INTERRUPT_PENDING_ADDR(base) ((base) + (0x10d100+0*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_DEBUG_PAUSED_INTERRUPT_PENDING_ADDR(base,m) ((base) + (0x10d200+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_TASK_ERROR_INTERRUPT_PENDING_ADDR(base) ((base) + (0x10d300+0*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_TASK_TIMEOUT_INTERRUPT_PENDING_ADDR(base,m) ((base) + (0x10d400+(m)*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_TASK_TRAP_INTERRUPT_PENDING_ADDR(base) ((base) + (0x10d500+0*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_SQE_ERROR_INTERRUPT_PENDING_ADDR(base) ((base) + (0x10d600+0*0x4UL))
#define SOC_NPU_HWTS_TINY_L2_SW_STATUS_ERROR_INTERRUPT_PENDING_ADDR(base) ((base) + (0x10d700+0*0x4UL))
#else
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_ADDR(base) ((base) + (0x109000))
#define SOC_NPU_HWTS_TINY_L1_DEBUG_INTERRUPT_ADDR(base) ((base) + (0x109004))
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_ADDR(base) ((base) + (0x109008))
#define SOC_NPU_HWTS_TINY_L1_DFX_INTERRUPT_ADDR(base) ((base) + (0x10900c))
#define SOC_NPU_HWTS_TINY_L1_DFX_INTERRUPT_FORCE_ADDR(base) ((base) + (0x109020))
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_FORCE_ADDR(base) ((base) + (0x109024))
#define SOC_NPU_HWTS_TINY_L1_NORMAL_MASK_ADDR(base) ((base) + (0x109080))
#define SOC_NPU_HWTS_TINY_L1_DEBUG_MASK_ADDR(base) ((base) + (0x109084))
#define SOC_NPU_HWTS_TINY_L1_ERROR_MASK_ADDR(base) ((base) + (0x109088))
#define SOC_NPU_HWTS_TINY_L1_DFX_MASK_ADDR(base) ((base) + (0x10908c))
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_PENDING_ADDR(base) ((base) + (0x109100))
#define SOC_NPU_HWTS_TINY_L1_DEBUG_INTERRUPT_PENDING_ADDR(base) ((base) + (0x109104))
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_PENDING_ADDR(base) ((base) + (0x109108))
#define SOC_NPU_HWTS_TINY_L1_DFX_INTERRUPT_PENDING_ADDR(base) ((base) + (0x10910c))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQE_DONE_INTERRUPT_ADDR(base,m) ((base) + (0x10a000+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_PRE_PAUSED_INTERRUPT_ADDR(base) ((base) + (0x10a100+0*0x4))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_POST_PAUSED_INTERRUPT_ADDR(base) ((base) + (0x10a200+0*0x4))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQ_FULL_INTERRUPT_ADDR(base) ((base) + (0x10a300+0*0x4))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_TASK_PAUSED_INTERRUPT_ADDR(base,m) ((base) + (0x10a400+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQ_DONE_INTERRUPT_ADDR(base,m) ((base) + (0x10a500+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQE_WRITTEN_INTERRUPT_ADDR(base,m) ((base) + (0x10a600+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_TASK_DEBUG_INTERRUPT_ADDR(base) ((base) + (0x10a700+0*0x4))
#define SOC_NPU_HWTS_TINY_L2_DEBUG_PAUSED_INTERRUPT_ADDR(base,m) ((base) + (0x10a800+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_TASK_ERROR_INTERRUPT_ADDR(base) ((base) + (0x10a900+0*0x4))
#define SOC_NPU_HWTS_TINY_L2_TASK_TIMEOUT_INTERRUPT_ADDR(base,m) ((base) + (0x10aa00+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_TASK_TRAP_INTERRUPT_ADDR(base) ((base) + (0x10ab00+0*0x4))
#define SOC_NPU_HWTS_TINY_L2_SQE_ERROR_INTERRUPT_ADDR(base) ((base) + (0x10ac00+0*0x4))
#define SOC_NPU_HWTS_TINY_L2_SW_STATUS_ERROR_INTERRUPT_ADDR(base) ((base) + (0x10ad00+0*0x4))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQE_DONE_FORCE_ADDR(base,m) ((base) + (0x10ae00+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_PRE_PAUSED_FORCE_ADDR(base) ((base) + (0x10af00+0*0x4))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_POST_PAUSED_FORCE_ADDR(base) ((base) + (0x10b000+0*0x4))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQ_FULL_FORCE_ADDR(base) ((base) + (0x10b100+0*0x4))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_TASK_PAUSED_FORCE_ADDR(base,m) ((base) + (0x10b200+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQ_DONE_FORCE_ADDR(base,m) ((base) + (0x10b300+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQE_WRITTEN_FORCE_ADDR(base,m) ((base) + (0x10b400+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_TASK_DEBUG_FORCE_ADDR(base) ((base) + (0x10b500+0*0x4))
#define SOC_NPU_HWTS_TINY_L2_DEBUG_PAUSED_FORCE_ADDR(base,m) ((base) + (0x10b600+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_TASK_ERROR_FORCE_ADDR(base) ((base) + (0x10b700+0*0x4))
#define SOC_NPU_HWTS_TINY_L2_TASK_TIMEOUT_FORCE_ADDR(base,m) ((base) + (0x10b800+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_TASK_TRAP_FORCE_ADDR(base) ((base) + (0x10b900+0*0x4))
#define SOC_NPU_HWTS_TINY_L2_SQE_ERROR_FORCE_ADDR(base) ((base) + (0x10ba00+0*0x4))
#define SOC_NPU_HWTS_TINY_L2_SW_STATUS_ERROR_FORCE_ADDR(base) ((base) + (0x10bb00+0*0x4))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQE_DONE_MASK_ADDR(base,m) ((base) + (0x10bc00+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_PRE_PAUSED_MASK_ADDR(base,m) ((base) + (0x10bd00+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_POST_PAUSED_MASK_ADDR(base,m) ((base) + (0x10be00+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQ_FULL_MASK_ADDR(base,m) ((base) + (0x10bf00+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_TASK_PAUSED_MASK_ADDR(base,m) ((base) + (0x10c000+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQ_DONE_MASK_ADDR(base,m) ((base) + (0x10c100+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQE_WRITTEN_MASK_ADDR(base,m) ((base) + (0x10c200+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_TASK_DEBUG_MASK_ADDR(base,m) ((base) + (0x10c300+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_DEBUG_PAUSED_MASK_ADDR(base,m) ((base) + (0x10c400+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_TASK_ERROR_MASK_ADDR(base,m) ((base) + (0x10c500+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_TASK_TIMEOUT_MASK_ADDR(base,m) ((base) + (0x10c600+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_TASK_TRAP_MASK_ADDR(base,m) ((base) + (0x10c700+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_SQE_ERROR_MASK_ADDR(base,m) ((base) + (0x10c800+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_SW_STATUS_ERROR_MASK_ADDR(base,m) ((base) + (0x10c900+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQE_DONE_INTERRUPT_PENDING_ADDR(base,m) ((base) + (0x10ca00+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_PRE_PAUSED_INTERRUPT_PENDING_ADDR(base) ((base) + (0x10cb00+0*0x4))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_POST_PAUSED_INTERRUPT_PENDING_ADDR(base) ((base) + (0x10cc00+0*0x4))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQ_FULL_INTERRUPT_PENDING_ADDR(base) ((base) + (0x10cd00+0*0x4))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_TASK_PAUSED_INTERRUPT_PENDING_ADDR(base,m) ((base) + (0x10ce00+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQ_DONE_INTERRUPT_PENDING_ADDR(base,m) ((base) + (0x10cf00+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQE_WRITTEN_INTERRUPT_PENDING_ADDR(base,m) ((base) + (0x10d000+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_TASK_DEBUG_INTERRUPT_PENDING_ADDR(base) ((base) + (0x10d100+0*0x4))
#define SOC_NPU_HWTS_TINY_L2_DEBUG_PAUSED_INTERRUPT_PENDING_ADDR(base,m) ((base) + (0x10d200+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_TASK_ERROR_INTERRUPT_PENDING_ADDR(base) ((base) + (0x10d300+0*0x4))
#define SOC_NPU_HWTS_TINY_L2_TASK_TIMEOUT_INTERRUPT_PENDING_ADDR(base,m) ((base) + (0x10d400+(m)*0x4))
#define SOC_NPU_HWTS_TINY_L2_TASK_TRAP_INTERRUPT_PENDING_ADDR(base) ((base) + (0x10d500+0*0x4))
#define SOC_NPU_HWTS_TINY_L2_SQE_ERROR_INTERRUPT_PENDING_ADDR(base) ((base) + (0x10d600+0*0x4))
#define SOC_NPU_HWTS_TINY_L2_SW_STATUS_ERROR_INTERRUPT_PENDING_ADDR(base) ((base) + (0x10d700+0*0x4))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_sec_en : 14;
        unsigned int reserved : 18;
    } reg;
} SOC_NPU_HWTS_HWTS_SEC_EN_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_SEC_EN_hwts_sec_en_START (0)
#define SOC_NPU_HWTS_HWTS_SEC_EN_hwts_sec_en_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_tscpu_mid : 8;
        unsigned int hwts_acpu_mid : 8;
        unsigned int reserved : 8;
        unsigned int hwts_sensorhub_mid : 8;
    } reg;
} SOC_NPU_HWTS_HWTS_HOST_MID_CFG_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_HOST_MID_CFG_hwts_tscpu_mid_START (0)
#define SOC_NPU_HWTS_HWTS_HOST_MID_CFG_hwts_tscpu_mid_END (7)
#define SOC_NPU_HWTS_HWTS_HOST_MID_CFG_hwts_acpu_mid_START (8)
#define SOC_NPU_HWTS_HWTS_HOST_MID_CFG_hwts_acpu_mid_END (15)
#define SOC_NPU_HWTS_HWTS_HOST_MID_CFG_hwts_sensorhub_mid_START (24)
#define SOC_NPU_HWTS_HWTS_HOST_MID_CFG_hwts_sensorhub_mid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_mid_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_HWTS_HWTS_HOST_MID_CFG_EN_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_HOST_MID_CFG_EN_hwts_mid_enable_START (0)
#define SOC_NPU_HWTS_HWTS_HOST_MID_CFG_EN_hwts_mid_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_write_value_va : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_HWTS_HWTS_GLB_CTRL_S_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_GLB_CTRL_S_hwts_write_value_va_START (0)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL_S_hwts_write_value_va_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_ffrt_credit_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_HWTS_HWTS_FFRT_CFG0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_FFRT_CFG0_hwts_ffrt_credit_en_START (0)
#define SOC_NPU_HWTS_HWTS_FFRT_CFG0_hwts_ffrt_credit_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_log_en : 1;
        unsigned int hwts_profile_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_HWTS_HWTS_LOG_PMU_CFG0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_LOG_PMU_CFG0_hwts_log_en_START (0)
#define SOC_NPU_HWTS_HWTS_LOG_PMU_CFG0_hwts_log_en_END (0)
#define SOC_NPU_HWTS_HWTS_LOG_PMU_CFG0_hwts_profile_en_START (1)
#define SOC_NPU_HWTS_HWTS_LOG_PMU_CFG0_hwts_profile_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_sq_sec_en : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_SQ_SEC_EN_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_SQ_SEC_EN_hwts_sq_sec_en_START (0)
#define SOC_NPU_HWTS_HWTS_SQ_SEC_EN_hwts_sq_sec_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_sync_cnt : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_NPU_HWTS_HWTS_SYNC_CTRL_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_SYNC_CTRL_hwts_sync_cnt_START (0)
#define SOC_NPU_HWTS_HWTS_SYNC_CTRL_hwts_sync_cnt_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_lock_core_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_HWTS_HWTS_LOCK_CORE_CTRL_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_LOCK_CORE_CTRL_hwts_lock_core_enable_START (0)
#define SOC_NPU_HWTS_HWTS_LOCK_CORE_CTRL_hwts_lock_core_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_base_addr_l : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_AIC_BASE_ADDR_CFG0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIC_BASE_ADDR_CFG0_aic_base_addr_l_START (0)
#define SOC_NPU_HWTS_HWTS_AIC_BASE_ADDR_CFG0_aic_base_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_base_addr_h : 16;
        unsigned int aic_core_shift : 6;
        unsigned int reserved : 10;
    } reg;
} SOC_NPU_HWTS_HWTS_AIC_BASE_ADDR_CFG1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIC_BASE_ADDR_CFG1_aic_base_addr_h_START (0)
#define SOC_NPU_HWTS_HWTS_AIC_BASE_ADDR_CFG1_aic_base_addr_h_END (15)
#define SOC_NPU_HWTS_HWTS_AIC_BASE_ADDR_CFG1_aic_core_shift_START (16)
#define SOC_NPU_HWTS_HWTS_AIC_BASE_ADDR_CFG1_aic_core_shift_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aiv_base_addr_l : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_AIV_BASE_ADDR_CFG0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIV_BASE_ADDR_CFG0_aiv_base_addr_l_START (0)
#define SOC_NPU_HWTS_HWTS_AIV_BASE_ADDR_CFG0_aiv_base_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aiv_base_addr_h : 16;
        unsigned int aiv_core_shift : 6;
        unsigned int reserved : 10;
    } reg;
} SOC_NPU_HWTS_HWTS_AIV_BASE_ADDR_CFG1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIV_BASE_ADDR_CFG1_aiv_base_addr_h_START (0)
#define SOC_NPU_HWTS_HWTS_AIV_BASE_ADDR_CFG1_aiv_base_addr_h_END (15)
#define SOC_NPU_HWTS_HWTS_AIV_BASE_ADDR_CFG1_aiv_core_shift_START (16)
#define SOC_NPU_HWTS_HWTS_AIV_BASE_ADDR_CFG1_aiv_core_shift_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eff_aic_base_addr_l : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_EFF_AIC_BASE_ADDR_CFG0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_EFF_AIC_BASE_ADDR_CFG0_eff_aic_base_addr_l_START (0)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_BASE_ADDR_CFG0_eff_aic_base_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eff_aic_base_addr_h : 16;
        unsigned int eff_aic_core_shift : 6;
        unsigned int reserved : 10;
    } reg;
} SOC_NPU_HWTS_HWTS_EFF_AIC_BASE_ADDR_CFG1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_EFF_AIC_BASE_ADDR_CFG1_eff_aic_base_addr_h_START (0)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_BASE_ADDR_CFG1_eff_aic_base_addr_h_END (15)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_BASE_ADDR_CFG1_eff_aic_core_shift_START (16)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_BASE_ADDR_CFG1_eff_aic_core_shift_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mdc_base_addr_l : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_MDC_BASE_ADDR_CFG0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_MDC_BASE_ADDR_CFG0_mdc_base_addr_l_START (0)
#define SOC_NPU_HWTS_HWTS_MDC_BASE_ADDR_CFG0_mdc_base_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mdc_base_addr_h : 16;
        unsigned int reserved : 15;
        unsigned int mdc_is_virtual : 1;
    } reg;
} SOC_NPU_HWTS_HWTS_MDC_BASE_ADDR_CFG1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_MDC_BASE_ADDR_CFG1_mdc_base_addr_h_START (0)
#define SOC_NPU_HWTS_HWTS_MDC_BASE_ADDR_CFG1_mdc_base_addr_h_END (15)
#define SOC_NPU_HWTS_HWTS_MDC_BASE_ADDR_CFG1_mdc_is_virtual_START (31)
#define SOC_NPU_HWTS_HWTS_MDC_BASE_ADDR_CFG1_mdc_is_virtual_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int s_sq_swap_buf_base_addr_l : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_S_SQ_SWAP_BUF_BASE_ADDR_CFG0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_S_SQ_SWAP_BUF_BASE_ADDR_CFG0_s_sq_swap_buf_base_addr_l_START (0)
#define SOC_NPU_HWTS_HWTS_S_SQ_SWAP_BUF_BASE_ADDR_CFG0_s_sq_swap_buf_base_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int s_sq_swap_buf_base_addr_h : 16;
        unsigned int s_sq_swap_buf_shift : 6;
        unsigned int reserved : 9;
        unsigned int s_sq_swap_buf_is_virtual : 1;
    } reg;
} SOC_NPU_HWTS_HWTS_S_SQ_SWAP_BUF_BASE_ADDR_CFG1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_S_SQ_SWAP_BUF_BASE_ADDR_CFG1_s_sq_swap_buf_base_addr_h_START (0)
#define SOC_NPU_HWTS_HWTS_S_SQ_SWAP_BUF_BASE_ADDR_CFG1_s_sq_swap_buf_base_addr_h_END (15)
#define SOC_NPU_HWTS_HWTS_S_SQ_SWAP_BUF_BASE_ADDR_CFG1_s_sq_swap_buf_shift_START (16)
#define SOC_NPU_HWTS_HWTS_S_SQ_SWAP_BUF_BASE_ADDR_CFG1_s_sq_swap_buf_shift_END (21)
#define SOC_NPU_HWTS_HWTS_S_SQ_SWAP_BUF_BASE_ADDR_CFG1_s_sq_swap_buf_is_virtual_START (31)
#define SOC_NPU_HWTS_HWTS_S_SQ_SWAP_BUF_BASE_ADDR_CFG1_s_sq_swap_buf_is_virtual_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ffrt_swapbuf_addr_is_virtual : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_HWTS_HWTS_FFRT_SWAPBUF_ADDR_CFG_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_FFRT_SWAPBUF_ADDR_CFG_ffrt_swapbuf_addr_is_virtual_START (0)
#define SOC_NPU_HWTS_HWTS_FFRT_SWAPBUF_ADDR_CFG_ffrt_swapbuf_addr_is_virtual_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ffrt_swapbuf_idx_upper : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_NPU_HWTS_HWTS_FFRT_SWAPBUF_IDX_CFG_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_FFRT_SWAPBUF_IDX_CFG_ffrt_swapbuf_idx_upper_START (0)
#define SOC_NPU_HWTS_HWTS_FFRT_SWAPBUF_IDX_CFG_ffrt_swapbuf_idx_upper_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ffrt_mdc_blkdim_en : 1;
        unsigned int ffrt_usr_notify_err_en : 1;
        unsigned int hwts_ffts_swapout_bypass : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_NPU_HWTS_HWTS_FFRT_MDC_BLKDIM_CFG_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_FFRT_MDC_BLKDIM_CFG_ffrt_mdc_blkdim_en_START (0)
#define SOC_NPU_HWTS_HWTS_FFRT_MDC_BLKDIM_CFG_ffrt_mdc_blkdim_en_END (0)
#define SOC_NPU_HWTS_HWTS_FFRT_MDC_BLKDIM_CFG_ffrt_usr_notify_err_en_START (1)
#define SOC_NPU_HWTS_HWTS_FFRT_MDC_BLKDIM_CFG_ffrt_usr_notify_err_en_END (1)
#define SOC_NPU_HWTS_HWTS_FFRT_MDC_BLKDIM_CFG_hwts_ffts_swapout_bypass_START (2)
#define SOC_NPU_HWTS_HWTS_FFRT_MDC_BLKDIM_CFG_hwts_ffts_swapout_bypass_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_notify_send_err_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_HWTS_HWTS_NOTIFY_SEND_ERR_EN_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_NOTIFY_SEND_ERR_EN_hwts_notify_send_err_en_START (0)
#define SOC_NPU_HWTS_HWTS_NOTIFY_SEND_ERR_EN_hwts_notify_send_err_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hts_notify_upper : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_HTS_NOTIFY_UPPER_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_HTS_NOTIFY_UPPER_hts_notify_upper_START (0)
#define SOC_NPU_HWTS_HWTS_HTS_NOTIFY_UPPER_hts_notify_upper_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gen_core_pu_pd_bypass : 1;
        unsigned int eff_core0_pu_pd_bypass : 1;
        unsigned int eff_core1_pu_pd_bypass : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_NPU_HWTS_HWTS_POWER_CTRL0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_POWER_CTRL0_gen_core_pu_pd_bypass_START (0)
#define SOC_NPU_HWTS_HWTS_POWER_CTRL0_gen_core_pu_pd_bypass_END (0)
#define SOC_NPU_HWTS_HWTS_POWER_CTRL0_eff_core0_pu_pd_bypass_START (1)
#define SOC_NPU_HWTS_HWTS_POWER_CTRL0_eff_core0_pu_pd_bypass_END (1)
#define SOC_NPU_HWTS_HWTS_POWER_CTRL0_eff_core1_pu_pd_bypass_START (2)
#define SOC_NPU_HWTS_HWTS_POWER_CTRL0_eff_core1_pu_pd_bypass_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_idle_pd_cnt_l : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_POWER_CTRL1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_POWER_CTRL1_core_idle_pd_cnt_l_START (0)
#define SOC_NPU_HWTS_HWTS_POWER_CTRL1_core_idle_pd_cnt_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_idle_pd_cnt_h : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_HWTS_HWTS_POWER_CTRL2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_POWER_CTRL2_core_idle_pd_cnt_h_START (0)
#define SOC_NPU_HWTS_HWTS_POWER_CTRL2_core_idle_pd_cnt_h_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_pu_pd_timeout_cnt_l : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_POWER_CTRL3_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_POWER_CTRL3_core_pu_pd_timeout_cnt_l_START (0)
#define SOC_NPU_HWTS_HWTS_POWER_CTRL3_core_pu_pd_timeout_cnt_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_pu_pd_timeout_cnt_h : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_HWTS_HWTS_POWER_CTRL4_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_POWER_CTRL4_core_pu_pd_timeout_cnt_h_START (0)
#define SOC_NPU_HWTS_HWTS_POWER_CTRL4_core_pu_pd_timeout_cnt_h_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int burrs_filter_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_POWER_CTRL5_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_POWER_CTRL5_burrs_filter_cnt_START (0)
#define SOC_NPU_HWTS_HWTS_POWER_CTRL5_burrs_filter_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bootup_base_addr_l : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_BOOTUP_CFG0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_BOOTUP_CFG0_bootup_base_addr_l_START (0)
#define SOC_NPU_HWTS_HWTS_BOOTUP_CFG0_bootup_base_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bootup_base_addr_h : 16;
        unsigned int bootup_length : 15;
        unsigned int bootup_addr_is_virtual : 1;
    } reg;
} SOC_NPU_HWTS_HWTS_BOOTUP_CFG1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_BOOTUP_CFG1_bootup_base_addr_h_START (0)
#define SOC_NPU_HWTS_HWTS_BOOTUP_CFG1_bootup_base_addr_h_END (15)
#define SOC_NPU_HWTS_HWTS_BOOTUP_CFG1_bootup_length_START (16)
#define SOC_NPU_HWTS_HWTS_BOOTUP_CFG1_bootup_length_END (30)
#define SOC_NPU_HWTS_HWTS_BOOTUP_CFG1_bootup_addr_is_virtual_START (31)
#define SOC_NPU_HWTS_HWTS_BOOTUP_CFG1_bootup_addr_is_virtual_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bootdown_base_addr_l : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_BOOTDOWN_CFG0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_BOOTDOWN_CFG0_bootdown_base_addr_l_START (0)
#define SOC_NPU_HWTS_HWTS_BOOTDOWN_CFG0_bootdown_base_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bootdown_base_addr_h : 16;
        unsigned int bootdown_length : 15;
        unsigned int bootdown_addr_is_virtual : 1;
    } reg;
} SOC_NPU_HWTS_HWTS_BOOTDOWN_CFG1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_BOOTDOWN_CFG1_bootdown_base_addr_h_START (0)
#define SOC_NPU_HWTS_HWTS_BOOTDOWN_CFG1_bootdown_base_addr_h_END (15)
#define SOC_NPU_HWTS_HWTS_BOOTDOWN_CFG1_bootdown_length_START (16)
#define SOC_NPU_HWTS_HWTS_BOOTDOWN_CFG1_bootdown_length_END (30)
#define SOC_NPU_HWTS_HWTS_BOOTDOWN_CFG1_bootdown_addr_is_virtual_START (31)
#define SOC_NPU_HWTS_HWTS_BOOTDOWN_CFG1_bootdown_addr_is_virtual_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ns_sq_awprot_aic : 3;
        unsigned int reserved_0 : 1;
        unsigned int ns_sq_awprot_aiv : 3;
        unsigned int reserved_1 : 1;
        unsigned int ns_sq_awprot_swapbuf : 3;
        unsigned int reserved_2 : 1;
        unsigned int ns_sq_awprot_cqe : 3;
        unsigned int reserved_3 : 1;
        unsigned int ns_sq_awprot_eff_aic : 3;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 12;
    } reg;
} SOC_NPU_HWTS_HWTS_AXPROT_SETTING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING0_ns_sq_awprot_aic_START (0)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING0_ns_sq_awprot_aic_END (2)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING0_ns_sq_awprot_aiv_START (4)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING0_ns_sq_awprot_aiv_END (6)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING0_ns_sq_awprot_swapbuf_START (8)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING0_ns_sq_awprot_swapbuf_END (10)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING0_ns_sq_awprot_cqe_START (12)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING0_ns_sq_awprot_cqe_END (14)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING0_ns_sq_awprot_eff_aic_START (16)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING0_ns_sq_awprot_eff_aic_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int s_sq_awprot_aic : 3;
        unsigned int reserved_0 : 1;
        unsigned int s_sq_awprot_aiv : 3;
        unsigned int reserved_1 : 1;
        unsigned int s_sq_awprot_swapbuf : 3;
        unsigned int reserved_2 : 1;
        unsigned int s_sq_awprot_cqe : 3;
        unsigned int reserved_3 : 1;
        unsigned int s_sq_awprot_eff_aic : 3;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 12;
    } reg;
} SOC_NPU_HWTS_HWTS_AXPROT_SETTING1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING1_s_sq_awprot_aic_START (0)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING1_s_sq_awprot_aic_END (2)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING1_s_sq_awprot_aiv_START (4)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING1_s_sq_awprot_aiv_END (6)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING1_s_sq_awprot_swapbuf_START (8)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING1_s_sq_awprot_swapbuf_END (10)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING1_s_sq_awprot_cqe_START (12)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING1_s_sq_awprot_cqe_END (14)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING1_s_sq_awprot_eff_aic_START (16)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING1_s_sq_awprot_eff_aic_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awprot_log : 3;
        unsigned int reserved_0 : 1;
        unsigned int awprot_prof : 3;
        unsigned int reserved_1 : 1;
        unsigned int s_sq_awprot_write_value : 3;
        unsigned int reserved_2 : 21;
    } reg;
} SOC_NPU_HWTS_HWTS_AXPROT_SETTING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING2_awprot_log_START (0)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING2_awprot_log_END (2)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING2_awprot_prof_START (4)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING2_awprot_prof_END (6)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING2_s_sq_awprot_write_value_START (8)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING2_s_sq_awprot_write_value_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ns_sq_arprot_aic : 3;
        unsigned int reserved_0 : 1;
        unsigned int ns_sq_arprot_aiv : 3;
        unsigned int reserved_1 : 1;
        unsigned int ns_sq_arprot_swapbuf : 3;
        unsigned int reserved_2 : 1;
        unsigned int ns_sq_arprot_sqe : 3;
        unsigned int reserved_3 : 1;
        unsigned int ns_sq_arprot_eff_aic : 3;
        unsigned int reserved_4 : 1;
        unsigned int arprot_mdc : 3;
        unsigned int reserved_5 : 1;
        unsigned int arprot_usr_mdc : 3;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 4;
    } reg;
} SOC_NPU_HWTS_HWTS_AXPROT_SETTING3_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING3_ns_sq_arprot_aic_START (0)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING3_ns_sq_arprot_aic_END (2)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING3_ns_sq_arprot_aiv_START (4)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING3_ns_sq_arprot_aiv_END (6)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING3_ns_sq_arprot_swapbuf_START (8)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING3_ns_sq_arprot_swapbuf_END (10)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING3_ns_sq_arprot_sqe_START (12)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING3_ns_sq_arprot_sqe_END (14)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING3_ns_sq_arprot_eff_aic_START (16)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING3_ns_sq_arprot_eff_aic_END (18)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING3_arprot_mdc_START (20)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING3_arprot_mdc_END (22)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING3_arprot_usr_mdc_START (24)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING3_arprot_usr_mdc_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int s_sq_arprot_aic : 3;
        unsigned int reserved_0 : 1;
        unsigned int s_sq_arprot_aiv : 3;
        unsigned int reserved_1 : 1;
        unsigned int s_sq_arprot_swapbuf : 3;
        unsigned int reserved_2 : 1;
        unsigned int s_sq_arprot_sqe : 3;
        unsigned int reserved_3 : 1;
        unsigned int s_sq_arprot_eff_aic : 3;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 12;
    } reg;
} SOC_NPU_HWTS_HWTS_AXPROT_SETTING4_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING4_s_sq_arprot_aic_START (0)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING4_s_sq_arprot_aic_END (2)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING4_s_sq_arprot_aiv_START (4)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING4_s_sq_arprot_aiv_END (6)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING4_s_sq_arprot_swapbuf_START (8)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING4_s_sq_arprot_swapbuf_END (10)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING4_s_sq_arprot_sqe_START (12)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING4_s_sq_arprot_sqe_END (14)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING4_s_sq_arprot_eff_aic_START (16)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING4_s_sq_arprot_eff_aic_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_axprot_aic : 3;
        unsigned int reserved_0 : 1;
        unsigned int core_axprot_aiv : 3;
        unsigned int reserved_1 : 1;
        unsigned int core_axprot_eff_aic : 3;
        unsigned int reserved_2 : 1;
        unsigned int axprot_boot : 3;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 16;
    } reg;
} SOC_NPU_HWTS_HWTS_AXPROT_SETTING5_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING5_core_axprot_aic_START (0)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING5_core_axprot_aic_END (2)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING5_core_axprot_aiv_START (4)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING5_core_axprot_aiv_END (6)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING5_core_axprot_eff_aic_START (8)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING5_core_axprot_eff_aic_END (10)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING5_axprot_boot_START (12)
#define SOC_NPU_HWTS_HWTS_AXPROT_SETTING5_axprot_boot_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ns_sq_swap_buf_base_addr_l : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_NS_SQ_SWAP_BUF_BASE_ADDR_CFG0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_NS_SQ_SWAP_BUF_BASE_ADDR_CFG0_ns_sq_swap_buf_base_addr_l_START (0)
#define SOC_NPU_HWTS_HWTS_NS_SQ_SWAP_BUF_BASE_ADDR_CFG0_ns_sq_swap_buf_base_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ns_sq_swap_buf_base_addr_h : 16;
        unsigned int ns_sq_swap_buf_shift : 6;
        unsigned int reserved : 9;
        unsigned int ns_sq_swap_buf_is_virtual : 1;
    } reg;
} SOC_NPU_HWTS_HWTS_NS_SQ_SWAP_BUF_BASE_ADDR_CFG1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_NS_SQ_SWAP_BUF_BASE_ADDR_CFG1_ns_sq_swap_buf_base_addr_h_START (0)
#define SOC_NPU_HWTS_HWTS_NS_SQ_SWAP_BUF_BASE_ADDR_CFG1_ns_sq_swap_buf_base_addr_h_END (15)
#define SOC_NPU_HWTS_HWTS_NS_SQ_SWAP_BUF_BASE_ADDR_CFG1_ns_sq_swap_buf_shift_START (16)
#define SOC_NPU_HWTS_HWTS_NS_SQ_SWAP_BUF_BASE_ADDR_CFG1_ns_sq_swap_buf_shift_END (21)
#define SOC_NPU_HWTS_HWTS_NS_SQ_SWAP_BUF_BASE_ADDR_CFG1_ns_sq_swap_buf_is_virtual_START (31)
#define SOC_NPU_HWTS_HWTS_NS_SQ_SWAP_BUF_BASE_ADDR_CFG1_ns_sq_swap_buf_is_virtual_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arcache_sq : 4;
        unsigned int arsnoop_sq : 1;
        unsigned int reserved_0 : 3;
        unsigned int awcache_cq : 4;
        unsigned int awsnoop_cq : 1;
        unsigned int reserved_1 : 3;
        unsigned int awcache_log : 4;
        unsigned int awsnoop_log : 1;
        unsigned int reserved_2 : 3;
        unsigned int arcache_usr_mdc : 4;
        unsigned int arsnoop_usr_mdc : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_NPU_HWTS_HWTS_AXCACHE_SETTING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING0_arcache_sq_START (0)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING0_arcache_sq_END (3)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING0_arsnoop_sq_START (4)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING0_arsnoop_sq_END (4)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING0_awcache_cq_START (8)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING0_awcache_cq_END (11)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING0_awsnoop_cq_START (12)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING0_awsnoop_cq_END (12)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING0_awcache_log_START (16)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING0_awcache_log_END (19)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING0_awsnoop_log_START (20)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING0_awsnoop_log_END (20)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING0_arcache_usr_mdc_START (24)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING0_arcache_usr_mdc_END (27)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING0_arsnoop_usr_mdc_START (28)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING0_arsnoop_usr_mdc_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awcache_prof : 4;
        unsigned int awsnoop_prof : 1;
        unsigned int reserved_0 : 3;
        unsigned int awcache_swapbuf : 4;
        unsigned int awsnoop_swapbuf : 1;
        unsigned int reserved_1 : 3;
        unsigned int arcache_swapbuf : 4;
        unsigned int arsnoop_swapbuf : 1;
        unsigned int reserved_2 : 3;
        unsigned int arcache_mdc : 4;
        unsigned int arsnoop_mdc : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_NPU_HWTS_HWTS_AXCACHE_SETTING1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING1_awcache_prof_START (0)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING1_awcache_prof_END (3)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING1_awsnoop_prof_START (4)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING1_awsnoop_prof_END (4)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING1_awcache_swapbuf_START (8)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING1_awcache_swapbuf_END (11)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING1_awsnoop_swapbuf_START (12)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING1_awsnoop_swapbuf_END (12)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING1_arcache_swapbuf_START (16)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING1_arcache_swapbuf_END (19)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING1_arsnoop_swapbuf_START (20)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING1_arsnoop_swapbuf_END (20)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING1_arcache_mdc_START (24)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING1_arcache_mdc_END (27)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING1_arsnoop_mdc_START (28)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING1_arsnoop_mdc_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awcache_aic : 4;
        unsigned int awsnoop_aic : 1;
        unsigned int reserved_0 : 3;
        unsigned int arcache_aic : 4;
        unsigned int arsnoop_aic : 1;
        unsigned int reserved_1 : 3;
        unsigned int reserved_2 : 4;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 11;
    } reg;
} SOC_NPU_HWTS_HWTS_AXCACHE_SETTING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING2_awcache_aic_START (0)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING2_awcache_aic_END (3)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING2_awsnoop_aic_START (4)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING2_awsnoop_aic_END (4)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING2_arcache_aic_START (8)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING2_arcache_aic_END (11)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING2_arsnoop_aic_START (12)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING2_arsnoop_aic_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awcache_aiv : 4;
        unsigned int awsnoop_aiv : 1;
        unsigned int reserved_0 : 3;
        unsigned int arcache_aiv : 4;
        unsigned int arsnoop_aiv : 1;
        unsigned int reserved_1 : 3;
        unsigned int reserved_2 : 4;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 3;
        unsigned int reserved_5 : 4;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 3;
    } reg;
} SOC_NPU_HWTS_HWTS_AXCACHE_SETTING3_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING3_awcache_aiv_START (0)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING3_awcache_aiv_END (3)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING3_awsnoop_aiv_START (4)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING3_awsnoop_aiv_END (4)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING3_arcache_aiv_START (8)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING3_arcache_aiv_END (11)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING3_arsnoop_aiv_START (12)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING3_arsnoop_aiv_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awcache_eff_aic : 4;
        unsigned int awsnoop_eff_aic : 1;
        unsigned int reserved_0 : 3;
        unsigned int arcache_eff_aic : 4;
        unsigned int arsnoop_eff_aic : 1;
        unsigned int reserved_1 : 3;
        unsigned int arcache_boot : 4;
        unsigned int arsnoop_boot : 1;
        unsigned int reserved_2 : 11;
    } reg;
} SOC_NPU_HWTS_HWTS_AXCACHE_SETTING4_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING4_awcache_eff_aic_START (0)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING4_awcache_eff_aic_END (3)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING4_awsnoop_eff_aic_START (4)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING4_awsnoop_eff_aic_END (4)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING4_arcache_eff_aic_START (8)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING4_arcache_eff_aic_END (11)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING4_arsnoop_eff_aic_START (12)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING4_arsnoop_eff_aic_END (12)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING4_arcache_boot_START (16)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING4_arcache_boot_END (19)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING4_arsnoop_boot_START (20)
#define SOC_NPU_HWTS_HWTS_AXCACHE_SETTING4_arsnoop_boot_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_ecc_bypass : 1;
        unsigned int syscnt_gray : 1;
        unsigned int acsq_swapout_sqe : 1;
        unsigned int hwts_ecc_err_wb_bypass : 1;
        unsigned int axi_slv_resp_err : 1;
        unsigned int bus_err_bypass : 1;
        unsigned int sqe_err_bypass : 1;
        unsigned int reserved_0 : 9;
        unsigned int aiv_context_switch_enable : 1;
        unsigned int reserved_1 : 7;
        unsigned int flag_update_bypass : 1;
        unsigned int reserved_2 : 7;
    } reg;
} SOC_NPU_HWTS_HWTS_GLB_CTRL0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_GLB_CTRL0_hwts_ecc_bypass_START (0)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL0_hwts_ecc_bypass_END (0)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL0_syscnt_gray_START (1)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL0_syscnt_gray_END (1)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL0_acsq_swapout_sqe_START (2)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL0_acsq_swapout_sqe_END (2)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL0_hwts_ecc_err_wb_bypass_START (3)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL0_hwts_ecc_err_wb_bypass_END (3)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL0_axi_slv_resp_err_START (4)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL0_axi_slv_resp_err_END (4)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL0_bus_err_bypass_START (5)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL0_bus_err_bypass_END (5)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL0_sqe_err_bypass_START (6)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL0_sqe_err_bypass_END (6)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL0_aiv_context_switch_enable_START (16)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL0_aiv_context_switch_enable_END (16)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL0_flag_update_bypass_START (24)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL0_flag_update_bypass_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sq_friendly_aic : 1;
        unsigned int sq_friendly_aiv : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int sq_friendly_eff_aic : 1;
        unsigned int reserved_4 : 1;
        unsigned int notify_friendly : 1;
        unsigned int hts_friendly : 1;
        unsigned int reserved_5 : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_GLB_CTRL1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_GLB_CTRL1_sq_friendly_aic_START (0)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL1_sq_friendly_aic_END (0)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL1_sq_friendly_aiv_START (1)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL1_sq_friendly_aiv_END (1)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL1_sq_friendly_eff_aic_START (6)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL1_sq_friendly_eff_aic_END (6)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL1_notify_friendly_START (8)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL1_notify_friendly_END (8)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL1_hts_friendly_START (9)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL1_hts_friendly_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_task_timeout_bypass : 1;
        unsigned int aiv_task_timeout_bypass : 1;
        unsigned int notify_wait_task_timeout_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int eff_aic_task_timeout_bypass : 1;
        unsigned int hts_event_wait_task_timeout_bypass : 1;
        unsigned int reserved_2 : 25;
    } reg;
} SOC_NPU_HWTS_HWTS_GLB_CTRL2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_GLB_CTRL2_aic_task_timeout_bypass_START (0)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL2_aic_task_timeout_bypass_END (0)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL2_aiv_task_timeout_bypass_START (1)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL2_aiv_task_timeout_bypass_END (1)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL2_notify_wait_task_timeout_bypass_START (2)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL2_notify_wait_task_timeout_bypass_END (2)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL2_eff_aic_task_timeout_bypass_START (5)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL2_eff_aic_task_timeout_bypass_END (5)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL2_hts_event_wait_task_timeout_bypass_START (6)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL2_hts_event_wait_task_timeout_bypass_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_task_runtime_limit_exp : 6;
        unsigned int reserved_0 : 2;
        unsigned int aiv_task_runtime_limit_exp : 6;
        unsigned int reserved_1 : 2;
        unsigned int notify_wait_task_runtime_limit_exp : 6;
        unsigned int reserved_2 : 2;
        unsigned int swapout_task_runtime_limit_exp : 6;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_NPU_HWTS_HWTS_GLB_CTRL3_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_GLB_CTRL3_aic_task_runtime_limit_exp_START (0)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL3_aic_task_runtime_limit_exp_END (5)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL3_aiv_task_runtime_limit_exp_START (8)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL3_aiv_task_runtime_limit_exp_END (13)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL3_notify_wait_task_runtime_limit_exp_START (16)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL3_notify_wait_task_runtime_limit_exp_END (21)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL3_swapout_task_runtime_limit_exp_START (24)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL3_swapout_task_runtime_limit_exp_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 6;
        unsigned int reserved_3 : 2;
        unsigned int hts_event_wait_task_runtime_limit_exp : 6;
        unsigned int reserved_4 : 2;
        unsigned int eff_aic_task_runtime_limit_exp : 6;
        unsigned int reserved_5 : 2;
    } reg;
} SOC_NPU_HWTS_HWTS_GLB_CTRL4_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_GLB_CTRL4_hts_event_wait_task_runtime_limit_exp_START (16)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL4_hts_event_wait_task_runtime_limit_exp_END (21)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL4_eff_aic_task_runtime_limit_exp_START (24)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL4_eff_aic_task_runtime_limit_exp_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_exe_cg_mask : 1;
        unsigned int rtsq_cg_mask : 1;
        unsigned int nmanager_cg_mask : 1;
        unsigned int acsq_cg_mask : 1;
        unsigned int reserved_0 : 1;
        unsigned int notify_tbl_cg_mask : 1;
        unsigned int gs_cg_mask : 1;
        unsigned int profile_cg_mask : 1;
        unsigned int hts_event_tbl_cg_mask : 1;
        unsigned int reserved_1 : 15;
        unsigned int hwts_cg_dly_cnt : 8;
    } reg;
} SOC_NPU_HWTS_HWTS_GLB_CTRL5_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_GLB_CTRL5_hwts_exe_cg_mask_START (0)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL5_hwts_exe_cg_mask_END (0)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL5_rtsq_cg_mask_START (1)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL5_rtsq_cg_mask_END (1)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL5_nmanager_cg_mask_START (2)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL5_nmanager_cg_mask_END (2)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL5_acsq_cg_mask_START (3)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL5_acsq_cg_mask_END (3)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL5_notify_tbl_cg_mask_START (5)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL5_notify_tbl_cg_mask_END (5)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL5_gs_cg_mask_START (6)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL5_gs_cg_mask_END (6)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL5_profile_cg_mask_START (7)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL5_profile_cg_mask_END (7)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL5_hts_event_tbl_cg_mask_START (8)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL5_hts_event_tbl_cg_mask_END (8)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL5_hwts_cg_dly_cnt_START (24)
#define SOC_NPU_HWTS_HWTS_GLB_CTRL5_hwts_cg_dly_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int notifyid_vfid : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_NPU_HWTS_HWTS_NOTIFYID_CTRL_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_NOTIFYID_CTRL_notifyid_vfid_START (0)
#define SOC_NPU_HWTS_HWTS_NOTIFYID_CTRL_notifyid_vfid_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hts_event_id : 10;
        unsigned int hts_dst_id : 6;
        unsigned int hts_uid : 12;
        unsigned int reserved : 3;
        unsigned int hts_event_send : 1;
    } reg;
} SOC_NPU_HWTS_HWTS_HTS_EVENT_SEND_CTRL_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_HTS_EVENT_SEND_CTRL_hts_event_id_START (0)
#define SOC_NPU_HWTS_HWTS_HTS_EVENT_SEND_CTRL_hts_event_id_END (9)
#define SOC_NPU_HWTS_HWTS_HTS_EVENT_SEND_CTRL_hts_dst_id_START (10)
#define SOC_NPU_HWTS_HWTS_HTS_EVENT_SEND_CTRL_hts_dst_id_END (15)
#define SOC_NPU_HWTS_HWTS_HTS_EVENT_SEND_CTRL_hts_uid_START (16)
#define SOC_NPU_HWTS_HWTS_HTS_EVENT_SEND_CTRL_hts_uid_END (27)
#define SOC_NPU_HWTS_HWTS_HTS_EVENT_SEND_CTRL_hts_event_send_START (31)
#define SOC_NPU_HWTS_HWTS_HTS_EVENT_SEND_CTRL_hts_event_send_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ffrt_task_done_pld : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_FFRT_CTRL0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_FFRT_CTRL0_ffrt_task_done_pld_START (0)
#define SOC_NPU_HWTS_HWTS_FFRT_CTRL0_ffrt_task_done_pld_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ffrt_task_done : 1;
        unsigned int ffrt_task_done_block : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_HWTS_HWTS_FFRT_CTRL1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_FFRT_CTRL1_ffrt_task_done_START (0)
#define SOC_NPU_HWTS_HWTS_FFRT_CTRL1_ffrt_task_done_END (0)
#define SOC_NPU_HWTS_HWTS_FFRT_CTRL1_ffrt_task_done_block_START (1)
#define SOC_NPU_HWTS_HWTS_FFRT_CTRL1_ffrt_task_done_block_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rw_eco0 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_RW_ECO0_RESERVED_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_RW_ECO0_RESERVED_rw_eco0_START (0)
#define SOC_NPU_HWTS_HWTS_RW_ECO0_RESERVED_rw_eco0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rw_eco1 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_RW_ECO1_RESERVED_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_RW_ECO1_RESERVED_rw_eco1_START (0)
#define SOC_NPU_HWTS_HWTS_RW_ECO1_RESERVED_rw_eco1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ro_eco0 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_RO_ECO0_RESERVED_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_RO_ECO0_RESERVED_ro_eco0_START (0)
#define SOC_NPU_HWTS_HWTS_RO_ECO0_RESERVED_ro_eco0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ro_eco1 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_RO_ECO1_RESERVED_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_RO_ECO1_RESERVED_ro_eco1_START (0)
#define SOC_NPU_HWTS_HWTS_RO_ECO1_RESERVED_ro_eco1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_prefetch_ecc_pattern0_l : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_PREFETCH_ECC_CTRL0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_CTRL0_hwts_prefetch_ecc_pattern0_l_START (0)
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_CTRL0_hwts_prefetch_ecc_pattern0_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_prefetch_ecc_pattern0_h : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_PREFETCH_ECC_CTRL1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_CTRL1_hwts_prefetch_ecc_pattern0_h_START (0)
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_CTRL1_hwts_prefetch_ecc_pattern0_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_prefetch_ecc_pattern1_l : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_PREFETCH_ECC_CTRL2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_CTRL2_hwts_prefetch_ecc_pattern1_l_START (0)
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_CTRL2_hwts_prefetch_ecc_pattern1_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_prefetch_ecc_pattern1_h : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_PREFETCH_ECC_CTRL3_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_CTRL3_hwts_prefetch_ecc_pattern1_h_START (0)
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_CTRL3_hwts_prefetch_ecc_pattern1_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_prefetch_ecc_pattern2 : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_NPU_HWTS_HWTS_PREFETCH_ECC_CTRL4_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_CTRL4_hwts_prefetch_ecc_pattern2_START (0)
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_CTRL4_hwts_prefetch_ecc_pattern2_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_prefetch_mbit_ecc_err_vld : 1;
        unsigned int hwts_prefetch_mbit_ecc_err_syn : 9;
        unsigned int hwts_prefetch_mbit_ecc_err_addr : 7;
        unsigned int reserved : 15;
    } reg;
} SOC_NPU_HWTS_HWTS_PREFETCH_ECC_DFX0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_DFX0_hwts_prefetch_mbit_ecc_err_vld_START (0)
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_DFX0_hwts_prefetch_mbit_ecc_err_vld_END (0)
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_DFX0_hwts_prefetch_mbit_ecc_err_syn_START (1)
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_DFX0_hwts_prefetch_mbit_ecc_err_syn_END (9)
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_DFX0_hwts_prefetch_mbit_ecc_err_addr_START (10)
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_DFX0_hwts_prefetch_mbit_ecc_err_addr_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_prefetch_1bit_ecc_err_cnt : 10;
        unsigned int hwts_prefetch_1bit_ecc_err_cnt_clr : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_NPU_HWTS_HWTS_PREFETCH_ECC_DFX1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_DFX1_hwts_prefetch_1bit_ecc_err_cnt_START (0)
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_DFX1_hwts_prefetch_1bit_ecc_err_cnt_END (9)
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_DFX1_hwts_prefetch_1bit_ecc_err_cnt_clr_START (10)
#define SOC_NPU_HWTS_HWTS_PREFETCH_ECC_DFX1_hwts_prefetch_1bit_ecc_err_cnt_clr_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_profile_ecc_pattern0_l : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_PROFILE_ECC_CTRL0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_CTRL0_hwts_profile_ecc_pattern0_l_START (0)
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_CTRL0_hwts_profile_ecc_pattern0_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_profile_ecc_pattern0_h : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_PROFILE_ECC_CTRL1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_CTRL1_hwts_profile_ecc_pattern0_h_START (0)
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_CTRL1_hwts_profile_ecc_pattern0_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_profile_ecc_pattern1_l : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_PROFILE_ECC_CTRL2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_CTRL2_hwts_profile_ecc_pattern1_l_START (0)
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_CTRL2_hwts_profile_ecc_pattern1_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_profile_ecc_pattern1_h : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_PROFILE_ECC_CTRL3_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_CTRL3_hwts_profile_ecc_pattern1_h_START (0)
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_CTRL3_hwts_profile_ecc_pattern1_h_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_profile_ecc_pattern2 : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_NPU_HWTS_HWTS_PROFILE_ECC_CTRL4_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_CTRL4_hwts_profile_ecc_pattern2_START (0)
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_CTRL4_hwts_profile_ecc_pattern2_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_profile_mbit_ecc_err_vld : 1;
        unsigned int hwts_profile_mbit_ecc_err_syn : 9;
        unsigned int hwts_profile_mbit_ecc_err_addr : 6;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_HWTS_HWTS_PROFILE_ECC_DFX0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_DFX0_hwts_profile_mbit_ecc_err_vld_START (0)
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_DFX0_hwts_profile_mbit_ecc_err_vld_END (0)
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_DFX0_hwts_profile_mbit_ecc_err_syn_START (1)
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_DFX0_hwts_profile_mbit_ecc_err_syn_END (9)
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_DFX0_hwts_profile_mbit_ecc_err_addr_START (10)
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_DFX0_hwts_profile_mbit_ecc_err_addr_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_profile_1bit_ecc_err_cnt : 10;
        unsigned int hwts_profile_1bit_ecc_err_cnt_clr : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_NPU_HWTS_HWTS_PROFILE_ECC_DFX1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_DFX1_hwts_profile_1bit_ecc_err_cnt_START (0)
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_DFX1_hwts_profile_1bit_ecc_err_cnt_END (9)
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_DFX1_hwts_profile_1bit_ecc_err_cnt_clr_START (10)
#define SOC_NPU_HWTS_HWTS_PROFILE_ECC_DFX1_hwts_profile_1bit_ecc_err_cnt_clr_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_bus_wr_state : 4;
        unsigned int hwts_bus_wr_ost_cnt : 5;
        unsigned int reserved : 23;
    } reg;
} SOC_NPU_HWTS_HWTS_MASTER_BUS_DFX0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_MASTER_BUS_DFX0_hwts_bus_wr_state_START (0)
#define SOC_NPU_HWTS_HWTS_MASTER_BUS_DFX0_hwts_bus_wr_state_END (3)
#define SOC_NPU_HWTS_HWTS_MASTER_BUS_DFX0_hwts_bus_wr_ost_cnt_START (4)
#define SOC_NPU_HWTS_HWTS_MASTER_BUS_DFX0_hwts_bus_wr_ost_cnt_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_bus_rd_state : 4;
        unsigned int hwts_bus_rd_ost_cnt : 5;
        unsigned int reserved : 23;
    } reg;
} SOC_NPU_HWTS_HWTS_MASTER_BUS_DFX1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_MASTER_BUS_DFX1_hwts_bus_rd_state_START (0)
#define SOC_NPU_HWTS_HWTS_MASTER_BUS_DFX1_hwts_bus_rd_state_END (3)
#define SOC_NPU_HWTS_HWTS_MASTER_BUS_DFX1_hwts_bus_rd_ost_cnt_START (4)
#define SOC_NPU_HWTS_HWTS_MASTER_BUS_DFX1_hwts_bus_rd_ost_cnt_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bus_block_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_HWTS_HWTS_MASTER_BUS_DFX2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_MASTER_BUS_DFX2_bus_block_enable_START (0)
#define SOC_NPU_HWTS_HWTS_MASTER_BUS_DFX2_bus_block_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dfx_core_power_state : 3;
        unsigned int reserved_0 : 1;
        unsigned int dfx_core_pu_pd_timeout : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_NPU_HWTS_HWTS_POWER_DFX0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_POWER_DFX0_dfx_core_power_state_START (0)
#define SOC_NPU_HWTS_HWTS_POWER_DFX0_dfx_core_power_state_END (2)
#define SOC_NPU_HWTS_HWTS_POWER_DFX0_dfx_core_pu_pd_timeout_START (4)
#define SOC_NPU_HWTS_HWTS_POWER_DFX0_dfx_core_pu_pd_timeout_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_force_icache_inv : 1;
        unsigned int aic_skip_reset : 1;
        unsigned int aic_skip_warning_check : 1;
        unsigned int reserved_0 : 13;
        unsigned int aic_sq_extra_ram_clear_en : 1;
        unsigned int aic_host_extra_ram_clear_en : 1;
        unsigned int aic_vm_extra_ram_clear_en : 1;
        unsigned int reserved_1 : 13;
    } reg;
} SOC_NPU_HWTS_HWTS_AICV_CTRL0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AICV_CTRL0_aic_force_icache_inv_START (0)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL0_aic_force_icache_inv_END (0)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL0_aic_skip_reset_START (1)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL0_aic_skip_reset_END (1)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL0_aic_skip_warning_check_START (2)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL0_aic_skip_warning_check_END (2)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL0_aic_sq_extra_ram_clear_en_START (16)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL0_aic_sq_extra_ram_clear_en_END (16)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL0_aic_host_extra_ram_clear_en_START (17)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL0_aic_host_extra_ram_clear_en_END (17)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL0_aic_vm_extra_ram_clear_en_START (18)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL0_aic_vm_extra_ram_clear_en_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aiv_force_icache_inv : 1;
        unsigned int aiv_skip_reset : 1;
        unsigned int aiv_skip_warning_check : 1;
        unsigned int reserved_0 : 13;
        unsigned int aiv_sq_extra_ram_clear_en : 1;
        unsigned int aiv_host_extra_ram_clear_en : 1;
        unsigned int aiv_vm_extra_ram_clear_en : 1;
        unsigned int reserved_1 : 13;
    } reg;
} SOC_NPU_HWTS_HWTS_AICV_CTRL1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AICV_CTRL1_aiv_force_icache_inv_START (0)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL1_aiv_force_icache_inv_END (0)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL1_aiv_skip_reset_START (1)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL1_aiv_skip_reset_END (1)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL1_aiv_skip_warning_check_START (2)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL1_aiv_skip_warning_check_END (2)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL1_aiv_sq_extra_ram_clear_en_START (16)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL1_aiv_sq_extra_ram_clear_en_END (16)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL1_aiv_host_extra_ram_clear_en_START (17)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL1_aiv_host_extra_ram_clear_en_END (17)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL1_aiv_vm_extra_ram_clear_en_START (18)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL1_aiv_vm_extra_ram_clear_en_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eff_aic_force_icache_inv : 1;
        unsigned int eff_aic_skip_reset : 1;
        unsigned int eff_aic_skip_warning_check : 1;
        unsigned int reserved_0 : 13;
        unsigned int eff_aic_sq_extra_ram_clear_en : 1;
        unsigned int eff_aic_host_extra_ram_clear_en : 1;
        unsigned int eff_aic_vm_extra_ram_clear_en : 1;
        unsigned int reserved_1 : 13;
    } reg;
} SOC_NPU_HWTS_HWTS_AICV_CTRL2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AICV_CTRL2_eff_aic_force_icache_inv_START (0)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL2_eff_aic_force_icache_inv_END (0)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL2_eff_aic_skip_reset_START (1)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL2_eff_aic_skip_reset_END (1)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL2_eff_aic_skip_warning_check_START (2)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL2_eff_aic_skip_warning_check_END (2)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL2_eff_aic_sq_extra_ram_clear_en_START (16)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL2_eff_aic_sq_extra_ram_clear_en_END (16)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL2_eff_aic_host_extra_ram_clear_en_START (17)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL2_eff_aic_host_extra_ram_clear_en_END (17)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL2_eff_aic_vm_extra_ram_clear_en_START (18)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL2_eff_aic_vm_extra_ram_clear_en_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int each_time_need_rd_pfifo : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_HWTS_HWTS_AICV_CTRL4_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AICV_CTRL4_each_time_need_rd_pfifo_START (0)
#define SOC_NPU_HWTS_HWTS_AICV_CTRL4_each_time_need_rd_pfifo_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_enable_ctrl : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_HWTS_HWTS_AIC_POOL_ENABLE_CTRL_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIC_POOL_ENABLE_CTRL_aic_enable_ctrl_START (0)
#define SOC_NPU_HWTS_HWTS_AIC_POOL_ENABLE_CTRL_aic_enable_ctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_disable_ctrl : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_HWTS_HWTS_AIC_POOL_DISABLE_CTRL_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIC_POOL_DISABLE_CTRL_aic_disable_ctrl_START (0)
#define SOC_NPU_HWTS_HWTS_AIC_POOL_DISABLE_CTRL_aic_disable_ctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_enabled_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_HWTS_HWTS_AIC_POOL_STATUS_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIC_POOL_STATUS_aic_enabled_status_START (0)
#define SOC_NPU_HWTS_HWTS_AIC_POOL_STATUS_aic_enabled_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aiv_enable_ctrl : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_HWTS_HWTS_AIV_POOL_ENABLE_CTRL_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIV_POOL_ENABLE_CTRL_aiv_enable_ctrl_START (0)
#define SOC_NPU_HWTS_HWTS_AIV_POOL_ENABLE_CTRL_aiv_enable_ctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aiv_disable_ctrl : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_HWTS_HWTS_AIV_POOL_DISABLE_CTRL_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIV_POOL_DISABLE_CTRL_aiv_disable_ctrl_START (0)
#define SOC_NPU_HWTS_HWTS_AIV_POOL_DISABLE_CTRL_aiv_disable_ctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aiv_enabled_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_HWTS_HWTS_AIV_POOL_STATUS_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIV_POOL_STATUS_aiv_enabled_status_START (0)
#define SOC_NPU_HWTS_HWTS_AIV_POOL_STATUS_aiv_enabled_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eff_aic_enable_ctrl : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_HWTS_HWTS_EFF_AIC_POOL_ENABLE_CTRL_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_EFF_AIC_POOL_ENABLE_CTRL_eff_aic_enable_ctrl_START (0)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_POOL_ENABLE_CTRL_eff_aic_enable_ctrl_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eff_aic_disable_ctrl : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_HWTS_HWTS_EFF_AIC_POOL_DISABLE_CTRL_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_EFF_AIC_POOL_DISABLE_CTRL_eff_aic_disable_ctrl_START (0)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_POOL_DISABLE_CTRL_eff_aic_disable_ctrl_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eff_aic_enabled_status : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_HWTS_HWTS_EFF_AIC_POOL_STATUS_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_EFF_AIC_POOL_STATUS_eff_aic_enabled_status_START (0)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_POOL_STATUS_eff_aic_enabled_status_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_pmu_cnt0_idx : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_AIC_PMU_CNT0_IDX_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT0_IDX_aic_pmu_cnt0_idx_START (0)
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT0_IDX_aic_pmu_cnt0_idx_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_pmu_cnt1_idx : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_AIC_PMU_CNT1_IDX_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT1_IDX_aic_pmu_cnt1_idx_START (0)
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT1_IDX_aic_pmu_cnt1_idx_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_pmu_cnt2_idx : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_AIC_PMU_CNT2_IDX_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT2_IDX_aic_pmu_cnt2_idx_START (0)
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT2_IDX_aic_pmu_cnt2_idx_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_pmu_cnt3_idx : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_AIC_PMU_CNT3_IDX_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT3_IDX_aic_pmu_cnt3_idx_START (0)
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT3_IDX_aic_pmu_cnt3_idx_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_pmu_cnt4_idx : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_AIC_PMU_CNT4_IDX_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT4_IDX_aic_pmu_cnt4_idx_START (0)
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT4_IDX_aic_pmu_cnt4_idx_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_pmu_cnt5_idx : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_AIC_PMU_CNT5_IDX_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT5_IDX_aic_pmu_cnt5_idx_START (0)
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT5_IDX_aic_pmu_cnt5_idx_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_pmu_cnt6_idx : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_AIC_PMU_CNT6_IDX_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT6_IDX_aic_pmu_cnt6_idx_START (0)
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT6_IDX_aic_pmu_cnt6_idx_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_pmu_cnt7_idx : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_AIC_PMU_CNT7_IDX_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT7_IDX_aic_pmu_cnt7_idx_START (0)
#define SOC_NPU_HWTS_HWTS_AIC_PMU_CNT7_IDX_aic_pmu_cnt7_idx_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aiv_pmu_cnt0_idx : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_AIV_PMU_CNT0_IDX_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT0_IDX_aiv_pmu_cnt0_idx_START (0)
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT0_IDX_aiv_pmu_cnt0_idx_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aiv_pmu_cnt1_idx : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_AIV_PMU_CNT1_IDX_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT1_IDX_aiv_pmu_cnt1_idx_START (0)
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT1_IDX_aiv_pmu_cnt1_idx_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aiv_pmu_cnt2_idx : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_AIV_PMU_CNT2_IDX_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT2_IDX_aiv_pmu_cnt2_idx_START (0)
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT2_IDX_aiv_pmu_cnt2_idx_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aiv_pmu_cnt3_idx : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_AIV_PMU_CNT3_IDX_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT3_IDX_aiv_pmu_cnt3_idx_START (0)
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT3_IDX_aiv_pmu_cnt3_idx_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aiv_pmu_cnt4_idx : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_AIV_PMU_CNT4_IDX_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT4_IDX_aiv_pmu_cnt4_idx_START (0)
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT4_IDX_aiv_pmu_cnt4_idx_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aiv_pmu_cnt5_idx : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_AIV_PMU_CNT5_IDX_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT5_IDX_aiv_pmu_cnt5_idx_START (0)
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT5_IDX_aiv_pmu_cnt5_idx_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aiv_pmu_cnt6_idx : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_AIV_PMU_CNT6_IDX_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT6_IDX_aiv_pmu_cnt6_idx_START (0)
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT6_IDX_aiv_pmu_cnt6_idx_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aiv_pmu_cnt7_idx : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_AIV_PMU_CNT7_IDX_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT7_IDX_aiv_pmu_cnt7_idx_START (0)
#define SOC_NPU_HWTS_HWTS_AIV_PMU_CNT7_IDX_aiv_pmu_cnt7_idx_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eff_aic_pmu_cnt0_idx : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT0_IDX_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT0_IDX_eff_aic_pmu_cnt0_idx_START (0)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT0_IDX_eff_aic_pmu_cnt0_idx_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eff_aic_pmu_cnt1_idx : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT1_IDX_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT1_IDX_eff_aic_pmu_cnt1_idx_START (0)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT1_IDX_eff_aic_pmu_cnt1_idx_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eff_aic_pmu_cnt2_idx : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT2_IDX_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT2_IDX_eff_aic_pmu_cnt2_idx_START (0)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT2_IDX_eff_aic_pmu_cnt2_idx_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eff_aic_pmu_cnt3_idx : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT3_IDX_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT3_IDX_eff_aic_pmu_cnt3_idx_START (0)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT3_IDX_eff_aic_pmu_cnt3_idx_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eff_aic_pmu_cnt4_idx : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT4_IDX_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT4_IDX_eff_aic_pmu_cnt4_idx_START (0)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT4_IDX_eff_aic_pmu_cnt4_idx_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eff_aic_pmu_cnt5_idx : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT5_IDX_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT5_IDX_eff_aic_pmu_cnt5_idx_START (0)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT5_IDX_eff_aic_pmu_cnt5_idx_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eff_aic_pmu_cnt6_idx : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT6_IDX_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT6_IDX_eff_aic_pmu_cnt6_idx_START (0)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT6_IDX_eff_aic_pmu_cnt6_idx_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eff_aic_pmu_cnt7_idx : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT7_IDX_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT7_IDX_eff_aic_pmu_cnt7_idx_START (0)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_PMU_CNT7_IDX_eff_aic_pmu_cnt7_idx_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int pmu_cnt_idx_update : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_HWTS_HWTS_PMU_CNT_IDX_UPDATE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_PMU_CNT_IDX_UPDATE_pmu_cnt_idx_update_START (0)
#define SOC_NPU_HWTS_HWTS_PMU_CNT_IDX_UPDATE_pmu_cnt_idx_update_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_fsm0_state : 4;
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 2;
        unsigned int aic_fsm0_done_with_warn : 1;
        unsigned int aic_fsm0_l1lock : 1;
        unsigned int reserved_2 : 4;
        unsigned int aic_fsm0_cfg_ost_cnt : 1;
        unsigned int aic_fsm0_log_ost_cnt : 2;
        unsigned int aic_fsm0_pmu_ost_cnt : 1;
        unsigned int aic_fsm0_rd_ost_cnt : 2;
        unsigned int aic_done : 1;
        unsigned int aic_except : 1;
        unsigned int aic_warn : 1;
        unsigned int aic_hostid : 2;
        unsigned int reserved_3 : 5;
    } reg;
} SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX0_aic_fsm0_state_START (0)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX0_aic_fsm0_state_END (3)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX0_aic_fsm0_done_with_warn_START (10)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX0_aic_fsm0_done_with_warn_END (10)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX0_aic_fsm0_l1lock_START (11)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX0_aic_fsm0_l1lock_END (11)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX0_aic_fsm0_cfg_ost_cnt_START (16)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX0_aic_fsm0_cfg_ost_cnt_END (16)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX0_aic_fsm0_log_ost_cnt_START (17)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX0_aic_fsm0_log_ost_cnt_END (18)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX0_aic_fsm0_pmu_ost_cnt_START (19)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX0_aic_fsm0_pmu_ost_cnt_END (19)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX0_aic_fsm0_rd_ost_cnt_START (20)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX0_aic_fsm0_rd_ost_cnt_END (21)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX0_aic_done_START (22)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX0_aic_done_END (22)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX0_aic_except_START (23)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX0_aic_except_END (23)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX0_aic_warn_START (24)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX0_aic_warn_END (24)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX0_aic_hostid_START (25)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX0_aic_hostid_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_fsm0_acsqid : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX1_aic_fsm0_acsqid_START (0)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX1_aic_fsm0_acsqid_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 16;
        unsigned int reserved_1: 16;
    } reg;
} SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 8;
        unsigned int aic_fsm0_blkid : 16;
    } reg;
} SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX3_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX3_aic_fsm0_blkid_START (16)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_DFX3_aic_fsm0_blkid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_task_kill : 1;
        unsigned int aic_debug_pause : 1;
        unsigned int aic_debug_resume : 1;
        unsigned int aic_terminate : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_NPU_HWTS_HWTS_AIC_FSM0_CTRL_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_CTRL_aic_task_kill_START (0)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_CTRL_aic_task_kill_END (0)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_CTRL_aic_debug_pause_START (1)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_CTRL_aic_debug_pausel_END (1)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_CTRL_aic_debug_resume_START (2)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_CTRL_aic_debug_resume_END (2)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_CTRL_aic_terminate_START (3)
#define SOC_NPU_HWTS_HWTS_AIC_FSM0_CTRL_aic_terminate_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aiv_fsm0_state : 4;
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 2;
        unsigned int aiv_fsm0_done_with_warn : 1;
        unsigned int aiv_fsm0_l1lock : 1;
        unsigned int reserved_2 : 3;
        unsigned int aiv_fsm0_rstore : 1;
        unsigned int aiv_fsm0_cfg_ost_cnt : 1;
        unsigned int aiv_fsm0_log_ost_cnt : 2;
        unsigned int aiv_fsm0_pmu_ost_cnt : 1;
        unsigned int aiv_fsm0_rd_ost_cnt : 2;
        unsigned int aiv_fsm0_cxt_sw_ost_cnt : 1;
        unsigned int aiv_done : 1;
        unsigned int aiv_except : 1;
        unsigned int aiv_warn : 1;
        unsigned int aiv_cxt_sw_done : 1;
        unsigned int aiv_hostid : 2;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_aiv_fsm0_state_START (0)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_aiv_fsm0_state_END (3)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_aiv_fsm0_done_with_warn_START (10)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_aiv_fsm0_done_with_warn_END (10)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_aiv_fsm0_l1lock_START (11)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_aiv_fsm0_l1lock_END (11)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_aiv_fsm0_rstore_START (15)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_aiv_fsm0_rstore_END (15)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_aiv_fsm0_cfg_ost_cnt_START (16)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_aiv_fsm0_cfg_ost_cnt_END (16)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_aiv_fsm0_log_ost_cnt_START (17)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_aiv_fsm0_log_ost_cnt_END (18)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_aiv_fsm0_pmu_ost_cnt_START (19)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_aiv_fsm0_pmu_ost_cnt_END (19)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_aiv_fsm0_rd_ost_cnt_START (20)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_aiv_fsm0_rd_ost_cnt_END (21)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_aiv_fsm0_cxt_sw_ost_cnt_START (22)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_aiv_fsm0_cxt_sw_ost_cnt_END (22)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_aiv_done_START (23)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_aiv_done_END (23)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_aiv_except_START (24)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_aiv_except_END (24)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_aiv_warn_START (25)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_aiv_warn_END (25)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_aiv_cxt_sw_done_START (26)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_aiv_cxt_sw_done_END (26)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_aiv_hostid_START (27)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX0_aiv_hostid_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aiv_fsm0_acsqid : 3;
        unsigned int reserved_0 : 5;
        unsigned int aiv_fsm0_cxt_sw_bufid : 1;
        unsigned int aiv_fsm0_cxt_sw_state : 2;
        unsigned int reserved_1 : 21;
    } reg;
} SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX1_aiv_fsm0_acsqid_START (0)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX1_aiv_fsm0_acsqid_END (2)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX1_aiv_fsm0_cxt_sw_bufid_START (8)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX1_aiv_fsm0_cxt_sw_bufid_END (8)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX1_aiv_fsm0_cxt_sw_state_START (9)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX1_aiv_fsm0_cxt_sw_state_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 16;
        unsigned int reserved_1: 16;
    } reg;
} SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 8;
        unsigned int aiv_fsm0_blkid : 16;
    } reg;
} SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX3_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX3_aiv_fsm0_blkid_START (16)
#define SOC_NPU_HWTS_HWTS_AIV_FSM0_DFX3_aiv_fsm0_blkid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aiv_task_kill : 1;
        unsigned int aiv_debug_pause : 1;
        unsigned int aiv_debug_resume : 1;
        unsigned int aiv_terminate : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_NPU_HWTS_WTS_AIV_FSM0_CTRL_UNION;
#endif
#define SOC_NPU_HWTS_WTS_AIV_FSM0_CTRL_aiv_task_kill_START (0)
#define SOC_NPU_HWTS_WTS_AIV_FSM0_CTRL_aiv_task_kill_END (0)
#define SOC_NPU_HWTS_WTS_AIV_FSM0_CTRL_aiv_debug_pause_START (1)
#define SOC_NPU_HWTS_WTS_AIV_FSM0_CTRL_aiv_debug_pause_END (1)
#define SOC_NPU_HWTS_WTS_AIV_FSM0_CTRL_aiv_debug_resume_START (2)
#define SOC_NPU_HWTS_WTS_AIV_FSM0_CTRL_aiv_debug_resume_END (2)
#define SOC_NPU_HWTS_WTS_AIV_FSM0_CTRL_aiv_terminate_START (3)
#define SOC_NPU_HWTS_WTS_AIV_FSM0_CTRL_aiv_terminate_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eff_aic_fsm0_state : 4;
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 2;
        unsigned int eff_aic_fsm0_done_with_warn : 1;
        unsigned int eff_aic_fsm0_l1lock : 1;
        unsigned int reserved_2 : 4;
        unsigned int eff_aic_fsm0_cfg_ost_cnt : 1;
        unsigned int eff_aic_fsm0_log_ost_cnt : 2;
        unsigned int eff_aic_fsm0_pmu_ost_cnt : 1;
        unsigned int eff_aic_fsm0_rd_ost_cnt : 2;
        unsigned int eff_aic_done : 1;
        unsigned int eff_aic_except : 1;
        unsigned int eff_aic_warn : 1;
        unsigned int eff_aic_hostid : 2;
        unsigned int reserved_3 : 5;
    } reg;
} SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX0_eff_aic_fsm0_state_START (0)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX0_eff_aic_fsm0_state_END (3)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX0_eff_aic_fsm0_done_with_warn_START (10)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX0_eff_aic_fsm0_done_with_warn_END (10)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX0_eff_aic_fsm0_l1lock_START (11)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX0_eff_aic_fsm0_l1lock_END (11)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX0_eff_aic_fsm0_cfg_ost_cnt_START (16)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX0_eff_aic_fsm0_cfg_ost_cnt_END (16)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX0_eff_aic_fsm0_log_ost_cnt_START (17)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX0_eff_aic_fsm0_log_ost_cnt_END (18)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX0_eff_aic_fsm0_pmu_ost_cnt_START (19)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX0_eff_aic_fsm0_pmu_ost_cnt_END (19)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX0_eff_aic_fsm0_rd_ost_cnt_START (20)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX0_eff_aic_fsm0_rd_ost_cnt_END (21)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX0_eff_aic_done_START (22)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX0_eff_aic_done_END (22)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX0_eff_aic_except_START (23)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX0_eff_aic_except_END (23)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX0_eff_aic_warn_START (24)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX0_eff_aic_warn_END (24)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX0_eff_aic_hostid_START (25)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX0_eff_aic_hostid_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eff_aic_fsm0_acsqid : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX1_eff_aic_fsm0_acsqid_START (0)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX1_eff_aic_fsm0_acsqid_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 16;
        unsigned int reserved_1: 16;
    } reg;
} SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 8;
        unsigned int reserved_1 : 8;
        unsigned int eff_aic_fsm0_blkid : 16;
    } reg;
} SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX3_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX3_eff_aic_fsm0_blkid_START (16)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_DFX3_eff_aic_fsm0_blkid_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int eff_aic_task_kill : 1;
        unsigned int eff_aic_debug_pause : 1;
        unsigned int eff_aic_debug_resume : 1;
        unsigned int eff_aic_terminate : 1;
    } reg;
} SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_CTRL_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_CTRL_eff_aic_task_kill_START (0)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_CTRL_eff_aic_task_kill_END (0)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_CTRL_eff_aic_debug_pause_START (1)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_CTRL_eff_aic_debug_pause_END (1)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_CTRL_eff_aic_debug_resume_START (2)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_CTRL_eff_aic_debug_resume_END (2)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_CTRL_eff_aic_terminate_START (3)
#define SOC_NPU_HWTS_HWTS_EFF_AIC_FSM0_CTRL_eff_aic_terminate_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int aic_utilization_en : 1;
        unsigned int aiv_utilization_en : 1;
        unsigned int eff_aic_utilization_en : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_NPU_HWTS_HWTS_UTILIZATION_CTRL0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_UTILIZATION_CTRL0_aic_utilization_en_START (0)
#define SOC_NPU_HWTS_HWTS_UTILIZATION_CTRL0_aic_utilization_en_END (0)
#define SOC_NPU_HWTS_HWTS_UTILIZATION_CTRL0_aiv_utilization_en_START (1)
#define SOC_NPU_HWTS_HWTS_UTILIZATION_CTRL0_aiv_utilization_en_END (1)
#define SOC_NPU_HWTS_HWTS_UTILIZATION_CTRL0_eff_aic_utilization_en_START (2)
#define SOC_NPU_HWTS_HWTS_UTILIZATION_CTRL0_eff_aic_utilization_en_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts_utilization_wind : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_UTILIZATION_CTRL1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_UTILIZATION_CTRL1_hwts_utilization_wind_START (0)
#define SOC_NPU_HWTS_HWTS_UTILIZATION_CTRL1_hwts_utilization_wind_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vm_aic_busy_cnt : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_NPU_HWTS_HWTS_UTILIZATION_CTRL2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_UTILIZATION_CTRL2_vm_aic_busy_cnt_START (0)
#define SOC_NPU_HWTS_HWTS_UTILIZATION_CTRL2_vm_aic_busy_cnt_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vm_aiv_busy_cnt : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_NPU_HWTS_HWTS_UTILIZATION_CTRL3_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_UTILIZATION_CTRL3_vm_aiv_busy_cnt_START (0)
#define SOC_NPU_HWTS_HWTS_UTILIZATION_CTRL3_vm_aiv_busy_cnt_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vm_eff_aic_busy_cnt : 28;
        unsigned int reserved : 4;
    } reg;
} SOC_NPU_HWTS_HWTS_UTILIZATION_CTRL4_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_UTILIZATION_CTRL4_vm_eff_aic_busy_cnt_START (0)
#define SOC_NPU_HWTS_HWTS_UTILIZATION_CTRL4_vm_eff_aic_busy_cnt_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int acsq_max_gen_aic : 3;
        unsigned int reserved_0 : 1;
        unsigned int acsq_max_eff_aic : 3;
        unsigned int reserved_1 : 1;
        unsigned int acsq_max_aiv : 3;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 4;
        unsigned int reserved_4 : 4;
        unsigned int reserved_5 : 4;
        unsigned int reserved_6 : 4;
        unsigned int reserved_7 : 4;
    } reg;
} SOC_NPU_HWTS_HWTS_SWAPIN_CTRL0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_SWAPIN_CTRL0_acsq_max_gen_aic_START (0)
#define SOC_NPU_HWTS_HWTS_SWAPIN_CTRL0_acsq_max_gen_aic_END (2)
#define SOC_NPU_HWTS_HWTS_SWAPIN_CTRL0_acsq_max_eff_aic_START (4)
#define SOC_NPU_HWTS_HWTS_SWAPIN_CTRL0_acsq_max_eff_aic_END (6)
#define SOC_NPU_HWTS_HWTS_SWAPIN_CTRL0_acsq_max_aiv_START (8)
#define SOC_NPU_HWTS_HWTS_SWAPIN_CTRL0_acsq_max_aiv_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int virtualization_mode : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_HWTS_VIRTUALIZATION_GLB_CFG_UNION;
#endif
#define SOC_NPU_HWTS_VIRTUALIZATION_GLB_CFG_virtualization_mode_START (0)
#define SOC_NPU_HWTS_VIRTUALIZATION_GLB_CFG_virtualization_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vm_change_pending_set : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_HWTS_VIRTUAL_MACHINE_CTRL_UNION;
#endif
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_CTRL_vm_change_pending_set_START (0)
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_CTRL_vm_change_pending_set_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vm_change_pending_status : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_HWTS_VIRTUAL_MACHINE_STATUS_UNION;
#endif
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_STATUS_vm_change_pending_status_START (0)
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_STATUS_vm_change_pending_status_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vm_vmgid : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_HWTS_VIRTUAL_MACHINE_CFG_UNION;
#endif
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_CFG_vm_vmgid_START (0)
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_CFG_vm_vmgid_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vm_token_min_shadow_l : 32;
    } reg;
} SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_SHADOW_L_UNION;
#endif
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_SHADOW_L_vm_token_min_shadow_l_START (0)
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_SHADOW_L_vm_token_min_shadow_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vm_token_min_shadow_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_SHADOW_H_UNION;
#endif
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_SHADOW_H_vm_token_min_shadow_h_START (0)
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_SHADOW_H_vm_token_min_shadow_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vm_token_max_shadow_l : 32;
    } reg;
} SOC_NPU_HWTS_VIRTUAL_MACHINE_MAX_TOKEN_SHADOW_L_UNION;
#endif
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_MAX_TOKEN_SHADOW_L_vm_token_max_shadow_l_START (0)
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_MAX_TOKEN_SHADOW_L_vm_token_max_shadow_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vm_token_max_shadow_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_VIRTUAL_MACHINE_MAX_TOKEN_SHADOW_H_UNION;
#endif
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_MAX_TOKEN_SHADOW_H_vm_token_max_shadow_h_START (0)
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_MAX_TOKEN_SHADOW_H_vm_token_max_shadow_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vm_refill_token_shadow_l : 32;
    } reg;
} SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_REFILL_SHADOW_L_UNION;
#endif
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_REFILL_SHADOW_L_vm_refill_token_shadow_l_START (0)
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_REFILL_SHADOW_L_vm_refill_token_shadow_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vm_refill_token_shadow_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_REFILL_SHADOW_H_UNION;
#endif
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_REFILL_SHADOW_H_vm_refill_token_shadow_h_START (0)
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_REFILL_SHADOW_H_vm_refill_token_shadow_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vm_remain_token_l : 32;
    } reg;
} SOC_NPU_HWTS_VIRTUAL_MACHINE_REMAIN_TOKEN_L_UNION;
#endif
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_REMAIN_TOKEN_L_vm_remain_token_l_START (0)
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_REMAIN_TOKEN_L_vm_remain_token_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vm_remain_token_h : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_NPU_HWTS_VIRTUAL_MACHINE_REMAIN_TOKEN_H_UNION;
#endif
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_REMAIN_TOKEN_H_vm_remain_token_h_START (0)
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_REMAIN_TOKEN_H_vm_remain_token_h_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vm_threshold_l : 32;
    } reg;
} SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_L_UNION;
#endif
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_L_vm_threshold_l_START (0)
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_L_vm_threshold_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vm_threshold_h : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_H_UNION;
#endif
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_H_vm_threshold_h_START (0)
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_THRESHOLD_H_vm_threshold_h_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vm_token_max_l : 32;
    } reg;
} SOC_NPU_HWTS_VIRTUAL_MACHINE_TOKEN_MAX_L_UNION;
#endif
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_TOKEN_MAX_L_vm_token_max_l_START (0)
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_TOKEN_MAX_L_vm_token_max_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vm_token_max_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_VIRTUAL_MACHINE_TOKEN_MAX_H_UNION;
#endif
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_TOKEN_MAX_H_vm_token_max_h_START (0)
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_TOKEN_MAX_H_vm_token_max_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vm_token_min_l : 32;
    } reg;
} SOC_NPU_HWTS_VIRTUAL_MACHINE_TOKEN_MIN_L_UNION;
#endif
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_TOKEN_MIN_L_vm_token_min_l_START (0)
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_TOKEN_MIN_L_vm_token_min_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vm_token_min_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_VIRTUAL_MACHINE_TOKEN_MIN_H_UNION;
#endif
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_TOKEN_MIN_H_vm_token_min_h_START (0)
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_TOKEN_MIN_H_vm_token_min_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vm_refill_token_l : 32;
    } reg;
} SOC_NPU_HWTS_VIRTUAL_MACHINE_REFILL_TOKEN_L_UNION;
#endif
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_REFILL_TOKEN_L_vm_refill_token_l_START (0)
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_REFILL_TOKEN_L_vm_refill_token_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vm_refill_token_h : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_VIRTUAL_MACHINE_REFILL_TOKEN_H_UNION;
#endif
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_REFILL_TOKEN_H_vm_refill_token_h_START (0)
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_REFILL_TOKEN_H_vm_refill_token_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int statis_vm_token_min_l : 32;
    } reg;
} SOC_NPU_HWTS_VIRTUAL_MACHINE_STATIS_TOKEN_MIN_L_UNION;
#endif
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_STATIS_TOKEN_MIN_L_statis_vm_token_min_l_START (0)
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_STATIS_TOKEN_MIN_L_statis_vm_token_min_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int statis_vm_token_min_h : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_NPU_HWTS_VIRTUAL_MACHINE_STATIS_TOKEN_MIN_H_UNION;
#endif
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_STATIS_TOKEN_MIN_H_statis_vm_token_min_h_START (0)
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_STATIS_TOKEN_MIN_H_statis_vm_token_min_h_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int statis_vm_token_max_l : 32;
    } reg;
} SOC_NPU_HWTS_VIRTUAL_MACHINE_STATIS_TOKEN_MAX_L_UNION;
#endif
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_STATIS_TOKEN_MAX_L_statis_vm_token_max_l_START (0)
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_STATIS_TOKEN_MAX_L_statis_vm_token_max_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int statis_vm_token_max_h : 9;
        unsigned int reserved : 23;
    } reg;
} SOC_NPU_HWTS_VIRTUAL_MACHINE_STATIS_TOKEN_MAX_H_UNION;
#endif
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_STATIS_TOKEN_MAX_H_statis_vm_token_max_h_START (0)
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_STATIS_TOKEN_MAX_H_statis_vm_token_max_h_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vm_dfx_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_HWTS_VIRTUAL_MACHINE_DFX_CTRL0_UNION;
#endif
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_DFX_CTRL0_vm_dfx_clr_START (0)
#define SOC_NPU_HWTS_VIRTUAL_MACHINE_DFX_CTRL0_vm_dfx_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_VIRTUAL_MACHINE_DFX_CTRL1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int vm_dfx_retain_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_HWTS_VIRTUAL_DFX_GLB_CTRL_UNION;
#endif
#define SOC_NPU_HWTS_VIRTUAL_DFX_GLB_CTRL_vm_dfx_retain_bypass_START (0)
#define SOC_NPU_HWTS_VIRTUAL_DFX_GLB_CTRL_vm_dfx_retain_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int profile_buf_length : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPU_HWTS_HWTS_DFX_PROFILE_CTRL0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_CTRL0_profile_buf_length_START (0)
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_CTRL0_profile_buf_length_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int profile_af_threshold : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPU_HWTS_HWTS_DFX_PROFILE_CTRL1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_CTRL1_profile_af_threshold_START (0)
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_CTRL1_profile_af_threshold_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int profile_base_addr_l : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_DFX_PROFILE_BASE_ADDR0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_BASE_ADDR0_profile_base_addr_l_START (0)
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_BASE_ADDR0_profile_base_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int profile_base_addr_h : 16;
        unsigned int reserved : 15;
        unsigned int profile_base_addr_is_virtual : 1;
    } reg;
} SOC_NPU_HWTS_HWTS_DFX_PROFILE_BASE_ADDR1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_BASE_ADDR1_profile_base_addr_h_START (0)
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_BASE_ADDR1_profile_base_addr_h_END (15)
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_BASE_ADDR1_profile_base_addr_is_virtual_START (31)
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_BASE_ADDR1_profile_base_addr_is_virtual_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int profile_wptr_initial : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_HWTS_HWTS_DFX_PROFILE_WPTR_INITIAL_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_WPTR_INITIAL_profile_wptr_initial_START (0)
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_WPTR_INITIAL_profile_wptr_initial_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int profile_wptr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPU_HWTS_HWTS_DFX_PROFILE_WPTR_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_WPTR_profile_wptr_START (0)
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_WPTR_profile_wptr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int profile_rptr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPU_HWTS_HWTS_DFX_PROFILE_RPTR_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_RPTR_profile_rptr_START (0)
#define SOC_NPU_HWTS_HWTS_DFX_PROFILE_RPTR_profile_rptr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 16;
        unsigned int reserved_1: 16;
    } reg;
} SOC_NPU_HWTS_HWTS_DFX_PROFILE_SSID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 31;
    } reg;
} SOC_NPU_HWTS_HWTS_DFX_PROFILE_SSID_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int log_buf_length : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPU_HWTS_HWTS_DFX_LOG_CTRL0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_DFX_LOG_CTRL0_log_buf_length_START (0)
#define SOC_NPU_HWTS_HWTS_DFX_LOG_CTRL0_log_buf_length_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int log_af_threshold : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPU_HWTS_HWTS_DFX_LOG_CTRL1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_DFX_LOG_CTRL1_log_af_threshold_START (0)
#define SOC_NPU_HWTS_HWTS_DFX_LOG_CTRL1_log_af_threshold_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int log_base_addr_l : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_DFX_LOG_BASE_ADDR0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_DFX_LOG_BASE_ADDR0_log_base_addr_l_START (0)
#define SOC_NPU_HWTS_HWTS_DFX_LOG_BASE_ADDR0_log_base_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int log_base_addr_h : 16;
        unsigned int reserved : 15;
        unsigned int log_base_addr_is_virtual : 1;
    } reg;
} SOC_NPU_HWTS_HWTS_DFX_LOG_BASE_ADDR1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_DFX_LOG_BASE_ADDR1_log_base_addr_h_START (0)
#define SOC_NPU_HWTS_HWTS_DFX_LOG_BASE_ADDR1_log_base_addr_h_END (15)
#define SOC_NPU_HWTS_HWTS_DFX_LOG_BASE_ADDR1_log_base_addr_is_virtual_START (31)
#define SOC_NPU_HWTS_HWTS_DFX_LOG_BASE_ADDR1_log_base_addr_is_virtual_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int log_wptr_initial : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_HWTS_HWTS_DFX_LOG_WPTR_INITIAL_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_DFX_LOG_WPTR_INITIAL_log_wptr_initial_START (0)
#define SOC_NPU_HWTS_HWTS_DFX_LOG_WPTR_INITIAL_log_wptr_initial_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int log_wptr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPU_HWTS_HWTS_DFX_LOG_WPTR_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_DFX_LOG_WPTR_log_wptr_START (0)
#define SOC_NPU_HWTS_HWTS_DFX_LOG_WPTR_log_wptr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int log_rptr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPU_HWTS_HWTS_DFX_LOG_RPTR_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_DFX_LOG_RPTR_log_rptr_START (0)
#define SOC_NPU_HWTS_HWTS_DFX_LOG_RPTR_log_rptr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 16;
        unsigned int reserved_1: 16;
    } reg;
} SOC_NPU_HWTS_HWTS_DFX_LOG_SSID_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 31;
    } reg;
} SOC_NPU_HWTS_HWTS_DFX_LOG_SSID_EN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int entry_idle : 1;
        unsigned int task_vld : 1;
        unsigned int rtsq_assign : 1;
        unsigned int rtsq0_vld : 1;
        unsigned int rtsq1_vld : 1;
        unsigned int rtsq0_done : 1;
        unsigned int rtsq1_done : 1;
        unsigned int rtsq0_err : 1;
        unsigned int rtsq1_err : 1;
        unsigned int rtsq2_vld : 1;
        unsigned int rtsq2_done : 1;
        unsigned int rtsq2_err : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_entry_idle_START (0)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_entry_idle_END (0)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_task_vld_START (1)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_task_vld_END (1)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_rtsq_assign_START (2)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_rtsq_assign_END (2)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_rtsq0_vld_START (3)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_rtsq0_vld_END (3)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_rtsq1_vld_START (4)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_rtsq1_vld_END (4)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_rtsq0_done_START (5)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_rtsq0_done_END (5)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_rtsq1_done_START (6)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_rtsq1_done_END (6)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_rtsq0_err_START (7)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_rtsq0_err_END (7)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_rtsq1_err_START (8)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_rtsq1_err_END (8)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_rtsq2_vld_START (9)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_rtsq2_vld_END (9)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_rtsq2_done_START (10)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_rtsq2_done_END (10)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_rtsq2_err_START (11)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_CTRL0_rtsq2_err_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtsqid_0 : 7;
        unsigned int reserved_0: 1;
        unsigned int rtsqid_1 : 7;
        unsigned int reserved_1: 1;
        unsigned int rtsqid_2 : 7;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 8;
    } reg;
} SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO0_rtsqid_0_START (0)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO0_rtsqid_0_END (6)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO0_rtsqid_1_START (8)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO0_rtsqid_1_END (14)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO0_rtsqid_2_START (16)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO0_rtsqid_2_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ssid : 12;
        unsigned int ssidv : 1;
        unsigned int opcode : 3;
        unsigned int usrbit : 1;
        unsigned int err_mode : 1;
        unsigned int grpid : 3;
        unsigned int qos : 3;
        unsigned int reserved : 8;
    } reg;
} SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO1_ssid_START (0)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO1_ssid_END (11)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO1_ssidv_START (12)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO1_ssidv_END (12)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO1_opcode_START (13)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO1_opcode_END (15)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO1_usrbit_START (16)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO1_usrbit_END (16)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO1_err_mode_START (17)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO1_err_mode_END (17)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO1_grpid_START (18)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO1_grpid_END (20)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO1_qos_START (21)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO1_qos_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int funcptr_h : 7;
        unsigned int reserved : 9;
        unsigned int taskidx : 16;
    } reg;
} SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO2_funcptr_h_START (0)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO2_funcptr_h_END (6)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO2_taskidx_START (16)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO2_taskidx_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int funcptr_l : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO3_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO3_funcptr_l_START (0)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_INFO3_funcptr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtsq0_swapbuf_idx : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_NPU_HWTS_HWTS_FFRT_ACTIVE_ENTRY_INFO0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_FFRT_ACTIVE_ENTRY_INFO0_rtsq0_swapbuf_idx_START (0)
#define SOC_NPU_HWTS_HWTS_FFRT_ACTIVE_ENTRY_INFO0_rtsq0_swapbuf_idx_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtsq1_swapbuf_idx : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_NPU_HWTS_HWTS_FFRT_ACTIVE_ENTRY_INFO1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_FFRT_ACTIVE_ENTRY_INFO1_rtsq1_swapbuf_idx_START (0)
#define SOC_NPU_HWTS_HWTS_FFRT_ACTIVE_ENTRY_INFO1_rtsq1_swapbuf_idx_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtsq2_swapbuf_idx : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_NPU_HWTS_HWTS_FFRT_ACTIVE_ENTRY_INFO2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_FFRT_ACTIVE_ENTRY_INFO2_rtsq2_swapbuf_idx_START (0)
#define SOC_NPU_HWTS_HWTS_FFRT_ACTIVE_ENTRY_INFO2_rtsq2_swapbuf_idx_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts2ffrt_taskdone_valid : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_HWTS_HWTS_FFRT_ENTRY_DFX0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_DFX0_hwts2ffrt_taskdone_valid_START (0)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_DFX0_hwts2ffrt_taskdone_valid_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts2ffrt_taskdone_pld : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_FFRT_ENTRY_DFX1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_DFX1_hwts2ffrt_taskdone_pld_START (0)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_DFX1_hwts2ffrt_taskdone_pld_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ffrt2hwts_pushtask_cnt : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_FFRT_ENTRY_DFX2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_DFX2_ffrt2hwts_pushtask_cnt_START (0)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_DFX2_ffrt2hwts_pushtask_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hwts2ffrt_taskdone_cnt : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_FFRT_ENTRY_DFX3_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_DFX3_hwts2ffrt_taskdone_cnt_START (0)
#define SOC_NPU_HWTS_HWTS_FFRT_ENTRY_DFX3_hwts2ffrt_taskdone_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtsq_base_addr_l : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_RTSQ_BASE_ADDR0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_RTSQ_BASE_ADDR0_rtsq_base_addr_l_START (0)
#define SOC_NPU_HWTS_HWTS_RTSQ_BASE_ADDR0_rtsq_base_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtsq_base_addr_h : 16;
        unsigned int reserved : 15;
        unsigned int rtsq_base_addr_is_virtual : 1;
    } reg;
} SOC_NPU_HWTS_HWTS_RTSQ_BASE_ADDR1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_RTSQ_BASE_ADDR1_rtsq_base_addr_h_START (0)
#define SOC_NPU_HWTS_HWTS_RTSQ_BASE_ADDR1_rtsq_base_addr_h_END (15)
#define SOC_NPU_HWTS_HWTS_RTSQ_BASE_ADDR1_rtsq_base_addr_is_virtual_START (31)
#define SOC_NPU_HWTS_HWTS_RTSQ_BASE_ADDR1_rtsq_base_addr_is_virtual_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtsq_smmu_substream_id : 16;
        unsigned int rtsq_smmu_two_stage_stream_id : 16;
    } reg;
} SOC_NPU_HWTS_HWTS_RTSQ_CFG0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG0_rtsq_smmu_substream_id_START (0)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG0_rtsq_smmu_substream_id_END (15)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG0_rtsq_smmu_two_stage_stream_id_START (16)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG0_rtsq_smmu_two_stage_stream_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtsq_smmu_two_stage_en : 1;
        unsigned int rtsq_ban_wr_cqe : 1;
        unsigned int rtsq_sat_mode : 1;
        unsigned int rtsq_rsp_mode : 1;
        unsigned int rtsq_profile_block_en : 1;
        unsigned int rtsq_profile_task_en : 1;
        unsigned int rtsq_log_block_en : 1;
        unsigned int rtsq_log_task_en : 1;
        unsigned int rtsq_profile_bufid : 2;
        unsigned int reserved_0 : 2;
        unsigned int rtsq_log_bufid : 2;
        unsigned int reserved_1 : 2;
        unsigned int rtsq_rtcqid : 7;
        unsigned int reserved_2 : 9;
    } reg;
} SOC_NPU_HWTS_HWTS_RTSQ_CFG1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG1_rtsq_smmu_two_stage_en_START (0)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG1_rtsq_smmu_two_stage_en_END (0)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG1_rtsq_ban_wr_cqe_START (1)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG1_rtsq_ban_wr_cqe_END (1)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG1_rtsq_sat_mode_START (2)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG1_rtsq_sat_mode_END (2)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG1_rtsq_rsp_mode_START (3)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG1_rtsq_rsp_mode_END (3)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG1_rtsq_profile_block_en_START (4)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG1_rtsq_profile_block_en_END (4)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG1_rtsq_profile_task_en_START (5)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG1_rtsq_profile_task_en_END (5)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG1_rtsq_log_block_en_START (6)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG1_rtsq_log_block_en_END (6)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG1_rtsq_log_task_en_START (7)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG1_rtsq_log_task_en_END (7)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG1_rtsq_profile_bufid_START (8)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG1_rtsq_profile_bufid_END (9)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG1_rtsq_log_bufid_START (12)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG1_rtsq_log_bufid_END (13)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG1_rtsq_rtcqid_START (16)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG1_rtsq_rtcqid_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtsq_gen_aic_poolid : 1;
        unsigned int reserved_0 : 3;
        unsigned int rtsq_aiv_poolid : 1;
        unsigned int reserved_1 : 3;
        unsigned int rtsq_eff_aic_poolid : 1;
        unsigned int reserved_2 : 3;
        unsigned int reserved_3 : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_RTSQ_CFG2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG2_rtsq_gen_aic_poolid_START (0)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG2_rtsq_gen_aic_poolid_END (0)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG2_rtsq_aiv_poolid_START (4)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG2_rtsq_aiv_poolid_END (4)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG2_rtsq_eff_aic_poolid_START (8)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG2_rtsq_eff_aic_poolid_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_RTSQ_CFG3_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtsq_length : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_HWTS_HWTS_RTSQ_CFG4_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG4_rtsq_length_START (0)
#define SOC_NPU_HWTS_HWTS_RTSQ_CFG4_rtsq_length_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtcq_base_addr_l : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_RTCQ_BASE_ADDR0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_RTCQ_BASE_ADDR0_rtcq_base_addr_l_START (0)
#define SOC_NPU_HWTS_HWTS_RTCQ_BASE_ADDR0_rtcq_base_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtcq_base_addr_h : 16;
        unsigned int reserved : 15;
        unsigned int rtcq_base_addr_is_virtual : 1;
    } reg;
} SOC_NPU_HWTS_HWTS_RTCQ_BASE_ADDR1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_RTCQ_BASE_ADDR1_rtcq_base_addr_h_START (0)
#define SOC_NPU_HWTS_HWTS_RTCQ_BASE_ADDR1_rtcq_base_addr_h_END (15)
#define SOC_NPU_HWTS_HWTS_RTCQ_BASE_ADDR1_rtcq_base_addr_is_virtual_START (31)
#define SOC_NPU_HWTS_HWTS_RTCQ_BASE_ADDR1_rtcq_base_addr_is_virtual_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtcq_length : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_HWTS_HWTS_RTCQ_CFG0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_RTCQ_CFG0_rtcq_length_START (0)
#define SOC_NPU_HWTS_HWTS_RTCQ_CFG0_rtcq_length_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtsq_context_switch_buf_base_addr_l : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_RTSQ_CONTEXT_SWITCH_BUF_CTRL0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_RTSQ_CONTEXT_SWITCH_BUF_CTRL0_rtsq_context_switch_buf_base_addr_l_START (0)
#define SOC_NPU_HWTS_HWTS_RTSQ_CONTEXT_SWITCH_BUF_CTRL0_rtsq_context_switch_buf_base_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtsq_context_switch_buf_base_addr_h : 16;
        unsigned int rtsq_context_switch_buf_shift : 6;
        unsigned int reserved : 10;
    } reg;
} SOC_NPU_HWTS_HWTS_RTSQ_CONTEXT_SWITCH_BUF_CTRL1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_RTSQ_CONTEXT_SWITCH_BUF_CTRL1_rtsq_context_switch_buf_base_addr_h_START (0)
#define SOC_NPU_HWTS_HWTS_RTSQ_CONTEXT_SWITCH_BUF_CTRL1_rtsq_context_switch_buf_base_addr_h_END (15)
#define SOC_NPU_HWTS_HWTS_RTSQ_CONTEXT_SWITCH_BUF_CTRL1_rtsq_context_switch_buf_shift_START (16)
#define SOC_NPU_HWTS_HWTS_RTSQ_CONTEXT_SWITCH_BUF_CTRL1_rtsq_context_switch_buf_shift_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtsq_sw_status : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_RTSQ_SW_STATUS_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_RTSQ_SW_STATUS_rtsq_sw_status_START (0)
#define SOC_NPU_HWTS_HWTS_RTSQ_SW_STATUS_rtsq_sw_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_own_bitmap : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_ACSQ_FSM_IP_OWN_STATE_UNION;
#endif
#define SOC_NPU_HWTS_ACSQ_FSM_IP_OWN_STATE_ip_own_bitmap_START (0)
#define SOC_NPU_HWTS_ACSQ_FSM_IP_OWN_STATE_ip_own_bitmap_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_debug_bitmap : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_ACSQ_FSM_IP_DEBUG_STATE_UNION;
#endif
#define SOC_NPU_HWTS_ACSQ_FSM_IP_DEBUG_STATE_ip_debug_bitmap_START (0)
#define SOC_NPU_HWTS_ACSQ_FSM_IP_DEBUG_STATE_ip_debug_bitmap_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_exception_bitmap : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_ACSQ_FSM_IP_EXCEPTION_STATE_UNION;
#endif
#define SOC_NPU_HWTS_ACSQ_FSM_IP_EXCEPTION_STATE_ip_exception_bitmap_START (0)
#define SOC_NPU_HWTS_ACSQ_FSM_IP_EXCEPTION_STATE_ip_exception_bitmap_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_trap_bitmap : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_ACSQ_FSM_IP_TRAP_STATE_UNION;
#endif
#define SOC_NPU_HWTS_ACSQ_FSM_IP_TRAP_STATE_ip_trap_bitmap_START (0)
#define SOC_NPU_HWTS_ACSQ_FSM_IP_TRAP_STATE_ip_trap_bitmap_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_done_bitmap : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_ACSQ_FSM_IP_DONE_STATE_UNION;
#endif
#define SOC_NPU_HWTS_ACSQ_FSM_IP_DONE_STATE_ip_done_bitmap_START (0)
#define SOC_NPU_HWTS_ACSQ_FSM_IP_DONE_STATE_ip_done_bitmap_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sqe_type : 6;
        unsigned int reserved : 10;
        unsigned int block_id : 16;
    } reg;
} SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL0_UNION;
#endif
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL0_sqe_type_START (0)
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL0_sqe_type_END (5)
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL0_block_id_START (16)
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL0_block_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int block_dim : 16;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 6;
        unsigned int kernel_credit : 8;
    } reg;
} SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL1_UNION;
#endif
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL1_block_dim_START (0)
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL1_block_dim_END (15)
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL1_kernel_credit_START (24)
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL1_kernel_credit_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int acsq_fsm_state : 5;
        unsigned int reserved_0 : 3;
        unsigned int acsq_fsm_task_log_ost_cnt : 2;
        unsigned int acsq_fsm_profile_ost_cnt : 1;
        unsigned int acsq_fsm_write_value_ost_cnt : 1;
        unsigned int acsq_fsm_cq_write_ost_cnt : 1;
        unsigned int reserved_1 : 19;
    } reg;
} SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL2_UNION;
#endif
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL2_acsq_fsm_state_START (0)
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL2_acsq_fsm_state_END (4)
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL2_acsq_fsm_task_log_ost_cnt_START (8)
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL2_acsq_fsm_task_log_ost_cnt_END (9)
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL2_acsq_fsm_profile_ost_cnt_START (10)
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL2_acsq_fsm_profile_ost_cnt_END (10)
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL2_acsq_fsm_write_value_ost_cnt_START (11)
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL2_acsq_fsm_write_value_ost_cnt_END (11)
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL2_acsq_fsm_cq_write_ost_cnt_START (12)
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL2_acsq_fsm_cq_write_ost_cnt_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int acsq_prefetch_busy : 1;
        unsigned int reserved_1 : 30;
    } reg;
} SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL3_UNION;
#endif
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL3_acsq_prefetch_busy_START (1)
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL3_acsq_prefetch_busy_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int acsq_task_kill : 1;
        unsigned int acsq_debug_pause : 1;
        unsigned int acsq_debug_resume : 1;
        unsigned int acsq_terminate : 1;
        unsigned int acsq_task_resume : 1;
        unsigned int acsq_prefetch_clear : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL4_UNION;
#endif
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL4_acsq_task_kill_START (0)
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL4_acsq_task_kill_END (0)
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL4_acsq_debug_pause_START (1)
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL4_acsq_debug_pause_END (1)
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL4_acsq_debug_resume_START (2)
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL4_acsq_debug_resume_END (2)
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL4_acsq_terminate_START (3)
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL4_acsq_terminate_END (3)
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL4_acsq_task_resume_START (4)
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL4_acsq_task_resume_END (4)
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL4_acsq_prefetch_clear_START (5)
#define SOC_NPU_HWTS_ACSQ_FSM_DFX_CTRL4_acsq_prefetch_clear_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int acsq_to_rtsqid_map : 7;
        unsigned int reserved : 25;
    } reg;
} SOC_NPU_HWTS_ACSQ_TO_RTSQ_MAP0_UNION;
#endif
#define SOC_NPU_HWTS_ACSQ_TO_RTSQ_MAP0_acsq_to_rtsqid_map_START (0)
#define SOC_NPU_HWTS_ACSQ_TO_RTSQ_MAP0_acsq_to_rtsqid_map_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int acsq_to_rtsqid_map_vld : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_HWTS_ACSQ_TO_RTSQ_MAP1_UNION;
#endif
#define SOC_NPU_HWTS_ACSQ_TO_RTSQ_MAP1_acsq_to_rtsqid_map_vld_START (0)
#define SOC_NPU_HWTS_ACSQ_TO_RTSQ_MAP1_acsq_to_rtsqid_map_vld_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_table_cnt : 8;
        unsigned int event_table_overflow : 1;
        unsigned int reserved_0 : 10;
        unsigned int event_table_oveflow_clear : 1;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_NPU_HWTS_HWTS_HTS_EVENT_TABLE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_HTS_EVENT_TABLE_event_table_cnt_START (0)
#define SOC_NPU_HWTS_HWTS_HTS_EVENT_TABLE_event_table_cnt_END (7)
#define SOC_NPU_HWTS_HWTS_HTS_EVENT_TABLE_event_table_overflow_START (8)
#define SOC_NPU_HWTS_HWTS_HTS_EVENT_TABLE_event_table_overflow_END (8)
#define SOC_NPU_HWTS_HWTS_HTS_EVENT_TABLE_event_table_oveflow_clear_START (19)
#define SOC_NPU_HWTS_HWTS_HTS_EVENT_TABLE_event_table_oveflow_clear_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hts_error_type : 2;
        unsigned int hts_error_notifyid : 10;
        unsigned int hts_error_dfx_clr : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_NPU_HWTS_HWTS_HTS_ERROR_DFX_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_HTS_ERROR_DFX_hts_error_type_START (0)
#define SOC_NPU_HWTS_HWTS_HTS_ERROR_DFX_hts_error_type_END (1)
#define SOC_NPU_HWTS_HWTS_HTS_ERROR_DFX_hts_error_notifyid_START (2)
#define SOC_NPU_HWTS_HWTS_HTS_ERROR_DFX_hts_error_notifyid_END (11)
#define SOC_NPU_HWTS_HWTS_HTS_ERROR_DFX_hts_error_dfx_clr_START (12)
#define SOC_NPU_HWTS_HWTS_HTS_ERROR_DFX_hts_error_dfx_clr_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int p0_rtsq_host_id : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG0_p0_rtsq_host_id_START (0)
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG0_p0_rtsq_host_id_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int p0_rtsq_tail : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG1_p0_rtsq_tail_START (0)
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG1_p0_rtsq_tail_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int p0_rtsq_head : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG2_p0_rtsq_head_START (0)
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG2_p0_rtsq_head_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int p0_rtsq_en : 1;
        unsigned int reserved_0 : 7;
        unsigned int p0_rtsq_vmid : 2;
        unsigned int p0_rtsq_pmu_id : 1;
        unsigned int reserved_1 : 17;
        unsigned int p0_rtsq_priority : 3;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG3_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG3_p0_rtsq_en_START (0)
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG3_p0_rtsq_en_END (0)
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG3_p0_rtsq_vmid_START (8)
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG3_p0_rtsq_vmid_END (9)
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG3_p0_rtsq_pmu_id_START (10)
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG3_p0_rtsq_pmu_id_END (10)
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG3_p0_rtsq_priority_START (28)
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG3_p0_rtsq_priority_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int p0_rtsq_loop_en : 1;
        unsigned int p0_rtsq_ffrt : 1;
        unsigned int reserved_0 : 6;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG4_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG4_p0_rtsq_loop_en_START (0)
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG4_p0_rtsq_loop_en_END (0)
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG4_p0_rtsq_ffrt_START (1)
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_CFG4_p0_rtsq_ffrt_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int p0_debug_pause : 1;
        unsigned int p0_task_kill : 1;
        unsigned int reserved_0 : 6;
        unsigned int p0_prefetch_clear : 1;
        unsigned int reserved_1 : 7;
        unsigned int p0_debug_resume : 1;
        unsigned int p0_task_resume : 1;
        unsigned int p0_task_terminate : 1;
        unsigned int p0_ffrt_swapout : 1;
        unsigned int reserved_2 : 12;
    } reg;
} SOC_NPU_HWTS_HWTS_P0_TASK_CTRL_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_P0_TASK_CTRL_p0_debug_pause_START (0)
#define SOC_NPU_HWTS_HWTS_P0_TASK_CTRL_p0_debug_pause_END (0)
#define SOC_NPU_HWTS_HWTS_P0_TASK_CTRL_p0_task_kill_START (1)
#define SOC_NPU_HWTS_HWTS_P0_TASK_CTRL_p0_task_kill_END (1)
#define SOC_NPU_HWTS_HWTS_P0_TASK_CTRL_p0_prefetch_clear_START (8)
#define SOC_NPU_HWTS_HWTS_P0_TASK_CTRL_p0_prefetch_clear_END (8)
#define SOC_NPU_HWTS_HWTS_P0_TASK_CTRL_p0_debug_resume_START (16)
#define SOC_NPU_HWTS_HWTS_P0_TASK_CTRL_p0_debug_resume_END (16)
#define SOC_NPU_HWTS_HWTS_P0_TASK_CTRL_p0_task_resume_START (17)
#define SOC_NPU_HWTS_HWTS_P0_TASK_CTRL_p0_task_resume_END (17)
#define SOC_NPU_HWTS_HWTS_P0_TASK_CTRL_p0_task_terminate_START (18)
#define SOC_NPU_HWTS_HWTS_P0_TASK_CTRL_p0_task_terminate_END (18)
#define SOC_NPU_HWTS_HWTS_P0_TASK_CTRL_p0_ffrt_swapout_START (19)
#define SOC_NPU_HWTS_HWTS_P0_TASK_CTRL_p0_ffrt_swapout_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int p0_rtsq_cond0 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_P0_RTSQ_COND0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_COND0_p0_rtsq_cond0_START (0)
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_COND0_p0_rtsq_cond0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int p0_rtsq_cond1 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_P0_RTSQ_COND1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_COND1_p0_rtsq_cond1_START (0)
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_COND1_p0_rtsq_cond1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int p0_rtsq_to_acsqid_map : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_NPU_HWTS_HWTS_P0_RTSQ_TO_ACSQ_MAP0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_TO_ACSQ_MAP0_p0_rtsq_to_acsqid_map_START (0)
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_TO_ACSQ_MAP0_p0_rtsq_to_acsqid_map_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int p0_rtsq_to_acsqid_map_vld : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_HWTS_HWTS_P0_RTSQ_TO_ACSQ_MAP1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_TO_ACSQ_MAP1_p0_rtsq_to_acsqid_map_vld_START (0)
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_TO_ACSQ_MAP1_p0_rtsq_to_acsqid_map_vld_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int p0_rtsq_fsm_state : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_NPU_HWTS_HWTS_P0_RTSQ_DFX0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_DFX0_p0_rtsq_fsm_state_START (0)
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_DFX0_p0_rtsq_fsm_state_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int p0_rtsq_entry_sq_idx : 2;
        unsigned int p0_rtsq_active_entryid : 3;
        unsigned int p0_rtsq_normal_entryid : 6;
        unsigned int reserved : 21;
    } reg;
} SOC_NPU_HWTS_HWTS_P0_RTSQ_DFX1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_DFX1_p0_rtsq_entry_sq_idx_START (0)
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_DFX1_p0_rtsq_entry_sq_idx_END (1)
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_DFX1_p0_rtsq_active_entryid_START (2)
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_DFX1_p0_rtsq_active_entryid_END (4)
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_DFX1_p0_rtsq_normal_entryid_START (5)
#define SOC_NPU_HWTS_HWTS_P0_RTSQ_DFX1_p0_rtsq_normal_entryid_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int p0_rtcq_head : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_HWTS_HWTS_P0_RTCQ_CFG0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_P0_RTCQ_CFG0_p0_rtcq_head_START (0)
#define SOC_NPU_HWTS_HWTS_P0_RTCQ_CFG0_p0_rtcq_head_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int p0_rtcq_tail : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_NPU_HWTS_HWTS_P0_RTCQ_CFG1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_P0_RTCQ_CFG1_p0_rtcq_tail_START (0)
#define SOC_NPU_HWTS_HWTS_P0_RTCQ_CFG1_p0_rtcq_tail_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int p0_rtcq_phase_bit : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 30;
    } reg;
} SOC_NPU_HWTS_HWTS_P0_RTCQ_CFG2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_P0_RTCQ_CFG2_p0_rtcq_phase_bit_START (0)
#define SOC_NPU_HWTS_HWTS_P0_RTCQ_CFG2_p0_rtcq_phase_bit_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_sqe_done_s_status : 1;
        unsigned int l1_pre_paused_s_status : 1;
        unsigned int l1_post_paused_s_status : 1;
        unsigned int l1_cq_full_s_status : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int l1_sq_done_s_status : 1;
        unsigned int l1_cqe_written_s_status : 1;
        unsigned int reserved_4 : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_l1_sqe_done_s_status_START (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_l1_sqe_done_s_status_END (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_l1_pre_paused_s_status_START (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_l1_pre_paused_s_status_END (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_l1_post_paused_s_status_START (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_l1_post_paused_s_status_END (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_l1_cq_full_s_status_START (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_l1_cq_full_s_status_END (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_l1_sq_done_s_status_START (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_l1_sq_done_s_status_END (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_l1_cqe_written_s_status_START (9)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_l1_cqe_written_s_status_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_debug_s_status : 1;
        unsigned int l1_debug_paused_s_status : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DEBUG_S_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_INTERRUPT_l1_task_debug_s_status_START (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_INTERRUPT_l1_task_debug_s_status_END (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_INTERRUPT_l1_debug_paused_s_status_START (1)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_INTERRUPT_l1_debug_paused_s_status_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_error_s_status : 1;
        unsigned int l1_task_timeout_s_status : 1;
        unsigned int l1_task_trap_s_status : 1;
        unsigned int l1_sqe_error_s_status : 1;
        unsigned int l1_sw_status_error_s_status : 1;
        unsigned int l1_bus_error_s_status : 1;
        unsigned int l1_ecc_error_s_status : 1;
        unsigned int l1_pool_conflict_s_status : 1;
        unsigned int l1_hts_error_s_status : 1;
        unsigned int l1_pu_pd_timeout_s_status : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_l1_task_error_s_status_START (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_l1_task_error_s_status_END (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_l1_task_timeout_s_status_START (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_l1_task_timeout_s_status_END (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_l1_task_trap_s_status_START (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_l1_task_trap_s_status_END (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_l1_sqe_error_s_status_START (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_l1_sqe_error_s_status_END (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_l1_sw_status_error_s_status_START (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_l1_sw_status_error_s_status_END (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_l1_bus_error_s_status_START (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_l1_bus_error_s_status_END (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_l1_ecc_error_s_status_START (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_l1_ecc_error_s_status_END (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_l1_pool_conflict_s_status_START (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_l1_pool_conflict_s_status_END (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_l1_hts_error_s_status_START (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_l1_hts_error_s_status_END (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_l1_pu_pd_timeout_s_status_START (9)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_l1_pu_pd_timeout_s_status_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 5;
        unsigned int l1_bus_error_s_force : 1;
        unsigned int l1_ecc_error_s_force : 1;
        unsigned int l1_pool_conflict_s_force : 1;
        unsigned int l1_hts_error_s_force : 1;
        unsigned int l1_pu_pd_timeout_s_force : 1;
        unsigned int reserved_1 : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_FORCE_l1_bus_error_s_force_START (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_FORCE_l1_bus_error_s_force_END (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_FORCE_l1_ecc_error_s_force_START (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_FORCE_l1_ecc_error_s_force_END (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_FORCE_l1_pool_conflict_s_force_START (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_FORCE_l1_pool_conflict_s_force_END (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_FORCE_l1_hts_error_s_force_START (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_FORCE_l1_hts_error_s_force_END (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_FORCE_l1_pu_pd_timeout_s_force_START (9)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_FORCE_l1_pu_pd_timeout_s_force_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_sqe_done_s_mask0 : 1;
        unsigned int l1_pre_paused_s_mask0 : 1;
        unsigned int l1_post_paused_s_mask0 : 1;
        unsigned int l1_cq_full_s_mask0 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int l1_sq_done_s_mask0 : 1;
        unsigned int l1_cqe_written_s_mask0 : 1;
        unsigned int reserved_4 : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_l1_sqe_done_s_mask0_START (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_l1_sqe_done_s_mask0_END (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_l1_pre_paused_s_mask0_START (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_l1_pre_paused_s_mask0_END (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_l1_post_paused_s_mask0_START (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_l1_post_paused_s_mask0_END (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_l1_cq_full_s_mask0_START (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_l1_cq_full_s_mask0_END (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_l1_sq_done_s_mask0_START (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_l1_sq_done_s_mask0_END (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_l1_cqe_written_s_mask0_START (9)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_l1_cqe_written_s_mask0_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_debug_s_mask0 : 1;
        unsigned int l1_debug_paused_s_mask0 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK0_l1_task_debug_s_mask0_START (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK0_l1_task_debug_s_mask0_END (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK0_l1_debug_paused_s_mask0_START (1)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK0_l1_debug_paused_s_mask0_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_error_s_mask0 : 1;
        unsigned int l1_task_timeout_s_mask0 : 1;
        unsigned int l1_task_trap_s_mask0 : 1;
        unsigned int l1_sqe_error_s_mask0 : 1;
        unsigned int l1_sw_status_error_s_mask0 : 1;
        unsigned int l1_bus_error_s_mask0 : 1;
        unsigned int l1_ecc_error_s_mask0 : 1;
        unsigned int l1_pool_conflict_s_mask0 : 1;
        unsigned int l1_hts_error_s_mask0 : 1;
        unsigned int l1_pu_pd_timeout_s_mask0 : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_l1_task_error_s_mask0_START (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_l1_task_error_s_mask0_END (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_l1_task_timeout_s_mask0_START (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_l1_task_timeout_s_mask0_END (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_l1_task_trap_s_mask0_START (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_l1_task_trap_s_mask0_END (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_l1_sqe_error_s_mask0_START (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_l1_sqe_error_s_mask0_END (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_l1_sw_status_error_s_mask0_START (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_l1_sw_status_error_s_mask0_END (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_l1_bus_error_s_mask0_START (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_l1_bus_error_s_mask0_END (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_l1_ecc_error_s_mask0_START (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_l1_ecc_error_s_mask0_END (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_l1_pool_conflict_s_mask0_START (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_l1_pool_conflict_s_mask0_END (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_l1_hts_error_s_mask0_START (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_l1_hts_error_s_mask0_END (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_l1_pu_pd_timeout_s_mask0_START (9)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_l1_pu_pd_timeout_s_mask0_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 30;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_sqe_done_s_mask2 : 1;
        unsigned int l1_pre_paused_s_mask2 : 1;
        unsigned int l1_post_paused_s_mask2 : 1;
        unsigned int l1_cq_full_s_mask2 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int l1_sq_done_s_mask2 : 1;
        unsigned int l1_cqe_written_s_mask2 : 1;
        unsigned int reserved_4 : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_l1_sqe_done_s_mask2_START (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_l1_sqe_done_s_mask2_END (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_l1_pre_paused_s_mask2_START (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_l1_pre_paused_s_mask2_END (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_l1_post_paused_s_mask2_START (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_l1_post_paused_s_mask2_END (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_l1_cq_full_s_mask2_START (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_l1_cq_full_s_mask2_END (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_l1_sq_done_s_mask2_START (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_l1_sq_done_s_mask2_END (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_l1_cqe_written_s_mask2_START (9)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_l1_cqe_written_s_mask2_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_debug_s_mask2 : 1;
        unsigned int l1_debug_paused_s_mask2 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK2_l1_task_debug_s_mask2_START (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK2_l1_task_debug_s_mask2_END (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK2_l1_debug_paused_s_mask2_START (1)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK2_l1_debug_paused_s_mask2_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_error_s_mask2 : 1;
        unsigned int l1_task_timeout_s_mask2 : 1;
        unsigned int l1_task_trap_s_mask2 : 1;
        unsigned int l1_sqe_error_s_mask2 : 1;
        unsigned int l1_sw_status_error_s_mask2 : 1;
        unsigned int l1_bus_error_s_mask2 : 1;
        unsigned int l1_ecc_error_s_mask2 : 1;
        unsigned int l1_pool_conflict_s_mask2 : 1;
        unsigned int l1_hts_error_s_mask2 : 1;
        unsigned int l1_pu_pd_timeout_s_mask2 : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_l1_task_error_s_mask2_START (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_l1_task_error_s_mask2_END (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_l1_task_timeout_s_mask2_START (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_l1_task_timeout_s_mask2_END (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_l1_task_trap_s_mask2_START (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_l1_task_trap_s_mask2_END (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_l1_sqe_error_s_mask2_START (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_l1_sqe_error_s_mask2_END (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_l1_sw_status_error_s_mask2_START (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_l1_sw_status_error_s_mask2_END (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_l1_bus_error_s_mask2_START (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_l1_bus_error_s_mask2_END (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_l1_ecc_error_s_mask2_START (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_l1_ecc_error_s_mask2_END (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_l1_pool_conflict_s_mask2_START (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_l1_pool_conflict_s_mask2_END (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_l1_hts_error_s_mask2_START (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_l1_hts_error_s_mask2_END (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_l1_pu_pd_timeout_s_mask2_START (9)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_l1_pu_pd_timeout_s_mask2_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_sqe_done_s_mask0_set : 1;
        unsigned int l1_pre_paused_s_mask0_set : 1;
        unsigned int l1_post_paused_s_mask0_set : 1;
        unsigned int l1_cq_full_s_mask0_set : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int l1_sq_done_s_mask0_set : 1;
        unsigned int l1_cqe_written_s_mask0_set : 1;
        unsigned int reserved_4 : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_SET_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_SET_l1_sqe_done_s_mask0_set_START (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_SET_l1_sqe_done_s_mask0_set_END (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_SET_l1_pre_paused_s_mask0_set_START (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_SET_l1_pre_paused_s_mask0_set_END (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_SET_l1_post_paused_s_mask0_set_START (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_SET_l1_post_paused_s_mask0_set_END (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_SET_l1_cq_full_s_mask0_set_START (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_SET_l1_cq_full_s_mask0_set_END (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_SET_l1_sq_done_s_mask0_set_START (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_SET_l1_sq_done_s_mask0_set_END (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_SET_l1_cqe_written_s_mask0_set_START (9)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_SET_l1_cqe_written_s_mask0_set_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_debug_s_mask0_set : 1;
        unsigned int l1_debug_paused_s_mask0_set : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK0_SET_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK0_SET_l1_task_debug_s_mask0_set_START (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK0_SET_l1_task_debug_s_mask0_set_END (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK0_SET_l1_debug_paused_s_mask0_set_START (1)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK0_SET_l1_debug_paused_s_mask0_set_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_error_s_mask0_set : 1;
        unsigned int l1_task_timeout_s_mask0_set : 1;
        unsigned int l1_task_trap_s_mask0_set : 1;
        unsigned int l1_sqe_error_s_mask0_set : 1;
        unsigned int l1_sw_status_error_s_mask0_set : 1;
        unsigned int l1_bus_error_s_mask0_set : 1;
        unsigned int l1_ecc_error_s_mask0_set : 1;
        unsigned int l1_pool_conflict_s_mask0_set : 1;
        unsigned int l1_hts_error_s_mask0_set : 1;
        unsigned int l1_pu_pd_timeout_s_mask0_set : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_SET_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_SET_l1_task_error_s_mask0_set_START (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_SET_l1_task_error_s_mask0_set_END (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_SET_l1_task_timeout_s_mask0_set_START (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_SET_l1_task_timeout_s_mask0_set_END (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_SET_l1_task_trap_s_mask0_set_START (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_SET_l1_task_trap_s_mask0_set_END (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_SET_l1_sqe_error_s_mask0_set_START (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_SET_l1_sqe_error_s_mask0_set_END (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_SET_l1_sw_status_error_s_mask0_set_START (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_SET_l1_sw_status_error_s_mask0_set_END (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_SET_l1_bus_error_s_mask0_set_START (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_SET_l1_bus_error_s_mask0_set_END (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_SET_l1_ecc_error_s_mask0_set_START (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_SET_l1_ecc_error_s_mask0_set_END (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_SET_l1_pool_conflict_s_mask0_set_START (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_SET_l1_pool_conflict_s_mask0_set_END (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_SET_l1_hts_error_s_mask0_set_START (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_SET_l1_hts_error_s_mask0_set_END (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_SET_l1_pu_pd_timeout_s_mask0_set_START (9)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_SET_l1_pu_pd_timeout_s_mask0_set_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 30;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_sqe_done_s_mask2_set : 1;
        unsigned int l1_pre_paused_s_mask2_set : 1;
        unsigned int l1_post_paused_s_mask2_set : 1;
        unsigned int l1_cq_full_s_mask2_set : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int l1_sq_done_s_mask2_set : 1;
        unsigned int l1_cqe_written_s_mask2_set : 1;
        unsigned int reserved_4 : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_SET_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_SET_l1_sqe_done_s_mask2_set_START (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_SET_l1_sqe_done_s_mask2_set_END (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_SET_l1_pre_paused_s_mask2_set_START (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_SET_l1_pre_paused_s_mask2_set_END (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_SET_l1_post_paused_s_mask2_set_START (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_SET_l1_post_paused_s_mask2_set_END (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_SET_l1_cq_full_s_mask2_set_START (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_SET_l1_cq_full_s_mask2_set_END (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_SET_l1_sq_done_s_mask2_set_START (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_SET_l1_sq_done_s_mask2_set_END (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_SET_l1_cqe_written_s_mask2_set_START (9)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_SET_l1_cqe_written_s_mask2_set_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_debug_s_mask2_set : 1;
        unsigned int l1_debug_paused_s_mask2_set : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK2_SET_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK2_SET_l1_task_debug_s_mask2_set_START (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK2_SET_l1_task_debug_s_mask2_set_END (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK2_SET_l1_debug_paused_s_mask2_set_START (1)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK2_SET_l1_debug_paused_s_mask2_set_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_error_s_mask2_set : 1;
        unsigned int l1_task_timeout_s_mask2_set : 1;
        unsigned int l1_task_trap_s_mask2_set : 1;
        unsigned int l1_sqe_error_s_mask2_set : 1;
        unsigned int l1_sw_status_error_s_mask2_set : 1;
        unsigned int l1_bus_error_s_mask2_set : 1;
        unsigned int l1_ecc_error_s_mask2_set : 1;
        unsigned int l1_pool_conflict_s_mask2_set : 1;
        unsigned int l1_hts_error_s_mask2_set : 1;
        unsigned int l1_pu_pd_timeout_s_mask2_set : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_SET_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_SET_l1_task_error_s_mask2_set_START (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_SET_l1_task_error_s_mask2_set_END (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_SET_l1_task_timeout_s_mask2_set_START (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_SET_l1_task_timeout_s_mask2_set_END (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_SET_l1_task_trap_s_mask2_set_START (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_SET_l1_task_trap_s_mask2_set_END (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_SET_l1_sqe_error_s_mask2_set_START (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_SET_l1_sqe_error_s_mask2_set_END (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_SET_l1_sw_status_error_s_mask2_set_START (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_SET_l1_sw_status_error_s_mask2_set_END (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_SET_l1_bus_error_s_mask2_set_START (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_SET_l1_bus_error_s_mask2_set_END (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_SET_l1_ecc_error_s_mask2_set_START (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_SET_l1_ecc_error_s_mask2_set_END (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_SET_l1_pool_conflict_s_mask2_set_START (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_SET_l1_pool_conflict_s_mask2_set_END (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_SET_l1_hts_error_s_mask2_set_START (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_SET_l1_hts_error_s_mask2_set_END (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_SET_l1_pu_pd_timeout_s_mask2_set_START (9)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_SET_l1_pu_pd_timeout_s_mask2_set_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_sqe_done_s_mask0_clr : 1;
        unsigned int l1_pre_paused_s_mask0_clr : 1;
        unsigned int l1_post_paused_s_mask0_clr : 1;
        unsigned int l1_cq_full_s_mask0_clr : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int l1_sq_done_s_mask0_clr : 1;
        unsigned int l1_cqe_written_s_mask0_clr : 1;
        unsigned int reserved_4 : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_CLR_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_CLR_l1_sqe_done_s_mask0_clr_START (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_CLR_l1_sqe_done_s_mask0_clr_END (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_CLR_l1_pre_paused_s_mask0_clr_START (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_CLR_l1_pre_paused_s_mask0_clr_END (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_CLR_l1_post_paused_s_mask0_clr_START (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_CLR_l1_post_paused_s_mask0_clr_END (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_CLR_l1_cq_full_s_mask0_clr_START (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_CLR_l1_cq_full_s_mask0_clr_END (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_CLR_l1_sq_done_s_mask0_clr_START (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_CLR_l1_sq_done_s_mask0_clr_END (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_CLR_l1_cqe_written_s_mask0_clr_START (9)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK0_CLR_l1_cqe_written_s_mask0_clr_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_debug_s_mask0_clr : 1;
        unsigned int l1_debug_paused_s_mask0_clr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK0_CLR_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK0_CLR_l1_task_debug_s_mask0_clr_START (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK0_CLR_l1_task_debug_s_mask0_clr_END (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK0_CLR_l1_debug_paused_s_mask0_clr_START (1)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK0_CLR_l1_debug_paused_s_mask0_clr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_error_s_mask0_clr : 1;
        unsigned int l1_task_timeout_s_mask0_clr : 1;
        unsigned int l1_task_trap_s_mask0_clr : 1;
        unsigned int l1_sqe_error_s_mask0_clr : 1;
        unsigned int l1_sw_status_error_s_mask0_clr : 1;
        unsigned int l1_bus_error_s_mask0_clr : 1;
        unsigned int l1_ecc_error_s_mask0_clr : 1;
        unsigned int l1_pool_conflict_s_mask0_clr : 1;
        unsigned int l1_hts_error_s_mask0_clr : 1;
        unsigned int l1_pu_pd_timeout_s_mask0_clr : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_CLR_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_CLR_l1_task_error_s_mask0_clr_START (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_CLR_l1_task_error_s_mask0_clr_END (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_CLR_l1_task_timeout_s_mask0_clr_START (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_CLR_l1_task_timeout_s_mask0_clr_END (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_CLR_l1_task_trap_s_mask0_clr_START (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_CLR_l1_task_trap_s_mask0_clr_END (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_CLR_l1_sqe_error_s_mask0_clr_START (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_CLR_l1_sqe_error_s_mask0_clr_END (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_CLR_l1_sw_status_error_s_mask0_clr_START (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_CLR_l1_sw_status_error_s_mask0_clr_END (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_CLR_l1_bus_error_s_mask0_clr_START (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_CLR_l1_bus_error_s_mask0_clr_END (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_CLR_l1_ecc_error_s_mask0_clr_START (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_CLR_l1_ecc_error_s_mask0_clr_END (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_CLR_l1_pool_conflict_s_mask0_clr_START (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_CLR_l1_pool_conflict_s_mask0_clr_END (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_CLR_l1_hts_error_s_mask0_clr_START (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_CLR_l1_hts_error_s_mask0_clr_END (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_CLR_l1_pu_pd_timeout_s_mask0_clr_START (9)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK0_CLR_l1_pu_pd_timeout_s_mask0_clr_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 30;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_sqe_done_s_mask2_clr : 1;
        unsigned int l1_pre_paused_s_mask2_clr : 1;
        unsigned int l1_post_paused_s_mask2_clr : 1;
        unsigned int l1_cq_full_s_mask2_clr : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int l1_sq_done_s_mask2_clr : 1;
        unsigned int l1_cqe_written_s_mask2_clr : 1;
        unsigned int reserved_4 : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_CLR_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_CLR_l1_sqe_done_s_mask2_clr_START (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_CLR_l1_sqe_done_s_mask2_clr_END (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_CLR_l1_pre_paused_s_mask2_clr_START (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_CLR_l1_pre_paused_s_mask2_clr_END (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_CLR_l1_post_paused_s_mask2_clr_START (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_CLR_l1_post_paused_s_mask2_clr_END (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_CLR_l1_cq_full_s_mask2_clr_START (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_CLR_l1_cq_full_s_mask2_clr_END (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_CLR_l1_sq_done_s_mask2_clr_START (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_CLR_l1_sq_done_s_mask2_clr_END (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_CLR_l1_cqe_written_s_mask2_clr_START (9)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_MASK2_CLR_l1_cqe_written_s_mask2_clr_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_debug_s_mask2_clr : 1;
        unsigned int l1_debug_paused_s_mask2_clr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK2_CLR_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK2_CLR_l1_task_debug_s_mask2_clr_START (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK2_CLR_l1_task_debug_s_mask2_clr_END (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK2_CLR_l1_debug_paused_s_mask2_clr_START (1)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_MASK2_CLR_l1_debug_paused_s_mask2_clr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_error_s_mask2_clr : 1;
        unsigned int l1_task_timeout_s_mask2_clr : 1;
        unsigned int l1_task_trap_s_mask2_clr : 1;
        unsigned int l1_sqe_error_s_mask2_clr : 1;
        unsigned int l1_sw_status_error_s_mask2_clr : 1;
        unsigned int l1_bus_error_s_mask2_clr : 1;
        unsigned int l1_ecc_error_s_mask2_clr : 1;
        unsigned int l1_pool_conflict_s_mask2_clr : 1;
        unsigned int l1_hts_error_s_mask2_clr : 1;
        unsigned int l1_pu_pd_timeout_s_mask2_clr : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_CLR_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_CLR_l1_task_error_s_mask2_clr_START (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_CLR_l1_task_error_s_mask2_clr_END (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_CLR_l1_task_timeout_s_mask2_clr_START (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_CLR_l1_task_timeout_s_mask2_clr_END (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_CLR_l1_task_trap_s_mask2_clr_START (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_CLR_l1_task_trap_s_mask2_clr_END (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_CLR_l1_sqe_error_s_mask2_clr_START (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_CLR_l1_sqe_error_s_mask2_clr_END (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_CLR_l1_sw_status_error_s_mask2_clr_START (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_CLR_l1_sw_status_error_s_mask2_clr_END (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_CLR_l1_bus_error_s_mask2_clr_START (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_CLR_l1_bus_error_s_mask2_clr_END (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_CLR_l1_ecc_error_s_mask2_clr_START (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_CLR_l1_ecc_error_s_mask2_clr_END (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_CLR_l1_pool_conflict_s_mask2_clr_START (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_CLR_l1_pool_conflict_s_mask2_clr_END (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_CLR_l1_hts_error_s_mask2_clr_START (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_CLR_l1_hts_error_s_mask2_clr_END (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_CLR_l1_pu_pd_timeout_s_mask2_clr_START (9)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_MASK2_CLR_l1_pu_pd_timeout_s_mask2_clr_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_sqe_done_s_pending0 : 1;
        unsigned int l1_pre_paused_s_pending0 : 1;
        unsigned int l1_post_paused_s_pending0 : 1;
        unsigned int l1_cq_full_s_pending0 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int l1_sq_done_s_pending0 : 1;
        unsigned int l1_cqe_written_s_pending0 : 1;
        unsigned int reserved_4 : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING0_l1_sqe_done_s_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING0_l1_sqe_done_s_pending0_END (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING0_l1_pre_paused_s_pending0_START (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING0_l1_pre_paused_s_pending0_END (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING0_l1_post_paused_s_pending0_START (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING0_l1_post_paused_s_pending0_END (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING0_l1_cq_full_s_pending0_START (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING0_l1_cq_full_s_pending0_END (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING0_l1_sq_done_s_pending0_START (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING0_l1_sq_done_s_pending0_END (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING0_l1_cqe_written_s_pending0_START (9)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING0_l1_cqe_written_s_pending0_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_debug_s_pending0 : 1;
        unsigned int l1_debug_paused_s_pending0 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DEBUG_S_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_INTERRUPT_PENDING0_l1_task_debug_s_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_INTERRUPT_PENDING0_l1_task_debug_s_pending0_END (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_INTERRUPT_PENDING0_l1_debug_paused_s_pending0_START (1)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_INTERRUPT_PENDING0_l1_debug_paused_s_pending0_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_error_s_pending0 : 1;
        unsigned int l1_task_timeout_s_pending0 : 1;
        unsigned int l1_task_trap_s_pending0 : 1;
        unsigned int l1_sqe_error_s_pending0 : 1;
        unsigned int l1_sw_status_error_s_pending0 : 1;
        unsigned int l1_bus_error_s_pending0 : 1;
        unsigned int l1_ecc_error_s_pending0 : 1;
        unsigned int l1_pool_conflict_s_pending0 : 1;
        unsigned int l1_hts_error_s_pending0 : 1;
        unsigned int l1_pu_pd_timeout_s_pending0 : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING0_l1_task_error_s_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING0_l1_task_error_s_pending0_END (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING0_l1_task_timeout_s_pending0_START (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING0_l1_task_timeout_s_pending0_END (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING0_l1_task_trap_s_pending0_START (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING0_l1_task_trap_s_pending0_END (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING0_l1_sqe_error_s_pending0_START (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING0_l1_sqe_error_s_pending0_END (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING0_l1_sw_status_error_s_pending0_START (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING0_l1_sw_status_error_s_pending0_END (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING0_l1_bus_error_s_pending0_START (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING0_l1_bus_error_s_pending0_END (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING0_l1_ecc_error_s_pending0_START (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING0_l1_ecc_error_s_pending0_END (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING0_l1_pool_conflict_s_pending0_START (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING0_l1_pool_conflict_s_pending0_END (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING0_l1_hts_error_s_pending0_START (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING0_l1_hts_error_s_pending0_END (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING0_l1_pu_pd_timeout_s_pending0_START (9)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING0_l1_pu_pd_timeout_s_pending0_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 30;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DEBUG_S_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_sqe_done_s_pending2 : 1;
        unsigned int l1_pre_paused_s_pending2 : 1;
        unsigned int l1_post_paused_s_pending2 : 1;
        unsigned int l1_cq_full_s_pending2 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int l1_sq_done_s_pending2 : 1;
        unsigned int l1_cqe_written_s_pending2 : 1;
        unsigned int reserved_4 : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING2_l1_sqe_done_s_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING2_l1_sqe_done_s_pending2_END (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING2_l1_pre_paused_s_pending2_START (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING2_l1_pre_paused_s_pending2_END (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING2_l1_post_paused_s_pending2_START (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING2_l1_post_paused_s_pending2_END (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING2_l1_cq_full_s_pending2_START (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING2_l1_cq_full_s_pending2_END (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING2_l1_sq_done_s_pending2_START (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING2_l1_sq_done_s_pending2_END (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING2_l1_cqe_written_s_pending2_START (9)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_S_INTERRUPT_PENDING2_l1_cqe_written_s_pending2_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_debug_s_pending2 : 1;
        unsigned int l1_debug_paused_s_pending2 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DEBUG_S_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_INTERRUPT_PENDING2_l1_task_debug_s_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_INTERRUPT_PENDING2_l1_task_debug_s_pending2_END (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_INTERRUPT_PENDING2_l1_debug_paused_s_pending2_START (1)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_S_INTERRUPT_PENDING2_l1_debug_paused_s_pending2_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_error_s_pending2 : 1;
        unsigned int l1_task_timeout_s_pending2 : 1;
        unsigned int l1_task_trap_s_pending2 : 1;
        unsigned int l1_sqe_error_s_pending2 : 1;
        unsigned int l1_sw_status_error_s_pending2 : 1;
        unsigned int l1_bus_error_s_pending2 : 1;
        unsigned int l1_ecc_error_s_pending2 : 1;
        unsigned int l1_pool_conflict_s_pending2 : 1;
        unsigned int l1_hts_error_s_pending2 : 1;
        unsigned int l1_pu_pd_timeout_s_pending2 : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING2_l1_task_error_s_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING2_l1_task_error_s_pending2_END (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING2_l1_task_timeout_s_pending2_START (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING2_l1_task_timeout_s_pending2_END (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING2_l1_task_trap_s_pending2_START (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING2_l1_task_trap_s_pending2_END (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING2_l1_sqe_error_s_pending2_START (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING2_l1_sqe_error_s_pending2_END (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING2_l1_sw_status_error_s_pending2_START (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING2_l1_sw_status_error_s_pending2_END (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING2_l1_bus_error_s_pending2_START (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING2_l1_bus_error_s_pending2_END (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING2_l1_ecc_error_s_pending2_START (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING2_l1_ecc_error_s_pending2_END (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING2_l1_pool_conflict_s_pending2_START (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING2_l1_pool_conflict_s_pending2_END (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING2_l1_hts_error_s_pending2_START (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING2_l1_hts_error_s_pending2_END (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING2_l1_pu_pd_timeout_s_pending2_START (9)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_S_INTERRUPT_PENDING2_l1_pu_pd_timeout_s_pending2_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sqe_done_s_status : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_INTERRUPT_l2_sqe_done_s_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_INTERRUPT_l2_sqe_done_s_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_pre_paused_s_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_INTERRUPT_l2_pre_paused_s_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_INTERRUPT_l2_pre_paused_s_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_post_paused_s_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_INTERRUPT_l2_post_paused_s_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_INTERRUPT_l2_post_paused_s_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_cq_full_s_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_INTERRUPT_l2_cq_full_s_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_INTERRUPT_l2_cq_full_s_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sq_done_s_status : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_INTERRUPT_l2_sq_done_s_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_INTERRUPT_l2_sq_done_s_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_cqe_written_s_status : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_INTERRUPT_l2_cqe_written_s_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_INTERRUPT_l2_cqe_written_s_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_debug_s_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_INTERRUPT_l2_task_debug_s_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_INTERRUPT_l2_task_debug_s_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_debug_paused_s_status : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_INTERRUPT_l2_debug_paused_s_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_INTERRUPT_l2_debug_paused_s_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_error_s_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_INTERRUPT_l2_task_error_s_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_INTERRUPT_l2_task_error_s_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_timeout_s_status : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_INTERRUPT_l2_task_timeout_s_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_INTERRUPT_l2_task_timeout_s_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_trap_s_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_INTERRUPT_l2_task_trap_s_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_INTERRUPT_l2_task_trap_s_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sqe_error_s_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_INTERRUPT_l2_sqe_error_s_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_INTERRUPT_l2_sqe_error_s_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sw_status_error_s_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_INTERRUPT_l2_sw_status_error_s_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_INTERRUPT_l2_sw_status_error_s_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sqe_done_s_force : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_FORCE_l2_sqe_done_s_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_FORCE_l2_sqe_done_s_force_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_pre_paused_s_force : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_FORCE_l2_pre_paused_s_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_FORCE_l2_pre_paused_s_force_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_post_paused_s_force : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_FORCE_l2_post_paused_s_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_FORCE_l2_post_paused_s_force_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_cq_full_s_force : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_FORCE_l2_cq_full_s_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_FORCE_l2_cq_full_s_force_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sq_done_s_force : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_FORCE_l2_sq_done_s_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_FORCE_l2_sq_done_s_force_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_cqe_written_s_force : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_FORCE_l2_cqe_written_s_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_FORCE_l2_cqe_written_s_force_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_debug_s_force : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_FORCE_l2_task_debug_s_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_FORCE_l2_task_debug_s_force_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_debug_paused_s_force : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_FORCE_l2_debug_paused_s_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_FORCE_l2_debug_paused_s_force_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_error_s_force : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_FORCE_l2_task_error_s_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_FORCE_l2_task_error_s_force_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_timeout_s_force : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_FORCE_l2_task_timeout_s_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_FORCE_l2_task_timeout_s_force_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_trap_s_force : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_FORCE_l2_task_trap_s_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_FORCE_l2_task_trap_s_force_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sqe_error_s_force : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_FORCE_l2_sqe_error_s_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_FORCE_l2_sqe_error_s_force_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sw_status_error_s_force : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_FORCE_l2_sw_status_error_s_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_FORCE_l2_sw_status_error_s_force_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_MASK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_MASK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_MASK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_MASK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_MASK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_MASK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_MASK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_MASK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_MASK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_MASK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_MASK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_MASK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_MASK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_MASK2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_MASK2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_MASK2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_MASK2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_MASK2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_MASK2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_MASK2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_MASK2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_MASK2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_MASK2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_MASK2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_MASK2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_MASK2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_MASK0_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_MASK0_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_MASK0_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_MASK0_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_MASK0_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_MASK0_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_MASK0_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_MASK0_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_MASK0_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_MASK0_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_MASK0_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_MASK0_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_MASK0_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_MASK2_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_MASK2_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_MASK2_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_MASK2_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_MASK2_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_MASK2_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_MASK2_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_MASK2_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_MASK2_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_MASK2_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_MASK2_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_MASK2_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_MASK2_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_MASK0_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_MASK0_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_MASK0_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_MASK0_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_MASK0_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_MASK0_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_MASK0_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_MASK0_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_MASK0_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_MASK0_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_MASK0_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_MASK0_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_MASK0_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_MASK2_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_MASK2_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_MASK2_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_MASK2_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_MASK2_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_MASK2_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_MASK2_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_MASK2_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_MASK2_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_MASK2_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_MASK2_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_MASK2_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_MASK2_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sqe_done_s_pending0 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_INTERRUPT_PENDING0_l2_sqe_done_s_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_INTERRUPT_PENDING0_l2_sqe_done_s_pending0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_pre_paused_s_pending0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_INTERRUPT_PENDING0_l2_pre_paused_s_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_INTERRUPT_PENDING0_l2_pre_paused_s_pending0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_post_paused_s_pending0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_INTERRUPT_PENDING0_l2_post_paused_s_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_INTERRUPT_PENDING0_l2_post_paused_s_pending0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_cq_full_s_pending0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_INTERRUPT_PENDING0_l2_cq_full_s_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_INTERRUPT_PENDING0_l2_cq_full_s_pending0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sq_done_s_pending0 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_INTERRUPT_PENDING0_l2_sq_done_s_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_INTERRUPT_PENDING0_l2_sq_done_s_pending0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_cqe_written_s_pending0 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_INTERRUPT_PENDING0_l2_cqe_written_s_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_INTERRUPT_PENDING0_l2_cqe_written_s_pending0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_debug_s_pending0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_INTERRUPT_PENDING0_l2_task_debug_s_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_INTERRUPT_PENDING0_l2_task_debug_s_pending0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_debug_paused_s_pending0 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_INTERRUPT_PENDING0_l2_debug_paused_s_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_INTERRUPT_PENDING0_l2_debug_paused_s_pending0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_error_s_pending0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_INTERRUPT_PENDING0_l2_task_error_s_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_INTERRUPT_PENDING0_l2_task_error_s_pending0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_timeout_s_pending0 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_INTERRUPT_PENDING0_l2_task_timeout_s_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_INTERRUPT_PENDING0_l2_task_timeout_s_pending0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_trap_s_pending0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_INTERRUPT_PENDING0_l2_task_trap_s_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_INTERRUPT_PENDING0_l2_task_trap_s_pending0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sqe_error_s_pending0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_INTERRUPT_PENDING0_l2_sqe_error_s_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_INTERRUPT_PENDING0_l2_sqe_error_s_pending0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sw_status_error_s_pending0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_INTERRUPT_PENDING0_l2_sw_status_error_s_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_INTERRUPT_PENDING0_l2_sw_status_error_s_pending0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sqe_done_s_pending2 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_INTERRUPT_PENDING2_l2_sqe_done_s_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_S_INTERRUPT_PENDING2_l2_sqe_done_s_pending2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_pre_paused_s_pending2 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_INTERRUPT_PENDING2_l2_pre_paused_s_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_S_INTERRUPT_PENDING2_l2_pre_paused_s_pending2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_post_paused_s_pending2 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_INTERRUPT_PENDING2_l2_post_paused_s_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_S_INTERRUPT_PENDING2_l2_post_paused_s_pending2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_cq_full_s_pending2 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_INTERRUPT_PENDING2_l2_cq_full_s_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_S_INTERRUPT_PENDING2_l2_cq_full_s_pending2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sq_done_s_pending2 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_INTERRUPT_PENDING2_l2_sq_done_s_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_S_INTERRUPT_PENDING2_l2_sq_done_s_pending2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_cqe_written_s_pending2 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_INTERRUPT_PENDING2_l2_cqe_written_s_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_S_INTERRUPT_PENDING2_l2_cqe_written_s_pending2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_debug_s_pending2 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_INTERRUPT_PENDING2_l2_task_debug_s_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_S_INTERRUPT_PENDING2_l2_task_debug_s_pending2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_debug_paused_s_pending2 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_INTERRUPT_PENDING2_l2_debug_paused_s_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_S_INTERRUPT_PENDING2_l2_debug_paused_s_pending2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_error_s_pending2 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_INTERRUPT_PENDING2_l2_task_error_s_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_S_INTERRUPT_PENDING2_l2_task_error_s_pending2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_timeout_s_pending2 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_INTERRUPT_PENDING2_l2_task_timeout_s_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_S_INTERRUPT_PENDING2_l2_task_timeout_s_pending2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_trap_s_pending2 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_INTERRUPT_PENDING2_l2_task_trap_s_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_S_INTERRUPT_PENDING2_l2_task_trap_s_pending2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sqe_error_s_pending2 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_INTERRUPT_PENDING2_l2_sqe_error_s_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_S_INTERRUPT_PENDING2_l2_sqe_error_s_pending2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sw_status_error_s_pending2 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_INTERRUPT_PENDING2_l2_sw_status_error_s_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_S_INTERRUPT_PENDING2_l2_sw_status_error_s_pending2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_sqe_done_ns_status : 1;
        unsigned int l1_pre_paused_ns_status : 1;
        unsigned int l1_post_paused_ns_status : 1;
        unsigned int l1_cq_full_ns_status : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int l1_sq_done_ns_status : 1;
        unsigned int l1_cqe_written_ns_status : 1;
        unsigned int reserved_4 : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_l1_sqe_done_ns_status_START (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_l1_sqe_done_ns_status_END (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_l1_pre_paused_ns_status_START (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_l1_pre_paused_ns_status_END (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_l1_post_paused_ns_status_START (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_l1_post_paused_ns_status_END (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_l1_cq_full_ns_status_START (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_l1_cq_full_ns_status_END (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_l1_sq_done_ns_status_START (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_l1_sq_done_ns_status_END (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_l1_cqe_written_ns_status_START (9)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_l1_cqe_written_ns_status_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_debug_ns_status : 1;
        unsigned int l1_debug_paused_ns_status : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_INTERRUPT_l1_task_debug_ns_status_START (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_INTERRUPT_l1_task_debug_ns_status_END (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_INTERRUPT_l1_debug_paused_ns_status_START (1)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_INTERRUPT_l1_debug_paused_ns_status_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_error_ns_status : 1;
        unsigned int l1_task_timeout_ns_status : 1;
        unsigned int l1_task_trap_ns_status : 1;
        unsigned int l1_sqe_error_ns_status : 1;
        unsigned int l1_sw_status_error_ns_status : 1;
        unsigned int l1_bus_error_ns_status : 1;
        unsigned int l1_ecc_error_ns_status : 1;
        unsigned int l1_pool_conflict_ns_status : 1;
        unsigned int l1_hts_error_ns_status : 1;
        unsigned int l1_ffrt_error_ns_status : 1;
        unsigned int l1_ffrt_drain_ns_status : 1;
        unsigned int l1_pu_pd_timeout_ns_status : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_l1_task_error_ns_status_START (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_l1_task_error_ns_status_END (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_l1_task_timeout_ns_status_START (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_l1_task_timeout_ns_status_END (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_l1_task_trap_ns_status_START (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_l1_task_trap_ns_status_END (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_l1_sqe_error_ns_status_START (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_l1_sqe_error_ns_status_END (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_l1_sw_status_error_ns_status_START (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_l1_sw_status_error_ns_status_END (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_l1_bus_error_ns_status_START (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_l1_bus_error_ns_status_END (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_l1_ecc_error_ns_status_START (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_l1_ecc_error_ns_status_END (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_l1_pool_conflict_ns_status_START (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_l1_pool_conflict_ns_status_END (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_l1_hts_error_ns_status_START (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_l1_hts_error_ns_status_END (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_l1_ffrt_error_ns_status_START (9)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_l1_ffrt_error_ns_status_END (9)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_l1_ffrt_drain_ns_status_START (10)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_l1_ffrt_drain_ns_status_END (10)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_l1_pu_pd_timeout_ns_status_START (11)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_l1_pu_pd_timeout_ns_status_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_profile_almost_full_status : 1;
        unsigned int reserved_0 : 1;
        unsigned int l1_log_almost_full_status : 1;
        unsigned int reserved_1 : 29;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DFX_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_DFX_INTERRUPT_l1_profile_almost_full_status_START (0)
#define SOC_NPU_HWTS_HWTS_L1_DFX_INTERRUPT_l1_profile_almost_full_status_END (0)
#define SOC_NPU_HWTS_HWTS_L1_DFX_INTERRUPT_l1_log_almost_full_status_START (2)
#define SOC_NPU_HWTS_HWTS_L1_DFX_INTERRUPT_l1_log_almost_full_status_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 5;
        unsigned int l1_bus_error_ns_force : 1;
        unsigned int l1_ecc_error_ns_force : 1;
        unsigned int l1_pool_conflict_ns_force : 1;
        unsigned int l1_hts_error_ns_force : 1;
        unsigned int l1_pu_pd_timeout_ns_force : 1;
        unsigned int reserved_1 : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_FORCE_l1_bus_error_ns_force_START (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_FORCE_l1_bus_error_ns_force_END (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_FORCE_l1_ecc_error_ns_force_START (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_FORCE_l1_ecc_error_ns_force_END (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_FORCE_l1_pool_conflict_ns_force_START (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_FORCE_l1_pool_conflict_ns_force_END (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_FORCE_l1_hts_error_ns_force_START (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_FORCE_l1_hts_error_ns_force_END (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_FORCE_l1_pu_pd_timeout_ns_force_START (9)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_FORCE_l1_pu_pd_timeout_ns_force_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 29;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DFX_INTERRUPT_FORCE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_sqe_done_ns_mask0 : 1;
        unsigned int l1_pre_paused_ns_mask0 : 1;
        unsigned int l1_post_paused_ns_mask0 : 1;
        unsigned int l1_cq_full_ns_mask0 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int l1_sq_done_ns_mask0 : 1;
        unsigned int l1_cqe_written_ns_mask0 : 1;
        unsigned int reserved_4 : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_l1_sqe_done_ns_mask0_START (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_l1_sqe_done_ns_mask0_END (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_l1_pre_paused_ns_mask0_START (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_l1_pre_paused_ns_mask0_END (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_l1_post_paused_ns_mask0_START (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_l1_post_paused_ns_mask0_END (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_l1_cq_full_ns_mask0_START (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_l1_cq_full_ns_mask0_END (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_l1_sq_done_ns_mask0_START (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_l1_sq_done_ns_mask0_END (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_l1_cqe_written_ns_mask0_START (9)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_l1_cqe_written_ns_mask0_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_debug_ns_mask0 : 1;
        unsigned int l1_debug_paused_ns_mask0 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK0_l1_task_debug_ns_mask0_START (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK0_l1_task_debug_ns_mask0_END (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK0_l1_debug_paused_ns_mask0_START (1)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK0_l1_debug_paused_ns_mask0_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_error_ns_mask0 : 1;
        unsigned int l1_task_timeout_ns_mask0 : 1;
        unsigned int l1_task_trap_ns_mask0 : 1;
        unsigned int l1_sqe_error_ns_mask0 : 1;
        unsigned int l1_sw_status_error_ns_mask0 : 1;
        unsigned int l1_bus_error_ns_mask0 : 1;
        unsigned int l1_ecc_error_ns_mask0 : 1;
        unsigned int l1_pool_conflict_ns_mask0 : 1;
        unsigned int l1_hts_error_ns_mask0 : 1;
        unsigned int l1_ffrt_error_ns_mask0 : 1;
        unsigned int l1_ffrt_drain_ns_mask0 : 1;
        unsigned int l1_pu_pd_timeout_ns_mask0 : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_l1_task_error_ns_mask0_START (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_l1_task_error_ns_mask0_END (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_l1_task_timeout_ns_mask0_START (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_l1_task_timeout_ns_mask0_END (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_l1_task_trap_ns_mask0_START (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_l1_task_trap_ns_mask0_END (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_l1_sqe_error_ns_mask0_START (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_l1_sqe_error_ns_mask0_END (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_l1_sw_status_error_ns_mask0_START (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_l1_sw_status_error_ns_mask0_END (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_l1_bus_error_ns_mask0_START (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_l1_bus_error_ns_mask0_END (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_l1_ecc_error_ns_mask0_START (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_l1_ecc_error_ns_mask0_END (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_l1_pool_conflict_ns_mask0_START (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_l1_pool_conflict_ns_mask0_END (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_l1_hts_error_ns_mask0_START (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_l1_hts_error_ns_mask0_END (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_l1_ffrt_error_ns_mask0_START (9)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_l1_ffrt_error_ns_mask0_END (9)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_l1_ffrt_drain_ns_mask0_START (10)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_l1_ffrt_drain_ns_mask0_END (10)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_l1_pu_pd_timeout_ns_mask0_START (11)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_l1_pu_pd_timeout_ns_mask0_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 30;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_sqe_done_ns_mask2 : 1;
        unsigned int l1_pre_paused_ns_mask2 : 1;
        unsigned int l1_post_paused_ns_mask2 : 1;
        unsigned int l1_cq_full_ns_mask2 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int l1_sq_done_ns_mask2 : 1;
        unsigned int l1_cqe_written_ns_mask2 : 1;
        unsigned int reserved_4 : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_l1_sqe_done_ns_mask2_START (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_l1_sqe_done_ns_mask2_END (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_l1_pre_paused_ns_mask2_START (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_l1_pre_paused_ns_mask2_END (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_l1_post_paused_ns_mask2_START (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_l1_post_paused_ns_mask2_END (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_l1_cq_full_ns_mask2_START (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_l1_cq_full_ns_mask2_END (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_l1_sq_done_ns_mask2_START (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_l1_sq_done_ns_mask2_END (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_l1_cqe_written_ns_mask2_START (9)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_l1_cqe_written_ns_mask2_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_debug_ns_mask2 : 1;
        unsigned int l1_debug_paused_ns_mask2 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK2_l1_task_debug_ns_mask2_START (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK2_l1_task_debug_ns_mask2_END (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK2_l1_debug_paused_ns_mask2_START (1)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK2_l1_debug_paused_ns_mask2_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_error_ns_mask2 : 1;
        unsigned int l1_task_timeout_ns_mask2 : 1;
        unsigned int l1_task_trap_ns_mask2 : 1;
        unsigned int l1_sqe_error_ns_mask2 : 1;
        unsigned int l1_sw_status_error_ns_mask2 : 1;
        unsigned int l1_bus_error_ns_mask2 : 1;
        unsigned int l1_ecc_error_ns_mask2 : 1;
        unsigned int l1_pool_conflict_ns_mask2 : 1;
        unsigned int l1_hts_error_ns_mask2 : 1;
        unsigned int l1_ffrt_error_ns_mask2 : 1;
        unsigned int l1_ffrt_drain_ns_mask2 : 1;
        unsigned int l1_pu_pd_timeout_ns_mask2 : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_l1_task_error_ns_mask2_START (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_l1_task_error_ns_mask2_END (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_l1_task_timeout_ns_mask2_START (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_l1_task_timeout_ns_mask2_END (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_l1_task_trap_ns_mask2_START (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_l1_task_trap_ns_mask2_END (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_l1_sqe_error_ns_mask2_START (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_l1_sqe_error_ns_mask2_END (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_l1_sw_status_error_ns_mask2_START (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_l1_sw_status_error_ns_mask2_END (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_l1_bus_error_ns_mask2_START (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_l1_bus_error_ns_mask2_END (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_l1_ecc_error_ns_mask2_START (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_l1_ecc_error_ns_mask2_END (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_l1_pool_conflict_ns_mask2_START (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_l1_pool_conflict_ns_mask2_END (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_l1_hts_error_ns_mask2_START (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_l1_hts_error_ns_mask2_END (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_l1_ffrt_error_ns_mask2_START (9)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_l1_ffrt_error_ns_mask2_END (9)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_l1_ffrt_drain_ns_mask2_START (10)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_l1_ffrt_drain_ns_mask2_END (10)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_l1_pu_pd_timeout_ns_mask2_START (11)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_l1_pu_pd_timeout_ns_mask2_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_profile_almost_full_mask : 1;
        unsigned int reserved_0 : 1;
        unsigned int l1_log_almost_full_mask : 1;
        unsigned int reserved_1 : 29;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DFX_MASK_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_DFX_MASK_l1_profile_almost_full_mask_START (0)
#define SOC_NPU_HWTS_HWTS_L1_DFX_MASK_l1_profile_almost_full_mask_END (0)
#define SOC_NPU_HWTS_HWTS_L1_DFX_MASK_l1_log_almost_full_mask_START (2)
#define SOC_NPU_HWTS_HWTS_L1_DFX_MASK_l1_log_almost_full_mask_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_sqe_done_ns_mask0_set : 1;
        unsigned int l1_pre_paused_ns_mask0_set : 1;
        unsigned int l1_post_paused_ns_mask0_set : 1;
        unsigned int l1_cq_full_ns_mask0_set : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int l1_sq_done_ns_mask0_set : 1;
        unsigned int l1_cqe_written_ns_mask0_set : 1;
        unsigned int reserved_4 : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_SET_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_SET_l1_sqe_done_ns_mask0_set_START (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_SET_l1_sqe_done_ns_mask0_set_END (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_SET_l1_pre_paused_ns_mask0_set_START (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_SET_l1_pre_paused_ns_mask0_set_END (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_SET_l1_post_paused_ns_mask0_set_START (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_SET_l1_post_paused_ns_mask0_set_END (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_SET_l1_cq_full_ns_mask0_set_START (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_SET_l1_cq_full_ns_mask0_set_END (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_SET_l1_sq_done_ns_mask0_set_START (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_SET_l1_sq_done_ns_mask0_set_END (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_SET_l1_cqe_written_ns_mask0_set_START (9)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_SET_l1_cqe_written_ns_mask0_set_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_debug_ns_mask0_set : 1;
        unsigned int l1_debug_paused_ns_mask0_set : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK0_SET_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK0_SET_l1_task_debug_ns_mask0_set_START (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK0_SET_l1_task_debug_ns_mask0_set_END (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK0_SET_l1_debug_paused_ns_mask0_set_START (1)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK0_SET_l1_debug_paused_ns_mask0_set_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_error_ns_mask0_set : 1;
        unsigned int l1_task_timeout_ns_mask0_set : 1;
        unsigned int l1_task_trap_ns_mask0_set : 1;
        unsigned int l1_sqe_error_ns_mask0_set : 1;
        unsigned int l1_sw_status_error_ns_mask0_set : 1;
        unsigned int l1_bus_error_ns_mask0_set : 1;
        unsigned int l1_ecc_error_ns_mask0_set : 1;
        unsigned int l1_pool_conflict_ns_mask0_set : 1;
        unsigned int l1_hts_error_ns_mask0_set : 1;
        unsigned int l1_ffrt_error_ns_mask0_set : 1;
        unsigned int l1_ffrt_drain_ns_mask0_set : 1;
        unsigned int l1_pu_pd_timeout_ns_mask0_set : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_SET_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_SET_l1_task_error_ns_mask0_set_START (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_SET_l1_task_error_ns_mask0_set_END (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_SET_l1_task_timeout_ns_mask0_set_START (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_SET_l1_task_timeout_ns_mask0_set_END (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_SET_l1_task_trap_ns_mask0_set_START (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_SET_l1_task_trap_ns_mask0_set_END (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_SET_l1_sqe_error_ns_mask0_set_START (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_SET_l1_sqe_error_ns_mask0_set_END (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_SET_l1_sw_status_error_ns_mask0_set_START (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_SET_l1_sw_status_error_ns_mask0_set_END (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_SET_l1_bus_error_ns_mask0_set_START (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_SET_l1_bus_error_ns_mask0_set_END (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_SET_l1_ecc_error_ns_mask0_set_START (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_SET_l1_ecc_error_ns_mask0_set_END (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_SET_l1_pool_conflict_ns_mask0_set_START (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_SET_l1_pool_conflict_ns_mask0_set_END (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_SET_l1_hts_error_ns_mask0_set_START (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_SET_l1_hts_error_ns_mask0_set_END (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_SET_l1_ffrt_error_ns_mask0_set_START (9)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_SET_l1_ffrt_error_ns_mask0_set_END (9)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_SET_l1_ffrt_drain_ns_mask0_set_START (10)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_SET_l1_ffrt_drain_ns_mask0_set_END (10)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_SET_l1_pu_pd_timeout_ns_mask0_set_START (11)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_SET_l1_pu_pd_timeout_ns_mask0_set_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 30;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_sqe_done_ns_mask2_set : 1;
        unsigned int l1_pre_paused_ns_mask2_set : 1;
        unsigned int l1_post_paused_ns_mask2_set : 1;
        unsigned int l1_cq_full_ns_mask2_set : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int l1_sq_done_ns_mask2_set : 1;
        unsigned int l1_cqe_written_ns_mask2_set : 1;
        unsigned int reserved_4 : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_SET_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_SET_l1_sqe_done_ns_mask2_set_START (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_SET_l1_sqe_done_ns_mask2_set_END (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_SET_l1_pre_paused_ns_mask2_set_START (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_SET_l1_pre_paused_ns_mask2_set_END (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_SET_l1_post_paused_ns_mask2_set_START (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_SET_l1_post_paused_ns_mask2_set_END (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_SET_l1_cq_full_ns_mask2_set_START (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_SET_l1_cq_full_ns_mask2_set_END (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_SET_l1_sq_done_ns_mask2_set_START (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_SET_l1_sq_done_ns_mask2_set_END (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_SET_l1_cqe_written_ns_mask2_set_START (9)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_SET_l1_cqe_written_ns_mask2_set_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_debug_ns_mask2_set : 1;
        unsigned int l1_debug_paused_ns_mask2_set : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK2_SET_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK2_SET_l1_task_debug_ns_mask2_set_START (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK2_SET_l1_task_debug_ns_mask2_set_END (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK2_SET_l1_debug_paused_ns_mask2_set_START (1)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK2_SET_l1_debug_paused_ns_mask2_set_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_error_ns_mask2_set : 1;
        unsigned int l1_task_timeout_ns_mask2_set : 1;
        unsigned int l1_task_trap_ns_mask2_set : 1;
        unsigned int l1_sqe_error_ns_mask2_set : 1;
        unsigned int l1_sw_status_error_ns_mask2_set : 1;
        unsigned int l1_bus_error_ns_mask2_set : 1;
        unsigned int l1_ecc_error_ns_mask2_set : 1;
        unsigned int l1_pool_conflict_ns_mask2_set : 1;
        unsigned int l1_hts_error_ns_mask2_set : 1;
        unsigned int l1_ffrt_error_ns_mask2_set : 1;
        unsigned int l1_ffrt_drain_ns_mask2_set : 1;
        unsigned int l1_pu_pd_timeout_ns_mask2_set : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_SET_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_SET_l1_task_error_ns_mask2_set_START (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_SET_l1_task_error_ns_mask2_set_END (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_SET_l1_task_timeout_ns_mask2_set_START (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_SET_l1_task_timeout_ns_mask2_set_END (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_SET_l1_task_trap_ns_mask2_set_START (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_SET_l1_task_trap_ns_mask2_set_END (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_SET_l1_sqe_error_ns_mask2_set_START (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_SET_l1_sqe_error_ns_mask2_set_END (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_SET_l1_sw_status_error_ns_mask2_set_START (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_SET_l1_sw_status_error_ns_mask2_set_END (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_SET_l1_bus_error_ns_mask2_set_START (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_SET_l1_bus_error_ns_mask2_set_END (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_SET_l1_ecc_error_ns_mask2_set_START (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_SET_l1_ecc_error_ns_mask2_set_END (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_SET_l1_pool_conflict_ns_mask2_set_START (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_SET_l1_pool_conflict_ns_mask2_set_END (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_SET_l1_hts_error_ns_mask2_set_START (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_SET_l1_hts_error_ns_mask2_set_END (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_SET_l1_ffrt_error_ns_mask2_set_START (9)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_SET_l1_ffrt_error_ns_mask2_set_END (9)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_SET_l1_ffrt_drain_ns_mask2_set_START (10)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_SET_l1_ffrt_drain_ns_mask2_set_END (10)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_SET_l1_pu_pd_timeout_ns_mask2_set_START (11)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_SET_l1_pu_pd_timeout_ns_mask2_set_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_profile_almost_full_mask_set : 1;
        unsigned int reserved_0 : 1;
        unsigned int l1_log_almost_full_mask_set : 1;
        unsigned int reserved_1 : 29;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DFX_MASK_SET_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_DFX_MASK_SET_l1_profile_almost_full_mask_set_START (0)
#define SOC_NPU_HWTS_HWTS_L1_DFX_MASK_SET_l1_profile_almost_full_mask_set_END (0)
#define SOC_NPU_HWTS_HWTS_L1_DFX_MASK_SET_l1_log_almost_full_mask_set_START (2)
#define SOC_NPU_HWTS_HWTS_L1_DFX_MASK_SET_l1_log_almost_full_mask_set_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_sqe_done_ns_mask0_clr : 1;
        unsigned int l1_pre_paused_ns_mask0_clr : 1;
        unsigned int l1_post_paused_ns_mask0_clr : 1;
        unsigned int l1_cq_full_ns_mask0_clr : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int l1_sq_done_ns_mask0_clr : 1;
        unsigned int l1_cqe_written_ns_mask0_clr : 1;
        unsigned int reserved_4 : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_CLR_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_CLR_l1_sqe_done_ns_mask0_clr_START (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_CLR_l1_sqe_done_ns_mask0_clr_END (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_CLR_l1_pre_paused_ns_mask0_clr_START (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_CLR_l1_pre_paused_ns_mask0_clr_END (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_CLR_l1_post_paused_ns_mask0_clr_START (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_CLR_l1_post_paused_ns_mask0_clr_END (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_CLR_l1_cq_full_ns_mask0_clr_START (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_CLR_l1_cq_full_ns_mask0_clr_END (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_CLR_l1_sq_done_ns_mask0_clr_START (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_CLR_l1_sq_done_ns_mask0_clr_END (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_CLR_l1_cqe_written_ns_mask0_clr_START (9)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK0_CLR_l1_cqe_written_ns_mask0_clr_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_debug_ns_mask0_clr : 1;
        unsigned int l1_debug_paused_ns_mask0_clr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK0_CLR_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK0_CLR_l1_task_debug_ns_mask0_clr_START (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK0_CLR_l1_task_debug_ns_mask0_clr_END (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK0_CLR_l1_debug_paused_ns_mask0_clr_START (1)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK0_CLR_l1_debug_paused_ns_mask0_clr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_error_ns_mask0_clr : 1;
        unsigned int l1_task_timeout_ns_mask0_clr : 1;
        unsigned int l1_task_trap_ns_mask0_clr : 1;
        unsigned int l1_sqe_error_ns_mask0_clr : 1;
        unsigned int l1_sw_status_error_ns_mask0_clr : 1;
        unsigned int l1_bus_error_ns_mask0_clr : 1;
        unsigned int l1_ecc_error_ns_mask0_clr : 1;
        unsigned int l1_pool_conflict_ns_mask0_clr : 1;
        unsigned int l1_hts_error_ns_mask0_clr : 1;
        unsigned int l1_ffrt_error_ns_mask0_clr : 1;
        unsigned int l1_ffrt_drain_ns_mask0_clr : 1;
        unsigned int l1_pu_pd_timeout_ns_mask0_clr : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_CLR_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_CLR_l1_task_error_ns_mask0_clr_START (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_CLR_l1_task_error_ns_mask0_clr_END (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_CLR_l1_task_timeout_ns_mask0_clr_START (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_CLR_l1_task_timeout_ns_mask0_clr_END (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_CLR_l1_task_trap_ns_mask0_clr_START (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_CLR_l1_task_trap_ns_mask0_clr_END (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_CLR_l1_sqe_error_ns_mask0_clr_START (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_CLR_l1_sqe_error_ns_mask0_clr_END (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_CLR_l1_sw_status_error_ns_mask0_clr_START (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_CLR_l1_sw_status_error_ns_mask0_clr_END (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_CLR_l1_bus_error_ns_mask0_clr_START (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_CLR_l1_bus_error_ns_mask0_clr_END (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_CLR_l1_ecc_error_ns_mask0_clr_START (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_CLR_l1_ecc_error_ns_mask0_clr_END (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_CLR_l1_pool_conflict_ns_mask0_clr_START (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_CLR_l1_pool_conflict_ns_mask0_clr_END (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_CLR_l1_hts_error_ns_mask0_clr_START (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_CLR_l1_hts_error_ns_mask0_clr_END (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_CLR_l1_ffrt_error_ns_mask0_clr_START (9)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_CLR_l1_ffrt_error_ns_mask0_clr_END (9)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_CLR_l1_ffrt_drain_ns_mask0_clr_START (10)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_CLR_l1_ffrt_drain_ns_mask0_clr_END (10)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_CLR_l1_pu_pd_timeout_ns_mask0_clr_START (11)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK0_CLR_l1_pu_pd_timeout_ns_mask0_clr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 30;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_sqe_done_ns_mask2_clr : 1;
        unsigned int l1_pre_paused_ns_mask2_clr : 1;
        unsigned int l1_post_paused_ns_mask2_clr : 1;
        unsigned int l1_cq_full_ns_mask2_clr : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int l1_sq_done_ns_mask2_clr : 1;
        unsigned int l1_cqe_written_ns_mask2_clr : 1;
        unsigned int reserved_4 : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_CLR_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_CLR_l1_sqe_done_ns_mask2_clr_START (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_CLR_l1_sqe_done_ns_mask2_clr_END (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_CLR_l1_pre_paused_ns_mask2_clr_START (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_CLR_l1_pre_paused_ns_mask2_clr_END (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_CLR_l1_post_paused_ns_mask2_clr_START (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_CLR_l1_post_paused_ns_mask2_clr_END (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_CLR_l1_cq_full_ns_mask2_clr_START (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_CLR_l1_cq_full_ns_mask2_clr_END (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_CLR_l1_sq_done_ns_mask2_clr_START (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_CLR_l1_sq_done_ns_mask2_clr_END (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_CLR_l1_cqe_written_ns_mask2_clr_START (9)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_MASK2_CLR_l1_cqe_written_ns_mask2_clr_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_debug_ns_mask2_clr : 1;
        unsigned int l1_debug_paused_ns_mask2_clr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK2_CLR_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK2_CLR_l1_task_debug_ns_mask2_clr_START (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK2_CLR_l1_task_debug_ns_mask2_clr_END (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK2_CLR_l1_debug_paused_ns_mask2_clr_START (1)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_MASK2_CLR_l1_debug_paused_ns_mask2_clr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_error_ns_mask2_clr : 1;
        unsigned int l1_task_timeout_ns_mask2_clr : 1;
        unsigned int l1_task_trap_ns_mask2_clr : 1;
        unsigned int l1_sqe_error_ns_mask2_clr : 1;
        unsigned int l1_sw_status_error_ns_mask2_clr : 1;
        unsigned int l1_bus_error_ns_mask2_clr : 1;
        unsigned int l1_ecc_error_ns_mask2_clr : 1;
        unsigned int l1_pool_conflict_ns_mask2_clr : 1;
        unsigned int l1_hts_error_ns_mask2_clr : 1;
        unsigned int l1_ffrt_error_ns_mask2_clr : 1;
        unsigned int l1_ffrt_drain_ns_mask2_clr : 1;
        unsigned int l1_pu_pd_timeout_ns_mask2_clr : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_CLR_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_CLR_l1_task_error_ns_mask2_clr_START (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_CLR_l1_task_error_ns_mask2_clr_END (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_CLR_l1_task_timeout_ns_mask2_clr_START (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_CLR_l1_task_timeout_ns_mask2_clr_END (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_CLR_l1_task_trap_ns_mask2_clr_START (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_CLR_l1_task_trap_ns_mask2_clr_END (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_CLR_l1_sqe_error_ns_mask2_clr_START (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_CLR_l1_sqe_error_ns_mask2_clr_END (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_CLR_l1_sw_status_error_ns_mask2_clr_START (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_CLR_l1_sw_status_error_ns_mask2_clr_END (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_CLR_l1_bus_error_ns_mask2_clr_START (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_CLR_l1_bus_error_ns_mask2_clr_END (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_CLR_l1_ecc_error_ns_mask2_clr_START (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_CLR_l1_ecc_error_ns_mask2_clr_END (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_CLR_l1_pool_conflict_ns_mask2_clr_START (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_CLR_l1_pool_conflict_ns_mask2_clr_END (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_CLR_l1_hts_error_ns_mask2_clr_START (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_CLR_l1_hts_error_ns_mask2_clr_END (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_CLR_l1_ffrt_error_ns_mask2_clr_START (9)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_CLR_l1_ffrt_error_ns_mask2_clr_END (9)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_CLR_l1_ffrt_drain_ns_mask2_clr_START (10)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_CLR_l1_ffrt_drain_ns_mask2_clr_END (10)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_CLR_l1_pu_pd_timeout_ns_mask2_clr_START (11)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_MASK2_CLR_l1_pu_pd_timeout_ns_mask2_clr_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_profile_almost_full_mask_clr : 1;
        unsigned int reserved_0 : 1;
        unsigned int l1_log_almost_full_mask_clr : 1;
        unsigned int reserved_1 : 29;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DFX_MASK_CLR_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_DFX_MASK_CLR_l1_profile_almost_full_mask_clr_START (0)
#define SOC_NPU_HWTS_HWTS_L1_DFX_MASK_CLR_l1_profile_almost_full_mask_clr_END (0)
#define SOC_NPU_HWTS_HWTS_L1_DFX_MASK_CLR_l1_log_almost_full_mask_clr_START (2)
#define SOC_NPU_HWTS_HWTS_L1_DFX_MASK_CLR_l1_log_almost_full_mask_clr_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_sqe_done_ns_pending0 : 1;
        unsigned int l1_pre_paused_ns_pending0 : 1;
        unsigned int l1_post_paused_ns_pending0 : 1;
        unsigned int l1_cq_full_ns_pending0 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int l1_sq_done_ns_pending0 : 1;
        unsigned int l1_cqe_written_ns_pending0 : 1;
        unsigned int reserved_4 : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING0_l1_sqe_done_ns_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING0_l1_sqe_done_ns_pending0_END (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING0_l1_pre_paused_ns_pending0_START (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING0_l1_pre_paused_ns_pending0_END (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING0_l1_post_paused_ns_pending0_START (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING0_l1_post_paused_ns_pending0_END (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING0_l1_cq_full_ns_pending0_START (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING0_l1_cq_full_ns_pending0_END (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING0_l1_sq_done_ns_pending0_START (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING0_l1_sq_done_ns_pending0_END (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING0_l1_cqe_written_ns_pending0_START (9)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING0_l1_cqe_written_ns_pending0_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_debug_ns_pending0 : 1;
        unsigned int l1_debug_paused_ns_pending0 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_INTERRUPT_PENDING0_l1_task_debug_ns_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_INTERRUPT_PENDING0_l1_task_debug_ns_pending0_END (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_INTERRUPT_PENDING0_l1_debug_paused_ns_pending0_START (1)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_INTERRUPT_PENDING0_l1_debug_paused_ns_pending0_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_error_ns_pending0 : 1;
        unsigned int l1_task_timeout_ns_pending0 : 1;
        unsigned int l1_task_trap_ns_pending0 : 1;
        unsigned int l1_sqe_error_ns_pending0 : 1;
        unsigned int l1_sw_status_error_ns_pending0 : 1;
        unsigned int l1_bus_error_ns_pending0 : 1;
        unsigned int l1_ecc_error_ns_pending0 : 1;
        unsigned int l1_pool_conflict_ns_pending0 : 1;
        unsigned int l1_hts_error_ns_pending0 : 1;
        unsigned int l1_ffrt_error_ns_pending0 : 1;
        unsigned int l1_ffrt_drain_ns_pending0 : 1;
        unsigned int l1_pu_pd_timeout_ns_pending0 : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING0_l1_task_error_ns_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING0_l1_task_error_ns_pending0_END (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING0_l1_task_timeout_ns_pending0_START (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING0_l1_task_timeout_ns_pending0_END (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING0_l1_task_trap_ns_pending0_START (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING0_l1_task_trap_ns_pending0_END (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING0_l1_sqe_error_ns_pending0_START (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING0_l1_sqe_error_ns_pending0_END (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING0_l1_sw_status_error_ns_pending0_START (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING0_l1_sw_status_error_ns_pending0_END (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING0_l1_bus_error_ns_pending0_START (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING0_l1_bus_error_ns_pending0_END (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING0_l1_ecc_error_ns_pending0_START (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING0_l1_ecc_error_ns_pending0_END (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING0_l1_pool_conflict_ns_pending0_START (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING0_l1_pool_conflict_ns_pending0_END (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING0_l1_hts_error_ns_pending0_START (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING0_l1_hts_error_ns_pending0_END (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING0_l1_ffrt_error_ns_pending0_START (9)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING0_l1_ffrt_error_ns_pending0_END (9)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING0_l1_ffrt_drain_ns_pending0_START (10)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING0_l1_ffrt_drain_ns_pending0_END (10)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING0_l1_pu_pd_timeout_ns_pending0_START (11)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING0_l1_pu_pd_timeout_ns_pending0_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 30;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_sqe_done_ns_pending2 : 1;
        unsigned int l1_pre_paused_ns_pending2 : 1;
        unsigned int l1_post_paused_ns_pending2 : 1;
        unsigned int l1_cq_full_ns_pending2 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int l1_sq_done_ns_pending2 : 1;
        unsigned int l1_cqe_written_ns_pending2 : 1;
        unsigned int reserved_4 : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING2_l1_sqe_done_ns_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING2_l1_sqe_done_ns_pending2_END (0)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING2_l1_pre_paused_ns_pending2_START (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING2_l1_pre_paused_ns_pending2_END (1)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING2_l1_post_paused_ns_pending2_START (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING2_l1_post_paused_ns_pending2_END (2)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING2_l1_cq_full_ns_pending2_START (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING2_l1_cq_full_ns_pending2_END (3)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING2_l1_sq_done_ns_pending2_START (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING2_l1_sq_done_ns_pending2_END (8)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING2_l1_cqe_written_ns_pending2_START (9)
#define SOC_NPU_HWTS_HWTS_L1_NORMAL_NS_INTERRUPT_PENDING2_l1_cqe_written_ns_pending2_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_debug_ns_pending2 : 1;
        unsigned int l1_debug_paused_ns_pending2 : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_INTERRUPT_PENDING2_l1_task_debug_ns_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_INTERRUPT_PENDING2_l1_task_debug_ns_pending2_END (0)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_INTERRUPT_PENDING2_l1_debug_paused_ns_pending2_START (1)
#define SOC_NPU_HWTS_HWTS_L1_DEBUG_NS_INTERRUPT_PENDING2_l1_debug_paused_ns_pending2_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_task_error_ns_pending2 : 1;
        unsigned int l1_task_timeout_ns_pending2 : 1;
        unsigned int l1_task_trap_ns_pending2 : 1;
        unsigned int l1_sqe_error_ns_pending2 : 1;
        unsigned int l1_sw_status_error_ns_pending2 : 1;
        unsigned int l1_bus_error_ns_pending2 : 1;
        unsigned int l1_ecc_error_ns_pending2 : 1;
        unsigned int l1_pool_conflict_ns_pending2 : 1;
        unsigned int l1_hts_error_ns_pending2 : 1;
        unsigned int l1_ffrt_error_ns_pending2 : 1;
        unsigned int l1_ffrt_drain_ns_pending2 : 1;
        unsigned int l1_pu_pd_timeout_ns_pending2 : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING2_l1_task_error_ns_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING2_l1_task_error_ns_pending2_END (0)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING2_l1_task_timeout_ns_pending2_START (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING2_l1_task_timeout_ns_pending2_END (1)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING2_l1_task_trap_ns_pending2_START (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING2_l1_task_trap_ns_pending2_END (2)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING2_l1_sqe_error_ns_pending2_START (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING2_l1_sqe_error_ns_pending2_END (3)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING2_l1_sw_status_error_ns_pending2_START (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING2_l1_sw_status_error_ns_pending2_END (4)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING2_l1_bus_error_ns_pending2_START (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING2_l1_bus_error_ns_pending2_END (5)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING2_l1_ecc_error_ns_pending2_START (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING2_l1_ecc_error_ns_pending2_END (6)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING2_l1_pool_conflict_ns_pending2_START (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING2_l1_pool_conflict_ns_pending2_END (7)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING2_l1_hts_error_ns_pending2_START (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING2_l1_hts_error_ns_pending2_END (8)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING2_l1_ffrt_error_ns_pending2_START (9)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING2_l1_ffrt_error_ns_pending2_END (9)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING2_l1_ffrt_drain_ns_pending2_START (10)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING2_l1_ffrt_drain_ns_pending2_END (10)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING2_l1_pu_pd_timeout_ns_pending2_START (11)
#define SOC_NPU_HWTS_HWTS_L1_ERROR_NS_INTERRUPT_PENDING2_l1_pu_pd_timeout_ns_pending2_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l1_profile_almost_full_pending : 1;
        unsigned int reserved_0 : 1;
        unsigned int l1_log_almost_full_pending : 1;
        unsigned int reserved_1 : 29;
    } reg;
} SOC_NPU_HWTS_HWTS_L1_DFX_INTERRUPT_PENDING_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L1_DFX_INTERRUPT_PENDING_l1_profile_almost_full_pending_START (0)
#define SOC_NPU_HWTS_HWTS_L1_DFX_INTERRUPT_PENDING_l1_profile_almost_full_pending_END (0)
#define SOC_NPU_HWTS_HWTS_L1_DFX_INTERRUPT_PENDING_l1_log_almost_full_pending_START (2)
#define SOC_NPU_HWTS_HWTS_L1_DFX_INTERRUPT_PENDING_l1_log_almost_full_pending_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sqe_done_ns_status : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_INTERRUPT_l2_sqe_done_ns_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_INTERRUPT_l2_sqe_done_ns_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_pre_paused_ns_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_INTERRUPT_l2_pre_paused_ns_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_INTERRUPT_l2_pre_paused_ns_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_post_paused_ns_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_INTERRUPT_l2_post_paused_ns_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_INTERRUPT_l2_post_paused_ns_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_cq_full_ns_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_INTERRUPT_l2_cq_full_ns_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_INTERRUPT_l2_cq_full_ns_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sq_done_ns_status : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_INTERRUPT_l2_sq_done_ns_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_INTERRUPT_l2_sq_done_ns_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_cqe_written_ns_status : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_INTERRUPT_l2_cqe_written_ns_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_INTERRUPT_l2_cqe_written_ns_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_debug_ns_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_INTERRUPT_l2_task_debug_ns_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_INTERRUPT_l2_task_debug_ns_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_debug_paused_ns_status : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_INTERRUPT_l2_debug_paused_ns_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_INTERRUPT_l2_debug_paused_ns_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_error_ns_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_INTERRUPT_l2_task_error_ns_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_INTERRUPT_l2_task_error_ns_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_timeout_ns_status : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_INTERRUPT_l2_task_timeout_ns_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_INTERRUPT_l2_task_timeout_ns_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_trap_ns_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_INTERRUPT_l2_task_trap_ns_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_INTERRUPT_l2_task_trap_ns_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sqe_error_ns_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_INTERRUPT_l2_sqe_error_ns_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_INTERRUPT_l2_sqe_error_ns_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_ffrt_error0_ns_status : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR_NS_INTERRUPT0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR_NS_INTERRUPT0_l2_ffrt_error0_ns_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR_NS_INTERRUPT0_l2_ffrt_error0_ns_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_ffrt_error1_ns_status : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR_NS_INTERRUPT1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR_NS_INTERRUPT1_l2_ffrt_error1_ns_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR_NS_INTERRUPT1_l2_ffrt_error1_ns_status_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_ffrt_drain0_ns_status : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN_NS_INTERRUPT0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN_NS_INTERRUPT0_l2_ffrt_drain0_ns_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN_NS_INTERRUPT0_l2_ffrt_drain0_ns_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_ffrt_drain1_ns_status : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN_NS_INTERRUPT1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN_NS_INTERRUPT1_l2_ffrt_drain1_ns_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN_NS_INTERRUPT1_l2_ffrt_drain1_ns_status_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sw_status_error_ns_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_INTERRUPT_l2_sw_status_error_ns_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_INTERRUPT_l2_sw_status_error_ns_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_log_almost_full_status : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_LOG_ALMOST_FULL_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_LOG_ALMOST_FULL_INTERRUPT_l2_log_almost_full_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_LOG_ALMOST_FULL_INTERRUPT_l2_log_almost_full_status_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_profile_almost_full_status : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_PROFILE_ALMOST_FULL_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_PROFILE_ALMOST_FULL_INTERRUPT_l2_profile_almost_full_status_START (0)
#define SOC_NPU_HWTS_HWTS_L2_PROFILE_ALMOST_FULL_INTERRUPT_l2_profile_almost_full_status_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sqe_done_ns_force : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_FORCE_l2_sqe_done_ns_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_FORCE_l2_sqe_done_ns_force_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_pre_paused_ns_force : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_FORCE_l2_pre_paused_ns_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_FORCE_l2_pre_paused_ns_force_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_post_paused_ns_force : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_FORCE_l2_post_paused_ns_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_FORCE_l2_post_paused_ns_force_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_cq_full_ns_force : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_FORCE_l2_cq_full_ns_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_FORCE_l2_cq_full_ns_force_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sq_done_ns_force : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_FORCE_l2_sq_done_ns_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_FORCE_l2_sq_done_ns_force_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_cqe_written_ns_force : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_FORCE_l2_cqe_written_ns_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_FORCE_l2_cqe_written_ns_force_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_debug_ns_force : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_FORCE_l2_task_debug_ns_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_FORCE_l2_task_debug_ns_force_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_debug_paused_ns_force : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_FORCE_l2_debug_paused_ns_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_FORCE_l2_debug_paused_ns_force_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_error_ns_force : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_FORCE_l2_task_error_ns_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_FORCE_l2_task_error_ns_force_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_timeout_ns_force : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_FORCE_l2_task_timeout_ns_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_FORCE_l2_task_timeout_ns_force_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_trap_ns_force : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_FORCE_l2_task_trap_ns_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_FORCE_l2_task_trap_ns_force_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sqe_error_ns_force : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_FORCE_l2_sqe_error_ns_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_FORCE_l2_sqe_error_ns_force_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_ffrt_error0_ns_force : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR_NS_FORCE0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR_NS_FORCE0_l2_ffrt_error0_ns_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR_NS_FORCE0_l2_ffrt_error0_ns_force_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_ffrt_error1_ns_force : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR_NS_FORCE1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR_NS_FORCE1_l2_ffrt_error1_ns_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR_NS_FORCE1_l2_ffrt_error1_ns_force_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_ffrt_drain0_ns_force : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN_NS_FORCE0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN_NS_FORCE0_l2_ffrt_drain0_ns_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN_NS_FORCE0_l2_ffrt_drain0_ns_force_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_ffrt_drain1_ns_force : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN_NS_FORCE1_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN_NS_FORCE1_l2_ffrt_drain1_ns_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN_NS_FORCE1_l2_ffrt_drain1_ns_force_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sw_status_error_ns_force : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_FORCE_l2_sw_status_error_ns_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_FORCE_l2_sw_status_error_ns_force_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_log_almost_full_force : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DFX_LOG_ALMOST_FULL_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_DFX_LOG_ALMOST_FULL_FORCE_l2_log_almost_full_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_DFX_LOG_ALMOST_FULL_FORCE_l2_log_almost_full_force_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_profile_almost_full_force : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DFX_PROFILE_ALMOST_FULL_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_DFX_PROFILE_ALMOST_FULL_FORCE_l2_profile_almost_full_force_START (0)
#define SOC_NPU_HWTS_HWTS_L2_DFX_PROFILE_ALMOST_FULL_FORCE_l2_profile_almost_full_force_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_MASK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_MASK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_MASK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_MASK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_MASK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_MASK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_MASK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_MASK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_MASK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_MASK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_MASK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_MASK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_MASK0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_log_almost_full_mask : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_LOG_ALMOST_FULL_MASK_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_LOG_ALMOST_FULL_MASK_l2_log_almost_full_mask_START (0)
#define SOC_NPU_HWTS_HWTS_L2_LOG_ALMOST_FULL_MASK_l2_log_almost_full_mask_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_profile_almost_full_mask : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_PROFILE_ALMOST_FULL_MASK_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_PROFILE_ALMOST_FULL_MASK_l2_profile_almost_full_mask_START (0)
#define SOC_NPU_HWTS_HWTS_L2_PROFILE_ALMOST_FULL_MASK_l2_profile_almost_full_mask_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_MASK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_MASK2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_MASK2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_MASK2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_MASK2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_MASK2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_MASK2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_MASK2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_MASK2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_MASK2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_MASK2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_MASK2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_MASK2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_MASK2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_MASK0_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_MASK0_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_MASK0_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_MASK0_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_MASK0_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_MASK0_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_MASK0_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_MASK0_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_MASK0_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_MASK0_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_MASK0_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_MASK0_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_MASK0_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_LOG_ALMOST_FULL_MASK_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_PROFILE_ALMOST_FULL_MASK_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_MASK1_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_MASK2_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_MASK2_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_MASK2_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_MASK2_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_MASK2_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_MASK2_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_MASK2_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_MASK2_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_MASK2_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_MASK2_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_MASK2_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_MASK2_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_MASK2_SET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_MASK0_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_MASK0_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_MASK0_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_MASK0_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_MASK0_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_MASK0_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_MASK0_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_MASK0_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_MASK0_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_MASK0_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_MASK0_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_MASK0_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_MASK0_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_LOG_ALMOST_FULL_MASK_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_PROFILE_ALMOST_FULL_MASK_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_MASK1_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_MASK2_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_MASK2_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_MASK2_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_MASK2_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_MASK2_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_MASK2_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_MASK2_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_MASK2_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_MASK2_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_MASK2_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_MASK2_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_MASK2_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_MASK2_CLR_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sqe_done_ns_pending0 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_INTERRUPT_PENDING0_l2_sqe_done_ns_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_INTERRUPT_PENDING0_l2_sqe_done_ns_pending0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_pre_paused_ns_pending0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_INTERRUPT_PENDING0_l2_pre_paused_ns_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_INTERRUPT_PENDING0_l2_pre_paused_ns_pending0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_post_paused_ns_pending0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_INTERRUPT_PENDING0_l2_post_paused_ns_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_INTERRUPT_PENDING0_l2_post_paused_ns_pending0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_cq_full_ns_pending0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_INTERRUPT_PENDING0_l2_cq_full_ns_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_INTERRUPT_PENDING0_l2_cq_full_ns_pending0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sq_done_ns_pending0 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_INTERRUPT_PENDING0_l2_sq_done_ns_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_INTERRUPT_PENDING0_l2_sq_done_ns_pending0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_cqe_written_ns_pending0 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_INTERRUPT_PENDING0_l2_cqe_written_ns_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_INTERRUPT_PENDING0_l2_cqe_written_ns_pending0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_debug_ns_pending0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_INTERRUPT_PENDING0_l2_task_debug_ns_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_INTERRUPT_PENDING0_l2_task_debug_ns_pending0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_debug_paused_ns_pending0 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_INTERRUPT_PENDING0_l2_debug_paused_ns_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_INTERRUPT_PENDING0_l2_debug_paused_ns_pending0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_error_ns_pending0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_INTERRUPT_PENDING0_l2_task_error_ns_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_INTERRUPT_PENDING0_l2_task_error_ns_pending0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_timeout_ns_pending0 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_INTERRUPT_PENDING0_l2_task_timeout_ns_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_INTERRUPT_PENDING0_l2_task_timeout_ns_pending0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_trap_ns_pending0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_INTERRUPT_PENDING0_l2_task_trap_ns_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_INTERRUPT_PENDING0_l2_task_trap_ns_pending0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sqe_error_ns_pending0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_INTERRUPT_PENDING0_l2_sqe_error_ns_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_INTERRUPT_PENDING0_l2_sqe_error_ns_pending0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_ffrt_error0_ns_pending0 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR0_NS_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR0_NS_INTERRUPT_PENDING0_l2_ffrt_error0_ns_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR0_NS_INTERRUPT_PENDING0_l2_ffrt_error0_ns_pending0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_ffrt_error1_ns_pending0 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR1_NS_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR1_NS_INTERRUPT_PENDING0_l2_ffrt_error1_ns_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR1_NS_INTERRUPT_PENDING0_l2_ffrt_error1_ns_pending0_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_ffrt_drain0_ns_pending0 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN0_NS_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN0_NS_INTERRUPT_PENDING0_l2_ffrt_drain0_ns_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN0_NS_INTERRUPT_PENDING0_l2_ffrt_drain0_ns_pending0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_ffrt_drain1_ns_pending0 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN1_NS_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN1_NS_INTERRUPT_PENDING0_l2_ffrt_drain1_ns_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN1_NS_INTERRUPT_PENDING0_l2_ffrt_drain1_ns_pending0_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sw_status_error_ns_pending0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_INTERRUPT_PENDING0_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_INTERRUPT_PENDING0_l2_sw_status_error_ns_pending0_START (0)
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_INTERRUPT_PENDING0_l2_sw_status_error_ns_pending0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_log_almost_full_pending : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_LOG_ALMOST_FULL_INTERRUPT_PENDING_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_LOG_ALMOST_FULL_INTERRUPT_PENDING_l2_log_almost_full_pending_START (0)
#define SOC_NPU_HWTS_HWTS_L2_LOG_ALMOST_FULL_INTERRUPT_PENDING_l2_log_almost_full_pending_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_profile_almost_full_pending : 4;
        unsigned int reserved : 28;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_PROFILE_ALMOST_FULL_INTERRUPT_PENDING_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_PROFILE_ALMOST_FULL_INTERRUPT_PENDING_l2_profile_almost_full_pending_START (0)
#define SOC_NPU_HWTS_HWTS_L2_PROFILE_ALMOST_FULL_INTERRUPT_PENDING_l2_profile_almost_full_pending_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR0_NS_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 10;
        unsigned int reserved_1: 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR1_NS_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN0_NS_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 10;
        unsigned int reserved_1: 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN1_NS_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0: 8;
        unsigned int reserved_1: 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_INTERRUPT_PENDING1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sqe_done_ns_pending2 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_INTERRUPT_PENDING2_l2_sqe_done_ns_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQE_DONE_NS_INTERRUPT_PENDING2_l2_sqe_done_ns_pending2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_pre_paused_ns_pending2 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_INTERRUPT_PENDING2_l2_pre_paused_ns_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_PRE_PAUSED_NS_INTERRUPT_PENDING2_l2_pre_paused_ns_pending2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_post_paused_ns_pending2 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_INTERRUPT_PENDING2_l2_post_paused_ns_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_POST_PAUSED_NS_INTERRUPT_PENDING2_l2_post_paused_ns_pending2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_cq_full_ns_pending2 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_INTERRUPT_PENDING2_l2_cq_full_ns_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQ_FULL_NS_INTERRUPT_PENDING2_l2_cq_full_ns_pending2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sq_done_ns_pending2 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_INTERRUPT_PENDING2_l2_sq_done_ns_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_SQ_DONE_NS_INTERRUPT_PENDING2_l2_sq_done_ns_pending2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_cqe_written_ns_pending2 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_INTERRUPT_PENDING2_l2_cqe_written_ns_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_NORMAL_CQE_WRITTEN_NS_INTERRUPT_PENDING2_l2_cqe_written_ns_pending2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_debug_ns_pending2 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_INTERRUPT_PENDING2_l2_task_debug_ns_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_DEBUG_NS_INTERRUPT_PENDING2_l2_task_debug_ns_pending2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_debug_paused_ns_pending2 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_INTERRUPT_PENDING2_l2_debug_paused_ns_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_DEBUG_PAUSED_NS_INTERRUPT_PENDING2_l2_debug_paused_ns_pending2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_error_ns_pending2 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_INTERRUPT_PENDING2_l2_task_error_ns_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_ERROR_NS_INTERRUPT_PENDING2_l2_task_error_ns_pending2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_timeout_ns_pending2 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_INTERRUPT_PENDING2_l2_task_timeout_ns_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_TIMEOUT_NS_INTERRUPT_PENDING2_l2_task_timeout_ns_pending2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_task_trap_ns_pending2 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_INTERRUPT_PENDING2_l2_task_trap_ns_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_TASK_TRAP_NS_INTERRUPT_PENDING2_l2_task_trap_ns_pending2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sqe_error_ns_pending2 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_INTERRUPT_PENDING2_l2_sqe_error_ns_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_SQE_ERROR_NS_INTERRUPT_PENDING2_l2_sqe_error_ns_pending2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_ffrt_error0_ns_pending2 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR0_NS_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR0_NS_INTERRUPT_PENDING2_l2_ffrt_error0_ns_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR0_NS_INTERRUPT_PENDING2_l2_ffrt_error0_ns_pending2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_ffrt_error1_ns_pending2 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR1_NS_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR1_NS_INTERRUPT_PENDING2_l2_ffrt_error1_ns_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_FFRT_ERROR1_NS_INTERRUPT_PENDING2_l2_ffrt_error1_ns_pending2_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_ffrt_drain0_ns_pending2 : 32;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN0_NS_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN0_NS_INTERRUPT_PENDING2_l2_ffrt_drain0_ns_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN0_NS_INTERRUPT_PENDING2_l2_ffrt_drain0_ns_pending2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_ffrt_drain1_ns_pending2 : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN1_NS_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN1_NS_INTERRUPT_PENDING2_l2_ffrt_drain1_ns_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_FFRT_DRAIN1_NS_INTERRUPT_PENDING2_l2_ffrt_drain1_ns_pending2_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int l2_sw_status_error_ns_pending2 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_INTERRUPT_PENDING2_UNION;
#endif
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_INTERRUPT_PENDING2_l2_sw_status_error_ns_pending2_START (0)
#define SOC_NPU_HWTS_HWTS_L2_SW_STATUS_ERROR_NS_INTERRUPT_PENDING2_l2_sw_status_error_ns_pending2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_arcache_sqe : 4;
        unsigned int tiny_arsnoop_sqe : 1;
        unsigned int reserved_0 : 3;
        unsigned int tiny_awcache_cqe : 4;
        unsigned int tiny_awsnoop_cqe : 1;
        unsigned int reserved_1 : 3;
        unsigned int tiny_arcache_swapbuf : 4;
        unsigned int tiny_arsnoop_swapbuf : 1;
        unsigned int reserved_2 : 3;
        unsigned int tiny_awcache_log : 4;
        unsigned int tiny_awsnoop_log : 1;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_NPU_HWTS_TINY_AXCACHE_SETTING0_UNION;
#endif
#define SOC_NPU_HWTS_TINY_AXCACHE_SETTING0_tiny_arcache_sqe_START (0)
#define SOC_NPU_HWTS_TINY_AXCACHE_SETTING0_tiny_arcache_sqe_END (3)
#define SOC_NPU_HWTS_TINY_AXCACHE_SETTING0_tiny_arsnoop_sqe_START (4)
#define SOC_NPU_HWTS_TINY_AXCACHE_SETTING0_tiny_arsnoop_sqe_END (4)
#define SOC_NPU_HWTS_TINY_AXCACHE_SETTING0_tiny_awcache_cqe_START (8)
#define SOC_NPU_HWTS_TINY_AXCACHE_SETTING0_tiny_awcache_cqe_END (11)
#define SOC_NPU_HWTS_TINY_AXCACHE_SETTING0_tiny_awsnoop_cqe_START (12)
#define SOC_NPU_HWTS_TINY_AXCACHE_SETTING0_tiny_awsnoop_cqe_END (12)
#define SOC_NPU_HWTS_TINY_AXCACHE_SETTING0_tiny_arcache_swapbuf_START (16)
#define SOC_NPU_HWTS_TINY_AXCACHE_SETTING0_tiny_arcache_swapbuf_END (19)
#define SOC_NPU_HWTS_TINY_AXCACHE_SETTING0_tiny_arsnoop_swapbuf_START (20)
#define SOC_NPU_HWTS_TINY_AXCACHE_SETTING0_tiny_arsnoop_swapbuf_END (20)
#define SOC_NPU_HWTS_TINY_AXCACHE_SETTING0_tiny_awcache_log_START (24)
#define SOC_NPU_HWTS_TINY_AXCACHE_SETTING0_tiny_awcache_log_END (27)
#define SOC_NPU_HWTS_TINY_AXCACHE_SETTING0_tiny_awsnoop_log_START (28)
#define SOC_NPU_HWTS_TINY_AXCACHE_SETTING0_tiny_awsnoop_log_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_awcache_swapbuf : 4;
        unsigned int tiny_awsnoop_swapbuf : 1;
        unsigned int reserved_0 : 3;
        unsigned int tiny_awcache_prof : 4;
        unsigned int tiny_awsnoop_prof : 1;
        unsigned int reserved_1 : 19;
    } reg;
} SOC_NPU_HWTS_TINY_AXCACHE_SETTING1_UNION;
#endif
#define SOC_NPU_HWTS_TINY_AXCACHE_SETTING1_tiny_awcache_swapbuf_START (0)
#define SOC_NPU_HWTS_TINY_AXCACHE_SETTING1_tiny_awcache_swapbuf_END (3)
#define SOC_NPU_HWTS_TINY_AXCACHE_SETTING1_tiny_awsnoop_swapbuf_START (4)
#define SOC_NPU_HWTS_TINY_AXCACHE_SETTING1_tiny_awsnoop_swapbuf_END (4)
#define SOC_NPU_HWTS_TINY_AXCACHE_SETTING1_tiny_awcache_prof_START (8)
#define SOC_NPU_HWTS_TINY_AXCACHE_SETTING1_tiny_awcache_prof_END (11)
#define SOC_NPU_HWTS_TINY_AXCACHE_SETTING1_tiny_awsnoop_prof_START (12)
#define SOC_NPU_HWTS_TINY_AXCACHE_SETTING1_tiny_awsnoop_prof_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_sq_swap_buf_base_addr_l : 32;
    } reg;
} SOC_NPU_HWTS_TINY_SQ_SWAP_BUF_BASE_ADDR_CFG0_UNION;
#endif
#define SOC_NPU_HWTS_TINY_SQ_SWAP_BUF_BASE_ADDR_CFG0_tiny_sq_swap_buf_base_addr_l_START (0)
#define SOC_NPU_HWTS_TINY_SQ_SWAP_BUF_BASE_ADDR_CFG0_tiny_sq_swap_buf_base_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_sq_swap_buf_base_addr_h : 16;
        unsigned int tiny_sq_swap_buf_shift : 6;
        unsigned int reserved : 9;
        unsigned int tiny_sq_swap_buf_is_virtual : 1;
    } reg;
} SOC_NPU_HWTS_TINY_SQ_SWAP_BUF_BASE_ADDR_CFG1_UNION;
#endif
#define SOC_NPU_HWTS_TINY_SQ_SWAP_BUF_BASE_ADDR_CFG1_tiny_sq_swap_buf_base_addr_h_START (0)
#define SOC_NPU_HWTS_TINY_SQ_SWAP_BUF_BASE_ADDR_CFG1_tiny_sq_swap_buf_base_addr_h_END (15)
#define SOC_NPU_HWTS_TINY_SQ_SWAP_BUF_BASE_ADDR_CFG1_tiny_sq_swap_buf_shift_START (16)
#define SOC_NPU_HWTS_TINY_SQ_SWAP_BUF_BASE_ADDR_CFG1_tiny_sq_swap_buf_shift_END (21)
#define SOC_NPU_HWTS_TINY_SQ_SWAP_BUF_BASE_ADDR_CFG1_tiny_sq_swap_buf_is_virtual_START (31)
#define SOC_NPU_HWTS_TINY_SQ_SWAP_BUF_BASE_ADDR_CFG1_tiny_sq_swap_buf_is_virtual_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_profile_buf_length : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPU_HWTS_TINY_DFX_PROFILE_CTRL0_UNION;
#endif
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_CTRL0_tiny_profile_buf_length_START (0)
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_CTRL0_tiny_profile_buf_length_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_profile_af_threshold : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPU_HWTS_TINY_DFX_PROFILE_CTRL1_UNION;
#endif
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_CTRL1_tiny_profile_af_threshold_START (0)
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_CTRL1_tiny_profile_af_threshold_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_profile_base_addr_l : 32;
    } reg;
} SOC_NPU_HWTS_TINY_DFX_PROFILE_BASE_ADDR0_UNION;
#endif
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_BASE_ADDR0_tiny_profile_base_addr_l_START (0)
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_BASE_ADDR0_tiny_profile_base_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_profile_base_addr_h : 16;
        unsigned int reserved : 15;
        unsigned int tiny_profile_base_addr_is_virtual : 1;
    } reg;
} SOC_NPU_HWTS_TINY_DFX_PROFILE_BASE_ADDR1_UNION;
#endif
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_BASE_ADDR1_tiny_profile_base_addr_h_START (0)
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_BASE_ADDR1_tiny_profile_base_addr_h_END (15)
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_BASE_ADDR1_tiny_profile_base_addr_is_virtual_START (31)
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_BASE_ADDR1_tiny_profile_base_addr_is_virtual_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_profile_wptr_initial : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_HWTS_TINY_DFX_PROFILE_WPTR_INITIAL_UNION;
#endif
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_WPTR_INITIAL_tiny_profile_wptr_initial_START (0)
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_WPTR_INITIAL_tiny_profile_wptr_initial_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_profile_wptr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPU_HWTS_TINY_DFX_PROFILE_WPTR_UNION;
#endif
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_WPTR_tiny_profile_wptr_START (0)
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_WPTR_tiny_profile_wptr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_profile_rptr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPU_HWTS_TINY_DFX_PROFILE_RPTR_UNION;
#endif
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_RPTR_tiny_profile_rptr_START (0)
#define SOC_NPU_HWTS_TINY_DFX_PROFILE_RPTR_tiny_profile_rptr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_log_buf_length : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPU_HWTS_TINY_DFX_LOG_CTRL0_UNION;
#endif
#define SOC_NPU_HWTS_TINY_DFX_LOG_CTRL0_tiny_log_buf_length_START (0)
#define SOC_NPU_HWTS_TINY_DFX_LOG_CTRL0_tiny_log_buf_length_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_log_af_threshold : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPU_HWTS_TINY_DFX_LOG_CTRL1_UNION;
#endif
#define SOC_NPU_HWTS_TINY_DFX_LOG_CTRL1_tiny_log_af_threshold_START (0)
#define SOC_NPU_HWTS_TINY_DFX_LOG_CTRL1_tiny_log_af_threshold_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_log_base_addr_l : 32;
    } reg;
} SOC_NPU_HWTS_TINY_DFX_LOG_BASE_ADDR0_UNION;
#endif
#define SOC_NPU_HWTS_TINY_DFX_LOG_BASE_ADDR0_tiny_log_base_addr_l_START (0)
#define SOC_NPU_HWTS_TINY_DFX_LOG_BASE_ADDR0_tiny_log_base_addr_l_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_log_base_addr_h : 16;
        unsigned int reserved : 15;
        unsigned int tiny_log_base_addr_is_virtual : 1;
    } reg;
} SOC_NPU_HWTS_TINY_DFX_LOG_BASE_ADDR1_UNION;
#endif
#define SOC_NPU_HWTS_TINY_DFX_LOG_BASE_ADDR1_tiny_log_base_addr_h_START (0)
#define SOC_NPU_HWTS_TINY_DFX_LOG_BASE_ADDR1_tiny_log_base_addr_h_END (15)
#define SOC_NPU_HWTS_TINY_DFX_LOG_BASE_ADDR1_tiny_log_base_addr_is_virtual_START (31)
#define SOC_NPU_HWTS_TINY_DFX_LOG_BASE_ADDR1_tiny_log_base_addr_is_virtual_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_log_wptr_initial : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_NPU_HWTS_TINY_DFX_LOG_WPTR_INITIAL_UNION;
#endif
#define SOC_NPU_HWTS_TINY_DFX_LOG_WPTR_INITIAL_tiny_log_wptr_initial_START (0)
#define SOC_NPU_HWTS_TINY_DFX_LOG_WPTR_INITIAL_tiny_log_wptr_initial_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_log_wptr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPU_HWTS_TINY_DFX_LOG_WPTR_UNION;
#endif
#define SOC_NPU_HWTS_TINY_DFX_LOG_WPTR_tiny_log_wptr_START (0)
#define SOC_NPU_HWTS_TINY_DFX_LOG_WPTR_tiny_log_wptr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_log_rptr : 20;
        unsigned int reserved : 12;
    } reg;
} SOC_NPU_HWTS_TINY_DFX_LOG_RPTR_UNION;
#endif
#define SOC_NPU_HWTS_TINY_DFX_LOG_RPTR_tiny_log_rptr_START (0)
#define SOC_NPU_HWTS_TINY_DFX_LOG_RPTR_tiny_log_rptr_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_arprot_sqe : 3;
        unsigned int reserved_0 : 1;
        unsigned int tiny_awprot_cqe : 3;
        unsigned int reserved_1 : 1;
        unsigned int tiny_arprot_swapbuf : 3;
        unsigned int reserved_2 : 1;
        unsigned int tiny_awprot_log : 3;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 3;
        unsigned int reserved_5 : 1;
        unsigned int tiny_awprot_prof : 3;
        unsigned int reserved_6 : 9;
    } reg;
} SOC_NPU_HWTS_TINY_AXPROT_SETTING0_UNION;
#endif
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING0_tiny_arprot_sqe_START (0)
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING0_tiny_arprot_sqe_END (2)
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING0_tiny_awprot_cqe_START (4)
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING0_tiny_awprot_cqe_END (6)
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING0_tiny_arprot_swapbuf_START (8)
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING0_tiny_arprot_swapbuf_END (10)
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING0_tiny_awprot_log_START (12)
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING0_tiny_awprot_log_END (14)
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING0_tiny_awprot_prof_START (20)
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING0_tiny_awprot_prof_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_awprot_aic : 3;
        unsigned int reserved_0 : 1;
        unsigned int tiny_arprot_aic : 3;
        unsigned int reserved_1 : 1;
        unsigned int tiny_awprot_aiv : 3;
        unsigned int reserved_2 : 1;
        unsigned int tiny_arprot_aiv : 3;
        unsigned int reserved_3 : 1;
        unsigned int tiny_awprot_write_value : 3;
        unsigned int reserved_4 : 1;
        unsigned int tiny_awprot_swapbuf : 3;
        unsigned int reserved_5 : 9;
    } reg;
} SOC_NPU_HWTS_TINY_AXPROT_SETTING1_UNION;
#endif
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING1_tiny_awprot_aic_START (0)
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING1_tiny_awprot_aic_END (2)
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING1_tiny_arprot_aic_START (4)
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING1_tiny_arprot_aic_END (6)
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING1_tiny_awprot_aiv_START (8)
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING1_tiny_awprot_aiv_END (10)
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING1_tiny_arprot_aiv_START (12)
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING1_tiny_arprot_aiv_END (14)
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING1_tiny_awprot_write_value_START (16)
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING1_tiny_awprot_write_value_END (18)
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING1_tiny_awprot_swapbuf_START (20)
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING1_tiny_awprot_swapbuf_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_awprot_eff_aic : 3;
        unsigned int reserved_0 : 1;
        unsigned int tiny_arprot_eff_aic : 3;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 24;
    } reg;
} SOC_NPU_HWTS_TINY_AXPROT_SETTING2_UNION;
#endif
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING2_tiny_awprot_eff_aic_START (0)
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING2_tiny_awprot_eff_aic_END (2)
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING2_tiny_arprot_eff_aic_START (4)
#define SOC_NPU_HWTS_TINY_AXPROT_SETTING2_tiny_arprot_eff_aic_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l1_sqe_done_status : 1;
        unsigned int tiny_l1_pre_paused_status : 1;
        unsigned int tiny_l1_post_paused_status : 1;
        unsigned int tiny_l1_cq_full_status : 1;
        unsigned int tiny_l1_task_paused_status : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int tiny_l1_sq_done_status : 1;
        unsigned int tiny_l1_cqe_written_status : 1;
        unsigned int reserved_3 : 22;
    } reg;
} SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_tiny_l1_sqe_done_status_START (0)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_tiny_l1_sqe_done_status_END (0)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_tiny_l1_pre_paused_status_START (1)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_tiny_l1_pre_paused_status_END (1)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_tiny_l1_post_paused_status_START (2)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_tiny_l1_post_paused_status_END (2)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_tiny_l1_cq_full_status_START (3)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_tiny_l1_cq_full_status_END (3)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_tiny_l1_task_paused_status_START (4)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_tiny_l1_task_paused_status_END (4)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_tiny_l1_sq_done_status_START (8)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_tiny_l1_sq_done_status_END (8)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_tiny_l1_cqe_written_status_START (9)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_tiny_l1_cqe_written_status_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l1_task_debug_status : 1;
        unsigned int tiny_l1_debug_paused_status : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_HWTS_TINY_L1_DEBUG_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L1_DEBUG_INTERRUPT_tiny_l1_task_debug_status_START (0)
#define SOC_NPU_HWTS_TINY_L1_DEBUG_INTERRUPT_tiny_l1_task_debug_status_END (0)
#define SOC_NPU_HWTS_TINY_L1_DEBUG_INTERRUPT_tiny_l1_debug_paused_status_START (1)
#define SOC_NPU_HWTS_TINY_L1_DEBUG_INTERRUPT_tiny_l1_debug_paused_status_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l1_task_error_status : 1;
        unsigned int tiny_l1_task_timeout_status : 1;
        unsigned int tiny_l1_task_trap_status : 1;
        unsigned int tiny_l1_sqe_error_status : 1;
        unsigned int tiny_l1_sw_status_error_status : 1;
        unsigned int tiny_l1_bus_error_status : 1;
        unsigned int tiny_l1_ecc_error_status : 1;
        unsigned int tiny_l1_pool_conflict_status : 1;
        unsigned int tiny_l1_hts_error_status : 1;
        unsigned int tiny_l1_pu_pd_timeout_status : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_tiny_l1_task_error_status_START (0)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_tiny_l1_task_error_status_END (0)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_tiny_l1_task_timeout_status_START (1)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_tiny_l1_task_timeout_status_END (1)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_tiny_l1_task_trap_status_START (2)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_tiny_l1_task_trap_status_END (2)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_tiny_l1_sqe_error_status_START (3)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_tiny_l1_sqe_error_status_END (3)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_tiny_l1_sw_status_error_status_START (4)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_tiny_l1_sw_status_error_status_END (4)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_tiny_l1_bus_error_status_START (5)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_tiny_l1_bus_error_status_END (5)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_tiny_l1_ecc_error_status_START (6)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_tiny_l1_ecc_error_status_END (6)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_tiny_l1_pool_conflict_status_START (7)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_tiny_l1_pool_conflict_status_END (7)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_tiny_l1_hts_error_status_START (8)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_tiny_l1_hts_error_status_END (8)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_tiny_l1_pu_pd_timeout_status_START (9)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_tiny_l1_pu_pd_timeout_status_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l1_profile_almost_full : 1;
        unsigned int tiny_l1_trace_almost_full : 1;
        unsigned int tiny_l1_log_almost_full : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_NPU_HWTS_TINY_L1_DFX_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L1_DFX_INTERRUPT_tiny_l1_profile_almost_full_START (0)
#define SOC_NPU_HWTS_TINY_L1_DFX_INTERRUPT_tiny_l1_profile_almost_full_END (0)
#define SOC_NPU_HWTS_TINY_L1_DFX_INTERRUPT_tiny_l1_trace_almost_full_START (1)
#define SOC_NPU_HWTS_TINY_L1_DFX_INTERRUPT_tiny_l1_trace_almost_full_END (1)
#define SOC_NPU_HWTS_TINY_L1_DFX_INTERRUPT_tiny_l1_log_almost_full_START (2)
#define SOC_NPU_HWTS_TINY_L1_DFX_INTERRUPT_tiny_l1_log_almost_full_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l1_profile_almost_full_force : 1;
        unsigned int tiny_l1_trace_almost_full_force : 1;
        unsigned int tiny_l1_log_almost_full_force : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_NPU_HWTS_TINY_L1_DFX_INTERRUPT_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L1_DFX_INTERRUPT_FORCE_tiny_l1_profile_almost_full_force_START (0)
#define SOC_NPU_HWTS_TINY_L1_DFX_INTERRUPT_FORCE_tiny_l1_profile_almost_full_force_END (0)
#define SOC_NPU_HWTS_TINY_L1_DFX_INTERRUPT_FORCE_tiny_l1_trace_almost_full_force_START (1)
#define SOC_NPU_HWTS_TINY_L1_DFX_INTERRUPT_FORCE_tiny_l1_trace_almost_full_force_END (1)
#define SOC_NPU_HWTS_TINY_L1_DFX_INTERRUPT_FORCE_tiny_l1_log_almost_full_force_START (2)
#define SOC_NPU_HWTS_TINY_L1_DFX_INTERRUPT_FORCE_tiny_l1_log_almost_full_force_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 5;
        unsigned int tiny_l1_bus_error_force : 1;
        unsigned int tiny_l1_ecc_error_force : 1;
        unsigned int tiny_l1_pool_conflict_force : 1;
        unsigned int tiny_l1_hts_error_force : 1;
        unsigned int tiny_l1_pu_pd_timeout_force : 1;
        unsigned int reserved_1 : 22;
    } reg;
} SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_FORCE_tiny_l1_bus_error_force_START (5)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_FORCE_tiny_l1_bus_error_force_END (5)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_FORCE_tiny_l1_ecc_error_force_START (6)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_FORCE_tiny_l1_ecc_error_force_END (6)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_FORCE_tiny_l1_pool_conflict_force_START (7)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_FORCE_tiny_l1_pool_conflict_force_END (7)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_FORCE_tiny_l1_hts_error_force_START (8)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_FORCE_tiny_l1_hts_error_force_END (8)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_FORCE_tiny_l1_pu_pd_timeout_force_START (9)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_FORCE_tiny_l1_pu_pd_timeout_force_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l1_sqe_done_mask : 1;
        unsigned int tiny_l1_pre_paused_mask : 1;
        unsigned int tiny_l1_post_paused_mask : 1;
        unsigned int tiny_l1_cq_full_mask : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int tiny_l1_sq_done_mask : 1;
        unsigned int tiny_l1_cqe_written_mask : 1;
        unsigned int reserved_4 : 22;
    } reg;
} SOC_NPU_HWTS_TINY_L1_NORMAL_MASK_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L1_NORMAL_MASK_tiny_l1_sqe_done_mask_START (0)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_MASK_tiny_l1_sqe_done_mask_END (0)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_MASK_tiny_l1_pre_paused_mask_START (1)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_MASK_tiny_l1_pre_paused_mask_END (1)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_MASK_tiny_l1_post_paused_mask_START (2)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_MASK_tiny_l1_post_paused_mask_END (2)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_MASK_tiny_l1_cq_full_mask_START (3)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_MASK_tiny_l1_cq_full_mask_END (3)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_MASK_tiny_l1_sq_done_mask_START (8)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_MASK_tiny_l1_sq_done_mask_END (8)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_MASK_tiny_l1_cqe_written_mask_START (9)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_MASK_tiny_l1_cqe_written_mask_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l1_task_debug_mask : 1;
        unsigned int tiny_l1_debug_paused_mask : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_HWTS_TINY_L1_DEBUG_MASK_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L1_DEBUG_MASK_tiny_l1_task_debug_mask_START (0)
#define SOC_NPU_HWTS_TINY_L1_DEBUG_MASK_tiny_l1_task_debug_mask_END (0)
#define SOC_NPU_HWTS_TINY_L1_DEBUG_MASK_tiny_l1_debug_paused_mask_START (1)
#define SOC_NPU_HWTS_TINY_L1_DEBUG_MASK_tiny_l1_debug_paused_mask_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l1_task_error_mask : 1;
        unsigned int tiny_l1_task_timeout_mask : 1;
        unsigned int tiny_l1_task_trap_mask : 1;
        unsigned int tiny_l1_sqe_error_mask : 1;
        unsigned int tiny_l1_sw_status_error_mask : 1;
        unsigned int tiny_l1_bus_error_mask : 1;
        unsigned int tiny_l1_ecc_error_mask : 1;
        unsigned int tiny_l1_pool_conflict_mask : 1;
        unsigned int tiny_l1_hts_error_mask : 1;
        unsigned int tiny_l1_pu_pd_timeout_mask : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_HWTS_TINY_L1_ERROR_MASK_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L1_ERROR_MASK_tiny_l1_task_error_mask_START (0)
#define SOC_NPU_HWTS_TINY_L1_ERROR_MASK_tiny_l1_task_error_mask_END (0)
#define SOC_NPU_HWTS_TINY_L1_ERROR_MASK_tiny_l1_task_timeout_mask_START (1)
#define SOC_NPU_HWTS_TINY_L1_ERROR_MASK_tiny_l1_task_timeout_mask_END (1)
#define SOC_NPU_HWTS_TINY_L1_ERROR_MASK_tiny_l1_task_trap_mask_START (2)
#define SOC_NPU_HWTS_TINY_L1_ERROR_MASK_tiny_l1_task_trap_mask_END (2)
#define SOC_NPU_HWTS_TINY_L1_ERROR_MASK_tiny_l1_sqe_error_mask_START (3)
#define SOC_NPU_HWTS_TINY_L1_ERROR_MASK_tiny_l1_sqe_error_mask_END (3)
#define SOC_NPU_HWTS_TINY_L1_ERROR_MASK_tiny_l1_sw_status_error_mask_START (4)
#define SOC_NPU_HWTS_TINY_L1_ERROR_MASK_tiny_l1_sw_status_error_mask_END (4)
#define SOC_NPU_HWTS_TINY_L1_ERROR_MASK_tiny_l1_bus_error_mask_START (5)
#define SOC_NPU_HWTS_TINY_L1_ERROR_MASK_tiny_l1_bus_error_mask_END (5)
#define SOC_NPU_HWTS_TINY_L1_ERROR_MASK_tiny_l1_ecc_error_mask_START (6)
#define SOC_NPU_HWTS_TINY_L1_ERROR_MASK_tiny_l1_ecc_error_mask_END (6)
#define SOC_NPU_HWTS_TINY_L1_ERROR_MASK_tiny_l1_pool_conflict_mask_START (7)
#define SOC_NPU_HWTS_TINY_L1_ERROR_MASK_tiny_l1_pool_conflict_mask_END (7)
#define SOC_NPU_HWTS_TINY_L1_ERROR_MASK_tiny_l1_hts_error_mask_START (8)
#define SOC_NPU_HWTS_TINY_L1_ERROR_MASK_tiny_l1_hts_error_mask_END (8)
#define SOC_NPU_HWTS_TINY_L1_ERROR_MASK_tiny_l1_pu_pd_timeout_mask_START (9)
#define SOC_NPU_HWTS_TINY_L1_ERROR_MASK_tiny_l1_pu_pd_timeout_mask_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l1_profile_almost_full_mask : 1;
        unsigned int tiny_l1_pc_trace_almost_full_mask : 1;
        unsigned int tiny_l1_log_almost_full_mask : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_NPU_HWTS_TINY_L1_DFX_MASK_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L1_DFX_MASK_tiny_l1_profile_almost_full_mask_START (0)
#define SOC_NPU_HWTS_TINY_L1_DFX_MASK_tiny_l1_profile_almost_full_mask_END (0)
#define SOC_NPU_HWTS_TINY_L1_DFX_MASK_tiny_l1_pc_trace_almost_full_mask_START (1)
#define SOC_NPU_HWTS_TINY_L1_DFX_MASK_tiny_l1_pc_trace_almost_full_mask_END (1)
#define SOC_NPU_HWTS_TINY_L1_DFX_MASK_tiny_l1_log_almost_full_mask_START (2)
#define SOC_NPU_HWTS_TINY_L1_DFX_MASK_tiny_l1_log_almost_full_mask_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l1_sqe_done_pending : 1;
        unsigned int tiny_l1_pre_paused_pending : 1;
        unsigned int tiny_l1_post_paused_pending : 1;
        unsigned int tiny_l1_cq_full_pending : 1;
        unsigned int tiny_l1_task_paused_pending : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int tiny_l1_sq_done_pending : 1;
        unsigned int tiny_l1_cqe_written_pending : 1;
        unsigned int reserved_3 : 22;
    } reg;
} SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_PENDING_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_PENDING_tiny_l1_sqe_done_pending_START (0)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_PENDING_tiny_l1_sqe_done_pending_END (0)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_PENDING_tiny_l1_pre_paused_pending_START (1)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_PENDING_tiny_l1_pre_paused_pending_END (1)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_PENDING_tiny_l1_post_paused_pending_START (2)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_PENDING_tiny_l1_post_paused_pending_END (2)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_PENDING_tiny_l1_cq_full_pending_START (3)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_PENDING_tiny_l1_cq_full_pending_END (3)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_PENDING_tiny_l1_task_paused_pending_START (4)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_PENDING_tiny_l1_task_paused_pending_END (4)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_PENDING_tiny_l1_sq_done_pending_START (8)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_PENDING_tiny_l1_sq_done_pending_END (8)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_PENDING_tiny_l1_cqe_written_pending_START (9)
#define SOC_NPU_HWTS_TINY_L1_NORMAL_INTERRUPT_PENDING_tiny_l1_cqe_written_pending_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l1_task_debug_pending : 1;
        unsigned int tiny_l1_debug_paused_pending : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_NPU_HWTS_TINY_L1_DEBUG_INTERRUPT_PENDING_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L1_DEBUG_INTERRUPT_PENDING_tiny_l1_task_debug_pending_START (0)
#define SOC_NPU_HWTS_TINY_L1_DEBUG_INTERRUPT_PENDING_tiny_l1_task_debug_pending_END (0)
#define SOC_NPU_HWTS_TINY_L1_DEBUG_INTERRUPT_PENDING_tiny_l1_debug_paused_pending_START (1)
#define SOC_NPU_HWTS_TINY_L1_DEBUG_INTERRUPT_PENDING_tiny_l1_debug_paused_pending_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l1_task_error_pending : 1;
        unsigned int tiny_l1_task_timeout_pending : 1;
        unsigned int tiny_l1_task_trap_pending : 1;
        unsigned int tiny_l1_sqe_error_pending : 1;
        unsigned int tiny_l1_sw_status_error_pending : 1;
        unsigned int tiny_l1_bus_error_pending : 1;
        unsigned int tiny_l1_ecc_error_pending : 1;
        unsigned int tiny_l1_pool_conflict_pending : 1;
        unsigned int tiny_l1_hts_error_pending : 1;
        unsigned int tiny_l1_pu_pd_timeout_pending : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_PENDING_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_PENDING_tiny_l1_task_error_pending_START (0)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_PENDING_tiny_l1_task_error_pending_END (0)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_PENDING_tiny_l1_task_timeout_pending_START (1)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_PENDING_tiny_l1_task_timeout_pending_END (1)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_PENDING_tiny_l1_task_trap_pending_START (2)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_PENDING_tiny_l1_task_trap_pending_END (2)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_PENDING_tiny_l1_sqe_error_pending_START (3)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_PENDING_tiny_l1_sqe_error_pending_END (3)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_PENDING_tiny_l1_sw_status_error_pending_START (4)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_PENDING_tiny_l1_sw_status_error_pending_END (4)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_PENDING_tiny_l1_bus_error_pending_START (5)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_PENDING_tiny_l1_bus_error_pending_END (5)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_PENDING_tiny_l1_ecc_error_pending_START (6)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_PENDING_tiny_l1_ecc_error_pending_END (6)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_PENDING_tiny_l1_pool_conflict_pending_START (7)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_PENDING_tiny_l1_pool_conflict_pending_END (7)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_PENDING_tiny_l1_hts_error_pending_START (8)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_PENDING_tiny_l1_hts_error_pending_END (8)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_PENDING_tiny_l1_pu_pd_timeout_pending_START (9)
#define SOC_NPU_HWTS_TINY_L1_ERROR_INTERRUPT_PENDING_tiny_l1_pu_pd_timeout_pending_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l1_profile_almost_full_pending : 1;
        unsigned int tiny_l1_pc_trace_almost_full_pending : 1;
        unsigned int tiny_l1_log_almost_full_pending : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_NPU_HWTS_TINY_L1_DFX_INTERRUPT_PENDING_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L1_DFX_INTERRUPT_PENDING_tiny_l1_profile_almost_full_pending_START (0)
#define SOC_NPU_HWTS_TINY_L1_DFX_INTERRUPT_PENDING_tiny_l1_profile_almost_full_pending_END (0)
#define SOC_NPU_HWTS_TINY_L1_DFX_INTERRUPT_PENDING_tiny_l1_pc_trace_almost_full_pending_START (1)
#define SOC_NPU_HWTS_TINY_L1_DFX_INTERRUPT_PENDING_tiny_l1_pc_trace_almost_full_pending_END (1)
#define SOC_NPU_HWTS_TINY_L1_DFX_INTERRUPT_PENDING_tiny_l1_log_almost_full_pending_START (2)
#define SOC_NPU_HWTS_TINY_L1_DFX_INTERRUPT_PENDING_tiny_l1_log_almost_full_pending_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_sqe_done_status : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_NORMAL_SQE_DONE_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQE_DONE_INTERRUPT_tiny_l2_sqe_done_status_START (0)
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQE_DONE_INTERRUPT_tiny_l2_sqe_done_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_pre_paused_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_TINY_L2_NORMAL_PRE_PAUSED_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_NORMAL_PRE_PAUSED_INTERRUPT_tiny_l2_pre_paused_status_START (0)
#define SOC_NPU_HWTS_TINY_L2_NORMAL_PRE_PAUSED_INTERRUPT_tiny_l2_pre_paused_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_post_paused_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_TINY_L2_NORMAL_POST_PAUSED_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_NORMAL_POST_PAUSED_INTERRUPT_tiny_l2_post_paused_status_START (0)
#define SOC_NPU_HWTS_TINY_L2_NORMAL_POST_PAUSED_INTERRUPT_tiny_l2_post_paused_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_cq_full_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_TINY_L2_NORMAL_CQ_FULL_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQ_FULL_INTERRUPT_tiny_l2_cq_full_status_START (0)
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQ_FULL_INTERRUPT_tiny_l2_cq_full_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_task_paused_status : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_NORMAL_TASK_PAUSED_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_NORMAL_TASK_PAUSED_INTERRUPT_tiny_l2_task_paused_status_START (0)
#define SOC_NPU_HWTS_TINY_L2_NORMAL_TASK_PAUSED_INTERRUPT_tiny_l2_task_paused_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_sq_done_status : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_NORMAL_SQ_DONE_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQ_DONE_INTERRUPT_tiny_l2_sq_done_status_START (0)
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQ_DONE_INTERRUPT_tiny_l2_sq_done_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_cqe_written_status : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_NORMAL_CQE_WRITTEN_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQE_WRITTEN_INTERRUPT_tiny_l2_cqe_written_status_START (0)
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQE_WRITTEN_INTERRUPT_tiny_l2_cqe_written_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_task_debug_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_TINY_L2_TASK_DEBUG_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_TASK_DEBUG_INTERRUPT_tiny_l2_task_debug_status_START (0)
#define SOC_NPU_HWTS_TINY_L2_TASK_DEBUG_INTERRUPT_tiny_l2_task_debug_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_debug_paused_status : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_DEBUG_PAUSED_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_DEBUG_PAUSED_INTERRUPT_tiny_l2_debug_paused_status_START (0)
#define SOC_NPU_HWTS_TINY_L2_DEBUG_PAUSED_INTERRUPT_tiny_l2_debug_paused_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_task_error_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_TINY_L2_TASK_ERROR_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_TASK_ERROR_INTERRUPT_tiny_l2_task_error_status_START (0)
#define SOC_NPU_HWTS_TINY_L2_TASK_ERROR_INTERRUPT_tiny_l2_task_error_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_task_timeout_status : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_TASK_TIMEOUT_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_TASK_TIMEOUT_INTERRUPT_tiny_l2_task_timeout_status_START (0)
#define SOC_NPU_HWTS_TINY_L2_TASK_TIMEOUT_INTERRUPT_tiny_l2_task_timeout_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_task_trap_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_TINY_L2_TASK_TRAP_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_TASK_TRAP_INTERRUPT_tiny_l2_task_trap_status_START (0)
#define SOC_NPU_HWTS_TINY_L2_TASK_TRAP_INTERRUPT_tiny_l2_task_trap_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_sqe_error_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_TINY_L2_SQE_ERROR_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_SQE_ERROR_INTERRUPT_tiny_l2_sqe_error_status_START (0)
#define SOC_NPU_HWTS_TINY_L2_SQE_ERROR_INTERRUPT_tiny_l2_sqe_error_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_sw_status_error_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_TINY_L2_SW_STATUS_ERROR_INTERRUPT_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_SW_STATUS_ERROR_INTERRUPT_tiny_l2_sw_status_error_status_START (0)
#define SOC_NPU_HWTS_TINY_L2_SW_STATUS_ERROR_INTERRUPT_tiny_l2_sw_status_error_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_sqe_done_force : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_NORMAL_SQE_DONE_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQE_DONE_FORCE_tiny_l2_sqe_done_force_START (0)
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQE_DONE_FORCE_tiny_l2_sqe_done_force_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_pre_paused_force : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_TINY_L2_NORMAL_PRE_PAUSED_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_NORMAL_PRE_PAUSED_FORCE_tiny_l2_pre_paused_force_START (0)
#define SOC_NPU_HWTS_TINY_L2_NORMAL_PRE_PAUSED_FORCE_tiny_l2_pre_paused_force_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_post_paused_force : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_TINY_L2_NORMAL_POST_PAUSED_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_NORMAL_POST_PAUSED_FORCE_tiny_l2_post_paused_force_START (0)
#define SOC_NPU_HWTS_TINY_L2_NORMAL_POST_PAUSED_FORCE_tiny_l2_post_paused_force_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_cq_full_force : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_TINY_L2_NORMAL_CQ_FULL_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQ_FULL_FORCE_tiny_l2_cq_full_force_START (0)
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQ_FULL_FORCE_tiny_l2_cq_full_force_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_task_paused_force : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_NORMAL_TASK_PAUSED_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_NORMAL_TASK_PAUSED_FORCE_tiny_l2_task_paused_force_START (0)
#define SOC_NPU_HWTS_TINY_L2_NORMAL_TASK_PAUSED_FORCE_tiny_l2_task_paused_force_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_sq_done_force : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_NORMAL_SQ_DONE_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQ_DONE_FORCE_tiny_l2_sq_done_force_START (0)
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQ_DONE_FORCE_tiny_l2_sq_done_force_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_cqe_written_force : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_NORMAL_CQE_WRITTEN_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQE_WRITTEN_FORCE_tiny_l2_cqe_written_force_START (0)
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQE_WRITTEN_FORCE_tiny_l2_cqe_written_force_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_task_debug_force : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_TINY_L2_TASK_DEBUG_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_TASK_DEBUG_FORCE_tiny_l2_task_debug_force_START (0)
#define SOC_NPU_HWTS_TINY_L2_TASK_DEBUG_FORCE_tiny_l2_task_debug_force_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_debug_paused_force : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_DEBUG_PAUSED_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_DEBUG_PAUSED_FORCE_tiny_l2_debug_paused_force_START (0)
#define SOC_NPU_HWTS_TINY_L2_DEBUG_PAUSED_FORCE_tiny_l2_debug_paused_force_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_task_error_force : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_TINY_L2_TASK_ERROR_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_TASK_ERROR_FORCE_tiny_l2_task_error_force_START (0)
#define SOC_NPU_HWTS_TINY_L2_TASK_ERROR_FORCE_tiny_l2_task_error_force_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_task_timeout_force : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_TASK_TIMEOUT_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_TASK_TIMEOUT_FORCE_tiny_l2_task_timeout_force_START (0)
#define SOC_NPU_HWTS_TINY_L2_TASK_TIMEOUT_FORCE_tiny_l2_task_timeout_force_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_task_trap_force : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_TINY_L2_TASK_TRAP_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_TASK_TRAP_FORCE_tiny_l2_task_trap_force_START (0)
#define SOC_NPU_HWTS_TINY_L2_TASK_TRAP_FORCE_tiny_l2_task_trap_force_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_sqe_error_force : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_TINY_L2_SQE_ERROR_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_SQE_ERROR_FORCE_tiny_l2_sqe_error_force_START (0)
#define SOC_NPU_HWTS_TINY_L2_SQE_ERROR_FORCE_tiny_l2_sqe_error_force_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_sw_status_error_force : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_TINY_L2_SW_STATUS_ERROR_FORCE_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_SW_STATUS_ERROR_FORCE_tiny_l2_sw_status_error_force_START (0)
#define SOC_NPU_HWTS_TINY_L2_SW_STATUS_ERROR_FORCE_tiny_l2_sw_status_error_force_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_sqe_done_mask : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_NORMAL_SQE_DONE_MASK_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQE_DONE_MASK_tiny_l2_sqe_done_mask_START (0)
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQE_DONE_MASK_tiny_l2_sqe_done_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_pre_paused_mask : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_NORMAL_PRE_PAUSED_MASK_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_NORMAL_PRE_PAUSED_MASK_tiny_l2_pre_paused_mask_START (0)
#define SOC_NPU_HWTS_TINY_L2_NORMAL_PRE_PAUSED_MASK_tiny_l2_pre_paused_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_post_paused_mask : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_NORMAL_POST_PAUSED_MASK_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_NORMAL_POST_PAUSED_MASK_tiny_l2_post_paused_mask_START (0)
#define SOC_NPU_HWTS_TINY_L2_NORMAL_POST_PAUSED_MASK_tiny_l2_post_paused_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_cq_full_mask : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_NORMAL_CQ_FULL_MASK_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQ_FULL_MASK_tiny_l2_cq_full_mask_START (0)
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQ_FULL_MASK_tiny_l2_cq_full_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_task_paused_mask : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_NORMAL_TASK_PAUSED_MASK_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_NORMAL_TASK_PAUSED_MASK_tiny_l2_task_paused_mask_START (0)
#define SOC_NPU_HWTS_TINY_L2_NORMAL_TASK_PAUSED_MASK_tiny_l2_task_paused_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_sq_done_mask : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_NORMAL_SQ_DONE_MASK_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQ_DONE_MASK_tiny_l2_sq_done_mask_START (0)
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQ_DONE_MASK_tiny_l2_sq_done_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_cqe_written_mask : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_NORMAL_CQE_WRITTEN_MASK_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQE_WRITTEN_MASK_tiny_l2_cqe_written_mask_START (0)
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQE_WRITTEN_MASK_tiny_l2_cqe_written_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_task_debug_mask : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_TASK_DEBUG_MASK_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_TASK_DEBUG_MASK_tiny_l2_task_debug_mask_START (0)
#define SOC_NPU_HWTS_TINY_L2_TASK_DEBUG_MASK_tiny_l2_task_debug_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_debug_paused_mask : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_DEBUG_PAUSED_MASK_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_DEBUG_PAUSED_MASK_tiny_l2_debug_paused_mask_START (0)
#define SOC_NPU_HWTS_TINY_L2_DEBUG_PAUSED_MASK_tiny_l2_debug_paused_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_task_error_mask : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_TASK_ERROR_MASK_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_TASK_ERROR_MASK_tiny_l2_task_error_mask_START (0)
#define SOC_NPU_HWTS_TINY_L2_TASK_ERROR_MASK_tiny_l2_task_error_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_task_timeout_mask : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_TASK_TIMEOUT_MASK_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_TASK_TIMEOUT_MASK_tiny_l2_task_timeout_mask_START (0)
#define SOC_NPU_HWTS_TINY_L2_TASK_TIMEOUT_MASK_tiny_l2_task_timeout_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_task_trap_mask : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_TASK_TRAP_MASK_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_TASK_TRAP_MASK_tiny_l2_task_trap_mask_START (0)
#define SOC_NPU_HWTS_TINY_L2_TASK_TRAP_MASK_tiny_l2_task_trap_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_sqe_error_mask : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_SQE_ERROR_MASK_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_SQE_ERROR_MASK_tiny_l2_sqe_error_mask_START (0)
#define SOC_NPU_HWTS_TINY_L2_SQE_ERROR_MASK_tiny_l2_sqe_error_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_sw_status_mask : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_SW_STATUS_ERROR_MASK_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_SW_STATUS_ERROR_MASK_tiny_l2_sw_status_mask_START (0)
#define SOC_NPU_HWTS_TINY_L2_SW_STATUS_ERROR_MASK_tiny_l2_sw_status_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_sqe_done_pending : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_NORMAL_SQE_DONE_INTERRUPT_PENDING_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQE_DONE_INTERRUPT_PENDING_tiny_l2_sqe_done_pending_START (0)
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQE_DONE_INTERRUPT_PENDING_tiny_l2_sqe_done_pending_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_pre_paused_pending : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_TINY_L2_NORMAL_PRE_PAUSED_INTERRUPT_PENDING_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_NORMAL_PRE_PAUSED_INTERRUPT_PENDING_tiny_l2_pre_paused_pending_START (0)
#define SOC_NPU_HWTS_TINY_L2_NORMAL_PRE_PAUSED_INTERRUPT_PENDING_tiny_l2_pre_paused_pending_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_post_paused_pending : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_TINY_L2_NORMAL_POST_PAUSED_INTERRUPT_PENDING_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_NORMAL_POST_PAUSED_INTERRUPT_PENDING_tiny_l2_post_paused_pending_START (0)
#define SOC_NPU_HWTS_TINY_L2_NORMAL_POST_PAUSED_INTERRUPT_PENDING_tiny_l2_post_paused_pending_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_cq_full_pending : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_TINY_L2_NORMAL_CQ_FULL_INTERRUPT_PENDING_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQ_FULL_INTERRUPT_PENDING_tiny_l2_cq_full_pending_START (0)
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQ_FULL_INTERRUPT_PENDING_tiny_l2_cq_full_pending_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_task_paused_pending : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_NORMAL_TASK_PAUSED_INTERRUPT_PENDING_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_NORMAL_TASK_PAUSED_INTERRUPT_PENDING_tiny_l2_task_paused_pending_START (0)
#define SOC_NPU_HWTS_TINY_L2_NORMAL_TASK_PAUSED_INTERRUPT_PENDING_tiny_l2_task_paused_pending_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_sq_done_pending : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_NORMAL_SQ_DONE_INTERRUPT_PENDING_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQ_DONE_INTERRUPT_PENDING_tiny_l2_sq_done_pending_START (0)
#define SOC_NPU_HWTS_TINY_L2_NORMAL_SQ_DONE_INTERRUPT_PENDING_tiny_l2_sq_done_pending_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_cqe_written_pending : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_NORMAL_CQE_WRITTEN_INTERRUPT_PENDING_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQE_WRITTEN_INTERRUPT_PENDING_tiny_l2_cqe_written_pending_START (0)
#define SOC_NPU_HWTS_TINY_L2_NORMAL_CQE_WRITTEN_INTERRUPT_PENDING_tiny_l2_cqe_written_pending_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_task_debug_pending : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_TINY_L2_TASK_DEBUG_INTERRUPT_PENDING_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_TASK_DEBUG_INTERRUPT_PENDING_tiny_l2_task_debug_pending_START (0)
#define SOC_NPU_HWTS_TINY_L2_TASK_DEBUG_INTERRUPT_PENDING_tiny_l2_task_debug_pending_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_debug_paused_pending : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_DEBUG_PAUSED_INTERRUPT_PENDING_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_DEBUG_PAUSED_INTERRUPT_PENDING_tiny_l2_debug_paused_pending_START (0)
#define SOC_NPU_HWTS_TINY_L2_DEBUG_PAUSED_INTERRUPT_PENDING_tiny_l2_debug_paused_pending_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_task_error_pending : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_TINY_L2_TASK_ERROR_INTERRUPT_PENDING_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_TASK_ERROR_INTERRUPT_PENDING_tiny_l2_task_error_pending_START (0)
#define SOC_NPU_HWTS_TINY_L2_TASK_ERROR_INTERRUPT_PENDING_tiny_l2_task_error_pending_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_task_timeout_pending : 32;
    } reg;
} SOC_NPU_HWTS_TINY_L2_TASK_TIMEOUT_INTERRUPT_PENDING_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_TASK_TIMEOUT_INTERRUPT_PENDING_tiny_l2_task_timeout_pending_START (0)
#define SOC_NPU_HWTS_TINY_L2_TASK_TIMEOUT_INTERRUPT_PENDING_tiny_l2_task_timeout_pending_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_task_trap_pending : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_TINY_L2_TASK_TRAP_INTERRUPT_PENDING_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_TASK_TRAP_INTERRUPT_PENDING_tiny_l2_task_trap_pending_START (0)
#define SOC_NPU_HWTS_TINY_L2_TASK_TRAP_INTERRUPT_PENDING_tiny_l2_task_trap_pending_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_sqe_error_pending : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_TINY_L2_SQE_ERROR_INTERRUPT_PENDING_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_SQE_ERROR_INTERRUPT_PENDING_tiny_l2_sqe_error_pending_START (0)
#define SOC_NPU_HWTS_TINY_L2_SQE_ERROR_INTERRUPT_PENDING_tiny_l2_sqe_error_pending_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tiny_l2_sw_status_error_pending : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_NPU_HWTS_TINY_L2_SW_STATUS_ERROR_INTERRUPT_PENDING_UNION;
#endif
#define SOC_NPU_HWTS_TINY_L2_SW_STATUS_ERROR_INTERRUPT_PENDING_tiny_l2_sw_status_error_pending_START (0)
#define SOC_NPU_HWTS_TINY_L2_SW_STATUS_ERROR_INTERRUPT_PENDING_tiny_l2_sw_status_error_pending_END (7)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
