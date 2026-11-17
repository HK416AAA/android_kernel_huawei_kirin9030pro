#ifndef __SOC_IOMCU_INTERFACE_H__
#define __SOC_IOMCU_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_IOMCU_CLK_SEL_ADDR(base) ((base) + (0x000UL))
#define SOC_IOMCU_CFG_DIV0_ADDR(base) ((base) + (0x004UL))
#define SOC_IOMCU_CFG_DIV1_ADDR(base) ((base) + (0x008UL))
#define SOC_IOMCU_RTC_CFG_ADDR(base) ((base) + (0x00CUL))
#define SOC_IOMCU_CLKEN0_ADDR(base) ((base) + (0x010UL))
#define SOC_IOMCU_CLKDIS0_ADDR(base) ((base) + (0x014UL))
#define SOC_IOMCU_CLKSTAT0_ADDR(base) ((base) + (0x018UL))
#define SOC_IOMCU_RSTEN0_ADDR(base) ((base) + (0x020UL))
#define SOC_IOMCU_RSTDIS0_ADDR(base) ((base) + (0x024UL))
#define SOC_IOMCU_RSTSTAT0_ADDR(base) ((base) + (0x028UL))
#define SOC_IOMCU_M7_CFG0_ADDR(base) ((base) + (0x030UL))
#define SOC_IOMCU_M7_CFG1_ADDR(base) ((base) + (0x034UL))
#define SOC_IOMCU_M7_STAT0_ADDR(base) ((base) + (0x038UL))
#define SOC_IOMCU_M7_STAT1_ADDR(base) ((base) + (0x03CUL))
#define SOC_IOMCU_DDR_ACCESS_WINDOW0_ADDR(base) ((base) + (0x040UL))
#define SOC_IOMCU_MMBUF_ACCESS_WINDOW_ADDR(base) ((base) + (0x044UL))
#define SOC_IOMCU_HACK_ACCESS_WINDOW_ADDR(base) ((base) + (0x048UL))
#define SOC_IOMCU_DLOCK_BYPASS_ADDR(base) ((base) + (0x04CUL))
#define SOC_IOMCU_MEM_CTRL_PGT_ADDR(base) ((base) + (0x050UL))
#define SOC_IOMCU_MEM_CTRL_0_ADDR(base) ((base) + (0x054UL))
#define SOC_IOMCU_SYS_STAT_ADDR(base) ((base) + (0x058UL))
#define SOC_IOMCU_SYS_CONFIG_ADDR(base) ((base) + (0x05CUL))
#define SOC_IOMCU_WAKEUP_EN_ADDR(base) ((base) + (0x060UL))
#define SOC_IOMCU_WAKEUP_CLR_ADDR(base) ((base) + (0x064UL))
#define SOC_IOMCU_WAKEUP_STAT_ADDR(base) ((base) + (0x068UL))
#define SOC_IOMCU_COMB_INT_RAW_ADDR(base) ((base) + (0x070UL))
#define SOC_IOMCU_COMB_INT_MSK_ADDR(base) ((base) + (0x074UL))
#define SOC_IOMCU_COMB_INT_STAT_ADDR(base) ((base) + (0x078UL))
#define SOC_IOMCU_BUS_AUTO_FREQ_ADDR(base) ((base) + (0x080UL))
#define SOC_IOMCU_MISC_CTRL_ADDR(base) ((base) + (0x084UL))
#define SOC_IOMCU_QIC_CTRL_ADDR(base) ((base) + (0x088UL))
#define SOC_IOMCU_HIFI_DTCM_ACCESS_WINDOW_ADDR(base) ((base) + (0x08CUL))
#define SOC_IOMCU_CLKEN1_ADDR(base) ((base) + (0x090UL))
#define SOC_IOMCU_CLKDIS1_ADDR(base) ((base) + (0x094UL))
#define SOC_IOMCU_CLKSTAT1_ADDR(base) ((base) + (0x098UL))
#define SOC_IOMCU_OCRAM_ACCESS_WINDOW_ADDR(base) ((base) + (0x09CUL))
#define SOC_IOMCU_SEC_TZPC_ADDR(base) ((base) + (0x0100UL))
#define SOC_IOMCU_SEC_TZPC_RES_ADDR(base) ((base) + (0x104UL))
#define SOC_IOMCU_MEM_CTRL6_ADDR(base) ((base) + (0x108UL))
#define SOC_IOMCU_QIC_USER_CTRL_ADDR(base) ((base) + (0x10CUL))
#define SOC_IOMCU_DDR_ACCESS_WINDOW1_ADDR(base) ((base) + (0x110UL))
#define SOC_IOMCU_SCBBPDRXSTAT1_IOMCU_ADDR(base) ((base) + (0x114UL))
#define SOC_IOMCU_SCBBPDRXSTAT2_IOMCU_ADDR(base) ((base) + (0x118UL))
#define SOC_IOMCU_CNT_VSYNC_VALUE_ADDR(base) ((base) + (0x11CUL))
#define SOC_IOMCU_CNT_VSYNC_CONFIG_ADDR(base) ((base) + (0x120UL))
#define SOC_IOMCU_CNT_VSYNC_CYCLE_ADDR(base) ((base) + (0x124UL))
#define SOC_IOMCU_FRAME_DATA_CONFIG_ADDR(base) ((base) + (0x128UL))
#define SOC_IOMCU_CFG_DIV2_ADDR(base) ((base) + (0x12CUL))
#define SOC_IOMCU_ADDR_REMAP_ADDR(base) ((base) + (0x130UL))
#define SOC_IOMCU_RSV_CORE_CTRL0_ADDR(base) ((base) + (0x134UL))
#define SOC_IOMCU_RSV_CORE_CTRL1_ADDR(base) ((base) + (0x138UL))
#define SOC_IOMCU_RSV_CORE_CTRL2_ADDR(base) ((base) + (0x13CUL))
#define SOC_IOMCU_RSV_CORE_CTRL3_ADDR(base) ((base) + (0x140UL))
#define SOC_IOMCU_RSV_CORE_CTRL4_ADDR(base) ((base) + (0x144UL))
#define SOC_IOMCU_RSV_CORE_CTRL5_ADDR(base) ((base) + (0x148UL))
#define SOC_IOMCU_RSV_CORE_CTRL6_ADDR(base) ((base) + (0x14CUL))
#define SOC_IOMCU_RSV_CORE_CTRL7_ADDR(base) ((base) + (0x150UL))
#define SOC_IOMCU_CORE_APB_TIMEOUT_INFO_ADDR(base) ((base) + (0x154UL))
#define SOC_IOMCU_CORE_APB_TIMEOUT_CFG_ADDR(base) ((base) + (0x158UL))
#define SOC_IOMCU_AXI_USER_ADDR(base) ((base) + (0x15CUL))
#define SOC_IOMCU_RSV_CORE_CTRL8_ADDR(base) ((base) + (0x160UL))
#define SOC_IOMCU_RESERVED_REG_0_ADDR(base) ((base) + (0x170UL))
#define SOC_IOMCU_RESERVED_REG_1_ADDR(base) ((base) + (0x174UL))
#define SOC_IOMCU_RESERVED_REG_2_ADDR(base) ((base) + (0x178UL))
#define SOC_IOMCU_RESERVED_REG_3_ADDR(base) ((base) + (0x17CUL))
#define SOC_IOMCU_RESERVED_REG_4_ADDR(base) ((base) + (0x180UL))
#define SOC_IOMCU_RESERVED_REG_5_ADDR(base) ((base) + (0x184UL))
#define SOC_IOMCU_RESERVED_REG_6_ADDR(base) ((base) + (0x188UL))
#define SOC_IOMCU_RESERVED_REG_7_ADDR(base) ((base) + (0x18CUL))
#define SOC_IOMCU_MEM_CTRL_SPUA_ADDR(base) ((base) + (0x198UL))
#define SOC_IOMCU_MEM_CTRL_TCM_ADDR(base) ((base) + (0x19CUL))
#define SOC_IOMCU_MEM_CTRL2_ADDR(base) ((base) + (0x200UL))
#define SOC_IOMCU_MEM_CTRL3_ADDR(base) ((base) + (0x204UL))
#define SOC_IOMCU_DMA_USER_CTRL_ADDR(base) ((base) + (0x208UL))
#define SOC_IOMCU_MEM_CTRL4_ADDR(base) ((base) + (0x20CUL))
#define SOC_IOMCU_MEM_CTRL5_ADDR(base) ((base) + (0x210UL))
#define SOC_IOMCU_ARADDR_CHK_ADDR(base) ((base) + (0x214UL))
#define SOC_IOMCU_AWADDR_CHK_ADDR(base) ((base) + (0x218UL))
#define SOC_IOMCU_MISC_CTRL_1_ADDR(base) ((base) + (0x21CUL))
#define SOC_IOMCU_CCM_CTRL_ADDR(base) ((base) + (0x220UL))
#define SOC_IOMCU_ARC_RB0_ADDR(base) ((base) + (0x224UL))
#define SOC_IOMCU_ARC_CTRL_ADDR(base) ((base) + (0x228UL))
#define SOC_IOMCU_CLK_MCU_FRAC_DIV_CTRL_ADDR(base) ((base) + (0x22CUL))
#define SOC_IOMCU_DCCM0_ERR_ADDR_ADDR(base) ((base) + (0x230UL))
#define SOC_IOMCU_DCCM1_ERR_ADDR_ADDR(base) ((base) + (0x234UL))
#define SOC_IOMCU_ICCM0_ERR_ADDR_ADDR(base) ((base) + (0x238UL))
#define SOC_IOMCU_CCM_RB0_ADDR(base) ((base) + (0x23CUL))
#define SOC_IOMCU_CCM_RB1_ADDR(base) ((base) + (0x240UL))
#define SOC_IOMCU_ARC_RB1_ADDR(base) ((base) + (0x244UL))
#define SOC_IOMCU_ARC_AP_PARAM0_ADDR(base) ((base) + (0x248UL))
#define SOC_IOMCU_ARC_AP_PARAM1_ADDR(base) ((base) + (0x24CUL))
#define SOC_IOMCU_ARC_EVENT_EN0_ADDR(base) ((base) + (0x250UL))
#define SOC_IOMCU_ARC_EVENT_EN1_ADDR(base) ((base) + (0x254UL))
#define SOC_IOMCU_ARC_EVENT_EN2_ADDR(base) ((base) + (0x258UL))
#define SOC_IOMCU_ARC_EVENT_EN3_ADDR(base) ((base) + (0x25CUL))
#define SOC_IOMCU_ARC_IRQ_EN0_ADDR(base) ((base) + (0x260UL))
#define SOC_IOMCU_ARC_IRQ_EN1_ADDR(base) ((base) + (0x264UL))
#define SOC_IOMCU_ARC_IRQ_EN2_ADDR(base) ((base) + (0x268UL))
#define SOC_IOMCU_ARC_IRQ_EN3_ADDR(base) ((base) + (0x26CUL))
#define SOC_IOMCU_ARC_EVENT_EN4_ADDR(base) ((base) + (0x270UL))
#define SOC_IOMCU_ARC_EVENT_EN5_ADDR(base) ((base) + (0x274UL))
#define SOC_IOMCU_ARC_EVENT_EN6_ADDR(base) ((base) + (0x278UL))
#define SOC_IOMCU_ARC_EVENT_EN7_ADDR(base) ((base) + (0x27CUL))
#define SOC_IOMCU_M7_AHB_DBG_INFO1_ADDR(base) ((base) + (0x280UL))
#define SOC_IOMCU_M7_AHB_DBG_INFO2_ADDR(base) ((base) + (0x284UL))
#define SOC_IOMCU_M7_AHB_TIME_CFG_ADDR(base) ((base) + (0x288UL))
#define SOC_IOMCU_M7_AHB_TIMEOUT_ADDR(base) ((base) + (0x28CUL))
#define SOC_IOMCU_QIC_CTL_1_ADDR(base) ((base) + (0x290UL))
#define SOC_IOMCU_RESERVED_REG1_ADDR(base) ((base) + (0x294UL))
#define SOC_IOMCU_RSV_HART_ID_ADDR(base) ((base) + (0x298UL))
#define SOC_IOMCU_RSV_DFX0_ADDR(base) ((base) + (0x29CUL))
#define SOC_IOMCU_RSV_DFX1_ADDR(base) ((base) + (0x300UL))
#define SOC_IOMCU_RSV_DFX2_ADDR(base) ((base) + (0x304UL))
#define SOC_IOMCU_RSV_DFX3_ADDR(base) ((base) + (0x308UL))
#define SOC_IOMCU_RSV_DFX4_ADDR(base) ((base) + (0x30CUL))
#define SOC_IOMCU_RSTEN1_ADDR(base) ((base) + (0x310UL))
#define SOC_IOMCU_RSTDIS1_ADDR(base) ((base) + (0x314UL))
#define SOC_IOMCU_RSTSTAT1_ADDR(base) ((base) + (0x318UL))
#define SOC_IOMCU_RSV_DFX5_ADDR(base,m) ((base) + (0x31C+0x004*(m)))
#define SOC_IOMCU_SEC_CTRL_ADDR(base) ((base) + (0x39CUL))
#else
#define SOC_IOMCU_CLK_SEL_ADDR(base) ((base) + (0x000))
#define SOC_IOMCU_CFG_DIV0_ADDR(base) ((base) + (0x004))
#define SOC_IOMCU_CFG_DIV1_ADDR(base) ((base) + (0x008))
#define SOC_IOMCU_RTC_CFG_ADDR(base) ((base) + (0x00C))
#define SOC_IOMCU_CLKEN0_ADDR(base) ((base) + (0x010))
#define SOC_IOMCU_CLKDIS0_ADDR(base) ((base) + (0x014))
#define SOC_IOMCU_CLKSTAT0_ADDR(base) ((base) + (0x018))
#define SOC_IOMCU_RSTEN0_ADDR(base) ((base) + (0x020))
#define SOC_IOMCU_RSTDIS0_ADDR(base) ((base) + (0x024))
#define SOC_IOMCU_RSTSTAT0_ADDR(base) ((base) + (0x028))
#define SOC_IOMCU_M7_CFG0_ADDR(base) ((base) + (0x030))
#define SOC_IOMCU_M7_CFG1_ADDR(base) ((base) + (0x034))
#define SOC_IOMCU_M7_STAT0_ADDR(base) ((base) + (0x038))
#define SOC_IOMCU_M7_STAT1_ADDR(base) ((base) + (0x03C))
#define SOC_IOMCU_DDR_ACCESS_WINDOW0_ADDR(base) ((base) + (0x040))
#define SOC_IOMCU_MMBUF_ACCESS_WINDOW_ADDR(base) ((base) + (0x044))
#define SOC_IOMCU_HACK_ACCESS_WINDOW_ADDR(base) ((base) + (0x048))
#define SOC_IOMCU_DLOCK_BYPASS_ADDR(base) ((base) + (0x04C))
#define SOC_IOMCU_MEM_CTRL_PGT_ADDR(base) ((base) + (0x050))
#define SOC_IOMCU_MEM_CTRL_0_ADDR(base) ((base) + (0x054))
#define SOC_IOMCU_SYS_STAT_ADDR(base) ((base) + (0x058))
#define SOC_IOMCU_SYS_CONFIG_ADDR(base) ((base) + (0x05C))
#define SOC_IOMCU_WAKEUP_EN_ADDR(base) ((base) + (0x060))
#define SOC_IOMCU_WAKEUP_CLR_ADDR(base) ((base) + (0x064))
#define SOC_IOMCU_WAKEUP_STAT_ADDR(base) ((base) + (0x068))
#define SOC_IOMCU_COMB_INT_RAW_ADDR(base) ((base) + (0x070))
#define SOC_IOMCU_COMB_INT_MSK_ADDR(base) ((base) + (0x074))
#define SOC_IOMCU_COMB_INT_STAT_ADDR(base) ((base) + (0x078))
#define SOC_IOMCU_BUS_AUTO_FREQ_ADDR(base) ((base) + (0x080))
#define SOC_IOMCU_MISC_CTRL_ADDR(base) ((base) + (0x084))
#define SOC_IOMCU_QIC_CTRL_ADDR(base) ((base) + (0x088))
#define SOC_IOMCU_HIFI_DTCM_ACCESS_WINDOW_ADDR(base) ((base) + (0x08C))
#define SOC_IOMCU_CLKEN1_ADDR(base) ((base) + (0x090))
#define SOC_IOMCU_CLKDIS1_ADDR(base) ((base) + (0x094))
#define SOC_IOMCU_CLKSTAT1_ADDR(base) ((base) + (0x098))
#define SOC_IOMCU_OCRAM_ACCESS_WINDOW_ADDR(base) ((base) + (0x09C))
#define SOC_IOMCU_SEC_TZPC_ADDR(base) ((base) + (0x0100))
#define SOC_IOMCU_SEC_TZPC_RES_ADDR(base) ((base) + (0x104))
#define SOC_IOMCU_MEM_CTRL6_ADDR(base) ((base) + (0x108))
#define SOC_IOMCU_QIC_USER_CTRL_ADDR(base) ((base) + (0x10C))
#define SOC_IOMCU_DDR_ACCESS_WINDOW1_ADDR(base) ((base) + (0x110))
#define SOC_IOMCU_SCBBPDRXSTAT1_IOMCU_ADDR(base) ((base) + (0x114))
#define SOC_IOMCU_SCBBPDRXSTAT2_IOMCU_ADDR(base) ((base) + (0x118))
#define SOC_IOMCU_CNT_VSYNC_VALUE_ADDR(base) ((base) + (0x11C))
#define SOC_IOMCU_CNT_VSYNC_CONFIG_ADDR(base) ((base) + (0x120))
#define SOC_IOMCU_CNT_VSYNC_CYCLE_ADDR(base) ((base) + (0x124))
#define SOC_IOMCU_FRAME_DATA_CONFIG_ADDR(base) ((base) + (0x128))
#define SOC_IOMCU_CFG_DIV2_ADDR(base) ((base) + (0x12C))
#define SOC_IOMCU_ADDR_REMAP_ADDR(base) ((base) + (0x130))
#define SOC_IOMCU_RSV_CORE_CTRL0_ADDR(base) ((base) + (0x134))
#define SOC_IOMCU_RSV_CORE_CTRL1_ADDR(base) ((base) + (0x138))
#define SOC_IOMCU_RSV_CORE_CTRL2_ADDR(base) ((base) + (0x13C))
#define SOC_IOMCU_RSV_CORE_CTRL3_ADDR(base) ((base) + (0x140))
#define SOC_IOMCU_RSV_CORE_CTRL4_ADDR(base) ((base) + (0x144))
#define SOC_IOMCU_RSV_CORE_CTRL5_ADDR(base) ((base) + (0x148))
#define SOC_IOMCU_RSV_CORE_CTRL6_ADDR(base) ((base) + (0x14C))
#define SOC_IOMCU_RSV_CORE_CTRL7_ADDR(base) ((base) + (0x150))
#define SOC_IOMCU_CORE_APB_TIMEOUT_INFO_ADDR(base) ((base) + (0x154))
#define SOC_IOMCU_CORE_APB_TIMEOUT_CFG_ADDR(base) ((base) + (0x158))
#define SOC_IOMCU_AXI_USER_ADDR(base) ((base) + (0x15C))
#define SOC_IOMCU_RSV_CORE_CTRL8_ADDR(base) ((base) + (0x160))
#define SOC_IOMCU_RESERVED_REG_0_ADDR(base) ((base) + (0x170))
#define SOC_IOMCU_RESERVED_REG_1_ADDR(base) ((base) + (0x174))
#define SOC_IOMCU_RESERVED_REG_2_ADDR(base) ((base) + (0x178))
#define SOC_IOMCU_RESERVED_REG_3_ADDR(base) ((base) + (0x17C))
#define SOC_IOMCU_RESERVED_REG_4_ADDR(base) ((base) + (0x180))
#define SOC_IOMCU_RESERVED_REG_5_ADDR(base) ((base) + (0x184))
#define SOC_IOMCU_RESERVED_REG_6_ADDR(base) ((base) + (0x188))
#define SOC_IOMCU_RESERVED_REG_7_ADDR(base) ((base) + (0x18C))
#define SOC_IOMCU_MEM_CTRL_SPUA_ADDR(base) ((base) + (0x198))
#define SOC_IOMCU_MEM_CTRL_TCM_ADDR(base) ((base) + (0x19C))
#define SOC_IOMCU_MEM_CTRL2_ADDR(base) ((base) + (0x200))
#define SOC_IOMCU_MEM_CTRL3_ADDR(base) ((base) + (0x204))
#define SOC_IOMCU_DMA_USER_CTRL_ADDR(base) ((base) + (0x208))
#define SOC_IOMCU_MEM_CTRL4_ADDR(base) ((base) + (0x20C))
#define SOC_IOMCU_MEM_CTRL5_ADDR(base) ((base) + (0x210))
#define SOC_IOMCU_ARADDR_CHK_ADDR(base) ((base) + (0x214))
#define SOC_IOMCU_AWADDR_CHK_ADDR(base) ((base) + (0x218))
#define SOC_IOMCU_MISC_CTRL_1_ADDR(base) ((base) + (0x21C))
#define SOC_IOMCU_CCM_CTRL_ADDR(base) ((base) + (0x220))
#define SOC_IOMCU_ARC_RB0_ADDR(base) ((base) + (0x224))
#define SOC_IOMCU_ARC_CTRL_ADDR(base) ((base) + (0x228))
#define SOC_IOMCU_CLK_MCU_FRAC_DIV_CTRL_ADDR(base) ((base) + (0x22C))
#define SOC_IOMCU_DCCM0_ERR_ADDR_ADDR(base) ((base) + (0x230))
#define SOC_IOMCU_DCCM1_ERR_ADDR_ADDR(base) ((base) + (0x234))
#define SOC_IOMCU_ICCM0_ERR_ADDR_ADDR(base) ((base) + (0x238))
#define SOC_IOMCU_CCM_RB0_ADDR(base) ((base) + (0x23C))
#define SOC_IOMCU_CCM_RB1_ADDR(base) ((base) + (0x240))
#define SOC_IOMCU_ARC_RB1_ADDR(base) ((base) + (0x244))
#define SOC_IOMCU_ARC_AP_PARAM0_ADDR(base) ((base) + (0x248))
#define SOC_IOMCU_ARC_AP_PARAM1_ADDR(base) ((base) + (0x24C))
#define SOC_IOMCU_ARC_EVENT_EN0_ADDR(base) ((base) + (0x250))
#define SOC_IOMCU_ARC_EVENT_EN1_ADDR(base) ((base) + (0x254))
#define SOC_IOMCU_ARC_EVENT_EN2_ADDR(base) ((base) + (0x258))
#define SOC_IOMCU_ARC_EVENT_EN3_ADDR(base) ((base) + (0x25C))
#define SOC_IOMCU_ARC_IRQ_EN0_ADDR(base) ((base) + (0x260))
#define SOC_IOMCU_ARC_IRQ_EN1_ADDR(base) ((base) + (0x264))
#define SOC_IOMCU_ARC_IRQ_EN2_ADDR(base) ((base) + (0x268))
#define SOC_IOMCU_ARC_IRQ_EN3_ADDR(base) ((base) + (0x26C))
#define SOC_IOMCU_ARC_EVENT_EN4_ADDR(base) ((base) + (0x270))
#define SOC_IOMCU_ARC_EVENT_EN5_ADDR(base) ((base) + (0x274))
#define SOC_IOMCU_ARC_EVENT_EN6_ADDR(base) ((base) + (0x278))
#define SOC_IOMCU_ARC_EVENT_EN7_ADDR(base) ((base) + (0x27C))
#define SOC_IOMCU_M7_AHB_DBG_INFO1_ADDR(base) ((base) + (0x280))
#define SOC_IOMCU_M7_AHB_DBG_INFO2_ADDR(base) ((base) + (0x284))
#define SOC_IOMCU_M7_AHB_TIME_CFG_ADDR(base) ((base) + (0x288))
#define SOC_IOMCU_M7_AHB_TIMEOUT_ADDR(base) ((base) + (0x28C))
#define SOC_IOMCU_QIC_CTL_1_ADDR(base) ((base) + (0x290))
#define SOC_IOMCU_RESERVED_REG1_ADDR(base) ((base) + (0x294))
#define SOC_IOMCU_RSV_HART_ID_ADDR(base) ((base) + (0x298))
#define SOC_IOMCU_RSV_DFX0_ADDR(base) ((base) + (0x29C))
#define SOC_IOMCU_RSV_DFX1_ADDR(base) ((base) + (0x300))
#define SOC_IOMCU_RSV_DFX2_ADDR(base) ((base) + (0x304))
#define SOC_IOMCU_RSV_DFX3_ADDR(base) ((base) + (0x308))
#define SOC_IOMCU_RSV_DFX4_ADDR(base) ((base) + (0x30C))
#define SOC_IOMCU_RSTEN1_ADDR(base) ((base) + (0x310))
#define SOC_IOMCU_RSTDIS1_ADDR(base) ((base) + (0x314))
#define SOC_IOMCU_RSTSTAT1_ADDR(base) ((base) + (0x318))
#define SOC_IOMCU_RSV_DFX5_ADDR(base,m) ((base) + (0x31C+0x004*(m)))
#define SOC_IOMCU_SEC_CTRL_ADDR(base) ((base) + (0x39C))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk_mcu_sel : 2;
        unsigned int clk_mcu_sel_stat : 2;
        unsigned int clk_peri1_sel_spi2 : 2;
        unsigned int clk_peri1_sel_stat_spi2 : 2;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 2;
        unsigned int clk_peri0_sel : 2;
        unsigned int clk_peri1_sel : 2;
        unsigned int clk_peri2_sel : 2;
        unsigned int reserved_2 : 2;
        unsigned int clk_peri0_sel_stat : 2;
        unsigned int clk_peri1_sel_stat : 2;
        unsigned int clk_peri2_sel_stat : 2;
        unsigned int reserved_3 : 2;
        unsigned int clk_pll_stable : 1;
        unsigned int clk_fll_stable : 1;
        unsigned int sel_ftimer_clk : 2;
    } reg;
} SOC_IOMCU_CLK_SEL_UNION;
#endif
#define SOC_IOMCU_CLK_SEL_clk_mcu_sel_START (0)
#define SOC_IOMCU_CLK_SEL_clk_mcu_sel_END (1)
#define SOC_IOMCU_CLK_SEL_clk_mcu_sel_stat_START (2)
#define SOC_IOMCU_CLK_SEL_clk_mcu_sel_stat_END (3)
#define SOC_IOMCU_CLK_SEL_clk_peri1_sel_spi2_START (4)
#define SOC_IOMCU_CLK_SEL_clk_peri1_sel_spi2_END (5)
#define SOC_IOMCU_CLK_SEL_clk_peri1_sel_stat_spi2_START (6)
#define SOC_IOMCU_CLK_SEL_clk_peri1_sel_stat_spi2_END (7)
#define SOC_IOMCU_CLK_SEL_clk_peri0_sel_START (12)
#define SOC_IOMCU_CLK_SEL_clk_peri0_sel_END (13)
#define SOC_IOMCU_CLK_SEL_clk_peri1_sel_START (14)
#define SOC_IOMCU_CLK_SEL_clk_peri1_sel_END (15)
#define SOC_IOMCU_CLK_SEL_clk_peri2_sel_START (16)
#define SOC_IOMCU_CLK_SEL_clk_peri2_sel_END (17)
#define SOC_IOMCU_CLK_SEL_clk_peri0_sel_stat_START (20)
#define SOC_IOMCU_CLK_SEL_clk_peri0_sel_stat_END (21)
#define SOC_IOMCU_CLK_SEL_clk_peri1_sel_stat_START (22)
#define SOC_IOMCU_CLK_SEL_clk_peri1_sel_stat_END (23)
#define SOC_IOMCU_CLK_SEL_clk_peri2_sel_stat_START (24)
#define SOC_IOMCU_CLK_SEL_clk_peri2_sel_stat_END (25)
#define SOC_IOMCU_CLK_SEL_clk_pll_stable_START (28)
#define SOC_IOMCU_CLK_SEL_clk_pll_stable_END (28)
#define SOC_IOMCU_CLK_SEL_clk_fll_stable_START (29)
#define SOC_IOMCU_CLK_SEL_clk_fll_stable_END (29)
#define SOC_IOMCU_CLK_SEL_sel_ftimer_clk_START (30)
#define SOC_IOMCU_CLK_SEL_sel_ftimer_clk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_mcu0_div : 2;
        unsigned int iomcu_apb_l_div_pre : 2;
        unsigned int iomcu_apb_l_div : 2;
        unsigned int reserved_0 : 1;
        unsigned int iomcu_apb_l_div_en : 1;
        unsigned int iomcu_apb_h_div : 2;
        unsigned int iomcu_mcu1_div : 2;
        unsigned int iomcu_peri0_div : 2;
        unsigned int reserved_1 : 1;
        unsigned int iomcu_peri_ahb_div_en : 1;
        unsigned int iomcu_peri1_div : 2;
        unsigned int iomcu_peri2_div : 2;
        unsigned int reserved_2 : 2;
        unsigned int reserved_3 : 1;
        unsigned int iomcu_peri_div_en : 1;
        unsigned int iomcu_div : 6;
        unsigned int reserved_4 : 1;
        unsigned int iomcu_div_en : 1;
    } reg;
} SOC_IOMCU_CFG_DIV0_UNION;
#endif
#define SOC_IOMCU_CFG_DIV0_iomcu_mcu0_div_START (0)
#define SOC_IOMCU_CFG_DIV0_iomcu_mcu0_div_END (1)
#define SOC_IOMCU_CFG_DIV0_iomcu_apb_l_div_pre_START (2)
#define SOC_IOMCU_CFG_DIV0_iomcu_apb_l_div_pre_END (3)
#define SOC_IOMCU_CFG_DIV0_iomcu_apb_l_div_START (4)
#define SOC_IOMCU_CFG_DIV0_iomcu_apb_l_div_END (5)
#define SOC_IOMCU_CFG_DIV0_iomcu_apb_l_div_en_START (7)
#define SOC_IOMCU_CFG_DIV0_iomcu_apb_l_div_en_END (7)
#define SOC_IOMCU_CFG_DIV0_iomcu_apb_h_div_START (8)
#define SOC_IOMCU_CFG_DIV0_iomcu_apb_h_div_END (9)
#define SOC_IOMCU_CFG_DIV0_iomcu_mcu1_div_START (10)
#define SOC_IOMCU_CFG_DIV0_iomcu_mcu1_div_END (11)
#define SOC_IOMCU_CFG_DIV0_iomcu_peri0_div_START (12)
#define SOC_IOMCU_CFG_DIV0_iomcu_peri0_div_END (13)
#define SOC_IOMCU_CFG_DIV0_iomcu_peri_ahb_div_en_START (15)
#define SOC_IOMCU_CFG_DIV0_iomcu_peri_ahb_div_en_END (15)
#define SOC_IOMCU_CFG_DIV0_iomcu_peri1_div_START (16)
#define SOC_IOMCU_CFG_DIV0_iomcu_peri1_div_END (17)
#define SOC_IOMCU_CFG_DIV0_iomcu_peri2_div_START (18)
#define SOC_IOMCU_CFG_DIV0_iomcu_peri2_div_END (19)
#define SOC_IOMCU_CFG_DIV0_iomcu_peri_div_en_START (23)
#define SOC_IOMCU_CFG_DIV0_iomcu_peri_div_en_END (23)
#define SOC_IOMCU_CFG_DIV0_iomcu_div_START (24)
#define SOC_IOMCU_CFG_DIV0_iomcu_div_END (29)
#define SOC_IOMCU_CFG_DIV0_iomcu_div_en_START (31)
#define SOC_IOMCU_CFG_DIV0_iomcu_div_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_mcu0_div_nopending : 2;
        unsigned int iomcu_mcu1_div_nopending : 2;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 1;
        unsigned int iomcu_mcu1_div_en : 1;
        unsigned int ftimer0_div0 : 2;
        unsigned int ftimer0_div1 : 2;
        unsigned int ftimer0_div2 : 2;
        unsigned int reserved_2 : 1;
        unsigned int ftimer_div_en : 1;
        unsigned int iomcu_peri1_div_spi2 : 2;
        unsigned int ftimer1_div1 : 2;
        unsigned int ftimer1_div2 : 2;
        unsigned int reserved_3 : 1;
        unsigned int iomcu_peri_div_en_spi2 : 1;
        unsigned int auto_cpu_freq_bypass : 1;
        unsigned int reserved_4 : 6;
        unsigned int acpu_ctrl_en : 1;
    } reg;
} SOC_IOMCU_CFG_DIV1_UNION;
#endif
#define SOC_IOMCU_CFG_DIV1_iomcu_mcu0_div_nopending_START (0)
#define SOC_IOMCU_CFG_DIV1_iomcu_mcu0_div_nopending_END (1)
#define SOC_IOMCU_CFG_DIV1_iomcu_mcu1_div_nopending_START (2)
#define SOC_IOMCU_CFG_DIV1_iomcu_mcu1_div_nopending_END (3)
#define SOC_IOMCU_CFG_DIV1_iomcu_mcu1_div_en_START (7)
#define SOC_IOMCU_CFG_DIV1_iomcu_mcu1_div_en_END (7)
#define SOC_IOMCU_CFG_DIV1_ftimer0_div0_START (8)
#define SOC_IOMCU_CFG_DIV1_ftimer0_div0_END (9)
#define SOC_IOMCU_CFG_DIV1_ftimer0_div1_START (10)
#define SOC_IOMCU_CFG_DIV1_ftimer0_div1_END (11)
#define SOC_IOMCU_CFG_DIV1_ftimer0_div2_START (12)
#define SOC_IOMCU_CFG_DIV1_ftimer0_div2_END (13)
#define SOC_IOMCU_CFG_DIV1_ftimer_div_en_START (15)
#define SOC_IOMCU_CFG_DIV1_ftimer_div_en_END (15)
#define SOC_IOMCU_CFG_DIV1_iomcu_peri1_div_spi2_START (16)
#define SOC_IOMCU_CFG_DIV1_iomcu_peri1_div_spi2_END (17)
#define SOC_IOMCU_CFG_DIV1_ftimer1_div1_START (18)
#define SOC_IOMCU_CFG_DIV1_ftimer1_div1_END (19)
#define SOC_IOMCU_CFG_DIV1_ftimer1_div2_START (20)
#define SOC_IOMCU_CFG_DIV1_ftimer1_div2_END (21)
#define SOC_IOMCU_CFG_DIV1_iomcu_peri_div_en_spi2_START (23)
#define SOC_IOMCU_CFG_DIV1_iomcu_peri_div_en_spi2_END (23)
#define SOC_IOMCU_CFG_DIV1_auto_cpu_freq_bypass_START (24)
#define SOC_IOMCU_CFG_DIV1_auto_cpu_freq_bypass_END (24)
#define SOC_IOMCU_CFG_DIV1_acpu_ctrl_en_START (31)
#define SOC_IOMCU_CFG_DIV1_acpu_ctrl_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rtc_clk_sel : 1;
        unsigned int rtc_crc_clken : 1;
        unsigned int reserved_0 : 2;
        unsigned int rtc_div_quotient : 11;
        unsigned int reserved_1 : 1;
        unsigned int rtc_div_remainder : 10;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_IOMCU_RTC_CFG_UNION;
