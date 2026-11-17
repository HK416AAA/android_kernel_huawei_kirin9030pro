#ifndef __SOC_ASP_CFG_INTERFACE_H__
#define __SOC_ASP_CFG_INTERFACE_H__ 
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_ASP_CFG_R_RST_CTRLEN_ADDR(base) ((base) + (0x0000UL))
#define SOC_ASP_CFG_R_RST_CTRLDIS_ADDR(base) ((base) + (0x0004UL))
#define SOC_ASP_CFG_R_RST_CTRLSTAT_ADDR(base) ((base) + (0x0008UL))
#define SOC_ASP_CFG_R_GATE_EN_ADDR(base) ((base) + (0x000CUL))
#define SOC_ASP_CFG_R_GATE_DIS_ADDR(base) ((base) + (0x0010UL))
#define SOC_ASP_CFG_R_GATE_CLKEN_ADDR(base) ((base) + (0x0014UL))
#define SOC_ASP_CFG_R_GATE_CLKSTAT_ADDR(base) ((base) + (0x0018UL))
#define SOC_ASP_CFG_R_GATE_CLKDIV_EN_ADDR(base) ((base) + (0x001CUL))
#define SOC_ASP_CFG_R_CLK1_DIV_ADDR(base) ((base) + (0x0020UL))
#define SOC_ASP_CFG_R_CLK2_DIV_ADDR(base) ((base) + (0x0024UL))
#define SOC_ASP_CFG_R_CLK3_DIV_ADDR(base) ((base) + (0x0028UL))
#define SOC_ASP_CFG_R_CLK4_DIV_ADDR(base) ((base) + (0x002CUL))
#define SOC_ASP_CFG_R_DMA0_REQ_SEL_ADDR(base) ((base) + (0x0030UL))
#define SOC_ASP_CFG_R_DMA1_REQ_SEL_ADDR(base) ((base) + (0x0034UL))
#define SOC_ASP_CFG_R_CLK_SEL_ADDR(base) ((base) + (0x0038UL))
#define SOC_ASP_CFG_R_DSP_NMI_ADDR(base) ((base) + (0x003CUL))
#define SOC_ASP_CFG_R_DMA_SEL_ADDR(base) ((base) + (0x0054UL))
#define SOC_ASP_CFG_R_BUS_PRIORITY_ADDR(base) ((base) + (0x0058UL))
#define SOC_ASP_CFG_R_CG_EN_ADDR(base) ((base) + (0x005CUL))
#define SOC_ASP_CFG_R_OCRAM_RET_ADDR(base) ((base) + (0x0060UL))
#define SOC_ASP_CFG_R_INTR_NS_INI_ADDR(base) ((base) + (0x0064UL))
#define SOC_ASP_CFG_R_INTR_NS_EN_ADDR(base) ((base) + (0x0068UL))
#define SOC_ASP_CFG_R_INTR_NS_MASK_ADDR(base) ((base) + (0x006CUL))
#define SOC_ASP_CFG_R_DBG_SET_AHB2AXI_ADDR(base) ((base) + (0x0070UL))
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_ADDR(base) ((base) + (0x0074UL))
#define SOC_ASP_CFG_R_DLOCK_BP_ADDR(base) ((base) + (0x0078UL))
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_ADDR(base) ((base) + (0x007CUL))
#define SOC_ASP_CFG_R_DSP_RAM_RET_ADDR(base) ((base) + (0x0084UL))
#define SOC_ASP_CFG_R_HIFIDSP_FLAG0_ADDR(base) ((base) + (0x0090UL))
#define SOC_ASP_CFG_R_HIFIDSP_FLAG1_ADDR(base) ((base) + (0x0094UL))
#define SOC_ASP_CFG_R_HIFIDSP_FLAG2_ADDR(base) ((base) + (0x0098UL))
#define SOC_ASP_CFG_R_HIFIDSP_FLAG3_ADDR(base) ((base) + (0x009CUL))
#define SOC_ASP_CFG_R_TZ_SECURE_N_ADDR(base) ((base) + (0x0100UL))
#define SOC_ASP_CFG_R_OCRAM_R0SIZE_ADDR(base) ((base) + (0x0104UL))
#define SOC_ASP_CFG_R_SIO_LOOP_SECURE_N_ADDR(base) ((base) + (0x0108UL))
#define SOC_ASP_CFG_R_INTR_S_INI_ADDR(base) ((base) + (0x010CUL))
#define SOC_ASP_CFG_R_INTR_S_EN_ADDR(base) ((base) + (0x0110UL))
#define SOC_ASP_CFG_R_INTR_S_MASK_ADDR(base) ((base) + (0x0114UL))
#define SOC_ASP_CFG_R_DSP_REMAPPING_EN_ADDR(base) ((base) + (0x0118UL))
#define SOC_ASP_CFG_R_DSP_REMAPPING_SRC_BASE_ADDR_ADDR(base) ((base) + (0x011CUL))
#define SOC_ASP_CFG_R_DSP_REMAPPING_DES_BASE_ADDR_ADDR(base) ((base) + (0x0120UL))
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_EN_ADDR(base) ((base) + (0x124UL))
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x128UL))
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x12CUL))
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_EN_ADDR(base) ((base) + (0x130UL))
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x134UL))
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x138UL))
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_EN_ADDR(base) ((base) + (0x13CUL))
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x140UL))
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x144UL))
#define SOC_ASP_CFG_R_MMBUF_CTRL_ADDR(base) ((base) + (0x0148UL))
#define SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_ADDR(base) ((base) + (0x014CUL))
#define SOC_ASP_CFG_R_INTR_FREQ_OFFSET_CFG_ADDR(base) ((base) + (0x0150UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_EN_ADDR_ADDR(base) ((base) + (0x0160UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_CLR_ADDR_ADDR(base) ((base) + (0x0164UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_EN_ADDR_ADDR(base) ((base) + (0x0168UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_ADDR(base) ((base) + (0x016CUL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_BASE_ADDR_ADDR(base) ((base) + (0x0170UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_LEN_ADDR_ADDR(base) ((base) + (0x0174UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_HIT_AWADDR_ADDR(base) ((base) + (0x0178UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_HIT_ARADDR_ADDR(base) ((base) + (0x017CUL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_BASE_ADDR_ADDR(base) ((base) + (0x0180UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_LEN_ADDR_ADDR(base) ((base) + (0x0184UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_HIT_AWADDR_ADDR(base) ((base) + (0x0188UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_HIT_ARADDR_ADDR(base) ((base) + (0x018CUL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_BASE_ADDR_ADDR(base) ((base) + (0x0190UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_LEN_ADDR_ADDR(base) ((base) + (0x0194UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_HIT_AWADDR_ADDR(base) ((base) + (0x0198UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_HIT_ARADDR_ADDR(base) ((base) + (0x019CUL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_BASE_ADDR_ADDR(base) ((base) + (0x01A0UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_LEN_ADDR_ADDR(base) ((base) + (0x01A4UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_HIT_AWADDR_ADDR(base) ((base) + (0x01A8UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_HIT_ARADDR_ADDR(base) ((base) + (0x01ACUL))
#define SOC_ASP_CFG_R_MEMORY_CTRL_ADDR(base) ((base) + (0x01B0UL))
#define SOC_ASP_CFG_R_HDMI_CLK_SEL_ADDR(base) ((base) + (0x01D8UL))
#define SOC_ASP_CFG_R_ACC_ADDR_MONI_BYPASS_ADDR_ADDR(base) ((base) + (0x01DCUL))
#define SOC_ASP_CFG_R_DIV_HDMI_I2S_ADWS_ADDR(base) ((base) + (0x01E0UL))
#define SOC_ASP_CFG_R_DIV_SPDIF_CLK_ADDR(base) ((base) + (0x01E4UL))
#define SOC_ASP_CFG_R_NOC_FIREWALL_CTRL_ADDR(base) ((base) + (0x01F4UL))
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_ADDR(base) ((base) + (0x0200UL))
#define SOC_ASP_CFG_R_SW_SLIM_DMA_SEL_ADDR(base) ((base) + (0x0218UL))
#define SOC_ASP_CFG_R_GATE1_EN_ADDR_ADDR(base) ((base) + (0x021CUL))
#define SOC_ASP_CFG_R_GATE1_DIS_ADDR_ADDR(base) ((base) + (0x0220UL))
#define SOC_ASP_CFG_R_GATE1_CLKEN_ADDR_ADDR(base) ((base) + (0x0224UL))
#define SOC_ASP_CFG_R_GATE1_CLKSTAT_ADDR_ADDR(base) ((base) + (0x0228UL))
#define SOC_ASP_CFG_R_MEMORY_CTRL_D1W2R_ADDR_ADDR(base) ((base) + (0x022CUL))
#define SOC_ASP_CFG_R_TEST_PROC_OUT_SW_ADDR(base) ((base) + (0x0230UL))
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_EN_ADDR(base) ((base) + (0x0234UL))
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x0238UL))
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x023CUL))
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_EN_ADDR(base) ((base) + (0x0240UL))
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x0244UL))
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x0248UL))
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_EN_ADDR(base) ((base) + (0x024CUL))
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x0250UL))
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x0254UL))
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_EN_ADDR(base) ((base) + (0x0258UL))
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x025CUL))
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x0260UL))
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_EN_ADDR(base) ((base) + (0x0264UL))
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x0268UL))
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x026CUL))
#define SOC_ASP_CFG_R_H2X_CACHE_ADDR_ADDR(base) ((base) + (0x0270UL))
#define SOC_ASP_CFG_R_HIFI_S2_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x0274UL))
#define SOC_ASP_CFG_R_HIFI_S2_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x0278UL))
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_EN_ADDR(base) ((base) + (0x027CUL))
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x0280UL))
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x0284UL))
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_EN_ADDR(base) ((base) + (0x0288UL))
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x028CUL))
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x0290UL))
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_EN_ADDR(base) ((base) + (0x0294UL))
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x0298UL))
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x029CUL))
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_EN_ADDR(base) ((base) + (0x02A0UL))
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x02A4UL))
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x02A8UL))
#define SOC_ASP_CFG_R_TZ_SECURE_1_N_ADDR(base) ((base) + (0x02ACUL))
#define SOC_ASP_CFG_R_DLOCK_BP_1_ADDR_ADDR(base) ((base) + (0x02B0UL))
#define SOC_ASP_CFG_R_MEMORY_CTRL1_ADDR(base) ((base) + (0x02C4UL))
#define SOC_ASP_CFG_DSP_AWUSER_CFG_LOW_ADDR(base) ((base) + (0x0300UL))
#define SOC_ASP_CFG_DSP_AWUSER_CFG_HIGH_ADDR(base) ((base) + (0x0304UL))
#define SOC_ASP_CFG_DSP_ARUSER_CFG_LOW_ADDR(base) ((base) + (0x0308UL))
#define SOC_ASP_CFG_DSP_ARUSER_CFG_HIGH_ADDR(base) ((base) + (0x030CUL))
#define SOC_ASP_CFG_EDMAC_AWUSER_CFG_LOW_ADDR(base) ((base) + (0x0310UL))
#define SOC_ASP_CFG_EDMAC_AWUSER_CFG_HIGH_ADDR(base) ((base) + (0x0314UL))
#define SOC_ASP_CFG_EDMAC_ARUSER_CFG_LOW_ADDR(base) ((base) + (0x0318UL))
#define SOC_ASP_CFG_EDMAC_ARUSER_CFG_HIGH_ADDR(base) ((base) + (0x031CUL))
#define SOC_ASP_CFG_HDMI_AWUSER_CFG_LOW_ADDR(base) ((base) + (0x0320UL))
#define SOC_ASP_CFG_HDMI_AWUSER_CFG_HIGH_ADDR(base) ((base) + (0x0324UL))
#define SOC_ASP_CFG_HDMI_ARUSER_CFG_LOW_ADDR(base) ((base) + (0x0328UL))
#define SOC_ASP_CFG_HDMI_ARUSER_CFG_HIGH_ADDR(base) ((base) + (0x032CUL))
#define SOC_ASP_CFG_CPU_AUDIO_BAK_ADDR(base) ((base) + (0x03E0UL))
#define SOC_ASP_CFG_DISPLAY_VSYNC_IRQ_CLR_ADDR(base) ((base) + (0x03E4UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR4_BASE_ADDR_ADDR(base) ((base) + (0x03ECUL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR4_LEN_ADDR_ADDR(base) ((base) + (0x3F0UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR4_HIT_AWADDR_ADDR(base) ((base) + (0x03F4UL))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR4_HIT_ARADDR_ADDR(base) ((base) + (0x03F8UL))
#define SOC_ASP_CFG_LL_CLK_CTRL_ADDR(base) ((base) + (0x0F00UL))
#define SOC_ASP_CFG_LL_ACCESS_ADDR_BASE0_ADDR(base) ((base) + (0x0F04UL))
#define SOC_ASP_CFG_LL_ACCESS_ADDR_BASE1_ADDR(base) ((base) + (0x0F08UL))
#define SOC_ASP_CFG_LL_ACCESS_ADDR_BASE2_ADDR(base) ((base) + (0x0F0CUL))
#define SOC_ASP_CFG_LL_DSS0_CTRL0_ADDR(base) ((base) + (0x0F10UL))
#define SOC_ASP_CFG_LL_DSS0_CTRL1_ADDR(base) ((base) + (0x0F14UL))
#define SOC_ASP_CFG_LL_DSS0_CTRL2_ADDR(base) ((base) + (0x0F18UL))
#define SOC_ASP_CFG_LL_DSS0_CTRL3_ADDR(base) ((base) + (0x0F1CUL))
#define SOC_ASP_CFG_LL_MEM_POWER_STATUS_ADDR(base) ((base) + (0x0F80UL))
#define SOC_ASP_CFG_LL_CLK_POWER_STATUS_ADDR(base) ((base) + (0x0F84UL))
#define SOC_ASP_CFG_LL_MP_DFX_ADDR(base) ((base) + (0x0F88UL))
#define SOC_ASP_CFG_LL_DSS_STATUS0_ADDR(base) ((base) + (0x0F8CUL))
#define SOC_ASP_CFG_LL_DSS_STATUS1_ADDR(base) ((base) + (0x0F90UL))
#define SOC_ASP_CFG_LL_JTAG_EN_ADDR(base) ((base) + (0x0F94UL))
#else
#define SOC_ASP_CFG_R_RST_CTRLEN_ADDR(base) ((base) + (0x0000))
#define SOC_ASP_CFG_R_RST_CTRLDIS_ADDR(base) ((base) + (0x0004))
#define SOC_ASP_CFG_R_RST_CTRLSTAT_ADDR(base) ((base) + (0x0008))
#define SOC_ASP_CFG_R_GATE_EN_ADDR(base) ((base) + (0x000C))
#define SOC_ASP_CFG_R_GATE_DIS_ADDR(base) ((base) + (0x0010))
#define SOC_ASP_CFG_R_GATE_CLKEN_ADDR(base) ((base) + (0x0014))
#define SOC_ASP_CFG_R_GATE_CLKSTAT_ADDR(base) ((base) + (0x0018))
#define SOC_ASP_CFG_R_GATE_CLKDIV_EN_ADDR(base) ((base) + (0x001C))
#define SOC_ASP_CFG_R_CLK1_DIV_ADDR(base) ((base) + (0x0020))
#define SOC_ASP_CFG_R_CLK2_DIV_ADDR(base) ((base) + (0x0024))
#define SOC_ASP_CFG_R_CLK3_DIV_ADDR(base) ((base) + (0x0028))
#define SOC_ASP_CFG_R_CLK4_DIV_ADDR(base) ((base) + (0x002C))
#define SOC_ASP_CFG_R_DMA0_REQ_SEL_ADDR(base) ((base) + (0x0030))
#define SOC_ASP_CFG_R_DMA1_REQ_SEL_ADDR(base) ((base) + (0x0034))
#define SOC_ASP_CFG_R_CLK_SEL_ADDR(base) ((base) + (0x0038))
#define SOC_ASP_CFG_R_DSP_NMI_ADDR(base) ((base) + (0x003C))
#define SOC_ASP_CFG_R_DMA_SEL_ADDR(base) ((base) + (0x0054))
#define SOC_ASP_CFG_R_BUS_PRIORITY_ADDR(base) ((base) + (0x0058))
#define SOC_ASP_CFG_R_CG_EN_ADDR(base) ((base) + (0x005C))
#define SOC_ASP_CFG_R_OCRAM_RET_ADDR(base) ((base) + (0x0060))
#define SOC_ASP_CFG_R_INTR_NS_INI_ADDR(base) ((base) + (0x0064))
#define SOC_ASP_CFG_R_INTR_NS_EN_ADDR(base) ((base) + (0x0068))
#define SOC_ASP_CFG_R_INTR_NS_MASK_ADDR(base) ((base) + (0x006C))
#define SOC_ASP_CFG_R_DBG_SET_AHB2AXI_ADDR(base) ((base) + (0x0070))
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_ADDR(base) ((base) + (0x0074))
#define SOC_ASP_CFG_R_DLOCK_BP_ADDR(base) ((base) + (0x0078))
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_ADDR(base) ((base) + (0x007C))
#define SOC_ASP_CFG_R_DSP_RAM_RET_ADDR(base) ((base) + (0x0084))
#define SOC_ASP_CFG_R_HIFIDSP_FLAG0_ADDR(base) ((base) + (0x0090))
#define SOC_ASP_CFG_R_HIFIDSP_FLAG1_ADDR(base) ((base) + (0x0094))
#define SOC_ASP_CFG_R_HIFIDSP_FLAG2_ADDR(base) ((base) + (0x0098))
#define SOC_ASP_CFG_R_HIFIDSP_FLAG3_ADDR(base) ((base) + (0x009C))
#define SOC_ASP_CFG_R_TZ_SECURE_N_ADDR(base) ((base) + (0x0100))
#define SOC_ASP_CFG_R_OCRAM_R0SIZE_ADDR(base) ((base) + (0x0104))
#define SOC_ASP_CFG_R_SIO_LOOP_SECURE_N_ADDR(base) ((base) + (0x0108))
#define SOC_ASP_CFG_R_INTR_S_INI_ADDR(base) ((base) + (0x010C))
#define SOC_ASP_CFG_R_INTR_S_EN_ADDR(base) ((base) + (0x0110))
#define SOC_ASP_CFG_R_INTR_S_MASK_ADDR(base) ((base) + (0x0114))
#define SOC_ASP_CFG_R_DSP_REMAPPING_EN_ADDR(base) ((base) + (0x0118))
#define SOC_ASP_CFG_R_DSP_REMAPPING_SRC_BASE_ADDR_ADDR(base) ((base) + (0x011C))
#define SOC_ASP_CFG_R_DSP_REMAPPING_DES_BASE_ADDR_ADDR(base) ((base) + (0x0120))
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_EN_ADDR(base) ((base) + (0x124))
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x128))
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x12C))
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_EN_ADDR(base) ((base) + (0x130))
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x134))
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x138))
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_EN_ADDR(base) ((base) + (0x13C))
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x140))
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x144))
#define SOC_ASP_CFG_R_MMBUF_CTRL_ADDR(base) ((base) + (0x0148))
#define SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_ADDR(base) ((base) + (0x014C))
#define SOC_ASP_CFG_R_INTR_FREQ_OFFSET_CFG_ADDR(base) ((base) + (0x0150))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_EN_ADDR_ADDR(base) ((base) + (0x0160))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_CLR_ADDR_ADDR(base) ((base) + (0x0164))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_EN_ADDR_ADDR(base) ((base) + (0x0168))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_ADDR(base) ((base) + (0x016C))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_BASE_ADDR_ADDR(base) ((base) + (0x0170))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_LEN_ADDR_ADDR(base) ((base) + (0x0174))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_HIT_AWADDR_ADDR(base) ((base) + (0x0178))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_HIT_ARADDR_ADDR(base) ((base) + (0x017C))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_BASE_ADDR_ADDR(base) ((base) + (0x0180))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_LEN_ADDR_ADDR(base) ((base) + (0x0184))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_HIT_AWADDR_ADDR(base) ((base) + (0x0188))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_HIT_ARADDR_ADDR(base) ((base) + (0x018C))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_BASE_ADDR_ADDR(base) ((base) + (0x0190))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_LEN_ADDR_ADDR(base) ((base) + (0x0194))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_HIT_AWADDR_ADDR(base) ((base) + (0x0198))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_HIT_ARADDR_ADDR(base) ((base) + (0x019C))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_BASE_ADDR_ADDR(base) ((base) + (0x01A0))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_LEN_ADDR_ADDR(base) ((base) + (0x01A4))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_HIT_AWADDR_ADDR(base) ((base) + (0x01A8))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_HIT_ARADDR_ADDR(base) ((base) + (0x01AC))
#define SOC_ASP_CFG_R_MEMORY_CTRL_ADDR(base) ((base) + (0x01B0))
#define SOC_ASP_CFG_R_HDMI_CLK_SEL_ADDR(base) ((base) + (0x01D8))
#define SOC_ASP_CFG_R_ACC_ADDR_MONI_BYPASS_ADDR_ADDR(base) ((base) + (0x01DC))
#define SOC_ASP_CFG_R_DIV_HDMI_I2S_ADWS_ADDR(base) ((base) + (0x01E0))
#define SOC_ASP_CFG_R_DIV_SPDIF_CLK_ADDR(base) ((base) + (0x01E4))
#define SOC_ASP_CFG_R_NOC_FIREWALL_CTRL_ADDR(base) ((base) + (0x01F4))
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_ADDR(base) ((base) + (0x0200))
#define SOC_ASP_CFG_R_SW_SLIM_DMA_SEL_ADDR(base) ((base) + (0x0218))
#define SOC_ASP_CFG_R_GATE1_EN_ADDR_ADDR(base) ((base) + (0x021C))
#define SOC_ASP_CFG_R_GATE1_DIS_ADDR_ADDR(base) ((base) + (0x0220))
#define SOC_ASP_CFG_R_GATE1_CLKEN_ADDR_ADDR(base) ((base) + (0x0224))
#define SOC_ASP_CFG_R_GATE1_CLKSTAT_ADDR_ADDR(base) ((base) + (0x0228))
#define SOC_ASP_CFG_R_MEMORY_CTRL_D1W2R_ADDR_ADDR(base) ((base) + (0x022C))
#define SOC_ASP_CFG_R_TEST_PROC_OUT_SW_ADDR(base) ((base) + (0x0230))
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_EN_ADDR(base) ((base) + (0x0234))
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x0238))
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x023C))
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_EN_ADDR(base) ((base) + (0x0240))
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x0244))
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x0248))
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_EN_ADDR(base) ((base) + (0x024C))
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x0250))
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x0254))
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_EN_ADDR(base) ((base) + (0x0258))
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x025C))
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x0260))
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_EN_ADDR(base) ((base) + (0x0264))
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x0268))
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x026C))
#define SOC_ASP_CFG_R_H2X_CACHE_ADDR_ADDR(base) ((base) + (0x0270))
#define SOC_ASP_CFG_R_HIFI_S2_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x0274))
#define SOC_ASP_CFG_R_HIFI_S2_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x0278))
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_EN_ADDR(base) ((base) + (0x027C))
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x0280))
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x0284))
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_EN_ADDR(base) ((base) + (0x0288))
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x028C))
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x0290))
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_EN_ADDR(base) ((base) + (0x0294))
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x0298))
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x029C))
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_EN_ADDR(base) ((base) + (0x02A0))
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_SRC_BASE_ADDR_ADDR(base) ((base) + (0x02A4))
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_DES_BASE_ADDR_ADDR(base) ((base) + (0x02A8))
#define SOC_ASP_CFG_R_TZ_SECURE_1_N_ADDR(base) ((base) + (0x02AC))
#define SOC_ASP_CFG_R_DLOCK_BP_1_ADDR_ADDR(base) ((base) + (0x02B0))
#define SOC_ASP_CFG_R_MEMORY_CTRL1_ADDR(base) ((base) + (0x02C4))
#define SOC_ASP_CFG_DSP_AWUSER_CFG_LOW_ADDR(base) ((base) + (0x0300))
#define SOC_ASP_CFG_DSP_AWUSER_CFG_HIGH_ADDR(base) ((base) + (0x0304))
#define SOC_ASP_CFG_DSP_ARUSER_CFG_LOW_ADDR(base) ((base) + (0x0308))
#define SOC_ASP_CFG_DSP_ARUSER_CFG_HIGH_ADDR(base) ((base) + (0x030C))
#define SOC_ASP_CFG_EDMAC_AWUSER_CFG_LOW_ADDR(base) ((base) + (0x0310))
#define SOC_ASP_CFG_EDMAC_AWUSER_CFG_HIGH_ADDR(base) ((base) + (0x0314))
#define SOC_ASP_CFG_EDMAC_ARUSER_CFG_LOW_ADDR(base) ((base) + (0x0318))
#define SOC_ASP_CFG_EDMAC_ARUSER_CFG_HIGH_ADDR(base) ((base) + (0x031C))
#define SOC_ASP_CFG_HDMI_AWUSER_CFG_LOW_ADDR(base) ((base) + (0x0320))
#define SOC_ASP_CFG_HDMI_AWUSER_CFG_HIGH_ADDR(base) ((base) + (0x0324))
#define SOC_ASP_CFG_HDMI_ARUSER_CFG_LOW_ADDR(base) ((base) + (0x0328))
#define SOC_ASP_CFG_HDMI_ARUSER_CFG_HIGH_ADDR(base) ((base) + (0x032C))
#define SOC_ASP_CFG_CPU_AUDIO_BAK_ADDR(base) ((base) + (0x03E0))
#define SOC_ASP_CFG_DISPLAY_VSYNC_IRQ_CLR_ADDR(base) ((base) + (0x03E4))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR4_BASE_ADDR_ADDR(base) ((base) + (0x03EC))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR4_LEN_ADDR_ADDR(base) ((base) + (0x3F0))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR4_HIT_AWADDR_ADDR(base) ((base) + (0x03F4))
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR4_HIT_ARADDR_ADDR(base) ((base) + (0x03F8))
#define SOC_ASP_CFG_LL_CLK_CTRL_ADDR(base) ((base) + (0x0F00))
#define SOC_ASP_CFG_LL_ACCESS_ADDR_BASE0_ADDR(base) ((base) + (0x0F04))
#define SOC_ASP_CFG_LL_ACCESS_ADDR_BASE1_ADDR(base) ((base) + (0x0F08))
#define SOC_ASP_CFG_LL_ACCESS_ADDR_BASE2_ADDR(base) ((base) + (0x0F0C))
#define SOC_ASP_CFG_LL_DSS0_CTRL0_ADDR(base) ((base) + (0x0F10))
#define SOC_ASP_CFG_LL_DSS0_CTRL1_ADDR(base) ((base) + (0x0F14))
#define SOC_ASP_CFG_LL_DSS0_CTRL2_ADDR(base) ((base) + (0x0F18))
#define SOC_ASP_CFG_LL_DSS0_CTRL3_ADDR(base) ((base) + (0x0F1C))
#define SOC_ASP_CFG_LL_MEM_POWER_STATUS_ADDR(base) ((base) + (0x0F80))
#define SOC_ASP_CFG_LL_CLK_POWER_STATUS_ADDR(base) ((base) + (0x0F84))
#define SOC_ASP_CFG_LL_MP_DFX_ADDR(base) ((base) + (0x0F88))
#define SOC_ASP_CFG_LL_DSS_STATUS0_ADDR(base) ((base) + (0x0F8C))
#define SOC_ASP_CFG_LL_DSS_STATUS1_ADDR(base) ((base) + (0x0F90))
#define SOC_ASP_CFG_LL_JTAG_EN_ADDR(base) ((base) + (0x0F94))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int enable_rst_dsp_n : 1;
        unsigned int enable_rst_dsp_jtag_debug_n : 1;
        unsigned int enable_rst_ipc_n : 1;
        unsigned int enable_rst_asp_hdmi_n : 1;
        unsigned int enable_rst_dmac_n : 1;
        unsigned int enable_rst_codec_n : 1;
        unsigned int enable_rst_uart_n : 1;
        unsigned int enable_rst_ocram_n : 1;
        unsigned int enable_rst_hts_mst_n : 1;
        unsigned int enable_rst_hts_slv_n : 1;
        unsigned int reserved_4 : 1;
        unsigned int enable_rst_asp_h2x_n : 1;
        unsigned int enable_rst_gpio_n : 1;
        unsigned int enable_rst_timer0_n : 1;
        unsigned int enable_rst_timer1_n : 1;
        unsigned int enable_rst_dmac1_n : 1;
        unsigned int enable_dsp_jtag_srst_req_n : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int enable_rst_axi2tdm_n : 1;
        unsigned int enable_rst_dsp1_n : 1;
        unsigned int enable_rst_dsp1_debug_n : 1;
        unsigned int enable_rst_ipc1_n : 1;
        unsigned int reserved_9 : 3;
    } reg;
} SOC_ASP_CFG_R_RST_CTRLEN_UNION;
#endif
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_dsp_n_START (4)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_dsp_n_END (4)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_dsp_debug_n_START (5)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_dsp_debug_n_END (5)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_ipc_n_START (6)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_ipc_n_END (6)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_asp_hdmi_n_START (7)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_asp_hdmi_n_END (7)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_dmac_n_START (8)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_dmac_n_END (8)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_codec_n_START (9)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_codec_n_END (9)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_uart_n_START (10)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_uart_n_END (10)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_ocram_n_START (11)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_ocram_n_END (11)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_hts_mst_n_START (12)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_hts_mst_n_END (12)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_hts_slv_n_START (13)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_hts_slv_n_END (13)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_asp_h2x_n_START (15)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_asp_h2x_n_END (15)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_gpio_n_START (16)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_gpio_n_END (16)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_timer0_n_START (17)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_timer0_n_END (17)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_timer1_n_START (18)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_timer1_n_END (18)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_dmac1_n_START (19)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_dmac1_n_END (19)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_dsp_jtag_srst_req_n_START (20)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_dsp_jtag_srst_req_n_END (20)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_axi2tdm_n_START (25)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_axi2tdm_n_END (25)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_dsp1_n_START (26)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_dsp1_n_END (26)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_dsp1_debug_n_START (27)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_dsp1_debug_n_END (27)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_ipc1_n_START (28)
#define SOC_ASP_CFG_R_RST_CTRLEN_enable_rst_ipc1_n_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int disable_rst_dsp_n : 1;
        unsigned int disable_rst_dsp_jtag_debug_n : 1;
        unsigned int disable_rst_ipc_n : 1;
        unsigned int disable_rst_asp_hdmi_n : 1;
        unsigned int disable_rst_dmac_n : 1;
        unsigned int disable_rst_codec_n : 1;
        unsigned int disable_rst_uart_n : 1;
        unsigned int disable_rst_ocram_n : 1;
        unsigned int disable_rst_hts_mst_n : 1;
        unsigned int disable_rst_hts_slv_n : 1;
        unsigned int reserved_4 : 1;
        unsigned int disable_rst_asp_h2x_n : 1;
        unsigned int disable_rst_gpio_n : 1;
        unsigned int disable_rst_timer0_n : 1;
        unsigned int disable_rst_timer1_n : 1;
        unsigned int disable_rst_dmac1_n : 1;
        unsigned int disable_dsp_jtag_srst_req_n : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int disable_rst_axi2tdm_n : 1;
        unsigned int disable_rst_dsp1_n : 1;
        unsigned int disable_rst_dsp1_debug_n : 1;
        unsigned int disable_rst_ipc1_n : 1;
        unsigned int reserved_9 : 3;
    } reg;
} SOC_ASP_CFG_R_RST_CTRLDIS_UNION;
#endif
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_dsp_n_START (4)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_dsp_n_END (4)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_dsp_jtag_debug_n_START (5)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_dsp_jtag_debug_n_END (5)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_ipc_n_START (6)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_ipc_n_END (6)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_asp_hdmi_n_START (7)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_asp_hdmi_n_END (7)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_dmac_n_START (8)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_dmac_n_END (8)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_codec_n_START (9)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_codec_n_END (9)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_uart_n_START (10)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_uart_n_END (10)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_ocram_n_START (11)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_ocram_n_END (11)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_hts_mst_n_START (12)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_hts_mst_n_END (12)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_hts_slv_n_START (13)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_hts_slv_n_END (13)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_asp_h2x_n_START (15)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_asp_h2x_n_END (15)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_gpio_n_START (16)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_gpio_n_END (16)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_timer0_n_START (17)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_timer0_n_END (17)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_timer1_n_START (18)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_timer1_n_END (18)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_dmac1_n_START (19)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_dmac1_n_END (19)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_dsp_jtag_srst_req_n_START (20)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_dsp_jtag_srst_req_n_END (20)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_axi2tdm_n_START (25)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_axi2tdm_n_END (25)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_dsp1_n_START (26)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_dsp1_n_END (26)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_dsp1_debug_n_START (27)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_dsp1_debug_n_END (27)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_ipc1_n_START (28)
#define SOC_ASP_CFG_R_RST_CTRLDIS_disable_rst_ipc1_n_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int rst_dsp_n : 1;
        unsigned int rst_dsp_jtag_debug_n : 1;
        unsigned int rst_ipc_n : 1;
        unsigned int rst_asp_hdmi_n : 1;
        unsigned int rst_dmac_n : 1;
        unsigned int rst_codec_n : 1;
        unsigned int rst_uart_m_n : 1;
        unsigned int rst_ocram_n : 1;
        unsigned int rst_hts_mst_n : 1;
        unsigned int rst_hts_slv_n : 1;
        unsigned int rst_audio_multi_acc_n : 1;
        unsigned int rst_asp_h2x_n : 1;
        unsigned int rst_gpio_n : 1;
        unsigned int rst_timer0_n : 1;
        unsigned int rst_timer1_n : 1;
        unsigned int rst_dmac1_n : 1;
        unsigned int dsp_jtag_srst_req_n : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int rst_swire_ahb_n : 1;
        unsigned int reserved_6 : 1;
        unsigned int rst_axi2tdm_n : 1;
        unsigned int rst_dsp1_n : 1;
        unsigned int rst_dsp1_debug_n : 1;
        unsigned int rst_ipc1_n : 1;
        unsigned int reserved_7 : 3;
    } reg;
} SOC_ASP_CFG_R_RST_CTRLSTAT_UNION;
#endif
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_dsp_n_START (4)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_dsp_n_END (4)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_dsp_jtag_debug_n_START (5)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_dsp_jtag_debug_n_END (5)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_ipc_n_START (6)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_ipc_n_END (6)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_asp_hdmi_n_START (7)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_asp_hdmi_n_END (7)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_dmac_n_START (8)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_dmac_n_END (8)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_codec_n_START (9)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_codec_n_END (9)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_uart_m_n_START (10)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_uart_m_n_END (10)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_ocram_n_START (11)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_ocram_n_END (11)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_hts_mst_n_START (12)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_hts_mst_n_END (12)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_hts_slv_n_START (13)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_hts_slv_n_END (13)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_audio_multi_acc_n_START (14)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_audio_multi_acc_n_END (14)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_asp_h2x_n_START (15)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_asp_h2x_n_END (15)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_gpio_n_START (16)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_gpio_n_END (16)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_timer0_n_START (17)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_timer0_n_END (17)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_timer1_n_START (18)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_timer1_n_END (18)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_dmac1_n_START (19)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_dmac1_n_END (19)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_dsp_jtag_srst_req_n_START (20)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_dsp_jtag_srst_req_n_END (20)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_swire_ahb_n_START (23)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_swire_ahb_n_END (23)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_axi2tdm_n_START (25)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_axi2tdm_n_END (25)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_dsp1_n_START (26)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_dsp1_n_END (26)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_dsp1_debug_n_START (27)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_dsp1_debug_n_END (27)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_ipc1_n_START (28)
#define SOC_ASP_CFG_R_RST_CTRLSTAT_rst_ipc1_n_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int enable_gt_hifidspclk : 1;
        unsigned int enable_gt_dspjtagdebugclk : 1;
        unsigned int reserved_0 : 1;
        unsigned int enable_gt_codec_clk : 1;
        unsigned int enable_gt_hifidsp1clk : 1;
        unsigned int reserved_1 : 1;
        unsigned int enable_gt_pa_clk_out : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int enable_gt_ipchclk : 1;
        unsigned int enable_gt_hdmihclk : 1;
        unsigned int enable_gt_dmachclk : 1;
        unsigned int reserved_4 : 1;
        unsigned int enable_gt_asp_dmmu_clk : 1;
        unsigned int enable_gt_ocramhclk : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int enable_gt_uart : 1;
        unsigned int enable_gt_asp_h2x : 1;
        unsigned int enable_gt_spdifclk : 1;
        unsigned int enable_gt_hdmibclk : 1;
        unsigned int enable_gt_gpiohclk : 1;
        unsigned int enable_gt_timer0hclk : 1;
        unsigned int enable_gt_timer1hclk : 1;
        unsigned int enable_gt_ipc1hclk : 1;
        unsigned int enable_gt_audio_pll : 1;
        unsigned int enable_gt_spdifclk_o : 1;
        unsigned int enable_gt_hts_mst : 1;
        unsigned int enable_gt_hts_slv : 1;
        unsigned int enable_gt_audio_multi_acc : 1;
        unsigned int enable_axi2tdm_clk : 1;
        unsigned int enable_gt_dma1chclk : 1;
    } reg;
} SOC_ASP_CFG_R_GATE_EN_UNION;
#endif
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_hifidspclk_START (0)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_hifidspclk_END (0)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_dspjtagdebugclk_START (1)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_dspjtagdebugclk_END (1)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_codec_clk_START (3)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_codec_clk_END (3)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_hifidsp1clk_START (4)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_hifidsp1clk_END (4)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_pa_clk_out_START (6)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_pa_clk_out_END (6)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_ipchclk_START (9)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_ipchclk_END (9)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_hdmihclk_START (10)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_hdmihclk_END (10)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_dmachclk_START (11)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_dmachclk_END (11)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_asp_dmmu_clk_START (13)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_asp_dmmu_clk_END (13)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_ocramhclk_START (14)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_ocramhclk_END (14)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_uart_START (17)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_uart_END (17)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_asp_h2x_START (18)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_asp_h2x_END (18)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_spdifclk_START (19)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_spdifclk_END (19)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_hdmibclk_START (20)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_hdmibclk_END (20)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_gpiohclk_START (21)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_gpiohclk_END (21)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_timer0hclk_START (22)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_timer0hclk_END (22)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_timer1hclk_START (23)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_timer1hclk_END (23)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_ipc1hclk_START (24)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_ipc1hclk_END (24)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_audio_pll_START (25)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_audio_pll_END (25)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_spdifclk_o_START (26)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_spdifclk_o_END (26)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_hts_mst_START (27)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_hts_mst_END (27)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_hts_slv_START (28)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_hts_slv_END (28)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_audio_multi_acc_START (29)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_audio_multi_acc_END (29)
#define SOC_ASP_CFG_R_GATE_EN_enable_axi2tdm_clk_START (30)
#define SOC_ASP_CFG_R_GATE_EN_enable_axi2tdm_clk_END (30)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_dma1chclk_START (31)
#define SOC_ASP_CFG_R_GATE_EN_enable_gt_dma1chclk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int disable_gt_hifidspclk : 1;
        unsigned int disable_gt_dspjtagdebugclk : 1;
        unsigned int reserved_0 : 1;
        unsigned int disable_gt_codec : 1;
        unsigned int disable_gt_hifidsp1clk : 1;
        unsigned int reserved_1 : 1;
        unsigned int disable_gt_pa_clk_out : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int disable_gt_ipchclk : 1;
        unsigned int disable_gt_hdmihclk : 1;
        unsigned int disable_gt_dmachclk : 1;
        unsigned int reserved_4 : 1;
        unsigned int disable_gt_asp_dmmu_clk : 1;
        unsigned int disable_gt_ocramhclk : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int disable_gt_uart : 1;
        unsigned int disable_gt_asp_h2x : 1;
        unsigned int disable_gt_spdifclk : 1;
        unsigned int disable_gt_hdmibclk : 1;
        unsigned int disable_gt_gpiohclk : 1;
        unsigned int disable_gt_timer0hclk : 1;
        unsigned int disable_gt_timer1hclk : 1;
        unsigned int disable_gt_ipc1hclk : 1;
        unsigned int disable_gt_audio_pll : 1;
        unsigned int disable_gt_spdifclk_o : 1;
        unsigned int disable_gt_hts_mst : 1;
        unsigned int disable_gt_hts_slv : 1;
        unsigned int disable_gt_audio_multi_acc : 1;
        unsigned int disable_axi2tdm_clk : 1;
        unsigned int disable_gt_dmac1hclk : 1;
    } reg;
} SOC_ASP_CFG_R_GATE_DIS_UNION;
#endif
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_hifidspclk_START (0)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_hifidspclk_END (0)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_dspjtagdebugclk_START (1)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_dspjtagdebugclk_END (1)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_codec_START (3)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_codec_END (3)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_hifidsp1clk_START (4)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_hifidsp1clk_END (4)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_pa_clk_out_START (6)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_pa_clk_out_END (6)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_ipchclk_START (9)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_ipchclk_END (9)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_hdmihclk_START (10)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_hdmihclk_END (10)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_dmachclk_START (11)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_dmachclk_END (11)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_asp_dmmu_clk_START (13)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_asp_dmmu_clk_END (13)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_ocramhclk_START (14)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_ocramhclk_END (14)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_uart_START (17)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_uart_END (17)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_asp_h2x_START (18)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_asp_h2x_END (18)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_spdifclk_START (19)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_spdifclk_END (19)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_hdmibclk_START (20)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_hdmibclk_END (20)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_gpiohclk_START (21)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_gpiohclk_END (21)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_timer0hclk_START (22)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_timer0hclk_END (22)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_timer1hclk_START (23)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_timer1hclk_END (23)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_ipc1hclk_START (24)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_ipc1hclk_END (24)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_audio_pll_START (25)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_audio_pll_END (25)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_spdifclk_o_START (26)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_spdifclk_o_END (26)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_hts_mst_START (27)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_hts_mst_END (27)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_hts_slv_START (28)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_hts_slv_END (28)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_audio_multi_acc_START (29)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_audio_multi_acc_END (29)
#define SOC_ASP_CFG_R_GATE_DIS_disable_axi2tdm_clk_START (30)
#define SOC_ASP_CFG_R_GATE_DIS_disable_axi2tdm_clk_END (30)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_dmac1hclk_START (31)
#define SOC_ASP_CFG_R_GATE_DIS_disable_gt_dmac1hclk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_hifidspclk : 1;
        unsigned int gt_dspjtagdebug_clk : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_codec_clk : 1;
        unsigned int gt_hifidsp1clk : 1;
        unsigned int reserved_1 : 1;
        unsigned int gt_pa_clk_out : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_ipchclk : 1;
        unsigned int gt_hdmihclk : 1;
        unsigned int gt_dmachclk : 1;
        unsigned int reserved_4 : 1;
        unsigned int gt_asp_dmmu_clk : 1;
        unsigned int gt_ocramhclk : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int gt_uart_clk : 1;
        unsigned int gt_asp_h2x : 1;
        unsigned int gt_spdifclk : 1;
        unsigned int gt_hdmibclk : 1;
        unsigned int gt_gpiohclk : 1;
        unsigned int gt_timer0hclk : 1;
        unsigned int gt_timer1hclk : 1;
        unsigned int gt_ipc1hclk : 1;
        unsigned int gt_audio_pll : 1;
        unsigned int gt_spdifclk_o : 1;
        unsigned int gt_hts_mst_clk : 1;
        unsigned int gt_hts_slv_clk : 1;
        unsigned int gt_audio_multi_acc_clk : 1;
        unsigned int gt_axi2tdm_clk : 1;
        unsigned int gt_dmac1hclk : 1;
    } reg;
} SOC_ASP_CFG_R_GATE_CLKEN_UNION;
#endif
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_hifidspclk_START (0)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_hifidspclk_END (0)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_dspjtagdebug_clk_START (1)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_dspjtagdebug_clk_END (1)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_codec_clk_START (3)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_codec_clk_END (3)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_hifidsp1clk_START (4)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_hifidsp1clk_END (4)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_pa_clk_out_START (6)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_pa_clk_out_END (6)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_ipchclk_START (9)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_ipchclk_END (9)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_hdmihclk_START (10)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_hdmihclk_END (10)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_dmachclk_START (11)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_dmachclk_END (11)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_asp_dmmu_clk_START (13)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_asp_dmmu_clk_END (13)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_ocramhclk_START (14)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_ocramhclk_END (14)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_uart_clk_START (17)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_uart_clk_END (17)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_asp_h2x_START (18)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_asp_h2x_END (18)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_spdifclk_START (19)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_spdifclk_END (19)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_hdmibclk_START (20)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_hdmibclk_END (20)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_gpiohclk_START (21)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_gpiohclk_END (21)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_timer0hclk_START (22)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_timer0hclk_END (22)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_timer1hclk_START (23)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_timer1hclk_END (23)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_ipc1hclk_START (24)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_ipc1hclk_END (24)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_audio_pll_START (25)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_audio_pll_END (25)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_spdifclk_o_START (26)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_spdifclk_o_END (26)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_hts_mst_clk_START (27)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_hts_mst_clk_END (27)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_hts_slv_clk_START (28)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_hts_slv_clk_END (28)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_audio_multi_acc_clk_START (29)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_audio_multi_acc_clk_END (29)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_axi2tdm_clk_START (30)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_axi2tdm_clk_END (30)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_dmac1hclk_START (31)
#define SOC_ASP_CFG_R_GATE_CLKEN_gt_dmac1hclk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_hifidspclk : 1;
        unsigned int st_dspjtagdebug_clk : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int st_hifidsp1clk : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int st_ipchclk : 1;
        unsigned int st_hdmihclk : 1;
        unsigned int st_dmachclk0 : 1;
        unsigned int st_dmachclk1 : 1;
        unsigned int st_asp_dmmu_clk : 1;
        unsigned int st_ipc1hclk : 1;
        unsigned int st_ocramhclk : 1;
        unsigned int st_wdhclk : 1;
        unsigned int st_uart_clk_m : 1;
        unsigned int st_uart_clk_s : 1;
        unsigned int st_spdifclk : 1;
        unsigned int st_spdifclk_o : 1;
        unsigned int st_hts_mst_clk : 1;
        unsigned int st_hts_slv_clk : 1;
        unsigned int st_audio_multi_acc_clk : 1;
        unsigned int reserved_6 : 1;
        unsigned int st_asp_h2x : 1;
        unsigned int st_pclk_codec : 1;
        unsigned int st_gpiohclk : 1;
        unsigned int st_timer0hclk : 1;
        unsigned int st_timer1hclk : 1;
        unsigned int st_hdmibclk : 1;
        unsigned int st_codec_clk : 1;
    } reg;
} SOC_ASP_CFG_R_GATE_CLKSTAT_UNION;
#endif
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_hifidspclk_START (0)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_hifidspclk_END (0)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_dspjtagdebug_clk_START (1)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_dspjtagdebug_clk_END (1)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_hifidsp1clk_START (4)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_hifidsp1clk_END (4)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_ipchclk_START (9)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_ipchclk_END (9)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_hdmihclk_START (10)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_hdmihclk_END (10)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_dmachclk0_START (11)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_dmachclk0_END (11)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_dmachclk1_START (12)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_dmachclk1_END (12)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_asp_dmmu_clk_START (13)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_asp_dmmu_clk_END (13)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_ipc1hclk_START (14)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_ipc1hclk_END (14)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_ocramhclk_START (15)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_ocramhclk_END (15)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_wdhclk_START (16)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_wdhclk_END (16)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_uart_clk_m_START (17)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_uart_clk_m_END (17)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_uart_clk_s_START (18)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_uart_clk_s_END (18)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_spdifclk_START (19)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_spdifclk_END (19)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_spdifclk_o_START (20)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_spdifclk_o_END (20)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_hts_mst_clk_START (21)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_hts_mst_clk_END (21)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_hts_slv_clk_START (22)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_hts_slv_clk_END (22)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_audio_multi_acc_clk_START (23)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_audio_multi_acc_clk_END (23)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_asp_h2x_START (25)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_asp_h2x_END (25)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_pclk_codec_START (26)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_pclk_codec_END (26)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_gpiohclk_START (27)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_gpiohclk_END (27)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_timer0hclk_START (28)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_timer0hclk_END (28)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_timer1hclk_START (29)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_timer1hclk_END (29)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_hdmibclk_START (30)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_hdmibclk_END (30)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_codec_clk_START (31)
#define SOC_ASP_CFG_R_GATE_CLKSTAT_st_codec_clk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_hdmimclk_div : 1;
        unsigned int gt_hdmimclk_in : 1;
        unsigned int gt_siobclk_div : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int gt_asp_tcxo_div : 1;
        unsigned int gt_uart_clk_div : 1;
        unsigned int gt_hdmiadws_div : 1;
        unsigned int gt_spdifclk_div : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 20;
    } reg;
} SOC_ASP_CFG_R_GATE_CLKDIV_EN_UNION;
#endif
#define SOC_ASP_CFG_R_GATE_CLKDIV_EN_gt_hdmimclk_div_START (0)
#define SOC_ASP_CFG_R_GATE_CLKDIV_EN_gt_hdmimclk_div_END (0)
#define SOC_ASP_CFG_R_GATE_CLKDIV_EN_gt_hdmimclk_in_START (1)
#define SOC_ASP_CFG_R_GATE_CLKDIV_EN_gt_hdmimclk_in_END (1)
#define SOC_ASP_CFG_R_GATE_CLKDIV_EN_gt_siobclk_div_START (2)
#define SOC_ASP_CFG_R_GATE_CLKDIV_EN_gt_siobclk_div_END (2)
#define SOC_ASP_CFG_R_GATE_CLKDIV_EN_gt_asp_tcxo_div_START (7)
#define SOC_ASP_CFG_R_GATE_CLKDIV_EN_gt_asp_tcxo_div_END (7)
#define SOC_ASP_CFG_R_GATE_CLKDIV_EN_gt_uart_clk_div_START (8)
#define SOC_ASP_CFG_R_GATE_CLKDIV_EN_gt_uart_clk_div_END (8)
#define SOC_ASP_CFG_R_GATE_CLKDIV_EN_gt_hdmiadws_div_START (9)
#define SOC_ASP_CFG_R_GATE_CLKDIV_EN_gt_hdmiadws_div_END (9)
#define SOC_ASP_CFG_R_GATE_CLKDIV_EN_gt_spdifclk_div_START (10)
#define SOC_ASP_CFG_R_GATE_CLKDIV_EN_gt_spdifclk_div_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_siobclk : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_ASP_CFG_R_CLK1_DIV_UNION;
#endif
#define SOC_ASP_CFG_R_CLK1_DIV_div_siobclk_START (0)
#define SOC_ASP_CFG_R_CLK1_DIV_div_siobclk_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_hdmimclk : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_ASP_CFG_R_CLK2_DIV_UNION;
#endif
#define SOC_ASP_CFG_R_CLK2_DIV_div_hdmimclk_START (0)
#define SOC_ASP_CFG_R_CLK2_DIV_div_hdmimclk_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_uartclk : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_ASP_CFG_R_CLK3_DIV_UNION;
#endif
#define SOC_ASP_CFG_R_CLK3_DIV_div_uartclk_START (0)
#define SOC_ASP_CFG_R_CLK3_DIV_div_uartclk_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_pa_clk_out : 6;
        unsigned int reserved : 10;
        unsigned int write_en_h2c : 16;
    } reg;
} SOC_ASP_CFG_R_CLK4_DIV_UNION;
#endif
#define SOC_ASP_CFG_R_CLK4_DIV_div_pa_clk_out_START (0)
#define SOC_ASP_CFG_R_CLK4_DIV_div_pa_clk_out_END (5)
#define SOC_ASP_CFG_R_CLK4_DIV_write_en_h2c_START (16)
#define SOC_ASP_CFG_R_CLK4_DIV_write_en_h2c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int asp_dma0_sel : 32;
    } reg;
} SOC_ASP_CFG_R_DMA0_REQ_SEL_UNION;
#endif
#define SOC_ASP_CFG_R_DMA0_REQ_SEL_asp_dma0_sel_START (0)
#define SOC_ASP_CFG_R_DMA0_REQ_SEL_asp_dma0_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int asp_dma1_sel : 32;
    } reg;
} SOC_ASP_CFG_R_DMA1_REQ_SEL_UNION;
#endif
#define SOC_ASP_CFG_R_DMA1_REQ_SEL_asp_dma1_sel_START (0)
#define SOC_ASP_CFG_R_DMA1_REQ_SEL_asp_dma1_sel_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 2;
        unsigned int soundwire_base_clk_sel : 1;
        unsigned int watchdog_debug_en : 1;
        unsigned int timer0_debug_en : 2;
        unsigned int timer1_debug_en : 2;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int hifidsp_clk_sel : 1;
        unsigned int hifidsp1_clk_sel : 1;
        unsigned int write_en_h38 : 16;
    } reg;
} SOC_ASP_CFG_R_CLK_SEL_UNION;
#endif
#define SOC_ASP_CFG_R_CLK_SEL_soundwire_base_clk_sel_START (6)
#define SOC_ASP_CFG_R_CLK_SEL_soundwire_base_clk_sel_END (6)
#define SOC_ASP_CFG_R_CLK_SEL_watchdog_debug_en_START (7)
#define SOC_ASP_CFG_R_CLK_SEL_watchdog_debug_en_END (7)
#define SOC_ASP_CFG_R_CLK_SEL_timer0_debug_en_START (8)
#define SOC_ASP_CFG_R_CLK_SEL_timer0_debug_en_END (9)
#define SOC_ASP_CFG_R_CLK_SEL_timer1_debug_en_START (10)
#define SOC_ASP_CFG_R_CLK_SEL_timer1_debug_en_END (11)
#define SOC_ASP_CFG_R_CLK_SEL_hifidsp_clk_sel_START (14)
#define SOC_ASP_CFG_R_CLK_SEL_hifidsp_clk_sel_END (14)
#define SOC_ASP_CFG_R_CLK_SEL_hifidsp1_clk_sel_START (15)
#define SOC_ASP_CFG_R_CLK_SEL_hifidsp1_clk_sel_END (15)
#define SOC_ASP_CFG_R_CLK_SEL_write_en_h38_START (16)
#define SOC_ASP_CFG_R_CLK_SEL_write_en_h38_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int r_dsp_nmi : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ASP_CFG_R_DSP_NMI_UNION;
#endif
#define SOC_ASP_CFG_R_DSP_NMI_r_dsp_nmi_START (0)
#define SOC_ASP_CFG_R_DSP_NMI_r_dsp_nmi_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 2;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int dma_0_1_sel : 1;
        unsigned int dsp0_dsp1_jtag_sel : 2;
        unsigned int pa_clk_out_oen : 1;
        unsigned int reserved_7 : 4;
        unsigned int write_en_h54 : 16;
    } reg;
} SOC_ASP_CFG_R_DMA_SEL_UNION;
#endif
#define SOC_ASP_CFG_R_DMA_SEL_dma_0_1_sel_START (8)
#define SOC_ASP_CFG_R_DMA_SEL_dma_0_1_sel_END (8)
#define SOC_ASP_CFG_R_DMA_SEL_dsp0_dsp1_jtag_sel_START (9)
#define SOC_ASP_CFG_R_DMA_SEL_dsp0_dsp1_jtag_sel_END (10)
#define SOC_ASP_CFG_R_DMA_SEL_pa_clk_out_oen_START (11)
#define SOC_ASP_CFG_R_DMA_SEL_pa_clk_out_oen_END (11)
#define SOC_ASP_CFG_R_DMA_SEL_write_en_h54_START (16)
#define SOC_ASP_CFG_R_DMA_SEL_write_en_h54_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp_ar_qos : 4;
        unsigned int dsp_aw_qos : 4;
        unsigned int edmac_ar_qos : 4;
        unsigned int edmac_aw_qos : 4;
        unsigned int hdmi_ar_qos : 4;
        unsigned int hdmi_aw_qos : 4;
        unsigned int reserved : 8;
    } reg;
} SOC_ASP_CFG_R_BUS_PRIORITY_UNION;
#endif
#define SOC_ASP_CFG_R_BUS_PRIORITY_dsp_ar_qos_START (0)
#define SOC_ASP_CFG_R_BUS_PRIORITY_dsp_ar_qos_END (3)
#define SOC_ASP_CFG_R_BUS_PRIORITY_dsp_aw_qos_START (4)
#define SOC_ASP_CFG_R_BUS_PRIORITY_dsp_aw_qos_END (7)
#define SOC_ASP_CFG_R_BUS_PRIORITY_edmac_ar_qos_START (8)
#define SOC_ASP_CFG_R_BUS_PRIORITY_edmac_ar_qos_END (11)
#define SOC_ASP_CFG_R_BUS_PRIORITY_edmac_aw_qos_START (12)
#define SOC_ASP_CFG_R_BUS_PRIORITY_edmac_aw_qos_END (15)
#define SOC_ASP_CFG_R_BUS_PRIORITY_hdmi_ar_qos_START (16)
#define SOC_ASP_CFG_R_BUS_PRIORITY_hdmi_ar_qos_END (19)
#define SOC_ASP_CFG_R_BUS_PRIORITY_hdmi_aw_qos_START (20)
#define SOC_ASP_CFG_R_BUS_PRIORITY_hdmi_aw_qos_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int stat_monitor_sel : 2;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int dmac1_hclk1_cg_en : 1;
        unsigned int dmac1_hclk0_cg_en : 1;
        unsigned int soundiwre_h2h_cg_en : 1;
        unsigned int ocram_x2ram_cg_en : 1;
        unsigned int dmac_hclk0_cg_en : 1;
        unsigned int dmac_hclk1_cg_en : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int write_en_h5c : 16;
    } reg;
} SOC_ASP_CFG_R_CG_EN_UNION;
#endif
#define SOC_ASP_CFG_R_CG_EN_stat_monitor_sel_START (2)
#define SOC_ASP_CFG_R_CG_EN_stat_monitor_sel_END (3)
#define SOC_ASP_CFG_R_CG_EN_dmac1_hclk1_cg_en_START (6)
#define SOC_ASP_CFG_R_CG_EN_dmac1_hclk1_cg_en_END (6)
#define SOC_ASP_CFG_R_CG_EN_dmac1_hclk0_cg_en_START (7)
#define SOC_ASP_CFG_R_CG_EN_dmac1_hclk0_cg_en_END (7)
#define SOC_ASP_CFG_R_CG_EN_soundiwre_h2h_cg_en_START (8)
#define SOC_ASP_CFG_R_CG_EN_soundiwre_h2h_cg_en_END (8)
#define SOC_ASP_CFG_R_CG_EN_ocram_x2ram_cg_en_START (9)
#define SOC_ASP_CFG_R_CG_EN_ocram_x2ram_cg_en_END (9)
#define SOC_ASP_CFG_R_CG_EN_dmac_hclk0_cg_en_START (10)
#define SOC_ASP_CFG_R_CG_EN_dmac_hclk0_cg_en_END (10)
#define SOC_ASP_CFG_R_CG_EN_dmac_hclk1_cg_en_START (11)
#define SOC_ASP_CFG_R_CG_EN_dmac_hclk1_cg_en_END (11)
#define SOC_ASP_CFG_R_CG_EN_write_en_h5c_START (16)
#define SOC_ASP_CFG_R_CG_EN_write_en_h5c_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ocram_ret1n : 4;
        unsigned int reserved : 12;
        unsigned int write_en_h60 : 16;
    } reg;
} SOC_ASP_CFG_R_OCRAM_RET_UNION;
#endif
#define SOC_ASP_CFG_R_OCRAM_RET_ocram_ret1n_START (0)
#define SOC_ASP_CFG_R_OCRAM_RET_ocram_ret1n_END (3)
#define SOC_ASP_CFG_R_OCRAM_RET_write_en_h60_START (16)
#define SOC_ASP_CFG_R_OCRAM_RET_write_en_h60_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int asp_hdmi_int : 1;
        unsigned int intr0_modem_ipc2hifi_ns : 1;
        unsigned int intr1_modem_ipc2hifi_ns : 1;
        unsigned int intr_ipc_ns_isp2asp : 1;
        unsigned int intr_soc_peri_eicc_0_hifi : 1;
        unsigned int l2drx2hifi_time_int_ns : 1;
        unsigned int audio_multi_acc_int : 1;
        unsigned int usb31_ctrl_intr_ns : 1;
        unsigned int swire_int_ns : 1;
        unsigned int intr_ipc_davinci_ns : 3;
        unsigned int reserved_0 : 1;
        unsigned int i2c_hifi_intr : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int addr_mon_intr : 1;
        unsigned int dma_ns_intr1 : 1;
        unsigned int asp_hdmi_hifi_intr : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int intr1_nosec_ipc_rtos : 1;
        unsigned int intr0_nosec_ipc_rtos : 1;
        unsigned int intr1_nosec_ipc : 1;
        unsigned int intr0_nosec_ipc : 1;
        unsigned int intr_dsp_nmi : 1;
        unsigned int i2c9_hifi_intr : 1;
        unsigned int asp_uart_intr : 1;
        unsigned int arpp2hifi_intr_ns : 1;
        unsigned int display_sh_vsync_irq : 1;
    } reg;
} SOC_ASP_CFG_R_INTR_NS_INI_UNION;
#endif
#define SOC_ASP_CFG_R_INTR_NS_INI_asp_hdmi_int_START (0)
#define SOC_ASP_CFG_R_INTR_NS_INI_asp_hdmi_int_END (0)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr0_modem_ipc2hifi_ns_START (1)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr0_modem_ipc2hifi_ns_END (1)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr1_modem_ipc2hifi_ns_START (2)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr1_modem_ipc2hifi_ns_END (2)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr_ipc_ns_isp2asp_START (3)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr_ipc_ns_isp2asp_END (3)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr_soc_peri_eicc_0_hifi_START (4)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr_soc_peri_eicc_0_hifi_END (4)
#define SOC_ASP_CFG_R_INTR_NS_INI_l2drx2hifi_time_int_ns_START (5)
#define SOC_ASP_CFG_R_INTR_NS_INI_l2drx2hifi_time_int_ns_END (5)
#define SOC_ASP_CFG_R_INTR_NS_INI_audio_multi_acc_int_START (6)
#define SOC_ASP_CFG_R_INTR_NS_INI_audio_multi_acc_int_END (6)
#define SOC_ASP_CFG_R_INTR_NS_INI_usb31_ctrl_intr_ns_START (7)
#define SOC_ASP_CFG_R_INTR_NS_INI_usb31_ctrl_intr_ns_END (7)
#define SOC_ASP_CFG_R_INTR_NS_INI_swire_int_ns_START (8)
#define SOC_ASP_CFG_R_INTR_NS_INI_swire_int_ns_END (8)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr_ipc_davinci_ns_START (9)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr_ipc_davinci_ns_END (11)
#define SOC_ASP_CFG_R_INTR_NS_INI_i2c_hifi_intr_START (13)
#define SOC_ASP_CFG_R_INTR_NS_INI_i2c_hifi_intr_END (13)
#define SOC_ASP_CFG_R_INTR_NS_INI_addr_mon_intr_START (16)
#define SOC_ASP_CFG_R_INTR_NS_INI_addr_mon_intr_END (16)
#define SOC_ASP_CFG_R_INTR_NS_INI_dma_ns_intr1_START (17)
#define SOC_ASP_CFG_R_INTR_NS_INI_dma_ns_intr1_END (17)
#define SOC_ASP_CFG_R_INTR_NS_INI_asp_hdmi_hifi_intr_START (18)
#define SOC_ASP_CFG_R_INTR_NS_INI_asp_hdmi_hifi_intr_END (18)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr1_nosec_ipc_rtos_START (23)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr1_nosec_ipc_rtos_END (23)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr0_nosec_ipc_rtos_START (24)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr0_nosec_ipc_rtos_END (24)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr1_nosec_ipc_START (25)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr1_nosec_ipc_END (25)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr0_nosec_ipc_START (26)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr0_nosec_ipc_END (26)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr_dsp_nmi_START (27)
#define SOC_ASP_CFG_R_INTR_NS_INI_intr_dsp_nmi_END (27)
#define SOC_ASP_CFG_R_INTR_NS_INI_i2c9_hifi_intr_START (28)
#define SOC_ASP_CFG_R_INTR_NS_INI_i2c9_hifi_intr_END (28)
#define SOC_ASP_CFG_R_INTR_NS_INI_asp_uart_intr_START (29)
#define SOC_ASP_CFG_R_INTR_NS_INI_asp_uart_intr_END (29)
#define SOC_ASP_CFG_R_INTR_NS_INI_arpp2hifi_intr_ns_START (30)
#define SOC_ASP_CFG_R_INTR_NS_INI_arpp2hifi_intr_ns_END (30)
#define SOC_ASP_CFG_R_INTR_NS_INI_display_sh_vsync_irq_START (31)
#define SOC_ASP_CFG_R_INTR_NS_INI_display_sh_vsync_irq_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int asp_hdmi_intr_mask : 1;
        unsigned int intr0_modem_ipc2hifi_ns_mask : 1;
        unsigned int intr1_modem_ipc2hifi_ns_mask : 1;
        unsigned int intr_ipc_ns_isp2asp_mask : 1;
        unsigned int intr_soc_peri_eicc_0_en_mask : 1;
        unsigned int l2drx2hifi_time_int_ns_mask : 1;
        unsigned int audio_multi_acc_int_mask : 1;
        unsigned int usb31_ctrl_intr_ns_mask : 1;
        unsigned int swire_int_ns_mask : 1;
        unsigned int intr_ipc_davinci_ns_mask : 3;
        unsigned int reserved_0 : 1;
        unsigned int i2c_hifi_intr_mask : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int addr_mon_intr_mask : 1;
        unsigned int dma_ns_intr1_mask : 1;
        unsigned int asp_hdmi_hifi_intr_mask : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int intr1_nosec_ipc_rtos_mask : 1;
        unsigned int intr0_nosec_ipc_rtos_mask : 1;
        unsigned int intr1_nosec_ipc_mask : 1;
        unsigned int intr0_nosec_ipc_mask : 1;
        unsigned int intr_dsp_nmi_mask : 1;
        unsigned int i2c9_hifi_intr_mask : 1;
        unsigned int asp_uart_intr_mask : 1;
        unsigned int arpp2hifi_intr_ns_mask : 1;
        unsigned int display_sh_vsync_irq_mask : 1;
    } reg;
} SOC_ASP_CFG_R_INTR_NS_EN_UNION;
#endif
#define SOC_ASP_CFG_R_INTR_NS_EN_asp_hdmi_intr_mask_START (0)
#define SOC_ASP_CFG_R_INTR_NS_EN_asp_hdmi_intr_mask_END (0)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr0_modem_ipc2hifi_ns_mask_START (1)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr0_modem_ipc2hifi_ns_mask_END (1)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr1_modem_ipc2hifi_ns_mask_START (2)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr1_modem_ipc2hifi_ns_mask_END (2)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr_ipc_ns_isp2asp_mask_START (3)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr_ipc_ns_isp2asp_mask_END (3)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr_soc_peri_eicc_0_en_mask_START (4)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr_soc_peri_eicc_0_en_mask_END (4)
#define SOC_ASP_CFG_R_INTR_NS_EN_l2drx2hifi_time_int_ns_mask_START (5)
#define SOC_ASP_CFG_R_INTR_NS_EN_l2drx2hifi_time_int_ns_mask_END (5)
#define SOC_ASP_CFG_R_INTR_NS_EN_audio_multi_acc_int_mask_START (6)
#define SOC_ASP_CFG_R_INTR_NS_EN_audio_multi_acc_int_mask_END (6)
#define SOC_ASP_CFG_R_INTR_NS_EN_usb31_ctrl_intr_ns_mask_START (7)
#define SOC_ASP_CFG_R_INTR_NS_EN_usb31_ctrl_intr_ns_mask_END (7)
#define SOC_ASP_CFG_R_INTR_NS_EN_swire_int_ns_mask_START (8)
#define SOC_ASP_CFG_R_INTR_NS_EN_swire_int_ns_mask_END (8)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr_ipc_davinci_ns_mask_START (9)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr_ipc_davinci_ns_mask_END (11)
#define SOC_ASP_CFG_R_INTR_NS_EN_i2c_hifi_intr_mask_START (13)
#define SOC_ASP_CFG_R_INTR_NS_EN_i2c_hifi_intr_mask_END (13)
#define SOC_ASP_CFG_R_INTR_NS_EN_addr_mon_intr_mask_START (16)
#define SOC_ASP_CFG_R_INTR_NS_EN_addr_mon_intr_mask_END (16)
#define SOC_ASP_CFG_R_INTR_NS_EN_dma_ns_intr1_mask_START (17)
#define SOC_ASP_CFG_R_INTR_NS_EN_dma_ns_intr1_mask_END (17)
#define SOC_ASP_CFG_R_INTR_NS_EN_asp_hdmi_hifi_intr_mask_START (18)
#define SOC_ASP_CFG_R_INTR_NS_EN_asp_hdmi_hifi_intr_mask_END (18)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr1_nosec_ipc_rtos_mask_START (23)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr1_nosec_ipc_rtos_mask_END (23)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr0_nosec_ipc_rtos_mask_START (24)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr0_nosec_ipc_rtos_mask_END (24)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr1_nosec_ipc_mask_START (25)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr1_nosec_ipc_mask_END (25)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr0_nosec_ipc_mask_START (26)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr0_nosec_ipc_mask_END (26)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr_dsp_nmi_mask_START (27)
#define SOC_ASP_CFG_R_INTR_NS_EN_intr_dsp_nmi_mask_END (27)
#define SOC_ASP_CFG_R_INTR_NS_EN_i2c9_hifi_intr_mask_START (28)
#define SOC_ASP_CFG_R_INTR_NS_EN_i2c9_hifi_intr_mask_END (28)
#define SOC_ASP_CFG_R_INTR_NS_EN_asp_uart_intr_mask_START (29)
#define SOC_ASP_CFG_R_INTR_NS_EN_asp_uart_intr_mask_END (29)
#define SOC_ASP_CFG_R_INTR_NS_EN_arpp2hifi_intr_ns_mask_START (30)
#define SOC_ASP_CFG_R_INTR_NS_EN_arpp2hifi_intr_ns_mask_END (30)
#define SOC_ASP_CFG_R_INTR_NS_EN_display_sh_vsync_irq_mask_START (31)
#define SOC_ASP_CFG_R_INTR_NS_EN_display_sh_vsync_irq_mask_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int asp_hdmi_int_mstat : 1;
        unsigned int ipcm2hifi_intr0_ns_mstat : 1;
        unsigned int ipcm2hifi_intr1_ns_mstat : 1;
        unsigned int intr_ipc_ns_isp2asp_mstat : 1;
        unsigned int intr_soc_peri_eicc_0_hifi_mstat : 1;
        unsigned int l2drx2hifi_time_int_ns_mstat : 1;
        unsigned int audio_multi_acc_int_mstat : 1;
        unsigned int usb31_ctrl_intr_ns_mstat : 1;
        unsigned int swire_int_ns_mstat : 1;
        unsigned int intr_ipc_davinci_ns_mstat : 3;
        unsigned int reserved_0 : 1;
        unsigned int i2c_hifi_intr_mstat : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int addr_mon_intr_mstat : 1;
        unsigned int dma_ns_intr1_mstat : 1;
        unsigned int asp_hdmi_hifi_intr_mstat : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int intr1_nosec_ipc_rtos_mstat : 1;
        unsigned int intr0_nosec_ipc_rtos_mstat : 1;
        unsigned int intr1_nosec_ipc_mstat : 1;
        unsigned int intr0_nosec_ipc_mstat : 1;
        unsigned int intr_dsp_nmi_mstat : 1;
        unsigned int i2c9_hifi_intr_mstat : 1;
        unsigned int asp_uart_intr_mstat : 1;
        unsigned int arpp2hifi_intr_ns_mstat : 1;
        unsigned int display_sh_vsync_irq_mstat : 1;
    } reg;
} SOC_ASP_CFG_R_INTR_NS_MASK_UNION;
#endif
#define SOC_ASP_CFG_R_INTR_NS_MASK_asp_hdmi_int_mstat_START (0)
#define SOC_ASP_CFG_R_INTR_NS_MASK_asp_hdmi_int_mstat_END (0)
#define SOC_ASP_CFG_R_INTR_NS_MASK_ipcm2hifi_intr0_ns_mstat_START (1)
#define SOC_ASP_CFG_R_INTR_NS_MASK_ipcm2hifi_intr0_ns_mstat_END (1)
#define SOC_ASP_CFG_R_INTR_NS_MASK_ipcm2hifi_intr1_ns_mstat_START (2)
#define SOC_ASP_CFG_R_INTR_NS_MASK_ipcm2hifi_intr1_ns_mstat_END (2)
#define SOC_ASP_CFG_R_INTR_NS_MASK_intr_ipc_ns_isp2asp_mstat_START (3)
#define SOC_ASP_CFG_R_INTR_NS_MASK_intr_ipc_ns_isp2asp_mstat_END (3)
#define SOC_ASP_CFG_R_INTR_NS_MASK_intr_soc_peri_eicc_0_hifi_mstat_START (4)
#define SOC_ASP_CFG_R_INTR_NS_MASK_intr_soc_peri_eicc_0_hifi_mstat_END (4)
#define SOC_ASP_CFG_R_INTR_NS_MASK_l2drx2hifi_time_int_ns_mstat_START (5)
#define SOC_ASP_CFG_R_INTR_NS_MASK_l2drx2hifi_time_int_ns_mstat_END (5)
#define SOC_ASP_CFG_R_INTR_NS_MASK_audio_multi_acc_int_mstat_START (6)
#define SOC_ASP_CFG_R_INTR_NS_MASK_audio_multi_acc_int_mstat_END (6)
#define SOC_ASP_CFG_R_INTR_NS_MASK_usb31_ctrl_intr_ns_mstat_START (7)
#define SOC_ASP_CFG_R_INTR_NS_MASK_usb31_ctrl_intr_ns_mstat_END (7)
#define SOC_ASP_CFG_R_INTR_NS_MASK_swire_int_ns_mstat_START (8)
#define SOC_ASP_CFG_R_INTR_NS_MASK_swire_int_ns_mstat_END (8)
#define SOC_ASP_CFG_R_INTR_NS_MASK_intr_ipc_davinci_ns_mstat_START (9)
#define SOC_ASP_CFG_R_INTR_NS_MASK_intr_ipc_davinci_ns_mstat_END (11)
#define SOC_ASP_CFG_R_INTR_NS_MASK_i2c_hifi_intr_mstat_START (13)
#define SOC_ASP_CFG_R_INTR_NS_MASK_i2c_hifi_intr_mstat_END (13)
#define SOC_ASP_CFG_R_INTR_NS_MASK_addr_mon_intr_mstat_START (16)
#define SOC_ASP_CFG_R_INTR_NS_MASK_addr_mon_intr_mstat_END (16)
#define SOC_ASP_CFG_R_INTR_NS_MASK_dma_ns_intr1_mstat_START (17)
#define SOC_ASP_CFG_R_INTR_NS_MASK_dma_ns_intr1_mstat_END (17)
#define SOC_ASP_CFG_R_INTR_NS_MASK_asp_hdmi_hifi_intr_mstat_START (18)
#define SOC_ASP_CFG_R_INTR_NS_MASK_asp_hdmi_hifi_intr_mstat_END (18)
#define SOC_ASP_CFG_R_INTR_NS_MASK_intr1_nosec_ipc_rtos_mstat_START (23)
#define SOC_ASP_CFG_R_INTR_NS_MASK_intr1_nosec_ipc_rtos_mstat_END (23)
#define SOC_ASP_CFG_R_INTR_NS_MASK_intr0_nosec_ipc_rtos_mstat_START (24)
#define SOC_ASP_CFG_R_INTR_NS_MASK_intr0_nosec_ipc_rtos_mstat_END (24)
#define SOC_ASP_CFG_R_INTR_NS_MASK_intr1_nosec_ipc_mstat_START (25)
#define SOC_ASP_CFG_R_INTR_NS_MASK_intr1_nosec_ipc_mstat_END (25)
#define SOC_ASP_CFG_R_INTR_NS_MASK_intr0_nosec_ipc_mstat_START (26)
#define SOC_ASP_CFG_R_INTR_NS_MASK_intr0_nosec_ipc_mstat_END (26)
#define SOC_ASP_CFG_R_INTR_NS_MASK_intr_dsp_nmi_mstat_START (27)
#define SOC_ASP_CFG_R_INTR_NS_MASK_intr_dsp_nmi_mstat_END (27)
#define SOC_ASP_CFG_R_INTR_NS_MASK_i2c9_hifi_intr_mstat_START (28)
#define SOC_ASP_CFG_R_INTR_NS_MASK_i2c9_hifi_intr_mstat_END (28)
#define SOC_ASP_CFG_R_INTR_NS_MASK_asp_uart_intr_mstat_START (29)
#define SOC_ASP_CFG_R_INTR_NS_MASK_asp_uart_intr_mstat_END (29)
#define SOC_ASP_CFG_R_INTR_NS_MASK_arpp2hifi_intr_ns_mstat_START (30)
#define SOC_ASP_CFG_R_INTR_NS_MASK_arpp2hifi_intr_ns_mstat_END (30)
#define SOC_ASP_CFG_R_INTR_NS_MASK_display_sh_vsync_irq_mstat_START (31)
#define SOC_ASP_CFG_R_INTR_NS_MASK_display_sh_vsync_irq_mstat_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dbg_wfq_weight_port2 : 4;
        unsigned int dbg_wfq_weight_port1 : 4;
        unsigned int dbg_wfq_weight_port0 : 4;
        unsigned int dbg_rd_outstd : 4;
        unsigned int dbg_wr_outstd : 4;
        unsigned int dbg_port_sel : 4;
        unsigned int dbg_incr_spen : 1;
        unsigned int dbg_h2x_sel : 1;
        unsigned int dbg_stat_clr : 1;
        unsigned int reserved : 5;
    } reg;
} SOC_ASP_CFG_R_DBG_SET_AHB2AXI_UNION;
#endif
#define SOC_ASP_CFG_R_DBG_SET_AHB2AXI_dbg_wfq_weight_port2_START (0)
#define SOC_ASP_CFG_R_DBG_SET_AHB2AXI_dbg_wfq_weight_port2_END (3)
#define SOC_ASP_CFG_R_DBG_SET_AHB2AXI_dbg_wfq_weight_port1_START (4)
#define SOC_ASP_CFG_R_DBG_SET_AHB2AXI_dbg_wfq_weight_port1_END (7)
#define SOC_ASP_CFG_R_DBG_SET_AHB2AXI_dbg_wfq_weight_port0_START (8)
#define SOC_ASP_CFG_R_DBG_SET_AHB2AXI_dbg_wfq_weight_port0_END (11)
#define SOC_ASP_CFG_R_DBG_SET_AHB2AXI_dbg_rd_outstd_START (12)
#define SOC_ASP_CFG_R_DBG_SET_AHB2AXI_dbg_rd_outstd_END (15)
#define SOC_ASP_CFG_R_DBG_SET_AHB2AXI_dbg_wr_outstd_START (16)
#define SOC_ASP_CFG_R_DBG_SET_AHB2AXI_dbg_wr_outstd_END (19)
#define SOC_ASP_CFG_R_DBG_SET_AHB2AXI_dbg_port_sel_START (20)
#define SOC_ASP_CFG_R_DBG_SET_AHB2AXI_dbg_port_sel_END (23)
#define SOC_ASP_CFG_R_DBG_SET_AHB2AXI_dbg_incr_spen_START (24)
#define SOC_ASP_CFG_R_DBG_SET_AHB2AXI_dbg_incr_spen_END (24)
#define SOC_ASP_CFG_R_DBG_SET_AHB2AXI_dbg_h2x_sel_START (25)
#define SOC_ASP_CFG_R_DBG_SET_AHB2AXI_dbg_h2x_sel_END (25)
#define SOC_ASP_CFG_R_DBG_SET_AHB2AXI_dbg_stat_clr_START (26)
#define SOC_ASP_CFG_R_DBG_SET_AHB2AXI_dbg_stat_clr_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int rlast_bresp_err : 1;
        unsigned int rdata_err : 1;
        unsigned int rdcmd_gnt : 1;
        unsigned int rdcmd_rearb : 1;
        unsigned int wrcmd_nt : 1;
        unsigned int wrcmd_rearb : 1;
        unsigned int cmd_arrdy : 1;
        unsigned int cmd_awrdy : 1;
        unsigned int rdfifo_full : 1;
        unsigned int rdfifo_empty : 1;
        unsigned int wrfifo_alfull : 1;
        unsigned int wrfifo_empty : 1;
        unsigned int rdfifo_rerr : 1;
        unsigned int rdfifo_werr : 1;
        unsigned int wrfifo_rerr : 1;
        unsigned int wrfifo_werr : 1;
        unsigned int rdcmd_cnt : 4;
        unsigned int rddata_cnt : 4;
        unsigned int wrcmd_cnt : 4;
        unsigned int wrdata_cnt : 4;
    } reg;
} SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_UNION;
#endif
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_rlast_bresp_err_START (0)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_rlast_bresp_err_END (0)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_rdata_err_START (1)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_rdata_err_END (1)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_rdcmd_gnt_START (2)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_rdcmd_gnt_END (2)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_rdcmd_rearb_START (3)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_rdcmd_rearb_END (3)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_wrcmd_nt_START (4)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_wrcmd_nt_END (4)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_wrcmd_rearb_START (5)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_wrcmd_rearb_END (5)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_cmd_arrdy_START (6)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_cmd_arrdy_END (6)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_cmd_awrdy_START (7)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_cmd_awrdy_END (7)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_rdfifo_full_START (8)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_rdfifo_full_END (8)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_rdfifo_empty_START (9)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_rdfifo_empty_END (9)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_wrfifo_alfull_START (10)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_wrfifo_alfull_END (10)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_wrfifo_empty_START (11)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_wrfifo_empty_END (11)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_rdfifo_rerr_START (12)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_rdfifo_rerr_END (12)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_rdfifo_werr_START (13)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_rdfifo_werr_END (13)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_wrfifo_rerr_START (14)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_wrfifo_rerr_END (14)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_wrfifo_werr_START (15)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_wrfifo_werr_END (15)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_rdcmd_cnt_START (16)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_rdcmd_cnt_END (19)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_rddata_cnt_START (20)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_rddata_cnt_END (23)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_wrcmd_cnt_START (24)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_wrcmd_cnt_END (27)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_wrdata_cnt_START (28)
#define SOC_ASP_CFG_R_DBG_STATUS_AHB2AXI_wrdata_cnt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dlock_bp_codec : 1;
        unsigned int reserved : 1;
        unsigned int dlock_bp_h2p : 1;
        unsigned int dlock_bp_asphdmi : 1;
        unsigned int dlock_bp_audio_multi_acc : 1;
        unsigned int dlock_bp_soundwire : 1;
        unsigned int dlock_bp_hts_slv : 1;
        unsigned int dlock_bp_hts_mst : 1;
        unsigned int dlock_bp_uart : 1;
        unsigned int dlock_bp_edmac : 1;
        unsigned int dlock_bp_ipc : 1;
        unsigned int dlock_bp_watchdog : 1;
        unsigned int dlock_bp_cfg : 1;
        unsigned int dlock_bp_gpio : 1;
        unsigned int dlock_bp_timer0 : 1;
        unsigned int dlock_bp_timer1 : 1;
        unsigned int write_en_h78 : 16;
    } reg;
} SOC_ASP_CFG_R_DLOCK_BP_UNION;
#endif
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_codec_START (0)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_codec_END (0)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_h2p_START (2)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_h2p_END (2)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_asphdmi_START (3)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_asphdmi_END (3)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_audio_multi_acc_START (4)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_audio_multi_acc_END (4)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_soundwire_START (5)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_soundwire_END (5)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_hts_slv_START (6)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_hts_slv_END (6)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_hts_mst_START (7)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_hts_mst_END (7)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_uart_START (8)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_uart_END (8)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_edmac_START (9)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_edmac_END (9)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_ipc_START (10)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_ipc_END (10)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_watchdog_START (11)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_watchdog_END (11)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_cfg_START (12)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_cfg_END (12)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_gpio_START (13)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_gpio_END (13)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_timer0_START (14)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_timer0_END (14)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_timer1_START (15)
#define SOC_ASP_CFG_R_DLOCK_BP_dlock_bp_timer1_END (15)
#define SOC_ASP_CFG_R_DLOCK_BP_write_en_h78_START (16)
#define SOC_ASP_CFG_R_DLOCK_BP_write_en_h78_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp_BInterrupt : 32;
    } reg;
} SOC_ASP_CFG_R_DSP_BINTERRUPT_UNION;
#endif
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_dsp_BInterrupt_START (0)
#define SOC_ASP_CFG_R_DSP_BINTERRUPT_dsp_BInterrupt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dram_pgt_ctrl_0 : 1;
        unsigned int iram_pgt_ctrl_0 : 1;
        unsigned int cache_pgt_ctrl_1_0 : 2;
        unsigned int noise_meter_pgt_ctrl_0 : 1;
        unsigned int reserved : 11;
        unsigned int write_en_h84 : 16;
    } reg;
} SOC_ASP_CFG_R_DSP_RAM_RET_UNION;
#endif
#define SOC_ASP_CFG_R_DSP_RAM_RET_dram_pgt_ctrl_0_START (0)
#define SOC_ASP_CFG_R_DSP_RAM_RET_dram_pgt_ctrl_0_END (0)
#define SOC_ASP_CFG_R_DSP_RAM_RET_iram_pgt_ctrl_0_START (1)
#define SOC_ASP_CFG_R_DSP_RAM_RET_iram_pgt_ctrl_0_END (1)
#define SOC_ASP_CFG_R_DSP_RAM_RET_cache_pgt_ctrl_1_0_START (2)
#define SOC_ASP_CFG_R_DSP_RAM_RET_cache_pgt_ctrl_1_0_END (3)
#define SOC_ASP_CFG_R_DSP_RAM_RET_noise_meter_pgt_ctrl_0_START (4)
#define SOC_ASP_CFG_R_DSP_RAM_RET_noise_meter_pgt_ctrl_0_END (4)
#define SOC_ASP_CFG_R_DSP_RAM_RET_write_en_h84_START (16)
#define SOC_ASP_CFG_R_DSP_RAM_RET_write_en_h84_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hifidsp_flag0 : 32;
    } reg;
} SOC_ASP_CFG_R_HIFIDSP_FLAG0_UNION;
#endif
#define SOC_ASP_CFG_R_HIFIDSP_FLAG0_hifidsp_flag0_START (0)
#define SOC_ASP_CFG_R_HIFIDSP_FLAG0_hifidsp_flag0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hifidsp_flag1 : 32;
    } reg;
} SOC_ASP_CFG_R_HIFIDSP_FLAG1_UNION;
#endif
#define SOC_ASP_CFG_R_HIFIDSP_FLAG1_hifidsp_flag1_START (0)
#define SOC_ASP_CFG_R_HIFIDSP_FLAG1_hifidsp_flag1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hifidsp_flag2 : 32;
    } reg;
} SOC_ASP_CFG_R_HIFIDSP_FLAG2_UNION;
#endif
#define SOC_ASP_CFG_R_HIFIDSP_FLAG2_hifidsp_flag2_START (0)
#define SOC_ASP_CFG_R_HIFIDSP_FLAG2_hifidsp_flag2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hifidsp_flag3 : 32;
    } reg;
} SOC_ASP_CFG_R_HIFIDSP_FLAG3_UNION;
#endif
#define SOC_ASP_CFG_R_HIFIDSP_FLAG3_hifidsp_flag3_START (0)
#define SOC_ASP_CFG_R_HIFIDSP_FLAG3_hifidsp_flag3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_codec_n : 1;
        unsigned int tz_secure_asp_n : 1;
        unsigned int tz_secure_asphdmi_n : 1;
        unsigned int tz_secure_uart_n : 1;
        unsigned int tz_secure_axi2tdm_n : 1;
        unsigned int tz_secure_hts_mst_adaptor_n : 1;
        unsigned int tz_secure_hts_slv_adaptor_n : 1;
        unsigned int tz_secure_edmac1_n : 1;
        unsigned int tz_secure_edmac0_n : 1;
        unsigned int tz_secure_ipc_n : 1;
        unsigned int tz_secure_watchdog_n : 1;
        unsigned int tz_secure_asp_cfg_n : 1;
        unsigned int tz_secure_gpio_n : 1;
        unsigned int tz_secure_timer0_n : 1;
        unsigned int tz_secure_timer1_n : 1;
        unsigned int tz_secure_dmmu_n : 1;
        unsigned int write_en_h100 : 16;
    } reg;
} SOC_ASP_CFG_R_TZ_SECURE_N_UNION;
#endif
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_codec_n_START (0)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_codec_n_END (0)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_asp_n_START (1)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_asp_n_END (1)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_asphdmi_n_START (2)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_asphdmi_n_END (2)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_uart_n_START (3)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_uart_n_END (3)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_axi2tdm_n_START (4)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_axi2tdm_n_END (4)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_hts_mst_adaptor_n_START (5)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_hts_mst_adaptor_n_END (5)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_hts_slv_adaptor_n_START (6)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_hts_slv_adaptor_n_END (6)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_edmac1_n_START (7)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_edmac1_n_END (7)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_edmac0_n_START (8)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_edmac0_n_END (8)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_ipc_n_START (9)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_ipc_n_END (9)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_watchdog_n_START (10)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_watchdog_n_END (10)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_asp_cfg_n_START (11)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_asp_cfg_n_END (11)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_gpio_n_START (12)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_gpio_n_END (12)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_timer0_n_START (13)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_timer0_n_END (13)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_timer1_n_START (14)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_timer1_n_END (14)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_dmmu_n_START (15)
#define SOC_ASP_CFG_R_TZ_SECURE_N_tz_secure_dmmu_n_END (15)
#define SOC_ASP_CFG_R_TZ_SECURE_N_write_en_h100_START (16)
#define SOC_ASP_CFG_R_TZ_SECURE_N_write_en_h100_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ocram_r0size : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ASP_CFG_R_OCRAM_R0SIZE_UNION;
#endif
#define SOC_ASP_CFG_R_OCRAM_R0SIZE_ocram_r0size_START (0)
#define SOC_ASP_CFG_R_OCRAM_R0SIZE_ocram_r0size_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int axi2tdm_intf0_secure_n : 1;
        unsigned int axi2tdm_intf1_secure_n : 1;
        unsigned int axi2tdm_intf2_secure_n : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 28;
    } reg;
} SOC_ASP_CFG_R_SIO_LOOP_SECURE_N_UNION;
#endif
#define SOC_ASP_CFG_R_SIO_LOOP_SECURE_N_axi2tdm_intf0_secure_n_START (0)
#define SOC_ASP_CFG_R_SIO_LOOP_SECURE_N_axi2tdm_intf0_secure_n_END (0)
#define SOC_ASP_CFG_R_SIO_LOOP_SECURE_N_axi2tdm_intf1_secure_n_START (1)
#define SOC_ASP_CFG_R_SIO_LOOP_SECURE_N_axi2tdm_intf1_secure_n_END (1)
#define SOC_ASP_CFG_R_SIO_LOOP_SECURE_N_axi2tdm_intf2_secure_n_START (2)
#define SOC_ASP_CFG_R_SIO_LOOP_SECURE_N_axi2tdm_intf2_secure_n_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int asp_hdmi_int_secure : 1;
        unsigned int intr0_modem_ipc2hifi_s : 1;
        unsigned int intr1_modem_ipc2hifi_s : 1;
        unsigned int intr_hisee_hifi_fast0 : 1;
        unsigned int tds_hifi_intr : 1;
        unsigned int intr_hisee_hifi_comm : 1;
        unsigned int intr_ao_ipc_comm : 1;
        unsigned int intr_ao_ipc_fast : 1;
        unsigned int hieps_hifi_fast_intr : 1;
        unsigned int hieps_hifi_comm_intr : 1;
        unsigned int spa3_abnormal_intr : 1;
        unsigned int spa2_abnormal_intr : 1;
        unsigned int spa1_abnormal_intr : 1;
        unsigned int intr1_ipc_sec_ipc : 1;
        unsigned int intr0_ipc_sec_ipc : 1;
        unsigned int dma_s_intr1 : 1;
        unsigned int asp_hdmi_int_sec : 1;
        unsigned int intr_mad_wakeup : 1;
        unsigned int intr_asp_timer1_1 : 1;
        unsigned int intr_asp_timer1_0 : 1;
        unsigned int intr_asp_timer0_1 : 1;
        unsigned int intr_asp_timer0_0 : 1;
        unsigned int intr_watch_dog : 1;
        unsigned int intr_ipc_hifi : 1;
        unsigned int intr_gpio_hifi : 1;
        unsigned int spa0_abnormal_intr : 1;
        unsigned int noise_meter_intr_hifi : 1;
        unsigned int audio_hts_event_intr : 1;
        unsigned int arpp2hifi_intr_s : 1;
        unsigned int int_hts_slv_adapter_error : 1;
        unsigned int int_hts_mst_adapter_error : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_ASP_CFG_R_INTR_S_INI_UNION;
#endif
#define SOC_ASP_CFG_R_INTR_S_INI_asp_hdmi_int_secure_START (0)
#define SOC_ASP_CFG_R_INTR_S_INI_asp_hdmi_int_secure_END (0)
#define SOC_ASP_CFG_R_INTR_S_INI_intr0_modem_ipc2hifi_s_START (1)
#define SOC_ASP_CFG_R_INTR_S_INI_intr0_modem_ipc2hifi_s_END (1)
#define SOC_ASP_CFG_R_INTR_S_INI_intr1_modem_ipc2hifi_s_START (2)
#define SOC_ASP_CFG_R_INTR_S_INI_intr1_modem_ipc2hifi_s_END (2)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_hisee_hifi_fast0_START (3)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_hisee_hifi_fast0_END (3)
#define SOC_ASP_CFG_R_INTR_S_INI_tds_hifi_intr_START (4)
#define SOC_ASP_CFG_R_INTR_S_INI_tds_hifi_intr_END (4)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_hisee_hifi_comm_START (5)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_hisee_hifi_comm_END (5)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_ao_ipc_comm_START (6)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_ao_ipc_comm_END (6)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_ao_ipc_fast_START (7)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_ao_ipc_fast_END (7)
#define SOC_ASP_CFG_R_INTR_S_INI_hieps_hifi_fast_intr_START (8)
#define SOC_ASP_CFG_R_INTR_S_INI_hieps_hifi_fast_intr_END (8)
#define SOC_ASP_CFG_R_INTR_S_INI_hieps_hifi_comm_intr_START (9)
#define SOC_ASP_CFG_R_INTR_S_INI_hieps_hifi_comm_intr_END (9)
#define SOC_ASP_CFG_R_INTR_S_INI_spa3_abnormal_intr_START (10)
#define SOC_ASP_CFG_R_INTR_S_INI_spa3_abnormal_intr_END (10)
#define SOC_ASP_CFG_R_INTR_S_INI_spa2_abnormal_intr_START (11)
#define SOC_ASP_CFG_R_INTR_S_INI_spa2_abnormal_intr_END (11)
#define SOC_ASP_CFG_R_INTR_S_INI_spa1_abnormal_intr_START (12)
#define SOC_ASP_CFG_R_INTR_S_INI_spa1_abnormal_intr_END (12)
#define SOC_ASP_CFG_R_INTR_S_INI_intr1_ipc_sec_ipc_START (13)
#define SOC_ASP_CFG_R_INTR_S_INI_intr1_ipc_sec_ipc_END (13)
#define SOC_ASP_CFG_R_INTR_S_INI_intr0_ipc_sec_ipc_START (14)
#define SOC_ASP_CFG_R_INTR_S_INI_intr0_ipc_sec_ipc_END (14)
#define SOC_ASP_CFG_R_INTR_S_INI_dma_s_intr1_START (15)
#define SOC_ASP_CFG_R_INTR_S_INI_dma_s_intr1_END (15)
#define SOC_ASP_CFG_R_INTR_S_INI_asp_hdmi_int_sec_START (16)
#define SOC_ASP_CFG_R_INTR_S_INI_asp_hdmi_int_sec_END (16)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_mad_wakeup_START (17)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_mad_wakeup_END (17)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_asp_timer1_1_START (18)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_asp_timer1_1_END (18)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_asp_timer1_0_START (19)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_asp_timer1_0_END (19)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_asp_timer0_1_START (20)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_asp_timer0_1_END (20)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_asp_timer0_0_START (21)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_asp_timer0_0_END (21)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_watch_dog_START (22)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_watch_dog_END (22)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_ipc_hifi_START (23)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_ipc_hifi_END (23)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_gpio_hifi_START (24)
#define SOC_ASP_CFG_R_INTR_S_INI_intr_gpio_hifi_END (24)
#define SOC_ASP_CFG_R_INTR_S_INI_spa0_abnormal_intr_START (25)
#define SOC_ASP_CFG_R_INTR_S_INI_spa0_abnormal_intr_END (25)
#define SOC_ASP_CFG_R_INTR_S_INI_noise_meter_intr_hifi_START (26)
#define SOC_ASP_CFG_R_INTR_S_INI_noise_meter_intr_hifi_END (26)
#define SOC_ASP_CFG_R_INTR_S_INI_audio_hts_event_intr_START (27)
#define SOC_ASP_CFG_R_INTR_S_INI_audio_hts_event_intr_END (27)
#define SOC_ASP_CFG_R_INTR_S_INI_arpp2hifi_intr_s_START (28)
#define SOC_ASP_CFG_R_INTR_S_INI_arpp2hifi_intr_s_END (28)
#define SOC_ASP_CFG_R_INTR_S_INI_int_hts_slv_adapter_error_START (29)
#define SOC_ASP_CFG_R_INTR_S_INI_int_hts_slv_adapter_error_END (29)
#define SOC_ASP_CFG_R_INTR_S_INI_int_hts_mst_adapter_error_START (30)
#define SOC_ASP_CFG_R_INTR_S_INI_int_hts_mst_adapter_error_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int asp_hdmi_int_secure_en_mask : 1;
        unsigned int intr0_modem_ipc2hifi_s_mask : 1;
        unsigned int intr1_modem_ipc2hifi_s_mask : 1;
        unsigned int intr_hisee_hifi_fast0_mask : 1;
        unsigned int intr_soc_peri_eicc_1_en_mask : 1;
        unsigned int intr_hisee_hifi_comm_mask : 1;
        unsigned int intr_ao_ipc_comm_mask : 1;
        unsigned int intr_ao_ipc_fast_mask : 1;
        unsigned int hieps_hifi_fast_intr_mask : 1;
        unsigned int hieps_hifi_comm_intr_mask : 1;
        unsigned int spa3_abnormal_intr_mask : 1;
        unsigned int spa2_abnormal_intr_mask : 1;
        unsigned int spa1_abnormal_intr_mask : 1;
        unsigned int intr1_ipc_sec_ipc_mask : 1;
        unsigned int intr0_ipc_sec_ipc_mask : 1;
        unsigned int dma_s_intr1_mask : 1;
        unsigned int asp_hdmi_int_sec_mask : 1;
        unsigned int intr_mad_wakeup_mask : 1;
        unsigned int intr_asp_timer1_1_mask : 1;
        unsigned int intr_asp_timer1_0_mask : 1;
        unsigned int intr_asp_timer0_1_mask : 1;
        unsigned int intr_asp_timer0_0_mask : 1;
        unsigned int intr_watch_dog_mask : 1;
        unsigned int intr_ipc_hifi_mask : 1;
        unsigned int intr_gpio_hifi_mask : 1;
        unsigned int spa0_abnormal_intr_mask : 1;
        unsigned int noise_meter_intr_hifi_mask : 1;
        unsigned int audio_hts_event_intr_mask : 1;
        unsigned int arpp2hifi_intr_s_mask : 1;
        unsigned int int_hts_slv_adapter_error_mask : 1;
        unsigned int int_hts_mst_adapter_error_mask : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_ASP_CFG_R_INTR_S_EN_UNION;