#endif
#define SOC_IOMCU_RTC_CFG_rtc_clk_sel_START (0)
#define SOC_IOMCU_RTC_CFG_rtc_clk_sel_END (0)
#define SOC_IOMCU_RTC_CFG_rtc_crc_clken_START (1)
#define SOC_IOMCU_RTC_CFG_rtc_crc_clken_END (1)
#define SOC_IOMCU_RTC_CFG_rtc_div_quotient_START (4)
#define SOC_IOMCU_RTC_CFG_rtc_div_quotient_END (14)
#define SOC_IOMCU_RTC_CFG_rtc_div_remainder_START (16)
#define SOC_IOMCU_RTC_CFG_rtc_div_remainder_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_clken0_0dmac : 1;
        unsigned int iomcu_clken0_lwdt : 1;
        unsigned int iomcu_clken0_2timer : 1;
        unsigned int iomcu_clken0_3i2c0 : 1;
        unsigned int iomcu_clken0_4i2c1 : 1;
        unsigned int iomcu_clken0_5i3c1 : 1;
        unsigned int iomcu_clken0_6gpio : 1;
        unsigned int iomcu_clken0_7spi4 : 1;
        unsigned int iomcu_clken0_8spi8 : 1;
        unsigned int iomcu_clken0_9spi9 : 1;
        unsigned int iomcu_clken0_10spi0 : 1;
        unsigned int iomcu_clken0_11uart3 : 1;
        unsigned int iomcu_clken0_12uart7 : 1;
        unsigned int iomcu_clken0_13spi10 : 1;
        unsigned int iomcu_clken0_14fclk_mcu : 1;
        unsigned int iomcu_clken0_15clk_mcu : 1;
        unsigned int iomcu_clken0_16clk_etm : 1;
        unsigned int iomcu_clken0_17aclk_mcu : 1;
        unsigned int iomcu_clken0_18hclk_mcu : 1;
        unsigned int iomcu_clken0_19clk_fll : 1;
        unsigned int iomcu_clken0_20clk_ppll0 : 1;
        unsigned int iomcu_clken0_21clk_dapb : 1;
        unsigned int iomcu_clken0_22clk_atb : 1;
        unsigned int iomcu_clken0_23pclk_rtc : 1;
        unsigned int iomcu_clken0_24clk_ctm : 1;
        unsigned int iomcu_clken0_25clk_tcxo_in : 1;
        unsigned int iomcu_clken0_26i2c5 : 1;
        unsigned int iomcu_clken0_27i3c2 : 1;
        unsigned int iomcu_clken0_28tcm : 1;
        unsigned int iomcu_clken0_29ao_bus : 1;
        unsigned int iomcu_clken0_30spi2 : 1;
        unsigned int iomcu_clken0_31uart8 : 1;
    } reg;
} SOC_IOMCU_CLKEN0_UNION;
#endif
#define SOC_IOMCU_CLKEN0_iomcu_clken0_0dmac_START (0)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_0dmac_END (0)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_lwdt_START (1)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_lwdt_END (1)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_2timer_START (2)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_2timer_END (2)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_3i2c0_START (3)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_3i2c0_END (3)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_4i2c1_START (4)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_4i2c1_END (4)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_5i3c1_START (5)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_5i3c1_END (5)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_6gpio_START (6)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_6gpio_END (6)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_7spi4_START (7)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_7spi4_END (7)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_8spi8_START (8)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_8spi8_END (8)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_9spi9_START (9)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_9spi9_END (9)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_10spi0_START (10)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_10spi0_END (10)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_11uart3_START (11)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_11uart3_END (11)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_12uart7_START (12)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_12uart7_END (12)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_13spi10_START (13)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_13spi10_END (13)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_14fclk_mcu_START (14)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_14fclk_mcu_END (14)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_15clk_mcu_START (15)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_15clk_mcu_END (15)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_16clk_etm_START (16)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_16clk_etm_END (16)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_17aclk_mcu_START (17)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_17aclk_mcu_END (17)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_18hclk_mcu_START (18)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_18hclk_mcu_END (18)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_19clk_fll_START (19)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_19clk_fll_END (19)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_20clk_ppll0_START (20)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_20clk_ppll0_END (20)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_21clk_dapb_START (21)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_21clk_dapb_END (21)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_22clk_atb_START (22)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_22clk_atb_END (22)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_23pclk_rtc_START (23)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_23pclk_rtc_END (23)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_24clk_ctm_START (24)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_24clk_ctm_END (24)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_25clk_tcxo_in_START (25)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_25clk_tcxo_in_END (25)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_26i2c5_START (26)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_26i2c5_END (26)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_27i3c2_START (27)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_27i3c2_END (27)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_28tcm_START (28)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_28tcm_END (28)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_29ao_bus_START (29)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_29ao_bus_END (29)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_30spi2_START (30)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_30spi2_END (30)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_31uart8_START (31)
#define SOC_IOMCU_CLKEN0_iomcu_clken0_31uart8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_clkdis0_0dmac : 1;
        unsigned int iomcu_clkdis0_lwdt : 1;
        unsigned int iomcu_clkdis0_2timer : 1;
        unsigned int iomcu_clkdis0_3i2c0 : 1;
        unsigned int iomcu_clkdis0_4i2c1 : 1;
        unsigned int iomcu_clkdis0_5i3c1 : 1;
        unsigned int iomcu_clkdis0_6gpio : 1;
        unsigned int iomcu_clkdis0_7spi4 : 1;
        unsigned int iomcu_clkdis0_8spi8 : 1;
        unsigned int iomcu_clkdis0_9spi9 : 1;
        unsigned int iomcu_clkdis0_10spi0 : 1;
        unsigned int iomcu_clkdis0_11uart3 : 1;
        unsigned int iomcu_clkdis0_12uart7 : 1;
        unsigned int iomcu_clkdis0_13spi10 : 1;
        unsigned int iomcu_clkdis0_14fclk_mcu : 1;
        unsigned int iomcu_clkdis0_15clk_mcu : 1;
        unsigned int iomcu_clkdis0_16clk_etm : 1;
        unsigned int iomcu_clkdis0_17aclk_mcu : 1;
        unsigned int iomcu_clkdis0_18hclk_mcu : 1;
        unsigned int iomcu_clkdis0_19clk_fll : 1;
        unsigned int iomcu_clkdis0_20clk_ppll0 : 1;
        unsigned int iomcu_clkdis0_21clk_dapb : 1;
        unsigned int iomcu_clkdis0_22clk_atb : 1;
        unsigned int iomcu_clkdis0_23pclk_rtc : 1;
        unsigned int iomcu_clkdis0_24clk_ctm : 1;
        unsigned int iomcu_clkdis0_25clk_tcxo_in : 1;
        unsigned int iomcu_clkdis0_26i2c5 : 1;
        unsigned int iomcu_clkdis0_27i3c2 : 1;
        unsigned int iomcu_clkdis0_28tcm : 1;
        unsigned int iomcu_clkdis0_29ao_bus : 1;
        unsigned int iomcu_clkdis0_30spi2 : 1;
        unsigned int iomcu_clkdis0_31uart8 : 1;
    } reg;
} SOC_IOMCU_CLKDIS0_UNION;
#endif
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_0dmac_START (0)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_0dmac_END (0)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_lwdt_START (1)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_lwdt_END (1)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_2timer_START (2)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_2timer_END (2)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_3i2c0_START (3)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_3i2c0_END (3)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_4i2c1_START (4)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_4i2c1_END (4)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_5i3c1_START (5)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_5i3c1_END (5)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_6gpio_START (6)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_6gpio_END (6)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_7spi4_START (7)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_7spi4_END (7)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_8spi8_START (8)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_8spi8_END (8)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_9spi9_START (9)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_9spi9_END (9)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_10spi0_START (10)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_10spi0_END (10)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_11uart3_START (11)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_11uart3_END (11)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_12uart7_START (12)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_12uart7_END (12)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_13spi10_START (13)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_13spi10_END (13)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_14fclk_mcu_START (14)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_14fclk_mcu_END (14)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_15clk_mcu_START (15)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_15clk_mcu_END (15)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_16clk_etm_START (16)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_16clk_etm_END (16)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_17aclk_mcu_START (17)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_17aclk_mcu_END (17)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_18hclk_mcu_START (18)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_18hclk_mcu_END (18)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_19clk_fll_START (19)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_19clk_fll_END (19)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_20clk_ppll0_START (20)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_20clk_ppll0_END (20)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_21clk_dapb_START (21)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_21clk_dapb_END (21)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_22clk_atb_START (22)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_22clk_atb_END (22)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_23pclk_rtc_START (23)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_23pclk_rtc_END (23)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_24clk_ctm_START (24)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_24clk_ctm_END (24)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_25clk_tcxo_in_START (25)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_25clk_tcxo_in_END (25)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_26i2c5_START (26)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_26i2c5_END (26)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_27i3c2_START (27)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_27i3c2_END (27)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_28tcm_START (28)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_28tcm_END (28)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_29ao_bus_START (29)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_29ao_bus_END (29)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_30spi2_START (30)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_30spi2_END (30)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_31uart8_START (31)
#define SOC_IOMCU_CLKDIS0_iomcu_clkdis0_31uart8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_clkstat0_0dmac : 1;
        unsigned int iomcu_clkstat0_lwdt : 1;
        unsigned int iomcu_clkstat0_2timer : 1;
        unsigned int iomcu_clkstat0_3i2c0 : 1;
        unsigned int iomcu_clkstat0_4i2c1 : 1;
        unsigned int iomcu_clkstat0_5i3c1 : 1;
        unsigned int iomcu_clkstat0_6gpio : 1;
        unsigned int iomcu_clkstat0_7spi4 : 1;
        unsigned int iomcu_clkstat0_8spi8 : 1;
        unsigned int iomcu_clkstat0_9spi9 : 1;
        unsigned int iomcu_clkstat0_10spi0 : 1;
        unsigned int iomcu_clkstat0_11uart3 : 1;
        unsigned int iomcu_clkstat0_12uart7 : 1;
        unsigned int iomcu_clkstat0_13spi10 : 1;
        unsigned int iomcu_clkstat0_14fclk_mcu : 1;
        unsigned int iomcu_clkstat0_15clk_mcu : 1;
        unsigned int iomcu_clkstat0_16clk_etm : 1;
        unsigned int iomcu_clkstat0_17aclk_mcu : 1;
        unsigned int iomcu_clkstat0_18hclk_mcu : 1;
        unsigned int iomcu_clkstat0_19clk_fll : 1;
        unsigned int iomcu_clkstat0_20clk_ppll0 : 1;
        unsigned int iomcu_clkstat0_21clk_dapb : 1;
        unsigned int iomcu_clkstat0_22clk_atb : 1;
        unsigned int iomcu_clkstat0_23pclk_rtc : 1;
        unsigned int iomcu_clkstat0_24clk_ctm : 1;
        unsigned int iomcu_clkstat0_25clk_tcxo_in : 1;
        unsigned int iomcu_clkstat0_26i2c5 : 1;
        unsigned int iomcu_clkstat0_27i3c2 : 1;
        unsigned int iomcu_clkstat0_28tcm : 1;
        unsigned int iomcu_clkstat0_29ao_bus : 1;
        unsigned int iomcu_clkstat0_30spi2 : 1;
        unsigned int iomcu_clkstat0_31uart8 : 1;
    } reg;
} SOC_IOMCU_CLKSTAT0_UNION;
#endif
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_0dmac_START (0)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_0dmac_END (0)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_lwdt_START (1)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_lwdt_END (1)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_2timer_START (2)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_2timer_END (2)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_3i2c0_START (3)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_3i2c0_END (3)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_4i2c1_START (4)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_4i2c1_END (4)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_5i3c1_START (5)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_5i3c1_END (5)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_6gpio_START (6)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_6gpio_END (6)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_7spi4_START (7)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_7spi4_END (7)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_8spi8_START (8)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_8spi8_END (8)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_9spi9_START (9)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_9spi9_END (9)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_10spi0_START (10)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_10spi0_END (10)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_11uart3_START (11)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_11uart3_END (11)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_12uart7_START (12)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_12uart7_END (12)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_13spi10_START (13)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_13spi10_END (13)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_14fclk_mcu_START (14)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_14fclk_mcu_END (14)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_15clk_mcu_START (15)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_15clk_mcu_END (15)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_16clk_etm_START (16)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_16clk_etm_END (16)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_17aclk_mcu_START (17)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_17aclk_mcu_END (17)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_18hclk_mcu_START (18)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_18hclk_mcu_END (18)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_19clk_fll_START (19)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_19clk_fll_END (19)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_20clk_ppll0_START (20)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_20clk_ppll0_END (20)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_21clk_dapb_START (21)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_21clk_dapb_END (21)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_22clk_atb_START (22)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_22clk_atb_END (22)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_23pclk_rtc_START (23)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_23pclk_rtc_END (23)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_24clk_ctm_START (24)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_24clk_ctm_END (24)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_25clk_tcxo_in_START (25)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_25clk_tcxo_in_END (25)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_26i2c5_START (26)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_26i2c5_END (26)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_27i3c2_START (27)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_27i3c2_END (27)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_28tcm_START (28)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_28tcm_END (28)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_29ao_bus_START (29)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_29ao_bus_END (29)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_30spi2_START (30)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_30spi2_END (30)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_31uart8_START (31)
#define SOC_IOMCU_CLKSTAT0_iomcu_clkstat0_31uart8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_rsten0_0dma : 1;
        unsigned int iomcu_rsten0_1wdt : 1;
        unsigned int iomcu_rsten0_2timer : 1;
        unsigned int iomcu_rsten0_3i2c0 : 1;
        unsigned int iomcu_rsten0_3i2c1 : 1;
        unsigned int iomcu_rsten0_5i3c1 : 1;
        unsigned int iomcu_rsten0_6gpio : 1;
        unsigned int iomcu_rsten0_7spi4 : 1;
        unsigned int iomcu_rsten0_8spi8 : 1;
        unsigned int iomcu_rsten0_9ftimer1 : 1;
        unsigned int iomcu_rsten0_10spi0 : 1;
        unsigned int iomcu_rsten0_11uart3 : 1;
        unsigned int iomcu_rsten0_12uart7 : 1;
        unsigned int reserved : 1;
        unsigned int iomcu_rsten0_14mcu_sys : 1;
        unsigned int iomcu_rsten0_15mcu_etm : 1;
        unsigned int iomcu_rsten0_16dmmu : 1;
        unsigned int iomcu_rsten0_17ftimer0 : 1;
        unsigned int iomcu_rsten0_18i2c5 : 1;
        unsigned int iomcu_rsten0_19tcm : 1;
        unsigned int iomcu_rsten0_20p2j : 1;
        unsigned int iomcu_rsten0_21dapb : 1;
        unsigned int iomcu_rsten0_22atb : 1;
        unsigned int iomcu_rsten0_23rtc : 1;
        unsigned int iomcu_rsten0_24ctm : 1;
        unsigned int iomcu_rsten0_25i2c8 : 1;
        unsigned int iomcu_rsten0_26_p_tcp : 1;
        unsigned int iomcu_rsten0_27i3c2 : 1;
        unsigned int iomcu_rsten0_28i3c3 : 1;
        unsigned int iomcu_rsten0_29i3c0 : 1;
        unsigned int iomcu_rsten0_30spi2 : 1;
        unsigned int iomcu_rsten0_31uart8 : 1;
    } reg;
} SOC_IOMCU_RSTEN0_UNION;
#endif
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_0dma_START (0)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_0dma_END (0)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_1wdt_START (1)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_1wdt_END (1)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_2timer_START (2)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_2timer_END (2)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_3i2c0_START (3)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_3i2c0_END (3)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_3i2c1_START (4)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_3i2c1_END (4)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_5i3c1_START (5)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_5i3c1_END (5)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_6gpio_START (6)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_6gpio_END (6)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_7spi4_START (7)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_7spi4_END (7)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_8spi8_START (8)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_8spi8_END (8)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_9ftimer1_START (9)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_9ftimer1_END (9)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_10spi0_START (10)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_10spi0_END (10)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_11uart3_START (11)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_11uart3_END (11)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_12uart7_START (12)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_12uart7_END (12)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_14mcu_sys_START (14)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_14mcu_sys_END (14)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_15mcu_etm_START (15)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_15mcu_etm_END (15)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_16dmmu_START (16)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_16dmmu_END (16)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_17ftimer0_START (17)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_17ftimer0_END (17)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_18i2c5_START (18)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_18i2c5_END (18)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_19tcm_START (19)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_19tcm_END (19)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_20p2j_START (20)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_20p2j_END (20)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_21dapb_START (21)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_21dapb_END (21)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_22atb_START (22)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_22atb_END (22)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_23rtc_START (23)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_23rtc_END (23)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_24ctm_START (24)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_24ctm_END (24)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_25i2c8_START (25)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_25i2c8_END (25)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_26_p_tcp_START (26)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_26_p_tcp_END (26)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_27i3c2_START (27)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_27i3c2_END (27)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_28i3c3_START (28)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_28i3c3_END (28)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_29i3c0_START (29)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_29i3c0_END (29)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_30spi2_START (30)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_30spi2_END (30)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_31uart8_START (31)
#define SOC_IOMCU_RSTEN0_iomcu_rsten0_31uart8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_rstdis0_0dma : 1;
        unsigned int iomcu_rstdis0_1wdt : 1;
        unsigned int iomcu_rstdis0_2timer : 1;
        unsigned int iomcu_rstdis0_3i2c0 : 1;
        unsigned int iomcu_rstdis0_3i2c1 : 1;
        unsigned int iomcu_rstdis0_5i3c1 : 1;
        unsigned int iomcu_rstdis0_6gpio : 1;
        unsigned int iomcu_rstdis0_7spi4 : 1;
        unsigned int iomcu_rstdis0_8spi8 : 1;
        unsigned int iomcu_rstdis0_9ftimer1 : 1;
        unsigned int iomcu_rstdis0_10spi0 : 1;
        unsigned int iomcu_rstdis0_11uart3 : 1;
        unsigned int iomcu_rstdis0_12uart7 : 1;
        unsigned int reserved : 1;
        unsigned int iomcu_rstdis0_14mcu_sys : 1;
        unsigned int iomcu_rstdis0_15mcu_etm : 1;
        unsigned int iomcu_rstdis0_16dmmu : 1;
        unsigned int iomcu_rstdis0_17ftimer0 : 1;
        unsigned int iomcu_rstdis0_18i2c5 : 1;
        unsigned int iomcu_rstdis0_19tcm : 1;
        unsigned int iomcu_rstdis0_20p2j : 1;
        unsigned int iomcu_rstdis0_21dapb : 1;
        unsigned int iomcu_rstdis0_22atb : 1;
        unsigned int iomcu_rstdis0_23rtc : 1;
        unsigned int iomcu_rstdis0_24ctm : 1;
        unsigned int iomcu_rstdis0_25i2c8 : 1;
        unsigned int iomcu_rstdis0_26_p_tcp : 1;
        unsigned int iomcu_rstdis0_27i3c2 : 1;
        unsigned int iomcu_rstdis0_28i3c3 : 1;
        unsigned int iomcu_rstdis0_29i3c0 : 1;
        unsigned int iomcu_rstdis0_30spi2 : 1;
        unsigned int iomcu_rstdis0_31uart8 : 1;
    } reg;
} SOC_IOMCU_RSTDIS0_UNION;
#endif
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_0dma_START (0)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_0dma_END (0)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_1wdt_START (1)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_1wdt_END (1)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_2timer_START (2)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_2timer_END (2)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_3i2c0_START (3)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_3i2c0_END (3)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_3i2c1_START (4)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_3i2c1_END (4)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_5i3c1_START (5)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_5i3c1_END (5)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_6gpio_START (6)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_6gpio_END (6)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_7spi4_START (7)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_7spi4_END (7)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_8spi8_START (8)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_8spi8_END (8)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_9ftimer1_START (9)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_9ftimer1_END (9)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_10spi0_START (10)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_10spi0_END (10)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_11uart3_START (11)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_11uart3_END (11)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_12uart7_START (12)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_12uart7_END (12)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_14mcu_sys_START (14)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_14mcu_sys_END (14)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_15mcu_etm_START (15)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_15mcu_etm_END (15)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_16dmmu_START (16)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_16dmmu_END (16)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_17ftimer0_START (17)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_17ftimer0_END (17)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_18i2c5_START (18)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_18i2c5_END (18)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_19tcm_START (19)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_19tcm_END (19)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_20p2j_START (20)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_20p2j_END (20)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_21dapb_START (21)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_21dapb_END (21)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_22atb_START (22)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_22atb_END (22)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_23rtc_START (23)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_23rtc_END (23)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_24ctm_START (24)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_24ctm_END (24)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_25i2c8_START (25)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_25i2c8_END (25)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_26_p_tcp_START (26)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_26_p_tcp_END (26)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_27i3c2_START (27)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_27i3c2_END (27)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_28i3c3_START (28)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_28i3c3_END (28)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_29i3c0_START (29)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_29i3c0_END (29)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_30spi2_START (30)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_30spi2_END (30)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_31uart8_START (31)
#define SOC_IOMCU_RSTDIS0_iomcu_rstdis0_31uart8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_rststats0_0dma : 1;
        unsigned int iomcu_rststats0_1wdt : 1;
        unsigned int iomcu_rststats0_2timer : 1;
        unsigned int iomcu_rststats0_3i2c0 : 1;
        unsigned int iomcu_rststats0_3i2c1 : 1;
        unsigned int iomcu_rststats0_5i3c1 : 1;
        unsigned int iomcu_rststats0_6gpio : 1;
        unsigned int iomcu_rststats0_7spi4 : 1;
        unsigned int iomcu_rststats0_8spi8 : 1;
        unsigned int iomcu_rststats0_9ftimer1 : 1;
        unsigned int iomcu_rststats0_10spi0 : 1;
        unsigned int iomcu_rststats0_11uart3 : 1;
        unsigned int iomcu_rststats0_12uart7 : 1;
        unsigned int reserved : 1;
        unsigned int iomcu_rststats0_14mcu_sys : 1;
        unsigned int iomcu_rststats0_15mcu_etm : 1;
        unsigned int iomcu_rststats0_16dmmu : 1;
        unsigned int iomcu_rststats0_17ftimer0 : 1;
        unsigned int iomcu_rststats0_18i2c5 : 1;
        unsigned int iomcu_rststats0_19tcm : 1;
        unsigned int iomcu_rststats0_20p2j : 1;
        unsigned int iomcu_rststats0_21dapb : 1;
        unsigned int iomcu_rststats0_22atb : 1;
        unsigned int iomcu_rststats0_23rtc : 1;
        unsigned int iomcu_rststats0_24ctm : 1;
        unsigned int iomcu_rststats0_25i2c8 : 1;
        unsigned int iomcu_rststats0_26_p_tcp : 1;
        unsigned int iomcu_rststats0_27i3c2 : 1;
        unsigned int iomcu_rststats0_28i3c3 : 1;
        unsigned int iomcu_rststats0_29i3c0 : 1;
        unsigned int iomcu_rststats0_30spi2 : 1;
        unsigned int iomcu_rststat0_31uart8 : 1;
    } reg;
} SOC_IOMCU_RSTSTAT0_UNION;
#endif
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_0dma_START (0)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_0dma_END (0)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_1wdt_START (1)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_1wdt_END (1)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_2timer_START (2)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_2timer_END (2)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_3i2c0_START (3)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_3i2c0_END (3)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_3i2c1_START (4)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_3i2c1_END (4)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_5i3c1_START (5)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_5i3c1_END (5)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_6gpio_START (6)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_6gpio_END (6)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_7spi4_START (7)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_7spi4_END (7)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_8spi8_START (8)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_8spi8_END (8)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_9ftimer1_START (9)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_9ftimer1_END (9)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_10spi0_START (10)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_10spi0_END (10)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_11uart3_START (11)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_11uart3_END (11)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_12uart7_START (12)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_12uart7_END (12)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_14mcu_sys_START (14)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_14mcu_sys_END (14)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_15mcu_etm_START (15)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_15mcu_etm_END (15)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_16dmmu_START (16)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_16dmmu_END (16)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_17ftimer0_START (17)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_17ftimer0_END (17)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_18i2c5_START (18)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_18i2c5_END (18)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_19tcm_START (19)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_19tcm_END (19)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_20p2j_START (20)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_20p2j_END (20)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_21dapb_START (21)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_21dapb_END (21)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_22atb_START (22)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_22atb_END (22)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_23rtc_START (23)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_23rtc_END (23)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_24ctm_START (24)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_24ctm_END (24)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_25i2c8_START (25)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_25i2c8_END (25)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_26_p_tcp_START (26)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_26_p_tcp_END (26)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_27i3c2_START (27)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_27i3c2_END (27)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_28i3c3_START (28)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_28i3c3_END (28)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_29i3c0_START (29)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_29i3c0_END (29)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_30spi2_START (30)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststats0_30spi2_END (30)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststat0_31uart8_START (31)
#define SOC_IOMCU_RSTSTAT0_iomcu_rststat0_31uart8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_wait : 1;
        unsigned int hclken_sleeping_bypass : 1;
        unsigned int hifi_dtcm_remap_bypass : 1;
        unsigned int ocram_remap_bypass : 1;
        unsigned int cpu_initvtor : 25;
        unsigned int ahbs_ready_error_clr : 1;
        unsigned int cfg_bigend : 1;
        unsigned int cpu_iadbgprot : 1;
    } reg;
} SOC_IOMCU_M7_CFG0_UNION;
#endif
#define SOC_IOMCU_M7_CFG0_cpu_wait_START (0)
#define SOC_IOMCU_M7_CFG0_cpu_wait_END (0)
#define SOC_IOMCU_M7_CFG0_hclken_sleeping_bypass_START (1)
#define SOC_IOMCU_M7_CFG0_hclken_sleeping_bypass_END (1)
#define SOC_IOMCU_M7_CFG0_hifi_dtcm_remap_bypass_START (2)
#define SOC_IOMCU_M7_CFG0_hifi_dtcm_remap_bypass_END (2)
#define SOC_IOMCU_M7_CFG0_ocram_remap_bypass_START (3)
#define SOC_IOMCU_M7_CFG0_ocram_remap_bypass_END (3)
#define SOC_IOMCU_M7_CFG0_cpu_initvtor_START (4)
#define SOC_IOMCU_M7_CFG0_cpu_initvtor_END (28)
#define SOC_IOMCU_M7_CFG0_ahbs_ready_error_clr_START (29)
#define SOC_IOMCU_M7_CFG0_ahbs_ready_error_clr_END (29)
#define SOC_IOMCU_M7_CFG0_cfg_bigend_START (30)
#define SOC_IOMCU_M7_CFG0_cfg_bigend_END (30)
#define SOC_IOMCU_M7_CFG0_cpu_iadbgprot_START (31)
#define SOC_IOMCU_M7_CFG0_cpu_iadbgprot_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cfgstcalib_cycclecnt : 24;
        unsigned int cfgstcalib_precision : 1;
        unsigned int cfgstcalib_ticken : 1;
        unsigned int halt_bypass : 1;
        unsigned int hack_remap_bypass : 1;
        unsigned int mmbuf_remap_bypass : 1;
        unsigned int aclken_sleeping_bypass : 1;
        unsigned int deepsleeping_bypass : 1;
        unsigned int clken_sleeping_bypass : 1;
    } reg;
} SOC_IOMCU_M7_CFG1_UNION;
#endif
#define SOC_IOMCU_M7_CFG1_cfgstcalib_cycclecnt_START (0)
#define SOC_IOMCU_M7_CFG1_cfgstcalib_cycclecnt_END (23)
#define SOC_IOMCU_M7_CFG1_cfgstcalib_precision_START (24)
#define SOC_IOMCU_M7_CFG1_cfgstcalib_precision_END (24)
#define SOC_IOMCU_M7_CFG1_cfgstcalib_ticken_START (25)
#define SOC_IOMCU_M7_CFG1_cfgstcalib_ticken_END (25)
#define SOC_IOMCU_M7_CFG1_halt_bypass_START (26)
#define SOC_IOMCU_M7_CFG1_halt_bypass_END (26)
#define SOC_IOMCU_M7_CFG1_hack_remap_bypass_START (27)
#define SOC_IOMCU_M7_CFG1_hack_remap_bypass_END (27)
#define SOC_IOMCU_M7_CFG1_mmbuf_remap_bypass_START (28)
#define SOC_IOMCU_M7_CFG1_mmbuf_remap_bypass_END (28)
#define SOC_IOMCU_M7_CFG1_aclken_sleeping_bypass_START (29)
#define SOC_IOMCU_M7_CFG1_aclken_sleeping_bypass_END (29)
#define SOC_IOMCU_M7_CFG1_deepsleeping_bypass_START (30)
#define SOC_IOMCU_M7_CFG1_deepsleeping_bypass_END (30)
#define SOC_IOMCU_M7_CFG1_clken_sleeping_bypass_START (31)
#define SOC_IOMCU_M7_CFG1_clken_sleeping_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int m7_iaddr_stat : 29;
        unsigned int ahbs_ready_error_stat : 1;
        unsigned int cpu_halt_stat : 1;
        unsigned int cpu_lockup : 1;
    } reg;
} SOC_IOMCU_M7_STAT0_UNION;
#endif
#define SOC_IOMCU_M7_STAT0_m7_iaddr_stat_START (0)
#define SOC_IOMCU_M7_STAT0_m7_iaddr_stat_END (28)
#define SOC_IOMCU_M7_STAT0_ahbs_ready_error_stat_START (29)
#define SOC_IOMCU_M7_STAT0_ahbs_ready_error_stat_END (29)
#define SOC_IOMCU_M7_STAT0_cpu_halt_stat_START (30)
#define SOC_IOMCU_M7_STAT0_cpu_halt_stat_END (30)
#define SOC_IOMCU_M7_STAT0_cpu_lockup_START (31)
#define SOC_IOMCU_M7_STAT0_cpu_lockup_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int m7_sleeping_stat : 1;
        unsigned int m7_deepsleeping_stat : 1;
        unsigned int m7_ahbs_ready_stat : 1;
        unsigned int m7_tcp_ahb_wr_bypass : 1;
        unsigned int m7_tcp_ahb_rd_bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int m7_sc_stat : 9;
        unsigned int m7_etmpwrupreq : 1;
        unsigned int check_enable : 1;
        unsigned int sys_sleep_mode_r : 3;
        unsigned int nmi_ack : 1;
        unsigned int check_addr_clr : 1;
        unsigned int core_async_excp_hdlr : 1;
        unsigned int core_nmi_hdlr : 1;
        unsigned int reserved_4 : 5;
    } reg;
} SOC_IOMCU_M7_STAT1_UNION;
#endif
#define SOC_IOMCU_M7_STAT1_m7_sleeping_stat_START (0)
#define SOC_IOMCU_M7_STAT1_m7_sleeping_stat_END (0)
#define SOC_IOMCU_M7_STAT1_m7_deepsleeping_stat_START (1)
#define SOC_IOMCU_M7_STAT1_m7_deepsleeping_stat_END (1)
#define SOC_IOMCU_M7_STAT1_m7_ahbs_ready_stat_START (2)
#define SOC_IOMCU_M7_STAT1_m7_ahbs_ready_stat_END (2)
#define SOC_IOMCU_M7_STAT1_m7_tcp_ahb_wr_bypass_START (3)
#define SOC_IOMCU_M7_STAT1_m7_tcp_ahb_wr_bypass_END (3)
#define SOC_IOMCU_M7_STAT1_m7_tcp_ahb_rd_bypass_START (4)
#define SOC_IOMCU_M7_STAT1_m7_tcp_ahb_rd_bypass_END (4)
#define SOC_IOMCU_M7_STAT1_m7_sc_stat_START (9)
#define SOC_IOMCU_M7_STAT1_m7_sc_stat_END (17)
#define SOC_IOMCU_M7_STAT1_m7_etmpwrupreq_START (18)
#define SOC_IOMCU_M7_STAT1_m7_etmpwrupreq_END (18)
#define SOC_IOMCU_M7_STAT1_check_enable_START (19)
#define SOC_IOMCU_M7_STAT1_check_enable_END (19)
#define SOC_IOMCU_M7_STAT1_sys_sleep_mode_r_START (20)
#define SOC_IOMCU_M7_STAT1_sys_sleep_mode_r_END (22)
#define SOC_IOMCU_M7_STAT1_nmi_ack_START (23)
#define SOC_IOMCU_M7_STAT1_nmi_ack_END (23)
#define SOC_IOMCU_M7_STAT1_check_addr_clr_START (24)
#define SOC_IOMCU_M7_STAT1_check_addr_clr_END (24)
#define SOC_IOMCU_M7_STAT1_core_async_excp_hdlr_START (25)
#define SOC_IOMCU_M7_STAT1_core_async_excp_hdlr_END (25)
#define SOC_IOMCU_M7_STAT1_core_nmi_hdlr_START (26)
#define SOC_IOMCU_M7_STAT1_core_nmi_hdlr_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_IOMCU_DDR_ACCESS_WINDOW0_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mmbuf_access_window : 32;
    } reg;
} SOC_IOMCU_MMBUF_ACCESS_WINDOW_UNION;
#endif
#define SOC_IOMCU_MMBUF_ACCESS_WINDOW_mmbuf_access_window_START (0)
#define SOC_IOMCU_MMBUF_ACCESS_WINDOW_mmbuf_access_window_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hack_access_window : 32;
    } reg;
} SOC_IOMCU_HACK_ACCESS_WINDOW_UNION;
#endif
#define SOC_IOMCU_HACK_ACCESS_WINDOW_hack_access_window_START (0)
#define SOC_IOMCU_HACK_ACCESS_WINDOW_hack_access_window_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bypass_for_watchdog : 1;
        unsigned int bypass_for_timer : 1;
        unsigned int bypass_for_spi0 : 1;
        unsigned int bypass_for_gpio : 1;
        unsigned int bypass_for_spi4 : 1;
        unsigned int bypass_for_spi8 : 1;
        unsigned int bypass_for_ftimer1 : 1;
        unsigned int bypass_for_i2c0 : 1;
        unsigned int bypass_for_i2c1 : 1;
        unsigned int bypass_for_i3c1 : 1;
        unsigned int bypass_for_uart3 : 1;
        unsigned int reserved_0 : 1;
        unsigned int bypass_for_uart7 : 1;
        unsigned int bypass_for_dma : 1;
        unsigned int bypass_for_rtc : 1;
        unsigned int bypass_for_i3c2 : 1;
        unsigned int bypass_for_i2c10 : 1;
        unsigned int bypass_for_spi2 : 1;
        unsigned int bypass_for_i2c5 : 1;
        unsigned int bypass_for_dmmu : 1;
        unsigned int bypass_for_ftimer0 : 1;
        unsigned int bypass_for_i3c0 : 1;
        unsigned int bypass_for_i2c11 : 1;
        unsigned int bypass_for_i3c3 : 1;
        unsigned int bypass_for_tcm : 1;
        unsigned int bypass_for_i2c8 : 1;
        unsigned int bypass_for_p2j : 1;
        unsigned int bypass_for_hts_adp_mst : 1;
        unsigned int bypass_for_hts_adp_slv : 1;
        unsigned int bypass_for_spi9 : 1;
        unsigned int bypass_for_spi10 : 1;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_IOMCU_DLOCK_BYPASS_UNION;