#endif
#define SOC_ASP_CFG_R_INTR_S_EN_asp_hdmi_int_secure_en_mask_START (0)
#define SOC_ASP_CFG_R_INTR_S_EN_asp_hdmi_int_secure_en_mask_END (0)
#define SOC_ASP_CFG_R_INTR_S_EN_intr0_modem_ipc2hifi_s_mask_START (1)
#define SOC_ASP_CFG_R_INTR_S_EN_intr0_modem_ipc2hifi_s_mask_END (1)
#define SOC_ASP_CFG_R_INTR_S_EN_intr1_modem_ipc2hifi_s_mask_START (2)
#define SOC_ASP_CFG_R_INTR_S_EN_intr1_modem_ipc2hifi_s_mask_END (2)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_hisee_hifi_fast0_mask_START (3)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_hisee_hifi_fast0_mask_END (3)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_soc_peri_eicc_1_en_mask_START (4)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_soc_peri_eicc_1_en_mask_END (4)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_hisee_hifi_comm_mask_START (5)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_hisee_hifi_comm_mask_END (5)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_ao_ipc_comm_mask_START (6)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_ao_ipc_comm_mask_END (6)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_ao_ipc_fast_mask_START (7)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_ao_ipc_fast_mask_END (7)
#define SOC_ASP_CFG_R_INTR_S_EN_hieps_hifi_fast_intr_mask_START (8)
#define SOC_ASP_CFG_R_INTR_S_EN_hieps_hifi_fast_intr_mask_END (8)
#define SOC_ASP_CFG_R_INTR_S_EN_hieps_hifi_comm_intr_mask_START (9)
#define SOC_ASP_CFG_R_INTR_S_EN_hieps_hifi_comm_intr_mask_END (9)
#define SOC_ASP_CFG_R_INTR_S_EN_spa3_abnormal_intr_mask_START (10)
#define SOC_ASP_CFG_R_INTR_S_EN_spa3_abnormal_intr_mask_END (10)
#define SOC_ASP_CFG_R_INTR_S_EN_spa2_abnormal_intr_mask_START (11)
#define SOC_ASP_CFG_R_INTR_S_EN_spa2_abnormal_intr_mask_END (11)
#define SOC_ASP_CFG_R_INTR_S_EN_spa1_abnormal_intr_mask_START (12)
#define SOC_ASP_CFG_R_INTR_S_EN_spa1_abnormal_intr_mask_END (12)
#define SOC_ASP_CFG_R_INTR_S_EN_intr1_ipc_sec_ipc_mask_START (13)
#define SOC_ASP_CFG_R_INTR_S_EN_intr1_ipc_sec_ipc_mask_END (13)
#define SOC_ASP_CFG_R_INTR_S_EN_intr0_ipc_sec_ipc_mask_START (14)
#define SOC_ASP_CFG_R_INTR_S_EN_intr0_ipc_sec_ipc_mask_END (14)
#define SOC_ASP_CFG_R_INTR_S_EN_dma_s_intr1_mask_START (15)
#define SOC_ASP_CFG_R_INTR_S_EN_dma_s_intr1_mask_END (15)
#define SOC_ASP_CFG_R_INTR_S_EN_asp_hdmi_int_sec_mask_START (16)
#define SOC_ASP_CFG_R_INTR_S_EN_asp_hdmi_int_sec_mask_END (16)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_mad_wakeup_mask_START (17)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_mad_wakeup_mask_END (17)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_asp_timer1_1_mask_START (18)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_asp_timer1_1_mask_END (18)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_asp_timer1_0_mask_START (19)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_asp_timer1_0_mask_END (19)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_asp_timer0_1_mask_START (20)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_asp_timer0_1_mask_END (20)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_asp_timer0_0_mask_START (21)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_asp_timer0_0_mask_END (21)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_watch_dog_mask_START (22)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_watch_dog_mask_END (22)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_ipc_hifi_mask_START (23)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_ipc_hifi_mask_END (23)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_gpio_hifi_mask_START (24)
#define SOC_ASP_CFG_R_INTR_S_EN_intr_gpio_hifi_mask_END (24)
#define SOC_ASP_CFG_R_INTR_S_EN_spa0_abnormal_intr_mask_START (25)
#define SOC_ASP_CFG_R_INTR_S_EN_spa0_abnormal_intr_mask_END (25)
#define SOC_ASP_CFG_R_INTR_S_EN_noise_meter_intr_hifi_mask_START (26)
#define SOC_ASP_CFG_R_INTR_S_EN_noise_meter_intr_hifi_mask_END (26)
#define SOC_ASP_CFG_R_INTR_S_EN_audio_hts_event_intr_mask_START (27)
#define SOC_ASP_CFG_R_INTR_S_EN_audio_hts_event_intr_mask_END (27)
#define SOC_ASP_CFG_R_INTR_S_EN_arpp2hifi_intr_s_mask_START (28)
#define SOC_ASP_CFG_R_INTR_S_EN_arpp2hifi_intr_s_mask_END (28)
#define SOC_ASP_CFG_R_INTR_S_EN_int_hts_slv_adapter_error_mask_START (29)
#define SOC_ASP_CFG_R_INTR_S_EN_int_hts_slv_adapter_error_mask_END (29)
#define SOC_ASP_CFG_R_INTR_S_EN_int_hts_mst_adapter_error_mask_START (30)
#define SOC_ASP_CFG_R_INTR_S_EN_int_hts_mst_adapter_error_mask_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int asp_hdmi_int_secure_mstat : 1;
        unsigned int intr0_modem_ipc2hifi_s_mstat : 1;
        unsigned int intr1_modem_ipc2hifi_s_mstat : 1;
        unsigned int intr_hisee_hifi_fast0_mstat : 1;
        unsigned int intr_soc_peri_eicc_1_hifi_mstat : 1;
        unsigned int intr_hisee_hifi_comm_mstat : 1;
        unsigned int intr_ao_ipc_comm_mstat : 1;
        unsigned int intr_ao_ipc_fast_mstat : 1;
        unsigned int hieps_hifi_fast_intr_mstat : 1;
        unsigned int hieps_hifi_comm_intr_mstat : 1;
        unsigned int spa3_abnormal_intr_mstat : 1;
        unsigned int spa2_abnormal_intr_mstat : 1;
        unsigned int spa1_abnormal_intr_mstat : 1;
        unsigned int intr1_ipc_sec_ipc_mstat : 1;
        unsigned int intr0_ipc_sec_ipc_mstat : 1;
        unsigned int dma_s_intr1_mstat : 1;
        unsigned int asp_hdmi_int_sec_mstat : 1;
        unsigned int intr_mad_wakeup_mstat : 1;
        unsigned int intr_asp_timer1_1_mstat : 1;
        unsigned int intr_asp_timer1_0_mstat : 1;
        unsigned int intr_asp_timer0_1_mstat : 1;
        unsigned int intr_asp_timer0_0_mstat : 1;
        unsigned int intr_watch_dog_mstat : 1;
        unsigned int intr_ipc_hifi_mstat : 1;
        unsigned int intr_gpio_hifi_mstat : 1;
        unsigned int spa0_abnormal_intr_mstat : 1;
        unsigned int noise_meter_intr_hifi_mstat : 1;
        unsigned int audio_hts_event_intr_mstat : 1;
        unsigned int arpp2hifi_intr_s_mstat : 1;
        unsigned int int_hts_slv_adapter_error_mstat : 1;
        unsigned int int_hts_mst_adapter_error_mstat : 1;
        unsigned int reserved : 1;
    } reg;
} SOC_ASP_CFG_R_INTR_S_MASK_UNION;
#endif
#define SOC_ASP_CFG_R_INTR_S_MASK_asp_hdmi_int_secure_mstat_START (0)
#define SOC_ASP_CFG_R_INTR_S_MASK_asp_hdmi_int_secure_mstat_END (0)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr0_modem_ipc2hifi_s_mstat_START (1)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr0_modem_ipc2hifi_s_mstat_END (1)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr1_modem_ipc2hifi_s_mstat_START (2)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr1_modem_ipc2hifi_s_mstat_END (2)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_hisee_hifi_fast0_mstat_START (3)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_hisee_hifi_fast0_mstat_END (3)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_soc_peri_eicc_1_hifi_mstat_START (4)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_soc_peri_eicc_1_hifi_mstat_END (4)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_hisee_hifi_comm_mstat_START (5)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_hisee_hifi_comm_mstat_END (5)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_ao_ipc_comm_mstat_START (6)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_ao_ipc_comm_mstat_END (6)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_ao_ipc_fast_mstat_START (7)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_ao_ipc_fast_mstat_END (7)
#define SOC_ASP_CFG_R_INTR_S_MASK_hieps_hifi_fast_intr_mstat_START (8)
#define SOC_ASP_CFG_R_INTR_S_MASK_hieps_hifi_fast_intr_mstat_END (8)
#define SOC_ASP_CFG_R_INTR_S_MASK_hieps_hifi_comm_intr_mstat_START (9)
#define SOC_ASP_CFG_R_INTR_S_MASK_hieps_hifi_comm_intr_mstat_END (9)
#define SOC_ASP_CFG_R_INTR_S_MASK_spa3_abnormal_intr_mstat_START (10)
#define SOC_ASP_CFG_R_INTR_S_MASK_spa3_abnormal_intr_mstat_END (10)
#define SOC_ASP_CFG_R_INTR_S_MASK_spa2_abnormal_intr_mstat_START (11)
#define SOC_ASP_CFG_R_INTR_S_MASK_spa2_abnormal_intr_mstat_END (11)
#define SOC_ASP_CFG_R_INTR_S_MASK_spa1_abnormal_intr_mstat_START (12)
#define SOC_ASP_CFG_R_INTR_S_MASK_spa1_abnormal_intr_mstat_END (12)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr1_ipc_sec_ipc_mstat_START (13)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr1_ipc_sec_ipc_mstat_END (13)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr0_ipc_sec_ipc_mstat_START (14)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr0_ipc_sec_ipc_mstat_END (14)
#define SOC_ASP_CFG_R_INTR_S_MASK_dma_s_intr1_mstat_START (15)
#define SOC_ASP_CFG_R_INTR_S_MASK_dma_s_intr1_mstat_END (15)
#define SOC_ASP_CFG_R_INTR_S_MASK_asp_hdmi_int_sec_mstat_START (16)
#define SOC_ASP_CFG_R_INTR_S_MASK_asp_hdmi_int_sec_mstat_END (16)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_mad_wakeup_mstat_START (17)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_mad_wakeup_mstat_END (17)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_asp_timer1_1_mstat_START (18)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_asp_timer1_1_mstat_END (18)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_asp_timer1_0_mstat_START (19)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_asp_timer1_0_mstat_END (19)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_asp_timer0_1_mstat_START (20)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_asp_timer0_1_mstat_END (20)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_asp_timer0_0_mstat_START (21)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_asp_timer0_0_mstat_END (21)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_watch_dog_mstat_START (22)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_watch_dog_mstat_END (22)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_ipc_hifi_mstat_START (23)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_ipc_hifi_mstat_END (23)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_gpio_hifi_mstat_START (24)
#define SOC_ASP_CFG_R_INTR_S_MASK_intr_gpio_hifi_mstat_END (24)
#define SOC_ASP_CFG_R_INTR_S_MASK_spa0_abnormal_intr_mstat_START (25)
#define SOC_ASP_CFG_R_INTR_S_MASK_spa0_abnormal_intr_mstat_END (25)
#define SOC_ASP_CFG_R_INTR_S_MASK_noise_meter_intr_hifi_mstat_START (26)
#define SOC_ASP_CFG_R_INTR_S_MASK_noise_meter_intr_hifi_mstat_END (26)
#define SOC_ASP_CFG_R_INTR_S_MASK_audio_hts_event_intr_mstat_START (27)
#define SOC_ASP_CFG_R_INTR_S_MASK_audio_hts_event_intr_mstat_END (27)
#define SOC_ASP_CFG_R_INTR_S_MASK_arpp2hifi_intr_s_mstat_START (28)
#define SOC_ASP_CFG_R_INTR_S_MASK_arpp2hifi_intr_s_mstat_END (28)
#define SOC_ASP_CFG_R_INTR_S_MASK_int_hts_slv_adapter_error_mstat_START (29)
#define SOC_ASP_CFG_R_INTR_S_MASK_int_hts_slv_adapter_error_mstat_END (29)
#define SOC_ASP_CFG_R_INTR_S_MASK_int_hts_mst_adapter_error_mstat_START (30)
#define SOC_ASP_CFG_R_INTR_S_MASK_int_hts_mst_adapter_error_mstat_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp_addr_remap_length : 8;
        unsigned int dsp_addr_remapping_en : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_ASP_CFG_R_DSP_REMAPPING_EN_UNION;
#endif
#define SOC_ASP_CFG_R_DSP_REMAPPING_EN_dsp_addr_remap_length_START (0)
#define SOC_ASP_CFG_R_DSP_REMAPPING_EN_dsp_addr_remap_length_END (7)
#define SOC_ASP_CFG_R_DSP_REMAPPING_EN_dsp_addr_remapping_en_START (8)
#define SOC_ASP_CFG_R_DSP_REMAPPING_EN_dsp_addr_remapping_en_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 20;
        unsigned int asp_reserved_start_addr : 12;
    } reg;
} SOC_ASP_CFG_R_DSP_REMAPPING_SRC_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DSP_REMAPPING_SRC_BASE_ADDR_asp_reserved_start_addr_START (20)
#define SOC_ASP_CFG_R_DSP_REMAPPING_SRC_BASE_ADDR_asp_reserved_start_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 20;
        unsigned int ddr_start_addr : 12;
    } reg;
} SOC_ASP_CFG_R_DSP_REMAPPING_DES_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DSP_REMAPPING_DES_BASE_ADDR_ddr_start_addr_START (20)
#define SOC_ASP_CFG_R_DSP_REMAPPING_DES_BASE_ADDR_ddr_start_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_harq_remap_addr_len : 9;
        unsigned int ddr_harq_remap_en : 1;
        unsigned int ddr_harq_remap_awcache : 4;
        unsigned int ddr_harq_remap_arcache : 4;
        unsigned int reserved : 14;
    } reg;
} SOC_ASP_CFG_R_DDR_HARQ_REMAP_EN_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_EN_ddr_harq_remap_addr_len_START (0)
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_EN_ddr_harq_remap_addr_len_END (8)
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_EN_ddr_harq_remap_en_START (9)
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_EN_ddr_harq_remap_en_END (9)
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_EN_ddr_harq_remap_awcache_START (10)
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_EN_ddr_harq_remap_awcache_END (13)
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_EN_ddr_harq_remap_arcache_START (14)
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_EN_ddr_harq_remap_arcache_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int ddr_harq_remap_src_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_HARQ_REMAP_SRC_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_SRC_BASE_ADDR_ddr_harq_remap_src_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_SRC_BASE_ADDR_ddr_harq_remap_src_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int ddr_harq_remap_des_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_HARQ_REMAP_DES_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_DES_BASE_ADDR_ddr_harq_remap_des_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_HARQ_REMAP_DES_BASE_ADDR_ddr_harq_remap_des_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_mmbuf_remap_addr_len : 9;
        unsigned int ddr_mmbuf_remap_en : 1;
        unsigned int ddr_mmbuf_remap_awcache : 4;
        unsigned int ddr_mmbuf_remap_arcache : 4;
        unsigned int reserved : 14;
    } reg;
} SOC_ASP_CFG_R_DDR_MMBUF_REMAP_EN_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_EN_ddr_mmbuf_remap_addr_len_START (0)
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_EN_ddr_mmbuf_remap_addr_len_END (8)
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_EN_ddr_mmbuf_remap_en_START (9)
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_EN_ddr_mmbuf_remap_en_END (9)
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_EN_ddr_mmbuf_remap_awcache_START (10)
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_EN_ddr_mmbuf_remap_awcache_END (13)
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_EN_ddr_mmbuf_remap_arcache_START (14)
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_EN_ddr_mmbuf_remap_arcache_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int ddr_mmbuf_remap_src_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_MMBUF_REMAP_SRC_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_SRC_BASE_ADDR_ddr_mmbuf_remap_src_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_SRC_BASE_ADDR_ddr_mmbuf_remap_src_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int ddr_mmbuf_remap_des_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_MMBUF_REMAP_DES_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_DES_BASE_ADDR_ddr_mmbuf_remap_des_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_MMBUF_REMAP_DES_BASE_ADDR_ddr_mmbuf_remap_des_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ddr_ocram_remap_addr_len : 9;
        unsigned int ddr_ocram_remap_en : 1;
        unsigned int ddr_ocram_remap_awcache : 4;
        unsigned int ddr_ocram_remap_arcache : 4;
        unsigned int reserved : 14;
    } reg;
} SOC_ASP_CFG_R_DDR_OCRAM_REMAP_EN_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_EN_ddr_ocram_remap_addr_len_START (0)
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_EN_ddr_ocram_remap_addr_len_END (8)
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_EN_ddr_ocram_remap_en_START (9)
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_EN_ddr_ocram_remap_en_END (9)
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_EN_ddr_ocram_remap_awcache_START (10)
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_EN_ddr_ocram_remap_awcache_END (13)
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_EN_ddr_ocram_remap_arcache_START (14)
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_EN_ddr_ocram_remap_arcache_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int ddr_ocram_remap_src_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_OCRAM_REMAP_SRC_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_SRC_BASE_ADDR_ddr_ocram_remap_src_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_SRC_BASE_ADDR_ddr_ocram_remap_src_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int ddr_ocram_remap_des_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_OCRAM_REMAP_DES_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_DES_BASE_ADDR_ddr_ocram_remap_des_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_OCRAM_REMAP_DES_BASE_ADDR_ddr_ocram_remap_des_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ppll0_en : 1;
        unsigned int fll_en : 1;
        unsigned int mmbuf_clk_en : 1;
        unsigned int aobus_clk_en : 1;
        unsigned int asp_pwr_req_hifi : 2;
        unsigned int aobus_clk_sel : 2;
        unsigned int audio_fll_ctrl : 5;
        unsigned int asp_sclk_sw2fll_req : 1;
        unsigned int asp_sclk_sw2fll_ack : 1;
        unsigned int asp_sclk_sw2fll_lock : 1;
        unsigned int write_en_h148 : 16;
    } reg;
} SOC_ASP_CFG_R_MMBUF_CTRL_UNION;
#endif
#define SOC_ASP_CFG_R_MMBUF_CTRL_ppll0_en_START (0)
#define SOC_ASP_CFG_R_MMBUF_CTRL_ppll0_en_END (0)
#define SOC_ASP_CFG_R_MMBUF_CTRL_fll_en_START (1)
#define SOC_ASP_CFG_R_MMBUF_CTRL_fll_en_END (1)
#define SOC_ASP_CFG_R_MMBUF_CTRL_mmbuf_clk_en_START (2)
#define SOC_ASP_CFG_R_MMBUF_CTRL_mmbuf_clk_en_END (2)
#define SOC_ASP_CFG_R_MMBUF_CTRL_aobus_clk_en_START (3)
#define SOC_ASP_CFG_R_MMBUF_CTRL_aobus_clk_en_END (3)
#define SOC_ASP_CFG_R_MMBUF_CTRL_asp_pwr_req_hifi_START (4)
#define SOC_ASP_CFG_R_MMBUF_CTRL_asp_pwr_req_hifi_END (5)
#define SOC_ASP_CFG_R_MMBUF_CTRL_aobus_clk_sel_START (6)
#define SOC_ASP_CFG_R_MMBUF_CTRL_aobus_clk_sel_END (7)
#define SOC_ASP_CFG_R_MMBUF_CTRL_audio_fll_ctrl_START (8)
#define SOC_ASP_CFG_R_MMBUF_CTRL_audio_fll_ctrl_END (12)
#define SOC_ASP_CFG_R_MMBUF_CTRL_asp_sclk_sw2fll_req_START (13)
#define SOC_ASP_CFG_R_MMBUF_CTRL_asp_sclk_sw2fll_req_END (13)
#define SOC_ASP_CFG_R_MMBUF_CTRL_asp_sclk_sw2fll_ack_START (14)
#define SOC_ASP_CFG_R_MMBUF_CTRL_asp_sclk_sw2fll_ack_END (14)
#define SOC_ASP_CFG_R_MMBUF_CTRL_asp_sclk_sw2fll_lock_START (15)
#define SOC_ASP_CFG_R_MMBUF_CTRL_asp_sclk_sw2fll_lock_END (15)
#define SOC_ASP_CFG_R_MMBUF_CTRL_write_en_h148_START (16)
#define SOC_ASP_CFG_R_MMBUF_CTRL_write_en_h148_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hifidsp_idle_time_cfgcnt : 8;
        unsigned int div_hifidsp_clk_auto : 3;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 2;
        unsigned int dsp_pwaitmode_bypass : 1;
        unsigned int dsp_hi_axi_idle_st_bypass : 1;
        unsigned int reserved_2 : 3;
        unsigned int dmmu_clkup_req_bypass : 1;
        unsigned int reserved_3 : 12;
    } reg;
} SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_UNION;
#endif
#define SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_hifidsp_idle_time_cfgcnt_START (0)
#define SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_hifidsp_idle_time_cfgcnt_END (7)
#define SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_div_hifidsp_clk_auto_START (8)
#define SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_div_hifidsp_clk_auto_END (10)
#define SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_dsp_pwaitmode_bypass_START (14)
#define SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_dsp_pwaitmode_bypass_END (14)
#define SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_dsp_hi_axi_idle_st_bypass_START (15)
#define SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_dsp_hi_axi_idle_st_bypass_END (15)
#define SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_dmmu_clkup_req_bypass_START (19)
#define SOC_ASP_CFG_R_HIFIDSP_CLK_DIV_AUTO_dmmu_clkup_req_bypass_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 32;
    } reg;
} SOC_ASP_CFG_R_INTR_FREQ_OFFSET_CFG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp0_addr_mon0_en : 1;
        unsigned int dsp0_addr_mon1_en : 1;
        unsigned int dsp0_addr_mon2_en : 1;
        unsigned int dsp0_addr_mon3_en : 1;
        unsigned int dsp0_addr_mon4_en : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_EN_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_EN_ADDR_dsp0_addr_mon0_en_START (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_EN_ADDR_dsp0_addr_mon0_en_END (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_EN_ADDR_dsp0_addr_mon1_en_START (1)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_EN_ADDR_dsp0_addr_mon1_en_END (1)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_EN_ADDR_dsp0_addr_mon2_en_START (2)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_EN_ADDR_dsp0_addr_mon2_en_END (2)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_EN_ADDR_dsp0_addr_mon3_en_START (3)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_EN_ADDR_dsp0_addr_mon3_en_END (3)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_EN_ADDR_dsp0_addr_mon4_en_START (4)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_EN_ADDR_dsp0_addr_mon4_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp0_addr_mon_intr_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_CLR_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_CLR_ADDR_dsp0_addr_mon_intr_clr_START (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_CLR_ADDR_dsp0_addr_mon_intr_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp0_addr_mon0_intr_en : 1;
        unsigned int dsp0_addr_mon1_intr_en : 1;
        unsigned int dsp0_addr_mon2_intr_en : 1;
        unsigned int dsp0_addr_mon3_intr_en : 1;
        unsigned int dsp0_addr_mon4_intr_en : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_EN_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_EN_ADDR_dsp0_addr_mon0_intr_en_START (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_EN_ADDR_dsp0_addr_mon0_intr_en_END (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_EN_ADDR_dsp0_addr_mon1_intr_en_START (1)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_EN_ADDR_dsp0_addr_mon1_intr_en_END (1)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_EN_ADDR_dsp0_addr_mon2_intr_en_START (2)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_EN_ADDR_dsp0_addr_mon2_intr_en_END (2)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_EN_ADDR_dsp0_addr_mon3_intr_en_START (3)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_EN_ADDR_dsp0_addr_mon3_intr_en_END (3)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_EN_ADDR_dsp0_addr_mon4_intr_en_START (4)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_EN_ADDR_dsp0_addr_mon4_intr_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp0_addr_monitor0_arhit_intr_stat : 1;
        unsigned int dsp0_addr_monitor0_awhit_intr_stat : 1;
        unsigned int dsp0_addr_monitor1_arhit_intr_stat : 1;
        unsigned int dsp0_addr_monitor1_awhit_intr_stat : 1;
        unsigned int dsp0_addr_monitor2_arhit_intr_stat : 1;
        unsigned int dsp0_addr_monitor2_awhit_intr_stat : 1;
        unsigned int dsp0_addr_monitor3_arhit_intr_stat : 1;
        unsigned int dsp0_addr_monitor3_awhit_intr_stat : 1;
        unsigned int dsp0_addr_monitor4_arhit_intr_stat : 1;
        unsigned int dsp0_addr_monitor4_awhit_intr_stat : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_dsp0_addr_monitor0_arhit_intr_stat_START (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_dsp0_addr_monitor0_arhit_intr_stat_END (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_dsp0_addr_monitor0_awhit_intr_stat_START (1)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_dsp0_addr_monitor0_awhit_intr_stat_END (1)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_dsp0_addr_monitor1_arhit_intr_stat_START (2)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_dsp0_addr_monitor1_arhit_intr_stat_END (2)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_dsp0_addr_monitor1_awhit_intr_stat_START (3)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_dsp0_addr_monitor1_awhit_intr_stat_END (3)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_dsp0_addr_monitor2_arhit_intr_stat_START (4)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_dsp0_addr_monitor2_arhit_intr_stat_END (4)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_dsp0_addr_monitor2_awhit_intr_stat_START (5)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_dsp0_addr_monitor2_awhit_intr_stat_END (5)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_dsp0_addr_monitor3_arhit_intr_stat_START (6)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_dsp0_addr_monitor3_arhit_intr_stat_END (6)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_dsp0_addr_monitor3_awhit_intr_stat_START (7)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_dsp0_addr_monitor3_awhit_intr_stat_END (7)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_dsp0_addr_monitor4_arhit_intr_stat_START (8)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_dsp0_addr_monitor4_arhit_intr_stat_END (8)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_dsp0_addr_monitor4_awhit_intr_stat_START (9)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR_INTR_STAT_ADDR_dsp0_addr_monitor4_awhit_intr_stat_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int dsp0_addr_mon0_addr_base : 20;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_BASE_ADDR_dsp0_addr_mon0_addr_base_START (12)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_BASE_ADDR_dsp0_addr_mon0_addr_base_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int dsp0_addr_mon0_addr_len : 20;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_LEN_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_LEN_ADDR_dsp0_addr_mon0_addr_len_START (12)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_LEN_ADDR_dsp0_addr_mon0_addr_len_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp0_addr_mon0_hit_awaddr : 32;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_HIT_AWADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_HIT_AWADDR_dsp0_addr_mon0_hit_awaddr_START (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_HIT_AWADDR_dsp0_addr_mon0_hit_awaddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp0_addr_mon0_hit_araddr : 32;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_HIT_ARADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_HIT_ARADDR_dsp0_addr_mon0_hit_araddr_START (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR0_HIT_ARADDR_dsp0_addr_mon0_hit_araddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int dsp0_addr_mon1_addr_base : 20;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_BASE_ADDR_dsp0_addr_mon1_addr_base_START (12)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_BASE_ADDR_dsp0_addr_mon1_addr_base_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int dsp0_addr_mon1_addr_len : 20;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_LEN_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_LEN_ADDR_dsp0_addr_mon1_addr_len_START (12)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_LEN_ADDR_dsp0_addr_mon1_addr_len_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp0_addr_mon1_hit_awaddr : 32;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_HIT_AWADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_HIT_AWADDR_dsp0_addr_mon1_hit_awaddr_START (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_HIT_AWADDR_dsp0_addr_mon1_hit_awaddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp0_addr_mon1_hit_araddr : 32;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_HIT_ARADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_HIT_ARADDR_dsp0_addr_mon1_hit_araddr_START (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR1_HIT_ARADDR_dsp0_addr_mon1_hit_araddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int dsp0_addr_mon2_addr_base : 20;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_BASE_ADDR_dsp0_addr_mon2_addr_base_START (12)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_BASE_ADDR_dsp0_addr_mon2_addr_base_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int dsp0_addr_mon2_addr_len : 20;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_LEN_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_LEN_ADDR_dsp0_addr_mon2_addr_len_START (12)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_LEN_ADDR_dsp0_addr_mon2_addr_len_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp0_addr_mon2_hit_awaddr : 32;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_HIT_AWADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_HIT_AWADDR_dsp0_addr_mon2_hit_awaddr_START (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_HIT_AWADDR_dsp0_addr_mon2_hit_awaddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp0_addr_mon2_hit_araddr : 32;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_HIT_ARADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_HIT_ARADDR_dsp0_addr_mon2_hit_araddr_START (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR2_HIT_ARADDR_dsp0_addr_mon2_hit_araddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int dsp0_addr_mon3_addr_base : 20;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_BASE_ADDR_dsp0_addr_mon3_addr_base_START (12)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_BASE_ADDR_dsp0_addr_mon3_addr_base_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int dsp0_addr_mon3_addr_len : 20;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_LEN_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_LEN_ADDR_dsp0_addr_mon3_addr_len_START (12)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_LEN_ADDR_dsp0_addr_mon3_addr_len_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp0_addr_mon3_hit_awaddr : 32;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_HIT_AWADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_HIT_AWADDR_dsp0_addr_mon3_hit_awaddr_START (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_HIT_AWADDR_dsp0_addr_mon3_hit_awaddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp0_addr_mon3_hit_araddr : 32;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_HIT_ARADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_HIT_ARADDR_dsp0_addr_mon3_hit_araddr_START (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR3_HIT_ARADDR_dsp0_addr_mon3_hit_araddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_s : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_ASP_CFG_R_MEMORY_CTRL_UNION;
#endif
#define SOC_ASP_CFG_R_MEMORY_CTRL_mem_ctrl_s_START (0)
#define SOC_ASP_CFG_R_MEMORY_CTRL_mem_ctrl_s_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hdmi_clk_sel : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 30;
    } reg;
} SOC_ASP_CFG_R_HDMI_CLK_SEL_UNION;
#endif
#define SOC_ASP_CFG_R_HDMI_CLK_SEL_hdmi_clk_sel_START (0)
#define SOC_ASP_CFG_R_HDMI_CLK_SEL_hdmi_clk_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int acc_addr_moni_bypass_addr : 32;
    } reg;
} SOC_ASP_CFG_R_ACC_ADDR_MONI_BYPASS_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACC_ADDR_MONI_BYPASS_ADDR_acc_addr_moni_bypass_addr_START (0)
#define SOC_ASP_CFG_R_ACC_ADDR_MONI_BYPASS_ADDR_acc_addr_moni_bypass_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_hdmi_i2s_adws : 9;
        unsigned int reserved : 7;
        unsigned int write_en_h1e0 : 16;
    } reg;
} SOC_ASP_CFG_R_DIV_HDMI_I2S_ADWS_UNION;
#endif
#define SOC_ASP_CFG_R_DIV_HDMI_I2S_ADWS_div_hdmi_i2s_adws_START (0)
#define SOC_ASP_CFG_R_DIV_HDMI_I2S_ADWS_div_hdmi_i2s_adws_END (8)
#define SOC_ASP_CFG_R_DIV_HDMI_I2S_ADWS_write_en_h1e0_START (16)
#define SOC_ASP_CFG_R_DIV_HDMI_I2S_ADWS_write_en_h1e0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int div_spdif_clk : 10;
        unsigned int reserved : 6;
        unsigned int write_en_h1e4 : 16;
    } reg;
} SOC_ASP_CFG_R_DIV_SPDIF_CLK_UNION;
#endif
#define SOC_ASP_CFG_R_DIV_SPDIF_CLK_div_spdif_clk_START (0)
#define SOC_ASP_CFG_R_DIV_SPDIF_CLK_div_spdif_clk_END (9)
#define SOC_ASP_CFG_R_DIV_SPDIF_CLK_write_en_h1e4_START (16)
#define SOC_ASP_CFG_R_DIV_SPDIF_CLK_write_en_h1e4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int qic_firewall_en : 1;
        unsigned int qic_firewall_err_resp : 1;
        unsigned int reserved : 6;
        unsigned int mid_cfg0 : 8;
        unsigned int mid_cfg1 : 8;
        unsigned int mid_cfg2 : 8;
    } reg;
} SOC_ASP_CFG_R_NOC_FIREWALL_CTRL_UNION;
#endif
#define SOC_ASP_CFG_R_NOC_FIREWALL_CTRL_qic_firewall_en_START (0)
#define SOC_ASP_CFG_R_NOC_FIREWALL_CTRL_qic_firewall_en_END (0)
#define SOC_ASP_CFG_R_NOC_FIREWALL_CTRL_qic_firewall_err_resp_START (1)
#define SOC_ASP_CFG_R_NOC_FIREWALL_CTRL_qic_firewall_err_resp_END (1)
#define SOC_ASP_CFG_R_NOC_FIREWALL_CTRL_mid_cfg0_START (8)
#define SOC_ASP_CFG_R_NOC_FIREWALL_CTRL_mid_cfg0_END (15)
#define SOC_ASP_CFG_R_NOC_FIREWALL_CTRL_mid_cfg1_START (16)
#define SOC_ASP_CFG_R_NOC_FIREWALL_CTRL_mid_cfg1_END (23)
#define SOC_ASP_CFG_R_NOC_FIREWALL_CTRL_mid_cfg2_START (24)
#define SOC_ASP_CFG_R_NOC_FIREWALL_CTRL_mid_cfg2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int secure_en_ddr_remap : 1;
        unsigned int secure_en_ddr_harq_remap : 1;
        unsigned int secure_en_ddr_mmbuf_remap : 1;
        unsigned int secure_en_ddr_ocram_remap : 1;
        unsigned int secure_en_ddr_cache0_remap : 1;
        unsigned int secure_en_ddr_cache1_remap : 1;
        unsigned int secure_en_ddr_cache2_remap : 1;
        unsigned int secure_en_ddr_cache3_remap : 1;
        unsigned int secure_en_ddr_cache4_remap : 1;
        unsigned int reserved_0 : 1;
        unsigned int secure_en_hifi_s2_remap : 1;
        unsigned int secure_en_ddr_cache5_remap : 1;
        unsigned int secure_en_ddr_cache6_remap : 1;
        unsigned int secure_en_ddr_cache7_remap : 1;
        unsigned int secure_en_ddr_cache8_remap : 1;
        unsigned int tz_secure_clkrst_n : 1;
        unsigned int secure_en_dsp0_dsp1_remap : 1;
        unsigned int secure_en_dsp1_dsp0_remap : 1;
        unsigned int reserved_1 : 14;
    } reg;
} SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_UNION;
#endif
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_remap_START (0)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_remap_END (0)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_harq_remap_START (1)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_harq_remap_END (1)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_mmbuf_remap_START (2)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_mmbuf_remap_END (2)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_ocram_remap_START (3)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_ocram_remap_END (3)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache0_remap_START (4)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache0_remap_END (4)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache1_remap_START (5)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache1_remap_END (5)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache2_remap_START (6)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache2_remap_END (6)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache3_remap_START (7)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache3_remap_END (7)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache4_remap_START (8)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache4_remap_END (8)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_hifi_s2_remap_START (10)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_hifi_s2_remap_END (10)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache5_remap_START (11)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache5_remap_END (11)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache6_remap_START (12)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache6_remap_END (12)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache7_remap_START (13)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache7_remap_END (13)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache8_remap_START (14)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_ddr_cache8_remap_END (14)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_tz_secure_clkrst_n_START (15)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_tz_secure_clkrst_n_END (15)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_dsp0_dsp1_remap_START (16)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_dsp0_dsp1_remap_END (16)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_dsp1_dsp0_remap_START (17)
#define SOC_ASP_CFG_R_SECURE_AUTHORITY_EN_secure_en_dsp1_dsp0_remap_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved_0 : 16;
        unsigned int sw_io_debug_sel : 1;
        unsigned int codec_soc_i2s1_sel : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 5;
        unsigned int reserved_3 : 6;
        unsigned int intr_vad_wakeup : 1;
        unsigned int sram_lv_bypass : 1;
    } reg;
} SOC_ASP_CFG_R_SW_SLIM_DMA_SEL_UNION;
#endif
#define SOC_ASP_CFG_R_SW_SLIM_DMA_SEL_sw_io_debug_sel_START (16)
#define SOC_ASP_CFG_R_SW_SLIM_DMA_SEL_sw_io_debug_sel_END (16)
#define SOC_ASP_CFG_R_SW_SLIM_DMA_SEL_codec_soc_i2s1_sel_START (17)
#define SOC_ASP_CFG_R_SW_SLIM_DMA_SEL_codec_soc_i2s1_sel_END (17)
#define SOC_ASP_CFG_R_SW_SLIM_DMA_SEL_intr_vad_wakeup_START (30)
#define SOC_ASP_CFG_R_SW_SLIM_DMA_SEL_intr_vad_wakeup_END (30)
#define SOC_ASP_CFG_R_SW_SLIM_DMA_SEL_sram_lv_bypass_START (31)
#define SOC_ASP_CFG_R_SW_SLIM_DMA_SEL_sram_lv_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int enable_gt_swire_hclk : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 28;
    } reg;
} SOC_ASP_CFG_R_GATE1_EN_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_GATE1_EN_ADDR_enable_gt_swire_hclk_START (0)
#define SOC_ASP_CFG_R_GATE1_EN_ADDR_enable_gt_swire_hclk_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int disable_gt_swire_hclk : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 28;
    } reg;
} SOC_ASP_CFG_R_GATE1_DIS_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_GATE1_DIS_ADDR_disable_gt_swire_hclk_START (0)
#define SOC_ASP_CFG_R_GATE1_DIS_ADDR_disable_gt_swire_hclk_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_swire_hclk : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 28;
    } reg;
} SOC_ASP_CFG_R_GATE1_CLKEN_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_GATE1_CLKEN_ADDR_gt_swire_hclk_START (0)
#define SOC_ASP_CFG_R_GATE1_CLKEN_ADDR_gt_swire_hclk_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_swire_hclk : 1;
        unsigned int st_swire_base_clk : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int st_axi2tdm_49mclk : 1;
        unsigned int st_axi2tdm_aclk : 1;
        unsigned int st_dmac1hclk0 : 1;
        unsigned int st_dmac1hclk1 : 1;
        unsigned int reserved_2 : 24;
    } reg;
} SOC_ASP_CFG_R_GATE1_CLKSTAT_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_GATE1_CLKSTAT_ADDR_st_swire_hclk_START (0)
#define SOC_ASP_CFG_R_GATE1_CLKSTAT_ADDR_st_swire_hclk_END (0)
#define SOC_ASP_CFG_R_GATE1_CLKSTAT_ADDR_st_swire_base_clk_START (1)
#define SOC_ASP_CFG_R_GATE1_CLKSTAT_ADDR_st_swire_base_clk_END (1)
#define SOC_ASP_CFG_R_GATE1_CLKSTAT_ADDR_st_axi2tdm_49mclk_START (4)
#define SOC_ASP_CFG_R_GATE1_CLKSTAT_ADDR_st_axi2tdm_49mclk_END (4)
#define SOC_ASP_CFG_R_GATE1_CLKSTAT_ADDR_st_axi2tdm_aclk_START (5)
#define SOC_ASP_CFG_R_GATE1_CLKSTAT_ADDR_st_axi2tdm_aclk_END (5)
#define SOC_ASP_CFG_R_GATE1_CLKSTAT_ADDR_st_dmac1hclk0_START (6)
#define SOC_ASP_CFG_R_GATE1_CLKSTAT_ADDR_st_dmac1hclk0_END (6)
#define SOC_ASP_CFG_R_GATE1_CLKSTAT_ADDR_st_dmac1hclk1_START (7)
#define SOC_ASP_CFG_R_GATE1_CLKSTAT_ADDR_st_dmac1hclk1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_d1w2r : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ASP_CFG_R_MEMORY_CTRL_D1W2R_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_MEMORY_CTRL_D1W2R_ADDR_mem_ctrl_d1w2r_START (0)
#define SOC_ASP_CFG_R_MEMORY_CTRL_D1W2R_ADDR_mem_ctrl_d1w2r_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int test_proc_out_sw : 32;
    } reg;
} SOC_ASP_CFG_R_TEST_PROC_OUT_SW_UNION;
#endif
#define SOC_ASP_CFG_R_TEST_PROC_OUT_SW_test_proc_out_sw_START (0)
#define SOC_ASP_CFG_R_TEST_PROC_OUT_SW_test_proc_out_sw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp0_ddr_cache0_remap_addr_len : 9;
        unsigned int dsp0_ddr_cache0_remap_en : 1;
        unsigned int ddr_cache0_remap_awcache_m2 : 4;
        unsigned int ddr_cache0_remap_arcache_m2 : 4;
        unsigned int reserved : 14;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE0_REMAP_EN_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_EN_dsp0_ddr_cache0_remap_addr_len_START (0)
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_EN_dsp0_ddr_cache0_remap_addr_len_END (8)
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_EN_dsp0_ddr_cache0_remap_en_START (9)
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_EN_dsp0_ddr_cache0_remap_en_END (9)
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_EN_ddr_cache0_remap_awcache_m2_START (10)
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_EN_ddr_cache0_remap_awcache_m2_END (13)
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_EN_ddr_cache0_remap_arcache_m2_START (14)
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_EN_ddr_cache0_remap_arcache_m2_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int dsp0_ddr_cache0_remap_src_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE0_REMAP_SRC_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_SRC_BASE_ADDR_dsp0_ddr_cache0_remap_src_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_SRC_BASE_ADDR_dsp0_ddr_cache0_remap_src_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int dsp0_ddr_cache0_remap_des_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE0_REMAP_DES_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_DES_BASE_ADDR_dsp0_ddr_cache0_remap_des_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE0_REMAP_DES_BASE_ADDR_dsp0_ddr_cache0_remap_des_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp0_ddr_cache1_remap_addr_len : 9;
        unsigned int dsp0_ddr_cache1_remap_en : 1;
        unsigned int ddr_cache1_remap_awcache_m2 : 4;
        unsigned int ddr_cache1_remap_arcache_m2 : 4;
        unsigned int reserved : 14;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE1_REMAP_EN_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_EN_dsp0_ddr_cache1_remap_addr_len_START (0)
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_EN_dsp0_ddr_cache1_remap_addr_len_END (8)
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_EN_dsp0_ddr_cache1_remap_en_START (9)
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_EN_dsp0_ddr_cache1_remap_en_END (9)
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_EN_ddr_cache1_remap_awcache_m2_START (10)
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_EN_ddr_cache1_remap_awcache_m2_END (13)
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_EN_ddr_cache1_remap_arcache_m2_START (14)
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_EN_ddr_cache1_remap_arcache_m2_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int dsp0_ddr_cache1_remap_src_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE1_REMAP_SRC_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_SRC_BASE_ADDR_dsp0_ddr_cache1_remap_src_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_SRC_BASE_ADDR_dsp0_ddr_cache1_remap_src_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int dsp0_ddr_cache1_remap_des_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE1_REMAP_DES_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_DES_BASE_ADDR_dsp0_ddr_cache1_remap_des_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE1_REMAP_DES_BASE_ADDR_dsp0_ddr_cache1_remap_des_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp0_ddr_cache2_remap_addr_len : 9;
        unsigned int dsp0_ddr_cache2_remap_en : 1;
        unsigned int ddr_cache2_remap_awcache_m2 : 4;
        unsigned int ddr_cache2_remap_arcache_m2 : 4;
        unsigned int reserved : 14;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE2_REMAP_EN_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_EN_dsp0_ddr_cache2_remap_addr_len_START (0)
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_EN_dsp0_ddr_cache2_remap_addr_len_END (8)
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_EN_dsp0_ddr_cache2_remap_en_START (9)
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_EN_dsp0_ddr_cache2_remap_en_END (9)
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_EN_ddr_cache2_remap_awcache_m2_START (10)
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_EN_ddr_cache2_remap_awcache_m2_END (13)
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_EN_ddr_cache2_remap_arcache_m2_START (14)
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_EN_ddr_cache2_remap_arcache_m2_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int dsp0_ddr_cache2_remap_src_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE2_REMAP_SRC_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_SRC_BASE_ADDR_dsp0_ddr_cache2_remap_src_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_SRC_BASE_ADDR_dsp0_ddr_cache2_remap_src_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int dsp0_ddr_cache2_remap_des_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE2_REMAP_DES_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_DES_BASE_ADDR_dsp0_ddr_cache2_remap_des_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE2_REMAP_DES_BASE_ADDR_dsp0_ddr_cache2_remap_des_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp0_ddr_cache3_remap_addr_len : 9;
        unsigned int dsp0_ddr_cache3_remap_en : 1;
        unsigned int ddr_cache3_remap_awcache_m2 : 4;
        unsigned int ddr_cache3_remap_arcache_m2 : 4;
        unsigned int reserved : 14;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE3_REMAP_EN_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_EN_dsp0_ddr_cache3_remap_addr_len_START (0)
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_EN_dsp0_ddr_cache3_remap_addr_len_END (8)
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_EN_dsp0_ddr_cache3_remap_en_START (9)
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_EN_dsp0_ddr_cache3_remap_en_END (9)
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_EN_ddr_cache3_remap_awcache_m2_START (10)
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_EN_ddr_cache3_remap_awcache_m2_END (13)
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_EN_ddr_cache3_remap_arcache_m2_START (14)
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_EN_ddr_cache3_remap_arcache_m2_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int dsp0_ddr_cache3_remap_src_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE3_REMAP_SRC_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_SRC_BASE_ADDR_dsp0_ddr_cache3_remap_src_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_SRC_BASE_ADDR_dsp0_ddr_cache3_remap_src_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int dsp0_ddr_cache3_remap_des_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE3_REMAP_DES_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_DES_BASE_ADDR_dsp0_ddr_cache3_remap_des_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE3_REMAP_DES_BASE_ADDR_dsp0_ddr_cache3_remap_des_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp0_ddr_cache4_remap_addr_len : 9;
        unsigned int dsp0_ddr_cache4_remap_en : 1;
        unsigned int ddr_cache4_remap_awcache_m2 : 4;
        unsigned int ddr_cache4_remap_arcache_m2 : 4;
        unsigned int reserved : 14;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE4_REMAP_EN_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_EN_dsp0_ddr_cache4_remap_addr_len_START (0)
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_EN_dsp0_ddr_cache4_remap_addr_len_END (8)
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_EN_dsp0_ddr_cache4_remap_en_START (9)
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_EN_dsp0_ddr_cache4_remap_en_END (9)
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_EN_ddr_cache4_remap_awcache_m2_START (10)
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_EN_ddr_cache4_remap_awcache_m2_END (13)
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_EN_ddr_cache4_remap_arcache_m2_START (14)
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_EN_ddr_cache4_remap_arcache_m2_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int dsp0_ddr_cache4_remap_src_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE4_REMAP_SRC_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_SRC_BASE_ADDR_dsp0_ddr_cache4_remap_src_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_SRC_BASE_ADDR_dsp0_ddr_cache4_remap_src_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int dsp0_ddr_cache4_remap_des_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE4_REMAP_DES_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_DES_BASE_ADDR_dsp0_ddr_cache4_remap_des_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE4_REMAP_DES_BASE_ADDR_dsp0_ddr_cache4_remap_des_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hdmi_awcache : 4;
        unsigned int hdmi_arcache : 4;
        unsigned int hdmi_cache_sel : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_ASP_CFG_R_H2X_CACHE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_H2X_CACHE_ADDR_hdmi_awcache_START (0)