#endif
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_watchdog_START (0)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_watchdog_END (0)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_timer_START (1)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_timer_END (1)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_spi0_START (2)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_spi0_END (2)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_gpio_START (3)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_gpio_END (3)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_spi4_START (4)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_spi4_END (4)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_spi8_START (5)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_spi8_END (5)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_ftimer1_START (6)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_ftimer1_END (6)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i2c0_START (7)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i2c0_END (7)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i2c1_START (8)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i2c1_END (8)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i3c1_START (9)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i3c1_END (9)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_uart3_START (10)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_uart3_END (10)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_uart7_START (12)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_uart7_END (12)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_dma_START (13)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_dma_END (13)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_rtc_START (14)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_rtc_END (14)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i3c2_START (15)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i3c2_END (15)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i2c10_START (16)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i2c10_END (16)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_spi2_START (17)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_spi2_END (17)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i2c5_START (18)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i2c5_END (18)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_dmmu_START (19)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_dmmu_END (19)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_ftimer0_START (20)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_ftimer0_END (20)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i3c0_START (21)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i3c0_END (21)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i2c11_START (22)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i2c11_END (22)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i3c3_START (23)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i3c3_END (23)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_tcm_START (24)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_tcm_END (24)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i2c8_START (25)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_i2c8_END (25)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_p2j_START (26)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_p2j_END (26)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_hts_adp_mst_START (27)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_hts_adp_mst_END (27)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_hts_adp_slv_START (28)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_hts_adp_slv_END (28)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_spi9_START (29)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_spi9_END (29)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_spi10_START (30)
#define SOC_IOMCU_DLOCK_BYPASS_bypass_for_spi10_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_bank0 : 3;
        unsigned int mem_ctrl_bank1 : 3;
        unsigned int mem_ctrl_bank2 : 3;
        unsigned int mem_ctrl_bank3 : 3;
        unsigned int mem_ctrl_bank4 : 3;
        unsigned int mem_ctrl_bank5 : 3;
        unsigned int mem_ctrl_bank6 : 3;
        unsigned int mem_ctrl_icache : 3;
        unsigned int mem_ctrl_dcache : 3;
        unsigned int reserved_0 : 1;
        unsigned int mem_ctrl_map_table : 3;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_IOMCU_MEM_CTRL_PGT_UNION;