#define SOC_ASP_CFG_R_H2X_CACHE_ADDR_hdmi_awcache_END (3)
#define SOC_ASP_CFG_R_H2X_CACHE_ADDR_hdmi_arcache_START (4)
#define SOC_ASP_CFG_R_H2X_CACHE_ADDR_hdmi_arcache_END (7)
#define SOC_ASP_CFG_R_H2X_CACHE_ADDR_hdmi_cache_sel_START (8)
#define SOC_ASP_CFG_R_H2X_CACHE_ADDR_hdmi_cache_sel_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp0_hifi_s2_remap_addr_len : 9;
        unsigned int dsp0_hifi_s2_remap_en : 1;
        unsigned int reserved : 2;
        unsigned int dsp0_hifi_s2_remap_src_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_HIFI_S2_REMAP_SRC_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_HIFI_S2_REMAP_SRC_BASE_ADDR_dsp0_hifi_s2_remap_addr_len_START (0)
#define SOC_ASP_CFG_R_HIFI_S2_REMAP_SRC_BASE_ADDR_dsp0_hifi_s2_remap_addr_len_END (8)
#define SOC_ASP_CFG_R_HIFI_S2_REMAP_SRC_BASE_ADDR_dsp0_hifi_s2_remap_en_START (9)
#define SOC_ASP_CFG_R_HIFI_S2_REMAP_SRC_BASE_ADDR_dsp0_hifi_s2_remap_en_END (9)
#define SOC_ASP_CFG_R_HIFI_S2_REMAP_SRC_BASE_ADDR_dsp0_hifi_s2_remap_src_base_addr_START (12)
#define SOC_ASP_CFG_R_HIFI_S2_REMAP_SRC_BASE_ADDR_dsp0_hifi_s2_remap_src_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int dsp0_hifi_s2_remap_des_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_HIFI_S2_REMAP_DES_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_HIFI_S2_REMAP_DES_BASE_ADDR_dsp0_hifi_s2_remap_des_base_addr_START (12)
#define SOC_ASP_CFG_R_HIFI_S2_REMAP_DES_BASE_ADDR_dsp0_hifi_s2_remap_des_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp0_ddr_cache5_remap_addr_len : 9;
        unsigned int dsp0_ddr_cache5_remap_en : 1;
        unsigned int ddr_cache5_remap_awcache_m2 : 4;
        unsigned int ddr_cache5_remap_arcache_m2 : 4;
        unsigned int reserved : 14;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE5_REMAP_EN_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_EN_dsp0_ddr_cache5_remap_addr_len_START (0)
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_EN_dsp0_ddr_cache5_remap_addr_len_END (8)
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_EN_dsp0_ddr_cache5_remap_en_START (9)
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_EN_dsp0_ddr_cache5_remap_en_END (9)
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_EN_ddr_cache5_remap_awcache_m2_START (10)
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_EN_ddr_cache5_remap_awcache_m2_END (13)
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_EN_ddr_cache5_remap_arcache_m2_START (14)
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_EN_ddr_cache5_remap_arcache_m2_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int dsp0_ddr_cache5_remap_src_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE5_REMAP_SRC_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_SRC_BASE_ADDR_dsp0_ddr_cache5_remap_src_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_SRC_BASE_ADDR_dsp0_ddr_cache5_remap_src_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int dsp0_ddr_cache5_remap_des_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE5_REMAP_DES_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_DES_BASE_ADDR_dsp0_ddr_cache5_remap_des_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE5_REMAP_DES_BASE_ADDR_dsp0_ddr_cache5_remap_des_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp0_ddr_cache6_remap_addr_len : 9;
        unsigned int dsp0_ddr_cache6_remap_en : 1;
        unsigned int ddr_cache6_remap_awcache_m2 : 4;
        unsigned int ddr_cache6_remap_arcache_m2 : 4;
        unsigned int reserved : 14;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE6_REMAP_EN_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_EN_dsp0_ddr_cache6_remap_addr_len_START (0)
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_EN_dsp0_ddr_cache6_remap_addr_len_END (8)
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_EN_dsp0_ddr_cache6_remap_en_START (9)
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_EN_dsp0_ddr_cache6_remap_en_END (9)
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_EN_ddr_cache6_remap_awcache_m2_START (10)
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_EN_ddr_cache6_remap_awcache_m2_END (13)
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_EN_ddr_cache6_remap_arcache_m2_START (14)
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_EN_ddr_cache6_remap_arcache_m2_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int dsp0_ddr_cache6_remap_src_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE6_REMAP_SRC_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_SRC_BASE_ADDR_dsp0_ddr_cache6_remap_src_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_SRC_BASE_ADDR_dsp0_ddr_cache6_remap_src_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int dsp0_ddr_cache6_remap_des_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE6_REMAP_DES_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_DES_BASE_ADDR_dsp0_ddr_cache6_remap_des_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE6_REMAP_DES_BASE_ADDR_dsp0_ddr_cache6_remap_des_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp0_ddr_cache7_remap_addr_len : 9;
        unsigned int dsp0_ddr_cache7_remap_en : 1;
        unsigned int ddr_cache7_remap_awcache_m2 : 4;
        unsigned int ddr_cache7_remap_arcache_m2 : 4;
        unsigned int reserved : 14;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE7_REMAP_EN_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_EN_dsp0_ddr_cache7_remap_addr_len_START (0)
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_EN_dsp0_ddr_cache7_remap_addr_len_END (8)
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_EN_dsp0_ddr_cache7_remap_en_START (9)
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_EN_dsp0_ddr_cache7_remap_en_END (9)
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_EN_ddr_cache7_remap_awcache_m2_START (10)
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_EN_ddr_cache7_remap_awcache_m2_END (13)
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_EN_ddr_cache7_remap_arcache_m2_START (14)
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_EN_ddr_cache7_remap_arcache_m2_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int dsp0_ddr_cache7_remap_src_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE7_REMAP_SRC_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_SRC_BASE_ADDR_dsp0_ddr_cache7_remap_src_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_SRC_BASE_ADDR_dsp0_ddr_cache7_remap_src_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int dsp0_ddr_cache7_remap_des_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE7_REMAP_DES_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_DES_BASE_ADDR_dsp0_ddr_cache7_remap_des_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE7_REMAP_DES_BASE_ADDR_dsp0_ddr_cache7_remap_des_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp0_ddr_cache8_remap_addr_len : 9;
        unsigned int dsp0_ddr_cache8_remap_en : 1;
        unsigned int ddr_cache8_remap_awcache_m2 : 4;
        unsigned int ddr_cache8_remap_arcache_m2 : 4;
        unsigned int reserved : 14;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE8_REMAP_EN_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_EN_dsp0_ddr_cache8_remap_addr_len_START (0)
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_EN_dsp0_ddr_cache8_remap_addr_len_END (8)
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_EN_dsp0_ddr_cache8_remap_en_START (9)
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_EN_dsp0_ddr_cache8_remap_en_END (9)
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_EN_ddr_cache8_remap_awcache_m2_START (10)
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_EN_ddr_cache8_remap_awcache_m2_END (13)
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_EN_ddr_cache8_remap_arcache_m2_START (14)
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_EN_ddr_cache8_remap_arcache_m2_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int dsp0_ddr_cache8_remap_src_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE8_REMAP_SRC_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_SRC_BASE_ADDR_dsp0_ddr_cache8_remap_src_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_SRC_BASE_ADDR_dsp0_ddr_cache8_remap_src_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int dsp0_ddr_cache8_remap_des_base_addr : 20;
    } reg;
} SOC_ASP_CFG_R_DDR_CACHE8_REMAP_DES_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_DES_BASE_ADDR_dsp0_ddr_cache8_remap_des_base_addr_START (12)
#define SOC_ASP_CFG_R_DDR_CACHE8_REMAP_DES_BASE_ADDR_dsp0_ddr_cache8_remap_des_base_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_asp_cfg_n : 1;
        unsigned int tz_secure_dmmu_n : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int tz_secure_codec_data_n : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int tz_secure_soundwire_data_n : 1;
        unsigned int audio_acc_data_secure_n : 1;
        unsigned int tz_secure_edmac1_n : 1;
        unsigned int tz_secure_axi2tdm_n : 1;
        unsigned int tz_secure_ipc1_n : 1;
        unsigned int dsp1_mst_secure_n : 1;
        unsigned int axi2tdm_data_secure_n : 1;
        unsigned int access_region_secure_n : 1;
        unsigned int write_en_h2ac : 16;
    } reg;
} SOC_ASP_CFG_R_TZ_SECURE_1_N_UNION;
#endif
#define SOC_ASP_CFG_R_TZ_SECURE_1_N_tz_secure_asp_cfg_n_START (0)
#define SOC_ASP_CFG_R_TZ_SECURE_1_N_tz_secure_asp_cfg_n_END (0)
#define SOC_ASP_CFG_R_TZ_SECURE_1_N_tz_secure_dmmu_n_START (1)
#define SOC_ASP_CFG_R_TZ_SECURE_1_N_tz_secure_dmmu_n_END (1)
#define SOC_ASP_CFG_R_TZ_SECURE_1_N_tz_secure_codec_data_n_START (5)
#define SOC_ASP_CFG_R_TZ_SECURE_1_N_tz_secure_codec_data_n_END (5)
#define SOC_ASP_CFG_R_TZ_SECURE_1_N_tz_secure_soundwire_data_n_START (8)
#define SOC_ASP_CFG_R_TZ_SECURE_1_N_tz_secure_soundwire_data_n_END (8)
#define SOC_ASP_CFG_R_TZ_SECURE_1_N_audio_acc_data_secure_n_START (9)
#define SOC_ASP_CFG_R_TZ_SECURE_1_N_audio_acc_data_secure_n_END (9)
#define SOC_ASP_CFG_R_TZ_SECURE_1_N_tz_secure_edmac1_n_START (10)
#define SOC_ASP_CFG_R_TZ_SECURE_1_N_tz_secure_edmac1_n_END (10)
#define SOC_ASP_CFG_R_TZ_SECURE_1_N_tz_secure_axi2tdm_n_START (11)
#define SOC_ASP_CFG_R_TZ_SECURE_1_N_tz_secure_axi2tdm_n_END (11)
#define SOC_ASP_CFG_R_TZ_SECURE_1_N_tz_secure_ipc1_n_START (12)
#define SOC_ASP_CFG_R_TZ_SECURE_1_N_tz_secure_ipc1_n_END (12)
#define SOC_ASP_CFG_R_TZ_SECURE_1_N_dsp1_mst_secure_n_START (13)
#define SOC_ASP_CFG_R_TZ_SECURE_1_N_dsp1_mst_secure_n_END (13)
#define SOC_ASP_CFG_R_TZ_SECURE_1_N_axi2tdm_data_secure_n_START (14)
#define SOC_ASP_CFG_R_TZ_SECURE_1_N_axi2tdm_data_secure_n_END (14)
#define SOC_ASP_CFG_R_TZ_SECURE_1_N_access_region_secure_n_START (15)
#define SOC_ASP_CFG_R_TZ_SECURE_1_N_access_region_secure_n_END (15)
#define SOC_ASP_CFG_R_TZ_SECURE_1_N_write_en_h2ac_START (16)
#define SOC_ASP_CFG_R_TZ_SECURE_1_N_write_en_h2ac_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dlock_bp_dmmu : 1;
        unsigned int reserved_0 : 1;
        unsigned int dlock_bp_axi2tdm : 1;
        unsigned int dlock_bp_edmac1 : 1;
        unsigned int dlock_bp_ipc1 : 1;
        unsigned int reserved_1 : 11;
        unsigned int write_en_2b0 : 16;
    } reg;
} SOC_ASP_CFG_R_DLOCK_BP_1_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_DLOCK_BP_1_ADDR_dlock_bp_dmmu_START (0)
#define SOC_ASP_CFG_R_DLOCK_BP_1_ADDR_dlock_bp_dmmu_END (0)
#define SOC_ASP_CFG_R_DLOCK_BP_1_ADDR_dlock_bp_axi2tdm_START (2)
#define SOC_ASP_CFG_R_DLOCK_BP_1_ADDR_dlock_bp_axi2tdm_END (2)
#define SOC_ASP_CFG_R_DLOCK_BP_1_ADDR_dlock_bp_edmac1_START (3)
#define SOC_ASP_CFG_R_DLOCK_BP_1_ADDR_dlock_bp_edmac1_END (3)
#define SOC_ASP_CFG_R_DLOCK_BP_1_ADDR_dlock_bp_ipc1_START (4)
#define SOC_ASP_CFG_R_DLOCK_BP_1_ADDR_dlock_bp_ipc1_END (4)
#define SOC_ASP_CFG_R_DLOCK_BP_1_ADDR_write_en_2b0_START (16)
#define SOC_ASP_CFG_R_DLOCK_BP_1_ADDR_write_en_2b0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_spc : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_ASP_CFG_R_MEMORY_CTRL1_UNION;
#endif
#define SOC_ASP_CFG_R_MEMORY_CTRL1_mem_ctrl_spc_START (0)
#define SOC_ASP_CFG_R_MEMORY_CTRL1_mem_ctrl_spc_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp_awuser_low : 32;
    } reg;
} SOC_ASP_CFG_DSP_AWUSER_CFG_LOW_UNION;
#endif
#define SOC_ASP_CFG_DSP_AWUSER_CFG_LOW_dsp_awuser_low_START (0)
#define SOC_ASP_CFG_DSP_AWUSER_CFG_LOW_dsp_awuser_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp_awuser_high : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ASP_CFG_DSP_AWUSER_CFG_HIGH_UNION;
#endif
#define SOC_ASP_CFG_DSP_AWUSER_CFG_HIGH_dsp_awuser_high_START (0)
#define SOC_ASP_CFG_DSP_AWUSER_CFG_HIGH_dsp_awuser_high_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp_aruser_low : 32;
    } reg;
} SOC_ASP_CFG_DSP_ARUSER_CFG_LOW_UNION;
#endif
#define SOC_ASP_CFG_DSP_ARUSER_CFG_LOW_dsp_aruser_low_START (0)
#define SOC_ASP_CFG_DSP_ARUSER_CFG_LOW_dsp_aruser_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp_aruser_high : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ASP_CFG_DSP_ARUSER_CFG_HIGH_UNION;
#endif
#define SOC_ASP_CFG_DSP_ARUSER_CFG_HIGH_dsp_aruser_high_START (0)
#define SOC_ASP_CFG_DSP_ARUSER_CFG_HIGH_dsp_aruser_high_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int edmac_awuser_low : 32;
    } reg;
} SOC_ASP_CFG_EDMAC_AWUSER_CFG_LOW_UNION;
#endif
#define SOC_ASP_CFG_EDMAC_AWUSER_CFG_LOW_edmac_awuser_low_START (0)
#define SOC_ASP_CFG_EDMAC_AWUSER_CFG_LOW_edmac_awuser_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int edmac_awuser_high : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ASP_CFG_EDMAC_AWUSER_CFG_HIGH_UNION;
#endif
#define SOC_ASP_CFG_EDMAC_AWUSER_CFG_HIGH_edmac_awuser_high_START (0)
#define SOC_ASP_CFG_EDMAC_AWUSER_CFG_HIGH_edmac_awuser_high_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int edmac_aruser_low : 32;
    } reg;
} SOC_ASP_CFG_EDMAC_ARUSER_CFG_LOW_UNION;
#endif
#define SOC_ASP_CFG_EDMAC_ARUSER_CFG_LOW_edmac_aruser_low_START (0)
#define SOC_ASP_CFG_EDMAC_ARUSER_CFG_LOW_edmac_aruser_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int edmac_aruser_high : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ASP_CFG_EDMAC_ARUSER_CFG_HIGH_UNION;
#endif
#define SOC_ASP_CFG_EDMAC_ARUSER_CFG_HIGH_edmac_aruser_high_START (0)
#define SOC_ASP_CFG_EDMAC_ARUSER_CFG_HIGH_edmac_aruser_high_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hdmi_awuser_low : 32;
    } reg;
} SOC_ASP_CFG_HDMI_AWUSER_CFG_LOW_UNION;
#endif
#define SOC_ASP_CFG_HDMI_AWUSER_CFG_LOW_hdmi_awuser_low_START (0)
#define SOC_ASP_CFG_HDMI_AWUSER_CFG_LOW_hdmi_awuser_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hdmi_awuser_high : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ASP_CFG_HDMI_AWUSER_CFG_HIGH_UNION;
#endif
#define SOC_ASP_CFG_HDMI_AWUSER_CFG_HIGH_hdmi_awuser_high_START (0)
#define SOC_ASP_CFG_HDMI_AWUSER_CFG_HIGH_hdmi_awuser_high_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hdmi_aruser_low : 32;
    } reg;
} SOC_ASP_CFG_HDMI_ARUSER_CFG_LOW_UNION;
#endif
#define SOC_ASP_CFG_HDMI_ARUSER_CFG_LOW_hdmi_aruser_low_START (0)
#define SOC_ASP_CFG_HDMI_ARUSER_CFG_LOW_hdmi_aruser_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int hdmi_aruser_high : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ASP_CFG_HDMI_ARUSER_CFG_HIGH_UNION;
#endif
#define SOC_ASP_CFG_HDMI_ARUSER_CFG_HIGH_hdmi_aruser_high_START (0)
#define SOC_ASP_CFG_HDMI_ARUSER_CFG_HIGH_hdmi_aruser_high_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int cpu_audio_bak_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ASP_CFG_CPU_AUDIO_BAK_UNION;
#endif
#define SOC_ASP_CFG_CPU_AUDIO_BAK_cpu_audio_bak_en_START (0)
#define SOC_ASP_CFG_CPU_AUDIO_BAK_cpu_audio_bak_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int display_sh_vsync_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ASP_CFG_DISPLAY_VSYNC_IRQ_CLR_UNION;
#endif
#define SOC_ASP_CFG_DISPLAY_VSYNC_IRQ_CLR_display_sh_vsync_clr_START (0)
#define SOC_ASP_CFG_DISPLAY_VSYNC_IRQ_CLR_display_sh_vsync_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int dsp0_addr_mon4_addr_base : 20;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR4_BASE_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR4_BASE_ADDR_dsp0_addr_mon4_addr_base_START (12)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR4_BASE_ADDR_dsp0_addr_mon4_addr_base_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 12;
        unsigned int dsp0_addr_mon4_addr_len : 20;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR4_LEN_ADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR4_LEN_ADDR_dsp0_addr_mon4_addr_len_START (12)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR4_LEN_ADDR_dsp0_addr_mon4_addr_len_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp0_addr_mon4_hit_awaddr : 32;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR4_HIT_AWADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR4_HIT_AWADDR_dsp0_addr_mon4_hit_awaddr_START (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR4_HIT_AWADDR_dsp0_addr_mon4_hit_awaddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dsp0_addr_mon4_hit_araddr : 32;
    } reg;
} SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR4_HIT_ARADDR_UNION;
#endif
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR4_HIT_ARADDR_dsp0_addr_mon4_hit_araddr_START (0)
#define SOC_ASP_CFG_R_ACCESS_ADDR_MONITOR4_HIT_ARADDR_dsp0_addr_mon4_hit_araddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gg_clk_en : 1;
        unsigned int lpc_mp_cg_dis : 1;
        unsigned int mp_ocd_dbg_ni_ena : 1;
        unsigned int mp_ocd_dbg_ena : 1;
        unsigned int mp_notocd_dbg_rd_ena : 1;
        unsigned int dss0_sleep_csysreq : 1;
        unsigned int mp_sleep_csysreq : 1;
        unsigned int gg_timer_clk_en_ctrl : 2;
        unsigned int gg_icu_clk_en_ctrl : 1;
        unsigned int reserved : 22;
    } reg;
} SOC_ASP_CFG_LL_CLK_CTRL_UNION;
#endif
#define SOC_ASP_CFG_LL_CLK_CTRL_gg_clk_en_START (0)
#define SOC_ASP_CFG_LL_CLK_CTRL_gg_clk_en_END (0)
#define SOC_ASP_CFG_LL_CLK_CTRL_lpc_mp_cg_dis_START (1)
#define SOC_ASP_CFG_LL_CLK_CTRL_lpc_mp_cg_dis_END (1)
#define SOC_ASP_CFG_LL_CLK_CTRL_mp_ocd_dbg_ni_ena_START (2)
#define SOC_ASP_CFG_LL_CLK_CTRL_mp_ocd_dbg_ni_ena_END (2)
#define SOC_ASP_CFG_LL_CLK_CTRL_mp_ocd_dbg_ena_START (3)
#define SOC_ASP_CFG_LL_CLK_CTRL_mp_ocd_dbg_ena_END (3)
#define SOC_ASP_CFG_LL_CLK_CTRL_mp_notocd_dbg_rd_ena_START (4)
#define SOC_ASP_CFG_LL_CLK_CTRL_mp_notocd_dbg_rd_ena_END (4)
#define SOC_ASP_CFG_LL_CLK_CTRL_dss0_sleep_csysreq_START (5)
#define SOC_ASP_CFG_LL_CLK_CTRL_dss0_sleep_csysreq_END (5)
#define SOC_ASP_CFG_LL_CLK_CTRL_mp_sleep_csysreq_START (6)
#define SOC_ASP_CFG_LL_CLK_CTRL_mp_sleep_csysreq_END (6)
#define SOC_ASP_CFG_LL_CLK_CTRL_gg_timer_clk_en_ctrl_START (7)
#define SOC_ASP_CFG_LL_CLK_CTRL_gg_timer_clk_en_ctrl_END (8)
#define SOC_ASP_CFG_LL_CLK_CTRL_gg_icu_clk_en_ctrl_START (9)
#define SOC_ASP_CFG_LL_CLK_CTRL_gg_icu_clk_en_ctrl_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mp_l1m_lbase : 12;
        unsigned int reserved_0 : 4;
        unsigned int mp_l1m_gbase : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ASP_CFG_LL_ACCESS_ADDR_BASE0_UNION;
#endif
#define SOC_ASP_CFG_LL_ACCESS_ADDR_BASE0_mp_l1m_lbase_START (0)
#define SOC_ASP_CFG_LL_ACCESS_ADDR_BASE0_mp_l1m_lbase_END (11)
#define SOC_ASP_CFG_LL_ACCESS_ADDR_BASE0_mp_l1m_gbase_START (16)
#define SOC_ASP_CFG_LL_ACCESS_ADDR_BASE0_mp_l1m_gbase_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mp_apb_lbase : 12;
        unsigned int reserved_0 : 4;
        unsigned int mp_apb_gbase : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ASP_CFG_LL_ACCESS_ADDR_BASE1_UNION;
#endif
#define SOC_ASP_CFG_LL_ACCESS_ADDR_BASE1_mp_apb_lbase_START (0)
#define SOC_ASP_CFG_LL_ACCESS_ADDR_BASE1_mp_apb_lbase_END (11)
#define SOC_ASP_CFG_LL_ACCESS_ADDR_BASE1_mp_apb_gbase_START (16)
#define SOC_ASP_CFG_LL_ACCESS_ADDR_BASE1_mp_apb_gbase_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int soc_apb_base : 12;
        unsigned int reserved_0 : 4;
        unsigned int soc_apb_end : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ASP_CFG_LL_ACCESS_ADDR_BASE2_UNION;