#endif
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_bank0_START (0)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_bank0_END (2)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_bank1_START (3)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_bank1_END (5)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_bank2_START (6)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_bank2_END (8)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_bank3_START (9)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_bank3_END (11)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_bank4_START (12)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_bank4_END (14)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_bank5_START (15)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_bank5_END (17)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_bank6_START (18)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_bank6_END (20)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_icache_START (21)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_icache_END (23)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_dcache_START (24)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_dcache_END (26)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_map_table_START (28)
#define SOC_IOMCU_MEM_CTRL_PGT_mem_ctrl_map_table_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_bank7 : 3;
        unsigned int mem_ctrl_bank8 : 3;
        unsigned int mem_ctrl_bank9 : 3;
        unsigned int mem_ctrl_bank10 : 3;
        unsigned int mem_ctrl_bank11 : 3;
        unsigned int mem_ctrl_bank12 : 3;
        unsigned int mem_ctrl_bank13 : 3;
        unsigned int mem_ctrl_bank14 : 3;
        unsigned int mem_ctrl_bank15 : 3;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 2;
    } reg;
} SOC_IOMCU_MEM_CTRL_0_UNION;
#endif
#define SOC_IOMCU_MEM_CTRL_0_mem_ctrl_bank7_START (0)
#define SOC_IOMCU_MEM_CTRL_0_mem_ctrl_bank7_END (2)
#define SOC_IOMCU_MEM_CTRL_0_mem_ctrl_bank8_START (3)
#define SOC_IOMCU_MEM_CTRL_0_mem_ctrl_bank8_END (5)
#define SOC_IOMCU_MEM_CTRL_0_mem_ctrl_bank9_START (6)
#define SOC_IOMCU_MEM_CTRL_0_mem_ctrl_bank9_END (8)
#define SOC_IOMCU_MEM_CTRL_0_mem_ctrl_bank10_START (9)
#define SOC_IOMCU_MEM_CTRL_0_mem_ctrl_bank10_END (11)
#define SOC_IOMCU_MEM_CTRL_0_mem_ctrl_bank11_START (12)
#define SOC_IOMCU_MEM_CTRL_0_mem_ctrl_bank11_END (14)
#define SOC_IOMCU_MEM_CTRL_0_mem_ctrl_bank12_START (15)
#define SOC_IOMCU_MEM_CTRL_0_mem_ctrl_bank12_END (17)
#define SOC_IOMCU_MEM_CTRL_0_mem_ctrl_bank13_START (18)
#define SOC_IOMCU_MEM_CTRL_0_mem_ctrl_bank13_END (20)
#define SOC_IOMCU_MEM_CTRL_0_mem_ctrl_bank14_START (21)
#define SOC_IOMCU_MEM_CTRL_0_mem_ctrl_bank14_END (23)
#define SOC_IOMCU_MEM_CTRL_0_mem_ctrl_bank15_START (24)
#define SOC_IOMCU_MEM_CTRL_0_mem_ctrl_bank15_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sys_stat : 4;
        unsigned int reserved_0 : 2;
        unsigned int gt_clk_mmbuf : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 2;
        unsigned int reserved_4 : 4;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 4;
        unsigned int reserved_7 : 4;
        unsigned int reserved_8 : 8;
    } reg;
} SOC_IOMCU_SYS_STAT_UNION;
#endif
#define SOC_IOMCU_SYS_STAT_sys_stat_START (0)
#define SOC_IOMCU_SYS_STAT_sys_stat_END (3)
#define SOC_IOMCU_SYS_STAT_gt_clk_mmbuf_START (6)
#define SOC_IOMCU_SYS_STAT_gt_clk_mmbuf_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sleep_mode : 1;
        unsigned int ppll0_en : 1;
        unsigned int fll_en : 1;
        unsigned int auto_cksel_dmmu : 1;
        unsigned int auto_cksel_iomcu : 1;
        unsigned int reserved_0 : 1;
        unsigned int iomcu_sclk_sw2fll_req : 1;
        unsigned int iomcu_fll_ctrl : 5;
        unsigned int reserved_1 : 1;
        unsigned int pclkdbg_en : 1;
        unsigned int txev : 1;
        unsigned int req_out_en : 1;
        unsigned int atclken : 1;
        unsigned int iomcu_logic_low_req : 1;
        unsigned int iomcu_sram_low_req : 1;
        unsigned int tcmerr_nmi_en : 1;
        unsigned int fll_vote_gt_hard_by : 1;
        unsigned int iomcu_fll_vote_gt : 1;
        unsigned int iomcu_fll_vote_en : 1;
        unsigned int iomcu_fll_vote_bp : 1;
        unsigned int reserved_2 : 8;
    } reg;
} SOC_IOMCU_SYS_CONFIG_UNION;
#endif
#define SOC_IOMCU_SYS_CONFIG_sleep_mode_START (0)
#define SOC_IOMCU_SYS_CONFIG_sleep_mode_END (0)
#define SOC_IOMCU_SYS_CONFIG_ppll0_en_START (1)
#define SOC_IOMCU_SYS_CONFIG_ppll0_en_END (1)
#define SOC_IOMCU_SYS_CONFIG_fll_en_START (2)
#define SOC_IOMCU_SYS_CONFIG_fll_en_END (2)
#define SOC_IOMCU_SYS_CONFIG_auto_cksel_dmmu_START (3)
#define SOC_IOMCU_SYS_CONFIG_auto_cksel_dmmu_END (3)
#define SOC_IOMCU_SYS_CONFIG_auto_cksel_iomcu_START (4)
#define SOC_IOMCU_SYS_CONFIG_auto_cksel_iomcu_END (4)
#define SOC_IOMCU_SYS_CONFIG_iomcu_sclk_sw2fll_req_START (6)
#define SOC_IOMCU_SYS_CONFIG_iomcu_sclk_sw2fll_req_END (6)
#define SOC_IOMCU_SYS_CONFIG_iomcu_fll_ctrl_START (7)
#define SOC_IOMCU_SYS_CONFIG_iomcu_fll_ctrl_END (11)
#define SOC_IOMCU_SYS_CONFIG_pclkdbg_en_START (13)
#define SOC_IOMCU_SYS_CONFIG_pclkdbg_en_END (13)
#define SOC_IOMCU_SYS_CONFIG_txev_START (14)
#define SOC_IOMCU_SYS_CONFIG_txev_END (14)
#define SOC_IOMCU_SYS_CONFIG_req_out_en_START (15)
#define SOC_IOMCU_SYS_CONFIG_req_out_en_END (15)
#define SOC_IOMCU_SYS_CONFIG_atclken_START (16)
#define SOC_IOMCU_SYS_CONFIG_atclken_END (16)
#define SOC_IOMCU_SYS_CONFIG_iomcu_logic_low_req_START (17)
#define SOC_IOMCU_SYS_CONFIG_iomcu_logic_low_req_END (17)
#define SOC_IOMCU_SYS_CONFIG_iomcu_sram_low_req_START (18)
#define SOC_IOMCU_SYS_CONFIG_iomcu_sram_low_req_END (18)
#define SOC_IOMCU_SYS_CONFIG_tcmerr_nmi_en_START (19)
#define SOC_IOMCU_SYS_CONFIG_tcmerr_nmi_en_END (19)
#define SOC_IOMCU_SYS_CONFIG_fll_vote_gt_hard_by_START (20)
#define SOC_IOMCU_SYS_CONFIG_fll_vote_gt_hard_by_END (20)
#define SOC_IOMCU_SYS_CONFIG_iomcu_fll_vote_gt_START (21)
#define SOC_IOMCU_SYS_CONFIG_iomcu_fll_vote_gt_END (21)
#define SOC_IOMCU_SYS_CONFIG_iomcu_fll_vote_en_START (22)
#define SOC_IOMCU_SYS_CONFIG_iomcu_fll_vote_en_END (22)
#define SOC_IOMCU_SYS_CONFIG_iomcu_fll_vote_bp_START (23)
#define SOC_IOMCU_SYS_CONFIG_iomcu_fll_vote_bp_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wakeup_en : 1;
        unsigned int soft_int_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_IOMCU_WAKEUP_EN_UNION;
#endif
#define SOC_IOMCU_WAKEUP_EN_wakeup_en_START (0)
#define SOC_IOMCU_WAKEUP_EN_wakeup_en_END (0)
#define SOC_IOMCU_WAKEUP_EN_soft_int_en_START (1)
#define SOC_IOMCU_WAKEUP_EN_soft_int_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wakeup_clr : 1;
        unsigned int soft_int_clr : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_IOMCU_WAKEUP_CLR_UNION;
#endif
#define SOC_IOMCU_WAKEUP_CLR_wakeup_clr_START (0)
#define SOC_IOMCU_WAKEUP_CLR_wakeup_clr_END (0)
#define SOC_IOMCU_WAKEUP_CLR_soft_int_clr_START (1)
#define SOC_IOMCU_WAKEUP_CLR_soft_int_clr_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int wakeup_stat : 1;
        unsigned int soft_int_stat : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_IOMCU_WAKEUP_STAT_UNION;