#endif
#define SOC_ASP_CFG_LL_ACCESS_ADDR_BASE2_soc_apb_base_START (0)
#define SOC_ASP_CFG_LL_ACCESS_ADDR_BASE2_soc_apb_base_END (11)
#define SOC_ASP_CFG_LL_ACCESS_ADDR_BASE2_soc_apb_end_START (16)
#define SOC_ASP_CFG_LL_ACCESS_ADDR_BASE2_soc_apb_end_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dss0_ext_dgb_req : 1;
        unsigned int dss0_init_mmu_mode : 3;
        unsigned int dss0_unit_selfboot : 1;
        unsigned int dss0_core_id : 7;
        unsigned int reserved : 20;
    } reg;
} SOC_ASP_CFG_LL_DSS0_CTRL0_UNION;
#endif
#define SOC_ASP_CFG_LL_DSS0_CTRL0_dss0_ext_dgb_req_START (0)
#define SOC_ASP_CFG_LL_DSS0_CTRL0_dss0_ext_dgb_req_END (0)
#define SOC_ASP_CFG_LL_DSS0_CTRL0_dss0_init_mmu_mode_START (1)
#define SOC_ASP_CFG_LL_DSS0_CTRL0_dss0_init_mmu_mode_END (3)
#define SOC_ASP_CFG_LL_DSS0_CTRL0_dss0_unit_selfboot_START (4)
#define SOC_ASP_CFG_LL_DSS0_CTRL0_dss0_unit_selfboot_END (4)
#define SOC_ASP_CFG_LL_DSS0_CTRL0_dss0_core_id_START (5)
#define SOC_ASP_CFG_LL_DSS0_CTRL0_dss0_core_id_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dss0_init_addr : 32;
    } reg;
} SOC_ASP_CFG_LL_DSS0_CTRL1_UNION;
#endif
#define SOC_ASP_CFG_LL_DSS0_CTRL1_dss0_init_addr_START (0)
#define SOC_ASP_CFG_LL_DSS0_CTRL1_dss0_init_addr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 10;
        unsigned int dss0_init_icu_base : 22;
    } reg;
} SOC_ASP_CFG_LL_DSS0_CTRL2_UNION;
#endif
#define SOC_ASP_CFG_LL_DSS0_CTRL2_dss0_init_icu_base_START (10)
#define SOC_ASP_CFG_LL_DSS0_CTRL2_dss0_init_icu_base_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int reserved : 4;
        unsigned int dss0_init_ssp : 28;
    } reg;
} SOC_ASP_CFG_LL_DSS0_CTRL3_UNION;
#endif
#define SOC_ASP_CFG_LL_DSS0_CTRL3_dss0_init_ssp_START (4)
#define SOC_ASP_CFG_LL_DSS0_CTRL3_dss0_init_ssp_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dss0_pl1_poff_out : 2;
        unsigned int dss0_other_poff_out : 2;
        unsigned int reserved : 28;
    } reg;
} SOC_ASP_CFG_LL_MEM_POWER_STATUS_UNION;
#endif
#define SOC_ASP_CFG_LL_MEM_POWER_STATUS_dss0_pl1_poff_out_START (0)
#define SOC_ASP_CFG_LL_MEM_POWER_STATUS_dss0_pl1_poff_out_END (1)
#define SOC_ASP_CFG_LL_MEM_POWER_STATUS_dss0_other_poff_out_START (2)
#define SOC_ASP_CFG_LL_MEM_POWER_STATUS_dss0_other_poff_out_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mp_clock_off_status : 1;
        unsigned int dss0_sleep_cactive : 1;
        unsigned int dss0_sleep_csysack : 1;
        unsigned int mp_sleep_cactive : 1;
        unsigned int mp_sleep_csysack : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_ASP_CFG_LL_CLK_POWER_STATUS_UNION;
#endif
#define SOC_ASP_CFG_LL_CLK_POWER_STATUS_mp_clock_off_status_START (0)
#define SOC_ASP_CFG_LL_CLK_POWER_STATUS_mp_clock_off_status_END (0)
#define SOC_ASP_CFG_LL_CLK_POWER_STATUS_dss0_sleep_cactive_START (1)
#define SOC_ASP_CFG_LL_CLK_POWER_STATUS_dss0_sleep_cactive_END (1)
#define SOC_ASP_CFG_LL_CLK_POWER_STATUS_dss0_sleep_csysack_START (2)
#define SOC_ASP_CFG_LL_CLK_POWER_STATUS_dss0_sleep_csysack_END (2)
#define SOC_ASP_CFG_LL_CLK_POWER_STATUS_mp_sleep_cactive_START (3)
#define SOC_ASP_CFG_LL_CLK_POWER_STATUS_mp_sleep_cactive_END (3)
#define SOC_ASP_CFG_LL_CLK_POWER_STATUS_mp_sleep_csysack_START (4)
#define SOC_ASP_CFG_LL_CLK_POWER_STATUS_mp_sleep_csysack_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mpmss_debug_bus : 32;
    } reg;
} SOC_ASP_CFG_LL_MP_DFX_UNION;
#endif
#define SOC_ASP_CFG_LL_MP_DFX_mpmss_debug_bus_START (0)
#define SOC_ASP_CFG_LL_MP_DFX_mpmss_debug_bus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dss0_flush_done_int : 1;
        unsigned int dss0_busy : 1;
        unsigned int dss0_wait_mode : 1;
        unsigned int dss0_fatal_err : 2;
        unsigned int dss_thrd_debug_mode : 4;
        unsigned int reserved : 23;
    } reg;
} SOC_ASP_CFG_LL_DSS_STATUS0_UNION;
#endif
#define SOC_ASP_CFG_LL_DSS_STATUS0_dss0_flush_done_int_START (0)
#define SOC_ASP_CFG_LL_DSS_STATUS0_dss0_flush_done_int_END (0)
#define SOC_ASP_CFG_LL_DSS_STATUS0_dss0_busy_START (1)
#define SOC_ASP_CFG_LL_DSS_STATUS0_dss0_busy_END (1)
#define SOC_ASP_CFG_LL_DSS_STATUS0_dss0_wait_mode_START (2)
#define SOC_ASP_CFG_LL_DSS_STATUS0_dss0_wait_mode_END (2)
#define SOC_ASP_CFG_LL_DSS_STATUS0_dss0_fatal_err_START (3)
#define SOC_ASP_CFG_LL_DSS_STATUS0_dss0_fatal_err_END (4)
#define SOC_ASP_CFG_LL_DSS_STATUS0_dss_thrd_debug_mode_START (5)
#define SOC_ASP_CFG_LL_DSS_STATUS0_dss_thrd_debug_mode_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dss0_debug_bus : 32;
    } reg;
} SOC_ASP_CFG_LL_DSS_STATUS1_UNION;
#endif
#define SOC_ASP_CFG_LL_DSS_STATUS1_dss0_debug_bus_START (0)
#define SOC_ASP_CFG_LL_DSS_STATUS1_dss0_debug_bus_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dspjtag_se : 1;
        unsigned int dspjtag_spiden : 1;
        unsigned int dspjtag_dbgen : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_ASP_CFG_LL_JTAG_EN_UNION;
#endif
#define SOC_ASP_CFG_LL_JTAG_EN_dspjtag_se_START (0)
#define SOC_ASP_CFG_LL_JTAG_EN_dspjtag_se_END (0)
#define SOC_ASP_CFG_LL_JTAG_EN_dspjtag_spiden_START (1)
#define SOC_ASP_CFG_LL_JTAG_EN_dspjtag_spiden_END (1)
#define SOC_ASP_CFG_LL_JTAG_EN_dspjtag_dbgen_START (2)
#define SOC_ASP_CFG_LL_JTAG_EN_dspjtag_dbgen_END (2)
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
#endif