#endif
#define SOC_IOMCU_WAKEUP_STAT_wakeup_stat_START (0)
#define SOC_IOMCU_WAKEUP_STAT_wakeup_stat_END (0)
#define SOC_IOMCU_WAKEUP_STAT_soft_int_stat_START (1)
#define SOC_IOMCU_WAKEUP_STAT_soft_int_stat_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gpio_int_raw : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int timer1_int_raw : 1;
        unsigned int timer2_int_raw : 1;
        unsigned int soft_int_raw : 1;
        unsigned int dsi0_int_raw : 1;
        unsigned int dsi1_int_raw : 1;
        unsigned int sys_wakeup_int_raw : 1;
        unsigned int sys_sleep_int_raw : 1;
        unsigned int dsi2_int_raw : 1;
        unsigned int ftimer0_1_int_raw : 1;
        unsigned int ftimer0_2_int_raw : 1;
        unsigned int intr_wakeup_swing_enter_req_raw : 1;
        unsigned int intr_wakeup_swing_exit_req_raw : 1;
        unsigned int intr_frame_data_sync_raw : 1;
        unsigned int intr_cnt_vsync_raw : 1;
        unsigned int ftimer1_1_int_raw : 1;
        unsigned int ftimer1_2_int_raw : 1;
        unsigned int reserved_3 : 12;
    } reg;
} SOC_IOMCU_COMB_INT_RAW_UNION;
#endif
#define SOC_IOMCU_COMB_INT_RAW_gpio_int_raw_START (0)
#define SOC_IOMCU_COMB_INT_RAW_gpio_int_raw_END (0)
#define SOC_IOMCU_COMB_INT_RAW_timer1_int_raw_START (4)
#define SOC_IOMCU_COMB_INT_RAW_timer1_int_raw_END (4)
#define SOC_IOMCU_COMB_INT_RAW_timer2_int_raw_START (5)
#define SOC_IOMCU_COMB_INT_RAW_timer2_int_raw_END (5)
#define SOC_IOMCU_COMB_INT_RAW_soft_int_raw_START (6)
#define SOC_IOMCU_COMB_INT_RAW_soft_int_raw_END (6)
#define SOC_IOMCU_COMB_INT_RAW_dsi0_int_raw_START (7)
#define SOC_IOMCU_COMB_INT_RAW_dsi0_int_raw_END (7)
#define SOC_IOMCU_COMB_INT_RAW_dsi1_int_raw_START (8)
#define SOC_IOMCU_COMB_INT_RAW_dsi1_int_raw_END (8)
#define SOC_IOMCU_COMB_INT_RAW_sys_wakeup_int_raw_START (9)
#define SOC_IOMCU_COMB_INT_RAW_sys_wakeup_int_raw_END (9)
#define SOC_IOMCU_COMB_INT_RAW_sys_sleep_int_raw_START (10)
#define SOC_IOMCU_COMB_INT_RAW_sys_sleep_int_raw_END (10)
#define SOC_IOMCU_COMB_INT_RAW_dsi2_int_raw_START (11)
#define SOC_IOMCU_COMB_INT_RAW_dsi2_int_raw_END (11)
#define SOC_IOMCU_COMB_INT_RAW_ftimer0_1_int_raw_START (12)
#define SOC_IOMCU_COMB_INT_RAW_ftimer0_1_int_raw_END (12)
#define SOC_IOMCU_COMB_INT_RAW_ftimer0_2_int_raw_START (13)
#define SOC_IOMCU_COMB_INT_RAW_ftimer0_2_int_raw_END (13)
#define SOC_IOMCU_COMB_INT_RAW_intr_wakeup_swing_enter_req_raw_START (14)
#define SOC_IOMCU_COMB_INT_RAW_intr_wakeup_swing_enter_req_raw_END (14)
#define SOC_IOMCU_COMB_INT_RAW_intr_wakeup_swing_exit_req_raw_START (15)
#define SOC_IOMCU_COMB_INT_RAW_intr_wakeup_swing_exit_req_raw_END (15)
#define SOC_IOMCU_COMB_INT_RAW_intr_frame_data_sync_raw_START (16)
#define SOC_IOMCU_COMB_INT_RAW_intr_frame_data_sync_raw_END (16)
#define SOC_IOMCU_COMB_INT_RAW_intr_cnt_vsync_raw_START (17)
#define SOC_IOMCU_COMB_INT_RAW_intr_cnt_vsync_raw_END (17)
#define SOC_IOMCU_COMB_INT_RAW_ftimer1_1_int_raw_START (18)
#define SOC_IOMCU_COMB_INT_RAW_ftimer1_1_int_raw_END (18)
#define SOC_IOMCU_COMB_INT_RAW_ftimer1_2_int_raw_START (19)
#define SOC_IOMCU_COMB_INT_RAW_ftimer1_2_int_raw_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gpio_int_msk : 1;
        unsigned int ftimer1_2_int_mask : 1;
        unsigned int ftimer1_1_int_mask : 1;
        unsigned int reserved : 1;
        unsigned int timer1_int_msk : 1;
        unsigned int timer2_int_msk : 1;
        unsigned int soft_int_msk : 1;
        unsigned int dsi0_int_msk : 1;
        unsigned int dsi1_int_msk : 1;
        unsigned int dsi0_int_clr : 1;
        unsigned int dsi1_int_clr : 1;
        unsigned int sys_wakeup_int_msk : 1;
        unsigned int sys_wakeup_int_clr : 1;
        unsigned int sys_sleep_int_msk : 1;
        unsigned int sys_sleep_int_clr : 1;
        unsigned int dsi2_int_msk : 1;
        unsigned int dsi2_int_clr : 1;
        unsigned int ftimer0_2_int_mask : 1;
        unsigned int ftimer0_1_int_mask : 1;
        unsigned int intr_wakeup_swing_enter_req_en : 1;
        unsigned int intr_wakeup_swing_exit_req_en : 1;
        unsigned int intr_wakeup_swing_enter_req_clr : 1;
        unsigned int intr_wakeup_swing_exit_req_clr : 1;
        unsigned int intr_wakeup_swing_enter_req_msk : 1;
        unsigned int intr_wakeup_swing_exit_req_msk : 1;
        unsigned int intr_frame_data_sync_clr : 1;
        unsigned int intr_frame_data_sync_msk : 1;
        unsigned int intr_cnt_vsync_clr : 1;
        unsigned int intr_cnt_vsync_msk : 1;
        unsigned int iomcu_tcm_err_int_clr : 1;
        unsigned int iomcu_tcm_err_int_msk : 1;
        unsigned int iomcu_tcm_err_int_en : 1;
    } reg;
} SOC_IOMCU_COMB_INT_MSK_UNION;
#endif
#define SOC_IOMCU_COMB_INT_MSK_gpio_int_msk_START (0)
#define SOC_IOMCU_COMB_INT_MSK_gpio_int_msk_END (0)
#define SOC_IOMCU_COMB_INT_MSK_ftimer1_2_int_mask_START (1)
#define SOC_IOMCU_COMB_INT_MSK_ftimer1_2_int_mask_END (1)
#define SOC_IOMCU_COMB_INT_MSK_ftimer1_1_int_mask_START (2)
#define SOC_IOMCU_COMB_INT_MSK_ftimer1_1_int_mask_END (2)
#define SOC_IOMCU_COMB_INT_MSK_timer1_int_msk_START (4)
#define SOC_IOMCU_COMB_INT_MSK_timer1_int_msk_END (4)
#define SOC_IOMCU_COMB_INT_MSK_timer2_int_msk_START (5)
#define SOC_IOMCU_COMB_INT_MSK_timer2_int_msk_END (5)
#define SOC_IOMCU_COMB_INT_MSK_soft_int_msk_START (6)
#define SOC_IOMCU_COMB_INT_MSK_soft_int_msk_END (6)
#define SOC_IOMCU_COMB_INT_MSK_dsi0_int_msk_START (7)
#define SOC_IOMCU_COMB_INT_MSK_dsi0_int_msk_END (7)
#define SOC_IOMCU_COMB_INT_MSK_dsi1_int_msk_START (8)
#define SOC_IOMCU_COMB_INT_MSK_dsi1_int_msk_END (8)
#define SOC_IOMCU_COMB_INT_MSK_dsi0_int_clr_START (9)
#define SOC_IOMCU_COMB_INT_MSK_dsi0_int_clr_END (9)
#define SOC_IOMCU_COMB_INT_MSK_dsi1_int_clr_START (10)
#define SOC_IOMCU_COMB_INT_MSK_dsi1_int_clr_END (10)
#define SOC_IOMCU_COMB_INT_MSK_sys_wakeup_int_msk_START (11)
#define SOC_IOMCU_COMB_INT_MSK_sys_wakeup_int_msk_END (11)
#define SOC_IOMCU_COMB_INT_MSK_sys_wakeup_int_clr_START (12)
#define SOC_IOMCU_COMB_INT_MSK_sys_wakeup_int_clr_END (12)
#define SOC_IOMCU_COMB_INT_MSK_sys_sleep_int_msk_START (13)
#define SOC_IOMCU_COMB_INT_MSK_sys_sleep_int_msk_END (13)
#define SOC_IOMCU_COMB_INT_MSK_sys_sleep_int_clr_START (14)
#define SOC_IOMCU_COMB_INT_MSK_sys_sleep_int_clr_END (14)
#define SOC_IOMCU_COMB_INT_MSK_dsi2_int_msk_START (15)
#define SOC_IOMCU_COMB_INT_MSK_dsi2_int_msk_END (15)
#define SOC_IOMCU_COMB_INT_MSK_dsi2_int_clr_START (16)
#define SOC_IOMCU_COMB_INT_MSK_dsi2_int_clr_END (16)
#define SOC_IOMCU_COMB_INT_MSK_ftimer0_2_int_mask_START (17)
#define SOC_IOMCU_COMB_INT_MSK_ftimer0_2_int_mask_END (17)
#define SOC_IOMCU_COMB_INT_MSK_ftimer0_1_int_mask_START (18)
#define SOC_IOMCU_COMB_INT_MSK_ftimer0_1_int_mask_END (18)
#define SOC_IOMCU_COMB_INT_MSK_intr_wakeup_swing_enter_req_en_START (19)
#define SOC_IOMCU_COMB_INT_MSK_intr_wakeup_swing_enter_req_en_END (19)
#define SOC_IOMCU_COMB_INT_MSK_intr_wakeup_swing_exit_req_en_START (20)
#define SOC_IOMCU_COMB_INT_MSK_intr_wakeup_swing_exit_req_en_END (20)
#define SOC_IOMCU_COMB_INT_MSK_intr_wakeup_swing_enter_req_clr_START (21)
#define SOC_IOMCU_COMB_INT_MSK_intr_wakeup_swing_enter_req_clr_END (21)
#define SOC_IOMCU_COMB_INT_MSK_intr_wakeup_swing_exit_req_clr_START (22)
#define SOC_IOMCU_COMB_INT_MSK_intr_wakeup_swing_exit_req_clr_END (22)
#define SOC_IOMCU_COMB_INT_MSK_intr_wakeup_swing_enter_req_msk_START (23)
#define SOC_IOMCU_COMB_INT_MSK_intr_wakeup_swing_enter_req_msk_END (23)
#define SOC_IOMCU_COMB_INT_MSK_intr_wakeup_swing_exit_req_msk_START (24)
#define SOC_IOMCU_COMB_INT_MSK_intr_wakeup_swing_exit_req_msk_END (24)
#define SOC_IOMCU_COMB_INT_MSK_intr_frame_data_sync_clr_START (25)
#define SOC_IOMCU_COMB_INT_MSK_intr_frame_data_sync_clr_END (25)
#define SOC_IOMCU_COMB_INT_MSK_intr_frame_data_sync_msk_START (26)
#define SOC_IOMCU_COMB_INT_MSK_intr_frame_data_sync_msk_END (26)
#define SOC_IOMCU_COMB_INT_MSK_intr_cnt_vsync_clr_START (27)
#define SOC_IOMCU_COMB_INT_MSK_intr_cnt_vsync_clr_END (27)
#define SOC_IOMCU_COMB_INT_MSK_intr_cnt_vsync_msk_START (28)
#define SOC_IOMCU_COMB_INT_MSK_intr_cnt_vsync_msk_END (28)
#define SOC_IOMCU_COMB_INT_MSK_iomcu_tcm_err_int_clr_START (29)
#define SOC_IOMCU_COMB_INT_MSK_iomcu_tcm_err_int_clr_END (29)
#define SOC_IOMCU_COMB_INT_MSK_iomcu_tcm_err_int_msk_START (30)
#define SOC_IOMCU_COMB_INT_MSK_iomcu_tcm_err_int_msk_END (30)
#define SOC_IOMCU_COMB_INT_MSK_iomcu_tcm_err_int_en_START (31)
#define SOC_IOMCU_COMB_INT_MSK_iomcu_tcm_err_int_en_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gpio_int_mskd : 1;
        unsigned int ftimer1_1_int_maskd : 1;
        unsigned int ftimer1_2_int_maskd : 1;
        unsigned int reserved_0 : 1;
        unsigned int timer1_int_mskd : 1;
        unsigned int timer2_int_mskd : 1;
        unsigned int soft_int_mskd : 1;
        unsigned int dsi0_int_mskd : 1;
        unsigned int dsi1_int_mskd : 1;
        unsigned int sys_wakeup_int_mskd : 1;
        unsigned int sys_sleep_int_mskd : 1;
        unsigned int dsi2_int_mskd : 1;
        unsigned int ftimer0_1_int_maskd : 1;
        unsigned int ftimer0_2_int_maskd : 1;
        unsigned int intr_wakeup_swing_enter_req_mskd : 1;
        unsigned int intr_wakeup_swing_exit_req_mskd : 1;
        unsigned int intr_frame_data_sync_mskd : 1;
        unsigned int intr_cnt_vsync_mskd : 1;
        unsigned int reserved_1 : 14;
    } reg;
} SOC_IOMCU_COMB_INT_STAT_UNION;
#endif
#define SOC_IOMCU_COMB_INT_STAT_gpio_int_mskd_START (0)
#define SOC_IOMCU_COMB_INT_STAT_gpio_int_mskd_END (0)
#define SOC_IOMCU_COMB_INT_STAT_ftimer1_1_int_maskd_START (1)
#define SOC_IOMCU_COMB_INT_STAT_ftimer1_1_int_maskd_END (1)
#define SOC_IOMCU_COMB_INT_STAT_ftimer1_2_int_maskd_START (2)
#define SOC_IOMCU_COMB_INT_STAT_ftimer1_2_int_maskd_END (2)
#define SOC_IOMCU_COMB_INT_STAT_timer1_int_mskd_START (4)
#define SOC_IOMCU_COMB_INT_STAT_timer1_int_mskd_END (4)
#define SOC_IOMCU_COMB_INT_STAT_timer2_int_mskd_START (5)
#define SOC_IOMCU_COMB_INT_STAT_timer2_int_mskd_END (5)
#define SOC_IOMCU_COMB_INT_STAT_soft_int_mskd_START (6)
#define SOC_IOMCU_COMB_INT_STAT_soft_int_mskd_END (6)
#define SOC_IOMCU_COMB_INT_STAT_dsi0_int_mskd_START (7)
#define SOC_IOMCU_COMB_INT_STAT_dsi0_int_mskd_END (7)
#define SOC_IOMCU_COMB_INT_STAT_dsi1_int_mskd_START (8)
#define SOC_IOMCU_COMB_INT_STAT_dsi1_int_mskd_END (8)
#define SOC_IOMCU_COMB_INT_STAT_sys_wakeup_int_mskd_START (9)
#define SOC_IOMCU_COMB_INT_STAT_sys_wakeup_int_mskd_END (9)
#define SOC_IOMCU_COMB_INT_STAT_sys_sleep_int_mskd_START (10)
#define SOC_IOMCU_COMB_INT_STAT_sys_sleep_int_mskd_END (10)
#define SOC_IOMCU_COMB_INT_STAT_dsi2_int_mskd_START (11)
#define SOC_IOMCU_COMB_INT_STAT_dsi2_int_mskd_END (11)
#define SOC_IOMCU_COMB_INT_STAT_ftimer0_1_int_maskd_START (12)
#define SOC_IOMCU_COMB_INT_STAT_ftimer0_1_int_maskd_END (12)
#define SOC_IOMCU_COMB_INT_STAT_ftimer0_2_int_maskd_START (13)
#define SOC_IOMCU_COMB_INT_STAT_ftimer0_2_int_maskd_END (13)
#define SOC_IOMCU_COMB_INT_STAT_intr_wakeup_swing_enter_req_mskd_START (14)
#define SOC_IOMCU_COMB_INT_STAT_intr_wakeup_swing_enter_req_mskd_END (14)
#define SOC_IOMCU_COMB_INT_STAT_intr_wakeup_swing_exit_req_mskd_START (15)
#define SOC_IOMCU_COMB_INT_STAT_intr_wakeup_swing_exit_req_mskd_END (15)
#define SOC_IOMCU_COMB_INT_STAT_intr_frame_data_sync_mskd_START (16)
#define SOC_IOMCU_COMB_INT_STAT_intr_frame_data_sync_mskd_END (16)
#define SOC_IOMCU_COMB_INT_STAT_intr_cnt_vsync_mskd_START (17)
#define SOC_IOMCU_COMB_INT_STAT_intr_cnt_vsync_mskd_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int auto_m7_freq_bypass : 1;
        unsigned int auto32k_sw_num : 5;
        unsigned int auto_num_in : 10;
        unsigned int auto_num_out : 10;
        unsigned int aximux_acg_bypass : 1;
        unsigned int qic_clkgate_bypass : 1;
        unsigned int iomcu_h2x_minibus_idle : 1;
        unsigned int qic_nopending_pdm_aobus_bypass : 1;
        unsigned int dma_cg_err : 1;
        unsigned int m7_axi_cg_err : 1;
    } reg;
} SOC_IOMCU_BUS_AUTO_FREQ_UNION;
#endif
#define SOC_IOMCU_BUS_AUTO_FREQ_auto_m7_freq_bypass_START (0)
#define SOC_IOMCU_BUS_AUTO_FREQ_auto_m7_freq_bypass_END (0)
#define SOC_IOMCU_BUS_AUTO_FREQ_auto32k_sw_num_START (1)
#define SOC_IOMCU_BUS_AUTO_FREQ_auto32k_sw_num_END (5)
#define SOC_IOMCU_BUS_AUTO_FREQ_auto_num_in_START (6)
#define SOC_IOMCU_BUS_AUTO_FREQ_auto_num_in_END (15)
#define SOC_IOMCU_BUS_AUTO_FREQ_auto_num_out_START (16)
#define SOC_IOMCU_BUS_AUTO_FREQ_auto_num_out_END (25)
#define SOC_IOMCU_BUS_AUTO_FREQ_aximux_acg_bypass_START (26)
#define SOC_IOMCU_BUS_AUTO_FREQ_aximux_acg_bypass_END (26)
#define SOC_IOMCU_BUS_AUTO_FREQ_qic_clkgate_bypass_START (27)
#define SOC_IOMCU_BUS_AUTO_FREQ_qic_clkgate_bypass_END (27)
#define SOC_IOMCU_BUS_AUTO_FREQ_iomcu_h2x_minibus_idle_START (28)
#define SOC_IOMCU_BUS_AUTO_FREQ_iomcu_h2x_minibus_idle_END (28)
#define SOC_IOMCU_BUS_AUTO_FREQ_qic_nopending_pdm_aobus_bypass_START (29)
#define SOC_IOMCU_BUS_AUTO_FREQ_qic_nopending_pdm_aobus_bypass_END (29)
#define SOC_IOMCU_BUS_AUTO_FREQ_dma_cg_err_START (30)
#define SOC_IOMCU_BUS_AUTO_FREQ_dma_cg_err_END (30)
#define SOC_IOMCU_BUS_AUTO_FREQ_m7_axi_cg_err_START (31)
#define SOC_IOMCU_BUS_AUTO_FREQ_m7_axi_cg_err_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spi0_cs : 4;
        unsigned int clk_tp_ctrl : 1;
        unsigned int dmac_ckgt_dis : 1;
        unsigned int cfg_itcm_size : 4;
        unsigned int cfg_dtcm_size : 4;
        unsigned int spi2_cs : 4;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int spi2_sel : 1;
        unsigned int cg_off : 1;
        unsigned int tcm_int_sel : 1;
        unsigned int ahb_err_bypass : 1;
        unsigned int i3c2_spi4_sel : 1;
        unsigned int i3c0_spi10_sel : 1;
        unsigned int spi4_cs : 4;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_IOMCU_MISC_CTRL_UNION;
#endif
#define SOC_IOMCU_MISC_CTRL_spi0_cs_START (0)
#define SOC_IOMCU_MISC_CTRL_spi0_cs_END (3)
#define SOC_IOMCU_MISC_CTRL_clk_tp_ctrl_START (4)
#define SOC_IOMCU_MISC_CTRL_clk_tp_ctrl_END (4)
#define SOC_IOMCU_MISC_CTRL_dmac_ckgt_dis_START (5)
#define SOC_IOMCU_MISC_CTRL_dmac_ckgt_dis_END (5)
#define SOC_IOMCU_MISC_CTRL_cfg_itcm_size_START (6)
#define SOC_IOMCU_MISC_CTRL_cfg_itcm_size_END (9)
#define SOC_IOMCU_MISC_CTRL_cfg_dtcm_size_START (10)
#define SOC_IOMCU_MISC_CTRL_cfg_dtcm_size_END (13)
#define SOC_IOMCU_MISC_CTRL_spi2_cs_START (14)
#define SOC_IOMCU_MISC_CTRL_spi2_cs_END (17)
#define SOC_IOMCU_MISC_CTRL_spi2_sel_START (21)
#define SOC_IOMCU_MISC_CTRL_spi2_sel_END (21)
#define SOC_IOMCU_MISC_CTRL_cg_off_START (22)
#define SOC_IOMCU_MISC_CTRL_cg_off_END (22)
#define SOC_IOMCU_MISC_CTRL_tcm_int_sel_START (23)
#define SOC_IOMCU_MISC_CTRL_tcm_int_sel_END (23)
#define SOC_IOMCU_MISC_CTRL_ahb_err_bypass_START (24)
#define SOC_IOMCU_MISC_CTRL_ahb_err_bypass_END (24)
#define SOC_IOMCU_MISC_CTRL_i3c2_spi4_sel_START (25)
#define SOC_IOMCU_MISC_CTRL_i3c2_spi4_sel_END (25)
#define SOC_IOMCU_MISC_CTRL_i3c0_spi10_sel_START (26)
#define SOC_IOMCU_MISC_CTRL_i3c0_spi10_sel_END (26)
#define SOC_IOMCU_MISC_CTRL_spi4_cs_START (27)
#define SOC_IOMCU_MISC_CTRL_spi4_cs_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_iomcu_dma_mst_awqos : 4;
        unsigned int qic_iomcu_dma_mst_arqos : 4;
        unsigned int qic_iomcu_awdomain : 2;
        unsigned int qic_iomcu_ardomain : 2;
        unsigned int sysqic_iomcu_ahb_mst_awcache : 4;
        unsigned int sysqic_iomcu_ahb_mst_arcache : 4;
        unsigned int qic_iomcu_awcache : 4;
        unsigned int qic_iomcu_arcache : 4;
        unsigned int qic_iomcu_axcache_mux : 1;
        unsigned int qic_m7_ahb_mst_qos : 3;
    } reg;
} SOC_IOMCU_QIC_CTRL_UNION;
#endif
#define SOC_IOMCU_QIC_CTRL_qic_iomcu_dma_mst_awqos_START (0)
#define SOC_IOMCU_QIC_CTRL_qic_iomcu_dma_mst_awqos_END (3)
#define SOC_IOMCU_QIC_CTRL_qic_iomcu_dma_mst_arqos_START (4)
#define SOC_IOMCU_QIC_CTRL_qic_iomcu_dma_mst_arqos_END (7)
#define SOC_IOMCU_QIC_CTRL_qic_iomcu_awdomain_START (8)
#define SOC_IOMCU_QIC_CTRL_qic_iomcu_awdomain_END (9)
#define SOC_IOMCU_QIC_CTRL_qic_iomcu_ardomain_START (10)
#define SOC_IOMCU_QIC_CTRL_qic_iomcu_ardomain_END (11)
#define SOC_IOMCU_QIC_CTRL_sysqic_iomcu_ahb_mst_awcache_START (12)
#define SOC_IOMCU_QIC_CTRL_sysqic_iomcu_ahb_mst_awcache_END (15)
#define SOC_IOMCU_QIC_CTRL_sysqic_iomcu_ahb_mst_arcache_START (16)
#define SOC_IOMCU_QIC_CTRL_sysqic_iomcu_ahb_mst_arcache_END (19)
#define SOC_IOMCU_QIC_CTRL_qic_iomcu_awcache_START (20)
#define SOC_IOMCU_QIC_CTRL_qic_iomcu_awcache_END (23)
#define SOC_IOMCU_QIC_CTRL_qic_iomcu_arcache_START (24)
#define SOC_IOMCU_QIC_CTRL_qic_iomcu_arcache_END (27)
#define SOC_IOMCU_QIC_CTRL_qic_iomcu_axcache_mux_START (28)
#define SOC_IOMCU_QIC_CTRL_qic_iomcu_axcache_mux_END (28)
#define SOC_IOMCU_QIC_CTRL_qic_m7_ahb_mst_qos_START (29)
#define SOC_IOMCU_QIC_CTRL_qic_m7_ahb_mst_qos_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hifi_dtcm_access_window : 32;
    } reg;
} SOC_IOMCU_HIFI_DTCM_ACCESS_WINDOW_UNION;
#endif
#define SOC_IOMCU_HIFI_DTCM_ACCESS_WINDOW_hifi_dtcm_access_window_START (0)
#define SOC_IOMCU_HIFI_DTCM_ACCESS_WINDOW_hifi_dtcm_access_window_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_clken1_0peri0 : 1;
        unsigned int iomcu_clken1_1peri1 : 1;
        unsigned int iomcu_clken1_2peri2 : 1;
        unsigned int reserved_0 : 1;
        unsigned int iomcu_clken1_4dmmu : 1;
        unsigned int iomcu_clken1_clk_ftimer0 : 1;
        unsigned int iomcu_clken1_t_ftimer0 : 1;
        unsigned int iomcu_clken1_pclk_ftimer0 : 1;
        unsigned int iomcu_clken1_ftimer0_1 : 1;
        unsigned int iomcu_clken1_i3c0 : 1;
        unsigned int iomcu_clken1_h_tcp : 1;
        unsigned int iomcu_clken1_p_tcp : 1;
        unsigned int iomcu_clken1_i3c3 : 1;
        unsigned int iomcu_clken1_rtt : 1;
        unsigned int iomcu_clken1_i2c8 : 1;
        unsigned int iomcu_clken1_1peri1_spi2 : 1;
        unsigned int iomcu_clken1_qcr_iomcubus : 1;
        unsigned int iomcu_clken1_iomcu_p2j : 1;
        unsigned int iomcu_clken1_cnt_vsync_div : 1;
        unsigned int iomcu_clken1_cnt_vsync : 1;
        unsigned int iomcu_clken1_pclk_ftimer1 : 1;
        unsigned int iomcu_clken1_clk_ftimer1 : 1;
        unsigned int iomcu_clken1_hts_adp_mst : 1;
        unsigned int iomcu_clken1_hts_adp_slv : 1;
        unsigned int iomcu_clken1_i2c10 : 1;
        unsigned int iomcu_clken1_i2c11 : 1;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_IOMCU_CLKEN1_UNION;
#endif
#define SOC_IOMCU_CLKEN1_iomcu_clken1_0peri0_START (0)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_0peri0_END (0)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_1peri1_START (1)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_1peri1_END (1)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_2peri2_START (2)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_2peri2_END (2)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_4dmmu_START (4)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_4dmmu_END (4)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_clk_ftimer0_START (5)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_clk_ftimer0_END (5)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_t_ftimer0_START (6)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_t_ftimer0_END (6)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_pclk_ftimer0_START (7)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_pclk_ftimer0_END (7)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_ftimer0_1_START (8)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_ftimer0_1_END (8)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_i3c0_START (9)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_i3c0_END (9)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_h_tcp_START (10)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_h_tcp_END (10)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_p_tcp_START (11)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_p_tcp_END (11)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_i3c3_START (12)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_i3c3_END (12)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_rtt_START (13)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_rtt_END (13)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_i2c8_START (14)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_i2c8_END (14)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_1peri1_spi2_START (15)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_1peri1_spi2_END (15)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_qcr_iomcubus_START (16)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_qcr_iomcubus_END (16)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_iomcu_p2j_START (17)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_iomcu_p2j_END (17)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_cnt_vsync_div_START (18)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_cnt_vsync_div_END (18)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_cnt_vsync_START (19)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_cnt_vsync_END (19)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_pclk_ftimer1_START (20)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_pclk_ftimer1_END (20)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_clk_ftimer1_START (21)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_clk_ftimer1_END (21)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_hts_adp_mst_START (22)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_hts_adp_mst_END (22)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_hts_adp_slv_START (23)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_hts_adp_slv_END (23)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_i2c10_START (24)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_i2c10_END (24)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_i2c11_START (25)
#define SOC_IOMCU_CLKEN1_iomcu_clken1_i2c11_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_clkdis1_0peri0 : 1;
        unsigned int iomcu_clkdis1_1peri1 : 1;
        unsigned int iomcu_clkdis1_2peri2 : 1;
        unsigned int reserved_0 : 1;
        unsigned int iomcu_clkdis1_4dmmu : 1;
        unsigned int iomcu_clkdis1_clk_ftimer0 : 1;
        unsigned int iomcu_clkdis1_t_ftimer0 : 1;
        unsigned int iomcu_clkdis1_pclk_ftimer0 : 1;
        unsigned int iomcu_clkdis1_ftimer0_1 : 1;
        unsigned int iomcu_clkdis1_i3c0 : 1;
        unsigned int iomcu_clkdis1_h_tcp : 1;
        unsigned int iomcu_clkdis1_p_tcp : 1;
        unsigned int iomcu_clkdis1_i3c3 : 1;
        unsigned int iomcu_clkdis1_rtt : 1;
        unsigned int iomcu_clkdis1_i2c8 : 1;
        unsigned int iomcu_clkdis1_1peri1_spi2 : 1;
        unsigned int iomcu_clkdis1_qcr_iomcubus : 1;
        unsigned int iomcu_clkdis1_iomcu_p2j : 1;
        unsigned int iomcu_clkdis1_cnt_vsync_div : 1;
        unsigned int iomcu_clkdis1_cnt_vsync : 1;
        unsigned int iomcu_clkdis1_p_ftimer1 : 1;
        unsigned int iomcu_clkdis1_ref_ftimer1 : 1;
        unsigned int iomcu_clkdis1_hts_adp_mst : 1;
        unsigned int iomcu_clkdis1_hts_adp_slv : 1;
        unsigned int iomcu_clkdis1_i2c10 : 1;
        unsigned int iomcu_clkdis1_i2c11 : 1;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_IOMCU_CLKDIS1_UNION;
#endif
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_0peri0_START (0)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_0peri0_END (0)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_1peri1_START (1)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_1peri1_END (1)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_2peri2_START (2)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_2peri2_END (2)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_4dmmu_START (4)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_4dmmu_END (4)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_clk_ftimer0_START (5)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_clk_ftimer0_END (5)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_t_ftimer0_START (6)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_t_ftimer0_END (6)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_pclk_ftimer0_START (7)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_pclk_ftimer0_END (7)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_ftimer0_1_START (8)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_ftimer0_1_END (8)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_i3c0_START (9)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_i3c0_END (9)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_h_tcp_START (10)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_h_tcp_END (10)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_p_tcp_START (11)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_p_tcp_END (11)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_i3c3_START (12)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_i3c3_END (12)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_rtt_START (13)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_rtt_END (13)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_i2c8_START (14)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_i2c8_END (14)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_1peri1_spi2_START (15)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_1peri1_spi2_END (15)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_qcr_iomcubus_START (16)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_qcr_iomcubus_END (16)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_iomcu_p2j_START (17)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_iomcu_p2j_END (17)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_cnt_vsync_div_START (18)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_cnt_vsync_div_END (18)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_cnt_vsync_START (19)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_cnt_vsync_END (19)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_p_ftimer1_START (20)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_p_ftimer1_END (20)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_ref_ftimer1_START (21)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_ref_ftimer1_END (21)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_hts_adp_mst_START (22)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_hts_adp_mst_END (22)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_hts_adp_slv_START (23)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_hts_adp_slv_END (23)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_i2c10_START (24)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_i2c10_END (24)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_i2c11_START (25)
#define SOC_IOMCU_CLKDIS1_iomcu_clkdis1_i2c11_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_clkstat1_0peri0 : 1;
        unsigned int iomcu_clkstat1_1peri1 : 1;
        unsigned int iomcu_clkstat1_2peri2 : 1;
        unsigned int reserved_0 : 1;
        unsigned int iomcu_clkstat1_4dmmu : 1;
        unsigned int iomcu_clkstat1_clk_ftimer0 : 1;
        unsigned int iomcu_clkstat1_t_ftimer0 : 1;
        unsigned int iomcu_clkstat1_pclk_ftimer0 : 1;
        unsigned int iomcu_clkstat1_ftimer0_1 : 1;
        unsigned int iomcu_clkstat1_i3c0 : 1;
        unsigned int iomcu_clkstat1_h_tcp : 1;
        unsigned int iomcu_clkstat1_p_tcp : 1;
        unsigned int iomcu_clkstat1_i3c3 : 1;
        unsigned int iomcu_clkstat1_rtt : 1;
        unsigned int iomcu_clkstat1_i2c8 : 1;
        unsigned int iomcu_clkstat1_1peri1_spi2 : 1;
        unsigned int iomcu_clkstat1_qcr_iomcubus : 1;
        unsigned int iomcu_clkstat1_iomcu_p2j : 1;
        unsigned int iomcu_clkstat1_cnt_vsync_div : 1;
        unsigned int iomcu_clkstat1_cnt_vsync : 1;
        unsigned int iomcu_clkstat1_pclk_ftimer1 : 1;
        unsigned int iomcu_clkstat1_clk_ftimer1 : 1;
        unsigned int iomcu_clkstat1_hts_adp_mst : 1;
        unsigned int iomcu_clkstat1_hts_adp_slv : 1;
        unsigned int iomcu_clkstat1_i2c10 : 1;
        unsigned int iomcu_clkstat1_i2c11 : 1;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_IOMCU_CLKSTAT1_UNION;
#endif
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_0peri0_START (0)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_0peri0_END (0)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_1peri1_START (1)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_1peri1_END (1)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_2peri2_START (2)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_2peri2_END (2)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_4dmmu_START (4)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_4dmmu_END (4)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_clk_ftimer0_START (5)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_clk_ftimer0_END (5)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_t_ftimer0_START (6)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_t_ftimer0_END (6)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_pclk_ftimer0_START (7)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_pclk_ftimer0_END (7)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_ftimer0_1_START (8)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_ftimer0_1_END (8)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_i3c0_START (9)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_i3c0_END (9)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_h_tcp_START (10)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_h_tcp_END (10)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_p_tcp_START (11)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_p_tcp_END (11)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_i3c3_START (12)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_i3c3_END (12)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_rtt_START (13)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_rtt_END (13)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_i2c8_START (14)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_i2c8_END (14)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_1peri1_spi2_START (15)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_1peri1_spi2_END (15)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_qcr_iomcubus_START (16)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_qcr_iomcubus_END (16)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_iomcu_p2j_START (17)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_iomcu_p2j_END (17)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_cnt_vsync_div_START (18)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_cnt_vsync_div_END (18)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_cnt_vsync_START (19)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_cnt_vsync_END (19)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_pclk_ftimer1_START (20)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_pclk_ftimer1_END (20)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_clk_ftimer1_START (21)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_clk_ftimer1_END (21)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_hts_adp_mst_START (22)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_hts_adp_mst_END (22)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_hts_adp_slv_START (23)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_hts_adp_slv_END (23)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_i2c10_START (24)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_i2c10_END (24)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_i2c11_START (25)
#define SOC_IOMCU_CLKSTAT1_iomcu_clkstat1_i2c11_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ocram_access_window : 32;
    } reg;
} SOC_IOMCU_OCRAM_ACCESS_WINDOW_UNION;
#endif
#define SOC_IOMCU_OCRAM_ACCESS_WINDOW_ocram_access_window_START (0)
#define SOC_IOMCU_OCRAM_ACCESS_WINDOW_ocram_access_window_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_AHB_tzpc : 1;
        unsigned int iomcu_AXI_tzpc : 1;
        unsigned int iomcu_dmmu_tzpc : 1;
        unsigned int iomcu_i3c1_tzpc : 1;
        unsigned int iomcu_i2c1_tzpc : 1;
        unsigned int iomcu_spi2_tzpc : 1;
        unsigned int iomcu_i2c10_tzpc : 1;
        unsigned int iomcu_i3c2_tzpc : 1;
        unsigned int iomcu_i2c5_tzpc : 1;
        unsigned int iomcu_spi0_tzpc : 1;
        unsigned int iomcu_i2c0_tzpc : 1;
        unsigned int iomcu_uart3_tzpc : 1;
        unsigned int reserved : 1;
        unsigned int iomcu_uart7_tzpc : 1;
        unsigned int iomcu_i3c0_tzpc : 1;
        unsigned int iomcu_gpio_tzpc : 1;
        unsigned int iomcu_spi4_tzpc : 1;
        unsigned int iomcu_spi8_tzpc : 1;
        unsigned int iomcu_hts_adp_mst_tzpc : 1;
        unsigned int iomcu_wdg_tzpc : 1;
        unsigned int iomcu_timer_tzpc : 1;
        unsigned int iomcu_sctrl_tzpc : 1;
        unsigned int iomcu_rtc_tzpc : 1;
        unsigned int iomcu_m7_tzpc : 1;
        unsigned int iomcu_ftimer0_tzpc : 1;
        unsigned int iomcu_hts_adp_slv_tzpc : 1;
        unsigned int iomcu_ahb_tcp_tzpc : 1;
        unsigned int iomcu_i3c3_tzpc : 1;
        unsigned int iomcu_tcm_tzpc : 1;
        unsigned int iomcu_i2c8_tzpc : 1;
        unsigned int iomcu_ftimer1_tzpc : 1;
        unsigned int iomcu_i2c11_tzpc : 1;
    } reg;
} SOC_IOMCU_SEC_TZPC_UNION;
#endif
#define SOC_IOMCU_SEC_TZPC_iomcu_AHB_tzpc_START (0)
#define SOC_IOMCU_SEC_TZPC_iomcu_AHB_tzpc_END (0)
#define SOC_IOMCU_SEC_TZPC_iomcu_AXI_tzpc_START (1)
#define SOC_IOMCU_SEC_TZPC_iomcu_AXI_tzpc_END (1)
#define SOC_IOMCU_SEC_TZPC_iomcu_dmmu_tzpc_START (2)
#define SOC_IOMCU_SEC_TZPC_iomcu_dmmu_tzpc_END (2)
#define SOC_IOMCU_SEC_TZPC_iomcu_i3c1_tzpc_START (3)
#define SOC_IOMCU_SEC_TZPC_iomcu_i3c1_tzpc_END (3)
#define SOC_IOMCU_SEC_TZPC_iomcu_i2c1_tzpc_START (4)
#define SOC_IOMCU_SEC_TZPC_iomcu_i2c1_tzpc_END (4)
#define SOC_IOMCU_SEC_TZPC_iomcu_spi2_tzpc_START (5)
#define SOC_IOMCU_SEC_TZPC_iomcu_spi2_tzpc_END (5)
#define SOC_IOMCU_SEC_TZPC_iomcu_i2c10_tzpc_START (6)
#define SOC_IOMCU_SEC_TZPC_iomcu_i2c10_tzpc_END (6)
#define SOC_IOMCU_SEC_TZPC_iomcu_i3c2_tzpc_START (7)
#define SOC_IOMCU_SEC_TZPC_iomcu_i3c2_tzpc_END (7)
#define SOC_IOMCU_SEC_TZPC_iomcu_i2c5_tzpc_START (8)
#define SOC_IOMCU_SEC_TZPC_iomcu_i2c5_tzpc_END (8)
#define SOC_IOMCU_SEC_TZPC_iomcu_spi0_tzpc_START (9)
#define SOC_IOMCU_SEC_TZPC_iomcu_spi0_tzpc_END (9)
#define SOC_IOMCU_SEC_TZPC_iomcu_i2c0_tzpc_START (10)
#define SOC_IOMCU_SEC_TZPC_iomcu_i2c0_tzpc_END (10)
#define SOC_IOMCU_SEC_TZPC_iomcu_uart3_tzpc_START (11)
#define SOC_IOMCU_SEC_TZPC_iomcu_uart3_tzpc_END (11)
#define SOC_IOMCU_SEC_TZPC_iomcu_uart7_tzpc_START (13)
#define SOC_IOMCU_SEC_TZPC_iomcu_uart7_tzpc_END (13)
#define SOC_IOMCU_SEC_TZPC_iomcu_i3c0_tzpc_START (14)
#define SOC_IOMCU_SEC_TZPC_iomcu_i3c0_tzpc_END (14)
#define SOC_IOMCU_SEC_TZPC_iomcu_gpio_tzpc_START (15)
#define SOC_IOMCU_SEC_TZPC_iomcu_gpio_tzpc_END (15)
#define SOC_IOMCU_SEC_TZPC_iomcu_spi4_tzpc_START (16)
#define SOC_IOMCU_SEC_TZPC_iomcu_spi4_tzpc_END (16)
#define SOC_IOMCU_SEC_TZPC_iomcu_spi8_tzpc_START (17)
#define SOC_IOMCU_SEC_TZPC_iomcu_spi8_tzpc_END (17)
#define SOC_IOMCU_SEC_TZPC_iomcu_hts_adp_mst_tzpc_START (18)
#define SOC_IOMCU_SEC_TZPC_iomcu_hts_adp_mst_tzpc_END (18)
#define SOC_IOMCU_SEC_TZPC_iomcu_wdg_tzpc_START (19)
#define SOC_IOMCU_SEC_TZPC_iomcu_wdg_tzpc_END (19)
#define SOC_IOMCU_SEC_TZPC_iomcu_timer_tzpc_START (20)
#define SOC_IOMCU_SEC_TZPC_iomcu_timer_tzpc_END (20)
#define SOC_IOMCU_SEC_TZPC_iomcu_sctrl_tzpc_START (21)
#define SOC_IOMCU_SEC_TZPC_iomcu_sctrl_tzpc_END (21)
#define SOC_IOMCU_SEC_TZPC_iomcu_rtc_tzpc_START (22)
#define SOC_IOMCU_SEC_TZPC_iomcu_rtc_tzpc_END (22)
#define SOC_IOMCU_SEC_TZPC_iomcu_m7_tzpc_START (23)
#define SOC_IOMCU_SEC_TZPC_iomcu_m7_tzpc_END (23)
#define SOC_IOMCU_SEC_TZPC_iomcu_ftimer0_tzpc_START (24)
#define SOC_IOMCU_SEC_TZPC_iomcu_ftimer0_tzpc_END (24)
#define SOC_IOMCU_SEC_TZPC_iomcu_hts_adp_slv_tzpc_START (25)
#define SOC_IOMCU_SEC_TZPC_iomcu_hts_adp_slv_tzpc_END (25)
#define SOC_IOMCU_SEC_TZPC_iomcu_ahb_tcp_tzpc_START (26)
#define SOC_IOMCU_SEC_TZPC_iomcu_ahb_tcp_tzpc_END (26)
#define SOC_IOMCU_SEC_TZPC_iomcu_i3c3_tzpc_START (27)
#define SOC_IOMCU_SEC_TZPC_iomcu_i3c3_tzpc_END (27)
#define SOC_IOMCU_SEC_TZPC_iomcu_tcm_tzpc_START (28)
#define SOC_IOMCU_SEC_TZPC_iomcu_tcm_tzpc_END (28)
#define SOC_IOMCU_SEC_TZPC_iomcu_i2c8_tzpc_START (29)
#define SOC_IOMCU_SEC_TZPC_iomcu_i2c8_tzpc_END (29)
#define SOC_IOMCU_SEC_TZPC_iomcu_ftimer1_tzpc_START (30)
#define SOC_IOMCU_SEC_TZPC_iomcu_ftimer1_tzpc_END (30)
#define SOC_IOMCU_SEC_TZPC_iomcu_i2c11_tzpc_START (31)
#define SOC_IOMCU_SEC_TZPC_iomcu_i2c11_tzpc_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_config_tzpc : 1;
        unsigned int iomcu_spi9_tzpc : 1;
        unsigned int iomcu_spi10_tzpc : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_IOMCU_SEC_TZPC_RES_UNION;
#endif
#define SOC_IOMCU_SEC_TZPC_RES_iomcu_config_tzpc_START (0)
#define SOC_IOMCU_SEC_TZPC_RES_iomcu_config_tzpc_END (0)
#define SOC_IOMCU_SEC_TZPC_RES_iomcu_spi9_tzpc_START (1)
#define SOC_IOMCU_SEC_TZPC_RES_iomcu_spi9_tzpc_END (1)
#define SOC_IOMCU_SEC_TZPC_RES_iomcu_spi10_tzpc_START (2)
#define SOC_IOMCU_SEC_TZPC_RES_iomcu_spi10_tzpc_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_spi : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_IOMCU_MEM_CTRL6_UNION;
#endif
#define SOC_IOMCU_MEM_CTRL6_mem_ctrl_spi_START (0)
#define SOC_IOMCU_MEM_CTRL6_mem_ctrl_spi_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_ahb_mst_mid : 8;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int qic_ahb_mst_gid : 6;
        unsigned int qic_ahb_mst_axchint : 4;
        unsigned int qic_ahb_mst_axdomain : 2;
        unsigned int qic_ahb_mst_axcache : 4;
        unsigned int qic_ahb_mst_mpam : 4;
        unsigned int reserved_2 : 2;
    } reg;
} SOC_IOMCU_QIC_USER_CTRL_UNION;
#endif
#define SOC_IOMCU_QIC_USER_CTRL_qic_ahb_mst_mid_START (0)
#define SOC_IOMCU_QIC_USER_CTRL_qic_ahb_mst_mid_END (7)
#define SOC_IOMCU_QIC_USER_CTRL_qic_ahb_mst_gid_START (10)
#define SOC_IOMCU_QIC_USER_CTRL_qic_ahb_mst_gid_END (15)
#define SOC_IOMCU_QIC_USER_CTRL_qic_ahb_mst_axchint_START (16)
#define SOC_IOMCU_QIC_USER_CTRL_qic_ahb_mst_axchint_END (19)
#define SOC_IOMCU_QIC_USER_CTRL_qic_ahb_mst_axdomain_START (20)
#define SOC_IOMCU_QIC_USER_CTRL_qic_ahb_mst_axdomain_END (21)
#define SOC_IOMCU_QIC_USER_CTRL_qic_ahb_mst_axcache_START (22)
#define SOC_IOMCU_QIC_USER_CTRL_qic_ahb_mst_axcache_END (25)
#define SOC_IOMCU_QIC_USER_CTRL_qic_ahb_mst_mpam_START (26)
#define SOC_IOMCU_QIC_USER_CTRL_qic_ahb_mst_mpam_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_IOMCU_DDR_ACCESS_WINDOW1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ldrx_abs_timer_iomcu_32k_1 : 32;
    } reg;
} SOC_IOMCU_SCBBPDRXSTAT1_IOMCU_UNION;
#endif
#define SOC_IOMCU_SCBBPDRXSTAT1_IOMCU_ldrx_abs_timer_iomcu_32k_1_START (0)
#define SOC_IOMCU_SCBBPDRXSTAT1_IOMCU_ldrx_abs_timer_iomcu_32k_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ldrx_abs_timer_iomcu_32k_2 : 32;
    } reg;
} SOC_IOMCU_SCBBPDRXSTAT2_IOMCU_UNION;
#endif
#define SOC_IOMCU_SCBBPDRXSTAT2_IOMCU_ldrx_abs_timer_iomcu_32k_2_START (0)
#define SOC_IOMCU_SCBBPDRXSTAT2_IOMCU_ldrx_abs_timer_iomcu_32k_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnt_vsync_value : 32;
    } reg;
} SOC_IOMCU_CNT_VSYNC_VALUE_UNION;
#endif
#define SOC_IOMCU_CNT_VSYNC_VALUE_cnt_vsync_value_START (0)
#define SOC_IOMCU_CNT_VSYNC_VALUE_cnt_vsync_value_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int bypass_cnt_vsync : 1;
        unsigned int vsync_mux : 2;
        unsigned int reserved : 29;
    } reg;
} SOC_IOMCU_CNT_VSYNC_CONFIG_UNION;
#endif
#define SOC_IOMCU_CNT_VSYNC_CONFIG_bypass_cnt_vsync_START (0)
#define SOC_IOMCU_CNT_VSYNC_CONFIG_bypass_cnt_vsync_END (0)
#define SOC_IOMCU_CNT_VSYNC_CONFIG_vsync_mux_START (1)
#define SOC_IOMCU_CNT_VSYNC_CONFIG_vsync_mux_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cnt_vsync_cycle : 32;
    } reg;
} SOC_IOMCU_CNT_VSYNC_CYCLE_UNION;
#endif
#define SOC_IOMCU_CNT_VSYNC_CYCLE_cnt_vsync_cycle_START (0)
#define SOC_IOMCU_CNT_VSYNC_CYCLE_cnt_vsync_cycle_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int frame_data : 4;
        unsigned int reserved_0 : 3;
        unsigned int frame_data_update_en : 1;
        unsigned int reserved_1 : 24;
    } reg;
} SOC_IOMCU_FRAME_DATA_CONFIG_UNION;
#endif
#define SOC_IOMCU_FRAME_DATA_CONFIG_frame_data_START (0)
#define SOC_IOMCU_FRAME_DATA_CONFIG_frame_data_END (3)
#define SOC_IOMCU_FRAME_DATA_CONFIG_frame_data_update_en_START (7)
#define SOC_IOMCU_FRAME_DATA_CONFIG_frame_data_update_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk_wdt_div : 6;
        unsigned int reserved_0 : 1;
        unsigned int clk_wdt_div_en : 1;
        unsigned int clk_fll_src_div_vsync : 6;
        unsigned int reserved_1 : 1;
        unsigned int clk_fll_src_div_vsync_en : 1;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_IOMCU_CFG_DIV2_UNION;
#endif
#define SOC_IOMCU_CFG_DIV2_clk_wdt_div_START (0)
#define SOC_IOMCU_CFG_DIV2_clk_wdt_div_END (5)
#define SOC_IOMCU_CFG_DIV2_clk_wdt_div_en_START (7)
#define SOC_IOMCU_CFG_DIV2_clk_wdt_div_en_END (7)
#define SOC_IOMCU_CFG_DIV2_clk_fll_src_div_vsync_START (8)
#define SOC_IOMCU_CFG_DIV2_clk_fll_src_div_vsync_END (13)
#define SOC_IOMCU_CFG_DIV2_clk_fll_src_div_vsync_en_START (15)
#define SOC_IOMCU_CFG_DIV2_clk_fll_src_div_vsync_en_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_des_addr : 32;
    } reg;
} SOC_IOMCU_ADDR_REMAP_UNION;
#endif
#define SOC_IOMCU_ADDR_REMAP_iomcu_des_addr_START (0)
#define SOC_IOMCU_ADDR_REMAP_iomcu_des_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int io_top_ctrl_processor_init_addr : 32;
    } reg;
} SOC_IOMCU_RSV_CORE_CTRL0_UNION;
#endif
#define SOC_IOMCU_RSV_CORE_CTRL0_io_top_ctrl_processor_init_addr_START (0)
#define SOC_IOMCU_RSV_CORE_CTRL0_io_top_ctrl_processor_init_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int io_top_ctrl_processor_itcm_base : 32;
    } reg;
} SOC_IOMCU_RSV_CORE_CTRL1_UNION;
#endif
#define SOC_IOMCU_RSV_CORE_CTRL1_io_top_ctrl_processor_itcm_base_START (0)
#define SOC_IOMCU_RSV_CORE_CTRL1_io_top_ctrl_processor_itcm_base_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int io_top_ctrl_processor_dtcm_base : 32;
    } reg;
} SOC_IOMCU_RSV_CORE_CTRL2_UNION;
#endif
#define SOC_IOMCU_RSV_CORE_CTRL2_io_top_ctrl_processor_dtcm_base_START (0)
#define SOC_IOMCU_RSV_CORE_CTRL2_io_top_ctrl_processor_dtcm_base_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int io_top_ctrl_processor_reg_base : 17;
        unsigned int reserved : 15;
    } reg;
} SOC_IOMCU_RSV_CORE_CTRL3_UNION;
#endif
#define SOC_IOMCU_RSV_CORE_CTRL3_io_top_ctrl_processor_reg_base_START (0)
#define SOC_IOMCU_RSV_CORE_CTRL3_io_top_ctrl_processor_reg_base_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int io_top_ctrl_mmem_start : 32;
    } reg;
} SOC_IOMCU_RSV_CORE_CTRL4_UNION;
#endif
#define SOC_IOMCU_RSV_CORE_CTRL4_io_top_ctrl_mmem_start_START (0)
#define SOC_IOMCU_RSV_CORE_CTRL4_io_top_ctrl_mmem_start_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int io_top_ctrl_mmem_end : 32;
    } reg;
} SOC_IOMCU_RSV_CORE_CTRL5_UNION;
#endif
#define SOC_IOMCU_RSV_CORE_CTRL5_io_top_ctrl_mmem_end_START (0)
#define SOC_IOMCU_RSV_CORE_CTRL5_io_top_ctrl_mmem_end_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int io_top_ctrl_pmem_start : 32;
    } reg;
} SOC_IOMCU_RSV_CORE_CTRL6_UNION;
#endif
#define SOC_IOMCU_RSV_CORE_CTRL6_io_top_ctrl_pmem_start_START (0)
#define SOC_IOMCU_RSV_CORE_CTRL6_io_top_ctrl_pmem_start_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int io_top_ctrl_pmem_end : 32;
    } reg;
} SOC_IOMCU_RSV_CORE_CTRL7_UNION;
#endif
#define SOC_IOMCU_RSV_CORE_CTRL7_io_top_ctrl_pmem_end_START (0)
#define SOC_IOMCU_RSV_CORE_CTRL7_io_top_ctrl_pmem_end_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_apb_dbg_info : 32;
    } reg;
} SOC_IOMCU_CORE_APB_TIMEOUT_INFO_UNION;
#endif
#define SOC_IOMCU_CORE_APB_TIMEOUT_INFO_core_apb_dbg_info_START (0)
#define SOC_IOMCU_CORE_APB_TIMEOUT_INFO_core_apb_dbg_info_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int core_apbd_timeout_bypass : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOMCU_CORE_APB_TIMEOUT_CFG_UNION;
#endif
#define SOC_IOMCU_CORE_APB_TIMEOUT_CFG_core_apbd_timeout_bypass_START (0)
#define SOC_IOMCU_CORE_APB_TIMEOUT_CFG_core_apbd_timeout_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_axi_user_arschint : 4;
        unsigned int iomcu_axi_user_armpam : 4;
        unsigned int iomcu_axi_user_argid : 6;
        unsigned int iomcu_axi_user_awschint : 4;
        unsigned int iomcu_axi_user_awmpam : 4;
        unsigned int iomcu_axi_user_awgid : 6;
        unsigned int reserved : 4;
    } reg;
} SOC_IOMCU_AXI_USER_UNION;
#endif
#define SOC_IOMCU_AXI_USER_iomcu_axi_user_arschint_START (0)
#define SOC_IOMCU_AXI_USER_iomcu_axi_user_arschint_END (3)
#define SOC_IOMCU_AXI_USER_iomcu_axi_user_armpam_START (4)
#define SOC_IOMCU_AXI_USER_iomcu_axi_user_armpam_END (7)
#define SOC_IOMCU_AXI_USER_iomcu_axi_user_argid_START (8)
#define SOC_IOMCU_AXI_USER_iomcu_axi_user_argid_END (13)
#define SOC_IOMCU_AXI_USER_iomcu_axi_user_awschint_START (14)
#define SOC_IOMCU_AXI_USER_iomcu_axi_user_awschint_END (17)
#define SOC_IOMCU_AXI_USER_iomcu_axi_user_awmpam_START (18)
#define SOC_IOMCU_AXI_USER_iomcu_axi_user_awmpam_END (21)
#define SOC_IOMCU_AXI_USER_iomcu_axi_user_awgid_START (22)
#define SOC_IOMCU_AXI_USER_iomcu_axi_user_awgid_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int io_dm_clk_off_n : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOMCU_RSV_CORE_CTRL8_UNION;
#endif
#define SOC_IOMCU_RSV_CORE_CTRL8_io_dm_clk_off_n_START (0)
#define SOC_IOMCU_RSV_CORE_CTRL8_io_dm_clk_off_n_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_reserved_reg_0 : 32;
    } reg;
} SOC_IOMCU_RESERVED_REG_0_UNION;
#endif
#define SOC_IOMCU_RESERVED_REG_0_iomcu_reserved_reg_0_START (0)
#define SOC_IOMCU_RESERVED_REG_0_iomcu_reserved_reg_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_reserved_reg_1 : 32;
    } reg;
} SOC_IOMCU_RESERVED_REG_1_UNION;
#endif
#define SOC_IOMCU_RESERVED_REG_1_iomcu_reserved_reg_1_START (0)
#define SOC_IOMCU_RESERVED_REG_1_iomcu_reserved_reg_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_reserved_reg_2 : 32;
    } reg;
} SOC_IOMCU_RESERVED_REG_2_UNION;
#endif
#define SOC_IOMCU_RESERVED_REG_2_iomcu_reserved_reg_2_START (0)
#define SOC_IOMCU_RESERVED_REG_2_iomcu_reserved_reg_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_reserved_reg_3 : 32;
    } reg;
} SOC_IOMCU_RESERVED_REG_3_UNION;
#endif
#define SOC_IOMCU_RESERVED_REG_3_iomcu_reserved_reg_3_START (0)
#define SOC_IOMCU_RESERVED_REG_3_iomcu_reserved_reg_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_reserved_reg_4 : 32;
    } reg;
} SOC_IOMCU_RESERVED_REG_4_UNION;
#endif
#define SOC_IOMCU_RESERVED_REG_4_iomcu_reserved_reg_4_START (0)
#define SOC_IOMCU_RESERVED_REG_4_iomcu_reserved_reg_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_reserved_reg_5 : 32;
    } reg;
} SOC_IOMCU_RESERVED_REG_5_UNION;
#endif
#define SOC_IOMCU_RESERVED_REG_5_iomcu_reserved_reg_5_START (0)
#define SOC_IOMCU_RESERVED_REG_5_iomcu_reserved_reg_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_reserved_reg_6 : 32;
    } reg;
} SOC_IOMCU_RESERVED_REG_6_UNION;
#endif
#define SOC_IOMCU_RESERVED_REG_6_iomcu_reserved_reg_6_START (0)
#define SOC_IOMCU_RESERVED_REG_6_iomcu_reserved_reg_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_reserved_reg_7 : 32;
    } reg;
} SOC_IOMCU_RESERVED_REG_7_UNION;
#endif
#define SOC_IOMCU_RESERVED_REG_7_iomcu_reserved_reg_7_START (0)
#define SOC_IOMCU_RESERVED_REG_7_iomcu_reserved_reg_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spua_mem_ctrl : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_IOMCU_MEM_CTRL_SPUA_UNION;
#endif
#define SOC_IOMCU_MEM_CTRL_SPUA_spua_mem_ctrl_START (0)
#define SOC_IOMCU_MEM_CTRL_SPUA_spua_mem_ctrl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tcm_mem_ctrl : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_IOMCU_MEM_CTRL_TCM_UNION;
#endif
#define SOC_IOMCU_MEM_CTRL_TCM_tcm_mem_ctrl_START (0)
#define SOC_IOMCU_MEM_CTRL_TCM_tcm_mem_ctrl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sp_mem_ctrl : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_IOMCU_MEM_CTRL2_UNION;
#endif
#define SOC_IOMCU_MEM_CTRL2_sp_mem_ctrl_START (0)
#define SOC_IOMCU_MEM_CTRL2_sp_mem_ctrl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_bank16 : 3;
        unsigned int mem_ctrl_bank17 : 3;
        unsigned int mem_ctrl_bank18 : 3;
        unsigned int mem_ctrl_bank19 : 3;
        unsigned int mem_ctrl_bank20 : 3;
        unsigned int mem_ctrl_bank21 : 3;
        unsigned int reserved : 14;
    } reg;
} SOC_IOMCU_MEM_CTRL3_UNION;
#endif
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank16_START (0)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank16_END (2)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank17_START (3)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank17_END (5)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank18_START (6)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank18_END (8)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank19_START (9)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank19_END (11)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank20_START (12)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank20_END (14)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank21_START (15)
#define SOC_IOMCU_MEM_CTRL3_mem_ctrl_bank21_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_IOMCU_DMA_USER_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_dma : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_IOMCU_MEM_CTRL4_UNION;
#endif
#define SOC_IOMCU_MEM_CTRL4_mem_ctrl_dma_START (0)
#define SOC_IOMCU_MEM_CTRL4_mem_ctrl_dma_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_i3c : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_IOMCU_MEM_CTRL5_UNION;
#endif
#define SOC_IOMCU_MEM_CTRL5_mem_ctrl_i3c_START (0)
#define SOC_IOMCU_MEM_CTRL5_mem_ctrl_i3c_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int araddr_chk : 32;
    } reg;
} SOC_IOMCU_ARADDR_CHK_UNION;
#endif
#define SOC_IOMCU_ARADDR_CHK_araddr_chk_START (0)
#define SOC_IOMCU_ARADDR_CHK_araddr_chk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int awaddr_chk : 32;
    } reg;
} SOC_IOMCU_AWADDR_CHK_UNION;
#endif
#define SOC_IOMCU_AWADDR_CHK_awaddr_chk_START (0)
#define SOC_IOMCU_AWADDR_CHK_awaddr_chk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int spi8_cs : 4;
        unsigned int spi9_cs : 4;
        unsigned int spi10_cs : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_IOMCU_MISC_CTRL_1_UNION;
#endif
#define SOC_IOMCU_MISC_CTRL_1_spi8_cs_START (0)
#define SOC_IOMCU_MISC_CTRL_1_spi8_cs_END (3)
#define SOC_IOMCU_MISC_CTRL_1_spi9_cs_START (4)
#define SOC_IOMCU_MISC_CTRL_1_spi9_cs_END (7)
#define SOC_IOMCU_MISC_CTRL_1_spi10_cs_START (8)
#define SOC_IOMCU_MISC_CTRL_1_spi10_cs_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_IOMCU_CCM_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cti_rtt_filters : 26;
        unsigned int arc_run_ack : 1;
        unsigned int arc_halt_ack : 1;
        unsigned int core_stalled : 1;
        unsigned int sys_tf_halt_r : 1;
        unsigned int reserved : 2;
    } reg;
} SOC_IOMCU_ARC_RB0_UNION;
#endif
#define SOC_IOMCU_ARC_RB0_cti_rtt_filters_START (0)
#define SOC_IOMCU_ARC_RB0_cti_rtt_filters_END (25)
#define SOC_IOMCU_ARC_RB0_arc_run_ack_START (26)
#define SOC_IOMCU_ARC_RB0_arc_run_ack_END (26)
#define SOC_IOMCU_ARC_RB0_arc_halt_ack_START (27)
#define SOC_IOMCU_ARC_RB0_arc_halt_ack_END (27)
#define SOC_IOMCU_ARC_RB0_core_stalled_START (28)
#define SOC_IOMCU_ARC_RB0_core_stalled_END (28)
#define SOC_IOMCU_ARC_RB0_sys_tf_halt_r_START (29)
#define SOC_IOMCU_ARC_RB0_sys_tf_halt_r_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int arcnum : 8;
        unsigned int clusternum : 8;
        unsigned int ccm_intr_clear : 1;
        unsigned int ccm_intr_bypass : 1;
        unsigned int ap_param0_read : 1;
        unsigned int ap_param1_read : 1;
        unsigned int ap_param0_write : 1;
        unsigned int ap_param1_write : 1;
        unsigned int dbg_cache_rst_disable : 1;
        unsigned int reserved_0 : 5;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_IOMCU_ARC_CTRL_UNION;
#endif
#define SOC_IOMCU_ARC_CTRL_arcnum_START (0)
#define SOC_IOMCU_ARC_CTRL_arcnum_END (7)
#define SOC_IOMCU_ARC_CTRL_clusternum_START (8)
#define SOC_IOMCU_ARC_CTRL_clusternum_END (15)
#define SOC_IOMCU_ARC_CTRL_ccm_intr_clear_START (16)
#define SOC_IOMCU_ARC_CTRL_ccm_intr_clear_END (16)
#define SOC_IOMCU_ARC_CTRL_ccm_intr_bypass_START (17)
#define SOC_IOMCU_ARC_CTRL_ccm_intr_bypass_END (17)
#define SOC_IOMCU_ARC_CTRL_ap_param0_read_START (18)
#define SOC_IOMCU_ARC_CTRL_ap_param0_read_END (18)
#define SOC_IOMCU_ARC_CTRL_ap_param1_read_START (19)
#define SOC_IOMCU_ARC_CTRL_ap_param1_read_END (19)
#define SOC_IOMCU_ARC_CTRL_ap_param0_write_START (20)
#define SOC_IOMCU_ARC_CTRL_ap_param0_write_END (20)
#define SOC_IOMCU_ARC_CTRL_ap_param1_write_START (21)
#define SOC_IOMCU_ARC_CTRL_ap_param1_write_END (21)
#define SOC_IOMCU_ARC_CTRL_dbg_cache_rst_disable_START (22)
#define SOC_IOMCU_ARC_CTRL_dbg_cache_rst_disable_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int clk_mcu_frac_div : 26;
        unsigned int clk_iomcu_p2j_div : 6;
    } reg;
} SOC_IOMCU_CLK_MCU_FRAC_DIV_CTRL_UNION;
#endif
#define SOC_IOMCU_CLK_MCU_FRAC_DIV_CTRL_clk_mcu_frac_div_START (0)
#define SOC_IOMCU_CLK_MCU_FRAC_DIV_CTRL_clk_mcu_frac_div_END (25)
#define SOC_IOMCU_CLK_MCU_FRAC_DIV_CTRL_clk_iomcu_p2j_div_START (26)
#define SOC_IOMCU_CLK_MCU_FRAC_DIV_CTRL_clk_iomcu_p2j_div_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dccm0_lo_err_addr : 16;
        unsigned int dccm0_hi_err_addr : 16;
    } reg;
} SOC_IOMCU_DCCM0_ERR_ADDR_UNION;
#endif
#define SOC_IOMCU_DCCM0_ERR_ADDR_dccm0_lo_err_addr_START (0)
#define SOC_IOMCU_DCCM0_ERR_ADDR_dccm0_lo_err_addr_END (15)
#define SOC_IOMCU_DCCM0_ERR_ADDR_dccm0_hi_err_addr_START (16)
#define SOC_IOMCU_DCCM0_ERR_ADDR_dccm0_hi_err_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dccm1_lo_err_addr : 16;
        unsigned int dccm1_hi_err_addr : 16;
    } reg;
} SOC_IOMCU_DCCM1_ERR_ADDR_UNION;
#endif
#define SOC_IOMCU_DCCM1_ERR_ADDR_dccm1_lo_err_addr_START (0)
#define SOC_IOMCU_DCCM1_ERR_ADDR_dccm1_lo_err_addr_END (15)
#define SOC_IOMCU_DCCM1_ERR_ADDR_dccm1_hi_err_addr_START (16)
#define SOC_IOMCU_DCCM1_ERR_ADDR_dccm1_hi_err_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iccm_bank0_err_addr : 16;
        unsigned int iccm_bank1_err_addr : 16;
    } reg;
} SOC_IOMCU_ICCM0_ERR_ADDR_UNION;
#endif
#define SOC_IOMCU_ICCM0_ERR_ADDR_iccm_bank0_err_addr_START (0)
#define SOC_IOMCU_ICCM0_ERR_ADDR_iccm_bank0_err_addr_END (15)
#define SOC_IOMCU_ICCM0_ERR_ADDR_iccm_bank1_err_addr_START (16)
#define SOC_IOMCU_ICCM0_ERR_ADDR_iccm_bank1_err_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dccm0_lo_err_cnt : 8;
        unsigned int dccm0_hi_err_cnt : 8;
        unsigned int dccm1_lo_err_cnt : 8;
        unsigned int dccm1_hi_err_cnt : 8;
    } reg;
} SOC_IOMCU_CCM_RB0_UNION;
#endif
#define SOC_IOMCU_CCM_RB0_dccm0_lo_err_cnt_START (0)
#define SOC_IOMCU_CCM_RB0_dccm0_lo_err_cnt_END (7)
#define SOC_IOMCU_CCM_RB0_dccm0_hi_err_cnt_START (8)
#define SOC_IOMCU_CCM_RB0_dccm0_hi_err_cnt_END (15)
#define SOC_IOMCU_CCM_RB0_dccm1_lo_err_cnt_START (16)
#define SOC_IOMCU_CCM_RB0_dccm1_lo_err_cnt_END (23)
#define SOC_IOMCU_CCM_RB0_dccm1_hi_err_cnt_START (24)
#define SOC_IOMCU_CCM_RB0_dccm1_hi_err_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iccm0_bank0_err_cnt : 8;
        unsigned int iccm0_bank1_err_cnt : 8;
        unsigned int dccm0_lo_out_bound_err : 1;
        unsigned int dccm0_hi_out_bound_err : 1;
        unsigned int dccm1_lo_out_bound_err : 1;
        unsigned int dccm1_hi_out_bound_err : 1;
        unsigned int iccm0_bank0_out_bound_err : 1;
        unsigned int iccm0_bank1_out_bound_err : 1;
        unsigned int ccm_err_status : 1;
        unsigned int reserved : 9;
    } reg;
} SOC_IOMCU_CCM_RB1_UNION;
#endif
#define SOC_IOMCU_CCM_RB1_iccm0_bank0_err_cnt_START (0)
#define SOC_IOMCU_CCM_RB1_iccm0_bank0_err_cnt_END (7)
#define SOC_IOMCU_CCM_RB1_iccm0_bank1_err_cnt_START (8)
#define SOC_IOMCU_CCM_RB1_iccm0_bank1_err_cnt_END (15)
#define SOC_IOMCU_CCM_RB1_dccm0_lo_out_bound_err_START (16)
#define SOC_IOMCU_CCM_RB1_dccm0_lo_out_bound_err_END (16)
#define SOC_IOMCU_CCM_RB1_dccm0_hi_out_bound_err_START (17)
#define SOC_IOMCU_CCM_RB1_dccm0_hi_out_bound_err_END (17)
#define SOC_IOMCU_CCM_RB1_dccm1_lo_out_bound_err_START (18)
#define SOC_IOMCU_CCM_RB1_dccm1_lo_out_bound_err_END (18)
#define SOC_IOMCU_CCM_RB1_dccm1_hi_out_bound_err_START (19)
#define SOC_IOMCU_CCM_RB1_dccm1_hi_out_bound_err_END (19)
#define SOC_IOMCU_CCM_RB1_iccm0_bank0_out_bound_err_START (20)
#define SOC_IOMCU_CCM_RB1_iccm0_bank0_out_bound_err_END (20)
#define SOC_IOMCU_CCM_RB1_iccm0_bank1_out_bound_err_START (21)
#define SOC_IOMCU_CCM_RB1_iccm0_bank1_out_bound_err_END (21)
#define SOC_IOMCU_CCM_RB1_ccm_err_status_START (22)
#define SOC_IOMCU_CCM_RB1_ccm_err_status_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cti_ap_status : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_IOMCU_ARC_RB1_UNION;
#endif
#define SOC_IOMCU_ARC_RB1_cti_ap_status_START (0)
#define SOC_IOMCU_ARC_RB1_cti_ap_status_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ap_param0 : 32;
    } reg;
} SOC_IOMCU_ARC_AP_PARAM0_UNION;
#endif
#define SOC_IOMCU_ARC_AP_PARAM0_ap_param0_START (0)
#define SOC_IOMCU_ARC_AP_PARAM0_ap_param0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ap_param1 : 32;
    } reg;
} SOC_IOMCU_ARC_AP_PARAM1_UNION;
#endif
#define SOC_IOMCU_ARC_AP_PARAM1_ap_param1_START (0)
#define SOC_IOMCU_ARC_AP_PARAM1_ap_param1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_en0 : 32;
    } reg;
} SOC_IOMCU_ARC_EVENT_EN0_UNION;
#endif
#define SOC_IOMCU_ARC_EVENT_EN0_event_en0_START (0)
#define SOC_IOMCU_ARC_EVENT_EN0_event_en0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_en1 : 32;
    } reg;
} SOC_IOMCU_ARC_EVENT_EN1_UNION;
#endif
#define SOC_IOMCU_ARC_EVENT_EN1_event_en1_START (0)
#define SOC_IOMCU_ARC_EVENT_EN1_event_en1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_en2 : 32;
    } reg;
} SOC_IOMCU_ARC_EVENT_EN2_UNION;
#endif
#define SOC_IOMCU_ARC_EVENT_EN2_event_en2_START (0)
#define SOC_IOMCU_ARC_EVENT_EN2_event_en2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_en3 : 32;
    } reg;
} SOC_IOMCU_ARC_EVENT_EN3_UNION;
#endif
#define SOC_IOMCU_ARC_EVENT_EN3_event_en3_START (0)
#define SOC_IOMCU_ARC_EVENT_EN3_event_en3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_en0 : 32;
    } reg;
} SOC_IOMCU_ARC_IRQ_EN0_UNION;
#endif
#define SOC_IOMCU_ARC_IRQ_EN0_irq_en0_START (0)
#define SOC_IOMCU_ARC_IRQ_EN0_irq_en0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_en1 : 32;
    } reg;
} SOC_IOMCU_ARC_IRQ_EN1_UNION;
#endif
#define SOC_IOMCU_ARC_IRQ_EN1_irq_en1_START (0)
#define SOC_IOMCU_ARC_IRQ_EN1_irq_en1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_en2 : 32;
    } reg;
} SOC_IOMCU_ARC_IRQ_EN2_UNION;
#endif
#define SOC_IOMCU_ARC_IRQ_EN2_irq_en2_START (0)
#define SOC_IOMCU_ARC_IRQ_EN2_irq_en2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int irq_en3 : 32;
    } reg;
} SOC_IOMCU_ARC_IRQ_EN3_UNION;
#endif
#define SOC_IOMCU_ARC_IRQ_EN3_irq_en3_START (0)
#define SOC_IOMCU_ARC_IRQ_EN3_irq_en3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_en4 : 32;
    } reg;
} SOC_IOMCU_ARC_EVENT_EN4_UNION;
#endif
#define SOC_IOMCU_ARC_EVENT_EN4_event_en4_START (0)
#define SOC_IOMCU_ARC_EVENT_EN4_event_en4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_en5 : 32;
    } reg;
} SOC_IOMCU_ARC_EVENT_EN5_UNION;
#endif
#define SOC_IOMCU_ARC_EVENT_EN5_event_en5_START (0)
#define SOC_IOMCU_ARC_EVENT_EN5_event_en5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_en6 : 32;
    } reg;
} SOC_IOMCU_ARC_EVENT_EN6_UNION;
#endif
#define SOC_IOMCU_ARC_EVENT_EN6_event_en6_START (0)
#define SOC_IOMCU_ARC_EVENT_EN6_event_en6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int event_en7 : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_IOMCU_ARC_EVENT_EN7_UNION;
#endif
#define SOC_IOMCU_ARC_EVENT_EN7_event_en7_START (0)
#define SOC_IOMCU_ARC_EVENT_EN7_event_en7_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int m7_ahb_dbg_info1 : 32;
    } reg;
} SOC_IOMCU_M7_AHB_DBG_INFO1_UNION;
#endif
#define SOC_IOMCU_M7_AHB_DBG_INFO1_m7_ahb_dbg_info1_START (0)
#define SOC_IOMCU_M7_AHB_DBG_INFO1_m7_ahb_dbg_info1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int m7_ahb_dbg_info2 : 32;
    } reg;
} SOC_IOMCU_M7_AHB_DBG_INFO2_UNION;
#endif
#define SOC_IOMCU_M7_AHB_DBG_INFO2_m7_ahb_dbg_info2_START (0)
#define SOC_IOMCU_M7_AHB_DBG_INFO2_m7_ahb_dbg_info2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int m7_ahb_time_cfg : 32;
    } reg;
} SOC_IOMCU_M7_AHB_TIME_CFG_UNION;
#endif
#define SOC_IOMCU_M7_AHB_TIME_CFG_m7_ahb_time_cfg_START (0)
#define SOC_IOMCU_M7_AHB_TIME_CFG_m7_ahb_time_cfg_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int m7_ahb_timeout_bypass : 1;
        unsigned int m7_ahb_timeout_resperr : 1;
        unsigned int m7_ahb_dbg_timeout_int_en : 1;
        unsigned int m7_ahb_dbg_timeout_int_clr : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_IOMCU_M7_AHB_TIMEOUT_UNION;
#endif
#define SOC_IOMCU_M7_AHB_TIMEOUT_m7_ahb_timeout_bypass_START (0)
#define SOC_IOMCU_M7_AHB_TIMEOUT_m7_ahb_timeout_bypass_END (0)
#define SOC_IOMCU_M7_AHB_TIMEOUT_m7_ahb_timeout_resperr_START (1)
#define SOC_IOMCU_M7_AHB_TIMEOUT_m7_ahb_timeout_resperr_END (1)
#define SOC_IOMCU_M7_AHB_TIMEOUT_m7_ahb_dbg_timeout_int_en_START (2)
#define SOC_IOMCU_M7_AHB_TIMEOUT_m7_ahb_dbg_timeout_int_en_END (2)
#define SOC_IOMCU_M7_AHB_TIMEOUT_m7_ahb_dbg_timeout_int_clr_START (3)
#define SOC_IOMCU_M7_AHB_TIMEOUT_m7_ahb_dbg_timeout_int_clr_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_iomcu_lx_mst_awqos : 4;
        unsigned int qic_iomcu_lx_mst_arqos : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_IOMCU_QIC_CTL_1_UNION;
#endif
#define SOC_IOMCU_QIC_CTL_1_qic_iomcu_lx_mst_awqos_START (0)
#define SOC_IOMCU_QIC_CTL_1_qic_iomcu_lx_mst_awqos_END (3)
#define SOC_IOMCU_QIC_CTL_1_qic_iomcu_lx_mst_arqos_START (4)
#define SOC_IOMCU_QIC_CTL_1_qic_iomcu_lx_mst_arqos_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_reserved_reg1 : 32;
    } reg;
} SOC_IOMCU_RESERVED_REG1_UNION;
#endif
#define SOC_IOMCU_RESERVED_REG1_iomcu_reserved_reg1_START (0)
#define SOC_IOMCU_RESERVED_REG1_iomcu_reserved_reg1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_linx_hart_id : 4;
        unsigned int io_dcsr_stoptime : 1;
        unsigned int io_in_double_excp_hdlr : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_IOMCU_RSV_HART_ID_UNION;
#endif
#define SOC_IOMCU_RSV_HART_ID_iomcu_linx_hart_id_START (0)
#define SOC_IOMCU_RSV_HART_ID_iomcu_linx_hart_id_END (3)
#define SOC_IOMCU_RSV_HART_ID_io_dcsr_stoptime_START (4)
#define SOC_IOMCU_RSV_HART_ID_io_dcsr_stoptime_END (4)
#define SOC_IOMCU_RSV_HART_ID_io_in_double_excp_hdlr_START (5)
#define SOC_IOMCU_RSV_HART_ID_io_in_double_excp_hdlr_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int io_top_dfx_cmt_vld_0 : 1;
        unsigned int io_top_dfx_cmt_vld_1 : 1;
        unsigned int io_top_dfx_cmt_gpr_vld_0 : 1;
        unsigned int io_top_dfx_cmt_gpr_vld_1 : 1;
        unsigned int io_top_dfx_cmt_gpr_idx_0 : 5;
        unsigned int io_top_dfx_cmt_gpr_idx_1 : 5;
        unsigned int reserved : 18;
    } reg;
} SOC_IOMCU_RSV_DFX0_UNION;
#endif
#define SOC_IOMCU_RSV_DFX0_io_top_dfx_cmt_vld_0_START (0)
#define SOC_IOMCU_RSV_DFX0_io_top_dfx_cmt_vld_0_END (0)
#define SOC_IOMCU_RSV_DFX0_io_top_dfx_cmt_vld_1_START (1)
#define SOC_IOMCU_RSV_DFX0_io_top_dfx_cmt_vld_1_END (1)
#define SOC_IOMCU_RSV_DFX0_io_top_dfx_cmt_gpr_vld_0_START (2)
#define SOC_IOMCU_RSV_DFX0_io_top_dfx_cmt_gpr_vld_0_END (2)
#define SOC_IOMCU_RSV_DFX0_io_top_dfx_cmt_gpr_vld_1_START (3)
#define SOC_IOMCU_RSV_DFX0_io_top_dfx_cmt_gpr_vld_1_END (3)
#define SOC_IOMCU_RSV_DFX0_io_top_dfx_cmt_gpr_idx_0_START (4)
#define SOC_IOMCU_RSV_DFX0_io_top_dfx_cmt_gpr_idx_0_END (8)
#define SOC_IOMCU_RSV_DFX0_io_top_dfx_cmt_gpr_idx_1_START (9)
#define SOC_IOMCU_RSV_DFX0_io_top_dfx_cmt_gpr_idx_1_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int io_top_dfx_cmt_pc_0 : 32;
    } reg;
} SOC_IOMCU_RSV_DFX1_UNION;
#endif
#define SOC_IOMCU_RSV_DFX1_io_top_dfx_cmt_pc_0_START (0)
#define SOC_IOMCU_RSV_DFX1_io_top_dfx_cmt_pc_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int io_top_dfx_cmt_pc_1 : 32;
    } reg;
} SOC_IOMCU_RSV_DFX2_UNION;
#endif
#define SOC_IOMCU_RSV_DFX2_io_top_dfx_cmt_pc_1_START (0)
#define SOC_IOMCU_RSV_DFX2_io_top_dfx_cmt_pc_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int io_top_dfx_cmt_gpr_data_0 : 32;
    } reg;
} SOC_IOMCU_RSV_DFX3_UNION;
#endif
#define SOC_IOMCU_RSV_DFX3_io_top_dfx_cmt_gpr_data_0_START (0)
#define SOC_IOMCU_RSV_DFX3_io_top_dfx_cmt_gpr_data_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int io_top_dfx_cmt_gpr_data_1 : 32;
    } reg;
} SOC_IOMCU_RSV_DFX4_UNION;
#endif
#define SOC_IOMCU_RSV_DFX4_io_top_dfx_cmt_gpr_data_1_START (0)
#define SOC_IOMCU_RSV_DFX4_io_top_dfx_cmt_gpr_data_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_rsten1_0hts_adp_mst : 1;
        unsigned int iomcu_rsten1_1hts_adp_slv : 1;
        unsigned int iomcu_rsten1_2i2c10 : 1;
        unsigned int iomcu_rsten1_3i2c11 : 1;
        unsigned int iomcu_rsten1_4spi9 : 1;
        unsigned int iomcu_rsten1_5spi10 : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_IOMCU_RSTEN1_UNION;
#endif
#define SOC_IOMCU_RSTEN1_iomcu_rsten1_0hts_adp_mst_START (0)
#define SOC_IOMCU_RSTEN1_iomcu_rsten1_0hts_adp_mst_END (0)
#define SOC_IOMCU_RSTEN1_iomcu_rsten1_1hts_adp_slv_START (1)
#define SOC_IOMCU_RSTEN1_iomcu_rsten1_1hts_adp_slv_END (1)
#define SOC_IOMCU_RSTEN1_iomcu_rsten1_2i2c10_START (2)
#define SOC_IOMCU_RSTEN1_iomcu_rsten1_2i2c10_END (2)
#define SOC_IOMCU_RSTEN1_iomcu_rsten1_3i2c11_START (3)
#define SOC_IOMCU_RSTEN1_iomcu_rsten1_3i2c11_END (3)
#define SOC_IOMCU_RSTEN1_iomcu_rsten1_4spi9_START (4)
#define SOC_IOMCU_RSTEN1_iomcu_rsten1_4spi9_END (4)
#define SOC_IOMCU_RSTEN1_iomcu_rsten1_5spi10_START (5)
#define SOC_IOMCU_RSTEN1_iomcu_rsten1_5spi10_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_rstdis1_0hts_adp_mst : 1;
        unsigned int iomcu_rstdis1_1hts_adp_slv : 1;
        unsigned int iomcu_rstdis1_2i2c10 : 1;
        unsigned int iomcu_rstdis1_2i2c11 : 1;
        unsigned int iomcu_rstdis1_4spi9 : 1;
        unsigned int iomcu_rstdis1_5spi10 : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_IOMCU_RSTDIS1_UNION;
#endif
#define SOC_IOMCU_RSTDIS1_iomcu_rstdis1_0hts_adp_mst_START (0)
#define SOC_IOMCU_RSTDIS1_iomcu_rstdis1_0hts_adp_mst_END (0)
#define SOC_IOMCU_RSTDIS1_iomcu_rstdis1_1hts_adp_slv_START (1)
#define SOC_IOMCU_RSTDIS1_iomcu_rstdis1_1hts_adp_slv_END (1)
#define SOC_IOMCU_RSTDIS1_iomcu_rstdis1_2i2c10_START (2)
#define SOC_IOMCU_RSTDIS1_iomcu_rstdis1_2i2c10_END (2)
#define SOC_IOMCU_RSTDIS1_iomcu_rstdis1_2i2c11_START (3)
#define SOC_IOMCU_RSTDIS1_iomcu_rstdis1_2i2c11_END (3)
#define SOC_IOMCU_RSTDIS1_iomcu_rstdis1_4spi9_START (4)
#define SOC_IOMCU_RSTDIS1_iomcu_rstdis1_4spi9_END (4)
#define SOC_IOMCU_RSTDIS1_iomcu_rstdis1_5spi10_START (5)
#define SOC_IOMCU_RSTDIS1_iomcu_rstdis1_5spi10_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int iomcu_rststat1_0hts_adp_mst : 1;
        unsigned int iomcu_rststat1_1hts_adp_slv : 1;
        unsigned int iomcu_rststat1_2i2c10 : 1;
        unsigned int iomcu_rststat1_3i2c11 : 1;
        unsigned int iomcu_rststat1_4spi9 : 1;
        unsigned int iomcu_rststat1_5spi10 : 1;
        unsigned int reserved : 26;
    } reg;
} SOC_IOMCU_RSTSTAT1_UNION;
#endif
#define SOC_IOMCU_RSTSTAT1_iomcu_rststat1_0hts_adp_mst_START (0)
#define SOC_IOMCU_RSTSTAT1_iomcu_rststat1_0hts_adp_mst_END (0)
#define SOC_IOMCU_RSTSTAT1_iomcu_rststat1_1hts_adp_slv_START (1)
#define SOC_IOMCU_RSTSTAT1_iomcu_rststat1_1hts_adp_slv_END (1)
#define SOC_IOMCU_RSTSTAT1_iomcu_rststat1_2i2c10_START (2)
#define SOC_IOMCU_RSTSTAT1_iomcu_rststat1_2i2c10_END (2)
#define SOC_IOMCU_RSTSTAT1_iomcu_rststat1_3i2c11_START (3)
#define SOC_IOMCU_RSTSTAT1_iomcu_rststat1_3i2c11_END (3)
#define SOC_IOMCU_RSTSTAT1_iomcu_rststat1_4spi9_START (4)
#define SOC_IOMCU_RSTSTAT1_iomcu_rststat1_4spi9_END (4)
#define SOC_IOMCU_RSTSTAT1_iomcu_rststat1_5spi10_START (5)
#define SOC_IOMCU_RSTSTAT1_iomcu_rststat1_5spi10_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int io_top_dfx_gpr_data : 32;
    } reg;
} SOC_IOMCU_RSV_DFX5_UNION;
#endif
#define SOC_IOMCU_RSV_DFX5_io_top_dfx_gpr_data_START (0)
#define SOC_IOMCU_RSV_DFX5_io_top_dfx_gpr_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tzpc_lock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_IOMCU_SEC_CTRL_UNION;
#endif
#define SOC_IOMCU_SEC_CTRL_tzpc_lock_START (0)
#define SOC_IOMCU_SEC_CTRL_tzpc_lock_END (0)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
